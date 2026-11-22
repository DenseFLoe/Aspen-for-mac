/* RVA 0x19900 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_180019900(undefined8 param_1,int param_2,int param_3,char *param_4)

{
  char cVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  char **ppcVar5;
  undefined1 auStackY_1a8 [32];
  char *local_178 [2];
  char local_168 [8];
  undefined4 local_160;
  char *local_58;
  undefined1 local_50;
  ulonglong local_38;
  
  local_38 = DAT_1800516d8 ^ (ulonglong)auStackY_1a8;
  if ((DAT_180052ec4 != 0) && (iVar2 = GRinqiap(), iVar2 != 0)) {
    uVar4 = ((longlong)param_2 | 0xc00U) << 8;
    if (param_3 < 1) {
      uVar4 = ((longlong)(0x80 - param_3) | uVar4) << 8;
    }
    else {
      uVar4 = ((longlong)param_3 | uVar4) << 8 | 0xff;
    }
    ppcVar5 = local_178;
    FUN_180018800(param_4,ppcVar5);
    if (local_178[0] != (char *)0x0) {
      ppcVar5 = (char **)((longlong)&local_58 - (longlong)local_178[0]);
      do {
        cVar1 = *local_178[0];
        *(char *)((longlong)ppcVar5 + (longlong)local_178[0]) = cVar1;
        local_178[0] = local_178[0] + 1;
      } while (cVar1 != '\0');
    }
    iVar2 = 0;
    lVar3 = 0;
    do {
      if (*(char *)((longlong)&local_58 + lVar3) == '\0') {
        if (iVar2 < 8) {
          memset((void *)((longlong)&local_58 + (longlong)iVar2),
                 (int)CONCAT71((int7)((ulonglong)ppcVar5 >> 8),0x20),(longlong)(8 - iVar2));
        }
        break;
      }
      iVar2 = iVar2 + 1;
      lVar3 = lVar3 + 1;
    } while (lVar3 < 8);
    local_50 = 0;
    iVar2 = FUN_180030240((char *)0x0,local_168,0,uVar4,(char *)&local_58);
    if (iVar2 != 0) {
      _guard_check_icall();
      switch(local_160) {
      case 4:
      case 6:
      case 7:
      case 8:
      case 10:
      case 0xb:
      case 0xd:
      case 0xe:
      case 0xf:
      case 0x10:
        GRsetust(0);
        break;
      default:
        show_mouse();
        return local_160;
      }
    }
  }
  return 0xffffffff;
}

/* RVA 0x19ad0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_180019ad0(LPCSTR param_1)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  char *pcVar6;
  char *pcVar7;
  undefined1 auStack_148 [31];
  undefined4 uStack_129;
  undefined1 local_124 [268];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_148;
  pcVar7 = (char *)((longlong)&uStack_129 + 1);
  pcVar6 = *(char **)topfinfo_exref;
  do {
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    *pcVar7 = cVar1;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  puVar2 = &uStack_129;
  do {
    puVar5 = puVar2;
    puVar2 = (undefined4 *)((longlong)puVar5 + 1);
  } while (*(char *)((longlong)puVar5 + 1) != '\0');
  *(undefined4 *)((longlong)puVar5 + 1) = DAT_1800410f8;
  *(undefined1 *)((longlong)puVar5 + 5) = DAT_1800410fc;
  _mbslwr((uchar *)((longlong)&uStack_129 + 1));
  iVar3 = WPFSimAskReexecuteFortran((LPCSTR)((longlong)&uStack_129 + 1),param_1);
  remove((char *)((longlong)&uStack_129 + 1));
  DAT_180052d70 = 0;
  iVar4 = 0;
  if ((iVar3 != 0) && (iVar4 = 0, param_1 != (LPCSTR)0x0)) {
    iVar4 = iVar3;
  }
  return iVar4;
}

/* RVA 0x19bb0 */
void FUN_180019bb0(void)

{
  int local_res8 [8];
  
  FUN_180019cb0(local_res8);
  return;
}

/* RVA 0x19bd0 */
void FUN_180019bd0(void)

{
  FUN_180021fd0(*(longlong *)(*(longlong *)topfinfo_exref + 0x560));
  return;
}

/* RVA 0x19bf0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_180019bf0(char *param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  undefined1 auStackY_158 [32];
  char local_128 [272];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStackY_158;
  if ((DAT_180052ec4 == 0) || (iVar1 = GRinqiap(), iVar1 == 0)) {
    return -1;
  }
  pcVar2 = "";
  if (param_1 != (char *)0x0) {
    pcVar2 = param_1;
  }
  SBsetscp(pcVar2);
  DAT_180050de4 = 0;
  iVar1 = FUN_180030240((char *)0x0,local_128,0,0xa030000,(char *)0x0);
  if ((iVar1 != -1) && (param_2 != 0)) {
    iVar1 = FUN_180030240((char *)0x0,local_128,0,0xa040000,(char *)0x0);
  }
  DAT_180050de4 = 1;
  return iVar1;
}

/* RVA 0x19cb0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

char * FUN_180019cb0(int *param_1)

{
  int iVar1;
  char *pcVar2;
  undefined1 auStackY_158 [32];
  char local_128 [8];
  undefined4 local_120;
  undefined1 local_11c [260];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStackY_158;
  iVar1 = FUN_180030240((char *)0x0,local_128,0,0xa020000,(char *)0x0);
  *param_1 = iVar1;
  if (iVar1 != 0) {
    switch(local_120) {
    case 1:
    case 5:
      pcVar2 = FUN_18002f550(&DAT_180051f80,(longlong)local_11c);
      return pcVar2;
    case 4:
    case 6:
    case 7:
    case 8:
    case 10:
    case 0xb:
    case 0xd:
    case 0xe:
    case 0xf:
    case 0x10:
      *param_1 = 0;
    }
  }
  return (char *)0x0;
}

/* RVA 0x19d90 */
undefined4 FUN_180019d90(void)

{
  int iVar1;
  
  if (DAT_180052ec4 != 0) {
    iVar1 = GRinqiap();
    if (iVar1 != 0) {
      DAT_180051fd0 = 0;
      HYloohie(FUN_180019de0);
      return DAT_180051fd0;
    }
  }
  return 0xffffffff;
}

/* RVA 0x19de0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180019de0(void)

{
  int iVar1;
  undefined1 auStackY_1c8 [32];
  undefined8 local_198;
  undefined8 local_190;
  undefined8 local_188;
  undefined8 uStack_180;
  char local_178 [272];
  char local_68 [80];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStackY_1c8;
  local_198 = *(undefined8 *)(*(longlong *)finfo_exref + 0x698);
  local_190 = *(undefined8 *)(*(longlong *)finfo_exref + 0x690);
  local_188 = 0;
  uStack_180 = 0;
  if (-1 < DAT_180051fd0) {
    HYdspnam(&local_198,&local_188,local_68,0x4a);
    SBsetscp(local_68);
    DAT_180050de4 = 0;
    iVar1 = FUN_180030240((char *)0x0,local_178,0,0xa010000,(char *)0x0);
    DAT_180050de4 = 1;
    if (iVar1 == 0) {
      DAT_180051fd0 = -1;
    }
  }
  return;
}

/* RVA 0x19eb0 */
void FUN_180019eb0(longlong param_1,undefined8 param_2)

{
  undefined8 uVar1;
  longlong lVar2;
  
  uVar1 = MDfndkey(*(undefined8 *)iwpfile_exref,*(undefined8 *)(param_1 + 0xf8),1,param_2);
  *(undefined8 *)(param_1 + 0xf0) = uVar1;
  if (*(longlong *)MDerror_exref != 0) {
    ERclear(0);
    *(undefined8 *)(param_1 + 0xf0) = 0;
    return;
  }
  lVar2 = MDrslcls(*(undefined8 *)iwpfile_exref,*(undefined8 *)(param_1 + 0xf8));
  lVar2 = lVar2 + *(longlong *)(param_1 + 0xf0) * 0x108;
  if (*(char *)(lVar2 + 0x107) == '\b') {
    *(undefined8 *)(param_1 + 0xf0) = *(undefined8 *)(lVar2 + 0x30);
    *(undefined8 *)(param_1 + 0xf8) = *(undefined8 *)(lVar2 + 0x28);
  }
  return;
}

/* RVA 0x19f50 */
char * FUN_180019f50(char *param_1,int param_2)

{
  char *pcVar1;
  
  pcVar1 = strchr(param_1,param_2);
  if (pcVar1 != (char *)0x0) {
    *pcVar1 = '\0';
    pcVar1 = pcVar1 + 1;
  }
  return pcVar1;
}

/* RVA 0x19f70 */
void FUN_180019f70(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  undefined8 local_res10;
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res10 = param_2;
  local_res18 = param_3;
  local_res20 = param_4;
  uVar1 = __acrt_iob_func(1);
  puVar2 = (undefined8 *)FUN_180001b20();
  __stdio_common_vfprintf(*puVar2,uVar1,param_1,0,&local_res10);
  return;
}

/* RVA 0x19fd0 */
undefined * FUN_180019fd0(void)

{
  return commsect_exref;
}

/* RVA 0x19fe0 */
int FUN_180019fe0(uint param_1,undefined8 *param_2,longlong *param_3,uint *param_4,uint *param_5)

{
  int iVar1;
  char *_Str1;
  
  if (param_1 == 0xffffffff) {
    DAT_180051fe0 = SBcntcsect();
    if (DAT_180051fe0 == 0) {
      return -1;
    }
    if (DAT_180051fe8 != (void *)0x0) {
      free(DAT_180051fe8);
      DAT_180051fe8 = (void *)0x0;
    }
    DAT_180051fe8 = malloc((longlong)DAT_180051fe0 * 0x32);
    if (DAT_180051fe8 == (void *)0x0) {
      return -1;
    }
    iVar1 = SBreacsect(DAT_180051fe8);
    if (iVar1 != 0) {
      free(DAT_180051fe8);
      return -1;
    }
    param_1 = 0;
  }
  else if (param_1 == 0xfffffffe) {
    if (DAT_180051fe8 == (void *)0x0) {
      return -1;
    }
    free(DAT_180051fe8);
    DAT_180051fe8 = (void *)0x0;
    return -1;
  }
  if (DAT_180051fe0 <= (int)param_1) {
    return -1;
  }
  _Str1 = (char *)((longlong)(int)param_1 * 0x32 + (longlong)DAT_180051fe8);
  if (param_2 != (undefined8 *)0x0) {
    *param_2 = _Str1;
  }
  if (param_3 != (longlong *)0x0) {
    *param_3 = (longlong)(_Str1 + 9);
  }
  if (param_4 != (uint *)0x0) {
    iVar1 = _stricmp(_Str1,(char *)commsect_exref);
    *param_4 = (uint)(iVar1 == 0);
  }
  if (param_5 != (uint *)0x0) {
    *param_5 = (uint)((*(uint *)(submitdata_exref + 0x1470) >> (param_1 & 0x1f) & 1) != 0);
  }
  return param_1 + 1;
}

/* RVA 0x1a130 */
longlong FUN_18001a130(void)

{
  return *(longlong *)SBdataptr_exref + 0x10;
}

/* RVA 0x1a140 */
void FUN_18001a140(undefined8 param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  puVar2 = (undefined8 *)MDcalloc(0x10);
  puVar1 = puVar2;
  *puVar2 = DAT_180052000;
  DAT_180052000 = puVar1;
  puVar2[1] = param_1;
  return;
}

/* RVA 0x1a180 */
void FUN_18001a180(void)

{
  undefined8 *puVar1;
  
  puVar1 = DAT_180052000;
  while (puVar1 != (undefined8 *)0x0) {
    puVar1 = (undefined8 *)*puVar1;
    MDfree();
  }
  DAT_180052000 = (undefined8 *)0x0;
  return;
}

/* RVA 0x1a1c0 */
undefined8 FUN_18001a1c0(longlong param_1)

{
  undefined8 *puVar1;
  
  puVar1 = DAT_180052000;
  while( true ) {
    if (puVar1 == (undefined8 *)0x0) {
      return 0;
    }
    if (puVar1[1] == param_1) break;
    puVar1 = (undefined8 *)*puVar1;
  }
  return 1;
}

/* RVA 0x1a1f0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int SBDumpBlockXML(char *param_1)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  longlong lVar4;
  undefined8 uVar5;
  size_t sVar6;
  size_t _Size;
  undefined1 auStackY_e98 [32];
  char *local_e68 [2];
  undefined1 local_e58 [8];
  char *local_e50;
  char *local_e48;
  char *local_e40;
  char acStack_dc0 [96];
  undefined8 local_d60;
  undefined1 local_d58 [3056];
  undefined1 local_168 [8];
  undefined8 local_160;
  char local_158 [272];
  char local_48 [24];
  char local_30 [24];
  ulonglong local_18;
  
                    /* 0x1a1f0  173  SBDumpBlockXML */
  local_18 = DAT_1800516d8 ^ (ulonglong)auStackY_e98;
  uVar5 = 1;
  iVar3 = GRinqiap();
  if ((iVar3 != 1) || (iVar3 = GRinqcnn(), iVar3 != 2)) {
    return 0;
  }
  FUN_180018800(param_1,local_e68);
  lVar4 = -(longlong)local_e68[0];
  do {
    cVar2 = *local_e68[0];
    local_e68[0][(longlong)(local_48 + lVar4)] = cVar2;
    local_e68[0] = local_e68[0] + 1;
  } while (cVar2 != '\0');
  builtin_strncpy(local_30,"        ",9);
  sVar6 = 0xffffffffffffffff;
  do {
    _Size = sVar6 + 1;
    lVar4 = sVar6 + 1;
    sVar6 = _Size;
  } while (local_48[lVar4] != '\0');
  memcpy(local_30,local_48,_Size);
  local_e68[0] = (char *)GRinqscp();
  if (local_e68[0] != (char *)0x0) {
    iVar3 = HYrslhie(local_e68[0],&DAT_18003fa80,&local_160,local_168);
    if (iVar3 == 0) {
      return 0;
    }
    uVar5 = HYGetFinfoCls(local_160);
  }
  uVar5 = HYPshFinfo(uVar5);
  memset(local_e58,0,0xf8);
  memset(local_d58,0,0xbf0);
  local_d60 = *(undefined8 *)(*(longlong *)finfo_exref + 0x1b8);
  FUN_180019eb0((longlong)local_e58,local_48);
  lVar4 = 0;
  do {
    pcVar1 = local_48 + lVar4;
    acStack_dc0[lVar4] = *pcVar1;
    lVar4 = lVar4 + 1;
  } while (*pcVar1 != '\0');
  local_e50 = "RECDEF";
  local_e48 = "BLOCK";
  local_e40 = local_48;
  MDrslcls(*(undefined8 *)iwpfile_exref,local_d60);
  SBsetscp((char *)0x0);
  iVar3 = FUN_180030240((char *)0x0,local_158,0,0x1b81ff00,local_30);
  HYPopFinfo(uVar5);
  return iVar3;
}

