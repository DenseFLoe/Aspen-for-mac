/* RVA 0x3c658 */
void FUN_18003c658(void)

{
  ulonglong *puVar1;
  
  puVar1 = (ulonglong *)FUN_180001b20();
  *puVar1 = *puVar1 | 0x24;
  puVar1 = (ulonglong *)FUN_180001b30();
  *puVar1 = *puVar1 | 2;
  return;
}

/* RVA 0x3c674 */
undefined * FUN_18003c674(void)

{
  return &DAT_1800538b8;
}

/* RVA 0x3c67c */
void FUN_18003c67c(void)

{
  longlong *plVar1;
  
  for (plVar1 = &DAT_180044d88; plVar1 < &DAT_180044d88; plVar1 = plVar1 + 1) {
    if (*plVar1 != 0) {
      (*(code *)PTR__guard_dispatch_icall_18003f628)();
    }
  }
  return;
}

/* RVA 0x3c6b8 */
void FUN_18003c6b8(void)

{
  longlong *plVar1;
  
  for (plVar1 = &DAT_180044d98; plVar1 < &DAT_180044d98; plVar1 = plVar1 + 1) {
    if (*plVar1 != 0) {
      (*(code *)PTR__guard_dispatch_icall_18003f628)();
    }
  }
  return;
}

/* RVA 0x3c700 */
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
  *(undefined **)(this + 0x20) = &DAT_180043f08;
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
      DAT_180051f74 = 1;
    }
  }
  return this;
}

/* RVA 0x3c7a8 */
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

/* RVA 0x3c7dc */
void __stdcall CoFreeUnusedLibraries(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003c7dc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CoFreeUnusedLibraries();
  return;
}

/* RVA 0x3c7e2 */
void __cdecl std::_Xlength_error(char *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00018003c7e2. Too many branches */
                    /* WARNING: Subroutine does not return */
                    /* WARNING: Treating indirect jump as call */
  _Xlength_error(param_1);
  return;
}

/* RVA 0x3c7f0 */
void FUN_18003c7f0(undefined8 param_1)

{
  (*(code *)PTR__guard_dispatch_icall_18003f628)(param_1,0);
  return;
}

/* RVA 0x3c800 */
LPSTR FUN_18003c800(LPCWSTR param_1)

