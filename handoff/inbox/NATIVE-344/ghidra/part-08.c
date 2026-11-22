/* RVA 0x26490 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180026490(void)

{
  undefined8 in_R9;
  undefined1 auStack_148 [32];
  char local_128 [272];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_148;
  if (DAT_180052d80 != (FILE *)0x0) {
    fclose(DAT_180052d80);
    DAT_180052d80 = (FILE *)0x0;
  }
  FUN_180008f80(local_128,"%s.ssq",*(undefined8 *)topfinfo_exref,in_R9);
  remove(local_128);
  return;
}

/* RVA 0x26510 */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_180026510(char *param_1,char *param_2)

{
  char cVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  undefined1 auStack_1088 [32];
  int local_1068 [4];
  char local_1058 [1040];
  char local_c48 [1040];
  char local_838 [1040];
  char local_428 [1040];
  ulonglong local_18;
  undefined8 uStack_10;
  
  uStack_10 = 0x180026520;
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_1088;
  iVar4 = -1;
  local_1068[0] = -1;
  if ((*(uint *)(xprtdata_exref + 0x93c) & 0x10000000) == 0) {
    iVar3 = *(int *)(*(longlong *)SBdataptr_exref + 0x1214);
    if (iVar3 == 0) {
      if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {
        lVar2 = -(longlong)param_2;
        do {
          cVar1 = *param_2;
          param_2[(longlong)(local_1058 + lVar2)] = cVar1;
          param_2 = param_2 + 1;
        } while (cVar1 != '\0');
      }
      else {
        FUN_180026740(param_1,param_2,local_1058,1);
      }
      iVar4 = _access(local_1058,0);
    }
    else if (((iVar3 == 1) || (iVar3 == 2)) || (iVar3 == 3)) {
      CUsethvr("_HFILE",param_2,lvars_exref,0x400);
      CUsubhvr(lvars_exref,local_1058,*(longlong *)SBdataptr_exref + 0xf14,0);
      CUusthvr("_HFILE",lvars_exref,0x400);
      sscanf(local_1058,"%s %s",local_838,local_428);
      iVar4 = FUN_180035180(local_838,param_2,local_c48,local_1068);
      if ((iVar4 != 0) || (iVar4 = 0, local_1068[0] != 0)) {
        return -1;
      }
    }
  }
  else {
    CUsethvr("_HFILE",param_2,lvars_exref);
    uVar5 = 0;
    CUsubhvr(lvars_exref,local_1058,*(longlong *)SBdataptr_exref + 0xf14);
    CUusthvr("_HFILE",lvars_exref,0x400);
    FUN_180028100(local_1058,0);
    iVar3 = FUN_1800270a0(1);
    if (iVar3 != 0x42) {
      FUN_180008f80(local_c48,"%s does not exist",param_2,uVar5);
      FUN_180028530(local_c48,-1);
    }
  }
  return iVar4;
}

/* RVA 0x26740 */
undefined1 * FUN_180026740(char *param_1,char *param_2,undefined1 *param_3,int param_4)

{
  char *pcVar1;
  char cVar2;
  undefined1 uVar3;
  longlong lVar4;
  undefined1 *puVar5;
  undefined2 *puVar6;
  longlong lVar7;
  ulonglong uVar8;
  
  if (param_4 != 0) {
    uVar3 = 0;
  }
  else {
    param_3[1] = 0;
    uVar3 = 0x22;
  }
  uVar8 = (ulonglong)(param_4 == 0);
  *param_3 = uVar3;
  lVar7 = -1;
  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {
LAB_1800267cd:
    if (param_2 == (char *)0x0) goto LAB_180026810;
  }
  else {
    lVar4 = -1;
    do {
      lVar4 = lVar4 + 1;
    } while (param_1[lVar4] != '\0');
    uVar8 = uVar8 + lVar4;
    puVar5 = param_3 + -1;
    do {
      pcVar1 = puVar5 + 1;
      puVar5 = puVar5 + 1;
    } while (*pcVar1 != '\0');
    lVar4 = 0;
    do {
      cVar2 = param_1[lVar4];
      puVar5[lVar4] = cVar2;
      lVar4 = lVar4 + 1;
    } while (cVar2 != '\0');
    if (param_3[uVar8 - 1] == '\\') goto LAB_1800267cd;
    if ((param_2 == (char *)0x0) || (*param_2 == '\0')) goto LAB_180026810;
    *(undefined2 *)(param_3 + uVar8) = 0x5c;
    uVar8 = uVar8 + 1;
  }
  if (*param_2 != '\0') {
    do {
      lVar7 = lVar7 + 1;
    } while (param_2[lVar7] != '\0');
    uVar8 = uVar8 + lVar7;
    puVar5 = param_3 + -1;
    do {
      pcVar1 = puVar5 + 1;
      puVar5 = puVar5 + 1;
    } while (*pcVar1 != '\0');
    lVar7 = 0;
    do {
      cVar2 = param_2[lVar7];
      puVar5[lVar7] = cVar2;
      lVar7 = lVar7 + 1;
    } while (cVar2 != '\0');
  }
LAB_180026810:
  if (param_4 != 0) {
    param_3[uVar8] = 0;
    return param_3;
  }
  puVar6 = (undefined2 *)(param_3 + -1);
  do {
    pcVar1 = (char *)((longlong)puVar6 + 1);
    puVar6 = (undefined2 *)((longlong)puVar6 + 1);
  } while (*pcVar1 != '\0');
  *puVar6 = DAT_1800426a4;
  param_3[uVar8 + 1] = 0;
  return param_3;
}

/* RVA 0x26860 */
undefined1 * FUN_180026860(char *param_1,char *param_2,undefined1 *param_3,int param_4)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  char *pcVar4;
  size_t _Count;
  longlong lVar5;
  longlong lVar6;
  
  lVar6 = 0;
  lVar5 = -1;
  bVar2 = false;
  if (((param_4 == 0) || (param_1 == (char *)0x0)) ||
     ((*param_1 != '\"' && (pcVar4 = strchr(param_1,0x20), pcVar4 == (char *)0x0)))) {
    *param_3 = 0;
    bVar3 = false;
    if (param_1 == (char *)0x0) goto LAB_18002693c;
  }
  else {
    lVar6 = 1;
    *param_3 = 0x22;
    param_3[1] = 0;
    bVar3 = true;
  }
  do {
    bVar2 = bVar3;
    if (*param_1 == '\0') break;
    pcVar4 = strchr(param_1,0x22);
    if (pcVar4 == (char *)0x0) {
      if (*param_1 != '\0') {
        _Count = 0xffffffffffffffff;
        do {
          _Count = _Count + 1;
        } while (param_1[_Count] != '\0');
        strncpy(param_3 + lVar6,param_1,_Count);
        lVar6 = lVar6 + _Count;
      }
      break;
    }
    strncpy(param_3 + lVar6,param_1,(longlong)pcVar4 - (longlong)param_1);
    lVar6 = lVar6 + ((longlong)pcVar4 - (longlong)param_1);
    param_1 = pcVar4 + 1;
    bVar3 = bVar2;
  } while (param_1 != (char *)0x0);
LAB_18002693c:
  if ((param_2 != (char *)0x0) && (*param_2 != '\0')) {
    if (param_3[lVar6 + -1] != '\\') {
      param_3[lVar6] = 0x5c;
      lVar6 = lVar6 + 1;
    }
    pcVar4 = param_2;
    do {
      cVar1 = *pcVar4;
      (param_3 + (lVar6 - (longlong)param_2))[(longlong)pcVar4] = cVar1;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    do {
      lVar5 = lVar5 + 1;
    } while (param_2[lVar5] != '\0');
    lVar6 = lVar6 + lVar5;
  }
  if (bVar2) {
    *(undefined2 *)(param_3 + lVar6) = 0x22;
    return param_3;
  }
  param_3[lVar6] = 0;
  return param_3;
}

/* RVA 0x269c0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_1800269c0(char *param_1,undefined1 *param_2)

{
  int iVar1;
  DWORD DVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined1 auStackY_278 [32];
  char *local_248 [2];
  char local_238 [272];
  char local_128 [272];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStackY_278;
  iVar1 = SBlocalhost();
  if (iVar1 == 0) {
    uVar3 = FUN_180026f10(local_238,(int *)local_248);
    if ((int)uVar3 == 0) {
      if ((int)local_248[0] != 0) goto LAB_180026bd5;
      FUN_180026860(local_238,"xeq",local_128,0);
      FUN_180026860(local_128,param_1,local_238,0);
      iVar1 = FUN_180026510((char *)0x0,local_238);
      if (iVar1 == 0) goto LAB_180026ab0;
    }
    uVar3 = FUN_180026fe0(local_238,(int *)local_248);
    if ((int)uVar3 == 0) {
      if ((int)local_248[0] != 0) goto LAB_180026bd5;
      FUN_180026860(local_238,"xeq",local_128,0);
      FUN_180026860(local_128,param_1,local_238,0);
      iVar1 = FUN_180026510((char *)0x0,local_238);
      if (iVar1 == 0) goto LAB_180026ab0;
    }
    FUN_180026860(param_1,(char *)0x0,local_238,0);
  }
  else {
    lVar4 = MDfndfil(1,param_1);
    if (lVar4 == 0) {
      local_248[0] = (char *)GetGlobalPointer("ASPTOP");
      if (local_248[0] != (char *)0x0) {
        FUN_180026860(local_248[0],"xeq",local_128,0);
        FUN_180026860(local_128,param_1,local_238,0);
        iVar1 = FUN_180026510((char *)0x0,local_238);
        if (iVar1 == 0) goto LAB_180026ab0;
      }
      local_248[0] = (char *)GetGlobalPointer();
      if (local_248[0] != (char *)0x0) {
        FUN_180026860(local_248[0],"xeq",local_128,0);
        FUN_180026860(local_128,param_1,local_238,0);
        iVar1 = FUN_180026510((char *)0x0,local_238);
        if (iVar1 == 0) goto LAB_180026ab0;
      }
      DVar2 = SearchPathA((LPCSTR)0x0,param_1,(LPCSTR)0x0,0x104,local_238,local_248);
      if (DVar2 == 0) {
LAB_180026ab0:
        FUN_180026860(local_238,(char *)0x0,param_2,1);
        return 0;
      }
    }
  }
LAB_180026bd5:
  iVar1 = FUN_180026510((char *)0x0,local_238);
  FUN_180026860(local_238,(char *)0x0,param_2,1);
  return iVar1;
}

/* RVA 0x26c20 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180026c20(char *param_1,undefined *param_2,uint *param_3)

{
  code cVar1;
  char cVar2;
  longlong lVar3;
  int iVar4;
  longlong lVar5;
  longlong lVar6;
  code *pcVar7;
  char *pcVar8;
  longlong lVar9;
  undefined **ppuVar10;
  int iVar11;
  undefined1 auStack_168 [32];
  char local_148 [272];
  ulonglong local_38;
  
  local_38 = DAT_1800516d8 ^ (ulonglong)auStack_168;
  iVar11 = 0;
  if (0 < DAT_180050db0) {
    ppuVar10 = &PTR_s_runid_180050d80;
    do {
      iVar4 = _stricmp(param_1,*ppuVar10);
      if (iVar4 == 0) break;
      iVar11 = iVar11 + 1;
      ppuVar10 = ppuVar10 + 1;
    } while (iVar11 < DAT_180050db0);
  }
  if (param_3 == (uint *)0x0) {
    return 0xffffffffffffffff;
  }
  switch(iVar11) {
  case 0:
    lVar9 = -1;
    pcVar7 = APtmpfil_exref;
    if (param_2 != (undefined *)0x0) {
      lVar6 = -1;
      do {
        lVar6 = lVar6 + 1;
      } while (APtmpfil_exref[lVar6] != (code)0x0);
      if ((int)lVar6 < (int)*param_3) {
        do {
          cVar1 = *pcVar7;
          pcVar7 = pcVar7 + 1;
          *param_2 = cVar1;
          param_2 = param_2 + 1;
        } while (cVar1 != (code)0x0);
        pcVar7 = APtmpfil_exref;
      }
    }
    do {
      lVar9 = lVar9 + 1;
    } while (pcVar7[lVar9] != (code)0x0);
    break;
  case 1:
    _getcwd(local_148,0x104);
    lVar6 = -1;
    if (param_2 != (undefined *)0x0) {
      lVar9 = -1;
      do {
        lVar5 = lVar9 + 1;
        lVar3 = lVar9 + 1;
        lVar9 = lVar5;
      } while (local_148[lVar3] != '\0');
      if ((int)lVar5 < (int)*param_3) {
        pcVar8 = local_148;
        do {
          cVar2 = *pcVar8;
          pcVar8[(longlong)param_2 - (longlong)local_148] = cVar2;
          pcVar8 = pcVar8 + 1;
        } while (cVar2 != '\0');
      }
    }
    do {
      lVar9 = lVar6 + 1;
      lVar3 = lVar6 + 1;
      lVar6 = lVar9;
    } while (local_148[lVar3] != '\0');
    break;
  case 2:
    lVar9 = -1;
    if (param_2 != (undefined *)0x0) {
      lVar6 = -1;
      pcVar8 = (char *)(*(longlong *)SBdataptr_exref + 0x10);
      do {
        lVar6 = lVar6 + 1;
      } while (pcVar8[lVar6] != '\0');
      if ((int)lVar6 < (int)*param_3) {
        do {
          cVar2 = *pcVar8;
          pcVar8 = pcVar8 + 1;
          *param_2 = cVar2;
          param_2 = param_2 + 1;
        } while (cVar2 != '\0');
      }
    }
    do {
      lVar9 = lVar9 + 1;
    } while (*(char *)(*(longlong *)SBdataptr_exref + 0x10 + lVar9) != '\0');
    break;
  case 3:
    if ((param_2 != (undefined *)0x0) && (3 < *param_3)) {
      *(uint *)param_2 = (uint)(*(int *)(*(longlong *)SBdataptr_exref + 0x1214) != 0);
    }
    *param_3 = 4;
    return 0;
  case 4:
    lVar9 = -1;
    if (param_2 != (undefined *)0x0) {
      lVar6 = -1;
      pcVar8 = (char *)(*(longlong *)SBdataptr_exref + 0x1324);
      do {
        lVar6 = lVar6 + 1;
      } while (pcVar8[lVar6] != '\0');
      if ((int)lVar6 < (int)*param_3) {
        do {
          cVar2 = *pcVar8;
          pcVar8 = pcVar8 + 1;
          *param_2 = cVar2;
          param_2 = param_2 + 1;
        } while (cVar2 != '\0');
      }
    }
    do {
      lVar9 = lVar9 + 1;
    } while (*(char *)(*(longlong *)SBdataptr_exref + 0x1324 + lVar9) != '\0');
    break;
  case 5:
    lVar9 = -1;
    if (param_2 != (undefined *)0x0) {
      lVar6 = -1;
      pcVar8 = (char *)(*(longlong *)SBdataptr_exref + 0x1224);
      do {
        lVar6 = lVar6 + 1;
      } while (pcVar8[lVar6] != '\0');
      if ((int)lVar6 < (int)*param_3) {
        do {
          cVar2 = *pcVar8;
          pcVar8 = pcVar8 + 1;
          *param_2 = cVar2;
          param_2 = param_2 + 1;
        } while (cVar2 != '\0');
      }
    }
    do {
      lVar9 = lVar9 + 1;
    } while (*(char *)(*(longlong *)SBdataptr_exref + 0x1224 + lVar9) != '\0');
    break;
  default:
    goto LAB_180026ed0;
  }
  *param_3 = (uint)lVar9;
LAB_180026ed0:
  return 0;
}

/* RVA 0x26f10 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180026f10(undefined8 param_1,int *param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined1 auStack_248 [32];
  char local_228 [8];
  char local_220 [2];
  char local_21e;
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_248;
  local_220 = (char  [2])s__Software__1800421e0._8_2_;
  local_21e = s__Software__1800421e0[10];
  local_228 = (char  [8])s__Software__1800421e0._0_8_;
  lVar1 = GetGlobalPointer("RegistryKey");
  lVar2 = GetGlobalPointer("ProfileName");
  if ((lVar1 == 0) || (lVar2 == 0)) {
    uVar3 = 0xffffffff;
  }
  else {
    FUN_180008f80(local_228,"Software\\%s\\%s\\aplus\\asptop",lVar1,lVar2);
    uVar3 = FUN_180035320(local_228,param_1,param_2,lVar2);
  }
  return uVar3;
}

/* RVA 0x26fe0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180026fe0(undefined8 param_1,int *param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  char *pcVar3;
  undefined1 auStack_258 [32];
  longlong local_238;
  undefined1 local_228 [528];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_258;
  lVar1 = GetGlobalPointer("RegistryKey");
  local_238 = MVGetRegistryKey();
  if ((lVar1 == 0) || (local_238 == 0)) {
    uVar2 = 0xffffffff;
  }
  else {
    pcVar3 = "APrSystem";
    FUN_180008f80(local_228,"Software\\%s\\%s\\%s\\aplus\\asptop",lVar1,"APrSystem");
    uVar2 = FUN_180035320(local_228,param_1,param_2,pcVar3);
    if (((int)uVar2 != 0) || (*param_2 != 0)) {
      uVar2 = FUN_180026f10(param_1,param_2);
    }
  }
  return uVar2;
}

/* RVA 0x270a0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_1800270a0(int param_1)

{
  bool bVar1;
  int iVar2;
  FILE *_File;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  undefined1 auStack_b8 [32];
  char local_98 [128];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_b8;
  iVar5 = 0;
  bVar1 = false;
  _File = fopen("results.mm","r");
  if (_File == (FILE *)0x0) {
    iVar2 = -1;
  }
  else {
    pcVar3 = fgets(local_98,0x78,_File);
    while (pcVar3 != (char *)0x0) {
      pcVar4 = strstr(pcVar3,"))ASPACK**");
      if (pcVar4 == (char *)0x0) {
        if (bVar1) goto LAB_18002713f;
      }
      else {
        bVar1 = true;
LAB_18002713f:
        pcVar3 = strstr(pcVar3,"))ASPEN");
        if (pcVar3 != (char *)0x0) {
          iVar5 = (int)pcVar3[7];
        }
      }
      pcVar3 = fgets(local_98,0x78,_File);
    }
    fclose(_File);
    if (param_1 != 0) {
      remove("results.mm");
    }
    iVar2 = -1;
    if (bVar1) {
      iVar2 = iVar5;
    }
  }
  return iVar2;
}

/* RVA 0x271d0 */
void FUN_1800271d0(undefined4 *param_1,int param_2)

{
  if (param_2 == 0) {
    *param_1 = *(undefined4 *)(*(longlong *)SBdataptr_exref + 0xc);
  }
  else if (param_2 == 1) {
    *(undefined4 *)(*(longlong *)SBdataptr_exref + 0xc) = *param_1;
    return;
  }
  return;
}

/* RVA 0x27200 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char * FUN_180027200(char *param_1)

{
  char cVar1;
  char *pcVar2;
  undefined2 *puVar3;
  longlong lVar4;
  longlong lVar5;
  
  if (param_1 == (char *)0x0) {
    return (char *)0x0;
  }
  pcVar2 = strchr(param_1,0x2e);
  if (pcVar2 != (char *)0x0) {
    return param_1;
  }
  pcVar2 = (char *)GRinqscp();
  if (pcVar2 == (char *)0x0) {
    DAT_1800521c0 = 0;
  }
  else {
    lVar4 = (longlong)&DAT_1800521c0 - (longlong)pcVar2;
    do {
      cVar1 = *pcVar2;
      pcVar2[lVar4] = cVar1;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    puVar3 = (undefined2 *)0x1800521bf;
    do {
      pcVar2 = (char *)((longlong)puVar3 + 1);
      puVar3 = (undefined2 *)((longlong)puVar3 + 1);
    } while (*pcVar2 != '\0');
    *puVar3 = _DAT_18003fa80;
  }
  lVar4 = 0x1800521bf;
  do {
    pcVar2 = (char *)(lVar4 + 1);
    lVar4 = lVar4 + 1;
  } while (*pcVar2 != '\0');
  lVar5 = 0;
  do {
    cVar1 = param_1[lVar5];
    *(char *)(lVar4 + lVar5) = cVar1;
    lVar5 = lVar5 + 1;
  } while (cVar1 != '\0');
  pcVar2 = strchr(&DAT_1800521c0,0x20);
  if (pcVar2 != (char *)0x0) {
    *pcVar2 = '\0';
  }
  return &DAT_1800521c0;
}

/* RVA 0x272e0 */
undefined8 FUN_1800272e0(char *param_1,undefined8 *param_2,undefined8 *param_3)

