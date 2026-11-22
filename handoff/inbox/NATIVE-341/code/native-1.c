/* NATIVE-341 reconstructed pseudo-C (editable) */

/* ---- FUNC 00001000 FUN_180001000 (36 bytes) ---- */

void FUN_180001000(void)

{
  DAT_180079fa0 = GetProcAddress(DAT_180079f98,"GetSorResStringEx");
  return;
}

/* ---- FUNC 00001030 FUN_180001030 (29 bytes) ---- */

void FUN_180001030(void)

{
  DAT_180079f98 = LoadLibraryA("sorresdll.dll");
  return;
}

/* ---- FUNC 00001050 FUN_180001050 (32 bytes) ---- */

void FUN_180001050(void)

{
  CApwnEOStatus::CApwnEOStatus(&g_ApwnEOStatusMap);
  atexit((_func_5014 *)&LAB_1800513f0);
  return;
}

/* ---- FUNC 00001070 FUN_180001070 (40 bytes) ---- */

void FUN_180001070(void)

{
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            (&CApwnLibraries::m_ConceptualDesign,"Conceptual Design");
  atexit((_func_5014 *)&LAB_180051400);
  return;
}

/* ---- FUNC 000010A0 FUN_1800010a0 (40 bytes) ---- */

void FUN_1800010a0(void)

{
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            (&CApwnLibraries::m_HybridModelLib,"Hybrid Models");
  atexit((_func_5014 *)&LAB_180051410);
  return;
}

/* ---- FUNC 000010D0 FUN_1800010d0 (32 bytes) ---- */

void FUN_1800010d0(void)

{
  CStringArray::CStringArray(&CApwnLibraries::m_InitializedLibraries);
  atexit((_func_5014 *)&LAB_180051420);
  return;
}

/* ---- FUNC 000010F0 FUN_1800010f0 (40 bytes) ---- */

void FUN_1800010f0(void)

{
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            (&CApwnLibraries::m_acmbuiltin,"ACM Built-In");
  atexit((_func_5014 *)&LAB_180051430);
  return;
}

/* ---- FUNC 00001120 FUN_180001120 (40 bytes) ---- */

void FUN_180001120(void)

{
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            (&CApwnLibraries::m_acmcatalog,"ACM Models");
  atexit((_func_5014 *)&LAB_180051440);
  return;
}

/* ---- FUNC 00001150 FUN_180001150 (40 bytes) ---- */

void FUN_180001150(void)

{
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            (&CApwnLibraries::m_acmcatalogold,"ACM-Catalog");
  atexit((_func_5014 *)&LAB_180051450);
  return;
}

/* ---- FUNC 00001180 FUN_180001180 (40 bytes) ---- */

void FUN_180001180(void)

{
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            (&CApwnLibraries::m_builtin,"Built-In");
  atexit((_func_5014 *)&LAB_180051460);
  return;
}

/* ---- FUNC 000011B0 FUN_1800011b0 (40 bytes) ---- */

void FUN_1800011b0(void)

{
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            (&CApwnLibraries::m_capeopen,"CAPE-OPEN");
  atexit((_func_5014 *)&LAB_180051470);
  return;
}

/* ---- FUNC 000011E0 FUN_1800011e0 (40 bytes) ---- */

void FUN_1800011e0(void)

{
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            (&CApwnLibraries::m_streams,"Streams");
  atexit((_func_5014 *)&LAB_180051480);
  return;
}

/* ---- FUNC 00001210 FUN_180001210 (92 bytes) ---- */

void FUN_180001210(void)

{
  undefined4 local_28;
  undefined2 local_24;
  undefined1 local_22;
  undefined1 local_21;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  local_28 = (undefined4)DAT_180053860;
  local_24 = DAT_180053860._4_2_;
  local_22 = DAT_180053860._6_1_;
  local_20 = 0;
  local_18 = 7;
  local_10 = 0xf;
  local_21 = 0;
  DAT_18007a040 = FUN_18000da20((longlong *)&local_28);
  return;
}

/* ---- FUNC 00001270 FUN_180001270 (54 bytes) ---- */

void FUN_180001270(void)

{
  DAT_18007a288 = operator_new(0x50);
  *(void **)DAT_18007a288 = DAT_18007a288;
  *(void **)((longlong)DAT_18007a288 + 8) = DAT_18007a288;
  *(void **)((longlong)DAT_18007a288 + 0x10) = DAT_18007a288;
  *(undefined2 *)((longlong)DAT_18007a288 + 0x18) = 0x101;
  atexit(FUN_180051490);
  return;
}

/* ---- FUNC 000012B0 FUN_1800012b0 (54 bytes) ---- */

void FUN_1800012b0(void)

{
  DAT_18007a278 = operator_new(0x50);
  *(void **)DAT_18007a278 = DAT_18007a278;
  *(void **)((longlong)DAT_18007a278 + 8) = DAT_18007a278;
  *(void **)((longlong)DAT_18007a278 + 0x10) = DAT_18007a278;
  *(undefined2 *)((longlong)DAT_18007a278 + 0x18) = 0x101;
  atexit(FUN_180051590);
  return;
}

/* ---- FUNC 000012F0 FUN_1800012f0 (92 bytes) ---- */

void FUN_1800012f0(void)

{
  undefined4 local_28;
  undefined2 local_24;
  undefined1 local_22;
  undefined1 local_21;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  local_28 = (undefined4)DAT_180053860;
  local_24 = DAT_180053860._4_2_;
  local_22 = DAT_180053860._6_1_;
  local_20 = 0;
  local_18 = 7;
  local_10 = 0xf;
  local_21 = 0;
  DAT_18007a270 = FUN_18000da20((longlong *)&local_28);
  return;
}

/* ---- FUNC 00001350 FUN_180001350 (40 bytes) ---- */

void FUN_180001350(void)

{
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&DAT_18007b6a8,
             "ACM Built-In");
  atexit((_func_5014 *)&LAB_180051690);
  return;
}

/* ---- FUNC 00001380 FUN_180001380 (40 bytes) ---- */

void FUN_180001380(void)

{
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&DAT_18007b6a0,
             "ACM Models");
  atexit((_func_5014 *)&LAB_1800516a0);
  return;
}

/* ---- FUNC 000013B0 FUN_1800013b0 (40 bytes) ---- */

void FUN_1800013b0(void)

{
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&DAT_18007b690,
             "Built-In");
  atexit((_func_5014 *)&LAB_1800516b0);
  return;
}

/* ---- FUNC 000013E0 FUN_1800013e0 (40 bytes) ---- */

void FUN_1800013e0(void)

{
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&DAT_18007b698,
             "CAPE-OPEN");
  atexit((_func_5014 *)&LAB_1800516c0);
  return;
}

/* ---- FUNC 00001410 FUN_180001410 (32 bytes) ---- */

void FUN_180001410(void)

{
  CConvertMgr::CConvertMgr(&g_Converter);
  atexit((_func_5014 *)&LAB_1800516d0);
  return;
}

/* ---- FUNC 00001430 FUN_180001430 (55 bytes) ---- */

void FUN_180001430(void)

{
  DAT_18007b6d8 = operator_new(0x10);
  DAT_18007b6d8[1] = 0;
  *DAT_18007b6d8 = &DAT_18007b6d8;
  atexit(FUN_1800516e0);
  return;
}

/* ---- FUNC 00001470 FUN_180001470 (32 bytes) ---- */

void FUN_180001470(void)

{
  FUN_18002fce0((CMapStringToPtr *)&DAT_18007b760);
  atexit((_func_5014 *)&LAB_180051710);
  return;
}

/* ---- FUNC 00001490 FUN_180001490 (32 bytes) ---- */

void FUN_180001490(void)

{
  FUN_180040820((CPtrArray *)&DAT_18007b738);
  atexit((_func_5014 *)&LAB_180051720);
  return;
}

/* ---- FUNC 000014FC FUN_1800014fc (32 bytes) ---- */

void FUN_1800014fc(void)

{
  ATL::CAtlBaseModule::CAtlBaseModule((CAtlBaseModule *)&DAT_18009c1c0);
  atexit((_func_5014 *)&LAB_180051874);
  return;
}

/* ---- FUNC 00001540 FUN_180001540 (42 bytes) ---- */

bool FUN_180001540(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_1,
                  undefined8 *param_2)

{
  int iVar1;
  
  if ((param_1 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) &&
     (param_2 != (undefined8 *)0x0)) {
    iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                      (param_1,(char *)*param_2);
    return iVar1 == 0;
  }
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 00001570 FUN_180001570 (44 bytes) ---- */

void FUN_180001570(CArchive *param_1,void *param_2,ulonglong param_3)

{
  code *pcVar1;
  uint uVar2;
  uint uVar3;
  ulonglong uVar4;
  
  if ((param_3 != 0) && (param_2 == (void *)0x0)) {
                    /* WARNING: Subroutine does not return */
    AfxThrowInvalidArgException();
  }
  if ((~*(uint *)(param_1 + 0x20) & 1) == 0) {
    for (; param_3 != 0; param_3 = param_3 - uVar4) {
      uVar4 = 0xfffffff;
      if (param_3 < 0xfffffff) {
        uVar4 = param_3 & 0xffffffff;
      }
      uVar3 = (int)uVar4 * 8;
      uVar2 = CArchive::Read(param_1,param_2,uVar3);
      if (uVar2 != uVar3) {
        AfxThrowArchiveException(3,(char *)0x0);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      param_2 = (void *)((longlong)param_2 + uVar4 * 8);
    }
  }
  else {
    for (; param_3 != 0; param_3 = param_3 - uVar4) {
      uVar4 = 0xfffffff;
      if (param_3 < 0xfffffff) {
        uVar4 = param_3 & 0xffffffff;
      }
      CArchive::Write(param_1,param_2,(int)uVar4 * 8);
      param_2 = (void *)((longlong)param_2 + uVar4 * 8);
    }
  }
  return;
}

/* ---- FUNC 0000159C FUN_18000159c (68 bytes) ---- */

void FUN_18000159c(void)

{
  code *pcVar1;
  uint uVar2;
  ulonglong in_RAX;
  ulonglong unaff_RBX;
  void *unaff_RSI;
  uint uVar3;
  ulonglong uVar4;
  CArchive *unaff_R14;
  
  if ((in_RAX & 1) == 0) {
    for (; unaff_RBX != 0; unaff_RBX = unaff_RBX - uVar4) {
      uVar4 = 0xfffffff;
      if (unaff_RBX < 0xfffffff) {
        uVar4 = unaff_RBX & 0xffffffff;
      }
      uVar3 = (int)uVar4 * 8;
      uVar2 = CArchive::Read(unaff_R14,unaff_RSI,uVar3);
      if (uVar2 != uVar3) {
        AfxThrowArchiveException(3,(char *)0x0);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      unaff_RSI = (void *)((longlong)unaff_RSI + uVar4 * 8);
    }
  }
  else {
    for (; unaff_RBX != 0; unaff_RBX = unaff_RBX - uVar4) {
      uVar4 = 0xfffffff;
      if (unaff_RBX < 0xfffffff) {
        uVar4 = unaff_RBX & 0xffffffff;
      }
      CArchive::Write(unaff_R14,unaff_RSI,(int)uVar4 * 8);
      unaff_RSI = (void *)((longlong)unaff_RSI + uVar4 * 8);
    }
  }
  return;
}

/* ---- FUNC 000015E0 FUN_1800015e0 (68 bytes) ---- */

void FUN_1800015e0(void)

{
  code *pcVar1;
  uint uVar2;
  ulonglong unaff_RBX;
  ulonglong uVar3;
  void *unaff_RSI;
  uint uVar4;
  CArchive *unaff_R14;
  
  while( true ) {
    uVar3 = 0xfffffff;
    if (unaff_RBX < 0xfffffff) {
      uVar3 = unaff_RBX & 0xffffffff;
    }
    uVar4 = (int)uVar3 * 8;
    uVar2 = CArchive::Read(unaff_R14,unaff_RSI,uVar4);
    if (uVar2 != uVar4) break;
    unaff_RSI = (void *)((longlong)unaff_RSI + uVar3 * 8);
    unaff_RBX = unaff_RBX - uVar3;
    if (unaff_RBX == 0) {
      return;
    }
  }
  AfxThrowArchiveException(3,(char *)0x0);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

/* ---- FUNC 00001624 FUN_180001624 (22 bytes) ---- */

void FUN_180001624(void)

{
  return;
}

/* ---- FUNC 0000163A FUN_18000163a (11 bytes) ---- */

void FUN_18000163a(void)

{
  code *pcVar1;
  
  AfxThrowArchiveException(3,(char *)0x0);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

/* ---- FUNC 00001645 AfxThrowInvalidArgException (5 bytes) ---- */

void __cdecl AfxThrowInvalidArgException(void)

{
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 00001650 FUN_180001650 (44 bytes) ---- */

void FUN_180001650(CArchive *param_1,void *param_2,ulonglong param_3)

{
  code *pcVar1;
  uint uVar2;
  uint uVar3;
  
  if ((param_3 != 0) && (param_2 == (void *)0x0)) {
                    /* WARNING: Subroutine does not return */
    AfxThrowInvalidArgException();
  }
  if ((~*(uint *)(param_1 + 0x20) & 1) == 0) {
    for (; param_3 != 0; param_3 = param_3 - uVar3) {
      uVar3 = 0x7ffffff;
      if (param_3 < 0x7ffffff) {
        uVar3 = (uint)param_3;
      }
      uVar2 = CArchive::Read(param_1,param_2,uVar3 << 4);
      if (uVar2 != uVar3 << 4) {
        AfxThrowArchiveException(3,(char *)0x0);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      param_2 = (void *)((longlong)param_2 + (ulonglong)uVar3 * 0x10);
    }
  }
  else {
    for (; param_3 != 0; param_3 = param_3 - uVar3) {
      uVar3 = 0x7ffffff;
      if (param_3 < 0x7ffffff) {
        uVar3 = (uint)param_3;
      }
      CArchive::Write(param_1,param_2,uVar3 << 4);
      param_2 = (void *)((longlong)param_2 + (ulonglong)uVar3 * 0x10);
    }
  }
  return;
}

/* ---- FUNC 0000167C FUN_18000167c (73 bytes) ---- */

void FUN_18000167c(void)

{
  code *pcVar1;
  uint uVar2;
  ulonglong in_RAX;
  ulonglong unaff_RBX;
  void *unaff_RSI;
  uint uVar3;
  CArchive *unaff_R14;
  
  if ((in_RAX & 1) == 0) {
    for (; unaff_RBX != 0; unaff_RBX = unaff_RBX - uVar3) {
      uVar3 = 0x7ffffff;
      if (unaff_RBX < 0x7ffffff) {
        uVar3 = (uint)unaff_RBX;
      }
      uVar2 = CArchive::Read(unaff_R14,unaff_RSI,uVar3 << 4);
      if (uVar2 != uVar3 << 4) {
        AfxThrowArchiveException(3,(char *)0x0);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      unaff_RSI = (void *)((longlong)unaff_RSI + (ulonglong)uVar3 * 0x10);
    }
  }
  else {
    for (; unaff_RBX != 0; unaff_RBX = unaff_RBX - uVar3) {
      uVar3 = 0x7ffffff;
      if (unaff_RBX < 0x7ffffff) {
        uVar3 = (uint)unaff_RBX;
      }
      CArchive::Write(unaff_R14,unaff_RSI,uVar3 << 4);
      unaff_RSI = (void *)((longlong)unaff_RSI + (ulonglong)uVar3 * 0x10);
    }
  }
  return;
}

/* ---- FUNC 000016C5 FUN_1800016c5 (67 bytes) ---- */

void FUN_1800016c5(void)

{
  code *pcVar1;
  uint uVar2;
  ulonglong unaff_RBX;
  uint uVar3;
  void *unaff_RSI;
  CArchive *unaff_R14;
  
  while( true ) {
    uVar3 = 0x7ffffff;
    if (unaff_RBX < 0x7ffffff) {
      uVar3 = (uint)unaff_RBX;
    }
    uVar2 = CArchive::Read(unaff_R14,unaff_RSI,uVar3 << 4);
    if (uVar2 != uVar3 << 4) break;
    unaff_RBX = unaff_RBX - uVar3;
    unaff_RSI = (void *)((longlong)unaff_RSI + (ulonglong)uVar3 * 0x10);
    if (unaff_RBX == 0) {
      return;
    }
  }
  AfxThrowArchiveException(3,(char *)0x0);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

/* ---- FUNC 00001708 FUN_180001708 (22 bytes) ---- */

void FUN_180001708(void)

{
  return;
}

/* ---- FUNC 0000171E FUN_18000171e (11 bytes) ---- */

void FUN_18000171e(void)

{
  code *pcVar1;
  
  AfxThrowArchiveException(3,(char *)0x0);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

/* ---- FUNC 00001729 AfxThrowInvalidArgException (5 bytes) ---- */

void __cdecl AfxThrowInvalidArgException(void)

{
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 00001730 FUN_180001730 (40 bytes) ---- */

undefined8 * FUN_180001730(undefined8 *param_1,undefined8 param_2)

{
  param_1[6] = param_2;
  *param_1 = CList<ModelTypeRef,ModelTypeRef&___ptr64>::vftable;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[2] = 0;
  param_1[1] = 0;
  param_1[5] = 0;
  return param_1;
}

/* ---- FUNC 00001760 CMap<> (43 bytes) ---- */

/* Library Function - Multiple Matches With Same Base Name
    public: __cdecl CMap<int,int,int,int>::CMap<int,int,int,int>(__int64) __ptr64
    public: __cdecl CMap<int,int,unsigned int,unsigned int>::CMap<int,int,unsigned int,unsigned
   int>(__int64) __ptr64
    public: __cdecl CMap<unsigned int,unsigned int & __ptr64,class CMFCToolBarButton * __ptr64,class
   CMFCToolBarButton * __ptr64 & __ptr64>::CMap<unsigned int,unsigned int & __ptr64,class
   CMFCToolBarButton * __ptr64,class CMFCToolBarButton * __ptr64 & __ptr64>(__int64) __ptr64
    public: __cdecl CMap<unsigned int,unsigned int,int,int>::CMap<unsigned int,unsigned
   int,int,int>(__int64) __ptr64
     34 names - too many to list
   
   Library: Visual Studio 2015 Release */

undefined8 * CMap<>(undefined8 *param_1,undefined8 param_2)

{
  *(undefined4 *)(param_1 + 2) = 0x11;
  *param_1 = CMap<ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>,char_const*___ptr64,ModelTypeRefList*___ptr64,ModelTypeRefList*___ptr64>
             ::vftable;
  param_1[1] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = param_2;
  return param_1;
}

/* ---- FUNC 00001790 CTypedPtrArray<CPtrArray,CNameAndState*___ptr64> (33 bytes) ---- */

/* public: __cdecl CTypedPtrArray<class CPtrArray,class CNameAndState *
   __ptr64>::CTypedPtrArray<class CPtrArray,class CNameAndState * __ptr64>(void) __ptr64 */

CTypedPtrArray<CPtrArray,CNameAndState*___ptr64> * __thiscall
CTypedPtrArray<CPtrArray,CNameAndState*___ptr64>::CTypedPtrArray<CPtrArray,CNameAndState*___ptr64>
          (CTypedPtrArray<CPtrArray,CNameAndState*___ptr64> *this)

{
                    /* 0x1790  1  ??0?$CTypedPtrArray@VCPtrArray@@PEAVCNameAndState@@@@QEAA@XZ */
  CPtrArray::CPtrArray((CPtrArray *)this);
  *(undefined ***)this = vftable;
  return this;
}

/* ---- FUNC 000017C0 CApwnBlockUsage (80 bytes) ---- */

/* public: __cdecl CApwnBlockUsage::CApwnBlockUsage(class CApwnLibraries * __ptr64,struct IAModel *
   __ptr64) __ptr64 */

CApwnBlockUsage * __thiscall
CApwnBlockUsage::CApwnBlockUsage(CApwnBlockUsage *this,CApwnLibraries *param_1,IAModel *param_2)

{
                    /* 0x17c0  18  ??0CApwnBlockUsage@@QEAA@PEAVCApwnLibraries@@PEAUIAModel@@@Z */
  CPtrArray::CPtrArray((CPtrArray *)(this + 8));
  *(CApwnLibraries **)this = param_1;
  *(IAModel **)(this + 0x30) = param_2;
  if (param_2 != (IAModel *)0x0) {
    (**(code **)(*(longlong *)param_2 + 8))(param_2);
  }
  return this;
}

/* ---- FUNC 00001810 FUN_180001810 (557 bytes) ---- */

CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
FUN_180001810(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_1,
             longlong *param_2,longlong *param_3,longlong *param_4)

{
  longlong *plVar1;
  longlong lVar2;
  char *pcVar3;
  longlong *local_res10;
  
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1 + 8);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1 + 0x10);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1 + 0x18);
  *(undefined8 *)(param_1 + 0x20) = 0;
  *(undefined8 *)(param_1 + 0x28) = 0;
  *(undefined8 *)(param_1 + 0x30) = 0;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(param_1,"");
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(param_1 + 8,"");
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(param_1 + 0x10,"");
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(param_1 + 0x18,"");
  *(undefined4 *)(param_1 + 0x3c) = 0;
  if (*(longlong **)(param_1 + 0x20) != param_2) {
    if (param_2 != (longlong *)0x0) {
      (**(code **)(*param_2 + 8))(param_2);
    }
    plVar1 = *(longlong **)(param_1 + 0x20);
    *(longlong **)(param_1 + 0x20) = param_2;
    if (plVar1 != (longlong *)0x0) {
      (**(code **)(*plVar1 + 0x10))();
    }
  }
  plVar1 = *(longlong **)(param_1 + 0x20);
  lVar2 = *plVar1;
  pcVar3 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)param_1,0x40);
  (**(code **)(lVar2 + 0x38))(plVar1,pcVar3,0x3f);
  ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)param_1,-1);
  if (*(longlong **)(param_1 + 0x28) != param_3) {
    if (param_3 != (longlong *)0x0) {
      (**(code **)(*param_3 + 8))(param_3);
    }
    plVar1 = *(longlong **)(param_1 + 0x28);
    *(longlong **)(param_1 + 0x28) = param_3;
    if (plVar1 != (longlong *)0x0) {
      (**(code **)(*plVar1 + 0x10))();
    }
  }
  (**(code **)(**(longlong **)(param_1 + 0x28) + 0x30))
            (*(longlong **)(param_1 + 0x28),param_1 + 0x38);
  (**(code **)**(undefined8 **)(param_1 + 0x28))
            (*(undefined8 **)(param_1 + 0x28),&DAT_1800561e0,&local_res10);
  lVar2 = *local_res10;
  pcVar3 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)(param_1 + 8),0x40);
  (**(code **)(lVar2 + 0x18))(local_res10,pcVar3,0x3f);
  (**(code **)(*local_res10 + 0x10))();
  ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)(param_1 + 8),-1);
  plVar1 = *(longlong **)(param_1 + 0x28);
  lVar2 = *plVar1;
  pcVar3 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)(param_1 + 0x18),0x40);
  (**(code **)(lVar2 + 0x18))(plVar1,pcVar3,0x3f);
  ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)(param_1 + 0x18),-1);
  if (*(longlong **)(param_1 + 0x30) != param_4) {
    if (param_4 != (longlong *)0x0) {
      (**(code **)(*param_4 + 8))(param_4);
    }
    plVar1 = *(longlong **)(param_1 + 0x30);
    *(longlong **)(param_1 + 0x30) = param_4;
    if (plVar1 != (longlong *)0x0) {
      (**(code **)(*plVar1 + 0x10))();
    }
  }
  plVar1 = *(longlong **)(param_1 + 0x30);
  pcVar3 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)(param_1 + 0x10),0x40);
  FUN_180003e00(plVar1,pcVar3,0x3f);
  ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)(param_1 + 0x10),-1);
  return param_1;
}

/* ---- FUNC 00001A40 FUN_180001a40 (246 bytes) ---- */

CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
FUN_180001a40(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_1,char *param_2,
             char *param_3,char *param_4,char *param_5)

{
  longlong *plVar1;
  
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1 + 8);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1 + 0x10);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1 + 0x18);
  *(undefined8 *)(param_1 + 0x20) = 0;
  *(undefined8 *)(param_1 + 0x28) = 0;
  *(undefined8 *)(param_1 + 0x30) = 0;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(param_1,param_3);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(param_1 + 8,param_4)
  ;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            (param_1 + 0x10,param_2);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            (param_1 + 0x18,param_5);
  plVar1 = *(longlong **)(param_1 + 0x20);
  if (plVar1 != (longlong *)0x0) {
    *(undefined8 *)(param_1 + 0x20) = 0;
    (**(code **)(*plVar1 + 0x10))();
  }
  plVar1 = *(longlong **)(param_1 + 0x28);
  if (plVar1 != (longlong *)0x0) {
    *(undefined8 *)(param_1 + 0x28) = 0;
    (**(code **)(*plVar1 + 0x10))();
  }
  plVar1 = *(longlong **)(param_1 + 0x30);
  if (plVar1 != (longlong *)0x0) {
    *(undefined8 *)(param_1 + 0x30) = 0;
    (**(code **)(*plVar1 + 0x10))();
  }
  *(undefined8 *)(param_1 + 0x38) = 0;
  return param_1;
}

/* ---- FUNC 00001B40 FUN_180001b40 (174 bytes) ---- */

CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
FUN_180001b40(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_1)

{
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1 + 8);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1 + 0x10);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1 + 0x18);
  *(undefined8 *)(param_1 + 0x20) = 0;
  *(undefined8 *)(param_1 + 0x28) = 0;
  *(undefined8 *)(param_1 + 0x30) = 0;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(param_1,"");
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(param_1 + 8,"");
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(param_1 + 0x10,"");
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(param_1 + 0x18,"");
  *(undefined8 *)(param_1 + 0x38) = 0;
  return param_1;
}

/* ---- FUNC 00001BF0 CNameAndStateArray (33 bytes) ---- */

/* public: __cdecl CNameAndStateArray::CNameAndStateArray(void) __ptr64 */

CNameAndStateArray * __thiscall CNameAndStateArray::CNameAndStateArray(CNameAndStateArray *this)

{
                    /* 0x1bf0  27  ??0CNameAndStateArray@@QEAA@XZ */
  CPtrArray::CPtrArray((CPtrArray *)this);
  *(undefined ***)this = vftable;
  return this;
}

/* ---- FUNC 00001C20 FUN_180001c20 (34 bytes) ---- */

CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
FUN_180001c20(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_1)

{
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1 + 8);
  return param_1;
}

/* ---- FUNC 00001C50 FUN_180001c50 (24 bytes) ---- */

void FUN_180001c50(longlong *param_1)

{
  if ((longlong *)*param_1 != (longlong *)0x0) {
    (**(code **)(*(longlong *)*param_1 + 0x10))();
  }
  return;
}

/* ---- FUNC 00001C70 FUN_180001c70 (25 bytes) ---- */

void FUN_180001c70(undefined8 *param_1)

{
  *param_1 = CList<ModelTypeRef,ModelTypeRef&___ptr64>::vftable;
  FUN_180004940((longlong)param_1);
  return;
}

/* ---- FUNC 00001C90 FUN_180001c90 (25 bytes) ---- */

void FUN_180001c90(undefined8 *param_1)

{
  *param_1 = CMap<ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>,char_const*___ptr64,ModelTypeRefList*___ptr64,ModelTypeRefList*___ptr64>
             ::vftable;
  FUN_1800049b0((longlong)param_1);
  return;
}

/* ---- FUNC 00001CB0 ~CTypedPtrArray<CPtrArray,CNameAndState*___ptr64> (5 bytes) ---- */

/* public: virtual __cdecl CTypedPtrArray<class CPtrArray,class CNameAndState *
   __ptr64>::~CTypedPtrArray<class CPtrArray,class CNameAndState * __ptr64>(void) __ptr64 */

void __thiscall
CTypedPtrArray<CPtrArray,CNameAndState*___ptr64>::~CTypedPtrArray<CPtrArray,CNameAndState*___ptr64>
          (CTypedPtrArray<CPtrArray,CNameAndState*___ptr64> *this)

{
                    /* 0x1cb0  28  ??1?$CTypedPtrArray@VCPtrArray@@PEAVCNameAndState@@@@UEAA@XZ */
  CPtrArray::~CPtrArray((CPtrArray *)this);
  return;
}

/* ---- FUNC 00001CC0 ~CApwnBlockUsage (28 bytes) ---- */

/* public: __cdecl CApwnBlockUsage::~CApwnBlockUsage(void) __ptr64 */

void __thiscall CApwnBlockUsage::~CApwnBlockUsage(CApwnBlockUsage *this)

{
                    /* 0x1cc0  31  ??1CApwnBlockUsage@@QEAA@XZ */
  FUN_180004a40((undefined8 *)this);
  CPtrArray::~CPtrArray((CPtrArray *)(this + 8));
  return;
}

/* ---- FUNC 00001CE0 FUN_180001ce0 (271 bytes) ---- */

void FUN_180001ce0(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_1)

{
  longlong *plVar1;
  
  plVar1 = *(longlong **)(param_1 + 0x30);
  if (plVar1 != (longlong *)0x0) {
    *(undefined8 *)(param_1 + 0x30) = 0;
    (**(code **)(*plVar1 + 0x10))();
  }
  plVar1 = *(longlong **)(param_1 + 0x28);
  if (plVar1 != (longlong *)0x0) {
    *(undefined8 *)(param_1 + 0x28) = 0;
    (**(code **)(*plVar1 + 0x10))();
  }
  plVar1 = *(longlong **)(param_1 + 0x20);
  if (plVar1 != (longlong *)0x0) {
    *(undefined8 *)(param_1 + 0x20) = 0;
    (**(code **)(*plVar1 + 0x10))();
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(param_1,"");
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(param_1 + 8,"");
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(param_1 + 0x18,"");
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(param_1 + 0x10,"");
  *(undefined4 *)(param_1 + 0x38) = 0;
  if (*(longlong **)(param_1 + 0x30) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(param_1 + 0x30) + 0x10))();
  }
  if (*(longlong **)(param_1 + 0x28) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(param_1 + 0x28) + 0x10))();
  }
  if (*(longlong **)(param_1 + 0x20) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(param_1 + 0x20) + 0x10))();
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1 + 0x18);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1 + 0x10);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1 + 8);
                    /* WARNING: Could not recover jumptable at 0x000180001de8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1);
  return;
}

/* ---- FUNC 00001E00 FUN_180001e00 (34 bytes) ---- */

void FUN_180001e00(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_1)

{
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1 + 8);
                    /* WARNING: Could not recover jumptable at 0x000180001e1b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1);
  return;
}

/* ---- FUNC 00001E30 FUN_180001e30 (141 bytes) ---- */

CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
FUN_180001e30(longlong param_1,char *param_2)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar1;
  uint local_res18 [2];
  uint local_res20 [2];
  
  pCVar1 = FUN_180003d50(param_1,param_2,local_res20,local_res18);
  if (pCVar1 == (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
    if (*(longlong *)(param_1 + 8) == 0) {
      FUN_180004280(param_1,*(uint *)(param_1 + 0x10),1);
      if (*(longlong *)(param_1 + 8) == 0) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
    }
    pCVar1 = FUN_1800043b0(param_1,param_2);
    *(uint *)(pCVar1 + 0x18) = local_res18[0];
    *(undefined8 *)(pCVar1 + 0x10) =
         *(undefined8 *)((ulonglong)local_res20[0] * 8 + *(longlong *)(param_1 + 8));
    *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
     ((ulonglong)local_res20[0] * 8 + *(longlong *)(param_1 + 8)) = pCVar1;
  }
  return pCVar1 + 8;
}

/* ---- FUNC 00001EC0 operator[] (33 bytes) ---- */

/* public: class CNameAndState * __ptr64 & __ptr64 __cdecl CTypedPtrArray<class CPtrArray,class
   CNameAndState * __ptr64>::operator[](__int64) __ptr64 */

CNameAndState ** __thiscall
CTypedPtrArray<CPtrArray,CNameAndState*___ptr64>::operator[]
          (CTypedPtrArray<CPtrArray,CNameAndState*___ptr64> *this,__int64 param_1)

{
                    /* 0x1ec0  45
                       ??A?$CTypedPtrArray@VCPtrArray@@PEAVCNameAndState@@@@QEAAAEAPEAVCNameAndState@@_J@Z
                       0x1ec0  83
                       ?ElementAt@?$CTypedPtrArray@VCPtrArray@@PEAVCNameAndState@@@@QEAAAEAPEAVCNameAndState@@_J@Z
                        */
  if ((-1 < param_1) && (param_1 < *(longlong *)(this + 0x10))) {
    return (CNameAndState **)(*(longlong *)(this + 8) + param_1 * 8);
  }
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 00001EF0 operator[] (33 bytes) ---- */

/* public: class CNameAndState * __ptr64 __cdecl CTypedPtrArray<class CPtrArray,class CNameAndState
   * __ptr64>::operator[](__int64)const __ptr64 */

CNameAndState * __thiscall
CTypedPtrArray<CPtrArray,CNameAndState*___ptr64>::operator[]
          (CTypedPtrArray<CPtrArray,CNameAndState*___ptr64> *this,__int64 param_1)

{
                    /* 0x1ef0  46
                       ??A?$CTypedPtrArray@VCPtrArray@@PEAVCNameAndState@@@@QEBAPEAVCNameAndState@@_J@Z
                       0x1ef0  94
                       ?GetAt@?$CTypedPtrArray@VCPtrArray@@PEAVCNameAndState@@@@QEBAPEAVCNameAndState@@_J@Z
                        */
  if ((-1 < param_1) && (param_1 < *(longlong *)(this + 0x10))) {
    return *(CNameAndState **)(*(longlong *)(this + 8) + param_1 * 8);
  }
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 00001F20 FUN_180001f20 (171 bytes) ---- */

CPtrArray * FUN_180001f20(CPtrArray *param_1,uint param_2)

{
  if ((param_2 & 2) != 0) {
    _eh_vector_destructor_iterator_
              (param_1,0x28,*(__uint64 *)(param_1 + -8),
               CTypedPtrArray<CPtrArray,CNameAndState*___ptr64>::
               ~CTypedPtrArray<CPtrArray,CNameAndState*___ptr64>);
    if ((param_2 & 1) != 0) {
      operator_delete__(param_1 + -8);
    }
    return param_1 + -8;
  }
  CPtrArray::~CPtrArray(param_1);
  if ((param_2 & 1) != 0) {
    if ((param_2 & 4) == 0) {
      operator_delete(param_1);
      return param_1;
    }
    operator_delete(param_1);
  }
  return param_1;
}

/* ---- FUNC 00001FD0 FUN_180001fd0 (171 bytes) ---- */

CNameAndStateArray * FUN_180001fd0(CNameAndStateArray *param_1,uint param_2)

{
  if ((param_2 & 2) != 0) {
    _eh_vector_destructor_iterator_
              (param_1,0x28,*(__uint64 *)(param_1 + -8),CNameAndStateArray::~CNameAndStateArray);
    if ((param_2 & 1) != 0) {
      operator_delete__(param_1 + -8);
    }
    return param_1 + -8;
  }
  CNameAndStateArray::~CNameAndStateArray(param_1);
  if ((param_2 & 1) != 0) {
    if ((param_2 & 4) == 0) {
      operator_delete(param_1);
      return param_1;
    }
    operator_delete(param_1);
  }
  return param_1;
}

/* ---- FUNC 00002080 FUN_180002080 (78 bytes) ---- */

undefined8 * FUN_180002080(undefined8 *param_1,uint param_2)

{
  FUN_180001c70(param_1);
  if ((param_2 & 1) != 0) {
    if ((param_2 & 4) == 0) {
      operator_delete(param_1);
      return param_1;
    }
    operator_delete(param_1);
  }
  return param_1;
}

/* ---- FUNC 000020D0 FUN_1800020d0 (78 bytes) ---- */

undefined8 * FUN_1800020d0(undefined8 *param_1,uint param_2)

{
  FUN_180001c90(param_1);
  if ((param_2 & 1) != 0) {
    if ((param_2 & 4) == 0) {
      operator_delete(param_1);
      return param_1;
    }
    operator_delete(param_1);
  }
  return param_1;
}

/* ---- FUNC 00002120 Add (30 bytes) ---- */

/* public: __int64 __cdecl CTypedPtrArray<class CPtrArray,class CNameAndState * __ptr64>::Add(class
   CNameAndState * __ptr64) __ptr64 */

__int64 __thiscall
CTypedPtrArray<CPtrArray,CNameAndState*___ptr64>::Add
          (CTypedPtrArray<CPtrArray,CNameAndState*___ptr64> *this,CNameAndState *param_1)

{
  __int64 _Var1;
  
                    /* 0x2120  56
                       ?Add@?$CTypedPtrArray@VCPtrArray@@PEAVCNameAndState@@@@QEAA_JPEAVCNameAndState@@@Z
                        */
  _Var1 = *(__int64 *)(this + 0x10);
  CPtrArray::SetAtGrow((CPtrArray *)this,_Var1,param_1);
  return _Var1;
}

/* ---- FUNC 00002140 FUN_180002140 (69 bytes) ---- */

int FUN_180002140(undefined8 *param_1,char *param_2)

{
  int iVar1;
  
  iVar1 = CApwnLibraries::FindApwnLibrary((CApwnLibraries *)*param_1,param_2);
  if (iVar1 != -1) {
    return 0;
  }
  iVar1 = CApwnLibraries::AddNewLibrary((CApwnLibraries *)*param_1,param_2,1);
  return iVar1;
}

/* ---- FUNC 00002190 FUN_180002190 (1191 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

CSimpleStringT<char,1> *
FUN_180002190(undefined8 *param_1,char *param_2,char *param_3,char *param_4,char *param_5,
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_6,int param_7)

{
  longlong *plVar1;
  int iVar2;
  int iVar3;
  int extraout_EAX;
  int extraout_EAX_00;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar4;
  IAUserModelLibrary *pIVar5;
  char *pcVar6;
  undefined8 uVar7;
  INT_PTR IVar8;
  CSimpleStringT<char,1> *pCVar9;
  IAUserModelLibrary *pIVar10;
  IAUserModelLibrary *pIVar11;
  uint uVar12;
  longlong lVar13;
  undefined4 uVar15;
  bool bVar16;
  undefined1 auStackY_258 [32];
  longlong *local_200;
  IAUserModelLibrary *local_1f8;
  int local_1f0 [2];
  char *local_1e8;
  char *local_1e0;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_1d8 [8];
  char *local_1d0;
  longlong *local_1c8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_1c0;
  IAUserModelLibrary *local_1b8;
  char local_1a8 [64];
  CHAR local_168 [272];
  ulonglong local_58;
  IAUserModelLibrary *pIVar14;
  
  local_58 = DAT_1800791f8 ^ (ulonglong)auStackY_258;
  local_1d0 = param_5;
  local_1c0 = param_6;
  local_1e8 = param_4;
  local_1e0 = param_2;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_1d8);
  pIVar11 = (IAUserModelLibrary *)0x0;
  bVar16 = false;
  local_1b8 = (IAUserModelLibrary *)0x0;
  local_1f8 = (IAUserModelLibrary *)0x0;
  local_1c8 = (longlong *)0x0;
  local_200 = (longlong *)0x0;
  lVar13 = (longlong)(*(int *)(param_1 + 3) + -1);
  if (-1 < *(int *)(param_1 + 3) + -1) {
    do {
      if ((longlong)param_1[3] <= lVar13) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      pCVar4 = FUN_1800040d0(*(longlong *)(param_1[2] + lVar13 * 8),
                             (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             local_1f0);
      iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                        (pCVar4,param_2);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_1f0);
      if (iVar2 == 0) {
        pCVar9 = (CSimpleStringT<char,1> *)0x1;
        goto LAB_1800025bb;
      }
      lVar13 = lVar13 + -1;
      param_2 = local_1e0;
    } while (-1 < lVar13);
  }
  local_1f0[0] = 0;
  iVar2 = CApwnLibraries::CountLibraries((CApwnLibraries *)*param_1);
  pIVar10 = pIVar11;
  pcVar6 = local_1e8;
  pIVar14 = pIVar11;
  if (0 < iVar2) {
    do {
      pIVar5 = CApwnLibraries::GetLibrary((CApwnLibraries *)*param_1,(int)pIVar14);
      pIVar11 = pIVar10;
      if (pIVar10 != pIVar5) {
        if (pIVar5 != (IAUserModelLibrary *)0x0) {
          (**(code **)(*(longlong *)pIVar5 + 8))(pIVar5);
        }
        pIVar11 = pIVar5;
        local_1b8 = pIVar5;
        if (pIVar10 != (IAUserModelLibrary *)0x0) {
          (**(code **)(*(longlong *)pIVar10 + 0x10))();
        }
      }
      lVar13 = *(longlong *)pIVar11;
      pcVar6 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)local_1d8,0x40);
      (**(code **)(lVar13 + 0x38))(pIVar11,pcVar6,0x3f);
      ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)local_1d8,-1);
      iVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                        (local_1d8,param_3);
      pIVar10 = local_1f8;
      if (iVar3 == 0) {
        local_1f0[0] = 1;
        if (local_1f8 != pIVar11) {
          if ((pIVar11 == (IAUserModelLibrary *)0x0) ||
             (iVar2 = (*(code *)**(undefined8 **)pIVar11)(pIVar11,&DAT_180053510,&local_1f8),
             iVar2 < 0)) {
            local_1f8 = (IAUserModelLibrary *)0x0;
          }
          if (pIVar10 != (IAUserModelLibrary *)0x0) {
            (**(code **)(*(longlong *)pIVar10 + 0x10))(pIVar10);
          }
        }
        pcVar6 = local_1e8;
        if (local_1f8 != (IAUserModelLibrary *)0x0) {
          uVar12 = (**(code **)(*(longlong *)local_1f8 + 0x38))(local_1f8,local_1e8,&local_1c8);
          plVar1 = local_200;
          if (((int)uVar12 < 0) || (local_1c8 == (longlong *)0x0)) goto LAB_18000254f;
          if (local_200 != local_1c8) {
            iVar2 = (**(code **)*local_1c8)(local_1c8,&DAT_180053520,&local_200);
            if (iVar2 < 0) {
              local_200 = (longlong *)0x0;
            }
            if (plVar1 != (longlong *)0x0) {
              (**(code **)(*plVar1 + 0x10))(plVar1);
            }
          }
          bVar16 = local_200 != (longlong *)0x0;
        }
        break;
      }
      uVar12 = (int)pIVar14 + 1;
      pIVar14 = (IAUserModelLibrary *)(ulonglong)uVar12;
      pIVar10 = pIVar11;
      pcVar6 = local_1e8;
    } while ((int)uVar12 < iVar2);
  }
  pCVar4 = local_1c0;
  pCVar9 = (CSimpleStringT<char,1> *)0x0;
  if (local_1f0[0] != 0) {
    if (bVar16) {
      local_1c0 = operator_new(0x40);
      pCVar4 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)pCVar9;
      if (local_1c0 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
        pCVar4 = FUN_180001a40(local_1c0,local_1e0,param_3,pcVar6,local_1d0);
      }
      FUN_180007a00((CSimpleStringT<char,1> *)pCVar4,(longlong *)pIVar11);
      FUN_180007b60((longlong)pCVar4,local_200);
      CPtrArray::SetAtGrow((CPtrArray *)(param_1 + 1),param_1[3],pCVar4);
    }
    goto LAB_1800025bb;
  }
  if (((local_1c0 == (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) ||
      (*local_1c0 == (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>)0x0)) ||
     (uVar7 = GetModLibDocName((LPCSTR)local_1c0,local_1a8,0x40), (int)uVar7 == 0)) {
LAB_180002462:
    if (((param_7 == 0) || (uVar12 = MMGetSuppress(), uVar12 != 0)) ||
       (IVar8 = MMDriveDialog2("FileOpenDialog",8,local_168,1), (int)IVar8 == 0))
    goto LAB_1800025bb;
    GetModLibDocName(local_168,local_1a8,0x40);
    uVar12 = APModLibNameUsed((longlong)local_1a8);
    if ((uVar12 & extraout_EAX_00 == 0) != 0) {
      APModLibRegisterLib(local_1a8,local_168,0,0);
    }
    if ((uVar12 == 0) ||
       (iVar2 = CApwnLibraries::AddNewLibrary((CApwnLibraries *)*param_1,local_1a8,1), iVar2 != 0))
    goto LAB_1800025bb;
    param_7 = 0;
  }
  else {
    uVar15 = APModLibNameUsed((longlong)local_1a8);
    if (extraout_EAX == 0) {
      APModLibRegisterLib(local_1a8,(char *)CONCAT44((int)((ulonglong)pCVar4 >> 0x20),uVar15),0,0);
    }
    iVar2 = CApwnLibraries::AddNewLibrary((CApwnLibraries *)*param_1,local_1a8,1);
    if (iVar2 != 0) goto LAB_180002462;
  }
  pCVar9 = FUN_180002190(param_1,local_1e0,param_3,pcVar6,local_1d0,
                         (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0,
                         param_7);
  uVar12 = (uint)pCVar9;
LAB_18000254f:
  pCVar9 = (CSimpleStringT<char,1> *)(ulonglong)uVar12;
LAB_1800025bb:
  if (local_200 != (longlong *)0x0) {
    (**(code **)(*local_200 + 0x10))(local_200);
  }
  if (local_1c8 != (longlong *)0x0) {
    (**(code **)(*local_1c8 + 0x10))();
  }
  if (local_1f8 != (IAUserModelLibrary *)0x0) {
    (**(code **)(*(longlong *)local_1f8 + 0x10))(local_1f8);
  }
  if (pIVar11 != (IAUserModelLibrary *)0x0) {
    (**(code **)(*(longlong *)pIVar11 + 0x10))(pIVar11);
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_1d8);
  return pCVar9;
}

/* ---- FUNC 00002640 FUN_180002640 (869 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180002640(longlong param_1,longlong *param_2,longlong *param_3,longlong *param_4)

{
  longlong *plVar1;
  int iVar2;
  char *pcVar3;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar4;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar5;
  longlong lVar6;
  uint uVar7;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar8;
  undefined1 auStack_4b8 [32];
  longlong *local_498;
  longlong *local_490;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_488 [8];
  char *local_480;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_478 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_470 [8];
  longlong *local_468;
  longlong *local_460;
  longlong *local_458;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_450;
  undefined1 local_448 [1008];
  ulonglong local_58;
  
  local_58 = DAT_1800791f8 ^ (ulonglong)auStack_4b8;
  local_468 = param_3;
  local_460 = param_4;
  local_458 = param_2;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_478);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_480);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_488);
  pcVar3 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)local_478,0x40);
  FUN_180003e00(param_4,pcVar3,0x3f);
  ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)local_478,-1);
  pCVar5 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
  local_490 = (longlong *)0x0;
  if ((param_3 != (longlong *)0x0) &&
     (iVar2 = (**(code **)*param_3)(param_3,&DAT_1800561e0,&local_490), iVar2 < 0)) {
    local_490 = (longlong *)0x0;
  }
  plVar1 = local_490;
  if (local_490 != (longlong *)0x0) {
    lVar6 = *local_490;
    pcVar3 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)&local_480,0x40);
    iVar2 = (**(code **)(lVar6 + 0x18))(plVar1,pcVar3,0x3f);
    ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)&local_480,-1);
    if (iVar2 < 0) {
      FUN_180007de0(local_448,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\apwnblockusage.cpp",0xb6);
      LogMessage(local_448,2,1);
    }
  }
  lVar6 = *(longlong *)(param_1 + 0x18);
  pCVar4 = pCVar5;
  pCVar8 = pCVar5;
  if (0 < lVar6) {
    do {
      if (((longlong)pCVar8 < 0) || (lVar6 <= (longlong)pCVar8)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x10) + (longlong)pCVar8 * 8);
      uVar7 = (int)pCVar4 + 1;
      pCVar4 = FUN_1800040d0(lVar6,local_470);
      iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                        (local_478,*(char **)pCVar4);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_470);
      if (iVar2 == 0) {
        pCVar4 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                 FUN_1800040f0(lVar6);
        local_450 = pCVar4;
        if (pCVar4 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
          (**(code **)(*(longlong *)pCVar4 + 8))(pCVar4);
        }
        local_498 = (longlong *)0x0;
        if ((pCVar4 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) &&
           (iVar2 = (*(code *)**(undefined8 **)pCVar4)(pCVar4,&DAT_1800561e0,&local_498), iVar2 < 0)
           ) {
          local_498 = (longlong *)0x0;
        }
        plVar1 = local_498;
        if (local_498 != (longlong *)0x0) {
          lVar6 = *local_498;
          pcVar3 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)local_488,0x40);
          iVar2 = (**(code **)(lVar6 + 0x18))(plVar1,pcVar3,0x3f);
          ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)local_488,-1);
          if (iVar2 < 0) {
            FUN_180007de0(local_448,"Assert failed in file %s line %d",
                          "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\apwnblockusage.cpp",199);
            LogMessage(local_448,2,1);
          }
        }
        iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                          (local_488,local_480);
        if (iVar2 == 0) {
          if (local_498 != (longlong *)0x0) {
            (**(code **)(*local_498 + 0x10))();
          }
          if (pCVar4 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
            (**(code **)(*(longlong *)pCVar4 + 0x10))(pCVar4);
          }
          goto LAB_18000292d;
        }
        if (local_498 != (longlong *)0x0) {
          (**(code **)(*local_498 + 0x10))();
        }
        if (pCVar4 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
          (**(code **)(*(longlong *)pCVar4 + 0x10))(pCVar4);
        }
      }
      lVar6 = *(longlong *)(param_1 + 0x18);
      param_3 = local_468;
      pCVar4 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(ulonglong)uVar7;
      param_4 = local_460;
      pCVar8 = pCVar8 + 1;
    } while ((int)uVar7 < lVar6);
  }
  local_450 = operator_new(0x40);
  if (local_450 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
    pCVar5 = FUN_180001810(local_450,local_458,param_3,param_4);
  }
  CPtrArray::SetAtGrow((CPtrArray *)(param_1 + 8),*(__int64 *)(param_1 + 0x18),pCVar5);
LAB_18000292d:
  if (local_490 != (longlong *)0x0) {
    (**(code **)(*local_490 + 0x10))();
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_488);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_480);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_478);
  return;
}

/* ---- FUNC 000029B0 FUN_1800029b0 (852 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1800029b0(longlong param_1,longlong *param_2,longlong *param_3,longlong *param_4,
                  char *param_5)

{
  longlong *plVar1;
  int iVar2;
  char *pcVar3;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar4;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar5;
  longlong lVar6;
  uint uVar7;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar8;
  undefined1 auStack_4c8 [32];
  longlong *local_4a8;
  longlong *local_4a0;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_498 [8];
  char *local_490;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_488 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_480 [8];
  longlong *local_478;
  char *local_470;
  longlong *local_468;
  longlong *local_460;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_458;
  undefined1 local_448 [1008];
  ulonglong local_58;
  
  local_58 = DAT_1800791f8 ^ (ulonglong)auStack_4c8;
  local_470 = param_5;
  local_478 = param_3;
  local_468 = param_4;
  local_460 = param_2;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_488);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_490);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_498);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(local_488,param_5);
  pCVar5 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
  local_4a0 = (longlong *)0x0;
  if ((param_3 != (longlong *)0x0) &&
     (iVar2 = (**(code **)*param_3)(param_3,&DAT_1800561e0,&local_4a0), iVar2 < 0)) {
    local_4a0 = (longlong *)0x0;
  }
  plVar1 = local_4a0;
  if (local_4a0 != (longlong *)0x0) {
    lVar6 = *local_4a0;
    pcVar3 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)&local_490,0x40);
    iVar2 = (**(code **)(lVar6 + 0x18))(plVar1,pcVar3,0x3f);
    ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)&local_490,-1);
    if (iVar2 < 0) {
      FUN_180007de0(local_448,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\apwnblockusage.cpp",0xe0);
      LogMessage(local_448,2,1);
    }
  }
  lVar6 = *(longlong *)(param_1 + 0x18);
  pCVar4 = pCVar5;
  pCVar8 = pCVar5;
  if (0 < lVar6) {
    do {
      if (((longlong)pCVar8 < 0) || (lVar6 <= (longlong)pCVar8)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x10) + (longlong)pCVar8 * 8);
      uVar7 = (int)pCVar4 + 1;
      pCVar4 = FUN_1800040d0(lVar6,local_480);
      iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                        (local_488,*(char **)pCVar4);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_480);
      if (iVar2 == 0) {
        pCVar4 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                 FUN_1800040f0(lVar6);
        local_458 = pCVar4;
        if (pCVar4 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
          (**(code **)(*(longlong *)pCVar4 + 8))(pCVar4);
        }
        local_4a8 = (longlong *)0x0;
        if ((pCVar4 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) &&
           (iVar2 = (*(code *)**(undefined8 **)pCVar4)(pCVar4,&DAT_1800561e0,&local_4a8), iVar2 < 0)
           ) {
          local_4a8 = (longlong *)0x0;
        }
        plVar1 = local_4a8;
        if (local_4a8 != (longlong *)0x0) {
          lVar6 = *local_4a8;
          pcVar3 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)local_498,0x40);
          iVar2 = (**(code **)(lVar6 + 0x18))(plVar1,pcVar3,0x3f);
          ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)local_498,-1);
          if (iVar2 < 0) {
            FUN_180007de0(local_448,"Assert failed in file %s line %d",
                          "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\apwnblockusage.cpp",0xf1);
            LogMessage(local_448,2,1);
          }
        }
        iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                          (local_498,local_490);
        if (iVar2 == 0) {
          if (local_4a8 != (longlong *)0x0) {
            (**(code **)(*local_4a8 + 0x10))();
          }
          if (pCVar4 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
            (**(code **)(*(longlong *)pCVar4 + 0x10))(pCVar4);
          }
          goto LAB_180002c8c;
        }
        if (local_4a8 != (longlong *)0x0) {
          (**(code **)(*local_4a8 + 0x10))();
        }
        if (pCVar4 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
          (**(code **)(*(longlong *)pCVar4 + 0x10))(pCVar4);
        }
      }
      lVar6 = *(longlong *)(param_1 + 0x18);
      param_3 = local_478;
      pCVar4 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(ulonglong)uVar7;
      param_5 = local_470;
      pCVar8 = pCVar8 + 1;
    } while ((int)uVar7 < lVar6);
  }
  local_458 = operator_new(0x40);
  if (local_458 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
    pCVar5 = FUN_180001810(local_458,local_460,param_3,local_468);
  }
  FUN_180007b40((longlong)pCVar5,param_5);
  CPtrArray::SetAtGrow((CPtrArray *)(param_1 + 8),*(__int64 *)(param_1 + 0x18),pCVar5);
LAB_180002c8c:
  if (local_4a0 != (longlong *)0x0) {
    (**(code **)(*local_4a0 + 0x10))();
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_498);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_490);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_488);
  return;
}

/* ---- FUNC 00002D10 FUN_180002d10 (114 bytes) ---- */

undefined8 *
FUN_180002d10(longlong param_1,
             CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *param_2)

{
  undefined8 *puVar1;
  
  puVar1 = FUN_180004470(param_1,*(undefined8 *)(param_1 + 0x10),0);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(puVar1 + 2),param_2);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(puVar1 + 3),
             param_2 + 8);
  if (*(undefined8 **)(param_1 + 0x10) == (undefined8 *)0x0) {
    *(undefined8 **)(param_1 + 8) = puVar1;
  }
  else {
    **(undefined8 **)(param_1 + 0x10) = puVar1;
  }
  *(undefined8 **)(param_1 + 0x10) = puVar1;
  return puVar1;
}

/* ---- FUNC 00002D90 Append (5 bytes) ---- */

/* public: __int64 __cdecl CTypedPtrArray<class CPtrArray,class CNameAndState *
   __ptr64>::Append(class CTypedPtrArray<class CPtrArray,class CNameAndState * __ptr64> const &
   __ptr64) __ptr64 */

__int64 __thiscall
CTypedPtrArray<CPtrArray,CNameAndState*___ptr64>::Append
          (CTypedPtrArray<CPtrArray,CNameAndState*___ptr64> *this,
          CTypedPtrArray<class_CPtrArray,class_CNameAndState*___ptr64> *param_1)

{
  __int64 _Var1;
  
                    /* 0x2d90  64
                       ?Append@?$CTypedPtrArray@VCPtrArray@@PEAVCNameAndState@@@@QEAA_JAEBV1@@Z */
                    /* WARNING: Could not recover jumptable at 0x0001800462cb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _Var1 = CPtrArray::Append((CPtrArray *)this,(CPtrArray *)param_1);
  return _Var1;
}

/* ---- FUNC 00002DA0 InitSuppressed (3 bytes) ---- */

/* protected: virtual void __cdecl CMMDialog::InitSuppressed(void) __ptr64 */

void __thiscall CMMDialog::InitSuppressed(CMMDialog *this)

{
                    /* 0x2da0  119  ?InitSuppressed@CMMDialog@@MEAAXXZ */
  return;
}

/* ---- FUNC 00002DB0 FUN_180002db0 (1824 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180002db0(CApwnBlockUsage *param_1,char *param_2,longlong *param_3)

{
  char cVar1;
  char cVar2;
  undefined8 *puVar3;
  longlong lVar4;
  bool bVar5;
  longlong *plVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  wchar_t *bstrString;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar10;
  IAUserModelType *pIVar11;
  longlong lVar12;
  ulonglong uVar13;
  uint uVar14;
  ulonglong uVar16;
  undefined1 auStack_538 [32];
  undefined8 local_518;
  longlong *local_510;
  longlong *local_508;
  char *local_500;
  char *local_4f8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_4f0 [8];
  longlong local_4e8;
  longlong *local_4e0;
  char *local_4d8;
  int local_4d0 [2];
  longlong *local_4c8;
  longlong *local_4c0;
  CApwnBlockUsage *local_4b8;
  _union_2707 local_4b0;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_498 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_490 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_488 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_480 [8];
  undefined4 local_478;
  ULONG UStack_474;
  undefined4 uStack_470;
  ULONG UStack_46c;
  undefined8 local_468;
  _union_2707 local_458;
  undefined1 local_438 [1008];
  ulonglong local_48;
  ulonglong uVar15;
  
  local_48 = DAT_1800791f8 ^ (ulonglong)auStack_538;
  uVar13 = 0;
  local_518 = (longlong *)((ulonglong)local_518 & 0xffffffff00000000);
  local_500 = param_2;
  local_4c8 = param_3;
  local_4b8 = param_1;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4e8);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4d8);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_4f0);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4f8);
  local_4e0 = (longlong *)0x0;
  if (param_3 == (longlong *)0x0) goto LAB_180003463;
  iVar7 = (**(code **)(*param_3 + 0x38))(param_3,&local_4e0);
  if (iVar7 < 0) {
    FUN_180007de0(local_438,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\apwnblockusage.cpp",0x47a);
    LogMessage(local_438,2,1);
  }
  plVar6 = local_4e0;
  if (local_4e0 != (longlong *)0x0) {
    lVar12 = *local_4e0;
    pcVar9 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)&local_4e8,0x40);
    iVar7 = (**(code **)(lVar12 + 0x18))(plVar6,pcVar9,0x3f);
    ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)&local_4e8,-1);
    param_2 = local_500;
    if (iVar7 < 0) {
      FUN_180007de0(local_438,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\apwnblockusage.cpp",0x480);
      LogMessage(local_438,2,1);
      param_2 = local_500;
    }
  }
  local_510 = (longlong *)0x0;
  iVar7 = (**(code **)*param_3)(param_3,&DAT_1800536a8,&local_510);
  if (iVar7 < 0) {
    local_510 = (longlong *)0x0;
  }
  if (local_510 == (longlong *)0x0) {
    local_458.n2.vt._0_1_ = s__Data_Blocks__1800535b8[0];
    local_458.n2.vt._1_1_ = s__Data_Blocks__1800535b8[1];
    local_458.n2.wReserved1._0_1_ = s__Data_Blocks__1800535b8[2];
    local_458.n2.wReserved1._1_1_ = s__Data_Blocks__1800535b8[3];
    local_458.n2.wReserved2._0_1_ = s__Data_Blocks__1800535b8[4];
    local_458.n2.wReserved2._1_1_ = s__Data_Blocks__1800535b8[5];
    local_458.n2.wReserved3._0_1_ = s__Data_Blocks__1800535b8[6];
    local_458.n2.wReserved3._1_1_ = s__Data_Blocks__1800535b8[7];
    local_458._12_1_ = s__Data_Blocks__1800535b8[0xc];
    local_458._13_1_ = s__Data_Blocks__1800535b8[0xd];
    local_458._8_1_ = s__Data_Blocks__1800535b8[8];
    local_458._9_1_ = s__Data_Blocks__1800535b8[9];
    local_458._10_1_ = s__Data_Blocks__1800535b8[10];
    local_458._11_1_ = s__Data_Blocks__1800535b8[0xb];
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_508,param_2);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Insert
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_508,0,
               (char *)&local_458);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Replace
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_508,".",
               (char *)&local_458);
    puVar3 = *(undefined8 **)(param_1 + 0x30);
    local_518 = (longlong *)0x0;
    if ((puVar3 != (undefined8 *)0x0) &&
       (iVar7 = (**(code **)*puVar3)(puVar3,&DAT_1800536a8,&local_518), iVar7 < 0)) {
      local_518 = (longlong *)0x0;
    }
    if (local_518 != (longlong *)0x0) {
      bstrString = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                   AllocSysString((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                  &local_508);
      (**(code **)(*local_518 + 0x110))(local_518,bstrString,&local_510);
      SysFreeString(bstrString);
    }
    if (local_518 != (longlong *)0x0) {
      (**(code **)(*local_518 + 0x10))();
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_508);
    if (local_510 != (longlong *)0x0) goto LAB_180003017;
  }
  else {
LAB_180003017:
    local_458._0_8_ = (IAUserModelType *)0x0;
    local_458.decVal.u2.Lo64 = (_union_1719)0x0;
    local_458._16_8_ = 0;
    VariantInit((VARIANTARG *)&local_458.n2);
    local_4b0._0_8_ = 0;
    local_4b0.decVal.u2.Lo64 = (_union_1719)0x0;
    local_4b0._16_8_ = 0;
    VariantInit((VARIANTARG *)&local_4b0.n2);
    local_478 = local_4b0._0_4_;
    UStack_474 = local_4b0.decVal.Hi32;
    uStack_470 = local_4b0._8_4_;
    UStack_46c = local_4b0._12_4_;
    local_468 = local_4b0._16_8_;
    iVar7 = (**(code **)(*local_510 + 0x98))(local_510,0x3b,&local_478,&local_458);
    if ((iVar7 < 0) || (local_458.n2.vt == 0)) {
      VariantClear((VARIANTARG *)&local_458.n2);
      local_478 = local_4b0._0_4_;
      UStack_474 = local_4b0.decVal.Hi32;
      uStack_470 = local_4b0._8_4_;
      UStack_46c = local_4b0._12_4_;
      local_468 = local_4b0._16_8_;
      iVar7 = (**(code **)(*local_510 + 0x98))(local_510,6,&local_478,&local_458);
      if (-1 < iVar7) {
        goto LAB_1800030c7;
      }
    }
    else {
LAB_1800030c7:
      if (local_458.n2.vt == 8) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  (local_4f0,(wchar_t *)local_458.decVal.u2);
      }
    }
    VariantClear((VARIANTARG *)&local_4b0.n2);
    VariantClear((VARIANTARG *)&local_458.n2);
  }
  local_518 = (longlong *)((ulonglong)local_518 & 0xffffffff00000000);
  lVar12 = *(longlong *)(param_1 + 0x18);
  uVar15 = uVar13;
  uVar16 = uVar13;
  if (0 < lVar12) {
    do {
      iVar7 = (int)uVar15;
      if (((longlong)uVar13 < 0) || (lVar12 <= (longlong)uVar13)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x10) + uVar13 * 8);
      pCVar10 = FUN_1800040d0(lVar12,local_498);
      pcVar9 = param_2;
      do {
        cVar1 = *pcVar9;
        cVar2 = pcVar9[*(longlong *)pCVar10 - (longlong)param_2];
        if (cVar1 != cVar2) break;
        pcVar9 = pcVar9 + 1;
      } while (cVar2 != '\0');
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_498);
      if (cVar1 == cVar2) {
        pIVar11 = (IAUserModelType *)FUN_1800040f0(lVar12);
        local_458._0_8_ = pIVar11;
        if (pIVar11 != (IAUserModelType *)0x0) {
          (**(code **)(*(longlong *)pIVar11 + 8))(pIVar11);
        }
        local_508 = (longlong *)0x0;
        if ((pIVar11 != (IAUserModelType *)0x0) &&
           (iVar8 = (*(code *)**(undefined8 **)pIVar11)(pIVar11,&DAT_1800561e0,&local_508),
           iVar8 < 0)) {
          local_508 = (longlong *)0x0;
        }
        plVar6 = local_508;
        if (local_508 != (longlong *)0x0) {
          lVar4 = *local_508;
          pcVar9 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)&local_4d8,0x40)
          ;
          iVar7 = (**(code **)(lVar4 + 0x18))(plVar6,pcVar9,0x3f);
          ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)&local_4d8,-1);
          if (iVar7 < 0) {
            FUN_180007de0(local_438,"Assert failed in file %s line %d",
                          "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\apwnblockusage.cpp",0x4b2);
            LogMessage(local_438,2,1);
          }
          iVar7 = (int)local_518;
        }
        pCVar10 = FUN_180003de0(lVar12,local_490);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4f8,
                   (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                   pCVar10);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_490);
        iVar8 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_4e8,local_4d8);
        if (((iVar8 == 0) ||
            (iVar8 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                               (local_4f0,local_4f8), iVar8 == 0)) ||
           (*(int *)(local_4e8 + -0x10) == 0)) {
LAB_180003308:
          bVar5 = true;
        }
        else {
          iVar8 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                            (local_4f0,"CAPE-OPEN");
          if (iVar8 == 0) {
            pCVar10 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                 &local_4f8,(int)local_480);
            uVar14 = (uint)uVar16;
            uVar16 = (ulonglong)(uVar14 | 1);
            local_518 = (longlong *)(CONCAT44(local_518._4_4_,uVar14) | 1);
            iVar8 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                              (pCVar10,"{");
            if (iVar8 == 0) {
              pCVar10 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Right
                                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                   &local_4f8,(int)local_488);
              uVar16 = 3;
              local_518 = (longlong *)CONCAT44(local_518._4_4_,3);
              iVar8 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                                (pCVar10,"}");
              if (iVar8 == 0) goto LAB_180003308;
            }
          }
          bVar5 = false;
        }
        if ((uVar16 & 2) != 0) {
          uVar16 = (ulonglong)((uint)uVar16 & 0xfffffffd);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_488);
        }
        if ((uVar16 & 1) != 0) {
          uVar16 = (ulonglong)((uint)uVar16 & 0xfffffffe);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_480);
        }
        plVar6 = local_4c8;
        if (bVar5) {
          FUN_180007aa0(lVar12,local_4c8);
          pcVar9 = local_500;
          if (local_500 != (char *)0x0) {
            pCVar10 = FUN_1800040d0(lVar12,(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                            *)&local_4c8);
            iVar7 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                              (pCVar10,pcVar9);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4c8);
            if (iVar7 != 0) {
              FUN_180007b40(lVar12,pcVar9);
            }
          }
          iVar7 = (**(code **)*plVar6)(plVar6,&DAT_180056290);
          if (-1 < iVar7) {
            (**(code **)(*local_4c0 + 0x30))(local_4c0,pIVar11);
            (**(code **)(*local_4c0 + 0x10))();
          }
          (**(code **)(*(longlong *)pIVar11 + 0x30))(pIVar11,local_4d0);
          iVar7 = FUN_180004270(lVar12);
          if (local_4d0[0] != iVar7) {
            CApwnBlockUsage::NotifyModelTypeChange(local_4b8,pIVar11,(char *)0x0);
          }
          if (local_508 != (longlong *)0x0) {
            (**(code **)(*local_508 + 0x10))();
          }
          if (pIVar11 != (IAUserModelType *)0x0) {
            (**(code **)(*(longlong *)pIVar11 + 0x10))(pIVar11);
          }
          break;
        }
        if (local_508 != (longlong *)0x0) {
          (**(code **)(*local_508 + 0x10))();
        }
        param_2 = local_500;
        if (pIVar11 != (IAUserModelType *)0x0) {
          (**(code **)(*(longlong *)pIVar11 + 0x10))(pIVar11);
          param_2 = local_500;
        }
      }
      uVar14 = iVar7 + 1;
      uVar15 = (ulonglong)uVar14;
      local_518 = (longlong *)CONCAT44(local_518._4_4_,uVar14);
      uVar13 = uVar13 + 1;
      lVar12 = *(longlong *)(local_4b8 + 0x18);
      param_1 = local_4b8;
    } while ((int)uVar14 < lVar12);
  }
  if (local_510 != (longlong *)0x0) {
    (**(code **)(*local_510 + 0x10))();
  }
LAB_180003463:
  if (local_4e0 != (longlong *)0x0) {
    (**(code **)(*local_4e0 + 0x10))(local_4e0);
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4f8);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_4f0);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4d8);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4e8);
  return;
}

/* ---- FUNC 000034E0 FUN_1800034e0 (1755 bytes) ---- */

/* WARNING: Removing unreachable block (ram,0x000180003b4a) */
/* WARNING: Removing unreachable block (ram,0x000180003670) */
/* WARNING: Removing unreachable block (ram,0x00018000359a) */
/* WARNING: Removing unreachable block (ram,0x0001800035bb) */
/* WARNING: Removing unreachable block (ram,0x0001800035b2) */
/* WARNING: Removing unreachable block (ram,0x000180003889) */
/* WARNING: Removing unreachable block (ram,0x0001800038aa) */
/* WARNING: Removing unreachable block (ram,0x0001800038a1) */
/* WARNING: Removing unreachable block (ram,0x00018000395b) */
/* WARNING: Removing unreachable block (ram,0x000180003824) */
/* WARNING: Removing unreachable block (ram,0x00018000374e) */
/* WARNING: Removing unreachable block (ram,0x00018000376f) */
/* WARNING: Removing unreachable block (ram,0x000180003766) */
/* WARNING: Removing unreachable block (ram,0x000180003a78) */
/* WARNING: Removing unreachable block (ram,0x000180003a99) */
/* WARNING: Removing unreachable block (ram,0x000180003a90) */
/* WARNING: Removing unreachable block (ram,0x000180003b8a) */
/* WARNING: Removing unreachable block (ram,0x00018000377c) */
/* WARNING: Removing unreachable block (ram,0x00018000379b) */
/* WARNING: Removing unreachable block (ram,0x0001800037bc) */
/* WARNING: Removing unreachable block (ram,0x0001800037b3) */
/* WARNING: Removing unreachable block (ram,0x0001800037c0) */
/* WARNING: Removing unreachable block (ram,0x0001800037c5) */
/* WARNING: Removing unreachable block (ram,0x0001800037d3) */
/* WARNING: Removing unreachable block (ram,0x0001800037d8) */
/* WARNING: Removing unreachable block (ram,0x0001800037de) */
/* WARNING: Removing unreachable block (ram,0x0001800037f9) */
/* WARNING: Removing unreachable block (ram,0x000180003808) */
/* WARNING: Removing unreachable block (ram,0x0001800038b7) */
/* WARNING: Removing unreachable block (ram,0x0001800038d6) */
/* WARNING: Removing unreachable block (ram,0x0001800038f7) */
/* WARNING: Removing unreachable block (ram,0x0001800038ee) */
/* WARNING: Removing unreachable block (ram,0x0001800038fb) */
/* WARNING: Removing unreachable block (ram,0x000180003900) */
/* WARNING: Removing unreachable block (ram,0x00018000390e) */
/* WARNING: Removing unreachable block (ram,0x000180003913) */
/* WARNING: Removing unreachable block (ram,0x000180003919) */
/* WARNING: Removing unreachable block (ram,0x000180003934) */
/* WARNING: Removing unreachable block (ram,0x000180003943) */
/* WARNING: Removing unreachable block (ram,0x0001800035c8) */
/* WARNING: Removing unreachable block (ram,0x0001800035e7) */
/* WARNING: Removing unreachable block (ram,0x000180003608) */
/* WARNING: Removing unreachable block (ram,0x0001800035ff) */
/* WARNING: Removing unreachable block (ram,0x00018000360c) */
/* WARNING: Removing unreachable block (ram,0x000180003611) */
/* WARNING: Removing unreachable block (ram,0x00018000361f) */
/* WARNING: Removing unreachable block (ram,0x000180003624) */
/* WARNING: Removing unreachable block (ram,0x00018000362a) */
/* WARNING: Removing unreachable block (ram,0x000180003645) */
/* WARNING: Removing unreachable block (ram,0x000180003654) */
/* WARNING: Removing unreachable block (ram,0x000180003aa6) */
/* WARNING: Removing unreachable block (ram,0x000180003ac5) */
/* WARNING: Removing unreachable block (ram,0x000180003ae6) */
/* WARNING: Removing unreachable block (ram,0x000180003add) */
/* WARNING: Removing unreachable block (ram,0x000180003aea) */
/* WARNING: Removing unreachable block (ram,0x000180003aef) */
/* WARNING: Removing unreachable block (ram,0x000180003afd) */
/* WARNING: Removing unreachable block (ram,0x000180003b02) */
/* WARNING: Removing unreachable block (ram,0x000180003b08) */
/* WARNING: Removing unreachable block (ram,0x000180003b23) */
/* WARNING: Removing unreachable block (ram,0x000180003b32) */
/* WARNING: Removing unreachable block (ram,0x000180003811) */
/* WARNING: Removing unreachable block (ram,0x00018000394c) */
/* WARNING: Removing unreachable block (ram,0x00018000365d) */
/* WARNING: Removing unreachable block (ram,0x000180003b3b) */

int FUN_1800034e0(CApwnBlockUsage *param_1,longlong *param_2,CSimpleStringT<char,1> *param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar4;
  char *pcVar5;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar6;
  IAtlStringMgr *pIVar7;
  longlong lVar8;
  ulonglong local_res20;
  undefined8 local_60;
  char *local_58;
  longlong *local_50;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_48 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_40 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_38 [16];
  longlong lVar9;
  
  local_res20 = local_res20 & 0xffffffff00000000;
  iVar2 = -0x7fffbffb;
  local_50 = (longlong *)0x0;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_60);
  FUN_180007a00(param_3,param_2);
  (**(code **)*param_2)(param_2,&DAT_180056240,&local_50);
  if (local_50 != (longlong *)0x0) {
    pCVar4 = FUN_180004250((longlong)param_3,
                           (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_res20);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_60,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar4);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20);
    iVar2 = (**(code **)(*local_50 + 0x38))(local_50,local_60);
    if (iVar2 < 0) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_48);
      lVar9 = *param_2;
      pcVar5 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)local_48,0x40);
      (**(code **)(lVar9 + 0x38))(param_2,pcVar5);
      ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)local_48,-1);
      iVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                        (local_48,"Built-In");
      if (iVar3 == 0) {
        pCVar4 = FUN_180003de0((longlong)param_3,
                               (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                               &local_res20);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_60,
                   (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                   pCVar4);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20);
        iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_60,"HTRIIST");
        if (iVar2 == 0) {
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_60,
                     "HTRIXIST");
        }
        iVar2 = (**(code **)(*local_50 + 0x38))();
        if (iVar2 < 0) {
          cVar1 = ATL::CSimpleStringT<char,1>::operator[]((CSimpleStringT<char,1> *)&local_60,0);
          pcVar5 = "USER3";
          if (cVar1 == '{') {
            pcVar5 = "CAPE-OPEN";
          }
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_60,
                     pcVar5);
          iVar2 = (**(code **)(*local_50 + 0x38))(local_50,local_60);
          if (-1 < iVar2) {
            local_res20 = 0;
            iVar2 = 1;
          }
        }
        else {
          local_res20 = 0;
        }
      }
      else {
        iVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                          (local_48,"ACM Models");
        if (iVar3 == 0) {
          FUN_180004250((longlong)param_3,
                        (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_58);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    (local_38,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                               *)&local_58);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::MakeLower(local_38);
          iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Find
                            (local_38," v",0);
          if (iVar2 == -1) {
            pIVar7 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                               ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                &local_58);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_40,pIVar7);
            local_res20 = CONCAT44(local_res20._4_4_,1);
            lVar9 = -1;
            do {
              lVar8 = lVar9 + 1;
              pcVar5 = "v12_1" + lVar9;
              lVar9 = lVar8;
            } while (*pcVar5 != '\0');
            ATL::CSimpleStringT<char,1>::Concatenate
                      ((CSimpleStringT<char,1> *)local_40,local_58,*(int *)(local_58 + -0x10),
                       " v12_1",(int)lVar8);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_58,
                       (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                       local_40);
            pCVar4 = local_40;
          }
          else {
            pCVar6 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                     ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                               ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                &local_58,(int)&local_res20);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_58,
                       pCVar6);
            pCVar4 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20;
          }
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar4);
          iVar2 = (**(code **)(*local_50 + 0x38))(local_50,local_58);
          if (-1 < iVar2) {
            local_res20 = 0;
          }
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_38);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_58);
        }
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_48);
    }
    else {
      local_res20 = 0;
    }
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_60);
  if (local_50 != (longlong *)0x0) {
    (**(code **)(*local_50 + 0x10))();
  }
  return iVar2;
}

/* ---- FUNC 00003BC0 FUN_180003bc0 (167 bytes) ---- */

void FUN_180003bc0(longlong param_1,
                  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_2,
                  longlong *param_3)

{
  int iVar1;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar2;
  ulonglong uVar3;
  uint uVar4;
  ulonglong uVar5;
  longlong lVar6;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res8 [8];
  
  uVar3 = 0;
  lVar6 = *(longlong *)(param_1 + 0x18);
  uVar5 = uVar3;
  if (0 < lVar6) {
    do {
      if (((longlong)uVar3 < 0) || (lVar6 <= (longlong)uVar3)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x10) + uVar3 * 8);
      pCVar2 = FUN_1800040d0(lVar6,local_res8);
      iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                        (param_2,*(char **)pCVar2);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res8);
      if (iVar1 == 0) {
        FUN_180007b60(lVar6,param_3);
        return;
      }
      uVar4 = (int)uVar5 + 1;
      uVar3 = uVar3 + 1;
      lVar6 = *(longlong *)(param_1 + 0x18);
      uVar5 = (ulonglong)uVar4;
    } while ((int)uVar4 < lVar6);
  }
  return;
}

/* ---- FUNC 00003C70 Copy (5 bytes) ---- */

/* public: void __cdecl CTypedPtrArray<class CPtrArray,class CNameAndState * __ptr64>::Copy(class
   CTypedPtrArray<class CPtrArray,class CNameAndState * __ptr64> const & __ptr64) __ptr64 */

void __thiscall
CTypedPtrArray<CPtrArray,CNameAndState*___ptr64>::Copy
          (CTypedPtrArray<CPtrArray,CNameAndState*___ptr64> *this,
          CTypedPtrArray<class_CPtrArray,class_CNameAndState*___ptr64> *param_1)

{
                    /* 0x3c70  73
                       ?Copy@?$CTypedPtrArray@VCPtrArray@@PEAVCNameAndState@@@@QEAAXAEBV1@@Z */
  CPtrArray::Copy((CPtrArray *)this,(CPtrArray *)param_1);
  return;
}

/* ---- FUNC 00003C80 FUN_180003c80 (200 bytes) ---- */

undefined8
FUN_180003c80(longlong param_1,
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_2,
             undefined8 *param_3)

{
  int iVar1;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar2;
  longlong *plVar3;
  ulonglong uVar4;
  uint uVar5;
  ulonglong uVar6;
  longlong lVar7;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res8 [8];
  
  uVar4 = 0;
  lVar7 = *(longlong *)(param_1 + 0x18);
  uVar6 = uVar4;
  if (0 < lVar7) {
    do {
      if (((longlong)uVar4 < 0) || (lVar7 <= (longlong)uVar4)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x10) + uVar4 * 8);
      pCVar2 = FUN_1800040d0(lVar7,local_res8);
      iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                        (param_2,*(char **)pCVar2);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res8);
      if ((iVar1 == 0) && (plVar3 = (longlong *)FUN_180003f70(lVar7), plVar3 != (longlong *)0x0)) {
        (**(code **)(*plVar3 + 8))(plVar3);
        *param_3 = plVar3;
        return 0;
      }
      uVar5 = (int)uVar6 + 1;
      uVar4 = uVar4 + 1;
      lVar7 = *(longlong *)(param_1 + 0x18);
      uVar6 = (ulonglong)uVar5;
    } while ((int)uVar5 < lVar7);
  }
  return 1;
}

/* ---- FUNC 00003D50 FUN_180003d50 (134 bytes) ---- */

CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
FUN_180003d50(longlong param_1,char *param_2,undefined4 *param_3,uint *param_4)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar1;
  ulonglong uVar2;
  bool bVar3;
  uint uVar4;
  undefined7 extraout_var;
  char *local_res10;
  
  local_res10 = param_2;
  uVar4 = HashKey<char_const*___ptr64>(param_2);
  *param_4 = uVar4;
  uVar2 = (ulonglong)uVar4 % (ulonglong)*(uint *)(param_1 + 0x10);
  *param_3 = (int)uVar2;
  if (*(longlong *)(param_1 + 8) != 0) {
    for (pCVar1 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
                   (*(longlong *)(param_1 + 8) + uVar2 * 8);
        pCVar1 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
        pCVar1 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)(pCVar1 + 0x10))
    {
      if ((*(uint *)(pCVar1 + 0x18) == *param_4) &&
         (bVar3 = FUN_180001540(pCVar1,&local_res10), (int)CONCAT71(extraout_var,bVar3) != 0)) {
        return pCVar1;
      }
    }
  }
  return (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
}

/* ---- FUNC 00003DE0 FUN_180003de0 (31 bytes) ---- */

CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
FUN_180003de0(longlong param_1,
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_2)

{
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            (param_2,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                     (param_1 + 0x18));
  return param_2;
}

/* ---- FUNC 00003E00 FUN_180003e00 (328 bytes) ---- */

void FUN_180003e00(longlong *param_1,char *param_2,int param_3)

{
  int iVar1;
  char *local_res8;
  longlong *local_res20;
  _union_2707 local_78;
  _union_2707 local_60;
  int local_48;
  ULONG UStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined8 local_38;
  VARIANTARG local_28;
  
  if ((param_1 != (longlong *)0x0) && (param_2 != (char *)0x0)) {
    *param_2 = '\0';
    iVar1 = (**(code **)*param_1)(param_1,&DAT_180056180,&local_res20);
    if (iVar1 < 0) {
      (**(code **)(*param_1 + 0x18))(param_1,param_2,param_3);
    }
    else {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8);
      AfxVariantInit((tagVARIANT *)&local_78.n2);
      VariantInit((VARIANTARG *)&local_60.n2);
      VariantInit(&local_28);
      local_60._0_4_ = (uint)local_60.n2.wReserved1 << 0x10;
      local_48 = local_60._0_4_;
      UStack_44 = local_60.decVal.Hi32;
      uStack_40 = local_60._8_4_;
      uStack_3c = local_60._12_4_;
      local_38 = local_60._16_8_;
      (**(code **)(*local_res20 + 0x98))(local_res20,0x41,&local_48,&local_78);
      if (local_78.n2.vt == 8) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8,
                   (wchar_t *)local_78.decVal.u2);
        strncpy(param_2,local_res8,(longlong)param_3);
      }
      else {
        (**(code **)(*param_1 + 0x18))(param_1,param_2,param_3);
      }
      (**(code **)(*local_res20 + 0x10))();
      VariantClear((VARIANTARG *)&local_78.n2);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8);
    }
  }
  return;
}

/* ---- FUNC 00003F50 FUN_180003f50 (30 bytes) ---- */

CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
FUN_180003f50(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *param_1,
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_2)

{
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_2,param_1);
  return param_2;
}

/* ---- FUNC 00003F70 FUN_180003f70 (5 bytes) ---- */

undefined8 FUN_180003f70(longlong param_1)

{
  return *(undefined8 *)(param_1 + 0x30);
}

/* ---- FUNC 00003F80 FUN_180003f80 (328 bytes) ---- */

undefined8 FUN_180003f80(longlong param_1,char *param_2,char *param_3,char *param_4,char *param_5)

{
  char cVar1;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar2;
  int iVar3;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar4;
  char *pcVar5;
  longlong lVar6;
  char *pcVar7;
  
  pcVar7 = param_5;
  iVar3 = *(int *)(param_1 + 0x18);
  *param_3 = '\0';
  *param_4 = '\0';
  *param_5 = '\0';
  iVar3 = iVar3 + -1;
  lVar6 = (longlong)iVar3;
  if (-1 < iVar3) {
    do {
      if (*(longlong *)(param_1 + 0x18) <= lVar6) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      pCVar2 = *(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> **)
                (*(longlong *)(param_1 + 0x10) + lVar6 * 8);
      pCVar4 = FUN_1800040d0((longlong)pCVar2,
                             (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &param_5);
      iVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                        (pCVar4,param_2);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&param_5);
      if (iVar3 == 0) {
        pCVar4 = FUN_180003f50(pCVar2,(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                       *)&param_5);
        pcVar5 = *(char **)pCVar4;
        do {
          cVar1 = *pcVar5;
          *param_3 = cVar1;
          pcVar5 = pcVar5 + 1;
          param_3 = param_3 + 1;
        } while (cVar1 != '\0');
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&param_5);
        pCVar4 = FUN_180004250((longlong)pCVar2,
                               (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                               &param_5);
        pcVar5 = *(char **)pCVar4;
        do {
          cVar1 = *pcVar5;
          *param_4 = cVar1;
          pcVar5 = pcVar5 + 1;
          param_4 = param_4 + 1;
        } while (cVar1 != '\0');
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&param_5);
        pCVar4 = FUN_180003de0((longlong)pCVar2,
                               (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                               &param_5);
        pcVar5 = *(char **)pCVar4;
        do {
          cVar1 = *pcVar5;
          *pcVar7 = cVar1;
          pcVar5 = pcVar5 + 1;
          pcVar7 = pcVar7 + 1;
        } while (cVar1 != '\0');
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&param_5);
        return 0;
      }
      lVar6 = lVar6 + -1;
    } while (-1 < lVar6);
  }
  return 1;
}

/* ---- FUNC 000040D0 FUN_1800040d0 (31 bytes) ---- */

CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
FUN_1800040d0(longlong param_1,
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_2)

{
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            (param_2,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                     (param_1 + 0x10));
  return param_2;
}

/* ---- FUNC 000040F0 FUN_1800040f0 (5 bytes) ---- */

undefined8 FUN_1800040f0(longlong param_1)

{
  return *(undefined8 *)(param_1 + 0x28);
}

/* ---- FUNC 00004100 FUN_180004100 (153 bytes) ---- */

void FUN_180004100(longlong param_1,longlong *param_2,
                  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_3,
                  undefined8 *param_4)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar5;
  
  lVar1 = *(longlong *)(param_1 + 8);
  if ((lVar1 != 0) &&
     (pCVar5 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)*param_2
     , pCVar5 != (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)0x0))
  {
    if (pCVar5 == (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                  0xffffffffffffffff) {
      uVar4 = 0;
      if (*(uint *)(param_1 + 0x10) != 0) {
        do {
          pCVar5 = *(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> **)
                    (lVar1 + uVar4 * 8);
          if (pCVar5 != (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *
                        )0x0) goto LAB_180004147;
          uVar3 = (int)uVar4 + 1;
          uVar4 = (ulonglong)uVar3;
        } while (uVar3 < *(uint *)(param_1 + 0x10));
        goto LAB_180004194;
      }
    }
LAB_180004147:
    lVar2 = *(longlong *)(pCVar5 + 0x10);
    if (lVar2 == 0) {
      uVar3 = *(uint *)(pCVar5 + 0x18) % *(uint *)(param_1 + 0x10);
      do {
        uVar3 = uVar3 + 1;
        if (*(uint *)(param_1 + 0x10) <= uVar3) break;
        lVar2 = *(longlong *)(lVar1 + (ulonglong)uVar3 * 8);
      } while (lVar2 == 0);
    }
    *param_2 = lVar2;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(param_3,pCVar5);
    *param_4 = *(undefined8 *)(pCVar5 + 8);
    return;
  }
LAB_180004194:
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 000041A0 FUN_1800041a0 (120 bytes) ---- */

int FUN_1800041a0(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  ulonglong uVar3;
  int iVar4;
  uint uVar5;
  ulonglong uVar6;
  
  lVar1 = *(longlong *)(param_1 + 0x18);
  uVar3 = 0;
  iVar4 = 4;
  uVar6 = uVar3;
  if (0 < lVar1) {
    do {
      if (((longlong)uVar3 < 0) || (lVar1 <= (longlong)uVar3)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      iVar2 = FUN_180004220(*(longlong **)(*(longlong *)(param_1 + 0x10) + uVar3 * 8));
      uVar5 = (int)uVar6 + 1;
      iVar4 = iVar4 + iVar2;
      uVar3 = uVar3 + 1;
      uVar6 = (ulonglong)uVar5;
    } while ((int)uVar5 < lVar1);
  }
  return iVar4;
}

/* ---- FUNC 00004220 FUN_180004220 (37 bytes) ---- */

int FUN_180004220(longlong *param_1)

{
  return *(int *)(*param_1 + -0x10) + 0x18 +
         *(int *)(param_1[3] + -0x10) + *(int *)(param_1[2] + -0x10) + *(int *)(param_1[1] + -0x10);
}

/* ---- FUNC 00004250 FUN_180004250 (31 bytes) ---- */

CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
FUN_180004250(longlong param_1,
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_2)

{
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            (param_2,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                     (param_1 + 8));
  return param_2;
}

/* ---- FUNC 00004270 FUN_180004270 (4 bytes) ---- */

undefined4 FUN_180004270(longlong param_1)

{
  return *(undefined4 *)(param_1 + 0x38);
}

/* ---- FUNC 00004280 FUN_180004280 (127 bytes) ---- */

void FUN_180004280(longlong param_1,uint param_2,int param_3)

{
  undefined1 auVar1 [16];
  __uint64 _Var2;
  void *_Dst;
  
  if (*(void **)(param_1 + 8) != (void *)0x0) {
    operator_delete__(*(void **)(param_1 + 8));
    *(undefined8 *)(param_1 + 8) = 0;
  }
  if (param_3 != 0) {
    auVar1._8_8_ = 0;
    auVar1._0_8_ = CONCAT44(0,param_2);
    _Var2 = SUB168(ZEXT816(8) * auVar1,0);
    if (SUB168(ZEXT816(8) * auVar1,8) != 0) {
      _Var2 = 0xffffffffffffffff;
    }
    _Dst = operator_new__(_Var2);
    *(void **)(param_1 + 8) = _Dst;
    if (_Dst == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      AfxThrowInvalidArgException();
    }
    memset(_Dst,0,CONCAT44(0,param_2) * 8);
  }
  *(uint *)(param_1 + 0x10) = param_2;
  return;
}

/* ---- FUNC 00004300 InsertAt (5 bytes) ---- */

/* public: void __cdecl CTypedPtrArray<class CPtrArray,class CNameAndState *
   __ptr64>::InsertAt(__int64,class CTypedPtrArray<class CPtrArray,class CNameAndState * __ptr64> *
   __ptr64) __ptr64 */

void __thiscall
CTypedPtrArray<CPtrArray,CNameAndState*___ptr64>::InsertAt
          (CTypedPtrArray<CPtrArray,CNameAndState*___ptr64> *this,__int64 param_1,
          CTypedPtrArray<class_CPtrArray,class_CNameAndState*___ptr64> *param_2)

{
                    /* 0x4300  122
                       ?InsertAt@?$CTypedPtrArray@VCPtrArray@@PEAVCNameAndState@@@@QEAAX_JPEAV1@@Z
                        */
                    /* WARNING: Could not recover jumptable at 0x0001800462e3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CPtrArray::InsertAt((CPtrArray *)this,param_1,(CPtrArray *)param_2);
  return;
}

/* ---- FUNC 00004310 InsertAt (5 bytes) ---- */

/* public: void __cdecl CTypedPtrArray<class CPtrArray,class CNameAndState *
   __ptr64>::InsertAt(__int64,class CNameAndState * __ptr64,__int64) __ptr64 */

void __thiscall
CTypedPtrArray<CPtrArray,CNameAndState*___ptr64>::InsertAt
          (CTypedPtrArray<CPtrArray,CNameAndState*___ptr64> *this,__int64 param_1,
          CNameAndState *param_2,__int64 param_3)

{
                    /* 0x4310  123
                       ?InsertAt@?$CTypedPtrArray@VCPtrArray@@PEAVCNameAndState@@@@QEAAX_JPEAVCNameAndState@@0@Z
                        */
  CPtrArray::InsertAt((CPtrArray *)this,param_1,param_2,param_3);
  return;
}

/* ---- FUNC 00004320 FUN_180004320 (53 bytes) ---- */

undefined8 FUN_180004320(longlong param_1,char *param_2,undefined8 *param_3)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar1;
  uint local_res20 [2];
  undefined4 local_18 [4];
  
  pCVar1 = FUN_180003d50(param_1,param_2,local_18,local_res20);
  if (pCVar1 == (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
    return 0;
  }
  *param_3 = *(undefined8 *)(pCVar1 + 8);
  return 1;
}

/* ---- FUNC 00004360 FUN_180004360 (67 bytes) ---- */

void FUN_180004360(longlong param_1,undefined4 param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  
  iVar1 = *(int *)(param_1 + 0x18);
  if (0 < (longlong)iVar1) {
    lVar3 = 0;
    do {
      if ((lVar3 < 0) || (*(longlong *)(param_1 + 0x18) <= lVar3)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x10) + lVar3 * 8);
      if (lVar2 != 0) {
        *(undefined4 *)(lVar2 + 0x3c) = param_2;
      }
      lVar3 = lVar3 + 1;
    } while (lVar3 < iVar1);
  }
  return;
}

/* ---- FUNC 000043B0 FUN_1800043b0 (184 bytes) ---- */

CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
FUN_1800043b0(longlong param_1,char *param_2)

{
  longlong lVar1;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this;
  undefined8 uVar2;
  CPlex *pCVar3;
  
  if (*(longlong *)(param_1 + 0x20) == 0) {
    pCVar3 = CPlex::Create((CPlex **)(param_1 + 0x28),*(__uint64 *)(param_1 + 0x30),0x20);
    lVar1 = *(longlong *)(param_1 + 0x30);
    pCVar3 = pCVar3 + lVar1 * 0x20 + -0x18;
    while (lVar1 = lVar1 + -1, -1 < lVar1) {
      *(undefined8 *)(pCVar3 + 0x10) = *(undefined8 *)(param_1 + 0x20);
      *(CPlex **)(param_1 + 0x20) = pCVar3;
      pCVar3 = pCVar3 + -0x20;
    }
  }
  this = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)(param_1 + 0x20);
  if (this != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
    *(undefined8 *)this = 0;
    *(undefined8 *)(this + 8) = 0;
    *(undefined8 *)(this + 0x18) = 0;
    *(undefined8 *)(this + 0x10) = *(undefined8 *)(this + 0x10);
    uVar2 = *(undefined8 *)(*(longlong *)(param_1 + 0x20) + 0x10);
    *(longlong *)(param_1 + 0x18) = *(longlong *)(param_1 + 0x18) + 1;
    *(undefined8 *)(param_1 + 0x20) = uVar2;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(this,param_2);
    return this;
  }
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 00004470 FUN_180004470 (177 bytes) ---- */

undefined8 * FUN_180004470(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  undefined8 *puVar2;
  CPlex *pCVar3;
  
  if (*(longlong *)(param_1 + 0x20) == 0) {
    pCVar3 = CPlex::Create((CPlex **)(param_1 + 0x28),*(__uint64 *)(param_1 + 0x30),0x20);
    lVar1 = *(longlong *)(param_1 + 0x30);
    pCVar3 = pCVar3 + lVar1 * 0x20 + -0x18;
    while (lVar1 = lVar1 + -1, -1 < lVar1) {
      *(undefined8 *)pCVar3 = *(undefined8 *)(param_1 + 0x20);
      *(CPlex **)(param_1 + 0x20) = pCVar3;
      pCVar3 = pCVar3 + -0x20;
    }
  }
  puVar2 = *(undefined8 **)(param_1 + 0x20);
  if (puVar2 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
    AfxThrowInvalidArgException();
  }
  *(undefined8 *)(param_1 + 0x20) = *puVar2;
  puVar2[1] = param_2;
  *puVar2 = param_3;
  *(longlong *)(param_1 + 0x18) = *(longlong *)(param_1 + 0x18) + 1;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(puVar2 + 2));
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(puVar2 + 3));
  return puVar2;
}

/* ---- FUNC 00004530 NotifyModelTypeChange (481 bytes) ---- */

/* public: void __cdecl CApwnBlockUsage::NotifyModelTypeChange(struct IAUserModelType * __ptr64,char
   const * __ptr64) __ptr64 */

void __thiscall
CApwnBlockUsage::NotifyModelTypeChange(CApwnBlockUsage *this,IAUserModelType *param_1,char *param_2)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar4;
  longlong lVar5;
  longlong lVar6;
  int iVar7;
  int local_res10 [2];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res20 [8];
  longlong *local_58;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_50 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_48 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_40 [8];
  
                    /* 0x4530  157
                       ?NotifyModelTypeChange@CApwnBlockUsage@@QEAAXPEAUIAUserModelType@@PEBD@Z */
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res20);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_50);
  (*(code *)**(undefined8 **)param_1)(param_1,&DAT_1800561e0,&local_58);
  lVar5 = *local_58;
  pcVar3 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)local_res20,0x40);
  (**(code **)(lVar5 + 0x18))(local_58,pcVar3,0x3f);
  ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)local_res20,-1);
  (**(code **)(*local_58 + 0x10))();
  (**(code **)(*(longlong *)param_1 + 0x30))(param_1,local_res10);
  iVar7 = 0;
  lVar5 = *(longlong *)(this + 0x18);
  if (0 < lVar5) {
    lVar6 = 0;
    do {
      if ((lVar6 < 0) || (lVar5 <= lVar6)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      lVar5 = *(longlong *)(*(longlong *)(this + 0x10) + lVar6 * 8);
      if ((param_2 == (char *)0x0) || (*param_2 == '\0')) {
        pCVar4 = FUN_180004250(lVar5,local_40);
        iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                          (local_res20,*(char **)pCVar4);
        if ((iVar2 == 0) && (iVar2 = FUN_180004270(lVar5), local_res10[0] != iVar2)) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_40);
        if (bVar1) goto LAB_1800046bc;
      }
      else {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  (local_50,param_2);
        pCVar4 = FUN_180004250(lVar5,local_48);
        iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                          (local_50,*(char **)pCVar4);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_48);
        if (iVar2 == 0) {
          FUN_180007b60(lVar5,(longlong *)param_1);
LAB_1800046bc:
          FUN_180004720(lVar5);
        }
      }
      iVar7 = iVar7 + 1;
      lVar6 = lVar6 + 1;
      lVar5 = *(longlong *)(this + 0x18);
    } while (iVar7 < lVar5);
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_50);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res20);
  return;
}

/* ---- FUNC 00004720 FUN_180004720 (82 bytes) ---- */

void FUN_180004720(longlong param_1)

{
  undefined8 *puVar1;
  longlong *plVar2;
  longlong *local_res8 [4];
  
  puVar1 = *(undefined8 **)(param_1 + 0x30);
  if (puVar1 != (undefined8 *)0x0) {
    (**(code **)*puVar1)(puVar1,&DAT_180056290,local_res8);
    (**(code **)(*local_res8[0] + 0x28))();
    (**(code **)(*local_res8[0] + 0x10))();
    plVar2 = *(longlong **)(param_1 + 0x28);
    if (plVar2 != (longlong *)0x0) {
      (**(code **)(*plVar2 + 0x30))(plVar2,param_1 + 0x38);
    }
  }
  return;
}

/* ---- FUNC 00004780 FUN_180004780 (432 bytes) ---- */

void FUN_180004780(longlong param_1,char *param_2,char *param_3,int param_4,int param_5)

{
  int iVar1;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar2;
  longlong lVar3;
  CSimpleStringT<char,1> *pCVar4;
  longlong lVar5;
  longlong lVar6;
  ulonglong uVar7;
  uint uVar8;
  ulonglong uVar9;
  char *local_res8;
  char *local_58;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_50 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_48 [16];
  
  lVar6 = -1;
  do {
    lVar6 = lVar6 + 1;
  } while (param_2[lVar6] != '\0');
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_58);
  uVar7 = 0;
  lVar5 = *(longlong *)(param_1 + 0x18);
  uVar9 = uVar7;
  if (0 < lVar5) {
    do {
      if (((longlong)uVar7 < 0) || (lVar5 <= (longlong)uVar7)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x10) + uVar7 * 8);
      if ((param_5 == 0) || (*(int *)(lVar5 + 0x3c) == 0)) {
        pCVar2 = FUN_1800040d0(lVar5,local_50);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8,
                   (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                   pCVar2);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_50);
        iVar1 = strncmp(local_res8,param_2,(longlong)(int)lVar6);
        if (iVar1 == 0) {
          lVar3 = FUN_180003f70(lVar5);
          if (lVar3 == 0) {
            if ((param_4 == 0) || (*(int *)(local_res8 + -0x10) == (int)lVar6)) {
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_58,
                         param_3);
              pCVar4 = (CSimpleStringT<char,1> *)
                       ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Right
                                 ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                  &local_res8,(int)local_48);
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_58,
                         pCVar4);
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_48);
              FUN_180007b40(lVar5,local_58);
            }
          }
          else {
            FUN_180004d90(lVar5);
          }
        }
      }
      uVar8 = (int)uVar9 + 1;
      uVar7 = uVar7 + 1;
      lVar5 = *(longlong *)(param_1 + 0x18);
      uVar9 = (ulonglong)uVar8;
    } while ((int)uVar8 < lVar5);
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_58);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8);
  return;
}

/* ---- FUNC 00004940 FUN_180004940 (22 bytes) ---- */

void FUN_180004940(longlong param_1)

{
  undefined8 *puVar1;
  
  for (puVar1 = *(undefined8 **)(param_1 + 8); puVar1 != (undefined8 *)0x0;
      puVar1 = (undefined8 *)*puVar1) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(puVar1 + 3));
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(puVar1 + 2));
  }
  *(undefined8 *)(param_1 + 0x18) = 0;
  *(undefined8 *)(param_1 + 0x20) = 0;
  *(undefined8 *)(param_1 + 0x10) = 0;
  *(undefined8 *)(param_1 + 8) = 0;
  CPlex::FreeDataChain(*(CPlex **)(param_1 + 0x28));
  *(undefined8 *)(param_1 + 0x28) = 0;
  return;
}

/* ---- FUNC 00004956 FUN_180004956 (43 bytes) ---- */

void FUN_180004956(void)

{
  longlong *unaff_RBX;
  longlong unaff_RSI;
  
  do {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(unaff_RBX + 3));
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(unaff_RBX + 2));
    unaff_RBX = (longlong *)*unaff_RBX;
  } while (unaff_RBX != (longlong *)0x0);
  *(undefined8 *)(unaff_RSI + 0x18) = 0;
  *(undefined8 *)(unaff_RSI + 0x20) = 0;
  *(undefined8 *)(unaff_RSI + 0x10) = 0;
  *(undefined8 *)(unaff_RSI + 8) = 0;
  CPlex::FreeDataChain(*(CPlex **)(unaff_RSI + 0x28));
  *(undefined8 *)(unaff_RSI + 0x28) = 0;
  return;
}

/* ---- FUNC 00004981 FUN_180004981 (42 bytes) ---- */

void FUN_180004981(void)

{
  longlong unaff_RSI;
  
  *(undefined8 *)(unaff_RSI + 0x18) = 0;
  *(undefined8 *)(unaff_RSI + 0x20) = 0;
  *(undefined8 *)(unaff_RSI + 0x10) = 0;
  *(undefined8 *)(unaff_RSI + 8) = 0;
  CPlex::FreeDataChain(*(CPlex **)(unaff_RSI + 0x28));
  *(undefined8 *)(unaff_RSI + 0x28) = 0;
  return;
}

/* ---- FUNC 000049B0 FUN_1800049b0 (21 bytes) ---- */

void FUN_1800049b0(longlong param_1)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this;
  ulonglong uVar1;
  uint uVar2;
  
  uVar1 = 0;
  if (*(longlong *)(param_1 + 8) != 0) {
    if (*(int *)(param_1 + 0x10) != 0) {
      do {
        for (this = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
                     (*(longlong *)(param_1 + 8) + uVar1 * 8);
            this != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
            this = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)(this + 0x10))
        {
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(this);
        }
        uVar2 = (int)uVar1 + 1;
        uVar1 = (ulonglong)uVar2;
      } while (uVar2 < *(uint *)(param_1 + 0x10));
    }
    operator_delete__(*(void **)(param_1 + 8));
    *(undefined8 *)(param_1 + 8) = 0;
  }
  *(undefined8 *)(param_1 + 0x18) = 0;
  *(undefined8 *)(param_1 + 0x20) = 0;
  CPlex::FreeDataChain(*(CPlex **)(param_1 + 0x28));
  *(undefined8 *)(param_1 + 0x28) = 0;
  return;
}

/* ---- FUNC 000049C5 FUN_1800049c5 (12 bytes) ---- */

void FUN_1800049c5(longlong param_1)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this;
  ulonglong unaff_RBP;
  uint uVar1;
  ulonglong uVar2;
  longlong unaff_RDI;
  
  uVar2 = unaff_RBP & 0xffffffff;
  if ((uint)unaff_RBP < *(uint *)(param_1 + 0x10)) {
    do {
      for (this = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
                   (*(longlong *)(unaff_RDI + 8) + uVar2 * 8);
          this != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
          this = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)(this + 0x10)) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(this);
      }
      uVar1 = (int)uVar2 + 1;
      uVar2 = (ulonglong)uVar1;
    } while (uVar1 < *(uint *)(unaff_RDI + 0x10));
  }
  operator_delete__(*(void **)(unaff_RDI + 8));
  *(ulonglong *)(unaff_RDI + 8) = unaff_RBP;
  *(ulonglong *)(unaff_RDI + 0x18) = unaff_RBP;
  *(ulonglong *)(unaff_RDI + 0x20) = unaff_RBP;
  CPlex::FreeDataChain(*(CPlex **)(unaff_RDI + 0x28));
  *(ulonglong *)(unaff_RDI + 0x28) = unaff_RBP;
  return;
}

/* ---- FUNC 000049D1 FUN_1800049d1 (61 bytes) ---- */

void FUN_1800049d1(void)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this;
  undefined8 unaff_RBP;
  uint unaff_ESI;
  longlong unaff_RDI;
  
  do {
    for (this = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
                 (*(longlong *)(unaff_RDI + 8) + (ulonglong)unaff_ESI * 8);
        this != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
        this = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)(this + 0x10)) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(this);
    }
    unaff_ESI = unaff_ESI + 1;
  } while (unaff_ESI < *(uint *)(unaff_RDI + 0x10));
  operator_delete__(*(void **)(unaff_RDI + 8));
  *(undefined8 *)(unaff_RDI + 8) = unaff_RBP;
  *(undefined8 *)(unaff_RDI + 0x18) = unaff_RBP;
  *(undefined8 *)(unaff_RDI + 0x20) = unaff_RBP;
  CPlex::FreeDataChain(*(CPlex **)(unaff_RDI + 0x28));
  *(undefined8 *)(unaff_RDI + 0x28) = unaff_RBP;
  return;
}

/* ---- FUNC 00004A0E FUN_180004a0e (18 bytes) ---- */

void FUN_180004a0e(void)

{
  undefined8 unaff_RBP;
  longlong unaff_RDI;
  
  operator_delete__(*(void **)(unaff_RDI + 8));
  *(undefined8 *)(unaff_RDI + 8) = unaff_RBP;
  *(undefined8 *)(unaff_RDI + 0x18) = unaff_RBP;
  *(undefined8 *)(unaff_RDI + 0x20) = unaff_RBP;
  CPlex::FreeDataChain(*(CPlex **)(unaff_RDI + 0x28));
  *(undefined8 *)(unaff_RDI + 0x28) = unaff_RBP;
  return;
}

/* ---- FUNC 00004A20 FUN_180004a20 (32 bytes) ---- */

void FUN_180004a20(void)

{
  undefined8 unaff_RBP;
  longlong unaff_RDI;
  
  *(undefined8 *)(unaff_RDI + 0x18) = unaff_RBP;
  *(undefined8 *)(unaff_RDI + 0x20) = unaff_RBP;
  CPlex::FreeDataChain(*(CPlex **)(unaff_RDI + 0x28));
  *(undefined8 *)(unaff_RDI + 0x28) = unaff_RBP;
  return;
}

/* ---- FUNC 00004A40 FUN_180004a40 (165 bytes) ---- */

void FUN_180004a40(undefined8 *param_1)

{
  int iVar1;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar2;
  longlong lVar3;
  
  iVar1 = *(int *)(param_1 + 3);
  *param_1 = 0;
  if (0 < (longlong)iVar1) {
    lVar3 = 0;
    do {
      if ((lVar3 < 0) || ((longlong)param_1[3] <= lVar3)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      pCVar2 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
                (param_1[2] + lVar3 * 8);
      if (pCVar2 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
        FUN_180001ce0(pCVar2);
        operator_delete(pCVar2);
      }
      lVar3 = lVar3 + 1;
    } while (lVar3 < iVar1);
  }
  CPtrArray::SetSize((CPtrArray *)(param_1 + 1),0,-1);
  if ((longlong *)param_1[6] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[6] + 0x10))();
    param_1[6] = 0;
  }
  return;
}

/* ---- FUNC 00004AF0 FUN_180004af0 (208 bytes) ---- */

void FUN_180004af0(longlong param_1,
                  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_2)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar1;
  int iVar2;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar3;
  ulonglong uVar4;
  uint uVar5;
  ulonglong uVar6;
  longlong lVar7;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res8 [8];
  
  uVar4 = 0;
  lVar7 = *(longlong *)(param_1 + 0x18);
  uVar6 = uVar4;
  if (0 < lVar7) {
    do {
      if (((longlong)uVar4 < 0) || (lVar7 <= (longlong)uVar4)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      pCVar1 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
                (*(longlong *)(param_1 + 0x10) + uVar4 * 8);
      pCVar3 = FUN_1800040d0((longlong)pCVar1,local_res8);
      iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                        (param_2,*(char **)pCVar3);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res8);
      if (iVar2 == 0) {
        CPtrArray::RemoveAt((CPtrArray *)(param_1 + 8),(longlong)(int)uVar6,1);
        if (pCVar1 == (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
          return;
        }
        FUN_180001ce0(pCVar1);
        operator_delete(pCVar1);
        return;
      }
      uVar5 = (int)uVar6 + 1;
      uVar4 = uVar4 + 1;
      lVar7 = *(longlong *)(param_1 + 0x18);
      uVar6 = (ulonglong)uVar5;
    } while ((int)uVar5 < lVar7);
  }
  return;
}

/* ---- FUNC 00004BD0 FUN_180004bd0 (113 bytes) ---- */

void FUN_180004bd0(longlong param_1,longlong *param_2)

{
  char *pcVar1;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res18 [16];
  
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res18);
  pcVar1 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)local_res18,0x40);
  FUN_180003e00(param_2,pcVar1,0x3f);
  ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)local_res18,-1);
  FUN_180004af0(param_1,local_res18);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res18);
  return;
}

/* ---- FUNC 00004C50 FUN_180004c50 (24 bytes) ---- */

void FUN_180004c50(longlong param_1)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  
  lVar2 = *(longlong *)(param_1 + 0x18);
  uVar3 = 0;
  uVar4 = uVar3;
  if (0 < lVar2) {
    do {
      if (((longlong)uVar3 < 0) || (lVar2 <= (longlong)uVar3)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      pCVar1 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
                (*(longlong *)(param_1 + 0x10) + uVar3 * 8);
      if ((pCVar1 == (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) ||
         (*(int *)(pCVar1 + 0x3c) != 0)) {
        uVar4 = (ulonglong)((int)uVar4 + 1);
        uVar3 = uVar3 + 1;
      }
      else {
        FUN_180001ce0(pCVar1);
        operator_delete(pCVar1);
        CPtrArray::RemoveAt((CPtrArray *)(param_1 + 8),(longlong)(int)uVar4,1);
      }
      lVar2 = *(longlong *)(param_1 + 0x18);
    } while ((int)uVar4 < lVar2);
  }
  return;
}

/* ---- FUNC 00004C68 FUN_180004c68 (126 bytes) ---- */

void FUN_180004c68(undefined8 param_1,longlong param_2)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar1;
  ulonglong uVar2;
  longlong unaff_RBP;
  uint unaff_ESI;
  
  uVar2 = (ulonglong)unaff_ESI;
  do {
    if (((longlong)uVar2 < 0) || (param_2 <= (longlong)uVar2)) {
                    /* WARNING: Subroutine does not return */
      AfxThrowInvalidArgException();
    }
    pCVar1 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
              (*(longlong *)(unaff_RBP + 0x10) + uVar2 * 8);
    if ((pCVar1 == (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) ||
       (*(int *)(pCVar1 + 0x3c) != 0)) {
      unaff_ESI = unaff_ESI + 1;
      uVar2 = uVar2 + 1;
    }
    else {
      FUN_180001ce0(pCVar1);
      operator_delete(pCVar1);
      CPtrArray::RemoveAt((CPtrArray *)(unaff_RBP + 8),(longlong)(int)unaff_ESI,1);
    }
    param_2 = *(longlong *)(unaff_RBP + 0x18);
  } while ((int)unaff_ESI < param_2);
  return;
}

/* ---- FUNC 00004CE6 FUN_180004ce6 (11 bytes) ---- */

void FUN_180004ce6(void)

{
  return;
}

/* ---- FUNC 00004CF1 AfxThrowInvalidArgException (5 bytes) ---- */

void __cdecl AfxThrowInvalidArgException(void)

{
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 00004D00 FUN_180004d00 (31 bytes) ---- */

void FUN_180004d00(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  uint uVar5;
  ulonglong uVar6;
  
  lVar1 = *(longlong *)(param_1 + 0x18);
  uVar4 = 0;
  uVar6 = uVar4;
  if (0 < lVar1) {
    do {
      if (((longlong)uVar4 < 0) || (lVar1 <= (longlong)uVar4)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x10) + uVar4 * 8);
      lVar3 = FUN_180003f70(lVar2);
      if (param_2 == lVar3) {
        FUN_180004d90(lVar2);
        return;
      }
      uVar5 = (int)uVar6 + 1;
      uVar4 = uVar4 + 1;
      uVar6 = (ulonglong)uVar5;
    } while ((int)uVar5 < lVar1);
  }
  return;
}

/* ---- FUNC 00004D1F FUN_180004d1f (101 bytes) ---- */

void FUN_180004d1f(void)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  longlong unaff_RSI;
  uint unaff_EDI;
  longlong unaff_R14;
  longlong unaff_R15;
  
  uVar3 = (ulonglong)unaff_EDI;
  do {
    if (((longlong)uVar3 < 0) || (unaff_RSI <= (longlong)uVar3)) {
                    /* WARNING: Subroutine does not return */
      AfxThrowInvalidArgException();
    }
    lVar1 = *(longlong *)(*(longlong *)(unaff_R14 + 0x10) + uVar3 * 8);
    lVar2 = FUN_180003f70(lVar1);
    if (unaff_R15 == lVar2) {
      FUN_180004d90(lVar1);
      return;
    }
    unaff_EDI = unaff_EDI + 1;
    uVar3 = uVar3 + 1;
  } while ((int)unaff_EDI < unaff_RSI);
  return;
}

/* ---- FUNC 00004D66 FUN_180004d66 (15 bytes) ---- */

void FUN_180004d66(void)

{
  return;
}

/* ---- FUNC 00004D75 FUN_180004d75 (10 bytes) ---- */

void FUN_180004d75(void)

{
  longlong unaff_RBP;
  
  FUN_180004d90(unaff_RBP);
  return;
}

/* ---- FUNC 00004D90 FUN_180004d90 (103 bytes) ---- */

void FUN_180004d90(longlong param_1)

{
  CSimpleStringT<char,1> *this;
  longlong *plVar1;
  char *pcVar2;
  
  plVar1 = *(longlong **)(param_1 + 0x30);
  this = (CSimpleStringT<char,1> *)(param_1 + 0x10);
  if (plVar1 != (longlong *)0x0) {
    pcVar2 = ATL::CSimpleStringT<char,1>::GetBuffer(this,0x40);
    FUN_180003e00(plVar1,pcVar2,0x3f);
                    /* WARNING: Could not recover jumptable at 0x000180004dd8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    ATL::CSimpleStringT<char,1>::ReleaseBuffer(this,-1);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000180004df0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)this,"");
  return;
}

/* ---- FUNC 00004E00 FUN_180004e00 (3845 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180004e00(CApwnBlockUsage *param_1,int *param_2,HWND param_3)

{
  char cVar1;
  longlong lVar2;
  undefined8 *puVar3;
  longlong *plVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar12;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar13;
  wchar_t *bstrString;
  IAUserModelLibrary *pIVar14;
  char *pcVar15;
  undefined7 extraout_var;
  __POSITION *p_Var16;
  INT_PTR IVar17;
  undefined8 uVar18;
  IAUserModelLibrary *pIVar19;
  undefined7 extraout_var_00;
  CSimpleStringT<char,1> *pCVar20;
  IAUserModelLibrary *pIVar21;
  undefined1 auStackY_498 [32];
  char *local_448;
  char *local_440;
  char *local_438;
  char *local_430;
  int local_428;
  int local_424;
  uint local_420;
  IAUserModelLibrary *local_418;
  CSimpleStringT<char,1> *local_410;
  longlong *local_408;
  IAUserModelLibrary *local_400;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_3f8;
  char *local_3f0;
  longlong *local_3e8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_3e0 [8];
  int local_3d8;
  int local_3d4;
  HWND local_3d0;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_3c8 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_3c0 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_3b8 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_3b0 [8];
  longlong *local_3a8;
  longlong *local_3a0;
  longlong *local_398;
  IAUserModelLibrary *local_390;
  longlong *local_388;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_380 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_378 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_370 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_368 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_360 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_358 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_350 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_348 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_340 [8];
  longlong *local_338;
  undefined8 local_330 [3];
  longlong *local_318;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_2f8;
  CStringList local_2f0 [24];
  int local_2d8;
  CStringList local_2b8 [56];
  char local_280 [8];
  char local_278 [4];
  char local_274 [12];
  char local_268 [272];
  char local_158 [272];
  ulonglong local_48;
  
  local_48 = DAT_1800791f8 ^ (ulonglong)auStackY_498;
  iVar10 = 0;
  local_3d0 = param_3;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_430);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_3e0);
  iVar8 = *param_2;
  pIVar21 = (IAUserModelLibrary *)(param_2 + 1);
  local_3d4 = iVar8;
  (**(code **)**(undefined8 **)(param_1 + 0x30))
            (*(undefined8 **)(param_1 + 0x30),&DAT_180056200,&local_3a0);
  local_424 = CApwnLibraries::CountLibraries(*(CApwnLibraries **)param_1);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_438);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_448);
  CMap<>(local_330,10);
  CStringList::CStringList(local_2f0,10);
  CStringList::CStringList(local_2b8,10);
  pIVar14 = local_390;
  if (0 < iVar8) {
    do {
      local_3e8 = (longlong *)0x0;
      bVar6 = false;
      bVar7 = false;
      local_2f8 = operator_new(0x40);
      if (local_2f8 == (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
        pCVar12 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
      }
      else {
        pCVar12 = FUN_180001b40(local_2f8);
      }
      local_410 = (CSimpleStringT<char,1> *)pCVar12;
      FUN_180005d10(pCVar12,(int *)pIVar21);
      iVar8 = FUN_180004220((longlong *)pCVar12);
      local_3d8 = iVar10 + 1;
      local_390 = pIVar21 + iVar8;
      pCVar13 = FUN_1800040d0((longlong)pCVar12,local_350);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_430,
                 (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                 pCVar13);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_350);
      iVar9 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Find
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_430
                         ,'.',0);
      if (iVar9 == -1) {
        (**(code **)(*local_3a0 + 0x28))(local_3a0,local_430,&local_3e8);
      }
      else {
        local_280[0] = s__Data_Blocks__1800535b8[0];
        local_280[1] = s__Data_Blocks__1800535b8[1];
        local_280[2] = s__Data_Blocks__1800535b8[2];
        local_280[3] = s__Data_Blocks__1800535b8[3];
        local_280[4] = s__Data_Blocks__1800535b8[4];
        local_280[5] = s__Data_Blocks__1800535b8[5];
        local_280[6] = s__Data_Blocks__1800535b8[6];
        local_280[7] = s__Data_Blocks__1800535b8[7];
        local_278[0] = s__Data_Blocks__1800535b8[8];
        local_278[1] = s__Data_Blocks__1800535b8[9];
        local_278[2] = s__Data_Blocks__1800535b8[10];
        local_278[3] = s__Data_Blocks__1800535b8[0xb];
        local_274[0] = s__Data_Blocks__1800535b8[0xc];
        local_274[1] = s__Data_Blocks__1800535b8[0xd];
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_408,
                   (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                   &local_430);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Insert
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_408,0,
                   local_280);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Replace
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_408,".",
                   local_280);
        iVar9 = (**(code **)**(undefined8 **)(param_1 + 0x30))
                          (*(undefined8 **)(param_1 + 0x30),&DAT_180056180,&local_3a8);
        bVar7 = bVar6;
        if (-1 < iVar9) {
          bstrString = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                       AllocSysString((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                       *)&local_408);
          (**(code **)(*local_3a8 + 0x110))(local_3a8,bstrString,&local_388);
          SysFreeString(bstrString);
          if (local_388 != (longlong *)0x0) {
            (**(code **)*local_388)(local_388,&DAT_1800561f0,&local_3e8);
            local_398 = (longlong *)0x0;
            if ((local_3e8 == (longlong *)0x0) ||
               (iVar9 = (**(code **)*local_3e8)(local_3e8,&DAT_180056180,&local_398), iVar9 < 0)) {
              bVar7 = true;
            }
            else {
              (**(code **)(*local_398 + 0x10))();
            }
            (**(code **)(*local_388 + 0x10))();
          }
          (**(code **)(*local_3a8 + 0x10))();
          pCVar12 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_410;
        }
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_408);
      }
      pIVar21 = pIVar21 + iVar8;
      iVar10 = iVar10 + 1;
      if (local_3e8 != (longlong *)0x0) {
        FUN_180007aa0((longlong)pCVar12,local_3e8);
        pCVar20 = local_410;
        if (bVar7) {
          FUN_180007b40((longlong)local_410,local_430);
        }
        (**(code **)*local_3e8)(local_3e8,&DAT_180056290,&local_338);
        CPtrArray::SetAtGrow((CPtrArray *)(param_1 + 8),*(__int64 *)(param_1 + 0x18),pCVar20);
        pCVar12 = FUN_180003f50((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                 *)pCVar20,local_348);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_448,
                   (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                   pCVar12);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_348);
        iVar8 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_448,"Aspen Split");
        if (iVar8 == 0) {
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_448,
                     "Conceptual Design");
        }
        pCVar12 = FUN_180004250((longlong)pCVar20,local_340);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_430,
                   (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                   pCVar12);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_340);
        pCVar12 = FUN_180003de0((longlong)pCVar20,local_380);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  (local_3e0,
                   (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                   pCVar12);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_380);
        local_420 = 0;
        iVar8 = 1;
        bVar7 = false;
        local_428 = 0;
        pIVar21 = (IAUserModelLibrary *)0x0;
        local_418 = (IAUserModelLibrary *)0x0;
        if (local_424 < 1) {
LAB_1800054ca:
          pIVar21 = local_418;
          iVar8 = local_428;
          uVar11 = CApwnLibraries::AddNewLibrary(*(CApwnLibraries **)param_1,local_448,1);
          if (uVar11 == 0) {
LAB_1800056a4:
            PostMainWndMessage(0x565,0,0);
            local_424 = CApwnLibraries::CountLibraries(*(CApwnLibraries **)param_1);
            pCVar20 = local_410;
            iVar8 = local_424;
            while (iVar8 = iVar8 + -1, -1 < iVar8) {
              pIVar14 = CApwnLibraries::GetLibrary(*(CApwnLibraries **)param_1,iVar8);
              lVar2 = *(longlong *)pIVar14;
              pcVar15 = ATL::CSimpleStringT<char,1>::GetBuffer
                                  ((CSimpleStringT<char,1> *)&local_438,0x40);
              (**(code **)(lVar2 + 0x38))(pIVar14,pcVar15);
              ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)&local_438,-1);
              iVar10 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                       CompareNoCase((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                      *)&local_438,local_430);
              pIVar21 = local_418;
              if (iVar10 == 0) {
                local_428 = 1;
                iVar10 = FUN_1800034e0(param_1,(longlong *)pIVar14,pCVar20);
                pIVar21 = local_418;
                if (iVar10 == 0) {
                  bVar7 = true;
                }
              }
            }
          }
          else {
            iVar10 = ApwnIsReservedDisplayName(local_448);
            if (iVar10 != 0) goto LAB_18000577c;
            p_Var16 = CStringList::Find(local_2b8,local_448,(__POSITION *)0x0);
            if (p_Var16 == (__POSITION *)0x0) {
              CStringList::AddTail
                        (local_2b8,
                         (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_448
                        );
              pcVar15 = (char *)(*DAT_180079fa0)(0x1e1);
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_3f0
                         ,pcVar15);
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_3f0
                         ,"\t");
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_3f0
                         ,(CSimpleStringT<char,1> *)&local_448);
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_3f0
                         ,"\n");
              pcVar15 = (char *)(*DAT_180079fa0)(0x1e3);
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_3f0
                         ,pcVar15);
              iVar10 = STmsgbox2(local_3d0,local_3f0,"Aspen Plus",0x34);
              if (iVar10 == 6) {
                pcVar15 = local_448;
                do {
                  cVar1 = *pcVar15;
                  pcVar15[(longlong)(local_268 + -(longlong)local_448)] = cVar1;
                  pcVar15 = pcVar15 + 1;
                } while (cVar1 != '\0');
                IVar17 = MMDriveDialog2("FileOpenDialog",8,local_268,1);
                if ((int)IVar17 != 0) {
                  pCVar12 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                            CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                      (local_368,local_268);
                  bVar6 = CApwnLibraries::InsertLibrary
                                    (*(CApwnLibraries **)param_1,pCVar12,9999,local_158,0x104,1);
                  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_368);
                  uVar11 = bVar6 ^ 1;
                  if (uVar11 == 0) {
                    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                               &local_448,local_158);
                    uVar11 = CApwnLibraries::AddNewLibrary(*(CApwnLibraries **)param_1,local_448,1);
                  }
                }
              }
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_3f0
                        );
              local_428 = iVar8;
              if (uVar11 == 0) goto LAB_1800056a4;
            }
          }
          if ((local_428 == 0) &&
             (p_Var16 = CStringList::Find(local_2f0,local_430,(__POSITION *)0x0),
             p_Var16 == (__POSITION *)0x0)) {
            CStringList::AddTail
                      (local_2f0,
                       (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_430);
          }
        }
        else {
          do {
            pIVar14 = CApwnLibraries::GetLibrary(*(CApwnLibraries **)param_1,local_420);
            lVar2 = *(longlong *)pIVar14;
            pcVar15 = ATL::CSimpleStringT<char,1>::GetBuffer
                                ((CSimpleStringT<char,1> *)&local_438,0x40);
            (**(code **)(lVar2 + 0x38))(pIVar14,pcVar15);
            ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)&local_438,-1);
            iVar10 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                               ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                &local_438,"Built-In");
            if (iVar10 == 0) {
              if (iVar8 == 0) {
                iVar10 = FUN_1800034e0(param_1,(longlong *)pIVar14,pCVar20);
                if (iVar10 == 0) {
                  bVar7 = true;
                }
              }
              else {
                (**(code **)(*(longlong *)pIVar14 + 8))(pIVar14);
                pIVar21 = pIVar14;
              }
            }
            iVar10 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                     CompareNoCase((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                   &local_448,local_438);
            uVar11 = local_420;
            if (iVar10 == 0) {
              local_428 = 1;
              iVar10 = FUN_1800034e0(param_1,(longlong *)pIVar14,pCVar20);
              if (iVar10 == 0) {
                uVar11 = local_420 + local_424;
                bVar7 = true;
              }
              else {
                p_Var16 = CStringList::Find(local_2f0,local_448,(__POSITION *)0x0);
                if (p_Var16 == (__POSITION *)0x0) {
                  uVar18 = FUN_180004320((longlong)local_330,local_448,&local_400);
                  if ((int)uVar18 == 0) {
                    pIVar19 = operator_new(0x38);
                    local_418 = pIVar19;
                    if (pIVar19 == (IAUserModelLibrary *)0x0) {
                      local_400 = (IAUserModelLibrary *)0x0;
                    }
                    else {
                      *(longlong *)pIVar19 = 0;
                      *(longlong *)(pIVar19 + 8) = 0;
                      *(longlong *)(pIVar19 + 0x10) = 0;
                      *(longlong *)(pIVar19 + 0x18) = 0;
                      *(longlong *)(pIVar19 + 0x20) = 0;
                      *(longlong *)(pIVar19 + 0x28) = 0;
                      *(longlong *)(pIVar19 + 0x30) = 0;
                      FUN_180001730((undefined8 *)pIVar19,10);
                      *(undefined ***)pIVar19 = ModelTypeRefList::vftable;
                      local_400 = pIVar19;
                    }
                  }
                  pIVar19 = local_400;
                  for (puVar3 = *(undefined8 **)(local_400 + 8); puVar3 != (undefined8 *)0x0;
                      puVar3 = (undefined8 *)*puVar3) {
                    bVar6 = FUN_180001540((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                           *)(puVar3 + 2),&local_430);
                    if ((int)CONCAT71(extraout_var,bVar6) != 0) {
                      if (puVar3 != (undefined8 *)0x0) goto LAB_1800053e3;
                      break;
                    }
                  }
                  local_418 = (IAUserModelLibrary *)local_378;
                  pCVar12 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                            CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                      (local_378,
                                       (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                        *)local_3e0);
                  local_3f8 = pCVar12;
                  pCVar13 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                            CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                      (local_370,
                                       (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                        *)&local_430);
                  local_418 = (IAUserModelLibrary *)pCVar13;
                  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_3b8);
                  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_3b0);
                  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                            (local_3b8,
                             (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                              *)pCVar13);
                  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                            (local_3b0,
                             (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                              *)pCVar12);
                  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar13);
                  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar12);
                  FUN_180002d10((longlong)pIVar19,
                                (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                 *)local_3b8);
                  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_3b0);
                  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_3b8);
                  pCVar12 = FUN_180001e30((longlong)local_330,local_448);
                  *(IAUserModelLibrary **)pCVar12 = pIVar19;
                  pCVar20 = local_410;
                }
LAB_1800053e3:
                iVar10 = local_424;
                local_3f8 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            ((ulonglong)local_3f8 & 0xffffffff00000000);
                iVar8 = 0;
                if (pIVar21 == (IAUserModelLibrary *)0x0) {
                  iVar8 = 0;
                  do {
                    pIVar14 = CApwnLibraries::GetLibrary(*(CApwnLibraries **)param_1,iVar8);
                    lVar2 = *(longlong *)pIVar14;
                    pcVar15 = ATL::CSimpleStringT<char,1>::GetBuffer
                                        ((CSimpleStringT<char,1> *)&local_438,0x40);
                    (**(code **)(lVar2 + 0x38))(pIVar14,pcVar15);
                    ATL::CSimpleStringT<char,1>::ReleaseBuffer
                              ((CSimpleStringT<char,1> *)&local_438,-1);
                    iVar9 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                            Compare((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
                                    )&local_438,"Built-In");
                    if (iVar9 == 0) {
                      (**(code **)(*(longlong *)pIVar14 + 8))(pIVar14);
                      pIVar21 = pIVar14;
                    }
                    iVar8 = iVar8 + 1;
                  } while (iVar8 < iVar10);
                  pCVar20 = local_410;
                  iVar8 = (int)local_3f8;
                  if (pIVar21 != (IAUserModelLibrary *)0x0) goto LAB_180005476;
                }
                else {
LAB_180005476:
                  iVar10 = FUN_1800034e0(param_1,(longlong *)pIVar21,pCVar20);
                  if (iVar10 == 0) {
                    bVar7 = true;
                  }
                }
                uVar11 = local_420 + local_424;
              }
            }
            (**(code **)(*(longlong *)pIVar14 + 0x10))(pIVar14);
            local_420 = uVar11 + 1;
          } while ((int)local_420 < local_424);
          local_418 = pIVar21;
          if (local_428 == 0) goto LAB_1800054ca;
        }
LAB_18000577c:
        if (bVar7) {
LAB_1800059ae:
          if (pIVar21 != (IAUserModelLibrary *)0x0) {
            (**(code **)(*(longlong *)pIVar21 + 0x10))(pIVar21);
          }
        }
        else {
          if (pIVar21 != (IAUserModelLibrary *)0x0) {
LAB_180005840:
            p_Var16 = CStringList::Find(local_2f0,local_448,(__POSITION *)0x0);
            if (p_Var16 == (__POSITION *)0x0) {
              uVar18 = FUN_180004320((longlong)local_330,local_448,&local_400);
              if ((int)uVar18 == 0) {
                pIVar19 = operator_new(0x38);
                local_418 = pIVar19;
                if (pIVar19 == (IAUserModelLibrary *)0x0) {
                  local_400 = (IAUserModelLibrary *)0x0;
                }
                else {
                  *(longlong *)pIVar19 = 0;
                  *(longlong *)(pIVar19 + 8) = 0;
                  *(longlong *)(pIVar19 + 0x10) = 0;
                  *(longlong *)(pIVar19 + 0x18) = 0;
                  *(longlong *)(pIVar19 + 0x20) = 0;
                  *(longlong *)(pIVar19 + 0x28) = 0;
                  *(longlong *)(pIVar19 + 0x30) = 0;
                  FUN_180001730((undefined8 *)pIVar19,10);
                  *(undefined ***)pIVar19 = ModelTypeRefList::vftable;
                  local_400 = pIVar19;
                }
              }
              pIVar19 = local_400;
              for (puVar3 = *(undefined8 **)(local_400 + 8); puVar3 != (undefined8 *)0x0;
                  puVar3 = (undefined8 *)*puVar3) {
                bVar7 = FUN_180001540((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                       *)(puVar3 + 2),&local_430);
                if ((int)CONCAT71(extraout_var_00,bVar7) != 0) {
                  if (puVar3 != (undefined8 *)0x0) goto LAB_18000599f;
                  break;
                }
              }
              local_418 = (IAUserModelLibrary *)local_360;
              pCVar12 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                  (local_360,
                                   (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                    *)local_3e0);
              local_3f8 = pCVar12;
              pCVar13 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                  (local_358,
                                   (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                    *)&local_430);
              local_418 = (IAUserModelLibrary *)pCVar13;
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_3c8);
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_3c0);
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                        (local_3c8,
                         (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                          *)pCVar13);
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                        (local_3c0,
                         (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                          *)pCVar12);
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar13);
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar12);
              FUN_180002d10((longlong)pIVar19,
                            (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                             *)local_3c8);
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_3c0);
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_3c8);
              pCVar12 = FUN_180001e30((longlong)local_330,local_448);
              *(IAUserModelLibrary **)pCVar12 = pIVar19;
            }
LAB_18000599f:
            FUN_1800034e0(param_1,(longlong *)pIVar14,local_410);
            goto LAB_1800059ae;
          }
          iVar8 = CApwnLibraries::AddNewLibrary(*(CApwnLibraries **)param_1,"Built-In",0);
          if (iVar8 == 0) {
            PostMainWndMessage(0x565,0,0);
            local_424 = CApwnLibraries::CountLibraries(*(CApwnLibraries **)param_1);
            iVar8 = local_424 + -1;
            if (-1 < iVar8) {
              do {
                pIVar14 = CApwnLibraries::GetLibrary(*(CApwnLibraries **)param_1,iVar8);
                lVar2 = *(longlong *)pIVar14;
                pcVar15 = ATL::CSimpleStringT<char,1>::GetBuffer
                                    ((CSimpleStringT<char,1> *)&local_438,0x40);
                (**(code **)(lVar2 + 0x38))(pIVar14,pcVar15);
                ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)&local_438,-1);
                iVar10 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                                   ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
                                    )&local_438,"Built-In");
                if (iVar10 == 0) {
                  (**(code **)(*(longlong *)pIVar14 + 8))(pIVar14);
                  pIVar21 = pIVar14;
                }
                iVar8 = iVar8 + -1;
              } while (-1 < iVar8);
              if (pIVar21 != (IAUserModelLibrary *)0x0) goto LAB_180005840;
            }
          }
        }
        (**(code **)(*local_3e8 + 0x10))();
        (**(code **)(*local_338 + 0x10))();
        pIVar21 = local_390;
        iVar10 = local_3d8;
      }
    } while (iVar10 < local_3d4);
  }
  (**(code **)(*local_3a0 + 0x10))();
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_440);
  bVar7 = false;
  local_420 = 0;
  if (0 < local_2d8) {
    pcVar15 = (char *)(*DAT_180079fa0)(0x1e1);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_440,pcVar15);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_440,"\n");
  }
  local_420 = (uint)(0 < local_2d8);
  uVar11 = (uint)(0 < local_2d8);
  if ((int)local_318 != 0) {
    if (*(int *)(local_440 + -0x10) == 0) {
      pcVar15 = (char *)(*DAT_180079fa0)(0x1e1);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_440,pcVar15
                );
    }
    local_408 = (longlong *)-(ulonglong)(local_318 != (longlong *)0x0);
    bVar7 = false;
    while (local_318 != (longlong *)0x0) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_418);
      FUN_180004100((longlong)local_330,(longlong *)&local_408,
                    (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_418,
                    &local_400);
      pIVar21 = local_400;
      local_318 = local_408;
      if (local_400 != (IAUserModelLibrary *)0x0) {
        bVar6 = true;
        plVar4 = *(longlong **)(local_400 + 8);
        local_408 = plVar4;
        for (; plVar4 != (longlong *)0x0; plVar4 = (longlong *)*plVar4) {
          iVar8 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             (plVar4 + 3),"RATEFRAC");
          bVar5 = true;
          if ((iVar8 != 0) &&
             (iVar8 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                      CompareNoCase((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
                                    )(plVar4 + 3),"BATCHFRAC"), iVar8 != 0)) {
            if (bVar6) {
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_440
                         ,"\t\'");
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_440
                         ,(CSimpleStringT<char,1> *)&local_418);
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_440
                         ,"\' ");
              pcVar15 = (char *)(*DAT_180079fa0)(0x1e8);
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_440
                         ,pcVar15);
              bVar6 = false;
            }
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_440,
                       "\t\t");
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_440,
                       (CSimpleStringT<char,1> *)(plVar4 + 2));
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_440,
                       "\n");
            bVar5 = bVar7;
          }
          bVar7 = bVar5;
        }
        local_408 = (longlong *)0x0;
        (**(code **)(*(longlong *)pIVar21 + 8))(pIVar21,1);
        local_318 = (longlong *)0x0;
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_418);
      uVar11 = local_420;
    }
  }
  if ((*(int *)(local_440 + -0x10) != 0) || (bVar7)) {
    if (uVar11 != 0) {
      pcVar15 = (char *)(*DAT_180079fa0)(0x1e2);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_440,pcVar15
                );
    }
    if (bVar7) {
      if (*(int *)(local_440 + -0x10) == 0) {
        pcVar15 = (char *)(*DAT_180079fa0)(0x1e4);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_440,
                   pcVar15);
      }
      pcVar15 = (char *)(*DAT_180079fa0)(0x1e5);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_440,pcVar15
                );
    }
    STmsgbox2(local_3d0,local_440,"Aspen Plus",0x30);
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_440);
  CStringList::~CStringList(local_2b8);
  CStringList::~CStringList(local_2f0);
  FUN_180001c90(local_330);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_448);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_438);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_3e0);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_430);
  return;
}

/* ---- FUNC 00005D10 FUN_180005d10 (113 bytes) ---- */

void FUN_180005d10(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_1,
                  int *param_2)

{
  *(int *)(param_1 + 0x38) = param_2[4];
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            (param_1 + 0x10,(char *)((longlong)param_2 + (longlong)*param_2 + 0x14));
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            (param_1 + 8,(char *)((longlong)param_2 + (longlong)param_2[1] + 0x14));
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            (param_1,(char *)((longlong)param_2 + (longlong)param_2[2] + 0x14));
                    /* WARNING: Could not recover jumptable at 0x000180005d7a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            (param_1 + 0x18,(char *)((longlong)param_2 + (longlong)param_2[3] + 0x14));
  return;
}

/* ---- FUNC 00005D90 FUN_180005d90 (4357 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180005d90(CApwnBlockUsage *param_1,longlong *param_2,HWND param_3,char *param_4,
                  CMapStringToString *param_5)

{
  char cVar1;
  char cVar2;
  undefined8 *puVar3;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar4;
  bool bVar5;
  CApwnBlockUsage *pCVar6;
  CMapStringToString *this;
  bool bVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  ulonglong uVar11;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar12;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar13;
  IAUserModelLibrary *pIVar14;
  char *pcVar15;
  IAUserModelLibrary *pIVar16;
  undefined7 extraout_var;
  __POSITION *p_Var17;
  INT_PTR IVar18;
  IAUserModelLibrary *pIVar19;
  IAUserModelLibrary *pIVar20;
  undefined8 uVar21;
  undefined7 extraout_var_00;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar22;
  longlong *plVar23;
  longlong lVar24;
  uint uVar25;
  CApwnBlockUsage *pCVar26;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar27;
  uint uVar28;
  ulonglong uVar29;
  undefined1 auStackY_5a8 [32];
  char *local_558;
  char *local_550;
  uint local_548;
  IAUserModelLibrary *local_540;
  uint local_538;
  char *local_530;
  int local_528;
  char *local_520;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_518;
  uint local_510;
  longlong *local_508;
  int local_500;
  int local_4fc;
  IAUserModelLibrary *local_4f8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_4f0;
  CApwnBlockUsage *local_4e8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_4e0 [8];
  uint local_4d8;
  HWND local_4d0;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_4c8 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_4c0 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_4b8 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_4b0 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_4a8 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_4a0 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_498 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_490 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_488 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_480 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_478 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_470 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_468 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_460 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_458 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_450 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_448 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_440 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_438 [8];
  longlong *local_430;
  char *local_428;
  CMapStringToString *local_420;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_418 [8];
  undefined8 local_410 [3];
  longlong *local_3f8;
  CStringList local_3d8 [8];
  undefined8 *local_3d0;
  int local_3c0;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_3a0;
  CStringList local_398 [64];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_358 [64];
  char local_318 [160];
  char local_278 [272];
  char local_168 [272];
  ulonglong local_58;
  
  local_58 = DAT_1800791f8 ^ (ulonglong)auStackY_5a8;
  local_420 = param_5;
  uVar25 = 0;
  local_548 = 0;
  local_538 = 0;
  local_4e8 = param_1;
  local_4d0 = param_3;
  local_430 = param_2;
  local_428 = param_4;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_520);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_4e0);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_530);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_558);
  local_4fc = 0;
  CStringList::CStringList(local_3d8,10);
  CStringList::CStringList(local_398,10);
  CMap<>(local_410,10);
  do {
    FUN_180007ca0(param_2,local_318);
  } while (local_318[0] == ';');
  sscanf(local_318,"%d",&local_500);
  uVar11 = FUN_1800240b0();
  if ((int)uVar11 == 2) {
    FUN_180001b40(local_358);
    if (0 < local_500) {
      do {
        FUN_180006ea0(local_358,param_2);
        uVar25 = uVar25 + 1;
      } while ((int)uVar25 < local_500);
    }
    FUN_180001ce0(local_358);
  }
  else {
    local_528 = CApwnLibraries::CountLibraries(*(CApwnLibraries **)param_1);
    uVar28 = uVar25;
    if (0 < local_500) {
LAB_180005ef5:
      pIVar19 = (IAUserModelLibrary *)0x0;
      local_3a0 = operator_new(0x40);
      pCVar12 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)pIVar19;
      if (local_3a0 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
        pCVar12 = FUN_180001b40(local_3a0);
      }
      local_518 = pCVar12;
      FUN_180006ea0(pCVar12,param_2);
      this = local_420;
      local_4d8 = uVar28 + 1;
      if (local_420 == (CMapStringToString *)0x0) {
LAB_180005f76:
        bVar7 = false;
      }
      else {
        pCVar13 = FUN_1800040d0((longlong)pCVar12,local_418);
        uVar25 = uVar25 | 1;
        local_548 = uVar25;
        local_538 = uVar25;
        iVar8 = CMapStringToString::Lookup
                          (this,*(char **)pCVar13,
                           (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_520);
        if (iVar8 == 0) goto LAB_180005f76;
        bVar7 = true;
      }
      if ((uVar25 & 1) != 0) {
        local_548 = uVar25 & 0xfffffffe;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_418);
      }
      if (bVar7) {
LAB_180005fcf:
        FUN_180007b40((longlong)pCVar12,local_520);
      }
      else if (param_4 != (char *)0x0) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_520,
                   param_4);
        pCVar13 = FUN_1800040d0((longlong)pCVar12,local_4a8);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_520,
                   (CSimpleStringT<char,1> *)pCVar13);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_4a8);
        goto LAB_180005fcf;
      }
      pCVar13 = FUN_180003f50((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                               *)pCVar12,local_4a0);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_558,
                 (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                 pCVar13);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_4a0);
      pCVar13 = FUN_180004250((longlong)pCVar12,local_498);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_520,
                 (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                 pCVar13);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_498);
      pCVar12 = FUN_180003de0((longlong)pCVar12,local_490);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                (local_4e0,
                 (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                 pCVar12);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_490);
      local_510 = 0;
      local_540 = (IAUserModelLibrary *)0x0;
      iVar8 = 1;
      local_538 = 0;
      pCVar26 = local_4e8;
      pIVar14 = pIVar19;
      pIVar20 = pIVar19;
      if (local_528 < 1) {
LAB_18000639c:
        pCVar26 = local_4e8;
        uVar25 = local_538;
        pIVar19 = local_540;
        iVar9 = (int)pIVar20;
        CApwnLibraries::FindAPMFileAndRegisterLibrary(*(CApwnLibraries **)local_4e8,local_558);
        iVar8 = CApwnLibraries::AddNewLibrary(*(CApwnLibraries **)pCVar26,local_558,1);
        if (iVar8 == 0) {
LAB_1800065c5:
          local_528 = CApwnLibraries::CountLibraries(*(CApwnLibraries **)pCVar26);
          pCVar12 = local_518;
          iVar8 = local_528;
          while (iVar8 = iVar8 + -1, -1 < iVar8) {
            pIVar19 = CApwnLibraries::GetLibrary(*(CApwnLibraries **)pCVar26,iVar8);
            lVar24 = *(longlong *)pIVar19;
            pcVar15 = ATL::CSimpleStringT<char,1>::GetBuffer
                                ((CSimpleStringT<char,1> *)&local_530,0x40);
            (**(code **)(lVar24 + 0x38))(pIVar19,pcVar15);
            ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)&local_530,-1);
            iVar9 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                    CompareNoCase((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                  &local_558,local_530);
            if (iVar9 == 0) {
              iVar9 = FUN_1800034e0(pCVar26,(longlong *)pIVar19,(CSimpleStringT<char,1> *)pCVar12);
              uVar25 = 1;
              if (iVar9 == 0) {
                pIVar20 = (IAUserModelLibrary *)0x1;
                uVar25 = 1;
              }
            }
            iVar9 = (int)pIVar20;
            pIVar19 = local_540;
          }
        }
        else {
          iVar10 = ApwnIsReservedDisplayName(local_558);
          if (iVar10 != 0) goto LAB_18000668f;
          p_Var17 = CStringList::Find(local_398,local_558,(__POSITION *)0x0);
          if (p_Var17 == (__POSITION *)0x0) {
            CStringList::AddTail
                      (local_398,
                       (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_558);
            iVar10 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                     CompareNoCase((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                   &local_520,"ConSep");
            if ((iVar10 == 0) &&
               (iVar10 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                         CompareNoCase(local_4e0,"USER2"), iVar10 == 0)) {
              local_4fc = 1;
            }
            else {
              pcVar15 = (char *)(*DAT_180079fa0)(0x1e1);
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_508
                         ,pcVar15);
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_508
                         ,"\t");
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_508
                         ,(CSimpleStringT<char,1> *)&local_558);
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_508
                         ,"\n");
              pcVar15 = (char *)(*DAT_180079fa0)(0x1e3);
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_508
                         ,pcVar15);
              iVar10 = STmsgbox2(local_4d0,(char *)local_508,"Aspen Plus",0x34);
              if (iVar10 == 6) {
                pcVar15 = local_558;
                do {
                  cVar1 = *pcVar15;
                  pcVar15[(longlong)(local_278 + -(longlong)local_558)] = cVar1;
                  pcVar15 = pcVar15 + 1;
                } while (cVar1 != '\0');
                IVar18 = MMDriveDialog2("FileOpenDialog",8,local_278,1);
                if ((int)IVar18 != 0) {
                  pCVar12 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                            CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                      (local_478,local_278);
                  bVar7 = CApwnLibraries::InsertLibrary
                                    (*(CApwnLibraries **)pCVar26,pCVar12,9999,local_168,0x104,1);
                  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_478);
                  if (bVar7) {
                    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                               &local_558,local_168);
                    iVar8 = CApwnLibraries::AddNewLibrary(*(CApwnLibraries **)pCVar26,local_558,1);
                  }
                }
              }
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_508
                        );
              if (iVar8 == 0) goto LAB_1800065c5;
            }
          }
        }
        if ((uVar25 == 0) &&
           (p_Var17 = CStringList::Find(local_3d8,local_558,(__POSITION *)0x0),
           p_Var17 == (__POSITION *)0x0)) {
          CStringList::AddTail
                    (local_3d8,
                     (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_558);
        }
      }
      else {
        do {
          uVar25 = (uint)pIVar14;
          pIVar14 = CApwnLibraries::GetLibrary(*(CApwnLibraries **)pCVar26,uVar25);
          lVar24 = *(longlong *)pIVar14;
          pcVar15 = ATL::CSimpleStringT<char,1>::GetBuffer
                              ((CSimpleStringT<char,1> *)&local_530,0x40);
          (**(code **)(lVar24 + 0x38))(pIVar14,pcVar15);
          ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)&local_530,-1);
          iVar9 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &local_530,"Built-In");
          pCVar12 = local_518;
          if (iVar9 == 0) {
            if (iVar8 == 0) {
              iVar9 = FUN_1800034e0(pCVar26,(longlong *)pIVar14,(CSimpleStringT<char,1> *)local_518)
              ;
              if (iVar9 == 0) {
                pIVar20 = (IAUserModelLibrary *)0x1;
              }
            }
            else {
              (**(code **)(*(longlong *)pIVar14 + 8))(pIVar14);
              pCVar12 = local_518;
              pIVar19 = pIVar14;
            }
          }
          iVar9 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &local_558,local_530);
          if (iVar9 == 0) {
            local_538 = 1;
            iVar9 = FUN_1800034e0(pCVar26,(longlong *)pIVar14,(CSimpleStringT<char,1> *)pCVar12);
            if (iVar9 == 0) {
              pIVar20 = (IAUserModelLibrary *)0x1;
            }
            else {
              p_Var17 = CStringList::Find(local_3d8,local_558,(__POSITION *)0x0);
              if (p_Var17 == (__POSITION *)0x0) {
                uVar21 = FUN_180004320((longlong)local_410,local_558,&local_4f8);
                if ((int)uVar21 == 0) {
                  pIVar16 = operator_new(0x38);
                  local_540 = pIVar16;
                  if (pIVar16 == (IAUserModelLibrary *)0x0) {
                    local_4f8 = (IAUserModelLibrary *)0x0;
                  }
                  else {
                    *(longlong *)pIVar16 = 0;
                    *(longlong *)(pIVar16 + 8) = 0;
                    *(longlong *)(pIVar16 + 0x10) = 0;
                    *(longlong *)(pIVar16 + 0x18) = 0;
                    *(longlong *)(pIVar16 + 0x20) = 0;
                    *(longlong *)(pIVar16 + 0x28) = 0;
                    *(longlong *)(pIVar16 + 0x30) = 0;
                    FUN_180001730((undefined8 *)pIVar16,10);
                    *(undefined ***)pIVar16 = ModelTypeRefList::vftable;
                    local_4f8 = pIVar16;
                  }
                }
                pIVar16 = local_4f8;
                for (puVar3 = *(undefined8 **)(local_4f8 + 8); puVar3 != (undefined8 *)0x0;
                    puVar3 = (undefined8 *)*puVar3) {
                  bVar7 = FUN_180001540((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                         *)(puVar3 + 2),&local_520);
                  pCVar12 = local_518;
                  if ((int)CONCAT71(extraout_var,bVar7) != 0) goto LAB_1800062b3;
                }
                local_540 = (IAUserModelLibrary *)local_488;
                pCVar12 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                    (local_488,
                                     (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                      *)local_4e0);
                local_4f0 = pCVar12;
                pCVar13 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                    (local_480,
                                     (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                      *)&local_520);
                local_540 = (IAUserModelLibrary *)pCVar13;
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_4c8);
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_4c0);
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                          (local_4c8,
                           (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                            *)pCVar13);
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                          (local_4c0,
                           (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                            *)pCVar12);
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar13);
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar12);
                FUN_180002d10((longlong)pIVar16,
                              (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                               *)local_4c8);
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_4c0);
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_4c8);
                pCVar12 = FUN_180001e30((longlong)local_410,local_558);
                *(IAUserModelLibrary **)pCVar12 = pIVar16;
                pCVar26 = local_4e8;
                pCVar12 = local_518;
              }
LAB_1800062b3:
              pCVar6 = local_4e8;
              iVar9 = local_528;
              local_4f0 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                          ((ulonglong)local_4f0 & 0xffffffff00000000);
              iVar8 = 0;
              if (pIVar19 == (IAUserModelLibrary *)0x0) {
                iVar8 = 0;
                do {
                  pIVar14 = CApwnLibraries::GetLibrary(*(CApwnLibraries **)pCVar6,iVar8);
                  lVar24 = *(longlong *)pIVar14;
                  pcVar15 = ATL::CSimpleStringT<char,1>::GetBuffer
                                      ((CSimpleStringT<char,1> *)&local_530,0x40);
                  (**(code **)(lVar24 + 0x38))(pIVar14,pcVar15);
                  ATL::CSimpleStringT<char,1>::ReleaseBuffer
                            ((CSimpleStringT<char,1> *)&local_530,-1);
                  iVar10 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                           Compare((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                   &local_530,"Built-In");
                  if (iVar10 == 0) {
                    (**(code **)(*(longlong *)pIVar14 + 8))(pIVar14);
                    pIVar19 = pIVar14;
                  }
                  iVar8 = iVar8 + 1;
                } while (iVar8 < iVar9);
                pCVar26 = local_4e8;
                pCVar12 = local_518;
                iVar8 = (int)local_4f0;
                uVar25 = local_510;
                if (pIVar19 == (IAUserModelLibrary *)0x0) goto LAB_180006366;
              }
              iVar9 = FUN_1800034e0(pCVar26,(longlong *)pIVar19,(CSimpleStringT<char,1> *)pCVar12);
              if (iVar9 == 0) {
                pIVar20 = (IAUserModelLibrary *)0x1;
              }
            }
LAB_180006366:
            uVar25 = uVar25 + local_528;
          }
          iVar9 = (int)pIVar20;
          (**(code **)(*(longlong *)pIVar14 + 0x10))(pIVar14);
          local_510 = uVar25 + 1;
          pIVar14 = (IAUserModelLibrary *)(ulonglong)local_510;
        } while ((int)local_510 < local_528);
        pCVar26 = local_4e8;
        local_540 = pIVar19;
        if (local_538 == 0) goto LAB_18000639c;
      }
LAB_18000668f:
      if (iVar9 == 0) {
        if (pIVar19 != (IAUserModelLibrary *)0x0) {
LAB_180006752:
          p_Var17 = CStringList::Find(local_3d8,local_558,(__POSITION *)0x0);
          if (p_Var17 == (__POSITION *)0x0) {
            uVar21 = FUN_180004320((longlong)local_410,local_558,&local_4f8);
            if ((int)uVar21 == 0) {
              pIVar20 = operator_new(0x38);
              local_540 = pIVar20;
              if (pIVar20 == (IAUserModelLibrary *)0x0) {
                local_4f8 = (IAUserModelLibrary *)0x0;
              }
              else {
                *(longlong *)pIVar20 = 0;
                *(longlong *)(pIVar20 + 8) = 0;
                *(longlong *)(pIVar20 + 0x10) = 0;
                *(longlong *)(pIVar20 + 0x18) = 0;
                *(longlong *)(pIVar20 + 0x20) = 0;
                *(longlong *)(pIVar20 + 0x28) = 0;
                *(longlong *)(pIVar20 + 0x30) = 0;
                FUN_180001730((undefined8 *)pIVar20,10);
                *(undefined ***)pIVar20 = ModelTypeRefList::vftable;
                local_4f8 = pIVar20;
              }
            }
            pIVar20 = local_4f8;
            for (puVar3 = *(undefined8 **)(local_4f8 + 8); puVar3 != (undefined8 *)0x0;
                puVar3 = (undefined8 *)*puVar3) {
              bVar7 = FUN_180001540((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
                                    )(puVar3 + 2),&local_520);
              if ((int)CONCAT71(extraout_var_00,bVar7) != 0) goto LAB_1800068ac;
            }
            local_540 = (IAUserModelLibrary *)local_470;
            pCVar12 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                (local_470,
                                 (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                  *)local_4e0);
            local_4f0 = pCVar12;
            pCVar13 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                (local_468,
                                 (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                  *)&local_520);
            local_540 = (IAUserModelLibrary *)pCVar13;
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_4b8);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_4b0);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                      (local_4b8,
                       (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                       pCVar13);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                      (local_4b0,
                       (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                       pCVar12);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar13);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar12);
            FUN_180002d10((longlong)pIVar20,
                          (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                           *)local_4b8);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_4b0);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_4b8);
            pCVar12 = FUN_180001e30((longlong)local_410,local_558);
            *(IAUserModelLibrary **)pCVar12 = pIVar20;
          }
LAB_1800068ac:
          FUN_1800034e0(pCVar26,(longlong *)pIVar19,(CSimpleStringT<char,1> *)local_518);
          goto LAB_1800068bb;
        }
        iVar8 = CApwnLibraries::AddNewLibrary(*(CApwnLibraries **)pCVar26,"Built-In",0);
        if (iVar8 == 0) {
          PostMainWndMessage(0x565,0,0);
          local_528 = CApwnLibraries::CountLibraries(*(CApwnLibraries **)pCVar26);
          iVar8 = local_528 + -1;
          if (-1 < iVar8) {
            do {
              pIVar20 = CApwnLibraries::GetLibrary(*(CApwnLibraries **)pCVar26,iVar8);
              lVar24 = *(longlong *)pIVar20;
              pcVar15 = ATL::CSimpleStringT<char,1>::GetBuffer
                                  ((CSimpleStringT<char,1> *)&local_530,0x40);
              (**(code **)(lVar24 + 0x38))(pIVar20,pcVar15);
              ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)&local_530,-1);
              iVar9 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                 &local_530,"Built-In");
              if (iVar9 == 0) {
                (**(code **)(*(longlong *)pIVar20 + 8))(pIVar20);
                pIVar19 = pIVar20;
              }
              iVar8 = iVar8 + -1;
            } while (-1 < iVar8);
            if (pIVar19 != (IAUserModelLibrary *)0x0) goto LAB_180006752;
          }
        }
      }
      else {
LAB_1800068bb:
        if (pIVar19 != (IAUserModelLibrary *)0x0) {
          (**(code **)(*(longlong *)pIVar19 + 0x10))(pIVar19);
        }
      }
      pCVar12 = local_518;
      uVar29 = 0;
      lVar24 = *(longlong *)(pCVar26 + 0x18);
      uVar11 = uVar29;
      if (0 < lVar24) {
        do {
          if (((longlong)uVar29 < 0) || (lVar24 <= (longlong)uVar29)) {
                    /* WARNING: Subroutine does not return */
            AfxThrowInvalidArgException();
          }
          pCVar4 = *(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> **)
                    (*(longlong *)(pCVar26 + 0x10) + uVar29 * 8);
          pCVar13 = FUN_1800040d0((longlong)pCVar12,local_458);
          pCVar22 = FUN_1800040d0((longlong)pCVar4,local_460);
          pcVar15 = *(char **)pCVar22;
          lVar24 = *(longlong *)pCVar13 - (longlong)pcVar15;
          do {
            cVar1 = *pcVar15;
            cVar2 = pcVar15[lVar24];
            if (cVar1 != cVar2) break;
            pcVar15 = pcVar15 + 1;
          } while (cVar2 != '\0');
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_460);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_458);
          if (cVar1 == cVar2) {
            pCVar13 = FUN_180003de0((longlong)pCVar12,local_448);
            pCVar22 = FUN_180003de0((longlong)pCVar4,local_450);
            pcVar15 = *(char **)pCVar22;
            lVar24 = *(longlong *)pCVar13 - (longlong)pcVar15;
            goto LAB_1800069c0;
          }
          uVar25 = (int)uVar11 + 1;
          uVar29 = uVar29 + 1;
          lVar24 = *(longlong *)(pCVar26 + 0x18);
          uVar11 = (ulonglong)uVar25;
        } while ((int)uVar25 < lVar24);
      }
      goto LAB_180006964;
    }
LAB_180006b4c:
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_550);
    bVar7 = false;
    uVar25 = 0;
    local_510 = 0;
    if (0 < local_3c0) {
      pcVar15 = (char *)(*DAT_180079fa0)(0x1e1);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_550,pcVar15
                );
      uVar25 = 0;
      for (; local_3d0 != (undefined8 *)0x0; local_3d0 = (undefined8 *)*local_3d0) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_550,"\t")
        ;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_550,
                   (CSimpleStringT<char,1> *)(local_3d0 + 2));
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_550,"\n")
        ;
        uVar25 = 1;
        local_510 = 1;
      }
    }
    if ((int)local_3f8 != 0) {
      local_508 = (longlong *)-(ulonglong)(local_3f8 != (longlong *)0x0);
      bVar7 = false;
      while (local_3f8 != (longlong *)0x0) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_540);
        FUN_180004100((longlong)local_410,(longlong *)&local_508,
                      (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_540,
                      &local_4f8);
        local_3f8 = local_508;
        if (local_4f8 != (IAUserModelLibrary *)0x0) {
          bVar5 = true;
          plVar23 = *(longlong **)(local_4f8 + 8);
          local_508 = plVar23;
          for (; plVar23 != (longlong *)0x0; plVar23 = (longlong *)*plVar23) {
            iVar8 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                    CompareNoCase((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                  (plVar23 + 3),"RATEFRAC");
            if ((iVar8 == 0) ||
               (iVar8 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                        CompareNoCase((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                       *)(plVar23 + 3),"BATCHFRAC"), iVar8 == 0)) {
              bVar7 = true;
            }
            else {
              if (bVar5) {
                if (*(int *)(local_550 + -0x10) == 0) {
                  pcVar15 = (char *)(*DAT_180079fa0)(0x1e1);
                  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &local_550,pcVar15);
                }
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_550,"\t\'");
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_550,(CSimpleStringT<char,1> *)&local_540);
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_550,"\' ");
                pcVar15 = (char *)(*DAT_180079fa0)(0x1e8);
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_550,pcVar15);
                bVar5 = false;
              }
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_550
                         ,"\t\t");
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_550
                         ,(CSimpleStringT<char,1> *)(plVar23 + 2));
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_550
                         ,"\n");
            }
          }
          local_508 = (longlong *)0x0;
          (**(code **)(*(longlong *)local_4f8 + 8))(local_4f8,1);
          local_3f8 = (longlong *)0x0;
        }
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_540);
        uVar25 = local_510;
      }
    }
    if (((*(int *)(local_550 + -0x10) != 0) || (bVar7)) && (local_4fc == 0)) {
      if (uVar25 != 0) {
        pcVar15 = (char *)(*DAT_180079fa0)(0x1e2);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_550,
                   pcVar15);
      }
      if (bVar7) {
        if (*(int *)(local_550 + -0x10) == 0) {
          pcVar15 = (char *)(*DAT_180079fa0)(0x1e4);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_550,
                     pcVar15);
        }
        pcVar15 = (char *)(*DAT_180079fa0)(0x1e5);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_550,
                   pcVar15);
      }
      STmsgbox2(local_4d0,local_550,"Aspen Plus",0x30);
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_550);
  }
  FUN_180001c90(local_410);
  CStringList::~CStringList(local_398);
  CStringList::~CStringList(local_3d8);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_558);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_530);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_4e0);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_520);
  return;
  while (pcVar15 = pcVar15 + 1, cVar2 != '\0') {
LAB_1800069c0:
    cVar1 = *pcVar15;
    cVar2 = pcVar15[lVar24];
    if (cVar1 != cVar2) break;
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_450);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_448);
  pCVar27 = pCVar4;
  if (cVar1 != cVar2) goto LAB_180006b19;
  pCVar13 = FUN_180003f50((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                           *)pCVar12,local_438);
  uVar25 = local_548;
  uVar28 = local_548 | 2;
  local_548 = uVar28;
  local_538 = uVar28;
  iVar8 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                    (pCVar13,"Built-In");
  if (iVar8 == 0) {
    pCVar13 = FUN_180003f50(pCVar4,local_440);
    uVar28 = uVar25 | 6;
    local_548 = uVar28;
    local_538 = uVar28;
    iVar8 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                      (pCVar13,"Built-In");
    if (iVar8 == 0) goto LAB_180006a4f;
    bVar7 = true;
  }
  else {
LAB_180006a4f:
    bVar7 = false;
  }
  if ((uVar28 & 4) != 0) {
    uVar28 = uVar28 & 0xfffffffb;
    local_548 = uVar28;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_440);
  }
  if ((uVar28 & 2) != 0) {
    local_548 = uVar28 & 0xfffffffd;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_438);
  }
  if (bVar7) {
    if (pCVar12 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
      FUN_180001ce0(pCVar12);
      operator_delete(pCVar12);
    }
    pCVar27 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
              (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
    local_518 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)pCVar4;
  }
  else if ((pCVar4 != (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                      0x0) &&
          (plVar23 = (longlong *)FUN_180003f70((longlong)pCVar4), plVar23 != (longlong *)0x0)) {
    FUN_180007aa0((longlong)pCVar12,plVar23);
    lVar24 = FUN_1800040f0((longlong)pCVar12);
    if (lVar24 != 0) {
      local_540 = (IAUserModelLibrary *)0x0;
      iVar8 = (**(code **)*plVar23)(plVar23,&DAT_180056290,&local_540);
      if (-1 < iVar8) {
        (**(code **)(*(longlong *)local_540 + 0x30))(local_540,lVar24);
        FUN_180004720((longlong)pCVar12);
        (**(code **)(*(longlong *)local_540 + 0x10))();
      }
    }
  }
LAB_180006b19:
  CPtrArray::RemoveAt((CPtrArray *)(pCVar26 + 8),(longlong)(int)uVar11,1);
  if (pCVar27 != (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)0x0) {
    FUN_180001ce0((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)pCVar27);
    operator_delete(pCVar27);
  }
LAB_180006964:
  CPtrArray::SetAtGrow((CPtrArray *)(pCVar26 + 8),*(__int64 *)(pCVar26 + 0x18),local_518);
  param_2 = local_430;
  param_4 = local_428;
  uVar25 = local_548;
  uVar28 = local_4d8;
  if (local_500 <= (int)local_4d8) goto LAB_180006b4c;
  goto LAB_180005ef5;
}

/* ---- FUNC 00006EA0 FUN_180006ea0 (31 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180006ea0(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_1,
                  longlong *param_2)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  undefined1 auStack_148 [32];
  char *local_128;
  char *local_120;
  char local_118 [160];
  char local_78 [64];
  ulonglong local_38;
  
  local_38 = DAT_1800791f8 ^ (ulonglong)auStack_148;
  FUN_180007ca0(param_2,local_118);
  sscanf(local_118,"%s",local_78);
  iVar1 = strcmp(local_78,">VERSION");
  if (iVar1 == 0) {
    sscanf(local_118,"%s %d",local_78,param_1 + 0x38);
    FUN_180007ca0(param_2,local_118);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              (param_1 + 0x10,local_118);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::TrimRight(param_1 + 0x10);
    FUN_180007ca0(param_2,local_118);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              (param_1 + 8,local_118);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::TrimRight(param_1 + 8);
    FUN_180007ca0(param_2,local_118);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(param_1,local_118)
    ;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::TrimRight(param_1);
    FUN_180007ca0(param_2,local_118);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              (param_1 + 0x18,local_118);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::TrimRight(param_1 + 0x18);
  }
  else {
    pcVar2 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)(param_1 + 0x18),0x40)
    ;
    pcVar3 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)param_1,0x40);
    pcVar4 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)(param_1 + 8),0x40);
    pcVar5 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)(param_1 + 0x10),0x40)
    ;
    local_128 = pcVar3;
    local_120 = pcVar2;
    sscanf(local_118,"%s %s %s %s",pcVar5,pcVar4);
    ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)(param_1 + 0x10),-1);
    ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)(param_1 + 8),-1);
    ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)param_1,-1);
    ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)(param_1 + 0x18),-1);
  }
  iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                    (param_1,"ACM-Catalog");
  if (iVar1 == 0) {
    iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                      (param_1 + 0x18,"ACMMODEL");
    if (iVar1 == 0) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                (param_1,"ACM Models");
    }
  }
  return;
}

/* ---- FUNC 00006EBF FUN_180006ebf (274 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180006ebf(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_1,
                  longlong *param_2)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  undefined8 unaff_RBX;
  longlong in_R11;
  undefined8 unaff_R12;
  undefined8 unaff_R15;
  
  *(undefined8 *)(in_R11 + 0x18) = unaff_RBX;
  *(undefined8 *)(in_R11 + -0x20) = unaff_R12;
  *(undefined8 *)(in_R11 + -0x28) = unaff_R15;
  FUN_180007ca0(param_2,&stack0x00000030);
  sscanf(&stack0x00000030,"%s",&stack0x000000d0);
  iVar1 = strcmp(&stack0x000000d0,">VERSION");
  if (iVar1 == 0) {
    sscanf(&stack0x00000030,"%s %d",&stack0x000000d0,param_1 + 0x38);
    FUN_180007ca0(param_2,&stack0x00000030);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              (param_1 + 0x10,&stack0x00000030);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::TrimRight(param_1 + 0x10);
    FUN_180007ca0(param_2,&stack0x00000030);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              (param_1 + 8,&stack0x00000030);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::TrimRight(param_1 + 8);
    FUN_180007ca0(param_2,&stack0x00000030);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              (param_1,&stack0x00000030);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::TrimRight(param_1);
    FUN_180007ca0(param_2,&stack0x00000030);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              (param_1 + 0x18,&stack0x00000030);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::TrimRight(param_1 + 0x18);
  }
  else {
    ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)(param_1 + 0x18),0x40);
    pcVar2 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)param_1,0x40);
    pcVar3 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)(param_1 + 8),0x40);
    pcVar4 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)(param_1 + 0x10),0x40)
    ;
    sscanf(&stack0x00000030,"%s %s %s %s",pcVar4,pcVar3,pcVar2);
    ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)(param_1 + 0x10),-1);
    ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)(param_1 + 8),-1);
    ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)param_1,-1);
    ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)(param_1 + 0x18),-1);
  }
  iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                    (param_1,"ACM-Catalog");
  if (iVar1 == 0) {
    iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                      (param_1 + 0x18,"ACMMODEL");
    if (iVar1 == 0) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                (param_1,"ACM Models");
    }
  }
  return;
}

/* ---- FUNC 00006FD1 FUN_180006fd1 (190 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180006fd1(void)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  CSimpleStringT<char,1> *unaff_RBP;
  CSimpleStringT<char,1> *unaff_R14;
  
  ATL::CSimpleStringT<char,1>::GetBuffer(unaff_R14,0x40);
  pcVar2 = ATL::CSimpleStringT<char,1>::GetBuffer(unaff_RBP,0x40);
  pcVar3 = ATL::CSimpleStringT<char,1>::GetBuffer(unaff_RBP + 8,0x40);
  pcVar4 = ATL::CSimpleStringT<char,1>::GetBuffer(unaff_RBP + 0x10,0x40);
  sscanf(&stack0x00000030,"%s %s %s %s",pcVar4,pcVar3,pcVar2);
  ATL::CSimpleStringT<char,1>::ReleaseBuffer(unaff_RBP + 0x10,-1);
  ATL::CSimpleStringT<char,1>::ReleaseBuffer(unaff_RBP + 8,-1);
  ATL::CSimpleStringT<char,1>::ReleaseBuffer(unaff_RBP,-1);
  ATL::CSimpleStringT<char,1>::ReleaseBuffer(unaff_R14,-1);
  iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)unaff_RBP,
                     "ACM-Catalog");
  if (iVar1 == 0) {
    iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)unaff_R14,
                       "ACMMODEL");
    if (iVar1 == 0) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)unaff_RBP,
                 "ACM Models");
    }
  }
  return;
}

/* ---- FUNC 0000708F FUN_18000708f (44 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18000708f(void)

{
  int iVar1;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *unaff_RBP;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *unaff_R14;
  
  iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                    (unaff_RBP,"ACM-Catalog");
  if (iVar1 == 0) {
    iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                      (unaff_R14,"ACMMODEL");
    if (iVar1 == 0) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                (unaff_RBP,"ACM Models");
    }
  }
  return;
}

/* ---- FUNC 000070BB FUN_1800070bb (63 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1800070bb(void)

{
  int iVar1;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *unaff_RBP;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *unaff_R14;
  
  iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                    (unaff_R14,"ACMMODEL");
  if (iVar1 == 0) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              (unaff_RBP,"ACM Models");
  }
  return;
}

/* ---- FUNC 00007100 FUN_180007100 (33 bytes) ---- */

void FUN_180007100(longlong param_1,undefined4 *param_2)

{
  longlong *plVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined4 *puVar7;
  
  puVar7 = param_2 + 1;
  *param_2 = *(undefined4 *)(param_1 + 0x18);
  uVar4 = 0;
  lVar3 = *(longlong *)(param_1 + 0x18);
  uVar6 = uVar4;
  if (0 < lVar3) {
    do {
      if (((longlong)uVar4 < 0) || (lVar3 <= (longlong)uVar4)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      plVar1 = *(longlong **)(*(longlong *)(param_1 + 0x10) + uVar4 * 8);
      iVar2 = FUN_180004220(plVar1);
      FUN_180007190(plVar1,puVar7);
      lVar3 = *(longlong *)(param_1 + 0x18);
      uVar5 = (int)uVar6 + 1;
      puVar7 = (undefined4 *)((longlong)puVar7 + (longlong)iVar2);
      uVar4 = uVar4 + 1;
      uVar6 = (ulonglong)uVar5;
    } while ((int)uVar5 < lVar3);
  }
  return;
}

/* ---- FUNC 00007121 FUN_180007121 (92 bytes) ---- */

void FUN_180007121(undefined8 param_1,longlong param_2)

{
  longlong *plVar1;
  int iVar2;
  ulonglong uVar3;
  uint unaff_EBP;
  undefined4 *unaff_R14;
  longlong unaff_R15;
  
  uVar3 = (ulonglong)unaff_EBP;
  while ((-1 < (longlong)uVar3 && ((longlong)uVar3 < param_2))) {
    plVar1 = *(longlong **)(*(longlong *)(unaff_R15 + 0x10) + uVar3 * 8);
    iVar2 = FUN_180004220(plVar1);
    FUN_180007190(plVar1,unaff_R14);
    param_2 = *(longlong *)(unaff_R15 + 0x18);
    unaff_EBP = unaff_EBP + 1;
    unaff_R14 = (undefined4 *)((longlong)unaff_R14 + (longlong)iVar2);
    uVar3 = uVar3 + 1;
    if (param_2 <= (int)unaff_EBP) {
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 0000717D FUN_18000717d (10 bytes) ---- */

void FUN_18000717d(void)

{
  return;
}

/* ---- FUNC 00007187 AfxThrowInvalidArgException (5 bytes) ---- */

void __cdecl AfxThrowInvalidArgException(void)

{
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 00007190 FUN_180007190 (256 bytes) ---- */

void FUN_180007190(longlong *param_1,undefined4 *param_2)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  
  *param_2 = 0;
  pcVar2 = (char *)(param_2 + 5);
  iVar4 = *(int *)(param_1[2] + -0x10) + 1;
  param_2[1] = iVar4;
  iVar4 = iVar4 + *(int *)(param_1[1] + -0x10) + 1;
  param_2[2] = iVar4;
  param_2[3] = *(int *)(*param_1 + -0x10) + 1 + iVar4;
  param_2[4] = (int)param_1[7];
  pcVar5 = (char *)param_1[2];
  pcVar3 = pcVar2;
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    *pcVar3 = cVar1;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  pcVar2 = pcVar2 + *(int *)(param_1[2] + -0x10);
  *pcVar2 = '\0';
  pcVar2 = pcVar2 + 1;
  pcVar5 = (char *)param_1[1];
  pcVar3 = pcVar2;
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    *pcVar3 = cVar1;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  pcVar2 = pcVar2 + *(int *)(param_1[1] + -0x10);
  *pcVar2 = '\0';
  pcVar5 = (char *)*param_1;
  pcVar3 = pcVar2 + 1;
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    *pcVar3 = cVar1;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  pcVar3 = pcVar2 + 1 + *(int *)(*param_1 + -0x10);
  *pcVar3 = '\0';
  pcVar2 = (char *)param_1[3];
  pcVar5 = pcVar3;
  do {
    pcVar5 = pcVar5 + 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    *pcVar5 = cVar1;
  } while (cVar1 != '\0');
  pcVar3[(longlong)*(int *)(param_1[3] + -0x10) + 1] = '\0';
  return;
}

/* ---- FUNC 00007290 FUN_180007290 (303 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180007290(longlong param_1,longlong *param_2)

{
  undefined8 *puVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  longlong lVar8;
  undefined1 *puVar9;
  longlong lVar10;
  undefined1 auStack_108 [32];
  undefined1 local_e8 [16];
  char local_d8 [160];
  ulonglong local_38;
  
  local_38 = DAT_1800791f8 ^ (ulonglong)auStack_108;
  puVar9 = local_e8;
  (**(code **)(*param_2 + 0x20))(param_2,&DAT_1800536a0,3);
  lVar10 = (longlong)*(int *)(param_1 + 0x18);
  uVar5 = 0;
  uVar4 = 0;
  uVar6 = uVar5;
  uVar7 = uVar5;
  if (0 < lVar10) {
    do {
      if (((longlong)uVar7 < 0) || (*(longlong *)(param_1 + 0x18) <= (longlong)uVar7))
      goto LAB_1800073ba;
      lVar3 = FUN_180003f70(*(longlong *)(*(longlong *)(param_1 + 0x10) + uVar7 * 8));
      uVar4 = (uint)uVar6 + 1;
      if (lVar3 == 0) {
        uVar4 = (uint)uVar6;
      }
      uVar7 = uVar7 + 1;
      uVar6 = (ulonglong)uVar4;
    } while ((longlong)uVar7 < lVar10);
  }
  FUN_180007de0(local_d8,&DAT_1800536a4,(ulonglong)uVar4,puVar9);
  lVar3 = -1;
  do {
    lVar8 = lVar3 + 1;
    lVar2 = lVar3 + 1;
    lVar3 = lVar8;
  } while (local_d8[lVar2] != '\0');
  puVar9 = local_e8;
  (**(code **)(*param_2 + 0x20))(param_2,local_d8);
  if (0 < lVar10) {
    do {
      if (((longlong)uVar5 < 0) || (*(longlong *)(param_1 + 0x18) <= (longlong)uVar5)) {
LAB_1800073ba:
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      puVar1 = *(undefined8 **)(*(longlong *)(param_1 + 0x10) + uVar5 * 8);
      lVar3 = FUN_180003f70((longlong)puVar1);
      if (lVar3 != 0) {
        FUN_1800075b0(puVar1,param_2,lVar8,puVar9);
      }
      uVar5 = uVar5 + 1;
    } while ((longlong)uVar5 < lVar10);
  }
  return;
}

/* ---- FUNC 000073C0 FUN_1800073c0 (482 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1800073c0(longlong param_1,longlong *param_2,CMapStringToString *param_3)

{
  undefined8 *puVar1;
  int iVar2;
  longlong lVar3;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar4;
  longlong lVar5;
  uint uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  undefined1 *puVar9;
  ulonglong uVar10;
  longlong lVar11;
  undefined1 auStack_128 [32];
  undefined8 local_108;
  undefined1 local_100 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_f8 [16];
  char local_e8 [160];
  ulonglong local_48;
  
  local_48 = DAT_1800791f8 ^ (ulonglong)auStack_128;
  puVar9 = local_100;
  (**(code **)(*param_2 + 0x20))(param_2,&DAT_1800536a0,3);
  uVar7 = 0;
  lVar11 = (longlong)*(int *)(param_1 + 0x18);
  uVar8 = uVar7;
  uVar10 = uVar7;
  if (0 < lVar11) {
    do {
      if (((longlong)uVar8 < 0) || (*(longlong *)(param_1 + 0x18) <= (longlong)uVar8))
      goto LAB_18000759d;
      lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x10) + uVar8 * 8);
      lVar3 = FUN_180003f70(lVar5);
      if (lVar3 != 0) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_108);
        pCVar4 = FUN_1800040d0(lVar5,local_f8);
        iVar2 = CMapStringToString::Lookup
                          (param_3,*(char **)pCVar4,
                           (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_108);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_f8);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_108);
        uVar6 = (uint)uVar10 + 1;
        if (iVar2 == 0) {
          uVar6 = (uint)uVar10;
        }
        uVar10 = (ulonglong)uVar6;
      }
      uVar8 = uVar8 + 1;
    } while ((longlong)uVar8 < lVar11);
  }
  FUN_180007de0(local_e8,&DAT_1800536a4,uVar10,puVar9);
  lVar5 = -1;
  do {
    lVar3 = lVar5 + 1;
    lVar5 = lVar5 + 1;
  } while (local_e8[lVar3] != '\0');
  puVar9 = local_100;
  (**(code **)(*param_2 + 0x20))(param_2,local_e8);
  if (0 < lVar11) {
    do {
      if (((longlong)uVar7 < 0) || (*(longlong *)(param_1 + 0x18) <= (longlong)uVar7)) {
LAB_18000759d:
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      puVar1 = *(undefined8 **)(*(longlong *)(param_1 + 0x10) + uVar7 * 8);
      lVar5 = FUN_180003f70((longlong)puVar1);
      if (lVar5 != 0) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_108);
        pCVar4 = FUN_1800040d0((longlong)puVar1,local_f8);
        iVar2 = CMapStringToString::Lookup
                          (param_3,*(char **)pCVar4,
                           (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_108);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_f8);
        if (iVar2 != 0) {
          FUN_1800076a0(puVar1,param_2,local_108,puVar9);
        }
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_108);
      }
      uVar7 = uVar7 + 1;
    } while ((longlong)uVar7 < lVar11);
  }
  return;
}

/* ---- FUNC 000075B0 FUN_1800075b0 (225 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1800075b0(undefined8 *param_1,longlong *param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 auStack_f8 [32];
  undefined8 local_d8;
  undefined8 local_d0;
  undefined1 local_c8 [16];
  char local_b8 [160];
  ulonglong local_18;
  
  local_18 = DAT_1800791f8 ^ (ulonglong)auStack_f8;
  FUN_180007de0(local_b8,">VERSION %d\n",(ulonglong)*(uint *)(param_1 + 7),param_4);
  lVar2 = -1;
  do {
    lVar3 = lVar2 + 1;
    lVar1 = lVar2 + 1;
    lVar2 = lVar3;
  } while (local_b8[lVar1] != '\0');
  (**(code **)(*param_2 + 0x20))(param_2,local_b8,lVar3,local_c8);
  local_d0 = param_1[3];
  local_d8 = *param_1;
  FUN_180007de0(local_b8,"%s\n%s\n%s\n%s\n",param_1[2],param_1[1]);
  lVar2 = -1;
  do {
    lVar3 = lVar2 + 1;
    lVar1 = lVar2 + 1;
    lVar2 = lVar3;
  } while (local_b8[lVar1] != '\0');
  (**(code **)(*param_2 + 0x20))(param_2,local_b8,lVar3,local_c8);
  return;
}

/* ---- FUNC 000076A0 FUN_1800076a0 (223 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1800076a0(undefined8 *param_1,longlong *param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 auStack_108 [32];
  undefined8 local_e8;
  undefined8 local_e0;
  undefined1 local_d8 [16];
  char local_c8 [160];
  ulonglong local_28;
  
  local_28 = DAT_1800791f8 ^ (ulonglong)auStack_108;
  FUN_180007de0(local_c8,">VERSION %d\n",(ulonglong)*(uint *)(param_1 + 7),param_4);
  lVar2 = -1;
  do {
    lVar3 = lVar2 + 1;
    lVar1 = lVar2 + 1;
    lVar2 = lVar3;
  } while (local_c8[lVar1] != '\0');
  (**(code **)(*param_2 + 0x20))(param_2,local_c8,lVar3,local_d8);
  local_e0 = param_1[3];
  local_e8 = *param_1;
  FUN_180007de0(local_c8,"%s\n%s\n%s\n%s\n",param_3,param_1[1]);
  lVar2 = -1;
  do {
    lVar3 = lVar2 + 1;
    lVar1 = lVar2 + 1;
    lVar2 = lVar3;
  } while (local_c8[lVar1] != '\0');
  (**(code **)(*param_2 + 0x20))(param_2,local_c8,lVar3,local_d8);
  return;
}

/* ---- FUNC 00007780 FUN_180007780 (229 bytes) ---- */

void FUN_180007780(longlong param_1,CArchive *param_2)

{
  undefined8 *puVar1;
  __uint64 _Var2;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> local_18 [16];
  
  if ((~*(uint *)(param_2 + 0x20) & 1) == 0) {
    for (_Var2 = CArchive::ReadCount(param_2); _Var2 != 0; _Var2 = _Var2 - 1) {
      _eh_vector_constructor_iterator_(local_18,0x10,1,FUN_180001c20,FUN_180001e00);
      FUN_180001650(param_2,local_18,1);
      FUN_180002d10(param_1,local_18);
      _eh_vector_destructor_iterator_(local_18,0x10,1,FUN_180001e00);
    }
  }
  else {
    CArchive::WriteCount(param_2,*(__uint64 *)(param_1 + 0x18));
    for (puVar1 = *(undefined8 **)(param_1 + 8); puVar1 != (undefined8 *)0x0;
        puVar1 = (undefined8 *)*puVar1) {
      FUN_180001650(param_2,puVar1 + 2,1);
    }
  }
  return;
}

/* ---- FUNC 00007870 FUN_180007870 (327 bytes) ---- */

void FUN_180007870(longlong param_1,CArchive *param_2)

{
  undefined8 uVar1;
  __uint64 _Var2;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar3;
  uint uVar4;
  ulonglong uVar5;
  char *local_res10;
  undefined8 local_res18 [2];
  
  if ((~*(uint *)(param_2 + 0x20) & 1) == 0) {
    for (_Var2 = CArchive::ReadCount(param_2); _Var2 != 0; _Var2 = _Var2 - 1) {
      _eh_vector_constructor_iterator_
                (&local_res10,8,1,
                 CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>_exref,
                 ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>_exref);
      SerializeElements<ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>_>
                (param_2,(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                         &local_res10,1);
      FUN_180001570(param_2,local_res18,1);
      uVar1 = local_res18[0];
      pCVar3 = FUN_180001e30(param_1,local_res10);
      *(undefined8 *)pCVar3 = uVar1;
      _eh_vector_destructor_iterator_
                (&local_res10,8,1,
                 ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>_exref);
    }
  }
  else {
    CArchive::WriteCount(param_2,*(__uint64 *)(param_1 + 0x18));
    if (((*(longlong *)(param_1 + 0x18) != 0) && (*(longlong *)(param_1 + 8) != 0)) &&
       (uVar5 = 0, *(int *)(param_1 + 0x10) != 0)) {
      do {
        for (pCVar3 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
                       (*(longlong *)(param_1 + 8) + uVar5 * 8);
            pCVar3 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
            pCVar3 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
                      (pCVar3 + 0x10)) {
          SerializeElements<ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>_>
                    (param_2,pCVar3,1);
          FUN_180001570(param_2,pCVar3 + 8,1);
        }
        uVar4 = (int)uVar5 + 1;
        uVar5 = (ulonglong)uVar4;
      } while (uVar4 < *(uint *)(param_1 + 0x10));
      return;
    }
  }
  return;
}

/* ---- FUNC 000079C0 SetAt (33 bytes) ---- */

/* public: void __cdecl CTypedPtrArray<class CPtrArray,class CNameAndState *
   __ptr64>::SetAt(__int64,class CNameAndState * __ptr64) __ptr64 */

void __thiscall
CTypedPtrArray<CPtrArray,CNameAndState*___ptr64>::SetAt
          (CTypedPtrArray<CPtrArray,CNameAndState*___ptr64> *this,__int64 param_1,
          CNameAndState *param_2)

{
                    /* 0x79c0  185
                       ?SetAt@?$CTypedPtrArray@VCPtrArray@@PEAVCNameAndState@@@@QEAAX_JPEAVCNameAndState@@@Z
                        */
  if ((-1 < param_1) && (param_1 < *(longlong *)(this + 0x10))) {
    *(CNameAndState **)(*(longlong *)(this + 8) + param_1 * 8) = param_2;
    return;
  }
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 000079F0 SetAtGrow (5 bytes) ---- */

/* public: void __cdecl CTypedPtrArray<class CPtrArray,class CNameAndState *
   __ptr64>::SetAtGrow(__int64,class CNameAndState * __ptr64) __ptr64 */

void __thiscall
CTypedPtrArray<CPtrArray,CNameAndState*___ptr64>::SetAtGrow
          (CTypedPtrArray<CPtrArray,CNameAndState*___ptr64> *this,__int64 param_1,
          CNameAndState *param_2)

{
                    /* 0x79f0  187
                       ?SetAtGrow@?$CTypedPtrArray@VCPtrArray@@PEAVCNameAndState@@@@QEAAX_JPEAVCNameAndState@@@Z
                        */
  CPtrArray::SetAtGrow((CPtrArray *)this,param_1,param_2);
  return;
}

/* ---- FUNC 00007A00 FUN_180007a00 (160 bytes) ---- */

void FUN_180007a00(CSimpleStringT<char,1> *param_1,longlong *param_2)

{
  longlong *plVar1;
  longlong lVar2;
  char *pcVar3;
  
  if (*(longlong **)(param_1 + 0x20) != param_2) {
    if (param_2 != (longlong *)0x0) {
      (**(code **)(*param_2 + 8))(param_2);
    }
    plVar1 = *(longlong **)(param_1 + 0x20);
    *(longlong **)(param_1 + 0x20) = param_2;
    if (plVar1 != (longlong *)0x0) {
      (**(code **)(*plVar1 + 0x10))();
    }
  }
  plVar1 = *(longlong **)(param_1 + 0x20);
  if (plVar1 != (longlong *)0x0) {
    lVar2 = *plVar1;
    pcVar3 = ATL::CSimpleStringT<char,1>::GetBuffer(param_1,0x40);
    (**(code **)(lVar2 + 0x38))(plVar1,pcVar3,0x3f);
                    /* WARNING: Could not recover jumptable at 0x000180007a7c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    ATL::CSimpleStringT<char,1>::ReleaseBuffer(param_1,-1);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000180007a99. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_1,"");
  return;
}

/* ---- FUNC 00007AA0 FUN_180007aa0 (148 bytes) ---- */

void FUN_180007aa0(longlong param_1,longlong *param_2)

{
  longlong *plVar1;
  char *pcVar2;
  CSimpleStringT<char,1> *this;
  
  if (*(longlong **)(param_1 + 0x30) != param_2) {
    if (param_2 != (longlong *)0x0) {
      (**(code **)(*param_2 + 8))(param_2);
    }
    plVar1 = *(longlong **)(param_1 + 0x30);
    *(longlong **)(param_1 + 0x30) = param_2;
    if (plVar1 != (longlong *)0x0) {
      (**(code **)(*plVar1 + 0x10))();
    }
    plVar1 = *(longlong **)(param_1 + 0x30);
    this = (CSimpleStringT<char,1> *)(param_1 + 0x10);
    if (plVar1 != (longlong *)0x0) {
      pcVar2 = ATL::CSimpleStringT<char,1>::GetBuffer(this,0x40);
      FUN_180003e00(plVar1,pcVar2,0x3f);
                    /* WARNING: Could not recover jumptable at 0x000180007b15. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      ATL::CSimpleStringT<char,1>::ReleaseBuffer(this,-1);
      return;
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)this,"");
  }
  return;
}

/* ---- FUNC 00007B40 FUN_180007b40 (23 bytes) ---- */

void FUN_180007b40(longlong param_1,char *param_2)

{
  if (param_2 == (char *)0x0) {
    param_2 = "";
  }
                    /* WARNING: Could not recover jumptable at 0x000180007b50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0x10),
             param_2);
  return;
}

/* ---- FUNC 00007B60 FUN_180007b60 (75 bytes) ---- */

void FUN_180007b60(longlong param_1,longlong *param_2)

{
  longlong *plVar1;
  longlong lVar2;
  char *pcVar3;
  longlong *local_res8;
  
  if (*(longlong **)(param_1 + 0x28) != param_2) {
    if (param_2 != (longlong *)0x0) {
      (**(code **)(*param_2 + 8))(param_2);
    }
    plVar1 = *(longlong **)(param_1 + 0x28);
    *(longlong **)(param_1 + 0x28) = param_2;
    if (plVar1 != (longlong *)0x0) {
      (**(code **)(*plVar1 + 0x10))();
    }
  }
  plVar1 = *(longlong **)(param_1 + 0x28);
  if (plVar1 != (longlong *)0x0) {
    (**(code **)(*plVar1 + 0x30))(plVar1,param_1 + 0x38);
    (**(code **)**(undefined8 **)(param_1 + 0x28))
              (*(undefined8 **)(param_1 + 0x28),&DAT_1800561e0,&local_res8);
    lVar2 = *local_res8;
    pcVar3 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)(param_1 + 8),0x40);
    (**(code **)(lVar2 + 0x18))(local_res8,pcVar3,0x3f);
    ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)(param_1 + 8),-1);
    (**(code **)(*local_res8 + 0x10))();
    plVar1 = *(longlong **)(param_1 + 0x28);
    lVar2 = *plVar1;
    pcVar3 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)(param_1 + 0x18),0x40)
    ;
    (**(code **)(lVar2 + 0x18))(plVar1,pcVar3,0x3f);
    ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)(param_1 + 0x18),-1);
    return;
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 8),"");
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0x18),"");
  *(undefined4 *)(param_1 + 0x38) = 0;
  return;
}

/* ---- FUNC 00007BAB FUN_180007bab (173 bytes) ---- */

void FUN_180007bab(void)

{
  longlong lVar1;
  longlong *plVar2;
  longlong in_RAX;
  char *pcVar3;
  longlong unaff_RBP;
  longlong *in_stack_00000030;
  
  (**(code **)(in_RAX + 0x30))();
  (**(code **)**(undefined8 **)(unaff_RBP + 0x28))
            (*(undefined8 **)(unaff_RBP + 0x28),&DAT_1800561e0,&stack0x00000030);
  lVar1 = *in_stack_00000030;
  pcVar3 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)(unaff_RBP + 8),0x40);
  (**(code **)(lVar1 + 0x18))(in_stack_00000030,pcVar3,0x3f);
  ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)(unaff_RBP + 8),-1);
  (**(code **)(*in_stack_00000030 + 0x10))();
  plVar2 = *(longlong **)(unaff_RBP + 0x28);
  lVar1 = *plVar2;
  pcVar3 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)(unaff_RBP + 0x18),0x40)
  ;
  (**(code **)(lVar1 + 0x18))(plVar2,pcVar3,0x3f);
  ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)(unaff_RBP + 0x18),-1);
  return;
}

/* ---- FUNC 00007C58 FUN_180007c58 (52 bytes) ---- */

void FUN_180007c58(void)

{
  longlong unaff_RBP;
  
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(unaff_RBP + 8),"");
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(unaff_RBP + 0x18),"")
  ;
  *(undefined4 *)(unaff_RBP + 0x38) = 0;
  return;
}

/* ---- FUNC 00007C90 FUN_180007c90 (5 bytes) ---- */

void FUN_180007c90(void *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000180046271. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  operator_delete(param_1);
  return;
}

/* ---- FUNC 00007CA0 FUN_180007ca0 (116 bytes) ---- */

void FUN_180007ca0(longlong *param_1,char *param_2)

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

/* ---- FUNC 00007D20 FreeGlobalBlockUsage (56 bytes) ---- */

void FreeGlobalBlockUsage(void)

{
  CApwnBlockUsage *pCVar1;
  
                    /* 0x7d20  352  FreeGlobalBlockUsage */
  pCVar1 = g_pApwnBlockUsage;
  if (g_pApwnBlockUsage != (CApwnBlockUsage *)0x0) {
    CApwnBlockUsage::~CApwnBlockUsage(g_pApwnBlockUsage);
    operator_delete(pCVar1);
  }
  g_pApwnBlockUsage = (CApwnBlockUsage *)0x0;
  return;
}

/* ---- FUNC 00007D60 InitGlobalBlockUsage (78 bytes) ---- */

void InitGlobalBlockUsage(IAModel *param_1)

{
  CApwnBlockUsage *this;
  
                    /* 0x7d60  368  InitGlobalBlockUsage */
  if (g_pApwnBlockUsage == (CApwnBlockUsage *)0x0) {
    this = operator_new(0x38);
    if (this != (CApwnBlockUsage *)0x0) {
      g_pApwnBlockUsage =
           (CApwnBlockUsage *)CApwnBlockUsage::CApwnBlockUsage(this,g_pApwnLibs,param_1);
      return;
    }
    g_pApwnBlockUsage = (CApwnBlockUsage *)0x0;
  }
  return;
}

/* ---- FUNC 00007DB0 MMStructGetSorResStringEx (16 bytes) ---- */

void MMStructGetSorResStringEx(void)

{
                    /* 0x7db0  412  MMStructGetSorResStringEx */
  if (DAT_180079fa0 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000180007dbc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*DAT_180079fa0)();
    return;
  }
  return;
}

/* ---- FUNC 00007DC0 FUN_180007dc0 (8 bytes) ---- */

undefined * FUN_180007dc0(void)

{
  return &DAT_180079fa8;
}

/* ---- FUNC 00007DD0 FUN_180007dd0 (8 bytes) ---- */

undefined * FUN_180007dd0(void)

{
  return &DAT_180079fb0;
}

/* ---- FUNC 00007DE0 FUN_180007de0 (94 bytes) ---- */

int FUN_180007de0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  ulonglong *puVar2;
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res18 = param_3;
  local_res20 = param_4;
  puVar2 = (ulonglong *)FUN_180007dc0();
  iVar1 = __stdio_common_vsprintf(*puVar2 | 1,param_1,0xffffffffffffffff,param_2,0,&local_res18);
  if (iVar1 < 0) {
    iVar1 = -1;
  }
  return iVar1;
}

/* ---- FUNC 00007E40 sscanf (82 bytes) ---- */

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
  puVar2 = (undefined8 *)FUN_180007dd0();
  iVar1 = __stdio_common_vsscanf(*puVar2,_Src,0xffffffffffffffff,_Format,0,&local_res18);
  return iVar1;
}

/* ---- FUNC 00007EA0 FUN_180007ea0 (112 bytes) ---- */

uint FUN_180007ea0(undefined8 *param_1,undefined8 *param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  uint uVar3;
  undefined8 *_Buf1;
  ulonglong _Size;
  undefined8 *_Buf2;
  
  _Buf2 = param_2;
  if (0xf < (ulonglong)param_2[3]) {
    _Buf2 = (undefined8 *)*param_2;
  }
  _Buf1 = param_1;
  if (0xf < (ulonglong)param_1[3]) {
    _Buf1 = (undefined8 *)*param_1;
  }
  uVar1 = param_2[2];
  uVar2 = param_1[2];
  _Size = uVar2;
  if (uVar1 < uVar2) {
    _Size = uVar1;
  }
  uVar3 = memcmp(_Buf1,_Buf2,_Size);
  if (uVar3 == 0) {
    if (uVar2 < uVar1) {
      return 1;
    }
    uVar3 = 0;
  }
  return uVar3 >> 0x1f;
}

/* ---- FUNC 00007F10 FUN_180007f10 (58 bytes) ---- */

void FUN_180007f10(ulonglong param_1)

{
  void *pvVar1;
  
  if (param_1 + 0x27 <= param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_18000ac70();
  }
  pvVar1 = operator_new(param_1 + 0x27);
  if (pvVar1 != (void *)0x0) {
    *(void **)(((longlong)pvVar1 + 0x27U & 0xffffffffffffffe0) - 8) = pvVar1;
    return;
  }
                    /* WARNING: Subroutine does not return */
  _invalid_parameter_noinfo_noreturn();
}

/* ---- FUNC 00007F50 FUN_180007f50 (164 bytes) ---- */

void FUN_180007f50(longlong *param_1,longlong *param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong *plVar6;
  
  plVar6 = FUN_180008120(param_1,*(undefined8 **)(*param_2 + 8),*param_1,param_4);
  *(longlong **)(*param_1 + 8) = plVar6;
  plVar6 = (longlong *)*param_1;
  param_1[1] = param_2[1];
  plVar2 = (longlong *)plVar6[1];
  if (*(char *)((longlong)plVar2 + 0x19) != '\0') {
    *plVar6 = (longlong)plVar6;
    *(longlong *)(*param_1 + 0x10) = *param_1;
    return;
  }
  cVar1 = *(char *)(*plVar2 + 0x19);
  plVar5 = (longlong *)*plVar2;
  while (cVar1 == '\0') {
    cVar1 = *(char *)(*plVar5 + 0x19);
    plVar2 = plVar5;
    plVar5 = (longlong *)*plVar5;
  }
  *plVar6 = (longlong)plVar2;
  lVar3 = *(longlong *)(*param_1 + 8);
  lVar4 = *(longlong *)(lVar3 + 0x10);
  cVar1 = *(char *)(lVar4 + 0x19);
  while (cVar1 == '\0') {
    cVar1 = *(char *)(*(longlong *)(lVar4 + 0x10) + 0x19);
    lVar3 = lVar4;
    lVar4 = *(longlong *)(lVar4 + 0x10);
  }
  *(longlong *)(*param_1 + 0x10) = lVar3;
  return;
}

/* ---- FUNC 00008000 FUN_180008000 (286 bytes) ---- */

longlong *
FUN_180008000(undefined8 *param_1,undefined8 *param_2,longlong param_3,undefined8 param_4)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong *plVar5;
  
  plVar4 = (longlong *)*param_1;
  if (*(char *)((longlong)param_2 + 0x19) == '\0') {
    plVar1 = operator_new(0x50);
    plVar2 = plVar1 + 4;
    *plVar2 = (longlong)&DAT_1800537c8;
    plVar1[5] = 0;
    plVar1[6] = 0;
    plVar1[7] = 0;
    plVar1[8] = 0xf;
    *(undefined1 *)(plVar1 + 5) = 0;
    plVar5 = (longlong *)((longlong)*(int *)(param_2[4] + 4) + (longlong)(param_2 + 4));
    plVar2 = (longlong *)((longlong)*(int *)(*plVar2 + 4) + (longlong)plVar2);
    if (plVar2 != plVar5) {
      plVar3 = plVar5;
      if (0xf < (ulonglong)plVar5[3]) {
        plVar3 = (longlong *)*plVar5;
      }
      FUN_18000ad20(plVar2,plVar3,plVar5[2]);
    }
    *(undefined4 *)(plVar1 + 9) = *(undefined4 *)(param_2 + 9);
    *plVar1 = (longlong)plVar4;
    plVar1[2] = (longlong)plVar4;
    *(undefined2 *)(plVar1 + 3) = 0;
    plVar1[1] = param_3;
    *(undefined1 *)(plVar1 + 3) = *(undefined1 *)(param_2 + 3);
    if (*(char *)((longlong)plVar4 + 0x19) != '\0') {
      plVar4 = plVar1;
    }
    plVar2 = FUN_180008000(param_1,(undefined8 *)*param_2,(longlong)plVar1,param_4);
    *plVar1 = (longlong)plVar2;
    plVar2 = FUN_180008000(param_1,(undefined8 *)param_2[2],(longlong)plVar1,param_4);
    plVar1[2] = (longlong)plVar2;
  }
  return plVar4;
}

/* ---- FUNC 00008120 FUN_180008120 (184 bytes) ---- */

longlong *
FUN_180008120(undefined8 *param_1,undefined8 *param_2,longlong param_3,undefined8 param_4)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  
  plVar3 = (longlong *)*param_1;
  if (*(char *)((longlong)param_2 + 0x19) == '\0') {
    plVar1 = operator_new(0x50);
    FUN_180009090(plVar1 + 4,param_2 + 4);
    *plVar1 = (longlong)plVar3;
    plVar1[2] = (longlong)plVar3;
    *(undefined2 *)(plVar1 + 3) = 0;
    plVar1[1] = param_3;
    *(undefined1 *)(plVar1 + 3) = *(undefined1 *)(param_2 + 3);
    if (*(char *)((longlong)plVar3 + 0x19) != '\0') {
      plVar3 = plVar1;
    }
    plVar2 = FUN_180008120(param_1,(undefined8 *)*param_2,(longlong)plVar1,param_4);
    *plVar1 = (longlong)plVar2;
    plVar2 = FUN_180008120(param_1,(undefined8 *)param_2[2],(longlong)plVar1,param_4);
    plVar1[2] = (longlong)plVar2;
  }
  return plVar3;
}

/* ---- FUNC 000081E0 FUN_1800081e0 (15 bytes) ---- */

void FUN_1800081e0(longlong *param_1,longlong *param_2)

{
  void *pvVar1;
  void *pvVar2;
  
  do {
    if (param_1 == param_2) {
      return;
    }
    if (0xf < (ulonglong)param_1[3]) {
      pvVar1 = (void *)*param_1;
      pvVar2 = pvVar1;
      if ((0xfff < param_1[3] + 1U) &&
         (pvVar2 = *(void **)((longlong)pvVar1 + -8),
         0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar2)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      operator_delete(pvVar2);
    }
    param_1[2] = 0;
    param_1[3] = 0xf;
    *(undefined1 *)param_1 = 0;
    param_1 = param_1 + 4;
  } while( true );
}

/* ---- FUNC 000081EF FUN_1800081ef (110 bytes) ---- */

void FUN_1800081ef(longlong *param_1,longlong *param_2)

{
  void *pvVar1;
  void *pvVar2;
  
  do {
    if (0xf < (ulonglong)param_1[3]) {
      pvVar1 = (void *)*param_1;
      pvVar2 = pvVar1;
      if ((0xfff < param_1[3] + 1U) &&
         (pvVar2 = *(void **)((longlong)pvVar1 + -8),
         0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar2)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      operator_delete(pvVar2);
    }
    param_1[2] = 0;
    param_1[3] = 0xf;
    *(undefined1 *)param_1 = 0;
    param_1 = param_1 + 4;
    if (param_1 == param_2) {
      return;
    }
  } while( true );
}

/* ---- FUNC 0000825D FUN_18000825d (1 bytes) ---- */

void FUN_18000825d(void)

{
  return;
}

/* ---- FUNC 0000825E _invalid_parameter_noinfo_noreturn (6 bytes) ---- */

void __cdecl _invalid_parameter_noinfo_noreturn(void)

{
                    /* WARNING: Subroutine does not return */
  _invalid_parameter_noinfo_noreturn();
}

/* ---- FUNC 00008270 FUN_180008270 (435 bytes) ---- */

undefined8 * FUN_180008270(longlong *param_1,undefined8 *param_2,longlong *param_3)

{
  int iVar1;
  uint uVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong *plVar5;
  longlong *plVar6;
  longlong *plVar7;
  bool bVar8;
  longlong *local_68;
  longlong *plStack_60;
  longlong *local_58;
  uint uStack_50;
  undefined4 uStack_4c;
  
  plVar4 = (longlong *)*param_1;
  local_58 = (longlong *)plVar4[1];
  uStack_50 = 0;
  plVar5 = plVar4;
  if (*(char *)((longlong)local_58 + 0x19) == '\0') {
    iVar1 = *(int *)(*param_3 + 4);
    plVar3 = local_58;
    do {
      local_58 = plVar3;
      uVar2 = FUN_180007ea0((undefined8 *)
                            ((longlong)*(int *)(plVar3[4] + 4) + (longlong)(plVar3 + 4)),
                            (undefined8 *)((longlong)iVar1 + (longlong)param_3));
      bVar8 = (char)uVar2 == '\0';
      if (bVar8) {
        plVar7 = (longlong *)*plVar3;
        plVar5 = plVar3;
      }
      else {
        plVar7 = (longlong *)plVar3[2];
      }
      uStack_50 = (uint)bVar8;
      plVar3 = plVar7;
    } while (*(char *)((longlong)plVar7 + 0x19) == '\0');
  }
  if ((*(char *)((longlong)plVar5 + 0x19) == '\0') &&
     (uVar2 = FUN_180007ea0((undefined8 *)((longlong)*(int *)(*param_3 + 4) + (longlong)param_3),
                            (undefined8 *)
                            ((longlong)*(int *)(plVar5[4] + 4) + (longlong)(plVar5 + 4))),
     (char)uVar2 == '\0')) {
    *param_2 = plVar5;
    *(undefined1 *)(param_2 + 1) = 0;
    return param_2;
  }
  if (param_1[1] != 0x333333333333333) {
    plStack_60 = (longlong *)0x0;
    local_68 = param_1;
    plVar3 = operator_new(0x50);
    plVar5 = plVar3 + 4;
    *plVar5 = (longlong)&DAT_1800537c8;
    plVar3[5] = 0;
    plVar3[6] = 0;
    plVar3[7] = 0;
    plVar3[8] = 0xf;
    *(undefined1 *)(plVar3 + 5) = 0;
    plVar7 = (longlong *)((longlong)*(int *)(*param_3 + 4) + (longlong)param_3);
    plVar5 = (longlong *)((longlong)*(int *)(*plVar5 + 4) + (longlong)plVar5);
    if (plVar5 != plVar7) {
      plVar6 = plVar7;
      if (0xf < (ulonglong)plVar7[3]) {
        plVar6 = (longlong *)*plVar7;
      }
      plStack_60 = plVar3;
      FUN_18000ad20(plVar5,plVar6,plVar7[2]);
    }
    *(int *)(plVar3 + 9) = (int)param_3[5];
    *plVar3 = (longlong)plVar4;
    plVar3[1] = (longlong)plVar4;
    plVar3[2] = (longlong)plVar4;
    *(undefined2 *)(plVar3 + 3) = 0;
    plStack_60 = (longlong *)CONCAT44(uStack_4c,uStack_50);
    local_68 = local_58;
    plVar4 = FUN_18000a930(param_1,(longlong *)&local_68,plVar3);
    *param_2 = plVar4;
    *(undefined1 *)(param_2 + 1) = 1;
    return param_2;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18000ac90();
}

/* ---- FUNC 00008430 FUN_180008430 (207 bytes) ---- */

longlong * FUN_180008430(longlong *param_1,longlong *param_2,longlong *param_3)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *local_38;
  longlong *local_30;
  longlong local_28;
  longlong *local_18;
  longlong lStack_10;
  
  plVar2 = FUN_180008940(param_1,(longlong *)&local_38,param_2,param_3);
  local_18 = (longlong *)*plVar2;
  lStack_10 = plVar2[1];
  local_28 = plVar2[2];
  if ((char)local_28 == '\0') {
    if (param_1[1] == 0x333333333333333) {
                    /* WARNING: Subroutine does not return */
      FUN_18000ac90();
    }
    lVar1 = *param_1;
    local_30 = (longlong *)0x0;
    local_38 = param_1;
    plVar2 = operator_new(0x50);
    local_30 = plVar2;
    FUN_180009090(plVar2 + 4,param_3);
    *plVar2 = lVar1;
    plVar2[1] = lVar1;
    plVar2[2] = lVar1;
    *(undefined2 *)(plVar2 + 3) = 0;
    local_18 = FUN_18000a930(param_1,(longlong *)&local_18,plVar2);
  }
  return local_18;
}

/* ---- FUNC 00008500 FUN_180008500 (506 bytes) ---- */

undefined8 * FUN_180008500(longlong *param_1,longlong *param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  longlong lVar2;
  void *pvVar3;
  undefined8 uVar4;
  longlong *plVar5;
  ulonglong uVar6;
  longlong *plVar7;
  void *pvVar8;
  longlong *plVar9;
  longlong lVar10;
  ulonglong uVar11;
  __uint64 _Var12;
  ulonglong uVar13;
  longlong *plVar14;
  
  lVar2 = *param_1;
  lVar10 = param_1[1] - lVar2 >> 5;
  if (lVar10 == 0x7ffffffffffffff) {
                    /* WARNING: Subroutine does not return */
    FUN_18000ad00();
  }
  uVar11 = lVar10 + 1;
  uVar6 = param_1[2] - lVar2 >> 5;
  if (0x7ffffffffffffff - (uVar6 >> 1) < uVar6) {
    _Var12 = 0xffffffffffffffe0;
    plVar5 = (longlong *)FUN_180007f10(0xffffffffffffffe0);
  }
  else {
    uVar6 = (uVar6 >> 1) + uVar6;
    uVar13 = uVar11;
    if (uVar11 <= uVar6) {
      uVar13 = uVar6;
    }
    if (0x7ffffffffffffff < uVar13) {
                    /* WARNING: Subroutine does not return */
      FUN_18000ac70();
    }
    _Var12 = uVar13 << 5;
    if (_Var12 < 0x1000) {
      if (_Var12 == 0) {
        plVar5 = (longlong *)0x0;
      }
      else {
        plVar5 = operator_new(_Var12);
      }
    }
    else {
      plVar5 = (longlong *)FUN_180007f10(_Var12);
    }
  }
  puVar1 = (undefined8 *)(((longlong)param_2 - lVar2 & 0xffffffffffffffe0U) + (longlong)plVar5);
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  uVar4 = param_3[1];
  *puVar1 = *param_3;
  puVar1[1] = uVar4;
  uVar4 = param_3[3];
  puVar1[2] = param_3[2];
  puVar1[3] = uVar4;
  param_3[2] = 0;
  param_3[3] = 0xf;
  *(undefined1 *)param_3 = 0;
  plVar9 = (longlong *)param_1[1];
  plVar7 = (longlong *)*param_1;
  plVar14 = plVar5;
  if (param_2 != plVar9) {
    FUN_180008dd0(plVar7,param_2,plVar5);
    plVar9 = (longlong *)param_1[1];
    plVar7 = param_2;
    plVar14 = puVar1 + 4;
  }
  FUN_180008dd0(plVar7,plVar9,plVar14);
  if ((longlong *)*param_1 != (longlong *)0x0) {
    FUN_1800081e0((longlong *)*param_1,(longlong *)param_1[1]);
    pvVar3 = (void *)*param_1;
    pvVar8 = pvVar3;
    if ((0xfff < (param_1[2] - (longlong)pvVar3 & 0xffffffffffffffe0U)) &&
       (pvVar8 = *(void **)((longlong)pvVar3 + -8),
       0x1f < (ulonglong)((longlong)pvVar3 + (-8 - (longlong)pvVar8)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar8);
  }
  *param_1 = (longlong)plVar5;
  param_1[1] = (longlong)(plVar5 + uVar11 * 4);
  param_1[2] = (longlong)plVar5 + _Var12;
  return puVar1;
}

/* ---- FUNC 00008700 FUN_180008700 (44 bytes) ---- */

longlong * FUN_180008700(longlong *param_1,longlong *param_2,longlong *param_3)

{
  int iVar1;
  uint uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  
  puVar6 = (undefined8 *)*param_1;
  puVar3 = (undefined8 *)puVar6[1];
  puVar7 = puVar6;
  if (*(char *)((longlong)puVar3 + 0x19) == '\0') {
    puVar8 = (undefined8 *)((longlong)*(int *)(*param_3 + 4) + (longlong)param_3);
    puVar5 = puVar6;
    puVar4 = puVar3;
    do {
      puVar6 = puVar4;
      iVar1 = *(int *)(puVar6[4] + 4);
      uVar2 = FUN_180007ea0((undefined8 *)((longlong)puVar6 + (longlong)iVar1 + 0x20),puVar8);
      if ((char)uVar2 == '\0') {
        if ((*(char *)((longlong)puVar7 + 0x19) != '\0') &&
           (uVar2 = FUN_180007ea0(puVar8,(undefined8 *)((longlong)puVar6 + (longlong)iVar1 + 0x20)),
           (char)uVar2 != '\0')) {
          puVar7 = puVar6;
        }
        puVar4 = (undefined8 *)*puVar6;
      }
      else {
        puVar4 = (undefined8 *)puVar6[2];
        puVar6 = puVar5;
      }
      puVar5 = puVar6;
    } while (*(char *)((longlong)puVar4 + 0x19) == '\0');
  }
  if (*(char *)((longlong)puVar7 + 0x19) == '\0') {
    puVar3 = (undefined8 *)*puVar7;
  }
  if (*(char *)((longlong)puVar3 + 0x19) == '\0') {
    iVar1 = *(int *)(*param_3 + 4);
    do {
      uVar2 = FUN_180007ea0((undefined8 *)((longlong)iVar1 + (longlong)param_3),
                            (undefined8 *)
                            ((longlong)puVar3 + (longlong)*(int *)(puVar3[4] + 4) + 0x20));
      if ((char)uVar2 == '\0') {
        puVar4 = (undefined8 *)puVar3[2];
      }
      else {
        puVar4 = (undefined8 *)*puVar3;
        puVar7 = puVar3;
      }
      puVar3 = puVar4;
    } while (*(char *)((longlong)puVar4 + 0x19) == '\0');
  }
  *param_2 = (longlong)puVar6;
  param_2[1] = (longlong)puVar7;
  return param_2;
}

/* ---- FUNC 0000872C FUN_18000872c (102 bytes) ---- */

void FUN_18000872c(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  int iVar1;
  uint uVar2;
  longlong in_RAX;
  undefined8 *unaff_RBX;
  undefined8 *unaff_RBP;
  undefined8 *puVar3;
  undefined8 *unaff_RSI;
  undefined8 *unaff_RDI;
  longlong *unaff_R12;
  undefined8 *unaff_R13;
  undefined8 *puVar4;
  
  puVar4 = (undefined8 *)(*(int *)(in_RAX + 4) + param_3);
  do {
    puVar3 = unaff_RDI;
    iVar1 = *(int *)(puVar3[4] + 4);
    uVar2 = FUN_180007ea0((undefined8 *)((longlong)puVar3 + (longlong)iVar1 + 0x20),puVar4);
    if ((char)uVar2 == '\0') {
      if (*(char *)((longlong)unaff_RSI + 0x19) != '\0') {
        uVar2 = FUN_180007ea0(puVar4,(undefined8 *)((longlong)puVar3 + (longlong)iVar1 + 0x20));
        if ((char)uVar2 != '\0') {
          unaff_RSI = puVar3;
        }
      }
      unaff_RDI = (undefined8 *)*puVar3;
    }
    else {
      unaff_RDI = (undefined8 *)puVar3[2];
      puVar3 = unaff_RBP;
    }
    unaff_RBP = puVar3;
  } while (*(char *)((longlong)unaff_RDI + 0x19) == '\0');
  if (*(char *)((longlong)unaff_RSI + 0x19) == '\0') {
    unaff_RBX = (undefined8 *)*unaff_RSI;
  }
  if (*(char *)((longlong)unaff_RBX + 0x19) == '\0') {
    iVar1 = *(int *)(*unaff_R12 + 4);
    do {
      uVar2 = FUN_180007ea0((undefined8 *)((longlong)iVar1 + (longlong)unaff_R12),
                            (undefined8 *)
                            ((longlong)unaff_RBX + (longlong)*(int *)(unaff_RBX[4] + 4) + 0x20));
      if ((char)uVar2 == '\0') {
        puVar4 = (undefined8 *)unaff_RBX[2];
      }
      else {
        puVar4 = (undefined8 *)*unaff_RBX;
        unaff_RSI = unaff_RBX;
      }
      unaff_RBX = puVar4;
    } while (*(char *)((longlong)puVar4 + 0x19) == '\0');
  }
  *unaff_R13 = puVar3;
  unaff_R13[1] = unaff_RSI;
  return;
}

/* ---- FUNC 00008792 FUN_180008792 (103 bytes) ---- */

void FUN_180008792(void)

{
  int iVar1;
  uint uVar2;
  undefined8 *unaff_RBX;
  undefined8 *puVar3;
  undefined8 unaff_RBP;
  undefined8 *unaff_RSI;
  longlong *unaff_R12;
  undefined8 *unaff_R13;
  
  if (*(char *)((longlong)unaff_RSI + 0x19) == '\0') {
    unaff_RBX = (undefined8 *)*unaff_RSI;
  }
  if (*(char *)((longlong)unaff_RBX + 0x19) == '\0') {
    iVar1 = *(int *)(*unaff_R12 + 4);
    do {
      uVar2 = FUN_180007ea0((undefined8 *)((longlong)iVar1 + (longlong)unaff_R12),
                            (undefined8 *)
                            ((longlong)unaff_RBX + (longlong)*(int *)(unaff_RBX[4] + 4) + 0x20));
      if ((char)uVar2 == '\0') {
        puVar3 = (undefined8 *)unaff_RBX[2];
      }
      else {
        puVar3 = (undefined8 *)*unaff_RBX;
        unaff_RSI = unaff_RBX;
      }
      unaff_RBX = puVar3;
    } while (*(char *)((longlong)puVar3 + 0x19) == '\0');
  }
  *unaff_R13 = unaff_RBP;
  unaff_R13[1] = unaff_RSI;
  return;
}

/* ---- FUNC 00008800 FUN_180008800 (31 bytes) ---- */

void FUN_180008800(undefined8 param_1,undefined8 param_2,longlong *param_3)

{
  char cVar1;
  longlong *plVar2;
  
  cVar1 = *(char *)((longlong)param_3 + 0x19);
  while (cVar1 == '\0') {
    FUN_180008800(param_1,param_2,(longlong *)param_3[2]);
    plVar2 = (longlong *)*param_3;
    FUN_180009900((longlong)(param_3 + 4));
    operator_delete(param_3);
    param_3 = plVar2;
    cVar1 = *(char *)((longlong)plVar2 + 0x19);
  }
  return;
}

/* ---- FUNC 0000881F FUN_18000881f (71 bytes) ---- */

void FUN_18000881f(void)

{
  longlong *plVar1;
  longlong *unaff_RBX;
  undefined8 unaff_RBP;
  undefined8 unaff_RSI;
  
  do {
    FUN_180008800(unaff_RBP,unaff_RSI,(longlong *)unaff_RBX[2]);
    plVar1 = (longlong *)*unaff_RBX;
    FUN_180009900((longlong)(unaff_RBX + 4));
    operator_delete(unaff_RBX);
    unaff_RBX = plVar1;
  } while (*(char *)((longlong)plVar1 + 0x19) == '\0');
  return;
}

/* ---- FUNC 00008866 FUN_180008866 (16 bytes) ---- */

void FUN_180008866(void)

{
  return;
}

/* ---- FUNC 00008880 FUN_180008880 (22 bytes) ---- */

undefined8 * FUN_180008880(longlong *param_1,longlong *param_2)

{
  int iVar1;
  undefined8 *puVar2;
  uint uVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  
  puVar2 = (undefined8 *)*param_1;
  puVar4 = puVar2;
  if (*(char *)((longlong)puVar2[1] + 0x19) == '\0') {
    iVar1 = *(int *)(*param_2 + 4);
    puVar5 = (undefined8 *)puVar2[1];
    do {
      uVar3 = FUN_180007ea0((undefined8 *)
                            ((longlong)puVar5 + (longlong)*(int *)(puVar5[4] + 4) + 0x20),
                            (undefined8 *)((longlong)iVar1 + (longlong)param_2));
      if ((char)uVar3 == '\0') {
        puVar6 = (undefined8 *)*puVar5;
        puVar4 = puVar5;
      }
      else {
        puVar6 = (undefined8 *)puVar5[2];
      }
      puVar5 = puVar6;
    } while (*(char *)((longlong)puVar6 + 0x19) == '\0');
  }
  if ((*(char *)((longlong)puVar4 + 0x19) != '\0') ||
     (uVar3 = FUN_180007ea0((undefined8 *)((longlong)*(int *)(*param_2 + 4) + (longlong)param_2),
                            (undefined8 *)
                            ((longlong)puVar4 + (longlong)*(int *)(puVar4[4] + 4) + 0x20)),
     (char)uVar3 != '\0')) {
    puVar4 = puVar2;
  }
  return puVar4;
}

/* ---- FUNC 00008896 FUN_180008896 (21 bytes) ---- */

void FUN_180008896(undefined8 param_1,longlong *param_2)

{
  int iVar1;
  uint uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 *unaff_RSI;
  longlong *unaff_R14;
  
  if (*(char *)((longlong)unaff_RSI[1] + 0x19) == '\0') {
    iVar1 = *(int *)(*param_2 + 4);
    puVar3 = (undefined8 *)unaff_RSI[1];
    do {
      uVar2 = FUN_180007ea0((undefined8 *)
                            ((longlong)puVar3 + (longlong)*(int *)(puVar3[4] + 4) + 0x20),
                            (undefined8 *)((longlong)iVar1 + (longlong)param_2));
      if ((char)uVar2 == '\0') {
        puVar4 = (undefined8 *)*puVar3;
        unaff_RSI = puVar3;
      }
      else {
        puVar4 = (undefined8 *)puVar3[2];
      }
      puVar3 = puVar4;
    } while (*(char *)((longlong)puVar4 + 0x19) == '\0');
  }
  if (*(char *)((longlong)unaff_RSI + 0x19) == '\0') {
    FUN_180007ea0((undefined8 *)((longlong)*(int *)(*unaff_R14 + 4) + (longlong)unaff_R14),
                  (undefined8 *)((longlong)unaff_RSI + (longlong)*(int *)(unaff_RSI[4] + 4) + 0x20))
    ;
  }
  return;
}

/* ---- FUNC 000088AB FUN_1800088ab (71 bytes) ---- */

void FUN_1800088ab(undefined8 param_1,longlong param_2)

{
  int iVar1;
  uint uVar2;
  longlong in_RAX;
  undefined8 *unaff_RBX;
  undefined8 *puVar3;
  undefined8 *unaff_RDI;
  longlong *unaff_R14;
  
  iVar1 = *(int *)(in_RAX + 4);
  do {
    uVar2 = FUN_180007ea0((undefined8 *)
                          ((longlong)unaff_RBX + (longlong)*(int *)(unaff_RBX[4] + 4) + 0x20),
                          (undefined8 *)(iVar1 + param_2));
    if ((char)uVar2 == '\0') {
      puVar3 = (undefined8 *)*unaff_RBX;
      unaff_RDI = unaff_RBX;
    }
    else {
      puVar3 = (undefined8 *)unaff_RBX[2];
    }
    unaff_RBX = puVar3;
  } while (*(char *)((longlong)puVar3 + 0x19) == '\0');
  if (*(char *)((longlong)unaff_RDI + 0x19) == '\0') {
    FUN_180007ea0((undefined8 *)((longlong)*(int *)(*unaff_R14 + 4) + (longlong)unaff_R14),
                  (undefined8 *)((longlong)unaff_RDI + (longlong)*(int *)(unaff_RDI[4] + 4) + 0x20))
    ;
  }
  return;
}

/* ---- FUNC 000088F2 FUN_1800088f2 (11 bytes) ---- */

void FUN_1800088f2(void)

{
  longlong unaff_RDI;
  longlong *unaff_R14;
  
  if (*(char *)(unaff_RDI + 0x19) == '\0') {
    FUN_180007ea0((undefined8 *)((longlong)*(int *)(*unaff_R14 + 4) + (longlong)unaff_R14),
                  (undefined8 *)
                  ((longlong)*(int *)(*(longlong *)(unaff_RDI + 0x20) + 4) + unaff_RDI + 0x20));
  }
  return;
}

/* ---- FUNC 000088FD FUN_1800088fd (57 bytes) ---- */

void FUN_1800088fd(void)

{
  longlong unaff_RDI;
  longlong *unaff_R14;
  
  FUN_180007ea0((undefined8 *)((longlong)*(int *)(*unaff_R14 + 4) + (longlong)unaff_R14),
                (undefined8 *)
                ((longlong)*(int *)(*(longlong *)(unaff_RDI + 0x20) + 4) + unaff_RDI + 0x20));
  return;
}

/* ---- FUNC 00008940 FUN_180008940 (711 bytes) ---- */

longlong * FUN_180008940(longlong *param_1,longlong *param_2,longlong *param_3,longlong *param_4)

{
  char cVar1;
  int iVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong *plVar5;
  uint uVar6;
  longlong *plVar7;
  longlong *plVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  longlong lVar11;
  bool bVar12;
  longlong *local_res8;
  longlong *local_48;
  uint uStack_40;
  undefined4 uStack_3c;
  
  plVar8 = (longlong *)*param_1;
  if (*(char *)((longlong)param_3 + 0x19) == '\0') {
    lVar11 = *param_4;
    if (param_3 == (longlong *)*plVar8) {
      uVar6 = FUN_180007ea0((undefined8 *)((longlong)*(int *)(lVar11 + 4) + (longlong)param_4),
                            (undefined8 *)
                            ((longlong)param_3 + (longlong)*(int *)(param_3[4] + 4) + 0x20));
      if ((char)uVar6 != '\0') {
        *param_2 = (longlong)param_3;
        *(undefined4 *)(param_2 + 1) = 1;
        *(undefined1 *)(param_2 + 2) = 0;
        return param_2;
      }
    }
    else {
      puVar9 = (undefined8 *)((longlong)param_3 + (longlong)*(int *)(param_3[4] + 4) + 0x20);
      puVar10 = (undefined8 *)((longlong)*(int *)(lVar11 + 4) + (longlong)param_4);
      uVar6 = FUN_180007ea0(puVar10,puVar9);
      if ((char)uVar6 == '\0') {
        uVar6 = FUN_180007ea0(puVar9,puVar10);
        if ((char)uVar6 == '\0') {
          *param_2 = (longlong)param_3;
          *(undefined1 *)(param_2 + 2) = 1;
          goto LAB_180008be7;
        }
        local_res8 = param_3;
        plVar7 = FUN_180009890((longlong *)&local_res8);
        lVar3 = *plVar7;
        if ((*(char *)(lVar3 + 0x19) != '\0') ||
           (uVar6 = FUN_180007ea0(puVar10,(undefined8 *)
                                          ((longlong)*(int *)(*(longlong *)(lVar3 + 0x20) + 4) +
                                          lVar3 + 0x20)), (char)uVar6 != '\0')) {
          cVar1 = *(char *)(param_3[2] + 0x19);
          *(undefined1 *)(param_2 + 2) = 0;
          if (cVar1 != '\0') {
            *param_2 = (longlong)param_3;
            *(undefined4 *)(param_2 + 1) = 0;
            return param_2;
          }
          *param_2 = lVar3;
          *(undefined4 *)(param_2 + 1) = 1;
          return param_2;
        }
      }
      else {
        plVar7 = (longlong *)*param_3;
        if (*(char *)((longlong)plVar7 + 0x19) == '\0') {
          cVar1 = *(char *)(plVar7[2] + 0x19);
          plVar4 = (longlong *)plVar7[2];
          while (cVar1 == '\0') {
            cVar1 = *(char *)(plVar4[2] + 0x19);
            plVar7 = plVar4;
            plVar4 = (longlong *)plVar4[2];
          }
        }
        else {
          cVar1 = *(char *)(param_3[1] + 0x19);
          plVar5 = (longlong *)param_3[1];
          plVar4 = param_3;
          while ((plVar7 = plVar5, cVar1 == '\0' && (plVar4 == (longlong *)*plVar7))) {
            cVar1 = *(char *)(plVar7[1] + 0x19);
            plVar5 = (longlong *)plVar7[1];
            plVar4 = plVar7;
          }
          if (*(char *)((longlong)plVar4 + 0x19) != '\0') {
            plVar7 = plVar4;
          }
        }
        uVar6 = FUN_180007ea0((undefined8 *)
                              ((longlong)plVar7 + (longlong)*(int *)(plVar7[4] + 4) + 0x20),puVar10)
        ;
        if ((char)uVar6 != '\0') {
          cVar1 = *(char *)(plVar7[2] + 0x19);
          *(undefined1 *)(param_2 + 2) = 0;
          if (cVar1 != '\0') {
            *param_2 = (longlong)plVar7;
            *(undefined4 *)(param_2 + 1) = 0;
            return param_2;
          }
          *param_2 = (longlong)param_3;
          *(undefined4 *)(param_2 + 1) = 1;
          return param_2;
        }
      }
    }
LAB_180008b15:
    local_48 = (longlong *)plVar8[1];
    uStack_40 = 0;
    if (*(char *)((longlong)local_48 + 0x19) == '\0') {
      iVar2 = *(int *)(lVar11 + 4);
      plVar7 = local_48;
      do {
        local_48 = plVar7;
        uVar6 = FUN_180007ea0((undefined8 *)
                              ((longlong)local_48 + (longlong)*(int *)(local_48[4] + 4) + 0x20),
                              (undefined8 *)((longlong)iVar2 + (longlong)param_4));
        bVar12 = (char)uVar6 == '\0';
        if (bVar12) {
          plVar7 = (longlong *)*local_48;
          plVar8 = local_48;
        }
        else {
          plVar7 = (longlong *)local_48[2];
        }
        uStack_40 = (uint)bVar12;
      } while (*(char *)((longlong)plVar7 + 0x19) == '\0');
    }
    if ((*(char *)((longlong)plVar8 + 0x19) == '\0') &&
       (uVar6 = FUN_180007ea0((undefined8 *)((longlong)*(int *)(*param_4 + 4) + (longlong)param_4),
                              (undefined8 *)
                              ((longlong)plVar8 + (longlong)*(int *)(plVar8[4] + 4) + 0x20)),
       (char)uVar6 == '\0')) {
      *param_2 = (longlong)plVar8;
      *(undefined4 *)(param_2 + 1) = 2;
      *(undefined1 *)(param_2 + 2) = 1;
    }
    else {
      *(undefined1 *)(param_2 + 2) = 0;
      *param_2 = (longlong)local_48;
      param_2[1] = CONCAT44(uStack_3c,uStack_40);
    }
  }
  else {
    if (*(char *)(plVar8[1] + 0x19) == '\0') {
      lVar11 = *param_4;
      uVar6 = FUN_180007ea0((undefined8 *)
                            ((longlong)*(int *)(*(longlong *)(plVar8[2] + 0x20) + 4) +
                            plVar8[2] + 0x20),
                            (undefined8 *)((longlong)*(int *)(lVar11 + 4) + (longlong)param_4));
      if ((char)uVar6 == '\0') goto LAB_180008b15;
    }
    *param_2 = plVar8[2];
    *(undefined1 *)(param_2 + 2) = 0;
LAB_180008be7:
    *(undefined4 *)(param_2 + 1) = 0;
  }
  return param_2;
}

/* ---- FUNC 00008C10 FUN_180008c10 (432 bytes) ---- */

undefined8 * FUN_180008c10(longlong *param_1,undefined8 *param_2,longlong *param_3)

{
  int iVar1;
  uint uVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong *plVar5;
  longlong *plVar6;
  longlong *plVar7;
  bool bVar8;
  longlong *local_68;
  longlong *plStack_60;
  longlong *local_58;
  uint uStack_50;
  undefined4 uStack_4c;
  
  plVar4 = (longlong *)*param_1;
  local_58 = (longlong *)plVar4[1];
  uStack_50 = 0;
  plVar5 = plVar4;
  if (*(char *)((longlong)local_58 + 0x19) == '\0') {
    iVar1 = *(int *)(*param_3 + 4);
    plVar3 = local_58;
    do {
      local_58 = plVar3;
      uVar2 = FUN_180007ea0((undefined8 *)
                            ((longlong)*(int *)(plVar3[4] + 4) + (longlong)(plVar3 + 4)),
                            (undefined8 *)((longlong)iVar1 + (longlong)param_3));
      bVar8 = (char)uVar2 == '\0';
      if (bVar8) {
        plVar7 = (longlong *)*plVar3;
        plVar5 = plVar3;
      }
      else {
        plVar7 = (longlong *)plVar3[2];
      }
      uStack_50 = (uint)bVar8;
      plVar3 = plVar7;
    } while (*(char *)((longlong)plVar7 + 0x19) == '\0');
  }
  if ((*(char *)((longlong)plVar5 + 0x19) == '\0') &&
     (uVar2 = FUN_180007ea0((undefined8 *)((longlong)*(int *)(*param_3 + 4) + (longlong)param_3),
                            (undefined8 *)
                            ((longlong)*(int *)(plVar5[4] + 4) + (longlong)(plVar5 + 4))),
     (char)uVar2 == '\0')) {
    *param_2 = plVar5;
    *(undefined1 *)(param_2 + 1) = 0;
    return param_2;
  }
  if (param_1[1] != 0x333333333333333) {
    plStack_60 = (longlong *)0x0;
    local_68 = param_1;
    plVar3 = operator_new(0x50);
    plVar5 = plVar3 + 4;
    *plVar5 = (longlong)&DAT_1800537c8;
    plVar3[5] = 0;
    plVar3[6] = 0;
    plVar3[7] = 0;
    plVar3[8] = 0xf;
    *(undefined1 *)(plVar3 + 5) = 0;
    plVar7 = (longlong *)((longlong)*(int *)(*param_3 + 4) + (longlong)param_3);
    plVar5 = (longlong *)((longlong)*(int *)(*plVar5 + 4) + (longlong)plVar5);
    if (plVar5 != plVar7) {
      plVar6 = plVar7;
      if (0xf < (ulonglong)plVar7[3]) {
        plVar6 = (longlong *)*plVar7;
      }
      plStack_60 = plVar3;
      FUN_18000ad20(plVar5,plVar6,plVar7[2]);
    }
    *(undefined4 *)(plVar3 + 9) = 0;
    *plVar3 = (longlong)plVar4;
    plVar3[1] = (longlong)plVar4;
    plVar3[2] = (longlong)plVar4;
    *(undefined2 *)(plVar3 + 3) = 0;
    plStack_60 = (longlong *)CONCAT44(uStack_4c,uStack_50);
    local_68 = local_58;
    plVar4 = FUN_18000a930(param_1,(longlong *)&local_68,plVar3);
    *param_2 = plVar4;
    *(undefined1 *)(param_2 + 1) = 1;
    return param_2;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18000ac90();
}

/* ---- FUNC 00008DD0 FUN_180008dd0 (121 bytes) ---- */

longlong * FUN_180008dd0(longlong *param_1,longlong *param_2,longlong *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  
  if (param_1 != param_2) {
    lVar3 = (longlong)param_3 - (longlong)param_1;
    plVar4 = param_1 + 3;
    do {
      *param_3 = 0;
      param_3[1] = 0;
      *(undefined8 *)(lVar3 + -0x28 + (longlong)(plVar4 + 4)) = 0;
      plVar1 = plVar4 + 1;
      *(undefined8 *)((longlong)plVar4 + lVar3) = 0;
      lVar2 = plVar4[-2];
      *param_3 = plVar4[-3];
      param_3[1] = lVar2;
      lVar2 = *plVar4;
      param_3[2] = plVar4[-1];
      param_3[3] = lVar2;
      plVar4[-1] = 0;
      param_3 = param_3 + 4;
      *plVar4 = 0xf;
      *(undefined1 *)(plVar4 + -3) = 0;
      plVar4 = plVar4 + 4;
    } while (plVar1 != param_2);
  }
  FUN_1800081e0(param_3,param_3);
  return param_3;
}

/* ---- FUNC 00008E50 _Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_> (92 bytes) ---- */

/* public: __cdecl std::_Tree<class std::_Tmap_traits<class CAPString,int,struct std::less<class
   CAPString>,class std::allocator<struct std::pair<class CAPString const ,int> >,0> >::_Tree<class
   std::_Tmap_traits<class CAPString,int,struct std::less<class CAPString>,class
   std::allocator<struct std::pair<class CAPString const ,int> >,0> >(class std::_Tree<class
   std::_Tmap_traits<class CAPString,int,struct std::less<class CAPString>,class
   std::allocator<struct std::pair<class CAPString const ,int> >,0> > && __ptr64) __ptr64 */

_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
* __thiscall
std::
_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
::
_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
          (_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
           *this,_Tree<class_std::_Tmap_traits<class_CAPString,int,struct_std::less<class_CAPString>,class_std::allocator<struct_std::pair<class_CAPString_const_,int>_>,0>_>
                 *param_1)

{
  undefined8 uVar1;
  void *pvVar2;
  
                    /* 0x8e50  2
                       ??0?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@QEAA@$$QEAV01@@Z
                       0x8e50  3
                       ??0?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@QEAA@$$QEAV01@AEBV?$allocator@U?$pair@$$CBVCAPString@@H@std@@@1@@Z
                       0x8e50  6
                       ??0?$map@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@@std@@QEAA@$$QEAV01@@Z
                       0x8e50  7
                       ??0?$map@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@@std@@QEAA@$$QEAV01@AEBV?$allocator@U?$pair@$$CBVCAPString@@H@std@@@1@@Z
                        */
  *(undefined8 *)this = 0;
  *(undefined8 *)(this + 8) = 0;
  pvVar2 = operator_new(0x50);
  *(void **)pvVar2 = pvVar2;
  *(void **)((longlong)pvVar2 + 8) = pvVar2;
  *(void **)((longlong)pvVar2 + 0x10) = pvVar2;
  *(undefined2 *)((longlong)pvVar2 + 0x18) = 0x101;
  *(void **)this = pvVar2;
  *(undefined8 *)this = *(undefined8 *)param_1;
  *(void **)param_1 = pvVar2;
  uVar1 = *(undefined8 *)(this + 8);
  *(undefined8 *)(this + 8) = *(undefined8 *)(param_1 + 8);
  *(undefined8 *)(param_1 + 8) = uVar1;
  return this;
}

/* ---- FUNC 00008EB0 _Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_> (55 bytes) ---- */

/* public: __cdecl std::_Tree<class std::_Tmap_traits<class CAPString,int,struct std::less<class
   CAPString>,class std::allocator<struct std::pair<class CAPString const ,int> >,0> >::_Tree<class
   std::_Tmap_traits<class CAPString,int,struct std::less<class CAPString>,class
   std::allocator<struct std::pair<class CAPString const ,int> >,0> >(struct std::less<class
   CAPString> const & __ptr64) __ptr64 */

_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
* __thiscall
std::
_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
::
_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
          (_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
           *this,less<CAPString> *param_1)

{
  void *pvVar1;
  
                    /* 0x8eb0  4
                       ??0?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@VCAPString@@@1@@Z
                       0x8eb0  5
                       ??0?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@VCAPString@@@1@AEBV?$allocator@U?$pair@$$CBVCAPString@@H@std@@@1@@Z
                       0x8eb0  8
                       ??0?$map@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@@std@@QEAA@AEBU?$less@VCAPString@@@1@@Z
                       0x8eb0  9
                       ??0?$map@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@@std@@QEAA@AEBU?$less@VCAPString@@@1@AEBV?$allocator@U?$pair@$$CBVCAPString@@H@std@@@1@@Z
                       0x8eb0  12
                       ??0?$map@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@@std@@QEAA@AEBV?$allocator@U?$pair@$$CBVCAPString@@H@std@@@1@@Z
                       0x8eb0  17
                       ??0?$map@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@@std@@QEAA@XZ
                        */
  *(undefined8 *)this = 0;
  *(undefined8 *)(this + 8) = 0;
  pvVar1 = operator_new(0x50);
  *(void **)pvVar1 = pvVar1;
  *(void **)((longlong)pvVar1 + 8) = pvVar1;
  *(void **)((longlong)pvVar1 + 0x10) = pvVar1;
  *(undefined2 *)((longlong)pvVar1 + 0x18) = 0x101;
  *(void **)this = pvVar1;
  return this;
}

/* ---- FUNC 00008EF0 map<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>_> (89 bytes) ---- */

/* public: __cdecl std::map<class CAPString,int,struct std::less<class CAPString>,class
   std::allocator<struct std::pair<class CAPString const ,int> > >::map<class CAPString,int,struct
   std::less<class CAPString>,class std::allocator<struct std::pair<class CAPString const ,int> >
   >(class std::map<class CAPString,int,struct std::less<class CAPString>,class
   std::allocator<struct std::pair<class CAPString const ,int> > > const & __ptr64) __ptr64 */

map<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>_> *
__thiscall
std::map<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>_>::
map<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>_>
          (map<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>_>
           *this,map<class_CAPString,int,struct_std::less<class_CAPString>,class_std::allocator<struct_std::pair<class_CAPString_const_,int>_>_>
                 *param_1)

{
  void *pvVar1;
  undefined8 in_R8;
  undefined8 in_R9;
  
                    /* 0x8ef0  10
                       ??0?$map@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@@std@@QEAA@AEBV01@@Z
                       0x8ef0  11
                       ??0?$map@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@@std@@QEAA@AEBV01@AEBV?$allocator@U?$pair@$$CBVCAPString@@H@std@@@1@@Z
                        */
  *(undefined8 *)this = 0;
  *(undefined8 *)(this + 8) = 0;
  pvVar1 = operator_new(0x50);
  *(void **)pvVar1 = pvVar1;
  *(void **)((longlong)pvVar1 + 8) = pvVar1;
  *(void **)((longlong)pvVar1 + 0x10) = pvVar1;
  *(undefined2 *)((longlong)pvVar1 + 0x18) = 0x101;
  *(void **)this = pvVar1;
  FUN_180007f50((longlong *)this,(longlong *)param_1,in_R8,in_R9);
  return this;
}

/* ---- FUNC 00008F50 map<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>_> (309 bytes) ---- */

/* public: __cdecl std::map<class CAPString,int,struct std::less<class CAPString>,class
   std::allocator<struct std::pair<class CAPString const ,int> > >::map<class CAPString,int,struct
   std::less<class CAPString>,class std::allocator<struct std::pair<class CAPString const ,int> >
   >(class std::initializer_list<struct std::pair<class CAPString const ,int> >) __ptr64 */

map<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>_> *
__thiscall
std::map<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>_>::
map<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>_>
          (map<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>_>
           *this,undefined8 *param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong *plVar5;
  longlong local_68;
  longlong lStack_60;
  longlong local_48;
  longlong local_40 [3];
  
                    /* 0x8f50  13
                       ??0?$map@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@@std@@QEAA@V?$initializer_list@U?$pair@$$CBVCAPString@@H@std@@@1@@Z
                       0x8f50  14
                       ??0?$map@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@@std@@QEAA@V?$initializer_list@U?$pair@$$CBVCAPString@@H@std@@@1@AEBU?$less@VCAPString@@@1@@Z
                       0x8f50  15
                       ??0?$map@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@@std@@QEAA@V?$initializer_list@U?$pair@$$CBVCAPString@@H@std@@@1@AEBU?$less@VCAPString@@@1@AEBV?$allocator@U?$pair@$$CBVCAPString@@H@std@@@1@@Z
                       0x8f50  16
                       ??0?$map@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@@std@@QEAA@V?$initializer_list@U?$pair@$$CBVCAPString@@H@std@@@1@AEBV?$allocator@U?$pair@$$CBVCAPString@@H@std@@@1@@Z
                        */
  *(undefined8 *)this = 0;
  *(undefined8 *)(this + 8) = 0;
  plVar3 = operator_new(0x50);
  *plVar3 = (longlong)plVar3;
  plVar3[1] = (longlong)plVar3;
  plVar3[2] = (longlong)plVar3;
  *(undefined2 *)(plVar3 + 3) = 0x101;
  *(longlong **)this = plVar3;
  plVar5 = (longlong *)*param_2;
  plVar1 = (longlong *)param_2[1];
  do {
    if (plVar5 == plVar1) {
      return this;
    }
    plVar4 = FUN_180008940((longlong *)this,local_40,plVar3,plVar5);
    local_68 = *plVar4;
    lStack_60 = plVar4[1];
    local_48 = plVar4[2];
    if ((char)local_48 == '\0') {
      if (*(longlong *)(this + 8) == 0x333333333333333) {
                    /* WARNING: Subroutine does not return */
        FUN_18000ac90();
      }
      lVar2 = *(longlong *)this;
      plVar4 = operator_new(0x50);
      FUN_180009090(plVar4 + 4,plVar5);
      *plVar4 = lVar2;
      plVar4[1] = lVar2;
      plVar4[2] = lVar2;
      *(undefined2 *)(plVar4 + 3) = 0;
      FUN_18000a930((longlong *)this,&local_68,plVar4);
    }
    plVar5 = plVar5 + 6;
  } while( true );
}

/* ---- FUNC 00009090 FUN_180009090 (140 bytes) ---- */

longlong * FUN_180009090(longlong *param_1,longlong *param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  
  *param_1 = (longlong)&DAT_1800537c8;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0xf;
  *(undefined1 *)(param_1 + 1) = 0;
  plVar3 = (longlong *)((longlong)*(int *)(*param_2 + 4) + (longlong)param_2);
  plVar1 = (longlong *)((longlong)*(int *)(*param_1 + 4) + (longlong)param_1);
  if (plVar1 != plVar3) {
    plVar2 = plVar3;
    if (0xf < (ulonglong)plVar3[3]) {
      plVar2 = (longlong *)*plVar3;
    }
    FUN_18000ad20(plVar1,plVar2,plVar3[2]);
  }
  *(int *)(param_1 + 5) = (int)param_2[5];
  return param_1;
}

/* ---- FUNC 00009120 CApwnEOStatus (119 bytes) ---- */

/* public: __cdecl CApwnEOStatus::CApwnEOStatus(class CApwnEOStatus const & __ptr64) __ptr64 */

CApwnEOStatus * __thiscall CApwnEOStatus::CApwnEOStatus(CApwnEOStatus *this,CApwnEOStatus *param_1)

{
  CApwnEOStatus *pCVar1;
  void *pvVar2;
  undefined8 in_R8;
  undefined8 in_R9;
  
                    /* 0x9120  19  ??0CApwnEOStatus@@QEAA@AEBV0@@Z */
  pCVar1 = this + 8;
  *(longlong *)pCVar1 = 0;
  *(undefined8 *)(this + 0x10) = 0;
  pvVar2 = operator_new(0x50);
  *(void **)pvVar2 = pvVar2;
  *(void **)((longlong)pvVar2 + 8) = pvVar2;
  *(void **)((longlong)pvVar2 + 0x10) = pvVar2;
  *(undefined2 *)((longlong)pvVar2 + 0x18) = 0x101;
  *(void **)pCVar1 = pvVar2;
  FUN_180007f50((longlong *)pCVar1,(longlong *)(param_1 + 8),in_R8,in_R9);
  *(undefined ***)this = vftable;
  return this;
}

/* ---- FUNC 000091A0 CApwnEOStatus (83 bytes) ---- */

/* public: __cdecl CApwnEOStatus::CApwnEOStatus(void) __ptr64 */

CApwnEOStatus * __thiscall CApwnEOStatus::CApwnEOStatus(CApwnEOStatus *this)

{
  void *pvVar1;
  
                    /* 0x91a0  20  ??0CApwnEOStatus@@QEAA@XZ */
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)(this + 0x10) = 0;
  pvVar1 = operator_new(0x50);
  *(void **)pvVar1 = pvVar1;
  *(void **)((longlong)pvVar1 + 8) = pvVar1;
  *(void **)((longlong)pvVar1 + 0x10) = pvVar1;
  *(undefined2 *)((longlong)pvVar1 + 0x18) = 0x101;
  *(void **)(this + 8) = pvVar1;
  *(undefined ***)this = vftable;
  return this;
}

/* ---- FUNC 00009200 FUN_180009200 (60 bytes) ---- */

undefined8 * FUN_180009200(undefined8 *param_1,longlong param_2)

{
  *param_1 = std::exception::vftable;
  param_1[1] = 0;
  param_1[2] = 0;
  __std_exception_copy(param_2 + 8);
  *param_1 = std::bad_alloc::vftable;
  return param_1;
}

/* ---- FUNC 00009240 FUN_180009240 (60 bytes) ---- */

undefined8 * FUN_180009240(undefined8 *param_1,longlong param_2)

{
  *param_1 = std::exception::vftable;
  param_1[1] = 0;
  param_1[2] = 0;
  __std_exception_copy(param_2 + 8);
  *param_1 = std::bad_array_new_length::vftable;
  return param_1;
}

/* ---- FUNC 00009280 FUN_180009280 (33 bytes) ---- */

undefined8 * FUN_180009280(undefined8 *param_1)

{
  param_1[2] = 0;
  param_1[1] = "bad array new length";
  *param_1 = std::bad_array_new_length::vftable;
  return param_1;
}

/* ---- FUNC 000092B0 exception (50 bytes) ---- */

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

/* ---- FUNC 00009310 ~_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_> (42 bytes) ---- */

/* public: __cdecl std::_Tree<class std::_Tmap_traits<class CAPString,int,struct std::less<class
   CAPString>,class std::allocator<struct std::pair<class CAPString const ,int> >,0> >::~_Tree<class
   std::_Tmap_traits<class CAPString,int,struct std::less<class CAPString>,class
   std::allocator<struct std::pair<class CAPString const ,int> >,0> >(void) __ptr64 */

void __thiscall
std::
_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
::
~_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
          (_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
           *this)

{
                    /* 0x9310  29
                       ??1?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@QEAA@XZ
                       0x9310  30
                       ??1?$map@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@@std@@QEAA@XZ
                        */
  FUN_180008800(this,this,*(longlong **)(*(longlong *)this + 8));
  operator_delete(*(void **)this);
  return;
}

/* ---- FUNC 00009340 FUN_180009340 (57 bytes) ---- */

void FUN_180009340(undefined8 *param_1)

{
  longlong *plVar1;
  
  plVar1 = (longlong *)param_1[1];
  if (plVar1 != (longlong *)0x0) {
    FUN_180008800(plVar1,*param_1,*(longlong **)(*plVar1 + 8));
    operator_delete((void *)*plVar1);
    return;
  }
  return;
}

/* ---- FUNC 00009380 FUN_180009380 (94 bytes) ---- */

void FUN_180009380(longlong *param_1)

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
    operator_delete(pvVar2);
  }
  param_1[2] = 0;
  param_1[3] = 0xf;
  *(undefined1 *)param_1 = 0;
  return;
}

/* ---- FUNC 000093F0 ~CApwnEOStatus (56 bytes) ---- */

/* public: virtual __cdecl CApwnEOStatus::~CApwnEOStatus(void) __ptr64 */

void __thiscall CApwnEOStatus::~CApwnEOStatus(CApwnEOStatus *this)

{
  CApwnEOStatus *pCVar1;
  
                    /* 0x93f0  32  ??1CApwnEOStatus@@UEAA@XZ */
  pCVar1 = this + 8;
  *(undefined ***)this = vftable;
  FUN_180008800(pCVar1,pCVar1,*(longlong **)(*(longlong *)pCVar1 + 8));
  operator_delete(*(void **)pCVar1);
  return;
}

/* ---- FUNC 00009450 operator= (21 bytes) ---- */

/* public: class std::_Tree<class std::_Tmap_traits<class CAPString,int,struct std::less<class
   CAPString>,class std::allocator<struct std::pair<class CAPString const ,int> >,0> > & __ptr64
   __cdecl std::_Tree<class std::_Tmap_traits<class CAPString,int,struct std::less<class
   CAPString>,class std::allocator<struct std::pair<class CAPString const ,int> >,0>
   >::operator=(class std::_Tree<class std::_Tmap_traits<class CAPString,int,struct std::less<class
   CAPString>,class std::allocator<struct std::pair<class CAPString const ,int> >,0> > && __ptr64)
   __ptr64 */

_Tree<class_std::_Tmap_traits<class_CAPString,int,struct_std::less<class_CAPString>,class_std::allocator<struct_std::pair<class_CAPString_const_,int>_>,0>_>
* __thiscall
std::
_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
::operator=(_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
            *this,_Tree<class_std::_Tmap_traits<class_CAPString,int,struct_std::less<class_CAPString>,class_std::allocator<struct_std::pair<class_CAPString_const_,int>_>,0>_>
                  *param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  
                    /* 0x9450  37
                       ??4?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@QEAAAEAV01@$$QEAV01@@Z
                        */
  if (this != (_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
               *)param_1) {
    lVar1 = *(longlong *)this;
    FUN_180008800(this,this,*(longlong **)(lVar1 + 8));
    *(longlong *)(lVar1 + 8) = lVar1;
    *(longlong *)lVar1 = lVar1;
    *(longlong *)(lVar1 + 0x10) = lVar1;
    *(undefined8 *)(this + 8) = 0;
    uVar2 = *(undefined8 *)this;
    *(undefined8 *)this = *(undefined8 *)param_1;
    *(undefined8 *)param_1 = uVar2;
    uVar2 = *(undefined8 *)(this + 8);
    *(undefined8 *)(this + 8) = *(undefined8 *)(param_1 + 8);
    *(undefined8 *)(param_1 + 8) = uVar2;
  }
  return (_Tree<class_std::_Tmap_traits<class_CAPString,int,struct_std::less<class_CAPString>,class_std::allocator<struct_std::pair<class_CAPString_const_,int>_>,0>_>
          *)this;
}

/* ---- FUNC 00009465 FUN_180009465 (72 bytes) ---- */

void FUN_180009465(longlong *param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 *unaff_RSI;
  undefined8 *unaff_RDI;
  
  lVar1 = *param_1;
  FUN_180008800(param_1,param_1,*(longlong **)(lVar1 + 8));
  *(longlong *)(lVar1 + 8) = lVar1;
  *(longlong *)lVar1 = lVar1;
  *(longlong *)(lVar1 + 0x10) = lVar1;
  unaff_RDI[1] = 0;
  uVar2 = *unaff_RDI;
  *unaff_RDI = *unaff_RSI;
  *unaff_RSI = uVar2;
  uVar2 = unaff_RDI[1];
  unaff_RDI[1] = unaff_RSI[1];
  unaff_RSI[1] = uVar2;
  return;
}

/* ---- FUNC 000094AD FUN_1800094ad (14 bytes) ---- */

void FUN_1800094ad(void)

{
  return;
}

/* ---- FUNC 000094C0 operator= (21 bytes) ---- */

/* public: class std::_Tree<class std::_Tmap_traits<class CAPString,int,struct std::less<class
   CAPString>,class std::allocator<struct std::pair<class CAPString const ,int> >,0> > & __ptr64
   __cdecl std::_Tree<class std::_Tmap_traits<class CAPString,int,struct std::less<class
   CAPString>,class std::allocator<struct std::pair<class CAPString const ,int> >,0>
   >::operator=(class std::_Tree<class std::_Tmap_traits<class CAPString,int,struct std::less<class
   CAPString>,class std::allocator<struct std::pair<class CAPString const ,int> >,0> > const &
   __ptr64) __ptr64 */

_Tree<class_std::_Tmap_traits<class_CAPString,int,struct_std::less<class_CAPString>,class_std::allocator<struct_std::pair<class_CAPString_const_,int>_>,0>_>
* __thiscall
std::
_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
::operator=(_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
            *this,_Tree<class_std::_Tmap_traits<class_CAPString,int,struct_std::less<class_CAPString>,class_std::allocator<struct_std::pair<class_CAPString_const_,int>_>,0>_>
                  *param_1)

{
  longlong lVar1;
  longlong *plVar2;
  undefined8 in_R9;
  
                    /* 0x94c0  38
                       ??4?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@QEAAAEAV01@AEBV01@@Z
                       0x94c0  40
                       ??4?$map@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@@std@@QEAAAEAV01@AEBV01@@Z
                        */
  if (this != (_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
               *)param_1) {
    lVar1 = *(longlong *)this;
    plVar2 = *(longlong **)(lVar1 + 8);
    FUN_180008800(this,this,plVar2);
    *(longlong *)(lVar1 + 8) = lVar1;
    *(longlong *)lVar1 = lVar1;
    *(longlong *)(lVar1 + 0x10) = lVar1;
    *(undefined8 *)(this + 8) = 0;
    FUN_180007f50((longlong *)this,(longlong *)param_1,plVar2,in_R9);
  }
  return (_Tree<class_std::_Tmap_traits<class_CAPString,int,struct_std::less<class_CAPString>,class_std::allocator<struct_std::pair<class_CAPString_const_,int>_>,0>_>
          *)this;
}

/* ---- FUNC 000094D5 FUN_1800094d5 (55 bytes) ---- */

void FUN_1800094d5(longlong *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  longlong *unaff_RSI;
  longlong *unaff_RDI;
  longlong *plVar2;
  
  lVar1 = *param_1;
  plVar2 = *(longlong **)(lVar1 + 8);
  FUN_180008800(param_1,param_1,plVar2);
  *(longlong *)(lVar1 + 8) = lVar1;
  *(longlong *)lVar1 = lVar1;
  *(longlong *)(lVar1 + 0x10) = lVar1;
  unaff_RDI[1] = 0;
  FUN_180007f50(unaff_RDI,unaff_RSI,plVar2,param_4);
  return;
}

/* ---- FUNC 0000950C FUN_18000950c (14 bytes) ---- */

void FUN_18000950c(void)

{
  return;
}

/* ---- FUNC 00009520 operator= (23 bytes) ---- */

/* public: class std::map<class CAPString,int,struct std::less<class CAPString>,class
   std::allocator<struct std::pair<class CAPString const ,int> > > & __ptr64 __cdecl std::map<class
   CAPString,int,struct std::less<class CAPString>,class std::allocator<struct std::pair<class
   CAPString const ,int> > >::operator=(class std::map<class CAPString,int,struct std::less<class
   CAPString>,class std::allocator<struct std::pair<class CAPString const ,int> > > && __ptr64)
   __ptr64 */

map<class_CAPString,int,struct_std::less<class_CAPString>,class_std::allocator<struct_std::pair<class_CAPString_const_,int>_>_>
* __thiscall
std::map<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>_>::
operator=(map<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>_>
          *this,map<class_CAPString,int,struct_std::less<class_CAPString>,class_std::allocator<struct_std::pair<class_CAPString_const_,int>_>_>
                *param_1)

{
                    /* 0x9520  39
                       ??4?$map@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@@std@@QEAAAEAV01@$$QEAV01@@Z
                        */
  _Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
  ::operator=((_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
               *)this,(_Tree<class_std::_Tmap_traits<class_CAPString,int,struct_std::less<class_CAPString>,class_std::allocator<struct_std::pair<class_CAPString_const_,int>_>,0>_>
                       *)param_1);
  return (map<class_CAPString,int,struct_std::less<class_CAPString>,class_std::allocator<struct_std::pair<class_CAPString_const_,int>_>_>
          *)this;
}

/* ---- FUNC 00009540 operator= (293 bytes) ---- */

/* public: class std::map<class CAPString,int,struct std::less<class CAPString>,class
   std::allocator<struct std::pair<class CAPString const ,int> > > & __ptr64 __cdecl std::map<class
   CAPString,int,struct std::less<class CAPString>,class std::allocator<struct std::pair<class
   CAPString const ,int> > >::operator=(class std::initializer_list<struct std::pair<class CAPString
   const ,int> >) __ptr64 */

map<class_CAPString,int,struct_std::less<class_CAPString>,class_std::allocator<struct_std::pair<class_CAPString_const_,int>_>_>
* __thiscall
std::map<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>_>::
operator=(map<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>_>
          *this,undefined8 *param_2)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong *plVar5;
  longlong local_68;
  longlong lStack_60;
  longlong local_48;
  longlong local_40 [3];
  
                    /* 0x9540  41
                       ??4?$map@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@@std@@QEAAAEAV01@V?$initializer_list@U?$pair@$$CBVCAPString@@H@std@@@1@@Z
                        */
  lVar1 = *(longlong *)this;
  FUN_180008800(this,this,*(longlong **)(lVar1 + 8));
  *(longlong *)(lVar1 + 8) = lVar1;
  *(longlong *)lVar1 = lVar1;
  *(longlong *)(lVar1 + 0x10) = lVar1;
  *(undefined8 *)(this + 8) = 0;
  plVar5 = (longlong *)*param_2;
  plVar2 = (longlong *)param_2[1];
  plVar3 = *(longlong **)this;
  do {
    if (plVar5 == plVar2) {
      return (map<class_CAPString,int,struct_std::less<class_CAPString>,class_std::allocator<struct_std::pair<class_CAPString_const_,int>_>_>
              *)this;
    }
    plVar4 = FUN_180008940((longlong *)this,local_40,plVar3,plVar5);
    local_68 = *plVar4;
    lStack_60 = plVar4[1];
    local_48 = plVar4[2];
    if ((char)local_48 == '\0') {
      if (*(longlong *)(this + 8) == 0x333333333333333) {
                    /* WARNING: Subroutine does not return */
        FUN_18000ac90();
      }
      lVar1 = *(longlong *)this;
      plVar4 = operator_new(0x50);
      FUN_180009090(plVar4 + 4,plVar5);
      *plVar4 = lVar1;
      plVar4[1] = lVar1;
      plVar4[2] = lVar1;
      *(undefined2 *)(plVar4 + 3) = 0;
      FUN_18000a930((longlong *)this,&local_68,plVar4);
    }
    plVar5 = plVar5 + 6;
  } while( true );
}

/* ---- FUNC 00009670 operator= (31 bytes) ---- */

/* public: class CApwnEOStatus & __ptr64 __cdecl CApwnEOStatus::operator=(class CApwnEOStatus const
   & __ptr64) __ptr64 */

CApwnEOStatus * __thiscall CApwnEOStatus::operator=(CApwnEOStatus *this,CApwnEOStatus *param_1)

{
  CApwnEOStatus *pCVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 in_R9;
  
                    /* 0x9670  42  ??4CApwnEOStatus@@QEAAAEAV0@AEBV0@@Z */
  pCVar1 = this + 8;
  if (pCVar1 != param_1 + 8) {
    lVar2 = *(longlong *)pCVar1;
    plVar3 = *(longlong **)(lVar2 + 8);
    FUN_180008800(pCVar1,pCVar1,plVar3);
    *(longlong *)(lVar2 + 8) = lVar2;
    *(longlong *)lVar2 = lVar2;
    *(longlong *)(lVar2 + 0x10) = lVar2;
    *(undefined8 *)(this + 0x10) = 0;
    FUN_180007f50((longlong *)pCVar1,(longlong *)(param_1 + 8),plVar3,in_R9);
  }
  return this;
}

/* ---- FUNC 0000968F FUN_18000968f (58 bytes) ---- */

void FUN_18000968f(void)

{
  longlong lVar1;
  longlong *unaff_RBP;
  longlong *unaff_RDI;
  longlong *plVar2;
  undefined8 in_R9;
  
  lVar1 = *unaff_RDI;
  plVar2 = *(longlong **)(lVar1 + 8);
  FUN_180008800(unaff_RDI,unaff_RDI,plVar2);
  *(longlong *)(lVar1 + 8) = lVar1;
  *(longlong *)lVar1 = lVar1;
  *(longlong *)(lVar1 + 0x10) = lVar1;
  unaff_RDI[1] = 0;
  FUN_180007f50(unaff_RDI,unaff_RBP,plVar2,in_R9);
  return;
}

/* ---- FUNC 000096C9 FUN_1800096c9 (19 bytes) ---- */

void FUN_1800096c9(void)

{
  return;
}

/* ---- FUNC 000096E0 operator[] (29 bytes) ---- */

/* public: int & __ptr64 __cdecl std::map<class CAPString,int,struct std::less<class
   CAPString>,class std::allocator<struct std::pair<class CAPString const ,int> >
   >::operator[](class CAPString && __ptr64) __ptr64 */

int * __thiscall
std::map<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>_>::
operator[](map<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>_>
           *this,CAPString *param_1)

{
  longlong *plVar1;
  undefined8 local_18 [3];
  
                    /* 0x96e0  47
                       ??A?$map@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@@std@@QEAAAEAH$$QEAVCAPString@@@Z
                       0x96e0  48
                       ??A?$map@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@@std@@QEAAAEAHAEBVCAPString@@@Z
                        */
  plVar1 = FUN_180008c10((longlong *)this,local_18,(longlong *)param_1);
  return (int *)(*plVar1 + 0x48);
}

/* ---- FUNC 00009700 operator[] (391 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: int & __ptr64 __cdecl CApwnEOStatus::operator[](char const * __ptr64) __ptr64 */

int * __thiscall CApwnEOStatus::operator[](CApwnEOStatus *this,char *param_1)

{
  undefined **ppuVar1;
  longlong lVar2;
  void *pvVar3;
  longlong *plVar4;
  size_t sVar5;
  undefined1 auStack_a8 [32];
  undefined4 local_88;
  undefined **local_80 [2];
  void *local_70 [2];
  size_t sStack_60;
  ulonglong local_58 [2];
  undefined *local_48 [5];
  undefined4 local_20;
  ulonglong local_18;
  
                    /* 0x9700  49  ??ACApwnEOStatus@@QEAAAEAHPEBD@Z */
  local_18 = DAT_1800791f8 ^ (ulonglong)auStack_a8;
  local_70[0] = &DAT_1800537c8;
  sStack_60 = 0;
  local_58[0] = _DAT_180053820;
  local_58[1] = _UNK_180053828;
  local_70[1] = (void *)0x0;
  local_88 = 1;
  sVar5 = 0xffffffffffffffff;
  do {
    sVar5 = sVar5 + 1;
  } while (param_1[sVar5] != '\0');
  FUN_18000ad20((longlong *)((longlong)local_70 + (longlong)DAT_1800537cc),param_1,sVar5);
  ppuVar1 = (undefined **)FUN_180008880((longlong *)(this + 8),(longlong *)local_70);
  if (ppuVar1 == *(undefined ***)(this + 8)) {
    local_80[0] = local_48;
    local_48[0] = &DAT_1800537c8;
    local_48[2] = (undefined *)0x0;
    local_48[3] = (undefined *)0x0;
    local_48[4] = (undefined *)0xf;
    local_48[1] = (undefined *)0x0;
    local_88 = 3;
    lVar2 = (longlong)*(int *)((longlong)local_70[0] + 4);
    plVar4 = (longlong *)((longlong)local_70 + lVar2);
    if ((longlong *)((longlong)local_48 + (longlong)DAT_1800537cc) != plVar4) {
      if (0xf < *(ulonglong *)((longlong)local_58 + lVar2)) {
        plVar4 = (longlong *)*plVar4;
      }
      FUN_18000ad20((longlong *)((longlong)local_48 + (longlong)DAT_1800537cc),plVar4,
                    *(size_t *)((longlong)&sStack_60 + lVar2));
    }
    local_20 = 1;
    FUN_180008270((longlong *)(this + 8),local_80,(longlong *)local_48);
    FUN_180009900((longlong)local_48);
    ppuVar1 = local_80[0];
  }
  if (0xf < local_58[1]) {
    pvVar3 = local_70[1];
    if ((0xfff < local_58[1] + 1) &&
       (pvVar3 = *(void **)((longlong)local_70[1] + -8),
       0x1f < (ulonglong)((longlong)local_70[1] + (-8 - (longlong)pvVar3)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar3);
  }
  return (int *)(ppuVar1 + 9);
}

/* ---- FUNC 00009890 FUN_180009890 (102 bytes) ---- */

longlong * FUN_180009890(longlong *param_1)

{
  char cVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong lVar5;
  
  lVar2 = *param_1;
  plVar3 = *(longlong **)(lVar2 + 0x10);
  if (*(char *)((longlong)plVar3 + 0x19) != '\0') {
    cVar1 = *(char *)(*(longlong *)(lVar2 + 8) + 0x19);
    lVar5 = *(longlong *)(lVar2 + 8);
    while ((cVar1 == '\0' && (lVar2 == *(longlong *)(lVar5 + 0x10)))) {
      *param_1 = lVar5;
      cVar1 = *(char *)(*(longlong *)(lVar5 + 8) + 0x19);
      lVar2 = lVar5;
      lVar5 = *(longlong *)(lVar5 + 8);
    }
    *param_1 = lVar5;
    return param_1;
  }
  cVar1 = *(char *)(*plVar3 + 0x19);
  plVar4 = (longlong *)*plVar3;
  while (cVar1 == '\0') {
    cVar1 = *(char *)(*plVar4 + 0x19);
    plVar3 = plVar4;
    plVar4 = (longlong *)*plVar4;
  }
  *param_1 = (longlong)plVar3;
  return param_1;
}

/* ---- FUNC 00009900 FUN_180009900 (96 bytes) ---- */

void FUN_180009900(longlong param_1)

{
  void *pvVar1;
  void *pvVar2;
  
  if (0xf < *(ulonglong *)(param_1 + 0x20)) {
    pvVar1 = *(void **)(param_1 + 8);
    pvVar2 = pvVar1;
    if ((0xfff < *(ulonglong *)(param_1 + 0x20) + 1) &&
       (pvVar2 = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar2)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar2);
  }
  *(undefined8 *)(param_1 + 0x18) = 0;
  *(undefined8 *)(param_1 + 0x20) = 0xf;
  *(undefined1 *)(param_1 + 8) = 0;
  return;
}

/* ---- FUNC 00009970 FUN_180009970 (139 bytes) ---- */

CApwnEOStatus * FUN_180009970(CApwnEOStatus *param_1,uint param_2)

{
  if ((param_2 & 2) != 0) {
    _eh_vector_destructor_iterator_
              (param_1,0x18,*(__uint64 *)(param_1 + -8),CApwnEOStatus::~CApwnEOStatus);
    if ((param_2 & 1) != 0) {
      operator_delete__(param_1 + -8);
    }
    return param_1 + -8;
  }
  CApwnEOStatus::~CApwnEOStatus(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

/* ---- FUNC 00009A00 FUN_180009a00 (66 bytes) ---- */

undefined8 * FUN_180009a00(undefined8 *param_1,ulonglong param_2)

{
  *param_1 = std::exception::vftable;
  __std_exception_destroy(param_1 + 1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

/* ---- FUNC 00009A50 Excluded (608 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: void __cdecl CApwnEOStatus::Excluded(class std::vector<class
   std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class
   std::allocator<class std::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> > > > & __ptr64) __ptr64 */

void __thiscall
CApwnEOStatus::Excluded
          (CApwnEOStatus *this,
          vector<std::basic_string<char,std::char_traits<char>,std::allocator<char>_>,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char>_>_>_>
          *param_1)

{
  ulonglong uVar1;
  char cVar2;
  longlong *plVar3;
  longlong *plVar4;
  void *pvVar5;
  undefined8 *puVar6;
  ulonglong uVar7;
  longlong *plVar8;
  undefined8 *_Src;
  ulonglong uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined1 auStack_78 [32];
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
                    /* 0x9a50  86
                       ?Excluded@CApwnEOStatus@@QEAAXAEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@@Z
                        */
  local_38 = DAT_1800791f8 ^ (ulonglong)auStack_78;
  if (*(longlong **)param_1 != *(longlong **)(param_1 + 8)) {
    FUN_1800081e0(*(longlong **)param_1,*(longlong **)(param_1 + 8));
    *(undefined8 *)(param_1 + 8) = *(undefined8 *)param_1;
  }
  plVar8 = (longlong *)**(longlong **)(this + 8);
  if (plVar8 != *(longlong **)(this + 8)) {
    do {
      if ((int)plVar8[9] == 0) {
        puVar6 = (undefined8 *)((longlong)*(int *)(plVar8[4] + 4) + (longlong)(plVar8 + 4));
        local_58 = (void *)0x0;
        uStack_50 = 0;
        local_48 = 0;
        uStack_40 = 0;
        _Src = puVar6;
        if (0xf < (ulonglong)puVar6[3]) {
          _Src = (undefined8 *)*puVar6;
        }
        uVar7 = puVar6[2];
        if (0x7fffffffffffffff < uVar7) {
                    /* WARNING: Subroutine does not return */
          FUN_18000ace0();
        }
        if (uVar7 < 0x10) {
          uStack_40 = 0xf;
          local_58 = (void *)*_Src;
          uStack_50 = _Src[1];
          uVar10 = *(undefined4 *)_Src;
          uVar11 = *(undefined4 *)((longlong)_Src + 4);
          uVar12 = *(undefined4 *)(_Src + 1);
          uVar13 = *(undefined4 *)((longlong)_Src + 0xc);
          local_48 = uVar7;
        }
        else {
          uVar9 = uVar7 | 0xf;
          if (uVar9 < 0x8000000000000000) {
            if (uVar9 < 0x16) {
              uVar9 = 0x16;
            }
            uVar1 = uVar9 + 1;
            if (uVar1 < 0x1000) {
              pvVar5 = (void *)0x0;
              if (uVar1 != 0) {
                pvVar5 = operator_new(uVar1);
              }
            }
            else {
              pvVar5 = (void *)FUN_180007f10(uVar1);
            }
          }
          else {
            uVar9 = 0x7fffffffffffffff;
            pvVar5 = (void *)FUN_180007f10(0x8000000000000000);
          }
          local_58 = pvVar5;
          local_48 = uVar7;
          uStack_40 = uVar9;
          memcpy(pvVar5,_Src,uVar7 + 1);
          uVar10 = (undefined4)local_58;
          uVar11 = local_58._4_4_;
          uVar12 = (undefined4)uStack_50;
          uVar13 = uStack_50._4_4_;
        }
        plVar3 = *(longlong **)(param_1 + 8);
        if (plVar3 == *(longlong **)(param_1 + 0x10)) {
          FUN_180008500((longlong *)param_1,plVar3,&local_58);
          uVar7 = uStack_40;
        }
        else {
          *(undefined4 *)plVar3 = uVar10;
          *(undefined4 *)((longlong)plVar3 + 4) = uVar11;
          *(undefined4 *)(plVar3 + 1) = uVar12;
          *(undefined4 *)((longlong)plVar3 + 0xc) = uVar13;
          *(undefined4 *)(plVar3 + 2) = (undefined4)local_48;
          *(undefined4 *)((longlong)plVar3 + 0x14) = local_48._4_4_;
          *(undefined4 *)(plVar3 + 3) = (undefined4)uStack_40;
          *(undefined4 *)((longlong)plVar3 + 0x1c) = uStack_40._4_4_;
          local_58 = (void *)((ulonglong)local_58 & 0xffffffffffffff00);
          *(longlong *)(param_1 + 8) = *(longlong *)(param_1 + 8) + 0x20;
          uVar7 = 0xf;
        }
        if (0xf < uVar7) {
          pvVar5 = local_58;
          if ((0xfff < uVar7 + 1) &&
             (pvVar5 = *(void **)((longlong)local_58 + -8),
             0x1f < (ulonglong)((longlong)local_58 + (-8 - (longlong)pvVar5)))) {
                    /* WARNING: Subroutine does not return */
            _invalid_parameter_noinfo_noreturn();
          }
          operator_delete(pvVar5);
        }
      }
      plVar3 = (longlong *)plVar8[2];
      if (*(char *)((longlong)plVar3 + 0x19) == '\0') {
        cVar2 = *(char *)(*plVar3 + 0x19);
        plVar8 = plVar3;
        plVar3 = (longlong *)*plVar3;
        while (cVar2 == '\0') {
          cVar2 = *(char *)(*plVar3 + 0x19);
          plVar8 = plVar3;
          plVar3 = (longlong *)*plVar3;
        }
      }
      else {
        cVar2 = *(char *)(plVar8[1] + 0x19);
        plVar4 = (longlong *)plVar8[1];
        plVar3 = plVar8;
        while ((plVar8 = plVar4, cVar2 == '\0' && (plVar3 == (longlong *)plVar8[2]))) {
          cVar2 = *(char *)(plVar8[1] + 0x19);
          plVar4 = (longlong *)plVar8[1];
          plVar3 = plVar8;
        }
      }
    } while (plVar8 != *(longlong **)(this + 8));
  }
  return;
}

/* ---- FUNC 00009CC0 Count (4 bytes) ---- */

/* public: int __cdecl CConvertMgr::Count(void) __ptr64 */

int __thiscall CConvertMgr::Count(CConvertMgr *this)

{
                    /* 0x9cc0  74  ?Count@CConvertMgr@@QEAAHXZ
                       0x9cc0  98  ?GetCount@CApwnEOStatus@@QEBAHXZ */
  return *(int *)(this + 0x10);
}

/* ---- FUNC 00009CD0 IsEmpty (10 bytes) ---- */

/* public: int __cdecl CApwnEOStatus::IsEmpty(void)const __ptr64 */

int __thiscall CApwnEOStatus::IsEmpty(CApwnEOStatus *this)

{
                    /* 0x9cd0  125  ?IsEmpty@CApwnEOStatus@@QEBAHXZ */
  return (int)(*(longlong *)(this + 0x10) == 0);
}

/* ---- FUNC 00009CE0 Lookup (556 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: int __cdecl CApwnEOStatus::Lookup(char const * __ptr64,int & __ptr64)const __ptr64 */

int __thiscall CApwnEOStatus::Lookup(CApwnEOStatus *this,char *param_1,int *param_2)

{
  int iVar1;
  undefined8 *puVar2;
  uint uVar3;
  void *pvVar4;
  size_t sVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  size_t sVar9;
  int iVar10;
  undefined1 auStack_c8 [32];
  undefined4 local_a8;
  int *local_a0;
  void *local_98 [4];
  ulonglong uStack_78;
  void *local_70 [4];
  ulonglong uStack_50;
  ulonglong local_48;
  
                    /* 0x9ce0  128  ?Lookup@CApwnEOStatus@@QEBAHPEBDAEAH@Z */
  local_48 = DAT_1800791f8 ^ (ulonglong)auStack_c8;
  local_70[0] = &DAT_1800537c8;
  local_70[2] = (void *)0x0;
  local_70[3] = (void *)_DAT_180053820;
  uStack_50 = _UNK_180053828;
  local_70[1] = (void *)0x0;
  iVar10 = 1;
  local_a8 = 1;
  sVar5 = 0xffffffffffffffff;
  sVar9 = 0xffffffffffffffff;
  do {
    sVar9 = sVar9 + 1;
  } while (param_1[sVar9] != '\0');
  local_a0 = param_2;
  FUN_18000ad20((longlong *)((longlong)local_70 + (longlong)DAT_1800537cc),param_1,sVar9);
  local_98[0] = &DAT_1800537c8;
  local_98[2] = (void *)0x0;
  local_98[3] = (void *)_DAT_180053820;
  uStack_78 = _UNK_180053828;
  local_98[1] = (void *)0x0;
  local_a8 = 3;
  do {
    sVar5 = sVar5 + 1;
  } while (param_1[sVar5] != '\0');
  FUN_18000ad20((longlong *)((longlong)local_98 + (longlong)DAT_1800537cc),param_1,sVar5);
  pvVar4 = local_98[0];
  puVar2 = *(undefined8 **)(this + 8);
  puVar8 = puVar2;
  if (*(char *)((longlong)puVar2[1] + 0x19) == '\0') {
    iVar1 = *(int *)((longlong)local_98[0] + 4);
    puVar6 = (undefined8 *)puVar2[1];
    do {
      uVar3 = FUN_180007ea0((undefined8 *)
                            ((longlong)*(int *)(puVar6[4] + 4) + (longlong)(puVar6 + 4)),
                            (undefined8 *)((longlong)local_98 + (longlong)iVar1));
      if ((char)uVar3 == '\0') {
        puVar7 = (undefined8 *)*puVar6;
        puVar8 = puVar6;
      }
      else {
        puVar7 = (undefined8 *)puVar6[2];
      }
      puVar6 = puVar7;
      param_2 = local_a0;
    } while (*(char *)((longlong)puVar7 + 0x19) == '\0');
  }
  if ((*(char *)((longlong)puVar8 + 0x19) != '\0') ||
     (uVar3 = FUN_180007ea0((undefined8 *)
                            ((longlong)local_98 + (longlong)*(int *)((longlong)pvVar4 + 4)),
                            (undefined8 *)
                            ((longlong)*(int *)(puVar8[4] + 4) + (longlong)(puVar8 + 4))),
     (char)uVar3 != '\0')) {
    puVar8 = puVar2;
  }
  if (0xf < uStack_78) {
    pvVar4 = local_98[1];
    if ((0xfff < uStack_78 + 1) &&
       (pvVar4 = *(void **)((longlong)local_98[1] + -8),
       0x1f < (ulonglong)((longlong)local_98[1] + (-8 - (longlong)pvVar4)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar4);
  }
  puVar2 = *(undefined8 **)(this + 8);
  if (puVar8 != puVar2) {
    iVar10 = *(int *)(puVar8 + 9);
  }
  *param_2 = iVar10;
  if (0xf < uStack_50) {
    pvVar4 = local_70[1];
    if ((0xfff < uStack_50 + 1) &&
       (pvVar4 = *(void **)((longlong)local_70[1] + -8),
       0x1f < (ulonglong)((longlong)local_70[1] + (-8 - (longlong)pvVar4)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar4);
  }
  return (int)(puVar8 != puVar2);
}

/* ---- FUNC 00009F10 RemoveAll (63 bytes) ---- */

/* public: void __cdecl CApwnEOStatus::RemoveAll(void) __ptr64 */

void __thiscall CApwnEOStatus::RemoveAll(CApwnEOStatus *this)

{
  longlong lVar1;
  
                    /* 0x9f10  164  ?RemoveAll@CApwnEOStatus@@QEAAXXZ */
  lVar1 = *(longlong *)(this + 8);
  FUN_180008800(this + 8,this + 8,*(longlong **)(lVar1 + 8));
  *(longlong *)(lVar1 + 8) = lVar1;
  *(longlong *)lVar1 = lVar1;
  *(longlong *)(lVar1 + 0x10) = lVar1;
  *(undefined8 *)(this + 0x10) = 0;
  return;
}

/* ---- FUNC 00009F50 RemoveKey (257 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: int __cdecl CApwnEOStatus::RemoveKey(char const * __ptr64) __ptr64 */

int __thiscall CApwnEOStatus::RemoveKey(CApwnEOStatus *this,char *param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  void *pvVar3;
  size_t sVar4;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  void *local_40 [4];
  ulonglong uStack_20;
  ulonglong local_18;
  
                    /* 0x9f50  167  ?RemoveKey@CApwnEOStatus@@QEAAHPEBD@Z */
  local_18 = DAT_1800791f8 ^ (ulonglong)auStack_68;
  local_40[0] = &DAT_1800537c8;
  local_40[2] = (void *)0x0;
  local_40[3] = (void *)_DAT_180053820;
  uStack_20 = _UNK_180053828;
  local_40[1] = (void *)0x0;
  local_48 = 1;
  sVar4 = 0xffffffffffffffff;
  do {
    sVar4 = sVar4 + 1;
  } while (param_1[sVar4] != '\0');
  FUN_18000ad20((longlong *)((longlong)local_40 + (longlong)DAT_1800537cc),param_1,sVar4);
  puVar2 = FUN_180008880((longlong *)(this + 8),(longlong *)local_40);
  puVar1 = *(undefined8 **)(this + 8);
  if (puVar2 != puVar1) {
    std::
    _Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
    ::_Erase_unchecked((_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
                        *)(this + 8),puVar2);
  }
  if (0xf < uStack_20) {
    pvVar3 = local_40[1];
    if ((0xfff < uStack_20 + 1) &&
       (pvVar3 = *(void **)((longlong)local_40[1] + -8),
       0x1f < (ulonglong)((longlong)local_40[1] + (-8 - (longlong)pvVar3)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar3);
  }
  return (uint)(puVar2 != puVar1);
}

/* ---- FUNC 0000A060 SetAt (379 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __cdecl CApwnEOStatus::SetAt(char const * __ptr64,int) __ptr64 */

void __thiscall CApwnEOStatus::SetAt(CApwnEOStatus *this,char *param_1,int param_2)

{
  undefined8 *puVar1;
  longlong lVar2;
  void *pvVar3;
  longlong *plVar4;
  size_t sVar5;
  undefined1 auStack_b8 [32];
  undefined4 local_98;
  undefined **local_90 [2];
  void *local_80 [2];
  size_t sStack_70;
  ulonglong local_68 [2];
  undefined *local_58 [5];
  int local_30;
  ulonglong local_28;
  
                    /* 0xa060  186  ?SetAt@CApwnEOStatus@@QEAAXPEBDH@Z */
  local_28 = DAT_1800791f8 ^ (ulonglong)auStack_b8;
  local_80[0] = &DAT_1800537c8;
  sStack_70 = 0;
  local_68[0] = _DAT_180053820;
  local_68[1] = _UNK_180053828;
  local_80[1] = (void *)0x0;
  local_98 = 1;
  sVar5 = 0xffffffffffffffff;
  do {
    sVar5 = sVar5 + 1;
  } while (param_1[sVar5] != '\0');
  FUN_18000ad20((longlong *)((longlong)local_80 + (longlong)DAT_1800537cc),param_1,sVar5);
  puVar1 = FUN_180008880((longlong *)(this + 8),(longlong *)local_80);
  if (puVar1 == *(undefined8 **)(this + 8)) {
    local_90[0] = local_58;
    local_58[0] = &DAT_1800537c8;
    local_58[2] = (undefined *)0x0;
    local_58[3] = (undefined *)0x0;
    local_58[4] = (undefined *)0xf;
    local_58[1] = (undefined *)0x0;
    local_98 = 3;
    lVar2 = (longlong)*(int *)((longlong)local_80[0] + 4);
    plVar4 = (longlong *)((longlong)local_80 + lVar2);
    if ((longlong *)((longlong)local_58 + (longlong)DAT_1800537cc) != plVar4) {
      if (0xf < *(ulonglong *)((longlong)local_68 + lVar2)) {
        plVar4 = (longlong *)*plVar4;
      }
      FUN_18000ad20((longlong *)((longlong)local_58 + (longlong)DAT_1800537cc),plVar4,
                    *(size_t *)((longlong)&sStack_70 + lVar2));
    }
    local_30 = param_2;
    FUN_180008270((longlong *)(this + 8),local_90,(longlong *)local_58);
    FUN_180009900((longlong)local_58);
  }
  else {
    *(int *)(puVar1 + 9) = param_2;
  }
  if (0xf < local_68[1]) {
    pvVar3 = local_80[1];
    if ((0xfff < local_68[1] + 1) &&
       (pvVar3 = *(void **)((longlong)local_80[1] + -8),
       0x1f < (ulonglong)((longlong)local_80[1] + (-8 - (longlong)pvVar3)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar3);
  }
  return;
}

/* ---- FUNC 0000A1E0 _Alloc_sentinel_and_proxy (45 bytes) ---- */

/* protected: void __cdecl std::_Tree<class std::_Tmap_traits<class CAPString,int,struct
   std::less<class CAPString>,class std::allocator<struct std::pair<class CAPString const ,int> >,0>
   >::_Alloc_sentinel_and_proxy(void) __ptr64 */

void __thiscall
std::
_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
::_Alloc_sentinel_and_proxy
          (_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
           *this)

{
  void *pvVar1;
  
                    /* 0xa1e0  191
                       ?_Alloc_sentinel_and_proxy@?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@IEAAXXZ
                        */
  pvVar1 = operator_new(0x50);
  *(void **)pvVar1 = pvVar1;
  *(void **)((longlong)pvVar1 + 8) = pvVar1;
  *(void **)((longlong)pvVar1 + 0x10) = pvVar1;
  *(undefined2 *)((longlong)pvVar1 + 0x18) = 0x101;
  *(void **)this = pvVar1;
  return;
}

/* ---- FUNC 0000A210 _Check_grow_by_1 (30 bytes) ---- */

/* protected: void __cdecl std::_Tree<class std::_Tmap_traits<class CAPString,int,struct
   std::less<class CAPString>,class std::allocator<struct std::pair<class CAPString const ,int> >,0>
   >::_Check_grow_by_1(void) __ptr64 */

void __thiscall
std::
_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
::_Check_grow_by_1(_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
                   *this)

{
                    /* 0xa210  192
                       ?_Check_grow_by_1@?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@IEAAXXZ
                        */
  if (*(longlong *)(this + 8) != 0x333333333333333) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18000ac90();
}

/* ---- FUNC 0000A230 _Different_allocator_move_construct (187 bytes) ---- */

/* private: void __cdecl std::_Tree<class std::_Tmap_traits<class CAPString,int,struct
   std::less<class CAPString>,class std::allocator<struct std::pair<class CAPString const ,int> >,0>
   >::_Different_allocator_move_construct(class std::_Tree<class std::_Tmap_traits<class
   CAPString,int,struct std::less<class CAPString>,class std::allocator<struct std::pair<class
   CAPString const ,int> >,0> > && __ptr64) __ptr64 */

void __thiscall
std::
_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
::_Different_allocator_move_construct
          (_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
           *this,_Tree<class_std::_Tmap_traits<class_CAPString,int,struct_std::less<class_CAPString>,class_std::allocator<struct_std::pair<class_CAPString_const_,int>_>,0>_>
                 *param_1)

{
  char cVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong lVar4;
  longlong *plVar5;
  void *pvVar6;
  longlong *plVar7;
  undefined8 in_R9;
  
                    /* 0xa230  193
                       ?_Different_allocator_move_construct@?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@AEAAX$$QEAV12@@Z
                        */
  pvVar6 = operator_new(0x50);
  *(void **)pvVar6 = pvVar6;
  *(void **)((longlong)pvVar6 + 8) = pvVar6;
  *(void **)((longlong)pvVar6 + 0x10) = pvVar6;
  *(undefined2 *)((longlong)pvVar6 + 0x18) = 0x101;
  *(void **)this = pvVar6;
  plVar7 = FUN_180008000((undefined8 *)this,*(undefined8 **)(*(longlong *)param_1 + 8),
                         (longlong)pvVar6,in_R9);
  *(longlong **)(*(longlong *)this + 8) = plVar7;
  *(undefined8 *)(this + 8) = *(undefined8 *)(param_1 + 8);
  plVar7 = *(longlong **)this;
  plVar2 = (longlong *)plVar7[1];
  if (*(char *)((longlong)plVar2 + 0x19) == '\0') {
    cVar1 = *(char *)(*plVar2 + 0x19);
    plVar5 = (longlong *)*plVar2;
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*plVar5 + 0x19);
      plVar2 = plVar5;
      plVar5 = (longlong *)*plVar5;
    }
    *plVar7 = (longlong)plVar2;
    lVar3 = *(longlong *)(*(longlong *)this + 8);
    lVar4 = *(longlong *)(lVar3 + 0x10);
    cVar1 = *(char *)(lVar4 + 0x19);
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*(longlong *)(lVar4 + 0x10) + 0x19);
      lVar3 = lVar4;
      lVar4 = *(longlong *)(lVar4 + 0x10);
    }
    *(longlong *)(*(longlong *)this + 0x10) = lVar3;
  }
  else {
    *plVar7 = (longlong)plVar7;
    *(longlong *)(*(longlong *)this + 0x10) = *(longlong *)this;
  }
  return;
}

/* ---- FUNC 0000A2F0 _Erase (133 bytes) ---- */

/* private: unsigned __int64 __cdecl std::_Tree<class std::_Tmap_traits<class CAPString,int,struct
   std::less<class CAPString>,class std::allocator<struct std::pair<class CAPString const ,int> >,0>
   >::_Erase(struct std::pair<struct std::_Tree_node<struct std::pair<class CAPString const
   ,int>,void * __ptr64> * __ptr64,struct std::_Tree_node<struct std::pair<class CAPString const
   ,int>,void * __ptr64> * __ptr64>) __ptr64 */

__uint64 __thiscall
std::
_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
::_Erase(_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
         *this,undefined8 *param_2)

{
  char cVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong *plVar4;
  __uint64 _Var5;
  
                    /* 0xa2f0  194
                       ?_Erase@?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@AEAA_KU?$pair@PEAU?$_Tree_node@U?$pair@$$CBVCAPString@@H@std@@PEAX@std@@PEAU12@@2@@Z
                        */
  _Var5 = 0;
  plVar2 = (longlong *)*param_2;
  while (plVar2 != (longlong *)param_2[1]) {
    plVar3 = (longlong *)plVar2[2];
    _Var5 = _Var5 + 1;
    if (*(char *)((longlong)plVar3 + 0x19) == '\0') {
      cVar1 = *(char *)(*plVar3 + 0x19);
      plVar2 = plVar3;
      plVar3 = (longlong *)*plVar3;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*plVar3 + 0x19);
        plVar2 = plVar3;
        plVar3 = (longlong *)*plVar3;
      }
    }
    else {
      cVar1 = *(char *)(plVar2[1] + 0x19);
      plVar4 = (longlong *)plVar2[1];
      plVar3 = plVar2;
      while ((plVar2 = plVar4, cVar1 == '\0' && (plVar3 == (longlong *)plVar2[2]))) {
        cVar1 = *(char *)(plVar2[1] + 0x19);
        plVar4 = (longlong *)plVar2[1];
        plVar3 = plVar2;
      }
    }
  }
  _Erase_unchecked(this);
  return _Var5;
}

/* ---- FUNC 0000A380 _Erase_unchecked (319 bytes) ---- */

/* private: struct std::_Tree_node<struct std::pair<class CAPString const ,int>,void * __ptr64> *
   __ptr64 __cdecl std::_Tree<class std::_Tmap_traits<class CAPString,int,struct std::less<class
   CAPString>,class std::allocator<struct std::pair<class CAPString const ,int> >,0>
   >::_Erase_unchecked(class std::_Tree_unchecked_const_iterator<class std::_Tree_val<struct
   std::_Tree_simple_types<struct std::pair<class CAPString const ,int> > >,struct
   std::_Iterator_base0>,class std::_Tree_unchecked_const_iterator<class std::_Tree_val<struct
   std::_Tree_simple_types<struct std::pair<class CAPString const ,int> > >,struct
   std::_Iterator_base0>) __ptr64 */

_Tree_node<std::pair<CAPString_const_,int>,void*___ptr64> * __thiscall
std::
_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
::_Erase_unchecked(_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
                   *this,_Tree_node<std::pair<CAPString_const_,int>,void*___ptr64> *param_2,
                  _Tree_node<std::pair<CAPString_const_,int>,void*___ptr64> *param_3)

{
  _Tree_node<std::pair<CAPString_const_,int>,void*___ptr64> _Var1;
  char cVar2;
  _Tree_node<std::pair<CAPString_const_,int>,void*___ptr64> *p_Var3;
  _Tree_node<std::pair<CAPString_const_,int>,void*___ptr64> *p_Var4;
  _Tree_node<std::pair<CAPString_const_,int>,void*___ptr64> *p_Var5;
  longlong *plVar6;
  _Tree_node<std::pair<CAPString_const_,int>,void*___ptr64> *p_Var7;
  
                    /* 0xa380  195
                       ?_Erase_unchecked@?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@AEAAPEAU?$_Tree_node@U?$pair@$$CBVCAPString@@H@std@@PEAX@2@V?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVCAPString@@H@std@@@std@@@std@@U_Iterator_base0@2@@2@0@Z
                        */
  plVar6 = *(longlong **)this;
  if ((param_2 == (_Tree_node<std::pair<CAPString_const_,int>,void*___ptr64> *)*plVar6) &&
     (param_3[0x19] != (_Tree_node<std::pair<CAPString_const_,int>,void*___ptr64>)0x0)) {
    FUN_180008800(this,this,(longlong *)plVar6[1]);
    plVar6[1] = (longlong)plVar6;
    *plVar6 = (longlong)plVar6;
    plVar6[2] = (longlong)plVar6;
    *(undefined8 *)(this + 8) = 0;
  }
  else {
    while (param_2 != param_3) {
      p_Var3 = *(_Tree_node<std::pair<CAPString_const_,int>,void*___ptr64> **)(param_2 + 0x10);
      if (p_Var3[0x19] == (_Tree_node<std::pair<CAPString_const_,int>,void*___ptr64>)0x0) {
        _Var1 = (*(_Tree_node<std::pair<CAPString_const_,int>,void*___ptr64> **)p_Var3)[0x19];
        p_Var7 = p_Var3;
        p_Var5 = *(_Tree_node<std::pair<CAPString_const_,int>,void*___ptr64> **)p_Var3;
        while (_Var1 == (_Tree_node<std::pair<CAPString_const_,int>,void*___ptr64>)0x0) {
          _Var1 = (*(_Tree_node<std::pair<CAPString_const_,int>,void*___ptr64> **)p_Var5)[0x19];
          p_Var7 = p_Var5;
          p_Var5 = *(_Tree_node<std::pair<CAPString_const_,int>,void*___ptr64> **)p_Var5;
        }
        plVar6 = *(longlong **)p_Var3;
        cVar2 = *(char *)((longlong)plVar6 + 0x19);
        while (cVar2 == '\0') {
          plVar6 = (longlong *)*plVar6;
          cVar2 = *(char *)((longlong)plVar6 + 0x19);
        }
      }
      else {
        _Var1 = (*(_Tree_node<std::pair<CAPString_const_,int>,void*___ptr64> **)(param_2 + 8))[0x19]
        ;
        p_Var5 = *(_Tree_node<std::pair<CAPString_const_,int>,void*___ptr64> **)(param_2 + 8);
        p_Var3 = param_2;
        while ((p_Var7 = p_Var5,
               _Var1 == (_Tree_node<std::pair<CAPString_const_,int>,void*___ptr64>)0x0 &&
               (p_Var3 == *(_Tree_node<std::pair<CAPString_const_,int>,void*___ptr64> **)
                           (p_Var7 + 0x10)))) {
          _Var1 = (*(_Tree_node<std::pair<CAPString_const_,int>,void*___ptr64> **)(p_Var7 + 8))
                  [0x19];
          p_Var5 = *(_Tree_node<std::pair<CAPString_const_,int>,void*___ptr64> **)(p_Var7 + 8);
          p_Var3 = p_Var7;
        }
        _Var1 = (*(_Tree_node<std::pair<CAPString_const_,int>,void*___ptr64> **)(param_2 + 8))[0x19]
        ;
        p_Var5 = *(_Tree_node<std::pair<CAPString_const_,int>,void*___ptr64> **)(param_2 + 8);
        p_Var3 = param_2;
        while ((p_Var4 = p_Var5,
               _Var1 == (_Tree_node<std::pair<CAPString_const_,int>,void*___ptr64>)0x0 &&
               (p_Var3 == *(_Tree_node<std::pair<CAPString_const_,int>,void*___ptr64> **)
                           (p_Var4 + 0x10)))) {
          _Var1 = (*(_Tree_node<std::pair<CAPString_const_,int>,void*___ptr64> **)(p_Var4 + 8))
                  [0x19];
          p_Var5 = *(_Tree_node<std::pair<CAPString_const_,int>,void*___ptr64> **)(p_Var4 + 8);
          p_Var3 = p_Var4;
        }
      }
      plVar6 = FUN_18000a550((longlong *)this,(longlong *)param_2);
      FUN_180009900((longlong)(plVar6 + 4));
      operator_delete(plVar6);
      param_2 = p_Var7;
    }
  }
  return param_3;
}

/* ---- FUNC 0000A4C0 _Erase_unchecked (142 bytes) ---- */

/* private: struct std::_Tree_node<struct std::pair<class CAPString const ,int>,void * __ptr64> *
   __ptr64 __cdecl std::_Tree<class std::_Tmap_traits<class CAPString,int,struct std::less<class
   CAPString>,class std::allocator<struct std::pair<class CAPString const ,int> >,0>
   >::_Erase_unchecked(class std::_Tree_unchecked_const_iterator<class std::_Tree_val<struct
   std::_Tree_simple_types<struct std::pair<class CAPString const ,int> > >,struct
   std::_Iterator_base0>) __ptr64 */

_Tree_node<std::pair<CAPString_const_,int>,void*___ptr64> * __thiscall
std::
_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
::_Erase_unchecked(_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
                   *this,_Tree_node<std::pair<CAPString_const_,int>,void*___ptr64> *param_2)

{
  _Tree_node<std::pair<CAPString_const_,int>,void*___ptr64> _Var1;
  _Tree_node<std::pair<CAPString_const_,int>,void*___ptr64> *p_Var2;
  _Tree_node<std::pair<CAPString_const_,int>,void*___ptr64> *p_Var3;
  longlong *plVar4;
  _Tree_node<std::pair<CAPString_const_,int>,void*___ptr64> *p_Var5;
  
                    /* 0xa4c0  196
                       ?_Erase_unchecked@?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@AEAAPEAU?$_Tree_node@U?$pair@$$CBVCAPString@@H@std@@PEAX@2@V?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVCAPString@@H@std@@@std@@@std@@U_Iterator_base0@2@@2@@Z
                        */
  p_Var5 = *(_Tree_node<std::pair<CAPString_const_,int>,void*___ptr64> **)(param_2 + 0x10);
  if (p_Var5[0x19] == (_Tree_node<std::pair<CAPString_const_,int>,void*___ptr64>)0x0) {
    _Var1 = (*(_Tree_node<std::pair<CAPString_const_,int>,void*___ptr64> **)p_Var5)[0x19];
    p_Var2 = *(_Tree_node<std::pair<CAPString_const_,int>,void*___ptr64> **)p_Var5;
    while (_Var1 == (_Tree_node<std::pair<CAPString_const_,int>,void*___ptr64>)0x0) {
      _Var1 = (*(_Tree_node<std::pair<CAPString_const_,int>,void*___ptr64> **)p_Var2)[0x19];
      p_Var5 = p_Var2;
      p_Var2 = *(_Tree_node<std::pair<CAPString_const_,int>,void*___ptr64> **)p_Var2;
    }
  }
  else {
    _Var1 = (*(_Tree_node<std::pair<CAPString_const_,int>,void*___ptr64> **)(param_2 + 8))[0x19];
    p_Var3 = *(_Tree_node<std::pair<CAPString_const_,int>,void*___ptr64> **)(param_2 + 8);
    p_Var2 = param_2;
    while ((p_Var5 = p_Var3, _Var1 == (_Tree_node<std::pair<CAPString_const_,int>,void*___ptr64>)0x0
           && (p_Var2 == *(_Tree_node<std::pair<CAPString_const_,int>,void*___ptr64> **)
                          (p_Var5 + 0x10)))) {
      _Var1 = (*(_Tree_node<std::pair<CAPString_const_,int>,void*___ptr64> **)(p_Var5 + 8))[0x19];
      p_Var3 = *(_Tree_node<std::pair<CAPString_const_,int>,void*___ptr64> **)(p_Var5 + 8);
      p_Var2 = p_Var5;
    }
  }
  plVar4 = FUN_18000a550((longlong *)this,(longlong *)param_2);
  FUN_180009900((longlong)(plVar4 + 4));
  operator_delete(plVar4);
  return p_Var5;
}

/* ---- FUNC 0000A550 FUN_18000a550 (19 bytes) ---- */

longlong * FUN_18000a550(longlong *param_1,longlong *param_2)

{
  char cVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong *plVar5;
  longlong *plVar6;
  longlong *plVar7;
  
  plVar3 = (longlong *)param_2[2];
  plVar4 = param_2 + 2;
  if (*(char *)((longlong)plVar3 + 0x19) == '\0') {
    cVar1 = *(char *)(*plVar3 + 0x19);
    plVar5 = (longlong *)*plVar3;
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*plVar5 + 0x19);
      plVar3 = plVar5;
      plVar5 = (longlong *)*plVar5;
    }
  }
  else {
    cVar1 = *(char *)(param_2[1] + 0x19);
    plVar6 = (longlong *)param_2[1];
    plVar5 = param_2;
    while ((plVar3 = plVar6, cVar1 == '\0' && (plVar5 == (longlong *)plVar3[2]))) {
      cVar1 = *(char *)(plVar3[1] + 0x19);
      plVar6 = (longlong *)plVar3[1];
      plVar5 = plVar3;
    }
  }
  plVar7 = param_2 + 1;
  plVar5 = (longlong *)*param_2;
  plVar6 = (longlong *)*plVar4;
  if (((*(char *)((longlong)plVar5 + 0x19) == '\0') &&
      (plVar6 = plVar5, *(char *)(*plVar4 + 0x19) == '\0')) &&
     (plVar6 = (longlong *)plVar3[2], plVar3 != param_2)) {
    plVar5[1] = (longlong)plVar3;
    *plVar3 = *param_2;
    plVar5 = plVar3;
    if (plVar3 != (longlong *)*plVar4) {
      plVar5 = (longlong *)plVar3[1];
      if (*(char *)((longlong)plVar6 + 0x19) == '\0') {
        plVar6[1] = (longlong)plVar5;
      }
      *plVar5 = (longlong)plVar6;
      plVar3[2] = *plVar4;
      *(longlong **)(*plVar4 + 8) = plVar3;
    }
    if (*(longlong **)(*param_1 + 8) == param_2) {
      *(longlong **)(*param_1 + 8) = plVar3;
    }
    else {
      plVar4 = (longlong *)*plVar7;
      if ((longlong *)*plVar4 == param_2) {
        *plVar4 = (longlong)plVar3;
      }
      else {
        plVar4[2] = (longlong)plVar3;
      }
    }
    lVar2 = plVar3[3];
    plVar3[1] = *plVar7;
    *(char *)(plVar3 + 3) = (char)param_2[3];
    *(char *)(param_2 + 3) = (char)lVar2;
  }
  else {
    plVar5 = (longlong *)*plVar7;
    if (*(char *)((longlong)plVar6 + 0x19) == '\0') {
      plVar6[1] = (longlong)plVar5;
    }
    if (*(longlong **)(*param_1 + 8) == param_2) {
      *(longlong **)(*param_1 + 8) = plVar6;
    }
    else if ((longlong *)*plVar5 == param_2) {
      *plVar5 = (longlong)plVar6;
    }
    else {
      plVar5[2] = (longlong)plVar6;
    }
    if (*(longlong **)*param_1 == param_2) {
      plVar4 = plVar5;
      if (*(char *)((longlong)plVar6 + 0x19) == '\0') {
        cVar1 = *(char *)(*plVar6 + 0x19);
        plVar3 = (longlong *)*plVar6;
        plVar4 = plVar6;
        while (plVar7 = plVar3, cVar1 == '\0') {
          plVar3 = (longlong *)*plVar7;
          cVar1 = *(char *)((longlong)plVar3 + 0x19);
          plVar4 = plVar7;
        }
      }
      *(longlong **)*param_1 = plVar4;
    }
    lVar2 = *param_1;
    if (*(longlong **)(lVar2 + 0x10) == param_2) {
      if (*(char *)((longlong)plVar6 + 0x19) == '\0') {
        cVar1 = *(char *)(plVar6[2] + 0x19);
        plVar4 = (longlong *)plVar6[2];
        plVar3 = plVar6;
        while (plVar7 = plVar4, cVar1 == '\0') {
          plVar4 = (longlong *)plVar7[2];
          cVar1 = *(char *)((longlong)plVar4 + 0x19);
          plVar3 = plVar7;
        }
        *(longlong **)(lVar2 + 0x10) = plVar3;
      }
      else {
        *(longlong **)(lVar2 + 0x10) = plVar5;
      }
    }
  }
  if ((char)param_2[3] == '\x01') {
    if (plVar6 != *(longlong **)(*param_1 + 8)) {
      do {
        plVar4 = plVar5;
        if ((char)plVar6[3] != '\x01') break;
        plVar3 = (longlong *)*plVar4;
        if (plVar6 == plVar3) {
          plVar3 = (longlong *)plVar4[2];
          if ((char)plVar3[3] == '\0') {
            *(undefined1 *)(plVar3 + 3) = 1;
            plVar3 = (longlong *)plVar4[2];
            *(undefined1 *)(plVar4 + 3) = 0;
            plVar4[2] = *plVar3;
            if (*(char *)(*plVar3 + 0x19) == '\0') {
              *(longlong **)(*plVar3 + 8) = plVar4;
            }
            plVar5 = plVar4 + 1;
            plVar3[1] = plVar4[1];
            if (plVar4 == *(longlong **)(*param_1 + 8)) {
              *(longlong **)(*param_1 + 8) = plVar3;
              *plVar3 = (longlong)plVar4;
              *plVar5 = (longlong)plVar3;
              plVar3 = (longlong *)plVar4[2];
            }
            else {
              plVar7 = (longlong *)*plVar5;
              if (plVar4 == (longlong *)*plVar7) {
                *plVar7 = (longlong)plVar3;
                *plVar3 = (longlong)plVar4;
                *plVar5 = (longlong)plVar3;
                plVar3 = (longlong *)plVar4[2];
              }
              else {
                plVar7[2] = (longlong)plVar3;
                *plVar3 = (longlong)plVar4;
                *plVar5 = (longlong)plVar3;
                plVar3 = (longlong *)plVar4[2];
              }
            }
          }
          if (*(char *)((longlong)plVar3 + 0x19) == '\0') {
            if ((*(char *)(*plVar3 + 0x18) != '\x01') || (*(char *)(plVar3[2] + 0x18) != '\x01')) {
              if (*(char *)(plVar3[2] + 0x18) == '\x01') {
                *(undefined1 *)(*plVar3 + 0x18) = 1;
                *(undefined1 *)(plVar3 + 3) = 0;
                FUN_18000abf0(param_1,plVar3);
                plVar3 = (longlong *)plVar4[2];
              }
              *(char *)(plVar3 + 3) = (char)plVar4[3];
              *(undefined1 *)(plVar4 + 3) = 1;
              *(undefined1 *)(plVar3[2] + 0x18) = 1;
              FUN_18000ab90(param_1,(longlong)plVar4);
              break;
            }
LAB_18000a89b:
            *(undefined1 *)(plVar3 + 3) = 0;
          }
        }
        else {
          if ((char)plVar3[3] == '\0') {
            *(undefined1 *)(plVar3 + 3) = 1;
            lVar2 = *plVar4;
            *(undefined1 *)(plVar4 + 3) = 0;
            *plVar4 = *(longlong *)(lVar2 + 0x10);
            if (*(char *)(*(longlong *)(lVar2 + 0x10) + 0x19) == '\0') {
              *(longlong **)(*(longlong *)(lVar2 + 0x10) + 8) = plVar4;
            }
            plVar3 = plVar4 + 1;
            *(longlong *)(lVar2 + 8) = plVar4[1];
            if (plVar4 == *(longlong **)(*param_1 + 8)) {
              *(longlong *)(*param_1 + 8) = lVar2;
              *(longlong **)(lVar2 + 0x10) = plVar4;
              *plVar3 = lVar2;
              plVar3 = (longlong *)*plVar4;
            }
            else {
              plVar5 = (longlong *)*plVar3;
              if (plVar4 == (longlong *)plVar5[2]) {
                plVar5[2] = lVar2;
                *(longlong **)(lVar2 + 0x10) = plVar4;
                *plVar3 = lVar2;
                plVar3 = (longlong *)*plVar4;
              }
              else {
                *plVar5 = lVar2;
                *(longlong **)(lVar2 + 0x10) = plVar4;
                *plVar3 = lVar2;
                plVar3 = (longlong *)*plVar4;
              }
            }
          }
          if (*(char *)((longlong)plVar3 + 0x19) == '\0') {
            if ((*(char *)(plVar3[2] + 0x18) == '\x01') && (*(char *)(*plVar3 + 0x18) == '\x01'))
            goto LAB_18000a89b;
            if (*(char *)(*plVar3 + 0x18) == '\x01') {
              *(undefined1 *)(plVar3[2] + 0x18) = 1;
              *(undefined1 *)(plVar3 + 3) = 0;
              FUN_18000ab90(param_1,(longlong)plVar3);
              plVar3 = (longlong *)*plVar4;
            }
            *(char *)(plVar3 + 3) = (char)plVar4[3];
            *(undefined1 *)(plVar4 + 3) = 1;
            *(undefined1 *)(*plVar3 + 0x18) = 1;
            FUN_18000abf0(param_1,plVar4);
            break;
          }
        }
        plVar5 = (longlong *)plVar4[1];
        plVar6 = plVar4;
      } while (plVar4 != *(longlong **)(*param_1 + 8));
    }
    *(undefined1 *)(plVar6 + 3) = 1;
  }
  if (param_1[1] != 0) {
    param_1[1] = param_1[1] + -1;
  }
  return param_2;
}

/* ---- FUNC 0000A563 FUN_18000a563 (936 bytes) ---- */

longlong * FUN_18000a563(longlong *param_1,longlong *param_2,undefined8 param_3,longlong *param_4)

{
  char cVar1;
  longlong lVar2;
  undefined8 *puVar3;
  longlong *plVar4;
  longlong *plVar5;
  longlong *in_RAX;
  longlong *plVar6;
  longlong *plVar7;
  longlong *plVar8;
  
  if (*(char *)((longlong)in_RAX + 0x19) == '\0') {
    cVar1 = *(char *)(*in_RAX + 0x19);
    plVar6 = (longlong *)*in_RAX;
    while (plVar8 = plVar6, cVar1 == '\0') {
      plVar6 = (longlong *)*plVar8;
      cVar1 = *(char *)((longlong)plVar6 + 0x19);
      in_RAX = plVar8;
    }
  }
  else {
    cVar1 = *(char *)(param_2[1] + 0x19);
    plVar8 = (longlong *)param_2[1];
    plVar6 = param_2;
    while ((in_RAX = plVar8, cVar1 == '\0' && (plVar6 == (longlong *)in_RAX[2]))) {
      cVar1 = *(char *)(in_RAX[1] + 0x19);
      plVar8 = (longlong *)in_RAX[1];
      plVar6 = in_RAX;
    }
  }
  plVar7 = param_2 + 1;
  plVar6 = (longlong *)*param_2;
  plVar8 = (longlong *)*param_4;
  if (((*(char *)((longlong)plVar6 + 0x19) == '\0') &&
      (plVar8 = plVar6, *(char *)(*param_4 + 0x19) == '\0')) &&
     (plVar8 = (longlong *)in_RAX[2], in_RAX != param_2)) {
    plVar6[1] = (longlong)in_RAX;
    *in_RAX = *param_2;
    plVar6 = in_RAX;
    if (in_RAX != (longlong *)*param_4) {
      plVar6 = (longlong *)in_RAX[1];
      if (*(char *)((longlong)plVar8 + 0x19) == '\0') {
        plVar8[1] = (longlong)plVar6;
      }
      *plVar6 = (longlong)plVar8;
      in_RAX[2] = *param_4;
      *(longlong **)(*param_4 + 8) = in_RAX;
    }
    if (*(longlong **)(*param_1 + 8) == param_2) {
      *(longlong **)(*param_1 + 8) = in_RAX;
    }
    else {
      puVar3 = (undefined8 *)*plVar7;
      if ((longlong *)*puVar3 == param_2) {
        *puVar3 = in_RAX;
      }
      else {
        puVar3[2] = in_RAX;
      }
    }
    lVar2 = in_RAX[3];
    in_RAX[1] = *plVar7;
    *(char *)(in_RAX + 3) = (char)param_2[3];
    *(char *)(param_2 + 3) = (char)lVar2;
  }
  else {
    plVar6 = (longlong *)*plVar7;
    if (*(char *)((longlong)plVar8 + 0x19) == '\0') {
      plVar8[1] = (longlong)plVar6;
    }
    if (*(longlong **)(*param_1 + 8) == param_2) {
      *(longlong **)(*param_1 + 8) = plVar8;
    }
    else if ((longlong *)*plVar6 == param_2) {
      *plVar6 = (longlong)plVar8;
    }
    else {
      plVar6[2] = (longlong)plVar8;
    }
    if (*(longlong **)*param_1 == param_2) {
      plVar7 = plVar6;
      if (*(char *)((longlong)plVar8 + 0x19) == '\0') {
        cVar1 = *(char *)(*plVar8 + 0x19);
        plVar5 = (longlong *)*plVar8;
        plVar7 = plVar8;
        while (plVar4 = plVar5, cVar1 == '\0') {
          plVar5 = (longlong *)*plVar4;
          cVar1 = *(char *)((longlong)plVar5 + 0x19);
          plVar7 = plVar4;
        }
      }
      *(longlong **)*param_1 = plVar7;
    }
    lVar2 = *param_1;
    if (*(longlong **)(lVar2 + 0x10) == param_2) {
      if (*(char *)((longlong)plVar8 + 0x19) == '\0') {
        cVar1 = *(char *)(plVar8[2] + 0x19);
        plVar7 = (longlong *)plVar8[2];
        plVar5 = plVar8;
        while (plVar4 = plVar7, cVar1 == '\0') {
          plVar7 = (longlong *)plVar4[2];
          cVar1 = *(char *)((longlong)plVar7 + 0x19);
          plVar5 = plVar4;
        }
        *(longlong **)(lVar2 + 0x10) = plVar5;
      }
      else {
        *(longlong **)(lVar2 + 0x10) = plVar6;
      }
    }
  }
  if ((char)param_2[3] == '\x01') {
    if (plVar8 != *(longlong **)(*param_1 + 8)) {
      do {
        plVar7 = plVar6;
        if ((char)plVar8[3] != '\x01') break;
        plVar6 = (longlong *)*plVar7;
        if (plVar8 == plVar6) {
          plVar6 = (longlong *)plVar7[2];
          if ((char)plVar6[3] == '\0') {
            *(undefined1 *)(plVar6 + 3) = 1;
            plVar6 = (longlong *)plVar7[2];
            *(undefined1 *)(plVar7 + 3) = 0;
            plVar7[2] = *plVar6;
            if (*(char *)(*plVar6 + 0x19) == '\0') {
              *(longlong **)(*plVar6 + 8) = plVar7;
            }
            plVar5 = plVar7 + 1;
            plVar6[1] = plVar7[1];
            if (plVar7 == *(longlong **)(*param_1 + 8)) {
              *(longlong **)(*param_1 + 8) = plVar6;
              *plVar6 = (longlong)plVar7;
              *plVar5 = (longlong)plVar6;
              plVar6 = (longlong *)plVar7[2];
            }
            else {
              plVar4 = (longlong *)*plVar5;
              if (plVar7 == (longlong *)*plVar4) {
                *plVar4 = (longlong)plVar6;
                *plVar6 = (longlong)plVar7;
                *plVar5 = (longlong)plVar6;
                plVar6 = (longlong *)plVar7[2];
              }
              else {
                plVar4[2] = (longlong)plVar6;
                *plVar6 = (longlong)plVar7;
                *plVar5 = (longlong)plVar6;
                plVar6 = (longlong *)plVar7[2];
              }
            }
          }
          if (*(char *)((longlong)plVar6 + 0x19) == '\0') {
            if ((*(char *)(*plVar6 + 0x18) != '\x01') || (*(char *)(plVar6[2] + 0x18) != '\x01')) {
              if (*(char *)(plVar6[2] + 0x18) == '\x01') {
                *(undefined1 *)(*plVar6 + 0x18) = 1;
                *(undefined1 *)(plVar6 + 3) = 0;
                FUN_18000abf0(param_1,plVar6);
                plVar6 = (longlong *)plVar7[2];
              }
              *(char *)(plVar6 + 3) = (char)plVar7[3];
              *(undefined1 *)(plVar7 + 3) = 1;
              *(undefined1 *)(plVar6[2] + 0x18) = 1;
              FUN_18000ab90(param_1,(longlong)plVar7);
              break;
            }
LAB_18000a89b:
            *(undefined1 *)(plVar6 + 3) = 0;
          }
        }
        else {
          if ((char)plVar6[3] == '\0') {
            *(undefined1 *)(plVar6 + 3) = 1;
            lVar2 = *plVar7;
            *(undefined1 *)(plVar7 + 3) = 0;
            *plVar7 = *(longlong *)(lVar2 + 0x10);
            if (*(char *)(*(longlong *)(lVar2 + 0x10) + 0x19) == '\0') {
              *(longlong **)(*(longlong *)(lVar2 + 0x10) + 8) = plVar7;
            }
            plVar6 = plVar7 + 1;
            *(longlong *)(lVar2 + 8) = plVar7[1];
            if (plVar7 == *(longlong **)(*param_1 + 8)) {
              *(longlong *)(*param_1 + 8) = lVar2;
              *(longlong **)(lVar2 + 0x10) = plVar7;
              *plVar6 = lVar2;
              plVar6 = (longlong *)*plVar7;
            }
            else {
              plVar5 = (longlong *)*plVar6;
              if (plVar7 == (longlong *)plVar5[2]) {
                plVar5[2] = lVar2;
                *(longlong **)(lVar2 + 0x10) = plVar7;
                *plVar6 = lVar2;
                plVar6 = (longlong *)*plVar7;
              }
              else {
                *plVar5 = lVar2;
                *(longlong **)(lVar2 + 0x10) = plVar7;
                *plVar6 = lVar2;
                plVar6 = (longlong *)*plVar7;
              }
            }
          }
          if (*(char *)((longlong)plVar6 + 0x19) == '\0') {
            if ((*(char *)(plVar6[2] + 0x18) == '\x01') && (*(char *)(*plVar6 + 0x18) == '\x01'))
            goto LAB_18000a89b;
            if (*(char *)(*plVar6 + 0x18) == '\x01') {
              *(undefined1 *)(plVar6[2] + 0x18) = 1;
              *(undefined1 *)(plVar6 + 3) = 0;
              FUN_18000ab90(param_1,(longlong)plVar6);
              plVar6 = (longlong *)*plVar7;
            }
            *(char *)(plVar6 + 3) = (char)plVar7[3];
            *(undefined1 *)(plVar7 + 3) = 1;
            *(undefined1 *)(*plVar6 + 0x18) = 1;
            FUN_18000abf0(param_1,plVar7);
            break;
          }
        }
        plVar6 = (longlong *)plVar7[1];
        plVar8 = plVar7;
      } while (plVar7 != *(longlong **)(*param_1 + 8));
    }
    *(undefined1 *)(plVar8 + 3) = 1;
  }
  if (param_1[1] != 0) {
    param_1[1] = param_1[1] + -1;
  }
  return param_2;
}

/* ---- FUNC 0000A90B FUN_18000a90b (19 bytes) ---- */

void FUN_18000a90b(longlong param_1)

{
  longlong unaff_RSI;
  
  *(longlong *)(unaff_RSI + 8) = param_1 + -1;
  return;
}

/* ---- FUNC 0000A920 _Get_scary (4 bytes) ---- */

/* protected: class std::_Tree_val<struct std::_Tree_simple_types<struct std::pair<class CAPString
   const ,int> > > * __ptr64 __cdecl std::_Tree<class std::_Tmap_traits<class CAPString,int,struct
   std::less<class CAPString>,class std::allocator<struct std::pair<class CAPString const ,int> >,0>
   >::_Get_scary(void) __ptr64 */

_Tree_val<std::_Tree_simple_types<std::pair<CAPString_const_,int>_>_> * __thiscall
std::
_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
::_Get_scary(_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
             *this)

{
                    /* 0xa920  197
                       ?_Get_scary@?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@IEAAPEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVCAPString@@H@std@@@std@@@2@XZ
                       0xa920  198
                       ?_Get_scary@?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@IEBAPEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVCAPString@@H@std@@@std@@@2@XZ
                       0xa920  199
                       ?_Getal@?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@IEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBVCAPString@@H@std@@PEAX@std@@@2@XZ
                       0xa920  200
                       ?_Getal@?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@IEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBVCAPString@@H@std@@PEAX@std@@@2@XZ
                       0xa920  201
                       ?_Getcomp@?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@IEAAAEAU?$less@VCAPString@@@2@XZ
                       0xa920  202
                       ?_Getcomp@?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@IEBAAEBU?$less@VCAPString@@@2@XZ
                        */
  return (_Tree_val<std::_Tree_simple_types<std::pair<CAPString_const_,int>_>_> *)this;
}

/* ---- FUNC 0000A930 FUN_18000a930 (603 bytes) ---- */

longlong * FUN_18000a930(longlong *param_1,longlong *param_2,longlong *param_3)

{
  char cVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  longlong *plVar6;
  longlong *plVar7;
  longlong *plVar8;
  
  param_1[1] = param_1[1] + 1;
  plVar2 = (longlong *)*param_1;
  plVar6 = (longlong *)*param_2;
  param_3[1] = (longlong)plVar6;
  if (plVar6 == plVar2) {
    *plVar2 = (longlong)param_3;
    plVar2[1] = (longlong)param_3;
    plVar2[2] = (longlong)param_3;
    *(undefined1 *)(param_3 + 3) = 1;
    return param_3;
  }
  if ((int)param_2[1] == 0) {
    plVar6[2] = (longlong)param_3;
    if (plVar6 == (longlong *)plVar2[2]) {
      plVar2[2] = (longlong)param_3;
    }
  }
  else {
    *plVar6 = (longlong)param_3;
    if (plVar6 == (longlong *)*plVar2) {
      *plVar2 = (longlong)param_3;
    }
  }
  cVar1 = *(char *)(param_3[1] + 0x18);
  plVar6 = param_3;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(plVar2[1] + 0x18) = 1;
      return param_3;
    }
    plVar7 = (longlong *)plVar6[1];
    lVar3 = *(longlong *)plVar7[1];
    if (plVar7 == (longlong *)lVar3) {
      lVar3 = ((longlong *)plVar7[1])[2];
      if (*(char *)(lVar3 + 0x18) == '\0') {
        *(undefined1 *)(plVar7 + 3) = 1;
        *(undefined1 *)(lVar3 + 0x18) = 1;
        *(undefined1 *)(*(longlong *)(plVar6[1] + 8) + 0x18) = 0;
        plVar6 = *(longlong **)(plVar6[1] + 8);
      }
      else {
        plVar8 = (longlong *)plVar7[2];
        if (plVar6 == plVar8) {
          plVar7[2] = *plVar8;
          if (*(char *)(*plVar8 + 0x19) == '\0') {
            *(longlong **)(*plVar8 + 8) = plVar7;
          }
          plVar8[1] = plVar7[1];
          if (plVar7 == (longlong *)*(longlong *)(*param_1 + 8)) {
            *(longlong **)(*param_1 + 8) = plVar8;
          }
          else {
            plVar6 = (longlong *)plVar7[1];
            if (plVar7 == (longlong *)*plVar6) {
              *plVar6 = (longlong)plVar8;
            }
            else {
              plVar6[2] = (longlong)plVar8;
            }
          }
          *plVar8 = (longlong)plVar7;
          plVar7[1] = (longlong)plVar8;
          plVar6 = plVar7;
        }
        *(undefined1 *)(plVar6[1] + 0x18) = 1;
        *(undefined1 *)(*(longlong *)(plVar6[1] + 8) + 0x18) = 0;
        plVar7 = *(longlong **)(plVar6[1] + 8);
        plVar8 = (longlong *)*plVar7;
        *plVar7 = plVar8[2];
        if (*(char *)(plVar8[2] + 0x19) == '\0') {
          *(longlong **)(plVar8[2] + 8) = plVar7;
        }
        plVar8[1] = plVar7[1];
        if (plVar7 == *(longlong **)(*param_1 + 8)) {
          *(longlong **)(*param_1 + 8) = plVar8;
          plVar8[2] = (longlong)plVar7;
        }
        else {
          plVar4 = (longlong *)plVar7[1];
          if (plVar7 == (longlong *)plVar4[2]) {
            plVar4[2] = (longlong)plVar8;
            plVar8[2] = (longlong)plVar7;
          }
          else {
            *plVar4 = (longlong)plVar8;
            plVar8[2] = (longlong)plVar7;
          }
        }
LAB_18000ab6d:
        plVar7[1] = (longlong)plVar8;
      }
    }
    else {
      if (*(char *)(lVar3 + 0x18) != '\0') {
        plVar8 = (longlong *)*plVar7;
        if (plVar6 == plVar8) {
          *plVar7 = plVar8[2];
          if (*(char *)(plVar8[2] + 0x19) == '\0') {
            *(longlong **)(plVar8[2] + 8) = plVar7;
          }
          plVar8[1] = plVar7[1];
          if (plVar7 == (longlong *)*(longlong *)(*param_1 + 8)) {
            *(longlong **)(*param_1 + 8) = plVar8;
          }
          else {
            puVar5 = (undefined8 *)plVar7[1];
            if (plVar7 == (longlong *)puVar5[2]) {
              puVar5[2] = plVar8;
            }
            else {
              *puVar5 = plVar8;
            }
          }
          plVar8[2] = (longlong)plVar7;
          plVar7[1] = (longlong)plVar8;
          plVar6 = plVar7;
        }
        *(undefined1 *)(plVar6[1] + 0x18) = 1;
        *(undefined1 *)(*(longlong *)(plVar6[1] + 8) + 0x18) = 0;
        plVar7 = *(longlong **)(plVar6[1] + 8);
        plVar8 = (longlong *)plVar7[2];
        plVar7[2] = *plVar8;
        if (*(char *)(*plVar8 + 0x19) == '\0') {
          *(longlong **)(*plVar8 + 8) = plVar7;
        }
        plVar8[1] = plVar7[1];
        if (plVar7 == *(longlong **)(*param_1 + 8)) {
          *(longlong **)(*param_1 + 8) = plVar8;
        }
        else {
          puVar5 = (undefined8 *)plVar7[1];
          if (plVar7 == (longlong *)*puVar5) {
            *puVar5 = plVar8;
          }
          else {
            puVar5[2] = plVar8;
          }
        }
        *plVar8 = (longlong)plVar7;
        goto LAB_18000ab6d;
      }
      *(undefined1 *)(plVar7 + 3) = 1;
      *(undefined1 *)(lVar3 + 0x18) = 1;
      *(undefined1 *)(*(longlong *)(plVar6[1] + 8) + 0x18) = 0;
      plVar6 = *(longlong **)(plVar6[1] + 8);
    }
    cVar1 = *(char *)(plVar6[1] + 0x18);
  } while( true );
}

/* ---- FUNC 0000AB90 FUN_18000ab90 (85 bytes) ---- */

void FUN_18000ab90(longlong *param_1,longlong param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  
  plVar1 = *(longlong **)(param_2 + 0x10);
  *(longlong *)(param_2 + 0x10) = *plVar1;
  if (*(char *)(*plVar1 + 0x19) == '\0') {
    *(longlong *)(*plVar1 + 8) = param_2;
  }
  plVar1[1] = *(longlong *)(param_2 + 8);
  if (param_2 == *(longlong *)(*param_1 + 8)) {
    *(longlong **)(*param_1 + 8) = plVar1;
    *plVar1 = param_2;
    *(longlong **)(param_2 + 8) = plVar1;
    return;
  }
  plVar2 = *(longlong **)(param_2 + 8);
  if (param_2 == *plVar2) {
    *plVar2 = (longlong)plVar1;
    *plVar1 = param_2;
    *(longlong **)(param_2 + 8) = plVar1;
    return;
  }
  plVar2[2] = (longlong)plVar1;
  *plVar1 = param_2;
  *(longlong **)(param_2 + 8) = plVar1;
  return;
}

/* ---- FUNC 0000ABF0 FUN_18000abf0 (89 bytes) ---- */

void FUN_18000abf0(longlong *param_1,longlong *param_2)

{
  longlong lVar1;
  longlong *plVar2;
  
  lVar1 = *param_2;
  *param_2 = *(longlong *)(lVar1 + 0x10);
  if (*(char *)(*(longlong *)(lVar1 + 0x10) + 0x19) == '\0') {
    *(longlong **)(*(longlong *)(lVar1 + 0x10) + 8) = param_2;
  }
  *(longlong *)(lVar1 + 8) = param_2[1];
  if (param_2 == *(longlong **)(*param_1 + 8)) {
    *(longlong *)(*param_1 + 8) = lVar1;
    *(longlong **)(lVar1 + 0x10) = param_2;
    param_2[1] = lVar1;
    return;
  }
  plVar2 = (longlong *)param_2[1];
  if (param_2 == (longlong *)plVar2[2]) {
    plVar2[2] = lVar1;
    *(longlong **)(lVar1 + 0x10) = param_2;
    param_2[1] = lVar1;
    return;
  }
  *plVar2 = lVar1;
  *(longlong **)(lVar1 + 0x10) = param_2;
  param_2[1] = lVar1;
  return;
}

/* ---- FUNC 0000AC50 _Swap_val_excluding_comp (29 bytes) ---- */

/* private: void __cdecl std::_Tree<class std::_Tmap_traits<class CAPString,int,struct
   std::less<class CAPString>,class std::allocator<struct std::pair<class CAPString const ,int> >,0>
   >::_Swap_val_excluding_comp(class std::_Tree<class std::_Tmap_traits<class CAPString,int,struct
   std::less<class CAPString>,class std::allocator<struct std::pair<class CAPString const ,int> >,0>
   > & __ptr64) __ptr64 */

void __thiscall
std::
_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
::_Swap_val_excluding_comp
          (_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
           *this,_Tree<class_std::_Tmap_traits<class_CAPString,int,struct_std::less<class_CAPString>,class_std::allocator<struct_std::pair<class_CAPString_const_,int>_>,0>_>
                 *param_1)

{
  undefined8 uVar1;
  
                    /* 0xac50  203
                       ?_Swap_val_excluding_comp@?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@AEAAXAEAV12@@Z
                        */
  uVar1 = *(undefined8 *)this;
  *(undefined8 *)this = *(undefined8 *)param_1;
  *(undefined8 *)param_1 = uVar1;
  uVar1 = *(undefined8 *)(this + 8);
  *(undefined8 *)(this + 8) = *(undefined8 *)(param_1 + 8);
  *(undefined8 *)(param_1 + 8) = uVar1;
  return;
}

/* ---- FUNC 0000AC70 FUN_18000ac70 (31 bytes) ---- */

void FUN_18000ac70(void)

{
  undefined8 local_28 [5];
  
  FUN_180009280(local_28);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_28,(ThrowInfo *)&DAT_1800652c8);
}

/* ---- FUNC 0000AC90 FUN_18000ac90 (16 bytes) ---- */

void FUN_18000ac90(void)

{
                    /* WARNING: Subroutine does not return */
  std::_Xlength_error("map/set too long");
}

/* ---- FUNC 0000ACB0 _Unchecked_begin (13 bytes) ---- */

/* public: class std::_Tree_unchecked_iterator<class std::_Tree_val<struct
   std::_Tree_simple_types<struct std::pair<class CAPString const ,int> > > > __cdecl
   std::_Tree<class std::_Tmap_traits<class CAPString,int,struct std::less<class CAPString>,class
   std::allocator<struct std::pair<class CAPString const ,int> >,0> >::_Unchecked_begin(void)
   __ptr64 */

void __thiscall
std::
_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
::_Unchecked_begin(_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
                   *this)

{
  undefined8 *in_RDX;
  
                    /* 0xacb0  204
                       ?_Unchecked_begin@?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_unchecked_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVCAPString@@H@std@@@std@@@std@@@2@XZ
                       0xacb0  205
                       ?_Unchecked_begin@?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@QEBA?AV?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVCAPString@@H@std@@@std@@@std@@U_Iterator_base0@2@@2@XZ
                       0xacb0  210
                       ?begin@?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVCAPString@@H@std@@@std@@@std@@@2@XZ
                       0xacb0  211
                       ?begin@?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@QEBA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVCAPString@@H@std@@@std@@@std@@@2@XZ
                       0xacb0  212
                       ?cbegin@?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@QEBA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVCAPString@@H@std@@@std@@@std@@@2@XZ
                       0xacb0  217
                       ?crend@?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@QEBA?AV?$reverse_iterator@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVCAPString@@H@std@@@std@@@std@@@std@@@2@XZ
                       0xacb0  252
                       ?rend@?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@QEAA?AV?$reverse_iterator@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVCAPString@@H@std@@@std@@@std@@@std@@@2@XZ
                       0xacb0  253
                       ?rend@?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@QEBA?AV?$reverse_iterator@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVCAPString@@H@std@@@std@@@std@@@std@@@2@XZ
                        */
  *in_RDX = **(undefined8 **)this;
  return;
}

/* ---- FUNC 0000ACC0 _Unchecked_end (8 bytes) ---- */

/* public: struct std::_Default_sentinel __cdecl std::_Tree<class std::_Tmap_traits<class
   CAPString,int,struct std::less<class CAPString>,class std::allocator<struct std::pair<class
   CAPString const ,int> >,0> >::_Unchecked_end(void)const __ptr64 */

void __thiscall
std::
_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
::_Unchecked_end(_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
                 *this)

{
  undefined1 *in_RDX;
  
                    /* 0xacc0  206
                       ?_Unchecked_end@?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@QEBA?AU_Default_sentinel@2@XZ
                        */
  *in_RDX = 0;
  return;
}

/* ---- FUNC 0000ACD0 _Unchecked_end_iter (10 bytes) ---- */

/* public: class std::_Tree_unchecked_const_iterator<class std::_Tree_val<struct
   std::_Tree_simple_types<struct std::pair<class CAPString const ,int> > >,struct
   std::_Iterator_base0> __cdecl std::_Tree<class std::_Tmap_traits<class CAPString,int,struct
   std::less<class CAPString>,class std::allocator<struct std::pair<class CAPString const ,int> >,0>
   >::_Unchecked_end_iter(void)const __ptr64 */

void __thiscall
std::
_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
::_Unchecked_end_iter
          (_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
           *this)

{
  undefined8 *in_RDX;
  
                    /* 0xacd0  207
                       ?_Unchecked_end_iter@?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@QEBA?AV?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVCAPString@@H@std@@@std@@@std@@U_Iterator_base0@2@@2@XZ
                       0xacd0  213
                       ?cend@?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@QEBA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVCAPString@@H@std@@@std@@@std@@@2@XZ
                       0xacd0  216
                       ?crbegin@?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@QEBA?AV?$reverse_iterator@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVCAPString@@H@std@@@std@@@std@@@std@@@2@XZ
                       0xacd0  219
                       ?end@?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVCAPString@@H@std@@@std@@@std@@@2@XZ
                       0xacd0  220
                       ?end@?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@QEBA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVCAPString@@H@std@@@std@@@std@@@2@XZ
                       0xacd0  250
                       ?rbegin@?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@QEAA?AV?$reverse_iterator@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVCAPString@@H@std@@@std@@@std@@@std@@@2@XZ
                       0xacd0  251
                       ?rbegin@?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@QEBA?AV?$reverse_iterator@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVCAPString@@H@std@@@std@@@std@@@std@@@2@XZ
                        */
  *in_RDX = *(undefined8 *)this;
  return;
}

/* ---- FUNC 0000ACE0 FUN_18000ace0 (16 bytes) ---- */

void FUN_18000ace0(void)

{
                    /* WARNING: Subroutine does not return */
  std::_Xlength_error("string too long");
}

/* ---- FUNC 0000AD00 FUN_18000ad00 (16 bytes) ---- */

void FUN_18000ad00(void)

{
                    /* WARNING: Subroutine does not return */
  std::_Xlength_error("vector too long");
}

/* ---- FUNC 0000AD20 FUN_18000ad20 (91 bytes) ---- */

longlong * FUN_18000ad20(longlong *param_1,void *param_2,size_t param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  void *pvVar3;
  void *_Dst;
  ulonglong uVar4;
  void *pvVar5;
  longlong *_Dst_00;
  ulonglong uVar6;
  
  uVar2 = param_1[3];
  if (uVar2 < param_3) {
    uVar6 = 0x7fffffffffffffff;
    if (0x7fffffffffffffff < param_3) {
                    /* WARNING: Subroutine does not return */
      FUN_18000ace0();
    }
    uVar4 = param_3 | 0xf;
    if (uVar4 < 0x8000000000000000) {
      if (0x7fffffffffffffff - (uVar2 >> 1) < uVar2) {
        _Dst = (void *)FUN_180007f10(0x8000000000000000);
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
          _Dst = (void *)FUN_180007f10(uVar4);
        }
      }
    }
    else {
      _Dst = (void *)FUN_180007f10(0x8000000000000000);
    }
    param_1[2] = param_3;
    param_1[3] = uVar6;
    memcpy(_Dst,param_2,param_3);
    *(undefined1 *)((longlong)_Dst + param_3) = 0;
    if (0xf < uVar2) {
      pvVar3 = (void *)*param_1;
      pvVar5 = pvVar3;
      if ((0xfff < uVar2 + 1) &&
         (pvVar5 = *(void **)((longlong)pvVar3 + -8),
         0x1f < (ulonglong)((longlong)pvVar3 + (-8 - (longlong)pvVar5)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      operator_delete(pvVar5);
    }
    *param_1 = (longlong)_Dst;
  }
  else {
    _Dst_00 = param_1;
    if (0xf < uVar2) {
      _Dst_00 = (longlong *)*param_1;
    }
    param_1[2] = param_3;
    memmove(_Dst_00,param_2,param_3);
    *(undefined1 *)((longlong)_Dst_00 + param_3) = 0;
  }
  return param_1;
}

/* ---- FUNC 0000AD7B FUN_18000ad7b (212 bytes) ---- */

void FUN_18000ad7b(ulonglong param_1)

{
  ulonglong uVar1;
  void *pvVar2;
  void *_Dst;
  void *pvVar3;
  longlong *unaff_RBX;
  ulonglong unaff_RBP;
  size_t unaff_RSI;
  ulonglong unaff_RDI;
  void *unaff_R15;
  
  param_1 = param_1 | 0xf;
  if (unaff_RDI < param_1) {
    _Dst = (void *)FUN_180007f10(0x8000000000000000);
  }
  else if (unaff_RDI - (unaff_RBP >> 1) < unaff_RBP) {
    _Dst = (void *)FUN_180007f10(0x8000000000000000);
  }
  else {
    uVar1 = (unaff_RBP >> 1) + unaff_RBP;
    unaff_RDI = param_1;
    if (param_1 < uVar1) {
      unaff_RDI = uVar1;
    }
    uVar1 = unaff_RDI + 1;
    if (uVar1 < 0x1000) {
      if (uVar1 == 0) {
        _Dst = (void *)0x0;
      }
      else {
        _Dst = operator_new(uVar1);
      }
    }
    else {
      _Dst = (void *)FUN_180007f10(uVar1);
    }
  }
  unaff_RBX[2] = unaff_RSI;
  unaff_RBX[3] = unaff_RDI;
  memcpy(_Dst,unaff_R15,unaff_RSI);
  *(undefined1 *)((longlong)_Dst + unaff_RSI) = 0;
  if (0xf < unaff_RBP) {
    pvVar2 = (void *)*unaff_RBX;
    pvVar3 = pvVar2;
    if ((0xfff < unaff_RBP + 1) &&
       (pvVar3 = *(void **)((longlong)pvVar2 + -8),
       0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)pvVar3)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar3);
  }
  *unaff_RBX = (longlong)_Dst;
  return;
}

/* ---- FUNC 0000AE4F FUN_18000ae4f (22 bytes) ---- */

void FUN_18000ae4f(void)

{
  return;
}

/* ---- FUNC 0000AE65 _invalid_parameter_noinfo_noreturn (6 bytes) ---- */

void __cdecl _invalid_parameter_noinfo_noreturn(void)

{
                    /* WARNING: Subroutine does not return */
  _invalid_parameter_noinfo_noreturn();
}

/* ---- FUNC 0000AE6C thunk_FUN_18000ace0 (5 bytes) ---- */

void thunk_FUN_18000ace0(void)

{
                    /* WARNING: Subroutine does not return */
  FUN_18000ace0();
}

/* ---- FUNC 0000AE80 at (16 bytes) ---- */

/* public: int & __ptr64 __cdecl std::map<class CAPString,int,struct std::less<class
   CAPString>,class std::allocator<struct std::pair<class CAPString const ,int> > >::at(class
   CAPString const & __ptr64) __ptr64 */

int * __thiscall
std::map<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>_>::at
          (map<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>_>
           *this,CAPString *param_1)

{
  int iVar1;
  code *pcVar2;
  uint uVar3;
  int *piVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  
                    /* 0xae80  208
                       ?at@?$map@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@@std@@QEAAAEAHAEBVCAPString@@@Z
                       0xae80  209
                       ?at@?$map@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@@std@@QEBAAEBHAEBVCAPString@@@Z
                        */
  puVar7 = *(undefined8 **)this;
  if (*(char *)((longlong)puVar7[1] + 0x19) == '\0') {
    iVar1 = *(int *)(*(longlong *)param_1 + 4);
    puVar5 = (undefined8 *)puVar7[1];
    do {
      uVar3 = FUN_180007ea0((undefined8 *)
                            ((longlong)puVar5 + (longlong)*(int *)(puVar5[4] + 4) + 0x20),
                            (undefined8 *)(param_1 + iVar1));
      if ((char)uVar3 == '\0') {
        puVar6 = (undefined8 *)*puVar5;
        puVar7 = puVar5;
      }
      else {
        puVar6 = (undefined8 *)puVar5[2];
      }
      puVar5 = puVar6;
    } while (*(char *)((longlong)puVar6 + 0x19) == '\0');
  }
  if ((*(char *)((longlong)puVar7 + 0x19) == '\0') &&
     (uVar3 = FUN_180007ea0((undefined8 *)(param_1 + *(int *)(*(longlong *)param_1 + 4)),
                            (undefined8 *)
                            ((longlong)puVar7 + (longlong)*(int *)(puVar7[4] + 4) + 0x20)),
     (char)uVar3 == '\0')) {
    return (int *)(puVar7 + 9);
  }
  std::_Xout_of_range("invalid map<K, T> key");
  pcVar2 = (code *)swi(3);
  piVar4 = (int *)(*pcVar2)();
  return piVar4;
}

/* ---- FUNC 0000AE90 FUN_18000ae90 (18 bytes) ---- */

undefined8 * FUN_18000ae90(undefined8 param_1,longlong *param_2)

{
  int iVar1;
  code *pcVar2;
  uint uVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  longlong *unaff_RSI;
  undefined8 *unaff_RDI;
  
  if (*(char *)((longlong)unaff_RDI[1] + 0x19) == '\0') {
    iVar1 = *(int *)(*param_2 + 4);
    puVar4 = (undefined8 *)unaff_RDI[1];
    do {
      uVar3 = FUN_180007ea0((undefined8 *)
                            ((longlong)puVar4 + (longlong)*(int *)(puVar4[4] + 4) + 0x20),
                            (undefined8 *)((longlong)iVar1 + (longlong)param_2));
      if ((char)uVar3 == '\0') {
        puVar5 = (undefined8 *)*puVar4;
        unaff_RDI = puVar4;
      }
      else {
        puVar5 = (undefined8 *)puVar4[2];
      }
      puVar4 = puVar5;
    } while (*(char *)((longlong)puVar5 + 0x19) == '\0');
  }
  if ((*(char *)((longlong)unaff_RDI + 0x19) == '\0') &&
     (uVar3 = FUN_180007ea0((undefined8 *)((longlong)*(int *)(*unaff_RSI + 4) + (longlong)unaff_RSI)
                            ,(undefined8 *)
                             ((longlong)unaff_RDI + (longlong)*(int *)(unaff_RDI[4] + 4) + 0x20)),
     (char)uVar3 == '\0')) {
    return unaff_RDI + 9;
  }
  std::_Xout_of_range("invalid map<K, T> key");
  pcVar2 = (code *)swi(3);
  puVar4 = (undefined8 *)(*pcVar2)();
  return puVar4;
}

/* ---- FUNC 0000AEA2 FUN_18000aea2 (64 bytes) ---- */

undefined8 * FUN_18000aea2(undefined8 param_1,longlong param_2)

{
  int iVar1;
  code *pcVar2;
  uint uVar3;
  longlong in_RAX;
  undefined8 *puVar4;
  undefined8 *unaff_RBX;
  longlong *unaff_RSI;
  undefined8 *unaff_RDI;
  
  iVar1 = *(int *)(in_RAX + 4);
  do {
    uVar3 = FUN_180007ea0((undefined8 *)
                          ((longlong)unaff_RBX + (longlong)*(int *)(unaff_RBX[4] + 4) + 0x20),
                          (undefined8 *)(iVar1 + param_2));
    if ((char)uVar3 == '\0') {
      puVar4 = (undefined8 *)*unaff_RBX;
      unaff_RDI = unaff_RBX;
    }
    else {
      puVar4 = (undefined8 *)unaff_RBX[2];
    }
    unaff_RBX = puVar4;
  } while (*(char *)((longlong)puVar4 + 0x19) == '\0');
  if (*(char *)((longlong)unaff_RDI + 0x19) == '\0') {
    uVar3 = FUN_180007ea0((undefined8 *)((longlong)*(int *)(*unaff_RSI + 4) + (longlong)unaff_RSI),
                          (undefined8 *)
                          ((longlong)unaff_RDI + (longlong)*(int *)(unaff_RDI[4] + 4) + 0x20));
    if ((char)uVar3 == '\0') {
      return unaff_RDI + 9;
    }
  }
  std::_Xout_of_range("invalid map<K, T> key");
  pcVar2 = (code *)swi(3);
  puVar4 = (undefined8 *)(*pcVar2)();
  return puVar4;
}

/* ---- FUNC 0000AEE2 FUN_18000aee2 (11 bytes) ---- */

longlong FUN_18000aee2(void)

{
  code *pcVar1;
  uint uVar2;
  longlong lVar3;
  longlong *unaff_RSI;
  longlong unaff_RDI;
  
  if (*(char *)(unaff_RDI + 0x19) == '\0') {
    uVar2 = FUN_180007ea0((undefined8 *)((longlong)*(int *)(*unaff_RSI + 4) + (longlong)unaff_RSI),
                          (undefined8 *)
                          ((longlong)*(int *)(*(longlong *)(unaff_RDI + 0x20) + 4) +
                          unaff_RDI + 0x20));
    if ((char)uVar2 == '\0') {
      return unaff_RDI + 0x48;
    }
  }
  std::_Xout_of_range("invalid map<K, T> key");
  pcVar1 = (code *)swi(3);
  lVar3 = (*pcVar1)();
  return lVar3;
}

/* ---- FUNC 0000AEED FUN_18000aeed (62 bytes) ---- */

longlong FUN_18000aeed(void)

{
  code *pcVar1;
  uint uVar2;
  longlong lVar3;
  longlong *unaff_RSI;
  longlong unaff_RDI;
  
  uVar2 = FUN_180007ea0((undefined8 *)((longlong)*(int *)(*unaff_RSI + 4) + (longlong)unaff_RSI),
                        (undefined8 *)
                        ((longlong)*(int *)(*(longlong *)(unaff_RDI + 0x20) + 4) + unaff_RDI + 0x20)
                       );
  if ((char)uVar2 == '\0') {
    return unaff_RDI + 0x48;
  }
  std::_Xout_of_range("invalid map<K, T> key");
  pcVar1 = (code *)swi(3);
  lVar3 = (*pcVar1)();
  return lVar3;
}

/* ---- FUNC 0000AF30 clear (58 bytes) ---- */

/* public: void __cdecl std::_Tree<class std::_Tmap_traits<class CAPString,int,struct
   std::less<class CAPString>,class std::allocator<struct std::pair<class CAPString const ,int> >,0>
   >::clear(void) __ptr64 */

void __thiscall
std::
_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
::clear(_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
        *this)

{
  longlong lVar1;
  
                    /* 0xaf30  214
                       ?clear@?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@QEAAXXZ
                        */
  lVar1 = *(longlong *)this;
  FUN_180008800(this,this,*(longlong **)(lVar1 + 8));
  *(longlong *)(lVar1 + 8) = lVar1;
  *(longlong *)lVar1 = lVar1;
  *(longlong *)(lVar1 + 0x10) = lVar1;
  *(undefined8 *)(this + 8) = 0;
  return;
}

/* ---- FUNC 0000AF70 count (16 bytes) ---- */

/* public: unsigned __int64 __cdecl std::_Tree<class std::_Tmap_traits<class CAPString,int,struct
   std::less<class CAPString>,class std::allocator<struct std::pair<class CAPString const ,int> >,0>
   >::count(class CAPString const & __ptr64)const __ptr64 */

__uint64 __thiscall
std::
_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
::count(_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
        *this,CAPString *param_1)

{
  int iVar1;
  uint uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  
                    /* 0xaf70  215
                       ?count@?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@QEBA_KAEBVCAPString@@@Z
                        */
  puVar5 = *(undefined8 **)this;
  if (*(char *)((longlong)puVar5[1] + 0x19) == '\0') {
    iVar1 = *(int *)(*(longlong *)param_1 + 4);
    puVar3 = (undefined8 *)puVar5[1];
    do {
      uVar2 = FUN_180007ea0((undefined8 *)
                            ((longlong)puVar3 + (longlong)*(int *)(puVar3[4] + 4) + 0x20),
                            (undefined8 *)(param_1 + iVar1));
      if ((char)uVar2 == '\0') {
        puVar4 = (undefined8 *)*puVar3;
        puVar5 = puVar3;
      }
      else {
        puVar4 = (undefined8 *)puVar3[2];
      }
      puVar3 = puVar4;
    } while (*(char *)((longlong)puVar4 + 0x19) == '\0');
  }
  if ((*(char *)((longlong)puVar5 + 0x19) == '\0') &&
     (uVar2 = FUN_180007ea0((undefined8 *)(param_1 + *(int *)(*(longlong *)param_1 + 4)),
                            (undefined8 *)
                            ((longlong)puVar5 + (longlong)*(int *)(puVar5[4] + 4) + 0x20)),
     (char)uVar2 == '\0')) {
    return 1;
  }
  return 0;
}

/* ---- FUNC 0000AF80 FUN_18000af80 (18 bytes) ---- */

undefined8 FUN_18000af80(undefined8 param_1,longlong *param_2)

{
  int iVar1;
  uint uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  longlong *unaff_RSI;
  undefined8 *unaff_RDI;
  
  if (*(char *)((longlong)unaff_RDI[1] + 0x19) == '\0') {
    iVar1 = *(int *)(*param_2 + 4);
    puVar3 = (undefined8 *)unaff_RDI[1];
    do {
      uVar2 = FUN_180007ea0((undefined8 *)
                            ((longlong)puVar3 + (longlong)*(int *)(puVar3[4] + 4) + 0x20),
                            (undefined8 *)((longlong)iVar1 + (longlong)param_2));
      if ((char)uVar2 == '\0') {
        puVar4 = (undefined8 *)*puVar3;
        unaff_RDI = puVar3;
      }
      else {
        puVar4 = (undefined8 *)puVar3[2];
      }
      puVar3 = puVar4;
    } while (*(char *)((longlong)puVar4 + 0x19) == '\0');
  }
  if ((*(char *)((longlong)unaff_RDI + 0x19) == '\0') &&
     (uVar2 = FUN_180007ea0((undefined8 *)((longlong)*(int *)(*unaff_RSI + 4) + (longlong)unaff_RSI)
                            ,(undefined8 *)
                             ((longlong)unaff_RDI + (longlong)*(int *)(unaff_RDI[4] + 4) + 0x20)),
     (char)uVar2 == '\0')) {
    return 1;
  }
  return 0;
}

/* ---- FUNC 0000AF92 FUN_18000af92 (64 bytes) ---- */

undefined8 FUN_18000af92(undefined8 param_1,longlong param_2)

{
  int iVar1;
  uint uVar2;
  longlong in_RAX;
  undefined8 *unaff_RBX;
  undefined8 *puVar3;
  longlong *unaff_RSI;
  undefined8 *unaff_RDI;
  
  iVar1 = *(int *)(in_RAX + 4);
  do {
    uVar2 = FUN_180007ea0((undefined8 *)
                          ((longlong)unaff_RBX + (longlong)*(int *)(unaff_RBX[4] + 4) + 0x20),
                          (undefined8 *)(iVar1 + param_2));
    if ((char)uVar2 == '\0') {
      puVar3 = (undefined8 *)*unaff_RBX;
      unaff_RDI = unaff_RBX;
    }
    else {
      puVar3 = (undefined8 *)unaff_RBX[2];
    }
    unaff_RBX = puVar3;
  } while (*(char *)((longlong)puVar3 + 0x19) == '\0');
  if (*(char *)((longlong)unaff_RDI + 0x19) == '\0') {
    uVar2 = FUN_180007ea0((undefined8 *)((longlong)*(int *)(*unaff_RSI + 4) + (longlong)unaff_RSI),
                          (undefined8 *)
                          ((longlong)unaff_RDI + (longlong)*(int *)(unaff_RDI[4] + 4) + 0x20));
    if ((char)uVar2 == '\0') {
      return 1;
    }
  }
  return 0;
}

/* ---- FUNC 0000AFD2 FUN_18000afd2 (11 bytes) ---- */

undefined8 FUN_18000afd2(void)

{
  uint uVar1;
  longlong *unaff_RSI;
  longlong unaff_RDI;
  
  if (*(char *)(unaff_RDI + 0x19) == '\0') {
    uVar1 = FUN_180007ea0((undefined8 *)((longlong)*(int *)(*unaff_RSI + 4) + (longlong)unaff_RSI),
                          (undefined8 *)
                          ((longlong)*(int *)(*(longlong *)(unaff_RDI + 0x20) + 4) +
                          unaff_RDI + 0x20));
    if ((char)uVar1 == '\0') {
      return 1;
    }
  }
  return 0;
}

/* ---- FUNC 0000AFDD FUN_18000afdd (63 bytes) ---- */

undefined8 FUN_18000afdd(void)

{
  uint uVar1;
  longlong *unaff_RSI;
  longlong unaff_RDI;
  
  uVar1 = FUN_180007ea0((undefined8 *)((longlong)*(int *)(*unaff_RSI + 4) + (longlong)unaff_RSI),
                        (undefined8 *)
                        ((longlong)*(int *)(*(longlong *)(unaff_RDI + 0x20) + 4) + unaff_RDI + 0x20)
                       );
  if ((char)uVar1 == '\0') {
    return 1;
  }
  return 0;
}

/* ---- FUNC 0000B020 FUN_18000b020 (65 bytes) ---- */

void FUN_18000b020(undefined8 param_1,void *param_2,longlong param_3)

{
  void *pvVar1;
  
  pvVar1 = param_2;
  if ((0xfff < (ulonglong)(param_3 << 5)) &&
     (pvVar1 = *(void **)((longlong)param_2 + -8),
     0x1f < (ulonglong)((longlong)param_2 + (-8 - (longlong)pvVar1)))) {
                    /* WARNING: Subroutine does not return */
    _invalid_parameter_noinfo_noreturn();
  }
  operator_delete(pvVar1);
  return;
}

/* ---- FUNC 0000B070 empty (9 bytes) ---- */

/* public: bool __cdecl std::_Tree<class std::_Tmap_traits<class CAPString,int,struct
   std::less<class CAPString>,class std::allocator<struct std::pair<class CAPString const ,int> >,0>
   >::empty(void)const __ptr64 */

bool __thiscall
std::
_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
::empty(_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
        *this)

{
                    /* 0xb070  218
                       ?empty@?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@QEBA_NXZ
                        */
  return *(longlong *)(this + 8) == 0;
}

/* ---- FUNC 0000B080 equal_range (45 bytes) ---- */

/* public: struct std::pair<class std::_Tree_iterator<class std::_Tree_val<struct
   std::_Tree_simple_types<struct std::pair<class CAPString const ,int> > > >,class
   std::_Tree_iterator<class std::_Tree_val<struct std::_Tree_simple_types<struct std::pair<class
   CAPString const ,int> > > > > __cdecl std::_Tree<class std::_Tmap_traits<class
   CAPString,int,struct std::less<class CAPString>,class std::allocator<struct std::pair<class
   CAPString const ,int> >,0> >::equal_range(class CAPString const & __ptr64) __ptr64 */

CAPString * __thiscall
std::
_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
::equal_range(_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
              *this,CAPString *param_1)

{
  longlong *in_R8;
  longlong local_18;
  undefined8 local_10;
  
                    /* 0xb080  221
                       ?equal_range@?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVCAPString@@H@std@@@std@@@std@@@std@@V12@@2@AEBVCAPString@@@Z
                       0xb080  222
                       ?equal_range@?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@QEBA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVCAPString@@H@std@@@std@@@std@@@std@@V12@@2@AEBVCAPString@@@Z
                        */
  FUN_180008700((longlong *)this,&local_18,in_R8);
  *(longlong *)param_1 = local_18;
  *(undefined8 *)(param_1 + 8) = local_10;
  return param_1;
}

/* ---- FUNC 0000B0B0 erase (35 bytes) ---- */

/* public: class std::_Tree_iterator<class std::_Tree_val<struct std::_Tree_simple_types<struct
   std::pair<class CAPString const ,int> > > > __cdecl std::_Tree<class std::_Tmap_traits<class
   CAPString,int,struct std::less<class CAPString>,class std::allocator<struct std::pair<class
   CAPString const ,int> >,0> >::erase(class std::_Tree_const_iterator<class std::_Tree_val<struct
   std::_Tree_simple_types<struct std::pair<class CAPString const ,int> > > >,class
   std::_Tree_const_iterator<class std::_Tree_val<struct std::_Tree_simple_types<struct
   std::pair<class CAPString const ,int> > > >) __ptr64 */

undefined8 * __thiscall
std::
_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
::erase(_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
        *this,undefined8 *param_2,undefined8 param_3,undefined8 param_4)

{
  _Tree_node<std::pair<CAPString_const_,int>,void*___ptr64> *p_Var1;
  
                    /* 0xb0b0  223
                       ?erase@?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVCAPString@@H@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVCAPString@@H@std@@@std@@@std@@@2@0@Z
                        */
  p_Var1 = _Erase_unchecked(this,param_3,param_4);
  *param_2 = p_Var1;
  return param_2;
}

/* ---- FUNC 0000B0E0 erase (29 bytes) ---- */

/* public: class std::_Tree_iterator<class std::_Tree_val<struct std::_Tree_simple_types<struct
   std::pair<class CAPString const ,int> > > > __cdecl std::_Tree<class std::_Tmap_traits<class
   CAPString,int,struct std::less<class CAPString>,class std::allocator<struct std::pair<class
   CAPString const ,int> >,0> >::erase(class std::_Tree_const_iterator<class std::_Tree_val<struct
   std::_Tree_simple_types<struct std::pair<class CAPString const ,int> > > >) __ptr64 */

undefined8 * __thiscall
std::
_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
::erase(_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
        *this,undefined8 *param_2,undefined8 param_3)

{
  _Tree_node<std::pair<CAPString_const_,int>,void*___ptr64> *p_Var1;
  
                    /* 0xb0e0  224
                       ?erase@?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVCAPString@@H@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVCAPString@@H@std@@@std@@@std@@@2@@Z
                        */
  p_Var1 = _Erase_unchecked(this,param_3);
  *param_2 = p_Var1;
  return param_2;
}

/* ---- FUNC 0000B100 erase (154 bytes) ---- */

/* public: unsigned __int64 __cdecl std::_Tree<class std::_Tmap_traits<class CAPString,int,struct
   std::less<class CAPString>,class std::allocator<struct std::pair<class CAPString const ,int> >,0>
   >::erase(class CAPString const & __ptr64) __ptr64 */

__uint64 __thiscall
std::
_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
::erase(_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
        *this,CAPString *param_1)

{
  char cVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong *plVar5;
  __uint64 _Var6;
  longlong local_18 [2];
  
                    /* 0xb100  225
                       ?erase@?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@QEAA_KAEBVCAPString@@@Z
                        */
  plVar5 = FUN_180008700((longlong *)this,local_18,(longlong *)param_1);
  _Var6 = 0;
  plVar2 = (longlong *)*plVar5;
  while (plVar2 != (longlong *)plVar5[1]) {
    plVar3 = (longlong *)plVar2[2];
    _Var6 = _Var6 + 1;
    if (*(char *)((longlong)plVar3 + 0x19) == '\0') {
      cVar1 = *(char *)(*plVar3 + 0x19);
      plVar2 = plVar3;
      plVar3 = (longlong *)*plVar3;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*plVar3 + 0x19);
        plVar2 = plVar3;
        plVar3 = (longlong *)*plVar3;
      }
    }
    else {
      cVar1 = *(char *)(plVar2[1] + 0x19);
      plVar4 = (longlong *)plVar2[1];
      plVar3 = plVar2;
      while ((plVar2 = plVar4, cVar1 == '\0' && (plVar3 == (longlong *)plVar2[2]))) {
        cVar1 = *(char *)(plVar2[1] + 0x19);
        plVar4 = (longlong *)plVar2[1];
        plVar3 = plVar2;
      }
    }
  }
  _Erase_unchecked(this);
  return _Var6;
}

/* ---- FUNC 0000B1A0 find (29 bytes) ---- */

/* public: class std::_Tree_iterator<class std::_Tree_val<struct std::_Tree_simple_types<struct
   std::pair<class CAPString const ,int> > > > __cdecl std::_Tree<class std::_Tmap_traits<class
   CAPString,int,struct std::less<class CAPString>,class std::allocator<struct std::pair<class
   CAPString const ,int> >,0> >::find(class CAPString const & __ptr64) __ptr64 */

CAPString * __thiscall
std::
_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
::find(_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
       *this,CAPString *param_1)

{
  undefined8 *puVar1;
  longlong *in_R8;
  
                    /* 0xb1a0  226
                       ?find@?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVCAPString@@H@std@@@std@@@std@@@2@AEBVCAPString@@@Z
                       0xb1a0  227
                       ?find@?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@QEBA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVCAPString@@H@std@@@std@@@std@@@2@AEBVCAPString@@@Z
                        */
  puVar1 = FUN_180008880((longlong *)this,in_R8);
  *(undefined8 **)param_1 = puVar1;
  return param_1;
}

/* ---- FUNC 0000B1C0 get_allocator (4 bytes) ---- */

/* public: class std::allocator<struct std::pair<class CAPString const ,int> > __cdecl
   std::_Tree<class std::_Tmap_traits<class CAPString,int,struct std::less<class CAPString>,class
   std::allocator<struct std::pair<class CAPString const ,int> >,0> >::get_allocator(void)const
   __ptr64 */

void __thiscall
std::
_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
::get_allocator(_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
                *this)

{
                    /* 0xb1c0  232
                       ?get_allocator@?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@QEBA?AV?$allocator@U?$pair@$$CBVCAPString@@H@std@@@2@XZ
                       0xb1c0  236
                       ?key_comp@?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@QEBA?AU?$less@VCAPString@@@2@XZ
                       0xb1c0  259
                       ?value_comp@?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@QEBA?AVvalue_compare@?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@2@XZ
                        */
  return;
}

/* ---- FUNC 0000B1D0 insert (332 bytes) ---- */

/* public: class std::_Tree_iterator<class std::_Tree_val<struct std::_Tree_simple_types<struct
   std::pair<class CAPString const ,int> > > > __cdecl std::_Tree<class std::_Tmap_traits<class
   CAPString,int,struct std::less<class CAPString>,class std::allocator<struct std::pair<class
   CAPString const ,int> >,0> >::insert(class std::_Tree_const_iterator<class std::_Tree_val<struct
   std::_Tree_simple_types<struct std::pair<class CAPString const ,int> > > >,struct std::pair<class
   CAPString const ,int> && __ptr64) __ptr64 */

longlong * __thiscall
std::
_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
::insert(_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
         *this,longlong *param_2,longlong *param_3,longlong *param_4)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong *plVar5;
  char local_50;
  longlong *local_48;
  longlong lStack_40;
  longlong local_38 [4];
  
                    /* 0xb1d0  233
                       ?insert@?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVCAPString@@H@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVCAPString@@H@std@@@std@@@std@@@2@$$QEAU?$pair@$$CBVCAPString@@H@2@@Z
                        */
  plVar2 = FUN_180008940((longlong *)this,local_38,param_3,param_4);
  local_48 = (longlong *)*plVar2;
  lStack_40 = plVar2[1];
  local_50 = (char)plVar2[2];
  if (local_50 == '\0') {
    if (*(longlong *)(this + 8) == 0x333333333333333) {
                    /* WARNING: Subroutine does not return */
      FUN_18000ac90();
    }
    lVar1 = *(longlong *)this;
    plVar3 = operator_new(0x50);
    plVar2 = plVar3 + 4;
    *plVar2 = (longlong)&DAT_1800537c8;
    plVar3[5] = 0;
    plVar3[6] = 0;
    plVar3[7] = 0;
    plVar3[8] = 0xf;
    *(undefined1 *)(plVar3 + 5) = 0;
    plVar5 = (longlong *)((longlong)*(int *)(*param_4 + 4) + (longlong)param_4);
    plVar2 = (longlong *)((longlong)*(int *)(*plVar2 + 4) + (longlong)plVar2);
    if (plVar2 != plVar5) {
      plVar4 = plVar5;
      if (0xf < (ulonglong)plVar5[3]) {
        plVar4 = (longlong *)*plVar5;
      }
      FUN_18000ad20(plVar2,plVar4,plVar5[2]);
    }
    *(int *)(plVar3 + 9) = (int)param_4[5];
    *plVar3 = lVar1;
    plVar3[1] = lVar1;
    plVar3[2] = lVar1;
    *(undefined2 *)(plVar3 + 3) = 0;
    local_48 = FUN_18000a930((longlong *)this,(longlong *)&local_48,plVar3);
  }
  *param_2 = (longlong)local_48;
  return param_2;
}

/* ---- FUNC 0000B320 insert (35 bytes) ---- */

/* public: class std::_Tree_iterator<class std::_Tree_val<struct std::_Tree_simple_types<struct
   std::pair<class CAPString const ,int> > > > __cdecl std::_Tree<class std::_Tmap_traits<class
   CAPString,int,struct std::less<class CAPString>,class std::allocator<struct std::pair<class
   CAPString const ,int> >,0> >::insert(class std::_Tree_const_iterator<class std::_Tree_val<struct
   std::_Tree_simple_types<struct std::pair<class CAPString const ,int> > > >,struct std::pair<class
   CAPString const ,int> const & __ptr64) __ptr64 */

undefined8 * __thiscall
std::
_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
::insert(_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
         *this,undefined8 *param_2,longlong *param_3,longlong *param_4)

{
  longlong *plVar1;
  
                    /* 0xb320  234
                       ?insert@?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVCAPString@@H@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVCAPString@@H@std@@@std@@@std@@@2@AEBU?$pair@$$CBVCAPString@@H@2@@Z
                        */
  plVar1 = FUN_180008430((longlong *)this,param_3,param_4);
  *param_2 = plVar1;
  return param_2;
}

/* ---- FUNC 0000B350 insert (258 bytes) ---- */

/* public: void __cdecl std::_Tree<class std::_Tmap_traits<class CAPString,int,struct
   std::less<class CAPString>,class std::allocator<struct std::pair<class CAPString const ,int> >,0>
   >::insert(class std::initializer_list<struct std::pair<class CAPString const ,int> >) __ptr64 */

void __thiscall
std::
_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
::insert(_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
         *this,undefined8 *param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong *plVar5;
  longlong local_68;
  longlong lStack_60;
  longlong local_48;
  longlong local_40 [3];
  
                    /* 0xb350  235
                       ?insert@?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@QEAAXV?$initializer_list@U?$pair@$$CBVCAPString@@H@std@@@2@@Z
                        */
  plVar1 = (longlong *)param_2[1];
  plVar5 = (longlong *)*param_2;
  plVar2 = *(longlong **)this;
  do {
    if (plVar5 == plVar1) {
      return;
    }
    plVar4 = FUN_180008940((longlong *)this,local_40,plVar2,plVar5);
    local_68 = *plVar4;
    lStack_60 = plVar4[1];
    local_48 = plVar4[2];
    if ((char)local_48 == '\0') {
      if (*(longlong *)(this + 8) == 0x333333333333333) {
                    /* WARNING: Subroutine does not return */
        FUN_18000ac90();
      }
      lVar3 = *(longlong *)this;
      plVar4 = operator_new(0x50);
      FUN_180009090(plVar4 + 4,plVar5);
      *plVar4 = lVar3;
      plVar4[1] = lVar3;
      plVar4[2] = lVar3;
      *(undefined2 *)(plVar4 + 3) = 0;
      FUN_18000a930((longlong *)this,&local_68,plVar4);
    }
    plVar5 = plVar5 + 6;
  } while( true );
}

/* ---- FUNC 0000B460 lower_bound (34 bytes) ---- */

/* public: class std::_Tree_iterator<class std::_Tree_val<struct std::_Tree_simple_types<struct
   std::pair<class CAPString const ,int> > > > __cdecl std::_Tree<class std::_Tmap_traits<class
   CAPString,int,struct std::less<class CAPString>,class std::allocator<struct std::pair<class
   CAPString const ,int> >,0> >::lower_bound(class CAPString const & __ptr64) __ptr64 */

CAPString * __thiscall
std::
_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
::lower_bound(_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
              *this,CAPString *param_1)

{
  int iVar1;
  uint uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  longlong *in_R8;
  
                    /* 0xb460  237
                       ?lower_bound@?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVCAPString@@H@std@@@std@@@std@@@2@AEBVCAPString@@@Z
                       0xb460  238
                       ?lower_bound@?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@QEBA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVCAPString@@H@std@@@std@@@std@@@2@AEBVCAPString@@@Z
                        */
  puVar5 = *(undefined8 **)this;
  if (*(char *)((longlong)puVar5[1] + 0x19) == '\0') {
    iVar1 = *(int *)(*in_R8 + 4);
    puVar3 = (undefined8 *)puVar5[1];
    do {
      uVar2 = FUN_180007ea0((undefined8 *)
                            ((longlong)puVar3 + (longlong)*(int *)(puVar3[4] + 4) + 0x20),
                            (undefined8 *)((longlong)iVar1 + (longlong)in_R8));
      if ((char)uVar2 == '\0') {
        puVar4 = (undefined8 *)*puVar3;
        puVar5 = puVar3;
      }
      else {
        puVar4 = (undefined8 *)puVar3[2];
      }
      puVar3 = puVar4;
    } while (*(char *)((longlong)puVar4 + 0x19) == '\0');
    *(undefined8 **)param_1 = puVar5;
    return param_1;
  }
  *(undefined8 **)param_1 = puVar5;
  return param_1;
}

/* ---- FUNC 0000B482 FUN_18000b482 (86 bytes) ---- */

void FUN_18000b482(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  int iVar1;
  uint uVar2;
  longlong in_RAX;
  undefined8 *unaff_RBX;
  undefined8 *puVar3;
  undefined8 *unaff_RSI;
  undefined8 *unaff_RDI;
  
  iVar1 = *(int *)(in_RAX + 4);
  do {
    uVar2 = FUN_180007ea0((undefined8 *)
                          ((longlong)unaff_RBX + (longlong)*(int *)(unaff_RBX[4] + 4) + 0x20),
                          (undefined8 *)(iVar1 + param_3));
    if ((char)uVar2 == '\0') {
      puVar3 = (undefined8 *)*unaff_RBX;
      unaff_RDI = unaff_RBX;
    }
    else {
      puVar3 = (undefined8 *)unaff_RBX[2];
    }
    unaff_RBX = puVar3;
  } while (*(char *)((longlong)puVar3 + 0x19) == '\0');
  *unaff_RSI = unaff_RDI;
  return;
}

/* ---- FUNC 0000B4D8 FUN_18000b4d8 (22 bytes) ---- */

void FUN_18000b4d8(undefined8 param_1,undefined8 *param_2)

{
  undefined8 unaff_RDI;
  
  *param_2 = unaff_RDI;
  return;
}

/* ---- FUNC 0000B4F0 max_size (11 bytes) ---- */

/* public: unsigned __int64 __cdecl std::_Tree<class std::_Tmap_traits<class CAPString,int,struct
   std::less<class CAPString>,class std::allocator<struct std::pair<class CAPString const ,int> >,0>
   >::max_size(void)const __ptr64 */

__uint64 __thiscall
std::
_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
::max_size(_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
           *this)

{
                    /* 0xb4f0  249
                       ?max_size@?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@QEBA_KXZ
                        */
  return 0x333333333333333;
}

/* ---- FUNC 0000B500 size (5 bytes) ---- */

/* public: unsigned __int64 __cdecl std::_Tree<class std::_Tmap_traits<class CAPString,int,struct
   std::less<class CAPString>,class std::allocator<struct std::pair<class CAPString const ,int> >,0>
   >::size(void)const __ptr64 */

__uint64 __thiscall
std::
_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
::size(_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
       *this)

{
                    /* 0xb500  254
                       ?size@?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@QEBA_KXZ
                        */
  return *(__uint64 *)(this + 8);
}

/* ---- FUNC 0000B510 swap (34 bytes) ---- */

/* public: void __cdecl std::_Tree<class std::_Tmap_traits<class CAPString,int,struct
   std::less<class CAPString>,class std::allocator<struct std::pair<class CAPString const ,int> >,0>
   >::swap(class std::_Tree<class std::_Tmap_traits<class CAPString,int,struct std::less<class
   CAPString>,class std::allocator<struct std::pair<class CAPString const ,int> >,0> > & __ptr64)
   __ptr64 */

void __thiscall
std::
_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
::swap(_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
       *this,_Tree<class_std::_Tmap_traits<class_CAPString,int,struct_std::less<class_CAPString>,class_std::allocator<struct_std::pair<class_CAPString_const_,int>_>,0>_>
             *param_1)

{
  undefined8 uVar1;
  
                    /* 0xb510  255
                       ?swap@?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@QEAAXAEAV12@@Z
                       0xb510  256
                       ?swap@?$map@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@@std@@QEAAXAEAV12@@Z
                        */
  if (this != (_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
               *)param_1) {
    uVar1 = *(undefined8 *)this;
    *(undefined8 *)this = *(undefined8 *)param_1;
    *(undefined8 *)param_1 = uVar1;
    uVar1 = *(undefined8 *)(this + 8);
    *(undefined8 *)(this + 8) = *(undefined8 *)(param_1 + 8);
    *(undefined8 *)(param_1 + 8) = uVar1;
  }
  return;
}

/* ---- FUNC 0000B540 upper_bound (34 bytes) ---- */

/* public: class std::_Tree_iterator<class std::_Tree_val<struct std::_Tree_simple_types<struct
   std::pair<class CAPString const ,int> > > > __cdecl std::_Tree<class std::_Tmap_traits<class
   CAPString,int,struct std::less<class CAPString>,class std::allocator<struct std::pair<class
   CAPString const ,int> >,0> >::upper_bound(class CAPString const & __ptr64) __ptr64 */

CAPString * __thiscall
std::
_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
::upper_bound(_Tree<std::_Tmap_traits<CAPString,int,std::less<CAPString>,std::allocator<std::pair<CAPString_const_,int>_>,0>_>
              *this,CAPString *param_1)

{
  int iVar1;
  uint uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  longlong *in_R8;
  
                    /* 0xb540  257
                       ?upper_bound@?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVCAPString@@H@std@@@std@@@std@@@2@AEBVCAPString@@@Z
                       0xb540  258
                       ?upper_bound@?$_Tree@V?$_Tmap_traits@VCAPString@@HU?$less@VCAPString@@@std@@V?$allocator@U?$pair@$$CBVCAPString@@H@std@@@3@$0A@@std@@@std@@QEBA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVCAPString@@H@std@@@std@@@std@@@2@AEBVCAPString@@@Z
                        */
  puVar5 = *(undefined8 **)this;
  if (*(char *)((longlong)puVar5[1] + 0x19) == '\0') {
    iVar1 = *(int *)(*in_R8 + 4);
    puVar3 = (undefined8 *)puVar5[1];
    do {
      uVar2 = FUN_180007ea0((undefined8 *)((longlong)iVar1 + (longlong)in_R8),
                            (undefined8 *)
                            ((longlong)puVar3 + (longlong)*(int *)(puVar3[4] + 4) + 0x20));
      if ((char)uVar2 == '\0') {
        puVar4 = (undefined8 *)puVar3[2];
      }
      else {
        puVar4 = (undefined8 *)*puVar3;
        puVar5 = puVar3;
      }
      puVar3 = puVar4;
    } while (*(char *)((longlong)puVar4 + 0x19) == '\0');
    *(undefined8 **)param_1 = puVar5;
    return param_1;
  }
  *(undefined8 **)param_1 = puVar5;
  return param_1;
}

/* ---- FUNC 0000B562 FUN_18000b562 (86 bytes) ---- */

void FUN_18000b562(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  int iVar1;
  uint uVar2;
  longlong in_RAX;
  undefined8 *unaff_RBX;
  undefined8 *puVar3;
  undefined8 *unaff_RSI;
  undefined8 *unaff_RDI;
  
  iVar1 = *(int *)(in_RAX + 4);
  do {
    uVar2 = FUN_180007ea0((undefined8 *)(iVar1 + param_3),
                          (undefined8 *)
                          ((longlong)unaff_RBX + (longlong)*(int *)(unaff_RBX[4] + 4) + 0x20));
    if ((char)uVar2 == '\0') {
      puVar3 = (undefined8 *)unaff_RBX[2];
    }
    else {
      puVar3 = (undefined8 *)*unaff_RBX;
      unaff_RDI = unaff_RBX;
    }
    unaff_RBX = puVar3;
  } while (*(char *)((longlong)puVar3 + 0x19) == '\0');
  *unaff_RSI = unaff_RDI;
  return;
}

/* ---- FUNC 0000B5B8 FUN_18000b5b8 (22 bytes) ---- */

void FUN_18000b5b8(undefined8 param_1,undefined8 *param_2)

{
  undefined8 unaff_RDI;
  
  *param_2 = unaff_RDI;
  return;
}

/* ---- FUNC 0000B5D0 FUN_18000b5d0 (19 bytes) ---- */

char * FUN_18000b5d0(longlong param_1)

{
  char *pcVar1;
  
  pcVar1 = "Unknown exception";
  if (*(char **)(param_1 + 8) != (char *)0x0) {
    pcVar1 = *(char **)(param_1 + 8);
  }
  return pcVar1;
}

/* ---- FUNC 0000B5F0 FUN_18000b5f0 (234 bytes) ---- */

void FUN_18000b5f0(undefined8 *param_1,void *param_2,size_t param_3)

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
          _Dst = (void *)FUN_180007f10(uVar1);
        }
      }
      else {
        _Dst = (void *)FUN_180007f10(0x8000000000000000);
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
  FUN_18000ace0();
}

/* ---- FUNC 0000B643 FUN_18000b643 (125 bytes) ---- */

void FUN_18000b643(void)

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
    _Dst = (void *)FUN_180007f10(0x8000000000000000);
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
      _Dst = (void *)FUN_180007f10(uVar1);
    }
  }
  *unaff_RSI = _Dst;
  unaff_RSI[2] = unaff_RBX;
  unaff_RSI[3] = uVar2;
  memcpy(_Dst,unaff_RBP,unaff_RBX);
  *(undefined1 *)((longlong)_Dst + unaff_RBX) = 0;
  return;
}

/* ---- FUNC 0000B6C0 FUN_18000b6c0 (21 bytes) ---- */

void FUN_18000b6c0(void)

{
  return;
}

/* ---- FUNC 0000B6E0 FUN_18000b6e0 (23 bytes) ---- */

void FUN_18000b6e0(void *param_1,longlong param_2,longlong param_3)

{
  memmove((void *)(param_3 - (param_2 - (longlong)param_1)),param_1,param_2 - (longlong)param_1);
  return;
}

/* ---- FUNC 0000B700 FUN_18000b700 (48 bytes) ---- */

longlong FUN_18000b700(void *param_1,longlong param_2,void *param_3)

{
  memmove(param_3,param_1,param_2 - (longlong)param_1);
  return (param_2 - (longlong)param_1) + (longlong)param_3;
}

/* ---- FUNC 0000B730 FUN_18000b730 (18 bytes) ---- */

void FUN_18000b730(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_1,
                  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_2)

{
  for (; param_1 != param_2; param_1 = param_1 + 0x20) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1 + 0x10);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1 + 8);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1);
  }
  return;
}

/* ---- FUNC 0000B742 FUN_18000b742 (67 bytes) ---- */

void FUN_18000b742(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_1)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *unaff_RSI;
  
  do {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1 + 0x10);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1 + 8);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1);
    param_1 = param_1 + 0x20;
  } while (param_1 != unaff_RSI);
  return;
}

/* ---- FUNC 0000B785 FUN_18000b785 (1 bytes) ---- */

void FUN_18000b785(void)

{
  return;
}

/* ---- FUNC 0000B790 FUN_18000b790 (328 bytes) ---- */

undefined4 * FUN_18000b790(longlong *param_1,void *param_2,undefined4 *param_3)

{
  ulonglong uVar1;
  undefined4 *puVar2;
  longlong lVar3;
  longlong lVar4;
  undefined4 *puVar5;
  ulonglong uVar6;
  void *pvVar7;
  void *pvVar8;
  ulonglong uVar9;
  undefined4 *puVar10;
  
  lVar3 = *param_1;
  lVar4 = param_1[1] - lVar3 >> 2;
  uVar9 = 0x3fffffffffffffff;
  if (lVar4 == 0x3fffffffffffffff) {
                    /* WARNING: Subroutine does not return */
    FUN_18000ad00();
  }
  uVar1 = lVar4 + 1;
  uVar6 = param_1[2] - lVar3 >> 2;
  if (0x3fffffffffffffff - (uVar6 >> 1) < uVar6) {
    puVar5 = (undefined4 *)FUN_180007f10(0xfffffffffffffffc);
  }
  else {
    uVar6 = (uVar6 >> 1) + uVar6;
    uVar9 = uVar1;
    if (uVar1 <= uVar6) {
      uVar9 = uVar6;
    }
    if (0x3fffffffffffffff < uVar9) {
                    /* WARNING: Subroutine does not return */
      FUN_18000ac70();
    }
    uVar6 = uVar9 * 4;
    if (uVar6 < 0x1000) {
      if (uVar6 == 0) {
        puVar5 = (undefined4 *)0x0;
      }
      else {
        puVar5 = operator_new(uVar6);
      }
    }
    else {
      puVar5 = (undefined4 *)FUN_180007f10(uVar6);
    }
  }
  puVar2 = puVar5 + ((longlong)param_2 - lVar3 >> 2);
  *puVar2 = *param_3;
  pvVar8 = (void *)param_1[1];
  pvVar7 = (void *)*param_1;
  puVar10 = puVar5;
  if (param_2 != pvVar8) {
    FUN_18000b700((void *)*param_1,(longlong)param_2,puVar5);
    puVar10 = puVar2 + 1;
    pvVar8 = (void *)param_1[1];
    pvVar7 = param_2;
  }
  FUN_18000b700(pvVar7,(longlong)pvVar8,puVar10);
  FID_conflict__Change_array(param_1,(longlong)puVar5,uVar1,uVar9);
  return puVar2;
}

/* ---- FUNC 0000B8E0 FUN_18000b8e0 (428 bytes) ---- */

CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
FUN_18000b8e0(longlong *param_1,
             CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *param_2,
             CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *param_3)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong lVar3;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar4;
  ulonglong uVar5;
  __uint64 _Var6;
  ulonglong uVar7;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this;
  
  lVar2 = *param_1;
  lVar3 = param_1[1] - lVar2 >> 5;
  uVar7 = 0x7ffffffffffffff;
  if (lVar3 == 0x7ffffffffffffff) {
                    /* WARNING: Subroutine does not return */
    FUN_18000ad00();
  }
  uVar1 = lVar3 + 1;
  uVar5 = param_1[2] - lVar2 >> 5;
  if (0x7ffffffffffffff - (uVar5 >> 1) < uVar5) {
    pCVar4 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
             FUN_180007f10(0xffffffffffffffe0);
  }
  else {
    uVar5 = (uVar5 >> 1) + uVar5;
    uVar7 = uVar1;
    if (uVar1 <= uVar5) {
      uVar7 = uVar5;
    }
    if (0x7ffffffffffffff < uVar7) {
                    /* WARNING: Subroutine does not return */
      FUN_18000ac70();
    }
    _Var6 = uVar7 << 5;
    if (_Var6 < 0x1000) {
      if (_Var6 == 0) {
        pCVar4 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
      }
      else {
        pCVar4 = operator_new(_Var6);
      }
    }
    else {
      pCVar4 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)FUN_180007f10(_Var6)
      ;
    }
  }
  this = pCVar4 + ((longlong)param_2 - lVar2 & 0xffffffffffffffe0);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(this,param_3);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(this + 8,param_3 + 8);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(this + 0x10,param_3 + 0x10);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(param_3 + 0x18);
  if (param_2 ==
      (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)param_1[1]) {
    FUN_18000c210((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                  *param_1,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                            *)param_1[1],pCVar4);
  }
  else {
    FUN_18000c210((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                  *param_1,param_2,pCVar4);
    FUN_18000c210(param_2,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                           *)param_1[1],this + 0x20);
  }
  FUN_1800169c0(param_1,(longlong)pCVar4,uVar1,uVar7);
  return this;
}

/* ---- FUNC 0000BA90 FUN_18000ba90 (133 bytes) ---- */

void FUN_18000ba90(int *param_1,int *param_2,int *param_3,longlong *param_4)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = FUN_18000d770(param_4,*param_2,*param_1);
  if ((char)uVar2 != '\0') {
    iVar1 = *param_2;
    *param_2 = *param_1;
    *param_1 = iVar1;
  }
  uVar2 = FUN_18000d770(param_4,*param_3,*param_2);
  if ((char)uVar2 != '\0') {
    iVar1 = *param_3;
    *param_3 = *param_2;
    *param_2 = iVar1;
    uVar2 = FUN_18000d770(param_4,iVar1,*param_1);
    if ((char)uVar2 != '\0') {
      iVar1 = *param_2;
      *param_2 = *param_1;
      *param_1 = iVar1;
    }
  }
  return;
}

/* ---- FUNC 0000BB20 FUN_18000bb20 (21 bytes) ---- */

CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
FUN_18000bb20(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *param_1,
             CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *param_2,
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_3)

{
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar1;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar2;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar3;
  
  if (param_2 != param_1) {
    pCVar2 = param_3;
    pCVar3 = param_2 + 0x10;
    do {
      param_3 = pCVar2 + -0x20;
      pCVar1 = pCVar3 + -0x30;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(param_3,pCVar1);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                (pCVar2 + -0x18,pCVar3 + -0x28);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                (pCVar2 + -0x10,pCVar3 + -0x20);
      *(undefined4 *)(pCVar2 + -8) = *(undefined4 *)(pCVar3 + -0x18);
      pCVar2 = param_3;
      pCVar3 = pCVar3 + -0x20;
    } while (pCVar1 != param_1);
  }
  return param_3;
}

/* ---- FUNC 0000BB35 FUN_18000bb35 (99 bytes) ---- */

CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
FUN_18000bb35(undefined8 param_1,longlong param_2)

{
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar1;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *unaff_RBX;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *unaff_RBP;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar2;
  
  pCVar2 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
           (param_2 + 0x10);
  do {
    this = unaff_RBX + -0x20;
    pCVar1 = pCVar2 + -0x30;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(this,pCVar1);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              (unaff_RBX + -0x18,pCVar2 + -0x28);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              (unaff_RBX + -0x10,pCVar2 + -0x20);
    *(undefined4 *)(unaff_RBX + -8) = *(undefined4 *)(pCVar2 + -0x18);
    unaff_RBX = this;
    pCVar2 = pCVar2 + -0x20;
  } while (pCVar1 != unaff_RBP);
  return this;
}

/* ---- FUNC 0000BB98 FUN_18000bb98 (14 bytes) ---- */

void FUN_18000bb98(void)

{
  return;
}

/* ---- FUNC 0000BBB0 FUN_18000bbb0 (625 bytes) ---- */

void FUN_18000bbb0(undefined8 *param_1,int *param_2,int *param_3,longlong *param_4)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  
  piVar6 = param_3 + -1;
  piVar7 = param_2 + ((longlong)param_3 - (longlong)param_2 >> 3);
  lVar3 = (longlong)piVar6 - (longlong)param_2 >> 2;
  piVar4 = param_2;
  if (0x28 < lVar3) {
    lVar3 = lVar3 + 1 >> 3;
    piVar4 = param_2 + lVar3;
    FUN_18000ba90(param_2,piVar4,param_2 + lVar3 * 2,param_4);
    FUN_18000ba90(piVar7 + -lVar3,piVar7,piVar7 + lVar3,param_4);
    piVar6 = piVar6 + -lVar3;
    FUN_18000ba90(param_3 + -1 + lVar3 * -2,piVar6,param_3 + -1,param_4);
  }
  FUN_18000ba90(piVar4,piVar7,piVar6,param_4);
  piVar6 = piVar7;
  while (piVar4 = piVar6, param_2 < piVar4) {
    uVar2 = FUN_18000d770(param_4,piVar4[-1],*piVar4);
    if (((char)uVar2 != '\0') ||
       (uVar2 = FUN_18000d770(param_4,*piVar4,piVar4[-1]), piVar6 = piVar4 + -1, (char)uVar2 != '\0'
       )) break;
  }
  do {
    piVar7 = piVar7 + 1;
    piVar6 = piVar7;
    piVar5 = piVar4;
    if (param_3 <= piVar7) break;
    uVar2 = FUN_18000d770(param_4,*piVar7,*piVar4);
    if (((char)uVar2 != '\0') ||
       (uVar2 = FUN_18000d770(param_4,*piVar4,*piVar7), (char)uVar2 != '\0')) break;
  } while( true );
joined_r0x00018000bce5:
  piVar8 = piVar5;
  if (param_3 <= piVar7) {
joined_r0x00018000bd31:
    for (; param_2 < piVar5; piVar5 = piVar5 + -1) {
      piVar8 = piVar8 + -1;
      uVar2 = FUN_18000d770(param_4,*piVar8,*piVar4);
      if ((char)uVar2 == '\0') {
        uVar2 = FUN_18000d770(param_4,*piVar4,*piVar8);
        if ((char)uVar2 != '\0') break;
        piVar4 = piVar4 + -1;
        if (piVar4 != piVar8) {
          iVar1 = *piVar4;
          *piVar4 = *piVar8;
          *piVar8 = iVar1;
        }
      }
    }
    if (piVar5 == param_2) {
      if (piVar7 == param_3) {
        *param_1 = piVar4;
        param_1[1] = piVar6;
        return;
      }
      if (piVar6 != piVar7) {
        iVar1 = *piVar4;
        *piVar4 = *piVar6;
        *piVar6 = iVar1;
      }
      iVar1 = *piVar4;
      *piVar4 = *piVar7;
      piVar4 = piVar4 + 1;
      *piVar7 = iVar1;
      piVar7 = piVar7 + 1;
      piVar6 = piVar6 + 1;
    }
    else {
      piVar5 = piVar5 + -1;
      if (piVar7 == param_3) {
        piVar4 = piVar4 + -1;
        if (piVar5 != piVar4) {
          iVar1 = *piVar5;
          *piVar5 = *piVar4;
          *piVar4 = iVar1;
        }
        iVar1 = *piVar4;
        *piVar4 = piVar6[-1];
        piVar6[-1] = iVar1;
        piVar6 = piVar6 + -1;
      }
      else {
        iVar1 = *piVar7;
        *piVar7 = *piVar5;
        piVar7 = piVar7 + 1;
        *piVar5 = iVar1;
      }
    }
    goto joined_r0x00018000bce5;
  }
  uVar2 = FUN_18000d770(param_4,*piVar4,*piVar7);
  if ((char)uVar2 == '\0') {
    uVar2 = FUN_18000d770(param_4,*piVar7,*piVar4);
    if ((char)uVar2 != '\0') goto joined_r0x00018000bd31;
    if (piVar6 != piVar7) {
      iVar1 = *piVar6;
      *piVar6 = *piVar7;
      *piVar7 = iVar1;
    }
    piVar6 = piVar6 + 1;
  }
  piVar7 = piVar7 + 1;
  goto joined_r0x00018000bce5;
}

/* ---- FUNC 0000BE30 FUN_18000be30 (25 bytes) ---- */

void FUN_18000be30(longlong param_1,longlong param_2,ulonglong param_3,int *param_4,
                  longlong *param_5)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar3 = (longlong)(param_3 - 1) >> 1;
  lVar4 = param_2;
  while (lVar4 < lVar3) {
    uVar1 = FUN_18000d770(param_5,*(int *)(param_1 + 8 + lVar4 * 8),
                          *(int *)(param_1 + 4 + lVar4 * 8));
    lVar2 = lVar4 * 2 + 1 + ((ulonglong)(uVar1 & 0xff) ^ 1);
    *(undefined4 *)(param_1 + lVar4 * 4) = *(undefined4 *)(param_1 + lVar2 * 4);
    lVar4 = lVar2;
  }
  if ((lVar4 == lVar3) && ((param_3 & 1) == 0)) {
    *(undefined4 *)(param_1 + lVar4 * 4) = *(undefined4 *)(param_1 + -4 + param_3 * 4);
    lVar4 = param_3 - 1;
  }
  if (param_2 < lVar4) {
    while( true ) {
      lVar3 = lVar4 + -1 >> 1;
      uVar1 = FUN_18000d770(param_5,*(int *)(param_1 + lVar3 * 4),*param_4);
      if ((char)uVar1 == '\0') break;
      *(undefined4 *)(param_1 + lVar4 * 4) = *(undefined4 *)(param_1 + lVar3 * 4);
      lVar4 = lVar3;
      if (lVar3 <= param_2) {
        *(int *)(param_1 + lVar3 * 4) = *param_4;
        return;
      }
    }
  }
  *(int *)(param_1 + lVar4 * 4) = *param_4;
  return;
}

/* ---- FUNC 0000BE49 FUN_18000be49 (106 bytes) ---- */

void FUN_18000be49(undefined8 param_1,longlong param_2,ulonglong param_3,int *param_4)

{
  uint uVar1;
  longlong lVar2;
  longlong *unaff_RBX;
  longlong lVar3;
  longlong lVar4;
  longlong unaff_R14;
  
  lVar3 = (longlong)(param_3 - 1) >> 1;
  lVar4 = param_2;
  while (lVar4 < lVar3) {
    uVar1 = FUN_18000d770(unaff_RBX,*(int *)(unaff_R14 + 8 + lVar4 * 8),
                          *(int *)(unaff_R14 + 4 + lVar4 * 8));
    lVar2 = lVar4 * 2 + 1 + ((ulonglong)(uVar1 & 0xff) ^ 1);
    *(undefined4 *)(unaff_R14 + lVar4 * 4) = *(undefined4 *)(unaff_R14 + lVar2 * 4);
    lVar4 = lVar2;
  }
  if ((lVar4 == lVar3) && ((param_3 & 1) == 0)) {
    *(undefined4 *)(unaff_R14 + lVar4 * 4) = *(undefined4 *)(unaff_R14 + -4 + param_3 * 4);
    lVar4 = param_3 - 1;
  }
  if (param_2 < lVar4) {
    while( true ) {
      lVar3 = lVar4 + -1 >> 1;
      uVar1 = FUN_18000d770(unaff_RBX,*(int *)(unaff_R14 + lVar3 * 4),*param_4);
      if ((char)uVar1 == '\0') break;
      *(undefined4 *)(unaff_R14 + lVar4 * 4) = *(undefined4 *)(unaff_R14 + lVar3 * 4);
      lVar4 = lVar3;
      if (lVar3 <= param_2) {
        *(int *)(unaff_R14 + lVar3 * 4) = *param_4;
        return;
      }
    }
  }
  *(int *)(unaff_R14 + lVar4 * 4) = *param_4;
  return;
}

/* ---- FUNC 0000BEB3 FUN_18000beb3 (29 bytes) ---- */

void FUN_18000beb3(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  longlong *unaff_RBX;
  longlong lVar2;
  longlong unaff_RDI;
  longlong unaff_R12;
  ulonglong unaff_R13;
  longlong unaff_R14;
  int *unaff_R15;
  
  if ((unaff_R13 & 1) == 0) {
    *(undefined4 *)(unaff_R14 + unaff_RDI * 4) = *(undefined4 *)(unaff_R14 + -4 + unaff_R13 * 4);
    unaff_RDI = param_2;
  }
  if (unaff_R12 < unaff_RDI) {
    while( true ) {
      lVar2 = unaff_RDI + -1 >> 1;
      uVar1 = FUN_18000d770(unaff_RBX,*(int *)(unaff_R14 + lVar2 * 4),*unaff_R15);
      if ((char)uVar1 == '\0') break;
      *(undefined4 *)(unaff_R14 + unaff_RDI * 4) = *(undefined4 *)(unaff_R14 + lVar2 * 4);
      unaff_RDI = lVar2;
      if (lVar2 <= unaff_R12) {
        *(int *)(unaff_R14 + lVar2 * 4) = *unaff_R15;
        return;
      }
    }
  }
  *(int *)(unaff_R14 + unaff_RDI * 4) = *unaff_R15;
  return;
}

/* ---- FUNC 0000BED0 FUN_18000bed0 (92 bytes) ---- */

void FUN_18000bed0(void)

{
  uint uVar1;
  longlong *unaff_RBX;
  longlong lVar2;
  longlong unaff_RDI;
  longlong unaff_R12;
  longlong unaff_R14;
  int *unaff_R15;
  
  do {
    lVar2 = unaff_RDI + -1 >> 1;
    uVar1 = FUN_18000d770(unaff_RBX,*(int *)(unaff_R14 + lVar2 * 4),*unaff_R15);
    if ((char)uVar1 == '\0') {
      *(int *)(unaff_R14 + unaff_RDI * 4) = *unaff_R15;
      return;
    }
    *(undefined4 *)(unaff_R14 + unaff_RDI * 4) = *(undefined4 *)(unaff_R14 + lVar2 * 4);
    unaff_RDI = lVar2;
  } while (unaff_R12 < lVar2);
  *(int *)(unaff_R14 + lVar2 * 4) = *unaff_R15;
  return;
}

/* ---- FUNC 0000BF30 FUN_18000bf30 (310 bytes) ---- */

void FUN_18000bf30(int *param_1,int *param_2,longlong param_3,longlong *param_4)

{
  int iVar1;
  longlong lVar2;
  int *piVar3;
  char cVar4;
  uint uVar5;
  ulonglong uVar6;
  longlong lVar7;
  int *piVar8;
  longlong lVar9;
  longlong lVar10;
  int *local_res10;
  int *local_48;
  int *local_40;
  
  uVar6 = (longlong)param_2 - (longlong)param_1;
  local_res10 = param_2;
  while( true ) {
    if ((longlong)(uVar6 & 0xfffffffffffffffc) < 0x81) {
      piVar8 = param_1;
      if (param_1 != param_2) {
        while (piVar3 = piVar8 + 1, piVar3 != param_2) {
          iVar1 = *piVar3;
          uVar5 = FUN_18000d770(param_4,iVar1,*param_1);
          if ((char)uVar5 == '\0') {
            uVar5 = FUN_18000d770(param_4,iVar1,*piVar8);
            cVar4 = (char)uVar5;
            piVar8 = piVar3;
            while (cVar4 != '\0') {
              *piVar8 = piVar8[-1];
              uVar5 = FUN_18000d770(param_4,iVar1,piVar8[-2]);
              piVar8 = piVar8 + -1;
              cVar4 = (char)uVar5;
            }
            *piVar8 = iVar1;
            piVar8 = piVar3;
          }
          else {
            FUN_18000b6e0(param_1,(longlong)piVar3,(longlong)(piVar8 + 2));
            *param_1 = iVar1;
            piVar8 = piVar3;
          }
        }
      }
      return;
    }
    if (param_3 < 1) break;
    FUN_18000bbb0(&local_48,param_1,param_2,param_4);
    piVar3 = local_40;
    piVar8 = local_48;
    param_3 = (param_3 >> 1) + (param_3 >> 2);
    if ((longlong)((longlong)local_48 - (longlong)param_1 & 0xfffffffffffffffcU) <
        (longlong)((longlong)param_2 - (longlong)local_40 & 0xfffffffffffffffcU)) {
      FUN_18000bf30(param_1,local_48,param_3,param_4);
      param_1 = piVar3;
      piVar8 = param_2;
    }
    else {
      FUN_18000bf30(local_40,param_2,param_3,param_4);
      local_res10 = piVar8;
    }
    uVar6 = (longlong)piVar8 - (longlong)param_1;
    param_2 = piVar8;
  }
  uVar6 = (longlong)param_2 - (longlong)param_1 >> 2;
  lVar9 = (longlong)param_2 - (longlong)param_1 >> 3;
  if (0 < lVar9) {
    lVar10 = (longlong)(uVar6 - 1) >> 1;
    do {
      iVar1 = param_1[lVar9 + -1];
      lVar9 = lVar9 + -1;
      lVar2 = lVar9;
      while (lVar2 < lVar10) {
        uVar5 = FUN_18000d770(param_4,param_1[lVar2 * 2 + 2],param_1[lVar2 * 2 + 1]);
        lVar7 = lVar2 * 2 + 1 + ((ulonglong)(uVar5 & 0xff) ^ 1);
        param_1[lVar2] = param_1[lVar7];
        lVar2 = lVar7;
      }
      if ((lVar2 == lVar10) && ((uVar6 & 1) == 0)) {
        param_1[lVar2] = param_1[uVar6 - 1];
        lVar2 = uVar6 - 1;
      }
      while (lVar9 < lVar2) {
        lVar7 = lVar2 + -1 >> 1;
        uVar5 = FUN_18000d770(param_4,param_1[lVar7],iVar1);
        if ((char)uVar5 == '\0') break;
        param_1[lVar2] = param_1[lVar7];
        lVar2 = lVar7;
      }
      param_1[lVar2] = iVar1;
      param_2 = local_res10;
    } while (0 < lVar9);
  }
  if ((longlong)uVar6 < 2) {
    return;
  }
  piVar8 = param_2 + -1;
  do {
    local_res10 = (int *)CONCAT44(local_res10._4_4_,*piVar8);
    *piVar8 = *param_1;
    FUN_18000be30((longlong)param_1,0,(longlong)piVar8 - (longlong)param_1 >> 2,(int *)&local_res10,
                  param_4);
    piVar8 = piVar8 + -1;
  } while (7 < (longlong)((4 - (longlong)param_1) + (longlong)piVar8 & 0xfffffffffffffffcU));
  return;
}

/* ---- FUNC 0000C066 FUN_18000c066 (218 bytes) ---- */

void FUN_18000c066(undefined8 param_1,longlong param_2)

{
  int iVar1;
  uint uVar2;
  ulonglong in_RAX;
  longlong lVar3;
  longlong *unaff_RBX;
  longlong lVar4;
  int *piVar5;
  int *unaff_RDI;
  longlong unaff_R14;
  longlong lVar6;
  longlong in_stack_00000080;
  int iStack0000000000000088;
  undefined4 uStack000000000000008c;
  
  lVar6 = param_2 >> 1;
  do {
    iVar1 = unaff_RDI[unaff_R14 + -1];
    unaff_R14 = unaff_R14 + -1;
    lVar4 = unaff_R14;
    lVar3 = unaff_R14;
    if (unaff_R14 < lVar6) {
      do {
        uVar2 = FUN_18000d770(unaff_RBX,unaff_RDI[lVar4 * 2 + 2],unaff_RDI[lVar4 * 2 + 1]);
        lVar3 = lVar4 * 2 + 1 + ((ulonglong)(uVar2 & 0xff) ^ 1);
        unaff_RDI[lVar4] = unaff_RDI[lVar3];
        lVar4 = lVar3;
      } while (lVar3 < lVar6);
      param_2 = in_RAX - 1;
    }
    if ((lVar3 == lVar6) && ((in_RAX & 1) == 0)) {
      unaff_RDI[lVar3] = unaff_RDI[in_RAX - 1];
      lVar3 = param_2;
    }
    while (unaff_R14 < lVar3) {
      lVar4 = lVar3 + -1 >> 1;
      uVar2 = FUN_18000d770(unaff_RBX,unaff_RDI[lVar4],iVar1);
      if ((char)uVar2 == '\0') break;
      unaff_RDI[lVar3] = unaff_RDI[lVar4];
      lVar3 = lVar4;
    }
    unaff_RDI[lVar3] = iVar1;
    param_2 = in_RAX - 1;
    if (unaff_R14 < 1) {
      if (1 < in_stack_00000080) {
        piVar5 = (int *)(CONCAT44(uStack000000000000008c,iStack0000000000000088) + -4);
        do {
          iStack0000000000000088 = *piVar5;
          *piVar5 = *unaff_RDI;
          FUN_18000be30((longlong)unaff_RDI,0,(longlong)piVar5 - (longlong)unaff_RDI >> 2,
                        &stack0x00000088,unaff_RBX);
          piVar5 = piVar5 + -1;
        } while (7 < (longlong)((4 - (longlong)unaff_RDI) + (longlong)piVar5 & 0xfffffffffffffffcU))
        ;
        return;
      }
      return;
    }
  } while( true );
}

/* ---- FUNC 0000C140 FUN_18000c140 (205 bytes) ---- */

void FUN_18000c140(void)

{
  longlong in_RAX;
  longlong *unaff_RBX;
  int *piVar1;
  int *unaff_RDI;
  longlong unaff_R13;
  int iStack0000000000000088;
  
  if (1 < in_RAX) {
    piVar1 = (int *)(unaff_R13 + -4);
    do {
      iStack0000000000000088 = *piVar1;
      *piVar1 = *unaff_RDI;
      FUN_18000be30((longlong)unaff_RDI,0,(longlong)piVar1 - (longlong)unaff_RDI >> 2,
                    &stack0x00000088,unaff_RBX);
      piVar1 = piVar1 + -1;
    } while (7 < (longlong)((4 - (longlong)unaff_RDI) + (longlong)piVar1 & 0xfffffffffffffffcU));
    return;
  }
  return;
}

/* ---- FUNC 0000C210 FUN_18000c210 (142 bytes) ---- */

CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
FUN_18000c210(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *param_1,
             CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *param_2,
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_3)

{
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar1;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar2;
  
  if (param_1 != param_2) {
    pCVar2 = param_1 + 0x10;
    do {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_3,pCVar2 + -0x10);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_3 + 8,pCVar2 + -8);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_3 + 0x10,pCVar2);
      *(undefined4 *)(param_3 + 0x18) = *(undefined4 *)(pCVar2 + 8);
      param_3 = param_3 + 0x20;
      pCVar1 = pCVar2 + 0x10;
      pCVar2 = pCVar2 + 0x20;
    } while (pCVar1 != param_2);
  }
  return param_3;
}

/* ---- FUNC 0000C2A0 FUN_18000c2a0 (398 bytes) ---- */

undefined8 *
FUN_18000c2a0(longlong *param_1,undefined8 *param_2,
             CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *param_3,
             CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *param_4)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar1;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_50 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_48 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_40 [8];
  undefined4 local_38;
  
  pCVar1 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_1[1];
  if (pCVar1 == (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_1[2]) {
    pCVar1 = FUN_18000b8e0(param_1,param_3,param_4);
    *param_2 = pCVar1;
  }
  else if (param_3 ==
           (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar1) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar1,param_4);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar1 + 8,param_4 + 8);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar1 + 0x10,param_4 + 0x10);
    *(undefined4 *)(pCVar1 + 0x18) = *(undefined4 *)(param_4 + 0x18);
    param_1[1] = param_1[1] + 0x20;
    *param_2 = param_3;
  }
  else {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_50,param_4);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_48,param_4 + 8);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_40,param_4 + 0x10);
    local_38 = *(undefined4 *)(param_4 + 0x18);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              (pCVar1,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                      (pCVar1 + -0x20));
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              (pCVar1 + 8,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               (pCVar1 + -0x18));
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              (pCVar1 + 0x10,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               (pCVar1 + -0x10));
    *(undefined4 *)(pCVar1 + 0x18) = *(undefined4 *)(pCVar1 + -8);
    param_1[1] = param_1[1] + 0x20;
    FUN_18000bb20(param_3,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                           *)(pCVar1 + -0x20),pCVar1);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_3,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)local_50
              );
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_3 + 8),
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)local_48
              );
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_3 + 0x10),
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)local_40
              );
    *(undefined4 *)(param_3 + 0x18) = local_38;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_40);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_48);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_50);
    *param_2 = param_3;
  }
  return param_2;
}

/* ---- FUNC 0000C430 FUN_18000c430 (417 bytes) ---- */

longlong *
FUN_18000c430(longlong *param_1,int *param_2,longlong param_3,int *param_4,longlong *param_5)

{
  int iVar1;
  longlong *plVar2;
  ulonglong uVar3;
  bool bVar4;
  int iVar5;
  ulonglong uVar6;
  longlong lVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  longlong lVar10;
  int *piVar11;
  int *piVar12;
  
  uVar8 = param_3 - (longlong)param_2 >> 2;
joined_r0x00018000c466:
  do {
    uVar3 = uVar8;
    piVar11 = param_2;
    if ((longlong)uVar3 < 1) goto LAB_18000c5b8;
    iVar5 = *param_4;
    uVar8 = uVar3 >> 1;
    piVar12 = param_2 + uVar8;
    iVar1 = *piVar12;
    if (iVar1 != iVar5) {
      plVar2 = (longlong *)param_5[1];
      if (iVar1 == -1) {
        lVar7 = (longlong)iVar5 * 0x20 + *plVar2;
        if (lVar7 == plVar2[1]) goto LAB_18000c4fc;
        lVar10 = *param_5;
LAB_18000c4ae:
        iVar5 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           (lVar10 + 0x10),*(char **)(lVar7 + 0x10));
        bVar4 = SUB41((uint)iVar5 >> 0x1f,0);
      }
      else {
        lVar10 = (longlong)iVar1 * 0x20 + *plVar2;
        if (iVar5 != -1) {
          lVar7 = (longlong)iVar5 * 0x20 + *plVar2;
          if ((lVar10 == plVar2[1]) || (lVar7 == plVar2[1])) goto LAB_18000c4fc;
          goto LAB_18000c4ae;
        }
        if (lVar10 != plVar2[1]) {
          lVar7 = *param_5;
          goto LAB_18000c4ae;
        }
LAB_18000c4fc:
        bVar4 = iVar1 < iVar5;
      }
      if (bVar4 != false) {
        param_2 = piVar12 + 1;
        uVar8 = uVar3 + (-1 - uVar8);
        goto joined_r0x00018000c466;
      }
    }
    iVar5 = *piVar12;
    iVar1 = *param_4;
    if (iVar1 == iVar5) goto FUN_18000c5d1;
    if (iVar1 == -1) {
      lVar7 = (longlong)iVar5 * 0x20 + *(longlong *)param_5[1];
      if (lVar7 == ((longlong *)param_5[1])[1]) goto LAB_18000c59c;
      lVar10 = *param_5;
LAB_18000c54a:
      iVar5 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                         (lVar10 + 0x10),*(char **)(lVar7 + 0x10));
      bVar4 = SUB41((uint)iVar5 >> 0x1f,0);
    }
    else {
      plVar2 = (longlong *)param_5[1];
      lVar10 = (longlong)iVar1 * 0x20 + *plVar2;
      if (iVar5 != -1) {
        lVar7 = (longlong)iVar5 * 0x20 + *plVar2;
        if ((lVar10 == plVar2[1]) || (lVar7 == plVar2[1])) goto LAB_18000c59c;
        goto LAB_18000c54a;
      }
      if (lVar10 != plVar2[1]) {
        lVar7 = *param_5;
        goto LAB_18000c54a;
      }
LAB_18000c59c:
      bVar4 = iVar1 < iVar5;
    }
    if (bVar4 == false) {
FUN_18000c5d1:
      if (uVar8 != 0) {
        do {
          uVar9 = uVar8 >> 1;
          uVar6 = FUN_18000d5c0(param_5,piVar11[uVar9],*param_4);
          if ((char)uVar6 != '\0') {
            piVar11 = piVar11 + uVar9 + 1;
            uVar9 = uVar8 + (-1 - uVar9);
          }
          uVar8 = uVar9;
        } while (0 < (longlong)uVar9);
      }
      lVar10 = (uVar3 * 4 - (longlong)(piVar12 + 1)) + (longlong)param_2;
      param_2 = piVar12 + 1;
      uVar8 = lVar10 >> 2;
      while (uVar3 = uVar8, 0 < (longlong)uVar3) {
        uVar8 = uVar3 >> 1;
        uVar6 = FUN_18000d5c0(param_5,*param_4,param_2[uVar8]);
        if ((char)uVar6 == '\0') {
          param_2 = param_2 + uVar8 + 1;
          uVar8 = uVar3 + (-1 - uVar8);
        }
      }
LAB_18000c5b8:
      *param_1 = (longlong)piVar11;
      param_1[1] = (longlong)param_2;
      return param_1;
    }
  } while( true );
}

/* ---- FUNC 0000C5D1 FUN_18000c5d1 (183 bytes) ---- */

longlong * FUN_18000c5d1(void)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  ulonglong unaff_RBX;
  longlong unaff_RBP;
  ulonglong uVar4;
  longlong lVar5;
  int *in_R11;
  longlong unaff_R12;
  longlong unaff_R13;
  longlong *unaff_R15;
  longlong *in_stack_00000060;
  int *in_stack_00000078;
  
  lVar5 = unaff_R13;
  if (unaff_RBX != 0) {
    do {
      uVar4 = unaff_RBX >> 1;
      uVar2 = FUN_18000d5c0(unaff_R15,*(int *)(lVar5 + uVar4 * 4),*in_R11);
      if ((char)uVar2 != '\0') {
        lVar5 = lVar5 + uVar4 * 4 + 4;
        uVar4 = unaff_RBX + (-1 - uVar4);
      }
      unaff_RBX = uVar4;
      in_R11 = in_stack_00000078;
    } while (0 < (longlong)uVar4);
  }
  lVar1 = unaff_R12 + 4;
  uVar2 = (unaff_RBP * 4 - lVar1) + unaff_R13 >> 2;
  while (uVar4 = uVar2, 0 < (longlong)uVar4) {
    uVar2 = uVar4 >> 1;
    uVar3 = FUN_18000d5c0(unaff_R15,*in_stack_00000078,*(int *)(lVar1 + uVar2 * 4));
    if ((char)uVar3 == '\0') {
      lVar1 = lVar1 + uVar2 * 4 + 4;
      uVar2 = uVar4 + (-1 - uVar2);
    }
  }
  *in_stack_00000060 = lVar5;
  in_stack_00000060[1] = lVar1;
  return in_stack_00000060;
}

/* ---- FUNC 0000C690 FUN_18000c690 (739 bytes) ---- */

longlong *
FUN_18000c690(longlong *param_1,int *param_2,longlong param_3,int *param_4,longlong *param_5)

{
  int iVar1;
  longlong *plVar2;
  ulonglong uVar3;
  bool bVar4;
  int iVar5;
  uint uVar6;
  longlong lVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  longlong lVar10;
  int *piVar11;
  int *piVar12;
  
  uVar9 = param_3 - (longlong)param_2 >> 2;
joined_r0x00018000c6cc:
  do {
    uVar3 = uVar9;
    piVar11 = param_2;
    if ((longlong)uVar3 < 1) goto LAB_18000c8a3;
    iVar5 = *param_4;
    uVar9 = uVar3 >> 1;
    piVar12 = param_2 + uVar9;
    iVar1 = *piVar12;
    if (iVar1 != iVar5) {
      plVar2 = (longlong *)param_5[1];
      if (iVar1 == -1) {
        lVar7 = (longlong)iVar5 * 0x20 + *plVar2;
        if (lVar7 == plVar2[1]) goto LAB_18000c7a4;
        lVar10 = *param_5;
LAB_18000c714:
        iVar5 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           (lVar10 + 0x10),*(char **)(lVar7 + 0x10));
        if (iVar5 == 0) {
          iVar5 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             (lVar10 + 8),*(char **)(lVar7 + 8));
        }
LAB_18000c734:
        bVar4 = SUB41((uint)iVar5 >> 0x1f,0);
      }
      else {
        lVar7 = *plVar2;
        if (iVar5 == -1) {
          lVar7 = (longlong)iVar1 * 0x20 + lVar7;
          if (lVar7 != plVar2[1]) {
            lVar10 = *param_5;
            iVar5 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                               (lVar7 + 0x10),*(char **)(lVar10 + 0x10));
            if (iVar5 != 0) goto LAB_18000c734;
            iVar5 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                               (lVar7 + 8),*(char **)(lVar10 + 8));
            bVar4 = SUB41((uint)iVar5 >> 0x1f,0);
            goto LAB_18000c7aa;
          }
        }
        else {
          lVar10 = (longlong)iVar1 * 0x20 + lVar7;
          lVar7 = (longlong)iVar5 * 0x20 + lVar7;
          if ((lVar10 != plVar2[1]) && (lVar7 != plVar2[1])) goto LAB_18000c714;
        }
LAB_18000c7a4:
        bVar4 = iVar1 < iVar5;
      }
LAB_18000c7aa:
      if (bVar4 != false) {
        param_2 = piVar12 + 1;
        uVar9 = uVar3 + (-1 - uVar9);
        goto joined_r0x00018000c6cc;
      }
    }
    iVar5 = *piVar12;
    iVar1 = *param_4;
    if (iVar1 == iVar5) goto LAB_18000c8c2;
    if (iVar1 == -1) {
      lVar7 = (longlong)iVar5 * 0x20 + *(longlong *)param_5[1];
      if (lVar7 == ((longlong *)param_5[1])[1]) goto LAB_18000c888;
      lVar10 = *param_5;
LAB_18000c7f4:
      iVar5 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                         (lVar10 + 0x10),*(char **)(lVar7 + 0x10));
      if (iVar5 == 0) {
        iVar5 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           (lVar10 + 8),*(char **)(lVar7 + 8));
      }
LAB_18000c814:
      bVar4 = SUB41((uint)iVar5 >> 0x1f,0);
    }
    else {
      plVar2 = (longlong *)param_5[1];
      lVar7 = *plVar2;
      if (iVar5 == -1) {
        lVar7 = (longlong)iVar1 * 0x20 + lVar7;
        if (lVar7 != plVar2[1]) {
          lVar10 = *param_5;
          iVar5 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             (lVar7 + 0x10),*(char **)(lVar10 + 0x10));
          if (iVar5 != 0) goto LAB_18000c814;
          iVar5 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             (lVar7 + 8),*(char **)(lVar10 + 8));
          bVar4 = SUB41((uint)iVar5 >> 0x1f,0);
          goto LAB_18000c88d;
        }
      }
      else {
        lVar10 = (longlong)iVar1 * 0x20 + lVar7;
        lVar7 = (longlong)iVar5 * 0x20 + lVar7;
        if ((lVar10 != plVar2[1]) && (lVar7 != plVar2[1])) goto LAB_18000c7f4;
      }
LAB_18000c888:
      bVar4 = iVar1 < iVar5;
    }
LAB_18000c88d:
    if (bVar4 == false) {
LAB_18000c8c2:
      if (uVar9 != 0) {
        do {
          uVar8 = uVar9 >> 1;
          uVar6 = FUN_18000d670(param_5,piVar11[uVar8],*param_4);
          if ((char)uVar6 != '\0') {
            piVar11 = piVar11 + uVar8 + 1;
            uVar8 = uVar9 + (-1 - uVar8);
          }
          uVar9 = uVar8;
        } while (0 < (longlong)uVar8);
      }
      lVar7 = (uVar3 * 4 - (longlong)(piVar12 + 1)) + (longlong)param_2;
      param_2 = piVar12 + 1;
      uVar9 = lVar7 >> 2;
      while (uVar3 = uVar9, 0 < (longlong)uVar3) {
        uVar9 = uVar3 >> 1;
        uVar6 = FUN_18000d670(param_5,*param_4,param_2[uVar9]);
        if ((char)uVar6 == '\0') {
          param_2 = param_2 + uVar9 + 1;
          uVar9 = uVar3 + (-1 - uVar9);
        }
      }
LAB_18000c8a3:
      param_1[1] = (longlong)param_2;
      *param_1 = (longlong)piVar11;
      return param_1;
    }
  } while( true );
}

/* ---- FUNC 0000C980 FUN_18000c980 (803 bytes) ---- */

longlong *
FUN_18000c980(longlong *param_1,int *param_2,longlong param_3,int *param_4,longlong *param_5)

{
  int iVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  bool bVar5;
  int iVar6;
  uint uVar7;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  longlong lVar11;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar12;
  int *piVar13;
  int *piVar14;
  
  uVar10 = param_3 - (longlong)param_2 >> 2;
joined_r0x00018000c9bc:
  do {
    uVar4 = uVar10;
    piVar13 = param_2;
    if ((longlong)uVar4 < 1) goto LAB_18000cbd3;
    iVar6 = *param_4;
    uVar10 = uVar4 >> 1;
    piVar14 = param_2 + uVar10;
    iVar1 = *piVar14;
    if (iVar1 != iVar6) {
      plVar2 = (longlong *)param_5[1];
      if (iVar1 == -1) {
        pCVar8 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                 ((longlong)iVar6 * 0x20 + *plVar2);
        if (pCVar8 == (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)plVar2[1])
        goto LAB_18000cab4;
        pCVar12 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)*param_5;
LAB_18000ca04:
        iVar6 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                          (pCVar12 + 0x10,*(char **)(pCVar8 + 0x10));
        if ((iVar6 == 0) &&
           (iVar6 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                              (pCVar12 + 8,*(char **)(pCVar8 + 8)), iVar6 == 0)) {
          iVar6 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                            (pCVar12,*(char **)pCVar8);
        }
LAB_18000ca34:
        bVar5 = SUB41((uint)iVar6 >> 0x1f,0);
      }
      else {
        lVar11 = *plVar2;
        if (iVar6 == -1) {
          pCVar12 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                    ((longlong)iVar1 * 0x20 + lVar11);
          if (pCVar12 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)plVar2[1])
          {
            puVar3 = (undefined8 *)*param_5;
            iVar6 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                              (pCVar12 + 0x10,(char *)puVar3[2]);
            if ((iVar6 != 0) ||
               (iVar6 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                                  (pCVar12 + 8,(char *)puVar3[1]), iVar6 != 0)) goto LAB_18000ca34;
            iVar6 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                              (pCVar12,(char *)*puVar3);
            bVar5 = SUB41((uint)iVar6 >> 0x1f,0);
            goto LAB_18000caba;
          }
        }
        else {
          pCVar12 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                    ((longlong)iVar1 * 0x20 + lVar11);
          pCVar8 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                   ((longlong)iVar6 * 0x20 + lVar11);
          if ((pCVar12 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)plVar2[1]
              ) && (pCVar8 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                              plVar2[1])) goto LAB_18000ca04;
        }
LAB_18000cab4:
        bVar5 = iVar1 < iVar6;
      }
LAB_18000caba:
      if (bVar5 != false) {
        param_2 = piVar14 + 1;
        uVar10 = uVar4 + (-1 - uVar10);
        goto joined_r0x00018000c9bc;
      }
    }
    iVar6 = *piVar14;
    iVar1 = *param_4;
    if (iVar1 == iVar6) goto LAB_18000cbf2;
    if (iVar1 == -1) {
      pCVar8 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
               ((longlong)iVar6 * 0x20 + *(longlong *)param_5[1]);
      if (pCVar8 == (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                    ((longlong *)param_5[1])[1]) goto LAB_18000cbb8;
      pCVar12 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)*param_5;
LAB_18000cb04:
      iVar6 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                        (pCVar12 + 0x10,*(char **)(pCVar8 + 0x10));
      if ((iVar6 == 0) &&
         (iVar6 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                            (pCVar12 + 8,*(char **)(pCVar8 + 8)), iVar6 == 0)) {
        iVar6 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                          (pCVar12,*(char **)pCVar8);
      }
LAB_18000cb34:
      bVar5 = SUB41((uint)iVar6 >> 0x1f,0);
    }
    else {
      plVar2 = (longlong *)param_5[1];
      lVar11 = *plVar2;
      if (iVar6 == -1) {
        pCVar12 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                  (lVar11 + (longlong)iVar1 * 0x20);
        if (pCVar12 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)plVar2[1]) {
          puVar3 = (undefined8 *)*param_5;
          iVar6 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                            (pCVar12 + 0x10,(char *)puVar3[2]);
          if ((iVar6 != 0) ||
             (iVar6 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                                (pCVar12 + 8,(char *)puVar3[1]), iVar6 != 0)) goto LAB_18000cb34;
          iVar6 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                            (pCVar12,(char *)*puVar3);
          bVar5 = SUB41((uint)iVar6 >> 0x1f,0);
          goto LAB_18000cbbd;
        }
      }
      else {
        pCVar12 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                  (lVar11 + (longlong)iVar1 * 0x20);
        pCVar8 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                 ((longlong)iVar6 * 0x20 + lVar11);
        if ((pCVar12 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)plVar2[1])
           && (pCVar8 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)plVar2[1])
           ) goto LAB_18000cb04;
      }
LAB_18000cbb8:
      bVar5 = iVar1 < iVar6;
    }
LAB_18000cbbd:
    if (bVar5 == false) {
LAB_18000cbf2:
      if (uVar10 != 0) {
        do {
          uVar9 = uVar10 >> 1;
          uVar7 = FUN_18000d770(param_5,piVar13[uVar9],*param_4);
          if ((char)uVar7 != '\0') {
            piVar13 = piVar13 + uVar9 + 1;
            uVar9 = uVar10 + (-1 - uVar9);
          }
          uVar10 = uVar9;
        } while (0 < (longlong)uVar9);
      }
      lVar11 = (uVar4 * 4 - (longlong)(piVar14 + 1)) + (longlong)param_2;
      param_2 = piVar14 + 1;
      uVar10 = lVar11 >> 2;
      while (uVar4 = uVar10, 0 < (longlong)uVar4) {
        uVar10 = uVar4 >> 1;
        uVar7 = FUN_18000d770(param_5,*param_4,param_2[uVar10]);
        if ((char)uVar7 == '\0') {
          param_2 = param_2 + uVar10 + 1;
          uVar10 = uVar4 + (-1 - uVar10);
        }
      }
LAB_18000cbd3:
      param_1[1] = (longlong)param_2;
      *param_1 = (longlong)piVar13;
      return param_1;
    }
  } while( true );
}

/* ---- FUNC 0000CCB0 CApwnLibraries (204 bytes) ---- */

/* public: __cdecl CApwnLibraries::CApwnLibraries(void) __ptr64 */

CApwnLibraries * __thiscall CApwnLibraries::CApwnLibraries(CApwnLibraries *this)

{
                    /* 0xccb0  21  ??0CApwnLibraries@@QEAA@XZ */
  *(undefined ***)this = vftable;
  CPtrArray::CPtrArray((CPtrArray *)(this + 8));
  *(undefined ***)(this + 8) = CLibraryArray::vftable;
  CPtrArray::CPtrArray((CPtrArray *)(this + 0x30));
  *(undefined ***)(this + 0x30) = CCategoryArray::vftable;
  CPtrArray::CPtrArray((CPtrArray *)(this + 0x58));
  *(undefined ***)(this + 0x58) = CLibraryArray::vftable;
  *(undefined8 *)(this + 0x90) = 0;
  *(undefined8 *)(this + 0x98) = 0;
  *(undefined8 *)(this + 0xa0) = 0;
  *(undefined8 *)(this + 0xa8) = 0;
  *(undefined8 *)(this + 0xb0) = 0;
  *(undefined8 *)(this + 0xb8) = 0;
  *(undefined8 *)(this + 0xc0) = 0;
  *(undefined8 *)(this + 200) = 0;
  *(undefined8 *)(this + 0xd0) = 0;
  *(undefined4 *)(this + 0x80) = 0;
  *(undefined8 *)(this + 0x88) = 0;
  return this;
}

/* ---- FUNC 0000CD80 FUN_18000cd80 (198 bytes) ---- */

undefined8 * FUN_18000cd80(undefined8 *param_1,longlong param_2)

{
  CPtrArray *this;
  void *pvVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  
  *param_1 = CImpEnumACategory::vftable;
  this = (CPtrArray *)(param_1 + 1);
  CPtrArray::CPtrArray(this);
  *(undefined ***)this = CCategoryArray::vftable;
  iVar4 = 0;
  *(undefined4 *)(param_1 + 6) = 0;
  *(undefined4 *)(param_1 + 7) = 0;
  lVar2 = *(longlong *)(param_2 + 0x10);
  if (0 < lVar2) {
    lVar3 = 0;
    do {
      if ((lVar3 < 0) || (lVar2 <= lVar3)) {
LAB_18000ce41:
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      pvVar1 = *(void **)(*(longlong *)(param_2 + 8) + lVar3 * 8);
      if (*(int *)((longlong)pvVar1 + 0x40) != 0) {
        CPtrArray::SetAtGrow(this,param_1[3],pvVar1);
        if (*(longlong *)(param_2 + 0x10) <= lVar3) goto LAB_18000ce41;
        (**(code **)(**(longlong **)(*(longlong *)(param_2 + 8) + lVar3 * 8) + 8))();
      }
      iVar4 = iVar4 + 1;
      lVar3 = lVar3 + 1;
      lVar2 = *(longlong *)(param_2 + 0x10);
    } while (iVar4 < lVar2);
  }
  *(undefined4 *)((longlong)param_1 + 0x34) = *(undefined4 *)(param_1 + 3);
  return param_1;
}

/* ---- FUNC 0000CE50 FUN_18000ce50 (30 bytes) ---- */

undefined8 * FUN_18000ce50(undefined8 *param_1,longlong param_2)

{
  param_1[1] = param_2;
  *param_1 = CImpEnumAModelType::vftable;
  *(undefined8 *)((longlong)param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 2) = *(undefined4 *)(param_2 + 0x10);
  return param_1;
}

/* ---- FUNC 0000CE70 FUN_18000ce70 (70 bytes) ---- */

CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
FUN_18000ce70(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_1,char *param_2,
             undefined4 param_3)

{
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(param_1,param_2);
  *(undefined4 *)(param_1 + 8) = param_3;
  return param_1;
}

/* ---- FUNC 0000CEC0 FUN_18000cec0 (94 bytes) ---- */

undefined8 * FUN_18000cec0(undefined8 *param_1)

{
  *param_1 = CPaletteCategory::vftable;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 2));
  CPtrArray::CPtrArray((CPtrArray *)(param_1 + 3));
  *(undefined ***)(param_1 + 3) = CModelTypeArray::vftable;
  *(undefined4 *)(param_1 + 1) = 1;
  *(undefined4 *)(param_1 + 8) = 1;
  return param_1;
}

/* ---- FUNC 0000CF20 FUN_18000cf20 (127 bytes) ---- */

void FUN_18000cf20(CPtrArray *param_1)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar1;
  longlong lVar2;
  
  *(undefined ***)param_1 = CDeleteArray<CPtrArray,CApwnLibrary*___ptr64>::vftable;
  lVar2 = (longlong)(*(int *)(param_1 + 0x10) + -1);
  if (-1 < *(int *)(param_1 + 0x10) + -1) {
    do {
      if (*(longlong *)(param_1 + 0x10) <= lVar2) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      pCVar1 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
                (*(longlong *)(param_1 + 8) + lVar2 * 8);
      if (pCVar1 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
        FUN_18000d210(pCVar1);
        operator_delete(pCVar1);
      }
      lVar2 = lVar2 + -1;
    } while (-1 < lVar2);
  }
  CPtrArray::SetSize(param_1,0,-1);
  CPtrArray::~CPtrArray(param_1);
  return;
}

/* ---- FUNC 0000CFA0 FUN_18000cfa0 (45 bytes) ---- */

void FUN_18000cfa0(longlong param_1)

{
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0x18));
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0x10));
                    /* WARNING: Could not recover jumptable at 0x00018000cfc6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 8));
  return;
}

/* ---- FUNC 0000CFD0 FUN_18000cfd0 (71 bytes) ---- */

void FUN_18000cfd0(undefined8 *param_1)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar1;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this;
  
  pCVar1 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_1[1];
  for (this = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)*param_1;
      this != pCVar1; this = this + 0x20) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(this + 0x10);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(this + 8);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(this);
  }
  return;
}

/* ---- FUNC 0000D020 FUN_18000d020 (21 bytes) ---- */

void FUN_18000d020(longlong *param_1)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar1;
  void *pvVar2;
  void *pvVar3;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this;
  
  this = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)*param_1;
  if (this != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
    pCVar1 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_1[1];
    for (; this != pCVar1; this = this + 0x20) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(this + 0x10);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(this + 8);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(this);
    }
    pvVar2 = (void *)*param_1;
    pvVar3 = pvVar2;
    if ((0xfff < (param_1[2] - (longlong)pvVar2 & 0xffffffffffffffe0U)) &&
       (pvVar3 = *(void **)((longlong)pvVar2 + -8),
       0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)pvVar3)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar3);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
  }
  return;
}

/* ---- FUNC 0000D035 FUN_18000d035 (80 bytes) ---- */

void FUN_18000d035(longlong param_1)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar1;
  void *pvVar2;
  void *pvVar3;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *unaff_RBX;
  longlong *unaff_RDI;
  
  pCVar1 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)(param_1 + 8);
  for (; unaff_RBX != pCVar1; unaff_RBX = unaff_RBX + 0x20) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(unaff_RBX + 0x10);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(unaff_RBX + 8);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(unaff_RBX);
  }
  pvVar2 = (void *)*unaff_RDI;
  pvVar3 = pvVar2;
  if ((0xfff < (unaff_RDI[2] - (longlong)pvVar2 & 0xffffffffffffffe0U)) &&
     (pvVar3 = *(void **)((longlong)pvVar2 + -8),
     0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)pvVar3)))) {
                    /* WARNING: Subroutine does not return */
    _invalid_parameter_noinfo_noreturn();
  }
  operator_delete(pvVar3);
  *unaff_RDI = 0;
  unaff_RDI[1] = 0;
  unaff_RDI[2] = 0;
  return;
}

/* ---- FUNC 0000D085 FUN_18000d085 (59 bytes) ---- */

void FUN_18000d085(longlong param_1)

{
  undefined8 *unaff_RDI;
  
  if ((param_1 - (longlong)*(void **)(param_1 + -8)) - 8U < 0x20) {
    operator_delete(*(void **)(param_1 + -8));
    *unaff_RDI = 0;
    unaff_RDI[1] = 0;
    unaff_RDI[2] = 0;
    return;
  }
                    /* WARNING: Subroutine does not return */
  _invalid_parameter_noinfo_noreturn();
}

/* ---- FUNC 0000D0D0 FUN_18000d0d0 (106 bytes) ---- */

void FUN_18000d0d0(longlong *param_1)

{
  void *pvVar1;
  void *pvVar2;
  
  if ((longlong *)*param_1 != (longlong *)0x0) {
    FUN_1800081e0((longlong *)*param_1,(longlong *)param_1[1]);
    pvVar1 = (void *)*param_1;
    pvVar2 = pvVar1;
    if ((0xfff < (param_1[2] - (longlong)pvVar1 & 0xffffffffffffffe0U)) &&
       (pvVar2 = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar2)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar2);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
  }
  return;
}

/* ---- FUNC 0000D140 ~CApwnLibraries (199 bytes) ---- */

/* public: __cdecl CApwnLibraries::~CApwnLibraries(void) __ptr64 */

void __thiscall CApwnLibraries::~CApwnLibraries(CApwnLibraries *this)

{
  longlong *plVar1;
  longlong lVar2;
  ulonglong uVar3;
  uint uVar4;
  ulonglong uVar5;
  
                    /* 0xd140  33  ??1CApwnLibraries@@QEAA@XZ */
  *(undefined ***)this = vftable;
  if (*(longlong **)(this + 0x88) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(this + 0x88) + 0x10))();
  }
  uVar3 = 0;
  lVar2 = *(longlong *)(this + 0x40);
  uVar5 = uVar3;
  if (0 < lVar2) {
    do {
      if (((longlong)uVar3 < 0) || (lVar2 <= (longlong)uVar3)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      plVar1 = *(longlong **)(*(longlong *)(this + 0x38) + uVar3 * 8);
      if (plVar1 != (longlong *)0x0) {
        (**(code **)(*plVar1 + 0x10))();
      }
      uVar4 = (int)uVar5 + 1;
      uVar3 = uVar3 + 1;
      lVar2 = *(longlong *)(this + 0x40);
      uVar5 = (ulonglong)uVar4;
    } while ((int)uVar4 < lVar2);
  }
  CStringArray::SetSize(&m_InitializedLibraries,0,-1);
  FUN_18000d0d0((longlong *)(this + 0xc0));
  FUN_18000d490((longlong *)(this + 0x90));
  FUN_18000cf20((CPtrArray *)(this + 0x58));
  CPtrArray::~CPtrArray((CPtrArray *)(this + 0x30));
  FUN_18000cf20((CPtrArray *)(this + 8));
  return;
}

/* ---- FUNC 0000D210 FUN_18000d210 (57 bytes) ---- */

void FUN_18000d210(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_1)

{
  if (*(longlong **)(param_1 + 8) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(param_1 + 8) + 0x28))();
    (**(code **)(**(longlong **)(param_1 + 8) + 0x10))();
    *(undefined8 *)(param_1 + 8) = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x00018000d242. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1);
  return;
}

/* ---- FUNC 0000D250 FUN_18000d250 (70 bytes) ---- */

void FUN_18000d250(CDialog *param_1)

{
  CNameAndStateArray::~CNameAndStateArray((CNameAndStateArray *)(param_1 + 0x470));
  FUN_18000d3f0((CButton *)(param_1 + 0x348));
  FUN_18000d3f0((CButton *)(param_1 + 0x220));
  CListBox::~CListBox((CListBox *)(param_1 + 0x130));
  CDialog::~CDialog(param_1);
  return;
}

/* ---- FUNC 0000D2A0 FUN_18000d2a0 (65 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18000d2a0(CGdiObject *param_1)

{
  undefined1 auStack_258 [576];
  ulonglong local_18;
  
  local_18 = DAT_1800791f8 ^ (ulonglong)auStack_258;
  *(undefined ***)param_1 = CGdiObject::vftable;
  CGdiObject::DeleteObject(param_1);
  return;
}

/* ---- FUNC 0000D2F0 FUN_18000d2f0 (133 bytes) ---- */

void FUN_18000d2f0(undefined8 *param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  uint uVar3;
  ulonglong uVar4;
  
  *param_1 = CImpEnumACategory::vftable;
  uVar2 = 0;
  lVar1 = param_1[3];
  uVar4 = uVar2;
  if (0 < lVar1) {
    do {
      if (((longlong)uVar2 < 0) || (lVar1 <= (longlong)uVar2)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      (**(code **)(**(longlong **)(param_1[2] + uVar2 * 8) + 0x10))();
      uVar3 = (int)uVar4 + 1;
      uVar2 = uVar2 + 1;
      lVar1 = param_1[3];
      uVar4 = (ulonglong)uVar3;
    } while ((int)uVar3 < lVar1);
  }
  CPtrArray::SetSize((CPtrArray *)(param_1 + 1),0,-1);
  CPtrArray::~CPtrArray((CPtrArray *)(param_1 + 1));
  return;
}

/* ---- FUNC 0000D380 FUN_18000d380 (11 bytes) ---- */

void FUN_18000d380(undefined8 *param_1)

{
  *param_1 = CImpEnumAModelType::vftable;
  return;
}

/* ---- FUNC 0000D390 FUN_18000d390 (70 bytes) ---- */

void FUN_18000d390(CDialog *param_1)

{
  CStringArray::~CStringArray((CStringArray *)(param_1 + 0x470));
  FUN_18000d3f0((CButton *)(param_1 + 0x348));
  FUN_18000d3f0((CButton *)(param_1 + 0x220));
  CListBox::~CListBox((CListBox *)(param_1 + 0x130));
  CDialog::~CDialog(param_1);
  return;
}

/* ---- FUNC 0000D3F0 FUN_18000d3f0 (98 bytes) ---- */

void FUN_18000d3f0(CButton *param_1)

{
  *(undefined ***)(param_1 + 0x118) = CBitmap::vftable;
  FUN_18000d2a0((CGdiObject *)(param_1 + 0x118));
  *(undefined ***)(param_1 + 0x108) = CBitmap::vftable;
  FUN_18000d2a0((CGdiObject *)(param_1 + 0x108));
  *(undefined ***)(param_1 + 0xf8) = CBitmap::vftable;
  FUN_18000d2a0((CGdiObject *)(param_1 + 0xf8));
  *(undefined ***)(param_1 + 0xe8) = CBitmap::vftable;
  FUN_18000d2a0((CGdiObject *)(param_1 + 0xe8));
  CButton::~CButton(param_1);
  return;
}

/* ---- FUNC 0000D460 FUN_18000d460 (44 bytes) ---- */

void FUN_18000d460(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_1)

{
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1 + 0x10);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1 + 8);
                    /* WARNING: Could not recover jumptable at 0x00018000d485. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1);
  return;
}

/* ---- FUNC 0000D490 FUN_18000d490 (100 bytes) ---- */

void FUN_18000d490(longlong *param_1)

{
  void *pvVar1;
  void *pvVar2;
  
  pvVar1 = (void *)param_1[3];
  if (pvVar1 != (void *)0x0) {
    pvVar2 = pvVar1;
    if ((0xfff < (param_1[5] - (longlong)pvVar1 & 0xfffffffffffffffcU)) &&
       (pvVar2 = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar2)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar2);
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[5] = 0;
  }
  FUN_18000d020(param_1);
  return;
}

/* ---- FUNC 0000D500 ~CNameAndStateArray (37 bytes) ---- */

/* public: virtual __cdecl CNameAndStateArray::~CNameAndStateArray(void) __ptr64 */

void __thiscall CNameAndStateArray::~CNameAndStateArray(CNameAndStateArray *this)

{
                    /* 0xd500  36  ??1CNameAndStateArray@@UEAA@XZ */
  *(undefined ***)this = vftable;
  RemoveAndDeleteAll(this);
  CPtrArray::~CPtrArray((CPtrArray *)this);
  return;
}

/* ---- FUNC 0000D530 FUN_18000d530 (134 bytes) ---- */

void FUN_18000d530(undefined8 *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  ulonglong uVar3;
  uint uVar4;
  ulonglong uVar5;
  
  *param_1 = CPaletteCategory::vftable;
  uVar3 = 0;
  lVar2 = param_1[5];
  uVar5 = uVar3;
  if (0 < lVar2) {
    do {
      if (((longlong)uVar3 < 0) || (lVar2 <= (longlong)uVar3)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      plVar1 = *(longlong **)(param_1[4] + uVar3 * 8);
      if (plVar1 != (longlong *)0x0) {
        (**(code **)(*plVar1 + 0x10))();
      }
      uVar4 = (int)uVar5 + 1;
      uVar3 = uVar3 + 1;
      lVar2 = param_1[5];
      uVar5 = (ulonglong)uVar4;
    } while ((int)uVar4 < lVar2);
  }
  CPtrArray::~CPtrArray((CPtrArray *)(param_1 + 3));
                    /* WARNING: Could not recover jumptable at 0x00018000d5aa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 2));
  return;
}

/* ---- FUNC 0000D5C0 FUN_18000d5c0 (163 bytes) ---- */

ulonglong FUN_18000d5c0(longlong *param_1,int param_2,int param_3)

{
  longlong lVar1;
  longlong *plVar2;
  uint uVar3;
  ulonglong in_RAX;
  longlong lVar4;
  longlong lVar5;
  
  if (param_2 == param_3) {
    return in_RAX & 0xffffffffffffff00;
  }
  plVar2 = (longlong *)param_1[1];
  if (param_2 == -1) {
    lVar4 = (longlong)param_3 * 0x20 + *plVar2;
    if (lVar4 != plVar2[1]) {
      lVar5 = *param_1;
LAB_18000d5f2:
      uVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                         (lVar5 + 0x10),*(char **)(lVar4 + 0x10));
      return (ulonglong)(uVar3 >> 0x1f);
    }
  }
  else {
    lVar5 = *plVar2;
    lVar4 = (longlong)param_2 * 0x20;
    if (param_3 == -1) {
      lVar5 = lVar5 + lVar4;
      if (lVar5 != plVar2[1]) {
        lVar4 = *param_1;
        goto LAB_18000d5f2;
      }
    }
    else {
      lVar1 = lVar4 + lVar5;
      lVar4 = (longlong)param_3 * 0x20 + lVar5;
      if ((lVar1 != plVar2[1]) && (lVar4 != plVar2[1])) {
        uVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           (lVar1 + 0x10),*(char **)(lVar4 + 0x10));
        return (ulonglong)(uVar3 >> 0x1f);
      }
    }
  }
  return CONCAT71((int7)((ulonglong)lVar4 >> 8),param_2 < param_3);
}

/* ---- FUNC 0000D670 FUN_18000d670 (23 bytes) ---- */

uint FUN_18000d670(longlong *param_1,int param_2,int param_3)

{
  longlong *plVar1;
  uint uVar2;
  longlong in_RAX;
  longlong lVar3;
  longlong lVar4;
  
  if (param_2 == param_3) {
    return (uint)in_RAX & 0xffffff00;
  }
  plVar1 = (longlong *)param_1[1];
  if (param_2 == -1) {
    lVar3 = (longlong)param_3 * 0x20 + *plVar1;
    if (lVar3 == plVar1[1]) goto LAB_18000d74e;
    lVar4 = *param_1;
  }
  else {
    in_RAX = *plVar1;
    if (param_3 == -1) {
      lVar4 = (longlong)param_2 * 0x20 + in_RAX;
      if (lVar4 == plVar1[1]) {
LAB_18000d74e:
        return (uint)CONCAT71((int7)((ulonglong)in_RAX >> 8),param_2 < param_3);
      }
      lVar3 = *param_1;
      uVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                         (lVar4 + 0x10),*(char **)(lVar3 + 0x10));
      if (uVar2 == 0) {
        uVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           (lVar4 + 8),*(char **)(lVar3 + 8));
        return uVar2 >> 0x1f;
      }
      goto LAB_18000d6cd;
    }
    lVar4 = (longlong)param_2 * 0x20 + in_RAX;
    lVar3 = (longlong)param_3 * 0x20 + in_RAX;
    in_RAX = plVar1[1];
    if ((lVar4 == in_RAX) || (lVar3 == in_RAX)) goto LAB_18000d74e;
  }
  uVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(lVar4 + 0x10)
                     ,*(char **)(lVar3 + 0x10));
  if (uVar2 == 0) {
    uVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(lVar4 + 8),
                       *(char **)(lVar3 + 8));
  }
LAB_18000d6cd:
  return uVar2 >> 0x1f;
}

/* ---- FUNC 0000D687 FUN_18000d687 (88 bytes) ---- */

uint FUN_18000d687(longlong *param_1,int param_2,int param_3,longlong *param_4)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  
  if (param_2 == -1) {
    lVar2 = (longlong)param_3 * 0x20 + *param_1;
    if (lVar2 == param_1[1]) goto LAB_18000d74e;
    lVar3 = *param_4;
  }
  else {
    lVar2 = *param_1;
    if (param_3 == -1) {
      lVar2 = (longlong)param_2 * 0x20 + lVar2;
      if (lVar2 == param_1[1]) {
LAB_18000d74e:
        return (uint)(param_2 < param_3);
      }
      lVar3 = *param_4;
      uVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                         (lVar2 + 0x10),*(char **)(lVar3 + 0x10));
      if (uVar1 == 0) {
        uVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           (lVar2 + 8),*(char **)(lVar3 + 8));
        return uVar1 >> 0x1f;
      }
      goto LAB_18000d6cd;
    }
    lVar3 = (longlong)param_2 * 0x20 + lVar2;
    lVar2 = (longlong)param_3 * 0x20 + lVar2;
    if ((lVar3 == param_1[1]) || (lVar2 == param_1[1])) goto LAB_18000d74e;
  }
  uVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(lVar3 + 0x10)
                     ,*(char **)(lVar2 + 0x10));
  if (uVar1 == 0) {
    uVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(lVar3 + 8),
                       *(char **)(lVar2 + 8));
  }
LAB_18000d6cd:
  return uVar1 >> 0x1f;
}

/* ---- FUNC 0000D6DF FUN_18000d6df (79 bytes) ---- */

ulonglong FUN_18000d6df(longlong *param_1,int param_2,int param_3,longlong *param_4)

{
  longlong lVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar3 = *param_1;
  if (param_3 == -1) {
    lVar1 = (longlong)param_2 * 0x20 + lVar3;
    if (lVar1 == param_1[1]) {
LAB_18000d74e:
      return CONCAT71((int7)((ulonglong)lVar3 >> 8),param_2 < param_3);
    }
    lVar3 = *param_4;
    uVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                       (lVar1 + 0x10),*(char **)(lVar3 + 0x10));
    if (uVar2 == 0) {
      uVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                         (lVar1 + 8),*(char **)(lVar3 + 8));
      return (ulonglong)(uVar2 >> 0x1f);
    }
  }
  else {
    lVar1 = (longlong)param_2 * 0x20 + lVar3;
    lVar4 = (longlong)param_3 * 0x20 + lVar3;
    lVar3 = param_1[1];
    if ((lVar1 == lVar3) || (lVar4 == lVar3)) goto LAB_18000d74e;
    uVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                       (lVar1 + 0x10),*(char **)(lVar4 + 0x10));
    if (uVar2 == 0) {
      uVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                         (lVar1 + 8),*(char **)(lVar4 + 8));
    }
  }
  return (ulonglong)(uVar2 >> 0x1f);
}

/* ---- FUNC 0000D72E FUN_18000d72e (53 bytes) ---- */

ulonglong FUN_18000d72e(longlong param_1,int param_2,int param_3)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  longlong in_RAX;
  longlong lVar4;
  longlong in_R10;
  
  lVar1 = in_R10 + in_RAX;
  lVar4 = (longlong)param_3 * 0x20 + in_RAX;
  lVar2 = *(longlong *)(param_1 + 8);
  if ((lVar1 != lVar2) && (lVar4 != lVar2)) {
    uVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                       (lVar1 + 0x10),*(char **)(lVar4 + 0x10));
    if (uVar3 == 0) {
      uVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                         (lVar1 + 8),*(char **)(lVar4 + 8));
    }
    return (ulonglong)(uVar3 >> 0x1f);
  }
  return CONCAT71((int7)((ulonglong)lVar2 >> 8),param_2 < param_3);
}

/* ---- FUNC 0000D770 FUN_18000d770 (23 bytes) ---- */

uint FUN_18000d770(longlong *param_1,int param_2,int param_3)

{
  longlong *plVar1;
  undefined8 *puVar2;
  uint uVar3;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *in_RAX;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar4;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar5;
  
  if (param_2 == param_3) {
    return (uint)in_RAX & 0xffffff00;
  }
  plVar1 = (longlong *)param_1[1];
  if (param_2 == -1) {
    pCVar4 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
             ((longlong)param_3 * 0x20 + *plVar1);
    if (pCVar4 == (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)plVar1[1])
    goto LAB_18000d86e;
    pCVar5 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)*param_1;
  }
  else {
    in_RAX = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)*plVar1;
    if (param_3 == -1) {
      pCVar5 = in_RAX + (longlong)param_2 * 0x20;
      if (pCVar5 == (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)plVar1[1]) {
LAB_18000d86e:
        return (uint)CONCAT71((int7)((ulonglong)in_RAX >> 8),param_2 < param_3);
      }
      puVar2 = (undefined8 *)*param_1;
      uVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                        (pCVar5 + 0x10,(char *)puVar2[2]);
      if (uVar3 == 0) {
        uVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                          (pCVar5 + 8,(char *)puVar2[1]);
        if (uVar3 == 0) {
          uVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                            (pCVar5,(char *)*puVar2);
          return uVar3 >> 0x1f;
        }
      }
      goto LAB_18000d7dd;
    }
    pCVar5 = in_RAX + (longlong)param_2 * 0x20;
    pCVar4 = in_RAX + (longlong)param_3 * 0x20;
    in_RAX = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)plVar1[1];
    if ((pCVar5 == in_RAX) || (pCVar4 == in_RAX)) goto LAB_18000d86e;
  }
  uVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                    (pCVar5 + 0x10,*(char **)(pCVar4 + 0x10));
  if (uVar3 == 0) {
    uVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                      (pCVar5 + 8,*(char **)(pCVar4 + 8));
    if (uVar3 == 0) {
      uVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                        (pCVar5,*(char **)pCVar4);
    }
  }
LAB_18000d7dd:
  return uVar3 >> 0x1f;
}

/* ---- FUNC 0000D787 FUN_18000d787 (104 bytes) ---- */

uint FUN_18000d787(longlong *param_1,int param_2,int param_3,longlong *param_4)

{
  longlong lVar1;
  undefined8 *puVar2;
  uint uVar3;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar4;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar5;
  
  if (param_2 == -1) {
    pCVar4 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
             ((longlong)param_3 * 0x20 + *param_1);
    if (pCVar4 == (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_1[1])
    goto LAB_18000d86e;
    pCVar5 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)*param_4;
  }
  else {
    lVar1 = *param_1;
    if (param_3 == -1) {
      pCVar5 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
               ((longlong)param_2 * 0x20 + lVar1);
      if (pCVar5 == (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_1[1]) {
LAB_18000d86e:
        return (uint)(param_2 < param_3);
      }
      puVar2 = (undefined8 *)*param_4;
      uVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                        (pCVar5 + 0x10,(char *)puVar2[2]);
      if (uVar3 == 0) {
        uVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                          (pCVar5 + 8,(char *)puVar2[1]);
        if (uVar3 == 0) {
          uVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                            (pCVar5,(char *)*puVar2);
          return uVar3 >> 0x1f;
        }
      }
      goto LAB_18000d7dd;
    }
    pCVar5 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
             ((longlong)param_2 * 0x20 + lVar1);
    pCVar4 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
             ((longlong)param_3 * 0x20 + lVar1);
    if ((pCVar5 == (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_1[1]) ||
       (pCVar4 == (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_1[1]))
    goto LAB_18000d86e;
  }
  uVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                    (pCVar5 + 0x10,*(char **)(pCVar4 + 0x10));
  if (uVar3 == 0) {
    uVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                      (pCVar5 + 8,*(char **)(pCVar4 + 8));
    if (uVar3 == 0) {
      uVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                        (pCVar5,*(char **)pCVar4);
    }
  }
LAB_18000d7dd:
  return uVar3 >> 0x1f;
}

/* ---- FUNC 0000D7EF FUN_18000d7ef (95 bytes) ---- */

ulonglong FUN_18000d7ef(undefined8 *param_1,int param_2,int param_3,longlong *param_4)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar1;
  undefined8 *puVar2;
  uint uVar3;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar4;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar5;
  
  pCVar4 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)*param_1;
  if (param_3 == -1) {
    pCVar1 = pCVar4 + (longlong)param_2 * 0x20;
    if (pCVar1 == (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_1[1]) {
LAB_18000d86e:
      return CONCAT71((int7)((ulonglong)pCVar4 >> 8),param_2 < param_3);
    }
    puVar2 = (undefined8 *)*param_4;
    uVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                      (pCVar1 + 0x10,(char *)puVar2[2]);
    if (uVar3 == 0) {
      uVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                        (pCVar1 + 8,(char *)puVar2[1]);
      if (uVar3 == 0) {
        uVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                          (pCVar1,(char *)*puVar2);
        return (ulonglong)(uVar3 >> 0x1f);
      }
    }
  }
  else {
    pCVar1 = pCVar4 + (longlong)param_2 * 0x20;
    pCVar5 = pCVar4 + (longlong)param_3 * 0x20;
    pCVar4 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_1[1];
    if ((pCVar1 == pCVar4) || (pCVar5 == pCVar4)) goto LAB_18000d86e;
    uVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                      (pCVar1 + 0x10,*(char **)(pCVar5 + 0x10));
    if (uVar3 == 0) {
      uVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                        (pCVar1 + 8,*(char **)(pCVar5 + 8));
      if (uVar3 == 0) {
        uVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                          (pCVar1,*(char **)pCVar5);
      }
    }
  }
  return (ulonglong)(uVar3 >> 0x1f);
}

/* ---- FUNC 0000D84E FUN_18000d84e (53 bytes) ---- */

ulonglong FUN_18000d84e(longlong param_1,int param_2,int param_3)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar1;
  uint uVar2;
  longlong in_RAX;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar3;
  longlong in_R10;
  
  this = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(in_R10 + in_RAX);
  pCVar3 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
           ((longlong)param_3 * 0x20 + in_RAX);
  pCVar1 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)(param_1 + 8);
  if ((this != pCVar1) && (pCVar3 != pCVar1)) {
    uVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                      (this + 0x10,*(char **)(pCVar3 + 0x10));
    if (uVar2 == 0) {
      uVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                        (this + 8,*(char **)(pCVar3 + 8));
      if (uVar2 == 0) {
        uVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                          (this,*(char **)pCVar3);
      }
    }
    return (ulonglong)(uVar2 >> 0x1f);
  }
  return CONCAT71((int7)((ulonglong)pCVar1 >> 8),param_2 < param_3);
}

/* ---- FUNC 0000D890 FUN_18000d890 (50 bytes) ---- */

void FUN_18000d890(longlong param_1)

{
  if (*(HKEY *)(param_1 + 8) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(param_1 + 8));
    *(undefined8 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0;
    return;
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}

/* ---- FUNC 0000D8D0 FUN_18000d8d0 (78 bytes) ---- */

CPtrArray * FUN_18000d8d0(CPtrArray *param_1,uint param_2)

{
  FUN_18000cf20(param_1);
  if ((param_2 & 1) != 0) {
    if ((param_2 & 4) == 0) {
      operator_delete(param_1);
      return param_1;
    }
    operator_delete(param_1);
  }
  return param_1;
}

/* ---- FUNC 0000D920 FUN_18000d920 (78 bytes) ---- */

CPtrArray * FUN_18000d920(CPtrArray *param_1,uint param_2)

{
  CPtrArray::~CPtrArray(param_1);
  if ((param_2 & 1) != 0) {
    if ((param_2 & 4) == 0) {
      operator_delete(param_1);
      return param_1;
    }
    operator_delete(param_1);
  }
  return param_1;
}

/* ---- FUNC 0000D970 FUN_18000d970 (88 bytes) ---- */

CGdiObject * FUN_18000d970(CGdiObject *param_1,uint param_2)

{
  *(undefined ***)param_1 = CBitmap::vftable;
  FUN_18000d2a0(param_1);
  if ((param_2 & 1) != 0) {
    if ((param_2 & 4) == 0) {
      operator_delete(param_1);
      return param_1;
    }
    operator_delete(param_1);
  }
  return param_1;
}

/* ---- FUNC 0000D9D0 FUN_18000d9d0 (78 bytes) ---- */

CGdiObject * FUN_18000d9d0(CGdiObject *param_1,uint param_2)

{
  FUN_18000d2a0(param_1);
  if ((param_2 & 1) != 0) {
    if ((param_2 & 4) == 0) {
      operator_delete(param_1);
      return param_1;
    }
    operator_delete(param_1);
  }
  return param_1;
}

/* ---- FUNC 0000DA20 FUN_18000da20 (792 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

HMODULE FUN_18000da20(longlong *param_1)

{
  ulonglong uVar1;
  LPCSTR pCVar2;
  ulonglong uVar3;
  void *pvVar4;
  LPCSTR **pppCVar5;
  ulonglong _Size;
  ulonglong uVar6;
  int iVar7;
  uint uVar8;
  longlong *plVar9;
  LPCSTR ***ppppCVar10;
  HMODULE pHVar11;
  void *pvVar12;
  char cVar13;
  ulonglong uVar14;
  LPCSTR ***ppppCVar15;
  undefined1 auStack_88 [32];
  int local_68;
  longlong local_60;
  longlong *local_58;
  LPCSTR **local_50;
  undefined8 uStack_48;
  ulonglong local_40;
  ulonglong local_38;
  ulonglong local_30;
  
  local_30 = DAT_1800791f8 ^ (ulonglong)auStack_88;
  uStack_48 = 0;
  local_40 = 0;
  local_38 = 0xf;
  local_50 = (LPCSTR **)0x0;
  local_58 = param_1;
  srand(0x37e07b3d);
  local_68 = 0;
  if (param_1[2] != 0) {
    local_60 = 0;
    do {
      plVar9 = param_1;
      if (0xf < (ulonglong)param_1[3]) {
        plVar9 = (longlong *)*param_1;
      }
      iVar7 = toupper((int)*(char *)(local_60 + (longlong)plVar9));
      uVar8 = rand();
      uVar6 = local_38;
      _Size = local_40;
      uVar8 = uVar8 & 0x8000003f;
      if ((int)uVar8 < 0) {
        uVar8 = (uVar8 - 1 | 0xffffffc0) + 1;
      }
      cVar13 = ((byte)uVar8 ^ (char)iVar7 - 0x20U) + 0x20;
      if (local_40 < local_38) {
        ppppCVar10 = &local_50;
        if (0xf < local_38) {
          ppppCVar10 = (LPCSTR ***)local_50;
        }
        pCVar2 = (LPCSTR)((longlong)ppppCVar10 + local_40);
        local_40 = local_40 + 1;
        *pCVar2 = cVar13;
        *(CHAR *)((longlong)ppppCVar10 + _Size + 1) = '\0';
      }
      else {
        if (local_40 == 0x7fffffffffffffff) {
                    /* WARNING: Subroutine does not return */
          FUN_18000ace0();
        }
        uVar1 = local_40 + 1;
        uVar14 = uVar1 | 0xf;
        if (uVar14 < 0x8000000000000000) {
          if (0x7fffffffffffffff - (local_38 >> 1) < local_38) {
            uVar14 = 0x7fffffffffffffff;
            ppppCVar10 = (LPCSTR ***)FUN_180007f10(0x8000000000000000);
          }
          else {
            uVar3 = local_38 + (local_38 >> 1);
            if (uVar14 < uVar3) {
              uVar14 = uVar3;
            }
            uVar3 = uVar14 + 1;
            if (uVar3 < 0x1000) {
              if (uVar3 == 0) {
                ppppCVar10 = (LPCSTR ***)0x0;
              }
              else {
                ppppCVar10 = operator_new(uVar3);
              }
            }
            else {
              ppppCVar10 = (LPCSTR ***)FUN_180007f10(uVar3);
            }
          }
        }
        else {
          uVar14 = 0x7fffffffffffffff;
          ppppCVar10 = (LPCSTR ***)FUN_180007f10(0x8000000000000000);
        }
        pppCVar5 = local_50;
        local_40 = uVar1;
        local_38 = uVar14;
        if (uVar6 < 0x10) {
          memcpy(ppppCVar10,&local_50,_Size);
          *(char *)((longlong)ppppCVar10 + _Size) = cVar13;
          *(CHAR *)((longlong)ppppCVar10 + _Size + 1) = '\0';
          local_50 = (LPCSTR **)ppppCVar10;
        }
        else {
          memcpy(ppppCVar10,local_50,_Size);
          *(char *)((longlong)ppppCVar10 + _Size) = cVar13;
          *(CHAR *)((longlong)ppppCVar10 + _Size + 1) = '\0';
          ppppCVar15 = (LPCSTR ***)pppCVar5;
          if ((0xfff < uVar6 + 1) &&
             (ppppCVar15 = (LPCSTR ***)pppCVar5[-1],
             (LPCSTR)0x1f < (LPCSTR)((longlong)pppCVar5 + (-8 - (longlong)ppppCVar15)))) {
                    /* WARNING: Subroutine does not return */
            _invalid_parameter_noinfo_noreturn();
          }
          operator_delete(ppppCVar15);
          local_50 = (LPCSTR **)ppppCVar10;
        }
      }
      local_68 = local_68 + 1;
      local_60 = local_60 + 1;
    } while ((ulonglong)(longlong)local_68 < (ulonglong)param_1[2]);
  }
  ppppCVar10 = &local_50;
  if (0xf < local_38) {
    ppppCVar10 = (LPCSTR ***)local_50;
  }
  pHVar11 = LoadLibraryA((LPCSTR)ppppCVar10);
  if (pHVar11 == (HMODULE)0x0) {
    GetLastError();
  }
  if (0xf < local_38) {
    ppppCVar10 = (LPCSTR ***)local_50;
    if ((0xfff < local_38 + 1) &&
       (ppppCVar10 = (LPCSTR ***)local_50[-1],
       (LPCSTR)0x1f < (LPCSTR)((longlong)local_50 + (-8 - (longlong)ppppCVar10)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(ppppCVar10);
  }
  local_40 = 0;
  local_38 = 0xf;
  local_50 = (LPCSTR **)((ulonglong)local_50 & 0xffffffffffffff00);
  if (0xf < (ulonglong)param_1[3]) {
    pvVar4 = (void *)*param_1;
    pvVar12 = pvVar4;
    if ((0xfff < param_1[3] + 1U) &&
       (pvVar12 = *(void **)((longlong)pvVar4 + -8),
       0x1f < (ulonglong)((longlong)pvVar4 + (-8 - (longlong)pvVar12)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar12);
  }
  param_1[2] = 0;
  param_1[3] = 0xf;
  *(undefined1 *)param_1 = 0;
  return pHVar11;
}

/* ---- FUNC 0000DD40 AddCategory (6 bytes) ---- */

/* public: virtual long __cdecl CApwnLibraries::AddCategory(char const * __ptr64,struct IACategory *
   __ptr64 * __ptr64) __ptr64 */

long __thiscall CApwnLibraries::AddCategory(CApwnLibraries *this,char *param_1,IACategory **param_2)

{
                    /* 0xdd40  57  ?AddCategory@CApwnLibraries@@UEAAJPEBDPEAPEAUIACategory@@@Z
                       0xdd40  166  ?RemoveCategory@CApwnLibraries@@UEAAJPEAUIACategory@@@Z */
  return -0x7fffbffb;
}

/* ---- FUNC 0000DD50 AddLibraries (352 bytes) ---- */

/* public: int __cdecl CApwnLibraries::AddLibraries(class CLibraryArray & __ptr64,class CStringArray
   const & __ptr64) __ptr64 */

int __thiscall
CApwnLibraries::AddLibraries(CApwnLibraries *this,CLibraryArray *param_1,CStringArray *param_2)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar1;
  undefined8 *puVar2;
  int iVar3;
  uint uVar4;
  longlong lVar5;
  uint uVar6;
  longlong lVar7;
  longlong lVar8;
  int local_res18;
  IAEditCategories *local_res20;
  
                    /* 0xdd50  58
                       ?AddLibraries@CApwnLibraries@@QEAAHAEAVCLibraryArray@@AEBVCStringArray@@@Z */
  lVar7 = *(longlong *)(param_2 + 0x10);
  uVar6 = 0;
  local_res18 = 0;
  if (0 < lVar7) {
    lVar8 = 0;
    lVar5 = 0;
    do {
      if ((lVar8 < 0) || (lVar7 <= lVar8)) {
LAB_18000deab:
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      iVar3 = FUN_180010330((longlong)param_1,*(char **)(*(longlong *)(param_2 + 8) + lVar8 * 8));
      if (iVar3 < 0) {
        if (*(longlong *)(param_2 + 0x10) <= lVar8) goto LAB_18000deab;
        uVar4 = AddNewLibrary(this,*(char **)(*(longlong *)(param_2 + 8) + lVar8 * 8),0);
        if (uVar4 != 0) {
          uVar6 = uVar6 | uVar4;
          lVar5 = lVar5 + -1;
        }
      }
      else {
        lVar7 = (longlong)iVar3;
        if (*(longlong *)(param_1 + 0x10) <= lVar7) {
LAB_18000dea5:
                    /* WARNING: Subroutine does not return */
          AfxThrowInvalidArgException();
        }
        pCVar1 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
                  (*(longlong *)(param_1 + 8) + lVar7 * 8);
        CPtrArray::SetAtGrow((CPtrArray *)(this + 8),*(__int64 *)(this + 0x18),pCVar1);
        if ((lVar5 < 0) || (*(longlong *)(this + 0x18) <= lVar5)) goto LAB_18000dea5;
        puVar2 = *(undefined8 **)(*(longlong *)(*(longlong *)(this + 0x10) + lVar5 * 8) + 8);
        local_res20 = (IAEditCategories *)0x0;
        iVar3 = (**(code **)*puVar2)(puVar2,&DAT_180056230,&local_res20);
        if (iVar3 < 0) {
          uVar6 = uVar6 | 4;
        }
        else {
          AddPaletteCategories(this,pCVar1,local_res20);
          (**(code **)(*(longlong *)local_res20 + 0x10))();
          local_res20 = (IAEditCategories *)0x0;
        }
        CPtrArray::RemoveAt((CPtrArray *)param_1,lVar7,1);
      }
      lVar8 = lVar8 + 1;
      lVar7 = *(longlong *)(param_2 + 0x10);
      local_res18 = local_res18 + 1;
      lVar5 = lVar5 + 1;
    } while (local_res18 < lVar7);
  }
  return uVar6;
}

/* ---- FUNC 0000DEC0 AddModelType (496 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: bool __cdecl CApwnLibraries::AddModelType(char const * __ptr64,char const *
   __ptr64,struct IAModelType * __ptr64) __ptr64 */

bool __thiscall
CApwnLibraries::AddModelType(CApwnLibraries *this,char *param_1,char *param_2,IAModelType *param_3)

{
  char cVar1;
  char cVar2;
  byte extraout_var;
  ulonglong uVar3;
  char *pcVar4;
  longlong *plVar5;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar6;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar7;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar8;
  longlong lVar9;
  bool bVar10;
  undefined1 auStackY_e8 [32];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_b8 [8];
  undefined8 *local_b0;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_a8 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_a0;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_98;
  char local_88 [64];
  ulonglong local_48;
  
                    /* 0xdec0  59  ?AddModelType@CApwnLibraries@@QEAA_NPEBD0PEAUIAModelType@@@Z */
  local_48 = DAT_1800791f8 ^ (ulonglong)auStackY_e8;
  if ((param_2 == (char *)0x0) || (param_3 == (IAModelType *)0x0)) {
LAB_18000e089:
    bVar10 = false;
  }
  else {
    (**(code **)(*(longlong *)param_3 + 0x18))(param_3,local_88,0x40);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_b8,param_2);
    uVar3 = FUN_180010240((longlong)(this + 0x30),(undefined8 *)local_b8);
    lVar9 = (longlong)(int)uVar3;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_b8);
    if ((int)uVar3 < 0) {
      pcVar4 = param_1;
      do {
        cVar1 = *pcVar4;
        cVar2 = pcVar4[_m_acmcatalog - (longlong)param_1];
        if (cVar1 != cVar2) break;
        pcVar4 = pcVar4 + 1;
      } while (cVar2 != '\0');
      if (cVar1 != cVar2) {
        pcVar4 = param_1;
        do {
          cVar1 = *pcVar4;
          cVar2 = pcVar4[_m_HybridModelLib - (longlong)param_1];
          if (cVar1 != cVar2) break;
          pcVar4 = pcVar4 + 1;
        } while (cVar2 != '\0');
        if (cVar1 != cVar2) goto LAB_18000e089;
      }
      local_b0 = operator_new(0x48);
      if (local_b0 == (undefined8 *)0x0) {
        plVar5 = (longlong *)0x0;
      }
      else {
        plVar5 = FUN_18000cec0(local_b0);
      }
      (**(code **)(*plVar5 + 0x20))(plVar5,param_2);
      *(undefined4 *)(plVar5 + 8) = 1;
      CPtrArray::SetAtGrow((CPtrArray *)(this + 0x30),*(__int64 *)(this + 0x40),plVar5);
    }
    else {
      if ((lVar9 < 0) || (*(longlong *)(this + 0x40) <= lVar9)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      plVar5 = *(longlong **)(*(longlong *)(this + 0x38) + lVar9 * 8);
    }
    (**(code **)(*plVar5 + 0x28))(plVar5,param_3);
    lVar9 = FUN_180010600((longlong *)(this + 0x90),local_88);
    if (lVar9 < 0) {
      local_a0 = local_b8;
      local_98 = local_a8;
      pCVar6 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
               CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_b8,local_88);
      pCVar7 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
               CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_a8,param_2);
      pCVar8 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
               CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                         ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b0
                          ,param_1);
      FUN_18000ebf0((longlong *)(this + 0x90),pCVar8,pCVar7,pCVar6,1);
    }
    bVar10 = (bool)(extraout_var >> 7 ^ 1);
  }
  return bVar10;
}

/* ---- FUNC 0000E0C0 FUN_18000e0c0 (58 bytes) ---- */

undefined8 FUN_18000e0c0(longlong param_1,longlong *param_2)

{
  if (param_2 == (longlong *)0x0) {
    return 0x80070057;
  }
  CPtrArray::SetAtGrow((CPtrArray *)(param_1 + 0x18),*(__int64 *)(param_1 + 0x28),param_2);
  (**(code **)(*param_2 + 8))(param_2);
  return 0;
}

/* ---- FUNC 0000E100 AddNewLibrary (1937 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: int __cdecl CApwnLibraries::AddNewLibrary(char const * __ptr64,int) __ptr64 */

int __thiscall CApwnLibraries::AddNewLibrary(CApwnLibraries *this,char *param_1,int param_2)

{
  int iVar1;
  int extraout_EAX;
  char *pcVar2;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar3;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar4;
  DWORD DVar5;
  undefined1 auStackY_2c8 [32];
  IAEditCategories *local_298;
  undefined8 local_290;
  IAEditCategories *local_288;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_280;
  undefined4 local_278 [4];
  CHAR local_268 [272];
  char local_158 [272];
  ulonglong local_48;
  
                    /* 0xe100  60  ?AddNewLibrary@CApwnLibraries@@QEAAHPEBDH@Z */
  local_48 = DAT_1800791f8 ^ (ulonglong)auStackY_2c8;
  GetModuleFileNameA((HMODULE)0x0,local_268,0x104);
  pcVar2 = _strlwr(local_268);
  pcVar2 = strstr(pcVar2,"hysys.exe");
  if ((pcVar2 != (char *)0x0) && (iVar1 = _stricmp(param_1,_m_builtin), iVar1 != 0)) {
    return 2;
  }
  iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                    (&m_acmcatalogold,param_1);
  if (iVar1 == 0) {
    param_1 = _m_acmcatalog;
  }
  iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                    (&m_builtin,param_1);
  if (iVar1 == 0) {
    pCVar3 = operator_new(0x10);
    local_280 = pCVar3;
    if (pCVar3 == (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
      pCVar3 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
    }
    else {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar3);
      *(undefined8 *)(pCVar3 + 8) = 0;
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(pCVar3,_m_builtin)
    ;
    local_298 = (IAEditCategories *)0x0;
    iVar1 = (**(code **)**(undefined8 **)(this + 0x88))
                      (*(undefined8 **)(this + 0x88),&DAT_180056270,&local_298);
    if (-1 < iVar1) {
      FUN_1800164b0((longlong)pCVar3,(longlong *)local_298);
      (**(code **)(*(longlong *)local_298 + 0x10))();
      local_298 = (IAEditCategories *)0x0;
    }
    CPtrArray::SetAtGrow((CPtrArray *)(this + 8),*(__int64 *)(this + 0x18),pCVar3);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_288,param_1);
    AddPaletteCategories
              (this,(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_288,
               *(IAEditCategories **)(this + 0x88));
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_288);
    goto LAB_18000e6bb;
  }
  iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                    (&m_capeopen,param_1);
  if (iVar1 == 0) {
    pCVar3 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
    local_290 = (longlong *)0x0;
    iVar1 = FUN_18000f4f0(&DAT_1800562b0,&DAT_180056270,&local_290);
    if (-1 < iVar1) {
      (**(code **)(*local_290 + 0x18))(local_290,0,0);
    }
    if (local_290 == (longlong *)0x0) {
      return 2;
    }
    pCVar4 = operator_new(0x10);
    local_280 = pCVar4;
    if (pCVar4 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar4);
      *(undefined8 *)(pCVar4 + 8) = 0;
      pCVar3 = pCVar4;
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              (pCVar3,_m_capeopen);
    FUN_1800164b0((longlong)pCVar3,local_290);
    CPtrArray::SetAtGrow((CPtrArray *)(this + 8),*(__int64 *)(this + 0x18),pCVar3);
    local_298 = (IAEditCategories *)0x0;
    iVar1 = (**(code **)*local_290)();
    if ((-1 < iVar1) && (local_298 != (IAEditCategories *)0x0)) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_288,param_1
                );
      AddPaletteCategories
                (this,(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_288,
                 local_298);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_288);
      goto LAB_18000e6a5;
    }
  }
  else {
    iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                      (&m_acmcatalog,param_1);
    if (iVar1 == 0) {
      pCVar3 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
      local_290 = (longlong *)0x0;
      iVar1 = FUN_18000f4f0(&DAT_180056460,&DAT_180056270,&local_290);
      if (iVar1 < 0) {
        return 2;
      }
      iVar1 = (**(code **)(*local_290 + 0x18))(local_290,0,0);
      if (iVar1 < 0) {
        return 2;
      }
      if (local_290 == (longlong *)0x0) {
        return 2;
      }
      pCVar4 = operator_new(0x10);
      local_280 = pCVar4;
      if (pCVar4 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar4);
        *(undefined8 *)(pCVar4 + 8) = 0;
        pCVar3 = pCVar4;
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                (pCVar3,_m_acmcatalog);
      FUN_1800164b0((longlong)pCVar3,local_290);
      CPtrArray::SetAtGrow((CPtrArray *)(this + 8),*(__int64 *)(this + 0x18),pCVar3);
      local_298 = (IAEditCategories *)0x0;
      iVar1 = (**(code **)*local_290)();
      if ((-1 < iVar1) && (local_298 != (IAEditCategories *)0x0)) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_288,
                   param_1);
        AddPaletteCategories
                  (this,(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_288,
                   local_298);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_288);
LAB_18000e6a5:
        (**(code **)(*(longlong *)local_298 + 0x10))();
      }
    }
    else {
      iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                        (&m_acmbuiltin,param_1);
      if (iVar1 == 0) {
        pCVar3 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
        local_290 = (longlong *)0x0;
        iVar1 = FUN_18000f4f0(&DAT_180056470,&DAT_180056270,&local_290);
        if (((-1 < iVar1) && (iVar1 = (**(code **)(*local_290 + 0x18))(local_290,0,0), -1 < iVar1))
           && (local_290 != (longlong *)0x0)) {
          pCVar4 = operator_new(0x10);
          local_280 = pCVar4;
          if (pCVar4 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar4);
            *(undefined8 *)(pCVar4 + 8) = 0;
            pCVar3 = pCVar4;
          }
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    (pCVar3,_m_acmbuiltin);
          FUN_1800164b0((longlong)pCVar3,local_290);
          CPtrArray::SetAtGrow((CPtrArray *)(this + 8),*(__int64 *)(this + 0x18),pCVar3);
          local_298 = (IAEditCategories *)0x0;
          iVar1 = (**(code **)*local_290)(local_290,&DAT_180056230,&local_298);
          if ((-1 < iVar1) && (local_298 != (IAEditCategories *)0x0)) {
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_288,
                       param_1);
            AddPaletteCategories
                      (this,(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            &local_288,local_298);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_288);
            (**(code **)(*(longlong *)local_298 + 0x10))();
          }
          iVar1 = (**(code **)(*local_290 + 0x10))();
          return iVar1;
        }
        return 2;
      }
      iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                        (&m_HybridModelLib,param_1);
      pCVar3 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
      if (iVar1 != 0) {
        local_298 = (IAEditCategories *)0x0;
        iVar1 = FUN_18000f4f0(&DAT_1800562a0,&DAT_180056270,&local_298);
        if (iVar1 < 0) {
          return 1;
        }
        local_290 = (longlong *)((ulonglong)local_290._4_4_ << 0x20);
        local_278[0] = 0;
        DVar5 = APModLibGetValues((longlong)param_1,local_158,0x104,(undefined4 *)&local_290,
                                  local_278);
        if (extraout_EAX < 1) {
          DVar5 = 8;
        }
        else {
          iVar1 = (**(code **)(*(longlong *)local_298 + 0x18))();
          if (iVar1 < 0) {
            DVar5 = 2;
            if ((iVar1 != -0x7ffcfffb) && (DVar5 = 2, iVar1 == -0x7ffcffe0)) {
              DVar5 = 0x10;
            }
          }
          else {
            iVar1 = FUN_180010330((longlong)(this + 8),param_1);
            if (iVar1 < 0) {
              pCVar4 = operator_new(0x10);
              local_280 = pCVar4;
              if (pCVar4 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar4);
                *(undefined8 *)(pCVar4 + 8) = 0;
                pCVar3 = pCVar4;
              }
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                        (pCVar3,param_1);
              FUN_1800164b0((longlong)pCVar3,(longlong *)local_298);
              CPtrArray::SetAtGrow((CPtrArray *)(this + 8),*(__int64 *)(this + 0x18),pCVar3);
              local_288 = (IAEditCategories *)0x0;
              iVar1 = (*(code *)**(undefined8 **)local_298)();
              if (iVar1 < 0) {
                DVar5 = 4;
              }
              else {
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_280,param_1);
                AddPaletteCategories
                          (this,(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                &local_280,local_288);
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_280);
                (**(code **)(*(longlong *)local_288 + 0x10))();
              }
            }
          }
        }
        (**(code **)(*(longlong *)local_298 + 0x10))();
        local_298 = (IAEditCategories *)0x0;
        if (param_2 != 0) {
          if (DVar5 == 0) {
            PostMainWndMessage2(0x565,0,0);
            return 0;
          }
          return DVar5;
        }
        return DVar5;
      }
      local_290 = (longlong *)0x0;
      iVar1 = FUN_18000f4f0(&DAT_180056480,&DAT_180056270,&local_290);
      if (iVar1 < 0) {
        return 2;
      }
      iVar1 = (**(code **)(*local_290 + 0x18))(local_290,0,0);
      if (iVar1 < 0) {
        return 2;
      }
      if (local_290 == (longlong *)0x0) {
        return 2;
      }
      pCVar4 = operator_new(0x10);
      local_280 = pCVar4;
      if (pCVar4 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar4);
        *(undefined8 *)(pCVar4 + 8) = 0;
        pCVar3 = pCVar4;
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                (pCVar3,_m_HybridModelLib);
      FUN_1800164b0((longlong)pCVar3,local_290);
      CPtrArray::SetAtGrow((CPtrArray *)(this + 8),*(__int64 *)(this + 0x18),pCVar3);
      local_298 = (IAEditCategories *)0x0;
      iVar1 = (**(code **)*local_290)();
      if ((-1 < iVar1) && (local_298 != (IAEditCategories *)0x0)) {
        AddPaletteCategories(this,&m_HybridModelLib,local_298);
        goto LAB_18000e6a5;
      }
    }
  }
  (**(code **)(*local_290 + 0x10))();
LAB_18000e6bb:
  if (param_2 != 0) {
    PostMainWndMessage2(0x565,0,0);
  }
  return 0;
}

/* ---- FUNC 0000E8A0 AddPaletteCategories (616 bytes) ---- */

/* public: void __cdecl CApwnLibraries::AddPaletteCategories(class ATL::CStringT<char,class
   StrTraitMFC_DLL<char,class ATL::ChTraitsCRT<char> > > const & __ptr64,struct IAEditCategories *
   __ptr64) __ptr64 */

void __thiscall
CApwnLibraries::AddPaletteCategories
          (CApwnLibraries *this,
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_1,
          IAEditCategories *param_2)

{
  CPtrArray *this_00;
  char cVar1;
  char cVar2;
  longlong lVar3;
  int iVar4;
  longlong lVar5;
  char *pcVar6;
  ulonglong uVar7;
  longlong *plVar8;
  undefined4 local_res18 [2];
  IACategory *local_res20;
  char *local_68;
  longlong *local_60;
  undefined8 local_58;
  longlong *local_50;
  CPtrArray *local_48;
  
                    /* 0xe8a0  61
                       ?AddPaletteCategories@CApwnLibraries@@QEAAXAEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAUIAEditCategories@@@Z
                        */
  if (param_2 != (IAEditCategories *)0x0) {
    local_60 = (longlong *)0x0;
    (**(code **)(*(longlong *)param_2 + 0x30))(param_2,&local_60);
    local_res18[0] = 0;
    lVar5 = MMStructGetSorResStringEx();
    iVar4 = (**(code **)(*local_60 + 0x18))(local_60,1,&local_res20,local_res18);
    while (iVar4 == 0) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_68);
      lVar3 = *(longlong *)local_res20;
      pcVar6 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)&local_68,0x40);
      (**(code **)(lVar3 + 0x18))(local_res20,pcVar6,0x40);
      ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)&local_68,-1);
      pcVar6 = local_68;
      do {
        cVar1 = *pcVar6;
        cVar2 = pcVar6[lVar5 - (longlong)local_68];
        if (cVar1 != cVar2) break;
        pcVar6 = pcVar6 + 1;
      } while (cVar2 != '\0');
      if (cVar1 != cVar2) {
        CacheModelTypes(this,param_1,
                        (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_68,
                        local_res20,1);
        uVar7 = FUN_180010240((longlong)(this + 0x30),&local_68);
        iVar4 = (int)uVar7;
        if (iVar4 < 0) {
          plVar8 = operator_new(0x48);
          local_50 = plVar8;
          if (plVar8 == (longlong *)0x0) {
            plVar8 = (longlong *)0x0;
          }
          else {
            *plVar8 = (longlong)CPaletteCategory::vftable;
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(plVar8 + 2)
                      );
            this_00 = (CPtrArray *)(plVar8 + 3);
            local_48 = this_00;
            CPtrArray::CPtrArray(this_00);
            *(undefined ***)this_00 = CModelTypeArray::vftable;
            *(undefined4 *)(plVar8 + 1) = 1;
            *(undefined4 *)(plVar8 + 8) = 1;
          }
          (**(code **)(*plVar8 + 0x20))(plVar8,local_68);
          FUN_180011e40((longlong)plVar8,(longlong *)local_res20,'\0');
          *(undefined4 *)(plVar8 + 8) = 1;
          CPtrArray::SetAtGrow((CPtrArray *)(this + 0x30),*(__int64 *)(this + 0x40),plVar8);
        }
        else {
          if (*(longlong *)(this + 0x40) <= (longlong)iVar4) {
                    /* WARNING: Subroutine does not return */
            AfxThrowInvalidArgException();
          }
          FUN_180011e40(*(longlong *)(*(longlong *)(this + 0x38) + (longlong)iVar4 * 8),
                        (longlong *)local_res20,'\x01');
        }
      }
      (**(code **)(*(longlong *)local_res20 + 0x10))();
      local_res20 = (IACategory *)0x0;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_68);
      iVar4 = (**(code **)(*local_60 + 0x18))(local_60,1,&local_res20,local_res18);
    }
    (**(code **)(*local_60 + 0x10))();
    local_60 = (longlong *)0x0;
    local_res20 = (IACategory *)0x0;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_58,
               "Uncategorized");
    iVar4 = (**(code **)(*(longlong *)param_2 + 0x28))(param_2,local_58,&local_res20);
    if ((-1 < iVar4) && (local_res20 != (IACategory *)0x0)) {
      CacheModelTypes(this,param_1,
                      (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_58,
                      local_res20,0);
      (**(code **)(*(longlong *)local_res20 + 0x10))();
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_58);
  }
  return;
}

/* ---- FUNC 0000EB10 AddRef (15 bytes) ---- */

/* public: virtual unsigned long __cdecl CApwnLibraries::AddRef(void) __ptr64 */

ulong __thiscall CApwnLibraries::AddRef(CApwnLibraries *this)

{
  int iVar1;
  
                    /* 0xeb10  62  ?AddRef@CApwnLibraries@@UEAAKXZ */
  iVar1 = *(int *)(this + 0x80);
  *(ulong *)(this + 0x80) = iVar1 + 1U;
  return iVar1 + 1U;
}

/* ---- FUNC 0000EB20 FUN_18000eb20 (9 bytes) ---- */

void FUN_18000eb20(longlong param_1)

{
  *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + 1;
  return;
}

/* ---- FUNC 0000EB30 FUN_18000eb30 (9 bytes) ---- */

void FUN_18000eb30(longlong param_1)

{
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
  return;
}

/* ---- FUNC 0000EB40 FUN_18000eb40 (9 bytes) ---- */

void FUN_18000eb40(longlong param_1)

{
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  return;
}

/* ---- FUNC 0000EB50 AddStreamCategory (155 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __cdecl CApwnLibraries::AddStreamCategory(void) __ptr64 */

void __thiscall CApwnLibraries::AddStreamCategory(CApwnLibraries *this)

{
  int iVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  
                    /* 0xeb50  63  ?AddStreamCategory@CApwnLibraries@@QEAAXXZ */
  plVar3 = (longlong *)0x0;
  iVar1 = (**(code **)(**(longlong **)(this + 0x88) + 0x28))(*(longlong **)(this + 0x88),_m_streams)
  ;
  if (-1 < iVar1) {
    puVar2 = operator_new(0x48);
    if (puVar2 != (undefined8 *)0x0) {
      plVar3 = FUN_18000cec0(puVar2);
    }
    (**(code **)(*plVar3 + 0x20))(plVar3,_m_streams);
    FUN_180011e40((longlong)plVar3,(longlong *)0x0,'\0');
    *(undefined4 *)(plVar3 + 8) = 1;
    CPtrArray::SetAtGrow((CPtrArray *)(this + 0x30),*(__int64 *)(this + 0x40),plVar3);
    (**(code **)(_DAT_00000000 + 0x10))();
  }
  return;
}

/* ---- FUNC 0000EBF0 FUN_18000ebf0 (660 bytes) ---- */

undefined8
FUN_18000ebf0(longlong *param_1,
             CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *param_2,
             CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *param_3,
             CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *param_4,
             int param_5)

{
  uint uVar1;
  uint *puVar2;
  int *piVar3;
  int *piVar4;
  bool bVar5;
  int iVar6;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar7;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this_00;
  longlong *plVar8;
  longlong lVar9;
  int iVar10;
  undefined8 *puVar11;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res8 [8];
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *local_res10;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *local_res18;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *local_res20;
  char *local_a8;
  char *local_a0;
  char *local_98;
  int local_90;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_88;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_80 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_78 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_70;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_68;
  longlong *local_60;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_58 [3];
  
  local_88 = local_res8;
  local_70 = local_80;
  local_res10 = param_2;
  local_res18 = param_3;
  local_res20 = param_4;
  pCVar7 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
           ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
           CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res8,param_4);
  local_58[0] = pCVar7;
  this = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
         ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
         CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_80,param_3);
  local_68 = this;
  this_00 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_78,param_2);
  local_70 = this_00;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_a8,
             (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)this_00);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_a0,
             (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)this);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_98,
             (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar7);
  iVar10 = param_5;
  local_90 = param_5;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(this_00);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(this);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar7);
  param_5 = -1;
  local_68 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_a8;
  local_60 = param_1;
  plVar8 = FUN_18000c980((longlong *)local_58,(int *)param_1[3],param_1[4],&param_5,
                         (longlong *)&local_68);
  puVar2 = (uint *)*plVar8;
  piVar3 = (int *)plVar8[1];
  if (puVar2 == (uint *)param_1[4]) {
LAB_18000edc6:
    FUN_18000c2a0(param_1,&local_88,
                  (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                  param_1[1],
                  (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                  &local_a8);
    iVar10 = (int)((longlong)local_88 - *param_1 >> 5);
    piVar4 = (int *)param_1[4];
    param_5 = iVar10;
    if (piVar4 == (int *)param_1[5]) {
      FUN_18000b790(param_1 + 3,piVar3,&param_5);
    }
    else if (piVar3 == piVar4) {
      *piVar4 = iVar10;
      param_1[4] = param_1[4] + 4;
    }
    else {
      *piVar4 = piVar4[-1];
      param_1[4] = param_1[4] + 4;
      FUN_18000b6e0(piVar3,(longlong)(piVar4 + -1),(longlong)piVar4);
      *piVar3 = iVar10;
    }
  }
  else {
    uVar1 = *puVar2;
    if (uVar1 != 0xffffffff) {
      pCVar7 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
               ((longlong)(int)uVar1 * 0x20 + *param_1);
      if (pCVar7 == (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_1[1]) {
        bVar5 = (int)uVar1 < -1;
      }
      else {
        iVar6 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                          (pCVar7 + 0x10,local_98);
        if (iVar6 == 0) {
          iVar6 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                            (pCVar7 + 8,local_a0);
          if (iVar6 == 0) {
            iVar6 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                              (pCVar7,local_a8);
          }
        }
        bVar5 = SUB41((uint)iVar6 >> 0x1f,0);
      }
      if (bVar5 != false) goto LAB_18000edc6;
    }
    uVar1 = *puVar2;
    if (uVar1 != 0xffffffff) {
      puVar11 = (undefined8 *)((longlong)(int)uVar1 * 0x20 + *param_1);
      if (puVar11 == (undefined8 *)param_1[1]) {
        bVar5 = uVar1 < 0x80000000;
      }
      else {
        iVar6 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_98,(char *)puVar11[2]);
        if (iVar6 == 0) {
          iVar6 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &local_a0,(char *)puVar11[1]);
          if (iVar6 == 0) {
            iVar6 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                               &local_a8,(char *)*puVar11);
          }
        }
        bVar5 = SUB41((uint)iVar6 >> 0x1f,0);
      }
      if (bVar5 != false) goto LAB_18000edc6;
    }
    lVar9 = (longlong)(int)*puVar2 * 0x20 + *param_1;
    if (lVar9 != param_1[1]) {
      *(int *)(lVar9 + 0x18) = iVar10;
    }
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_98);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_a0);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_a8);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_res10);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_res18);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_res20);
  return 1;
}

/* ---- FUNC 0000EE90 AppendLibrary (272 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: void __cdecl CApwnLibraries::AppendLibrary(class ATL::CStringT<char,class
   StrTraitMFC_DLL<char,class ATL::ChTraitsCRT<char> > > & __ptr64,struct IAUserModelLibrary *
   __ptr64) __ptr64 */

void __thiscall
CApwnLibraries::AppendLibrary
          (CApwnLibraries *this,
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_1,
          IAUserModelLibrary *param_2)

{
  int iVar1;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar2;
  undefined1 auStackY_188 [32];
  undefined4 local_158;
  undefined4 local_154;
  IAEditCategories *local_150;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_148;
  char local_138 [272];
  ulonglong local_28;
  
                    /* 0xee90  65
                       ?AppendLibrary@CApwnLibraries@@QEAAXAEAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAUIAUserModelLibrary@@@Z
                        */
  local_28 = DAT_1800791f8 ^ (ulonglong)auStackY_188;
  pCVar2 = operator_new(0x10);
  local_148 = pCVar2;
  if (pCVar2 == (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
    pCVar2 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
  }
  else {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar2);
    *(undefined8 *)(pCVar2 + 8) = 0;
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            (pCVar2,*(char **)param_1);
  FUN_1800164b0((longlong)pCVar2,(longlong *)param_2);
  local_154 = 0;
  local_158 = 0;
  APModLibGetValues(*(longlong *)param_1,local_138,0x104,&local_154,&local_158);
  CPtrArray::SetAtGrow((CPtrArray *)(this + 8),*(__int64 *)(this + 0x18),pCVar2);
  local_150 = (IAEditCategories *)0x0;
  iVar1 = (*(code *)**(undefined8 **)param_2)(param_2,&DAT_180056230,&local_150);
  if (-1 < iVar1) {
    AddPaletteCategories(this,param_1,local_150);
    (**(code **)(*(longlong *)local_150 + 0x10))();
  }
  return;
}

/* ---- FUNC 0000EFA0 AppendLibs (59 bytes) ---- */

/* public: int __cdecl CApwnLibraries::AppendLibs(class CStringArray const & __ptr64,class
   CNameAndStateArray & __ptr64) __ptr64 */

int __thiscall
CApwnLibraries::AppendLibs(CApwnLibraries *this,CStringArray *param_1,CNameAndStateArray *param_2)

{
  int iVar1;
  
                    /* 0xefa0  66
                       ?AppendLibs@CApwnLibraries@@QEAAHAEBVCStringArray@@AEAVCNameAndStateArray@@@Z
                        */
  MergeCategories(this,param_2);
  iVar1 = MergeLibraries(this,param_1);
  FUN_180013920((CPtrArray *)(this + 0x30));
  return iVar1;
}

/* ---- FUNC 0000EFE0 BuildCategoryInfo (307 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __cdecl CApwnLibraries::BuildCategoryInfo(class CNameAndStateArray & __ptr64)
   __ptr64 */

void __thiscall CApwnLibraries::BuildCategoryInfo(CApwnLibraries *this,CNameAndStateArray *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  int iVar3;
  char *pcVar4;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar5;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this_00;
  longlong lVar6;
  int iVar7;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res8 [16];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res18 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_res20;
  
                    /* 0xefe0  68
                       ?BuildCategoryInfo@CApwnLibraries@@QEAAXAEAVCNameAndStateArray@@@Z */
  iVar7 = 0;
  if (0 < *(longlong *)(this + 0x40)) {
    lVar6 = 0;
    do {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res8);
      if ((lVar6 < 0) || (*(longlong *)(this + 0x40) <= lVar6)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      plVar1 = *(longlong **)(*(longlong *)(this + 0x38) + lVar6 * 8);
      lVar2 = *plVar1;
      pcVar4 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)local_res8,0x40);
      (**(code **)(lVar2 + 0x18))(plVar1,pcVar4,0x40);
      ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)local_res8,-1);
      iVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                        (local_res8,_m_streams);
      if (iVar3 != 0) {
        pCVar5 = operator_new(0x10);
        local_res20 = pCVar5;
        if (pCVar5 == (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
          pCVar5 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
        }
        else {
          this_00 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                              (local_res18,
                               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                *)local_res8);
          lVar2 = plVar1[8];
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar5);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    (pCVar5,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                             *)this_00);
          *(int *)(pCVar5 + 8) = (int)lVar2;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(this_00);
        }
        CPtrArray::SetAtGrow((CPtrArray *)param_1,*(__int64 *)(param_1 + 0x10),pCVar5);
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res8);
      iVar7 = iVar7 + 1;
      lVar6 = lVar6 + 1;
    } while ((longlong)iVar7 < *(longlong *)(this + 0x40));
  }
  return;
}

/* ---- FUNC 0000F120 BuildLibraryInfo (47 bytes) ---- */

/* public: void __cdecl CApwnLibraries::BuildLibraryInfo(class CStringArray & __ptr64) __ptr64 */

void __thiscall CApwnLibraries::BuildLibraryInfo(CApwnLibraries *this,CStringArray *param_1)

{
  longlong lVar1;
  int iVar2;
  
                    /* 0xf120  69  ?BuildLibraryInfo@CApwnLibraries@@QEAAXAEAVCStringArray@@@Z */
  CStringArray::SetSize(param_1,(longlong)*(int *)(this + 0x18),-1);
  iVar2 = 0;
  if (0 < *(int *)(this + 0x18)) {
    lVar1 = 0;
    do {
      if ((((lVar1 < 0) || (*(longlong *)(this + 0x18) <= lVar1)) || (iVar2 < 0)) ||
         (*(longlong *)(param_1 + 0x10) <= (longlong)iVar2)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                 (*(longlong *)(param_1 + 8) + (longlong)iVar2 * 8),
                 *(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> **)
                  (*(longlong *)(this + 0x10) + lVar1 * 8));
      iVar2 = iVar2 + 1;
      lVar1 = lVar1 + 1;
    } while (iVar2 < *(int *)(this + 0x18));
  }
  return;
}

/* ---- FUNC 0000F14F FUN_18000f14f (68 bytes) ---- */

void FUN_18000f14f(void)

{
  ulonglong uVar1;
  longlong unaff_RBP;
  longlong unaff_RSI;
  uint unaff_EDI;
  
  uVar1 = (ulonglong)unaff_EDI;
  while ((-1 < (longlong)uVar1 && ((longlong)uVar1 < *(longlong *)(unaff_RSI + 0x18)))) {
    if (((int)unaff_EDI < 0) || (*(longlong *)(unaff_RBP + 0x10) <= (longlong)(int)unaff_EDI))
    break;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
               (*(longlong *)(unaff_RBP + 8) + (longlong)(int)unaff_EDI * 8),
               *(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> **)
                (*(longlong *)(unaff_RSI + 0x10) + uVar1 * 8));
    unaff_EDI = unaff_EDI + 1;
    uVar1 = uVar1 + 1;
    if (*(int *)(unaff_RSI + 0x18) <= (int)unaff_EDI) {
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 0000F193 FUN_18000f193 (16 bytes) ---- */

void FUN_18000f193(void)

{
  return;
}

/* ---- FUNC 0000F1A3 AfxThrowInvalidArgException (5 bytes) ---- */

void __cdecl AfxThrowInvalidArgException(void)

{
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 0000F1B0 CacheModelTypes (512 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: void __cdecl CApwnLibraries::CacheModelTypes(class ATL::CStringT<char,class
   StrTraitMFC_DLL<char,class ATL::ChTraitsCRT<char> > > const & __ptr64,class
   ATL::CStringT<char,class StrTraitMFC_DLL<char,class ATL::ChTraitsCRT<char> > > const &
   __ptr64,struct IACategory * __ptr64,int) __ptr64 */

void __thiscall
CApwnLibraries::CacheModelTypes
          (CApwnLibraries *this,
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_1,
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_2,IACategory *param_3
          ,int param_4)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar4;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar5;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar6;
  longlong lVar7;
  undefined1 auStackY_f8 [32];
  longlong *local_c8;
  undefined4 local_c0 [2];
  longlong *local_b8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_b0 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_a8 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_a0 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_98 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_90;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_88;
  char *local_78 [4];
  ulonglong local_58;
  
                    /* 0xf1b0  70
                       ?CacheModelTypes@CApwnLibraries@@QEAAXAEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@0PEAUIACategory@@H@Z
                        */
  if (param_3 != (IACategory *)0x0) {
    local_58 = DAT_1800791f8 ^ (ulonglong)auStackY_f8;
    local_78[0] = "Calculator";
    local_78[1] = "Design-Spec";
    local_78[2] = "Measurement";
    local_78[3] = "Transfer";
    local_b8 = (longlong *)0x0;
    iVar2 = (**(code **)(*(longlong *)param_3 + 0x40))(param_3,&local_b8);
    if ((-1 < iVar2) && (local_b8 != (longlong *)0x0)) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_b0);
      local_c0[0] = 0;
      local_c8 = (longlong *)0x0;
      iVar2 = (**(code **)(*local_b8 + 0x18))(local_b8,1,&local_c8,local_c0);
      while (iVar2 == 0) {
        bVar1 = false;
        iVar2 = (**(code **)(*local_c8 + 0x30))();
        if (iVar2 != 0) {
          lVar7 = *local_c8;
          pcVar3 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)local_b0,0x40);
          (**(code **)(lVar7 + 0x18))(local_c8,pcVar3,0x40);
          ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)local_b0,-1);
          lVar7 = 0;
          do {
            iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                    CompareNoCase(local_b0,local_78[lVar7]);
            if (iVar2 == 0) {
              bVar1 = true;
              break;
            }
            lVar7 = lVar7 + 1;
          } while (lVar7 < 4);
          local_90 = local_a8;
          local_88 = local_a0;
          pCVar4 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                   ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                   CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                             (local_a8,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                        *)local_b0);
          pCVar5 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                   ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                   CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                             (local_a0,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                        *)param_2);
          pCVar6 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                   ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                   CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                             (local_98,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                        *)param_1);
          iVar2 = 0;
          if (!bVar1) {
            iVar2 = param_4;
          }
          FUN_18000ebf0((longlong *)(this + 0x90),pCVar6,pCVar5,pCVar4,iVar2);
        }
        (**(code **)(*local_c8 + 0x10))();
        iVar2 = (**(code **)(*local_b8 + 0x18))(local_b8,1,&local_c8,local_c0);
      }
      (**(code **)(*local_b8 + 0x10))();
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_b0);
    }
  }
  return;
}

/* ---- FUNC 0000F3B0 FUN_18000f3b0 (110 bytes) ---- */

undefined8 FUN_18000f3b0(longlong param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  longlong *plVar2;
  
  puVar1 = operator_new(0x40);
  if (puVar1 == (undefined8 *)0x0) {
    plVar2 = (longlong *)0x0;
  }
  else {
    plVar2 = FUN_18000cd80(puVar1,param_1 + 8);
  }
  *param_2 = plVar2;
  if (plVar2 != (longlong *)0x0) {
    (**(code **)(*plVar2 + 8))();
    (**(code **)(*(longlong *)*param_2 + 0x20))
              ((longlong *)*param_2,*(undefined4 *)(param_1 + 0x38));
    return 0;
  }
  return 0x8007000e;
}

/* ---- FUNC 0000F420 FUN_18000f420 (113 bytes) ---- */

undefined8 FUN_18000f420(longlong param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  longlong *plVar2;
  
  puVar1 = operator_new(0x20);
  if (puVar1 == (undefined8 *)0x0) {
    *param_2 = 0;
  }
  else {
    plVar2 = FUN_18000ce50(puVar1,*(longlong *)(param_1 + 8));
    *param_2 = plVar2;
    if (plVar2 != (longlong *)0x0) {
      (**(code **)(*plVar2 + 8))(plVar2);
      (**(code **)(*(longlong *)*param_2 + 0x20))
                ((longlong *)*param_2,*(undefined4 *)(param_1 + 0x14));
      return 0;
    }
  }
  return 0x8007000e;
}

/* ---- FUNC 0000F4A0 CountLibraries (4 bytes) ---- */

/* public: int __cdecl CApwnLibraries::CountLibraries(void) __ptr64 */

int __thiscall CApwnLibraries::CountLibraries(CApwnLibraries *this)

{
                    /* 0xf4a0  75  ?CountLibraries@CApwnLibraries@@QEAAHXZ */
  return *(int *)(this + 0x18);
}

/* ---- FUNC 0000F4B0 FUN_18000f4b0 (57 bytes) ---- */

void FUN_18000f4b0(void)

{
  ulonglong uVar1;
  
  uVar1 = FUN_1800240b0();
  if ((int)uVar1 == 1) {
    if (g_pApwnLibs == (CApwnLibraries *)0x0) {
      g_pApwnLibs = CApwnLibraries::CreateObject();
    }
                    /* WARNING: Could not recover jumptable at 0x00018000f4e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(longlong *)g_pApwnLibs + 8))(g_pApwnLibs);
    return;
  }
  return;
}

/* ---- FUNC 0000F4F0 FUN_18000f4f0 (238 bytes) ---- */

int FUN_18000f4f0(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  HINSTANCE hModule;
  FARPROC pFVar2;
  INT_PTR IVar3;
  longlong *local_res20;
  longlong *local_18 [2];
  
  hModule = CoLoadLibrary(L"apmodlib.dll",0);
  if (hModule != (HINSTANCE)0x0) {
    pFVar2 = GetProcAddress(hModule,"DllGetClassObject");
    if (pFVar2 != (FARPROC)0x0) {
      local_res20 = (longlong *)0x0;
      IVar3 = (*pFVar2)(param_1,&DAT_180057a68,&local_res20);
      if ((-1 < (int)IVar3) && (local_res20 != (longlong *)0x0)) {
        local_18[0] = (longlong *)0x0;
        iVar1 = (**(code **)(*local_res20 + 0x18))(local_res20,0,&DAT_180057a58,local_18);
        if ((-1 < iVar1) && (local_18[0] != (longlong *)0x0)) {
          iVar1 = (**(code **)*local_18[0])(local_18[0],param_2,param_3);
        }
        (**(code **)(*local_res20 + 0x10))();
        if (local_18[0] != (longlong *)0x0) {
          (**(code **)(*local_18[0] + 0x10))();
        }
        return iVar1;
      }
    }
  }
  return -0x7fffbffb;
}

/* ---- FUNC 0000F5E0 CreateObject (45 bytes) ---- */

/* private: static class CApwnLibraries * __ptr64 __cdecl CApwnLibraries::CreateObject(void) */

CApwnLibraries * __cdecl CApwnLibraries::CreateObject(void)

{
  CApwnLibraries *pCVar1;
  
                    /* 0xf5e0  76  ?CreateObject@CApwnLibraries@@CAPEAV1@XZ */
  pCVar1 = operator_new(0xd8);
  if (pCVar1 != (CApwnLibraries *)0x0) {
    pCVar1 = (CApwnLibraries *)CApwnLibraries(pCVar1);
    return pCVar1;
  }
  return (CApwnLibraries *)0x0;
}

/* ---- FUNC 0000F610 DestroyAndRebuildLibraries (600 bytes) ---- */

/* public: int __cdecl CApwnLibraries::DestroyAndRebuildLibraries(void) __ptr64 */

int __thiscall CApwnLibraries::DestroyAndRebuildLibraries(CApwnLibraries *this)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar1;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar2;
  longlong *plVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  longlong lVar7;
  longlong lVar8;
  int iVar9;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res8 [8];
  longlong *local_res10;
  undefined **local_78 [5];
  CStringArray local_50 [40];
  
                    /* 0xf610  77  ?DestroyAndRebuildLibraries@CApwnLibraries@@QEAAHXZ */
  CStringArray::CStringArray(local_50);
  BuildLibraryInfo(this,local_50);
  CPtrArray::CPtrArray((CPtrArray *)local_78);
  local_78[0] = CNameAndStateArray::vftable;
  BuildCategoryInfo(this,(CNameAndStateArray *)local_78);
  UpdateLibCache(this);
  lVar7 = (longlong)(*(int *)(this + 0x18) + -1);
  if (-1 < *(int *)(this + 0x18) + -1) {
    do {
      if (*(longlong *)(this + 0x18) <= lVar7) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      pCVar1 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
                (*(longlong *)(this + 0x10) + lVar7 * 8);
      if (pCVar1 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
        FUN_18000d210(pCVar1);
        operator_delete(pCVar1);
      }
      lVar7 = lVar7 + -1;
    } while (-1 < lVar7);
  }
  CPtrArray::SetSize((CPtrArray *)(this + 8),0,-1);
  FUN_1800138b0((CPtrArray *)(this + 0x30));
  FUN_180013f80((longlong *)(this + 0x90));
  AddStreamCategory(this);
  MergeCategories(this,(CNameAndStateArray *)local_78);
  iVar4 = AddLibraries(this,(CLibraryArray *)(this + 0x58),local_50);
  FUN_180013920((CPtrArray *)(this + 0x30));
  CStringArray::SetSize(&m_InitializedLibraries,0,-1);
  iVar9 = 0;
  iVar5 = CountLibraries(this);
  if (0 < iVar5) {
    lVar7 = 0;
    do {
      if ((lVar7 < 0) || (*(longlong *)(this + 0x18) <= lVar7)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      pCVar2 = *(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> **)
                (*(longlong *)(this + 0x10) + lVar7 * 8);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res8,pCVar2);
      iVar5 = 0;
      lVar8 = 0;
      if (0 < DAT_18007a028) {
        do {
          if ((lVar8 < 0) || (DAT_18007a028 <= lVar8)) {
                    /* WARNING: Subroutine does not return */
            AfxThrowInvalidArgException();
          }
          iVar6 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                            (local_res8,*(char **)(DAT_18007a020 + lVar8 * 8));
          if (iVar6 == 0) goto LAB_18000f801;
          iVar5 = iVar5 + 1;
          lVar8 = lVar8 + 1;
        } while (iVar5 < DAT_18007a028);
      }
      plVar3 = *(longlong **)(pCVar2 + 8);
      local_res10 = plVar3;
      if (plVar3 != (longlong *)0x0) {
        (**(code **)(*plVar3 + 8))(plVar3);
      }
      FUN_180015f90(plVar3);
      CStringArray::SetAtGrow(&m_InitializedLibraries,DAT_18007a028,local_res8);
      if (plVar3 != (longlong *)0x0) {
        (**(code **)(*plVar3 + 0x10))(plVar3);
      }
LAB_18000f801:
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res8);
      iVar9 = iVar9 + 1;
      lVar7 = lVar7 + 1;
      iVar5 = CountLibraries(this);
    } while (iVar9 < iVar5);
  }
  CNameAndStateArray::~CNameAndStateArray((CNameAndStateArray *)local_78);
  CStringArray::~CStringArray(local_50);
  return iVar4;
}

/* ---- FUNC 0000F870 DoSave (55 bytes) ---- */

/* public: int __cdecl CApwnLibraries::DoSave(char * __ptr64 * __ptr64) __ptr64 */

int __thiscall CApwnLibraries::DoSave(CApwnLibraries *this,char **param_1)

{
  int iVar1;
  int *piVar2;
  int local_res10 [6];
  
                    /* 0xf870  79  ?DoSave@CApwnLibraries@@QEAAHPEAPEAD@Z */
  local_res10[0] = 0;
  piVar2 = local_res10;
  if (param_1 != (char **)0x0) {
    piVar2 = (int *)0x0;
  }
  FUN_180016850((longlong *)param_1,2,piVar2);
  iVar1 = SaveV2(this,param_1,piVar2);
  return iVar1;
}

/* ---- FUNC 0000F8B0 EditCategoryList (303 bytes) ---- */

/* public: bool __cdecl CApwnLibraries::EditCategoryList(struct HWND__ * __ptr64) __ptr64 */

bool __thiscall CApwnLibraries::EditCategoryList(CApwnLibraries *this,HWND__ *param_1)

{
  __int64 _Var1;
  undefined **local_528 [5];
  undefined **local_500 [5];
  CStringArray local_4d8 [48];
  CDialog local_4a8 [304];
  CListBox local_378 [240];
  CButton local_288 [296];
  CButton local_160 [296];
  CNameAndStateArray local_38 [48];
  
                    /* 0xf8b0  81  ?EditCategoryList@CApwnLibraries@@QEAA_NPEAUHWND__@@@Z */
  CPtrArray::CPtrArray((CPtrArray *)local_500);
  local_500[0] = CNameAndStateArray::vftable;
  BuildCategoryInfo(this,(CNameAndStateArray *)local_500);
  FUN_180022a00(local_4a8,(CWnd *)0x0);
  FUN_180023610((longlong)local_4a8,(longlong)local_500);
  _Var1 = CDialog::DoModal(local_4a8);
  if (_Var1 == 1) {
    CPtrArray::CPtrArray((CPtrArray *)local_528);
    local_528[0] = CNameAndStateArray::vftable;
    FUN_180022cd0((longlong)local_4a8,(CPtrArray *)local_528);
    CStringArray::CStringArray(local_4d8);
    BuildLibraryInfo(this,local_4d8);
    ReconcileLibs(this,local_4d8,(CNameAndStateArray *)local_528);
    CStringArray::~CStringArray(local_4d8);
    CNameAndStateArray::~CNameAndStateArray((CNameAndStateArray *)local_528);
  }
  CNameAndStateArray::~CNameAndStateArray(local_38);
  FUN_18000d3f0(local_160);
  FUN_18000d3f0(local_288);
  CListBox::~CListBox(local_378);
  CDialog::~CDialog(local_4a8);
  CNameAndStateArray::~CNameAndStateArray((CNameAndStateArray *)local_500);
  return _Var1 == 1;
}

/* ---- FUNC 0000F9E0 EditLibraryList (312 bytes) ---- */

/* public: bool __cdecl CApwnLibraries::EditLibraryList(struct HWND__ * __ptr64) __ptr64 */

bool __thiscall CApwnLibraries::EditLibraryList(CApwnLibraries *this,HWND__ *param_1)

{
  uint uVar1;
  __int64 _Var2;
  bool bVar3;
  undefined **local_528 [5];
  CStringArray local_500 [40];
  CStringArray local_4d8 [48];
  CDialog local_4a8 [304];
  CListBox local_378 [240];
  CButton local_288 [296];
  CButton local_160 [296];
  CStringArray local_38 [48];
  
                    /* 0xf9e0  82  ?EditLibraryList@CApwnLibraries@@QEAA_NPEAUHWND__@@@Z */
  CPtrArray::CPtrArray((CPtrArray *)local_528);
  local_528[0] = CNameAndStateArray::vftable;
  BuildCategoryInfo(this,(CNameAndStateArray *)local_528);
  CStringArray::CStringArray(local_4d8);
  BuildLibraryInfo(this,local_4d8);
  FUN_180025bf0(local_4a8,(CWnd *)0x0);
  FUN_180026990((longlong)local_4a8,(longlong)local_4d8);
  _Var2 = CDialog::DoModal(local_4a8);
  if (_Var2 == 1) {
    CStringArray::CStringArray(local_500);
    FUN_180025d60((longlong)local_4a8,local_500);
    uVar1 = ReconcileLibs(this,local_500,(CNameAndStateArray *)local_528);
    if ((uVar1 & 0x10) != 0) {
      MMAfxMessageBox("One or More User Model Libraries Referenced Is Locked and\nCould Not Be Opened. Another Instance of Aspen Plus May Currently\nHave this Library Open for Writing."
                      ,0,-1,0);
    }
    CStringArray::~CStringArray(local_500);
    bVar3 = true;
  }
  else {
    bVar3 = false;
  }
  CStringArray::~CStringArray(local_38);
  FUN_18000d3f0(local_160);
  FUN_18000d3f0(local_288);
  CListBox::~CListBox(local_378);
  CDialog::~CDialog(local_4a8);
  CStringArray::~CStringArray(local_4d8);
  CNameAndStateArray::~CNameAndStateArray((CNameAndStateArray *)local_528);
  return bVar3;
}

/* ---- FUNC 0000FB20 EnumCategories (121 bytes) ---- */

/* public: virtual long __cdecl CApwnLibraries::EnumCategories(struct IEnumACategory * __ptr64 *
   __ptr64) __ptr64 */

long __thiscall CApwnLibraries::EnumCategories(CApwnLibraries *this,IEnumACategory **param_1)

{
  long lVar1;
  undefined8 *puVar2;
  
                    /* 0xfb20  84  ?EnumCategories@CApwnLibraries@@UEAAJPEAPEAUIEnumACategory@@@Z */
  if (param_1 == (IEnumACategory **)0x0) {
    return -0x7ff8ffa9;
  }
  *param_1 = (IEnumACategory *)0x0;
  puVar2 = operator_new(0x40);
  if (puVar2 != (undefined8 *)0x0) {
    puVar2 = FUN_18000cd80(puVar2,(longlong)(this + 0x30));
    if (puVar2 != (undefined8 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00018000fb86. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      lVar1 = (**(code **)*puVar2)(puVar2,&DAT_180056220,param_1);
      return lVar1;
    }
  }
  return -0x7ff8fff2;
}

/* ---- FUNC 0000FBA0 FUN_18000fba0 (121 bytes) ---- */

undefined8 FUN_18000fba0(longlong param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  if (param_2 == (undefined8 *)0x0) {
    return 0x80070057;
  }
  *param_2 = 0;
  puVar1 = operator_new(0x20);
  if (puVar1 != (undefined8 *)0x0) {
    puVar1 = FUN_18000ce50(puVar1,param_1 + 0x18);
    if (puVar1 != (undefined8 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00018000fc06. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (**(code **)*puVar1)(puVar1,&DAT_1800561d0,param_2);
      return uVar2;
    }
  }
  return 0x8007000e;
}

/* ---- FUNC 0000FC20 EnumModelTypes (12 bytes) ---- */

/* public: __int64 __cdecl CApwnLibraries::EnumModelTypes(__int64 * __ptr64) __ptr64 */

__int64 __thiscall CApwnLibraries::EnumModelTypes(CApwnLibraries *this,__int64 *param_1)

{
  longlong lVar1;
  
                    /* 0xfc20  85  ?EnumModelTypes@CApwnLibraries@@QEAA_JPEA_J@Z */
  lVar1 = FUN_18000fc30((longlong *)(this + 0x90),param_1);
  return lVar1;
}

/* ---- FUNC 0000FC30 FUN_18000fc30 (35 bytes) ---- */

longlong FUN_18000fc30(longlong *param_1,longlong *param_2)

{
  uint uVar1;
  ulonglong uVar2;
  bool bVar3;
  int iVar4;
  longlong lVar5;
  uint *puVar6;
  uint *puVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  uint *puVar10;
  longlong lVar11;
  
  if (param_2 != (longlong *)0x0) {
    lVar11 = *param_2;
    if (-1 < lVar11) {
      puVar7 = (uint *)param_1[3];
      if (lVar11 != 0) {
        puVar7 = puVar7 + lVar11 + -1;
      }
      puVar10 = (uint *)param_1[4];
      if (puVar7 < puVar10) {
        do {
          lVar11 = (longlong)(int)*puVar7 * 0x20 + *param_1;
          uVar9 = (longlong)puVar10 - (longlong)puVar7 >> 2;
joined_r0x00018000fcbf:
          do {
            uVar2 = uVar9;
            if ((longlong)uVar2 < 1) goto LAB_18000febc;
            uVar9 = uVar2 >> 1;
            puVar10 = puVar7 + uVar9;
            uVar1 = *puVar10;
            if (uVar1 != 0xffffffff) {
              lVar5 = (longlong)(int)uVar1 * 0x20 + *param_1;
              if (lVar5 == param_1[1]) {
                bVar3 = (int)uVar1 < -1;
              }
              else {
                iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                   (lVar5 + 0x10),*(char **)(lVar11 + 0x10));
                bVar3 = SUB41((uint)iVar4 >> 0x1f,0);
              }
              if (bVar3 != false) {
                puVar7 = puVar10 + 1;
                uVar9 = uVar2 + (-1 - uVar9);
                goto joined_r0x00018000fcbf;
              }
            }
            uVar1 = *puVar10;
            if (uVar1 == 0xffffffff) break;
            lVar5 = (longlong)(int)uVar1 * 0x20 + *param_1;
            if (lVar5 == param_1[1]) {
              bVar3 = uVar1 < 0x80000000;
            }
            else {
              iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                 (lVar11 + 0x10),*(char **)(lVar5 + 0x10));
              bVar3 = SUB41((uint)iVar4 >> 0x1f,0);
            }
          } while (bVar3 != false);
          puVar6 = puVar7;
          if (uVar9 != 0) {
            do {
              uVar8 = uVar9 >> 1;
              uVar1 = puVar6[uVar8];
              if (uVar1 != 0xffffffff) {
                lVar5 = (longlong)(int)uVar1 * 0x20 + *param_1;
                if (lVar5 == param_1[1]) {
                  bVar3 = (int)uVar1 < -1;
                }
                else {
                  iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                          Compare((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                  (lVar5 + 0x10),*(char **)(lVar11 + 0x10));
                  bVar3 = SUB41((uint)iVar4 >> 0x1f,0);
                }
                if (bVar3 != false) {
                  puVar6 = puVar6 + uVar8 + 1;
                  uVar8 = uVar9 + (-1 - uVar8);
                }
              }
              uVar9 = uVar8;
            } while (0 < (longlong)uVar8);
          }
          puVar10 = puVar10 + 1;
          uVar9 = (longlong)((uVar2 * 4 - (longlong)puVar10) + (longlong)puVar7) >> 2;
joined_r0x00018000fe23:
          uVar2 = uVar9;
          if (0 < (longlong)uVar2) {
            uVar9 = uVar2 >> 1;
            uVar1 = puVar10[uVar9];
            if (uVar1 != 0xffffffff) goto code_r0x00018000fe43;
            goto LAB_18000fe75;
          }
          puVar7 = puVar6;
          if (puVar6 != puVar10) {
            do {
              if (*(int *)((longlong)(int)*puVar6 * 0x20 + 0x18 + *param_1) != 0) {
                *param_2 = ((longlong)puVar10 - param_1[3] >> 2) + 1;
                return (longlong)(int)*puVar6;
              }
              puVar6 = puVar6 + 1;
              puVar7 = puVar6;
            } while (puVar6 != puVar10);
          }
LAB_18000febc:
          puVar10 = (uint *)param_1[4];
        } while (puVar7 < puVar10);
      }
      *param_2 = -1;
      return -1;
    }
  }
  return -1;
code_r0x00018000fe43:
  lVar5 = (longlong)(int)uVar1 * 0x20 + *param_1;
  if (lVar5 == param_1[1]) {
    bVar3 = uVar1 < 0x80000000;
  }
  else {
    iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                       (lVar11 + 0x10),*(char **)(lVar5 + 0x10));
    bVar3 = SUB41((uint)iVar4 >> 0x1f,0);
  }
  if (bVar3 == false) {
LAB_18000fe75:
    puVar10 = puVar10 + uVar9 + 1;
    uVar9 = uVar2 + (-1 - uVar9);
  }
  goto joined_r0x00018000fe23;
}

/* ---- FUNC 0000FC53 FUN_18000fc53 (691 bytes) ---- */

longlong FUN_18000fc53(longlong param_1)

{
  uint uVar1;
  ulonglong uVar2;
  bool bVar3;
  int iVar4;
  longlong in_RAX;
  longlong lVar5;
  longlong lVar6;
  uint *puVar7;
  uint *puVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  uint *puVar11;
  longlong *unaff_R14;
  bool in_ZF;
  longlong *in_stack_00000078;
  longlong lStack0000000000000080;
  
  puVar8 = *(uint **)(param_1 + 0x18);
  if (!in_ZF) {
    puVar8 = puVar8 + in_RAX + -1;
  }
  puVar11 = *(uint **)(param_1 + 0x20);
  if (puVar8 < puVar11) {
    do {
      lStack0000000000000080 = (longlong)(int)*puVar8 * 0x20 + *unaff_R14;
      uVar10 = (longlong)puVar11 - (longlong)puVar8 >> 2;
joined_r0x00018000fcbf:
      do {
        uVar2 = uVar10;
        if ((longlong)uVar2 < 1) goto LAB_18000febc;
        uVar10 = uVar2 >> 1;
        puVar11 = puVar8 + uVar10;
        uVar1 = *puVar11;
        if (uVar1 != 0xffffffff) {
          lVar5 = (longlong)(int)uVar1 * 0x20 + *unaff_R14;
          if (lVar5 == unaff_R14[1]) {
            bVar3 = (int)uVar1 < -1;
          }
          else {
            iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                               (lVar5 + 0x10),*(char **)(lStack0000000000000080 + 0x10));
            bVar3 = SUB41((uint)iVar4 >> 0x1f,0);
          }
          if (bVar3 != false) {
            puVar8 = puVar11 + 1;
            uVar10 = uVar2 + (-1 - uVar10);
            goto joined_r0x00018000fcbf;
          }
        }
        uVar1 = *puVar11;
        if (uVar1 == 0xffffffff) break;
        lVar5 = (longlong)(int)uVar1 * 0x20 + *unaff_R14;
        if (lVar5 == unaff_R14[1]) {
          bVar3 = uVar1 < 0x80000000;
        }
        else {
          iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             (lStack0000000000000080 + 0x10),*(char **)(lVar5 + 0x10));
          bVar3 = SUB41((uint)iVar4 >> 0x1f,0);
        }
      } while (bVar3 != false);
      lVar5 = lStack0000000000000080;
      puVar7 = puVar8;
      if (uVar10 != 0) {
        do {
          uVar9 = uVar10 >> 1;
          uVar1 = puVar7[uVar9];
          if (uVar1 != 0xffffffff) {
            lVar6 = (longlong)(int)uVar1 * 0x20 + *unaff_R14;
            if (lVar6 == unaff_R14[1]) {
              bVar3 = (int)uVar1 < -1;
            }
            else {
              iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                 (lVar6 + 0x10),*(char **)(lVar5 + 0x10));
              bVar3 = SUB41((uint)iVar4 >> 0x1f,0);
            }
            if (bVar3 != false) {
              puVar7 = puVar7 + uVar9 + 1;
              uVar9 = uVar10 + (-1 - uVar9);
            }
          }
          uVar10 = uVar9;
        } while (0 < (longlong)uVar9);
      }
      lVar5 = lStack0000000000000080;
      puVar11 = puVar11 + 1;
      uVar10 = (longlong)((uVar2 * 4 - (longlong)puVar11) + (longlong)puVar8) >> 2;
joined_r0x00018000fe23:
      uVar2 = uVar10;
      if (0 < (longlong)uVar2) {
        uVar10 = uVar2 >> 1;
        uVar1 = puVar11[uVar10];
        if (uVar1 != 0xffffffff) goto code_r0x00018000fe43;
        goto LAB_18000fe75;
      }
      puVar8 = puVar7;
      if (puVar7 != puVar11) {
        do {
          if (*(int *)((longlong)(int)*puVar7 * 0x20 + 0x18 + *unaff_R14) != 0) {
            *in_stack_00000078 = ((longlong)puVar11 - unaff_R14[3] >> 2) + 1;
            return (longlong)(int)*puVar7;
          }
          puVar7 = puVar7 + 1;
          puVar8 = puVar7;
        } while (puVar7 != puVar11);
      }
LAB_18000febc:
      puVar11 = (uint *)unaff_R14[4];
    } while (puVar8 < puVar11);
  }
  *in_stack_00000078 = -1;
  return -1;
code_r0x00018000fe43:
  lVar6 = (longlong)(int)uVar1 * 0x20 + *unaff_R14;
  if (lVar6 == unaff_R14[1]) {
    bVar3 = uVar1 < 0x80000000;
  }
  else {
    iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                       (lVar5 + 0x10),*(char **)(lVar6 + 0x10));
    bVar3 = SUB41((uint)iVar4 >> 0x1f,0);
  }
  if (bVar3 == false) {
LAB_18000fe75:
    puVar11 = puVar11 + uVar10 + 1;
    uVar10 = uVar2 + (-1 - uVar10);
  }
  goto joined_r0x00018000fe23;
}

/* ---- FUNC 0000FF06 FUN_18000ff06 (24 bytes) ---- */

longlong FUN_18000ff06(void)

{
  int *unaff_RBX;
  longlong unaff_RSI;
  longlong unaff_R14;
  longlong *in_stack_00000078;
  
  *in_stack_00000078 = (unaff_RSI - *(longlong *)(unaff_R14 + 0x18) >> 2) + 1;
  return (longlong)*unaff_RBX;
}

/* ---- FUNC 0000FF1E FUN_18000ff1e (14 bytes) ---- */

undefined8 FUN_18000ff1e(void)

{
  return 0xffffffffffffffff;
}

/* ---- FUNC 0000FF30 FindAPMFileAndRegisterLibrary (581 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: int __cdecl CApwnLibraries::FindAPMFileAndRegisterLibrary(char const * __ptr64) __ptr64
    */

int __thiscall CApwnLibraries::FindAPMFileAndRegisterLibrary(CApwnLibraries *this,char *param_1)

{
  int iVar1;
  longlong lVar2;
  longlong *plVar3;
  ulonglong uVar4;
  uint uVar5;
  undefined1 auStack_1c8 [32];
  longlong *local_1a8;
  char *local_1a0;
  char *local_198 [2];
  char local_188 [80];
  CHAR local_138 [272];
  ulonglong local_28;
  ulonglong uVar6;
  
                    /* 0xff30  87  ?FindAPMFileAndRegisterLibrary@CApwnLibraries@@QEAAHPEBD@Z */
  local_28 = DAT_1800791f8 ^ (ulonglong)auStack_1c8;
  if (param_1 != (char *)0x0) {
    UpdateAPMfilesInTheCurrentDirectory(this);
    iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                      (&m_acmcatalog,param_1);
    if ((((iVar1 != 0) &&
         (iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                            (&m_builtin,param_1), iVar1 != 0)) &&
        (iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                           (&m_capeopen,param_1), iVar1 != 0)) &&
       ((iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                           (&m_acmbuiltin,param_1), iVar1 != 0 &&
        (iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                           (&m_HybridModelLib,param_1), iVar1 != 0)))) {
      uVar4 = 0;
      local_1a8 = (longlong *)0x0;
      iVar1 = FUN_18000f4f0(&DAT_1800562a0,&DAT_180056270,&local_1a8);
      if (iVar1 < 0) {
        return 1;
      }
      lVar2 = *(longlong *)(this + 0xc0);
      uVar6 = uVar4;
      if (*(longlong *)(this + 200) - lVar2 >> 5 != 0) {
        do {
          plVar3 = (longlong *)(uVar4 + lVar2);
          if (0xf < (ulonglong)plVar3[3]) {
            plVar3 = (longlong *)*plVar3;
          }
          iVar1 = (**(code **)(*local_1a8 + 0x18))(local_1a8,1,plVar3);
          if (-1 < iVar1) {
            (**(code **)(*local_1a8 + 0x38))(local_1a8,local_188,0x50);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1a0,
                       local_188);
            iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                    CompareNoCase((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                  &local_1a0,param_1);
            if (iVar1 == 0) {
              GetCurrentDirectoryA(0x104,local_138);
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_198)
              ;
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_198,
                         "%s\\%s");
              APModLibRegisterLib(local_1a0,local_198[0],0,0);
              (**(code **)(*local_1a8 + 0x28))();
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_198)
              ;
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1a0
                        );
              break;
            }
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1a0);
          }
          (**(code **)(*local_1a8 + 0x28))();
          uVar5 = (int)uVar6 + 1;
          uVar6 = (ulonglong)uVar5;
          uVar4 = uVar4 + 0x20;
          lVar2 = *(longlong *)(this + 0xc0);
        } while ((ulonglong)(longlong)(int)uVar5 <
                 (ulonglong)(*(longlong *)(this + 200) - lVar2 >> 5));
      }
      (**(code **)(*local_1a8 + 0x10))();
    }
  }
  return 0;
}

/* ---- FUNC 00010180 FindApwnLibrary (9 bytes) ---- */

/* public: int __cdecl CApwnLibraries::FindApwnLibrary(char const * __ptr64) __ptr64 */

int __thiscall CApwnLibraries::FindApwnLibrary(CApwnLibraries *this,char *param_1)

{
  int iVar1;
  
                    /* 0x10180  88  ?FindApwnLibrary@CApwnLibraries@@QEAAHPEBD@Z */
  iVar1 = FUN_180010330((longlong)(this + 8),param_1);
  return iVar1;
}

/* ---- FUNC 00010190 FindCategory (31 bytes) ---- */

/* public: virtual long __cdecl CApwnLibraries::FindCategory(char const * __ptr64,struct IACategory
   * __ptr64 * __ptr64) __ptr64 */

long __thiscall
CApwnLibraries::FindCategory(CApwnLibraries *this,char *param_1,IACategory **param_2)

{
  undefined8 *puVar1;
  int iVar2;
  long lVar3;
  ulonglong uVar4;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res10 [8];
  
                    /* 0x10190  89  ?FindCategory@CApwnLibraries@@UEAAJPEBDPEAPEAUIACategory@@@Z */
  if ((param_1 == (char *)0x0) || (param_2 == (IACategory **)0x0)) {
    return -0x7ff8ffa9;
  }
  *param_2 = (IACategory *)0x0;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res10,param_1);
  uVar4 = FUN_180010240((longlong)(this + 0x30),(undefined8 *)local_res10);
  iVar2 = (int)uVar4;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res10);
  if (iVar2 < 0) {
    return -0x7fffbffb;
  }
  if ((longlong)iVar2 < *(longlong *)(this + 0x40)) {
    puVar1 = *(undefined8 **)(*(longlong *)(this + 0x38) + (longlong)iVar2 * 8);
                    /* WARNING: Could not recover jumptable at 0x00018001020b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    lVar3 = (**(code **)*puVar1)(puVar1,&DAT_180056210,param_2);
    return lVar3;
  }
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 000101AF FUN_1800101af (95 bytes) ---- */

undefined8
FUN_1800101af(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_1,char *param_2,
             undefined8 *param_3)

{
  undefined8 *puVar1;
  int iVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  longlong unaff_RDI;
  
  *param_3 = 0;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1,param_2);
  uVar3 = FUN_180010240(unaff_RDI + 0x30,(undefined8 *)&stack0x00000038);
  iVar2 = (int)uVar3;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&stack0x00000038);
  if (iVar2 < 0) {
    return 0x80004005;
  }
  if ((longlong)iVar2 < *(longlong *)(unaff_RDI + 0x40)) {
    puVar1 = *(undefined8 **)(*(longlong *)(unaff_RDI + 0x38) + (longlong)iVar2 * 8);
                    /* WARNING: Could not recover jumptable at 0x00018001020b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar4 = (**(code **)*puVar1)(puVar1,&DAT_180056210);
    return uVar4;
  }
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 0001020E FUN_18001020e (21 bytes) ---- */

undefined8 FUN_18001020e(void)

{
  return 0x80004005;
}

/* ---- FUNC 00010223 FUN_180010223 (16 bytes) ---- */

undefined8 FUN_180010223(void)

{
  return 0x80070057;
}

/* ---- FUNC 00010233 AfxThrowInvalidArgException (5 bytes) ---- */

void __cdecl AfxThrowInvalidArgException(void)

{
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 00010240 FUN_180010240 (239 bytes) ---- */

ulonglong FUN_180010240(longlong param_1,undefined8 *param_2)

{
  longlong *plVar1;
  longlong lVar2;
  int iVar3;
  char *pcVar4;
  ulonglong uVar5;
  uint uVar6;
  ulonglong uVar7;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res8 [8];
  
  uVar5 = 0;
  uVar7 = uVar5;
  if (0 < *(longlong *)(param_1 + 0x10)) {
    do {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res8);
      if (((longlong)uVar5 < 0) || (*(longlong *)(param_1 + 0x10) <= (longlong)uVar5)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      plVar1 = *(longlong **)(*(longlong *)(param_1 + 8) + uVar5 * 8);
      if (plVar1 != (longlong *)0x0) {
        lVar2 = *plVar1;
        pcVar4 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)local_res8,0x40);
        (**(code **)(lVar2 + 0x18))(plVar1,pcVar4,0x40);
        ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)local_res8,-1);
        iVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                          (local_res8,(char *)*param_2);
        if (iVar3 == 0) {
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res8);
          return uVar7;
        }
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res8);
      uVar6 = (int)uVar7 + 1;
      uVar5 = uVar5 + 1;
      uVar7 = (ulonglong)uVar6;
    } while ((longlong)(int)uVar6 < *(longlong *)(param_1 + 0x10));
  }
  return 0xffffffff;
}

/* ---- FUNC 00010330 FUN_180010330 (158 bytes) ---- */

int FUN_180010330(longlong param_1,char *param_2)

{
  int iVar1;
  longlong lVar2;
  int iVar3;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res8 [8];
  
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x10)) {
    lVar2 = 0;
    do {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res8);
      if ((lVar2 < 0) || (*(longlong *)(param_1 + 0x10) <= lVar2)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                (local_res8,
                 *(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> **)
                  (*(longlong *)(param_1 + 8) + lVar2 * 8));
      iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                        (local_res8,param_2);
      if (iVar1 == 0) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res8);
        return iVar3;
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res8);
      iVar3 = iVar3 + 1;
      lVar2 = lVar2 + 1;
    } while (iVar3 < *(int *)(param_1 + 0x10));
  }
  return -1;
}

/* ---- FUNC 000103D0 FindModelType (12 bytes) ---- */

/* public: __int64 __cdecl CApwnLibraries::FindModelType(char const * __ptr64) __ptr64 */

__int64 __thiscall CApwnLibraries::FindModelType(CApwnLibraries *this,char *param_1)

{
  longlong lVar1;
  
                    /* 0x103d0  90  ?FindModelType@CApwnLibraries@@QEAA_JPEBD@Z */
  lVar1 = FUN_180010600((longlong *)(this + 0x90),param_1);
  return lVar1;
}

/* ---- FUNC 000103E0 FUN_1800103e0 (290 bytes) ---- */

ulonglong FUN_1800103e0(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  longlong *plVar2;
  int iVar3;
  char *pcVar4;
  ulonglong uVar5;
  uint uVar6;
  ulonglong uVar7;
  char *local_res8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res10 [8];
  
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res10);
  lVar1 = *param_2;
  pcVar4 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)local_res10,0x40);
  (**(code **)(lVar1 + 0x18))(param_2,pcVar4,0x40);
  ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)local_res10,-1);
  uVar5 = 0;
  uVar7 = uVar5;
  if (0 < *(longlong *)(param_1 + 0x10)) {
    do {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8);
      if (((longlong)uVar5 < 0) || (*(longlong *)(param_1 + 0x10) <= (longlong)uVar5)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      plVar2 = *(longlong **)(*(longlong *)(param_1 + 8) + uVar5 * 8);
      lVar1 = *plVar2;
      pcVar4 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)&local_res8,0x40);
      (**(code **)(lVar1 + 0x18))(plVar2,pcVar4,0x40);
      ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)&local_res8,-1);
      iVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                        (local_res10,local_res8);
      if (iVar3 == 0) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8);
        goto LAB_1800104d4;
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8);
      uVar6 = (int)uVar7 + 1;
      uVar5 = uVar5 + 1;
      uVar7 = (ulonglong)uVar6;
    } while ((longlong)(int)uVar6 < *(longlong *)(param_1 + 0x10));
  }
  uVar7 = 0xffffffff;
LAB_1800104d4:
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res10);
  return uVar7;
}

/* ---- FUNC 00010510 FUN_180010510 (230 bytes) ---- */

ulonglong FUN_180010510(longlong param_1,char *param_2)

{
  longlong *plVar1;
  longlong lVar2;
  int iVar3;
  char *pcVar4;
  ulonglong uVar5;
  uint uVar6;
  ulonglong uVar7;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res8 [8];
  
  uVar5 = 0;
  uVar7 = uVar5;
  if (0 < *(longlong *)(param_1 + 0x10)) {
    do {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res8);
      if (((longlong)uVar5 < 0) || (*(longlong *)(param_1 + 0x10) <= (longlong)uVar5)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      plVar1 = *(longlong **)(*(longlong *)(param_1 + 8) + uVar5 * 8);
      lVar2 = *plVar1;
      pcVar4 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)local_res8,0x40);
      (**(code **)(lVar2 + 0x18))(plVar1,pcVar4,0x40);
      ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)local_res8,-1);
      iVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                        (local_res8,param_2);
      if (iVar3 == 0) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res8);
        return uVar7;
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res8);
      uVar6 = (int)uVar7 + 1;
      uVar5 = uVar5 + 1;
      uVar7 = (ulonglong)uVar6;
    } while ((longlong)(int)uVar6 < *(longlong *)(param_1 + 0x10));
  }
  return 0xffffffff;
}

/* ---- FUNC 00010600 FUN_180010600 (1320 bytes) ---- */

longlong FUN_180010600(longlong *param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar4;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar5;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar6;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar7;
  longlong *plVar8;
  int *piVar9;
  int *piVar10;
  undefined8 *puVar11;
  longlong lVar12;
  uint uVar13;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_res18;
  longlong local_res20;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_a8 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_a0 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_98 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_90 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_88;
  longlong *local_80;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_78 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_70 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_68 [8];
  undefined4 local_60;
  longlong local_58;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_50 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_48 [2];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_38;
  
  lVar12 = -1;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_a8,param_2);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_50);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_58);
  iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Find(local_a8,'\t',0);
  local_80 = param_1;
  if (iVar2 == -1) {
    local_res18 = local_a0;
    local_88 = local_90;
    pCVar5 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                       (local_a0,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                  *)local_a8);
    local_48[0] = pCVar5;
    pCVar6 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_90,"");
    local_38 = pCVar6;
    pCVar7 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_98,"");
    local_res18 = pCVar7;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              (local_78,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *
                        )pCVar7);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              (local_70,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *
                        )pCVar6);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              (local_68,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *
                        )pCVar5);
    local_60 = 1;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar7);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar6);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar5);
    local_res18 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                  CONCAT44(local_res18._4_4_,0xffffffff);
    local_88 = local_78;
    plVar8 = FUN_18000c430((longlong *)local_48,(int *)param_1[3],param_1[4],(int *)&local_res18,
                           (longlong *)&local_88);
    piVar9 = (int *)*plVar8;
    piVar10 = (int *)plVar8[1];
  }
  else {
    pCVar4 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                       (local_a8,(int)&local_res18);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(local_50,pCVar4);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res18);
    pCVar4 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Mid
                       (local_a8,(int)&local_res18,iVar2 + 1);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20,pCVar4)
    ;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res18);
    iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Find
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20
                       ,'\t',0);
    if (iVar2 == -1) {
      cVar1 = ATL::CSimpleStringT<char,1>::operator[]((CSimpleStringT<char,1> *)&local_res20,0);
      if (cVar1 == '(') {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Delete
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20,0,1
                  );
      }
      iVar2 = *(int *)(local_res20 + -0x10);
      cVar1 = ATL::CSimpleStringT<char,1>::operator[]
                        ((CSimpleStringT<char,1> *)&local_res20,iVar2 + -1);
      if (cVar1 == ')') {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Delete
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20,
                   iVar2 + -1,1);
      }
      local_res18 = local_a0;
      local_88 = local_90;
      pCVar5 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
               ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
               CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                         (local_a0,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                    *)local_50);
      local_48[0] = pCVar5;
      pCVar6 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
               ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
               CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                         (local_90,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                    *)&local_res20);
      local_38 = pCVar6;
      pCVar7 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
               ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
               CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_98,"");
      local_res18 = pCVar7;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                (local_78,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                           *)pCVar7);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                (local_70,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                           *)pCVar6);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                (local_68,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                           *)pCVar5);
      local_60 = 1;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar7);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar6);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar5);
      local_res18 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                    CONCAT44(local_res18._4_4_,0xffffffff);
      local_88 = local_78;
      plVar8 = FUN_18000c690((longlong *)local_48,(int *)param_1[3],param_1[4],(int *)&local_res18,
                             (longlong *)&local_88);
      piVar9 = (int *)*plVar8;
      piVar10 = (int *)plVar8[1];
    }
    else {
      pCVar4 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Mid
                         ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                          &local_res20,(int)&local_res18);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_58,pCVar4);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res18);
      cVar1 = ATL::CSimpleStringT<char,1>::operator[]((CSimpleStringT<char,1> *)&local_res20,0);
      if (cVar1 == '(') {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Delete
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20,0,1
                  );
      }
      pCVar4 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                         ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                          &local_res20,(int)&local_res18);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20,
                 pCVar4);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res18);
      iVar2 = *(int *)(local_res20 + -0x10);
      if ((0 < iVar2) &&
         (cVar1 = ATL::CSimpleStringT<char,1>::operator[]
                            ((CSimpleStringT<char,1> *)&local_res20,iVar2 + -1), cVar1 == ')')) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Delete
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20,
                   iVar2 + -1,1);
      }
      local_res18 = local_98;
      local_38 = local_90;
      pCVar5 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
               ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
               CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                         (local_98,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                    *)local_50);
      local_48[0] = pCVar5;
      pCVar6 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
               ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
               CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                         (local_90,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                    *)&local_res20);
      local_88 = pCVar6;
      pCVar7 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
               ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
               CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_a0,"");
      local_res18 = pCVar7;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                (local_78,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                           *)pCVar7);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                (local_70,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                           *)pCVar6);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                (local_68,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                           *)pCVar5);
      local_60 = 1;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar7);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar6);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar5);
      local_res18 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                    CONCAT44(local_res18._4_4_,0xffffffff);
      local_88 = local_78;
      plVar8 = FUN_18000c430((longlong *)local_48,(int *)param_1[3],param_1[4],(int *)&local_res18,
                             (longlong *)&local_88);
      piVar9 = (int *)*plVar8;
      piVar10 = (int *)plVar8[1];
    }
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_68);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_70);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_78);
  uVar13 = 0xffffffff;
  for (; piVar9 != piVar10; piVar9 = piVar9 + 1) {
    puVar11 = (undefined8 *)((longlong)*piVar9 * 0x20 + *param_1);
    if ((puVar11 != (undefined8 *)param_1[1]) &&
       (((*(int *)(local_58 + -0x10) == 0 ||
         (iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &local_58,(char *)*puVar11), iVar2 == 0)) &&
        (uVar3 = CApwnLibraries::FindApwnLibrary(g_pApwnLibs,(char *)*puVar11), uVar3 < uVar13)))) {
      lVar12 = (longlong)*piVar9;
      uVar13 = uVar3;
    }
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_58);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_50);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_a8);
  return lVar12;
}

/* ---- FUNC 00010B30 FUN_180010b30 (122 bytes) ---- */

undefined8 FUN_180010b30(longlong param_1,char *param_2,undefined8 *param_3)

{
  longlong *plVar1;
  int iVar2;
  ulonglong uVar3;
  
  if ((param_2 == (char *)0x0) || (param_3 == (undefined8 *)0x0)) {
    return 0x80070057;
  }
  *param_3 = 0;
  uVar3 = FUN_180010510(param_1 + 0x18,param_2);
  iVar2 = (int)uVar3;
  if (iVar2 < 0) {
    return 0x80004005;
  }
  if ((longlong)iVar2 < *(longlong *)(param_1 + 0x28)) {
    plVar1 = *(longlong **)(*(longlong *)(param_1 + 0x20) + (longlong)iVar2 * 8);
    *param_3 = plVar1;
    (**(code **)(*plVar1 + 8))();
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 00010BB0 FUN_180010bb0 (51 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_180010bb0(void)

{
  char cVar1;
  undefined4 uVar2;
  INT_PTR IVar3;
  char *pcVar4;
  undefined2 *puVar5;
  undefined *puVar6;
  longlong lVar7;
  char *pcVar8;
  
  if (DAT_18007a160 == '\0') {
    _DAT_18007a171 = s_Software_AspenTech__180053ee0._17_2_;
    DAT_18007a173 = s_Software_AspenTech__180053ee0[0x13];
    DAT_18007a160 = 'S';
    _DAT_18007a161 = s_Software_AspenTech__180053ee0._1_8_;
    ram0x00018007a169 = s_Software_AspenTech__180053ee0._9_8_;
    IVar3 = FUN_180024130();
    puVar6 = &DAT_18007a15f;
    do {
      pcVar4 = puVar6 + 1;
      puVar6 = puVar6 + 1;
    } while (*pcVar4 != '\0');
    lVar7 = 0;
    do {
      cVar1 = *(char *)(IVar3 + lVar7);
      puVar6[lVar7] = cVar1;
      lVar7 = lVar7 + 1;
    } while (cVar1 != '\0');
    puVar5 = (undefined2 *)&DAT_18007a15f;
    do {
      pcVar4 = (char *)((longlong)puVar5 + 1);
      puVar5 = (undefined2 *)((longlong)puVar5 + 1);
    } while (*pcVar4 != '\0');
    *puVar5 = DAT_180053ef4;
    IVar3 = FUN_180024170();
    puVar6 = &DAT_18007a15f;
    do {
      pcVar4 = puVar6 + 1;
      puVar6 = puVar6 + 1;
    } while (*pcVar4 != '\0');
    lVar7 = 0;
    do {
      cVar1 = *(char *)(IVar3 + lVar7);
      puVar6[lVar7] = cVar1;
      uVar2 = s__AOSA_IconDef_180053ef8._8_4_;
      lVar7 = lVar7 + 1;
    } while (cVar1 != '\0');
    pcVar4 = &DAT_18007a15f;
    do {
      pcVar8 = pcVar4;
      pcVar4 = pcVar8 + 1;
    } while (pcVar8[1] != '\0');
    *(undefined8 *)(pcVar8 + 1) = s__AOSA_IconDef_180053ef8._0_8_;
    *(undefined4 *)(pcVar8 + 9) = uVar2;
    *(undefined2 *)(pcVar8 + 0xd) = s__AOSA_IconDef_180053ef8._12_2_;
  }
  if (DAT_18007a050 == '\0') {
    GetModuleFileNameA((HMODULE)0x0,&DAT_18007a050,0x104);
    pcVar4 = strrchr(&DAT_18007a050,0x5c);
    if (pcVar4 == (char *)0x0) {
      pcVar4 = strrchr(&DAT_18007a050,0x2f);
      if (pcVar4 == (char *)0x0) goto LAB_180010d01;
    }
    *(undefined8 *)(pcVar4 + 1) = s_aosa_ini_180053f08._0_8_;
    pcVar4[9] = s_aosa_ini_180053f08[8];
  }
LAB_180010d01:
  if ((DAT_18007a160 != '\0') && (DAT_18007a050 != '\0')) {
    return 0;
  }
  return 1;
}

/* ---- FUNC 00010BE3 FUN_180010be3 (191 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_180010be3(undefined8 param_1)

{
  char cVar1;
  undefined4 uVar2;
  INT_PTR IVar3;
  char *pcVar4;
  undefined2 *puVar5;
  undefined *puVar6;
  longlong lVar7;
  char *pcVar8;
  undefined8 in_XMM0_Qb;
  
  DAT_18007a160 = 'S';
  _DAT_18007a161 = param_1;
  unique0x100000f0 = in_XMM0_Qb;
  IVar3 = FUN_180024130();
  puVar6 = &DAT_18007a15f;
  do {
    pcVar4 = puVar6 + 1;
    puVar6 = puVar6 + 1;
  } while (*pcVar4 != '\0');
  lVar7 = 0;
  do {
    cVar1 = *(char *)(IVar3 + lVar7);
    puVar6[lVar7] = cVar1;
    lVar7 = lVar7 + 1;
  } while (cVar1 != '\0');
  puVar5 = (undefined2 *)&DAT_18007a15f;
  do {
    pcVar4 = (char *)((longlong)puVar5 + 1);
    puVar5 = (undefined2 *)((longlong)puVar5 + 1);
  } while (*pcVar4 != '\0');
  *puVar5 = DAT_180053ef4;
  IVar3 = FUN_180024170();
  puVar6 = &DAT_18007a15f;
  do {
    pcVar4 = puVar6 + 1;
    puVar6 = puVar6 + 1;
  } while (*pcVar4 != '\0');
  lVar7 = 0;
  do {
    cVar1 = *(char *)(IVar3 + lVar7);
    puVar6[lVar7] = cVar1;
    uVar2 = s__AOSA_IconDef_180053ef8._8_4_;
    lVar7 = lVar7 + 1;
  } while (cVar1 != '\0');
  pcVar4 = &DAT_18007a15f;
  do {
    pcVar8 = pcVar4;
    pcVar4 = pcVar8 + 1;
  } while (pcVar8[1] != '\0');
  *(undefined8 *)(pcVar8 + 1) = s__AOSA_IconDef_180053ef8._0_8_;
  *(undefined4 *)(pcVar8 + 9) = uVar2;
  *(undefined2 *)(pcVar8 + 0xd) = s__AOSA_IconDef_180053ef8._12_2_;
  if (DAT_18007a050 == '\0') {
    GetModuleFileNameA((HMODULE)0x0,&DAT_18007a050,0x104);
    pcVar4 = strrchr(&DAT_18007a050,0x5c);
    if (pcVar4 == (char *)0x0) {
      pcVar4 = strrchr(&DAT_18007a050,0x2f);
      if (pcVar4 == (char *)0x0) goto LAB_180010d01;
    }
    *(undefined8 *)(pcVar4 + 1) = s_aosa_ini_180053f08._0_8_;
    pcVar4[9] = s_aosa_ini_180053f08[8];
  }
LAB_180010d01:
  if ((DAT_18007a160 != '\0') && (DAT_18007a050 != '\0')) {
    return 0;
  }
  return 1;
}

/* ---- FUNC 00010CA2 FUN_180010ca2 (130 bytes) ---- */

undefined8 FUN_180010ca2(void)

{
  char *pcVar1;
  
  if (DAT_18007a050 == '\0') {
    GetModuleFileNameA((HMODULE)0x0,&DAT_18007a050,0x104);
    pcVar1 = strrchr(&DAT_18007a050,0x5c);
    if (pcVar1 == (char *)0x0) {
      pcVar1 = strrchr(&DAT_18007a050,0x2f);
      if (pcVar1 == (char *)0x0) goto LAB_180010d01;
    }
    *(undefined8 *)(pcVar1 + 1) = s_aosa_ini_180053f08._0_8_;
    pcVar1[9] = s_aosa_ini_180053f08[8];
  }
LAB_180010d01:
  if ((DAT_18007a160 != '\0') && (DAT_18007a050 != '\0')) {
    return 0;
  }
  return 1;
}

/* ---- FUNC 00010D30 GetApwnLibrary (47 bytes) ---- */

/* public: class CApwnLibrary * __ptr64 __cdecl CApwnLibraries::GetApwnLibrary(int) __ptr64 */

CApwnLibrary * __thiscall CApwnLibraries::GetApwnLibrary(CApwnLibraries *this,int param_1)

{
                    /* 0x10d30  92  ?GetApwnLibrary@CApwnLibraries@@QEAAPEAVCApwnLibrary@@H@Z */
  if ((-1 < param_1) && (param_1 < *(int *)(this + 0x18))) {
    if ((longlong)param_1 < *(longlong *)(this + 0x18)) {
      return *(CApwnLibrary **)(*(longlong *)(this + 0x10) + (longlong)param_1 * 8);
    }
                    /* WARNING: Subroutine does not return */
    AfxThrowInvalidArgException();
  }
  return (CApwnLibrary *)0x0;
}

/* ---- FUNC 00010D60 GetApwnLibrary (33 bytes) ---- */

/* public: class CApwnLibrary * __ptr64 __cdecl CApwnLibraries::GetApwnLibrary(char const * __ptr64)
   __ptr64 */

CApwnLibrary * __thiscall CApwnLibraries::GetApwnLibrary(CApwnLibraries *this,char *param_1)

{
  int iVar1;
  CApwnLibrary *pCVar2;
  
                    /* 0x10d60  93  ?GetApwnLibrary@CApwnLibraries@@QEAAPEAVCApwnLibrary@@PEBD@Z */
  iVar1 = FUN_180010330((longlong)(this + 8),param_1);
  pCVar2 = GetApwnLibrary(this,iVar1);
  return pCVar2;
}

/* ---- FUNC 00010D90 GetCategory (59 bytes) ---- */

/* public: class CPaletteCategory * __ptr64 __cdecl CApwnLibraries::GetCategory(int) __ptr64 */

CPaletteCategory * __thiscall CApwnLibraries::GetCategory(CApwnLibraries *this,int param_1)

{
  longlong lVar1;
  
                    /* 0x10d90  95  ?GetCategory@CApwnLibraries@@QEAAPEAVCPaletteCategory@@H@Z */
  if (*(longlong *)(this + 0x40) + -1 <= (longlong)param_1) {
    return (CPaletteCategory *)0x0;
  }
  lVar1 = (longlong)param_1 + 1;
  if ((-1 < lVar1) && (lVar1 < *(longlong *)(this + 0x40))) {
    return *(CPaletteCategory **)(*(longlong *)(this + 0x38) + lVar1 * 8);
  }
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 00010DD0 GetCategory (192 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: class CPaletteCategory * __ptr64 __cdecl CApwnLibraries::GetCategory(char * __ptr64)
   __ptr64 */

CPaletteCategory * __thiscall CApwnLibraries::GetCategory(CApwnLibraries *this,char *param_1)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  CPaletteCategory *pCVar4;
  undefined1 auStack_a8 [32];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_88 [16];
  char local_78 [80];
  ulonglong local_28;
  
                    /* 0x10dd0  96  ?GetCategory@CApwnLibraries@@QEAAPEAVCPaletteCategory@@PEAD@Z */
  local_28 = DAT_1800791f8 ^ (ulonglong)auStack_a8;
  iVar1 = *(int *)(this + 0x40);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_88,param_1);
  if (0 < iVar1) {
    lVar3 = 0;
    do {
      if ((lVar3 < 0) || (*(longlong *)(this + 0x40) <= lVar3)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      pCVar4 = *(CPaletteCategory **)(*(longlong *)(this + 0x38) + lVar3 * 8);
      if (pCVar4 != (CPaletteCategory *)0x0) {
        (**(code **)(*(longlong *)pCVar4 + 0x18))(pCVar4,local_78,0x50);
        iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                          (local_88,local_78);
        if (iVar2 == 0) goto LAB_180010e5a;
      }
      lVar3 = lVar3 + 1;
    } while (lVar3 < iVar1);
  }
  pCVar4 = (CPaletteCategory *)0x0;
LAB_180010e5a:
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_88);
  return pCVar4;
}

/* ---- FUNC 00010EA0 GetLibrary (90 bytes) ---- */

/* public: struct IAUserModelLibrary * __ptr64 __cdecl CApwnLibraries::GetLibrary(int) __ptr64 */

IAUserModelLibrary * __thiscall CApwnLibraries::GetLibrary(CApwnLibraries *this,int param_1)

{
  undefined8 *puVar1;
  IAUserModelLibrary *pIVar2;
  IAUserModelLibrary *local_res8 [4];
  
                    /* 0x10ea0  104  ?GetLibrary@CApwnLibraries@@QEAAPEAUIAUserModelLibrary@@H@Z */
  if (*(int *)(this + 0x18) <= param_1) {
    return (IAUserModelLibrary *)0x0;
  }
  local_res8[0] = (IAUserModelLibrary *)0x0;
  if ((-1 < param_1) && ((longlong)param_1 < *(longlong *)(this + 0x18))) {
    puVar1 = *(undefined8 **)(*(longlong *)(*(longlong *)(this + 0x10) + (longlong)param_1 * 8) + 8)
    ;
    pIVar2 = (IAUserModelLibrary *)0x0;
    if (puVar1 != (undefined8 *)0x0) {
      (**(code **)*puVar1)(puVar1,&DAT_180056270,local_res8);
      pIVar2 = local_res8[0];
    }
    return pIVar2;
  }
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 00010F00 GetModelTypeAttr (12 bytes) ---- */

/* public: int __cdecl CApwnLibraries::GetModelTypeAttr(__int64,enum ApwnModelTypeAttr,void *
   __ptr64,unsigned __int64) __ptr64 */

int __thiscall
CApwnLibraries::GetModelTypeAttr
          (CApwnLibraries *this,__int64 param_1,ApwnModelTypeAttr param_2,void *param_3,
          __uint64 param_4)

{
  int iVar1;
  
                    /* 0x10f00  106
                       ?GetModelTypeAttr@CApwnLibraries@@QEAAH_JW4ApwnModelTypeAttr@@PEAX_K@Z */
  iVar1 = FUN_180010f10((longlong *)(this + 0x90),param_1,param_2,param_3,param_4);
  return iVar1;
}

/* ---- FUNC 00010F10 FUN_180010f10 (991 bytes) ---- */

int FUN_180010f10(longlong *param_1,ulonglong param_2,undefined4 param_3,char *param_4,
                 size_t param_5)

{
  undefined8 *puVar1;
  int iVar2;
  CApwnLibrary *pCVar3;
  longlong *plVar4;
  char *_Source;
  longlong *plVar5;
  longlong *local_res10;
  longlong *local_18;
  longlong *local_10;
  
  if (param_2 == 0xffffffffffffffff) {
    return -1;
  }
  if ((ulonglong)(param_1[1] - *param_1 >> 5) <= param_2) {
    return -1;
  }
  plVar5 = (longlong *)(param_2 * 0x20 + *param_1);
  switch(param_3) {
  case 0:
    _Source = (char *)plVar5[2];
    if (param_4 == (char *)0x0) {
      return *(int *)(_Source + -0x10) + 1;
    }
    goto LAB_180010f88;
  case 1:
    _Source = (char *)plVar5[1];
    if (param_4 == (char *)0x0) {
      return *(int *)(_Source + -0x10) + 1;
    }
    goto LAB_180010f88;
  case 2:
    _Source = (char *)*plVar5;
    if (param_4 == (char *)0x0) {
      return *(int *)(_Source + -0x10) + 1;
    }
LAB_180010f88:
    strncpy(param_4,_Source,param_5);
    param_4[param_5 - 1] = '\0';
    return -1;
  case 3:
    pCVar3 = CApwnLibraries::GetApwnLibrary(g_pApwnLibs,(char *)*plVar5);
    if (pCVar3 == (CApwnLibrary *)0x0) {
      return -1;
    }
    puVar1 = *(undefined8 **)(pCVar3 + 8);
    local_res10 = (longlong *)0x0;
    if ((puVar1 != (undefined8 *)0x0) &&
       (iVar2 = (**(code **)*puVar1)(puVar1,&DAT_180053510,&local_res10), iVar2 < 0)) {
      local_res10 = (longlong *)0x0;
    }
    plVar4 = local_res10;
    if (local_res10 != (longlong *)0x0) {
      local_18 = (longlong *)0x0;
      iVar2 = (**(code **)(*local_res10 + 0x38))(local_res10,plVar5[2],&local_18);
      if ((-1 < iVar2) && (local_18 != (longlong *)0x0)) {
        local_10 = (longlong *)0x0;
        iVar2 = (**(code **)*local_18)(local_18,&DAT_180053520,&local_10);
        if (iVar2 < 0) {
          local_10 = (longlong *)0x0;
        }
        if (local_10 != (longlong *)0x0) {
          iVar2 = (**(code **)(*local_10 + 0x18))(local_10,param_4,param_5 & 0xffffffff);
          if (local_10 != (longlong *)0x0) {
            (**(code **)(*local_10 + 0x10))();
          }
          if (local_18 != (longlong *)0x0) {
            (**(code **)(*local_18 + 0x10))();
          }
          goto LAB_180011058;
        }
      }
      plVar4 = local_res10;
      if (local_18 != (longlong *)0x0) {
        (**(code **)(*local_18 + 0x10))();
        plVar4 = local_res10;
      }
    }
    break;
  case 4:
    pCVar3 = CApwnLibraries::GetApwnLibrary(g_pApwnLibs,(char *)*plVar5);
    if (pCVar3 == (CApwnLibrary *)0x0) {
      return -1;
    }
    puVar1 = *(undefined8 **)(pCVar3 + 8);
    local_res10 = (longlong *)0x0;
    if ((puVar1 != (undefined8 *)0x0) &&
       (iVar2 = (**(code **)*puVar1)(puVar1,&DAT_180053510,&local_res10), iVar2 < 0)) {
      local_res10 = (longlong *)0x0;
    }
    plVar4 = local_res10;
    if (local_res10 != (longlong *)0x0) {
      local_10 = (longlong *)0x0;
      iVar2 = (**(code **)(*local_res10 + 0x38))(local_res10,plVar5[2],&local_10);
      if ((-1 < iVar2) && (local_10 != (longlong *)0x0)) {
        iVar2 = (**(code **)*local_10)(local_10,&DAT_180057a58,param_4);
        if (local_10 != (longlong *)0x0) {
          (**(code **)(*local_10 + 0x10))();
        }
LAB_180011058:
        if (local_res10 != (longlong *)0x0) {
          (**(code **)(*local_res10 + 0x10))();
          return iVar2;
        }
        return iVar2;
      }
      plVar4 = local_res10;
      if (local_10 != (longlong *)0x0) {
        (**(code **)(*local_10 + 0x10))();
        plVar4 = local_res10;
      }
    }
    break;
  case 5:
    pCVar3 = CApwnLibraries::GetApwnLibrary(g_pApwnLibs,(char *)*plVar5);
    if (pCVar3 == (CApwnLibrary *)0x0) {
      return -1;
    }
    puVar1 = *(undefined8 **)(pCVar3 + 8);
    local_res10 = (longlong *)0x0;
    if ((puVar1 != (undefined8 *)0x0) &&
       (iVar2 = (**(code **)*puVar1)(puVar1,&DAT_180053510,&local_res10), iVar2 < 0)) {
      local_res10 = (longlong *)0x0;
    }
    plVar4 = local_res10;
    if (local_res10 != (longlong *)0x0) {
      local_10 = (longlong *)0x0;
      iVar2 = (**(code **)(*local_res10 + 0x38))(local_res10,plVar5[2],&local_10);
      if ((-1 < iVar2) && (local_10 != (longlong *)0x0)) {
        iVar2 = (**(code **)(*local_10 + 0x40))(local_10,param_4,param_5 & 0xffffffff);
        if (local_10 != (longlong *)0x0) {
          (**(code **)(*local_10 + 0x10))();
        }
        goto LAB_180011058;
      }
      plVar4 = local_res10;
      if (local_10 != (longlong *)0x0) {
        (**(code **)(*local_10 + 0x10))();
        plVar4 = local_res10;
      }
    }
    break;
  case 6:
    pCVar3 = CApwnLibraries::GetApwnLibrary(g_pApwnLibs,(char *)*plVar5);
    if (pCVar3 == (CApwnLibrary *)0x0) {
      return -1;
    }
    puVar1 = *(undefined8 **)(pCVar3 + 8);
    local_18 = (longlong *)0x0;
    if ((puVar1 != (undefined8 *)0x0) &&
       (iVar2 = (**(code **)*puVar1)(puVar1,&DAT_180053510,&local_18), iVar2 < 0)) {
      local_18 = (longlong *)0x0;
    }
    plVar4 = local_18;
    if (local_18 != (longlong *)0x0) {
      local_10 = (longlong *)0x0;
      iVar2 = (**(code **)(*local_18 + 0x38))(local_18,plVar5[2],&local_10);
      if ((-1 < iVar2) && (local_10 != (longlong *)0x0)) {
        local_res10 = (longlong *)((ulonglong)local_res10 & 0xffffffff00000000);
        (**(code **)(*local_10 + 0x50))(local_10,&local_res10);
        iVar2 = (int)local_res10;
        if (local_10 != (longlong *)0x0) {
          (**(code **)(*local_10 + 0x10))();
        }
        if (local_18 != (longlong *)0x0) {
          (**(code **)(*local_18 + 0x10))();
          return iVar2;
        }
        return iVar2;
      }
      plVar4 = local_18;
      if (local_10 != (longlong *)0x0) {
        (**(code **)(*local_10 + 0x10))();
        plVar4 = local_18;
      }
    }
    break;
  default:
    goto switchD_180010f73_default;
  }
  if (plVar4 != (longlong *)0x0) {
    (**(code **)(*plVar4 + 0x10))();
  }
switchD_180010f73_default:
  return -1;
}

/* ---- FUNC 00011310 FUN_180011310 (4 bytes) ---- */

undefined4 FUN_180011310(longlong param_1)

{
  return *(undefined4 *)(param_1 + 0x28);
}

/* ---- FUNC 00011320 GetModelTypeList (10 bytes) ---- */

/* public: void __cdecl CApwnLibraries::GetModelTypeList(struct IAEditCategories * __ptr64 *
   __ptr64) __ptr64 */

void __thiscall CApwnLibraries::GetModelTypeList(CApwnLibraries *this,IAEditCategories **param_1)

{
                    /* 0x11320  107
                       ?GetModelTypeList@CApwnLibraries@@QEAAXPEAPEAUIAEditCategories@@@Z */
  *param_1 = (IAEditCategories *)this;
                    /* WARNING: Could not recover jumptable at 0x000180011326. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(longlong *)this + 8))();
  return;
}

/* ---- FUNC 00011330 FUN_180011330 (62 bytes) ---- */

undefined8 FUN_180011330(longlong param_1,char *param_2,int param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(*(char **)(param_1 + 0x10) + -0x10);
  if (param_3 + -1 <= iVar1) {
    iVar1 = param_3 + -1;
  }
  strncpy(param_2,*(char **)(param_1 + 0x10),(longlong)iVar1);
  param_2[iVar1] = '\0';
  return 0;
}

/* ---- FUNC 00011370 GetSaveSize (7 bytes) ---- */

/* public: int __cdecl CApwnLibraries::GetSaveSize(void) __ptr64 */

int __thiscall CApwnLibraries::GetSaveSize(CApwnLibraries *this)

{
  int iVar1;
  
                    /* 0x11370  109  ?GetSaveSize@CApwnLibraries@@QEAAHXZ */
  iVar1 = DoSave(this,(char **)0x0);
  return iVar1;
}

/* ---- FUNC 00011380 GetUniqueDisplayName (253 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: class ATL::CStringT<char,class StrTraitMFC_DLL<char,class ATL::ChTraitsCRT<char> > >
   __cdecl CApwnLibraries::GetUniqueDisplayName(class ATL::CStringT<char,class
   StrTraitMFC_DLL<char,class ATL::ChTraitsCRT<char> > > & __ptr64) __ptr64 */

CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> * __thiscall
CApwnLibraries::GetUniqueDisplayName
          (CApwnLibraries *this,
          CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *param_1)

{
  longlong lVar1;
  bool bVar2;
  IAtlStringMgr *pIVar3;
  longlong lVar4;
  int _Value;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *in_R8;
  undefined1 auStackY_98 [32];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_60 [8];
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *local_58;
  char local_50 [24];
  ulonglong local_38;
  longlong lVar5;
  
                    /* 0x11380  111
                       ?GetUniqueDisplayName@CApwnLibraries@@QEAA?AV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@AEAV23@@Z
                        */
  local_38 = DAT_1800791f8 ^ (ulonglong)auStackY_98;
  _Value = 1;
  local_58 = param_1;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_1);
  while( true ) {
    _itoa(_Value,local_50,10);
    pIVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager(in_R8);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_60,pIVar3);
    lVar5 = -1;
    do {
      lVar4 = lVar5 + 1;
      lVar1 = lVar5 + 1;
      lVar5 = lVar4;
    } while (local_50[lVar1] != '\0');
    ATL::CSimpleStringT<char,1>::Concatenate
              ((CSimpleStringT<char,1> *)local_60,*(char **)in_R8,*(int *)(*(char **)in_R8 + -0x10),
               local_50,(int)lVar4);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_1,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)local_60
              );
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_60);
    bVar2 = IsLibraryNameUnique(this,(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                      *)param_1);
    if (bVar2) break;
    _Value = _Value * 10 + 1;
  }
  return param_1;
}

/* ---- FUNC 00011480 HaveAnyLibraries (8 bytes) ---- */

/* public: bool __cdecl CApwnLibraries::HaveAnyLibraries(void) __ptr64 */

bool __thiscall CApwnLibraries::HaveAnyLibraries(CApwnLibraries *this)

{
                    /* 0x11480  113  ?HaveAnyLibraries@CApwnLibraries@@QEAA_NXZ */
  return 0 < *(int *)(this + 0x18);
}

/* ---- FUNC 00011490 Init (72 bytes) ---- */

/* public: void __cdecl CApwnLibraries::Init(struct IUnknown * __ptr64,struct IUnknown * __ptr64)
   __ptr64 */

void __thiscall CApwnLibraries::Init(CApwnLibraries *this,IUnknown *param_1,IUnknown *param_2)

{
  longlong *plVar1;
  
                    /* 0x11490  114  ?Init@CApwnLibraries@@QEAAXPEAUIUnknown@@0@Z */
  plVar1 = *(longlong **)(this + 0x88);
  if (plVar1 != (longlong *)0x0) {
    (**(code **)(*plVar1 + 0x10))();
  }
  (*param_1->lpVtbl->QueryInterface)(param_1,(IID *)&DAT_180056230,(void **)(this + 0x88));
  FUN_180036960();
  FUN_1800338d0();
  return;
}

/* ---- FUNC 000114E0 InitCatFromRegistry (789 bytes) ---- */

/* public: int __cdecl CApwnLibraries::InitCatFromRegistry(class CNameAndStateArray & __ptr64)
   __ptr64 */

int __thiscall CApwnLibraries::InitCatFromRegistry(CApwnLibraries *this,CNameAndStateArray *param_1)

{
  undefined4 uVar1;
  char *pcVar2;
  undefined1 auVar3 [16];
  undefined4 uVar4;
  DWORD DVar5;
  __uint64 _Var6;
  void *pvVar7;
  void *pvVar8;
  ulonglong uVar9;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar10;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar11;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar12;
  ulonglong uVar13;
  int iVar14;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar15;
  longlong lVar16;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar17;
  undefined4 local_res18 [2];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_res20;
  undefined **local_68;
  longlong local_60;
  int local_58;
  undefined4 uStack_54;
  
                    /* 0x114e0  115
                       ?InitCatFromRegistry@CApwnLibraries@@QEAAHAEAVCNameAndStateArray@@@Z */
  DVar5 = APModCatCount();
  uVar13 = (ulonglong)(int)DVar5;
  CPtrArray::CPtrArray((CPtrArray *)&local_68);
  local_68 = CTypedPtrArray<CPtrArray,CCatInfo*___ptr64>::vftable;
  auVar3._8_8_ = 0;
  auVar3._0_8_ = uVar13;
  _Var6 = SUB168(ZEXT816(8) * auVar3,0);
  if (SUB168(ZEXT816(8) * auVar3,8) != 0) {
    _Var6 = 0xffffffffffffffff;
  }
  pvVar7 = operator_new__(_Var6);
  pCVar17 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
  pCVar12 = pCVar17;
  if (0 < (int)DVar5) {
    do {
      pvVar8 = operator_new__(0x40);
      *(void **)((longlong)pvVar7 + (longlong)pCVar12 * 8) = pvVar8;
      pCVar12 = pCVar12 + 1;
    } while ((longlong)pCVar12 < (longlong)uVar13);
  }
  uVar9 = APModCatListCats((longlong)pvVar7,DVar5,0x40);
  if ((int)uVar9 == 1) {
    pCVar12 = pCVar17;
    if (0 < (int)DVar5) {
      do {
        local_res20 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                      ((ulonglong)local_res20 & 0xffffffff00000000);
        local_res18[0] = 0;
        APModCatGetValues(*(longlong *)((longlong)pvVar7 + (longlong)pCVar12 * 8),
                          (undefined4 *)&local_res20,local_res18);
        pCVar10 = operator_new(0x10);
        uVar1 = local_res18[0];
        pCVar11 = pCVar17;
        if (pCVar10 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
          uVar4 = local_res20._0_4_;
          pcVar2 = *(char **)((longlong)pvVar7 + (longlong)pCVar12 * 8);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar10);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    (pCVar10,pcVar2);
          *(undefined4 *)(pCVar10 + 8) = uVar4;
          *(undefined4 *)(pCVar10 + 0xc) = uVar1;
          pCVar11 = pCVar10;
        }
        lVar16 = CONCAT44(uStack_54,local_58);
        pCVar10 = pCVar17;
        pCVar15 = pCVar17;
        while( true ) {
          iVar14 = (int)pCVar15;
          if (lVar16 <= iVar14) break;
          if (((longlong)pCVar10 < 0) || (lVar16 <= (longlong)pCVar10)) {
                    /* WARNING: Subroutine does not return */
            AfxThrowInvalidArgException();
          }
          if (*(int *)(pCVar11 + 8) < *(int *)(*(longlong *)(local_60 + (longlong)pCVar10 * 8) + 8))
          {
            CPtrArray::InsertAt((CPtrArray *)&local_68,(longlong)iVar14,pCVar11,1);
            goto LAB_180011655;
          }
          pCVar15 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                    (ulonglong)(iVar14 + 1);
          pCVar10 = pCVar10 + 1;
        }
        CPtrArray::SetAtGrow((CPtrArray *)&local_68,lVar16,pCVar11);
LAB_180011655:
        pCVar12 = pCVar12 + 1;
      } while ((longlong)pCVar12 < (longlong)uVar13);
    }
    lVar16 = (longlong)local_58;
    CPtrArray::SetSize((CPtrArray *)param_1,lVar16,-1);
    pCVar12 = pCVar17;
    if (0 < lVar16) {
      do {
        pCVar10 = operator_new(0x10);
        pCVar11 = pCVar17;
        local_res20 = pCVar10;
        if (pCVar10 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
          if (((longlong)pCVar12 < 0) || (CONCAT44(uStack_54,local_58) <= (longlong)pCVar12)) {
                    /* WARNING: Subroutine does not return */
            AfxThrowInvalidArgException();
          }
          pCVar11 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                               local_res18,
                               *(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                 **)((longlong)pCVar12 * 8 + local_60));
          if (CONCAT44(uStack_54,local_58) <= (longlong)pCVar12) {
                    /* WARNING: Subroutine does not return */
            AfxThrowInvalidArgException();
          }
          uVar1 = *(undefined4 *)(*(longlong *)((longlong)pCVar12 * 8 + local_60) + 0xc);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar10);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    (pCVar10,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                              *)pCVar11);
          *(undefined4 *)(pCVar10 + 8) = uVar1;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar11);
          pCVar11 = pCVar10;
        }
        if ((((longlong)pCVar12 < 0) || (*(longlong *)(param_1 + 0x10) <= (longlong)pCVar12)) ||
           (*(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
             ((longlong)pCVar12 * 8 + *(longlong *)(param_1 + 8)) = pCVar11,
           CONCAT44(uStack_54,local_58) <= (longlong)pCVar12)) {
                    /* WARNING: Subroutine does not return */
          AfxThrowInvalidArgException();
        }
        pCVar11 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
                   ((longlong)pCVar12 * 8 + local_60);
        if (pCVar11 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar11);
          operator_delete(pCVar11);
        }
        pCVar12 = pCVar12 + 1;
      } while ((longlong)pCVar12 < lVar16);
    }
    CPtrArray::SetSize((CPtrArray *)&local_68,0,-1);
  }
  if (0 < (longlong)uVar13) {
    do {
      operator_delete__(*(void **)((longlong)pvVar7 + (longlong)pCVar17 * 8));
      pCVar17 = pCVar17 + 1;
    } while ((longlong)pCVar17 < (longlong)uVar13);
  }
  operator_delete__(pvVar7);
  CPtrArray::~CPtrArray((CPtrArray *)&local_68);
  return 0;
}

/* ---- FUNC 00011800 InitFromRegistry (188 bytes) ---- */

/* public: int __cdecl CApwnLibraries::InitFromRegistry(struct HWND__ * __ptr64) __ptr64 */

int __thiscall CApwnLibraries::InitFromRegistry(CApwnLibraries *this,HWND__ *param_1)

{
  int iVar1;
  CStringArray local_58 [16];
  longlong local_48;
  undefined **local_30 [5];
  
                    /* 0x11800  116  ?InitFromRegistry@CApwnLibraries@@QEAAHPEAUHWND__@@@Z */
  CStringArray::CStringArray(local_58);
  InitLibFromRegistry(this,local_58);
  CPtrArray::CPtrArray((CPtrArray *)local_30);
  local_30[0] = CNameAndStateArray::vftable;
  InitCatFromRegistry(this,(CNameAndStateArray *)local_30);
  if (local_48 == 0) {
    CStringArray::SetAtGrow(local_58,0,&m_builtin);
    CStringArray::SetAtGrow(local_58,local_48,&m_capeopen);
    CStringArray::SetAtGrow(local_58,local_48,&m_acmcatalog);
  }
  iVar1 = ReconcileLibs(this,local_58,(CNameAndStateArray *)local_30);
  CNameAndStateArray::~CNameAndStateArray((CNameAndStateArray *)local_30);
  CStringArray::~CStringArray(local_58);
  return iVar1;
}

/* ---- FUNC 000118C0 InitFromTemplate (481 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: int __cdecl CApwnLibraries::InitFromTemplate(struct HWND__ * __ptr64,struct
   IAUserModelLibrary * __ptr64) __ptr64 */

int __thiscall
CApwnLibraries::InitFromTemplate(CApwnLibraries *this,HWND__ *param_1,IAUserModelLibrary *param_2)

{
  int iVar1;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this_00;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar2;
  __int64 _Var3;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this_01;
  undefined1 auStack_f8 [32];
  char *local_d8;
  CStringArray local_d0 [8];
  longlong local_c8;
  __int64 local_c0;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_a8;
  undefined **local_a0 [5];
  char local_78 [64];
  ulonglong local_38;
  
                    /* 0x118c0  117
                       ?InitFromTemplate@CApwnLibraries@@QEAAHPEAUHWND__@@PEAUIAUserModelLibrary@@@Z
                        */
  local_38 = DAT_1800791f8 ^ (ulonglong)auStack_f8;
  CStringArray::CStringArray(local_d0);
  InitLibFromRegistry(this,local_d0);
  CPtrArray::CPtrArray((CPtrArray *)local_a0);
  local_a0[0] = CNameAndStateArray::vftable;
  InitCatFromRegistry(this,(CNameAndStateArray *)local_a0);
  _Var3 = local_c0;
  if ((int)local_c0 == 0) {
    CStringArray::SetAtGrow(local_d0,local_c0,&m_builtin);
    CStringArray::SetAtGrow(local_d0,local_c0,&m_capeopen);
    CStringArray::SetAtGrow(local_d0,local_c0,&m_acmcatalog);
    _Var3 = 3;
  }
  (**(code **)(*(longlong *)param_2 + 0x38))(param_2,local_78,0x40);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_d8,local_78);
  iVar1 = FUN_180010330((longlong)(this + 8),local_78);
  pCVar2 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
  if (iVar1 < 0) {
    this_00 = operator_new(0x10);
    this_01 = pCVar2;
    local_a8 = this_00;
    if (this_00 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(this_00);
      *(undefined8 *)(this_00 + 8) = 0;
      this_01 = this_00;
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(this_01,local_d8);
    FUN_1800164b0((longlong)this_01,(longlong *)param_2);
    CPtrArray::SetAtGrow((CPtrArray *)(this + 8),*(__int64 *)(this + 0x18),this_01);
  }
  if (0 < (int)_Var3) {
    do {
      if (((longlong)pCVar2 < 0) || (local_c0 <= (longlong)pCVar2)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_d8,
                         *(char **)(local_c8 + (longlong)pCVar2 * 8));
      if (iVar1 == 0) goto LAB_180011a42;
      pCVar2 = pCVar2 + 1;
    } while ((longlong)pCVar2 < (longlong)(int)_Var3);
  }
  CStringArray::SetAtGrow
            (local_d0,local_c0,
             (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_d8);
LAB_180011a42:
  iVar1 = ReconcileLibs(this,local_d0,(CNameAndStateArray *)local_a0);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_d8);
  CNameAndStateArray::~CNameAndStateArray((CNameAndStateArray *)local_a0);
  CStringArray::~CStringArray(local_d0);
  return iVar1;
}

/* ---- FUNC 00011AB0 InitLibFromRegistry (897 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: int __cdecl CApwnLibraries::InitLibFromRegistry(class CStringArray & __ptr64) __ptr64 */

int __thiscall CApwnLibraries::InitLibFromRegistry(CApwnLibraries *this,CStringArray *param_1)

{
  char *pcVar1;
  undefined1 auVar2 [16];
  bool bVar3;
  DWORD DVar4;
  DWORD DVar5;
  int iVar6;
  __uint64 _Var7;
  void *pvVar8;
  void *pvVar9;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar10;
  undefined7 extraout_var;
  undefined7 extraout_var_00;
  undefined7 extraout_var_01;
  undefined7 extraout_var_02;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar11;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar12;
  ulonglong uVar13;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar14;
  undefined1 auStackY_1b8 [32];
  int local_188;
  int local_184;
  int local_180 [2];
  undefined **local_178;
  longlong local_170;
  longlong local_168;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_150;
  char local_148 [272];
  ulonglong local_38;
  
                    /* 0x11ab0  118  ?InitLibFromRegistry@CApwnLibraries@@QEAAHAEAVCStringArray@@@Z
                        */
  local_38 = DAT_1800791f8 ^ (ulonglong)auStackY_1b8;
  DVar4 = APModLibCount();
  uVar13 = (ulonglong)(int)DVar4;
  CPtrArray::CPtrArray((CPtrArray *)&local_178);
  local_178 = CTypedPtrArray<CPtrArray,CNameAndPos*___ptr64>::vftable;
  auVar2._8_8_ = 0;
  auVar2._0_8_ = uVar13;
  _Var7 = SUB168(ZEXT816(8) * auVar2,0);
  if (SUB168(ZEXT816(8) * auVar2,8) != 0) {
    _Var7 = 0xffffffffffffffff;
  }
  pvVar8 = operator_new__(_Var7);
  pCVar14 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
  pCVar12 = pCVar14;
  if (0 < (int)DVar4) {
    do {
      pvVar9 = operator_new__(0x40);
      *(void **)((longlong)pvVar8 + (longlong)pCVar12 * 8) = pvVar9;
      pCVar12 = pCVar12 + 1;
    } while ((longlong)pCVar12 < (longlong)uVar13);
  }
  DVar5 = APModLibListLibs((longlong)pvVar8,DVar4,0x40);
  pCVar12 = pCVar14;
  if (DVar5 == 1) {
    if (0 < (int)DVar4) {
      do {
        local_184 = (int)pCVar12;
        pcVar1 = *(char **)((longlong)pvVar8 + (longlong)pCVar14 * 8);
        local_180[0] = local_184;
        iVar6 = ApwnIsReservedDisplayName(pcVar1);
        if (iVar6 == 0) {
          DVar4 = APModLibGetValues((longlong)pcVar1,local_148,0x104,local_180,&local_184);
          pCVar12 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                    (ulonglong)DVar4;
          if (local_184 != 0) {
            local_150 = operator_new(0x10);
            pCVar11 = pCVar12;
            pCVar10 = pCVar12;
            if (local_150 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
              pCVar10 = FUN_18000ce70(local_150,*(char **)((longlong)pvVar8 + (longlong)pCVar14 * 8)
                                      ,local_180[0]);
            }
            for (; (int)DVar4 < local_168; DVar4 = DVar4 + 1) {
              if (((longlong)pCVar11 < 0) || (local_168 <= (longlong)pCVar11)) {
                    /* WARNING: Subroutine does not return */
                AfxThrowInvalidArgException();
              }
              if (*(int *)(pCVar10 + 8) <
                  *(int *)(*(longlong *)(local_170 + (longlong)pCVar11 * 8) + 8)) {
                CPtrArray::InsertAt((CPtrArray *)&local_178,(longlong)(int)DVar4,pCVar10,1);
                goto LAB_180011c57;
              }
              pCVar11 = pCVar11 + 1;
            }
            CPtrArray::SetAtGrow((CPtrArray *)&local_178,local_168,pCVar10);
          }
        }
        else {
          APModLibUnregisterLib((longlong)pcVar1);
        }
LAB_180011c57:
        pCVar14 = pCVar14 + 1;
      } while ((longlong)pCVar14 < (longlong)uVar13);
    }
    iVar6 = (int)local_168;
    pCVar14 = pCVar12;
    if (0 < iVar6) {
      do {
        if ((((longlong)pCVar14 < 0) || (local_168 <= (longlong)pCVar14)) ||
           (CStringArray::SetAtGrow
                      (param_1,*(__int64 *)(param_1 + 0x10),
                       *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
                        (local_170 + (longlong)pCVar14 * 8)), local_168 <= (longlong)pCVar14)) {
                    /* WARNING: Subroutine does not return */
          AfxThrowInvalidArgException();
        }
        pCVar11 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
                   (local_170 + (longlong)pCVar14 * 8);
        if (pCVar11 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar11);
          operator_delete(pCVar11);
        }
        pCVar14 = pCVar14 + 1;
      } while ((longlong)pCVar14 < (longlong)iVar6);
    }
    CPtrArray::SetSize((CPtrArray *)&local_178,0,-1);
  }
  local_188 = (int)pCVar12;
  bVar3 = APModLibUseBuiltin(&local_188);
  if ((int)CONCAT71(extraout_var,bVar3) != 0) {
    CStringArray::InsertAt(param_1,(longlong)(local_188 + -1),&m_builtin,1);
  }
  bVar3 = APModLibUseCapeOpen(&local_188);
  if ((int)CONCAT71(extraout_var_00,bVar3) != 0) {
    if (local_188 == 0) {
      local_188 = *(int *)(param_1 + 0x10) + 1;
    }
    CStringArray::InsertAt(param_1,(longlong)(local_188 + -1),&m_capeopen,1);
  }
  bVar3 = FUN_180037f70(&local_188);
  if ((int)CONCAT71(extraout_var_01,bVar3) != 0) {
    if (local_188 == 0) {
      local_188 = *(int *)(param_1 + 0x10) + 1;
    }
    CStringArray::InsertAt(param_1,(longlong)(local_188 + -1),&m_acmcatalog,1);
  }
  bVar3 = FUN_180037c30(&local_188);
  if ((int)CONCAT71(extraout_var_02,bVar3) != 0) {
    if (local_188 == 0) {
      local_188 = *(int *)(param_1 + 0x10) + 1;
    }
    CStringArray::InsertAt(param_1,(longlong)(local_188 + -1),&m_acmbuiltin,1);
  }
  if (0 < (longlong)uVar13) {
    do {
      operator_delete__(*(void **)((longlong)pvVar8 + (longlong)pCVar12 * 8));
      pCVar12 = pCVar12 + 1;
    } while ((longlong)pCVar12 < (longlong)uVar13);
  }
  operator_delete__(pvVar8);
  CPtrArray::~CPtrArray((CPtrArray *)&local_178);
  return 0;
}

/* ---- FUNC 00011E40 FUN_180011e40 (212 bytes) ---- */

void FUN_180011e40(longlong param_1,longlong *param_2,char param_3)

{
  int iVar1;
  ulonglong uVar2;
  undefined4 local_res10 [2];
  longlong *local_res20;
  longlong *local_18 [2];
  
  local_18[0] = (longlong *)0x0;
  (**(code **)(*param_2 + 0x40))(param_2,local_18);
  if (local_18[0] != (longlong *)0x0) {
    local_res20 = (longlong *)0x0;
    local_res10[0] = 0;
    iVar1 = (**(code **)(*local_18[0] + 0x18))(local_18[0],1,&local_res20,local_res10);
    while (iVar1 == 0) {
      if ((param_3 == '\0') || (uVar2 = FUN_1800103e0(param_1 + 0x18,local_res20), (int)uVar2 < 0))
      {
        CPtrArray::SetAtGrow((CPtrArray *)(param_1 + 0x18),*(__int64 *)(param_1 + 0x28),local_res20)
        ;
      }
      else {
        (**(code **)(*local_res20 + 0x10))();
        local_res20 = (longlong *)0x0;
      }
      iVar1 = (**(code **)(*local_18[0] + 0x18))(local_18[0],1,&local_res20,local_res10);
    }
    (**(code **)(*local_18[0] + 0x10))();
  }
  return;
}

/* ---- FUNC 00011F20 InitializeApwnLibraries (84 bytes) ---- */

undefined8 InitializeApwnLibraries(IUnknown *param_1,IUnknown *param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  
                    /* 0x11f20  121  InitializeApwnLibraries */
  uVar1 = 0;
  if (g_pApwnLibs == (CApwnLibraries *)0x0) {
    uVar1 = 0x80004005;
  }
  else {
    CApwnLibraries::Init(g_pApwnLibs,param_1,param_2);
  }
  *param_3 = g_pApwnLibs;
  (**(code **)(*(longlong *)g_pApwnLibs + 8))();
  return uVar1;
}

/* ---- FUNC 00011F80 InsertLibrary (1997 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: bool __cdecl CApwnLibraries::InsertLibrary(class ATL::CStringT<char,class
   StrTraitMFC_DLL<char,class ATL::ChTraitsCRT<char> > > & __ptr64,int,char * __ptr64,long,int)
   __ptr64 */

bool __thiscall
CApwnLibraries::InsertLibrary
          (CApwnLibraries *this,
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_1,int param_2,
          char *param_3,long param_4,int param_5)

{
  longlong *plVar1;
  longlong lVar2;
  undefined1 auVar3 [16];
  IAEditCategories *pIVar4;
  bool bVar5;
  int iVar6;
  int extraout_EAX;
  HRESULT HVar7;
  int iVar8;
  __uint64 _Var9;
  void *pvVar10;
  void *pvVar11;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar12;
  char *pcVar13;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar14;
  ulonglong uVar15;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar16;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar17;
  DWORD DVar18;
  ulonglong uVar19;
  int iVar20;
  bool bVar21;
  undefined1 auStackY_288 [32];
  char local_258;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_250;
  char *local_248;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_240;
  int local_238;
  undefined4 local_234;
  IAEditCategories *local_230;
  undefined4 local_228 [2];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_220 [8];
  IAEditCategories *local_218;
  longlong local_210;
  IAEditCategories local_208 [80];
  char local_1b8 [80];
  char local_168 [272];
  ulonglong local_58;
  
                    /* 0x11f80  124
                       ?InsertLibrary@CApwnLibraries@@QEAA_NAEAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HPEADJH@Z
                        */
  local_58 = DAT_1800791f8 ^ (ulonglong)auStackY_288;
  local_250 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
              CONCAT44(local_250._4_4_,param_2);
  local_218 = (IAEditCategories *)param_3;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_248);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_220,"");
  local_258 = '\0';
  bVar21 = false;
  pCVar16 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
  if (param_2 < 0) {
    local_238 = 0;
  }
  else {
    local_238 = param_2;
    iVar6 = CountLibraries(this);
    if (iVar6 < param_2) {
      local_238 = CountLibraries(this);
    }
  }
  iVar6 = CountLibraries(this);
  pCVar17 = pCVar16;
  pCVar14 = pCVar16;
  if (0 < iVar6) {
LAB_180012026:
    if (((longlong)pCVar16 < 0) || (*(longlong *)(this + 0x18) <= (longlong)pCVar16)) {
                    /* WARNING: Subroutine does not return */
      AfxThrowInvalidArgException();
    }
    pvVar10 = *(void **)(*(longlong *)(this + 0x10) + (longlong)pCVar16 * 8);
    plVar1 = *(longlong **)((longlong)pvVar10 + 8);
    (**(code **)(*plVar1 + 0x38))(plVar1,local_208,0x50);
    local_234 = SUB84(pCVar17,0);
    local_228[0] = local_234;
    DVar18 = APModLibGetValues((longlong)local_208,local_1b8,0x50,&local_234,local_228);
    pCVar17 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(ulonglong)DVar18;
    iVar6 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                      (param_1,local_1b8);
    iVar20 = (int)pCVar14;
    if (iVar6 != 0) goto code_r0x00018001209a;
    iVar8 = CountLibraries(this);
    iVar6 = local_238;
    if (iVar8 < (int)local_250) {
      iVar6 = CountLibraries(this);
      iVar6 = iVar6 + -1;
    }
    if (iVar20 != iVar6) {
      CPtrArray::RemoveAt((CPtrArray *)(this + 8),(longlong)iVar20,1);
      (**(code **)(*plVar1 + 0x40))(plVar1,local_208);
      CPtrArray::InsertAt((CPtrArray *)(this + 8),(longlong)iVar6,pvVar10,1);
    }
    pIVar4 = local_218;
    uVar19 = 0xffffffffffffffff;
    do {
      uVar15 = uVar19 + 1;
      lVar2 = uVar19 + 1;
      uVar19 = uVar15;
    } while (local_208[lVar2] != SUB41(DVar18,0));
    iVar6 = (int)uVar15;
    if ((longlong)param_4 - 1U <= uVar15) {
      iVar6 = param_4 + -1;
    }
    strncpy((char *)local_218,(char *)local_208,(longlong)iVar6);
    pIVar4[iVar6] = SUB41(DVar18,0);
    bVar21 = param_5 == DVar18;
    goto LAB_180012730;
  }
LAB_1800120ae:
  DVar18 = APModLibCount();
  uVar19 = (ulonglong)(int)DVar18;
  auVar3._8_8_ = 0;
  auVar3._0_8_ = uVar19;
  _Var9 = SUB168(ZEXT816(8) * auVar3,0);
  if (SUB168(ZEXT816(8) * auVar3,8) != 0) {
    _Var9 = 0xffffffffffffffff;
  }
  pvVar10 = operator_new__(_Var9);
  pCVar16 = pCVar17;
  if (0 < (int)DVar18) {
    do {
      pvVar11 = operator_new__(0x40);
      *(void **)((longlong)pvVar10 + (longlong)pCVar16 * 8) = pvVar11;
      pCVar16 = pCVar16 + 1;
    } while ((longlong)pCVar16 < (longlong)uVar19);
  }
  APModLibListLibs((longlong)pvVar10,DVar18,0x40);
  pCVar16 = pCVar17;
  if (0 < (int)DVar18) {
    do {
      local_234 = SUB84(pCVar16,0);
      local_250 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                  CONCAT44(local_250._4_4_,local_234);
      DVar18 = APModLibGetValues(*(longlong *)((longlong)pvVar10 + (longlong)pCVar17 * 8),local_168,
                                 0x104,&local_234,(undefined4 *)&local_250);
      pCVar16 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(ulonglong)DVar18;
      if ((0 < extraout_EAX) &&
         (iVar6 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                            (param_1,local_168), iVar6 == 0)) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_248,
                   *(char **)((longlong)pvVar10 + (longlong)pCVar17 * 8));
        local_258 = '\x01';
        bVar21 = true;
      }
      pCVar17 = pCVar17 + 1;
    } while ((longlong)pCVar17 < (longlong)uVar19);
  }
  local_240 = pCVar16;
  HVar7 = CoCreateInstance((IID *)&DAT_1800562a0,(LPUNKNOWN)0x0,1,(IID *)&DAT_180056270,&local_240);
  if (-1 < HVar7) {
    iVar6 = (**(code **)(*(longlong *)local_240 + 0x18))(local_240,1,*(undefined8 *)param_1);
    if (iVar6 < 0) {
      (**(code **)(*(longlong *)local_240 + 0x10))();
    }
    else {
      iVar6 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
                        (param_1,'\\');
      if (local_258 == (char)pCVar16) {
        pCVar12 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Mid
                            (param_1,(int)&local_250,iVar6 + 1);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_248,
                   pCVar12);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_250);
        bVar5 = IsLibraryNameUnique(this,(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                          *)&local_248);
        if (!bVar5) {
          pCVar12 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                    GetUniqueDisplayName
                              (this,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                     *)&local_250);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_248,
                     pCVar12);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_250);
        }
      }
      pIVar4 = local_218;
      iVar6 = *(int *)(local_248 + -0x10);
      if (param_4 + -1 <= *(int *)(local_248 + -0x10)) {
        iVar6 = param_4 + -1;
      }
      strncpy((char *)local_218,local_248,(longlong)iVar6);
      pIVar4[iVar6] = (IAEditCategories)0x0;
      (**(code **)(*(longlong *)local_240 + 0x38))(local_240,local_208);
      iVar6 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_248
                         ,(char *)local_208);
      if (iVar6 != 0) {
        local_250 = pCVar16;
        (*(code *)**(undefined8 **)local_240)(local_240,&DAT_180057a98,&local_250);
        (**(code **)(*(longlong *)local_250 + 0x18))(local_250,&local_218);
        if ((((((((local_218 != DAT_1800562a0) || (local_210 != DAT_1800562a8)) &&
                ((local_218 != DAT_1800562c0 || (local_210 != DAT_1800562c8)))) &&
               ((local_218 != DAT_1800562d0 || (local_210 != DAT_1800562d8)))) &&
              (((local_218 != DAT_1800562e0 || (local_210 != DAT_1800562e8)) &&
               ((((local_218 != DAT_1800562f0 || (local_210 != DAT_1800562f8)) &&
                 ((local_218 != DAT_180056300 || (local_210 != DAT_180056308)))) &&
                ((local_218 != DAT_180056310 || (local_210 != DAT_180056318)))))))) &&
             ((((((local_218 != DAT_180056320 || (local_210 != DAT_180056328)) &&
                 (((local_218 != DAT_180056330 || (local_210 != DAT_180056338)) &&
                  ((local_218 != DAT_180056340 || (local_210 != DAT_180056348)))))) &&
                ((((local_218 != DAT_180056350 || (local_210 != DAT_180056358)) &&
                  ((local_218 != DAT_180056360 || (local_210 != DAT_180056368)))) &&
                 ((((local_218 != DAT_180056370 || (local_210 != DAT_180056378)) &&
                   ((local_218 != DAT_180056380 || (local_210 != DAT_180056388)))) &&
                  ((local_218 != DAT_180056390 || (local_210 != DAT_180056398)))))))) &&
               ((local_218 != DAT_1800563a0 || (local_210 != DAT_1800563a8)))) &&
              ((((local_218 != DAT_1800563b0 || (local_210 != DAT_1800563b8)) &&
                ((local_218 != DAT_1800563c0 || (local_210 != DAT_1800563c8)))) &&
               (((local_218 != DAT_1800563d0 || (local_210 != DAT_1800563d8)) &&
                ((local_218 != DAT_1800563e0 || (local_210 != DAT_1800563e8)))))))))) &&
            (((((local_218 != DAT_1800563f0 || (local_210 != DAT_1800563f8)) &&
               ((local_218 != DAT_180056400 || (local_210 != DAT_180056408)))) &&
              ((local_218 != DAT_180056410 || (local_210 != DAT_180056418)))) &&
             ((local_218 != DAT_180056420 || (local_210 != DAT_180056428)))))) ||
           (iVar6 = (**(code **)(*(longlong *)local_240 + 0x20))(local_240,0), iVar6 < 0))
        goto LAB_1800121c4;
        lVar2 = *(longlong *)local_240;
        pcVar13 = ATL::CSimpleStringT<char,1>::GetBuffer
                            ((CSimpleStringT<char,1> *)&local_248,*(int *)(local_248 + -0x10));
        (**(code **)(lVar2 + 0x40))(local_240,pcVar13);
        (*(code *)**(undefined8 **)local_240)(local_240,&DAT_180057a98,&local_250);
        (**(code **)(*(longlong *)local_250 + 0x38))();
        (**(code **)(*(longlong *)local_250 + 0x40))(local_250,0);
        (**(code **)(*(longlong *)local_250 + 0x10))();
        (**(code **)(*(longlong *)local_240 + 0x20))(local_240,1);
      }
      if (!bVar21) {
        APModLibRegisterLib(local_248,*(char **)param_1,0,0);
      }
      pCVar14 = operator_new(0x10);
      pCVar17 = pCVar16;
      local_218 = (IAEditCategories *)pCVar14;
      if (pCVar14 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar14);
        *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)(pCVar14 + 8) = pCVar16;
        pCVar17 = pCVar14;
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                (pCVar17,local_248);
      FUN_1800164b0((longlong)pCVar17,(longlong *)local_240);
      CPtrArray::InsertAt((CPtrArray *)(this + 8),(longlong)local_238,pCVar17,1);
      local_230 = (IAEditCategories *)pCVar16;
      iVar6 = (*(code *)**(undefined8 **)local_240)(local_240,&DAT_180056230,&local_230);
      if (-1 < iVar6) {
        AddPaletteCategories
                  (this,(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_248,
                   local_230);
        (**(code **)(*(longlong *)local_230 + 0x10))();
        local_230 = (IAEditCategories *)pCVar16;
        if (0 < (longlong)uVar19) {
          do {
            operator_delete__(*(void **)((longlong)pvVar10 + (longlong)pCVar16 * 8));
            pCVar16 = pCVar16 + 1;
          } while ((longlong)pCVar16 < (longlong)uVar19);
        }
        operator_delete__(pvVar10);
        bVar21 = param_5 == 0;
LAB_180012730:
        if (!bVar21) {
          PostMainWndMessage2(0x565,0,0);
        }
        bVar21 = true;
        goto LAB_1800121c6;
      }
    }
  }
LAB_1800121c4:
  bVar21 = false;
LAB_1800121c6:
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_220);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_248);
  return bVar21;
code_r0x00018001209a:
  pCVar16 = pCVar16 + 1;
  iVar6 = CountLibraries(this);
  pCVar14 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
            (ulonglong)(iVar20 + 1U);
  if (iVar6 <= (int)(iVar20 + 1U)) goto LAB_1800120ae;
  goto LAB_180012026;
}

/* ---- FUNC 00012750 IsLibraryNameUnique (358 bytes) ---- */

/* public: bool __cdecl CApwnLibraries::IsLibraryNameUnique(class ATL::CStringT<char,class
   StrTraitMFC_DLL<char,class ATL::ChTraitsCRT<char> > > const & __ptr64) __ptr64 */

bool __thiscall
CApwnLibraries::IsLibraryNameUnique
          (CApwnLibraries *this,
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_1)

{
  undefined1 auVar1 [16];
  int iVar2;
  DWORD DVar3;
  __uint64 _Var4;
  void *pvVar5;
  void *pvVar6;
  ulonglong uVar7;
  uint uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res18 [8];
  
                    /* 0x12750  126
                       ?IsLibraryNameUnique@CApwnLibraries@@QEAA_NAEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Z
                        */
  uVar7 = 0;
  iVar2 = CountLibraries(this);
  uVar10 = uVar7;
  uVar9 = uVar7;
  if (0 < iVar2) {
    do {
      if (((longlong)uVar9 < 0) || (*(longlong *)(this + 0x18) <= (longlong)uVar9)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                (local_res18,
                 *(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> **)
                  (*(longlong *)(this + 0x10) + uVar9 * 8));
      iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                        (local_res18,*(char **)param_1);
      if (iVar2 == 0) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res18);
        return false;
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res18);
      uVar8 = (int)uVar10 + 1;
      iVar2 = CountLibraries(this);
      uVar10 = (ulonglong)uVar8;
      uVar9 = uVar9 + 1;
    } while ((int)uVar8 < iVar2);
  }
  DVar3 = APModLibCount();
  uVar10 = (ulonglong)(int)DVar3;
  auVar1._8_8_ = 0;
  auVar1._0_8_ = uVar10;
  _Var4 = SUB168(ZEXT816(8) * auVar1,0);
  if (SUB168(ZEXT816(8) * auVar1,8) != 0) {
    _Var4 = 0xffffffffffffffff;
  }
  pvVar5 = operator_new__(_Var4);
  uVar9 = uVar7;
  if ((int)DVar3 < 1) {
    APModLibListLibs((longlong)pvVar5,DVar3,0x40);
  }
  else {
    do {
      pvVar6 = operator_new__(0x40);
      *(void **)((longlong)pvVar5 + uVar9 * 8) = pvVar6;
      uVar9 = uVar9 + 1;
    } while ((longlong)uVar9 < (longlong)uVar10);
    APModLibListLibs((longlong)pvVar5,DVar3,0x40);
    uVar9 = uVar7;
    do {
      iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                        (param_1,*(char **)((longlong)pvVar5 + uVar9 * 8));
      if (iVar2 == 0) {
        return false;
      }
      uVar9 = uVar9 + 1;
    } while ((longlong)uVar9 < (longlong)uVar10);
    do {
      operator_delete__(*(void **)((longlong)pvVar5 + uVar7 * 8));
      uVar7 = uVar7 + 1;
    } while ((longlong)uVar7 < (longlong)uVar10);
  }
  operator_delete__(pvVar5);
  return true;
}

/* ---- FUNC 000128C0 IsReservedDisplayName (77 bytes) ---- */

/* public: int __cdecl CApwnLibraries::IsReservedDisplayName(char const * __ptr64) __ptr64 */

int __thiscall CApwnLibraries::IsReservedDisplayName(CApwnLibraries *this,char *param_1)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  uint uVar4;
  undefined **ppuVar5;
  
                    /* 0x128c0  127  ?IsReservedDisplayName@CApwnLibraries@@QEAAHPEBD@Z */
  ppuVar5 = &m_ReservedList;
  uVar4 = 0;
  do {
    pcVar3 = param_1;
    do {
      cVar1 = *pcVar3;
      cVar2 = pcVar3[(longlong)*ppuVar5 - (longlong)param_1];
      if (cVar1 != cVar2) break;
      pcVar3 = pcVar3 + 1;
    } while (cVar2 != '\0');
    if (cVar1 == cVar2) {
      return 1;
    }
    uVar4 = uVar4 + 1;
    ppuVar5 = ppuVar5 + 1;
    if (6 < uVar4) {
      return 0;
    }
  } while( true );
}

/* ---- FUNC 00012910 MergeCategories (287 bytes) ---- */

/* public: void __cdecl CApwnLibraries::MergeCategories(class CNameAndStateArray & __ptr64) __ptr64
    */

void __thiscall CApwnLibraries::MergeCategories(CApwnLibraries *this,CNameAndStateArray *param_1)

{
  ulonglong uVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong lVar4;
  int iVar5;
  
                    /* 0x12910  152
                       ?MergeCategories@CApwnLibraries@@QEAAXAEAVCNameAndStateArray@@@Z */
  iVar5 = 0;
  lVar4 = *(longlong *)(param_1 + 0x10);
  if (0 < lVar4) {
    lVar3 = 0;
    do {
      if ((lVar3 < 0) || (lVar4 <= lVar3)) goto LAB_180012a2a;
      uVar1 = FUN_180010240((longlong)(this + 0x30),
                            *(undefined8 **)(*(longlong *)(param_1 + 8) + lVar3 * 8));
      if ((int)uVar1 < 0) {
        plVar2 = operator_new(0x48);
        if (plVar2 == (longlong *)0x0) {
          plVar2 = (longlong *)0x0;
        }
        else {
          *plVar2 = (longlong)CPaletteCategory::vftable;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(plVar2 + 2));
          CPtrArray::CPtrArray((CPtrArray *)(plVar2 + 3));
          *(undefined ***)(plVar2 + 3) = CModelTypeArray::vftable;
          *(undefined4 *)(plVar2 + 1) = 1;
          *(undefined4 *)(plVar2 + 8) = 1;
        }
        if (*(longlong *)(param_1 + 0x10) <= lVar3) {
LAB_180012a2a:
                    /* WARNING: Subroutine does not return */
          AfxThrowInvalidArgException();
        }
        (**(code **)(*plVar2 + 0x20))
                  (plVar2,**(undefined8 **)(*(longlong *)(param_1 + 8) + lVar3 * 8));
        if (*(longlong *)(param_1 + 0x10) <= lVar3) goto LAB_180012a2a;
        *(undefined4 *)(plVar2 + 8) =
             *(undefined4 *)(*(longlong *)(*(longlong *)(param_1 + 8) + lVar3 * 8) + 8);
        CPtrArray::SetAtGrow((CPtrArray *)(this + 0x30),*(__int64 *)(this + 0x40),plVar2);
      }
      iVar5 = iVar5 + 1;
      lVar3 = lVar3 + 1;
      lVar4 = *(longlong *)(param_1 + 0x10);
    } while (iVar5 < lVar4);
  }
  return;
}

/* ---- FUNC 00012A30 MergeLibraries (160 bytes) ---- */

/* public: int __cdecl CApwnLibraries::MergeLibraries(class CStringArray const & __ptr64) __ptr64 */

int __thiscall CApwnLibraries::MergeLibraries(CApwnLibraries *this,CStringArray *param_1)

{
  int iVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  
                    /* 0x12a30  153  ?MergeLibraries@CApwnLibraries@@QEAAHAEBVCStringArray@@@Z
                       0x12a30  154  ?MergeLibs@CApwnLibraries@@QEAAHAEBVCStringArray@@@Z */
  lVar5 = *(longlong *)(param_1 + 0x10);
  iVar3 = 0;
  iVar4 = 0;
  if (0 < lVar5) {
    lVar2 = 0;
    do {
      if ((lVar2 < 0) || (lVar5 <= lVar2)) {
LAB_180012acb:
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      iVar1 = FUN_180010330((longlong)(this + 8),*(char **)(*(longlong *)(param_1 + 8) + lVar2 * 8))
      ;
      if (iVar1 < 0) {
        if (*(longlong *)(param_1 + 0x10) <= lVar2) goto LAB_180012acb;
        iVar1 = AddNewLibrary(this,*(char **)(*(longlong *)(param_1 + 8) + lVar2 * 8),0);
        if (iVar1 != 0) {
          iVar3 = iVar1;
        }
      }
      lVar5 = *(longlong *)(param_1 + 0x10);
      iVar4 = iVar4 + 1;
      lVar2 = lVar2 + 1;
    } while (iVar4 < lVar5);
  }
  return iVar3;
}

/* ---- FUNC 00012AE0 MoveCategory (62 bytes) ---- */

/* public: bool __cdecl CApwnLibraries::MoveCategory(short,short,int) __ptr64 */

bool __thiscall
CApwnLibraries::MoveCategory(CApwnLibraries *this,short param_1,short param_2,int param_3)

{
  longlong lVar1;
  void *pvVar2;
  bool bVar3;
  
                    /* 0x12ae0  155  ?MoveCategory@CApwnLibraries@@QEAA_NFFH@Z */
  if (-1 < param_1) {
    if ((((int)param_1 < *(int *)(this + 0x40) + -1) && (-1 < param_2)) &&
       ((int)param_2 < *(int *)(this + 0x40) + -1)) {
      lVar1 = (longlong)param_1 + 1;
      if (*(longlong *)(this + 0x40) <= lVar1) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      pvVar2 = *(void **)(*(longlong *)(this + 0x38) + lVar1 * 8);
      bVar3 = pvVar2 != (void *)0x0;
      if (bVar3) {
        CPtrArray::RemoveAt((CPtrArray *)(this + 0x30),lVar1,1);
        CPtrArray::InsertAt((CPtrArray *)(this + 0x30),(ulonglong)((int)param_2 + 1),pvVar2,1);
      }
      if ((param_3 != 0) && (bVar3)) {
        PostMainWndMessage2(0x565,0,0);
      }
      return bVar3;
    }
  }
  return false;
}

/* ---- FUNC 00012B1E FUN_180012b1e (30 bytes) ---- */

bool FUN_180012b1e(longlong param_1)

{
  longlong lVar1;
  void *pvVar2;
  int unaff_EBP;
  int unaff_ESI;
  longlong in_R10;
  bool bVar3;
  
  lVar1 = in_R10 + 1;
  if (*(longlong *)(param_1 + 0x40) <= lVar1) {
                    /* WARNING: Subroutine does not return */
    AfxThrowInvalidArgException();
  }
  pvVar2 = *(void **)(*(longlong *)(param_1 + 0x38) + lVar1 * 8);
  bVar3 = pvVar2 != (void *)0x0;
  if (bVar3) {
    CPtrArray::RemoveAt((CPtrArray *)(param_1 + 0x30),lVar1,1);
    CPtrArray::InsertAt((CPtrArray *)(param_1 + 0x30),(ulonglong)(unaff_ESI + 1),pvVar2,1);
  }
  if ((unaff_EBP != 0) && (bVar3)) {
    PostMainWndMessage2(0x565,0,0);
  }
  return bVar3;
}

/* ---- FUNC 00012B3C FUN_180012b3c (61 bytes) ---- */

char FUN_180012b3c(undefined8 param_1,longlong param_2)

{
  void *pvVar1;
  longlong in_RAX;
  char unaff_BL;
  int unaff_EBP;
  int unaff_ESI;
  CPtrArray *unaff_R14;
  
  pvVar1 = *(void **)(in_RAX + param_2 * 8);
  if (pvVar1 == (void *)0x0) {
    unaff_BL = '\0';
  }
  else {
    CPtrArray::RemoveAt(unaff_R14,param_2,1);
    CPtrArray::InsertAt(unaff_R14,(ulonglong)(unaff_ESI + 1),pvVar1,1);
  }
  if ((unaff_EBP != 0) && (unaff_BL == '\x01')) {
    PostMainWndMessage2(0x565,0,0);
  }
  return unaff_BL;
}

/* ---- FUNC 00012B79 FUN_180012b79 (44 bytes) ---- */

char FUN_180012b79(void)

{
  char unaff_BL;
  
  if (unaff_BL == '\x01') {
    PostMainWndMessage2(0x565,0,0);
  }
  return unaff_BL;
}

/* ---- FUNC 00012BA5 FUN_180012ba5 (13 bytes) ---- */

undefined1 FUN_180012ba5(void)

{
  return 0;
}

/* ---- FUNC 00012BB2 AfxThrowInvalidArgException (5 bytes) ---- */

void __cdecl AfxThrowInvalidArgException(void)

{
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 00012BC0 MoveLibrary (171 bytes) ---- */

/* public: bool __cdecl CApwnLibraries::MoveLibrary(short,short,int) __ptr64 */

bool __thiscall
CApwnLibraries::MoveLibrary(CApwnLibraries *this,short param_1,short param_2,int param_3)

{
  void *pvVar1;
  longlong lVar2;
  bool bVar3;
  
                    /* 0x12bc0  156  ?MoveLibrary@CApwnLibraries@@QEAA_NFFH@Z */
  if ((((-1 < param_1) && ((int)param_1 < *(int *)(this + 0x18))) && (-1 < param_2)) &&
     ((int)param_2 < *(int *)(this + 0x18))) {
    lVar2 = (longlong)param_1;
    if (*(longlong *)(this + 0x18) <= lVar2) {
                    /* WARNING: Subroutine does not return */
      AfxThrowInvalidArgException();
    }
    pvVar1 = *(void **)(*(longlong *)(this + 0x10) + lVar2 * 8);
    if (pvVar1 != (void *)0x0) {
      CPtrArray::RemoveAt((CPtrArray *)(this + 8),lVar2,1);
      CPtrArray::InsertAt((CPtrArray *)(this + 8),(longlong)param_2,pvVar1,1);
      bVar3 = true;
      goto LAB_180012c36;
    }
  }
  bVar3 = false;
LAB_180012c36:
  if ((param_3 != 0) && (bVar3 == true)) {
    PostMainWndMessage2(0x565,0,0);
  }
  return bVar3;
}

/* ---- FUNC 00012C70 FUN_180012c70 (47 bytes) ---- */

ulonglong FUN_180012c70(longlong param_1,uint param_2,longlong *param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  longlong *plVar3;
  uint uVar4;
  
  if (param_2 == 0) {
    return 0x80070057;
  }
  uVar1 = *(uint *)(param_1 + 0x34);
  uVar4 = 0;
  do {
    uVar2 = *(uint *)(param_1 + 0x38);
    if (uVar1 <= uVar2) break;
    if (*(longlong *)(param_1 + 0x18) <= (longlong)(ulonglong)uVar2) {
                    /* WARNING: Subroutine does not return */
      AfxThrowInvalidArgException();
    }
    plVar3 = *(longlong **)(*(longlong *)(param_1 + 0x10) + (ulonglong)uVar2 * 8);
    *param_3 = (longlong)plVar3;
    if (plVar3 == (longlong *)0x0) {
      return 0x80004005;
    }
    (**(code **)(*plVar3 + 8))();
    *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + 1;
    uVar4 = uVar4 + 1;
    param_3 = param_3 + 1;
  } while (uVar4 < param_2);
  if (param_4 != (uint *)0x0) {
    *param_4 = uVar4;
  }
  return (ulonglong)(uVar4 != param_2);
}

/* ---- FUNC 00012C9F FUN_180012c9f (135 bytes) ---- */

ulonglong FUN_180012c9f(longlong param_1)

{
  uint uVar1;
  uint uVar2;
  longlong *plVar3;
  longlong unaff_RBX;
  uint unaff_EBP;
  longlong *unaff_RSI;
  uint uVar4;
  uint *unaff_R12;
  
  uVar1 = *(uint *)(param_1 + 0x34);
  uVar4 = 0;
  do {
    uVar2 = *(uint *)(unaff_RBX + 0x38);
    if (uVar1 <= uVar2) break;
    if (*(longlong *)(unaff_RBX + 0x18) <= (longlong)(ulonglong)uVar2) {
                    /* WARNING: Subroutine does not return */
      AfxThrowInvalidArgException();
    }
    plVar3 = *(longlong **)(*(longlong *)(unaff_RBX + 0x10) + (ulonglong)uVar2 * 8);
    *unaff_RSI = (longlong)plVar3;
    if (plVar3 == (longlong *)0x0) {
      return 0x80004005;
    }
    (**(code **)(*plVar3 + 8))();
    *(int *)(unaff_RBX + 0x38) = *(int *)(unaff_RBX + 0x38) + 1;
    uVar4 = uVar4 + 1;
    unaff_RSI = unaff_RSI + 1;
  } while (uVar4 < unaff_EBP);
  if (unaff_R12 != (uint *)0x0) {
    *unaff_R12 = uVar4;
  }
  return (ulonglong)(uVar4 != unaff_EBP);
}

/* ---- FUNC 00012D1A FUN_180012d1a (7 bytes) ---- */

undefined8 FUN_180012d1a(void)

{
  return 0x80004005;
}

/* ---- FUNC 00012D30 FUN_180012d30 (47 bytes) ---- */

ulonglong FUN_180012d30(longlong param_1,uint param_2,longlong *param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  
  if (param_2 == 0) {
    return 0x80070057;
  }
  OutputDebugStringA("CImpEnumAModelType::Next......");
  uVar1 = *(uint *)(param_1 + 0x10);
  uVar2 = 0;
  do {
    if (uVar1 <= *(uint *)(param_1 + 0x14)) break;
    OutputDebugStringA("m_modelTypes[m_nIndex]...... before");
    if (*(longlong *)(*(longlong *)(param_1 + 8) + 0x10) <=
        (longlong)(ulonglong)*(uint *)(param_1 + 0x14)) {
                    /* WARNING: Subroutine does not return */
      AfxThrowInvalidArgException();
    }
    *param_3 = *(longlong *)
                (*(longlong *)(*(longlong *)(param_1 + 8) + 8) +
                (ulonglong)*(uint *)(param_1 + 0x14) * 8);
    OutputDebugStringA("m_modelTypes[m_nIndex]...... After");
    if (*param_3 == 0) {
      return 0x80004005;
    }
    OutputDebugStringA("(*ppModelType)->AddRef()...... before");
    (**(code **)(*(longlong *)*param_3 + 8))();
    OutputDebugStringA("(*ppModelType)->AddRef()...... After");
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    uVar2 = uVar2 + 1;
    param_3 = param_3 + 1;
  } while (uVar2 < param_2);
  if (param_4 != (uint *)0x0) {
    *param_4 = uVar2;
  }
  return (ulonglong)(uVar2 != param_2);
}

/* ---- FUNC 00012D5F FUN_180012d5f (210 bytes) ---- */

ulonglong FUN_180012d5f(void)

{
  uint uVar1;
  longlong unaff_RBX;
  uint unaff_EBP;
  uint uVar2;
  longlong *unaff_RDI;
  uint *unaff_R12;
  
  OutputDebugStringA("CImpEnumAModelType::Next......");
  uVar1 = *(uint *)(unaff_RBX + 0x10);
  uVar2 = 0;
  do {
    if (uVar1 <= *(uint *)(unaff_RBX + 0x14)) break;
    OutputDebugStringA("m_modelTypes[m_nIndex]...... before");
    if (*(longlong *)(*(longlong *)(unaff_RBX + 8) + 0x10) <=
        (longlong)(ulonglong)*(uint *)(unaff_RBX + 0x14)) {
                    /* WARNING: Subroutine does not return */
      AfxThrowInvalidArgException();
    }
    *unaff_RDI = *(longlong *)
                  (*(longlong *)(*(longlong *)(unaff_RBX + 8) + 8) +
                  (ulonglong)*(uint *)(unaff_RBX + 0x14) * 8);
    OutputDebugStringA("m_modelTypes[m_nIndex]...... After");
    if (*unaff_RDI == 0) {
      return 0x80004005;
    }
    OutputDebugStringA("(*ppModelType)->AddRef()...... before");
    (**(code **)(*(longlong *)*unaff_RDI + 8))();
    OutputDebugStringA("(*ppModelType)->AddRef()...... After");
    *(int *)(unaff_RBX + 0x14) = *(int *)(unaff_RBX + 0x14) + 1;
    uVar2 = uVar2 + 1;
    unaff_RDI = unaff_RDI + 1;
  } while (uVar2 < unaff_EBP);
  if (unaff_R12 != (uint *)0x0) {
    *unaff_R12 = uVar2;
  }
  return (ulonglong)(uVar2 != unaff_EBP);
}

/* ---- FUNC 00012E25 FUN_180012e25 (7 bytes) ---- */

undefined8 FUN_180012e25(void)

{
  return 0x80004005;
}

/* ---- FUNC 00012E40 QueryInterface (87 bytes) ---- */

/* public: virtual long __cdecl CApwnLibraries::QueryInterface(struct _GUID const & __ptr64,void *
   __ptr64 * __ptr64) __ptr64 */

long __thiscall CApwnLibraries::QueryInterface(CApwnLibraries *this,_GUID *param_1,void **param_2)

{
  longlong lVar1;
  longlong lVar2;
  
                    /* 0x12e40  158  ?QueryInterface@CApwnLibraries@@UEAAJAEBU_GUID@@PEAPEAX@Z */
  *param_2 = (void *)0x0;
  lVar1._0_4_ = param_1->Data1;
  lVar1._4_2_ = param_1->Data2;
  lVar1._6_2_ = param_1->Data3;
  if (((lVar1 != DAT_180057a58) || (*(longlong *)param_1->Data4 != DAT_180057a60)) &&
     ((lVar2._0_4_ = param_1->Data1, lVar2._4_2_ = param_1->Data2, lVar2._6_2_ = param_1->Data3,
      lVar2 != DAT_180056230 || (*(longlong *)param_1->Data4 != DAT_180056238)))) {
    return -0x7fffbffe;
  }
  *param_2 = this;
  (**(code **)(*(longlong *)this + 8))();
  return 0;
}

/* ---- FUNC 00012EA0 FUN_180012ea0 (87 bytes) ---- */

undefined8 FUN_180012ea0(longlong *param_1,longlong *param_2,undefined8 *param_3)

{
  *param_3 = 0;
  if (((*param_2 != DAT_180057a58) || (param_2[1] != DAT_180057a60)) &&
     ((*param_2 != DAT_180056220 || (param_2[1] != DAT_180056228)))) {
    return 0x80004002;
  }
  *param_3 = param_1;
  (**(code **)(*param_1 + 8))();
  return 0;
}

/* ---- FUNC 00012F00 FUN_180012f00 (87 bytes) ---- */

undefined8 FUN_180012f00(longlong *param_1,longlong *param_2,undefined8 *param_3)

{
  *param_3 = 0;
  if (((*param_2 != DAT_180057a58) || (param_2[1] != DAT_180057a60)) &&
     ((*param_2 != DAT_1800561d0 || (param_2[1] != DAT_1800561d8)))) {
    return 0x80004002;
  }
  *param_3 = param_1;
  (**(code **)(*param_1 + 8))();
  return 0;
}

/* ---- FUNC 00012F60 FUN_180012f60 (87 bytes) ---- */

undefined8 FUN_180012f60(longlong *param_1,longlong *param_2,undefined8 *param_3)

{
  *param_3 = 0;
  if (((*param_2 != DAT_180057a58) || (param_2[1] != DAT_180057a60)) &&
     ((*param_2 != DAT_180056210 || (param_2[1] != DAT_180056218)))) {
    return 0x80004002;
  }
  *param_3 = param_1;
  (**(code **)(*param_1 + 8))();
  return 0;
}

/* ---- FUNC 00012FC0 FUN_180012fc0 (14 bytes) ---- */

void FUN_180012fc0(longlong *param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)*param_1;
  *param_1 = *param_1 + 4;
  return;
}

/* ---- FUNC 00012FD0 FUN_180012fd0 (163 bytes) ---- */

undefined8 FUN_180012fd0(longlong *param_1,longlong param_2)

{
  int iVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  int iVar4;
  ulonglong uVar5;
  char local_res8 [8];
  
  if (param_1 == (longlong *)0x0) {
LAB_180013058:
    uVar2 = 0xffffffff;
  }
  else {
    uVar3 = 0;
    uVar5 = uVar3;
    do {
      iVar4 = (int)uVar5;
      iVar1 = (**(code **)(*param_1 + 0x18))(param_1,local_res8,1);
      if (iVar1 != 0) goto LAB_180013058;
      if (local_res8[0] == '\t') {
        iVar4 = iVar4 + -1;
        uVar3 = uVar3 - 1;
      }
      else {
        *(char *)(uVar3 + param_2) = local_res8[0];
        if (local_res8[0] == '\n') {
          *(undefined1 *)((longlong)(iVar4 + -1) + 1 + param_2) = 0;
          return 0;
        }
      }
      uVar5 = (ulonglong)(iVar4 + 1U);
      uVar3 = uVar3 + 1;
    } while ((longlong)uVar3 < 0x91);
    *(undefined1 *)((longlong)(int)(iVar4 + 1U) + 1 + param_2) = 0;
    uVar2 = 0;
  }
  return uVar2;
}

/* ---- FUNC 00013080 FUN_180013080 (68 bytes) ---- */

void FUN_180013080(longlong *param_1,void *param_2)

{
  int *_Src;
  size_t _Size;
  
  _Size = (size_t)*(int *)*param_1;
  _Src = (int *)*param_1 + 1;
  *param_1 = (longlong)_Src;
  memcpy(param_2,_Src,_Size);
  *(undefined1 *)(_Size + (longlong)param_2) = 0;
  *param_1 = *param_1 + _Size;
  return;
}

/* ---- FUNC 000130D0 RebuildCategoryInfo (114 bytes) ---- */

/* public: void __cdecl CApwnLibraries::RebuildCategoryInfo(void) __ptr64 */

void __thiscall CApwnLibraries::RebuildCategoryInfo(CApwnLibraries *this)

{
  undefined **local_58 [5];
  CStringArray local_30 [40];
  
                    /* 0x130d0  159  ?RebuildCategoryInfo@CApwnLibraries@@QEAAXXZ */
  CPtrArray::CPtrArray((CPtrArray *)local_58);
  local_58[0] = CNameAndStateArray::vftable;
  CStringArray::CStringArray(local_30);
  BuildCategoryInfo(this,(CNameAndStateArray *)local_58);
  BuildLibraryInfo(this,local_30);
  ReconcileLibs(this,local_30,(CNameAndStateArray *)local_58);
  CStringArray::~CStringArray(local_30);
  CNameAndStateArray::~CNameAndStateArray((CNameAndStateArray *)local_58);
  return;
}

/* ---- FUNC 00013150 ReconcileLibs (494 bytes) ---- */

/* public: int __cdecl CApwnLibraries::ReconcileLibs(class CStringArray const & __ptr64,class
   CNameAndStateArray & __ptr64) __ptr64 */

int __thiscall
CApwnLibraries::ReconcileLibs
          (CApwnLibraries *this,CStringArray *param_1,CNameAndStateArray *param_2)

{
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar1;
  longlong *plVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  longlong lVar6;
  int iVar7;
  int iVar8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res20 [8];
  
                    /* 0x13150  160
                       ?ReconcileLibs@CApwnLibraries@@QEAAHAEBVCStringArray@@AEAVCNameAndStateArray@@@Z
                        */
  iVar7 = 0;
  iVar3 = CountLibraries(this);
  if (0 < iVar3) {
    lVar5 = 0;
    do {
      if ((lVar5 < 0) || (*(longlong *)(this + 0x18) <= lVar5)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      CPtrArray::SetAtGrow
                ((CPtrArray *)(this + 0x58),*(__int64 *)(this + 0x68),
                 *(void **)(*(longlong *)(this + 0x10) + lVar5 * 8));
      iVar7 = iVar7 + 1;
      lVar5 = lVar5 + 1;
      iVar3 = CountLibraries(this);
    } while (iVar7 < iVar3);
  }
  CPtrArray::SetSize((CPtrArray *)(this + 8),0,-1);
  FUN_1800138b0((CPtrArray *)(this + 0x30));
  FUN_180013f80((longlong *)(this + 0x90));
  AddStreamCategory(this);
  MergeCategories(this,param_2);
  iVar3 = AddLibraries(this,(CLibraryArray *)(this + 0x58),param_1);
  FUN_180013920((CPtrArray *)(this + 0x30));
  UpdateLibCache(this);
  iVar8 = 0;
  iVar7 = CountLibraries(this);
  if (0 < iVar7) {
    lVar5 = 0;
    do {
      if ((lVar5 < 0) || (*(longlong *)(this + 0x18) <= lVar5)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      pCVar1 = *(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> **)
                (*(longlong *)(this + 0x10) + lVar5 * 8);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res20,pCVar1);
      iVar7 = 0;
      lVar6 = 0;
      if (0 < DAT_18007a028) {
        do {
          if ((lVar6 < 0) || (DAT_18007a028 <= lVar6)) {
                    /* WARNING: Subroutine does not return */
            AfxThrowInvalidArgException();
          }
          iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                            (local_res20,*(char **)(DAT_18007a020 + lVar6 * 8));
          if (iVar4 == 0) goto LAB_1800132c1;
          iVar7 = iVar7 + 1;
          lVar6 = lVar6 + 1;
        } while (iVar7 < DAT_18007a028);
      }
      CStringArray::SetAtGrow(&m_InitializedLibraries,DAT_18007a028,local_res20);
LAB_1800132c1:
      plVar2 = *(longlong **)(pCVar1 + 8);
      if (plVar2 != (longlong *)0x0) {
        (**(code **)(*plVar2 + 8))(plVar2);
      }
      FUN_180015f90(plVar2);
      if (plVar2 != (longlong *)0x0) {
        (**(code **)(*plVar2 + 0x10))(plVar2);
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res20);
      iVar8 = iVar8 + 1;
      lVar5 = lVar5 + 1;
      iVar7 = CountLibraries(this);
    } while (iVar8 < iVar7);
  }
  return iVar3;
}

/* ---- FUNC 00013340 Refresh (1004 bytes) ---- */

/* public: void __cdecl CApwnLibraries::Refresh(void) __ptr64 */

void __thiscall CApwnLibraries::Refresh(CApwnLibraries *this)

{
  CPtrArray *pCVar1;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar2;
  int iVar3;
  char *pcVar4;
  ulonglong uVar5;
  longlong *plVar6;
  longlong lVar7;
  int iVar8;
  longlong lVar9;
  undefined4 local_res8 [2];
  IACategory *local_res10;
  undefined8 local_res18;
  longlong *local_res20;
  longlong *local_a8;
  undefined8 local_a0;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_98;
  longlong local_90;
  CPtrArray *local_88;
  undefined **local_80;
  longlong local_78;
  longlong local_70;
  longlong *local_58;
  longlong *local_50;
  
                    /* 0x13340  161  ?Refresh@CApwnLibraries@@QEAAXXZ */
  CPtrArray::CPtrArray((CPtrArray *)&local_80);
  local_80 = CCategoryArray::vftable;
  CPtrArray::Copy((CPtrArray *)&local_80,(CPtrArray *)(this + 0x30));
  iVar8 = *(int *)(this + 0x40);
  CPtrArray::SetSize((CPtrArray *)(this + 0x30),0,-1);
  FUN_180013f80((longlong *)(this + 0x90));
  lVar7 = (longlong)*(int *)(this + 0x18);
  local_90 = lVar7;
  if (0 < lVar7) {
    lVar9 = 0;
    do {
      if ((lVar9 < 0) || (*(longlong *)(this + 0x18) <= lVar9)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      pCVar2 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
                (*(longlong *)(this + 0x10) + lVar9 * 8);
      local_a8 = (longlong *)0x0;
      local_98 = pCVar2;
      iVar3 = (**(code **)**(undefined8 **)(pCVar2 + 8))
                        (*(undefined8 **)(pCVar2 + 8),&DAT_180056230,&local_a8);
      if (-1 < iVar3) {
        local_res20 = (longlong *)0x0;
        (**(code **)(*local_a8 + 0x30))(local_a8,&local_res20);
        local_res8[0] = 0;
        iVar3 = (**(code **)(*local_res20 + 0x18))(local_res20,1,&local_res10,local_res8);
        while (iVar3 == 0) {
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res18);
          lVar7 = *(longlong *)local_res10;
          pcVar4 = ATL::CSimpleStringT<char,1>::GetBuffer
                             ((CSimpleStringT<char,1> *)&local_res18,0x40);
          (**(code **)(lVar7 + 0x18))(local_res10,pcVar4,0x40);
          ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)&local_res18,-1);
          CacheModelTypes(this,pCVar2,
                          (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                          &local_res18,local_res10,1);
          uVar5 = FUN_180010240((longlong)(this + 0x30),&local_res18);
          iVar3 = (int)uVar5;
          if (iVar3 < 0) {
            uVar5 = FUN_180010240((longlong)&local_80,&local_res18);
            iVar3 = (int)uVar5;
            lVar7 = (longlong)iVar3;
            if (iVar3 < 0) {
              plVar6 = operator_new(0x48);
              local_50 = plVar6;
              if (plVar6 == (longlong *)0x0) {
                plVar6 = (longlong *)0x0;
              }
              else {
                *plVar6 = (longlong)CPaletteCategory::vftable;
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           (plVar6 + 2));
                pCVar1 = (CPtrArray *)(plVar6 + 3);
                local_88 = pCVar1;
                CPtrArray::CPtrArray(pCVar1);
                *(undefined ***)pCVar1 = CModelTypeArray::vftable;
                *(undefined4 *)(plVar6 + 1) = 1;
                *(undefined4 *)(plVar6 + 8) = 1;
              }
              (**(code **)(*plVar6 + 0x20))(plVar6,local_res18);
              FUN_180011e40((longlong)plVar6,(longlong *)local_res10,'\0');
              *(undefined4 *)(plVar6 + 8) = 1;
              CPtrArray::InsertAt((CPtrArray *)(this + 0x30),(longlong)iVar8,plVar6,1);
              iVar8 = iVar8 + 1;
            }
            else {
              plVar6 = operator_new(0x48);
              local_58 = plVar6;
              if (plVar6 == (longlong *)0x0) {
                plVar6 = (longlong *)0x0;
              }
              else {
                *plVar6 = (longlong)CPaletteCategory::vftable;
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           (plVar6 + 2));
                pCVar1 = (CPtrArray *)(plVar6 + 3);
                local_88 = pCVar1;
                CPtrArray::CPtrArray(pCVar1);
                *(undefined ***)pCVar1 = CModelTypeArray::vftable;
                *(undefined4 *)(plVar6 + 1) = 1;
                *(undefined4 *)(plVar6 + 8) = 1;
              }
              (**(code **)(*plVar6 + 0x20))(plVar6,local_res18);
              FUN_180011e40((longlong)plVar6,(longlong *)local_res10,'\0');
              if ((iVar3 < 0) || (local_70 <= lVar7)) goto LAB_180013721;
              *(undefined4 *)(plVar6 + 8) =
                   *(undefined4 *)(*(longlong *)(local_78 + lVar7 * 8) + 0x40);
              CPtrArray::SetAtGrow((CPtrArray *)(this + 0x30),lVar7,plVar6);
            }
          }
          else {
            if ((iVar3 < 0) || (*(longlong *)(this + 0x40) <= (longlong)iVar3)) {
LAB_180013721:
                    /* WARNING: Subroutine does not return */
              AfxThrowInvalidArgException();
            }
            lVar7 = *(longlong *)(*(longlong *)(this + 0x38) + (longlong)iVar3 * 8);
            FUN_180011e40(lVar7,(longlong *)local_res10,'\x01');
            *(undefined4 *)(lVar7 + 0x40) = 1;
          }
          (**(code **)(*(longlong *)local_res10 + 0x10))();
          local_res10 = (IACategory *)0x0;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res18);
          iVar3 = (**(code **)(*local_res20 + 0x18))(local_res20,1,&local_res10,local_res8);
          pCVar2 = local_98;
          lVar7 = local_90;
        }
        (**(code **)(*local_res20 + 0x10))();
        local_res20 = (longlong *)0x0;
        local_res10 = (IACategory *)0x0;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_a0,
                   "Uncategorized");
        iVar3 = (**(code **)(*local_a8 + 0x28))(local_a8,local_a0,&local_res10);
        if ((-1 < iVar3) && (local_res10 != (IACategory *)0x0)) {
          CacheModelTypes(this,pCVar2,
                          (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_a0
                          ,local_res10,0);
          (**(code **)(*(longlong *)local_res10 + 0x10))();
        }
        (**(code **)(*local_a8 + 0x10))();
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_a0);
      }
      lVar9 = lVar9 + 1;
    } while (lVar9 < lVar7);
  }
  FUN_180013920((CPtrArray *)(this + 0x30));
  FUN_1800138b0((CPtrArray *)&local_80);
  CPtrArray::~CPtrArray((CPtrArray *)&local_80);
  return;
}

/* ---- FUNC 00013730 Release (61 bytes) ---- */

/* public: virtual unsigned long __cdecl CApwnLibraries::Release(void) __ptr64 */

ulong __thiscall CApwnLibraries::Release(CApwnLibraries *this)

{
  ulong uVar1;
  
                    /* 0x13730  162  ?Release@CApwnLibraries@@UEAAKXZ */
  *(int *)(this + 0x80) = *(int *)(this + 0x80) + -1;
  uVar1 = *(ulong *)(this + 0x80);
  if (uVar1 == 0) {
    ~CApwnLibraries(this);
    operator_delete(this);
  }
  return uVar1;
}

/* ---- FUNC 00013770 FUN_180013770 (55 bytes) ---- */

int FUN_180013770(undefined8 *param_1)

{
  int iVar1;
  
  *(int *)(param_1 + 6) = *(int *)(param_1 + 6) + -1;
  iVar1 = *(int *)(param_1 + 6);
  if (iVar1 == 0) {
    FUN_18000d2f0(param_1);
    operator_delete(param_1);
  }
  return iVar1;
}

/* ---- FUNC 000137B0 FUN_1800137b0 (46 bytes) ---- */

int FUN_1800137b0(undefined8 *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 3) + -1;
  *(int *)(param_1 + 3) = iVar1;
  if (iVar1 == 0) {
    FUN_18000d380(param_1);
    operator_delete(param_1);
    iVar1 = 0;
  }
  return iVar1;
}

/* ---- FUNC 000137E0 FUN_1800137e0 (55 bytes) ---- */

int FUN_1800137e0(undefined8 *param_1)

{
  int iVar1;
  
  *(int *)(param_1 + 1) = *(int *)(param_1 + 1) + -1;
  iVar1 = *(int *)(param_1 + 1);
  if (iVar1 == 0) {
    FUN_18000d530(param_1);
    operator_delete(param_1);
  }
  return iVar1;
}

/* ---- FUNC 00013820 RemoveAndDeleteAll (137 bytes) ---- */

/* public: void __cdecl CNameAndStateArray::RemoveAndDeleteAll(void) __ptr64 */

void __thiscall CNameAndStateArray::RemoveAndDeleteAll(CNameAndStateArray *this)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this_00;
  longlong lVar1;
  ulonglong uVar2;
  uint uVar3;
  ulonglong uVar4;
  
                    /* 0x13820  165  ?RemoveAndDeleteAll@CNameAndStateArray@@QEAAXXZ */
  lVar1 = *(longlong *)(this + 0x10);
  uVar2 = 0;
  uVar4 = uVar2;
  if (0 < lVar1) {
    do {
      if (((longlong)uVar2 < 0) || (lVar1 <= (longlong)uVar2)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      this_00 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
                 (*(longlong *)(this + 8) + uVar2 * 8);
      if (this_00 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(this_00);
        operator_delete(this_00);
      }
      lVar1 = *(longlong *)(this + 0x10);
      uVar3 = (int)uVar4 + 1;
      uVar2 = uVar2 + 1;
      uVar4 = (ulonglong)uVar3;
    } while ((int)uVar3 < lVar1);
  }
  CPtrArray::SetSize((CPtrArray *)this,0,-1);
  return;
}

/* ---- FUNC 000138B0 FUN_1800138b0 (107 bytes) ---- */

void FUN_1800138b0(CPtrArray *param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  uint uVar3;
  ulonglong uVar4;
  
  lVar1 = *(longlong *)(param_1 + 0x10);
  uVar2 = 0;
  uVar4 = uVar2;
  if (0 < lVar1) {
    do {
      if (((longlong)uVar2 < 0) || (lVar1 <= (longlong)uVar2)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      (**(code **)(**(longlong **)(*(longlong *)(param_1 + 8) + uVar2 * 8) + 0x10))();
      lVar1 = *(longlong *)(param_1 + 0x10);
      uVar3 = (int)uVar4 + 1;
      uVar2 = uVar2 + 1;
      uVar4 = (ulonglong)uVar3;
    } while ((int)uVar3 < lVar1);
  }
  CPtrArray::SetSize(param_1,0,-1);
  return;
}

/* ---- FUNC 00013920 FUN_180013920 (21 bytes) ---- */

void FUN_180013920(CPtrArray *param_1)

{
  undefined8 *puVar1;
  int iVar2;
  longlong lVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x10) + -1;
  if (-1 < iVar4) {
    lVar3 = (longlong)iVar4;
    do {
      if ((lVar3 < 0) || (*(longlong *)(param_1 + 0x10) <= lVar3)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      puVar1 = *(undefined8 **)(*(longlong *)(param_1 + 8) + lVar3 * 8);
      if (puVar1 == (undefined8 *)0x0) {
LAB_18001397b:
        CPtrArray::RemoveAt(param_1,(longlong)iVar4,1);
      }
      else {
        iVar2 = FUN_180011310((longlong)puVar1);
        if (iVar2 == 0) {
          FUN_18000d530(puVar1);
          operator_delete(puVar1);
          goto LAB_18001397b;
        }
      }
      lVar3 = lVar3 + -1;
      iVar4 = iVar4 + -1;
    } while (-1 < iVar4);
  }
  return;
}

/* ---- FUNC 00013935 FUN_180013935 (105 bytes) ---- */

void FUN_180013935(void)

{
  undefined8 *puVar1;
  int iVar2;
  longlong lVar3;
  CPtrArray *unaff_RSI;
  int unaff_EDI;
  
  lVar3 = (longlong)unaff_EDI;
  do {
    if ((lVar3 < 0) || (*(longlong *)(unaff_RSI + 0x10) <= lVar3)) {
                    /* WARNING: Subroutine does not return */
      AfxThrowInvalidArgException();
    }
    puVar1 = *(undefined8 **)(*(longlong *)(unaff_RSI + 8) + lVar3 * 8);
    if (puVar1 == (undefined8 *)0x0) {
LAB_18001397b:
      CPtrArray::RemoveAt(unaff_RSI,(longlong)unaff_EDI,1);
    }
    else {
      iVar2 = FUN_180011310((longlong)puVar1);
      if (iVar2 == 0) {
        FUN_18000d530(puVar1);
        operator_delete(puVar1);
        goto LAB_18001397b;
      }
    }
    lVar3 = lVar3 + -1;
    unaff_EDI = unaff_EDI + -1;
    if (unaff_EDI < 0) {
      return;
    }
  } while( true );
}

/* ---- FUNC 0001399E FUN_18001399e (11 bytes) ---- */

void FUN_18001399e(void)

{
  return;
}

/* ---- FUNC 000139A9 AfxThrowInvalidArgException (5 bytes) ---- */

void __cdecl AfxThrowInvalidArgException(void)

{
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 000139B0 RemoveLibrary (363 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: bool __cdecl CApwnLibraries::RemoveLibrary(short,int) __ptr64 */

bool __thiscall CApwnLibraries::RemoveLibrary(CApwnLibraries *this,short param_1,int param_2)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar1;
  undefined8 *puVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  longlong lVar6;
  longlong lVar7;
  
                    /* 0x139b0  168  ?RemoveLibrary@CApwnLibraries@@QEAA_NFH@Z */
  lVar6 = (longlong)param_1;
  bVar3 = true;
  if ((param_1 < 0) || (iVar4 = CountLibraries(this), lVar7 = lVar6, iVar4 <= param_1)) {
    bVar3 = false;
  }
  else {
    do {
      if ((lVar7 < 0) || (*(longlong *)(this + 0x18) <= lVar7)) goto LAB_180013b16;
      pCVar1 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
                (*(longlong *)(this + 0x10) + lVar7 * 8);
      if (pCVar1 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
        FUN_18000d210(pCVar1);
        operator_delete(pCVar1);
      }
      lVar7 = lVar7 + -1;
    } while (-1 < lVar7 - lVar6);
    CPtrArray::RemoveAt((CPtrArray *)(this + 8),lVar6,1);
    FUN_1800138b0((CPtrArray *)(this + 0x30));
    AddStreamCategory(this);
    iVar4 = CountLibraries(this);
    if (0 < iVar4) {
      lVar6 = 0;
      do {
        if ((lVar6 < 0) || (*(longlong *)(this + 0x18) <= lVar6)) {
LAB_180013b16:
                    /* WARNING: Subroutine does not return */
          AfxThrowInvalidArgException();
        }
        pCVar1 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
                  (*(longlong *)(this + 0x10) + lVar6 * 8);
        puVar2 = *(undefined8 **)(pCVar1 + 8);
        if (puVar2 != (undefined8 *)0x0) {
          iVar5 = (**(code **)*puVar2)();
          if (iVar5 < 0) {
            bVar3 = false;
          }
          else {
            AddPaletteCategories(this,pCVar1,(IAEditCategories *)0x0);
            (**(code **)(_DAT_00000000 + 0x10))();
          }
        }
        lVar6 = lVar6 + 1;
      } while (lVar6 < iVar4);
    }
    FUN_180013920((CPtrArray *)(this + 0x30));
  }
  if ((param_2 != 0) && (bVar3)) {
    PostMainWndMessage2(0x565,0,0);
  }
  return bVar3;
}

/* ---- FUNC 00013B20 RemoveModelType (320 bytes) ---- */

/* public: bool __cdecl CApwnLibraries::RemoveModelType(char const * __ptr64,char const *
   __ptr64,char const * __ptr64) __ptr64 */

bool __thiscall
CApwnLibraries::RemoveModelType(CApwnLibraries *this,char *param_1,char *param_2,char *param_3)

{
  longlong *plVar1;
  int iVar2;
  ulonglong uVar3;
  byte extraout_var;
  byte extraout_var_00;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar4;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar5;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar6;
  byte bVar7;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res18 [8];
  longlong local_48;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_40 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_38 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_30;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_28;
  
                    /* 0x13b20  169  ?RemoveModelType@CApwnLibraries@@QEAA_NPEBD00@Z */
  if ((param_2 != (char *)0x0) && (param_3 != (char *)0x0)) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res18,param_2);
    uVar3 = FUN_180010240((longlong)(this + 0x30),(undefined8 *)local_res18);
    iVar2 = (int)uVar3;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res18);
    if (-1 < iVar2) {
      if ((longlong)iVar2 < *(longlong *)(this + 0x40)) {
        plVar1 = *(longlong **)(*(longlong *)(this + 0x38) + (longlong)iVar2 * 8);
        local_48 = 0;
        (**(code **)(*plVar1 + 0x38))(plVar1,param_3,&local_48);
        bVar7 = extraout_var;
        if (local_48 != 0) {
          (**(code **)(*plVar1 + 0x30))(plVar1);
          local_30 = local_res18;
          local_28 = local_40;
          pCVar4 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                   ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                   CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                             (local_res18,param_3);
          pCVar5 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                   ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                   CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_40,param_2);
          pCVar6 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                   ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                   CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_38,param_1);
          FUN_180013cf0((longlong *)(this + 0x90),pCVar6,pCVar5,pCVar4);
          bVar7 = extraout_var_00;
        }
        return (bool)(bVar7 >> 7 ^ 1);
      }
                    /* WARNING: Subroutine does not return */
      AfxThrowInvalidArgException();
    }
  }
  return false;
}

/* ---- FUNC 00013C70 FUN_180013c70 (115 bytes) ---- */

undefined8 FUN_180013c70(longlong param_1,longlong *param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  uVar1 = 0;
  uVar2 = uVar1;
  if (0 < (longlong)*(int *)(param_1 + 0x28)) {
    do {
      if (((longlong)uVar1 < 0) || (*(longlong *)(param_1 + 0x28) <= (longlong)uVar1)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      if (*(longlong **)(*(longlong *)(param_1 + 0x20) + uVar1 * 8) == param_2) {
        CPtrArray::RemoveAt((CPtrArray *)(param_1 + 0x18),(longlong)(int)uVar2,1);
        (**(code **)(*param_2 + 0x10))(param_2);
        return 0;
      }
      uVar1 = uVar1 + 1;
      uVar2 = (ulonglong)((int)uVar2 + 1);
    } while ((longlong)uVar1 < (longlong)*(int *)(param_1 + 0x28));
  }
  return 0x80004005;
}

/* ---- FUNC 00013CF0 FUN_180013cf0 (619 bytes) ---- */

undefined8
FUN_180013cf0(longlong *param_1,
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_2,
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_3,
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_4)

{
  uint uVar1;
  uint *puVar2;
  bool bVar3;
  int iVar4;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar5;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this_00;
  longlong *plVar6;
  undefined8 uVar7;
  longlong lVar8;
  undefined8 *puVar9;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_res8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_res10;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_res18;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_res20;
  char *local_b8;
  char *local_b0;
  char *local_a8;
  undefined4 local_a0;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_98 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_90 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_88 [16];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_78;
  longlong *local_70;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_68;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_60 [4];
  
  local_res8 = local_90;
  local_68 = local_88;
  local_res10 = param_2;
  local_res18 = param_3;
  local_res20 = param_4;
  pCVar5 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
           ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
           CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                     (local_90,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                *)param_4);
  local_60[0] = pCVar5;
  this = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
         ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
         CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                   (local_88,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                              *)param_3);
  local_78 = this;
  this_00 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      (local_98,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                 *)param_2);
  local_res8 = this_00;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b8,
             (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)this_00);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b0,
             (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)this);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_a8,
             (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar5);
  local_a0 = 1;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(this_00);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(this);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar5);
  local_res8 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
               CONCAT44(local_res8._4_4_,0xffffffff);
  local_78 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b8;
  local_70 = param_1;
  plVar6 = FUN_18000c980((longlong *)local_60,(int *)param_1[3],param_1[4],(int *)&local_res8,
                         (longlong *)&local_78);
  puVar2 = (uint *)*plVar6;
  if (puVar2 == (uint *)param_1[4]) {
LAB_180013f09:
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_a8);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b0);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b8);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_2);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_3);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_4);
    uVar7 = 0;
  }
  else {
    uVar1 = *puVar2;
    if (uVar1 != 0xffffffff) {
      pCVar5 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
               ((longlong)(int)uVar1 * 0x20 + *param_1);
      if (pCVar5 == (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_1[1]) {
        bVar3 = (int)uVar1 < -1;
      }
      else {
        iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                          (pCVar5 + 0x10,local_a8);
        if (iVar4 == 0) {
          iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                            (pCVar5 + 8,local_b0);
          if (iVar4 == 0) {
            iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                              (pCVar5,local_b8);
          }
        }
        bVar3 = SUB41((uint)iVar4 >> 0x1f,0);
      }
      if (bVar3 != false) goto LAB_180013f09;
    }
    uVar1 = *puVar2;
    if (uVar1 != 0xffffffff) {
      puVar9 = (undefined8 *)((longlong)(int)uVar1 * 0x20 + *param_1);
      if (puVar9 == (undefined8 *)param_1[1]) {
        bVar3 = uVar1 < 0x80000000;
      }
      else {
        iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_a8,(char *)puVar9[2]);
        if (iVar4 == 0) {
          iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &local_b0,(char *)puVar9[1]);
          if (iVar4 == 0) {
            iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                               &local_b8,(char *)*puVar9);
          }
        }
        bVar3 = SUB41((uint)iVar4 >> 0x1f,0);
      }
      if (bVar3 != false) goto LAB_180013f09;
    }
    lVar8 = (longlong)(int)*puVar2 * 0x20 + *param_1;
    if (lVar8 != param_1[1]) {
      *(undefined4 *)(lVar8 + 0x18) = 0;
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_a8);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b0);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b8);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_2);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_3);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_4);
    uVar7 = 1;
  }
  return uVar7;
}

/* ---- FUNC 00013F60 FUN_180013f60 (10 bytes) ---- */

undefined8 FUN_180013f60(longlong param_1)

{
  *(undefined4 *)(param_1 + 0x38) = 0;
  return 0;
}

/* ---- FUNC 00013F70 FUN_180013f70 (10 bytes) ---- */

undefined8 FUN_180013f70(longlong param_1)

{
  *(undefined4 *)(param_1 + 0x14) = 0;
  return 0;
}

/* ---- FUNC 00013F80 FUN_180013f80 (35 bytes) ---- */

undefined8 FUN_180013f80(longlong *param_1)

{
  longlong lVar1;
  
  lVar1 = *param_1;
  if (lVar1 != param_1[1]) {
    do {
      *(undefined4 *)(lVar1 + 0x18) = 0;
      lVar1 = lVar1 + 0x20;
    } while (lVar1 != param_1[1]);
  }
  return 1;
}

/* ---- FUNC 00013FB0 Restore (104 bytes) ---- */

/* public: int __cdecl CApwnLibraries::Restore(void * __ptr64,struct HWND__ * __ptr64) __ptr64 */

int __thiscall CApwnLibraries::Restore(CApwnLibraries *this,void *param_1,HWND__ *param_2)

{
  int iVar1;
  void *local_res10 [2];
  int local_res20 [2];
  
                    /* 0x13fb0  170  ?Restore@CApwnLibraries@@QEAAHPEAXPEAUHWND__@@@Z */
  local_res20[0] = 0;
  local_res10[0] = param_1;
  FUN_180012fc0((longlong *)local_res10,local_res20);
  if (local_res20[0] == 1) {
    iVar1 = RestoreV1(this,local_res10,param_2);
    return iVar1;
  }
  if (local_res20[0] == 2) {
    iVar1 = RestoreV2(this,local_res10,param_2);
    return iVar1;
  }
  return -1;
}

/* ---- FUNC 00014020 FUN_180014020 (779 bytes) ---- */

undefined8 FUN_180014020(longlong *param_1,longlong *param_2)

{
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar1;
  int *piVar2;
  int iVar3;
  char *pcVar4;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this_00;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this_01;
  ulonglong uVar5;
  int local_res8 [2];
  longlong *local_res10;
  int local_res18 [2];
  undefined4 local_res20 [2];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_c8 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_c0 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_b8 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_b0 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_a8 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_a0 [8];
  undefined4 local_98;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_90 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_88 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_80 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_78;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_70;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_68;
  longlong *local_60;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_58;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_50;
  
  local_res10 = param_2;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_b8);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_c0);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_c8);
  local_res8[0] = 0;
  FUN_180012fc0(param_2,local_res8);
  iVar3 = local_res8[0];
  uVar5 = (ulonglong)local_res8[0];
  if ((ulonglong)(param_1[2] - *param_1 >> 5) < uVar5) {
    if (0x7ffffffffffffff < uVar5) {
                    /* WARNING: Subroutine does not return */
      FUN_18000ad00();
    }
    FUN_180016b30(param_1,uVar5);
  }
  if ((ulonglong)(param_1[5] - param_1[3] >> 2) < uVar5) {
    if (0x3fffffffffffffff < uVar5) {
                    /* WARNING: Subroutine does not return */
      FUN_18000ad00();
    }
    FUN_180016a90(param_1 + 3,uVar5);
  }
  local_res18[0] = 0;
  if (0 < iVar3) {
    do {
      iVar3 = local_res18[0];
      pcVar4 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)local_b8,0x40);
      FUN_180013080(param_2,pcVar4);
      ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)local_b8,-1);
      pcVar4 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)local_c0,0x40);
      FUN_180013080(param_2,pcVar4);
      ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)local_c0,-1);
      pcVar4 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)local_c8,0x40);
      FUN_180013080(param_2,pcVar4);
      ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)local_c8,-1);
      FUN_180012fc0(param_2,local_res20);
      local_58 = local_90;
      local_78 = local_88;
      pCVar1 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               param_1[1];
      this = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                       (local_90,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                  *)local_b8);
      local_70 = this;
      this_00 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                          (local_88,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                     *)local_c0);
      local_50 = this_00;
      this_01 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                          (local_80,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                                     *)local_c8);
      local_78 = this_01;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                (local_b0,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                           *)this_01);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                (local_a8,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                           *)this_00);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                (local_a0,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                           *)this);
      local_98 = local_res20[0];
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(this_01);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(this_00);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(this);
      FUN_18000c2a0(param_1,&local_68,pCVar1,
                    (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                    local_b0);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_a0);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_a8);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_b0);
      piVar2 = (int *)param_1[4];
      if (piVar2 == (int *)param_1[5]) {
        FUN_18000b790(param_1 + 3,piVar2,local_res18);
      }
      else {
        *piVar2 = iVar3;
        param_1[4] = param_1[4] + 4;
      }
      local_res18[0] = iVar3 + 1;
      param_2 = local_res10;
    } while (local_res18[0] < local_res8[0]);
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_b0);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_a8);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_a0);
  local_98 = 0;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_a0);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_a8);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_b0);
  local_68 = local_b0;
  local_60 = param_1;
  FUN_18000bf30((int *)param_1[3],(int *)param_1[4],param_1[4] - param_1[3] >> 2,
                (longlong *)&local_68);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_c8);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_c0);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_b8);
  return 0;
}

/* ---- FUNC 00014330 RestoreFromText (708 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: int __cdecl CApwnLibraries::RestoreFromText(struct IStream * __ptr64,struct HWND__ *
   __ptr64) __ptr64 */

int __thiscall
CApwnLibraries::RestoreFromText(CApwnLibraries *this,IStream *param_1,HWND__ *param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  ulonglong uVar4;
  undefined1 auStack_138 [32];
  CStringArray local_118 [16];
  __int64 local_108;
  undefined **local_f0 [5];
  char local_c8 [160];
  ulonglong local_28;
  
                    /* 0x14330  172
                       ?RestoreFromText@CApwnLibraries@@QEAAHPEAUIStream@@PEAUHWND__@@@Z */
  local_28 = DAT_1800791f8 ^ (ulonglong)auStack_138;
  if (param_1 == (IStream *)0x0) {
    uVar4 = FUN_1800240b0();
    if (((int)uVar4 == 1) && (bVar1 = HaveAnyLibraries(this), !bVar1)) {
      CStringArray::CStringArray(local_118);
      CStringArray::SetAtGrow(local_118,local_108,&m_builtin);
      CStringArray::SetAtGrow(local_118,local_108,&m_acmbuiltin);
      CStringArray::SetAtGrow(local_118,local_108,&m_ConceptualDesign);
      CStringArray::SetAtGrow(local_118,local_108,&m_acmcatalog);
      CStringArray::SetAtGrow(local_118,local_108,&m_HybridModelLib);
      CPtrArray::CPtrArray((CPtrArray *)local_f0);
      local_f0[0] = CNameAndStateArray::vftable;
      CPtrArray::SetSize((CPtrArray *)local_f0,0,-1);
      iVar2 = ReconcileLibs(this,local_118,(CNameAndStateArray *)local_f0);
      CNameAndStateArray::~CNameAndStateArray((CNameAndStateArray *)local_f0);
      CStringArray::~CStringArray(local_118);
      return iVar2;
    }
    iVar2 = 0;
  }
  else {
    FUN_180012fd0((longlong *)param_1,(longlong)local_c8);
    iVar2 = _strnicmp(local_c8,"startlibrary",0xc);
    if (iVar2 == 0) {
      FUN_180012fd0((longlong *)param_1,(longlong)local_c8);
      iVar2 = _strnicmp(local_c8,"version1",8);
      if (iVar2 == 0) {
        iVar2 = RestoreFromTextV1(this,param_1,param_2);
        FUN_180012fd0((longlong *)param_1,(longlong)local_c8);
        iVar3 = _strnicmp(local_c8,"endlibrary",10);
        if (iVar3 == 0) {
          return iVar2;
        }
      }
    }
    else {
      uVar4 = FUN_1800240b0();
      if (((int)uVar4 == 1) && (bVar1 = HaveAnyLibraries(this), !bVar1)) {
        CStringArray::CStringArray(local_118);
        CStringArray::SetAtGrow(local_118,local_108,&m_builtin);
        CStringArray::SetAtGrow(local_118,local_108,&m_acmbuiltin);
        CStringArray::SetAtGrow(local_118,local_108,&m_ConceptualDesign);
        CStringArray::SetAtGrow(local_118,local_108,&m_acmcatalog);
        CStringArray::SetAtGrow(local_118,local_108,&m_HybridModelLib);
        CPtrArray::CPtrArray((CPtrArray *)local_f0);
        local_f0[0] = CNameAndStateArray::vftable;
        CPtrArray::SetSize((CPtrArray *)local_f0,0,-1);
        ReconcileLibs(this,local_118,(CNameAndStateArray *)local_f0);
        CNameAndStateArray::~CNameAndStateArray((CNameAndStateArray *)local_f0);
        CStringArray::~CStringArray(local_118);
      }
    }
    iVar2 = -2;
  }
  return iVar2;
}

/* ---- FUNC 00014600 RestoreFromTextV1 (1696 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: int __cdecl CApwnLibraries::RestoreFromTextV1(struct IStream * __ptr64,struct HWND__ *
   __ptr64) __ptr64 */

int __thiscall
CApwnLibraries::RestoreFromTextV1(CApwnLibraries *this,IStream *param_1,HWND__ *param_2)

{
  CApwnLibraries *this_00;
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  LPSTR pCVar5;
  char *pcVar6;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this_01;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar7;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar8;
  ulonglong uVar9;
  uint uVar10;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar11;
  longlong lVar12;
  undefined8 *puVar13;
  IStream *pIVar14;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar15;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar16;
  undefined1 auStack_268 [32];
  int local_248;
  int local_244;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_240 [8];
  int local_238;
  char *local_230;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_228 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_220 [8];
  CStringArray local_218 [8];
  longlong local_210;
  longlong local_208;
  IStream *local_1f0;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_1e8 [8];
  char *local_1e0;
  char *local_1d8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_1d0;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_1c8;
  CStringArray local_1c0 [8];
  longlong local_1b8;
  longlong local_1b0;
  CApwnLibraries *local_198;
  undefined **local_190;
  longlong local_188;
  longlong local_180;
  CStringArray local_168 [8];
  longlong local_160;
  longlong local_158;
  undefined8 local_140 [3];
  char local_128 [64];
  char local_e8 [160];
  ulonglong local_48;
  
                    /* 0x14600  173
                       ?RestoreFromTextV1@CApwnLibraries@@QEAAHPEAUIStream@@PEAUHWND__@@@Z */
  local_48 = DAT_1800791f8 ^ (ulonglong)auStack_268;
  pCVar8 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
  iVar4 = 0;
  local_244 = 0;
  local_1f0 = param_1;
  local_198 = this;
  CStringArray::CStringArray(local_218);
  FUN_180012fd0((longlong *)param_1,(longlong)local_e8);
  sscanf(local_e8,"NumLibs = %d\n");
  if (local_244 < 0) {
    local_244 = 0;
  }
  pCVar15 = pCVar8;
  if (0 < local_244) {
    do {
      FUN_180012fd0((longlong *)param_1,(longlong)local_128);
      pCVar16 = pCVar8;
      pCVar11 = pCVar8;
      if (0 < local_208) {
        do {
          if (((longlong)pCVar16 < 0) || (local_208 <= (longlong)pCVar16)) {
                    /* WARNING: Subroutine does not return */
            AfxThrowInvalidArgException();
          }
          iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             (local_210 + (longlong)pCVar16 * 8),local_128);
          if (iVar2 == 0) goto LAB_1800146f6;
          uVar10 = (int)pCVar11 + 1;
          pCVar16 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                    (longlong)(int)uVar10;
          pCVar11 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                    (ulonglong)uVar10;
        } while ((int)uVar10 < local_208);
      }
      CStringArray::SetAtGrow(local_218,local_208,local_128);
LAB_1800146f6:
      uVar10 = (int)pCVar15 + 1;
      pCVar15 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(ulonglong)uVar10;
    } while ((int)uVar10 < local_244);
  }
  pCVar5 = GetCommandLineA();
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_228,pCVar5);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::MakeUpper(local_228);
  iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Find
                    (local_228,"HYSYS.EXE",0);
  if (iVar2 == -1) {
    local_140[0] = _m_acmbuiltin;
    local_140[1] = _m_acmcatalog;
    local_140[2] = _m_HybridModelLib;
    puVar13 = local_140;
    pCVar15 = pCVar8;
    do {
      pCVar16 = pCVar8;
      pCVar11 = pCVar8;
      if (0 < local_208) {
        do {
          if (((longlong)pCVar16 < 0) || (local_208 <= (longlong)pCVar16)) goto LAB_180014c8f;
          iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             (local_210 + (longlong)pCVar16 * 8),(char *)*puVar13);
          if (iVar2 == 0) goto LAB_1800147b7;
          uVar10 = (int)pCVar11 + 1;
          pCVar16 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                    (longlong)(int)uVar10;
          pCVar11 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                    (ulonglong)uVar10;
        } while ((int)uVar10 < local_208);
      }
      CStringArray::SetAtGrow(local_218,local_208,(char *)*puVar13);
LAB_1800147b7:
      pCVar15 = pCVar15 + 1;
      puVar13 = puVar13 + 1;
    } while ((longlong)pCVar15 < 3);
  }
  else {
    pCVar15 = pCVar8;
    pCVar16 = pCVar8;
    if (0 < local_208) {
      do {
        if (((longlong)pCVar15 < 0) || (local_208 <= (longlong)pCVar15)) {
LAB_180014c8f:
                    /* WARNING: Subroutine does not return */
          AfxThrowInvalidArgException();
        }
        iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           (local_210 + (longlong)pCVar15 * 8),_m_builtin);
        if (iVar2 == 0) {
          CStringArray::SetSize(local_218,0,-1);
          CStringArray::SetAtGrow(local_218,local_208,&m_builtin);
          goto LAB_180014827;
        }
        uVar10 = (int)pCVar16 + 1;
        pCVar15 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                  (longlong)(int)uVar10;
        pCVar16 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(ulonglong)uVar10
        ;
      } while ((int)uVar10 < local_208);
    }
    CStringArray::SetSize(local_218,0,-1);
  }
LAB_180014827:
  local_248 = 0;
  CStringArray::CStringArray(local_1c0);
  CStringArray::CStringArray(local_168);
  CPtrArray::CPtrArray((CPtrArray *)&local_190);
  pIVar14 = local_1f0;
  local_190 = CNameAndStateArray::vftable;
  FUN_180012fd0((longlong *)local_1f0,(longlong)local_e8);
  sscanf(local_e8,"NumCats = %d\n",&local_248);
  if (local_248 < 0) {
    local_248 = 0;
  }
  CPtrArray::SetSize((CPtrArray *)&local_190,(longlong)local_248,-1);
  CStringArray::SetSize(local_1c0,(longlong)local_248,-1);
  CStringArray::SetSize(local_168,(longlong)local_248,-1);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1d8,"Solids");
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_230,
             "Solids Separators");
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1e0,
             "Heat Exchangers");
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_1e8,"Exchangers");
  bVar1 = false;
  pCVar15 = pCVar8;
  pCVar16 = pCVar8;
  pCVar11 = pCVar8;
  if (0 < local_248) {
    do {
      iVar2 = (int)pCVar15;
      lVar12 = (longlong)iVar2;
      if ((iVar2 < 0) || (local_1b0 <= lVar12)) {
LAB_180014c83:
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      pcVar6 = ATL::CSimpleStringT<char,1>::GetBuffer
                         ((CSimpleStringT<char,1> *)(local_1b8 + lVar12 * 8),0x91);
      FUN_180012fd0((longlong *)pIVar14,(longlong)pcVar6);
      if (local_158 <= lVar12) goto LAB_180014c83;
      pcVar6 = ATL::CSimpleStringT<char,1>::GetBuffer
                         ((CSimpleStringT<char,1> *)(local_160 + lVar12 * 8),0x91);
      FUN_180012fd0((longlong *)pIVar14,(longlong)pcVar6);
      if ((((local_1b0 <= lVar12) ||
           (ATL::CSimpleStringT<char,1>::ReleaseBuffer
                      ((CSimpleStringT<char,1> *)(local_1b8 + lVar12 * 8),-1), local_158 <= lVar12))
          || (ATL::CSimpleStringT<char,1>::ReleaseBuffer
                        ((CSimpleStringT<char,1> *)(local_160 + lVar12 * 8),-1),
             (longlong)pCVar16 < 0)) ||
         ((local_158 <= (longlong)pCVar16 ||
          (local_238 = _strnicmp(*(char **)(local_160 + (longlong)pCVar16 * 8),"active",6),
          local_1b0 <= lVar12)))) goto LAB_180014c83;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                (local_240,
                 (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                 (local_1b8 + lVar12 * 8));
      iVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                        (local_240,local_1e0);
      if (iVar3 == 0) {
        if (local_1b0 <= lVar12) goto LAB_180014c9b;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                   (local_1b8 + lVar12 * 8),
                   (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                   local_1e8);
      }
      this_01 = operator_new(0x10);
      pCVar7 = pCVar8;
      local_1d0 = this_01;
      if (this_01 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
        if (local_1b0 <= lVar12) {
                    /* WARNING: Subroutine does not return */
          AfxThrowInvalidArgException();
        }
        pCVar7 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                 ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                 CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                           (local_220,
                            (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                             *)(local_1b8 + lVar12 * 8));
        local_1c8 = pCVar7;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(this_01);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  (this_01,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                            *)pCVar7);
        *(uint *)(this_01 + 8) = (uint)(local_238 == 0);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar7);
        pCVar7 = this_01;
      }
      if (local_180 <= (longlong)pCVar16) {
LAB_180014c9b:
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
       (local_188 + (longlong)pCVar16 * 8) = pCVar7;
      if (((int)pCVar11 == 0) &&
         (iVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                            (local_240,local_1d8), iVar3 == 0)) {
        pCVar11 = pCVar15;
      }
      iVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                        (local_240,local_230);
      if (iVar3 == 0) {
        bVar1 = true;
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_240);
      pCVar15 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                (ulonglong)(iVar2 + 1U);
      pCVar16 = pCVar16 + 1;
      pIVar14 = local_1f0;
    } while ((int)(iVar2 + 1U) < local_248);
    if ((!bVar1) && (0 < (int)pCVar11)) {
      pCVar15 = operator_new(0x10);
      local_1c8 = pCVar15;
      if (pCVar15 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
        pCVar8 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                 ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                 CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                           (local_220,
                            (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                             *)&local_230);
        local_1d0 = pCVar8;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar15);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  (pCVar15,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                            *)pCVar8);
        *(undefined4 *)(pCVar15 + 8) = 1;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar8);
        pCVar8 = pCVar15;
      }
      CPtrArray::InsertAt((CPtrArray *)&local_190,(longlong)((int)pCVar11 + 1),pCVar8,1);
    }
  }
  uVar9 = FUN_1800240b0();
  this_00 = local_198;
  if ((int)uVar9 != 2) {
    bVar1 = HaveAnyLibraries(local_198);
    if (bVar1) {
      iVar4 = AppendLibs(this_00,local_218,(CNameAndStateArray *)&local_190);
    }
    else {
      iVar4 = ReconcileLibs(this_00,local_218,(CNameAndStateArray *)&local_190);
    }
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_1e8);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1e0);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_230);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1d8);
  CNameAndStateArray::~CNameAndStateArray((CNameAndStateArray *)&local_190);
  CStringArray::~CStringArray(local_168);
  CStringArray::~CStringArray(local_1c0);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_228);
  CStringArray::~CStringArray(local_218);
  return iVar4;
}

/* ---- FUNC 00014CB0 RestoreV1 (533 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: int __cdecl CApwnLibraries::RestoreV1(void * __ptr64 * __ptr64,struct HWND__ * __ptr64)
   __ptr64 */

int __thiscall CApwnLibraries::RestoreV1(CApwnLibraries *this,void **param_1,HWND__ *param_2)

{
  int iVar1;
  char *pcVar2;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar3;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this_00;
  longlong lVar4;
  int iVar5;
  undefined1 auStack_118 [32];
  int local_f8 [2];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_f0 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_e8;
  CStringArray local_e0 [8];
  longlong local_d8;
  longlong local_d0;
  undefined **local_b8;
  longlong local_b0;
  longlong local_a8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_90;
  char local_88 [64];
  ulonglong local_48;
  
                    /* 0x14cb0  174  ?RestoreV1@CApwnLibraries@@QEAAHPEAPEAXPEAUHWND__@@@Z */
  local_48 = DAT_1800791f8 ^ (ulonglong)auStack_118;
  local_f8[0] = 0;
  FUN_180012fc0((longlong *)param_1,local_f8);
  CStringArray::CStringArray(local_e0);
  iVar1 = local_f8[0];
  CStringArray::SetSize(local_e0,(longlong)local_f8[0],-1);
  iVar5 = 0;
  if (0 < iVar1) {
    do {
      lVar4 = (longlong)iVar5;
      if ((iVar5 < 0) || (local_d0 <= lVar4)) {
LAB_180014eba:
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      pcVar2 = ATL::CSimpleStringT<char,1>::GetBuffer
                         ((CSimpleStringT<char,1> *)(local_d8 + lVar4 * 8),0x40);
      FUN_180013080((longlong *)param_1,pcVar2);
      if (local_d0 <= lVar4) goto LAB_180014eba;
      ATL::CSimpleStringT<char,1>::ReleaseBuffer
                ((CSimpleStringT<char,1> *)(local_d8 + lVar4 * 8),-1);
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar1);
  }
  local_f8[0] = 0;
  FUN_180012fc0((longlong *)param_1,local_f8);
  CPtrArray::CPtrArray((CPtrArray *)&local_b8);
  iVar1 = local_f8[0];
  local_b8 = CNameAndStateArray::vftable;
  CPtrArray::SetSize((CPtrArray *)&local_b8,(longlong)local_f8[0],-1);
  iVar5 = 0;
  if (0 < iVar1) {
    lVar4 = 0;
    do {
      FUN_180013080((longlong *)param_1,local_88);
      local_f8[0] = 0;
      FUN_180012fc0((longlong *)param_1,local_f8);
      pCVar3 = operator_new(0x10);
      local_90 = pCVar3;
      if (pCVar3 == (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
        pCVar3 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
      }
      else {
        this_00 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_f0,local_88);
        local_e8 = this_00;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar3);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  (pCVar3,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                           *)this_00);
        *(int *)(pCVar3 + 8) = local_f8[0];
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(this_00);
      }
      if ((lVar4 < 0) || (local_a8 <= lVar4)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)(local_b0 + lVar4 * 8) =
           pCVar3;
      iVar5 = iVar5 + 1;
      lVar4 = lVar4 + 1;
    } while (iVar5 < iVar1);
  }
  iVar1 = ReconcileLibs(this,local_e0,(CNameAndStateArray *)&local_b8);
  CNameAndStateArray::~CNameAndStateArray((CNameAndStateArray *)&local_b8);
  CStringArray::~CStringArray(local_e0);
  return iVar1;
}

/* ---- FUNC 00014ED0 RestoreV2 (552 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: int __cdecl CApwnLibraries::RestoreV2(void * __ptr64 * __ptr64,struct HWND__ * __ptr64)
   __ptr64 */

int __thiscall CApwnLibraries::RestoreV2(CApwnLibraries *this,void **param_1,HWND__ *param_2)

{
  int iVar1;
  char *pcVar2;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar3;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this_00;
  longlong lVar4;
  int iVar5;
  undefined1 auStack_118 [32];
  int local_f8 [2];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_f0 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_e8;
  CStringArray local_e0 [8];
  longlong local_d8;
  longlong local_d0;
  undefined **local_b8;
  longlong local_b0;
  longlong local_a8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_90;
  char local_88 [64];
  ulonglong local_48;
  
                    /* 0x14ed0  175  ?RestoreV2@CApwnLibraries@@QEAAHPEAPEAXPEAUHWND__@@@Z */
  local_48 = DAT_1800791f8 ^ (ulonglong)auStack_118;
  local_f8[0] = 0;
  FUN_180012fc0((longlong *)param_1,local_f8);
  CStringArray::CStringArray(local_e0);
  iVar1 = local_f8[0];
  CStringArray::SetSize(local_e0,(longlong)local_f8[0],-1);
  iVar5 = 0;
  if (0 < iVar1) {
    do {
      lVar4 = (longlong)iVar5;
      if ((iVar5 < 0) || (local_d0 <= lVar4)) {
LAB_1800150ed:
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      pcVar2 = ATL::CSimpleStringT<char,1>::GetBuffer
                         ((CSimpleStringT<char,1> *)(local_d8 + lVar4 * 8),0x40);
      FUN_180013080((longlong *)param_1,pcVar2);
      if (local_d0 <= lVar4) goto LAB_1800150ed;
      ATL::CSimpleStringT<char,1>::ReleaseBuffer
                ((CSimpleStringT<char,1> *)(local_d8 + lVar4 * 8),-1);
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar1);
  }
  local_f8[0] = 0;
  FUN_180012fc0((longlong *)param_1,local_f8);
  CPtrArray::CPtrArray((CPtrArray *)&local_b8);
  iVar1 = local_f8[0];
  local_b8 = CNameAndStateArray::vftable;
  CPtrArray::SetSize((CPtrArray *)&local_b8,(longlong)local_f8[0],-1);
  iVar5 = 0;
  if (0 < iVar1) {
    lVar4 = 0;
    do {
      FUN_180013080((longlong *)param_1,local_88);
      local_f8[0] = 0;
      FUN_180012fc0((longlong *)param_1,local_f8);
      pCVar3 = operator_new(0x10);
      local_90 = pCVar3;
      if (pCVar3 == (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
        pCVar3 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
      }
      else {
        this_00 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_f0,local_88);
        local_e8 = this_00;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar3);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  (pCVar3,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                           *)this_00);
        *(int *)(pCVar3 + 8) = local_f8[0];
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(this_00);
      }
      if ((lVar4 < 0) || (local_a8 <= lVar4)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)(local_b0 + lVar4 * 8) =
           pCVar3;
      iVar5 = iVar5 + 1;
      lVar4 = lVar4 + 1;
    } while (iVar5 < iVar1);
  }
  FUN_180014020((longlong *)(this + 0x90),(longlong *)param_1);
  iVar1 = ReconcileLibs(this,local_e0,(CNameAndStateArray *)&local_b8);
  CNameAndStateArray::~CNameAndStateArray((CNameAndStateArray *)&local_b8);
  CStringArray::~CStringArray(local_e0);
  return iVar1;
}

/* ---- FUNC 00015100 Save (24 bytes) ---- */

/* public: int __cdecl CApwnLibraries::Save(void * __ptr64) __ptr64 */

int __thiscall CApwnLibraries::Save(CApwnLibraries *this,void *param_1)

{
  int iVar1;
  char *local_res10 [3];
  
                    /* 0x15100  178  ?Save@CApwnLibraries@@QEAAHPEAX@Z */
  local_res10[0] = param_1;
  iVar1 = DoSave(this,local_res10);
  return iVar1;
}

/* ---- FUNC 00015120 FUN_180015120 (156 bytes) ---- */

undefined8 FUN_180015120(longlong *param_1,longlong *param_2,int *param_3)

{
  undefined8 *puVar1;
  
  FUN_180016850(param_2,(int)(param_1[1] - *param_1 >> 5),param_3);
  puVar1 = (undefined8 *)*param_1;
  if (puVar1 != (undefined8 *)param_1[1]) {
    do {
      FUN_1800168b0(param_2,(void *)puVar1[2],param_3);
      FUN_1800168b0(param_2,(void *)puVar1[1],param_3);
      FUN_1800168b0(param_2,(void *)*puVar1,param_3);
      FUN_180016850(param_2,*(undefined4 *)(puVar1 + 3),param_3);
      puVar1 = puVar1 + 4;
    } while (puVar1 != (undefined8 *)param_1[1]);
  }
  return 0;
}

/* ---- FUNC 000151C0 FUN_1800151c0 (1180 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

HKEY FUN_1800151c0(longlong *param_1)

{
  char cVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong *plVar4;
  int iVar5;
  LSTATUS LVar6;
  UINT UVar7;
  undefined8 uVar8;
  char *pcVar9;
  longlong lVar10;
  HKEY pHVar12;
  HKEY unaff_RBX;
  HKEY hKey;
  HKEY pHVar13;
  undefined1 auStackY_268 [32];
  longlong *local_218;
  UINT local_210;
  DWORD local_20c;
  longlong *local_208;
  longlong *local_200;
  longlong *local_1f8;
  DWORD local_1f0;
  DWORD local_1ec;
  HKEY local_1e8;
  longlong *local_1e0;
  undefined *local_1d8;
  HKEY local_1d0;
  undefined4 local_1c8;
  undefined8 local_1c0;
  undefined *local_1b8;
  HKEY local_1b0;
  undefined4 local_1a8;
  undefined8 local_1a0;
  longlong *local_198;
  BYTE local_190 [32];
  CHAR local_170 [40];
  char local_148 [272];
  ulonglong local_38;
  longlong lVar11;
  
  local_38 = DAT_1800791f8 ^ (ulonglong)auStackY_268;
  hKey = (HKEY)0x0;
  uVar8 = FUN_180010bb0();
  if ((int)uVar8 != 0) {
    return unaff_RBX;
  }
  local_200 = (longlong *)0x0;
  if ((param_1 != (longlong *)0x0) &&
     (iVar5 = (**(code **)*param_1)(param_1,&DAT_180053510,&local_200), iVar5 < 0)) {
    local_200 = (longlong *)0x0;
  }
  plVar4 = local_200;
  local_198 = local_200;
  if (local_200 == (longlong *)0x0) goto LAB_18001560c;
  (**(code **)(*local_200 + 8))();
  local_1f0 = 4;
  local_210 = 1;
  local_1ec = 4;
  pHVar12 = hKey;
  do {
    cVar1 = (char)pHVar12[0x6001e858].unused;
    local_148[(longlong)pHVar12] = cVar1;
    pHVar12 = (HKEY)((longlong)&pHVar12->unused + 1);
  } while (cVar1 != '\0');
  pcVar9 = strrchr(local_148,0x5c);
  if (pcVar9 != (char *)0x0) {
    *pcVar9 = '\0';
  }
  local_1d8 = &DAT_180053988;
  local_1d0 = (HKEY)0x0;
  local_1c8 = 0;
  local_1c0 = 0;
  LVar6 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000001,local_148,0,0x20019,&local_1e8);
  pHVar12 = local_1e8;
  pHVar13 = hKey;
  if (LVar6 == 0) {
    local_1d0 = local_1e8;
    local_1c8 = 0;
    local_1c0 = 0;
    LVar6 = RegQueryValueExA(local_1e8,"SaveUserLibDefaults",(LPDWORD)0x0,&local_1f0,
                             (LPBYTE)&local_210,&local_1ec);
    pHVar13 = pHVar12;
    if (LVar6 == 0) {
      UVar7 = local_210;
      if (local_1f0 != 4) goto LAB_1800153a1;
    }
    else {
      UVar7 = GetPrivateProfileIntA("System","SaveUserLibDefaults",local_210,&DAT_18007a050);
    }
    if (((UVar7 != 0) || (iVar5 = (**(code **)(*param_1 + 0x38))(param_1,local_190,0x20), iVar5 < 0)
        ) || (iVar5 = _stricmp((char *)local_190,"Built-In"), iVar5 == 0)) goto LAB_1800153a1;
  }
  else {
LAB_1800153a1:
    local_1b8 = &DAT_180053988;
    local_1a8 = 0;
    local_1a0 = 0;
    LVar6 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000001,&DAT_18007a160,0,0x2001f,&local_1e8);
    if ((LVar6 == 0) ||
       (LVar6 = RegCreateKeyExA((HKEY)&DAT_ffffffff80000001,&DAT_18007a160,0,(LPSTR)0x0,0,0x2001f,
                                (LPSECURITY_ATTRIBUTES)0x0,&local_1e8,&local_20c), LVar6 == 0)) {
      local_1b0 = local_1e8;
      local_1a8 = 0;
      local_1a0 = 0;
      local_1e0 = (longlong *)0x0;
      iVar5 = (**(code **)(*plVar4 + 0x40))(plVar4,&local_1e0);
      if (-1 < iVar5) {
        local_208 = (longlong *)0x0;
        local_20c = 0;
        iVar5 = (**(code **)(*local_1e0 + 0x18))(local_1e0,1,&local_208,&local_20c);
        while (iVar5 == 0) {
          local_218 = (longlong *)0x0;
          local_1f8 = (longlong *)0x0;
          iVar5 = (**(code **)(*local_208 + 0x18))(local_208,local_170,0x20);
          plVar3 = local_218;
          if (iVar5 < 0) {
LAB_180015493:
            if (local_1f8 != (longlong *)0x0) {
              (**(code **)(*local_1f8 + 0x10))();
            }
          }
          else {
            if (local_218 != local_208) {
              if ((local_208 == (longlong *)0x0) ||
                 (iVar5 = (**(code **)*local_208)(local_208,&DAT_180053f18,&local_218), iVar5 < 0))
              {
                local_218 = (longlong *)0x0;
              }
              if (plVar3 != (longlong *)0x0) {
                (**(code **)(*plVar3 + 0x10))(plVar3);
              }
            }
            if (local_218 != (longlong *)0x0) {
              iVar5 = (**(code **)(*local_218 + 0x18))(local_218,&local_1f8);
              if ((iVar5 < 0) ||
                 (iVar5 = (**(code **)(*local_1f8 + 0x18))(local_1f8,local_190,0x20), iVar5 < 0))
              goto LAB_180015493;
              lVar11 = -1;
              do {
                lVar10 = lVar11 + 1;
                lVar2 = lVar11 + 1;
                lVar11 = lVar10;
              } while (local_190[lVar2] != '\0');
              RegSetValueExA(local_1e8,local_170,0,1,local_190,(int)lVar10 + 1);
            }
            if (local_1f8 != (longlong *)0x0) {
              (**(code **)(*local_1f8 + 0x10))(local_1f8);
            }
          }
          if (local_218 != (longlong *)0x0) {
            (**(code **)(*local_218 + 0x10))();
          }
          plVar3 = local_208;
          if (local_208 != (longlong *)0x0) {
            local_208 = (longlong *)0x0;
            (**(code **)(*plVar3 + 0x10))(plVar3);
          }
          iVar5 = (**(code **)(*local_1e0 + 0x18))(local_1e0,1,&local_208,&local_20c);
        }
        if (local_208 != (longlong *)0x0) {
          (**(code **)(*local_208 + 0x10))();
        }
      }
      hKey = local_1e8;
      if (local_1e0 != (longlong *)0x0) {
        (**(code **)(*local_1e0 + 0x10))();
      }
    }
    pHVar12 = pHVar13;
    if (hKey != (HKEY)0x0) {
      RegCloseKey(hKey);
    }
  }
  if (pHVar12 != (HKEY)0x0) {
    RegCloseKey(pHVar12);
  }
LAB_18001560c:
  if (plVar4 != (longlong *)0x0) {
    (**(code **)(*plVar4 + 0x10))(plVar4);
  }
  if (local_200 != (longlong *)0x0) {
    (**(code **)(*local_200 + 0x10))();
  }
  return unaff_RBX;
}

/* ---- FUNC 00015660 SaveAsText (173 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: int __cdecl CApwnLibraries::SaveAsText(struct IStream * __ptr64) __ptr64 */

int __thiscall CApwnLibraries::SaveAsText(CApwnLibraries *this,IStream *param_1)

{
  undefined8 in_R8;
  undefined8 in_R9;
  undefined1 auStack_d8 [32];
  undefined1 local_b8 [160];
  ulonglong local_18;
  
                    /* 0x15660  179  ?SaveAsText@CApwnLibraries@@QEAAHPEAUIStream@@@Z */
  local_18 = DAT_1800791f8 ^ (ulonglong)auStack_d8;
  FUN_180007de0(local_b8,"startlibrary\n",in_R8,in_R9);
  FUN_180016870((longlong *)param_1,(longlong)local_b8);
  FUN_180007de0(local_b8,"version1\n",in_R8,in_R9);
  FUN_180016870((longlong *)param_1,(longlong)local_b8);
  SaveAsTextV1(this,param_1);
  FUN_180007de0(local_b8,"endlibrary\n",in_R8,in_R9);
  FUN_180016870((longlong *)param_1,(longlong)local_b8);
  return 0;
}

/* ---- FUNC 00015710 SaveAsTextV1 (655 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: int __cdecl CApwnLibraries::SaveAsTextV1(struct IStream * __ptr64) __ptr64 */

int __thiscall CApwnLibraries::SaveAsTextV1(CApwnLibraries *this,IStream *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  undefined8 uVar9;
  undefined8 in_R9;
  undefined1 auStack_118 [32];
  undefined8 local_f8;
  undefined8 local_f0;
  undefined1 local_e8 [160];
  ulonglong local_48;
  
                    /* 0x15710  180  ?SaveAsTextV1@CApwnLibraries@@QEAAHPEAUIStream@@@Z */
  local_48 = DAT_1800791f8 ^ (ulonglong)auStack_118;
  uVar3 = CountLibraries(this);
  FUN_180007de0(local_e8,"NumLibs = %d\n",(ulonglong)uVar3,in_R9);
  FUN_180016870((longlong *)param_1,(longlong)local_e8);
  uVar8 = 0;
  iVar4 = CountLibraries(this);
  uVar6 = uVar8;
  uVar7 = uVar8;
  if (0 < iVar4) {
    do {
      if (((longlong)uVar6 < 0) || (*(longlong *)(this + 0x18) <= (longlong)uVar6)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_f8,
                 *(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> **)
                  (*(longlong *)(this + 0x10) + uVar6 * 8));
      FUN_180007de0(local_e8,&DAT_180053c08,local_f8,in_R9);
      FUN_180016870((longlong *)param_1,(longlong)local_e8);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_f8);
      uVar3 = (int)uVar7 + 1;
      iVar4 = CountLibraries(this);
      uVar6 = uVar6 + 1;
      uVar7 = (ulonglong)uVar3;
    } while ((int)uVar3 < iVar4);
  }
  FUN_180007de0(local_e8,"NumCats = %d\n",(ulonglong)(*(int *)(this + 0x40) - 1),in_R9);
  FUN_180016870((longlong *)param_1,(longlong)local_e8);
  if (DAT_18007a048 == (FARPROC)0x0) {
    DAT_18007a048 = GetProcAddress(DAT_18007a040,"BLGetCategoryNameByDisplayName");
  }
  uVar6 = uVar8;
  if (0 < *(longlong *)(this + 0x40)) {
    do {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_f8);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_f0);
      if (((longlong)uVar8 < 0) || (*(longlong *)(this + 0x40) <= (longlong)uVar8)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      plVar1 = *(longlong **)(*(longlong *)(this + 0x38) + uVar8 * 8);
      lVar2 = *plVar1;
      pcVar5 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)&local_f8,0x40);
      (**(code **)(lVar2 + 0x18))(plVar1,pcVar5,0x40);
      ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)&local_f8,-1);
      pcVar5 = (char *)(*DAT_18007a048)(local_f8);
      if (pcVar5 == (char *)0x0) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_f0,
                   (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                   &local_f8);
      }
      else {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_f0,pcVar5
                  );
      }
      iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_f0,
                         _m_streams);
      if (iVar4 != 0) {
        uVar9 = local_f0;
        FUN_180007de0(local_e8,&DAT_180053c08,local_f0,in_R9);
        FUN_180016870((longlong *)param_1,(longlong)local_e8);
        pcVar5 = "active\n";
        if ((int)plVar1[8] == 0) {
          pcVar5 = "inactive\n";
        }
        FUN_180007de0(local_e8,pcVar5,uVar9,in_R9);
        FUN_180016870((longlong *)param_1,(longlong)local_e8);
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_f0);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_f8);
      uVar3 = (int)uVar6 + 1;
      uVar8 = uVar8 + 1;
      uVar6 = (ulonglong)uVar3;
    } while ((longlong)(int)uVar3 < *(longlong *)(this + 0x40));
  }
  return 0;
}

/* ---- FUNC 000159A0 SaveIconDefaults (162 bytes) ---- */

/* public: bool __cdecl CApwnLibraries::SaveIconDefaults(void) __ptr64 */

bool __thiscall CApwnLibraries::SaveIconDefaults(CApwnLibraries *this)

{
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar1;
  longlong *plVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res10 [8];
  longlong *local_res18;
  
                    /* 0x159a0  181  ?SaveIconDefaults@CApwnLibraries@@QEAA_NXZ */
  iVar4 = 0;
  iVar3 = CountLibraries(this);
  if (0 < iVar3) {
    lVar5 = 0;
    do {
      if ((lVar5 < 0) || (*(longlong *)(this + 0x18) <= lVar5)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      pCVar1 = *(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> **)
                (*(longlong *)(this + 0x10) + lVar5 * 8);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res10,pCVar1);
      plVar2 = *(longlong **)(pCVar1 + 8);
      local_res18 = plVar2;
      if (plVar2 != (longlong *)0x0) {
        (**(code **)(*plVar2 + 8))(plVar2);
      }
      this = (CApwnLibraries *)FUN_1800151c0(plVar2);
      if (plVar2 != (longlong *)0x0) {
        (**(code **)(*plVar2 + 0x10))(plVar2);
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res10);
      iVar4 = iVar4 + 1;
      lVar5 = lVar5 + 1;
      iVar3 = CountLibraries(this);
    } while (iVar4 < iVar3);
  }
  return true;
}

/* ---- FUNC 00015A50 SaveToRegistry (753 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: int __cdecl CApwnLibraries::SaveToRegistry(void) __ptr64 */

int __thiscall CApwnLibraries::SaveToRegistry(CApwnLibraries *this)

{
  longlong *plVar1;
  longlong lVar2;
  bool bVar3;
  undefined1 auVar4 [16];
  DWORD DVar5;
  DWORD DVar6;
  int iVar7;
  __uint64 _Var8;
  void *pvVar9;
  void *pvVar10;
  char *pcVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  uint uVar15;
  ulonglong uVar16;
  char *local_res8;
  undefined **local_78 [5];
  CStringArray local_50 [40];
  
                    /* 0x15a50  182  ?SaveToRegistry@CApwnLibraries@@QEAAHXZ */
  DVar5 = APModLibCount();
  uVar13 = (ulonglong)(int)DVar5;
  CPtrArray::CPtrArray((CPtrArray *)local_78);
  local_78[0] = CTypedPtrArray<CPtrArray,CNameAndPos*___ptr64>::vftable;
  CStringArray::CStringArray(local_50);
  auVar4._8_8_ = 0;
  auVar4._0_8_ = uVar13;
  _Var8 = SUB168(ZEXT816(8) * auVar4,0);
  if (SUB168(ZEXT816(8) * auVar4,8) != 0) {
    _Var8 = 0xffffffffffffffff;
  }
  pvVar9 = operator_new__(_Var8);
  uVar14 = 0;
  uVar12 = uVar14;
  if (0 < (int)DVar5) {
    do {
      pvVar10 = operator_new__(0x40);
      *(void **)((longlong)pvVar9 + uVar12 * 8) = pvVar10;
      uVar12 = uVar12 + 1;
    } while ((longlong)uVar12 < (longlong)uVar13);
  }
  DVar6 = APModLibListLibs((longlong)pvVar9,DVar5,0x40);
  if ((DVar6 == 1) && (uVar12 = uVar14, 0 < (int)DVar5)) {
    do {
      APModLibUpdateLib(*(longlong *)((longlong)pvVar9 + uVar12 * 8),0,0);
      uVar12 = uVar12 + 1;
    } while ((longlong)uVar12 < (longlong)uVar13);
  }
  APModLibSetBuiltin(0,0);
  APModLibSetCapeOpen(0,0);
  FUN_180036030(0,0);
  if (0 < *(int *)(this + 0x18)) {
    uVar12 = uVar14;
    uVar15 = 1;
    do {
      if (((longlong)uVar12 < 0) || (*(longlong *)(this + 0x18) <= (longlong)uVar12)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8,
                 *(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> **)
                  (*(longlong *)(this + 0x10) + uVar12 * 8));
      iVar7 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                         &local_res8,_m_builtin);
      if (iVar7 == 0) {
        APModLibSetBuiltin(1,uVar15);
      }
      else {
        iVar7 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_res8,_m_capeopen);
        if (iVar7 == 0) {
          APModLibSetCapeOpen(1,uVar15);
        }
        else {
          iVar7 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &local_res8,_m_acmcatalog);
          if (iVar7 == 0) {
            FUN_180036030(1,uVar15);
          }
          else {
            APModLibUpdateLib((longlong)local_res8,uVar15,1);
          }
        }
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8);
      uVar12 = uVar12 + 1;
      bVar3 = (int)uVar15 < *(int *)(this + 0x18);
      uVar15 = uVar15 + 1;
    } while (bVar3);
  }
  APModCatUnregisterAll();
  uVar12 = uVar14;
  uVar16 = uVar14;
  if (0 < *(longlong *)(this + 0x40)) {
    do {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8);
      if (((longlong)uVar12 < 0) || (*(longlong *)(this + 0x40) <= (longlong)uVar12)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      plVar1 = *(longlong **)(*(longlong *)(this + 0x38) + uVar12 * 8);
      lVar2 = *plVar1;
      pcVar11 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)&local_res8,0x40);
      (**(code **)(lVar2 + 0x18))(plVar1,pcVar11,0x40);
      ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)&local_res8,-1);
      iVar7 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                         &local_res8,_m_streams);
      if (iVar7 != 0) {
        APModCatRegisterCat(local_res8,(int)uVar16,(int)plVar1[8]);
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8);
      uVar15 = (int)uVar16 + 1;
      uVar12 = uVar12 + 1;
      uVar16 = (ulonglong)uVar15;
    } while ((longlong)(int)uVar15 < *(longlong *)(this + 0x40));
  }
  if (0 < (longlong)uVar13) {
    do {
      operator_delete__(*(void **)((longlong)pvVar9 + uVar14 * 8));
      uVar14 = uVar14 + 1;
    } while ((longlong)uVar14 < (longlong)uVar13);
  }
  operator_delete__(pvVar9);
  CStringArray::~CStringArray(local_50);
  CPtrArray::~CPtrArray((CPtrArray *)local_78);
  return 0;
}

/* ---- FUNC 00015D50 SaveV1 (479 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: int __cdecl CApwnLibraries::SaveV1(char * __ptr64 * __ptr64,int * __ptr64) __ptr64 */

int __thiscall CApwnLibraries::SaveV1(CApwnLibraries *this,char **param_1,int *param_2)

{
  longlong *plVar1;
  longlong lVar2;
  int iVar3;
  char *pcVar4;
  ulonglong uVar5;
  uint uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  void *local_res8;
  undefined8 local_res20;
  
                    /* 0x15d50  183  ?SaveV1@CApwnLibraries@@QEAAHPEAPEADPEAH@Z */
  FUN_180016850((longlong *)param_1,*(undefined4 *)(this + 0x18),param_2);
  uVar5 = 0;
  uVar7 = uVar5;
  uVar8 = uVar5;
  if (0 < *(int *)(this + 0x18)) {
    do {
      if (((longlong)uVar8 < 0) || (*(longlong *)(this + 0x18) <= (longlong)uVar8)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      FUN_1800168b0((longlong *)param_1,
                    (void *)**(undefined8 **)(*(longlong *)(this + 0x10) + uVar8 * 8),param_2);
      uVar6 = (int)uVar7 + 1;
      uVar7 = (ulonglong)uVar6;
      uVar8 = uVar8 + 1;
    } while ((int)uVar6 < *(int *)(this + 0x18));
  }
  FUN_180016850((longlong *)param_1,*(int *)(this + 0x40) + -1,param_2);
  if (DAT_18007a048 == (FARPROC)0x0) {
    DAT_18007a048 = GetProcAddress(DAT_18007a040,"BLGetCategoryNameByDisplayName");
  }
  uVar7 = uVar5;
  if (0 < *(longlong *)(this + 0x40)) {
    do {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8);
      if (((longlong)uVar5 < 0) || (*(longlong *)(this + 0x40) <= (longlong)uVar5)) {
LAB_180015f24:
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      plVar1 = *(longlong **)(*(longlong *)(this + 0x38) + uVar5 * 8);
      lVar2 = *plVar1;
      pcVar4 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)&local_res20,0x40);
      (**(code **)(lVar2 + 0x18))(plVar1,pcVar4,0x40);
      ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)&local_res20,-1);
      pcVar4 = (char *)(*DAT_18007a048)(local_res20);
      if (pcVar4 == (char *)0x0) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8,
                   (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                   &local_res20);
      }
      else {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8,
                   pcVar4);
      }
      iVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                         &local_res8,_m_streams);
      if (iVar3 != 0) {
        FUN_1800168b0((longlong *)param_1,local_res8,param_2);
        if (*(longlong *)(this + 0x40) <= (longlong)uVar5) goto LAB_180015f24;
        FUN_180016850((longlong *)param_1,
                      *(undefined4 *)(*(longlong *)(*(longlong *)(this + 0x38) + uVar5 * 8) + 0x40),
                      param_2);
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20);
      uVar6 = (int)uVar7 + 1;
      uVar5 = uVar5 + 1;
      uVar7 = (ulonglong)uVar6;
    } while ((longlong)(int)uVar6 < *(longlong *)(this + 0x40));
  }
  if (param_2 == (int *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *param_2;
  }
  return iVar3;
}

/* ---- FUNC 00015F30 SaveV2 (88 bytes) ---- */

/* public: int __cdecl CApwnLibraries::SaveV2(char * __ptr64 * __ptr64,int * __ptr64) __ptr64 */

int __thiscall CApwnLibraries::SaveV2(CApwnLibraries *this,char **param_1,int *param_2)

{
                    /* 0x15f30  184  ?SaveV2@CApwnLibraries@@QEAAHPEAPEADPEAH@Z */
  SaveV1(this,param_1,param_2);
  FUN_180015120((longlong *)(this + 0x90),(longlong *)param_1,param_2);
  if (param_2 != (int *)0x0) {
    return *param_2;
  }
  return 0;
}

/* ---- FUNC 00015F90 FUN_180015f90 (1300 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_180015f90(undefined8 *param_1)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  DWORD DVar7;
  undefined8 uVar8;
  longlong lVar9;
  BYTE *pBVar10;
  longlong lVar11;
  int iVar12;
  undefined1 auStackY_128 [32];
  longlong *local_f8;
  DWORD local_f0 [2];
  longlong *local_e8;
  DWORD local_e0;
  undefined4 local_dc;
  undefined4 local_d8 [2];
  longlong *local_d0;
  longlong *local_c8;
  longlong *local_c0;
  longlong *local_b8;
  longlong *local_b0;
  undefined1 local_a8 [4];
  undefined1 local_a4 [4];
  HKEY local_a0;
  longlong *local_98;
  undefined *local_90;
  HKEY local_88;
  undefined4 local_80;
  undefined8 local_78;
  BYTE local_70 [32];
  CHAR local_50 [32];
  ulonglong local_30;
  
  local_30 = DAT_1800791f8 ^ (ulonglong)auStackY_128;
  uVar8 = FUN_180010bb0();
  if ((int)uVar8 == 0) {
    local_b8 = (longlong *)0x0;
    if ((param_1 != (undefined8 *)0x0) &&
       (iVar4 = (**(code **)*param_1)(param_1,&DAT_180053510,&local_b8), iVar4 < 0)) {
      local_b8 = (longlong *)0x0;
    }
    plVar3 = local_b8;
    local_98 = local_b8;
    if (local_b8 != (longlong *)0x0) {
      (**(code **)(*local_b8 + 8))();
    }
    iVar4 = 1;
    if (plVar3 != (longlong *)0x0) {
      local_f0[0] = 4;
      iVar4 = 1;
      local_dc = 1;
      local_e0 = 4;
      local_90 = &DAT_180053988;
      RegOpenKeyExA((HKEY)&DAT_ffffffff80000001,&DAT_18007a160,0,0x20019,&local_a0);
      local_88 = local_a0;
      local_80 = 0;
      local_78 = 0;
      local_b0 = (longlong *)0x0;
      iVar5 = (**(code **)(*plVar3 + 0x40))(plVar3,&local_b0);
      if (-1 < iVar5) {
        local_c0 = (longlong *)0x0;
        local_d8[0] = 0;
        iVar12 = 1;
        iVar5 = (**(code **)(*local_b0 + 0x18))(local_b0,1,&local_c0,local_d8);
        while (iVar5 == 0) {
          local_f8 = (longlong *)0x0;
          local_e8 = (longlong *)0x0;
          iVar5 = (**(code **)(*local_c0 + 0x18))(local_c0,local_50,0x20);
          plVar2 = local_f8;
          if (iVar5 < 0) {
            if (local_e8 != (longlong *)0x0) {
              (**(code **)(*local_e8 + 0x10))();
            }
            if (local_f8 != (longlong *)0x0) {
              lVar11 = *local_f8;
LAB_1800163c4:
              (**(code **)(lVar11 + 0x10))(local_f8);
            }
          }
          else {
            if (local_f8 != local_c0) {
              if ((local_c0 == (longlong *)0x0) ||
                 (iVar5 = (**(code **)*local_c0)(local_c0,&DAT_180053f18,&local_f8), iVar5 < 0)) {
                local_f8 = (longlong *)0x0;
              }
              if (plVar2 != (longlong *)0x0) {
                (**(code **)(*plVar2 + 0x10))(plVar2);
              }
            }
            if (local_f8 != (longlong *)0x0) {
              iVar5 = 1;
              iVar4 = iVar12;
              if (local_a0 != (HKEY)0x0) {
                local_f0[0] = 4;
                local_dc = 1;
                local_e0 = 4;
                pBVar10 = (BYTE *)&local_dc;
                iVar6 = RegQueryValueExA(local_a0,local_50,(LPDWORD)0x0,local_f0,(LPBYTE)&local_dc,
                                         &local_e0);
                iVar4 = iVar5;
                if (iVar6 == 0xea) {
                  if (0x1f < local_e0) goto LAB_1800162a8;
                  pBVar10 = local_70;
                  local_f0[0] = 1;
                  iVar6 = RegQueryValueExA(local_a0,local_50,(LPDWORD)0x0,local_f0,local_70,
                                           &local_e0);
                }
                if (iVar6 == 0) {
                  if (local_f0[0] == 4) {
                    local_d0 = (longlong *)0x0;
                    iVar6 = (**(code **)(*local_f8 + 0x48))(local_f8,&local_d0);
                    iVar4 = iVar12;
                    if ((((-1 < iVar6) && (local_d0 != (longlong *)0x0)) &&
                        (iVar6 = (**(code **)(*local_d0 + 0x20))(local_d0,local_dc), iVar4 = iVar5,
                        -1 < iVar6)) &&
                       ((iVar6 = (**(code **)(*local_d0 + 0x18))(local_d0,1,&local_e8,local_a8),
                        -1 < iVar6 && (local_e8 != (longlong *)0x0)))) {
                      iVar4 = (**(code **)(*local_f8 + 0x20))(local_f8,local_e8);
                    }
                    if (local_d0 != (longlong *)0x0) {
                      (**(code **)(*local_d0 + 0x10))();
                    }
                  }
                  else {
                    if (local_f0[0] != 1) goto LAB_1800162a8;
                    (**(code **)(*local_f8 + 0x40))(local_f8,pBVar10,&local_e8);
                    iVar4 = (**(code **)(*local_f8 + 0x20))(local_f8,local_e8);
                  }
                  if (iVar4 == 0) goto LAB_1800163a0;
                }
              }
LAB_1800162a8:
              DVar7 = GetPrivateProfileStringA
                                ("IconDef",local_50,"",(LPSTR)local_70,0x20,&DAT_18007a050);
              if (DVar7 != 0) {
                lVar11 = -1;
                do {
                  lVar9 = lVar11 + 1;
                  lVar1 = lVar11 + 1;
                  lVar11 = lVar9;
                } while (local_70[lVar1] != '\0');
                iVar5 = (int)lVar9;
                lVar11 = 0;
                if (0 < iVar5) {
                  do {
                    iVar6 = isdigit((int)(char)local_70[lVar11]);
                    if (iVar6 == 0) {
                      (**(code **)(*local_f8 + 0x40))(local_f8,local_70,&local_e8);
                      iVar4 = (**(code **)(*local_f8 + 0x20))(local_f8,local_e8);
                      goto LAB_1800163a0;
                    }
                    lVar11 = lVar11 + 1;
                  } while (lVar11 < iVar5);
                }
                iVar5 = atoi((char *)local_70);
                local_c8 = (longlong *)0x0;
                iVar6 = (**(code **)(*local_f8 + 0x48))(local_f8,&local_c8);
                if (((-1 < iVar6) && (local_c8 != (longlong *)0x0)) &&
                   ((iVar5 = (**(code **)(*local_c8 + 0x20))(local_c8,iVar5), -1 < iVar5 &&
                    ((iVar5 = (**(code **)(*local_c8 + 0x18))(local_c8,1,&local_e8,local_a4),
                     -1 < iVar5 && (local_e8 != (longlong *)0x0)))))) {
                  iVar4 = (**(code **)(*local_f8 + 0x20))(local_f8,local_e8);
                }
                if (local_c8 != (longlong *)0x0) {
                  (**(code **)(*local_c8 + 0x10))();
                }
              }
            }
LAB_1800163a0:
            if (local_e8 != (longlong *)0x0) {
              (**(code **)(*local_e8 + 0x10))(local_e8);
            }
            if (local_f8 != (longlong *)0x0) {
              lVar11 = *local_f8;
              goto LAB_1800163c4;
            }
          }
          plVar2 = local_c0;
          if (local_c0 != (longlong *)0x0) {
            local_c0 = (longlong *)0x0;
            (**(code **)(*plVar2 + 0x10))();
          }
          iVar5 = (**(code **)(*local_b0 + 0x18))(local_b0,1,&local_c0,local_d8);
        }
        if (local_c0 != (longlong *)0x0) {
          (**(code **)(*local_c0 + 0x10))();
        }
      }
      if (local_b0 != (longlong *)0x0) {
        (**(code **)(*local_b0 + 0x10))();
      }
      if (local_a0 != (HKEY)0x0) {
        RegCloseKey(local_a0);
      }
    }
    if (plVar3 != (longlong *)0x0) {
      (**(code **)(*plVar3 + 0x10))(plVar3);
    }
    if (local_b8 != (longlong *)0x0) {
      (**(code **)(*local_b8 + 0x10))();
    }
  }
  else {
    iVar4 = 1;
  }
  return iVar4;
}

/* ---- FUNC 000164B0 FUN_1800164b0 (55 bytes) ---- */

void FUN_1800164b0(longlong param_1,longlong *param_2)

{
  if (*(longlong **)(param_1 + 8) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(param_1 + 8) + 0x10))();
  }
  *(longlong **)(param_1 + 8) = param_2;
                    /* WARNING: Could not recover jumptable at 0x0001800164e3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_2 + 8))(param_2);
  return;
}

/* ---- FUNC 000164F0 FUN_1800164f0 (21 bytes) ---- */

undefined8 FUN_1800164f0(longlong param_1,char *param_2)

{
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0x10),
             param_2);
  return 0;
}

/* ---- FUNC 00016510 FUN_180016510 (25 bytes) ---- */

undefined8 FUN_180016510(longlong param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = param_2 + *(int *)(param_1 + 0x38);
  *(uint *)(param_1 + 0x38) = uVar1;
  if (*(uint *)(param_1 + 0x34) <= uVar1) {
    *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x34);
    return 1;
  }
  return 0;
}

/* ---- FUNC 00016530 FUN_180016530 (25 bytes) ---- */

undefined8 FUN_180016530(longlong param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = param_2 + *(int *)(param_1 + 0x14);
  *(uint *)(param_1 + 0x14) = uVar1;
  if (*(uint *)(param_1 + 0x10) <= uVar1) {
    *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x10);
    return 1;
  }
  return 0;
}

/* ---- FUNC 00016550 UpdateAPMfilesInTheCurrentDirectory (569 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: void __cdecl CApwnLibraries::UpdateAPMfilesInTheCurrentDirectory(void) __ptr64 */

void __thiscall CApwnLibraries::UpdateAPMfilesInTheCurrentDirectory(CApwnLibraries *this)

{
  CApwnLibraries *pCVar1;
  longlong *plVar2;
  longlong lVar3;
  int iVar4;
  HANDLE hFindFile;
  void *pvVar5;
  ulonglong uVar6;
  size_t sVar7;
  size_t sVar8;
  undefined1 auStack_198 [32];
  void *local_178;
  longlong lStack_170;
  longlong local_168;
  ulonglong uStack_160;
  _WIN32_FIND_DATAA local_158;
  ulonglong local_18;
  
                    /* 0x16550  189  ?UpdateAPMfilesInTheCurrentDirectory@CApwnLibraries@@QEAAXXZ */
  local_18 = DAT_1800791f8 ^ (ulonglong)auStack_198;
  pCVar1 = this + 0xc0;
  if (*(longlong **)pCVar1 != *(longlong **)(this + 200)) {
    FUN_1800081e0(*(longlong **)pCVar1,*(longlong **)(this + 200));
    *(longlong *)(this + 200) = *(longlong *)pCVar1;
  }
  hFindFile = FindFirstFileA("*.apm",&local_158);
  if (hFindFile != (HANDLE)0xffffffffffffffff) {
    local_178 = (void *)0x0;
    lStack_170 = 0;
    local_168 = 0;
    uStack_160 = 0;
    sVar8 = 0xffffffffffffffff;
    do {
      sVar7 = sVar8 + 1;
      lVar3 = sVar8 + 1;
      sVar8 = sVar7;
    } while (local_158.cFileName[lVar3] != '\0');
    FUN_18000b5f0(&local_178,local_158.cFileName,sVar7);
    plVar2 = *(longlong **)(this + 200);
    if (plVar2 == *(longlong **)(this + 0xd0)) {
      FUN_180008500((longlong *)pCVar1,plVar2,&local_178);
      uVar6 = uStack_160;
    }
    else {
      *plVar2 = (longlong)local_178;
      plVar2[1] = lStack_170;
      plVar2[2] = local_168;
      plVar2[3] = uStack_160;
      local_178 = (void *)((ulonglong)local_178 & 0xffffffffffffff00);
      *(longlong *)(this + 200) = *(longlong *)(this + 200) + 0x20;
      uVar6 = 0xf;
    }
    if (0xf < uVar6) {
      pvVar5 = local_178;
      if ((0xfff < uVar6 + 1) &&
         (pvVar5 = *(void **)((longlong)local_178 + -8),
         0x1f < (ulonglong)((longlong)local_178 + (-8 - (longlong)pvVar5)))) {
LAB_180016783:
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      operator_delete(pvVar5);
    }
    iVar4 = FindNextFileA(hFindFile,&local_158);
    while (iVar4 != 0) {
      local_178 = (void *)0x0;
      lStack_170 = 0;
      local_168 = 0;
      uStack_160 = 0;
      sVar8 = 0xffffffffffffffff;
      do {
        sVar7 = sVar8 + 1;
        lVar3 = sVar8 + 1;
        sVar8 = sVar7;
      } while (local_158.cFileName[lVar3] != '\0');
      FUN_18000b5f0(&local_178,local_158.cFileName,sVar7);
      plVar2 = *(longlong **)(this + 200);
      if (plVar2 == *(longlong **)(this + 0xd0)) {
        FUN_180008500((longlong *)pCVar1,plVar2,&local_178);
        uVar6 = uStack_160;
      }
      else {
        *plVar2 = (longlong)local_178;
        plVar2[1] = lStack_170;
        plVar2[2] = local_168;
        plVar2[3] = uStack_160;
        local_178 = (void *)((ulonglong)local_178 & 0xffffffffffffff00);
        *(longlong *)(this + 200) = *(longlong *)(this + 200) + 0x20;
        uVar6 = 0xf;
      }
      if (0xf < uVar6) {
        pvVar5 = local_178;
        if ((0xfff < uVar6 + 1) &&
           (pvVar5 = *(void **)((longlong)local_178 + -8),
           0x1f < (ulonglong)((longlong)local_178 + (-8 - (longlong)pvVar5)))) goto LAB_180016783;
        operator_delete(pvVar5);
      }
      iVar4 = FindNextFileA(hFindFile,&local_158);
    }
    FindClose(hFindFile);
  }
  return;
}

/* ---- FUNC 00016790 UpdateLibCache (18 bytes) ---- */

/* public: void __cdecl CApwnLibraries::UpdateLibCache(void) __ptr64 */

void __thiscall CApwnLibraries::UpdateLibCache(CApwnLibraries *this)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  
                    /* 0x16790  190  ?UpdateLibCache@CApwnLibraries@@QEAAXXZ */
  iVar2 = *(int *)(this + 0x68) + -1;
  if (-1 < iVar2) {
    lVar4 = (longlong)iVar2;
    lVar3 = -lVar4;
    lVar5 = lVar4;
    do {
      do {
        if ((lVar4 < 0) || (*(longlong *)(this + 0x68) <= lVar4)) {
                    /* WARNING: Subroutine does not return */
          AfxThrowInvalidArgException();
        }
        pCVar1 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
                  (*(longlong *)(this + 0x60) + lVar4 * 8);
        if (pCVar1 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
          FUN_18000d210(pCVar1);
          operator_delete(pCVar1);
        }
        lVar4 = lVar4 + -1;
      } while (-1 < lVar3 + lVar4);
      CPtrArray::RemoveAt((CPtrArray *)(this + 0x58),(longlong)iVar2,1);
      lVar4 = lVar5 + -1;
      lVar3 = lVar3 + 1;
      iVar2 = iVar2 + -1;
      lVar5 = lVar4;
    } while (-1 < iVar2);
  }
  return;
}

/* ---- FUNC 000167A2 FUN_1800167a2 (156 bytes) ---- */

void FUN_1800167a2(longlong param_1)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar1;
  int unaff_EBP;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar3 = (longlong)unaff_EBP;
  lVar2 = -lVar3;
  lVar4 = lVar3;
  while ((-1 < lVar3 && (lVar3 < *(longlong *)(param_1 + 0x68)))) {
    pCVar1 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
              (*(longlong *)(param_1 + 0x60) + lVar3 * 8);
    if (pCVar1 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
      FUN_18000d210(pCVar1);
      operator_delete(pCVar1);
    }
    lVar3 = lVar3 + -1;
    if (lVar2 + lVar3 < 0) {
      CPtrArray::RemoveAt((CPtrArray *)(param_1 + 0x58),(longlong)unaff_EBP,1);
      lVar3 = lVar4 + -1;
      lVar2 = lVar2 + 1;
      unaff_EBP = unaff_EBP + -1;
      lVar4 = lVar3;
      if (unaff_EBP < 0) {
        return;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 0001683E FUN_18001683e (6 bytes) ---- */

void FUN_18001683e(void)

{
  return;
}

/* ---- FUNC 00016844 AfxThrowInvalidArgException (5 bytes) ---- */

void __cdecl AfxThrowInvalidArgException(void)

{
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 00016850 FUN_180016850 (29 bytes) ---- */

void FUN_180016850(longlong *param_1,undefined4 param_2,int *param_3)

{
  if ((param_1 != (longlong *)0x0) && ((undefined4 *)*param_1 != (undefined4 *)0x0)) {
    *(undefined4 *)*param_1 = param_2;
    *param_1 = *param_1 + 4;
  }
  if (param_3 != (int *)0x0) {
    *param_3 = *param_3 + 4;
  }
  return;
}

/* ---- FUNC 00016870 FUN_180016870 (53 bytes) ---- */

ulonglong FUN_180016870(longlong *param_1,longlong param_2)

{
  int iVar1;
  ulonglong uVar2;
  
  uVar2 = 0xffffffffffffffff;
  if (param_1 != (longlong *)0x0) {
    do {
      uVar2 = uVar2 + 1;
    } while (*(char *)(param_2 + uVar2) != '\0');
    iVar1 = (**(code **)(*param_1 + 0x20))(param_1,param_2,uVar2,0);
    uVar2 = (ulonglong)((-1 < iVar1) - 1);
  }
  return uVar2;
}

/* ---- FUNC 000168B0 FUN_1800168b0 (10 bytes) ---- */

void FUN_1800168b0(longlong *param_1,void *param_2,int *param_3)

{
  int iVar1;
  longlong lVar2;
  
  lVar2 = -1;
  do {
    lVar2 = lVar2 + 1;
  } while (*(char *)((longlong)param_2 + lVar2) != '\0');
  iVar1 = (int)lVar2;
  if ((param_1 != (longlong *)0x0) && ((int *)*param_1 != (int *)0x0)) {
    *(int *)*param_1 = iVar1;
    *param_1 = *param_1 + 4;
    memcpy((void *)*param_1,param_2,(longlong)iVar1);
    *param_1 = *param_1 + (longlong)iVar1;
  }
  if (param_3 != (int *)0x0) {
    *param_3 = *param_3 + iVar1 + 4;
  }
  return;
}

/* ---- FUNC 000168BA FUN_1800168ba (53 bytes) ---- */

void FUN_1800168ba(longlong *param_1,void *param_2,int *param_3)

{
  int iVar1;
  longlong lVar2;
  
  lVar2 = -1;
  do {
    lVar2 = lVar2 + 1;
  } while (*(char *)((longlong)param_2 + lVar2) != '\0');
  iVar1 = (int)lVar2;
  if ((param_1 != (longlong *)0x0) && ((int *)*param_1 != (int *)0x0)) {
    *(int *)*param_1 = iVar1;
    *param_1 = *param_1 + 4;
    memcpy((void *)*param_1,param_2,(longlong)iVar1);
    *param_1 = *param_1 + (longlong)iVar1;
  }
  if (param_3 != (int *)0x0) {
    *param_3 = *param_3 + iVar1 + 4;
  }
  return;
}

/* ---- FUNC 000168EF FUN_1800168ef (24 bytes) ---- */

void FUN_1800168ef(void *param_1,void *param_2)

{
  int unaff_EBX;
  int *unaff_RBP;
  longlong *unaff_RSI;
  
  memcpy(param_1,param_2,(longlong)unaff_EBX);
  *unaff_RSI = *unaff_RSI + (longlong)unaff_EBX;
  if (unaff_RBP != (int *)0x0) {
    *unaff_RBP = *unaff_RBP + unaff_EBX + 4;
  }
  return;
}

/* ---- FUNC 00016907 FUN_180016907 (10 bytes) ---- */

void FUN_180016907(void)

{
  int unaff_EBX;
  int *unaff_RBP;
  
  if (unaff_RBP != (int *)0x0) {
    *unaff_RBP = *unaff_RBP + unaff_EBX + 4;
  }
  return;
}

/* ---- FUNC 00016911 FUN_180016911 (17 bytes) ---- */

void FUN_180016911(void)

{
  int unaff_EBX;
  int *unaff_RBP;
  
  *unaff_RBP = *unaff_RBP + unaff_EBX + 4;
  return;
}

/* ---- FUNC 00016930 FID_conflict:_Change_array (135 bytes) ---- */

/* Library Function - Multiple Matches With Different Base Names
    private: void __cdecl std::vector<struct CHN * __ptr64,class std::allocator<struct CHN *
   __ptr64> >::_Change_array(struct CHN * __ptr64 * __ptr64 const,unsigned __int64,unsigned __int64)
   __ptr64
    private: void __cdecl std::vector<unsigned __int64,struct std::_Parallelism_allocator<unsigned
   __int64> >::_Change_array(unsigned __int64 * __ptr64 const,unsigned __int64,unsigned __int64)
   __ptr64
    private: void __cdecl std::vector<unsigned __int64,class std::allocator<unsigned __int64>
   >::_Change_array(unsigned __int64 * __ptr64 const,unsigned __int64,unsigned __int64) __ptr64
   
   Library: Visual Studio 2019 Release */

void FID_conflict__Change_array
               (longlong *param_1,longlong param_2,longlong param_3,longlong param_4)

{
  void *pvVar1;
  void *pvVar2;
  
  pvVar1 = (void *)*param_1;
  if (pvVar1 != (void *)0x0) {
    pvVar2 = pvVar1;
    if ((0xfff < (param_1[2] - (longlong)pvVar1 & 0xfffffffffffffffcU)) &&
       (pvVar2 = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar2)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar2);
  }
  *param_1 = param_2;
  param_1[1] = param_2 + param_3 * 4;
  param_1[2] = param_2 + param_4 * 4;
  return;
}

/* ---- FUNC 000169C0 FUN_1800169c0 (39 bytes) ---- */

void FUN_1800169c0(longlong *param_1,longlong param_2,longlong param_3,longlong param_4)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar1;
  void *pvVar2;
  void *pvVar3;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this;
  
  this = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)*param_1;
  if (this != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
    pCVar1 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)param_1[1];
    for (; this != pCVar1; this = this + 0x20) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(this + 0x10);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(this + 8);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(this);
    }
    pvVar2 = (void *)*param_1;
    pvVar3 = pvVar2;
    if ((0xfff < (param_1[2] - (longlong)pvVar2 & 0xffffffffffffffe0U)) &&
       (pvVar3 = *(void **)((longlong)pvVar2 + -8),
       0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)pvVar3)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar3);
  }
  *param_1 = param_2;
  param_1[1] = param_3 * 0x20 + param_2;
  param_1[2] = param_4 * 0x20 + param_2;
  return;
}

/* ---- FUNC 000169E7 FUN_1800169e7 (80 bytes) ---- */

void FUN_1800169e7(longlong param_1)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar1;
  void *pvVar2;
  void *pvVar3;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *unaff_RBX;
  longlong unaff_RBP;
  longlong *unaff_RSI;
  longlong unaff_R14;
  longlong unaff_R15;
  
  pCVar1 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)(param_1 + 8);
  for (; unaff_RBX != pCVar1; unaff_RBX = unaff_RBX + 0x20) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(unaff_RBX + 0x10);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(unaff_RBX + 8);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(unaff_RBX);
  }
  pvVar2 = (void *)*unaff_RSI;
  pvVar3 = pvVar2;
  if ((0xfff < (unaff_RSI[2] - (longlong)pvVar2 & 0xffffffffffffffe0U)) &&
     (pvVar3 = *(void **)((longlong)pvVar2 + -8),
     0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)pvVar3)))) {
                    /* WARNING: Subroutine does not return */
    _invalid_parameter_noinfo_noreturn();
  }
  operator_delete(pvVar3);
  *unaff_RSI = unaff_R15;
  unaff_RSI[1] = unaff_R14 * 0x20 + unaff_R15;
  unaff_RSI[2] = unaff_RBP * 0x20 + unaff_R15;
  return;
}

/* ---- FUNC 00016A37 FUN_180016a37 (80 bytes) ---- */

void FUN_180016a37(longlong param_1)

{
  longlong unaff_RBP;
  longlong *unaff_RSI;
  longlong unaff_R14;
  longlong unaff_R15;
  
  if ((param_1 - (longlong)*(void **)(param_1 + -8)) - 8U < 0x20) {
    operator_delete(*(void **)(param_1 + -8));
    *unaff_RSI = unaff_R15;
    unaff_RSI[1] = unaff_R14 * 0x20 + unaff_R15;
    unaff_RSI[2] = unaff_RBP * 0x20 + unaff_R15;
    return;
  }
                    /* WARNING: Subroutine does not return */
  _invalid_parameter_noinfo_noreturn();
}

/* ---- FUNC 00016A90 FUN_180016a90 (155 bytes) ---- */

void FUN_180016a90(longlong *param_1,ulonglong param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong lVar3;
  void *pvVar4;
  
  lVar2 = param_1[1];
  lVar3 = *param_1;
  if (param_2 < 0x4000000000000000) {
    uVar1 = param_2 * 4;
    if (uVar1 < 0x1000) {
      if (uVar1 == 0) {
        pvVar4 = (void *)0x0;
      }
      else {
        pvVar4 = operator_new(uVar1);
      }
    }
    else {
      pvVar4 = (void *)FUN_180007f10(uVar1);
    }
    FUN_18000b700((void *)*param_1,param_1[1],pvVar4);
    FID_conflict__Change_array(param_1,(longlong)pvVar4,lVar2 - lVar3 >> 2,param_2);
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18000ac70();
}

/* ---- FUNC 00016B30 FUN_180016b30 (157 bytes) ---- */

void FUN_180016b30(longlong *param_1,ulonglong param_2)

{
  longlong lVar1;
  longlong lVar2;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar3;
  __uint64 _Var4;
  
  lVar1 = param_1[1];
  lVar2 = *param_1;
  if (param_2 < 0x800000000000000) {
    _Var4 = param_2 << 5;
    if (_Var4 < 0x1000) {
      if (_Var4 == 0) {
        pCVar3 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
      }
      else {
        pCVar3 = operator_new(_Var4);
      }
    }
    else {
      pCVar3 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)FUN_180007f10(_Var4)
      ;
    }
    FUN_18000c210((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                  *param_1,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                            *)param_1[1],pCVar3);
    FUN_1800169c0(param_1,(longlong)pCVar3,lVar1 - lVar2 >> 5,param_2);
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18000ac70();
}

/* ---- FUNC 00016BD0 deallocate (66 bytes) ---- */

/* Library Function - Multiple Matches With Same Base Name
    public: void __cdecl std::allocator<struct `void __cdecl
   phmap::container_internal::Deallocate<4,class std::allocator<unsigned long> >(class
   std::allocator<unsigned long> * __ptr64,void * __ptr64,unsigned
   __int64)'::`2'::M>::deallocate(struct `void __cdecl phmap::container_internal::Deallocate<4,class
   std::allocator<unsigned long> >(class std::allocator<unsigned long> * __ptr64,void *
   __ptr64,unsigned __int64)'::`2'::M * __ptr64 const,unsigned __int64) __ptr64
    public: void __cdecl std::allocator<struct `void __cdecl
   phmap::container_internal::Deallocate<4,class std::allocator<struct std::pair<unsigned long const
   ,unsigned long> > >(class std::allocator<struct std::pair<unsigned long const ,unsigned long> > *
   __ptr64,void * __ptr64,unsigned __int64)'::`2'::M>::deallocate(struct `void __cdecl
   phmap::container_internal::Deallocate<4,class std::allocator<struct std::pair<unsigned long const
   ,unsigned long> > >(class std::allocator<struct std::pair<unsigned long const ,unsigned long> > *
   __ptr64,void * __ptr64,unsigned __int64)'::`2'::M * __ptr64 const,unsigned __int64) __ptr64
    public: static void __cdecl phmap::allocator_traits<class std::allocator<struct `void __cdecl
   phmap::container_internal::Deallocate<4,class std::allocator<unsigned long> >(class
   std::allocator<unsigned long> * __ptr64,void * __ptr64,unsigned __int64)'::`2'::M>
   >::deallocate(class std::allocator<struct `void __cdecl
   phmap::container_internal::Deallocate<4,class std::allocator<unsigned long> >(class
   std::allocator<unsigned long> * __ptr64,void * __ptr64,unsigned __int64)'::`2'::M> &
   __ptr64,struct `void __cdecl phmap::container_internal::Deallocate<4,class
   std::allocator<unsigned long> >(class std::allocator<unsigned long> * __ptr64,void *
   __ptr64,unsigned __int64)'::`2'::M * __ptr64,unsigned __int64)
   
   Library: Visual Studio 2019 Release */

void deallocate(undefined8 param_1,void *param_2,longlong param_3)

{
  void *pvVar1;
  
  pvVar1 = param_2;
  if ((0xfff < (ulonglong)(param_3 * 4)) &&
     (pvVar1 = *(void **)((longlong)param_2 + -8),
     0x1f < (ulonglong)((longlong)param_2 + (-8 - (longlong)pvVar1)))) {
                    /* WARNING: Subroutine does not return */
    _invalid_parameter_noinfo_noreturn();
  }
  operator_delete(pvVar1);
  return;
}

/* ---- FUNC 00016C20 ApwnActiveLibrary (27 bytes) ---- */

int ApwnActiveLibrary(char *param_1)

{
  int iVar1;
  
                    /* 0x16c20  277  ApwnActiveLibrary */
  if (g_pApwnLibs == (CApwnLibraries *)0x0) {
    return -1;
  }
  iVar1 = CApwnLibraries::AddNewLibrary(g_pApwnLibs,param_1,0);
  return iVar1;
}

/* ---- FUNC 00016C40 ApwnAddModelType (33 bytes) ---- */

bool ApwnAddModelType(char *param_1,char *param_2,IAModelType *param_3)

{
  bool bVar1;
  
                    /* 0x16c40  278  ApwnAddModelType */
  bVar1 = CApwnLibraries::AddModelType(g_pApwnLibs,param_1,param_2,param_3);
  return bVar1;
}

/* ---- FUNC 00016C70 ApwnAddPaletteCategories (175 bytes) ---- */

uint ApwnAddPaletteCategories(char *param_1)

{
  int iVar1;
  uint uVar2;
  IAUserModelLibrary *pIVar3;
  IAEditCategories *local_res10;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res18 [16];
  
                    /* 0x16c70  279  ApwnAddPaletteCategories */
  iVar1 = CApwnLibraries::FindApwnLibrary(g_pApwnLibs,param_1);
  if (iVar1 < 0) {
    return 0;
  }
  pIVar3 = CApwnLibraries::GetLibrary(g_pApwnLibs,iVar1);
  local_res10 = (IAEditCategories *)0x0;
  uVar2 = (*(code *)**(undefined8 **)pIVar3)(pIVar3,&DAT_180056230,&local_res10);
  if ((-1 < (int)uVar2) && (local_res10 != (IAEditCategories *)0x0)) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res18,param_1);
    CApwnLibraries::AddPaletteCategories(g_pApwnLibs,local_res18,local_res10);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res18);
    (**(code **)(*(longlong *)local_res10 + 0x10))();
  }
  return ~uVar2 >> 0x1f;
}

/* ---- FUNC 00016D20 ApwnEnumModelTypes (25 bytes) ---- */

__int64 ApwnEnumModelTypes(__int64 *param_1)

{
  __int64 _Var1;
  
                    /* 0x16d20  300  ApwnEnumModelTypes */
  if (g_pApwnLibs == (CApwnLibraries *)0x0) {
    return -1;
  }
  _Var1 = CApwnLibraries::EnumModelTypes(g_pApwnLibs,param_1);
  return _Var1;
}

/* ---- FUNC 00016D40 ApwnFindModelType (15 bytes) ---- */

void ApwnFindModelType(char *param_1)

{
                    /* 0x16d40  301  ApwnFindModelType */
  CApwnLibraries::FindModelType(g_pApwnLibs,param_1);
  return;
}

/* ---- FUNC 00016D50 ApwnGetModelTypeAttr (51 bytes) ---- */

int ApwnGetModelTypeAttr(__int64 param_1,ApwnModelTypeAttr param_2,void *param_3,__uint64 param_4)

{
  int iVar1;
  
                    /* 0x16d50  302  ApwnGetModelTypeAttr */
  if (g_pApwnLibs == (CApwnLibraries *)0x0) {
    return -1;
  }
  iVar1 = CApwnLibraries::GetModelTypeAttr(g_pApwnLibs,param_1,param_2,param_3,param_4);
  return iVar1;
}

/* ---- FUNC 00016D90 ApwnIsReservedDisplayName (15 bytes) ---- */

void ApwnIsReservedDisplayName(char *param_1)

{
                    /* 0x16d90  303  ApwnIsReservedDisplayName */
  CApwnLibraries::IsReservedDisplayName(g_pApwnLibs,param_1);
  return;
}

/* ---- FUNC 00016DA0 ApwnLibGetSaveSize (19 bytes) ---- */

int ApwnLibGetSaveSize(void)

{
  int iVar1;
  
                    /* 0x16da0  304  ApwnLibGetSaveSize */
  if (g_pApwnLibs == (CApwnLibraries *)0x0) {
    return 0;
  }
  iVar1 = CApwnLibraries::DoSave(g_pApwnLibs,(char **)0x0);
  return iVar1;
}

/* ---- FUNC 00016DC0 ApwnLibInitFromRegistry (25 bytes) ---- */

int ApwnLibInitFromRegistry(void)

{
  CApwnLibraries *this;
  int iVar1;
  CStringArray aCStack_58 [16];
  longlong lStack_48;
  undefined **appuStack_30 [5];
  
                    /* 0x16dc0  305  ApwnLibInitFromRegistry */
  this = g_pApwnLibs;
  if (g_pApwnLibs == (CApwnLibraries *)0x0) {
    return -1;
  }
  CStringArray::CStringArray(aCStack_58);
  CApwnLibraries::InitLibFromRegistry(this,aCStack_58);
  CPtrArray::CPtrArray((CPtrArray *)appuStack_30);
  appuStack_30[0] = CNameAndStateArray::vftable;
  CApwnLibraries::InitCatFromRegistry(this,(CNameAndStateArray *)appuStack_30);
  if (lStack_48 == 0) {
    CStringArray::SetAtGrow(aCStack_58,0,&CApwnLibraries::m_builtin);
    CStringArray::SetAtGrow(aCStack_58,lStack_48,&CApwnLibraries::m_capeopen);
    CStringArray::SetAtGrow(aCStack_58,lStack_48,&CApwnLibraries::m_acmcatalog);
  }
  iVar1 = CApwnLibraries::ReconcileLibs(this,aCStack_58,(CNameAndStateArray *)appuStack_30);
  CNameAndStateArray::~CNameAndStateArray((CNameAndStateArray *)appuStack_30);
  CStringArray::~CStringArray(aCStack_58);
  return iVar1;
}

/* ---- FUNC 00016DE0 ApwnLibInitFromTemplate (32 bytes) ---- */

int ApwnLibInitFromTemplate(HWND__ *param_1,IAUserModelLibrary *param_2)

{
  int iVar1;
  
                    /* 0x16de0  306  ApwnLibInitFromTemplate */
  if (g_pApwnLibs != (CApwnLibraries *)0x0) {
    iVar1 = CApwnLibraries::InitFromTemplate(g_pApwnLibs,param_1,param_2);
    return iVar1;
  }
  return -1;
}

/* ---- FUNC 00016E00 ApwnLibRestore (32 bytes) ---- */

int ApwnLibRestore(void *param_1,HWND__ *param_2)

{
  int iVar1;
  
                    /* 0x16e00  307  ApwnLibRestore */
  if (g_pApwnLibs != (CApwnLibraries *)0x0) {
    iVar1 = CApwnLibraries::Restore(g_pApwnLibs,param_1,param_2);
    return iVar1;
  }
  return -1;
}

/* ---- FUNC 00016E20 ApwnLibRestoreFromText (147 bytes) ---- */

int ApwnLibRestoreFromText(IStream *param_1,HWND__ *param_2)

{
  int iVar1;
  ulonglong uVar2;
  CApwnLibraries local_e8 [224];
  
                    /* 0x16e20  308  ApwnLibRestoreFromText */
  if (g_pApwnLibs != (CApwnLibraries *)0x0) {
    iVar1 = CApwnLibraries::RestoreFromText(g_pApwnLibs,param_1,param_2);
    return iVar1;
  }
  uVar2 = FUN_1800240b0();
  if ((int)uVar2 == 2) {
    CApwnLibraries::CApwnLibraries(local_e8);
    iVar1 = CApwnLibraries::RestoreFromText(local_e8,param_1,param_2);
    CApwnLibraries::~CApwnLibraries(local_e8);
    return iVar1;
  }
  return -1;
}

/* ---- FUNC 00016EC0 ApwnLibSave (25 bytes) ---- */

int ApwnLibSave(char *param_1)

{
  int iVar1;
  char *apcStackX_10 [3];
  
                    /* 0x16ec0  309  ApwnLibSave */
  if (g_pApwnLibs == (CApwnLibraries *)0x0) {
    return -1;
  }
  apcStackX_10[0] = param_1;
  iVar1 = CApwnLibraries::DoSave(g_pApwnLibs,apcStackX_10);
  return iVar1;
}

/* ---- FUNC 00016EE0 ApwnLibSaveToText (30 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 ApwnLibSaveToText(IStream *param_1)

{
  CApwnLibraries *this;
  undefined8 in_R8;
  undefined8 in_R9;
  undefined1 auStack_d8 [32];
  undefined1 auStack_b8 [160];
  ulonglong uStack_18;
  
                    /* 0x16ee0  310  ApwnLibSaveToText */
  this = g_pApwnLibs;
  if ((param_1 != (IStream *)0x0) && (g_pApwnLibs != (CApwnLibraries *)0x0)) {
    uStack_18 = DAT_1800791f8 ^ (ulonglong)auStack_d8;
    FUN_180007de0(auStack_b8,"startlibrary\n",in_R8,in_R9);
    FUN_180016870((longlong *)param_1,(longlong)auStack_b8);
    FUN_180007de0(auStack_b8,"version1\n",in_R8,in_R9);
    FUN_180016870((longlong *)param_1,(longlong)auStack_b8);
    CApwnLibraries::SaveAsTextV1(this,param_1);
    FUN_180007de0(auStack_b8,"endlibrary\n",in_R8,in_R9);
    FUN_180016870((longlong *)param_1,(longlong)auStack_b8);
    return 0;
  }
  return 0xffffffff;
}

/* ---- FUNC 00016F00 ApwnLibrariesCanAdd (156 bytes) ---- */

int ApwnLibrariesCanAdd(void)

{
  int iVar1;
  IAUserModelLibrary *pIVar2;
  int iVar3;
  CApwnLibraries *this;
  int iVar4;
  int local_res8 [2];
  
                    /* 0x16f00  311  ApwnLibrariesCanAdd */
  this = g_pApwnLibs;
  iVar4 = 0;
  iVar1 = CApwnLibraries::CountLibraries(g_pApwnLibs);
  iVar3 = 0;
  if (0 < iVar1) {
    do {
      pIVar2 = CApwnLibraries::GetLibrary(this,iVar3);
      if (pIVar2 != (IAUserModelLibrary *)0x0) {
        local_res8[0] = 1;
        (**(code **)(*(longlong *)pIVar2 + 0x30))(pIVar2,local_res8);
        (**(code **)(*(longlong *)pIVar2 + 0x10))(pIVar2);
        if (local_res8[0] == 0) {
          iVar4 = iVar4 + 1;
        }
        if (1 < iVar4) {
          return 2;
        }
      }
      iVar3 = iVar3 + 1;
      this = g_pApwnLibs;
    } while (iVar3 < iVar1);
  }
  return iVar4;
}

/* ---- FUNC 00016FA0 ApwnLibrariesCanAppend (389 bytes) ---- */

int ApwnLibrariesCanAppend(void)

{
  int iVar1;
  int iVar2;
  IAUserModelLibrary *pIVar3;
  CApwnLibraries *this;
  int iVar4;
  int iVar5;
  int local_res8 [2];
  int local_res10 [2];
  longlong *local_res18;
  longlong *local_res20;
  longlong *local_48;
  longlong *local_40 [2];
  
                    /* 0x16fa0  312  ApwnLibrariesCanAppend */
  this = g_pApwnLibs;
  iVar4 = 0;
  iVar1 = CApwnLibraries::CountLibraries(g_pApwnLibs);
  iVar5 = iVar4;
  if (0 < iVar1) {
    do {
      pIVar3 = CApwnLibraries::GetLibrary(this,iVar5);
      if (pIVar3 != (IAUserModelLibrary *)0x0) {
        local_res8[0] = 1;
        (**(code **)(*(longlong *)pIVar3 + 0x30))(pIVar3,local_res8);
        if (local_res8[0] == 0) {
          local_40[0] = (longlong *)0x0;
          iVar2 = (*(code *)**(undefined8 **)pIVar3)(pIVar3,&DAT_180056240,local_40);
          if (-1 < iVar2) {
            local_res20 = (longlong *)0x0;
            iVar2 = (**(code **)(*local_40[0] + 0x40))(local_40[0],&local_res20);
            if (-1 < iVar2) {
              iVar2 = (**(code **)(*local_res20 + 0x18))(local_res20,1,&local_res18);
              while (iVar2 == 0) {
                local_48 = (longlong *)0x0;
                iVar2 = (**(code **)*local_res18)(local_res18,&DAT_180056280,&local_48);
                if (-1 < iVar2) {
                  local_res10[0] = 0;
                  (**(code **)(*local_48 + 0x20))(local_48,local_res10);
                  (**(code **)(*local_48 + 0x10))();
                  if (local_res10[0] != 0) {
                    (**(code **)(*local_res18 + 0x10))();
                    iVar4 = iVar4 + 1;
                    break;
                  }
                }
                (**(code **)(*local_res18 + 0x10))();
                iVar2 = (**(code **)(*local_res20 + 0x18))(local_res20,1,&local_res18);
              }
              (**(code **)(*local_res20 + 0x10))();
            }
            (**(code **)(*local_40[0] + 0x10))();
          }
        }
        (**(code **)(*(longlong *)pIVar3 + 0x10))(pIVar3);
        if (1 < iVar4) {
          return 2;
        }
      }
      iVar5 = iVar5 + 1;
      this = g_pApwnLibs;
    } while (iVar5 < iVar1);
  }
  return iVar4;
}

/* ---- FUNC 00017130 ApwnLibraryCanAdd (40 bytes) ---- */

bool ApwnLibraryCanAdd(undefined8 *param_1)

{
  bool bVar1;
  int local_res8 [2];
  longlong *local_res10;
  
                    /* 0x17130  313  ApwnLibraryCanAdd */
  bVar1 = false;
  local_res10 = (longlong *)0x0;
  (**(code **)*param_1)(param_1,&DAT_180056270,&local_res10);
  if (local_res10 != (longlong *)0x0) {
    local_res8[0] = 1;
    (**(code **)(*local_res10 + 0x30))(local_res10,local_res8);
    (**(code **)(*local_res10 + 0x10))();
    bVar1 = local_res8[0] == 0;
  }
  return bVar1;
}

/* ---- FUNC 00017158 FUN_180017158 (48 bytes) ---- */

int FUN_180017158(longlong *param_1)

{
  int unaff_EBX;
  int iStack0000000000000030;
  longlong *in_stack_00000038;
  
  iStack0000000000000030 = 1;
  (**(code **)(*param_1 + 0x30))(param_1,&stack0x00000030);
  (**(code **)(*in_stack_00000038 + 0x10))();
  if (iStack0000000000000030 == unaff_EBX) {
    unaff_EBX = 1;
  }
  return unaff_EBX;
}

/* ---- FUNC 00017188 FUN_180017188 (8 bytes) ---- */

undefined4 FUN_180017188(void)

{
  undefined4 unaff_EBX;
  
  return unaff_EBX;
}

/* ---- FUNC 00017190 ApwnLibraryCanAppend (311 bytes) ---- */

undefined8 ApwnLibraryCanAppend(undefined8 *param_1)

{
  int iVar1;
  undefined8 uVar2;
  int local_res8 [2];
  int local_res10 [2];
  longlong *local_res18;
  longlong *local_res20;
  longlong *local_38;
  longlong *local_30;
  longlong *local_28 [3];
  
                    /* 0x17190  314  ApwnLibraryCanAppend */
  uVar2 = 0;
  local_38 = (longlong *)0x0;
  (**(code **)*param_1)(param_1,&DAT_180056270,&local_38);
  if (local_38 != (longlong *)0x0) {
    local_res8[0] = 1;
    (**(code **)(*local_38 + 0x30))(local_38,local_res8);
    if (local_res8[0] == 0) {
      local_28[0] = (longlong *)0x0;
      iVar1 = (**(code **)*local_38)(local_38,&DAT_180056240,local_28);
      if (-1 < iVar1) {
        local_res20 = (longlong *)0x0;
        iVar1 = (**(code **)(*local_28[0] + 0x40))(local_28[0],&local_res20);
        if (-1 < iVar1) {
          iVar1 = (**(code **)(*local_res20 + 0x18))(local_res20,1,&local_res18,0);
          while (iVar1 == 0) {
            local_30 = (longlong *)0x0;
            iVar1 = (**(code **)*local_res18)(local_res18,&DAT_180056280,&local_30);
            if (-1 < iVar1) {
              local_res10[0] = 0;
              (**(code **)(*local_30 + 0x20))(local_30,local_res10);
              (**(code **)(*local_30 + 0x10))();
              if (local_res10[0] != 0) {
                (**(code **)(*local_res18 + 0x10))();
                uVar2 = 1;
                break;
              }
            }
            (**(code **)(*local_res18 + 0x10))();
            iVar1 = (**(code **)(*local_res20 + 0x18))(local_res20,1,&local_res18);
          }
          (**(code **)(*local_res20 + 0x10))();
        }
        (**(code **)(*local_28[0] + 0x10))();
      }
    }
    (**(code **)(*local_38 + 0x10))();
  }
  return uVar2;
}

/* ---- FUNC 000172D0 ApwnLibraryCount (19 bytes) ---- */

undefined4 ApwnLibraryCount(void)

{
                    /* 0x172d0  315  ApwnLibraryCount */
  if (g_pApwnLibs == (CApwnLibraries *)0x0) {
    return 0;
  }
  return *(undefined4 *)(g_pApwnLibs + 0x18);
}

/* ---- FUNC 000172F0 ApwnLibraryGetAt (21 bytes) ---- */

undefined8 ApwnLibraryGetAt(int param_1)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined8 auStackX_8 [4];
  
                    /* 0x172f0  316  ApwnLibraryGetAt */
  if (g_pApwnLibs == (CApwnLibraries *)0x0) {
    return 0;
  }
  if (*(int *)(g_pApwnLibs + 0x18) <= param_1) {
    return 0;
  }
  auStackX_8[0] = 0;
  if ((-1 < param_1) && ((longlong)param_1 < *(longlong *)(g_pApwnLibs + 0x18))) {
    puVar1 = *(undefined8 **)
              (*(longlong *)(*(longlong *)(g_pApwnLibs + 0x10) + (longlong)param_1 * 8) + 8);
    uVar2 = 0;
    if (puVar1 != (undefined8 *)0x0) {
      (**(code **)*puVar1)(puVar1,&DAT_180056270,auStackX_8);
      uVar2 = auStackX_8[0];
    }
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 00017310 ApwnRefreshPaletteCategories (12 bytes) ---- */

void ApwnRefreshPaletteCategories(void)

{
                    /* 0x17310  317  ApwnRefreshPaletteCategories */
  CApwnLibraries::Refresh(g_pApwnLibs);
  return;
}

/* ---- FUNC 00017320 ApwnRemoveModelType (33 bytes) ---- */

bool ApwnRemoveModelType(char *param_1,char *param_2,char *param_3)

{
  bool bVar1;
  
                    /* 0x17320  318  ApwnRemoveModelType */
  bVar1 = CApwnLibraries::RemoveModelType(g_pApwnLibs,param_1,param_2,param_3);
  return bVar1;
}

/* ---- FUNC 00017350 CreateApwnLibrariesTest (5 bytes) ---- */

void CreateApwnLibrariesTest(void)

{
  ulonglong uVar1;
  
  uVar1 = FUN_1800240b0();
  if ((int)uVar1 == 1) {
    if (g_pApwnLibs == (CApwnLibraries *)0x0) {
      g_pApwnLibs = CApwnLibraries::CreateObject();
    }
                    /* WARNING: Could not recover jumptable at 0x00018000f4e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(longlong *)g_pApwnLibs + 8))(g_pApwnLibs);
    return;
  }
  return;
}

/* ---- FUNC 00017360 CreateGlobalApwnLib (71 bytes) ---- */

CApwnLibraries * CreateGlobalApwnLib(void)

{
  CApwnLibraries *this;
  
                    /* 0x17360  342  CreateGlobalApwnLib */
  if (g_pApwnLibs == (CApwnLibraries *)0x0) {
    this = operator_new(0xd8);
    if (this == (CApwnLibraries *)0x0) {
      g_pApwnLibs = (CApwnLibraries *)0x0;
    }
    else {
      g_pApwnLibs = (CApwnLibraries *)CApwnLibraries::CApwnLibraries(this);
    }
    (**(code **)(*(longlong *)g_pApwnLibs + 8))();
  }
  return g_pApwnLibs;
}

/* ---- FUNC 000173B0 FreeGlobalApwnLib (38 bytes) ---- */

void FreeGlobalApwnLib(void)

{
                    /* 0x173b0  351  FreeGlobalApwnLib */
  if (g_pApwnLibs != (CApwnLibraries *)0x0) {
    (**(code **)(*(longlong *)g_pApwnLibs + 0x10))();
  }
  g_pApwnLibs = (CApwnLibraries *)0x0;
  return;
}

/* ---- FUNC 000173E0 InitGlobalApwnLib (27 bytes) ---- */

void InitGlobalApwnLib(IUnknown *param_1,IUnknown *param_2)

{
                    /* 0x173e0  367  InitGlobalApwnLib */
  if (g_pApwnLibs != (CApwnLibraries *)0x0) {
    CApwnLibraries::Init(g_pApwnLibs,param_1,param_2);
    return;
  }
  return;
}

/* ---- FUNC 00017400 MMStructGetModelTypeList (15 bytes) ---- */

void MMStructGetModelTypeList(IAEditCategories **param_1)

{
                    /* 0x17400  411  MMStructGetModelTypeList */
  CApwnLibraries::GetModelTypeList(g_pApwnLibs,param_1);
  return;
}

/* ---- FUNC 00017410 RemoveUserLibWithInvalidPath (43 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void RemoveUserLibWithInvalidPath(void)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  DWORD DVar3;
  int extraout_EAX;
  int iVar4;
  __uint64 _Var5;
  void *pvVar6;
  undefined4 *puVar7;
  void *pvVar8;
  longlong lVar9;
  DWORD DVar10;
  longlong lVar11;
  longlong lVar12;
  ulonglong uVar13;
  undefined4 uVar14;
  undefined4 *puVar15;
  undefined1 auStackY_178 [32];
  undefined4 local_148;
  undefined4 local_144 [3];
  char local_138 [272];
  ulonglong local_28;
  
                    /* 0x17410  446  RemoveUserLibWithInvalidPath */
  local_28 = DAT_1800791f8 ^ (ulonglong)auStackY_178;
  DVar3 = APModLibCount();
  uVar13 = (ulonglong)(int)DVar3;
  if (DVar3 != 0) {
    auVar1._8_8_ = 0;
    auVar1._0_8_ = uVar13;
    _Var5 = SUB168(ZEXT816(8) * auVar1,0);
    if (SUB168(ZEXT816(8) * auVar1,8) != 0) {
      _Var5 = 0xffffffffffffffff;
    }
    pvVar6 = operator_new__(_Var5);
    auVar2._8_8_ = 0;
    auVar2._0_8_ = uVar13;
    _Var5 = SUB168(ZEXT816(4) * auVar2,0);
    if (SUB168(ZEXT816(4) * auVar2,8) != 0) {
      _Var5 = 0xffffffffffffffff;
    }
    puVar7 = operator_new__(_Var5);
    lVar9 = 0;
    lVar11 = lVar9;
    puVar15 = puVar7;
    if (0 < (int)DVar3) {
      do {
        pvVar8 = operator_new__(0x40);
        *(void **)((longlong)pvVar6 + lVar11 * 8) = pvVar8;
        lVar11 = lVar11 + 1;
        *puVar15 = 0;
        puVar15 = puVar15 + 1;
      } while (lVar11 < (longlong)uVar13);
    }
    APModLibListLibs((longlong)pvVar6,DVar3,0x40);
    lVar11 = lVar9;
    puVar15 = puVar7;
    if (0 < (int)DVar3) {
      do {
        local_144[0] = 0;
        local_148 = 0;
        DVar10 = APModLibGetValues(*(longlong *)((longlong)pvVar6 + lVar11 * 8),local_138,0x104,
                                   local_144,&local_148);
        if ((0 < extraout_EAX) && (iVar4 = _access(local_138,0), iVar4 == -1)) {
          *puVar15 = 1;
        }
        lVar11 = CONCAT44((int)((ulonglong)lVar11 >> 0x20),DVar10) + 1;
        lVar12 = lVar9;
        puVar15 = puVar15 + 1;
      } while (lVar11 < (longlong)uVar13);
      do {
        if (puVar7[lVar12] != 0) {
          uVar14 = APModLibUnregisterLib(*(longlong *)((longlong)pvVar6 + lVar12 * 8));
          pvVar6 = (void *)CONCAT44((int)((ulonglong)pvVar6 >> 0x20),uVar14);
        }
        lVar12 = lVar12 + 1;
      } while (lVar12 < (longlong)uVar13);
    }
    if (pvVar6 != (void *)0x0) {
      if (0 < (int)DVar3) {
        do {
          operator_delete__(*(void **)((longlong)pvVar6 + lVar9 * 8));
          lVar9 = lVar9 + 1;
        } while (lVar9 < (longlong)uVar13);
      }
      operator_delete__(pvVar6);
    }
    if (puVar7 != (undefined4 *)0x0) {
      operator_delete__(puVar7);
    }
  }
  return;
}

/* ---- FUNC 0001743B FUN_18001743b (47 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18001743b(void)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  int extraout_EAX;
  int iVar3;
  __uint64 _Var4;
  void *pvVar5;
  undefined4 *puVar6;
  void *pvVar7;
  longlong lVar8;
  DWORD DVar9;
  longlong lVar10;
  longlong lVar11;
  DWORD DVar12;
  ulonglong unaff_R12;
  undefined4 uVar13;
  undefined4 *puVar14;
  undefined4 uStack0000000000000030;
  undefined4 uStack0000000000000034;
  
  auVar1._8_8_ = 0;
  auVar1._0_8_ = unaff_R12;
  _Var4 = SUB168(ZEXT816(8) * auVar1,0);
  if (SUB168(ZEXT816(8) * auVar1,8) != 0) {
    _Var4 = 0xffffffffffffffff;
  }
  pvVar5 = operator_new__(_Var4);
  auVar2._8_8_ = 0;
  auVar2._0_8_ = unaff_R12;
  _Var4 = SUB168(ZEXT816(4) * auVar2,0);
  if (SUB168(ZEXT816(4) * auVar2,8) != 0) {
    _Var4 = 0xffffffffffffffff;
  }
  puVar6 = operator_new__(_Var4);
  lVar8 = 0;
  DVar12 = (DWORD)unaff_R12;
  lVar10 = lVar8;
  puVar14 = puVar6;
  if (0 < (int)DVar12) {
    do {
      pvVar7 = operator_new__(0x40);
      *(void **)((longlong)pvVar5 + lVar10 * 8) = pvVar7;
      lVar10 = lVar10 + 1;
      *puVar14 = 0;
      puVar14 = puVar14 + 1;
    } while (lVar10 < (longlong)unaff_R12);
  }
  APModLibListLibs((longlong)pvVar5,DVar12,0x40);
  lVar10 = lVar8;
  puVar14 = puVar6;
  if (0 < (int)DVar12) {
    do {
      uStack0000000000000034 = 0;
      uStack0000000000000030 = 0;
      DVar9 = APModLibGetValues(*(longlong *)((longlong)pvVar5 + lVar10 * 8),&stack0x00000040,0x104,
                                (undefined4 *)((longlong)&stack0x00000030 + 4),&stack0x00000030);
      if ((0 < extraout_EAX) && (iVar3 = _access(&stack0x00000040,0), iVar3 == -1)) {
        *puVar14 = 1;
      }
      lVar10 = CONCAT44((int)((ulonglong)lVar10 >> 0x20),DVar9) + 1;
      lVar11 = lVar8;
      puVar14 = puVar14 + 1;
    } while (lVar10 < (longlong)unaff_R12);
    do {
      if (puVar6[lVar11] != 0) {
        uVar13 = APModLibUnregisterLib(*(longlong *)((longlong)pvVar5 + lVar11 * 8));
        pvVar5 = (void *)CONCAT44((int)((ulonglong)pvVar5 >> 0x20),uVar13);
      }
      lVar11 = lVar11 + 1;
    } while (lVar11 < (longlong)unaff_R12);
  }
  if (pvVar5 != (void *)0x0) {
    if (0 < (int)DVar12) {
      do {
        operator_delete__(*(void **)((longlong)pvVar5 + lVar8 * 8));
        lVar8 = lVar8 + 1;
      } while (lVar8 < (longlong)unaff_R12);
    }
    operator_delete__(pvVar5);
  }
  if (puVar6 != (undefined4 *)0x0) {
    operator_delete__(puVar6);
  }
  return;
}

/* ---- FUNC 0001746A FUN_18001746a (265 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18001746a(void)

{
  undefined1 auVar1 [16];
  int extraout_EAX;
  int iVar2;
  __uint64 in_RAX;
  void *pvVar3;
  __uint64 _Var4;
  undefined4 *puVar5;
  void *pvVar6;
  __uint64 unaff_RBX;
  longlong lVar7;
  DWORD DVar8;
  longlong lVar9;
  longlong lVar10;
  DWORD DVar11;
  ulonglong unaff_R12;
  undefined4 uVar12;
  undefined4 *puVar13;
  bool in_OF;
  undefined4 uStack0000000000000030;
  undefined4 uStack0000000000000034;
  
  if (in_OF) {
    in_RAX = unaff_RBX;
  }
  pvVar3 = operator_new__(in_RAX);
  auVar1._8_8_ = 0;
  auVar1._0_8_ = unaff_R12;
  _Var4 = SUB168(ZEXT816(4) * auVar1,0);
  if (SUB168(ZEXT816(4) * auVar1,8) != 0) {
    _Var4 = unaff_RBX;
  }
  puVar5 = operator_new__(_Var4);
  lVar7 = 0;
  DVar11 = (DWORD)unaff_R12;
  lVar9 = lVar7;
  puVar13 = puVar5;
  if (0 < (int)DVar11) {
    do {
      pvVar6 = operator_new__(0x40);
      *(void **)((longlong)pvVar3 + lVar9 * 8) = pvVar6;
      lVar9 = lVar9 + 1;
      *puVar13 = 0;
      puVar13 = puVar13 + 1;
    } while (lVar9 < (longlong)unaff_R12);
  }
  APModLibListLibs((longlong)pvVar3,DVar11,0x40);
  lVar9 = lVar7;
  puVar13 = puVar5;
  if (0 < (int)DVar11) {
    do {
      uStack0000000000000034 = 0;
      uStack0000000000000030 = 0;
      DVar8 = APModLibGetValues(*(longlong *)((longlong)pvVar3 + lVar9 * 8),&stack0x00000040,0x104,
                                (undefined4 *)((longlong)&stack0x00000030 + 4),&stack0x00000030);
      if ((0 < extraout_EAX) && (iVar2 = _access(&stack0x00000040,0), iVar2 == -1)) {
        *puVar13 = 1;
      }
      lVar9 = CONCAT44((int)((ulonglong)lVar9 >> 0x20),DVar8) + 1;
      lVar10 = lVar7;
      puVar13 = puVar13 + 1;
    } while (lVar9 < (longlong)unaff_R12);
    do {
      if (puVar5[lVar10] != 0) {
        uVar12 = APModLibUnregisterLib(*(longlong *)((longlong)pvVar3 + lVar10 * 8));
        pvVar3 = (void *)CONCAT44((int)((ulonglong)pvVar3 >> 0x20),uVar12);
      }
      lVar10 = lVar10 + 1;
    } while (lVar10 < (longlong)unaff_R12);
  }
  if (pvVar3 != (void *)0x0) {
    if (0 < (int)DVar11) {
      do {
        operator_delete__(*(void **)((longlong)pvVar3 + lVar7 * 8));
        lVar7 = lVar7 + 1;
      } while (lVar7 < (longlong)unaff_R12);
    }
    operator_delete__(pvVar3);
  }
  if (puVar5 != (undefined4 *)0x0) {
    operator_delete__(puVar5);
  }
  return;
}

/* ---- FUNC 00017573 FUN_180017573 (67 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180017573(void)

{
  longlong unaff_RBX;
  void *unaff_RBP;
  longlong unaff_R12;
  void *unaff_R14;
  
  if (0 < (int)unaff_R12) {
    do {
      operator_delete__(*(void **)((longlong)unaff_R14 + unaff_RBX * 8));
      unaff_RBX = unaff_RBX + 1;
    } while (unaff_RBX < unaff_R12);
  }
  operator_delete__(unaff_R14);
  if (unaff_RBP != (void *)0x0) {
    operator_delete__(unaff_RBP);
  }
  return;
}

/* ---- FUNC 000175B6 FUN_1800175b6 (16 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1800175b6(void)

{
  void *unaff_RBP;
  
  operator_delete__(unaff_RBP);
  return;
}

/* ---- FUNC 000175C6 FUN_1800175c6 (26 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1800175c6(void)

{
  return;
}

/* ---- FUNC 000175E0 FUN_1800175e0 (76 bytes) ---- */

ulonglong FUN_1800175e0(void *param_1,undefined8 *param_2)

{
  int iVar1;
  size_t sVar2;
  undefined4 extraout_var;
  undefined8 *_Buf1;
  
  sVar2 = 0xffffffffffffffff;
  do {
    sVar2 = sVar2 + 1;
  } while (*(char *)((longlong)param_1 + sVar2) != '\0');
  _Buf1 = param_2;
  if (0xf < (ulonglong)param_2[3]) {
    _Buf1 = (undefined8 *)*param_2;
  }
  if (param_2[2] == sVar2) {
    iVar1 = memcmp(_Buf1,param_1,param_2[2]);
    sVar2 = CONCAT44(extraout_var,iVar1);
    if (iVar1 == 0) {
      return CONCAT71((int7)(sVar2 >> 8),1);
    }
  }
  return sVar2 & 0xffffffffffffff00;
}

/* ---- FUNC 00017630 FUN_180017630 (13 bytes) ---- */

void FUN_180017630(void *param_1,void *param_2)

{
  if (param_1 != param_2) {
                    /* WARNING: Could not recover jumptable at 0x000180017635. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    free(param_1);
    return;
  }
  return;
}

/* ---- FUNC 00017640 FUN_180017640 (190 bytes) ---- */

longlong *
FUN_180017640(undefined8 *param_1,undefined8 *param_2,longlong param_3,undefined8 param_4)

{
  undefined8 uVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong *plVar4;
  
  plVar4 = (longlong *)*param_1;
  if (*(char *)((longlong)param_2 + 0x19) == '\0') {
    plVar2 = operator_new(0x38);
    uVar1 = *(undefined8 *)((longlong)param_2 + 0x24);
    *(undefined8 *)((longlong)plVar2 + 0x1c) = *(undefined8 *)((longlong)param_2 + 0x1c);
    *(undefined8 *)((longlong)plVar2 + 0x24) = uVar1;
    *(undefined8 *)((longlong)plVar2 + 0x2c) = *(undefined8 *)((longlong)param_2 + 0x2c);
    *(undefined4 *)((longlong)plVar2 + 0x34) = *(undefined4 *)((longlong)param_2 + 0x34);
    *plVar2 = (longlong)plVar4;
    plVar2[2] = (longlong)plVar4;
    *(undefined2 *)(plVar2 + 3) = 0;
    plVar2[1] = param_3;
    *(undefined1 *)(plVar2 + 3) = *(undefined1 *)(param_2 + 3);
    if (*(char *)((longlong)plVar4 + 0x19) != '\0') {
      plVar4 = plVar2;
    }
    plVar3 = FUN_180017640(param_1,(undefined8 *)*param_2,(longlong)plVar2,param_4);
    *plVar2 = (longlong)plVar3;
    plVar3 = FUN_180017640(param_1,(undefined8 *)param_2[2],(longlong)plVar2,param_4);
    plVar2[2] = (longlong)plVar3;
  }
  return plVar4;
}

/* ---- FUNC 00017700 FUN_180017700 (190 bytes) ---- */

longlong *
FUN_180017700(undefined8 *param_1,undefined8 *param_2,longlong param_3,undefined8 param_4)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  
  plVar4 = (longlong *)*param_1;
  if (*(char *)((longlong)param_2 + 0x19) == '\0') {
    lVar3 = param_3;
    plVar1 = operator_new(0x38);
    *(undefined4 *)(plVar1 + 4) = *(undefined4 *)(param_2 + 4);
    FUN_1800185f0(plVar1 + 5,param_2 + 5,lVar3,param_4);
    *plVar1 = (longlong)plVar4;
    plVar1[2] = (longlong)plVar4;
    *(undefined2 *)(plVar1 + 3) = 0;
    plVar1[1] = param_3;
    *(undefined1 *)(plVar1 + 3) = *(undefined1 *)(param_2 + 3);
    if (*(char *)((longlong)plVar4 + 0x19) != '\0') {
      plVar4 = plVar1;
    }
    plVar2 = FUN_180017700(param_1,(undefined8 *)*param_2,(longlong)plVar1,param_4);
    *plVar1 = (longlong)plVar2;
    plVar2 = FUN_180017700(param_1,(undefined8 *)param_2[2],(longlong)plVar1,param_4);
    plVar1[2] = (longlong)plVar2;
  }
  return plVar4;
}

/* ---- FUNC 000177C0 FUN_1800177c0 (218 bytes) ---- */

longlong *
FUN_1800177c0(undefined8 *param_1,undefined8 *param_2,longlong param_3,undefined8 param_4)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong *plVar4;
  
  plVar4 = (longlong *)*param_1;
  if (*(char *)((longlong)param_2 + 0x19) == '\0') {
    plVar2 = operator_new(0x58);
    FUN_180018500(plVar2 + 4,param_2 + 4);
    lVar1 = param_2[9];
    plVar2[8] = param_2[8];
    plVar2[9] = lVar1;
    plVar2[10] = param_2[10];
    *plVar2 = (longlong)plVar4;
    plVar2[2] = (longlong)plVar4;
    *(undefined2 *)(plVar2 + 3) = 0;
    plVar2[1] = param_3;
    *(undefined1 *)(plVar2 + 3) = *(undefined1 *)(param_2 + 3);
    if (*(char *)((longlong)plVar4 + 0x19) != '\0') {
      plVar4 = plVar2;
    }
    plVar3 = FUN_1800177c0(param_1,(undefined8 *)*param_2,(longlong)plVar2,param_4);
    *plVar2 = (longlong)plVar3;
    plVar3 = FUN_1800177c0(param_1,(undefined8 *)param_2[2],(longlong)plVar2,param_4);
    plVar2[2] = (longlong)plVar3;
  }
  return plVar4;
}

/* ---- FUNC 000178A0 FUN_1800178a0 (221 bytes) ---- */

longlong *
FUN_1800178a0(undefined8 *param_1,undefined8 *param_2,longlong param_3,undefined8 param_4)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  
  plVar4 = (longlong *)*param_1;
  if (*(char *)((longlong)param_2 + 0x19) == '\0') {
    lVar3 = param_3;
    plVar1 = operator_new(0x50);
    FUN_180018500(plVar1 + 4,param_2 + 4);
    FUN_1800186c0(plVar1 + 8,param_2 + 8,lVar3,param_4);
    *plVar1 = (longlong)plVar4;
    plVar1[2] = (longlong)plVar4;
    *(undefined2 *)(plVar1 + 3) = 0;
    plVar1[1] = param_3;
    *(undefined1 *)(plVar1 + 3) = *(undefined1 *)(param_2 + 3);
    if (*(char *)((longlong)plVar4 + 0x19) != '\0') {
      plVar4 = plVar1;
    }
    plVar2 = FUN_1800178a0(param_1,(undefined8 *)*param_2,(longlong)plVar1,param_4);
    *plVar1 = (longlong)plVar2;
    plVar2 = FUN_1800178a0(param_1,(undefined8 *)param_2[2],(longlong)plVar1,param_4);
    plVar1[2] = (longlong)plVar2;
  }
  return plVar4;
}

/* ---- FUNC 00017980 FUN_180017980 (466 bytes) ---- */

undefined8 * FUN_180017980(longlong *param_1,longlong *param_2,undefined8 *param_3)

{
  longlong lVar1;
  void *pvVar2;
  longlong *plVar3;
  ulonglong uVar4;
  longlong *plVar5;
  void *pvVar6;
  longlong *plVar7;
  ulonglong uVar8;
  longlong *plVar9;
  __uint64 _Var10;
  longlong lVar11;
  ulonglong uVar12;
  undefined8 *puVar13;
  
  lVar1 = *param_1;
  lVar11 = param_1[1] - lVar1 >> 5;
  if (lVar11 == 0x7ffffffffffffff) {
                    /* WARNING: Subroutine does not return */
    FUN_18000ad00();
  }
  uVar12 = lVar11 + 1;
  uVar4 = param_1[2] - lVar1 >> 5;
  if (0x7ffffffffffffff - (uVar4 >> 1) < uVar4) {
    _Var10 = 0xffffffffffffffe0;
    plVar3 = (longlong *)FUN_180007f10(0xffffffffffffffe0);
  }
  else {
    uVar4 = (uVar4 >> 1) + uVar4;
    uVar8 = uVar12;
    if (uVar12 <= uVar4) {
      uVar8 = uVar4;
    }
    if (0x7ffffffffffffff < uVar8) {
                    /* WARNING: Subroutine does not return */
      FUN_18000ac70();
    }
    _Var10 = uVar8 << 5;
    if (_Var10 < 0x1000) {
      if (_Var10 == 0) {
        plVar3 = (longlong *)0x0;
      }
      else {
        plVar3 = operator_new(_Var10);
      }
    }
    else {
      plVar3 = (longlong *)FUN_180007f10(_Var10);
    }
  }
  puVar13 = (undefined8 *)(((longlong)param_2 - lVar1 & 0xffffffffffffffe0U) + (longlong)plVar3);
  FUN_180018500(puVar13,param_3);
  plVar7 = (longlong *)param_1[1];
  plVar5 = (longlong *)*param_1;
  plVar9 = plVar3;
  if (param_2 != plVar7) {
    FUN_180008dd0(plVar5,param_2,plVar3);
    plVar7 = (longlong *)param_1[1];
    plVar5 = param_2;
    plVar9 = puVar13 + 4;
  }
  FUN_180008dd0(plVar5,plVar7,plVar9);
  if ((longlong *)*param_1 != (longlong *)0x0) {
    FUN_1800081e0((longlong *)*param_1,(longlong *)param_1[1]);
    pvVar2 = (void *)*param_1;
    pvVar6 = pvVar2;
    if ((0xfff < (param_1[2] - (longlong)pvVar2 & 0xffffffffffffffe0U)) &&
       (pvVar6 = *(void **)((longlong)pvVar2 + -8),
       0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)pvVar6)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar6);
  }
  *param_1 = (longlong)plVar3;
  param_1[1] = (longlong)(plVar3 + uVar12 * 4);
  param_1[2] = (longlong)plVar3 + _Var10;
  return puVar13;
}

/* ---- FUNC 00017B60 FUN_180017b60 (113 bytes) ---- */

void FUN_180017b60(longlong *param_1,undefined8 param_2)

{
  char cVar1;
  longlong *plVar2;
  longlong *plVar3;
  
  cVar1 = *(char *)((longlong)*(longlong **)(*param_1 + 8) + 0x19);
  plVar3 = *(longlong **)(*param_1 + 8);
  while (cVar1 == '\0') {
    FUN_180017be0(param_1,param_2,(longlong *)plVar3[2]);
    plVar2 = (longlong *)*plVar3;
    operator_delete(plVar3);
    plVar3 = plVar2;
    cVar1 = *(char *)((longlong)plVar2 + 0x19);
  }
  operator_delete((void *)*param_1);
  return;
}

/* ---- FUNC 00017BE0 FUN_180017be0 (85 bytes) ---- */

void FUN_180017be0(undefined8 param_1,undefined8 param_2,longlong *param_3)

{
  char cVar1;
  longlong *plVar2;
  
  cVar1 = *(char *)((longlong)param_3 + 0x19);
  while (cVar1 == '\0') {
    FUN_180017be0(param_1,param_2,(longlong *)param_3[2]);
    plVar2 = (longlong *)*param_3;
    operator_delete(param_3);
    param_3 = plVar2;
    cVar1 = *(char *)((longlong)plVar2 + 0x19);
  }
  return;
}

/* ---- FUNC 00017C40 FUN_180017c40 (31 bytes) ---- */

void FUN_180017c40(undefined8 param_1,undefined8 param_2,longlong *param_3)

{
  char cVar1;
  longlong *plVar2;
  
  cVar1 = *(char *)((longlong)param_3 + 0x19);
  while (cVar1 == '\0') {
    FUN_180017c40(param_1,param_2,(longlong *)param_3[2]);
    plVar2 = (longlong *)*param_3;
    FUN_180017b60(param_3 + 5,param_3 + 5);
    operator_delete(param_3);
    param_3 = plVar2;
    cVar1 = *(char *)((longlong)plVar2 + 0x19);
  }
  return;
}

/* ---- FUNC 00017C5F FUN_180017c5f (74 bytes) ---- */

void FUN_180017c5f(void)

{
  longlong *plVar1;
  longlong *unaff_RBX;
  undefined8 unaff_RBP;
  undefined8 unaff_RSI;
  
  do {
    FUN_180017c40(unaff_RBP,unaff_RSI,(longlong *)unaff_RBX[2]);
    plVar1 = (longlong *)*unaff_RBX;
    FUN_180017b60(unaff_RBX + 5,unaff_RBX + 5);
    operator_delete(unaff_RBX);
    unaff_RBX = plVar1;
  } while (*(char *)((longlong)plVar1 + 0x19) == '\0');
  return;
}

/* ---- FUNC 00017CA9 FUN_180017ca9 (16 bytes) ---- */

void FUN_180017ca9(void)

{
  return;
}

/* ---- FUNC 00017CC0 FUN_180017cc0 (35 bytes) ---- */

void FUN_180017cc0(undefined8 param_1,undefined8 param_2,longlong *param_3)

{
  char cVar1;
  longlong *plVar2;
  void *pvVar3;
  void *pvVar4;
  
  cVar1 = *(char *)((longlong)param_3 + 0x19);
  do {
    if (cVar1 != '\0') {
      return;
    }
    FUN_180017cc0(param_1,param_2,(longlong *)param_3[2]);
    plVar2 = (longlong *)*param_3;
    if (0xf < (ulonglong)param_3[7]) {
      pvVar3 = (void *)param_3[4];
      pvVar4 = pvVar3;
      if ((0xfff < param_3[7] + 1U) &&
         (pvVar4 = *(void **)((longlong)pvVar3 + -8),
         0x1f < (ulonglong)((longlong)pvVar3 + (-8 - (longlong)pvVar4)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      operator_delete(pvVar4);
    }
    param_3[6] = 0;
    param_3[7] = 0xf;
    *(undefined1 *)(param_3 + 4) = 0;
    operator_delete(param_3);
    cVar1 = *(char *)((longlong)plVar2 + 0x19);
    param_3 = plVar2;
  } while( true );
}

/* ---- FUNC 00017CE3 FUN_180017ce3 (134 bytes) ---- */

void FUN_180017ce3(void)

{
  longlong *plVar1;
  void *pvVar2;
  void *pvVar3;
  undefined8 unaff_RBP;
  undefined8 unaff_RSI;
  longlong *unaff_RDI;
  
  do {
    FUN_180017cc0(unaff_RBP,unaff_RSI,(longlong *)unaff_RDI[2]);
    plVar1 = (longlong *)*unaff_RDI;
    if (0xf < (ulonglong)unaff_RDI[7]) {
      pvVar2 = (void *)unaff_RDI[4];
      pvVar3 = pvVar2;
      if ((0xfff < unaff_RDI[7] + 1U) &&
         (pvVar3 = *(void **)((longlong)pvVar2 + -8),
         0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)pvVar3)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      operator_delete(pvVar3);
    }
    unaff_RDI[6] = 0;
    unaff_RDI[7] = 0xf;
    *(undefined1 *)(unaff_RDI + 4) = 0;
    operator_delete(unaff_RDI);
    unaff_RDI = plVar1;
    if (*(char *)((longlong)plVar1 + 0x19) != '\0') {
      return;
    }
  } while( true );
}

/* ---- FUNC 00017D69 FUN_180017d69 (16 bytes) ---- */

void FUN_180017d69(void)

{
  return;
}

/* ---- FUNC 00017D79 _invalid_parameter_noinfo_noreturn (6 bytes) ---- */

void __cdecl _invalid_parameter_noinfo_noreturn(void)

{
                    /* WARNING: Subroutine does not return */
  _invalid_parameter_noinfo_noreturn();
}

/* ---- FUNC 00017D80 FUN_180017d80 (31 bytes) ---- */

void FUN_180017d80(undefined8 param_1,undefined8 param_2,longlong *param_3)

{
  char cVar1;
  longlong *plVar2;
  
  cVar1 = *(char *)((longlong)param_3 + 0x19);
  while (cVar1 == '\0') {
    FUN_180017d80(param_1,param_2,(longlong *)param_3[2]);
    plVar2 = (longlong *)*param_3;
    FUN_180018090(param_2,param_3 + 4);
    operator_delete(param_3);
    param_3 = plVar2;
    cVar1 = *(char *)((longlong)plVar2 + 0x19);
  }
  return;
}

/* ---- FUNC 00017D9F FUN_180017d9f (74 bytes) ---- */

void FUN_180017d9f(void)

{
  longlong *plVar1;
  longlong *unaff_RBX;
  undefined8 unaff_RBP;
  undefined8 unaff_RSI;
  
  do {
    FUN_180017d80(unaff_RBP,unaff_RSI,(longlong *)unaff_RBX[2]);
    plVar1 = (longlong *)*unaff_RBX;
    FUN_180018090(unaff_RSI,unaff_RBX + 4);
    operator_delete(unaff_RBX);
    unaff_RBX = plVar1;
  } while (*(char *)((longlong)plVar1 + 0x19) == '\0');
  return;
}

/* ---- FUNC 00017DE9 FUN_180017de9 (16 bytes) ---- */

void FUN_180017de9(void)

{
  return;
}

/* ---- FUNC 00017E00 FUN_180017e00 (31 bytes) ---- */

void FUN_180017e00(undefined8 param_1,undefined8 param_2,longlong *param_3)

{
  char cVar1;
  longlong *plVar2;
  
  cVar1 = *(char *)((longlong)param_3 + 0x19);
  while (cVar1 == '\0') {
    FUN_180017e00(param_1,param_2,(longlong *)param_3[2]);
    plVar2 = (longlong *)*param_3;
    FUN_180018120(param_2,param_3 + 4);
    operator_delete(param_3);
    param_3 = plVar2;
    cVar1 = *(char *)((longlong)plVar2 + 0x19);
  }
  return;
}

/* ---- FUNC 00017E1F FUN_180017e1f (74 bytes) ---- */

void FUN_180017e1f(void)

{
  longlong *plVar1;
  longlong *unaff_RBX;
  undefined8 unaff_RBP;
  undefined8 unaff_RSI;
  
  do {
    FUN_180017e00(unaff_RBP,unaff_RSI,(longlong *)unaff_RBX[2]);
    plVar1 = (longlong *)*unaff_RBX;
    FUN_180018120(unaff_RSI,unaff_RBX + 4);
    operator_delete(unaff_RBX);
    unaff_RBX = plVar1;
  } while (*(char *)((longlong)plVar1 + 0x19) == '\0');
  return;
}

/* ---- FUNC 00017E69 FUN_180017e69 (16 bytes) ---- */

void FUN_180017e69(void)

{
  return;
}

/* ---- FUNC 00017E80 FUN_180017e80 (31 bytes) ---- */

void FUN_180017e80(undefined8 param_1,undefined8 param_2,longlong *param_3)

{
  char cVar1;
  longlong *plVar2;
  
  cVar1 = *(char *)((longlong)param_3 + 0x19);
  while (cVar1 == '\0') {
    FUN_180017e80(param_1,param_2,(longlong *)param_3[2]);
    plVar2 = (longlong *)*param_3;
    FUN_1800181b0(param_2,param_3 + 4);
    operator_delete(param_3);
    param_3 = plVar2;
    cVar1 = *(char *)((longlong)plVar2 + 0x19);
  }
  return;
}

/* ---- FUNC 00017E9F FUN_180017e9f (74 bytes) ---- */

void FUN_180017e9f(void)

{
  longlong *plVar1;
  longlong *unaff_RBX;
  undefined8 unaff_RBP;
  undefined8 unaff_RSI;
  
  do {
    FUN_180017e80(unaff_RBP,unaff_RSI,(longlong *)unaff_RBX[2]);
    plVar1 = (longlong *)*unaff_RBX;
    FUN_1800181b0(unaff_RSI,unaff_RBX + 4);
    operator_delete(unaff_RBX);
    unaff_RBX = plVar1;
  } while (*(char *)((longlong)plVar1 + 0x19) == '\0');
  return;
}

/* ---- FUNC 00017EE9 FUN_180017ee9 (16 bytes) ---- */

void FUN_180017ee9(void)

{
  return;
}

/* ---- FUNC 00017F00 FUN_180017f00 (46 bytes) ---- */

undefined8 *
FUN_180017f00(undefined8 *param_1,ulonglong param_2,undefined8 param_3,void *param_4,size_t param_5)

{
  ulonglong uVar1;
  size_t _Size;
  ulonglong uVar2;
  void *_Src;
  void *_Dst;
  ulonglong uVar3;
  ulonglong uVar4;
  void *pvVar5;
  
  _Size = param_1[2];
  uVar4 = 0x7fffffffffffffff;
  if (0x7fffffffffffffff - _Size < param_2) {
                    /* WARNING: Subroutine does not return */
    FUN_18000ace0();
  }
  uVar3 = _Size + param_2 | 0xf;
  uVar2 = param_1[3];
  if (uVar3 < 0x8000000000000000) {
    if (0x7fffffffffffffff - (uVar2 >> 1) < uVar2) {
      _Dst = (void *)FUN_180007f10(0x8000000000000000);
    }
    else {
      uVar1 = (uVar2 >> 1) + uVar2;
      uVar4 = uVar3;
      if (uVar3 < uVar1) {
        uVar4 = uVar1;
      }
      uVar3 = uVar4 + 1;
      if (uVar3 < 0x1000) {
        if (uVar3 == 0) {
          _Dst = (void *)0x0;
        }
        else {
          _Dst = operator_new(uVar3);
        }
      }
      else {
        _Dst = (void *)FUN_180007f10(uVar3);
      }
    }
  }
  else {
    _Dst = (void *)FUN_180007f10(0x8000000000000000);
  }
  param_1[2] = _Size + param_2;
  pvVar5 = (void *)((longlong)_Dst + _Size);
  param_1[3] = uVar4;
  if (uVar2 < 0x10) {
    memcpy(_Dst,param_1,_Size);
    memcpy(pvVar5,param_4,param_5);
    *(undefined1 *)((longlong)pvVar5 + param_5) = 0;
  }
  else {
    _Src = (void *)*param_1;
    memcpy(_Dst,_Src,_Size);
    memcpy(pvVar5,param_4,param_5);
    *(undefined1 *)((longlong)pvVar5 + param_5) = 0;
    pvVar5 = _Src;
    if ((0xfff < uVar2 + 1) &&
       (pvVar5 = *(void **)((longlong)_Src + -8),
       0x1f < (ulonglong)((longlong)_Src + (-8 - (longlong)pvVar5)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar5);
  }
  *param_1 = _Dst;
  return param_1;
}

/* ---- FUNC 00017F2E FUN_180017f2e (328 bytes) ---- */

void FUN_180017f2e(longlong param_1,longlong param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  void *_Src;
  void *_Dst;
  ulonglong uVar3;
  ulonglong unaff_RBX;
  void *pvVar4;
  undefined8 *unaff_RDI;
  void *unaff_R12;
  size_t unaff_R14;
  size_t in_stack_00000070;
  
  uVar3 = unaff_R14 + param_2 | 0xf;
  uVar2 = *(ulonglong *)(param_1 + 0x18);
  if (unaff_RBX < uVar3) {
    _Dst = (void *)FUN_180007f10(0x8000000000000000);
  }
  else if (unaff_RBX - (uVar2 >> 1) < uVar2) {
    _Dst = (void *)FUN_180007f10(0x8000000000000000);
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
      _Dst = (void *)FUN_180007f10(uVar3);
    }
  }
  unaff_RDI[2] = unaff_R14 + param_2;
  pvVar4 = (void *)((longlong)_Dst + unaff_R14);
  unaff_RDI[3] = unaff_RBX;
  if (uVar2 < 0x10) {
    memcpy(_Dst,unaff_RDI,unaff_R14);
    memcpy(pvVar4,unaff_R12,in_stack_00000070);
    *(undefined1 *)((longlong)pvVar4 + in_stack_00000070) = 0;
  }
  else {
    _Src = (void *)*unaff_RDI;
    memcpy(_Dst,_Src,unaff_R14);
    memcpy(pvVar4,unaff_R12,in_stack_00000070);
    *(undefined1 *)((longlong)pvVar4 + in_stack_00000070) = 0;
    pvVar4 = _Src;
    if ((0xfff < uVar2 + 1) &&
       (pvVar4 = *(void **)((longlong)_Src + -8),
       0x1f < (ulonglong)((longlong)_Src + (-8 - (longlong)pvVar4)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar4);
  }
  *unaff_RDI = _Dst;
  return;
}

/* ---- FUNC 00018076 thunk_FUN_18000ace0 (5 bytes) ---- */

void thunk_FUN_18000ace0(void)

{
                    /* WARNING: Subroutine does not return */
  FUN_18000ace0();
}

/* ---- FUNC 00018080 thunk_FUN_180047b40 (5 bytes) ---- */

undefined1 (*) [32]
thunk_FUN_180047b40(undefined1 (*param_1) [32],undefined1 (*param_2) [32],char param_3)

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

/* ---- FUNC 00018090 FUN_180018090 (138 bytes) ---- */

void FUN_180018090(undefined8 param_1,longlong *param_2)

{
  void *pvVar1;
  void *pvVar2;
  
  FUN_180017c40(param_2 + 4,param_2 + 4,*(longlong **)(param_2[4] + 8));
  operator_delete((void *)param_2[4]);
  if (0xf < (ulonglong)param_2[3]) {
    pvVar1 = (void *)*param_2;
    pvVar2 = pvVar1;
    if ((0xfff < param_2[3] + 1U) &&
       (pvVar2 = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar2)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar2);
  }
  param_2[2] = 0;
  param_2[3] = 0xf;
  *(undefined1 *)param_2 = 0;
  return;
}

/* ---- FUNC 00018120 FUN_180018120 (138 bytes) ---- */

void FUN_180018120(undefined8 param_1,longlong *param_2)

{
  void *pvVar1;
  void *pvVar2;
  
  FUN_180017cc0(param_2 + 4,param_2 + 4,*(longlong **)(param_2[4] + 8));
  operator_delete((void *)param_2[4]);
  if (0xf < (ulonglong)param_2[3]) {
    pvVar1 = (void *)*param_2;
    pvVar2 = pvVar1;
    if ((0xfff < param_2[3] + 1U) &&
       (pvVar2 = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar2)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar2);
  }
  param_2[2] = 0;
  param_2[3] = 0xf;
  *(undefined1 *)param_2 = 0;
  return;
}

/* ---- FUNC 000181B0 FUN_1800181b0 (138 bytes) ---- */

void FUN_1800181b0(undefined8 param_1,longlong *param_2)

{
  void *pvVar1;
  void *pvVar2;
  
  FUN_180017e00(param_2 + 4,param_2 + 4,*(longlong **)(param_2[4] + 8));
  operator_delete((void *)param_2[4]);
  if (0xf < (ulonglong)param_2[3]) {
    pvVar1 = (void *)*param_2;
    pvVar2 = pvVar1;
    if ((0xfff < param_2[3] + 1U) &&
       (pvVar2 = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar2)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar2);
  }
  param_2[2] = 0;
  param_2[3] = 0xf;
  *(undefined1 *)param_2 = 0;
  return;
}

/* ---- FUNC 00018240 FUN_180018240 (409 bytes) ---- */

basic_istream<char,std::char_traits<char>_> *
FUN_180018240(basic_istream<char,std::char_traits<char>_> *param_1,undefined8 *param_2,uint param_3)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  basic_streambuf<char,std::char_traits<char>_> *pbVar4;
  undefined8 *puVar5;
  
  uVar3 = 0;
  bVar1 = false;
  pbVar4 = std::basic_ios<char,std::char_traits<char>_>::rdbuf
                     ((basic_ios<char,std::char_traits<char>_> *)
                      (param_1 + *(int *)(*(longlong *)param_1 + 4)));
  if (pbVar4 != (basic_streambuf<char,std::char_traits<char>_> *)0x0) {
    (**(code **)(*(longlong *)pbVar4 + 8))(pbVar4);
  }
  bVar2 = std::basic_istream<char,std::char_traits<char>_>::_Ipfx(param_1,true);
  if (bVar2) {
    param_2[2] = 0;
    puVar5 = param_2;
    if (0xf < (ulonglong)param_2[3]) {
      puVar5 = (undefined8 *)*param_2;
    }
    *(undefined1 *)puVar5 = 0;
    pbVar4 = std::basic_ios<char,std::char_traits<char>_>::rdbuf
                       ((basic_ios<char,std::char_traits<char>_> *)
                        (param_1 + *(int *)(*(longlong *)param_1 + 4)));
    uVar3 = std::basic_streambuf<char,std::char_traits<char>_>::sgetc(pbVar4);
    while (uVar3 != 0xffffffff) {
      if (uVar3 == (param_3 & 0xff)) {
        bVar1 = true;
        pbVar4 = std::basic_ios<char,std::char_traits<char>_>::rdbuf
                           ((basic_ios<char,std::char_traits<char>_> *)
                            (param_1 + *(int *)(*(longlong *)param_1 + 4)));
        std::basic_streambuf<char,std::char_traits<char>_>::sbumpc(pbVar4);
        uVar3 = 0;
        goto LAB_180018334;
      }
      if (0x7ffffffffffffffe < (ulonglong)param_2[2]) {
        uVar3 = 2;
        goto LAB_180018334;
      }
      FUN_18001b6b0(param_2,(char)uVar3);
      bVar1 = true;
      pbVar4 = std::basic_ios<char,std::char_traits<char>_>::rdbuf
                         ((basic_ios<char,std::char_traits<char>_> *)
                          (param_1 + *(int *)(*(longlong *)param_1 + 4)));
      uVar3 = std::basic_streambuf<char,std::char_traits<char>_>::snextc(pbVar4);
    }
    uVar3 = 1;
LAB_180018334:
    if (bVar1) goto LAB_180018385;
  }
  uVar3 = uVar3 | 2;
LAB_180018385:
  std::basic_ios<char,std::char_traits<char>_>::setstate
            ((basic_ios<char,std::char_traits<char>_> *)
             (param_1 + *(int *)(*(longlong *)param_1 + 4)),uVar3,false);
  pbVar4 = std::basic_ios<char,std::char_traits<char>_>::rdbuf
                     ((basic_ios<char,std::char_traits<char>_> *)
                      (param_1 + *(int *)(*(longlong *)param_1 + 4)));
  if (pbVar4 != (basic_streambuf<char,std::char_traits<char>_> *)0x0) {
    (**(code **)(*(longlong *)pbVar4 + 0x10))(pbVar4);
  }
  return param_1;
}

/* ---- FUNC 000183E0 FUN_1800183e0 (59 bytes) ---- */

void FUN_1800183e0(basic_istream<char,std::char_traits<char>_> *param_1,undefined8 *param_2)

{
  byte bVar1;
  
  bVar1 = std::basic_ios<char,std::char_traits<char>_>::widen
                    ((basic_ios<char,std::char_traits<char>_> *)
                     (param_1 + *(int *)(*(longlong *)param_1 + 4)),'\n');
  FUN_180018240(param_1,param_2,(uint)bVar1);
  return;
}

/* ---- FUNC 00018420 FUN_180018420 (223 bytes) ---- */

_Facet_base * FUN_180018420(locale *param_1)

{
  longlong lVar1;
  __uint64 _Var2;
  _Locimp *p_Var3;
  _Facet_base *p_Var4;
  _Lockit local_res8 [8];
  _Facet_base *local_res10;
  _Facet_base *local_res18;
  
  std::_Lockit::_Lockit(local_res8,0);
  local_res10 = DAT_18007a6c8;
  _Var2 = std::locale::id::operator_unsigned___int64((id *)id_exref);
  lVar1 = *(longlong *)(param_1 + 8);
  if (_Var2 < *(ulonglong *)(lVar1 + 0x18)) {
    p_Var4 = *(_Facet_base **)(_Var2 * 8 + *(longlong *)(lVar1 + 0x10));
    if (p_Var4 != (_Facet_base *)0x0) goto LAB_1800184df;
  }
  else {
    p_Var4 = (_Facet_base *)0x0;
  }
  if (*(char *)(lVar1 + 0x24) == '\0') {
LAB_180018495:
    if (p_Var4 != (_Facet_base *)0x0) goto LAB_1800184df;
  }
  else {
    p_Var3 = std::locale::_Getgloballocale();
    if (_Var2 < *(ulonglong *)(p_Var3 + 0x18)) {
      p_Var4 = *(_Facet_base **)(_Var2 * 8 + *(longlong *)(p_Var3 + 0x10));
      goto LAB_180018495;
    }
  }
  p_Var4 = local_res10;
  if (local_res10 == (_Facet_base *)0x0) {
    _Var2 = std::codecvt<char,char,_Mbstatet>::_Getcat((facet **)&local_res10,param_1);
    p_Var4 = local_res10;
    if (_Var2 == 0xffffffffffffffff) {
                    /* WARNING: Subroutine does not return */
      FUN_18001b090();
    }
    local_res18 = local_res10;
    std::_Facet_Register(local_res10);
    (**(code **)(*(longlong *)p_Var4 + 8))(p_Var4);
    DAT_18007a6c8 = local_res10;
    p_Var4 = local_res10;
  }
LAB_1800184df:
  std::_Lockit::~_Lockit(local_res8);
  return p_Var4;
}

/* ---- FUNC 00018500 FUN_180018500 (231 bytes) ---- */

undefined8 * FUN_180018500(undefined8 *param_1,undefined8 *param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  void *_Dst;
  ulonglong uVar4;
  undefined8 *_Src;
  
  _Dst = (void *)0x0;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  _Src = param_2;
  if (0xf < (ulonglong)param_2[3]) {
    _Src = (undefined8 *)*param_2;
  }
  uVar2 = param_2[2];
  if (uVar2 < 0x8000000000000000) {
    param_1[3] = 0xf;
    if (uVar2 < 0x10) {
      param_1[2] = uVar2;
      uVar3 = _Src[1];
      *param_1 = *_Src;
      param_1[1] = uVar3;
    }
    else {
      uVar4 = uVar2 | 0xf;
      if (uVar4 < 0x8000000000000000) {
        if (uVar4 < 0x16) {
          uVar4 = 0x16;
        }
        uVar1 = uVar4 + 1;
        if (uVar1 < 0x1000) {
          if (uVar1 != 0) {
            _Dst = operator_new(uVar1);
          }
        }
        else {
          _Dst = (void *)FUN_180007f10(uVar1);
        }
      }
      else {
        _Dst = (void *)FUN_180007f10(0x8000000000000000);
        uVar4 = 0x7fffffffffffffff;
      }
      *param_1 = _Dst;
      param_1[2] = uVar2;
      param_1[3] = uVar4;
      memcpy(_Dst,_Src,uVar2 + 1);
    }
    return param_1;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18000ace0();
}

/* ---- FUNC 000185F0 FUN_1800185f0 (206 bytes) ---- */

longlong * FUN_1800185f0(longlong *param_1,longlong *param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong lVar4;
  longlong *plVar5;
  void *pvVar6;
  longlong *plVar7;
  
  *param_1 = 0;
  param_1[1] = 0;
  pvVar6 = operator_new(0x38);
  *(void **)pvVar6 = pvVar6;
  *(void **)((longlong)pvVar6 + 8) = pvVar6;
  *(void **)((longlong)pvVar6 + 0x10) = pvVar6;
  *(undefined2 *)((longlong)pvVar6 + 0x18) = 0x101;
  *param_1 = (longlong)pvVar6;
  plVar7 = FUN_180017640(param_1,*(undefined8 **)(*param_2 + 8),(longlong)pvVar6,param_4);
  *(longlong **)(*param_1 + 8) = plVar7;
  param_1[1] = param_2[1];
  plVar7 = (longlong *)*param_1;
  plVar2 = (longlong *)plVar7[1];
  if (*(char *)((longlong)plVar2 + 0x19) == '\0') {
    cVar1 = *(char *)(*plVar2 + 0x19);
    plVar5 = (longlong *)*plVar2;
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*plVar5 + 0x19);
      plVar2 = plVar5;
      plVar5 = (longlong *)*plVar5;
    }
    *plVar7 = (longlong)plVar2;
    lVar3 = *(longlong *)(*param_1 + 8);
    lVar4 = *(longlong *)(lVar3 + 0x10);
    cVar1 = *(char *)(lVar4 + 0x19);
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*(longlong *)(lVar4 + 0x10) + 0x19);
      lVar3 = lVar4;
      lVar4 = *(longlong *)(lVar4 + 0x10);
    }
    *(longlong *)(*param_1 + 0x10) = lVar3;
  }
  else {
    *plVar7 = (longlong)plVar7;
    *(longlong *)(*param_1 + 0x10) = *param_1;
  }
  return param_1;
}

/* ---- FUNC 000186C0 FUN_1800186c0 (206 bytes) ---- */

longlong * FUN_1800186c0(longlong *param_1,longlong *param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong lVar4;
  longlong *plVar5;
  void *pvVar6;
  longlong *plVar7;
  
  *param_1 = 0;
  param_1[1] = 0;
  pvVar6 = operator_new(0x58);
  *(void **)pvVar6 = pvVar6;
  *(void **)((longlong)pvVar6 + 8) = pvVar6;
  *(void **)((longlong)pvVar6 + 0x10) = pvVar6;
  *(undefined2 *)((longlong)pvVar6 + 0x18) = 0x101;
  *param_1 = (longlong)pvVar6;
  plVar7 = FUN_1800177c0(param_1,*(undefined8 **)(*param_2 + 8),(longlong)pvVar6,param_4);
  *(longlong **)(*param_1 + 8) = plVar7;
  param_1[1] = param_2[1];
  plVar7 = (longlong *)*param_1;
  plVar2 = (longlong *)plVar7[1];
  if (*(char *)((longlong)plVar2 + 0x19) == '\0') {
    cVar1 = *(char *)(*plVar2 + 0x19);
    plVar5 = (longlong *)*plVar2;
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*plVar5 + 0x19);
      plVar2 = plVar5;
      plVar5 = (longlong *)*plVar5;
    }
    *plVar7 = (longlong)plVar2;
    lVar3 = *(longlong *)(*param_1 + 8);
    lVar4 = *(longlong *)(lVar3 + 0x10);
    cVar1 = *(char *)(lVar4 + 0x19);
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*(longlong *)(lVar4 + 0x10) + 0x19);
      lVar3 = lVar4;
      lVar4 = *(longlong *)(lVar4 + 0x10);
    }
    *(longlong *)(*param_1 + 0x10) = lVar3;
  }
  else {
    *plVar7 = (longlong)plVar7;
    *(longlong *)(*param_1 + 0x10) = *param_1;
  }
  return param_1;
}

/* ---- FUNC 00018790 FUN_180018790 (114 bytes) ---- */

undefined8 *
FUN_180018790(undefined8 *param_1,longlong param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  FUN_180018910(param_1,0,0,param_2);
  param_1[0x23] = param_3;
  *param_1 = CBufferStream::vftable;
  uVar1 = 6;
  if (param_1[0x1f] != 0) {
    uVar1 = 0;
  }
  *(undefined4 *)((longlong)param_1 + 0x124) = param_4;
  *(undefined4 *)(param_1 + 0x20) = uVar1;
  *(undefined4 *)(param_1 + 0x25) = param_4;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return param_1;
}

/* ---- FUNC 00018810 FUN_180018810 (192 bytes) ---- */

undefined8 * FUN_180018810(undefined8 *param_1,LPCSTR param_2)

{
  int cchWideChar;
  int iVar1;
  BSTR lpWideCharStr;
  
  if (param_2 == (LPCSTR)0x0) {
    *param_1 = 0;
    return param_1;
  }
  cchWideChar = MultiByteToWideChar(0,0,param_2,-1,(LPWSTR)0x0,0);
  lpWideCharStr = SysAllocStringLen((OLECHAR *)0x0,cchWideChar - 1);
  if ((lpWideCharStr == (BSTR)0x0) ||
     (iVar1 = MultiByteToWideChar(0,0,param_2,-1,lpWideCharStr,cchWideChar), iVar1 == cchWideChar))
  {
    *param_1 = lpWideCharStr;
    if (lpWideCharStr != (BSTR)0x0) {
      return param_1;
    }
  }
  else {
    SysFreeString(lpWideCharStr);
    *param_1 = 0;
  }
                    /* WARNING: Subroutine does not return */
  FUN_180018e40(-0x7ff8fff2);
}

/* ---- FUNC 000188E0 FUN_1800188e0 (33 bytes) ---- */

undefined8 *
FUN_1800188e0(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  param_1[2] = param_2;
  *param_1 = CGenStream::vftable;
  param_1[3] = param_3;
  param_1[4] = param_4;
  *(undefined4 *)(param_1 + 1) = 0;
  return param_1;
}

/* ---- FUNC 00018910 FUN_180018910 (104 bytes) ---- */

undefined8 *
FUN_180018910(undefined8 *param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  undefined4 uVar1;
  
  param_1[0x1c] = param_2;
  *param_1 = CTextBufferStream::vftable;
  *(undefined1 *)((longlong)param_1 + 0xc) = 0;
  param_1[0x1e] = (undefined1 *)((longlong)param_1 + 0xc);
  uVar1 = 6;
  if (param_4 != 0) {
    uVar1 = 0;
  }
  param_1[0x1d] = param_3;
  *(undefined4 *)(param_1 + 0x20) = uVar1;
  *(undefined4 *)(param_1 + 1) = 0;
  *(undefined8 *)((longlong)param_1 + 0xd4) = 1;
  param_1[0x1f] = param_4;
  param_1[0x21] = 0;
  *(undefined4 *)(param_1 + 0x22) = 0;
  *(undefined4 *)((longlong)param_1 + 0x114) = 1;
  return param_1;
}

/* ---- FUNC 00018980 FUN_180018980 (151 bytes) ---- */

undefined8 *
FUN_180018980(undefined8 *param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
             undefined8 param_5,longlong param_6)

{
  undefined4 uVar1;
  
  FUN_180018910(param_1,0,0,param_6);
  param_1[0x23] = param_2;
  *param_1 = CTextFileStream::vftable;
  param_1[0x25] = param_5;
  uVar1 = 6;
  if (param_1[0x1f] != 0) {
    uVar1 = 0;
  }
  param_1[0x24] = param_4;
  *(undefined4 *)(param_1 + 0x20) = uVar1;
  *(undefined4 *)(param_1 + 0x26) = param_3;
  *(undefined4 *)((longlong)param_1 + 0x134) = 1;
  return param_1;
}