/* RVA 0x1a410 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00018001c379) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
thunk_FUN_18001b720(int *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  byte *pbVar1;
  undefined1 auVar2 [16];
  char cVar3;
  int iVar4;
  longlong lVar5;
  longlong lVar6;
  char *pcVar7;
  uint *puVar8;
  byte *pbVar9;
  longlong *plVar10;
  longlong *plVar11;
  undefined8 uVar12;
  longlong lVar13;
  longlong lVar14;
  undefined1 *puVar15;
  uint uVar16;
  undefined8 uVar17;
  char *pcVar18;
  undefined8 uVar19;
  ulonglong uVar20;
  char *pcVar21;
  bool bVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  undefined1 auStackY_2f8 [32];
  longlong lStack_2c8;
  undefined8 uStack_2b8;
  undefined4 uStack_2b0;
  undefined4 uStack_2ac;
  char acStack_268 [8];
  int iStack_260;
  int iStack_258;
  int iStack_254;
  undefined8 uStack_158;
  ushort uStack_150;
  undefined1 uStack_149;
  char acStack_148 [256];
  ulonglong uStack_48;
  
  auVar2 = _uStack_2b8;
  uStack_48 = DAT_1800516d8 ^ (ulonglong)auStackY_2f8;
  uStack_150 = 0;
  lStack_2c8 = 0;
  uVar12 = 1;
  if (DAT_180051ff0 != 0) {
    return 0;
  }
  if (*(int *)in_rename_exref != 0) {
    return 0;
  }
  uStack_158 = 0x2020202020202020;
  strncpy((char *)&uStack_158,(char *)(param_1 + 0x26),8);
  lVar5 = MDrslcls(*(undefined8 *)iwpfile_exref,*(undefined8 *)(param_1 + 0x3e));
  if (*(longlong *)(param_1 + 0x3c) == 0) {
    uStack_2b8 = (char *)0x0;
    uVar23 = 0;
    uVar24 = 0;
    uStack_2b0 = auVar2._8_4_;
    uStack_2ac = auVar2._12_4_;
  }
  else {
    auVar2 = *(undefined1 (*) [16])(param_1 + 0x3c);
    uStack_2b8._0_4_ = auVar2._0_4_;
    uStack_2b8._4_4_ = auVar2._4_4_;
    uStack_2b0 = auVar2._8_4_;
    uStack_2ac = auVar2._12_4_;
    lVar6 = *(longlong *)(param_1 + 0x3c) * 0x108;
    uVar19 = auVar2._0_8_;
    if (*(char *)(lVar6 + 0x107 + lVar5) == '\b') {
      uVar17 = *(undefined8 *)(lVar6 + 0x28 + lVar5);
      uVar19 = *(undefined8 *)(lVar6 + 0x30 + lVar5);
      uStack_2b8._0_4_ = (undefined4)uVar19;
      uStack_2b8._4_4_ = (undefined4)((ulonglong)uVar19 >> 0x20);
      uStack_2b0 = (undefined4)uVar17;
      uStack_2ac = (undefined4)((ulonglong)uVar17 >> 0x20);
    }
    else {
      uVar17 = *(undefined8 *)(param_1 + 0x3e);
    }
    lVar5 = MDgetito(*(undefined8 *)iwpfile_exref,uVar17,uVar19);
    if ((*(byte *)(lVar5 + 0x120) & 4) != 0) {
      return 0;
    }
    pcVar7 = (char *)MDgethkp(*(undefined8 *)iwpfile_exref,uVar17,uVar19);
    if ((((*(uint *)(pcVar7 + 0x18) & 0x1000) == 0) && (*pcVar7 != '$')) &&
       (lVar5 = MDgethkp(*(undefined8 *)recfile_exref,*(undefined8 *)(lVar5 + 0x20),
                         *(undefined8 *)(lVar5 + 0x18)), (*(uint *)(lVar5 + 0x18) & 0x4000) == 0)) {
      return 0;
    }
    uVar23 = (undefined4)uStack_2b8;
    uVar24 = uStack_2b8._4_4_;
    uStack_2b8 = pcVar7;
  }
  if (*param_1 == 2) {
    lVar5 = 0;
    do {
      lVar6 = lVar5 + 1;
      if (*(char *)(*(longlong *)(param_1 + 4) + lVar5) != "BLOCK"[lVar5]) goto LAB_18001b8eb;
      lVar5 = lVar6;
    } while (lVar6 != 6);
    iVar4 = strcmp(*(char **)(param_1 + 6),"HIERARCHY");
    if (iVar4 == 0) {
      return 0;
    }
  }
LAB_18001b8eb:
  iVar4 = GRinqiap();
  if (iVar4 != 1) {
    return 0;
  }
  iVar4 = GRinqcnn();
  if (iVar4 != 2) {
    return 0;
  }
  pcVar7 = *(char **)(param_1 + 0x3e);
  if (((pcVar7 != (char *)0x0) && (lVar5 = MDgetde(), lVar5 != 0)) &&
     ((*(longlong *)(lVar5 + 0x78) != 0 &&
      (pcVar7 = *(char **)(lVar5 + 0x70), pcVar7 != (char *)0x0)))) {
    HYGetFinfoCls();
    lStack_2c8 = HYPshFinfo();
  }
  SBsetscp((char *)0x0);
  pcVar18 = *(char **)(param_1 + 4);
  lVar5 = 0;
  do {
    lVar6 = lVar5 + 1;
    if (pcVar18[lVar5] != "BLOCK"[lVar5]) {
      pcVar7 = "CONVERGENCE";
      iVar4 = strcmp(pcVar18,"CONVERGENCE");
      if (iVar4 == 0) {
        pcVar18 = (char *)0x1b02ff00;
        goto LAB_18001bf80;
      }
      pcVar7 = "PRES-RELIEF";
      iVar4 = strcmp(pcVar18,"PRES-RELIEF");
      if (iVar4 == 0) {
        pcVar18 = (char *)0x1b0cff00;
        goto LAB_18001bf80;
      }
      lVar5 = 0;
      goto LAB_18001b9d2;
    }
    lVar5 = lVar6;
  } while (lVar6 != 6);
  pcVar18 = (char *)0x1b01ff00;
  goto LAB_18001bf80;
  while (lVar5 = lVar6, lVar6 != 8) {
LAB_18001baa0:
    lVar6 = lVar5 + 1;
    if (pcVar18[lVar5] != "UTILITY"[lVar5]) {
      iVar4 = strcmp(pcVar18,"DATA-FIT");
      if (iVar4 == 0) {
        pcVar7 = "DATA-SET";
        iVar4 = strcmp(*(char **)(param_1 + 6),"DATA-SET");
        pcVar18 = (char *)0xffffffffffffffff;
        if (iVar4 != 0) {
          pcVar18 = (char *)0x1b0dff00;
        }
        goto LAB_18001bc7c;
      }
      pcVar7 = "PROPERTIES";
      iVar4 = strcmp(pcVar18,"PROPERTIES");
      if (iVar4 == 0) {
        pcVar18 = (char *)0x1b950000;
        goto LAB_18001bf80;
      }
      pcVar7 = "COMPONENTS";
      iVar4 = strcmp(pcVar18,"COMPONENTS");
      if (iVar4 == 0) {
        pcVar18 = (char *)0x1b920000;
        goto LAB_18001bf80;
      }
      pcVar7 = "CALCULATOR";
      iVar4 = strcmp(pcVar18,"CALCULATOR");
      if (iVar4 == 0) {
        pcVar18 = (char *)0x1b08ff00;
        goto LAB_18001bf80;
      }
      pcVar7 = "BALANCE";
      lVar5 = 0;
      goto LAB_18001bb60;
    }
  }
  pcVar18 = (char *)0x1b09ff00;
  goto LAB_18001bf80;
  while (lVar5 = lVar6, lVar6 != 8) {
LAB_18001bb60:
    lVar6 = lVar5 + 1;
    if (pcVar18[lVar5] != "BALANCE"[lVar5]) {
      pcVar7 = "DIST-CURVE";
      iVar4 = strcmp(pcVar18,"DIST-CURVE");
      if (iVar4 == 0) {
        pcVar18 = (char *)0x1b0aff00;
        uStack_158._0_5_ = CONCAT14(DAT_1800414d8,DAT_1800414d4);
        goto LAB_18001bf80;
      }
      pcVar7 = "ECON-SUM";
      iVar4 = strcmp(pcVar18,"ECON-SUM");
      if (iVar4 == 0) {
        pcVar18 = (char *)0x1b930000;
        goto LAB_18001bf80;
      }
      pcVar7 = "RUN-STATUS";
      iVar4 = strcmp(pcVar18,"RUN-STATUS");
      if (iVar4 == 0) {
        pcVar18 = (char *)0x1b8c0000;
        goto LAB_18001bf80;
      }
      iVar4 = strcmp(pcVar18,"CONV-SUM");
      if (iVar4 != 0) {
        pcVar7 = "SENSITIVITY";
        iVar4 = strcmp(pcVar18,"SENSITIVITY");
        if (iVar4 == 0) {
          pcVar18 = (char *)0x1b05ff00;
          goto LAB_18001bf80;
        }
        pcVar7 = "EQUIP-SUM";
        iVar4 = strcmp(pcVar18,"EQUIP-SUM");
        if (iVar4 == 0) {
          pcVar18 = (char *)0x1b9a0000;
          goto LAB_18001bf80;
        }
        pcVar7 = "PROP-TABLE";
        iVar4 = strcmp(pcVar18,"PROP-TABLE");
        if (iVar4 == 0) {
          pcVar18 = (char *)0x1b85ff00;
          goto LAB_18001bf80;
        }
        pcVar7 = "COMPONENTS";
        iVar4 = strcmp(pcVar18,"COMPONENTS");
        if (iVar4 == 0) {
          pcVar18 = (char *)0x1b920000;
          goto LAB_18001bf80;
        }
        pcVar7 = "ECON-SUM";
        iVar4 = strcmp(pcVar18,"ECON-SUM");
        if (iVar4 == 0) {
          pcVar18 = (char *)0x1b930000;
          goto LAB_18001bf80;
        }
        lVar5 = 0;
        goto LAB_18001bd70;
      }
      pcVar21 = *(char **)(param_1 + 6);
      iVar4 = strcmp(pcVar21,"TEAR-SUMMARY");
      if (iVar4 == 0) {
        pcVar18 = (char *)0x1b8f0000;
      }
      else {
        iVar4 = strcmp(pcVar21,"SPEC-SUMMARY");
        if (iVar4 == 0) {
          pcVar18 = (char *)0x1b910000;
        }
        else {
          iVar4 = strcmp(pcVar21,"EOCV-SUMMARY");
          pcVar18 = uStack_2b8;
          if (iVar4 == 0) {
            pcVar18 = (char *)0x1bb10000;
          }
        }
      }
      pcVar7 = "TVAR-SUMMARY";
      iVar4 = strcmp(pcVar21,"TVAR-SUMMARY");
      if (iVar4 != 0) goto LAB_18001bc7c;
      pcVar18 = (char *)0x1bb6ff00;
      goto LAB_18001bf80;
    }
  }
  pcVar18 = (char *)0x1b0bff00;
  goto LAB_18001bf80;
LAB_18001bc7c:
  if (pcVar18 != (char *)0xffffffffffffffff) goto LAB_18001bf80;
LAB_18001bc86:
  if (*(longlong *)MDerror_exref != 0) goto LAB_18001bc97;
  if (lStack_2c8 == 0) {
    return 0;
  }
  goto LAB_18001c50b;
  while (lVar5 = lVar6, lVar6 != 6) {
LAB_18001bd70:
    lVar6 = lVar5 + 1;
    if (pcVar18[lVar5] != "BLOCK"[lVar5]) {
      pcVar7 = "TRANSFER";
      iVar4 = strcmp(pcVar18,"TRANSFER");
      if (iVar4 == 0) {
        pcVar18 = (char *)0x1b07ff00;
        goto LAB_18001bf80;
      }
      pcVar7 = "LOAD-SUM";
      iVar4 = strcmp(pcVar18,"LOAD-SUM");
      if (iVar4 == 0) {
        pcVar18 = (char *)0x1b0aff00;
        uStack_158 = CONCAT44(uStack_158._4_4_,0x4c4c41);
        goto LAB_18001bf80;
      }
      pcVar7 = "MEASUREMENT";
      iVar4 = strcmp(pcVar18,"MEASUREMENT");
      if (iVar4 == 0) {
        pcVar18 = (char *)0x1b0eff00;
        goto LAB_18001bf80;
      }
      pcVar7 = "OBJECTIVE";
      iVar4 = strcmp(pcVar18,"OBJECTIVE");
      if (iVar4 == 0) {
        pcVar18 = (char *)0x1ba8ff00;
        goto LAB_18001bf80;
      }
      pcVar7 = "CONNECTIONS";
      iVar4 = strcmp(pcVar18,"CONNECTIONS");
      if (iVar4 == 0) {
        pcVar18 = (char *)0x1ba90000;
        goto LAB_18001bf80;
      }
      pcVar7 = "SPECGROUPS";
      iVar4 = strcmp(pcVar18,"SPECGROUPS");
      if (iVar4 == 0) {
        pcVar18 = (char *)0x1baa0000;
        goto LAB_18001bf80;
      }
      pcVar7 = "INIT-VAR-ATT";
      iVar4 = strcmp(pcVar18,"INIT-VAR-ATT");
      if (iVar4 == 0) {
        pcVar18 = (char *)0x1bab0000;
        goto LAB_18001bf80;
      }
      pcVar7 = "STREAM-PRICE";
      iVar4 = strcmp(pcVar18,"STREAM-PRICE");
      if (iVar4 == 0) {
        pcVar18 = (char *)0x1bb00000;
        goto LAB_18001bf80;
      }
      pcVar7 = "EO-ALIAS";
      iVar4 = strcmp(pcVar18,"EO-ALIAS");
      if (iVar4 == 0) {
        pcVar18 = (char *)0x1bae0000;
        goto LAB_18001bf80;
      }
      pcVar7 = "DESIGN-SPEC";
      iVar4 = strcmp(pcVar18,"DESIGN-SPEC");
      if (iVar4 == 0) {
        pcVar18 = (char *)0x1b87ff00;
        goto LAB_18001bf80;
      }
      pcVar7 = "CONSTRAINT";
      iVar4 = strcmp(pcVar18,"CONSTRAINT");
      if (iVar4 == 0) {
        pcVar18 = (char *)0x1bb3ff00;
        goto LAB_18001bf80;
      }
      pcVar7 = "OPTIMIZATION";
      iVar4 = strcmp(pcVar18,"OPTIMIZATION");
      if (iVar4 == 0) {
        pcVar18 = (char *)0x1bb4ff00;
        goto LAB_18001bf80;
      }
      pcVar7 = "UTIL-SUMMARY";
      iVar4 = strcmp(pcVar18,"UTIL-SUMMARY");
      if (iVar4 == 0) {
        pcVar18 = (char *)0x1baf0000;
        goto LAB_18001bf80;
      }
      pcVar7 = "REACTIONS";
      iVar4 = strcmp(pcVar18,"REACTIONS");
      if (iVar4 == 0) {
        pcVar18 = (char *)0x1bb5ff00;
        goto LAB_18001bf80;
      }
      pcVar7 = "CONTROLLER";
      iVar4 = strcmp(pcVar18,"CONTROLLER");
      if (iVar4 == 0) {
        pcVar18 = (char *)0x1b11ff00;
        goto LAB_18001bf80;
      }
      pcVar7 = "BATCH-OPTS";
      iVar4 = strcmp(pcVar18,"BATCH-OPTS");
      if (iVar4 == 0) {
        pcVar18 = (char *)0x1b100000;
        goto LAB_18001bf80;
      }
      pcVar7 = "SENSOR";
      lVar5 = 0;
      goto LAB_18001bf64;
    }
  }
  pcVar18 = (char *)0x1b01ff00;
  goto LAB_18001bf80;
  while (lVar5 = lVar6, lVar6 != 7) {
LAB_18001bf64:
    lVar6 = lVar5 + 1;
    if (pcVar18[lVar5] != "SENSOR"[lVar5]) goto LAB_18001bc86;
  }
  pcVar18 = (char *)0x1b12ff00;
  goto LAB_18001bf80;
  while (lVar5 = lVar6, lVar6 != 8) {
LAB_18001b9d2:
    lVar6 = lVar5 + 1;
    if (pcVar18[lVar5] != "COSTING"[lVar5]) {
      pcVar7 = "UTILITY";
      lVar5 = 0;
      goto LAB_18001baa0;
    }
  }
  pcVar18 = *(char **)(param_1 + 6);
  pcVar7 = "EQUIPMENT";
  iVar4 = strcmp(pcVar18,"EQUIPMENT");
  if (iVar4 == 0) {
    pcVar18 = (char *)0x1b03ff00;
  }
  else {
    pcVar7 = "CAPITAL-COST";
    iVar4 = strcmp(pcVar18,"CAPITAL-COST");
    if (iVar4 == 0) {
      pcVar18 = (char *)0x1b8d0000;
    }
    else {
      pcVar7 = "OPERATING";
      iVar4 = strcmp(pcVar18,"OPERATING");
      if (iVar4 == 0) {
        pcVar18 = (char *)0x1b8e0000;
      }
      else {
        pcVar7 = "COST-SECTION";
        iVar4 = strcmp(pcVar18,"COST-SECTION");
        if (iVar4 == 0) {
          pcVar18 = (char *)0x1b96ff00;
        }
        else {
          pcVar7 = "UTILITY";
          lVar5 = 0;
          do {
            lVar6 = lVar5 + 1;
            if (pcVar18[lVar5] != "UTILITY"[lVar5]) goto LAB_18001bc86;
            lVar5 = lVar6;
          } while (lVar6 != 8);
          pcVar18 = (char *)0x1b09ff00;
        }
      }
    }
  }
LAB_18001bf80:
  if (*(longlong *)MDerror_exref != 0) {
LAB_18001bc97:
    ERclear(0);
    FUN_180008f80(acStack_148,"MDerror in QUERY code: %s",*(undefined8 *)(param_1 + 4),param_4);
    FUN_180028530(acStack_148,0);
    uVar12 = 0;
    goto LAB_18001bcc6;
  }
  if ((*(int *)bestinput_exref != 0) && (uStack_2b8 != (char *)0x0)) {
    if (uStack_2b8[0x107] == '\b') {
      pcVar21 = *(char **)(uStack_2b8 + 0x28);
      uVar19 = *(undefined8 *)(uStack_2b8 + 0x30);
    }
    else {
      pcVar21 = (char *)CONCAT44(uStack_2ac,uStack_2b0);
      uVar19 = CONCAT44(uVar24,uVar23);
    }
    pcVar7 = pcVar21;
    lVar5 = MDgetito(*(undefined8 *)iwpfile_exref,pcVar21,uVar19);
    if (lVar5 != 0) {
      lVar6 = MDgethkp(*(undefined8 *)iwpfile_exref,pcVar21,uVar19);
      pcVar7 = *(char **)(lVar5 + 8);
      iVar4 = AreDependenciesComplete(*(undefined8 *)(lVar5 + 0x10),pcVar7);
      if (((lVar6 != 0) && ((*(byte *)(lVar6 + 0x18) & 0xf) == 0)) || (iVar4 == 0)) {
        if (lStack_2c8 != 0) {
LAB_18001c50b:
          HYPopFinfo(lStack_2c8);
        }
        return 0;
      }
    }
  }
  if (*(longlong *)(*(longlong *)finfo_exref + 0x1e0) != 0) {
    puVar8 = (uint *)MDgetito(*(undefined8 *)iwpfile_exref,0xffffffffffffffff);
    uVar16 = *puVar8;
    pcVar7 = (char *)(ulonglong)uVar16;
    if (0 < (int)uVar16) {
      lVar5 = (longlong)(int)uVar16 * 0x2c + -0x22 + (longlong)puVar8;
      uVar20 = (ulonglong)uVar16;
      do {
        if (*(char *)(lVar5 + -1) == '\x01') {
          pbVar9 = *(byte **)(param_1 + 4);
          lVar6 = lVar5 - (longlong)pbVar9;
          do {
            pbVar1 = pbVar9 + lVar6;
            uVar16 = (uint)*pbVar9 - (uint)*pbVar1;
            pcVar7 = (char *)(ulonglong)uVar16;
            if (uVar16 != 0) break;
            pbVar9 = pbVar9 + 1;
          } while (*pbVar1 != 0);
          if (uVar16 == 0) {
            pbVar9 = (byte *)(lVar5 + 0x1c);
            lVar6 = -0x10 - (longlong)pbVar9;
            do {
              pbVar1 = pbVar9 + (longlong)(acStack_148 + lVar6);
              uVar16 = (uint)*pbVar9 - (uint)*pbVar1;
              pcVar7 = (char *)(ulonglong)uVar16;
              if (uVar16 != 0) break;
              pbVar9 = pbVar9 + 1;
            } while (*pbVar1 != 0);
            if (uVar16 == 0) {
              pcVar7 = (char *)0x0;
              strcpy_s((char *)&uStack_158,10,(char *)(lVar5 + 0xe));
            }
          }
        }
        lVar5 = lVar5 + -0x2c;
        uVar20 = uVar20 - 1;
      } while (uVar20 != 0);
    }
  }
  iVar4 = 0;
  lVar5 = 0;
  do {
    if (acStack_148[lVar5 + -0x10] == '\0') {
      if (iVar4 < 8) {
        memset(acStack_148 + (longlong)iVar4 + -0x10,
               (int)CONCAT71((int7)((ulonglong)pcVar7 >> 8),0x20),(longlong)(8 - iVar4));
      }
      break;
    }
    iVar4 = iVar4 + 1;
    lVar5 = lVar5 + 1;
  } while (lVar5 < 8);
  uStack_150 = uStack_150 & 0xff00;
  iVar4 = FUN_180030240((char *)0x0,acStack_268,0,(ulonglong)pcVar18,(char *)&uStack_158);
  if (iVar4 != 1) {
    if (iVar4 < 1) {
      uVar12 = GetSorResStringEx(0x1af);
      GetSorResStringEx(0x282);
      FUN_180008f80(acStack_148,"%s%s%s%s",uVar12,&DAT_18003f9bc);
      iVar4 = GRinqsme();
      if (iVar4 != 0) {
        lVar5 = GetSorResStringEx(0x283);
        puVar15 = &uStack_149;
        do {
          pcVar7 = puVar15 + 1;
          puVar15 = puVar15 + 1;
        } while (*pcVar7 != '\0');
        lVar6 = 0;
        do {
          cVar3 = *(char *)(lVar5 + lVar6);
          puVar15[lVar6] = cVar3;
          lVar6 = lVar6 + 1;
        } while (cVar3 != '\0');
      }
      FUN_180028530(acStack_148,-1);
      _DAT_180051ff8 = 1;
      uVar12 = 0xffffffff;
    }
    goto LAB_18001bcc6;
  }
  if (((iStack_260 != 1) || (iStack_254 != 1)) && ((1 < iStack_260 - 2U || (iStack_258 != 1)))) {
    uVar12 = 0;
    goto LAB_18001bcc6;
  }
  if ((uStack_2b8 == (char *)0x0) || (*(longlong *)(uStack_2b8 + 0x48) == 0)) {
LAB_18001c437:
    FUN_18002c620((longlong)APtmpfil_exref);
  }
  else {
    if (pcVar18 < (char *)0x1b910001) {
      if (pcVar18 == (char *)0x1b910000) goto LAB_18001c2c6;
      if (pcVar18 == (char *)0x1b0aff00) {
        FUN_18001d3c0((char *)&uStack_158,1);
        FUN_18002c620((longlong)APtmpfil_exref);
        goto LAB_18001bcc6;
      }
      if (pcVar18 == (char *)0x1b8c0000) {
        plVar10 = (longlong *)deref_ptr();
        lVar5 = *plVar10;
        if (lVar5 != 0) {
          do {
            plVar11 = (longlong *)deref_ptr(lVar5);
            lVar6 = *plVar11;
            lVar13 = 0;
            while (lVar14 = lVar13 + 1,
                  *(char *)((longlong)plVar11 + lVar13 + 8) == (&DAT_18004156c)[lVar13]) {
              lVar13 = lVar14;
              if (lVar14 == 7) {
                *plVar10 = lVar6;
                OPpurlnk(lVar5,0);
                free3(lVar5,0x28);
                FUN_18002c620((longlong)APtmpfil_exref);
                goto LAB_18001bcc6;
              }
            }
            lVar5 = lVar6;
            plVar10 = plVar11;
          } while (lVar6 != 0);
          FUN_18002c620((longlong)APtmpfil_exref);
          goto LAB_18001bcc6;
        }
        goto LAB_18001c437;
      }
      bVar22 = pcVar18 == (char *)0x1b8f0000;
    }
    else {
      if (pcVar18 == (char *)0x1b930000) {
        uVar12 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"ECON-SUM");
        do {
          do {
            do {
              lVar5 = MDfndsls(*(undefined8 *)iwpfile_exref,uVar12,1,0);
              lVar6 = MDrslcls(*(undefined8 *)iwpfile_exref,uVar12);
              lVar6 = lVar6 + lVar5 * 0x108;
            } while ((*(uint *)(lVar6 + 0x18) & 0x1f0) == 0x20);
            OPpurdst(lVar6,1);
          } while (*(longlong *)MDerror_exref == 0);
          ERclear(0);
        } while( true );
      }
      if (pcVar18 == (char *)0x1bb10000) goto LAB_18001c2c6;
      bVar22 = pcVar18 == (char *)0x1bb6ff00;
    }
    if (bVar22) {
LAB_18001c2c6:
      uVar12 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"CONV-SUM");
      do {
        do {
          lVar5 = MDfndsls(*(undefined8 *)iwpfile_exref,uVar12,1,0);
          lVar6 = MDrslcls(*(undefined8 *)iwpfile_exref,uVar12);
          lVar6 = lVar6 + lVar5 * 0x108;
        } while ((*(uint *)(lVar6 + 0x18) & 0x1f0) == 0x20);
        OPpurdst(lVar6,1);
        if (*(longlong *)MDerror_exref != 0) {
          ERclear(0);
        }
      } while( true );
    }
    OPpurdst(uStack_2b8,1);
    FUN_18002c620((longlong)APtmpfil_exref);
  }
LAB_18001bcc6:
  if (lStack_2c8 != 0) {
    HYPopFinfo();
  }
  return uVar12;
}

/* RVA 0x1a420 */
undefined4 FUN_18001a420(longlong param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong lVar5;
  bool bVar6;
  
  uVar2 = 0;
  lVar5 = 0;
  bVar6 = DAT_180051ffc != 0;
  uVar1 = *(undefined4 *)partial_results_exref;
  *(undefined4 *)partial_results_exref = 1;
  if (bVar6) {
    *(undefined4 *)partial_results_exref = uVar1;
    return 0;
  }
  DAT_180051ffc = 1;
  if ((param_1 != 0) && (*(longlong *)(param_1 + 0xf8) != 0)) {
    lVar3 = MDgetde(*(undefined8 *)iwpfile_exref);
    if ((lVar3 != 0) && ((*(longlong *)(lVar3 + 0x78) != 0 && (*(longlong *)(lVar3 + 0x70) != 0))))
    {
      uVar4 = HYGetFinfoCls();
      lVar5 = HYPshFinfo(uVar4);
    }
  }
  if (DAT_180051ff4 == 1) {
    FUN_18001a180();
    DAT_180051ff4 = 0;
  }
  lVar3 = *(longlong *)finfo_exref;
  uVar4 = FUN_18001a1c0(lVar3);
  if ((int)uVar4 == 0) {
    FUN_18001a140(lVar3);
    uVar2 = FUN_18001cc20();
  }
  if (lVar5 != 0) {
    HYPopFinfo(lVar5);
  }
  DAT_180051ffc = 0;
  *(undefined4 *)partial_results_exref = uVar1;
  return uVar2;
}

