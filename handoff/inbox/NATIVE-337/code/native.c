/* NATIVE-337 reconstructed C (Hex-Rays) */

/* ---- FUNC 00001000 sub_180001000 ---- */
int sub_180001000()
{
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>>>(
    (ATL::CStringT<char, class StrTraitMFC_DLL<char, class ATL::ChTraitsCRT<char>>> *)&unk_18000B728,
    byte_180007738);
  return atexit(sub_180006230);
}

/* ---- FUNC 00001028 sub_180001028 ---- */
int sub_180001028()
{
  sub_180005C20((__int64)&unk_18000BD40);
  return atexit(sub_180006240);
}

/* ---- FUNC 00001050 sub_180001050 ---- */
int sub_180001050()
{
  return atexit(sub_180006250);
}

/* ---- FUNC 00001060 sub_180001060 ---- */
void __fastcall __noreturn sub_180001060(int a1)
{
  if ( a1 == -2147024882 )
    AfxThrowMemoryException();
  AfxThrowOleException(a1);
}

/* ---- FUNC 00001080 InitializeCriticalSectionEx ---- */
// attributes: thunk
BOOL __stdcall InitializeCriticalSectionEx(LPCRITICAL_SECTION lpCriticalSection, DWORD dwSpinCount, DWORD Flags)
{
  return __imp_InitializeCriticalSectionEx(lpCriticalSection, dwSpinCount, Flags);
}

/* ---- FUNC 00001090 _guard_check_icall_nop ---- */
void guard_check_icall_nop()
{
  ;
}

/* ---- FUNC 000010A0 gxSetRefState ---- */
void __fastcall gxSetRefState(int a1)
{
  dword_18000B5A4 = a1;
}

/* ---- FUNC 000010B0 sub_1800010B0 ---- */
__int64 __fastcall sub_1800010B0(__int64 a1, int a2)
{
  struct AFX_MODULE_STATE *ModuleState; // rax

  if ( a2 == 1 )
  {
    ModuleState = AfxGetModuleState();
    *((_QWORD *)ModuleState + 6) = *((_QWORD *)ModuleState + 7);
    *((_QWORD *)ModuleState + 9) = *((_QWORD *)ModuleState + 10);
    *((_QWORD *)ModuleState + 7) = 0;
    *((_QWORD *)ModuleState + 10) = 0;
  }
  return 1;
}

/* ---- FUNC 000010F0 sub_1800010F0 ---- */
OLECHAR **__fastcall sub_1800010F0(OLECHAR **a1, const CHAR *a2)
{
  int cchWideChar; // r14d
  WCHAR *lpWideCharStr; // rax
  OLECHAR *v6; // rsi

  if ( a2 != nullptr )
  {
    cchWideChar = MultiByteToWideChar(0, 0, a2, -1, nullptr, 0);
    lpWideCharStr = SysAllocStringLen(nullptr, cchWideChar - 1);
    v6 = lpWideCharStr;
    if ( lpWideCharStr != nullptr && MultiByteToWideChar(0, 0, a2, -1, lpWideCharStr, cchWideChar) != cchWideChar )
    {
      SysFreeString(v6);
      *a1 = nullptr;
    }
    else
    {
      *a1 = v6;
      if ( v6 != nullptr )
        return a1;
    }
    sub_180001060(-2147024882);
  }
  *a1 = nullptr;
  return a1;
}

/* ---- FUNC 000011C0 sub_1800011C0 ---- */
void __fastcall sub_1800011C0(BSTR *a1)
{
  SysFreeString(*a1);
}

/* ---- FUNC 000011D0 VariantClear ---- */
// attributes: thunk
HRESULT __stdcall VariantClear(VARIANTARG *pvarg)
{
  return __imp_VariantClear(pvarg);
}

/* ---- FUNC 000011E0 sub_1800011E0 ---- */
// Hidden C++ exception states: #wind=1
__int64 __fastcall sub_1800011E0(BSTR *a1, const CHAR *a2)
{
  HRESULT v5; // edi
  int cchWideChar; // r15d
  WCHAR *lpWideCharStr; // rax
  OLECHAR *v8; // rbx
  CException *v9; // [rsp+30h] [rbp-38h] BYREF
  BSTR *v10; // [rsp+70h] [rbp+8h]
  BSTR pbstrResult; // [rsp+78h] [rbp+10h] BYREF
  OLECHAR *v12; // [rsp+80h] [rbp+18h]

  if ( a2 == nullptr )
    return 0;
  SysFreeString(nullptr);
  v5 = 0;
  cchWideChar = MultiByteToWideChar(0, 0, a2, -1, nullptr, 0);
  lpWideCharStr = SysAllocStringLen(nullptr, cchWideChar - 1);
  v8 = lpWideCharStr;
  if ( lpWideCharStr == nullptr || MultiByteToWideChar(0, 0, a2, -1, lpWideCharStr, cchWideChar) == cchWideChar )
  {
    pbstrResult = v8;
    v12 = v8;
    if ( v8 != nullptr )
      goto LABEL_11;
  }
  else
  {
    SysFreeString(v8);
    pbstrResult = nullptr;
    v12 = nullptr;
  }
  try
  {
    sub_180001060(-2147024882);
  }
  catch ( CException *v9 )
  {
    CException::Delete(v9);
    v8 = pbstrResult;
    if ( pbstrResult == nullptr )
    {
      SysFreeString(nullptr);
      return 2147942414LL;
    }
    v5 = 0;
    a1 = v10;
  }
LABEL_11:
  if ( SysStringLen(v8) != 0 )
  {
    pbstrResult = nullptr;
    v5 = VarBstrCat(*a1, v8, &pbstrResult);
    if ( v5 >= 0 )
    {
      SysFreeString(*a1);
      *a1 = pbstrResult;
    }
  }
  SysFreeString(v8);
  return (unsigned int)v5;
}

/* ---- FUNC 00001320 sub_180001320 ---- */
// Hidden C++ exception states: #wind=1
__int64 __fastcall sub_180001320(__int64 a1)
{
  __int64 *v2; // rdi
  __int64 v3; // rbx
  LCID UserDefaultLCID; // eax
  unsigned int Lo; // esi
  unsigned int v7; // ebx
  __int64 v8; // rbx
  LCID v9; // eax
  int v10; // [rsp+20h] [rbp-98h]
  _QWORD v11[2]; // [rsp+50h] [rbp-68h] BYREF
  __int64 v12; // [rsp+60h] [rbp-58h]
  _QWORD v13[3]; // [rsp+68h] [rbp-50h] BYREF
  VARIANTARG pvarg; // [rsp+80h] [rbp-38h] BYREF
  unsigned int v15; // [rsp+C8h] [rbp+10h] BYREF
  const wchar_t *v16; // [rsp+D0h] [rbp+18h] BYREF

  v2 = (__int64 *)sub_180002330();
  if ( v2 == nullptr )
    return 0;
  v16 = L"ShowDialog";
  v3 = *v2;
  UserDefaultLCID = GetUserDefaultLCID();
  if ( (*(int (__fastcall **)(__int64 *, void *, const wchar_t **, __int64, LCID, unsigned int *))(v3 + 40))(
         v2,
         &unk_1800082F8,
         &v16,
         1,
         UserDefaultLCID,
         &v15) < 0 )
  {
    (*(void (__fastcall **)(__int64 *))(*v2 + 16))(v2);
    return 0;
  }
  Lo = 0;
  v11[1] = 0;
  v12 = 1;
  v11[0] = v13;
  v7 = 0;
  do
    VariantInit((VARIANTARG *)&v13[3 * v7++]);
  while ( v7 < (unsigned int)v12 );
  LOWORD(v13[0]) = 8;
  v13[1] = a1;
  COleVariant::COleVariant((COleVariant *)&pvarg, 0, 3u);
  v8 = *v2;
  v9 = GetUserDefaultLCID();
  LOWORD(v10) = 1;
  if ( (*(int (__fastcall **)(__int64 *, _QWORD, void *, _QWORD, int, _QWORD *, VARIANTARG *, _QWORD, _QWORD))(v8 + 48))(
         v2,
         v15,
         &unk_1800082F8,
         v9,
         v10,
         v11,
         &pvarg,
         0,
         0) >= 0 )
    Lo = pvarg.cyVal.Lo;
  (*(void (__fastcall **)(__int64 *))(*v2 + 16))(v2);
  VariantClear(&pvarg);
  return Lo;
}

/* ---- FUNC 00001490 sub_180001490 ---- */
// Hidden C++ exception states: #wind=1
__int64 __fastcall sub_180001490(int a1)
{
  __int64 *v2; // rdi
  __int64 v3; // rbx
  LCID UserDefaultLCID; // eax
  unsigned int Lo; // esi
  unsigned int v7; // ebx
  __int64 v8; // rbx
  LCID v9; // eax
  int v10; // [rsp+20h] [rbp-98h]
  _QWORD v11[2]; // [rsp+50h] [rbp-68h] BYREF
  __int64 v12; // [rsp+60h] [rbp-58h]
  _DWORD v13[6]; // [rsp+68h] [rbp-50h] BYREF
  VARIANTARG pvarg; // [rsp+80h] [rbp-38h] BYREF
  unsigned int v15; // [rsp+C8h] [rbp+10h] BYREF
  const wchar_t *v16; // [rsp+D0h] [rbp+18h] BYREF

  v2 = (__int64 *)sub_180002330();
  if ( v2 == nullptr )
    return 0;
  v16 = L"ShowElecWizard";
  v3 = *v2;
  UserDefaultLCID = GetUserDefaultLCID();
  if ( (*(int (__fastcall **)(__int64 *, void *, const wchar_t **, __int64, LCID, unsigned int *))(v3 + 40))(
         v2,
         &unk_1800082F8,
         &v16,
         1,
         UserDefaultLCID,
         &v15) < 0 )
  {
    (*(void (__fastcall **)(__int64 *))(*v2 + 16))(v2);
    return 0;
  }
  Lo = 0;
  v11[1] = 0;
  v12 = 1;
  v11[0] = v13;
  v7 = 0;
  do
    VariantInit((VARIANTARG *)&v13[6 * v7++]);
  while ( v7 < (unsigned int)v12 );
  LOWORD(v13[0]) = 3;
  v13[2] = a1;
  COleVariant::COleVariant((COleVariant *)&pvarg, 0, 3u);
  v8 = *v2;
  v9 = GetUserDefaultLCID();
  LOWORD(v10) = 1;
  if ( (*(int (__fastcall **)(__int64 *, _QWORD, void *, _QWORD, int, _QWORD *, VARIANTARG *, _QWORD, _QWORD))(v8 + 48))(
         v2,
         v15,
         &unk_1800082F8,
         v9,
         v10,
         v11,
         &pvarg,
         0,
         0) >= 0 )
    Lo = pvarg.cyVal.Lo;
  (*(void (__fastcall **)(__int64 *))(*v2 + 16))(v2);
  VariantClear(&pvarg);
  return Lo;
}

/* ---- FUNC 000015F0 sub_1800015F0 ---- */
// Hidden C++ exception states: #wind=1
__int64 __fastcall sub_1800015F0(BSTR *a1)
{
  __int64 *v2; // rdi
  __int64 v3; // rbx
  LCID UserDefaultLCID; // eax
  unsigned int Lo; // esi
  unsigned int v7; // ebx
  __int64 v8; // rbx
  LCID v9; // eax
  int v10; // [rsp+20h] [rbp-A8h]
  _QWORD v11[2]; // [rsp+50h] [rbp-78h] BYREF
  __int64 v12; // [rsp+60h] [rbp-68h]
  _QWORD v13[3]; // [rsp+68h] [rbp-60h] BYREF
  VARIANTARG pvarg; // [rsp+80h] [rbp-48h] BYREF
  unsigned int v15; // [rsp+D8h] [rbp+10h] BYREF
  BSTR bstrString; // [rsp+E0h] [rbp+18h] BYREF
  const wchar_t *v17; // [rsp+E8h] [rbp+20h] BYREF

  v2 = (__int64 *)sub_180002330();
  if ( v2 == nullptr )
    return 0;
  v17 = L"ShowNewPureCompParam";
  v3 = *v2;
  UserDefaultLCID = GetUserDefaultLCID();
  if ( (*(int (__fastcall **)(__int64 *, void *, const wchar_t **, __int64, LCID, unsigned int *))(v3 + 40))(
         v2,
         &unk_1800082F8,
         &v17,
         1,
         UserDefaultLCID,
         &v15) < 0 )
  {
    (*(void (__fastcall **)(__int64 *))(*v2 + 16))(v2);
    return 0;
  }
  Lo = 0;
  v11[1] = 0;
  v12 = 1;
  v11[0] = v13;
  v7 = 0;
  do
    VariantInit((VARIANTARG *)&v13[3 * v7++]);
  while ( v7 < (unsigned int)v12 );
  bstrString = SysAllocString(&psz);
  LOWORD(v13[0]) = 16392;
  v13[1] = &bstrString;
  COleVariant::COleVariant((COleVariant *)&pvarg, 0, 3u);
  v8 = *v2;
  v9 = GetUserDefaultLCID();
  LOWORD(v10) = 1;
  if ( (*(int (__fastcall **)(__int64 *, _QWORD, void *, _QWORD, int, _QWORD *, VARIANTARG *, _QWORD, _QWORD))(v8 + 48))(
         v2,
         v15,
         &unk_1800082F8,
         v9,
         v10,
         v11,
         &pvarg,
         0,
         0) >= 0 )
  {
    Lo = pvarg.cyVal.Lo;
    *a1 = bstrString;
  }
  (*(void (__fastcall **)(__int64 *))(*v2 + 16))(v2);
  SysFreeString(bstrString);
  VariantClear(&pvarg);
  return Lo;
}

/* ---- FUNC 00001780 sub_180001780 ---- */
__int64 __fastcall sub_180001780(int a1)
{
  __int64 *v2; // rdi
  __int64 v3; // rbx
  LCID UserDefaultLCID; // eax
  unsigned int Lo; // esi
  unsigned int v7; // ebx
  __int64 v8; // rbx
  LCID v9; // eax
  int v10; // [rsp+20h] [rbp-98h]
  _QWORD v11[2]; // [rsp+50h] [rbp-68h] BYREF
  __int64 v12; // [rsp+60h] [rbp-58h]
  _DWORD v13[6]; // [rsp+68h] [rbp-50h] BYREF
  VARIANTARG pvarg; // [rsp+80h] [rbp-38h] BYREF
  unsigned int v15; // [rsp+C8h] [rbp+10h] BYREF
  const wchar_t *v16; // [rsp+D0h] [rbp+18h] BYREF

  v2 = (__int64 *)sub_180002330();
  if ( v2 == nullptr )
    return 0;
  v16 = L"ShowSFEAssistant";
  v3 = *v2;
  UserDefaultLCID = GetUserDefaultLCID();
  if ( (*(int (__fastcall **)(__int64 *, void *, const wchar_t **, __int64, LCID, unsigned int *))(v3 + 40))(
         v2,
         &unk_1800082F8,
         &v16,
         1,
         UserDefaultLCID,
         &v15) < 0 )
  {
    (*(void (__fastcall **)(__int64 *))(*v2 + 16))(v2);
    return 0;
  }
  Lo = 0;
  v11[1] = 0;
  v12 = 1;
  v11[0] = v13;
  v7 = 0;
  do
    VariantInit((VARIANTARG *)&v13[6 * v7++]);
  while ( v7 < (unsigned int)v12 );
  LOWORD(v13[0]) = 3;
  v13[2] = a1;
  COleVariant::COleVariant((COleVariant *)&pvarg, 0, 3u);
  v8 = *v2;
  v9 = GetUserDefaultLCID();
  LOWORD(v10) = 1;
  if ( (*(int (__fastcall **)(__int64 *, _QWORD, void *, _QWORD, int, _QWORD *, VARIANTARG *, _QWORD, _QWORD))(v8 + 48))(
         v2,
         v15,
         &unk_1800082F8,
         v9,
         v10,
         v11,
         &pvarg,
         0,
         0) >= 0 )
    Lo = pvarg.cyVal.Lo;
  (*(void (__fastcall **)(__int64 *))(*v2 + 16))(v2);
  VariantClear(&pvarg);
  return Lo;
}

/* ---- FUNC 000018E0 sub_1800018E0 ---- */
__int64 __fastcall sub_1800018E0(int a1)
{
  __int64 *v2; // rdi
  __int64 v3; // rbx
  LCID UserDefaultLCID; // eax
  unsigned int Lo; // esi
  unsigned int v7; // ebx
  __int64 v8; // rbx
  LCID v9; // eax
  int v10; // [rsp+20h] [rbp-98h]
  _QWORD v11[2]; // [rsp+50h] [rbp-68h] BYREF
  __int64 v12; // [rsp+60h] [rbp-58h]
  _DWORD v13[6]; // [rsp+68h] [rbp-50h] BYREF
  VARIANTARG pvarg; // [rsp+80h] [rbp-38h] BYREF
  unsigned int v15; // [rsp+C8h] [rbp+10h] BYREF
  const wchar_t *v16; // [rsp+D0h] [rbp+18h] BYREF

  v2 = (__int64 *)sub_180002330();
  if ( v2 == nullptr )
    return 0;
  v16 = L"ShowSFEAssistantMain";
  v3 = *v2;
  UserDefaultLCID = GetUserDefaultLCID();
  if ( (*(int (__fastcall **)(__int64 *, void *, const wchar_t **, __int64, LCID, unsigned int *))(v3 + 40))(
         v2,
         &unk_1800082F8,
         &v16,
         1,
         UserDefaultLCID,
         &v15) < 0 )
  {
    (*(void (__fastcall **)(__int64 *))(*v2 + 16))(v2);
    return 0;
  }
  Lo = 0;
  v11[1] = 0;
  v12 = 1;
  v11[0] = v13;
  v7 = 0;
  do
    VariantInit((VARIANTARG *)&v13[6 * v7++]);
  while ( v7 < (unsigned int)v12 );
  LOWORD(v13[0]) = 3;
  v13[2] = a1;
  COleVariant::COleVariant((COleVariant *)&pvarg, 0, 3u);
  v8 = *v2;
  v9 = GetUserDefaultLCID();
  LOWORD(v10) = 1;
  if ( (*(int (__fastcall **)(__int64 *, _QWORD, void *, _QWORD, int, _QWORD *, VARIANTARG *, _QWORD, _QWORD))(v8 + 48))(
         v2,
         v15,
         &unk_1800082F8,
         v9,
         v10,
         v11,
         &pvarg,
         0,
         0) >= 0 )
    Lo = pvarg.cyVal.Lo;
  (*(void (__fastcall **)(__int64 *))(*v2 + 16))(v2);
  VariantClear(&pvarg);
  return Lo;
}

/* ---- FUNC 00001A40 sub_180001A40 ---- */
// Hidden C++ exception states: #wind=1
__int64 __fastcall sub_180001A40(__int64 a1, int a2, __int64 a3)
{
  __int64 *v6; // rdi
  __int64 v7; // rbx
  LCID UserDefaultLCID; // eax
  unsigned int Lo; // esi
  unsigned int v11; // ebx
  __int64 v12; // rbx
  LCID v13; // eax
  int v14; // [rsp+20h] [rbp-F8h]
  unsigned int v15; // [rsp+50h] [rbp-C8h] BYREF
  const wchar_t *v16; // [rsp+58h] [rbp-C0h] BYREF
  _QWORD v17[2]; // [rsp+60h] [rbp-B8h] BYREF
  __int64 v18; // [rsp+70h] [rbp-A8h]
  VARIANTARG pvarg; // [rsp+78h] [rbp-A0h] BYREF
  _QWORD v20[3]; // [rsp+90h] [rbp-88h] BYREF
  __int16 v21; // [rsp+A8h] [rbp-70h]
  int v22; // [rsp+B0h] [rbp-68h]
  __int16 v23; // [rsp+C0h] [rbp-58h]
  __int64 v24; // [rsp+C8h] [rbp-50h]

  v6 = (__int64 *)sub_180002330();
  if ( v6 == nullptr )
    return 0;
  v16 = L"ShowSearchComponent";
  v7 = *v6;
  UserDefaultLCID = GetUserDefaultLCID();
  if ( (*(int (__fastcall **)(__int64 *, void *, const wchar_t **, __int64, LCID, unsigned int *))(v7 + 40))(
         v6,
         &unk_1800082F8,
         &v16,
         1,
         UserDefaultLCID,
         &v15) < 0 )
  {
    (*(void (__fastcall **)(__int64 *))(*v6 + 16))(v6);
    return 0;
  }
  Lo = 0;
  v17[1] = 0;
  v18 = 3;
  v17[0] = v20;
  v11 = 0;
  do
    VariantInit((VARIANTARG *)&v20[3 * v11++]);
  while ( v11 < (unsigned int)v18 );
  v23 = 8;
  v24 = a1;
  v21 = 3;
  v22 = a2;
  LOWORD(v20[0]) = 8;
  v20[1] = a3;
  COleVariant::COleVariant((COleVariant *)&pvarg, 0, 3u);
  v12 = *v6;
  v13 = GetUserDefaultLCID();
  LOWORD(v14) = 1;
  if ( (*(int (__fastcall **)(__int64 *, _QWORD, void *, _QWORD, int, _QWORD *, VARIANTARG *, _QWORD, _QWORD))(v12 + 48))(
         v6,
         v15,
         &unk_1800082F8,
         v13,
         v14,
         v17,
         &pvarg,
         0,
         0) >= 0 )
    Lo = pvarg.cyVal.Lo;
  (*(void (__fastcall **)(__int64 *))(*v6 + 16))(v6);
  VariantClear(&pvarg);
  return Lo;
}

/* ---- FUNC 00001C00 sub_180001C00 ---- */
__int64 __fastcall sub_180001C00(__int64 a1)
{
  __int64 *v2; // rdi
  __int64 v3; // rbx
  LCID UserDefaultLCID; // eax
  unsigned int Lo; // esi
  unsigned int v7; // ebx
  __int64 v8; // rbx
  LCID v9; // eax
  int v10; // [rsp+20h] [rbp-98h]
  _QWORD v11[2]; // [rsp+50h] [rbp-68h] BYREF
  __int64 v12; // [rsp+60h] [rbp-58h]
  _QWORD v13[3]; // [rsp+68h] [rbp-50h] BYREF
  VARIANTARG pvarg; // [rsp+80h] [rbp-38h] BYREF
  unsigned int v15; // [rsp+C8h] [rbp+10h] BYREF
  const wchar_t *v16; // [rsp+D0h] [rbp+18h] BYREF

  v2 = (__int64 *)sub_180002330();
  if ( v2 == nullptr )
    return 0;
  v16 = L"ShowSearchProperty";
  v3 = *v2;
  UserDefaultLCID = GetUserDefaultLCID();
  if ( (*(int (__fastcall **)(__int64 *, void *, const wchar_t **, __int64, LCID, unsigned int *))(v3 + 40))(
         v2,
         &unk_1800082F8,
         &v16,
         1,
         UserDefaultLCID,
         &v15) < 0 )
  {
    (*(void (__fastcall **)(__int64 *))(*v2 + 16))(v2);
    return 0;
  }
  Lo = 0;
  v11[1] = 0;
  v12 = 1;
  v11[0] = v13;
  v7 = 0;
  do
    VariantInit((VARIANTARG *)&v13[3 * v7++]);
  while ( v7 < (unsigned int)v12 );
  LOWORD(v13[0]) = 8;
  v13[1] = a1;
  COleVariant::COleVariant((COleVariant *)&pvarg, 0, 3u);
  v8 = *v2;
  v9 = GetUserDefaultLCID();
  LOWORD(v10) = 1;
  if ( (*(int (__fastcall **)(__int64 *, _QWORD, void *, _QWORD, int, _QWORD *, VARIANTARG *, _QWORD, _QWORD))(v8 + 48))(
         v2,
         v15,
         &unk_1800082F8,
         v9,
         v10,
         v11,
         &pvarg,
         0,
         0) >= 0 )
    Lo = pvarg.cyVal.Lo;
  (*(void (__fastcall **)(__int64 *))(*v2 + 16))(v2);
  VariantClear(&pvarg);
  return Lo;
}