{
  longlong lVar1;
  int cbMultiByte;
  int iVar2;
  uint uVar3;
  LPSTR lpMultiByteStr;
  longlong lVar4;
  
  if (param_1 == (LPCWSTR)0x0) {
    lpMultiByteStr = (LPSTR)0x0;
  }
  else {
    lVar1 = -1;
    do {
      lVar4 = lVar1;
      lVar1 = lVar4 + 1;
    } while (param_1[lVar1] != L'\0');
    iVar2 = (int)lVar4;
    cbMultiByte = WideCharToMultiByte(0,0,param_1,iVar2 + 2,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
    if (cbMultiByte == 0) {
      uVar3 = GetLastError();
      if (0 < (int)uVar3) {
        uVar3 = uVar3 & 0xffff | 0x80070000;
      }
                    /* WARNING: Subroutine does not return */
      FUN_18003c7f0((ulonglong)uVar3);
    }
    lpMultiByteStr = operator_new__((longlong)cbMultiByte);
    if (lpMultiByteStr == (LPSTR)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_18003c7f0(0x8007000e);
    }
    iVar2 = WideCharToMultiByte(0,0,param_1,iVar2 + 2,lpMultiByteStr,cbMultiByte,(LPCSTR)0x0,
                                (LPBOOL)0x0);
    if (iVar2 == 0) {
      operator_delete__(lpMultiByteStr);
      uVar3 = GetLastError();
      if (0 < (int)uVar3) {
        uVar3 = uVar3 & 0xffff | 0x80070000;
      }
                    /* WARNING: Subroutine does not return */
      FUN_18003c7f0((ulonglong)uVar3);
    }
  }
  return lpMultiByteStr;
}

/* RVA 0x3c920 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

BSTR FUN_18003c920(LPCSTR param_1)

{
  size_t _Size;
  int iVar1;
  int iVar2;
  uint uVar3;
  OLECHAR *psz;
  BSTR pOVar4;
  longlong lVar6;
  longlong lVar5;
  ulonglong uVar7;
  undefined1 *puVar8;
  undefined1 auStackY_68 [32];
  int local_38;
  int iStack_34;
  OLECHAR *local_30;
  ulonglong local_28;
  
  puVar8 = auStackY_68;
  local_28 = DAT_1800516d8 ^ (ulonglong)&local_38;
  if (param_1 == (LPCSTR)0x0) {
    pOVar4 = (BSTR)0x0;
LAB_18003c952:
    *(undefined8 *)(puVar8 + -8) = 0x18003c95e;
    return pOVar4;
  }
  lVar5 = -1;
  do {
    lVar6 = lVar5;
    lVar5 = lVar6 + 1;
  } while (param_1[lVar5] != '\0');
  uVar7 = lVar6 + 2;
  if (0x7fffffff < uVar7) {
                    /* WARNING: Subroutine does not return */
    FUN_18003c7f0(0x80070057);
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
    FUN_18003c7f0((ulonglong)uVar3);
  }
  _Size = (longlong)iVar1 * 2;
  if (iVar1 < 0x1000) {
    uVar7 = _Size + 0xf;
    if (uVar7 <= _Size) {
      uVar7 = 0xffffffffffffff0;
    }
    puVar8 = auStackY_68 + -(uVar7 & 0xfffffffffffffff0);
    psz = (OLECHAR *)((longlong)&local_38 + -(uVar7 & 0xfffffffffffffff0));
  }
  else {
    psz = malloc(_Size);
    puVar8 = auStackY_68;
  }
  local_30 = psz;
  if (psz != (OLECHAR *)0x0) {
    *(int *)(puVar8 + 0x28) = iVar1;
    *(OLECHAR **)(puVar8 + 0x20) = psz;
    *(undefined8 *)(puVar8 + -8) = 0x18003ca2f;
    iVar2 = MultiByteToWideChar(0,0,param_1,iVar2,*(LPWSTR *)(puVar8 + 0x20),*(int *)(puVar8 + 0x28)
                               );
    if (iVar2 == 0) {
      if (0xfff < iVar1) {
        *(undefined8 *)(puVar8 + -8) = 0x18003ca9e;
        free(psz);
      }
      *(undefined8 *)(puVar8 + -8) = 0x18003caa4;
      uVar3 = GetLastError();
      if (0 < (int)uVar3) {
        uVar3 = uVar3 & 0xffff | 0x80070000;
      }
                    /* WARNING: Subroutine does not return */
      *(undefined **)(puVar8 + -8) = &UNK_18003cab7;
      FUN_18003c7f0((ulonglong)uVar3);
    }
    *(undefined8 *)(puVar8 + -8) = 0x18003ca3c;
    pOVar4 = SysAllocString(psz);
    if (0xfff < iVar1) {
      *(undefined8 *)(puVar8 + -8) = 0x18003ca50;
      free(psz);
    }
    if (pOVar4 != (BSTR)0x0) goto LAB_18003c952;
  }
                    /* WARNING: Subroutine does not return */
  *(undefined **)(puVar8 + -8) = &UNK_18003ca67;
  FUN_18003c7f0(0x8007000e);
}