/* RVA 0x1a520 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18001a520(void)

{
  int iVar1;
  char *pcVar2;
  undefined8 uVar3;
  undefined1 auStackY_168 [32];
  char local_128 [272];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStackY_168;
  iVar1 = GRinqiap();
  if ((iVar1 == 1) && (*(int *)triggered_by_canned_exref == 0)) {
    FUN_180008f80(dbxbuf_exref,"%c%c%s%s%s",0x5e,0x69);
    iVar1 = EXyesno(dbxbuf_exref);
    if (iVar1 != 2) {
      *(undefined4 *)partial_results_exref = 0;
      pcVar2 = (char *)GetSorResStringEx(0x782);
      iVar1 = FUN_180030240(pcVar2,local_128,0,0x9010000,(char *)0x0);
      if (0 < iVar1) {
        FUN_18002c620((longlong)APtmpfil_exref);
        GRsetrpt(1);
        *(undefined4 *)partial_results_exref = 1;
        DAT_180051ff0 = 1;
        goto LAB_18001a614;
      }
      *(undefined4 *)partial_results_exref = 1;
      DAT_180051ff0 = 1;
    }
    uVar3 = 0;
  }
  else {
LAB_18001a614:
    uVar3 = 1;
  }
  return uVar3;
}

/* RVA 0x1a650 */
undefined8 FUN_18001a650(undefined8 param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  uVar2 = GetSorResStringEx(0x20c);
  GetSorResStringEx(0x20b);
  FUN_180008f80(dbxbuf_exref,"%c%c%s%s%s",0x5e,0x69);
  iVar1 = EXyesno(dbxbuf_exref,3,1);
  if (iVar1 == 2) {
    return 0;
  }
  *(undefined4 *)partial_results_exref = 0;
  SESetSettingValue("partial",partial_results_exref,0,0,0,param_1,uVar2);
  *(undefined4 *)denied_exref = 1;
  return 1;
}

/* RVA 0x1a710 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18001a710(int param_1,char *param_2,char *param_3,int param_4)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStack_68 [56];
  undefined8 local_30;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = DAT_1800516d8 ^ (ulonglong)auStack_68;
  uVar4 = 1;
  if ((param_2 != (char *)0x0) && (*param_2 != '\0')) {
    iVar1 = HYrslhie(param_2,&DAT_18003fa80,&local_28,&local_30);
    if (iVar1 == 0) {
      return;
    }
    uVar4 = HYGetFinfoCls(local_28,local_30);
  }
  uVar2 = HYPshFinfo(uVar4);
  lVar3 = *(longlong *)finfo_exref;
  uVar4 = *(undefined8 *)(lVar3 + 0x168);
  switch(param_1) {
  case 1:
  case 8:
    uVar5 = *(undefined8 *)iwpfile_exref;
    if (param_1 != 8) {
      param_3 = "SPECGROUPS";
      goto LAB_18001a937;
    }
    uVar4 = *(undefined8 *)(lVar3 + 0x1b8);
    lVar3 = MDchkkey(uVar5,uVar4,1,param_3);
    if (-1 < lVar3) {
      MDgethkp(*(undefined8 *)iwpfile_exref,uVar4,lVar3);
    }
    goto LAB_18001a93c;
  case 2:
    uVar4 = MDfnddir(*(undefined8 *)iwpfile_exref,uVar4,"OBJECTIVE");
    break;
  case 3:
    if ((param_3 == (char *)0x0) || (*param_3 == '\0')) {
      param_3 = "INIT-VAR-ATT";
      goto LAB_18001a927;
    }
    if (param_4 == 1) {
      uVar4 = *(undefined8 *)(lVar3 + 0x1b8);
    }
    else {
      if (param_4 != 0xe) goto switchD_18001a7b5_default;
      uVar4 = MDfnddir(*(undefined8 *)iwpfile_exref,uVar4,"MEASUREMENT");
      if (*(longlong *)MDerror_exref != 0) goto LAB_18001a949;
    }
    break;
  case 4:
    param_3 = "CONNECTIONS";
    goto LAB_18001a927;
  case 5:
  case 7:
    uVar5 = *(undefined8 *)iwpfile_exref;
    if (param_1 == 5) {
      uVar4 = *(undefined8 *)(lVar3 + 0x1b8);
      goto LAB_18001a839;
    }
    uVar4 = MDfnddir(uVar5,uVar4,"EO-PORT");
    if (*(longlong *)MDerror_exref == 0) goto LAB_18001a927;
    goto LAB_18001a949;
  case 6:
    param_3 = "EO-ALIAS";
LAB_18001a927:
    uVar5 = *(undefined8 *)iwpfile_exref;
LAB_18001a937:
    MDchkkey(uVar5,uVar4,1,param_3);
    goto LAB_18001a93c;
  default:
    goto switchD_18001a7b5_default;
  }
  uVar5 = *(undefined8 *)iwpfile_exref;
LAB_18001a839:
  lVar3 = MDchkkey(uVar5,uVar4,1,param_3);
  if (-1 < lVar3) {
    MDgethkp(*(undefined8 *)iwpfile_exref,uVar4,lVar3);
  }
LAB_18001a93c:
  if (*(longlong *)MDerror_exref != 0) {
LAB_18001a949:
    ERclear(0);
  }
switchD_18001a7b5_default:
  HYPopFinfo(uVar2);
  return;
}

/* RVA 0x1a9a0 */
undefined8 FUN_18001a9a0(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  switch(param_1) {
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
  case 0x65:
    *param_2 = param_1;
    return 1;
  case 0xe:
    *param_2 = 1;
    *param_3 = 0x25;
    return 1;
  case 0xf:
  case 0x13:
  case 0x14:
  case 0x15:
  case 0x16:
  case 0x17:
  case 0x18:
  case 0x19:
  case 0x1a:
  case 0x1b:
  case 0x1c:
  case 0x1d:
  case 0x1f:
    *param_2 = 0;
    break;
  case 0x10:
    *param_2 = 0xfffffff9;
    return 1;
  case 0x11:
    *param_2 = 0xffffffcd;
    return 1;
  case 0x12:
    *param_2 = 0xffffffcc;
    return 1;
  case 0x1e:
    *param_2 = 0xe;
    return 1;
  case 0xffffffff:
    *param_2 = 1;
    return 1;
  }
  return 0;
}

/* RVA 0x1aac0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18001aac0(undefined *param_1,char *param_2,undefined8 param_3,undefined8 param_4)

{
  code cVar1;
  char cVar2;
  undefined8 uVar3;
  char *pcVar4;
  code *pcVar5;
  code *pcVar6;
  ulonglong uVar7;
  undefined1 auStack_d68 [32];
  char *local_d48;
  undefined4 local_d40;
  undefined8 local_d38;
  undefined4 local_d28;
  undefined4 local_d24;
  undefined1 *local_d20;
  char *local_d18;
  undefined *local_d10;
  undefined1 local_d08 [120];
  char local_c90 [16];
  undefined8 local_c80;
  undefined8 local_c78;
  undefined8 local_c70;
  undefined8 local_c40;
  ulonglong local_38;
  
  local_38 = DAT_1800516d8 ^ (ulonglong)auStack_d68;
  uVar7 = 0xffffffffffffffff;
  do {
    uVar7 = uVar7 + 1;
  } while (param_1[uVar7] != '\0');
  if (uVar7 < 3) {
    uVar3 = 0xffffffff;
  }
  else {
    local_d24 = 0;
    memset(local_d08,0,0xcd0);
    pcVar5 = (code *)&DAT_1800413f4;
    local_d20 = &DAT_1800413f4;
    local_d28 = 3;
    local_d18 = "CONVERGENCE";
    pcVar6 = path_name_exref;
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      *pcVar6 = cVar1;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != (code)0x0);
    pcVar4 = "CONVERGENCE";
    pcVar5 = path_name_exref + 0xe;
    do {
      cVar1 = (code)*pcVar4;
      pcVar4 = pcVar4 + 1;
      *pcVar5 = cVar1;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != (code)0x0);
    pcVar6 = path_name_exref + 0x1c;
    pcVar5 = (code *)param_1;
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      *pcVar6 = cVar1;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != (code)0x0);
    pcVar4 = param_2;
    do {
      cVar2 = *pcVar4;
      pcVar4[(longlong)(local_c90 + -(longlong)param_2)] = cVar2;
      pcVar4 = pcVar4 + 1;
    } while (cVar2 != '\0');
    local_c80 = *(undefined8 *)dataclass_exref;
    local_d10 = param_1;
    local_c78 = param_3;
    local_c70 = MDfnddir(*(undefined8 *)iwpfile_exref,param_3,param_1);
    local_c40 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"CONVERGENCE");
    local_d40 = 0;
    local_d48 = param_2;
    local_d38 = param_4;
    OPcreblk(&local_d28,2,*(undefined8 *)iwpfile_exref,local_c70);
    uVar3 = 0;
  }
  return uVar3;
}

/* RVA 0x1aca0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
FUN_18001aca0(undefined *param_1,undefined *param_2,undefined8 param_3,undefined8 param_4)

{
  code cVar1;
  char cVar2;
  char *pcVar3;
  code *pcVar4;
  code *pcVar5;
  undefined1 auStack_d58 [32];
  undefined *local_d38;
  undefined4 local_d30;
  undefined8 local_d28;
  undefined4 local_d18;
  undefined4 local_d14;
  undefined1 *local_d10;
  undefined *local_d08;
  undefined *local_d00;
  undefined1 local_cf8 [120];
  char local_c80 [16];
  undefined8 local_c70;
  undefined8 local_c68;
  undefined8 local_c30;
  ulonglong local_28;
  
  local_28 = DAT_1800516d8 ^ (ulonglong)auStack_d58;
  local_d14 = 0;
  memset(local_cf8,0,0xcd0);
  pcVar4 = (code *)&DAT_1800413f4;
  local_d10 = &DAT_1800413f4;
  local_d18 = 2;
  pcVar5 = path_name_exref;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    *pcVar5 = cVar1;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != (code)0x0);
  pcVar5 = path_name_exref + 0xe;
  pcVar4 = (code *)param_1;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    *pcVar5 = cVar1;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != (code)0x0);
  pcVar5 = path_name_exref + 0x1c;
  pcVar4 = (code *)param_2;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    *pcVar5 = cVar1;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != (code)0x0);
  pcVar3 = param_2;
  do {
    cVar2 = *pcVar3;
    pcVar3[(longlong)(local_c80 + -(longlong)param_2)] = cVar2;
    pcVar3 = pcVar3 + 1;
  } while (cVar2 != '\0');
  local_d28 = 0;
  local_c70 = *(undefined8 *)dataclass_exref;
  local_d30 = 2;
  local_d38 = param_2;
  local_d08 = param_1;
  local_d00 = param_2;
  local_c68 = param_4;
  local_c30 = param_3;
  OPcreblk(&local_d18,2,*(undefined8 *)iwpfile_exref,param_4);
  return 0;
}

/* RVA 0x1ae10 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18001ae10(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  char *pcVar7;
  undefined1 auStack_db8 [32];
  longlong *local_d98;
  undefined8 local_d90;
  undefined4 local_d88;
  undefined4 local_d78 [2];
  longlong local_d70 [5];
  undefined1 local_d48 [3312];
  undefined8 local_58;
  undefined8 local_50;
  ulonglong local_28;
  
  local_28 = DAT_1800516d8 ^ (ulonglong)auStack_db8;
  GRsavpgc(local_d78);
  uVar1 = *(undefined4 *)triggered_by_canned_exref;
  *(undefined4 *)triggered_by_canned_exref = 1;
  uVar3 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"CONVERGENCE");
  local_d70[0] = 0;
  do {
    local_d98 = local_d70;
    local_d90 = 0;
    lVar4 = MDfndsls(*(undefined8 *)iwpfile_exref,uVar3,1);
    if (local_d70[0] == -1) break;
    lVar5 = MDrslcls(*(undefined8 *)iwpfile_exref,uVar3);
    pcVar7 = (char *)(lVar4 * 0x108 + lVar5);
    if (*pcVar7 == '$') {
      lVar4 = MDrslcls(*(undefined8 *)iwpfile_exref,*(undefined8 *)(pcVar7 + 0x28));
      lVar4 = *(longlong *)(pcVar7 + 0x30) * 0x108 + lVar4;
      if (*(longlong *)(lVar4 + 0x60) != 0) {
        uVar6 = deref_ptr();
        HANotify(uVar6,6);
      }
      *(undefined8 *)(lVar4 + 0x60) = 0;
      lVar4 = MDgetito(*(undefined8 *)iwpfile_exref,*(undefined8 *)(pcVar7 + 0x28),
                       *(undefined8 *)(pcVar7 + 0x30));
      if (lVar4 != 0) {
        uVar2 = GRinqnec();
        MDdhdvds(lVar4,local_d48);
        MDdelsrv(local_d48);
        local_d70[0] = 0;
        GRsetnec(uVar2);
      }
    }
  } while (local_d70[0] != -1);
  local_58 = *(undefined8 *)dataclass_exref;
  local_d70[0] = 0;
  uVar3 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"CONV-SUM");
  local_50 = uVar3;
  if (*(longlong *)MDerror_exref == 0) {
    while (local_d70[0] != -1) {
      local_d98 = local_d70;
      local_d90 = 0;
      lVar4 = MDfndsls(*(undefined8 *)iwpfile_exref,uVar3,1);
      if (local_d70[0] == -1) break;
      lVar5 = MDrslcls(*(undefined8 *)iwpfile_exref,uVar3);
      lVar5 = lVar5 + lVar4 * 0x108;
      if ((*(uint *)(lVar5 + 0x18) & 0x1f0) != 0x20) {
        if (*(longlong *)(lVar5 + 0x48) != 0) {
          OPpurdst(lVar5,1);
        }
        if (*(longlong *)MDerror_exref == 0) {
          local_d88 = 9999;
          local_d90 = CONCAT44(local_d90._4_4_,2);
          local_d98 = (longlong *)CONCAT44(local_d98._4_4_,9999);
          MDprpcmp(&local_58,1);
        }
        else {
          ERclear(0);
        }
      }
    }
  }
  else {
    ERclear(0);
  }
  local_d70[0] = 0;
  uVar3 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"EQUIP-SUM");
  local_50 = uVar3;
  if (*(longlong *)MDerror_exref == 0) {
    while (local_d70[0] != -1) {
      local_d98 = local_d70;
      local_d90 = 0;
      lVar4 = MDfndsls(*(undefined8 *)iwpfile_exref,uVar3,1);
      if (local_d70[0] == -1) break;
      lVar5 = MDrslcls(*(undefined8 *)iwpfile_exref,uVar3);
      lVar5 = lVar5 + lVar4 * 0x108;
      if ((*(uint *)(lVar5 + 0x18) & 0x1f0) != 0x20) {
        if (*(longlong *)(lVar5 + 0x48) != 0) {
          OPpurdst(lVar5,1);
        }
        if (*(longlong *)MDerror_exref == 0) {
          local_d88 = 9999;
          local_d90 = CONCAT44(local_d90._4_4_,2);
          local_d98 = (longlong *)CONCAT44(local_d98._4_4_,9999);
          MDprpcmp(&local_58,1);
        }
        else {
          ERclear(0);
        }
      }
    }
  }
  else {
    ERclear(0);
  }
  local_d70[0] = 0;
  uVar3 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"ECON-SUM");
  local_50 = uVar3;
  if (*(longlong *)MDerror_exref == 0) {
    while (local_d70[0] != -1) {
      local_d98 = local_d70;
      local_d90 = 0;
      lVar4 = MDfndsls(*(undefined8 *)iwpfile_exref,uVar3,1);
      if (local_d70[0] == -1) break;
      lVar5 = MDrslcls(*(undefined8 *)iwpfile_exref,uVar3);
      lVar5 = lVar5 + lVar4 * 0x108;
      if ((*(uint *)(lVar5 + 0x18) & 0x1f0) != 0x20) {
        if (*(longlong *)(lVar5 + 0x48) != 0) {
          OPpurdst(lVar5,1);
        }
        if (*(longlong *)MDerror_exref == 0) {
          local_d88 = 9999;
          local_d90 = CONCAT44(local_d90._4_4_,2);
          local_d98 = (longlong *)CONCAT44(local_d98._4_4_,9999);
          MDprpcmp(&local_58,1);
        }
        else {
          ERclear(0);
        }
      }
    }
  }
  else {
    ERclear(0);
    local_d70[0] = -1;
  }
  lVar4 = MDchkkey(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,1,"HEAT-SUM");
  if (0 < lVar4) {
    lVar5 = MDrslcls(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref);
    lVar5 = lVar5 + lVar4 * 0x108;
    if ((*(uint *)(lVar5 + 0x18) & 0x1f0) != 0x20) {
      if (*(longlong *)(lVar5 + 0x48) != 0) {
        OPpurdst(lVar5,1);
      }
      if (*(longlong *)MDerror_exref == 0) {
        local_d88 = 9999;
        local_d90 = CONCAT44(local_d90._4_4_,2);
        local_d98 = (longlong *)CONCAT44(local_d98._4_4_,9999);
        MDprpcmp(&local_58,0,0,lVar4);
      }
      else {
        ERclear(0);
      }
    }
  }
  lVar4 = MDchkkey(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,1,"WORK-SUM");
  if (0 < lVar4) {
    lVar5 = MDrslcls(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref);
    lVar5 = lVar5 + lVar4 * 0x108;
    if ((*(uint *)(lVar5 + 0x18) & 0x1f0) != 0x20) {
      if (*(longlong *)(lVar5 + 0x48) != 0) {
        OPpurdst(lVar5,1);
      }
      if (*(longlong *)MDerror_exref == 0) {
        local_d88 = 9999;
        local_d90 = CONCAT44(local_d90._4_4_,2);
        local_d98 = (longlong *)CONCAT44(local_d98._4_4_,9999);
        MDprpcmp(&local_58,0,0,lVar4);
      }
      else {
        ERclear(0);
      }
    }
  }
  lVar4 = MDchkkey(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,1,"LOAD-SUM");
  if (0 < lVar4) {
    lVar5 = MDrslcls(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref);
    lVar5 = lVar5 + lVar4 * 0x108;
    if ((*(uint *)(lVar5 + 0x18) & 0x1f0) != 0x20) {
      if (*(longlong *)(lVar5 + 0x48) != 0) {
        OPpurdst(lVar5,1);
      }
      if (*(longlong *)MDerror_exref == 0) {
        local_d88 = 9999;
        local_d90 = CONCAT44(local_d90._4_4_,2);
        local_d98 = (longlong *)CONCAT44(local_d98._4_4_,9999);
        MDprpcmp(&local_58,0,0,lVar4);
      }
      else {
        ERclear(0);
      }
    }
  }
  *(undefined4 *)triggered_by_canned_exref = uVar1;
  GRsetpgc(local_d78[0]);
  return;
}

/* RVA 0x1b550 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_18001b550(undefined4 param_1,int param_2,char *param_3,undefined1 param_4,
                       undefined8 param_5)

{
  char cVar1;
  longlong lVar2;
  bool bVar3;
  int iVar4;
  char *pcVar5;
  ulonglong uVar6;
  undefined7 extraout_var;
  undefined8 uVar7;
  undefined1 auStackY_f8 [32];
  int local_b8 [2];
  char *local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88 [6];
  char local_58 [16];
  ulonglong local_48;
  
  local_48 = DAT_1800516d8 ^ (ulonglong)auStackY_f8;
  uVar7 = 1;
  pcVar5 = strchr(param_3,0x20);
  if (pcVar5 != (char *)0x0) {
    *pcVar5 = '\0';
  }
  iVar4 = HYparnam(param_3,&local_a8,&local_b0);
  if (iVar4 != 0) {
    lVar2 = -(longlong)local_b0;
    do {
      cVar1 = *local_b0;
      local_b0[(longlong)(local_58 + lVar2)] = cVar1;
      local_b0 = local_b0 + 1;
    } while (cVar1 != '\0');
    local_b0 = local_58;
    uVar6 = HYrslhie(local_a8,&DAT_18003fa80,&local_90,&local_98);
    if ((int)uVar6 == 0) {
      return uVar6;
    }
    uVar7 = HYGetFinfoCls(local_90,local_98);
  }
  uVar7 = HYPshFinfo(uVar7);
  bVar3 = FUN_18001e1a0(param_1,param_2,local_b0,local_88,local_b8,&local_98,&local_a0);
  if ((int)CONCAT71(extraout_var,bVar3) != 0) {
    local_98 = local_a0;
    local_90 = local_88[local_b8[0]];
    HYnavpth(&local_98,param_4,0,param_5);
  }
  HYPopFinfo(uVar7);
  return CONCAT71(extraout_var,bVar3) & 0xffffffff;
}

/* RVA 0x1b6d0 */
void FUN_18001b6d0(void)