/* ---- FUNC 00001D70 sub_180001D70 ---- */
// Hidden C++ exception states: #wind=1
__int64 __fastcall sub_180001D70(int a1, int *a2)
{
  __int64 *v4; // rdi
  __int64 v5; // rbx
  LCID UserDefaultLCID; // eax
  unsigned int Lo; // esi
  unsigned int v9; // ebx
  __int64 v10; // rbx
  LCID v11; // eax
  int v12; // [rsp+20h] [rbp-C8h]
  const wchar_t *v13; // [rsp+50h] [rbp-98h] BYREF
  _QWORD v14[2]; // [rsp+58h] [rbp-90h] BYREF
  __int64 v15; // [rsp+68h] [rbp-80h]
  VARIANTARG pvarg; // [rsp+70h] [rbp-78h] BYREF
  _QWORD v17[3]; // [rsp+88h] [rbp-60h] BYREF
  __int16 v18; // [rsp+A0h] [rbp-48h]
  int v19; // [rsp+A8h] [rbp-40h]
  int v20; // [rsp+100h] [rbp+18h] BYREF
  unsigned int v21; // [rsp+108h] [rbp+20h] BYREF

  v4 = (__int64 *)sub_180002330();
  if ( v4 == nullptr )
    return 0;
  v13 = L"ShowUpgradeRetired";
  v5 = *v4;
  UserDefaultLCID = GetUserDefaultLCID();
  if ( (*(int (__fastcall **)(__int64 *, void *, const wchar_t **, __int64, LCID, unsigned int *))(v5 + 40))(
         v4,
         &unk_1800082F8,
         &v13,
         1,
         UserDefaultLCID,
         &v21) < 0 )
  {
    (*(void (__fastcall **)(__int64 *))(*v4 + 16))(v4);
    return 0;
  }
  Lo = 0;
  v14[1] = 0;
  v15 = 2;
  v14[0] = v17;
  v9 = 0;
  do
    VariantInit((VARIANTARG *)&v17[3 * v9++]);
  while ( v9 < (unsigned int)v15 );
  v20 = -1;
  v18 = 3;
  v19 = a1;
  LOWORD(v17[0]) = 16387;
  v17[1] = &v20;
  COleVariant::COleVariant((COleVariant *)&pvarg, 0, 3u);
  v10 = *v4;
  v11 = GetUserDefaultLCID();
  LOWORD(v12) = 1;
  if ( (*(int (__fastcall **)(__int64 *, _QWORD, void *, _QWORD, int, _QWORD *, VARIANTARG *, _QWORD, _QWORD))(v10 + 48))(
         v4,
         v21,
         &unk_1800082F8,
         v11,
         v12,
         v14,
         &pvarg,
         0,
         0) >= 0 )
  {
    Lo = pvarg.cyVal.Lo;
    *a2 = v20;
  }
  (*(void (__fastcall **)(__int64 *))(*v4 + 16))(v4);
  VariantClear(&pvarg);
  return Lo;
}

/* ---- FUNC 00001F00 sub_180001F00 ---- */
__int64 __fastcall sub_180001F00(int a1)
{
  __int64 *v2; // rdi
  __int64 v3; // rbx
  LCID UserDefaultLCID; // eax
  unsigned int Lo; // esi
  unsigned int v7; // ebx
  __int64 v8; // rbx
  LCID v9; // eax
  int v10; // [rsp+20h] [rbp-98h]
  _QWORD v11[2]; // [rsp+50h] [rbp-68h] BYREF
  __int64 v12; // [rsp+60h] [rbp-58h]
  _DWORD v13[6]; // [rsp+68h] [rbp-50h] BYREF
  VARIANTARG pvarg; // [rsp+80h] [rbp-38h] BYREF
  unsigned int v15; // [rsp+C8h] [rbp+10h] BYREF
  const wchar_t *v16; // [rsp+D0h] [rbp+18h] BYREF

  v2 = (__int64 *)sub_180002330();
  if ( v2 == nullptr )
    return 0;
  v16 = L"ShowUpwardComp1";
  v3 = *v2;
  UserDefaultLCID = GetUserDefaultLCID();
  if ( (*(int (__fastcall **)(__int64 *, void *, const wchar_t **, __int64, LCID, unsigned int *))(v3 + 40))(
         v2,
         &unk_1800082F8,
         &v16,
         1,
         UserDefaultLCID,
         &v15) < 0 )
  {
    (*(void (__fastcall **)(__int64 *))(*v2 + 16))(v2);
    return 0;
  }
  Lo = 0;
  v11[1] = 0;
  v12 = 1;
  v11[0] = v13;
  v7 = 0;
  do
    VariantInit((VARIANTARG *)&v13[6 * v7++]);
  while ( v7 < (unsigned int)v12 );
  LOWORD(v13[0]) = 3;
  v13[2] = a1;
  COleVariant::COleVariant((COleVariant *)&pvarg, 0, 3u);
  v8 = *v2;
  v9 = GetUserDefaultLCID();
  LOWORD(v10) = 1;
  if ( (*(int (__fastcall **)(__int64 *, _QWORD, void *, _QWORD, int, _QWORD *, VARIANTARG *, _QWORD, _QWORD))(v8 + 48))(
         v2,
         v15,
         &unk_1800082F8,
         v9,
         v10,
         v11,
         &pvarg,
         0,
         0) >= 0 )
    Lo = pvarg.cyVal.Lo;
  (*(void (__fastcall **)(__int64 *))(*v2 + 16))(v2);
  VariantClear(&pvarg);
  return Lo;
}

/* ---- FUNC 00002060 sub_180002060 ---- */
// Hidden C++ exception states: #wind=1
__int64 __fastcall sub_180002060(int a1, int a2)
{
  __int64 *v4; // rdi
  __int64 v5; // rbx
  LCID UserDefaultLCID; // eax
  unsigned int Lo; // esi
  unsigned int v9; // ebx
  __int64 v10; // rbx
  LCID v11; // eax
  int v12; // [rsp+20h] [rbp-B8h]
  _QWORD v13[2]; // [rsp+50h] [rbp-88h] BYREF
  __int64 v14; // [rsp+60h] [rbp-78h]
  VARIANTARG pvarg; // [rsp+68h] [rbp-70h] BYREF
  _DWORD v16[6]; // [rsp+80h] [rbp-58h] BYREF
  __int16 v17; // [rsp+98h] [rbp-40h]
  int v18; // [rsp+A0h] [rbp-38h]
  unsigned int v19; // [rsp+F0h] [rbp+18h] BYREF
  const wchar_t *v20; // [rsp+F8h] [rbp+20h] BYREF

  v4 = (__int64 *)sub_180002330();
  if ( v4 == nullptr )
    return 0;
  v20 = L"ShowUpwardComp";
  v5 = *v4;
  UserDefaultLCID = GetUserDefaultLCID();
  if ( (*(int (__fastcall **)(__int64 *, void *, const wchar_t **, __int64, LCID, unsigned int *))(v5 + 40))(
         v4,
         &unk_1800082F8,
         &v20,
         1,
         UserDefaultLCID,
         &v19) < 0 )
  {
    (*(void (__fastcall **)(__int64 *))(*v4 + 16))(v4);
    return 0;
  }
  Lo = 0;
  v13[1] = 0;
  v14 = 2;
  v13[0] = v16;
  v9 = 0;
  do
    VariantInit((VARIANTARG *)&v16[6 * v9++]);
  while ( v9 < (unsigned int)v14 );
  v17 = 3;
  v18 = a1;
  LOWORD(v16[0]) = 3;
  v16[2] = a2;
  COleVariant::COleVariant((COleVariant *)&pvarg, 0, 3u);
  v10 = *v4;
  v11 = GetUserDefaultLCID();
  LOWORD(v12) = 1;
  if ( (*(int (__fastcall **)(__int64 *, _QWORD, void *, _QWORD, int, _QWORD *, VARIANTARG *, _QWORD, _QWORD))(v10 + 48))(
         v4,
         v19,
         &unk_1800082F8,
         v11,
         v12,
         v13,
         &pvarg,
         0,
         0) >= 0 )
    Lo = pvarg.cyVal.Lo;
  (*(void (__fastcall **)(__int64 *))(*v4 + 16))(v4);
  VariantClear(&pvarg);
  return Lo;
}

/* ---- FUNC 000021D0 sub_1800021D0 ---- */
__int64 __fastcall sub_1800021D0(int a1)
{
  __int64 *v2; // rdi
  __int64 v3; // rbx
  LCID UserDefaultLCID; // eax
  unsigned int Lo; // esi
  unsigned int v7; // ebx
  __int64 v8; // rbx
  LCID v9; // eax
  int v10; // [rsp+20h] [rbp-98h]
  _QWORD v11[2]; // [rsp+50h] [rbp-68h] BYREF
  __int64 v12; // [rsp+60h] [rbp-58h]
  _DWORD v13[6]; // [rsp+68h] [rbp-50h] BYREF
  VARIANTARG pvarg; // [rsp+80h] [rbp-38h] BYREF
  unsigned int v15; // [rsp+C8h] [rbp+10h] BYREF
  const wchar_t *v16; // [rsp+D0h] [rbp+18h] BYREF

  v2 = (__int64 *)sub_180002330();
  if ( v2 == nullptr )
    return 0;
  v16 = L"ShowUserDefinedWizard";
  v3 = *v2;
  UserDefaultLCID = GetUserDefaultLCID();
  if ( (*(int (__fastcall **)(__int64 *, void *, const wchar_t **, __int64, LCID, unsigned int *))(v3 + 40))(
         v2,
         &unk_1800082F8,
         &v16,
         1,
         UserDefaultLCID,
         &v15) < 0 )
  {
    (*(void (__fastcall **)(__int64 *))(*v2 + 16))(v2);
    return 0;
  }
  Lo = 0;
  v11[1] = 0;
  v12 = 1;
  v11[0] = v13;
  v7 = 0;
  do
    VariantInit((VARIANTARG *)&v13[6 * v7++]);
  while ( v7 < (unsigned int)v12 );
  LOWORD(v13[0]) = 3;
  v13[2] = a1;
  COleVariant::COleVariant((COleVariant *)&pvarg, 0, 3u);
  v8 = *v2;
  v9 = GetUserDefaultLCID();
  LOWORD(v10) = 1;
  if ( (*(int (__fastcall **)(__int64 *, _QWORD, void *, _QWORD, int, _QWORD *, VARIANTARG *, _QWORD, _QWORD))(v8 + 48))(
         v2,
         v15,
         &unk_1800082F8,
         v9,
         v10,
         v11,
         &pvarg,
         0,
         0) >= 0 )
    Lo = pvarg.cyVal.Lo;
  (*(void (__fastcall **)(__int64 *))(*v2 + 16))(v2);
  VariantClear(&pvarg);
  return Lo;
}

/* ---- FUNC 00002330 sub_180002330 ---- */
LPVOID sub_180002330()
{
  WCHAR *v0; // rbx
  __int64 v2; // [rsp-20h] [rbp-B0h] BYREF
  WCHAR WideCharStr[40]; // [rsp+10h] [rbp-80h] BYREF
  LPVOID ppv; // [rsp+90h] [rbp+0h] BYREF
  CLSID clsid; // [rsp+98h] [rbp+8h] BYREF

  v0 = WideCharStr;
  if ( &v2 == (__int64 *)-48LL )
  {
    v0 = nullptr;
  }
  else
  {
    WideCharStr[0] = 0;
    if ( MultiByteToWideChar(0, 0, "AspenTech.AspenPlus.WpfFindComponent.FindComponentDriver.410", -1, WideCharStr, 61) == 0 )
      v0 = nullptr;
  }
  if ( CLSIDFromProgID(v0, &clsid) < 0 )
    return nullptr;
  ppv = nullptr;
  if ( CoCreateInstance(&clsid, nullptr, 1u, &riid, &ppv) < 0 )
    return nullptr;
  else
    return ppv;
}

/* ---- FUNC 00002400 sub_180002400 ---- */
__int64 sub_180002400()
{
  return (unsigned int)dword_18000B5B4;
}

/* ---- FUNC 00002410 sub_180002410 ---- */
LPVOID sub_180002410()
{
  WCHAR *v0; // rbx
  __int64 v2; // [rsp-20h] [rbp-90h] BYREF
  WCHAR WideCharStr[24]; // [rsp+10h] [rbp-60h] BYREF
  LPVOID ppv; // [rsp+70h] [rbp+0h] BYREF
  CLSID clsid; // [rsp+78h] [rbp+8h] BYREF

  v0 = WideCharStr;
  if ( &v2 == (__int64 *)-48LL )
  {
    v0 = nullptr;
  }
  else
  {
    WideCharStr[0] = 0;
    if ( MultiByteToWideChar(0, 0, "AspenTech.AspenPlus.WpfMMDialog.MessageBox.410", -1, WideCharStr, 47) == 0 )
      v0 = nullptr;
  }
  if ( CLSIDFromProgID(v0, &clsid) < 0 )
    return nullptr;
  ppv = nullptr;
  if ( CoCreateInstance(&clsid, nullptr, 1u, &riid, &ppv) < 0 )
    return nullptr;
  else
    return ppv;
}

/* ---- FUNC 000024E0 sub_1800024E0 ---- */
LPVOID sub_1800024E0()
{
  WCHAR *v0; // rbx
  __int64 v2; // [rsp-20h] [rbp-A0h] BYREF
  WCHAR WideCharStr[32]; // [rsp+10h] [rbp-70h] BYREF
  LPVOID ppv; // [rsp+80h] [rbp+0h] BYREF
  CLSID clsid; // [rsp+88h] [rbp+8h] BYREF

  v0 = WideCharStr;
  if ( &v2 == (__int64 *)-48LL )
  {
    v0 = nullptr;
  }
  else
  {
    WideCharStr[0] = 0;
    if ( MultiByteToWideChar(0, 0, "AspenTech.AspenPlus.WpfMMDialog.DialogDriver.410", -1, WideCharStr, 49) == 0 )
      v0 = nullptr;
  }
  if ( CLSIDFromProgID(v0, &clsid) < 0 )
    return nullptr;
  ppv = nullptr;
  if ( CoCreateInstance(&clsid, nullptr, 1u, &riid, &ppv) < 0 )
    return nullptr;
  else
    return ppv;
}

/* ---- FUNC 000025B0 sub_1800025B0 ---- */
// Hidden C++ exception states: #wind=1
__int64 __fastcall sub_1800025B0(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8,
        int a9)
{
  __int64 *v13; // rdi
  __int64 v14; // rbx
  LCID UserDefaultLCID; // eax
  unsigned int Lo; // esi
  unsigned int v18; // ebx
  __int64 v19; // rbx
  LCID v20; // eax
  int v21; // [rsp+20h] [rbp-E0h]
  unsigned int v22; // [rsp+50h] [rbp-B0h] BYREF
  _BYTE v23[4]; // [rsp+54h] [rbp-ACh] BYREF
  const wchar_t *v24; // [rsp+58h] [rbp-A8h] BYREF
  _QWORD v25[2]; // [rsp+60h] [rbp-A0h] BYREF
  __int64 v26; // [rsp+70h] [rbp-90h]
  VARIANTARG pvarg; // [rsp+78h] [rbp-88h] BYREF
  _BYTE v28[64]; // [rsp+90h] [rbp-70h] BYREF
  _DWORD v29[6]; // [rsp+D0h] [rbp-30h] BYREF
  __int16 v30; // [rsp+E8h] [rbp-18h]
  int v31; // [rsp+F0h] [rbp-10h]
  __int16 v32; // [rsp+100h] [rbp+0h]
  __int64 v33; // [rsp+108h] [rbp+8h]
  __int16 v34; // [rsp+118h] [rbp+18h]
  __int64 v35; // [rsp+120h] [rbp+20h]
  __int16 v36; // [rsp+130h] [rbp+30h]
  __int64 v37; // [rsp+138h] [rbp+38h]
  __int16 v38; // [rsp+148h] [rbp+48h]
  __int64 v39; // [rsp+150h] [rbp+50h]
  __int16 v40; // [rsp+160h] [rbp+60h]
  __int64 v41; // [rsp+168h] [rbp+68h]
  __int16 v42; // [rsp+178h] [rbp+78h]
  __int64 v43; // [rsp+180h] [rbp+80h]
  __int16 v44; // [rsp+190h] [rbp+90h]
  __int64 v45; // [rsp+198h] [rbp+98h]

  v13 = (__int64 *)sub_180002410();
  if ( v13 == nullptr )
    return 0;
  v24 = L"ShowOpenMessageBox";
  v14 = *v13;
  UserDefaultLCID = GetUserDefaultLCID();
  if ( (*(int (__fastcall **)(__int64 *, void *, const wchar_t **, __int64, LCID, unsigned int *))(v14 + 40))(
         v13,
         &unk_1800082F8,
         &v24,
         1,
         UserDefaultLCID,
         &v22) < 0 )
  {
    (*(void (__fastcall **)(__int64 *))(*v13 + 16))(v13);
    return 0;
  }
  Lo = 0;
  v25[1] = 0;
  v26 = 9;
  v25[0] = v29;
  v18 = 0;
  do
    VariantInit((VARIANTARG *)&v29[6 * v18++]);
  while ( v18 < (unsigned int)v26 );
  v44 = 8;
  v45 = a1;
  v42 = 8;
  v43 = a2;
  v40 = 8;
  v41 = a3;
  v38 = 8;
  v39 = a4;
  v36 = 8;
  v37 = a5;
  v34 = 8;
  v35 = a6;
  v32 = 8;
  v33 = a7;
  v30 = 3;
  v31 = a8;
  LOWORD(v29[0]) = 3;
  v29[2] = a9;
  COleVariant::COleVariant((COleVariant *)&pvarg, 0, 3u);
  v19 = *v13;
  v20 = GetUserDefaultLCID();
  LOWORD(v21) = 1;
  if ( (*(int (__fastcall **)(__int64 *, _QWORD, void *, _QWORD, int, _QWORD *, VARIANTARG *, _BYTE *, _BYTE *))(v19 + 48))(
         v13,
         v22,
         &unk_1800082F8,
         v20,
         v21,
         v25,
         &pvarg,
         v28,
         v23) >= 0 )
    Lo = pvarg.cyVal.Lo;
  (*(void (__fastcall **)(__int64 *))(*v13 + 16))(v13);
  VariantClear(&pvarg);
  return Lo;
}

/* ---- FUNC 000027B0 sub_1800027B0 ---- */
// Hidden C++ exception states: #wind=1
__int64 __fastcall sub_1800027B0(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8,
        int *a9,
        int a10)
{
  __int64 *v13; // rdi
  __int64 v14; // rbx
  LCID UserDefaultLCID; // eax
  unsigned int Lo; // esi
  unsigned int v18; // ebx
  __int64 v19; // rbx
  LCID v20; // eax
  int v21; // [rsp+20h] [rbp-E0h]
  int v22; // [rsp+50h] [rbp-B0h] BYREF
  unsigned int v23; // [rsp+54h] [rbp-ACh] BYREF
  char v24[8]; // [rsp+58h] [rbp-A8h] BYREF
  const wchar_t *v25; // [rsp+60h] [rbp-A0h] BYREF
  __int64 v26; // [rsp+68h] [rbp-98h]
  _QWORD v27[2]; // [rsp+70h] [rbp-90h] BYREF
  __int64 v28; // [rsp+80h] [rbp-80h]
  VARIANTARG pvarg; // [rsp+88h] [rbp-78h] BYREF
  char v30[64]; // [rsp+A0h] [rbp-60h] BYREF
  _DWORD v31[6]; // [rsp+E0h] [rbp-20h] BYREF
  __int16 v32; // [rsp+F8h] [rbp-8h]
  int *v33; // [rsp+100h] [rbp+0h]
  __int16 v34; // [rsp+110h] [rbp+10h]
  int v35; // [rsp+118h] [rbp+18h]
  __int16 v36; // [rsp+128h] [rbp+28h]
  __int64 v37; // [rsp+130h] [rbp+30h]
  __int16 v38; // [rsp+140h] [rbp+40h]
  __int64 v39; // [rsp+148h] [rbp+48h]
  __int16 v40; // [rsp+158h] [rbp+58h]
  __int64 v41; // [rsp+160h] [rbp+60h]
  __int16 v42; // [rsp+170h] [rbp+70h]
  __int64 v43; // [rsp+178h] [rbp+78h]
  __int16 v44; // [rsp+188h] [rbp+88h]
  __int64 v45; // [rsp+190h] [rbp+90h]
  __int16 v46; // [rsp+1A0h] [rbp+A0h]
  __int64 v47; // [rsp+1A8h] [rbp+A8h]
  __int16 v48; // [rsp+1B8h] [rbp+B8h]
  __int64 v49; // [rsp+1C0h] [rbp+C0h]

  v26 = a1;
  v13 = (__int64 *)sub_180002410();
  if ( v13 == nullptr )
    return 0;
  v25 = L"ShowOpenMessageBoxWithCheckBox";
  v14 = *v13;
  UserDefaultLCID = GetUserDefaultLCID();
  if ( (*(int (__fastcall **)(__int64 *, void *, const wchar_t **, __int64, LCID, unsigned int *))(v14 + 40))(
         v13,
         &unk_1800082F8,
         &v25,
         1,
         UserDefaultLCID,
         &v23) < 0 )
  {
    (*(void (__fastcall **)(__int64 *))(*v13 + 16))(v13);
    return 0;
  }
  Lo = 0;
  v27[1] = 0;
  v28 = 10;
  v27[0] = v31;
  v18 = 0;
  do
    VariantInit((VARIANTARG *)&v31[6 * v18++]);
  while ( v18 < (unsigned int)v28 );
  v22 = -1;
  v48 = 8;
  v49 = v26;
  v46 = 8;
  v47 = a2;
  v44 = 8;
  v45 = a3;
  v42 = 8;
  v43 = a4;
  v40 = 8;
  v41 = a5;
  v38 = 8;
  v39 = a6;
  v36 = 8;
  v37 = a7;
  v34 = 3;
  v35 = a8;
  v32 = 16406;
  v33 = &v22;
  LOWORD(v31[0]) = 3;
  v31[2] = a10;
  COleVariant::COleVariant((COleVariant *)&pvarg, 0, 3u);
  v19 = *v13;
  v20 = GetUserDefaultLCID();
  LOWORD(v21) = 1;
  if ( (*(int (__fastcall **)(__int64 *, _QWORD, void *, _QWORD, int, _QWORD *, VARIANTARG *, char *, char *))(v19 + 48))(
         v13,
         v23,
         &unk_1800082F8,
         v20,
         v21,
         v27,
         &pvarg,
         v30,
         v24) >= 0 )
  {
    Lo = pvarg.cyVal.Lo;
    *a9 = v22;
  }
  (*(void (__fastcall **)(__int64 *))(*v13 + 16))(v13);
  VariantClear(&pvarg);
  return Lo;
}

/* ---- FUNC 000029F0 sub_1800029F0 ---- */
// Hidden C++ exception states: #wind=1
__int64 sub_1800029F0()
{
  __int64 *v0; // rsi
  __int64 v1; // rbx
  LCID UserDefaultLCID; // eax
  unsigned int Lo; // edi
  __int64 v5; // rbx
  LCID v6; // eax
  int v7; // [rsp+20h] [rbp-78h]
  VARIANTARG pvarg; // [rsp+50h] [rbp-48h] BYREF
  __int128 v9; // [rsp+68h] [rbp-30h] BYREF
  __int64 v10; // [rsp+78h] [rbp-20h]
  unsigned int v11; // [rsp+A0h] [rbp+8h] BYREF
  const wchar_t *v12; // [rsp+A8h] [rbp+10h] BYREF

  v0 = (__int64 *)sub_1800024E0();
  if ( v0 == nullptr )
    return 0;
  v12 = L"ShowResultsInconsistentDlg";
  v1 = *v0;
  UserDefaultLCID = GetUserDefaultLCID();
  if ( (*(int (__fastcall **)(__int64 *, void *, const wchar_t **, __int64, LCID, unsigned int *))(v1 + 40))(
         v0,
         &unk_1800082F8,
         &v12,
         1,
         UserDefaultLCID,
         &v11) < 0 )
  {
    (*(void (__fastcall **)(__int64 *))(*v0 + 16))(v0);
    return 0;
  }
  v9 = 0;
  v10 = 0;
  SysAllocString(&psz);
  Lo = 0;
  COleVariant::COleVariant((COleVariant *)&pvarg, 0, 3u);
  v5 = *v0;
  v6 = GetUserDefaultLCID();
  LOWORD(v7) = 1;
  if ( (*(int (__fastcall **)(__int64 *, _QWORD, void *, _QWORD, int, __int128 *, VARIANTARG *, _QWORD, _QWORD))(v5 + 48))(
         v0,
         v11,
         &unk_1800082F8,
         v6,
         v7,
         &v9,
         &pvarg,
         0,
         0) >= 0 )
    Lo = pvarg.cyVal.Lo;
  (*(void (__fastcall **)(__int64 *))(*v0 + 16))(v0);
  VariantClear(&pvarg);
  return Lo;
}

