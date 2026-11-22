/* ---- FUNC 00030F20 MMGetLMSectionKey (190 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

HKEY MMGetLMSectionKey(LPCSTR param_1)

{
  HKEY hKey;
  HKEY pHVar1;
  undefined1 auStackY_448 [32];
  HKEY local_418 [2];
  undefined1 local_408 [1008];
  ulonglong local_18;
  
                    /* 0x30f20  138  MMGetLMSectionKey */
  local_18 = DAT_1800791f8 ^ (ulonglong)auStackY_448;
  if (param_1 == (LPCSTR)0x0) {
    FUN_180007de0(local_408,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\reghelper.cpp",0x48);
    LogMessage(local_408,2,1);
  }
  FUN_180031520();
  local_418[0] = (HKEY)0x0;
  hKey = MMGetLMAppRegistryKey();
  pHVar1 = (HKEY)0x0;
  if (hKey != (HKEY)0x0) {
    RegOpenKeyExA(hKey,param_1,0,0x20019,local_418);
    RegCloseKey(hKey);
    pHVar1 = local_418[0];
  }
  return pHVar1;
}

/* ---- FUNC 00030FE0 MMGetProfileInt (293 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* int __cdecl MMGetProfileInt(char const * __ptr64,char const * __ptr64,int) */

int __cdecl MMGetProfileInt(char *param_1,char *param_2,int param_3)

{
  LSTATUS LVar1;
  HKEY__ *hKey;
  undefined1 auStackY_448 [32];
  DWORD local_418;
  DWORD local_414;
  int local_410 [2];
  undefined1 local_408 [1008];
  ulonglong local_18;
  
                    /* 0x30fe0  139  ?MMGetProfileInt@@YAHPEBD0H@Z */
  local_18 = DAT_1800791f8 ^ (ulonglong)auStackY_448;
  if ((DAT_180072218 != 0) && (hKey = GetSectionKey(param_1), hKey != (HKEY__ *)0x0)) {
    local_418 = 4;
    LVar1 = RegQueryValueExA(hKey,param_2,(LPDWORD)0x0,&local_414,(LPBYTE)local_410,&local_418);
    RegCloseKey(hKey);
    if (LVar1 == 0) {
      if (local_414 != 4) {
        FUN_180007de0(local_408,"Assert failed in file %s line %d",
                      "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\reghelper.cpp",0x1b5);
        LogMessage(local_408,2,1);
      }
      param_3 = local_410[0];
      if (local_418 != 4) {
        FUN_180007de0(local_408,"Assert failed in file %s line %d",
                      "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\reghelper.cpp",0x1b6);
        LogMessage(local_408,2,1);
        param_3 = local_410[0];
      }
    }
  }
  return param_3;
}

/* ---- FUNC 00031110 MMReplaceEnvironmentVariables (672 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* char const * __ptr64 __cdecl MMReplaceEnvironmentVariables(char const * __ptr64) */

char * __cdecl MMReplaceEnvironmentVariables(char *param_1)

{
  char ****ppppcVar1;
  ulonglong uVar2;
  DWORD DVar3;
  LSTATUS LVar4;
  LSTATUS LVar5;
  ulonglong uVar6;
  void *pvVar7;
  size_t sVar8;
  char *pcVar9;
  HKEY__ *hKey;
  undefined4 extraout_var;
  longlong *****lpName;
  char *****pppppcVar10;
  int iVar11;
  ulonglong uVar12;
  undefined4 uVar13;
  size_t sVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  int iVar17;
  bool bVar18;
  undefined1 auStack_1c8 [8];
  ulonglong uStack_1c0;
  undefined4 auStack_1b0 [2];
  char ****local_190;
  undefined8 uStack_188;
  ulonglong local_180;
  ulonglong local_178;
  longlong ****local_170;
  undefined8 uStack_168;
  undefined8 local_160;
  char *local_158;
  CHAR local_148;
  char acStack_147 [271];
  ulonglong local_38;
  
                    /* 0x31110  144  ?MMReplaceEnvironmentVariables@@YAPEBDPEBD@Z */
  local_38 = DAT_1800791f8 ^ (ulonglong)auStack_1c8;
  uVar6 = 0;
  local_190 = (char ****)0x0;
  uStack_188 = 0;
  local_180 = 0;
  local_178 = 0;
  sVar14 = 0xffffffffffffffff;
  do {
    sVar14 = sVar14 + 1;
  } while (param_1[sVar14] != '\0');
  lpName = (longlong *****)&local_190;
  FUN_18000b5f0(lpName,param_1,sVar14);
  do {
    uVar15 = local_178;
    uVar2 = local_180;
    ppppcVar1 = local_190;
    uVar13 = (undefined4)sVar14;
    uVar6 = (ulonglong)(int)uVar6;
    bVar18 = 0xf < local_178;
    pppppcVar10 = &local_190;
    if (bVar18) {
      pppppcVar10 = (char *****)local_190;
    }
    if (uVar6 < local_180) {
      sVar14 = local_180 - uVar6;
      lpName = (longlong *****)((longlong)pppppcVar10 + uVar6);
      param_1 = (char *)0x25;
      pvVar7 = memchr(lpName,0x25,sVar14);
      uVar13 = (undefined4)sVar14;
      if (pvVar7 == (void *)0x0) goto LAB_1800311ca;
      uVar12 = (longlong)pvVar7 - (longlong)pppppcVar10;
    }
    else {
LAB_1800311ca:
      uVar12 = 0xffffffffffffffff;
    }
    iVar11 = (int)uVar12;
    if (iVar11 < 0) goto LAB_180031321;
    uVar16 = (ulonglong)(iVar11 + 1);
    pppppcVar10 = &local_190;
    if (bVar18) {
      pppppcVar10 = (char *****)ppppcVar1;
    }
    if (uVar16 < uVar2) {
      sVar14 = uVar2 - uVar16;
      lpName = (longlong *****)((longlong)pppppcVar10 + uVar16);
      param_1 = (char *)0x25;
      pvVar7 = memchr(lpName,0x25,sVar14);
      uVar13 = (undefined4)sVar14;
      if (pvVar7 == (void *)0x0) goto LAB_180031213;
      uVar6 = (longlong)pvVar7 - (longlong)pppppcVar10;
    }
    else {
LAB_180031213:
      uVar6 = 0xffffffffffffffff;
    }
    if ((int)uVar6 == 0) {
LAB_180031321:
      pppppcVar10 = &local_190;
      if (0xf < uVar15) {
        pppppcVar10 = (char *****)ppppcVar1;
      }
      pcVar9 = _strdup((char *)pppppcVar10);
      if (0xf < local_178) {
        pppppcVar10 = (char *****)local_190;
        if ((0xfff < local_178 + 1) &&
           (pppppcVar10 = (char *****)local_190[-1],
           (char *)0x1f < (char *)((longlong)local_190 + (-8 - (longlong)pppppcVar10)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        operator_delete(pppppcVar10);
      }
      return pcVar9;
    }
    local_170 = (longlong ****)0x0;
    uStack_168 = 0;
    local_160 = 0;
    local_158 = (char *)0x0;
    if (uVar2 < uVar16) {
      uVar6 = FUN_180031710();
      if (DAT_180072218 != 0) {
        uStack_1c0 = uVar12;
        auStack_1b0[0] = uVar13;
        hKey = GetSectionKey((char *)lpName);
        uVar6 = 0;
        if (hKey != (HKEY__ *)0x0) {
          LVar4 = RegSetValueExA(hKey,param_1,0,4,(BYTE *)auStack_1b0,4);
          LVar5 = RegCloseKey(hKey);
          return (char *)CONCAT71((int7)(CONCAT44(extraout_var,LVar5) >> 8),LVar4 == 0);
        }
      }
      return (char *)(uVar6 & 0xffffffffffffff00);
    }
    iVar17 = (int)uVar6 - iVar11;
    uVar15 = (ulonglong)(iVar17 + -1);
    if (uVar2 - uVar16 < uVar15) {
      uVar15 = uVar2 - uVar16;
    }
    pppppcVar10 = &local_190;
    if (bVar18) {
      pppppcVar10 = (char *****)ppppcVar1;
    }
    FUN_18000b5f0(&local_170,(char *)((longlong)pppppcVar10 + uVar16),uVar15);
    lpName = &local_170;
    if ((char *)0xf < local_158) {
      lpName = (longlong *****)local_170;
    }
    sVar14 = 0x104;
    DVar3 = GetEnvironmentVariableA((LPCSTR)lpName,&local_148,0x104);
    if (DVar3 != 0) {
      sVar14 = 0xffffffffffffffff;
      do {
        sVar8 = sVar14 + 1;
        pcVar9 = acStack_147 + sVar14;
        sVar14 = sVar8;
      } while (*pcVar9 != '\0');
      sVar14 = (size_t)(iVar17 + 1);
      lpName = (longlong *****)&local_190;
      FUN_180031730((longlong *)lpName,(longlong)iVar11,sVar14,&local_148,sVar8);
      uVar6 = uVar12 & 0xffffffff;
    }
    param_1 = local_158;
    if ((char *)0xf < local_158) {
      param_1 = local_158 + 1;
      lpName = (longlong *****)local_170;
      if ((char *)0xfff < param_1) {
        param_1 = local_158 + 0x28;
        lpName = (longlong *****)local_170[-1];
        if (0x1f < (ulonglong)((longlong)local_170 + (-8 - (longlong)lpName))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
      }
      operator_delete(lpName);
    }
  } while( true );
}

/* ---- FUNC 000313B0 MMWriteProfileInt (120 bytes) ---- */

/* bool __cdecl MMWriteProfileInt(char const * __ptr64,char const * __ptr64,int) */

bool __cdecl MMWriteProfileInt(char *param_1,char *param_2,int param_3)

{
  LSTATUS LVar1;
  HKEY__ *hKey;
  int local_res18 [4];
  
                    /* 0x313b0  150  ?MMWriteProfileInt@@YA_NPEBD0H@Z */
  if (DAT_180072218 != 0) {
    local_res18[0] = param_3;
    hKey = GetSectionKey(param_1);
    if (hKey != (HKEY__ *)0x0) {
      LVar1 = RegSetValueExA(hKey,param_2,0,4,(BYTE *)local_res18,4);
      RegCloseKey(hKey);
      return LVar1 == 0;
    }
  }
  return false;
}

/* ---- FUNC 00031430 MMWriteProfileString (233 bytes) ---- */

/* bool __cdecl MMWriteProfileString(char const * __ptr64,char const * __ptr64,char const * __ptr64)
    */

bool __cdecl MMWriteProfileString(char *param_1,char *param_2,char *param_3)

{
  LSTATUS LVar1;
  int iVar2;
  HKEY__ *pHVar3;
  
                    /* 0x31430  151  ?MMWriteProfileString@@YA_NPEBD00@Z */
  if (DAT_180072218 != 0) {
    if (param_2 == (char *)0x0) {
      pHVar3 = GetAppRegistryKey();
      if (pHVar3 != (HKEY__ *)0x0) {
        LVar1 = RegDeleteKeyA(pHVar3,param_1);
        RegCloseKey(pHVar3);
        return LVar1 == 0;
      }
    }
    else {
      pHVar3 = GetSectionKey(param_1);
      if (param_3 == (char *)0x0) {
        if (pHVar3 != (HKEY__ *)0x0) {
          LVar1 = RegDeleteValueA(pHVar3,param_2);
          RegCloseKey(pHVar3);
          return LVar1 == 0;
        }
      }
      else if (pHVar3 != (HKEY__ *)0x0) {
        iVar2 = lstrlenA(param_3);
        LVar1 = RegSetValueExA(pHVar3,param_2,0,1,(BYTE *)param_3,iVar2 + 1);
        RegCloseKey(pHVar3);
        return LVar1 == 0;
      }
    }
  }
  return false;
}

/* ---- FUNC 00031520 FUN_180031520 (483 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180031520(void)

{
  undefined2 *puVar1;
  void *pvVar2;
  undefined8 ****ppppuVar3;
  char **ppcVar4;
  void *_Dst;
  char **ppcVar5;
  ulonglong _Size;
  size_t sVar6;
  undefined1 auStackY_68 [32];
  undefined8 ***local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  ulonglong local_20;
  ulonglong local_18;
  
  local_18 = DAT_1800791f8 ^ (ulonglong)auStackY_68;
  if (DAT_180072238 == 0) {
    pvVar2 = (void *)FUN_180024130();
    local_38 = (undefined8 ****)0x0;
    uStack_30 = 0;
    local_28 = 0;
    local_20 = 0;
    _Size = 0xffffffffffffffff;
    sVar6 = 0xffffffffffffffff;
    do {
      sVar6 = sVar6 + 1;
    } while (*(char *)((longlong)pvVar2 + sVar6) != '\0');
    FUN_18000b5f0(&local_38,pvVar2,sVar6);
    if (local_20 == local_28) {
      FUN_180017f00(&local_38,1,0,&DAT_180053ef4,1);
    }
    else {
      ppppuVar3 = &local_38;
      if (0xf < local_20) {
        ppppuVar3 = (undefined8 ****)local_38;
      }
      puVar1 = (undefined2 *)((longlong)ppppuVar3 + local_28);
      local_28 = local_28 + 1;
      *puVar1 = 0x5c;
    }
    pvVar2 = (void *)FUN_180024170();
    do {
      _Size = _Size + 1;
    } while (*(char *)((longlong)pvVar2 + _Size) != '\0');
    if (local_20 - local_28 < _Size) {
      FUN_180017f00(&local_38,_Size,0,pvVar2,_Size);
    }
    else {
      ppppuVar3 = &local_38;
      if (0xf < local_20) {
        ppppuVar3 = (undefined8 ****)local_38;
      }
      _Dst = (void *)((longlong)ppppuVar3 + local_28);
      local_28 = local_28 + _Size;
      memmove(_Dst,pvVar2,_Size);
      *(undefined1 *)((longlong)_Dst + _Size) = 0;
    }
    ppcVar5 = &DAT_180072228;
    FUN_18002c730((longlong *)&DAT_180072228,(longlong *)&local_38);
    ppcVar4 = &DAT_180072208;
    if (0xf < DAT_180072220) {
      ppcVar4 = (char **)DAT_180072208;
    }
    SetGlobalPointer("RegistryKey",(char *)ppcVar4,1);
    if (0xf < DAT_180072240) {
      ppcVar5 = (char **)DAT_180072228;
    }
    SetGlobalPointer("ProfileName",(char *)ppcVar5,1);
    if (0xf < local_20) {
      ppppuVar3 = (undefined8 ****)local_38;
      if ((0xfff < local_20 + 1) &&
         (ppppuVar3 = (undefined8 ****)local_38[-1],
         0x1f < (ulonglong)((longlong)local_38 + (-8 - (longlong)ppppuVar3)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      operator_delete(ppppuVar3);
    }
  }
  return;
}

/* ---- FUNC 00031710 FUN_180031710 (17 bytes) ---- */

void FUN_180031710(void)

{
  code *pcVar1;
  
  std::_Xout_of_range("invalid string position");
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

/* ---- FUNC 00031730 FUN_180031730 (35 bytes) ---- */

longlong *
FUN_180031730(longlong *param_1,ulonglong param_2,ulonglong param_3,void *param_4,size_t param_5)

{
  void *pvVar1;
  void *_Src;
  ulonglong uVar2;
  code *pcVar3;
  longlong *plVar4;
  size_t _Size;
  ulonglong uVar5;
  ulonglong uVar6;
  
  uVar2 = param_1[2];
  if (uVar2 < param_2) {
    FUN_180031710();
    pcVar3 = (code *)swi(3);
    plVar4 = (longlong *)(*pcVar3)();
    return plVar4;
  }
  uVar5 = uVar2 - param_2;
  if (uVar5 < param_3) {
    param_3 = uVar5;
  }
  if (param_3 == param_5) {
    plVar4 = param_1;
    if (0xf < (ulonglong)param_1[3]) {
      plVar4 = (longlong *)*param_1;
    }
    memmove((void *)((longlong)plVar4 + param_2),param_4,param_5);
  }
  else if (param_5 < param_3) {
    plVar4 = param_1;
    if (0xf < (ulonglong)param_1[3]) {
      plVar4 = (longlong *)*param_1;
    }
    pvVar1 = (void *)((longlong)plVar4 + param_2);
    memmove(pvVar1,param_4,param_5);
    memmove((void *)((longlong)pvVar1 + param_5),(void *)((longlong)pvVar1 + param_3),
            (uVar5 - param_3) + 1);
    param_1[2] = (uVar2 - param_3) + param_5;
  }
  else {
    uVar6 = param_5 - param_3;
    if (param_1[3] - uVar2 < uVar6) {
      param_1 = FUN_18002ff20(param_1,uVar6,0,param_2,param_3,param_4,param_5);
    }
    else {
      param_1[2] = uVar2 + uVar6;
      plVar4 = param_1;
      if (0xf < (ulonglong)param_1[3]) {
        plVar4 = (longlong *)*param_1;
      }
      pvVar1 = (void *)((longlong)plVar4 + param_2);
      _Src = (void *)((longlong)pvVar1 + param_3);
      _Size = param_5;
      if ((pvVar1 < (void *)((longlong)param_4 + param_5)) &&
         (param_4 <= (void *)((longlong)plVar4 + uVar2))) {
        if (param_4 < _Src) {
          _Size = (longlong)_Src - (longlong)param_4;
        }
        else {
          _Size = 0;
        }
      }
      memmove((void *)((longlong)_Src + uVar6),_Src,(uVar5 - param_3) + 1);
      memmove(pvVar1,param_4,_Size);
      memcpy((void *)(_Size + (longlong)pvVar1),(void *)(_Size + uVar6 + (longlong)param_4),
             param_5 - _Size);
    }
  }
  return param_1;
}

/* ---- FUNC 00031753 FUN_180031753 (73 bytes) ---- */

void FUN_180031753(longlong *param_1,size_t param_2,ulonglong param_3,longlong param_4)

{
  void *pvVar1;
  void *_Src;
  longlong in_RAX;
  longlong lVar2;
  size_t _Size;
  ulonglong unaff_RBP;
  undefined8 unaff_RSI;
  longlong unaff_RDI;
  undefined8 unaff_R12;
  ulonglong uVar3;
  ulonglong uVar4;
  void *unaff_R14;
  longlong unaff_R15;
  size_t in_stack_00000090;
  
  *(undefined8 *)(in_RAX + 0x18) = unaff_RSI;
  *(undefined8 *)(in_RAX + 0x20) = unaff_R12;
  uVar3 = unaff_R15 - param_2;
  if (uVar3 < param_3) {
    unaff_RBP = uVar3;
  }
  if (unaff_RBP == in_stack_00000090) {
    if (0xf < (ulonglong)param_1[3]) {
      param_1 = (longlong *)*param_1;
    }
    memmove((void *)((longlong)param_1 + param_2),unaff_R14,in_stack_00000090);
  }
  else if (in_stack_00000090 < unaff_RBP) {
    lVar2 = unaff_RDI;
    if (0xf < (ulonglong)param_1[3]) {
      lVar2 = *param_1;
    }
    pvVar1 = (void *)(lVar2 + param_2);
    memmove(pvVar1,unaff_R14,in_stack_00000090);
    memmove((void *)((longlong)pvVar1 + in_stack_00000090),(void *)((longlong)pvVar1 + unaff_RBP),
            (uVar3 - unaff_RBP) + 1);
    *(ulonglong *)(unaff_RDI + 0x10) = (unaff_R15 - unaff_RBP) + in_stack_00000090;
  }
  else {
    uVar4 = in_stack_00000090 - unaff_RBP;
    if ((ulonglong)(param_1[3] - unaff_R15) < uVar4) {
      FUN_18002ff20(param_1,uVar4,0,param_2,unaff_RBP,unaff_R14,in_stack_00000090);
    }
    else {
      param_1[2] = unaff_R15 + uVar4;
      if (0xf < (ulonglong)param_1[3]) {
        param_1 = (longlong *)*param_1;
      }
      pvVar1 = (void *)((longlong)param_1 + param_2);
      _Src = (void *)((longlong)pvVar1 + unaff_RBP);
      _Size = in_stack_00000090;
      if ((pvVar1 < (void *)(param_4 + in_stack_00000090)) &&
         (unaff_R14 <= (void *)((longlong)param_1 + unaff_R15))) {
        if (unaff_R14 < _Src) {
          _Size = (longlong)_Src - (longlong)unaff_R14;
        }
        else {
          _Size = 0;
        }
      }
      memmove((void *)((longlong)_Src + uVar4),_Src,(uVar3 - unaff_RBP) + 1);
      memmove(pvVar1,unaff_R14,_Size);
      memcpy((void *)(_Size + (longlong)pvVar1),(void *)(_Size + uVar4 + (longlong)unaff_R14),
             in_stack_00000090 - _Size);
    }
  }
  return;
}

/* ---- FUNC 0003179C FUN_18003179c (81 bytes) ---- */

void FUN_18003179c(longlong *param_1,size_t param_2,undefined8 param_3,longlong param_4)

{
  void *pvVar1;
  void *_Src;
  longlong lVar2;
  size_t _Size;
  ulonglong unaff_RBP;
  ulonglong unaff_RSI;
  longlong unaff_RDI;
  longlong unaff_R12;
  ulonglong uVar3;
  void *unaff_R14;
  longlong unaff_R15;
  
  if (unaff_RSI < unaff_RBP) {
    lVar2 = unaff_RDI;
    if (0xf < (ulonglong)param_1[3]) {
      lVar2 = *param_1;
    }
    pvVar1 = (void *)(lVar2 + param_2);
    memmove(pvVar1,unaff_R14,unaff_RSI);
    memmove((void *)((longlong)pvVar1 + unaff_RSI),(void *)((longlong)pvVar1 + unaff_RBP),
            unaff_R12 + 1);
    *(ulonglong *)(unaff_RDI + 0x10) = (unaff_R15 - unaff_RBP) + unaff_RSI;
  }
  else {
    uVar3 = unaff_RSI - unaff_RBP;
    if ((ulonglong)(param_1[3] - unaff_R15) < uVar3) {
      FUN_18002ff20(param_1,uVar3,0,param_2,unaff_RBP,unaff_R14,unaff_RSI);
    }
    else {
      param_1[2] = unaff_R15 + uVar3;
      if (0xf < (ulonglong)param_1[3]) {
        param_1 = (longlong *)*param_1;
      }
      pvVar1 = (void *)((longlong)param_1 + param_2);
      _Src = (void *)((longlong)pvVar1 + unaff_RBP);
      _Size = unaff_RSI;
      if ((pvVar1 < (void *)(param_4 + unaff_RSI)) &&
         (unaff_R14 <= (void *)((longlong)param_1 + unaff_R15))) {
        if (unaff_R14 < _Src) {
          _Size = (longlong)_Src - (longlong)unaff_R14;
        }
        else {
          _Size = 0;
        }
      }
      memmove((void *)((longlong)_Src + uVar3),_Src,unaff_R12 + 1);
      memmove(pvVar1,unaff_R14,_Size);
      memcpy((void *)(_Size + (longlong)pvVar1),(void *)(_Size + uVar3 + (longlong)unaff_R14),
             unaff_RSI - _Size);
    }
  }
  return;
}

/* ---- FUNC 000317ED FUN_1800317ed (188 bytes) ---- */

void FUN_1800317ed(undefined8 *param_1,size_t param_2,ulonglong param_3,longlong param_4)

{
  void *_Dst;
  void *_Src;
  size_t _Size;
  longlong unaff_RBP;
  size_t unaff_RSI;
  longlong unaff_R12;
  ulonglong uVar1;
  void *unaff_R14;
  longlong unaff_R15;
  
  uVar1 = unaff_RSI - unaff_RBP;
  if (param_3 - unaff_R15 < uVar1) {
    FUN_18002ff20(param_1,uVar1,0,param_2,unaff_RBP,unaff_R14,unaff_RSI);
  }
  else {
    param_1[2] = unaff_R15 + uVar1;
    if (0xf < param_3) {
      param_1 = (undefined8 *)*param_1;
    }
    _Dst = (void *)((longlong)param_1 + param_2);
    _Src = (void *)((longlong)_Dst + unaff_RBP);
    _Size = unaff_RSI;
    if ((_Dst < (void *)(param_4 + unaff_RSI)) &&
       (unaff_R14 <= (void *)((longlong)param_1 + unaff_R15))) {
      if (unaff_R14 < _Src) {
        _Size = (longlong)_Src - (longlong)unaff_R14;
      }
      else {
        _Size = 0;
      }
    }
    memmove((void *)((longlong)_Src + uVar1),_Src,unaff_R12 + 1);
    memmove(_Dst,unaff_R14,_Size);
    memcpy((void *)(_Size + (longlong)_Dst),(void *)(_Size + uVar1 + (longlong)unaff_R14),
           unaff_RSI - _Size);
  }
  return;
}

/* ---- FUNC 000318A9 FUN_1800318a9 (5 bytes) ---- */

void FUN_1800318a9(void)

{
  return;
}

/* ---- FUNC 000318AE FUN_1800318ae (27 bytes) ---- */

void FUN_1800318ae(void)

{
  return;
}

/* ---- FUNC 000318C9 FUN_1800318c9 (6 bytes) ---- */

void FUN_1800318c9(void)

{
  code *pcVar1;
  
  FUN_180031710();
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

/* ---- FUNC 000318D0 FUN_1800318d0 (35 bytes) ---- */

void FUN_1800318d0(undefined8 param_1,undefined8 param_2,longlong *param_3)

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
    FUN_1800318d0(param_1,param_2,(longlong *)param_3[2]);
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

/* ---- FUNC 000318F3 FUN_1800318f3 (134 bytes) ---- */

void FUN_1800318f3(void)

{
  longlong *plVar1;
  void *pvVar2;
  void *pvVar3;
  undefined8 unaff_RBP;
  undefined8 unaff_RSI;
  longlong *unaff_RDI;
  
  do {
    FUN_1800318d0(unaff_RBP,unaff_RSI,(longlong *)unaff_RDI[2]);
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

/* ---- FUNC 00031979 FUN_180031979 (16 bytes) ---- */

void FUN_180031979(void)

{
  return;
}

/* ---- FUNC 00031989 _invalid_parameter_noinfo_noreturn (6 bytes) ---- */

void __cdecl _invalid_parameter_noinfo_noreturn(void)

{
                    /* WARNING: Subroutine does not return */
  _invalid_parameter_noinfo_noreturn();
}

/* ---- FUNC 00031990 FUN_180031990 (842 bytes) ---- */

longlong * FUN_180031990(longlong *param_1,longlong *param_2,longlong *param_3,undefined8 *param_4)

{
  char cVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong *plVar4;
  uint uVar5;
  byte *pbVar6;
  byte *pbVar7;
  longlong *plVar8;
  longlong *local_res8;
  longlong local_80;
  longlong lStack_78;
  longlong local_70;
  longlong local_68 [4];
  longlong local_48 [4];
  
  plVar8 = (longlong *)*param_1;
  if (*(char *)((longlong)param_3 + 0x19) == '\0') {
    local_res8 = local_48;
    if (param_3 == (longlong *)*plVar8) {
      pbVar6 = (byte *)FUN_180018500(local_48,param_3 + 4);
      pbVar7 = (byte *)FUN_180018500(local_68,param_4);
      uVar5 = FUN_180032150(param_1,pbVar7,pbVar6);
      if ((char)uVar5 != '\0') {
        *param_2 = (longlong)param_3;
        *(undefined4 *)(param_2 + 1) = 1;
        *(undefined1 *)(param_2 + 2) = 0;
        return param_2;
      }
    }
    else {
      pbVar6 = (byte *)FUN_180018500(local_48,param_3 + 4);
      pbVar7 = (byte *)FUN_180018500(local_68,param_4);
      uVar5 = FUN_180032150(param_1,pbVar7,pbVar6);
      if ((char)uVar5 == '\0') {
        local_res8 = local_48;
        pbVar6 = (byte *)FUN_180018500(local_48,param_4);
        pbVar7 = (byte *)FUN_180018500(local_68,param_3 + 4);
        uVar5 = FUN_180032150(param_1,pbVar7,pbVar6);
        if ((char)uVar5 == '\0') {
          *param_2 = (longlong)param_3;
          *(undefined1 *)(param_2 + 2) = 1;
          goto LAB_180031cb4;
        }
        local_res8 = param_3;
        plVar8 = FUN_180009890((longlong *)&local_res8);
        lVar2 = *plVar8;
        if (*(char *)(lVar2 + 0x19) != '\0') {
LAB_180031c82:
          cVar1 = *(char *)(param_3[2] + 0x19);
          *(undefined1 *)(param_2 + 2) = 0;
          if (cVar1 != '\0') {
            *param_2 = (longlong)param_3;
            *(undefined4 *)(param_2 + 1) = 0;
            return param_2;
          }
          *param_2 = lVar2;
          *(undefined4 *)(param_2 + 1) = 1;
          return param_2;
        }
        pbVar6 = (byte *)FUN_180018500(local_48,(undefined8 *)(lVar2 + 0x20));
        pbVar7 = (byte *)FUN_180018500(local_68,param_4);
        uVar5 = FUN_180032150(param_1,pbVar7,pbVar6);
        if ((char)uVar5 != '\0') goto LAB_180031c82;
      }
      else {
        if (*(char *)((longlong)param_3 + 0x19) == '\0') {
          plVar8 = (longlong *)*param_3;
          if (*(char *)((longlong)plVar8 + 0x19) == '\0') {
            cVar1 = *(char *)(plVar8[2] + 0x19);
            plVar3 = (longlong *)plVar8[2];
            while (cVar1 == '\0') {
              cVar1 = *(char *)(plVar3[2] + 0x19);
              plVar8 = plVar3;
              plVar3 = (longlong *)plVar3[2];
            }
          }
          else {
            cVar1 = *(char *)(param_3[1] + 0x19);
            plVar4 = (longlong *)param_3[1];
            plVar3 = param_3;
            while ((plVar8 = plVar4, cVar1 == '\0' && (plVar3 == (longlong *)*plVar8))) {
              cVar1 = *(char *)(plVar8[1] + 0x19);
              plVar4 = (longlong *)plVar8[1];
              plVar3 = plVar8;
            }
            if (*(char *)((longlong)plVar3 + 0x19) != '\0') {
              plVar8 = plVar3;
            }
          }
        }
        else {
          plVar8 = (longlong *)param_3[2];
        }
        local_res8 = local_48;
        pbVar6 = (byte *)FUN_180018500(local_48,param_4);
        pbVar7 = (byte *)FUN_180018500(local_68,plVar8 + 4);
        uVar5 = FUN_180032150(param_1,pbVar7,pbVar6);
        if ((char)uVar5 != '\0') {
          cVar1 = *(char *)(plVar8[2] + 0x19);
          *(undefined1 *)(param_2 + 2) = 0;
          if (cVar1 != '\0') {
            *param_2 = (longlong)plVar8;
            *(undefined4 *)(param_2 + 1) = 0;
            return param_2;
          }
          *param_2 = (longlong)param_3;
          *(undefined4 *)(param_2 + 1) = 1;
          return param_2;
        }
      }
    }
LAB_180031c15:
    FUN_180031ce0(param_1,&local_80,param_4);
    if (*(char *)(local_70 + 0x19) == '\0') {
      local_res8 = local_48;
      pbVar6 = (byte *)FUN_180018500(local_48,(undefined8 *)(local_70 + 0x20));
      pbVar7 = (byte *)FUN_180018500(local_68,param_4);
      uVar5 = FUN_180032150(param_1,pbVar7,pbVar6);
      if ((char)uVar5 == '\0') {
        *param_2 = local_70;
        *(undefined4 *)(param_2 + 1) = 2;
        *(undefined1 *)(param_2 + 2) = 1;
        return param_2;
      }
    }
    *param_2 = local_80;
    param_2[1] = lStack_78;
    *(undefined1 *)(param_2 + 2) = 0;
  }
  else {
    if (*(char *)(plVar8[1] + 0x19) == '\0') {
      local_res8 = local_68;
      pbVar6 = (byte *)FUN_180018500(local_68,param_4);
      pbVar7 = (byte *)FUN_180018500(local_48,(undefined8 *)(plVar8[2] + 0x20));
      uVar5 = FUN_180032150(param_1,pbVar7,pbVar6);
      if ((char)uVar5 == '\0') goto LAB_180031c15;
    }
    *param_2 = plVar8[2];
    *(undefined1 *)(param_2 + 2) = 0;
LAB_180031cb4:
    *(undefined4 *)(param_2 + 1) = 0;
  }
  return param_2;
}

/* ---- FUNC 00031CE0 FUN_180031ce0 (711 bytes) ---- */

undefined8 * FUN_180031ce0(longlong *param_1,undefined8 *param_2,undefined8 *param_3)

{
  ulonglong uVar1;
  longlong lVar2;
  ulonglong uVar3;
  int iVar4;
  byte ****ppppbVar5;
  byte ****ppppbVar6;
  byte ****ppppbVar7;
  ulonglong uVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  byte ***local_78;
  undefined8 uStack_70;
  ulonglong local_68;
  ulonglong local_60;
  byte ***local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  ulonglong local_40;
  
  lVar2 = *param_1;
  puVar10 = *(undefined8 **)(lVar2 + 8);
  *param_2 = puVar10;
  *(undefined4 *)(param_2 + 1) = 0;
  param_2[2] = lVar2;
  do {
    if (*(char *)((longlong)puVar10 + 0x19) != '\0') {
      return param_2;
    }
    *param_2 = puVar10;
    local_78 = (byte ***)0x0;
    uStack_70 = 0;
    local_68 = 0;
    local_60 = 0;
    puVar9 = param_3;
    if (0xf < (ulonglong)param_3[3]) {
      puVar9 = (undefined8 *)*param_3;
    }
    uVar3 = param_3[2];
    if (0x7fffffffffffffff < uVar3) {
                    /* WARNING: Subroutine does not return */
      FUN_18000ace0();
    }
    local_60 = 0xf;
    if (uVar3 < 0x10) {
      local_78 = (byte ***)*puVar9;
      uStack_70 = puVar9[1];
      local_68 = uVar3;
    }
    else {
      uVar8 = uVar3 | 0xf;
      if (uVar8 < 0x8000000000000000) {
        if (uVar8 < 0x16) {
          uVar8 = 0x16;
        }
        uVar1 = uVar8 + 1;
        if (uVar1 < 0x1000) {
          if (uVar1 == 0) {
            local_78 = (byte ***)0x0;
          }
          else {
            local_78 = operator_new(uVar1);
          }
        }
        else {
          local_78 = (byte ***)FUN_180007f10(uVar1);
        }
      }
      else {
        uVar8 = 0x7fffffffffffffff;
        local_78 = (byte ***)FUN_180007f10(0x8000000000000000);
      }
      local_68 = uVar3;
      local_60 = uVar8;
      memcpy(local_78,puVar9,uVar3 + 1);
    }
    local_58 = (byte ***)0x0;
    uStack_50 = 0;
    local_40 = 0;
    puVar9 = puVar10 + 4;
    if (0xf < (ulonglong)puVar10[7]) {
      puVar9 = (undefined8 *)puVar10[4];
    }
    uVar3 = puVar10[6];
    if (0x7fffffffffffffff < uVar3) {
                    /* WARNING: Subroutine does not return */
      FUN_18000ace0();
    }
    if (uVar3 < 0x10) {
      uVar8 = 0xf;
      local_40 = 0xf;
      ppppbVar5 = (byte ****)*puVar9;
      uStack_50 = puVar9[1];
      local_58 = (byte ***)ppppbVar5;
      local_48 = uVar3;
    }
    else {
      uVar8 = uVar3 | 0xf;
      if (uVar8 < 0x8000000000000000) {
        if (uVar8 < 0x16) {
          uVar8 = 0x16;
        }
        uVar1 = uVar8 + 1;
        if (uVar1 < 0x1000) {
          if (uVar1 == 0) {
            ppppbVar5 = (byte ****)0x0;
          }
          else {
            ppppbVar5 = operator_new(uVar1);
          }
        }
        else {
          ppppbVar5 = (byte ****)FUN_180007f10(uVar1);
        }
      }
      else {
        uVar8 = 0x7fffffffffffffff;
        ppppbVar5 = (byte ****)FUN_180007f10(0x8000000000000000);
      }
      local_58 = (byte ***)ppppbVar5;
      local_48 = uVar3;
      local_40 = uVar8;
      memcpy(ppppbVar5,puVar9,uVar3 + 1);
    }
    ppppbVar7 = &local_78;
    if (0xf < local_60) {
      ppppbVar7 = (byte ****)local_78;
    }
    ppppbVar6 = &local_58;
    if (0xf < uVar8) {
      ppppbVar6 = ppppbVar5;
    }
    iVar4 = FUN_180032240((byte *)ppppbVar6,(byte *)ppppbVar7);
    if (0xf < local_40) {
      ppppbVar5 = (byte ****)local_58;
      if ((0xfff < local_40 + 1) &&
         (ppppbVar5 = (byte ****)local_58[-1],
         (byte *)0x1f < (byte *)((longlong)local_58 + (-8 - (longlong)ppppbVar5))))
      goto LAB_180031f7a;
      operator_delete(ppppbVar5);
    }
    if (0xf < local_60) {
      ppppbVar5 = (byte ****)local_78;
      if ((0xfff < local_60 + 1) &&
         (ppppbVar5 = (byte ****)local_78[-1],
         (byte *)0x1f < (byte *)((longlong)local_78 + (-8 - (longlong)ppppbVar5)))) {
LAB_180031f7a:
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      operator_delete(ppppbVar5);
    }
    if (iVar4 < 0) {
      puVar10 = (undefined8 *)puVar10[2];
      *(undefined4 *)(param_2 + 1) = 0;
    }
    else {
      param_2[2] = puVar10;
      puVar10 = (undefined8 *)*puVar10;
      *(undefined4 *)(param_2 + 1) = 1;
    }
  } while( true );
}

/* ---- FUNC 00031FB0 FUN_180031fb0 (414 bytes) ---- */

longlong * FUN_180031fb0(longlong *param_1,void *param_2,int param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  void *pvVar3;
  void *_Dst;
  ulonglong uVar4;
  void *pvVar5;
  ulonglong _Size;
  longlong *_Dst_00;
  ulonglong uVar6;
  longlong *plVar7;
  
  _Dst = (void *)0x0;
  if (param_3 != 0) {
    *param_1 = (longlong)&DAT_1800537c8;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0xf;
    *(undefined1 *)(param_1 + 1) = 0;
  }
  plVar7 = (longlong *)((longlong)*(int *)(*param_1 + 4) + (longlong)param_1);
  _Size = 0xffffffffffffffff;
  do {
    _Size = _Size + 1;
  } while (*(char *)(_Size + (longlong)param_2) != '\0');
  uVar2 = plVar7[3];
  if (uVar2 < _Size) {
    uVar6 = 0x7fffffffffffffff;
    if (0x7fffffffffffffff < _Size) {
                    /* WARNING: Subroutine does not return */
      FUN_18000ace0();
    }
    uVar4 = _Size | 0xf;
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
          if (uVar4 != 0) {
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
    plVar7[2] = _Size;
    plVar7[3] = uVar6;
    memcpy(_Dst,param_2,_Size);
    *(undefined1 *)((longlong)_Dst + _Size) = 0;
    if (0xf < uVar2) {
      pvVar3 = (void *)*plVar7;
      pvVar5 = pvVar3;
      if ((0xfff < uVar2 + 1) &&
         (pvVar5 = *(void **)((longlong)pvVar3 + -8),
         0x1f < (ulonglong)((longlong)pvVar3 + (-8 - (longlong)pvVar5)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      operator_delete(pvVar5);
    }
    *plVar7 = (longlong)_Dst;
  }
  else {
    _Dst_00 = plVar7;
    if (0xf < uVar2) {
      _Dst_00 = (longlong *)*plVar7;
    }
    plVar7[2] = _Size;
    memmove(_Dst_00,param_2,_Size);
    *(undefined1 *)((longlong)_Dst_00 + _Size) = 0;
  }
  return param_1;
}

/* ---- FUNC 00032150 FUN_180032150 (239 bytes) ---- */

uint FUN_180032150(undefined8 param_1,byte *param_2,byte *param_3)

{
  void *pvVar1;
  uint uVar2;
  byte *pbVar3;
  void *pvVar4;
  byte *pbVar5;
  
  pbVar5 = param_3;
  if (0xf < *(ulonglong *)(param_3 + 0x18)) {
    pbVar5 = *(byte **)param_3;
  }
  pbVar3 = param_2;
  if (0xf < *(ulonglong *)(param_2 + 0x18)) {
    pbVar3 = *(byte **)param_2;
  }
  uVar2 = FUN_180032240(pbVar3,pbVar5);
  if (0xf < *(ulonglong *)(param_2 + 0x18)) {
    pvVar1 = *(void **)param_2;
    pvVar4 = pvVar1;
    if ((0xfff < *(ulonglong *)(param_2 + 0x18) + 1) &&
       (pvVar4 = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar4)))) goto LAB_180032239;
    operator_delete(pvVar4);
  }
  param_2[0x10] = 0;
  param_2[0x11] = 0;
  param_2[0x12] = 0;
  param_2[0x13] = 0;
  param_2[0x14] = 0;
  param_2[0x15] = 0;
  param_2[0x16] = 0;
  param_2[0x17] = 0;
  param_2[0x18] = 0xf;
  param_2[0x19] = 0;
  param_2[0x1a] = 0;
  param_2[0x1b] = 0;
  param_2[0x1c] = 0;
  param_2[0x1d] = 0;
  param_2[0x1e] = 0;
  param_2[0x1f] = 0;
  *param_2 = 0;
  if (0xf < *(ulonglong *)(param_3 + 0x18)) {
    pvVar1 = *(void **)param_3;
    pvVar4 = pvVar1;
    if ((0xfff < *(ulonglong *)(param_3 + 0x18) + 1) &&
       (pvVar4 = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar4)))) {
LAB_180032239:
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar4);
  }
  param_3[0x10] = 0;
  param_3[0x11] = 0;
  param_3[0x12] = 0;
  param_3[0x13] = 0;
  param_3[0x14] = 0;
  param_3[0x15] = 0;
  param_3[0x16] = 0;
  param_3[0x17] = 0;
  param_3[0x18] = 0xf;
  param_3[0x19] = 0;
  param_3[0x1a] = 0;
  param_3[0x1b] = 0;
  param_3[0x1c] = 0;
  param_3[0x1d] = 0;
  param_3[0x1e] = 0;
  param_3[0x1f] = 0;
  *param_3 = 0;
  return uVar2 >> 0x1f;
}

/* ---- FUNC 00032240 FUN_180032240 (291 bytes) ---- */

int FUN_180032240(byte *param_1,byte *param_2)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  bVar1 = *param_1;
  do {
    if ((bVar1 == 0) || (bVar2 = *param_2, bVar2 == 0)) {
      iVar6 = (uint)bVar1 - (uint)*param_2;
      iVar3 = iVar6;
      if (iVar6 < 0) {
        iVar6 = -1;
      }
      else {
LAB_180032340:
        if (0 < iVar3) {
          iVar6 = 1;
        }
      }
      return iVar6;
    }
    iVar3 = isdigit((uint)bVar1);
    if ((iVar3 == 0) || (iVar3 = isdigit((uint)bVar2), iVar3 == 0)) {
      iVar3 = (uint)bVar1 - (uint)bVar2;
      if (iVar3 != 0) goto LAB_18003230f;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    }
    else {
      iVar3 = 0;
      iVar6 = 0;
      iVar4 = isdigit((int)(char)*param_1);
      while (iVar4 != 0) {
        bVar1 = *param_1;
        param_1 = param_1 + 1;
        iVar6 = iVar6 + 1;
        iVar3 = (int)(char)bVar1 + iVar3 * 10 + -0x30;
        iVar4 = isdigit((int)(char)*param_1);
      }
      iVar4 = 0;
      iVar7 = 0;
      iVar5 = isdigit((int)(char)*param_2);
      while (iVar5 != 0) {
        bVar1 = *param_2;
        param_2 = param_2 + 1;
        iVar7 = iVar7 + 1;
        iVar4 = (int)(char)bVar1 + iVar4 * 10 + -0x30;
        iVar5 = isdigit((int)(char)*param_2);
      }
      iVar3 = iVar3 - iVar4;
      if ((iVar3 != 0) || (iVar3 = iVar7 - iVar6, iVar3 != 0)) {
LAB_18003230f:
        iVar6 = -1;
        goto LAB_180032340;
      }
    }
    bVar1 = *param_1;
  } while( true );
}

/* ---- FUNC 00032370 APModCatCount (22 bytes) ---- */

DWORD APModCatCount(void)

{
  HKEY hKey;
  LSTATUS LVar1;
  int iVar2;
  LPCSTR lpSubKey;
  DWORD dwIndex;
  DWORD local_res8 [2];
  CHAR local_res10 [8];
  _FILETIME local_res18;
  HKEY local_b8 [2];
  undefined4 local_a8;
  undefined8 local_a0;
  HKEY local_98 [2];
  undefined4 local_88;
  undefined8 local_80;
  HKEY local_78 [2];
  undefined4 local_68;
  undefined8 local_60;
  HKEY local_58 [2];
  undefined4 local_48;
  undefined8 local_40;
  HKEY local_38 [2];
  undefined4 local_28;
  undefined8 local_20;
  
                    /* 0x32370  260  APModCatCount */
  dwIndex = 0;
  local_38[0] = (HKEY)&DAT_180053988;
  local_58[0] = (HKEY)&DAT_180053988;
  local_78[0] = (HKEY)&DAT_180053988;
  local_98[0] = (HKEY)&DAT_180053988;
  local_b8[0] = (HKEY)&DAT_180053988;
  local_38[1] = (HKEY)0x0;
  local_28 = 0;
  local_20 = 0;
  local_58[1] = (HKEY)0x0;
  local_48 = 0;
  local_40 = 0;
  local_78[1] = (HKEY)0x0;
  local_68 = 0;
  local_60 = 0;
  local_98[1] = (HKEY)0x0;
  local_88 = 0;
  local_80 = 0;
  local_b8[1] = (HKEY)0x0;
  local_a8 = 0;
  local_a0 = 0;
  LVar1 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000001,"Software",0,0xf003f,local_38 + 1);
  if (((LVar1 == 0) &&
      (LVar1 = RegOpenKeyExA(*(HKEY *)((longlong)local_38 + (longlong)local_38[0][1].unused),
                             "AspenTech",0,0xf003f,
                             (PHKEY)((longlong)local_58 + (longlong)local_58[0][1].unused)),
      LVar1 == 0)) &&
     (LVar1 = RegOpenKeyExA(*(HKEY *)((longlong)local_58 + (longlong)local_58[0][1].unused),
                            "ASPEN PLUS",0,0xf003f,
                            (PHKEY)((longlong)local_78 + (longlong)local_78[0][1].unused)),
     LVar1 == 0)) {
    iVar2 = local_98[0][1].unused;
    hKey = *(HKEY *)((longlong)local_78 + (longlong)local_78[0][1].unused);
    lpSubKey = (LPCSTR)FUN_180024170();
    LVar1 = RegOpenKeyExA(hKey,lpSubKey,0,0xf003f,(PHKEY)((longlong)local_98 + (longlong)iVar2));
    if ((LVar1 == 0) &&
       (LVar1 = RegOpenKeyExA(*(HKEY *)((longlong)local_98 + (longlong)local_98[0][1].unused),
                              "Categories",0,0xf003f,
                              (PHKEY)((longlong)local_b8 + (longlong)local_b8[0][1].unused)),
       LVar1 == 0)) {
      local_res8[0] = 4;
      iVar2 = RegEnumKeyExA(*(HKEY *)((longlong)local_b8 + (longlong)local_b8[0][1].unused),0,
                            local_res10,local_res8,(LPDWORD)0x0,(LPSTR)0x0,(LPDWORD)0x0,&local_res18
                           );
      while (iVar2 == 0) {
        local_res8[0] = 4;
        dwIndex = dwIndex + 1;
        iVar2 = RegEnumKeyExA(*(HKEY *)((longlong)local_b8 + (longlong)local_b8[0][1].unused),
                              dwIndex,local_res10,local_res8,(LPDWORD)0x0,(LPSTR)0x0,(LPDWORD)0x0,
                              &local_res18);
      }
      goto LAB_1800325a6;
    }
  }
  dwIndex = 0;
LAB_1800325a6:
  if (local_b8[1] != (HKEY)0x0) {
    RegCloseKey(local_b8[1]);
    local_b8[1] = (HKEY)0x0;
  }
  local_a8 = 0;
  if (local_98[1] != (HKEY)0x0) {
    RegCloseKey(local_98[1]);
    local_98[1] = (HKEY)0x0;
  }
  local_88 = 0;
  if (local_78[1] != (HKEY)0x0) {
    RegCloseKey(local_78[1]);
    local_78[1] = (HKEY)0x0;
  }
  local_68 = 0;
  if (local_58[1] != (HKEY)0x0) {
    RegCloseKey(local_58[1]);
    local_58[1] = (HKEY)0x0;
  }
  local_48 = 0;
  if (local_38[1] != (HKEY)0x0) {
    RegCloseKey(local_38[1]);
  }
  return dwIndex;
}

/* ---- FUNC 00032386 FUN_180032386 (265 bytes) ---- */

DWORD FUN_180032386(void)

{
  HKEY hKey;
  LSTATUS LVar1;
  int iVar2;
  undefined8 in_RAX;
  LPCSTR lpSubKey;
  DWORD dwIndex;
  longlong unaff_RBP;
  
  dwIndex = 0;
  *(undefined8 *)(unaff_RBP + 0x27) = in_RAX;
  *(undefined8 *)(unaff_RBP + 7) = in_RAX;
  *(undefined8 *)(unaff_RBP + -0x19) = in_RAX;
  *(undefined8 *)(unaff_RBP + -0x39) = in_RAX;
  *(undefined8 *)(unaff_RBP + -0x59) = in_RAX;
  *(undefined8 *)(unaff_RBP + 0x2f) = 0;
  *(undefined4 *)(unaff_RBP + 0x37) = 0;
  *(undefined8 *)(unaff_RBP + 0x3f) = 0;
  *(undefined8 *)(unaff_RBP + 0xf) = 0;
  *(undefined4 *)(unaff_RBP + 0x17) = 0;
  *(undefined8 *)(unaff_RBP + 0x1f) = 0;
  *(undefined8 *)(unaff_RBP + -0x11) = 0;
  *(undefined4 *)(unaff_RBP + -9) = 0;
  *(undefined8 *)(unaff_RBP + -1) = 0;
  *(undefined8 *)(unaff_RBP + -0x31) = 0;
  *(undefined4 *)(unaff_RBP + -0x29) = 0;
  *(undefined8 *)(unaff_RBP + -0x21) = 0;
  *(undefined8 *)(unaff_RBP + -0x51) = 0;
  *(undefined4 *)(unaff_RBP + -0x49) = 0;
  *(undefined8 *)(unaff_RBP + -0x41) = 0;
  LVar1 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000001,"Software",0,0xf003f,(PHKEY)(unaff_RBP + 0x2f));
  if (((LVar1 == 0) &&
      (LVar1 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + 0x27 +
                                      (longlong)*(int *)(*(longlong *)(unaff_RBP + 0x27) + 4)),
                             "AspenTech",0,0xf003f,
                             (PHKEY)(unaff_RBP + 7 +
                                    (longlong)*(int *)(*(longlong *)(unaff_RBP + 7) + 4))),
      LVar1 == 0)) &&
     (LVar1 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + 7 +
                                     (longlong)*(int *)(*(longlong *)(unaff_RBP + 7) + 4)),
                            "ASPEN PLUS",0,0xf003f,
                            (PHKEY)(unaff_RBP + -0x19 +
                                   (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x19) + 4))),
     LVar1 == 0)) {
    iVar2 = *(int *)(*(longlong *)(unaff_RBP + -0x39) + 4);
    hKey = *(HKEY *)(unaff_RBP + -0x19 + (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x19) + 4));
    lpSubKey = (LPCSTR)FUN_180024170();
    LVar1 = RegOpenKeyExA(hKey,lpSubKey,0,0xf003f,(PHKEY)(unaff_RBP + -0x39 + (longlong)iVar2));
    if ((LVar1 == 0) &&
       (LVar1 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + -0x39 +
                                       (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x39) + 4)),
                              "Categories",0,0xf003f,
                              (PHKEY)(unaff_RBP + -0x59 +
                                     (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x59) + 4))),
       LVar1 == 0)) {
      *(undefined4 *)(unaff_RBP + 0x67) = 4;
      iVar2 = RegEnumKeyExA(*(HKEY *)(unaff_RBP + -0x59 +
                                     (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x59) + 4)),0,
                            (LPSTR)(unaff_RBP + 0x6f),(LPDWORD)(unaff_RBP + 0x67),(LPDWORD)0x0,
                            (LPSTR)0x0,(LPDWORD)0x0,(PFILETIME)(unaff_RBP + 0x77));
      while (iVar2 == 0) {
        *(undefined4 *)(unaff_RBP + 0x67) = 4;
        dwIndex = dwIndex + 1;
        iVar2 = RegEnumKeyExA(*(HKEY *)(unaff_RBP + -0x59 +
                                       (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x59) + 4)),
                              dwIndex,(LPSTR)(unaff_RBP + 0x6f),(LPDWORD)(unaff_RBP + 0x67),
                              (LPDWORD)0x0,(LPSTR)0x0,(LPDWORD)0x0,(PFILETIME)(unaff_RBP + 0x77));
      }
      goto LAB_1800325a6;
    }
  }
  dwIndex = 0;
LAB_1800325a6:
  if (*(HKEY *)(unaff_RBP + -0x51) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x51));
    *(undefined8 *)(unaff_RBP + -0x51) = 0;
  }
  *(undefined4 *)(unaff_RBP + -0x49) = 0;
  if (*(HKEY *)(unaff_RBP + -0x31) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x31));
    *(undefined8 *)(unaff_RBP + -0x31) = 0;
  }
  *(undefined4 *)(unaff_RBP + -0x29) = 0;
  if (*(HKEY *)(unaff_RBP + -0x11) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x11));
    *(undefined8 *)(unaff_RBP + -0x11) = 0;
  }
  *(undefined4 *)(unaff_RBP + -9) = 0;
  if (*(HKEY *)(unaff_RBP + 0xf) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + 0xf));
    *(undefined8 *)(unaff_RBP + 0xf) = 0;
  }
  *(undefined4 *)(unaff_RBP + 0x17) = 0;
  if (*(HKEY *)(unaff_RBP + 0x2f) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + 0x2f));
  }
  return dwIndex;
}

/* ---- FUNC 0003248F FUN_18003248f (75 bytes) ---- */

ulonglong FUN_18003248f(void)

{
  HKEY hKey;
  LSTATUS LVar1;
  int iVar2;
  longlong in_RAX;
  LPCSTR lpSubKey;
  uint dwIndex;
  longlong unaff_RBX;
  ulonglong uVar3;
  longlong unaff_RBP;
  undefined4 uVar4;
  LPDWORD unaff_RSI;
  
  iVar2 = *(int *)(in_RAX + 4);
  hKey = *(HKEY *)(unaff_RBP + -0x19 + (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x19) + 4));
  lpSubKey = (LPCSTR)FUN_180024170();
  LVar1 = RegOpenKeyExA(hKey,lpSubKey,0,0xf003f,(PHKEY)(unaff_RBX + iVar2));
  uVar4 = SUB84(unaff_RSI,0);
  if ((LVar1 == 0) &&
     (LVar1 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + -0x39 +
                                     (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x39) + 4)),
                            "Categories",0,0xf003f,
                            (PHKEY)(unaff_RBP + -0x59 +
                                   (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x59) + 4))),
     LVar1 == 0)) {
    *(undefined4 *)(unaff_RBP + 0x67) = 4;
    uVar3 = (ulonglong)unaff_RSI & 0xffffffff;
    iVar2 = RegEnumKeyExA(*(HKEY *)(unaff_RBP + -0x59 +
                                   (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x59) + 4)),0,
                          (LPSTR)(unaff_RBP + 0x6f),(LPDWORD)(unaff_RBP + 0x67),unaff_RSI,
                          (LPSTR)unaff_RSI,unaff_RSI,(PFILETIME)(unaff_RBP + 0x77));
    while (iVar2 == 0) {
      *(undefined4 *)(unaff_RBP + 0x67) = 4;
      dwIndex = (int)uVar3 + 1;
      uVar3 = (ulonglong)dwIndex;
      iVar2 = RegEnumKeyExA(*(HKEY *)(unaff_RBP + -0x59 +
                                     (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x59) + 4)),
                            dwIndex,(LPSTR)(unaff_RBP + 0x6f),(LPDWORD)(unaff_RBP + 0x67),unaff_RSI,
                            (LPSTR)unaff_RSI,unaff_RSI,(PFILETIME)(unaff_RBP + 0x77));
    }
  }
  else {
    uVar3 = (ulonglong)unaff_RSI & 0xffffffff;
  }
  if (*(HKEY *)(unaff_RBP + -0x51) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x51));
    *(LPDWORD *)(unaff_RBP + -0x51) = unaff_RSI;
  }
  *(undefined4 *)(unaff_RBP + -0x49) = uVar4;
  if (*(HKEY *)(unaff_RBP + -0x31) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x31));
    *(LPDWORD *)(unaff_RBP + -0x31) = unaff_RSI;
  }
  *(undefined4 *)(unaff_RBP + -0x29) = uVar4;
  if (*(HKEY *)(unaff_RBP + -0x11) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x11));
    *(LPDWORD *)(unaff_RBP + -0x11) = unaff_RSI;
  }
  *(undefined4 *)(unaff_RBP + -9) = uVar4;
  if (*(HKEY *)(unaff_RBP + 0xf) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + 0xf));
    *(LPDWORD *)(unaff_RBP + 0xf) = unaff_RSI;
  }
  *(undefined4 *)(unaff_RBP + 0x17) = uVar4;
  if (*(HKEY *)(unaff_RBP + 0x2f) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + 0x2f));
  }
  return uVar3;
}

/* ---- FUNC 000324DA FUN_1800324da (309 bytes) ---- */

ulonglong FUN_1800324da(void)

{
  LSTATUS LVar1;
  int iVar2;
  uint dwIndex;
  ulonglong uVar3;
  longlong unaff_RBP;
  undefined4 uVar4;
  LPDWORD unaff_RSI;
  
  LVar1 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + -0x39 +
                                 (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x39) + 4)),
                        "Categories",0,0xf003f,
                        (PHKEY)(unaff_RBP + -0x59 +
                               (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x59) + 4)));
  uVar4 = SUB84(unaff_RSI,0);
  if (LVar1 == 0) {
    *(undefined4 *)(unaff_RBP + 0x67) = 4;
    uVar3 = (ulonglong)unaff_RSI & 0xffffffff;
    iVar2 = RegEnumKeyExA(*(HKEY *)(unaff_RBP + -0x59 +
                                   (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x59) + 4)),0,
                          (LPSTR)(unaff_RBP + 0x6f),(LPDWORD)(unaff_RBP + 0x67),unaff_RSI,
                          (LPSTR)unaff_RSI,unaff_RSI,(PFILETIME)(unaff_RBP + 0x77));
    while (iVar2 == 0) {
      *(undefined4 *)(unaff_RBP + 0x67) = 4;
      dwIndex = (int)uVar3 + 1;
      uVar3 = (ulonglong)dwIndex;
      iVar2 = RegEnumKeyExA(*(HKEY *)(unaff_RBP + -0x59 +
                                     (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x59) + 4)),
                            dwIndex,(LPSTR)(unaff_RBP + 0x6f),(LPDWORD)(unaff_RBP + 0x67),unaff_RSI,
                            (LPSTR)unaff_RSI,unaff_RSI,(PFILETIME)(unaff_RBP + 0x77));
    }
  }
  else {
    uVar3 = (ulonglong)unaff_RSI & 0xffffffff;
  }
  if (*(HKEY *)(unaff_RBP + -0x51) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x51));
    *(LPDWORD *)(unaff_RBP + -0x51) = unaff_RSI;
  }
  *(undefined4 *)(unaff_RBP + -0x49) = uVar4;
  if (*(HKEY *)(unaff_RBP + -0x31) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x31));
    *(LPDWORD *)(unaff_RBP + -0x31) = unaff_RSI;
  }
  *(undefined4 *)(unaff_RBP + -0x29) = uVar4;
  if (*(HKEY *)(unaff_RBP + -0x11) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x11));
    *(LPDWORD *)(unaff_RBP + -0x11) = unaff_RSI;
  }
  *(undefined4 *)(unaff_RBP + -9) = uVar4;
  if (*(HKEY *)(unaff_RBP + 0xf) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + 0xf));
    *(LPDWORD *)(unaff_RBP + 0xf) = unaff_RSI;
  }
  *(undefined4 *)(unaff_RBP + 0x17) = uVar4;
  if (*(HKEY *)(unaff_RBP + 0x2f) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + 0x2f));
  }
  return uVar3;
}

/* ---- FUNC 0003260F FUN_18003260f (18 bytes) ---- */

undefined4 FUN_18003260f(HKEY param_1)

{
  undefined4 unaff_EBX;
  
  RegCloseKey(param_1);
  return unaff_EBX;
}

/* ---- FUNC 00032630 APModCatGetValues (74 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 APModCatGetValues(longlong param_1,undefined4 *param_2,undefined4 *param_3)

{
  BYTE BVar1;
  BYTE BVar2;
  HKEY hKey;
  LSTATUS LVar3;
  int iVar4;
  LPCSTR lpSubKey;
  BYTE *pBVar5;
  DWORD dwIndex;
  undefined4 unaff_EDI;
  longlong lVar6;
  undefined1 auStackY_5a8 [32];
  DWORD local_568;
  DWORD local_564;
  undefined4 local_560;
  DWORD local_55c;
  HKEY local_558 [2];
  undefined4 local_548;
  undefined8 local_540;
  HKEY local_538 [2];
  undefined4 local_528;
  undefined8 local_520;
  HKEY local_518 [2];
  undefined4 local_508;
  undefined8 local_500;
  HKEY local_4f8 [2];
  undefined4 local_4e8;
  undefined8 local_4e0;
  HKEY local_4d8 [2];
  undefined4 local_4c8;
  undefined8 local_4c0;
  _FILETIME local_4b8;
  HKEY local_4b0 [2];
  undefined4 local_4a0;
  undefined8 local_498;
  CHAR local_488 [64];
  BYTE local_448 [1024];
  ulonglong local_48;
  
                    /* 0x32630  261  APModCatGetValues */
  local_48 = DAT_1800791f8 ^ (ulonglong)auStackY_5a8;
  dwIndex = 0;
  *param_2 = 0xffffffff;
  *param_3 = 0;
  if (param_1 != 0) {
    local_4b0[1] = (HKEY)0x0;
    local_4b0[0] = (HKEY)&DAT_180053988;
    local_4d8[0] = (HKEY)&DAT_180053988;
    local_4f8[0] = (HKEY)&DAT_180053988;
    local_518[0] = (HKEY)&DAT_180053988;
    local_558[0] = (HKEY)&DAT_180053988;
    local_4a0 = 0;
    local_498 = 0;
    local_4d8[1] = (HKEY)0x0;
    local_4c8 = 0;
    local_4c0 = 0;
    local_4f8[1] = (HKEY)0x0;
    local_4e8 = 0;
    local_4e0 = 0;
    local_518[1] = (HKEY)0x0;
    local_508 = 0;
    local_500 = 0;
    local_558[1] = (HKEY)0x0;
    local_548 = 0;
    local_540 = 0;
    LVar3 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000001,"Software",0,0xf003f,local_4b0 + 1);
    if (((LVar3 == 0) &&
        (LVar3 = RegOpenKeyExA(*(HKEY *)((longlong)local_4b0 + (longlong)local_4b0[0][1].unused),
                               "AspenTech",0,0xf003f,
                               (PHKEY)((longlong)local_4d8 + (longlong)local_4d8[0][1].unused)),
        LVar3 == 0)) &&
       (LVar3 = RegOpenKeyExA(*(HKEY *)((longlong)local_4d8 + (longlong)local_4d8[0][1].unused),
                              "ASPEN PLUS",0,0xf003f,
                              (PHKEY)((longlong)local_4f8 + (longlong)local_4f8[0][1].unused)),
       LVar3 == 0)) {
      hKey = *(HKEY *)((longlong)local_4f8 + (longlong)local_4f8[0][1].unused);
      iVar4 = local_518[0][1].unused;
      lpSubKey = (LPCSTR)FUN_180024170();
      LVar3 = RegOpenKeyExA(hKey,lpSubKey,0,0xf003f,(PHKEY)((longlong)local_518 + (longlong)iVar4));
      if ((LVar3 == 0) &&
         (LVar3 = RegOpenKeyExA(*(HKEY *)((longlong)local_518 + (longlong)local_518[0][1].unused),
                                "Categories",0,0xf003f,
                                (PHKEY)((longlong)local_558 + (longlong)local_558[0][1].unused)),
         LVar3 == 0)) {
        local_55c = 0x400;
        local_568 = 0x40;
        local_564 = 4;
        iVar4 = RegEnumKeyExA(*(HKEY *)((longlong)local_558 + (longlong)local_558[0][1].unused),0,
                              local_488,&local_568,(LPDWORD)0x0,(LPSTR)0x0,(LPDWORD)0x0,&local_4b8);
        while (iVar4 == 0) {
          local_538[0] = (HKEY)&DAT_180053988;
          local_538[1] = (HKEY)0x0;
          local_528 = 0;
          local_520 = 0;
          LVar3 = RegOpenKeyExA(*(HKEY *)((longlong)local_558 + (longlong)local_558[0][1].unused),
                                local_488,0,0xf003f,local_538 + 1);
          if (LVar3 == 0) {
            local_55c = 0x400;
            LVar3 = RegQueryValueExA(*(HKEY *)((longlong)local_538 +
                                              (longlong)local_538[0][1].unused),"name",(LPDWORD)0x0,
                                     (LPDWORD)0x0,local_448,&local_55c);
            if (LVar3 == 0) {
              pBVar5 = local_448;
              lVar6 = param_1 - (longlong)pBVar5;
              do {
                BVar1 = *pBVar5;
                BVar2 = pBVar5[lVar6];
                if (BVar1 != BVar2) break;
                pBVar5 = pBVar5 + 1;
              } while (BVar2 != '\0');
              if (BVar1 == BVar2) {
                LVar3 = RegQueryValueExA(*(HKEY *)((longlong)local_538 +
                                                  (longlong)local_538[0][1].unused),"Position",
                                         (LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)&local_560,&local_564);
                if (LVar3 == 0) {
                  *param_2 = local_560;
                }
                local_564 = 4;
                LVar3 = RegQueryValueExA(*(HKEY *)((longlong)local_538 +
                                                  (longlong)local_538[0][1].unused),"Active",
                                         (LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)&local_560,&local_564);
                if (LVar3 == 0) {
                  *param_3 = local_560;
                }
                if (local_538[1] != (HKEY)0x0) {
                  RegCloseKey(local_538[1]);
                }
                break;
              }
            }
          }
          dwIndex = dwIndex + 1;
          local_568 = 0x40;
          if (local_538[1] != (HKEY)0x0) {
            RegCloseKey(local_538[1]);
          }
          iVar4 = RegEnumKeyExA(*(HKEY *)((longlong)local_558 + (longlong)local_558[0][1].unused),
                                dwIndex,local_488,&local_568,(LPDWORD)0x0,(LPSTR)0x0,(LPDWORD)0x0,
                                &local_4b8);
        }
      }
    }
    if (local_558[1] != (HKEY)0x0) {
      RegCloseKey(local_558[1]);
      local_558[1] = (HKEY)0x0;
    }
    local_548 = 0;
    if (local_518[1] != (HKEY)0x0) {
      RegCloseKey(local_518[1]);
      local_518[1] = (HKEY)0x0;
    }
    local_508 = 0;
    if (local_4f8[1] != (HKEY)0x0) {
      RegCloseKey(local_4f8[1]);
      local_4f8[1] = (HKEY)0x0;
    }
    local_4e8 = 0;
    if (local_4d8[1] != (HKEY)0x0) {
      RegCloseKey(local_4d8[1]);
      local_4d8[1] = (HKEY)0x0;
    }
    local_4c8 = 0;
    if (local_4b0[1] != (HKEY)0x0) {
      RegCloseKey(local_4b0[1]);
    }
  }
  return unaff_EDI;
}

/* ---- FUNC 0003267A FUN_18003267a (967 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_18003267a(void)

{
  char cVar1;
  char cVar2;
  HKEY hKey;
  LSTATUS LVar3;
  int iVar4;
  LPCSTR lpSubKey;
  PHKEY ppHVar5;
  uint dwIndex;
  ulonglong uVar6;
  PHKEY unaff_RBP;
  longlong unaff_RSI;
  ulonglong uVar7;
  longlong lVar8;
  undefined4 uVar9;
  HKEY unaff_R12;
  undefined4 *unaff_R14;
  undefined4 *unaff_R15;
  DWORD DStack0000000000000040;
  undefined4 uStack0000000000000044;
  undefined4 uStack0000000000000048;
  undefined4 uStack000000000000004c;
  undefined *puStack0000000000000050;
  undefined4 uStack0000000000000060;
  undefined *in_stack_00000070;
  HKEY in_stack_00000078;
  
  *unaff_RBP = unaff_R12;
  unaff_RBP[-1] = (HKEY)&DAT_180053988;
  unaff_RBP[-6] = (HKEY)&DAT_180053988;
  unaff_RBP[-10] = (HKEY)&DAT_180053988;
  unaff_RBP[-0xe] = (HKEY)&DAT_180053988;
  puStack0000000000000050 = &DAT_180053988;
  uVar9 = SUB84(unaff_R12,0);
  *(undefined4 *)(unaff_RBP + 1) = uVar9;
  unaff_RBP[2] = unaff_R12;
  unaff_RBP[-5] = unaff_R12;
  *(undefined4 *)(unaff_RBP + -4) = uVar9;
  unaff_RBP[-3] = unaff_R12;
  unaff_RBP[-9] = unaff_R12;
  *(undefined4 *)(unaff_RBP + -8) = uVar9;
  unaff_RBP[-7] = unaff_R12;
  unaff_RBP[-0xd] = unaff_R12;
  *(undefined4 *)(unaff_RBP + -0xc) = uVar9;
  unaff_RBP[-0xb] = unaff_R12;
  uStack0000000000000060 = uVar9;
  LVar3 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000001,"Software",0,0xf003f,unaff_RBP);
  if (((LVar3 == 0) &&
      (LVar3 = RegOpenKeyExA(*(HKEY *)((longlong)unaff_RBP + (longlong)unaff_RBP[-1][1].unused + -8)
                             ,"AspenTech",0,0xf003f,
                             (PHKEY)((longlong)unaff_RBP + (longlong)unaff_RBP[-6][1].unused + -0x30
                                    )), LVar3 == 0)) &&
     (LVar3 = RegOpenKeyExA(*(HKEY *)((longlong)unaff_RBP +
                                     (longlong)unaff_RBP[-6][1].unused + -0x30),"ASPEN PLUS",0,
                            0xf003f,(PHKEY)((longlong)unaff_RBP +
                                           (longlong)unaff_RBP[-10][1].unused + -0x50)), LVar3 == 0)
     ) {
    hKey = *(HKEY *)((longlong)unaff_RBP + (longlong)unaff_RBP[-10][1].unused + -0x50);
    iVar4 = unaff_RBP[-0xe][1].unused;
    lpSubKey = (LPCSTR)FUN_180024170();
    LVar3 = RegOpenKeyExA(hKey,lpSubKey,0,0xf003f,
                          (PHKEY)((longlong)unaff_RBP + (longlong)iVar4 + -0x70));
    if ((LVar3 == 0) &&
       (LVar3 = RegOpenKeyExA(*(HKEY *)((longlong)unaff_RBP +
                                       (longlong)unaff_RBP[-0xe][1].unused + -0x70),"Categories",0,
                              0xf003f,(PHKEY)((longlong)&stack0x00000050 +
                                             (longlong)*(int *)(puStack0000000000000050 + 4))),
       LVar3 == 0)) {
      uStack000000000000004c = 0x400;
      DStack0000000000000040 = 0x40;
      uStack0000000000000044 = 4;
      uVar6 = (ulonglong)unaff_R12 & 0xffffffff;
      uVar7 = (ulonglong)unaff_R12 & 0xffffffff;
      iVar4 = RegEnumKeyExA(*(HKEY *)((longlong)&stack0x00000050 +
                                     (longlong)*(int *)(puStack0000000000000050 + 4)),0,
                            (LPSTR)(unaff_RBP + 4),&stack0x00000040,(LPDWORD)unaff_R12,
                            (LPSTR)unaff_R12,(LPDWORD)unaff_R12,(PFILETIME)(unaff_RBP + -2));
      while (iVar4 == 0) {
        in_stack_00000070 = &DAT_180053988;
        *(undefined4 *)(unaff_RBP + -0x10) = uVar9;
        unaff_RBP[-0xf] = unaff_R12;
        in_stack_00000078 = unaff_R12;
        LVar3 = RegOpenKeyExA(*(HKEY *)((longlong)&stack0x00000050 +
                                       (longlong)*(int *)(puStack0000000000000050 + 4)),
                              (LPCSTR)(unaff_RBP + 4),0,0xf003f,&stack0x00000078);
        if (LVar3 == 0) {
          uStack000000000000004c = 0x400;
          LVar3 = RegQueryValueExA(*(HKEY *)((longlong)&stack0x00000070 +
                                            (longlong)*(int *)(in_stack_00000070 + 4)),"name",
                                   (LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)(unaff_RBP + 0xc),
                                   (LPDWORD)((longlong)&stack0x00000048 + 4));
          if (LVar3 == 0) {
            ppHVar5 = unaff_RBP + 0xc;
            lVar8 = unaff_RSI - (longlong)ppHVar5;
            do {
              cVar1 = *(char *)ppHVar5;
              cVar2 = *(char *)((longlong)ppHVar5 + lVar8);
              if (cVar1 != cVar2) break;
              ppHVar5 = (PHKEY)((longlong)ppHVar5 + 1);
            } while (cVar2 != '\0');
            if (cVar1 == cVar2) {
              uVar7 = 1;
              LVar3 = RegQueryValueExA(*(HKEY *)((longlong)&stack0x00000070 +
                                                (longlong)*(int *)(in_stack_00000070 + 4)),
                                       "Position",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)&stack0x00000048
                                       ,(LPDWORD)((longlong)&stack0x00000040 + 4));
              if (LVar3 == 0) {
                *unaff_R14 = uStack0000000000000048;
              }
              uStack0000000000000044 = 4;
              LVar3 = RegQueryValueExA(*(HKEY *)((longlong)&stack0x00000070 +
                                                (longlong)*(int *)(in_stack_00000070 + 4)),"Active",
                                       (LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)&stack0x00000048,
                                       (LPDWORD)((longlong)&stack0x00000040 + 4));
              if (LVar3 == 0) {
                *unaff_R15 = uStack0000000000000048;
              }
              if (in_stack_00000078 != (HKEY)0x0) {
                RegCloseKey(in_stack_00000078);
              }
              break;
            }
          }
        }
        dwIndex = (int)uVar6 + 1;
        uVar6 = (ulonglong)dwIndex;
        DStack0000000000000040 = 0x40;
        if (in_stack_00000078 != (HKEY)0x0) {
          RegCloseKey(in_stack_00000078);
        }
        iVar4 = RegEnumKeyExA(*(HKEY *)((longlong)&stack0x00000050 +
                                       (longlong)*(int *)(puStack0000000000000050 + 4)),dwIndex,
                              (LPSTR)(unaff_RBP + 4),&stack0x00000040,(LPDWORD)unaff_R12,
                              (LPSTR)unaff_R12,(LPDWORD)unaff_R12,(PFILETIME)(unaff_RBP + -2));
      }
      goto LAB_180032a27;
    }
  }
  uVar7 = (ulonglong)unaff_R12 & 0xffffffff;
LAB_180032a27:
  if (unaff_R12 != (HKEY)0x0) {
    RegCloseKey(unaff_R12);
  }
  uStack0000000000000060 = uVar9;
  if (unaff_RBP[-0xd] != (HKEY)0x0) {
    RegCloseKey(unaff_RBP[-0xd]);
    unaff_RBP[-0xd] = unaff_R12;
  }
  *(undefined4 *)(unaff_RBP + -0xc) = uVar9;
  if (unaff_RBP[-9] != (HKEY)0x0) {
    RegCloseKey(unaff_RBP[-9]);
    unaff_RBP[-9] = unaff_R12;
  }
  *(undefined4 *)(unaff_RBP + -8) = uVar9;
  if (unaff_RBP[-5] != (HKEY)0x0) {
    RegCloseKey(unaff_RBP[-5]);
    unaff_RBP[-5] = unaff_R12;
  }
  *(undefined4 *)(unaff_RBP + -4) = uVar9;
  if (*unaff_RBP != (HKEY)0x0) {
    RegCloseKey(*unaff_RBP);
  }
  return uVar7;
}

/* ---- FUNC 00032A41 FUN_180032a41 (110 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_180032a41(HKEY param_1)

{
  undefined8 *unaff_RBP;
  undefined4 unaff_EDI;
  undefined4 uVar1;
  undefined8 unaff_R12;
  
  RegCloseKey(param_1);
  uVar1 = (undefined4)unaff_R12;
  if ((HKEY)unaff_RBP[-0xd] != (HKEY)0x0) {
    RegCloseKey((HKEY)unaff_RBP[-0xd]);
    unaff_RBP[-0xd] = unaff_R12;
  }
  *(undefined4 *)(unaff_RBP + -0xc) = uVar1;
  if ((HKEY)unaff_RBP[-9] != (HKEY)0x0) {
    RegCloseKey((HKEY)unaff_RBP[-9]);
    unaff_RBP[-9] = unaff_R12;
  }
  *(undefined4 *)(unaff_RBP + -8) = uVar1;
  if ((HKEY)unaff_RBP[-5] != (HKEY)0x0) {
    RegCloseKey((HKEY)unaff_RBP[-5]);
    unaff_RBP[-5] = unaff_R12;
  }
  *(undefined4 *)(unaff_RBP + -4) = uVar1;
  if ((HKEY)*unaff_RBP != (HKEY)0x0) {
    RegCloseKey((HKEY)*unaff_RBP);
  }
  return unaff_EDI;
}

/* ---- FUNC 00032AAF FUN_180032aaf (31 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180032aaf(void)

{
  return;
}

/* ---- FUNC 00032AD0 APModCatListCats (90 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong APModCatListCats(longlong param_1,uint param_2,int param_3)

{
  HKEY hKey;
  char *_Dest;
  longlong lVar1;
  LSTATUS LVar2;
  LPCSTR lpSubKey;
  int iVar3;
  longlong lVar4;
  ulonglong uVar6;
  uint dwIndex;
  undefined1 auStackY_598 [32];
  DWORD local_558 [2];
  HKEY local_550 [2];
  undefined4 local_540;
  undefined8 local_538;
  HKEY local_530 [2];
  undefined4 local_520;
  undefined8 local_518;
  HKEY local_510 [2];
  undefined4 local_500;
  undefined8 local_4f8;
  HKEY local_4f0 [2];
  undefined4 local_4e0;
  undefined8 local_4d8;
  HKEY local_4d0 [2];
  undefined4 local_4c0;
  undefined8 local_4b8;
  _FILETIME local_4b0;
  HKEY local_4a8 [2];
  undefined4 local_498;
  undefined8 local_490;
  CHAR local_488 [64];
  BYTE local_448 [1024];
  ulonglong local_48;
  longlong lVar5;
  
                    /* 0x32ad0  262  APModCatListCats */
  local_48 = DAT_1800791f8 ^ (ulonglong)auStackY_598;
  uVar6 = 0;
  if (((param_1 == 0) || ((int)param_2 < 1)) || (param_3 < 1)) {
    uVar6 = 0;
  }
  else {
    local_4a8[0] = (HKEY)&DAT_180053988;
    local_4f0[0] = (HKEY)&DAT_180053988;
    local_510[0] = (HKEY)&DAT_180053988;
    local_530[0] = (HKEY)&DAT_180053988;
    local_550[0] = (HKEY)&DAT_180053988;
    local_4a8[1] = (HKEY)0x0;
    local_498 = 0;
    local_490 = 0;
    local_4f0[1] = (HKEY)0x0;
    local_4e0 = 0;
    local_4d8 = 0;
    local_510[1] = (HKEY)0x0;
    local_500 = 0;
    local_4f8 = 0;
    local_530[1] = (HKEY)0x0;
    local_520 = 0;
    local_518 = 0;
    local_550[1] = (HKEY)0x0;
    local_540 = 0;
    local_538 = 0;
    LVar2 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000001,"Software",0,0xf003f,local_4a8 + 1);
    if (((LVar2 == 0) &&
        (LVar2 = RegOpenKeyExA(*(HKEY *)((longlong)local_4a8 + (longlong)local_4a8[0][1].unused),
                               "AspenTech",0,0xf003f,
                               (PHKEY)((longlong)local_4f0 + (longlong)local_4f0[0][1].unused)),
        LVar2 == 0)) &&
       (LVar2 = RegOpenKeyExA(*(HKEY *)((longlong)local_4f0 + (longlong)local_4f0[0][1].unused),
                              "ASPEN PLUS",0,0xf003f,
                              (PHKEY)((longlong)local_510 + (longlong)local_510[0][1].unused)),
       LVar2 == 0)) {
      hKey = *(HKEY *)((longlong)local_510 + (longlong)local_510[0][1].unused);
      iVar3 = local_530[0][1].unused;
      lpSubKey = (LPCSTR)FUN_180024170();
      LVar2 = RegOpenKeyExA(hKey,lpSubKey,0,0xf003f,(PHKEY)((longlong)local_530 + (longlong)iVar3));
      if ((LVar2 == 0) &&
         (LVar2 = RegOpenKeyExA(*(HKEY *)((longlong)local_530 + (longlong)local_530[0][1].unused),
                                "Categories",0,0xf003f,
                                (PHKEY)((longlong)local_550 + (longlong)local_550[0][1].unused)),
         LVar2 == 0)) {
        local_558[1] = 0x400;
        local_558[0] = 0x40;
        LVar2 = RegEnumKeyExA(*(HKEY *)((longlong)local_550 + (longlong)local_550[0][1].unused),0,
                              local_488,local_558,(LPDWORD)0x0,(LPSTR)0x0,(LPDWORD)0x0,&local_4b0);
        if (LVar2 == 0) {
          do {
            local_4d0[1] = (HKEY)0x0;
            local_4d0[0] = (HKEY)&DAT_180053988;
            local_4c0 = 0;
            local_4b8 = 0;
            LVar2 = RegOpenKeyExA(*(HKEY *)((longlong)local_550 + (longlong)local_550[0][1].unused),
                                  local_488,0,0xf003f,local_4d0 + 1);
            if (LVar2 == 0) {
              local_558[1] = 0x400;
              LVar2 = RegQueryValueExA(*(HKEY *)((longlong)local_4d0 +
                                                (longlong)local_4d0[0][1].unused),"name",
                                       (LPDWORD)0x0,(LPDWORD)0x0,local_448,local_558 + 1);
              if (LVar2 == 0) {
                lVar5 = -1;
                do {
                  lVar4 = lVar5 + 1;
                  lVar1 = lVar5 + 1;
                  lVar5 = lVar4;
                } while (local_448[lVar1] != '\0');
                iVar3 = (int)lVar4;
                if (param_3 + -1 <= iVar3) {
                  iVar3 = param_3 + -1;
                }
                _Dest = *(char **)(param_1 + uVar6 * 8);
                strncpy(_Dest,(char *)local_448,(longlong)iVar3);
                _Dest[iVar3] = '\0';
              }
            }
            dwIndex = (int)uVar6 + 1;
            uVar6 = (ulonglong)dwIndex;
            local_558[0] = 0x40;
            if (dwIndex == param_2) {
              if (local_4d0[1] != (HKEY)0x0) {
                RegCloseKey(local_4d0[1]);
              }
              goto LAB_180032e55;
            }
            if (local_4d0[1] != (HKEY)0x0) {
              RegCloseKey(local_4d0[1]);
            }
            LVar2 = RegEnumKeyExA(*(HKEY *)((longlong)local_550 + (longlong)local_550[0][1].unused),
                                  dwIndex,local_488,local_558,(LPDWORD)0x0,(LPSTR)0x0,(LPDWORD)0x0,
                                  &local_4b0);
          } while (LVar2 == 0);
          uVar6 = 1;
        }
        else {
LAB_180032e55:
          uVar6 = 1;
        }
      }
    }
    if (local_550[1] != (HKEY)0x0) {
      RegCloseKey(local_550[1]);
      local_550[1] = (HKEY)0x0;
    }
    local_540 = 0;
    if (local_530[1] != (HKEY)0x0) {
      RegCloseKey(local_530[1]);
      local_530[1] = (HKEY)0x0;
    }
    local_520 = 0;
    if (local_510[1] != (HKEY)0x0) {
      RegCloseKey(local_510[1]);
      local_510[1] = (HKEY)0x0;
    }
    local_500 = 0;
    if (local_4f0[1] != (HKEY)0x0) {
      RegCloseKey(local_4f0[1]);
      local_4f0[1] = (HKEY)0x0;
    }
    local_4e0 = 0;
    if (local_4a8[1] != (HKEY)0x0) {
      RegCloseKey(local_4a8[1]);
    }
  }
  return uVar6;
}

/* ---- FUNC 00032B2A FUN_180032b2a (58 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_180032b2a(void)

{
  HKEY pHVar1;
  char *_Dest;
  longlong lVar2;
  undefined4 uVar3;
  LSTATUS LVar4;
  longlong in_RAX;
  LPCSTR lpSubKey;
  int iVar5;
  longlong lVar6;
  undefined8 unaff_RBX;
  ulonglong uVar8;
  undefined4 *unaff_RBP;
  uint dwIndex;
  undefined8 unaff_RDI;
  longlong in_R11;
  longlong unaff_R12;
  undefined4 uVar9;
  HKEY unaff_R13;
  uint unaff_R14D;
  int unaff_R15D;
  DWORD DStack0000000000000040;
  undefined4 uStack0000000000000044;
  longlong lStack0000000000000048;
  undefined4 uStack0000000000000058;
  longlong lStack0000000000000068;
  undefined4 uStack0000000000000078;
  longlong lVar7;
  
  *(undefined8 *)(in_R11 + 0x10) = unaff_RBX;
  *(longlong *)(unaff_RBP + -4) = in_RAX;
  *(longlong *)(unaff_RBP + -0x16) = in_RAX;
  *(longlong *)(unaff_RBP + -0x1e) = in_RAX;
  *(undefined8 *)(in_R11 + -0x38) = unaff_RDI;
  *(HKEY *)(unaff_RBP + -2) = unaff_R13;
  uVar9 = SUB84(unaff_R13,0);
  *unaff_RBP = uVar9;
  *(HKEY *)(unaff_RBP + 2) = unaff_R13;
  *(HKEY *)(unaff_RBP + -0x14) = unaff_R13;
  unaff_RBP[-0x12] = uVar9;
  *(HKEY *)(unaff_RBP + -0x10) = unaff_R13;
  *(HKEY *)(unaff_RBP + -0x1c) = unaff_R13;
  unaff_RBP[-0x1a] = uVar9;
  *(HKEY *)(unaff_RBP + -0x18) = unaff_R13;
  *(HKEY *)(unaff_RBP + -0x20) = unaff_R13;
  lStack0000000000000048 = in_RAX;
  uStack0000000000000058 = uVar9;
  lStack0000000000000068 = in_RAX;
  uStack0000000000000078 = uVar9;
  LVar4 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000001,"Software",0,0xf003f,(PHKEY)(unaff_RBP + -2));
  if (((LVar4 == 0) &&
      (LVar4 = RegOpenKeyExA(*(HKEY *)((longlong)unaff_RBP +
                                      (longlong)*(int *)(*(longlong *)(unaff_RBP + -4) + 4) + -0x10)
                             ,"AspenTech",0,0xf003f,
                             (PHKEY)((longlong)unaff_RBP +
                                    (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x16) + 4) + -0x58
                                    )), LVar4 == 0)) &&
     (LVar4 = RegOpenKeyExA(*(HKEY *)((longlong)unaff_RBP +
                                     (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x16) + 4) +
                                     -0x58),"ASPEN PLUS",0,0xf003f,
                            (PHKEY)((longlong)unaff_RBP +
                                   (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x1e) + 4) + -0x78)
                           ), LVar4 == 0)) {
    pHVar1 = *(HKEY *)((longlong)unaff_RBP +
                      (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x1e) + 4) + -0x78);
    iVar5 = *(int *)(lStack0000000000000068 + 4);
    lpSubKey = (LPCSTR)FUN_180024170();
    LVar4 = RegOpenKeyExA(pHVar1,lpSubKey,0,0xf003f,
                          (PHKEY)((longlong)&stack0x00000068 + (longlong)iVar5));
    if ((LVar4 == 0) &&
       (LVar4 = RegOpenKeyExA(*(HKEY *)((longlong)&stack0x00000068 +
                                       (longlong)*(int *)(lStack0000000000000068 + 4)),"Categories",
                              0,0xf003f,
                              (PHKEY)((longlong)&stack0x00000048 +
                                     (longlong)*(int *)(lStack0000000000000048 + 4))), LVar4 == 0))
    {
      uStack0000000000000044 = 0x400;
      DStack0000000000000040 = 0x40;
      uVar8 = (ulonglong)unaff_R13 & 0xffffffff;
      LVar4 = RegEnumKeyExA(*(HKEY *)((longlong)&stack0x00000048 +
                                     (longlong)*(int *)(lStack0000000000000048 + 4)),0,
                            (LPSTR)(unaff_RBP + 4),&stack0x00000040,(LPDWORD)unaff_R13,
                            (LPSTR)unaff_R13,(LPDWORD)unaff_R13,(PFILETIME)(unaff_RBP + -6));
      if (LVar4 == 0) {
        do {
          *(HKEY *)(unaff_RBP + -0xc) = unaff_R13;
          *(undefined **)(unaff_RBP + -0xe) = &DAT_180053988;
          unaff_RBP[-10] = uVar9;
          *(HKEY *)(unaff_RBP + -8) = unaff_R13;
          LVar4 = RegOpenKeyExA(*(HKEY *)((longlong)&stack0x00000048 +
                                         (longlong)*(int *)(lStack0000000000000048 + 4)),
                                (LPCSTR)(unaff_RBP + 4),0,0xf003f,(PHKEY)(unaff_RBP + -0xc));
          if (LVar4 == 0) {
            uStack0000000000000044 = 0x400;
            LVar4 = RegQueryValueExA(*(HKEY *)((longlong)unaff_RBP +
                                              (longlong)
                                              *(int *)(*(longlong *)(unaff_RBP + -0xe) + 4) + -0x38)
                                     ,"name",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)(unaff_RBP + 0x14),
                                     (LPDWORD)((longlong)&stack0x00000040 + 4));
            if (LVar4 == 0) {
              lVar7 = -1;
              do {
                lVar6 = lVar7 + 1;
                lVar2 = lVar7 + 0x51;
                lVar7 = lVar6;
              } while (*(char *)((longlong)unaff_RBP + lVar2) != (char)unaff_R13);
              iVar5 = (int)lVar6;
              if (unaff_R15D + -1 <= iVar5) {
                iVar5 = unaff_R15D + -1;
              }
              _Dest = *(char **)(unaff_R12 + uVar8 * 8);
              strncpy(_Dest,(char *)(unaff_RBP + 0x14),(longlong)iVar5);
              _Dest[iVar5] = (char)unaff_R13;
            }
          }
          pHVar1 = *(HKEY *)(unaff_RBP + -0xc);
          dwIndex = (int)uVar8 + 1;
          uVar8 = (ulonglong)dwIndex;
          DStack0000000000000040 = 0x40;
          if (dwIndex == unaff_R14D) {
            if (pHVar1 != (HKEY)0x0) {
              RegCloseKey(pHVar1);
            }
            goto LAB_180032e55;
          }
          if (pHVar1 != (HKEY)0x0) {
            RegCloseKey(pHVar1);
          }
          LVar4 = RegEnumKeyExA(*(HKEY *)((longlong)&stack0x00000048 +
                                         (longlong)*(int *)(lStack0000000000000048 + 4)),dwIndex,
                                (LPSTR)(unaff_RBP + 4),&stack0x00000040,(LPDWORD)unaff_R13,
                                (LPSTR)unaff_R13,(LPDWORD)unaff_R13,(PFILETIME)(unaff_RBP + -6));
        } while (LVar4 == 0);
        uVar8 = 1;
      }
      else {
LAB_180032e55:
        uVar8 = 1;
      }
      goto LAB_180032e67;
    }
  }
  uVar8 = (ulonglong)unaff_R13 & 0xffffffff;
LAB_180032e67:
  uVar3 = uVar9;
  if (unaff_R13 != (HKEY)0x0) {
    RegCloseKey(unaff_R13);
    uStack0000000000000058 = uVar9;
    RegCloseKey(unaff_R13);
    uVar3 = uStack0000000000000058;
  }
  uStack0000000000000058 = uVar3;
  uStack0000000000000078 = uVar9;
  if (*(HKEY *)(unaff_RBP + -0x1c) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x1c));
    *(HKEY *)(unaff_RBP + -0x1c) = unaff_R13;
  }
  unaff_RBP[-0x1a] = uVar9;
  if (*(HKEY *)(unaff_RBP + -0x14) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x14));
    *(HKEY *)(unaff_RBP + -0x14) = unaff_R13;
  }
  unaff_RBP[-0x12] = uVar9;
  if (*(HKEY *)(unaff_RBP + -2) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -2));
  }
  return uVar8;
}

/* ---- FUNC 00032B64 FUN_180032b64 (376 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_180032b64(HKEY param_1,LPCSTR param_2,DWORD param_3,REGSAM param_4)

{
  HKEY pHVar1;
  char *_Dest;
  longlong lVar2;
  undefined4 uVar3;
  LSTATUS LVar4;
  LPCSTR lpSubKey;
  int iVar5;
  longlong lVar6;
  ulonglong uVar8;
  undefined4 *unaff_RBP;
  uint dwIndex;
  undefined8 unaff_RDI;
  longlong in_R11;
  longlong unaff_R12;
  undefined4 uVar9;
  HKEY unaff_R13;
  uint unaff_R14D;
  int unaff_R15D;
  PHKEY in_stack_00000020;
  DWORD DStack0000000000000040;
  undefined4 uStack0000000000000044;
  longlong in_stack_00000048;
  undefined4 uStack0000000000000058;
  longlong in_stack_00000068;
  undefined4 uStack0000000000000078;
  longlong lVar7;
  
  *(undefined8 *)(in_R11 + -0x38) = unaff_RDI;
  *(HKEY *)(unaff_RBP + -2) = unaff_R13;
  uVar9 = SUB84(unaff_R13,0);
  *unaff_RBP = uVar9;
  *(HKEY *)(unaff_RBP + 2) = unaff_R13;
  *(HKEY *)(unaff_RBP + -0x14) = unaff_R13;
  unaff_RBP[-0x12] = uVar9;
  *(HKEY *)(unaff_RBP + -0x10) = unaff_R13;
  *(HKEY *)(unaff_RBP + -0x1c) = unaff_R13;
  unaff_RBP[-0x1a] = uVar9;
  *(HKEY *)(unaff_RBP + -0x18) = unaff_R13;
  *(HKEY *)(unaff_RBP + -0x20) = unaff_R13;
  uStack0000000000000058 = uVar9;
  uStack0000000000000078 = uVar9;
  LVar4 = RegOpenKeyExA(param_1,param_2,param_3,param_4,in_stack_00000020);
  if (((LVar4 == 0) &&
      (LVar4 = RegOpenKeyExA(*(HKEY *)((longlong)unaff_RBP +
                                      (longlong)*(int *)(*(longlong *)(unaff_RBP + -4) + 4) + -0x10)
                             ,"AspenTech",0,0xf003f,
                             (PHKEY)((longlong)unaff_RBP +
                                    (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x16) + 4) + -0x58
                                    )), LVar4 == 0)) &&
     (LVar4 = RegOpenKeyExA(*(HKEY *)((longlong)unaff_RBP +
                                     (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x16) + 4) +
                                     -0x58),"ASPEN PLUS",0,0xf003f,
                            (PHKEY)((longlong)unaff_RBP +
                                   (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x1e) + 4) + -0x78)
                           ), LVar4 == 0)) {
    pHVar1 = *(HKEY *)((longlong)unaff_RBP +
                      (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x1e) + 4) + -0x78);
    iVar5 = *(int *)(in_stack_00000068 + 4);
    lpSubKey = (LPCSTR)FUN_180024170();
    LVar4 = RegOpenKeyExA(pHVar1,lpSubKey,0,0xf003f,
                          (PHKEY)((longlong)&stack0x00000068 + (longlong)iVar5));
    if ((LVar4 == 0) &&
       (LVar4 = RegOpenKeyExA(*(HKEY *)((longlong)&stack0x00000068 +
                                       (longlong)*(int *)(in_stack_00000068 + 4)),"Categories",0,
                              0xf003f,(PHKEY)((longlong)&stack0x00000048 +
                                             (longlong)*(int *)(in_stack_00000048 + 4))), LVar4 == 0
       )) {
      uStack0000000000000044 = 0x400;
      DStack0000000000000040 = 0x40;
      uVar8 = (ulonglong)unaff_R13 & 0xffffffff;
      LVar4 = RegEnumKeyExA(*(HKEY *)((longlong)&stack0x00000048 +
                                     (longlong)*(int *)(in_stack_00000048 + 4)),0,
                            (LPSTR)(unaff_RBP + 4),&stack0x00000040,(LPDWORD)unaff_R13,
                            (LPSTR)unaff_R13,(LPDWORD)unaff_R13,(PFILETIME)(unaff_RBP + -6));
      if (LVar4 == 0) {
        do {
          *(HKEY *)(unaff_RBP + -0xc) = unaff_R13;
          *(undefined **)(unaff_RBP + -0xe) = &DAT_180053988;
          unaff_RBP[-10] = uVar9;
          *(HKEY *)(unaff_RBP + -8) = unaff_R13;
          LVar4 = RegOpenKeyExA(*(HKEY *)((longlong)&stack0x00000048 +
                                         (longlong)*(int *)(in_stack_00000048 + 4)),
                                (LPCSTR)(unaff_RBP + 4),0,0xf003f,(PHKEY)(unaff_RBP + -0xc));
          if (LVar4 == 0) {
            uStack0000000000000044 = 0x400;
            LVar4 = RegQueryValueExA(*(HKEY *)((longlong)unaff_RBP +
                                              (longlong)
                                              *(int *)(*(longlong *)(unaff_RBP + -0xe) + 4) + -0x38)
                                     ,"name",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)(unaff_RBP + 0x14),
                                     (LPDWORD)((longlong)&stack0x00000040 + 4));
            if (LVar4 == 0) {
              lVar7 = -1;
              do {
                lVar6 = lVar7 + 1;
                lVar2 = lVar7 + 0x51;
                lVar7 = lVar6;
              } while (*(char *)((longlong)unaff_RBP + lVar2) != (char)unaff_R13);
              iVar5 = (int)lVar6;
              if (unaff_R15D + -1 <= iVar5) {
                iVar5 = unaff_R15D + -1;
              }
              _Dest = *(char **)(unaff_R12 + uVar8 * 8);
              strncpy(_Dest,(char *)(unaff_RBP + 0x14),(longlong)iVar5);
              _Dest[iVar5] = (char)unaff_R13;
            }
          }
          pHVar1 = *(HKEY *)(unaff_RBP + -0xc);
          dwIndex = (int)uVar8 + 1;
          uVar8 = (ulonglong)dwIndex;
          DStack0000000000000040 = 0x40;
          if (dwIndex == unaff_R14D) {
            if (pHVar1 != (HKEY)0x0) {
              RegCloseKey(pHVar1);
            }
            goto LAB_180032e55;
          }
          if (pHVar1 != (HKEY)0x0) {
            RegCloseKey(pHVar1);
          }
          LVar4 = RegEnumKeyExA(*(HKEY *)((longlong)&stack0x00000048 +
                                         (longlong)*(int *)(in_stack_00000048 + 4)),dwIndex,
                                (LPSTR)(unaff_RBP + 4),&stack0x00000040,(LPDWORD)unaff_R13,
                                (LPSTR)unaff_R13,(LPDWORD)unaff_R13,(PFILETIME)(unaff_RBP + -6));
        } while (LVar4 == 0);
        uVar8 = 1;
      }
      else {
LAB_180032e55:
        uVar8 = 1;
      }
      goto LAB_180032e67;
    }
  }
  uVar8 = (ulonglong)unaff_R13 & 0xffffffff;
LAB_180032e67:
  uVar3 = uVar9;
  if (unaff_R13 != (HKEY)0x0) {
    RegCloseKey(unaff_R13);
    uStack0000000000000058 = uVar9;
    RegCloseKey(unaff_R13);
    uVar3 = uStack0000000000000058;
  }
  uStack0000000000000058 = uVar3;
  uStack0000000000000078 = uVar9;
  if (*(HKEY *)(unaff_RBP + -0x1c) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x1c));
    *(HKEY *)(unaff_RBP + -0x1c) = unaff_R13;
  }
  unaff_RBP[-0x1a] = uVar9;
  if (*(HKEY *)(unaff_RBP + -0x14) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x14));
    *(HKEY *)(unaff_RBP + -0x14) = unaff_R13;
  }
  unaff_RBP[-0x12] = uVar9;
  if (*(HKEY *)(unaff_RBP + -2) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -2));
  }
  return uVar8;
}

/* ---- FUNC 00032CDC FUN_180032cdc (366 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180032cdc(undefined8 param_1,DWORD param_2,LPSTR param_3,LPDWORD param_4)

{
  char *_Dest;
  HKEY hKey;
  int iVar1;
  LSTATUS LVar2;
  longlong in_RAX;
  longlong lVar3;
  longlong unaff_RBP;
  uint dwIndex;
  ulonglong uVar4;
  longlong unaff_R12;
  undefined4 uVar5;
  LPDWORD unaff_R13;
  uint unaff_R14D;
  int unaff_R15D;
  DWORD DStack0000000000000040;
  undefined4 uStack0000000000000044;
  longlong in_stack_00000048;
  HKEY in_stack_00000050;
  HKEY in_stack_00000070;
  
  uVar5 = SUB84(unaff_R13,0);
  uVar4 = (ulonglong)unaff_R13 & 0xffffffff;
  iVar1 = RegEnumKeyExA(*(HKEY *)((longlong)&stack0x00000048 + (longlong)*(int *)(in_RAX + 4)),
                        param_2,param_3,param_4,unaff_R13,(LPSTR)unaff_R13,unaff_R13,
                        (PFILETIME)(unaff_RBP + -0x18));
  do {
    if (iVar1 != 0) {
LAB_180032e67:
      if (in_stack_00000050 != (HKEY)0x0) {
        RegCloseKey(in_stack_00000050);
      }
      if (in_stack_00000070 != (HKEY)0x0) {
        RegCloseKey(in_stack_00000070);
      }
      if (*(HKEY *)(unaff_RBP + -0x70) != (HKEY)0x0) {
        RegCloseKey(*(HKEY *)(unaff_RBP + -0x70));
        *(LPDWORD *)(unaff_RBP + -0x70) = unaff_R13;
      }
      *(undefined4 *)(unaff_RBP + -0x68) = uVar5;
      if (*(HKEY *)(unaff_RBP + -0x50) != (HKEY)0x0) {
        RegCloseKey(*(HKEY *)(unaff_RBP + -0x50));
        *(LPDWORD *)(unaff_RBP + -0x50) = unaff_R13;
      }
      *(undefined4 *)(unaff_RBP + -0x48) = uVar5;
      if (*(HKEY *)(unaff_RBP + -8) != (HKEY)0x0) {
        RegCloseKey(*(HKEY *)(unaff_RBP + -8));
      }
      return 1;
    }
    *(LPDWORD *)(unaff_RBP + -0x30) = unaff_R13;
    *(undefined **)(unaff_RBP + -0x38) = &DAT_180053988;
    *(undefined4 *)(unaff_RBP + -0x28) = uVar5;
    *(LPDWORD *)(unaff_RBP + -0x20) = unaff_R13;
    LVar2 = RegOpenKeyExA(*(HKEY *)((longlong)&stack0x00000048 +
                                   (longlong)*(int *)(in_stack_00000048 + 4)),
                          (LPCSTR)(unaff_RBP + 0x10),0,0xf003f,(PHKEY)(unaff_RBP + -0x30));
    if (LVar2 == 0) {
      uStack0000000000000044 = 0x400;
      LVar2 = RegQueryValueExA(*(HKEY *)(unaff_RBP + -0x38 +
                                        (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x38) + 4)),
                               "name",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)(unaff_RBP + 0x50),
                               (LPDWORD)((longlong)&stack0x00000040 + 4));
      if (LVar2 == 0) {
        lVar3 = -1;
        do {
          lVar3 = lVar3 + 1;
        } while (*(char *)(unaff_RBP + 0x50 + lVar3) != (char)unaff_R13);
        iVar1 = (int)lVar3;
        if (unaff_R15D + -1 <= (int)lVar3) {
          iVar1 = unaff_R15D + -1;
        }
        _Dest = *(char **)(unaff_R12 + uVar4 * 8);
        strncpy(_Dest,(char *)(unaff_RBP + 0x50),(longlong)iVar1);
        _Dest[iVar1] = (char)unaff_R13;
      }
    }
    hKey = *(HKEY *)(unaff_RBP + -0x30);
    dwIndex = (int)uVar4 + 1;
    uVar4 = (ulonglong)dwIndex;
    DStack0000000000000040 = 0x40;
    if (dwIndex == unaff_R14D) {
      if (hKey != (HKEY)0x0) {
        RegCloseKey(hKey);
      }
      goto LAB_180032e67;
    }
    if (hKey != (HKEY)0x0) {
      RegCloseKey(hKey);
    }
    iVar1 = RegEnumKeyExA(*(HKEY *)((longlong)&stack0x00000048 +
                                   (longlong)*(int *)(in_stack_00000048 + 4)),dwIndex,
                          (LPSTR)(unaff_RBP + 0x10),&stack0x00000040,unaff_R13,(LPSTR)unaff_R13,
                          unaff_R13,(PFILETIME)(unaff_RBP + -0x18));
  } while( true );
}

/* ---- FUNC 00032E4A FUN_180032e4a (26 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180032e4a(HKEY param_1)

{
  longlong unaff_RBP;
  undefined8 unaff_R13;
  HKEY in_stack_00000050;
  HKEY in_stack_00000070;
  
  if (param_1 != (HKEY)0x0) {
    RegCloseKey(param_1);
  }
  if (in_stack_00000050 != (HKEY)0x0) {
    RegCloseKey(in_stack_00000050);
  }
  if (in_stack_00000070 != (HKEY)0x0) {
    RegCloseKey(in_stack_00000070);
  }
  if (*(HKEY *)(unaff_RBP + -0x70) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x70));
    *(undefined8 *)(unaff_RBP + -0x70) = unaff_R13;
  }
  *(int *)(unaff_RBP + -0x68) = (int)unaff_R13;
  if (*(HKEY *)(unaff_RBP + -0x50) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x50));
    *(undefined8 *)(unaff_RBP + -0x50) = unaff_R13;
  }
  *(int *)(unaff_RBP + -0x48) = (int)unaff_R13;
  if (*(HKEY *)(unaff_RBP + -8) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -8));
  }
  return 1;
}

/* ---- FUNC 00032E64 FUN_180032e64 (21 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_180032e64(void)

{
  longlong unaff_RBP;
  ulonglong unaff_R13;
  HKEY in_stack_00000050;
  HKEY in_stack_00000070;
  
  if (in_stack_00000050 != (HKEY)0x0) {
    RegCloseKey(in_stack_00000050);
  }
  if (in_stack_00000070 != (HKEY)0x0) {
    RegCloseKey(in_stack_00000070);
  }
  if (*(HKEY *)(unaff_RBP + -0x70) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x70));
    *(ulonglong *)(unaff_RBP + -0x70) = unaff_R13;
  }
  *(int *)(unaff_RBP + -0x68) = (int)unaff_R13;
  if (*(HKEY *)(unaff_RBP + -0x50) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x50));
    *(ulonglong *)(unaff_RBP + -0x50) = unaff_R13;
  }
  *(int *)(unaff_RBP + -0x48) = (int)unaff_R13;
  if (*(HKEY *)(unaff_RBP + -8) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -8));
  }
  return unaff_R13 & 0xffffffff;
}

/* ---- FUNC 00032E79 FUN_180032e79 (115 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_180032e79(HKEY param_1)

{
  undefined4 unaff_EBX;
  longlong unaff_RBP;
  undefined8 unaff_R13;
  HKEY in_stack_00000070;
  
  RegCloseKey(param_1);
  if (in_stack_00000070 != (HKEY)0x0) {
    RegCloseKey(in_stack_00000070);
  }
  if (*(HKEY *)(unaff_RBP + -0x70) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x70));
    *(undefined8 *)(unaff_RBP + -0x70) = unaff_R13;
  }
  *(int *)(unaff_RBP + -0x68) = (int)unaff_R13;
  if (*(HKEY *)(unaff_RBP + -0x50) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x50));
    *(undefined8 *)(unaff_RBP + -0x50) = unaff_R13;
  }
  *(int *)(unaff_RBP + -0x48) = (int)unaff_R13;
  if (*(HKEY *)(unaff_RBP + -8) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -8));
  }
  return unaff_EBX;
}

/* ---- FUNC 00032EEC FUN_180032eec (34 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180032eec(void)

{
  return 0;
}

/* ---- FUNC 00032F10 APModCatRegisterCat (2494 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 APModCatRegisterCat(char *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  BYTE BVar2;
  BYTE BVar3;
  HKEY hKey;
  int iVar4;
  int iVar5;
  int iVar6;
  LSTATUS LVar7;
  int iVar8;
  int iVar9;
  LPCSTR lpSubKey;
  void *_Memory;
  longlong lVar10;
  BYTE *pBVar11;
  uint uVar12;
  int *piVar13;
  DWORD DVar14;
  DWORD dwIndex;
  int iVar15;
  longlong lVar16;
  int iVar17;
  LPDWORD lpcchName;
  uint uVar18;
  longlong lVar19;
  undefined1 auStackY_5a8 [32];
  DWORD local_558;
  CHAR local_554 [4];
  HKEY local_550 [2];
  undefined4 local_540;
  undefined8 local_538;
  HKEY local_530 [2];
  undefined4 local_520;
  undefined8 local_518;
  HKEY local_510 [2];
  undefined4 local_500;
  undefined8 local_4f8;
  HKEY local_4f0 [2];
  undefined4 local_4e0;
  undefined8 local_4d8;
  DWORD local_4d0;
  int local_4cc;
  DWORD local_4c8;
  DWORD local_4c4;
  int local_4c0;
  undefined4 local_4bc;
  HKEY local_4b8 [2];
  undefined4 local_4a8;
  undefined8 local_4a0;
  HKEY local_498 [2];
  undefined4 local_488;
  undefined8 local_480;
  HKEY local_478 [2];
  undefined4 local_468;
  undefined8 local_460;
  undefined4 local_458;
  _FILETIME local_450;
  BYTE local_448 [1023];
  undefined1 local_49;
  ulonglong local_48;
  
                    /* 0x32f10  263  APModCatRegisterCat */
  local_48 = DAT_1800791f8 ^ (ulonglong)auStackY_5a8;
  if (param_1 == (char *)0x0) {
    return 0;
  }
  local_498[1] = (HKEY)0x0;
  local_498[0] = (HKEY)&DAT_180053988;
  local_530[0] = (HKEY)&DAT_180053988;
  local_510[0] = (HKEY)&DAT_180053988;
  local_4f0[0] = (HKEY)&DAT_180053988;
  local_550[0] = (HKEY)&DAT_180053988;
  DVar14 = 0;
  local_488 = 0;
  local_480 = 0;
  local_530[1] = (HKEY)0x0;
  local_520 = 0;
  local_518 = 0;
  local_510[1] = (HKEY)0x0;
  local_500 = 0;
  local_4f8 = 0;
  local_4f0[1] = (HKEY)0x0;
  local_4e0 = 0;
  local_4d8 = 0;
  local_550[1] = (HKEY)0x0;
  local_540 = 0;
  local_538 = 0;
  local_4c0 = param_2;
  local_458 = param_3;
  LVar7 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000001,"Software",0,0xf003f,local_498 + 1);
  if (LVar7 == 0) {
    LVar7 = RegOpenKeyExA(*(HKEY *)((longlong)local_498 + (longlong)local_498[0][1].unused),
                          "AspenTech",0,0xf003f,
                          (PHKEY)((longlong)local_530 + (longlong)local_530[0][1].unused));
    if (LVar7 == 0) {
      LVar7 = RegOpenKeyExA(*(HKEY *)((longlong)local_530 + (longlong)local_530[0][1].unused),
                            "ASPEN PLUS",0,0xf003f,
                            (PHKEY)((longlong)local_510 + (longlong)local_510[0][1].unused));
      if (LVar7 == 0) {
        hKey = *(HKEY *)((longlong)local_510 + (longlong)local_510[0][1].unused);
        iVar15 = local_4f0[0][1].unused;
        lpSubKey = (LPCSTR)FUN_180024170();
        LVar7 = RegCreateKeyExA(hKey,lpSubKey,0,(LPSTR)0x0,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,
                                (PHKEY)((longlong)local_4f0 + (longlong)iVar15),&local_4c4);
        if (LVar7 == 0) {
          LVar7 = RegCreateKeyExA(*(HKEY *)((longlong)local_4f0 + (longlong)local_4f0[0][1].unused),
                                  "Categories",0,(LPSTR)0x0,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,
                                  (PHKEY)((longlong)local_550 + (longlong)local_550[0][1].unused),
                                  &local_4c4);
          if (LVar7 == 0) {
            local_558 = 4;
            local_4d0 = 0x400;
            local_4c8 = 4;
            iVar15 = -1;
            iVar8 = RegEnumKeyExA(*(HKEY *)((longlong)local_550 + (longlong)local_550[0][1].unused),
                                  0,local_554,&local_558,(LPDWORD)0x0,(LPSTR)0x0,(LPDWORD)0x0,
                                  &local_450);
            while (iVar8 == 0) {
              local_558 = 4;
              DVar14 = DVar14 + 1;
              iVar8 = RegEnumKeyExA(*(HKEY *)((longlong)local_550 + (longlong)local_550[0][1].unused
                                             ),DVar14,local_554,&local_558,(LPDWORD)0x0,(LPSTR)0x0,
                                    (LPDWORD)0x0,&local_450);
            }
            uVar18 = DVar14 + 1;
            lVar19 = (longlong)(int)uVar18;
            _Memory = malloc(lVar19 * 4);
            iVar6 = _UNK_18005696c;
            iVar5 = _UNK_180056968;
            iVar4 = _UNK_180056964;
            iVar8 = _DAT_180056960;
            dwIndex = 0;
            DVar14 = dwIndex;
            if ((0 < (int)uVar18) && (DVar14 = 0, 0xf < uVar18)) {
              uVar12 = uVar18 & 0x8000000f;
              if ((int)uVar12 < 0) {
                uVar12 = (uVar12 - 1 | 0xfffffff0) + 1;
              }
              piVar13 = (int *)((longlong)_Memory + 0x20);
              iVar17 = 8;
              DVar14 = dwIndex;
              do {
                iVar9 = iVar17 + -4;
                piVar13[-8] = DVar14 + iVar8;
                piVar13[-7] = DVar14 + iVar4;
                piVar13[-6] = DVar14 + iVar5;
                piVar13[-5] = DVar14 + iVar6;
                iVar1 = iVar17 + 4;
                DVar14 = DVar14 + 0x10;
                piVar13[-4] = iVar9 + iVar8;
                piVar13[-3] = iVar9 + iVar4;
                piVar13[-2] = iVar9 + iVar5;
                piVar13[-1] = iVar9 + iVar6;
                *piVar13 = iVar17 + iVar8;
                piVar13[1] = iVar17 + iVar4;
                piVar13[2] = iVar17 + iVar5;
                piVar13[3] = iVar17 + iVar6;
                piVar13[4] = iVar1 + iVar8;
                piVar13[5] = iVar1 + iVar4;
                piVar13[6] = iVar1 + iVar5;
                piVar13[7] = iVar1 + iVar6;
                piVar13 = piVar13 + 0x10;
                iVar17 = iVar17 + 0x10;
              } while ((int)DVar14 < (int)(uVar18 - uVar12));
            }
            for (lVar10 = (longlong)(int)DVar14; lVar10 < lVar19; lVar10 = lVar10 + 1) {
              *(DWORD *)((longlong)_Memory + lVar10 * 4) = DVar14;
              DVar14 = DVar14 + 1;
            }
            lpcchName = &local_558;
            local_558 = 4;
            iVar8 = RegEnumKeyExA(*(HKEY *)((longlong)local_550 + (longlong)local_550[0][1].unused),
                                  0,local_554,lpcchName,(LPDWORD)0x0,(LPSTR)0x0,(LPDWORD)0x0,
                                  &local_450);
            while (iVar8 == 0) {
              local_4b8[0] = (HKEY)&DAT_180053988;
              local_4b8[1] = (HKEY)0x0;
              local_4a8 = 0;
              local_4a0 = 0;
              LVar7 = RegOpenKeyExA(*(HKEY *)((longlong)local_550 + (longlong)local_550[0][1].unused
                                             ),local_554,0,0xf003f,local_4b8 + 1);
              if (LVar7 != 0) {
LAB_180033593:
                free(_Memory);
                if (local_4b8[1] != (HKEY)0x0) {
                  RegCloseKey(local_4b8[1]);
                  local_4b8[1] = (HKEY)0x0;
                }
                local_4a8 = 0;
                if (local_550[1] != (HKEY)0x0) {
                  RegCloseKey(local_550[1]);
                  local_550[1] = (HKEY)0x0;
                }
                goto LAB_1800335d1;
              }
              iVar8 = atoi(local_554);
              if (iVar8 < (int)uVar18) {
                *(undefined4 *)((longlong)_Memory + (longlong)iVar8 * 4) = 0xffffffff;
              }
              local_4d0 = 0x400;
              LVar7 = RegQueryValueExA(*(HKEY *)((longlong)local_4b8 +
                                                (longlong)local_4b8[0][1].unused),"name",
                                       (LPDWORD)0x0,(LPDWORD)0x0,local_448,&local_4d0);
              if (LVar7 == 0) {
                pBVar11 = local_448;
                lVar10 = (longlong)param_1 - (longlong)pBVar11;
                do {
                  BVar2 = *pBVar11;
                  BVar3 = pBVar11[lVar10];
                  if (BVar2 != BVar3) break;
                  pBVar11 = pBVar11 + 1;
                } while (BVar3 != '\0');
                if (BVar2 == BVar3) goto LAB_180033593;
              }
              local_4c8 = 4;
              LVar7 = RegQueryValueExA(*(HKEY *)((longlong)local_4b8 +
                                                (longlong)local_4b8[0][1].unused),"Position",
                                       (LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)&local_4cc,&local_4c8);
              if (LVar7 == 0) {
                if (local_4cc == local_4c0) goto LAB_180033593;
                if (iVar15 < local_4cc) {
                  iVar15 = local_4cc;
                }
              }
              dwIndex = dwIndex + 1;
              local_558 = 4;
              if (local_4b8[1] != (HKEY)0x0) {
                RegCloseKey(local_4b8[1]);
              }
              lpcchName = &local_558;
              iVar8 = RegEnumKeyExA(*(HKEY *)((longlong)local_550 + (longlong)local_550[0][1].unused
                                             ),dwIndex,local_554,lpcchName,(LPDWORD)0x0,(LPSTR)0x0,
                                    (LPDWORD)0x0,&local_450);
            }
            if (iVar8 == 0x103) {
              uVar18 = 0;
              if (0 < lVar19) {
                lVar10 = 0;
                uVar18 = 0;
                do {
                  if (*(int *)((longlong)_Memory + lVar10 * 4) != -1) break;
                  uVar18 = uVar18 + 1;
                  lVar10 = lVar10 + 1;
                } while (lVar10 < lVar19);
              }
              free(_Memory);
              FUN_180007de0(local_554,&DAT_1800533ec,(ulonglong)uVar18,lpcchName);
              local_478[1] = (HKEY)0x0;
              local_478[0] = (HKEY)&DAT_180053988;
              local_468 = 0;
              local_460 = 0;
              LVar7 = RegCreateKeyExA(*(HKEY *)((longlong)local_550 +
                                               (longlong)local_550[0][1].unused),local_554,0,
                                      (LPSTR)0x0,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,local_478 + 1,
                                      &local_4c4);
              if (LVar7 == 0) {
                strncpy((char *)local_448,param_1,0x3ff);
                local_49 = 0;
                lVar19 = -1;
                do {
                  lVar16 = lVar19 + 1;
                  lVar10 = lVar19 + 1;
                  lVar19 = lVar16;
                } while (local_448[lVar10] != '\0');
                local_4d0 = (int)lVar16 + 1;
                RegSetValueExA(*(HKEY *)((longlong)local_478 + (longlong)local_478[0][1].unused),
                               "name",0,1,local_448,local_4d0);
                local_4cc = local_4c0;
                if (local_4c0 == -1) {
                  local_4cc = iVar15 + 1;
                }
                RegSetValueExA(*(HKEY *)((longlong)local_478 + (longlong)local_478[0][1].unused),
                               "Position",0,4,(BYTE *)&local_4cc,4);
                local_4bc = local_458;
                RegSetValueExA(*(HKEY *)((longlong)local_478 + (longlong)local_478[0][1].unused),
                               "Active",0,4,(BYTE *)&local_4bc,4);
                if (local_478[1] != (HKEY)0x0) {
                  RegCloseKey(local_478[1]);
                  local_478[1] = (HKEY)0x0;
                }
                local_468 = 0;
                if (local_550[1] != (HKEY)0x0) {
                  RegCloseKey(local_550[1]);
                  local_550[1] = (HKEY)0x0;
                }
                local_540 = 0;
                if (local_4f0[1] != (HKEY)0x0) {
                  RegCloseKey(local_4f0[1]);
                  local_4f0[1] = (HKEY)0x0;
                }
                local_4e0 = 0;
                if (local_510[1] != (HKEY)0x0) {
                  RegCloseKey(local_510[1]);
                  local_510[1] = (HKEY)0x0;
                }
                local_500 = 0;
                if (local_530[1] != (HKEY)0x0) {
                  RegCloseKey(local_530[1]);
                  local_530[1] = (HKEY)0x0;
                }
                local_520 = 0;
                if (local_498[1] != (HKEY)0x0) {
                  RegCloseKey(local_498[1]);
                }
                return 1;
              }
              if (local_478[1] != (HKEY)0x0) {
                RegCloseKey(local_478[1]);
                local_478[1] = (HKEY)0x0;
              }
              local_468 = 0;
              if (local_550[1] != (HKEY)0x0) {
                RegCloseKey(local_550[1]);
                local_550[1] = (HKEY)0x0;
              }
              local_540 = 0;
              if (local_4f0[1] != (HKEY)0x0) {
                RegCloseKey(local_4f0[1]);
                local_4f0[1] = (HKEY)0x0;
              }
              local_4e0 = 0;
              if (local_510[1] != (HKEY)0x0) {
                RegCloseKey(local_510[1]);
                local_510[1] = (HKEY)0x0;
              }
              local_500 = 0;
              if (local_530[1] != (HKEY)0x0) {
                RegCloseKey(local_530[1]);
                local_530[1] = (HKEY)0x0;
              }
              local_520 = 0;
            }
            else {
              free(_Memory);
              if (local_550[1] != (HKEY)0x0) {
                RegCloseKey(local_550[1]);
                local_550[1] = (HKEY)0x0;
              }
LAB_1800335d1:
              local_540 = 0;
              if (local_4f0[1] != (HKEY)0x0) {
                RegCloseKey(local_4f0[1]);
                local_4f0[1] = (HKEY)0x0;
              }
              local_4e0 = 0;
              if (local_510[1] != (HKEY)0x0) {
                RegCloseKey(local_510[1]);
                local_510[1] = (HKEY)0x0;
              }
              local_500 = 0;
              if (local_530[1] != (HKEY)0x0) {
                RegCloseKey(local_530[1]);
                local_530[1] = (HKEY)0x0;
              }
              local_520 = 0;
            }
            goto LAB_180033617;
          }
          if (local_550[1] != (HKEY)0x0) {
            RegCloseKey(local_550[1]);
            local_550[1] = (HKEY)0x0;
          }
          local_540 = 0;
        }
        else if (local_550[1] != (HKEY)0x0) {
          RegCloseKey(local_550[1]);
        }
        if (local_4f0[1] != (HKEY)0x0) {
          RegCloseKey(local_4f0[1]);
          local_4f0[1] = (HKEY)0x0;
        }
        local_4e0 = 0;
      }
      else {
        if (local_550[1] != (HKEY)0x0) {
          RegCloseKey(local_550[1]);
        }
        if (local_4f0[1] != (HKEY)0x0) {
          RegCloseKey(local_4f0[1]);
        }
      }
      if (local_510[1] != (HKEY)0x0) {
        RegCloseKey(local_510[1]);
        local_510[1] = (HKEY)0x0;
      }
      local_500 = 0;
    }
    else {
      if (local_550[1] != (HKEY)0x0) {
        RegCloseKey(local_550[1]);
      }
      if (local_4f0[1] != (HKEY)0x0) {
        RegCloseKey(local_4f0[1]);
      }
      if (local_510[1] != (HKEY)0x0) {
        RegCloseKey(local_510[1]);
      }
    }
    if (local_530[1] != (HKEY)0x0) {
      RegCloseKey(local_530[1]);
      local_530[1] = (HKEY)0x0;
    }
    local_520 = 0;
  }
  else {
    if (local_550[1] != (HKEY)0x0) {
      RegCloseKey(local_550[1]);
    }
    if (local_4f0[1] != (HKEY)0x0) {
      RegCloseKey(local_4f0[1]);
    }
    if (local_510[1] != (HKEY)0x0) {
      RegCloseKey(local_510[1]);
    }
    if (local_530[1] != (HKEY)0x0) {
      RegCloseKey(local_530[1]);
    }
  }
LAB_180033617:
  if (local_498[1] != (HKEY)0x0) {
    RegCloseKey(local_498[1]);
  }
  return 0;
}

/* ---- FUNC 000338D0 FUN_1800338d0 (41 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

DWORD FUN_1800338d0(void)

{
  BYTE BVar1;
  BYTE BVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  void *pvVar5;
  bool bVar6;
  LSTATUS LVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  void *pvVar11;
  BYTE *pBVar12;
  longlong lVar13;
  longlong lVar14;
  longlong lVar15;
  undefined8 *puVar16;
  LPCSTR pCVar17;
  DWORD DVar18;
  DWORD dwIndex;
  undefined1 auStackY_398 [32];
  DWORD local_348 [2];
  DWORD local_340;
  DWORD local_33c;
  DWORD local_338;
  DWORD local_334;
  DWORD local_330 [2];
  HKEY local_328 [2];
  undefined4 local_318;
  undefined8 local_310;
  HKEY local_308 [2];
  undefined4 local_2f8;
  undefined8 local_2f0;
  DWORD local_2e8;
  DWORD local_2e4;
  _FILETIME local_2e0;
  HKEY local_2d8 [2];
  undefined4 local_2c8;
  undefined8 local_2c0;
  HKEY local_2b8 [2];
  undefined4 local_2a8;
  undefined8 local_2a0;
  DWORD local_298;
  DWORD local_294;
  longlong local_290;
  undefined1 local_288;
  undefined7 uStack_287;
  ulonglong auStack_280 [3];
  CHAR local_268 [24];
  CHAR local_250 [23];
  char acStack_239 [257];
  BYTE local_138 [256];
  ulonglong local_38;
  
  local_38 = DAT_1800791f8 ^ (ulonglong)auStackY_398;
  DVar18 = 0;
  local_2d8[1] = (HKEY)0x0;
  local_2d8[0] = (HKEY)&DAT_180053988;
  local_308[0] = (HKEY)&DAT_180053988;
  local_2c8 = 0;
  local_2c0 = 0;
  local_308[1] = (HKEY)0x0;
  local_2f8 = 0;
  local_2f0 = 0;
  FUN_180031fb0(&local_290,"Software\\AspenTech\\",1);
  pvVar11 = (void *)FUN_180024130();
  FUN_180029360((longlong *)((longlong)&local_290 + (longlong)*(int *)(local_290 + 4)),pvVar11);
  lVar14 = (longlong)*(int *)(local_290 + 4);
  puVar16 = (undefined8 *)((longlong)&local_290 + lVar14);
  uVar3 = *(ulonglong *)((longlong)auStack_280 + lVar14 + 8);
  uVar4 = *(ulonglong *)((longlong)auStack_280 + lVar14);
  if (uVar3 == uVar4) {
    FUN_180017f00(puVar16,1,0,&DAT_180053ef4,1);
  }
  else {
    *(ulonglong *)((longlong)auStack_280 + lVar14) = uVar4 + 1;
    if (0xf < uVar3) {
      puVar16 = (undefined8 *)*puVar16;
    }
    *(undefined2 *)((longlong)puVar16 + uVar4) = 0x5c;
  }
  pvVar11 = (void *)FUN_180024170();
  FUN_180029360((longlong *)((longlong)&local_290 + (longlong)*(int *)(local_290 + 4)),pvVar11);
  lVar14 = (longlong)*(int *)(local_290 + 4);
  puVar16 = (undefined8 *)((longlong)&local_290 + lVar14);
  uVar3 = *(ulonglong *)((longlong)auStack_280 + lVar14 + 8);
  uVar4 = *(ulonglong *)((longlong)auStack_280 + lVar14);
  if (uVar3 == uVar4) {
    FUN_180017f00(puVar16,1,0,&DAT_180053ef4,1);
  }
  else {
    *(ulonglong *)((longlong)auStack_280 + lVar14) = uVar4 + 1;
    if (0xf < uVar3) {
      puVar16 = (undefined8 *)*puVar16;
    }
    *(undefined2 *)((longlong)puVar16 + uVar4) = 0x5c;
  }
  lVar15 = (longlong)*(int *)(local_290 + 4);
  puVar16 = (undefined8 *)((longlong)&local_290 + lVar15);
  uVar3 = *(ulonglong *)((longlong)auStack_280 + lVar15 + 8);
  lVar14 = *(longlong *)((longlong)auStack_280 + lVar15);
  if (uVar3 - lVar14 < 10) {
    FUN_180017f00(puVar16,10,0,"Categories",10);
  }
  else {
    *(longlong *)((longlong)auStack_280 + lVar15) = lVar14 + 10;
    if (0xf < uVar3) {
      puVar16 = (undefined8 *)*puVar16;
    }
    memmove((void *)((longlong)puVar16 + lVar14),"Categories",10);
    *(undefined1 *)((longlong)puVar16 + lVar14 + 10) = 0;
  }
  pCVar17 = (LPCSTR)((longlong)&local_290 + (longlong)*(int *)(local_290 + 4));
  if (0xf < *(ulonglong *)((longlong)auStack_280 + (longlong)*(int *)(local_290 + 4) + 8)) {
    pCVar17 = *(LPCSTR *)pCVar17;
  }
  LVar7 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000002,pCVar17,0,0x20019,
                        (PHKEY)((longlong)local_2d8 + (longlong)local_2d8[0][1].unused));
  if (LVar7 == 0) {
    pCVar17 = (LPCSTR)((longlong)&local_290 + (longlong)*(int *)(local_290 + 4));
    if (0xf < *(ulonglong *)((longlong)auStack_280 + (longlong)*(int *)(local_290 + 4) + 8)) {
      pCVar17 = *(LPCSTR *)pCVar17;
    }
    LVar7 = RegCreateKeyExA((HKEY)&DAT_ffffffff80000001,pCVar17,0,(LPSTR)0x0,0,0xf003f,
                            (LPSECURITY_ATTRIBUTES)0x0,
                            (PHKEY)((longlong)local_308 + (longlong)local_308[0][1].unused),
                            &local_298);
    if (LVar7 == 0) {
      local_338 = 0x18;
      local_334 = 0x100;
      local_340 = 0x100;
      iVar8 = RegEnumKeyExA(*(HKEY *)((longlong)local_2d8 + (longlong)local_2d8[0][1].unused),0,
                            local_250,&local_338,(LPDWORD)0x0,(LPSTR)0x0,(LPDWORD)0x0,&local_2e0);
      dwIndex = DVar18;
      while (DVar18 = 1, iVar8 == 0) {
        local_2b8[0] = (HKEY)&DAT_180053988;
        local_2b8[1] = (HKEY)0x0;
        local_2a8 = 0;
        local_2a0 = 0;
        LVar7 = RegOpenKeyExA(*(HKEY *)((longlong)local_2d8 + (longlong)local_2d8[0][1].unused),
                              local_250,0,0x20019,local_2b8 + 1);
        if (LVar7 == 0) {
          local_334 = 0x100;
          LVar7 = RegQueryValueExA(*(HKEY *)((longlong)local_2b8 + (longlong)local_2b8[0][1].unused)
                                   ,"name",(LPDWORD)0x0,(LPDWORD)0x0,local_138,&local_334);
          if (LVar7 == 0) {
            local_33c = 0x18;
            iVar9 = RegEnumKeyExA(*(HKEY *)((longlong)local_308 + (longlong)local_308[0][1].unused),
                                  0,local_268,&local_33c,(LPDWORD)0x0,(LPSTR)0x0,(LPDWORD)0x0,
                                  &local_2e0);
            iVar8 = -1;
            DVar18 = 0;
            while (bVar6 = false, iVar9 == 0) {
              local_328[0] = (HKEY)&DAT_180053988;
              local_328[1] = (HKEY)0x0;
              local_318 = 0;
              local_310 = 0;
              LVar7 = RegOpenKeyExA(*(HKEY *)((longlong)local_308 + (longlong)local_308[0][1].unused
                                             ),local_268,0,0x20019,local_328 + 1);
              if (LVar7 == 0) {
                local_340 = 0x100;
                LVar7 = RegQueryValueExA(*(HKEY *)((longlong)local_328 +
                                                  (longlong)local_328[0][1].unused),"name",
                                         (LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)(acStack_239 + 1),
                                         &local_340);
                if (LVar7 == 0) {
                  pBVar12 = local_138;
                  lVar14 = 1 - (longlong)pBVar12;
                  do {
                    BVar1 = *pBVar12;
                    BVar2 = pBVar12[(longlong)(acStack_239 + lVar14)];
                    if (BVar1 != BVar2) break;
                    pBVar12 = pBVar12 + 1;
                  } while (BVar2 != '\0');
                  if (BVar1 == BVar2) {
                    bVar6 = true;
                    if (local_328[1] != (HKEY)0x0) {
                      RegCloseKey(local_328[1]);
                      bVar6 = true;
                    }
                    break;
                  }
                }
              }
              iVar10 = atoi(local_268);
              local_33c = 0x18;
              if (iVar10 < iVar8) {
                iVar10 = iVar8;
              }
              if (local_328[1] != (HKEY)0x0) {
                RegCloseKey(local_328[1]);
              }
              iVar9 = RegEnumKeyExA(*(HKEY *)((longlong)local_308 + (longlong)local_308[0][1].unused
                                             ),DVar18 + 1,local_268,&local_33c,(LPDWORD)0x0,
                                    (LPSTR)0x0,(LPDWORD)0x0,&local_2e0);
              iVar8 = iVar10;
              DVar18 = DVar18 + 1;
            }
            if (!bVar6) {
              iVar9 = DVar18 + 1;
              if ((int)(DVar18 + 1) < iVar8) {
                iVar9 = iVar8;
              }
              _itoa(iVar9 + 1,local_268,10);
              local_328[0] = (HKEY)&DAT_180053988;
              local_328[1] = (HKEY)0x0;
              local_318 = 0;
              local_310 = 0;
              LVar7 = RegCreateKeyExA(*(HKEY *)((longlong)local_308 +
                                               (longlong)local_308[0][1].unused),local_268,0,
                                      (LPSTR)0x0,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,local_328 + 1,
                                      &local_294);
              if (LVar7 == 0) {
                local_348[0] = 0x100;
                local_340 = 0;
                LVar7 = RegQueryValueExA(*(HKEY *)((longlong)local_2b8 +
                                                  (longlong)local_2b8[0][1].unused),"name",
                                         (LPDWORD)0x0,&local_2e8,(LPBYTE)(acStack_239 + 1),local_348
                                        );
                if ((LVar7 == 0) && (local_2e8 == 1 || local_2e8 == 2)) {
                  if (local_348[0] == 0) {
                    acStack_239[1] = 0;
                  }
                  else if (acStack_239[local_348[0]] != '\0') goto LAB_180033ef2;
                  local_340 = local_348[0];
                  lVar14 = -1;
                  do {
                    lVar13 = lVar14 + 1;
                    lVar15 = lVar14 + 2;
                    lVar14 = lVar13;
                  } while (acStack_239[lVar15] != '\0');
                  RegSetValueExA(*(HKEY *)((longlong)local_328 + (longlong)local_328[0][1].unused),
                                 "name",0,1,(BYTE *)(acStack_239 + 1),(int)lVar13 + 1);
                }
LAB_180033ef2:
                local_348[0] = 4;
                LVar7 = RegQueryValueExA(*(HKEY *)((longlong)local_2b8 +
                                                  (longlong)local_2b8[0][1].unused),"position",
                                         (LPDWORD)0x0,&local_2e4,(LPBYTE)local_330,local_348);
                if ((LVar7 == 0) && (local_2e4 == 4)) {
                  local_348[0] = local_330[0];
                  RegSetValueExA(*(HKEY *)((longlong)local_328 + (longlong)local_328[0][1].unused),
                                 "position",0,4,(BYTE *)local_348,4);
                }
              }
              if (local_328[1] != (HKEY)0x0) {
                RegCloseKey(local_328[1]);
              }
            }
          }
        }
        dwIndex = dwIndex + 1;
        local_338 = 0x18;
        if (local_2b8[1] != (HKEY)0x0) {
          RegCloseKey(local_2b8[1]);
        }
        iVar8 = RegEnumKeyExA(*(HKEY *)((longlong)local_2d8 + (longlong)local_2d8[0][1].unused),
                              dwIndex,local_250,&local_338,(LPDWORD)0x0,(LPSTR)0x0,(LPDWORD)0x0,
                              &local_2e0);
      }
    }
  }
  if (0xf < auStack_280[2]) {
    pvVar5 = (void *)CONCAT71(uStack_287,local_288);
    pvVar11 = pvVar5;
    if ((0xfff < auStack_280[2] + 1) &&
       (pvVar11 = *(void **)((longlong)pvVar5 + -8),
       0x1f < (ulonglong)((longlong)pvVar5 + (-8 - (longlong)pvVar11)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar11);
  }
  local_288 = 0;
  auStack_280[1] = _DAT_180053820;
  auStack_280[2] = _UNK_180053828;
  if (local_308[1] != (HKEY)0x0) {
    RegCloseKey(local_308[1]);
    local_308[1] = (HKEY)0x0;
  }
  local_2f8 = 0;
  if (local_2d8[1] != (HKEY)0x0) {
    RegCloseKey(local_2d8[1]);
  }
  return DVar18;
}

/* ---- FUNC 000338F9 FUN_1800338f9 (296 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_1800338f9(void)

{
  char cVar1;
  uint uVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  LSTATUS LVar6;
  int iVar7;
  uint uVar8;
  void *pvVar9;
  LPDWORD pDVar10;
  longlong lVar11;
  undefined8 *puVar13;
  void *pvVar14;
  LPCSTR pCVar15;
  uint uVar16;
  ulonglong uVar17;
  LPDWORD unaff_RBP;
  DWORD DVar18;
  char cVar19;
  DWORD dwOptions;
  LPSECURITY_ATTRIBUTES unaff_R12;
  ulonglong uVar20;
  ulonglong uVar21;
  DWORD in_stack_00000050;
  DWORD DStack0000000000000058;
  undefined4 uStack000000000000005c;
  DWORD DStack0000000000000060;
  undefined4 uStack0000000000000064;
  DWORD in_stack_00000068;
  undefined *in_stack_00000070;
  LPSECURITY_ATTRIBUTES in_stack_00000078;
  longlong lVar12;
  
  *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0xe) = unaff_R12;
  uVar20 = 1;
  *(undefined **)(unaff_RBP + -0x10) = &DAT_180053988;
  *(undefined **)(unaff_RBP + -0x1c) = &DAT_180053988;
  dwOptions = (DWORD)unaff_R12;
  unaff_RBP[-0xc] = dwOptions;
  *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -10) = unaff_R12;
  *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x1a) = unaff_R12;
  unaff_RBP[-0x18] = dwOptions;
  *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x16) = unaff_R12;
  FUN_180031fb0((longlong *)(unaff_RBP + 2),"Software\\AspenTech\\",1);
  pvVar9 = (void *)FUN_180024130();
  FUN_180029360((longlong *)
                ((longlong)unaff_RBP + (longlong)*(int *)(*(longlong *)(unaff_RBP + 2) + 4) + 8),
                pvVar9);
  puVar13 = (undefined8 *)
            ((longlong)unaff_RBP + (longlong)*(int *)(*(longlong *)(unaff_RBP + 2) + 4) + 8);
  uVar21 = puVar13[2];
  if (puVar13[3] == uVar21) {
    FUN_180017f00(puVar13,1,0,&DAT_180053ef4,1);
  }
  else {
    puVar13[2] = uVar21 + 1;
    if (0xf < (ulonglong)puVar13[3]) {
      puVar13 = (undefined8 *)*puVar13;
    }
    *(undefined2 *)((longlong)puVar13 + uVar21) = 0x5c;
  }
  pvVar9 = (void *)FUN_180024170();
  FUN_180029360((longlong *)
                ((longlong)unaff_RBP + (longlong)*(int *)(*(longlong *)(unaff_RBP + 2) + 4) + 8),
                pvVar9);
  puVar13 = (undefined8 *)
            ((longlong)unaff_RBP + (longlong)*(int *)(*(longlong *)(unaff_RBP + 2) + 4) + 8);
  uVar21 = puVar13[2];
  if (puVar13[3] == uVar21) {
    FUN_180017f00(puVar13,1,0,&DAT_180053ef4,1);
  }
  else {
    puVar13[2] = uVar21 + 1;
    if (0xf < (ulonglong)puVar13[3]) {
      puVar13 = (undefined8 *)*puVar13;
    }
    *(undefined2 *)((longlong)puVar13 + uVar21) = 0x5c;
  }
  puVar13 = (undefined8 *)
            ((longlong)unaff_RBP + (longlong)*(int *)(*(longlong *)(unaff_RBP + 2) + 4) + 8);
  lVar12 = puVar13[2];
  cVar19 = (char)unaff_R12;
  if ((ulonglong)(puVar13[3] - lVar12) < 10) {
    FUN_180017f00(puVar13,10,0,"Categories",10);
  }
  else {
    puVar13[2] = lVar12 + 10;
    if (0xf < (ulonglong)puVar13[3]) {
      puVar13 = (undefined8 *)*puVar13;
    }
    memmove((void *)((longlong)puVar13 + lVar12),"Categories",10);
    *(char *)((longlong)puVar13 + lVar12 + 10) = cVar19;
  }
  pCVar15 = (LPCSTR)((longlong)unaff_RBP + (longlong)*(int *)(*(longlong *)(unaff_RBP + 2) + 4) + 8)
  ;
  if (0xf < *(ulonglong *)(pCVar15 + 0x18)) {
    pCVar15 = *(LPCSTR *)pCVar15;
  }
  LVar6 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000002,pCVar15,0,0x20019,
                        (PHKEY)((longlong)unaff_RBP +
                               (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x10) + 4) + -0x40));
  if (LVar6 == 0) {
    pCVar15 = (LPCSTR)((longlong)unaff_RBP +
                      (longlong)*(int *)(*(longlong *)(unaff_RBP + 2) + 4) + 8);
    if (0xf < *(ulonglong *)(pCVar15 + 0x18)) {
      pCVar15 = *(LPCSTR *)pCVar15;
    }
    LVar6 = RegCreateKeyExA((HKEY)&DAT_ffffffff80000001,pCVar15,0,(LPSTR)0x0,dwOptions,0xf003f,
                            unaff_R12,
                            (PHKEY)((longlong)unaff_RBP +
                                   (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x1c) + 4) + -0x70)
                            ,unaff_RBP);
    if (LVar6 == 0) {
      DStack0000000000000060 = 0x18;
      uStack0000000000000064 = 0x100;
      DStack0000000000000058 = 0x100;
      uVar21 = (ulonglong)unaff_R12 & 0xffffffff;
      iVar7 = RegEnumKeyExA(*(HKEY *)((longlong)unaff_RBP +
                                     (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x10) + 4) +
                                     -0x40),0,(LPSTR)(unaff_RBP + 0x12),&stack0x00000060,
                            &unaff_R12->nLength,(LPSTR)unaff_R12,&unaff_R12->nLength,
                            (PFILETIME)(unaff_RBP + -0x12));
      while (iVar7 == 0) {
        *(undefined **)(unaff_RBP + -8) = &DAT_180053988;
        *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -6) = unaff_R12;
        unaff_RBP[-4] = dwOptions;
        *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -2) = unaff_R12;
        LVar6 = RegOpenKeyExA(*(HKEY *)((longlong)unaff_RBP +
                                       (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x10) + 4) +
                                       -0x40),(LPCSTR)(unaff_RBP + 0x12),0,0x20019,
                              (PHKEY)(unaff_RBP + -6));
        if (LVar6 == 0) {
          uStack0000000000000064 = 0x100;
          LVar6 = RegQueryValueExA(*(HKEY *)((longlong)unaff_RBP +
                                            (longlong)*(int *)(*(longlong *)(unaff_RBP + -8) + 4) +
                                            -0x20),"name",(LPDWORD)0x0,(LPDWORD)0x0,
                                   (LPBYTE)(unaff_RBP + 0x58),
                                   (LPDWORD)((longlong)&stack0x00000060 + 4));
          if (LVar6 == 0) {
            uStack000000000000005c = 0x18;
            uVar17 = (ulonglong)unaff_R12 & 0xffffffff;
            iVar7 = RegEnumKeyExA(*(HKEY *)((longlong)unaff_RBP +
                                           (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x1c) + 4)
                                           + -0x70),0,(LPSTR)(unaff_RBP + 0xc),
                                  (LPDWORD)((longlong)&stack0x00000058 + 4),&unaff_R12->nLength,
                                  (LPSTR)unaff_R12,&unaff_R12->nLength,
                                  (PFILETIME)(unaff_RBP + -0x12));
            uVar16 = dwOptions;
            uVar2 = 0xffffffff;
            while (iVar7 == 0) {
              in_stack_00000070 = &DAT_180053988;
              unaff_RBP[-0x20] = dwOptions;
              uVar16 = (int)uVar17 + 1;
              uVar17 = (ulonglong)uVar16;
              *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x1e) = unaff_R12;
              in_stack_00000078 = unaff_R12;
              LVar6 = RegOpenKeyExA(*(HKEY *)((longlong)unaff_RBP +
                                             (longlong)
                                             *(int *)(*(longlong *)(unaff_RBP + -0x1c) + 4) + -0x70)
                                    ,(LPCSTR)(unaff_RBP + 0xc),0,0x20019,(PHKEY)&stack0x00000078);
              if (LVar6 == 0) {
                DStack0000000000000058 = 0x100;
                LVar6 = RegQueryValueExA(*(HKEY *)((longlong)&stack0x00000070 +
                                                  (longlong)*(int *)(in_stack_00000070 + 4)),"name",
                                         (LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)(unaff_RBP + 0x18),
                                         &stack0x00000058);
                if (LVar6 == 0) {
                  pDVar10 = unaff_RBP + 0x58;
                  lVar12 = 0x60 - (longlong)pDVar10;
                  do {
                    DVar18 = *pDVar10;
                    cVar1 = *(char *)((longlong)pDVar10 + (longlong)unaff_RBP + lVar12);
                    if ((char)DVar18 != cVar1) break;
                    pDVar10 = (LPDWORD)((longlong)pDVar10 + 1);
                  } while (cVar1 != '\0');
                  if ((char)DVar18 == cVar1) {
                    DVar18 = 1;
                    if (in_stack_00000078 != (LPSECURITY_ATTRIBUTES)0x0) {
                      RegCloseKey((HKEY)in_stack_00000078);
                      DVar18 = 1;
                    }
                    goto LAB_180033da4;
                  }
                }
              }
              uVar8 = atoi((char *)(unaff_RBP + 0xc));
              uStack000000000000005c = 0x18;
              if ((int)uVar8 < (int)uVar2) {
                uVar8 = uVar2;
              }
              if (in_stack_00000078 != (LPSECURITY_ATTRIBUTES)0x0) {
                RegCloseKey((HKEY)in_stack_00000078);
              }
              iVar7 = RegEnumKeyExA(*(HKEY *)((longlong)unaff_RBP +
                                             (longlong)
                                             *(int *)(*(longlong *)(unaff_RBP + -0x1c) + 4) + -0x70)
                                    ,uVar16,(LPSTR)(unaff_RBP + 0xc),
                                    (LPDWORD)((longlong)&stack0x00000058 + 4),&unaff_R12->nLength,
                                    (LPSTR)unaff_R12,&unaff_R12->nLength,
                                    (PFILETIME)(unaff_RBP + -0x12));
              uVar2 = uVar8;
            }
            uVar16 = uVar16 + 1;
            DVar18 = dwOptions;
LAB_180033da4:
            if (DVar18 == 0) {
              if ((int)uVar16 < (int)uVar2) {
                uVar16 = uVar2;
              }
              _itoa(uVar16 + 1,(char *)(unaff_RBP + 0xc),10);
              in_stack_00000070 = &DAT_180053988;
              unaff_RBP[-0x20] = dwOptions;
              *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x1e) = unaff_R12;
              in_stack_00000078 = unaff_R12;
              LVar6 = RegCreateKeyExA(*(HKEY *)((longlong)unaff_RBP +
                                               (longlong)
                                               *(int *)(*(longlong *)(unaff_RBP + -0x1c) + 4) +
                                               -0x70),(LPCSTR)(unaff_RBP + 0xc),0,(LPSTR)0x0,
                                      dwOptions,0xf003f,unaff_R12,(PHKEY)&stack0x00000078,
                                      unaff_RBP + 1);
              if (LVar6 == 0) {
                in_stack_00000050 = 0x100;
                DStack0000000000000058 = dwOptions;
                LVar6 = RegQueryValueExA(*(HKEY *)((longlong)unaff_RBP +
                                                  (longlong)
                                                  *(int *)(*(longlong *)(unaff_RBP + -8) + 4) +
                                                  -0x20),"name",(LPDWORD)0x0,unaff_RBP + -0x14,
                                         (LPBYTE)(unaff_RBP + 0x18),&stack0x00000050);
                if ((LVar6 == 0) && (unaff_RBP[-0x14] == 1 || unaff_RBP[-0x14] == 2)) {
                  if (in_stack_00000050 == 0) {
                    *(char *)(unaff_RBP + 0x18) = cVar19;
                  }
                  else if (*(char *)((longlong)unaff_RBP + (ulonglong)in_stack_00000050 + 0x5f) !=
                           cVar19) goto LAB_180033ef2;
                  DStack0000000000000058 = in_stack_00000050;
                  lVar12 = -1;
                  do {
                    lVar11 = lVar12 + 1;
                    lVar3 = lVar12 + 0x61;
                    lVar12 = lVar11;
                  } while (*(char *)((longlong)unaff_RBP + lVar3) != cVar19);
                  RegSetValueExA(*(HKEY *)((longlong)&stack0x00000070 +
                                          (longlong)*(int *)(in_stack_00000070 + 4)),"name",0,1,
                                 (BYTE *)(unaff_RBP + 0x18),(int)lVar11 + 1);
                }
LAB_180033ef2:
                in_stack_00000050 = 4;
                LVar6 = RegQueryValueExA(*(HKEY *)((longlong)unaff_RBP +
                                                  (longlong)
                                                  *(int *)(*(longlong *)(unaff_RBP + -8) + 4) +
                                                  -0x20),"position",(LPDWORD)0x0,unaff_RBP + -0x13,
                                         (LPBYTE)&stack0x00000068,&stack0x00000050);
                if ((LVar6 == 0) && (unaff_RBP[-0x13] == 4)) {
                  in_stack_00000050 = in_stack_00000068;
                  RegSetValueExA(*(HKEY *)((longlong)&stack0x00000070 +
                                          (longlong)*(int *)(in_stack_00000070 + 4)),"position",0,4,
                                 (BYTE *)&stack0x00000050,4);
                }
              }
              if (in_stack_00000078 != (LPSECURITY_ATTRIBUTES)0x0) {
                RegCloseKey((HKEY)in_stack_00000078);
              }
            }
          }
        }
        uVar16 = (int)uVar21 + 1;
        uVar21 = (ulonglong)uVar16;
        DStack0000000000000060 = 0x18;
        if (*(HKEY *)(unaff_RBP + -6) != (HKEY)0x0) {
          RegCloseKey(*(HKEY *)(unaff_RBP + -6));
        }
        iVar7 = RegEnumKeyExA(*(HKEY *)((longlong)unaff_RBP +
                                       (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x10) + 4) +
                                       -0x40),uVar16,(LPSTR)(unaff_RBP + 0x12),&stack0x00000060,
                              &unaff_R12->nLength,(LPSTR)unaff_R12,&unaff_R12->nLength,
                              (PFILETIME)(unaff_RBP + -0x12));
      }
      goto LAB_180033ffd;
    }
  }
  uVar20 = (ulonglong)unaff_R12 & 0xffffffff;
LAB_180033ffd:
  if (0xf < *(ulonglong *)(unaff_RBP + 10)) {
    pvVar9 = *(void **)(unaff_RBP + 4);
    pvVar14 = pvVar9;
    if ((0xfff < *(ulonglong *)(unaff_RBP + 10) + 1) &&
       (pvVar14 = *(void **)((longlong)pvVar9 + -8),
       0x1f < (ulonglong)((longlong)pvVar9 + (-8 - (longlong)pvVar14)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar14);
  }
  uVar5 = _UNK_180053828;
  uVar4 = _DAT_180053820;
  *(char *)(unaff_RBP + 4) = cVar19;
  *(undefined8 *)(unaff_RBP + 8) = uVar4;
  *(undefined8 *)(unaff_RBP + 10) = uVar5;
  if (*(HKEY *)(unaff_RBP + -0x1a) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x1a));
    *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x1a) = unaff_R12;
  }
  unaff_RBP[-0x18] = dwOptions;
  if (*(HKEY *)(unaff_RBP + -0xe) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0xe));
  }
  return uVar20;
}

/* ---- FUNC 00033A21 FUN_180033a21 (356 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_180033a21(void)

{
  char cVar1;
  void *pvVar2;
  uint uVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  LSTATUS LVar7;
  int iVar8;
  uint uVar9;
  longlong in_RAX;
  LPDWORD pDVar10;
  longlong lVar11;
  undefined8 *puVar13;
  void *pvVar14;
  LPCSTR pCVar15;
  uint uVar16;
  ulonglong uVar17;
  LPDWORD unaff_RBP;
  DWORD DVar18;
  char cVar19;
  DWORD dwOptions;
  LPSECURITY_ATTRIBUTES unaff_R12;
  longlong unaff_R13;
  DWORD dwType;
  ulonglong unaff_R14;
  ulonglong uVar20;
  DWORD in_stack_00000050;
  DWORD DStack0000000000000058;
  undefined4 uStack000000000000005c;
  DWORD DStack0000000000000060;
  undefined4 uStack0000000000000064;
  DWORD in_stack_00000068;
  longlong in_stack_00000070;
  LPSECURITY_ATTRIBUTES in_stack_00000078;
  longlong lVar12;
  
  puVar13 = (undefined8 *)((longlong)unaff_RBP + (longlong)*(int *)(in_RAX + 4) + 8);
  lVar12 = puVar13[2];
  cVar19 = (char)unaff_R12;
  if ((ulonglong)(puVar13[3] - lVar12) < 10) {
    FUN_180017f00(puVar13,10,0,"Categories",10);
  }
  else {
    puVar13[2] = lVar12 + 10;
    if (0xf < (ulonglong)puVar13[3]) {
      puVar13 = (undefined8 *)*puVar13;
    }
    memmove((void *)((longlong)puVar13 + lVar12),"Categories",10);
    *(char *)((longlong)puVar13 + lVar12 + 10) = cVar19;
  }
  pCVar15 = (LPCSTR)((longlong)unaff_RBP + (longlong)*(int *)(*(longlong *)(unaff_RBP + 2) + 4) + 8)
  ;
  if (0xf < *(ulonglong *)(pCVar15 + 0x18)) {
    pCVar15 = *(LPCSTR *)pCVar15;
  }
  LVar7 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000002,pCVar15,0,0x20019,
                        (PHKEY)((longlong)unaff_RBP +
                               (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x10) + 4) + -0x40));
  dwOptions = (DWORD)unaff_R12;
  if (LVar7 == 0) {
    pCVar15 = (LPCSTR)((longlong)unaff_RBP +
                      (longlong)*(int *)(*(longlong *)(unaff_RBP + 2) + 4) + 8);
    if (0xf < *(ulonglong *)(pCVar15 + 0x18)) {
      pCVar15 = *(LPCSTR *)pCVar15;
    }
    LVar7 = RegCreateKeyExA((HKEY)&DAT_ffffffff80000001,pCVar15,0,(LPSTR)0x0,dwOptions,0xf003f,
                            unaff_R12,
                            (PHKEY)((longlong)unaff_RBP +
                                   (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x1c) + 4) + -0x70)
                            ,unaff_RBP);
    if (LVar7 == 0) {
      DStack0000000000000060 = 0x18;
      uStack0000000000000064 = 0x100;
      DStack0000000000000058 = 0x100;
      uVar20 = (ulonglong)unaff_R12 & 0xffffffff;
      iVar8 = RegEnumKeyExA(*(HKEY *)((longlong)unaff_RBP +
                                     (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x10) + 4) +
                                     -0x40),0,(LPSTR)(unaff_RBP + 0x12),&stack0x00000060,
                            &unaff_R12->nLength,(LPSTR)unaff_R12,&unaff_R12->nLength,
                            (PFILETIME)(unaff_RBP + -0x12));
      while (iVar8 == 0) {
        *(longlong *)(unaff_RBP + -8) = unaff_R13;
        *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -6) = unaff_R12;
        unaff_RBP[-4] = dwOptions;
        *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -2) = unaff_R12;
        LVar7 = RegOpenKeyExA(*(HKEY *)((longlong)unaff_RBP +
                                       (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x10) + 4) +
                                       -0x40),(LPCSTR)(unaff_RBP + 0x12),0,0x20019,
                              (PHKEY)(unaff_RBP + -6));
        if (LVar7 == 0) {
          uStack0000000000000064 = 0x100;
          LVar7 = RegQueryValueExA(*(HKEY *)((longlong)unaff_RBP +
                                            (longlong)*(int *)(*(longlong *)(unaff_RBP + -8) + 4) +
                                            -0x20),"name",(LPDWORD)0x0,(LPDWORD)0x0,
                                   (LPBYTE)(unaff_RBP + 0x58),
                                   (LPDWORD)((longlong)&stack0x00000060 + 4));
          if (LVar7 == 0) {
            uStack000000000000005c = 0x18;
            uVar17 = (ulonglong)unaff_R12 & 0xffffffff;
            iVar8 = RegEnumKeyExA(*(HKEY *)((longlong)unaff_RBP +
                                           (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x1c) + 4)
                                           + -0x70),0,(LPSTR)(unaff_RBP + 0xc),
                                  (LPDWORD)((longlong)&stack0x00000058 + 4),&unaff_R12->nLength,
                                  (LPSTR)unaff_R12,&unaff_R12->nLength,
                                  (PFILETIME)(unaff_RBP + -0x12));
            dwType = (DWORD)unaff_R14;
            uVar16 = dwOptions;
            uVar3 = 0xffffffff;
            while (iVar8 == 0) {
              unaff_RBP[-0x20] = dwOptions;
              uVar16 = (int)uVar17 + 1;
              uVar17 = (ulonglong)uVar16;
              *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x1e) = unaff_R12;
              in_stack_00000070 = unaff_R13;
              in_stack_00000078 = unaff_R12;
              LVar7 = RegOpenKeyExA(*(HKEY *)((longlong)unaff_RBP +
                                             (longlong)
                                             *(int *)(*(longlong *)(unaff_RBP + -0x1c) + 4) + -0x70)
                                    ,(LPCSTR)(unaff_RBP + 0xc),0,0x20019,(PHKEY)&stack0x00000078);
              if (LVar7 == 0) {
                DStack0000000000000058 = 0x100;
                LVar7 = RegQueryValueExA(*(HKEY *)((longlong)&stack0x00000070 +
                                                  (longlong)*(int *)(in_stack_00000070 + 4)),"name",
                                         (LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)(unaff_RBP + 0x18),
                                         &stack0x00000058);
                if (LVar7 == 0) {
                  pDVar10 = unaff_RBP + 0x58;
                  lVar12 = 0x60 - (longlong)pDVar10;
                  do {
                    DVar18 = *pDVar10;
                    cVar1 = *(char *)((longlong)pDVar10 + (longlong)unaff_RBP + lVar12);
                    if ((char)DVar18 != cVar1) break;
                    pDVar10 = (LPDWORD)((longlong)pDVar10 + 1);
                  } while (cVar1 != '\0');
                  if ((char)DVar18 == cVar1) {
                    DVar18 = dwType;
                    if (in_stack_00000078 != (LPSECURITY_ATTRIBUTES)0x0) {
                      RegCloseKey((HKEY)in_stack_00000078);
                    }
                    goto LAB_180033da4;
                  }
                }
              }
              uVar9 = atoi((char *)(unaff_RBP + 0xc));
              uStack000000000000005c = 0x18;
              if ((int)uVar9 < (int)uVar3) {
                uVar9 = uVar3;
              }
              if (in_stack_00000078 != (LPSECURITY_ATTRIBUTES)0x0) {
                RegCloseKey((HKEY)in_stack_00000078);
              }
              iVar8 = RegEnumKeyExA(*(HKEY *)((longlong)unaff_RBP +
                                             (longlong)
                                             *(int *)(*(longlong *)(unaff_RBP + -0x1c) + 4) + -0x70)
                                    ,uVar16,(LPSTR)(unaff_RBP + 0xc),
                                    (LPDWORD)((longlong)&stack0x00000058 + 4),&unaff_R12->nLength,
                                    (LPSTR)unaff_R12,&unaff_R12->nLength,
                                    (PFILETIME)(unaff_RBP + -0x12));
              uVar3 = uVar9;
            }
            uVar16 = uVar16 + 1;
            DVar18 = dwOptions;
LAB_180033da4:
            if (DVar18 == 0) {
              if ((int)uVar16 < (int)uVar3) {
                uVar16 = uVar3;
              }
              _itoa(uVar16 + 1,(char *)(unaff_RBP + 0xc),10);
              unaff_RBP[-0x20] = dwOptions;
              *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x1e) = unaff_R12;
              in_stack_00000070 = unaff_R13;
              in_stack_00000078 = unaff_R12;
              LVar7 = RegCreateKeyExA(*(HKEY *)((longlong)unaff_RBP +
                                               (longlong)
                                               *(int *)(*(longlong *)(unaff_RBP + -0x1c) + 4) +
                                               -0x70),(LPCSTR)(unaff_RBP + 0xc),0,(LPSTR)0x0,
                                      dwOptions,0xf003f,unaff_R12,(PHKEY)&stack0x00000078,
                                      unaff_RBP + 1);
              if (LVar7 == 0) {
                in_stack_00000050 = 0x100;
                DStack0000000000000058 = dwOptions;
                LVar7 = RegQueryValueExA(*(HKEY *)((longlong)unaff_RBP +
                                                  (longlong)
                                                  *(int *)(*(longlong *)(unaff_RBP + -8) + 4) +
                                                  -0x20),"name",(LPDWORD)0x0,unaff_RBP + -0x14,
                                         (LPBYTE)(unaff_RBP + 0x18),&stack0x00000050);
                if ((LVar7 == 0) && (unaff_RBP[-0x14] - 1 <= dwType)) {
                  if (in_stack_00000050 == 0) {
                    *(char *)(unaff_RBP + 0x18) = cVar19;
                  }
                  else if (*(char *)((longlong)unaff_RBP + (ulonglong)in_stack_00000050 + 0x5f) !=
                           cVar19) goto LAB_180033ef2;
                  DStack0000000000000058 = in_stack_00000050;
                  lVar12 = -1;
                  do {
                    lVar11 = lVar12 + 1;
                    lVar4 = lVar12 + 0x61;
                    lVar12 = lVar11;
                  } while (*(char *)((longlong)unaff_RBP + lVar4) != cVar19);
                  RegSetValueExA(*(HKEY *)((longlong)&stack0x00000070 +
                                          (longlong)*(int *)(in_stack_00000070 + 4)),"name",0,dwType
                                 ,(BYTE *)(unaff_RBP + 0x18),(int)lVar11 + 1);
                }
LAB_180033ef2:
                in_stack_00000050 = 4;
                LVar7 = RegQueryValueExA(*(HKEY *)((longlong)unaff_RBP +
                                                  (longlong)
                                                  *(int *)(*(longlong *)(unaff_RBP + -8) + 4) +
                                                  -0x20),"position",(LPDWORD)0x0,unaff_RBP + -0x13,
                                         (LPBYTE)&stack0x00000068,&stack0x00000050);
                if ((LVar7 == 0) && (unaff_RBP[-0x13] == 4)) {
                  in_stack_00000050 = in_stack_00000068;
                  RegSetValueExA(*(HKEY *)((longlong)&stack0x00000070 +
                                          (longlong)*(int *)(in_stack_00000070 + 4)),"position",0,4,
                                 (BYTE *)&stack0x00000050,4);
                }
              }
              if (in_stack_00000078 != (LPSECURITY_ATTRIBUTES)0x0) {
                RegCloseKey((HKEY)in_stack_00000078);
              }
            }
          }
        }
        uVar16 = (int)uVar20 + 1;
        uVar20 = (ulonglong)uVar16;
        DStack0000000000000060 = 0x18;
        if (*(HKEY *)(unaff_RBP + -6) != (HKEY)0x0) {
          RegCloseKey(*(HKEY *)(unaff_RBP + -6));
        }
        iVar8 = RegEnumKeyExA(*(HKEY *)((longlong)unaff_RBP +
                                       (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x10) + 4) +
                                       -0x40),uVar16,(LPSTR)(unaff_RBP + 0x12),&stack0x00000060,
                              &unaff_R12->nLength,(LPSTR)unaff_R12,&unaff_R12->nLength,
                              (PFILETIME)(unaff_RBP + -0x12));
      }
      goto LAB_180033ffd;
    }
  }
  unaff_R14 = (ulonglong)unaff_R12 & 0xffffffff;
LAB_180033ffd:
  if (0xf < *(ulonglong *)(unaff_RBP + 10)) {
    pvVar2 = *(void **)(unaff_RBP + 4);
    pvVar14 = pvVar2;
    if ((0xfff < *(ulonglong *)(unaff_RBP + 10) + 1) &&
       (pvVar14 = *(void **)((longlong)pvVar2 + -8),
       0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)pvVar14)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar14);
  }
  uVar6 = _UNK_180053828;
  uVar5 = _DAT_180053820;
  *(char *)(unaff_RBP + 4) = cVar19;
  *(undefined8 *)(unaff_RBP + 8) = uVar5;
  *(undefined8 *)(unaff_RBP + 10) = uVar6;
  if (*(HKEY *)(unaff_RBP + -0x1a) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x1a));
    *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x1a) = unaff_R12;
  }
  unaff_RBP[-0x18] = dwOptions;
  if (*(HKEY *)(unaff_RBP + -0xe) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0xe));
  }
  return unaff_R14 & 0xffffffff;
}

/* ---- FUNC 00033B85 FUN_180033b85 (30 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_180033b85(HKEY param_1,DWORD param_2,LPSTR param_3,LPDWORD param_4,LPSTR param_5,
                  LPDWORD param_6,PFILETIME param_7,undefined8 param_8,undefined8 param_9,
                  DWORD param_10,undefined8 param_11,undefined8 param_12,DWORD param_13,
                  longlong param_14,LPSECURITY_ATTRIBUTES param_15)

{
  char cVar1;
  char cVar2;
  void *pvVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  int iVar7;
  LSTATUS LVar8;
  uint uVar9;
  char *pcVar10;
  void *pvVar11;
  uint uVar12;
  ulonglong uVar13;
  longlong unaff_RBP;
  DWORD DVar14;
  longlong lVar15;
  char cVar16;
  DWORD dwOptions;
  LPSECURITY_ATTRIBUTES unaff_R12;
  longlong unaff_R13;
  uint unaff_R14D;
  ulonglong uVar17;
  
  dwOptions = (DWORD)unaff_R12;
  uVar17 = (ulonglong)unaff_R12 & 0xffffffff;
  iVar7 = RegEnumKeyExA(param_1,param_2,param_3,param_4,&unaff_R12->nLength,param_5,param_6,param_7)
  ;
  cVar16 = (char)unaff_R12;
  do {
    if (iVar7 != 0) {
      if (0xf < *(ulonglong *)(unaff_RBP + 0x28)) {
        pvVar3 = *(void **)(unaff_RBP + 0x10);
        pvVar11 = pvVar3;
        if ((0xfff < *(ulonglong *)(unaff_RBP + 0x28) + 1) &&
           (pvVar11 = *(void **)((longlong)pvVar3 + -8),
           0x1f < (ulonglong)((longlong)pvVar3 + (-8 - (longlong)pvVar11)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        operator_delete(pvVar11);
      }
      uVar6 = _UNK_180053828;
      uVar5 = _DAT_180053820;
      *(char *)(unaff_RBP + 0x10) = cVar16;
      *(undefined8 *)(unaff_RBP + 0x20) = uVar5;
      *(undefined8 *)(unaff_RBP + 0x28) = uVar6;
      if (*(HKEY *)(unaff_RBP + -0x68) != (HKEY)0x0) {
        RegCloseKey(*(HKEY *)(unaff_RBP + -0x68));
        *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x68) = unaff_R12;
      }
      *(DWORD *)(unaff_RBP + -0x60) = dwOptions;
      if (*(HKEY *)(unaff_RBP + -0x38) != (HKEY)0x0) {
        RegCloseKey(*(HKEY *)(unaff_RBP + -0x38));
      }
      return unaff_R14D;
    }
    *(longlong *)(unaff_RBP + -0x20) = unaff_R13;
    *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x18) = unaff_R12;
    *(DWORD *)(unaff_RBP + -0x10) = dwOptions;
    *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -8) = unaff_R12;
    LVar8 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + -0x40 +
                                   (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x40) + 4)),
                          (LPCSTR)(unaff_RBP + 0x48),0,0x20019,(PHKEY)(unaff_RBP + -0x18));
    if (LVar8 == 0) {
      param_12._4_4_ = 0x100;
      LVar8 = RegQueryValueExA(*(HKEY *)(unaff_RBP + -0x20 +
                                        (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x20) + 4)),
                               "name",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)(unaff_RBP + 0x160),
                               (LPDWORD)((longlong)&param_12 + 4));
      if (LVar8 == 0) {
        param_11._4_4_ = 0x18;
        uVar13 = (ulonglong)unaff_R12 & 0xffffffff;
        iVar7 = RegEnumKeyExA(*(HKEY *)(unaff_RBP + -0x70 +
                                       (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x70) + 4)),0,
                              (LPSTR)(unaff_RBP + 0x30),(LPDWORD)((longlong)&param_11 + 4),
                              &unaff_R12->nLength,(LPSTR)unaff_R12,&unaff_R12->nLength,
                              (PFILETIME)(unaff_RBP + -0x48));
        uVar12 = dwOptions;
        uVar4 = 0xffffffff;
        while (iVar7 == 0) {
          *(DWORD *)(unaff_RBP + -0x80) = dwOptions;
          uVar12 = (int)uVar13 + 1;
          uVar13 = (ulonglong)uVar12;
          *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x78) = unaff_R12;
          param_14 = unaff_R13;
          param_15 = unaff_R12;
          LVar8 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + -0x70 +
                                         (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x70) + 4)),
                                (LPCSTR)(unaff_RBP + 0x30),0,0x20019,(PHKEY)&stack0x00000078);
          if (LVar8 == 0) {
            param_11._0_4_ = 0x100;
            LVar8 = RegQueryValueExA(*(HKEY *)((longlong)&stack0x00000070 +
                                              (longlong)*(int *)(param_14 + 4)),"name",(LPDWORD)0x0,
                                     (LPDWORD)0x0,(LPBYTE)(unaff_RBP + 0x60),(LPDWORD)&param_11);
            if (LVar8 == 0) {
              pcVar10 = (char *)(unaff_RBP + 0x160);
              lVar15 = (unaff_RBP + 0x60) - (longlong)pcVar10;
              do {
                cVar1 = *pcVar10;
                cVar2 = pcVar10[lVar15];
                if (cVar1 != cVar2) break;
                pcVar10 = pcVar10 + 1;
              } while (cVar2 != '\0');
              if (cVar1 == cVar2) {
                DVar14 = unaff_R14D;
                if (param_15 != (LPSECURITY_ATTRIBUTES)0x0) {
                  RegCloseKey((HKEY)param_15);
                }
                goto LAB_180033da4;
              }
            }
          }
          uVar9 = atoi((char *)(unaff_RBP + 0x30));
          param_11._4_4_ = 0x18;
          if ((int)uVar9 < (int)uVar4) {
            uVar9 = uVar4;
          }
          if (param_15 != (LPSECURITY_ATTRIBUTES)0x0) {
            RegCloseKey((HKEY)param_15);
          }
          iVar7 = RegEnumKeyExA(*(HKEY *)(unaff_RBP + -0x70 +
                                         (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x70) + 4)),
                                uVar12,(LPSTR)(unaff_RBP + 0x30),(LPDWORD)((longlong)&param_11 + 4),
                                &unaff_R12->nLength,(LPSTR)unaff_R12,&unaff_R12->nLength,
                                (PFILETIME)(unaff_RBP + -0x48));
          uVar4 = uVar9;
        }
        uVar12 = uVar12 + 1;
        DVar14 = dwOptions;
LAB_180033da4:
        if (DVar14 == 0) {
          if ((int)uVar12 < (int)uVar4) {
            uVar12 = uVar4;
          }
          _itoa(uVar12 + 1,(char *)(unaff_RBP + 0x30),10);
          *(DWORD *)(unaff_RBP + -0x80) = dwOptions;
          *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x78) = unaff_R12;
          param_14 = unaff_R13;
          param_15 = unaff_R12;
          LVar8 = RegCreateKeyExA(*(HKEY *)(unaff_RBP + -0x70 +
                                           (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x70) + 4))
                                  ,(LPCSTR)(unaff_RBP + 0x30),0,(LPSTR)0x0,dwOptions,0xf003f,
                                  unaff_R12,(PHKEY)&stack0x00000078,(LPDWORD)(unaff_RBP + 4));
          if (LVar8 == 0) {
            param_10 = 0x100;
            param_11._0_4_ = dwOptions;
            LVar8 = RegQueryValueExA(*(HKEY *)(unaff_RBP + -0x20 +
                                              (longlong)
                                              *(int *)(*(longlong *)(unaff_RBP + -0x20) + 4)),"name"
                                     ,(LPDWORD)0x0,(LPDWORD)(unaff_RBP + -0x50),
                                     (LPBYTE)(unaff_RBP + 0x60),&param_10);
            if ((LVar8 == 0) && (*(int *)(unaff_RBP + -0x50) - 1U <= unaff_R14D)) {
              if (param_10 == 0) {
                *(char *)(unaff_RBP + 0x60) = cVar16;
              }
              else if (*(char *)(unaff_RBP + 0x5f + (ulonglong)param_10) != cVar16)
              goto LAB_180033ef2;
              param_11._0_4_ = param_10;
              lVar15 = -1;
              do {
                lVar15 = lVar15 + 1;
              } while (*(char *)(unaff_RBP + 0x60 + lVar15) != cVar16);
              RegSetValueExA(*(HKEY *)((longlong)&stack0x00000070 + (longlong)*(int *)(param_14 + 4)
                                      ),"name",0,unaff_R14D,(BYTE *)(unaff_RBP + 0x60),
                             (int)lVar15 + 1);
            }
LAB_180033ef2:
            param_10 = 4;
            LVar8 = RegQueryValueExA(*(HKEY *)(unaff_RBP + -0x20 +
                                              (longlong)
                                              *(int *)(*(longlong *)(unaff_RBP + -0x20) + 4)),
                                     "position",(LPDWORD)0x0,(LPDWORD)(unaff_RBP + -0x4c),
                                     (LPBYTE)&param_13,&param_10);
            if ((LVar8 == 0) && (*(int *)(unaff_RBP + -0x4c) == 4)) {
              param_10 = param_13;
              RegSetValueExA(*(HKEY *)((longlong)&stack0x00000070 + (longlong)*(int *)(param_14 + 4)
                                      ),"position",0,4,(BYTE *)&param_10,4);
            }
          }
          if (param_15 != (LPSECURITY_ATTRIBUTES)0x0) {
            RegCloseKey((HKEY)param_15);
          }
        }
      }
    }
    uVar12 = (int)uVar17 + 1;
    uVar17 = (ulonglong)uVar12;
    param_12._0_4_ = 0x18;
    if (*(HKEY *)(unaff_RBP + -0x18) != (HKEY)0x0) {
      RegCloseKey(*(HKEY *)(unaff_RBP + -0x18));
    }
    iVar7 = RegEnumKeyExA(*(HKEY *)(unaff_RBP + -0x40 +
                                   (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x40) + 4)),uVar12,
                          (LPSTR)(unaff_RBP + 0x48),(LPDWORD)&param_12,&unaff_R12->nLength,
                          (LPSTR)unaff_R12,&unaff_R12->nLength,(PFILETIME)(unaff_RBP + -0x48));
  } while( true );
}

/* ---- FUNC 00033BA3 FUN_180033ba3 (1101 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_180033ba3(void)

{
  char cVar1;
  char cVar2;
  void *pvVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  LSTATUS LVar7;
  int iVar8;
  uint uVar9;
  char *pcVar10;
  void *pvVar11;
  uint dwIndex;
  ulonglong uVar12;
  longlong unaff_RBP;
  DWORD DVar13;
  longlong lVar14;
  char cVar15;
  DWORD dwOptions;
  LPSECURITY_ATTRIBUTES unaff_R12;
  longlong unaff_R13;
  uint unaff_R14D;
  DWORD unaff_R15D;
  DWORD in_stack_00000050;
  DWORD DStack0000000000000058;
  undefined4 uStack000000000000005c;
  DWORD DStack0000000000000060;
  undefined4 uStack0000000000000064;
  DWORD in_stack_00000068;
  longlong in_stack_00000070;
  LPSECURITY_ATTRIBUTES in_stack_00000078;
  
  do {
    *(longlong *)(unaff_RBP + -0x20) = unaff_R13;
    *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x18) = unaff_R12;
    dwOptions = (DWORD)unaff_R12;
    *(DWORD *)(unaff_RBP + -0x10) = dwOptions;
    *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -8) = unaff_R12;
    LVar7 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + -0x40 +
                                   (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x40) + 4)),
                          (LPCSTR)(unaff_RBP + 0x48),0,0x20019,(PHKEY)(unaff_RBP + -0x18));
    cVar15 = (char)unaff_R12;
    if (LVar7 == 0) {
      uStack0000000000000064 = 0x100;
      LVar7 = RegQueryValueExA(*(HKEY *)(unaff_RBP + -0x20 +
                                        (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x20) + 4)),
                               "name",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)(unaff_RBP + 0x160),
                               (LPDWORD)((longlong)&stack0x00000060 + 4));
      if (LVar7 == 0) {
        uStack000000000000005c = 0x18;
        uVar12 = (ulonglong)unaff_R12 & 0xffffffff;
        iVar8 = RegEnumKeyExA(*(HKEY *)(unaff_RBP + -0x70 +
                                       (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x70) + 4)),0,
                              (LPSTR)(unaff_RBP + 0x30),(LPDWORD)((longlong)&stack0x00000058 + 4),
                              &unaff_R12->nLength,(LPSTR)unaff_R12,&unaff_R12->nLength,
                              (PFILETIME)(unaff_RBP + -0x48));
        dwIndex = dwOptions;
        uVar4 = 0xffffffff;
        while (iVar8 == 0) {
          *(DWORD *)(unaff_RBP + -0x80) = dwOptions;
          dwIndex = (int)uVar12 + 1;
          uVar12 = (ulonglong)dwIndex;
          *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x78) = unaff_R12;
          in_stack_00000070 = unaff_R13;
          in_stack_00000078 = unaff_R12;
          LVar7 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + -0x70 +
                                         (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x70) + 4)),
                                (LPCSTR)(unaff_RBP + 0x30),0,0x20019,(PHKEY)&stack0x00000078);
          if (LVar7 == 0) {
            DStack0000000000000058 = 0x100;
            LVar7 = RegQueryValueExA(*(HKEY *)((longlong)&stack0x00000070 +
                                              (longlong)*(int *)(in_stack_00000070 + 4)),"name",
                                     (LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)(unaff_RBP + 0x60),
                                     &stack0x00000058);
            if (LVar7 == 0) {
              pcVar10 = (char *)(unaff_RBP + 0x160);
              lVar14 = (unaff_RBP + 0x60) - (longlong)pcVar10;
              do {
                cVar1 = *pcVar10;
                cVar2 = pcVar10[lVar14];
                if (cVar1 != cVar2) break;
                pcVar10 = pcVar10 + 1;
              } while (cVar2 != '\0');
              if (cVar1 == cVar2) {
                DVar13 = unaff_R14D;
                if (in_stack_00000078 != (LPSECURITY_ATTRIBUTES)0x0) {
                  RegCloseKey((HKEY)in_stack_00000078);
                }
                goto LAB_180033da4;
              }
            }
          }
          uVar9 = atoi((char *)(unaff_RBP + 0x30));
          uStack000000000000005c = 0x18;
          if ((int)uVar9 < (int)uVar4) {
            uVar9 = uVar4;
          }
          if (in_stack_00000078 != (LPSECURITY_ATTRIBUTES)0x0) {
            RegCloseKey((HKEY)in_stack_00000078);
          }
          iVar8 = RegEnumKeyExA(*(HKEY *)(unaff_RBP + -0x70 +
                                         (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x70) + 4)),
                                dwIndex,(LPSTR)(unaff_RBP + 0x30),
                                (LPDWORD)((longlong)&stack0x00000058 + 4),&unaff_R12->nLength,
                                (LPSTR)unaff_R12,&unaff_R12->nLength,(PFILETIME)(unaff_RBP + -0x48))
          ;
          uVar4 = uVar9;
        }
        dwIndex = dwIndex + 1;
        DVar13 = dwOptions;
LAB_180033da4:
        if (DVar13 == 0) {
          if ((int)dwIndex < (int)uVar4) {
            dwIndex = uVar4;
          }
          _itoa(dwIndex + 1,(char *)(unaff_RBP + 0x30),10);
          *(DWORD *)(unaff_RBP + -0x80) = dwOptions;
          *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x78) = unaff_R12;
          in_stack_00000070 = unaff_R13;
          in_stack_00000078 = unaff_R12;
          LVar7 = RegCreateKeyExA(*(HKEY *)(unaff_RBP + -0x70 +
                                           (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x70) + 4))
                                  ,(LPCSTR)(unaff_RBP + 0x30),0,(LPSTR)0x0,dwOptions,0xf003f,
                                  unaff_R12,(PHKEY)&stack0x00000078,(LPDWORD)(unaff_RBP + 4));
          if (LVar7 == 0) {
            in_stack_00000050 = 0x100;
            DStack0000000000000058 = dwOptions;
            LVar7 = RegQueryValueExA(*(HKEY *)(unaff_RBP + -0x20 +
                                              (longlong)
                                              *(int *)(*(longlong *)(unaff_RBP + -0x20) + 4)),"name"
                                     ,(LPDWORD)0x0,(LPDWORD)(unaff_RBP + -0x50),
                                     (LPBYTE)(unaff_RBP + 0x60),&stack0x00000050);
            if ((LVar7 == 0) && (*(int *)(unaff_RBP + -0x50) - 1U <= unaff_R14D)) {
              if (in_stack_00000050 == 0) {
                *(char *)(unaff_RBP + 0x60) = cVar15;
              }
              else if (*(char *)(unaff_RBP + 0x5f + (ulonglong)in_stack_00000050) != cVar15)
              goto LAB_180033ef2;
              DStack0000000000000058 = in_stack_00000050;
              lVar14 = -1;
              do {
                lVar14 = lVar14 + 1;
              } while (*(char *)(unaff_RBP + 0x60 + lVar14) != cVar15);
              RegSetValueExA(*(HKEY *)((longlong)&stack0x00000070 +
                                      (longlong)*(int *)(in_stack_00000070 + 4)),"name",0,unaff_R14D
                             ,(BYTE *)(unaff_RBP + 0x60),(int)lVar14 + 1);
            }
LAB_180033ef2:
            in_stack_00000050 = 4;
            LVar7 = RegQueryValueExA(*(HKEY *)(unaff_RBP + -0x20 +
                                              (longlong)
                                              *(int *)(*(longlong *)(unaff_RBP + -0x20) + 4)),
                                     "position",(LPDWORD)0x0,(LPDWORD)(unaff_RBP + -0x4c),
                                     (LPBYTE)&stack0x00000068,&stack0x00000050);
            if ((LVar7 == 0) && (*(int *)(unaff_RBP + -0x4c) == 4)) {
              in_stack_00000050 = in_stack_00000068;
              RegSetValueExA(*(HKEY *)((longlong)&stack0x00000070 +
                                      (longlong)*(int *)(in_stack_00000070 + 4)),"position",0,4,
                             (BYTE *)&stack0x00000050,4);
            }
          }
          if (in_stack_00000078 != (LPSECURITY_ATTRIBUTES)0x0) {
            RegCloseKey((HKEY)in_stack_00000078);
          }
        }
      }
    }
    unaff_R15D = unaff_R15D + 1;
    DStack0000000000000060 = 0x18;
    if (*(HKEY *)(unaff_RBP + -0x18) != (HKEY)0x0) {
      RegCloseKey(*(HKEY *)(unaff_RBP + -0x18));
    }
    LVar7 = RegEnumKeyExA(*(HKEY *)(unaff_RBP + -0x40 +
                                   (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x40) + 4)),
                          unaff_R15D,(LPSTR)(unaff_RBP + 0x48),&stack0x00000060,&unaff_R12->nLength,
                          (LPSTR)unaff_R12,&unaff_R12->nLength,(PFILETIME)(unaff_RBP + -0x48));
    if (LVar7 != 0) {
      if (0xf < *(ulonglong *)(unaff_RBP + 0x28)) {
        pvVar3 = *(void **)(unaff_RBP + 0x10);
        pvVar11 = pvVar3;
        if ((0xfff < *(ulonglong *)(unaff_RBP + 0x28) + 1) &&
           (pvVar11 = *(void **)((longlong)pvVar3 + -8),
           0x1f < (ulonglong)((longlong)pvVar3 + (-8 - (longlong)pvVar11)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        operator_delete(pvVar11);
      }
      uVar6 = _UNK_180053828;
      uVar5 = _DAT_180053820;
      *(char *)(unaff_RBP + 0x10) = cVar15;
      *(undefined8 *)(unaff_RBP + 0x20) = uVar5;
      *(undefined8 *)(unaff_RBP + 0x28) = uVar6;
      if (*(HKEY *)(unaff_RBP + -0x68) != (HKEY)0x0) {
        RegCloseKey(*(HKEY *)(unaff_RBP + -0x68));
        *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x68) = unaff_R12;
      }
      *(DWORD *)(unaff_RBP + -0x60) = dwOptions;
      if (*(HKEY *)(unaff_RBP + -0x38) != (HKEY)0x0) {
        RegCloseKey(*(HKEY *)(unaff_RBP + -0x38));
      }
      return unaff_R14D;
    }
  } while( true );
}

/* ---- FUNC 00033FF0 FUN_180033ff0 (10 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_180033ff0(void)

{
  void *pvVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  void *pvVar4;
  longlong unaff_RBP;
  undefined8 unaff_R12;
  undefined4 unaff_R14D;
  
  if (0xf < *(ulonglong *)(unaff_RBP + 0x28)) {
    pvVar1 = *(void **)(unaff_RBP + 0x10);
    pvVar4 = pvVar1;
    if ((0xfff < *(ulonglong *)(unaff_RBP + 0x28) + 1) &&
       (pvVar4 = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar4)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar4);
  }
  uVar3 = _UNK_180053828;
  uVar2 = _DAT_180053820;
  *(char *)(unaff_RBP + 0x10) = (char)unaff_R12;
  *(undefined8 *)(unaff_RBP + 0x20) = uVar2;
  *(undefined8 *)(unaff_RBP + 0x28) = uVar3;
  if (*(HKEY *)(unaff_RBP + -0x68) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x68));
    *(undefined8 *)(unaff_RBP + -0x68) = unaff_R12;
  }
  *(int *)(unaff_RBP + -0x60) = (int)unaff_R12;
  if (*(HKEY *)(unaff_RBP + -0x38) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x38));
  }
  return unaff_R14D;
}

/* ---- FUNC 00033FFA FUN_180033ffa (29 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_180033ffa(void)

{
  void *pvVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  void *pvVar4;
  longlong unaff_RBP;
  ulonglong unaff_R12;
  
  if (0xf < *(ulonglong *)(unaff_RBP + 0x28)) {
    pvVar1 = *(void **)(unaff_RBP + 0x10);
    pvVar4 = pvVar1;
    if ((0xfff < *(ulonglong *)(unaff_RBP + 0x28) + 1) &&
       (pvVar4 = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar4)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar4);
  }
  uVar3 = _UNK_180053828;
  uVar2 = _DAT_180053820;
  *(char *)(unaff_RBP + 0x10) = (char)unaff_R12;
  *(undefined8 *)(unaff_RBP + 0x20) = uVar2;
  *(undefined8 *)(unaff_RBP + 0x28) = uVar3;
  if (*(HKEY *)(unaff_RBP + -0x68) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x68));
    *(ulonglong *)(unaff_RBP + -0x68) = unaff_R12;
  }
  *(int *)(unaff_RBP + -0x60) = (int)unaff_R12;
  if (*(HKEY *)(unaff_RBP + -0x38) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x38));
  }
  return unaff_R12 & 0xffffffff;
}

/* ---- FUNC 00034017 FUN_180034017 (138 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_180034017(undefined8 param_1,longlong param_2)

{
  void *pvVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  void *pvVar4;
  longlong unaff_RBP;
  undefined8 unaff_R12;
  undefined4 unaff_R14D;
  
  pvVar1 = *(void **)(unaff_RBP + 0x10);
  pvVar4 = pvVar1;
  if ((0xfff < param_2 + 1U) &&
     (pvVar4 = *(void **)((longlong)pvVar1 + -8),
     0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar4)))) {
                    /* WARNING: Subroutine does not return */
    _invalid_parameter_noinfo_noreturn();
  }
  operator_delete(pvVar4);
  uVar3 = _UNK_180053828;
  uVar2 = _DAT_180053820;
  *(char *)(unaff_RBP + 0x10) = (char)unaff_R12;
  *(undefined8 *)(unaff_RBP + 0x20) = uVar2;
  *(undefined8 *)(unaff_RBP + 0x28) = uVar3;
  if (*(HKEY *)(unaff_RBP + -0x68) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x68));
    *(undefined8 *)(unaff_RBP + -0x68) = unaff_R12;
  }
  *(int *)(unaff_RBP + -0x60) = (int)unaff_R12;
  if (*(HKEY *)(unaff_RBP + -0x38) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x38));
  }
  return unaff_R14D;
}

/* ---- FUNC 000340B0 APModCatUnregisterAll (22 bytes) ---- */

undefined4 APModCatUnregisterAll(void)

{
  HKEY hKey;
  LSTATUS LVar1;
  int iVar2;
  LPCSTR lpSubKey;
  undefined4 uVar3;
  undefined4 uVar4;
  DWORD local_res8 [2];
  CHAR local_res10 [8];
  _FILETIME local_res18;
  HKEY local_b8 [2];
  undefined4 local_a8;
  undefined8 local_a0;
  HKEY local_98 [2];
  undefined4 local_88;
  undefined8 local_80;
  HKEY local_78 [2];
  undefined4 local_68;
  undefined8 local_60;
  HKEY local_58 [2];
  undefined4 local_48;
  undefined8 local_40;
  HKEY local_38 [2];
  undefined4 local_28;
  undefined8 local_20;
  
                    /* 0x340b0  264  APModCatUnregisterAll */
  local_38[0] = (HKEY)&DAT_180053988;
  local_58[0] = (HKEY)&DAT_180053988;
  local_78[0] = (HKEY)&DAT_180053988;
  local_98[0] = (HKEY)&DAT_180053988;
  local_b8[0] = (HKEY)&DAT_180053988;
  local_38[1] = (HKEY)0x0;
  uVar4 = 0;
  local_28 = 0;
  local_20 = 0;
  local_58[1] = (HKEY)0x0;
  local_48 = 0;
  local_40 = 0;
  local_78[1] = (HKEY)0x0;
  local_68 = 0;
  local_60 = 0;
  local_98[1] = (HKEY)0x0;
  local_88 = 0;
  local_80 = 0;
  local_b8[1] = (HKEY)0x0;
  local_a8 = 0;
  local_a0 = 0;
  LVar1 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000001,"Software",0,0xf003f,local_38 + 1);
  if (((LVar1 == 0) &&
      (LVar1 = RegOpenKeyExA(*(HKEY *)((longlong)local_38 + (longlong)local_38[0][1].unused),
                             "AspenTech",0,0xf003f,
                             (PHKEY)((longlong)local_58 + (longlong)local_58[0][1].unused)),
      LVar1 == 0)) &&
     (LVar1 = RegOpenKeyExA(*(HKEY *)((longlong)local_58 + (longlong)local_58[0][1].unused),
                            "ASPEN PLUS",0,0xf003f,
                            (PHKEY)((longlong)local_78 + (longlong)local_78[0][1].unused)),
     LVar1 == 0)) {
    hKey = *(HKEY *)((longlong)local_78 + (longlong)local_78[0][1].unused);
    iVar2 = local_98[0][1].unused;
    lpSubKey = (LPCSTR)FUN_180024170();
    LVar1 = RegOpenKeyExA(hKey,lpSubKey,0,0xf003f,(PHKEY)((longlong)local_98 + (longlong)iVar2));
    if ((LVar1 == 0) &&
       (LVar1 = RegOpenKeyExA(*(HKEY *)((longlong)local_98 + (longlong)local_98[0][1].unused),
                              "Categories",0,0xf003f,
                              (PHKEY)((longlong)local_b8 + (longlong)local_b8[0][1].unused)),
       LVar1 == 0)) {
      local_res8[0] = 4;
      iVar2 = RegEnumKeyExA(*(HKEY *)((longlong)local_b8 + (longlong)local_b8[0][1].unused),0,
                            local_res10,local_res8,(LPDWORD)0x0,(LPSTR)0x0,(LPDWORD)0x0,&local_res18
                           );
      uVar4 = 1;
      while (iVar2 == 0) {
        LVar1 = RegDeleteKeyA(*(HKEY *)((longlong)local_b8 + (longlong)local_b8[0][1].unused),
                              local_res10);
        local_res8[0] = 4;
        uVar3 = 0;
        if (LVar1 == 0) {
          uVar3 = uVar4;
        }
        iVar2 = RegEnumKeyExA(*(HKEY *)((longlong)local_b8 + (longlong)local_b8[0][1].unused),0,
                              local_res10,local_res8,(LPDWORD)0x0,(LPSTR)0x0,(LPDWORD)0x0,
                              &local_res18);
        uVar4 = uVar3;
      }
    }
  }
  if (local_b8[1] != (HKEY)0x0) {
    RegCloseKey(local_b8[1]);
    local_b8[1] = (HKEY)0x0;
  }
  local_a8 = 0;
  if (local_98[1] != (HKEY)0x0) {
    RegCloseKey(local_98[1]);
    local_98[1] = (HKEY)0x0;
  }
  local_88 = 0;
  if (local_78[1] != (HKEY)0x0) {
    RegCloseKey(local_78[1]);
    local_78[1] = (HKEY)0x0;
  }
  local_68 = 0;
  if (local_58[1] != (HKEY)0x0) {
    RegCloseKey(local_58[1]);
    local_58[1] = (HKEY)0x0;
  }
  local_48 = 0;
  if (local_38[1] != (HKEY)0x0) {
    RegCloseKey(local_38[1]);
  }
  return uVar4;
}

/* ---- FUNC 000340C6 FUN_1800340c6 (265 bytes) ---- */

undefined4 FUN_1800340c6(void)

{
  HKEY hKey;
  LSTATUS LVar1;
  int iVar2;
  undefined8 in_RAX;
  LPCSTR lpSubKey;
  undefined4 uVar3;
  longlong unaff_RBP;
  undefined4 uVar4;
  
  *(undefined8 *)(unaff_RBP + 0x27) = in_RAX;
  *(undefined8 *)(unaff_RBP + 7) = in_RAX;
  *(undefined8 *)(unaff_RBP + -0x19) = in_RAX;
  *(undefined8 *)(unaff_RBP + -0x39) = in_RAX;
  *(undefined8 *)(unaff_RBP + -0x59) = in_RAX;
  *(undefined8 *)(unaff_RBP + 0x2f) = 0;
  uVar4 = 0;
  *(undefined4 *)(unaff_RBP + 0x37) = 0;
  *(undefined8 *)(unaff_RBP + 0x3f) = 0;
  *(undefined8 *)(unaff_RBP + 0xf) = 0;
  *(undefined4 *)(unaff_RBP + 0x17) = 0;
  *(undefined8 *)(unaff_RBP + 0x1f) = 0;
  *(undefined8 *)(unaff_RBP + -0x11) = 0;
  *(undefined4 *)(unaff_RBP + -9) = 0;
  *(undefined8 *)(unaff_RBP + -1) = 0;
  *(undefined8 *)(unaff_RBP + -0x31) = 0;
  *(undefined4 *)(unaff_RBP + -0x29) = 0;
  *(undefined8 *)(unaff_RBP + -0x21) = 0;
  *(undefined8 *)(unaff_RBP + -0x51) = 0;
  *(undefined4 *)(unaff_RBP + -0x49) = 0;
  *(undefined8 *)(unaff_RBP + -0x41) = 0;
  LVar1 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000001,"Software",0,0xf003f,(PHKEY)(unaff_RBP + 0x2f));
  if (((LVar1 == 0) &&
      (LVar1 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + 0x27 +
                                      (longlong)*(int *)(*(longlong *)(unaff_RBP + 0x27) + 4)),
                             "AspenTech",0,0xf003f,
                             (PHKEY)(unaff_RBP + 7 +
                                    (longlong)*(int *)(*(longlong *)(unaff_RBP + 7) + 4))),
      LVar1 == 0)) &&
     (LVar1 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + 7 +
                                     (longlong)*(int *)(*(longlong *)(unaff_RBP + 7) + 4)),
                            "ASPEN PLUS",0,0xf003f,
                            (PHKEY)(unaff_RBP + -0x19 +
                                   (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x19) + 4))),
     LVar1 == 0)) {
    hKey = *(HKEY *)(unaff_RBP + -0x19 + (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x19) + 4));
    iVar2 = *(int *)(*(longlong *)(unaff_RBP + -0x39) + 4);
    lpSubKey = (LPCSTR)FUN_180024170();
    LVar1 = RegOpenKeyExA(hKey,lpSubKey,0,0xf003f,(PHKEY)(unaff_RBP + -0x39 + (longlong)iVar2));
    if ((LVar1 == 0) &&
       (LVar1 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + -0x39 +
                                       (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x39) + 4)),
                              "Categories",0,0xf003f,
                              (PHKEY)(unaff_RBP + -0x59 +
                                     (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x59) + 4))),
       LVar1 == 0)) {
      *(undefined4 *)(unaff_RBP + 0x67) = 4;
      iVar2 = RegEnumKeyExA(*(HKEY *)(unaff_RBP + -0x59 +
                                     (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x59) + 4)),0,
                            (LPSTR)(unaff_RBP + 0x6f),(LPDWORD)(unaff_RBP + 0x67),(LPDWORD)0x0,
                            (LPSTR)0x0,(LPDWORD)0x0,(PFILETIME)(unaff_RBP + 0x77));
      uVar4 = 1;
      while (iVar2 == 0) {
        LVar1 = RegDeleteKeyA(*(HKEY *)(unaff_RBP + -0x59 +
                                       (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x59) + 4)),
                              (LPCSTR)(unaff_RBP + 0x6f));
        *(undefined4 *)(unaff_RBP + 0x67) = 4;
        uVar3 = 0;
        if (LVar1 == 0) {
          uVar3 = uVar4;
        }
        iVar2 = RegEnumKeyExA(*(HKEY *)(unaff_RBP + -0x59 +
                                       (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x59) + 4)),0,
                              (LPSTR)(unaff_RBP + 0x6f),(LPDWORD)(unaff_RBP + 0x67),(LPDWORD)0x0,
                              (LPSTR)0x0,(LPDWORD)0x0,(PFILETIME)(unaff_RBP + 0x77));
        uVar4 = uVar3;
      }
    }
  }
  if (*(HKEY *)(unaff_RBP + -0x51) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x51));
    *(undefined8 *)(unaff_RBP + -0x51) = 0;
  }
  *(undefined4 *)(unaff_RBP + -0x49) = 0;
  if (*(HKEY *)(unaff_RBP + -0x31) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x31));
    *(undefined8 *)(unaff_RBP + -0x31) = 0;
  }
  *(undefined4 *)(unaff_RBP + -0x29) = 0;
  if (*(HKEY *)(unaff_RBP + -0x11) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x11));
    *(undefined8 *)(unaff_RBP + -0x11) = 0;
  }
  *(undefined4 *)(unaff_RBP + -9) = 0;
  if (*(HKEY *)(unaff_RBP + 0xf) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + 0xf));
    *(undefined8 *)(unaff_RBP + 0xf) = 0;
  }
  *(undefined4 *)(unaff_RBP + 0x17) = 0;
  if (*(HKEY *)(unaff_RBP + 0x2f) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + 0x2f));
  }
  return uVar4;
}

/* ---- FUNC 000341CF FUN_1800341cf (75 bytes) ---- */

int FUN_1800341cf(void)

{
  HKEY hKey;
  LSTATUS LVar1;
  int iVar2;
  longlong in_RAX;
  LPCSTR lpSubKey;
  int iVar3;
  int iVar4;
  longlong unaff_RBX;
  longlong unaff_RBP;
  int iVar5;
  LPDWORD unaff_RSI;
  
  hKey = *(HKEY *)(unaff_RBP + -0x19 + (longlong)*(int *)(in_RAX + 4));
  iVar4 = *(int *)(*(longlong *)(unaff_RBP + -0x39) + 4);
  lpSubKey = (LPCSTR)FUN_180024170();
  LVar1 = RegOpenKeyExA(hKey,lpSubKey,0,0xf003f,(PHKEY)(unaff_RBX + iVar4));
  iVar5 = (int)unaff_RSI;
  iVar4 = iVar5;
  if ((LVar1 == 0) &&
     (LVar1 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + -0x39 +
                                     (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x39) + 4)),
                            "Categories",0,0xf003f,
                            (PHKEY)(unaff_RBP + -0x59 +
                                   (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x59) + 4))),
     LVar1 == 0)) {
    *(undefined4 *)(unaff_RBP + 0x67) = 4;
    iVar2 = RegEnumKeyExA(*(HKEY *)(unaff_RBP + -0x59 +
                                   (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x59) + 4)),0,
                          (LPSTR)(unaff_RBP + 0x6f),(LPDWORD)(unaff_RBP + 0x67),unaff_RSI,
                          (LPSTR)unaff_RSI,unaff_RSI,(PFILETIME)(unaff_RBP + 0x77));
    iVar4 = iVar5 + 1;
    while (iVar2 == 0) {
      LVar1 = RegDeleteKeyA(*(HKEY *)(unaff_RBP + -0x59 +
                                     (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x59) + 4)),
                            (LPCSTR)(unaff_RBP + 0x6f));
      *(undefined4 *)(unaff_RBP + 0x67) = 4;
      iVar3 = iVar5;
      if (LVar1 == 0) {
        iVar3 = iVar4;
      }
      iVar2 = RegEnumKeyExA(*(HKEY *)(unaff_RBP + -0x59 +
                                     (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x59) + 4)),0,
                            (LPSTR)(unaff_RBP + 0x6f),(LPDWORD)(unaff_RBP + 0x67),unaff_RSI,
                            (LPSTR)unaff_RSI,unaff_RSI,(PFILETIME)(unaff_RBP + 0x77));
      iVar4 = iVar3;
    }
  }
  if (*(HKEY *)(unaff_RBP + -0x51) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x51));
    *(LPDWORD *)(unaff_RBP + -0x51) = unaff_RSI;
  }
  *(int *)(unaff_RBP + -0x49) = iVar5;
  if (*(HKEY *)(unaff_RBP + -0x31) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x31));
    *(LPDWORD *)(unaff_RBP + -0x31) = unaff_RSI;
  }
  *(int *)(unaff_RBP + -0x29) = iVar5;
  if (*(HKEY *)(unaff_RBP + -0x11) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x11));
    *(LPDWORD *)(unaff_RBP + -0x11) = unaff_RSI;
  }
  *(int *)(unaff_RBP + -9) = iVar5;
  if (*(HKEY *)(unaff_RBP + 0xf) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + 0xf));
    *(LPDWORD *)(unaff_RBP + 0xf) = unaff_RSI;
  }
  *(int *)(unaff_RBP + 0x17) = iVar5;
  if (*(HKEY *)(unaff_RBP + 0x2f) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + 0x2f));
  }
  return iVar4;
}

/* ---- FUNC 0003421A FUN_18003421a (339 bytes) ---- */

int FUN_18003421a(void)

{
  LSTATUS LVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  longlong unaff_RBP;
  int iVar5;
  LPDWORD unaff_RSI;
  
  LVar1 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + -0x39 +
                                 (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x39) + 4)),
                        "Categories",0,0xf003f,
                        (PHKEY)(unaff_RBP + -0x59 +
                               (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x59) + 4)));
  iVar5 = (int)unaff_RSI;
  iVar4 = iVar5;
  if (LVar1 == 0) {
    *(undefined4 *)(unaff_RBP + 0x67) = 4;
    iVar2 = RegEnumKeyExA(*(HKEY *)(unaff_RBP + -0x59 +
                                   (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x59) + 4)),0,
                          (LPSTR)(unaff_RBP + 0x6f),(LPDWORD)(unaff_RBP + 0x67),unaff_RSI,
                          (LPSTR)unaff_RSI,unaff_RSI,(PFILETIME)(unaff_RBP + 0x77));
    iVar4 = iVar5 + 1;
    while (iVar2 == 0) {
      LVar1 = RegDeleteKeyA(*(HKEY *)(unaff_RBP + -0x59 +
                                     (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x59) + 4)),
                            (LPCSTR)(unaff_RBP + 0x6f));
      *(undefined4 *)(unaff_RBP + 0x67) = 4;
      iVar3 = iVar5;
      if (LVar1 == 0) {
        iVar3 = iVar4;
      }
      iVar2 = RegEnumKeyExA(*(HKEY *)(unaff_RBP + -0x59 +
                                     (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x59) + 4)),0,
                            (LPSTR)(unaff_RBP + 0x6f),(LPDWORD)(unaff_RBP + 0x67),unaff_RSI,
                            (LPSTR)unaff_RSI,unaff_RSI,(PFILETIME)(unaff_RBP + 0x77));
      iVar4 = iVar3;
    }
  }
  if (*(HKEY *)(unaff_RBP + -0x51) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x51));
    *(LPDWORD *)(unaff_RBP + -0x51) = unaff_RSI;
  }
  *(int *)(unaff_RBP + -0x49) = iVar5;
  if (*(HKEY *)(unaff_RBP + -0x31) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x31));
    *(LPDWORD *)(unaff_RBP + -0x31) = unaff_RSI;
  }
  *(int *)(unaff_RBP + -0x29) = iVar5;
  if (*(HKEY *)(unaff_RBP + -0x11) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x11));
    *(LPDWORD *)(unaff_RBP + -0x11) = unaff_RSI;
  }
  *(int *)(unaff_RBP + -9) = iVar5;
  if (*(HKEY *)(unaff_RBP + 0xf) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + 0xf));
    *(LPDWORD *)(unaff_RBP + 0xf) = unaff_RSI;
  }
  *(int *)(unaff_RBP + 0x17) = iVar5;
  if (*(HKEY *)(unaff_RBP + 0x2f) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + 0x2f));
  }
  return iVar4;
}

/* ---- FUNC 0003436D FUN_18003436d (18 bytes) ---- */

undefined4 FUN_18003436d(HKEY param_1)

{
  undefined4 unaff_EBX;
  
  RegCloseKey(param_1);
  return unaff_EBX;
}

/* ---- FUNC 00034380 APModLibCount (22 bytes) ---- */

DWORD APModLibCount(void)

{
  HKEY hKey;
  LSTATUS LVar1;
  int iVar2;
  LPCSTR lpSubKey;
  DWORD dwIndex;
  DWORD local_res8 [2];
  CHAR local_res10 [8];
  _FILETIME local_res18;
  HKEY local_b8 [2];
  undefined4 local_a8;
  undefined8 local_a0;
  HKEY local_98 [2];
  undefined4 local_88;
  undefined8 local_80;
  HKEY local_78 [2];
  undefined4 local_68;
  undefined8 local_60;
  HKEY local_58 [2];
  undefined4 local_48;
  undefined8 local_40;
  HKEY local_38 [2];
  undefined4 local_28;
  undefined8 local_20;
  
                    /* 0x34380  265  APModLibCount */
  dwIndex = 0;
  local_38[0] = (HKEY)&DAT_180053988;
  local_58[0] = (HKEY)&DAT_180053988;
  local_78[0] = (HKEY)&DAT_180053988;
  local_98[0] = (HKEY)&DAT_180053988;
  local_b8[0] = (HKEY)&DAT_180053988;
  local_38[1] = (HKEY)0x0;
  local_28 = 0;
  local_20 = 0;
  local_58[1] = (HKEY)0x0;
  local_48 = 0;
  local_40 = 0;
  local_78[1] = (HKEY)0x0;
  local_68 = 0;
  local_60 = 0;
  local_98[1] = (HKEY)0x0;
  local_88 = 0;
  local_80 = 0;
  local_b8[1] = (HKEY)0x0;
  local_a8 = 0;
  local_a0 = 0;
  LVar1 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000001,"Software",0,0xf003f,local_38 + 1);
  if (((LVar1 == 0) &&
      (LVar1 = RegOpenKeyExA(*(HKEY *)((longlong)local_38 + (longlong)local_38[0][1].unused),
                             "AspenTech",0,0xf003f,
                             (PHKEY)((longlong)local_58 + (longlong)local_58[0][1].unused)),
      LVar1 == 0)) &&
     (LVar1 = RegOpenKeyExA(*(HKEY *)((longlong)local_58 + (longlong)local_58[0][1].unused),
                            "ASPEN PLUS",0,0xf003f,
                            (PHKEY)((longlong)local_78 + (longlong)local_78[0][1].unused)),
     LVar1 == 0)) {
    iVar2 = local_98[0][1].unused;
    hKey = *(HKEY *)((longlong)local_78 + (longlong)local_78[0][1].unused);
    lpSubKey = (LPCSTR)FUN_180024170();
    LVar1 = RegOpenKeyExA(hKey,lpSubKey,0,0xf003f,(PHKEY)((longlong)local_98 + (longlong)iVar2));
    if ((LVar1 == 0) &&
       (LVar1 = RegOpenKeyExA(*(HKEY *)((longlong)local_98 + (longlong)local_98[0][1].unused),
                              "Libraries",0,0xf003f,
                              (PHKEY)((longlong)local_b8 + (longlong)local_b8[0][1].unused)),
       LVar1 == 0)) {
      local_res8[0] = 4;
      iVar2 = RegEnumKeyExA(*(HKEY *)((longlong)local_b8 + (longlong)local_b8[0][1].unused),0,
                            local_res10,local_res8,(LPDWORD)0x0,(LPSTR)0x0,(LPDWORD)0x0,&local_res18
                           );
      while (iVar2 == 0) {
        local_res8[0] = 4;
        dwIndex = dwIndex + 1;
        iVar2 = RegEnumKeyExA(*(HKEY *)((longlong)local_b8 + (longlong)local_b8[0][1].unused),
                              dwIndex,local_res10,local_res8,(LPDWORD)0x0,(LPSTR)0x0,(LPDWORD)0x0,
                              &local_res18);
      }
      goto LAB_1800345b6;
    }
  }
  dwIndex = 0;
LAB_1800345b6:
  if (local_b8[1] != (HKEY)0x0) {
    RegCloseKey(local_b8[1]);
    local_b8[1] = (HKEY)0x0;
  }
  local_a8 = 0;
  if (local_98[1] != (HKEY)0x0) {
    RegCloseKey(local_98[1]);
    local_98[1] = (HKEY)0x0;
  }
  local_88 = 0;
  if (local_78[1] != (HKEY)0x0) {
    RegCloseKey(local_78[1]);
    local_78[1] = (HKEY)0x0;
  }
  local_68 = 0;
  if (local_58[1] != (HKEY)0x0) {
    RegCloseKey(local_58[1]);
    local_58[1] = (HKEY)0x0;
  }
  local_48 = 0;
  if (local_38[1] != (HKEY)0x0) {
    RegCloseKey(local_38[1]);
  }
  return dwIndex;
}

/* ---- FUNC 00034396 FUN_180034396 (265 bytes) ---- */

DWORD FUN_180034396(void)

{
  HKEY hKey;
  LSTATUS LVar1;
  int iVar2;
  undefined8 in_RAX;
  LPCSTR lpSubKey;
  DWORD dwIndex;
  longlong unaff_RBP;
  
  dwIndex = 0;
  *(undefined8 *)(unaff_RBP + 0x27) = in_RAX;
  *(undefined8 *)(unaff_RBP + 7) = in_RAX;
  *(undefined8 *)(unaff_RBP + -0x19) = in_RAX;
  *(undefined8 *)(unaff_RBP + -0x39) = in_RAX;
  *(undefined8 *)(unaff_RBP + -0x59) = in_RAX;
  *(undefined8 *)(unaff_RBP + 0x2f) = 0;
  *(undefined4 *)(unaff_RBP + 0x37) = 0;
  *(undefined8 *)(unaff_RBP + 0x3f) = 0;
  *(undefined8 *)(unaff_RBP + 0xf) = 0;
  *(undefined4 *)(unaff_RBP + 0x17) = 0;
  *(undefined8 *)(unaff_RBP + 0x1f) = 0;
  *(undefined8 *)(unaff_RBP + -0x11) = 0;
  *(undefined4 *)(unaff_RBP + -9) = 0;
  *(undefined8 *)(unaff_RBP + -1) = 0;
  *(undefined8 *)(unaff_RBP + -0x31) = 0;
  *(undefined4 *)(unaff_RBP + -0x29) = 0;
  *(undefined8 *)(unaff_RBP + -0x21) = 0;
  *(undefined8 *)(unaff_RBP + -0x51) = 0;
  *(undefined4 *)(unaff_RBP + -0x49) = 0;
  *(undefined8 *)(unaff_RBP + -0x41) = 0;
  LVar1 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000001,"Software",0,0xf003f,(PHKEY)(unaff_RBP + 0x2f));
  if (((LVar1 == 0) &&
      (LVar1 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + 0x27 +
                                      (longlong)*(int *)(*(longlong *)(unaff_RBP + 0x27) + 4)),
                             "AspenTech",0,0xf003f,
                             (PHKEY)(unaff_RBP + 7 +
                                    (longlong)*(int *)(*(longlong *)(unaff_RBP + 7) + 4))),
      LVar1 == 0)) &&
     (LVar1 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + 7 +
                                     (longlong)*(int *)(*(longlong *)(unaff_RBP + 7) + 4)),
                            "ASPEN PLUS",0,0xf003f,
                            (PHKEY)(unaff_RBP + -0x19 +
                                   (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x19) + 4))),
     LVar1 == 0)) {
    iVar2 = *(int *)(*(longlong *)(unaff_RBP + -0x39) + 4);
    hKey = *(HKEY *)(unaff_RBP + -0x19 + (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x19) + 4));
    lpSubKey = (LPCSTR)FUN_180024170();
    LVar1 = RegOpenKeyExA(hKey,lpSubKey,0,0xf003f,(PHKEY)(unaff_RBP + -0x39 + (longlong)iVar2));
    if ((LVar1 == 0) &&
       (LVar1 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + -0x39 +
                                       (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x39) + 4)),
                              "Libraries",0,0xf003f,
                              (PHKEY)(unaff_RBP + -0x59 +
                                     (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x59) + 4))),
       LVar1 == 0)) {
      *(undefined4 *)(unaff_RBP + 0x67) = 4;
      iVar2 = RegEnumKeyExA(*(HKEY *)(unaff_RBP + -0x59 +
                                     (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x59) + 4)),0,
                            (LPSTR)(unaff_RBP + 0x6f),(LPDWORD)(unaff_RBP + 0x67),(LPDWORD)0x0,
                            (LPSTR)0x0,(LPDWORD)0x0,(PFILETIME)(unaff_RBP + 0x77));
      while (iVar2 == 0) {
        *(undefined4 *)(unaff_RBP + 0x67) = 4;
        dwIndex = dwIndex + 1;
        iVar2 = RegEnumKeyExA(*(HKEY *)(unaff_RBP + -0x59 +
                                       (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x59) + 4)),
                              dwIndex,(LPSTR)(unaff_RBP + 0x6f),(LPDWORD)(unaff_RBP + 0x67),
                              (LPDWORD)0x0,(LPSTR)0x0,(LPDWORD)0x0,(PFILETIME)(unaff_RBP + 0x77));
      }
      goto LAB_1800345b6;
    }
  }
  dwIndex = 0;
LAB_1800345b6:
  if (*(HKEY *)(unaff_RBP + -0x51) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x51));
    *(undefined8 *)(unaff_RBP + -0x51) = 0;
  }
  *(undefined4 *)(unaff_RBP + -0x49) = 0;
  if (*(HKEY *)(unaff_RBP + -0x31) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x31));
    *(undefined8 *)(unaff_RBP + -0x31) = 0;
  }
  *(undefined4 *)(unaff_RBP + -0x29) = 0;
  if (*(HKEY *)(unaff_RBP + -0x11) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x11));
    *(undefined8 *)(unaff_RBP + -0x11) = 0;
  }
  *(undefined4 *)(unaff_RBP + -9) = 0;
  if (*(HKEY *)(unaff_RBP + 0xf) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + 0xf));
    *(undefined8 *)(unaff_RBP + 0xf) = 0;
  }
  *(undefined4 *)(unaff_RBP + 0x17) = 0;
  if (*(HKEY *)(unaff_RBP + 0x2f) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + 0x2f));
  }
  return dwIndex;
}

/* ---- FUNC 0003449F FUN_18003449f (75 bytes) ---- */

ulonglong FUN_18003449f(void)

{
  HKEY hKey;
  LSTATUS LVar1;
  int iVar2;
  longlong in_RAX;
  LPCSTR lpSubKey;
  uint dwIndex;
  longlong unaff_RBX;
  ulonglong uVar3;
  longlong unaff_RBP;
  undefined4 uVar4;
  LPDWORD unaff_RSI;
  
  iVar2 = *(int *)(in_RAX + 4);
  hKey = *(HKEY *)(unaff_RBP + -0x19 + (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x19) + 4));
  lpSubKey = (LPCSTR)FUN_180024170();
  LVar1 = RegOpenKeyExA(hKey,lpSubKey,0,0xf003f,(PHKEY)(unaff_RBX + iVar2));
  uVar4 = SUB84(unaff_RSI,0);
  if ((LVar1 == 0) &&
     (LVar1 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + -0x39 +
                                     (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x39) + 4)),
                            "Libraries",0,0xf003f,
                            (PHKEY)(unaff_RBP + -0x59 +
                                   (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x59) + 4))),
     LVar1 == 0)) {
    *(undefined4 *)(unaff_RBP + 0x67) = 4;
    uVar3 = (ulonglong)unaff_RSI & 0xffffffff;
    iVar2 = RegEnumKeyExA(*(HKEY *)(unaff_RBP + -0x59 +
                                   (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x59) + 4)),0,
                          (LPSTR)(unaff_RBP + 0x6f),(LPDWORD)(unaff_RBP + 0x67),unaff_RSI,
                          (LPSTR)unaff_RSI,unaff_RSI,(PFILETIME)(unaff_RBP + 0x77));
    while (iVar2 == 0) {
      *(undefined4 *)(unaff_RBP + 0x67) = 4;
      dwIndex = (int)uVar3 + 1;
      uVar3 = (ulonglong)dwIndex;
      iVar2 = RegEnumKeyExA(*(HKEY *)(unaff_RBP + -0x59 +
                                     (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x59) + 4)),
                            dwIndex,(LPSTR)(unaff_RBP + 0x6f),(LPDWORD)(unaff_RBP + 0x67),unaff_RSI,
                            (LPSTR)unaff_RSI,unaff_RSI,(PFILETIME)(unaff_RBP + 0x77));
    }
  }
  else {
    uVar3 = (ulonglong)unaff_RSI & 0xffffffff;
  }
  if (*(HKEY *)(unaff_RBP + -0x51) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x51));
    *(LPDWORD *)(unaff_RBP + -0x51) = unaff_RSI;
  }
  *(undefined4 *)(unaff_RBP + -0x49) = uVar4;
  if (*(HKEY *)(unaff_RBP + -0x31) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x31));
    *(LPDWORD *)(unaff_RBP + -0x31) = unaff_RSI;
  }
  *(undefined4 *)(unaff_RBP + -0x29) = uVar4;
  if (*(HKEY *)(unaff_RBP + -0x11) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x11));
    *(LPDWORD *)(unaff_RBP + -0x11) = unaff_RSI;
  }
  *(undefined4 *)(unaff_RBP + -9) = uVar4;
  if (*(HKEY *)(unaff_RBP + 0xf) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + 0xf));
    *(LPDWORD *)(unaff_RBP + 0xf) = unaff_RSI;
  }
  *(undefined4 *)(unaff_RBP + 0x17) = uVar4;
  if (*(HKEY *)(unaff_RBP + 0x2f) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + 0x2f));
  }
  return uVar3;
}

/* ---- FUNC 000344EA FUN_1800344ea (309 bytes) ---- */

ulonglong FUN_1800344ea(void)

{
  LSTATUS LVar1;
  int iVar2;
  uint dwIndex;
  ulonglong uVar3;
  longlong unaff_RBP;
  undefined4 uVar4;
  LPDWORD unaff_RSI;
  
  LVar1 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + -0x39 +
                                 (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x39) + 4)),
                        "Libraries",0,0xf003f,
                        (PHKEY)(unaff_RBP + -0x59 +
                               (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x59) + 4)));
  uVar4 = SUB84(unaff_RSI,0);
  if (LVar1 == 0) {
    *(undefined4 *)(unaff_RBP + 0x67) = 4;
    uVar3 = (ulonglong)unaff_RSI & 0xffffffff;
    iVar2 = RegEnumKeyExA(*(HKEY *)(unaff_RBP + -0x59 +
                                   (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x59) + 4)),0,
                          (LPSTR)(unaff_RBP + 0x6f),(LPDWORD)(unaff_RBP + 0x67),unaff_RSI,
                          (LPSTR)unaff_RSI,unaff_RSI,(PFILETIME)(unaff_RBP + 0x77));
    while (iVar2 == 0) {
      *(undefined4 *)(unaff_RBP + 0x67) = 4;
      dwIndex = (int)uVar3 + 1;
      uVar3 = (ulonglong)dwIndex;
      iVar2 = RegEnumKeyExA(*(HKEY *)(unaff_RBP + -0x59 +
                                     (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x59) + 4)),
                            dwIndex,(LPSTR)(unaff_RBP + 0x6f),(LPDWORD)(unaff_RBP + 0x67),unaff_RSI,
                            (LPSTR)unaff_RSI,unaff_RSI,(PFILETIME)(unaff_RBP + 0x77));
    }
  }
  else {
    uVar3 = (ulonglong)unaff_RSI & 0xffffffff;
  }
  if (*(HKEY *)(unaff_RBP + -0x51) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x51));
    *(LPDWORD *)(unaff_RBP + -0x51) = unaff_RSI;
  }
  *(undefined4 *)(unaff_RBP + -0x49) = uVar4;
  if (*(HKEY *)(unaff_RBP + -0x31) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x31));
    *(LPDWORD *)(unaff_RBP + -0x31) = unaff_RSI;
  }
  *(undefined4 *)(unaff_RBP + -0x29) = uVar4;
  if (*(HKEY *)(unaff_RBP + -0x11) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x11));
    *(LPDWORD *)(unaff_RBP + -0x11) = unaff_RSI;
  }
  *(undefined4 *)(unaff_RBP + -9) = uVar4;
  if (*(HKEY *)(unaff_RBP + 0xf) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + 0xf));
    *(LPDWORD *)(unaff_RBP + 0xf) = unaff_RSI;
  }
  *(undefined4 *)(unaff_RBP + 0x17) = uVar4;
  if (*(HKEY *)(unaff_RBP + 0x2f) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + 0x2f));
  }
  return uVar3;
}

/* ---- FUNC 0003461F FUN_18003461f (18 bytes) ---- */

undefined4 FUN_18003461f(HKEY param_1)

{
  undefined4 unaff_EBX;
  
  RegCloseKey(param_1);
  return unaff_EBX;
}

/* ---- FUNC 00034640 APModLibGetValues (108 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

DWORD APModLibGetValues(longlong param_1,char *param_2,int param_3,undefined4 *param_4,
                       undefined4 *param_5)

{
  BYTE BVar1;
  BYTE BVar2;
  HKEY hKey;
  longlong lVar3;
  char *pcVar4;
  LSTATUS LVar5;
  LPCSTR lpSubKey;
  BYTE *pBVar6;
  DWORD dwIndex;
  int iVar7;
  longlong lVar8;
  DWORD unaff_EDI;
  longlong lVar9;
  undefined1 auStackY_688 [32];
  DWORD local_648 [2];
  undefined4 local_640;
  DWORD local_63c;
  CHAR local_638 [4];
  DWORD local_634;
  HKEY local_630 [2];
  undefined4 local_620;
  undefined8 local_618;
  HKEY local_610 [2];
  undefined4 local_600;
  undefined8 local_5f8;
  HKEY local_5f0 [2];
  undefined4 local_5e0;
  undefined8 local_5d8;
  HKEY local_5d0 [2];
  undefined4 local_5c0;
  undefined8 local_5b8;
  HKEY local_5b0 [2];
  undefined4 local_5a0;
  undefined8 local_598;
  _FILETIME local_590;
  char *local_588;
  HKEY local_580 [2];
  undefined4 local_570;
  undefined8 local_568;
  BYTE local_558 [272];
  BYTE local_448 [1024];
  ulonglong local_48;
  
                    /* 0x34640  266  APModLibGetValues */
  local_48 = DAT_1800791f8 ^ (ulonglong)auStackY_688;
  *param_2 = '\0';
  *param_4 = 0xffffffff;
  *param_5 = 0;
  if ((param_1 != 0) && (0 < param_3)) {
    local_580[0] = (HKEY)&DAT_180053988;
    local_5b0[0] = (HKEY)&DAT_180053988;
    local_5d0[0] = (HKEY)&DAT_180053988;
    local_5f0[0] = (HKEY)&DAT_180053988;
    local_610[0] = (HKEY)&DAT_180053988;
    local_580[1] = (HKEY)0x0;
    local_570 = 0;
    local_568 = 0;
    local_5b0[1] = (HKEY)0x0;
    local_5a0 = 0;
    local_598 = 0;
    local_5d0[1] = (HKEY)0x0;
    local_5c0 = 0;
    local_5b8 = 0;
    local_5f0[1] = (HKEY)0x0;
    local_5e0 = 0;
    local_5d8 = 0;
    local_610[1] = (HKEY)0x0;
    local_600 = 0;
    local_5f8 = 0;
    local_588 = param_2;
    LVar5 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000001,"Software",0,0xf003f,local_580 + 1);
    if ((LVar5 == 0) &&
       ((LVar5 = RegOpenKeyExA(*(HKEY *)((longlong)local_580 + (longlong)local_580[0][1].unused),
                               "AspenTech",0,0xf003f,
                               (PHKEY)((longlong)local_5b0 + (longlong)local_5b0[0][1].unused)),
        LVar5 == 0 &&
        (LVar5 = RegOpenKeyExA(*(HKEY *)((longlong)local_5b0 + (longlong)local_5b0[0][1].unused),
                               "ASPEN PLUS",0,0xf003f,
                               (PHKEY)((longlong)local_5d0 + (longlong)local_5d0[0][1].unused)),
        LVar5 == 0)))) {
      hKey = *(HKEY *)((longlong)local_5d0 + (longlong)local_5d0[0][1].unused);
      iVar7 = local_5f0[0][1].unused;
      lpSubKey = (LPCSTR)FUN_180024170();
      LVar5 = RegOpenKeyExA(hKey,lpSubKey,0,0xf003f,(PHKEY)((longlong)local_5f0 + (longlong)iVar7));
      if ((LVar5 == 0) &&
         (LVar5 = RegOpenKeyExA(*(HKEY *)((longlong)local_5f0 + (longlong)local_5f0[0][1].unused),
                                "Libraries",0,0xf003f,
                                (PHKEY)((longlong)local_610 + (longlong)local_610[0][1].unused)),
         LVar5 == 0)) {
        dwIndex = 0;
        local_63c = 0x400;
        local_648[0] = 4;
        local_648[1] = 4;
        LVar5 = RegEnumKeyExA(*(HKEY *)((longlong)local_610 + (longlong)local_610[0][1].unused),0,
                              local_638,local_648,(LPDWORD)0x0,(LPSTR)0x0,(LPDWORD)0x0,&local_590);
        if (LVar5 == 0) {
LAB_180034890:
          local_630[0] = (HKEY)&DAT_180053988;
          local_630[1] = (HKEY)0x0;
          local_620 = 0;
          local_618 = 0;
          LVar5 = RegOpenKeyExA(*(HKEY *)((longlong)local_610 + (longlong)local_610[0][1].unused),
                                local_638,0,0xf003f,local_630 + 1);
          if (LVar5 != 0) goto LAB_180034947;
          local_63c = 0x400;
          LVar5 = RegQueryValueExA(*(HKEY *)((longlong)local_630 + (longlong)local_630[0][1].unused)
                                   ,"Display Name",(LPDWORD)0x0,(LPDWORD)0x0,local_448,&local_63c);
          if (LVar5 != 0) goto LAB_180034947;
          pBVar6 = local_448;
          lVar9 = param_1 - (longlong)pBVar6;
          do {
            BVar1 = *pBVar6;
            BVar2 = pBVar6[lVar9];
            if (BVar1 != BVar2) break;
            pBVar6 = pBVar6 + 1;
          } while (BVar2 != '\0');
          if (BVar1 != BVar2) goto LAB_180034947;
          LVar5 = RegQueryValueExA(*(HKEY *)((longlong)local_630 + (longlong)local_630[0][1].unused)
                                   ,"Position",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)&local_640,
                                   local_648 + 1);
          if (LVar5 == 0) {
            *param_4 = local_640;
          }
          local_648[1] = 4;
          LVar5 = RegQueryValueExA(*(HKEY *)((longlong)local_630 + (longlong)local_630[0][1].unused)
                                   ,"Active",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)&local_640,
                                   local_648 + 1);
          if (LVar5 == 0) {
            *param_5 = local_640;
          }
          local_634 = 0x104;
          LVar5 = RegQueryValueExA(*(HKEY *)((longlong)local_630 + (longlong)local_630[0][1].unused)
                                   ,"Path",(LPDWORD)0x0,(LPDWORD)0x0,local_558,&local_634);
          pcVar4 = local_588;
          if (LVar5 == 0) {
            lVar9 = -1;
            do {
              lVar8 = lVar9 + 1;
              lVar3 = lVar9 + 1;
              lVar9 = lVar8;
            } while (local_558[lVar3] != '\0');
            iVar7 = (int)lVar8;
            if (param_3 + -1 <= iVar7) {
              iVar7 = param_3 + -1;
            }
            strncpy(local_588,(char *)local_558,(longlong)iVar7);
            pcVar4[iVar7] = '\0';
          }
          if (local_630[1] != (HKEY)0x0) {
            RegCloseKey(local_630[1]);
          }
        }
      }
    }
LAB_180034ac2:
    if (local_610[1] != (HKEY)0x0) {
      RegCloseKey(local_610[1]);
      local_610[1] = (HKEY)0x0;
    }
    local_600 = 0;
    if (local_5f0[1] != (HKEY)0x0) {
      RegCloseKey(local_5f0[1]);
      local_5f0[1] = (HKEY)0x0;
    }
    local_5e0 = 0;
    if (local_5d0[1] != (HKEY)0x0) {
      RegCloseKey(local_5d0[1]);
      local_5d0[1] = (HKEY)0x0;
    }
    local_5c0 = 0;
    if (local_5b0[1] != (HKEY)0x0) {
      RegCloseKey(local_5b0[1]);
      local_5b0[1] = (HKEY)0x0;
    }
    local_5a0 = 0;
    if (local_580[1] != (HKEY)0x0) {
      RegCloseKey(local_580[1]);
    }
  }
  return unaff_EDI;
LAB_180034947:
  dwIndex = dwIndex + 1;
  local_648[0] = 4;
  if (local_630[1] != (HKEY)0x0) {
    RegCloseKey(local_630[1]);
  }
  LVar5 = RegEnumKeyExA(*(HKEY *)((longlong)local_610 + (longlong)local_610[0][1].unused),dwIndex,
                        local_638,local_648,(LPDWORD)0x0,(LPSTR)0x0,(LPDWORD)0x0,&local_590);
  if (LVar5 != 0) goto LAB_180034ac2;
  goto LAB_180034890;
}

/* ---- FUNC 000346AC FUN_1800346ac (1161 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_1800346ac(void)

{
  char cVar1;
  char cVar2;
  HKEY hKey;
  LSTATUS LVar3;
  longlong in_RAX;
  LPCSTR lpSubKey;
  char *pcVar4;
  undefined4 uVar5;
  uint dwIndex;
  ulonglong unaff_RBX;
  undefined8 *unaff_RBP;
  int iVar7;
  longlong unaff_RSI;
  longlong lVar8;
  ulonglong uVar9;
  longlong lVar10;
  undefined4 *unaff_R12;
  undefined4 *unaff_R13;
  longlong unaff_R14;
  int unaff_R15D;
  DWORD DStack0000000000000040;
  undefined4 uStack0000000000000044;
  undefined4 uStack0000000000000048;
  undefined4 uStack000000000000004c;
  undefined8 in_stack_00000050;
  undefined *in_stack_00000058;
  HKEY in_stack_00000060;
  undefined4 in_stack_00000068;
  undefined8 in_stack_00000070;
  longlong lStack0000000000000078;
  ulonglong uVar6;
  
  unaff_RBP[1] = in_RAX;
  unaff_RBP[-5] = in_RAX;
  unaff_RBP[-9] = in_RAX;
  unaff_RBP[-0xd] = in_RAX;
  unaff_RBP[2] = unaff_RBX;
  uVar5 = (undefined4)unaff_RBX;
  *(undefined4 *)(unaff_RBP + 3) = uVar5;
  unaff_RBP[4] = unaff_RBX;
  unaff_RBP[-4] = unaff_RBX;
  *(undefined4 *)(unaff_RBP + -3) = uVar5;
  unaff_RBP[-2] = unaff_RBX;
  unaff_RBP[-8] = unaff_RBX;
  *(undefined4 *)(unaff_RBP + -7) = uVar5;
  unaff_RBP[-6] = unaff_RBX;
  unaff_RBP[-0xc] = unaff_RBX;
  *(undefined4 *)(unaff_RBP + -0xb) = uVar5;
  unaff_RBP[-10] = unaff_RBX;
  unaff_RBP[-0x10] = unaff_RBX;
  *(undefined4 *)(unaff_RBP + -0xf) = uVar5;
  unaff_RBP[-0xe] = unaff_RBX;
  lStack0000000000000078 = in_RAX;
  LVar3 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000001,"Software",0,0xf003f,(PHKEY)(unaff_RBP + 2));
  if (LVar3 == 0) {
    LVar3 = RegOpenKeyExA(*(HKEY *)((longlong)unaff_RBP + (longlong)*(int *)(unaff_RBP[1] + 4) + 8),
                          "AspenTech",0,0xf003f,
                          (PHKEY)((longlong)unaff_RBP +
                                 (longlong)*(int *)(unaff_RBP[-5] + 4) + -0x28));
    if (LVar3 == 0) {
      LVar3 = RegOpenKeyExA(*(HKEY *)((longlong)unaff_RBP +
                                     (longlong)*(int *)(unaff_RBP[-5] + 4) + -0x28),"ASPEN PLUS",0,
                            0xf003f,(PHKEY)((longlong)unaff_RBP +
                                           (longlong)*(int *)(unaff_RBP[-9] + 4) + -0x48));
      if (LVar3 == 0) {
        hKey = *(HKEY *)((longlong)unaff_RBP + (longlong)*(int *)(unaff_RBP[-9] + 4) + -0x48);
        iVar7 = *(int *)(unaff_RBP[-0xd] + 4);
        lpSubKey = (LPCSTR)FUN_180024170();
        LVar3 = RegOpenKeyExA(hKey,lpSubKey,0,0xf003f,
                              (PHKEY)((longlong)unaff_RBP + (longlong)iVar7 + -0x68));
        if (LVar3 == 0) {
          LVar3 = RegOpenKeyExA(*(HKEY *)((longlong)unaff_RBP +
                                         (longlong)*(int *)(unaff_RBP[-0xd] + 4) + -0x68),
                                "Libraries",0,0xf003f,
                                (PHKEY)((longlong)&stack0x00000078 +
                                       (longlong)*(int *)(lStack0000000000000078 + 4)));
          if (LVar3 == 0) {
            uVar9 = 0;
            uStack000000000000004c = 0x400;
            DStack0000000000000040 = 4;
            uStack0000000000000044 = 4;
            LVar3 = RegEnumKeyExA(*(HKEY *)((longlong)&stack0x00000078 +
                                           (longlong)*(int *)(lStack0000000000000078 + 4)),0,
                                  (LPSTR)&stack0x00000050,&stack0x00000040,(LPDWORD)0x0,(LPSTR)0x0,
                                  (LPDWORD)0x0,(PFILETIME)(unaff_RBP + -1));
            uVar6 = uVar9;
            if (LVar3 == 0) {
              do {
                in_stack_00000058 = &DAT_180053988;
                in_stack_00000060 = (HKEY)0x0;
                in_stack_00000068 = 0;
                in_stack_00000070 = 0;
                LVar3 = RegOpenKeyExA(*(HKEY *)((longlong)&stack0x00000078 +
                                               (longlong)*(int *)(lStack0000000000000078 + 4)),
                                      (LPCSTR)&stack0x00000050,0,0xf003f,&stack0x00000060);
                if (LVar3 == 0) {
                  uStack000000000000004c = 0x400;
                  LVar3 = RegQueryValueExA(*(HKEY *)((longlong)&stack0x00000058 +
                                                    (longlong)*(int *)(in_stack_00000058 + 4)),
                                           "Display Name",(LPDWORD)0x0,(LPDWORD)0x0,
                                           (LPBYTE)(unaff_RBP + 0x28),
                                           (LPDWORD)((longlong)&stack0x00000048 + 4));
                  if (LVar3 != 0) goto LAB_180034947;
                  pcVar4 = (char *)(unaff_RBP + 0x28);
                  lVar10 = unaff_R14 - (longlong)pcVar4;
                  do {
                    cVar1 = *pcVar4;
                    cVar2 = pcVar4[lVar10];
                    if (cVar1 != cVar2) break;
                    pcVar4 = pcVar4 + 1;
                  } while (cVar2 != '\0');
                  if (cVar1 != cVar2) goto LAB_180034947;
                  uVar9 = 1;
                  LVar3 = RegQueryValueExA(*(HKEY *)((longlong)&stack0x00000058 +
                                                    (longlong)*(int *)(in_stack_00000058 + 4)),
                                           "Position",(LPDWORD)0x0,(LPDWORD)0x0,
                                           (LPBYTE)&stack0x00000048,
                                           (LPDWORD)((longlong)&stack0x00000040 + 4));
                  if (LVar3 == 0) {
                    *unaff_R12 = uStack0000000000000048;
                  }
                  uStack0000000000000044 = 4;
                  LVar3 = RegQueryValueExA(*(HKEY *)((longlong)&stack0x00000058 +
                                                    (longlong)*(int *)(in_stack_00000058 + 4)),
                                           "Active",(LPDWORD)0x0,(LPDWORD)0x0,
                                           (LPBYTE)&stack0x00000048,
                                           (LPDWORD)((longlong)&stack0x00000040 + 4));
                  if (LVar3 == 0) {
                    *unaff_R13 = uStack0000000000000048;
                  }
                  in_stack_00000050._4_4_ = 0x104;
                  LVar3 = RegQueryValueExA(*(HKEY *)((longlong)&stack0x00000058 +
                                                    (longlong)*(int *)(in_stack_00000058 + 4)),
                                           "Path",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)(unaff_RBP + 6),
                                           (LPDWORD)((longlong)&stack0x00000050 + 4));
                  if (LVar3 == 0) {
                    do {
                      lVar8 = unaff_RSI + 1;
                      lVar10 = unaff_RSI + 0x31;
                      unaff_RSI = lVar8;
                    } while (*(char *)((longlong)unaff_RBP + lVar10) != '\0');
                    iVar7 = (int)lVar8;
                    if (unaff_R15D + -1 <= iVar7) {
                      iVar7 = unaff_R15D + -1;
                    }
                    pcVar4 = (char *)*unaff_RBP;
                    strncpy(pcVar4,(char *)(unaff_RBP + 6),(longlong)iVar7);
                    pcVar4[iVar7] = '\0';
                  }
                  if (in_stack_00000060 != (HKEY)0x0) {
                    RegCloseKey(in_stack_00000060);
                  }
                  goto LAB_180034aba;
                }
LAB_180034947:
                dwIndex = (int)uVar6 + 1;
                uVar6 = (ulonglong)dwIndex;
                DStack0000000000000040 = 4;
                if (in_stack_00000060 != (HKEY)0x0) {
                  RegCloseKey(in_stack_00000060);
                }
                LVar3 = RegEnumKeyExA(*(HKEY *)((longlong)&stack0x00000078 +
                                               (longlong)*(int *)(lStack0000000000000078 + 4)),
                                      dwIndex,(LPSTR)&stack0x00000050,&stack0x00000040,(LPDWORD)0x0,
                                      (LPSTR)0x0,(LPDWORD)0x0,(PFILETIME)(unaff_RBP + -1));
              } while (LVar3 == 0);
              unaff_RBX = 0;
            }
            else {
LAB_180034aba:
              unaff_RBX = 0;
            }
            goto LAB_180034ac2;
          }
        }
        unaff_RBX = 0;
      }
    }
  }
  uVar9 = unaff_RBX & 0xffffffff;
LAB_180034ac2:
  if ((HKEY)unaff_RBP[-0x10] != (HKEY)0x0) {
    RegCloseKey((HKEY)unaff_RBP[-0x10]);
    unaff_RBP[-0x10] = unaff_RBX;
  }
  uVar5 = (undefined4)unaff_RBX;
  *(undefined4 *)(unaff_RBP + -0xf) = uVar5;
  if ((HKEY)unaff_RBP[-0xc] != (HKEY)0x0) {
    RegCloseKey((HKEY)unaff_RBP[-0xc]);
    unaff_RBP[-0xc] = unaff_RBX;
  }
  *(undefined4 *)(unaff_RBP + -0xb) = uVar5;
  if ((HKEY)unaff_RBP[-8] != (HKEY)0x0) {
    RegCloseKey((HKEY)unaff_RBP[-8]);
    unaff_RBP[-8] = unaff_RBX;
  }
  *(undefined4 *)(unaff_RBP + -7) = uVar5;
  if ((HKEY)unaff_RBP[-4] != (HKEY)0x0) {
    RegCloseKey((HKEY)unaff_RBP[-4]);
    unaff_RBP[-4] = unaff_RBX;
  }
  *(undefined4 *)(unaff_RBP + -3) = uVar5;
  if ((HKEY)unaff_RBP[2] != (HKEY)0x0) {
    RegCloseKey((HKEY)unaff_RBP[2]);
  }
  return uVar9;
}

/* ---- FUNC 00034B35 FUN_180034b35 (36 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180034b35(void)

{
  return 0;
}

/* ---- FUNC 00034B60 APModLibListLibs (88 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

DWORD APModLibListLibs(longlong param_1,DWORD param_2,int param_3)

{
  ulonglong uVar1;
  char cVar2;
  HKEY hKey;
  char *_Dest;
  longlong lVar3;
  longlong *plVar4;
  LSTATUS LVar5;
  int iVar6;
  DWORD DVar7;
  LPCSTR lpSubKey;
  undefined *puVar8;
  longlong *plVar9;
  longlong lVar10;
  ulonglong uVar12;
  longlong *plVar13;
  ulonglong uVar14;
  DWORD dwIndex;
  undefined1 auStackY_5b8 [32];
  CHAR local_578;
  char acStack_577 [3];
  DWORD local_574;
  DWORD local_570 [2];
  longlong *local_568;
  longlong local_560;
  HKEY local_558 [2];
  undefined4 local_548;
  undefined8 local_540;
  HKEY local_538 [2];
  undefined4 local_528;
  undefined8 local_520;
  HKEY local_518 [2];
  undefined4 local_508;
  undefined8 local_500;
  HKEY local_4f8 [2];
  undefined4 local_4e8;
  undefined8 local_4e0;
  _FILETIME local_4d8 [2];
  longlong local_4c8;
  longlong lStack_4c0;
  HKEY local_4b8 [2];
  undefined4 local_4a8;
  undefined8 local_4a0;
  longlong local_488;
  longlong local_480 [3];
  undefined8 local_468;
  HKEY pHStack_460;
  ulonglong local_458;
  ulonglong uStack_450;
  BYTE local_448 [1024];
  ulonglong local_48;
  longlong lVar11;
  
                    /* 0x34b60  267  APModLibListLibs */
  local_48 = DAT_1800791f8 ^ (ulonglong)auStackY_5b8;
  dwIndex = 0;
  DVar7 = 0;
  if (((param_1 == 0) || ((int)param_2 < 1)) || (param_3 < 1)) {
    DVar7 = 0;
  }
  else {
    local_4b8[0] = (HKEY)&DAT_180053988;
    local_4f8[0] = (HKEY)&DAT_180053988;
    local_518[0] = (HKEY)&DAT_180053988;
    local_538[0] = (HKEY)&DAT_180053988;
    local_558[0] = (HKEY)&DAT_180053988;
    local_4b8[1] = (HKEY)0x0;
    local_4a8 = 0;
    local_4a0 = 0;
    local_4f8[1] = (HKEY)0x0;
    local_4e8 = 0;
    local_4e0 = 0;
    local_518[1] = (HKEY)0x0;
    local_508 = 0;
    local_500 = 0;
    local_538[1] = (HKEY)0x0;
    local_528 = 0;
    local_520 = 0;
    local_558[1] = (HKEY)0x0;
    local_548 = 0;
    local_540 = 0;
    LVar5 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000001,"Software",0,0xf003f,local_4b8 + 1);
    if (((LVar5 == 0) &&
        (LVar5 = RegOpenKeyExA(*(HKEY *)((longlong)local_4b8 + (longlong)local_4b8[0][1].unused),
                               "AspenTech",0,0xf003f,
                               (PHKEY)((longlong)local_4f8 + (longlong)local_4f8[0][1].unused)),
        LVar5 == 0)) &&
       (LVar5 = RegOpenKeyExA(*(HKEY *)((longlong)local_4f8 + (longlong)local_4f8[0][1].unused),
                              "ASPEN PLUS",0,0xf003f,
                              (PHKEY)((longlong)local_518 + (longlong)local_518[0][1].unused)),
       LVar5 == 0)) {
      hKey = *(HKEY *)((longlong)local_518 + (longlong)local_518[0][1].unused);
      iVar6 = local_538[0][1].unused;
      lpSubKey = (LPCSTR)FUN_180024170();
      LVar5 = RegOpenKeyExA(hKey,lpSubKey,0,0xf003f,(PHKEY)((longlong)local_538 + (longlong)iVar6));
      if ((LVar5 == 0) &&
         (LVar5 = RegOpenKeyExA(*(HKEY *)((longlong)local_538 + (longlong)local_538[0][1].unused),
                                "Libraries",0,0xf003f,
                                (PHKEY)((longlong)local_558 + (longlong)local_558[0][1].unused)),
         LVar5 == 0)) {
        local_570[0] = 0x400;
        local_574 = 4;
        local_560 = 0;
        local_568 = operator_new(0x40);
        *local_568 = (longlong)local_568;
        local_568[1] = (longlong)local_568;
        local_568[2] = (longlong)local_568;
        *(undefined2 *)(local_568 + 3) = 0x101;
        iVar6 = RegEnumKeyExA(*(HKEY *)((longlong)local_558 + (longlong)local_558[0][1].unused),0,
                              &local_578,&local_574,(LPDWORD)0x0,(LPSTR)0x0,(LPDWORD)0x0,local_4d8);
        while (iVar6 == 0) {
          puVar8 = (undefined *)0x0;
          local_468 = (undefined *)0x0;
          pHStack_460 = (HKEY)0x0;
          uVar12 = 0xffffffffffffffff;
          do {
            uVar14 = uVar12;
            uVar12 = uVar14 + 1;
          } while (acStack_577[uVar14] != '\0');
          if (0x7fffffffffffffff < uVar12) {
                    /* WARNING: Subroutine does not return */
            FUN_18000ace0();
          }
          if (uVar12 < 0x10) {
            uStack_450 = 0xf;
            local_458 = uVar12;
            memcpy(&local_468,&local_578,uVar12);
            *(undefined1 *)((longlong)&local_468 + uVar14 + 1) = 0;
          }
          else {
            uVar14 = uVar12 | 0xf;
            if (uVar14 < 0x8000000000000000) {
              if (uVar14 < 0x16) {
                uVar14 = 0x16;
              }
              uVar1 = uVar14 + 1;
              if (uVar1 < 0x1000) {
                if (uVar1 != 0) {
                  puVar8 = operator_new(uVar1);
                }
              }
              else {
                puVar8 = (undefined *)FUN_180007f10(uVar1);
              }
            }
            else {
              uVar14 = 0x7fffffffffffffff;
              puVar8 = (undefined *)FUN_180007f10(0x8000000000000000);
            }
            local_468 = puVar8;
            local_458 = uVar12;
            uStack_450 = uVar14;
            memcpy(puVar8,&local_578,uVar12);
            puVar8[uVar12] = 0;
          }
          plVar9 = FUN_180031990((longlong *)&local_568,local_480,local_568,&local_468);
          plVar13 = local_568;
          local_4c8 = *plVar9;
          lStack_4c0 = plVar9[1];
          local_488 = plVar9[2];
          lVar11 = local_488;
          local_488._0_1_ = (char)plVar9[2];
          local_488 = lVar11;
          if ((char)local_488 == '\0') {
            if (local_560 == 0x3ffffffffffffff) {
                    /* WARNING: Subroutine does not return */
              FUN_18000ac90();
            }
            plVar9 = operator_new(0x40);
            plVar9[4] = (longlong)local_468;
            plVar9[5] = (longlong)pHStack_460;
            plVar9[6] = local_458;
            plVar9[7] = uStack_450;
            *plVar9 = (longlong)plVar13;
            plVar9[1] = (longlong)plVar13;
            plVar9[2] = (longlong)plVar13;
            *(undefined2 *)(plVar9 + 3) = 0;
            FUN_18000a930((longlong *)&local_568,&local_4c8,plVar9);
          }
          else if (0xf < uStack_450) {
            puVar8 = local_468;
            if ((0xfff < uStack_450 + 1) &&
               (puVar8 = *(undefined **)(local_468 + -8),
               (undefined *)0x1f < local_468 + (-8 - (longlong)puVar8))) {
                    /* WARNING: Subroutine does not return */
              _invalid_parameter_noinfo_noreturn();
            }
            operator_delete(puVar8);
          }
          dwIndex = dwIndex + 1;
          local_574 = 4;
          if (dwIndex == param_2) break;
          iVar6 = RegEnumKeyExA(*(HKEY *)((longlong)local_558 + (longlong)local_558[0][1].unused),
                                dwIndex,&local_578,&local_574,(LPDWORD)0x0,(LPSTR)0x0,(LPDWORD)0x0,
                                local_4d8);
        }
        uVar12 = 0;
        plVar13 = (longlong *)*local_568;
        if (plVar13 != local_568) {
          do {
            plVar9 = plVar13 + 4;
            local_468 = &DAT_180053988;
            pHStack_460 = (HKEY)0x0;
            local_458 = local_458 & 0xffffffff00000000;
            uStack_450 = 0;
            if (0xf < (ulonglong)plVar13[7]) {
              plVar9 = (longlong *)*plVar9;
            }
            LVar5 = RegOpenKeyExA(*(HKEY *)((longlong)local_558 + (longlong)local_558[0][1].unused),
                                  (LPCSTR)plVar9,0,0xf003f,&pHStack_460);
            if (LVar5 == 0) {
              local_570[0] = 0x400;
              LVar5 = RegQueryValueExA(*(HKEY *)((longlong)&local_468 +
                                                (longlong)*(int *)(local_468 + 4)),"Display Name",
                                       (LPDWORD)0x0,(LPDWORD)0x0,local_448,local_570);
              if (LVar5 == 0) {
                lVar11 = -1;
                do {
                  lVar10 = lVar11 + 1;
                  lVar3 = lVar11 + 1;
                  lVar11 = lVar10;
                } while (local_448[lVar3] != '\0');
                iVar6 = (int)lVar10;
                if (param_3 + -1 <= iVar6) {
                  iVar6 = param_3 + -1;
                }
                _Dest = *(char **)(param_1 + uVar12 * 8);
                strncpy(_Dest,(char *)local_448,(longlong)iVar6);
                _Dest[iVar6] = '\0';
              }
            }
            uVar12 = (ulonglong)((int)uVar12 + 1);
            if (pHStack_460 != (HKEY)0x0) {
              RegCloseKey(pHStack_460);
            }
            plVar9 = (longlong *)plVar13[2];
            if (*(char *)((longlong)plVar9 + 0x19) == '\0') {
              cVar2 = *(char *)(*plVar9 + 0x19);
              plVar13 = plVar9;
              plVar9 = (longlong *)*plVar9;
              while (cVar2 == '\0') {
                cVar2 = *(char *)(*plVar9 + 0x19);
                plVar13 = plVar9;
                plVar9 = (longlong *)*plVar9;
              }
            }
            else {
              cVar2 = *(char *)(plVar13[1] + 0x19);
              plVar4 = (longlong *)plVar13[1];
              plVar9 = plVar13;
              while ((plVar13 = plVar4, cVar2 == '\0' && (plVar9 == (longlong *)plVar13[2]))) {
                cVar2 = *(char *)(plVar13[1] + 0x19);
                plVar4 = (longlong *)plVar13[1];
                plVar9 = plVar13;
              }
            }
          } while (plVar13 != local_568);
        }
        DVar7 = 1;
        FUN_1800318d0(&local_568,&local_568,(longlong *)local_568[1]);
        operator_delete(local_568);
      }
    }
    if (local_558[1] != (HKEY)0x0) {
      RegCloseKey(local_558[1]);
      local_558[1] = (HKEY)0x0;
    }
    local_548 = 0;
    if (local_538[1] != (HKEY)0x0) {
      RegCloseKey(local_538[1]);
      local_538[1] = (HKEY)0x0;
    }
    local_528 = 0;
    if (local_518[1] != (HKEY)0x0) {
      RegCloseKey(local_518[1]);
      local_518[1] = (HKEY)0x0;
    }
    local_508 = 0;
    if (local_4f8[1] != (HKEY)0x0) {
      RegCloseKey(local_4f8[1]);
      local_4f8[1] = (HKEY)0x0;
    }
    local_4e8 = 0;
    if (local_4b8[1] != (HKEY)0x0) {
      RegCloseKey(local_4b8[1]);
    }
  }
  return DVar7;
}

/* ---- FUNC 00034BB8 FUN_180034bb8 (1584 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_180034bb8(void)

{
  ulonglong uVar1;
  char cVar2;
  int iVar3;
  HKEY hKey;
  void *pvVar4;
  char *_Dest;
  longlong lVar5;
  longlong lVar6;
  longlong *plVar7;
  LSTATUS LVar8;
  int iVar9;
  longlong in_RAX;
  LPCSTR lpSubKey;
  HKEY pHVar10;
  longlong *plVar11;
  void *pvVar12;
  longlong lVar13;
  undefined8 unaff_RBX;
  ulonglong uVar15;
  longlong *plVar16;
  ulonglong uVar17;
  longlong *unaff_RBP;
  undefined4 uVar18;
  HKEY unaff_RSI;
  undefined8 unaff_RDI;
  ulonglong uVar19;
  longlong in_R11;
  longlong unaff_R12;
  int unaff_R13D;
  uint dwIndex;
  undefined8 unaff_R14;
  uint unaff_R15D;
  undefined8 in_stack_00000040;
  DWORD in_stack_00000048;
  longlong *in_stack_00000050;
  longlong lStack0000000000000060;
  int iStack0000000000000070;
  longlong lVar14;
  
  *(undefined8 *)(in_R11 + 0x10) = unaff_RBX;
  *unaff_RBP = in_RAX;
  unaff_RBP[-8] = in_RAX;
  unaff_RBP[-0xc] = in_RAX;
  unaff_RBP[-0x10] = in_RAX;
  *(undefined8 *)(in_R11 + -0x30) = unaff_RDI;
  *(undefined8 *)(in_R11 + -0x38) = unaff_R14;
  unaff_RBP[1] = (longlong)unaff_RSI;
  iVar9 = (int)unaff_RSI;
  *(int *)(unaff_RBP + 2) = iVar9;
  unaff_RBP[3] = (longlong)unaff_RSI;
  unaff_RBP[-7] = (longlong)unaff_RSI;
  *(int *)(unaff_RBP + -6) = iVar9;
  unaff_RBP[-5] = (longlong)unaff_RSI;
  unaff_RBP[-0xb] = (longlong)unaff_RSI;
  *(int *)(unaff_RBP + -10) = iVar9;
  unaff_RBP[-9] = (longlong)unaff_RSI;
  unaff_RBP[-0xf] = (longlong)unaff_RSI;
  *(int *)(unaff_RBP + -0xe) = iVar9;
  unaff_RBP[-0xd] = (longlong)unaff_RSI;
  lStack0000000000000060 = in_RAX;
  iStack0000000000000070 = iVar9;
  LVar8 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000001,"Software",0,0xf003f,(PHKEY)(unaff_RBP + 1));
  pHVar10 = unaff_RSI;
  if (((LVar8 == 0) &&
      (LVar8 = RegOpenKeyExA(*(HKEY *)((longlong)unaff_RBP + (longlong)*(int *)(*unaff_RBP + 4)),
                             "AspenTech",0,0xf003f,
                             (PHKEY)((longlong)unaff_RBP +
                                    (longlong)*(int *)(unaff_RBP[-8] + 4) + -0x40)), LVar8 == 0)) &&
     (LVar8 = RegOpenKeyExA(*(HKEY *)((longlong)unaff_RBP +
                                     (longlong)*(int *)(unaff_RBP[-8] + 4) + -0x40),"ASPEN PLUS",0,
                            0xf003f,(PHKEY)((longlong)unaff_RBP +
                                           (longlong)*(int *)(unaff_RBP[-0xc] + 4) + -0x60)),
     LVar8 == 0)) {
    hKey = *(HKEY *)((longlong)unaff_RBP + (longlong)*(int *)(unaff_RBP[-0xc] + 4) + -0x60);
    iVar3 = *(int *)(unaff_RBP[-0x10] + 4);
    lpSubKey = (LPCSTR)FUN_180024170();
    LVar8 = RegOpenKeyExA(hKey,lpSubKey,0,0xf003f,
                          (PHKEY)((longlong)unaff_RBP + (longlong)iVar3 + -0x80));
    if ((LVar8 == 0) &&
       (LVar8 = RegOpenKeyExA(*(HKEY *)((longlong)unaff_RBP +
                                       (longlong)*(int *)(unaff_RBP[-0x10] + 4) + -0x80),"Libraries"
                              ,0,0xf003f,
                              (PHKEY)((longlong)&stack0x00000060 +
                                     (longlong)*(int *)(lStack0000000000000060 + 4))), LVar8 == 0))
    {
      in_stack_00000048 = 0x400;
      uVar17 = (ulonglong)unaff_RSI & 0xffffffff;
      in_stack_00000040._4_4_ = 4;
      in_stack_00000050 = operator_new((ulonglong)(iVar9 + 0x40));
      *in_stack_00000050 = (longlong)in_stack_00000050;
      in_stack_00000050[1] = (longlong)in_stack_00000050;
      in_stack_00000050[2] = (longlong)in_stack_00000050;
      *(undefined2 *)(in_stack_00000050 + 3) = 0x101;
      iVar9 = RegEnumKeyExA(*(HKEY *)((longlong)&stack0x00000060 +
                                     (longlong)*(int *)(lStack0000000000000060 + 4)),0,
                            (LPSTR)&stack0x00000040,(LPDWORD)((longlong)&stack0x00000040 + 4),
                            (LPDWORD)unaff_RSI,(LPSTR)unaff_RSI,(LPDWORD)unaff_RSI,
                            (PFILETIME)(unaff_RBP + -4));
      while (iVar9 == 0) {
        unaff_RBP[10] = 0;
        unaff_RBP[0xb] = 0;
        uVar15 = 0xffffffffffffffff;
        do {
          uVar19 = uVar15;
          uVar15 = uVar19 + 1;
        } while (*(char *)((longlong)&stack0x00000040 + uVar19 + 1) != '\0');
        if (0x7fffffffffffffff < uVar15) {
                    /* WARNING: Subroutine does not return */
          FUN_18000ace0();
        }
        if (uVar15 < 0x10) {
          unaff_RBP[0xc] = uVar15;
          unaff_RBP[0xd] = 0xf;
          memcpy(unaff_RBP + 10,&stack0x00000040,uVar15);
          *(undefined1 *)((longlong)unaff_RBP + uVar19 + 0x51) = 0;
        }
        else {
          uVar19 = uVar15 | 0xf;
          if (uVar19 < 0x8000000000000000) {
            if (uVar19 < 0x16) {
              uVar19 = 0x16;
            }
            uVar1 = uVar19 + 1;
            if (uVar1 < 0x1000) {
              if (uVar1 != 0) {
                pHVar10 = operator_new(uVar1);
              }
            }
            else {
              pHVar10 = (HKEY)FUN_180007f10(uVar1);
            }
          }
          else {
            uVar19 = 0x7fffffffffffffff;
            pHVar10 = (HKEY)FUN_180007f10(0x8000000000000000);
          }
          unaff_RBP[10] = (longlong)pHVar10;
          unaff_RBP[0xc] = uVar15;
          unaff_RBP[0xd] = uVar19;
          memcpy(pHVar10,&stack0x00000040,uVar15);
          *(undefined1 *)((longlong)&pHVar10->unused + uVar15) = 0;
          pHVar10 = (HKEY)0x0;
        }
        plVar11 = FUN_180031990((longlong *)&stack0x00000050,unaff_RBP + 7,in_stack_00000050,
                                unaff_RBP + 10);
        plVar16 = in_stack_00000050;
        lVar14 = plVar11[1];
        unaff_RBP[-2] = *plVar11;
        unaff_RBP[-1] = lVar14;
        unaff_RBP[6] = plVar11[2];
        if ((char)unaff_RBP[6] == '\0') {
          if (unaff_RSI == (HKEY)0x3ffffffffffffff) {
                    /* WARNING: Subroutine does not return */
            FUN_18000ac90();
          }
          plVar11 = operator_new(0x40);
          lVar14 = unaff_RBP[0xb];
          lVar5 = unaff_RBP[0xc];
          lVar13 = unaff_RBP[0xd];
          plVar11[4] = unaff_RBP[10];
          plVar11[5] = lVar14;
          lVar14 = unaff_RBP[-2];
          lVar6 = unaff_RBP[-1];
          plVar11[6] = lVar5;
          plVar11[7] = lVar13;
          *plVar11 = (longlong)plVar16;
          plVar11[1] = (longlong)plVar16;
          plVar11[2] = (longlong)plVar16;
          *(undefined2 *)(plVar11 + 3) = 0;
          unaff_RBP[-2] = lVar14;
          unaff_RBP[-1] = lVar6;
          FUN_18000a930((longlong *)&stack0x00000050,unaff_RBP + -2,plVar11);
        }
        else if (0xf < (ulonglong)unaff_RBP[0xd]) {
          pvVar4 = (void *)unaff_RBP[10];
          pvVar12 = pvVar4;
          if ((0xfff < unaff_RBP[0xd] + 1U) &&
             (pvVar12 = *(void **)((longlong)pvVar4 + -8),
             0x1f < (ulonglong)((longlong)pvVar4 + (-8 - (longlong)pvVar12)))) {
                    /* WARNING: Subroutine does not return */
            _invalid_parameter_noinfo_noreturn();
          }
          operator_delete(pvVar12);
        }
        dwIndex = (int)uVar17 + 1;
        uVar17 = (ulonglong)dwIndex;
        in_stack_00000040._4_4_ = 4;
        if (dwIndex == unaff_R15D) break;
        iVar9 = RegEnumKeyExA(*(HKEY *)((longlong)&stack0x00000060 +
                                       (longlong)*(int *)(lStack0000000000000060 + 4)),dwIndex,
                              (LPSTR)&stack0x00000040,(LPDWORD)((longlong)&stack0x00000040 + 4),
                              (LPDWORD)pHVar10,(LPSTR)pHVar10,(LPDWORD)pHVar10,
                              (PFILETIME)(unaff_RBP + -4));
      }
      uVar17 = (ulonglong)pHVar10 & 0xffffffff;
      plVar16 = (longlong *)*in_stack_00000050;
      if (plVar16 != in_stack_00000050) {
        do {
          uVar15 = plVar16[7];
          plVar11 = plVar16 + 4;
          unaff_RBP[10] = (longlong)&DAT_180053988;
          unaff_RBP[0xb] = (longlong)pHVar10;
          *(int *)(unaff_RBP + 0xc) = (int)pHVar10;
          unaff_RBP[0xd] = (longlong)pHVar10;
          if (0xf < uVar15) {
            plVar11 = (longlong *)*plVar11;
          }
          LVar8 = RegOpenKeyExA(*(HKEY *)((longlong)&stack0x00000060 +
                                         (longlong)*(int *)(lStack0000000000000060 + 4)),
                                (LPCSTR)plVar11,0,0xf003f,(PHKEY)(unaff_RBP + 0xb));
          if (LVar8 == 0) {
            in_stack_00000048 = 0x400;
            LVar8 = RegQueryValueExA(*(HKEY *)((longlong)unaff_RBP +
                                              (longlong)*(int *)(unaff_RBP[10] + 4) + 0x50),
                                     "Display Name",(LPDWORD)0x0,(LPDWORD)0x0,
                                     (LPBYTE)(unaff_RBP + 0xe),&stack0x00000048);
            if (LVar8 == 0) {
              lVar14 = -1;
              do {
                lVar13 = lVar14 + 1;
                lVar5 = lVar14 + 0x71;
                lVar14 = lVar13;
              } while (*(char *)((longlong)unaff_RBP + lVar5) != '\0');
              iVar9 = (int)lVar13;
              if (unaff_R13D + -1 <= iVar9) {
                iVar9 = unaff_R13D + -1;
              }
              _Dest = *(char **)(unaff_R12 + uVar17 * 8);
              strncpy(_Dest,(char *)(unaff_RBP + 0xe),(longlong)iVar9);
              _Dest[iVar9] = '\0';
              pHVar10 = (HKEY)0x0;
            }
          }
          uVar17 = (ulonglong)((int)uVar17 + 1);
          if ((HKEY)unaff_RBP[0xb] != (HKEY)0x0) {
            RegCloseKey((HKEY)unaff_RBP[0xb]);
          }
          plVar11 = (longlong *)plVar16[2];
          if (*(char *)((longlong)plVar11 + 0x19) == '\0') {
            cVar2 = *(char *)(*plVar11 + 0x19);
            plVar16 = plVar11;
            plVar11 = (longlong *)*plVar11;
            while (cVar2 == '\0') {
              cVar2 = *(char *)(*plVar11 + 0x19);
              plVar16 = plVar11;
              plVar11 = (longlong *)*plVar11;
            }
          }
          else {
            cVar2 = *(char *)(plVar16[1] + 0x19);
            plVar7 = (longlong *)plVar16[1];
            plVar11 = plVar16;
            while ((plVar16 = plVar7, cVar2 == '\0' && (plVar11 == (longlong *)plVar16[2]))) {
              cVar2 = *(char *)(plVar16[1] + 0x19);
              plVar7 = (longlong *)plVar16[1];
              plVar11 = plVar16;
            }
          }
        } while (plVar16 != in_stack_00000050);
      }
      uVar17 = 1;
      FUN_1800318d0(&stack0x00000050,&stack0x00000050,(longlong *)in_stack_00000050[1]);
      operator_delete(in_stack_00000050);
      goto LAB_180035136;
    }
  }
  uVar17 = (ulonglong)unaff_RSI & 0xffffffff;
LAB_180035136:
  if (unaff_RSI != (HKEY)0x0) {
    RegCloseKey(unaff_RSI);
  }
  uVar18 = SUB84(pHVar10,0);
  iStack0000000000000070 = uVar18;
  if ((HKEY)unaff_RBP[-0xf] != (HKEY)0x0) {
    RegCloseKey((HKEY)unaff_RBP[-0xf]);
    unaff_RBP[-0xf] = (longlong)pHVar10;
  }
  *(undefined4 *)(unaff_RBP + -0xe) = uVar18;
  if ((HKEY)unaff_RBP[-0xb] != (HKEY)0x0) {
    RegCloseKey((HKEY)unaff_RBP[-0xb]);
    unaff_RBP[-0xb] = (longlong)pHVar10;
  }
  *(undefined4 *)(unaff_RBP + -10) = uVar18;
  if ((HKEY)unaff_RBP[-7] != (HKEY)0x0) {
    RegCloseKey((HKEY)unaff_RBP[-7]);
    unaff_RBP[-7] = (longlong)pHVar10;
  }
  *(undefined4 *)(unaff_RBP + -6) = uVar18;
  if ((HKEY)unaff_RBP[1] != (HKEY)0x0) {
    RegCloseKey((HKEY)unaff_RBP[1]);
  }
  return uVar17;
}

/* ---- FUNC 000351BA FUN_1800351ba (31 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1800351ba(void)

{
  return;
}

/* ---- FUNC 000351DD thunk_FUN_18000ace0 (5 bytes) ---- */

void thunk_FUN_18000ace0(void)

{
                    /* WARNING: Subroutine does not return */
  FUN_18000ace0();
}

/* ---- FUNC 000351F0 APModLibNameUsed (55 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 APModLibNameUsed(longlong param_1)

{
  BYTE BVar1;
  BYTE BVar2;
  HKEY hKey;
  LSTATUS LVar3;
  int iVar4;
  LPCSTR lpSubKey;
  BYTE *pBVar5;
  DWORD dwIndex;
  undefined4 unaff_EDI;
  longlong lVar6;
  undefined1 auStackY_548 [32];
  DWORD local_508;
  CHAR local_504 [4];
  DWORD local_500 [2];
  HKEY local_4f8 [2];
  undefined4 local_4e8;
  undefined8 local_4e0;
  HKEY local_4d8 [2];
  undefined4 local_4c8;
  undefined8 local_4c0;
  HKEY local_4b8 [2];
  undefined4 local_4a8;
  undefined8 local_4a0;
  HKEY local_498 [2];
  undefined4 local_488;
  undefined8 local_480;
  HKEY local_478 [2];
  undefined4 local_468;
  undefined8 local_460;
  _FILETIME local_458;
  HKEY local_450 [2];
  undefined4 local_440;
  undefined8 local_438;
  BYTE local_428 [1024];
  ulonglong local_28;
  
                    /* 0x351f0  268  APModLibNameUsed */
  local_28 = DAT_1800791f8 ^ (ulonglong)auStackY_548;
  dwIndex = 0;
  if (param_1 != 0) {
    local_450[1] = (HKEY)0x0;
    local_450[0] = (HKEY)&DAT_180053988;
    local_498[0] = (HKEY)&DAT_180053988;
    local_4b8[0] = (HKEY)&DAT_180053988;
    local_4d8[0] = (HKEY)&DAT_180053988;
    local_4f8[0] = (HKEY)&DAT_180053988;
    local_440 = 0;
    local_438 = 0;
    local_498[1] = (HKEY)0x0;
    local_488 = 0;
    local_480 = 0;
    local_4b8[1] = (HKEY)0x0;
    local_4a8 = 0;
    local_4a0 = 0;
    local_4d8[1] = (HKEY)0x0;
    local_4c8 = 0;
    local_4c0 = 0;
    local_4f8[1] = (HKEY)0x0;
    local_4e8 = 0;
    local_4e0 = 0;
    LVar3 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000001,"Software",0,0xf003f,local_450 + 1);
    if (((LVar3 == 0) &&
        (LVar3 = RegOpenKeyExA(*(HKEY *)((longlong)local_450 + (longlong)local_450[0][1].unused),
                               "AspenTech",0,0xf003f,
                               (PHKEY)((longlong)local_498 + (longlong)local_498[0][1].unused)),
        LVar3 == 0)) &&
       (LVar3 = RegOpenKeyExA(*(HKEY *)((longlong)local_498 + (longlong)local_498[0][1].unused),
                              "ASPEN PLUS",0,0xf003f,
                              (PHKEY)((longlong)local_4b8 + (longlong)local_4b8[0][1].unused)),
       LVar3 == 0)) {
      iVar4 = local_4d8[0][1].unused;
      hKey = *(HKEY *)((longlong)local_4b8 + (longlong)local_4b8[0][1].unused);
      lpSubKey = (LPCSTR)FUN_180024170();
      LVar3 = RegOpenKeyExA(hKey,lpSubKey,0,0xf003f,(PHKEY)((longlong)local_4d8 + (longlong)iVar4));
      if ((LVar3 == 0) &&
         (LVar3 = RegOpenKeyExA(*(HKEY *)((longlong)local_4d8 + (longlong)local_4d8[0][1].unused),
                                "Libraries",0,0xf003f,
                                (PHKEY)((longlong)local_4f8 + (longlong)local_4f8[0][1].unused)),
         LVar3 == 0)) {
        local_500[0] = 0x400;
        local_508 = 4;
        iVar4 = RegEnumKeyExA(*(HKEY *)((longlong)local_4f8 + (longlong)local_4f8[0][1].unused),0,
                              local_504,&local_508,(LPDWORD)0x0,(LPSTR)0x0,(LPDWORD)0x0,&local_458);
        while (iVar4 == 0) {
          local_478[0] = (HKEY)&DAT_180053988;
          local_478[1] = (HKEY)0x0;
          local_468 = 0;
          local_460 = 0;
          LVar3 = RegOpenKeyExA(*(HKEY *)((longlong)local_4f8 + (longlong)local_4f8[0][1].unused),
                                local_504,0,0xf003f,local_478 + 1);
          if (LVar3 == 0) {
            local_500[0] = 0x400;
            LVar3 = RegQueryValueExA(*(HKEY *)((longlong)local_478 +
                                              (longlong)local_478[0][1].unused),"Display Name",
                                     (LPDWORD)0x0,(LPDWORD)0x0,local_428,local_500);
            if (LVar3 == 0) {
              pBVar5 = local_428;
              lVar6 = param_1 - (longlong)pBVar5;
              do {
                BVar1 = *pBVar5;
                BVar2 = pBVar5[lVar6];
                if (BVar1 != BVar2) break;
                pBVar5 = pBVar5 + 1;
              } while (BVar2 != '\0');
              if (BVar1 == BVar2) {
                if (local_478[1] != (HKEY)0x0) {
                  RegCloseKey(local_478[1]);
                }
                break;
              }
            }
          }
          dwIndex = dwIndex + 1;
          local_508 = 4;
          if (local_478[1] != (HKEY)0x0) {
            RegCloseKey(local_478[1]);
          }
          iVar4 = RegEnumKeyExA(*(HKEY *)((longlong)local_4f8 + (longlong)local_4f8[0][1].unused),
                                dwIndex,local_504,&local_508,(LPDWORD)0x0,(LPSTR)0x0,(LPDWORD)0x0,
                                &local_458);
        }
      }
    }
    if (local_4f8[1] != (HKEY)0x0) {
      RegCloseKey(local_4f8[1]);
      local_4f8[1] = (HKEY)0x0;
    }
    local_4e8 = 0;
    if (local_4d8[1] != (HKEY)0x0) {
      RegCloseKey(local_4d8[1]);
      local_4d8[1] = (HKEY)0x0;
    }
    local_4c8 = 0;
    if (local_4b8[1] != (HKEY)0x0) {
      RegCloseKey(local_4b8[1]);
      local_4b8[1] = (HKEY)0x0;
    }
    local_4a8 = 0;
    if (local_498[1] != (HKEY)0x0) {
      RegCloseKey(local_498[1]);
      local_498[1] = (HKEY)0x0;
    }
    local_488 = 0;
    if (local_450[1] != (HKEY)0x0) {
      RegCloseKey(local_450[1]);
    }
  }
  return unaff_EDI;
}

/* ---- FUNC 00035227 FUN_180035227 (830 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_180035227(void)

{
  char cVar1;
  char cVar2;
  HKEY hKey;
  undefined4 uVar3;
  LSTATUS LVar4;
  int iVar5;
  LPCSTR lpSubKey;
  PHKEY ppHVar6;
  uint dwIndex;
  ulonglong uVar7;
  PHKEY unaff_RBP;
  longlong unaff_RSI;
  ulonglong uVar8;
  longlong lVar9;
  undefined4 uVar10;
  HKEY unaff_R14;
  DWORD in_stack_00000040;
  DWORD in_stack_00000048;
  undefined *puStack0000000000000050;
  undefined4 uStack0000000000000060;
  undefined *puStack0000000000000070;
  
  *unaff_RBP = unaff_R14;
  unaff_RBP[-1] = (HKEY)&DAT_180053988;
  unaff_RBP[-10] = (HKEY)&DAT_180053988;
  unaff_RBP[-0xe] = (HKEY)&DAT_180053988;
  puStack0000000000000070 = &DAT_180053988;
  puStack0000000000000050 = &DAT_180053988;
  uVar10 = SUB84(unaff_R14,0);
  *(undefined4 *)(unaff_RBP + 1) = uVar10;
  unaff_RBP[2] = unaff_R14;
  unaff_RBP[-9] = unaff_R14;
  *(undefined4 *)(unaff_RBP + -8) = uVar10;
  unaff_RBP[-7] = unaff_R14;
  unaff_RBP[-0xd] = unaff_R14;
  *(undefined4 *)(unaff_RBP + -0xc) = uVar10;
  unaff_RBP[-0xb] = unaff_R14;
  *(undefined4 *)(unaff_RBP + -0x10) = uVar10;
  unaff_RBP[-0xf] = unaff_R14;
  uStack0000000000000060 = uVar10;
  LVar4 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000001,"Software",0,0xf003f,unaff_RBP);
  if (((LVar4 == 0) &&
      (LVar4 = RegOpenKeyExA(*(HKEY *)((longlong)unaff_RBP + (longlong)unaff_RBP[-1][1].unused + -8)
                             ,"AspenTech",0,0xf003f,
                             (PHKEY)((longlong)unaff_RBP +
                                    (longlong)unaff_RBP[-10][1].unused + -0x50)), LVar4 == 0)) &&
     (LVar4 = RegOpenKeyExA(*(HKEY *)((longlong)unaff_RBP +
                                     (longlong)unaff_RBP[-10][1].unused + -0x50),"ASPEN PLUS",0,
                            0xf003f,(PHKEY)((longlong)unaff_RBP +
                                           (longlong)unaff_RBP[-0xe][1].unused + -0x70)), LVar4 == 0
     )) {
    iVar5 = *(int *)(puStack0000000000000070 + 4);
    hKey = *(HKEY *)((longlong)unaff_RBP + (longlong)unaff_RBP[-0xe][1].unused + -0x70);
    lpSubKey = (LPCSTR)FUN_180024170();
    LVar4 = RegOpenKeyExA(hKey,lpSubKey,0,0xf003f,
                          (PHKEY)((longlong)&stack0x00000070 + (longlong)iVar5));
    if ((LVar4 == 0) &&
       (LVar4 = RegOpenKeyExA(*(HKEY *)((longlong)&stack0x00000070 +
                                       (longlong)*(int *)(puStack0000000000000070 + 4)),"Libraries",
                              0,0xf003f,
                              (PHKEY)((longlong)&stack0x00000050 +
                                     (longlong)*(int *)(puStack0000000000000050 + 4))), LVar4 == 0))
    {
      in_stack_00000048 = 0x400;
      in_stack_00000040 = 4;
      uVar7 = (ulonglong)unaff_R14 & 0xffffffff;
      uVar8 = (ulonglong)unaff_R14 & 0xffffffff;
      iVar5 = RegEnumKeyExA(*(HKEY *)((longlong)&stack0x00000050 +
                                     (longlong)*(int *)(puStack0000000000000050 + 4)),0,
                            &stack0x00000044,&stack0x00000040,(LPDWORD)unaff_R14,(LPSTR)unaff_R14,
                            (LPDWORD)unaff_R14,(PFILETIME)(unaff_RBP + -2));
      while (iVar5 == 0) {
        unaff_RBP[-6] = (HKEY)&DAT_180053988;
        unaff_RBP[-5] = unaff_R14;
        *(undefined4 *)(unaff_RBP + -4) = uVar10;
        unaff_RBP[-3] = unaff_R14;
        LVar4 = RegOpenKeyExA(*(HKEY *)((longlong)&stack0x00000050 +
                                       (longlong)*(int *)(puStack0000000000000050 + 4)),
                              &stack0x00000044,0,0xf003f,unaff_RBP + -5);
        if (LVar4 == 0) {
          in_stack_00000048 = 0x400;
          LVar4 = RegQueryValueExA(*(HKEY *)((longlong)unaff_RBP +
                                            (longlong)unaff_RBP[-6][1].unused + -0x30),
                                   "Display Name",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)(unaff_RBP + 4),
                                   &stack0x00000048);
          if (LVar4 == 0) {
            ppHVar6 = unaff_RBP + 4;
            lVar9 = unaff_RSI - (longlong)ppHVar6;
            do {
              cVar1 = *(char *)ppHVar6;
              cVar2 = *(char *)((longlong)ppHVar6 + lVar9);
              if (cVar1 != cVar2) break;
              ppHVar6 = (PHKEY)((longlong)ppHVar6 + 1);
            } while (cVar2 != '\0');
            if (cVar1 == cVar2) {
              uVar8 = 1;
              if (unaff_RBP[-5] != (HKEY)0x0) {
                RegCloseKey(unaff_RBP[-5]);
              }
              break;
            }
          }
        }
        dwIndex = (int)uVar7 + 1;
        uVar7 = (ulonglong)dwIndex;
        in_stack_00000040 = 4;
        if (unaff_RBP[-5] != (HKEY)0x0) {
          RegCloseKey(unaff_RBP[-5]);
        }
        iVar5 = RegEnumKeyExA(*(HKEY *)((longlong)&stack0x00000050 +
                                       (longlong)*(int *)(puStack0000000000000050 + 4)),dwIndex,
                              &stack0x00000044,&stack0x00000040,(LPDWORD)unaff_R14,(LPSTR)unaff_R14,
                              (LPDWORD)unaff_R14,(PFILETIME)(unaff_RBP + -2));
      }
      goto LAB_18003554b;
    }
  }
  uVar8 = (ulonglong)unaff_R14 & 0xffffffff;
LAB_18003554b:
  uVar3 = uVar10;
  if (unaff_R14 != (HKEY)0x0) {
    RegCloseKey(unaff_R14);
    uStack0000000000000060 = uVar10;
    RegCloseKey(unaff_R14);
    uVar3 = uStack0000000000000060;
  }
  uStack0000000000000060 = uVar3;
  *(undefined4 *)(unaff_RBP + -0x10) = uVar10;
  if (unaff_RBP[-0xd] != (HKEY)0x0) {
    RegCloseKey(unaff_RBP[-0xd]);
    unaff_RBP[-0xd] = unaff_R14;
  }
  *(undefined4 *)(unaff_RBP + -0xc) = uVar10;
  if (unaff_RBP[-9] != (HKEY)0x0) {
    RegCloseKey(unaff_RBP[-9]);
    unaff_RBP[-9] = unaff_R14;
  }
  *(undefined4 *)(unaff_RBP + -8) = uVar10;
  if (*unaff_RBP != (HKEY)0x0) {
    RegCloseKey(*unaff_RBP);
  }
  return uVar8;
}

/* ---- FUNC 00035565 FUN_180035565 (112 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_180035565(HKEY param_1)

{
  undefined8 *unaff_RBP;
  undefined4 unaff_EDI;
  undefined4 uVar1;
  undefined8 unaff_R14;
  HKEY in_stack_00000078;
  
  RegCloseKey(param_1);
  uVar1 = (undefined4)unaff_R14;
  if (in_stack_00000078 != (HKEY)0x0) {
    RegCloseKey(in_stack_00000078);
  }
  *(undefined4 *)(unaff_RBP + -0x10) = uVar1;
  if ((HKEY)unaff_RBP[-0xd] != (HKEY)0x0) {
    RegCloseKey((HKEY)unaff_RBP[-0xd]);
    unaff_RBP[-0xd] = unaff_R14;
  }
  *(undefined4 *)(unaff_RBP + -0xc) = uVar1;
  if ((HKEY)unaff_RBP[-9] != (HKEY)0x0) {
    RegCloseKey((HKEY)unaff_RBP[-9]);
    unaff_RBP[-9] = unaff_R14;
  }
  *(undefined4 *)(unaff_RBP + -8) = uVar1;
  if ((HKEY)*unaff_RBP != (HKEY)0x0) {
    RegCloseKey((HKEY)*unaff_RBP);
  }
  return unaff_EDI;
}

/* ---- FUNC 000355D5 FUN_1800355d5 (27 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1800355d5(void)

{
  return;
}

/* ---- FUNC 000355F0 APModLibRegisterLib (2624 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 APModLibRegisterLib(char *param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  BYTE BVar2;
  BYTE BVar3;
  HKEY hKey;
  int iVar4;
  int iVar5;
  int iVar6;
  LSTATUS LVar7;
  int iVar8;
  int iVar9;
  LPCSTR lpSubKey;
  void *_Memory;
  longlong lVar10;
  BYTE *pBVar11;
  uint uVar12;
  int *piVar13;
  DWORD DVar14;
  DWORD dwIndex;
  int iVar15;
  longlong lVar16;
  LPDWORD lpcchName;
  longlong lVar17;
  uint uVar18;
  undefined1 auStackY_6c8 [32];
  DWORD local_678;
  CHAR local_674 [4];
  HKEY local_670 [2];
  undefined4 local_660;
  undefined8 local_658;
  HKEY local_650 [2];
  undefined4 local_640;
  undefined8 local_638;
  HKEY local_630 [2];
  undefined4 local_620;
  undefined8 local_618;
  DWORD local_610 [2];
  HKEY local_608 [2];
  undefined4 local_5f8;
  undefined8 local_5f0;
  DWORD local_5e8;
  undefined4 local_5e4;
  HKEY local_5e0 [2];
  undefined4 local_5d0;
  undefined8 local_5c8;
  HKEY local_5c0 [2];
  undefined4 local_5b0;
  undefined8 local_5a8;
  undefined4 local_5a0;
  undefined4 local_59c;
  undefined4 local_598;
  _FILETIME local_590;
  HKEY local_588 [2];
  undefined4 local_578;
  undefined8 local_570;
  BYTE local_568 [260];
  undefined1 local_464;
  BYTE local_458 [1023];
  undefined1 local_59;
  ulonglong local_58;
  
                    /* 0x355f0  269  APModLibRegisterLib */
  local_58 = DAT_1800791f8 ^ (ulonglong)auStackY_6c8;
  if (param_1 == (char *)0x0) {
    return 0;
  }
  if (param_2 == (char *)0x0) {
    return 0;
  }
  local_5c0[1] = (HKEY)0x0;
  local_5c0[0] = (HKEY)&DAT_180053988;
  local_650[0] = (HKEY)&DAT_180053988;
  local_630[0] = (HKEY)&DAT_180053988;
  local_608[0] = (HKEY)&DAT_180053988;
  local_670[0] = (HKEY)&DAT_180053988;
  DVar14 = 0;
  local_5b0 = 0;
  local_5a8 = 0;
  local_650[1] = (HKEY)0x0;
  local_640 = 0;
  local_638 = 0;
  local_630[1] = (HKEY)0x0;
  local_620 = 0;
  local_618 = 0;
  local_608[1] = (HKEY)0x0;
  local_5f8 = 0;
  local_5f0 = 0;
  local_670[1] = (HKEY)0x0;
  local_660 = 0;
  local_658 = 0;
  local_5a0 = param_3;
  local_598 = param_4;
  LVar7 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000001,"Software",0,0xf003f,local_5c0 + 1);
  if (LVar7 != 0) {
    if (local_670[1] != (HKEY)0x0) {
      RegCloseKey(local_670[1]);
    }
    if (local_608[1] != (HKEY)0x0) {
      RegCloseKey(local_608[1]);
    }
    if (local_630[1] != (HKEY)0x0) {
      RegCloseKey(local_630[1]);
    }
    if (local_650[1] != (HKEY)0x0) {
      RegCloseKey(local_650[1]);
    }
    goto LAB_180035d17;
  }
  LVar7 = RegOpenKeyExA(*(HKEY *)((longlong)local_5c0 + (longlong)local_5c0[0][1].unused),
                        "AspenTech",0,0xf003f,
                        (PHKEY)((longlong)local_650 + (longlong)local_650[0][1].unused));
  if (LVar7 == 0) {
    LVar7 = RegOpenKeyExA(*(HKEY *)((longlong)local_650 + (longlong)local_650[0][1].unused),
                          "ASPEN PLUS",0,0xf003f,
                          (PHKEY)((longlong)local_630 + (longlong)local_630[0][1].unused));
    if (LVar7 == 0) {
      hKey = *(HKEY *)((longlong)local_630 + (longlong)local_630[0][1].unused);
      iVar8 = local_608[0][1].unused;
      lpSubKey = (LPCSTR)FUN_180024170();
      LVar7 = RegCreateKeyExA(hKey,lpSubKey,0,(LPSTR)0x0,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,
                              (PHKEY)((longlong)local_608 + (longlong)iVar8),&local_5e8);
      if (LVar7 == 0) {
        LVar7 = RegCreateKeyExA(*(HKEY *)((longlong)local_608 + (longlong)local_608[0][1].unused),
                                "Libraries",0,(LPSTR)0x0,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,
                                (PHKEY)((longlong)local_670 + (longlong)local_670[0][1].unused),
                                &local_5e8);
        if (LVar7 == 0) {
          local_678 = 4;
          local_610[0] = 0x400;
          iVar8 = RegEnumKeyExA(*(HKEY *)((longlong)local_670 + (longlong)local_670[0][1].unused),0,
                                local_674,&local_678,(LPDWORD)0x0,(LPSTR)0x0,(LPDWORD)0x0,&local_590
                               );
          while (iVar8 == 0) {
            local_678 = 4;
            DVar14 = DVar14 + 1;
            iVar8 = RegEnumKeyExA(*(HKEY *)((longlong)local_670 + (longlong)local_670[0][1].unused),
                                  DVar14,local_674,&local_678,(LPDWORD)0x0,(LPSTR)0x0,(LPDWORD)0x0,
                                  &local_590);
          }
          uVar18 = DVar14 + 1;
          lVar17 = (longlong)(int)uVar18;
          _Memory = malloc(lVar17 * 4);
          iVar6 = _UNK_18005696c;
          iVar5 = _UNK_180056968;
          iVar4 = _UNK_180056964;
          iVar8 = _DAT_180056960;
          dwIndex = 0;
          DVar14 = dwIndex;
          if ((0 < (int)uVar18) && (DVar14 = 0, 0xf < uVar18)) {
            uVar12 = uVar18 & 0x8000000f;
            if ((int)uVar12 < 0) {
              uVar12 = (uVar12 - 1 | 0xfffffff0) + 1;
            }
            piVar13 = (int *)((longlong)_Memory + 0x20);
            iVar15 = 8;
            DVar14 = dwIndex;
            do {
              iVar9 = iVar15 + -4;
              piVar13[-8] = DVar14 + iVar8;
              piVar13[-7] = DVar14 + iVar4;
              piVar13[-6] = DVar14 + iVar5;
              piVar13[-5] = DVar14 + iVar6;
              iVar1 = iVar15 + 4;
              DVar14 = DVar14 + 0x10;
              piVar13[-4] = iVar9 + iVar8;
              piVar13[-3] = iVar9 + iVar4;
              piVar13[-2] = iVar9 + iVar5;
              piVar13[-1] = iVar9 + iVar6;
              *piVar13 = iVar15 + iVar8;
              piVar13[1] = iVar15 + iVar4;
              piVar13[2] = iVar15 + iVar5;
              piVar13[3] = iVar15 + iVar6;
              piVar13[4] = iVar1 + iVar8;
              piVar13[5] = iVar1 + iVar4;
              piVar13[6] = iVar1 + iVar5;
              piVar13[7] = iVar1 + iVar6;
              piVar13 = piVar13 + 0x10;
              iVar15 = iVar15 + 0x10;
            } while ((int)DVar14 < (int)(uVar18 - uVar12));
          }
          for (lVar10 = (longlong)(int)DVar14; lVar10 < lVar17; lVar10 = lVar10 + 1) {
            *(DWORD *)((longlong)_Memory + lVar10 * 4) = DVar14;
            DVar14 = DVar14 + 1;
          }
          lpcchName = &local_678;
          local_678 = 4;
          iVar8 = RegEnumKeyExA(*(HKEY *)((longlong)local_670 + (longlong)local_670[0][1].unused),0,
                                local_674,lpcchName,(LPDWORD)0x0,(LPSTR)0x0,(LPDWORD)0x0,&local_590)
          ;
          while (iVar8 == 0) {
            local_588[0] = (HKEY)&DAT_180053988;
            local_588[1] = (HKEY)0x0;
            local_578 = 0;
            local_570 = 0;
            LVar7 = RegOpenKeyExA(*(HKEY *)((longlong)local_670 + (longlong)local_670[0][1].unused),
                                  local_674,0,0xf003f,local_588 + 1);
            if (LVar7 != 0) {
LAB_180035c93:
              free(_Memory);
              if (local_588[1] != (HKEY)0x0) {
                RegCloseKey(local_588[1]);
                local_588[1] = (HKEY)0x0;
              }
              local_578 = 0;
              if (local_670[1] != (HKEY)0x0) {
                RegCloseKey(local_670[1]);
                local_670[1] = (HKEY)0x0;
              }
              goto LAB_180035cd1;
            }
            iVar8 = atoi(local_674);
            if (iVar8 < (int)uVar18) {
              *(undefined4 *)((longlong)_Memory + (longlong)iVar8 * 4) = 0xffffffff;
            }
            local_610[0] = 0x400;
            LVar7 = RegQueryValueExA(*(HKEY *)((longlong)local_588 +
                                              (longlong)local_588[0][1].unused),"Display Name",
                                     (LPDWORD)0x0,(LPDWORD)0x0,local_458,local_610);
            if (LVar7 == 0) {
              pBVar11 = local_458;
              lVar10 = (longlong)param_1 - (longlong)pBVar11;
              do {
                BVar2 = *pBVar11;
                BVar3 = pBVar11[lVar10];
                if (BVar2 != BVar3) break;
                pBVar11 = pBVar11 + 1;
              } while (BVar3 != '\0');
              if (BVar2 == BVar3) goto LAB_180035c93;
            }
            dwIndex = dwIndex + 1;
            local_678 = 4;
            if (local_588[1] != (HKEY)0x0) {
              RegCloseKey(local_588[1]);
            }
            lpcchName = &local_678;
            iVar8 = RegEnumKeyExA(*(HKEY *)((longlong)local_670 + (longlong)local_670[0][1].unused),
                                  dwIndex,local_674,lpcchName,(LPDWORD)0x0,(LPSTR)0x0,(LPDWORD)0x0,
                                  &local_590);
          }
          if (iVar8 == 0x103) {
            uVar18 = 0;
            if (0 < lVar17) {
              lVar10 = 0;
              uVar18 = 0;
              do {
                if (*(int *)((longlong)_Memory + lVar10 * 4) != -1) break;
                uVar18 = uVar18 + 1;
                lVar10 = lVar10 + 1;
              } while (lVar10 < lVar17);
            }
            free(_Memory);
            FUN_180007de0(local_674,&DAT_1800533ec,(ulonglong)uVar18,lpcchName);
            local_5e0[1] = (HKEY)0x0;
            local_5e0[0] = (HKEY)&DAT_180053988;
            local_5d0 = 0;
            local_5c8 = 0;
            LVar7 = RegCreateKeyExA(*(HKEY *)((longlong)local_670 + (longlong)local_670[0][1].unused
                                             ),local_674,0,(LPSTR)0x0,0,0xf003f,
                                    (LPSECURITY_ATTRIBUTES)0x0,local_5e0 + 1,&local_5e8);
            if (LVar7 == 0) {
              strncpy((char *)local_458,param_1,0x3ff);
              local_59 = 0;
              lVar17 = -1;
              do {
                lVar16 = lVar17 + 1;
                lVar10 = lVar17 + 1;
                lVar17 = lVar16;
              } while (local_458[lVar10] != '\0');
              local_610[0] = (int)lVar16 + 1;
              RegSetValueExA(*(HKEY *)((longlong)local_5e0 + (longlong)local_5e0[0][1].unused),
                             "Display Name",0,1,local_458,local_610[0]);
              strncpy((char *)local_568,param_2,0x104);
              local_464 = 0;
              lVar17 = -1;
              do {
                lVar16 = lVar17 + 1;
                lVar10 = lVar17 + 1;
                lVar17 = lVar16;
              } while (local_568[lVar10] != '\0');
              RegSetValueExA(*(HKEY *)((longlong)local_5e0 + (longlong)local_5e0[0][1].unused),
                             "Path",0,1,local_568,(int)lVar16 + 1);
              local_59c = local_5a0;
              RegSetValueExA(*(HKEY *)((longlong)local_5e0 + (longlong)local_5e0[0][1].unused),
                             "Position",0,4,(BYTE *)&local_59c,4);
              local_5e4 = local_598;
              RegSetValueExA(*(HKEY *)((longlong)local_5e0 + (longlong)local_5e0[0][1].unused),
                             "Active",0,4,(BYTE *)&local_5e4,4);
              if (local_5e0[1] != (HKEY)0x0) {
                RegCloseKey(local_5e0[1]);
                local_5e0[1] = (HKEY)0x0;
              }
              local_5d0 = 0;
              if (local_670[1] != (HKEY)0x0) {
                RegCloseKey(local_670[1]);
                local_670[1] = (HKEY)0x0;
              }
              local_660 = 0;
              if (local_608[1] != (HKEY)0x0) {
                RegCloseKey(local_608[1]);
                local_608[1] = (HKEY)0x0;
              }
              local_5f8 = 0;
              if (local_630[1] != (HKEY)0x0) {
                RegCloseKey(local_630[1]);
                local_630[1] = (HKEY)0x0;
              }
              local_620 = 0;
              if (local_650[1] != (HKEY)0x0) {
                RegCloseKey(local_650[1]);
                local_650[1] = (HKEY)0x0;
              }
              local_640 = 0;
              if (local_5c0[1] != (HKEY)0x0) {
                RegCloseKey(local_5c0[1]);
              }
              return 1;
            }
            if (local_5e0[1] != (HKEY)0x0) {
              RegCloseKey(local_5e0[1]);
              local_5e0[1] = (HKEY)0x0;
            }
            local_5d0 = 0;
            if (local_670[1] != (HKEY)0x0) {
              RegCloseKey(local_670[1]);
              local_670[1] = (HKEY)0x0;
            }
            local_660 = 0;
            if (local_608[1] != (HKEY)0x0) {
              RegCloseKey(local_608[1]);
              local_608[1] = (HKEY)0x0;
            }
            local_5f8 = 0;
            if (local_630[1] != (HKEY)0x0) {
              RegCloseKey(local_630[1]);
              local_630[1] = (HKEY)0x0;
            }
            local_620 = 0;
            if (local_650[1] != (HKEY)0x0) {
              RegCloseKey(local_650[1]);
              local_650[1] = (HKEY)0x0;
            }
            local_640 = 0;
          }
          else {
            free(_Memory);
            if (local_670[1] != (HKEY)0x0) {
              RegCloseKey(local_670[1]);
              local_670[1] = (HKEY)0x0;
            }
LAB_180035cd1:
            local_660 = 0;
            if (local_608[1] != (HKEY)0x0) {
              RegCloseKey(local_608[1]);
              local_608[1] = (HKEY)0x0;
            }
            local_5f8 = 0;
            if (local_630[1] != (HKEY)0x0) {
              RegCloseKey(local_630[1]);
              local_630[1] = (HKEY)0x0;
            }
            local_620 = 0;
            if (local_650[1] != (HKEY)0x0) {
              RegCloseKey(local_650[1]);
              local_650[1] = (HKEY)0x0;
            }
            local_640 = 0;
          }
          goto LAB_180035d17;
        }
        if (local_670[1] != (HKEY)0x0) {
          RegCloseKey(local_670[1]);
          local_670[1] = (HKEY)0x0;
        }
        local_660 = 0;
        if (local_608[1] != (HKEY)0x0) {
          RegCloseKey(local_608[1]);
          local_608[1] = (HKEY)0x0;
        }
        local_5f8 = 0;
        if (local_630[1] != (HKEY)0x0) {
          RegCloseKey(local_630[1]);
          local_630[1] = (HKEY)0x0;
        }
        local_620 = 0;
        if (local_650[1] != (HKEY)0x0) {
          RegCloseKey(local_650[1]);
          local_650[1] = (HKEY)0x0;
          local_640 = 0;
          goto LAB_180035d17;
        }
      }
      else {
        if (local_670[1] != (HKEY)0x0) {
          RegCloseKey(local_670[1]);
        }
        if (local_608[1] != (HKEY)0x0) {
          RegCloseKey(local_608[1]);
          local_608[1] = (HKEY)0x0;
        }
        local_5f8 = 0;
        if (local_630[1] != (HKEY)0x0) {
          RegCloseKey(local_630[1]);
          local_630[1] = (HKEY)0x0;
        }
        local_620 = 0;
        if (local_650[1] != (HKEY)0x0) {
          RegCloseKey(local_650[1]);
          local_650[1] = (HKEY)0x0;
          local_640 = 0;
          goto LAB_180035d17;
        }
      }
    }
    else {
      if (local_670[1] != (HKEY)0x0) {
        RegCloseKey(local_670[1]);
      }
      if (local_608[1] != (HKEY)0x0) {
        RegCloseKey(local_608[1]);
      }
      if (local_630[1] != (HKEY)0x0) {
        RegCloseKey(local_630[1]);
        local_630[1] = (HKEY)0x0;
      }
      local_620 = 0;
      if (local_650[1] != (HKEY)0x0) {
        RegCloseKey(local_650[1]);
        local_650[1] = (HKEY)0x0;
        local_640 = 0;
        goto LAB_180035d17;
      }
    }
  }
  else {
    if (local_670[1] != (HKEY)0x0) {
      RegCloseKey(local_670[1]);
    }
    if (local_608[1] != (HKEY)0x0) {
      RegCloseKey(local_608[1]);
    }
    if (local_630[1] != (HKEY)0x0) {
      RegCloseKey(local_630[1]);
    }
    if (local_650[1] != (HKEY)0x0) {
      RegCloseKey(local_650[1]);
      local_650[1] = (HKEY)0x0;
    }
  }
  local_640 = 0;
LAB_180035d17:
  if (local_5c0[1] != (HKEY)0x0) {
    RegCloseKey(local_5c0[1]);
  }
  return 0;
}

/* ---- FUNC 00036030 FUN_180036030 (15 bytes) ---- */

void FUN_180036030(int param_1,uint param_2)

{
  int iVar1;
  HKEY hKey;
  LSTATUS LVar2;
  LPCSTR lpSubKey;
  uint local_res18 [2];
  DWORD local_res20 [2];
  HKEY local_c8 [2];
  undefined4 local_b8;
  undefined8 local_b0;
  HKEY local_a8 [2];
  undefined4 local_98;
  undefined8 local_90;
  HKEY local_88 [2];
  undefined4 local_78;
  undefined8 local_70;
  HKEY local_68 [2];
  undefined4 local_58;
  undefined8 local_50;
  HKEY local_48 [2];
  undefined4 local_38;
  undefined8 local_30;
  
  local_48[0] = (HKEY)&DAT_180053988;
  local_68[0] = (HKEY)&DAT_180053988;
  local_88[0] = (HKEY)&DAT_180053988;
  local_a8[0] = (HKEY)&DAT_180053988;
  local_c8[0] = (HKEY)&DAT_180053988;
  local_48[1] = (HKEY)0x0;
  local_38 = 0;
  local_30 = 0;
  local_68[1] = (HKEY)0x0;
  local_58 = 0;
  local_50 = 0;
  local_88[1] = (HKEY)0x0;
  local_78 = 0;
  local_70 = 0;
  local_a8[1] = (HKEY)0x0;
  local_98 = 0;
  local_90 = 0;
  local_c8[1] = (HKEY)0x0;
  local_b8 = 0;
  local_b0 = 0;
  LVar2 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000001,"Software",0,0xf003f,local_48 + 1);
  if (LVar2 == 0) {
    LVar2 = RegOpenKeyExA(*(HKEY *)((longlong)local_48 + (longlong)local_48[0][1].unused),
                          "AspenTech",0,0xf003f,
                          (PHKEY)((longlong)local_68 + (longlong)local_68[0][1].unused));
    if (LVar2 == 0) {
      LVar2 = RegOpenKeyExA(*(HKEY *)((longlong)local_68 + (longlong)local_68[0][1].unused),
                            "ASPEN PLUS",0,0xf003f,
                            (PHKEY)((longlong)local_88 + (longlong)local_88[0][1].unused));
      if (LVar2 == 0) {
        hKey = *(HKEY *)((longlong)local_88 + (longlong)local_88[0][1].unused);
        iVar1 = local_a8[0][1].unused;
        lpSubKey = (LPCSTR)FUN_180024170();
        LVar2 = RegCreateKeyExA(hKey,lpSubKey,0,(LPSTR)0x0,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,
                                (PHKEY)((longlong)local_a8 + (longlong)iVar1),local_res20);
        if (LVar2 == 0) {
          LVar2 = RegCreateKeyExA(*(HKEY *)((longlong)local_a8 + (longlong)local_a8[0][1].unused),
                                  "Libraries",0,(LPSTR)0x0,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,
                                  (PHKEY)((longlong)local_c8 + (longlong)local_c8[0][1].unused),
                                  local_res20);
          if (LVar2 == 0) {
            local_res18[0] = (uint)(param_1 != 0);
            RegSetValueExA(*(HKEY *)((longlong)local_c8 + (longlong)local_c8[0][1].unused),
                           "UseACMCatalog",0,4,(BYTE *)local_res18,4);
            local_res18[0] = param_2;
            RegSetValueExA(*(HKEY *)((longlong)local_c8 + (longlong)local_c8[0][1].unused),
                           "ACMCatalogPosition",0,4,(BYTE *)local_res18,4);
          }
        }
      }
    }
  }
  if (local_c8[1] != (HKEY)0x0) {
    RegCloseKey(local_c8[1]);
    local_c8[1] = (HKEY)0x0;
  }
  local_b8 = 0;
  if (local_a8[1] != (HKEY)0x0) {
    RegCloseKey(local_a8[1]);
    local_a8[1] = (HKEY)0x0;
  }
  local_98 = 0;
  if (local_88[1] != (HKEY)0x0) {
    RegCloseKey(local_88[1]);
    local_88[1] = (HKEY)0x0;
  }
  local_78 = 0;
  if (local_68[1] != (HKEY)0x0) {
    RegCloseKey(local_68[1]);
    local_68[1] = (HKEY)0x0;
  }
  local_58 = 0;
  if (local_48[1] != (HKEY)0x0) {
    RegCloseKey(local_48[1]);
  }
  return;
}

/* ---- FUNC 0003603F FUN_18003603f (289 bytes) ---- */

void FUN_18003603f(int param_1,undefined4 param_2)

{
  int iVar1;
  HKEY hKey;
  LSTATUS LVar2;
  longlong in_RAX;
  LPCSTR lpSubKey;
  longlong unaff_RBP;
  undefined8 unaff_RSI;
  undefined8 unaff_R14;
  undefined8 unaff_R15;
  undefined *puStack0000000000000050;
  HKEY pHStack0000000000000058;
  undefined4 uStack0000000000000060;
  undefined8 uStack0000000000000068;
  undefined *puStack0000000000000070;
  HKEY pHStack0000000000000078;
  
  *(undefined8 *)(in_RAX + -0x10) = unaff_RSI;
  *(undefined8 *)(in_RAX + -0x20) = unaff_R14;
  *(undefined8 *)(in_RAX + -0x28) = unaff_R15;
  *(undefined **)(unaff_RBP + -0x30) = &DAT_180053988;
  *(undefined **)(unaff_RBP + -0x50) = &DAT_180053988;
  *(undefined **)(unaff_RBP + -0x70) = &DAT_180053988;
  puStack0000000000000070 = &DAT_180053988;
  puStack0000000000000050 = &DAT_180053988;
  *(undefined8 *)(unaff_RBP + -0x28) = 0;
  *(undefined4 *)(unaff_RBP + -0x20) = 0;
  *(undefined8 *)(unaff_RBP + -0x18) = 0;
  *(undefined8 *)(unaff_RBP + -0x48) = 0;
  *(undefined4 *)(unaff_RBP + -0x40) = 0;
  *(undefined8 *)(unaff_RBP + -0x38) = 0;
  *(undefined8 *)(unaff_RBP + -0x68) = 0;
  *(undefined4 *)(unaff_RBP + -0x60) = 0;
  *(undefined8 *)(unaff_RBP + -0x58) = 0;
  pHStack0000000000000078 = (HKEY)0x0;
  *(undefined4 *)(unaff_RBP + -0x80) = 0;
  *(undefined8 *)(unaff_RBP + -0x78) = 0;
  pHStack0000000000000058 = (HKEY)0x0;
  uStack0000000000000060 = 0;
  uStack0000000000000068 = 0;
  LVar2 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000001,"Software",0,0xf003f,(PHKEY)(unaff_RBP + -0x28))
  ;
  if (LVar2 == 0) {
    LVar2 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + -0x30 +
                                   (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x30) + 4)),
                          "AspenTech",0,0xf003f,
                          (PHKEY)(unaff_RBP + -0x50 +
                                 (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x50) + 4)));
    if (LVar2 == 0) {
      LVar2 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + -0x50 +
                                     (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x50) + 4)),
                            "ASPEN PLUS",0,0xf003f,
                            (PHKEY)(unaff_RBP + -0x70 +
                                   (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x70) + 4)));
      if (LVar2 == 0) {
        hKey = *(HKEY *)(unaff_RBP + -0x70 +
                        (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x70) + 4));
        iVar1 = *(int *)(puStack0000000000000070 + 4);
        lpSubKey = (LPCSTR)FUN_180024170();
        LVar2 = RegCreateKeyExA(hKey,lpSubKey,0,(LPSTR)0x0,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,
                                (PHKEY)((longlong)&stack0x00000070 + (longlong)iVar1),
                                (LPDWORD)(unaff_RBP + 0x38));
        if (LVar2 == 0) {
          LVar2 = RegCreateKeyExA(*(HKEY *)((longlong)&stack0x00000070 +
                                           (longlong)*(int *)(puStack0000000000000070 + 4)),
                                  "Libraries",0,(LPSTR)0x0,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,
                                  (PHKEY)((longlong)&stack0x00000050 +
                                         (longlong)*(int *)(puStack0000000000000050 + 4)),
                                  (LPDWORD)(unaff_RBP + 0x38));
          if (LVar2 == 0) {
            *(uint *)(unaff_RBP + 0x30) = (uint)(param_1 != 0);
            RegSetValueExA(*(HKEY *)((longlong)&stack0x00000050 +
                                    (longlong)*(int *)(puStack0000000000000050 + 4)),"UseACMCatalog"
                           ,0,4,(BYTE *)(unaff_RBP + 0x30),4);
            *(undefined4 *)(unaff_RBP + 0x30) = param_2;
            RegSetValueExA(*(HKEY *)((longlong)&stack0x00000050 +
                                    (longlong)*(int *)(puStack0000000000000050 + 4)),
                           "ACMCatalogPosition",0,4,(BYTE *)(unaff_RBP + 0x30),4);
          }
        }
      }
    }
  }
  if (pHStack0000000000000058 != (HKEY)0x0) {
    RegCloseKey(pHStack0000000000000058);
    pHStack0000000000000058 = (HKEY)0x0;
  }
  uStack0000000000000060 = 0;
  if (pHStack0000000000000078 != (HKEY)0x0) {
    RegCloseKey(pHStack0000000000000078);
    pHStack0000000000000078 = (HKEY)0x0;
  }
  *(undefined4 *)(unaff_RBP + -0x80) = 0;
  if (*(HKEY *)(unaff_RBP + -0x68) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x68));
    *(undefined8 *)(unaff_RBP + -0x68) = 0;
  }
  *(undefined4 *)(unaff_RBP + -0x60) = 0;
  if (*(HKEY *)(unaff_RBP + -0x48) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x48));
    *(undefined8 *)(unaff_RBP + -0x48) = 0;
  }
  *(undefined4 *)(unaff_RBP + -0x40) = 0;
  if (*(HKEY *)(unaff_RBP + -0x28) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x28));
  }
  return;
}

/* ---- FUNC 00036160 FUN_180036160 (121 bytes) ---- */

void FUN_180036160(void)

{
  int iVar1;
  HKEY hKey;
  LSTATUS LVar2;
  longlong in_RAX;
  LPCSTR lpSubKey;
  longlong unaff_RBP;
  undefined4 unaff_ESI;
  int unaff_R14D;
  DWORD dwOptions;
  LPSECURITY_ATTRIBUTES unaff_R15;
  longlong in_stack_00000050;
  HKEY in_stack_00000058;
  longlong in_stack_00000070;
  HKEY in_stack_00000078;
  
  hKey = *(HKEY *)(unaff_RBP + -0x70 + (longlong)*(int *)(in_RAX + 4));
  iVar1 = *(int *)(in_stack_00000070 + 4);
  lpSubKey = (LPCSTR)FUN_180024170();
  dwOptions = (DWORD)unaff_R15;
  LVar2 = RegCreateKeyExA(hKey,lpSubKey,0,(LPSTR)0x0,dwOptions,0xf003f,unaff_R15,
                          (PHKEY)((longlong)&stack0x00000070 + (longlong)iVar1),
                          (LPDWORD)(unaff_RBP + 0x38));
  if (LVar2 == 0) {
    LVar2 = RegCreateKeyExA(*(HKEY *)((longlong)&stack0x00000070 +
                                     (longlong)*(int *)(in_stack_00000070 + 4)),"Libraries",0,
                            (LPSTR)0x0,dwOptions,0xf003f,unaff_R15,
                            (PHKEY)((longlong)&stack0x00000050 +
                                   (longlong)*(int *)(in_stack_00000050 + 4)),
                            (LPDWORD)(unaff_RBP + 0x38));
    if (LVar2 == 0) {
      *(int *)(unaff_RBP + 0x30) = (int)CONCAT71((int7)((ulonglong)unaff_R15 >> 8),unaff_R14D != 0);
      RegSetValueExA(*(HKEY *)((longlong)&stack0x00000050 +
                              (longlong)*(int *)(in_stack_00000050 + 4)),"UseACMCatalog",0,
                     dwOptions + 4,(BYTE *)(unaff_RBP + 0x30),4);
      *(undefined4 *)(unaff_RBP + 0x30) = unaff_ESI;
      RegSetValueExA(*(HKEY *)((longlong)&stack0x00000050 +
                              (longlong)*(int *)(in_stack_00000050 + 4)),"ACMCatalogPosition",0,
                     dwOptions + 4,(BYTE *)(unaff_RBP + 0x30),4);
    }
  }
  if (in_stack_00000058 != (HKEY)0x0) {
    RegCloseKey(in_stack_00000058);
  }
  if (in_stack_00000078 != (HKEY)0x0) {
    RegCloseKey(in_stack_00000078);
  }
  *(DWORD *)(unaff_RBP + -0x80) = dwOptions;
  if (*(HKEY *)(unaff_RBP + -0x68) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x68));
    *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x68) = unaff_R15;
  }
  *(DWORD *)(unaff_RBP + -0x60) = dwOptions;
  if (*(HKEY *)(unaff_RBP + -0x48) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x48));
    *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x48) = unaff_R15;
  }
  *(DWORD *)(unaff_RBP + -0x40) = dwOptions;
  if (*(HKEY *)(unaff_RBP + -0x28) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x28));
  }
  return;
}

/* ---- FUNC 000361D9 FUN_1800361d9 (229 bytes) ---- */

void FUN_1800361d9(void)

{
  LSTATUS LVar1;
  longlong unaff_RBP;
  undefined4 unaff_ESI;
  int unaff_R14D;
  DWORD dwOptions;
  LPSECURITY_ATTRIBUTES unaff_R15;
  longlong in_stack_00000050;
  HKEY in_stack_00000058;
  longlong in_stack_00000070;
  HKEY in_stack_00000078;
  
  dwOptions = (DWORD)unaff_R15;
  LVar1 = RegCreateKeyExA(*(HKEY *)((longlong)&stack0x00000070 +
                                   (longlong)*(int *)(in_stack_00000070 + 4)),"Libraries",0,
                          (LPSTR)0x0,dwOptions,0xf003f,unaff_R15,
                          (PHKEY)((longlong)&stack0x00000050 +
                                 (longlong)*(int *)(in_stack_00000050 + 4)),
                          (LPDWORD)(unaff_RBP + 0x38));
  if (LVar1 == 0) {
    *(int *)(unaff_RBP + 0x30) = (int)CONCAT71((int7)((ulonglong)unaff_R15 >> 8),unaff_R14D != 0);
    RegSetValueExA(*(HKEY *)((longlong)&stack0x00000050 + (longlong)*(int *)(in_stack_00000050 + 4))
                   ,"UseACMCatalog",0,dwOptions + 4,(BYTE *)(unaff_RBP + 0x30),4);
    *(undefined4 *)(unaff_RBP + 0x30) = unaff_ESI;
    RegSetValueExA(*(HKEY *)((longlong)&stack0x00000050 + (longlong)*(int *)(in_stack_00000050 + 4))
                   ,"ACMCatalogPosition",0,dwOptions + 4,(BYTE *)(unaff_RBP + 0x30),4);
  }
  if (in_stack_00000058 != (HKEY)0x0) {
    RegCloseKey(in_stack_00000058);
  }
  if (in_stack_00000078 != (HKEY)0x0) {
    RegCloseKey(in_stack_00000078);
  }
  *(DWORD *)(unaff_RBP + -0x80) = dwOptions;
  if (*(HKEY *)(unaff_RBP + -0x68) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x68));
    *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x68) = unaff_R15;
  }
  *(DWORD *)(unaff_RBP + -0x60) = dwOptions;
  if (*(HKEY *)(unaff_RBP + -0x48) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x48));
    *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x48) = unaff_R15;
  }
  *(DWORD *)(unaff_RBP + -0x40) = dwOptions;
  if (*(HKEY *)(unaff_RBP + -0x28) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x28));
  }
  return;
}

/* ---- FUNC 000362BE FUN_1800362be (104 bytes) ---- */

void FUN_1800362be(HKEY param_1)

{
  longlong unaff_RBP;
  undefined4 uVar1;
  undefined8 unaff_R15;
  HKEY in_stack_00000078;
  
  RegCloseKey(param_1);
  uVar1 = (undefined4)unaff_R15;
  if (in_stack_00000078 != (HKEY)0x0) {
    RegCloseKey(in_stack_00000078);
  }
  *(undefined4 *)(unaff_RBP + -0x80) = uVar1;
  if (*(HKEY *)(unaff_RBP + -0x68) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x68));
    *(undefined8 *)(unaff_RBP + -0x68) = unaff_R15;
  }
  *(undefined4 *)(unaff_RBP + -0x60) = uVar1;
  if (*(HKEY *)(unaff_RBP + -0x48) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x48));
    *(undefined8 *)(unaff_RBP + -0x48) = unaff_R15;
  }
  *(undefined4 *)(unaff_RBP + -0x40) = uVar1;
  if (*(HKEY *)(unaff_RBP + -0x28) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x28));
  }
  return;
}

/* ---- FUNC 00036326 FUN_180036326 (15 bytes) ---- */

void FUN_180036326(HKEY param_1)

{
  RegCloseKey(param_1);
  return;
}

/* ---- FUNC 00036340 APModLibSetBuiltin (15 bytes) ---- */

void APModLibSetBuiltin(int param_1,uint param_2)

{
  int iVar1;
  HKEY hKey;
  LSTATUS LVar2;
  LPCSTR lpSubKey;
  uint local_res18 [2];
  DWORD local_res20 [2];
  HKEY local_c8 [2];
  undefined4 local_b8;
  undefined8 local_b0;
  HKEY local_a8 [2];
  undefined4 local_98;
  undefined8 local_90;
  HKEY local_88 [2];
  undefined4 local_78;
  undefined8 local_70;
  HKEY local_68 [2];
  undefined4 local_58;
  undefined8 local_50;
  HKEY local_48 [2];
  undefined4 local_38;
  undefined8 local_30;
  
                    /* 0x36340  270  APModLibSetBuiltin */
  local_48[0] = (HKEY)&DAT_180053988;
  local_68[0] = (HKEY)&DAT_180053988;
  local_88[0] = (HKEY)&DAT_180053988;
  local_a8[0] = (HKEY)&DAT_180053988;
  local_c8[0] = (HKEY)&DAT_180053988;
  local_48[1] = (HKEY)0x0;
  local_38 = 0;
  local_30 = 0;
  local_68[1] = (HKEY)0x0;
  local_58 = 0;
  local_50 = 0;
  local_88[1] = (HKEY)0x0;
  local_78 = 0;
  local_70 = 0;
  local_a8[1] = (HKEY)0x0;
  local_98 = 0;
  local_90 = 0;
  local_c8[1] = (HKEY)0x0;
  local_b8 = 0;
  local_b0 = 0;
  LVar2 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000001,"Software",0,0xf003f,local_48 + 1);
  if (LVar2 == 0) {
    LVar2 = RegOpenKeyExA(*(HKEY *)((longlong)local_48 + (longlong)local_48[0][1].unused),
                          "AspenTech",0,0xf003f,
                          (PHKEY)((longlong)local_68 + (longlong)local_68[0][1].unused));
    if (LVar2 == 0) {
      LVar2 = RegOpenKeyExA(*(HKEY *)((longlong)local_68 + (longlong)local_68[0][1].unused),
                            "ASPEN PLUS",0,0xf003f,
                            (PHKEY)((longlong)local_88 + (longlong)local_88[0][1].unused));
      if (LVar2 == 0) {
        hKey = *(HKEY *)((longlong)local_88 + (longlong)local_88[0][1].unused);
        iVar1 = local_a8[0][1].unused;
        lpSubKey = (LPCSTR)FUN_180024170();
        LVar2 = RegCreateKeyExA(hKey,lpSubKey,0,(LPSTR)0x0,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,
                                (PHKEY)((longlong)local_a8 + (longlong)iVar1),local_res20);
        if (LVar2 == 0) {
          LVar2 = RegCreateKeyExA(*(HKEY *)((longlong)local_a8 + (longlong)local_a8[0][1].unused),
                                  "Libraries",0,(LPSTR)0x0,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,
                                  (PHKEY)((longlong)local_c8 + (longlong)local_c8[0][1].unused),
                                  local_res20);
          if (LVar2 == 0) {
            local_res18[0] = (uint)(param_1 != 0);
            RegSetValueExA(*(HKEY *)((longlong)local_c8 + (longlong)local_c8[0][1].unused),
                           "UseBuiltin",0,4,(BYTE *)local_res18,4);
            local_res18[0] = param_2;
            RegSetValueExA(*(HKEY *)((longlong)local_c8 + (longlong)local_c8[0][1].unused),
                           "BuiltinPosition",0,4,(BYTE *)local_res18,4);
          }
        }
      }
    }
  }
  if (local_c8[1] != (HKEY)0x0) {
    RegCloseKey(local_c8[1]);
    local_c8[1] = (HKEY)0x0;
  }
  local_b8 = 0;
  if (local_a8[1] != (HKEY)0x0) {
    RegCloseKey(local_a8[1]);
    local_a8[1] = (HKEY)0x0;
  }
  local_98 = 0;
  if (local_88[1] != (HKEY)0x0) {
    RegCloseKey(local_88[1]);
    local_88[1] = (HKEY)0x0;
  }
  local_78 = 0;
  if (local_68[1] != (HKEY)0x0) {
    RegCloseKey(local_68[1]);
    local_68[1] = (HKEY)0x0;
  }
  local_58 = 0;
  if (local_48[1] != (HKEY)0x0) {
    RegCloseKey(local_48[1]);
  }
  return;
}

/* ---- FUNC 0003634F FUN_18003634f (289 bytes) ---- */

void FUN_18003634f(int param_1,undefined4 param_2)

{
  int iVar1;
  HKEY hKey;
  LSTATUS LVar2;
  longlong in_RAX;
  LPCSTR lpSubKey;
  longlong unaff_RBP;
  undefined8 unaff_RSI;
  undefined8 unaff_R14;
  undefined8 unaff_R15;
  undefined *puStack0000000000000050;
  HKEY pHStack0000000000000058;
  undefined4 uStack0000000000000060;
  undefined8 uStack0000000000000068;
  undefined *puStack0000000000000070;
  HKEY pHStack0000000000000078;
  
  *(undefined8 *)(in_RAX + -0x10) = unaff_RSI;
  *(undefined8 *)(in_RAX + -0x20) = unaff_R14;
  *(undefined8 *)(in_RAX + -0x28) = unaff_R15;
  *(undefined **)(unaff_RBP + -0x30) = &DAT_180053988;
  *(undefined **)(unaff_RBP + -0x50) = &DAT_180053988;
  *(undefined **)(unaff_RBP + -0x70) = &DAT_180053988;
  puStack0000000000000070 = &DAT_180053988;
  puStack0000000000000050 = &DAT_180053988;
  *(undefined8 *)(unaff_RBP + -0x28) = 0;
  *(undefined4 *)(unaff_RBP + -0x20) = 0;
  *(undefined8 *)(unaff_RBP + -0x18) = 0;
  *(undefined8 *)(unaff_RBP + -0x48) = 0;
  *(undefined4 *)(unaff_RBP + -0x40) = 0;
  *(undefined8 *)(unaff_RBP + -0x38) = 0;
  *(undefined8 *)(unaff_RBP + -0x68) = 0;
  *(undefined4 *)(unaff_RBP + -0x60) = 0;
  *(undefined8 *)(unaff_RBP + -0x58) = 0;
  pHStack0000000000000078 = (HKEY)0x0;
  *(undefined4 *)(unaff_RBP + -0x80) = 0;
  *(undefined8 *)(unaff_RBP + -0x78) = 0;
  pHStack0000000000000058 = (HKEY)0x0;
  uStack0000000000000060 = 0;
  uStack0000000000000068 = 0;
  LVar2 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000001,"Software",0,0xf003f,(PHKEY)(unaff_RBP + -0x28))
  ;
  if (LVar2 == 0) {
    LVar2 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + -0x30 +
                                   (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x30) + 4)),
                          "AspenTech",0,0xf003f,
                          (PHKEY)(unaff_RBP + -0x50 +
                                 (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x50) + 4)));
    if (LVar2 == 0) {
      LVar2 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + -0x50 +
                                     (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x50) + 4)),
                            "ASPEN PLUS",0,0xf003f,
                            (PHKEY)(unaff_RBP + -0x70 +
                                   (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x70) + 4)));
      if (LVar2 == 0) {
        hKey = *(HKEY *)(unaff_RBP + -0x70 +
                        (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x70) + 4));
        iVar1 = *(int *)(puStack0000000000000070 + 4);
        lpSubKey = (LPCSTR)FUN_180024170();
        LVar2 = RegCreateKeyExA(hKey,lpSubKey,0,(LPSTR)0x0,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,
                                (PHKEY)((longlong)&stack0x00000070 + (longlong)iVar1),
                                (LPDWORD)(unaff_RBP + 0x38));
        if (LVar2 == 0) {
          LVar2 = RegCreateKeyExA(*(HKEY *)((longlong)&stack0x00000070 +
                                           (longlong)*(int *)(puStack0000000000000070 + 4)),
                                  "Libraries",0,(LPSTR)0x0,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,
                                  (PHKEY)((longlong)&stack0x00000050 +
                                         (longlong)*(int *)(puStack0000000000000050 + 4)),
                                  (LPDWORD)(unaff_RBP + 0x38));
          if (LVar2 == 0) {
            *(uint *)(unaff_RBP + 0x30) = (uint)(param_1 != 0);
            RegSetValueExA(*(HKEY *)((longlong)&stack0x00000050 +
                                    (longlong)*(int *)(puStack0000000000000050 + 4)),"UseBuiltin",0,
                           4,(BYTE *)(unaff_RBP + 0x30),4);
            *(undefined4 *)(unaff_RBP + 0x30) = param_2;
            RegSetValueExA(*(HKEY *)((longlong)&stack0x00000050 +
                                    (longlong)*(int *)(puStack0000000000000050 + 4)),
                           "BuiltinPosition",0,4,(BYTE *)(unaff_RBP + 0x30),4);
          }
        }
      }
    }
  }
  if (pHStack0000000000000058 != (HKEY)0x0) {
    RegCloseKey(pHStack0000000000000058);
    pHStack0000000000000058 = (HKEY)0x0;
  }
  uStack0000000000000060 = 0;
  if (pHStack0000000000000078 != (HKEY)0x0) {
    RegCloseKey(pHStack0000000000000078);
    pHStack0000000000000078 = (HKEY)0x0;
  }
  *(undefined4 *)(unaff_RBP + -0x80) = 0;
  if (*(HKEY *)(unaff_RBP + -0x68) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x68));
    *(undefined8 *)(unaff_RBP + -0x68) = 0;
  }
  *(undefined4 *)(unaff_RBP + -0x60) = 0;
  if (*(HKEY *)(unaff_RBP + -0x48) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x48));
    *(undefined8 *)(unaff_RBP + -0x48) = 0;
  }
  *(undefined4 *)(unaff_RBP + -0x40) = 0;
  if (*(HKEY *)(unaff_RBP + -0x28) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x28));
  }
  return;
}

/* ---- FUNC 00036470 FUN_180036470 (121 bytes) ---- */

void FUN_180036470(void)

{
  int iVar1;
  HKEY hKey;
  LSTATUS LVar2;
  longlong in_RAX;
  LPCSTR lpSubKey;
  longlong unaff_RBP;
  undefined4 unaff_ESI;
  int unaff_R14D;
  DWORD dwOptions;
  LPSECURITY_ATTRIBUTES unaff_R15;
  longlong in_stack_00000050;
  HKEY in_stack_00000058;
  longlong in_stack_00000070;
  HKEY in_stack_00000078;
  
  hKey = *(HKEY *)(unaff_RBP + -0x70 + (longlong)*(int *)(in_RAX + 4));
  iVar1 = *(int *)(in_stack_00000070 + 4);
  lpSubKey = (LPCSTR)FUN_180024170();
  dwOptions = (DWORD)unaff_R15;
  LVar2 = RegCreateKeyExA(hKey,lpSubKey,0,(LPSTR)0x0,dwOptions,0xf003f,unaff_R15,
                          (PHKEY)((longlong)&stack0x00000070 + (longlong)iVar1),
                          (LPDWORD)(unaff_RBP + 0x38));
  if (LVar2 == 0) {
    LVar2 = RegCreateKeyExA(*(HKEY *)((longlong)&stack0x00000070 +
                                     (longlong)*(int *)(in_stack_00000070 + 4)),"Libraries",0,
                            (LPSTR)0x0,dwOptions,0xf003f,unaff_R15,
                            (PHKEY)((longlong)&stack0x00000050 +
                                   (longlong)*(int *)(in_stack_00000050 + 4)),
                            (LPDWORD)(unaff_RBP + 0x38));
    if (LVar2 == 0) {
      *(int *)(unaff_RBP + 0x30) = (int)CONCAT71((int7)((ulonglong)unaff_R15 >> 8),unaff_R14D != 0);
      RegSetValueExA(*(HKEY *)((longlong)&stack0x00000050 +
                              (longlong)*(int *)(in_stack_00000050 + 4)),"UseBuiltin",0,
                     dwOptions + 4,(BYTE *)(unaff_RBP + 0x30),4);
      *(undefined4 *)(unaff_RBP + 0x30) = unaff_ESI;
      RegSetValueExA(*(HKEY *)((longlong)&stack0x00000050 +
                              (longlong)*(int *)(in_stack_00000050 + 4)),"BuiltinPosition",0,
                     dwOptions + 4,(BYTE *)(unaff_RBP + 0x30),4);
    }
  }
  if (in_stack_00000058 != (HKEY)0x0) {
    RegCloseKey(in_stack_00000058);
  }
  if (in_stack_00000078 != (HKEY)0x0) {
    RegCloseKey(in_stack_00000078);
  }
  *(DWORD *)(unaff_RBP + -0x80) = dwOptions;
  if (*(HKEY *)(unaff_RBP + -0x68) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x68));
    *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x68) = unaff_R15;
  }
  *(DWORD *)(unaff_RBP + -0x60) = dwOptions;
  if (*(HKEY *)(unaff_RBP + -0x48) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x48));
    *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x48) = unaff_R15;
  }
  *(DWORD *)(unaff_RBP + -0x40) = dwOptions;
  if (*(HKEY *)(unaff_RBP + -0x28) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x28));
  }
  return;
}

/* ---- FUNC 000364E9 FUN_1800364e9 (229 bytes) ---- */

void FUN_1800364e9(void)

{
  LSTATUS LVar1;
  longlong unaff_RBP;
  undefined4 unaff_ESI;
  int unaff_R14D;
  DWORD dwOptions;
  LPSECURITY_ATTRIBUTES unaff_R15;
  longlong in_stack_00000050;
  HKEY in_stack_00000058;
  longlong in_stack_00000070;
  HKEY in_stack_00000078;
  
  dwOptions = (DWORD)unaff_R15;
  LVar1 = RegCreateKeyExA(*(HKEY *)((longlong)&stack0x00000070 +
                                   (longlong)*(int *)(in_stack_00000070 + 4)),"Libraries",0,
                          (LPSTR)0x0,dwOptions,0xf003f,unaff_R15,
                          (PHKEY)((longlong)&stack0x00000050 +
                                 (longlong)*(int *)(in_stack_00000050 + 4)),
                          (LPDWORD)(unaff_RBP + 0x38));
  if (LVar1 == 0) {
    *(int *)(unaff_RBP + 0x30) = (int)CONCAT71((int7)((ulonglong)unaff_R15 >> 8),unaff_R14D != 0);
    RegSetValueExA(*(HKEY *)((longlong)&stack0x00000050 + (longlong)*(int *)(in_stack_00000050 + 4))
                   ,"UseBuiltin",0,dwOptions + 4,(BYTE *)(unaff_RBP + 0x30),4);
    *(undefined4 *)(unaff_RBP + 0x30) = unaff_ESI;
    RegSetValueExA(*(HKEY *)((longlong)&stack0x00000050 + (longlong)*(int *)(in_stack_00000050 + 4))
                   ,"BuiltinPosition",0,dwOptions + 4,(BYTE *)(unaff_RBP + 0x30),4);
  }
  if (in_stack_00000058 != (HKEY)0x0) {
    RegCloseKey(in_stack_00000058);
  }
  if (in_stack_00000078 != (HKEY)0x0) {
    RegCloseKey(in_stack_00000078);
  }
  *(DWORD *)(unaff_RBP + -0x80) = dwOptions;
  if (*(HKEY *)(unaff_RBP + -0x68) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x68));
    *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x68) = unaff_R15;
  }
  *(DWORD *)(unaff_RBP + -0x60) = dwOptions;
  if (*(HKEY *)(unaff_RBP + -0x48) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x48));
    *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x48) = unaff_R15;
  }
  *(DWORD *)(unaff_RBP + -0x40) = dwOptions;
  if (*(HKEY *)(unaff_RBP + -0x28) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x28));
  }
  return;
}

/* ---- FUNC 000365CE FUN_1800365ce (104 bytes) ---- */

void FUN_1800365ce(HKEY param_1)

{
  longlong unaff_RBP;
  undefined4 uVar1;
  undefined8 unaff_R15;
  HKEY in_stack_00000078;
  
  RegCloseKey(param_1);
  uVar1 = (undefined4)unaff_R15;
  if (in_stack_00000078 != (HKEY)0x0) {
    RegCloseKey(in_stack_00000078);
  }
  *(undefined4 *)(unaff_RBP + -0x80) = uVar1;
  if (*(HKEY *)(unaff_RBP + -0x68) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x68));
    *(undefined8 *)(unaff_RBP + -0x68) = unaff_R15;
  }
  *(undefined4 *)(unaff_RBP + -0x60) = uVar1;
  if (*(HKEY *)(unaff_RBP + -0x48) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x48));
    *(undefined8 *)(unaff_RBP + -0x48) = unaff_R15;
  }
  *(undefined4 *)(unaff_RBP + -0x40) = uVar1;
  if (*(HKEY *)(unaff_RBP + -0x28) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x28));
  }
  return;
}

/* ---- FUNC 00036636 FUN_180036636 (15 bytes) ---- */

void FUN_180036636(HKEY param_1)

{
  RegCloseKey(param_1);
  return;
}

/* ---- FUNC 00036650 APModLibSetCapeOpen (15 bytes) ---- */

void APModLibSetCapeOpen(int param_1,uint param_2)

{
  int iVar1;
  HKEY hKey;
  LSTATUS LVar2;
  LPCSTR lpSubKey;
  uint local_res18 [2];
  DWORD local_res20 [2];
  HKEY local_c8 [2];
  undefined4 local_b8;
  undefined8 local_b0;
  HKEY local_a8 [2];
  undefined4 local_98;
  undefined8 local_90;
  HKEY local_88 [2];
  undefined4 local_78;
  undefined8 local_70;
  HKEY local_68 [2];
  undefined4 local_58;
  undefined8 local_50;
  HKEY local_48 [2];
  undefined4 local_38;
  undefined8 local_30;
  
                    /* 0x36650  271  APModLibSetCapeOpen */
  local_48[0] = (HKEY)&DAT_180053988;
  local_68[0] = (HKEY)&DAT_180053988;
  local_88[0] = (HKEY)&DAT_180053988;
  local_a8[0] = (HKEY)&DAT_180053988;
  local_c8[0] = (HKEY)&DAT_180053988;
  local_48[1] = (HKEY)0x0;
  local_38 = 0;
  local_30 = 0;
  local_68[1] = (HKEY)0x0;
  local_58 = 0;
  local_50 = 0;
  local_88[1] = (HKEY)0x0;
  local_78 = 0;
  local_70 = 0;
  local_a8[1] = (HKEY)0x0;
  local_98 = 0;
  local_90 = 0;
  local_c8[1] = (HKEY)0x0;
  local_b8 = 0;
  local_b0 = 0;
  LVar2 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000001,"Software",0,0xf003f,local_48 + 1);
  if (LVar2 == 0) {
    LVar2 = RegOpenKeyExA(*(HKEY *)((longlong)local_48 + (longlong)local_48[0][1].unused),
                          "AspenTech",0,0xf003f,
                          (PHKEY)((longlong)local_68 + (longlong)local_68[0][1].unused));
    if (LVar2 == 0) {
      LVar2 = RegOpenKeyExA(*(HKEY *)((longlong)local_68 + (longlong)local_68[0][1].unused),
                            "ASPEN PLUS",0,0xf003f,
                            (PHKEY)((longlong)local_88 + (longlong)local_88[0][1].unused));
      if (LVar2 == 0) {
        hKey = *(HKEY *)((longlong)local_88 + (longlong)local_88[0][1].unused);
        iVar1 = local_a8[0][1].unused;
        lpSubKey = (LPCSTR)FUN_180024170();
        LVar2 = RegCreateKeyExA(hKey,lpSubKey,0,(LPSTR)0x0,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,
                                (PHKEY)((longlong)local_a8 + (longlong)iVar1),local_res20);
        if (LVar2 == 0) {
          LVar2 = RegCreateKeyExA(*(HKEY *)((longlong)local_a8 + (longlong)local_a8[0][1].unused),
                                  "Libraries",0,(LPSTR)0x0,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,
                                  (PHKEY)((longlong)local_c8 + (longlong)local_c8[0][1].unused),
                                  local_res20);
          if (LVar2 == 0) {
            local_res18[0] = (uint)(param_1 != 0);
            RegSetValueExA(*(HKEY *)((longlong)local_c8 + (longlong)local_c8[0][1].unused),
                           "UseCapeOpen",0,4,(BYTE *)local_res18,4);
            local_res18[0] = param_2;
            RegSetValueExA(*(HKEY *)((longlong)local_c8 + (longlong)local_c8[0][1].unused),
                           "CapeOpenPosition",0,4,(BYTE *)local_res18,4);
          }
        }
      }
    }
  }
  if (local_c8[1] != (HKEY)0x0) {
    RegCloseKey(local_c8[1]);
    local_c8[1] = (HKEY)0x0;
  }
  local_b8 = 0;
  if (local_a8[1] != (HKEY)0x0) {
    RegCloseKey(local_a8[1]);
    local_a8[1] = (HKEY)0x0;
  }
  local_98 = 0;
  if (local_88[1] != (HKEY)0x0) {
    RegCloseKey(local_88[1]);
    local_88[1] = (HKEY)0x0;
  }
  local_78 = 0;
  if (local_68[1] != (HKEY)0x0) {
    RegCloseKey(local_68[1]);
    local_68[1] = (HKEY)0x0;
  }
  local_58 = 0;
  if (local_48[1] != (HKEY)0x0) {
    RegCloseKey(local_48[1]);
  }
  return;
}

/* ---- FUNC 0003665F FUN_18003665f (289 bytes) ---- */

void FUN_18003665f(int param_1,undefined4 param_2)

{
  int iVar1;
  HKEY hKey;
  LSTATUS LVar2;
  longlong in_RAX;
  LPCSTR lpSubKey;
  longlong unaff_RBP;
  undefined8 unaff_RSI;
  undefined8 unaff_R14;
  undefined8 unaff_R15;
  undefined *puStack0000000000000050;
  HKEY pHStack0000000000000058;
  undefined4 uStack0000000000000060;
  undefined8 uStack0000000000000068;
  undefined *puStack0000000000000070;
  HKEY pHStack0000000000000078;
  
  *(undefined8 *)(in_RAX + -0x10) = unaff_RSI;
  *(undefined8 *)(in_RAX + -0x20) = unaff_R14;
  *(undefined8 *)(in_RAX + -0x28) = unaff_R15;
  *(undefined **)(unaff_RBP + -0x30) = &DAT_180053988;
  *(undefined **)(unaff_RBP + -0x50) = &DAT_180053988;
  *(undefined **)(unaff_RBP + -0x70) = &DAT_180053988;
  puStack0000000000000070 = &DAT_180053988;
  puStack0000000000000050 = &DAT_180053988;
  *(undefined8 *)(unaff_RBP + -0x28) = 0;
  *(undefined4 *)(unaff_RBP + -0x20) = 0;
  *(undefined8 *)(unaff_RBP + -0x18) = 0;
  *(undefined8 *)(unaff_RBP + -0x48) = 0;
  *(undefined4 *)(unaff_RBP + -0x40) = 0;
  *(undefined8 *)(unaff_RBP + -0x38) = 0;
  *(undefined8 *)(unaff_RBP + -0x68) = 0;
  *(undefined4 *)(unaff_RBP + -0x60) = 0;
  *(undefined8 *)(unaff_RBP + -0x58) = 0;
  pHStack0000000000000078 = (HKEY)0x0;
  *(undefined4 *)(unaff_RBP + -0x80) = 0;
  *(undefined8 *)(unaff_RBP + -0x78) = 0;
  pHStack0000000000000058 = (HKEY)0x0;
  uStack0000000000000060 = 0;
  uStack0000000000000068 = 0;
  LVar2 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000001,"Software",0,0xf003f,(PHKEY)(unaff_RBP + -0x28))
  ;
  if (LVar2 == 0) {
    LVar2 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + -0x30 +
                                   (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x30) + 4)),
                          "AspenTech",0,0xf003f,
                          (PHKEY)(unaff_RBP + -0x50 +
                                 (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x50) + 4)));
    if (LVar2 == 0) {
      LVar2 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + -0x50 +
                                     (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x50) + 4)),
                            "ASPEN PLUS",0,0xf003f,
                            (PHKEY)(unaff_RBP + -0x70 +
                                   (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x70) + 4)));
      if (LVar2 == 0) {
        hKey = *(HKEY *)(unaff_RBP + -0x70 +
                        (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x70) + 4));
        iVar1 = *(int *)(puStack0000000000000070 + 4);
        lpSubKey = (LPCSTR)FUN_180024170();
        LVar2 = RegCreateKeyExA(hKey,lpSubKey,0,(LPSTR)0x0,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,
                                (PHKEY)((longlong)&stack0x00000070 + (longlong)iVar1),
                                (LPDWORD)(unaff_RBP + 0x38));
        if (LVar2 == 0) {
          LVar2 = RegCreateKeyExA(*(HKEY *)((longlong)&stack0x00000070 +
                                           (longlong)*(int *)(puStack0000000000000070 + 4)),
                                  "Libraries",0,(LPSTR)0x0,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,
                                  (PHKEY)((longlong)&stack0x00000050 +
                                         (longlong)*(int *)(puStack0000000000000050 + 4)),
                                  (LPDWORD)(unaff_RBP + 0x38));
          if (LVar2 == 0) {
            *(uint *)(unaff_RBP + 0x30) = (uint)(param_1 != 0);
            RegSetValueExA(*(HKEY *)((longlong)&stack0x00000050 +
                                    (longlong)*(int *)(puStack0000000000000050 + 4)),"UseCapeOpen",0
                           ,4,(BYTE *)(unaff_RBP + 0x30),4);
            *(undefined4 *)(unaff_RBP + 0x30) = param_2;
            RegSetValueExA(*(HKEY *)((longlong)&stack0x00000050 +
                                    (longlong)*(int *)(puStack0000000000000050 + 4)),
                           "CapeOpenPosition",0,4,(BYTE *)(unaff_RBP + 0x30),4);
          }
        }
      }
    }
  }
  if (pHStack0000000000000058 != (HKEY)0x0) {
    RegCloseKey(pHStack0000000000000058);
    pHStack0000000000000058 = (HKEY)0x0;
  }
  uStack0000000000000060 = 0;
  if (pHStack0000000000000078 != (HKEY)0x0) {
    RegCloseKey(pHStack0000000000000078);
    pHStack0000000000000078 = (HKEY)0x0;
  }
  *(undefined4 *)(unaff_RBP + -0x80) = 0;
  if (*(HKEY *)(unaff_RBP + -0x68) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x68));
    *(undefined8 *)(unaff_RBP + -0x68) = 0;
  }
  *(undefined4 *)(unaff_RBP + -0x60) = 0;
  if (*(HKEY *)(unaff_RBP + -0x48) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x48));
    *(undefined8 *)(unaff_RBP + -0x48) = 0;
  }
  *(undefined4 *)(unaff_RBP + -0x40) = 0;
  if (*(HKEY *)(unaff_RBP + -0x28) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x28));
  }
  return;
}

/* ---- FUNC 00036780 FUN_180036780 (121 bytes) ---- */

void FUN_180036780(void)

{
  int iVar1;
  HKEY hKey;
  LSTATUS LVar2;
  longlong in_RAX;
  LPCSTR lpSubKey;
  longlong unaff_RBP;
  undefined4 unaff_ESI;
  int unaff_R14D;
  DWORD dwOptions;
  LPSECURITY_ATTRIBUTES unaff_R15;
  longlong in_stack_00000050;
  HKEY in_stack_00000058;
  longlong in_stack_00000070;
  HKEY in_stack_00000078;
  
  hKey = *(HKEY *)(unaff_RBP + -0x70 + (longlong)*(int *)(in_RAX + 4));
  iVar1 = *(int *)(in_stack_00000070 + 4);
  lpSubKey = (LPCSTR)FUN_180024170();
  dwOptions = (DWORD)unaff_R15;
  LVar2 = RegCreateKeyExA(hKey,lpSubKey,0,(LPSTR)0x0,dwOptions,0xf003f,unaff_R15,
                          (PHKEY)((longlong)&stack0x00000070 + (longlong)iVar1),
                          (LPDWORD)(unaff_RBP + 0x38));
  if (LVar2 == 0) {
    LVar2 = RegCreateKeyExA(*(HKEY *)((longlong)&stack0x00000070 +
                                     (longlong)*(int *)(in_stack_00000070 + 4)),"Libraries",0,
                            (LPSTR)0x0,dwOptions,0xf003f,unaff_R15,
                            (PHKEY)((longlong)&stack0x00000050 +
                                   (longlong)*(int *)(in_stack_00000050 + 4)),
                            (LPDWORD)(unaff_RBP + 0x38));
    if (LVar2 == 0) {
      *(int *)(unaff_RBP + 0x30) = (int)CONCAT71((int7)((ulonglong)unaff_R15 >> 8),unaff_R14D != 0);
      RegSetValueExA(*(HKEY *)((longlong)&stack0x00000050 +
                              (longlong)*(int *)(in_stack_00000050 + 4)),"UseCapeOpen",0,
                     dwOptions + 4,(BYTE *)(unaff_RBP + 0x30),4);
      *(undefined4 *)(unaff_RBP + 0x30) = unaff_ESI;
      RegSetValueExA(*(HKEY *)((longlong)&stack0x00000050 +
                              (longlong)*(int *)(in_stack_00000050 + 4)),"CapeOpenPosition",0,
                     dwOptions + 4,(BYTE *)(unaff_RBP + 0x30),4);
    }
  }
  if (in_stack_00000058 != (HKEY)0x0) {
    RegCloseKey(in_stack_00000058);
  }
  if (in_stack_00000078 != (HKEY)0x0) {
    RegCloseKey(in_stack_00000078);
  }
  *(DWORD *)(unaff_RBP + -0x80) = dwOptions;
  if (*(HKEY *)(unaff_RBP + -0x68) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x68));
    *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x68) = unaff_R15;
  }
  *(DWORD *)(unaff_RBP + -0x60) = dwOptions;
  if (*(HKEY *)(unaff_RBP + -0x48) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x48));
    *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x48) = unaff_R15;
  }
  *(DWORD *)(unaff_RBP + -0x40) = dwOptions;
  if (*(HKEY *)(unaff_RBP + -0x28) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x28));
  }
  return;
}

/* ---- FUNC 000367F9 FUN_1800367f9 (229 bytes) ---- */

void FUN_1800367f9(void)

{
  LSTATUS LVar1;
  longlong unaff_RBP;
  undefined4 unaff_ESI;
  int unaff_R14D;
  DWORD dwOptions;
  LPSECURITY_ATTRIBUTES unaff_R15;
  longlong in_stack_00000050;
  HKEY in_stack_00000058;
  longlong in_stack_00000070;
  HKEY in_stack_00000078;
  
  dwOptions = (DWORD)unaff_R15;
  LVar1 = RegCreateKeyExA(*(HKEY *)((longlong)&stack0x00000070 +
                                   (longlong)*(int *)(in_stack_00000070 + 4)),"Libraries",0,
                          (LPSTR)0x0,dwOptions,0xf003f,unaff_R15,
                          (PHKEY)((longlong)&stack0x00000050 +
                                 (longlong)*(int *)(in_stack_00000050 + 4)),
                          (LPDWORD)(unaff_RBP + 0x38));
  if (LVar1 == 0) {
    *(int *)(unaff_RBP + 0x30) = (int)CONCAT71((int7)((ulonglong)unaff_R15 >> 8),unaff_R14D != 0);
    RegSetValueExA(*(HKEY *)((longlong)&stack0x00000050 + (longlong)*(int *)(in_stack_00000050 + 4))
                   ,"UseCapeOpen",0,dwOptions + 4,(BYTE *)(unaff_RBP + 0x30),4);
    *(undefined4 *)(unaff_RBP + 0x30) = unaff_ESI;
    RegSetValueExA(*(HKEY *)((longlong)&stack0x00000050 + (longlong)*(int *)(in_stack_00000050 + 4))
                   ,"CapeOpenPosition",0,dwOptions + 4,(BYTE *)(unaff_RBP + 0x30),4);
  }
  if (in_stack_00000058 != (HKEY)0x0) {
    RegCloseKey(in_stack_00000058);
  }
  if (in_stack_00000078 != (HKEY)0x0) {
    RegCloseKey(in_stack_00000078);
  }
  *(DWORD *)(unaff_RBP + -0x80) = dwOptions;
  if (*(HKEY *)(unaff_RBP + -0x68) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x68));
    *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x68) = unaff_R15;
  }
  *(DWORD *)(unaff_RBP + -0x60) = dwOptions;
  if (*(HKEY *)(unaff_RBP + -0x48) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x48));
    *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x48) = unaff_R15;
  }
  *(DWORD *)(unaff_RBP + -0x40) = dwOptions;
  if (*(HKEY *)(unaff_RBP + -0x28) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x28));
  }
  return;
}

/* ---- FUNC 000368DE FUN_1800368de (104 bytes) ---- */

void FUN_1800368de(HKEY param_1)

{
  longlong unaff_RBP;
  undefined4 uVar1;
  undefined8 unaff_R15;
  HKEY in_stack_00000078;
  
  RegCloseKey(param_1);
  uVar1 = (undefined4)unaff_R15;
  if (in_stack_00000078 != (HKEY)0x0) {
    RegCloseKey(in_stack_00000078);
  }
  *(undefined4 *)(unaff_RBP + -0x80) = uVar1;
  if (*(HKEY *)(unaff_RBP + -0x68) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x68));
    *(undefined8 *)(unaff_RBP + -0x68) = unaff_R15;
  }
  *(undefined4 *)(unaff_RBP + -0x60) = uVar1;
  if (*(HKEY *)(unaff_RBP + -0x48) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x48));
    *(undefined8 *)(unaff_RBP + -0x48) = unaff_R15;
  }
  *(undefined4 *)(unaff_RBP + -0x40) = uVar1;
  if (*(HKEY *)(unaff_RBP + -0x28) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x28));
  }
  return;
}

/* ---- FUNC 00036946 FUN_180036946 (15 bytes) ---- */

void FUN_180036946(HKEY param_1)

{
  RegCloseKey(param_1);
  return;
}

/* ---- FUNC 00036960 FUN_180036960 (41 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

DWORD FUN_180036960(void)

{
  BYTE BVar1;
  BYTE BVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  void *pvVar5;
  bool bVar6;
  LSTATUS LVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  void *pvVar11;
  BYTE *pBVar12;
  longlong lVar13;
  longlong lVar14;
  longlong lVar15;
  undefined8 *puVar16;
  LPCSTR pCVar17;
  DWORD DVar18;
  DWORD dwIndex;
  undefined1 auStackY_3a8 [32];
  DWORD local_358 [2];
  DWORD local_350;
  DWORD local_34c;
  DWORD local_348;
  DWORD local_344;
  DWORD local_340;
  DWORD local_33c;
  DWORD local_338 [2];
  HKEY local_330 [2];
  undefined4 local_320;
  undefined8 local_318;
  HKEY local_310 [2];
  undefined4 local_300;
  undefined8 local_2f8;
  DWORD local_2f0;
  DWORD local_2ec;
  DWORD local_2e8 [2];
  _FILETIME local_2e0;
  HKEY local_2d8 [2];
  undefined4 local_2c8;
  undefined8 local_2c0;
  HKEY local_2b8 [2];
  undefined4 local_2a8;
  undefined8 local_2a0;
  DWORD local_298;
  DWORD local_294;
  longlong local_290;
  undefined1 local_288;
  undefined7 uStack_287;
  ulonglong auStack_280 [3];
  CHAR local_268 [24];
  CHAR local_250 [23];
  char acStack_239 [257];
  BYTE local_138 [256];
  ulonglong local_38;
  
  local_38 = DAT_1800791f8 ^ (ulonglong)auStackY_3a8;
  DVar18 = 0;
  local_2b8[1] = (HKEY)0x0;
  local_2b8[0] = (HKEY)&DAT_180053988;
  local_310[0] = (HKEY)&DAT_180053988;
  local_2a8 = 0;
  local_2a0 = 0;
  local_310[1] = (HKEY)0x0;
  local_300 = 0;
  local_2f8 = 0;
  FUN_180031fb0(&local_290,"Software\\AspenTech\\",1);
  pvVar11 = (void *)FUN_180024130();
  FUN_180029360((longlong *)((longlong)&local_290 + (longlong)*(int *)(local_290 + 4)),pvVar11);
  lVar14 = (longlong)*(int *)(local_290 + 4);
  puVar16 = (undefined8 *)((longlong)&local_290 + lVar14);
  uVar3 = *(ulonglong *)((longlong)auStack_280 + lVar14 + 8);
  uVar4 = *(ulonglong *)((longlong)auStack_280 + lVar14);
  if (uVar3 == uVar4) {
    FUN_180017f00(puVar16,1,0,&DAT_180053ef4,1);
  }
  else {
    *(ulonglong *)((longlong)auStack_280 + lVar14) = uVar4 + 1;
    if (0xf < uVar3) {
      puVar16 = (undefined8 *)*puVar16;
    }
    *(undefined2 *)((longlong)puVar16 + uVar4) = 0x5c;
  }
  pvVar11 = (void *)FUN_180024170();
  FUN_180029360((longlong *)((longlong)&local_290 + (longlong)*(int *)(local_290 + 4)),pvVar11);
  lVar14 = (longlong)*(int *)(local_290 + 4);
  puVar16 = (undefined8 *)((longlong)&local_290 + lVar14);
  uVar3 = *(ulonglong *)((longlong)auStack_280 + lVar14 + 8);
  uVar4 = *(ulonglong *)((longlong)auStack_280 + lVar14);
  if (uVar3 == uVar4) {
    FUN_180017f00(puVar16,1,0,&DAT_180053ef4,1);
  }
  else {
    *(ulonglong *)((longlong)auStack_280 + lVar14) = uVar4 + 1;
    if (0xf < uVar3) {
      puVar16 = (undefined8 *)*puVar16;
    }
    *(undefined2 *)((longlong)puVar16 + uVar4) = 0x5c;
  }
  lVar15 = (longlong)*(int *)(local_290 + 4);
  puVar16 = (undefined8 *)((longlong)&local_290 + lVar15);
  uVar3 = *(ulonglong *)((longlong)auStack_280 + lVar15 + 8);
  lVar14 = *(longlong *)((longlong)auStack_280 + lVar15);
  if (uVar3 - lVar14 < 9) {
    FUN_180017f00(puVar16,9,0,"Libraries",9);
  }
  else {
    *(longlong *)((longlong)auStack_280 + lVar15) = lVar14 + 9;
    if (0xf < uVar3) {
      puVar16 = (undefined8 *)*puVar16;
    }
    memmove((void *)((longlong)puVar16 + lVar14),"Libraries",9);
    *(undefined1 *)((longlong)puVar16 + lVar14 + 9) = 0;
  }
  pCVar17 = (LPCSTR)((longlong)&local_290 + (longlong)*(int *)(local_290 + 4));
  if (0xf < *(ulonglong *)((longlong)auStack_280 + (longlong)*(int *)(local_290 + 4) + 8)) {
    pCVar17 = *(LPCSTR *)pCVar17;
  }
  LVar7 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000002,pCVar17,0,0x20019,
                        (PHKEY)((longlong)local_2b8 + (longlong)local_2b8[0][1].unused));
  if (LVar7 == 0) {
    pCVar17 = (LPCSTR)((longlong)&local_290 + (longlong)*(int *)(local_290 + 4));
    if (0xf < *(ulonglong *)((longlong)auStack_280 + (longlong)*(int *)(local_290 + 4) + 8)) {
      pCVar17 = *(LPCSTR *)pCVar17;
    }
    LVar7 = RegCreateKeyExA((HKEY)&DAT_ffffffff80000001,pCVar17,0,(LPSTR)0x0,0,0xf003f,
                            (LPSECURITY_ATTRIBUTES)0x0,
                            (PHKEY)((longlong)local_310 + (longlong)local_310[0][1].unused),
                            &local_298);
    if (LVar7 == 0) {
      local_348 = 0x18;
      local_344 = 0x100;
      local_350 = 0x100;
      iVar8 = RegEnumKeyExA(*(HKEY *)((longlong)local_2b8 + (longlong)local_2b8[0][1].unused),0,
                            local_250,&local_348,(LPDWORD)0x0,(LPSTR)0x0,(LPDWORD)0x0,&local_2e0);
      dwIndex = DVar18;
      while (DVar18 = 1, iVar8 == 0) {
        local_2d8[0] = (HKEY)&DAT_180053988;
        local_2d8[1] = (HKEY)0x0;
        local_2c8 = 0;
        local_2c0 = 0;
        LVar7 = RegOpenKeyExA(*(HKEY *)((longlong)local_2b8 + (longlong)local_2b8[0][1].unused),
                              local_250,0,0x20019,local_2d8 + 1);
        if (LVar7 == 0) {
          local_344 = 0x100;
          LVar7 = RegQueryValueExA(*(HKEY *)((longlong)local_2d8 + (longlong)local_2d8[0][1].unused)
                                   ,"Display Name",(LPDWORD)0x0,(LPDWORD)0x0,local_138,&local_344);
          if (LVar7 == 0) {
            local_34c = 0x18;
            iVar9 = RegEnumKeyExA(*(HKEY *)((longlong)local_310 + (longlong)local_310[0][1].unused),
                                  0,local_268,&local_34c,(LPDWORD)0x0,(LPSTR)0x0,(LPDWORD)0x0,
                                  &local_2e0);
            iVar8 = -1;
            DVar18 = 0;
            while (bVar6 = false, iVar9 == 0) {
              local_330[0] = (HKEY)&DAT_180053988;
              local_330[1] = (HKEY)0x0;
              local_320 = 0;
              local_318 = 0;
              LVar7 = RegOpenKeyExA(*(HKEY *)((longlong)local_310 + (longlong)local_310[0][1].unused
                                             ),local_268,0,0x20019,local_330 + 1);
              if (LVar7 == 0) {
                local_350 = 0x100;
                LVar7 = RegQueryValueExA(*(HKEY *)((longlong)local_330 +
                                                  (longlong)local_330[0][1].unused),"Display Name",
                                         (LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)(acStack_239 + 1),
                                         &local_350);
                if (LVar7 == 0) {
                  pBVar12 = local_138;
                  lVar14 = 1 - (longlong)pBVar12;
                  do {
                    BVar1 = *pBVar12;
                    BVar2 = pBVar12[(longlong)(acStack_239 + lVar14)];
                    if (BVar1 != BVar2) break;
                    pBVar12 = pBVar12 + 1;
                  } while (BVar2 != '\0');
                  if (BVar1 == BVar2) {
                    bVar6 = true;
                    if (local_330[1] != (HKEY)0x0) {
                      RegCloseKey(local_330[1]);
                      bVar6 = true;
                    }
                    break;
                  }
                }
              }
              iVar10 = atoi(local_268);
              local_34c = 0x18;
              if (iVar10 < iVar8) {
                iVar10 = iVar8;
              }
              if (local_330[1] != (HKEY)0x0) {
                RegCloseKey(local_330[1]);
              }
              iVar9 = RegEnumKeyExA(*(HKEY *)((longlong)local_310 + (longlong)local_310[0][1].unused
                                             ),DVar18 + 1,local_268,&local_34c,(LPDWORD)0x0,
                                    (LPSTR)0x0,(LPDWORD)0x0,&local_2e0);
              iVar8 = iVar10;
              DVar18 = DVar18 + 1;
            }
            if (!bVar6) {
              iVar9 = iVar8 + 1;
              if (iVar8 < (int)(DVar18 + 1)) {
                iVar9 = DVar18 + 1;
              }
              _itoa(iVar9,local_268,10);
              local_330[0] = (HKEY)&DAT_180053988;
              local_330[1] = (HKEY)0x0;
              local_320 = 0;
              local_318 = 0;
              LVar7 = RegCreateKeyExA(*(HKEY *)((longlong)local_310 +
                                               (longlong)local_310[0][1].unused),local_268,0,
                                      (LPSTR)0x0,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,local_330 + 1,
                                      &local_294);
              if (LVar7 == 0) {
                local_358[0] = 0x100;
                local_350 = 0;
                LVar7 = RegQueryValueExA(*(HKEY *)((longlong)local_2d8 +
                                                  (longlong)local_2d8[0][1].unused),"Display Name",
                                         (LPDWORD)0x0,&local_2f0,(LPBYTE)(acStack_239 + 1),local_358
                                        );
                if ((LVar7 == 0) && (local_2f0 == 1 || local_2f0 == 2)) {
                  if (local_358[0] == 0) {
                    acStack_239[1] = 0;
                  }
                  else if (acStack_239[local_358[0]] != '\0') goto LAB_180036f80;
                  local_350 = local_358[0];
                  lVar14 = -1;
                  do {
                    lVar13 = lVar14 + 1;
                    lVar15 = lVar14 + 2;
                    lVar14 = lVar13;
                  } while (acStack_239[lVar15] != '\0');
                  RegSetValueExA(*(HKEY *)((longlong)local_330 + (longlong)local_330[0][1].unused),
                                 "Display Name",0,1,(BYTE *)(acStack_239 + 1),(int)lVar13 + 1);
                }
LAB_180036f80:
                local_358[0] = 0x100;
                local_350 = 0;
                LVar7 = RegQueryValueExA(*(HKEY *)((longlong)local_2d8 +
                                                  (longlong)local_2d8[0][1].unused),"Path",
                                         (LPDWORD)0x0,&local_2ec,(LPBYTE)(acStack_239 + 1),local_358
                                        );
                if ((LVar7 == 0) && (local_2ec == 1 || local_2ec == 2)) {
                  if (local_358[0] == 0) {
                    acStack_239[1] = 0;
                  }
                  else if (acStack_239[local_358[0]] != '\0') goto LAB_180037034;
                  local_350 = local_358[0];
                  lVar14 = -1;
                  do {
                    lVar13 = lVar14 + 1;
                    lVar15 = lVar14 + 2;
                    lVar14 = lVar13;
                  } while (acStack_239[lVar15] != '\0');
                  RegSetValueExA(*(HKEY *)((longlong)local_330 + (longlong)local_330[0][1].unused),
                                 "Path",0,1,(BYTE *)(acStack_239 + 1),(int)lVar13 + 1);
                }
LAB_180037034:
                local_358[0] = 4;
                LVar7 = RegQueryValueExA(*(HKEY *)((longlong)local_2d8 +
                                                  (longlong)local_2d8[0][1].unused),"Position",
                                         (LPDWORD)0x0,local_2e8,(LPBYTE)&local_340,local_358);
                if ((LVar7 != 0) || (local_2e8[0] != 4)) {
                  local_340 = 0;
                }
                local_358[0] = local_340;
                RegSetValueExA(*(HKEY *)((longlong)local_330 + (longlong)local_330[0][1].unused),
                               "Position",0,4,(BYTE *)local_358,4);
                local_358[0] = 4;
                LVar7 = RegQueryValueExA(*(HKEY *)((longlong)local_2d8 +
                                                  (longlong)local_2d8[0][1].unused),"Active",
                                         (LPDWORD)0x0,local_338,(LPBYTE)&local_33c,local_358);
                if ((LVar7 != 0) || (local_338[0] != 4)) {
                  local_33c = 0;
                }
                local_358[0] = local_33c;
                RegSetValueExA(*(HKEY *)((longlong)local_330 + (longlong)local_330[0][1].unused),
                               "Active",0,4,(BYTE *)local_358,4);
              }
              if (local_330[1] != (HKEY)0x0) {
                RegCloseKey(local_330[1]);
              }
            }
          }
        }
        dwIndex = dwIndex + 1;
        local_348 = 0x18;
        if (local_2d8[1] != (HKEY)0x0) {
          RegCloseKey(local_2d8[1]);
        }
        iVar8 = RegEnumKeyExA(*(HKEY *)((longlong)local_2b8 + (longlong)local_2b8[0][1].unused),
                              dwIndex,local_250,&local_348,(LPDWORD)0x0,(LPSTR)0x0,(LPDWORD)0x0,
                              &local_2e0);
      }
    }
  }
  if (0xf < auStack_280[2]) {
    pvVar5 = (void *)CONCAT71(uStack_287,local_288);
    pvVar11 = pvVar5;
    if ((0xfff < auStack_280[2] + 1) &&
       (pvVar11 = *(void **)((longlong)pvVar5 + -8),
       0x1f < (ulonglong)((longlong)pvVar5 + (-8 - (longlong)pvVar11)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar11);
  }
  local_288 = 0;
  auStack_280[1] = _DAT_180053820;
  auStack_280[2] = _UNK_180053828;
  if (local_310[1] != (HKEY)0x0) {
    RegCloseKey(local_310[1]);
    local_310[1] = (HKEY)0x0;
  }
  local_300 = 0;
  if (local_2b8[1] != (HKEY)0x0) {
    RegCloseKey(local_2b8[1]);
  }
  return DVar18;
}

/* ---- FUNC 00036989 FUN_180036989 (296 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_180036989(void)

{
  char cVar1;
  uint _Value;
  longlong lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  LSTATUS LVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  void *pvVar9;
  DWORD *pDVar10;
  longlong lVar11;
  undefined8 *puVar13;
  void *pvVar14;
  LPCSTR pCVar15;
  uint uVar16;
  ulonglong uVar17;
  DWORD *unaff_RBP;
  DWORD DVar18;
  char cVar19;
  DWORD dwOptions;
  LPSECURITY_ATTRIBUTES unaff_R12;
  ulonglong uVar20;
  ulonglong uVar21;
  DWORD in_stack_00000050;
  DWORD DStack0000000000000058;
  undefined4 uStack000000000000005c;
  DWORD DStack0000000000000060;
  undefined4 uStack0000000000000064;
  DWORD DStack0000000000000068;
  DWORD DStack000000000000006c;
  DWORD in_stack_00000070;
  undefined *in_stack_00000078;
  longlong lVar12;
  
  *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -2) = unaff_R12;
  uVar20 = 1;
  *(undefined **)(unaff_RBP + -4) = &DAT_180053988;
  *(undefined **)(unaff_RBP + -0x1a) = &DAT_180053988;
  dwOptions = (DWORD)unaff_R12;
  *unaff_RBP = dwOptions;
  *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + 2) = unaff_R12;
  *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x18) = unaff_R12;
  unaff_RBP[-0x16] = dwOptions;
  *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x14) = unaff_R12;
  FUN_180031fb0((longlong *)(unaff_RBP + 6),"Software\\AspenTech\\",1);
  pvVar9 = (void *)FUN_180024130();
  FUN_180029360((longlong *)
                ((longlong)unaff_RBP + (longlong)*(int *)(*(longlong *)(unaff_RBP + 6) + 4) + 0x18),
                pvVar9);
  puVar13 = (undefined8 *)
            ((longlong)unaff_RBP + (longlong)*(int *)(*(longlong *)(unaff_RBP + 6) + 4) + 0x18);
  uVar21 = puVar13[2];
  if (puVar13[3] == uVar21) {
    FUN_180017f00(puVar13,1,0,&DAT_180053ef4,1);
  }
  else {
    puVar13[2] = uVar21 + 1;
    if (0xf < (ulonglong)puVar13[3]) {
      puVar13 = (undefined8 *)*puVar13;
    }
    *(undefined2 *)((longlong)puVar13 + uVar21) = 0x5c;
  }
  pvVar9 = (void *)FUN_180024170();
  FUN_180029360((longlong *)
                ((longlong)unaff_RBP + (longlong)*(int *)(*(longlong *)(unaff_RBP + 6) + 4) + 0x18),
                pvVar9);
  puVar13 = (undefined8 *)
            ((longlong)unaff_RBP + (longlong)*(int *)(*(longlong *)(unaff_RBP + 6) + 4) + 0x18);
  uVar21 = puVar13[2];
  if (puVar13[3] == uVar21) {
    FUN_180017f00(puVar13,1,0,&DAT_180053ef4,1);
  }
  else {
    puVar13[2] = uVar21 + 1;
    if (0xf < (ulonglong)puVar13[3]) {
      puVar13 = (undefined8 *)*puVar13;
    }
    *(undefined2 *)((longlong)puVar13 + uVar21) = 0x5c;
  }
  puVar13 = (undefined8 *)
            ((longlong)unaff_RBP + (longlong)*(int *)(*(longlong *)(unaff_RBP + 6) + 4) + 0x18);
  lVar12 = puVar13[2];
  cVar19 = (char)unaff_R12;
  if ((ulonglong)(puVar13[3] - lVar12) < 9) {
    FUN_180017f00(puVar13,9,0,"Libraries",9);
  }
  else {
    puVar13[2] = lVar12 + 9;
    if (0xf < (ulonglong)puVar13[3]) {
      puVar13 = (undefined8 *)*puVar13;
    }
    memmove((void *)((longlong)puVar13 + lVar12),"Libraries",9);
    *(char *)((longlong)puVar13 + lVar12 + 9) = cVar19;
  }
  pCVar15 = (LPCSTR)((longlong)unaff_RBP +
                    (longlong)*(int *)(*(longlong *)(unaff_RBP + 6) + 4) + 0x18);
  if (0xf < *(ulonglong *)(pCVar15 + 0x18)) {
    pCVar15 = *(LPCSTR *)pCVar15;
  }
  LVar5 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000002,pCVar15,0,0x20019,
                        (PHKEY)((longlong)unaff_RBP +
                               (longlong)*(int *)(*(longlong *)(unaff_RBP + -4) + 4) + -0x10));
  if (LVar5 == 0) {
    pCVar15 = (LPCSTR)((longlong)unaff_RBP +
                      (longlong)*(int *)(*(longlong *)(unaff_RBP + 6) + 4) + 0x18);
    if (0xf < *(ulonglong *)(pCVar15 + 0x18)) {
      pCVar15 = *(LPCSTR *)pCVar15;
    }
    LVar5 = RegCreateKeyExA((HKEY)&DAT_ffffffff80000001,pCVar15,0,(LPSTR)0x0,dwOptions,0xf003f,
                            unaff_R12,
                            (PHKEY)((longlong)unaff_RBP +
                                   (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x1a) + 4) + -0x68)
                            ,unaff_RBP + 4);
    if (LVar5 == 0) {
      DStack0000000000000060 = 0x18;
      uStack0000000000000064 = 0x100;
      DStack0000000000000058 = 0x100;
      uVar21 = (ulonglong)unaff_R12 & 0xffffffff;
      iVar6 = RegEnumKeyExA(*(HKEY *)((longlong)unaff_RBP +
                                     (longlong)*(int *)(*(longlong *)(unaff_RBP + -4) + 4) + -0x10),
                            0,(LPSTR)(unaff_RBP + 0x16),&stack0x00000060,&unaff_R12->nLength,
                            (LPSTR)unaff_R12,&unaff_R12->nLength,(PFILETIME)(unaff_RBP + -0xe));
      while (iVar6 == 0) {
        *(undefined **)(unaff_RBP + -0xc) = &DAT_180053988;
        *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -10) = unaff_R12;
        unaff_RBP[-8] = dwOptions;
        *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -6) = unaff_R12;
        LVar5 = RegOpenKeyExA(*(HKEY *)((longlong)unaff_RBP +
                                       (longlong)*(int *)(*(longlong *)(unaff_RBP + -4) + 4) + -0x10
                                       ),(LPCSTR)(unaff_RBP + 0x16),0,0x20019,
                              (PHKEY)(unaff_RBP + -10));
        if (LVar5 == 0) {
          uStack0000000000000064 = 0x100;
          LVar5 = RegQueryValueExA(*(HKEY *)((longlong)unaff_RBP +
                                            (longlong)*(int *)(*(longlong *)(unaff_RBP + -0xc) + 4)
                                            + -0x30),"Display Name",(LPDWORD)0x0,(LPDWORD)0x0,
                                   (LPBYTE)(unaff_RBP + 0x5c),
                                   (LPDWORD)((longlong)&stack0x00000060 + 4));
          if (LVar5 == 0) {
            uStack000000000000005c = 0x18;
            uVar17 = (ulonglong)unaff_R12 & 0xffffffff;
            iVar7 = RegEnumKeyExA(*(HKEY *)((longlong)unaff_RBP +
                                           (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x1a) + 4)
                                           + -0x68),0,(LPSTR)(unaff_RBP + 0x10),
                                  (LPDWORD)((longlong)&stack0x00000058 + 4),&unaff_R12->nLength,
                                  (LPSTR)unaff_R12,&unaff_R12->nLength,(PFILETIME)(unaff_RBP + -0xe)
                                 );
            uVar16 = dwOptions;
            iVar6 = -1;
            while (iVar7 == 0) {
              in_stack_00000078 = &DAT_180053988;
              *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x20) = unaff_R12;
              unaff_RBP[-0x1e] = dwOptions;
              uVar16 = (int)uVar17 + 1;
              uVar17 = (ulonglong)uVar16;
              *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x1c) = unaff_R12;
              LVar5 = RegOpenKeyExA(*(HKEY *)((longlong)unaff_RBP +
                                             (longlong)
                                             *(int *)(*(longlong *)(unaff_RBP + -0x1a) + 4) + -0x68)
                                    ,(LPCSTR)(unaff_RBP + 0x10),0,0x20019,(PHKEY)(unaff_RBP + -0x20)
                                   );
              if (LVar5 == 0) {
                DStack0000000000000058 = 0x100;
                LVar5 = RegQueryValueExA(*(HKEY *)((longlong)&stack0x00000078 +
                                                  (longlong)*(int *)(in_stack_00000078 + 4)),
                                         "Display Name",(LPDWORD)0x0,(LPDWORD)0x0,
                                         (LPBYTE)(unaff_RBP + 0x1c),&stack0x00000058);
                if (LVar5 == 0) {
                  pDVar10 = unaff_RBP + 0x5c;
                  lVar12 = 0x70 - (longlong)pDVar10;
                  do {
                    DVar18 = *pDVar10;
                    cVar1 = *(char *)((longlong)pDVar10 + (longlong)unaff_RBP + lVar12);
                    if ((char)DVar18 != cVar1) break;
                    pDVar10 = (DWORD *)((longlong)pDVar10 + 1);
                  } while (cVar1 != '\0');
                  if ((char)DVar18 == cVar1) {
                    DVar18 = 1;
                    if (*(HKEY *)(unaff_RBP + -0x20) != (HKEY)0x0) {
                      RegCloseKey(*(HKEY *)(unaff_RBP + -0x20));
                      DVar18 = 1;
                    }
                    goto LAB_180036e33;
                  }
                }
              }
              iVar8 = atoi((char *)(unaff_RBP + 0x10));
              uStack000000000000005c = 0x18;
              if (iVar8 < iVar6) {
                iVar8 = iVar6;
              }
              if (*(HKEY *)(unaff_RBP + -0x20) != (HKEY)0x0) {
                RegCloseKey(*(HKEY *)(unaff_RBP + -0x20));
              }
              iVar7 = RegEnumKeyExA(*(HKEY *)((longlong)unaff_RBP +
                                             (longlong)
                                             *(int *)(*(longlong *)(unaff_RBP + -0x1a) + 4) + -0x68)
                                    ,uVar16,(LPSTR)(unaff_RBP + 0x10),
                                    (LPDWORD)((longlong)&stack0x00000058 + 4),&unaff_R12->nLength,
                                    (LPSTR)unaff_R12,&unaff_R12->nLength,
                                    (PFILETIME)(unaff_RBP + -0xe));
              iVar6 = iVar8;
            }
            uVar16 = uVar16 + 1;
            DVar18 = dwOptions;
LAB_180036e33:
            if (DVar18 == 0) {
              _Value = iVar6 + 1;
              if (iVar6 < (int)uVar16) {
                _Value = uVar16;
              }
              _itoa(_Value,(char *)(unaff_RBP + 0x10),10);
              in_stack_00000078 = &DAT_180053988;
              *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x20) = unaff_R12;
              unaff_RBP[-0x1e] = dwOptions;
              *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x1c) = unaff_R12;
              LVar5 = RegCreateKeyExA(*(HKEY *)((longlong)unaff_RBP +
                                               (longlong)
                                               *(int *)(*(longlong *)(unaff_RBP + -0x1a) + 4) +
                                               -0x68),(LPCSTR)(unaff_RBP + 0x10),0,(LPSTR)0x0,
                                      dwOptions,0xf003f,unaff_R12,(PHKEY)(unaff_RBP + -0x20),
                                      unaff_RBP + 5);
              if (LVar5 == 0) {
                in_stack_00000050 = 0x100;
                DStack0000000000000058 = dwOptions;
                LVar5 = RegQueryValueExA(*(HKEY *)((longlong)unaff_RBP +
                                                  (longlong)
                                                  *(int *)(*(longlong *)(unaff_RBP + -0xc) + 4) +
                                                  -0x30),"Display Name",(LPDWORD)0x0,
                                         unaff_RBP + -0x12,(LPBYTE)(unaff_RBP + 0x1c),
                                         &stack0x00000050);
                if ((LVar5 == 0) && (unaff_RBP[-0x12] == 1 || unaff_RBP[-0x12] == 2)) {
                  if (in_stack_00000050 == 0) {
                    *(char *)(unaff_RBP + 0x1c) = cVar19;
                  }
                  else if (*(char *)((longlong)unaff_RBP + (ulonglong)in_stack_00000050 + 0x6f) !=
                           cVar19) goto LAB_180036f80;
                  DStack0000000000000058 = in_stack_00000050;
                  lVar12 = -1;
                  do {
                    lVar11 = lVar12 + 1;
                    lVar2 = lVar12 + 0x71;
                    lVar12 = lVar11;
                  } while (*(char *)((longlong)unaff_RBP + lVar2) != cVar19);
                  RegSetValueExA(*(HKEY *)((longlong)&stack0x00000078 +
                                          (longlong)*(int *)(in_stack_00000078 + 4)),"Display Name",
                                 0,1,(BYTE *)(unaff_RBP + 0x1c),(int)lVar11 + 1);
                }
LAB_180036f80:
                in_stack_00000050 = 0x100;
                DStack0000000000000058 = dwOptions;
                LVar5 = RegQueryValueExA(*(HKEY *)((longlong)unaff_RBP +
                                                  (longlong)
                                                  *(int *)(*(longlong *)(unaff_RBP + -0xc) + 4) +
                                                  -0x30),"Path",(LPDWORD)0x0,unaff_RBP + -0x11,
                                         (LPBYTE)(unaff_RBP + 0x1c),&stack0x00000050);
                if ((LVar5 == 0) && (unaff_RBP[-0x11] == 1 || unaff_RBP[-0x11] == 2)) {
                  if (in_stack_00000050 == 0) {
                    *(char *)(unaff_RBP + 0x1c) = cVar19;
                  }
                  else if (*(char *)((longlong)unaff_RBP + (ulonglong)in_stack_00000050 + 0x6f) !=
                           cVar19) goto LAB_180037034;
                  DStack0000000000000058 = in_stack_00000050;
                  lVar12 = -1;
                  do {
                    lVar11 = lVar12 + 1;
                    lVar2 = lVar12 + 0x71;
                    lVar12 = lVar11;
                  } while (*(char *)((longlong)unaff_RBP + lVar2) != cVar19);
                  RegSetValueExA(*(HKEY *)((longlong)&stack0x00000078 +
                                          (longlong)*(int *)(in_stack_00000078 + 4)),"Path",0,1,
                                 (BYTE *)(unaff_RBP + 0x1c),(int)lVar11 + 1);
                }
LAB_180037034:
                in_stack_00000050 = 4;
                LVar5 = RegQueryValueExA(*(HKEY *)((longlong)unaff_RBP +
                                                  (longlong)
                                                  *(int *)(*(longlong *)(unaff_RBP + -0xc) + 4) +
                                                  -0x30),"Position",(LPDWORD)0x0,unaff_RBP + -0x10,
                                         (LPBYTE)&stack0x00000068,&stack0x00000050);
                DVar18 = dwOptions;
                if ((LVar5 == 0) && (unaff_RBP[-0x10] == 4)) {
                  DVar18 = DStack0000000000000068;
                }
                DStack0000000000000068 = DVar18;
                in_stack_00000050 = DStack0000000000000068;
                RegSetValueExA(*(HKEY *)((longlong)&stack0x00000078 +
                                        (longlong)*(int *)(in_stack_00000078 + 4)),"Position",0,4,
                               (BYTE *)&stack0x00000050,4);
                in_stack_00000050 = 4;
                LVar5 = RegQueryValueExA(*(HKEY *)((longlong)unaff_RBP +
                                                  (longlong)
                                                  *(int *)(*(longlong *)(unaff_RBP + -0xc) + 4) +
                                                  -0x30),"Active",(LPDWORD)0x0,&stack0x00000070,
                                         (LPBYTE)((longlong)&stack0x00000068 + 4),&stack0x00000050);
                DVar18 = dwOptions;
                if ((LVar5 == 0) && (in_stack_00000070 == 4)) {
                  DVar18 = DStack000000000000006c;
                }
                DStack000000000000006c = DVar18;
                in_stack_00000050 = DStack000000000000006c;
                RegSetValueExA(*(HKEY *)((longlong)&stack0x00000078 +
                                        (longlong)*(int *)(in_stack_00000078 + 4)),"Active",0,4,
                               (BYTE *)&stack0x00000050,4);
              }
              if (*(HKEY *)(unaff_RBP + -0x20) != (HKEY)0x0) {
                RegCloseKey(*(HKEY *)(unaff_RBP + -0x20));
              }
            }
          }
        }
        uVar16 = (int)uVar21 + 1;
        uVar21 = (ulonglong)uVar16;
        DStack0000000000000060 = 0x18;
        if (*(HKEY *)(unaff_RBP + -10) != (HKEY)0x0) {
          RegCloseKey(*(HKEY *)(unaff_RBP + -10));
        }
        iVar6 = RegEnumKeyExA(*(HKEY *)((longlong)unaff_RBP +
                                       (longlong)*(int *)(*(longlong *)(unaff_RBP + -4) + 4) + -0x10
                                       ),uVar16,(LPSTR)(unaff_RBP + 0x16),&stack0x00000060,
                              &unaff_R12->nLength,(LPSTR)unaff_R12,&unaff_R12->nLength,
                              (PFILETIME)(unaff_RBP + -0xe));
      }
      goto LAB_1800371d7;
    }
  }
  uVar20 = (ulonglong)unaff_R12 & 0xffffffff;
LAB_1800371d7:
  if (0xf < *(ulonglong *)(unaff_RBP + 0xe)) {
    pvVar9 = *(void **)(unaff_RBP + 8);
    pvVar14 = pvVar9;
    if ((0xfff < *(ulonglong *)(unaff_RBP + 0xe) + 1) &&
       (pvVar14 = *(void **)((longlong)pvVar9 + -8),
       0x1f < (ulonglong)((longlong)pvVar9 + (-8 - (longlong)pvVar14)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar14);
  }
  uVar4 = _UNK_180053828;
  uVar3 = _DAT_180053820;
  *(char *)(unaff_RBP + 8) = cVar19;
  *(undefined8 *)(unaff_RBP + 0xc) = uVar3;
  *(undefined8 *)(unaff_RBP + 0xe) = uVar4;
  if (*(HKEY *)(unaff_RBP + -0x18) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x18));
    *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x18) = unaff_R12;
  }
  unaff_RBP[-0x16] = dwOptions;
  if (*(HKEY *)(unaff_RBP + -2) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -2));
  }
  return uVar20;
}

/* ---- FUNC 00036AB1 FUN_180036ab1 (356 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_180036ab1(void)

{
  char cVar1;
  char cVar2;
  void *pvVar3;
  uint _Value;
  undefined8 uVar4;
  undefined8 uVar5;
  LSTATUS LVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  longlong in_RAX;
  char *pcVar10;
  undefined8 *puVar11;
  void *pvVar12;
  LPCSTR pCVar13;
  uint uVar14;
  ulonglong uVar15;
  longlong unaff_RBP;
  DWORD DVar16;
  longlong lVar17;
  char cVar18;
  DWORD dwOptions;
  LPSECURITY_ATTRIBUTES unaff_R12;
  longlong unaff_R13;
  DWORD DVar19;
  ulonglong unaff_R14;
  ulonglong uVar20;
  DWORD in_stack_00000050;
  DWORD DStack0000000000000058;
  undefined4 uStack000000000000005c;
  DWORD DStack0000000000000060;
  undefined4 uStack0000000000000064;
  DWORD DStack0000000000000068;
  DWORD DStack000000000000006c;
  DWORD in_stack_00000070;
  longlong in_stack_00000078;
  
  puVar11 = (undefined8 *)((longlong)*(int *)(in_RAX + 4) + unaff_RBP + 0x18);
  lVar17 = puVar11[2];
  cVar18 = (char)unaff_R12;
  if ((ulonglong)(puVar11[3] - lVar17) < 9) {
    FUN_180017f00(puVar11,9,0,"Libraries",9);
  }
  else {
    puVar11[2] = lVar17 + 9;
    if (0xf < (ulonglong)puVar11[3]) {
      puVar11 = (undefined8 *)*puVar11;
    }
    memmove((void *)((longlong)puVar11 + lVar17),"Libraries",9);
    *(char *)((longlong)puVar11 + lVar17 + 9) = cVar18;
  }
  pCVar13 = (LPCSTR)(unaff_RBP + 0x18 + (longlong)*(int *)(*(longlong *)(unaff_RBP + 0x18) + 4));
  if (0xf < *(ulonglong *)(pCVar13 + 0x18)) {
    pCVar13 = *(LPCSTR *)pCVar13;
  }
  LVar6 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000002,pCVar13,0,0x20019,
                        (PHKEY)(unaff_RBP + -0x10 +
                               (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x10) + 4)));
  dwOptions = (DWORD)unaff_R12;
  if (LVar6 == 0) {
    pCVar13 = (LPCSTR)(unaff_RBP + 0x18 + (longlong)*(int *)(*(longlong *)(unaff_RBP + 0x18) + 4));
    if (0xf < *(ulonglong *)(pCVar13 + 0x18)) {
      pCVar13 = *(LPCSTR *)pCVar13;
    }
    LVar6 = RegCreateKeyExA((HKEY)&DAT_ffffffff80000001,pCVar13,0,(LPSTR)0x0,dwOptions,0xf003f,
                            unaff_R12,
                            (PHKEY)(unaff_RBP + -0x68 +
                                   (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x68) + 4)),
                            (LPDWORD)(unaff_RBP + 0x10));
    if (LVar6 == 0) {
      DStack0000000000000060 = 0x18;
      uStack0000000000000064 = 0x100;
      DStack0000000000000058 = 0x100;
      uVar20 = (ulonglong)unaff_R12 & 0xffffffff;
      iVar7 = RegEnumKeyExA(*(HKEY *)(unaff_RBP + -0x10 +
                                     (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x10) + 4)),0,
                            (LPSTR)(unaff_RBP + 0x58),&stack0x00000060,&unaff_R12->nLength,
                            (LPSTR)unaff_R12,&unaff_R12->nLength,(PFILETIME)(unaff_RBP + -0x38));
      while (iVar7 == 0) {
        *(longlong *)(unaff_RBP + -0x30) = unaff_R13;
        *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x28) = unaff_R12;
        *(DWORD *)(unaff_RBP + -0x20) = dwOptions;
        *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x18) = unaff_R12;
        LVar6 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + -0x10 +
                                       (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x10) + 4)),
                              (LPCSTR)(unaff_RBP + 0x58),0,0x20019,(PHKEY)(unaff_RBP + -0x28));
        if (LVar6 == 0) {
          uStack0000000000000064 = 0x100;
          LVar6 = RegQueryValueExA(*(HKEY *)(unaff_RBP + -0x30 +
                                            (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x30) + 4)
                                            ),"Display Name",(LPDWORD)0x0,(LPDWORD)0x0,
                                   (LPBYTE)(unaff_RBP + 0x170),
                                   (LPDWORD)((longlong)&stack0x00000060 + 4));
          if (LVar6 == 0) {
            uStack000000000000005c = 0x18;
            uVar15 = (ulonglong)unaff_R12 & 0xffffffff;
            iVar8 = RegEnumKeyExA(*(HKEY *)(unaff_RBP + -0x68 +
                                           (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x68) + 4))
                                  ,0,(LPSTR)(unaff_RBP + 0x40),
                                  (LPDWORD)((longlong)&stack0x00000058 + 4),&unaff_R12->nLength,
                                  (LPSTR)unaff_R12,&unaff_R12->nLength,
                                  (PFILETIME)(unaff_RBP + -0x38));
            DVar19 = (DWORD)unaff_R14;
            uVar14 = dwOptions;
            iVar7 = -1;
            while (iVar8 == 0) {
              *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x80) = unaff_R12;
              *(DWORD *)(unaff_RBP + -0x78) = dwOptions;
              uVar14 = (int)uVar15 + 1;
              uVar15 = (ulonglong)uVar14;
              *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x70) = unaff_R12;
              in_stack_00000078 = unaff_R13;
              LVar6 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + -0x68 +
                                             (longlong)
                                             *(int *)(*(longlong *)(unaff_RBP + -0x68) + 4)),
                                    (LPCSTR)(unaff_RBP + 0x40),0,0x20019,(PHKEY)(unaff_RBP + -0x80))
              ;
              if (LVar6 == 0) {
                DStack0000000000000058 = 0x100;
                LVar6 = RegQueryValueExA(*(HKEY *)((longlong)&stack0x00000078 +
                                                  (longlong)*(int *)(in_stack_00000078 + 4)),
                                         "Display Name",(LPDWORD)0x0,(LPDWORD)0x0,
                                         (LPBYTE)(unaff_RBP + 0x70),&stack0x00000058);
                if (LVar6 == 0) {
                  pcVar10 = (char *)(unaff_RBP + 0x170);
                  lVar17 = (unaff_RBP + 0x70) - (longlong)pcVar10;
                  do {
                    cVar1 = *pcVar10;
                    cVar2 = pcVar10[lVar17];
                    if (cVar1 != cVar2) break;
                    pcVar10 = pcVar10 + 1;
                  } while (cVar2 != '\0');
                  if (cVar1 == cVar2) {
                    DVar16 = DVar19;
                    if (*(HKEY *)(unaff_RBP + -0x80) != (HKEY)0x0) {
                      RegCloseKey(*(HKEY *)(unaff_RBP + -0x80));
                    }
                    goto LAB_180036e33;
                  }
                }
              }
              iVar9 = atoi((char *)(unaff_RBP + 0x40));
              uStack000000000000005c = 0x18;
              if (iVar9 < iVar7) {
                iVar9 = iVar7;
              }
              if (*(HKEY *)(unaff_RBP + -0x80) != (HKEY)0x0) {
                RegCloseKey(*(HKEY *)(unaff_RBP + -0x80));
              }
              iVar8 = RegEnumKeyExA(*(HKEY *)(unaff_RBP + -0x68 +
                                             (longlong)
                                             *(int *)(*(longlong *)(unaff_RBP + -0x68) + 4)),uVar14,
                                    (LPSTR)(unaff_RBP + 0x40),
                                    (LPDWORD)((longlong)&stack0x00000058 + 4),&unaff_R12->nLength,
                                    (LPSTR)unaff_R12,&unaff_R12->nLength,
                                    (PFILETIME)(unaff_RBP + -0x38));
              iVar7 = iVar9;
            }
            uVar14 = uVar14 + 1;
            DVar16 = dwOptions;
LAB_180036e33:
            if (DVar16 == 0) {
              _Value = iVar7 + 1;
              if (iVar7 < (int)uVar14) {
                _Value = uVar14;
              }
              _itoa(_Value,(char *)(unaff_RBP + 0x40),10);
              *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x80) = unaff_R12;
              *(DWORD *)(unaff_RBP + -0x78) = dwOptions;
              *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x70) = unaff_R12;
              in_stack_00000078 = unaff_R13;
              LVar6 = RegCreateKeyExA(*(HKEY *)(unaff_RBP + -0x68 +
                                               (longlong)
                                               *(int *)(*(longlong *)(unaff_RBP + -0x68) + 4)),
                                      (LPCSTR)(unaff_RBP + 0x40),0,(LPSTR)0x0,dwOptions,0xf003f,
                                      unaff_R12,(PHKEY)(unaff_RBP + -0x80),
                                      (LPDWORD)(unaff_RBP + 0x14));
              if (LVar6 == 0) {
                in_stack_00000050 = 0x100;
                DStack0000000000000058 = dwOptions;
                LVar6 = RegQueryValueExA(*(HKEY *)(unaff_RBP + -0x30 +
                                                  (longlong)
                                                  *(int *)(*(longlong *)(unaff_RBP + -0x30) + 4)),
                                         "Display Name",(LPDWORD)0x0,(LPDWORD)(unaff_RBP + -0x48),
                                         (LPBYTE)(unaff_RBP + 0x70),&stack0x00000050);
                if ((LVar6 == 0) && (*(int *)(unaff_RBP + -0x48) - 1U <= DVar19)) {
                  if (in_stack_00000050 == 0) {
                    *(char *)(unaff_RBP + 0x70) = cVar18;
                  }
                  else if (*(char *)(unaff_RBP + 0x6f + (ulonglong)in_stack_00000050) != cVar18)
                  goto LAB_180036f80;
                  DStack0000000000000058 = in_stack_00000050;
                  lVar17 = -1;
                  do {
                    lVar17 = lVar17 + 1;
                  } while (*(char *)(unaff_RBP + 0x70 + lVar17) != cVar18);
                  RegSetValueExA(*(HKEY *)((longlong)&stack0x00000078 +
                                          (longlong)*(int *)(in_stack_00000078 + 4)),"Display Name",
                                 0,DVar19,(BYTE *)(unaff_RBP + 0x70),(int)lVar17 + 1);
                }
LAB_180036f80:
                in_stack_00000050 = 0x100;
                DStack0000000000000058 = dwOptions;
                LVar6 = RegQueryValueExA(*(HKEY *)(unaff_RBP + -0x30 +
                                                  (longlong)
                                                  *(int *)(*(longlong *)(unaff_RBP + -0x30) + 4)),
                                         "Path",(LPDWORD)0x0,(LPDWORD)(unaff_RBP + -0x44),
                                         (LPBYTE)(unaff_RBP + 0x70),&stack0x00000050);
                if ((LVar6 == 0) && (*(int *)(unaff_RBP + -0x44) - 1U <= DVar19)) {
                  if (in_stack_00000050 == 0) {
                    *(char *)(unaff_RBP + 0x70) = cVar18;
                  }
                  else if (*(char *)(unaff_RBP + 0x6f + (ulonglong)in_stack_00000050) != cVar18)
                  goto LAB_180037034;
                  DStack0000000000000058 = in_stack_00000050;
                  lVar17 = -1;
                  do {
                    lVar17 = lVar17 + 1;
                  } while (*(char *)(unaff_RBP + 0x70 + lVar17) != cVar18);
                  RegSetValueExA(*(HKEY *)((longlong)&stack0x00000078 +
                                          (longlong)*(int *)(in_stack_00000078 + 4)),"Path",0,DVar19
                                 ,(BYTE *)(unaff_RBP + 0x70),(int)lVar17 + 1);
                }
LAB_180037034:
                in_stack_00000050 = 4;
                LVar6 = RegQueryValueExA(*(HKEY *)(unaff_RBP + -0x30 +
                                                  (longlong)
                                                  *(int *)(*(longlong *)(unaff_RBP + -0x30) + 4)),
                                         "Position",(LPDWORD)0x0,(LPDWORD)(unaff_RBP + -0x40),
                                         (LPBYTE)&stack0x00000068,&stack0x00000050);
                DVar19 = dwOptions;
                if ((LVar6 == 0) && (*(int *)(unaff_RBP + -0x40) == 4)) {
                  DVar19 = DStack0000000000000068;
                }
                DStack0000000000000068 = DVar19;
                in_stack_00000050 = DStack0000000000000068;
                RegSetValueExA(*(HKEY *)((longlong)&stack0x00000078 +
                                        (longlong)*(int *)(in_stack_00000078 + 4)),"Position",0,4,
                               (BYTE *)&stack0x00000050,4);
                in_stack_00000050 = 4;
                LVar6 = RegQueryValueExA(*(HKEY *)(unaff_RBP + -0x30 +
                                                  (longlong)
                                                  *(int *)(*(longlong *)(unaff_RBP + -0x30) + 4)),
                                         "Active",(LPDWORD)0x0,&stack0x00000070,
                                         (LPBYTE)((longlong)&stack0x00000068 + 4),&stack0x00000050);
                DVar19 = dwOptions;
                if ((LVar6 == 0) && (in_stack_00000070 == 4)) {
                  DVar19 = DStack000000000000006c;
                }
                DStack000000000000006c = DVar19;
                in_stack_00000050 = DStack000000000000006c;
                RegSetValueExA(*(HKEY *)((longlong)&stack0x00000078 +
                                        (longlong)*(int *)(in_stack_00000078 + 4)),"Active",0,4,
                               (BYTE *)&stack0x00000050,4);
              }
              if (*(HKEY *)(unaff_RBP + -0x80) != (HKEY)0x0) {
                RegCloseKey(*(HKEY *)(unaff_RBP + -0x80));
              }
            }
          }
        }
        uVar14 = (int)uVar20 + 1;
        uVar20 = (ulonglong)uVar14;
        DStack0000000000000060 = 0x18;
        if (*(HKEY *)(unaff_RBP + -0x28) != (HKEY)0x0) {
          RegCloseKey(*(HKEY *)(unaff_RBP + -0x28));
        }
        iVar7 = RegEnumKeyExA(*(HKEY *)(unaff_RBP + -0x10 +
                                       (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x10) + 4)),
                              uVar14,(LPSTR)(unaff_RBP + 0x58),&stack0x00000060,&unaff_R12->nLength,
                              (LPSTR)unaff_R12,&unaff_R12->nLength,(PFILETIME)(unaff_RBP + -0x38));
      }
      goto LAB_1800371d7;
    }
  }
  unaff_R14 = (ulonglong)unaff_R12 & 0xffffffff;
LAB_1800371d7:
  if (0xf < *(ulonglong *)(unaff_RBP + 0x38)) {
    pvVar3 = *(void **)(unaff_RBP + 0x20);
    pvVar12 = pvVar3;
    if ((0xfff < *(ulonglong *)(unaff_RBP + 0x38) + 1) &&
       (pvVar12 = *(void **)((longlong)pvVar3 + -8),
       0x1f < (ulonglong)((longlong)pvVar3 + (-8 - (longlong)pvVar12)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar12);
  }
  uVar5 = _UNK_180053828;
  uVar4 = _DAT_180053820;
  *(char *)(unaff_RBP + 0x20) = cVar18;
  *(undefined8 *)(unaff_RBP + 0x30) = uVar4;
  *(undefined8 *)(unaff_RBP + 0x38) = uVar5;
  if (*(HKEY *)(unaff_RBP + -0x60) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x60));
    *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x60) = unaff_R12;
  }
  *(DWORD *)(unaff_RBP + -0x58) = dwOptions;
  if (*(HKEY *)(unaff_RBP + -8) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -8));
  }
  return unaff_R14 & 0xffffffff;
}

/* ---- FUNC 00036C15 FUN_180036c15 (30 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_180036c15(HKEY param_1,DWORD param_2,LPSTR param_3,LPDWORD param_4,LPSTR param_5,
                  LPDWORD param_6,PFILETIME param_7,undefined8 param_8,undefined8 param_9,
                  DWORD param_10,undefined8 param_11,undefined8 param_12,undefined8 param_13,
                  DWORD param_14,longlong param_15)

{
  char cVar1;
  char cVar2;
  void *pvVar3;
  uint _Value;
  undefined8 uVar4;
  undefined8 uVar5;
  int iVar6;
  LSTATUS LVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  void *pvVar11;
  uint uVar12;
  ulonglong uVar13;
  longlong unaff_RBP;
  DWORD DVar14;
  longlong lVar15;
  char cVar16;
  DWORD dwOptions;
  LPSECURITY_ATTRIBUTES unaff_R12;
  longlong unaff_R13;
  uint unaff_R14D;
  ulonglong uVar17;
  
  dwOptions = (DWORD)unaff_R12;
  uVar17 = (ulonglong)unaff_R12 & 0xffffffff;
  iVar6 = RegEnumKeyExA(param_1,param_2,param_3,param_4,&unaff_R12->nLength,param_5,param_6,param_7)
  ;
  cVar16 = (char)unaff_R12;
  do {
    if (iVar6 != 0) {
      if (0xf < *(ulonglong *)(unaff_RBP + 0x38)) {
        pvVar3 = *(void **)(unaff_RBP + 0x20);
        pvVar11 = pvVar3;
        if ((0xfff < *(ulonglong *)(unaff_RBP + 0x38) + 1) &&
           (pvVar11 = *(void **)((longlong)pvVar3 + -8),
           0x1f < (ulonglong)((longlong)pvVar3 + (-8 - (longlong)pvVar11)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        operator_delete(pvVar11);
      }
      uVar5 = _UNK_180053828;
      uVar4 = _DAT_180053820;
      *(char *)(unaff_RBP + 0x20) = cVar16;
      *(undefined8 *)(unaff_RBP + 0x30) = uVar4;
      *(undefined8 *)(unaff_RBP + 0x38) = uVar5;
      if (*(HKEY *)(unaff_RBP + -0x60) != (HKEY)0x0) {
        RegCloseKey(*(HKEY *)(unaff_RBP + -0x60));
        *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x60) = unaff_R12;
      }
      *(DWORD *)(unaff_RBP + -0x58) = dwOptions;
      if (*(HKEY *)(unaff_RBP + -8) != (HKEY)0x0) {
        RegCloseKey(*(HKEY *)(unaff_RBP + -8));
      }
      return unaff_R14D;
    }
    *(longlong *)(unaff_RBP + -0x30) = unaff_R13;
    *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x28) = unaff_R12;
    *(DWORD *)(unaff_RBP + -0x20) = dwOptions;
    *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x18) = unaff_R12;
    LVar7 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + -0x10 +
                                   (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x10) + 4)),
                          (LPCSTR)(unaff_RBP + 0x58),0,0x20019,(PHKEY)(unaff_RBP + -0x28));
    if (LVar7 == 0) {
      param_12._4_4_ = 0x100;
      LVar7 = RegQueryValueExA(*(HKEY *)(unaff_RBP + -0x30 +
                                        (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x30) + 4)),
                               "Display Name",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)(unaff_RBP + 0x170),
                               (LPDWORD)((longlong)&param_12 + 4));
      if (LVar7 == 0) {
        param_11._4_4_ = 0x18;
        uVar13 = (ulonglong)unaff_R12 & 0xffffffff;
        iVar8 = RegEnumKeyExA(*(HKEY *)(unaff_RBP + -0x68 +
                                       (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x68) + 4)),0,
                              (LPSTR)(unaff_RBP + 0x40),(LPDWORD)((longlong)&param_11 + 4),
                              &unaff_R12->nLength,(LPSTR)unaff_R12,&unaff_R12->nLength,
                              (PFILETIME)(unaff_RBP + -0x38));
        uVar12 = dwOptions;
        iVar6 = -1;
        while (iVar8 == 0) {
          *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x80) = unaff_R12;
          *(DWORD *)(unaff_RBP + -0x78) = dwOptions;
          uVar12 = (int)uVar13 + 1;
          uVar13 = (ulonglong)uVar12;
          *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x70) = unaff_R12;
          param_15 = unaff_R13;
          LVar7 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + -0x68 +
                                         (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x68) + 4)),
                                (LPCSTR)(unaff_RBP + 0x40),0,0x20019,(PHKEY)(unaff_RBP + -0x80));
          if (LVar7 == 0) {
            param_11._0_4_ = 0x100;
            LVar7 = RegQueryValueExA(*(HKEY *)((longlong)&stack0x00000078 +
                                              (longlong)*(int *)(param_15 + 4)),"Display Name",
                                     (LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)(unaff_RBP + 0x70),
                                     (LPDWORD)&param_11);
            if (LVar7 == 0) {
              pcVar10 = (char *)(unaff_RBP + 0x170);
              lVar15 = (unaff_RBP + 0x70) - (longlong)pcVar10;
              do {
                cVar1 = *pcVar10;
                cVar2 = pcVar10[lVar15];
                if (cVar1 != cVar2) break;
                pcVar10 = pcVar10 + 1;
              } while (cVar2 != '\0');
              if (cVar1 == cVar2) {
                DVar14 = unaff_R14D;
                if (*(HKEY *)(unaff_RBP + -0x80) != (HKEY)0x0) {
                  RegCloseKey(*(HKEY *)(unaff_RBP + -0x80));
                }
                goto LAB_180036e33;
              }
            }
          }
          iVar9 = atoi((char *)(unaff_RBP + 0x40));
          param_11._4_4_ = 0x18;
          if (iVar9 < iVar6) {
            iVar9 = iVar6;
          }
          if (*(HKEY *)(unaff_RBP + -0x80) != (HKEY)0x0) {
            RegCloseKey(*(HKEY *)(unaff_RBP + -0x80));
          }
          iVar8 = RegEnumKeyExA(*(HKEY *)(unaff_RBP + -0x68 +
                                         (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x68) + 4)),
                                uVar12,(LPSTR)(unaff_RBP + 0x40),(LPDWORD)((longlong)&param_11 + 4),
                                &unaff_R12->nLength,(LPSTR)unaff_R12,&unaff_R12->nLength,
                                (PFILETIME)(unaff_RBP + -0x38));
          iVar6 = iVar9;
        }
        uVar12 = uVar12 + 1;
        DVar14 = dwOptions;
LAB_180036e33:
        if (DVar14 == 0) {
          _Value = iVar6 + 1;
          if (iVar6 < (int)uVar12) {
            _Value = uVar12;
          }
          _itoa(_Value,(char *)(unaff_RBP + 0x40),10);
          *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x80) = unaff_R12;
          *(DWORD *)(unaff_RBP + -0x78) = dwOptions;
          *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x70) = unaff_R12;
          param_15 = unaff_R13;
          LVar7 = RegCreateKeyExA(*(HKEY *)(unaff_RBP + -0x68 +
                                           (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x68) + 4))
                                  ,(LPCSTR)(unaff_RBP + 0x40),0,(LPSTR)0x0,dwOptions,0xf003f,
                                  unaff_R12,(PHKEY)(unaff_RBP + -0x80),(LPDWORD)(unaff_RBP + 0x14));
          if (LVar7 == 0) {
            param_10 = 0x100;
            param_11._0_4_ = dwOptions;
            LVar7 = RegQueryValueExA(*(HKEY *)(unaff_RBP + -0x30 +
                                              (longlong)
                                              *(int *)(*(longlong *)(unaff_RBP + -0x30) + 4)),
                                     "Display Name",(LPDWORD)0x0,(LPDWORD)(unaff_RBP + -0x48),
                                     (LPBYTE)(unaff_RBP + 0x70),&param_10);
            if ((LVar7 == 0) && (*(int *)(unaff_RBP + -0x48) - 1U <= unaff_R14D)) {
              if (param_10 == 0) {
                *(char *)(unaff_RBP + 0x70) = cVar16;
              }
              else if (*(char *)(unaff_RBP + 0x6f + (ulonglong)param_10) != cVar16)
              goto LAB_180036f80;
              param_11._0_4_ = param_10;
              lVar15 = -1;
              do {
                lVar15 = lVar15 + 1;
              } while (*(char *)(unaff_RBP + 0x70 + lVar15) != cVar16);
              RegSetValueExA(*(HKEY *)((longlong)&stack0x00000078 + (longlong)*(int *)(param_15 + 4)
                                      ),"Display Name",0,unaff_R14D,(BYTE *)(unaff_RBP + 0x70),
                             (int)lVar15 + 1);
            }
LAB_180036f80:
            param_10 = 0x100;
            param_11._0_4_ = dwOptions;
            LVar7 = RegQueryValueExA(*(HKEY *)(unaff_RBP + -0x30 +
                                              (longlong)
                                              *(int *)(*(longlong *)(unaff_RBP + -0x30) + 4)),"Path"
                                     ,(LPDWORD)0x0,(LPDWORD)(unaff_RBP + -0x44),
                                     (LPBYTE)(unaff_RBP + 0x70),&param_10);
            if ((LVar7 == 0) && (*(int *)(unaff_RBP + -0x44) - 1U <= unaff_R14D)) {
              if (param_10 == 0) {
                *(char *)(unaff_RBP + 0x70) = cVar16;
              }
              else if (*(char *)(unaff_RBP + 0x6f + (ulonglong)param_10) != cVar16)
              goto LAB_180037034;
              param_11._0_4_ = param_10;
              lVar15 = -1;
              do {
                lVar15 = lVar15 + 1;
              } while (*(char *)(unaff_RBP + 0x70 + lVar15) != cVar16);
              RegSetValueExA(*(HKEY *)((longlong)&stack0x00000078 + (longlong)*(int *)(param_15 + 4)
                                      ),"Path",0,unaff_R14D,(BYTE *)(unaff_RBP + 0x70),
                             (int)lVar15 + 1);
            }
LAB_180037034:
            param_10 = 4;
            LVar7 = RegQueryValueExA(*(HKEY *)(unaff_RBP + -0x30 +
                                              (longlong)
                                              *(int *)(*(longlong *)(unaff_RBP + -0x30) + 4)),
                                     "Position",(LPDWORD)0x0,(LPDWORD)(unaff_RBP + -0x40),
                                     (LPBYTE)&param_13,&param_10);
            DVar14 = dwOptions;
            if ((LVar7 == 0) && (*(int *)(unaff_RBP + -0x40) == 4)) {
              DVar14 = (DWORD)param_13;
            }
            param_13._0_4_ = DVar14;
            param_10 = (DWORD)param_13;
            RegSetValueExA(*(HKEY *)((longlong)&stack0x00000078 + (longlong)*(int *)(param_15 + 4)),
                           "Position",0,4,(BYTE *)&param_10,4);
            param_10 = 4;
            LVar7 = RegQueryValueExA(*(HKEY *)(unaff_RBP + -0x30 +
                                              (longlong)
                                              *(int *)(*(longlong *)(unaff_RBP + -0x30) + 4)),
                                     "Active",(LPDWORD)0x0,&param_14,
                                     (LPBYTE)((longlong)&param_13 + 4),&param_10);
            DVar14 = dwOptions;
            if ((LVar7 == 0) && (param_14 == 4)) {
              DVar14 = param_13._4_4_;
            }
            param_13._4_4_ = DVar14;
            param_10 = param_13._4_4_;
            RegSetValueExA(*(HKEY *)((longlong)&stack0x00000078 + (longlong)*(int *)(param_15 + 4)),
                           "Active",0,4,(BYTE *)&param_10,4);
          }
          if (*(HKEY *)(unaff_RBP + -0x80) != (HKEY)0x0) {
            RegCloseKey(*(HKEY *)(unaff_RBP + -0x80));
          }
        }
      }
    }
    uVar12 = (int)uVar17 + 1;
    uVar17 = (ulonglong)uVar12;
    param_12._0_4_ = 0x18;
    if (*(HKEY *)(unaff_RBP + -0x28) != (HKEY)0x0) {
      RegCloseKey(*(HKEY *)(unaff_RBP + -0x28));
    }
    iVar6 = RegEnumKeyExA(*(HKEY *)(unaff_RBP + -0x10 +
                                   (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x10) + 4)),uVar12,
                          (LPSTR)(unaff_RBP + 0x58),(LPDWORD)&param_12,&unaff_R12->nLength,
                          (LPSTR)unaff_R12,&unaff_R12->nLength,(PFILETIME)(unaff_RBP + -0x38));
  } while( true );
}

/* ---- FUNC 00036C33 FUN_180036c33 (1431 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_180036c33(void)

{
  char cVar1;
  char cVar2;
  void *pvVar3;
  uint _Value;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  LSTATUS LVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  void *pvVar11;
  uint dwIndex;
  ulonglong uVar12;
  longlong unaff_RBP;
  DWORD DVar13;
  longlong lVar14;
  char cVar15;
  DWORD dwOptions;
  LPSECURITY_ATTRIBUTES unaff_R12;
  longlong unaff_R13;
  uint unaff_R14D;
  DWORD unaff_R15D;
  DWORD in_stack_00000050;
  DWORD DStack0000000000000058;
  undefined4 uStack000000000000005c;
  DWORD DStack0000000000000060;
  undefined4 uStack0000000000000064;
  DWORD DStack0000000000000068;
  DWORD DStack000000000000006c;
  DWORD in_stack_00000070;
  longlong in_stack_00000078;
  
  do {
    *(longlong *)(unaff_RBP + -0x30) = unaff_R13;
    *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x28) = unaff_R12;
    dwOptions = (DWORD)unaff_R12;
    *(DWORD *)(unaff_RBP + -0x20) = dwOptions;
    *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x18) = unaff_R12;
    LVar7 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + -0x10 +
                                   (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x10) + 4)),
                          (LPCSTR)(unaff_RBP + 0x58),0,0x20019,(PHKEY)(unaff_RBP + -0x28));
    cVar15 = (char)unaff_R12;
    if (LVar7 == 0) {
      uStack0000000000000064 = 0x100;
      LVar7 = RegQueryValueExA(*(HKEY *)(unaff_RBP + -0x30 +
                                        (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x30) + 4)),
                               "Display Name",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)(unaff_RBP + 0x170),
                               (LPDWORD)((longlong)&stack0x00000060 + 4));
      if (LVar7 == 0) {
        uStack000000000000005c = 0x18;
        uVar12 = (ulonglong)unaff_R12 & 0xffffffff;
        iVar8 = RegEnumKeyExA(*(HKEY *)(unaff_RBP + -0x68 +
                                       (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x68) + 4)),0,
                              (LPSTR)(unaff_RBP + 0x40),(LPDWORD)((longlong)&stack0x00000058 + 4),
                              &unaff_R12->nLength,(LPSTR)unaff_R12,&unaff_R12->nLength,
                              (PFILETIME)(unaff_RBP + -0x38));
        dwIndex = dwOptions;
        iVar4 = -1;
        while (iVar8 == 0) {
          *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x80) = unaff_R12;
          *(DWORD *)(unaff_RBP + -0x78) = dwOptions;
          dwIndex = (int)uVar12 + 1;
          uVar12 = (ulonglong)dwIndex;
          *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x70) = unaff_R12;
          in_stack_00000078 = unaff_R13;
          LVar7 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + -0x68 +
                                         (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x68) + 4)),
                                (LPCSTR)(unaff_RBP + 0x40),0,0x20019,(PHKEY)(unaff_RBP + -0x80));
          if (LVar7 == 0) {
            DStack0000000000000058 = 0x100;
            LVar7 = RegQueryValueExA(*(HKEY *)((longlong)&stack0x00000078 +
                                              (longlong)*(int *)(in_stack_00000078 + 4)),
                                     "Display Name",(LPDWORD)0x0,(LPDWORD)0x0,
                                     (LPBYTE)(unaff_RBP + 0x70),&stack0x00000058);
            if (LVar7 == 0) {
              pcVar10 = (char *)(unaff_RBP + 0x170);
              lVar14 = (unaff_RBP + 0x70) - (longlong)pcVar10;
              do {
                cVar1 = *pcVar10;
                cVar2 = pcVar10[lVar14];
                if (cVar1 != cVar2) break;
                pcVar10 = pcVar10 + 1;
              } while (cVar2 != '\0');
              if (cVar1 == cVar2) {
                DVar13 = unaff_R14D;
                if (*(HKEY *)(unaff_RBP + -0x80) != (HKEY)0x0) {
                  RegCloseKey(*(HKEY *)(unaff_RBP + -0x80));
                }
                goto LAB_180036e33;
              }
            }
          }
          iVar9 = atoi((char *)(unaff_RBP + 0x40));
          uStack000000000000005c = 0x18;
          if (iVar9 < iVar4) {
            iVar9 = iVar4;
          }
          if (*(HKEY *)(unaff_RBP + -0x80) != (HKEY)0x0) {
            RegCloseKey(*(HKEY *)(unaff_RBP + -0x80));
          }
          iVar8 = RegEnumKeyExA(*(HKEY *)(unaff_RBP + -0x68 +
                                         (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x68) + 4)),
                                dwIndex,(LPSTR)(unaff_RBP + 0x40),
                                (LPDWORD)((longlong)&stack0x00000058 + 4),&unaff_R12->nLength,
                                (LPSTR)unaff_R12,&unaff_R12->nLength,(PFILETIME)(unaff_RBP + -0x38))
          ;
          iVar4 = iVar9;
        }
        dwIndex = dwIndex + 1;
        DVar13 = dwOptions;
LAB_180036e33:
        if (DVar13 == 0) {
          _Value = iVar4 + 1;
          if (iVar4 < (int)dwIndex) {
            _Value = dwIndex;
          }
          _itoa(_Value,(char *)(unaff_RBP + 0x40),10);
          *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x80) = unaff_R12;
          *(DWORD *)(unaff_RBP + -0x78) = dwOptions;
          *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x70) = unaff_R12;
          in_stack_00000078 = unaff_R13;
          LVar7 = RegCreateKeyExA(*(HKEY *)(unaff_RBP + -0x68 +
                                           (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x68) + 4))
                                  ,(LPCSTR)(unaff_RBP + 0x40),0,(LPSTR)0x0,dwOptions,0xf003f,
                                  unaff_R12,(PHKEY)(unaff_RBP + -0x80),(LPDWORD)(unaff_RBP + 0x14));
          if (LVar7 == 0) {
            in_stack_00000050 = 0x100;
            DStack0000000000000058 = dwOptions;
            LVar7 = RegQueryValueExA(*(HKEY *)(unaff_RBP + -0x30 +
                                              (longlong)
                                              *(int *)(*(longlong *)(unaff_RBP + -0x30) + 4)),
                                     "Display Name",(LPDWORD)0x0,(LPDWORD)(unaff_RBP + -0x48),
                                     (LPBYTE)(unaff_RBP + 0x70),&stack0x00000050);
            if ((LVar7 == 0) && (*(int *)(unaff_RBP + -0x48) - 1U <= unaff_R14D)) {
              if (in_stack_00000050 == 0) {
                *(char *)(unaff_RBP + 0x70) = cVar15;
              }
              else if (*(char *)(unaff_RBP + 0x6f + (ulonglong)in_stack_00000050) != cVar15)
              goto LAB_180036f80;
              DStack0000000000000058 = in_stack_00000050;
              lVar14 = -1;
              do {
                lVar14 = lVar14 + 1;
              } while (*(char *)(unaff_RBP + 0x70 + lVar14) != cVar15);
              RegSetValueExA(*(HKEY *)((longlong)&stack0x00000078 +
                                      (longlong)*(int *)(in_stack_00000078 + 4)),"Display Name",0,
                             unaff_R14D,(BYTE *)(unaff_RBP + 0x70),(int)lVar14 + 1);
            }
LAB_180036f80:
            in_stack_00000050 = 0x100;
            DStack0000000000000058 = dwOptions;
            LVar7 = RegQueryValueExA(*(HKEY *)(unaff_RBP + -0x30 +
                                              (longlong)
                                              *(int *)(*(longlong *)(unaff_RBP + -0x30) + 4)),"Path"
                                     ,(LPDWORD)0x0,(LPDWORD)(unaff_RBP + -0x44),
                                     (LPBYTE)(unaff_RBP + 0x70),&stack0x00000050);
            if ((LVar7 == 0) && (*(int *)(unaff_RBP + -0x44) - 1U <= unaff_R14D)) {
              if (in_stack_00000050 == 0) {
                *(char *)(unaff_RBP + 0x70) = cVar15;
              }
              else if (*(char *)(unaff_RBP + 0x6f + (ulonglong)in_stack_00000050) != cVar15)
              goto LAB_180037034;
              DStack0000000000000058 = in_stack_00000050;
              lVar14 = -1;
              do {
                lVar14 = lVar14 + 1;
              } while (*(char *)(unaff_RBP + 0x70 + lVar14) != cVar15);
              RegSetValueExA(*(HKEY *)((longlong)&stack0x00000078 +
                                      (longlong)*(int *)(in_stack_00000078 + 4)),"Path",0,unaff_R14D
                             ,(BYTE *)(unaff_RBP + 0x70),(int)lVar14 + 1);
            }
LAB_180037034:
            in_stack_00000050 = 4;
            LVar7 = RegQueryValueExA(*(HKEY *)(unaff_RBP + -0x30 +
                                              (longlong)
                                              *(int *)(*(longlong *)(unaff_RBP + -0x30) + 4)),
                                     "Position",(LPDWORD)0x0,(LPDWORD)(unaff_RBP + -0x40),
                                     (LPBYTE)&stack0x00000068,&stack0x00000050);
            DVar13 = dwOptions;
            if ((LVar7 == 0) && (*(int *)(unaff_RBP + -0x40) == 4)) {
              DVar13 = DStack0000000000000068;
            }
            DStack0000000000000068 = DVar13;
            in_stack_00000050 = DStack0000000000000068;
            RegSetValueExA(*(HKEY *)((longlong)&stack0x00000078 +
                                    (longlong)*(int *)(in_stack_00000078 + 4)),"Position",0,4,
                           (BYTE *)&stack0x00000050,4);
            in_stack_00000050 = 4;
            LVar7 = RegQueryValueExA(*(HKEY *)(unaff_RBP + -0x30 +
                                              (longlong)
                                              *(int *)(*(longlong *)(unaff_RBP + -0x30) + 4)),
                                     "Active",(LPDWORD)0x0,&stack0x00000070,
                                     (LPBYTE)((longlong)&stack0x00000068 + 4),&stack0x00000050);
            DVar13 = dwOptions;
            if ((LVar7 == 0) && (in_stack_00000070 == 4)) {
              DVar13 = DStack000000000000006c;
            }
            DStack000000000000006c = DVar13;
            in_stack_00000050 = DStack000000000000006c;
            RegSetValueExA(*(HKEY *)((longlong)&stack0x00000078 +
                                    (longlong)*(int *)(in_stack_00000078 + 4)),"Active",0,4,
                           (BYTE *)&stack0x00000050,4);
          }
          if (*(HKEY *)(unaff_RBP + -0x80) != (HKEY)0x0) {
            RegCloseKey(*(HKEY *)(unaff_RBP + -0x80));
          }
        }
      }
    }
    unaff_R15D = unaff_R15D + 1;
    DStack0000000000000060 = 0x18;
    if (*(HKEY *)(unaff_RBP + -0x28) != (HKEY)0x0) {
      RegCloseKey(*(HKEY *)(unaff_RBP + -0x28));
    }
    LVar7 = RegEnumKeyExA(*(HKEY *)(unaff_RBP + -0x10 +
                                   (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x10) + 4)),
                          unaff_R15D,(LPSTR)(unaff_RBP + 0x58),&stack0x00000060,&unaff_R12->nLength,
                          (LPSTR)unaff_R12,&unaff_R12->nLength,(PFILETIME)(unaff_RBP + -0x38));
    if (LVar7 != 0) {
      if (0xf < *(ulonglong *)(unaff_RBP + 0x38)) {
        pvVar3 = *(void **)(unaff_RBP + 0x20);
        pvVar11 = pvVar3;
        if ((0xfff < *(ulonglong *)(unaff_RBP + 0x38) + 1) &&
           (pvVar11 = *(void **)((longlong)pvVar3 + -8),
           0x1f < (ulonglong)((longlong)pvVar3 + (-8 - (longlong)pvVar11)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        operator_delete(pvVar11);
      }
      uVar6 = _UNK_180053828;
      uVar5 = _DAT_180053820;
      *(char *)(unaff_RBP + 0x20) = cVar15;
      *(undefined8 *)(unaff_RBP + 0x30) = uVar5;
      *(undefined8 *)(unaff_RBP + 0x38) = uVar6;
      if (*(HKEY *)(unaff_RBP + -0x60) != (HKEY)0x0) {
        RegCloseKey(*(HKEY *)(unaff_RBP + -0x60));
        *(LPSECURITY_ATTRIBUTES *)(unaff_RBP + -0x60) = unaff_R12;
      }
      *(DWORD *)(unaff_RBP + -0x58) = dwOptions;
      if (*(HKEY *)(unaff_RBP + -8) != (HKEY)0x0) {
        RegCloseKey(*(HKEY *)(unaff_RBP + -8));
      }
      return unaff_R14D;
    }
  } while( true );
}

/* ---- FUNC 000371CA FUN_1800371ca (10 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1800371ca(void)

{
  void *pvVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  void *pvVar4;
  longlong unaff_RBP;
  undefined8 unaff_R12;
  undefined4 unaff_R14D;
  
  if (0xf < *(ulonglong *)(unaff_RBP + 0x38)) {
    pvVar1 = *(void **)(unaff_RBP + 0x20);
    pvVar4 = pvVar1;
    if ((0xfff < *(ulonglong *)(unaff_RBP + 0x38) + 1) &&
       (pvVar4 = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar4)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar4);
  }
  uVar3 = _UNK_180053828;
  uVar2 = _DAT_180053820;
  *(char *)(unaff_RBP + 0x20) = (char)unaff_R12;
  *(undefined8 *)(unaff_RBP + 0x30) = uVar2;
  *(undefined8 *)(unaff_RBP + 0x38) = uVar3;
  if (*(HKEY *)(unaff_RBP + -0x60) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x60));
    *(undefined8 *)(unaff_RBP + -0x60) = unaff_R12;
  }
  *(int *)(unaff_RBP + -0x58) = (int)unaff_R12;
  if (*(HKEY *)(unaff_RBP + -8) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -8));
  }
  return unaff_R14D;
}

/* ---- FUNC 000371D4 FUN_1800371d4 (29 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_1800371d4(void)

{
  void *pvVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  void *pvVar4;
  longlong unaff_RBP;
  ulonglong unaff_R12;
  
  if (0xf < *(ulonglong *)(unaff_RBP + 0x38)) {
    pvVar1 = *(void **)(unaff_RBP + 0x20);
    pvVar4 = pvVar1;
    if ((0xfff < *(ulonglong *)(unaff_RBP + 0x38) + 1) &&
       (pvVar4 = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar4)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar4);
  }
  uVar3 = _UNK_180053828;
  uVar2 = _DAT_180053820;
  *(char *)(unaff_RBP + 0x20) = (char)unaff_R12;
  *(undefined8 *)(unaff_RBP + 0x30) = uVar2;
  *(undefined8 *)(unaff_RBP + 0x38) = uVar3;
  if (*(HKEY *)(unaff_RBP + -0x60) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x60));
    *(ulonglong *)(unaff_RBP + -0x60) = unaff_R12;
  }
  *(int *)(unaff_RBP + -0x58) = (int)unaff_R12;
  if (*(HKEY *)(unaff_RBP + -8) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -8));
  }
  return unaff_R12 & 0xffffffff;
}

/* ---- FUNC 000371F1 FUN_1800371f1 (138 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1800371f1(undefined8 param_1,longlong param_2)

{
  void *pvVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  void *pvVar4;
  longlong unaff_RBP;
  undefined8 unaff_R12;
  undefined4 unaff_R14D;
  
  pvVar1 = *(void **)(unaff_RBP + 0x20);
  pvVar4 = pvVar1;
  if ((0xfff < param_2 + 1U) &&
     (pvVar4 = *(void **)((longlong)pvVar1 + -8),
     0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar4)))) {
                    /* WARNING: Subroutine does not return */
    _invalid_parameter_noinfo_noreturn();
  }
  operator_delete(pvVar4);
  uVar3 = _UNK_180053828;
  uVar2 = _DAT_180053820;
  *(char *)(unaff_RBP + 0x20) = (char)unaff_R12;
  *(undefined8 *)(unaff_RBP + 0x30) = uVar2;
  *(undefined8 *)(unaff_RBP + 0x38) = uVar3;
  if (*(HKEY *)(unaff_RBP + -0x60) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x60));
    *(undefined8 *)(unaff_RBP + -0x60) = unaff_R12;
  }
  *(int *)(unaff_RBP + -0x58) = (int)unaff_R12;
  if (*(HKEY *)(unaff_RBP + -8) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -8));
  }
  return unaff_R14D;
}

/* ---- FUNC 00037280 APModLibUnregisterLib (55 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 APModLibUnregisterLib(longlong param_1)

{
  BYTE BVar1;
  BYTE BVar2;
  longlong *plVar3;
  LSTATUS LVar4;
  int iVar5;
  LPCSTR lpSubKey;
  BYTE *pBVar6;
  HMODULE pHVar7;
  FARPROC pFVar8;
  HKEY pHVar9;
  DWORD dwIndex;
  longlong lVar10;
  undefined4 unaff_R14D;
  undefined1 auStackY_548 [32];
  CHAR local_508 [4];
  DWORD local_504;
  DWORD local_500 [2];
  HKEY local_4f8;
  HKEY local_4f0;
  undefined4 local_4e8 [2];
  undefined8 local_4e0;
  HKEY local_4d8 [2];
  undefined4 local_4c8;
  undefined8 local_4c0;
  HKEY local_4b8 [2];
  undefined4 local_4a8;
  undefined8 local_4a0;
  HKEY local_498 [2];
  undefined4 local_488;
  undefined8 local_480;
  HKEY local_478 [2];
  undefined4 local_468;
  undefined8 local_460;
  _FILETIME local_458;
  HKEY local_450 [2];
  undefined4 local_440;
  undefined8 local_438;
  BYTE local_428 [1024];
  ulonglong local_28;
  
                    /* 0x37280  272  APModLibUnregisterLib */
  local_28 = DAT_1800791f8 ^ (ulonglong)auStackY_548;
  dwIndex = 0;
  if (param_1 != 0) {
    local_450[0] = (HKEY)&DAT_180053988;
    local_498[0] = (HKEY)&DAT_180053988;
    local_4b8[0] = (HKEY)&DAT_180053988;
    local_4d8[0] = (HKEY)&DAT_180053988;
    local_4f8 = (HKEY)&DAT_180053988;
    local_450[1] = (HKEY)0x0;
    local_440 = 0;
    local_438 = 0;
    local_498[1] = (HKEY)0x0;
    local_488 = 0;
    local_480 = 0;
    local_4b8[1] = (HKEY)0x0;
    local_4a8 = 0;
    local_4a0 = 0;
    local_4d8[1] = (HKEY)0x0;
    local_4c8 = 0;
    local_4c0 = 0;
    local_4f0 = (HKEY)0x0;
    local_4e8[0] = 0;
    local_4e0 = 0;
    LVar4 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000001,"Software",0,0xf003f,local_450 + 1);
    if (((LVar4 == 0) &&
        (LVar4 = RegOpenKeyExA(*(HKEY *)((longlong)local_450 + (longlong)local_450[0][1].unused),
                               "AspenTech",0,0xf003f,
                               (PHKEY)((longlong)local_498 + (longlong)local_498[0][1].unused)),
        LVar4 == 0)) &&
       (LVar4 = RegOpenKeyExA(*(HKEY *)((longlong)local_498 + (longlong)local_498[0][1].unused),
                              "ASPEN PLUS",0,0xf003f,
                              (PHKEY)((longlong)local_4b8 + (longlong)local_4b8[0][1].unused)),
       LVar4 == 0)) {
      pHVar9 = *(HKEY *)((longlong)local_4b8 + (longlong)local_4b8[0][1].unused);
      iVar5 = local_4d8[0][1].unused;
      lpSubKey = (LPCSTR)FUN_180024170();
      LVar4 = RegOpenKeyExA(pHVar9,lpSubKey,0,0xf003f,(PHKEY)((longlong)local_4d8 + (longlong)iVar5)
                           );
      if ((LVar4 == 0) &&
         (LVar4 = RegOpenKeyExA(*(HKEY *)((longlong)local_4d8 + (longlong)local_4d8[0][1].unused),
                                "Libraries",0,0xf003f,
                                (PHKEY)((longlong)&local_4f8 + (longlong)local_4f8[1].unused)),
         LVar4 == 0)) {
        local_500[0] = 0x400;
        local_504 = 4;
        iVar5 = RegEnumKeyExA(*(HKEY *)((longlong)&local_4f8 + (longlong)local_4f8[1].unused),0,
                              local_508,&local_504,(LPDWORD)0x0,(LPSTR)0x0,(LPDWORD)0x0,&local_458);
        while (iVar5 == 0) {
          local_478[0] = (HKEY)&DAT_180053988;
          local_478[1] = (HKEY)0x0;
          local_468 = 0;
          local_460 = 0;
          LVar4 = RegOpenKeyExA(*(HKEY *)((longlong)&local_4f8 + (longlong)local_4f8[1].unused),
                                local_508,0,0xf003f,local_478 + 1);
          if (LVar4 == 0) {
            local_500[0] = 0x400;
            LVar4 = RegQueryValueExA(*(HKEY *)((longlong)local_478 +
                                              (longlong)local_478[0][1].unused),"Display Name",
                                     (LPDWORD)0x0,(LPDWORD)0x0,local_428,local_500);
            if (LVar4 == 0) {
              pBVar6 = local_428;
              lVar10 = param_1 - (longlong)pBVar6;
              do {
                BVar1 = *pBVar6;
                BVar2 = pBVar6[lVar10];
                if (BVar1 != BVar2) break;
                pBVar6 = pBVar6 + 1;
              } while (BVar2 != '\0');
              if (BVar1 == BVar2) {
                if (local_478[1] != (HKEY)0x0) {
                  RegCloseKey(local_478[1]);
                }
                lVar10 = (longlong)local_4f8[1].unused;
                plVar3 = *(longlong **)((longlong)local_4e8 + lVar10);
                if (plVar3 == (longlong *)0x0) {
                  if (DAT_18007b7b0 == '\0') {
                    pHVar7 = GetModuleHandleA("Advapi32.dll");
                    if (pHVar7 == (HMODULE)0x0) {
                      DAT_18007b7b0 = '\x01';
                    }
                    else {
                      DAT_18007b7a8 = GetProcAddress(pHVar7,"RegDeleteKeyExA");
                      DAT_18007b7b0 = '\x01';
                    }
                  }
                  pHVar9 = *(HKEY *)((longlong)&local_4f8 + lVar10);
                  if (DAT_18007b7a8 != (FARPROC)0x0) {
                    (*DAT_18007b7a8)(pHVar9,local_508,
                                     (ulonglong)*(uint *)((longlong)local_4e8 + lVar10 + -8),0);
                    break;
                  }
                }
                else {
                  pHVar9 = *(HKEY *)((longlong)&local_4f8 + lVar10);
                  if (*plVar3 != 0) {
                    pHVar7 = GetModuleHandleA("Advapi32.dll");
                    if ((pHVar7 != (HMODULE)0x0) &&
                       (pFVar8 = GetProcAddress(pHVar7,"RegDeleteKeyTransactedA"),
                       pFVar8 != (FARPROC)0x0)) {
                      (*pFVar8)(pHVar9,local_508,0,0);
                    }
                    break;
                  }
                  if ((int)plVar3[1] == 0) break;
                }
                RegDeleteKeyA(pHVar9,local_508);
                break;
              }
            }
          }
          dwIndex = dwIndex + 1;
          local_504 = 4;
          if (local_478[1] != (HKEY)0x0) {
            RegCloseKey(local_478[1]);
          }
          iVar5 = RegEnumKeyExA(*(HKEY *)((longlong)&local_4f8 + (longlong)local_4f8[1].unused),
                                dwIndex,local_508,&local_504,(LPDWORD)0x0,(LPSTR)0x0,(LPDWORD)0x0,
                                &local_458);
        }
      }
    }
    if (local_4f0 != (HKEY)0x0) {
      RegCloseKey(local_4f0);
      local_4f0 = (HKEY)0x0;
    }
    local_4e8[0] = 0;
    if (local_4d8[1] != (HKEY)0x0) {
      RegCloseKey(local_4d8[1]);
      local_4d8[1] = (HKEY)0x0;
    }
    local_4c8 = 0;
    if (local_4b8[1] != (HKEY)0x0) {
      RegCloseKey(local_4b8[1]);
      local_4b8[1] = (HKEY)0x0;
    }
    local_4a8 = 0;
    if (local_498[1] != (HKEY)0x0) {
      RegCloseKey(local_498[1]);
      local_498[1] = (HKEY)0x0;
    }
    local_488 = 0;
    if (local_450[1] != (HKEY)0x0) {
      RegCloseKey(local_450[1]);
    }
  }
  return unaff_R14D;
}

/* ---- FUNC 000372B7 FUN_1800372b7 (1083 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_1800372b7(void)

{
  char cVar1;
  char cVar2;
  longlong *plVar3;
  LSTATUS LVar4;
  int iVar5;
  LPCSTR lpSubKey;
  PHKEY ppHVar6;
  HMODULE pHVar7;
  FARPROC pFVar8;
  HKEY pHVar9;
  uint dwIndex;
  ulonglong uVar10;
  PHKEY unaff_RBP;
  longlong unaff_RSI;
  longlong lVar11;
  ulonglong uVar12;
  int iVar13;
  HKEY unaff_R15;
  undefined8 in_stack_00000040;
  DWORD in_stack_00000048;
  undefined *puStack0000000000000050;
  int iStack0000000000000060;
  undefined *puStack0000000000000070;
  
  unaff_RBP[-1] = (HKEY)&DAT_180053988;
  unaff_RBP[-10] = (HKEY)&DAT_180053988;
  unaff_RBP[-0xe] = (HKEY)&DAT_180053988;
  puStack0000000000000070 = &DAT_180053988;
  puStack0000000000000050 = &DAT_180053988;
  *unaff_RBP = unaff_R15;
  iVar13 = (int)unaff_R15;
  *(int *)(unaff_RBP + 1) = iVar13;
  unaff_RBP[2] = unaff_R15;
  unaff_RBP[-9] = unaff_R15;
  *(int *)(unaff_RBP + -8) = iVar13;
  unaff_RBP[-7] = unaff_R15;
  unaff_RBP[-0xd] = unaff_R15;
  *(int *)(unaff_RBP + -0xc) = iVar13;
  unaff_RBP[-0xb] = unaff_R15;
  *(int *)(unaff_RBP + -0x10) = iVar13;
  unaff_RBP[-0xf] = unaff_R15;
  iStack0000000000000060 = iVar13;
  LVar4 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000001,"Software",0,0xf003f,unaff_RBP);
  if (((LVar4 == 0) &&
      (LVar4 = RegOpenKeyExA(*(HKEY *)((longlong)unaff_RBP + (longlong)unaff_RBP[-1][1].unused + -8)
                             ,"AspenTech",0,0xf003f,
                             (PHKEY)((longlong)unaff_RBP +
                                    (longlong)unaff_RBP[-10][1].unused + -0x50)), LVar4 == 0)) &&
     (LVar4 = RegOpenKeyExA(*(HKEY *)((longlong)unaff_RBP +
                                     (longlong)unaff_RBP[-10][1].unused + -0x50),"ASPEN PLUS",0,
                            0xf003f,(PHKEY)((longlong)unaff_RBP +
                                           (longlong)unaff_RBP[-0xe][1].unused + -0x70)), LVar4 == 0
     )) {
    pHVar9 = *(HKEY *)((longlong)unaff_RBP + (longlong)unaff_RBP[-0xe][1].unused + -0x70);
    iVar5 = *(int *)(puStack0000000000000070 + 4);
    lpSubKey = (LPCSTR)FUN_180024170();
    LVar4 = RegOpenKeyExA(pHVar9,lpSubKey,0,0xf003f,
                          (PHKEY)((longlong)&stack0x00000070 + (longlong)iVar5));
    if ((LVar4 == 0) &&
       (LVar4 = RegOpenKeyExA(*(HKEY *)((longlong)&stack0x00000070 +
                                       (longlong)*(int *)(puStack0000000000000070 + 4)),"Libraries",
                              0,0xf003f,
                              (PHKEY)((longlong)&stack0x00000050 +
                                     (longlong)*(int *)(puStack0000000000000050 + 4))), LVar4 == 0))
    {
      in_stack_00000048 = 0x400;
      in_stack_00000040._4_4_ = 4;
      uVar10 = (ulonglong)unaff_R15 & 0xffffffff;
      uVar12 = (ulonglong)unaff_R15 & 0xffffffff;
      iVar5 = RegEnumKeyExA(*(HKEY *)((longlong)&stack0x00000050 +
                                     (longlong)*(int *)(puStack0000000000000050 + 4)),0,
                            (LPSTR)&stack0x00000040,(LPDWORD)((longlong)&stack0x00000040 + 4),
                            (LPDWORD)unaff_R15,(LPSTR)unaff_R15,(LPDWORD)unaff_R15,
                            (PFILETIME)(unaff_RBP + -2));
      while (iVar5 == 0) {
        unaff_RBP[-6] = (HKEY)&DAT_180053988;
        unaff_RBP[-5] = unaff_R15;
        *(int *)(unaff_RBP + -4) = iVar13;
        unaff_RBP[-3] = unaff_R15;
        LVar4 = RegOpenKeyExA(*(HKEY *)((longlong)&stack0x00000050 +
                                       (longlong)*(int *)(puStack0000000000000050 + 4)),
                              (LPCSTR)&stack0x00000040,0,0xf003f,unaff_RBP + -5);
        if (LVar4 == 0) {
          in_stack_00000048 = 0x400;
          LVar4 = RegQueryValueExA(*(HKEY *)((longlong)unaff_RBP +
                                            (longlong)unaff_RBP[-6][1].unused + -0x30),
                                   "Display Name",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)(unaff_RBP + 4),
                                   &stack0x00000048);
          if (LVar4 == 0) {
            ppHVar6 = unaff_RBP + 4;
            lVar11 = unaff_RSI - (longlong)ppHVar6;
            do {
              cVar1 = *(char *)ppHVar6;
              cVar2 = *(char *)((longlong)ppHVar6 + lVar11);
              if (cVar1 != cVar2) break;
              ppHVar6 = (PHKEY)((longlong)ppHVar6 + 1);
            } while (cVar2 != '\0');
            if (cVar1 == cVar2) {
              uVar12 = 1;
              if (unaff_RBP[-5] != (HKEY)0x0) {
                RegCloseKey(unaff_RBP[-5]);
              }
              iVar5 = *(int *)(puStack0000000000000050 + 4);
              plVar3 = *(longlong **)((longlong)&stack0x00000060 + (longlong)iVar5);
              if (plVar3 == (longlong *)0x0) {
                if (DAT_18007b7b0 == (char)unaff_R15) {
                  pHVar7 = GetModuleHandleA("Advapi32.dll");
                  if (pHVar7 == (HMODULE)0x0) {
                    DAT_18007b7b0 = '\x01';
                  }
                  else {
                    DAT_18007b7a8 = GetProcAddress(pHVar7,"RegDeleteKeyExA");
                    DAT_18007b7b0 = '\x01';
                  }
                }
                pHVar9 = *(HKEY *)((longlong)&stack0x00000050 + (longlong)iVar5);
                if (DAT_18007b7a8 != (FARPROC)0x0) {
                  (*DAT_18007b7a8)(pHVar9,&stack0x00000040,
                                   (ulonglong)*(uint *)(&stack0x00000058 + iVar5),0);
                  break;
                }
              }
              else {
                pHVar9 = *(HKEY *)((longlong)&stack0x00000050 + (longlong)iVar5);
                if ((HKEY)*plVar3 != unaff_R15) {
                  pHVar7 = GetModuleHandleA("Advapi32.dll");
                  if ((pHVar7 != (HMODULE)0x0) &&
                     (pFVar8 = GetProcAddress(pHVar7,"RegDeleteKeyTransactedA"),
                     pFVar8 != (FARPROC)0x0)) {
                    (*pFVar8)(pHVar9,&stack0x00000040,0,0,*plVar3);
                  }
                  break;
                }
                if ((int)plVar3[1] == iVar13) break;
              }
              RegDeleteKeyA(pHVar9,(LPCSTR)&stack0x00000040);
              break;
            }
          }
        }
        dwIndex = (int)uVar10 + 1;
        uVar10 = (ulonglong)dwIndex;
        in_stack_00000040._4_4_ = 4;
        if (unaff_RBP[-5] != (HKEY)0x0) {
          RegCloseKey(unaff_RBP[-5]);
        }
        iVar5 = RegEnumKeyExA(*(HKEY *)((longlong)&stack0x00000050 +
                                       (longlong)*(int *)(puStack0000000000000050 + 4)),dwIndex,
                              (LPSTR)&stack0x00000040,(LPDWORD)((longlong)&stack0x00000040 + 4),
                              (LPDWORD)unaff_R15,(LPSTR)unaff_R15,(LPDWORD)unaff_R15,
                              (PFILETIME)(unaff_RBP + -2));
      }
      goto LAB_1800376d0;
    }
  }
  uVar12 = (ulonglong)unaff_R15 & 0xffffffff;
LAB_1800376d0:
  iVar5 = iVar13;
  if (unaff_R15 != (HKEY)0x0) {
    RegCloseKey(unaff_R15);
    iStack0000000000000060 = iVar13;
    RegCloseKey(unaff_R15);
    iVar5 = iStack0000000000000060;
  }
  iStack0000000000000060 = iVar5;
  *(int *)(unaff_RBP + -0x10) = iVar13;
  if (unaff_RBP[-0xd] != (HKEY)0x0) {
    RegCloseKey(unaff_RBP[-0xd]);
    unaff_RBP[-0xd] = unaff_R15;
  }
  *(int *)(unaff_RBP + -0xc) = iVar13;
  if (unaff_RBP[-9] != (HKEY)0x0) {
    RegCloseKey(unaff_RBP[-9]);
    unaff_RBP[-9] = unaff_R15;
  }
  *(int *)(unaff_RBP + -8) = iVar13;
  if (*unaff_RBP != (HKEY)0x0) {
    RegCloseKey(*unaff_RBP);
  }
  return uVar12;
}

/* ---- FUNC 000376F2 FUN_1800376f2 (113 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_1800376f2(HKEY param_1)

{
  undefined8 *unaff_RBP;
  undefined4 unaff_R14D;
  undefined4 uVar1;
  undefined8 unaff_R15;
  HKEY in_stack_00000078;
  
  RegCloseKey(param_1);
  uVar1 = (undefined4)unaff_R15;
  if (in_stack_00000078 != (HKEY)0x0) {
    RegCloseKey(in_stack_00000078);
  }
  *(undefined4 *)(unaff_RBP + -0x10) = uVar1;
  if ((HKEY)unaff_RBP[-0xd] != (HKEY)0x0) {
    RegCloseKey((HKEY)unaff_RBP[-0xd]);
    unaff_RBP[-0xd] = unaff_R15;
  }
  *(undefined4 *)(unaff_RBP + -0xc) = uVar1;
  if ((HKEY)unaff_RBP[-9] != (HKEY)0x0) {
    RegCloseKey((HKEY)unaff_RBP[-9]);
    unaff_RBP[-9] = unaff_R15;
  }
  *(undefined4 *)(unaff_RBP + -8) = uVar1;
  if ((HKEY)*unaff_RBP != (HKEY)0x0) {
    RegCloseKey((HKEY)*unaff_RBP);
  }
  return unaff_R14D;
}

/* ---- FUNC 00037763 FUN_180037763 (27 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180037763(void)

{
  return;
}

/* ---- FUNC 00037780 APModLibUpdateLib (65 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

DWORD APModLibUpdateLib(longlong param_1,undefined4 param_2,undefined4 param_3)

{
  BYTE BVar1;
  BYTE BVar2;
  HKEY pHVar3;
  DWORD DVar4;
  LSTATUS LVar5;
  int iVar6;
  LPCSTR lpSubKey;
  BYTE *pBVar7;
  DWORD dwIndex;
  undefined8 *puVar8;
  longlong lVar9;
  undefined1 auStackY_568 [32];
  DWORD local_528;
  DWORD local_524;
  CHAR local_520 [4];
  undefined4 local_51c;
  undefined4 local_518 [2];
  HKEY local_510 [2];
  undefined4 local_500;
  undefined8 local_4f8;
  HKEY local_4f0 [2];
  undefined4 local_4e0;
  undefined8 local_4d8;
  HKEY local_4d0 [2];
  undefined4 local_4c0;
  undefined8 local_4b8;
  HKEY local_4b0 [2];
  undefined4 local_4a0;
  undefined8 local_498;
  HKEY local_490 [2];
  undefined4 local_480;
  undefined8 local_478;
  undefined *local_470;
  HKEY local_468;
  undefined4 local_460;
  undefined8 local_458;
  _FILETIME local_450;
  BYTE local_448 [1024];
  ulonglong local_48;
  
                    /* 0x37780  273  APModLibUpdateLib */
  local_48 = DAT_1800791f8 ^ (ulonglong)auStackY_568;
  dwIndex = 0;
  DVar4 = 0;
  if (param_1 == 0) {
    DVar4 = 0;
  }
  else {
    local_468 = (HKEY)0x0;
    local_470 = &DAT_180053988;
    local_490[0] = (HKEY)&DAT_180053988;
    local_4b0[0] = (HKEY)&DAT_180053988;
    local_4d0[0] = (HKEY)&DAT_180053988;
    local_510[0] = (HKEY)&DAT_180053988;
    local_460 = 0;
    local_458 = 0;
    local_490[1] = (HKEY)0x0;
    local_480 = 0;
    local_478 = 0;
    local_4b0[1] = (HKEY)0x0;
    local_4a0 = 0;
    local_498 = 0;
    local_4d0[1] = (HKEY)0x0;
    local_4c0 = 0;
    local_4b8 = 0;
    local_510[1] = (HKEY)0x0;
    local_500 = 0;
    local_4f8 = 0;
    LVar5 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000001,"Software",0,0xf003f,&local_468);
    if (LVar5 == 0) {
      LVar5 = RegOpenKeyExA(*(HKEY *)((longlong)&local_470 + (longlong)*(int *)(local_470 + 4)),
                            "AspenTech",0,0xf003f,
                            (PHKEY)((longlong)local_490 + (longlong)local_490[0][1].unused));
      if (LVar5 == 0) {
        LVar5 = RegOpenKeyExA(*(HKEY *)((longlong)local_490 + (longlong)local_490[0][1].unused),
                              "ASPEN PLUS",0,0xf003f,
                              (PHKEY)((longlong)local_4b0 + (longlong)local_4b0[0][1].unused));
        if (LVar5 == 0) {
          pHVar3 = *(HKEY *)((longlong)local_4b0 + (longlong)local_4b0[0][1].unused);
          iVar6 = local_4d0[0][1].unused;
          lpSubKey = (LPCSTR)FUN_180024170();
          LVar5 = RegOpenKeyExA(pHVar3,lpSubKey,0,0xf003f,
                                (PHKEY)((longlong)local_4d0 + (longlong)iVar6));
          if ((LVar5 == 0) &&
             (LVar5 = RegOpenKeyExA(*(HKEY *)((longlong)local_4d0 + (longlong)local_4d0[0][1].unused
                                             ),"Libraries",0,0xf003f,
                                    (PHKEY)((longlong)local_510 + (longlong)local_510[0][1].unused))
             , LVar5 == 0)) {
            local_524 = 0x400;
            local_528 = 4;
            iVar6 = RegEnumKeyExA(*(HKEY *)((longlong)local_510 + (longlong)local_510[0][1].unused),
                                  0,local_520,&local_528,(LPDWORD)0x0,(LPSTR)0x0,(LPDWORD)0x0,
                                  &local_450);
            while (DVar4 = 0, iVar6 == 0) {
              local_4f0[0] = (HKEY)&DAT_180053988;
              local_4f0[1] = (HKEY)0x0;
              local_4e0 = 0;
              local_4d8 = 0;
              LVar5 = RegOpenKeyExA(*(HKEY *)((longlong)local_510 + (longlong)local_510[0][1].unused
                                             ),local_520,0,0xf003f,local_4f0 + 1);
              if (LVar5 == 0) {
                local_524 = 0x400;
                LVar5 = RegQueryValueExA(*(HKEY *)((longlong)local_4f0 +
                                                  (longlong)local_4f0[0][1].unused),"Display Name",
                                         (LPDWORD)0x0,(LPDWORD)0x0,local_448,&local_524);
                if (LVar5 == 0) {
                  pBVar7 = local_448;
                  lVar9 = param_1 - (longlong)pBVar7;
                  do {
                    BVar1 = *pBVar7;
                    BVar2 = pBVar7[lVar9];
                    if (BVar1 != BVar2) break;
                    pBVar7 = pBVar7 + 1;
                  } while (BVar2 != '\0');
                  if (BVar1 == BVar2) {
                    DVar4 = 1;
                    local_518[0] = param_2;
                    RegSetValueExA(*(HKEY *)((longlong)local_4f0 + (longlong)local_4f0[0][1].unused)
                                   ,"Position",0,4,(BYTE *)local_518,4);
                    local_51c = param_3;
                    RegSetValueExA(*(HKEY *)((longlong)local_4f0 + (longlong)local_4f0[0][1].unused)
                                   ,"Active",0,4,(BYTE *)&local_51c,4);
                    if (local_4f0[1] != (HKEY)0x0) {
                      RegCloseKey(local_4f0[1]);
                    }
                    break;
                  }
                }
              }
              dwIndex = dwIndex + 1;
              local_528 = 4;
              if (local_4f0[1] != (HKEY)0x0) {
                RegCloseKey(local_4f0[1]);
              }
              iVar6 = RegEnumKeyExA(*(HKEY *)((longlong)local_510 + (longlong)local_510[0][1].unused
                                             ),dwIndex,local_520,&local_528,(LPDWORD)0x0,(LPSTR)0x0,
                                    (LPDWORD)0x0,&local_450);
            }
          }
        }
      }
      else {
        iVar6 = *(int *)(local_470 + 4);
        puVar8 = (undefined8 *)((longlong)&local_470 + (longlong)iVar6);
        pHVar3 = (HKEY)*puVar8;
        if (pHVar3 != (HKEY)0x0) {
          RegCloseKey(pHVar3);
          *puVar8 = 0;
        }
        *(undefined4 *)((longlong)&local_468 + (longlong)iVar6) = 0;
      }
    }
    if (local_510[1] != (HKEY)0x0) {
      RegCloseKey(local_510[1]);
      local_510[1] = (HKEY)0x0;
    }
    local_500 = 0;
    if (local_4d0[1] != (HKEY)0x0) {
      RegCloseKey(local_4d0[1]);
      local_4d0[1] = (HKEY)0x0;
    }
    local_4c0 = 0;
    if (local_4b0[1] != (HKEY)0x0) {
      RegCloseKey(local_4b0[1]);
      local_4b0[1] = (HKEY)0x0;
    }
    local_4a0 = 0;
    if (local_490[1] != (HKEY)0x0) {
      RegCloseKey(local_490[1]);
      local_490[1] = (HKEY)0x0;
    }
    local_480 = 0;
    if (local_468 != (HKEY)0x0) {
      RegCloseKey(local_468);
    }
  }
  return DVar4;
}

/* ---- FUNC 000377C1 FUN_1800377c1 (285 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_1800377c1(void)

{
  char cVar1;
  char cVar2;
  HKEY hKey;
  LSTATUS LVar3;
  int iVar4;
  LPCSTR lpSubKey;
  PHKEY ppHVar5;
  uint dwIndex;
  undefined8 *puVar6;
  ulonglong uVar7;
  PHKEY unaff_RBP;
  longlong unaff_RSI;
  ulonglong uVar8;
  longlong lVar9;
  undefined4 uVar10;
  HKEY unaff_R12;
  undefined4 unaff_R14D;
  DWORD DStack0000000000000040;
  undefined4 uStack0000000000000044;
  undefined4 in_stack_00000050;
  undefined *puStack0000000000000058;
  undefined4 uStack0000000000000068;
  undefined *in_stack_00000078;
  
  *unaff_RBP = unaff_R12;
  unaff_RBP[-1] = (HKEY)&DAT_180053988;
  unaff_RBP[-5] = (HKEY)&DAT_180053988;
  unaff_RBP[-9] = (HKEY)&DAT_180053988;
  unaff_RBP[-0xd] = (HKEY)&DAT_180053988;
  puStack0000000000000058 = &DAT_180053988;
  uVar10 = SUB84(unaff_R12,0);
  *(undefined4 *)(unaff_RBP + 1) = uVar10;
  unaff_RBP[2] = unaff_R12;
  unaff_RBP[-4] = unaff_R12;
  *(undefined4 *)(unaff_RBP + -3) = uVar10;
  unaff_RBP[-2] = unaff_R12;
  unaff_RBP[-8] = unaff_R12;
  *(undefined4 *)(unaff_RBP + -7) = uVar10;
  unaff_RBP[-6] = unaff_R12;
  unaff_RBP[-0xc] = unaff_R12;
  *(undefined4 *)(unaff_RBP + -0xb) = uVar10;
  unaff_RBP[-10] = unaff_R12;
  uStack0000000000000068 = uVar10;
  LVar3 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000001,"Software",0,0xf003f,unaff_RBP);
  if (LVar3 == 0) {
    LVar3 = RegOpenKeyExA(*(HKEY *)((longlong)unaff_RBP + (longlong)unaff_RBP[-1][1].unused + -8),
                          "AspenTech",0,0xf003f,
                          (PHKEY)((longlong)unaff_RBP + (longlong)unaff_RBP[-5][1].unused + -0x28));
    if (LVar3 == 0) {
      LVar3 = RegOpenKeyExA(*(HKEY *)((longlong)unaff_RBP +
                                     (longlong)unaff_RBP[-5][1].unused + -0x28),"ASPEN PLUS",0,
                            0xf003f,(PHKEY)((longlong)unaff_RBP +
                                           (longlong)unaff_RBP[-9][1].unused + -0x48));
      if (LVar3 == 0) {
        hKey = *(HKEY *)((longlong)unaff_RBP + (longlong)unaff_RBP[-9][1].unused + -0x48);
        iVar4 = unaff_RBP[-0xd][1].unused;
        lpSubKey = (LPCSTR)FUN_180024170();
        LVar3 = RegOpenKeyExA(hKey,lpSubKey,0,0xf003f,
                              (PHKEY)((longlong)unaff_RBP + (longlong)iVar4 + -0x68));
        if ((LVar3 == 0) &&
           (LVar3 = RegOpenKeyExA(*(HKEY *)((longlong)unaff_RBP +
                                           (longlong)unaff_RBP[-0xd][1].unused + -0x68),"Libraries",
                                  0,0xf003f,
                                  (PHKEY)((longlong)&stack0x00000058 +
                                         (longlong)*(int *)(puStack0000000000000058 + 4))),
           LVar3 == 0)) {
          uStack0000000000000044 = 0x400;
          DStack0000000000000040 = 4;
          uVar7 = (ulonglong)unaff_R12 & 0xffffffff;
          uVar8 = (ulonglong)unaff_R12 & 0xffffffff;
          iVar4 = RegEnumKeyExA(*(HKEY *)((longlong)&stack0x00000058 +
                                         (longlong)*(int *)(puStack0000000000000058 + 4)),0,
                                &stack0x00000048,&stack0x00000040,(LPDWORD)unaff_R12,
                                (LPSTR)unaff_R12,(LPDWORD)unaff_R12,(PFILETIME)(unaff_RBP + 3));
          while (iVar4 == 0) {
            in_stack_00000078 = &DAT_180053988;
            unaff_RBP[-0x10] = unaff_R12;
            *(undefined4 *)(unaff_RBP + -0xf) = uVar10;
            unaff_RBP[-0xe] = unaff_R12;
            LVar3 = RegOpenKeyExA(*(HKEY *)((longlong)&stack0x00000058 +
                                           (longlong)*(int *)(puStack0000000000000058 + 4)),
                                  &stack0x00000048,0,0xf003f,unaff_RBP + -0x10);
            if (LVar3 == 0) {
              uStack0000000000000044 = 0x400;
              LVar3 = RegQueryValueExA(*(HKEY *)((longlong)&stack0x00000078 +
                                                (longlong)*(int *)(in_stack_00000078 + 4)),
                                       "Display Name",(LPDWORD)0x0,(LPDWORD)0x0,
                                       (LPBYTE)(unaff_RBP + 4),
                                       (LPDWORD)((longlong)&stack0x00000040 + 4));
              if (LVar3 == 0) {
                ppHVar5 = unaff_RBP + 4;
                lVar9 = unaff_RSI - (longlong)ppHVar5;
                do {
                  cVar1 = *(char *)ppHVar5;
                  cVar2 = *(char *)((longlong)ppHVar5 + lVar9);
                  if (cVar1 != cVar2) break;
                  ppHVar5 = (PHKEY)((longlong)ppHVar5 + 1);
                } while (cVar2 != '\0');
                if (cVar1 == cVar2) {
                  uVar8 = 1;
                  in_stack_00000050 = unaff_R14D;
                  RegSetValueExA(*(HKEY *)((longlong)&stack0x00000078 +
                                          (longlong)*(int *)(in_stack_00000078 + 4)),"Position",0,4,
                                 (BYTE *)&stack0x00000050,4);
                  RegSetValueExA(*(HKEY *)((longlong)&stack0x00000078 +
                                          (longlong)*(int *)(in_stack_00000078 + 4)),"Active",0,4,
                                 &stack0x0000004c,4);
                  if (unaff_RBP[-0x10] != (HKEY)0x0) {
                    RegCloseKey(unaff_RBP[-0x10]);
                  }
                  break;
                }
              }
            }
            dwIndex = (int)uVar7 + 1;
            uVar7 = (ulonglong)dwIndex;
            DStack0000000000000040 = 4;
            if (unaff_RBP[-0x10] != (HKEY)0x0) {
              RegCloseKey(unaff_RBP[-0x10]);
            }
            iVar4 = RegEnumKeyExA(*(HKEY *)((longlong)&stack0x00000058 +
                                           (longlong)*(int *)(puStack0000000000000058 + 4)),dwIndex,
                                  &stack0x00000048,&stack0x00000040,(LPDWORD)unaff_R12,
                                  (LPSTR)unaff_R12,(LPDWORD)unaff_R12,(PFILETIME)(unaff_RBP + 3));
          }
          goto LAB_1800378c4;
        }
      }
    }
    else {
      puVar6 = (undefined8 *)((longlong)unaff_RBP + (longlong)unaff_RBP[-1][1].unused + -8);
      if ((HKEY)*puVar6 != (HKEY)0x0) {
        RegCloseKey((HKEY)*puVar6);
        *puVar6 = unaff_R12;
      }
      *(undefined4 *)(puVar6 + 1) = uVar10;
    }
  }
  uVar8 = (ulonglong)unaff_R12 & 0xffffffff;
LAB_1800378c4:
  if (unaff_R12 != (HKEY)0x0) {
    RegCloseKey(unaff_R12);
  }
  uStack0000000000000068 = uVar10;
  if (unaff_RBP[-0xc] != (HKEY)0x0) {
    RegCloseKey(unaff_RBP[-0xc]);
    unaff_RBP[-0xc] = unaff_R12;
  }
  *(undefined4 *)(unaff_RBP + -0xb) = uVar10;
  if (unaff_RBP[-8] != (HKEY)0x0) {
    RegCloseKey(unaff_RBP[-8]);
    unaff_RBP[-8] = unaff_R12;
  }
  *(undefined4 *)(unaff_RBP + -7) = uVar10;
  if (unaff_RBP[-4] != (HKEY)0x0) {
    RegCloseKey(unaff_RBP[-4]);
    unaff_RBP[-4] = unaff_R12;
  }
  *(undefined4 *)(unaff_RBP + -3) = uVar10;
  if (*unaff_RBP != (HKEY)0x0) {
    RegCloseKey(*unaff_RBP);
  }
  return uVar8;
}

/* ---- FUNC 000378DE FUN_1800378de (110 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_1800378de(HKEY param_1)

{
  undefined8 *unaff_RBP;
  undefined4 unaff_EDI;
  undefined4 uVar1;
  undefined8 unaff_R12;
  
  RegCloseKey(param_1);
  uVar1 = (undefined4)unaff_R12;
  if ((HKEY)unaff_RBP[-0xc] != (HKEY)0x0) {
    RegCloseKey((HKEY)unaff_RBP[-0xc]);
    unaff_RBP[-0xc] = unaff_R12;
  }
  *(undefined4 *)(unaff_RBP + -0xb) = uVar1;
  if ((HKEY)unaff_RBP[-8] != (HKEY)0x0) {
    RegCloseKey((HKEY)unaff_RBP[-8]);
    unaff_RBP[-8] = unaff_R12;
  }
  *(undefined4 *)(unaff_RBP + -7) = uVar1;
  if ((HKEY)unaff_RBP[-4] != (HKEY)0x0) {
    RegCloseKey((HKEY)unaff_RBP[-4]);
    unaff_RBP[-4] = unaff_R12;
  }
  *(undefined4 *)(unaff_RBP + -3) = uVar1;
  if ((HKEY)*unaff_RBP != (HKEY)0x0) {
    RegCloseKey((HKEY)*unaff_RBP);
  }
  return unaff_EDI;
}

/* ---- FUNC 0003794C FUN_18003794c (31 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18003794c(void)

{
  return;
}

/* ---- FUNC 0003796B FUN_18003796b (697 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_18003796b(void)

{
  char cVar1;
  char cVar2;
  HKEY hKey;
  LSTATUS LVar3;
  int iVar4;
  LPCSTR lpSubKey;
  char *pcVar5;
  uint dwIndex;
  ulonglong uVar6;
  undefined8 *unaff_RBP;
  longlong unaff_RSI;
  ulonglong uVar7;
  longlong lVar8;
  undefined4 uVar9;
  LPDWORD unaff_R12;
  longlong unaff_R13;
  undefined4 unaff_R14D;
  DWORD DStack0000000000000040;
  undefined4 uStack0000000000000044;
  undefined4 in_stack_00000050;
  longlong in_stack_00000058;
  HKEY in_stack_00000060;
  longlong in_stack_00000078;
  
  LVar3 = RegOpenKeyExA(*(HKEY *)((longlong)unaff_RBP +
                                 (longlong)*(int *)(unaff_RBP[-5] + 4) + -0x28),"ASPEN PLUS",0,
                        0xf003f,(PHKEY)((longlong)unaff_RBP +
                                       (longlong)*(int *)(unaff_RBP[-9] + 4) + -0x48));
  uVar9 = SUB84(unaff_R12,0);
  if (LVar3 == 0) {
    hKey = *(HKEY *)((longlong)unaff_RBP + (longlong)*(int *)(unaff_RBP[-9] + 4) + -0x48);
    iVar4 = *(int *)(unaff_RBP[-0xd] + 4);
    lpSubKey = (LPCSTR)FUN_180024170();
    LVar3 = RegOpenKeyExA(hKey,lpSubKey,0,0xf003f,
                          (PHKEY)((longlong)unaff_RBP + (longlong)iVar4 + -0x68));
    if ((LVar3 == 0) &&
       (LVar3 = RegOpenKeyExA(*(HKEY *)((longlong)unaff_RBP +
                                       (longlong)*(int *)(unaff_RBP[-0xd] + 4) + -0x68),"Libraries",
                              0,0xf003f,
                              (PHKEY)((longlong)&stack0x00000058 +
                                     (longlong)*(int *)(in_stack_00000058 + 4))), LVar3 == 0)) {
      uStack0000000000000044 = 0x400;
      DStack0000000000000040 = 4;
      uVar6 = (ulonglong)unaff_R12 & 0xffffffff;
      uVar7 = (ulonglong)unaff_R12 & 0xffffffff;
      iVar4 = RegEnumKeyExA(*(HKEY *)((longlong)&stack0x00000058 +
                                     (longlong)*(int *)(in_stack_00000058 + 4)),0,&stack0x00000048,
                            &stack0x00000040,unaff_R12,(LPSTR)unaff_R12,unaff_R12,
                            (PFILETIME)(unaff_RBP + 3));
      while (iVar4 == 0) {
        unaff_RBP[-0x10] = unaff_R12;
        *(undefined4 *)(unaff_RBP + -0xf) = uVar9;
        unaff_RBP[-0xe] = unaff_R12;
        in_stack_00000078 = unaff_R13;
        LVar3 = RegOpenKeyExA(*(HKEY *)((longlong)&stack0x00000058 +
                                       (longlong)*(int *)(in_stack_00000058 + 4)),&stack0x00000048,0
                              ,0xf003f,(PHKEY)(unaff_RBP + -0x10));
        if (LVar3 == 0) {
          uStack0000000000000044 = 0x400;
          LVar3 = RegQueryValueExA(*(HKEY *)((longlong)&stack0x00000078 +
                                            (longlong)*(int *)(in_stack_00000078 + 4)),
                                   "Display Name",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)(unaff_RBP + 4),
                                   (LPDWORD)((longlong)&stack0x00000040 + 4));
          if (LVar3 == 0) {
            pcVar5 = (char *)(unaff_RBP + 4);
            lVar8 = unaff_RSI - (longlong)pcVar5;
            do {
              cVar1 = *pcVar5;
              cVar2 = pcVar5[lVar8];
              if (cVar1 != cVar2) break;
              pcVar5 = pcVar5 + 1;
            } while (cVar2 != '\0');
            if (cVar1 == cVar2) {
              uVar7 = 1;
              in_stack_00000050 = unaff_R14D;
              RegSetValueExA(*(HKEY *)((longlong)&stack0x00000078 +
                                      (longlong)*(int *)(in_stack_00000078 + 4)),"Position",0,4,
                             (BYTE *)&stack0x00000050,4);
              RegSetValueExA(*(HKEY *)((longlong)&stack0x00000078 +
                                      (longlong)*(int *)(in_stack_00000078 + 4)),"Active",0,4,
                             &stack0x0000004c,4);
              if ((HKEY)unaff_RBP[-0x10] != (HKEY)0x0) {
                RegCloseKey((HKEY)unaff_RBP[-0x10]);
              }
              break;
            }
          }
        }
        dwIndex = (int)uVar6 + 1;
        uVar6 = (ulonglong)dwIndex;
        DStack0000000000000040 = 4;
        if ((HKEY)unaff_RBP[-0x10] != (HKEY)0x0) {
          RegCloseKey((HKEY)unaff_RBP[-0x10]);
        }
        iVar4 = RegEnumKeyExA(*(HKEY *)((longlong)&stack0x00000058 +
                                       (longlong)*(int *)(in_stack_00000058 + 4)),dwIndex,
                              &stack0x00000048,&stack0x00000040,unaff_R12,(LPSTR)unaff_R12,unaff_R12
                              ,(PFILETIME)(unaff_RBP + 3));
      }
      goto LAB_1800378c4;
    }
  }
  uVar7 = (ulonglong)unaff_R12 & 0xffffffff;
LAB_1800378c4:
  if (in_stack_00000060 != (HKEY)0x0) {
    RegCloseKey(in_stack_00000060);
  }
  if ((HKEY)unaff_RBP[-0xc] != (HKEY)0x0) {
    RegCloseKey((HKEY)unaff_RBP[-0xc]);
    unaff_RBP[-0xc] = unaff_R12;
  }
  *(undefined4 *)(unaff_RBP + -0xb) = uVar9;
  if ((HKEY)unaff_RBP[-8] != (HKEY)0x0) {
    RegCloseKey((HKEY)unaff_RBP[-8]);
    unaff_RBP[-8] = unaff_R12;
  }
  *(undefined4 *)(unaff_RBP + -7) = uVar9;
  if ((HKEY)unaff_RBP[-4] != (HKEY)0x0) {
    RegCloseKey((HKEY)unaff_RBP[-4]);
    unaff_RBP[-4] = unaff_R12;
  }
  *(undefined4 *)(unaff_RBP + -3) = uVar9;
  if ((HKEY)*unaff_RBP != (HKEY)0x0) {
    RegCloseKey((HKEY)*unaff_RBP);
  }
  return uVar7;
}

/* ---- FUNC 00037C30 FUN_180037c30 (18 bytes) ---- */

bool FUN_180037c30(int *param_1)

{
  HKEY hKey;
  int iVar1;
  LSTATUS LVar2;
  LPSTR pCVar3;
  LPCSTR lpSubKey;
  bool bVar4;
  DWORD local_res8 [2];
  int local_res10 [2];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res18 [16];
  HKEY local_d8 [2];
  undefined4 local_c8;
  undefined8 local_c0;
  HKEY local_b8 [2];
  undefined4 local_a8;
  undefined8 local_a0;
  HKEY local_98 [2];
  undefined4 local_88;
  undefined8 local_80;
  HKEY local_78 [2];
  undefined4 local_68;
  undefined8 local_60;
  HKEY local_58 [2];
  undefined4 local_48;
  undefined8 local_40;
  
  pCVar3 = GetCommandLineA();
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res18,pCVar3);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::MakeUpper(local_res18);
  iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Find
                    (local_res18,"APWN.EXE",0);
  local_58[1] = (HKEY)0x0;
  bVar4 = iVar1 != -1;
  local_48 = 0;
  local_40 = 0;
  local_58[0] = (HKEY)&DAT_180053988;
  local_78[0] = (HKEY)&DAT_180053988;
  local_78[1] = (HKEY)0x0;
  local_68 = 0;
  local_60 = 0;
  local_98[0] = (HKEY)&DAT_180053988;
  local_98[1] = (HKEY)0x0;
  local_88 = 0;
  local_80 = 0;
  local_b8[0] = (HKEY)&DAT_180053988;
  local_b8[1] = (HKEY)0x0;
  local_a8 = 0;
  local_a0 = 0;
  local_d8[0] = (HKEY)&DAT_180053988;
  local_d8[1] = (HKEY)0x0;
  local_c8 = 0;
  local_c0 = 0;
  if (param_1 != (int *)0x0) {
    *param_1 = 4;
  }
  LVar2 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000001,"Software",0,0xf003f,local_58 + 1);
  if (LVar2 == 0) {
    LVar2 = RegOpenKeyExA(*(HKEY *)((longlong)local_58 + (longlong)local_58[0][1].unused),
                          "AspenTech",0,0xf003f,
                          (PHKEY)((longlong)local_78 + (longlong)local_78[0][1].unused));
    if (LVar2 == 0) {
      LVar2 = RegOpenKeyExA(*(HKEY *)((longlong)local_78 + (longlong)local_78[0][1].unused),
                            "ASPEN PLUS",0,0xf003f,
                            (PHKEY)((longlong)local_98 + (longlong)local_98[0][1].unused));
      if (LVar2 == 0) {
        hKey = *(HKEY *)((longlong)local_98 + (longlong)local_98[0][1].unused);
        iVar1 = local_b8[0][1].unused;
        lpSubKey = (LPCSTR)FUN_180024170();
        LVar2 = RegOpenKeyExA(hKey,lpSubKey,0,0xf003f,(PHKEY)((longlong)local_b8 + (longlong)iVar1))
        ;
        if (LVar2 == 0) {
          LVar2 = RegOpenKeyExA(*(HKEY *)((longlong)local_b8 + (longlong)local_b8[0][1].unused),
                                "Libraries",0,0xf003f,
                                (PHKEY)((longlong)local_d8 + (longlong)local_d8[0][1].unused));
          if (LVar2 == 0) {
            local_res8[0] = 4;
            LVar2 = RegQueryValueExA(*(HKEY *)((longlong)local_d8 + (longlong)local_d8[0][1].unused)
                                     ,"UseACMBuiltin",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)local_res10,
                                     local_res8);
            if (LVar2 == 0) {
              bVar4 = local_res10[0] != 0;
            }
            if (param_1 != (int *)0x0) {
              local_res8[0] = 4;
              LVar2 = RegQueryValueExA(*(HKEY *)((longlong)local_d8 +
                                                (longlong)local_d8[0][1].unused),
                                       "ACMBuiltinPosition",(LPDWORD)0x0,(LPDWORD)0x0,
                                       (LPBYTE)local_res10,local_res8);
              iVar1 = 4;
              if (LVar2 == 0) {
                iVar1 = local_res10[0];
              }
              *param_1 = iVar1;
            }
          }
        }
      }
    }
  }
  if (local_d8[1] != (HKEY)0x0) {
    RegCloseKey(local_d8[1]);
    local_d8[1] = (HKEY)0x0;
  }
  local_c8 = 0;
  if (local_b8[1] != (HKEY)0x0) {
    RegCloseKey(local_b8[1]);
    local_b8[1] = (HKEY)0x0;
  }
  local_a8 = 0;
  if (local_98[1] != (HKEY)0x0) {
    RegCloseKey(local_98[1]);
    local_98[1] = (HKEY)0x0;
  }
  local_88 = 0;
  if (local_78[1] != (HKEY)0x0) {
    RegCloseKey(local_78[1]);
    local_78[1] = (HKEY)0x0;
  }
  local_68 = 0;
  if (local_58[1] != (HKEY)0x0) {
    RegCloseKey(local_58[1]);
    local_58[1] = (HKEY)0x0;
  }
  local_48 = 0;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res18);
  return bVar4;
}

/* ---- FUNC 00037C42 FUN_180037c42 (349 bytes) ---- */

bool FUN_180037c42(undefined4 *param_1)

{
  HKEY hKey;
  int iVar1;
  LSTATUS LVar2;
  longlong in_RAX;
  LPSTR pCVar3;
  LPCSTR lpSubKey;
  longlong unaff_RBP;
  undefined4 uVar4;
  undefined8 unaff_R14;
  undefined8 unaff_R15;
  bool bVar5;
  
  *(undefined8 *)(in_RAX + -0x30) = unaff_R14;
  *(undefined8 *)(in_RAX + -0x38) = unaff_R15;
  pCVar3 = GetCommandLineA();
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(unaff_RBP + 0x77),
             pCVar3);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::MakeUpper
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(unaff_RBP + 0x77));
  iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Find
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                     (unaff_RBP + 0x77),"APWN.EXE",0);
  *(undefined8 *)(unaff_RBP + 0xf) = 0;
  bVar5 = iVar1 != -1;
  *(undefined4 *)(unaff_RBP + 0x17) = 0;
  *(undefined8 *)(unaff_RBP + 0x1f) = 0;
  *(undefined **)(unaff_RBP + 7) = &DAT_180053988;
  *(undefined **)(unaff_RBP + -0x19) = &DAT_180053988;
  *(undefined8 *)(unaff_RBP + -0x11) = 0;
  *(undefined4 *)(unaff_RBP + -9) = 0;
  *(undefined8 *)(unaff_RBP + -1) = 0;
  *(undefined **)(unaff_RBP + -0x39) = &DAT_180053988;
  *(undefined8 *)(unaff_RBP + -0x31) = 0;
  *(undefined4 *)(unaff_RBP + -0x29) = 0;
  *(undefined8 *)(unaff_RBP + -0x21) = 0;
  *(undefined **)(unaff_RBP + -0x59) = &DAT_180053988;
  *(undefined8 *)(unaff_RBP + -0x51) = 0;
  *(undefined4 *)(unaff_RBP + -0x49) = 0;
  *(undefined8 *)(unaff_RBP + -0x41) = 0;
  *(undefined **)(unaff_RBP + -0x79) = &DAT_180053988;
  *(undefined8 *)(unaff_RBP + -0x71) = 0;
  *(undefined4 *)(unaff_RBP + -0x69) = 0;
  *(undefined8 *)(unaff_RBP + -0x61) = 0;
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 4;
  }
  LVar2 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000001,"Software",0,0xf003f,(PHKEY)(unaff_RBP + 0xf));
  if (LVar2 == 0) {
    LVar2 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + 7 +
                                   (longlong)*(int *)(*(longlong *)(unaff_RBP + 7) + 4)),"AspenTech"
                          ,0,0xf003f,
                          (PHKEY)(unaff_RBP + -0x19 +
                                 (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x19) + 4)));
    if (LVar2 == 0) {
      LVar2 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + -0x19 +
                                     (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x19) + 4)),
                            "ASPEN PLUS",0,0xf003f,
                            (PHKEY)(unaff_RBP + -0x39 +
                                   (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x39) + 4)));
      if (LVar2 == 0) {
        hKey = *(HKEY *)(unaff_RBP + -0x39 +
                        (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x39) + 4));
        iVar1 = *(int *)(*(longlong *)(unaff_RBP + -0x59) + 4);
        lpSubKey = (LPCSTR)FUN_180024170();
        LVar2 = RegOpenKeyExA(hKey,lpSubKey,0,0xf003f,(PHKEY)(unaff_RBP + -0x59 + (longlong)iVar1));
        if (LVar2 == 0) {
          LVar2 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + -0x59 +
                                         (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x59) + 4)),
                                "Libraries",0,0xf003f,
                                (PHKEY)(unaff_RBP + -0x79 +
                                       (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x79) + 4)));
          if (LVar2 == 0) {
            *(undefined4 *)(unaff_RBP + 0x67) = 4;
            LVar2 = RegQueryValueExA(*(HKEY *)(unaff_RBP + -0x79 +
                                              (longlong)
                                              *(int *)(*(longlong *)(unaff_RBP + -0x79) + 4)),
                                     "UseACMBuiltin",(LPDWORD)0x0,(LPDWORD)0x0,
                                     (LPBYTE)(unaff_RBP + 0x6f),(LPDWORD)(unaff_RBP + 0x67));
            if (LVar2 == 0) {
              bVar5 = *(int *)(unaff_RBP + 0x6f) != 0;
            }
            if (param_1 != (undefined4 *)0x0) {
              *(undefined4 *)(unaff_RBP + 0x67) = 4;
              LVar2 = RegQueryValueExA(*(HKEY *)(unaff_RBP + -0x79 +
                                                (longlong)
                                                *(int *)(*(longlong *)(unaff_RBP + -0x79) + 4)),
                                       "ACMBuiltinPosition",(LPDWORD)0x0,(LPDWORD)0x0,
                                       (LPBYTE)(unaff_RBP + 0x6f),(LPDWORD)(unaff_RBP + 0x67));
              uVar4 = 4;
              if (LVar2 == 0) {
                uVar4 = *(undefined4 *)(unaff_RBP + 0x6f);
              }
              *param_1 = uVar4;
            }
          }
        }
      }
    }
  }
  if (*(HKEY *)(unaff_RBP + -0x71) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x71));
    *(undefined8 *)(unaff_RBP + -0x71) = 0;
  }
  *(undefined4 *)(unaff_RBP + -0x69) = 0;
  if (*(HKEY *)(unaff_RBP + -0x51) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x51));
    *(undefined8 *)(unaff_RBP + -0x51) = 0;
  }
  *(undefined4 *)(unaff_RBP + -0x49) = 0;
  if (*(HKEY *)(unaff_RBP + -0x31) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x31));
    *(undefined8 *)(unaff_RBP + -0x31) = 0;
  }
  *(undefined4 *)(unaff_RBP + -0x29) = 0;
  if (*(HKEY *)(unaff_RBP + -0x11) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x11));
    *(undefined8 *)(unaff_RBP + -0x11) = 0;
  }
  *(undefined4 *)(unaff_RBP + -9) = 0;
  if (*(HKEY *)(unaff_RBP + 0xf) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + 0xf));
    *(undefined8 *)(unaff_RBP + 0xf) = 0;
  }
  *(undefined4 *)(unaff_RBP + 0x17) = 0;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(unaff_RBP + 0x77));
  return bVar5;
}

/* ---- FUNC 00037D9F FUN_180037d9f (95 bytes) ---- */

ulonglong FUN_180037d9f(void)

{
  HKEY hKey;
  LSTATUS LVar1;
  longlong in_RAX;
  LPCSTR lpSubKey;
  longlong unaff_RBP;
  ulonglong unaff_RSI;
  int iVar2;
  undefined8 unaff_R12;
  undefined4 unaff_R14D;
  undefined4 *unaff_R15;
  
  hKey = *(HKEY *)(unaff_RBP + -0x39 + (longlong)*(int *)(in_RAX + 4));
  iVar2 = *(int *)(*(longlong *)(unaff_RBP + -0x59) + 4);
  lpSubKey = (LPCSTR)FUN_180024170();
  LVar1 = RegOpenKeyExA(hKey,lpSubKey,0,0xf003f,(PHKEY)(unaff_RBP + -0x59 + (longlong)iVar2));
  iVar2 = (int)unaff_R12;
  if (LVar1 == 0) {
    LVar1 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + -0x59 +
                                   (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x59) + 4)),
                          "Libraries",0,0xf003f,
                          (PHKEY)(unaff_RBP + -0x79 +
                                 (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x79) + 4)));
    if (LVar1 == 0) {
      *(undefined4 *)(unaff_RBP + 0x67) = unaff_R14D;
      LVar1 = RegQueryValueExA(*(HKEY *)(unaff_RBP + -0x79 +
                                        (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x79) + 4)),
                               "UseACMBuiltin",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)(unaff_RBP + 0x6f),
                               (LPDWORD)(unaff_RBP + 0x67));
      if (LVar1 == 0) {
        unaff_RSI = CONCAT71((int7)((ulonglong)unaff_R12 >> 8),*(int *)(unaff_RBP + 0x6f) != iVar2)
                    & 0xffffffff;
      }
      if (unaff_R15 != (undefined4 *)0x0) {
        *(undefined4 *)(unaff_RBP + 0x67) = unaff_R14D;
        LVar1 = RegQueryValueExA(*(HKEY *)(unaff_RBP + -0x79 +
                                          (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x79) + 4)),
                                 "ACMBuiltinPosition",(LPDWORD)0x0,(LPDWORD)0x0,
                                 (LPBYTE)(unaff_RBP + 0x6f),(LPDWORD)(unaff_RBP + 0x67));
        if (LVar1 == 0) {
          unaff_R14D = *(undefined4 *)(unaff_RBP + 0x6f);
        }
        *unaff_R15 = unaff_R14D;
      }
    }
  }
  if (*(HKEY *)(unaff_RBP + -0x71) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x71));
    *(undefined8 *)(unaff_RBP + -0x71) = unaff_R12;
  }
  *(int *)(unaff_RBP + -0x69) = iVar2;
  if (*(HKEY *)(unaff_RBP + -0x51) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x51));
    *(undefined8 *)(unaff_RBP + -0x51) = unaff_R12;
  }
  *(int *)(unaff_RBP + -0x49) = iVar2;
  if (*(HKEY *)(unaff_RBP + -0x31) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x31));
    *(undefined8 *)(unaff_RBP + -0x31) = unaff_R12;
  }
  *(int *)(unaff_RBP + -0x29) = iVar2;
  if (*(HKEY *)(unaff_RBP + -0x11) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x11));
    *(undefined8 *)(unaff_RBP + -0x11) = unaff_R12;
  }
  *(int *)(unaff_RBP + -9) = iVar2;
  if (*(HKEY *)(unaff_RBP + 0xf) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + 0xf));
    *(undefined8 *)(unaff_RBP + 0xf) = unaff_R12;
  }
  *(int *)(unaff_RBP + 0x17) = iVar2;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(unaff_RBP + 0x77));
  return unaff_RSI & 0xffffffff;
}

/* ---- FUNC 00037DFE FUN_180037dfe (226 bytes) ---- */

ulonglong FUN_180037dfe(void)

{
  LSTATUS LVar1;
  longlong unaff_RBP;
  ulonglong unaff_RSI;
  int iVar2;
  undefined8 unaff_R12;
  undefined4 unaff_R14D;
  undefined4 *unaff_R15;
  
  LVar1 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + -0x59 +
                                 (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x59) + 4)),
                        "Libraries",0,0xf003f,
                        (PHKEY)(unaff_RBP + -0x79 +
                               (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x79) + 4)));
  iVar2 = (int)unaff_R12;
  if (LVar1 == 0) {
    *(undefined4 *)(unaff_RBP + 0x67) = unaff_R14D;
    LVar1 = RegQueryValueExA(*(HKEY *)(unaff_RBP + -0x79 +
                                      (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x79) + 4)),
                             "UseACMBuiltin",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)(unaff_RBP + 0x6f),
                             (LPDWORD)(unaff_RBP + 0x67));
    if (LVar1 == 0) {
      unaff_RSI = CONCAT71((int7)((ulonglong)unaff_R12 >> 8),*(int *)(unaff_RBP + 0x6f) != iVar2) &
                  0xffffffff;
    }
    if (unaff_R15 != (undefined4 *)0x0) {
      *(undefined4 *)(unaff_RBP + 0x67) = unaff_R14D;
      LVar1 = RegQueryValueExA(*(HKEY *)(unaff_RBP + -0x79 +
                                        (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x79) + 4)),
                               "ACMBuiltinPosition",(LPDWORD)0x0,(LPDWORD)0x0,
                               (LPBYTE)(unaff_RBP + 0x6f),(LPDWORD)(unaff_RBP + 0x67));
      if (LVar1 == 0) {
        unaff_R14D = *(undefined4 *)(unaff_RBP + 0x6f);
      }
      *unaff_R15 = unaff_R14D;
    }
  }
  if (*(HKEY *)(unaff_RBP + -0x71) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x71));
    *(undefined8 *)(unaff_RBP + -0x71) = unaff_R12;
  }
  *(int *)(unaff_RBP + -0x69) = iVar2;
  if (*(HKEY *)(unaff_RBP + -0x51) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x51));
    *(undefined8 *)(unaff_RBP + -0x51) = unaff_R12;
  }
  *(int *)(unaff_RBP + -0x49) = iVar2;
  if (*(HKEY *)(unaff_RBP + -0x31) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x31));
    *(undefined8 *)(unaff_RBP + -0x31) = unaff_R12;
  }
  *(int *)(unaff_RBP + -0x29) = iVar2;
  if (*(HKEY *)(unaff_RBP + -0x11) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x11));
    *(undefined8 *)(unaff_RBP + -0x11) = unaff_R12;
  }
  *(int *)(unaff_RBP + -9) = iVar2;
  if (*(HKEY *)(unaff_RBP + 0xf) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + 0xf));
    *(undefined8 *)(unaff_RBP + 0xf) = unaff_R12;
  }
  *(int *)(unaff_RBP + 0x17) = iVar2;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(unaff_RBP + 0x77));
  return unaff_RSI & 0xffffffff;
}

/* ---- FUNC 00037EE0 FUN_180037ee0 (130 bytes) ---- */

undefined4 FUN_180037ee0(HKEY param_1)

{
  longlong unaff_RBP;
  undefined4 unaff_ESI;
  undefined4 uVar1;
  undefined8 unaff_R12;
  
  RegCloseKey(param_1);
  *(undefined8 *)(unaff_RBP + -0x71) = unaff_R12;
  uVar1 = (undefined4)unaff_R12;
  *(undefined4 *)(unaff_RBP + -0x69) = uVar1;
  if (*(HKEY *)(unaff_RBP + -0x51) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x51));
    *(undefined8 *)(unaff_RBP + -0x51) = unaff_R12;
  }
  *(undefined4 *)(unaff_RBP + -0x49) = uVar1;
  if (*(HKEY *)(unaff_RBP + -0x31) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x31));
    *(undefined8 *)(unaff_RBP + -0x31) = unaff_R12;
  }
  *(undefined4 *)(unaff_RBP + -0x29) = uVar1;
  if (*(HKEY *)(unaff_RBP + -0x11) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x11));
    *(undefined8 *)(unaff_RBP + -0x11) = unaff_R12;
  }
  *(undefined4 *)(unaff_RBP + -9) = uVar1;
  if (*(HKEY *)(unaff_RBP + 0xf) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + 0xf));
    *(undefined8 *)(unaff_RBP + 0xf) = unaff_R12;
  }
  *(undefined4 *)(unaff_RBP + 0x17) = uVar1;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(unaff_RBP + 0x77));
  return unaff_ESI;
}

/* ---- FUNC 00037F70 FUN_180037f70 (16 bytes) ---- */

bool FUN_180037f70(int *param_1)

{
  HKEY hKey;
  LSTATUS LVar1;
  LPCSTR lpSubKey;
  int iVar2;
  bool bVar3;
  bool bVar4;
  DWORD local_res8 [2];
  int local_res10 [2];
  HKEY local_c8 [2];
  undefined4 local_b8;
  undefined8 local_b0;
  HKEY local_a8 [2];
  undefined4 local_98;
  undefined8 local_90;
  HKEY local_88 [2];
  undefined4 local_78;
  undefined8 local_70;
  HKEY local_68 [2];
  undefined4 local_58;
  undefined8 local_50;
  HKEY local_48 [2];
  undefined4 local_38;
  undefined8 local_30;
  
  local_48[1] = (HKEY)0x0;
  local_48[0] = (HKEY)&DAT_180053988;
  bVar3 = false;
  local_38 = 0;
  local_30 = 0;
  local_68[0] = (HKEY)&DAT_180053988;
  local_68[1] = (HKEY)0x0;
  local_58 = 0;
  local_50 = 0;
  local_88[0] = (HKEY)&DAT_180053988;
  local_88[1] = (HKEY)0x0;
  local_78 = 0;
  local_70 = 0;
  local_a8[0] = (HKEY)&DAT_180053988;
  local_a8[1] = (HKEY)0x0;
  local_98 = 0;
  local_90 = 0;
  local_c8[0] = (HKEY)&DAT_180053988;
  local_c8[1] = (HKEY)0x0;
  local_b8 = 0;
  local_b0 = 0;
  if (param_1 != (int *)0x0) {
    *param_1 = -1;
  }
  LVar1 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000001,"Software",0,0xf003f,local_48 + 1);
  bVar4 = false;
  if (((LVar1 == 0) &&
      (LVar1 = RegOpenKeyExA(*(HKEY *)((longlong)local_48 + (longlong)local_48[0][1].unused),
                             "AspenTech",0,0xf003f,
                             (PHKEY)((longlong)local_68 + (longlong)local_68[0][1].unused)),
      bVar4 = bVar3, LVar1 == 0)) &&
     (LVar1 = RegOpenKeyExA(*(HKEY *)((longlong)local_68 + (longlong)local_68[0][1].unused),
                            "ASPEN PLUS",0,0xf003f,
                            (PHKEY)((longlong)local_88 + (longlong)local_88[0][1].unused)),
     LVar1 == 0)) {
    hKey = *(HKEY *)((longlong)local_88 + (longlong)local_88[0][1].unused);
    iVar2 = local_a8[0][1].unused;
    lpSubKey = (LPCSTR)FUN_180024170();
    LVar1 = RegOpenKeyExA(hKey,lpSubKey,0,0xf003f,(PHKEY)((longlong)local_a8 + (longlong)iVar2));
    if ((LVar1 == 0) &&
       (LVar1 = RegOpenKeyExA(*(HKEY *)((longlong)local_a8 + (longlong)local_a8[0][1].unused),
                              "Libraries",0,0xf003f,
                              (PHKEY)((longlong)local_c8 + (longlong)local_c8[0][1].unused)),
       LVar1 == 0)) {
      local_res8[0] = 4;
      LVar1 = RegQueryValueExA(*(HKEY *)((longlong)local_c8 + (longlong)local_c8[0][1].unused),
                               "UseACMCatalog",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)local_res10,
                               local_res8);
      bVar4 = LVar1 == 0 && local_res10[0] != 0;
      if (param_1 != (int *)0x0) {
        local_res8[0] = 4;
        LVar1 = RegQueryValueExA(*(HKEY *)((longlong)local_c8 + (longlong)local_c8[0][1].unused),
                                 "ACMCatalogPosition",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)local_res10,
                                 local_res8);
        iVar2 = 3;
        if (LVar1 == 0) {
          iVar2 = local_res10[0];
        }
        *param_1 = iVar2;
      }
    }
  }
  if (local_c8[1] != (HKEY)0x0) {
    RegCloseKey(local_c8[1]);
    local_c8[1] = (HKEY)0x0;
  }
  local_b8 = 0;
  if (local_a8[1] != (HKEY)0x0) {
    RegCloseKey(local_a8[1]);
    local_a8[1] = (HKEY)0x0;
  }
  local_98 = 0;
  if (local_88[1] != (HKEY)0x0) {
    RegCloseKey(local_88[1]);
    local_88[1] = (HKEY)0x0;
  }
  local_78 = 0;
  if (local_68[1] != (HKEY)0x0) {
    RegCloseKey(local_68[1]);
    local_68[1] = (HKEY)0x0;
  }
  local_58 = 0;
  if (local_48[1] != (HKEY)0x0) {
    RegCloseKey(local_48[1]);
  }
  return bVar4;
}

/* ---- FUNC 00037F80 FUN_180037f80 (291 bytes) ---- */

bool FUN_180037f80(undefined4 *param_1)

{
  int iVar1;
  HKEY hKey;
  LSTATUS LVar2;
  longlong in_RAX;
  LPCSTR lpSubKey;
  undefined4 uVar3;
  longlong unaff_RBP;
  bool bVar4;
  bool bVar5;
  undefined8 unaff_R14;
  undefined8 unaff_R15;
  bool bVar6;
  
  *(undefined8 *)(in_RAX + -0x20) = unaff_R14;
  *(undefined8 *)(in_RAX + -0x28) = unaff_R15;
  bVar6 = false;
  *(undefined8 *)(unaff_RBP + 0x1f) = 0;
  *(undefined **)(unaff_RBP + 0x17) = &DAT_180053988;
  bVar4 = false;
  *(undefined4 *)(unaff_RBP + 0x27) = 0;
  *(undefined8 *)(unaff_RBP + 0x2f) = 0;
  *(undefined **)(unaff_RBP + -9) = &DAT_180053988;
  *(undefined8 *)(unaff_RBP + -1) = 0;
  *(undefined4 *)(unaff_RBP + 7) = 0;
  *(undefined8 *)(unaff_RBP + 0xf) = 0;
  *(undefined **)(unaff_RBP + -0x29) = &DAT_180053988;
  *(undefined8 *)(unaff_RBP + -0x21) = 0;
  *(undefined4 *)(unaff_RBP + -0x19) = 0;
  *(undefined8 *)(unaff_RBP + -0x11) = 0;
  *(undefined **)(unaff_RBP + -0x49) = &DAT_180053988;
  *(undefined8 *)(unaff_RBP + -0x41) = 0;
  *(undefined4 *)(unaff_RBP + -0x39) = 0;
  *(undefined8 *)(unaff_RBP + -0x31) = 0;
  *(undefined **)(unaff_RBP + -0x69) = &DAT_180053988;
  *(undefined8 *)(unaff_RBP + -0x61) = 0;
  *(undefined4 *)(unaff_RBP + -0x59) = 0;
  *(undefined8 *)(unaff_RBP + -0x51) = 0;
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0xffffffff;
  }
  LVar2 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000001,"Software",0,0xf003f,(PHKEY)(unaff_RBP + 0x1f));
  bVar5 = bVar6;
  if (LVar2 == 0) {
    LVar2 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + 0x17 +
                                   (longlong)*(int *)(*(longlong *)(unaff_RBP + 0x17) + 4)),
                          "AspenTech",0,0xf003f,
                          (PHKEY)(unaff_RBP + -9 +
                                 (longlong)*(int *)(*(longlong *)(unaff_RBP + -9) + 4)));
    bVar5 = bVar4;
    if (LVar2 == 0) {
      LVar2 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + -9 +
                                     (longlong)*(int *)(*(longlong *)(unaff_RBP + -9) + 4)),
                            "ASPEN PLUS",0,0xf003f,
                            (PHKEY)(unaff_RBP + -0x29 +
                                   (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x29) + 4)));
      if (LVar2 == 0) {
        hKey = *(HKEY *)(unaff_RBP + -0x29 +
                        (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x29) + 4));
        iVar1 = *(int *)(*(longlong *)(unaff_RBP + -0x49) + 4);
        lpSubKey = (LPCSTR)FUN_180024170();
        LVar2 = RegOpenKeyExA(hKey,lpSubKey,0,0xf003f,(PHKEY)(unaff_RBP + -0x49 + (longlong)iVar1));
        if (LVar2 == 0) {
          LVar2 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + -0x49 +
                                         (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x49) + 4)),
                                "Libraries",0,0xf003f,
                                (PHKEY)(unaff_RBP + -0x69 +
                                       (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x69) + 4)));
          if (LVar2 == 0) {
            *(undefined4 *)(unaff_RBP + 0x67) = 4;
            LVar2 = RegQueryValueExA(*(HKEY *)(unaff_RBP + -0x69 +
                                              (longlong)
                                              *(int *)(*(longlong *)(unaff_RBP + -0x69) + 4)),
                                     "UseACMCatalog",(LPDWORD)0x0,(LPDWORD)0x0,
                                     (LPBYTE)(unaff_RBP + 0x6f),(LPDWORD)(unaff_RBP + 0x67));
            if (LVar2 == 0) {
              bVar6 = *(int *)(unaff_RBP + 0x6f) != 0;
            }
            bVar5 = bVar6;
            if (param_1 != (undefined4 *)0x0) {
              *(undefined4 *)(unaff_RBP + 0x67) = 4;
              LVar2 = RegQueryValueExA(*(HKEY *)(unaff_RBP + -0x69 +
                                                (longlong)
                                                *(int *)(*(longlong *)(unaff_RBP + -0x69) + 4)),
                                       "ACMCatalogPosition",(LPDWORD)0x0,(LPDWORD)0x0,
                                       (LPBYTE)(unaff_RBP + 0x6f),(LPDWORD)(unaff_RBP + 0x67));
              uVar3 = 3;
              if (LVar2 == 0) {
                uVar3 = *(undefined4 *)(unaff_RBP + 0x6f);
              }
              *param_1 = uVar3;
            }
          }
        }
      }
    }
  }
  if (*(HKEY *)(unaff_RBP + -0x61) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x61));
    *(undefined8 *)(unaff_RBP + -0x61) = 0;
  }
  *(undefined4 *)(unaff_RBP + -0x59) = 0;
  if (*(HKEY *)(unaff_RBP + -0x41) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x41));
    *(undefined8 *)(unaff_RBP + -0x41) = 0;
  }
  *(undefined4 *)(unaff_RBP + -0x39) = 0;
  if (*(HKEY *)(unaff_RBP + -0x21) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x21));
    *(undefined8 *)(unaff_RBP + -0x21) = 0;
  }
  *(undefined4 *)(unaff_RBP + -0x19) = 0;
  if (*(HKEY *)(unaff_RBP + -1) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -1));
    *(undefined8 *)(unaff_RBP + -1) = 0;
  }
  *(undefined4 *)(unaff_RBP + 7) = 0;
  if (*(HKEY *)(unaff_RBP + 0x1f) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + 0x1f));
  }
  return bVar5;
}

/* ---- FUNC 000380A3 FUN_1800380a3 (95 bytes) ---- */

ulonglong FUN_1800380a3(void)

{
  int iVar1;
  HKEY hKey;
  LSTATUS LVar2;
  longlong in_RAX;
  LPCSTR lpSubKey;
  longlong unaff_RBP;
  ulonglong unaff_RSI;
  undefined4 *unaff_R14;
  undefined4 uVar3;
  undefined8 unaff_R15;
  
  hKey = *(HKEY *)(unaff_RBP + -0x29 + (longlong)*(int *)(in_RAX + 4));
  iVar1 = *(int *)(*(longlong *)(unaff_RBP + -0x49) + 4);
  lpSubKey = (LPCSTR)FUN_180024170();
  LVar2 = RegOpenKeyExA(hKey,lpSubKey,0,0xf003f,(PHKEY)(unaff_RBP + -0x49 + (longlong)iVar1));
  if (LVar2 == 0) {
    LVar2 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + -0x49 +
                                   (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x49) + 4)),
                          "Libraries",0,0xf003f,
                          (PHKEY)(unaff_RBP + -0x69 +
                                 (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x69) + 4)));
    if (LVar2 == 0) {
      *(undefined4 *)(unaff_RBP + 0x67) = 4;
      LVar2 = RegQueryValueExA(*(HKEY *)(unaff_RBP + -0x69 +
                                        (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x69) + 4)),
                               "UseACMCatalog",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)(unaff_RBP + 0x6f),
                               (LPDWORD)(unaff_RBP + 0x67));
      if (LVar2 == 0) {
        unaff_RSI = CONCAT71((int7)(unaff_RSI >> 8),*(int *)(unaff_RBP + 0x6f) != (int)unaff_RSI);
      }
      if (unaff_R14 != (undefined4 *)0x0) {
        *(undefined4 *)(unaff_RBP + 0x67) = 4;
        LVar2 = RegQueryValueExA(*(HKEY *)(unaff_RBP + -0x69 +
                                          (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x69) + 4)),
                                 "ACMCatalogPosition",(LPDWORD)0x0,(LPDWORD)0x0,
                                 (LPBYTE)(unaff_RBP + 0x6f),(LPDWORD)(unaff_RBP + 0x67));
        uVar3 = 3;
        if (LVar2 == 0) {
          uVar3 = *(undefined4 *)(unaff_RBP + 0x6f);
        }
        *unaff_R14 = uVar3;
      }
    }
  }
  if (*(HKEY *)(unaff_RBP + -0x61) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x61));
    *(undefined8 *)(unaff_RBP + -0x61) = unaff_R15;
  }
  uVar3 = (undefined4)unaff_R15;
  *(undefined4 *)(unaff_RBP + -0x59) = uVar3;
  if (*(HKEY *)(unaff_RBP + -0x41) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x41));
    *(undefined8 *)(unaff_RBP + -0x41) = unaff_R15;
  }
  *(undefined4 *)(unaff_RBP + -0x39) = uVar3;
  if (*(HKEY *)(unaff_RBP + -0x21) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x21));
    *(undefined8 *)(unaff_RBP + -0x21) = unaff_R15;
  }
  *(undefined4 *)(unaff_RBP + -0x19) = uVar3;
  if (*(HKEY *)(unaff_RBP + -1) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -1));
    *(undefined8 *)(unaff_RBP + -1) = unaff_R15;
  }
  *(undefined4 *)(unaff_RBP + 7) = uVar3;
  if (*(HKEY *)(unaff_RBP + 0x1f) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + 0x1f));
  }
  return unaff_RSI & 0xffffffff;
}

/* ---- FUNC 00038102 FUN_180038102 (224 bytes) ---- */

ulonglong FUN_180038102(void)

{
  LSTATUS LVar1;
  longlong unaff_RBP;
  ulonglong unaff_RSI;
  undefined4 *unaff_R14;
  undefined4 uVar2;
  undefined8 unaff_R15;
  
  LVar1 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + -0x49 +
                                 (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x49) + 4)),
                        "Libraries",0,0xf003f,
                        (PHKEY)(unaff_RBP + -0x69 +
                               (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x69) + 4)));
  if (LVar1 == 0) {
    *(undefined4 *)(unaff_RBP + 0x67) = 4;
    LVar1 = RegQueryValueExA(*(HKEY *)(unaff_RBP + -0x69 +
                                      (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x69) + 4)),
                             "UseACMCatalog",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)(unaff_RBP + 0x6f),
                             (LPDWORD)(unaff_RBP + 0x67));
    if (LVar1 == 0) {
      unaff_RSI = CONCAT71((int7)(unaff_RSI >> 8),*(int *)(unaff_RBP + 0x6f) != (int)unaff_RSI);
    }
    if (unaff_R14 != (undefined4 *)0x0) {
      *(undefined4 *)(unaff_RBP + 0x67) = 4;
      LVar1 = RegQueryValueExA(*(HKEY *)(unaff_RBP + -0x69 +
                                        (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x69) + 4)),
                               "ACMCatalogPosition",(LPDWORD)0x0,(LPDWORD)0x0,
                               (LPBYTE)(unaff_RBP + 0x6f),(LPDWORD)(unaff_RBP + 0x67));
      uVar2 = 3;
      if (LVar1 == 0) {
        uVar2 = *(undefined4 *)(unaff_RBP + 0x6f);
      }
      *unaff_R14 = uVar2;
    }
  }
  if (*(HKEY *)(unaff_RBP + -0x61) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x61));
    *(undefined8 *)(unaff_RBP + -0x61) = unaff_R15;
  }
  uVar2 = (undefined4)unaff_R15;
  *(undefined4 *)(unaff_RBP + -0x59) = uVar2;
  if (*(HKEY *)(unaff_RBP + -0x41) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x41));
    *(undefined8 *)(unaff_RBP + -0x41) = unaff_R15;
  }
  *(undefined4 *)(unaff_RBP + -0x39) = uVar2;
  if (*(HKEY *)(unaff_RBP + -0x21) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x21));
    *(undefined8 *)(unaff_RBP + -0x21) = unaff_R15;
  }
  *(undefined4 *)(unaff_RBP + -0x19) = uVar2;
  if (*(HKEY *)(unaff_RBP + -1) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -1));
    *(undefined8 *)(unaff_RBP + -1) = unaff_R15;
  }
  *(undefined4 *)(unaff_RBP + 7) = uVar2;
  if (*(HKEY *)(unaff_RBP + 0x1f) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + 0x1f));
  }
  return unaff_RSI & 0xffffffff;
}

/* ---- FUNC 000381E2 FUN_1800381e2 (100 bytes) ---- */

undefined4 FUN_1800381e2(HKEY param_1)

{
  longlong unaff_RBP;
  undefined4 unaff_ESI;
  undefined4 uVar1;
  undefined8 unaff_R15;
  
  RegCloseKey(param_1);
  *(undefined8 *)(unaff_RBP + -0x61) = unaff_R15;
  uVar1 = (undefined4)unaff_R15;
  *(undefined4 *)(unaff_RBP + -0x59) = uVar1;
  if (*(HKEY *)(unaff_RBP + -0x41) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x41));
    *(undefined8 *)(unaff_RBP + -0x41) = unaff_R15;
  }
  *(undefined4 *)(unaff_RBP + -0x39) = uVar1;
  if (*(HKEY *)(unaff_RBP + -0x21) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x21));
    *(undefined8 *)(unaff_RBP + -0x21) = unaff_R15;
  }
  *(undefined4 *)(unaff_RBP + -0x19) = uVar1;
  if (*(HKEY *)(unaff_RBP + -1) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -1));
    *(undefined8 *)(unaff_RBP + -1) = unaff_R15;
  }
  *(undefined4 *)(unaff_RBP + 7) = uVar1;
  if (*(HKEY *)(unaff_RBP + 0x1f) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + 0x1f));
  }
  return unaff_ESI;
}

/* ---- FUNC 00038246 FUN_180038246 (18 bytes) ---- */

undefined4 FUN_180038246(HKEY param_1)

{
  undefined4 unaff_ESI;
  
  RegCloseKey(param_1);
  return unaff_ESI;
}

/* ---- FUNC 00038260 APModLibUseBuiltin (16 bytes) ---- */

bool APModLibUseBuiltin(int *param_1)

{
  HKEY hKey;
  LSTATUS LVar1;
  LPCSTR lpSubKey;
  bool bVar2;
  bool bVar3;
  int iVar4;
  DWORD local_res8 [2];
  int local_res10 [2];
  HKEY local_c8 [2];
  undefined4 local_b8;
  undefined8 local_b0;
  HKEY local_a8 [2];
  undefined4 local_98;
  undefined8 local_90;
  HKEY local_88 [2];
  undefined4 local_78;
  undefined8 local_70;
  HKEY local_68 [2];
  undefined4 local_58;
  undefined8 local_50;
  HKEY local_48 [2];
  undefined4 local_38;
  undefined8 local_30;
  
                    /* 0x38260  274  APModLibUseBuiltin */
  *param_1 = 1;
  local_48[0] = (HKEY)&DAT_180053988;
  local_68[0] = (HKEY)&DAT_180053988;
  local_88[0] = (HKEY)&DAT_180053988;
  local_a8[0] = (HKEY)&DAT_180053988;
  local_c8[0] = (HKEY)&DAT_180053988;
  bVar2 = true;
  local_48[1] = (HKEY)0x0;
  local_38 = 0;
  local_30 = 0;
  local_68[1] = (HKEY)0x0;
  local_58 = 0;
  local_50 = 0;
  local_88[1] = (HKEY)0x0;
  local_78 = 0;
  local_70 = 0;
  local_a8[1] = (HKEY)0x0;
  local_98 = 0;
  local_90 = 0;
  local_c8[1] = (HKEY)0x0;
  local_b8 = 0;
  local_b0 = 0;
  LVar1 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000001,"Software",0,0xf003f,local_48 + 1);
  bVar3 = true;
  if (((LVar1 == 0) &&
      (LVar1 = RegOpenKeyExA(*(HKEY *)((longlong)local_48 + (longlong)local_48[0][1].unused),
                             "AspenTech",0,0xf003f,
                             (PHKEY)((longlong)local_68 + (longlong)local_68[0][1].unused)),
      bVar3 = true, LVar1 == 0)) &&
     (LVar1 = RegOpenKeyExA(*(HKEY *)((longlong)local_68 + (longlong)local_68[0][1].unused),
                            "ASPEN PLUS",0,0xf003f,
                            (PHKEY)((longlong)local_88 + (longlong)local_88[0][1].unused)),
     bVar3 = bVar2, LVar1 == 0)) {
    hKey = *(HKEY *)((longlong)local_88 + (longlong)local_88[0][1].unused);
    iVar4 = local_a8[0][1].unused;
    lpSubKey = (LPCSTR)FUN_180024170();
    LVar1 = RegOpenKeyExA(hKey,lpSubKey,0,0xf003f,(PHKEY)((longlong)local_a8 + (longlong)iVar4));
    if ((LVar1 == 0) &&
       (LVar1 = RegOpenKeyExA(*(HKEY *)((longlong)local_a8 + (longlong)local_a8[0][1].unused),
                              "Libraries",0,0xf003f,
                              (PHKEY)((longlong)local_c8 + (longlong)local_c8[0][1].unused)),
       LVar1 == 0)) {
      local_res8[0] = 4;
      LVar1 = RegQueryValueExA(*(HKEY *)((longlong)local_c8 + (longlong)local_c8[0][1].unused),
                               "UseBuiltin",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)local_res10,local_res8
                              );
      bVar3 = LVar1 != 0 || local_res10[0] != 0;
      local_res8[0] = 4;
      LVar1 = RegQueryValueExA(*(HKEY *)((longlong)local_c8 + (longlong)local_c8[0][1].unused),
                               "BuiltinPosition",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)local_res10,
                               local_res8);
      iVar4 = 1;
      if (LVar1 == 0) {
        iVar4 = local_res10[0];
      }
      *param_1 = iVar4;
    }
  }
  if (local_c8[1] != (HKEY)0x0) {
    RegCloseKey(local_c8[1]);
    local_c8[1] = (HKEY)0x0;
  }
  local_b8 = 0;
  if (local_a8[1] != (HKEY)0x0) {
    RegCloseKey(local_a8[1]);
    local_a8[1] = (HKEY)0x0;
  }
  local_98 = 0;
  if (local_88[1] != (HKEY)0x0) {
    RegCloseKey(local_88[1]);
    local_88[1] = (HKEY)0x0;
  }
  local_78 = 0;
  if (local_68[1] != (HKEY)0x0) {
    RegCloseKey(local_68[1]);
    local_68[1] = (HKEY)0x0;
  }
  local_58 = 0;
  if (local_48[1] != (HKEY)0x0) {
    RegCloseKey(local_48[1]);
  }
  return bVar3;
}

/* ---- FUNC 00038270 FUN_180038270 (14 bytes) ---- */

bool FUN_180038270(undefined4 *param_1)

{
  int iVar1;
  HKEY hKey;
  LSTATUS LVar2;
  longlong in_RAX;
  LPCSTR lpSubKey;
  longlong unaff_RBP;
  bool bVar3;
  undefined8 unaff_R12;
  undefined4 uVar4;
  undefined8 unaff_R14;
  undefined8 unaff_R15;
  bool bVar5;
  
  *(undefined8 *)(in_RAX + -0x18) = unaff_R12;
  *(undefined8 *)(in_RAX + -0x20) = unaff_R14;
  *(undefined8 *)(in_RAX + -0x28) = unaff_R15;
  *param_1 = 1;
  *(undefined **)(unaff_RBP + 0x17) = &DAT_180053988;
  *(undefined **)(unaff_RBP + -9) = &DAT_180053988;
  *(undefined **)(unaff_RBP + -0x29) = &DAT_180053988;
  *(undefined **)(unaff_RBP + -0x49) = &DAT_180053988;
  *(undefined **)(unaff_RBP + -0x69) = &DAT_180053988;
  bVar5 = true;
  *(undefined8 *)(unaff_RBP + 0x1f) = 0;
  *(undefined4 *)(unaff_RBP + 0x27) = 0;
  *(undefined8 *)(unaff_RBP + 0x2f) = 0;
  *(undefined8 *)(unaff_RBP + -1) = 0;
  *(undefined4 *)(unaff_RBP + 7) = 0;
  *(undefined8 *)(unaff_RBP + 0xf) = 0;
  *(undefined8 *)(unaff_RBP + -0x21) = 0;
  *(undefined4 *)(unaff_RBP + -0x19) = 0;
  *(undefined8 *)(unaff_RBP + -0x11) = 0;
  *(undefined8 *)(unaff_RBP + -0x41) = 0;
  *(undefined4 *)(unaff_RBP + -0x39) = 0;
  *(undefined8 *)(unaff_RBP + -0x31) = 0;
  *(undefined8 *)(unaff_RBP + -0x61) = 0;
  *(undefined4 *)(unaff_RBP + -0x59) = 0;
  *(undefined8 *)(unaff_RBP + -0x51) = 0;
  LVar2 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000001,"Software",0,0xf003f,(PHKEY)(unaff_RBP + 0x1f));
  bVar3 = bVar5;
  if (LVar2 == 0) {
    LVar2 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + 0x17 +
                                   (longlong)*(int *)(*(longlong *)(unaff_RBP + 0x17) + 4)),
                          "AspenTech",0,0xf003f,
                          (PHKEY)(unaff_RBP + -9 +
                                 (longlong)*(int *)(*(longlong *)(unaff_RBP + -9) + 4)));
    if (LVar2 == 0) {
      LVar2 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + -9 +
                                     (longlong)*(int *)(*(longlong *)(unaff_RBP + -9) + 4)),
                            "ASPEN PLUS",0,0xf003f,
                            (PHKEY)(unaff_RBP + -0x29 +
                                   (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x29) + 4)));
      if (LVar2 == 0) {
        hKey = *(HKEY *)(unaff_RBP + -0x29 +
                        (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x29) + 4));
        iVar1 = *(int *)(*(longlong *)(unaff_RBP + -0x49) + 4);
        lpSubKey = (LPCSTR)FUN_180024170();
        LVar2 = RegOpenKeyExA(hKey,lpSubKey,0,0xf003f,(PHKEY)(unaff_RBP + -0x49 + (longlong)iVar1));
        bVar3 = true;
        if (LVar2 == 0) {
          LVar2 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + -0x49 +
                                         (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x49) + 4)),
                                "Libraries",0,0xf003f,
                                (PHKEY)(unaff_RBP + -0x69 +
                                       (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x69) + 4)));
          if (LVar2 == 0) {
            *(undefined4 *)(unaff_RBP + 0x67) = 4;
            LVar2 = RegQueryValueExA(*(HKEY *)(unaff_RBP + -0x69 +
                                              (longlong)
                                              *(int *)(*(longlong *)(unaff_RBP + -0x69) + 4)),
                                     "UseBuiltin",(LPDWORD)0x0,(LPDWORD)0x0,
                                     (LPBYTE)(unaff_RBP + 0x6f),(LPDWORD)(unaff_RBP + 0x67));
            if (LVar2 == 0) {
              bVar5 = *(int *)(unaff_RBP + 0x6f) != 0;
            }
            *(undefined4 *)(unaff_RBP + 0x67) = 4;
            LVar2 = RegQueryValueExA(*(HKEY *)(unaff_RBP + -0x69 +
                                              (longlong)
                                              *(int *)(*(longlong *)(unaff_RBP + -0x69) + 4)),
                                     "BuiltinPosition",(LPDWORD)0x0,(LPDWORD)0x0,
                                     (LPBYTE)(unaff_RBP + 0x6f),(LPDWORD)(unaff_RBP + 0x67));
            uVar4 = 1;
            if (LVar2 == 0) {
              uVar4 = *(undefined4 *)(unaff_RBP + 0x6f);
            }
            *param_1 = uVar4;
            bVar3 = bVar5;
          }
        }
      }
    }
  }
  if (*(HKEY *)(unaff_RBP + -0x61) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x61));
    *(undefined8 *)(unaff_RBP + -0x61) = 0;
  }
  *(undefined4 *)(unaff_RBP + -0x59) = 0;
  if (*(HKEY *)(unaff_RBP + -0x41) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x41));
    *(undefined8 *)(unaff_RBP + -0x41) = 0;
  }
  *(undefined4 *)(unaff_RBP + -0x39) = 0;
  if (*(HKEY *)(unaff_RBP + -0x21) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x21));
    *(undefined8 *)(unaff_RBP + -0x21) = 0;
  }
  *(undefined4 *)(unaff_RBP + -0x19) = 0;
  if (*(HKEY *)(unaff_RBP + -1) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -1));
    *(undefined8 *)(unaff_RBP + -1) = 0;
  }
  *(undefined4 *)(unaff_RBP + 7) = 0;
  if (*(HKEY *)(unaff_RBP + 0x1f) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + 0x1f));
  }
  return bVar3;
}

/* ---- FUNC 0003827E FUN_18003827e (279 bytes) ---- */

ulonglong FUN_18003827e(undefined4 *param_1,LPCSTR param_2)

{
  int iVar1;
  HKEY hKey;
  LSTATUS LVar2;
  longlong in_RAX;
  LPCSTR lpSubKey;
  longlong unaff_RBP;
  ulonglong uVar3;
  ulonglong uVar4;
  int iVar5;
  undefined8 unaff_R12;
  undefined4 uVar6;
  undefined8 unaff_R14;
  undefined8 unaff_R15;
  
  *(undefined8 *)(in_RAX + -0x20) = unaff_R14;
  *(undefined8 *)(in_RAX + -0x28) = unaff_R15;
  *param_1 = 1;
  *(undefined **)(unaff_RBP + 0x17) = &DAT_180053988;
  *(undefined **)(unaff_RBP + -9) = &DAT_180053988;
  *(undefined **)(unaff_RBP + -0x29) = &DAT_180053988;
  *(undefined **)(unaff_RBP + -0x49) = &DAT_180053988;
  *(undefined **)(unaff_RBP + -0x69) = &DAT_180053988;
  uVar3 = 1;
  *(undefined8 *)(unaff_RBP + 0x1f) = unaff_R12;
  iVar5 = (int)unaff_R12;
  *(int *)(unaff_RBP + 0x27) = iVar5;
  *(undefined8 *)(unaff_RBP + 0x2f) = unaff_R12;
  *(undefined8 *)(unaff_RBP + -1) = unaff_R12;
  *(int *)(unaff_RBP + 7) = iVar5;
  *(undefined8 *)(unaff_RBP + 0xf) = unaff_R12;
  *(undefined8 *)(unaff_RBP + -0x21) = unaff_R12;
  *(int *)(unaff_RBP + -0x19) = iVar5;
  *(undefined8 *)(unaff_RBP + -0x11) = unaff_R12;
  *(undefined8 *)(unaff_RBP + -0x41) = unaff_R12;
  *(int *)(unaff_RBP + -0x39) = iVar5;
  *(undefined8 *)(unaff_RBP + -0x31) = unaff_R12;
  *(undefined8 *)(unaff_RBP + -0x61) = unaff_R12;
  *(int *)(unaff_RBP + -0x59) = iVar5;
  *(undefined8 *)(unaff_RBP + -0x51) = unaff_R12;
  LVar2 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000001,param_2,0,0xf003f,(PHKEY)(unaff_RBP + 0x1f));
  uVar4 = uVar3;
  if (LVar2 == 0) {
    LVar2 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + 0x17 +
                                   (longlong)*(int *)(*(longlong *)(unaff_RBP + 0x17) + 4)),
                          "AspenTech",0,0xf003f,
                          (PHKEY)(unaff_RBP + -9 +
                                 (longlong)*(int *)(*(longlong *)(unaff_RBP + -9) + 4)));
    if (LVar2 == 0) {
      LVar2 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + -9 +
                                     (longlong)*(int *)(*(longlong *)(unaff_RBP + -9) + 4)),
                            "ASPEN PLUS",0,0xf003f,
                            (PHKEY)(unaff_RBP + -0x29 +
                                   (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x29) + 4)));
      if (LVar2 == 0) {
        hKey = *(HKEY *)(unaff_RBP + -0x29 +
                        (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x29) + 4));
        iVar1 = *(int *)(*(longlong *)(unaff_RBP + -0x49) + 4);
        lpSubKey = (LPCSTR)FUN_180024170();
        LVar2 = RegOpenKeyExA(hKey,lpSubKey,0,0xf003f,(PHKEY)(unaff_RBP + -0x49 + (longlong)iVar1));
        uVar4 = 1;
        if (LVar2 == 0) {
          LVar2 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + -0x49 +
                                         (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x49) + 4)),
                                "Libraries",0,0xf003f,
                                (PHKEY)(unaff_RBP + -0x69 +
                                       (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x69) + 4)));
          if (LVar2 == 0) {
            *(undefined4 *)(unaff_RBP + 0x67) = 4;
            LVar2 = RegQueryValueExA(*(HKEY *)(unaff_RBP + -0x69 +
                                              (longlong)
                                              *(int *)(*(longlong *)(unaff_RBP + -0x69) + 4)),
                                     "UseBuiltin",(LPDWORD)0x0,(LPDWORD)0x0,
                                     (LPBYTE)(unaff_RBP + 0x6f),(LPDWORD)(unaff_RBP + 0x67));
            if (LVar2 == 0) {
              uVar3 = CONCAT71((int7)((ulonglong)unaff_R12 >> 8),*(int *)(unaff_RBP + 0x6f) != iVar5
                              ) & 0xffffffff;
            }
            *(undefined4 *)(unaff_RBP + 0x67) = 4;
            LVar2 = RegQueryValueExA(*(HKEY *)(unaff_RBP + -0x69 +
                                              (longlong)
                                              *(int *)(*(longlong *)(unaff_RBP + -0x69) + 4)),
                                     "BuiltinPosition",(LPDWORD)0x0,(LPDWORD)0x0,
                                     (LPBYTE)(unaff_RBP + 0x6f),(LPDWORD)(unaff_RBP + 0x67));
            uVar6 = 1;
            if (LVar2 == 0) {
              uVar6 = *(undefined4 *)(unaff_RBP + 0x6f);
            }
            *param_1 = uVar6;
            uVar4 = uVar3;
          }
        }
      }
    }
  }
  if (*(HKEY *)(unaff_RBP + -0x61) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x61));
    *(undefined8 *)(unaff_RBP + -0x61) = unaff_R12;
  }
  *(int *)(unaff_RBP + -0x59) = iVar5;
  if (*(HKEY *)(unaff_RBP + -0x41) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x41));
    *(undefined8 *)(unaff_RBP + -0x41) = unaff_R12;
  }
  *(int *)(unaff_RBP + -0x39) = iVar5;
  if (*(HKEY *)(unaff_RBP + -0x21) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x21));
    *(undefined8 *)(unaff_RBP + -0x21) = unaff_R12;
  }
  *(int *)(unaff_RBP + -0x19) = iVar5;
  if (*(HKEY *)(unaff_RBP + -1) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -1));
    *(undefined8 *)(unaff_RBP + -1) = unaff_R12;
  }
  *(int *)(unaff_RBP + 7) = iVar5;
  if (*(HKEY *)(unaff_RBP + 0x1f) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + 0x1f));
  }
  return uVar4;
}

/* ---- FUNC 00038395 FUN_180038395 (95 bytes) ---- */

ulonglong FUN_180038395(void)

{
  HKEY hKey;
  LSTATUS LVar1;
  longlong in_RAX;
  LPCSTR lpSubKey;
  longlong unaff_RBP;
  ulonglong unaff_RSI;
  int iVar2;
  undefined8 unaff_R12;
  undefined4 unaff_R14D;
  undefined4 *unaff_R15;
  
  hKey = *(HKEY *)(unaff_RBP + -0x29 + (longlong)*(int *)(in_RAX + 4));
  iVar2 = *(int *)(*(longlong *)(unaff_RBP + -0x49) + 4);
  lpSubKey = (LPCSTR)FUN_180024170();
  LVar1 = RegOpenKeyExA(hKey,lpSubKey,0,0xf003f,(PHKEY)(unaff_RBP + -0x49 + (longlong)iVar2));
  iVar2 = (int)unaff_R12;
  if (LVar1 == 0) {
    LVar1 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + -0x49 +
                                   (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x49) + 4)),
                          "Libraries",0,0xf003f,
                          (PHKEY)(unaff_RBP + -0x69 +
                                 (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x69) + 4)));
    if (LVar1 == 0) {
      *(undefined4 *)(unaff_RBP + 0x67) = 4;
      LVar1 = RegQueryValueExA(*(HKEY *)(unaff_RBP + -0x69 +
                                        (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x69) + 4)),
                               "UseBuiltin",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)(unaff_RBP + 0x6f),
                               (LPDWORD)(unaff_RBP + 0x67));
      if (LVar1 == 0) {
        unaff_RSI = CONCAT71((int7)((ulonglong)unaff_R12 >> 8),*(int *)(unaff_RBP + 0x6f) != iVar2)
                    & 0xffffffff;
      }
      *(undefined4 *)(unaff_RBP + 0x67) = 4;
      LVar1 = RegQueryValueExA(*(HKEY *)(unaff_RBP + -0x69 +
                                        (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x69) + 4)),
                               "BuiltinPosition",(LPDWORD)0x0,(LPDWORD)0x0,
                               (LPBYTE)(unaff_RBP + 0x6f),(LPDWORD)(unaff_RBP + 0x67));
      if (LVar1 == 0) {
        unaff_R14D = *(undefined4 *)(unaff_RBP + 0x6f);
      }
      *unaff_R15 = unaff_R14D;
    }
  }
  if (*(HKEY *)(unaff_RBP + -0x61) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x61));
    *(undefined8 *)(unaff_RBP + -0x61) = unaff_R12;
  }
  *(int *)(unaff_RBP + -0x59) = iVar2;
  if (*(HKEY *)(unaff_RBP + -0x41) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x41));
    *(undefined8 *)(unaff_RBP + -0x41) = unaff_R12;
  }
  *(int *)(unaff_RBP + -0x39) = iVar2;
  if (*(HKEY *)(unaff_RBP + -0x21) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x21));
    *(undefined8 *)(unaff_RBP + -0x21) = unaff_R12;
  }
  *(int *)(unaff_RBP + -0x19) = iVar2;
  if (*(HKEY *)(unaff_RBP + -1) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -1));
    *(undefined8 *)(unaff_RBP + -1) = unaff_R12;
  }
  *(int *)(unaff_RBP + 7) = iVar2;
  if (*(HKEY *)(unaff_RBP + 0x1f) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + 0x1f));
  }
  return unaff_RSI & 0xffffffff;
}

/* ---- FUNC 000383F4 FUN_1800383f4 (227 bytes) ---- */

ulonglong FUN_1800383f4(void)

{
  LSTATUS LVar1;
  longlong unaff_RBP;
  ulonglong unaff_RSI;
  int iVar2;
  undefined8 unaff_R12;
  undefined4 unaff_R14D;
  undefined4 *unaff_R15;
  
  LVar1 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + -0x49 +
                                 (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x49) + 4)),
                        "Libraries",0,0xf003f,
                        (PHKEY)(unaff_RBP + -0x69 +
                               (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x69) + 4)));
  iVar2 = (int)unaff_R12;
  if (LVar1 == 0) {
    *(undefined4 *)(unaff_RBP + 0x67) = 4;
    LVar1 = RegQueryValueExA(*(HKEY *)(unaff_RBP + -0x69 +
                                      (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x69) + 4)),
                             "UseBuiltin",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)(unaff_RBP + 0x6f),
                             (LPDWORD)(unaff_RBP + 0x67));
    if (LVar1 == 0) {
      unaff_RSI = CONCAT71((int7)((ulonglong)unaff_R12 >> 8),*(int *)(unaff_RBP + 0x6f) != iVar2) &
                  0xffffffff;
    }
    *(undefined4 *)(unaff_RBP + 0x67) = 4;
    LVar1 = RegQueryValueExA(*(HKEY *)(unaff_RBP + -0x69 +
                                      (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x69) + 4)),
                             "BuiltinPosition",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)(unaff_RBP + 0x6f),
                             (LPDWORD)(unaff_RBP + 0x67));
    if (LVar1 == 0) {
      unaff_R14D = *(undefined4 *)(unaff_RBP + 0x6f);
    }
    *unaff_R15 = unaff_R14D;
  }
  if (*(HKEY *)(unaff_RBP + -0x61) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x61));
    *(undefined8 *)(unaff_RBP + -0x61) = unaff_R12;
  }
  *(int *)(unaff_RBP + -0x59) = iVar2;
  if (*(HKEY *)(unaff_RBP + -0x41) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x41));
    *(undefined8 *)(unaff_RBP + -0x41) = unaff_R12;
  }
  *(int *)(unaff_RBP + -0x39) = iVar2;
  if (*(HKEY *)(unaff_RBP + -0x21) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x21));
    *(undefined8 *)(unaff_RBP + -0x21) = unaff_R12;
  }
  *(int *)(unaff_RBP + -0x19) = iVar2;
  if (*(HKEY *)(unaff_RBP + -1) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -1));
    *(undefined8 *)(unaff_RBP + -1) = unaff_R12;
  }
  *(int *)(unaff_RBP + 7) = iVar2;
  if (*(HKEY *)(unaff_RBP + 0x1f) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + 0x1f));
  }
  return unaff_RSI & 0xffffffff;
}

/* ---- FUNC 000384D7 FUN_1800384d7 (100 bytes) ---- */

undefined4 FUN_1800384d7(HKEY param_1)

{
  longlong unaff_RBP;
  undefined4 unaff_ESI;
  undefined4 uVar1;
  undefined8 unaff_R12;
  
  RegCloseKey(param_1);
  *(undefined8 *)(unaff_RBP + -0x61) = unaff_R12;
  uVar1 = (undefined4)unaff_R12;
  *(undefined4 *)(unaff_RBP + -0x59) = uVar1;
  if (*(HKEY *)(unaff_RBP + -0x41) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x41));
    *(undefined8 *)(unaff_RBP + -0x41) = unaff_R12;
  }
  *(undefined4 *)(unaff_RBP + -0x39) = uVar1;
  if (*(HKEY *)(unaff_RBP + -0x21) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x21));
    *(undefined8 *)(unaff_RBP + -0x21) = unaff_R12;
  }
  *(undefined4 *)(unaff_RBP + -0x19) = uVar1;
  if (*(HKEY *)(unaff_RBP + -1) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -1));
    *(undefined8 *)(unaff_RBP + -1) = unaff_R12;
  }
  *(undefined4 *)(unaff_RBP + 7) = uVar1;
  if (*(HKEY *)(unaff_RBP + 0x1f) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + 0x1f));
  }
  return unaff_ESI;
}

/* ---- FUNC 0003853B FUN_18003853b (18 bytes) ---- */

undefined4 FUN_18003853b(HKEY param_1)

{
  undefined4 unaff_ESI;
  
  RegCloseKey(param_1);
  return unaff_ESI;
}

/* ---- FUNC 00038550 APModLibUseCapeOpen (16 bytes) ---- */

bool APModLibUseCapeOpen(int *param_1)

{
  HKEY hKey;
  LSTATUS LVar1;
  LPCSTR lpSubKey;
  int iVar2;
  bool bVar3;
  bool bVar4;
  DWORD local_res8 [2];
  int local_res10 [2];
  HKEY local_c8 [2];
  undefined4 local_b8;
  undefined8 local_b0;
  HKEY local_a8 [2];
  undefined4 local_98;
  undefined8 local_90;
  HKEY local_88 [2];
  undefined4 local_78;
  undefined8 local_70;
  HKEY local_68 [2];
  undefined4 local_58;
  undefined8 local_50;
  HKEY local_48 [2];
  undefined4 local_38;
  undefined8 local_30;
  
                    /* 0x38550  275  APModLibUseCapeOpen */
  local_48[1] = (HKEY)0x0;
  local_48[0] = (HKEY)&DAT_180053988;
  bVar3 = false;
  local_38 = 0;
  local_30 = 0;
  local_68[0] = (HKEY)&DAT_180053988;
  local_68[1] = (HKEY)0x0;
  local_58 = 0;
  local_50 = 0;
  local_88[0] = (HKEY)&DAT_180053988;
  local_88[1] = (HKEY)0x0;
  local_78 = 0;
  local_70 = 0;
  local_a8[0] = (HKEY)&DAT_180053988;
  local_a8[1] = (HKEY)0x0;
  local_98 = 0;
  local_90 = 0;
  local_c8[0] = (HKEY)&DAT_180053988;
  local_c8[1] = (HKEY)0x0;
  local_b8 = 0;
  local_b0 = 0;
  if (param_1 != (int *)0x0) {
    *param_1 = -1;
  }
  LVar1 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000001,"Software",0,0xf003f,local_48 + 1);
  bVar4 = false;
  if (((LVar1 == 0) &&
      (LVar1 = RegOpenKeyExA(*(HKEY *)((longlong)local_48 + (longlong)local_48[0][1].unused),
                             "AspenTech",0,0xf003f,
                             (PHKEY)((longlong)local_68 + (longlong)local_68[0][1].unused)),
      bVar4 = bVar3, LVar1 == 0)) &&
     (LVar1 = RegOpenKeyExA(*(HKEY *)((longlong)local_68 + (longlong)local_68[0][1].unused),
                            "ASPEN PLUS",0,0xf003f,
                            (PHKEY)((longlong)local_88 + (longlong)local_88[0][1].unused)),
     LVar1 == 0)) {
    hKey = *(HKEY *)((longlong)local_88 + (longlong)local_88[0][1].unused);
    iVar2 = local_a8[0][1].unused;
    lpSubKey = (LPCSTR)FUN_180024170();
    LVar1 = RegOpenKeyExA(hKey,lpSubKey,0,0xf003f,(PHKEY)((longlong)local_a8 + (longlong)iVar2));
    if ((LVar1 == 0) &&
       (LVar1 = RegOpenKeyExA(*(HKEY *)((longlong)local_a8 + (longlong)local_a8[0][1].unused),
                              "Libraries",0,0xf003f,
                              (PHKEY)((longlong)local_c8 + (longlong)local_c8[0][1].unused)),
       LVar1 == 0)) {
      local_res8[0] = 4;
      LVar1 = RegQueryValueExA(*(HKEY *)((longlong)local_c8 + (longlong)local_c8[0][1].unused),
                               "UseCapeOpen",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)local_res10,
                               local_res8);
      bVar4 = LVar1 == 0 && local_res10[0] != 0;
      if (param_1 != (int *)0x0) {
        local_res8[0] = 4;
        LVar1 = RegQueryValueExA(*(HKEY *)((longlong)local_c8 + (longlong)local_c8[0][1].unused),
                                 "CapeOpenPosition",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)local_res10,
                                 local_res8);
        iVar2 = 2;
        if (LVar1 == 0) {
          iVar2 = local_res10[0];
        }
        *param_1 = iVar2;
      }
    }
  }
  if (local_c8[1] != (HKEY)0x0) {
    RegCloseKey(local_c8[1]);
    local_c8[1] = (HKEY)0x0;
  }
  local_b8 = 0;
  if (local_a8[1] != (HKEY)0x0) {
    RegCloseKey(local_a8[1]);
    local_a8[1] = (HKEY)0x0;
  }
  local_98 = 0;
  if (local_88[1] != (HKEY)0x0) {
    RegCloseKey(local_88[1]);
    local_88[1] = (HKEY)0x0;
  }
  local_78 = 0;
  if (local_68[1] != (HKEY)0x0) {
    RegCloseKey(local_68[1]);
    local_68[1] = (HKEY)0x0;
  }
  local_58 = 0;
  if (local_48[1] != (HKEY)0x0) {
    RegCloseKey(local_48[1]);
  }
  return bVar4;
}

/* ---- FUNC 00038560 FUN_180038560 (291 bytes) ---- */

bool FUN_180038560(undefined4 *param_1)

{
  int iVar1;
  HKEY hKey;
  LSTATUS LVar2;
  longlong in_RAX;
  LPCSTR lpSubKey;
  undefined4 uVar3;
  longlong unaff_RBP;
  bool bVar4;
  bool bVar5;
  undefined8 unaff_R14;
  undefined8 unaff_R15;
  bool bVar6;
  
  *(undefined8 *)(in_RAX + -0x20) = unaff_R14;
  *(undefined8 *)(in_RAX + -0x28) = unaff_R15;
  bVar6 = false;
  *(undefined8 *)(unaff_RBP + 0x1f) = 0;
  *(undefined **)(unaff_RBP + 0x17) = &DAT_180053988;
  bVar4 = false;
  *(undefined4 *)(unaff_RBP + 0x27) = 0;
  *(undefined8 *)(unaff_RBP + 0x2f) = 0;
  *(undefined **)(unaff_RBP + -9) = &DAT_180053988;
  *(undefined8 *)(unaff_RBP + -1) = 0;
  *(undefined4 *)(unaff_RBP + 7) = 0;
  *(undefined8 *)(unaff_RBP + 0xf) = 0;
  *(undefined **)(unaff_RBP + -0x29) = &DAT_180053988;
  *(undefined8 *)(unaff_RBP + -0x21) = 0;
  *(undefined4 *)(unaff_RBP + -0x19) = 0;
  *(undefined8 *)(unaff_RBP + -0x11) = 0;
  *(undefined **)(unaff_RBP + -0x49) = &DAT_180053988;
  *(undefined8 *)(unaff_RBP + -0x41) = 0;
  *(undefined4 *)(unaff_RBP + -0x39) = 0;
  *(undefined8 *)(unaff_RBP + -0x31) = 0;
  *(undefined **)(unaff_RBP + -0x69) = &DAT_180053988;
  *(undefined8 *)(unaff_RBP + -0x61) = 0;
  *(undefined4 *)(unaff_RBP + -0x59) = 0;
  *(undefined8 *)(unaff_RBP + -0x51) = 0;
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0xffffffff;
  }
  LVar2 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000001,"Software",0,0xf003f,(PHKEY)(unaff_RBP + 0x1f));
  bVar5 = bVar6;
  if (LVar2 == 0) {
    LVar2 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + 0x17 +
                                   (longlong)*(int *)(*(longlong *)(unaff_RBP + 0x17) + 4)),
                          "AspenTech",0,0xf003f,
                          (PHKEY)(unaff_RBP + -9 +
                                 (longlong)*(int *)(*(longlong *)(unaff_RBP + -9) + 4)));
    bVar5 = bVar4;
    if (LVar2 == 0) {
      LVar2 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + -9 +
                                     (longlong)*(int *)(*(longlong *)(unaff_RBP + -9) + 4)),
                            "ASPEN PLUS",0,0xf003f,
                            (PHKEY)(unaff_RBP + -0x29 +
                                   (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x29) + 4)));
      if (LVar2 == 0) {
        hKey = *(HKEY *)(unaff_RBP + -0x29 +
                        (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x29) + 4));
        iVar1 = *(int *)(*(longlong *)(unaff_RBP + -0x49) + 4);
        lpSubKey = (LPCSTR)FUN_180024170();
        LVar2 = RegOpenKeyExA(hKey,lpSubKey,0,0xf003f,(PHKEY)(unaff_RBP + -0x49 + (longlong)iVar1));
        if (LVar2 == 0) {
          LVar2 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + -0x49 +
                                         (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x49) + 4)),
                                "Libraries",0,0xf003f,
                                (PHKEY)(unaff_RBP + -0x69 +
                                       (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x69) + 4)));
          if (LVar2 == 0) {
            *(undefined4 *)(unaff_RBP + 0x67) = 4;
            LVar2 = RegQueryValueExA(*(HKEY *)(unaff_RBP + -0x69 +
                                              (longlong)
                                              *(int *)(*(longlong *)(unaff_RBP + -0x69) + 4)),
                                     "UseCapeOpen",(LPDWORD)0x0,(LPDWORD)0x0,
                                     (LPBYTE)(unaff_RBP + 0x6f),(LPDWORD)(unaff_RBP + 0x67));
            if (LVar2 == 0) {
              bVar6 = *(int *)(unaff_RBP + 0x6f) != 0;
            }
            bVar5 = bVar6;
            if (param_1 != (undefined4 *)0x0) {
              *(undefined4 *)(unaff_RBP + 0x67) = 4;
              LVar2 = RegQueryValueExA(*(HKEY *)(unaff_RBP + -0x69 +
                                                (longlong)
                                                *(int *)(*(longlong *)(unaff_RBP + -0x69) + 4)),
                                       "CapeOpenPosition",(LPDWORD)0x0,(LPDWORD)0x0,
                                       (LPBYTE)(unaff_RBP + 0x6f),(LPDWORD)(unaff_RBP + 0x67));
              uVar3 = 2;
              if (LVar2 == 0) {
                uVar3 = *(undefined4 *)(unaff_RBP + 0x6f);
              }
              *param_1 = uVar3;
            }
          }
        }
      }
    }
  }
  if (*(HKEY *)(unaff_RBP + -0x61) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x61));
    *(undefined8 *)(unaff_RBP + -0x61) = 0;
  }
  *(undefined4 *)(unaff_RBP + -0x59) = 0;
  if (*(HKEY *)(unaff_RBP + -0x41) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x41));
    *(undefined8 *)(unaff_RBP + -0x41) = 0;
  }
  *(undefined4 *)(unaff_RBP + -0x39) = 0;
  if (*(HKEY *)(unaff_RBP + -0x21) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x21));
    *(undefined8 *)(unaff_RBP + -0x21) = 0;
  }
  *(undefined4 *)(unaff_RBP + -0x19) = 0;
  if (*(HKEY *)(unaff_RBP + -1) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -1));
    *(undefined8 *)(unaff_RBP + -1) = 0;
  }
  *(undefined4 *)(unaff_RBP + 7) = 0;
  if (*(HKEY *)(unaff_RBP + 0x1f) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + 0x1f));
  }
  return bVar5;
}

/* ---- FUNC 00038683 FUN_180038683 (95 bytes) ---- */

ulonglong FUN_180038683(void)

{
  int iVar1;
  HKEY hKey;
  LSTATUS LVar2;
  longlong in_RAX;
  LPCSTR lpSubKey;
  longlong unaff_RBP;
  ulonglong unaff_RSI;
  undefined4 *unaff_R14;
  undefined4 uVar3;
  undefined8 unaff_R15;
  
  hKey = *(HKEY *)(unaff_RBP + -0x29 + (longlong)*(int *)(in_RAX + 4));
  iVar1 = *(int *)(*(longlong *)(unaff_RBP + -0x49) + 4);
  lpSubKey = (LPCSTR)FUN_180024170();
  LVar2 = RegOpenKeyExA(hKey,lpSubKey,0,0xf003f,(PHKEY)(unaff_RBP + -0x49 + (longlong)iVar1));
  if (LVar2 == 0) {
    LVar2 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + -0x49 +
                                   (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x49) + 4)),
                          "Libraries",0,0xf003f,
                          (PHKEY)(unaff_RBP + -0x69 +
                                 (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x69) + 4)));
    if (LVar2 == 0) {
      *(undefined4 *)(unaff_RBP + 0x67) = 4;
      LVar2 = RegQueryValueExA(*(HKEY *)(unaff_RBP + -0x69 +
                                        (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x69) + 4)),
                               "UseCapeOpen",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)(unaff_RBP + 0x6f),
                               (LPDWORD)(unaff_RBP + 0x67));
      if (LVar2 == 0) {
        unaff_RSI = CONCAT71((int7)(unaff_RSI >> 8),*(int *)(unaff_RBP + 0x6f) != (int)unaff_RSI);
      }
      if (unaff_R14 != (undefined4 *)0x0) {
        *(undefined4 *)(unaff_RBP + 0x67) = 4;
        LVar2 = RegQueryValueExA(*(HKEY *)(unaff_RBP + -0x69 +
                                          (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x69) + 4)),
                                 "CapeOpenPosition",(LPDWORD)0x0,(LPDWORD)0x0,
                                 (LPBYTE)(unaff_RBP + 0x6f),(LPDWORD)(unaff_RBP + 0x67));
        uVar3 = 2;
        if (LVar2 == 0) {
          uVar3 = *(undefined4 *)(unaff_RBP + 0x6f);
        }
        *unaff_R14 = uVar3;
      }
    }
  }
  if (*(HKEY *)(unaff_RBP + -0x61) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x61));
    *(undefined8 *)(unaff_RBP + -0x61) = unaff_R15;
  }
  uVar3 = (undefined4)unaff_R15;
  *(undefined4 *)(unaff_RBP + -0x59) = uVar3;
  if (*(HKEY *)(unaff_RBP + -0x41) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x41));
    *(undefined8 *)(unaff_RBP + -0x41) = unaff_R15;
  }
  *(undefined4 *)(unaff_RBP + -0x39) = uVar3;
  if (*(HKEY *)(unaff_RBP + -0x21) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x21));
    *(undefined8 *)(unaff_RBP + -0x21) = unaff_R15;
  }
  *(undefined4 *)(unaff_RBP + -0x19) = uVar3;
  if (*(HKEY *)(unaff_RBP + -1) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -1));
    *(undefined8 *)(unaff_RBP + -1) = unaff_R15;
  }
  *(undefined4 *)(unaff_RBP + 7) = uVar3;
  if (*(HKEY *)(unaff_RBP + 0x1f) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + 0x1f));
  }
  return unaff_RSI & 0xffffffff;
}

/* ---- FUNC 000386E2 FUN_1800386e2 (224 bytes) ---- */

ulonglong FUN_1800386e2(void)

{
  LSTATUS LVar1;
  longlong unaff_RBP;
  ulonglong unaff_RSI;
  undefined4 *unaff_R14;
  undefined4 uVar2;
  undefined8 unaff_R15;
  
  LVar1 = RegOpenKeyExA(*(HKEY *)(unaff_RBP + -0x49 +
                                 (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x49) + 4)),
                        "Libraries",0,0xf003f,
                        (PHKEY)(unaff_RBP + -0x69 +
                               (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x69) + 4)));
  if (LVar1 == 0) {
    *(undefined4 *)(unaff_RBP + 0x67) = 4;
    LVar1 = RegQueryValueExA(*(HKEY *)(unaff_RBP + -0x69 +
                                      (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x69) + 4)),
                             "UseCapeOpen",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)(unaff_RBP + 0x6f),
                             (LPDWORD)(unaff_RBP + 0x67));
    if (LVar1 == 0) {
      unaff_RSI = CONCAT71((int7)(unaff_RSI >> 8),*(int *)(unaff_RBP + 0x6f) != (int)unaff_RSI);
    }
    if (unaff_R14 != (undefined4 *)0x0) {
      *(undefined4 *)(unaff_RBP + 0x67) = 4;
      LVar1 = RegQueryValueExA(*(HKEY *)(unaff_RBP + -0x69 +
                                        (longlong)*(int *)(*(longlong *)(unaff_RBP + -0x69) + 4)),
                               "CapeOpenPosition",(LPDWORD)0x0,(LPDWORD)0x0,
                               (LPBYTE)(unaff_RBP + 0x6f),(LPDWORD)(unaff_RBP + 0x67));
      uVar2 = 2;
      if (LVar1 == 0) {
        uVar2 = *(undefined4 *)(unaff_RBP + 0x6f);
      }
      *unaff_R14 = uVar2;
    }
  }
  if (*(HKEY *)(unaff_RBP + -0x61) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x61));
    *(undefined8 *)(unaff_RBP + -0x61) = unaff_R15;
  }
  uVar2 = (undefined4)unaff_R15;
  *(undefined4 *)(unaff_RBP + -0x59) = uVar2;
  if (*(HKEY *)(unaff_RBP + -0x41) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x41));
    *(undefined8 *)(unaff_RBP + -0x41) = unaff_R15;
  }
  *(undefined4 *)(unaff_RBP + -0x39) = uVar2;
  if (*(HKEY *)(unaff_RBP + -0x21) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x21));
    *(undefined8 *)(unaff_RBP + -0x21) = unaff_R15;
  }
  *(undefined4 *)(unaff_RBP + -0x19) = uVar2;
  if (*(HKEY *)(unaff_RBP + -1) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -1));
    *(undefined8 *)(unaff_RBP + -1) = unaff_R15;
  }
  *(undefined4 *)(unaff_RBP + 7) = uVar2;
  if (*(HKEY *)(unaff_RBP + 0x1f) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + 0x1f));
  }
  return unaff_RSI & 0xffffffff;
}

/* ---- FUNC 000387C2 FUN_1800387c2 (100 bytes) ---- */

undefined4 FUN_1800387c2(HKEY param_1)

{
  longlong unaff_RBP;
  undefined4 unaff_ESI;
  undefined4 uVar1;
  undefined8 unaff_R15;
  
  RegCloseKey(param_1);
  *(undefined8 *)(unaff_RBP + -0x61) = unaff_R15;
  uVar1 = (undefined4)unaff_R15;
  *(undefined4 *)(unaff_RBP + -0x59) = uVar1;
  if (*(HKEY *)(unaff_RBP + -0x41) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x41));
    *(undefined8 *)(unaff_RBP + -0x41) = unaff_R15;
  }
  *(undefined4 *)(unaff_RBP + -0x39) = uVar1;
  if (*(HKEY *)(unaff_RBP + -0x21) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -0x21));
    *(undefined8 *)(unaff_RBP + -0x21) = unaff_R15;
  }
  *(undefined4 *)(unaff_RBP + -0x19) = uVar1;
  if (*(HKEY *)(unaff_RBP + -1) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + -1));
    *(undefined8 *)(unaff_RBP + -1) = unaff_R15;
  }
  *(undefined4 *)(unaff_RBP + 7) = uVar1;
  if (*(HKEY *)(unaff_RBP + 0x1f) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(unaff_RBP + 0x1f));
  }
  return unaff_ESI;
}

/* ---- FUNC 00038826 FUN_180038826 (18 bytes) ---- */

undefined4 FUN_180038826(HKEY param_1)

{
  undefined4 unaff_ESI;
  
  RegCloseKey(param_1);
  return unaff_ESI;
}

/* ---- FUNC 00038840 GetModLibDocName (1164 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 GetModLibDocName(LPCSTR param_1,char *param_2,int param_3)

{
  WCHAR *pwcsName;
  _func_5398 *p_Var1;
  code *pcVar2;
  _func_5396 *p_Var3;
  ulonglong uVar4;
  LPSTORAGE pIVar5;
  uint uVar6;
  longlong *plVar7;
  HRESULT HVar8;
  char *_Source;
  undefined8 uVar9;
  int iVar10;
  longlong lVar11;
  ulonglong uVar12;
  undefined1 *puVar13;
  DWORD *pDVar14;
  undefined8 uStack_c0;
  undefined1 auStack_b8 [24];
  undefined8 uStack_a0;
  DWORD aDStack_98 [2];
  longlong lStack_90;
  OLECHAR local_88 [8];
  DWORD local_78 [2];
  longlong lStack_70;
  uint local_68 [2];
  LPSTORAGE local_60;
  uint local_58 [2];
  longlong *local_50;
  CLSID local_48;
  ulonglong local_38;
  
                    /* 0x38840  364  GetModLibDocName */
  local_38 = DAT_1800791f8 ^ (ulonglong)local_68;
  pDVar14 = aDStack_98;
  if (((param_1 != (LPCSTR)0x0) && (pDVar14 = aDStack_98, param_2 != (char *)0x0)) &&
     (pDVar14 = aDStack_98, 0 < param_3)) {
    *param_2 = '\0';
    lVar11 = -1;
    do {
      lVar11 = lVar11 + 1;
    } while (param_1[lVar11] != '\0');
    iVar10 = (int)lVar11 + 1;
    uVar4 = (longlong)iVar10 * 2;
    uVar12 = uVar4 + 0xf;
    if (uVar12 <= uVar4) {
      uVar12 = 0xffffffffffffff0;
    }
    uStack_a0 = 0x1800388c1;
    lVar11 = -(uVar12 & 0xfffffffffffffff0);
    *(int *)((longlong)&lStack_70 + lVar11) = iVar10;
    pwcsName = (WCHAR *)((longlong)local_68 + lVar11);
    *(WCHAR **)((longlong)local_78 + lVar11) = pwcsName;
    *(undefined8 *)((longlong)aDStack_98 + lVar11 + -8) = 0x1800388e0;
    MultiByteToWideChar(0,0,param_1,-1,*(LPWSTR *)((longlong)local_78 + lVar11),
                        *(int *)((longlong)&lStack_70 + lVar11));
    *(undefined8 *)((longlong)aDStack_98 + lVar11 + -8) = 0x1800388e9;
    HVar8 = StgIsStorageFile(pwcsName);
    pDVar14 = (DWORD *)((longlong)aDStack_98 + lVar11);
    if (HVar8 == 0) {
      *(LPSTORAGE **)((longlong)&lStack_70 + lVar11) = &local_60;
      local_60 = (LPSTORAGE)0x0;
      *(undefined4 *)((longlong)local_78 + lVar11) = 0;
      *(undefined8 *)((longlong)aDStack_98 + lVar11 + -8) = 0x180038916;
      HVar8 = StgOpenStorage(pwcsName,(IStorage *)0x0,0x20,(SNB)0x0,
                             *(DWORD *)((longlong)local_78 + lVar11),
                             *(IStorage ***)((longlong)&lStack_70 + lVar11));
      pIVar5 = local_60;
      if (HVar8 == -0x7ffcffe0) {
        uVar9 = 0xffffffff;
        pDVar14 = (DWORD *)((longlong)aDStack_98 + lVar11);
        goto LAB_180038cb5;
      }
      pDVar14 = (DWORD *)((longlong)aDStack_98 + lVar11);
      if (-1 < HVar8) {
        *(undefined8 *)((longlong)aDStack_98 + lVar11 + -8) = 0x18003893b;
        ReadClassStg(pIVar5,&local_48);
        if ((((((((local_48._0_8_ == DAT_1800562a0) && (local_48.Data4 == DAT_1800562a8)) ||
                ((local_48._0_8_ == DAT_1800562c0 && (local_48.Data4 == DAT_1800562c8)))) ||
               ((local_48._0_8_ == DAT_1800562d0 && (local_48.Data4 == DAT_1800562d8)))) ||
              (((local_48._0_8_ == DAT_1800562e0 && (local_48.Data4 == DAT_1800562e8)) ||
               ((((local_48._0_8_ == DAT_1800562f0 && (local_48.Data4 == DAT_1800562f8)) ||
                 ((local_48._0_8_ == DAT_180056300 && (local_48.Data4 == DAT_180056308)))) ||
                ((local_48._0_8_ == DAT_180056310 && (local_48.Data4 == DAT_180056318)))))))) ||
             ((local_48._0_8_ == DAT_180056320 && (local_48.Data4 == DAT_180056328)))) ||
            (((((local_48._0_8_ == DAT_180056330 && (local_48.Data4 == DAT_180056338)) ||
               ((local_48._0_8_ == DAT_180056340 && (local_48.Data4 == DAT_180056348)))) ||
              ((((local_48._0_8_ == DAT_180056350 && (local_48.Data4 == DAT_180056358)) ||
                ((local_48._0_8_ == DAT_180056360 && (local_48.Data4 == DAT_180056368)))) ||
               ((((local_48._0_8_ == DAT_180056370 && (local_48.Data4 == DAT_180056378)) ||
                 ((local_48._0_8_ == DAT_180056380 && (local_48.Data4 == DAT_180056388)))) ||
                ((local_48._0_8_ == DAT_180056390 && (local_48.Data4 == DAT_180056398)))))))) ||
             ((local_48._0_8_ == DAT_1800563a0 && (local_48.Data4 == DAT_1800563a8)))))) ||
           (((((local_48._0_8_ == DAT_1800563b0 && (local_48.Data4 == DAT_1800563b8)) ||
              ((local_48._0_8_ == DAT_1800563c0 && (local_48.Data4 == DAT_1800563c8)))) ||
             ((((local_48._0_8_ == DAT_1800563d0 && (local_48.Data4 == DAT_1800563d8)) ||
               ((local_48._0_8_ == DAT_1800563e0 && (local_48.Data4 == DAT_1800563e8)))) ||
              (((((local_48._0_8_ == DAT_1800563f0 && (local_48.Data4 == DAT_1800563f8)) ||
                 ((local_48._0_8_ == DAT_180056400 && (local_48.Data4 == DAT_180056408)))) ||
                ((local_48._0_8_ == DAT_180056410 && (local_48.Data4 == DAT_180056418)))) ||
               ((local_48._0_8_ == DAT_180056420 && (local_48.Data4 == DAT_180056428)))))))) ||
            ((((local_48._0_8_ == DAT_180056430 && (local_48.Data4 == DAT_180056438)) ||
              ((local_48._0_8_ == DAT_180056440 && (local_48.Data4 == DAT_180056448)))) ||
             ((puVar13 = (undefined1 *)((longlong)aDStack_98 + lVar11),
              local_48._0_8_ == DAT_180056450 &&
              (puVar13 = (undefined1 *)((longlong)aDStack_98 + lVar11),
              local_48.Data4 == DAT_180056458)))))))) {
          local_50 = (longlong *)0x0;
          pDVar14 = (DWORD *)(auStack_b8 + lVar11);
          *(undefined4 *)((longlong)&lStack_90 + lVar11) = 10;
          *(OLECHAR **)((longlong)aDStack_98 + lVar11) = (OLECHAR *)((longlong)local_88 + lVar11);
          *(undefined8 *)((longlong)&uStack_c0 + lVar11) = 0x180038bb7;
          MultiByteToWideChar(0,0,"CONTENTS",-1,*(LPWSTR *)((longlong)aDStack_98 + lVar11),
                              *(int *)((longlong)&lStack_90 + lVar11));
          pIVar5 = local_60;
          *(longlong ***)((longlong)&lStack_90 + lVar11) = &local_50;
          *(undefined4 *)((longlong)aDStack_98 + lVar11) = 0;
          p_Var1 = pIVar5->lpVtbl->OpenStream;
          *(undefined8 *)((longlong)&uStack_c0 + lVar11) = 0x180038bda;
          HVar8 = (*p_Var1)(pIVar5,(OLECHAR *)((longlong)local_88 + lVar11),(void *)0x0,0x10,
                            *(DWORD *)((longlong)aDStack_98 + lVar11),
                            *(IStream ***)((longlong)&lStack_90 + lVar11));
          plVar7 = local_50;
          puVar13 = auStack_b8 + lVar11;
          if (-1 < HVar8) {
            local_68[0] = 0;
            pcVar2 = *(code **)(*local_50 + 0x18);
            *(undefined8 *)((longlong)&uStack_c0 + lVar11) = 0x180038bfd;
            iVar10 = (*pcVar2)(plVar7,local_58,4,local_68);
            if ((-1 < iVar10) && (local_68[0] == 4)) {
              if (local_58[0] != 0) {
                uVar12 = (ulonglong)local_58[0];
                *(undefined8 *)((longlong)&uStack_c0 + lVar11) = 0x180038c1e;
                _Source = malloc(uVar12);
                plVar7 = local_50;
                uVar6 = local_58[0];
                if (_Source == (char *)0x0) {
                  uVar9 = 0x8007000e;
                  pDVar14 = (DWORD *)(auStack_b8 + lVar11);
                  goto LAB_180038cb5;
                }
                pcVar2 = *(code **)(*local_50 + 0x18);
                *(undefined8 *)((longlong)&uStack_c0 + lVar11) = 0x180038c45;
                iVar10 = (*pcVar2)(plVar7,_Source,uVar6,local_68);
                if ((iVar10 < 0) || (local_68[0] != local_58[0])) {
                  *(undefined8 *)((longlong)&uStack_c0 + lVar11) = 0x180038c9f;
                  free(_Source);
                  goto LAB_180038c9f;
                }
                iVar10 = local_58[0] - 1;
                if (param_3 + -1 <= (int)(local_58[0] - 1)) {
                  iVar10 = param_3 + -1;
                }
                *(undefined8 *)((longlong)&uStack_c0 + lVar11) = 0x180038c6e;
                strncpy(param_2,_Source,(longlong)iVar10);
                param_2[iVar10] = '\0';
                *(undefined8 *)((longlong)&uStack_c0 + lVar11) = 0x180038c7b;
                free(_Source);
              }
              pcVar2 = *(code **)(*local_50 + 0x10);
              *(undefined8 *)((longlong)&uStack_c0 + lVar11) = 0x180038c85;
              (*pcVar2)();
              pIVar5 = local_60;
              p_Var3 = local_60->lpVtbl->Release;
              *(undefined8 *)((longlong)&uStack_c0 + lVar11) = 0x180038c8f;
              (*p_Var3)(pIVar5);
              uVar9 = 1;
              goto LAB_180038cb5;
            }
LAB_180038c9f:
            pcVar2 = *(code **)(*local_50 + 0x10);
            *(undefined8 *)((longlong)&uStack_c0 + lVar11) = 0x180038ca9;
            (*pcVar2)();
            puVar13 = auStack_b8 + lVar11;
          }
        }
        pIVar5 = local_60;
        p_Var3 = local_60->lpVtbl->Release;
        *(undefined8 *)(puVar13 + -8) = 0x180038cb3;
        (*p_Var3)(pIVar5);
        pDVar14 = (DWORD *)puVar13;
      }
    }
  }
  uVar9 = 0;
LAB_180038cb5:
  *(undefined8 *)((longlong)pDVar14 + -8) = 0x180038cc1;
  return uVar9;
}

/* ---- FUNC 00038CD0 FUN_180038cd0 (266 bytes) ---- */

undefined8 * FUN_180038cd0(undefined8 *param_1,void *param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  void *_Dst;
  ulonglong _Size;
  
  _Dst = (void *)0x0;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  _Size = 0xffffffffffffffff;
  do {
    _Size = _Size + 1;
  } while (*(char *)(_Size + (longlong)param_2) != '\0');
  if (_Size < 0x8000000000000000) {
    param_1[3] = 0xf;
    if (_Size < 0x10) {
      param_1[2] = _Size;
      memcpy(param_1,param_2,_Size);
      *(undefined1 *)(_Size + (longlong)param_1) = 0;
    }
    else {
      uVar2 = _Size | 0xf;
      if (uVar2 < 0x8000000000000000) {
        if (uVar2 < 0x16) {
          uVar2 = 0x16;
        }
        uVar1 = uVar2 + 1;
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
        uVar2 = 0x7fffffffffffffff;
      }
      *param_1 = _Dst;
      param_1[2] = _Size;
      param_1[3] = uVar2;
      memcpy(_Dst,param_2,_Size);
      *(undefined1 *)((longlong)_Dst + _Size) = 0;
    }
    return param_1;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18000ace0();
}

/* ---- FUNC 00038DE0 GetDefaultCopyContent (7 bytes) ---- */

undefined4 GetDefaultCopyContent(void)

{
                    /* 0x38de0  99  GetDefaultCopyContent */
  return DAT_180072250;
}

/* ---- FUNC 00038DF0 FUN_180038df0 (43 bytes) ---- */

undefined8 FUN_180038df0(longlong param_1,char *param_2,uint param_3,uint *param_4)

{
  char cVar1;
  uint uVar2;
  
  if (*(longlong *)(param_1 + 0x7d8) == 0) {
    (**(code **)(**(longlong **)(param_1 + 0x7e0) + 0x20))
              (*(longlong **)(param_1 + 0x7e0),param_1 + 8,2000);
    *(longlong *)(param_1 + 0x7d8) = param_1 + 8;
  }
  uVar2 = 0;
  if (param_3 != 0) {
    do {
      cVar1 = **(char **)(param_1 + 0x7d8);
      if (cVar1 == '\0') {
        return 0x80004005;
      }
      uVar2 = uVar2 + 1;
      *(char **)(param_1 + 0x7d8) = *(char **)(param_1 + 0x7d8) + 1;
      *param_2 = cVar1;
      param_2 = param_2 + 1;
    } while (uVar2 < param_3);
  }
  if (param_4 != (uint *)0x0) {
    *param_4 = uVar2;
  }
  return 0;
}

/* ---- FUNC 00038E1B FUN_180038e1b (43 bytes) ---- */

undefined8 FUN_180038e1b(longlong param_1)

{
  char cVar1;
  uint uVar2;
  uint unaff_EBP;
  longlong unaff_RSI;
  char *unaff_RDI;
  uint *unaff_R14;
  
  (**(code **)(**(longlong **)(param_1 + 0x7e0) + 0x20))
            (*(longlong **)(param_1 + 0x7e0),param_1 + 8,2000);
  *(longlong *)(unaff_RSI + 0x7d8) = param_1 + 8;
  uVar2 = 0;
  if (unaff_EBP != 0) {
    do {
      cVar1 = **(char **)(unaff_RSI + 0x7d8);
      if (cVar1 == '\0') {
        return 0x80004005;
      }
      uVar2 = uVar2 + 1;
      *(char **)(unaff_RSI + 0x7d8) = *(char **)(unaff_RSI + 0x7d8) + 1;
      *unaff_RDI = cVar1;
      unaff_RDI = unaff_RDI + 1;
    } while (uVar2 < unaff_EBP);
  }
  if (unaff_R14 != (uint *)0x0) {
    *unaff_R14 = uVar2;
  }
  return 0;
}

/* ---- FUNC 00038E46 FUN_180038e46 (84 bytes) ---- */

undefined8 FUN_180038e46(void)

{
  char cVar1;
  uint uVar2;
  uint unaff_EBP;
  longlong unaff_RSI;
  char *unaff_RDI;
  uint *unaff_R14;
  
  uVar2 = 0;
  if (unaff_EBP != 0) {
    do {
      cVar1 = **(char **)(unaff_RSI + 0x7d8);
      if (cVar1 == '\0') {
        return 0x80004005;
      }
      uVar2 = uVar2 + 1;
      *(char **)(unaff_RSI + 0x7d8) = *(char **)(unaff_RSI + 0x7d8) + 1;
      *unaff_RDI = cVar1;
      unaff_RDI = unaff_RDI + 1;
    } while (uVar2 < unaff_EBP);
  }
  if (unaff_R14 != (uint *)0x0) {
    *unaff_R14 = uVar2;
  }
  return 0;
}

/* ---- FUNC 00038EA0 FUN_180038ea0 (228 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180038ea0(FILE *param_1)

{
  int iVar1;
  char *pcVar2;
  undefined1 auStack_1b8 [32];
  char local_198 [128];
  char local_118 [128];
  undefined1 local_98 [128];
  ulonglong local_18;
  
  local_18 = DAT_1800791f8 ^ (ulonglong)auStack_1b8;
  if (param_1 != (FILE *)0x0) {
    rewind(param_1);
    pcVar2 = fgets(local_198,0x78,param_1);
    while (pcVar2 != (char *)0x0) {
      pcVar2 = strchr(local_198,10);
      if (pcVar2 != (char *)0x0) {
        *pcVar2 = '\0';
      }
      iVar1 = _strnicmp(local_198,"version",7);
      if (iVar1 == 0) {
        sscanf(local_198,"%s %s",local_98,local_118);
        pcVar2 = (char *)FUN_1800241b0();
        iVar1 = _stricmp(local_118,pcVar2);
        if (iVar1 != 0) {
          return 0;
        }
        return 1;
      }
      pcVar2 = fgets(local_198,0x78,param_1);
    }
  }
  return 0;
}

/* ---- FUNC 00038F90 FUN_180038f90 (193 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_180038f90(char *param_1,uint param_2,undefined8 param_3,undefined8 param_4)

{
  char *pcVar1;
  char cVar2;
  LSTATUS LVar3;
  undefined1 *puVar4;
  HKEY__ *hKey;
  longlong lVar5;
  undefined4 uVar6;
  undefined1 auStack_88 [31];
  undefined1 uStack_69;
  CHAR local_68 [48];
  char local_38 [32];
  ulonglong local_18;
  
  local_18 = DAT_1800791f8 ^ (ulonglong)auStack_88;
  uVar6 = 0;
  lVar5 = -(longlong)param_1;
  do {
    cVar2 = *param_1;
    param_1[(longlong)(local_68 + lVar5)] = cVar2;
    param_1 = param_1 + 1;
  } while (cVar2 != '\0');
  if (param_2 != 0) {
    FUN_180007de0(local_38,&DAT_180056ce8,(ulonglong)param_2,param_4);
    puVar4 = &uStack_69;
    do {
      pcVar1 = puVar4 + 1;
      puVar4 = puVar4 + 1;
    } while (*pcVar1 != '\0');
    lVar5 = 0;
    do {
      cVar2 = local_38[lVar5];
      puVar4[lVar5] = cVar2;
      lVar5 = lVar5 + 1;
    } while (cVar2 != '\0');
  }
  hKey = GetSectionKey("mmgini");
  if (hKey != (HKEY__ *)0x0) {
    LVar3 = RegDeleteValueA(hKey,local_68);
    uVar6 = 0;
    if (LVar3 == 0) {
      uVar6 = 1;
    }
  }
  return uVar6;
}

/* ---- FUNC 00039060 FUN_180039060 (100 bytes) ---- */

char * FUN_180039060(char *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = _stricmp(param_1,s_paramdata_180072260 + (longlong)iVar2 * 0x60);
    if (iVar1 == 0) {
      return s_paramdata_180072260 + (longlong)iVar2 * 0x60;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x129);
  return (char *)0x0;
}

/* ---- FUNC 000390D0 FUN_1800390d0 (518 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint FUN_1800390d0(FILE *param_1,char *param_2,int param_3)

{
  char cVar1;
  longlong lVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  undefined2 *puVar6;
  longlong lVar7;
  undefined1 auVar9 [8];
  size_t _MaxCount;
  uint uVar10;
  undefined1 auStackY_238 [32];
  uint local_208 [2];
  undefined1 local_200 [8];
  char local_1f8 [48];
  char local_1c8 [128];
  uint local_148 [64];
  ulonglong local_48;
  longlong lVar8;
  
  uVar3 = DAT_18007b7e8;
  local_48 = DAT_1800791f8 ^ (ulonglong)auStackY_238;
  uVar10 = 0;
  DAT_18007b7e8 = 1;
  rewind(param_1);
  pcVar5 = param_2;
  do {
    cVar1 = *pcVar5;
    pcVar5[(longlong)(local_1f8 + -(longlong)param_2)] = cVar1;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  puVar6 = (undefined2 *)(local_200 + 7);
  do {
    pcVar5 = (char *)((longlong)puVar6 + 1);
    puVar6 = (undefined2 *)((longlong)puVar6 + 1);
  } while (*pcVar5 != '\0');
  *puVar6 = DAT_180056d20;
  lVar8 = -1;
  do {
    lVar7 = lVar8 + 1;
    lVar2 = lVar8 + 1;
    lVar8 = lVar7;
  } while (local_1f8[lVar2] != '\0');
  pcVar5 = fgets(local_1c8,0x78,param_1);
  if (pcVar5 == (char *)0x0) {
    uVar10 = 0;
  }
  else {
    _MaxCount = (size_t)(int)lVar7;
    auVar9 = local_200;
    do {
      pcVar5 = strchr(local_1c8,10);
      if (pcVar5 != (char *)0x0) {
        *pcVar5 = '\0';
      }
      iVar4 = _strnicmp(local_1c8,local_1f8,_MaxCount);
      if (iVar4 == 0) {
        cVar1 = param_2[0x20];
        if (cVar1 == '\x01') {
          local_208[0] = atoi(local_1c8 + _MaxCount);
          auVar9 = (undefined1  [8])local_208;
        }
        else if (cVar1 == '\x02') {
          local_200 = (undefined1  [8])atof(local_1c8 + _MaxCount);
          auVar9 = (undefined1  [8])local_200;
        }
        else if (cVar1 == '\x03') {
          pcVar5 = local_1c8 + _MaxCount;
          if (*pcVar5 == '\0') {
            local_148[0]._0_1_ = 0;
            auVar9 = (undefined1  [8])local_148;
          }
          else {
            lVar8 = (longlong)local_148 - (longlong)pcVar5;
            do {
              cVar1 = *pcVar5;
              pcVar5[lVar8] = cVar1;
              pcVar5 = pcVar5 + 1;
            } while (cVar1 != '\0');
            auVar9 = (undefined1  [8])local_148;
          }
        }
        SESetSettingValue(param_2,(uint *)auVar9,param_3,uVar10,0);
        uVar10 = uVar10 + 1;
      }
      else if (uVar10 != 0) {
        DAT_18007b7e8 = uVar3;
        return uVar10;
      }
      pcVar5 = fgets(local_1c8,0x78,param_1);
    } while (pcVar5 != (char *)0x0);
  }
  DAT_18007b7e8 = uVar3;
  return uVar10;
}

/* ---- FUNC 0003918B FUN_18003918b (284 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint FUN_18003918b(void)

{
  char cVar1;
  longlong lVar2;
  int iVar3;
  char *pcVar4;
  int unaff_EBX;
  uint *puVar5;
  char *unaff_RBP;
  size_t _MaxCount;
  uint unaff_EDI;
  int unaff_R12D;
  char cVar6;
  longlong unaff_R13;
  undefined4 unaff_R14D;
  FILE *unaff_R15;
  uint in_stack_00000030;
  uint *in_stack_00000038;
  char in_stack_000000f0;
  
  _MaxCount = (size_t)unaff_EBX;
  puVar5 = in_stack_00000038;
  do {
    pcVar4 = strchr(&stack0x00000070,10);
    cVar6 = (char)unaff_R13;
    if (pcVar4 != (char *)0x0) {
      *pcVar4 = cVar6;
    }
    iVar3 = _strnicmp(&stack0x00000070,&stack0x00000040,_MaxCount);
    if (iVar3 == 0) {
      cVar1 = unaff_RBP[0x20];
      if (cVar1 == '\x01') {
        in_stack_00000030 = atoi(&stack0x00000070 + _MaxCount);
        puVar5 = &stack0x00000030;
      }
      else if (cVar1 == '\x02') {
        in_stack_00000038 = (uint *)atof(&stack0x00000070 + _MaxCount);
        puVar5 = (uint *)&stack0x00000038;
      }
      else if (cVar1 == '\x03') {
        pcVar4 = &stack0x00000070 + _MaxCount;
        if (*pcVar4 == cVar6) {
          puVar5 = (uint *)&stack0x000000f0;
          in_stack_000000f0 = cVar6;
        }
        else {
          lVar2 = -(longlong)pcVar4;
          do {
            cVar6 = *pcVar4;
            pcVar4[(longlong)(&stack0x000000f0 + lVar2)] = cVar6;
            pcVar4 = pcVar4 + 1;
          } while (cVar6 != '\0');
          puVar5 = (uint *)&stack0x000000f0;
        }
      }
      SESetSettingValue(unaff_RBP,puVar5,unaff_R12D,unaff_EDI,unaff_R13);
      unaff_EDI = unaff_EDI + 1;
    }
    else if (unaff_EDI != 0) {
      DAT_18007b7e8 = unaff_R14D;
      return unaff_EDI;
    }
    pcVar4 = fgets(&stack0x00000070,0x78,unaff_R15);
  } while (pcVar4 != (char *)0x0);
  DAT_18007b7e8 = unaff_R14D;
  return unaff_EDI;
}

/* ---- FUNC 000392A7 FUN_1800392a7 (35 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1800392a7(void)

{
  return;
}

/* ---- FUNC 000392E0 SEInitializeVData (91 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SEInitializeVData(undefined8 param_1)

{
  undefined1 auStack_828 [32];
  undefined **local_808 [251];
  undefined8 local_30;
  undefined8 local_28;
  ulonglong local_18;
  
                    /* 0x392e0  176  SEInitializeVData */
  local_18 = DAT_1800791f8 ^ (ulonglong)auStack_828;
  local_808[0] = CVDataStream::vftable;
  local_30 = 0;
  local_28 = param_1;
  SEWriteAllSettings(1,(longlong *)local_808);
  return;
}

/* ---- FUNC 00039340 FUN_180039340 (571 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong FUN_180039340(char *param_1,char *param_2)

{
  int iVar1;
  uint uVar2;
  FARPROC pFVar3;
  longlong lVar4;
  HMODULE hModule;
  longlong lVar5;
  undefined1 auStack_68 [32];
  longlong local_48;
  char *local_40 [5];
  ulonglong local_18;
  
  hModule = DAT_18007b818;
  local_18 = DAT_1800791f8 ^ (ulonglong)auStack_68;
  if (((param_1 == (char *)0x0) || (param_2 == (char *)0x0)) || (DAT_18007b818 == (HMODULE)0x0)) {
LAB_180039553:
    lVar4 = 0x80004005;
  }
  else {
    iVar1 = strcmp(param_1,"submitdata");
    if (iVar1 == 0) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_48,param_2)
      ;
      local_40[0] = "usrpp1a ";
      local_40[1] = "usrpp1b ";
      local_40[2] = "usrpp2a ";
      local_40[3] = "usrpp2b ";
      local_40[4] = "usrpp2c ";
      lVar5 = 0;
      lVar4 = lVar5;
      do {
        if ((*(int *)(local_48 + -0x10) != 0) &&
           (iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Find
                              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                               &local_48,local_40[lVar4],0), iVar1 != -1)) goto LAB_180039439;
        lVar4 = lVar4 + 1;
      } while (lVar4 < 5);
      pFVar3 = GetProcAddress(DAT_18007b818,"SBmmgini");
      if (pFVar3 == (FARPROC)0x0) {
        lVar5 = 0x80004005;
LAB_180039439:
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_48);
        return lVar5;
      }
      (*pFVar3)(param_2,1,0xffffffff);
      if ((DAT_18007b820 != (HMODULE)0x0) &&
         (_DAT_18007b7c0 = GetProcAddress(DAT_18007b820,"SMtmpdbankfiles"),
         _DAT_18007b7c0 != (FARPROC)0x0)) {
        (*_DAT_18007b7c0)(0);
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_48);
      hModule = DAT_18007b818;
    }
    iVar1 = strcmp(param_1,"regcases");
    if (iVar1 == 0) {
      pFVar3 = GetProcAddress(hModule,"MDdefcse");
      if (pFVar3 == (FARPROC)0x0) goto LAB_180039553;
      (*pFVar3)(param_2,1);
      hModule = DAT_18007b818;
    }
    iVar1 = strcmp(param_1,"sumcount");
    if (iVar1 == 0) {
      DAT_18007b7e0 = GetProcAddress(hModule,"GRset_higher_sumcount");
      if (DAT_18007b7e0 == (FARPROC)0x0) goto LAB_180039553;
      uVar2 = atoi(param_2);
      (*DAT_18007b7e0)((ulonglong)uVar2);
      hModule = DAT_18007b818;
    }
    iVar1 = strcmp(param_1,"STREAMGBLOBDATA");
    if ((iVar1 == 0) &&
       (_DAT_18007b7f8 = GetProcAddress(hModule,"RestoreStreamGlobalData"),
       _DAT_18007b7f8 != (FARPROC)0x0)) {
      (*_DAT_18007b7f8)(param_2);
    }
    lVar4 = 0;
  }
  return lVar4;
}

/* ---- FUNC 00039580 FUN_180039580 (301 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint FUN_180039580(char *param_1,int *param_2,uint param_3)

{
  char cVar1;
  bool bVar2;
  undefined1 *puVar3;
  char *pcVar4;
  longlong lVar5;
  ulonglong uVar6;
  undefined1 auStack_88 [32];
  uint local_68;
  int local_60 [7];
  undefined2 local_44;
  undefined1 uStack_41;
  char local_40 [48];
  ulonglong local_10;
  
  local_10 = DAT_1800791f8 ^ (ulonglong)auStack_88;
  uVar6 = (ulonglong)param_3;
  pcVar4 = param_1;
  do {
    cVar1 = *pcVar4;
    pcVar4[(longlong)(local_40 + -(longlong)param_1)] = cVar1;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  if (param_3 != 0) {
    FUN_180007de0(local_60,&DAT_180056ce8,uVar6,uVar6);
    puVar3 = &uStack_41;
    do {
      pcVar4 = puVar3 + 1;
      puVar3 = puVar3 + 1;
    } while (*pcVar4 != '\0');
    lVar5 = 0;
    do {
      cVar1 = *(char *)((longlong)local_60 + lVar5);
      puVar3[lVar5] = cVar1;
      lVar5 = lVar5 + 1;
    } while (cVar1 != '\0');
  }
  cVar1 = param_1[0x20];
  if (cVar1 == '\x01') {
    bVar2 = MMWriteProfileInt("mmgini",local_40,*param_2);
  }
  else {
    if (cVar1 == '\x02') {
      local_60[4] = 0;
      local_60[5] = 0;
      local_60[6] = 0;
      local_60[0] = 0;
      local_60[1] = 0;
      local_60[2] = 0;
      local_60[3] = 0;
      local_44 = 0;
      FUN_180007de0(local_60,&DAT_180056974,*(undefined8 *)param_2,uVar6);
      param_2 = local_60;
    }
    else if (cVar1 != '\x03') {
      return local_68;
    }
    bVar2 = MMWriteProfileString("mmgini",local_40,(char *)param_2);
  }
  return (uint)bVar2;
}

/* ---- FUNC 000396B0 FUN_1800396b0 (1340 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_1800396b0(longlong *param_1,longlong *param_2,ulonglong param_3,undefined8 param_4)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined8 *puVar5;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar6;
  IAtlStringMgr *pIVar7;
  char *pcVar8;
  char *pcVar9;
  longlong lVar10;
  longlong lVar11;
  char *pcVar12;
  undefined1 auStackY_108 [32];
  char *local_d8;
  undefined4 local_d0;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_c8 [8];
  char *local_c0;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_b8 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_b0 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_a8 [16];
  char local_98 [8];
  char local_90 [2];
  char local_8e;
  ulonglong local_28;
  
  local_28 = DAT_1800791f8 ^ (ulonglong)auStackY_108;
  local_d0 = 0;
  pcVar8 = (char *)*param_1;
  iVar2 = strcmp(pcVar8,"simulate");
  if (iVar2 == 0) {
    lVar10 = 0;
    do {
      lVar11 = lVar10 + 1;
      if (*(char *)(*param_2 + lVar10) != (&DAT_180056e74)[lVar10]) {
        return 0x80004005;
      }
      lVar10 = lVar11;
    } while (lVar11 != 5);
    local_98[0] = s_editinput_180056e80[0];
    local_98[1] = s_editinput_180056e80[1];
    local_98[2] = s_editinput_180056e80[2];
    local_98[3] = s_editinput_180056e80[3];
    local_98[4] = s_editinput_180056e80[4];
    local_98[5] = s_editinput_180056e80[5];
    local_98[6] = s_editinput_180056e80[6];
    local_98[7] = s_editinput_180056e80[7];
    local_90[0] = s_editinput_180056e80[8];
    local_90[1] = s_editinput_180056e80[9];
    local_8e = s_editinput_180056e80[10];
    lVar10 = -1;
    do {
      lVar11 = lVar10;
      lVar10 = lVar11 + 1;
    } while (local_98[lVar11 + 1] != '\0');
    pcVar12 = local_98 + lVar11 + 1;
    pcVar12[0] = '1';
    pcVar12[1] = '\0';
    pcVar8 = local_98;
    pcVar9 = (char *)*param_1;
    do {
      cVar1 = *pcVar8;
      *pcVar9 = cVar1;
      pcVar8 = pcVar8 + 1;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    lVar10 = *param_1;
    *param_2 = (longlong)(pcVar12 + (lVar10 - (longlong)local_98));
    (pcVar12 + (lVar10 - (longlong)local_98))[-1] = '\0';
  }
  else {
    iVar2 = strcmp(pcVar8,"plotmarkersize");
    if (iVar2 == 0) {
      return 0x80004005;
    }
    iVar2 = _stricmp(pcVar8,"material_style");
    if (((((iVar2 == 0) || (iVar2 = _stricmp((char *)*param_1,"heat_style"), iVar2 == 0)) ||
         (iVar2 = _stricmp((char *)*param_1,"work_style"), iVar2 == 0)) ||
        (((iVar2 = _stricmp((char *)*param_1,"power_style"), iVar2 == 0 ||
          (iVar2 = _stricmp((char *)*param_1,"connections_style"), iVar2 == 0)) ||
         (iVar2 = _stricmp((char *)*param_1,"measurements_style"), iVar2 == 0)))) &&
       (uVar3 = atoi((char *)*param_2), (uVar3 & 0xf0000) != 0)) {
      DAT_18007b834 = '\x01';
      uVar3 = uVar3 & 0xf;
      if (uVar3 != 0) {
        if (uVar3 < 5) {
          uVar3 = uVar3 - 1;
          if (uVar3 == 2) {
            DAT_1800791c0 = 1;
            uVar3 = 1;
          }
          else {
            if (uVar3 == 1) {
              uVar3 = 2;
            }
            DAT_1800791c0 = 1;
          }
        }
        else {
          DAT_1800791c0 = 0xfffffffd;
          uVar3 = 0;
        }
      }
      FUN_180007de0(*param_2,&DAT_1800533ec,(ulonglong)uVar3,param_4);
    }
    iVar2 = _stricmp((char *)*param_1,"material_width");
    if ((((iVar2 == 0) || (iVar2 = _stricmp((char *)*param_1,"heat_width"), iVar2 == 0)) ||
        ((iVar2 = _stricmp((char *)*param_1,"work_width"), iVar2 == 0 ||
         (((iVar2 = _stricmp((char *)*param_1,"power_width"), iVar2 == 0 ||
           (iVar2 = _stricmp((char *)*param_1,"connections_width"), iVar2 == 0)) ||
          (iVar2 = _stricmp((char *)*param_1,"measurements_width"), iVar2 == 0)))))) &&
       (DAT_18007b834 != '\0')) {
      DAT_18007b834 = '\0';
      FUN_180007de0(*param_2,&DAT_1800533ec,(ulonglong)DAT_1800791c0,param_4);
    }
    iVar2 = _stricmp((char *)*param_1,"qwformat");
    if ((((iVar2 == 0) || (iVar2 = _stricmp((char *)*param_1,"tempformat"), iVar2 == 0)) ||
        (((iVar2 = _stricmp((char *)*param_1,"presformat"), iVar2 == 0 ||
          ((iVar2 = _stricmp((char *)*param_1,"flowformat"), iVar2 == 0 ||
           (iVar2 = _stricmp((char *)*param_1,"strmqwformat"), iVar2 == 0)))) ||
         (iVar2 = _stricmp((char *)*param_1,"vflowformat"), iVar2 == 0)))) ||
       ((iVar2 = _stricmp((char *)*param_1,"mflowformat"), iVar2 == 0 ||
        (iVar2 = _stricmp((char *)*param_1,"vfracformat"), iVar2 == 0)))) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_d8,
                 (char *)*param_2);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Replace
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_d8,',','.')
      ;
      pcVar9 = (char *)*param_2;
      pcVar8 = local_d8;
      do {
        cVar1 = *pcVar8;
        *pcVar9 = cVar1;
        pcVar8 = pcVar8 + 1;
        pcVar9 = pcVar9 + 1;
      } while (cVar1 != '\0');
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_d8);
    }
    iVar2 = strncmp((char *)*param_1,"customglobaldatapropset",0x17);
    if (iVar2 == 0) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_d8,
                 (char *)*param_2);
      iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Find
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_d8,
                         '|',0);
      if ((((-1 < iVar2) &&
           (iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Find
                              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                               &local_d8,'|',iVar2 + 1), -1 < iVar2)) &&
          (iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Find
                             ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                              &local_d8,'|',iVar2 + 1), -1 < iVar2)) &&
         (iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Find
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &local_d8,'|',iVar2 + 1), -1 < iVar4)) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Mid
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_d8,
                   (int)&local_c0,iVar2 + 1);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Replace
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_c0,',',
                   '.');
        puVar5 = (undefined8 *)
                 ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Mid
                           ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            &local_d8,(int)local_a8);
        pCVar6 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                 ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                           ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            &local_d8,(int)local_b0);
        pIVar7 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                           (pCVar6);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_c8,pIVar7);
        local_d0 = 1;
        ATL::CSimpleStringT<char,1>::Concatenate
                  ((CSimpleStringT<char,1> *)local_c8,*(char **)pCVar6,
                   *(int *)(*(char **)pCVar6 + -0x10),local_c0,*(int *)(local_c0 + -0x10));
        pCVar6 = FUN_180018cd0(local_b8,local_c8,puVar5);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_d8,
                   (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                   pCVar6);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_b8);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_c8);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_b0);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_a8);
        pcVar8 = (char *)*param_2;
        do {
          cVar1 = *local_d8;
          *pcVar8 = cVar1;
          local_d8 = local_d8 + 1;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_c0);
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_d8);
    }
  }
  return 0;
}

/* ---- FUNC 00039BF0 SEUpdateFromVData (89 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SEUpdateFromVData(undefined8 param_1,longlong param_2,undefined8 param_3,ulonglong param_4)

{
  undefined1 auStack_828 [32];
  undefined **local_808 [251];
  undefined8 local_30;
  undefined8 local_28;
  ulonglong local_18;
  
                    /* 0x39bf0  177  SEUpdateFromVData */
  local_18 = DAT_1800791f8 ^ (ulonglong)auStack_828;
  local_808[0] = CVDataStream::vftable;
  local_30 = 0;
  local_28 = param_1;
  SEReadConfigStream((longlong *)local_808,param_2,0,param_4);
  return;
}

/* ---- FUNC 00039C50 FUN_180039c50 (554 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_180039c50(longlong *param_1)

{
  longlong lVar1;
  int iVar2;
  FARPROC pFVar3;
  INT_PTR IVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  longlong lVar7;
  uint uVar8;
  uint uVar9;
  longlong lVar10;
  undefined1 **ppuVar11;
  undefined1 auStack_578 [32];
  undefined1 *local_558 [2];
  char local_548 [784];
  undefined1 local_238 [528];
  ulonglong local_28;
  
  local_28 = DAT_1800791f8 ^ (ulonglong)auStack_578;
  uVar8 = 0;
  uVar9 = 0;
  if ((DAT_18007b818 == (HMODULE)0x0) ||
     (pFVar3 = GetProcAddress(DAT_18007b818,"SBmmgini"), pFVar3 == (FARPROC)0x0)) {
    uVar5 = 0x80004005;
  }
  else {
    local_558[0] = local_238;
    ppuVar11 = local_558;
    IVar4 = (*pFVar3)(0,2,0);
    iVar2 = (int)IVar4;
    while (iVar2 != -1) {
      uVar9 = uVar9 + 1;
      if ((int)IVar4 != 0) {
        FUN_180007de0(local_548,"submitdata %s\"\n",local_238,ppuVar11);
        lVar7 = -1;
        do {
          lVar10 = lVar7 + 1;
          lVar1 = lVar7 + 1;
          lVar7 = lVar10;
        } while (local_548[lVar1] != '\0');
        uVar5 = (**(code **)(*param_1 + 0x20))(param_1,local_548,lVar10,0);
        if ((int)uVar5 != 0) {
          return uVar5;
        }
      }
      ppuVar11 = local_558;
      IVar4 = (*pFVar3)(0,2,(ulonglong)uVar9);
      iVar2 = (int)IVar4;
    }
    pFVar3 = GetProcAddress(DAT_18007b818,"MDgetcse");
    local_558[0] = (undefined1 *)(*pFVar3)(0);
    while (local_558[0] != (undefined1 *)0x0) {
      uVar8 = uVar8 + 1;
      FUN_180007de0(local_548,"regcases %s\n",local_558[0],ppuVar11);
      lVar7 = -1;
      do {
        lVar1 = lVar7 + 1;
        lVar7 = lVar7 + 1;
      } while (local_548[lVar1] != '\0');
      ppuVar11 = (undefined1 **)0x0;
      uVar5 = (**(code **)(*param_1 + 0x20))(param_1,local_548);
      if ((int)uVar5 != 0) {
        return uVar5;
      }
      local_558[0] = (undefined1 *)(*pFVar3)((ulonglong)uVar8);
    }
    _DAT_18007b7d8 = GetProcAddress(DAT_18007b818,"GRgetsumcount");
    if ((_DAT_18007b7d8 != (FARPROC)0x0) && (uVar6 = (*_DAT_18007b7d8)(), 0 < (int)uVar6)) {
      FUN_180007de0(local_548,"sumcount %d\n",uVar6 & 0xffffffff,ppuVar11);
      lVar7 = -1;
      do {
        lVar10 = lVar7 + 1;
        lVar1 = lVar7 + 1;
        lVar7 = lVar10;
      } while (local_548[lVar1] != '\0');
      uVar5 = (**(code **)(*param_1 + 0x20))(param_1,local_548,lVar10,0);
      if ((int)uVar5 != 0) {
        return uVar5;
      }
    }
    uVar6 = FUN_1800240b0();
    if (((int)uVar6 == 1) &&
       (_DAT_18007b7f0 = GetProcAddress(DAT_18007b818,"DumpGlobalData"),
       _DAT_18007b7f0 != (FARPROC)0x0)) {
      (*_DAT_18007b7f0)(param_1,"GRglbst");
    }
    uVar5 = 0;
  }
  return uVar5;
}

/* ---- FUNC 00039CAA FUN_180039caa (421 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_180039caa(void)

{
  char *pcVar1;
  int iVar2;
  undefined8 uVar3;
  FARPROC pFVar4;
  ulonglong uVar5;
  longlong lVar6;
  uint unaff_EBP;
  longlong *unaff_RSI;
  int unaff_EDI;
  longlong *plVar7;
  code *unaff_R14;
  longlong lStackX_20;
  
  plVar7 = &lStackX_20;
  iVar2 = (*unaff_R14)(0,unaff_EBP + 2,0);
  while (iVar2 != -1) {
    unaff_EDI = unaff_EDI + 1;
    if (iVar2 != 0) {
      FUN_180007de0(&stack0x00000030,"submitdata %s\"\n",&stack0x00000340,plVar7);
      lVar6 = -1;
      do {
        pcVar1 = &stack0x00000031 + lVar6;
        lVar6 = lVar6 + 1;
      } while (*pcVar1 != (char)unaff_EBP);
      uVar3 = (**(code **)(*unaff_RSI + 0x20))();
      if ((int)uVar3 != 0) {
        return uVar3;
      }
    }
    plVar7 = &lStackX_20;
    iVar2 = (*unaff_R14)(0,2,unaff_EDI);
  }
  pFVar4 = GetProcAddress(DAT_18007b818,"MDgetcse");
  lStackX_20 = (*pFVar4)(0);
  while (lStackX_20 != 0) {
    unaff_EBP = unaff_EBP + 1;
    FUN_180007de0(&stack0x00000030,"regcases %s\n",lStackX_20,plVar7);
    lVar6 = -1;
    do {
      pcVar1 = &stack0x00000031 + lVar6;
      lVar6 = lVar6 + 1;
    } while (*pcVar1 != '\0');
    plVar7 = (longlong *)0x0;
    uVar3 = (**(code **)(*unaff_RSI + 0x20))();
    if ((int)uVar3 != 0) {
      return uVar3;
    }
    lStackX_20 = (*pFVar4)((ulonglong)unaff_EBP);
  }
  _DAT_18007b7d8 = GetProcAddress(DAT_18007b818,"GRgetsumcount");
  if ((_DAT_18007b7d8 != (FARPROC)0x0) && (uVar5 = (*_DAT_18007b7d8)(), 0 < (int)uVar5)) {
    FUN_180007de0(&stack0x00000030,"sumcount %d\n",uVar5 & 0xffffffff,plVar7);
    lVar6 = -1;
    do {
      pcVar1 = &stack0x00000031 + lVar6;
      lVar6 = lVar6 + 1;
    } while (*pcVar1 != '\0');
    uVar3 = (**(code **)(*unaff_RSI + 0x20))();
    if ((int)uVar3 != 0) {
      return uVar3;
    }
  }
  uVar5 = FUN_1800240b0();
  if (((int)uVar5 == 1) &&
     (_DAT_18007b7f0 = GetProcAddress(DAT_18007b818,"DumpGlobalData"),
     _DAT_18007b7f0 != (FARPROC)0x0)) {
    (*_DAT_18007b7f0)();
  }
  return 0;
}

/* ---- FUNC 00039E4F FUN_180039e4f (36 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180039e4f(void)

{
  return;
}

/* ---- FUNC 00039E80 SetDefaultCopyContent (7 bytes) ---- */

void SetDefaultCopyContent(undefined4 param_1)

{
                    /* 0x39e80  188  SetDefaultCopyContent */
  DAT_180072250 = param_1;
  return;
}

/* ---- FUNC 00039E90 FUN_180039e90 (14 bytes) ---- */

void FUN_180039e90(longlong param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000180039e9a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(longlong **)(param_1 + 0x7e0) + 0x28))();
  return;
}

/* ---- FUNC 00039EA0 CallWithWait (111 bytes) ---- */

void CallWithWait(undefined *param_1,undefined4 param_2)

{
  HCURSOR pHVar1;
  AFX_MODULE_STATE *pAVar2;
  
                    /* 0x39ea0  322  CallWithWait */
  pHVar1 = GetCursor();
  if (pHVar1 != *(HCURSOR *)(afxData_exref + 0x48)) {
    pAVar2 = AfxGetModuleState();
    CCmdTarget::BeginWaitCursor(*(CCmdTarget **)(pAVar2 + 8));
    (*(code *)param_1)(param_2);
    pAVar2 = AfxGetModuleState();
    CCmdTarget::EndWaitCursor(*(CCmdTarget **)(pAVar2 + 8));
    return;
  }
  (*(code *)param_1)(param_2);
  pAVar2 = AfxGetModuleState();
                    /* WARNING: Could not recover jumptable at 0x000180039f08. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(longlong **)(pAVar2 + 8) + 0x180))(*(longlong **)(pAVar2 + 8),0);
  return;
}

/* ---- FUNC 00039F10 SEClearSettingsBinary (126 bytes) ---- */

void SEClearSettingsBinary(undefined8 param_1)

{
  int iVar1;
  undefined8 uVar2;
  int *piVar3;
  INT_PTR IVar4;
  longlong lVar5;
  int iVar6;
  INT_PTR IVar7;
  INT_PTR IVar8;
  char *pcVar9;
  INT_PTR local_res10;
  
                    /* 0x39f10  448  SEClearSettingsBinary */
  if (((DAT_18007b818 != (HMODULE)0x0) &&
      ((DAT_18007b808 != (FARPROC)0x0 ||
       (DAT_18007b808 = GetProcAddress(DAT_18007b818,"deref_ptr"), DAT_18007b808 != (FARPROC)0x0))))
     && ((DAT_18007b810 != (FARPROC)0x0 ||
         (DAT_18007b810 = GetProcAddress(DAT_18007b818,"free3"), DAT_18007b810 != (FARPROC)0x0)))) {
    piVar3 = (int *)(*DAT_18007b808)(param_1);
    iVar1 = *piVar3;
    if (0 < iVar1) {
      lVar5 = 0;
      pcVar9 = &DAT_180072290;
      IVar8 = local_res10;
      do {
        if (*pcVar9 != '\0') {
          uVar2 = *(undefined8 *)(piVar3 + lVar5 * 2 + 1);
          IVar4 = (*DAT_18007b808)(uVar2);
          if (*(char *)(IVar4 + 0x31) != '\0') {
            IVar8 = *(INT_PTR *)(IVar4 + 0x38);
            local_res10 = (*DAT_18007b808)(IVar8);
          }
          iVar6 = 0;
          IVar7 = IVar8;
          if ('\0' < *(char *)(IVar4 + 0x31)) {
            do {
              IVar8 = *(INT_PTR *)(local_res10 + 0x100);
              (*DAT_18007b810)(IVar7,0x108);
              local_res10 = (*DAT_18007b808)(IVar8);
              iVar6 = iVar6 + 1;
              IVar7 = IVar8;
            } while (iVar6 < *(char *)(IVar4 + 0x31));
          }
          (*DAT_18007b810)(uVar2,0x60);
        }
        lVar5 = lVar5 + 1;
        pcVar9 = pcVar9 + 0x60;
      } while (lVar5 < iVar1);
    }
    (*DAT_18007b810)(param_1,(ulonglong)(iVar1 * 8 + 4));
  }
  return;
}

/* ---- FUNC 00039F8E FUN_180039f8e (35 bytes) ---- */

void FUN_180039f8e(void)

{
  int iVar1;
  undefined8 uVar2;
  code *in_RAX;
  int *piVar3;
  longlong lVar4;
  undefined8 unaff_RBX;
  longlong lVar5;
  int iVar6;
  longlong lVar7;
  longlong lVar8;
  char *pcVar9;
  undefined8 in_stack_00000060;
  longlong in_stack_00000068;
  
  piVar3 = (int *)(*in_RAX)();
  iVar1 = *piVar3;
  if (0 < iVar1) {
    lVar5 = 0;
    pcVar9 = &DAT_180072290;
    lVar8 = in_stack_00000068;
    do {
      if (*pcVar9 != '\0') {
        uVar2 = *(undefined8 *)(piVar3 + lVar5 * 2 + 1);
        lVar4 = (*DAT_18007b808)(uVar2);
        if (*(char *)(lVar4 + 0x31) != '\0') {
          lVar8 = *(longlong *)(lVar4 + 0x38);
          in_stack_00000068 = (*DAT_18007b808)(lVar8);
        }
        iVar6 = 0;
        lVar7 = lVar8;
        if ('\0' < *(char *)(lVar4 + 0x31)) {
          do {
            lVar8 = *(longlong *)(in_stack_00000068 + 0x100);
            (*DAT_18007b810)(lVar7,0x108);
            in_stack_00000068 = (*DAT_18007b808)(lVar8);
            iVar6 = iVar6 + 1;
            lVar7 = lVar8;
          } while (iVar6 < *(char *)(lVar4 + 0x31));
        }
        (*DAT_18007b810)(uVar2,0x60);
      }
      lVar5 = lVar5 + 1;
      pcVar9 = pcVar9 + 0x60;
      unaff_RBX = in_stack_00000060;
    } while (lVar5 < iVar1);
  }
  (*DAT_18007b810)(unaff_RBX,iVar1 * 8 + 4);
  return;
}

/* ---- FUNC 00039FB1 FUN_180039fb1 (230 bytes) ---- */

void FUN_180039fb1(void)

{
  undefined8 uVar1;
  longlong in_RAX;
  longlong lVar2;
  longlong unaff_RBX;
  longlong lVar3;
  int iVar4;
  longlong unaff_R13;
  undefined8 uVar5;
  char *pcVar6;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  longlong in_stack_00000070;
  
  lVar3 = 0;
  pcVar6 = &DAT_180072290;
  do {
    if (*pcVar6 != '\0') {
      uVar1 = *(undefined8 *)(in_RAX + lVar3 * 8);
      lVar2 = (*DAT_18007b808)(uVar1);
      if (*(char *)(lVar2 + 0x31) != '\0') {
        in_stack_00000068 = *(undefined8 *)(lVar2 + 0x38);
        unaff_RBX = (*DAT_18007b808)(in_stack_00000068);
      }
      iVar4 = 0;
      uVar5 = in_stack_00000068;
      if ('\0' < *(char *)(lVar2 + 0x31)) {
        do {
          in_stack_00000068 = *(undefined8 *)(unaff_RBX + 0x100);
          (*DAT_18007b810)(uVar5,0x108);
          unaff_RBX = (*DAT_18007b808)(in_stack_00000068);
          iVar4 = iVar4 + 1;
          uVar5 = in_stack_00000068;
        } while (iVar4 < *(char *)(lVar2 + 0x31));
      }
      (*DAT_18007b810)(uVar1,0x60);
      in_RAX = in_stack_00000070;
    }
    lVar3 = lVar3 + 1;
    pcVar6 = pcVar6 + 0x60;
  } while (lVar3 < unaff_R13);
  (*DAT_18007b810)(in_stack_00000060,(int)unaff_R13 * 8 + 4);
  return;
}

/* ---- FUNC 0003A097 FUN_18003a097 (21 bytes) ---- */

void FUN_18003a097(void)

{
  (*DAT_18007b810)();
  return;
}

/* ---- FUNC 0003A0AC FUN_18003a0ac (6 bytes) ---- */

void FUN_18003a0ac(void)

{
  return;
}

/* ---- FUNC 0003A0C0 SEDelSettingValue (76 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint SEDelSettingValue(char *param_1,int param_2,ulonglong param_3,longlong param_4)

{
  char cVar1;
  undefined2 *puVar2;
  uint uVar3;
  char *pcVar4;
  ulonglong uVar5;
  undefined2 *puVar6;
  void *_Memory;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  ulonglong uVar10;
  longlong lVar11;
  longlong *plVar12;
  undefined1 auStack_378 [31];
  undefined2 uStack_359;
  undefined1 local_356 [782];
  ulonglong local_48;
  
                    /* 0x3a0c0  449  SEDelSettingValue */
  local_48 = DAT_1800791f8 ^ (ulonglong)auStack_378;
  uVar5 = param_3 & 0xffffffff;
  uVar3 = 1;
  uVar10 = param_3;
  lVar11 = param_4;
  pcVar4 = FUN_180039060(param_1);
  uVar8 = 0;
  if (pcVar4 != (char *)0x0) {
    uVar7 = (uint)param_3;
    if ((int)uVar7 < (int)pcVar4[0x31]) {
      _Memory = *(void **)(pcVar4 + 0x38);
      plVar12 = (longlong *)(pcVar4 + 0x38);
      if (0 < (int)uVar7) {
        do {
          plVar12 = (longlong *)((longlong)_Memory + 0x100);
          _Memory = (void *)*plVar12;
          uVar5 = uVar5 - 1;
        } while (uVar5 != 0);
      }
      if (param_2 != 0) {
        uVar5 = param_3 & 0xffffffff;
        do {
          uVar3 = FUN_180038f90(pcVar4,(uint)uVar5,uVar10,lVar11);
          uVar8 = (uint)uVar5 + 1;
          uVar5 = (ulonglong)uVar8;
        } while ((int)uVar8 < (int)pcVar4[0x31]);
        piVar9 = *(int **)((longlong)_Memory + 0x100);
        uVar10 = param_3 & 0xffffffff;
        if ((int)uVar7 < pcVar4[0x31] + -1) {
          do {
            uVar3 = FUN_180039580(pcVar4,piVar9,uVar7);
            piVar9 = *(int **)(piVar9 + 0x40);
            uVar8 = (int)uVar10 + 1;
            uVar10 = (ulonglong)uVar8;
          } while ((int)uVar8 < pcVar4[0x31] + -1);
        }
      }
      *plVar12 = *(longlong *)((longlong)_Memory + 0x100);
      free(_Memory);
      pcVar4[0x31] = pcVar4[0x31] + -1;
      uVar8 = uVar3;
      if (((param_4 != 0) && (uVar7 == 0)) && (pcVar4[0x20] == '\x03')) {
        lVar11 = 1 - (longlong)pcVar4;
        do {
          cVar1 = *pcVar4;
          pcVar4[(longlong)&uStack_359 + lVar11] = cVar1;
          pcVar4 = pcVar4 + 1;
        } while (cVar1 != '\0');
        puVar2 = &uStack_359;
        do {
          puVar6 = puVar2;
          puVar2 = (undefined2 *)((longlong)puVar6 + 1);
        } while (*(char *)((longlong)puVar6 + 1) != '\0');
        *(undefined2 *)((longlong)puVar6 + 1) = DAT_180056d24;
        *(undefined1 *)((longlong)puVar6 + 3) = DAT_180056d26;
        PostMainWndMessage(0x4f5,0,(longlong)&uStack_359 + 1);
      }
    }
    else {
      uVar8 = 0;
    }
  }
  return uVar8;
}

/* ---- FUNC 0003A10C FUN_18003a10c (55 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_18003a10c(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  longlong lVar2;
  undefined2 *puVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined2 *puVar6;
  char *unaff_RBX;
  void *_Memory;
  uint uVar7;
  ulonglong unaff_RSI;
  int unaff_EDI;
  uint uVar8;
  int *piVar9;
  ulonglong unaff_R12;
  longlong unaff_R13;
  longlong *plVar10;
  undefined2 uStackX_1f;
  undefined1 auStackX_22 [6];
  
  _Memory = *(void **)(unaff_RBX + 0x38);
  plVar10 = (longlong *)(unaff_RBX + 0x38);
  uVar7 = (uint)unaff_RSI;
  uVar5 = unaff_RSI;
  if (0 < (int)uVar7) {
    do {
      plVar10 = (longlong *)((longlong)_Memory + 0x100);
      _Memory = (void *)*plVar10;
      uVar5 = uVar5 - unaff_R12;
    } while (uVar5 != 0);
  }
  if (unaff_EDI != 0) {
    uVar5 = unaff_RSI & 0xffffffff;
    do {
      uVar4 = FUN_180038f90(unaff_RBX,(uint)uVar5,param_3,param_4);
      uVar8 = (uint)uVar5 + 1;
      uVar5 = (ulonglong)uVar8;
    } while ((int)uVar8 < (int)unaff_RBX[0x31]);
    piVar9 = *(int **)((longlong)_Memory + 0x100);
    uVar5 = unaff_RSI & 0xffffffff;
    if ((int)uVar7 < unaff_RBX[0x31] + -1) {
      do {
        uVar4 = FUN_180039580(unaff_RBX,piVar9,uVar7);
        piVar9 = *(int **)(piVar9 + 0x40);
        uVar8 = (int)uVar5 + 1;
        uVar5 = (ulonglong)uVar8;
      } while ((int)uVar8 < unaff_RBX[0x31] + -1);
    }
    unaff_R12 = (ulonglong)uVar4;
  }
  *plVar10 = *(longlong *)((longlong)_Memory + 0x100);
  free(_Memory);
  unaff_RBX[0x31] = unaff_RBX[0x31] + -1;
  if (((unaff_R13 != 0) && (uVar7 == 0)) && (unaff_RBX[0x20] == '\x03')) {
    lVar2 = 1 - (longlong)unaff_RBX;
    do {
      cVar1 = *unaff_RBX;
      unaff_RBX[(longlong)&uStackX_1f + lVar2] = cVar1;
      unaff_RBX = unaff_RBX + 1;
    } while (cVar1 != '\0');
    puVar3 = &uStackX_1f;
    do {
      puVar6 = puVar3;
      puVar3 = (undefined2 *)((longlong)puVar6 + 1);
    } while (*(char *)((longlong)puVar6 + 1) != '\0');
    *(undefined2 *)((longlong)puVar6 + 1) = DAT_180056d24;
    *(undefined1 *)((longlong)puVar6 + 3) = DAT_180056d26;
    PostMainWndMessage(0x4f5,0,(longlong)&uStackX_1f + 1);
  }
  return unaff_R12 & 0xffffffff;
}

/* ---- FUNC 0003A143 FUN_18003a143 (107 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint FUN_18003a143(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  longlong lVar2;
  undefined2 *puVar3;
  uint uVar4;
  undefined2 *puVar5;
  char *unaff_RBX;
  void *unaff_RBP;
  uint unaff_ESI;
  uint uVar6;
  int *piVar7;
  longlong unaff_R13;
  undefined8 *unaff_R14;
  undefined2 uStackX_1f;
  undefined1 auStackX_22 [6];
  
  uVar6 = unaff_ESI;
  do {
    uVar4 = FUN_180038f90(unaff_RBX,uVar6,param_3,param_4);
    uVar6 = uVar6 + 1;
  } while ((int)uVar6 < (int)unaff_RBX[0x31]);
  piVar7 = *(int **)((longlong)unaff_RBP + 0x100);
  uVar6 = unaff_ESI;
  if ((int)unaff_ESI < unaff_RBX[0x31] + -1) {
    do {
      uVar4 = FUN_180039580(unaff_RBX,piVar7,unaff_ESI);
      piVar7 = *(int **)(piVar7 + 0x40);
      uVar6 = uVar6 + 1;
    } while ((int)uVar6 < unaff_RBX[0x31] + -1);
  }
  *unaff_R14 = *(undefined8 *)((longlong)unaff_RBP + 0x100);
  free(unaff_RBP);
  unaff_RBX[0x31] = unaff_RBX[0x31] + -1;
  if (((unaff_R13 != 0) && (unaff_ESI == 0)) && (unaff_RBX[0x20] == '\x03')) {
    lVar2 = 1 - (longlong)unaff_RBX;
    do {
      cVar1 = *unaff_RBX;
      unaff_RBX[(longlong)&uStackX_1f + lVar2] = cVar1;
      unaff_RBX = unaff_RBX + 1;
    } while (cVar1 != '\0');
    puVar3 = &uStackX_1f;
    do {
      puVar5 = puVar3;
      puVar3 = (undefined2 *)((longlong)puVar5 + 1);
    } while (*(char *)((longlong)puVar5 + 1) != '\0');
    *(undefined2 *)((longlong)puVar5 + 1) = DAT_180056d24;
    *(undefined1 *)((longlong)puVar5 + 3) = DAT_180056d26;
    PostMainWndMessage(0x4f5,0,(longlong)&uStackX_1f + 1);
  }
  return uVar4;
}

/* ---- FUNC 0003A1AE FUN_18003a1ae (43 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_18003a1ae(void)

{
  char cVar1;
  longlong lVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  char *unaff_RBX;
  void *unaff_RBP;
  int unaff_ESI;
  undefined4 unaff_R12D;
  longlong unaff_R13;
  undefined8 *unaff_R14;
  undefined2 uStackX_1f;
  undefined1 auStackX_22 [6];
  
  *unaff_R14 = *(undefined8 *)((longlong)unaff_RBP + 0x100);
  free(unaff_RBP);
  unaff_RBX[0x31] = unaff_RBX[0x31] + -1;
  if (((unaff_R13 != 0) && (unaff_ESI == 0)) && (unaff_RBX[0x20] == '\x03')) {
    lVar2 = 1 - (longlong)unaff_RBX;
    do {
      cVar1 = *unaff_RBX;
      unaff_RBX[(longlong)&uStackX_1f + lVar2] = cVar1;
      unaff_RBX = unaff_RBX + 1;
    } while (cVar1 != '\0');
    puVar3 = &uStackX_1f;
    do {
      puVar4 = puVar3;
      puVar3 = (undefined2 *)((longlong)puVar4 + 1);
    } while (*(char *)((longlong)puVar4 + 1) != '\0');
    *(undefined2 *)((longlong)puVar4 + 1) = DAT_180056d24;
    *(undefined1 *)((longlong)puVar4 + 3) = DAT_180056d26;
    PostMainWndMessage(0x4f5,0,(longlong)&uStackX_1f + 1);
  }
  return unaff_R12D;
}

/* ---- FUNC 0003A1D9 FUN_18003a1d9 (131 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_18003a1d9(void)

{
  char cVar1;
  longlong lVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  char *unaff_RBX;
  int unaff_ESI;
  undefined4 unaff_R12D;
  undefined2 uStackX_1f;
  undefined1 auStackX_22 [6];
  
  if ((unaff_ESI == 0) && (unaff_RBX[0x20] == '\x03')) {
    lVar2 = 1 - (longlong)unaff_RBX;
    do {
      cVar1 = *unaff_RBX;
      unaff_RBX[(longlong)&uStackX_1f + lVar2] = cVar1;
      unaff_RBX = unaff_RBX + 1;
    } while (cVar1 != '\0');
    puVar3 = &uStackX_1f;
    do {
      puVar4 = puVar3;
      puVar3 = (undefined2 *)((longlong)puVar4 + 1);
    } while (*(char *)((longlong)puVar4 + 1) != '\0');
    *(undefined2 *)((longlong)puVar4 + 1) = DAT_180056d24;
    *(undefined1 *)((longlong)puVar4 + 3) = DAT_180056d26;
    PostMainWndMessage(0x4f5,0,(longlong)&uStackX_1f + 1);
  }
  return unaff_R12D;
}

/* ---- FUNC 0003A260 SEFindConfigCA (421 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 SEFindConfigCA(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  ulonglong uVar5;
  char *pcVar6;
  undefined1 auStackY_c58 [32];
  uint local_c20 [2];
  char local_c18 [2048];
  undefined1 local_418 [1008];
  ulonglong local_28;
  
                    /* 0x3a260  450  SEFindConfigCA */
  uVar1 = DAT_18007b7e8;
  local_28 = DAT_1800791f8 ^ (ulonglong)auStackY_c58;
  puVar4 = (undefined8 *)0x0;
  DAT_18007b7e8 = 2;
  puVar3 = operator_new(0x138);
  if (puVar3 != (undefined8 *)0x0) {
    puVar4 = FUN_180018980(puVar3,param_1,0,param_3,0,0);
  }
  iVar2 = (**(code **)*puVar4)(puVar4,&DAT_180057a78);
  if (iVar2 != 0) {
    FUN_180007de0(local_418,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\settings.cpp",0x546);
    LogMessage(local_418);
  }
  uVar5 = FUN_18001b180((longlong *)0x0,(longlong)local_c18);
  iVar2 = (int)uVar5;
  do {
    if ((iVar2 != 0) || (local_c18[0] == '\0')) goto LAB_18003a3cf;
    pcVar6 = strchr(local_c18,10);
    if (pcVar6 != (char *)0x0) {
      *pcVar6 = '\0';
    }
    if ((local_c18[0] == '\0') || (local_c18[0] == '#')) goto LAB_18003a3cf;
    pcVar6 = strchr(local_c18,0x20);
    if (pcVar6 != (char *)0x0) {
      *pcVar6 = '\0';
      iVar2 = strcmp(local_c18,"tpsaupgrade");
      if (iVar2 == 0) {
        local_c20[0] = atol(pcVar6 + 1);
        SESetSettingValue(local_c18,local_c20,0,0,0);
LAB_18003a3cf:
        DAT_18007b7e8 = uVar1;
        (**(code **)(_DAT_00000000 + 0x10))();
        return 0;
      }
    }
    uVar5 = FUN_18001b180((longlong *)0x0,(longlong)local_c18);
    iVar2 = (int)uVar5;
  } while( true );
}

/* ---- FUNC 0003A410 SEFreeSettings (190 bytes) ---- */

void SEFreeSettings(void)

{
  void *pvVar1;
  void *_Memory;
  char *pcVar2;
  longlong lVar3;
  int iVar4;
  
                    /* 0x3a410  451  SEFreeSettings */
  pcVar2 = &DAT_180072291;
  lVar3 = 0x129;
  do {
    _Memory = *(void **)(pcVar2 + 7);
    iVar4 = 0;
    if ('\0' < *pcVar2) {
      do {
        pvVar1 = *(void **)((longlong)_Memory + 0x100);
        free(_Memory);
        iVar4 = iVar4 + 1;
        _Memory = pvVar1;
      } while (iVar4 < *pcVar2);
    }
    *pcVar2 = '\0';
    pcVar2[7] = '\0';
    pcVar2[8] = '\0';
    pcVar2[9] = '\0';
    pcVar2[10] = '\0';
    pcVar2[0xb] = '\0';
    pcVar2[0xc] = '\0';
    pcVar2[0xd] = '\0';
    pcVar2[0xe] = '\0';
    pcVar2 = pcVar2 + 0x60;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  if (DAT_18007b818 != (HMODULE)0x0) {
    FreeLibrary(DAT_18007b818);
    DAT_18007b818 = (HMODULE)0x0;
  }
  if (DAT_18007b820 != (HMODULE)0x0) {
    FreeLibrary(DAT_18007b820);
    DAT_18007b820 = (HMODULE)0x0;
  }
  DAT_18007b7ec = 0;
  return;
}

/* ---- FUNC 0003A4D0 SEGetLength (28 bytes) ---- */

int SEGetLength(char *param_1)

{
  char *pcVar1;
  
                    /* 0x3a4d0  452  SEGetLength */
  pcVar1 = FUN_180039060(param_1);
  if (pcVar1 == (char *)0x0) {
    return 0;
  }
  return (int)pcVar1[0x31];
}

/* ---- FUNC 0003A4F0 SEGetSettingInfo (234 bytes) ---- */

int SEGetSettingInfo(int param_1,char *param_2,int param_3,int *param_4,undefined8 *param_5)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  longlong lVar5;
  longlong lVar6;
  
                    /* 0x3a4f0  453  SEGetSettingInfo */
  if (param_1 == 0) {
    lVar5 = (longlong)param_3 * 0x60;
    pcVar3 = s_paramdata_180072260 + lVar5;
    lVar6 = (longlong)param_2 - (longlong)pcVar3;
    do {
      cVar1 = *pcVar3;
      pcVar3[lVar6] = cVar1;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    *param_5 = (&DAT_180072288)[(longlong)param_3 * 0xc];
    *param_4 = (int)(char)(&DAT_180072280)[lVar5];
    return param_3;
  }
  iVar4 = 0;
  do {
    lVar5 = (longlong)iVar4 * 0x60;
    pcVar3 = param_2;
    do {
      cVar1 = *pcVar3;
      cVar2 = pcVar3[(longlong)(s_paramdata_180072260 + (lVar5 - (longlong)param_2))];
      if (cVar1 != cVar2) break;
      pcVar3 = pcVar3 + 1;
    } while (cVar2 != '\0');
    if (cVar1 == cVar2) {
      *param_5 = (&DAT_180072288)[(longlong)iVar4 * 0xc];
      *param_4 = (int)(char)(&DAT_180072280)[lVar5];
      return iVar4;
    }
    iVar4 = iVar4 + 1;
    if (0x128 < iVar4) {
      return -1;
    }
  } while( true );
}

/* ---- FUNC 0003A5E0 SEGetSettingValue (89 bytes) ---- */

longlong SEGetSettingValue(char *param_1,uint param_2)

{
  char cVar1;
  char *pcVar2;
  longlong lVar3;
  ulonglong uVar4;
  
                    /* 0x3a5e0  454  SEGetSettingValue */
  pcVar2 = FUN_180039060(param_1);
  if ((pcVar2 != (char *)0x0) && ((int)param_2 < (int)pcVar2[0x31])) {
    lVar3 = *(longlong *)(pcVar2 + 0x38);
    if (0 < (int)param_2) {
      uVar4 = (ulonglong)param_2;
      do {
        lVar3 = *(longlong *)(lVar3 + 0x100);
        uVar4 = uVar4 - 1;
      } while (uVar4 != 0);
    }
    cVar1 = pcVar2[0x20];
    if (cVar1 == '\x01') {
      return lVar3;
    }
    if (cVar1 == '\x02') {
      return lVar3;
    }
    if (cVar1 == '\x03') {
      return lVar3;
    }
  }
  return 0;
}

/* ---- FUNC 0003A640 SEGetSettingsLength (6 bytes) ---- */

undefined8 SEGetSettingsLength(void)

{
                    /* 0x3a640  455  SEGetSettingsLength */
  return 0x129;
}

/* ---- FUNC 0003A650 SEInitialize (86 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 SEInitialize(int param_1,undefined8 param_2,undefined8 param_3,ulonglong param_4)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  ulonglong uVar6;
  char *pcVar7;
  FILE *_File;
  undefined8 uVar8;
  LPCSTR pCVar9;
  HKEY__ *hKey;
  longlong *plVar10;
  FARPROC pFVar11;
  INT_PTR IVar12;
  uint *puVar13;
  undefined1 *puVar14;
  longlong lVar15;
  char *pcVar16;
  char *pcVar17;
  uint uVar18;
  size_t _MaxCount;
  undefined1 *puVar20;
  undefined4 uVar21;
  bool bVar22;
  bool bVar23;
  undefined1 auStackY_508 [32];
  uint local_4d8 [2];
  char *local_4d0;
  double local_4c8;
  undefined8 local_4c0 [4];
  char local_4a0 [16];
  char local_490 [15];
  undefined1 uStack_481;
  char local_480 [55];
  char acStack_449 [257];
  CHAR local_348 [272];
  char local_238 [512];
  ulonglong local_38;
  size_t sVar19;
  
                    /* 0x3a650  456  SEInitialize */
  local_38 = DAT_1800791f8 ^ (ulonglong)auStackY_508;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4d0);
  bVar23 = false;
  uVar21 = 1;
  if (DAT_18007b7ec != 0) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4d0);
    return 1;
  }
  uVar6 = FUN_1800240b0();
  bVar22 = (int)uVar6 != 1;
  if (bVar22) {
    local_4a0[0] = s_PropMmg_ini_180056bc0[0];
    local_4a0[1] = s_PropMmg_ini_180056bc0[1];
    local_4a0[2] = s_PropMmg_ini_180056bc0[2];
    local_4a0[3] = s_PropMmg_ini_180056bc0[3];
    local_4a0[4] = s_PropMmg_ini_180056bc0[4];
    local_4a0[5] = s_PropMmg_ini_180056bc0[5];
    local_4a0[6] = s_PropMmg_ini_180056bc0[6];
    local_4a0[7] = s_PropMmg_ini_180056bc0[7];
    local_4a0[8] = s_PropMmg_ini_180056bc0[8];
    local_4a0[9] = s_PropMmg_ini_180056bc0[9];
    local_4a0[10] = s_PropMmg_ini_180056bc0[10];
    local_4a0[0xb] = s_PropMmg_ini_180056bc0[0xb];
  }
  else {
    builtin_strncpy(local_4a0,"mmg.ini",8);
  }
  pcVar16 = 
  "System copy of MMG.INI is missing or is not compatible with this version.\nYou must update the system copy of MMG.INI from the Aspen Plus CD."
  ;
  if (bVar22) {
    pcVar16 = 
    "System copy of PROPMMG.INI is missing or is not compatible with this version.\nYou must update the system copy of PROPMMG.INI from the Aspen Properties CD."
    ;
  }
  pcVar17 = 
  "Local copy of MMG.INI file is not compatible with current version.\nUse system version of MMG.INI?  Cancel will exit Aspen Plus."
  ;
  if (bVar22) {
    pcVar17 = 
    "Local copy of PROPMMG.INI file is not compatible with current version.\nUse system version of PROPMMG.INI?  Cancel will exit Aspen Properties."
    ;
  }
  pcVar7 = FUN_180026a00(1,local_4a0,local_238);
  if (pcVar7 == (char *)0x0) {
    pCVar9 = (LPCSTR)FUN_1800240f0();
    MMMessageBox((HWND)0x0,pcVar16,pCVar9,0x30,0xffffffff);
    goto LAB_18003ad5f;
  }
  _File = fopen(local_238,"r");
  uVar8 = FUN_180038ea0(_File);
  bVar22 = true;
  if ((int)uVar8 == 0) {
    if (_File != (FILE *)0x0) {
      fclose(_File);
      _File = (FILE *)0x0;
    }
    sVar19 = 0xffffffffffffffff;
    do {
      _MaxCount = sVar19 + 1;
      lVar15 = sVar19 + 1;
      sVar19 = _MaxCount;
    } while (local_4a0[lVar15] != '\0');
    iVar4 = _strnicmp(local_238,local_4a0,_MaxCount);
    bVar22 = bVar23;
    if (iVar4 == 0) {
      pCVar9 = (LPCSTR)FUN_1800240f0();
      param_4 = 0x31;
      iVar4 = MMMessageBox((HWND)0x0,pcVar17,pCVar9,0x31,0xffffffff);
      if ((iVar4 == 1) && (pcVar17 = FUN_180026a00(3,local_4a0,local_238), pcVar17 != (char *)0x0))
      {
        _File = fopen(local_238,"r");
        uVar8 = FUN_180038ea0(_File);
        bVar22 = true;
        if ((int)uVar8 == 0) {
          if (_File != (FILE *)0x0) {
            fclose(_File);
            _File = (FILE *)0x0;
          }
          goto LAB_18003a818;
        }
      }
    }
    else {
LAB_18003a818:
      pCVar9 = (LPCSTR)FUN_1800240f0();
      param_4 = 0x30;
      MMMessageBox((HWND)0x0,pcVar16,pCVar9,0x30,0xffffffff);
      bVar22 = bVar23;
    }
  }
  if (!bVar22) {
LAB_18003ad5f:
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4d0);
    return 0;
  }
  if ((param_1 != 0) && (hKey = GetAppRegistryKey(), hKey != (HKEY__ *)0x0)) {
    RegDeleteKeyA(hKey,"mmgini");
  }
  plVar10 = FUN_180038cd0(local_4c0,&DAT_180053860);
  DAT_18007b818 = FUN_18000da20(plVar10);
  plVar10 = FUN_180038cd0(local_4c0,"+%XWM\"&&");
  DAT_18007b820 = FUN_18000da20(plVar10);
  if (DAT_18007b818 != (HMODULE)0x0) {
    pFVar11 = GetProcAddress(DAT_18007b818,"SMfwdini");
    if (pFVar11 != (FARPROC)0x0) {
      (*pFVar11)();
    }
    pFVar11 = GetProcAddress(DAT_18007b818,"GRsetaped");
    (*pFVar11)();
    pFVar11 = GetProcAddress(DAT_18007b818,"GRinqaped");
    IVar12 = (*pFVar11)();
    DAT_18007b828 = (int)IVar12;
    pFVar11 = GetProcAddress(DAT_18007b818,"GRsetdbProvider");
    (*pFVar11)();
    pFVar11 = GetProcAddress(DAT_18007b818,"GRinqdbProvider");
    IVar12 = (*pFVar11)();
    _DAT_18007b82c = (undefined4)IVar12;
    pFVar11 = GetProcAddress(DAT_18007b818,"GRsetNistHoc");
    (*pFVar11)();
    pFVar11 = GetProcAddress(DAT_18007b818,"GRinqNistHoc");
    IVar12 = (*pFVar11)();
    _DAT_18007b830 = (undefined4)IVar12;
  }
  GetModuleFileNameA((HMODULE)0x0,local_348,0x104);
  pcVar16 = _strlwr(local_348);
  pcVar16 = strstr(pcVar16,"aspenplus.exe");
  if (pcVar16 == (char *)0x0) {
    pcVar16 = _strlwr(local_348);
    pcVar16 = strstr(pcVar16,"aspenproperties.exe");
    if ((pcVar16 == (char *)0x0) && (DAT_18007b828 == 1)) {
      if (DAT_18007b818 == (HMODULE)0x0) goto LAB_18003aa5e;
      pFVar11 = GetProcAddress(DAT_18007b818,"InitializeApedGUIDataDll");
      acStack_449[1] = 0;
      pcVar16 = acStack_449;
      do {
        pcVar17 = pcVar16;
        pcVar16 = pcVar17 + 1;
      } while (pcVar17[1] != '\0');
      *(undefined8 *)(pcVar17 + 1) = s_apedconnectionerror_log_180056ca0._0_8_;
      *(undefined8 *)(pcVar17 + 9) = s_apedconnectionerror_log_180056ca0._8_8_;
      *(undefined8 *)(pcVar17 + 0x11) = s_apedconnectionerror_log_180056ca0._16_8_;
      (*pFVar11)(acStack_449 + 1);
    }
  }
  if ((DAT_18007b818 != (HMODULE)0x0) &&
     (DAT_18007b7b8 = GetProcAddress(DAT_18007b818,"Get_new_pure_com"),
     DAT_18007b818 != (HMODULE)0x0)) {
    DAT_18007b7c8 = GetProcAddress(DAT_18007b818,"GetDatabaseDatabankName");
  }
LAB_18003aa5e:
  pcVar16 = s_paramdata_180072260;
  puVar20 = &stack0xfffffffe7ff8d920;
  do {
    if ((DAT_18007b818 != (HMODULE)0x0) && (pcVar16[0x40] != '\0')) {
      pFVar11 = GetProcAddress(DAT_18007b818,pcVar16 + 0x40);
      *(FARPROC *)(pcVar16 + 0x28) = pFVar11;
    }
    pcVar17 = pcVar16;
    uVar18 = 0;
    do {
      do {
        cVar1 = *pcVar17;
        puVar20[(longlong)pcVar17] = cVar1;
        pcVar17 = pcVar17 + 1;
      } while (cVar1 != '\0');
      if (uVar18 != 0) {
        FUN_180007de0(local_490,&DAT_180056ce8,(ulonglong)uVar18,param_4);
        puVar14 = &uStack_481;
        do {
          pcVar17 = puVar14 + 1;
          puVar14 = puVar14 + 1;
        } while (*pcVar17 != '\0');
        lVar15 = 0;
        do {
          cVar1 = local_490[lVar15];
          puVar14[lVar15] = cVar1;
          lVar15 = lVar15 + 1;
        } while (cVar1 != '\0');
      }
      uVar3 = uVar18;
      if (pcVar16[0x21] == '\0') break;
      cVar1 = pcVar16[0x20];
      if (cVar1 == '\x01') {
        iVar4 = strcmp(pcVar16,"polyplusenabled");
        if (iVar4 == 0) {
          param_4 = (ulonglong)uVar18;
          local_4d8[0] = 1;
          SESetSettingValue(pcVar16,local_4d8,0,uVar18,0);
          break;
        }
        uVar5 = MMGetProfileInt("mmgini",local_480,-9999);
        local_4d8[0] = uVar5;
        if (uVar5 == 0xffffd8f1) break;
        iVar4 = strcmp(pcVar16,"linklimit");
        if ((iVar4 == 0) && (uVar5 == 500)) {
          local_4d8[0] = 5000;
        }
        param_4 = (ulonglong)uVar18;
        uVar3 = SESetSettingValue(pcVar16,local_4d8,0,uVar18,0);
        uVar2 = uVar21;
        if (uVar3 == 0) {
          uVar2 = 0;
        }
      }
      else if (cVar1 == '\x02') {
        pcVar17 = GetProfileStringA("mmgini",local_480,(char *)0x0);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4d0,
                   pcVar17);
        if (pcVar17 != (char *)0x0) {
          operator_delete__(pcVar17);
        }
        if (*(int *)(local_4d0 + -0x10) == 0) break;
        local_4c8 = atof(local_4d0);
        param_4 = (ulonglong)uVar18;
        uVar3 = SESetSettingValue(pcVar16,(uint *)&local_4c8,0,uVar18,0);
        uVar2 = 0;
        if (uVar3 != 0) {
          uVar2 = uVar21;
        }
      }
      else {
        if (cVar1 != '\x03') break;
        pcVar17 = GetProfileStringA("mmgini",local_480,(char *)0x0);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4d0,
                   pcVar17);
        if (pcVar17 != (char *)0x0) {
          operator_delete__(pcVar17);
        }
        if (*(int *)(local_4d0 + -0x10) == 0) break;
        puVar13 = (uint *)ATL::CSimpleStringT<char,1>::GetBuffer
                                    ((CSimpleStringT<char,1> *)&local_4d0,
                                     *(int *)(local_4d0 + -0x10));
        param_4 = (ulonglong)uVar18;
        uVar3 = SESetSettingValue(pcVar16,puVar13,0,uVar18,0);
        ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)&local_4d0,-1);
        uVar2 = 0;
        if (uVar3 != 0) {
          uVar2 = uVar21;
        }
      }
      uVar21 = uVar2;
      uVar3 = uVar18 + 1;
      bVar23 = uVar18 != uVar3;
      pcVar17 = pcVar16;
      uVar18 = uVar3;
    } while (bVar23);
    if ((uVar3 == 0) && (_File != (FILE *)0x0)) {
      FUN_1800390d0(_File,pcVar16,1);
    }
    pcVar16 = pcVar16 + 0x60;
    puVar20 = puVar20 + -0x60;
    if (0x1800791bf < (longlong)pcVar16) {
      if (_File != (FILE *)0x0) {
        fclose(_File);
      }
      DAT_18007b7ec = 1;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_4d0);
      return uVar21;
    }
  } while( true );
}

/* ---- FUNC 0003A6A6 FUN_18003a6a6 (410 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_18003a6a6(void)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  ulonglong uVar6;
  char *pcVar7;
  FILE *_File;
  undefined8 uVar8;
  LPCSTR pCVar9;
  HKEY__ *hKey;
  longlong *plVar10;
  FARPROC pFVar11;
  INT_PTR IVar12;
  uint *puVar13;
  longlong lVar14;
  longlong lVar15;
  char *pcVar16;
  longlong unaff_RBP;
  char *pcVar17;
  int unaff_EDI;
  uint uVar18;
  size_t _MaxCount;
  ulonglong in_R9;
  int unaff_R14D;
  longlong lVar20;
  int unaff_R15D;
  bool bVar21;
  uint in_stack_00000030;
  char *in_stack_00000038;
  double in_stack_00000040;
  char cStack0000000000000068;
  char cStack0000000000000069;
  char cStack000000000000006a;
  char cStack000000000000006b;
  char cStack000000000000006c;
  char cStack000000000000006d;
  char cStack000000000000006e;
  char cStack000000000000006f;
  char cStack0000000000000070;
  char cStack0000000000000071;
  char cStack0000000000000072;
  char cStack0000000000000073;
  size_t sVar19;
  
  uVar6 = FUN_1800240b0();
  bVar21 = (int)uVar6 != unaff_R15D;
  if (bVar21) {
    cStack0000000000000068 = s_PropMmg_ini_180056bc0[0];
    cStack0000000000000069 = s_PropMmg_ini_180056bc0[1];
    cStack000000000000006a = s_PropMmg_ini_180056bc0[2];
    cStack000000000000006b = s_PropMmg_ini_180056bc0[3];
    cStack000000000000006c = s_PropMmg_ini_180056bc0[4];
    cStack000000000000006d = s_PropMmg_ini_180056bc0[5];
    cStack000000000000006e = s_PropMmg_ini_180056bc0[6];
    cStack000000000000006f = s_PropMmg_ini_180056bc0[7];
    cStack0000000000000070 = s_PropMmg_ini_180056bc0[8];
    cStack0000000000000071 = s_PropMmg_ini_180056bc0[9];
    cStack0000000000000072 = s_PropMmg_ini_180056bc0[10];
    cStack0000000000000073 = s_PropMmg_ini_180056bc0[0xb];
  }
  else {
    cStack0000000000000068 = 'm';
    cStack0000000000000069 = 'm';
    cStack000000000000006a = 'g';
    cStack000000000000006b = '.';
    cStack000000000000006c = 'i';
    cStack000000000000006d = 'n';
    cStack000000000000006e = 'i';
    cStack000000000000006f = '\0';
  }
  pcVar16 = 
  "System copy of MMG.INI is missing or is not compatible with this version.\nYou must update the system copy of MMG.INI from the Aspen Plus CD."
  ;
  if (bVar21) {
    pcVar16 = 
    "System copy of PROPMMG.INI is missing or is not compatible with this version.\nYou must update the system copy of PROPMMG.INI from the Aspen Properties CD."
    ;
  }
  pcVar17 = 
  "Local copy of MMG.INI file is not compatible with current version.\nUse system version of MMG.INI?  Cancel will exit Aspen Plus."
  ;
  if (bVar21) {
    pcVar17 = 
    "Local copy of PROPMMG.INI file is not compatible with current version.\nUse system version of PROPMMG.INI?  Cancel will exit Aspen Properties."
    ;
  }
  pcVar7 = FUN_180026a00(unaff_R15D,&stack0x00000068,(char *)(unaff_RBP + 0x1d0));
  if (pcVar7 == (char *)0x0) {
    pCVar9 = (LPCSTR)FUN_1800240f0();
    MMMessageBox((HWND)0x0,pcVar16,pCVar9,0x30,0xffffffff);
    goto LAB_18003ad5f;
  }
  _File = fopen((char *)(unaff_RBP + 0x1d0),"r");
  uVar8 = FUN_180038ea0(_File);
  iVar4 = unaff_R15D;
  if ((int)uVar8 == 0) {
    if (_File != (FILE *)0x0) {
      fclose(_File);
      _File = (FILE *)0x0;
    }
    sVar19 = 0xffffffffffffffff;
    do {
      _MaxCount = sVar19 + 1;
      lVar20 = sVar19 + 1;
      sVar19 = _MaxCount;
    } while (*(char *)((longlong)&stack0x00000068 + lVar20) != (char)unaff_EDI);
    iVar2 = _strnicmp((char *)(unaff_RBP + 0x1d0),&stack0x00000068,_MaxCount);
    iVar4 = unaff_EDI;
    if (iVar2 == 0) {
      pCVar9 = (LPCSTR)FUN_1800240f0();
      in_R9 = 0x31;
      iVar2 = MMMessageBox((HWND)0x0,pcVar17,pCVar9,0x31,0xffffffff);
      if ((iVar2 == unaff_R15D) &&
         (pcVar17 = FUN_180026a00(3,&stack0x00000068,(char *)(unaff_RBP + 0x1d0)),
         pcVar17 != (char *)0x0)) {
        _File = fopen((char *)(unaff_RBP + 0x1d0),"r");
        uVar8 = FUN_180038ea0(_File);
        iVar4 = unaff_R15D;
        if ((int)uVar8 == 0) {
          if (_File != (FILE *)0x0) {
            fclose(_File);
            _File = (FILE *)0x0;
          }
          goto LAB_18003a818;
        }
      }
    }
    else {
LAB_18003a818:
      pCVar9 = (LPCSTR)FUN_1800240f0();
      in_R9 = 0x30;
      MMMessageBox((HWND)0x0,pcVar16,pCVar9,0x30,0xffffffff);
      iVar4 = unaff_EDI;
    }
  }
  if (iVar4 == 0) {
LAB_18003ad5f:
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&stack0x00000038);
    return 0;
  }
  if ((unaff_R14D != 0) && (hKey = GetAppRegistryKey(), hKey != (HKEY__ *)0x0)) {
    RegDeleteKeyA(hKey,"mmgini");
  }
  plVar10 = FUN_180038cd0((undefined8 *)&stack0x00000048,&DAT_180053860);
  DAT_18007b818 = FUN_18000da20(plVar10);
  plVar10 = FUN_180038cd0((undefined8 *)&stack0x00000048,"+%XWM\"&&");
  DAT_18007b820 = FUN_18000da20(plVar10);
  if (DAT_18007b818 != (HMODULE)0x0) {
    pFVar11 = GetProcAddress(DAT_18007b818,"SMfwdini");
    if (pFVar11 != (FARPROC)0x0) {
      (*pFVar11)();
    }
    pFVar11 = GetProcAddress(DAT_18007b818,"GRsetaped");
    (*pFVar11)();
    pFVar11 = GetProcAddress(DAT_18007b818,"GRinqaped");
    IVar12 = (*pFVar11)();
    DAT_18007b828 = (int)IVar12;
    pFVar11 = GetProcAddress(DAT_18007b818,"GRsetdbProvider");
    (*pFVar11)();
    pFVar11 = GetProcAddress(DAT_18007b818,"GRinqdbProvider");
    IVar12 = (*pFVar11)();
    _DAT_18007b82c = (undefined4)IVar12;
    pFVar11 = GetProcAddress(DAT_18007b818,"GRsetNistHoc");
    (*pFVar11)();
    pFVar11 = GetProcAddress(DAT_18007b818,"GRinqNistHoc");
    IVar12 = (*pFVar11)();
    _DAT_18007b830 = (undefined4)IVar12;
  }
  GetModuleFileNameA((HMODULE)0x0,(LPSTR)(unaff_RBP + 0xc0),0x104);
  pcVar16 = _strlwr((char *)(unaff_RBP + 0xc0));
  pcVar16 = strstr(pcVar16,"aspenplus.exe");
  if (pcVar16 == (char *)0x0) {
    pcVar16 = _strlwr((char *)(unaff_RBP + 0xc0));
    pcVar16 = strstr(pcVar16,"aspenproperties.exe");
    if ((pcVar16 == (char *)0x0) && (DAT_18007b828 == unaff_R15D)) {
      if (DAT_18007b818 == (HMODULE)0x0) goto LAB_18003aa5e;
      pFVar11 = GetProcAddress(DAT_18007b818,"InitializeApedGUIDataDll");
      *(undefined1 *)(unaff_RBP + -0x40) = 0;
      uVar8 = s_apedconnectionerror_log_180056ca0._8_8_;
      pcVar16 = (char *)(unaff_RBP + -0x41);
      do {
        pcVar17 = pcVar16;
        pcVar16 = pcVar17 + 1;
      } while (pcVar17[1] != '\0');
      *(undefined8 *)(pcVar17 + 1) = s_apedconnectionerror_log_180056ca0._0_8_;
      *(undefined8 *)(pcVar17 + 9) = uVar8;
      *(undefined8 *)(pcVar17 + 0x11) = s_apedconnectionerror_log_180056ca0._16_8_;
      (*pFVar11)(unaff_RBP + -0x40);
    }
  }
  if ((DAT_18007b818 != (HMODULE)0x0) &&
     (DAT_18007b7b8 = GetProcAddress(DAT_18007b818,"Get_new_pure_com"),
     DAT_18007b818 != (HMODULE)0x0)) {
    DAT_18007b7c8 = GetProcAddress(DAT_18007b818,"GetDatabaseDatabankName");
  }
LAB_18003aa5e:
  pcVar16 = s_paramdata_180072260;
  lVar20 = unaff_RBP + -0x1800722d8;
  do {
    if ((DAT_18007b818 != (HMODULE)0x0) && (pcVar16[0x40] != '\0')) {
      pFVar11 = GetProcAddress(DAT_18007b818,pcVar16 + 0x40);
      *(FARPROC *)(pcVar16 + 0x28) = pFVar11;
    }
    uVar6 = 0;
    do {
      uVar18 = (uint)uVar6;
      pcVar17 = pcVar16;
      do {
        cVar1 = *pcVar17;
        pcVar17[lVar20] = cVar1;
        pcVar17 = pcVar17 + 1;
      } while (cVar1 != '\0');
      if (uVar18 != 0) {
        FUN_180007de0(&stack0x00000078,&DAT_180056ce8,uVar6,in_R9);
        lVar14 = unaff_RBP + -0x79;
        do {
          pcVar17 = (char *)(lVar14 + 1);
          lVar14 = lVar14 + 1;
        } while (*pcVar17 != '\0');
        lVar15 = 0;
        do {
          cVar1 = (&stack0x00000078)[lVar15];
          *(char *)(lVar14 + lVar15) = cVar1;
          lVar15 = lVar15 + 1;
        } while (cVar1 != '\0');
      }
      uVar3 = uVar18;
      if (pcVar16[0x21] == '\0') break;
      cVar1 = pcVar16[0x20];
      if (cVar1 == '\x01') {
        iVar4 = strcmp(pcVar16,"polyplusenabled");
        if (iVar4 == 0) {
          in_stack_00000030 = 1;
          SESetSettingValue(pcVar16,&stack0x00000030,0,uVar18,0);
          in_R9 = uVar6;
          break;
        }
        uVar5 = MMGetProfileInt("mmgini",(char *)(unaff_RBP + -0x78),-9999);
        in_stack_00000030 = uVar5;
        if (uVar5 == 0xffffd8f1) break;
        iVar4 = strcmp(pcVar16,"linklimit");
        if ((iVar4 == 0) && (uVar5 == 500)) {
          in_stack_00000030 = 5000;
        }
        in_R9 = uVar6;
        uVar3 = SESetSettingValue(pcVar16,&stack0x00000030,0,uVar18,0);
        uVar6 = (ulonglong)(uVar18 + 1);
        iVar4 = unaff_R15D;
        if (uVar3 == 0) {
          iVar4 = 0;
        }
      }
      else if (cVar1 == '\x02') {
        pcVar17 = GetProfileStringA("mmgini",(char *)(unaff_RBP + -0x78),(char *)0x0);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&stack0x00000038
                   ,pcVar17);
        if (pcVar17 != (char *)0x0) {
          operator_delete__(pcVar17);
        }
        if (*(int *)(in_stack_00000038 + -0x10) == 0) break;
        in_stack_00000040 = atof(in_stack_00000038);
        in_R9 = uVar6;
        uVar3 = SESetSettingValue(pcVar16,(uint *)&stack0x00000040,0,uVar18,0);
        uVar6 = (ulonglong)(uVar18 + 1);
        iVar4 = 0;
        if (uVar3 != 0) {
          iVar4 = unaff_R15D;
        }
      }
      else {
        if (cVar1 != '\x03') break;
        pcVar17 = GetProfileStringA("mmgini",(char *)(unaff_RBP + -0x78),(char *)0x0);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&stack0x00000038
                   ,pcVar17);
        if (pcVar17 != (char *)0x0) {
          operator_delete__(pcVar17);
        }
        if (*(int *)(in_stack_00000038 + -0x10) == 0) break;
        puVar13 = (uint *)ATL::CSimpleStringT<char,1>::GetBuffer
                                    ((CSimpleStringT<char,1> *)&stack0x00000038,
                                     *(int *)(in_stack_00000038 + -0x10));
        in_R9 = uVar6;
        uVar3 = SESetSettingValue(pcVar16,puVar13,0,uVar18,0);
        uVar6 = (ulonglong)(uVar18 + 1);
        ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)&stack0x00000038,-1);
        iVar4 = 0;
        if (uVar3 != 0) {
          iVar4 = unaff_R15D;
        }
      }
      unaff_R15D = iVar4;
      uVar3 = (uint)uVar6;
    } while (uVar18 != uVar3);
    if ((uVar3 == 0) && (_File != (FILE *)0x0)) {
      FUN_1800390d0(_File,pcVar16,1);
    }
    pcVar16 = pcVar16 + 0x60;
    lVar20 = lVar20 + -0x60;
    if (0x1800791bf < (longlong)pcVar16) {
      if (_File != (FILE *)0x0) {
        fclose(_File);
      }
      DAT_18007b7ec = 1;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&stack0x00000038);
      return unaff_R15D;
    }
  } while( true );
}

/* ---- FUNC 0003A840 FUN_18003a840 (1244 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_18003a840(void)

{
  char cVar1;
  undefined8 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  HKEY__ *hKey;
  longlong *plVar6;
  FARPROC pFVar7;
  INT_PTR IVar8;
  char *pcVar9;
  char *pcVar10;
  uint *puVar11;
  longlong lVar12;
  longlong lVar13;
  longlong unaff_RBP;
  uint uVar14;
  ulonglong in_R9;
  FILE *unaff_R13;
  int unaff_R14D;
  longlong lVar15;
  int unaff_R15D;
  bool bVar16;
  uint in_stack_00000030;
  char *in_stack_00000038;
  double in_stack_00000040;
  
  if ((unaff_R14D != 0) && (hKey = GetAppRegistryKey(), hKey != (HKEY__ *)0x0)) {
    RegDeleteKeyA(hKey,"mmgini");
  }
  plVar6 = FUN_180038cd0((undefined8 *)&stack0x00000048,&DAT_180053860);
  DAT_18007b818 = FUN_18000da20(plVar6);
  plVar6 = FUN_180038cd0((undefined8 *)&stack0x00000048,"+%XWM\"&&");
  DAT_18007b820 = FUN_18000da20(plVar6);
  if (DAT_18007b818 != (HMODULE)0x0) {
    pFVar7 = GetProcAddress(DAT_18007b818,"SMfwdini");
    if (pFVar7 != (FARPROC)0x0) {
      (*pFVar7)();
    }
    pFVar7 = GetProcAddress(DAT_18007b818,"GRsetaped");
    (*pFVar7)();
    pFVar7 = GetProcAddress(DAT_18007b818,"GRinqaped");
    IVar8 = (*pFVar7)();
    DAT_18007b828 = (int)IVar8;
    pFVar7 = GetProcAddress(DAT_18007b818,"GRsetdbProvider");
    (*pFVar7)();
    pFVar7 = GetProcAddress(DAT_18007b818,"GRinqdbProvider");
    IVar8 = (*pFVar7)();
    _DAT_18007b82c = (undefined4)IVar8;
    pFVar7 = GetProcAddress(DAT_18007b818,"GRsetNistHoc");
    (*pFVar7)();
    pFVar7 = GetProcAddress(DAT_18007b818,"GRinqNistHoc");
    IVar8 = (*pFVar7)();
    _DAT_18007b830 = (undefined4)IVar8;
  }
  GetModuleFileNameA((HMODULE)0x0,(LPSTR)(unaff_RBP + 0xc0),0x104);
  pcVar9 = _strlwr((char *)(unaff_RBP + 0xc0));
  pcVar9 = strstr(pcVar9,"aspenplus.exe");
  if (pcVar9 == (char *)0x0) {
    pcVar9 = _strlwr((char *)(unaff_RBP + 0xc0));
    pcVar9 = strstr(pcVar9,"aspenproperties.exe");
    if ((pcVar9 == (char *)0x0) && (DAT_18007b828 == unaff_R15D)) {
      if (DAT_18007b818 == (HMODULE)0x0) goto LAB_18003aa5e;
      pFVar7 = GetProcAddress(DAT_18007b818,"InitializeApedGUIDataDll");
      *(undefined1 *)(unaff_RBP + -0x40) = 0;
      uVar2 = s_apedconnectionerror_log_180056ca0._8_8_;
      pcVar9 = (char *)(unaff_RBP + -0x41);
      do {
        pcVar10 = pcVar9;
        pcVar9 = pcVar10 + 1;
      } while (pcVar10[1] != '\0');
      *(undefined8 *)(pcVar10 + 1) = s_apedconnectionerror_log_180056ca0._0_8_;
      *(undefined8 *)(pcVar10 + 9) = uVar2;
      *(undefined8 *)(pcVar10 + 0x11) = s_apedconnectionerror_log_180056ca0._16_8_;
      (*pFVar7)(unaff_RBP + -0x40);
    }
  }
  if ((DAT_18007b818 != (HMODULE)0x0) &&
     (DAT_18007b7b8 = GetProcAddress(DAT_18007b818,"Get_new_pure_com"),
     DAT_18007b818 != (HMODULE)0x0)) {
    DAT_18007b7c8 = GetProcAddress(DAT_18007b818,"GetDatabaseDatabankName");
  }
LAB_18003aa5e:
  pcVar9 = s_paramdata_180072260;
  lVar15 = unaff_RBP + -0x1800722d8;
  do {
    if ((DAT_18007b818 != (HMODULE)0x0) && (pcVar9[0x40] != '\0')) {
      pFVar7 = GetProcAddress(DAT_18007b818,pcVar9 + 0x40);
      *(FARPROC *)(pcVar9 + 0x28) = pFVar7;
    }
    pcVar10 = pcVar9;
    iVar4 = unaff_R15D;
    uVar14 = 0;
    do {
      do {
        cVar1 = *pcVar10;
        pcVar10[lVar15] = cVar1;
        pcVar10 = pcVar10 + 1;
      } while (cVar1 != '\0');
      if (uVar14 != 0) {
        FUN_180007de0(&stack0x00000078,&DAT_180056ce8,(ulonglong)uVar14,in_R9);
        lVar12 = unaff_RBP + -0x79;
        do {
          pcVar10 = (char *)(lVar12 + 1);
          lVar12 = lVar12 + 1;
        } while (*pcVar10 != '\0');
        lVar13 = 0;
        do {
          cVar1 = (&stack0x00000078)[lVar13];
          *(char *)(lVar12 + lVar13) = cVar1;
          lVar13 = lVar13 + 1;
        } while (cVar1 != '\0');
      }
      unaff_R15D = iVar4;
      uVar3 = uVar14;
      if (pcVar9[0x21] == '\0') break;
      cVar1 = pcVar9[0x20];
      if (cVar1 == '\x01') {
        iVar4 = strcmp(pcVar9,"polyplusenabled");
        if (iVar4 == 0) {
          in_R9 = (ulonglong)uVar14;
          in_stack_00000030 = 1;
          SESetSettingValue(pcVar9,&stack0x00000030,0,uVar14,0);
          break;
        }
        uVar5 = MMGetProfileInt("mmgini",(char *)(unaff_RBP + -0x78),-9999);
        in_stack_00000030 = uVar5;
        if (uVar5 == 0xffffd8f1) break;
        iVar4 = strcmp(pcVar9,"linklimit");
        if ((iVar4 == 0) && (uVar5 == 500)) {
          in_stack_00000030 = 5000;
        }
        in_R9 = (ulonglong)uVar14;
        uVar3 = SESetSettingValue(pcVar9,&stack0x00000030,0,uVar14,0);
        if (uVar3 == 0) {
          unaff_R15D = 0;
        }
      }
      else if (cVar1 == '\x02') {
        pcVar10 = GetProfileStringA("mmgini",(char *)(unaff_RBP + -0x78),(char *)0x0);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&stack0x00000038
                   ,pcVar10);
        if (pcVar10 != (char *)0x0) {
          operator_delete__(pcVar10);
        }
        if (*(int *)(in_stack_00000038 + -0x10) == 0) break;
        in_stack_00000040 = atof(in_stack_00000038);
        in_R9 = (ulonglong)uVar14;
        uVar3 = SESetSettingValue(pcVar9,(uint *)&stack0x00000040,0,uVar14,0);
        unaff_R15D = 0;
        if (uVar3 != 0) {
          unaff_R15D = iVar4;
        }
      }
      else {
        if (cVar1 != '\x03') break;
        pcVar10 = GetProfileStringA("mmgini",(char *)(unaff_RBP + -0x78),(char *)0x0);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&stack0x00000038
                   ,pcVar10);
        if (pcVar10 != (char *)0x0) {
          operator_delete__(pcVar10);
        }
        if (*(int *)(in_stack_00000038 + -0x10) == 0) break;
        puVar11 = (uint *)ATL::CSimpleStringT<char,1>::GetBuffer
                                    ((CSimpleStringT<char,1> *)&stack0x00000038,
                                     *(int *)(in_stack_00000038 + -0x10));
        in_R9 = (ulonglong)uVar14;
        uVar3 = SESetSettingValue(pcVar9,puVar11,0,uVar14,0);
        ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)&stack0x00000038,-1);
        unaff_R15D = 0;
        if (uVar3 != 0) {
          unaff_R15D = iVar4;
        }
      }
      uVar3 = uVar14 + 1;
      bVar16 = uVar14 != uVar3;
      pcVar10 = pcVar9;
      iVar4 = unaff_R15D;
      uVar14 = uVar3;
    } while (bVar16);
    if ((uVar3 == 0) && (unaff_R13 != (FILE *)0x0)) {
      FUN_1800390d0(unaff_R13,pcVar9,1);
    }
    pcVar9 = pcVar9 + 0x60;
    lVar15 = lVar15 + -0x60;
    if (0x1800791bf < (longlong)pcVar9) {
      if (unaff_R13 != (FILE *)0x0) {
        fclose(unaff_R13);
      }
      DAT_18007b7ec = 1;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&stack0x00000038);
      return unaff_R15D;
    }
  } while( true );
}

/* ---- FUNC 0003AD1C FUN_18003ad1c (104 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_18003ad1c(void)

{
  FILE *unaff_R13;
  undefined4 unaff_R15D;
  
  fclose(unaff_R13);
  DAT_18007b7ec = 1;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&stack0x00000038);
  return unaff_R15D;
}

/* ---- FUNC 0003AD84 FUN_18003ad84 (29 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18003ad84(void)

{
  return;
}

/* ---- FUNC 0003ADB0 SEReReadDelFromRegistry (61 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint SEReReadDelFromRegistry(char *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  undefined1 *puVar4;
  longlong lVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined8 uVar9;
  bool bVar10;
  undefined1 auStack_88 [32];
  longlong local_68;
  char local_60 [15];
  undefined1 uStack_51;
  char local_50 [48];
  ulonglong local_20;
  
                    /* 0x3adb0  457  SEReReadDelFromRegistry */
  local_20 = DAT_1800791f8 ^ (ulonglong)auStack_88;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_68);
  pcVar2 = FUN_180039060(param_1);
  uVar8 = 0;
  if (pcVar2 != (char *)0x0) {
    pcVar3 = param_1;
    uVar6 = 0;
    do {
      do {
        cVar1 = *pcVar3;
        pcVar3[(longlong)(local_50 + -(longlong)param_1)] = cVar1;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      if (uVar6 != 0) {
        FUN_180007de0(local_60,&DAT_180056ce8,(ulonglong)uVar6,param_4);
        puVar4 = &uStack_51;
        do {
          pcVar3 = puVar4 + 1;
          puVar4 = puVar4 + 1;
        } while (*pcVar3 != '\0');
        lVar5 = 0;
        do {
          cVar1 = local_60[lVar5];
          puVar4[lVar5] = cVar1;
          lVar5 = lVar5 + 1;
        } while (cVar1 != '\0');
      }
      uVar9 = 0;
      pcVar3 = GetProfileStringA("mmgini",local_50,(char *)0x0);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_68,pcVar3);
      uVar7 = uVar6;
    } while ((*(int *)(local_68 + -0x10) != 0) &&
            (uVar7 = uVar6 + 1, bVar10 = uVar6 != uVar7, pcVar3 = param_1, uVar6 = uVar7, bVar10));
    if (0 < (int)uVar7) {
      do {
        FUN_180038f90(pcVar2,uVar8,uVar9,param_4);
        uVar8 = uVar8 + 1;
      } while ((int)uVar8 < (int)uVar7);
    }
    uVar8 = 1;
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_68);
  return uVar8;
}

/* ---- FUNC 0003ADED FUN_18003aded (10 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18003aded(void)

{
  char cVar1;
  char *pcVar2;
  undefined1 *puVar3;
  longlong lVar4;
  uint uVar5;
  uint uVar6;
  uint unaff_EDI;
  undefined8 uVar7;
  undefined8 in_R9;
  char *unaff_R14;
  char *unaff_R15;
  bool bVar8;
  longlong lStackX_20;
  
  pcVar2 = unaff_R14;
  uVar5 = unaff_EDI;
  do {
    do {
      cVar1 = *pcVar2;
      pcVar2[(longlong)(&stack0x00000038 + -(longlong)unaff_R14)] = cVar1;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    if (uVar5 != 0) {
      FUN_180007de0(&stack0x00000028,&DAT_180056ce8,(ulonglong)uVar5,in_R9);
      puVar3 = &stack0x00000037;
      do {
        pcVar2 = puVar3 + 1;
        puVar3 = puVar3 + 1;
      } while (*pcVar2 != (char)unaff_EDI);
      lVar4 = 0;
      do {
        cVar1 = (&stack0x00000028)[lVar4];
        puVar3[lVar4] = cVar1;
        lVar4 = lVar4 + 1;
      } while (cVar1 != '\0');
    }
    uVar7 = 0;
    pcVar2 = GetProfileStringA("mmgini",&stack0x00000038,(char *)0x0);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&lStackX_20,pcVar2);
    uVar6 = uVar5;
  } while ((*(uint *)(lStackX_20 + -0x10) != unaff_EDI) &&
          (uVar6 = uVar5 + 1, bVar8 = uVar5 != uVar6, pcVar2 = unaff_R14, uVar5 = uVar6, bVar8));
  if (0 < (int)uVar6) {
    do {
      FUN_180038f90(unaff_R15,unaff_EDI,uVar7,in_R9);
      unaff_EDI = unaff_EDI + 1;
    } while ((int)unaff_EDI < (int)uVar6);
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&lStackX_20);
  return 1;
}

/* ---- FUNC 0003ADF7 FUN_18003adf7 (217 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18003adf7(void)

{
  char cVar1;
  char *pcVar2;
  undefined1 *puVar3;
  longlong lVar4;
  uint unaff_EBX;
  uint uVar5;
  uint unaff_EDI;
  undefined8 uVar6;
  undefined8 in_R9;
  char *unaff_R14;
  char *unaff_R15;
  bool bVar7;
  longlong lStackX_20;
  
  pcVar2 = unaff_R14;
  do {
    do {
      cVar1 = *pcVar2;
      pcVar2[(longlong)(&stack0x00000038 + -(longlong)unaff_R14)] = cVar1;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    if (unaff_EBX != 0) {
      FUN_180007de0(&stack0x00000028,&DAT_180056ce8,(ulonglong)unaff_EBX,in_R9);
      puVar3 = &stack0x00000037;
      do {
        pcVar2 = puVar3 + 1;
        puVar3 = puVar3 + 1;
      } while (*pcVar2 != (char)unaff_EDI);
      lVar4 = 0;
      do {
        cVar1 = (&stack0x00000028)[lVar4];
        puVar3[lVar4] = cVar1;
        lVar4 = lVar4 + 1;
      } while (cVar1 != '\0');
    }
    uVar6 = 0;
    pcVar2 = GetProfileStringA("mmgini",&stack0x00000038,(char *)0x0);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&lStackX_20,pcVar2);
    uVar5 = unaff_EBX;
  } while ((*(uint *)(lStackX_20 + -0x10) != unaff_EDI) &&
          (uVar5 = unaff_EBX + 1, bVar7 = unaff_EBX != uVar5, pcVar2 = unaff_R14, unaff_EBX = uVar5,
          bVar7));
  if (0 < (int)uVar5) {
    do {
      FUN_180038f90(unaff_R15,unaff_EDI,uVar6,in_R9);
      unaff_EDI = unaff_EDI + 1;
    } while ((int)unaff_EDI < (int)uVar5);
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&lStackX_20);
  return 1;
}

/* ---- FUNC 0003AED0 FUN_18003aed0 (29 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
FUN_18003aed0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int unaff_EBX;
  uint unaff_EDI;
  char *unaff_R15;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> aCStackX_20 [8];
  
  do {
    FUN_180038f90(unaff_R15,unaff_EDI,param_3,param_4);
    unaff_EDI = unaff_EDI + 1;
  } while ((int)unaff_EDI < unaff_EBX);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(aCStackX_20);
  return 1;
}

/* ---- FUNC 0003AEED FUN_18003aeed (36 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_18003aeed(void)

{
  undefined4 unaff_EDI;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> aCStackX_20 [8];
  
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(aCStackX_20);
  return unaff_EDI;
}

/* ---- FUNC 0003AF20 SEReadConfigBuffer (229 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong SEReadConfigBuffer(longlong param_1,undefined8 param_2,undefined8 param_3,
                            ulonglong param_4)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  undefined1 auStack_438 [32];
  longlong *local_418 [2];
  undefined1 local_408 [1008];
  ulonglong local_18;
  
                    /* 0x3af20  458  SEReadConfigBuffer */
  local_18 = DAT_1800791f8 ^ (ulonglong)auStack_438;
  puVar3 = (undefined8 *)0x0;
  local_418[0] = (longlong *)0x0;
  puVar2 = operator_new(0x118);
  if (puVar2 != (undefined8 *)0x0) {
    param_4 = 0;
    puVar3 = FUN_180018910(puVar2,param_2,0,0);
  }
  iVar1 = (**(code **)*puVar3)(puVar3,&DAT_180057a78,local_418);
  if (iVar1 != 0) {
    param_4 = 0x63b;
    FUN_180007de0(local_408,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\settings.cpp",0x63b);
    LogMessage(local_408,2,1);
  }
  uVar4 = SEReadConfigStream(local_418[0],param_1,1,param_4);
  (**(code **)(*local_418[0] + 0x10))();
  return uVar4 & 0xffffffff;
}

/* ---- FUNC 0003B010 SEReadConfigFile (237 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong SEReadConfigFile(undefined8 param_1,longlong param_2,ulonglong param_3,ulonglong param_4)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  undefined1 auStackY_458 [32];
  longlong *local_428 [2];
  undefined1 local_418 [1008];
  ulonglong local_28;
  
                    /* 0x3b010  459  SEReadConfigFile */
  local_28 = DAT_1800791f8 ^ (ulonglong)auStackY_458;
  puVar3 = (undefined8 *)0x0;
  local_428[0] = (longlong *)0x0;
  puVar2 = operator_new(0x138);
  if (puVar2 != (undefined8 *)0x0) {
    puVar3 = FUN_180018980(puVar2,param_1,0,param_3,0,0);
    param_4 = param_3;
  }
  iVar1 = (**(code **)*puVar3)(puVar3,&DAT_180057a78,local_428);
  if (iVar1 != 0) {
    param_4 = 0x61f;
    FUN_180007de0(local_418,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\settings.cpp",0x61f);
    LogMessage(local_418,2,1);
  }
  uVar4 = SEReadConfigStream(local_428[0],param_2,1,param_4);
  (**(code **)(*local_428[0] + 0x10))();
  return uVar4 & 0xffffffff;
}

/* ---- FUNC 0003B100 SEReadConfigStream (1878 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 SEReadConfigStream(longlong *param_1,longlong param_2,int param_3,ulonglong param_4)

{
  ulonglong uVar1;
  byte *pbVar2;
  ulonglong uVar3;
  char cVar4;
  byte bVar5;
  longlong lVar6;
  bool bVar7;
  bool bVar8;
  char cVar9;
  int iVar10;
  long lVar11;
  ulonglong uVar12;
  char *pcVar13;
  undefined8 uVar14;
  char *pcVar15;
  char *pcVar16;
  char ****ppppcVar17;
  longlong lVar18;
  double *pdVar19;
  uint uVar20;
  ulonglong uVar21;
  char ****ppppcVar22;
  char ****ppppcVar23;
  undefined4 uVar24;
  uint *_Dest;
  uint *puVar25;
  ulonglong uVar26;
  undefined1 auStackY_ae8 [32];
  int local_ab4;
  uint local_ab0;
  uint *local_aa8;
  undefined4 local_aa0;
  int local_a9c;
  long local_a98 [2];
  char *local_a90;
  char *local_a88;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_a80 [8];
  char *local_a78;
  longlong local_a70;
  longlong *local_a68;
  double local_a60;
  char ***local_a58;
  undefined8 uStack_a50;
  ulonglong local_a48;
  ulonglong local_a40;
  char local_a38 [512];
  char local_838 [2048];
  ulonglong local_38;
  
                    /* 0x3b100  460  SEReadConfigStream */
  uVar24 = DAT_18007b7e8;
  local_38 = DAT_1800791f8 ^ (ulonglong)auStackY_ae8;
  local_ab0 = 0;
  bVar7 = false;
  local_a38[0] = '#';
  local_a38[1] = '\0';
  local_aa0 = DAT_18007b7e8;
  DAT_18007b7e8 = 2;
  bVar8 = false;
  local_a9c = param_3;
  local_a70 = param_2;
  local_a68 = param_1;
  uVar12 = FUN_18001b180(param_1,(longlong)local_838);
  if ((int)uVar12 == 0) {
    while (local_838[0] != '\0') {
      pcVar13 = strchr(local_838,10);
      if (pcVar13 != (char *)0x0) {
        *pcVar13 = '\0';
      }
      if ((local_838[0] == '\0') || (local_838[0] == '#')) break;
      local_a88 = local_838;
      pcVar13 = strchr(local_838,0x20);
      if (pcVar13 != (char *)0x0) {
        *pcVar13 = '\0';
        local_aa8 = (uint *)(pcVar13 + 1);
        pcVar13 = local_838;
        lVar6 = -(longlong)pcVar13;
        do {
          cVar9 = *pcVar13;
          cVar4 = pcVar13[(longlong)(local_a38 + lVar6)];
          if (cVar9 != cVar4) break;
          pcVar13 = pcVar13 + 1;
        } while (cVar4 != '\0');
        if (cVar9 != cVar4) {
          local_ab0 = 0;
          lVar18 = 0;
          do {
            pcVar13 = local_838 + lVar18;
            local_a38[lVar18] = *pcVar13;
            lVar18 = lVar18 + 1;
          } while (*pcVar13 != '\0');
        }
        uVar14 = FUN_1800396b0((longlong *)&local_a88,(longlong *)&local_aa8,local_a38 + lVar6,
                               param_4);
        pcVar13 = local_a88;
        if ((int)uVar14 != -0x7fffbffb) {
          pcVar15 = FUN_180039060(local_a88);
          local_a78 = pcVar15;
          if (pcVar15 == (char *)0x0) {
            FUN_180039340(pcVar13,(char *)local_aa8);
          }
          else {
            iVar10 = strcmp(pcVar13,"customglobaldatapropset1");
            if (iVar10 == 0) {
              uVar20 = 1;
              do {
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_a90);
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_a90,"customglobaldatapropset%d",(ulonglong)uVar20);
                pcVar16 = (char *)SEGetSettingValue(local_a90,0);
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_a80,pcVar16);
                cVar9 = ATL::CSimpleStringT<char,1>::operator[]
                                  ((CSimpleStringT<char,1> *)local_a80,0);
                if (cVar9 != '0') {
                  bVar8 = true;
                  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_a80);
                  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &local_a90);
                  bVar7 = true;
                  break;
                }
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_a80);
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_a90);
                uVar20 = uVar20 + 1;
                bVar7 = bVar8;
              } while ((int)uVar20 < 7);
            }
            iVar10 = strcmp(pcVar13,"streamprefix");
            if ((iVar10 == 0) ||
               (iVar10 = strcmp(pcVar13,"blockprefix"), _Dest = local_aa8, iVar10 == 0)) {
              local_a48 = 0;
              uStack_a50 = 0;
              local_a58 = (char ***)0x0;
              local_a40 = 0xf;
              local_ab4 = 0;
              _Dest = local_aa8;
              puVar25 = local_aa8;
              do {
                if (((char)(byte)*puVar25 < -1) ||
                   (iVar10 = isalnum((int)(char)(byte)*puVar25), uVar26 = local_a40,
                   uVar12 = local_a48, iVar10 == 0)) {
                  uVar26 = local_a40;
                  uVar12 = local_a48;
                  bVar5 = (byte)*puVar25;
                  if ((bVar5 < 0x3b) &&
                     ((0x400381000000000U >> ((longlong)(char)bVar5 & 0x3fU) & 1) != 0)) {
                    if (local_a48 < local_a40) {
                      ppppcVar17 = &local_a58;
                      if (0xf < local_a40) {
                        ppppcVar17 = (char ****)local_a58;
                      }
                      pbVar2 = (byte *)((longlong)ppppcVar17 + local_a48);
                      local_a48 = local_a48 + 1;
                      *pbVar2 = bVar5;
                      *(char *)((longlong)ppppcVar17 + uVar12 + 1) = '\0';
                    }
                    else {
                      if (local_a48 == 0x7fffffffffffffff) goto LAB_18003b851;
                      uVar1 = local_a48 + 1;
                      uVar21 = uVar1 | 0xf;
                      if (uVar21 < 0x8000000000000000) {
                        if (0x7fffffffffffffff - (local_a40 >> 1) < local_a40) {
                          uVar21 = 0x7fffffffffffffff;
                          ppppcVar17 = (char ****)FUN_180007f10(0x8000000000000000);
                        }
                        else {
                          uVar3 = local_a40 + (local_a40 >> 1);
                          if (uVar21 < uVar3) {
                            uVar21 = uVar3;
                          }
                          uVar3 = uVar21 + 1;
                          if (uVar3 < 0x1000) {
                            if (uVar3 == 0) {
                              ppppcVar17 = (char ****)0x0;
                            }
                            else {
                              ppppcVar17 = operator_new(uVar3);
                            }
                          }
                          else {
                            ppppcVar17 = (char ****)FUN_180007f10(uVar3);
                          }
                        }
                      }
                      else {
                        uVar21 = 0x7fffffffffffffff;
                        ppppcVar17 = (char ****)FUN_180007f10(0x8000000000000000);
                      }
                      ppppcVar22 = (char ****)local_a58;
                      local_a48 = uVar1;
                      local_a40 = uVar21;
                      if (0xf < uVar26) {
                        memcpy(ppppcVar17,local_a58,uVar12);
                        *(byte *)((longlong)ppppcVar17 + uVar12) = bVar5;
                        *(char *)((longlong)ppppcVar17 + uVar12 + 1) = '\0';
                        goto LAB_18003b497;
                      }
                      memcpy(ppppcVar17,&local_a58,uVar12);
                      *(byte *)((longlong)ppppcVar17 + uVar12) = bVar5;
                      *(char *)((longlong)ppppcVar17 + uVar12 + 1) = '\0';
                      _Dest = local_aa8;
                      local_a58 = (char ***)ppppcVar17;
                    }
                  }
                }
                else {
                  bVar5 = (byte)*puVar25;
                  if (local_a48 < local_a40) {
                    ppppcVar17 = &local_a58;
                    if (0xf < local_a40) {
                      ppppcVar17 = (char ****)local_a58;
                    }
                    pbVar2 = (byte *)((longlong)ppppcVar17 + local_a48);
                    local_a48 = local_a48 + 1;
                    *pbVar2 = bVar5;
                    *(char *)((longlong)ppppcVar17 + uVar12 + 1) = '\0';
                  }
                  else {
                    if (local_a48 == 0x7fffffffffffffff) {
LAB_18003b851:
                    /* WARNING: Subroutine does not return */
                      FUN_18000ace0();
                    }
                    uVar1 = local_a48 + 1;
                    uVar21 = uVar1 | 0xf;
                    if (uVar21 < 0x8000000000000000) {
                      if (0x7fffffffffffffff - (local_a40 >> 1) < local_a40) {
                        uVar21 = 0x7fffffffffffffff;
                        ppppcVar17 = (char ****)FUN_180007f10(0x8000000000000000);
                      }
                      else {
                        uVar3 = local_a40 + (local_a40 >> 1);
                        if (uVar21 < uVar3) {
                          uVar21 = uVar3;
                        }
                        uVar3 = uVar21 + 1;
                        if (uVar3 < 0x1000) {
                          if (uVar3 == 0) {
                            ppppcVar17 = (char ****)0x0;
                          }
                          else {
                            ppppcVar17 = operator_new(uVar3);
                          }
                        }
                        else {
                          ppppcVar17 = (char ****)FUN_180007f10(uVar3);
                        }
                      }
                    }
                    else {
                      uVar21 = 0x7fffffffffffffff;
                      ppppcVar17 = (char ****)FUN_180007f10(0x8000000000000000);
                    }
                    ppppcVar22 = (char ****)local_a58;
                    local_a48 = uVar1;
                    local_a40 = uVar21;
                    if (uVar26 < 0x10) {
                      memcpy(ppppcVar17,&local_a58,uVar12);
                      *(byte *)((longlong)ppppcVar17 + uVar12) = bVar5;
                      *(char *)((longlong)ppppcVar17 + uVar12 + 1) = '\0';
                      _Dest = local_aa8;
                      local_a58 = (char ***)ppppcVar17;
                    }
                    else {
                      memcpy(ppppcVar17,local_a58,uVar12);
                      *(byte *)((longlong)ppppcVar17 + uVar12) = bVar5;
                      *(char *)((longlong)ppppcVar17 + uVar12 + 1) = '\0';
LAB_18003b497:
                      ppppcVar23 = ppppcVar22;
                      if ((0xfff < uVar26 + 1) &&
                         (ppppcVar23 = (char ****)ppppcVar22[-1],
                         (char *)0x1f < (char *)((longlong)ppppcVar22 + (-8 - (longlong)ppppcVar23))
                         )) goto LAB_18003b84a;
                      operator_delete(ppppcVar23);
                      _Dest = local_aa8;
                      local_a58 = (char ***)ppppcVar17;
                    }
                  }
                }
                local_ab4 = local_ab4 + 1;
                uVar12 = 0xffffffffffffffff;
                puVar25 = (uint *)((longlong)puVar25 + 1);
                do {
                  uVar12 = uVar12 + 1;
                } while (*(byte *)((longlong)_Dest + uVar12) != 0);
              } while ((ulonglong)(longlong)local_ab4 <= uVar12);
              FUN_18001b6b0(&local_a58,0);
              ppppcVar17 = &local_a58;
              if (0xf < local_a40) {
                ppppcVar17 = (char ****)local_a58;
              }
              strncpy((char *)_Dest,(char *)ppppcVar17,local_a48);
              pcVar13 = local_a88;
              param_1 = local_a68;
              pcVar15 = local_a78;
              param_2 = local_a70;
              param_3 = local_a9c;
              bVar7 = bVar8;
              if (0xf < local_a40) {
                ppppcVar17 = (char ****)local_a58;
                if ((0xfff < local_a40 + 1) &&
                   (ppppcVar17 = (char ****)local_a58[-1],
                   (char *)0x1f < (char *)((longlong)local_a58 + (-8 - (longlong)ppppcVar17)))) {
LAB_18003b84a:
                    /* WARNING: Subroutine does not return */
                  _invalid_parameter_noinfo_noreturn();
                }
                operator_delete(ppppcVar17);
                pcVar13 = local_a88;
                param_1 = local_a68;
                pcVar15 = local_a78;
                param_2 = local_a70;
                param_3 = local_a9c;
              }
            }
            if (((!bVar7) || (iVar10 = strncmp(pcVar13,"customglobaldatapropset",0x17), iVar10 != 0)
                ) || ((char)*_Dest != '0')) {
              uVar20 = 0;
              if (param_3 == 0) {
                uVar20 = (uint)(pcVar15[0x30] == '\0');
              }
              cVar9 = pcVar15[0x20];
              if (cVar9 == '\x01') {
                lVar11 = atol((char *)_Dest);
                local_a98[0] = lVar11;
                iVar10 = strcmp(pcVar13,"linklimit");
                if (iVar10 == 0) {
                  if (lVar11 == 500) {
                    local_a98[0] = 5000;
                  }
                }
                else {
                  iVar10 = strcmp(pcVar13,"tpsaupgrade");
                  bVar7 = bVar8;
                  if (iVar10 == 0) goto LAB_18003b7d1;
                }
                pdVar19 = (double *)local_a98;
              }
              else {
                if (cVar9 != '\x02') {
                  bVar7 = bVar8;
                  if (cVar9 == '\x03') {
                    param_4 = (ulonglong)local_ab0;
                    SESetSettingValue(pcVar13,_Dest,uVar20,local_ab0,param_2);
                    local_ab0 = local_ab0 + 1;
                  }
                  goto LAB_18003b7d1;
                }
                local_a60 = atof((char *)_Dest);
                pdVar19 = &local_a60;
              }
              param_4 = (ulonglong)local_ab0;
              SESetSettingValue(pcVar13,(uint *)pdVar19,uVar20,local_ab0,param_2);
              local_ab0 = local_ab0 + 1;
              bVar7 = bVar8;
            }
          }
        }
      }
LAB_18003b7d1:
      uVar12 = FUN_18001b180(param_1,(longlong)local_838);
      if ((int)uVar12 != 0) break;
    }
    uVar24 = local_aa0;
    if ((bVar7) &&
       (_DAT_18007b7d0 = GetProcAddress(DAT_18007b820,"SMSetGlobalPropset"), uVar24 = local_aa0,
       _DAT_18007b7d0 != (FARPROC)0x0)) {
      (*_DAT_18007b7d0)();
      uVar24 = local_aa0;
    }
  }
  DAT_18007b7e8 = uVar24;
  return 0;
}

/* ---- FUNC 0003B860 SERestoreSettingsBinary (69 bytes) ---- */

void SERestoreSettingsBinary(undefined8 param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  INT_PTR IVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  int *piVar10;
  undefined8 *puVar11;
  longlong lVar12;
  int *local_48;
  int local_40;
  int local_3c;
  undefined8 local_38;
  
                    /* 0x3b860  461  SERestoreSettingsBinary */
  if ((DAT_18007b818 != (HMODULE)0x0) &&
     ((DAT_18007b808 != (FARPROC)0x0 ||
      (DAT_18007b808 = GetProcAddress(DAT_18007b818,"deref_ptr"), DAT_18007b808 != (FARPROC)0x0))))
  {
    piVar4 = (int *)(*DAT_18007b808)(param_1);
    iVar2 = *piVar4;
    if (0 < (longlong)iVar2) {
      puVar11 = &DAT_180072298;
      lVar12 = 0;
      piVar6 = piVar4;
      do {
        if (*(char *)(puVar11 + -1) != '\0') {
          IVar5 = (*DAT_18007b808)(*(undefined8 *)(piVar4 + lVar12 * 2 + 1));
          piVar8 = (int *)*puVar11;
          if (*(char *)(IVar5 + 0x31) != '\0') {
            piVar6 = (int *)(*DAT_18007b808)(*(undefined8 *)(IVar5 + 0x38));
          }
          piVar7 = (int *)0x0;
          iVar9 = 0;
          *(undefined1 *)((longlong)puVar11 + -7) = *(undefined1 *)(IVar5 + 0x31);
          piVar10 = piVar7;
          if ('\0' < *(char *)(IVar5 + 0x31)) {
            do {
              piVar7 = piVar8;
              if (piVar8 == (int *)0x0) {
                piVar7 = malloc(0x108);
                memset(piVar7,0,0x108);
                if (iVar9 == 0) {
                  *puVar11 = piVar7;
                }
                else if (piVar10 != (int *)0x0) {
                  *(int **)(piVar10 + 0x40) = piVar7;
                }
              }
              cVar1 = *(char *)(puVar11 + -3);
              if (cVar1 == '\x01') {
                *piVar7 = *piVar6;
              }
              else if (cVar1 == '\x02') {
                *(undefined8 *)piVar7 = *(undefined8 *)piVar6;
              }
              else if (cVar1 == '\x03') {
                piVar8 = piVar6;
                do {
                  iVar3 = *piVar8;
                  *(char *)(((longlong)piVar7 - (longlong)piVar6) + (longlong)piVar8) = (char)iVar3;
                  piVar8 = (int *)((longlong)piVar8 + 1);
                } while ((char)iVar3 != '\0');
              }
              if ((code *)puVar11[-2] != (code *)0x0) {
                local_3c = (int)*(char *)(puVar11 + -3);
                local_38 = 3;
                local_48 = piVar7;
                local_40 = iVar9;
                (*(code *)puVar11[-2])(&local_48);
              }
              piVar8 = *(int **)(piVar7 + 0x40);
              piVar6 = (int *)(*DAT_18007b808)(*(undefined8 *)(piVar6 + 0x40));
              iVar9 = iVar9 + 1;
              piVar10 = piVar7;
            } while (iVar9 < *(char *)(IVar5 + 0x31));
          }
          if (piVar8 != (int *)0x0) {
            if (piVar7 != (int *)0x0) {
              piVar7[0x40] = 0;
              piVar7[0x41] = 0;
            }
            do {
              piVar7 = *(int **)(piVar8 + 0x40);
              free(piVar8);
              piVar8 = piVar7;
            } while (piVar7 != (int *)0x0);
          }
        }
        lVar12 = lVar12 + 1;
        puVar11 = puVar11 + 0xc;
      } while (lVar12 < iVar2);
    }
  }
  return;
}

/* ---- FUNC 0003B8A5 FUN_18003b8a5 (24 bytes) ---- */

void FUN_18003b8a5(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  code *in_RAX;
  int *piVar4;
  longlong lVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  int *piVar10;
  undefined8 *puVar11;
  longlong lVar12;
  int *piStackX_20;
  
  piVar4 = (int *)(*in_RAX)();
  iVar2 = *piVar4;
  if (0 < (longlong)iVar2) {
    puVar11 = &DAT_180072298;
    lVar12 = 0;
    piVar6 = piVar4;
    do {
      if (*(char *)(puVar11 + -1) != '\0') {
        lVar5 = (*DAT_18007b808)(*(undefined8 *)(piVar4 + lVar12 * 2 + 1));
        piVar8 = (int *)*puVar11;
        if (*(char *)(lVar5 + 0x31) != '\0') {
          piVar6 = (int *)(*DAT_18007b808)(*(undefined8 *)(lVar5 + 0x38));
        }
        piVar7 = (int *)0x0;
        iVar9 = 0;
        *(undefined1 *)((longlong)puVar11 + -7) = *(undefined1 *)(lVar5 + 0x31);
        piVar10 = piVar7;
        if ('\0' < *(char *)(lVar5 + 0x31)) {
          do {
            piVar7 = piVar8;
            if (piVar8 == (int *)0x0) {
              piVar7 = malloc(0x108);
              memset(piVar7,0,0x108);
              if (iVar9 == 0) {
                *puVar11 = piVar7;
              }
              else if (piVar10 != (int *)0x0) {
                *(int **)(piVar10 + 0x40) = piVar7;
              }
            }
            cVar1 = *(char *)(puVar11 + -3);
            if (cVar1 == '\x01') {
              *piVar7 = *piVar6;
            }
            else if (cVar1 == '\x02') {
              *(undefined8 *)piVar7 = *(undefined8 *)piVar6;
            }
            else if (cVar1 == '\x03') {
              piVar8 = piVar6;
              do {
                iVar3 = *piVar8;
                *(char *)(((longlong)piVar7 - (longlong)piVar6) + (longlong)piVar8) = (char)iVar3;
                piVar8 = (int *)((longlong)piVar8 + 1);
              } while ((char)iVar3 != '\0');
            }
            if ((code *)puVar11[-2] != (code *)0x0) {
              piStackX_20 = piVar7;
              (*(code *)puVar11[-2])(&piStackX_20);
            }
            piVar8 = *(int **)(piVar7 + 0x40);
            piVar6 = (int *)(*DAT_18007b808)(*(undefined8 *)(piVar6 + 0x40));
            iVar9 = iVar9 + 1;
            piVar10 = piVar7;
          } while (iVar9 < *(char *)(lVar5 + 0x31));
        }
        if (piVar8 != (int *)0x0) {
          if (piVar7 != (int *)0x0) {
            piVar7[0x40] = 0;
            piVar7[0x41] = 0;
          }
          do {
            piVar7 = *(int **)(piVar8 + 0x40);
            free(piVar8);
            piVar8 = piVar7;
          } while (piVar7 != (int *)0x0);
        }
      }
      lVar12 = lVar12 + 1;
      puVar11 = puVar11 + 0xc;
    } while (lVar12 < iVar2);
  }
  return;
}

/* ---- FUNC 0003B8BD FUN_18003b8bd (433 bytes) ---- */

void FUN_18003b8bd(void)

{
  char cVar1;
  char *in_RAX;
  longlong lVar2;
  char *pcVar3;
  undefined8 *puVar4;
  char *pcVar5;
  undefined8 *_Memory;
  int iVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  longlong lVar9;
  longlong unaff_R13;
  undefined8 *puStackX_20;
  char *in_stack_00000078;
  
  puVar8 = &DAT_180072298;
  lVar9 = 0;
  pcVar3 = in_stack_00000078;
  do {
    if (*(char *)(puVar8 + -1) != '\0') {
      lVar2 = (*DAT_18007b808)(*(undefined8 *)(in_RAX + lVar9 * 8 + 4));
      _Memory = (undefined8 *)*puVar8;
      if (*(char *)(lVar2 + 0x31) != '\0') {
        pcVar3 = (char *)(*DAT_18007b808)(*(undefined8 *)(lVar2 + 0x38));
      }
      puVar4 = (undefined8 *)0x0;
      iVar6 = 0;
      *(undefined1 *)((longlong)puVar8 + -7) = *(undefined1 *)(lVar2 + 0x31);
      puVar7 = puVar4;
      if ('\0' < *(char *)(lVar2 + 0x31)) {
        do {
          puVar4 = _Memory;
          if (_Memory == (undefined8 *)0x0) {
            puVar4 = malloc(0x108);
            memset(puVar4,0,0x108);
            if (iVar6 == 0) {
              *puVar8 = puVar4;
            }
            else if (puVar7 != (undefined8 *)0x0) {
              puVar7[0x20] = puVar4;
            }
          }
          cVar1 = *(char *)(puVar8 + -3);
          if (cVar1 == '\x01') {
            *(undefined4 *)puVar4 = *(undefined4 *)pcVar3;
          }
          else if (cVar1 == '\x02') {
            *puVar4 = *(undefined8 *)pcVar3;
          }
          else if (cVar1 == '\x03') {
            pcVar5 = pcVar3;
            do {
              cVar1 = *pcVar5;
              pcVar5[(longlong)puVar4 - (longlong)pcVar3] = cVar1;
              pcVar5 = pcVar5 + 1;
            } while (cVar1 != '\0');
          }
          if ((code *)puVar8[-2] != (code *)0x0) {
            puStackX_20 = puVar4;
            (*(code *)puVar8[-2])(&puStackX_20);
          }
          _Memory = (undefined8 *)puVar4[0x20];
          pcVar3 = (char *)(*DAT_18007b808)(*(undefined8 *)(pcVar3 + 0x100));
          iVar6 = iVar6 + 1;
          puVar7 = puVar4;
        } while (iVar6 < *(char *)(lVar2 + 0x31));
      }
      in_RAX = in_stack_00000078;
      if (_Memory != (undefined8 *)0x0) {
        if (puVar4 != (undefined8 *)0x0) {
          puVar4[0x20] = 0;
        }
        do {
          puVar4 = (undefined8 *)_Memory[0x20];
          free(_Memory);
          _Memory = puVar4;
        } while (puVar4 != (undefined8 *)0x0);
      }
    }
    lVar9 = lVar9 + 1;
    puVar8 = puVar8 + 0xc;
  } while (lVar9 < unaff_R13);
  return;
}

/* ---- FUNC 0003BA6E FUN_18003ba6e (5 bytes) ---- */

void FUN_18003ba6e(void)

{
  return;
}

/* ---- FUNC 0003BA73 FUN_18003ba73 (6 bytes) ---- */

void FUN_18003ba73(void)

{
  return;
}

/* ---- FUNC 0003BA80 SESetSettingResetValue (58 bytes) ---- */

undefined8
SESetSettingResetValue(char *param_1,undefined8 *param_2,int param_3,int param_4,longlong param_5)

{
  char *pcVar1;
  uint uVar2;
  uint uVar3;
  
                    /* 0x3ba80  462  SESetSettingResetValue */
  pcVar1 = FUN_180039060(param_1);
  if (pcVar1 != (char *)0x0) {
    uVar2 = 0;
    uVar3 = 0;
    if ('\0' < pcVar1[0x31]) {
      do {
        SEDelSettingValue(param_1,param_4,(ulonglong)uVar3,param_5);
        uVar3 = uVar3 + 1;
      } while ((int)uVar3 < (int)pcVar1[0x31]);
    }
    if (0 < param_3) {
      do {
        SESetSettingValue(param_1,(uint *)*param_2,param_4,uVar2,param_5);
        uVar2 = uVar2 + 1;
        param_2 = param_2 + 1;
      } while ((int)uVar2 < param_3);
    }
    return 1;
  }
  return 0;
}

/* ---- FUNC 0003BABA FUN_18003baba (70 bytes) ---- */

undefined8 FUN_18003baba(void)

{
  longlong in_RAX;
  uint unaff_EBX;
  char *unaff_RBP;
  uint uVar1;
  undefined8 *unaff_RDI;
  longlong unaff_R12;
  int unaff_R13D;
  int unaff_R15D;
  longlong in_stack_00000080;
  
  uVar1 = unaff_EBX;
  if ((char)unaff_EBX < *(char *)(in_RAX + 0x31)) {
    do {
      SEDelSettingValue(unaff_RBP,unaff_R15D,(ulonglong)uVar1,in_stack_00000080);
      uVar1 = uVar1 + 1;
    } while ((int)uVar1 < (int)*(char *)(unaff_R12 + 0x31));
  }
  if (0 < unaff_R13D) {
    do {
      SESetSettingValue(unaff_RBP,(uint *)*unaff_RDI,unaff_R15D,unaff_EBX,in_stack_00000080);
      unaff_EBX = unaff_EBX + 1;
      unaff_RDI = unaff_RDI + 1;
    } while ((int)unaff_EBX < unaff_R13D);
  }
  return 1;
}

/* ---- FUNC 0003BB00 FUN_18003bb00 (61 bytes) ---- */

undefined8 FUN_18003bb00(void)

{
  uint unaff_EBX;
  char *unaff_RBP;
  undefined8 *unaff_RDI;
  int unaff_R13D;
  longlong unaff_R14;
  int unaff_R15D;
  
  do {
    SESetSettingValue(unaff_RBP,(uint *)*unaff_RDI,unaff_R15D,unaff_EBX,unaff_R14);
    unaff_EBX = unaff_EBX + 1;
    unaff_RDI = unaff_RDI + 1;
  } while ((int)unaff_EBX < unaff_R13D);
  return 1;
}

/* ---- FUNC 0003BB40 SESetSettingValue (1051 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint SESetSettingValue(char *param_1,uint *param_2,int param_3,uint param_4,longlong param_5)

{
  char cVar1;
  uint uVar2;
  undefined8 uVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  ulonglong uVar7;
  uint *_Dest;
  char *pcVar8;
  char *pcVar9;
  longlong lVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  uint *puVar13;
  undefined1 auStack_3e8 [32];
  int local_3c8;
  char *local_3c0;
  undefined8 local_3b8;
  char local_3b0;
  uint *local_398;
  uint local_390;
  int local_38c;
  undefined4 local_388;
  undefined4 local_384;
  char local_380 [40];
  undefined1 local_358 [784];
  ulonglong local_48;
  
                    /* 0x3bb40  463  SESetSettingValue */
  local_48 = DAT_1800791f8 ^ (ulonglong)auStack_3e8;
  local_3c8 = param_3;
  local_3c0 = param_1;
  pcVar6 = FUN_180039060(param_1);
  if (pcVar6 == (char *)0x0) {
LAB_18003bc84:
    uVar5 = 0;
  }
  else {
    _Dest = *(uint **)(pcVar6 + 0x38);
    puVar13 = (uint *)(pcVar6 + 0x38);
    iVar4 = (int)pcVar6[0x31];
    uVar12 = 0;
    if ((int)param_4 < iVar4) {
      if (0 < (int)param_4) {
        uVar7 = (ulonglong)param_4;
        do {
          _Dest = *(uint **)(_Dest + 0x40);
          uVar7 = uVar7 - 1;
        } while (uVar7 != 0);
      }
    }
    else {
      if ('\0' < pcVar6[0x31]) {
        uVar7 = (ulonglong)(iVar4 - 1U);
        if (0 < (int)(iVar4 - 1U)) {
          do {
            _Dest = *(uint **)(_Dest + 0x40);
            uVar7 = uVar7 - 1;
          } while (uVar7 != 0);
        }
        puVar13 = _Dest + 0x40;
      }
      uVar7 = uVar12;
      if (0 < (int)((param_4 - iVar4) + 1)) {
        do {
          _Dest = malloc(0x108);
          memset(_Dest,0,0x108);
          *(uint **)puVar13 = _Dest;
          puVar13 = _Dest + 0x40;
          uVar5 = (int)uVar7 + 1;
          uVar7 = (ulonglong)uVar5;
        } while ((int)uVar5 < (int)((param_4 - (int)pcVar6[0x31]) + 1));
      }
      pcVar6[0x31] = (char)param_4 + '\x01';
      param_1 = local_3c0;
    }
    if (*(code **)(pcVar6 + 0x28) == (code *)0x0) {
      uVar5 = 1;
    }
    else {
      local_38c = (int)pcVar6[0x20];
      local_388 = DAT_18007b7e8;
      local_384 = 0;
      local_398 = param_2;
      local_390 = param_4;
      uVar5 = (**(code **)(pcVar6 + 0x28))(&local_398);
      if (uVar5 == 0) goto LAB_18003bc84;
    }
    cVar1 = pcVar6[0x20];
    if (cVar1 == '\x01') {
      *_Dest = *param_2;
    }
    else if (cVar1 == '\x02') {
      *(undefined8 *)_Dest = *(undefined8 *)param_2;
    }
    else if (cVar1 == '\x03') {
      iVar4 = _stricmp(param_1,"purebank");
      if ((iVar4 == 0) || (iVar4 = _stricmp(param_1,"paramdata"), iVar4 == 0)) {
        iVar4 = _stricmp((char *)param_2,"PURECOMP");
        if (iVar4 == 0) {
          if ((DAT_18007b7b8 == (code *)0x0) ||
             (iVar4 = (*DAT_18007b7b8)(), uVar3 = local_3b8, iVar4 == 0)) {
            uVar3 = local_3b8;
            local_3b8._4_1_ = (undefined1)DAT_180056d60;
            local_3b8._5_1_ = DAT_180056d60._1_1_;
            local_3b8._0_1_ = (undefined1)DAT_180056d5c;
            local_3b8._1_1_ = DAT_180056d5c._1_1_;
            local_3b8._2_1_ = DAT_180056d5c._2_1_;
            local_3b8._3_1_ = DAT_180056d5c._3_1_;
            local_3b8._7_1_ = SUB81(uVar3,7);
            local_3b8._6_1_ = DAT_180056d62;
          }
          else {
            local_3b8._4_1_ = (undefined1)DAT_180056d58;
            local_3b8._5_1_ = DAT_180056d58._1_1_;
            local_3b8._0_1_ = (undefined1)DAT_180056d54;
            local_3b8._1_1_ = DAT_180056d54._1_1_;
            local_3b8._2_1_ = DAT_180056d54._2_1_;
            local_3b8._3_1_ = DAT_180056d54._3_1_;
            local_3b8._7_1_ = SUB81(uVar3,7);
            local_3b8._6_1_ = DAT_180056d5a;
          }
        }
        else {
          lVar10 = (longlong)&local_3b8 - (longlong)param_2;
          do {
            uVar2 = *param_2;
            *(char *)(lVar10 + (longlong)param_2) = (char)uVar2;
            param_2 = (uint *)((longlong)param_2 + 1);
          } while ((char)uVar2 != '\0');
        }
        if (DAT_18007b828 == 0) {
          pcVar9 = strchr((char *)&local_3b8,0x20);
          if (pcVar9 != (char *)0x0) {
            pcVar8 = pcVar9 + 1;
            lVar10 = (longlong)&local_398 - (longlong)pcVar8;
            do {
              cVar1 = *pcVar8;
              pcVar8[lVar10] = cVar1;
              pcVar8 = pcVar8 + 1;
            } while (cVar1 != '\0');
            *pcVar9 = '\0';
            iVar4 = strcmp("HENRY-AP",(char *)&local_398);
            if (iVar4 == 0) {
              local_3b8._4_1_ = (undefined1)DAT_180056d68;
              local_3b8._5_1_ = DAT_180056d68._1_1_;
              local_3b8._0_1_ = (undefined1)DAT_180056d64;
              local_3b8._1_1_ = DAT_180056d64._1_1_;
              local_3b8._2_1_ = DAT_180056d64._2_1_;
              local_3b8._3_1_ = DAT_180056d64._3_1_;
            }
            else {
              do {
                pcVar9 = (char *)((longlong)&local_398 + uVar12);
                *(char *)((longlong)&local_3b8 + uVar12) = *pcVar9;
                uVar12 = uVar12 + 1;
              } while (*pcVar9 != '\0');
            }
          }
          pcVar9 = (char *)&local_3b8;
        }
        else {
          pcVar8 = strchr((char *)&local_3b8,0x20);
          pcVar9 = (char *)&local_3b8;
          uVar7 = uVar12;
          if (pcVar8 == (char *)0x0) {
            do {
              uVar11 = uVar7 + 1;
              if (pcVar9[uVar7] != *(char *)((longlong)&DAT_180056d64 + uVar7)) goto LAB_18003bdfd;
              uVar7 = uVar11;
            } while (uVar11 != 6);
            local_3b0 = s_HENRY_AP_180056d70[8];
            local_3b8._0_1_ = s_HENRY_AP_180056d70[0];
            local_3b8._1_1_ = s_HENRY_AP_180056d70[1];
            local_3b8._2_1_ = s_HENRY_AP_180056d70[2];
            local_3b8._3_1_ = s_HENRY_AP_180056d70[3];
            local_3b8._4_1_ = s_HENRY_AP_180056d70[4];
            local_3b8._5_1_ = s_HENRY_AP_180056d70[5];
            local_3b8._6_1_ = s_HENRY_AP_180056d70[6];
            local_3b8._7_1_ = s_HENRY_AP_180056d70[7];
LAB_18003bdfd:
            iVar4 = (*DAT_18007b7c8)(&local_3b8,local_380);
            if (iVar4 == 0) {
              do {
                pcVar9 = (char *)((longlong)&local_3b8 + uVar12);
                local_380[uVar12] = *pcVar9;
                uVar12 = uVar12 + 1;
              } while (*pcVar9 != '\0');
            }
            pcVar9 = local_380;
          }
        }
        strncpy((char *)_Dest,pcVar9,0xff);
        *(undefined1 *)((longlong)_Dest + 0xff) = 0;
      }
      else {
        strncpy((char *)_Dest,(char *)param_2,0xff);
        *(undefined1 *)((longlong)_Dest + 0xff) = 0;
      }
    }
    if (local_3c8 != 0) {
      uVar5 = FUN_180039580(pcVar6,(int *)_Dest,param_4);
    }
    if ((param_5 != 0) && (param_4 == 0)) {
      cVar1 = pcVar6[0x20];
      if (cVar1 == '\x01') {
        FUN_180007de0(local_358,"%s %ld\n",pcVar6,(ulonglong)*_Dest);
      }
      else if (cVar1 == '\x02') {
        FUN_180007de0(local_358,"%s %f\n",pcVar6,*(undefined8 *)_Dest);
      }
      else if (cVar1 == '\x03') {
        FUN_180007de0(local_358,"%s %s\n",pcVar6,_Dest);
      }
      PostMainWndMessage(0x4f5,0,local_358);
    }
  }
  return uVar5;
}

/* ---- FUNC 0003BF60 SEStoreSettingsBinary (114 bytes) ---- */

INT_PTR SEStoreSettingsBinary(void)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  INT_PTR IVar7;
  undefined4 *puVar8;
  INT_PTR IVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  undefined8 *puVar12;
  int iVar13;
  undefined8 *puVar14;
  char *pcVar15;
  longlong lVar16;
  INT_PTR *pIVar17;
  undefined8 *local_res8;
  
                    /* 0x3bf60  464  SEStoreSettingsBinary */
  if (((DAT_18007b818 != (HMODULE)0x0) &&
      ((DAT_18007b800 != (FARPROC)0x0 ||
       (DAT_18007b800 = GetProcAddress(DAT_18007b818,"malloc3"), DAT_18007b800 != (FARPROC)0x0))))
     && ((DAT_18007b808 != (FARPROC)0x0 ||
         (DAT_18007b808 = GetProcAddress(DAT_18007b818,"deref_ptr"), DAT_18007b808 != (FARPROC)0x0))
        )) {
    IVar7 = (*DAT_18007b800)(0x94c);
    puVar8 = (undefined4 *)(*DAT_18007b808)(IVar7);
    memset(puVar8 + 1,0,0x948);
    pIVar17 = (INT_PTR *)(puVar8 + 1);
    *puVar8 = 0x129;
    pcVar15 = &DAT_180072291;
    do {
      if (pcVar15[-1] != '\0') {
        IVar9 = (*DAT_18007b800)(0x60);
        *pIVar17 = IVar9;
        puVar10 = (undefined8 *)(*DAT_18007b808)(IVar9);
        uVar6 = *(undefined8 *)(pcVar15 + -0x29);
        iVar13 = 0;
        *puVar10 = *(undefined8 *)(pcVar15 + -0x31);
        puVar10[1] = uVar6;
        uVar6 = *(undefined8 *)(pcVar15 + -0x19);
        puVar10[2] = *(undefined8 *)(pcVar15 + -0x21);
        puVar10[3] = uVar6;
        uVar6 = *(undefined8 *)(pcVar15 + -9);
        puVar10[4] = *(undefined8 *)(pcVar15 + -0x11);
        puVar10[5] = uVar6;
        uVar6 = *(undefined8 *)(pcVar15 + 7);
        puVar10[6] = *(undefined8 *)(pcVar15 + -1);
        puVar10[7] = uVar6;
        uVar3 = *(undefined4 *)(pcVar15 + 0x13);
        uVar4 = *(undefined4 *)(pcVar15 + 0x17);
        uVar5 = *(undefined4 *)(pcVar15 + 0x1b);
        *(undefined4 *)(puVar10 + 8) = *(undefined4 *)(pcVar15 + 0xf);
        *(undefined4 *)((longlong)puVar10 + 0x44) = uVar3;
        *(undefined4 *)(puVar10 + 9) = uVar4;
        *(undefined4 *)((longlong)puVar10 + 0x4c) = uVar5;
        uVar3 = *(undefined4 *)(pcVar15 + 0x23);
        uVar4 = *(undefined4 *)(pcVar15 + 0x27);
        uVar5 = *(undefined4 *)(pcVar15 + 0x2b);
        *(undefined4 *)(puVar10 + 10) = *(undefined4 *)(pcVar15 + 0x1f);
        *(undefined4 *)((longlong)puVar10 + 0x54) = uVar3;
        *(undefined4 *)(puVar10 + 0xb) = uVar4;
        *(undefined4 *)((longlong)puVar10 + 0x5c) = uVar5;
        puVar14 = *(undefined8 **)(pcVar15 + 7);
        if ('\0' < *pcVar15) {
          do {
            IVar9 = (*DAT_18007b800)(0x108);
            if (iVar13 == 0) {
              puVar10[7] = IVar9;
            }
            else {
              local_res8[0x20] = IVar9;
            }
            local_res8 = (undefined8 *)(*DAT_18007b808)(IVar9);
            lVar16 = 2;
            puVar11 = puVar14;
            puVar12 = local_res8;
            do {
              puVar1 = puVar12 + 0x10;
              uVar6 = puVar11[1];
              puVar2 = puVar11 + 0x10;
              *puVar12 = *puVar11;
              puVar12[1] = uVar6;
              uVar6 = puVar11[3];
              puVar12[2] = puVar11[2];
              puVar12[3] = uVar6;
              uVar6 = puVar11[5];
              puVar12[4] = puVar11[4];
              puVar12[5] = uVar6;
              uVar6 = puVar11[7];
              puVar12[6] = puVar11[6];
              puVar12[7] = uVar6;
              uVar6 = puVar11[9];
              puVar12[8] = puVar11[8];
              puVar12[9] = uVar6;
              uVar6 = puVar11[0xb];
              puVar12[10] = puVar11[10];
              puVar12[0xb] = uVar6;
              uVar3 = *(undefined4 *)((longlong)puVar11 + 100);
              uVar4 = *(undefined4 *)(puVar11 + 0xd);
              uVar5 = *(undefined4 *)((longlong)puVar11 + 0x6c);
              *(undefined4 *)(puVar12 + 0xc) = *(undefined4 *)(puVar11 + 0xc);
              *(undefined4 *)((longlong)puVar12 + 100) = uVar3;
              *(undefined4 *)(puVar12 + 0xd) = uVar4;
              *(undefined4 *)((longlong)puVar12 + 0x6c) = uVar5;
              uVar3 = *(undefined4 *)((longlong)puVar11 + 0x74);
              uVar4 = *(undefined4 *)(puVar11 + 0xf);
              uVar5 = *(undefined4 *)((longlong)puVar11 + 0x7c);
              *(undefined4 *)(puVar12 + 0xe) = *(undefined4 *)(puVar11 + 0xe);
              *(undefined4 *)((longlong)puVar12 + 0x74) = uVar3;
              *(undefined4 *)(puVar12 + 0xf) = uVar4;
              *(undefined4 *)((longlong)puVar12 + 0x7c) = uVar5;
              lVar16 = lVar16 + -1;
              puVar11 = puVar2;
              puVar12 = puVar1;
            } while (lVar16 != 0);
            iVar13 = iVar13 + 1;
            *puVar1 = *puVar2;
            puVar14 = (undefined8 *)puVar14[0x20];
          } while (iVar13 < *pcVar15);
        }
      }
      pcVar15 = pcVar15 + 0x60;
      pIVar17 = pIVar17 + 1;
    } while ((longlong)pcVar15 < 0x1800791f1);
    return IVar7;
  }
  return 0;
}

/* ---- FUNC 0003BFD2 FUN_18003bfd2 (433 bytes) ---- */

undefined8 FUN_18003bfd2(void)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  code *in_RAX;
  undefined8 uVar6;
  undefined4 *puVar7;
  undefined8 uVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  int iVar12;
  undefined8 *puVar13;
  char *pcVar14;
  longlong lVar15;
  undefined8 *puVar16;
  undefined8 *in_stack_00000050;
  
  uVar6 = (*in_RAX)(0x94c);
  puVar7 = (undefined4 *)(*DAT_18007b808)(uVar6);
  memset(puVar7 + 1,0,0x948);
  puVar16 = (undefined8 *)(puVar7 + 1);
  *puVar7 = 0x129;
  pcVar14 = &DAT_180072291;
  do {
    if (pcVar14[-1] != '\0') {
      uVar8 = (*DAT_18007b800)(0x60);
      *puVar16 = uVar8;
      puVar9 = (undefined8 *)(*DAT_18007b808)(uVar8);
      uVar8 = *(undefined8 *)(pcVar14 + -0x29);
      iVar12 = 0;
      *puVar9 = *(undefined8 *)(pcVar14 + -0x31);
      puVar9[1] = uVar8;
      uVar8 = *(undefined8 *)(pcVar14 + -0x19);
      puVar9[2] = *(undefined8 *)(pcVar14 + -0x21);
      puVar9[3] = uVar8;
      uVar8 = *(undefined8 *)(pcVar14 + -9);
      puVar9[4] = *(undefined8 *)(pcVar14 + -0x11);
      puVar9[5] = uVar8;
      uVar8 = *(undefined8 *)(pcVar14 + 7);
      puVar9[6] = *(undefined8 *)(pcVar14 + -1);
      puVar9[7] = uVar8;
      uVar3 = *(undefined4 *)(pcVar14 + 0x13);
      uVar4 = *(undefined4 *)(pcVar14 + 0x17);
      uVar5 = *(undefined4 *)(pcVar14 + 0x1b);
      *(undefined4 *)(puVar9 + 8) = *(undefined4 *)(pcVar14 + 0xf);
      *(undefined4 *)((longlong)puVar9 + 0x44) = uVar3;
      *(undefined4 *)(puVar9 + 9) = uVar4;
      *(undefined4 *)((longlong)puVar9 + 0x4c) = uVar5;
      uVar3 = *(undefined4 *)(pcVar14 + 0x23);
      uVar4 = *(undefined4 *)(pcVar14 + 0x27);
      uVar5 = *(undefined4 *)(pcVar14 + 0x2b);
      *(undefined4 *)(puVar9 + 10) = *(undefined4 *)(pcVar14 + 0x1f);
      *(undefined4 *)((longlong)puVar9 + 0x54) = uVar3;
      *(undefined4 *)(puVar9 + 0xb) = uVar4;
      *(undefined4 *)((longlong)puVar9 + 0x5c) = uVar5;
      puVar13 = *(undefined8 **)(pcVar14 + 7);
      if ('\0' < *pcVar14) {
        do {
          uVar8 = (*DAT_18007b800)(0x108);
          if (iVar12 == 0) {
            puVar9[7] = uVar8;
          }
          else {
            in_stack_00000050[0x20] = uVar8;
          }
          in_stack_00000050 = (undefined8 *)(*DAT_18007b808)(uVar8);
          lVar15 = 2;
          puVar10 = puVar13;
          puVar11 = in_stack_00000050;
          do {
            puVar1 = puVar11 + 0x10;
            uVar8 = puVar10[1];
            puVar2 = puVar10 + 0x10;
            *puVar11 = *puVar10;
            puVar11[1] = uVar8;
            uVar8 = puVar10[3];
            puVar11[2] = puVar10[2];
            puVar11[3] = uVar8;
            uVar8 = puVar10[5];
            puVar11[4] = puVar10[4];
            puVar11[5] = uVar8;
            uVar8 = puVar10[7];
            puVar11[6] = puVar10[6];
            puVar11[7] = uVar8;
            uVar8 = puVar10[9];
            puVar11[8] = puVar10[8];
            puVar11[9] = uVar8;
            uVar8 = puVar10[0xb];
            puVar11[10] = puVar10[10];
            puVar11[0xb] = uVar8;
            uVar3 = *(undefined4 *)((longlong)puVar10 + 100);
            uVar4 = *(undefined4 *)(puVar10 + 0xd);
            uVar5 = *(undefined4 *)((longlong)puVar10 + 0x6c);
            *(undefined4 *)(puVar11 + 0xc) = *(undefined4 *)(puVar10 + 0xc);
            *(undefined4 *)((longlong)puVar11 + 100) = uVar3;
            *(undefined4 *)(puVar11 + 0xd) = uVar4;
            *(undefined4 *)((longlong)puVar11 + 0x6c) = uVar5;
            uVar3 = *(undefined4 *)((longlong)puVar10 + 0x74);
            uVar4 = *(undefined4 *)(puVar10 + 0xf);
            uVar5 = *(undefined4 *)((longlong)puVar10 + 0x7c);
            *(undefined4 *)(puVar11 + 0xe) = *(undefined4 *)(puVar10 + 0xe);
            *(undefined4 *)((longlong)puVar11 + 0x74) = uVar3;
            *(undefined4 *)(puVar11 + 0xf) = uVar4;
            *(undefined4 *)((longlong)puVar11 + 0x7c) = uVar5;
            lVar15 = lVar15 + -1;
            puVar10 = puVar2;
            puVar11 = puVar1;
          } while (lVar15 != 0);
          iVar12 = iVar12 + 1;
          *puVar1 = *puVar2;
          puVar13 = (undefined8 *)puVar13[0x20];
        } while (iVar12 < *pcVar14);
      }
    }
    pcVar14 = pcVar14 + 0x60;
    puVar16 = puVar16 + 1;
  } while ((longlong)pcVar14 < 0x1800791f1);
  return uVar6;
}

/* ---- FUNC 0003C183 FUN_18003c183 (7 bytes) ---- */

undefined8 FUN_18003c183(void)

{
  return 0;
}

/* ---- FUNC 0003C190 SEWriteAllSettings (333 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 SEWriteAllSettings(int param_1,longlong *param_2)

{
  char cVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  int iVar5;
  uint *puVar6;
  longlong lVar7;
  undefined1 auStack_358 [32];
  char local_338 [784];
  ulonglong local_28;
  longlong lVar8;
  
                    /* 0x3c190  465  SEWriteAllSettings */
  local_28 = DAT_1800791f8 ^ (ulonglong)auStack_358;
  puVar4 = &DAT_180072298;
  do {
    if ((param_1 != 0) || (*(char *)(puVar4 + -1) != '\0')) {
      puVar6 = (uint *)*puVar4;
      iVar5 = 0;
      if ('\0' < *(char *)((longlong)puVar4 + -7)) {
        do {
          cVar1 = *(char *)(puVar4 + -3);
          if (cVar1 == '\x01') {
            FUN_180007de0(local_338,"%s %ld\n",puVar4 + -7,(ulonglong)*puVar6);
          }
          else if (cVar1 == '\x02') {
            FUN_180007de0(local_338,"%s %f\n",puVar4 + -7,*(undefined8 *)puVar6);
          }
          else if (cVar1 == '\x03') {
            FUN_180007de0(local_338,"%s %s\n",puVar4 + -7,puVar6);
          }
          lVar8 = -1;
          do {
            lVar7 = lVar8 + 1;
            lVar2 = lVar8 + 1;
            lVar8 = lVar7;
          } while (local_338[lVar2] != '\0');
          uVar3 = (**(code **)(*param_2 + 0x20))(param_2,local_338,lVar7,0);
          if ((int)uVar3 != 0) {
            return uVar3;
          }
          iVar5 = iVar5 + 1;
          puVar6 = *(uint **)(puVar6 + 0x40);
        } while (iVar5 < *(char *)((longlong)puVar4 + -7));
      }
    }
    puVar4 = puVar4 + 0xc;
    if (0x1800791f7 < (longlong)puVar4) {
      if (param_1 == 0) {
        FUN_180039c50(param_2);
      }
      return 0;
    }
  } while( true );
}

/* ---- FUNC 0003C2E0 SEWriteConfigFile (237 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 SEWriteConfigFile(undefined8 param_1,undefined4 param_2,int param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 *puVar2;
  undefined1 auStackY_458 [32];
  longlong *local_428 [2];
  undefined1 local_418 [1008];
  ulonglong local_28;
  
                    /* 0x3c2e0  466  SEWriteConfigFile */
  local_28 = DAT_1800791f8 ^ (ulonglong)auStackY_458;
  puVar2 = operator_new(0x138);
  if (puVar2 == (undefined8 *)0x0) {
    puVar2 = (undefined8 *)0x0;
  }
  else {
    puVar2 = FUN_180018980(puVar2,param_1,param_2,0,param_4,0);
  }
  local_428[0] = (longlong *)0x0;
  iVar1 = (**(code **)*puVar2)(puVar2,&DAT_180057a78,local_428);
  if (iVar1 != 0) {
    FUN_180007de0(local_418,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\settings.cpp",0x6f1);
    LogMessage(local_418,2,1);
  }
  SEWriteAllSettings(param_3,local_428[0]);
  (**(code **)(*local_428[0] + 0x10))();
  return 0;
}

/* ---- FUNC 0003C3D0 isApp (25 bytes) ---- */

bool isApp(void)

{
  AFX_MODULE_STATE *pAVar1;
  
                    /* 0x3c3d0  548  isApp */
  pAVar1 = AfxGetModuleState();
  return *(longlong *)(pAVar1 + 8) != 0;
}

/* ---- FUNC 0003C3F0 FUN_18003c3f0 (15 bytes) ---- */

void FUN_18003c3f0(longlong *param_1,longlong *param_2)

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
    param_1 = param_1 + 5;
  } while( true );
}

/* ---- FUNC 0003C3FF FUN_18003c3ff (110 bytes) ---- */

void FUN_18003c3ff(longlong *param_1,longlong *param_2)

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
    param_1 = param_1 + 5;
    if (param_1 == param_2) {
      return;
    }
  } while( true );
}

/* ---- FUNC 0003C46D FUN_18003c46d (1 bytes) ---- */

void FUN_18003c46d(void)

{
  return;
}

/* ---- FUNC 0003C46E _invalid_parameter_noinfo_noreturn (6 bytes) ---- */

void __cdecl _invalid_parameter_noinfo_noreturn(void)

{
                    /* WARNING: Subroutine does not return */
  _invalid_parameter_noinfo_noreturn();
}

/* ---- FUNC 0003C480 FUN_18003c480 (15 bytes) ---- */

void FUN_18003c480(undefined8 *param_1,undefined8 *param_2)

{
  for (; param_1 != param_2; param_1 = param_1 + 10) {
    if ((LPVOID)*param_1 != (LPVOID)0x0) {
      CoTaskMemFree((LPVOID)*param_1);
    }
    *param_1 = 0;
  }
  return;
}

/* ---- FUNC 0003C48F FUN_18003c48f (58 bytes) ---- */

void FUN_18003c48f(undefined8 *param_1,undefined8 *param_2)

{
  do {
    if ((LPVOID)*param_1 != (LPVOID)0x0) {
      CoTaskMemFree((LPVOID)*param_1);
    }
    *param_1 = 0;
    param_1 = param_1 + 10;
  } while (param_1 != param_2);
  return;
}

/* ---- FUNC 0003C4C9 FUN_18003c4c9 (1 bytes) ---- */

void FUN_18003c4c9(void)

{
  return;
}

/* ---- FUNC 0003C4D0 FUN_18003c4d0 (635 bytes) ---- */

longlong * FUN_18003c4d0(longlong *param_1,longlong *param_2,longlong *param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  longlong *plVar3;
  longlong lVar4;
  void *pvVar5;
  longlong lVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong *plVar9;
  ulonglong uVar10;
  void *pvVar11;
  __uint64 _Var12;
  longlong *plVar13;
  
  lVar4 = *param_1;
  lVar6 = (param_1[1] - lVar4) / 0x28;
  if (lVar6 == 0x666666666666666) {
                    /* WARNING: Subroutine does not return */
    FUN_18000ad00();
  }
  uVar1 = lVar6 + 1;
  uVar2 = (param_1[2] - lVar4) / 0x28;
  if (0x666666666666666 - (uVar2 >> 1) < uVar2) {
    _Var12 = 0xfffffffffffffff0;
    plVar7 = (longlong *)FUN_180007f10(0xfffffffffffffff0);
  }
  else {
    uVar2 = (uVar2 >> 1) + uVar2;
    uVar10 = uVar1;
    if (uVar1 <= uVar2) {
      uVar10 = uVar2;
    }
    if (0x666666666666666 < uVar10) {
                    /* WARNING: Subroutine does not return */
      FUN_18000ac70();
    }
    _Var12 = uVar10 * 0x28;
    if (_Var12 < 0x1000) {
      if (_Var12 == 0) {
        plVar7 = (longlong *)0x0;
      }
      else {
        plVar7 = operator_new(_Var12);
      }
    }
    else {
      plVar7 = (longlong *)FUN_180007f10(_Var12);
    }
  }
  plVar3 = plVar7 + (((longlong)param_2 - lVar4) / 0x28) * 5;
  *plVar3 = 0;
  plVar3[1] = 0;
  plVar3[2] = 0;
  plVar3[3] = 0;
  lVar4 = param_3[1];
  *plVar3 = *param_3;
  plVar3[1] = lVar4;
  lVar4 = param_3[3];
  plVar3[2] = param_3[2];
  plVar3[3] = lVar4;
  param_3[2] = 0;
  param_3[3] = 0xf;
  *(undefined1 *)param_3 = 0;
  *(int *)(plVar3 + 4) = (int)param_3[4];
  *(undefined4 *)((longlong)plVar3 + 0x24) = *(undefined4 *)((longlong)param_3 + 0x24);
  plVar9 = (longlong *)param_1[1];
  plVar8 = (longlong *)*param_1;
  plVar13 = plVar7;
  if (param_2 != plVar9) {
    FUN_18003dcb0(plVar8,param_2,plVar7);
    plVar9 = (longlong *)param_1[1];
    plVar8 = param_2;
    plVar13 = plVar3 + 5;
  }
  FUN_18003dcb0(plVar8,plVar9,plVar13);
  if ((longlong *)*param_1 != (longlong *)0x0) {
    FUN_18003c3f0((longlong *)*param_1,(longlong *)param_1[1]);
    pvVar5 = (void *)*param_1;
    pvVar11 = pvVar5;
    if ((0xfff < (ulonglong)(((param_1[2] - (longlong)pvVar5) / 0x28) * 0x28)) &&
       (pvVar11 = *(void **)((longlong)pvVar5 + -8),
       0x1f < (ulonglong)((longlong)pvVar5 + (-8 - (longlong)pvVar11)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar11);
  }
  *param_1 = (longlong)plVar7;
  param_1[1] = (longlong)(plVar7 + uVar1 * 5);
  param_1[2] = _Var12 + (longlong)plVar7;
  return plVar3;
}

/* ---- FUNC 0003C750 FUN_18003c750 (537 bytes) ---- */

longlong * FUN_18003c750(longlong *param_1,longlong *param_2,longlong *param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong lVar5;
  longlong *plVar6;
  longlong *plVar7;
  __uint64 _Var8;
  longlong *plVar9;
  longlong *plVar10;
  ulonglong uVar11;
  
  lVar3 = *param_1;
  lVar5 = (param_1[1] - lVar3) / 0x50;
  uVar11 = 0x333333333333333;
  if (lVar5 == 0x333333333333333) {
                    /* WARNING: Subroutine does not return */
    FUN_18000ad00();
  }
  uVar1 = lVar5 + 1;
  uVar2 = (param_1[2] - lVar3) / 0x50;
  if (0x333333333333333 - (uVar2 >> 1) < uVar2) {
    plVar7 = (longlong *)FUN_180007f10(0xfffffffffffffff0);
  }
  else {
    uVar2 = (uVar2 >> 1) + uVar2;
    uVar11 = uVar1;
    if (uVar1 <= uVar2) {
      uVar11 = uVar2;
    }
    if (0x333333333333333 < uVar11) {
                    /* WARNING: Subroutine does not return */
      FUN_18000ac70();
    }
    _Var8 = uVar11 * 0x50;
    if (_Var8 < 0x1000) {
      if (_Var8 == 0) {
        plVar7 = (longlong *)0x0;
      }
      else {
        plVar7 = operator_new(_Var8);
      }
    }
    else {
      plVar7 = (longlong *)FUN_180007f10(_Var8);
    }
  }
  plVar10 = plVar7 + (((longlong)param_2 - lVar3) / 0x50) * 10;
  FUN_18003de90(plVar10,param_3);
  plVar4 = (longlong *)param_1[1];
  plVar9 = (longlong *)*param_1;
  plVar6 = plVar7;
  if (param_2 == plVar4) {
    for (; plVar9 != plVar4; plVar9 = plVar9 + 10) {
      FUN_18003de90(plVar6,plVar9);
      plVar6 = plVar6 + 10;
    }
  }
  else {
    for (; plVar9 != param_2; plVar9 = plVar9 + 10) {
      FUN_18003de90(plVar6,plVar9);
      plVar6 = plVar6 + 10;
    }
    plVar4 = (longlong *)param_1[1];
    if (param_2 != plVar4) {
      lVar3 = 0x50 - (longlong)param_2;
      do {
        FUN_18003de90((longlong *)((longlong)plVar10 + lVar3 + (longlong)param_2),param_2);
        param_2 = param_2 + 10;
      } while (param_2 != plVar4);
    }
  }
  FUN_18003e5a0(param_1,(longlong)plVar7,uVar1,uVar11);
  return plVar10;
}

/* ---- FUNC 0003C970 FUN_18003c970 (580 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

longlong * FUN_18003c970(longlong *param_1,longlong *param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  int iVar4;
  undefined8 ******ppppppuVar5;
  undefined8 ******ppppppuVar6;
  longlong *plVar7;
  longlong *_Buf2;
  longlong *plVar8;
  undefined4 *puVar9;
  longlong *plVar10;
  ulonglong uVar11;
  undefined1 auStack_88 [32];
  longlong *local_68;
  undefined8 *****local_60;
  longlong lStack_58;
  ulonglong local_50;
  ulonglong uStack_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = DAT_1800791f8 ^ (ulonglong)auStack_88;
  if ((param_1 == param_2) || (plVar10 = param_1 + 5, local_68 = param_2, plVar10 == param_2)) {
    return param_2;
  }
LAB_18003c9c0:
  ppppppuVar6 = (undefined8 ******)*plVar10;
  lStack_58 = plVar10[1];
  uVar2 = plVar10[2];
  uVar3 = plVar10[3];
  plVar10[2] = 0;
  plVar10[3] = 0xf;
  *(undefined1 *)plVar10 = 0;
  local_40 = (undefined4)plVar10[4];
  local_3c = *(undefined4 *)((longlong)plVar10 + 0x24);
  plVar7 = param_1;
  if (0xf < (ulonglong)param_1[3]) {
    plVar7 = (longlong *)*param_1;
  }
  uVar1 = param_1[2];
  ppppppuVar5 = &local_60;
  if (0xf < uVar3) {
    ppppppuVar5 = ppppppuVar6;
  }
  uVar11 = uVar2;
  if (uVar1 < uVar2) {
    uVar11 = uVar1;
  }
  local_60 = ppppppuVar6;
  local_50 = uVar2;
  uStack_48 = uVar3;
  iVar4 = memcmp(ppppppuVar5,plVar7,uVar11);
  plVar7 = plVar10;
  if (iVar4 == 0) {
    if (uVar1 <= uVar2) goto LAB_18003ca50;
  }
  else if (-1 < iVar4) {
LAB_18003ca50:
    do {
      plVar8 = plVar7 + -5;
      _Buf2 = plVar8;
      if (0xf < (ulonglong)plVar7[-2]) {
        _Buf2 = (longlong *)*plVar8;
      }
      uVar1 = plVar7[-3];
      ppppppuVar5 = &local_60;
      if (0xf < uVar3) {
        ppppppuVar5 = ppppppuVar6;
      }
      uVar11 = uVar2;
      if (uVar1 < uVar2) {
        uVar11 = uVar1;
      }
      iVar4 = memcmp(ppppppuVar5,_Buf2,uVar11);
      if (iVar4 == 0) {
        if (uVar1 <= uVar2) goto LAB_18003ca8f;
      }
      else if (-1 < iVar4) goto LAB_18003ca8f;
      FUN_18003dfd0(plVar7,plVar8);
      *(int *)(plVar7 + 4) = (int)plVar7[-1];
      *(undefined4 *)((longlong)plVar7 + 0x24) = *(undefined4 *)((longlong)plVar7 + -4);
      plVar7 = plVar8;
    } while( true );
  }
  if (plVar10 != param_1) {
    puVar9 = (undefined4 *)((longlong)plVar10 + 0x4c);
    do {
      plVar7 = (longlong *)(puVar9 + -0x1d);
      FUN_18003dfd0((longlong *)(puVar9 + -0x13),plVar7);
      puVar9[-0xb] = puVar9[-0x15];
      puVar9[-10] = puVar9[-0x14];
      puVar9 = puVar9 + -10;
    } while (plVar7 != param_1);
  }
  FUN_18003dfd0(param_1,(longlong *)&local_60);
  *(undefined4 *)(param_1 + 4) = local_40;
  *(undefined4 *)((longlong)param_1 + 0x24) = local_3c;
  goto LAB_18003caaf;
LAB_18003ca8f:
  FUN_18003dfd0(plVar7,(longlong *)&local_60);
  *(undefined4 *)(plVar7 + 4) = local_40;
  *(undefined4 *)((longlong)plVar7 + 0x24) = local_3c;
  param_2 = local_68;
LAB_18003caaf:
  if (0xf < uStack_48) {
    ppppppuVar6 = (undefined8 ******)local_60;
    if ((0xfff < uStack_48 + 1) &&
       (ppppppuVar6 = (undefined8 ******)local_60[-1],
       0x1f < (ulonglong)((longlong)local_60 + (-8 - (longlong)ppppppuVar6)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(ppppppuVar6);
  }
  plVar10 = plVar10 + 5;
  if (plVar10 == param_2) {
    return param_2;
  }
  goto LAB_18003c9c0;
}

/* ---- FUNC 0003CBC0 FUN_18003cbc0 (85 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18003cbc0(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  longlong *plVar2;
  ulonglong uVar3;
  longlong lVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  uint uVar7;
  int iVar8;
  longlong *plVar9;
  undefined8 ******ppppppuVar10;
  longlong lVar11;
  ulonglong _Size;
  longlong lVar12;
  undefined8 *puVar13;
  longlong lVar14;
  undefined1 auStack_a8 [32];
  ulonglong local_88;
  longlong local_80;
  longlong local_78;
  undefined8 *****local_70;
  undefined8 uStack_68;
  ulonglong local_60;
  ulonglong uStack_58;
  undefined4 local_50;
  undefined4 local_4c;
  ulonglong local_48;
  
  local_48 = DAT_1800791f8 ^ (ulonglong)auStack_a8;
  local_88 = (param_2 - param_1) / 0x28;
  lVar12 = (longlong)local_88 >> 1;
  if (0 < lVar12) {
    local_80 = local_88 - 1;
    lVar11 = local_80 >> 1;
    puVar13 = (undefined8 *)(param_1 + (lVar12 * 5 + 3) * 8);
    local_78 = lVar11;
    do {
      local_70 = (undefined8 *****)puVar13[-8];
      uStack_68 = puVar13[-7];
      lVar12 = lVar12 + -1;
      local_60 = puVar13[-6];
      uStack_58 = puVar13[-5];
      puVar13[-6] = 0;
      puVar13[-5] = 0xf;
      *(undefined1 *)(puVar13 + -8) = 0;
      local_50 = *(undefined4 *)(puVar13 + -4);
      local_4c = *(undefined4 *)((longlong)puVar13 + -0x1c);
      lVar4 = lVar12;
      while (lVar4 < lVar11) {
        puVar1 = (undefined8 *)(param_1 + (lVar4 * 2 + 2) * 0x28);
        uVar7 = FUN_18003eb20(puVar1,puVar1 + -5);
        lVar14 = lVar4 * 2 + 2 + ((longlong)(int)uVar7 >> 0x3f);
        plVar2 = (longlong *)(param_1 + lVar14 * 0x28);
        plVar9 = (longlong *)(param_1 + lVar4 * 0x28);
        FUN_18003dfd0(plVar9,plVar2);
        *(int *)(plVar9 + 4) = (int)plVar2[4];
        *(undefined4 *)((longlong)plVar9 + 0x24) = *(undefined4 *)((longlong)plVar2 + 0x24);
        lVar4 = lVar14;
      }
      uVar6 = local_60;
      if ((lVar4 == lVar11) && ((local_88 & 1) == 0)) {
        lVar14 = param_1 + local_88 * 0x28;
        plVar2 = (longlong *)(param_1 + lVar4 * 0x28);
        FUN_18003dfd0(plVar2,(longlong *)(lVar14 + -0x28));
        *(undefined4 *)(plVar2 + 4) = *(undefined4 *)(lVar14 + -8);
        *(undefined4 *)((longlong)plVar2 + 0x24) = *(undefined4 *)(lVar14 + -4);
        lVar4 = local_80;
        uVar6 = local_60;
      }
      while (uVar5 = local_60, lVar12 < lVar4) {
        lVar14 = lVar4 + -1 >> 1;
        ppppppuVar10 = &local_70;
        if (0xf < uStack_58) {
          ppppppuVar10 = (undefined8 ******)local_70;
        }
        plVar2 = (longlong *)(param_1 + lVar14 * 0x28);
        plVar9 = plVar2;
        if (0xf < *(ulonglong *)(param_1 + 0x18 + lVar14 * 0x28)) {
          plVar9 = (longlong *)*plVar2;
        }
        uVar3 = plVar2[2];
        _Size = uVar3;
        if (local_60 < uVar3) {
          _Size = local_60;
        }
        local_60 = uVar6;
        iVar8 = memcmp(plVar9,ppppppuVar10,_Size);
        lVar11 = local_78;
        uVar6 = local_60;
        if (iVar8 == 0) {
          if (uVar5 <= uVar3) break;
        }
        else if (-1 < iVar8) break;
        plVar9 = (longlong *)(param_1 + lVar4 * 0x28);
        FUN_18003dfd0(plVar9,plVar2);
        *(int *)(plVar9 + 4) = (int)plVar2[4];
        *(undefined4 *)((longlong)plVar9 + 0x24) = *(undefined4 *)((longlong)plVar2 + 0x24);
        lVar11 = local_78;
        lVar4 = lVar14;
        uVar6 = local_60;
        local_60 = uVar5;
      }
      local_60 = uVar6;
      plVar2 = (longlong *)(param_1 + lVar4 * 0x28);
      FUN_18003dfd0(plVar2,(longlong *)&local_70);
      *(undefined4 *)(plVar2 + 4) = local_50;
      *(undefined4 *)((longlong)plVar2 + 0x24) = local_4c;
      if (0xf < uStack_58) {
        ppppppuVar10 = (undefined8 ******)local_70;
        if ((0xfff < uStack_58 + 1) &&
           (ppppppuVar10 = (undefined8 ******)local_70[-1],
           0x1f < (ulonglong)((longlong)local_70 + (-8 - (longlong)ppppppuVar10)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        operator_delete(ppppppuVar10);
      }
      puVar13 = puVar13 + -5;
    } while (0 < lVar12);
  }
  return;
}

/* ---- FUNC 0003CC15 FUN_18003cc15 (577 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18003cc15(ulonglong param_1)

{
  undefined8 *puVar1;
  longlong *plVar2;
  ulonglong uVar3;
  longlong lVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  uint uVar7;
  int iVar8;
  longlong *plVar9;
  undefined1 *puVar10;
  undefined8 unaff_RBX;
  undefined8 unaff_RBP;
  longlong lVar11;
  undefined8 unaff_RSI;
  undefined8 unaff_RDI;
  ulonglong _Size;
  longlong in_R11;
  longlong unaff_R12;
  undefined8 unaff_R13;
  undefined8 *puVar12;
  undefined8 unaff_R14;
  longlong lVar13;
  longlong unaff_R15;
  ulonglong uStackX_20;
  longlong lStack0000000000000028;
  longlong lStack0000000000000030;
  undefined1 *puStack0000000000000038;
  undefined8 uStack0000000000000040;
  ulonglong uStack0000000000000048;
  ulonglong uStack0000000000000050;
  undefined4 uStack0000000000000058;
  undefined4 uStack000000000000005c;
  
  *(undefined8 *)(in_R11 + 0x18) = unaff_RBX;
  lStack0000000000000028 = param_1 - 1;
  *(undefined8 *)(in_R11 + -0x18) = unaff_RBP;
  *(undefined8 *)(in_R11 + -0x20) = unaff_RSI;
  *(undefined8 *)(in_R11 + -0x28) = unaff_RDI;
  *(undefined8 *)(in_R11 + -0x30) = unaff_R13;
  lVar11 = lStack0000000000000028 >> 1;
  *(undefined8 *)(in_R11 + -0x38) = unaff_R14;
  puVar12 = (undefined8 *)(unaff_R15 + (unaff_R12 * 5 + 3) * 8);
  lStack0000000000000030 = lVar11;
  do {
    puStack0000000000000038 = (undefined1 *)puVar12[-8];
    uStack0000000000000040 = puVar12[-7];
    unaff_R12 = unaff_R12 + -1;
    uStack0000000000000048 = puVar12[-6];
    uStack0000000000000050 = puVar12[-5];
    puVar12[-6] = 0;
    puVar12[-5] = 0xf;
    *(undefined1 *)(puVar12 + -8) = 0;
    uStack0000000000000058 = *(undefined4 *)(puVar12 + -4);
    uStack000000000000005c = *(undefined4 *)((longlong)puVar12 + -0x1c);
    lVar4 = unaff_R12;
    while (lVar4 < lVar11) {
      puVar1 = (undefined8 *)(unaff_R15 + (lVar4 * 2 + 2) * 0x28);
      uVar7 = FUN_18003eb20(puVar1,puVar1 + -5);
      lVar13 = lVar4 * 2 + 2 + ((longlong)(int)uVar7 >> 0x3f);
      plVar2 = (longlong *)(unaff_R15 + lVar13 * 0x28);
      plVar9 = (longlong *)(unaff_R15 + lVar4 * 0x28);
      FUN_18003dfd0(plVar9,plVar2);
      *(int *)(plVar9 + 4) = (int)plVar2[4];
      *(undefined4 *)((longlong)plVar9 + 0x24) = *(undefined4 *)((longlong)plVar2 + 0x24);
      lVar4 = lVar13;
      param_1 = uStackX_20;
    }
    uVar6 = uStack0000000000000048;
    if ((lVar4 == lVar11) && ((param_1 & 1) == 0)) {
      lVar13 = unaff_R15 + param_1 * 0x28;
      plVar2 = (longlong *)(unaff_R15 + lVar4 * 0x28);
      FUN_18003dfd0(plVar2,(longlong *)(lVar13 + -0x28));
      *(undefined4 *)(plVar2 + 4) = *(undefined4 *)(lVar13 + -8);
      *(undefined4 *)((longlong)plVar2 + 0x24) = *(undefined4 *)(lVar13 + -4);
      lVar4 = lStack0000000000000028;
      uVar6 = uStack0000000000000048;
    }
    while (uVar5 = uStack0000000000000048, unaff_R12 < lVar4) {
      lVar13 = lVar4 + -1 >> 1;
      puVar10 = (undefined1 *)&stack0x00000038;
      if (0xf < uStack0000000000000050) {
        puVar10 = puStack0000000000000038;
      }
      plVar2 = (longlong *)(unaff_R15 + lVar13 * 0x28);
      plVar9 = plVar2;
      if (0xf < *(ulonglong *)(unaff_R15 + 0x18 + lVar13 * 0x28)) {
        plVar9 = (longlong *)*plVar2;
      }
      uVar3 = plVar2[2];
      _Size = uVar3;
      if (uStack0000000000000048 < uVar3) {
        _Size = uStack0000000000000048;
      }
      uStack0000000000000048 = uVar6;
      iVar8 = memcmp(plVar9,puVar10,_Size);
      lVar11 = lStack0000000000000030;
      uVar6 = uStack0000000000000048;
      if (iVar8 == 0) {
        if (uVar5 <= uVar3) break;
      }
      else if (-1 < iVar8) break;
      plVar9 = (longlong *)(unaff_R15 + lVar4 * 0x28);
      FUN_18003dfd0(plVar9,plVar2);
      *(int *)(plVar9 + 4) = (int)plVar2[4];
      *(undefined4 *)((longlong)plVar9 + 0x24) = *(undefined4 *)((longlong)plVar2 + 0x24);
      lVar11 = lStack0000000000000030;
      lVar4 = lVar13;
      uVar6 = uStack0000000000000048;
      uStack0000000000000048 = uVar5;
    }
    uStack0000000000000048 = uVar6;
    plVar2 = (longlong *)(unaff_R15 + lVar4 * 0x28);
    FUN_18003dfd0(plVar2,(longlong *)&stack0x00000038);
    *(undefined4 *)(plVar2 + 4) = uStack0000000000000058;
    *(undefined4 *)((longlong)plVar2 + 0x24) = uStack000000000000005c;
    if (0xf < uStack0000000000000050) {
      puVar10 = puStack0000000000000038;
      if ((0xfff < uStack0000000000000050 + 1) &&
         (puVar10 = *(undefined1 **)(puStack0000000000000038 + -8),
         (undefined1 *)0x1f < puStack0000000000000038 + (-8 - (longlong)puVar10))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      operator_delete(puVar10);
    }
    param_1 = uStackX_20;
    puVar12 = puVar12 + -5;
    if (unaff_R12 < 1) {
      return;
    }
  } while( true );
}

/* ---- FUNC 0003CE56 FUN_18003ce56 (25 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18003ce56(void)

{
  return;
}

/* ---- FUNC 0003CE70 FUN_18003ce70 (118 bytes) ---- */

void FUN_18003ce70(void **param_1,void **param_2,void **param_3)

{
  uint uVar1;
  
  uVar1 = FUN_18003eb20(param_2,param_1);
  if ((int)uVar1 < 0) {
    FUN_18003dd40(param_2,param_1);
  }
  uVar1 = FUN_18003eb20(param_3,param_2);
  if ((int)uVar1 < 0) {
    FUN_18003dd40(param_3,param_2);
    uVar1 = FUN_18003eb20(param_2,param_1);
    if ((int)uVar1 < 0) {
      FUN_18003dd40(param_2,param_1);
    }
  }
  return;
}

/* ---- FUNC 0003CEF0 FUN_18003cef0 (87 bytes) ---- */

longlong * FUN_18003cef0(longlong *param_1,longlong *param_2,longlong *param_3)

{
  while (param_2 != param_1) {
    FUN_18003dfd0(param_3 + -5,param_2 + -5);
    *(int *)(param_3 + -1) = (int)param_2[-1];
    *(undefined4 *)((longlong)param_3 + -4) = *(undefined4 *)((longlong)param_2 + -4);
    param_2 = param_2 + -5;
    param_3 = param_3 + -5;
  }
  return param_3;
}

/* ---- FUNC 0003CF50 FUN_18003cf50 (2471 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18003cf50(undefined8 *param_1,void **param_2,void **param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  longlong lVar5;
  void **ppvVar6;
  void **ppvVar7;
  void *pvVar8;
  void **ppvVar9;
  void **ppvVar10;
  void *pvVar11;
  void **ppvVar12;
  void **ppvVar13;
  void *_Size;
  void *pvVar14;
  void *pvVar15;
  void **ppvVar16;
  bool bVar17;
  undefined1 auStack_198 [32];
  void **local_178;
  void **local_170;
  void *local_168;
  void *pvStack_160;
  void *local_158;
  void *pvStack_150;
  undefined8 *local_148;
  void *local_140;
  void *pvStack_138;
  void *local_130;
  void *pvStack_128;
  undefined4 local_120;
  undefined4 local_11c;
  void *local_118;
  void *pvStack_110;
  void *local_108;
  void *pvStack_100;
  void *local_f0;
  void *pvStack_e8;
  void *local_e0;
  void *pvStack_d8;
  void *local_c8;
  void *pvStack_c0;
  void *local_b8;
  void *pvStack_b0;
  void *local_a0;
  void *pvStack_98;
  void *local_90;
  void *pvStack_88;
  void *local_78;
  void *pvStack_70;
  void *local_68;
  void *pvStack_60;
  ulonglong local_50;
  
  local_50 = DAT_1800791f8 ^ (ulonglong)auStack_198;
  ppvVar12 = param_3 + -5;
  ppvVar10 = param_2 + (((longlong)param_3 - (longlong)param_2) / 0x28 >> 1) * 5;
  lVar5 = ((longlong)ppvVar12 - (longlong)param_2) / 0x28;
  local_178 = param_3;
  local_170 = param_2;
  local_148 = param_1;
  if (lVar5 < 0x29) {
    FUN_18003ce70(param_2,ppvVar10,ppvVar12);
  }
  else {
    lVar5 = lVar5 + 1 >> 3;
    FUN_18003ce70(param_2,param_2 + lVar5 * 5,param_2 + lVar5 * 10);
    FUN_18003ce70(ppvVar10 + lVar5 * -5,ppvVar10,ppvVar10 + lVar5 * 5);
    FUN_18003ce70(ppvVar12 + lVar5 * -10,ppvVar12 + lVar5 * -5,ppvVar12);
    FUN_18003ce70(param_2 + lVar5 * 5,ppvVar10,ppvVar12 + lVar5 * -5);
    param_2 = local_170;
    param_3 = local_178;
  }
  ppvVar12 = ppvVar10 + 5;
  while (ppvVar13 = ppvVar10, param_2 < ppvVar13) {
    ppvVar10 = ppvVar13 + -5;
    uVar3 = FUN_18003eb20(ppvVar10,ppvVar13);
    if (((int)uVar3 < 0) || (uVar3 = FUN_18003eb20(ppvVar13,ppvVar10), (int)uVar3 < 0)) break;
  }
  ppvVar10 = local_178;
  ppvVar9 = ppvVar12;
  ppvVar16 = ppvVar13;
  if (ppvVar12 < param_3) {
    pvVar11 = ppvVar13[3];
    pvVar8 = ppvVar13[2];
    do {
      ppvVar9 = ppvVar13;
      if ((void *)0xf < pvVar11) {
        ppvVar9 = *ppvVar13;
      }
      pvVar14 = ppvVar12[3];
      ppvVar7 = ppvVar12;
      if ((void *)0xf < pvVar14) {
        ppvVar7 = *ppvVar12;
      }
      pvVar15 = ppvVar12[2];
      _Size = pvVar15;
      if (pvVar8 < pvVar15) {
        _Size = pvVar8;
      }
      iVar4 = memcmp(ppvVar7,ppvVar9,(size_t)_Size);
      param_3 = ppvVar10;
      ppvVar9 = ppvVar12;
      if (iVar4 == 0) {
        if (pvVar15 < pvVar8) break;
      }
      else if (iVar4 < 0) break;
      ppvVar7 = ppvVar12;
      if ((void *)0xf < pvVar14) {
        ppvVar7 = *ppvVar12;
      }
      ppvVar6 = ppvVar13;
      if ((void *)0xf < pvVar11) {
        ppvVar6 = *ppvVar13;
      }
      pvVar14 = pvVar8;
      if (pvVar15 < pvVar8) {
        pvVar14 = pvVar15;
      }
      iVar4 = memcmp(ppvVar6,ppvVar7,(size_t)pvVar14);
      if (iVar4 == 0) {
        if (pvVar8 < pvVar15) break;
      }
      else if (iVar4 < 0) break;
      ppvVar12 = ppvVar12 + 5;
      ppvVar9 = ppvVar12;
    } while (ppvVar12 < ppvVar10);
  }
LAB_18003d142:
  do {
    if (ppvVar12 < param_3) {
      do {
        ppvVar10 = ppvVar12;
        if ((void *)0xf < ppvVar12[3]) {
          ppvVar10 = *ppvVar12;
        }
        pvVar11 = ppvVar13[3];
        ppvVar7 = ppvVar13;
        if ((void *)0xf < pvVar11) {
          ppvVar7 = *ppvVar13;
        }
        pvVar8 = ppvVar12[2];
        pvVar14 = ppvVar13[2];
        pvVar15 = pvVar14;
        if (pvVar8 < pvVar14) {
          pvVar15 = pvVar8;
        }
        iVar4 = memcmp(ppvVar7,ppvVar10,(size_t)pvVar15);
        if (iVar4 == 0) {
          if (pvVar8 <= pvVar14) goto LAB_18003d199;
        }
        else if (-1 < iVar4) {
LAB_18003d199:
          ppvVar10 = ppvVar13;
          if ((void *)0xf < pvVar11) {
            ppvVar10 = *ppvVar13;
          }
          ppvVar7 = ppvVar12;
          if ((void *)0xf < ppvVar12[3]) {
            ppvVar7 = *ppvVar12;
          }
          pvVar11 = pvVar8;
          if (pvVar14 < pvVar8) {
            pvVar11 = pvVar14;
          }
          iVar4 = memcmp(ppvVar7,ppvVar10,(size_t)pvVar11);
          if (iVar4 == 0) {
            if (pvVar8 < pvVar14) break;
          }
          else if (iVar4 < 0) break;
          if (ppvVar9 != ppvVar12) {
            local_130 = ppvVar9[2];
            pvStack_128 = ppvVar9[3];
            local_120 = *(undefined4 *)(ppvVar9 + 4);
            local_140 = *ppvVar9;
            pvStack_138 = ppvVar9[1];
            local_11c = *(undefined4 *)((longlong)ppvVar9 + 0x24);
            ppvVar9[2] = (void *)0x0;
            ppvVar9[3] = (void *)0xf;
            *(undefined1 *)ppvVar9 = 0;
            pvVar11 = ppvVar12[1];
            *ppvVar9 = *ppvVar12;
            ppvVar9[1] = pvVar11;
            pvVar11 = ppvVar12[3];
            ppvVar9[2] = ppvVar12[2];
            ppvVar9[3] = pvVar11;
            ppvVar12[2] = (void *)0x0;
            ppvVar12[3] = (void *)0xf;
            *(undefined1 *)ppvVar12 = 0;
            *(undefined4 *)(ppvVar9 + 4) = *(undefined4 *)(ppvVar12 + 4);
            *(undefined4 *)((longlong)ppvVar9 + 0x24) = *(undefined4 *)((longlong)ppvVar12 + 0x24);
            FUN_18003dfd0((longlong *)ppvVar12,(longlong *)&local_140);
            *(undefined4 *)(ppvVar12 + 4) = local_120;
            *(undefined4 *)((longlong)ppvVar12 + 0x24) = local_11c;
            if ((void *)0xf < pvStack_128) {
              pvVar11 = local_140;
              if ((0xfff < (longlong)pvStack_128 + 1U) &&
                 (pvVar11 = *(void **)((longlong)local_140 + -8),
                 0x1f < (ulonglong)((longlong)local_140 + (-8 - (longlong)pvVar11))))
              goto LAB_18003d8f1;
              operator_delete(pvVar11);
            }
          }
          ppvVar9 = ppvVar9 + 5;
        }
        ppvVar12 = ppvVar12 + 5;
      } while (ppvVar12 < local_178);
    }
    bVar17 = ppvVar16 == local_170;
    ppvVar10 = ppvVar16;
    if (local_170 < ppvVar16) {
      do {
        ppvVar6 = ppvVar10 + -5;
        uVar3 = FUN_18003eb20(ppvVar6,ppvVar13);
        ppvVar7 = ppvVar13;
        if (-1 < (int)uVar3) {
          uVar3 = FUN_18003eb20(ppvVar13,ppvVar6);
          if ((int)uVar3 < 0) break;
          ppvVar7 = ppvVar13 + -5;
          if (ppvVar7 != ppvVar6) {
            local_168 = *ppvVar7;
            pvStack_160 = ppvVar13[-4];
            local_158 = ppvVar13[-3];
            pvVar11 = ppvVar13[-2];
            *(undefined1 *)ppvVar7 = 0;
            uVar1 = *(undefined4 *)(ppvVar13 + -1);
            uVar2 = *(undefined4 *)((longlong)ppvVar13 + -4);
            ppvVar13[-3] = (void *)0x0;
            ppvVar13[-2] = (void *)0xf;
            pvVar8 = ppvVar10[-4];
            *ppvVar7 = *ppvVar6;
            ppvVar13[-4] = pvVar8;
            pvVar8 = ppvVar10[-2];
            ppvVar13[-3] = ppvVar10[-3];
            ppvVar13[-2] = pvVar8;
            ppvVar10[-3] = (void *)0x0;
            *(undefined1 *)ppvVar6 = 0;
            ppvVar10[-2] = (void *)0xf;
            *(undefined4 *)(ppvVar13 + -1) = *(undefined4 *)(ppvVar10 + -1);
            *(undefined4 *)((longlong)ppvVar13 + -4) = *(undefined4 *)((longlong)ppvVar10 + -4);
            pvStack_150 = pvVar11;
            local_118 = local_168;
            pvStack_110 = pvStack_160;
            local_108 = local_158;
            pvStack_100 = pvVar11;
            if (ppvVar6 != &local_118) {
              if ((void *)0xf < ppvVar10[-2]) {
                pvVar11 = *ppvVar6;
                pvVar8 = pvVar11;
                if ((0xfff < (longlong)ppvVar10[-2] + 1U) &&
                   (pvVar8 = *(void **)((longlong)pvVar11 + -8),
                   0x1f < (ulonglong)((longlong)pvVar11 + (-8 - (longlong)pvVar8))))
                goto LAB_18003d8f1;
                operator_delete(pvVar8);
              }
              ppvVar10[-3] = (void *)0x0;
              pvVar11 = (void *)0xf;
              local_118 = (void *)((ulonglong)local_118 & 0xffffffffffffff00);
              *ppvVar6 = local_168;
              ppvVar10[-4] = pvStack_160;
              ppvVar10[-3] = local_158;
              ppvVar10[-2] = pvStack_150;
            }
            *(undefined4 *)(ppvVar10 + -1) = uVar1;
            *(undefined4 *)((longlong)ppvVar10 + -4) = uVar2;
            if ((void *)0xf < pvVar11) {
              pvVar8 = local_118;
              if ((0xfff < (longlong)pvVar11 + 1U) &&
                 (pvVar8 = *(void **)((longlong)local_118 + -8),
                 0x1f < (ulonglong)((longlong)local_118 + (-8 - (longlong)pvVar8))))
              goto LAB_18003d8f1;
              operator_delete(pvVar8);
            }
          }
        }
        ppvVar16 = ppvVar16 + -5;
        ppvVar13 = ppvVar7;
        ppvVar10 = ppvVar6;
      } while (local_170 < ppvVar16);
      bVar17 = ppvVar16 == local_170;
      ppvVar13 = ppvVar7;
    }
    if (!bVar17) {
      ppvVar10 = ppvVar16 + -5;
      if (ppvVar12 == local_178) {
        ppvVar16 = ppvVar13 + -5;
        if (ppvVar10 != ppvVar16) {
          FUN_18003dd40(ppvVar10,ppvVar16);
        }
        local_158 = *ppvVar16;
        pvStack_150 = ppvVar13[-4];
        ppvVar7 = ppvVar9 + -5;
        local_168 = ppvVar13[-3];
        pvVar11 = ppvVar13[-2];
        ppvVar13[-3] = (void *)0x0;
        ppvVar13[-2] = (void *)0xf;
        *(undefined1 *)ppvVar16 = 0;
        uVar1 = *(undefined4 *)(ppvVar13 + -1);
        uVar2 = *(undefined4 *)((longlong)ppvVar13 + -4);
        if (ppvVar16 != ppvVar7) {
          pvVar8 = ppvVar9[-4];
          *ppvVar16 = *ppvVar7;
          ppvVar13[-4] = pvVar8;
          pvVar8 = ppvVar9[-2];
          ppvVar13[-3] = ppvVar9[-3];
          ppvVar13[-2] = pvVar8;
          ppvVar9[-3] = (void *)0x0;
          ppvVar9[-2] = (void *)0xf;
          *(undefined1 *)ppvVar7 = 0;
        }
        *(undefined4 *)(ppvVar13 + -1) = *(undefined4 *)(ppvVar9 + -1);
        *(undefined4 *)((longlong)ppvVar13 + -4) = *(undefined4 *)((longlong)ppvVar9 + -4);
        pvStack_160 = pvVar11;
        local_a0 = local_158;
        pvStack_98 = pvStack_150;
        local_90 = local_168;
        pvStack_88 = pvVar11;
        if (ppvVar7 != &local_a0) {
          if ((void *)0xf < ppvVar9[-2]) {
            pvVar11 = *ppvVar7;
            pvVar8 = pvVar11;
            if ((0xfff < (longlong)ppvVar9[-2] + 1U) &&
               (pvVar8 = *(void **)((longlong)pvVar11 + -8),
               0x1f < (ulonglong)((longlong)pvVar11 + (-8 - (longlong)pvVar8)))) goto LAB_18003d8f1;
            operator_delete(pvVar8);
          }
          ppvVar9[-2] = (void *)0xf;
          pvVar11 = (void *)0xf;
          local_a0 = (void *)((ulonglong)local_a0 & 0xffffffffffffff00);
          *ppvVar7 = local_158;
          ppvVar9[-4] = pvStack_150;
          ppvVar9[-3] = local_168;
          ppvVar9[-2] = pvStack_160;
        }
        param_3 = local_178;
        *(undefined4 *)(ppvVar9 + -1) = uVar1;
        *(undefined4 *)((longlong)ppvVar9 + -4) = uVar2;
        ppvVar9 = ppvVar7;
        ppvVar13 = ppvVar16;
        ppvVar16 = ppvVar10;
        if ((void *)0xf < pvVar11) {
          pvVar8 = local_a0;
          if ((0xfff < (longlong)pvVar11 + 1U) &&
             (pvVar8 = *(void **)((longlong)local_a0 + -8),
             0x1f < (ulonglong)((longlong)local_a0 + (-8 - (longlong)pvVar8)))) goto LAB_18003d8f1;
          operator_delete(pvVar8);
        }
      }
      else {
        local_158 = *ppvVar12;
        pvStack_150 = ppvVar12[1];
        local_168 = ppvVar12[2];
        pvVar11 = ppvVar12[3];
        ppvVar12[2] = (void *)0x0;
        ppvVar12[3] = (void *)0xf;
        *(undefined1 *)ppvVar12 = 0;
        uVar1 = *(undefined4 *)(ppvVar12 + 4);
        uVar2 = *(undefined4 *)((longlong)ppvVar12 + 0x24);
        if (ppvVar12 != ppvVar10) {
          pvVar8 = ppvVar16[-4];
          *ppvVar12 = *ppvVar10;
          ppvVar12[1] = pvVar8;
          pvVar8 = ppvVar16[-2];
          ppvVar12[2] = ppvVar16[-3];
          ppvVar12[3] = pvVar8;
          ppvVar16[-3] = (void *)0x0;
          ppvVar16[-2] = (void *)0xf;
          *(undefined1 *)ppvVar10 = 0;
        }
        *(undefined4 *)(ppvVar12 + 4) = *(undefined4 *)(ppvVar16 + -1);
        *(undefined4 *)((longlong)ppvVar12 + 0x24) = *(undefined4 *)((longlong)ppvVar16 + -4);
        pvStack_160 = pvVar11;
        local_78 = local_158;
        pvStack_70 = pvStack_150;
        local_68 = local_168;
        pvStack_60 = pvVar11;
        if (ppvVar10 != &local_78) {
          if ((void *)0xf < ppvVar16[-2]) {
            pvVar11 = *ppvVar10;
            pvVar8 = pvVar11;
            if ((0xfff < (longlong)ppvVar16[-2] + 1U) &&
               (pvVar8 = *(void **)((longlong)pvVar11 + -8),
               0x1f < (ulonglong)((longlong)pvVar11 + (-8 - (longlong)pvVar8)))) goto LAB_18003d8f1;
            operator_delete(pvVar8);
          }
          ppvVar16[-2] = (void *)0xf;
          pvVar11 = (void *)0xf;
          local_78 = (void *)((ulonglong)local_78 & 0xffffffffffffff00);
          *ppvVar10 = local_158;
          ppvVar16[-4] = pvStack_150;
          ppvVar16[-3] = local_168;
          ppvVar16[-2] = pvStack_160;
        }
        *(undefined4 *)(ppvVar16 + -1) = uVar1;
        *(undefined4 *)((longlong)ppvVar16 + -4) = uVar2;
        if ((void *)0xf < pvVar11) {
          pvVar8 = local_78;
          if ((0xfff < (longlong)pvVar11 + 1U) &&
             (pvVar8 = *(void **)((longlong)local_78 + -8),
             0x1f < (ulonglong)((longlong)local_78 + (-8 - (longlong)pvVar8)))) goto LAB_18003d8f1;
          operator_delete(pvVar8);
        }
        ppvVar12 = ppvVar12 + 5;
        ppvVar16 = ppvVar10;
        param_3 = local_178;
      }
      goto LAB_18003d142;
    }
    if (ppvVar12 == local_178) {
      *local_148 = ppvVar13;
      local_148[1] = ppvVar9;
      return;
    }
    if (ppvVar9 != ppvVar12) {
      local_158 = *ppvVar13;
      pvStack_150 = ppvVar13[1];
      local_168 = ppvVar13[2];
      pvVar11 = ppvVar13[3];
      ppvVar13[2] = (void *)0x0;
      ppvVar13[3] = (void *)0xf;
      *(undefined1 *)ppvVar13 = 0;
      uVar1 = *(undefined4 *)(ppvVar13 + 4);
      uVar2 = *(undefined4 *)((longlong)ppvVar13 + 0x24);
      if (ppvVar13 != ppvVar9) {
        pvVar8 = ppvVar9[1];
        *ppvVar13 = *ppvVar9;
        ppvVar13[1] = pvVar8;
        pvVar8 = ppvVar9[3];
        ppvVar13[2] = ppvVar9[2];
        ppvVar13[3] = pvVar8;
        ppvVar9[2] = (void *)0x0;
        ppvVar9[3] = (void *)0xf;
        *(undefined1 *)ppvVar9 = 0;
      }
      *(undefined4 *)(ppvVar13 + 4) = *(undefined4 *)(ppvVar9 + 4);
      *(undefined4 *)((longlong)ppvVar13 + 0x24) = *(undefined4 *)((longlong)ppvVar9 + 0x24);
      pvStack_160 = pvVar11;
      local_f0 = local_158;
      pvStack_e8 = pvStack_150;
      local_e0 = local_168;
      pvStack_d8 = pvVar11;
      if (ppvVar9 != &local_f0) {
        if ((void *)0xf < ppvVar9[3]) {
          pvVar11 = *ppvVar9;
          pvVar8 = pvVar11;
          if ((0xfff < (longlong)ppvVar9[3] + 1U) &&
             (pvVar8 = *(void **)((longlong)pvVar11 + -8),
             0x1f < (ulonglong)((longlong)pvVar11 + (-8 - (longlong)pvVar8)))) {
LAB_18003d8f1:
                    /* WARNING: Subroutine does not return */
            _invalid_parameter_noinfo_noreturn();
          }
          operator_delete(pvVar8);
        }
        ppvVar9[3] = (void *)0xf;
        pvVar11 = (void *)0xf;
        local_f0 = (void *)((ulonglong)local_f0 & 0xffffffffffffff00);
        *ppvVar9 = local_158;
        ppvVar9[1] = pvStack_150;
        ppvVar9[2] = local_168;
        ppvVar9[3] = pvStack_160;
      }
      *(undefined4 *)(ppvVar9 + 4) = uVar1;
      *(undefined4 *)((longlong)ppvVar9 + 0x24) = uVar2;
      if ((void *)0xf < pvVar11) {
        pvVar8 = local_f0;
        if ((0xfff < (longlong)pvVar11 + 1U) &&
           (pvVar8 = *(void **)((longlong)local_f0 + -8),
           0x1f < (ulonglong)((longlong)local_f0 + (-8 - (longlong)pvVar8)))) goto LAB_18003d8f1;
        operator_delete(pvVar8);
      }
    }
    local_158 = *ppvVar13;
    pvStack_150 = ppvVar13[1];
    local_168 = ppvVar13[2];
    pvVar11 = ppvVar13[3];
    ppvVar13[2] = (void *)0x0;
    ppvVar13[3] = (void *)0xf;
    *(undefined1 *)ppvVar13 = 0;
    uVar1 = *(undefined4 *)(ppvVar13 + 4);
    uVar2 = *(undefined4 *)((longlong)ppvVar13 + 0x24);
    if (ppvVar13 != ppvVar12) {
      pvVar8 = ppvVar12[1];
      *ppvVar13 = *ppvVar12;
      ppvVar13[1] = pvVar8;
      pvVar8 = ppvVar12[3];
      ppvVar13[2] = ppvVar12[2];
      ppvVar13[3] = pvVar8;
      ppvVar12[2] = (void *)0x0;
      ppvVar12[3] = (void *)0xf;
      *(undefined1 *)ppvVar12 = 0;
    }
    *(undefined4 *)(ppvVar13 + 4) = *(undefined4 *)(ppvVar12 + 4);
    *(undefined4 *)((longlong)ppvVar13 + 0x24) = *(undefined4 *)((longlong)ppvVar12 + 0x24);
    pvStack_160 = pvVar11;
    local_c8 = local_158;
    pvStack_c0 = pvStack_150;
    local_b8 = local_168;
    pvStack_b0 = pvVar11;
    if (ppvVar12 != &local_c8) {
      if ((void *)0xf < ppvVar12[3]) {
        pvVar11 = *ppvVar12;
        pvVar8 = pvVar11;
        if ((0xfff < (longlong)ppvVar12[3] + 1U) &&
           (pvVar8 = *(void **)((longlong)pvVar11 + -8),
           0x1f < (ulonglong)((longlong)pvVar11 + (-8 - (longlong)pvVar8)))) goto LAB_18003d8f1;
        operator_delete(pvVar8);
      }
      ppvVar12[3] = (void *)0xf;
      pvVar11 = (void *)0xf;
      local_c8 = (void *)((ulonglong)local_c8 & 0xffffffffffffff00);
      *ppvVar12 = local_158;
      ppvVar12[1] = pvStack_150;
      ppvVar12[2] = local_168;
      ppvVar12[3] = pvStack_160;
    }
    *(undefined4 *)(ppvVar12 + 4) = uVar1;
    *(undefined4 *)((longlong)ppvVar12 + 0x24) = uVar2;
    if ((void *)0xf < pvVar11) {
      pvVar8 = local_c8;
      if ((0xfff < (longlong)pvVar11 + 1U) &&
         (pvVar8 = *(void **)((longlong)local_c8 + -8),
         0x1f < (ulonglong)((longlong)local_c8 + (-8 - (longlong)pvVar8)))) goto LAB_18003d8f1;
      operator_delete(pvVar8);
    }
    ppvVar12 = ppvVar12 + 5;
    ppvVar9 = ppvVar9 + 5;
    ppvVar13 = ppvVar13 + 5;
    param_3 = local_178;
  } while( true );
}

/* ---- FUNC 0003D900 FUN_18003d900 (22 bytes) ---- */

void FUN_18003d900(longlong param_1,longlong param_2,ulonglong param_3,longlong *param_4)

{
  undefined8 *puVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong lVar4;
  uint uVar5;
  longlong lVar6;
  longlong lVar7;
  
  lVar6 = (longlong)(param_3 - 1) >> 1;
  lVar4 = param_2;
  while (lVar4 < lVar6) {
    puVar1 = (undefined8 *)(param_1 + (lVar4 * 2 + 2) * 0x28);
    uVar5 = FUN_18003eb20(puVar1,puVar1 + -5);
    lVar7 = lVar4 * 2 + 2 + ((longlong)(int)uVar5 >> 0x3f);
    plVar2 = (longlong *)(param_1 + lVar7 * 0x28);
    plVar3 = (longlong *)(param_1 + lVar4 * 0x28);
    FUN_18003dfd0(plVar3,plVar2);
    *(int *)(plVar3 + 4) = (int)plVar2[4];
    *(undefined4 *)((longlong)plVar3 + 0x24) = *(undefined4 *)((longlong)plVar2 + 0x24);
    lVar4 = lVar7;
  }
  if ((lVar4 == lVar6) && ((param_3 & 1) == 0)) {
    lVar6 = param_1 + param_3 * 0x28;
    plVar2 = (longlong *)(param_1 + lVar4 * 0x28);
    FUN_18003dfd0(plVar2,(longlong *)(lVar6 + -0x28));
    *(undefined4 *)(plVar2 + 4) = *(undefined4 *)(lVar6 + -8);
    *(undefined4 *)((longlong)plVar2 + 0x24) = *(undefined4 *)(lVar6 + -4);
    lVar4 = param_3 - 1;
  }
  while (param_2 < lVar4) {
    lVar6 = lVar4 + -1 >> 1;
    plVar2 = (longlong *)(param_1 + lVar6 * 0x28);
    uVar5 = FUN_18003eb20(plVar2,param_4);
    if (-1 < (int)uVar5) break;
    plVar3 = (longlong *)(param_1 + lVar4 * 0x28);
    FUN_18003dfd0(plVar3,plVar2);
    *(int *)(plVar3 + 4) = (int)plVar2[4];
    *(undefined4 *)((longlong)plVar3 + 0x24) = *(undefined4 *)((longlong)plVar2 + 0x24);
    lVar4 = lVar6;
  }
  plVar2 = (longlong *)(param_1 + lVar4 * 0x28);
  FUN_18003dfd0(plVar2,param_4);
  *(int *)(plVar2 + 4) = (int)param_4[4];
  *(undefined4 *)((longlong)plVar2 + 0x24) = *(undefined4 *)((longlong)param_4 + 0x24);
  return;
}

/* ---- FUNC 0003D916 FUN_18003d916 (143 bytes) ---- */

void FUN_18003d916(undefined8 param_1,longlong param_2,ulonglong param_3,longlong *param_4)

{
  undefined8 *puVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong lVar4;
  uint uVar5;
  longlong lVar6;
  longlong unaff_R14;
  longlong lVar7;
  longlong lStack0000000000000060;
  ulonglong in_stack_00000070;
  
  lStack0000000000000060 = param_3 - 1;
  lVar6 = lStack0000000000000060 >> 1;
  lVar4 = param_2;
  while (lVar4 < lVar6) {
    puVar1 = (undefined8 *)(unaff_R14 + (lVar4 * 2 + 2) * 0x28);
    uVar5 = FUN_18003eb20(puVar1,puVar1 + -5);
    lVar7 = lVar4 * 2 + 2 + ((longlong)(int)uVar5 >> 0x3f);
    plVar2 = (longlong *)(unaff_R14 + lVar7 * 0x28);
    plVar3 = (longlong *)(unaff_R14 + lVar4 * 0x28);
    FUN_18003dfd0(plVar3,plVar2);
    *(int *)(plVar3 + 4) = (int)plVar2[4];
    *(undefined4 *)((longlong)plVar3 + 0x24) = *(undefined4 *)((longlong)plVar2 + 0x24);
    param_3 = in_stack_00000070;
    lVar4 = lVar7;
  }
  if ((lVar4 == lVar6) && ((param_3 & 1) == 0)) {
    lVar6 = unaff_R14 + param_3 * 0x28;
    plVar2 = (longlong *)(unaff_R14 + lVar4 * 0x28);
    FUN_18003dfd0(plVar2,(longlong *)(lVar6 + -0x28));
    *(undefined4 *)(plVar2 + 4) = *(undefined4 *)(lVar6 + -8);
    *(undefined4 *)((longlong)plVar2 + 0x24) = *(undefined4 *)(lVar6 + -4);
    lVar4 = lStack0000000000000060;
  }
  while (param_2 < lVar4) {
    lVar6 = lVar4 + -1 >> 1;
    plVar2 = (longlong *)(unaff_R14 + lVar6 * 0x28);
    uVar5 = FUN_18003eb20(plVar2,param_4);
    if (-1 < (int)uVar5) break;
    plVar3 = (longlong *)(unaff_R14 + lVar4 * 0x28);
    FUN_18003dfd0(plVar3,plVar2);
    *(int *)(plVar3 + 4) = (int)plVar2[4];
    *(undefined4 *)((longlong)plVar3 + 0x24) = *(undefined4 *)((longlong)plVar2 + 0x24);
    lVar4 = lVar6;
  }
  plVar2 = (longlong *)(unaff_R14 + lVar4 * 0x28);
  FUN_18003dfd0(plVar2,param_4);
  *(int *)(plVar2 + 4) = (int)param_4[4];
  *(undefined4 *)((longlong)plVar2 + 0x24) = *(undefined4 *)((longlong)param_4 + 0x24);
  return;
}

/* ---- FUNC 0003D9A5 FUN_18003d9a5 (176 bytes) ---- */

void FUN_18003d9a5(void)

{
  longlong *plVar1;
  longlong *plVar2;
  uint uVar3;
  ulonglong in_RAX;
  longlong lVar4;
  longlong unaff_RSI;
  longlong unaff_R12;
  longlong *unaff_R13;
  longlong unaff_R14;
  longlong in_stack_00000060;
  
  if ((in_RAX & 1) == 0) {
    lVar4 = unaff_R14 + in_RAX * 0x28;
    plVar1 = (longlong *)(unaff_R14 + unaff_RSI * 0x28);
    FUN_18003dfd0(plVar1,(longlong *)(lVar4 + -0x28));
    *(undefined4 *)(plVar1 + 4) = *(undefined4 *)(lVar4 + -8);
    *(undefined4 *)((longlong)plVar1 + 0x24) = *(undefined4 *)(lVar4 + -4);
    unaff_RSI = in_stack_00000060;
  }
  while (unaff_R12 < unaff_RSI) {
    lVar4 = unaff_RSI + -1 >> 1;
    plVar1 = (longlong *)(unaff_R14 + lVar4 * 0x28);
    uVar3 = FUN_18003eb20(plVar1,unaff_R13);
    if (-1 < (int)uVar3) break;
    plVar2 = (longlong *)(unaff_R14 + unaff_RSI * 0x28);
    FUN_18003dfd0(plVar2,plVar1);
    *(int *)(plVar2 + 4) = (int)plVar1[4];
    *(undefined4 *)((longlong)plVar2 + 0x24) = *(undefined4 *)((longlong)plVar1 + 0x24);
    unaff_RSI = lVar4;
  }
  plVar1 = (longlong *)(unaff_R14 + unaff_RSI * 0x28);
  FUN_18003dfd0(plVar1,unaff_R13);
  *(int *)(plVar1 + 4) = (int)unaff_R13[4];
  *(undefined4 *)((longlong)plVar1 + 0x24) = *(undefined4 *)((longlong)unaff_R13 + 0x24);
  return;
}

/* ---- FUNC 0003DA60 FUN_18003da60 (586 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18003da60(void **param_1,void **param_2,longlong param_3,undefined1 param_4)

{
  void **ppvVar1;
  longlong lVar2;
  ulonglong uVar3;
  void *pvVar4;
  void **ppvVar5;
  undefined1 auStack_a8 [32];
  undefined1 local_88;
  void **local_78;
  void **local_70;
  void *local_68;
  void *pvStack_60;
  void *local_58;
  void *pvStack_50;
  undefined4 local_48;
  undefined4 local_44;
  ulonglong local_40;
  
  local_40 = DAT_1800791f8 ^ (ulonglong)auStack_a8;
  lVar2 = (longlong)param_2 - (longlong)param_1;
  while( true ) {
    if (lVar2 < 0x528) {
      FUN_18003c970((longlong *)param_1,(longlong *)param_2);
      return;
    }
    if (param_3 < 1) break;
    FUN_18003cf50(&local_78,param_1,param_2);
    ppvVar1 = local_70;
    ppvVar5 = local_78;
    param_3 = (param_3 >> 1) + (param_3 >> 2);
    if (((longlong)local_78 - (longlong)param_1) / 0x28 <
        ((longlong)param_2 - (longlong)local_70) / 0x28) {
      FUN_18003da60(param_1,local_78,param_3,param_4);
      ppvVar5 = param_2;
      param_1 = ppvVar1;
    }
    else {
      FUN_18003da60(local_70,param_2,param_3,param_4);
    }
    lVar2 = (longlong)ppvVar5 - (longlong)param_1;
    param_2 = ppvVar5;
  }
  FUN_18003cbc0((longlong)param_1,(longlong)param_2);
  uVar3 = (longlong)param_2 - (longlong)param_1;
  if ((longlong)uVar3 < 0x50) {
    return;
  }
  ppvVar5 = param_2 + -2;
  do {
    if (1 < uVar3 / 0x28) {
      local_68 = ppvVar5[-3];
      pvStack_60 = ppvVar5[-2];
      ppvVar1 = ppvVar5 + -3;
      local_58 = ppvVar5[-1];
      pvStack_50 = *ppvVar5;
      ppvVar5[-1] = (void *)0x0;
      *ppvVar5 = (void *)0xf;
      *(undefined1 *)ppvVar1 = 0;
      local_48 = *(undefined4 *)(ppvVar5 + 1);
      local_44 = *(undefined4 *)((longlong)ppvVar5 + 0xc);
      if (ppvVar1 != param_1) {
        pvVar4 = param_1[1];
        *ppvVar1 = *param_1;
        ppvVar5[-2] = pvVar4;
        pvVar4 = param_1[3];
        ppvVar5[-1] = param_1[2];
        *ppvVar5 = pvVar4;
        param_1[2] = (void *)0x0;
        param_1[3] = (void *)0xf;
        *(undefined1 *)param_1 = 0;
      }
      *(undefined4 *)(ppvVar5 + 1) = *(undefined4 *)(param_1 + 4);
      *(undefined4 *)((longlong)ppvVar5 + 0xc) = *(undefined4 *)((longlong)param_1 + 0x24);
      local_88 = param_4;
      FUN_18003d900((longlong)param_1,0,((longlong)ppvVar1 - (longlong)param_1) / 0x28,
                    (longlong *)&local_68);
      if ((void *)0xf < pvStack_50) {
        pvVar4 = local_68;
        if ((0xfff < (longlong)pvStack_50 + 1U) &&
           (pvVar4 = *(void **)((longlong)local_68 + -8),
           0x1f < (ulonglong)((longlong)local_68 + (-8 - (longlong)pvVar4)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        operator_delete(pvVar4);
      }
    }
    ppvVar5 = ppvVar5 + -5;
    uVar3 = (longlong)ppvVar5 + (0x10 - (longlong)param_1);
    if ((longlong)uVar3 < 0x50) {
      return;
    }
  } while( true );
}

/* ---- FUNC 0003DCB0 FUN_18003dcb0 (139 bytes) ---- */

longlong * FUN_18003dcb0(longlong *param_1,longlong *param_2,longlong *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong lVar5;
  
  if (param_1 != param_2) {
    lVar5 = (longlong)param_3 - (longlong)param_1;
    plVar4 = param_1 + 3;
    do {
      plVar1 = plVar4 + 5;
      *param_3 = 0;
      param_3[1] = 0;
      *(undefined8 *)(lVar5 + -0x30 + (longlong)plVar1) = 0;
      *(undefined8 *)((longlong)plVar4 + lVar5) = 0;
      lVar3 = plVar4[-2];
      *param_3 = plVar4[-3];
      param_3[1] = lVar3;
      lVar3 = *plVar4;
      param_3[2] = plVar4[-1];
      param_3[3] = lVar3;
      plVar4[-1] = 0;
      param_3 = param_3 + 5;
      *plVar4 = 0xf;
      *(undefined1 *)(plVar4 + -3) = 0;
      *(int *)(lVar5 + -0x20 + (longlong)plVar1) = (int)plVar4[1];
      *(undefined4 *)(lVar5 + -0x1c + (longlong)plVar1) = *(undefined4 *)((longlong)plVar4 + 0xc);
      plVar2 = plVar4 + 2;
      plVar4 = plVar1;
    } while (plVar2 != param_2);
  }
  FUN_18003c3f0(param_3,param_3);
  return param_3;
}

/* ---- FUNC 0003DD40 FUN_18003dd40 (335 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18003dd40(void **param_1,void **param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  void *pvVar3;
  void *pvVar4;
  undefined1 auStack_98 [32];
  void *local_78;
  void *pvStack_70;
  void *local_68;
  void *pvStack_60;
  void *local_58;
  void *pvStack_50;
  void *local_48;
  void *pvStack_40;
  ulonglong local_30;
  
  local_30 = DAT_1800791f8 ^ (ulonglong)auStack_98;
  local_78 = *param_1;
  pvStack_70 = param_1[1];
  local_68 = param_1[2];
  pvVar4 = param_1[3];
  param_1[2] = (void *)0x0;
  param_1[3] = (void *)0xf;
  *(undefined1 *)param_1 = 0;
  uVar1 = *(undefined4 *)(param_1 + 4);
  uVar2 = *(undefined4 *)((longlong)param_1 + 0x24);
  if (param_1 != param_2) {
    pvVar3 = param_2[1];
    *param_1 = *param_2;
    param_1[1] = pvVar3;
    pvVar3 = param_2[3];
    param_1[2] = param_2[2];
    param_1[3] = pvVar3;
    param_2[2] = (void *)0x0;
    param_2[3] = (void *)0xf;
    *(undefined1 *)param_2 = 0;
  }
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)((longlong)param_1 + 0x24) = *(undefined4 *)((longlong)param_2 + 0x24);
  pvStack_60 = pvVar4;
  local_58 = local_78;
  pvStack_50 = pvStack_70;
  local_48 = local_68;
  pvStack_40 = pvVar4;
  if (param_2 != &local_58) {
    if ((void *)0xf < param_2[3]) {
      pvVar4 = *param_2;
      pvVar3 = pvVar4;
      if ((0xfff < (longlong)param_2[3] + 1U) &&
         (pvVar3 = *(void **)((longlong)pvVar4 + -8),
         0x1f < (ulonglong)((longlong)pvVar4 + (-8 - (longlong)pvVar3)))) goto LAB_18003de62;
      operator_delete(pvVar3);
    }
    param_2[2] = (void *)0x0;
    local_58 = (void *)((ulonglong)local_58 & 0xffffffffffffff00);
    *param_2 = local_78;
    param_2[1] = pvStack_70;
    param_2[2] = local_68;
    param_2[3] = pvStack_60;
    pvVar4 = (void *)0xf;
  }
  *(undefined4 *)(param_2 + 4) = uVar1;
  *(undefined4 *)((longlong)param_2 + 0x24) = uVar2;
  if ((void *)0xf < pvVar4) {
    pvVar3 = local_58;
    if ((0xfff < (longlong)pvVar4 + 1U) &&
       (pvVar3 = *(void **)((longlong)local_58 + -8),
       0x1f < (ulonglong)((longlong)local_58 + (-8 - (longlong)pvVar3)))) {
LAB_18003de62:
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar3);
  }
  return;
}

/* ---- FUNC 0003DE90 FUN_18003de90 (145 bytes) ---- */

longlong * FUN_18003de90(longlong *param_1,longlong *param_2)

{
  longlong lVar1;
  short sVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  short *psVar5;
  longlong lVar6;
  short *psVar7;
  
  lVar6 = param_2[1];
  *param_1 = *param_2;
  param_1[1] = lVar6;
  lVar6 = param_2[3];
  param_1[2] = param_2[2];
  param_1[3] = lVar6;
  lVar6 = param_2[5];
  param_1[4] = param_2[4];
  param_1[5] = lVar6;
  uVar3 = *(undefined4 *)((longlong)param_2 + 0x34);
  lVar6 = param_2[7];
  uVar4 = *(undefined4 *)((longlong)param_2 + 0x3c);
  *(int *)(param_1 + 6) = (int)param_2[6];
  *(undefined4 *)((longlong)param_1 + 0x34) = uVar3;
  *(int *)(param_1 + 7) = (int)lVar6;
  *(undefined4 *)((longlong)param_1 + 0x3c) = uVar4;
  uVar3 = *(undefined4 *)((longlong)param_2 + 0x44);
  lVar6 = param_2[9];
  uVar4 = *(undefined4 *)((longlong)param_2 + 0x4c);
  *(int *)(param_1 + 8) = (int)param_2[8];
  *(undefined4 *)((longlong)param_1 + 0x44) = uVar3;
  *(int *)(param_1 + 9) = (int)lVar6;
  *(undefined4 *)((longlong)param_1 + 0x4c) = uVar4;
  if (*param_2 != 0) {
    lVar6 = -1;
    do {
      lVar1 = lVar6 * 2;
      lVar6 = lVar6 + 1;
    } while (*(short *)(*param_2 + 2 + lVar1) != 0);
    psVar5 = CoTaskMemAlloc(lVar6 * 2 + 2);
    *param_1 = (longlong)psVar5;
    psVar7 = (short *)*param_2;
    do {
      sVar2 = *psVar7;
      psVar7 = psVar7 + 1;
      *psVar5 = sVar2;
      psVar5 = psVar5 + 1;
    } while (sVar2 != 0);
  }
  return param_1;
}

/* ---- FUNC 0003DF30 FUN_18003df30 (137 bytes) ---- */

void FUN_18003df30(longlong *param_1)

{
  void *pvVar1;
  void *pvVar2;
  
  if ((longlong *)*param_1 != (longlong *)0x0) {
    FUN_18003c3f0((longlong *)*param_1,(longlong *)param_1[1]);
    pvVar1 = (void *)*param_1;
    pvVar2 = pvVar1;
    if ((0xfff < (ulonglong)(((param_1[2] - (longlong)pvVar1) / 0x28) * 0x28)) &&
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

/* ---- FUNC 0003DFD0 FUN_18003dfd0 (139 bytes) ---- */

longlong * FUN_18003dfd0(longlong *param_1,longlong *param_2)

{
  void *pvVar1;
  longlong lVar2;
  void *pvVar3;
  
  if (param_1 != param_2) {
    if (0xf < (ulonglong)param_1[3]) {
      pvVar1 = (void *)*param_1;
      pvVar3 = pvVar1;
      if ((0xfff < param_1[3] + 1U) &&
         (pvVar3 = *(void **)((longlong)pvVar1 + -8),
         0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar3)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      operator_delete(pvVar3);
    }
    param_1[3] = 0xf;
    param_1[2] = 0;
    *(undefined1 *)param_1 = 0;
    lVar2 = param_2[1];
    *param_1 = *param_2;
    param_1[1] = lVar2;
    lVar2 = param_2[3];
    param_1[2] = param_2[2];
    param_1[3] = lVar2;
    param_2[2] = 0;
    param_2[3] = 0xf;
    *(undefined1 *)param_2 = 0;
  }
  return param_1;
}

/* ---- FUNC 0003E060 FUN_18003e060 (24 bytes) ---- */

void FUN_18003e060(undefined4 param_1)

{
  MMXLCommitItem(param_1);
  DAT_18007b83c = 1;
  return;
}

/* ---- FUNC 0003E080 FUN_18003e080 (68 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18003e080(undefined *param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 auStack_158 [32];
  undefined4 local_138 [2];
  undefined8 local_130;
  undefined1 local_128 [272];
  ulonglong local_18;
  
  local_18 = DAT_1800791f8 ^ (ulonglong)auStack_158;
  uVar2 = 0;
  local_130 = 0;
  iVar1 = (*(code *)param_1)(&local_130,local_128,0x104,local_138);
  while (iVar1 != 0) {
    iVar1 = MMXLCommitItem(local_138[0]);
    if (iVar1 != 0) {
      uVar2 = 1;
    }
    iVar1 = (*(code *)param_1)(&local_130,local_128,0x104,local_138);
  }
  return uVar2;
}

/* ---- FUNC 0003E0C4 FUN_18003e0c4 (61 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_18003e0c4(void)

{
  int iVar1;
  int unaff_EBX;
  int iVar2;
  code *unaff_RDI;
  undefined4 auStackX_20 [2];
  
  iVar2 = unaff_EBX + 1;
  do {
    iVar1 = MMXLCommitItem(auStackX_20[0]);
    if (iVar1 != 0) {
      unaff_EBX = iVar2;
    }
    iVar1 = (*unaff_RDI)(&stack0x00000028,&stack0x00000030,0x104,auStackX_20);
  } while (iVar1 != 0);
  return unaff_EBX;
}

/* ---- FUNC 0003E101 FUN_18003e101 (35 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_18003e101(void)

{
  undefined4 unaff_EBX;
  
  return unaff_EBX;
}

/* ---- FUNC 0003E130 FUN_18003e130 (197 bytes) ---- */

HRESULT FUN_18003e130(longlong *param_1,IStorage *param_2,undefined *param_3,undefined *param_4)

{
  HRESULT HVar1;
  IStorage *local_res20;
  LPLOCKBYTES local_18 [2];
  
  if (param_4 == (undefined *)0x0) {
    HVar1 = MMCopyStorage(param_1,param_2,param_3);
  }
  else {
    local_res20 = (IStorage *)0x0;
    local_18[0] = (ILockBytes *)0x0;
    HVar1 = MMCreateStorageOnHGlobal(&local_res20,local_18);
    if (-1 < HVar1) {
      HVar1 = MMCopyStorage(param_1,local_res20,param_3);
      if (-1 < HVar1) {
        FUN_18003e270((longlong *)local_res20,(longlong *)param_2,param_4);
        (*local_res20->lpVtbl->Commit)(local_res20,0);
        HVar1 = (*local_res20->lpVtbl->CopyTo)(local_res20,0,(IID *)0x0,(SNB)0x0,param_2);
      }
      (*local_res20->lpVtbl->Release)(local_res20);
      (*local_18[0]->lpVtbl->Release)(local_18[0]);
    }
  }
  return HVar1;
}

/* ---- FUNC 0003E200 MMCreateStorageOnHGlobal (99 bytes) ---- */

HRESULT MMCreateStorageOnHGlobal(IStorage **param_1,LPLOCKBYTES *param_2)

{
  HRESULT HVar1;
  
                    /* 0x3e200  134  MMCreateStorageOnHGlobal */
  if ((param_1 == (IStorage **)0x0) || (param_2 == (LPLOCKBYTES *)0x0)) {
    HVar1 = -0x7ff8ffa9;
  }
  else {
    *param_1 = (IStorage *)0x0;
    *param_2 = (LPLOCKBYTES)0x0;
    HVar1 = CreateILockBytesOnHGlobal((HGLOBAL)0x0,1,param_2);
    if (HVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x00018003e24c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      HVar1 = StgCreateDocfileOnILockBytes(*param_2,0x1012,0,param_1);
      return HVar1;
    }
  }
  return HVar1;
}

/* ---- FUNC 0003E270 FUN_18003e270 (720 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_18003e270(longlong *param_1,longlong *param_2,undefined *param_3)

{
  short sVar1;
  void *pvVar2;
  longlong *plVar3;
  int iVar4;
  ulonglong uVar5;
  uint uVar6;
  void *pvVar7;
  longlong *plVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  undefined1 auStack_278 [32];
  ulonglong local_258;
  longlong **local_250;
  longlong **local_248;
  int local_238 [2];
  longlong *local_230;
  longlong *local_228;
  longlong *plStack_220;
  longlong local_218;
  undefined8 local_210;
  short local_208 [10];
  wchar_t local_1f4 [38];
  wchar_t local_1a8 [40];
  undefined1 local_158 [272];
  ulonglong local_48;
  
  local_48 = DAT_1800791f8 ^ (ulonglong)auStack_278;
  uVar10 = 0;
  local_210 = 0;
  local_228 = (longlong *)0x0;
  plStack_220 = (longlong *)0x0;
  local_218 = 0;
  local_230 = (longlong *)0x0;
  FUN_18003ec30((longlong *)&local_228,param_2);
  iVar4 = (*(code *)param_3)(&local_210,local_158,0x104,local_238);
  uVar9 = uVar10;
  while (iVar4 != 0) {
    uVar6 = 0;
    uVar5 = uVar10;
    for (plVar8 = local_228; plVar8 != plStack_220; plVar8 = plVar8 + 5) {
      uVar6 = *(uint *)((longlong)plVar8 + 0x24);
      if ((int)*(uint *)((longlong)plVar8 + 0x24) < (int)(uint)uVar5) {
        uVar6 = (uint)uVar5;
      }
      uVar5 = (ulonglong)uVar6;
    }
    FUN_18003e780((longlong *)&local_228,local_158,local_238[0],uVar6 + 1);
    uVar5 = uVar10;
    do {
      sVar1 = *(short *)((longlong)L"Embedding " + uVar5);
      *(short *)((longlong)local_208 + uVar5) = sVar1;
      uVar5 = uVar5 + 2;
    } while (sVar1 != 0);
    _itow(local_238[0],local_1f4,10);
    if (local_230 == (longlong *)0x0) {
      local_248 = &local_230;
      local_250 = (longlong **)((ulonglong)local_250 & 0xffffffff00000000);
      local_258 = 0;
      iVar4 = (**(code **)(*param_1 + 0x30))(param_1,L"CalcExcel",0,0x12);
      if (iVar4 < 0) {
        local_250 = &local_230;
        local_258 = local_258 & 0xffffffff00000000;
        iVar4 = (**(code **)(*param_1 + 0x28))(param_1,L"CalcExcel",0x12);
      }
      if (local_230 != (longlong *)0x0) goto LAB_18003e3cf;
    }
    else {
LAB_18003e3cf:
      _itow(uVar6 + 1,local_1a8,10);
      local_258 = local_258 & 0xffffffff00000000;
      iVar4 = (**(code **)(*param_1 + 0x40))(param_1,local_208,local_230,local_1a8);
    }
    if (-1 < iVar4) {
      uVar9 = 1;
    }
    iVar4 = (*(code *)param_3)(&local_210,local_158,0x104,local_238);
  }
  if (local_230 != (longlong *)0x0) {
    (**(code **)(*local_230 + 0x10))();
  }
  if (local_228 != plStack_220) {
    FUN_18003ee30((longlong *)&local_228,param_1);
  }
  plVar3 = plStack_220;
  plVar8 = local_228;
  if (local_228 != (longlong *)0x0) {
    for (; plVar8 != plVar3; plVar8 = plVar8 + 5) {
      if (0xf < (ulonglong)plVar8[3]) {
        pvVar2 = (void *)*plVar8;
        pvVar7 = pvVar2;
        if ((0xfff < plVar8[3] + 1U) &&
           (pvVar7 = *(void **)((longlong)pvVar2 + -8),
           0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)pvVar7)))) goto LAB_18003e504;
        operator_delete(pvVar7);
      }
      plVar8[2] = 0;
      plVar8[3] = 0xf;
      *(undefined1 *)plVar8 = 0;
    }
    plVar8 = local_228;
    if ((0xfff < (ulonglong)(((local_218 - (longlong)local_228) / 0x28) * 0x28)) &&
       (plVar8 = (longlong *)local_228[-1],
       (undefined1 *)0x1f < (undefined1 *)((longlong)local_228 + (-8 - (longlong)plVar8)))) {
LAB_18003e504:
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(plVar8);
  }
  return uVar9;
}

/* ---- FUNC 0003E540 FUN_18003e540 (40 bytes) ---- */

bool FUN_18003e540(wchar_t *param_1)

{
  int iVar1;
  
  iVar1 = wcsncmp(L"Embedding ",param_1,10);
  return iVar1 == 0;
}

/* ---- FUNC 0003E570 FUN_18003e570 (40 bytes) ---- */

bool FUN_18003e570(wchar_t *param_1)

{
  int iVar1;
  
  iVar1 = wcsncmp(L"PFSEmbedding",param_1,0xc);
  return iVar1 == 0;
}

/* ---- FUNC 0003E5A0 FUN_18003e5a0 (43 bytes) ---- */

void FUN_18003e5a0(longlong *param_1,longlong param_2,longlong param_3,longlong param_4)

{
  undefined8 *puVar1;
  void *pvVar2;
  undefined8 *puVar3;
  void *pvVar4;
  
  puVar3 = (undefined8 *)*param_1;
  if (puVar3 != (undefined8 *)0x0) {
    puVar1 = (undefined8 *)param_1[1];
    for (; puVar3 != puVar1; puVar3 = puVar3 + 10) {
      if ((LPVOID)*puVar3 != (LPVOID)0x0) {
        CoTaskMemFree((LPVOID)*puVar3);
      }
      *puVar3 = 0;
    }
    pvVar2 = (void *)*param_1;
    pvVar4 = pvVar2;
    if ((0xfff < (ulonglong)(((param_1[2] - (longlong)pvVar2) / 0x50) * 0x50)) &&
       (pvVar4 = *(void **)((longlong)pvVar2 + -8),
       0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)pvVar4)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar4);
  }
  *param_1 = param_2;
  param_1[1] = param_3 * 0x50 + param_2;
  param_1[2] = param_4 * 0x50 + param_2;
  return;
}

/* ---- FUNC 0003E5CB FUN_18003e5cb (14 bytes) ---- */

void FUN_18003e5cb(longlong param_1)

{
  undefined8 *puVar1;
  void *pvVar2;
  undefined8 *unaff_RBX;
  longlong unaff_RBP;
  longlong *unaff_RSI;
  void *pvVar3;
  longlong unaff_R14;
  longlong unaff_R15;
  
  puVar1 = *(undefined8 **)(param_1 + 8);
  for (; unaff_RBX != puVar1; unaff_RBX = unaff_RBX + 10) {
    if ((LPVOID)*unaff_RBX != (LPVOID)0x0) {
      CoTaskMemFree((LPVOID)*unaff_RBX);
    }
    *unaff_RBX = 0;
  }
  pvVar2 = (void *)*unaff_RSI;
  pvVar3 = pvVar2;
  if ((0xfff < (ulonglong)(((unaff_RSI[2] - (longlong)pvVar2) / 0x50) * 0x50)) &&
     (pvVar3 = *(void **)((longlong)pvVar2 + -8),
     0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)pvVar3)))) {
                    /* WARNING: Subroutine does not return */
    _invalid_parameter_noinfo_noreturn();
  }
  operator_delete(pvVar3);
  *unaff_RSI = unaff_RBP;
  unaff_RSI[1] = unaff_R15 * 0x50 + unaff_RBP;
  unaff_RSI[2] = unaff_R14 * 0x50 + unaff_RBP;
  return;
}

/* ---- FUNC 0003E5D9 FUN_18003e5d9 (39 bytes) ---- */

void FUN_18003e5d9(void)

{
  void *pvVar1;
  undefined8 *unaff_RBX;
  longlong unaff_RBP;
  longlong *unaff_RSI;
  undefined8 *unaff_RDI;
  void *pvVar2;
  longlong unaff_R14;
  longlong unaff_R15;
  
  do {
    if ((LPVOID)*unaff_RBX != (LPVOID)0x0) {
      CoTaskMemFree((LPVOID)*unaff_RBX);
    }
    *unaff_RBX = 0;
    unaff_RBX = unaff_RBX + 10;
  } while (unaff_RBX != unaff_RDI);
  pvVar1 = (void *)*unaff_RSI;
  pvVar2 = pvVar1;
  if ((0xfff < (ulonglong)(((unaff_RSI[2] - (longlong)pvVar1) / 0x50) * 0x50)) &&
     (pvVar2 = *(void **)((longlong)pvVar1 + -8),
     0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar2)))) {
                    /* WARNING: Subroutine does not return */
    _invalid_parameter_noinfo_noreturn();
  }
  operator_delete(pvVar2);
  *unaff_RSI = unaff_RBP;
  unaff_RSI[1] = unaff_R15 * 0x50 + unaff_RBP;
  unaff_RSI[2] = unaff_R14 * 0x50 + unaff_RBP;
  return;
}

/* ---- FUNC 0003E600 FUN_18003e600 (59 bytes) ---- */

void FUN_18003e600(void)

{
  void *pvVar1;
  longlong unaff_RBP;
  longlong *unaff_RSI;
  void *pvVar2;
  longlong unaff_R14;
  longlong unaff_R15;
  
  pvVar1 = (void *)*unaff_RSI;
  pvVar2 = pvVar1;
  if ((0xfff < (ulonglong)(((unaff_RSI[2] - (longlong)pvVar1) / 0x50) * 0x50)) &&
     (pvVar2 = *(void **)((longlong)pvVar1 + -8),
     0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar2)))) {
                    /* WARNING: Subroutine does not return */
    _invalid_parameter_noinfo_noreturn();
  }
  operator_delete(pvVar2);
  *unaff_RSI = unaff_RBP;
  unaff_RSI[1] = unaff_R15 * 0x50 + unaff_RBP;
  unaff_RSI[2] = unaff_R14 * 0x50 + unaff_RBP;
  return;
}

/* ---- FUNC 0003E63B FUN_18003e63b (91 bytes) ---- */

void FUN_18003e63b(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  longlong unaff_RBP;
  longlong *unaff_RSI;
  longlong unaff_R14;
  longlong unaff_R15;
  
  if ((param_3 - (longlong)*(void **)(param_3 + -8)) - 8U < 0x20) {
    operator_delete(*(void **)(param_3 + -8));
    *unaff_RSI = unaff_RBP;
    unaff_RSI[1] = unaff_R15 * 0x50 + unaff_RBP;
    unaff_RSI[2] = unaff_R14 * 0x50 + unaff_RBP;
    return;
  }
                    /* WARNING: Subroutine does not return */
  _invalid_parameter_noinfo_noreturn();
}

/* ---- FUNC 0003E6A0 FUN_18003e6a0 (208 bytes) ---- */

void FUN_18003e6a0(longlong *param_1,ulonglong param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong *plVar4;
  __uint64 _Var5;
  longlong *plVar6;
  longlong *plVar7;
  
  lVar1 = param_1[1];
  lVar2 = *param_1;
  if (0x333333333333333 < param_2) {
                    /* WARNING: Subroutine does not return */
    FUN_18000ac70();
  }
  _Var5 = param_2 * 0x50;
  if (_Var5 < 0x1000) {
    if (_Var5 == 0) {
      plVar4 = (longlong *)0x0;
    }
    else {
      plVar4 = operator_new(_Var5);
    }
  }
  else {
    plVar4 = (longlong *)FUN_180007f10(_Var5);
  }
  plVar3 = (longlong *)param_1[1];
  plVar7 = plVar4;
  for (plVar6 = (longlong *)*param_1; plVar6 != plVar3; plVar6 = plVar6 + 10) {
    FUN_18003de90(plVar7,plVar6);
    plVar7 = plVar7 + 10;
  }
  FUN_18003e5a0(param_1,(longlong)plVar4,(lVar1 - lVar2) / 0x50,param_2);
  return;
}

/* ---- FUNC 0003E780 FUN_18003e780 (924 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Type propagation algorithm not settling */

undefined8 FUN_18003e780(longlong *param_1,void *param_2,undefined4 param_3,undefined4 param_4)

{
  longlong *plVar1;
  ulonglong uVar2;
  longlong *plVar3;
  void *pvVar4;
  undefined8 *******pppppppuVar5;
  ulonglong uVar6;
  int iVar7;
  ulonglong uVar8;
  longlong *plVar9;
  void *pvVar10;
  undefined8 ******ppppppuVar11;
  undefined8 *******pppppppuVar12;
  ulonglong uVar13;
  size_t sVar14;
  ulonglong _Size;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined1 auStack_f8 [32];
  undefined1 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  longlong *local_c8;
  longlong *local_c0;
  undefined4 local_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  ulonglong local_a8;
  ulonglong uStack_a0;
  undefined4 local_98;
  undefined4 local_94;
  undefined8 local_90;
  undefined8 uStack_88;
  ulonglong local_80;
  ulonglong uStack_78;
  undefined4 local_70;
  undefined4 local_6c;
  undefined8 *******local_68;
  undefined8 uStack_60;
  ulonglong local_58;
  ulonglong local_50;
  ulonglong local_48;
  
  local_48 = DAT_1800791f8 ^ (ulonglong)auStack_f8;
  local_68 = (undefined8 *******)0x0;
  uStack_60 = 0;
  local_58 = 0;
  local_50 = 0;
  sVar14 = 0xffffffffffffffff;
  do {
    sVar14 = sVar14 + 1;
  } while (*(char *)((longlong)param_2 + sVar14) != '\0');
  local_d4 = param_3;
  local_d0 = param_4;
  local_c8 = param_1;
  FUN_18000b5f0(&local_68,param_2,sVar14);
  uVar6 = local_58;
  pppppppuVar5 = local_68;
  plVar1 = (longlong *)*param_1;
  uVar13 = (param_1[1] - (longlong)plVar1) / 0x28;
joined_r0x00018003e817:
  do {
    uVar8 = uVar13;
    if ((longlong)uVar8 < 1) {
      local_90 = (undefined8 ******)0x0;
      uStack_88 = (undefined8 ******)0x0;
      local_80 = 0;
      uStack_78 = 0;
      pppppppuVar12 = &local_68;
      if (0xf < local_50) {
        pppppppuVar12 = pppppppuVar5;
      }
      if (0x7fffffffffffffff < uVar6) {
                    /* WARNING: Subroutine does not return */
        FUN_18000ace0();
      }
      uVar13 = 0xf;
      if (uVar6 < 0x10) {
        local_80 = uVar6;
        uStack_78 = 0xf;
        local_90 = *pppppppuVar12;
        uStack_88 = pppppppuVar12[1];
        uVar15 = *(undefined4 *)pppppppuVar12;
        uVar16 = *(undefined4 *)((longlong)pppppppuVar12 + 4);
        uVar17 = *(undefined4 *)(pppppppuVar12 + 1);
        uVar18 = *(undefined4 *)((longlong)pppppppuVar12 + 0xc);
      }
      else {
        uVar8 = uVar6 | 0xf;
        if (uVar8 < 0x8000000000000000) {
          if (uVar8 < 0x16) {
            uVar8 = 0x16;
          }
          uVar2 = uVar8 + 1;
          if (uVar2 < 0x1000) {
            if (uVar2 == 0) {
              local_90 = (undefined8 ******)0x0;
            }
            else {
              local_90 = operator_new(uVar2);
            }
          }
          else {
            local_90 = (undefined8 ******)FUN_180007f10(uVar2);
          }
        }
        else {
          local_90 = (undefined8 ******)FUN_180007f10(0x8000000000000000);
          uVar8 = 0x7fffffffffffffff;
        }
        local_80 = uVar6;
        uStack_78 = uVar8;
        memcpy(local_90,pppppppuVar12,uVar6 + 1);
        uVar15 = (undefined4)local_90;
        uVar16 = local_90._4_4_;
        uVar17 = (undefined4)uStack_88;
        uVar18 = uStack_88._4_4_;
      }
      local_70 = local_d4;
      local_6c = local_d0;
      plVar3 = (longlong *)param_1[1];
      if (plVar3 == (longlong *)param_1[2]) {
        FUN_18003c4d0(param_1,plVar1,&local_90);
        uVar13 = uStack_78;
      }
      else {
        local_90 = (undefined8 ******)((ulonglong)local_90 & 0xffffffffffffff00);
        if (plVar1 == plVar3) {
          *(undefined4 *)plVar3 = uVar15;
          *(undefined4 *)((longlong)plVar3 + 4) = uVar16;
          *(undefined4 *)(plVar3 + 1) = uVar17;
          *(undefined4 *)((longlong)plVar3 + 0xc) = uVar18;
          plVar3[2] = local_80;
          plVar3[3] = uStack_78;
          *(undefined4 *)(plVar3 + 4) = local_d4;
          *(undefined4 *)((longlong)plVar3 + 0x24) = local_d0;
          param_1[1] = param_1[1] + 0x28;
        }
        else {
          local_a8 = local_80;
          uStack_a0 = uStack_78;
          local_98 = local_d4;
          local_94 = local_d0;
          plVar9 = plVar3 + -5;
          *plVar3 = *plVar9;
          plVar3[1] = plVar3[-4];
          plVar3[2] = plVar3[-3];
          plVar3[3] = plVar3[-2];
          plVar3[-3] = 0;
          plVar3[-2] = 0xf;
          *(undefined1 *)plVar9 = 0;
          *(int *)(plVar3 + 4) = (int)plVar3[-1];
          *(undefined4 *)((longlong)plVar3 + 0x24) = *(undefined4 *)((longlong)plVar3 + -4);
          param_1[1] = param_1[1] + 0x28;
          local_c0 = param_1;
          local_b8 = uVar15;
          uStack_b4 = uVar16;
          uStack_b0 = uVar17;
          uStack_ac = uVar18;
          FUN_18003cef0(plVar1,plVar9,plVar3);
          FUN_18003dfd0(plVar1,(longlong *)&local_b8);
          *(undefined4 *)(plVar1 + 4) = local_98;
          *(undefined4 *)((longlong)plVar1 + 0x24) = local_94;
          if (0xf < uStack_a0) {
            pvVar4 = (void *)CONCAT44(uStack_b4,local_b8);
            pvVar10 = pvVar4;
            if ((0xfff < uStack_a0 + 1) &&
               (pvVar10 = *(void **)((longlong)pvVar4 + -8),
               0x1f < (ulonglong)((longlong)pvVar4 + (-8 - (longlong)pvVar10)))) {
                    /* WARNING: Subroutine does not return */
              _invalid_parameter_noinfo_noreturn();
            }
            operator_delete(pvVar10);
          }
        }
      }
      if (0xf < uVar13) {
        ppppppuVar11 = local_90;
        if ((0xfff < uVar13 + 1) &&
           (ppppppuVar11 = (undefined8 ******)local_90[-1],
           0x1f < (ulonglong)((longlong)local_90 + (-8 - (longlong)ppppppuVar11)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        operator_delete(ppppppuVar11);
      }
      FUN_18003da60((void **)*param_1,(void **)param_1[1],(param_1[1] - *param_1) / 0x28,local_d8);
      if (0xf < local_50) {
        pppppppuVar12 = pppppppuVar5;
        if ((0xfff < local_50 + 1) &&
           (pppppppuVar12 = (undefined8 *******)pppppppuVar5[-1],
           0x1f < (ulonglong)((longlong)pppppppuVar5 + (-8 - (longlong)pppppppuVar12)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        operator_delete(pppppppuVar12);
      }
      return 0;
    }
    uVar13 = uVar8 >> 1;
    plVar3 = plVar1 + uVar13 * 5;
    pppppppuVar12 = &local_68;
    if (0xf < local_50) {
      pppppppuVar12 = pppppppuVar5;
    }
    plVar9 = plVar3;
    if (0xf < (ulonglong)plVar3[3]) {
      plVar9 = (longlong *)*plVar3;
    }
    uVar2 = plVar3[2];
    _Size = uVar2;
    if (uVar6 < uVar2) {
      _Size = uVar6;
    }
    iVar7 = memcmp(plVar9,pppppppuVar12,_Size);
    param_1 = local_c8;
    if (iVar7 == 0) goto LAB_18003e8bc;
  } while (-1 < iVar7);
  goto LAB_18003e8c1;
LAB_18003e8bc:
  if (uVar2 < uVar6) {
LAB_18003e8c1:
    plVar1 = plVar3 + 5;
    uVar13 = uVar8 + (-1 - uVar13);
  }
  goto joined_r0x00018003e817;
}

/* ---- FUNC 0003EB20 FUN_18003eb20 (109 bytes) ---- */

uint FUN_18003eb20(undefined8 *param_1,undefined8 *param_2)

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
      return 0xffffffff;
    }
    uVar3 = (uint)(uVar1 < uVar2);
  }
  return uVar3;
}

/* ---- FUNC 0003EB90 deallocate (66 bytes) ---- */

/* Library Function - Multiple Matches With Same Base Name
    public: void __cdecl std::allocator<struct `protected: int __cdecl GSI1::readHash(unsigned
   short,long,long) __ptr64'::`2'::FileSymbolInfo>::deallocate(struct `protected: int __cdecl
   GSI1::readHash(unsigned short,long,long) __ptr64'::`2'::FileSymbolInfo * __ptr64 const,unsigned
   __int64) __ptr64
    public: void __cdecl std::allocator<struct GSISymbolEntry>::deallocate(struct GSISymbolEntry *
   __ptr64 const,unsigned __int64) __ptr64
   
   Library: Visual Studio 2019 Release */

void deallocate(undefined8 param_1,void *param_2,longlong param_3)

{
  void *pvVar1;
  
  pvVar1 = param_2;
  if ((0xfff < (ulonglong)(param_3 * 0x28)) &&
     (pvVar1 = *(void **)((longlong)param_2 + -8),
     0x1f < (ulonglong)((longlong)param_2 + (-8 - (longlong)pvVar1)))) {
                    /* WARNING: Subroutine does not return */
    _invalid_parameter_noinfo_noreturn();
  }
  operator_delete(pvVar1);
  return;
}

/* ---- FUNC 0003EBE0 deallocate (66 bytes) ---- */

/* Library Function - Multiple Matches With Same Base Name
    public: void __cdecl std::allocator<struct `protected: int __cdecl GSI1::readHash(unsigned
   short,long,long) __ptr64'::`2'::FileSymbolInfo>::deallocate(struct `protected: int __cdecl
   GSI1::readHash(unsigned short,long,long) __ptr64'::`2'::FileSymbolInfo * __ptr64 const,unsigned
   __int64) __ptr64
    public: void __cdecl std::allocator<struct GSISymbolEntry>::deallocate(struct GSISymbolEntry *
   __ptr64 const,unsigned __int64) __ptr64
   
   Library: Visual Studio 2019 Release */

void deallocate(undefined8 param_1,void *param_2,longlong param_3)

{
  void *pvVar1;
  
  pvVar1 = param_2;
  if ((0xfff < (ulonglong)(param_3 * 0x50)) &&
     (pvVar1 = *(void **)((longlong)param_2 + -8),
     0x1f < (ulonglong)((longlong)param_2 + (-8 - (longlong)pvVar1)))) {
                    /* WARNING: Subroutine does not return */
    _invalid_parameter_noinfo_noreturn();
  }
  operator_delete(pvVar1);
  return;
}

/* ---- FUNC 0003EC30 FUN_18003ec30 (133 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_18003ec30(longlong *param_1,longlong *param_2)

{
  uint uVar1;
  int iVar2;
  ulonglong uVar3;
  undefined1 auStack_578 [32];
  ulonglong local_558;
  longlong **local_550;
  longlong **local_548;
  uint local_538;
  uint local_534;
  longlong *local_530;
  undefined4 local_528;
  undefined4 local_524;
  longlong *local_520;
  undefined1 local_518 [256];
  undefined1 local_418 [1008];
  ulonglong local_28;
  
  local_28 = DAT_1800791f8 ^ (ulonglong)auStack_578;
  local_520 = (longlong *)0x0;
  local_548 = &local_520;
  local_550 = (longlong **)((ulonglong)local_550 & 0xffffffff00000000);
  local_558 = 0;
  uVar3 = (**(code **)(*param_2 + 0x30))(param_2,L"CalcExcel",0,0x10);
  if (-1 < (int)uVar3) {
    local_550 = &local_530;
    local_530 = (longlong *)0x0;
    local_558 = local_558 & 0xffffffff00000000;
    uVar1 = (**(code **)(*local_520 + 0x20))(local_520,L"CONTENTS",0,0x10);
    uVar3 = (ulonglong)uVar1;
    if (-1 < (int)uVar1) {
      iVar2 = (**(code **)(*local_530 + 0x18))(local_530,&local_534,4,&local_538);
      if (iVar2 == 0) {
        while (local_538 == 4) {
          if (0xff < local_534) {
            FUN_180007de0(local_418,"Assert failed in file %s line %d",
                          "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\stgutil.cpp",0x5a0);
            LogMessage(local_418,2,1);
          }
          uVar1 = local_534;
          iVar2 = (**(code **)(*local_530 + 0x18))(local_530,local_518,local_534,&local_538);
          if ((iVar2 != 0) || (local_538 != uVar1)) break;
          iVar2 = (**(code **)(*local_530 + 0x18))(local_530,&local_524,4,&local_538);
          if ((iVar2 != 0) || (local_538 != 4)) break;
          iVar2 = (**(code **)(*local_530 + 0x18))(local_530,&local_528,4,&local_538);
          if ((iVar2 != 0) || (local_538 != 4)) break;
          FUN_18003e780(param_1,local_518,local_524,local_528);
          iVar2 = (**(code **)(*local_530 + 0x18))(local_530,&local_534,4,&local_538);
          if (iVar2 != 0) break;
        }
      }
      (**(code **)(*local_530 + 0x10))();
    }
    (**(code **)(*local_520 + 0x10))();
  }
  return uVar3;
}

/* ---- FUNC 0003ECB5 FUN_18003ecb5 (345 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_18003ecb5(longlong *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int unaff_EBX;
  longlong unaff_RBP;
  longlong *unaff_RSI;
  uint uStack0000000000000040;
  uint uStack0000000000000044;
  longlong *in_stack_00000048;
  undefined4 uStack0000000000000050;
  undefined4 uStack0000000000000054;
  longlong *in_stack_00000058;
  
  iVar2 = (**(code **)(*param_1 + 0x20))();
  if (-1 < iVar2) {
    iVar3 = (**(code **)(*in_stack_00000048 + 0x18))
                      (in_stack_00000048,(longlong)&stack0x00000040 + 4,unaff_EBX + 4,
                       &stack0x00000040);
    if (iVar3 == 0) {
      while (uStack0000000000000040 == 4) {
        if (0xff < uStack0000000000000044) {
          FUN_180007de0(unaff_RBP + 0x60,"Assert failed in file %s line %d",
                        "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\stgutil.cpp",0x5a0);
          LogMessage(unaff_RBP + 0x60,2,1);
        }
        uVar1 = uStack0000000000000044;
        iVar3 = (**(code **)(*in_stack_00000048 + 0x18))
                          (in_stack_00000048,&stack0x00000060,uStack0000000000000044,
                           &stack0x00000040);
        if ((iVar3 != 0) || (uStack0000000000000040 != uVar1)) break;
        iVar3 = (**(code **)(*in_stack_00000048 + 0x18))
                          (in_stack_00000048,(longlong)&stack0x00000050 + 4,4,&stack0x00000040);
        if ((iVar3 != 0) || (uStack0000000000000040 != 4)) break;
        iVar3 = (**(code **)(*in_stack_00000048 + 0x18))
                          (in_stack_00000048,&stack0x00000050,4,&stack0x00000040);
        if ((iVar3 != 0) || (uStack0000000000000040 != 4)) break;
        FUN_18003e780(unaff_RSI,&stack0x00000060,uStack0000000000000054,uStack0000000000000050);
        iVar3 = (**(code **)(*in_stack_00000048 + 0x18))
                          (in_stack_00000048,(longlong)&stack0x00000040 + 4,4,&stack0x00000040);
        if (iVar3 != 0) break;
      }
    }
    (**(code **)(*in_stack_00000048 + 0x10))();
  }
  (**(code **)(*in_stack_00000058 + 0x10))();
  return iVar2;
}

/* ---- FUNC 0003EE0E FUN_18003ee0e (26 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18003ee0e(void)

{
  return;
}

/* ---- FUNC 0003EE30 FUN_18003ee30 (158 bytes) ---- */

ulonglong FUN_18003ee30(longlong *param_1,longlong *param_2)

{
  undefined8 *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  int local_res10 [2];
  int local_res18 [2];
  longlong *local_res20;
  ulonglong uVar8;
  ulonglong in_stack_ffffffffffffffb0;
  longlong *local_38 [2];
  
  local_38[0] = (longlong *)0x0;
  uVar8 = 0;
  uVar5 = (**(code **)(*param_2 + 0x30))
                    (param_2,L"CalcExcel",0,0x12,0,in_stack_ffffffffffffffb0 & 0xffffffff00000000,
                     local_38);
  if ((int)uVar5 < 0) {
    uVar8 = uVar8 & 0xffffffff00000000;
    uVar5 = (**(code **)(*param_2 + 0x28))(param_2,L"CalcExcel",0x12,0,uVar8,local_38);
  }
  if ((local_38[0] != (longlong *)0x0) && ((int)uVar5 == 0)) {
    local_res20 = (longlong *)0x0;
    uVar2 = (**(code **)(*local_38[0] + 0x18))
                      (local_38[0],L"CONTENTS",0x1011,0,uVar8 & 0xffffffff00000000,&local_res20);
    uVar5 = (ulonglong)uVar2;
    if (-1 < (int)uVar2) {
      puVar7 = (undefined8 *)*param_1;
      puVar1 = (undefined8 *)param_1[1];
      if (puVar7 != puVar1) {
        while( true ) {
          local_res18[0] = *(int *)(puVar7 + 2) + 1;
          iVar3 = (**(code **)(*local_res20 + 0x20))(local_res20,local_res18,4,local_res10);
          iVar4 = local_res18[0];
          if ((iVar3 != 0) || (local_res10[0] != 4)) break;
          puVar6 = puVar7;
          if (0xf < (ulonglong)puVar7[3]) {
            puVar6 = (undefined8 *)*puVar7;
          }
          iVar3 = (**(code **)(*local_res20 + 0x20))(local_res20,puVar6,local_res18[0],local_res10);
          if ((((iVar3 != 0) || (local_res10[0] != iVar4)) ||
              (iVar4 = (**(code **)(*local_res20 + 0x20))(local_res20,puVar7 + 4,4,local_res10),
              iVar4 != 0)) ||
             (((local_res10[0] != 4 ||
               (iVar4 = (**(code **)(*local_res20 + 0x20))
                                  (local_res20,(longlong)puVar7 + 0x24,4,local_res10), iVar4 != 0))
              || ((local_res10[0] != 4 || (puVar7 = puVar7 + 5, puVar7 == puVar1)))))) break;
        }
      }
      (**(code **)(*local_res20 + 0x40))(local_res20,0);
      (**(code **)(*local_res20 + 0x10))();
    }
    (**(code **)(*local_38[0] + 0x10))();
  }
  return uVar5;
}

/* ---- FUNC 0003EECE FUN_18003eece (259 bytes) ---- */

int FUN_18003eece(void)

{
  undefined8 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  longlong in_RAX;
  undefined8 *puVar5;
  undefined8 *puVar6;
  longlong unaff_RBP;
  longlong *unaff_RDI;
  
  iVar2 = (**(code **)(in_RAX + 0x18))();
  if (-1 < iVar2) {
    puVar6 = (undefined8 *)*unaff_RDI;
    puVar1 = (undefined8 *)unaff_RDI[1];
    if (puVar6 != puVar1) {
      while( true ) {
        *(int *)(unaff_RBP + 0x38) = *(int *)(puVar6 + 2) + 1;
        iVar3 = (**(code **)(**(longlong **)(unaff_RBP + 0x40) + 0x20))
                          (*(longlong **)(unaff_RBP + 0x40),unaff_RBP + 0x38,4,unaff_RBP + 0x30);
        if ((iVar3 != 0) || (*(int *)(unaff_RBP + 0x30) != 4)) break;
        iVar3 = *(int *)(unaff_RBP + 0x38);
        puVar5 = puVar6;
        if (0xf < (ulonglong)puVar6[3]) {
          puVar5 = (undefined8 *)*puVar6;
        }
        iVar4 = (**(code **)(**(longlong **)(unaff_RBP + 0x40) + 0x20))
                          (*(longlong **)(unaff_RBP + 0x40),puVar5,iVar3,unaff_RBP + 0x30);
        if ((((iVar4 != 0) || (*(int *)(unaff_RBP + 0x30) != iVar3)) ||
            (iVar3 = (**(code **)(**(longlong **)(unaff_RBP + 0x40) + 0x20))
                               (*(longlong **)(unaff_RBP + 0x40),puVar6 + 4,4,unaff_RBP + 0x30),
            iVar3 != 0)) ||
           (((*(int *)(unaff_RBP + 0x30) != 4 ||
             (iVar3 = (**(code **)(**(longlong **)(unaff_RBP + 0x40) + 0x20))
                                (*(longlong **)(unaff_RBP + 0x40),(longlong)puVar6 + 0x24,4,
                                 unaff_RBP + 0x30), iVar3 != 0)) ||
            ((*(int *)(unaff_RBP + 0x30) != 4 || (puVar6 = puVar6 + 5, puVar6 == puVar1)))))) break;
      }
    }
    (**(code **)(**(longlong **)(unaff_RBP + 0x40) + 0x40))(*(longlong **)(unaff_RBP + 0x40),0);
    (**(code **)(**(longlong **)(unaff_RBP + 0x40) + 0x10))();
  }
  (**(code **)(**(longlong **)(unaff_RBP + -0x18) + 0x10))();
  return iVar2;
}

/* ---- FUNC 0003EFD1 FUN_18003efd1 (9 bytes) ---- */

void FUN_18003efd1(void)

{
  return;
}

/* ---- FUNC 0003EFE0 MMCommitEmbeddedItems (68 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int MMCommitEmbeddedItems(undefined *param_1,undefined *param_2)

{
  int iVar1;
  int iVar2;
  longlong *plVar3;
  ulonglong uVar4;
  undefined8 *puVar5;
  char *pcVar6;
  longlong lVar7;
  undefined1 auStack_478 [32];
  longlong local_458;
  int local_450 [2];
  longlong *local_448;
  longlong *local_440;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_438 [8];
  longlong *local_430;
  undefined1 local_428 [1008];
  ulonglong local_38;
  
                    /* 0x3efe0  373  MMCommitEmbeddedItems */
  local_38 = DAT_1800791f8 ^ (ulonglong)auStack_478;
  plVar3 = (longlong *)GetGlobalPointer("ApwnDocStorage");
  iVar2 = 0;
  if (plVar3 != (longlong *)0x0) {
    if (param_1 == (undefined *)0x0) {
      DAT_18007b83c = 0;
      MMEnumerateXLStorages(FUN_18003e060);
      uVar4 = (ulonglong)DAT_18007b83c;
    }
    else {
      uVar4 = FUN_18003e080(param_1);
      uVar4 = uVar4 & 0xffffffff;
    }
    iVar2 = (int)uVar4;
    puVar5 = (undefined8 *)GetGlobalPointer("HappNode");
    local_430 = (longlong *)0x0;
    iVar1 = (**(code **)*puVar5)(puVar5,&DAT_180056250,&local_430);
    if (-1 < iVar1) {
      local_440 = (longlong *)0x0;
      iVar1 = (**(code **)(*local_430 + 0x30))(local_430,&local_440);
      if (-1 < iVar1) {
        local_448 = (longlong *)0x0;
        local_450[0] = 0;
        (**(code **)(*local_440 + 0x18))(local_440,1,&local_448,local_450);
        while ((local_448 != (longlong *)0x0 && (iVar2 = (int)uVar4, local_450[0] != 0))) {
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_458);
          pcVar6 = ATL::CSimpleStringT<char,1>::GetBuffer
                             ((CSimpleStringT<char,1> *)&local_458,0x100);
          FUN_180019cf0(local_448,pcVar6);
          ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)&local_458,-1);
          if ((*(int *)(local_458 + -0x10) == 0) ||
             (iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                 &local_458,""), iVar2 == 0)) {
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_458,
                       "Root");
          }
          if (param_2 == (undefined *)0x0) {
LAB_18003f1c0:
            lVar7 = PostMainWndMessage(0x4e1,0,local_458);
            if (lVar7 != 0) {
              uVar4 = 1;
            }
          }
          else {
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_438);
            lVar7 = local_458;
            pcVar6 = ATL::CSimpleStringT<char,1>::GetBuffer
                               ((CSimpleStringT<char,1> *)local_438,0x100);
            iVar2 = (*(code *)param_2)(lVar7,pcVar6,0x100);
            ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)local_438,-1);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_438);
            if (iVar2 != 0) goto LAB_18003f1c0;
          }
          iVar2 = (int)uVar4;
          (**(code **)(*local_448 + 0x10))();
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_458);
          (**(code **)(*local_440 + 0x18))(local_440,1,&local_448,local_450);
        }
        (**(code **)(*local_440 + 0x10))();
      }
      (**(code **)(*local_430 + 0x10))();
    }
    if ((iVar2 != 0) && (iVar1 = (**(code **)(*plVar3 + 0x48))(plVar3,2), iVar1 < 0)) {
      FUN_180007de0(local_428,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\stgutil.cpp",0x21d);
      LogMessage(local_428,2,1);
    }
  }
  return iVar2;
}

/* ---- FUNC 0003F024 FUN_18003f024 (16 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_18003f024(void)

{
  int iVar1;
  int iVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  char *pcVar5;
  longlong lVar6;
  undefined *unaff_RBX;
  code *unaff_RSI;
  longlong *unaff_R14;
  longlong lStackX_20;
  int in_stack_00000028;
  longlong *in_stack_00000030;
  longlong *in_stack_00000038;
  longlong *in_stack_00000048;
  
  if (unaff_RBX == (undefined *)0x0) {
    DAT_18007b83c = 0;
    MMEnumerateXLStorages(FUN_18003e060);
    uVar3 = (ulonglong)DAT_18007b83c;
  }
  else {
    uVar3 = FUN_18003e080(unaff_RBX);
    uVar3 = uVar3 & 0xffffffff;
  }
  iVar2 = (int)uVar3;
  puVar4 = (undefined8 *)GetGlobalPointer("HappNode");
  in_stack_00000048 = (longlong *)0x0;
  iVar1 = (**(code **)*puVar4)(puVar4,&DAT_180056250,&stack0x00000048);
  if (-1 < iVar1) {
    in_stack_00000038 = (longlong *)0x0;
    iVar1 = (**(code **)(*in_stack_00000048 + 0x30))(in_stack_00000048,&stack0x00000038);
    if (-1 < iVar1) {
      in_stack_00000030 = (longlong *)0x0;
      in_stack_00000028 = 0;
      (**(code **)(*in_stack_00000038 + 0x18))
                (in_stack_00000038,1,&stack0x00000030,&stack0x00000028);
      while ((in_stack_00000030 != (longlong *)0x0 && (iVar2 = (int)uVar3, in_stack_00000028 != 0)))
      {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&lStackX_20);
        pcVar5 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)&lStackX_20,0x100)
        ;
        FUN_180019cf0(in_stack_00000030,pcVar5);
        ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)&lStackX_20,-1);
        if ((*(int *)(lStackX_20 + -0x10) == 0) ||
           (iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                               &lStackX_20,""), iVar2 == 0)) {
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&lStackX_20,
                     "Root");
        }
        if (unaff_RSI == (code *)0x0) {
LAB_18003f1c0:
          lVar6 = PostMainWndMessage(0x4e1,0,lStackX_20);
          if (lVar6 != 0) {
            uVar3 = 1;
          }
        }
        else {
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                     &stack0x00000040);
          lVar6 = lStackX_20;
          pcVar5 = ATL::CSimpleStringT<char,1>::GetBuffer
                             ((CSimpleStringT<char,1> *)&stack0x00000040,0x100);
          iVar2 = (*unaff_RSI)(lVar6,pcVar5,0x100);
          ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)&stack0x00000040,-1);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                     &stack0x00000040);
          if (iVar2 != 0) goto LAB_18003f1c0;
        }
        iVar2 = (int)uVar3;
        (**(code **)(*in_stack_00000030 + 0x10))();
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&lStackX_20);
        (**(code **)(*in_stack_00000038 + 0x18))
                  (in_stack_00000038,1,&stack0x00000030,&stack0x00000028);
      }
      (**(code **)(*in_stack_00000038 + 0x10))();
    }
    (**(code **)(*in_stack_00000048 + 0x10))();
  }
  if ((iVar2 != 0) && (iVar1 = (**(code **)(*unaff_R14 + 0x48))(), iVar1 < 0)) {
    FUN_180007de0(&stack0x00000050,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\stgutil.cpp",0x21d);
    LogMessage(&stack0x00000050,2,1);
  }
  return iVar2;
}

/* ---- FUNC 0003F034 FUN_18003f034 (511 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_18003f034(void)

{
  int iVar1;
  int iVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  char *pcVar5;
  longlong lVar6;
  undefined *unaff_RBX;
  code *unaff_RSI;
  longlong *unaff_R14;
  longlong lStackX_20;
  int in_stack_00000028;
  longlong *in_stack_00000030;
  longlong *in_stack_00000038;
  longlong *in_stack_00000048;
  
  if (unaff_RBX == (undefined *)0x0) {
    DAT_18007b83c = 0;
    MMEnumerateXLStorages(FUN_18003e060);
    uVar3 = (ulonglong)DAT_18007b83c;
  }
  else {
    uVar3 = FUN_18003e080(unaff_RBX);
    uVar3 = uVar3 & 0xffffffff;
  }
  iVar2 = (int)uVar3;
  puVar4 = (undefined8 *)GetGlobalPointer("HappNode");
  in_stack_00000048 = (longlong *)0x0;
  iVar1 = (**(code **)*puVar4)(puVar4,&DAT_180056250,&stack0x00000048);
  if (-1 < iVar1) {
    in_stack_00000038 = (longlong *)0x0;
    iVar1 = (**(code **)(*in_stack_00000048 + 0x30))(in_stack_00000048,&stack0x00000038);
    if (-1 < iVar1) {
      in_stack_00000030 = (longlong *)0x0;
      in_stack_00000028 = 0;
      (**(code **)(*in_stack_00000038 + 0x18))
                (in_stack_00000038,1,&stack0x00000030,&stack0x00000028);
      while ((in_stack_00000030 != (longlong *)0x0 && (iVar2 = (int)uVar3, in_stack_00000028 != 0)))
      {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&lStackX_20);
        pcVar5 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)&lStackX_20,0x100)
        ;
        FUN_180019cf0(in_stack_00000030,pcVar5);
        ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)&lStackX_20,-1);
        if ((*(int *)(lStackX_20 + -0x10) == 0) ||
           (iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                               &lStackX_20,""), iVar2 == 0)) {
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&lStackX_20,
                     "Root");
        }
        if (unaff_RSI == (code *)0x0) {
LAB_18003f1c0:
          lVar6 = PostMainWndMessage(0x4e1,0,lStackX_20);
          if (lVar6 != 0) {
            uVar3 = 1;
          }
        }
        else {
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                     &stack0x00000040);
          lVar6 = lStackX_20;
          pcVar5 = ATL::CSimpleStringT<char,1>::GetBuffer
                             ((CSimpleStringT<char,1> *)&stack0x00000040,0x100);
          iVar2 = (*unaff_RSI)(lVar6,pcVar5,0x100);
          ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)&stack0x00000040,-1);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                     &stack0x00000040);
          if (iVar2 != 0) goto LAB_18003f1c0;
        }
        iVar2 = (int)uVar3;
        (**(code **)(*in_stack_00000030 + 0x10))();
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&lStackX_20);
        (**(code **)(*in_stack_00000038 + 0x18))
                  (in_stack_00000038,1,&stack0x00000030,&stack0x00000028);
      }
      (**(code **)(*in_stack_00000038 + 0x10))();
    }
    (**(code **)(*in_stack_00000048 + 0x10))();
  }
  if ((iVar2 != 0) && (iVar1 = (**(code **)(*unaff_R14 + 0x48))(), iVar1 < 0)) {
    FUN_180007de0(&stack0x00000050,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\stgutil.cpp",0x21d);
    LogMessage(&stack0x00000050,2,1);
  }
  return iVar2;
}

/* ---- FUNC 0003F233 FUN_18003f233 (85 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_18003f233(void)

{
  int iVar1;
  undefined4 unaff_EDI;
  undefined4 unaff_R12D;
  longlong *unaff_R14;
  
  iVar1 = (**(code **)(*unaff_R14 + 0x48))();
  if (iVar1 < 0) {
    FUN_180007de0(&stack0x00000050,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\stgutil.cpp",0x21d);
    LogMessage(&stack0x00000050,2,unaff_R12D);
  }
  return unaff_EDI;
}

/* ---- FUNC 0003F288 FUN_18003f288 (28 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18003f288(void)

{
  return;
}

/* ---- FUNC 0003F2B0 FUN_18003f2b0 (23 bytes) ---- */

undefined8 FUN_18003f2b0(void)

{
  GetGlobalPointer("ApwnDocStorage");
  return 0;
}

/* ---- FUNC 0003F2D0 FUN_18003f2d0 (3215 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_18003f2d0(longlong *param_1,undefined *param_2,undefined *param_3,undefined *param_4,int param_5
             )

{
  longlong lVar1;
  wchar_t wVar2;
  code *pcVar3;
  longlong *plVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  HRESULT HVar10;
  uint uVar11;
  LCID LVar12;
  int iVar13;
  undefined4 uVar14;
  longlong lVar15;
  BSTR pwcsName;
  void *pvVar16;
  FILE *_File;
  char *pcVar17;
  undefined8 *****pppppuVar18;
  wchar_t *pwVar19;
  undefined8 *_Buf1;
  ulonglong uVar20;
  undefined8 *puVar21;
  undefined8 *****pppppuVar22;
  longlong *plVar23;
  undefined1 *puVar24;
  undefined1 *puVar25;
  ulonglong uVar26;
  undefined8 *****pppppuVar27;
  ulonglong uVar28;
  longlong lVar29;
  size_t sVar30;
  longlong *plVar32;
  longlong *_Src;
  undefined1 local_4a8 [32];
  undefined4 local_488;
  int local_458;
  int local_454;
  int local_450 [2];
  char *local_448;
  undefined4 local_440;
  longlong *local_438;
  longlong *local_430;
  char *local_428;
  code *local_420;
  longlong *local_418;
  int local_410 [2];
  longlong local_408;
  longlong *local_400;
  undefined4 local_3f8 [2];
  undefined8 local_3f0;
  longlong *local_3e8;
  longlong *local_3e0;
  undefined8 local_3d8;
  longlong *local_3d0;
  longlong *plStack_3c8;
  longlong *local_3c0;
  undefined8 local_3b8;
  code *local_3b0;
  undefined1 local_3a8 [8];
  wchar_t *local_3a0;
  code *local_398;
  undefined8 *local_390;
  undefined8 local_388;
  undefined8 local_380;
  undefined8 *local_378;
  undefined8 *puStack_370;
  undefined8 local_368;
  undefined8 ****local_360;
  ulonglong uStack_358;
  ulonglong local_350;
  ulonglong local_348;
  void *local_340;
  longlong lStack_338;
  longlong local_330;
  ulonglong uStack_328;
  undefined1 local_318 [8];
  BSTR pOStack_310;
  ulonglong local_308;
  undefined8 uStack_300;
  undefined8 local_2f8;
  undefined8 uStack_2f0;
  undefined8 local_2e8;
  BSTR pOStack_2e0;
  undefined8 local_2d8;
  undefined8 uStack_2d0;
  CLSID local_2c8;
  wchar_t local_2b8 [40];
  char local_268 [272];
  char local_158 [256];
  ulonglong local_58;
  size_t sVar31;
  
  puVar24 = local_4a8;
  local_58 = DAT_1800791f8 ^ (ulonglong)&local_458;
  pppppuVar27 = (undefined8 *****)0x0;
  local_440 = 0;
  local_3b8 = 0;
  local_420 = (code *)param_4;
  local_418 = param_1;
  local_3b0 = (code *)param_2;
  local_398 = (code *)param_3;
  lVar15 = GetGlobalPointer("ApwnDocStorage");
  uVar14 = 0;
  if (lVar15 != 0) {
    local_368 = 0;
    local_378 = (undefined8 *)0x0;
    puStack_370 = (undefined8 *)0x0;
    local_408 = lVar15;
    FUN_18003ec30((longlong *)&local_378,param_1);
    local_458 = -1;
    local_3c0 = (longlong *)0x0;
    local_488 = 0x104;
    local_3d0 = (longlong *)0x0;
    plStack_3c8 = (longlong *)0x0;
    iVar7 = (*local_3b0)(&local_3b8,local_450,local_410);
    iVar9 = local_410[0];
    plVar4 = local_3d0;
    plVar32 = plStack_3c8;
    puVar24 = local_4a8;
    while (local_3d0 = plVar4, plStack_3c8 = plVar32, iVar7 != 0) {
      puVar25 = puVar24;
      local_410[0] = iVar9;
      if (local_450[0] != -1) {
        pwVar19 = L"Embedding ";
        do {
          wVar2 = *pwVar19;
          *(wchar_t *)(puVar24 + -0x180057200 + (longlong)pwVar19) = wVar2;
          pwVar19 = pwVar19 + 1;
        } while (wVar2 != L'\0');
        local_448 = puVar24 + -0x10;
        *(undefined8 *)(puVar24 + -0x68) = 0x18003f403;
        _itow(iVar9,(wchar_t *)(puVar24 + 4),10);
        *(undefined8 *)(puVar24 + -0x68) = 0x18003f40c;
        local_454 = (*(code *)param_4)(local_268);
        puVar6 = puStack_370;
        iVar9 = local_450[0];
        iVar13 = -0x7fffbffb;
        puVar25 = puVar24 + -0x60;
        pcVar17 = puVar24 + -0x10;
        iVar7 = local_458;
        if (local_378 != puStack_370) {
          uVar20 = 0xffffffffffffffff;
          do {
            uVar26 = uVar20 + 1;
            lVar15 = uVar20 + 1;
            puVar21 = local_378;
            uVar20 = uVar26;
          } while (local_268[lVar15] != '\0');
LAB_18003f443:
          _Buf1 = puVar21;
          if (0xf < (ulonglong)puVar21[3]) {
            _Buf1 = (undefined8 *)*puVar21;
          }
          uVar20 = puVar21[2];
          uVar28 = uVar20;
          if (uVar26 < uVar20) {
            uVar28 = uVar26;
          }
          *(undefined8 *)(puVar24 + -0x68) = 0x18003f46a;
          iVar8 = memcmp(_Buf1,local_268,uVar28);
          pcVar17 = local_448;
          param_1 = local_418;
          lVar15 = local_408;
          iVar7 = local_458;
          if ((((iVar8 != 0) || (uVar20 < uVar26)) || (uVar20 != uVar26)) ||
             (iVar9 != *(int *)(puVar21 + 4))) goto LAB_18003f47f;
          iVar9 = *(int *)((longlong)puVar21 + 0x24);
          puVar25 = puVar24 + -0x60;
          if (0 < iVar9) {
            *(undefined8 *)(puVar24 + -0x68) = 0x18003f591;
            _itow(iVar9,local_2b8,10);
            param_1 = local_418;
            *(longlong ***)(puVar24 + -0x30) = &local_430;
            *(undefined4 *)(puVar24 + -0x38) = 0;
            local_430 = (longlong *)0x0;
            lVar15 = *param_1;
            *(undefined8 *)(puVar24 + -0x40) = 0;
            pcVar3 = *(code **)(lVar15 + 0x30);
            *(undefined8 *)(puVar24 + -0x68) = 0x18003f5c4;
            iVar13 = (*pcVar3)(param_1,L"CalcExcel",0);
            puVar25 = puVar24 + -0x60;
            pcVar17 = local_448;
            lVar15 = local_408;
            iVar7 = local_458;
            if (-1 < iVar13) {
              *(undefined8 *)(puVar24 + -0x68) = 0x18003f5da;
              pcVar17 = (char *)GetSorResStringEx(0xa817);
              *(undefined8 *)(puVar24 + -0x68) = 0x18003f5e7;
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_428
                         ,pcVar17);
              puVar25 = puVar24 + -0x60;
              iVar7 = local_458;
              if ((local_454 != 0) || (puVar25 = puVar24 + -0x60, param_5 != 0)) goto LAB_18003fc1a;
              *(undefined8 *)(puVar24 + -0x68) = 0x18003f601;
              iVar9 = GetPastingStatus();
              pcVar17 = local_428;
              puVar25 = puVar24 + -0x60;
              iVar7 = local_458;
              if (iVar9 != 0) goto LAB_18003fc1a;
              if (local_458 != 1) {
                if (local_458 == -1) {
                  *(undefined8 *)(puVar24 + -0x68) = 0x18003f628;
                  iVar9 = MMAfxMessageBox(pcVar17,4,-1,0);
                  if (iVar9 == 6) goto LAB_18003f638;
                }
                local_458 = 0;
                puVar25 = puVar24 + -0x60;
                iVar7 = local_458;
                goto LAB_18003fc1a;
              }
LAB_18003f638:
              plVar4 = local_430;
              *(longlong ***)(puVar24 + -0x30) = &local_3e8;
              local_3e8 = (longlong *)0x0;
              *(undefined4 *)(puVar24 + -0x38) = 0;
              lVar15 = *plVar4;
              local_458 = 1;
              *(undefined8 *)(puVar24 + -0x40) = 0;
              pcVar3 = *(code **)(lVar15 + 0x30);
              *(undefined8 *)(puVar24 + -0x68) = 0x18003f673;
              iVar9 = (*pcVar3)(plVar4,local_2b8,0,0x10);
              puVar25 = puVar24 + -0x60;
              iVar7 = 1;
              if (iVar9 < 0) goto LAB_18003fc1a;
              local_400 = (longlong *)0x0;
              puVar25 = puVar24 + -0x70;
              pppppuVar18 = (undefined8 *****)(puVar24 + -0x20);
              pppppuVar22 = pppppuVar27;
              if (pppppuVar18 != (undefined8 *****)0x0) {
                *(undefined4 *)(puVar24 + -0x48) = 8;
                *(undefined8 ******)(puVar24 + -0x50) = pppppuVar18;
                *(undefined2 *)pppppuVar18 = 0;
                *(undefined8 *)(puVar24 + -0x78) = 0x18003f6b8;
                iVar9 = MultiByteToWideChar(0,0,"Package",-1,*(LPWSTR *)(puVar24 + -0x50),
                                            *(int *)(puVar24 + -0x48));
                pppppuVar22 = pppppuVar18;
                if (iVar9 == 0) {
                  pppppuVar22 = pppppuVar27;
                }
              }
              plVar4 = local_3e8;
              *(longlong ***)(puVar24 + -0x48) = &local_400;
              *(undefined4 *)(puVar24 + -0x50) = 0;
              pcVar3 = *(code **)(*plVar4 + 0x20);
              *(undefined8 *)(puVar24 + -0x78) = 0x18003f6e6;
              iVar9 = (*pcVar3)(plVar4,pppppuVar22,0);
              *(undefined8 *)(puVar24 + -0x78) = 0x18003f6fc;
              memset(local_158,0,0x100);
              plVar4 = local_400;
              if (iVar9 < 0) {
                *(undefined8 *)(puVar24 + -0x78) = 0x18003f716;
                tmpnam_s(local_158,0x100);
                *(undefined8 *)(puVar24 + -0x78) = 0x18003f722;
                pwcsName = FUN_180047d90(local_158);
                *(longlong ***)(puVar24 + -0x38) = &local_3e0;
                *(undefined **)(puVar24 + -0x40) = &DAT_180057a88;
                *(undefined8 *)(puVar24 + -0x48) = 0;
                *(undefined8 *)(puVar24 + -0x50) = 0;
                *(undefined8 *)(puVar24 + -0x78) = 0x18003f756;
                HVar10 = StgCreateStorageEx(pwcsName,0x11012,5,0,*(STGOPTIONS **)(puVar24 + -0x50),
                                            *(PSECURITY_DESCRIPTOR *)(puVar24 + -0x48),
                                            *(IID **)(puVar24 + -0x40),*(void ***)(puVar24 + -0x38))
                ;
                plVar4 = local_3e8;
                if (-1 < HVar10) {
                  *(longlong **)(puVar24 + -0x50) = local_3e0;
                  pcVar3 = *(code **)(*plVar4 + 0x38);
                  *(undefined8 *)(puVar24 + -0x78) = 0x18003f77a;
                  (*pcVar3)(plVar4,0,0,0);
                  plVar4 = local_3e0;
                  pcVar3 = *(code **)(*local_3e0 + 0x48);
                  *(undefined8 *)(puVar24 + -0x78) = 0x18003f789;
                  (*pcVar3)(plVar4,2);
                  pcVar3 = *(code **)(*local_3e0 + 0x10);
                  *(undefined8 *)(puVar24 + -0x78) = 0x18003f793;
                  (*pcVar3)();
                }
              }
              else if (local_400 != (longlong *)0x0) {
                local_318 = (undefined1  [8])0x0;
                pOStack_310 = (BSTR)0x0;
                local_308 = 0;
                uStack_300 = 0;
                local_2f8 = 0;
                uStack_2f0 = 0;
                local_2e8 = 0;
                pOStack_2e0 = (BSTR)0x0;
                local_2d8 = 0;
                uStack_2d0 = 0;
                pcVar3 = *(code **)(*local_400 + 0x60);
                *(undefined8 *)(puVar24 + -0x78) = 0x18003f7db;
                (*pcVar3)(plVar4,local_318,1);
                uVar20 = local_308;
                iVar9 = (int)local_308;
                uVar26 = local_308 & 0xffffffff;
                uVar11 = (int)local_308 + 1;
                *(undefined8 *)(puVar24 + -0x78) = 0x18003f7ee;
                pvVar16 = operator_new__((ulonglong)uVar11);
                plVar4 = local_400;
                pcVar3 = *(code **)(*local_400 + 0x28);
                *(undefined8 *)(puVar24 + -0x78) = 0x18003f804;
                (*pcVar3)(plVar4,0,0,0);
                plVar4 = local_400;
                pcVar3 = *(code **)(*local_400 + 0x18);
                *(undefined8 *)(puVar24 + -0x78) = 0x18003f81b;
                (*pcVar3)(plVar4,pvVar16,uVar20 & 0xffffffff,local_3a8);
                if (iVar9 == 0) {
                  *(undefined8 *)(puVar24 + -0x78) = 0x18003f829;
                  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &local_428);
                  param_4 = local_420;
                  goto LAB_18003fce2;
                }
                *(undefined1 *)(uVar26 + (longlong)pvVar16) = 0;
                *(undefined8 *)(puVar24 + -0x78) = 0x18003f844;
                tmpnam_s(local_158,0x100);
                *(undefined8 *)(puVar24 + -0x78) = 0x18003f858;
                _File = fopen(local_158,"wb+");
                param_1 = local_418;
                if (_File != (FILE *)0x0) {
                  *(undefined8 *)(puVar24 + -0x78) = 0x18003f872;
                  fwrite(pvVar16,1,(ulonglong)uVar11,_File);
                  *(undefined8 *)(puVar24 + -0x78) = 0x18003f87b;
                  fclose(_File);
                  param_1 = local_418;
                }
              }
              *(undefined8 *)(puVar24 + -0x78) = 0x18003f893;
              HVar10 = CLSIDFromProgID(L"AspenTech.AspenPlus.SpreadsheetCalculator.410",&local_2c8);
              if (HVar10 < 0) {
                *(undefined8 *)(puVar24 + -0x78) = 0x18003f8a4;
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_3d8);
                *(undefined8 *)(puVar24 + -0x78) = 0x18003f8bf;
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_3d8,"MMCopyRestoreEmbeddedItems(): %ls not registered",
                           L"AspenTech.AspenPlus.SpreadsheetCalculator.410");
                uVar5 = local_3d8;
                *(undefined8 *)(puVar24 + -0x78) = 0x18003f8d2;
                LogMessage(uVar5,1,1);
                *(undefined8 *)(puVar24 + -0x78) = 0x18003f8df;
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_3d8);
                *(undefined8 *)(puVar24 + -0x78) = 0x18003f8e9;
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_428);
                param_4 = local_420;
                puVar25 = puVar24 + -0x70;
              }
              else {
                local_438 = (longlong *)0x0;
                *(longlong ***)(puVar24 + -0x50) = &local_438;
                *(undefined8 *)(puVar24 + -0x78) = 0x18003f914;
                uVar11 = CoCreateInstance(&local_2c8,(LPUNKNOWN)0x0,1,(IID *)&DAT_180057ac8,
                                          *(LPVOID **)(puVar24 + -0x50));
                if (((int)uVar11 < 0) || (local_438 == (longlong *)0x0)) {
                  *(undefined8 *)(puVar24 + -0x78) = 0x18003fbcc;
                  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &local_3f0);
                  *(undefined8 *)(puVar24 + -0x78) = 0x18003fbe7;
                  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &local_3f0,
                             "MMCopyRestoreEmbeddedItems(): Failed to create the instance of %ls. HR=%d"
                             ,L"AspenTech.AspenPlus.SpreadsheetCalculator.410",(ulonglong)uVar11);
                  uVar5 = local_3f0;
                  *(undefined8 *)(puVar24 + -0x78) = 0x18003fbf7;
                  LogMessage(uVar5,1,1);
                  *(undefined8 *)(puVar24 + -0x78) = 0x18003fc01;
                  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &local_3f0);
                  *(undefined8 *)(puVar24 + -0x78) = 0x18003fc0b;
                  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &local_428);
                  param_4 = local_420;
                  puVar25 = puVar24 + -0x70;
                }
                else {
                  local_3a0 = L"ConvertToSpreadsheet";
                  lVar15 = *local_438;
                  *(undefined8 *)(puVar24 + -0x78) = 0x18003f942;
                  LVar12 = GetUserDefaultLCID();
                  *(undefined4 **)(puVar24 + -0x48) = local_3f8;
                  plVar4 = local_438;
                  *(LCID *)(puVar24 + -0x50) = LVar12;
                  pcVar3 = *(code **)(lVar15 + 0x28);
                  *(undefined8 *)(puVar24 + -0x78) = 0x18003f967;
                  iVar9 = (*pcVar3)(plVar4,&DAT_180057ab8,&local_3a0,1);
                  if (-1 < iVar9) {
                    local_390 = (undefined8 *)local_318;
                    local_388 = 0;
                    local_380 = 3;
                    pppppuVar18 = pppppuVar27;
                    do {
                      *(undefined8 *)(puVar24 + -0x78) = 0x18003f9c7;
                      VariantInit((VARIANTARG *)(local_318 + (longlong)pppppuVar18 * 0x18));
                      uVar11 = (int)pppppuVar18 + 1;
                      pppppuVar18 = (undefined8 *****)(ulonglong)uVar11;
                    } while (uVar11 < (uint)local_380);
                    local_2e8 = CONCAT62(local_2e8._2_6_,8);
                    *(undefined8 *)(puVar24 + -0x78) = 0x18003f9e5;
                    pOStack_2e0 = FUN_180047d90(local_268);
                    local_2f8 = CONCAT44(local_2f8._4_4_,local_450[0]);
                    uStack_300 = CONCAT62(uStack_300._2_6_,3);
                    local_318._0_2_ = 8;
                    *(undefined8 *)(puVar24 + -0x78) = 0x18003fa10;
                    pOStack_310 = FUN_180047d90(local_158);
                    local_360 = (undefined8 ****)CONCAT62(local_360._2_6_,3);
                    lVar15 = *local_438;
                    *(undefined8 *)(puVar24 + -0x78) = 0x18003fa2b;
                    LVar12 = GetUserDefaultLCID();
                    uVar14 = local_3f8[0];
                    plVar4 = local_438;
                    *(undefined8 *)(puVar24 + -0x30) = 0;
                    *(undefined8 *)(puVar24 + -0x38) = 0;
                    *(undefined8 ******)(puVar24 + -0x40) = &local_360;
                    *(undefined8 ***)(puVar24 + -0x48) = &local_390;
                    *(undefined2 *)(puVar24 + -0x50) = 1;
                    pcVar3 = *(code **)(lVar15 + 0x30);
                    *(undefined8 *)(puVar24 + -0x78) = 0x18003fa67;
                    iVar7 = (*pcVar3)(plVar4,uVar14,&DAT_180057ab8,LVar12);
                    uVar20 = uStack_358;
                    iVar9 = (int)uStack_358;
                    pcVar3 = *(code **)(*local_438 + 0x10);
                    *(undefined8 *)(puVar24 + -0x78) = 0x18003fa79;
                    (*pcVar3)();
                    *(undefined8 *)(puVar24 + -0x78) = 0x18003fa86;
                    remove(local_158);
                    pcVar3 = local_398;
                    if ((-1 < iVar7) && (0 < iVar9)) {
                      *(undefined8 *)(puVar24 + -0x78) = 0x18003fa9d;
                      (*pcVar3)(local_268,uVar20 & 0xffffffff);
                      local_440 = 1;
                      pcVar3 = *(code **)(*local_430 + 0x10);
                      *(undefined8 *)(puVar24 + -0x78) = 0x18003faab;
                      (*pcVar3)();
                      *(undefined8 *)(puVar24 + -0x78) = 0x18003fab5;
                      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                 &local_428);
                      param_4 = local_420;
                      puVar25 = puVar24 + -0x70;
                      goto LAB_18003fce2;
                    }
                    pcVar3 = *(code **)(*local_430 + 0x10);
                    *(undefined8 *)(puVar24 + -0x78) = 0x18003fac4;
                    (*pcVar3)();
                    local_330 = 0;
                    local_340 = (void *)0x0;
                    lStack_338 = 0;
                    uStack_328 = 0;
                    sVar31 = 0xffffffffffffffff;
                    do {
                      sVar30 = sVar31 + 1;
                      lVar15 = sVar31 + 1;
                      sVar31 = sVar30;
                    } while (local_268[lVar15] != '\0');
                    *(undefined8 *)(puVar24 + -0x78) = 0x18003fb0c;
                    FUN_18000b5f0(&local_340,local_268,sVar30);
                    plVar4 = plStack_3c8;
                    if (plStack_3c8 == local_3c0) {
                      *(undefined8 *)(puVar24 + -0x78) = 0x18003fb54;
                      FUN_180008500((longlong *)&local_3d0,plVar4,&local_340);
                      if (0xf < uStack_328) {
                        pvVar16 = local_340;
                        if ((0xfff < uStack_328 + 1) &&
                           (pvVar16 = *(void **)((longlong)local_340 + -8),
                           0x1f < (ulonglong)((longlong)local_340 + (-8 - (longlong)pvVar16)))) {
                    /* WARNING: Subroutine does not return */
                          *(undefined **)(puVar24 + -0x78) = &UNK_18003fd1d;
                          _invalid_parameter_noinfo_noreturn();
                        }
                        *(undefined8 *)(puVar24 + -0x78) = 0x18003fb95;
                        operator_delete(pvVar16);
                      }
                    }
                    else {
                      *plStack_3c8 = (longlong)local_340;
                      plStack_3c8[1] = lStack_338;
                      plStack_3c8[2] = local_330;
                      plStack_3c8[3] = uStack_328;
                      plStack_3c8 = plStack_3c8 + 4;
                    }
                    lVar15 = *param_1;
                    *(longlong ***)(puVar24 + -0x40) = &local_430;
                    *(undefined4 *)(puVar24 + -0x48) = 0;
                    *(undefined8 *)(puVar24 + -0x50) = 0;
                    pcVar3 = *(code **)(lVar15 + 0x30);
                    *(undefined8 *)(puVar24 + -0x78) = 0x18003fbc0;
                    (*pcVar3)(param_1,L"CalcExcel",0,0x10);
                    puVar25 = puVar24 + -0x70;
                    iVar7 = 1;
LAB_18003fc1a:
                    lVar15 = local_408;
                    plVar4 = local_430;
                    pcVar17 = local_448;
                    *(undefined4 *)(puVar25 + 0x20) = 1;
                    pcVar3 = *(code **)(*plVar4 + 0x40);
                    *(undefined8 *)(puVar25 + -8) = 0x18003fc3e;
                    iVar13 = (*pcVar3)(plVar4,local_2b8,lVar15,pcVar17);
                    pcVar3 = *(code **)(*local_430 + 0x10);
                    *(undefined8 *)(puVar25 + -8) = 0x18003fc4b;
                    (*pcVar3)();
                    *(undefined8 *)(puVar25 + -8) = 0x18003fc55;
                    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                               &local_428);
                    goto LAB_18003f49b;
                  }
                  pcVar3 = *(code **)(*local_438 + 0x10);
                  *(undefined8 *)(puVar24 + -0x78) = 0x18003f975;
                  (*pcVar3)();
                  *(undefined8 *)(puVar24 + -0x78) = 0x18003f97f;
                  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &local_428);
                  param_4 = local_420;
                  puVar25 = puVar24 + -0x70;
                }
              }
              goto LAB_18003fce2;
            }
          }
        }
LAB_18003f49b:
        if ((iVar7 == 1) && (local_454 == 0)) {
LAB_18003fcc8:
          param_4 = local_420;
          if (iVar13 < 0) goto LAB_18003fce2;
        }
        else if (iVar13 < 0) {
          lVar1 = -1;
          do {
            lVar29 = lVar1;
            lVar1 = lVar29 + 1;
          } while (local_268[lVar29 + 1] != '\0');
          iVar9 = (int)(lVar29 + 1);
          puVar24 = puVar25;
          if (iVar9 != 0) {
            lVar1 = (longlong)iVar9 * 2;
            uVar20 = lVar1 + 0x25;
            if (uVar20 <= lVar1 + 0x16U) {
              uVar20 = 0xffffffffffffff0;
            }
            *(undefined8 *)(puVar25 + -8) = 0x18003f4fc;
            lVar1 = -(uVar20 & 0xfffffffffffffff0);
            puVar24 = puVar25 + lVar1;
            pwVar19 = L"CalcExcel ";
            do {
              wVar2 = *pwVar19;
              *(wchar_t *)((longlong)pwVar19 + (longlong)(puVar25 + lVar1 + -0x1800571b8)) = wVar2;
              pwVar19 = pwVar19 + 1;
            } while (wVar2 != L'\0');
            *(undefined8 *)(puVar25 + lVar1 + -8) = 0x18003f549;
            mbstowcs((wchar_t *)(puVar25 + lVar1 + 100),local_268,(longlong)((int)lVar29 + 2));
            lVar29 = *param_1;
            *(undefined4 *)(puVar25 + lVar1 + 0x20) = 1;
            pcVar3 = *(code **)(lVar29 + 0x40);
            *(undefined8 *)(puVar25 + lVar1 + -8) = 0x18003f566;
            iVar9 = (*pcVar3)(param_1,puVar25 + lVar1 + 0x50,lVar15,pcVar17);
            puVar25 = puVar25 + lVar1;
            if (-1 < iVar9) goto LAB_18003fcd3;
          }
          iVar9 = local_450[0];
          puVar25 = puVar24 + -0x60;
          pwVar19 = L"Embedding ";
          do {
            wVar2 = *pwVar19;
            *(wchar_t *)((longlong)pwVar19 + (longlong)(puVar24 + -0x180057200)) = wVar2;
            pwVar19 = pwVar19 + 1;
          } while (wVar2 != L'\0');
          *(undefined8 *)(puVar24 + -0x68) = 0x18003fca5;
          _itow(iVar9,(wchar_t *)(puVar24 + 4),10);
          lVar1 = *param_1;
          *(undefined4 *)(puVar24 + -0x40) = 1;
          pcVar3 = *(code **)(lVar1 + 0x40);
          *(undefined8 *)(puVar24 + -0x68) = 0x18003fcbc;
          iVar13 = (*pcVar3)(param_1,puVar24 + -0x10,lVar15,pcVar17);
          goto LAB_18003fcc8;
        }
LAB_18003fcd3:
        local_440 = 1;
        param_4 = local_420;
      }
LAB_18003fce2:
      *(undefined4 *)(puVar25 + 0x20) = 0x104;
      pcVar3 = local_3b0;
      *(undefined8 *)(puVar25 + -8) = 0x18003fd06;
      iVar7 = (*pcVar3)(&local_3b8,local_450,local_410);
      param_1 = local_418;
      lVar15 = local_408;
      iVar9 = local_410[0];
      plVar4 = local_3d0;
      plVar32 = plStack_3c8;
      puVar24 = puVar25;
    }
    if (plVar4 != plVar32) {
      *(undefined8 *)(puVar24 + -8) = 0x18003fd40;
      pcVar17 = (char *)GetSorResStringEx(0xa818);
      *(undefined8 *)(puVar24 + -8) = 0x18003fd4d;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_448,pcVar17
                );
      *(undefined8 *)(puVar24 + -8) = 0x18003fd5e;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::AppendFormat
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_448,"\n\n")
      ;
      plVar23 = plVar4;
      do {
        local_360 = (undefined8 ****)0x0;
        uStack_358 = 0;
        local_350 = 0;
        local_348 = 0;
        _Src = plVar23;
        if (0xf < (ulonglong)plVar23[3]) {
          _Src = (longlong *)*plVar23;
        }
        uVar20 = plVar23[2];
        if (0x7fffffffffffffff < uVar20) {
                    /* WARNING: Subroutine does not return */
          *(undefined **)(puVar24 + -8) = &UNK_18003ff5f;
          FUN_18000ace0();
        }
        local_348 = 0xf;
        if (uVar20 < 0x10) {
          local_360 = (undefined8 ****)*_Src;
          uStack_358 = _Src[1];
          pppppuVar18 = &local_360;
          local_350 = uVar20;
        }
        else {
          uVar26 = uVar20 | 0xf;
          if (uVar26 < 0x8000000000000000) {
            if (uVar26 < 0x16) {
              uVar26 = 0x16;
            }
            uVar28 = uVar26 + 1;
            if (uVar28 < 0x1000) {
              pppppuVar18 = pppppuVar27;
              if (uVar28 != 0) {
                *(undefined8 *)(puVar24 + -8) = 0x18003fe14;
                pppppuVar18 = operator_new(uVar28);
              }
            }
            else {
              *(undefined8 *)(puVar24 + -8) = 0x18003fe08;
              pppppuVar18 = (undefined8 *****)FUN_180007f10(uVar28);
            }
          }
          else {
            uVar26 = 0x7fffffffffffffff;
            *(undefined8 *)(puVar24 + -8) = 0x18003fdec;
            pppppuVar18 = (undefined8 *****)FUN_180007f10(0x8000000000000000);
          }
          local_360 = pppppuVar18;
          local_350 = uVar20;
          local_348 = uVar26;
          *(undefined8 *)(puVar24 + -8) = 0x18003fe3d;
          memcpy(pppppuVar18,_Src,uVar20 + 1);
          pppppuVar18 = &local_360;
          if (0xf < local_348) {
            pppppuVar18 = (undefined8 *****)local_360;
          }
        }
        *(undefined8 *)(puVar24 + -8) = 0x18003fe65;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::AppendFormat
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_448,"%s "
                   ,pppppuVar18);
        if (0xf < local_348) {
          pppppuVar18 = (undefined8 *****)local_360;
          if ((0xfff < local_348 + 1) &&
             (pppppuVar18 = (undefined8 *****)local_360[-1],
             0x1f < (ulonglong)((longlong)local_360 + (-8 - (longlong)pppppuVar18)))) {
                    /* WARNING: Subroutine does not return */
            *(undefined **)(puVar24 + -8) = &UNK_18003ff1f;
            _invalid_parameter_noinfo_noreturn();
          }
          *(undefined8 *)(puVar24 + -8) = 0x18003fea2;
          operator_delete(pppppuVar18);
        }
        pcVar17 = local_448;
        plVar23 = plVar23 + 4;
      } while (plVar23 != plVar32);
      *(undefined8 *)(puVar24 + -8) = 0x18003fec1;
      MMAfxMessageBox(pcVar17,0,-1,0);
      *(undefined8 *)(puVar24 + -8) = 0x18003fecb;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_448);
    }
    if (plVar4 != (longlong *)0x0) {
      *(undefined8 *)(puVar24 + -8) = 0x18003fee2;
      FUN_1800081e0(plVar4,plVar32);
      plVar32 = plVar4;
      if ((0xfff < ((longlong)local_3c0 - (longlong)plVar4 & 0xffffffffffffffe0U)) &&
         (plVar32 = (longlong *)plVar4[-1],
         0x1f < (ulonglong)((longlong)plVar4 + (-8 - (longlong)plVar32)))) {
                    /* WARNING: Subroutine does not return */
        *(undefined **)(puVar24 + -8) = &UNK_18003ff18;
        _invalid_parameter_noinfo_noreturn();
      }
      *(undefined8 *)(puVar24 + -8) = 0x18003ff28;
      operator_delete(plVar32);
    }
    *(undefined8 *)(puVar24 + -8) = 0x18003ff34;
    FUN_18003df30((longlong *)&local_378);
    uVar14 = local_440;
  }
  *(undefined8 *)(puVar24 + -8) = 0x18003ff46;
  return uVar14;
LAB_18003f47f:
  puVar21 = puVar21 + 5;
  puVar25 = puVar24 + -0x60;
  if (puVar21 == puVar6) goto LAB_18003f49b;
  goto LAB_18003f443;
}

/* ---- FUNC 0003FF60 MMCopyStorage (24 bytes) ---- */

int MMCopyStorage(longlong *param_1,undefined8 param_2,undefined *param_3)

{
  longlong lVar1;
  short sVar2;
  longlong *plVar3;
  int iVar4;
  int iVar5;
  longlong *plVar6;
  void *_Memory;
  longlong lVar7;
  short *psVar8;
  short *psVar9;
  int iVar10;
  int local_res8 [2];
  longlong *local_res20;
  longlong *local_a8;
  longlong *plStack_a0;
  longlong *local_98;
  longlong local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  
                    /* 0x3ff60  376  MMCopyStorage */
  iVar10 = 0;
  local_res20 = (longlong *)0x0;
  local_98 = (longlong *)0x0;
  local_a8 = (longlong *)0x0;
  plStack_a0 = (longlong *)0x0;
  FUN_18003e6a0((longlong *)&local_a8,10);
  iVar4 = (**(code **)(*param_1 + 0x58))(param_1,0,0,0,&local_res20);
  if (-1 < iVar4) {
    do {
      local_88 = 0;
      uStack_80 = 0;
      local_78 = 0;
      uStack_70 = 0;
      local_68 = 0;
      uStack_60 = 0;
      local_58 = 0;
      uStack_50 = 0;
      local_48 = 0;
      uStack_40 = 0;
      if (plStack_a0 == local_98) {
        plVar6 = FUN_18003c750((longlong *)&local_a8,plStack_a0,&local_88);
      }
      else {
        *plStack_a0 = 0;
        plStack_a0[1] = 0;
        plStack_a0[2] = 0;
        plStack_a0[3] = 0;
        plStack_a0[4] = 0;
        plStack_a0[5] = 0;
        plStack_a0[6] = 0;
        plStack_a0[7] = 0;
        plStack_a0[8] = 0;
        plStack_a0[9] = 0;
        plVar6 = plStack_a0;
        plStack_a0 = plStack_a0 + 10;
      }
      if (((plVar6 == plStack_a0) ||
          (iVar4 = (**(code **)(*local_res20 + 0x18))(local_res20,1,plVar6,local_res8), iVar4 < 0))
         || (iVar5 = 0, local_res8[0] == 0)) break;
      if (*plVar6 != 0) {
        if (param_3 != (undefined *)0x0) {
          iVar5 = (*(code *)param_3)();
        }
        if (iVar5 == 0) {
          lVar7 = -1;
          do {
            lVar7 = lVar7 + 1;
          } while (*(short *)(*plVar6 + lVar7 * 2) != 0);
          iVar10 = iVar10 + 1 + (int)lVar7;
        }
        else {
          CoTaskMemFree((LPVOID)*plVar6);
          *plVar6 = 0;
        }
      }
    } while (iVar4 != 1);
    (**(code **)(*local_res20 + 0x10))();
    iVar4 = (int)(((longlong)plStack_a0 - (longlong)local_a8) / 0x50) * 8 + 8;
    _Memory = calloc((longlong)(iVar4 + iVar10 * 2),1);
    iVar5 = 0;
    iVar10 = 0;
    for (plVar6 = local_a8; plVar6 != plStack_a0; plVar6 = plVar6 + 10) {
      if (*plVar6 != 0) {
        lVar7 = -1;
        do {
          lVar1 = lVar7 * 2;
          lVar7 = lVar7 + 1;
        } while (*(short *)(*plVar6 + 2 + lVar1) != 0);
        psVar8 = (short *)((longlong)iVar4 + (longlong)_Memory);
        *(short **)((longlong)iVar5 + (longlong)_Memory) = psVar8;
        psVar9 = (short *)*plVar6;
        do {
          sVar2 = *psVar9;
          psVar9 = psVar9 + 1;
          *psVar8 = sVar2;
          psVar8 = psVar8 + 1;
        } while (sVar2 != 0);
        iVar10 = iVar10 + 1;
        iVar5 = iVar5 + 8;
        iVar4 = iVar4 + 2 + (int)lVar7 * 2;
      }
    }
    *(undefined8 *)((longlong)(iVar10 * 8) + (longlong)_Memory) = 0;
    iVar4 = (**(code **)(*param_1 + 0x38))(param_1,0,0,_Memory,param_2);
    free(_Memory);
  }
  plVar3 = plStack_a0;
  plVar6 = local_a8;
  if (local_a8 != (longlong *)0x0) {
    for (; plVar6 != plVar3; plVar6 = plVar6 + 10) {
      if ((LPVOID)*plVar6 != (LPVOID)0x0) {
        CoTaskMemFree((LPVOID)*plVar6);
      }
      *plVar6 = 0;
    }
    plVar6 = local_a8;
    if ((0xfff < (ulonglong)((((longlong)local_98 - (longlong)local_a8) / 0x50) * 0x50)) &&
       (plVar6 = (longlong *)local_a8[-1],
       0x1f < (ulonglong)((longlong)local_a8 + (-8 - (longlong)plVar6)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(plVar6);
  }
  return iVar4;
}

/* ---- FUNC 0003FF78 FUN_18003ff78 (572 bytes) ---- */

int FUN_18003ff78(longlong *param_1,undefined8 param_2,code *param_3)

{
  longlong lVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  longlong in_RAX;
  longlong *plVar6;
  longlong *plVar7;
  void *_Memory;
  longlong lVar8;
  short *psVar9;
  ulonglong unaff_RBX;
  ulonglong *puVar10;
  ulonglong *puVar11;
  longlong unaff_RBP;
  short *psVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  undefined8 unaff_R12;
  undefined8 unaff_R13;
  ulonglong uVar15;
  
  *(undefined8 *)(in_RAX + 0x10) = unaff_R12;
  *(undefined8 *)(in_RAX + -0x38) = unaff_R13;
  *(ulonglong *)(unaff_RBP + 0x7f) = unaff_RBX;
  *(ulonglong *)(unaff_RBP + -0x39) = unaff_RBX;
  *(undefined8 *)(unaff_RBP + -0x49) = 0;
  *(undefined8 *)(unaff_RBP + -0x41) = 0;
  FUN_18003e6a0((longlong *)(unaff_RBP + -0x49),(ulonglong)((int)unaff_RBX + 10));
  uVar15 = unaff_RBX & 0xffffffff;
  iVar3 = (**(code **)(*param_1 + 0x58))(param_1,0,0,0,unaff_RBP + 0x7f);
  if (-1 < iVar3) {
    do {
      iVar3 = (int)uVar15;
      plVar7 = *(longlong **)(unaff_RBP + -0x41);
      *(undefined8 *)(unaff_RBP + -0x29) = 0;
      *(undefined8 *)(unaff_RBP + -0x21) = 0;
      *(undefined8 *)(unaff_RBP + -0x19) = 0;
      *(undefined8 *)(unaff_RBP + -0x11) = 0;
      *(undefined8 *)(unaff_RBP + -9) = 0;
      *(undefined8 *)(unaff_RBP + -1) = 0;
      *(undefined8 *)(unaff_RBP + 7) = 0;
      *(undefined8 *)(unaff_RBP + 0xf) = 0;
      *(undefined8 *)(unaff_RBP + 0x17) = 0;
      *(undefined8 *)(unaff_RBP + 0x1f) = 0;
      if (plVar7 == *(longlong **)(unaff_RBP + -0x39)) {
        plVar7 = FUN_18003c750((longlong *)(unaff_RBP + -0x49),plVar7,
                               (longlong *)(unaff_RBP + -0x29));
        plVar6 = *(longlong **)(unaff_RBP + -0x41);
      }
      else {
        *plVar7 = 0;
        plVar7[1] = 0;
        plVar7[2] = 0;
        plVar7[3] = 0;
        plVar7[4] = 0;
        plVar7[5] = 0;
        plVar7[6] = 0;
        plVar7[7] = 0;
        plVar7[8] = 0;
        plVar7[9] = 0;
        plVar6 = (longlong *)(*(longlong *)(unaff_RBP + -0x41) + 0x50);
        *(longlong **)(unaff_RBP + -0x41) = plVar6;
      }
      if (((plVar7 == plVar6) ||
          (iVar4 = (**(code **)(**(longlong **)(unaff_RBP + 0x7f) + 0x18))
                             (*(longlong **)(unaff_RBP + 0x7f),1,plVar7,unaff_RBP + 0x67), iVar4 < 0
          )) || (iVar5 = 0, *(int *)(unaff_RBP + 0x67) == 0)) break;
      if (*plVar7 != 0) {
        if (param_3 != (code *)0x0) {
          iVar5 = (*param_3)();
        }
        if (iVar5 == 0) {
          lVar8 = -1;
          do {
            lVar8 = lVar8 + 1;
          } while (*(short *)(*plVar7 + lVar8 * 2) != 0);
          uVar15 = (ulonglong)(uint)(iVar3 + 1 + (int)lVar8);
        }
        else {
          CoTaskMemFree((LPVOID)*plVar7);
          *plVar7 = 0;
        }
      }
      iVar3 = (int)uVar15;
    } while (iVar4 != 1);
    (**(code **)(**(longlong **)(unaff_RBP + 0x7f) + 0x10))();
    iVar4 = (int)((*(longlong *)(unaff_RBP + -0x41) - *(longlong *)(unaff_RBP + -0x49)) / 0x50) * 8
            + 8;
    _Memory = calloc((longlong)(iVar4 + iVar3 * 2),1);
    plVar7 = *(longlong **)(unaff_RBP + -0x49);
    uVar15 = 0;
    plVar6 = *(longlong **)(unaff_RBP + -0x41);
    iVar3 = 0;
    uVar13 = uVar15;
    uVar14 = uVar15;
    if (plVar7 != plVar6) {
      do {
        if (*plVar7 != 0) {
          lVar8 = -1;
          do {
            lVar1 = lVar8 * 2;
            lVar8 = lVar8 + 1;
          } while (*(short *)(*plVar7 + 2 + lVar1) != 0);
          psVar9 = (short *)((longlong)iVar4 + (longlong)_Memory);
          *(short **)((longlong)(int)uVar13 + (longlong)_Memory) = psVar9;
          psVar12 = (short *)*plVar7;
          do {
            sVar2 = *psVar12;
            psVar12 = psVar12 + 1;
            *psVar9 = sVar2;
            psVar9 = psVar9 + 1;
          } while (sVar2 != 0);
          plVar6 = *(longlong **)(unaff_RBP + -0x41);
          uVar14 = (ulonglong)((int)uVar14 + 1);
          uVar13 = (ulonglong)((int)uVar13 + 8);
          iVar4 = iVar4 + 2 + (int)lVar8 * 2;
        }
        iVar3 = (int)uVar14;
        plVar7 = plVar7 + 10;
      } while (plVar7 != plVar6);
    }
    *(undefined8 *)((longlong)(iVar3 * 8) + (longlong)_Memory) = 0;
    iVar3 = (**(code **)(*param_1 + 0x38))(param_1,0,0,_Memory,param_2);
    free(_Memory);
  }
  puVar10 = *(ulonglong **)(unaff_RBP + -0x49);
  if (puVar10 != (ulonglong *)0x0) {
    puVar11 = *(ulonglong **)(unaff_RBP + -0x41);
    if (puVar10 != puVar11) {
      do {
        if ((LPVOID)*puVar10 != (LPVOID)0x0) {
          CoTaskMemFree((LPVOID)*puVar10);
        }
        *puVar10 = uVar15;
        puVar10 = puVar10 + 10;
      } while (puVar10 != puVar11);
      puVar10 = *(ulonglong **)(unaff_RBP + -0x49);
    }
    puVar11 = puVar10;
    if ((0xfff < (ulonglong)(((*(longlong *)(unaff_RBP + -0x39) - (longlong)puVar10) / 0x50) * 0x50)
        ) && (puVar11 = (ulonglong *)puVar10[-1],
             0x1f < (ulonglong)((longlong)puVar10 + (-8 - (longlong)puVar11)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(puVar11);
  }
  return iVar3;
}

/* ---- FUNC 000401B4 FUN_1800401b4 (143 bytes) ---- */

undefined4 FUN_1800401b4(void)

{
  longlong lVar1;
  undefined8 *unaff_RBX;
  undefined8 *puVar2;
  longlong unaff_RBP;
  undefined4 unaff_ESI;
  undefined8 unaff_R14;
  longlong unaff_R15;
  
  puVar2 = *(undefined8 **)(unaff_RBP + -0x41);
  if (unaff_RBX != puVar2) {
    do {
      if ((LPVOID)*unaff_RBX != (LPVOID)0x0) {
        CoTaskMemFree((LPVOID)*unaff_RBX);
      }
      *unaff_RBX = unaff_R14;
      unaff_RBX = unaff_RBX + 10;
    } while (unaff_RBX != puVar2);
    unaff_RBX = *(undefined8 **)(unaff_RBP + -0x49);
  }
  lVar1 = SUB168(SEXT816(unaff_R15) *
                 SEXT816(*(longlong *)(unaff_RBP + -0x39) - (longlong)unaff_RBX),8);
  puVar2 = unaff_RBX;
  if ((0xfff < (ulonglong)(((lVar1 >> 5) - (lVar1 >> 0x3f)) * 0x50)) &&
     (puVar2 = (undefined8 *)unaff_RBX[-1],
     0x1f < (ulonglong)((longlong)unaff_RBX + (-8 - (longlong)puVar2)))) {
                    /* WARNING: Subroutine does not return */
    _invalid_parameter_noinfo_noreturn();
  }
  operator_delete(puVar2);
  return unaff_ESI;
}

/* ---- FUNC 00040250 MMEnumerateXLStorages (301 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void MMEnumerateXLStorages(undefined *param_1)

{
  int iVar1;
  longlong *plVar2;
  undefined1 auStack_a8 [32];
  longlong **local_88;
  int local_78 [2];
  longlong *local_70;
  wchar_t *local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
                    /* 0x40250  388  MMEnumerateXLStorages */
  local_18 = DAT_1800791f8 ^ (ulonglong)auStack_a8;
  plVar2 = (longlong *)GetGlobalPointer("ApwnDocStorage");
  if (plVar2 != (longlong *)0x0) {
    local_88 = &local_70;
    local_70 = (longlong *)0x0;
    iVar1 = (**(code **)(*plVar2 + 0x58))(plVar2,0,0,0);
    if (-1 < iVar1) {
      local_68 = (wchar_t *)0x0;
      uStack_60 = 0;
      local_58 = 0;
      uStack_50 = 0;
      local_48 = 0;
      uStack_40 = 0;
      local_38 = 0;
      uStack_30 = 0;
      local_28 = 0;
      uStack_20 = 0;
      iVar1 = (**(code **)(*local_70 + 0x18))(local_70,1,&local_68,local_78);
      while ((iVar1 == 0 && (local_78[0] != 0))) {
        if ((local_68 != (wchar_t *)0x0) && (iVar1 = wcsncmp(local_68,L"Embedding ",10), iVar1 == 0)
           ) {
          iVar1 = _wtoi(local_68 + 10);
          (*(code *)param_1)(iVar1);
        }
        iVar1 = (**(code **)(*local_70 + 0x18))(local_70,1,&local_68,local_78);
      }
      (**(code **)(*local_70 + 0x10))();
      if (local_68 != (wchar_t *)0x0) {
        CoTaskMemFree(local_68);
      }
    }
  }
  return;
}

/* ---- FUNC 00040380 MMRestoreEmbeddedItems (122 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
MMRestoreEmbeddedItems
          (LPSTORAGE param_1,undefined *param_2,undefined8 param_3,longlong param_4,
          undefined *param_5,undefined *param_6,int param_7)

{
  int iVar1;
  LPSTORAGE pStg;
  longlong *plVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined1 auStackY_1d8 [32];
  longlong *local_1a8;
  int local_1a0 [2];
  undefined *local_198;
  AFX_MAINTAIN_STATE2 local_190 [16];
  IID local_180;
  CLSID local_170;
  undefined1 local_158 [272];
  ulonglong local_48;
  
                    /* 0x40380  403  MMRestoreEmbeddedItems */
  local_48 = DAT_1800791f8 ^ (ulonglong)auStackY_1d8;
  local_198 = param_6;
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_190,DAT_18007b728);
  pStg = (LPSTORAGE)GetGlobalPointer("ApwnDocStorage");
  uVar5 = 0;
  if ((pStg != (LPSTORAGE)0x0) &&
     (plVar2 = (longlong *)GetGlobalPointer("HappNode"), plVar2 != (longlong *)0x0)) {
    ReadClassStg(param_1,&local_170);
    if ((param_2 == (undefined *)0x0) ||
       (iVar1 = FUN_18003f2d0((longlong *)param_1,param_2,param_5,local_198,param_7), iVar1 == 0)) {
      MMCopyStorage((longlong *)param_1,pStg,(undefined *)0x0);
    }
    if ((param_4 == 0) || (uVar3 = FUN_18003f2b0(), (int)uVar3 == 0)) {
      MMCopyStorage((longlong *)param_1,pStg,FUN_18003e570);
    }
    local_180.Data1 = _DAT_1800561b0;
    local_180.Data2 = _UNK_1800561b4;
    local_180.Data3 = _UNK_1800561b6;
    local_180.Data4[0] = UNK_1800561b8;
    local_180.Data4[1] = UNK_1800561b9;
    local_180.Data4[2] = UNK_1800561ba;
    local_180.Data4[3] = UNK_1800561bb;
    local_180.Data4[4] = UNK_1800561bc;
    local_180.Data4[5] = UNK_1800561bd;
    local_180.Data4[6] = UNK_1800561be;
    local_180.Data4[7] = UNK_1800561bf;
    uVar4 = FUN_1800240b0();
    if ((int)uVar4 == 1) {
      local_180.Data2 = _UNK_1800561a4;
      local_180.Data3 = _UNK_1800561a6;
      local_180.Data1 = _DAT_1800561a0;
      local_180.Data4[4] = UNK_1800561ac;
      local_180.Data4[5] = UNK_1800561ad;
      local_180.Data4[6] = UNK_1800561ae;
      local_180.Data4[7] = UNK_1800561af;
      local_180.Data4[0] = UNK_1800561a8;
      local_180.Data4[1] = UNK_1800561a9;
      local_180.Data4[2] = UNK_1800561aa;
      local_180.Data4[3] = UNK_1800561ab;
    }
    WriteClassStg(pStg,&local_180);
    (*pStg->lpVtbl->Commit)(pStg,0);
    if ((local_170._0_8_ == DAT_180057ab8) && (local_170.Data4 == DAT_180057ac0)) {
      local_1a8 = (longlong *)0x0;
      iVar1 = (**(code **)(*plVar2 + 0x90))(plVar2,&local_1a8);
      if (iVar1 < 0) goto FUN_18004058a;
      if (param_1 != (LPSTORAGE)0x0) {
        RestoreEmbeddedObjects(pStg,local_1a8);
      }
      (**(code **)(*local_1a8 + 0x10))();
    }
    if (param_2 == (undefined *)0x0) {
      MMEnumerateXLStorages(MMXLRestoreItem);
    }
    else {
      local_198 = (undefined *)0x0;
      iVar1 = (*(code *)param_2)(&local_198,&local_1a8,local_1a0,local_158);
      while (iVar1 != 0) {
        if (((int)local_1a8 != -1) && (local_1a0[0] != -1)) {
          MMXLRestoreItem(local_1a0[0]);
        }
        iVar1 = (*(code *)param_2)(&local_198,&local_1a8,local_1a0,local_158);
      }
    }
    uVar5 = 1;
  }
FUN_18004058a:
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_190);
  return uVar5;
}

/* ---- FUNC 000403FA FUN_1800403fa (400 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Exceeded maximum restarts with more pending */

ulonglong FUN_1800403fa(char *param_1)

{
  int iVar1;
  longlong *plVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  code *unaff_RBX;
  longlong unaff_RBP;
  LPSTORAGE unaff_RSI;
  LPSTORAGE unaff_RDI;
  longlong unaff_R12;
  undefined *unaff_R13;
  longlong *unaff_R14;
  int iStack0000000000000030;
  int in_stack_00000038;
  longlong *in_stack_00000040;
  ulong uStack0000000000000058;
  ushort uStack000000000000005c;
  ushort uStack000000000000005e;
  uchar uStack0000000000000060;
  uchar uStack0000000000000061;
  uchar uStack0000000000000062;
  uchar uStack0000000000000063;
  uchar uStack0000000000000064;
  uchar uStack0000000000000065;
  uchar uStack0000000000000066;
  uchar uStack0000000000000067;
  longlong in_stack_00000068;
  uchar in_stack_00000070 [8];
  
  plVar2 = (longlong *)GetGlobalPointer(param_1);
  if (plVar2 != (longlong *)0x0) {
    ReadClassStg(unaff_RDI,(CLSID *)&stack0x00000068);
    if ((unaff_RBX == (code *)0x0) ||
       (iVar1 = FUN_18003f2d0((longlong *)unaff_RDI,unaff_RBX,unaff_R13,
                              (undefined *)in_stack_00000040,*(int *)(unaff_RBP + 0x110)),
       iVar1 == 0)) {
      MMCopyStorage((longlong *)unaff_RDI,unaff_RSI,(undefined *)0x0);
    }
    if ((unaff_R12 == 0) || (uVar3 = FUN_18003f2b0(), (int)uVar3 == 0)) {
      MMCopyStorage((longlong *)unaff_RDI,unaff_RSI,FUN_18003e570);
    }
    uStack0000000000000058 = _DAT_1800561b0;
    uStack000000000000005c = _UNK_1800561b4;
    uStack000000000000005e = _UNK_1800561b6;
    uStack0000000000000060 = UNK_1800561b8;
    uStack0000000000000061 = UNK_1800561b9;
    uStack0000000000000062 = UNK_1800561ba;
    uStack0000000000000063 = UNK_1800561bb;
    uStack0000000000000064 = UNK_1800561bc;
    uStack0000000000000065 = UNK_1800561bd;
    uStack0000000000000066 = UNK_1800561be;
    uStack0000000000000067 = UNK_1800561bf;
    uVar4 = FUN_1800240b0();
    if ((int)uVar4 == 1) {
      uStack0000000000000058 = _DAT_1800561a0;
      uStack000000000000005c = _UNK_1800561a4;
      uStack000000000000005e = _UNK_1800561a6;
      uStack0000000000000060 = UNK_1800561a8;
      uStack0000000000000061 = UNK_1800561a9;
      uStack0000000000000062 = UNK_1800561aa;
      uStack0000000000000063 = UNK_1800561ab;
      uStack0000000000000064 = UNK_1800561ac;
      uStack0000000000000065 = UNK_1800561ad;
      uStack0000000000000066 = UNK_1800561ae;
      uStack0000000000000067 = UNK_1800561af;
    }
    WriteClassStg(unaff_RSI,(IID *)&stack0x00000058);
    (*unaff_RSI->lpVtbl->Commit)();
    if ((in_stack_00000068 == DAT_180057ab8) && (in_stack_00000070 == (uchar  [8])DAT_180057ac0)) {
      _iStack0000000000000030 = unaff_R14;
      iVar1 = (**(code **)(*plVar2 + 0x90))(plVar2,&stack0x00000030);
      if (iVar1 < 0) goto LAB_180040582;
      if (unaff_RDI != (LPSTORAGE)0x0) {
        RestoreEmbeddedObjects(unaff_RSI,_iStack0000000000000030);
      }
      (**(code **)(*_iStack0000000000000030 + 0x10))();
    }
    if (unaff_RBX == (code *)0x0) {
      MMEnumerateXLStorages(MMXLRestoreItem);
    }
    else {
      in_stack_00000040 = unaff_R14;
      iVar1 = (*unaff_RBX)(&stack0x00000040,&stack0x00000030,&stack0x00000038,unaff_RBP + -0x80,
                           0x104);
      while (iVar1 != 0) {
        if ((iStack0000000000000030 != -1) && (in_stack_00000038 != -1)) {
          MMXLRestoreItem(in_stack_00000038);
        }
        iVar1 = (*unaff_RBX)(&stack0x00000040,&stack0x00000030,&stack0x00000038,unaff_RBP + -0x80,
                             0x104);
      }
    }
    unaff_R14 = (longlong *)0x1;
  }
LAB_180040582:
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2((AFX_MAINTAIN_STATE2 *)&stack0x00000048);
  return (ulonglong)unaff_R14 & 0xffffffff;
}

/* ---- FUNC 0004058A FUN_18004058a (46 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_18004058a(void)

{
  undefined4 unaff_R14D;
  
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2((AFX_MAINTAIN_STATE2 *)&stack0x00000048);
  return unaff_R14D;
}

/* ---- FUNC 000405C0 MMSaveAllEmbeddedItems (305 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong MMSaveAllEmbeddedItems(char *param_1)

{
  _func_5403 *p_Var1;
  _func_5396 *p_Var2;
  IStorage *pIVar3;
  HRESULT HVar4;
  longlong lVar5;
  ulonglong uVar7;
  int iVar8;
  undefined1 *puVar9;
  AFX_MAINTAIN_STATE2 *pwcsName;
  undefined8 uStack_60;
  undefined1 auStack_58 [32];
  undefined8 uStack_38;
  int aiStack_30 [2];
  IStorage *local_28;
  AFX_MAINTAIN_STATE2 local_20 [16];
  ulonglong local_10;
  longlong lVar6;
  
                    /* 0x405c0  405  MMSaveAllEmbeddedItems */
  local_10 = DAT_1800791f8 ^ (ulonglong)&local_28;
  uStack_60 = 0x1800405f8;
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_20,DAT_18007b728);
  uStack_60 = 0x180040601;
  remove(param_1);
  puVar9 = auStack_58;
  if (param_1 != (char *)0x0) {
    lVar5 = -1;
    do {
      lVar6 = lVar5;
      lVar5 = lVar6 + 1;
    } while (param_1[lVar5] != '\0');
    iVar8 = (int)lVar6 + 2;
    puVar9 = auStack_58;
    if (iVar8 < 0x40000000) {
      lVar5 = (longlong)(int)lVar5 * 2;
      uVar7 = lVar5 + 0x11;
      if (uVar7 <= lVar5 + 2U) {
        uVar7 = 0xffffffffffffff0;
      }
      uStack_60 = 0x18004064d;
      lVar5 = -(uVar7 & 0xfffffffffffffff0);
      puVar9 = auStack_58 + lVar5;
      pwcsName = local_20 + lVar5 + -8;
      if (pwcsName != (AFX_MAINTAIN_STATE2 *)0x0) {
        *(int *)((longlong)aiStack_30 + lVar5) = iVar8;
        *(undefined2 *)pwcsName = 0;
        *(AFX_MAINTAIN_STATE2 **)((longlong)&uStack_38 + lVar5) = pwcsName;
        *(undefined8 *)(auStack_58 + lVar5 + -8) = 0x180040679;
        iVar8 = MultiByteToWideChar(0,0,param_1,-1,*(LPWSTR *)((longlong)&uStack_38 + lVar5),
                                    *(int *)((longlong)aiStack_30 + lVar5));
        puVar9 = auStack_58 + lVar5;
        if (iVar8 == 0) {
          puVar9 = auStack_58 + lVar5;
          pwcsName = (AFX_MAINTAIN_STATE2 *)0x0;
        }
        goto LAB_180040685;
      }
    }
  }
  pwcsName = (AFX_MAINTAIN_STATE2 *)0x0;
LAB_180040685:
  uVar7 = 0;
  *(undefined8 *)(puVar9 + -8) = 0x18004069a;
  HVar4 = StgCreateDocfile((WCHAR *)pwcsName,0x11012,0,&local_28);
  pIVar3 = local_28;
  if (-1 < HVar4) {
    *(undefined8 *)(puVar9 + -8) = 0x1800406af;
    uVar7 = MMSaveEmbeddedItems(pIVar3,(undefined *)0x0,(undefined *)0x0);
    pIVar3 = local_28;
    uVar7 = uVar7 & 0xffffffff;
    p_Var1 = local_28->lpVtbl->Commit;
    *(undefined8 *)(puVar9 + -8) = 0x1800406be;
    (*p_Var1)(pIVar3,0);
    p_Var2 = local_28->lpVtbl->Release;
    *(undefined8 *)(puVar9 + -8) = 0x1800406c8;
    (*p_Var2)(local_28);
  }
  *(undefined8 *)(puVar9 + -8) = 0x1800406d1;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_20);
  *(undefined8 *)(puVar9 + -8) = 0x1800406df;
  return uVar7;
}

/* ---- FUNC 00040700 MMSaveEmbeddedItems (283 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 MMSaveEmbeddedItems(IStorage *param_1,undefined *param_2,undefined *param_3)

{
  HRESULT HVar1;
  longlong *plVar2;
  undefined8 uVar3;
  code *pcVar4;
  undefined1 auStack_448 [32];
  AFX_MAINTAIN_STATE2 local_428 [16];
  undefined1 local_418 [1008];
  ulonglong local_28;
  
                    /* 0x40700  406  MMSaveEmbeddedItems */
  local_28 = DAT_1800791f8 ^ (ulonglong)auStack_448;
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_428,DAT_18007b728);
  plVar2 = (longlong *)GetGlobalPointer("ApwnDocStorage");
  if (plVar2 == (longlong *)0x0) {
    uVar3 = 0;
  }
  else {
    pcVar4 = FUN_18003e540;
    if (param_2 != (undefined *)0x0) {
      pcVar4 = (code *)param_2;
    }
    HVar1 = FUN_18003e130(plVar2,param_1,pcVar4,param_3);
    uVar3 = 1;
    if (HVar1 < 0) {
      FUN_180007de0(local_418,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\stgutil.cpp",0x244);
      LogMessage(local_418,2,1);
    }
    HVar1 = WriteClassStg(param_1,(IID *)&DAT_180056490);
    if (HVar1 < 0) {
      FUN_180007de0(local_418,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\stgutil.cpp",0x247);
      LogMessage(local_418,2,1);
    }
    (*param_1->lpVtbl->Commit)(param_1,0);
  }
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_428);
  return uVar3;
}

/* ---- FUNC 00040820 FUN_180040820 (43 bytes) ---- */

CPtrArray * FUN_180040820(CPtrArray *param_1)

{
  CPtrArray::CPtrArray(param_1);
  CPtrArray::SetSize(param_1,0,-1);
  return param_1;
}

/* ---- FUNC 00040850 FUN_180040850 (271 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

longlong *
FUN_180040850(longlong *param_1,longlong param_2,char *param_3,uint param_4,undefined4 param_5,
             undefined4 param_6)

{
  undefined1 auStack_448 [32];
  longlong *local_428;
  undefined1 local_418 [1008];
  ulonglong local_28;
  
  local_28 = DAT_1800791f8 ^ (ulonglong)auStack_448;
  local_428 = param_1;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 1));
  if (param_2 == 0) {
    FUN_180007de0(local_418,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\StreamTable.cpp",10);
    LogMessage(local_418,2,1);
  }
  if (0x7fffffff < param_4) {
    FUN_180007de0(local_418,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\StreamTable.cpp",0xc);
    LogMessage(local_418,2,1);
  }
  *param_1 = param_2;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 1),param_3)
  ;
  *(uint *)(param_1 + 2) = param_4;
  *(undefined4 *)((longlong)param_1 + 0x14) = param_5;
  *(undefined4 *)(param_1 + 3) = 0;
  *(undefined4 *)((longlong)param_1 + 0x1c) = param_6;
  FUN_180040d90(param_1);
  return param_1;
}

/* ---- FUNC 00040960 FUN_180040960 (145 bytes) ---- */

void FUN_180040960(CPtrArray *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  int iVar3;
  
  if (-1 < *(int *)(param_1 + 0x10) + -1) {
    lVar2 = (longlong)(*(int *)(param_1 + 0x10) + -1);
    do {
      if ((lVar2 < 0) || (*(longlong *)(param_1 + 0x10) <= lVar2)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      plVar1 = *(longlong **)(*(longlong *)(param_1 + 8) + lVar2 * 8);
      if (plVar1 != (longlong *)0x0) {
        if ((*(byte *)((longlong)plVar1 + 0x14) & 6) == 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = (int)plVar1[2];
        }
        FUN_180040a00(plVar1);
        operator_delete(plVar1);
        if (iVar3 != 0) {
          FUN_180041b20((longlong)param_1,iVar3);
        }
      }
      lVar2 = lVar2 + -1;
    } while (-1 < lVar2);
  }
  CPtrArray::~CPtrArray(param_1);
  return;
}

/* ---- FUNC 00040A00 FUN_180040a00 (36 bytes) ---- */

void FUN_180040a00(longlong *param_1)

{
  if (*param_1 != 0) {
    FUN_180041920(param_1);
  }
                    /* WARNING: Could not recover jumptable at 0x000180040a1d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 1));
  return;
}

/* ---- FUNC 00040A30 FUN_180040a30 (582 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
FUN_180040a30(CPtrArray *param_1,longlong param_2,longlong param_3,char *param_4,uint param_5,
             undefined4 param_6,int *param_7)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  longlong *plVar5;
  longlong lVar6;
  undefined1 auStackY_4a8 [32];
  uint local_468;
  undefined4 local_464;
  longlong local_460;
  longlong *local_458;
  undefined1 local_448 [1008];
  ulonglong local_58;
  
  local_58 = DAT_1800791f8 ^ (ulonglong)auStackY_4a8;
  local_464 = param_6;
  local_460 = param_2;
  if (param_2 == 0) {
    FUN_180007de0(local_448,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\StreamTable.cpp",0xde);
    LogMessage(local_448,2);
  }
  plVar5 = (longlong *)0x0;
  if ((param_5 & 2) == 0) {
    if ((param_5 & 4) == 0) goto LAB_180040b58;
    if (param_7 == (int *)0x0) {
      FUN_180007de0(local_448,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\StreamTable.cpp",0xe3);
      LogMessage(local_448,2);
    }
    *param_7 = 0;
    if (param_3 == 0) goto LAB_180040b58;
    iVar2 = FUN_1800410e0((longlong)param_1,param_3,param_4);
    if (iVar2 != 0) {
      return 0x80004005;
    }
  }
  else {
    if (param_3 == 0) {
      FUN_180007de0(local_448,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\StreamTable.cpp",0xe0);
      LogMessage(local_448,2,1);
      uVar3 = 0;
      goto LAB_180040bae;
    }
LAB_180040b58:
    uVar3 = 0;
    if (param_3 == 0) goto LAB_180040bae;
  }
  uVar3 = FUN_180040c80((longlong)param_1,param_3);
  if ((uVar3 == 0) &&
     (uVar4 = FUN_180040a30(param_1,param_3,0,"",1,local_464,(int *)&local_468), uVar3 = local_468,
     (int)uVar4 != 0)) {
    return 0x80004005;
  }
LAB_180040bae:
  local_458 = operator_new(0x20);
  if (local_458 != (longlong *)0x0) {
    plVar5 = FUN_180040850(local_458,local_460,param_4,uVar3,param_5,local_464);
  }
  local_468 = 1;
  lVar1 = *(longlong *)(param_1 + 0x10);
  if (0 < lVar1) {
    do {
      lVar6 = (longlong)(int)local_468 + -1;
      if ((lVar6 < 0) || (lVar1 <= lVar6)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
    } while ((*(longlong *)(*(longlong *)(param_1 + 8) + lVar6 * 8) != 0) &&
            (local_468 = local_468 + 1, (int)local_468 <= lVar1));
  }
  CPtrArray::SetAtGrow(param_1,(longlong)(int)(local_468 - 1),plVar5);
  if (param_7 != (int *)0x0) {
    *param_7 = local_468;
  }
  return 0;
}

/* ---- FUNC 00040C80 FUN_180040c80 (263 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_180040c80(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong *plVar2;
  bool bVar3;
  undefined7 extraout_var;
  longlong lVar4;
  int iVar5;
  undefined1 auStack_438 [32];
  undefined1 local_418 [1008];
  ulonglong local_28;
  
  local_28 = DAT_1800791f8 ^ (ulonglong)auStack_438;
  iVar5 = 1;
  if (param_2 == 0) {
    FUN_180007de0(local_418,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\StreamTable.cpp",0x104);
    LogMessage(local_418,2,1);
  }
  lVar1 = *(longlong *)(param_1 + 0x10);
  if (0 < lVar1) {
    lVar4 = 0;
    do {
      if ((lVar4 < 0) || (lVar1 <= lVar4)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      plVar2 = *(longlong **)(*(longlong *)(param_1 + 8) + lVar4 * 8);
      if ((((plVar2 != (longlong *)0x0) && (*plVar2 != 0)) &&
          ((*(byte *)((longlong)plVar2 + 0x14) & 3) != 0)) &&
         (bVar3 = FUN_180041730(plVar2,param_2), (int)CONCAT71(extraout_var,bVar3) != 0)) {
        FUN_180040d90(plVar2);
        return iVar5;
      }
      iVar5 = iVar5 + 1;
      lVar4 = lVar4 + 1;
    } while (iVar5 <= lVar1);
  }
  return 0;
}

/* ---- FUNC 00040D90 FUN_180040d90 (137 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_180040d90(longlong *param_1)

{
  ulonglong uVar1;
  undefined1 auStack_428 [32];
  undefined1 local_408 [1008];
  ulonglong local_18;
  
  local_18 = DAT_1800791f8 ^ (ulonglong)auStack_428;
  if (*param_1 == 0) {
    FUN_180007de0(local_408,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\StreamTable.cpp",0x4b);
    LogMessage(local_408,2,1);
  }
  if ((*(byte *)((longlong)param_1 + 0x14) & 3) == 0) {
    uVar1 = (**(code **)(*(longlong *)*param_1 + 8))();
  }
  else {
    (**(code **)(*(longlong *)*param_1 + 8))();
    *(int *)(param_1 + 3) = (int)param_1[3] + 1;
    uVar1 = (ulonglong)*(uint *)(param_1 + 3);
  }
  return uVar1;
}

/* ---- FUNC 00040E20 FUN_180040e20 (703 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

ulonglong FUN_180040e20(longlong param_1,int param_2,int param_3)

{
  wchar_t *pwVar1;
  undefined4 uVar2;
  longlong *plVar3;
  LPCSTR pCVar4;
  longlong *plVar5;
  uint uVar6;
  undefined8 uVar7;
  longlong lVar8;
  int iVar9;
  longlong lVar10;
  undefined1 *puVar11;
  ulonglong uVar12;
  wchar_t *pwVar13;
  wchar_t *pwVar14;
  longlong *plVar15;
  undefined *puStack_60;
  undefined1 auStack_58 [32];
  undefined8 uStack_38;
  int aiStack_30 [2];
  longlong *local_28;
  ulonglong local_20;
  
  local_20 = DAT_1800791f8 ^ (ulonglong)&local_28;
  if (0 < param_2) {
    if ((longlong)param_2 <= *(longlong *)(param_1 + 0x10)) {
      lVar10 = (longlong)param_2 + -1;
      uVar12 = 0x80004005;
      if ((lVar10 < 0) || (*(longlong *)(param_1 + 0x10) <= lVar10)) {
                    /* WARNING: Subroutine does not return */
        puStack_60 = &UNK_1800410df;
        AfxThrowInvalidArgException();
      }
      plVar3 = *(longlong **)(*(longlong *)(param_1 + 8) + lVar10 * 8);
      puVar11 = auStack_58;
      if (plVar3 == (longlong *)0x0) goto LAB_1800410b8;
      if ((*plVar3 == 0) || ((*(byte *)((longlong)plVar3 + 0x14) & 1) == 0)) {
        puVar11 = auStack_58;
        if (plVar3 == (longlong *)0x0) goto LAB_1800410b8;
        if ((*plVar3 != 0) && ((*(byte *)((longlong)plVar3 + 0x14) & 8) != 0)) {
          puVar11 = auStack_58;
          if ((int)plVar3[2] != 0) {
            if ((param_3 != 1) &&
               (puVar11 = auStack_58, (*(uint *)((longlong)plVar3 + 0x1c) & 0x1000) == 0))
            goto LAB_1800410b8;
            pwVar13 = (wchar_t *)0x0;
            local_28 = (longlong *)0x0;
            puStack_60 = (undefined *)0x180040f18;
            uVar7 = FUN_1800413a0(param_1,param_2,(undefined4 *)0x0,(longlong *)&local_28);
            puVar11 = auStack_58;
            if ((int)uVar7 != 0) {
              if ((*plVar3 == 0) || ((*(byte *)((longlong)plVar3 + 0x14) & 4) == 0)) {
                pCVar4 = (LPCSTR)plVar3[1];
                puVar11 = auStack_58;
                pwVar14 = pwVar13;
                if (pCVar4 != (LPCSTR)0x0) {
                  lVar10 = -1;
                  do {
                    lVar8 = lVar10;
                    lVar10 = lVar8 + 1;
                  } while (pCVar4[lVar10] != '\0');
                  iVar9 = (int)lVar8 + 2;
                  puVar11 = auStack_58;
                  if (iVar9 < 0x40000000) {
                    lVar10 = (longlong)(int)lVar10 * 2;
                    uVar12 = lVar10 + 0x11;
                    if (uVar12 <= lVar10 + 2U) {
                      uVar12 = 0xffffffffffffff0;
                    }
                    puStack_60 = (undefined *)0x18004101d;
                    lVar10 = -(uVar12 & 0xfffffffffffffff0);
                    pwVar1 = (wchar_t *)((longlong)&local_28 + lVar10);
                    puVar11 = auStack_58 + lVar10;
                    if (pwVar1 != (wchar_t *)0x0) {
                      *(int *)((longlong)aiStack_30 + lVar10) = iVar9;
                      *pwVar1 = L'\0';
                      *(wchar_t **)((longlong)&uStack_38 + lVar10) = pwVar1;
                      *(undefined8 *)(auStack_58 + lVar10 + -8) = 0x180041044;
                      iVar9 = MultiByteToWideChar(0,0,pCVar4,-1,
                                                  *(LPWSTR *)((longlong)&uStack_38 + lVar10),
                                                  *(int *)((longlong)aiStack_30 + lVar10));
                      puVar11 = auStack_58 + lVar10;
                      pwVar14 = pwVar1;
                      if (iVar9 == 0) {
                        puVar11 = auStack_58 + lVar10;
                        pwVar14 = pwVar13;
                      }
                    }
                  }
                }
                plVar15 = local_28;
                plVar5 = (longlong *)*plVar3;
                uVar2 = *(undefined4 *)((longlong)plVar3 + 0x1c);
                *(undefined8 *)(puVar11 + -8) = 0x180041063;
                uVar12 = FUN_180042a70(plVar15,pwVar14,uVar2,plVar5);
                uVar6 = (uint)uVar12;
              }
              else {
                pCVar4 = (LPCSTR)plVar3[1];
                puVar11 = auStack_58;
                pwVar14 = pwVar13;
                if (pCVar4 != (LPCSTR)0x0) {
                  lVar10 = -1;
                  do {
                    lVar8 = lVar10;
                    lVar10 = lVar8 + 1;
                  } while (pCVar4[lVar10] != '\0');
                  iVar9 = (int)lVar8 + 2;
                  puVar11 = auStack_58;
                  if (iVar9 < 0x40000000) {
                    lVar10 = (longlong)(int)lVar10 * 2;
                    uVar12 = lVar10 + 0x11;
                    if (uVar12 <= lVar10 + 2U) {
                      uVar12 = 0xffffffffffffff0;
                    }
                    puStack_60 = (undefined *)0x180040f80;
                    lVar10 = -(uVar12 & 0xfffffffffffffff0);
                    pwVar1 = (wchar_t *)((longlong)&local_28 + lVar10);
                    puVar11 = auStack_58 + lVar10;
                    if (pwVar1 != (wchar_t *)0x0) {
                      *(int *)((longlong)aiStack_30 + lVar10) = iVar9;
                      *pwVar1 = L'\0';
                      *(wchar_t **)((longlong)&uStack_38 + lVar10) = pwVar1;
                      *(undefined8 *)(auStack_58 + lVar10 + -8) = 0x180040fa7;
                      iVar9 = MultiByteToWideChar(0,0,pCVar4,-1,
                                                  *(LPWSTR *)((longlong)&uStack_38 + lVar10),
                                                  *(int *)((longlong)aiStack_30 + lVar10));
                      puVar11 = auStack_58 + lVar10;
                      pwVar14 = pwVar1;
                      if (iVar9 == 0) {
                        puVar11 = auStack_58 + lVar10;
                        pwVar14 = pwVar13;
                      }
                    }
                  }
                }
                plVar15 = local_28;
                plVar5 = (longlong *)*plVar3;
                uVar2 = *(undefined4 *)((longlong)plVar3 + 0x1c);
                *(undefined8 *)(puVar11 + -8) = 0x180040fc6;
                uVar12 = FUN_180042bc0(plVar15,pwVar14,uVar2,plVar5);
                uVar6 = (uint)uVar12;
              }
              uVar12 = (ulonglong)uVar6;
              *(undefined8 *)(puVar11 + -8) = 0x180041070;
              FUN_1800419b0(param_1,(longlong)plVar15);
            }
          }
          if (param_3 == 1) {
            *(uint *)((longlong)plVar3 + 0x1c) = *(uint *)((longlong)plVar3 + 0x1c) & 0xffffefff;
          }
          goto LAB_1800410b8;
        }
        puVar11 = auStack_58;
        if ((plVar3 == (longlong *)0x0) || (puVar11 = auStack_58, *plVar3 == 0)) goto LAB_1800410b8;
        if ((*(byte *)((longlong)plVar3 + 0x14) & 2) == 0) {
          puVar11 = auStack_58;
          if ((*plVar3 != 0) &&
             (puVar11 = auStack_58, (*(byte *)((longlong)plVar3 + 0x14) & 4) != 0)) {
            puStack_60 = (undefined *)0x1800410ad;
            uVar6 = (**(code **)(*(longlong *)*plVar3 + 0x40))((longlong *)*plVar3,0);
            uVar12 = (ulonglong)uVar6;
            puVar11 = auStack_58;
          }
          goto LAB_1800410b8;
        }
      }
      else if (param_3 == 2) {
        puStack_60 = (undefined *)0x180040eb0;
        uVar6 = (**(code **)(*(longlong *)*plVar3 + 0x48))((longlong *)*plVar3,8);
        uVar12 = (ulonglong)uVar6;
        puVar11 = auStack_58;
        if (-1 < (int)uVar6) goto LAB_1800410b8;
      }
      puStack_60 = (undefined *)0x180040ec5;
      uVar12 = (**(code **)(*(longlong *)*plVar3 + 0x48))((longlong *)*plVar3,0);
      puVar11 = auStack_58;
      goto LAB_1800410b8;
    }
  }
  uVar12 = 0x80004005;
  puVar11 = auStack_58;
LAB_1800410b8:
  *(undefined8 *)(puVar11 + -8) = 0x1800410c4;
  return uVar12;
}

/* ---- FUNC 000410E0 FUN_1800410e0 (425 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_1800410e0(longlong param_1,longlong param_2,char *param_3)

{
  longlong *plVar1;
  byte bVar2;
  bool bVar3;
  undefined7 extraout_var;
  undefined7 extraout_var_00;
  longlong lVar4;
  int iVar5;
  longlong lVar6;
  undefined1 auStack_448 [32];
  undefined1 local_428 [1008];
  ulonglong local_38;
  
  local_38 = DAT_1800791f8 ^ (ulonglong)auStack_448;
  if (param_2 == 0) {
    FUN_180007de0(local_428,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\StreamTable.cpp",0xcb);
    LogMessage(local_428,2,1);
  }
  lVar4 = *(longlong *)(param_1 + 0x10);
  iVar5 = 1;
  if (0 < lVar4) {
    lVar6 = 0;
    do {
      if ((lVar6 < 0) || (lVar4 <= lVar6)) {
LAB_180041284:
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      plVar1 = *(longlong **)(*(longlong *)(param_1 + 8) + lVar6 * 8);
      if (param_3 == (char *)0x0) {
        if ((plVar1 != (longlong *)0x0) && (*plVar1 != 0)) {
          bVar2 = *(byte *)((longlong)plVar1 + 0x14) & 2;
joined_r0x00018004122d:
          if ((bVar2 != 0) &&
             (bVar3 = FUN_180041730(plVar1,param_2), (int)CONCAT71(extraout_var_00,bVar3) != 0)) {
            return iVar5;
          }
        }
      }
      else if ((((plVar1 != (longlong *)0x0) && (*plVar1 != 0)) &&
               ((*(byte *)((longlong)plVar1 + 0x14) & 4) != 0)) &&
              (bVar3 = FUN_180041740((longlong)plVar1,param_3),
              (int)CONCAT71(extraout_var,bVar3) != 0)) {
        if ((int)plVar1[2] < 1) {
          FUN_180007de0(local_428,"Assert failed in file %s line %d",
                        "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\StreamTable.cpp",0xd3);
          LogMessage(local_428,2,1);
        }
        lVar4 = (longlong)(int)plVar1[2] + -1;
        if ((lVar4 < 0) || (*(longlong *)(param_1 + 0x10) <= lVar4)) goto LAB_180041284;
        plVar1 = *(longlong **)(*(longlong *)(param_1 + 8) + lVar4 * 8);
        if ((plVar1 != (longlong *)0x0) && (*plVar1 != 0)) {
          bVar2 = *(byte *)((longlong)plVar1 + 0x14) & 3;
          goto joined_r0x00018004122d;
        }
      }
      lVar4 = *(longlong *)(param_1 + 0x10);
      iVar5 = iVar5 + 1;
      lVar6 = lVar6 + 1;
    } while (iVar5 <= lVar4);
  }
  return 0;
}

/* ---- FUNC 00041290 FUN_180041290 (53 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_180041290(longlong param_1,int param_2)

{
  longlong *plVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined1 auStack_88 [32];
  undefined8 local_68;
  undefined8 uStack_60;
  ulonglong local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = DAT_1800791f8 ^ (ulonglong)auStack_88;
  if (0 < param_2) {
    if ((longlong)param_2 <= *(longlong *)(param_1 + 0x10)) {
      uVar4 = 0;
      lVar3 = (longlong)param_2 + -1;
      local_68 = 0;
      uStack_60 = 0;
      local_58 = 0;
      uStack_50 = 0;
      local_48 = 0;
      uStack_40 = 0;
      local_38 = 0;
      uStack_30 = 0;
      local_28 = 0;
      uStack_20 = 0;
      if ((-1 < lVar3) && (lVar3 < *(longlong *)(param_1 + 0x10))) {
        plVar1 = *(longlong **)(*(longlong *)(param_1 + 8) + lVar3 * 8);
        uVar5 = 0;
        if (plVar1 != (longlong *)0x0) {
          if ((*plVar1 == 0) || ((*(byte *)((longlong)plVar1 + 0x14) & 3) == 0)) {
            uVar5 = uVar4;
            if ((plVar1 != (longlong *)0x0) &&
               ((*plVar1 != 0 && ((*(byte *)((longlong)plVar1 + 0x14) & 4) != 0)))) {
              iVar2 = (**(code **)(*(longlong *)*plVar1 + 0x60))((longlong *)*plVar1,&local_68,1);
              uVar5 = 0;
              if (iVar2 == 0) {
                uVar5 = local_58 & 0xffffffff;
              }
            }
          }
          else {
            iVar2 = (**(code **)(*(longlong *)*plVar1 + 0x88))((longlong *)*plVar1,&local_68,1);
            if (iVar2 == 0) {
              uVar5 = local_58 & 0xffffffff;
            }
          }
        }
        return uVar5;
      }
                    /* WARNING: Subroutine does not return */
      AfxThrowInvalidArgException();
    }
  }
  return 0x80004005;
}

/* ---- FUNC 000412C5 FUN_1800412c5 (184 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_1800412c5(longlong param_1,undefined8 param_2,longlong param_3)

{
  longlong *plVar1;
  longlong lVar2;
  int iVar3;
  longlong in_RAX;
  ulonglong uVar4;
  ulonglong uVar5;
  ulonglong in_XMM0_Qa;
  ulonglong uStack0000000000000030;
  ulonglong uStack0000000000000040;
  ulonglong uStack0000000000000050;
  ulonglong uStack0000000000000060;
  
  uVar4 = 0;
  param_1 = param_1 + -1;
  uStack0000000000000030 = in_XMM0_Qa;
  uStack0000000000000040 = in_XMM0_Qa;
  uStack0000000000000050 = in_XMM0_Qa;
  uStack0000000000000060 = in_XMM0_Qa;
  if ((-1 < param_1) && (param_1 < in_RAX)) {
    plVar1 = *(longlong **)(*(longlong *)(param_3 + 8) + param_1 * 8);
    uVar5 = 0;
    if (plVar1 != (longlong *)0x0) {
      if ((*plVar1 == 0) || ((*(byte *)((longlong)plVar1 + 0x14) & 3) == 0)) {
        uVar5 = uVar4;
        if ((plVar1 != (longlong *)0x0) &&
           ((*plVar1 != 0 && ((*(byte *)((longlong)plVar1 + 0x14) & 4) != 0)))) {
          lVar2 = *(longlong *)*plVar1;
          iVar3 = (**(code **)(lVar2 + 0x60))
                            ((longlong *)*plVar1,&stack0x00000020,1,lVar2,in_XMM0_Qa);
          uVar5 = 0;
          if (iVar3 == 0) {
            uVar5 = uStack0000000000000030 & 0xffffffff;
          }
        }
      }
      else {
        iVar3 = (**(code **)(*(longlong *)*plVar1 + 0x88))((longlong *)*plVar1,&stack0x00000020,1);
        if (iVar3 == 0) {
          uVar5 = uStack0000000000000030 & 0xffffffff;
        }
      }
    }
    return uVar5;
  }
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 0004137D FUN_18004137d (26 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18004137d(void)

{
  return 0x80004005;
}

/* ---- FUNC 00041397 AfxThrowInvalidArgException (5 bytes) ---- */

void __cdecl AfxThrowInvalidArgException(void)

{
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 000413A0 FUN_1800413a0 (314 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_1800413a0(longlong param_1,int param_2,undefined4 *param_3,longlong *param_4)

{
  longlong *plVar1;
  longlong lVar2;
  undefined1 auStack_448 [32];
  undefined1 local_428 [1008];
  ulonglong local_38;
  
  local_38 = DAT_1800791f8 ^ (ulonglong)auStack_448;
  if (param_4 != (longlong *)0x0) {
    *param_4 = 0;
  }
  if (0 < param_2) {
    if ((longlong)param_2 <= *(longlong *)(param_1 + 0x10)) {
      lVar2 = (longlong)param_2 + -1;
      if ((lVar2 < 0) || (*(longlong *)(param_1 + 0x10) <= lVar2)) {
LAB_1800414d5:
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      plVar1 = *(longlong **)(*(longlong *)(param_1 + 8) + lVar2 * 8);
      if ((plVar1 != (longlong *)0x0) &&
         ((*plVar1 != 0 && ((*(byte *)((longlong)plVar1 + 0x14) & 6) != 0)))) {
        if ((int)plVar1[2] < 1) {
          FUN_180007de0(local_428,"Assert failed in file %s line %d",
                        "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\StreamTable.cpp",0x9f);
          LogMessage(local_428,2,1);
        }
        lVar2 = (longlong)(int)plVar1[2] + -1;
        if ((lVar2 < 0) || (*(longlong *)(param_1 + 0x10) <= lVar2)) goto LAB_1800414d5;
        plVar1 = *(longlong **)(*(longlong *)(param_1 + 8) + lVar2 * 8);
        if (((plVar1 != (longlong *)0x0) && (*plVar1 != 0)) &&
           ((*(byte *)((longlong)plVar1 + 0x14) & 3) != 0)) {
          if (param_3 != (undefined4 *)0x0) {
            *param_3 = *(undefined4 *)((longlong)plVar1 + 0x14);
          }
          if (param_4 != (longlong *)0x0) {
            *param_4 = *plVar1;
            FUN_180040d90(plVar1);
          }
          return 1;
        }
      }
    }
  }
  return 0;
}

/* ---- FUNC 000414E0 FUN_1800414e0 (173 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

longlong FUN_1800414e0(longlong param_1,int param_2)

{
  longlong *plVar1;
  longlong lVar2;
  undefined1 auStack_428 [32];
  undefined1 local_408 [1008];
  ulonglong local_18;
  
  local_18 = DAT_1800791f8 ^ (ulonglong)auStack_428;
  if (0 < param_2) {
    if ((longlong)param_2 <= *(longlong *)(param_1 + 0x10)) {
      lVar2 = (longlong)param_2 + -1;
      if ((lVar2 < 0) || (*(longlong *)(param_1 + 0x10) <= lVar2)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      plVar1 = *(longlong **)(*(longlong *)(param_1 + 8) + lVar2 * 8);
      if (((plVar1 != (longlong *)0x0) && (*plVar1 != 0)) &&
         ((*(byte *)((longlong)plVar1 + 0x14) & 4) != 0)) {
        if ((int)plVar1[2] < 1) {
          FUN_180007de0(local_408,"Assert failed in file %s line %d",
                        "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\StreamTable.cpp",0xb6);
          LogMessage(local_408,2,1);
        }
        return *plVar1;
      }
    }
  }
  return 0;
}

/* ---- FUNC 00041590 FUN_180041590 (229 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
FUN_180041590(longlong param_1,
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_2,int param_3)

{
  longlong *plVar1;
  longlong lVar2;
  undefined1 auStack_438 [40];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_410;
  undefined1 local_408 [1008];
  ulonglong local_18;
  
  local_18 = DAT_1800791f8 ^ (ulonglong)auStack_438;
  local_410 = param_2;
  if (0 < param_3) {
    if ((longlong)param_3 <= *(longlong *)(param_1 + 0x10)) {
      lVar2 = (longlong)param_3 + -1;
      if ((lVar2 < 0) || (*(longlong *)(param_1 + 0x10) <= lVar2)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      plVar1 = *(longlong **)(*(longlong *)(param_1 + 8) + lVar2 * 8);
      if (((plVar1 != (longlong *)0x0) && (*plVar1 != 0)) &&
         ((*(byte *)((longlong)plVar1 + 0x14) & 4) != 0)) {
        if ((int)plVar1[2] < 1) {
          FUN_180007de0(local_408,"Assert failed in file %s line %d",
                        "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\StreamTable.cpp",0xc3);
          LogMessage(local_408,2,1);
        }
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  (param_2,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                            *)(plVar1 + 1));
        return param_2;
      }
    }
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_2,"");
  return param_2;
}

/* ---- FUNC 00041680 FUN_180041680 (174 bytes) ---- */

undefined8 FUN_180041680(longlong param_1,char *param_2,longlong *param_3)

{
  longlong *plVar1;
  bool bVar2;
  undefined7 extraout_var;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  
  lVar5 = *(longlong *)(param_1 + 0x10);
  iVar3 = 1;
  if (0 < lVar5) {
    lVar4 = 0;
    do {
      if ((lVar4 < 0) || (lVar5 <= lVar4)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      plVar1 = *(longlong **)(*(longlong *)(param_1 + 8) + lVar4 * 8);
      if ((((plVar1 != (longlong *)0x0) && (*plVar1 != 0)) &&
          ((*(byte *)((longlong)plVar1 + 0x14) & 1) != 0)) &&
         (bVar2 = FUN_180041740((longlong)plVar1,param_2), (int)CONCAT71(extraout_var,bVar2) != 0))
      {
        if (param_3 != (longlong *)0x0) {
          *param_3 = *plVar1;
          FUN_180040d90(plVar1);
        }
        return 1;
      }
      lVar5 = *(longlong *)(param_1 + 0x10);
      iVar3 = iVar3 + 1;
      lVar4 = lVar4 + 1;
    } while (iVar3 <= lVar5);
  }
  return 0;
}

/* ---- FUNC 00041730 FUN_180041730 (9 bytes) ---- */

bool FUN_180041730(longlong *param_1,longlong param_2)

{
  return param_2 == *param_1;
}

/* ---- FUNC 00041740 FUN_180041740 (217 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool FUN_180041740(longlong param_1,char *param_2)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  undefined2 *puVar4;
  longlong lVar5;
  bool bVar6;
  undefined1 auStack_148 [31];
  undefined2 uStack_129;
  ulonglong local_18;
  
  local_18 = DAT_1800791f8 ^ (ulonglong)auStack_148;
  iVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 8),
                     param_2);
  if (iVar3 == 0) {
    bVar6 = true;
  }
  else if ((*(byte *)(param_1 + 0x14) & 1) == 0) {
    bVar6 = false;
  }
  else {
    _getcwd((char *)((longlong)&uStack_129 + 1),0x104);
    puVar4 = &uStack_129;
    do {
      pcVar1 = (char *)((longlong)puVar4 + 1);
      puVar4 = (undefined2 *)((longlong)puVar4 + 1);
    } while (*pcVar1 != '\0');
    *puVar4 = DAT_180053ef4;
    puVar4 = &uStack_129;
    do {
      pcVar1 = (char *)((longlong)puVar4 + 1);
      puVar4 = (undefined2 *)((longlong)puVar4 + 1);
    } while (*pcVar1 != '\0');
    lVar5 = 0;
    do {
      cVar2 = param_2[lVar5];
      *(char *)((longlong)puVar4 + lVar5) = cVar2;
      lVar5 = lVar5 + 1;
    } while (cVar2 != '\0');
    iVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                       (param_1 + 8),(char *)((longlong)&uStack_129 + 1));
    bVar6 = iVar3 == 0;
  }
  return bVar6;
}

/* ---- FUNC 00041820 FUN_180041820 (160 bytes) ---- */

undefined8 FUN_180041820(longlong param_1,int param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  
  if (0 < param_2) {
    if ((longlong)param_2 <= *(longlong *)(param_1 + 0x10)) {
      lVar3 = (longlong)param_2 + -1;
      if ((-1 < lVar3) && (lVar3 < *(longlong *)(param_1 + 0x10))) {
        plVar1 = *(longlong **)(lVar3 * 8 + *(longlong *)(param_1 + 8));
        if ((plVar1 == (longlong *)0x0) ||
           ((*plVar1 == 0 || ((*(byte *)((longlong)plVar1 + 0x14) & 8) == 0)))) {
          if (plVar1 == (longlong *)0x0) {
            return 0x80004005;
          }
        }
        else if ((*(byte *)((longlong)plVar1 + 0x14) & 2) != 0) {
          FUN_180040e20(param_1,param_2,0);
          return 0x80004005;
        }
        if (*plVar1 == 0) {
          return 0x80004005;
        }
        if ((*(byte *)((longlong)plVar1 + 0x14) & 4) == 0) {
          return 0x80004005;
        }
        lVar2 = plVar1[2];
        if ((*(byte *)((longlong)plVar1 + 0x14) & 8) != 0) {
          FUN_180040e20(param_1,param_2,0);
        }
        FUN_180040a00(plVar1);
        operator_delete(plVar1);
        if ((int)lVar2 != 0) {
          FUN_180041b20(param_1,(int)lVar2);
        }
        if (lVar3 < *(longlong *)(param_1 + 0x10)) {
          *(undefined8 *)(lVar3 * 8 + *(longlong *)(param_1 + 8)) = 0;
          return 0;
        }
      }
                    /* WARNING: Subroutine does not return */
      AfxThrowInvalidArgException();
    }
  }
  return 0x80004005;
}

/* ---- FUNC 000418C0 FUN_1800418c0 (85 bytes) ---- */

undefined8 FUN_1800418c0(longlong param_1,int param_2)

{
  longlong lVar1;
  longlong unaff_RBX;
  longlong *unaff_RSI;
  longlong unaff_RDI;
  longlong unaff_R14;
  bool in_ZF;
  
  lVar1 = unaff_RSI[2];
  if (!in_ZF) {
    FUN_180040e20(param_1,param_2,0);
  }
  FUN_180040a00(unaff_RSI);
  operator_delete(unaff_RSI);
  if ((int)lVar1 != 0) {
    FUN_180041b20(unaff_RBX,(int)lVar1);
  }
  if (unaff_RDI < *(longlong *)(unaff_RBX + 0x10)) {
    *(undefined8 *)(unaff_R14 + *(longlong *)(unaff_RBX + 8)) = 0;
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 00041900 FUN_180041900 (16 bytes) ---- */

undefined8 FUN_180041900(void)

{
  longlong unaff_RBX;
  longlong unaff_R14;
  
  *(undefined8 *)(unaff_R14 + *(longlong *)(unaff_RBX + 8)) = 0;
  return 0;
}

/* ---- FUNC 00041920 FUN_180041920 (134 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180041920(longlong *param_1)

{
  undefined1 auStack_428 [32];
  undefined1 local_408 [1008];
  ulonglong local_18;
  
  local_18 = DAT_1800791f8 ^ (ulonglong)auStack_428;
  if (*param_1 == 0) {
    FUN_180007de0(local_408,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\StreamTable.cpp",0x59);
    LogMessage(local_408,2,1);
  }
  if ((*(byte *)((longlong)param_1 + 0x14) & 3) == 0) {
    (**(code **)(*(longlong *)*param_1 + 0x10))();
  }
  else {
    (**(code **)(*(longlong *)*param_1 + 0x10))();
    *(int *)(param_1 + 3) = (int)param_1[3] + -1;
  }
  return;
}

/* ---- FUNC 000419B0 FUN_1800419b0 (359 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_1800419b0(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  bool bVar2;
  undefined7 extraout_var;
  longlong lVar3;
  int iVar4;
  longlong lVar5;
  undefined1 auStack_438 [32];
  undefined1 local_418 [1008];
  ulonglong local_28;
  
  local_28 = DAT_1800791f8 ^ (ulonglong)auStack_438;
  iVar4 = 1;
  if (param_2 == 0) {
    FUN_180007de0(local_418,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\StreamTable.cpp",0x134);
    LogMessage(local_418,2,1);
  }
  lVar3 = *(longlong *)(param_1 + 0x10);
  if (0 < lVar3) {
    lVar5 = 0;
    do {
      if ((lVar5 < 0) || (lVar3 <= lVar5)) {
LAB_180041b12:
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      plVar1 = *(longlong **)(*(longlong *)(param_1 + 8) + lVar5 * 8);
      if ((plVar1 != (longlong *)0x0) &&
         (((*plVar1 != 0 && ((*(byte *)((longlong)plVar1 + 0x14) & 3) != 0)) &&
          (bVar2 = FUN_180041730(plVar1,param_2), (int)CONCAT71(extraout_var,bVar2) != 0)))) {
        FUN_180041920(plVar1);
        if ((int)plVar1[3] == 0) {
          if (((*(byte *)((longlong)plVar1 + 0x14) & 2) != 0) && ((int)plVar1[2] != 0)) {
            FUN_180041b20(param_1,(int)plVar1[2]);
          }
          *plVar1 = 0;
          FUN_180040a00(plVar1);
          operator_delete(plVar1);
          lVar3 = (longlong)iVar4 + -1;
          if ((lVar3 < 0) || (*(longlong *)(param_1 + 0x10) <= lVar3)) goto LAB_180041b12;
          *(undefined8 *)(*(longlong *)(param_1 + 8) + lVar3 * 8) = 0;
        }
        return 0;
      }
      iVar4 = iVar4 + 1;
      lVar5 = lVar5 + 1;
    } while (iVar4 <= lVar3);
  }
  return 0x80004005;
}

/* ---- FUNC 00041B20 FUN_180041b20 (93 bytes) ---- */

undefined8 FUN_180041b20(longlong param_1,int param_2)

{
  longlong *plVar1;
  longlong lVar2;
  
  lVar2 = (longlong)param_2 + -1;
  if ((lVar2 < 0) || (*(longlong *)(param_1 + 0x10) <= lVar2)) {
LAB_180041c1c:
                    /* WARNING: Subroutine does not return */
    AfxThrowInvalidArgException();
  }
  plVar1 = *(longlong **)(lVar2 * 8 + *(longlong *)(param_1 + 8));
  if (plVar1 != (longlong *)0x0) {
    if ((*plVar1 != 0) && ((*(byte *)((longlong)plVar1 + 0x14) & 3) != 0)) {
      FUN_180041920(plVar1);
      if ((int)plVar1[3] == 0) {
        if ((int)plVar1[2] != 0) {
          FUN_180041b20(param_1,(int)plVar1[2]);
        }
        *plVar1 = 0;
        FUN_180040a00(plVar1);
        operator_delete(plVar1);
        if (*(longlong *)(param_1 + 0x10) <= lVar2) goto LAB_180041c1c;
        *(undefined8 *)(lVar2 * 8 + *(longlong *)(param_1 + 8)) = 0;
      }
      return 0;
    }
    if ((plVar1 != (longlong *)0x0) &&
       ((*plVar1 != 0 && ((*(byte *)((longlong)plVar1 + 0x14) & 4) != 0)))) {
      FUN_180041920(plVar1);
      return 0;
    }
  }
  return 0x80004005;
}

/* ---- FUNC 00041B7D FUN_180041b7d (164 bytes) ---- */

undefined8 FUN_180041b7d(undefined8 param_1,int param_2)

{
  longlong *unaff_RBX;
  longlong unaff_RSI;
  longlong unaff_RDI;
  longlong unaff_R14;
  
  if (param_2 != 0) {
    FUN_180041b20(unaff_RSI,param_2);
  }
  *unaff_RBX = 0;
  FUN_180040a00(unaff_RBX);
  operator_delete(unaff_RBX);
  if (unaff_RDI < *(longlong *)(unaff_RSI + 0x10)) {
    *(undefined8 *)(unaff_R14 + *(longlong *)(unaff_RSI + 8)) = 0;
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  AfxThrowInvalidArgException();
}

/* ---- FUNC 00041BC4 FUN_180041bc4 (28 bytes) ---- */

undefined8 FUN_180041bc4(void)

{
  longlong unaff_RSI;
  longlong unaff_R14;
  
  *(undefined8 *)(unaff_R14 + *(longlong *)(unaff_RSI + 8)) = 0;
  return 0;
}

/* ---- FUNC 00041C30 FUN_180041c30 (122 bytes) ---- */

void FUN_180041c30(longlong param_1,uint param_2)

{
  char cVar1;
  DWORD DVar2;
  char *pcVar3;
  uint dwMessageId;
  char *local_res18 [2];
  
  dwMessageId = param_2 & 0xffff;
  if ((param_2 & 0x1fff0000) != 0x80000) {
    dwMessageId = param_2;
  }
  DVar2 = FormatMessageA(0x1100,(LPCVOID)0x0,dwMessageId,0x400,(LPSTR)local_res18,0,(va_list *)0x0);
  if (DVar2 != 0) {
    pcVar3 = local_res18[0];
    do {
      cVar1 = *pcVar3;
      pcVar3[param_1 - (longlong)local_res18[0]] = cVar1;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    LocalFree(local_res18[0]);
  }
  return;
}

/* ---- FUNC 00041CB0 STInqCOModeltyp (704 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 STInqCOModeltyp(char *param_1,char *param_2,int param_3,longlong param_4)

{
  int iVar1;
  uint uVar2;
  HRESULT HVar3;
  LSTATUS LVar4;
  wchar_t *_Dest;
  char *_Dest_00;
  size_t _Size;
  longlong lVar5;
  longlong lVar7;
  char *pcVar8;
  longlong lVar9;
  undefined8 unaff_R13;
  undefined1 auStackY_168 [32];
  DWORD local_138 [2];
  wchar_t *local_130;
  int local_128;
  HKEY local_120;
  longlong *local_118;
  HKEY local_110;
  char *local_108;
  HKEY local_100;
  CLSID local_f8;
  undefined4 local_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  BYTE local_d8 [128];
  ulonglong local_58;
  longlong lVar6;
  
                    /* 0x41cb0  470  STInqCOModeltyp */
  local_58 = DAT_1800791f8 ^ (ulonglong)auStackY_168;
  lVar7 = -1;
  lVar5 = -1;
  do {
    lVar6 = lVar5;
    lVar5 = lVar6 + 1;
  } while (param_1[lVar5] != '\0');
  lVar9 = param_4;
  local_128 = param_3;
  local_108 = param_2;
  _Dest = malloc((longlong)((int)lVar6 + 2) * 2);
  iVar1 = ___mb_cur_max_func();
  mbstowcs(_Dest,param_1,(longlong)(iVar1 * (int)lVar5));
  CLSIDFromString(_Dest,&local_f8);
  uVar2 = ProgIDFromCLSID(&local_f8,&local_130);
  _Dest_00 = local_108;
  pcVar8 = param_1;
  if (local_130 != (wchar_t *)0x0) {
    lVar5 = -1;
    do {
      lVar5 = lVar5 + 1;
    } while (local_130[lVar5] != L'\0');
    _Size = (size_t)((int)lVar5 + 1);
    _Dest_00 = malloc(_Size);
    wcstombs(_Dest_00,local_130,_Size);
    pcVar8 = _Dest_00;
  }
  if ((int)uVar2 < 0) {
    FUN_180007de0(param_4,"%s failed with error : ",pcVar8,lVar9);
    do {
      lVar7 = lVar7 + 1;
    } while (*(char *)(param_4 + lVar7) != '\0');
    FUN_180041c30((int)lVar7 + param_4,uVar2);
    if (local_130 == (wchar_t *)0x0) {
      return unaff_R13;
    }
    free(_Dest_00);
    LocalFree(local_130);
    return unaff_R13;
  }
  local_118 = (longlong *)0x0;
  HVar3 = CoCreateInstance((IID *)&DAT_180057af8,(LPUNKNOWN)0x0,1,(IID *)&DAT_180057b08,&local_118);
  if (HVar3 < 0) goto LAB_180041f31;
  local_e8 = _DAT_1800573c8;
  uStack_e4 = _UNK_1800573cc;
  uStack_e0 = _UNK_1800573d0;
  uStack_dc = _UNK_1800573d4;
  (**(code **)(*local_118 + 0x30))(local_118,&local_f8,1,&local_e8);
  local_110 = (HKEY)0x0;
  RegOpenKeyA((HKEY)0xffffffff80000000,"CLSID",&local_110);
  local_d8[0] = '\0';
  local_138[0] = 0x80;
  local_120 = (HKEY)0x0;
  if (local_110 == (HKEY)0x0) goto LAB_180041f31;
  LVar4 = RegOpenKeyA(local_110,param_1,&local_120);
  if (LVar4 == 0) {
    LVar4 = RegOpenKeyA(local_120,"CapeDescription",&local_100);
    if (LVar4 == 0) {
      RegQueryValueExA(local_100,"name",(LPDWORD)0x0,(LPDWORD)0x0,local_d8,local_138);
    }
    if (local_d8[0] == '\0') {
      local_138[0] = 0x80;
      RegQueryValueExA(local_120,"",(LPDWORD)0x0,(LPDWORD)0x0,local_d8,local_138);
      goto LAB_180041f0f;
    }
  }
  else {
LAB_180041f0f:
    if (local_d8[0] == '\0') goto LAB_180041f31;
  }
  strncpy(local_108,(char *)local_d8,(longlong)local_128);
LAB_180041f31:
  if (local_130 != (wchar_t *)0x0) {
    free(_Dest_00);
    LocalFree(local_130);
  }
  return unaff_R13;
}

/* ---- FUNC 00041F70 STtypchk (663 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 STtypchk(longlong *param_1,longlong param_2,int param_3,undefined8 param_4)

{
  int iVar1;
  uint uVar2;
  HRESULT HVar3;
  LCID LVar4;
  int iVar5;
  wchar_t *_Dest;
  undefined8 uVar6;
  longlong lVar7;
  char *pcVar8;
  char *pcVar9;
  longlong lVar10;
  longlong *_Memory;
  size_t _Size;
  undefined8 *puVar12;
  undefined1 auStackY_a8 [32];
  int local_78;
  undefined4 uStack_74;
  longlong *local_70;
  CLSID local_68;
  undefined8 local_58;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  ulonglong local_48;
  longlong lVar11;
  
                    /* 0x41f70  519  STtypchk */
  local_48 = DAT_1800791f8 ^ (ulonglong)auStackY_a8;
  lVar7 = -1;
  uVar6 = 0;
  lVar10 = -1;
  do {
    lVar11 = lVar10;
    lVar10 = lVar11 + 1;
  } while (*(char *)((longlong)param_1 + lVar10) != '\0');
  _Dest = malloc((longlong)((int)lVar11 + 2) * 2);
  iVar1 = ___mb_cur_max_func();
  mbstowcs(_Dest,(char *)param_1,(longlong)(iVar1 * (int)lVar10));
  CLSIDFromString(_Dest,&local_68);
  uVar2 = ProgIDFromCLSID(&local_68,(LPOLESTR *)&local_78);
  _Memory = local_70;
  if (CONCAT44(uStack_74,local_78) != 0) {
    lVar10 = -1;
    do {
      lVar10 = lVar10 + 1;
    } while (*(short *)(CONCAT44(uStack_74,local_78) + lVar10 * 2) != 0);
    _Size = (size_t)((int)lVar10 + 1);
    param_1 = malloc(_Size);
    wcstombs((char *)param_1,(wchar_t *)CONCAT44(uStack_74,local_78),_Size);
    _Memory = param_1;
  }
  if ((int)uVar2 < 0) {
    FUN_180007de0(param_2,"%s failed with error : ",param_1,param_4);
    do {
      lVar7 = lVar7 + 1;
    } while (*(char *)(lVar7 + param_2) != '\0');
    FUN_180041c30((int)lVar7 + param_2,uVar2);
    if (CONCAT44(uStack_74,local_78) != 0) {
      free(_Memory);
      LocalFree((HLOCAL)CONCAT44(uStack_74,local_78));
    }
    uVar6 = 1;
  }
  else {
    local_70 = (longlong *)0x0;
    HVar3 = CoCreateInstance((IID *)&DAT_180057af8,(LPUNKNOWN)0x0,1,(IID *)&DAT_180057b08,&local_70)
    ;
    iVar1 = local_78;
    if (-1 < HVar3) {
      local_58 = (wchar_t *)CONCAT44(_UNK_1800573cc,_DAT_1800573c8);
      uStack_50 = _UNK_1800573d0;
      uStack_4c = _UNK_1800573d4;
      iVar1 = (**(code **)(*local_70 + 0x30))(local_70,&local_68,1,&local_58);
    }
    if (iVar1 == 1) {
      local_58 = (wchar_t *)0x0;
      LVar4 = GetUserDefaultLCID();
      puVar12 = &local_58;
      iVar1 = (**(code **)(*local_70 + 0x20))(local_70,&DAT_1800573c8,LVar4);
      if (-1 < iVar1) {
        lVar10 = -1;
        do {
          lVar10 = lVar10 + 1;
        } while (local_58[lVar10] != L'\0');
        iVar1 = (int)lVar10 + 1;
        FUN_180007de0(param_2,"%s does not implement Component Category : \"",param_1,puVar12);
        do {
          lVar7 = lVar7 + 1;
        } while (*(char *)(lVar7 + param_2) != '\0');
        pcVar8 = (char *)((int)lVar7 + param_2);
        iVar5 = ___mb_cur_max_func();
        if (iVar1 < param_3) {
          param_3 = iVar1;
        }
        wcstombs(pcVar8,local_58,(longlong)(iVar5 * param_3));
        pcVar8 = pcVar8 + -1;
        do {
          pcVar9 = pcVar8;
          pcVar8 = pcVar9 + 1;
        } while (pcVar9[1] != '\0');
        *(undefined2 *)(pcVar9 + 1) = DAT_180057420;
        pcVar9[3] = DAT_180057422;
        LocalFree(local_58);
      }
      uVar6 = 2;
    }
    if (CONCAT44(uStack_74,local_78) != 0) {
      free(_Memory);
      LocalFree((HLOCAL)CONCAT44(uStack_74,local_78));
    }
  }
  return uVar6;
}

/* ---- FUNC 00042210 FUN_180042210 (258 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180042210(longlong param_1,longlong param_2,int param_3)

{
  int iVar1;
  byte *pbVar2;
  longlong lVar3;
  undefined1 auStack_428 [32];
  undefined1 local_408 [1008];
  ulonglong local_18;
  
  local_18 = DAT_1800791f8 ^ (ulonglong)auStack_428;
  iVar1 = param_3 / 3;
  if (param_3 != iVar1 * 3) {
    FUN_180007de0(local_408,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\visbin.cpp",0xc);
    LogMessage(local_408);
  }
  if (0 < iVar1) {
    lVar3 = 0;
    pbVar2 = (byte *)(param_1 + 2);
    do {
      *(byte *)(param_2 + lVar3 * 4) = (pbVar2[-2] >> 2) + 0x30;
      *(byte *)(param_2 + 1 + lVar3 * 4) = ((pbVar2[-2] & 3) + 3) * '\x10' + (pbVar2[-1] >> 4);
      *(byte *)(param_2 + 2 + lVar3 * 4) = ((pbVar2[-1] & 0xf) + 0xc) * '\x04' + (*pbVar2 >> 6);
      *(byte *)(param_2 + 3 + lVar3 * 4) = (*pbVar2 & 0x3f) + 0x30;
      lVar3 = lVar3 + 1;
      pbVar2 = pbVar2 + 3;
    } while (lVar3 < iVar1);
  }
  return;
}

/* ---- FUNC 00042320 FUN_180042320 (246 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180042320(longlong param_1,longlong param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  longlong lVar5;
  longlong lVar6;
  undefined1 auStack_428 [32];
  undefined1 local_408 [1008];
  ulonglong local_18;
  
  local_18 = DAT_1800791f8 ^ (ulonglong)auStack_428;
  uVar2 = param_3 >> 0x1f & 3;
  uVar1 = param_3 + uVar2;
  iVar4 = (int)uVar1 >> 2;
  if ((uVar1 & 3) != uVar2) {
    FUN_180007de0(local_408,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\visbin.cpp",0x28);
    LogMessage(local_408,2,1);
  }
  lVar5 = (longlong)iVar4;
  if (0 < iVar4) {
    pcVar3 = (char *)(param_1 + 2);
    lVar6 = 0;
    do {
      *(byte *)(lVar6 + param_2) =
           (pcVar3[-2] + '\x10') * '\x04' + ((byte)(pcVar3[-1] - 0x30U) >> 4);
      *(byte *)(lVar6 + 1 + param_2) = ((byte)(*pcVar3 - 0x30U) >> 2) + pcVar3[-1] * '\x10';
      *(char *)(lVar6 + 2 + param_2) = *pcVar3 * '@' + -0x30 + pcVar3[1];
      lVar5 = lVar5 + -1;
      pcVar3 = pcVar3 + 4;
      lVar6 = lVar6 + 3;
    } while (lVar5 != 0);
  }
  return;
}

/* ---- FUNC 00042420 FUN_180042420 (45 bytes) ---- */

undefined8 FUN_180042420(undefined4 param_1)

{
  switch(param_1) {
  case 0:
    return 0;
  case 1:
  case 2:
    return 1;
  default:
    return 0x800300fd;
  }
}

/* ---- FUNC 00042480 FUN_180042480 (81 bytes) ---- */

undefined8 FUN_180042480(longlong *param_1,longlong *param_2)

{
  HRESULT HVar1;
  int iVar2;
  HGLOBAL hGlobal;
  IStorage *local_res18;
  LPSTREAM local_res20;
  LPLOCKBYTES local_38;
  undefined8 local_30;
  ULARGE_INTEGER local_28 [2];
  
  hGlobal = GlobalAlloc(0x42,0);
  local_38 = (ILockBytes *)0x0;
  HVar1 = CreateILockBytesOnHGlobal(hGlobal,0,&local_38);
  if (HVar1 == 0) {
    local_res18 = (IStorage *)0x0;
    HVar1 = StgCreateDocfileOnILockBytes(local_38,0x11002,0,&local_res18);
    (*local_38->lpVtbl->Release)(local_38);
    if (HVar1 == 0) {
      iVar2 = (**(code **)(*param_1 + 0x38))(param_1,0,0,0,local_res18);
      if (iVar2 == 0) {
        HVar1 = (*local_res18->lpVtbl->Commit)(local_res18,8);
        if (HVar1 != 0) {
          (*local_res18->lpVtbl->Commit)(local_res18,0);
        }
      }
      (*local_res18->lpVtbl->Release)(local_res18);
      local_res20 = (IStream *)0x0;
      HVar1 = CreateStreamOnHGlobal(hGlobal,0,&local_res20);
      if (HVar1 == 0) {
        local_30 = 0;
        (*local_res20->lpVtbl->Seek)(local_res20,(LARGE_INTEGER)0x0,0,local_28);
        ZStgCompressStream((longlong *)local_res20,param_2);
        (*local_res20->lpVtbl->Release)(local_res20);
      }
    }
  }
  GlobalFree(hGlobal);
  return 0x80004005;
}

/* ---- FUNC 000424D1 FUN_1800424d1 (50 bytes) ---- */

/* WARNING: Exceeded maximum restarts with more pending */

undefined8
FUN_1800424d1(ILockBytes *param_1,undefined8 param_2,DWORD param_3,IStorage **param_4,
             undefined8 param_5,longlong *param_6)

{
  HRESULT HVar1;
  int iVar2;
  longlong *unaff_RBP;
  longlong *unaff_RSI;
  HGLOBAL unaff_RDI;
  LPSTREAM unaff_R14;
  LPSTREAM in_stack_00000088;
  
  HVar1 = StgCreateDocfileOnILockBytes(param_1,0x11002,param_3,param_4);
  (**(code **)(*param_6 + 0x10))();
  if (HVar1 == 0) {
    iVar2 = (**(code **)(*unaff_RSI + 0x38))();
    if (iVar2 == 0) {
      iVar2 = (*unaff_R14->lpVtbl->Revert)();
      if (iVar2 != 0) {
        (*unaff_R14->lpVtbl->Revert)();
      }
    }
    (*unaff_R14->lpVtbl->Release)();
    in_stack_00000088 = unaff_R14;
    HVar1 = CreateStreamOnHGlobal(unaff_RDI,0,&stack0x00000088);
    if (HVar1 == 0) {
      (*in_stack_00000088->lpVtbl->Seek)();
      ZStgCompressStream((longlong *)in_stack_00000088,unaff_RBP);
      (*in_stack_00000088->lpVtbl->Release)();
    }
  }
  GlobalFree(unaff_RDI);
  return 0x80004005;
}

/* ---- FUNC 00042503 FUN_180042503 (206 bytes) ---- */

/* WARNING: Exceeded maximum restarts with more pending */

undefined8 FUN_180042503(void)

{
  int iVar1;
  HRESULT HVar2;
  longlong *unaff_RBP;
  longlong *unaff_RSI;
  HGLOBAL unaff_RDI;
  LPSTREAM unaff_R14;
  longlong *in_stack_00000080;
  LPSTREAM in_stack_00000088;
  
  iVar1 = (**(code **)(*unaff_RSI + 0x38))();
  if (iVar1 == 0) {
    iVar1 = (**(code **)(*in_stack_00000080 + 0x48))();
    if (iVar1 != 0) {
      (**(code **)(*in_stack_00000080 + 0x48))();
    }
  }
  (**(code **)(*in_stack_00000080 + 0x10))();
  in_stack_00000088 = unaff_R14;
  HVar2 = CreateStreamOnHGlobal(unaff_RDI,0,&stack0x00000088);
  if (HVar2 == 0) {
    (*in_stack_00000088->lpVtbl->Seek)();
    ZStgCompressStream((longlong *)in_stack_00000088,unaff_RBP);
    (*in_stack_00000088->lpVtbl->Release)();
  }
  GlobalFree(unaff_RDI);
  return 0x80004005;
}

/* ---- FUNC 000425E0 ZStgCompressStream (79 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong ZStgCompressStream(longlong *param_1,longlong *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  undefined1 auStackY_568 [32];
  uint local_508;
  uint local_504;
  ulonglong local_500;
  uint local_4f8 [2];
  undefined8 local_4f0;
  undefined *local_4e8;
  undefined8 uStack_4e0;
  undefined *local_4d8;
  undefined8 uStack_4d0;
  undefined8 local_4c8;
  undefined8 uStack_4c0;
  undefined8 local_4b8;
  undefined8 uStack_4b0;
  undefined8 local_4a8;
  undefined8 uStack_4a0;
  undefined8 local_498;
  undefined8 local_488;
  undefined8 uStack_480;
  ulonglong local_478;
  undefined8 uStack_470;
  undefined8 local_468;
  undefined8 uStack_460;
  undefined8 local_458;
  undefined8 uStack_450;
  undefined8 local_448;
  undefined8 uStack_440;
  undefined1 local_438 [1008];
  ulonglong local_48;
  
                    /* 0x425e0  544  ZStgCompressStream */
  local_48 = DAT_1800791f8 ^ (ulonglong)auStackY_568;
  uVar2 = 0;
  local_500 = 0;
  local_4f0 = 0;
  if ((param_1 == (longlong *)0x0) || (param_2 == (longlong *)0x0)) {
    return 0x80004003;
  }
  local_498 = 0;
  local_4e8 = (undefined *)0x0;
  uStack_4e0 = 0;
  local_4d8 = (undefined *)0x0;
  uStack_4d0 = 0;
  local_4c8 = 0;
  uStack_4c0 = 0;
  local_4b8 = 0;
  uStack_4b0 = 0;
  local_4a8 = 0;
  uStack_4a0 = 0;
  (**(code **)(*param_1 + 0x28))(0,0,0,&local_4f0);
  local_488 = 0;
  uStack_480 = 0;
  local_478 = 0;
  uStack_470 = 0;
  local_468 = 0;
  uStack_460 = 0;
  local_458 = 0;
  uStack_450 = 0;
  local_448 = 0;
  uStack_440 = 0;
  iVar1 = (**(code **)(*param_1 + 0x60))(param_1,&local_488,1);
  if (iVar1 == 0) {
    if ((int)local_478 == 0) {
      return local_478 & 0xffffffff;
    }
    if ((int)local_478 - 1U < 0x15) {
      uVar5 = (**(code **)(*param_1 + 0x18))(param_1,&DAT_18007b840,0x10000,&local_508);
      if ((int)uVar5 < 0) {
        return uVar5;
      }
      if (local_508 == 0) {
        return uVar5;
      }
      uVar2 = (**(code **)(*param_2 + 0x20))(param_2,&DAT_18007b840,local_508,&local_504);
      if (local_508 == local_504) {
        return (ulonglong)uVar2;
      }
      FUN_180007de0(local_438,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\ZStg.cpp",0x15f);
      LogMessage(local_438,2,1);
      return (ulonglong)uVar2;
    }
  }
  FUN_180007de0(&DAT_18008b840,"%c%c%c%c%c%c%c%c%c%c",0x1f,0x8b);
  uVar5 = (**(code **)(*param_2 + 0x20))();
  if (-1 < (int)uVar5) {
    local_4f8[0] = FUN_18004c120(0,(uint *)0x0,0);
    local_4d8 = &DAT_18008b840;
    uStack_4d0 = CONCAT44(uStack_4d0._4_4_,0x10000);
    uVar5 = FUN_1800497d0((longlong)&local_4e8,0xffffffff,8,-0xf,8,0,"1.2.11",0x58);
    uVar4 = (uint)uVar5;
    uVar5 = uVar5 & 0xffffffff;
    uVar3 = 0;
    if (-1 < (int)uVar4) {
      while (((uVar2 = uVar3, uVar4 = (uint)uVar5, uVar2 == 0 &&
              (uVar2 = (**(code **)(*param_1 + 0x18))(param_1,&DAT_18007b840,0x10000,&local_508),
              -1 < (int)uVar2)) && (local_508 != 0))) {
        local_4e8 = &DAT_18007b840;
        uStack_4e0 = CONCAT44(uStack_4e0._4_4_,local_508);
        local_4f8[0] = FUN_18004c120(local_4f8[0],(uint *)&DAT_18007b840,local_508);
        if ((int)uVar4 < 0) break;
        do {
          uVar4 = (uint)uVar5;
          if (uVar2 != 0) goto LAB_18004295f;
          uVar3 = FUN_180048dd0((longlong *)&local_4e8,2);
          uVar4 = 0;
          if (uVar3 != 1) {
            uVar4 = uVar3;
          }
          if ((int)uVar4 < 0) {
            uVar6 = FUN_180042420(uVar4);
            uVar2 = (uint)uVar6;
            if (-1 < (int)(uint)uVar6) {
              uVar2 = 0;
            }
            goto LAB_180042a03;
          }
          iVar1 = (int)local_4d8 + 0x7ff747c0;
          if (iVar1 == 0) break;
          local_500 = local_500 & 0xffffffff00000000;
          uVar2 = (**(code **)(*param_2 + 0x20))(param_2,&DAT_18008b840,iVar1,&local_500);
          if (iVar1 != (int)local_500) {
            FUN_180007de0(local_438,"Assert failed in file %s line %d",
                          "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\ZStg.cpp",0x188);
            LogMessage(local_438,2,1);
          }
          uStack_4d0 = CONCAT44(uStack_4d0._4_4_,0x10000);
          local_4d8 = &DAT_18008b840;
          uVar5 = (ulonglong)uVar4;
        } while (iVar1 == 0x10000);
        uVar5 = (ulonglong)uVar4;
        uVar3 = uVar2;
      }
    }
LAB_18004295f:
    if (-1 < (int)uVar2) {
      uVar2 = 0;
    }
    while ((-1 < (int)uVar4 && (uVar2 == 0))) {
      uVar4 = FUN_180048dd0((longlong *)&local_4e8,4);
      local_500 = local_500 & 0xffffffff00000000;
      iVar1 = (int)local_4d8 + 0x7ff747c0;
      if (iVar1 == 0) break;
      uVar2 = (**(code **)(*param_2 + 0x20))(param_2,&DAT_18008b840,iVar1,&local_500);
      if (iVar1 != (int)local_500) {
        FUN_180007de0(local_438,"Assert failed in file %s line %d",
                      "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\ZStg.cpp",0x199);
        LogMessage(local_438,2,1);
      }
      local_4d8 = &DAT_18008b840;
      uStack_4d0 = CONCAT44(uStack_4d0._4_4_,0x10000);
      memset(&DAT_18008b840,0,0x10000);
    }
LAB_180042a03:
    uVar6 = FUN_180049730((longlong)&local_4e8);
    if ((-1 < (int)uVar6) && (-1 < (int)uVar2)) {
      (**(code **)(*param_2 + 0x20))(param_2,local_4f8,4,&local_504);
      (**(code **)(*param_2 + 0x20))(param_2,(longlong)&uStack_4e0 + 4,4,&local_504);
    }
    uVar5 = FUN_180042420((int)uVar6);
  }
  return uVar5;
}

/* ---- FUNC 0004262F FUN_18004262f (122 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_18004262f(longlong *param_1)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  undefined8 unaff_RBX;
  undefined8 *unaff_RBP;
  uint unaff_ESI;
  uint uVar7;
  longlong in_R11;
  undefined8 unaff_R12;
  longlong *unaff_R13;
  longlong *unaff_R15;
  undefined4 extraout_XMM0_Da;
  undefined4 extraout_XMM0_Da_00;
  undefined4 uVar8;
  undefined8 in_XMM0_Qa;
  undefined4 uVar9;
  undefined4 in_XMM0_Dc;
  undefined4 in_XMM0_Dd;
  uint uStack0000000000000060;
  uint uStack0000000000000064;
  int in_stack_00000068;
  uint in_stack_00000070;
  
  uVar9 = (undefined4)((ulonglong)in_XMM0_Qa >> 0x20);
  uVar8 = (undefined4)in_XMM0_Qa;
  *(undefined8 *)(in_R11 + 0x18) = unaff_RBX;
  *(undefined8 *)(in_R11 + -0x30) = unaff_R12;
  unaff_RBP[-6] = 0;
  lVar1 = *param_1;
  *(undefined4 *)(unaff_RBP + -0x10) = uVar8;
  *(undefined4 *)((longlong)unaff_RBP + -0x7c) = uVar9;
  *(undefined4 *)(unaff_RBP + -0xf) = in_XMM0_Dc;
  *(undefined4 *)((longlong)unaff_RBP + -0x74) = in_XMM0_Dd;
  *(undefined4 *)(unaff_RBP + -0xe) = uVar8;
  *(undefined4 *)((longlong)unaff_RBP + -0x6c) = uVar9;
  *(undefined4 *)(unaff_RBP + -0xd) = in_XMM0_Dc;
  *(undefined4 *)((longlong)unaff_RBP + -100) = in_XMM0_Dd;
  *(undefined4 *)(unaff_RBP + -0xc) = uVar8;
  *(undefined4 *)((longlong)unaff_RBP + -0x5c) = uVar9;
  *(undefined4 *)(unaff_RBP + -0xb) = in_XMM0_Dc;
  *(undefined4 *)((longlong)unaff_RBP + -0x54) = in_XMM0_Dd;
  *(undefined4 *)(unaff_RBP + -10) = uVar8;
  *(undefined4 *)((longlong)unaff_RBP + -0x4c) = uVar9;
  *(undefined4 *)(unaff_RBP + -9) = in_XMM0_Dc;
  *(undefined4 *)((longlong)unaff_RBP + -0x44) = in_XMM0_Dd;
  *(undefined4 *)(unaff_RBP + -8) = uVar8;
  *(undefined4 *)((longlong)unaff_RBP + -0x3c) = uVar9;
  *(undefined4 *)(unaff_RBP + -7) = in_XMM0_Dc;
  *(undefined4 *)((longlong)unaff_RBP + -0x34) = in_XMM0_Dd;
  (**(code **)(lVar1 + 0x28))(param_1,unaff_ESI,0,&stack0x00000078);
  lVar1 = *unaff_R13;
  unaff_RBP[-4] = 0;
  unaff_RBP[-3] = 0;
  unaff_RBP[-2] = 0;
  unaff_RBP[-1] = 0;
  *unaff_RBP = 0;
  unaff_RBP[1] = 0;
  unaff_RBP[2] = 0;
  unaff_RBP[3] = 0;
  unaff_RBP[4] = 0;
  unaff_RBP[5] = 0;
  iVar2 = (**(code **)(lVar1 + 0x60))(0,unaff_RBP + -4,unaff_ESI + 1);
  if (iVar2 == 0) {
    if (*(int *)(unaff_RBP + -2) == 0) {
      return 0;
    }
    if (*(int *)(unaff_RBP + -2) - 1U < 0x15) {
      uVar5 = (**(code **)(*unaff_R13 + 0x18))
                        (extraout_XMM0_Da,&DAT_18007b840,0x10000,&stack0x00000060);
      if ((int)uVar5 < 0) {
        return uVar5;
      }
      if (uStack0000000000000060 == 0) {
        return uVar5;
      }
      uVar3 = (**(code **)(*unaff_R15 + 0x20))
                        (extraout_XMM0_Da_00,&DAT_18007b840,uStack0000000000000060,
                         (longlong)&stack0x00000060 + 4);
      if (uStack0000000000000060 == uStack0000000000000064) {
        return (ulonglong)uVar3;
      }
      FUN_180007de0(unaff_RBP + 6,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\ZStg.cpp",0x15f);
      LogMessage(unaff_RBP + 6,2,1);
      return (ulonglong)uVar3;
    }
  }
  FUN_180007de0(&DAT_18008b840,"%c%c%c%c%c%c%c%c%c%c",0x1f,0x8b);
  uVar5 = (**(code **)(*unaff_R15 + 0x20))();
  if (-1 < (int)uVar5) {
    in_stack_00000070 = FUN_18004c120(0,(uint *)0x0,0);
    unaff_RBP[-0xe] = &DAT_18008b840;
    *(undefined4 *)(unaff_RBP + -0xd) = 0x10000;
    uVar5 = FUN_1800497d0((longlong)(unaff_RBP + -0x10),0xffffffff,8,-0xf,8,unaff_ESI,"1.2.11",0x58)
    ;
    uVar3 = (uint)uVar5;
    uVar5 = uVar5 & 0xffffffff;
    uVar7 = unaff_ESI;
    if (-1 < (int)uVar3) {
      while (((uVar3 = (uint)uVar5, unaff_ESI == 0 &&
              (unaff_ESI = (**(code **)(*unaff_R13 + 0x18))(), -1 < (int)unaff_ESI)) &&
             (uStack0000000000000060 != 0))) {
        unaff_RBP[-0x10] = &DAT_18007b840;
        *(uint *)(unaff_RBP + -0xf) = uStack0000000000000060;
        in_stack_00000070 =
             FUN_18004c120(in_stack_00000070,(uint *)&DAT_18007b840,uStack0000000000000060);
        if ((int)uVar3 < 0) break;
        while( true ) {
          uVar3 = (uint)uVar5;
          if (unaff_ESI != 0) goto LAB_18004295f;
          uVar4 = FUN_180048dd0(unaff_RBP + -0x10,2);
          uVar3 = uVar7;
          if (uVar4 != 1) {
            uVar3 = uVar4;
          }
          if ((int)uVar3 < 0) {
            uVar6 = FUN_180042420(uVar3);
            unaff_ESI = (uint)uVar6;
            if (-1 < (int)(uint)uVar6) {
              unaff_ESI = uVar7;
            }
            goto LAB_180042a03;
          }
          iVar2 = *(int *)(unaff_RBP + -0xe) + 0x7ff747c0;
          if (*(int *)(unaff_RBP + -0xe) == -0x7ff747c0) break;
          in_stack_00000068 = 0;
          unaff_ESI = (**(code **)(*unaff_R15 + 0x20))();
          if (iVar2 != in_stack_00000068) {
            FUN_180007de0(unaff_RBP + 6,"Assert failed in file %s line %d",
                          "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\ZStg.cpp",0x188);
            LogMessage(unaff_RBP + 6,2,1);
          }
          *(undefined4 *)(unaff_RBP + -0xd) = 0x10000;
          unaff_RBP[-0xe] = &DAT_18008b840;
          uVar5 = (ulonglong)uVar3;
          if (iVar2 != 0x10000) break;
          uVar7 = 0;
        }
        uVar5 = (ulonglong)uVar3;
        uVar7 = 0;
      }
    }
LAB_18004295f:
    if (-1 < (int)unaff_ESI) {
      unaff_ESI = uVar7;
    }
    while ((-1 < (int)uVar3 && (unaff_ESI == 0))) {
      uVar3 = FUN_180048dd0(unaff_RBP + -0x10,4);
      iVar2 = *(int *)(unaff_RBP + -0xe);
      in_stack_00000068 = 0;
      if (iVar2 == -0x7ff747c0) break;
      unaff_ESI = (**(code **)(*unaff_R15 + 0x20))();
      if (iVar2 + 0x7ff747c0 != in_stack_00000068) {
        FUN_180007de0(unaff_RBP + 6,"Assert failed in file %s line %d",
                      "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\ZStg.cpp",0x199);
        LogMessage(unaff_RBP + 6,2,1);
      }
      unaff_RBP[-0xe] = &DAT_18008b840;
      *(undefined4 *)(unaff_RBP + -0xd) = 0x10000;
      memset(&DAT_18008b840,0,0x10000);
    }
LAB_180042a03:
    uVar6 = FUN_180049730((longlong)(unaff_RBP + -0x10));
    if ((-1 < (int)uVar6) && (-1 < (int)unaff_ESI)) {
      uVar8 = (**(code **)(*unaff_R15 + 0x20))();
      (**(code **)(*unaff_R15 + 0x20))
                (uVar8,(longlong)unaff_RBP + -0x74,4,(longlong)&stack0x00000060 + 4);
    }
    uVar5 = FUN_180042420((int)uVar6);
  }
  return uVar5;
}

/* ---- FUNC 000426A9 FUN_1800426a9 (29 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1800426a9(void)

{
  return;
}

/* ---- FUNC 000426C6 FUN_1800426c6 (249 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_1800426c6(void)

{
  int iVar1;
  int in_EAX;
  uint uVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  longlong unaff_RBP;
  uint unaff_ESI;
  uint uVar6;
  longlong *unaff_R13;
  longlong *unaff_R15;
  uint uStack0000000000000060;
  uint uStack0000000000000064;
  uint uStack0000000000000070;
  
  if (in_EAX - 1U < 0x15) {
    uVar4 = (**(code **)(*unaff_R13 + 0x18))();
    if ((-1 < (int)uVar4) && (uStack0000000000000060 != 0)) {
      uVar2 = (**(code **)(*unaff_R15 + 0x20))();
      uVar4 = (ulonglong)uVar2;
      if (uStack0000000000000060 != uStack0000000000000064) {
        FUN_180007de0(unaff_RBP + 0x30,"Assert failed in file %s line %d",
                      "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\ZStg.cpp",0x15f);
        LogMessage(unaff_RBP + 0x30,2,1);
      }
    }
  }
  else {
    FUN_180007de0(&DAT_18008b840,"%c%c%c%c%c%c%c%c%c%c",0x1f,0x8b);
    uVar4 = (**(code **)(*unaff_R15 + 0x20))();
    if (-1 < (int)uVar4) {
      uStack0000000000000070 = FUN_18004c120(0,(uint *)0x0,0);
      *(undefined **)(unaff_RBP + -0x70) = &DAT_18008b840;
      *(undefined4 *)(unaff_RBP + -0x68) = 0x10000;
      uVar4 = FUN_1800497d0(unaff_RBP + -0x80,0xffffffff,8,-0xf,8,unaff_ESI,"1.2.11",0x58);
      uVar2 = (uint)uVar4;
      uVar4 = uVar4 & 0xffffffff;
      uVar6 = unaff_ESI;
      if (-1 < (int)uVar2) {
        while (((uVar2 = (uint)uVar4, unaff_ESI == 0 &&
                (unaff_ESI = (**(code **)(*unaff_R13 + 0x18))(), -1 < (int)unaff_ESI)) &&
               (uStack0000000000000060 != 0))) {
          *(undefined **)(unaff_RBP + -0x80) = &DAT_18007b840;
          *(uint *)(unaff_RBP + -0x78) = uStack0000000000000060;
          uStack0000000000000070 =
               FUN_18004c120(uStack0000000000000070,(uint *)&DAT_18007b840,uStack0000000000000060);
          if ((int)uVar2 < 0) break;
          while( true ) {
            uVar2 = (uint)uVar4;
            if (unaff_ESI != 0) goto LAB_18004295f;
            uVar3 = FUN_180048dd0((longlong *)(unaff_RBP + -0x80),2);
            uVar2 = uVar6;
            if (uVar3 != 1) {
              uVar2 = uVar3;
            }
            if ((int)uVar2 < 0) {
              uVar5 = FUN_180042420(uVar2);
              unaff_ESI = (uint)uVar5;
              if (-1 < (int)(uint)uVar5) {
                unaff_ESI = uVar6;
              }
              goto LAB_180042a03;
            }
            iVar1 = *(int *)(unaff_RBP + -0x70);
            if (iVar1 == -0x7ff747c0) break;
            unaff_ESI = (**(code **)(*unaff_R15 + 0x20))();
            if (iVar1 != -0x7ff747c0) {
              FUN_180007de0(unaff_RBP + 0x30,"Assert failed in file %s line %d",
                            "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\ZStg.cpp",0x188);
              LogMessage(unaff_RBP + 0x30,2,1);
            }
            *(undefined4 *)(unaff_RBP + -0x68) = 0x10000;
            *(undefined **)(unaff_RBP + -0x70) = &DAT_18008b840;
            uVar4 = (ulonglong)uVar2;
            if (iVar1 != -0x7ff647c0) break;
            uVar6 = 0;
          }
          uVar4 = (ulonglong)uVar2;
          uVar6 = 0;
        }
      }
LAB_18004295f:
      if (-1 < (int)unaff_ESI) {
        unaff_ESI = uVar6;
      }
      while ((-1 < (int)uVar2 && (unaff_ESI == 0))) {
        uVar2 = FUN_180048dd0((longlong *)(unaff_RBP + -0x80),4);
        iVar1 = *(int *)(unaff_RBP + -0x70);
        if (iVar1 == -0x7ff747c0) break;
        unaff_ESI = (**(code **)(*unaff_R15 + 0x20))();
        if (iVar1 != -0x7ff747c0) {
          FUN_180007de0(unaff_RBP + 0x30,"Assert failed in file %s line %d",
                        "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\ZStg.cpp",0x199);
          LogMessage(unaff_RBP + 0x30,2,1);
        }
        *(undefined **)(unaff_RBP + -0x70) = &DAT_18008b840;
        *(undefined4 *)(unaff_RBP + -0x68) = 0x10000;
        memset(&DAT_18008b840,0,0x10000);
      }
LAB_180042a03:
      uVar5 = FUN_180049730(unaff_RBP + -0x80);
      if ((-1 < (int)uVar5) && (-1 < (int)unaff_ESI)) {
        (**(code **)(*unaff_R15 + 0x20))();
        (**(code **)(*unaff_R15 + 0x20))();
      }
      uVar4 = FUN_180042420((int)uVar5);
    }
  }
  return uVar4;
}

/* ---- FUNC 000427BF FUN_1800427bf (13 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1800427bf(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  longlong unaff_RBP;
  uint unaff_ESI;
  undefined *unaff_R12;
  longlong *unaff_R13;
  longlong *unaff_R15;
  uint in_stack_00000060;
  uint uStack0000000000000070;
  
  uStack0000000000000070 = FUN_18004c120(0,(uint *)0x0,0);
  *(undefined **)(unaff_RBP + -0x70) = unaff_R12;
  *(undefined4 *)(unaff_RBP + -0x68) = 0x10000;
  uVar5 = FUN_1800497d0(unaff_RBP + -0x80,0xffffffff,8,-0xf,8,unaff_ESI,"1.2.11",0x58);
  uVar4 = (uint)uVar5;
  uVar5 = uVar5 & 0xffffffff;
  uVar2 = unaff_ESI;
  if (-1 < (int)uVar4) {
    while (((uVar4 = (uint)uVar5, uVar2 == 0 &&
            (uVar2 = (**(code **)(*unaff_R13 + 0x18))(), -1 < (int)uVar2)) &&
           (in_stack_00000060 != 0))) {
      *(undefined **)(unaff_RBP + -0x80) = &DAT_18007b840;
      *(uint *)(unaff_RBP + -0x78) = in_stack_00000060;
      uStack0000000000000070 =
           FUN_18004c120(uStack0000000000000070,(uint *)&DAT_18007b840,in_stack_00000060);
      if ((int)uVar4 < 0) break;
      while( true ) {
        uVar4 = (uint)uVar5;
        if (uVar2 != 0) goto LAB_180042958;
        uVar3 = FUN_180048dd0((longlong *)(unaff_RBP + -0x80),2);
        uVar4 = unaff_ESI;
        if (uVar3 != 1) {
          uVar4 = uVar3;
        }
        if ((int)uVar4 < 0) {
          uVar6 = FUN_180042420(uVar4);
          uVar2 = (uint)uVar6;
          if (-1 < (int)(uint)uVar6) {
            uVar2 = unaff_ESI;
          }
          goto LAB_180042a03;
        }
        iVar1 = *(int *)(unaff_RBP + -0x70);
        if (iVar1 == -0x7ff747c0) break;
        uVar2 = (**(code **)(*unaff_R15 + 0x20))();
        if (iVar1 != -0x7ff747c0) {
          FUN_180007de0(unaff_RBP + 0x30,"Assert failed in file %s line %d",
                        "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\ZStg.cpp",0x188);
          LogMessage(unaff_RBP + 0x30,2,1);
        }
        *(undefined4 *)(unaff_RBP + -0x68) = 0x10000;
        *(undefined **)(unaff_RBP + -0x70) = &DAT_18008b840;
        uVar5 = (ulonglong)uVar4;
        if (iVar1 != -0x7ff647c0) break;
        unaff_ESI = 0;
      }
      uVar5 = (ulonglong)uVar4;
      unaff_ESI = 0;
    }
LAB_180042958:
    unaff_R12 = &DAT_18008b840;
  }
  if (-1 < (int)uVar2) {
    uVar2 = unaff_ESI;
  }
  while ((-1 < (int)uVar4 && (uVar2 == 0))) {
    uVar4 = FUN_180048dd0((longlong *)(unaff_RBP + -0x80),4);
    iVar1 = *(int *)(unaff_RBP + -0x70);
    if (iVar1 == (int)unaff_R12) break;
    uVar2 = (**(code **)(*unaff_R15 + 0x20))();
    if (iVar1 != (int)unaff_R12) {
      FUN_180007de0(unaff_RBP + 0x30,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\ZStg.cpp",0x199);
      LogMessage(unaff_RBP + 0x30,2,1);
    }
    *(undefined **)(unaff_RBP + -0x70) = unaff_R12;
    *(undefined4 *)(unaff_RBP + -0x68) = 0x10000;
    memset(unaff_R12,0,0x10000);
  }
LAB_180042a03:
  uVar6 = FUN_180049730(unaff_RBP + -0x80);
  if ((-1 < (int)uVar6) && (-1 < (int)uVar2)) {
    (**(code **)(*unaff_R15 + 0x20))();
    (**(code **)(*unaff_R15 + 0x20))();
  }
  FUN_180042420((int)uVar6);
  return;
}

/* ---- FUNC 000427CC FUN_1800427cc (590 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1800427cc(undefined8 param_1,uint *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  longlong unaff_RBP;
  uint unaff_ESI;
  undefined *unaff_R12;
  longlong *unaff_R13;
  longlong *unaff_R15;
  uint in_stack_00000060;
  uint uStack0000000000000070;
  
  uStack0000000000000070 = FUN_18004c120(0,param_2,param_3);
  *(undefined **)(unaff_RBP + -0x70) = unaff_R12;
  *(undefined4 *)(unaff_RBP + -0x68) = 0x10000;
  uVar5 = FUN_1800497d0(unaff_RBP + -0x80,0xffffffff,8,-0xf,8,unaff_ESI,"1.2.11",0x58);
  uVar4 = (uint)uVar5;
  uVar5 = uVar5 & 0xffffffff;
  uVar2 = unaff_ESI;
  if (-1 < (int)uVar4) {
    while (((uVar4 = (uint)uVar5, uVar2 == 0 &&
            (uVar2 = (**(code **)(*unaff_R13 + 0x18))(), -1 < (int)uVar2)) &&
           (in_stack_00000060 != 0))) {
      *(undefined **)(unaff_RBP + -0x80) = &DAT_18007b840;
      *(uint *)(unaff_RBP + -0x78) = in_stack_00000060;
      uStack0000000000000070 =
           FUN_18004c120(uStack0000000000000070,(uint *)&DAT_18007b840,in_stack_00000060);
      if ((int)uVar4 < 0) break;
      while( true ) {
        uVar4 = (uint)uVar5;
        if (uVar2 != 0) goto LAB_180042958;
        uVar3 = FUN_180048dd0((longlong *)(unaff_RBP + -0x80),2);
        uVar4 = unaff_ESI;
        if (uVar3 != 1) {
          uVar4 = uVar3;
        }
        if ((int)uVar4 < 0) {
          uVar6 = FUN_180042420(uVar4);
          uVar2 = (uint)uVar6;
          if (-1 < (int)(uint)uVar6) {
            uVar2 = unaff_ESI;
          }
          goto LAB_180042a03;
        }
        iVar1 = *(int *)(unaff_RBP + -0x70);
        if (iVar1 == -0x7ff747c0) break;
        uVar2 = (**(code **)(*unaff_R15 + 0x20))();
        if (iVar1 != -0x7ff747c0) {
          FUN_180007de0(unaff_RBP + 0x30,"Assert failed in file %s line %d",
                        "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\ZStg.cpp",0x188);
          LogMessage(unaff_RBP + 0x30,2,1);
        }
        *(undefined4 *)(unaff_RBP + -0x68) = 0x10000;
        *(undefined **)(unaff_RBP + -0x70) = &DAT_18008b840;
        uVar5 = (ulonglong)uVar4;
        if (iVar1 != -0x7ff647c0) break;
        unaff_ESI = 0;
      }
      uVar5 = (ulonglong)uVar4;
      unaff_ESI = 0;
    }
LAB_180042958:
    unaff_R12 = &DAT_18008b840;
  }
  if (-1 < (int)uVar2) {
    uVar2 = unaff_ESI;
  }
  while ((-1 < (int)uVar4 && (uVar2 == 0))) {
    uVar4 = FUN_180048dd0((longlong *)(unaff_RBP + -0x80),4);
    iVar1 = *(int *)(unaff_RBP + -0x70);
    if (iVar1 == (int)unaff_R12) break;
    uVar2 = (**(code **)(*unaff_R15 + 0x20))();
    if (iVar1 != (int)unaff_R12) {
      FUN_180007de0(unaff_RBP + 0x30,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\ZStg.cpp",0x199);
      LogMessage(unaff_RBP + 0x30,2,1);
    }
    *(undefined **)(unaff_RBP + -0x70) = unaff_R12;
    *(undefined4 *)(unaff_RBP + -0x68) = 0x10000;
    memset(unaff_R12,0,0x10000);
  }
LAB_180042a03:
  uVar6 = FUN_180049730(unaff_RBP + -0x80);
  if ((-1 < (int)uVar6) && (-1 < (int)uVar2)) {
    (**(code **)(*unaff_R15 + 0x20))();
    (**(code **)(*unaff_R15 + 0x20))();
  }
  FUN_180042420((int)uVar6);
  return;
}

/* ---- FUNC 00042A1A FUN_180042a1a (75 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180042a1a(void)

{
  undefined4 unaff_EBX;
  int unaff_EDI;
  longlong *unaff_R15;
  
  if (-1 < unaff_EDI) {
    (**(code **)(*unaff_R15 + 0x20))();
    (**(code **)(*unaff_R15 + 0x20))();
  }
  FUN_180042420(unaff_EBX);
  return;
}

/* ---- FUNC 00042A65 FUN_180042a65 (10 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180042a65(void)

{
  return 0x80004003;
}

/* ---- FUNC 00042A70 FUN_180042a70 (332 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_180042a70(longlong *param_1,wchar_t *param_2,undefined4 param_3,longlong *param_4)

{
  undefined2 *puVar1;
  code *pcVar2;
  longlong *plVar3;
  uint uVar4;
  longlong lVar5;
  ulonglong uVar7;
  int iVar8;
  undefined2 *puVar9;
  undefined1 *puVar10;
  undefined2 *puVar11;
  undefined8 uStack_70;
  undefined1 auStack_68 [32];
  undefined8 uStack_48;
  int aiStack_40 [2];
  longlong *local_38;
  LPCSTR local_30;
  ulonglong local_28;
  longlong lVar6;
  
  local_28 = DAT_1800791f8 ^ (ulonglong)&local_38;
  uStack_70 = 0x180042aac;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_30,param_2);
  uStack_70 = 0x180042abd;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_30,".ZStg");
  puVar11 = (undefined2 *)0x0;
  local_38 = (longlong *)0x0;
  puVar9 = puVar11;
  puVar10 = auStack_68;
  if (local_30 != (LPCSTR)0x0) {
    lVar5 = -1;
    do {
      lVar6 = lVar5;
      lVar5 = lVar6 + 1;
    } while (local_30[lVar5] != '\0');
    iVar8 = (int)lVar6 + 2;
    puVar10 = auStack_68;
    if (iVar8 < 0x40000000) {
      lVar5 = (longlong)(int)lVar5 * 2;
      uVar7 = lVar5 + 0x11;
      if (uVar7 <= lVar5 + 2U) {
        uVar7 = 0xffffffffffffff0;
      }
      uStack_70 = 0x180042b11;
      lVar5 = -(uVar7 & 0xfffffffffffffff0);
      puVar1 = (undefined2 *)((longlong)&local_38 + lVar5);
      puVar10 = auStack_68 + lVar5;
      if (puVar1 != (undefined2 *)0x0) {
        *(int *)((longlong)aiStack_40 + lVar5) = iVar8;
        *puVar1 = 0;
        *(undefined2 **)((longlong)&uStack_48 + lVar5) = puVar1;
        *(undefined8 *)(auStack_68 + lVar5 + -8) = 0x180042b39;
        iVar8 = MultiByteToWideChar(0,0,local_30,-1,*(LPWSTR *)((longlong)&uStack_48 + lVar5),
                                    *(int *)((longlong)aiStack_40 + lVar5));
        puVar9 = puVar1;
        puVar10 = auStack_68 + lVar5;
        if (iVar8 == 0) {
          puVar9 = puVar11;
          puVar10 = auStack_68 + lVar5;
        }
      }
    }
  }
  lVar5 = *param_1;
  *(longlong ***)(puVar10 + 0x28) = &local_38;
  *(undefined4 *)(puVar10 + 0x20) = 0;
  pcVar2 = *(code **)(lVar5 + 0x18);
  *(undefined8 *)(puVar10 + -8) = 0x180042b64;
  uVar4 = (*pcVar2)(param_1,puVar9,param_3,0);
  plVar3 = local_38;
  uVar7 = (ulonglong)uVar4;
  if (uVar4 == 0) {
    *(undefined8 *)(puVar10 + -8) = 0x180042b76;
    uVar7 = FUN_180042480(param_4,plVar3);
    plVar3 = local_38;
    uVar7 = uVar7 & 0xffffffff;
    pcVar2 = *(code **)(*local_38 + 0x40);
    *(undefined8 *)(puVar10 + -8) = 0x180042b84;
    (*pcVar2)(plVar3,0);
    pcVar2 = *(code **)(*local_38 + 0x10);
    *(undefined8 *)(puVar10 + -8) = 0x180042b8e;
    (*pcVar2)();
  }
  *(undefined8 *)(puVar10 + -8) = 0x180042b98;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_30);
  *(undefined8 *)(puVar10 + -8) = 0x180042ba6;
  return uVar7;
}

/* ---- FUNC 00042BC0 FUN_180042bc0 (332 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_180042bc0(longlong *param_1,wchar_t *param_2,undefined4 param_3,longlong *param_4)

{
  undefined2 *puVar1;
  code *pcVar2;
  longlong *plVar3;
  uint uVar4;
  longlong lVar5;
  ulonglong uVar7;
  int iVar8;
  undefined2 *puVar9;
  undefined1 *puVar10;
  undefined2 *puVar11;
  undefined8 uStack_70;
  undefined1 auStack_68 [32];
  undefined8 uStack_48;
  int aiStack_40 [2];
  longlong *local_38;
  LPCSTR local_30;
  ulonglong local_28;
  longlong lVar6;
  
  local_28 = DAT_1800791f8 ^ (ulonglong)&local_38;
  uStack_70 = 0x180042bfc;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_30,param_2);
  uStack_70 = 0x180042c0d;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_30,".ZStm");
  puVar11 = (undefined2 *)0x0;
  local_38 = (longlong *)0x0;
  puVar9 = puVar11;
  puVar10 = auStack_68;
  if (local_30 != (LPCSTR)0x0) {
    lVar5 = -1;
    do {
      lVar6 = lVar5;
      lVar5 = lVar6 + 1;
    } while (local_30[lVar5] != '\0');
    iVar8 = (int)lVar6 + 2;
    puVar10 = auStack_68;
    if (iVar8 < 0x40000000) {
      lVar5 = (longlong)(int)lVar5 * 2;
      uVar7 = lVar5 + 0x11;
      if (uVar7 <= lVar5 + 2U) {
        uVar7 = 0xffffffffffffff0;
      }
      uStack_70 = 0x180042c61;
      lVar5 = -(uVar7 & 0xfffffffffffffff0);
      puVar1 = (undefined2 *)((longlong)&local_38 + lVar5);
      puVar10 = auStack_68 + lVar5;
      if (puVar1 != (undefined2 *)0x0) {
        *(int *)((longlong)aiStack_40 + lVar5) = iVar8;
        *puVar1 = 0;
        *(undefined2 **)((longlong)&uStack_48 + lVar5) = puVar1;
        *(undefined8 *)(auStack_68 + lVar5 + -8) = 0x180042c89;
        iVar8 = MultiByteToWideChar(0,0,local_30,-1,*(LPWSTR *)((longlong)&uStack_48 + lVar5),
                                    *(int *)((longlong)aiStack_40 + lVar5));
        puVar9 = puVar1;
        puVar10 = auStack_68 + lVar5;
        if (iVar8 == 0) {
          puVar9 = puVar11;
          puVar10 = auStack_68 + lVar5;
        }
      }
    }
  }
  lVar5 = *param_1;
  *(longlong ***)(puVar10 + 0x28) = &local_38;
  *(undefined4 *)(puVar10 + 0x20) = 0;
  pcVar2 = *(code **)(lVar5 + 0x18);
  *(undefined8 *)(puVar10 + -8) = 0x180042cb4;
  uVar4 = (*pcVar2)(param_1,puVar9,param_3,0);
  plVar3 = local_38;
  uVar7 = (ulonglong)uVar4;
  if (uVar4 == 0) {
    *(undefined8 *)(puVar10 + -8) = 0x180042cc6;
    uVar7 = ZStgCompressStream(param_4,plVar3);
    plVar3 = local_38;
    uVar7 = uVar7 & 0xffffffff;
    pcVar2 = *(code **)(*local_38 + 0x40);
    *(undefined8 *)(puVar10 + -8) = 0x180042cd4;
    (*pcVar2)(plVar3,0);
    pcVar2 = *(code **)(*local_38 + 0x10);
    *(undefined8 *)(puVar10 + -8) = 0x180042cde;
    (*pcVar2)();
  }
  *(undefined8 *)(puVar10 + -8) = 0x180042ce8;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_30);
  *(undefined8 *)(puVar10 + -8) = 0x180042cf6;
  return uVar7;
}

/* ---- FUNC 00042D10 ZStgDecompressStream (137 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong ZStgDecompressStream(longlong *param_1,longlong *param_2)

{
  byte bVar1;
  longlong *plVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  undefined1 auStack_578 [32];
  undefined1 *local_558;
  byte local_548 [4];
  int local_544;
  ulonglong local_540;
  undefined8 local_538;
  uint local_530;
  undefined4 local_52c;
  undefined4 local_528;
  undefined4 local_524;
  uint local_520 [2];
  longlong *local_518;
  undefined8 local_510;
  undefined *local_508;
  undefined8 uStack_500;
  undefined *local_4f8;
  undefined8 uStack_4f0;
  undefined8 local_4e8;
  undefined8 uStack_4e0;
  undefined8 local_4d8;
  undefined8 uStack_4d0;
  undefined8 local_4c8;
  undefined8 uStack_4c0;
  undefined8 local_4b8;
  undefined1 local_4a8 [8];
  undefined1 local_4a0 [8];
  undefined1 local_498 [16];
  int local_488;
  char local_448;
  char local_447;
  byte local_444;
  undefined1 local_438 [1008];
  ulonglong local_48;
  
                    /* 0x42d10  545  ZStgDecompressStream */
  local_48 = DAT_1800791f8 ^ (ulonglong)auStack_578;
  local_538 = 0;
  local_540 = 0;
  local_530 = 0;
  local_510 = 0xffffffffffffffff;
  local_518 = param_2;
  uVar3 = FUN_18004c120(0,(uint *)0x0,0);
  local_52c = 0;
  local_544 = 0;
  if ((param_1 == (longlong *)0x0) || (param_2 == (longlong *)0x0)) {
    return 0x80004003;
  }
  iVar4 = (**(code **)(*param_1 + 0x18))(param_1,&local_448,10,&local_544);
  if (iVar4 < 0) {
    return 0x80004005;
  }
  if (local_544 != 10) {
    return 0x80004005;
  }
  if ((local_448 != '\x1f') || (local_447 != -0x75)) {
    (**(code **)(*param_1 + 0x28))(param_1,0,0,&local_538);
    local_558 = local_4a8;
    uVar3 = (**(code **)(*param_1 + 0x38))(param_1,param_2,local_510,local_4a0);
    uVar6 = (ulonglong)uVar3;
    goto LAB_180043255;
  }
  local_540 = 0xfffffffffffffff8;
  iVar5 = (**(code **)(*param_1 + 0x28))(param_1,0xfffffffffffffff8,2,&local_538);
  if (iVar5 == 0) {
    (**(code **)(*param_1 + 0x18))(param_1,&local_530,4,&local_544);
    (**(code **)(*param_1 + 0x18))(param_1,&local_52c,4,&local_544);
    local_538 = CONCAT44(local_538._4_4_,local_52c);
    (**(code **)(*param_2 + 0x30))(param_2,local_538);
    local_540 = 10;
LAB_180042ef2:
    (**(code **)(*param_1 + 0x28))(param_1,local_540,0,&local_538);
  }
  else {
    iVar5 = (**(code **)(*param_1 + 0x60))(param_1,local_498,1);
    if (iVar5 == 0) {
      local_540 = (ulonglong)(local_488 - 8);
      iVar5 = (**(code **)(*param_1 + 0x28))(param_1,local_540,0,&local_538);
      if (iVar5 == 0) {
        local_524 = 0;
        local_528 = 0;
        (**(code **)(*param_1 + 0x18))(param_1,&local_530,4,&local_528);
        (**(code **)(*param_1 + 0x18))(param_1,&local_524,4,&local_528);
        local_538 = CONCAT44(local_538._4_4_,local_524);
        (**(code **)(*param_2 + 0x30))(param_2,local_538);
        local_540 = CONCAT44(local_540._4_4_,10);
        goto LAB_180042ef2;
      }
    }
  }
  if ((local_444 & 4) != 0) {
    (**(code **)(*param_1 + 0x18))(param_1,local_548,1,&local_544);
    bVar1 = local_548[0];
    iVar4 = (**(code **)(*param_1 + 0x18))(param_1,local_548,1,&local_544);
    iVar5 = (uint)bVar1 + (uint)local_548[0] * 0x100;
    while ((iVar5 != 0 && (iVar5 = iVar5 + -1, iVar4 == 0))) {
      iVar4 = (**(code **)(*param_1 + 0x18))(param_1,local_548,1,&local_544);
    }
  }
  if ((local_444 & 8) != 0) {
    do {
      iVar4 = (**(code **)(*param_1 + 0x18))(param_1,local_548,1,&local_544);
      if (local_548[0] == 0) break;
    } while (iVar4 == 0);
  }
  if ((local_444 & 0x10) != 0) {
    do {
      iVar4 = (**(code **)(*param_1 + 0x18))(param_1,local_548,1,&local_544);
      if (local_548[0] == 0) break;
    } while (iVar4 == 0);
  }
  if ((local_444 & 2) != 0) {
    (**(code **)(*param_1 + 0x18))(param_1,local_548,1,&local_544);
    iVar4 = (**(code **)(*param_1 + 0x18))(param_1,local_548,1,&local_544);
  }
  local_4b8 = 0;
  uStack_4f0 = 0x10000;
  local_508 = (undefined *)0x0;
  uStack_500 = 0;
  local_4f8 = &DAT_18007b840;
  local_4e8 = 0;
  uStack_4e0 = 0;
  local_4d8 = 0;
  uStack_4d0 = 0;
  local_4c8 = 0;
  uStack_4c0 = 0;
  uVar6 = FUN_18004bd80((longlong)&local_508,0xfffffff1,"1.2.11",0x58);
  iVar5 = (int)uVar6;
  uVar6 = uVar6 & 0xffffffff;
  if (iVar5 < 0) {
LAB_18004318c:
    bVar10 = iVar4 < 0;
  }
  else {
LAB_180043070:
    iVar5 = (int)uVar6;
    bVar10 = iVar4 < 0;
    if (iVar4 == 0) {
      iVar4 = (**(code **)(*param_1 + 0x18))(param_1,&DAT_18008b840,0x10000,&local_510);
      if ((iVar4 < 0) || ((int)local_510 == 0)) goto LAB_18004318c;
      local_508 = &DAT_18008b840;
      uStack_500 = CONCAT44(uStack_500._4_4_,(int)local_510);
      if (iVar5 < 0) goto LAB_18004318c;
      do {
        iVar5 = (int)uVar6;
        bVar10 = iVar4 < 0;
        if (iVar4 != 0) goto LAB_18004318e;
        uVar6 = FUN_18004a580((longlong *)&local_508,2);
        uVar8 = 0;
        if ((uint)uVar6 != 1) {
          uVar8 = (uint)uVar6;
        }
        if ((int)uVar8 < 0) goto LAB_1800431f8;
        uVar6 = (ulonglong)uVar8;
        uVar9 = (int)local_4f8 + 0x7ff847c0;
        if (uVar9 == 0) break;
        uVar3 = FUN_18004c120(uVar3,(uint *)&DAT_18007b840,uVar9);
        iVar4 = (**(code **)(*local_518 + 0x20))(local_518,&DAT_18007b840,uVar9,local_520);
        if (uVar9 != local_520[0]) {
          FUN_180007de0(local_438,"Assert failed in file %s line %d",
                        "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\ZStg.cpp",0x215);
          LogMessage(local_438);
        }
        local_4f8 = &DAT_18007b840;
        uVar6 = (ulonglong)uVar8;
        uStack_4f0 = CONCAT44(uStack_4f0._4_4_,0x10000);
      } while (uVar9 == 0x10000);
      goto LAB_180043070;
    }
  }
LAB_18004318e:
  plVar2 = local_518;
  if (!bVar10) {
    iVar4 = 0;
  }
  while ((-1 < iVar5 && (iVar4 == 0))) {
    uVar6 = FUN_18004a580((longlong *)&local_508,4);
    uVar8 = (int)local_4f8 + 0x7ff847c0;
    if (uVar8 == 0) break;
    uVar3 = FUN_18004c120(uVar3,(uint *)&DAT_18007b840,uVar8);
    iVar4 = (**(code **)(*plVar2 + 0x20))(plVar2,&DAT_18007b840,uVar8,local_520);
    local_4f8 = &DAT_18007b840;
    uStack_4f0 = CONCAT44(uStack_4f0._4_4_,0x10000);
    iVar5 = (int)uVar6;
  }
LAB_1800431f8:
  uVar7 = FUN_18004bd30((longlong)&local_508);
  uVar6 = FUN_180042420((int)uVar7);
  uVar6 = uVar6 & 0xffffffff;
  param_2 = local_518;
  if ((local_530 != 0) && (local_530 != uVar3)) {
    FUN_180007de0(local_438,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\ZStg.cpp",0x22c);
    LogMessage(local_438,2,1);
    param_2 = local_518;
  }
LAB_180043255:
  (**(code **)(*param_1 + 0x28))(param_1,0,0,&local_538);
  (**(code **)(*param_2 + 0x28))(param_2,0,0,&local_538);
  return uVar6;
}

/* ---- FUNC 00042D99 FUN_180042d99 (89 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_180042d99(undefined4 param_1)

{
  byte bVar1;
  byte bVar2;
  longlong *plVar3;
  int iVar4;
  int iVar5;
  longlong in_RAX;
  ulonglong uVar6;
  undefined8 uVar7;
  int unaff_EBX;
  longlong unaff_RBP;
  ulonglong unaff_RSI;
  uint uVar8;
  longlong *unaff_R12;
  uint unaff_R13D;
  uint uVar9;
  longlong *unaff_R15;
  bool bVar10;
  undefined4 extraout_XMM0_Da;
  undefined4 extraout_XMM0_Da_00;
  undefined4 uVar11;
  undefined4 extraout_XMM0_Da_01;
  undefined4 extraout_XMM0_Da_02;
  undefined4 extraout_XMM0_Da_03;
  undefined4 extraout_XMM0_Da_04;
  undefined4 extraout_XMM0_Da_05;
  undefined4 extraout_XMM0_Da_06;
  byte bStack0000000000000030;
  int iStack0000000000000034;
  ulonglong in_stack_00000038;
  undefined4 uStack0000000000000040;
  undefined4 uStack0000000000000044;
  uint uStack0000000000000048;
  undefined4 uStack000000000000004c;
  undefined4 uStack0000000000000050;
  undefined4 uStack0000000000000054;
  uint in_stack_00000058;
  longlong *in_stack_00000060;
  int in_stack_00000068;
  undefined *in_stack_00000070;
  undefined8 in_stack_00000078;
  
  iVar4 = (**(code **)(in_RAX + 0x18))(param_1,unaff_RBP + 0x30);
  if ((iVar4 < 0) || (iStack0000000000000034 != 10)) goto LAB_18004327e;
  if ((*(char *)(unaff_RBP + 0x30) == '\x1f') && (*(char *)(unaff_RBP + 0x31) == -0x75)) {
    in_stack_00000038 = 0xfffffffffffffff8;
    bVar1 = *(byte *)(unaff_RBP + 0x34);
    iVar5 = (**(code **)(*unaff_R12 + 0x28))
                      (extraout_XMM0_Da,0xfffffffffffffff8,unaff_EBX + 2,&stack0x00000040);
    if (iVar5 == 0) {
      uVar11 = (**(code **)(*unaff_R12 + 0x18))
                         (extraout_XMM0_Da_00,&stack0x00000048,unaff_EBX + 4,
                          (longlong)&stack0x00000030 + 4);
      uVar11 = (**(code **)(*unaff_R12 + 0x18))
                         (uVar11,(longlong)&stack0x00000048 + 4,unaff_EBX + 4,
                          (longlong)&stack0x00000030 + 4);
      uStack0000000000000040 = uStack000000000000004c;
      uVar11 = (**(code **)(*unaff_R15 + 0x30))
                         (uVar11,CONCAT44(uStack0000000000000044,uStack000000000000004c));
      in_stack_00000038 = 10;
LAB_180042ef2:
      uVar11 = (**(code **)(*unaff_R12 + 0x28))(uVar11,in_stack_00000038,0,&stack0x00000040);
    }
    else {
      iVar5 = (**(code **)(*unaff_R12 + 0x60))(extraout_XMM0_Da_00,unaff_RBP + -0x20,1);
      uVar11 = extraout_XMM0_Da_01;
      if (iVar5 == 0) {
        in_stack_00000038 = (ulonglong)(*(int *)(unaff_RBP + -0x10) - 8);
        iVar5 = (**(code **)(*unaff_R12 + 0x28))
                          (extraout_XMM0_Da_01,in_stack_00000038,0,&stack0x00000040);
        uVar11 = extraout_XMM0_Da_02;
        if (iVar5 == 0) {
          uStack0000000000000054 = 0;
          uStack0000000000000050 = 0;
          uVar11 = (**(code **)(*unaff_R12 + 0x18))
                             (extraout_XMM0_Da_02,&stack0x00000048,4,&stack0x00000050);
          uVar11 = (**(code **)(*unaff_R12 + 0x18))
                             (uVar11,(longlong)&stack0x00000050 + 4,4,&stack0x00000050);
          uStack0000000000000040 = uStack0000000000000054;
          uVar11 = (**(code **)(*unaff_R15 + 0x30))
                             (uVar11,CONCAT44(uStack0000000000000044,uStack0000000000000054));
          in_stack_00000038 = CONCAT44(in_stack_00000038._4_4_,10);
          goto LAB_180042ef2;
        }
      }
    }
    if ((bVar1 & 4) != 0) {
      uVar11 = (**(code **)(*unaff_R12 + 0x18))
                         (uVar11,&stack0x00000030,1,(longlong)&stack0x00000030 + 4);
      bVar2 = bStack0000000000000030;
      iVar4 = (**(code **)(*unaff_R12 + 0x18))
                        (uVar11,&stack0x00000030,1,(longlong)&stack0x00000030 + 4);
      iVar5 = (uint)bVar2 + (uint)bStack0000000000000030 * 0x100;
      uVar11 = extraout_XMM0_Da_03;
      while ((iVar5 != 0 && (iVar5 = iVar5 + -1, iVar4 == 0))) {
        iVar4 = (**(code **)(*unaff_R12 + 0x18))
                          (uVar11,&stack0x00000030,1,(longlong)&stack0x00000030 + 4);
        uVar11 = extraout_XMM0_Da_04;
      }
    }
    if ((bVar1 & 8) != 0) {
      do {
        iVar4 = (**(code **)(*unaff_R12 + 0x18))
                          (uVar11,&stack0x00000030,1,(longlong)&stack0x00000030 + 4);
        uVar11 = extraout_XMM0_Da_05;
        if (bStack0000000000000030 == 0) break;
      } while (iVar4 == 0);
    }
    if ((bVar1 & 0x10) != 0) {
      do {
        iVar4 = (**(code **)(*unaff_R12 + 0x18))
                          (uVar11,&stack0x00000030,1,(longlong)&stack0x00000030 + 4);
        uVar11 = extraout_XMM0_Da_06;
        if (bStack0000000000000030 == 0) break;
      } while (iVar4 == 0);
    }
    if ((bVar1 & 2) != 0) {
      uVar11 = (**(code **)(*unaff_R12 + 0x18))
                         (uVar11,&stack0x00000030,1,(longlong)&stack0x00000030 + 4);
      iVar4 = (**(code **)(*unaff_R12 + 0x18))
                        (uVar11,&stack0x00000030,1,(longlong)&stack0x00000030 + 4);
    }
    *(undefined8 *)(unaff_RBP + -0x80) = 0;
    *(undefined8 *)(unaff_RBP + -0x78) = 0;
    *(undefined8 *)(unaff_RBP + -0x40) = 0;
    *(undefined4 *)(unaff_RBP + -0x78) = 0x10000;
    in_stack_00000070 = (undefined *)0x0;
    in_stack_00000078 = 0;
    *(undefined **)(unaff_RBP + -0x80) = &DAT_18007b840;
    *(undefined8 *)(unaff_RBP + -0x70) = 0;
    *(undefined8 *)(unaff_RBP + -0x68) = 0;
    *(undefined8 *)(unaff_RBP + -0x60) = 0;
    *(undefined8 *)(unaff_RBP + -0x58) = 0;
    *(undefined8 *)(unaff_RBP + -0x50) = 0;
    *(undefined8 *)(unaff_RBP + -0x48) = 0;
    uVar6 = FUN_18004bd80((longlong)&stack0x00000070,0xfffffff1,"1.2.11",0x58);
    iVar5 = (int)uVar6;
    uVar6 = uVar6 & 0xffffffff;
    if (iVar5 < 0) {
LAB_18004318c:
      bVar10 = iVar4 < 0;
    }
    else {
LAB_180043070:
      iVar5 = (int)uVar6;
      bVar10 = iVar4 < 0;
      if (iVar4 == 0) {
        iVar4 = (**(code **)(*unaff_R12 + 0x18))();
        if ((iVar4 < 0) || (in_stack_00000068 == 0)) goto LAB_18004318c;
        in_stack_00000070 = &DAT_18008b840;
        in_stack_00000078 = CONCAT44(in_stack_00000078._4_4_,in_stack_00000068);
        if (iVar5 < 0) goto LAB_18004318c;
        do {
          iVar5 = (int)uVar6;
          bVar10 = iVar4 < 0;
          if (iVar4 != 0) goto LAB_18004318e;
          uVar6 = FUN_18004a580((longlong *)&stack0x00000070,2);
          uVar8 = 0;
          if ((uint)uVar6 != 1) {
            uVar8 = (uint)uVar6;
          }
          if ((int)uVar8 < 0) goto LAB_1800431f8;
          uVar6 = (ulonglong)uVar8;
          uVar9 = *(int *)(unaff_RBP + -0x80) + 0x7ff847c0;
          if (uVar9 == 0) break;
          unaff_R13D = FUN_18004c120(unaff_R13D,(uint *)&DAT_18007b840,uVar9);
          iVar4 = (**(code **)(*in_stack_00000060 + 0x20))
                            (in_stack_00000060,&DAT_18007b840,uVar9,&stack0x00000058);
          if (uVar9 != in_stack_00000058) {
            FUN_180007de0(unaff_RBP + 0x40,"Assert failed in file %s line %d",
                          "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\ZStg.cpp",0x215);
            LogMessage(unaff_RBP + 0x40);
          }
          *(undefined **)(unaff_RBP + -0x80) = &DAT_18007b840;
          uVar6 = (ulonglong)uVar8;
          *(undefined4 *)(unaff_RBP + -0x78) = 0x10000;
        } while (uVar9 == 0x10000);
        goto LAB_180043070;
      }
    }
LAB_18004318e:
    plVar3 = in_stack_00000060;
    if (!bVar10) {
      iVar4 = 0;
    }
    while ((-1 < iVar5 && (iVar4 == 0))) {
      uVar6 = FUN_18004a580((longlong *)&stack0x00000070,4);
      uVar8 = *(int *)(unaff_RBP + -0x80) + 0x7ff847c0;
      if (uVar8 == 0) break;
      unaff_R13D = FUN_18004c120(unaff_R13D,(uint *)&DAT_18007b840,uVar8);
      iVar4 = (**(code **)(*plVar3 + 0x20))(plVar3,&DAT_18007b840,uVar8,&stack0x00000058);
      *(undefined **)(unaff_RBP + -0x80) = &DAT_18007b840;
      *(undefined4 *)(unaff_RBP + -0x78) = 0x10000;
      iVar5 = (int)uVar6;
    }
LAB_1800431f8:
    uVar7 = FUN_18004bd30((longlong)&stack0x00000070);
    uVar6 = FUN_180042420((int)uVar7);
    unaff_RSI = uVar6 & 0xffffffff;
    unaff_R15 = in_stack_00000060;
    if ((uStack0000000000000048 != 0) && (uStack0000000000000048 != unaff_R13D)) {
      FUN_180007de0(unaff_RBP + 0x40,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\ZStg.cpp",0x22c);
      LogMessage(unaff_RBP + 0x40,2,1);
      unaff_R15 = in_stack_00000060;
    }
  }
  else {
    (**(code **)(*unaff_R12 + 0x28))();
    uVar8 = (**(code **)(*unaff_R12 + 0x38))();
    unaff_RSI = (ulonglong)uVar8;
  }
  (**(code **)(*unaff_R12 + 0x28))();
  (**(code **)(*unaff_R15 + 0x28))(unaff_R15);
LAB_18004327e:
  return unaff_RSI & 0xffffffff;
}

/* ---- FUNC 00042DF2 FUN_180042df2 (1065 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_180042df2(void)

{
  byte bVar1;
  byte bVar2;
  longlong *plVar3;
  int iVar4;
  longlong in_RAX;
  ulonglong uVar5;
  undefined8 uVar6;
  int unaff_EBX;
  longlong unaff_RBP;
  int unaff_EDI;
  uint uVar7;
  longlong *unaff_R12;
  uint unaff_R13D;
  uint uVar8;
  longlong *unaff_R15;
  bool bVar9;
  undefined4 extraout_XMM0_Da;
  undefined4 uVar10;
  undefined4 extraout_XMM0_Da_00;
  undefined4 extraout_XMM0_Da_01;
  undefined4 extraout_XMM0_Da_02;
  undefined4 extraout_XMM0_Da_03;
  undefined4 extraout_XMM0_Da_04;
  undefined4 extraout_XMM0_Da_05;
  byte in_stack_00000030;
  ulonglong in_stack_00000038;
  undefined4 uStack0000000000000040;
  undefined4 uStack0000000000000044;
  uint uStack0000000000000048;
  undefined4 uStack000000000000004c;
  undefined4 uStack0000000000000050;
  undefined4 uStack0000000000000054;
  uint in_stack_00000058;
  longlong *in_stack_00000060;
  int in_stack_00000068;
  undefined *in_stack_00000070;
  undefined8 in_stack_00000078;
  
  bVar1 = *(byte *)(unaff_RBP + 0x34);
  iVar4 = (**(code **)(in_RAX + 0x28))();
  if (iVar4 == 0) {
    uVar10 = (**(code **)(*unaff_R12 + 0x18))
                       (extraout_XMM0_Da,&stack0x00000048,unaff_EBX + 4,&stack0x00000034);
    uVar10 = (**(code **)(*unaff_R12 + 0x18))
                       (uVar10,(longlong)&stack0x00000048 + 4,unaff_EBX + 4,&stack0x00000034);
    uStack0000000000000040 = uStack000000000000004c;
    uVar10 = (**(code **)(*unaff_R15 + 0x30))
                       (uVar10,CONCAT44(uStack0000000000000044,uStack000000000000004c));
    in_stack_00000038 = 10;
  }
  else {
    iVar4 = (**(code **)(*unaff_R12 + 0x60))(extraout_XMM0_Da,unaff_RBP + -0x20,1);
    uVar10 = extraout_XMM0_Da_00;
    if (iVar4 != 0) goto LAB_180042f09;
    in_stack_00000038 = (ulonglong)(*(int *)(unaff_RBP + -0x10) - 8);
    iVar4 = (**(code **)(*unaff_R12 + 0x28))
                      (extraout_XMM0_Da_00,in_stack_00000038,0,&stack0x00000040);
    uVar10 = extraout_XMM0_Da_01;
    if (iVar4 != 0) goto LAB_180042f09;
    uStack0000000000000054 = 0;
    uStack0000000000000050 = 0;
    uVar10 = (**(code **)(*unaff_R12 + 0x18))
                       (extraout_XMM0_Da_01,&stack0x00000048,4,&stack0x00000050);
    uVar10 = (**(code **)(*unaff_R12 + 0x18))
                       (uVar10,(longlong)&stack0x00000050 + 4,4,&stack0x00000050);
    uStack0000000000000040 = uStack0000000000000054;
    uVar10 = (**(code **)(*unaff_R15 + 0x30))
                       (uVar10,CONCAT44(uStack0000000000000044,uStack0000000000000054));
    in_stack_00000038 = CONCAT44(in_stack_00000038._4_4_,10);
  }
  uVar10 = (**(code **)(*unaff_R12 + 0x28))(uVar10,in_stack_00000038,0,&stack0x00000040);
LAB_180042f09:
  if ((bVar1 & 4) != 0) {
    uVar10 = (**(code **)(*unaff_R12 + 0x18))(uVar10,&stack0x00000030,1,&stack0x00000034);
    bVar2 = in_stack_00000030;
    unaff_EDI = (**(code **)(*unaff_R12 + 0x18))(uVar10,&stack0x00000030,1,&stack0x00000034);
    iVar4 = (uint)bVar2 + (uint)in_stack_00000030 * 0x100;
    uVar10 = extraout_XMM0_Da_02;
    while ((iVar4 != 0 && (iVar4 = iVar4 + -1, unaff_EDI == 0))) {
      unaff_EDI = (**(code **)(*unaff_R12 + 0x18))(uVar10,&stack0x00000030,1,&stack0x00000034);
      uVar10 = extraout_XMM0_Da_03;
    }
  }
  if ((bVar1 & 8) != 0) {
    do {
      unaff_EDI = (**(code **)(*unaff_R12 + 0x18))(uVar10,&stack0x00000030,1,&stack0x00000034);
      uVar10 = extraout_XMM0_Da_04;
      if (in_stack_00000030 == 0) break;
    } while (unaff_EDI == 0);
  }
  if ((bVar1 & 0x10) != 0) {
    do {
      unaff_EDI = (**(code **)(*unaff_R12 + 0x18))(uVar10,&stack0x00000030,1,&stack0x00000034);
      uVar10 = extraout_XMM0_Da_05;
      if (in_stack_00000030 == 0) break;
    } while (unaff_EDI == 0);
  }
  if ((bVar1 & 2) != 0) {
    uVar10 = (**(code **)(*unaff_R12 + 0x18))(uVar10,&stack0x00000030,1,&stack0x00000034);
    unaff_EDI = (**(code **)(*unaff_R12 + 0x18))(uVar10,&stack0x00000030,1,&stack0x00000034);
  }
  *(undefined8 *)(unaff_RBP + -0x80) = 0;
  *(undefined8 *)(unaff_RBP + -0x78) = 0;
  *(undefined8 *)(unaff_RBP + -0x40) = 0;
  *(undefined4 *)(unaff_RBP + -0x78) = 0x10000;
  in_stack_00000070 = (undefined *)0x0;
  in_stack_00000078 = 0;
  *(undefined **)(unaff_RBP + -0x80) = &DAT_18007b840;
  *(undefined8 *)(unaff_RBP + -0x70) = 0;
  *(undefined8 *)(unaff_RBP + -0x68) = 0;
  *(undefined8 *)(unaff_RBP + -0x60) = 0;
  *(undefined8 *)(unaff_RBP + -0x58) = 0;
  *(undefined8 *)(unaff_RBP + -0x50) = 0;
  *(undefined8 *)(unaff_RBP + -0x48) = 0;
  uVar5 = FUN_18004bd80((longlong)&stack0x00000070,0xfffffff1,"1.2.11",0x58);
  iVar4 = (int)uVar5;
  uVar5 = uVar5 & 0xffffffff;
  if (iVar4 < 0) {
LAB_18004318c:
    bVar9 = unaff_EDI < 0;
  }
  else {
LAB_180043070:
    iVar4 = (int)uVar5;
    bVar9 = unaff_EDI < 0;
    if (unaff_EDI == 0) {
      unaff_EDI = (**(code **)(*unaff_R12 + 0x18))();
      if ((unaff_EDI < 0) || (in_stack_00000068 == 0)) goto LAB_18004318c;
      in_stack_00000070 = &DAT_18008b840;
      in_stack_00000078 = CONCAT44(in_stack_00000078._4_4_,in_stack_00000068);
      if (iVar4 < 0) goto LAB_18004318c;
      do {
        iVar4 = (int)uVar5;
        bVar9 = unaff_EDI < 0;
        if (unaff_EDI != 0) goto LAB_18004318e;
        uVar5 = FUN_18004a580((longlong *)&stack0x00000070,2);
        uVar7 = 0;
        if ((uint)uVar5 != 1) {
          uVar7 = (uint)uVar5;
        }
        if ((int)uVar7 < 0) goto LAB_1800431f8;
        uVar5 = (ulonglong)uVar7;
        uVar8 = *(int *)(unaff_RBP + -0x80) + 0x7ff847c0;
        if (uVar8 == 0) break;
        unaff_R13D = FUN_18004c120(unaff_R13D,(uint *)&DAT_18007b840,uVar8);
        unaff_EDI = (**(code **)(*in_stack_00000060 + 0x20))
                              (in_stack_00000060,&DAT_18007b840,uVar8,&stack0x00000058);
        if (uVar8 != in_stack_00000058) {
          FUN_180007de0(unaff_RBP + 0x40,"Assert failed in file %s line %d",
                        "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\ZStg.cpp",0x215);
          LogMessage(unaff_RBP + 0x40);
        }
        *(undefined **)(unaff_RBP + -0x80) = &DAT_18007b840;
        uVar5 = (ulonglong)uVar7;
        *(undefined4 *)(unaff_RBP + -0x78) = 0x10000;
      } while (uVar8 == 0x10000);
      goto LAB_180043070;
    }
  }
LAB_18004318e:
  plVar3 = in_stack_00000060;
  if (!bVar9) {
    unaff_EDI = 0;
  }
  while ((-1 < iVar4 && (unaff_EDI == 0))) {
    uVar5 = FUN_18004a580((longlong *)&stack0x00000070,4);
    uVar7 = *(int *)(unaff_RBP + -0x80) + 0x7ff847c0;
    if (uVar7 == 0) break;
    unaff_R13D = FUN_18004c120(unaff_R13D,(uint *)&DAT_18007b840,uVar7);
    unaff_EDI = (**(code **)(*plVar3 + 0x20))(plVar3,&DAT_18007b840,uVar7,&stack0x00000058);
    *(undefined **)(unaff_RBP + -0x80) = &DAT_18007b840;
    *(undefined4 *)(unaff_RBP + -0x78) = 0x10000;
    iVar4 = (int)uVar5;
  }
LAB_1800431f8:
  uVar6 = FUN_18004bd30((longlong)&stack0x00000070);
  uVar5 = FUN_180042420((int)uVar6);
  if ((uStack0000000000000048 != 0) && (uStack0000000000000048 != unaff_R13D)) {
    FUN_180007de0(unaff_RBP + 0x40,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\ZStg.cpp",0x22c);
    LogMessage(unaff_RBP + 0x40,2,1);
  }
  plVar3 = in_stack_00000060;
  (**(code **)(*unaff_R12 + 0x28))();
  (**(code **)(*plVar3 + 0x28))(plVar3);
  return uVar5 & 0xffffffff;
}

/* ---- FUNC 0004321B FUN_18004321b (111 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_18004321b(void)

{
  int in_EAX;
  longlong unaff_RBP;
  undefined4 unaff_ESI;
  longlong *unaff_R12;
  int unaff_R13D;
  longlong *in_stack_00000060;
  
  if (in_EAX != unaff_R13D) {
    FUN_180007de0(unaff_RBP + 0x40,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\ZStg.cpp",0x22c);
    LogMessage(unaff_RBP + 0x40,2,1);
  }
  (**(code **)(*unaff_R12 + 0x28))();
  (**(code **)(*in_stack_00000060 + 0x28))(in_stack_00000060);
  return unaff_ESI;
}