{
  if (*(longlong *)(*(longlong *)topfinfo_exref + 0x5a0) != 0) {
    OPpurcls(*(undefined8 *)iwpfile_exref);
    *(undefined8 *)(*(longlong *)topfinfo_exref + 0x5a0) = 0;
  }
  return;
}

/* RVA 0x1b720 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00018001c379) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_18001b720(int *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  byte *pbVar1;
  undefined1 auVar2 [16];
  char cVar3;
  int iVar4;
  longlong lVar5;
  longlong lVar6;
  char *pcVar7;
  uint *puVar8;
  byte *pbVar9;
  longlong *plVar10;
  longlong *plVar11;
  undefined8 uVar12;
  longlong lVar13;
  longlong lVar14;
  undefined1 *puVar15;
  uint uVar16;
  undefined8 uVar17;
  char *pcVar18;
  undefined8 uVar19;
  ulonglong uVar20;
  char *pcVar21;
  bool bVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  undefined1 auStackY_2f8 [32];
  longlong local_2c8;
  undefined8 local_2b8;
  undefined4 uStack_2b0;
  undefined4 uStack_2ac;
  char local_268 [8];
  int local_260;
  int local_258;
  int local_254;
  undefined8 local_158;
  ushort local_150;
  undefined1 uStack_149;
  char local_148 [256];
  ulonglong local_48;
  
  auVar2 = _local_2b8;
  local_48 = DAT_1800516d8 ^ (ulonglong)auStackY_2f8;
  local_150 = 0;
  local_2c8 = 0;
  uVar12 = 1;
  if (DAT_180051ff0 != 0) {
    return 0;
  }
  if (*(int *)in_rename_exref != 0) {
    return 0;
  }
  local_158 = 0x2020202020202020;
  strncpy((char *)&local_158,(char *)(param_1 + 0x26),8);
  lVar5 = MDrslcls(*(undefined8 *)iwpfile_exref,*(undefined8 *)(param_1 + 0x3e));
  if (*(longlong *)(param_1 + 0x3c) == 0) {
    local_2b8 = (char *)0x0;
    uVar23 = 0;
    uVar24 = 0;
    uStack_2b0 = auVar2._8_4_;
    uStack_2ac = auVar2._12_4_;
  }
  else {
    auVar2 = *(undefined1 (*) [16])(param_1 + 0x3c);
    local_2b8._0_4_ = auVar2._0_4_;
    local_2b8._4_4_ = auVar2._4_4_;
    uStack_2b0 = auVar2._8_4_;
    uStack_2ac = auVar2._12_4_;
    lVar6 = *(longlong *)(param_1 + 0x3c) * 0x108;
    uVar19 = auVar2._0_8_;
    if (*(char *)(lVar6 + 0x107 + lVar5) == '\b') {
      uVar17 = *(undefined8 *)(lVar6 + 0x28 + lVar5);
      uVar19 = *(undefined8 *)(lVar6 + 0x30 + lVar5);
      local_2b8._0_4_ = (undefined4)uVar19;
      local_2b8._4_4_ = (undefined4)((ulonglong)uVar19 >> 0x20);
      uStack_2b0 = (undefined4)uVar17;
      uStack_2ac = (undefined4)((ulonglong)uVar17 >> 0x20);
    }
    else {
      uVar17 = *(undefined8 *)(param_1 + 0x3e);
    }
    lVar5 = MDgetito(*(undefined8 *)iwpfile_exref,uVar17,uVar19);
    if ((*(byte *)(lVar5 + 0x120) & 4) != 0) {
      return 0;
    }
    pcVar7 = (char *)MDgethkp(*(undefined8 *)iwpfile_exref,uVar17,uVar19);
    if ((((*(uint *)(pcVar7 + 0x18) & 0x1000) == 0) && (*pcVar7 != '$')) &&
       (lVar5 = MDgethkp(*(undefined8 *)recfile_exref,*(undefined8 *)(lVar5 + 0x20),
                         *(undefined8 *)(lVar5 + 0x18)), (*(uint *)(lVar5 + 0x18) & 0x4000) == 0)) {
      return 0;
    }
    uVar23 = (undefined4)local_2b8;
    uVar24 = local_2b8._4_4_;
    local_2b8 = pcVar7;
  }
  if (*param_1 == 2) {
    lVar5 = 0;
    do {
      lVar6 = lVar5 + 1;
      if (*(char *)(*(longlong *)(param_1 + 4) + lVar5) != "BLOCK"[lVar5]) goto LAB_18001b8eb;
      lVar5 = lVar6;
    } while (lVar6 != 6);
    iVar4 = strcmp(*(char **)(param_1 + 6),"HIERARCHY");
    if (iVar4 == 0) {
      return 0;
    }
  }
LAB_18001b8eb:
  iVar4 = GRinqiap();
  if (iVar4 != 1) {
    return 0;
  }
  iVar4 = GRinqcnn();
  if (iVar4 != 2) {
    return 0;
  }
  pcVar7 = *(char **)(param_1 + 0x3e);
  if (((pcVar7 != (char *)0x0) && (lVar5 = MDgetde(), lVar5 != 0)) &&
     ((*(longlong *)(lVar5 + 0x78) != 0 &&
      (pcVar7 = *(char **)(lVar5 + 0x70), pcVar7 != (char *)0x0)))) {
    HYGetFinfoCls();
    local_2c8 = HYPshFinfo();
  }
  SBsetscp((char *)0x0);
  pcVar18 = *(char **)(param_1 + 4);
  lVar5 = 0;
  do {
    lVar6 = lVar5 + 1;
    if (pcVar18[lVar5] != "BLOCK"[lVar5]) {
      pcVar7 = "CONVERGENCE";
      iVar4 = strcmp(pcVar18,"CONVERGENCE");
      if (iVar4 == 0) {
        pcVar18 = (char *)0x1b02ff00;
        goto LAB_18001bf80;
      }
      pcVar7 = "PRES-RELIEF";
      iVar4 = strcmp(pcVar18,"PRES-RELIEF");
      if (iVar4 == 0) {
        pcVar18 = (char *)0x1b0cff00;
        goto LAB_18001bf80;
      }
      lVar5 = 0;
      goto LAB_18001b9d2;
    }
    lVar5 = lVar6;
  } while (lVar6 != 6);
  pcVar18 = (char *)0x1b01ff00;
  goto LAB_18001bf80;
  while (lVar5 = lVar6, lVar6 != 8) {
LAB_18001baa0:
    lVar6 = lVar5 + 1;
    if (pcVar18[lVar5] != "UTILITY"[lVar5]) {
      iVar4 = strcmp(pcVar18,"DATA-FIT");
      if (iVar4 == 0) {
        pcVar7 = "DATA-SET";
        iVar4 = strcmp(*(char **)(param_1 + 6),"DATA-SET");
        pcVar18 = (char *)0xffffffffffffffff;
        if (iVar4 != 0) {
          pcVar18 = (char *)0x1b0dff00;
        }
        goto LAB_18001bc7c;
      }
      pcVar7 = "PROPERTIES";
      iVar4 = strcmp(pcVar18,"PROPERTIES");
      if (iVar4 == 0) {
        pcVar18 = (char *)0x1b950000;
        goto LAB_18001bf80;
      }
      pcVar7 = "COMPONENTS";
      iVar4 = strcmp(pcVar18,"COMPONENTS");
      if (iVar4 == 0) {
        pcVar18 = (char *)0x1b920000;
        goto LAB_18001bf80;
      }
      pcVar7 = "CALCULATOR";
      iVar4 = strcmp(pcVar18,"CALCULATOR");
      if (iVar4 == 0) {
        pcVar18 = (char *)0x1b08ff00;
        goto LAB_18001bf80;
      }
      pcVar7 = "BALANCE";
      lVar5 = 0;
      goto LAB_18001bb60;
    }
  }
  pcVar18 = (char *)0x1b09ff00;
  goto LAB_18001bf80;
  while (lVar5 = lVar6, lVar6 != 8) {
LAB_18001bb60:
    lVar6 = lVar5 + 1;
    if (pcVar18[lVar5] != "BALANCE"[lVar5]) {
      pcVar7 = "DIST-CURVE";
      iVar4 = strcmp(pcVar18,"DIST-CURVE");
      if (iVar4 == 0) {
        pcVar18 = (char *)0x1b0aff00;
        local_158._0_5_ = CONCAT14(DAT_1800414d8,DAT_1800414d4);
        goto LAB_18001bf80;
      }
      pcVar7 = "ECON-SUM";
      iVar4 = strcmp(pcVar18,"ECON-SUM");
      if (iVar4 == 0) {
        pcVar18 = (char *)0x1b930000;
        goto LAB_18001bf80;
      }
      pcVar7 = "RUN-STATUS";
      iVar4 = strcmp(pcVar18,"RUN-STATUS");
      if (iVar4 == 0) {
        pcVar18 = (char *)0x1b8c0000;
        goto LAB_18001bf80;
      }
      iVar4 = strcmp(pcVar18,"CONV-SUM");
      if (iVar4 != 0) {
        pcVar7 = "SENSITIVITY";
        iVar4 = strcmp(pcVar18,"SENSITIVITY");
        if (iVar4 == 0) {
          pcVar18 = (char *)0x1b05ff00;
          goto LAB_18001bf80;
        }
        pcVar7 = "EQUIP-SUM";
        iVar4 = strcmp(pcVar18,"EQUIP-SUM");
        if (iVar4 == 0) {
          pcVar18 = (char *)0x1b9a0000;
          goto LAB_18001bf80;
        }
        pcVar7 = "PROP-TABLE";
        iVar4 = strcmp(pcVar18,"PROP-TABLE");
        if (iVar4 == 0) {
          pcVar18 = (char *)0x1b85ff00;
          goto LAB_18001bf80;
        }
        pcVar7 = "COMPONENTS";
        iVar4 = strcmp(pcVar18,"COMPONENTS");
        if (iVar4 == 0) {
          pcVar18 = (char *)0x1b920000;
          goto LAB_18001bf80;
        }
        pcVar7 = "ECON-SUM";
        iVar4 = strcmp(pcVar18,"ECON-SUM");
        if (iVar4 == 0) {
          pcVar18 = (char *)0x1b930000;
          goto LAB_18001bf80;
        }
        lVar5 = 0;
        goto LAB_18001bd70;
      }
      pcVar21 = *(char **)(param_1 + 6);
      iVar4 = strcmp(pcVar21,"TEAR-SUMMARY");
      if (iVar4 == 0) {
        pcVar18 = (char *)0x1b8f0000;
      }
      else {
        iVar4 = strcmp(pcVar21,"SPEC-SUMMARY");
        if (iVar4 == 0) {
          pcVar18 = (char *)0x1b910000;
        }
        else {
          iVar4 = strcmp(pcVar21,"EOCV-SUMMARY");
          pcVar18 = local_2b8;
          if (iVar4 == 0) {
            pcVar18 = (char *)0x1bb10000;
          }
        }
      }
      pcVar7 = "TVAR-SUMMARY";
      iVar4 = strcmp(pcVar21,"TVAR-SUMMARY");
      if (iVar4 != 0) goto LAB_18001bc7c;
      pcVar18 = (char *)0x1bb6ff00;
      goto LAB_18001bf80;
    }
  }
  pcVar18 = (char *)0x1b0bff00;
  goto LAB_18001bf80;
LAB_18001bc7c:
  if (pcVar18 != (char *)0xffffffffffffffff) goto LAB_18001bf80;
LAB_18001bc86:
  if (*(longlong *)MDerror_exref != 0) goto LAB_18001bc97;
  if (local_2c8 == 0) {
    return 0;
  }
  goto LAB_18001c50b;
  while (lVar5 = lVar6, lVar6 != 6) {
LAB_18001bd70:
    lVar6 = lVar5 + 1;
    if (pcVar18[lVar5] != "BLOCK"[lVar5]) {
      pcVar7 = "TRANSFER";
      iVar4 = strcmp(pcVar18,"TRANSFER");
      if (iVar4 == 0) {
        pcVar18 = (char *)0x1b07ff00;
        goto LAB_18001bf80;
      }
      pcVar7 = "LOAD-SUM";
      iVar4 = strcmp(pcVar18,"LOAD-SUM");
      if (iVar4 == 0) {
        pcVar18 = (char *)0x1b0aff00;
        local_158 = CONCAT44(local_158._4_4_,0x4c4c41);
        goto LAB_18001bf80;
      }
      pcVar7 = "MEASUREMENT";
      iVar4 = strcmp(pcVar18,"MEASUREMENT");
      if (iVar4 == 0) {
        pcVar18 = (char *)0x1b0eff00;
        goto LAB_18001bf80;
      }
      pcVar7 = "OBJECTIVE";
      iVar4 = strcmp(pcVar18,"OBJECTIVE");
      if (iVar4 == 0) {
        pcVar18 = (char *)0x1ba8ff00;
        goto LAB_18001bf80;
      }
      pcVar7 = "CONNECTIONS";
      iVar4 = strcmp(pcVar18,"CONNECTIONS");
      if (iVar4 == 0) {
        pcVar18 = (char *)0x1ba90000;
        goto LAB_18001bf80;
      }
      pcVar7 = "SPECGROUPS";
      iVar4 = strcmp(pcVar18,"SPECGROUPS");
      if (iVar4 == 0) {
        pcVar18 = (char *)0x1baa0000;
        goto LAB_18001bf80;
      }
      pcVar7 = "INIT-VAR-ATT";
      iVar4 = strcmp(pcVar18,"INIT-VAR-ATT");
      if (iVar4 == 0) {
        pcVar18 = (char *)0x1bab0000;
        goto LAB_18001bf80;
      }
      pcVar7 = "STREAM-PRICE";
      iVar4 = strcmp(pcVar18,"STREAM-PRICE");
      if (iVar4 == 0) {
        pcVar18 = (char *)0x1bb00000;
        goto LAB_18001bf80;
      }
      pcVar7 = "EO-ALIAS";
      iVar4 = strcmp(pcVar18,"EO-ALIAS");
      if (iVar4 == 0) {
        pcVar18 = (char *)0x1bae0000;
        goto LAB_18001bf80;
      }
      pcVar7 = "DESIGN-SPEC";
      iVar4 = strcmp(pcVar18,"DESIGN-SPEC");
      if (iVar4 == 0) {
        pcVar18 = (char *)0x1b87ff00;
        goto LAB_18001bf80;
      }
      pcVar7 = "CONSTRAINT";
      iVar4 = strcmp(pcVar18,"CONSTRAINT");
      if (iVar4 == 0) {
        pcVar18 = (char *)0x1bb3ff00;
        goto LAB_18001bf80;
      }
      pcVar7 = "OPTIMIZATION";
      iVar4 = strcmp(pcVar18,"OPTIMIZATION");
      if (iVar4 == 0) {
        pcVar18 = (char *)0x1bb4ff00;
        goto LAB_18001bf80;
      }
      pcVar7 = "UTIL-SUMMARY";
      iVar4 = strcmp(pcVar18,"UTIL-SUMMARY");
      if (iVar4 == 0) {
        pcVar18 = (char *)0x1baf0000;
        goto LAB_18001bf80;
      }
      pcVar7 = "REACTIONS";
      iVar4 = strcmp(pcVar18,"REACTIONS");
      if (iVar4 == 0) {
        pcVar18 = (char *)0x1bb5ff00;
        goto LAB_18001bf80;
      }
      pcVar7 = "CONTROLLER";
      iVar4 = strcmp(pcVar18,"CONTROLLER");
      if (iVar4 == 0) {
        pcVar18 = (char *)0x1b11ff00;
        goto LAB_18001bf80;
      }
      pcVar7 = "BATCH-OPTS";
      iVar4 = strcmp(pcVar18,"BATCH-OPTS");
      if (iVar4 == 0) {
        pcVar18 = (char *)0x1b100000;
        goto LAB_18001bf80;
      }
      pcVar7 = "SENSOR";
      lVar5 = 0;
      goto LAB_18001bf64;
    }
  }
  pcVar18 = (char *)0x1b01ff00;
  goto LAB_18001bf80;
  while (lVar5 = lVar6, lVar6 != 7) {
LAB_18001bf64:
    lVar6 = lVar5 + 1;
    if (pcVar18[lVar5] != "SENSOR"[lVar5]) goto LAB_18001bc86;
  }
  pcVar18 = (char *)0x1b12ff00;
  goto LAB_18001bf80;
  while (lVar5 = lVar6, lVar6 != 8) {
LAB_18001b9d2:
    lVar6 = lVar5 + 1;
    if (pcVar18[lVar5] != "COSTING"[lVar5]) {
      pcVar7 = "UTILITY";
      lVar5 = 0;
      goto LAB_18001baa0;
    }
  }
  pcVar18 = *(char **)(param_1 + 6);
  pcVar7 = "EQUIPMENT";
  iVar4 = strcmp(pcVar18,"EQUIPMENT");
  if (iVar4 == 0) {
    pcVar18 = (char *)0x1b03ff00;
  }
  else {
    pcVar7 = "CAPITAL-COST";
    iVar4 = strcmp(pcVar18,"CAPITAL-COST");
    if (iVar4 == 0) {
      pcVar18 = (char *)0x1b8d0000;
    }
    else {
      pcVar7 = "OPERATING";
      iVar4 = strcmp(pcVar18,"OPERATING");
      if (iVar4 == 0) {
        pcVar18 = (char *)0x1b8e0000;
      }
      else {
        pcVar7 = "COST-SECTION";
        iVar4 = strcmp(pcVar18,"COST-SECTION");
        if (iVar4 == 0) {
          pcVar18 = (char *)0x1b96ff00;
        }
        else {
          pcVar7 = "UTILITY";
          lVar5 = 0;
          do {
            lVar6 = lVar5 + 1;
            if (pcVar18[lVar5] != "UTILITY"[lVar5]) goto LAB_18001bc86;
            lVar5 = lVar6;
          } while (lVar6 != 8);
          pcVar18 = (char *)0x1b09ff00;
        }
      }
    }
  }
LAB_18001bf80:
  if (*(longlong *)MDerror_exref != 0) {
LAB_18001bc97:
    ERclear(0);
    FUN_180008f80(local_148,"MDerror in QUERY code: %s",*(undefined8 *)(param_1 + 4),param_4);
    FUN_180028530(local_148,0);
    uVar12 = 0;
    goto LAB_18001bcc6;
  }
  if ((*(int *)bestinput_exref != 0) && (local_2b8 != (char *)0x0)) {
    if (local_2b8[0x107] == '\b') {
      pcVar21 = *(char **)(local_2b8 + 0x28);
      uVar19 = *(undefined8 *)(local_2b8 + 0x30);
    }
    else {
      pcVar21 = (char *)CONCAT44(uStack_2ac,uStack_2b0);
      uVar19 = CONCAT44(uVar24,uVar23);
    }
    pcVar7 = pcVar21;
    lVar5 = MDgetito(*(undefined8 *)iwpfile_exref,pcVar21,uVar19);
    if (lVar5 != 0) {
      lVar6 = MDgethkp(*(undefined8 *)iwpfile_exref,pcVar21,uVar19);
      pcVar7 = *(char **)(lVar5 + 8);
      iVar4 = AreDependenciesComplete(*(undefined8 *)(lVar5 + 0x10),pcVar7);
      if (((lVar6 != 0) && ((*(byte *)(lVar6 + 0x18) & 0xf) == 0)) || (iVar4 == 0)) {
        if (local_2c8 != 0) {
LAB_18001c50b:
          HYPopFinfo(local_2c8);
        }
        return 0;
      }
    }
  }
  if (*(longlong *)(*(longlong *)finfo_exref + 0x1e0) != 0) {
    puVar8 = (uint *)MDgetito(*(undefined8 *)iwpfile_exref,0xffffffffffffffff);
    uVar16 = *puVar8;
    pcVar7 = (char *)(ulonglong)uVar16;
    if (0 < (int)uVar16) {
      lVar5 = (longlong)(int)uVar16 * 0x2c + -0x22 + (longlong)puVar8;
      uVar20 = (ulonglong)uVar16;
      do {
        if (*(char *)(lVar5 + -1) == '\x01') {
          pbVar9 = *(byte **)(param_1 + 4);
          lVar6 = lVar5 - (longlong)pbVar9;
          do {
            pbVar1 = pbVar9 + lVar6;
            uVar16 = (uint)*pbVar9 - (uint)*pbVar1;
            pcVar7 = (char *)(ulonglong)uVar16;
            if (uVar16 != 0) break;
            pbVar9 = pbVar9 + 1;
          } while (*pbVar1 != 0);
          if (uVar16 == 0) {
            pbVar9 = (byte *)(lVar5 + 0x1c);
            lVar6 = -0x10 - (longlong)pbVar9;
            do {
              pbVar1 = pbVar9 + (longlong)(local_148 + lVar6);
              uVar16 = (uint)*pbVar9 - (uint)*pbVar1;
              pcVar7 = (char *)(ulonglong)uVar16;
              if (uVar16 != 0) break;
              pbVar9 = pbVar9 + 1;
            } while (*pbVar1 != 0);
            if (uVar16 == 0) {
              pcVar7 = (char *)0x0;
              strcpy_s((char *)&local_158,10,(char *)(lVar5 + 0xe));
            }
          }
        }
        lVar5 = lVar5 + -0x2c;
        uVar20 = uVar20 - 1;
      } while (uVar20 != 0);
    }
  }
  iVar4 = 0;
  lVar5 = 0;
  do {
    if (local_148[lVar5 + -0x10] == '\0') {
      if (iVar4 < 8) {
        memset(local_148 + (longlong)iVar4 + -0x10,
               (int)CONCAT71((int7)((ulonglong)pcVar7 >> 8),0x20),(longlong)(8 - iVar4));
      }
      break;
    }
    iVar4 = iVar4 + 1;
    lVar5 = lVar5 + 1;
  } while (lVar5 < 8);
  local_150 = local_150 & 0xff00;
  iVar4 = FUN_180030240((char *)0x0,local_268,0,(ulonglong)pcVar18,(char *)&local_158);
  if (iVar4 != 1) {
    if (iVar4 < 1) {
      uVar12 = GetSorResStringEx(0x1af);
      GetSorResStringEx(0x282);
      FUN_180008f80(local_148,"%s%s%s%s",uVar12,&DAT_18003f9bc);
      iVar4 = GRinqsme();
      if (iVar4 != 0) {
        lVar5 = GetSorResStringEx(0x283);
        puVar15 = &uStack_149;
        do {
          pcVar7 = puVar15 + 1;
          puVar15 = puVar15 + 1;
        } while (*pcVar7 != '\0');
        lVar6 = 0;
        do {
          cVar3 = *(char *)(lVar5 + lVar6);
          puVar15[lVar6] = cVar3;
          lVar6 = lVar6 + 1;
        } while (cVar3 != '\0');
      }
      FUN_180028530(local_148,-1);
      _DAT_180051ff8 = 1;
      uVar12 = 0xffffffff;
    }
    goto LAB_18001bcc6;
  }
  if (((local_260 != 1) || (local_254 != 1)) && ((1 < local_260 - 2U || (local_258 != 1)))) {
    uVar12 = 0;
    goto LAB_18001bcc6;
  }
  if ((local_2b8 == (char *)0x0) || (*(longlong *)(local_2b8 + 0x48) == 0)) {
LAB_18001c437:
    FUN_18002c620((longlong)APtmpfil_exref);
  }
  else {
    if (pcVar18 < (char *)0x1b910001) {
      if (pcVar18 == (char *)0x1b910000) goto LAB_18001c2c6;
      if (pcVar18 == (char *)0x1b0aff00) {
        FUN_18001d3c0((char *)&local_158,1);
        FUN_18002c620((longlong)APtmpfil_exref);
        goto LAB_18001bcc6;
      }
      if (pcVar18 == (char *)0x1b8c0000) {
        plVar10 = (longlong *)deref_ptr();
        lVar5 = *plVar10;
        if (lVar5 != 0) {
          do {
            plVar11 = (longlong *)deref_ptr(lVar5);
            lVar6 = *plVar11;
            lVar13 = 0;
            while (lVar14 = lVar13 + 1,
                  *(char *)((longlong)plVar11 + lVar13 + 8) == (&DAT_18004156c)[lVar13]) {
              lVar13 = lVar14;
              if (lVar14 == 7) {
                *plVar10 = lVar6;
                OPpurlnk(lVar5,0);
                free3(lVar5,0x28);
                FUN_18002c620((longlong)APtmpfil_exref);
                goto LAB_18001bcc6;
              }
            }
            lVar5 = lVar6;
            plVar10 = plVar11;
          } while (lVar6 != 0);
          FUN_18002c620((longlong)APtmpfil_exref);
          goto LAB_18001bcc6;
        }
        goto LAB_18001c437;
      }
      bVar22 = pcVar18 == (char *)0x1b8f0000;
    }
    else {
      if (pcVar18 == (char *)0x1b930000) {
        uVar12 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"ECON-SUM");
        do {
          do {
            do {
              lVar5 = MDfndsls(*(undefined8 *)iwpfile_exref,uVar12,1,0);
              lVar6 = MDrslcls(*(undefined8 *)iwpfile_exref,uVar12);
              lVar6 = lVar6 + lVar5 * 0x108;
            } while ((*(uint *)(lVar6 + 0x18) & 0x1f0) == 0x20);
            OPpurdst(lVar6,1);
          } while (*(longlong *)MDerror_exref == 0);
          ERclear(0);
        } while( true );
      }
      if (pcVar18 == (char *)0x1bb10000) goto LAB_18001c2c6;
      bVar22 = pcVar18 == (char *)0x1bb6ff00;
    }
    if (bVar22) {
LAB_18001c2c6:
      uVar12 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"CONV-SUM");
      do {
        do {
          lVar5 = MDfndsls(*(undefined8 *)iwpfile_exref,uVar12,1,0);
          lVar6 = MDrslcls(*(undefined8 *)iwpfile_exref,uVar12);
          lVar6 = lVar6 + lVar5 * 0x108;
        } while ((*(uint *)(lVar6 + 0x18) & 0x1f0) == 0x20);
        OPpurdst(lVar6,1);
        if (*(longlong *)MDerror_exref != 0) {
          ERclear(0);
        }
      } while( true );
    }
    OPpurdst(local_2b8,1);
    FUN_18002c620((longlong)APtmpfil_exref);
  }
LAB_18001bcc6:
  if (local_2c8 != 0) {
    HYPopFinfo();
  }
  return uVar12;
}

/* RVA 0x1c550 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_18001c550(longlong param_1,char *param_2,int param_3)

{
  char cVar1;
  char *_Str1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  longlong lVar8;
  char *pcVar9;
  int iVar10;
  undefined8 uVar11;
  ulonglong uVar12;
  undefined1 auStackY_2b8 [32];
  char local_268 [8];
  int local_260;
  int local_258;
  int local_254;
  char local_159;
  undefined8 local_158;
  undefined1 local_150;
  char local_148 [256];
  ulonglong local_48;
  
  local_48 = DAT_1800516d8 ^ (ulonglong)auStackY_2b8;
  lVar4 = 0;
  iVar10 = 1;
  if (DAT_180051ff0 != 0) {
    return 0;
  }
  if ((param_1 == 0) || (*(longlong *)(param_1 + 0xf0) == 0)) {
    pcVar9 = *(char **)(*(longlong *)finfo_exref + 0x1c0);
    MDrslcls(*(undefined8 *)iwpfile_exref,pcVar9);
  }
  else {
    pcVar9 = *(char **)(param_1 + 0xf8);
    lVar4 = MDrslcls(*(undefined8 *)iwpfile_exref,pcVar9);
    lVar4 = *(longlong *)(param_1 + 0xf0) * 0x108 + lVar4;
    if ((*(uint *)(lVar4 + 0x18) & 0x1000) == 0) {
      uVar11 = *(undefined8 *)(param_1 + 0xf0);
      uVar7 = *(undefined8 *)(param_1 + 0xf8);
      if (*(char *)(lVar4 + 0x107) == '\b') {
        uVar7 = *(undefined8 *)(lVar4 + 0x28);
        uVar11 = *(undefined8 *)(lVar4 + 0x30);
      }
      lVar5 = MDgetito(*(undefined8 *)iwpfile_exref,uVar7,uVar11);
      pcVar9 = *(char **)(lVar5 + 0x20);
      lVar5 = MDgethkp(*(undefined8 *)recfile_exref,pcVar9);
      if ((*(uint *)(lVar5 + 0x18) & 0x4000) == 0) {
        return 0;
      }
    }
  }
  iVar2 = GRinqiap();
  if (iVar2 != 1) {
    return 0;
  }
  iVar2 = GRinqcnn();
  if (iVar2 != 2) {
    return 0;
  }
  if ((((param_1 != 0) && (pcVar9 = *(char **)(param_1 + 0xf8), pcVar9 != (char *)0x0)) &&
      (lVar5 = MDgetde(*(undefined8 *)iwpfile_exref), lVar5 != 0)) &&
     ((*(longlong *)(lVar5 + 0x78) != 0 &&
      (pcVar9 = *(char **)(lVar5 + 0x70), pcVar9 != (char *)0x0)))) {
    HYGetFinfoCls();
  }
  uVar6 = HYPshFinfo();
  SBsetscp((char *)0x0);
  if (param_3 != 0) {
    iVar2 = 0;
    local_158 = 0x2020202020202020;
    if (0 < param_3) {
      do {
        if (*param_2 == '\0') {
          if (iVar10 == 1) {
            hide_mouse();
            HYloohie(&DAT_18003ae52);
            show_mouse();
          }
          goto LAB_18001c9b6;
        }
        strncpy((char *)&local_158,param_2,8);
        local_150 = 0;
        lVar4 = MDchkkey(*(undefined8 *)iwpfile_exref,*(undefined8 *)strclass_exref,1,&local_158);
        if (-1 < lVar4) {
          lVar5 = MDrslcls(*(undefined8 *)iwpfile_exref,*(undefined8 *)strclass_exref);
          lVar5 = lVar4 * 0x108 + lVar5;
          lVar4 = MDrslcls(*(undefined8 *)iwpfile_exref,*(undefined8 *)(lVar5 + 0x28));
          pcVar9 = "STREAM";
          lVar4 = lVar4 + *(longlong *)(lVar5 + 0x30) * 0x108;
          iVar3 = MDchkref(2,"STREAM");
          if (iVar3 == 0) {
            iVar3 = 0;
            lVar5 = 0;
            do {
              if (local_148[lVar5 + -0x10] == '\0') {
                if (iVar3 < 8) {
                  memset(local_148 + (longlong)iVar3 + -0x10,
                         (int)CONCAT71((int7)((ulonglong)pcVar9 >> 8),0x20),(longlong)(8 - iVar3));
                }
                break;
              }
              iVar3 = iVar3 + 1;
              lVar5 = lVar5 + 1;
            } while (lVar5 < 8);
            local_150 = 0;
            iVar3 = FUN_180030240((char *)0x0,local_268,0,0x1b0aff00,(char *)&local_158);
            if (iVar3 == 1) {
              iVar10 = local_254;
              if ((((int)_local_260 == 1) || (iVar10 = local_258, (int)_local_260 - 2U < 2)) &&
                 (iVar10 == 1)) {
                if ((lVar4 != 0) && (*(longlong *)(lVar4 + 0x48) != 0)) {
                  OPpurdst(lVar4,0);
                }
                FUN_18002c620((longlong)APtmpfil_exref);
                iVar10 = 1;
              }
              else {
                iVar10 = 0;
              }
            }
            else if (iVar3 < 1) {
              uVar7 = GetSorResStringEx(0x1af);
              GetSorResStringEx(0x282);
              FUN_180008f80(local_148,"%s%s%s",uVar7,&DAT_18003f9bc);
              FUN_180028530(local_148,-1);
              _DAT_180051ff8 = 1;
              HYPopFinfo(uVar6);
              return iVar3;
            }
          }
        }
        iVar2 = iVar2 + 1;
        param_2 = param_2 + 0xc;
      } while (iVar2 < param_3);
    }
    goto LAB_18001cb7b;
  }
  if (param_1 == 0) {
LAB_18001c860:
    uVar12 = 0x1b0aff00;
    local_158 = CONCAT44(local_158._4_4_,0x4c4c41);
  }
  else {
    _Str1 = *(char **)(param_1 + 0x10);
    pcVar9 = "STREAM-SUM";
    iVar2 = strcmp(_Str1,"STREAM-SUM");
    if (iVar2 == 0) goto LAB_18001c860;
    pcVar9 = "HEAT-SUM";
    iVar2 = strcmp(_Str1,"HEAT-SUM");
    if (iVar2 == 0) goto LAB_18001c860;
    pcVar9 = "LOAD-SUM";
    iVar2 = strcmp(_Str1,"LOAD-SUM");
    if (iVar2 == 0) goto LAB_18001c860;
    pcVar9 = "WORK-SUM";
    iVar2 = strcmp(_Str1,"WORK-SUM");
    if (iVar2 == 0) goto LAB_18001c860;
    lVar5 = 0;
    do {
      lVar8 = lVar5 + 1;
      if (_Str1[lVar5] != "STREAM"[lVar5]) {
        uVar12 = uVar6;
        goto LAB_18001c82f;
      }
      lVar5 = lVar8;
    } while (lVar8 != 7);
    local_158 = 0x2020202020202020;
    strncpy((char *)&local_158,(char *)(param_1 + 0x98),8);
    pcVar9 = *(char **)strclass_exref;
    lVar5 = MDchkkey(*(undefined8 *)iwpfile_exref,pcVar9,1,(char *)(param_1 + 0x98));
    if (lVar5 < 0) {
LAB_18001c822:
      iVar10 = 0;
    }
    else {
      lVar8 = MDrslcls(*(undefined8 *)iwpfile_exref,*(undefined8 *)strclass_exref);
      lVar8 = lVar5 * 0x108 + lVar8;
      lVar4 = MDrslcls(*(undefined8 *)iwpfile_exref,*(undefined8 *)(lVar8 + 0x28));
      pcVar9 = "STREAM";
      lVar4 = lVar4 + *(longlong *)(lVar8 + 0x30) * 0x108;
      iVar2 = MDchkref(2,"STREAM");
      if (iVar2 != 0) goto LAB_18001c822;
    }
    uVar12 = 0x1b0aff00;
  }
LAB_18001c82f:
  if ((iVar10 != 0) && (uVar12 != 0xffffffffffffffff)) {
    iVar2 = 0;
    lVar5 = 0;
    do {
      if (local_148[lVar5 + -0x10] == '\0') {
        if (iVar2 < 8) {
          memset(local_148 + (longlong)iVar2 + -0x10,
                 (int)CONCAT71((int7)((ulonglong)pcVar9 >> 8),0x20),(longlong)(8 - iVar2));
        }
        break;
      }
      iVar2 = iVar2 + 1;
      lVar5 = lVar5 + 1;
    } while (lVar5 < 8);
    local_150 = 0;
    iVar2 = FUN_180030240((char *)0x0,local_268,0,uVar12,(char *)&local_158);
    if (iVar2 == 1) {
      if (((local_260 == 1) && (local_254 == 1)) || ((local_260 - 2U < 2 && (local_258 == 1)))) {
        lVar5 = -1;
        do {
          lVar8 = lVar5;
          lVar5 = lVar8 + 1;
        } while (local_148[lVar8 + -0xf] != '\0');
        pcVar9 = local_148 + lVar8 + -0x10;
        cVar1 = local_148[lVar8 + -0x10];
        while (cVar1 == ' ') {
          *pcVar9 = '\0';
          pcVar9 = pcVar9 + -1;
          cVar1 = *pcVar9;
        }
        FUN_18001d3c0((char *)&local_158,1);
        if (DAT_180050a48 == 0) {
          HYReinitLSBEAD();
          DAT_180050a48 = DAT_180050a48 + 1;
        }
        if ((lVar4 != 0) && (*(longlong *)(lVar4 + 0x48) != 0)) {
          OPpurdst(lVar4,0);
        }
        FUN_18002c620((longlong)APtmpfil_exref);
        iVar10 = 1;
      }
      else {
        iVar10 = 0;
      }
    }
    else if (iVar2 < 1) {
      uVar7 = GetSorResStringEx(0x1af);
      GetSorResStringEx(0x282);
      FUN_180008f80(local_148,"%s%s%s",uVar7,&DAT_18003f9bc);
      iVar10 = -1;
      FUN_180028530(local_148,-1);
      _DAT_180051ff8 = 1;
    }
LAB_18001c9b6:
    HYPopFinfo(uVar6);
    return iVar10;
  }
LAB_18001cb7b:
  HYPopFinfo(uVar6);
  return 0;
}

/* RVA 0x1cc20 */
void FUN_18001cc20(void)