/* ---- FUNC 00002B10 sub_180002B10 ---- */
// Hidden C++ exception states: #wind=3
__int64 __fastcall sub_180002B10(LPCCH lpMultiByteStr, LPCCH a2, int a3, int a4, int a5, int a6)
{
  __int64 *v9; // r15
  __int64 v10; // rbx
  LCID UserDefaultLCID; // eax
  unsigned int Lo; // r14d
  unsigned int v14; // ebx
  int cchWideChar; // ebx
  WCHAR *v16; // rax
  OLECHAR *v17; // rdi
  int v18; // esi
  WCHAR *v19; // rax
  OLECHAR *v20; // rbx
  __int64 v21; // rsi
  LCID v22; // eax
  int lpWideCharStr; // [rsp+20h] [rbp-E0h]
  unsigned int v25; // [rsp+54h] [rbp-ACh] BYREF
  OLECHAR *v26; // [rsp+58h] [rbp-A8h]
  OLECHAR *v27; // [rsp+60h] [rbp-A0h]
  char v28[8]; // [rsp+68h] [rbp-98h] BYREF
  const wchar_t *v29; // [rsp+70h] [rbp-90h] BYREF
  _QWORD v30[2]; // [rsp+78h] [rbp-88h] BYREF
  __int64 v31; // [rsp+88h] [rbp-78h]
  VARIANTARG pvarg; // [rsp+90h] [rbp-70h] BYREF
  char v33[64]; // [rsp+B0h] [rbp-50h] BYREF
  _DWORD v34[6]; // [rsp+F0h] [rbp-10h] BYREF
  __int16 v35; // [rsp+108h] [rbp+8h]
  int v36; // [rsp+110h] [rbp+10h]
  __int16 v37; // [rsp+120h] [rbp+20h]
  int v38; // [rsp+128h] [rbp+28h]
  __int16 v39; // [rsp+138h] [rbp+38h]
  int v40; // [rsp+140h] [rbp+40h]
  __int16 v41; // [rsp+150h] [rbp+50h]
  OLECHAR *v42; // [rsp+158h] [rbp+58h]
  __int16 v43; // [rsp+168h] [rbp+68h]
  OLECHAR *v44; // [rsp+170h] [rbp+70h]

  v9 = (__int64 *)sub_180002410();
  if ( v9 == nullptr )
    return 0;
  v29 = L"Show_3";
  v10 = *v9;
  UserDefaultLCID = GetUserDefaultLCID();
  if ( (*(int (__fastcall **)(__int64 *, void *, const wchar_t **, __int64, LCID, unsigned int *))(v10 + 40))(
         v9,
         &unk_1800082F8,
         &v29,
         1,
         UserDefaultLCID,
         &v25) < 0 )
  {
    (*(void (__fastcall **)(__int64 *))(*v9 + 16))(v9);
    return 0;
  }
  Lo = 0;
  v30[1] = 0;
  v31 = 6;
  v30[0] = v34;
  v14 = 0;
  do
    VariantInit((VARIANTARG *)&v34[6 * v14++]);
  while ( v14 < (unsigned int)v31 );
  if ( lpMultiByteStr == nullptr )
  {
    v17 = nullptr;
    v26 = nullptr;
    goto LABEL_13;
  }
  cchWideChar = MultiByteToWideChar(0, 0, lpMultiByteStr, -1, nullptr, 0);
  v16 = SysAllocStringLen(nullptr, cchWideChar - 1);
  v17 = v16;
  if ( v16 != nullptr && MultiByteToWideChar(0, 0, lpMultiByteStr, -1, v16, cchWideChar) != cchWideChar )
  {
    SysFreeString(v17);
LABEL_23:
    sub_180001060(-2147024882);
  }
  v26 = v17;
  if ( v17 == nullptr )
    goto LABEL_23;
LABEL_13:
  if ( a2 != nullptr )
  {
    v18 = MultiByteToWideChar(0, 0, a2, -1, nullptr, 0);
    v19 = SysAllocStringLen(nullptr, v18 - 1);
    v20 = v19;
    if ( v19 != nullptr && MultiByteToWideChar(0, 0, a2, -1, v19, v18) != v18 )
    {
      SysFreeString(v20);
    }
    else
    {
      v27 = v20;
      if ( v20 != nullptr )
        goto LABEL_19;
    }
    sub_180001060(-2147024882);
  }
  v20 = nullptr;
  v27 = nullptr;
LABEL_19:
  v43 = 8;
  v44 = v17;
  v41 = 8;
  v42 = v20;
  v39 = 3;
  v40 = a3;
  v37 = 3;
  v38 = a4;
  v35 = 3;
  v36 = a5;
  LOWORD(v34[0]) = 3;
  v34[2] = a6;
  COleVariant::COleVariant((COleVariant *)&pvarg, 0, 3u);
  v21 = *v9;
  v22 = GetUserDefaultLCID();
  LOWORD(lpWideCharStr) = 1;
  if ( (*(int (__fastcall **)(__int64 *, _QWORD, void *, _QWORD, int, _QWORD *, VARIANTARG *, char *, char *))(v21 + 48))(
         v9,
         v25,
         &unk_1800082F8,
         v22,
         lpWideCharStr,
         v30,
         &pvarg,
         v33,
         v28) >= 0 )
    Lo = pvarg.cyVal.Lo;
  (*(void (__fastcall **)(__int64 *))(*v9 + 16))(v9);
  VariantClear(&pvarg);
  SysFreeString(v20);
  SysFreeString(v17);
  return Lo;
}

/* ---- FUNC 00002E00 sub_180002E00 ---- */
// Hidden C++ exception states: #wind=1
__int64 __fastcall sub_180002E00(int *a1)
{
  __int64 *v2; // rdi
  __int64 v3; // rbx
  LCID UserDefaultLCID; // eax
  unsigned int Lo; // esi
  unsigned int v7; // ebx
  __int64 v8; // rbx
  LCID v9; // eax
  int v10; // [rsp+20h] [rbp-E8h]
  const wchar_t *v11; // [rsp+50h] [rbp-B8h] BYREF
  _QWORD v12[2]; // [rsp+58h] [rbp-B0h] BYREF
  __int64 v13; // [rsp+68h] [rbp-A0h]
  _QWORD v14[3]; // [rsp+70h] [rbp-98h] BYREF
  VARIANTARG pvarg; // [rsp+88h] [rbp-80h] BYREF
  char v16[104]; // [rsp+A0h] [rbp-68h] BYREF
  int v17; // [rsp+118h] [rbp+10h] BYREF
  unsigned int v18; // [rsp+120h] [rbp+18h] BYREF
  char v19; // [rsp+128h] [rbp+20h] BYREF

  v2 = (__int64 *)sub_1800024E0();
  if ( v2 == nullptr )
    return 0;
  v11 = L"ShowTPSARUpgradeDialog";
  v3 = *v2;
  UserDefaultLCID = GetUserDefaultLCID();
  if ( (*(int (__fastcall **)(__int64 *, void *, const wchar_t **, __int64, LCID, unsigned int *))(v3 + 40))(
         v2,
         &unk_1800082F8,
         &v11,
         1,
         UserDefaultLCID,
         &v18) < 0 )
  {
    (*(void (__fastcall **)(__int64 *))(*v2 + 16))(v2);
    return 0;
  }
  Lo = 0;
  v12[1] = 0;
  v13 = 1;
  v12[0] = v14;
  v7 = 0;
  do
    VariantInit((VARIANTARG *)&v14[3 * v7++]);
  while ( v7 < (unsigned int)v13 );
  v17 = -1;
  LOWORD(v14[0]) = 16387;
  v14[1] = &v17;
  COleVariant::COleVariant((COleVariant *)&pvarg, 0, 3u);
  v8 = *v2;
  v9 = GetUserDefaultLCID();
  LOWORD(v10) = 1;
  if ( (*(int (__fastcall **)(__int64 *, _QWORD, void *, _QWORD, int, _QWORD *, VARIANTARG *, char *, char *))(v8 + 48))(
         v2,
         v18,
         &unk_1800082F8,
         v9,
         v10,
         v12,
         &pvarg,
         v16,
         &v19) >= 0 )
  {
    Lo = pvarg.cyVal.Lo;
    *a1 = v17;
  }
  (*(void (__fastcall **)(__int64 *))(*v2 + 16))(v2);
  VariantClear(&pvarg);
  return Lo;
}

/* ---- FUNC 00002F90 sub_180002F90 ---- */
unsigned int *sub_180002F90()
{
  unsigned int *result; // rax

  result = (unsigned int *)GetGlobalPointer("DontShowUpward");
  if ( result != nullptr )
    return (unsigned int *)*result;
  return result;
}

/* ---- FUNC 00002FC0 DllMain ---- */
BOOL __stdcall DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
  if ( fdwReason == 1 )
  {
    AfxInitExtensionModule((struct AFX_EXTENSION_MODULE *)&unk_18000B5B8, hinstDLL);
    qword_18000B5A8 = (__int64)hinstDLL;
  }
  return true;
}

/* ---- FUNC 00002FF0 FindComponentInitExtDLL ---- */
struct AFX_MODULE_STATE *FindComponentInitExtDLL()
{
  CDynLinkLibrary *v0; // rax
  struct AFX_MODULE_STATE *result; // rax

  v0 = (CDynLinkLibrary *)operator new(0x80u);
  if ( v0 != nullptr )
    CDynLinkLibrary::CDynLinkLibrary(v0, (struct AFX_EXTENSION_MODULE *)&unk_18000B5B8, 0);
  result = AfxGetModuleState();
  qword_18000B5E0 = result;
  return result;
}

/* ---- FUNC 00003030 __local_stdio_printf_options ---- */
unsigned __int64 *__cdecl _local_stdio_printf_options()
{
  return (unsigned __int64 *)&`__local_stdio_printf_options'::`2'::_OptionsStorage;
}

/* ---- FUNC 00003040 gxAskReconcile ---- */
// Hidden C++ exception states: #wind=2
__int64 __fastcall gxAskReconcile(const CHAR *a1)
{
  __int64 v3; // rbx
  __int64 v4; // rdi
  struct CWinThread *Thread; // rax
  int cchWideChar; // esi
  WCHAR *lpWideCharStr; // rax
  OLECHAR *v8; // rbx
  OLECHAR *v9; // rbx
  LPCCH *v10; // rax
  unsigned int v11; // esi
  _BYTE v12[24]; // [rsp+30h] [rbp-18h] BYREF
  BSTR bstrString; // [rsp+58h] [rbp+10h] BYREF

  if ( qword_18000B5E0 == nullptr )
    return 1;
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2((AFX_MAINTAIN_STATE2 *)v12, qword_18000B5E0);
  v3 = qword_18000B5A8;
  v4 = *((_QWORD *)AfxGetModuleState() + 3);
  *((_QWORD *)AfxGetModuleState() + 3) = v3;
  Thread = AfxGetThread();
  if ( Thread == nullptr || (*(__int64 (__fastcall **)(struct CWinThread *))(*(_QWORD *)Thread + 248LL))(Thread) == 0 )
  {
    v11 = 1;
    goto LABEL_10;
  }
  cchWideChar = MultiByteToWideChar(0, 0, "Block ", -1, nullptr, 0);
  lpWideCharStr = SysAllocStringLen(nullptr, cchWideChar - 1);
  v8 = lpWideCharStr;
  if ( lpWideCharStr != nullptr && MultiByteToWideChar(0, 0, "Block ", -1, lpWideCharStr, cchWideChar) != cchWideChar )
  {
    SysFreeString(v8);
LABEL_12:
    sub_180001060(-2147024882);
  }
  bstrString = v8;
  if ( v8 == nullptr )
    goto LABEL_12;
  sub_1800011E0(&bstrString, a1);
  sub_1800011E0(&bstrString, " has errors or warnings. Do you wish to reconcile?");
  v9 = bstrString;
  v10 = (LPCCH *)ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>>>(
                   (ATL::CStringT<char, class StrTraitMFC_DLL<char, class ATL::ChTraitsCRT<char>>> *)&bstrString,
                   bstrString);
  v11 = sub_180002B10(*v10, "Reconcile blocks with errors or warnings?", 0, 14, 32, 2);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>>>((ATL::CStringT<char, class StrTraitMFC_DLL<char, class ATL::ChTraitsCRT<char>>> *)&bstrString);
  SysFreeString(v9);
LABEL_10:
  *((_QWORD *)AfxGetModuleState() + 3) = v4;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2((AFX_MAINTAIN_STATE2 *)v12);
  return v11;
}

/* ---- FUNC 000031D0 gxElectrolyteWizard ---- */
// Hidden C++ exception states: #wind=2
__int64 gxElectrolyteWizard()
{
  __int64 v0; // rdi
  __int64 v1; // rbx
  struct CWinThread *Thread; // rax
  int v3; // eax
  _BYTE v5[24]; // [rsp+20h] [rbp-18h] BYREF

  if ( qword_18000B5E0 != nullptr )
  {
    AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2((AFX_MAINTAIN_STATE2 *)v5, qword_18000B5E0);
    v0 = qword_18000B5A8;
    v1 = *((_QWORD *)AfxGetModuleState() + 3);
    *((_QWORD *)AfxGetModuleState() + 3) = v0;
    Thread = AfxGetThread();
    if ( Thread != nullptr && (*(__int64 (__fastcall **)(struct CWinThread *))(*(_QWORD *)Thread + 248LL))(Thread) != 0 )
    {
      dword_18000B5EC = 0;
      v3 = sub_180002400();
      sub_180001490(v3);
    }
    *((_QWORD *)AfxGetModuleState() + 3) = v1;
    AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2((AFX_MAINTAIN_STATE2 *)v5);
  }
  return 0;
}

/* ---- FUNC 00003260 gxFindTemplate ---- */
// Hidden C++ exception states: #wind=1
__int64 __fastcall gxFindTemplate(__int64 a1, _QWORD *a2)
{
  __int64 v5; // rdi
  __int64 v6; // rbx
  unsigned __int64 v7; // rax
  unsigned int v8; // edi
  _BYTE v9[16]; // [rsp+20h] [rbp-258h] BYREF
  _BYTE v10[328]; // [rsp+30h] [rbp-248h] BYREF
  __int64 v11; // [rsp+178h] [rbp-100h]

  if ( qword_18000B5E0 == nullptr )
    return 0;
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2((AFX_MAINTAIN_STATE2 *)v9, qword_18000B5E0);
  v5 = qword_18000B5A8;
  v6 = *((_QWORD *)AfxGetModuleState() + 3);
  *((_QWORD *)AfxGetModuleState() + 3) = v5;
  *a2 = 0;
  sub_1800043C0((__int64)v10, a1, nullptr);
  v7 = CMMDialog::DoModal((CMMDialog *)v10);
  *a2 = v11;
  v8 = 0xFFFFFFFF;
  if ( v7 <= 0x7FFFFFFF )
    v8 = v7;
  sub_180004460((CDialog *)v10);
  *((_QWORD *)AfxGetModuleState() + 3) = v6;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2((AFX_MAINTAIN_STATE2 *)v9);
  return v8;
}

/* ---- FUNC 00003330 gxOpen_message_box ---- */
__int64 __fastcall gxOpen_message_box(
        const CHAR *a1,
        const CHAR *a2,
        const CHAR *a3,
        const CHAR *a4,
        const CHAR *a5,
        const CHAR *a6,
        const CHAR *a7,
        int a8)
{
  return gxOpen_message_box2(a1, a2, a3, a4, a5, a6, a7, a8, a8);
}

/* ---- FUNC 00003380 gxOpen_message_box2 ---- */
__int64 __fastcall gxOpen_message_box2(
        const CHAR *a1,
        const CHAR *a2,
        const CHAR *a3,
        const CHAR *a4,
        const CHAR *a5,
        const CHAR *a6,
        const CHAR *lpMultiByteStr,
        unsigned int a8,
        int a9)
{
  int cchWideChar; // edi
  WCHAR *lpWideCharStr; // rax
  OLECHAR *v13; // r12
  int v14; // edi
  WCHAR *v15; // rax
  OLECHAR *v16; // r15
  int v17; // edi
  WCHAR *v18; // rax
  OLECHAR *v19; // r14
  int v20; // ebx
  WCHAR *v21; // rax
  OLECHAR *v22; // rbp
  int v23; // ebx
  WCHAR *v24; // rax
  OLECHAR *v25; // rsi
  int v26; // ebx
  WCHAR *v27; // rax
  OLECHAR *v28; // rdi
  OLECHAR *v29; // rbx
  unsigned int v30; // ebx
  int v31; // [rsp+50h] [rbp-58h]
  int v32; // [rsp+50h] [rbp-58h]
  _BYTE v33[24]; // [rsp+58h] [rbp-50h] BYREF

  if ( qword_18000B5E0 == nullptr )
    return 0;
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2((AFX_MAINTAIN_STATE2 *)v33, qword_18000B5E0);
  if ( (unsigned int)MMGetSuppress() == 0 )
  {
    if ( lpMultiByteStr != nullptr )
    {
      cchWideChar = MultiByteToWideChar(0, 0, lpMultiByteStr, -1, nullptr, 0);
      lpWideCharStr = SysAllocStringLen(nullptr, cchWideChar - 1);
      v13 = lpWideCharStr;
      if ( lpWideCharStr != nullptr
        && MultiByteToWideChar(0, 0, lpMultiByteStr, -1, lpWideCharStr, cchWideChar) != cchWideChar )
      {
        SysFreeString(v13);
        goto LABEL_58;
      }
      if ( v13 == nullptr )
        goto LABEL_58;
    }
    else
    {
      v13 = nullptr;
    }
    if ( a6 != nullptr )
    {
      v14 = MultiByteToWideChar(0, 0, a6, -1, nullptr, 0);
      v15 = SysAllocStringLen(nullptr, v14 - 1);
      v16 = v15;
      if ( v15 != nullptr && MultiByteToWideChar(0, 0, a6, -1, v15, v14) != v14 )
      {
        SysFreeString(v16);
        goto LABEL_58;
      }
      if ( v16 == nullptr )
        goto LABEL_58;
    }
    else
    {
      v16 = nullptr;
    }
    if ( a5 != nullptr )
    {
      v17 = MultiByteToWideChar(0, 0, a5, -1, nullptr, 0);
      v18 = SysAllocStringLen(nullptr, v17 - 1);
      v19 = v18;
      if ( v18 != nullptr && MultiByteToWideChar(0, 0, a5, -1, v18, v17) != v17 )
      {
        SysFreeString(v19);
        goto LABEL_58;
      }
      if ( v19 == nullptr )
        goto LABEL_58;
    }
    else
    {
      v19 = nullptr;
    }
    if ( a4 != nullptr )
    {
      v20 = MultiByteToWideChar(0, 0, a4, -1, nullptr, 0);
      v21 = SysAllocStringLen(nullptr, v20 - 1);
      v22 = v21;
      if ( v21 != nullptr && MultiByteToWideChar(0, 0, a4, -1, v21, v20) != v20 )
      {
        SysFreeString(v22);
        goto LABEL_58;
      }
      if ( v22 == nullptr )
        goto LABEL_58;
    }
    else
    {
      v22 = nullptr;
    }
    if ( a3 != nullptr )
    {
      v23 = MultiByteToWideChar(0, 0, a3, -1, nullptr, 0);
      v24 = SysAllocStringLen(nullptr, v23 - 1);
      v25 = v24;
      if ( v24 != nullptr && MultiByteToWideChar(0, 0, a3, -1, v24, v23) != v23 )
      {
        SysFreeString(v25);
        goto LABEL_58;
      }
      if ( v25 == nullptr )
        goto LABEL_58;
    }
    else
    {
      v25 = nullptr;
    }
    if ( a2 != nullptr )
    {
      v26 = MultiByteToWideChar(0, 0, a2, -1, nullptr, 0);
      v27 = SysAllocStringLen(nullptr, v26 - 1);
      v28 = v27;
      if ( v27 != nullptr && MultiByteToWideChar(0, 0, a2, -1, v27, v26) != v26 )
      {
        SysFreeString(v28);
        goto LABEL_58;
      }
      if ( v28 == nullptr )
        goto LABEL_58;
    }
    else
    {
      v28 = nullptr;
    }
    if ( a1 == nullptr )
    {
      v29 = nullptr;
LABEL_52:
      v32 = sub_1800025B0(
              (__int64)v29,
              (__int64)v28,
              (__int64)v25,
              (__int64)v22,
              (__int64)v19,
              (__int64)v16,
              (__int64)v13,
              a8,
              a9);
      SysFreeString(v29);
      SysFreeString(v28);
      SysFreeString(v25);
      SysFreeString(v22);
      SysFreeString(v19);
      SysFreeString(v16);
      SysFreeString(v13);
      v30 = v32;
      if ( v32 == -1 )
        v30 = 0;
      goto LABEL_56;
    }
    v31 = MultiByteToWideChar(0, 0, a1, -1, nullptr, 0);
    v29 = SysAllocStringLen(nullptr, v31 - 1);
    if ( v29 != nullptr && MultiByteToWideChar(0, 0, a1, -1, v29, v31) != v31 )
    {
      SysFreeString(v29);
      goto LABEL_58;
    }
    if ( v29 != nullptr )
      goto LABEL_52;
LABEL_58:
    sub_180001060(-2147024882);
  }
  v30 = a8;
LABEL_56:
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2((AFX_MAINTAIN_STATE2 *)v33);
  return v30;
}

/* ---- FUNC 00003850 gxOpen_message_box_wcheck ---- */
// Hidden C++ exception states: #wind=4
__int64 __fastcall gxOpen_message_box_wcheck(
        const CHAR *a1,
        const CHAR *a2,
        const CHAR *a3,
        const CHAR *a4,
        const CHAR *a5,
        const CHAR *a6,
        const CHAR *a7,
        int a8,
        _DWORD *a9)
{
  __int64 v11; // rdi
  __int64 v12; // rbx
  struct CWinThread *Thread; // rax
  __int64 v14; // rsi
  HWND ForegroundWindow; // rax
  struct CWnd *v16; // rax
  struct CWnd *v17; // rdi
  HWND v18; // rdx
  char *v19; // rax
  __int64 v20; // r14
  OLECHAR *v21; // r12
  OLECHAR *v22; // r15
  OLECHAR *v23; // r14
  OLECHAR *v24; // rbp
  OLECHAR *v25; // rsi
  OLECHAR *v26; // rdi
  __int64 *v27; // rax
  unsigned int v28; // edi
  HWND v29; // rcx
  int v30; // [rsp+60h] [rbp-88h] BYREF
  BSTR bstrString; // [rsp+68h] [rbp-80h] BYREF
  BSTR v32; // [rsp+70h] [rbp-78h] BYREF
  BSTR v33; // [rsp+78h] [rbp-70h] BYREF
  BSTR v34; // [rsp+80h] [rbp-68h] BYREF
  BSTR v35; // [rsp+88h] [rbp-60h] BYREF
  BSTR v36; // [rsp+90h] [rbp-58h] BYREF
  BSTR v37; // [rsp+98h] [rbp-50h] BYREF
  _BYTE v38[72]; // [rsp+A0h] [rbp-48h] BYREF

  if ( (unsigned int)MMGetSuppress() != 0 )
    return (unsigned int)a8;
  if ( qword_18000B5E0 == nullptr )
    return 0;
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2((AFX_MAINTAIN_STATE2 *)v38, qword_18000B5E0);
  v11 = qword_18000B5A8;
  v12 = *((_QWORD *)AfxGetModuleState() + 3);
  *((_QWORD *)AfxGetModuleState() + 3) = v11;
  Thread = AfxGetThread();
  if ( Thread == nullptr )
    goto LABEL_22;
  v14 = (*(__int64 (__fastcall **)(struct CWinThread *))(*(_QWORD *)Thread + 248LL))(Thread);
  if ( v14 == 0 )
    goto LABEL_22;
  ForegroundWindow = GetForegroundWindow();
  v16 = CWnd::FromHandle(ForegroundWindow);
  v17 = v16;
  if ( v16 == (struct CWnd *)v14 )
  {
    v20 = (__int64)v16 + 64;
  }
  else
  {
    if ( v16 != nullptr )
      v18 = *((HWND *)v16 + 8);
    else
      v18 = nullptr;
    v19 = (char *)v16 + 64;
    v20 = 64;
    if ( v17 != nullptr )
      v20 = (__int64)v19;
    if ( !IsChild(*(HWND *)(v14 + 64), v18) )
    {
      v30 = 1;
      goto LABEL_15;
    }
  }
  if ( v17 != nullptr )
    v29 = *(HWND *)v20;
  else
    v29 = nullptr;
  v30 = 1;
  SendMessageA(v29, 0x4D2u, 0, 0);
LABEL_15:
  v21 = *sub_1800010F0(&v37, a7);
  v22 = *sub_1800010F0(&v36, a6);
  v23 = *sub_1800010F0(&v35, a5);
  v24 = *sub_1800010F0(&v34, a4);
  v25 = *sub_1800010F0(&v33, a3);
  v26 = *sub_1800010F0(&v32, a2);
  v27 = (__int64 *)sub_1800010F0(&bstrString, a1);
  v28 = sub_1800027B0(
          *v27,
          (__int64)v26,
          (__int64)v25,
          (__int64)v24,
          (__int64)v23,
          (__int64)v22,
          (__int64)v21,
          a8,
          &v30,
          -1);
  SysFreeString(bstrString);
  SysFreeString(v32);
  SysFreeString(v33);
  SysFreeString(v34);
  SysFreeString(v35);
  SysFreeString(v36);
  SysFreeString(v37);
  if ( v28 == -1 )
  {
LABEL_22:
    v28 = 0;
    goto LABEL_23;
  }
  *a9 = v30;
LABEL_23:
  *((_QWORD *)AfxGetModuleState() + 3) = v12;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2((AFX_MAINTAIN_STATE2 *)v38);
  return v28;
}