{
  char cVar1;
  char *pcVar2;
  undefined1 *puVar3;
  longlong lVar4;
  ulonglong uVar5;
  
  if (param_2 != (undefined8 *)0x0) {
    *param_2 = 0;
  }
  if (param_3 != (undefined8 *)0x0) {
    *param_3 = 0;
  }
  if (param_1 != (char *)0x0) {
    pcVar2 = strrchr(param_1,0x2e);
    if (pcVar2 != (char *)0x0) {
      if (param_2 != (undefined8 *)0x0) {
        uVar5 = (longlong)pcVar2 - (longlong)param_1;
        lVar4 = (longlong)&DAT_1800521c0 - (longlong)param_1;
        do {
          cVar1 = *param_1;
          param_1[lVar4] = cVar1;
          param_1 = param_1 + 1;
        } while (cVar1 != '\0');
        pcVar2 = strchr(&DAT_1800521c0,0x20);
        if (pcVar2 != (char *)0x0) {
          *pcVar2 = '\0';
        }
        if (0x4f < uVar5) {
                    /* WARNING: Subroutine does not return */
          FUN_18003b6e4();
        }
        (&DAT_1800521c0)[uVar5] = 0;
        *param_2 = &DAT_1800521c0;
        if (param_3 != (undefined8 *)0x0) {
          puVar3 = &DAT_1800521c1 + uVar5;
          if (uVar5 == 0) {
            puVar3 = &DAT_1800521c0;
          }
          *param_3 = puVar3;
        }
      }
      return 1;
    }
    if (param_3 != (undefined8 *)0x0) {
      *param_3 = param_1;
    }
  }
  return 0;
}

/* RVA 0x273d0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_1800273d0(char *param_1)

{
  code cVar1;
  char cVar2;
  int iVar3;
  undefined8 uVar4;
  char *pcVar5;
  char *pcVar6;
  code *pcVar7;
  longlong lVar8;
  char *pcVar9;
  longlong lVar11;
  longlong lVar10;
  undefined1 *puVar12;
  char *pcVar13;
  bool bVar14;
  undefined1 auStack_878 [32];
  char local_858 [232];
  undefined8 uStack_770;
  undefined1 local_768 [32];
  int local_748;
  undefined4 uStack_744;
  undefined1 local_740 [24];
  char local_728 [272];
  char local_618 [528];
  char local_408 [80];
  char local_3b8 [256];
  char local_2b8 [400];
  char local_128 [272];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)&local_748;
  *param_1 = '\0';
  local_748 = -1;
  pcVar7 = APtmpfil_exref;
  do {
    cVar1 = *pcVar7;
    pcVar7[(longlong)(local_740 + -(longlong)APtmpfil_exref)] = cVar1;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != (code)0x0);
  uStack_770 = 0x180027437;
  name_lwr(local_740);
  uStack_770 = 0x180027454;
  CUsethvr(&DAT_18004228c,local_740,lvars_exref,0x400);
  uStack_770 = 0x180027474;
  CUsubhvr(lvars_exref,param_1,xprtdata_exref + 0x300,0);
  if (*param_1 == '\0') {
LAB_1800275cf:
    pcVar13 = "No simulation program specified in mm.ini file";
  }
  else {
    pcVar13 = local_3b8;
    uStack_770 = 0x18002749a;
    sscanf(param_1,"%s %s",local_618,pcVar13);
    puVar12 = local_768;
    lVar8 = *(longlong *)SBdataptr_exref;
    iVar3 = *(int *)(lVar8 + 0x1214);
    if (iVar3 == 0) {
      iVar3 = *(int *)(lVar8 + 0x1218);
      if (iVar3 == 0) {
        if (*param_1 != '\0') {
          uStack_770 = 0x180027964;
          pcVar5 = getenv("ASP$COM");
          if (pcVar5 != (char *)0x0) {
            uStack_770 = 0x180027976;
            pcVar5 = getenv("ASP$XEQ");
            puVar12 = local_768;
            if (pcVar5 != (char *)0x0) goto LAB_18002797b;
          }
          pcVar13 = "No ASP$COM and ASP$XEQ set in environment";
          goto LAB_1800275d6;
        }
      }
      else {
        if (iVar3 != 1) {
          if (iVar3 == 2) {
            if (*param_1 == '\0') goto LAB_1800275cf;
            uStack_770 = 0x180027617;
            pcVar5 = getenv("ASPDIR");
            puVar12 = local_768;
            if (pcVar5 == (char *)0x0) {
              pcVar13 = "No ASPDIR set in environment";
              goto LAB_1800275d6;
            }
          }
          else if (*param_1 == '\0') goto LAB_1800275cf;
          goto LAB_18002797b;
        }
        if (local_618[0] != '\0') {
          uStack_770 = 0x180027637;
          iVar3 = MVGetProductCode();
          if (iVar3 == 2) {
            uStack_770 = 0x180027654;
            iVar3 = strncmp(local_618,"APropMain.exe",0xd);
            if (iVar3 != 0) {
              uStack_770 = 0x18002766b;
              iVar3 = _access(local_618,0);
              if (iVar3 != 0) {
                lVar8 = 0;
                do {
                  pcVar5 = local_618 + lVar8;
                  local_728[lVar8] = *pcVar5;
                  lVar8 = lVar8 + 1;
                } while (*pcVar5 != '\0');
LAB_1800276e4:
                uStack_770 = 0x1800276fb;
                FUN_180008f80(local_618,"Cannot access simulation program %s\n",local_728,pcVar13);
                pcVar13 = local_618;
                goto LAB_1800275d6;
              }
            }
          }
          else {
            uStack_770 = 0x1800276a9;
            iVar3 = strncmp(local_618,"apmain.exe",10);
            if (iVar3 != 0) {
              uStack_770 = 0x1800276bc;
              iVar3 = _access(local_618,0);
              if (iVar3 != 0) {
                lVar8 = 0;
                do {
                  pcVar5 = local_618 + lVar8;
                  local_728[lVar8] = *pcVar5;
                  lVar8 = lVar8 + 1;
                } while (*pcVar5 != '\0');
                goto LAB_1800276e4;
              }
            }
          }
          uStack_770 = 0x180027716;
          iVar3 = _access(local_618,0);
          if (iVar3 != 0) {
            uStack_770 = 0x1800277ed;
            pcVar13 = (char *)GetGlobalPointer("ASPTOP");
            if (pcVar13 != (char *)0x0) {
              uStack_770 = 0x18002780f;
              FUN_180026860(pcVar13,"xeq",local_2b8,0);
              uStack_770 = 0x180027829;
              FUN_180026860(local_2b8,local_618,local_728,0);
              uStack_770 = 0x180027835;
              iVar3 = _access(local_728,0);
              if (iVar3 == 0) {
                pcVar13 = local_728;
                pcVar5 = (char *)(*(longlong *)SBdataptr_exref + 0x1674);
                do {
                  cVar2 = *pcVar13;
                  pcVar13 = pcVar13 + 1;
                  *pcVar5 = cVar2;
                  pcVar5 = pcVar5 + 1;
                } while (cVar2 != '\0');
                lVar8 = *(longlong *)SBdataptr_exref;
                lVar10 = -1;
                do {
                  lVar11 = lVar10;
                  lVar10 = lVar11 + 1;
                } while (*(char *)(lVar8 + 0x1674 + lVar10) != '\0');
                pcVar13 = (char *)(lVar8 + 0x1673 + lVar10);
                if (-1 < lVar11) {
                  pcVar5 = pcVar13 + (-0x1674 - lVar8);
                  while (cVar2 = *pcVar13, cVar2 != '.') {
                    if (((cVar2 == '\\') || (cVar2 == '/')) || (cVar2 == '\0')) goto LAB_1800278d1;
                    pcVar13 = pcVar13 + -1;
                    pcVar5 = pcVar5 + -1;
                    if ((longlong)pcVar5 < 0) goto LAB_1800278d1;
                  }
                  *pcVar13 = '\0';
                }
LAB_1800278d1:
                pcVar13 = (char *)0x1;
                uStack_770 = 0x1800278e5;
                FUN_180026860(local_728,(char *)0x0,param_1,1);
                puVar12 = local_768;
                pcVar5 = param_1 + -1;
                do {
                  pcVar9 = pcVar5 + 1;
                  pcVar5 = pcVar5 + 1;
                } while (*pcVar9 != '\0');
                *(undefined2 *)pcVar5 = DAT_18003f9bc;
                pcVar5 = param_1 + -1;
                do {
                  pcVar9 = pcVar5 + 1;
                  pcVar5 = pcVar5 + 1;
                } while (*pcVar9 != '\0');
                lVar8 = 0;
                do {
                  cVar2 = local_3b8[lVar8];
                  pcVar5[lVar8] = cVar2;
                  lVar8 = lVar8 + 1;
                } while (cVar2 != '\0');
                goto LAB_18002797b;
              }
            }
            pcVar13 = "AspenPlus engine is not installed";
            goto LAB_1800275d6;
          }
          uStack_770 = 0x18002772d;
          _getcwd(local_408,0x50);
          uStack_770 = 0x18002773e;
          pcVar5 = strchr(local_618,0x3a);
          if ((pcVar5 == (char *)0x0) && (local_618[0] != '\\')) {
            pcVar13 = (char *)0x1;
            uStack_770 = 0x180027776;
            FUN_180026740(local_408,local_618,(undefined1 *)(*(longlong *)SBdataptr_exref + 0x1674),
                          1);
          }
          else {
            pcVar5 = local_618;
            pcVar9 = (char *)(*(longlong *)SBdataptr_exref + 0x1674);
            do {
              cVar2 = *pcVar5;
              pcVar5 = pcVar5 + 1;
              *pcVar9 = cVar2;
              pcVar9 = pcVar9 + 1;
            } while (cVar2 != '\0');
          }
          puVar12 = local_768;
          pcVar5 = (char *)(*(longlong *)SBdataptr_exref + 0x1674);
          cVar2 = *pcVar5;
          pcVar9 = (char *)CONCAT44(uStack_744,local_748);
          while (cVar2 != '\0') {
            bVar14 = cVar2 != '.';
            cVar2 = pcVar5[1];
            pcVar6 = pcVar5;
            if (bVar14) {
              pcVar6 = pcVar9;
            }
            pcVar5 = pcVar5 + 1;
            pcVar9 = pcVar6;
          }
          *pcVar9 = '\0';
          goto LAB_18002797b;
        }
      }
      goto LAB_1800275cf;
    }
    if ((((iVar3 != 1) && (iVar3 != 2)) && (puVar12 = local_768, iVar3 != 3)) ||
       (puVar12 = local_768, *(int *)(lVar8 + 0x1218) != 1)) {
LAB_18002797b:
      if (*(int *)debug_flag_exref != 0) {
        *(undefined8 *)(puVar12 + -8) = 0x18002799d;
        FUN_180008f80(local_2b8,"The command to be executed is: %s",param_1,pcVar13);
        *(undefined8 *)(puVar12 + -8) = 0x1800279a9;
        FUN_1800282b0(local_2b8);
      }
      uVar4 = 1;
      goto LAB_1800275df;
    }
    uStack_770 = 0x1800274e2;
    uVar4 = FUN_180026f10(local_128,&local_748);
    if (((int)uVar4 == 0) && (local_748 == 0)) {
      FUN_180026860(local_128,"xeq",local_858,0);
      FUN_180026860(local_858,local_618,local_728,0);
      pcVar13 = (char *)0x1;
      FUN_180026860(local_728,(char *)0x0,param_1,1);
      puVar12 = auStack_878;
      pcVar5 = param_1 + -1;
      do {
        pcVar9 = pcVar5 + 1;
        pcVar5 = pcVar5 + 1;
      } while (*pcVar9 != '\0');
      *(undefined2 *)pcVar5 = DAT_18003f9bc;
      pcVar5 = param_1 + -1;
      do {
        pcVar9 = pcVar5 + 1;
        pcVar5 = pcVar5 + 1;
      } while (*pcVar9 != '\0');
      lVar8 = 0;
      do {
        cVar2 = local_3b8[lVar8];
        pcVar5[lVar8] = cVar2;
        lVar8 = lVar8 + 1;
      } while (cVar2 != '\0');
      goto LAB_18002797b;
    }
    pcVar13 = "Missing ASPTOP in local/remote host registry";
  }
LAB_1800275d6:
  puVar12 = local_768;
  uStack_770 = 0x1800275dd;
  FUN_180028530(pcVar13,-1);
  uVar4 = 0;
LAB_1800275df:
  *(undefined8 *)(puVar12 + -8) = 0x1800275ee;
  return uVar4;
}

/* RVA 0x279c0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1800279c0(char *param_1)

{
  char cVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  int iVar4;
  void *pvVar5;
  char *pcVar6;
  undefined1 *puVar7;
  longlong lVar8;
  longlong lVar9;
  undefined4 *puVar10;
  int iVar11;
  longlong lVar12;
  undefined **ppuVar13;
  undefined1 auStack_298 [79];
  undefined1 uStack_249;
  uchar local_248 [271];
  undefined4 uStack_139;
  undefined1 local_134 [268];
  ulonglong local_28;
  
  local_28 = DAT_1800516d8 ^ (ulonglong)auStack_298;
  iVar11 = 0;
  _unlink("fort.15");
  _unlink("aptime.fil");
  _unlink("ndpasm.tmp");
  if (PTR_DAT_180050ae0 != (undefined *)0x0) {
    lVar12 = 0;
    ppuVar13 = &PTR_DAT_180050ae0;
    do {
      pcVar6 = param_1;
      do {
        cVar1 = *pcVar6;
        pcVar6[(longlong)(local_248 + -(longlong)param_1)] = cVar1;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      puVar7 = &uStack_249;
      do {
        pcVar6 = puVar7 + 1;
        puVar7 = puVar7 + 1;
      } while (*pcVar6 != '\0');
      puVar2 = *ppuVar13;
      lVar8 = 0;
      do {
        cVar1 = puVar2[lVar8];
        puVar7[lVar8] = cVar1;
        lVar8 = lVar8 + 1;
      } while (cVar1 != '\0');
      name_lwr(local_248);
      iVar4 = _unlink((char *)local_248);
      if (iVar4 == -1) {
        lVar8 = 0;
        do {
          lVar9 = lVar8 + 1;
          if ((*ppuVar13)[lVar8] != (&DAT_1800420fc)[lVar8]) goto LAB_180027b21;
          lVar8 = lVar9;
        } while (lVar9 != 5);
        iVar4 = _stat64i32(local_248);
        if (iVar4 == 0) {
          for (; iVar11 < 10; iVar11 = iVar11 + 1) {
            _sleep(1000);
            iVar4 = _unlink((char *)local_248);
            if (iVar4 == 0) break;
          }
        }
      }
LAB_180027b21:
      lVar12 = lVar12 + 1;
      ppuVar13 = &PTR_DAT_180050ae0 + lVar12;
    } while ((&PTR_DAT_180050ae0)[lVar12] != (undefined *)0x0);
  }
  lVar12 = 0x110 - (longlong)param_1;
  do {
    cVar1 = *param_1;
    param_1[(longlong)(local_248 + lVar12)] = cVar1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  puVar3 = &uStack_139;
  do {
    puVar10 = puVar3;
    puVar3 = (undefined4 *)((longlong)puVar10 + 1);
  } while (*(char *)((longlong)puVar10 + 1) != '\0');
  *(undefined4 *)((longlong)puVar10 + 1) = DAT_18004266c;
  *(undefined1 *)((longlong)puVar10 + 5) = DAT_180042670;
  lVar12 = -1;
  do {
    lVar9 = lVar12 + 1;
    lVar8 = lVar12 + 0x111;
    lVar12 = lVar9;
  } while (local_248[lVar8] != '\0');
  pvVar5 = FUN_180028970(".");
  lVar12 = FUN_180028a40((longlong)pvVar5);
  if (lVar12 != 0) {
    do {
      iVar11 = strncmp((char *)(lVar12 + 0x1c),(char *)((longlong)&uStack_139 + 1),
                       (longlong)(int)lVar9);
      if (iVar11 == 0) {
        _unlink((char *)(lVar12 + 0x1c));
      }
      lVar12 = FUN_180028a40((longlong)pvVar5);
    } while (lVar12 != 0);
  }
  FUN_180028750(pvVar5);
  return;
}

/* RVA 0x27c40 */
void FUN_180027c40(char *param_1,int param_2)