/* RVA 0x3cac0 */
/* Library Function - Single Match
    public: __cdecl _com_error::_com_error(class _com_error const & __ptr64) __ptr64
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

_com_error * __thiscall _com_error::_com_error(_com_error *this,_com_error *param_1)

{
  longlong lVar1;
  
  *(undefined ***)this = &PTR__scalar_deleting_destructor__180043fa8;
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  lVar1 = *(longlong *)(param_1 + 0x10);
  *(longlong *)(this + 0x10) = lVar1;
  *(undefined8 *)(this + 0x18) = 0;
  if (lVar1 != 0) {
    (*(code *)PTR__guard_dispatch_icall_18003f628)();
  }
  return this;
}

/* RVA 0x3cb10 */
/* Library Function - Single Match
    public: __cdecl _com_error::_com_error(long,struct IErrorInfo * __ptr64,bool) __ptr64
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

_com_error * __thiscall
_com_error::_com_error(_com_error *this,long param_1,IErrorInfo *param_2,bool param_3)

{
  *(long *)(this + 8) = param_1;
  *(undefined ***)this = &PTR__scalar_deleting_destructor__180043fa8;
  *(IErrorInfo **)(this + 0x10) = param_2;
  *(undefined8 *)(this + 0x18) = 0;
  if ((param_2 != (IErrorInfo *)0x0) && (param_3)) {
    (*(code *)PTR__guard_dispatch_icall_18003f628)(param_2);
  }
  return this;
}

/* RVA 0x3cb60 */
/* Library Function - Single Match
    public: virtual __cdecl _com_error::~_com_error(void) __ptr64
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __thiscall _com_error::~_com_error(_com_error *this)

{
  *(undefined ***)this = &PTR__scalar_deleting_destructor__180043fa8;
  if (*(longlong *)(this + 0x10) != 0) {
    (*(code *)PTR__guard_dispatch_icall_18003f628)();
  }
  if (*(HLOCAL *)(this + 0x18) == (HLOCAL)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00018003cb97. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LocalFree(*(HLOCAL *)(this + 0x18));
  return;
}

/* RVA 0x3cbb0 */
/* Library Function - Single Match
    public: virtual void * __ptr64 __cdecl _com_error::`scalar deleting destructor'(unsigned int)
   __ptr64
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void * __thiscall _com_error::_scalar_deleting_destructor_(_com_error *this,uint param_1)

{
  *(undefined ***)this = &PTR__scalar_deleting_destructor__180043fa8;
  if (*(longlong *)(this + 0x10) != 0) {
    (*(code *)PTR__guard_dispatch_icall_18003f628)();
  }
  if (*(HLOCAL *)(this + 0x18) != (HLOCAL)0x0) {
    LocalFree(*(HLOCAL *)(this + 0x18));
  }
  if ((param_1 & 1) != 0) {
    FUN_180001300(this);
  }
  return this;
}

/* RVA 0x3cc10 */
void FUN_18003cc10(long param_1,IErrorInfo *param_2)

{
  _com_error local_28 [40];
  
  _com_error::_com_error(local_28,param_1,param_2,false);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_28,(ThrowInfo *)&DAT_180048780);
}

/* RVA 0x3cc38 */
void __CxxFrameHandler4(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003cc38. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __CxxFrameHandler4();
  return;
}

/* RVA 0x3cc3e */
void * __cdecl memset(void *_Dst,int _Val,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003cc3e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memset(_Dst,_Val,_Size);
  return pvVar1;
}

/* RVA 0x3cc44 */
char * __cdecl strstr(char *_Str,char *_SubStr)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003cc44. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = strstr(_Str,_SubStr);
  return pcVar1;
}

/* RVA 0x3cc4a */
void * __cdecl memcpy(void *_Dst,void *_Src,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003cc4a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memcpy(_Dst,_Src,_Size);
  return pvVar1;
}

/* RVA 0x3cc50 */
char * __cdecl strchr(char *_Str,int _Val)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003cc50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = strchr(_Str,_Val);
  return pcVar1;
}

/* RVA 0x3cc56 */
void __std_exception_copy(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003cc56. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __std_exception_copy();
  return;
}

/* RVA 0x3cc5c */
void __std_exception_destroy(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003cc5c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __std_exception_destroy();
  return;
}

/* RVA 0x3cc62 */
void __stdcall _CxxThrowException(void *pExceptionObject,ThrowInfo *pThrowInfo)

{
                    /* WARNING: Could not recover jumptable at 0x00018003cc62. Too many branches */
                    /* WARNING: Subroutine does not return */
                    /* WARNING: Treating indirect jump as call */
  _CxxThrowException(pExceptionObject,pThrowInfo);
  return;
}

/* RVA 0x3cc68 */
int __cdecl memcmp(void *_Buf1,void *_Buf2,size_t _Size)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003cc68. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = memcmp(_Buf1,_Buf2,_Size);
  return iVar1;
}

/* RVA 0x3cc6e */
void * __cdecl memmove(void *_Dst,void *_Src,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003cc6e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memmove(_Dst,_Src,_Size);
  return pvVar1;
}

/* RVA 0x3cc74 */
char * __cdecl strrchr(char *_Str,int _Ch)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003cc74. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = strrchr(_Str,_Ch);
  return pcVar1;
}

/* RVA 0x3cc7a */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003cc7a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}

/* RVA 0x3cc80 */
void __std_type_info_destroy_list(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003cc80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __std_type_info_destroy_list();
  return;
}