/* ---- FUNC 00003B10 gxPure_component_param ---- */
// Hidden C++ exception states: #wind=4
__int64 __fastcall gxPure_component_param(char *Destination)
{
  __int64 v3; // rdi
  __int64 v4; // rbx
  struct CWinThread *Thread; // rax
  unsigned int v6; // edi
  CHAR *v7; // rax
  _BYTE v8[24]; // [rsp+20h] [rbp-18h] BYREF
  LPCWCH lpWideCharStr; // [rsp+48h] [rbp+10h] BYREF

  if ( qword_18000B5E0 == nullptr )
    return 0;
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2((AFX_MAINTAIN_STATE2 *)v8, qword_18000B5E0);
  v3 = qword_18000B5A8;
  v4 = *((_QWORD *)AfxGetModuleState() + 3);
  *((_QWORD *)AfxGetModuleState() + 3) = v3;
  Thread = AfxGetThread();
  if ( Thread != nullptr && (*(__int64 (__fastcall **)(struct CWinThread *))(*(_QWORD *)Thread + 248LL))(Thread) != 0 )
  {
    v6 = 0;
    lpWideCharStr = nullptr;
    if ( (unsigned int)sub_1800015F0((BSTR *)&lpWideCharStr) == 1 && lpWideCharStr != nullptr )
    {
      if ( Destination != nullptr )
      {
        v7 = sub_180005D10(lpWideCharStr);
        strncpy(Destination, v7, 0x20u);
      }
      v6 = 1;
    }
    else if ( Destination != nullptr )
    {
      *Destination = 0;
    }
  }
  else
  {
    v6 = 0;
  }
  *((_QWORD *)AfxGetModuleState() + 3) = v4;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2((AFX_MAINTAIN_STATE2 *)v8);
  return v6;
}

/* ---- FUNC 00003BF0 gxReorderComp ---- */
// Hidden C++ exception states: #wind=2
__int64 gxReorderComp()
{
  __int64 v0; // rbx
  __int64 v1; // rdi
  struct CWinThread *Thread; // rax
  BSTR v3; // rax
  OLECHAR *v4; // rbx
  _BYTE v6[24]; // [rsp+20h] [rbp-18h] BYREF

  if ( qword_18000B5E0 != nullptr )
  {
    AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2((AFX_MAINTAIN_STATE2 *)v6, qword_18000B5E0);
    v0 = qword_18000B5A8;
    v1 = *((_QWORD *)AfxGetModuleState() + 3);
    *((_QWORD *)AfxGetModuleState() + 3) = v0;
    Thread = AfxGetThread();
    if ( Thread != nullptr && (*(__int64 (__fastcall **)(struct CWinThread *))(*(_QWORD *)Thread + 248LL))(Thread) != 0 )
    {
      v3 = SysAllocString(L"ReorderComp");
      v4 = v3;
      if ( v3 == nullptr )
        sub_180001060(-2147024882);
      sub_180001320((__int64)v3);
      SysFreeString(v4);
    }
    *((_QWORD *)AfxGetModuleState() + 3) = v1;
    AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2((AFX_MAINTAIN_STATE2 *)v6);
  }
  return 0;
}

/* ---- FUNC 00003CA0 gxResults_inconsistent_dialog ---- */
__int64 gxResults_inconsistent_dialog()
{
  unsigned int v1; // ebx
  _BYTE v2[16]; // [rsp+20h] [rbp-18h] BYREF

  if ( qword_18000B5E0 == nullptr )
    return 0;
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2((AFX_MAINTAIN_STATE2 *)v2, qword_18000B5E0);
  if ( (unsigned int)MMGetSuppress() != 0 )
  {
    v1 = 0;
  }
  else
  {
    v1 = sub_1800029F0();
    if ( v1 == -1 )
      v1 = 0;
  }
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2((AFX_MAINTAIN_STATE2 *)v2);
  return v1;
}

/* ---- FUNC 00003D00 gxSFEAssistant ---- */
// Hidden C++ exception states: #wind=2
__int64 gxSFEAssistant()
{
  __int64 v0; // rdi
  __int64 v1; // rbx
  struct CWinThread *Thread; // rax
  int v3; // eax
  _BYTE v5[24]; // [rsp+20h] [rbp-18h] BYREF

  if ( qword_18000B5E0 != nullptr )
  {
    AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2((AFX_MAINTAIN_STATE2 *)v5, qword_18000B5E0);
    v0 = qword_18000B5A8;
    v1 = *((_QWORD *)AfxGetModuleState() + 3);
    *((_QWORD *)AfxGetModuleState() + 3) = v0;
    Thread = AfxGetThread();
    if ( Thread != nullptr && (*(__int64 (__fastcall **)(struct CWinThread *))(*(_QWORD *)Thread + 248LL))(Thread) != 0 )
    {
      v3 = sub_180002400();
      sub_180001780(v3);
    }
    *((_QWORD *)AfxGetModuleState() + 3) = v1;
    AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2((AFX_MAINTAIN_STATE2 *)v5);
  }
  return 0;
}

/* ---- FUNC 00003D90 gxSFEAssistantMain ---- */
__int64 gxSFEAssistantMain()
{
  __int64 v0; // rdi
  __int64 v1; // rbx
  struct CWinThread *Thread; // rax
  int v3; // eax
  _BYTE v5[24]; // [rsp+20h] [rbp-18h] BYREF

  if ( qword_18000B5E0 != nullptr )
  {
    AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2((AFX_MAINTAIN_STATE2 *)v5, qword_18000B5E0);
    v0 = qword_18000B5A8;
    v1 = *((_QWORD *)AfxGetModuleState() + 3);
    *((_QWORD *)AfxGetModuleState() + 3) = v0;
    Thread = AfxGetThread();
    if ( Thread != nullptr && (*(__int64 (__fastcall **)(struct CWinThread *))(*(_QWORD *)Thread + 248LL))(Thread) != 0 )
    {
      v3 = sub_180002400();
      sub_1800018E0(v3);
    }
    *((_QWORD *)AfxGetModuleState() + 3) = v1;
    AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2((AFX_MAINTAIN_STATE2 *)v5);
  }
  return 0;
}

/* ---- FUNC 00003E20 gxSearchComponents ---- */
// Hidden C++ exception states: #wind=2
__int64 __fastcall gxSearchComponents(__int64 a1, int a2, const CHAR *a3)
{
  __int64 v6; // rbx
  __int64 v7; // rdi
  struct CWinThread *Thread; // rax
  unsigned int v9; // esi
  OLECHAR *v10; // rbx
  __int64 *v11; // rax
  _BYTE v12[40]; // [rsp+20h] [rbp-28h] BYREF
  BSTR bstrString; // [rsp+68h] [rbp+20h] BYREF

  if ( qword_18000B5E0 == nullptr )
    return 0;
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2((AFX_MAINTAIN_STATE2 *)v12, qword_18000B5E0);
  v6 = qword_18000B5A8;
  v7 = *((_QWORD *)AfxGetModuleState() + 3);
  *((_QWORD *)AfxGetModuleState() + 3) = v6;
  Thread = AfxGetThread();
  if ( Thread != nullptr && (*(__int64 (__fastcall **)(struct CWinThread *))(*(_QWORD *)Thread + 248LL))(Thread) != 0 )
  {
    v9 = 0;
    if ( (unsigned int)MMGetSuppress() == 0 )
    {
      if ( a2 >= 0 )
        v9 = a2;
      v10 = SysAllocString(L"Happ");
      if ( v10 == nullptr )
        sub_180001060(-2147024882);
      v11 = (__int64 *)sub_1800010F0(&bstrString, a3);
      v9 = sub_180001A40((__int64)v10, v9, *v11);
      SysFreeString(v10);
      SysFreeString(bstrString);
    }
  }
  else
  {
    v9 = 0;
  }
  *((_QWORD *)AfxGetModuleState() + 3) = v7;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2((AFX_MAINTAIN_STATE2 *)v12);
  return v9;
}

/* ---- FUNC 00003F20 gxSearchProperty ---- */
// Hidden C++ exception states: #wind=2
__int64 __fastcall gxSearchProperty(LPCCH lpMultiByteStr)
{
  __int64 v2; // rbx
  __int64 v3; // rdi
  struct CWinThread *Thread; // rax
  OLECHAR *v5; // rbx
  int cchWideChar; // ebp
  WCHAR *lpWideCharStr; // rax
  _BYTE v9[24]; // [rsp+30h] [rbp-18h] BYREF

  if ( qword_18000B5E0 != nullptr )
  {
    AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2((AFX_MAINTAIN_STATE2 *)v9, qword_18000B5E0);
    v2 = qword_18000B5A8;
    v3 = *((_QWORD *)AfxGetModuleState() + 3);
    *((_QWORD *)AfxGetModuleState() + 3) = v2;
    Thread = AfxGetThread();
    if ( Thread != nullptr && (*(__int64 (__fastcall **)(struct CWinThread *))(*(_QWORD *)Thread + 248LL))(Thread) != 0 )
    {
      v5 = nullptr;
      if ( lpMultiByteStr != nullptr )
      {
        cchWideChar = MultiByteToWideChar(0, 0, lpMultiByteStr, -1, nullptr, 0);
        lpWideCharStr = SysAllocStringLen(nullptr, cchWideChar - 1);
        v5 = lpWideCharStr;
        if ( lpWideCharStr != nullptr
          && MultiByteToWideChar(0, 0, lpMultiByteStr, -1, lpWideCharStr, cchWideChar) != cchWideChar )
        {
          SysFreeString(v5);
        }
        else if ( v5 != nullptr )
        {
          goto LABEL_8;
        }
        sub_180001060(-2147024882);
      }
LABEL_8:
      sub_180001C00((__int64)v5);
      SysFreeString(v5);
    }
    *((_QWORD *)AfxGetModuleState() + 3) = v3;
    AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2((AFX_MAINTAIN_STATE2 *)v9);
  }
  return 0;
}

/* ---- FUNC 00004030 gxSetApedFlag ---- */
void __fastcall gxSetApedFlag(int a1)
{
  dword_18000B5B4 = a1;
}

/* ---- FUNC 00004040 gxShowTPSARUpgradeDialog ---- */
__int64 __fastcall gxShowTPSARUpgradeDialog(_DWORD *a1)
{
  __int64 result; // rax
  int v3; // [rsp+38h] [rbp+10h] BYREF

  if ( (unsigned int)MMGetSuppress() != 0 )
    return 0;
  v3 = 0;
  result = sub_180002E00(&v3);
  *a1 = v3;
  return result;
}

/* ---- FUNC 00004080 gxUpgradeRetired ---- */
// Hidden C++ exception states: #wind=3
__int64 __fastcall gxUpgradeRetired(_DWORD *a1)
{
  __int64 v3; // rdi
  __int64 v4; // rbx
  struct CWinThread *Thread; // rax
  unsigned int v6; // esi
  DWORD TickCount; // edi
  DWORD v8; // eax
  DWORD v9; // edi
  int v10; // eax
  struct AFX_MODULE_STATE *ModuleState; // rax
  DWORD v12; // eax
  int v13; // [rsp+20h] [rbp-438h] BYREF
  CHAR v14[24]; // [rsp+28h] [rbp-430h] BYREF
  CHAR OutputString[1024]; // [rsp+40h] [rbp-418h] BYREF

  if ( qword_18000B5E0 == nullptr )
    return 0;
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2((AFX_MAINTAIN_STATE2 *)v14, qword_18000B5E0);
  v3 = qword_18000B5A8;
  v4 = *((_QWORD *)AfxGetModuleState() + 3);
  *((_QWORD *)AfxGetModuleState() + 3) = v3;
  Thread = AfxGetThread();
  if ( Thread != nullptr && (*(__int64 (__fastcall **)(struct CWinThread *))(*(_QWORD *)Thread + 248LL))(Thread) != 0 )
  {
    if ( (unsigned int)sub_180002F90() != 0 )
    {
      v6 = 1;
      if ( a1 != nullptr )
        *a1 = 1;
    }
    else
    {
      TickCount = GetTickCount();
      v8 = GetTickCount();
      sub_180004360(
        OutputString,
        "\n+++++++++++++ CComPtr<AspenTech_AspenPlus_WpfFindComponent::IFindComponentDriver>: %d\n",
        v8 - TickCount);
      OutputDebugStringA(OutputString);
      v9 = GetTickCount();
      v10 = sub_180002400();
      v13 = 0;
      sub_180001D70(v10, &v13);
      *a1 = v13;
      ModuleState = AfxGetModuleState();
      CCmdTarget::RestoreWaitCursor(*((CCmdTarget **)ModuleState + 1));
      v12 = GetTickCount();
      sub_180004360(OutputString, "\n+++++++++++++ ShowUpgradeRetired %d\n", v12 - v9);
      OutputDebugStringA(OutputString);
      GetTickCount();
      v6 = 1;
    }
  }
  else
  {
    v6 = 0;
  }
  *((_QWORD *)AfxGetModuleState() + 3) = v4;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2((AFX_MAINTAIN_STATE2 *)v14);
  return v6;
}

/* ---- FUNC 00004200 gxUpwardComp ---- */
__int64 __fastcall gxUpwardComp(int a1, int a2)
{
  unsigned int *GlobalPointer; // rax
  __int64 result; // rax

  if ( (unsigned int)sub_180002F90() != 0 )
  {
    GlobalPointer = (unsigned int *)GetGlobalPointer("UpwardOption");
    if ( GlobalPointer != nullptr )
    {
      result = *GlobalPointer;
      if ( (_DWORD)result == 0 )
        return 0xFFFFFFFFLL;
    }
    else
    {
      return 0xFFFFFFFFLL;
    }
  }
  else
  {
    dword_18000B5E8 = a2;
    return sub_180002060(a2, a1);
  }
  return result;
}

/* ---- FUNC 00004270 gxUpwardComp1 ---- */
__int64 __fastcall gxUpwardComp1(int a1)
{
  unsigned int *GlobalPointer; // rax
  __int64 result; // rax

  if ( (unsigned int)sub_180002F90() != 0 )
  {
    GlobalPointer = (unsigned int *)GetGlobalPointer("UpwardOption");
    if ( GlobalPointer != nullptr )
    {
      result = *GlobalPointer;
      if ( (_DWORD)result == 0 )
        return 0xFFFFFFFFLL;
    }
    else
    {
      return 0xFFFFFFFFLL;
    }
  }
  else
  {
    dword_18000B5E8 = a1;
    return sub_180001F00(a1);
  }
  return result;
}

/* ---- FUNC 000042D0 gxUserDefWizard ---- */
// Hidden C++ exception states: #wind=2
__int64 __fastcall gxUserDefWizard(int a1)
{
  __int64 v2; // rdi
  __int64 v3; // rbx
  struct CWinThread *Thread; // rax
  _BYTE v6[24]; // [rsp+20h] [rbp-18h] BYREF

  if ( qword_18000B5E0 != nullptr )
  {
    AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2((AFX_MAINTAIN_STATE2 *)v6, qword_18000B5E0);
    v2 = qword_18000B5A8;
    v3 = *((_QWORD *)AfxGetModuleState() + 3);
    *((_QWORD *)AfxGetModuleState() + 3) = v2;
    Thread = AfxGetThread();
    if ( Thread != nullptr && (*(__int64 (__fastcall **)(struct CWinThread *))(*(_QWORD *)Thread + 248LL))(Thread) != 0 )
      sub_1800021D0(a1);
    *((_QWORD *)AfxGetModuleState() + 3) = v3;
    AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2((AFX_MAINTAIN_STATE2 *)v6);
  }
  return 0;
}

/* ---- FUNC 00004360 sub_180004360 ---- */
int sub_180004360(char *Buffer, char *Format, ...)
{
  unsigned __int64 *v4; // rax
  int result; // eax
  va_list va; // [rsp+60h] [rbp+18h] BYREF

  va_start(va, Format);
  v4 = _local_stdio_printf_options();
  result = _stdio_common_vsprintf(*v4 | 1, Buffer, 0xFFFFFFFFFFFFFFFFuLL, Format, nullptr, va);
  if ( result < 0 )
    return -1;
  return result;
}

/* ---- FUNC 000043C0 sub_1800043C0 ---- */
// Hidden C++ exception states: #wind=2
__int64 __fastcall sub_1800043C0(__int64 a1, __int64 a2, struct CWnd *a3)
{
  CMMDialog::CMMDialog((CMMDialog *)a1, 0x3170u, a3);
  *(_QWORD *)a1 = &CFindTemplateDlg::`vftable';
  CWnd::CWnd((CWnd *)(a1 + 336));
  *(_QWORD *)(a1 + 336) = &CTreeCtrl::`vftable';
  *(_DWORD *)(a1 + 304) = 2;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>>>::operator=(
    (ATL::CStringT<char, class StrTraitMFC_DLL<char, class ATL::ChTraitsCRT<char>>> *)(a1 + 312),
    "Select Template dialog is not shown when dialogs are suppressed.");
  *(_QWORD *)(a1 + 328) = 0;
  *(_QWORD *)(a1 + 568) = a2;
  if ( a2 != 0 )
    (*(void (__fastcall **)(__int64))(*(_QWORD *)a2 + 8LL))(a2);
  return a1;
}