{
  FUN_18001c550(0,(char *)0x0,0);
  return;
}

/* RVA 0x1cc30 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_18001cc30(int param_1,int param_2,char *param_3,int param_4)

{
  longlong *plVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  char *pcVar5;
  longlong lVar6;
  longlong lVar7;
  undefined8 uVar8;
  longlong lVar9;
  undefined7 extraout_var;
  longlong lVar10;
  longlong lVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  longlong lVar14;
  longlong lVar15;
  undefined1 auStackY_518 [32];
  int local_4d8;
  undefined4 local_4d4;
  int local_4d0;
  undefined4 uStack_4cc;
  longlong local_4c8;
  longlong local_4c0;
  longlong local_498 [6];
  undefined8 local_468;
  undefined8 uStack_460;
  undefined8 local_458;
  char local_450 [24];
  undefined1 local_438 [1008];
  ulonglong local_48;
  
  local_48 = DAT_1800516d8 ^ (ulonglong)auStackY_518;
  local_468 = _DAT_1800416a0;
  uStack_460 = _UNK_1800416a8;
  local_458 = DAT_180041698;
  local_4d0 = param_1;
  if ((param_3 == (char *)0x0) || (*param_3 == '\0')) {
    FUN_180008f80(local_438,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\sor\\sbsim\\sbsetrsl.c",0xe0a);
    LogMessage(local_438,2,1);
    if (param_3 == (char *)0x0) {
      return 0xffffffff;
    }
  }
  if (*param_3 != '\0') {
    lVar9 = -(longlong)param_3;
    do {
      cVar2 = *param_3;
      param_3[(longlong)(local_450 + lVar9)] = cVar2;
      param_3 = param_3 + 1;
    } while (cVar2 != '\0');
    pcVar5 = strchr(local_450,0x20);
    if (pcVar5 != (char *)0x0) {
      *pcVar5 = '\0';
    }
    if (local_450[0] == '\0') {
      FUN_180008f80(local_438,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\sor\\sbsim\\sbsetrsl.c",0xe12);
      LogMessage(local_438,2,1);
      if (local_450[0] == '\0') {
        return 0xffffffff;
      }
    }
    lVar9 = 0;
    do {
      lVar10 = lVar9 + 1;
      if (local_450[lVar9] != (&DAT_18004049c)[lVar9]) {
        bVar3 = FUN_18001e1a0(param_1,param_2,local_450,local_498,&local_4d8,&local_4c8,
                              (undefined8 *)&local_4d0);
        if ((int)CONCAT71(extraout_var,bVar3) == 0) {
          return 0xffffffff;
        }
        lVar9 = CONCAT44(uStack_4cc,local_4d0);
        if (lVar9 == 0) {
          FUN_180008f80(local_438,"Assert failed in file %s line %d",
                        "G:\\Agent\\work\\2\\s\\src\\mm\\sor\\sbsim\\sbsetrsl.c",0xe7f);
          LogMessage(local_438,2,1);
        }
        lVar6 = (longlong)local_4d8;
        lVar10 = MDrslcls(*(undefined8 *)iwpfile_exref,local_498[lVar6]);
        lVar10 = lVar10 + lVar9 * 0x108;
        if (*(char *)(lVar10 + 0x107) == '\b') {
          lVar7 = MDrslcls(*(undefined8 *)iwpfile_exref,*(longlong *)(lVar10 + 0x28));
          plVar1 = (longlong *)(lVar10 + 0x30);
          lVar14 = *(longlong *)(lVar10 + 0x28);
          lVar10 = *plVar1 * 0x108 + lVar7;
          lVar7 = *plVar1;
        }
        else {
          if (*(char *)(lVar10 + 0x107) != '\x03') {
            return 0xffffffff;
          }
          lVar14 = local_498[lVar6];
          lVar7 = lVar9;
        }
        lVar14 = MDgetito(*(undefined8 *)iwpfile_exref,lVar14,lVar7);
        if ((param_1 == 1) && (*(longlong *)(lVar14 + 0x160) != 0)) {
          AcBlockDeleteOutput();
        }
        GRsavpgc(&local_4d4);
        if ((*(uint *)(lVar10 + 0x18) & 0x1f0) == 0x20) {
          return 0;
        }
        if (param_4 == 0) {
          return 1;
        }
        if (*(longlong *)(lVar10 + 0x48) != 0) {
          OPpurdst(lVar10,1);
        }
        MDprpcmp(local_498,local_4d8,local_4c8,lVar9);
        if (param_1 == 1) {
          pcVar5 = (char *)MDgetde(*(undefined8 *)iwpfile_exref,local_498[lVar6]);
          if (*pcVar5 == '\0') {
            FUN_180008f80(local_438,"Assert failed in file %s line %d",
                          "G:\\Agent\\work\\2\\s\\src\\mm\\sor\\sbsim\\sbsetrsl.c",0xea4);
            LogMessage(local_438,2,1);
          }
          GRset_global_block_data(pcVar5,lVar10,&local_468);
        }
        iVar4 = strncmp(local_450,"$OLVER",6);
        if (iVar4 == 0) {
          if (local_4c8 != 0) {
            uVar8 = MDfndkey(*(undefined8 *)iwpfile_exref,local_4c8,1,local_450);
            MDdelobj(*(undefined8 *)iwpfile_exref,local_4c8,uVar8);
            MDfrehnk(*(undefined8 *)iwpfile_exref,local_4c8,uVar8);
          }
          if (*(longlong *)(lVar10 + 0x60) != 0) {
            uVar8 = deref_ptr();
            HANotify(uVar8,6);
          }
          MDdelitm(*(undefined8 *)iwpfile_exref,local_498[lVar6],lVar10);
          if (*(longlong *)MDerror_exref != 0) {
            ERclear(0);
          }
        }
        GRsetpgc(local_4d4);
        return 0;
      }
      lVar9 = lVar10;
    } while (lVar10 != 4);
    if (param_4 == 0) {
      return 1;
    }
    iVar4 = FUN_18001db20(param_1,param_2,local_498,&local_4d8,&local_4c8);
    if (iVar4 != 0) {
      GRsavpgc(&local_4d4);
      lVar10 = local_4c8;
      uVar12 = (ulonglong)local_4d8;
      lVar9 = local_4c8;
      if (local_4c8 == 0) {
        lVar9 = local_498[uVar12];
      }
      if (lVar9 == 0) {
        FUN_180008f80(local_438,"Assert failed in file %s line %d",
                      "G:\\Agent\\work\\2\\s\\src\\mm\\sor\\sbsim\\sbsetrsl.c",0xe21);
        LogMessage(local_438,2,1);
      }
      local_4c8 = MDrslcls(*(undefined8 *)iwpfile_exref,lVar9);
      local_4c0 = 0;
      do {
        lVar14 = local_4c8;
        lVar7 = 0;
        lVar6 = MDfndsls(*(undefined8 *)iwpfile_exref,lVar9,1);
        if (local_4c0 == -1) break;
        lVar14 = lVar6 * 0x108 + lVar14;
        if (*(char *)(lVar14 + 0x107) == '\b') {
          lVar7 = MDrslcls(*(undefined8 *)iwpfile_exref,*(longlong *)(lVar14 + 0x28));
          lVar6 = *(longlong *)(lVar14 + 0x30);
          lVar11 = *(longlong *)(lVar14 + 0x28);
          lVar15 = lVar6 * 0x108 + lVar7;
          lVar7 = lVar14;
LAB_18001cea6:
          lVar6 = MDgetito(*(undefined8 *)iwpfile_exref,lVar11,lVar6);
          if ((local_4d0 == 1) && (*(longlong *)(lVar6 + 0x160) != 0)) {
            AcBlockDeleteOutput();
          }
          if ((*(uint *)(lVar15 + 0x18) & 0x1f0) != 0x20) {
            if (*(longlong *)(lVar15 + 0x48) != 0) {
              OPpurdst(lVar15,1);
            }
            uVar13 = uVar12;
            if ((lVar10 != 0) && (lVar7 != 0)) {
              uVar13 = (ulonglong)((int)uVar12 + 1);
              local_498[(longlong)(int)uVar12 + 1] = *(longlong *)(lVar7 + 0x28);
            }
            MDprpcmp(local_498,uVar13 & 0xffffffff,lVar10);
            if (local_4d0 == 1) {
              pcVar5 = (char *)MDgetde(*(undefined8 *)iwpfile_exref,local_498[(int)uVar13]);
              if (*pcVar5 == '\0') {
                FUN_180008f80(local_438,"Assert failed in file %s line %d",
                              "G:\\Agent\\work\\2\\s\\src\\mm\\sor\\sbsim\\sbsetrsl.c",0xe54);
                LogMessage(local_438,2,1);
              }
              GRset_global_block_data(pcVar5,lVar15,&local_468);
            }
            uVar12 = uVar12 & 0xffffffff;
          }
        }
        else if (*(char *)(lVar14 + 0x107) == '\x03') {
          lVar11 = lVar9;
          lVar15 = lVar14;
          goto LAB_18001cea6;
        }
      } while (local_4c0 != -1);
      if (local_4d0 == 2) {
        local_498[0] = *(longlong *)dataclass_exref;
        local_4c0 = 0;
        uVar8 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"CONV-SUM");
        local_498[1] = uVar8;
        if (*(longlong *)MDerror_exref != 0) {
          ERclear(0);
          local_4c0 = 0xffffffffffffffff;
          GRsetpgc(local_4d4);
          return 0;
        }
        while ((local_4c0 != -1 &&
               (lVar9 = MDfndsls(*(undefined8 *)iwpfile_exref,uVar8,1), local_4c0 != -1))) {
          lVar10 = MDrslcls(*(undefined8 *)iwpfile_exref,uVar8);
          lVar10 = lVar10 + lVar9 * 0x108;
          if ((*(uint *)(lVar10 + 0x18) & 0x1f0) != 0x20) {
            if (*(longlong *)(lVar10 + 0x48) != 0) {
              OPpurdst(lVar10,1);
            }
            if (*(longlong *)MDerror_exref == 0) {
              MDprpcmp(local_498,1);
            }
            else {
              ERclear(0);
            }
          }
        }
      }
      GRsetpgc(local_4d4);
      return 0;
    }
  }
  return 0xffffffff;
}

/* RVA 0x1d3c0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_18001d3c0(char *param_1,int param_2)

{
  undefined8 uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  undefined1 auStack_148 [32];
  longlong *local_128;
  undefined8 local_120;
  undefined4 local_118;
  undefined4 local_108 [2];
  longlong local_100 [5];
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined4 local_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  ulonglong local_28;
  
  local_28 = DAT_1800516d8 ^ (ulonglong)auStack_148;
  local_88 = _DAT_1800416a0;
  uStack_84 = _UNK_1800416a4;
  uStack_80 = _UNK_1800416a8;
  uStack_7c = _UNK_1800416ac;
  local_78 = _DAT_1800416a0;
  uStack_74 = _UNK_1800416a4;
  uStack_70 = _UNK_1800416a8;
  uStack_6c = _UNK_1800416ac;
  local_68 = _DAT_1800416a0;
  uStack_64 = _UNK_1800416a4;
  uStack_60 = _UNK_1800416a8;
  uStack_5c = _UNK_1800416ac;
  local_58 = _DAT_1800416a0;
  uStack_54 = _UNK_1800416a4;
  uStack_50 = _UNK_1800416a8;
  uStack_4c = _UNK_1800416ac;
  local_48 = _DAT_1800416a0;
  uStack_44 = _UNK_1800416a4;
  uStack_40 = _UNK_1800416a8;
  uStack_3c = _UNK_1800416ac;
  local_38 = _DAT_1800416a0;
  uStack_34 = _UNK_1800416a4;
  uStack_30 = _UNK_1800416a8;
  uStack_2c = _UNK_1800416ac;
  local_98 = 0xffffffffffffffff;
  local_a8 = _DAT_1800412d0;
  uStack_a0 = _UNK_1800412d8;
  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {
    local_d8 = *(undefined8 *)dataclass_exref;
    if (param_2 == 1) {
      lVar2 = 0;
      do {
        lVar4 = lVar2 + 1;
        if (param_1[lVar2] != (&DAT_18004049c)[lVar2]) goto LAB_18001d99b;
        lVar2 = lVar4;
      } while (lVar4 != 4);
      GRsavpgc(local_108);
      uVar1 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"STREAM");
      local_100[0] = 0;
      do {
        local_128 = local_100;
        local_120 = 0;
        lVar2 = MDfndsls(*(undefined8 *)iwpfile_exref,uVar1,1);
        if (local_100[0] == -1) break;
        lVar4 = MDrslcls(*(undefined8 *)iwpfile_exref,uVar1);
        lVar4 = lVar4 + lVar2 * 0x108;
        lVar2 = *(longlong *)(lVar4 + 0x30);
        lVar3 = MDrslcls(*(undefined8 *)iwpfile_exref,*(undefined8 *)(lVar4 + 0x28));
        lVar3 = lVar3 + lVar2 * 0x108;
        MDgetito(*(undefined8 *)iwpfile_exref,*(undefined8 *)(lVar4 + 0x28),lVar2);
        if ((*(uint *)(lVar3 + 0x18) & 0x1f0) != 0x20) {
          if (*(longlong *)(lVar3 + 0x48) != 0) {
            OPpurdst(lVar3,1);
          }
          lVar2 = MDrslcls(*(undefined8 *)iwpfile_exref,*(undefined8 *)strclass_exref);
          local_118 = 9999;
          local_120 = CONCAT44(local_120._4_4_,2);
          local_d0 = *(undefined8 *)(lVar2 + 0x148);
          local_c8 = *(undefined8 *)(lVar4 + 0x28);
          local_128._0_4_ = 9999;
          MDprpcmp(&local_d8,2,*(undefined8 *)strclass_exref,*(undefined8 *)(lVar4 + 0x30));
          local_128 = (longlong *)CONCAT44(local_128._4_4_,1);
          GRset_global_stream_data("MATERIAL",lVar3,&local_88);
        }
      } while (local_100[0] != -1);
      local_d8 = *(undefined8 *)dataclass_exref;
      lVar2 = MDchkkey(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,1,"HEAT-SUM");
      if (0 < lVar2) {
        lVar4 = MDrslcls(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref);
        lVar4 = lVar4 + lVar2 * 0x108;
        if ((*(uint *)(lVar4 + 0x18) & 0x1f0) != 0x20) {
          if (*(longlong *)(lVar4 + 0x48) != 0) {
            OPpurdst(lVar4,1);
          }
          if (*(longlong *)MDerror_exref == 0) {
            local_118 = 9999;
            local_120 = CONCAT44(local_120._4_4_,2);
            local_128 = (longlong *)CONCAT44(local_128._4_4_,9999);
            MDprpcmp(&local_d8,0,0,lVar2);
          }
          else {
            ERclear(0);
          }
        }
      }
      lVar2 = MDchkkey(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,1,"WORK-SUM");
      if (0 < lVar2) {
        lVar4 = MDrslcls(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref);
        lVar4 = lVar4 + lVar2 * 0x108;
        if ((*(uint *)(lVar4 + 0x18) & 0x1f0) != 0x20) {
          if (*(longlong *)(lVar4 + 0x48) != 0) {
            OPpurdst(lVar4,1);
          }
          if (*(longlong *)MDerror_exref == 0) {
            local_118 = 9999;
            local_120 = CONCAT44(local_120._4_4_,2);
            local_128 = (longlong *)CONCAT44(local_128._4_4_,9999);
            MDprpcmp(&local_d8,0,0,lVar2);
          }
          else {
            ERclear(0);
          }
        }
      }
      lVar2 = MDchkkey(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,1,"LOAD-SUM");
      if (0 < lVar2) {
        lVar4 = MDrslcls(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref);
        lVar4 = lVar4 + lVar2 * 0x108;
        if ((*(uint *)(lVar4 + 0x18) & 0x1f0) != 0x20) {
          if (*(longlong *)(lVar4 + 0x48) != 0) {
            OPpurdst(lVar4,1);
          }
          if (*(longlong *)MDerror_exref == 0) {
            local_118 = 9999;
            local_120 = CONCAT44(local_120._4_4_,2);
            local_128 = (longlong *)CONCAT44(local_128._4_4_,9999);
            MDprpcmp(&local_d8,0,0,lVar2);
          }
          else {
            ERclear(0);
          }
        }
      }
      lVar2 = MDchkkey(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,1,"STREAM-SUM");
      if (0 < lVar2) {
        lVar4 = MDrslcls(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref);
        lVar4 = lVar4 + lVar2 * 0x108;
        if ((*(uint *)(lVar4 + 0x18) & 0x1f0) != 0x20) {
          if (*(longlong *)(lVar4 + 0x48) != 0) {
            OPpurdst(lVar4,1);
          }
          if (*(longlong *)MDerror_exref == 0) {
            local_118 = 9999;
            local_120 = CONCAT44(local_120._4_4_,2);
            local_128 = (longlong *)CONCAT44(local_128._4_4_,9999);
            MDprpcmp(&local_d8,0,0,lVar2);
          }
          else {
            ERclear(0);
          }
        }
      }
      lVar2 = MDchkkey(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,1,"DIST-CURVE");
      if (0 < lVar2) {
        lVar4 = MDrslcls(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref);
        lVar4 = lVar4 + lVar2 * 0x108;
        if ((*(uint *)(lVar4 + 0x18) & 0x1f0) != 0x20) {
          if (*(longlong *)(lVar4 + 0x48) != 0) {
            OPpurdst(lVar4,1);
          }
          if (*(longlong *)MDerror_exref == 0) {
            local_118 = 9999;
            local_120 = CONCAT44(local_120._4_4_,2);
            local_128 = (longlong *)CONCAT44(local_128._4_4_,9999);
            MDprpcmp(&local_d8,0,0,lVar2);
            GRsetpgc(local_108[0]);
            return 0;
          }
          ERclear(0);
        }
      }
      GRsetpgc(local_108[0]);
      return 0;
    }
LAB_18001d99b:
    lVar2 = MDchkkey(*(undefined8 *)iwpfile_exref,*(undefined8 *)strclass_exref,1);
    if (-1 < lVar2) {
      lVar4 = MDrslcls(*(undefined8 *)iwpfile_exref,*(undefined8 *)strclass_exref);
      lVar4 = lVar4 + lVar2 * 0x108;
      lVar2 = *(longlong *)(lVar4 + 0x30);
      lVar3 = MDrslcls(*(undefined8 *)iwpfile_exref,*(undefined8 *)(lVar4 + 0x28));
      lVar3 = lVar3 + lVar2 * 0x108;
      if (param_2 == 0) {
        return (ulonglong)((*(uint *)(lVar3 + 0x18) & 0x1f0) != 0x20);
      }
      MDgetito(*(undefined8 *)iwpfile_exref,*(undefined8 *)(lVar4 + 0x28),lVar2);
      if ((*(uint *)(lVar3 + 0x18) & 0x1f0) != 0x20) {
        if (*(longlong *)(lVar3 + 0x48) != 0) {
          OPpurdst(lVar3,0);
        }
        lVar2 = MDrslcls(*(undefined8 *)iwpfile_exref,*(undefined8 *)strclass_exref);
        local_118 = 9999;
        local_120 = CONCAT44(local_120._4_4_,2);
        local_d0 = *(undefined8 *)(lVar2 + 0x148);
        local_c8 = *(undefined8 *)(lVar4 + 0x28);
        local_128._0_4_ = 9999;
        MDprpcmp(&local_d8,2,*(undefined8 *)strclass_exref,*(undefined8 *)(lVar4 + 0x30));
        local_128 = (longlong *)CONCAT44(local_128._4_4_,1);
        GRset_global_stream_data("MATERIAL",lVar3,&local_88,&local_a8);
      }
      return 0;
    }
  }
  return 0xffffffff;
}

/* RVA 0x1db20 */
undefined4
FUN_18001db20(undefined4 param_1,int param_2,undefined8 *param_3,undefined4 *param_4,
             undefined8 *param_5)