/* RVA 0x3cc86 */
void __current_exception(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003cc86. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __current_exception();
  return;
}

/* RVA 0x3cc8c */
void __current_exception_context(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003cc8c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __current_exception_context();
  return;
}

/* RVA 0x3cc92 */
void __cdecl free(void *_Memory)

{
                    /* WARNING: Could not recover jumptable at 0x00018003cc92. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  free(_Memory);
  return;
}

/* RVA 0x3cc98 */
void * __cdecl malloc(size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003cc98. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = malloc(_Size);
  return pvVar1;
}

/* RVA 0x3cc9e */
int __cdecl strcmp(char *_Str1,char *_Str2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003cc9e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = strcmp(_Str1,_Str2);
  return iVar1;
}

/* RVA 0x3cca4 */
void _seh_filter_dll(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003cca4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _seh_filter_dll();
  return;
}

/* RVA 0x3ccaa */
void _configure_narrow_argv(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ccaa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _configure_narrow_argv();
  return;
}

/* RVA 0x3ccb0 */
void _initialize_narrow_environment(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ccb0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _initialize_narrow_environment();
  return;
}

/* RVA 0x3ccb6 */
void _initialize_onexit_table(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ccb6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _initialize_onexit_table();
  return;
}

/* RVA 0x3ccbc */
void _register_onexit_function(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ccbc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _register_onexit_function();
  return;
}

/* RVA 0x3ccc2 */
void _execute_onexit_table(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ccc2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _execute_onexit_table();
  return;
}

/* RVA 0x3ccc8 */
void _crt_atexit(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ccc8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _crt_atexit();
  return;
}

/* RVA 0x3ccce */
void __cdecl _cexit(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ccce. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _cexit();
  return;
}

/* RVA 0x3ccd4 */
void terminate(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ccd4. Too many branches */
                    /* WARNING: Subroutine does not return */
                    /* WARNING: Treating indirect jump as call */
  terminate();
  return;
}

/* RVA 0x3ccda */
void _initterm(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ccda. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _initterm();
  return;
}

/* RVA 0x3cce0 */
void _initterm_e(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003cce0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _initterm_e();
  return;
}

/* RVA 0x3cce6 */
char * __cdecl _getcwd(char *_DstBuf,int _SizeInBytes)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003cce6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = _getcwd(_DstBuf,_SizeInBytes);
  return pcVar1;
}

/* RVA 0x3ccec */
int __cdecl _chdir(char *_Path)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003ccec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = _chdir(_Path);
  return iVar1;
}

/* RVA 0x3ccf4 */
undefined1 FUN_18003ccf4(void)

{
  return 1;
}

/* RVA 0x3cd10 */
/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x00018003cd10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

/* RVA 0x3cd30 */
/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  (*(code *)PTR__guard_dispatch_icall_18003f628)();
  return;
}

/* RVA 0x3cd50 */
undefined8 FUN_18003cd50(void)

{
  return 0;
}

/* RVA 0x3cd80 */
undefined8 FUN_18003cd80(void)

{
  return 0;
}

/* RVA 0x3cda0 */
void FUN_18003cda0(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x30) & 1) != 0) {
    *(uint *)(param_2 + 0x30) = *(uint *)(param_2 + 0x30) & 0xfffffffe;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              (*(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)(param_2 + 0x50));
  }
  return;
}

/* RVA 0x3cdf0 */
void FUN_18003cdf0(undefined8 param_1,longlong param_2)

{
  FUN_180001300(*(void **)(param_2 + 0x40));
  return;
}

/* RVA 0x3ce80 */
void FUN_18003ce80(undefined8 param_1,longlong param_2)

{
  FUN_180001300(*(void **)(param_2 + 0x38));
  return;
}

/* RVA 0x3ceb0 */
bool FUN_18003ceb0(undefined8 *param_1)

{
  return *(int *)*param_1 == -0x3fffff03;
}

/* RVA 0x3cfa0 */
void FUN_18003cfa0(undefined8 param_1,longlong param_2)

{
  FUN_1800045e0(*(longlong **)(param_2 + 0x88),*(longlong **)(param_2 + 0x28));
  FUN_180006100(*(undefined8 *)(param_2 + 0x70),*(void **)(param_2 + 0x20),
                *(longlong *)(param_2 + 0x78));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}