/* ---- FUNC 00004460 sub_180004460 ---- */
void __fastcall sub_180004460(CDialog *this)
{
  __int64 v2; // rcx

  *(_QWORD *)this = &CFindTemplateDlg::`vftable';
  v2 = *((_QWORD *)this + 71);
  if ( v2 != 0 )
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v2 + 16LL))(v2);
  CTreeCtrl::~CTreeCtrl((CDialog *)((char *)this + 336));
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>>>((CDialog *)((char *)this + 320));
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>>>((CDialog *)((char *)this + 312));
  CDialog::~CDialog(this);
}

/* ---- FUNC 000044C0 sub_1800044C0 ---- */
void __fastcall sub_1800044C0(CDialog *this)
{
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>>>((CDialog *)((char *)this + 320));
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>>>((CDialog *)((char *)this + 312));
  CDialog::~CDialog(this);
}

/* ---- FUNC 000044F0 sub_1800044F0 ---- */
CDialog *__fastcall sub_1800044F0(CDialog *a1, char a2)
{
  sub_180004460(a1);
  if ( (a2 & 1) == 0 || (a2 & 4) != 0 )
    return a1;
  operator delete(a1);
  return a1;
}

/* ---- FUNC 00004540 sub_180004540 ---- */
CTreeCtrl *__fastcall sub_180004540(CTreeCtrl *a1, char a2)
{
  CTreeCtrl::~CTreeCtrl(a1);
  if ( (a2 & 1) == 0 || (a2 & 4) != 0 )
    return a1;
  operator delete(a1);
  return a1;
}

/* ---- FUNC 00004590 sub_180004590 ---- */
BOOL __fastcall sub_180004590(__int64 a1)
{
  return EnableWindow(*(HWND *)(a1 + 64), false);
}

/* ---- FUNC 000045A0 sub_1800045A0 ---- */
int __fastcall sub_1800045A0(CDialog *a1, unsigned __int16 a2, CWnd *a3)
{
  return CDialog::Create(a1, (const char *)a2, a3);
}

/* ---- FUNC 000045B0 sub_1800045B0 ---- */
void __fastcall sub_1800045B0(__int64 a1, struct CDataExchange *a2)
{
  DDX_Control(a2, 12657, (struct CWnd *)(a1 + 336));
}

/* ---- FUNC 000045D0 sub_1800045D0 ---- */
BOOL __fastcall sub_1800045D0(__int64 a1)
{
  return EnableWindow(*(HWND *)(a1 + 64), true);
}

/* ---- FUNC 000045E0 sub_1800045E0 ---- */
// attributes: thunk
__int64 sub_1800045E0()
{
  return sub_1800045F0();
}

/* ---- FUNC 000045F0 sub_1800045F0 ---- */
const struct AFX_MSGMAP *(**sub_1800045F0())()
{
  return &off_1800082A0;
}

/* ---- FUNC 00004600 sub_180004600 ---- */
void __fastcall sub_180004600(CDialog *this)
{
  __int64 v2; // rcx

  v2 = *((_QWORD *)this + 41);
  if ( v2 != 0 )
  {
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v2 + 16LL))(v2);
    *((_QWORD *)this + 41) = 0;
  }
  CDialog::OnCancel(this);
}

/* ---- FUNC 00004640 sub_180004640 ---- */
void __fastcall sub_180004640(__int64 a1, __int64 a2, _QWORD *a3)
{
  *a3 = 0;
}

/* ---- FUNC 00004650 sub_180004650 ---- */
__int64 __fastcall sub_180004650(__int64 a1, __int64 a2, _QWORD *a3)
{
  __int64 v3; // rcx
  __int64 result; // rax

  v3 = *(_QWORD *)(a2 + 80);
  if ( v3 != 0 )
  {
    result = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v3 + 16LL))(v3);
    *a3 = 0;
  }
  else
  {
    *a3 = 0;
  }
  return result;
}

/* ---- FUNC 00004690 sub_180004690 ---- */
__int64 __fastcall sub_180004690(HWND *this)
{
  CWnd *DlgItem; // rax
  LPARAM v3; // rbx
  int v4; // r13d
  int v5; // r12d
  struct IAUserModelLibrary *Library; // r14
  __int64 v7; // rax
  int (__fastcall **v8)(struct IAUserModelLibrary *, void *, __int64 *); // rax
  _TREEITEM *v9; // rsi
  _TREEITEM *inserted; // rax
  _TREEITEM *v11; // rax
  int v13; // [rsp+50h] [rbp-49h] BYREF
  int v14; // [rsp+54h] [rbp-45h] BYREF
  __int64 v15; // [rsp+58h] [rbp-41h] BYREF
  __int64 v16; // [rsp+60h] [rbp-39h] BYREF
  __int64 v17; // [rsp+68h] [rbp-31h] BYREF
  __int64 v18; // [rsp+70h] [rbp-29h] BYREF
  __int64 v19; // [rsp+78h] [rbp-21h] BYREF
  char v20[64]; // [rsp+80h] [rbp-19h] BYREF

  CDialog::OnInitDialog((CDialog *)this);
  DlgItem = CWnd::GetDlgItem((CWnd *)this, 1);
  CWnd::EnableWindow(DlgItem, 0);
  v3 = 0;
  v4 = 1;
  if ( *(this + 71) == nullptr )
    v4 = CApwnLibraries::CountLibraries(g_pApwnLibs);
  v5 = 0;
  if ( v4 > 0 )
  {
    while ( 1 )
    {
      Library = (struct IAUserModelLibrary *)*(this + 71);
      if ( Library != nullptr )
        break;
      Library = CApwnLibraries::GetLibrary(g_pApwnLibs, v5);
      if ( Library != nullptr )
        goto LABEL_7;
LABEL_22:
      if ( ++v5 >= v4 )
      {
        if ( v3 != 0 )
          SendMessageA(*(this + 50), 0x1114u, 0, v3);
        return 1;
      }
    }
    (*(void (__fastcall **)(_QWORD))(*(_QWORD *)Library + 8LL))(*(this + 71));
LABEL_7:
    v7 = *(_QWORD *)Library;
    v13 = 1;
    (*(void (__fastcall **)(struct IAUserModelLibrary *, int *))(v7 + 48))(Library, &v13);
    if ( v13 == 0 )
    {
      (*(void (__fastcall **)(struct IAUserModelLibrary *, char *, __int64))(*(_QWORD *)Library + 56LL))(
        Library,
        v20,
        64);
      v8 = *(int (__fastcall ***)(struct IAUserModelLibrary *, void *, __int64 *))Library;
      v18 = 0;
      v9 = nullptr;
      if ( (*v8)(Library, &unk_180007700, &v18) >= 0 )
      {
        v16 = 0;
        if ( (*(int (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v18 + 64LL))(v18, &v16) >= 0 )
        {
          while ( (*(unsigned int (__fastcall **)(__int64, __int64, __int64 *))(*(_QWORD *)v16 + 24LL))(v16, 1, &v15) == 0 )
          {
            v17 = 0;
            if ( (**(int (__fastcall ***)(__int64, void *, __int64 *))v15)(v15, &unk_180007710, &v17) >= 0 )
            {
              v14 = 0;
              (*(void (__fastcall **)(__int64, int *))(*(_QWORD *)v17 + 32LL))(v17, &v14);
              (*(void (__fastcall **)(__int64))(*(_QWORD *)v17 + 16LL))(v17);
              if ( v14 != 0 )
              {
                if ( v9 == nullptr )
                {
                  inserted = CTreeCtrl::InsertItem(
                               (CTreeCtrl *)(this + 42),
                               1u,
                               v20,
                               0,
                               0,
                               0,
                               0,
                               0,
                               (_TREEITEM *)0xFFFFFFFFFFFF0000LL,
                               (_TREEITEM *)0xFFFFFFFFFFFF0002LL);
                  v9 = inserted;
                  if ( v3 == 0 )
                    v3 = (LPARAM)inserted;
                }
                (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v15 + 24LL))(v15, v20, 64);
                v19 = 0;
                (**(void (__fastcall ***)(__int64, void *, __int64 *))v15)(v15, &unk_180007720, &v19);
                v11 = CTreeCtrl::InsertItem(
                        (CTreeCtrl *)(this + 42),
                        1u,
                        v20,
                        0,
                        0,
                        0,
                        0,
                        0,
                        v9,
                        (_TREEITEM *)0xFFFFFFFFFFFF0002LL);
                CTreeCtrl::SetItem((CTreeCtrl *)(this + 42), v11, 4u, nullptr, 0, 0, 0, 0, v19);
              }
            }
            (*(void (__fastcall **)(__int64))(*(_QWORD *)v15 + 16LL))(v15);
          }
          (*(void (__fastcall **)(__int64))(*(_QWORD *)v16 + 16LL))(v16);
        }
        (*(void (__fastcall **)(__int64))(*(_QWORD *)v18 + 16LL))(v18);
        if ( v9 != nullptr )
          SendMessageA(*(this + 50), 0x1102u, 2u, (LPARAM)v9);
      }
    }
    (*(void (__fastcall **)(struct IAUserModelLibrary *))(*(_QWORD *)Library + 16LL))(Library);
    goto LABEL_22;
  }
  return 1;
}

/* ---- FUNC 000049D0 sub_1800049D0 ---- */
int __fastcall sub_1800049D0(CWnd *this, __int64 a2, _QWORD *a3)
{
  __int64 v5; // rcx
  __int64 v7; // rcx
  int v8; // edi
  CWnd *DlgItem; // rax
  int result; // eax

  v5 = *((_QWORD *)this + 41);
  if ( v5 != 0 )
  {
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v5 + 16LL))(v5);
    *((_QWORD *)this + 41) = 0;
  }
  v7 = *(_QWORD *)(a2 + 136);
  *((_QWORD *)this + 41) = v7;
  if ( v7 != 0 )
  {
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v7 + 8LL))(v7);
    v8 = 1;
  }
  else
  {
    v8 = 0;
  }
  DlgItem = CWnd::GetDlgItem(this, 1);
  result = CWnd::EnableWindow(DlgItem, v8);
  *a3 = 0;
  return result;
}

/* ---- FUNC 00004A60 gxDelStruct ---- */
__int64 gxDelStruct()
{
  if ( qword_18000B6F8 != nullptr && qword_18000B618 != 0 )
    qword_18000B6F8();
  return 0;
}

/* ---- FUNC 00004A85 MMGetSuppress ---- */
// attributes: thunk
__int64 MMGetSuppress(void)
{
  return __imp_MMGetSuppress();
}

/* ---- FUNC 00004A8B ?DoModal@CMMDialog@@UEAA_JXZ ---- */
// attributes: thunk
__int64 __fastcall CMMDialog::DoModal(CMMDialog *this)
{
  return __imp_?DoModal@CMMDialog@@UEAA_JXZ(this);
}

/* ---- FUNC 00004A91 GetGlobalPointer ---- */
// attributes: thunk
__int64 __fastcall GetGlobalPointer(__int64 a1)
{
  return __imp_GetGlobalPointer(a1);
}

/* ---- FUNC 00004A97 ??0CMMDialog@@QEAA@IPEAVCWnd@@@Z ---- */
// attributes: thunk
CMMDialog *__fastcall CMMDialog::CMMDialog(CMMDialog *this, unsigned int a2, struct CWnd *a3)
{
  return __imp_??0CMMDialog@@QEAA@IPEAVCWnd@@@Z(this, a2, a3);
}

/* ---- FUNC 00004A9D ?InitSuppressed@CMMDialog@@MEAAXXZ ---- */
// attributes: thunk
void __fastcall CMMDialog::InitSuppressed(CMMDialog *this)
{
  __imp_?InitSuppressed@CMMDialog@@MEAAXXZ(this);
}

/* ---- FUNC 00004AA3 ?AfxThrowMemoryException@@YAXXZ ---- */
// attributes: thunk
void __noreturn AfxThrowMemoryException()
{
  __imp_?AfxThrowMemoryException@@YAXXZ();
}

/* ---- FUNC 00004AA9 ?AfxThrowOleException@@YAXJ@Z ---- */
// attributes: thunk
void __fastcall __noreturn AfxThrowOleException(int a1)
{
  __imp_?AfxThrowOleException@@YAXJ@Z(a1);
}

/* ---- FUNC 00004AAF ??3@YAXPEAX@Z ---- */
// attributes: thunk
void __fastcall operator delete(void *a1)
{
  __imp_??3@YAXPEAX@Z(a1);
}

/* ---- FUNC 00004AB5 ??2@YAPEAX_K@Z ---- */
// attributes: thunk
void *__fastcall operator new(unsigned __int64 a1)
{
  return __imp_??2@YAPEAX_K@Z(a1);
}

/* ---- FUNC 00004ABB ??_V@YAXPEAX@Z ---- */
// attributes: thunk
void __fastcall operator delete[](void *a1)
{
  __imp_??_V@YAXPEAX@Z(a1);
}

/* ---- FUNC 00004AC1 ?Delete@CException@@QEAAXXZ ---- */
// attributes: thunk
void __fastcall CException::Delete(CException *this)
{
  __imp_?Delete@CException@@QEAAXXZ(this);
}

/* ---- FUNC 00004AC7 ?AfxGetModuleState@@YAPEAVAFX_MODULE_STATE@@XZ ---- */
// attributes: thunk
struct AFX_MODULE_STATE *AfxGetModuleState()
{
  return __imp_?AfxGetModuleState@@YAPEAVAFX_MODULE_STATE@@XZ();
}

/* ---- FUNC 00004ACD ??0AFX_MAINTAIN_STATE2@@QEAA@PEAVAFX_MODULE_STATE@@@Z ---- */
// attributes: thunk
AFX_MAINTAIN_STATE2 *__fastcall AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(
        AFX_MAINTAIN_STATE2 *this,
        struct AFX_MODULE_STATE *a2)
{
  return __imp_??0AFX_MAINTAIN_STATE2@@QEAA@PEAVAFX_MODULE_STATE@@@Z(this, a2);
}

/* ---- FUNC 00004AD3 ??1AFX_MAINTAIN_STATE2@@QEAA@XZ ---- */
// attributes: thunk
void __fastcall AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(AFX_MAINTAIN_STATE2 *this)
{
  __imp_??1AFX_MAINTAIN_STATE2@@QEAA@XZ(this);
}

/* ---- FUNC 00004AD9 ?RestoreWaitCursor@CCmdTarget@@QEAAXXZ ---- */
// attributes: thunk
void __fastcall CCmdTarget::RestoreWaitCursor(CCmdTarget *this)
{
  __imp_?RestoreWaitCursor@CCmdTarget@@QEAAXXZ(this);
}

/* ---- FUNC 00004ADF ?FromHandle@CWnd@@SAPEAV1@PEAUHWND__@@@Z ---- */
// attributes: thunk
static struct CWnd *__fastcall CWnd::FromHandle(HWND a1)
{
  return __imp_?FromHandle@CWnd@@SAPEAV1@PEAUHWND__@@@Z(a1);
}

/* ---- FUNC 00004AE5 ?AfxGetThread@@YAPEAVCWinThread@@XZ ---- */
// attributes: thunk
struct CWinThread *AfxGetThread()
{
  return __imp_?AfxGetThread@@YAPEAVCWinThread@@XZ();
}

/* ---- FUNC 00004AEB ??0CDynLinkLibrary@@QEAA@AEAUAFX_EXTENSION_MODULE@@H@Z ---- */
// attributes: thunk
CDynLinkLibrary *__fastcall CDynLinkLibrary::CDynLinkLibrary(
        CDynLinkLibrary *this,
        struct AFX_EXTENSION_MODULE *a2,
        int a3)
{
  return __imp_??0CDynLinkLibrary@@QEAA@AEAUAFX_EXTENSION_MODULE@@H@Z(this, a2, a3);
}

/* ---- FUNC 00004AF1 ?AfxInitExtensionModule@@YAHAEAUAFX_EXTENSION_MODULE@@PEAUHINSTANCE__@@@Z ---- */
// attributes: thunk
int __fastcall AfxInitExtensionModule(struct AFX_EXTENSION_MODULE *a1, HINSTANCE a2)
{
  return __imp_?AfxInitExtensionModule@@YAHAEAUAFX_EXTENSION_MODULE@@PEAUHINSTANCE__@@@Z(a1, a2);
}

/* ---- FUNC 00004AF7 ??0COleVariant@@QEAA@JG@Z ---- */
// attributes: thunk
COleVariant *__fastcall COleVariant::COleVariant(COleVariant *this, int a2, unsigned __int16 a3)
{
  return __imp_??0COleVariant@@QEAA@JG@Z(this, a2, a3);
}

/* ---- FUNC 00004AFD ?DDX_Control@@YAXPEAVCDataExchange@@HAEAVCWnd@@@Z ---- */
// attributes: thunk
void __fastcall DDX_Control(struct CDataExchange *a1, int a2, struct CWnd *a3)
{
  __imp_?DDX_Control@@YAXPEAVCDataExchange@@HAEAVCWnd@@@Z(a1, a2, a3);
}

/* ---- FUNC 00004B03 ?OnCmdMsg@CCmdTarget@@UEAAHIHPEAXPEAUAFX_CMDHANDLERINFO@@@Z ---- */
// attributes: thunk
int __fastcall CCmdTarget::OnCmdMsg(CCmdTarget *this, unsigned int a2, int a3, void *a4, struct AFX_CMDHANDLERINFO *a5)
{
  return __imp_?OnCmdMsg@CCmdTarget@@UEAAHIHPEAXPEAUAFX_CMDHANDLERINFO@@@Z(this, a2, a3, a4, a5);
}

/* ---- FUNC 00004B09 ?IsInvokeAllowed@CCmdTarget@@UEAAHJ@Z ---- */
// attributes: thunk
int __fastcall CCmdTarget::IsInvokeAllowed(CCmdTarget *this, int a2)
{
  return __imp_?IsInvokeAllowed@CCmdTarget@@UEAAHJ@Z(this, a2);
}

/* ---- FUNC 00004B0F ?GetDispatchIID@CCmdTarget@@UEAAHPEAU_GUID@@@Z ---- */
// attributes: thunk
int __fastcall CCmdTarget::GetDispatchIID(CCmdTarget *this, _GUID *a2)
{
  return __imp_?GetDispatchIID@CCmdTarget@@UEAAHPEAU_GUID@@@Z(this, a2);
}

/* ---- FUNC 00004B15 ?GetTypeInfoCount@CCmdTarget@@UEAAIXZ ---- */
// attributes: thunk
unsigned int __fastcall CCmdTarget::GetTypeInfoCount(CCmdTarget *this)
{
  return __imp_?GetTypeInfoCount@CCmdTarget@@UEAAIXZ(this);
}

/* ---- FUNC 00004B1B ?GetTypeLibCache@CCmdTarget@@UEAAPEAVCTypeLibCache@@XZ ---- */
// attributes: thunk
struct CTypeLibCache *__fastcall CCmdTarget::GetTypeLibCache(CCmdTarget *this)
{
  return __imp_?GetTypeLibCache@CCmdTarget@@UEAAPEAVCTypeLibCache@@XZ(this);
}

/* ---- FUNC 00004B21 ?GetTypeLib@CCmdTarget@@UEAAJKPEAPEAUITypeLib@@@Z ---- */
// attributes: thunk
int __fastcall CCmdTarget::GetTypeLib(CCmdTarget *this, unsigned int a2, ITypeLib **a3)
{
  return __imp_?GetTypeLib@CCmdTarget@@UEAAJKPEAPEAUITypeLib@@@Z(this, a2, a3);
}

/* ---- FUNC 00004B27 ?GetCommandMap@CCmdTarget@@MEBAPEBUAFX_OLECMDMAP@@XZ ---- */
// attributes: thunk
const struct AFX_OLECMDMAP *__fastcall CCmdTarget::GetCommandMap(CCmdTarget *this)
{
  return __imp_?GetCommandMap@CCmdTarget@@MEBAPEBUAFX_OLECMDMAP@@XZ(this);
}

/* ---- FUNC 00004B2D ?GetDispatchMap@CCmdTarget@@MEBAPEBUAFX_DISPMAP@@XZ ---- */
// attributes: thunk
const struct AFX_DISPMAP *__fastcall CCmdTarget::GetDispatchMap(CCmdTarget *this)
{
  return __imp_?GetDispatchMap@CCmdTarget@@MEBAPEBUAFX_DISPMAP@@XZ(this);
}

/* ---- FUNC 00004B33 ?GetConnectionMap@CCmdTarget@@MEBAPEBUAFX_CONNECTIONMAP@@XZ ---- */
// attributes: thunk
const struct AFX_CONNECTIONMAP *__fastcall CCmdTarget::GetConnectionMap(CCmdTarget *this)
{
  return __imp_?GetConnectionMap@CCmdTarget@@MEBAPEBUAFX_CONNECTIONMAP@@XZ(this);
}

/* ---- FUNC 00004B39 ?GetEventSinkMap@CCmdTarget@@MEBAPEBUAFX_EVENTSINKMAP@@XZ ---- */
// attributes: thunk
const struct AFX_EVENTSINKMAP *__fastcall CCmdTarget::GetEventSinkMap(CCmdTarget *this)
{
  return __imp_?GetEventSinkMap@CCmdTarget@@MEBAPEBUAFX_EVENTSINKMAP@@XZ(this);
}

/* ---- FUNC 00004B3F ?OnCreateAggregates@CCmdTarget@@UEAAHXZ ---- */
// attributes: thunk
int __fastcall CCmdTarget::OnCreateAggregates(CCmdTarget *this)
{
  return __imp_?OnCreateAggregates@CCmdTarget@@UEAAHXZ(this);
}

/* ---- FUNC 00004B45 ?GetInterfaceHook@CCmdTarget@@UEAAPEAUIUnknown@@PEBX@Z ---- */
// attributes: thunk
IUnknown *__fastcall CCmdTarget::GetInterfaceHook(CCmdTarget *this, const void *a2)
{
  return __imp_?GetInterfaceHook@CCmdTarget@@UEAAPEAUIUnknown@@PEBX@Z(this, a2);
}

/* ---- FUNC 00004B4B ?GetExtraConnectionPoints@CCmdTarget@@MEAAHPEAVCPtrArray@@@Z ---- */
// attributes: thunk
int __fastcall CCmdTarget::GetExtraConnectionPoints(CCmdTarget *this, struct CPtrArray *a2)
{
  return __imp_?GetExtraConnectionPoints@CCmdTarget@@MEAAHPEAVCPtrArray@@@Z(this, a2);
}

/* ---- FUNC 00004B51 ?GetConnectionHook@CCmdTarget@@MEAAPEAUIConnectionPoint@@AEBU_GUID@@@Z ---- */
// attributes: thunk
IConnectionPoint *__fastcall CCmdTarget::GetConnectionHook(CCmdTarget *this, const _GUID *a2)
{
  return __imp_?GetConnectionHook@CCmdTarget@@MEAAPEAUIConnectionPoint@@AEBU_GUID@@@Z(this, a2);
}

/* ---- FUNC 00004B57 ??0CWnd@@QEAA@XZ ---- */
// attributes: thunk
CWnd *__fastcall CWnd::CWnd(CWnd *this)
{
  return __imp_??0CWnd@@QEAA@XZ(this);
}

/* ---- FUNC 00004B5D ?PreSubclassWindow@CWnd@@UEAAXXZ ---- */
// attributes: thunk
void __fastcall CWnd::PreSubclassWindow(CWnd *this)
{
  __imp_?PreSubclassWindow@CWnd@@UEAAXXZ(this);
}

/* ---- FUNC 00004B63 ?Create@CWnd@@UEAAHPEBD0KAEBUtagRECT@@PEAV1@IPEAUCCreateContext@@@Z ---- */
// attributes: thunk
int __fastcall CWnd::Create(
        CWnd *this,
        const char *a2,
        const char *a3,
        unsigned int a4,
        const tagRECT *a5,
        CWnd *a6,
        unsigned int a7,
        struct CCreateContext *a8)
{
  return __imp_?Create@CWnd@@UEAAHPEBD0KAEBUtagRECT@@PEAV1@IPEAUCCreateContext@@@Z(this, a2, a3, a4, a5, a6, a7, a8);
}

/* ---- FUNC 00004B69 ?CreateEx@CWnd@@UEAAHKPEBD0KHHHHPEAUHWND__@@PEAUHMENU__@@PEAX@Z ---- */
// attributes: thunk
int __fastcall CWnd::CreateEx(
        CWnd *this,
        unsigned int a2,
        const char *a3,
        const char *a4,
        unsigned int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        HWND a10,
        HMENU a11,
        void *a12)
{
  return __imp_?CreateEx@CWnd@@UEAAHKPEBD0KHHHHPEAUHWND__@@PEAUHMENU__@@PEAX@Z(
           this,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12);
}

/* ---- FUNC 00004B6F ?CreateEx@CWnd@@UEAAHKPEBD0KAEBUtagRECT@@PEAV1@IPEAX@Z ---- */
// attributes: thunk
int __fastcall CWnd::CreateEx(
        CWnd *this,
        unsigned int a2,
        const char *a3,
        const char *a4,
        unsigned int a5,
        const tagRECT *a6,
        CWnd *a7,
        unsigned int a8,
        void *a9)
{
  return __imp_?CreateEx@CWnd@@UEAAHKPEBD0KAEBUtagRECT@@PEAV1@IPEAX@Z(this, a2, a3, a4, a5, a6, a7, a8, a9);
}

/* ---- FUNC 00004B75 ?DestroyWindow@CWnd@@UEAAHXZ ---- */
// attributes: thunk
int __fastcall CWnd::DestroyWindow(CWnd *this)
{
  return __imp_?DestroyWindow@CWnd@@UEAAHXZ(this);
}

/* ---- FUNC 00004B7B ?PreCreateWindow@CWnd@@UEAAHAEAUtagCREATESTRUCTA@@@Z ---- */
// attributes: thunk
int __fastcall CWnd::PreCreateWindow(CWnd *this, tagCREATESTRUCTA *a2)
{
  return __imp_?PreCreateWindow@CWnd@@UEAAHAEAUtagCREATESTRUCTA@@@Z(this, a2);
}

/* ---- FUNC 00004B81 ?CalcWindowRect@CWnd@@UEAAXPEAUtagRECT@@I@Z ---- */
// attributes: thunk
void __fastcall CWnd::CalcWindowRect(CWnd *this, tagRECT *a2, unsigned int a3)
{
  __imp_?CalcWindowRect@CWnd@@UEAAXPEAUtagRECT@@I@Z(this, a2, a3);
}

/* ---- FUNC 00004B87 ?GetDlgItem@CWnd@@QEBAPEAV1@H@Z ---- */
// attributes: thunk
CWnd *__fastcall CWnd::GetDlgItem(CWnd *this, int a2)
{
  return __imp_?GetDlgItem@CWnd@@QEBAPEAV1@H@Z(this, a2);
}

/* ---- FUNC 00004B8D ?GetMenu@CWnd@@UEBAPEAVCMenu@@XZ ---- */
// attributes: thunk
struct CMenu *__fastcall CWnd::GetMenu(CWnd *this)
{
  return __imp_?GetMenu@CWnd@@UEBAPEAVCMenu@@XZ(this);
}

/* ---- FUNC 00004B93 ?SetMenu@CWnd@@UEAAHPEAVCMenu@@@Z ---- */
// attributes: thunk
int __fastcall CWnd::SetMenu(CWnd *this, struct CMenu *a2)
{
  return __imp_?SetMenu@CWnd@@UEAAHPEAVCMenu@@@Z(this, a2);
}

/* ---- FUNC 00004B99 ?OnToolHitTest@CWnd@@UEBA_JVCPoint@@PEAUtagTOOLINFOA@@@Z ---- */
// attributes: thunk
__int64 CWnd::OnToolHitTest()
{
  return __imp_?OnToolHitTest@CWnd@@UEBA_JVCPoint@@PEAUtagTOOLINFOA@@@Z();
}

/* ---- FUNC 00004B9F ?EnableWindow@CWnd@@QEAAHH@Z ---- */
// attributes: thunk
int __fastcall CWnd::EnableWindow(CWnd *this, int a2)
{
  return __imp_?EnableWindow@CWnd@@QEAAHH@Z(this, a2);
}

/* ---- FUNC 00004BA5 ?GetScrollBarCtrl@CWnd@@UEBAPEAVCScrollBar@@H@Z ---- */
// attributes: thunk
struct CScrollBar *__fastcall CWnd::GetScrollBarCtrl(CWnd *this, int a2)
{
  return __imp_?GetScrollBarCtrl@CWnd@@UEBAPEAVCScrollBar@@H@Z(this, a2);
}

/* ---- FUNC 00004BAB ?WinHelpA@CWnd@@UEAAX_KI@Z ---- */
// attributes: thunk
void __fastcall CWnd::WinHelpA(CWnd *this, unsigned __int64 a2, unsigned int a3)
{
  __imp_?WinHelpA@CWnd@@UEAAX_KI@Z(this, a2, a3);
}

/* ---- FUNC 00004BB1 ?HtmlHelpA@CWnd@@UEAAX_KI@Z ---- */
// attributes: thunk
void __fastcall CWnd::HtmlHelpA(CWnd *this, unsigned __int64 a2, unsigned int a3)
{
  __imp_?HtmlHelpA@CWnd@@UEAAX_KI@Z(this, a2, a3);
}

/* ---- FUNC 00004BB7 ?WinHelpInternal@CWnd@@UEAAX_KI@Z ---- */
// attributes: thunk
void __fastcall CWnd::WinHelpInternal(CWnd *this, unsigned __int64 a2, unsigned int a3)
{
  __imp_?WinHelpInternal@CWnd@@UEAAX_KI@Z(this, a2, a3);
}

/* ---- FUNC 00004BBD ?ContinueModal@CWnd@@UEAAHXZ ---- */
// attributes: thunk
int __fastcall CWnd::ContinueModal(CWnd *this)
{
  return __imp_?ContinueModal@CWnd@@UEAAHXZ(this);
}

/* ---- FUNC 00004BC3 ?EndModalLoop@CWnd@@UEAAXH@Z ---- */
// attributes: thunk
void __fastcall CWnd::EndModalLoop(CWnd *this, int a2)
{
  __imp_?EndModalLoop@CWnd@@UEAAXH@Z(this, a2);
}

/* ---- FUNC 00004BC9 ?OnDrawIconicThumbnailOrLivePreview@CWnd@@UEAAXAEAVCDC@@VCRect@@VCSize@@HAEAH@Z ---- */
// attributes: thunk
__int64 CWnd::OnDrawIconicThumbnailOrLivePreview()
{
  return __imp_?OnDrawIconicThumbnailOrLivePreview@CWnd@@UEAAXAEAVCDC@@VCRect@@VCSize@@HAEAH@Z();
}

/* ---- FUNC 00004BCF ?GetInterfaceMap@CWnd@@MEBAPEBUAFX_INTERFACEMAP@@XZ ---- */
// attributes: thunk
const struct AFX_INTERFACEMAP *__fastcall CWnd::GetInterfaceMap(CWnd *this)
{
  return __imp_?GetInterfaceMap@CWnd@@MEBAPEBUAFX_INTERFACEMAP@@XZ(this);
}

/* ---- FUNC 00004BD5 ?EnsureStdObj@CWnd@@UEAAJXZ ---- */
// attributes: thunk
int __fastcall CWnd::EnsureStdObj(CWnd *this)
{
  return __imp_?EnsureStdObj@CWnd@@UEAAJXZ(this);
}

/* ---- FUNC 00004BDB ?get_accParent@CWnd@@UEAAJPEAPEAUIDispatch@@@Z ---- */
// attributes: thunk
int __fastcall CWnd::get_accParent(CWnd *this, IDispatch **a2)
{
  return __imp_?get_accParent@CWnd@@UEAAJPEAPEAUIDispatch@@@Z(this, a2);
}

/* ---- FUNC 00004BE1 ?get_accChildCount@CWnd@@UEAAJPEAJ@Z ---- */
// attributes: thunk
int __fastcall CWnd::get_accChildCount(CWnd *this, int *a2)
{
  return __imp_?get_accChildCount@CWnd@@UEAAJPEAJ@Z(this, a2);
}

/* ---- FUNC 00004BE7 ?get_accChild@CWnd@@UEAAJUtagVARIANT@@PEAPEAUIDispatch@@@Z ---- */
// attributes: thunk
int __fastcall CWnd::get_accChild(CWnd *this, tagVARIANT *a2, IDispatch **a3)
{
  return __imp_?get_accChild@CWnd@@UEAAJUtagVARIANT@@PEAPEAUIDispatch@@@Z(this, a2, a3);
}

/* ---- FUNC 00004BED ?get_accName@CWnd@@UEAAJUtagVARIANT@@PEAPEA_W@Z ---- */
// attributes: thunk
int __fastcall CWnd::get_accName(CWnd *this, tagVARIANT *a2, wchar_t **a3)
{
  return __imp_?get_accName@CWnd@@UEAAJUtagVARIANT@@PEAPEA_W@Z(this, a2, a3);
}

/* ---- FUNC 00004BF3 ?get_accValue@CWnd@@UEAAJUtagVARIANT@@PEAPEA_W@Z ---- */
// attributes: thunk
int __fastcall CWnd::get_accValue(CWnd *this, tagVARIANT *a2, wchar_t **a3)
{
  return __imp_?get_accValue@CWnd@@UEAAJUtagVARIANT@@PEAPEA_W@Z(this, a2, a3);
}

/* ---- FUNC 00004BF9 ?get_accDescription@CWnd@@UEAAJUtagVARIANT@@PEAPEA_W@Z ---- */
// attributes: thunk
int __fastcall CWnd::get_accDescription(CWnd *this, tagVARIANT *a2, wchar_t **a3)
{
  return __imp_?get_accDescription@CWnd@@UEAAJUtagVARIANT@@PEAPEA_W@Z(this, a2, a3);
}

/* ---- FUNC 00004BFF ?get_accRole@CWnd@@UEAAJUtagVARIANT@@PEAU2@@Z ---- */
// attributes: thunk
int __fastcall CWnd::get_accRole(CWnd *this, tagVARIANT *a2, tagVARIANT *a3)
{
  return __imp_?get_accRole@CWnd@@UEAAJUtagVARIANT@@PEAU2@@Z(this, a2, a3);
}

/* ---- FUNC 00004C05 ?get_accState@CWnd@@UEAAJUtagVARIANT@@PEAU2@@Z ---- */
// attributes: thunk
int __fastcall CWnd::get_accState(CWnd *this, tagVARIANT *a2, tagVARIANT *a3)
{
  return __imp_?get_accState@CWnd@@UEAAJUtagVARIANT@@PEAU2@@Z(this, a2, a3);
}

/* ---- FUNC 00004C0B ?get_accHelp@CWnd@@UEAAJUtagVARIANT@@PEAPEA_W@Z ---- */
// attributes: thunk
int __fastcall CWnd::get_accHelp(CWnd *this, tagVARIANT *a2, wchar_t **a3)
{
  return __imp_?get_accHelp@CWnd@@UEAAJUtagVARIANT@@PEAPEA_W@Z(this, a2, a3);
}

/* ---- FUNC 00004C11 ?get_accHelpTopic@CWnd@@UEAAJPEAPEA_WUtagVARIANT@@PEAJ@Z ---- */
// attributes: thunk
int __fastcall CWnd::get_accHelpTopic(CWnd *this, wchar_t **a2, tagVARIANT *a3, int *a4)
{
  return __imp_?get_accHelpTopic@CWnd@@UEAAJPEAPEA_WUtagVARIANT@@PEAJ@Z(this, a2, a3, a4);
}

/* ---- FUNC 00004C17 ?get_accKeyboardShortcut@CWnd@@UEAAJUtagVARIANT@@PEAPEA_W@Z ---- */
// attributes: thunk
int __fastcall CWnd::get_accKeyboardShortcut(CWnd *this, tagVARIANT *a2, wchar_t **a3)
{
  return __imp_?get_accKeyboardShortcut@CWnd@@UEAAJUtagVARIANT@@PEAPEA_W@Z(this, a2, a3);
}

/* ---- FUNC 00004C1D ?get_accFocus@CWnd@@UEAAJPEAUtagVARIANT@@@Z ---- */
// attributes: thunk
int __fastcall CWnd::get_accFocus(CWnd *this, tagVARIANT *a2)
{
  return __imp_?get_accFocus@CWnd@@UEAAJPEAUtagVARIANT@@@Z(this, a2);
}

/* ---- FUNC 00004C23 ?get_accSelection@CWnd@@UEAAJPEAUtagVARIANT@@@Z ---- */
// attributes: thunk
int __fastcall CWnd::get_accSelection(CWnd *this, tagVARIANT *a2)
{
  return __imp_?get_accSelection@CWnd@@UEAAJPEAUtagVARIANT@@@Z(this, a2);
}

/* ---- FUNC 00004C29 ?get_accDefaultAction@CWnd@@UEAAJUtagVARIANT@@PEAPEA_W@Z ---- */
// attributes: thunk
int __fastcall CWnd::get_accDefaultAction(CWnd *this, tagVARIANT *a2, wchar_t **a3)
{
  return __imp_?get_accDefaultAction@CWnd@@UEAAJUtagVARIANT@@PEAPEA_W@Z(this, a2, a3);
}

/* ---- FUNC 00004C2F ?accSelect@CWnd@@UEAAJJUtagVARIANT@@@Z ---- */
// attributes: thunk
int __fastcall CWnd::accSelect(CWnd *this, int a2, tagVARIANT *a3)
{
  return __imp_?accSelect@CWnd@@UEAAJJUtagVARIANT@@@Z(this, a2, a3);
}

/* ---- FUNC 00004C35 ?accLocation@CWnd@@UEAAJPEAJ000UtagVARIANT@@@Z ---- */
// attributes: thunk
int __fastcall CWnd::accLocation(CWnd *this, int *a2, int *a3, int *a4, int *a5, tagVARIANT *a6)
{
  return __imp_?accLocation@CWnd@@UEAAJPEAJ000UtagVARIANT@@@Z(this, a2, a3, a4, a5, a6);
}

/* ---- FUNC 00004C3B ?accNavigate@CWnd@@UEAAJJUtagVARIANT@@PEAU2@@Z ---- */
// attributes: thunk
int __fastcall CWnd::accNavigate(CWnd *this, int a2, tagVARIANT *a3, tagVARIANT *a4)
{
  return __imp_?accNavigate@CWnd@@UEAAJJUtagVARIANT@@PEAU2@@Z(this, a2, a3, a4);
}

/* ---- FUNC 00004C41 ?accHitTest@CWnd@@UEAAJJJPEAUtagVARIANT@@@Z ---- */
// attributes: thunk
int __fastcall CWnd::accHitTest(CWnd *this, int a2, int a3, tagVARIANT *a4)
{
  return __imp_?accHitTest@CWnd@@UEAAJJJPEAUtagVARIANT@@@Z(this, a2, a3, a4);
}

/* ---- FUNC 00004C47 ?accDoDefaultAction@CWnd@@UEAAJUtagVARIANT@@@Z ---- */
// attributes: thunk
int __fastcall CWnd::accDoDefaultAction(CWnd *this, tagVARIANT *a2)
{
  return __imp_?accDoDefaultAction@CWnd@@UEAAJUtagVARIANT@@@Z(this, a2);
}

/* ---- FUNC 00004C4D ?put_accName@CWnd@@UEAAJUtagVARIANT@@PEA_W@Z ---- */
// attributes: thunk
int __fastcall CWnd::put_accName(CWnd *this, tagVARIANT *a2, wchar_t *a3)
{
  return __imp_?put_accName@CWnd@@UEAAJUtagVARIANT@@PEA_W@Z(this, a2, a3);
}

/* ---- FUNC 00004C53 ?put_accValue@CWnd@@UEAAJUtagVARIANT@@PEA_W@Z ---- */
// attributes: thunk
int __fastcall CWnd::put_accValue(CWnd *this, tagVARIANT *a2, wchar_t *a3)
{
  return __imp_?put_accValue@CWnd@@UEAAJUtagVARIANT@@PEA_W@Z(this, a2, a3);
}

/* ---- FUNC 00004C59 ?SetProxy@CWnd@@UEAAJPEAUIAccessibleProxy@@@Z ---- */
// attributes: thunk
int __fastcall CWnd::SetProxy(CWnd *this, struct IAccessibleProxy *a2)
{
  return __imp_?SetProxy@CWnd@@UEAAJPEAUIAccessibleProxy@@@Z(this, a2);
}

/* ---- FUNC 00004C5F ?CreateAccessibleProxy@CWnd@@UEAAJ_K_JPEA_J@Z ---- */
// attributes: thunk
int __fastcall CWnd::CreateAccessibleProxy(CWnd *this, unsigned __int64 a2, __int64 a3, __int64 *a4)
{
  return __imp_?CreateAccessibleProxy@CWnd@@UEAAJ_K_JPEA_J@Z(this, a2, a3, a4);
}

/* ---- FUNC 00004C65 ?OnCommand@CWnd@@MEAAH_K_J@Z ---- */
// attributes: thunk
int __fastcall CWnd::OnCommand(CWnd *this, unsigned __int64 a2, __int64 a3)
{
  return __imp_?OnCommand@CWnd@@MEAAH_K_J@Z(this, a2, a3);
}

/* ---- FUNC 00004C6B ?OnNotify@CWnd@@MEAAH_K_JPEA_J@Z ---- */
// attributes: thunk
int __fastcall CWnd::OnNotify(CWnd *this, unsigned __int64 a2, __int64 a3, __int64 *a4)
{
  return __imp_?OnNotify@CWnd@@MEAAH_K_JPEA_J@Z(this, a2, a3, a4);
}

/* ---- FUNC 00004C71 ?GetSuperWndProcAddr@CWnd@@MEAAPEAP6A_JPEAUHWND__@@I_K_J@ZXZ ---- */
// attributes: thunk
__int64 (**__fastcall CWnd::GetSuperWndProcAddr(CWnd *this))(HWND, unsigned int, unsigned __int64, __int64)
{
  return __imp_?GetSuperWndProcAddr@CWnd@@MEAAPEAP6A_JPEAUHWND__@@I_K_J@ZXZ(this);
}

/* ---- FUNC 00004C77 ?PreTranslateMessage@CWnd@@UEAAHPEAUtagMSG@@@Z ---- */
// attributes: thunk
int __fastcall CWnd::PreTranslateMessage(CWnd *this, tagMSG *a2)
{
  return __imp_?PreTranslateMessage@CWnd@@UEAAHPEAUtagMSG@@@Z(this, a2);
}

/* ---- FUNC 00004C7D ?OnAmbientProperty@CWnd@@UEAAHPEAVCOleControlSite@@JPEAUtagVARIANT@@@Z ---- */
// attributes: thunk
int __fastcall CWnd::OnAmbientProperty(CWnd *this, struct COleControlSite *a2, int a3, tagVARIANT *a4)
{
  return __imp_?OnAmbientProperty@CWnd@@UEAAHPEAVCOleControlSite@@JPEAUtagVARIANT@@@Z(this, a2, a3, a4);
}

/* ---- FUNC 00004C83 ?WindowProc@CWnd@@MEAA_JI_K_J@Z ---- */
// attributes: thunk
__int64 __fastcall CWnd::WindowProc(CWnd *this, unsigned int a2, unsigned __int64 a3, __int64 a4)
{
  return __imp_?WindowProc@CWnd@@MEAA_JI_K_J@Z(this, a2, a3, a4);
}

/* ---- FUNC 00004C89 ?OnWndMsg@CWnd@@MEAAHI_K_JPEA_J@Z ---- */
// attributes: thunk
int __fastcall CWnd::OnWndMsg(CWnd *this, unsigned int a2, unsigned __int64 a3, __int64 a4, __int64 *a5)
{
  return __imp_?OnWndMsg@CWnd@@MEAAHI_K_JPEA_J@Z(this, a2, a3, a4, a5);
}

/* ---- FUNC 00004C8F ?DefWindowProcA@CWnd@@MEAA_JI_K_J@Z ---- */
// attributes: thunk
__int64 __fastcall CWnd::DefWindowProcA(CWnd *this, unsigned int a2, unsigned __int64 a3, __int64 a4)
{
  return __imp_?DefWindowProcA@CWnd@@MEAA_JI_K_J@Z(this, a2, a3, a4);
}

/* ---- FUNC 00004C95 ?PostNcDestroy@CWnd@@MEAAXXZ ---- */
// attributes: thunk
void __fastcall CWnd::PostNcDestroy(CWnd *this)
{
  __imp_?PostNcDestroy@CWnd@@MEAAXXZ(this);
}

/* ---- FUNC 00004C9B ?OnChildNotify@CWnd@@MEAAHI_K_JPEA_J@Z ---- */
// attributes: thunk
int __fastcall CWnd::OnChildNotify(CWnd *this, unsigned int a2, unsigned __int64 a3, __int64 a4, __int64 *a5)
{
  return __imp_?OnChildNotify@CWnd@@MEAAHI_K_JPEA_J@Z(this, a2, a3, a4, a5);
}

/* ---- FUNC 00004CA1 ?OnTouchInputs@CWnd@@MEAAHIPEAUtagTOUCHINPUT@@@Z ---- */
// attributes: thunk
int __fastcall CWnd::OnTouchInputs(CWnd *this, unsigned int a2, tagTOUCHINPUT *a3)
{
  return __imp_?OnTouchInputs@CWnd@@MEAAHIPEAUtagTOUCHINPUT@@@Z(this, a2, a3);
}

/* ---- FUNC 00004CA7 ?OnTouchInput@CWnd@@MEAAHVCPoint@@HHPEAUtagTOUCHINPUT@@@Z ---- */
// attributes: thunk
__int64 CWnd::OnTouchInput()
{
  return __imp_?OnTouchInput@CWnd@@MEAAHVCPoint@@HHPEAUtagTOUCHINPUT@@@Z();
}

/* ---- FUNC 00004CAD ?GetGestureStatus@CWnd@@MEAAKVCPoint@@@Z ---- */
// attributes: thunk
__int64 CWnd::GetGestureStatus()
{
  return __imp_?GetGestureStatus@CWnd@@MEAAKVCPoint@@@Z();
}

/* ---- FUNC 00004CB3 ?OnGestureZoom@CWnd@@MEAAHVCPoint@@J@Z ---- */
// attributes: thunk
__int64 CWnd::OnGestureZoom()
{
  return __imp_?OnGestureZoom@CWnd@@MEAAHVCPoint@@J@Z();
}

/* ---- FUNC 00004CB9 ?OnGesturePan@CWnd@@MEAAHVCPoint@@0@Z ---- */
// attributes: thunk
__int64 CWnd::OnGesturePan()
{
  return __imp_?OnGesturePan@CWnd@@MEAAHVCPoint@@0@Z();
}

/* ---- FUNC 00004CBF ?OnGestureRotate@CWnd@@MEAAHVCPoint@@N@Z ---- */
// attributes: thunk
__int64 CWnd::OnGestureRotate()
{
  return __imp_?OnGestureRotate@CWnd@@MEAAHVCPoint@@N@Z();
}

/* ---- FUNC 00004CC5 ?OnGestureTwoFingerTap@CWnd@@MEAAHVCPoint@@@Z ---- */
// attributes: thunk
__int64 CWnd::OnGestureTwoFingerTap()
{
  return __imp_?OnGestureTwoFingerTap@CWnd@@MEAAHVCPoint@@@Z();
}

/* ---- FUNC 00004CCB ?OnGesturePressAndTap@CWnd@@MEAAHVCPoint@@J@Z ---- */
// attributes: thunk
__int64 CWnd::OnGesturePressAndTap()
{
  return __imp_?OnGesturePressAndTap@CWnd@@MEAAHVCPoint@@J@Z();
}

/* ---- FUNC 00004CD1 ?ResizeDynamicLayout@CWnd@@MEAAXXZ ---- */
// attributes: thunk
void __fastcall CWnd::ResizeDynamicLayout(CWnd *this)
{
  __imp_?ResizeDynamicLayout@CWnd@@MEAAXXZ(this);
}

/* ---- FUNC 00004CD7 ?CheckAutoCenter@CWnd@@UEAAHXZ ---- */
// attributes: thunk
int __fastcall CWnd::CheckAutoCenter(CWnd *this)
{
  return __imp_?CheckAutoCenter@CWnd@@UEAAHXZ(this);
}

/* ---- FUNC 00004CDD ?IsFrameWnd@CWnd@@UEBAHXZ ---- */
// attributes: thunk
int __fastcall CWnd::IsFrameWnd(CWnd *this)
{
  return __imp_?IsFrameWnd@CWnd@@UEBAHXZ(this);
}

/* ---- FUNC 00004CE3 ?OnFinalRelease@CWnd@@UEAAXXZ ---- */
// attributes: thunk
void __fastcall CWnd::OnFinalRelease(CWnd *this)
{
  __imp_?OnFinalRelease@CWnd@@UEAAXXZ(this);
}

/* ---- FUNC 00004CE9 ?CreateControlContainer@CWnd@@MEAAHPEAPEAVCOleControlContainer@@@Z ---- */
// attributes: thunk
int __fastcall CWnd::CreateControlContainer(CWnd *this, struct COleControlContainer **a2)
{
  return __imp_?CreateControlContainer@CWnd@@MEAAHPEAPEAVCOleControlContainer@@@Z(this, a2);
}

/* ---- FUNC 00004CEF ?CreateControlSite@CWnd@@MEAAHPEAVCOleControlContainer@@PEAPEAVCOleControlSite@@IAEBU_GUID@@@Z ---- */
// attributes: thunk
int __fastcall CWnd::CreateControlSite(
        CWnd *this,
        struct COleControlContainer *a2,
        struct COleControlSite **a3,
        unsigned int a4,
        const _GUID *a5)
{
  return __imp_?CreateControlSite@CWnd@@MEAAHPEAVCOleControlContainer@@PEAPEAVCOleControlSite@@IAEBU_GUID@@@Z(
           this,
           a2,
           a3,
           a4,
           a5);
}

/* ---- FUNC 00004CF5 ?SetOccDialogInfo@CWnd@@MEAAHPEAU_AFX_OCC_DIALOG_INFO@@@Z ---- */
// attributes: thunk
int __fastcall CWnd::SetOccDialogInfo(CWnd *this, struct _AFX_OCC_DIALOG_INFO *a2)
{
  return __imp_?SetOccDialogInfo@CWnd@@MEAAHPEAU_AFX_OCC_DIALOG_INFO@@@Z(this, a2);
}

/* ---- FUNC 00004CFB ?GetOccDialogInfo@CWnd@@MEAAPEAU_AFX_OCC_DIALOG_INFO@@XZ ---- */
// attributes: thunk
struct _AFX_OCC_DIALOG_INFO *__fastcall CWnd::GetOccDialogInfo(CWnd *this)
{
  return __imp_?GetOccDialogInfo@CWnd@@MEAAPEAU_AFX_OCC_DIALOG_INFO@@XZ(this);
}

/* ---- FUNC 00004D01 ?GetRuntimeClass@CDialog@@UEBAPEAUCRuntimeClass@@XZ ---- */
// attributes: thunk
struct CRuntimeClass *__fastcall CDialog::GetRuntimeClass(CDialog *this)
{
  return __imp_?GetRuntimeClass@CDialog@@UEBAPEAUCRuntimeClass@@XZ(this);
}

/* ---- FUNC 00004D07 ?Create@CDialog@@UEAAHPEBDPEAVCWnd@@@Z ---- */
// attributes: thunk
int __fastcall CDialog::Create(CDialog *this, const char *a2, CWnd *a3)
{
  return __imp_?Create@CDialog@@UEAAHPEBDPEAVCWnd@@@Z(this, a2, a3);
}

/* ---- FUNC 00004D0D ?CreateIndirect@CDialog@@UEAAHPEBUDLGTEMPLATE@@PEAVCWnd@@PEAX@Z ---- */
// attributes: thunk
int __fastcall CDialog::CreateIndirect(CDialog *this, const DLGTEMPLATE *a2, CWnd *a3, void *a4)
{
  return __imp_?CreateIndirect@CDialog@@UEAAHPEBUDLGTEMPLATE@@PEAVCWnd@@PEAX@Z(this, a2, a3, a4);
}

/* ---- FUNC 00004D13 ?CreateIndirect@CDialog@@UEAAHPEAXPEAVCWnd@@@Z ---- */
// attributes: thunk
int __fastcall CDialog::CreateIndirect(CDialog *this, void *a2, CWnd *a3)
{
  return __imp_?CreateIndirect@CDialog@@UEAAHPEAXPEAVCWnd@@@Z(this, a2, a3);
}

/* ---- FUNC 00004D19 ?OnInitDialog@CDialog@@UEAAHXZ ---- */
// attributes: thunk
int __fastcall CDialog::OnInitDialog(CDialog *this)
{
  return __imp_?OnInitDialog@CDialog@@UEAAHXZ(this);
}

/* ---- FUNC 00004D1F ?OnSetFont@CDialog@@UEAAXPEAVCFont@@@Z ---- */
// attributes: thunk
void __fastcall CDialog::OnSetFont(CDialog *this, struct CFont *a2)
{
  __imp_?OnSetFont@CDialog@@UEAAXPEAVCFont@@@Z(this, a2);
}

/* ---- FUNC 00004D25 ?OnOK@CDialog@@MEAAXXZ ---- */
// attributes: thunk
void __fastcall CDialog::OnOK(CDialog *this)
{
  __imp_?OnOK@CDialog@@MEAAXXZ(this);
}

/* ---- FUNC 00004D2B ?OnCancel@CDialog@@MEAAXXZ ---- */
// attributes: thunk
void __fastcall CDialog::OnCancel(CDialog *this)
{
  __imp_?OnCancel@CDialog@@MEAAXXZ(this);
}

/* ---- FUNC 00004D31 ??1CDialog@@UEAA@XZ ---- */
// attributes: thunk
void __fastcall CDialog::~CDialog(CDialog *this)
{
  __imp_??1CDialog@@UEAA@XZ(this);
}

/* ---- FUNC 00004D37 ?PreTranslateMessage@CDialog@@UEAAHPEAUtagMSG@@@Z ---- */
// attributes: thunk
int __fastcall CDialog::PreTranslateMessage(CDialog *this, tagMSG *a2)
{
  return __imp_?PreTranslateMessage@CDialog@@UEAAHPEAUtagMSG@@@Z(this, a2);
}

/* ---- FUNC 00004D3D ?OnCmdMsg@CDialog@@UEAAHIHPEAXPEAUAFX_CMDHANDLERINFO@@@Z ---- */
// attributes: thunk
int __fastcall CDialog::OnCmdMsg(CDialog *this, unsigned int a2, int a3, void *a4, struct AFX_CMDHANDLERINFO *a5)
{
  return __imp_?OnCmdMsg@CDialog@@UEAAHIHPEAXPEAUAFX_CMDHANDLERINFO@@@Z(this, a2, a3, a4, a5);
}

/* ---- FUNC 00004D43 ?CheckAutoCenter@CDialog@@UEAAHXZ ---- */
// attributes: thunk
int __fastcall CDialog::CheckAutoCenter(CDialog *this)
{
  return __imp_?CheckAutoCenter@CDialog@@UEAAHXZ(this);
}

/* ---- FUNC 00004D49 ?SetOccDialogInfo@CDialog@@MEAAHPEAU_AFX_OCC_DIALOG_INFO@@@Z ---- */
// attributes: thunk
int __fastcall CDialog::SetOccDialogInfo(CDialog *this, struct _AFX_OCC_DIALOG_INFO *a2)
{
  return __imp_?SetOccDialogInfo@CDialog@@MEAAHPEAU_AFX_OCC_DIALOG_INFO@@@Z(this, a2);
}

/* ---- FUNC 00004D4F ?GetOccDialogInfo@CDialog@@MEAAPEAU_AFX_OCC_DIALOG_INFO@@XZ ---- */
// attributes: thunk
struct _AFX_OCC_DIALOG_INFO *__fastcall CDialog::GetOccDialogInfo(CDialog *this)
{
  return __imp_?GetOccDialogInfo@CDialog@@MEAAPEAU_AFX_OCC_DIALOG_INFO@@XZ(this);
}

/* ---- FUNC 00004D55 ?PreInitDialog@CDialog@@MEAAXXZ ---- */
// attributes: thunk
void __fastcall CDialog::PreInitDialog(CDialog *this)
{
  __imp_?PreInitDialog@CDialog@@MEAAXXZ(this);
}

/* ---- FUNC 00004D5B ?GetThisMessageMap@CDialog@@KAPEBUAFX_MSGMAP@@XZ ---- */
// attributes: thunk
static const struct AFX_MSGMAP *CDialog::GetThisMessageMap()
{
  return __imp_?GetThisMessageMap@CDialog@@KAPEBUAFX_MSGMAP@@XZ();
}

/* ---- FUNC 00004D61 ?GetRuntimeClass@CTreeCtrl@@UEBAPEAUCRuntimeClass@@XZ ---- */
// attributes: thunk
struct CRuntimeClass *__fastcall CTreeCtrl::GetRuntimeClass(CTreeCtrl *this)
{
  return __imp_?GetRuntimeClass@CTreeCtrl@@UEBAPEAUCRuntimeClass@@XZ(this);
}

/* ---- FUNC 00004D67 ?SetItem@CTreeCtrl@@QEAAHPEAU_TREEITEM@@IPEBDHHII_J@Z ---- */
// attributes: thunk
int __fastcall CTreeCtrl::SetItem(
        CTreeCtrl *this,
        _TREEITEM *a2,
        unsigned int a3,
        const char *a4,
        int a5,
        int a6,
        unsigned int a7,
        unsigned int a8,
        __int64 a9)
{
  return __imp_?SetItem@CTreeCtrl@@QEAAHPEAU_TREEITEM@@IPEBDHHII_J@Z(this, a2, a3, a4, a5, a6, a7, a8, a9);
}

/* ---- FUNC 00004D6D ?InsertItem@CTreeCtrl@@QEAAPEAU_TREEITEM@@IPEBDHHII_JPEAU2@2@Z ---- */
// attributes: thunk
_TREEITEM *__fastcall CTreeCtrl::InsertItem(
        CTreeCtrl *this,
        unsigned int a2,
        const char *a3,
        int a4,
        int a5,
        unsigned int a6,
        unsigned int a7,
        __int64 a8,
        _TREEITEM *a9,
        _TREEITEM *a10)
{
  return __imp_?InsertItem@CTreeCtrl@@QEAAPEAU_TREEITEM@@IPEBDHHII_JPEAU2@2@Z(this, a2, a3, a4, a5, a6, a7, a8, a9, a10);
}

/* ---- FUNC 00004D73 ??1CTreeCtrl@@UEAA@XZ ---- */
// attributes: thunk
void __fastcall CTreeCtrl::~CTreeCtrl(CTreeCtrl *this)
{
  __imp_??1CTreeCtrl@@UEAA@XZ(this);
}

/* ---- FUNC 00004D79 ?GetMessageMap@CTreeCtrl@@MEBAPEBUAFX_MSGMAP@@XZ ---- */
// attributes: thunk
const struct AFX_MSGMAP *__fastcall CTreeCtrl::GetMessageMap(CTreeCtrl *this)
{
  return __imp_?GetMessageMap@CTreeCtrl@@MEBAPEBUAFX_MSGMAP@@XZ(this);
}

/* ---- FUNC 00004D80 ??_Gtype_info@@UEAAPEAXI@Z ---- */
type_info *__fastcall type_info::`scalar deleting destructor'(type_info *this, char a2)
{
  *(_QWORD *)this = &type_info::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}

/* ---- FUNC 00004DAC j_??3@YAXPEAX@Z ---- */
// attributes: thunk
void __fastcall operator delete(void *a1)
{
  ??3@YAXPEAX@Z(a1);
}

/* ---- FUNC 00004DB4 __scrt_acquire_startup_lock ---- */
char _scrt_acquire_startup_lock()
{
  PVOID StackBase; // rcx
  signed __int64 v1; // rax

  if ( _scrt_is_ucrt_dll_in_use() )
  {
    StackBase = NtCurrentTeb()->NtTib.StackBase;
    while ( 1 )
    {
      v1 = _InterlockedCompareExchange64(&_scrt_native_startup_lock, (signed __int64)StackBase, 0);
      if ( v1 == 0 )
        break;
      if ( StackBase == (PVOID)v1 )
        return 1;
    }
  }
  return 0;
}

/* ---- FUNC 00004DF0 __scrt_dllmain_after_initialize_c ---- */
char _scrt_dllmain_after_initialize_c()
{
  _crt_argv_mode startup_argv_mode; // eax

  if ( _scrt_is_ucrt_dll_in_use() )
  {
    _isa_available_init();
  }
  else
  {
    startup_argv_mode = get_startup_argv_mode();
    if ( configure_narrow_argv(startup_argv_mode) != 0 )
      return 0;
    initialize_narrow_environment();
  }
  return 1;
}

/* ---- FUNC 00004E24 __scrt_dllmain_before_initialize_c ---- */
bool _scrt_dllmain_before_initialize_c()
{
  return _scrt_initialize_onexit_tables(0) != 0;
}

/* ---- FUNC 00004E3C __scrt_dllmain_crt_thread_attach ---- */
char _scrt_dllmain_crt_thread_attach()
{
  if ( !_vcrt_thread_detach() )
    return 0;
  if ( !_vcrt_thread_detach() )
  {
    _vcrt_thread_detach();
    return 0;
  }
  return 1;
}

/* ---- FUNC 00004E64 __scrt_dllmain_crt_thread_detach ---- */
char _scrt_dllmain_crt_thread_detach()
{
  _vcrt_thread_detach();
  _vcrt_thread_detach();
  return 1;
}

/* ---- FUNC 00004E7C __scrt_dllmain_exception_filter ---- */
int __fastcall _scrt_dllmain_exception_filter(
        __int64 a1,
        int a2,
        __int64 a3,
        void (__fastcall *a4)(__int64, _QWORD, __int64),
        unsigned int ExceptionNum,
        struct _EXCEPTION_POINTERS *ExceptionPtr)
{
  if ( !_scrt_is_ucrt_dll_in_use() && a2 == 1 )
    a4(a1, 0, a3);
  return seh_filter_dll(ExceptionNum, ExceptionPtr);
}

/* ---- FUNC 00004EDC __scrt_dllmain_uninitialize_c ---- */
void _scrt_dllmain_uninitialize_c()
{
  if ( _scrt_is_ucrt_dll_in_use() )
  {
    execute_onexit_table(&module_local_atexit_table);
  }
  else if ( is_c_termination_complete() == 0 )
  {
    cexit();
  }
}

/* ---- FUNC 00004F0C __scrt_dllmain_uninitialize_critical ---- */
__vcrt_bool _scrt_dllmain_uninitialize_critical()
{
  _vcrt_thread_detach();
  return _vcrt_thread_detach();
}

/* ---- FUNC 00004F20 __scrt_initialize_crt ---- */
char __fastcall _scrt_initialize_crt(int a1)
{
  char v1; // al

  v1 = is_initialized_as_dll;
  if ( a1 == 0 )
    v1 = 1;
  is_initialized_as_dll = v1;
  _isa_available_init();
  if ( !_vcrt_thread_detach() )
    return 0;
  if ( !_vcrt_thread_detach() )
  {
    _vcrt_thread_detach();
    return 0;
  }
  return 1;
}

/* ---- FUNC 00004F6C __scrt_initialize_onexit_tables ---- */
char __fastcall _scrt_initialize_onexit_tables(unsigned int a1)
{
  if ( !module_local_atexit_table_initialized )
  {
    if ( a1 > 1 )
    {
      _scrt_fastfail(5u);
      JUMPOUT(0x180004FF6LL);
    }
    if ( !_scrt_is_ucrt_dll_in_use() || a1 != 0 )
    {
      *(__int128 *)&module_local_atexit_table._first = _xmm_ffffffffffffffffffffffffffffffff;
      module_local_atexit_table._end = (_PVFV *)-1LL;
      *(__int128 *)&module_local_at_quick_exit_table._first = _xmm_ffffffffffffffffffffffffffffffff;
      module_local_at_quick_exit_table._end = (_PVFV *)-1LL;
    }
    else if ( initialize_onexit_table(&module_local_atexit_table) != 0
           || initialize_onexit_table(&module_local_at_quick_exit_table) != 0 )
    {
      return 0;
    }
    module_local_atexit_table_initialized = true;
  }
  return 1;
}

/* ---- FUNC 00004FF8 __scrt_is_nonwritable_in_current_image ---- */
bool __fastcall _scrt_is_nonwritable_in_current_image(__int64 a1)
{
  _DWORD *v2; // rcx
  unsigned __int64 v3; // r8
  _DWORD *v4; // rdx
  _DWORD *v5; // r9
  unsigned __int64 v6; // rcx

  if ( MEMORY[0x180000000] != 23117 )
    return false;
  v2 = (_DWORD *)(0x180000000LL + MEMORY[0x18000003C]);
  if ( *v2 != 17744 || *(_WORD *)(0x180000018LL + MEMORY[0x18000003C]) != 523 )
    return false;
  v3 = a1 - 0x180000000LL;
  v4 = (_DWORD *)((char *)v2 + *(unsigned __int16 *)(0x180000014LL + MEMORY[0x18000003C]) + 24);
  v5 = &v4[10 * *(unsigned __int16 *)(0x180000006LL + MEMORY[0x18000003C])];
  while ( v4 != v5 )
  {
    v6 = (unsigned int)v4[3];
    if ( v3 >= v6 && v3 < (unsigned int)(v6 + v4[2]) )
      return v4 != nullptr && v4[9] >= 0;
    v4 += 10;
  }
  v4 = nullptr;
  return v4 != nullptr && v4[9] >= 0;
}

/* ---- FUNC 00005090 __scrt_release_startup_lock ---- */
_BOOL8 __fastcall _scrt_release_startup_lock(char a1)
{
  _BOOL8 result; // rax

  result = _scrt_is_ucrt_dll_in_use();
  if ( result && a1 == 0 )
    _InterlockedExchange64(&_scrt_native_startup_lock, 0);
  return result;
}

/* ---- FUNC 000050B4 __scrt_uninitialize_crt ---- */
char __fastcall _scrt_uninitialize_crt(__int64 a1, char a2)
{
  if ( !is_initialized_as_dll || a2 == 0 )
  {
    _vcrt_thread_detach();
    _vcrt_thread_detach();
  }
  return 1;
}

/* ---- FUNC 000050E0 _onexit ---- */
_onexit_t __cdecl onexit(_onexit_t Func)
{
  int v2; // eax
  int (__cdecl *v3)(); // rdx

  if ( module_local_atexit_table._first == (_PVFV *)-1LL )
    v2 = crt_atexit((_PVFV)Func);
  else
    v2 = register_onexit_function(&module_local_atexit_table, Func);
  v3 = nullptr;
  if ( v2 == 0 )
    return Func;
  return v3;
}

/* ---- FUNC 0000511C atexit ---- */
int __cdecl atexit(void (__cdecl *a1)())
{
  return (onexit((_onexit_t)a1) != nullptr) - 1;
}

/* ---- FUNC 00005134 __GSHandlerCheck ---- */
__int64 __fastcall _GSHandlerCheck(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  _GSHandlerCheckCommon(a2, a4);
  return 1;
}

/* ---- FUNC 00005154 __GSHandlerCheckCommon ---- */
__int64 __fastcall _GSHandlerCheckCommon(__int64 a1, __int64 a2)
{
  __int64 v2; // rcx
  __int64 result; // rax

  v2 = *(unsigned int *)(*(_QWORD *)(a2 + 16) + 8LL);
  result = *(_QWORD *)(a2 + 8);
  if ( (*(_BYTE *)(v2 + result + 3) & 0xF) != 0 )
    return *(_BYTE *)(v2 + result + 3) & 0xF0;
  return result;
}

/* ---- FUNC 000051B0 __GSHandlerCheck_EH4 ---- */
__int64 __fastcall _GSHandlerCheck_EH4(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // rbx
  __int64 result; // rax

  v4 = *(_QWORD *)(a4 + 56);
  _GSHandlerCheckCommon(a2, a4);
  result = 1;
  if ( ((((*(_DWORD *)(a1 + 4) & 0x66) != 0) + 1) & *(_DWORD *)(v4 + 4)) != 0 )
    return _CxxFrameHandler4(a1, a2, a3, a4);
  return result;
}

/* ---- FUNC 00005240 __alloca_probe ---- */
unsigned __int64 __fastcall _alloca_probe()
{
  unsigned __int64 result; // rax
  char *v1; // r10
  char *StackLimit; // r11
  char v3; // [rsp+18h] [rbp+8h] BYREF

  v1 = &v3 - result;
  if ( (unsigned __int64)&v3 < result )
    v1 = nullptr;
  StackLimit = (char *)NtCurrentTeb()->NtTib.StackLimit;
  if ( v1 < StackLimit )
  {
    LOWORD(v1) = (unsigned __int16)v1 & 0xF000;
    do
    {
      StackLimit -= 4096;
      *StackLimit = 0;
    }
    while ( v1 != StackLimit );
  }
  return result;
}

/* ---- FUNC 000052A0 __security_check_cookie ---- */
void __cdecl _security_check_cookie(uintptr_t StackCookie)
{
  __int64 v1; // rcx

  if ( StackCookie != _security_cookie )
ReportFailure:
    _report_gsfailure(StackCookie);
  v1 = __ROL8__(StackCookie, 16);
  if ( (_WORD)v1 != 0 )
  {
    StackCookie = __ROR8__(v1, 16);
    goto ReportFailure;
  }
}

/* ---- FUNC 000052C0 ?dllmain_crt_dispatch@@YAHQEAUHINSTANCE__@@KQEAX@Z ---- */
__int64 __fastcall dllmain_crt_dispatch(HINSTANCE a1, int a2, void *const a3)
{
  __int64 result; // rax

  switch ( a2 )
  {
    case 0:
      return dllmain_crt_process_detach(a3 != nullptr);
    case 1:
      return dllmain_crt_process_attach(a1, a3);
    case 2:
      LOBYTE(result) = _scrt_dllmain_crt_thread_attach();
      break;
    case 3:
      LOBYTE(result) = _scrt_dllmain_crt_thread_detach();
      break;
    default:
      return 1;
  }
  return (unsigned __int8)result;
}

/* ---- FUNC 00005310 ?dllmain_crt_process_attach@@YAHQEAUHINSTANCE__@@QEAX@Z ---- */
__int64 __fastcall dllmain_crt_process_attach(HINSTANCE a1, void *const a2)
{
  char v4; // bl
  char v5; // di
  _QWORD *dyn_tls_init_callback; // rax

  if ( _scrt_initialize_crt(0) == 0 )
    return 0;
  v4 = _scrt_acquire_startup_lock();
  v5 = 1;
  if ( _scrt_current_native_startup_state != 0 )
  {
    _scrt_fastfail(7u);
    __debugbreak();
  }
  _scrt_current_native_startup_state = 1;
  if ( _scrt_dllmain_before_initialize_c() )
  {
    RTC_Initialize();
    __scrt_initialize_type_info();
    _scrt_initialize_default_local_stdio_options();
    if ( initterm_e((_PIFV *)&_xi_a, (_PIFV *)&_xi_z) == 0 && _scrt_dllmain_after_initialize_c() != 0 )
    {
      initterm((_PVFV *)&_xc_a, (_PVFV *)&_xc_z);
      _scrt_current_native_startup_state = 2;
      v5 = 0;
    }
  }
  _scrt_release_startup_lock(v4);
  if ( v5 != 0 )
    return 0;
  dyn_tls_init_callback = _scrt_get_dyn_tls_init_callback();
  if ( *dyn_tls_init_callback != 0 && _scrt_is_nonwritable_in_current_image((__int64)dyn_tls_init_callback) )
    guard_dispatch_icall_nop(a1, 2, a2);
  ++__proc_attached;
  return 1;
}

/* ---- FUNC 00005428 ?dllmain_crt_process_detach@@YAH_N@Z ---- */
_BOOL8 __fastcall dllmain_crt_process_detach(char a1)
{
  char v3; // bl
  __int64 v4; // rcx
  BOOL v5; // ebx

  if ( __proc_attached <= 0 )
    return false;
  --__proc_attached;
  v3 = _scrt_acquire_startup_lock();
  if ( _scrt_current_native_startup_state != 2 )
  {
    _scrt_fastfail(7u);
    __debugbreak();
  }
  _scrt_dllmain_uninitialize_c();
  __scrt_uninitialize_type_info();
  RTC_Terminate();
  _scrt_current_native_startup_state = 0;
  _scrt_release_startup_lock(v3);
  LOBYTE(v4) = a1;
  v5 = _scrt_uninitialize_crt(v4, 0) != 0;
  _scrt_dllmain_uninitialize_critical();
  return v5;
}

/* ---- FUNC 000054AC ?dllmain_dispatch@@YAHQEAUHINSTANCE__@@KQEAX@Z ---- */
__int64 __fastcall dllmain_dispatch(HINSTANCE a1, DWORD a2, void *const a3)
{
  unsigned int v7; // ebx
  BOOL v8; // eax

  if ( a2 == 0 && __proc_attached <= 0 )
    return 0;
  if ( a2 - 1 > 1
    || (sub_1800010B0 == nullptr || (v7 = sub_1800010B0((__int64)a1, a2)) != 0)
    && (v7 = dllmain_crt_dispatch(a1, a2, a3)) != 0 )
  {
    v8 = DllMain(a1, a2, a3);
    v7 = v8;
    if ( a2 == 1 && !v8 )
    {
      DllMain(a1, 0, a3);
      dllmain_crt_process_detach(a3 != nullptr);
      if ( sub_1800010B0 != nullptr )
        sub_1800010B0((__int64)a1, 0);
    }
    if ( a2 == 0 || a2 == 3 )
    {
      v7 = dllmain_crt_dispatch(a1, a2, a3);
      if ( v7 != 0 )
      {
        if ( sub_1800010B0 != nullptr )
          return (unsigned int)sub_1800010B0((__int64)a1, a2);
        else
          return (unsigned int)sub_1800010B0 + 1;
      }
    }
  }
  return v7;
}

/* ---- FUNC 000055E0 DllEntryPoint ---- */
BOOL __stdcall DllEntryPoint(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{
  if ( fdwReason == 1 )
    _security_init_cookie();
  return dllmain_dispatch(hinstDLL, fdwReason, lpReserved);
}

/* ---- FUNC 00005620 __isa_available_init ---- */
int __cdecl _isa_available_init()
{
  int v5; // r11d
  int v6; // r9d
  int v7; // esi
  int v9; // r10d
  int v14; // edi
  int v15; // eax
  int v16; // eax
  __int64 v17; // rcx
  int v18; // r8d
  int v23; // eax
  char v25; // [rsp+20h] [rbp+8h]

  _RAX = 0;
  __asm { cpuid }
  v5 = 0;
  v6 = _RBX;
  v7 = _RAX;
  _RAX = 1;
  v9 = _RCX ^ 0x6C65746E | _RDX ^ 0x49656E69;
  __asm { cpuid }
  v14 = _RCX;
  if ( (v6 ^ 0x756E6547 | v9) == 0
    && ((_memset_nt_threshold = -1, v15 = _RAX & 0xFFF3FF0, _memset_fast_string_threshold = 0x8000, v15 == 67264)
     || v15 == 132704
     || v15 == 132720
     || (unsigned int)(v16 = v15 - 198224) <= 0x20 && (v17 = 0x100010001LL, _bittest64(&v17, (unsigned __int8)v16))) )
  {
    v18 = _favor | 1;
    _favor |= 1u;
  }
  else
  {
    v18 = _favor;
  }
  _RAX = 7;
  if ( v7 >= 7 )
  {
    __asm { cpuid }
    v5 = _RBX;
    if ( (_RBX & 0x200) != 0 )
      _favor = v18 | 2;
  }
  _isa_available = 1;
  _isa_enabled = 2;
  if ( (v14 & 0x100000) != 0 )
  {
    _isa_available = 2;
    _isa_enabled = 6;
    if ( (v14 & 0x8000000) != 0 && (v14 & 0x10000000) != 0 )
    {
      __asm { xgetbv }
      v25 = _RAX;
      if ( (_RAX & 6) == 6 )
      {
        v23 = _isa_enabled | 8;
        _isa_available = 3;
        _isa_enabled |= 8u;
        if ( (v5 & 0x20) != 0 )
        {
          _isa_available = 5;
          _isa_enabled = v23 | 0x20;
          if ( (v5 & 0xD0030000) == 0xD0030000 && (v25 & 0xE0) == 0xE0 )
          {
            _isa_enabled |= 0x40u;
            _isa_available = 6;
          }
        }
      }
    }
  }
  return 0;
}

/* ---- FUNC 000057CC _get_startup_argv_mode ---- */
_crt_argv_mode __cdecl get_startup_argv_mode()
{
  return _crt_argv_unexpanded_arguments;
}

/* ---- FUNC 000057D4 __scrt_is_ucrt_dll_in_use ---- */
_BOOL8 _scrt_is_ucrt_dll_in_use()
{
  return dword_18000B434 != 0;
}

/* ---- FUNC 000057E0 __crt_debugger_hook ---- */
void _crt_debugger_hook()
{
  dword_18000B7A4 = 0;
}

/* ---- FUNC 000057E8 __scrt_fastfail ---- */
void __fastcall _scrt_fastfail(unsigned int a1)
{
  ULONG64 Rip; // rbx
  struct _IMAGE_RUNTIME_FUNCTION_ENTRY *v3; // rax
  bool v4; // bl
  struct _EXCEPTION_POINTERS ExceptionInfo; // [rsp+40h] [rbp-C0h] BYREF
  _QWORD v6[20]; // [rsp+50h] [rbp-B0h] BYREF
  struct _CONTEXT ContextRecord; // [rsp+F0h] [rbp-10h] BYREF
  DWORD64 retaddr; // [rsp+5C8h] [rbp+4C8h]
  __int64 v9; // [rsp+5D0h] [rbp+4D0h] BYREF
  unsigned __int64 ImageBase; // [rsp+5D8h] [rbp+4D8h] BYREF
  unsigned __int64 EstablisherFrame; // [rsp+5E0h] [rbp+4E0h] BYREF
  PVOID HandlerData; // [rsp+5E8h] [rbp+4E8h] BYREF

  if ( IsProcessorFeaturePresent(0x17u) )
    __fastfail(a1);
  _crt_debugger_hook();
  memset(&ContextRecord, 0, sizeof(ContextRecord));
  RtlCaptureContext(&ContextRecord);
  Rip = ContextRecord.Rip;
  v3 = RtlLookupFunctionEntry(ContextRecord.Rip, &ImageBase, nullptr);
  if ( v3 != nullptr )
    RtlVirtualUnwind(0, ImageBase, Rip, v3, &ContextRecord, &HandlerData, &EstablisherFrame, nullptr);
  ContextRecord.Rip = retaddr;
  ContextRecord.Rsp = (DWORD64)&v9;
  memset(v6, 0, 0x98u);
  v6[2] = retaddr;
  v6[0] = 0x140000015LL;
  ExceptionInfo.ExceptionRecord = (PEXCEPTION_RECORD)v6;
  v4 = IsDebuggerPresent();
  ExceptionInfo.ContextRecord = &ContextRecord;
  SetUnhandledExceptionFilter(nullptr);
  if ( UnhandledExceptionFilter(&ExceptionInfo) == 0 && !v4 )
    _crt_debugger_hook();
}

/* ---- FUNC 00005934 __raise_securityfailure ---- */
BOOL __fastcall _raise_securityfailure(struct _EXCEPTION_POINTERS *ExceptionInfo)
{
  HANDLE CurrentProcess; // rax

  SetUnhandledExceptionFilter(nullptr);
  UnhandledExceptionFilter(ExceptionInfo);
  CurrentProcess = GetCurrentProcess();
  return TerminateProcess(CurrentProcess, 0xC0000409);
}

/* ---- FUNC 00005968 __report_gsfailure ---- */
void __cdecl __noreturn _report_gsfailure(uintptr_t StackCookie)
{
  DWORD64 retaddr; // [rsp+38h] [rbp+0h]
  uintptr_t v2; // [rsp+40h] [rbp+8h] BYREF

  v2 = StackCookie;
  if ( IsProcessorFeaturePresent(0x17u) )
    __fastfail(2u);
  capture_previous_context(&GS_ContextRecord);
  GS_ContextRecord.Rip = retaddr;
  GS_ContextRecord.Rsp = (DWORD64)&v2;
  qword_18000B7C0 = retaddr;
  GS_ContextRecord.Rcx = v2;
  GS_ExceptionRecord = -1073740791;
  dword_18000B7B4 = 1;
  dword_18000B7C8 = 1;
  unk_18000B7D0 = 2;
  _raise_securityfailure((struct _EXCEPTION_POINTERS *)&GS_ExceptionPointers);
}

/* ---- FUNC 00005A3C capture_previous_context ---- */
struct _IMAGE_RUNTIME_FUNCTION_ENTRY *__fastcall capture_previous_context(PCONTEXT ContextRecord)
{
  ULONG64 Rip; // rsi
  int i; // edi
  struct _IMAGE_RUNTIME_FUNCTION_ENTRY *result; // rax
  unsigned __int64 ImageBase; // [rsp+60h] [rbp+8h] BYREF
  unsigned __int64 EstablisherFrame; // [rsp+68h] [rbp+10h] BYREF
  PVOID HandlerData; // [rsp+70h] [rbp+18h] BYREF

  RtlCaptureContext(ContextRecord);
  Rip = ContextRecord->Rip;
  for ( i = 0; i < 2; ++i )
  {
    result = RtlLookupFunctionEntry(Rip, &ImageBase, nullptr);
    if ( result == nullptr )
      break;
    result = (struct _IMAGE_RUNTIME_FUNCTION_ENTRY *)RtlVirtualUnwind(
                                                       0,
                                                       ImageBase,
                                                       Rip,
                                                       result,
                                                       ContextRecord,
                                                       &HandlerData,
                                                       &EstablisherFrame,
                                                       nullptr);
  }
  return result;
}

/* ---- FUNC 00005AB0 __security_init_cookie ---- */
void __cdecl _security_init_cookie()
{
  uintptr_t v0; // rax
  struct _FILETIME v1; // [rsp+20h] [rbp-10h] BYREF
  struct _FILETIME SystemTimeAsFileTime; // [rsp+40h] [rbp+10h] BYREF
  LARGE_INTEGER PerformanceCount; // [rsp+48h] [rbp+18h] BYREF

  v0 = _security_cookie;
  if ( _security_cookie == 0x2B992DDFA232LL )
  {
    SystemTimeAsFileTime = 0;
    GetSystemTimeAsFileTime(&SystemTimeAsFileTime);
    v1 = SystemTimeAsFileTime;
    v1 = (struct _FILETIME)(GetCurrentThreadId() ^ *(unsigned __int64 *)&v1);
    v1 = (struct _FILETIME)(GetCurrentProcessId() ^ *(unsigned __int64 *)&v1);
    QueryPerformanceCounter(&PerformanceCount);
    v0 = ((unsigned __int64)&v1
        ^ *(_QWORD *)&v1
        ^ PerformanceCount.QuadPart
        ^ ((unsigned __int64)PerformanceCount.LowPart << 32))
       & 0xFFFFFFFFFFFFLL;
    if ( v0 == 0x2B992DDFA232LL )
      v0 = 0x2B992DDFA233LL;
    _security_cookie = v0;
  }
  _security_cookie_complement = ~v0;
}

/* ---- FUNC 00005B5C ?__scrt_initialize_type_info@@YAXXZ ---- */
void __scrt_initialize_type_info()
{
  InitializeSListHead(&__type_info_root_node);
}

/* ---- FUNC 00005B6C ?__scrt_uninitialize_type_info@@YAXXZ ---- */
__int64 __scrt_uninitialize_type_info()
{
  return _std_type_info_destroy_list(&__type_info_root_node);
}

/* ---- FUNC 00005B78 __local_stdio_scanf_options ---- */
unsigned __int64 *__cdecl _local_stdio_scanf_options()
{
  return (unsigned __int64 *)&`__local_stdio_scanf_options'::`2'::_OptionsStorage;
}

/* ---- FUNC 00005B80 __scrt_initialize_default_local_stdio_options ---- */
unsigned __int64 *_scrt_initialize_default_local_stdio_options()
{
  unsigned __int64 *v0; // rax
  unsigned __int64 *result; // rax

  v0 = _local_stdio_printf_options();
  *v0 |= 0x24u;
  result = _local_stdio_scanf_options();
  *result |= 2u;
  return result;
}

/* ---- FUNC 00005B9C __scrt_get_dyn_tls_init_callback ---- */
void *_scrt_get_dyn_tls_init_callback()
{
  return &_dyn_tls_init_callback;
}

/* ---- FUNC 00005BA4 _RTC_Initialize ---- */
void __cdecl RTC_Initialize()
{
  void (**i)(void); // rbx

  for ( i = &_rtc_izz; i < &_rtc_izz; ++i )
  {
    if ( *i != nullptr )
      (*i)();
  }
}

/* ---- FUNC 00005BE0 _RTC_Terminate ---- */
void __cdecl RTC_Terminate()
{
  void (**i)(void); // rbx

  for ( i = &_rtc_tzz; i < &_rtc_tzz; ++i )
  {
    if ( *i != nullptr )
      (*i)();
  }
}

/* ---- FUNC 00005C20 sub_180005C20 ---- */
__int64 __fastcall sub_180005C20(__int64 a1)
{
  signed int LastError; // eax
  signed int v3; // ecx

  memset((void *)(a1 + 40), 0, 0x28u);
  *(_QWORD *)(a1 + 80) = 0;
  *(_DWORD *)(a1 + 88) = 0;
  *(_DWORD *)(a1 + 92) = 0;
  *(_QWORD *)(a1 + 16) = 0x180000000uLL;
  *(_QWORD *)(a1 + 8) = 0x180000000uLL;
  *(_QWORD *)(a1 + 32) = &unk_180008318;
  *(_DWORD *)a1 = 96;
  *(_DWORD *)(a1 + 24) = 3584;
  if ( !InitializeCriticalSectionEx((LPCRITICAL_SECTION)(a1 + 40), 0, 0) )
  {
    LastError = GetLastError();
    v3 = (unsigned __int16)LastError | 0x80070000;
    if ( LastError <= 0 )
      v3 = LastError;
    if ( v3 < 0 )
    {
      if ( IsDebuggerPresent() )
        OutputDebugStringW(L"ERROR : Unable to initialize critical section in CAtlBaseModule\n");
      byte_18000B5A0 = 1;
    }
  }
  return a1;
}

/* ---- FUNC 00005CC8 sub_180005CC8 ---- */
void __fastcall sub_180005CC8(struct _RTL_CRITICAL_SECTION *a1)
{
  PRTL_CRITICAL_SECTION_DEBUG DebugInfo; // rcx

  DeleteCriticalSection(a1 + 1);
  DebugInfo = a1[2].DebugInfo;
  if ( DebugInfo != nullptr )
  {
    free(DebugInfo);
    a1[2].DebugInfo = nullptr;
  }
  a1[2].LockCount = 0;
  a1[2].RecursionCount = 0;
}

/* ---- FUNC 00005CFC VarBstrCat ---- */
// attributes: thunk
HRESULT __stdcall VarBstrCat(BSTR bstrLeft, BSTR bstrRight, LPBSTR pbstrResult)
{
  return __imp_VarBstrCat(bstrLeft, bstrRight, pbstrResult);
}

/* ---- FUNC 00005D10 sub_180005D10 ---- */
CHAR *__fastcall sub_180005D10(LPCWCH lpWideCharStr)
{
  __int64 v3; // rbx
  int v4; // eax
  int cbMultiByte; // r14d
  CHAR *lpMultiByteStr; // rax
  CHAR *v7; // rsi
  signed int LastError; // eax
  signed int v9; // eax

  if ( lpWideCharStr == nullptr )
    return nullptr;
  v3 = -1;
  do
    ++v3;
  while ( lpWideCharStr[v3] != 0 );
  v4 = WideCharToMultiByte(0, 0, lpWideCharStr, v3 + 1, nullptr, 0, nullptr, nullptr);
  cbMultiByte = v4;
  if ( v4 == 0 )
  {
    LastError = GetLastError();
    if ( LastError > 0 )
      LastError = (unsigned __int16)LastError | 0x80070000;
    sub_180005E30((unsigned int)LastError);
    __debugbreak();
  }
  try
  {
    lpMultiByteStr = (CHAR *)operator new[](v4);
  }
  catch ( ... )
  {
    goto LABEL_10;
  }
  v7 = lpMultiByteStr;
  if ( lpMultiByteStr == nullptr )
  {
LABEL_10:
    sub_180005E30(2147942414LL);
    __debugbreak();
  }
  if ( WideCharToMultiByte(0, 0, lpWideCharStr, v3 + 1, lpMultiByteStr, cbMultiByte, nullptr, nullptr) == 0 )
  {
    operator delete[](v7);
    v9 = GetLastError();
    if ( v9 > 0 )
      v9 = (unsigned __int16)v9 | 0x80070000;
    sub_180005E30((unsigned int)v9);
    JUMPOUT(0x180005E21LL);
  }
  return v7;
}

/* ---- FUNC 00005E30 sub_180005E30 ---- */
__int64 __fastcall sub_180005E30(__int64 a1)
{
  return ((__int64 (__fastcall *)(__int64, _QWORD))off_18000B428)(a1, 0);
}

/* ---- FUNC 00005E40 sub_180005E40 ---- */
__int64 __fastcall sub_180005E40(__int64 a1, __int64 a2)
{
  __int64 v3; // rcx

  *(_QWORD *)a1 = &off_1800083B8;
  *(_DWORD *)(a1 + 8) = *(_DWORD *)(a2 + 8);
  v3 = *(_QWORD *)(a2 + 16);
  *(_QWORD *)(a1 + 16) = v3;
  *(_QWORD *)(a1 + 24) = 0;
  if ( v3 != 0 )
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v3 + 8LL))(v3);
  return a1;
}