{
  undefined8 uVar1;
  longlong lVar2;
  undefined4 uVar3;
  char *pcVar4;
  
  *param_3 = *(undefined8 *)dataclass_exref;
  uVar3 = 1;
  switch(param_1) {
  case 1:
    lVar2 = MDrslcls(*(undefined8 *)iwpfile_exref,*(undefined8 *)blkclass_exref);
    param_3[1] = *(undefined8 *)(lVar2 + 0x148);
    *param_4 = 1;
    *param_5 = *(undefined8 *)blkclass_exref;
    break;
  case 2:
    pcVar4 = "CONVERGENCE";
    goto LAB_18001e087;
  case 3:
    uVar1 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"COSTING");
    pcVar4 = "EQUIPMENT";
LAB_18001dc66:
    param_3[1] = uVar1;
    uVar1 = MDfnddir(*(undefined8 *)iwpfile_exref,uVar1,pcVar4);
    *param_5 = uVar1;
    lVar2 = MDrslcls(*(undefined8 *)iwpfile_exref,uVar1);
    param_3[2] = *(undefined8 *)(lVar2 + 0x148);
    *param_4 = 2;
    break;
  case 5:
    uVar1 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"SENSITIVITY");
    param_3[1] = uVar1;
    *param_4 = 1;
    *param_5 = 0;
    break;
  case 7:
    uVar1 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"TRANSFER");
    param_3[1] = uVar1;
    *param_4 = 1;
    *param_5 = 0;
    break;
  case 8:
    uVar1 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"CALCULATOR");
    param_3[1] = uVar1;
    *param_4 = 1;
    *param_5 = 0;
    break;
  case 9:
    if ((param_2 != 0xd) && (param_2 != 0)) {
      uVar1 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"COSTING");
      pcVar4 = "UTILITY";
      goto LAB_18001dc66;
    }
    uVar1 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"UTILITY");
    param_3[1] = uVar1;
    *param_4 = 1;
    *param_5 = 0;
    break;
  case 0xb:
    uVar1 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"BALANCE");
    param_3[1] = uVar1;
    *param_4 = 1;
    *param_5 = 0;
    break;
  case 0xc:
    uVar1 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"PRES-RELIEF");
    param_3[1] = uVar1;
    *param_4 = 1;
    *param_5 = 0;
    break;
  case 0xd:
    uVar1 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"DATA-FIT");
    pcVar4 = "REGRESSION";
LAB_18001de3a:
    param_3[1] = uVar1;
    uVar1 = MDfnddir(*(undefined8 *)iwpfile_exref,uVar1,pcVar4);
    param_3[2] = uVar1;
    *param_4 = 2;
    *param_5 = 0;
    break;
  case 0xe:
    uVar1 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"MEASUREMENT");
    param_3[1] = uVar1;
    *param_4 = 1;
    *param_5 = 0;
    break;
  case 0x10:
    uVar1 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"DESIGN-SPEC");
    param_3[1] = uVar1;
    *param_4 = 1;
    *param_5 = 0;
    break;
  case 0x11:
    uVar1 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"CONSTRAINT");
    param_3[1] = uVar1;
    *param_4 = 1;
    *param_5 = 0;
    break;
  case 0x12:
    uVar1 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"OPTIMIZATION");
    param_3[1] = uVar1;
    *param_4 = 1;
    *param_5 = 0;
    break;
  case 0x13:
    pcVar4 = "REACTIONS";
LAB_18001e087:
    uVar1 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,pcVar4);