/* RVA 0x3cff0 */
void FUN_18003cff0(undefined8 param_1,longlong param_2)

{
  FUN_1800045e0(*(longlong **)(param_2 + 200),*(longlong **)(param_2 + 0x30));
  FUN_180006100(*(undefined8 *)(param_2 + 0xb0),*(void **)(param_2 + 0xb8),
                *(longlong *)(param_2 + 0x38));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}

/* RVA 0x3d040 */
void FUN_18003d040(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  longlong *plVar2;
  
  lVar1 = *(longlong *)(param_2 + 0x20);
  plVar2 = *(longlong **)(param_2 + 0xb8);
  FUN_1800045e0((longlong *)(*(longlong *)(param_2 + 200) * 0x20 + lVar1),(longlong *)*plVar2);
  *plVar2 = lVar1;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}

/* RVA 0x3d090 */
void FUN_18003d090(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  CSimSeqObj *pCVar2;
  longlong *plVar3;
  longlong *plVar4;
  
  lVar1 = *(longlong *)(param_2 + 200);
  pCVar2 = *(CSimSeqObj **)(param_2 + 0x20);
  FUN_180005600(pCVar2 + lVar1 * 0x20,pCVar2 + lVar1 * 0x40,pCVar2);
  plVar3 = *(longlong **)(param_2 + 0xb8);
  FUN_180004d90((longlong)(pCVar2 + lVar1 * 0x40),*plVar3,pCVar2 + lVar1 * 0x20);
  plVar4 = *(longlong **)(param_2 + 0x38);
  FUN_1800045e0(plVar4,(longlong *)*plVar3);
  *plVar3 = (longlong)plVar4;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}

/* RVA 0x3d120 */
void FUN_18003d120(undefined8 param_1,longlong param_2)

{
  undefined8 *puVar1;
  
  puVar1 = *(undefined8 **)(param_2 + 0xb8);
  FUN_1800045e0(*(longlong **)(param_2 + 200),(longlong *)*puVar1);
  *puVar1 = *(undefined8 *)(param_2 + 0x20);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}

/* RVA 0x3d160 */
void FUN_18003d160(undefined8 param_1,longlong param_2)

{
  undefined8 *puVar1;
  CSimSeqObj *pCVar2;
  
  puVar1 = *(undefined8 **)(param_2 + 0xb8);
  pCVar2 = *(CSimSeqObj **)(param_2 + 200);
  FUN_180005600(pCVar2,(CSimSeqObj *)*puVar1,*(CSimSeqObj **)(param_2 + 0x20));
  FUN_1800045e0((longlong *)pCVar2,(longlong *)*puVar1);
  *puVar1 = *(undefined8 *)(param_2 + 0x38);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}

/* RVA 0x3d1f0 */
void FUN_18003d1f0(undefined8 param_1,longlong param_2)

{
  FUN_180006100(*(undefined8 *)(param_2 + 0x90),*(void **)(param_2 + 0x80),
                *(longlong *)(param_2 + 0x88));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}

/* RVA 0x3d280 */
undefined8 FUN_18003d280(void)

{
  return 0;
}

/* RVA 0x3d2c0 */
void FUN_18003d2c0(undefined8 param_1,longlong param_2)

{
  deallocate(*(undefined8 *)(param_2 + 0x60),*(void **)(param_2 + 0x78),
             *(longlong *)(param_2 + 0x68));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}

/* RVA 0x3d300 */
void FUN_18003d300(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x30) & 1) != 0) {
    *(uint *)(param_2 + 0x30) = *(uint *)(param_2 + 0x30) & 0xfffffffe;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0x38));
  }
  return;
}

/* RVA 0x3d340 */
void FUN_18003d340(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x40) & 1) != 0) {
    *(uint *)(param_2 + 0x40) = *(uint *)(param_2 + 0x40) & 0xfffffffe;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0x30));
  }
  return;
}

/* RVA 0x3d370 */
void FUN_18003d370(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x40) & 2) != 0) {
    *(uint *)(param_2 + 0x40) = *(uint *)(param_2 + 0x40) & 0xfffffffd;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0x38));
  }
  return;
}