/* ---- FUNC 00005E90 sub_180005E90 ---- */
__int64 __fastcall sub_180005E90(__int64 a1, int a2, __int64 a3, char a4)
{
  *(_DWORD *)(a1 + 8) = a2;
  *(_QWORD *)a1 = &off_1800083B8;
  *(_QWORD *)(a1 + 16) = a3;
  *(_QWORD *)(a1 + 24) = 0;
  if ( a3 != 0 && a4 != 0 )
    (*(void (__fastcall **)(__int64))(*(_QWORD *)a3 + 8LL))(a3);
  return a1;
}

/* ---- FUNC 00005EE0 sub_180005EE0 ---- */
__int64 (__fastcall **__fastcall sub_180005EE0(_QWORD *a1))(void *)
{
  __int64 (__fastcall **result)(void *); // rax
  __int64 v3; // rcx
  void *v4; // rcx

  result = &off_1800083B8;
  *a1 = &off_1800083B8;
  v3 = a1[2];
  if ( v3 != 0 )
    result = (__int64 (__fastcall **)(void *))(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v3 + 16LL))(v3);
  v4 = (void *)a1[3];
  if ( v4 != nullptr )
    return (__int64 (__fastcall **)(void *))LocalFree(v4);
  return result;
}

/* ---- FUNC 00005F30 sub_180005F30 ---- */
_QWORD *__fastcall sub_180005F30(_QWORD *a1, char a2)
{
  __int64 v4; // rcx
  void *v5; // rcx

  *a1 = &off_1800083B8;
  v4 = a1[2];
  if ( v4 != 0 )
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v4 + 16LL))(v4);
  v5 = (void *)a1[3];
  if ( v5 != nullptr )
    LocalFree(v5);
  if ( (a2 & 1) != 0 )
    operator delete(a1);
  return a1;
}