{
  char cVar1;
  char *pcVar2;
  
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

/* RVA 0x27cb0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180027cb0(char *param_1)

{
  int iVar1;
  char *pcVar2;
  undefined4 *puVar3;
  char *pcVar4;
  undefined4 *puVar5;
  char *pcVar6;
  char *pcVar7;
  undefined1 auStack_8d8 [32];
  uchar local_8b8 [272];
  char local_7a8 [272];
  uchar local_698 [272];
  uchar local_588 [272];
  undefined1 local_478 [272];
  char local_368 [272];
  undefined1 local_258 [272];
  undefined1 local_148 [272];
  ulonglong local_38;
  
  if ((((param_1 != (char *)0x0) &&
       (local_38 = DAT_1800516d8 ^ (ulonglong)auStack_8d8, *param_1 != '\0')) &&
      (DAT_180052ec4 != 0)) &&
     (((iVar1 = GRinqcnn(), iVar1 != 0 && (iVar1 = GRinqcnn(), iVar1 != 1)) &&
      (*(int *)(*(longlong *)topfinfo_exref + 0x660) == 0)))) {
    iVar1 = MVGetProductCode();
    puVar3 = (undefined4 *)&DAT_180040b78;
    puVar5 = (undefined4 *)&DAT_180040b78;
    if (iVar1 == 1) {
      puVar5 = &DAT_180040b80;
    }
    FUN_180008f80(local_368,&DAT_18003f9b0,APtmpfil_exref,puVar5);
    iVar1 = MVGetProductCode();
    pcVar7 = ".aprhis";
    pcVar6 = ".aprhis";
    if (iVar1 == 1) {
      pcVar6 = ".his";
    }
    FUN_180008f80(local_7a8,&DAT_18003f9b0,APtmpfil_exref,pcVar6);
    FUN_180008f80(local_258,"%s.pppdf",APtmpfil_exref,pcVar6);
    pcVar4 = "%s.f";
    if ((*(int *)(*(longlong *)SBdataptr_exref + 0x1218) == 0) ||
       (pcVar2 = "%s.f", *(int *)(*(longlong *)SBdataptr_exref + 0x1218) == 1)) {
      pcVar2 = "%s.for";
    }
    FUN_180008f80(local_478,pcVar2,APtmpfil_exref,pcVar6);
    iVar1 = MVGetProductCode();
    if (iVar1 == 1) {
      puVar3 = &DAT_180040b80;
    }
    FUN_180008f80(local_698,&DAT_18003f9b0,*(undefined8 *)topfinfo_exref,puVar3);
    iVar1 = MVGetProductCode();
    if (iVar1 == 1) {
      pcVar7 = ".his";
    }
    FUN_180008f80(local_8b8,&DAT_18003f9b0,*(undefined8 *)topfinfo_exref,pcVar7);
    FUN_180008f80(local_148,"%s.pppdf",*(undefined8 *)topfinfo_exref,pcVar7);
    if ((*(int *)(*(longlong *)SBdataptr_exref + 0x1218) == 0) ||
       (*(int *)(*(longlong *)SBdataptr_exref + 0x1218) == 1)) {
      pcVar4 = "%s.for";
    }
    FUN_180008f80(local_588,pcVar4,*(undefined8 *)topfinfo_exref,pcVar7);
    name_lwr(local_698);
    FUN_180025fb0((char *)open_path_exref,(char *)local_698);
    name_lwr(local_8b8);
    FUN_180025fb0((char *)open_path_exref,(char *)local_8b8);
    name_lwr(local_588);
    FUN_180025fb0((char *)open_path_exref,(char *)local_588);
    if ((((DAT_180052ec4 != 0) && (iVar1 = GRinqcnn(), iVar1 != 0)) &&
        (iVar1 = GRinqcnn(), iVar1 != 1)) && (*(int *)(*(longlong *)topfinfo_exref + 0x660) == 0)) {
      if ((DAT_180052ec4 == 0) || (iVar1 = GRinqiap(), iVar1 != 1)) {
        iVar1 = *(int *)(*(longlong *)topfinfo_exref + 0x380);
        if ((iVar1 == 0x1b) || (iVar1 == 3)) {
          iVar1 = FUN_180026510((char *)0x0,local_7a8);
          if ((iVar1 == 0) && (iVar1 = GRinqiap(), iVar1 == 2)) {
            FUN_180017f80();
            FUN_180025b70((char *)0x0,local_7a8,(char *)open_path_exref,(char *)local_8b8);
            FUN_180017f80();
          }
        }
        else {
          if (iVar1 == 0x2d9) {
            FUN_180025b70((char *)0x0,local_368,(char *)open_path_exref,(char *)local_698);
          }
          else if (((iVar1 != 0xf3) && (iVar1 != 0x51)) && (iVar1 != 9)) {
            return;
          }
          FUN_180025b70((char *)0x0,local_7a8,(char *)open_path_exref,(char *)local_8b8);
        }
      }
      else {
        if (*(int *)(*(longlong *)SBdataptr_exref + 0x1214) != 0) {
          param_1 = *(char **)topfinfo_exref;
        }
        FUN_180019630(param_1);
      }
    }
  }
  return;
}

/* RVA 0x28080 */
void FUN_180028080(void)

{
  int iVar1;
  char local_res8;
  
  if (PTR__guard_check_icall_180044160[4] == '\0') {
    return;
  }
  iVar1 = *(int *)(PTR__guard_check_icall_180044160 + 0x408);
  if (iVar1 == 0) {
    local_res8 = 'i';
  }
  else if (iVar1 == 1) {
    local_res8 = '!';
  }
  else if (iVar1 == 2) {
    local_res8 = 'X';
  }
  FUN_180008f80(dbxbuf_exref,"%c%c%s",0x5e,(ulonglong)(uint)(int)local_res8);
  EXyesno(dbxbuf_exref,2,1);
  return;
}

/* RVA 0x28100 */
ulonglong FUN_180028100(undefined8 param_1,undefined4 param_2)

{
  ulonglong uVar1;
  undefined4 local_res18;
  
  if (*(int *)in_graphics_exref != 0) {
    local_res18 = *(undefined4 *)mask_pushed_exref;
    *(undefined4 *)mask_pushed_exref = 0;
    show_mouse();
    show_mouse();
    show_mouse();
    hide_mouse();
    push_mouse_mask(0xd);
    show_mouse();
  }
  uVar1 = SPAWN(DAT_180052d78,param_1,param_2,0,0,0,0);
  if (*(int *)in_graphics_exref != 0) {
    pop_mouse_mask();
    *(undefined4 *)mask_pushed_exref = local_res18;
    show_mouse();
    uVar1 = uVar1 & 0xffffffff;
  }
  return uVar1;
}

/* RVA 0x281c0 */
void FUN_1800281c0(char *param_1)

{
  FUN_180008f30(param_1);
  if ((DAT_180051e50 == 0) || (param_1 == (char *)0x0)) {
    return;
  }
  hide_mouse();
  thunk_FUN_180008f30(param_1);
  _guard_check_icall();
  show_mouse();
  return;
}

/* RVA 0x28200 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180028200(undefined8 param_1)

{
  undefined2 *puVar1;
  undefined8 uVar2;
  undefined2 *puVar3;
  undefined1 auStack_d8 [31];
  undefined2 uStack_b9;
  undefined1 local_b6 [158];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_d8;
  FUN_1800282b0("");
  uVar2 = GEtim_buf();
  FUN_180008f80((longlong)&uStack_b9 + 1,"<< %s %s",param_1,uVar2);
  SFfiltra((longlong)&uStack_b9 + 1,&DAT_18004100c);
  puVar1 = &uStack_b9;
  do {
    puVar3 = puVar1;
    puVar1 = (undefined2 *)((longlong)puVar3 + 1);
  } while (*(char *)((longlong)puVar3 + 1) != '\0');
  *(undefined2 *)((longlong)puVar3 + 1) = DAT_180042414;
  *(undefined1 *)((longlong)puVar3 + 3) = DAT_180042416;
  FUN_1800282b0((char *)((longlong)&uStack_b9 + 1));
  FUN_1800282b0("");
  return;
}

/* RVA 0x282b0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1800282b0(char *param_1)

{
  char cVar1;
  longlong lVar2;
  undefined1 auStack_d8 [32];
  char local_b8 [78];
  char local_6a;
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_d8;
  lVar2 = -(longlong)param_1;
  do {
    cVar1 = *param_1;
    param_1[(longlong)(local_b8 + lVar2)] = cVar1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  local_6a = cVar1;
  SimUpdateMessageView(0,local_b8);
  return;
}

/* RVA 0x28310 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180028310(char *param_1,undefined8 param_2,undefined8 param_3,char *param_4)

{
  int iVar1;
  uchar *puVar2;
  uchar *puVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  undefined1 auStack_148 [32];
  uchar local_128 [272];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_148;
  bVar6 = false;
  iVar1 = MVGetProductCode();
  pcVar4 = "aprhis";
  if (iVar1 != 2) {
    pcVar4 = "his";
  }
  if (DAT_180052ec4 == 0) {
LAB_18002840e:
    pcVar5 = pcVar4;
    FUN_180008f80(local_128,"%s.%s",filstr_exref,pcVar4);
    iVar1 = _access((char *)local_128,0);
    bVar6 = iVar1 == 0;
    if (!bVar6) {
      FUN_180008f80(local_128,"%s.%s",APtmpfil_exref,pcVar4);
      pcVar5 = pcVar4;
    }
    pcVar4 = pcVar5;
    name_lwr(local_128);
  }
  else {
    iVar1 = GRinqiap();
    if (iVar1 == 0) {
      if (DAT_180052ec4 == 0) goto LAB_18002840e;
      iVar1 = GRinqiap();
      if (iVar1 != 0) goto LAB_180028496;
      FUN_180008f80(local_128,"%s.%s",APtmpfil_exref,pcVar4);
    }
    else {
      pcVar5 = pcVar4;
      FUN_180008f80(local_128,"%s.%s",filstr_exref,pcVar4);
      iVar1 = _access((char *)local_128,0);
      if (iVar1 == 0) {
        bVar6 = true;
        name_lwr(local_128);
        FUN_180017f80();
        pcVar4 = pcVar5;
      }
      else {
        FUN_180008f80(local_128,"%s.%s",APtmpfil_exref,pcVar4);
        name_lwr(local_128);
        FUN_180017f80();
      }
    }
  }
  iVar1 = _access((char *)local_128,0);
  param_4 = pcVar4;
  if (iVar1 == 0) {
    if (bVar6) {
      puVar3 = (uchar *)0x0;
      puVar2 = local_128;
    }
    else {
      puVar3 = local_128;
      puVar2 = (uchar *)0x0;
    }
    param_4 = param_1;
    FUN_1800259d0((char *)puVar2,(char *)puVar3,(char *)0x0,param_1);
  }
LAB_180028496:
  iVar1 = MVGetProductCode();
  pcVar4 = "$backup.aprbk$";
  if (iVar1 != 2) {
    pcVar4 = "$backup.bk$";
  }
  FUN_180025120(param_1,pcVar4);
  FUN_180008f80(local_128,"%s.jnl",APtmpfil_exref,param_4);
  FUN_180025120(param_1,(char *)local_128);
  if ((DAT_180052ec4 != 0) && (iVar1 = GRinqiap(), iVar1 != 0)) {
    FUN_180017f80();
  }
  GRseterr(2);
  return 1;
}

/* RVA 0x28530 */
void FUN_180028530(char *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  if ((param_1 != (char *)0x0) && (iVar1 = GRInqIsSbSimYesNoDlgRaised(), iVar1 != 1)) {
    uVar2 = GRinqinmt();
    GRsetinmt(1);
    if (*param_1 != '\0') {
      uVar3 = 0x58;
      if (param_2 != -1) {
        uVar3 = 0x69;
      }
      FUN_180008f80(dbxbuf_exref,"%c%c%s",0x5e,uVar3);
      EXyesno(dbxbuf_exref,2);
    }
    GRsetinmt(uVar2);
  }
  return;
}

/* RVA 0x285d0 */
undefined4 FUN_1800285d0(void *param_1)

{
  if (param_1 == (void *)0x0) {
    _set_errno(9);
    return 0xffffffff;
  }
  if (*(HANDLE *)((longlong)param_1 + 0x480) != (HANDLE)0xffffffffffffffff) {
    FindClose(*(HANDLE *)((longlong)param_1 + 0x480));
  }
  free(*(void **)((longlong)param_1 + 0x488));
  free(param_1);
  return 0;
}

/* RVA 0x28630 */
void * FUN_180028630(LPCWSTR param_1)

{
  short sVar1;
  DWORD DVar2;
  void *pvVar3;
  LPWSTR lpBuffer;
  longlong lVar4;
  undefined4 *puVar5;
  
  if ((param_1 == (LPCWSTR)0x0) || (*param_1 == L'\0')) {
    _set_errno(2);
    return (void *)0x0;
  }
  pvVar3 = malloc(0x490);
  if (pvVar3 == (void *)0x0) {
    return (void *)0x0;
  }
  *(undefined8 *)((longlong)pvVar3 + 0x488) = 0;
  *(undefined4 *)((longlong)pvVar3 + 0x478) = 0;
  *(undefined8 *)((longlong)pvVar3 + 0x480) = 0xffffffffffffffff;
  DVar2 = GetFullPathNameW(param_1,0,(LPWSTR)0x0,(LPWSTR *)0x0);
  lpBuffer = malloc((ulonglong)DVar2 * 2 + 0x10);
  *(LPWSTR *)((longlong)pvVar3 + 0x488) = lpBuffer;
  if ((lpBuffer != (LPWSTR)0x0) &&
     (DVar2 = GetFullPathNameW(param_1,DVar2,lpBuffer,(LPWSTR *)0x0), DVar2 != 0)) {
    puVar5 = (undefined4 *)(*(longlong *)((longlong)pvVar3 + 0x488) + (ulonglong)DVar2 * 2);
    sVar1 = *(short *)(*(longlong *)((longlong)pvVar3 + 0x488) + -2 + (ulonglong)DVar2 * 2);
    if ((sVar1 != 0x2f) && ((sVar1 != 0x3a && (sVar1 != 0x5c)))) {
      *(undefined2 *)puVar5 = 0x5c;
      puVar5 = (undefined4 *)((longlong)puVar5 + 2);
    }
    *puVar5 = 0x2a;
    lVar4 = FUN_1800287b0((longlong)pvVar3);
    if (lVar4 != 0) {
      return pvVar3;
    }
  }
  FUN_1800285d0(pvVar3);
  return (void *)0x0;
}

/* RVA 0x28750 */
undefined4 FUN_180028750(void *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == (void *)0x0) {
    _set_errno(9);
    return 0xffffffff;
  }
  uVar1 = FUN_1800285d0(*(void **)((longlong)param_1 + 0x128));
  *(undefined8 *)((longlong)param_1 + 0x128) = 0;
  free(param_1);
  return uVar1;
}

/* RVA 0x287b0 */
longlong FUN_1800287b0(longlong param_1)

{
  DWORD DVar1;
  HANDLE pvVar2;
  
  if (param_1 == 0) {
    return 0;
  }
  pvVar2 = FindFirstFileExW(*(LPCWSTR *)(param_1 + 0x488),FindExInfoStandard,
                            (LPVOID)(param_1 + 0x228),FindExSearchNameMatch,(LPVOID)0x0,0);
  *(HANDLE *)(param_1 + 0x480) = pvVar2;
  if (pvVar2 != (HANDLE)0xffffffffffffffff) {
    *(undefined4 *)(param_1 + 0x478) = 1;
    return param_1 + 0x228;
  }
  *(undefined4 *)(param_1 + 0x478) = 0;
  DVar1 = GetLastError();
  if (DVar1 != 3) {
    if (DVar1 == 5) {
      _set_errno(0xd);
      return 0;
    }
    if (DVar1 == 0x10b) {
      _set_errno(0x14);
      return 0;
    }
  }
  _set_errno(2);
  return 0;
}

/* RVA 0x28890 */
longlong FUN_180028890(longlong param_1)

{
  BOOL BVar1;
  
  if (*(int *)(param_1 + 0x478) != 0) {
    *(undefined4 *)(param_1 + 0x478) = 0;
    return param_1 + 0x228;
  }
  if (*(HANDLE *)(param_1 + 0x480) == (HANDLE)0xffffffffffffffff) {
    return 0;
  }
  BVar1 = FindNextFileW(*(HANDLE *)(param_1 + 0x480),(LPWIN32_FIND_DATAW)(param_1 + 0x228));
  if (BVar1 == 0) {
    FindClose(*(HANDLE *)(param_1 + 0x480));
    *(undefined8 *)(param_1 + 0x480) = 0xffffffffffffffff;
    return 0;
  }
  return param_1 + 0x228;
}

/* RVA 0x28920 */
void FUN_180028920(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res18 = param_3;
  local_res20 = param_4;
  puVar1 = (undefined8 *)FUN_180001b20();
  __stdio_common_vfprintf(*puVar1,param_1,param_2,0,&local_res18);
  return;
}

/* RVA 0x28970 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void * FUN_180028970(char *param_1)

{
  errno_t eVar1;
  void *_Memory;
  void *pvVar2;
  undefined1 auStackY_268 [32];
  size_t local_238 [2];
  wchar_t local_228 [264];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStackY_268;
  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {
    _set_errno(2);
  }
  else {
    _Memory = malloc(0x130);
    if (_Memory != (void *)0x0) {
      eVar1 = mbstowcs_s(local_238,local_228,0x105,param_1,0x105);
      if (eVar1 == 0) {
        pvVar2 = FUN_180028630(local_228);
        *(void **)((longlong)_Memory + 0x128) = pvVar2;
        if (pvVar2 != (void *)0x0) {
          return _Memory;
        }
      }
      free(_Memory);
    }
  }
  return (void *)0x0;
}

/* RVA 0x28a40 */
undefined8 FUN_180028a40(longlong param_1)

{
  undefined8 local_res8 [4];
  
  FUN_180028a60(param_1,(undefined4 *)param_1,local_res8);
  return local_res8[0];
}

/* RVA 0x28a60 */
undefined8 FUN_180028a60(longlong param_1,undefined4 *param_2,undefined8 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint *puVar3;
  undefined2 uVar4;
  size_t local_res8;
  
  puVar3 = (uint *)FUN_180028890(*(longlong *)(param_1 + 0x128));
  if (puVar3 == (uint *)0x0) {
    *param_3 = 0;
    return 0;
  }
  iVar1 = wcstombs_s(&local_res8,(char *)(param_2 + 7),0x105,(wchar_t *)(puVar3 + 0xb),0x105);
  if (iVar1 != 0) {
    if (*(wchar_t *)(puVar3 + 0x8d) != L'\0') {
      iVar1 = wcstombs_s(&local_res8,(char *)(param_2 + 7),0x105,(wchar_t *)(puVar3 + 0x8d),0x105);
    }
    if (iVar1 != 0) {
      *(undefined2 *)(param_2 + 7) = 0x3f;
      param_2[6] = 0;
      uVar4 = 0;
      *(undefined8 *)(param_2 + 4) = 1;
      uVar2 = 0xffffffff;
      goto LAB_180028b53;
    }
  }
  *(size_t *)(param_2 + 4) = local_res8 - 1;
  if ((*puVar3 & 0x40) == 0) {
    uVar2 = 0x8000;
    if ((*puVar3 & 0x10) != 0) {
      uVar2 = 0x4000;
    }
    uVar4 = 0x128;
    param_2[6] = uVar2;
    uVar2 = 0;
  }
  else {
    uVar2 = 0;
    param_2[6] = 0x2000;
    uVar4 = 0x128;
  }
LAB_180028b53:
  *param_2 = 0;
  param_2[1] = uVar2;
  *(undefined2 *)(param_2 + 2) = uVar4;
  *param_3 = param_2;
  return 0;
}

/* RVA 0x28b80 */
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
  puVar2 = (undefined8 *)FUN_180001b30();
  iVar1 = __stdio_common_vsscanf(*puVar2,_Src,0xffffffffffffffff,_Format,0,&local_res18);
  return iVar1;
}

/* RVA 0x28be0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_180028be0(char *param_1,undefined8 param_2,longlong param_3,undefined8 param_4)

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
  longlong local_9c8;
  char *local_9c0;
  undefined8 local_9b8;
  undefined8 local_9b0;
  uint local_9a8 [2];
  undefined1 local_9a0 [8];
  char local_998 [9];
  undefined1 local_98f [262];
  undefined4 uStack_889;
  undefined1 local_884 [524];
  undefined1 local_678 [272];
  char local_568 [272];
  char local_458 [272];
  char local_348 [256];
  char local_248 [528];
  ulonglong local_38;
  
  local_38 = DAT_1800516d8 ^ (ulonglong)auStack_9e8;
  uVar19 = 0xffffffff;
  local_9a8[0] = 0xffffffff;
  if (DAT_180052cd4 == 10) {
    uVar6 = GetSorResStringEx(0xd10);
    local_9c8 = GetSorResStringEx(0xd0f);
    param_4 = 0x21;
    local_9c0 = (char *)CONCAT44(local_9c0._4_4_,10);
    local_9b8 = uVar6;
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
    local_9c8 = GetSorResStringEx(0xd12);
    param_4 = 0x21;
    local_9c0 = param_1;
    local_9b8 = uVar6;
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
        local_9c8 = GetSorResStringEx(0xd14);
        param_4 = 0x58;
        local_9c0 = param_1;
        local_9b8 = uVar8;
        local_9b0 = uVar6;
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
        pcVar20[(longlong)(local_98f + (0x107 - (longlong)param_1))] = cVar1;
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
        pcVar20[(longlong)(local_98f + (0x107 - (longlong)param_1))] = cVar1;
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
      pcVar20 = _getcwd(local_458,0x104);
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
      local_458[0] = '\0';
      *(uint *)(Sactions_exref + 4) = *(uint *)(Sactions_exref + 4) | 0x80;
      iVar4 = dump_input((longlong)&uStack_889 + 1,0);
      if (iVar4 == -1) goto LAB_180029797;
    }
    CUsethvr(&DAT_18004228c,param_1,lvars_exref,0x400);
    CUsubhvr(lvars_exref,local_998,xprtdata_exref + 0x200,0);
    CUusthvr(&DAT_18004228c,lvars_exref,0x400);
    if (*(int *)(*(longlong *)SBdataptr_exref + 0xc) != 0) {
      puVar13 = (undefined2 *)(local_9a0 + 7);
      do {
        pcVar20 = (char *)((longlong)puVar13 + 1);
        puVar13 = (undefined2 *)((longlong)puVar13 + 1);
      } while (*pcVar20 != '\0');
      *puVar13 = DAT_18003f9bc;
      pcVar20 = local_9a0 + 7;
      do {
        pcVar7 = pcVar20;
        pcVar20 = pcVar7 + 1;
      } while (pcVar7[1] != '\0');
      *(undefined8 *)(pcVar7 + 1) = s__getridof__mm_180042968._0_8_;
      *(undefined4 *)(pcVar7 + 9) = s__getridof__mm_180042968._8_4_;
      *(undefined2 *)(pcVar7 + 0xd) = s__getridof__mm_180042968._12_2_;
    }
    puVar13 = (undefined2 *)(local_9a0 + 7);
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
    } while (local_998[lVar3] != '\0');
    uVar6 = FUN_180029800((int)lVar14 + (int)lVar9,(longlong)local_348,local_998,
                          *(longlong *)SBdataptr_exref + 0xb10);
    if ((int)uVar6 != -1) {
      if ((int)uVar6 == 1) {
        puVar15 = local_9a0 + 7;
        do {
          pcVar20 = puVar15 + 1;
          puVar15 = puVar15 + 1;
        } while (*pcVar20 != '\0');
        lVar14 = 0;
        do {
          cVar1 = local_348[lVar14];
          puVar15[lVar14] = cVar1;
          lVar14 = lVar14 + 1;
        } while (cVar1 != '\0');
      }
      puVar15 = local_9a0 + 7;
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
      FUN_180008f80(local_678,&DAT_18003f9b0,(longlong)&uStack_889 + 1,local_98f);
      uVar11 = FUN_180028100(local_678,*(undefined4 *)(xprtdata_exref + 0x934));
      uVar19 = uVar11 & 0xffffffff;
      if (local_458[0] != '\0') {
        _chdir(local_458);
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
      FUN_180034540(local_458);
      FUN_180033fc0((char *)(*(longlong *)SBdataptr_exref + 0x110),lVar14,param_3,param_4);
    }
    pcVar20 = param_1;
    do {
      cVar1 = *pcVar20;
      pcVar20[(longlong)(local_98f + (0x107 - (longlong)param_1))] = cVar1;
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
      CUsubhvr(lvars_exref,local_998,xprtdata_exref + 0x200,0);
      CUusthvr(&DAT_18004228c,lvars_exref,0x400);
      if (*(int *)(*(longlong *)SBdataptr_exref + 0xc) != 0) {
        puVar13 = (undefined2 *)(local_9a0 + 7);
        do {
          pcVar20 = (char *)((longlong)puVar13 + 1);
          puVar13 = (undefined2 *)((longlong)puVar13 + 1);
        } while (*pcVar20 != '\0');
        *puVar13 = DAT_18003f9bc;
        pcVar20 = local_9a0 + 7;
        do {
          pcVar7 = pcVar20;
          pcVar20 = pcVar7 + 1;
        } while (pcVar7[1] != '\0');
        *(undefined8 *)(pcVar7 + 1) = s__getridof__mm_180042968._0_8_;
        *(undefined4 *)(pcVar7 + 9) = s__getridof__mm_180042968._8_4_;
        *(undefined2 *)(pcVar7 + 0xd) = s__getridof__mm_180042968._12_2_;
      }
      puVar13 = (undefined2 *)(local_9a0 + 7);
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
      } while (local_998[lVar3] != '\0');
      uVar6 = FUN_180029800((int)lVar14 + (int)lVar9,(longlong)local_348,local_998,
                            *(longlong *)SBdataptr_exref + 0xb10);
      if ((int)uVar6 != -1) {
        if ((int)uVar6 == 1) {
          puVar15 = local_9a0 + 7;
          do {
            pcVar20 = puVar15 + 1;
            puVar15 = puVar15 + 1;
          } while (*pcVar20 != '\0');
          lVar14 = 0;
          do {
            cVar1 = local_348[lVar14];
            puVar15[lVar14] = cVar1;
            lVar14 = lVar14 + 1;
          } while (cVar1 != '\0');
        }
        if (*(int *)(*(longlong *)SBdataptr_exref + 0x1218) == 1) {
          local_9a0 = (undefined1  [8])((longlong)&uStack_889 + 1);
          lVar14 = 0;
          do {
            cVar1 = local_998[lVar14];
            local_98f[lVar14 + 0x107] = cVar1;
            lVar14 = lVar14 + 1;
          } while (cVar1 != '\0');
          SFgetstr(local_9a0,local_248,0x208);
          local_9a8[0] = 0;
          iVar4 = FUN_1800269c0(local_248,local_568);
          if (iVar4 == 0) {
            pcVar20 = local_568;
            pcVar7 = "%s %s %s";
            auVar17 = local_9a0;
          }
          else {
            uVar6 = FUN_180026fe0(local_568,(int *)local_9a8);
            if (((int)uVar6 != 0) || (local_9a8[0] != 0)) goto LAB_180029658;
            FUN_180026740(local_568,"xeq",local_248,1);
            pcVar20 = local_248;
            pcVar7 = "%s\\%s %s";
            auVar17 = (undefined1  [8])local_998;
          }
          local_9c8 = *(longlong *)SBdataptr_exref + 0xb10;
          FUN_180008f80(local_678,pcVar7,pcVar20,auVar17);
          SFfmtnstr(local_678,0x101,local_998);
          if (local_9a8[0] != 0) goto LAB_180029658;
          local_9c0 = (char *)0x0;
          local_9c8 = CONCAT44(local_9c8._4_4_,*(undefined4 *)(xprtdata_exref + 0x934));
          FUN_180008f80((longlong)&uStack_889 + 1,"%s \"%s\" %d %d","SPAWN",local_998);
        }
        else {
          local_9c8 = *(longlong *)SBdataptr_exref + 0xb10;
          local_9b8 = 0;
          local_9c0 = (char *)CONCAT44(local_9c0._4_4_,*(undefined4 *)(xprtdata_exref + 0x934));
          FUN_180008f80((longlong)&uStack_889 + 1,"%s \"%s %s\" %d %d","SPAWN",local_998);
        }
        lVar14 = 0;
        do {
          cVar1 = local_98f[lVar14 + 0x107];
          local_998[lVar14] = cVar1;
          lVar14 = lVar14 + 1;
        } while (cVar1 != '\0');
        puVar18 = local_9a8;
        pcVar20 = local_568;
        pcVar7 = local_998;
        local_9c8 = CONCAT44(local_9c8._4_4_,*(undefined4 *)(*(longlong *)SBdataptr_exref + 0x1220))
        ;
        iVar4 = REMOTE_COMMAND(*(undefined4 *)(*(longlong *)SBdataptr_exref + 0x146c));
        if ((iVar4 == 0) && (local_9a8[0] == 0)) {
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
  return (ulonglong)local_9a8[0];
}

/* RVA 0x297f0 */
bool FUN_1800297f0(void)