/* RVA 0x3d3a0 */
void FUN_18003d3a0(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x40) & 4) != 0) {
    *(uint *)(param_2 + 0x40) = *(uint *)(param_2 + 0x40) & 0xfffffffb;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0x38));
  }
  return;
}

/* RVA 0x3d3d0 */
void FUN_18003d3d0(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x40) & 8) != 0) {
    *(uint *)(param_2 + 0x40) = *(uint *)(param_2 + 0x40) & 0xfffffff7;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0x30));
  }
  return;
}

/* RVA 0x3d400 */
void FUN_18003d400(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x40) & 0x10) != 0) {
    *(uint *)(param_2 + 0x40) = *(uint *)(param_2 + 0x40) & 0xffffffef;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0x38));
  }
  return;
}

/* RVA 0x3d430 */
void FUN_18003d430(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x40) & 0x20) != 0) {
    *(uint *)(param_2 + 0x40) = *(uint *)(param_2 + 0x40) & 0xffffffdf;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0x48));
  }
  return;
}

/* RVA 0x3d460 */
void FUN_18003d460(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x40) & 0x40) != 0) {
    *(uint *)(param_2 + 0x40) = *(uint *)(param_2 + 0x40) & 0xffffffbf;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0x30));
  }
  return;
}

/* RVA 0x3d4e0 */
void FUN_18003d4e0(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x60) & 1) != 0) {
    *(uint *)(param_2 + 0x60) = *(uint *)(param_2 + 0x60) & 0xfffffffe;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_2 + 0x70));
  }
  return;
}

/* RVA 0x3d507 */
bool FUN_18003d507(undefined8 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}

/* RVA 0x3d51f */
void FUN_18003d51f(undefined8 param_1,longlong param_2)

{
  if (*(char *)(param_2 + 0x20) == '\0') {
    __ArrayUnwind(*(void **)(param_2 + 0x60),*(__uint64 *)(param_2 + 0x68),
                  *(__uint64 *)(param_2 + 0x70),*(_func_void_void_ptr **)(param_2 + 0x78));
  }
  return;
}

/* RVA 0x3d54b */
undefined4 FUN_18003d54b(undefined8 param_1,longlong param_2)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  *(undefined8 *)(param_2 + 0x40) = param_1;
  *(undefined8 *)(param_2 + 0x30) = param_1;
  *(undefined8 *)(param_2 + 0x28) = **(undefined8 **)(param_2 + 0x30);
  if (**(int **)(param_2 + 0x28) == -0x1f928c9d) {
    puVar2 = (undefined8 *)__current_exception();
    *puVar2 = *(undefined8 *)(param_2 + 0x28);
    uVar1 = *(undefined8 *)(*(longlong *)(param_2 + 0x30) + 8);
    puVar2 = (undefined8 *)__current_exception_context();
    *puVar2 = uVar1;
                    /* WARNING: Subroutine does not return */
    terminate();
  }
  *(undefined4 *)(param_2 + 0x20) = 0;
  return *(undefined4 *)(param_2 + 0x20);
}

/* RVA 0x3d5aa */
void FUN_18003d5aa(undefined8 param_1,longlong param_2)

{
  __scrt_release_startup_lock(*(char *)(param_2 + 0x40));
  return;
}

/* RVA 0x3d5c1 */
void FUN_18003d5c1(undefined8 param_1,longlong param_2)

{
  __scrt_release_startup_lock(*(char *)(param_2 + 0x20));
  return;
}

/* RVA 0x3d5da */
void FUN_18003d5da(void)

{
  FUN_18003bb5c();
  return;
}

/* RVA 0x3d5ee */
void FUN_18003d5ee(undefined8 *param_1,longlong param_2)

{
  __scrt_dllmain_exception_filter
            (*(undefined8 *)(param_2 + 0x60),*(int *)(param_2 + 0x68),
             *(undefined8 *)(param_2 + 0x70),FUN_18003bf40,*(undefined4 *)*param_1,param_1);
  return;
}

/* RVA 0x3d630 */
undefined8 FUN_18003d630(void)

{
  return 0;
}

/* RVA 0x3d680 */
void FUN_18003d680(void)

{
  PTR_vftable_18004f620 = (undefined *)CSimSeqTree::vftable;
  FUN_1800058b0(&DAT_18004f628);
  return;
}

/* RVA 0x3d6b0 */
void FUN_18003d6b0(void)