/* ---- FUNC 00005F90 _guard_dispatch_icall_nop_0 ---- */
void __fastcall __noreturn guard_dispatch_icall_nop_0(int a1, __int64 a2)
{
  _BYTE pExceptionObject[40]; // [rsp+20h] [rbp-28h] BYREF

  sub_180005E90((__int64)pExceptionObject, a1, a2, 0);
  throw (_com_error *)pExceptionObject;
}

/* ---- FUNC 00005FB8 __std_terminate ---- */
// attributes: thunk
void __noreturn _std_terminate()
{
  __std_terminate();
}

/* ---- FUNC 00005FBE __CxxFrameHandler4 ---- */
// attributes: thunk
__int64 __fastcall _CxxFrameHandler4(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  return __CxxFrameHandler4(a1, a2, a3, a4);
}

/* ---- FUNC 00005FC4 _CxxThrowException ---- */
// attributes: thunk
void __stdcall __noreturn CxxThrowException(void *pExceptionObject, _ThrowInfo *pThrowInfo)
{
  _CxxThrowException(pExceptionObject, pThrowInfo);
}

/* ---- FUNC 00005FCA memset ---- */
// attributes: thunk
void *__cdecl memset(void *a1, int Val, size_t Size)
{
  return __imp_memset(a1, Val, Size);
}