{
  return DAT_180050db4 == 0;
}

/* RVA 0x29800 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180029800(int param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  char *pcVar6;
  undefined2 *puVar7;
  longlong lVar9;
  longlong lVar8;
  undefined4 *puVar10;
  undefined4 *puVar11;
  char *pcVar12;
  undefined1 *puVar13;
  longlong lVar14;
  undefined1 auStack_878 [32];
  undefined8 local_858;
  undefined8 local_850;
  undefined2 *local_848;
  longlong local_840;
  undefined2 *local_838;
  undefined8 local_830;
  undefined8 local_828;
  undefined1 local_820 [7];
  undefined4 uStack_819;
  char acStack_812 [41];
  undefined1 local_7e9;
  undefined1 local_428 [2];
  char local_426 [1006];
  ulonglong local_38;
  
  local_38 = DAT_1800516d8 ^ (ulonglong)auStack_878;
  bVar2 = false;
  uStack_819._1_2_ = 0x20;
  if (submitdata_exref[0x210] != (code)0x0) {
    bVar2 = true;
    puVar10 = (undefined4 *)(local_820 + 7);
    do {
      puVar11 = puVar10;
      puVar10 = (undefined4 *)((longlong)puVar11 + 1);
    } while (*(char *)((longlong)puVar11 + 1) != '\0');
    *(undefined4 *)((longlong)puVar11 + 1) = DAT_1800429c4;
    *(undefined2 *)((longlong)puVar11 + 5) = DAT_1800429c8;
    *(undefined1 *)((longlong)puVar11 + 7) = DAT_1800429ca;
    lVar9 = *(longlong *)SBdataptr_exref;
    puVar13 = local_820 + 7;
    do {
      pcVar6 = puVar13 + 1;
      puVar13 = puVar13 + 1;
    } while (*pcVar6 != '\0');
    lVar14 = 0;
    do {
      cVar1 = *(char *)(lVar9 + 0x210 + lVar14);
      puVar13[lVar14] = cVar1;
      lVar14 = lVar14 + 1;
    } while (cVar1 != '\0');
    puVar7 = (undefined2 *)(local_820 + 7);
    do {
      pcVar6 = (char *)((longlong)puVar7 + 1);
      puVar7 = (undefined2 *)((longlong)puVar7 + 1);
    } while (*pcVar6 != '\0');
    *puVar7 = DAT_18003f9bc;
  }
  if (submitdata_exref[0x310] != (code)0x0) {
    bVar2 = true;
    puVar10 = (undefined4 *)(local_820 + 7);
    do {
      puVar11 = puVar10;
      puVar10 = (undefined4 *)((longlong)puVar11 + 1);
    } while (*(char *)((longlong)puVar11 + 1) != '\0');
    *(undefined4 *)((longlong)puVar11 + 1) = DAT_1800429cc;
    *(undefined2 *)((longlong)puVar11 + 5) = DAT_1800429d0;
    *(undefined1 *)((longlong)puVar11 + 7) = DAT_1800429d2;
    lVar9 = *(longlong *)SBdataptr_exref;
    puVar13 = local_820 + 7;
    do {
      pcVar6 = puVar13 + 1;
      puVar13 = puVar13 + 1;
    } while (*pcVar6 != '\0');
    lVar14 = 0;
    do {
      cVar1 = *(char *)(lVar9 + 0x310 + lVar14);
      puVar13[lVar14] = cVar1;
      lVar14 = lVar14 + 1;
    } while (cVar1 != '\0');
    puVar7 = (undefined2 *)(local_820 + 7);
    do {
      pcVar6 = (char *)((longlong)puVar7 + 1);
      puVar7 = (undefined2 *)((longlong)puVar7 + 1);
    } while (*pcVar6 != '\0');
    *puVar7 = DAT_18003f9bc;
  }
  if (submitdata_exref[0x410] != (code)0x0) {
    bVar2 = true;
    puVar10 = (undefined4 *)(local_820 + 7);
    do {
      puVar11 = puVar10;
      puVar10 = (undefined4 *)((longlong)puVar11 + 1);
    } while (*(char *)((longlong)puVar11 + 1) != '\0');
    *(undefined4 *)((longlong)puVar11 + 1) = DAT_1800429d4;
    *(undefined2 *)((longlong)puVar11 + 5) = DAT_1800429d8;
    *(undefined1 *)((longlong)puVar11 + 7) = DAT_1800429da;
    lVar9 = *(longlong *)SBdataptr_exref;
    puVar13 = local_820 + 7;
    do {
      pcVar6 = puVar13 + 1;
      puVar13 = puVar13 + 1;
    } while (*pcVar6 != '\0');
    lVar14 = 0;
    do {
      cVar1 = *(char *)(lVar9 + 0x410 + lVar14);
      puVar13[lVar14] = cVar1;
      lVar14 = lVar14 + 1;
    } while (cVar1 != '\0');
    puVar7 = (undefined2 *)(local_820 + 7);
    do {
      pcVar6 = (char *)((longlong)puVar7 + 1);
      puVar7 = (undefined2 *)((longlong)puVar7 + 1);
    } while (*pcVar6 != '\0');
    *puVar7 = DAT_18003f9bc;
  }
  if (submitdata_exref[0x510] != (code)0x0) {
    bVar2 = true;
    puVar10 = (undefined4 *)(local_820 + 7);
    do {
      puVar11 = puVar10;
      puVar10 = (undefined4 *)((longlong)puVar11 + 1);
    } while (*(char *)((longlong)puVar11 + 1) != '\0');
    *(undefined4 *)((longlong)puVar11 + 1) = DAT_1800429dc;
    *(undefined2 *)((longlong)puVar11 + 5) = DAT_1800429e0;
    *(undefined1 *)((longlong)puVar11 + 7) = DAT_1800429e2;
    lVar9 = *(longlong *)SBdataptr_exref;
    puVar13 = local_820 + 7;
    do {
      pcVar6 = puVar13 + 1;
      puVar13 = puVar13 + 1;
    } while (*pcVar6 != '\0');
    lVar14 = 0;
    do {
      cVar1 = *(char *)(lVar9 + 0x510 + lVar14);
      puVar13[lVar14] = cVar1;
      lVar14 = lVar14 + 1;
    } while (cVar1 != '\0');
    puVar7 = (undefined2 *)(local_820 + 7);
    do {
      pcVar6 = (char *)((longlong)puVar7 + 1);
      puVar7 = (undefined2 *)((longlong)puVar7 + 1);
    } while (*pcVar6 != '\0');
    *puVar7 = DAT_18003f9bc;
  }
  if (submitdata_exref[0x610] != (code)0x0) {
    bVar2 = true;
    puVar10 = (undefined4 *)(local_820 + 7);
    do {
      puVar11 = puVar10;
      puVar10 = (undefined4 *)((longlong)puVar11 + 1);
    } while (*(char *)((longlong)puVar11 + 1) != '\0');
    *(undefined4 *)((longlong)puVar11 + 1) = DAT_1800429e4;
    *(undefined2 *)((longlong)puVar11 + 5) = DAT_1800429e8;
    *(undefined1 *)((longlong)puVar11 + 7) = DAT_1800429ea;
    lVar9 = *(longlong *)SBdataptr_exref;
    puVar13 = local_820 + 7;
    do {
      pcVar6 = puVar13 + 1;
      puVar13 = puVar13 + 1;
    } while (*pcVar6 != '\0');
    lVar14 = 0;
    do {
      cVar1 = *(char *)(lVar9 + 0x610 + lVar14);
      puVar13[lVar14] = cVar1;
      lVar14 = lVar14 + 1;
    } while (cVar1 != '\0');
    puVar7 = (undefined2 *)(local_820 + 7);
    do {
      pcVar6 = (char *)((longlong)puVar7 + 1);
      puVar7 = (undefined2 *)((longlong)puVar7 + 1);
    } while (*pcVar6 != '\0');
    *puVar7 = DAT_18003f9bc;
  }
  if (submitdata_exref[0x1474] != (code)0x0) {
    bVar2 = true;
    pcVar6 = local_820 + 7;
    do {
      pcVar12 = *(char (*) [8])pcVar6;
      pcVar6 = *(char (*) [8])pcVar6 + 1;
    } while (pcVar12[1] != '\0');
    *(char (*) [8])pcVar6 = s__dlopt__1800429f0;
    puVar13 = local_820 + 7;
    lVar9 = *(longlong *)SBdataptr_exref;
    do {
      pcVar6 = puVar13 + 1;
      puVar13 = puVar13 + 1;
    } while (*pcVar6 != '\0');
    lVar14 = 0;
    do {
      cVar1 = *(char *)(lVar9 + 0x1474 + lVar14);
      puVar13[lVar14] = cVar1;
      lVar14 = lVar14 + 1;
    } while (cVar1 != '\0');
    puVar7 = (undefined2 *)(local_820 + 7);
    do {
      pcVar6 = (char *)((longlong)puVar7 + 1);
      puVar7 = (undefined2 *)((longlong)puVar7 + 1);
    } while (*pcVar6 != '\0');
    *puVar7 = DAT_18003f9bc;
  }
  if (submitdata_exref[0x910] != (code)0x0) {
    bVar2 = true;
    pcVar6 = local_820 + 7;
    do {
      pcVar12 = *(char (*) [8])pcVar6;
      pcVar6 = *(char (*) [8])pcVar6 + 1;
    } while (pcVar12[1] != '\0');
    *(char (*) [8])pcVar6 = s__ucost__1800429f8;
    puVar13 = local_820 + 7;
    lVar9 = *(longlong *)SBdataptr_exref;
    do {
      pcVar6 = puVar13 + 1;
      puVar13 = puVar13 + 1;
    } while (*pcVar6 != '\0');
    lVar14 = 0;
    do {
      cVar1 = *(char *)(lVar9 + 0x910 + lVar14);
      puVar13[lVar14] = cVar1;
      lVar14 = lVar14 + 1;
    } while (cVar1 != '\0');
    puVar7 = (undefined2 *)(local_820 + 7);
    do {
      pcVar6 = (char *)((longlong)puVar7 + 1);
      puVar7 = (undefined2 *)((longlong)puVar7 + 1);
    } while (*pcVar6 != '\0');
    *puVar7 = DAT_18003f9bc;
  }
  if (submitdata_exref[0x810] != (code)0x0) {
    bVar2 = true;
    pcVar6 = local_820 + 7;
    do {
      pcVar12 = pcVar6;
      pcVar6 = pcVar12 + 1;
    } while (pcVar12[1] != '\0');
    *(undefined8 *)(pcVar12 + 1) = s__strlib__180042a00._0_8_;
    pcVar12[9] = s__strlib__180042a00[8];
    lVar9 = *(longlong *)SBdataptr_exref;
    puVar13 = local_820 + 7;
    do {
      pcVar6 = puVar13 + 1;
      puVar13 = puVar13 + 1;
    } while (*pcVar6 != '\0');
    lVar14 = 0;
    do {
      cVar1 = *(char *)(lVar9 + 0x810 + lVar14);
      puVar13[lVar14] = cVar1;
      lVar14 = lVar14 + 1;
    } while (cVar1 != '\0');
    puVar7 = (undefined2 *)(local_820 + 7);
    do {
      pcVar6 = (char *)((longlong)puVar7 + 1);
      puVar7 = (undefined2 *)((longlong)puVar7 + 1);
    } while (*pcVar6 != '\0');
    *puVar7 = DAT_18003f9bc;
  }
  if (submitdata_exref[0xa10] != (code)0x0) {
    bVar2 = true;
    pcVar6 = local_820 + 7;
    do {
      pcVar12 = pcVar6;
      pcVar6 = pcVar12 + 1;
    } while (pcVar12[1] != '\0');
    *(undefined8 *)(pcVar12 + 1) = s__default__180042a10._0_8_;
    *(undefined2 *)(pcVar12 + 9) = s__default__180042a10._8_2_;
    lVar9 = *(longlong *)SBdataptr_exref;
    puVar13 = local_820 + 7;
    do {
      pcVar6 = puVar13 + 1;
      puVar13 = puVar13 + 1;
    } while (*pcVar6 != '\0');
    lVar14 = 0;
    do {
      cVar1 = *(char *)(lVar9 + 0xa10 + lVar14);
      puVar13[lVar14] = cVar1;
      lVar14 = lVar14 + 1;
    } while (cVar1 != '\0');
    puVar7 = (undefined2 *)(local_820 + 7);
    do {
      pcVar6 = (char *)((longlong)puVar7 + 1);
      puVar7 = (undefined2 *)((longlong)puVar7 + 1);
    } while (*pcVar6 != '\0');
    *puVar7 = DAT_18003f9bc;
  }
  if (submitdata_exref[0x710] == (code)0x0) {
    if (!bVar2) {
      return 0;
    }
  }
  else {
    pcVar6 = local_820 + 7;
    do {
      pcVar12 = pcVar6;
      pcVar6 = pcVar12 + 1;
    } while (pcVar12[1] != '\0');
    *(undefined8 *)(pcVar12 + 1) = s__insert__180042a20._0_8_;
    pcVar12[9] = s__insert__180042a20[8];
    lVar9 = *(longlong *)SBdataptr_exref;
    puVar13 = local_820 + 7;
    do {
      pcVar6 = puVar13 + 1;
      puVar13 = puVar13 + 1;
    } while (*pcVar6 != '\0');
    lVar14 = 0;
    do {
      cVar1 = *(char *)(lVar9 + 0x710 + lVar14);
      puVar13[lVar14] = cVar1;
      lVar14 = lVar14 + 1;
    } while (cVar1 != '\0');
    puVar7 = (undefined2 *)(local_820 + 7);
    do {
      pcVar6 = (char *)((longlong)puVar7 + 1);
      puVar7 = (undefined2 *)((longlong)puVar7 + 1);
    } while (*pcVar6 != '\0');
    *puVar7 = DAT_18003f9bc;
  }
  lVar9 = -1;
  do {
    lVar8 = lVar9 + 1;
    lVar14 = lVar9 + 9;
    lVar9 = lVar8;
  } while (local_820[lVar14] != '\0');
  local_850 = param_3;
  local_830 = param_4;
  if ((ulonglong)(lVar8 + param_1) < 0xff) {
    uVar4 = GetSorResStringEx(0xd22);
    uVar5 = GetSorResStringEx(0xd21);
    local_858 = GetSorResStringEx(0xd20);
    local_840 = (longlong)&uStack_819 + 1;
    local_838 = &DAT_18003f9bc;
    local_848 = &DAT_18003f9bc;
    local_828 = uVar5;
    _local_820 = uVar4;
    FUN_180008f80(local_428,"%c%c%s%s%s%s%s%s%s%s",0x5e,0x58);
    uVar4 = FUN_180006fc0('q',local_426,"OKCANCEL",0);
    iVar3 = (int)uVar4;
  }
  else {
    local_7e9 = 0;
    puVar10 = (undefined4 *)(local_820 + 7);
    do {
      pcVar6 = (char *)((longlong)puVar10 + 1);
      puVar10 = (undefined4 *)((longlong)puVar10 + 1);
    } while (*pcVar6 != '\0');
    *puVar10 = DAT_180042a2c;
    uVar4 = GetSorResStringEx(0xd1f);
    local_858 = GetSorResStringEx(0xd1e);
    local_840 = (longlong)&uStack_819 + 1;
    local_838 = &DAT_18003f9bc;
    local_848 = &DAT_18003f9bc;
    local_828 = uVar4;
    FUN_180008f80(dbxbuf_exref,"%c%c%s%s%s%s%s%s%s",0x5e,0x58);
    iVar3 = EXyesno(dbxbuf_exref,2,1);
  }
  if (iVar3 == 1) {
    uVar4 = 0xffffffff;
  }
  else {
    pcVar6 = (char *)((longlong)&uStack_819 + 1);
    do {
      cVar1 = *pcVar6;
      pcVar6[param_2 - ((longlong)&uStack_819 + 1)] = cVar1;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    uVar4 = 1;
  }
  s__dlopt__1800429f0[0] = s__dlopt__1800429f0[0];
  s__dlopt__1800429f0[1] = s__dlopt__1800429f0[1];
  s__dlopt__1800429f0[2] = s__dlopt__1800429f0[2];
  s__dlopt__1800429f0[3] = s__dlopt__1800429f0[3];
  s__dlopt__1800429f0[4] = s__dlopt__1800429f0[4];
  s__dlopt__1800429f0[5] = s__dlopt__1800429f0[5];
  s__dlopt__1800429f0[6] = s__dlopt__1800429f0[6];
  s__dlopt__1800429f0[7] = s__dlopt__1800429f0[7];
  s__ucost__1800429f8[0] = s__ucost__1800429f8[0];
  s__ucost__1800429f8[1] = s__ucost__1800429f8[1];
  s__ucost__1800429f8[2] = s__ucost__1800429f8[2];
  s__ucost__1800429f8[3] = s__ucost__1800429f8[3];
  s__ucost__1800429f8[4] = s__ucost__1800429f8[4];
  s__ucost__1800429f8[5] = s__ucost__1800429f8[5];
  s__ucost__1800429f8[6] = s__ucost__1800429f8[6];
  s__ucost__1800429f8[7] = s__ucost__1800429f8[7];
  s__strlib__180042a00[0] = s__strlib__180042a00[0];
  s__strlib__180042a00[1] = s__strlib__180042a00[1];
  s__strlib__180042a00[2] = s__strlib__180042a00[2];
  s__strlib__180042a00[3] = s__strlib__180042a00[3];
  s__strlib__180042a00[4] = s__strlib__180042a00[4];
  s__strlib__180042a00[5] = s__strlib__180042a00[5];
  s__strlib__180042a00[6] = s__strlib__180042a00[6];
  s__strlib__180042a00[7] = s__strlib__180042a00[7];
  s__default__180042a10[0] = s__default__180042a10[0];
  s__default__180042a10[1] = s__default__180042a10[1];
  s__default__180042a10[2] = s__default__180042a10[2];
  s__default__180042a10[3] = s__default__180042a10[3];
  s__default__180042a10[4] = s__default__180042a10[4];
  s__default__180042a10[5] = s__default__180042a10[5];
  s__default__180042a10[6] = s__default__180042a10[6];
  s__default__180042a10[7] = s__default__180042a10[7];
  s__default__180042a10[8] = s__default__180042a10[8];
  s__default__180042a10[9] = s__default__180042a10[9];
  s__insert__180042a20[0] = s__insert__180042a20[0];
  s__insert__180042a20[1] = s__insert__180042a20[1];
  s__insert__180042a20[2] = s__insert__180042a20[2];
  s__insert__180042a20[3] = s__insert__180042a20[3];
  s__insert__180042a20[4] = s__insert__180042a20[4];
  s__insert__180042a20[5] = s__insert__180042a20[5];
  s__insert__180042a20[6] = s__insert__180042a20[6];
  s__insert__180042a20[7] = s__insert__180042a20[7];
  return uVar4;
}

/* RVA 0x29f50 */
void FUN_180029f50(int param_1)