{
  PTR_vftable_18004f5e0 = (undefined *)CSimSeqTree::vftable;
  FUN_1800058b0(&DAT_18004f5e8);
  return;
}

/* RVA 0x3d6d0 */
void FUN_18003d6d0(void)

{
  char cVar1;
  longlong *plVar2;
  longlong *plVar3;
  
  cVar1 = *(char *)((longlong)*(longlong **)((longlong)DAT_180051bd0 + 8) + 0x19);
  plVar3 = *(longlong **)((longlong)DAT_180051bd0 + 8);
  while (cVar1 == '\0') {
    FUN_1800047a0(&DAT_180051bd0,&DAT_180051bd0,(longlong *)plVar3[2]);
    plVar2 = (longlong *)*plVar3;
    FUN_180005800(plVar3 + 4);
    FUN_180001300(plVar3);
    plVar3 = plVar2;
    cVar1 = *(char *)((longlong)plVar2 + 0x19);
  }
  FUN_180001300(DAT_180051bd0);
  return;
}

/* RVA 0x3d750 */
void FUN_18003d750(void)

{
  PTR_vftable_18004f6c0 = (undefined *)CSimSeqTree::vftable;
  FUN_1800058b0(&DAT_18004f6c8);
  return;
}

/* RVA 0x3d7b0 */
void FUN_18003d7b0(void)

{
  void *pvVar1;
  
  if (DAT_180051dd8 != (void *)0x0) {
    pvVar1 = DAT_180051dd8;
    if ((0xfff < (DAT_180051de8 - (longlong)DAT_180051dd8 & 0xfffffffffffffff8U)) &&
       (pvVar1 = *(void **)((longlong)DAT_180051dd8 + -8),
       0x1f < (ulonglong)((longlong)DAT_180051dd8 + (-8 - (longlong)pvVar1)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180001300(pvVar1);
    DAT_180051dd8 = (void *)0x0;
    DAT_180051de0 = 0;
    DAT_180051de8 = 0;
  }
  return;
}

/* RVA 0x3d820 */
void FUN_18003d820(void)

{
  void *pvVar1;
  
  if (DAT_180051df0 != (void *)0x0) {
    pvVar1 = DAT_180051df0;
    if ((0xfff < (DAT_180051e00 - (longlong)DAT_180051df0 & 0xfffffffffffffff8U)) &&
       (pvVar1 = *(void **)((longlong)DAT_180051df0 + -8),
       0x1f < (ulonglong)((longlong)DAT_180051df0 + (-8 - (longlong)pvVar1)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180001300(pvVar1);
    DAT_180051df0 = (void *)0x0;
    DAT_180051df8 = 0;
    DAT_180051e00 = 0;
  }
  return;
}

/* RVA 0x3d890 */
void FUN_18003d890(void)

{
  void *pvVar1;
  
  if (DAT_180051e20 != (void *)0x0) {
    pvVar1 = DAT_180051e20;
    if ((0xfff < (DAT_180051e30 - (longlong)DAT_180051e20 & 0xfffffffffffffff8U)) &&
       (pvVar1 = *(void **)((longlong)DAT_180051e20 + -8),
       0x1f < (ulonglong)((longlong)DAT_180051e20 + (-8 - (longlong)pvVar1)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180001300(pvVar1);
    DAT_180051e20 = (void *)0x0;
    DAT_180051e28 = 0;
    DAT_180051e30 = 0;
  }
  return;
}

/* RVA 0x3d900 */
void FUN_18003d900(void)

{
  void *pvVar1;
  
  if (DAT_180051e08 != (void *)0x0) {
    pvVar1 = DAT_180051e08;
    if ((0xfff < (DAT_180051e18 - (longlong)DAT_180051e08 & 0xfffffffffffffff8U)) &&
       (pvVar1 = *(void **)((longlong)DAT_180051e08 + -8),
       0x1f < (ulonglong)((longlong)DAT_180051e08 + (-8 - (longlong)pvVar1)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180001300(pvVar1);
    DAT_180051e08 = (void *)0x0;
    DAT_180051e10 = 0;
    DAT_180051e18 = 0;
  }
  return;
}

/* RVA 0x3d990 */
void FUN_18003d990(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003d997. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  VariantClear((VARIANTARG *)&DAT_180051718);
  return;
}