LAB_18001e0a6:
    lVar2 = MDrslcls(*(undefined8 *)iwpfile_exref,uVar1);
    param_3[1] = *(undefined8 *)(lVar2 + 0x148);
    *param_4 = 1;
    *param_5 = uVar1;
    break;
  case 0xffffffd1:
    uVar1 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"UTIL-SUMMARY");
    param_3[1] = uVar1;
    *param_4 = 1;
    *param_5 = 0;
    break;
  default:
    return 0;
  case 0xffffffd3:
    uVar1 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"EO-PORT");
    if (*(longlong *)MDerror_exref != 0) goto LAB_18001e0d6;
    goto LAB_18001e0a6;
  case 0xffffffd8:
    uVar1 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"OBJECTIVE");
    if (*(longlong *)MDerror_exref == 0) goto LAB_18001e0a6;
    goto LAB_18001e0d6;
  case 0xffffffea:
    uVar1 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"COSTING");
    pcVar4 = "COST-SECTION";
    goto LAB_18001de3a;
  case 0xfffffff5:
  case 0xfffffff6:
    *param_3 = *(undefined8 *)(*(longlong *)topfinfo_exref + 0x168);
    uVar1 = MDfnddir(*(undefined8 *)iwpfile_exref,
                     *(undefined8 *)(*(longlong *)topfinfo_exref + 0x168),"COMPONENTS");
    param_3[1] = uVar1;
    uVar1 = MDfnddir(*(undefined8 *)iwpfile_exref,uVar1,&DAT_180041388);
    param_3[2] = uVar1;
    uVar1 = MDfnddir(*(undefined8 *)iwpfile_exref,uVar1,"ASSAY-BLEND");
    *param_5 = uVar1;
    lVar2 = MDrslcls(*(undefined8 *)iwpfile_exref,uVar1);
    param_3[3] = *(undefined8 *)(lVar2 + 0x148);
    *param_4 = 3;
    break;
  case 0xfffffffb:
    uVar1 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"PROP-TABLE");
    *param_5 = uVar1;
    lVar2 = MDrslcls(*(undefined8 *)iwpfile_exref,uVar1);
    param_3[1] = *(undefined8 *)(lVar2 + 0x148);
    *param_4 = 1;
  }
  if (*(longlong *)MDerror_exref != 0) {
LAB_18001e0d6:
    ERclear(0);
    uVar3 = 0;
  }
  return uVar3;
}

/* RVA 0x1e1a0 */
bool FUN_18001e1a0(undefined4 param_1,int param_2,char *param_3,undefined8 *param_4,
                  undefined4 *param_5,undefined8 *param_6,undefined8 *param_7)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  longlong lVar4;
  uint uVar5;
  char *pcVar6;
  
  uVar5 = 0;
  *param_4 = *(undefined8 *)dataclass_exref;
  switch(param_1) {
  case 1:
    lVar4 = MDrslcls(*(undefined8 *)iwpfile_exref,*(undefined8 *)blkclass_exref);
    param_4[1] = *(undefined8 *)(lVar4 + 0x148);
    lVar4 = MDchkkey(*(undefined8 *)iwpfile_exref,*(undefined8 *)blkclass_exref,1,param_3);
    if (lVar4 < 0) {
      uVar5 = 1;
    }
    else {
      lVar1 = MDrslcls(*(undefined8 *)iwpfile_exref,*(undefined8 *)blkclass_exref);
      lVar1 = lVar1 + lVar4 * 0x108;
      param_4[2] = *(undefined8 *)(lVar1 + 0x28);
      *param_5 = 2;
      *param_6 = *(undefined8 *)blkclass_exref;
      *param_7 = *(undefined8 *)(lVar1 + 0x30);
    }
    goto LAB_18001ea82;
  case 2:
    uVar2 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"CONVERGENCE");
    lVar4 = MDrslcls(*(undefined8 *)iwpfile_exref,uVar2);
    param_4[1] = *(undefined8 *)(lVar4 + 0x148);
    lVar4 = MDchkkey(*(undefined8 *)iwpfile_exref,uVar2,1,param_3);
    uVar5 = 0;
    if (lVar4 < 0) {
      uVar5 = 1;
      if (*param_3 != '$') goto LAB_18001ea82;
      uVar3 = FUN_18001aac0((&PTR_DAT_1800509e0)[param_2],param_3,param_4[1],uVar2);
      if ((int)uVar3 != 0) {
        return false;
      }
      lVar4 = MDfndkey(*(undefined8 *)iwpfile_exref,uVar2,1,param_3);
      uVar5 = 1;
    }
    lVar1 = MDrslcls(*(undefined8 *)iwpfile_exref,uVar2);
    goto LAB_18001e33f;
  case 3:
    uVar2 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"COSTING");
    pcVar6 = "EQUIPMENT";
LAB_18001e53d:
    param_4[1] = uVar2;
    uVar2 = MDfnddir(*(undefined8 *)iwpfile_exref,uVar2,pcVar6);
    *param_6 = uVar2;
    lVar4 = MDrslcls(*(undefined8 *)iwpfile_exref,uVar2);
    param_4[2] = *(undefined8 *)(lVar4 + 0x148);
    lVar4 = MDchkkey(*(undefined8 *)iwpfile_exref,*param_6,1,param_3);
    if (-1 < lVar4) {
      lVar1 = MDrslcls(*(undefined8 *)iwpfile_exref,*param_6);
      lVar1 = lVar1 + lVar4 * 0x108;
      param_4[3] = *(undefined8 *)(lVar1 + 0x28);
      *param_7 = *(undefined8 *)(lVar1 + 0x30);
      *param_5 = 3;
      goto LAB_18001ea82;
    }
LAB_18001e59b:
    uVar5 = 1;
    goto LAB_18001ea82;
  case 5:
    pcVar6 = "SENSITIVITY";
    break;
  case 7:
    pcVar6 = "TRANSFER";
    break;
  case 8:
    pcVar6 = "CALCULATOR";
    break;
  case 9:
    if ((param_2 != 0xd) && (param_2 != 0)) {
      uVar2 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"COSTING");
      pcVar6 = "UTILITY";
      goto LAB_18001e53d;
    }
    pcVar6 = "UTILITY";
    break;
  case 0xb:
    pcVar6 = "BALANCE";
    break;
  case 0xc:
    pcVar6 = "PRES-RELIEF";
    break;
  case 0xd:
    uVar2 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"DATA-FIT");
    pcVar6 = "REGRESSION";
LAB_18001e68d:
    param_4[1] = uVar2;
    uVar2 = MDfnddir(*(undefined8 *)iwpfile_exref,uVar2,pcVar6);
    param_4[2] = uVar2;
    uVar2 = MDchkkey(*(undefined8 *)iwpfile_exref,uVar2,1,param_3);
    *param_7 = uVar2;
    *param_5 = 2;
    goto LAB_18001ea74;
  case 0xe:
    pcVar6 = "MEASUREMENT";
    break;
  case 0x10:
    uVar2 = MDchkkey(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,1,"BATCH-OPTS");
    *param_7 = uVar2;
    *param_5 = 0;
    goto LAB_18001ea74;
  case 0x11:
    uVar2 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"CONTROLLER");
    lVar4 = MDrslcls(*(undefined8 *)iwpfile_exref,uVar2);
    param_4[1] = *(undefined8 *)(lVar4 + 0x148);
    lVar4 = MDchkkey(*(undefined8 *)iwpfile_exref,uVar2,1,param_3);
    if (lVar4 < 0) {
      uVar5 = 1;
      goto LAB_18001ea82;
    }
    goto LAB_18001e326;
  case 0x12:
    uVar2 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"SENSOR");
    lVar4 = MDrslcls(*(undefined8 *)iwpfile_exref,uVar2);
    param_4[1] = *(undefined8 *)(lVar4 + 0x148);
    lVar4 = MDchkkey(*(undefined8 *)iwpfile_exref,uVar2,1,param_3);
    if (lVar4 < 0) {
      uVar5 = 1;
      goto LAB_18001ea82;
    }
LAB_18001e326:
    lVar1 = MDrslcls(*(undefined8 *)iwpfile_exref,uVar2);
    uVar5 = 0;
LAB_18001e33f:
    lVar1 = lVar1 + lVar4 * 0x108;
    param_4[2] = *(undefined8 *)(lVar1 + 0x28);
    *param_5 = 2;
    *param_6 = uVar2;
    *param_7 = *(undefined8 *)(lVar1 + 0x30);
    goto LAB_18001ea82;
  case 0x65:
    param_4[1] = *(undefined8 *)dataclass_exref;
    param_3 = "STREAM-PRICE";
    uVar2 = *(undefined8 *)dataclass_exref;
    goto LAB_18001e3fc;
  case 0xffffffcb:
    uVar2 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"REACTIONS");
    lVar4 = MDrslcls(*(undefined8 *)iwpfile_exref,uVar2);
    param_4[1] = *(undefined8 *)(lVar4 + 0x148);
    lVar4 = MDchkkey(*(undefined8 *)iwpfile_exref,uVar2,1,param_3);
    if (lVar4 < 0) {
      uVar5 = 1;
      goto LAB_18001ea82;
    }
    goto LAB_18001e326;
  case 0xffffffcc:
    pcVar6 = "OPTIMIZATION";
    break;
  case 0xffffffcd:
    pcVar6 = "CONSTRAINT";
    break;
  default:
    return false;
  case 0xffffffd1:
    pcVar6 = "UTIL-SUMMARY";
    break;
  case 0xffffffd3:
    uVar2 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"EO-PORT");
    param_4[1] = uVar2;
    uVar2 = MDchkkey(*(undefined8 *)iwpfile_exref,uVar2,1,param_3);
    uVar5 = (uint)((ulonglong)uVar2 >> 0x20);
    *param_7 = uVar2;
    *param_5 = 1;
    goto LAB_18001ea7a;
  case 0xffffffd8:
    uVar2 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"OBJECTIVE");
    lVar4 = MDrslcls(*(undefined8 *)iwpfile_exref,uVar2);
    param_4[1] = *(undefined8 *)(lVar4 + 0x148);
    lVar4 = MDchkkey(*(undefined8 *)iwpfile_exref,uVar2,1,param_3);
    if (lVar4 < 0) {
      uVar5 = 1;
      goto LAB_18001ea82;
    }
    goto LAB_18001e326;
  case 0xffffffea:
    uVar2 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"COSTING");
    pcVar6 = "COST-SECTION";
    goto LAB_18001e68d;
  case 0xfffffff5:
  case 0xfffffff6:
    *param_4 = *(undefined8 *)(*(longlong *)topfinfo_exref + 0x168);
    uVar2 = MDfnddir(*(undefined8 *)iwpfile_exref,
                     *(undefined8 *)(*(longlong *)topfinfo_exref + 0x168),"COMPONENTS");
    param_4[1] = uVar2;
    uVar2 = MDfnddir(*(undefined8 *)iwpfile_exref,uVar2,&DAT_180041388);
    param_4[2] = uVar2;
    uVar2 = MDfnddir(*(undefined8 *)iwpfile_exref,uVar2,"ASSAY-BLEND");
    *param_6 = uVar2;
    lVar4 = MDrslcls(*(undefined8 *)iwpfile_exref,uVar2);
    param_4[3] = *(undefined8 *)(lVar4 + 0x148);
    lVar4 = MDchkkey(*(undefined8 *)iwpfile_exref,*param_6,1,param_3);
    if (-1 < lVar4) {
      lVar1 = MDrslcls(*(undefined8 *)iwpfile_exref,*param_6);
      lVar1 = lVar1 + lVar4 * 0x108;
      param_4[4] = *(undefined8 *)(lVar1 + 0x28);
      *param_7 = *(undefined8 *)(lVar1 + 0x30);
      *param_5 = 4;
      goto LAB_18001ea82;
    }
    goto LAB_18001e59b;
  case 0xfffffff9:
    pcVar6 = "DESIGN-SPEC";
    break;
  case 0xfffffffb:
    uVar2 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"PROP-TABLE");
    *param_6 = uVar2;
    lVar4 = MDrslcls(*(undefined8 *)iwpfile_exref,uVar2);
    param_4[1] = *(undefined8 *)(lVar4 + 0x148);
    lVar4 = MDchkkey(*(undefined8 *)iwpfile_exref,*param_6,1,param_3);
    if (-1 < lVar4) {
      lVar1 = MDrslcls(*(undefined8 *)iwpfile_exref,*param_6);
      lVar1 = lVar1 + lVar4 * 0x108;
      param_4[2] = *(undefined8 *)(lVar1 + 0x28);
      *param_5 = 2;
      *param_7 = *(undefined8 *)(lVar1 + 0x30);
      goto LAB_18001ea82;
    }
    goto LAB_18001e59b;
  }
  uVar2 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,pcVar6);
  param_4[1] = uVar2;
LAB_18001e3fc:
  uVar2 = MDchkkey(*(undefined8 *)iwpfile_exref,uVar2,1,param_3);
  *param_7 = uVar2;
  *param_5 = 1;
LAB_18001ea74:
  uVar5 = (uint)((ulonglong)uVar2 >> 0x20);
LAB_18001ea7a:
  uVar5 = uVar5 >> 0x1f;
  *param_6 = 0;
LAB_18001ea82:
  lVar4 = *(longlong *)MDerror_exref;
  if (lVar4 != 0) {
    ERclear(0);
  }
  return lVar4 == 0 && uVar5 != 1;
}