{
  if (param_1 == 0) {
    _guard_check_icall();
    return;
  }
  _guard_check_icall();
  _guard_check_icall();
  _guard_check_icall();
  return;
}

/* RVA 0x29f80 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_180029f80(char *param_1)

{
  char *pcVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  undefined7 extraout_var;
  undefined1 *puVar6;
  undefined2 *puVar7;
  longlong lVar8;
  undefined1 auStack_388 [32];
  undefined4 local_368;
  int local_358 [2];
  undefined1 local_350 [8];
  char local_348 [272];
  char local_238 [272];
  undefined1 local_128 [272];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_388;
  iVar4 = SBlocalhost();
  if (iVar4 == 0) {
    iVar4 = -1;
    local_358[0] = -1;
    SFfmtnstr(param_1,0x101,local_238);
    builtin_strncpy(local_348,"SPAWN \"",8);
    puVar6 = local_350 + 7;
    do {
      pcVar1 = puVar6 + 1;
      puVar6 = puVar6 + 1;
    } while (*pcVar1 != '\0');
    lVar8 = 0;
    do {
      cVar2 = local_238[lVar8];
      puVar6[lVar8] = cVar2;
      lVar8 = lVar8 + 1;
    } while (cVar2 != '\0');
    puVar7 = (undefined2 *)(local_350 + 7);
    do {
      pcVar1 = (char *)((longlong)puVar7 + 1);
      puVar7 = (undefined2 *)((longlong)puVar7 + 1);
    } while (*pcVar1 != '\0');
    *puVar7 = DAT_1800426a4;
    local_368 = *(undefined4 *)(*(longlong *)SBdataptr_exref + 0x1220);
    iVar5 = REMOTE_COMMAND(*(undefined4 *)(*(longlong *)SBdataptr_exref + 0x146c),local_348,
                           local_128,local_358);
    if ((iVar5 == 0) && (local_358[0] == 0)) {
      local_350 = (undefined1  [8])local_348;
      lVar8 = -(longlong)param_1;
      do {
        cVar2 = *param_1;
        param_1[(longlong)(local_348 + lVar8)] = cVar2;
        param_1 = param_1 + 1;
      } while (cVar2 != '\0');
      SFgetstr(local_350,local_238,0x101);
      SFgetstr(local_350,local_238,0x101);
      SFgetstr(local_350,local_238,0x101);
      iVar5 = FUN_180026510((char *)0x0,local_238);
      if ((iVar5 == 0) && (local_358[0] == 0)) {
        iVar4 = 0;
      }
    }
  }
  else {
    bVar3 = FUN_180008b50(param_1);
    iVar4 = ((int)CONCAT71(extraout_var,bVar3) != 0) - 1;
  }
  return iVar4;
}

/* RVA 0x2a150 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18002a150(void)

{
  char cVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  char *pcVar4;
  char *pcVar5;
  longlong lVar6;
  undefined1 auStack_388 [32];
  char *local_368;
  char local_358 [32];
  char local_338 [32];
  char local_318 [256];
  char local_218 [256];
  char local_118 [256];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_388;
  memset(&DAT_180052220,0,0xab8);
  lVar6 = *(longlong *)SBdataptr_exref;
  if (*(int *)(lVar6 + 0x1214) == 0) {
    *(undefined4 *)(lVar6 + 0x146c) = DAT_180052d78;
    return 0;
  }
  CUsubhvr(lvars_exref,local_218,lVar6 + 0x1224);
  pcVar5 = local_218;
  pcVar4 = (char *)(*(longlong *)SBdataptr_exref + 0x1224);
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    *pcVar4 = cVar1;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  CUsubhvr(lvars_exref,local_338,*(longlong *)SBdataptr_exref + 0x1324);
  pcVar5 = local_338;
  pcVar4 = (char *)(*(longlong *)SBdataptr_exref + 0x1324);
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    *pcVar4 = cVar1;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  CUsubhvr(lvars_exref,local_358,*(longlong *)SBdataptr_exref + 0x1344);
  pcVar5 = local_358;
  pcVar4 = (char *)(*(longlong *)SBdataptr_exref + 0x1344);
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    *pcVar4 = cVar1;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  uVar3 = 0;
  lVar6 = *(longlong *)SBdataptr_exref + 0x1364;
  CUsubhvr(lvars_exref,local_118);
  pcVar5 = local_118;
  pcVar4 = (char *)(*(longlong *)SBdataptr_exref + 0x1364);
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    *pcVar4 = cVar1;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  if (*(int *)debug_flag_exref != 0) {
    uVar2 = GetSorResStringEx(0xd0a);
    FUN_180008f80(local_318,uVar2,lVar6,uVar3);
    FUN_1800282b0(local_318);
    uVar3 = GetSorResStringEx(0xd0b);
    local_368 = local_358;
    FUN_180008f80(local_318,uVar3,local_218,local_338);
    FUN_1800282b0(local_318);
  }
  uVar3 = REMOTE_CONNECT(*(longlong *)SBdataptr_exref + 0x1214,*(longlong *)SBdataptr_exref + 0x146c
                        );
  return uVar3;
}

/* RVA 0x2a3a0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18002a3a0(undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4)

{
  code cVar1;
  code *pcVar2;
  char *pcVar3;
  undefined8 uVar4;
  char *pcVar5;
  undefined1 auStack_48 [31];
  char cStack_29;
  undefined1 local_28 [4];
  char acStack_24 [4];
  char acStack_20 [16];
  ulonglong local_10;
  
  local_10 = DAT_1800516d8 ^ (ulonglong)auStack_48;
  hide_mouse();
  push_mouse_mask(0xd);
  show_mouse();
  pcVar2 = APtmpfil_exref;
  do {
    cVar1 = *pcVar2;
    pcVar2[(longlong)(local_28 + -(longlong)APtmpfil_exref)] = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != (code)0x0);
  pcVar5 = &cStack_29;
  do {
    pcVar3 = pcVar5;
    pcVar5 = pcVar3 + 1;
  } while (pcVar3[1] != '\0');
  *(undefined4 *)(pcVar3 + 1) = DAT_180041718;
  pcVar3[5] = DAT_18004171c;
  FUN_180025fb0((char *)0x0,local_28);
  pcVar2 = APtmpfil_exref;
  do {
    cVar1 = *pcVar2;
    pcVar2[(longlong)(local_28 + -(longlong)APtmpfil_exref)] = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != (code)0x0);
  pcVar5 = &cStack_29;
  do {
    pcVar3 = pcVar5;
    pcVar5 = pcVar3 + 1;
  } while (pcVar3[1] != '\0');
  *(undefined4 *)(pcVar3 + 1) = DAT_180041f50;
  pcVar3[5] = DAT_180041f54;
  FUN_180025fb0((char *)0x0,local_28);
  pcVar2 = APtmpfil_exref;
  do {
    cVar1 = *pcVar2;
    pcVar2[(longlong)(local_28 + -(longlong)APtmpfil_exref)] = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != (code)0x0);
  pcVar5 = &cStack_29;
  do {
    pcVar3 = pcVar5;
    pcVar5 = pcVar3 + 1;
  } while (pcVar3[1] != '\0');
  *(undefined4 *)(pcVar3 + 1) = DAT_180042924;
  pcVar3[5] = DAT_180042928;
  FUN_180025fb0((char *)0x0,local_28);
  pcVar2 = APtmpfil_exref;
  do {
    cVar1 = *pcVar2;
    pcVar2[(longlong)(local_28 + -(longlong)APtmpfil_exref)] = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != (code)0x0);
  pcVar5 = &cStack_29;
  do {
    pcVar3 = pcVar5;
    pcVar5 = pcVar3 + 1;
  } while (pcVar3[1] != '\0');
  pcVar5 = local_28;
  *(undefined8 *)(pcVar3 + 1) = s__ads_txt_180042930._0_8_;
  pcVar3[9] = s__ads_txt_180042930[8];
  uVar4 = 0;
  FUN_180025fb0((char *)0x0,pcVar5);
  FUN_180018ef0(uVar4,pcVar5,param_3,param_4);
  if (*(int *)(submitdata_exref + 0x1214) != 0) {
    REMOTE_DISCONNECT(*(undefined4 *)(*(longlong *)SBdataptr_exref + 0x146c));
  }
  *(undefined4 *)(*(longlong *)SBdataptr_exref + 0x146c) = 0;
  GRsetcnn(0);
  pop_mouse_mask();
  show_mouse();
  return 0;
}

/* RVA 0x2a580 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_18002a580(char *param_1,int param_2,int param_3,LPCSTR param_4)

{
  BOOL BVar1;
  undefined1 auStack_158 [32];
  char local_138 [259];
  undefined1 local_35;
  ulonglong local_28;
  
  local_28 = DAT_1800516d8 ^ (ulonglong)auStack_158;
  strncpy(local_138,param_1,0x103);
  local_35 = 0;
  BVar1 = FUN_180009bc0(local_138,param_2,param_3,param_4);
  return -(uint)(BVar1 != 1);
}

/* RVA 0x2a600 */
void FUN_18002a600(longlong param_1,int *param_2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  
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

/* RVA 0x2a650 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18002a650(char *param_1,longlong param_2)

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
  undefined8 local_368;
  undefined8 local_360;
  char local_358 [15];
  undefined4 uStack_349;
  undefined1 local_344 [267];
  undefined4 uStack_239;
  undefined1 local_234 [524];
  ulonglong local_28;
  
  local_28 = DAT_1800516d8 ^ (ulonglong)auStack_388;
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
      param_1[(longlong)(local_358 + lVar10)] = cVar1;
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
          cVar2 = pcVar4[(longlong)(local_358 + lVar12)];
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
              pcVar4 = local_358 + lVar8;
              local_358[lVar8 + 0x10] = *pcVar4;
              lVar8 = lVar8 + 1;
            } while (*pcVar4 != '\0');
          }
          else {
            iVar11 = *(int *)(*(longlong *)SBdataptr_exref + 0x1218);
            if (iVar11 == 0) {
              FUN_180008f80((longlong)&uStack_349 + 1,&DAT_18003f9b0,pcVar4,local_358);
            }
            else if (iVar11 == 1) {
              FUN_180026740(pcVar4,local_358,(undefined1 *)((longlong)&uStack_349 + 1),1);
            }
            else if (iVar11 == 2) {
              FUN_180008f80((longlong)&uStack_349 + 1,"%s/%s",pcVar4,local_358);
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
              FUN_180008f80((longlong)&uStack_239 + 1,"%s.%s",local_358,&DAT_18004289c);
              iVar11 = *(int *)(*(longlong *)SBdataptr_exref + 0x1218);
              if (iVar11 != 0) {
                if (iVar11 == 1) {
                  if ((&DAT_180052284)[lVar12 * 0x104] != '\0') {
                    FUN_180026740(&DAT_180052284 + lVar12 * 0x104,local_358,
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
                pcVar4 = local_358 + lVar10;
                local_358[lVar10 + 0x10] = *pcVar4;
                lVar10 = lVar10 + 1;
              } while (*pcVar4 != '\0');
              FUN_180008f80((longlong)&uStack_239 + 1,"%s.%s",local_358,&DAT_18004289c);
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
                FUN_180008f80(param_2,"%s %s",uVar5,local_358);
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
      local_368 = uVar6;
      local_360 = uVar5;
      FUN_180008f80(param_2,"%s%s%s%s",uVar7,local_358);
    }
  }
  return 0xffffffff;
}

/* RVA 0x2ab60 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18002ab60(char *param_1)

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
  undefined8 local_498;
  char *local_490;
  undefined8 local_488;
  undefined8 local_480;
  char local_478 [271];
  undefined1 uStack_369;
  char local_368 [271];
  undefined1 local_259;
  char local_258 [272];
  char local_148 [272];
  ulonglong local_38;
  
  local_38 = DAT_1800516d8 ^ (ulonglong)auStack_4b8;
  if (*param_1 == '\0') {
    local_498 = GetSorResStringEx(0xce4);
    FUN_180008f80(dbxbuf_exref,"%c%c%s",0x5e,0x58);
    iVar6 = EXyesno(dbxbuf_exref,2,1);
    if (iVar6 == 1) {
      return 0xffffffff;
    }
  }
  lVar13 = -(longlong)param_1;
  do {
    cVar2 = *param_1;
    param_1[(longlong)(local_478 + lVar13)] = cVar2;
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
        cVar3 = pcVar8[(longlong)(local_478 + lVar15)];
        if (cVar2 != cVar3) break;
        pcVar8 = pcVar8 + 1;
      } while (cVar3 != '\0');
      if (cVar2 == cVar3) goto LAB_18002aced;
      iVar6 = iVar6 + 1;
    } while (iVar6 < DAT_180052cd4);
  }
  uVar9 = GetSorResStringEx(0xce7);
  uVar10 = GetSorResStringEx(0xce6);
  local_498 = GetSorResStringEx(0xce5);
  local_490 = local_478;
  local_488 = uVar10;
  local_480 = uVar9;
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
    local_498 = GetSorResStringEx(0xce5);
    local_490 = local_478;
    local_488 = uVar10;
    local_480 = uVar9;
    FUN_180008f80(dbxbuf_exref,"%c%c%s%s%s%s",0x5e,0x58);
    iVar7 = EXyesno(dbxbuf_exref,2,1);
    if (iVar7 == 1) {
      return 0xffffffff;
    }
  }
  pcVar8 = local_478;
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
    local_498 = GetSorResStringEx(0xcf0);
    local_490 = local_478;
    local_488 = uVar10;
    local_480 = uVar9;
    FUN_180008f80(dbxbuf_exref,"%c%c%s%s%s%s?",0x5e,0x3f);
    uVar9 = EXyesno(dbxbuf_exref,3,1);
    if ((int)uVar9 == 2) {
      return uVar9;
    }
  }
  if (((((*(int *)partial_results_exref == 0) || (iVar7 = GRinqiap(), iVar7 != 1)) ||
       (*(int *)triggered_by_canned_exref != 0)) ||
      ((*(int *)in_canned_exref != 0 || (*(int *)not_in_aspmsg_exref == 0)))) ||
     (uVar9 = FUN_18001a650(local_478), (int)uVar9 != 0)) {
    iVar7 = MVGetProductCode();
    pcVar8 = ".aprsum";
    pcVar14 = ".aprsum";
    if (iVar7 == 1) {
      pcVar14 = ".sum";
    }
    FUN_180008f80(local_368,&DAT_18003f9b0,local_478,pcVar14);
    lVar12 = 0;
    do {
      pcVar14 = local_478 + lVar12;
      local_148[lVar12] = *pcVar14;
      lVar12 = lVar12 + 1;
    } while (*pcVar14 != '\0');
    if (*(int *)(*(longlong *)SBdataptr_exref + 0x1214) == 0) {
      if ((*(int *)(*(longlong *)SBdataptr_exref + 0x1218) == 1) &&
         (lVar15 = lVar15 * 0x104, (&DAT_180052284)[lVar15] != '\0')) {
        FUN_180026740(&DAT_180052284 + lVar15,local_478,local_368,1);
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
        FUN_180026740(&DAT_180052284 + lVar15,local_478,local_148,1);
      }
    }
    else {
      iVar7 = FUN_18002b2c0(local_368,local_368,&DAT_180052284 + lVar15 * 0x104);
      if (iVar7 != 0) {
        local_498 = GetSorResStringEx(0xcf3);
        local_490 = local_368;
        FUN_180008f80(dbxbuf_exref,"%c%c%s%s",0x5e,0x58);
        iVar7 = EXyesno(dbxbuf_exref);
        if (iVar7 == 1) {
          return 0xffffffff;
        }
      }
    }
    iVar7 = _access(local_368,0);
    if (iVar7 == 0) {
      uVar4 = *(undefined4 *)partial_results_exref;
      *(undefined4 *)partial_results_exref = 0;
      OPreabck(local_148);
      *(int *)(*(longlong *)topfinfo_exref + 0x67c) =
           *(int *)(*(longlong *)topfinfo_exref + 0x67c) + 1;
      *(undefined4 *)partial_results_exref = uVar4;
    }
    else {
      uVar9 = GetSorResStringEx(0xcf5);
      local_498 = GetSorResStringEx(0xcf4);
      local_490 = local_368;
      local_488 = uVar9;
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
      local_258[0] = '\0';
      lVar15 = 0;
      do {
        pcVar14 = local_148 + lVar15;
        local_258[lVar15] = *pcVar14;
        lVar15 = lVar15 + 1;
      } while (*pcVar14 != '\0');
      iVar6 = MVGetProductCode();
      pcVar14 = ".aprinp";
      if (iVar6 == 1) {
        pcVar14 = ".inp";
      }
      puVar11 = &local_259;
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
      remove(local_258);
      local_258[0] = '\0';
      do {
        pcVar14 = local_148 + lVar13;
        local_258[lVar13] = *pcVar14;
        lVar13 = lVar13 + 1;
      } while (*pcVar14 != '\0');
      iVar6 = MVGetProductCode();
      puVar11 = &local_259;
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
      remove(local_258);
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

/* RVA 0x2b2c0 */
int FUN_18002b2c0(char *param_1,undefined8 param_2,undefined1 *param_3)

{
  int iVar1;
  
  if (*(int *)in_graphics_exref != 0) {
    hide_mouse();
    push_mouse_mask(0xd);
    show_mouse();
  }
  if ((*(uint *)(xprtdata_exref + 0x948) & 0x10000000) == 0) {
    FUN_1800345f0(param_1,param_2,param_3);
  }
  else {
    FUN_180034120(param_1,param_2,param_3);
  }
  iVar1 = _access(param_1,0);
  if (*(int *)in_graphics_exref != 0) {
    hide_mouse();
    pop_mouse_mask();
    show_mouse();
  }
  return -(uint)(iVar1 != 0);
}

/* RVA 0x2b360 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_18002b360(char *param_1,char *param_2,char *param_3)

{
  int iVar1;
  char *pcVar2;
  undefined1 auStack_158 [32];
  char local_138 [272];
  ulonglong local_28;
  
  local_28 = DAT_1800516d8 ^ (ulonglong)auStack_158;
  if (*(int *)in_graphics_exref != 0) {
    hide_mouse();
    push_mouse_mask(0xd);
    show_mouse();
  }
  if ((*(uint *)(xprtdata_exref + 0x944) & 0x10000000) == 0) {
    FUN_180034b70(param_1,param_2,param_3);
  }
  else {
    FUN_180034330(param_1,param_2,param_3);
  }
  iVar1 = *(int *)(*(longlong *)SBdataptr_exref + 0x1218);
  if (iVar1 == 0) {
    pcVar2 = "%s%s";
  }
  else {
    if (iVar1 == 1) {
      FUN_180026740(param_3,param_2,local_138,1);
      goto LAB_18002b424;
    }
    if (iVar1 != 2) goto LAB_18002b424;
    pcVar2 = "%s/%s";
  }
  FUN_180008f80(local_138,pcVar2,param_3,param_2);
LAB_18002b424:
  iVar1 = FUN_180026510((char *)0x0,local_138);
  if (*(int *)in_graphics_exref != 0) {
    hide_mouse();
    pop_mouse_mask();
    show_mouse();
  }
  return iVar1;
}

/* RVA 0x2b470 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_18002b470(char *param_1,undefined1 *param_2,char *param_3,int *param_4)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined1 *puVar5;
  ulonglong uVar6;
  int iVar7;
  char *pcVar8;
  undefined1 auStack_148 [32];
  undefined4 local_128;
  int local_118 [4];
  undefined1 local_108 [208];
  ulonglong local_38;
  
  local_38 = DAT_1800516d8 ^ (ulonglong)auStack_148;
  pcVar8 = "";
  uVar6 = 0xffffffff;
  iVar7 = 0;
  do {
    if (*(undefined1 **)(pcVar8 + -0xb) == (undefined1 *)0x0) {
LAB_18002b5ca:
      if (*param_1 != '\0') {
        uVar4 = FUN_180033fc0(param_1,param_2,param_3,param_4);
        uVar6 = uVar4 & 0xffffffff;
        if ((int)uVar4 == 0) {
          uVar3 = FUN_180034540(param_1);
          uVar6 = (ulonglong)uVar3;
          if (uVar3 == 0) {
            return 0;
          }
        }
      }
    }
    else {
      puVar5 = local_108;
      if (pcVar8[-1] == '\0') {
        if (*pcVar8 == '\0') {
          if (pcVar8[1] == '\0') goto LAB_18002b56d;
          uVar3 = MVGetPointI();
          uVar2 = MVGetMajorI();
          param_2 = *(undefined1 **)(pcVar8 + -0xb);
          param_3 = (char *)(ulonglong)uVar2;
          param_4 = (int *)(ulonglong)uVar3;
          FUN_180008f80(local_108,param_2,param_3,param_4);
        }
        else {
          param_3 = (char *)MVGetRegistryKey();
          param_2 = *(undefined1 **)(pcVar8 + -0xb);
          FUN_180008f80(local_108,param_2,param_3,param_4);
        }
      }
      else if (*pcVar8 == '\0') {
        if (pcVar8[1] == '\0') {
LAB_18002b56d:
          puVar5 = *(undefined1 **)(pcVar8 + -0xb);
        }
        else {
          uVar1 = MVGetPointI();
          uVar3 = MVGetMajorI();
          param_3 = (char *)MVGetProductRegistryName();
          param_2 = *(undefined1 **)(pcVar8 + -0xb);
          param_4 = (int *)(ulonglong)uVar3;
          local_128 = uVar1;
          FUN_180008f80(local_108,param_2,param_3,param_4);
        }
      }
      else {
        param_4 = (int *)MVGetRegistryKey();
        param_3 = (char *)MVGetProductRegistryName();
        param_2 = *(undefined1 **)(pcVar8 + -0xb);
        FUN_180008f80(local_108,param_2,param_3,param_4);
      }
      if (pcVar8[-3] == '\0') {
LAB_18002b599:
        if ((int)uVar6 == 0) goto LAB_18002b5ca;
      }
      else {
        param_4 = local_118;
        param_2 = puVar5;
        param_3 = param_1;
        uVar6 = FUN_180035440('U',puVar5,param_1,param_4);
        uVar6 = uVar6 & 0xffffffff;
        if (local_118[0] == 0) goto LAB_18002b599;
        uVar6 = 0xffffffff;
      }
      if (pcVar8[-2] != '\0') {
        param_4 = local_118;
        param_3 = param_1;
        uVar4 = FUN_180035440('M',puVar5,param_1,param_4);
        uVar6 = uVar4 & 0xffffffff;
        param_2 = puVar5;
        if (local_118[0] == 0) {
          if ((int)uVar4 == 0) goto LAB_18002b5ca;
        }
        else {
          uVar6 = 0xffffffff;
        }
      }
    }
    iVar7 = iVar7 + 1;
    pcVar8 = pcVar8 + 0x10;
    if (6 < iVar7) {
      return uVar6;
    }
  } while( true );
}

/* RVA 0x2b640 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_18002b640(undefined8 param_1,undefined1 *param_2,char *param_3,int *param_4)

{
  char cVar1;
  char cVar2;
  longlong lVar3;
  int iVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  char *pcVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  code *pcVar12;
  code *pcVar13;
  char *pcVar14;
  longlong lVar15;
  undefined *puVar16;
  undefined4 uVar17;
  undefined1 auStack_338 [32];
  undefined8 local_318;
  undefined8 local_310;
  undefined8 local_308;
  undefined8 local_300;
  char *local_2f8;
  undefined8 local_2f0;
  longlong local_2e8;
  int local_2d8 [2];
  char *local_2d0;
  char local_2c8 [256];
  char local_1c8 [144];
  char local_138 [272];
  ulonglong local_28;
  
  local_28 = DAT_1800516d8 ^ (ulonglong)auStack_338;
  *(undefined8 *)Sactions_exref = 0;
  *(uint *)(Sactions_exref + 4) = *(uint *)(Sactions_exref + 4) | 2;
  *(uint *)Sactions_exref = *(uint *)Sactions_exref | 0x200;
  if (*(int *)debug_flag_exref != 0) {
    show_cpanel();
  }
  iVar4 = GRinqcnn();
  if ((iVar4 == 0) && (*(int *)(*(longlong *)SBdataptr_exref + 0x146c) == 0)) {
    uVar5 = FUN_18002a150();
    if ((int)uVar5 != 0) {
      GetLastXCerror(local_2d8,&local_2d0);
      if ((local_2d8[0] == 0x23) || (local_2d8[0] == 0xb)) {
        pcVar8 = (char *)GetSorResStringEx(0xd03);
        pcVar14 = local_2d0;
        do {
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
          *pcVar14 = cVar1;
          pcVar14 = pcVar14 + 1;
        } while (cVar1 != '\0');
      }
      if (*(int *)debug_flag_exref == 0) {
        uVar5 = GetSorResStringEx(0xd06);
        uVar7 = GetSorResStringEx(0xd05);
        local_318 = GetSorResStringEx(0xd04);
        local_2f8 = local_2d0;
        local_300 = CONCAT44(local_300._4_4_,local_2d8[0]);
        local_310 = uVar7;
        local_308 = uVar5;
        FUN_180008f80(dbxbuf_exref,"%c%c%s%s%s%d - %s",0x5e,0x58);
      }
      else {
        lVar3 = *(longlong *)SBdataptr_exref;
        uVar5 = GetSorResStringEx(0xd07);
        uVar7 = GetSorResStringEx(0xd06);
        uVar9 = GetSorResStringEx(0xd05);
        local_318 = GetSorResStringEx(0xd04);
        local_2f8 = local_2d0;
        local_300 = CONCAT44(local_300._4_4_,local_2d8[0]);
        local_310 = uVar9;
        local_308 = uVar7;
        local_2f0 = uVar5;
        local_2e8 = lVar3 + 0x1364;
        FUN_180008f80(dbxbuf_exref,"%c%c%s%s%s%d - %s%s%s",0x5e,0x58);
      }
      FUN_180006fc0('e',(char *)(dbxbuf_exref + 2),"OKONLY",0);
      return 0xffffffff;
    }
    if (*(int *)debug_flag_exref != 0) {
      param_2 = (undefined1 *)GetSorResStringEx(0xcf6);
      FUN_180008f80(local_2c8,param_2,param_3,param_4);
      FUN_1800282b0(local_2c8);
    }
    if ((*(int *)(*(longlong *)SBdataptr_exref + 0x1214) == 0) ||
       (uVar6 = FUN_18002b470((char *)(*(longlong *)SBdataptr_exref + 0x10),param_2,param_3,param_4)
       , (int)uVar6 == 0)) {
      iVar4 = FUN_1800325b0((undefined *)0x0,param_2,param_3,(undefined *)param_4);
      if (iVar4 == 0) {
        if (*(int *)(*(longlong *)SBdataptr_exref + 0x1214) != 0) {
          _getcwd(local_138,0x104);
          lVar3 = *(longlong *)SBdataptr_exref;
          pcVar8 = local_138;
          lVar15 = (lVar3 + 0x10) - (longlong)pcVar8;
          do {
            cVar1 = *pcVar8;
            cVar2 = pcVar8[lVar15];
            if (cVar1 != cVar2) break;
            pcVar8 = pcVar8 + 1;
          } while (cVar2 != '\0');
          if (cVar1 == cVar2) {
            uVar5 = GetSorResStringEx(0xcfe);
            uVar7 = GetSorResStringEx(0xcfd);
            uVar9 = GetSorResStringEx(0xcfc);
            uVar10 = GetSorResStringEx(0xcfb);
            uVar11 = GetSorResStringEx(0xcfa);
            local_318 = uVar10;
            local_310 = uVar9;
            local_308 = uVar7;
            local_300 = uVar5;
            FUN_180008f80(local_2c8,"%s %s, %s.  %s.  %s, %s.",uVar11,local_138);
            FUN_180028530(local_2c8,-1);
            goto LAB_18002b97a;
          }
          if (*(int *)debug_flag_exref != 0) {
            uVar5 = GetSorResStringEx(0xcff);
            FUN_180008f80(local_2c8,uVar5,lVar3 + 0x10,param_4);
            FUN_1800282b0(local_2c8);
          }
          FUN_180008f80(local_1c8,"%s.def",APtmpfil_exref,param_4);
          param_3 = (char *)(*(longlong *)SBdataptr_exref + 0x10);
          iVar4 = FUN_18002b360(local_1c8,local_1c8,param_3);
          if (iVar4 != 0) {
            uVar5 = 0xd00;
            goto LAB_18002b7a8;
          }
        }
        if (*(int *)debug_flag_exref != 0) {
          uVar5 = GetSorResStringEx(0xd01);
          FUN_180008f80(local_2c8,uVar5,param_3,param_4);
          FUN_1800282b0(local_2c8);
        }
        uVar6 = FUN_180023ef0();
        if (0 < (int)uVar6) goto LAB_18002bb49;
        if (*(int *)debug_flag_exref != 0) {
          uVar5 = GetSorResStringEx(0xd02);
          FUN_180008f80(local_2c8,uVar5,param_3,param_4);
          FUN_1800282b0(local_2c8);
        }
      }
      else if ((*(uint *)Sactions_exref & 0x1000) != 0) {
        uVar5 = 0xcf9;
LAB_18002b7a8:
        pcVar8 = (char *)GetSorResStringEx(uVar5);
        FUN_180028530(pcVar8,-1);
      }
    }
    else {
      uVar5 = GetSorResStringEx(0xcf8);
      uVar7 = GetSorResStringEx(0xcf7);
      FUN_180008f80(local_2c8,"%s.  %s.",uVar7,uVar5);
      FUN_180028530(local_2c8,-1);
    }
LAB_18002b97a:
    show_cpanel();
    local_318 = GetSorResStringEx(0xd08);
    pcVar12 = dbxbuf_exref;
    FUN_180008f80(dbxbuf_exref,"%c%c%s",0x5e,0x58);
    puVar16 = &DAT_18003ffec;
    pcVar13 = dbxbuf_exref + 2;
    pcVar8 = (char *)0x0;
    uVar7 = CONCAT71((int7)((ulonglong)pcVar12 >> 8),0x71);
    uVar5 = FUN_180006fc0('q',(char *)pcVar13,"YN",0);
    FUN_18002a3a0(uVar7,pcVar13,puVar16,pcVar8);
    uVar17 = 0xffffffff;
    if ((int)uVar5 == 0) {
      uVar17 = 1;
    }
  }
  else {
LAB_18002bb49:
    GRsetsbs(4);
    local_318 = GetSorResStringEx(0xd09);
    FUN_180008f80(dbxbuf_exref,"%c%c%s",0x5e,0x69);
    memset(&DAT_180052220,0,0xab8);
    uVar17 = 0;
  }
  return uVar17;
}

/* RVA 0x2bbe0 */
int FUN_18002bbe0(void)

{
  int iVar1;
  char *pcVar2;
  
  pcVar2 = getenv("MM_SHELL_FLAG");
  if (pcVar2 != (char *)0x0) {
    iVar1 = atoi(pcVar2);
    *(int *)shell_flag_exref = iVar1;
  }
  FUN_180029f50(0);
  iVar1 = SPAWN(DAT_180052d78,shell_cmnd_exref,*(undefined4 *)shell_flag_exref,0,0,0,0);
  if (iVar1 == -1) {
    pcVar2 = (char *)GetSorResStringEx(0xd0c);
    FUN_180028530(pcVar2,-1);
    return iVar1;
  }
  FUN_180029f50(1);
  return iVar1;
}

/* RVA 0x2bc80 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_18002bc80(char *param_1)

{
  bool bVar1;
  int iVar2;
  FILE *_File;
  char *pcVar3;
  undefined4 uVar4;
  undefined1 auStack_d8 [32];
  char *local_b8;
  undefined1 local_b0 [24];
  char local_98 [128];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_d8;
  bVar1 = false;
  _File = fopen(param_1,"r");
  if (_File == (FILE *)0x0) {
    uVar4 = 0xffffffff;
  }
  else {
    local_b8 = fgets(local_98,0x78,_File);
    uVar4 = local_b8._0_4_;
    if (local_b8 != (char *)0x0) {
      do {
        if (bVar1) {
          bVar1 = false;
        }
        else {
          pcVar3 = (char *)FUN_18002bdd0((longlong)local_b8);
          if (*pcVar3 != '\n') {
            bVar1 = true;
          }
          SFgettok(&local_b8,local_b0,0x14);
          iVar2 = SFidxstri(local_b0,&PTR_DAT_180050db8,4);
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
        local_b8 = fgets(local_98,0x78,_File);
      } while (local_b8 != (char *)0x0);
      local_b8 = (char *)0x0;
    }
    fclose(_File);
  }
  return uVar4;
}

/* RVA 0x2bdd0 */
longlong FUN_18002bdd0(longlong param_1)

{
  longlong lVar2;
  longlong lVar1;
  
  lVar1 = -1;
  do {
    lVar2 = lVar1;
    lVar1 = lVar2 + 1;
  } while (*(char *)(param_1 + lVar1) != '\0');
  return lVar2 + param_1;
}

/* RVA 0x2bdf0 */
bool FUN_18002bdf0(void)

{
  return *(int *)(*(longlong *)topfinfo_exref + 0x380) == 1;
}

/* RVA 0x2be10 */
undefined8 FUN_18002be10(void)

{
  MDloocmp(*(undefined8 *)(*(longlong *)topfinfo_exref + 0x168),0,0x80,0);
  return 0;
}

/* RVA 0x2be40 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_18002be40(int param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined8 uVar4;
  longlong *plVar5;
  longlong lVar6;
  int iVar7;
  undefined1 auStack_168 [32];
  undefined4 local_148;
  uint *local_140;
  uint local_138;
  undefined4 local_134 [3];
  uchar local_128 [272];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_168;
  uVar4 = HYPshFinfo(1);
  GRsavpgc(local_134);
  if ((*(longlong *)g_gebisymlst_exref != 0) && (*(int *)bestinput_exref != 0)) {
    iVar3 = MDptrcnt();
    iVar7 = 0;
    if (0 < iVar3) {
      do {
        plVar5 = (longlong *)MDptridx(*(undefined8 *)g_gebisymlst_exref,iVar7);
        puVar2 = (undefined8 *)*plVar5;
        if ((puVar2 != (undefined8 *)0x0) &&
           (lVar6 = MDgetito(*(undefined8 *)iwpfile_exref,puVar2[1],*puVar2), lVar6 != 0)) {
          local_138 = local_138 & 0xfffff3ff | 0x2000200;
          param_4 = *(undefined8 *)(lVar6 + 8);
          local_140 = &local_138;
          local_148 = 0x104;
          MDchgflg(lVar6 + 0x40,*(undefined4 *)(lVar6 + 0x38),*(undefined8 *)(lVar6 + 0x80));
          lVar6 = MDgethkp(*(undefined8 *)iwpfile_exref,*(undefined8 *)(lVar6 + 0x10),
                           *(undefined8 *)(lVar6 + 8));
          if (lVar6 != 0) {
            *(uint *)(lVar6 + 0x18) = *(uint *)(lVar6 + 0x18) & 0xffffefff;
          }
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < iVar3);
    }
  }
  _DAT_180052cec = 0;
  uVar1 = *(uint *)(Sactions_exref + 4);
  if (((uVar1 >> 0xb & 1) != 0) || (((uVar1 & 0x43000) != 0 && (((byte)*Sactions_exref & 1) == 0))))
  {
    _DAT_180052cec = 1;
  }
  if ((uVar1 >> 9 & 1) == 0) {
    FUN_18002c180(*(undefined8 *)dataclass_exref);
  }
  else {
    FUN_180039ce0();
  }
  GRsetedt(1);
  GRsetist(0);
  if ((param_1 == 0) && ((*(uint *)(Sactions_exref + 4) & 0x21) == 0)) {
    if ((*(uint *)(Sactions_exref + 4) & 0xa00) == 0) {
      HYloohie(FUN_18002c100);
    }
    iVar3 = SBlocalhost();
    if (iVar3 == 0) {
      FUN_180008f80(local_128,"%s.dan",APtmpfil_exref,param_4);
      name_lwr(local_128);
      remove((char *)local_128);
      dump_input(local_128,0);
    }
  }
  GRsetpgc(local_134[0]);
  if (*(longlong *)g_gebisymlst_exref != 0) {
    MDptrfre();
    *(undefined8 *)g_gebisymlst_exref = 0;
  }
  HYPopFinfo(uVar4);
  return;
}

/* RVA 0x2c0b0 */
void SBfaksim(int param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
                    /* 0x2c0b0  102  SBfaksim */
  FUN_18002be40(param_1,param_2,param_3,param_4);
  GRsetsbm(1);
  GRsetsms(1);
  GRsetsmf(1);
  GRsetmtf(0);
  GRsetrpt(1);
  GRsetgpd(1);
  FUN_180021b60(1);
  return;
}

/* RVA 0x2c100 */
void FUN_18002c100(void)

{
  if (*(longlong *)(*(longlong *)finfo_exref + 0x1e0) != 0) {
    MDdelito(*(undefined8 *)iwpfile_exref,0xffffffffffffffff);
    MDfrehnk(*(undefined8 *)iwpfile_exref,0xffffffffffffffff,
             *(undefined8 *)(*(longlong *)finfo_exref + 0x1e0));
    *(undefined8 *)(*(longlong *)finfo_exref + 0x1e0) = 0;
  }
  return;
}

/* RVA 0x2c180 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_18002c180(undefined8 param_1)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  undefined8 uVar7;
  longlong lVar8;
  longlong lVar9;
  longlong lVar10;
  undefined1 auStack_1d8 [32];
  longlong *local_1b8;
  uint *local_1b0;
  undefined4 local_1a8;
  uint local_198 [2];
  longlong local_190 [5];
  undefined1 local_168 [8];
  undefined8 local_160;
  undefined8 uStack_158;
  undefined8 local_90;
  ulonglong local_38;
  
  local_38 = DAT_1800516d8 ^ (ulonglong)auStack_1d8;
  local_198[0] = local_198[0] & 0xfdfff1ff;
  if (((byte)Sactions_exref[4] & 1) != 0) {
    return;
  }
  local_190[0] = 0;
  lVar2 = MDrslcls(*(undefined8 *)iwpfile_exref,param_1);
joined_r0x00018002c1e5:
  if (local_190[0] == -1) {
    return;
  }
  local_1b8 = local_190;
  local_1b0 = (uint *)0x0;
  lVar3 = MDfndsls(*(undefined8 *)iwpfile_exref,param_1,1);
  if (local_190[0] == -1) {
    return;
  }
  lVar10 = lVar3 * 0x108 + lVar2;
  lVar5 = lVar3;
  if (*(char *)(lVar10 + 0x107) == '\x06') goto code_r0x00018002c26d;
  goto LAB_18002c2cb;
code_r0x00018002c26d:
  lVar6 = *(longlong *)(lVar10 + 0x28);
  lVar4 = MDrslcls(*(undefined8 *)iwpfile_exref,lVar6);
  if (((*(uint *)(lVar4 + 0x120) & 0xe00) != 0) ||
     ((*(int *)bestinput_exref != 0 &&
      (iVar1 = strcmp((char *)(lVar4 + 0x108),"FLOWSHEET"), iVar1 == 0)))) {
    lVar5 = *(longlong *)(lVar4 + 0x148);
    if (*(longlong *)(lVar4 + 0x148) == 0) {
      lVar5 = lVar6;
    }
LAB_18002c2cb:
    if (*(char *)(lVar10 + 0x107) == '\x03') {
      lVar5 = MDgetito(*(undefined8 *)iwpfile_exref,param_1,lVar3);
      if ((*(longlong *)(lVar5 + 0x10) != 0) && (*(longlong *)(lVar5 + 0x20) != 0)) {
        lVar6 = MDgetito(*(undefined8 *)recfile_exref,*(longlong *)(lVar5 + 0x20),
                         *(undefined8 *)(lVar5 + 0x18));
        iVar1 = *(int *)(lVar6 + 0x2c);
        if (iVar1 == 0x1e) {
          local_160 = *(undefined8 *)(lVar5 + 8);
          uStack_158 = *(undefined8 *)(lVar5 + 0x10);
          *(undefined1 **)gevaldef_exref = local_168;
          iVar1 = GEpropse(2);
          if (iVar1 == 2) {
            iVar1 = GRinqgpd();
            if ((iVar1 == 0) || (*(int *)(*(longlong *)topfinfo_exref + 0x1dc) == 0)) {
              local_1a8 = 1;
              local_1b0 = (uint *)CONCAT44(local_1b0._4_4_,9999);
              local_1b8 = (longlong *)CONCAT44(local_1b8._4_4_,9999);
              MDprpcmp(lVar5 + 0x40,*(undefined4 *)(lVar5 + 0x38),*(undefined8 *)(lVar5 + 0x80));
              *(uint *)(lVar10 + 0x18) = *(uint *)(lVar10 + 0x18) & 0xffffefff;
            }
            goto joined_r0x00018002c1e5;
          }
        }
        else if (iVar1 == 0xf) {
          if ((*(int *)runanyway_exref == 0) || (*(int *)bestinput_exref != 0)) {
            memset(local_168,0,0x128);
            local_160 = *(undefined8 *)(lVar5 + 8);
            uStack_158 = *(undefined8 *)(lVar5 + 0x10);
            local_90 = MDgetito(*(undefined8 *)iwpfile_exref,*(undefined8 *)(lVar5 + 0x10),local_160
                               );
            MDgetrdf(local_168);
            iVar1 = IsFlowSecComplete(local_168);
            if ((iVar1 == 0) ||
               ((*(int *)bestinput_exref != 0 &&
                (iVar1 = IsFlowSecBlkStrmComplete(local_168), iVar1 == 0)))) {
              iVar1 = GRinqgpd();
              if (((iVar1 != 0) && (*(int *)(*(longlong *)topfinfo_exref + 0x1dc) != 0)) ||
                 (*(int *)bestinput_exref != 0)) {
                local_1a8 = 1;
                local_1b0 = (uint *)CONCAT44(local_1b0._4_4_,9999);
                local_1b8 = (longlong *)CONCAT44(local_1b8._4_4_,9999);
                MDprpcmp(lVar5 + 0x40,*(undefined4 *)(lVar5 + 0x38),*(undefined8 *)(lVar5 + 0x80));
                *(uint *)(lVar10 + 0x18) = *(uint *)(lVar10 + 0x18) & 0xffffefff;
              }
              goto joined_r0x00018002c1e5;
            }
          }
        }
        else if (iVar1 == 0xd7) {
          *(uint *)(lVar10 + 0x18) = *(uint *)(lVar10 + 0x18) | 0x1000;
          uVar7 = HYGetFinfoCls(param_1,lVar3);
          uVar7 = HYPshFinfo(uVar7);
          FUN_18002c180(*(undefined8 *)dataclass_exref);
          HYPopFinfo(uVar7);
          goto joined_r0x00018002c1e5;
        }
        if ((_DAT_180052cec == 0) || ((*(uint *)(lVar10 + 0x18) & 0x2000000) != 0)) {
          if (*(int *)bestinput_exref != 0) {
            lVar4 = MDgethkp(*(undefined8 *)iwpfile_exref,*(undefined8 *)(lVar5 + 0x10),
                             *(undefined8 *)(lVar5 + 8));
            lVar8 = MDgetcnm(*(undefined8 *)iwpfile_exref,*(undefined8 *)(lVar5 + 0x10));
            lVar6 = 0;
            do {
              lVar9 = lVar6 + 1;
              if (*(char *)(lVar8 + lVar6) != "CONNECT"[lVar6]) {
                iVar1 = AreDependenciesComplete
                                  (*(undefined8 *)(lVar5 + 0x10),*(undefined8 *)(lVar5 + 8));
                if (iVar1 == 0) goto joined_r0x00018002c1e5;
                break;
              }
              lVar6 = lVar9;
            } while (lVar9 != 8);
            if ((*(byte *)(lVar4 + 0x18) & 0xf) == 0) goto joined_r0x00018002c1e5;
          }
          *(uint *)(lVar10 + 0x18) = *(uint *)(lVar10 + 0x18) | 0x1000;
          local_1b0 = local_198;
          local_1b8 = (longlong *)CONCAT44(local_1b8._4_4_,0x104);
          MDchgflg(lVar5 + 0x40,*(undefined4 *)(lVar5 + 0x38),*(undefined8 *)(lVar5 + 0x80));
          MDunlito(*(undefined8 *)iwpfile_exref,param_1,lVar3);
        }
      }
    }
    else if (*(char *)(lVar10 + 0x107) == '\x06') {
      FUN_18002c180(lVar5);
    }
  }
  goto joined_r0x00018002c1e5;
}

/* RVA 0x2c620 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18002c620(longlong param_1)

{
  code cVar1;
  code cVar2;
  int iVar3;
  code *pcVar4;
  undefined1 *puVar5;
  char *pcVar6;
  undefined1 auStack_158 [32];
  undefined4 local_138 [4];
  uchar local_128 [272];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_158;
  if (((byte)Sactions_exref[4] & 0x20) == 0) {
    GRsavpgc(local_138);
    _guard_check_icall();
    if (*(int *)(*(longlong *)SBdataptr_exref + 0x1214) != 0) {
      iVar3 = MVGetProductCode();
      pcVar6 = ".aprsum";
      if (iVar3 == 1) {
        pcVar6 = ".sum";
      }
      FUN_180008f80(local_128,&DAT_18003f9b0,param_1,pcVar6);
      name_lwr(local_128);
      pcVar4 = APtmpfil_exref;
      do {
        cVar1 = *pcVar4;
        cVar2 = pcVar4[param_1 - (longlong)APtmpfil_exref];
        if (cVar1 != cVar2) break;
        pcVar4 = pcVar4 + 1;
      } while (cVar2 != (code)0x0);
      if (cVar1 == cVar2) {
        puVar5 = (undefined1 *)(*(longlong *)SBdataptr_exref + 0x10);
      }
      else {
        puVar5 = (undefined1 *)(*(longlong *)SBdataptr_exref + 0x110);
      }
      FUN_18002b2c0((char *)local_128,local_128,puVar5);
    }
    OPreabck(param_1,0,0);
    _guard_check_icall();
    FUN_180008f00();
    GRsetpgc(local_138[0]);
    if (*(int *)(*(longlong *)topfinfo_exref + 0x150) != 0) {
      iVar3 = GRinqpgc();
      if (iVar3 != 0) {
        GRsetcpt(0);
      }
    }
  }
  return;
}

/* RVA 0x2c760 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18002c760(int param_1,int param_2,char *param_3,char *param_4)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  undefined8 uVar5;
  longlong lVar6;
  undefined1 auStackY_268 [32];
  uint local_238;
  char local_228 [272];
  char local_118 [256];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStackY_268;
  pcVar3 = (char *)GetSorResStringEx();
  if (param_2 == 1) {
    iVar2 = MVGetProductCode();
    if (iVar2 == 2) {
      pcVar4 = (char *)GetSorResStringEx(0x1ef);
      lVar6 = (longlong)pcVar3 - (longlong)pcVar4;
      do {
        cVar1 = *pcVar4;
        pcVar4[lVar6] = cVar1;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
    }
    if (((byte)Sactions_exref[4] & 0x20) == 0) {
      param_4 = (char *)0x0;
      param_3 = "OKCANCEL";
      uVar5 = FUN_180006fc0('q',pcVar3,"OKCANCEL",0);
      if ((int)uVar5 != 0) {
        DAT_180052ce4 = 1;
        return 0;
      }
    }
  }
  if (param_1 == 0) {
    RLResetAllACM();
  }
  else {
    param_4 = (char *)0x12010200;
    param_3 = (char *)0x0;
    FUN_180030240((char *)0x0,local_228,0,0x12010200,(char *)0x0);
  }
  *(undefined4 *)denied_exref = 0;
  _guard_check_icall();
  GRsetpdb(0);
  if ((DAT_180052ec4 != 0) && (iVar2 = GRinqiap(), iVar2 != 0)) {
    FUN_1800186a0();
  }
  FUN_180021800(*(longlong *)(*(longlong *)topfinfo_exref + 0x560),0);
  GRsetgpd(0);
  GRsetust(0);
  GRsetQRs(0);
  GRsetpdb(0);
  *(undefined4 *)(*(longlong *)topfinfo_exref + 0x438) = 0xffffffff;
  FUN_180025e00((char *)APtmpfil_exref,1,param_3,param_4);
  GRsetari(*(undefined8 *)topfinfo_exref);
  pcVar3 = (char *)GetSorResStringEx(0x1f0);
  lVar6 = -(longlong)pcVar3;
  do {
    cVar1 = *pcVar3;
    pcVar3[(longlong)(local_118 + lVar6)] = cVar1;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  _guard_check_icall();
  if (DAT_180050de0 != 0) {
    FUN_180028200(local_118);
  }
  GRsetsms(0);
  GRsetsmf(0);
  GRsetsbm(0);
  GRsetpgc();
  GRsetedt();
  GRsetexc();
  SBsetnxt((char *)0x0,0);
  GRsetanm();
  FUN_1800068d0((char *)0x0,1);
  GRsetrdy(0);
  OPpurout(*(undefined8 *)iwpfile_exref,0,0);
  MDclrmsg(*(undefined8 *)(*(longlong *)topfinfo_exref + 0x168));
  MDloocmp(*(undefined8 *)(*(longlong *)topfinfo_exref + 0x168),0,0xac,
           local_238 & 0xfe03a3ff | 0x8200);
  FUN_180006950();
  FUN_1800085e0(0);
  _guard_check_icall();
  pfs_refresh_status();
  return 1;
}

/* RVA 0x2c9f0 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_18002c9f0(undefined8 param_1,uchar *param_2,char *param_3,char *param_4)

{
  _DAT_180052ce8 = 1;
  *(undefined4 *)alwaysreplaceCHEM_exref = 0;
  *(undefined4 *)alwaysreplaceDRS_exref = 0;
  *(undefined4 *)alwaysreplacePCES_exref = 0;
  FUN_18002ca30(param_1,param_2,param_3,param_4);
  _DAT_180052ce8 = 0;
  return;
}

/* RVA 0x2ca30 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_18002ca30(undefined8 param_1,uchar *param_2,char *param_3,char *param_4)

{
  char cVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  undefined4 uVar17;
  char *pcVar18;
  undefined7 extraout_var;
  uchar *puVar19;
  ulonglong uVar20;
  FILE *_File;
  FILE *_File_00;
  FILE *_File_01;
  longlong lVar21;
  undefined7 extraout_var_00;
  longlong lVar22;
  undefined8 uVar23;
  char *pcVar24;
  undefined8 uVar25;
  uint uVar26;
  bool bVar27;
  undefined1 auStackY_678 [32];
  int local_648;
  int local_630;
  char local_5f8 [272];
  char local_4e8 [32];
  uchar local_4c8 [144];
  uchar local_438 [128];
  uchar local_3b8 [128];
  CHAR local_338 [80];
  char local_2e8 [80];
  char local_298 [128];
  char local_218 [208];
  char local_148 [272];
  ulonglong local_38;
  
  local_38 = DAT_1800516d8 ^ (ulonglong)auStackY_678;
  local_648 = 1;
  bVar10 = false;
  local_630 = 0;
  bVar8 = false;
  bVar27 = false;
  iVar15 = *(int *)(*(longlong *)SBdataptr_exref + 0x1214);
  bVar7 = true;
  puVar19 = param_2;
  pcVar24 = param_3;
  if (*(int *)debug_flag_exref != 0) {
    pcVar18 = (char *)GetSorResStringEx(0x1f2);
    FUN_1800282b0(pcVar18);
  }
  if (*(FILE **)PTR_DAT_180044168 != (FILE *)0x0) {
    fflush(*(FILE **)PTR_DAT_180044168);
  }
  if (((*(uint *)Sactions_exref & 0x1000) != 0) || (param_3 == (char *)0x0)) {
    return 0;
  }
  uVar11 = 0xffffd8f1;
  uVar17 = *(undefined4 *)partial_results_exref;
  if (*(int *)prop_retrieve_results_exref != 0) {
    *(undefined4 *)partial_results_exref = 1;
    *(undefined4 *)sum_header_exref = 1;
  }
  if ((*(uint *)Sactions_exref & 0x1000000) == 0) {
    GRseterr();
  }
  uVar16 = 0xffffffff;
  if ((*(uint *)Sactions_exref & 0x4000000) != 0) {
    if (*(int *)debug_flag_exref != 0) {
      pcVar18 = (char *)GetSorResStringEx(499);
      FUN_1800282b0(pcVar18);
    }
    uVar11 = FUN_1800186a0();
    GRsetust();
    if (uVar11 == 0) {
      uVar11 = 9;
      goto LAB_18002cb84;
    }
    if (uVar11 == 9) goto LAB_18002cb84;
    goto LAB_18002cbe2;
  }
LAB_18002cb84:
  if ((*(uint *)Sactions_exref & 0x8000000) != 0) {
    puVar19 = (uchar *)0x1;
    FUN_180025e00((char *)APtmpfil_exref,1,pcVar24,param_4);
  }
  if ((*(uint *)(Sactions_exref + 4) & 0x8000) != 0) {
    if (*(int *)debug_flag_exref != 0) {
      pcVar18 = (char *)GetSorResStringEx(500);
      FUN_1800282b0(pcVar18);
    }
    iVar12 = FUN_180029f80((char *)param_2);
    if (iVar12 != 0) {
      local_630 = -1;
      goto LAB_18002cbe2;
    }
  }
  if ((*(uint *)Sactions_exref & 0x200) != 0) {
    if (*(int *)debug_flag_exref != 0) {
      pcVar18 = (char *)GetSorResStringEx(0x1f5);
      FUN_1800282b0(pcVar18);
    }
    iVar12 = FUN_1800325b0((undefined *)0x0,puVar19,pcVar24,param_4);
    if (iVar12 == -1) goto LAB_18002cbe2;
  }
  if ((*(uint *)Sactions_exref & 0x100) != 0) {
    FUN_180008f80(local_4c8,"%s.inm",APtmpfil_exref,param_4);
    param_4 = (char *)GetSorResStringEx(0x1f6);
    puVar19 = (uchar *)0x0;
    pcVar24 = (char *)0x1;
    FUN_18002a580((char *)local_4c8,0,1,param_4);
  }
  if (((byte)*Sactions_exref & 1) == 0) {
LAB_18002cd23:
    if (((*(uint *)Sactions_exref & 0x200) != 0) && (iVar15 != 0)) {
      FUN_180008f80(local_4c8,"%s.def",APtmpfil_exref,param_4);
      name_lwr(local_4c8);
      puVar19 = local_4c8;
      pcVar24 = (char *)(*(longlong *)SBdataptr_exref + 0x10);
      iVar12 = FUN_18002b360((char *)local_4c8,(char *)puVar19,pcVar24);
      if (iVar12 != 0) {
        pcVar24 = (char *)GetSorResStringEx(0x1f9);
        FUN_180028530(pcVar24,-1);
        local_648 = 1;
        goto LAB_18002d274;
      }
    }
    if (((byte)*Sactions_exref & 0x80) == 0) {
      if (*(int *)badmax_exref != 0) {
        *(undefined4 *)badmax_exref = 0;
        pcVar24 = (char *)GetSorResStringEx(0x1fa);
        FUN_1800282b0(pcVar24);
        goto LAB_18002cbe2;
      }
      bVar9 = FUN_180025320();
      if ((int)CONCAT71(extraout_var,bVar9) != 0) {
        _guard_check_icall();
      }
      if ((*(uint *)Sactions_exref & 0x200000) != 0) {
        if (*(int *)debug_flag_exref != 0) {
          pcVar24 = (char *)GetSorResStringEx(0x1fb);
          FUN_1800282b0(pcVar24);
          pcVar24 = (char *)GetSorResStringEx(0x1fc);
          FUN_1800282b0(pcVar24);
        }
        puVar19 = name_lwr(*(uchar **)topfinfo_exref);
        FUN_180025350((char *)puVar19,(char *)APtmpfil_exref);
        FUN_180008f80(local_4e8,"%s.nin",APtmpfil_exref,param_4);
        dump_buffer(*(undefined8 *)(*(longlong *)topfinfo_exref + 0x548));
        if ((iVar15 != 0) &&
           (iVar15 = FUN_18002b360(local_4e8,local_4e8,(char *)(*(longlong *)SBdataptr_exref + 0x10)
                                  ), iVar15 != 0)) {
          pcVar24 = (char *)GetSorResStringEx(0x1fd);
          FUN_180028530(pcVar24,-1);
          local_648 = 1;
          goto LAB_18002d274;
        }
      }
      if (((byte)*Sactions_exref & 0x10) != 0) {
        uVar20 = FUN_180023ef0();
        uVar11 = (uint)uVar20;
        GRsetsbm();
        if (*(int *)in_canned_exref != 0) {
          *(undefined4 *)triggered_by_canned_exref = 1;
        }
        if ((*(int *)partial_results_exref != 0) && (DAT_180051ff0 != 0)) {
          DAT_180051ff0 = 0;
        }
        if (uVar11 == 0xffffffff) goto LAB_18002cbe2;
      }
      if ((*(uint *)Sactions_exref & 0x2000) != 0) {
        if (*(int *)debug_flag_exref != 0) {
          pcVar24 = (char *)GetSorResStringEx(0x1fe);
          FUN_1800282b0(pcVar24);
        }
        *(uint *)triggered_by_canned_exref = (uint)(*(int *)in_canned_exref != 0);
        if ((*(int *)partial_results_exref != 0) && (DAT_180051ff0 != 0)) {
          DAT_180051ff0 = 0;
        }
        uVar20 = FUN_180023d70();
        uVar11 = (uint)uVar20;
        GRsetfop(1);
        GRsetsbm();
        if (uVar11 == 0xffffffff) goto LAB_18002cbe2;
      }
      iVar15 = 0;
      if ((*(uint *)(Sactions_exref + 4) & 0x200) != 0) {
        pcVar24 = (char *)GRinqigb();
        if ((pcVar24 == (char *)0x0) || (iVar12 = strcmp(pcVar24,"########"), iVar12 == 0)) {
          Ordinal_69();
        }
        else {
          Ordinal_82(pcVar24);
        }
      }
      GRsetgpd(1);
      if ((*(uint *)Sactions_exref & 0x4000) != 0) {
        if (*(int *)debug_flag_exref != 0) {
          pcVar24 = (char *)GetSorResStringEx(0x1ff);
          FUN_1800282b0(pcVar24);
        }
        uVar11 = FUN_180023310();
        GRsetsbm();
        if (*(int *)partial_results_exref == 0) {
LAB_18002d080:
          if (*(int *)in_canned_exref == 0) {
            *(undefined4 *)triggered_by_canned_exref = 0;
          }
        }
        else {
          if (DAT_180051ff0 != 0) {
            DAT_180051ff0 = 0;
          }
          if (*(int *)partial_results_exref == 0) goto LAB_18002d080;
          if (*(int *)in_canned_exref == 0) {
            HYloohie();
            goto LAB_18002d080;
          }
        }
        if (uVar11 == 0xffffffff) goto LAB_18002cbe2;
      }
      if ((*(uint *)Sactions_exref & 0x6010) != 0) {
        GRsetrpt(0);
      }
      *(undefined4 *)sum_header_exref = 0;
      uVar26 = *(uint *)Sactions_exref;
      if ((uVar26 & 8) != 0) {
        if ((uVar11 < 0xc) && ((0xd90U >> (uVar11 & 0x1f) & 1) != 0)) {
          *(uint *)Sactions_exref = uVar26 & 0x7fffffff;
          *(uint *)Sactions_exref = uVar26 & 0x7fff7fff;
        }
        else {
          uVar11 = FUN_180024de0();
          show_mouse();
          if (uVar11 == 0xffffffff) goto LAB_18002cbe2;
          *(uint *)Sactions_exref = *(uint *)Sactions_exref & 0xfffffff7;
          *(undefined4 *)sum_header_exref = 1;
        }
      }
      if ((*(uint *)Sactions_exref & 0x10000) == 0) {
        iVar15 = 1;
        iVar12 = local_630;
      }
      else {
        if (*(int *)debug_flag_exref != 0) {
          pcVar24 = (char *)GetSorResStringEx(0x200);
          FUN_1800282b0(pcVar24);
        }
        FUN_180019bb0();
        iVar12 = GRinqerr();
        if (iVar12 == 2) {
          local_648 = 1;
          goto LAB_18002d274;
        }
        local_648 = 0;
      }
      if ((((byte)Sactions_exref[4] & 0x40) != 0) &&
         (FUN_180027cb0((char *)param_2), ((byte)*Sactions_exref & 0x10) == 0)) {
        *(uint *)(Sactions_exref + 4) = *(uint *)(Sactions_exref + 4) & 0xffffffbf;
      }
      if (((*(uint *)Sactions_exref & 0x4000) != 0) && (((byte)Sactions_exref[4] & 8) != 0)) {
        local_338[0] = '\0';
        iVar13 = FUN_180019ad0(local_338);
        if (iVar13 == 0) {
          *(uint *)Sactions_exref = *(uint *)Sactions_exref & 0xfffffbff;
          iVar15 = 0;
          local_648 = 0;
          *(uint *)(Sactions_exref + 4) = *(uint *)(Sactions_exref + 4) & 0xfffffff7;
        }
        else {
          *(uint *)(Sactions_exref + 4) = *(uint *)(Sactions_exref + 4) & 0xfffffff7;
          if (iVar13 != -1) {
            if (iVar13 - 7U < 2) {
              iVar12 = SBmoveto(iVar13,local_338);
            }
            if (iVar12 + 1U < 2) goto LAB_18002d274;
          }
        }
      }
      uVar26 = uVar11;
      if ((*(uint *)Sactions_exref & 0x100000) != 0) {
        uVar14 = FUN_180017920();
        if (uVar14 != 0xffffffff) {
          if (uVar14 == 0xfffffffe) {
            uVar16 = 5;
            if ((*(uint *)Sactions_exref & 0x40400) != 0) {
              _guard_check_icall();
              _guard_check_icall();
              _guard_check_icall();
              _guard_check_icall();
              _guard_check_icall();
            }
            goto LAB_18002d274;
          }
          if (uVar14 != 0) {
            uVar26 = uVar14;
          }
          goto LAB_18002d2d6;
        }
LAB_18002d330:
        bVar27 = false;
        uVar16 = uVar11;
        if (uVar11 == 0xffffd8f1) {
          uVar16 = 0xffffffff;
        }
        goto LAB_18002d274;
      }
LAB_18002d2d6:
      if ((*(uint *)Sactions_exref & 0x20000) != 0) {
        uVar11 = SBmoveto(0,(char *)param_2);
        if ((uVar11 != 0) && (uVar26 = uVar11, (int)uVar11 < 0)) goto LAB_18002d330;
      }
      if ((*(uint *)Sactions_exref & 0x800000) != 0) {
        param_4 = (LPCSTR)0x1;
        uVar20 = FUN_180019140((char *)0x0,(char ****)0x0,(char *)0x0,1);
        uVar11 = (uint)uVar20;
        if ((uVar11 != 0) && (uVar26 = uVar11, (int)uVar11 < 0)) goto LAB_18002d330;
      }
      if ((*(uint *)Sactions_exref & 0x20000000) != 0) {
        uVar23 = EXmsgbox();
        uVar11 = (uint)uVar23;
        if ((int)uVar11 < 0) goto LAB_18002d330;
        uVar11 = FUN_180019d90();
        if ((int)uVar11 < 0) {
          uVar16 = uVar11;
          if (uVar11 == 0xffffd8f1) {
            uVar16 = 0xffffffff;
          }
          goto LAB_18002d274;
        }
      }
      uVar11 = uVar26;
      if ((*(uint *)Sactions_exref & 0x40000000) != 0) {
        uVar11 = FUN_180019bd0();
        if ((uVar11 == 0) || (uVar26 = uVar11, -1 < (int)uVar11)) {
          uVar11 = uVar26;
          iVar12 = FUN_180020ec0(*(longlong *)(*(longlong *)topfinfo_exref + 0x560),1);
          if (iVar12 != -1) goto LAB_18002d3a9;
        }
        goto LAB_18002d330;
      }
LAB_18002d3a9:
      if ((*(uint *)Sactions_exref >> 2 & 1) == 0) {
        local_648 = iVar15;
      }
      else {
        uVar11 = 0;
        local_648 = 0;
      }
      if ((*(uint *)Sactions_exref >> 0x12 & 1) != 0) {
        if (*(int *)debug_flag_exref != 0) {
          pcVar24 = (char *)GetSorResStringEx(0x201);
          FUN_1800282b0(pcVar24);
        }
        GRsetust();
        uVar11 = FUN_180024b90();
        if (uVar11 != 0xffffffff) {
          if (*(int *)partial_results_exref == 0) {
            if (uVar11 - 2 < 2) {
              if (((byte)Sactions_exref[4] & 4) == 0) {
                *(uint *)Sactions_exref = *(uint *)Sactions_exref | 0x1000000;
                goto LAB_18002d44e;
              }
              goto LAB_18002d429;
            }
LAB_18002d42e:
            if (uVar11 != 3) goto LAB_18002d44e;
          }
          else {
LAB_18002d429:
            if (uVar11 != 2) goto LAB_18002d42e;
          }
          if (((byte)Sactions_exref[4] & 4) == 0) {
            GRsetsms();
            GRsetust();
          }
          goto LAB_18002d44e;
        }
LAB_18002dc4d:
        uVar16 = uVar11;
        if (uVar11 == 0xffffd8f1) {
          uVar16 = 0xffffffff;
        }
        goto LAB_18002d274;
      }
LAB_18002d44e:
      if ((*(uint *)Sactions_exref & 0x400) != 0) {
        if ((((uVar11 + 1 < 0x18) && ((0x840045U >> (uVar11 + 1 & 0x1f) & 1) != 0)) ||
            (uVar11 == 0xffffd8f1)) ||
           ((uVar11 - 2 < 2 && (iVar15 = GRstratchanged(), iVar15 != 0)))) {
          GRsetust();
          if (*(int *)debug_flag_exref != 0) {
            pcVar24 = (char *)GetSorResStringEx(0x202);
            FUN_1800282b0(pcVar24);
          }
          uVar11 = FUN_180023680();
          bVar10 = true;
          show_mouse();
          if (uVar11 == 0xffffffff) goto LAB_18002dc4d;
        }
        if (*(int *)partial_results_exref == 0) {
          if (uVar11 - 2 < 2) {
            if (((byte)Sactions_exref[4] & 4) == 0) {
              *(uint *)Sactions_exref = *(uint *)Sactions_exref | 0x1000000;
              goto LAB_18002d50a;
            }
            goto LAB_18002d4ec;
          }
LAB_18002d4f1:
          if (uVar11 != 3) goto LAB_18002d50a;
        }
        else {
LAB_18002d4ec:
          if (uVar11 != 2) goto LAB_18002d4f1;
        }
        if (((byte)Sactions_exref[4] & 4) == 0) {
          GRsetsms();
        }
      }
LAB_18002d50a:
      if (uVar11 == 0xffffffff) {
LAB_18002d607:
        if (((*(uint *)(Sactions_exref + 4) & 0x40000) != 0) && (iVar15 = GRinqust(), iVar15 == 0))
        goto LAB_18002d619;
      }
      else {
        if (((*(uint *)(Sactions_exref + 4) & 0x2000) != 0) && (iVar15 = GRinqust(), iVar15 == 0)) {
          if (bVar10) {
            if (((*(uint *)Sactions_exref & 0x1000000) != 0) &&
               ((0xb < uVar11 || ((0xd90U >> (uVar11 & 0x1f) & 1) == 0)))) {
              iVar15 = MVGetProductCode();
              if (iVar15 == 2) {
                uVar11 = SBrepall();
              }
              else {
                uVar11 = SBrepsum();
              }
              show_mouse();
              if (uVar11 == 0xffffffff) goto LAB_18002dc4d;
              bVar7 = false;
              local_648 = 2;
            }
            if ((((byte)Sactions_exref[4] & 4) != 0) &&
               (((0xb < uVar11 || ((0xd90U >> (uVar11 & 0x1f) & 1) == 0)) &&
                (*(int *)partial_results_exref == 0)))) {
              uVar11 = SBrepall();
              show_mouse();
              if (uVar11 == 0xffffffff) goto LAB_18002d330;
              local_648 = 2;
              bVar7 = false;
            }
          }
          uVar11 = FUN_18002fcc0((char *)0x0);
          if (uVar11 == 0xffffffff) goto LAB_18002d607;
        }
        if ((*(uint *)(Sactions_exref + 4) & 0x1000) == 0) goto LAB_18002d607;
LAB_18002d619:
        iVar15 = SimEOCommand((char *)param_2);
        uVar11 = 2;
        if (iVar15 != 1) {
          uVar11 = 0xffffffff;
        }
        if (DAT_180051c10 == 0) {
          bVar7 = false;
        }
        else {
          DAT_180051ff4 = 1;
          bVar7 = true;
        }
      }
      if (((uVar11 != 0xffffffff) && ((*(uint *)(Sactions_exref + 4) & 0x4000) != 0)) &&
         (iVar15 = GRinqust(), iVar15 == 0)) {
        FUN_18002f750((char *)param_2);
      }
      if (bVar7) {
        bVar27 = *(int *)partial_results_exref != 0;
        if (((*(uint *)Sactions_exref & 0x1000000) != 0) &&
           ((0xb < uVar11 || ((0xd90U >> (uVar11 & 0x1f) & 1) == 0)))) {
          iVar15 = MVGetProductCode();
          if ((iVar15 == 2) || (*(int *)(*(longlong *)topfinfo_exref + 0x380) == 0x2d9)) {
            uVar11 = SBrepall();
          }
          else {
            uVar11 = SBrepsum();
          }
          show_mouse();
          bVar27 = false;
          if (uVar11 == 0xffffffff) goto LAB_18002d330;
        }
        if ((((byte)Sactions_exref[4] & 4) != 0) &&
           (((0xb < uVar11 || ((0xd90U >> (uVar11 & 0x1f) & 1) == 0)) &&
            (*(int *)partial_results_exref == 0)))) {
          uVar11 = SBrepall();
          show_mouse();
          bVar27 = false;
          if (uVar11 == 0xffffffff) goto LAB_18002d330;
        }
        local_648 = 2;
      }
      if (((byte)Sactions_exref[4] & 1) == 0) {
LAB_18002d788:
        if (((*(uint *)Sactions_exref & 0x800) != 0) &&
           ((0xb < uVar11 || ((0xd90U >> (uVar11 & 0x1f) & 1) == 0)))) {
          if ((param_2 == (uchar *)0x0) || (*param_2 == '\0')) {
            uVar23 = 0x204;
          }
          else {
            uVar23 = FUN_180023a50();
            uVar11 = (uint)uVar23;
            HYloohie();
            show_mouse();
            if (uVar11 == 0xffffffff) goto LAB_18002cbe5;
            FUN_180008f80(local_438,"%s.rp1",APtmpfil_exref,param_4);
            name_lwr(local_438);
            FUN_180008f80(local_3b8,"%s.rp2",APtmpfil_exref,param_4);
            name_lwr(local_3b8);
            if ((*(int *)(*(longlong *)SBdataptr_exref + 0x1214) == 0) ||
               ((iVar15 = FUN_18002b2c0((char *)local_438,local_438,
                                        (undefined1 *)(*(longlong *)SBdataptr_exref + 0x10)),
                iVar15 == 0 &&
                (iVar15 = FUN_18002b2c0((char *)local_3b8,local_3b8,
                                        (undefined1 *)(*(longlong *)SBdataptr_exref + 0x10)),
                iVar15 != -1)))) {
              _File = fopen((char *)local_438,"r");
              if (_File != (FILE *)0x0) {
                _File_00 = fopen((char *)local_3b8,"r");
                if (_File_00 == (FILE *)0x0) {
                  pcVar24 = (char *)GetSorResStringEx(0x205);
                  FUN_180028530(pcVar24,-1);
                  fclose(_File);
                  uVar16 = uVar11;
                  if (uVar11 == 0xffffd8f1) {
                    uVar16 = 0xffffffff;
                  }
                  goto LAB_18002d274;
                }
                _File_01 = fopen((char *)param_2,"w");
                if (_File_01 != (FILE *)0x0) {
                  pcVar24 = fgets(local_298,0x78,_File);
                  while (pcVar24 != (char *)0x0) {
                    fputs(pcVar24,_File_01);
                    pcVar24 = fgets(local_298,0x78,_File);
                  }
                  pcVar24 = fgets(local_298,0x78,_File_00);
                  while (pcVar24 != (char *)0x0) {
                    fputs(pcVar24,_File_01);
                    pcVar24 = fgets(local_298,0x78,_File_00);
                  }
                  fclose(_File_01);
                  fclose(_File);
                  fclose(_File_00);
                  if (*(int *)(*(longlong *)SBdataptr_exref + 0x1214) != 0) {
                    remove((char *)local_438);
                    remove((char *)local_3b8);
                  }
                  lVar22 = -1;
                  do {
                    lVar21 = lVar22;
                    lVar22 = lVar21 + 1;
                  } while ((&DAT_180052cf1)[lVar21] != '\0');
                  if (0x77 < lVar21 - 3U) {
                    /* WARNING: Subroutine does not return */
                    FUN_18003b6e4();
                  }
                  *(undefined1 *)(lVar21 + 0x180052ced) = 0;
                  check_reportoption();
                  goto LAB_18002da17;
                }
                goto LAB_18002cbe5;
              }
              uVar23 = 0x205;
            }
            else {
              uVar23 = 0x1f1;
            }
          }
          pcVar24 = (char *)GetSorResStringEx(uVar23);
          FUN_180028530(pcVar24,-1);
          uVar16 = uVar11;
          if (uVar11 == 0xffffd8f1) {
            uVar16 = 0xffffffff;
          }
          goto LAB_18002d274;
        }