/* ---- FUNC 00005FD0 __C_specific_handler ---- */
// attributes: thunk
EXCEPTION_DISPOSITION __cdecl _C_specific_handler(
        struct _EXCEPTION_RECORD *ExceptionRecord,
        void *EstablisherFrame,
        struct _CONTEXT *ContextRecord,
        struct _DISPATCHER_CONTEXT *DispatcherContext)
{
  return __C_specific_handler(ExceptionRecord, EstablisherFrame, ContextRecord, DispatcherContext);
}

/* ---- FUNC 00005FD6 __std_type_info_destroy_list ---- */
// attributes: thunk
__int64 __fastcall _std_type_info_destroy_list(__int64 a1)
{
  return __std_type_info_destroy_list(a1);
}

/* ---- FUNC 00005FDC free ---- */
// attributes: thunk
void __cdecl free(void *Block)
{
  __imp_free(Block);
}

/* ---- FUNC 00005FE2 _seh_filter_dll ---- */
// attributes: thunk
int __cdecl seh_filter_dll(unsigned int ExceptionNum, struct _EXCEPTION_POINTERS *ExceptionPtr)
{
  return _seh_filter_dll(ExceptionNum, ExceptionPtr);
}

/* ---- FUNC 00005FE8 _configure_narrow_argv ---- */
// attributes: thunk
errno_t __cdecl configure_narrow_argv(_crt_argv_mode mode)
{
  return _configure_narrow_argv(mode);
}

/* ---- FUNC 00005FEE _initialize_narrow_environment ---- */
// attributes: thunk
int __cdecl initialize_narrow_environment()
{
  return _initialize_narrow_environment();
}

/* ---- FUNC 00005FF4 _initialize_onexit_table ---- */
// attributes: thunk
int __cdecl initialize_onexit_table(_onexit_table_t *Table)
{
  return _initialize_onexit_table(Table);
}

/* ---- FUNC 00005FFA _register_onexit_function ---- */
// attributes: thunk
int __cdecl register_onexit_function(_onexit_table_t *Table, _onexit_t Function)
{
  return _register_onexit_function(Table, Function);
}

/* ---- FUNC 00006000 _execute_onexit_table ---- */
// attributes: thunk
int __cdecl execute_onexit_table(_onexit_table_t *Table)
{
  return _execute_onexit_table(Table);
}

/* ---- FUNC 00006006 _crt_atexit ---- */
// attributes: thunk
int __cdecl crt_atexit(_PVFV Function)
{
  return _crt_atexit(Function);
}

/* ---- FUNC 0000600C _cexit ---- */
// attributes: thunk
void __cdecl cexit()
{
  _cexit();
}

/* ---- FUNC 00006012 _initterm ---- */
// attributes: thunk
void __cdecl initterm(_PVFV *First, _PVFV *Last)
{
  _initterm(First, Last);
}

/* ---- FUNC 00006018 _initterm_e ---- */
// attributes: thunk
int __cdecl initterm_e(_PIFV *First, _PIFV *Last)
{
  return _initterm_e(First, Last);
}

/* ---- FUNC 0000601E ??_U@YAPEAX_K@Z ---- */
// attributes: thunk
void *__fastcall operator new[](unsigned __int64 a1)
{
  return __imp_??_U@YAPEAX_K@Z(a1);
}

/* ---- FUNC 00006024 __vcrt_thread_detach ---- */
// Alternative name is '__acrt_thread_attach'
// Alternative name is '__acrt_thread_detach'
// Alternative name is '__acrt_uninitialize'
// Alternative name is '__acrt_uninitialize_critical'
// Alternative name is '__vcrt_initialize'
// Alternative name is '__vcrt_thread_attach'
// Alternative name is '__acrt_initialize'
// Alternative name is '__vcrt_uninitialize'
// Alternative name is '__vcrt_uninitialize_critical'
__vcrt_bool __cdecl _vcrt_thread_detach()
{
  return true;
}

/* ---- FUNC 00006028 _is_c_termination_complete ---- */
int __cdecl is_c_termination_complete()
{
  return 0;
}

/* ---- FUNC 0000602B memcpy ---- */
// attributes: thunk
void *__cdecl memcpy(void *a1, const void *Src, size_t Size)
{
  return __imp_memcpy(a1, Src, Size);
}

/* ---- FUNC 00006050 _guard_dispatch_icall_nop ---- */
// attributes: thunk
__int64 __fastcall guard_dispatch_icall_nop(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 (__fastcall *v3)(__int64, __int64, __int64); // rax

  return v3(a1, a2, a3);
}

/* ---- FUNC 00006070 _guard_xfg_dispatch_icall_nop ---- */
// attributes: thunk
__int64 __fastcall guard_xfg_dispatch_icall_nop()
{
  __int64 (*v0)(void); // rax

  return v0();
}

/* ---- FUNC 00006080 sub_180006080 ---- */
void __fastcall sub_180006080(__int64 a1, __int64 a2)
{
  sub_1800011C0((BSTR *)(a2 + 128));
}

/* ---- FUNC 00006090 sub_180006090 ---- */
__int64 __fastcall sub_180006090(__int64 a1, __int64 a2)
{
  CException::Delete(*(CException **)(a2 + 48));
  return 0;
}

/* ---- FUNC 000060C0 sub_1800060C0 ---- */
HRESULT __fastcall sub_1800060C0(__int64 a1, __int64 a2)
{
  return VariantClear((VARIANTARG *)(a2 + 128));
}

/* ---- FUNC 000060D0 sub_1800060D0 ---- */
HRESULT __fastcall sub_1800060D0(__int64 a1, VARIANTARG *a2)
{
  return VariantClear(a2 + 5);
}

/* ---- FUNC 000060E0 sub_1800060E0 ---- */
HRESULT __fastcall sub_1800060E0(__int64 a1, __int64 a2)
{
  return VariantClear((VARIANTARG *)(a2 + 112));
}

/* ---- FUNC 000060F0 sub_1800060F0 ---- */
HRESULT __fastcall sub_1800060F0(__int64 a1, __int64 a2)
{
  return VariantClear((VARIANTARG *)(a2 + 104));
}

/* ---- FUNC 00006100 sub_180006100 ---- */
HRESULT __fastcall sub_180006100(__int64 a1, __int64 a2)
{
  return VariantClear((VARIANTARG *)(a2 + 136));
}

/* ---- FUNC 00006110 sub_180006110 ---- */
HRESULT __fastcall sub_180006110(__int64 a1, __int64 a2)
{
  return VariantClear((VARIANTARG *)(a2 + 80));
}

/* ---- FUNC 00006140 sub_180006140 ---- */
HRESULT __fastcall sub_180006140(__int64 a1, VARIANTARG *a2)
{
  return VariantClear(a2 + 6);
}

/* ---- FUNC 00006150 sub_180006150 ---- */
void __fastcall sub_180006150(__int64 a1, __int64 a2)
{
  sub_1800044C0(*(CDialog **)(a2 + 48));
}

/* ---- FUNC 00006160 sub_180006160 ---- */
void __fastcall sub_180006160(__int64 a1, __int64 a2)
{
  CTreeCtrl::~CTreeCtrl((CTreeCtrl *)(*(_QWORD *)(a2 + 48) + 336LL));
}

/* ---- FUNC 00006173 __scrt_is_nonwritable_in_current_image$filt$0 ---- */
_BOOL8 __fastcall _scrt_is_nonwritable_in_current_image$filt$0(_DWORD **a1)
{
  return **a1 == -1073741819;
}

/* ---- FUNC 0000618B ?fin$0@?0??dllmain_crt_process_attach@@YAHQEAUHINSTANCE__@@QEAX@Z@4HA ---- */
_BOOL8 __fastcall `dllmain_crt_process_attach'::`1'::fin$0(__int64 a1, __int64 a2)
{
  return _scrt_release_startup_lock(*(_BYTE *)(a2 + 64));
}

/* ---- FUNC 000061A2 ?fin$0@?0??dllmain_crt_process_detach@@YAH_N@Z@4HA ---- */
_BOOL8 __fastcall `dllmain_crt_process_detach'::`1'::fin$0(__int64 a1, __int64 a2)
{
  return _scrt_release_startup_lock(*(_BYTE *)(a2 + 32));
}

/* ---- FUNC 000061BB ?fin$1@?0??dllmain_crt_process_detach@@YAH_N@Z@4HA ---- */
__vcrt_bool `dllmain_crt_process_detach'::`1'::fin$1()
{
  return _scrt_dllmain_uninitialize_critical();
}

/* ---- FUNC 000061CF ?filt$0@?0??dllmain_dispatch@@YAHQEAUHINSTANCE__@@KQEAX@Z@4HA ---- */
int __fastcall `dllmain_dispatch'::`1'::filt$0(struct _EXCEPTION_POINTERS *ExceptionPtr, __int64 a2)
{
  return _scrt_dllmain_exception_filter(
           *(_QWORD *)(a2 + 96),
           *(_DWORD *)(a2 + 104),
           *(_QWORD *)(a2 + 112),
           (void (__fastcall *)(__int64, _QWORD, __int64))dllmain_crt_dispatch,
           ExceptionPtr->ExceptionRecord->ExceptionCode,
           ExceptionPtr);
}

/* ---- FUNC 00006210 sub_180006210 ---- */
__int64 sub_180006210()
{
  return 0;
}

/* ---- FUNC 00006230 sub_180006230 ---- */
void __fastcall sub_180006230()
{
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>>>((ATL::CStringT<char, class StrTraitMFC_DLL<char, class ATL::ChTraitsCRT<char>>> *)&unk_18000B728);
}

/* ---- FUNC 00006240 sub_180006240 ---- */
void __fastcall sub_180006240()
{
  sub_180005CC8((struct _RTL_CRITICAL_SECTION *)&unk_18000BD40);
}

/* ---- FUNC 00006250 sub_180006250 ---- */
void __fastcall sub_180006250()
{
  VariantClear(&stru_18000B410);
}