/* RVA 0x1ebd0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18001ebd0(undefined4 param_1,int param_2,char *param_3)

{
  char cVar1;
  longlong lVar2;
  bool bVar3;
  int iVar4;
  char *pcVar5;
  undefined7 extraout_var;
  undefined8 uVar6;
  undefined1 auStackY_e8 [32];
  undefined4 local_a8 [2];
  char *local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78 [6];
  char local_48 [16];
  ulonglong local_38;
  
  local_38 = DAT_1800516d8 ^ (ulonglong)auStackY_e8;
  uVar6 = 1;
  pcVar5 = strchr(param_3,0x20);
  if (pcVar5 != (char *)0x0) {
    *pcVar5 = '\0';
  }
  iVar4 = HYparnam(param_3,&local_98,&local_a0);
  if (iVar4 != 0) {
    lVar2 = -(longlong)local_a0;
    do {
      cVar1 = *local_a0;
      local_a0[(longlong)(local_48 + lVar2)] = cVar1;
      local_a0 = local_a0 + 1;
    } while (cVar1 != '\0');
    local_a0 = local_48;
    uVar6 = HYPshFinfo(1);
    iVar4 = HYrslhie(local_98,&DAT_18003fa80,&local_80,&local_88);
    if (iVar4 == 0) goto LAB_18001ed13;
    HYPopFinfo(uVar6);
    uVar6 = HYGetFinfoCls(local_80,local_88);
  }
  uVar6 = HYPshFinfo(uVar6);
  bVar3 = FUN_18001e1a0(param_1,param_2,local_a0,local_78,local_a8,&local_88,&local_90);
  if ((int)CONCAT71(extraout_var,bVar3) != 0) {
    MDprpcmp(local_78,local_a8[0],local_88,local_90);
  }
LAB_18001ed13:
  HYPopFinfo(uVar6);
  return;
}

/* RVA 0x1ed40 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18001ed40(undefined4 param_1,uint param_2,char *param_3,undefined4 param_4,
                  undefined8 param_5,int param_6,int param_7)

{
  char cVar1;
  longlong lVar2;
  bool bVar3;
  int iVar4;
  undefined8 uVar5;
  char *pcVar6;
  undefined7 extraout_var;
  undefined8 uVar7;
  undefined1 auStackY_108 [32];
  uint local_c8 [2];
  undefined4 local_c0 [2];
  int local_b8 [2];
  char *local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78 [6];
  char local_48 [16];
  ulonglong local_38;
  
  local_38 = DAT_1800516d8 ^ (ulonglong)auStackY_108;
  uVar7 = 1;
  local_c8[0] = param_2;
  local_c0[0] = param_1;
  uVar5 = FUN_18001a9a0(param_1,local_c0,local_c8);
  if ((int)uVar5 != 0) {
    pcVar6 = strchr(param_3,0x20);
    if (pcVar6 != (char *)0x0) {
      *pcVar6 = '\0';
    }
    iVar4 = HYparnam(param_3,&local_a8,&local_b0);
    if (iVar4 != 0) {
      lVar2 = -(longlong)local_b0;
      do {
        cVar1 = *local_b0;
        local_b0[(longlong)(local_48 + lVar2)] = cVar1;
        local_b0 = local_b0 + 1;
      } while (cVar1 != '\0');
      local_b0 = local_48;
      iVar4 = HYrslhie(local_a8,&DAT_18003fa80,&local_80,&local_88);
      if (iVar4 == 0) {
        return;
      }
      uVar7 = HYGetFinfoCls(local_80,local_88);
    }
    uVar5 = HYPshFinfo(uVar7);
    bVar3 = FUN_18001e1a0(local_c0[0],local_c8[0],local_b0,local_78,local_b8,&local_88,&local_a0);
    if ((int)CONCAT71(extraout_var,bVar3) != 0) {
      switch(param_4) {
      case 3:
        local_c8[0] = local_c8[0] & 0xfe07ffff | 0x40000;
        break;
      default:
        local_c8[0] = local_c8[0] & 0xfe03ffff;
        break;
      case 5:
      case 6:
        local_c8[0] = local_c8[0] & 0xff03ffff | 0x1000000;
        break;
      case 7:
      case 8:
      case 9:
      case 10:
        local_c8[0] = local_c8[0] & 0xfe23ffff | 0x200000;
        break;
      case 0xb:
        local_c8[0] = local_c8[0] & 0xfe43ffff | 0x400000;
        break;
      case 0xc:
        local_c8[0] = local_c8[0] & 0xfe83ffff | 0x800000;
        break;
      case 0xe:
        local_c8[0] = local_c8[0] & 0xfe17ffff | 0x140000;
        break;
      case 0xf:
        local_c8[0] = local_c8[0] & 0xfe0fffff | 0xc0000;
      }
      local_98 = local_a0;
      local_90 = local_78[local_b8[0]];
      if (param_7 != 0) {
        MDfremsg(&local_98,0);
      }
      if (param_6 != 0) {
        MDcremsg(&local_98,0,param_5);
      }
      iVar4 = MDcntmsg(&local_98,0,1);
      if (iVar4 != 0) {
        local_c8[0] = local_c8[0] | 0x100000;
      }
      uVar7 = MDgethkp(*(undefined8 *)iwpfile_exref,local_90,local_98);
      MDeoupd(uVar7,local_c8,0);
      MDchgflg(local_78,local_b8[0],local_88,local_a0);
    }
    HYPopFinfo(uVar5);
  }
  return;
}

/* RVA 0x1f000 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18001f000(int param_1,char *param_2,char *param_3,int param_4,longlong param_5,
                  undefined4 param_6,char *param_7,int param_8)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  uint uVar7;
  undefined1 auStack_e8 [32];
  char *local_c8;
  uint *local_c0;
  uint local_b8 [2];
  uint local_b0;
  undefined4 uStack_ac;
  char *local_a8;
  longlong local_a0;
  longlong local_98;
  char *local_90;
  undefined8 local_88;
  undefined8 local_80;
  char *local_78;
  char *local_70;
  char *local_68;
  ulonglong local_48;
  
  local_48 = DAT_1800516d8 ^ (ulonglong)auStack_e8;
  uVar2 = 0;
  local_a0 = param_5;
  uVar6 = 1;
  local_b0 = 0;
  if ((param_3 != (char *)0x0) && (*param_3 != '\0')) {
    iVar1 = HYrslhie(param_3,&DAT_18003fa80,&local_80,&local_88);
    if (iVar1 == 0) {
      return;
    }
    uVar6 = HYGetFinfoCls(local_80,local_88);
  }
  local_a8 = (char *)HYPshFinfo(uVar6);
  local_90 = *(char **)(*(longlong *)finfo_exref + 0x168);
  switch(param_1) {
  case 1:
  case 8:
    if (param_1 == 8) {
      local_b0 = 1;
LAB_18001f0e2:
      pcVar3 = *(char **)(*(longlong *)finfo_exref + 0x1b8);
      local_78 = *(char **)dataclass_exref;
      local_70 = *(char **)(*(longlong *)finfo_exref + 0x1c8);
      local_98 = MDchkkey(*(undefined8 *)iwpfile_exref,pcVar3,1,param_2);
      uVar7 = 2;
      if (local_98 < 0) {
        param_7 = (char *)CONCAT44(uStack_ac,local_b0);
        lVar5 = CONCAT44(uStack_ac,local_b0);
        uVar2 = 1;
      }
      else {
        lVar5 = MDrslcls(*(undefined8 *)iwpfile_exref,pcVar3,local_98);
        lVar5 = lVar5 + local_98 * 0x108;
        local_90 = *(char **)(lVar5 + 0x28);
        lVar5 = *(longlong *)(lVar5 + 0x30);
        uVar2 = 0;
        local_98 = lVar5;
        local_68 = local_90;
      }
    }
    else {
      local_98 = MDchkkey(*(undefined8 *)iwpfile_exref,local_90,1,"SPECGROUPS");
      if (local_98 < 0) {
        param_7 = (char *)CONCAT44(uStack_ac,local_b0);
        lVar5 = CONCAT44(uStack_ac,local_b0);
        pcVar3 = local_a8;
        uVar7 = local_b0;
        uVar2 = 1;
      }
      else {
        uVar7 = 0;
        local_78 = local_90;
        pcVar3 = (char *)0x0;
        lVar5 = local_98;
        param_7 = param_2;
        uVar2 = 0;
      }
    }
    break;
  case 2:
    uVar7 = 2;
    local_78 = local_90;
    pcVar3 = (char *)MDfnddir(*(undefined8 *)iwpfile_exref,local_90,"OBJECTIVE");
    local_90 = pcVar3;
    if (*(longlong *)MDerror_exref == 0) {
      lVar5 = MDrslcls(*(undefined8 *)iwpfile_exref,pcVar3);
      local_70 = *(char **)(lVar5 + 0x148);
      local_98 = MDchkkey(*(undefined8 *)iwpfile_exref,local_90,1,param_2);
      if (-1 < local_98) {
        lVar5 = MDgethkp(*(undefined8 *)iwpfile_exref,local_90,local_98);
        local_90 = *(char **)(lVar5 + 0x28);
        local_98 = *(longlong *)(lVar5 + 0x30);
        local_68 = local_90;
        goto LAB_18001f25b;
      }
      lVar5 = CONCAT44(uStack_ac,local_b0);
      uVar2 = 1;
      param_7 = (char *)CONCAT44(uStack_ac,local_b0);
      break;
    }
    goto LAB_18001f665;
  case 3:
    if ((param_2 == (char *)0x0) || (*param_2 == '\0')) {
      local_98 = MDchkkey(*(undefined8 *)iwpfile_exref,local_90,1,"INIT-VAR-ATT");
      uVar7 = 0;
      local_78 = local_90;
      pcVar3 = (char *)0x0;
      uVar2 = (uint)((ulonglong)local_98 >> 0x3f);
LAB_18001f25b:
      param_7 = (char *)0x0;
      lVar5 = local_98;
    }
    else if (param_8 == 1) {
      uVar7 = 2;
      local_b0 = 2;
      pcVar3 = *(char **)(*(longlong *)finfo_exref + 0x1b8);
      local_78 = *(char **)dataclass_exref;
      local_70 = *(char **)(*(longlong *)finfo_exref + 0x1c8);
      local_98 = MDchkkey(*(undefined8 *)iwpfile_exref,pcVar3,1,param_2);
      if (-1 < local_98) {
        lVar5 = MDrslcls(*(undefined8 *)iwpfile_exref,pcVar3,local_98);
        lVar5 = lVar5 + local_98 * 0x108;
        local_90 = *(char **)(lVar5 + 0x28);
        local_98 = *(longlong *)(lVar5 + 0x30);
        local_68 = local_90;
        goto LAB_18001f25b;
      }
      lVar5 = CONCAT44(uStack_ac,local_b0);
      param_7 = (char *)CONCAT44(uStack_ac,local_b0);
      uVar2 = 1;
    }
    else {
      if (param_8 != 0xe) goto switchD_18001f0d3_default;
      local_b0 = 2;
      pcVar3 = (char *)0x0;
      uVar7 = 1;
      local_90 = (char *)MDfnddir(*(undefined8 *)iwpfile_exref,local_90,"MEASUREMENT");
      if (*(longlong *)MDerror_exref != 0) goto LAB_18001f665;
      local_78 = *(char **)dataclass_exref;
      local_98 = MDchkkey(*(undefined8 *)iwpfile_exref,local_90,1,param_2);
      if (-1 < local_98) {
        lVar5 = MDrslcls(*(undefined8 *)iwpfile_exref,local_90,local_98);
        lVar5 = lVar5 + local_98 * 0x108;
        if (*(char *)(lVar5 + 0x107) == '\b') {
          local_90 = *(char **)(lVar5 + 0x28);
          local_98 = *(longlong *)(lVar5 + 0x30);
        }
        local_70 = local_90;
        goto LAB_18001f25b;
      }
      lVar5 = CONCAT44(uStack_ac,local_b0);
      param_7 = (char *)CONCAT44(uStack_ac,local_b0);
      uVar2 = uVar7;
    }
    break;
  case 4:
  case 6:
    if (param_1 == 4) {
      pcVar3 = "CONNECTIONS";
    }
    else {
      pcVar3 = "EO-ALIAS";
      if (param_1 != 6) {
        pcVar3 = local_a8;
      }
    }
    lVar5 = MDchkkey(*(undefined8 *)iwpfile_exref,local_90,1,pcVar3);
    uVar7 = 0;
    pcVar3 = (char *)0x0;
    local_78 = local_90;
    param_7 = (char *)0x0;
    uVar2 = (uint)((ulonglong)lVar5 >> 0x3f);
    local_98 = lVar5;
    break;
  case 5:
  case 7:
    if (param_1 == 5) {
      local_b0 = 3;
      goto LAB_18001f0e2;
    }
    pcVar3 = (char *)0x0;
    local_78 = *(char **)dataclass_exref;
    uVar7 = 1;
    local_90 = (char *)MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,
                                "EO-PORT");
    local_70 = local_90;
    if (*(longlong *)MDerror_exref != 0) goto LAB_18001f665;
    local_98 = MDchkkey(*(undefined8 *)iwpfile_exref,local_90,1,param_7);
    if (-1 < local_98) goto LAB_18001f25b;
    param_7 = (char *)CONCAT44(uStack_ac,local_b0);
    lVar5 = local_98;
    uVar2 = 1;
    break;
  default:
    goto switchD_18001f0d3_default;
  }
  if (*(longlong *)MDerror_exref == 0) {
    if (uVar2 == 0) {
      lVar4 = MDgethkp(*(undefined8 *)iwpfile_exref,local_90,local_98);
      local_b8[0] = (*(uint *)(lVar4 + 0x88 + (ulonglong)local_b0 * 4) & 0x7f) << 0x12 |
                    local_b8[0] & 0xfe03ffff;
      if (local_a0 != 0) {
        local_c8 = param_7;
        MDcremsg(&local_98,param_1,local_a0,param_6);
      }
      if (param_4 == 0) {
        uVar2 = local_b8[0] >> 0x12 & 0x7f;
        if (uVar2 != 0) {
          if (uVar2 - 4 < 2) {
            local_b8[0] = local_b8[0] & 0xfe07ffff;
          }
          local_b8[0] = local_b8[0] | 0x40000;
        }
      }
      else if ((param_4 == -1) || (param_4 == -2)) {
        local_b8[0] = local_b8[0] | 0x100000;
      }
      else if (param_4 == -3) {
        local_b8[0] = local_b8[0] | 0x400000;
      }
      else {
        iVar1 = MDcntmsg(&local_98,0xffffffff);
        if (iVar1 == 0) {
          local_b8[0] = local_b8[0] & 0xfe03ffff;
        }
      }
      MDeoupd(lVar4,local_b8,local_b0);
      local_c0 = local_b8;
      local_c8 = (char *)CONCAT44(local_c8._4_4_,0x80);
      MDchgflg(&local_78,uVar7,pcVar3,lVar5);
    }
  }
  else {
LAB_18001f665:
    ERclear(0);
  }
switchD_18001f0d3_default:
  HYPopFinfo(local_a8);
  return;
}

/* RVA 0x1f6d0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18001f6d0(int param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined1 auStack_b8 [32];
  undefined4 local_98;
  undefined4 local_90;
  undefined4 local_88;
  undefined4 local_80;
  char *local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  char local_28 [16];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_b8;
  uVar5 = 1;
  iVar2 = HYparnam(param_3,&local_70,&local_78);
  if (iVar2 != 0) {
    lVar3 = -(longlong)local_78;
    do {
      cVar1 = *local_78;
      local_78[(longlong)(local_28 + lVar3)] = cVar1;
      local_78 = local_78 + 1;
    } while (cVar1 != '\0');
    local_78 = local_28;
    iVar2 = HYrslhie(local_70,&DAT_18003fa80,&local_60,&local_68);
    if (iVar2 == 0) {
      return;
    }
    uVar5 = HYGetFinfoCls(local_60,local_68);
  }
  uVar5 = HYPshFinfo(uVar5);
  local_58 = *(undefined8 *)dataclass_exref;
  if ((((param_1 == 1) || (param_1 == 2)) || (param_1 == 3)) || (param_1 == 4)) {
    lVar3 = MDrslcls(*(undefined8 *)iwpfile_exref,*(undefined8 *)strclass_exref);
    local_50 = *(undefined8 *)(lVar3 + 0x148);
    lVar3 = MDfndkey(*(undefined8 *)iwpfile_exref,*(undefined8 *)strclass_exref,1,local_78);
    if (*(longlong *)MDerror_exref == 0) {
      lVar4 = MDrslcls(*(undefined8 *)iwpfile_exref,*(undefined8 *)strclass_exref);
      lVar4 = lVar4 + lVar3 * 0x108;
      local_48 = *(undefined8 *)(lVar4 + 0x28);
      if (*(longlong *)MDerror_exref == 0) {
        local_80 = 0;
        local_88 = 9999;
        local_98 = 9999;
        local_90 = param_4;
        MDprpcmprec(&local_58,2,*(undefined8 *)strclass_exref,*(undefined8 *)(lVar4 + 0x30));
        goto LAB_18001f886;
      }
    }
    ERclear(0);
  }
LAB_18001f886:
  HYPopFinfo(uVar5);
  return;
}

/* RVA 0x1f8c0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18001f8c0(undefined8 param_1,int param_2,undefined8 param_3,undefined4 param_4)

{
  code cVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  longlong lVar5;
  char *pcVar6;
  code *pcVar7;
  code *pcVar8;
  uint uVar10;
  uint uVar9;
  undefined4 uVar11;
  undefined1 auStack_de8 [32];
  code *local_dc8;
  undefined4 local_dc0;
  undefined8 local_db8;
  code *local_da8;
  longlong local_da0;
  undefined8 local_d98;
  undefined8 local_d90;
  undefined8 local_d88 [2];
  undefined4 local_d78;
  undefined4 local_d74;
  undefined1 *local_d70;
  code *local_d68;
  undefined1 *local_d60;
  char *local_d58;
  undefined1 local_d50 [112];
  undefined1 local_ce0 [16];
  undefined8 local_cd0;
  undefined8 local_cc8;
  undefined8 uStack_cc0;
  undefined8 local_c90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined1 local_58 [16];
  ulonglong local_48;
  
  local_48 = DAT_1800516d8 ^ (ulonglong)auStack_de8;
  uVar11 = 0;
  uVar3 = 1;
  uVar10 = 0;
  uVar9 = 0;
  iVar2 = HYparnam(param_3,&local_d98,&local_da8);
  if (iVar2 != 0) {
    lVar5 = -(longlong)local_da8;
    do {
      cVar1 = *local_da8;
      local_da8[(longlong)(local_58 + lVar5)] = cVar1;
      local_da8 = local_da8 + 1;
    } while (cVar1 != (code)0x0);
    local_da8 = (code *)local_58;
    iVar2 = HYrslhie(local_d98,&DAT_18003fa80,local_d88,&local_d90);
    if (iVar2 == 0) {
      return;
    }
    uVar3 = HYGetFinfoCls(local_d88[0],local_d90);
  }
  uVar3 = HYPshFinfo(uVar3);
  local_88 = *(undefined8 *)dataclass_exref;
  switch(param_2) {
  case -0x36:
  case -0x31:
  case -0x11:
  case -0xf:
    local_80 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"CONV-SUM");
    local_da0 = MDchkkey(*(undefined8 *)iwpfile_exref,local_80,1,local_da8);
    uVar9 = uVar10;
    if (local_da0 < 0) {
      uVar4 = FUN_18001aca0("CONV-SUM",local_da8,0,local_80);
      if ((int)uVar4 != 0) goto switchD_18001f9b5_caseD_ffffffcb;
      local_da0 = MDchkkey(*(undefined8 *)iwpfile_exref,local_80,1,local_da8);
      if (local_da0 < 0) {
        uVar9 = 1;
      }
    }
    goto LAB_18001fadf;
  default:
    goto switchD_18001f9b5_caseD_ffffffcb;
  case -0x30:
  case -0x2f:
  case -9:
    if (param_2 == -0x30) {
      *(undefined8 *)local_da8 = s_UTIL_SUMMARY_180041358._0_8_;
      *(undefined4 *)(local_da8 + 8) = s_UTIL_SUMMARY_180041358._8_4_;
      local_da8[0xc] = (code)s_UTIL_SUMMARY_180041358[0xc];
    }
    local_da0 = MDchkkey(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,1,local_da8);
    if (local_da0 < 0) {
      local_d74 = 0;
      memset(&local_d60,0,0xcd8);
      pcVar7 = (code *)&DAT_1800413f4;
      local_d70 = &DAT_1800413f4;
      local_d68 = local_da8;
      local_d78 = 1;
      pcVar8 = path_name_exref;
      do {
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        *pcVar8 = cVar1;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != (code)0x0);
      pcVar8 = path_name_exref + 0xe;
      pcVar7 = local_da8;
      do {
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        *pcVar8 = cVar1;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != (code)0x0);
      pcVar7 = local_da8;
      do {
        cVar1 = *pcVar7;
        pcVar7[(longlong)(local_ce0 + -(longlong)local_da8)] = cVar1;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != (code)0x0);
      local_db8 = 0;
      local_cd0 = *(undefined8 *)dataclass_exref;
      local_c90 = 0;
      local_dc0 = 1;
      local_dc8 = local_da8;
      OPcreblk(&local_d78,2,*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref);
      local_da0 = MDchkkey(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,1,local_da8);
LAB_18002015f:
      uVar9 = uVar10;
      if (local_da0 < 0) {
        uVar9 = 1;
      }
    }
    break;
  case -0x2e:
  case -0x2b:
  case -0x2a:
  case -0x29:
  case -0xc:
    local_da0 = MDchkkey(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,1,local_da8);
    uVar9 = (uint)((ulonglong)local_da0 >> 0x3f);
    break;
  case -0x27:
  case -0x19:
  case -0x18:
  case -0x17:
    if (param_2 == -0x17) {
      GRsetssm(1);
    }
    local_da0 = MDchkkey(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,1,local_da8);
    if ((local_da0 < 0) &&
       (iVar2 = OPcrestr(local_da8,*(undefined8 *)dataclass_exref,&local_da0,local_da0), iVar2 == 2)
       ) goto switchD_18001f9b5_caseD_ffffffcb;
    break;
  case -0x26:
  case -0x25:
  case -0x24:
  case -0x23:
  case -0x22:
  case -0x21:
  case -0x20:
  case -0x1f:
  case -0x1e:
  case -0x1d:
  case -0x1c:
  case -0x1b:
  case -0x1a:
    local_80 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"EQUIP-SUM");
    local_da0 = MDchkkey(*(undefined8 *)iwpfile_exref,local_80,1,local_da8);
    uVar9 = uVar10;
    if (local_da0 < 0) {
      uVar4 = FUN_18001aca0("EQUIP-SUM",local_da8,0,local_80);
      if ((int)uVar4 != 0) goto switchD_18001f9b5_caseD_ffffffcb;
      local_da0 = MDchkkey(*(undefined8 *)iwpfile_exref,local_80,1,local_da8);
      uVar11 = 1;
      goto LAB_18002015f;
    }
LAB_18001fadf:
    uVar11 = 1;
    break;
  case -0x15:
    local_80 = MDfnddir(*(undefined8 *)iwpfile_exref,
                        *(undefined8 *)(*(longlong *)topfinfo_exref + 0x168),"PROPERTIES");
    local_da0 = MDchkkey(*(undefined8 *)iwpfile_exref,local_80,1,local_da8);
    uVar11 = 1;
    uVar9 = (uint)((ulonglong)local_da0 >> 0x3f);
    break;
  case -0x13:
    local_80 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,local_da8);
    uVar11 = 1;
    local_da0 = MDchkkey(*(undefined8 *)iwpfile_exref,local_80,1,"EXEC-SUM");
    if (local_da0 < 0) {
      uVar4 = FUN_18001aca0(local_da8,"EXEC-SUM",0,local_80);
      if ((int)uVar4 != 0) goto switchD_18001f9b5_caseD_ffffffcb;
      lVar5 = MDchkkey(*(undefined8 *)iwpfile_exref,local_80,1,"EXEC-SUM");
      local_db8 = CONCAT44(local_db8._4_4_,9999);
      local_dc8 = (code *)CONCAT44(local_dc8._4_4_,9999);
      local_dc0 = param_4;
      local_da0 = lVar5;
      MDprpcmp(&local_88,1,0,lVar5);
      uVar9 = (uint)((ulonglong)lVar5 >> 0x3f);
    }
    else {
      local_db8 = CONCAT44(local_db8._4_4_,9999);
      local_dc8 = (code *)CONCAT44(local_dc8._4_4_,9999);
      local_dc0 = param_4;
      MDprpcmp(&local_88,1,0,local_da0);
      uVar9 = uVar10;
    }
    local_da0 = MDchkkey(*(undefined8 *)iwpfile_exref,local_80,1,"PROJECT");
    if (local_da0 < 0) {
      uVar4 = FUN_18001aca0(local_da8,"PROJECT",0,local_80);
      if ((int)uVar4 != 0) goto switchD_18001f9b5_caseD_ffffffcb;
      local_da0 = MDfndkey(*(undefined8 *)iwpfile_exref,local_80,1,"PROJECT");
    }
    local_db8 = CONCAT44(local_db8._4_4_,9999);
    local_dc8 = (code *)CONCAT44(local_dc8._4_4_,9999);
    local_dc0 = param_4;
    MDprpcmp(&local_88,1,0,local_da0);
    lVar5 = MDchkkey(*(undefined8 *)iwpfile_exref,local_80,1,"PLANT");
    if ((lVar5 < 0) && (uVar4 = FUN_18001aca0(local_da8,"PLANT",0,local_80), (int)uVar4 != 0))
    goto switchD_18001f9b5_caseD_ffffffcb;
    local_da0 = MDchkkey(*(undefined8 *)iwpfile_exref,local_80,1,"PLANT");
    if (local_da0 < 0) {
      uVar9 = 1;
    }
    break;
  case -0x12:
    local_80 = MDfnddir(*(undefined8 *)iwpfile_exref,
                        *(undefined8 *)(*(longlong *)topfinfo_exref + 0x168),"COMPONENTS");
    uStack_78 = MDfnddir(*(undefined8 *)iwpfile_exref,local_80,&DAT_180041388);
    local_da0 = MDchkkey(*(undefined8 *)iwpfile_exref,uStack_78,1,local_da8);
    uVar9 = uVar10;
    if (local_da0 < 0) {
      local_d74 = 0;
      memset(local_d50,0,0xcc8);
      pcVar7 = (code *)&DAT_1800413f4;
      local_d70 = &DAT_1800413f4;
      local_d58 = "PC-PROP";
      local_d78 = 3;
      local_d68 = (code *)0x180041378;
      local_d60 = &DAT_180041388;
      pcVar8 = path_name_exref;
      do {
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        *pcVar8 = cVar1;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != (code)0x0);
      pcVar6 = "COMPONENTS";
      pcVar7 = path_name_exref + 0xe;
      do {
        cVar1 = (code)*pcVar6;
        pcVar6 = pcVar6 + 1;
        *pcVar7 = cVar1;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != (code)0x0);
      pcVar7 = (code *)&DAT_180041388;
      pcVar8 = path_name_exref + 0x1c;
      do {
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        *pcVar8 = cVar1;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != (code)0x0);
      pcVar6 = "PC-PROP";
      pcVar7 = path_name_exref + 0x2a;
      do {
        cVar1 = (code)*pcVar6;
        pcVar6 = pcVar6 + 1;
        *pcVar7 = cVar1;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != (code)0x0);
      pcVar7 = local_da8;
      do {
        cVar1 = *pcVar7;
        pcVar7[(longlong)(local_ce0 + -(longlong)local_da8)] = cVar1;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != (code)0x0);
      local_db8 = 0;
      local_cd0 = *(undefined8 *)(*(longlong *)topfinfo_exref + 0x168);
      local_cc8 = local_80;
      uStack_cc0 = uStack_78;
      local_dc0 = 3;
      local_dc8 = local_da8;
      local_c90 = 0;
      OPcreblk(&local_d78,2,*(undefined8 *)iwpfile_exref,uStack_78);
      local_da0 = MDchkkey(*(undefined8 *)iwpfile_exref,uStack_78,1,local_da8);
      if (local_da0 < 0) {
        uVar9 = 1;
      }
    }
    uVar11 = 2;
    break;
  case -0xe:
  case -0xd:
    local_80 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"COSTING");
    local_da0 = MDchkkey(*(undefined8 *)iwpfile_exref,local_80,1,local_da8);
    uVar11 = 1;
    uVar9 = (uint)((ulonglong)local_da0 >> 0x3f);
  }
  if (*(longlong *)MDerror_exref == 0) {
    if (uVar9 == 0) {
      local_db8 = CONCAT44(local_db8._4_4_,9999);
      local_dc8 = (code *)CONCAT44(local_dc8._4_4_,9999);
      local_dc0 = param_4;
      MDprpcmp(&local_88,uVar11,0,local_da0);
    }
  }
  else {
    ERclear(0);
  }
switchD_18001f9b5_caseD_ffffffcb:
  HYPopFinfo(uVar3);
  return;
}