LAB_18002da17:
        if ((((int)*(uint *)Sactions_exref < 0) && (((byte)Sactions_exref[4] & 1) == 0)) ||
           ((*(uint *)Sactions_exref >> 0xf & 1) != 0)) {
          FUN_180016340(param_2,0);
          bVar8 = true;
        }
        if (((int)*(uint *)Sactions_exref < 0) && (((byte)Sactions_exref[4] & 1) == 0)) {
          if ((*(uint *)Sactions_exref >> 0xf & 1) != 0) {
            *(undefined4 *)replacing_results_exref = 1;
          }
          if (*(int *)debug_flag_exref != 0) {
            pcVar24 = (char *)GetSorResStringEx(0x206);
            FUN_1800282b0(pcVar24);
          }
          iVar15 = OPpurout();
          *(undefined4 *)replacing_results_exref = 0;
          show_mouse();
          if (iVar15 == -1) goto LAB_18002d274;
        }
        if ((*(uint *)Sactions_exref >> 0xf & 1) != 0) {
          if (((*(uint *)Sactions_exref >> 0x18 & 1) == 0) || (*(int *)partial_results_exref == 0))
          {
            if (*(int *)in_canned_exref == 0) {
              *(undefined4 *)sum_header_exref = 1;
            }
            FUN_18002c620((longlong)APtmpfil_exref);
          }
          else {
            *(undefined4 *)partial_results_exref = 0;
            FUN_18001b6d0();
            FUN_18002c620((longlong)APtmpfil_exref);
            *(undefined4 *)partial_results_exref = 1;
            pcVar24 = getenv("SAVESUM");
            if (pcVar24 == (char *)0x0) {
              iVar15 = MVGetProductCode();
              param_4 = ".aprsum";
              if (iVar15 == 1) {
                param_4 = ".sum";
              }
              FUN_180008f80(local_148,&DAT_18003f9b0,APtmpfil_exref,param_4);
              remove(local_148);
            }
            *(undefined4 *)sum_header_exref = 1;
            uVar11 = FUN_180024de0();
            if (uVar11 == 0xffffffff) {
              OPpurout();
              *(undefined4 *)sum_header_exref = 0;
            }
            else {
              FUN_18002c620((longlong)APtmpfil_exref);
              *(undefined4 *)sum_header_exref = 0;
            }
          }
          *(uint *)Sactions_exref = *(uint *)Sactions_exref & 0xfeffffff;
          if (*(int *)sum_header_exref != 0) {
            *(undefined4 *)sum_header_exref = 0;
            uVar16 = uVar11;
            if (uVar11 == 0xffffd8f1) {
              uVar16 = 0xffffffff;
            }
            goto LAB_18002d274;
          }
        }
      }
      else {
        if (*(int *)debug_flag_exref != 0) {
          pcVar24 = (char *)GetSorResStringEx(0x203);
          FUN_1800282b0(pcVar24);
        }
        uVar20 = FUN_180036b00();
        uVar11 = (uint)uVar20;
        show_mouse();
        if (uVar11 != 0xffffffff) goto LAB_18002d788;
      }
    }
    else {
      SBfaksim(0,puVar19,pcVar24,param_4);
      HYloohie();
      show_mouse();
LAB_18002cbe2:
      local_648 = 1;
    }
LAB_18002cbe5:
    uVar16 = uVar11;
    if (uVar11 == 0xffffd8f1) {
      uVar16 = 0xffffffff;
    }
  }
  else {
    if (*(int *)debug_flag_exref != 0) {
      pcVar18 = (char *)GetSorResStringEx(0x1f7);
      FUN_1800282b0(pcVar18);
    }
    if (iVar15 == 0) goto LAB_18002cd23;
    FUN_180008f80(local_4c8,"%s.inm",APtmpfil_exref,param_4);
    name_lwr(local_4c8);
    FUN_180025fb0((char *)0x0,(char *)local_4c8);
    puVar19 = local_4c8;
    pcVar24 = (char *)(*(longlong *)SBdataptr_exref + 0x10);
    iVar12 = FUN_18002b360((char *)local_4c8,(char *)puVar19,pcVar24);
    if (iVar12 == 0) goto LAB_18002cd23;
    pcVar24 = (char *)GetSorResStringEx(0x1f8);
    FUN_180028530(pcVar24,-1);
    local_648 = 1;
  }
LAB_18002d274:
  FUN_1800187d0();
  EOClearError();
  if (DAT_180052ce0 == 0) {
    iVar15 = EOInqError();
    DAT_180052ce0 = (uint)(iVar15 != 6);
  }
  if (*(int *)prop_retrieve_results_exref != 0) {
    *(undefined4 *)prop_retrieve_results_exref = 0;
  }
  if (*(int *)sum_header_exref != 0) {
    *(undefined4 *)sum_header_exref = 0;
  }
  if ((*(uint *)Sactions_exref & 0x20000000) != 0) {
    _guard_check_icall();
  }
  *(undefined4 *)partial_results_exref = uVar17;
  bVar10 = FUN_180025320();
  if ((((int)CONCAT71(extraout_var_00,bVar10) != 0) && (lVar22 = GRchkitm(), lVar22 != 0)) &&
     ((*(uint *)Sactions_exref & 0x40000) != 0)) {
    hide_mouse();
    _guard_check_icall();
    show_mouse();
  }
  if (uVar16 == 0xffffffff) goto LAB_18002dd2c;
  if (((*(uint *)Sactions_exref & 0x40000) == 0) && (iVar15 = GRinqust(), iVar15 == 0)) {
    if (uVar16 == 1) {
      lVar22 = GRinqnxt();
      if (lVar22 == 0) goto LAB_18002dd2c;
      goto LAB_18002dd37;
    }
    if (uVar16 != 5) {
      if (1 < uVar16 - 2) goto LAB_18002dd2c;
      goto LAB_18002dd37;
    }
    lVar22 = GRinqexc();
    if (lVar22 != 0) goto LAB_18002dd37;
LAB_18002dd2c:
    if (bVar27) goto LAB_18002dd37;
LAB_18002deb7:
    if (uVar16 != 0xffffffff) {
LAB_18002debd:
      if ((*(uint *)(Sactions_exref + 4) & 0x20000) != 0) {
        uVar17 = GRinqinmt();
        GRsetinmt(0);
        GRSetIsSbSimYesNoDlgRaised(1);
        pfs_update_tables(1);
        GRSetIsSbSimYesNoDlgRaised(0);
        GRsetssm(1);
        GRsetinmt(uVar17);
      }
    }
  }
  else {
LAB_18002dd37:
    if (!bVar8) {
      FUN_180016340(param_2,0);
      bVar8 = true;
    }
    if (*(int *)partial_results_exref == 0) {
      param_4 = (LPCSTR)0x1c000000;
      iVar15 = FUN_180030240((char *)0x0,local_5f8,0,0x1c000000,(char *)0x0);
      if (iVar15 != -1) {
        hide_mouse();
        HYloohie();
        show_mouse();
      }
      if (*(int *)partial_results_exref == 0) goto LAB_18002deb7;
    }
    if (((byte)Sactions_exref[4] & 0x10) == 0) goto LAB_18002deb7;
    param_4 = (LPCSTR)0x1c000000;
    uVar16 = FUN_180030240((char *)0x0,local_5f8,0,0x1c000000,(char *)0x0);
    uVar23 = HYPshFinfo(1);
    HACxsReflect(0,0,0);
    HYPopFinfo(uVar23);
    if (uVar16 != 0xffffffff) {
      lVar22 = *(longlong *)topfinfo_exref;
      uVar3 = *(undefined8 *)(lVar22 + 0x5a0);
      uVar4 = *(undefined8 *)(lVar22 + 0x5a8);
      uVar2 = *(undefined8 *)(lVar22 + 0x5d0);
      uVar23 = *(undefined8 *)(lVar22 + 0x5b0);
      uVar5 = *(undefined8 *)(lVar22 + 0x5b8);
      uVar6 = *(undefined8 *)(lVar22 + 0x5c0);
      uVar25 = *(undefined8 *)(lVar22 + 0x5c8);
      hide_mouse();
      HYloohie(&DAT_18003ae52);
      lVar22 = *(longlong *)topfinfo_exref;
      *(undefined8 *)(lVar22 + 0x5a0) = uVar3;
      *(undefined8 *)(lVar22 + 0x5a8) = uVar4;
      *(undefined8 *)(lVar22 + 0x5b0) = uVar23;
      lVar22 = *(longlong *)topfinfo_exref;
      *(undefined8 *)(lVar22 + 0x5b8) = uVar5;
      *(undefined8 *)(lVar22 + 0x5c0) = uVar6;
      *(undefined8 *)(lVar22 + 0x5c8) = uVar25;
      *(undefined8 *)(*(longlong *)topfinfo_exref + 0x5d0) = uVar2;
      show_mouse();
      goto LAB_18002debd;
    }
  }
  lVar22 = GRinqexc();
  if (lVar22 == 0) {
    if ((uVar16 != 1) || (lVar22 = GRinqnxt(), lVar22 == 0)) goto LAB_18002dffc;
    if (local_648 != 2) {
      uVar23 = GRinqnxt();
      uVar25 = GetSorResStringEx(0x209);
      FUN_180008f80(local_218,uVar25,uVar23,param_4);
      GRsetrdy(1);
      FUN_1800281c0(local_218);
      goto LAB_18002e006;
    }
  }
  else {
    if (uVar16 != 0xffffffff) {
      pcVar24 = (char *)GRinqexc();
      lVar22 = -(longlong)pcVar24;
      do {
        cVar1 = *pcVar24;
        pcVar24[(longlong)(local_2e8 + lVar22)] = cVar1;
        pcVar24 = pcVar24 + 1;
      } while (cVar1 != '\0');
      pcVar24 = strchr(local_2e8,0x20);
      if (pcVar24 != (char *)0x0) {
        *pcVar24 = '\0';
      }
      GetSorResStringEx(0x208);
      uVar23 = GetSorResStringEx(0x207);
      FUN_180008f80(local_218,"%s %s %s",uVar23,local_2e8);
      GRsetrdy(5);
      FUN_1800281c0(local_218);
      goto LAB_18002e006;
    }
LAB_18002dffc:
    if (local_648 == 0) goto LAB_18002e006;
  }
  pfs_refresh_status();
LAB_18002e006:
  if (bVar8) {
    FUN_180016010(param_2,0);
  }
  return local_630;
}

