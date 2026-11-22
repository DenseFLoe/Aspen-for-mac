/* RVA 0x20230 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180020230(int param_1,undefined8 param_2)

{
  undefined4 uVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  undefined *puVar8;
  ulonglong uVar9;
  undefined1 auStackY_168 [32];
  char local_138 [272];
  ulonglong local_28;
  
  local_28 = DAT_1800516d8 ^ (ulonglong)auStackY_168;
  bVar3 = true;
  bVar4 = false;
  bVar2 = true;
  if (param_1 == 1) {
    if ((*(int *)(*(longlong *)topfinfo_exref + 0x14c) == 0) ||
       (*(int *)(*(longlong *)topfinfo_exref + 0x150) == 0)) {
      uVar5 = 0;
      uVar9 = 0x9010000;
    }
    else {
      uVar5 = 1;
      uVar9 = 0x9010000;
    }
  }
  else {
    if (param_1 == 2) {
      uVar9 = 0x9010000;
    }
    else {
      if (param_1 == 3) {
        uVar9 = 0x9010000;
        uVar5 = (uint)(*(int *)(*(longlong *)topfinfo_exref + 0x15c) == 0);
        bVar3 = false;
        goto LAB_1800202f2;
      }
      if (param_1 == 4) goto LAB_1800203c9;
      if (param_1 != 5) {
        return 0;
      }
      bVar2 = false;
      bVar4 = true;
      uVar9 = 0x9040000;
    }
    uVar5 = *(uint *)(*(longlong *)topfinfo_exref + 0x14c);
  }
LAB_1800202f2:
  if (uVar5 == 0) {
    return 0;
  }
  if ((((*(int *)partial_results_exref != 0) || (bVar4)) &&
      ((iVar6 = GRinqiap(), iVar6 != 0 || (iVar6 = MVGetProductCode(), iVar6 == 2)))) &&
     (*(int *)triggered_by_canned_exref == 0)) {
    uVar1 = *(undefined4 *)partial_results_exref;
    *(undefined4 *)partial_results_exref = 0;
    pcVar7 = (char *)GetSorResStringEx(0x782);
    iVar6 = FUN_180030240(pcVar7,local_138,0,uVar9,(char *)0x0);
    if ((bVar2) && (0 < iVar6)) {
      FUN_18002c620((longlong)APtmpfil_exref);
      GRsetrpt(1);
    }
    *(undefined4 *)partial_results_exref = uVar1;
  }
  if (!bVar3) {
    return 1;
  }
  if (param_1 == 1) {
    puVar8 = &DAT_180040a04;
  }
  else {
    if (param_1 != 2) goto LAB_1800203c9;
    puVar8 = &DAT_180040a7c;
  }
  dump_summary(param_2,puVar8);
LAB_1800203c9:
  if (((*(int *)partial_results_exref != 0) && (iVar6 = GRinqiap(), iVar6 != 0)) &&
     ((*(int *)triggered_by_canned_exref == 0 || (param_1 == 5)))) {
    iVar6 = FUN_180024de0();
    if (iVar6 < 1) {
      return 0;
    }
    *(undefined4 *)sum_header_exref = 1;
    FUN_18002c620((longlong)APtmpfil_exref);
    *(undefined4 *)sum_header_exref = 0;
  }
  return 1;
}

/* RVA 0x20450 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_180020450(char *param_1)

{
  longlong lVar1;
  undefined4 uVar2;
  int iVar3;
  FILE *_File;
  longlong lVar5;
  longlong lVar4;
  undefined1 auStack_88 [32];
  char local_68 [80];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_88;
  uVar2 = 0xffffffff;
  _File = fopen(param_1,"r");
  if (_File == (FILE *)0x0) {
    uVar2 = 1;
  }
  else {
    iVar3 = feof(_File);
    while (iVar3 == 0) {
      fgets(local_68,0x50,_File);
      lVar5 = -1;
      do {
        lVar4 = lVar5 + 1;
        lVar1 = lVar5 + 1;
        lVar5 = lVar4;
      } while (local_68[lVar1] != '\0');
      if ((local_68[0] != ';') && ((int)lVar4 != 0)) {
        uVar2 = MDaddcrc(local_68,lVar4,uVar2);
      }
      iVar3 = feof(_File);
    }
    fclose(_File);
  }
  return uVar2;
}

/* RVA 0x20520 */
undefined8 FUN_180020520(longlong param_1,int param_2,int param_3,int param_4,char *param_5)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  longlong lVar7;
  char *pcVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  longlong *plVar13;
  int iVar14;
  
  iVar14 = 0;
  bVar2 = false;
  piVar5 = (int *)0x0;
  if ((((param_1 == 0) || (param_3 == 0)) || (param_4 == 0)) ||
     ((param_5 == (char *)0x0 || (*param_5 == '\0')))) {
    return 0xffffffff;
  }
  uVar9 = param_4 / 1000 >> 0x1f;
  iVar12 = (param_4 / 1000 ^ uVar9) - uVar9;
  iVar10 = param_4 % 1000;
  piVar4 = (int *)deref_ptr(param_1);
  plVar13 = (longlong *)(piVar4 + 2);
  lVar7 = *(longlong *)(piVar4 + 2);
  iVar3 = 0;
  while ((iVar11 = iVar3, lVar7 != 0 && (piVar5 = (int *)deref_ptr(lVar7), piVar5 != (int *)0x0))) {
    lVar7 = *(longlong *)(piVar5 + 0x18);
    iVar3 = iVar11 + 1;
    if (piVar5[3] == 0) {
      iVar3 = iVar11;
    }
  }
  lVar7 = *plVar13;
  if (lVar7 != 0) {
    do {
      piVar5 = (int *)deref_ptr(lVar7);
      if (piVar5 == (int *)0x0) break;
      if (iVar10 < 0) {
        if (iVar10 == piVar5[2]) {
          bVar2 = true;
          if (param_2 == 0) {
            *piVar5 = 0;
            if (iVar12 == 0) {
              iVar11 = iVar11 + 1;
              piVar5[3] = iVar11;
            }
            else {
              if (iVar12 == 0) {
                iVar11 = iVar11 + 1;
              }
              piVar5[3] = iVar12;
            }
          }
          else {
            if (*piVar5 == -1) {
              *piVar5 = 0;
            }
            else if (*piVar5 == -2) {
              *piVar5 = 1;
            }
LAB_18002069a:
            iVar3 = iVar12;
            if (iVar12 == 0) {
              iVar3 = piVar5[3];
            }
            piVar5[3] = iVar3;
          }
        }
        else if (piVar5[2] < 0) {
          if (*piVar5 == 0) {
            *piVar5 = -1;
          }
          else if (*piVar5 == 1) {
            *piVar5 = -2;
          }
          goto LAB_18002069a;
        }
      }
      else if ((piVar5[1] == param_3) && (piVar5[2] == iVar10)) {
        piVar6 = piVar5 + 4;
        lVar7 = (longlong)param_5 - (longlong)piVar6;
        do {
          iVar3 = *piVar6;
          cVar1 = *(char *)((longlong)piVar6 + lVar7);
          if ((char)iVar3 != cVar1) break;
          piVar6 = (int *)((longlong)piVar6 + 1);
        } while (cVar1 != '\0');
        if ((char)iVar3 == cVar1) {
          if (param_2 == 0) {
            *piVar5 = 0;
            if (iVar12 == 0) {
              iVar12 = iVar11 + 1;
            }
          }
          else {
            if (*piVar5 == -1) {
              *piVar5 = 0;
            }
            else if (*piVar5 == -2) {
              *piVar5 = 1;
            }
            if (iVar12 == 0) {
              iVar12 = piVar5[3];
            }
          }
          piVar5[3] = iVar12;
          _guard_check_icall();
          goto LAB_180020779;
        }
      }
      iVar3 = iVar14 + 1;
      if (*piVar5 < 0) {
        iVar3 = iVar14;
      }
      iVar14 = iVar3;
      if (9 < iVar14) {
        return 1;
      }
      lVar7 = *(longlong *)(piVar5 + 0x18);
      plVar13 = (longlong *)(piVar5 + 0x18);
    } while (lVar7 != 0);
    if (bVar2) {
      return 0;
    }
  }
  if (*plVar13 == 0) {
    lVar7 = malloc3(0x68);
    *plVar13 = lVar7;
    piVar5 = (int *)deref_ptr(lVar7);
  }
  *piVar4 = *piVar4 + 1;
  *piVar5 = param_2;
  piVar5[1] = param_3;
  piVar5[2] = iVar10;
  piVar5[3] = 0;
  pcVar8 = param_5;
  do {
    cVar1 = *pcVar8;
    pcVar8[(longlong)piVar5 + (0x10 - (longlong)param_5)] = cVar1;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  piVar5[0x18] = 0;
  piVar5[0x19] = 0;
  if (0 < piVar5[2]) {
LAB_180020779:
    FUN_180008f60(param_5,param_3 + -1);
  }
  return 0;
}

/* RVA 0x20820 */
undefined8 FUN_180020820(void)

{
  GRclrstp0();
  FUN_180008f10();
  return 0;
}

/* RVA 0x20840 */
int FUN_180020840(void)

{
  longlong lVar1;
  int iVar2;
  
  iVar2 = 0;
  if ((*(longlong *)(*(longlong *)topfinfo_exref + 0x560) != 0) &&
     (lVar1 = deref_ptr(), *(longlong *)(lVar1 + 8) != 0)) {
    lVar1 = deref_ptr();
    while ((lVar1 != 0 && (iVar2 = iVar2 + 1, *(longlong *)(lVar1 + 0x60) != 0))) {
      lVar1 = deref_ptr();
    }
  }
  return iVar2;
}

/* RVA 0x208a0 */
undefined4 FUN_1800208a0(longlong param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  void *pvVar2;
  void *_Dst;
  void *_Dst_00;
  longlong lVar3;
  
  _Dst_00 = (void *)0x0;
  if (param_1 == 0) {
    *param_2 = 0;
    return 0xffffffff;
  }
  uVar1 = malloc3(0x10);
  *param_2 = uVar1;
  pvVar2 = (void *)deref_ptr(param_1);
  _Dst = (void *)deref_ptr(*param_2);
  memmove(_Dst,pvVar2,0x10);
  if (*(longlong *)((longlong)pvVar2 + 8) == 0) {
    *(undefined8 *)((longlong)_Dst + 8) = 0;
  }
  else {
    uVar1 = malloc3(0x68);
    *(undefined8 *)((longlong)_Dst + 8) = uVar1;
    lVar3 = *(longlong *)((longlong)pvVar2 + 8);
    if (lVar3 != 0) {
      while( true ) {
        pvVar2 = (void *)deref_ptr(lVar3);
        _Dst_00 = (void *)deref_ptr(uVar1);
        memmove(_Dst_00,pvVar2,0x68);
        lVar3 = *(longlong *)((longlong)pvVar2 + 0x60);
        if (lVar3 == 0) break;
        uVar1 = malloc3(0x68);
        *(undefined8 *)((longlong)_Dst_00 + 0x60) = uVar1;
      }
    }
    *(undefined8 *)((longlong)_Dst_00 + 0x60) = 0;
  }
  return 0;
}

/* RVA 0x209a0 */
undefined8 FUN_1800209a0(longlong param_1,int param_2)

{
  longlong lVar1;
  int *piVar2;
  longlong lVar3;
  
  if ((param_1 != 0) && (lVar1 = deref_ptr(), *(longlong *)(lVar1 + 8) != 0)) {
    piVar2 = (int *)deref_ptr();
    if (param_2 < 1) {
      while( true ) {
        if (piVar2 == (int *)0x0) {
          return 0xffffffff;
        }
        if ((piVar2[2] < 0) && ((piVar2[2] == param_2 || (param_2 == -1)))) {
          if (*piVar2 == 1) {
            *piVar2 = -2;
          }
          else if (*piVar2 == 0) {
            *piVar2 = -1;
          }
        }
        if (*(longlong *)(piVar2 + 0x18) == 0) break;
        piVar2 = (int *)deref_ptr();
      }
      return 0xffffffff;
    }
    if (*(longlong *)(piVar2 + 0x18) != 0) {
      do {
        if (param_2 < 1) break;
        if (*piVar2 < 0) {
LAB_180020a69:
          piVar2 = (int *)deref_ptr(*(undefined8 *)(piVar2 + 0x18));
        }
        else {
          if (piVar2[2] < 1) {
            lVar1 = 0;
            do {
              lVar3 = lVar1 + 1;
              if (*(char *)((longlong)piVar2 + lVar1 + 0x10) != "ERROR"[lVar1]) goto LAB_180020a69;
              lVar1 = lVar3;
            } while (lVar3 != 6);
          }
          param_2 = param_2 + -1;
          if (param_2 != 0) goto LAB_180020a69;
        }
      } while (*(longlong *)(piVar2 + 0x18) != 0);
      if (param_2 == 0) goto LAB_180020a8a;
    }
    if (param_2 == 1) {
LAB_180020a8a:
      if (*piVar2 == 1) {
        *piVar2 = -2;
      }
      else if (*piVar2 == 0) {
        *piVar2 = -1;
      }
      _guard_check_icall();
      FUN_180008f20(piVar2 + 4,piVar2[1] + -1);
      return 0;
    }
  }
  return 0xffffffff;
}

/* RVA 0x20ae0 */
bool FUN_180020ae0(undefined8 param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 10) {
    return false;
  }
  iVar1 = FUN_18002bbe0();
  return iVar1 == 1;
}

/* RVA 0x20b10 */
undefined8 FUN_180020b10(undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4)

{
  code *pcVar1;
  undefined8 uVar2;
  
  if ((int)param_2 == 10) {
    FUN_1800252b0(1,param_2,param_3,param_4);
  }
  else {
    uVar2 = FUN_18002a3a0(param_1,param_2,param_3,param_4);
    if ((int)uVar2 == 1) {
      return uVar2;
    }
  }
  GRsetsbs();
  pcVar1 = commsect_exref;
  *(undefined8 *)commsect_exref = 0;
  *(undefined8 *)(pcVar1 + 8) = 0;
  *(undefined8 *)(pcVar1 + 0x10) = 0;
  *(undefined8 *)(pcVar1 + 0x18) = 0;
  *(undefined8 *)(pcVar1 + 0x20) = 0;
  *(undefined8 *)(pcVar1 + 0x28) = 0;
  *(undefined2 *)(pcVar1 + 0x30) = 0;
  SBreaini(1,&DAT_18003f720);
  return 0;
}

/* RVA 0x20b70 */
undefined8 FUN_180020b70(char *param_1)

{
  int iVar1;
  
  iVar1 = _access(param_1,0);
  if (iVar1 == 0) {
    FUN_180008f80(dbxbuf_exref,"%c%cFile %s already exists on workstation. Erase file?",0x5e,0x3f);
    iVar1 = EXyesno(dbxbuf_exref,0,0);
    if (iVar1 == 0) {
      FUN_180008f80(dbxbuf_exref,"%c%c%s",0x5e,0x21);
      EXyesno(dbxbuf_exref,2,1);
      return 0xffffffff;
    }
    remove(param_1);
  }
  return 0;
}

/* RVA 0x20c20 */
int FUN_180020c20(longlong param_1)

{
  longlong lVar1;
  int *piVar2;
  
  if (param_1 != 0) {
    lVar1 = deref_ptr();
    lVar1 = *(longlong *)(lVar1 + 8);
    while (lVar1 != 0) {
      piVar2 = (int *)deref_ptr();
      if (((*piVar2 == 0) && (piVar2[3] != 0)) && (piVar2[2] < 0)) {
        return -piVar2[2];
      }
      lVar1 = *(longlong *)(piVar2 + 0x18);
    }
  }
  return 1;
}

/* RVA 0x20c70 */
undefined8 FUN_180020c70(int param_1)

{
  int iVar1;
  code *pcVar2;
  char *pcVar3;
  undefined8 uVar4;
  char *pcVar5;
  
  pcVar5 = (char *)0x3f;
  uVar4 = 0x5e;
  if (*(int *)defsaveasbkp_exref == 0) {
    pcVar3 = "%c%cSave current run (%s)?\n(Run will be saved in Quick Restart format)";
  }
  else {
    pcVar3 = "%c%cSave current run (%s)?\n(Run will be saved in Backup file format)";
  }
  pcVar2 = dbxbuf_exref;
  FUN_180008f80(dbxbuf_exref,pcVar3,0x5e,0x3f);
  if (param_1 == 2) {
    iVar1 = GRinqsme();
    if ((iVar1 == 0) && (iVar1 = EXyesno(dbxbuf_exref,0,1), iVar1 == 1)) {
      GRsetchanged(1);
      _guard_check_icall();
    }
  }
  else {
    if (((param_1 == 1) ||
        ((*(int *)opniwp_exref != 0 &&
         (pcVar2 = *(code **)topfinfo_exref, *(int *)(pcVar2 + 0x154) != 0)))) &&
       (iVar1 = GRinqsme(), iVar1 == 0)) {
      pcVar3 = (char *)0x1;
      uVar4 = 1;
      pcVar2 = dbxbuf_exref;
      iVar1 = EXyesno();
      if (iVar1 == 1) {
        pcVar3 = (char *)0x1;
        iVar1 = GRchkmmdir(filstr_exref);
        if (iVar1 != 0) {
          return 0;
        }
        pcVar2 = (code *)0x1;
        GRsetchanged();
        iVar1 = _guard_check_icall();
        if (iVar1 != 1) {
          return 0;
        }
      }
      else if (iVar1 == 2) {
        return 0;
      }
    }
    if ((*(int *)SBsession_exref == 4) && (*(int *)(submitdata_exref + 0x1214) != 0)) {
      pcVar5 = (char *)0x3f;
      FUN_180008f80(dbxbuf_exref,"%c%c%s?",0x5e,0x3f);
      pcVar3 = (char *)0x3;
      uVar4 = 1;
      pcVar2 = dbxbuf_exref;
      iVar1 = EXyesno();
      if (iVar1 == 2) {
        return 0;
      }
    }
    iVar1 = GRinqcnn();
    if (iVar1 != 0) {
      FUN_18002a3a0(pcVar2,pcVar3,uVar4,pcVar5);
    }
  }
  FUN_1800261d0((char *)APtmpfil_exref);
  return 3;
}

/* RVA 0x20e10 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool FUN_180020e10(undefined8 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  longlong lVar3;
  undefined1 auStack_c8 [32];
  char local_a8 [144];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_c8;
  if ((param_2 == 10) || (lVar3 = FUN_180033f00(&DAT_1800520a0,0x80,0), lVar3 == 0)) {
    return false;
  }
  lVar3 = 0;
  do {
    cVar1 = (&DAT_1800520a0)[lVar3];
    local_a8[lVar3] = cVar1;
    lVar3 = lVar3 + 1;
  } while (cVar1 != '\0');
  iVar2 = FUN_18002a580(local_a8,1,0,(LPCSTR)0x0);
  return iVar2 == 1;
}

/* RVA 0x20ec0 */
undefined4 FUN_180020ec0(longlong param_1,int param_2)

{
  int iVar1;
  longlong lVar2;
  int *piVar3;
  longlong lVar4;
  uint uVar5;
  uint uVar6;
  longlong *plVar7;
  ulonglong uVar8;
  
  uVar5 = 0;
  if (param_1 == 0) {
    return 0xffffffff;
  }
  lVar2 = deref_ptr();
  if (param_2 != 0) {
    _guard_check_icall();
    FUN_180008f10();
  }
  if (*(int *)(lVar2 + 4) == 1) {
    FUN_180017da0(0xffffffff);
  }
  lVar4 = *(longlong *)(lVar2 + 8);
  plVar7 = (longlong *)(lVar2 + 8);
  if (lVar4 != 0) {
    uVar6 = 1;
    do {
      uVar8 = (ulonglong)uVar6;
      piVar3 = (int *)deref_ptr(lVar4);
      iVar1 = *piVar3;
      if (iVar1 == -2) {
        lVar4 = *plVar7;
        *plVar7 = *(longlong *)(piVar3 + 0x18);
        free3(lVar4,0x68);
      }
      else if (iVar1 == -1) {
        if (*(int *)(lVar2 + 4) == 0) {
          uVar5 = piVar3[3];
          FUN_180017da0(uVar5);
        }
        lVar4 = *plVar7;
        *plVar7 = *(longlong *)(piVar3 + 0x18);
        free3(lVar4,0x68);
        for (lVar4 = *plVar7; lVar4 != 0; lVar4 = *(longlong *)(lVar4 + 0x60)) {
          lVar4 = deref_ptr(lVar4);
          if ((int)uVar5 < *(int *)(lVar4 + 0xc)) {
            *(int *)(lVar4 + 0xc) = *(int *)(lVar4 + 0xc) + -1;
          }
        }
      }
      else if (iVar1 == 0) {
        if (0 < piVar3[2]) {
          _guard_check_icall();
          FUN_180008f60(piVar3 + 4,piVar3[1] + -1);
        }
        uVar6 = uVar6 + 1;
        plVar7 = (longlong *)(piVar3 + 0x18);
      }
      else if (iVar1 == 1) {
        if ((param_2 != 0) && (0 < piVar3[2])) {
          FUN_180008f60(piVar3 + 4,piVar3[1] + -1);
        }
        piVar3[3] = uVar6;
        uVar6 = uVar6 + 1;
        FUN_180019900(uVar8,piVar3[1],piVar3[2],(char *)(piVar3 + 4));
        *piVar3 = 0;
        plVar7 = (longlong *)(piVar3 + 0x18);
      }
      else {
        *plVar7 = *(longlong *)(piVar3 + 0x18);
      }
      lVar4 = *plVar7;
    } while (lVar4 != 0);
    *(undefined4 *)(lVar2 + 4) = 0;
  }
  return 0;
}

/* RVA 0x210a0 */
undefined8 thunk_FUN_180006bf0(int param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  char *_Str;
  char *pcVar3;
  char *pcVar4;
  char *_Dest;
  CSimSeqObj *this;
  size_t _Count;
  longlong lVar5;
  longlong lVar6;
  undefined **ppuVar7;
  
  if (param_1 < 0) {
    return 1;
  }
  _Str = _strdup(param_2);
  _Count = 0;
  _Dest = (char *)0x0;
  pcVar3 = strchr(_Str,0x2e);
  if (pcVar3 != (char *)0x0) {
    *pcVar3 = '\0';
    _Count = (longlong)pcVar3 - (longlong)_Str;
  }
  ppuVar7 = &PTR_vftable_18004f600;
  pcVar3 = _Str;
  if (param_1 == 10) {
    ppuVar7 = &PTR_vftable_18004f620;
  }
  do {
    iVar1 = (int)(*(longlong *)((longlong)ppuVar7 + 0x10) - *(longlong *)((longlong)ppuVar7 + 8) >>
                 5);
    if (iVar1 == 0) {
      (*(code *)PTR_FUN_180044148)(_Dest,param_1 == 10);
      iVar1 = (int)(*(longlong *)((longlong)ppuVar7 + 0x10) - *(longlong *)((longlong)ppuVar7 + 8)
                   >> 5);
    }
    lVar6 = 0;
    if (0 < iVar1) {
      lVar5 = 0;
      do {
        this = (CSimSeqObj *)(*(longlong *)((longlong)ppuVar7 + 8) + lVar5);
        if (*(int *)(this + 0x10) == param_1) {
          iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             (this + 8),pcVar3);
          if (iVar2 == 0) {
            if (_Dest != (char *)0x0) {
              free(_Dest);
            }
            free(_Str);
            return 1;
          }
        }
        else if (((*(int *)(this + 0x10) == -1) && (_Count != 0)) &&
                (iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                                   ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
                                    )(this + 8),pcVar3), iVar2 == 0)) {
          if (_Dest != (char *)0x0) {
            free(_Dest);
          }
          _Dest = malloc(_Count + 1);
          strncpy(_Dest,param_2,_Count);
          _Dest[_Count] = '\0';
          ppuVar7 = (undefined **)CSimSeqObj::GetChildren(this);
          goto LAB_180006d5d;
        }
        lVar6 = lVar6 + 1;
        lVar5 = lVar5 + 0x20;
      } while (lVar6 < iVar1);
    }
    if (_Count == 0) break;
LAB_180006d5d:
    lVar6 = _Count + 1;
    _Count = 0;
    pcVar3 = _Str + lVar6;
    pcVar4 = strchr(pcVar3,0x2e);
    if (pcVar4 != (char *)0x0) {
      *pcVar4 = '\0';
      _Count = (longlong)pcVar4 - (longlong)_Str;
    }
  } while (pcVar3 != (char *)0x0);
  if (_Dest != (char *)0x0) {
    free(_Dest);
  }
  free(_Str);
  return 0;
}

/* RVA 0x210b0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_1800210b0(void)

{
  code cVar1;
  char *pcVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  longlong lVar6;
  undefined4 *puVar7;
  code *pcVar8;
  char *pcVar9;
  undefined8 in_R9;
  undefined1 auStack_2d8 [32];
  undefined1 local_2b8 [20];
  int local_2a4;
  char cStack_289;
  undefined1 local_288 [79];
  undefined4 uStack_239;
  undefined1 local_234 [76];
  char local_1e8 [192];
  undefined1 local_128 [272];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_2d8;
  lVar6 = GRinqnxt();
  if ((((lVar6 != 0) && (lVar6 = *(longlong *)topfinfo_exref, *(int *)(lVar6 + 0x550) != 0)) &&
      ((*(int *)(lVar6 + 0x44c) != 0 || (*(int *)(lVar6 + 0x450) != 0)))) &&
     (iVar4 = GRinqpgc(), iVar4 == 0)) {
    return 0;
  }
  local_1e8[0] = DAT_18003f720;
  lVar6 = (longlong)&DAT_180052010 - (longlong)filstr_exref;
  pcVar8 = filstr_exref;
  do {
    cVar1 = *pcVar8;
    pcVar8[lVar6] = cVar1;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != (code)0x0);
  *grerrstr_exref = (code)0x0;
  *(uint *)(Sactions_exref + 4) = *(uint *)(Sactions_exref + 4) | 0x80;
  iVar4 = GRinqautorun();
  if ((iVar4 != 0) && ((*(uint *)Sactions_exref & 0x2000000) == 0)) {
    pcVar8 = APtmpfil_exref;
    do {
      cVar1 = *pcVar8;
      pcVar8[(longlong)(local_288 + (0x50 - (longlong)APtmpfil_exref))] = cVar1;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != (code)0x0);
    puVar3 = &uStack_239;
    do {
      puVar7 = puVar3;
      puVar3 = (undefined4 *)((longlong)puVar7 + 1);
    } while (*(char *)((longlong)puVar7 + 1) != '\0');
    *(undefined4 *)((longlong)puVar7 + 1) = DAT_180041718;
    *(undefined1 *)((longlong)puVar7 + 5) = DAT_18004171c;
    iVar4 = _stat64i32((longlong)&uStack_239 + 1,local_2b8);
    if ((iVar4 != -1) && (local_2a4 != 0)) {
      pcVar8 = APtmpfil_exref;
      do {
        cVar1 = *pcVar8;
        pcVar8[(longlong)(local_288 + -(longlong)APtmpfil_exref)] = cVar1;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != (code)0x0);
      pcVar2 = &cStack_289;
      do {
        pcVar9 = pcVar2;
        pcVar2 = pcVar9 + 1;
      } while (pcVar9[1] != '\0');
      *(undefined8 *)(pcVar9 + 1) = s__save_inm_180041720._0_8_;
      *(undefined2 *)(pcVar9 + 9) = s__save_inm_180041720._8_2_;
      remove(local_288);
      rename((char *)((longlong)&uStack_239 + 1),local_288);
      iVar4 = GEmain(0,local_1e8,0);
      if (iVar4 == -1) goto LAB_180021276;
      iVar4 = GRinqrsl();
      if (iVar4 != 0) {
        iVar4 = FUN_180020450(local_288);
        iVar5 = FUN_180020450((char *)((longlong)&uStack_239 + 1));
        if (iVar5 == iVar4) {
          remove(local_288);
          return 0xffffffff;
        }
      }
      remove(local_288);
      goto LAB_180021320;
    }
  }
  iVar4 = GEmain(0,local_1e8,0);
  if (iVar4 == -1) {
LAB_180021276:
    EXmsgbox();
    return 0xffffffff;
  }
LAB_180021320:
  if (local_1e8[0] != '\0') {
    FUN_180008f80(local_128,"%s.gen",APtmpfil_exref,in_R9);
    gxDriveDialog2("Input Summary Error",1,local_128);
    return 0xffffffff;
  }
  *(undefined4 *)(*(longlong *)topfinfo_exref + 0x148) =
       *(undefined4 *)(*(longlong *)topfinfo_exref + 0x144);
  if ((*(uint *)(Sactions_exref + 4) & 0x200) == 0) {
    GRsetpgc(0);
    GRsetnec(0);
  }
  EXmsgbox();
  return 0;
}

/* RVA 0x213d0 */
undefined8 FUN_1800213d0(void)

{
  return *(undefined8 *)(*(longlong *)topfinfo_exref + 0x560);
}

/* RVA 0x213f0 */
undefined4 FUN_1800213f0(void)

{
  longlong lVar1;
  int *piVar2;
  
  if (*(longlong *)(*(longlong *)topfinfo_exref + 0x560) == 0) {
    return 0xffffffff;
  }
  piVar2 = (int *)deref_ptr();
  if (*piVar2 != 0) {
    lVar1 = *(longlong *)(piVar2 + 2);
    while (lVar1 != 0) {
      piVar2 = (int *)deref_ptr(lVar1);
      if ((*piVar2 == 0) || (*piVar2 == 1)) {
        return 1;
      }
      lVar1 = *(longlong *)(piVar2 + 0x18);
    }
  }
  return 0;
}

/* RVA 0x21460 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_180021460(longlong param_1)

{
  undefined *puVar1;
  longlong lVar2;
  int *piVar3;
  undefined8 uVar4;
  
  if (param_1 == 0) {
    DAT_180052128 = 0;
    _DAT_180052130 = 0;
    return (undefined *)0x0;
  }
  lVar2 = deref_ptr();
  if (DAT_180052128 == 0) {
    DAT_180052128 = *(longlong *)(lVar2 + 8);
  }
  else {
    lVar2 = deref_ptr();
    DAT_180052128 = *(longlong *)(lVar2 + 0x60);
  }
  while( true ) {
    if (DAT_180052128 == 0) {
      _DAT_180052130 = 0;
      return (undefined *)0x0;
    }
    piVar3 = (int *)deref_ptr();
    if ((-1 < *piVar3) && (-1 < piVar3[2])) break;
    DAT_180052128 = *(longlong *)(piVar3 + 0x18);
  }
  _DAT_180052130 = _DAT_180052130 + 1;
  FUN_180022ba0();
  puVar1 = (&PTR_DAT_180050a50)[piVar3[2]];
  uVar4 = 0x7c1;
  if (piVar3[1] != 1) {
    uVar4 = 0x7c2;
  }
  uVar4 = GetSorResStringEx(uVar4);
  FUN_180008f80(&DAT_180052140,uVar4,puVar1,piVar3 + 4);
  return &DAT_180052140;
}

/* RVA 0x21540 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_180021540(longlong param_1,int *param_2,int *param_3,int *param_4)

{
  longlong lVar1;
  int *piVar2;
  
  if (param_1 != 0) {
    lVar1 = deref_ptr();
    if (DAT_180052128 == 0) {
      DAT_180052128 = *(longlong *)(lVar1 + 8);
    }
    else {
      lVar1 = deref_ptr();
      DAT_180052128 = *(longlong *)(lVar1 + 0x60);
    }
    while (DAT_180052128 != 0) {
      piVar2 = (int *)deref_ptr();
      if ((-1 < *piVar2) && (-1 < piVar2[2])) {
        _DAT_180052130 = _DAT_180052130 + 1;
        if (param_2 != (int *)0x0) {
          *param_2 = piVar2[1];
        }
        if (param_3 != (int *)0x0) {
          *param_3 = piVar2[2];
        }
        if (param_4 != (int *)0x0) {
          *param_4 = piVar2[3];
        }
        return piVar2 + 4;
      }
      DAT_180052128 = *(longlong *)(piVar2 + 0x18);
    }
  }
  DAT_180052128 = 0;
  _DAT_180052130 = 0;
  return (int *)0x0;
}

/* RVA 0x21600 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
FUN_180021600(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  int iVar2;
  undefined1 *puVar3;
  longlong lVar4;
  undefined8 uVar5;
  char *pcVar6;
  char *pcVar7;
  undefined1 auStack_388 [32];
  char *local_368;
  char local_358 [144];
  uchar local_2c8 [144];
  char local_238 [272];
  char local_128 [272];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_388;
  if ((int)param_2 == 10) {
    FUN_1800252b0(0,param_2,param_3,param_4);
    return 0;
  }
  pcVar7 = local_128;
  pcVar6 = (char *)(*(longlong *)SBdataptr_exref + 0x10);
  do {
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    *pcVar7 = cVar1;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  puVar3 = (undefined1 *)FUN_180033e90(local_128);
  if (puVar3 == (undefined1 *)0x0) {
    return 0;
  }
  local_358[0] = '\0';
  local_358[1] = '\0';
  local_358[2] = '\0';
  local_358[3] = '\0';
  local_358[4] = '\0';
  local_358[5] = '\0';
  local_358[6] = '\0';
  local_358[7] = '\0';
  local_358[8] = '\0';
  local_358[9] = '\0';
  local_358[10] = '\0';
  local_358[0xb] = '\0';
  local_358[0xc] = '\0';
  local_358[0xd] = '\0';
  local_358[0xe] = '\0';
  local_358[0xf] = '\0';
  local_358[0x80] = 0;
  local_358[0x10] = '\0';
  local_358[0x11] = '\0';
  local_358[0x12] = '\0';
  local_358[0x13] = '\0';
  local_358[0x14] = '\0';
  local_358[0x15] = '\0';
  local_358[0x16] = '\0';
  local_358[0x17] = '\0';
  local_358[0x18] = '\0';
  local_358[0x19] = '\0';
  local_358[0x1a] = '\0';
  local_358[0x1b] = '\0';
  local_358[0x1c] = '\0';
  local_358[0x1d] = '\0';
  local_358[0x1e] = '\0';
  local_358[0x1f] = '\0';
  local_358[0x20] = '\0';
  local_358[0x21] = '\0';
  local_358[0x22] = '\0';
  local_358[0x23] = '\0';
  local_358[0x24] = '\0';
  local_358[0x25] = '\0';
  local_358[0x26] = '\0';
  local_358[0x27] = '\0';
  local_358[0x28] = '\0';
  local_358[0x29] = '\0';
  local_358[0x2a] = '\0';
  local_358[0x2b] = '\0';
  local_358[0x2c] = '\0';
  local_358[0x2d] = '\0';
  local_358[0x2e] = '\0';
  local_358[0x2f] = '\0';
  local_358[0x30] = '\0';
  local_358[0x31] = '\0';
  local_358[0x32] = '\0';
  local_358[0x33] = '\0';
  local_358[0x34] = '\0';
  local_358[0x35] = '\0';
  local_358[0x36] = '\0';
  local_358[0x37] = '\0';
  local_358[0x38] = '\0';
  local_358[0x39] = '\0';
  local_358[0x3a] = '\0';
  local_358[0x3b] = '\0';
  local_358[0x3c] = '\0';
  local_358[0x3d] = '\0';
  local_358[0x3e] = '\0';
  local_358[0x3f] = '\0';
  local_358[0x40] = '\0';
  local_358[0x41] = '\0';
  local_358[0x42] = '\0';
  local_358[0x43] = '\0';
  local_358[0x44] = '\0';
  local_358[0x45] = '\0';
  local_358[0x46] = '\0';
  local_358[0x47] = '\0';
  local_358[0x48] = '\0';
  local_358[0x49] = '\0';
  local_358[0x4a] = '\0';
  local_358[0x4b] = '\0';
  local_358[0x4c] = '\0';
  local_358[0x4d] = '\0';
  local_358[0x4e] = '\0';
  local_358[0x4f] = '\0';
  local_358[0x50] = '\0';
  local_358[0x51] = '\0';
  local_358[0x52] = '\0';
  local_358[0x53] = '\0';
  local_358[0x54] = '\0';
  local_358[0x55] = '\0';
  local_358[0x56] = '\0';
  local_358[0x57] = '\0';
  local_358[0x58] = '\0';
  local_358[0x59] = '\0';
  local_358[0x5a] = '\0';
  local_358[0x5b] = '\0';
  local_358[0x5c] = '\0';
  local_358[0x5d] = '\0';
  local_358[0x5e] = '\0';
  local_358[0x5f] = '\0';
  local_358[0x60] = '\0';
  local_358[0x61] = '\0';
  local_358[0x62] = '\0';
  local_358[99] = '\0';
  local_358[100] = '\0';
  local_358[0x65] = '\0';
  local_358[0x66] = '\0';
  local_358[0x67] = '\0';
  local_358[0x68] = '\0';
  local_358[0x69] = '\0';
  local_358[0x6a] = '\0';
  local_358[0x6b] = '\0';
  local_358[0x6c] = '\0';
  local_358[0x6d] = '\0';
  local_358[0x6e] = '\0';
  local_358[0x6f] = '\0';
  local_358[0x70] = '\0';
  local_358[0x71] = '\0';
  local_358[0x72] = '\0';
  local_358[0x73] = '\0';
  local_358[0x74] = '\0';
  local_358[0x75] = '\0';
  local_358[0x76] = '\0';
  local_358[0x77] = '\0';
  local_358[0x78] = '\0';
  local_358[0x79] = '\0';
  local_358[0x7a] = '\0';
  local_358[0x7b] = '\0';
  local_358[0x7c] = '\0';
  local_358[0x7d] = '\0';
  local_358[0x7e] = '\0';
  local_358[0x7f] = '\0';
  lVar4 = FUN_180033f00(local_358,0x81,4);
  if (lVar4 == 0) {
    return 0;
  }
  iVar2 = *(int *)(*(longlong *)SBdataptr_exref + 0x1218);
  if (iVar2 == 0) {
    pcVar6 = "%s%s";
  }
  else if (iVar2 == 1) {
    pcVar6 = "%s\\%s";
  }
  else {
    if (iVar2 != 2) goto LAB_18002171a;
    pcVar6 = "%s/%s";
  }
  FUN_180008f80(local_238,pcVar6,puVar3,local_358);
LAB_18002171a:
  iVar2 = FUN_180026510((char *)0x0,local_238);
  if (iVar2 == 0) {
    FUN_180033930(local_358,1,local_2c8,0);
    lVar4 = FUN_180033f00(local_2c8,0x81,3);
    if ((lVar4 != 0) && (uVar5 = FUN_180020b70((char *)local_2c8), (int)uVar5 == 0)) {
      iVar2 = FUN_18002b2c0((char *)local_2c8,local_358,puVar3);
      if (iVar2 != 0) {
        FUN_180028530("Receive failed",-1);
        return 0xffffffff;
      }
      FUN_180028530("Receive successful",0);
    }
  }
  else {
    local_368 = local_238;
    FUN_180008f80(dbxbuf_exref,"%c%cFile %s does not exist on the remote host",0x5e,0x21);
    EXyesno(dbxbuf_exref,2,1);
  }
  return 0;
}

/* RVA 0x21800 */
undefined4 FUN_180021800(longlong param_1,int param_2)

{
  bool bVar1;
  longlong lVar2;
  char *pcVar3;
  undefined4 *puVar4;
  undefined7 extraout_var;
  
  if (param_1 == 0) {
    return 0xffffffff;
  }
  lVar2 = deref_ptr();
  lVar2 = *(longlong *)(lVar2 + 8);
  if (lVar2 != 0) {
    pcVar3 = (char *)GRinqscp();
    do {
      puVar4 = (undefined4 *)deref_ptr(lVar2);
      bVar1 = FUN_180021890(pcVar3,(char *)(puVar4 + 4));
      if ((int)CONCAT71(extraout_var,bVar1) != 0) {
        *puVar4 = 1;
        puVar4[3] = 0;
      }
      lVar2 = *(longlong *)(puVar4 + 0x18);
    } while (lVar2 != 0);
    if (param_2 != 0) {
      FUN_180008f10();
    }
  }
  return 0;
}

/* RVA 0x21890 */
bool FUN_180021890(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  size_t _MaxCount;
  
  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {
    pcVar2 = strchr(param_2,0x2e);
    return pcVar2 == (char *)0x0;
  }
  _MaxCount = 0xffffffffffffffff;
  do {
    _MaxCount = _MaxCount + 1;
  } while (param_1[_MaxCount] != '\0');
  iVar1 = strncmp(param_2,param_1,_MaxCount);
  return iVar1 == 0;
}

/* RVA 0x218f0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_1800218f0(void)

{
  char cVar1;
  int iVar2;
  longlong lVar3;
  char *pcVar4;
  char *pcVar5;
  undefined1 auStack_398 [32];
  char *local_378;
  char *local_370;
  char *local_368;
  uchar local_358 [144];
  char local_2c8 [144];
  char local_238 [272];
  char local_128 [272];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_398;
  local_2c8[0] = '\0';
  local_2c8[1] = '\0';
  local_2c8[2] = '\0';
  local_2c8[3] = '\0';
  local_2c8[4] = '\0';
  local_2c8[5] = '\0';
  local_2c8[6] = '\0';
  local_2c8[7] = '\0';
  local_2c8[8] = '\0';
  local_2c8[9] = '\0';
  local_2c8[10] = '\0';
  local_2c8[0xb] = '\0';
  local_2c8[0xc] = '\0';
  local_2c8[0xd] = '\0';
  local_2c8[0xe] = '\0';
  local_2c8[0xf] = '\0';
  local_2c8[0x80] = 0;
  local_2c8[0x10] = '\0';
  local_2c8[0x11] = '\0';
  local_2c8[0x12] = '\0';
  local_2c8[0x13] = '\0';
  local_2c8[0x14] = '\0';
  local_2c8[0x15] = '\0';
  local_2c8[0x16] = '\0';
  local_2c8[0x17] = '\0';
  local_2c8[0x18] = '\0';
  local_2c8[0x19] = '\0';
  local_2c8[0x1a] = '\0';
  local_2c8[0x1b] = '\0';
  local_2c8[0x1c] = '\0';
  local_2c8[0x1d] = '\0';
  local_2c8[0x1e] = '\0';
  local_2c8[0x1f] = '\0';
  local_2c8[0x20] = '\0';
  local_2c8[0x21] = '\0';
  local_2c8[0x22] = '\0';
  local_2c8[0x23] = '\0';
  local_2c8[0x24] = '\0';
  local_2c8[0x25] = '\0';
  local_2c8[0x26] = '\0';
  local_2c8[0x27] = '\0';
  local_2c8[0x28] = '\0';
  local_2c8[0x29] = '\0';
  local_2c8[0x2a] = '\0';
  local_2c8[0x2b] = '\0';
  local_2c8[0x2c] = '\0';
  local_2c8[0x2d] = '\0';
  local_2c8[0x2e] = '\0';
  local_2c8[0x2f] = '\0';
  local_2c8[0x30] = '\0';
  local_2c8[0x31] = '\0';
  local_2c8[0x32] = '\0';
  local_2c8[0x33] = '\0';
  local_2c8[0x34] = '\0';
  local_2c8[0x35] = '\0';
  local_2c8[0x36] = '\0';
  local_2c8[0x37] = '\0';
  local_2c8[0x38] = '\0';
  local_2c8[0x39] = '\0';
  local_2c8[0x3a] = '\0';
  local_2c8[0x3b] = '\0';
  local_2c8[0x3c] = '\0';
  local_2c8[0x3d] = '\0';
  local_2c8[0x3e] = '\0';
  local_2c8[0x3f] = '\0';
  local_2c8[0x40] = '\0';
  local_2c8[0x41] = '\0';
  local_2c8[0x42] = '\0';
  local_2c8[0x43] = '\0';
  local_2c8[0x44] = '\0';
  local_2c8[0x45] = '\0';
  local_2c8[0x46] = '\0';
  local_2c8[0x47] = '\0';
  local_2c8[0x48] = '\0';
  local_2c8[0x49] = '\0';
  local_2c8[0x4a] = '\0';
  local_2c8[0x4b] = '\0';
  local_2c8[0x4c] = '\0';
  local_2c8[0x4d] = '\0';
  local_2c8[0x4e] = '\0';
  local_2c8[0x4f] = '\0';
  local_2c8[0x50] = '\0';
  local_2c8[0x51] = '\0';
  local_2c8[0x52] = '\0';
  local_2c8[0x53] = '\0';
  local_2c8[0x54] = '\0';
  local_2c8[0x55] = '\0';
  local_2c8[0x56] = '\0';
  local_2c8[0x57] = '\0';
  local_2c8[0x58] = '\0';
  local_2c8[0x59] = '\0';
  local_2c8[0x5a] = '\0';
  local_2c8[0x5b] = '\0';
  local_2c8[0x5c] = '\0';
  local_2c8[0x5d] = '\0';
  local_2c8[0x5e] = '\0';
  local_2c8[0x5f] = '\0';
  local_2c8[0x60] = '\0';
  local_2c8[0x61] = '\0';
  local_2c8[0x62] = '\0';
  local_2c8[99] = '\0';
  local_2c8[100] = '\0';
  local_2c8[0x65] = '\0';
  local_2c8[0x66] = '\0';
  local_2c8[0x67] = '\0';
  local_2c8[0x68] = '\0';
  local_2c8[0x69] = '\0';
  local_2c8[0x6a] = '\0';
  local_2c8[0x6b] = '\0';
  local_2c8[0x6c] = '\0';
  local_2c8[0x6d] = '\0';
  local_2c8[0x6e] = '\0';
  local_2c8[0x6f] = '\0';
  local_2c8[0x70] = '\0';
  local_2c8[0x71] = '\0';
  local_2c8[0x72] = '\0';
  local_2c8[0x73] = '\0';
  local_2c8[0x74] = '\0';
  local_2c8[0x75] = '\0';
  local_2c8[0x76] = '\0';
  local_2c8[0x77] = '\0';
  local_2c8[0x78] = '\0';
  local_2c8[0x79] = '\0';
  local_2c8[0x7a] = '\0';
  local_2c8[0x7b] = '\0';
  local_2c8[0x7c] = '\0';
  local_2c8[0x7d] = '\0';
  local_2c8[0x7e] = '\0';
  local_2c8[0x7f] = '\0';
  lVar3 = FUN_180033f00(local_2c8,0x81,2);
  if (lVar3 == 0) {
    return 0;
  }
  iVar2 = _access(local_2c8,4);
  if (iVar2 != 0) {
    local_378 = local_2c8;
    FUN_180008f80(dbxbuf_exref,"%c%cFile %s does not exist",0x5e,0x21);
    EXyesno(dbxbuf_exref,2,1);
    return 0;
  }
  local_358[0x80] = 0;
  local_358[0] = '\0';
  local_358[1] = '\0';
  local_358[2] = '\0';
  local_358[3] = '\0';
  local_358[4] = '\0';
  local_358[5] = '\0';
  local_358[6] = '\0';
  local_358[7] = '\0';
  local_358[8] = '\0';
  local_358[9] = '\0';
  local_358[10] = '\0';
  local_358[0xb] = '\0';
  local_358[0xc] = '\0';
  local_358[0xd] = '\0';
  local_358[0xe] = '\0';
  local_358[0xf] = '\0';
  local_358[0x10] = '\0';
  local_358[0x11] = '\0';
  local_358[0x12] = '\0';
  local_358[0x13] = '\0';
  local_358[0x14] = '\0';
  local_358[0x15] = '\0';
  local_358[0x16] = '\0';
  local_358[0x17] = '\0';
  local_358[0x18] = '\0';
  local_358[0x19] = '\0';
  local_358[0x1a] = '\0';
  local_358[0x1b] = '\0';
  local_358[0x1c] = '\0';
  local_358[0x1d] = '\0';
  local_358[0x1e] = '\0';
  local_358[0x1f] = '\0';
  local_358[0x20] = '\0';
  local_358[0x21] = '\0';
  local_358[0x22] = '\0';
  local_358[0x23] = '\0';
  local_358[0x24] = '\0';
  local_358[0x25] = '\0';
  local_358[0x26] = '\0';
  local_358[0x27] = '\0';
  local_358[0x28] = '\0';
  local_358[0x29] = '\0';
  local_358[0x2a] = '\0';
  local_358[0x2b] = '\0';
  local_358[0x2c] = '\0';
  local_358[0x2d] = '\0';
  local_358[0x2e] = '\0';
  local_358[0x2f] = '\0';
  local_358[0x30] = '\0';
  local_358[0x31] = '\0';
  local_358[0x32] = '\0';
  local_358[0x33] = '\0';
  local_358[0x34] = '\0';
  local_358[0x35] = '\0';
  local_358[0x36] = '\0';
  local_358[0x37] = '\0';
  local_358[0x38] = '\0';
  local_358[0x39] = '\0';
  local_358[0x3a] = '\0';
  local_358[0x3b] = '\0';
  local_358[0x3c] = '\0';
  local_358[0x3d] = '\0';
  local_358[0x3e] = '\0';
  local_358[0x3f] = '\0';
  local_358[0x40] = '\0';
  local_358[0x41] = '\0';
  local_358[0x42] = '\0';
  local_358[0x43] = '\0';
  local_358[0x44] = '\0';
  local_358[0x45] = '\0';
  local_358[0x46] = '\0';
  local_358[0x47] = '\0';
  local_358[0x48] = '\0';
  local_358[0x49] = '\0';
  local_358[0x4a] = '\0';
  local_358[0x4b] = '\0';
  local_358[0x4c] = '\0';
  local_358[0x4d] = '\0';
  local_358[0x4e] = '\0';
  local_358[0x4f] = '\0';
  local_358[0x50] = '\0';
  local_358[0x51] = '\0';
  local_358[0x52] = '\0';
  local_358[0x53] = '\0';
  local_358[0x54] = '\0';
  local_358[0x55] = '\0';
  local_358[0x56] = '\0';
  local_358[0x57] = '\0';
  local_358[0x58] = '\0';
  local_358[0x59] = '\0';
  local_358[0x5a] = '\0';
  local_358[0x5b] = '\0';
  local_358[0x5c] = '\0';
  local_358[0x5d] = '\0';
  local_358[0x5e] = '\0';
  local_358[0x5f] = '\0';
  local_358[0x60] = '\0';
  local_358[0x61] = '\0';
  local_358[0x62] = '\0';
  local_358[99] = '\0';
  local_358[100] = '\0';
  local_358[0x65] = '\0';
  local_358[0x66] = '\0';
  local_358[0x67] = '\0';
  local_358[0x68] = '\0';
  local_358[0x69] = '\0';
  local_358[0x6a] = '\0';
  local_358[0x6b] = '\0';
  local_358[0x6c] = '\0';
  local_358[0x6d] = '\0';
  local_358[0x6e] = '\0';
  local_358[0x6f] = '\0';
  local_358[0x70] = '\0';
  local_358[0x71] = '\0';
  local_358[0x72] = '\0';
  local_358[0x73] = '\0';
  local_358[0x74] = '\0';
  local_358[0x75] = '\0';
  local_358[0x76] = '\0';
  local_358[0x77] = '\0';
  local_358[0x78] = '\0';
  local_358[0x79] = '\0';
  local_358[0x7a] = '\0';
  local_358[0x7b] = '\0';
  local_358[0x7c] = '\0';
  local_358[0x7d] = '\0';
  local_358[0x7e] = '\0';
  local_358[0x7f] = '\0';
  FUN_180033930(local_2c8,0,local_358,1);
  pcVar5 = local_128;
  pcVar4 = (char *)(*(longlong *)SBdataptr_exref + 0x10);
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    *pcVar5 = cVar1;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  pcVar4 = (char *)FUN_180033e90(local_128);
  if (pcVar4 == (char *)0x0) {
    return 0;
  }
  lVar3 = FUN_180033f00(local_358,0x81,5);
  if (lVar3 == 0) {
    return 0;
  }
  iVar2 = *(int *)(*(longlong *)SBdataptr_exref + 0x1218);
  if (iVar2 == 0) {
    pcVar5 = "%s%s";
  }
  else if (iVar2 == 1) {
    pcVar5 = "%s\\%s";
  }
  else {
    if (iVar2 != 2) goto LAB_180021aae;
    pcVar5 = "%s/%s";
  }
  FUN_180008f80(local_238,pcVar5,pcVar4,local_358);
LAB_180021aae:
  iVar2 = FUN_180026510((char *)0x0,local_238);
  if (iVar2 == 0) {
    local_368 = "Cancel to abort send.";
    local_370 = "OK to overwrite the existing file.  ";
    local_378 = local_238;
    FUN_180008f80(dbxbuf_exref,"%c%cFile %s already exists on the remote host.  %s%s",0x5e,0x21);
    iVar2 = EXyesno(dbxbuf_exref,3,1);
    if (iVar2 == 2) {
      return 0;
    }
  }
  iVar2 = FUN_18002b360(local_2c8,(char *)local_358,pcVar4);
  if (iVar2 == 0) {
    FUN_180028530("Send successful",0);
    return 0;
  }
  FUN_180028530("Send failed",-1);
  return 0xffffffff;
}

/* RVA 0x21b60 */
void FUN_180021b60(int param_1)

{
  if ((DAT_180052ec4 == param_1) || (DAT_180052ec4 = param_1, param_1 == 0)) {
    return;
  }
  GRsetfop(1);
  return;
}

/* RVA 0x21b80 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_180021b80(int param_1,undefined8 param_2,longlong param_3)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  char *_Str1;
  char *pcVar5;
  undefined4 extraout_var;
  char *pcVar6;
  ulonglong uVar7;
  longlong lVar8;
  undefined1 *puVar9;
  code *pcVar10;
  code *pcVar11;
  undefined1 auStack_128 [32];
  uint *local_108;
  undefined8 local_100;
  uint local_f8;
  uint local_f4;
  char *local_f0;
  longlong local_e8;
  longlong local_e0;
  longlong local_d8;
  char *local_d0;
  undefined4 local_c8;
  undefined2 local_c4;
  undefined1 local_c2;
  ulonglong local_28;
  
  local_28 = DAT_1800516d8 ^ (ulonglong)auStack_128;
  local_f8 = 0;
  _Str1 = (char *)FUN_180022df0(param_3,&local_f8);
  local_f0 = _Str1;
  local_e8 = FUN_180022df0(param_3,&local_f8);
  local_e0 = FUN_180022df0(param_3,&local_f8);
  local_d8 = FUN_180022df0(param_3,&local_f8);
  pcVar5 = (char *)FUN_180022df0(param_3,&local_f8);
  uVar2 = *(undefined4 *)SBsession_exref;
  local_d0 = pcVar5;
  iVar3 = _stricmp(_Str1,(char *)commsect_exref);
  iVar4 = GRinqcnn();
  if (iVar4 != 0) {
    *(undefined4 *)GRcmdx_exref = 0x10;
    iVar4 = FUN_180022a50(0x10,1,(char *)0x0,(uchar *)0x0);
    if (iVar4 == 1) {
      return CONCAT44(extraout_var,iVar4);
    }
  }
  pcVar6 = (char *)(*(longlong *)SBdataptr_exref + 0x10);
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    *pcVar6 = cVar1;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  GRsetsbs(0);
  if (iVar3 != 0) {
    *(undefined4 *)PTR_DAT_180044158 = 0;
  }
  uVar7 = SBreaini(1,_Str1);
  local_f4 = (uint)uVar7;
  if (local_f4 != 0xffffffff) {
    pcVar10 = FUN_18002e110;
    puVar9 = &DAT_180050ad8;
    local_c4 = DAT_180041814;
    pcVar11 = submitdata_exref + 0xc10;
    local_c2 = DAT_180041816;
    local_108 = &local_f4;
    local_100 = 0;
    local_c8 = 0;
    SELF_INITIALIZE(&local_c8);
    if (iVar3 == 0) {
      GRsetsbs(uVar2);
    }
    if (*hvars_exref != (code)0x0) {
      FUN_180022e30((longlong)&local_f0);
    }
    if (param_1 == 0) {
      FUN_180022f60();
    }
    push_mouse_mask(0xd);
    show_mouse();
    lVar8 = *(longlong *)SBdataptr_exref;
    *(undefined1 *)(lVar8 + 0x110) = DAT_18003f720;
    do {
      local_f4 = FUN_18002b640(lVar8,puVar9,(char *)pcVar10,(int *)pcVar11);
    } while (local_f4 == 1);
    pop_mouse_mask();
    show_mouse();
    uVar7 = (ulonglong)local_f4;
  }
  return uVar7;
}

/* RVA 0x21db0 */
undefined8 FUN_180021db0(int param_1,undefined4 *param_2,undefined4 *param_3,longlong param_4)

{
  char cVar1;
  longlong lVar2;
  char *pcVar3;
  
  if (*(longlong *)(*(longlong *)topfinfo_exref + 0x560) != 0) {
    lVar2 = deref_ptr();
    for (lVar2 = *(longlong *)(lVar2 + 8); lVar2 != 0; lVar2 = *(longlong *)(lVar2 + 0x60)) {
      lVar2 = deref_ptr();
      if (*(int *)(lVar2 + 0xc) == param_1) {
        if (param_2 != (undefined4 *)0x0) {
          *param_2 = *(undefined4 *)(lVar2 + 4);
        }
        if (param_3 != (undefined4 *)0x0) {
          *param_3 = *(undefined4 *)(lVar2 + 8);
        }
        if (param_4 != 0) {
          pcVar3 = (char *)(lVar2 + 0x10);
          lVar2 = param_4 - (longlong)pcVar3;
          do {
            cVar1 = *pcVar3;
            pcVar3[lVar2] = cVar1;
            pcVar3 = pcVar3 + 1;
          } while (cVar1 != '\0');
        }
        return 0;
      }
    }
  }
  return 0xffffffff;
}

/* RVA 0x21e70 */
undefined4 FUN_180021e70(int param_1,undefined8 param_2,undefined8 param_3,uchar *param_4)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  
  iVar2 = FUN_18002c9f0(filstr_exref,param_4,*(char **)SBdataptr_exref,(char *)param_4);
  if (iVar2 != -1) {
    pcVar3 = *(char **)topfinfo_exref;
    pcVar4 = pcVar3 + 0x1e8;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
      *pcVar4 = cVar1;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    if (iVar2 == 1) {
      if (*(int *)(*(longlong *)topfinfo_exref + 0x154) != 0) {
        if (param_1 != 0) {
          hide_mouse();
          push_mouse_mask(0xd);
          show_mouse();
          save_graphics();
          STsavfil(*(undefined8 *)iwpfile_exref,0,1);
          hide_mouse();
          pop_mouse_mask();
          show_mouse();
          return 1;
        }
        save_graphics();
        STsavfil(*(undefined8 *)iwpfile_exref,0,1);
      }
      return 1;
    }
    EXmsgbox();
    if (iVar2 == 0) {
      pcVar3 = *(char **)topfinfo_exref;
      pcVar4 = pcVar3 + 0x1e8;
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
        *pcVar4 = cVar1;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
    }
  }
  return 0;
}

/* RVA 0x21fa0 */
bool FUN_180021fa0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulonglong uVar1;
  
  if ((int)param_2 == 10) {
    FUN_1800252b0(0,param_2,param_3,param_4);
    return false;
  }
  uVar1 = FUN_1800356d0();
  return (int)uVar1 == 1;
}

/* RVA 0x21fd0 */
undefined4 FUN_180021fd0(longlong param_1)

{
  longlong lVar1;
  int *piVar2;
  undefined8 uVar3;
  longlong *plVar4;
  
  if (param_1 == 0) {
    return 0xffffffff;
  }
  FUN_180006ad0();
  lVar1 = deref_ptr(param_1);
  plVar4 = (longlong *)(lVar1 + 8);
  lVar1 = *(longlong *)(lVar1 + 8);
  while ((lVar1 != 0 && (piVar2 = (int *)deref_ptr(lVar1), piVar2 != (int *)0x0))) {
    if ((*piVar2 == 0) ||
       (uVar3 = thunk_FUN_180006bf0(piVar2[2],(char *)(piVar2 + 4)), (int)uVar3 != 0)) {
      plVar4 = (longlong *)(piVar2 + 0x18);
    }
    else {
      lVar1 = *plVar4;
      *plVar4 = *(longlong *)(piVar2 + 0x18);
      free3(lVar1,0x68);
    }
    lVar1 = *plVar4;
  }
  return 0;
}

/* RVA 0x22060 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_180022060(int param_1,char *param_2,char *param_3,undefined8 param_4)

{
  code cVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  ulonglong uVar8;
  undefined7 extraout_var;
  longlong lVar9;
  undefined8 uVar10;
  undefined8 *puVar11;
  FILE *_File;
  FILE *_File_00;
  FILE *_File_01;
  code *pcVar12;
  longlong lVar13;
  undefined8 *puVar14;
  longlong lVar15;
  char *pcVar16;
  ulonglong uVar17;
  undefined1 auStack_668 [32];
  char *local_648;
  char *local_640;
  char *local_638;
  char *local_630;
  char *local_628;
  char *local_620;
  char *local_618;
  char *local_610;
  char *local_608;
  char local_5fe [5];
  undefined8 uStack_5f9;
  char local_4e8 [128];
  uchar local_468 [272];
  uchar local_358 [272];
  uchar local_248 [272];
  undefined1 local_138 [272];
  ulonglong local_28;
  
  local_28 = DAT_1800516d8 ^ (ulonglong)auStack_668;
  lVar13 = 0;
  iVar6 = 0;
  iVar5 = *(int *)(submitdata_exref + 0x1218);
  iVar4 = GRinqcnn();
  if ((iVar4 == 0) && (iVar5 != 1)) {
    pcVar16 = "simulation";
    pcVar7 = (char *)MVGetProductName();
    iVar5 = MVGetProductCode();
    if (iVar5 == 2) {
LAB_18002212b:
      pcVar16 = "problem";
    }
    else {
      uVar8 = 0xffffffffffffffff;
      do {
        uVar8 = uVar8 + 1;
      } while (param_2[uVar8] != '\0');
      if (7 < uVar8) {
        lVar15 = -1;
        do {
          lVar9 = lVar15;
          lVar15 = lVar9 + 1;
        } while (param_2[lVar9 + 1] != '\0');
        do {
          lVar15 = lVar13 + 1;
          if (param_2[lVar13 + lVar9 + -6] != (&DAT_180041948)[lVar13]) goto LAB_180022132;
          lVar13 = lVar15;
        } while (lVar15 != 8);
        pcVar7 = "Aspen Properties";
        goto LAB_18002212b;
      }
    }
LAB_180022132:
    local_638 = " Connect to a host and run the ";
  }
  else {
    iVar4 = GRinqcnn();
    if (((iVar4 == 0) && (iVar5 == 1)) || (iVar5 = GRinqcnn(), iVar5 == 1)) {
      iVar5 = GRinqQRs();
      if (iVar5 == 0) {
        bVar3 = false;
      }
      else {
        iVar5 = MVGetProductCode();
        pcVar16 = "%s.aprpdf";
        if (iVar5 != 2) {
          pcVar16 = "%s.appdf";
        }
        param_3 = *(char **)topfinfo_exref;
        FUN_180008f80(local_248,pcVar16,param_3,param_4);
        name_lwr(local_248);
        pcVar12 = open_path_exref;
        do {
          cVar1 = *pcVar12;
          pcVar12[(longlong)(local_138 + -(longlong)open_path_exref)] = cVar1;
          pcVar12 = pcVar12 + 1;
        } while (cVar1 != (code)0x0);
        name_lwr(local_138);
        iVar5 = FUN_180026510(local_138,(char *)local_248);
        bVar3 = iVar5 == 0;
      }
      if (bVar3) {
LAB_1800223d9:
        if (*(int *)triggered_by_canned_exref == 0) {
          iVar5 = GRinqpgc();
          if (iVar5 != 0) {
            MVGetProductCode();
            uVar10 = GetSorResStringEx(0xa40a);
            FUN_180008f80(dbxbuf_exref,uVar10,param_3,param_4);
            param_3 = (char *)0x1;
            iVar5 = EXyesno(dbxbuf_exref);
            if (iVar5 == 0) {
              return 0xffffffff;
            }
          }
          if (param_1 == 1) {
            return 0;
          }
          if ((*(int *)(*(longlong *)topfinfo_exref + 0x14c) != 0) &&
             (*(int *)(*(longlong *)topfinfo_exref + 0x150) == 0)) {
            local_630 = "  Select OK to continue, Cancel to abort.";
            param_4 = 0x21;
            local_638 = " first, then generate the report.";
            local_640 = "the current problem definition.  You should run the simulation";
            local_648 = "Aspen Plus Report files will be inconsistent with ";
            FUN_180008f80(dbxbuf_exref,"%c%c%s%s%s%s",0x5e,0x21);
            param_3 = (char *)0x1;
            iVar5 = EXyesno(dbxbuf_exref);
            if (iVar5 == 2) {
              return 1;
            }
          }
          if (param_1 == 0) {
            iVar5 = GRchkmmdir(param_2,2);
            if (iVar5 != 0) {
              return 0xffffffff;
            }
            pcVar7 = local_5fe + (6 - (longlong)param_2);
            pcVar16 = param_2;
            do {
              cVar2 = *pcVar16;
              pcVar16[(longlong)pcVar7] = cVar2;
              pcVar16 = pcVar16 + 1;
            } while (cVar2 != '\0');
            name_lwr((uchar *)((longlong)&uStack_5f9 + 1));
            uVar8 = 0xffffffffffffffff;
            do {
              uVar17 = uVar8;
              uVar8 = uVar17 + 1;
            } while (local_5fe[uVar17 + 7] != '\0');
            iVar5 = MVGetProductCode();
            if (iVar5 == 2) {
              if (uVar8 < 7) {
LAB_180022599:
                puVar11 = &uStack_5f9;
                do {
                  pcVar16 = (char *)((longlong)puVar11 + 1);
                  puVar11 = (undefined8 *)((longlong)puVar11 + 1);
                } while (*pcVar16 != '\0');
                *puVar11 = _DAT_180041948;
              }
              else {
                param_3 = local_5fe + uVar17;
                pcVar16 = (char *)0x0;
                do {
                  pcVar7 = pcVar16 + 1;
                  if (param_3[(longlong)pcVar16] != (&DAT_180041948)[(longlong)pcVar16])
                  goto LAB_180022599;
                  pcVar16 = pcVar7;
                } while (pcVar7 != (char *)0x8);
              }
            }
            else {
              param_3 = local_5fe + uVar17 + 7;
              if (uVar8 < 7) {
                if (uVar8 < 4) {
LAB_180022627:
                  puVar11 = &uStack_5f9;
                  do {
                    puVar14 = puVar11;
                    puVar11 = (undefined8 *)((longlong)puVar14 + 1);
                  } while (*(char *)((longlong)puVar14 + 1) != '\0');
                  *(undefined4 *)((longlong)puVar14 + 1) = _DAT_180041c30;
                  *(undefined1 *)((longlong)puVar14 + 5) = DAT_180041c34;
                }
                else {
LAB_1800225fd:
                  pcVar7 = ".rep";
                  lVar13 = 0;
                  do {
                    lVar15 = lVar13 + 1;
                    if (local_5fe[lVar13 + uVar8 + 2] != (&DAT_180041c30)[lVar13])
                    goto LAB_180022627;
                    lVar13 = lVar15;
                  } while (lVar15 != 5);
                }
              }
              else {
                lVar13 = 0;
                do {
                  lVar15 = lVar13 + 1;
                  if (local_5fe[lVar13 + uVar8 + -1] != (&DAT_180041948)[lVar13])
                  goto LAB_1800225fd;
                  lVar13 = lVar15;
                } while (lVar15 != 8);
                pcVar7 = (char *)0x8;
              }
            }
            iVar5 = GRchkwrt((longlong)&uStack_5f9 + 1);
            if (iVar5 == -1) {
              return 0xffffffff;
            }
          }
          else {
            pcVar7 = local_5fe + (6 - (longlong)param_2);
            pcVar16 = param_2;
            do {
              cVar2 = *pcVar16;
              pcVar16[(longlong)pcVar7] = cVar2;
              pcVar16 = pcVar16 + 1;
            } while (cVar2 != '\0');
          }
          if (*(int *)(*(longlong *)topfinfo_exref + 0x380) == 1) {
            uVar8 = FUN_180022f00(param_2,pcVar7,param_3,param_4);
            iVar6 = (int)uVar8;
            if (iVar6 == -1) {
              local_648 = " Export Report failed";
              FUN_180008f80(dbxbuf_exref,"%c%c%s",0x5e,0x21);
              goto LAB_180022a06;
            }
          }
          if ((*(int *)(*(longlong *)topfinfo_exref + 0x380) == 1) && (iVar6 == 2)) {
            return 0;
          }
          FUN_180008f80(local_468,"%s.rp1",APtmpfil_exref,param_4);
          name_lwr(local_468);
          FUN_180008f80(local_358,"%s.rp2",APtmpfil_exref,param_4);
          name_lwr(local_358);
          if ((*(int *)(*(longlong *)SBdataptr_exref + 0x1214) != 0) &&
             ((iVar5 = FUN_18002b2c0((char *)local_468,local_468,
                                     (undefined1 *)(*(longlong *)SBdataptr_exref + 0x10)),
              iVar5 != 0 ||
              (iVar5 = FUN_18002b2c0((char *)local_358,local_358,
                                     (undefined1 *)(*(longlong *)SBdataptr_exref + 0x10)),
              iVar5 == -1)))) {
            FUN_180028530("Export Report failed\nCould not receive remote file",-1);
            return 0xffffffff;
          }
          _File = fopen((char *)local_468,"r");
          if (_File == (FILE *)0x0) {
            FUN_180028530("Export Report failed\nCould not find local file",-1);
            return 0xffffffff;
          }
          _File_00 = fopen((char *)local_358,"r");
          if (_File_00 == (FILE *)0x0) {
            FUN_180028530("Export Report failed\nCould not find local file",-1);
            fclose(_File);
            return 0xffffffff;
          }
          _File_01 = fopen((char *)((longlong)&uStack_5f9 + 1),"w");
          if (_File_01 == (FILE *)0x0) {
            return 0xffffffff;
          }
          pcVar16 = fgets(local_4e8,0x78,_File);
          while (pcVar16 != (char *)0x0) {
            fputs(pcVar16,_File_01);
            pcVar16 = fgets(local_4e8,0x78,_File);
          }
          pcVar16 = fgets(local_4e8,0x78,_File_00);
          while (pcVar16 != (char *)0x0) {
            fputs(pcVar16,_File_01);
            pcVar16 = fgets(local_4e8,0x78,_File_00);
          }
          fclose(_File_01);
          fclose(_File);
          fclose(_File_00);
          if (*(int *)(*(longlong *)SBdataptr_exref + 0x1214) != 0) {
            remove((char *)local_468);
            remove((char *)local_358);
          }
          if (param_1 == 0) {
            check_reportoption(param_2);
          }
          FUN_180028200("Report exported");
          return 0;
        }
        local_638 = " you will be able to export report files.";
        local_640 = " of the problem.  You must re-run the simulation before";
        local_648 = "You have made an input change that required reinitialization";
        FUN_180008f80(dbxbuf_exref,"%c%c%s%s%s",0x5e,0x69);
        goto LAB_180022a06;
      }
    }
    else if (((0x1b < *(uint *)(*(longlong *)topfinfo_exref + 0x380)) ||
             ((0x800000aU >> (*(uint *)(*(longlong *)topfinfo_exref + 0x380) & 0x1f) & 1) == 0)) ||
            (iVar5 = GRinqiap(), iVar5 != 0)) {
      lVar15 = *(longlong *)topfinfo_exref;
      iVar5 = *(int *)(lVar15 + 0x380);
      if (((((iVar5 != 0x51) && (iVar5 != 0xf3)) && ((iVar5 != 0x2d9 && (iVar5 != 9)))) ||
          (*(int *)(lVar15 + 0x158) != 0)) &&
         ((((*(int *)(lVar15 + 0x454) != 0 || (*(int *)(lVar15 + 0x44c) != 0)) ||
           ((*(int *)(lVar15 + 0x450) != 0 || (iVar5 = GRinqust(), iVar5 != 0)))) ||
          (((iVar5 = GRinqpgc(), iVar5 != 0 && (*(int *)(*(longlong *)topfinfo_exref + 0x14c) != 0))
           || (((iVar5 = GRinqdrs(0), iVar5 != 0 && (iVar5 = GRinqdrs(1), iVar5 != 0)) ||
               (((iVar5 = GRinqQRs(), iVar5 != 0 &&
                 (*(int *)(*(longlong *)topfinfo_exref + 0x380) == 1)) ||
                ((iVar5 = GRinqgpd(), iVar5 != 0 && (iVar5 = GRinqsbm(), iVar5 != 0))))))))))))
      goto LAB_1800223d9;
    }
    bVar3 = FUN_1800297f0();
    pcVar16 = "simulation";
    if ((int)CONCAT71(extraout_var,bVar3) != 0) {
      pcVar7 = (char *)MVGetProductName();
      iVar5 = MVGetProductCode();
      if (iVar5 == 2) {
LAB_18002298b:
        pcVar16 = "calculations";
      }
      else {
        uVar8 = 0xffffffffffffffff;
        do {
          uVar8 = uVar8 + 1;
        } while (param_2[uVar8] != '\0');
        if (7 < uVar8) {
          lVar15 = -1;
          do {
            lVar9 = lVar15;
            lVar15 = lVar9 + 1;
          } while (param_2[lVar9 + 1] != '\0');
          do {
            lVar15 = lVar13 + 1;
            if (param_2[lVar13 + lVar9 + -6] != (&DAT_180041948)[lVar13]) goto LAB_180022992;
            lVar13 = lVar15;
          } while (lVar15 != 8);
          pcVar7 = "Aspen Properties";
          goto LAB_18002298b;
        }
      }
LAB_180022992:
      local_608 = " engine host.";
      local_618 = " on the ";
      local_620 = "Batch run report or output files already exist";
      local_628 = " first, then generate the report.  ";
      local_638 = " generated. Run the interactive ";
      local_640 = " Report cannot be";
      local_648 = pcVar7;
      local_630 = pcVar16;
      local_610 = pcVar7;
      FUN_180008f80(dbxbuf_exref,"%c%c%s%s%s%s%s%s%s%s%s",0x5e,0x69);
      goto LAB_180022a06;
    }
    pcVar7 = (char *)MVGetProductName();
    iVar5 = MVGetProductCode();
    if (iVar5 == 2) {
LAB_18002228b:
      pcVar16 = "problem";
    }
    else if (param_2 != (char *)0x0) {
      uVar8 = 0xffffffffffffffff;
      do {
        uVar8 = uVar8 + 1;
      } while (param_2[uVar8] != '\0');
      if (7 < uVar8) {
        lVar15 = -1;
        do {
          lVar9 = lVar15;
          lVar15 = lVar9 + 1;
        } while (param_2[lVar9 + 1] != '\0');
        do {
          lVar15 = lVar13 + 1;
          if (param_2[lVar13 + lVar9 + -6] != (&DAT_180041948)[lVar13]) goto LAB_180022292;
          lVar13 = lVar15;
        } while (lVar15 != 8);
        pcVar7 = "Aspen Properties";
        goto LAB_18002228b;
      }
    }
LAB_180022292:
    local_638 = " Run the ";
  }
  local_628 = " first, then generate the report.";
  local_640 = " Report cannot be generated.";
  local_648 = pcVar7;
  local_630 = pcVar16;
  FUN_180008f80(dbxbuf_exref,"%c%c%s%s%s%s%s",0x5e,0x69);
LAB_180022a06:
  EXyesno(dbxbuf_exref,2);
  return 0xffffffff;
}

/* RVA 0x22a50 */
undefined4 FUN_180022a50(undefined4 param_1,uint param_2,char *param_3,uchar *param_4)

{
  bool bVar1;
  undefined4 uVar2;
  undefined7 extraout_var;
  undefined7 extraout_var_00;
  int *piVar3;
  ulonglong uVar4;
  undefined7 extraout_var_01;
  undefined8 uVar5;
  int iVar6;
  
  uVar2 = 0;
  uVar4 = (ulonglong)param_3 & 0xffffffff;
  iVar6 = (int)param_3;
  switch(param_1) {
  case 1:
    uVar5 = FUN_1800210b0();
    uVar2 = (undefined4)uVar5;
    break;
  case 2:
    uVar2 = FUN_180021e70(param_2,uVar4,1,param_4);
    break;
  case 5:
    uVar5 = FUN_180020c70(param_2);
    uVar2 = (undefined4)uVar5;
    break;
  case 7:
  case 0x11:
    bVar1 = FUN_180020e10((ulonglong)param_2,iVar6);
    uVar2 = (undefined4)CONCAT71(extraout_var,bVar1);
    break;
  case 8:
  case 0x12:
    bVar1 = FUN_180020ae0((ulonglong)param_2,iVar6);
    uVar2 = (undefined4)CONCAT71(extraout_var_00,bVar1);
    break;
  case 0xc:
    piVar3 = (int *)SEGetSettingValue("SkipEngineLoadOnDocumentLoad",0);
    if ((piVar3 != (int *)0x0) && (*piVar3 != 0)) {
      CreateApwnLibrariesTest();
      return 0;
    }
    uVar4 = FUN_180021b80(param_2,uVar4,(longlong)param_4);
    uVar2 = (undefined4)uVar4;
    break;
  case 0xd:
    uVar5 = FUN_1800218f0();
    uVar2 = (undefined4)uVar5;
    break;
  case 0xe:
    uVar5 = FUN_180021600((ulonglong)param_2,uVar4,param_3,param_4);
    uVar2 = (undefined4)uVar5;
    break;
  case 0xf:
    bVar1 = FUN_180021fa0((ulonglong)param_2,uVar4,param_3,param_4);
    uVar2 = (undefined4)CONCAT71(extraout_var_01,bVar1);
    break;
  case 0x10:
    uVar5 = FUN_180020b10((ulonglong)param_2,uVar4,param_3,(char *)param_4);
    uVar2 = (undefined4)uVar5;
    break;
  case 0x13:
    uVar5 = FUN_180022060(iVar6,(char *)param_4,param_3,param_4);
    uVar2 = (undefined4)uVar5;
  }
  return uVar2;
}

/* RVA 0x22ba0 */
void FUN_180022ba0(void)

{
  undefined *puVar1;
  int iVar2;
  undefined **ppuVar3;
  uint uVar4;
  
  if (DAT_180052124 != 1) {
    ppuVar3 = &PTR_DAT_180050a50;
    uVar4 = 0;
    DAT_180052124 = 1;
    do {
      iVar2 = _stricmp(*ppuVar3,"BLOCK");
      if (iVar2 == 0) {
        puVar1 = (undefined *)GetSorResStringEx(0x7b3);
        *ppuVar3 = puVar1;
      }
      iVar2 = _stricmp(*ppuVar3,"CONVERGENCE");
      if (iVar2 == 0) {
        puVar1 = (undefined *)GetSorResStringEx(0x7b4);
        *ppuVar3 = puVar1;
      }
      iVar2 = _stricmp(*ppuVar3,"COST");
      if (iVar2 == 0) {
        puVar1 = (undefined *)GetSorResStringEx(0x7b5);
        *ppuVar3 = puVar1;
      }
      iVar2 = _stricmp(*ppuVar3,"ECONOMIC");
      if (iVar2 == 0) {
        puVar1 = (undefined *)GetSorResStringEx(0x7b6);
        *ppuVar3 = puVar1;
      }
      iVar2 = _stricmp(*ppuVar3,"SENSITIVITY");
      if (iVar2 == 0) {
        puVar1 = (undefined *)GetSorResStringEx(0x7b7);
        *ppuVar3 = puVar1;
      }
      iVar2 = _stricmp(*ppuVar3,"TRANSFER");
      if (iVar2 == 0) {
        puVar1 = (undefined *)GetSorResStringEx(0x7b8);
        *ppuVar3 = puVar1;
      }
      iVar2 = _stricmp(*ppuVar3,"CALCULATOR");
      if (iVar2 == 0) {
        puVar1 = (undefined *)GetSorResStringEx(0x7b9);
        *ppuVar3 = puVar1;
      }
      iVar2 = _stricmp(*ppuVar3,"UTILITY");
      if (iVar2 == 0) {
        puVar1 = (undefined *)GetSorResStringEx(0x7ba);
        *ppuVar3 = puVar1;
      }
      iVar2 = _stricmp(*ppuVar3,"CASE-STUDY");
      if (iVar2 == 0) {
        puVar1 = (undefined *)GetSorResStringEx(0x7bb);
        *ppuVar3 = puVar1;
      }
      iVar2 = _stricmp(*ppuVar3,"BALANCE");
      if (iVar2 == 0) {
        puVar1 = (undefined *)GetSorResStringEx(0x7bc);
        *ppuVar3 = puVar1;
      }
      iVar2 = _stricmp(*ppuVar3,"PRES-RELIEF");
      if (iVar2 == 0) {
        puVar1 = (undefined *)GetSorResStringEx(0x7bd);
        *ppuVar3 = puVar1;
      }
      iVar2 = _stricmp(*ppuVar3,"REGRESSION");
      if (iVar2 == 0) {
        puVar1 = (undefined *)GetSorResStringEx(0x7be);
        *ppuVar3 = puVar1;
      }
      iVar2 = _stricmp(*ppuVar3,"MEASUREMENT");
      if (iVar2 == 0) {
        puVar1 = (undefined *)GetSorResStringEx(0x7bf);
        *ppuVar3 = puVar1;
      }
      iVar2 = _stricmp(*ppuVar3,"EO-CONVERGENCE");
      if (iVar2 == 0) {
        puVar1 = (undefined *)GetSorResStringEx(0x7c0);
        *ppuVar3 = puVar1;
      }
      iVar2 = _stricmp(*ppuVar3,"BA-CONVERGENCE");
      if (iVar2 == 0) {
        puVar1 = (undefined *)GetSorResStringEx(0x82b);
        *ppuVar3 = puVar1;
      }
      uVar4 = uVar4 + 1;
      ppuVar3 = ppuVar3 + 1;
    } while (uVar4 < 0x11);
  }
  return;
}

/* RVA 0x22df0 */
longlong FUN_180022df0(longlong param_1,uint *param_2)

{
  longlong lVar1;
  char cVar2;
  uint uVar3;
  ulonglong uVar4;
  
  uVar3 = *param_2;
  uVar4 = (ulonglong)(int)uVar3;
  lVar1 = param_1 + uVar4;
  cVar2 = *(char *)(param_1 + uVar4);
  while (cVar2 != '\0') {
    uVar3 = (int)uVar4 + 1;
    uVar4 = (ulonglong)uVar3;
    *param_2 = uVar3;
    cVar2 = *(char *)((int)uVar3 + param_1);
  }
  *param_2 = uVar3 + 1;
  return lVar1;
}

/* RVA 0x22e30 */
void FUN_180022e30(longlong param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined8 uVar4;
  undefined1 local_res10 [8];
  undefined1 local_res18 [8];
  char *local_res20;
  undefined1 local_18 [8];
  undefined1 local_10 [8];
  
  pcVar3 = (char *)SB1sthvr();
  cVar1 = *pcVar3;
  do {
    if (cVar1 == '\0') {
      return;
    }
    SBinqhvr(pcVar3,&local_res20,local_10,local_res18,local_res10,local_18);
    iVar2 = _stricmp(local_res20,"NODENAME");
    if (iVar2 == 0) {
      uVar4 = *(undefined8 *)(param_1 + 8);
LAB_180022ed2:
      SBsethvr(local_res20,uVar4);
    }
    else {
      iVar2 = _stricmp(local_res20,"LOGONNAME");
      if (iVar2 == 0) {
        uVar4 = *(undefined8 *)(param_1 + 0x10);
        goto LAB_180022ed2;
      }
      iVar2 = _stricmp(local_res20,"PASSWORD");
      if (iVar2 == 0) {
        uVar4 = *(undefined8 *)(param_1 + 0x18);
        goto LAB_180022ed2;
      }
    }
    pcVar3 = (char *)SBnxthvr(pcVar3);
    cVar1 = *pcVar3;
  } while( true );
}

/* RVA 0x22f00 */
ulonglong FUN_180022f00(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  uint uVar4;
  
  iVar1 = GRinqiap();
  if (iVar1 != 0) {
    DAT_180050de4 = 0;
    uVar3 = FUN_180023a50();
    DAT_180050de4 = 1;
    return uVar3;
  }
  uVar2 = FUN_18000f470(param_1,param_2,param_3,param_4);
  uVar4 = 2;
  if ((int)uVar2 != 1) {
    uVar4 = 0xffffffff;
  }
  return (ulonglong)uVar4;
}

/* RVA 0x22f60 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180022f60(void)

{
  int iVar1;
  char *pcVar2;
  char *_OldFilename;
  undefined1 auStack_148 [32];
  undefined1 local_128 [272];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_148;
  iVar1 = MVGetProductCode();
  if (iVar1 == 1) {
    pcVar2 = (char *)GRemrbkp();
    remove(pcVar2);
    pcVar2 = "$backup.bkp";
  }
  else {
    pcVar2 = (char *)GRemrprp();
    remove(pcVar2);
    pcVar2 = "$backup.aprbkp";
  }
  remove(pcVar2);
  pcVar2 = (char *)GRemrbka();
  remove(pcVar2);
  remove("$backup.apmbd");
  iVar1 = LSbkpsrv("$backup",1);
  if (iVar1 != -1) {
    iVar1 = MVGetProductCode();
    if (iVar1 == 2) {
      pcVar2 = (char *)GRemrprp();
      _OldFilename = "$backup.aprbkp";
    }
    else {
      pcVar2 = (char *)GRemrbkp();
      _OldFilename = "$backup.bkp";
    }
    rename(_OldFilename,pcVar2);
    iVar1 = MDaccess("$backup.apmbd",0,local_128);
    if (iVar1 == 0) {
      pcVar2 = (char *)GRemrbka();
      rename("$backup.apmbd",pcVar2);
    }
  }
  return;
}

/* RVA 0x23060 */
void FUN_180023060(char *param_1,undefined4 *param_2)

{
  char cVar1;
  char *pcVar2;
  longlong lVar3;
  
  lVar3 = -1;
  pcVar2 = (char *)(*(longlong *)topfinfo_exref + 0x4c2);
  do {
    lVar3 = lVar3 + 1;
  } while (pcVar2[lVar3] != '\0');
  if (lVar3 == 0) {
    *param_1 = '\0';
    *param_2 = 0;
    return;
  }
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    *param_1 = cVar1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  *param_2 = *(undefined4 *)(*(longlong *)topfinfo_exref + 0x50c);
  return;
}

/* RVA 0x230d0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_1800230d0(char *param_1)

{
  char cVar1;
  longlong lVar2;
  int iVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  undefined1 auStack_368 [32];
  undefined8 local_348;
  char *local_338;
  undefined8 local_330;
  undefined8 local_328;
  undefined4 *local_220;
  undefined1 local_208 [8];
  undefined8 local_200;
  undefined1 local_1f8 [432];
  char local_48 [56];
  ulonglong local_10;
  
  local_10 = DAT_1800516d8 ^ (ulonglong)auStack_368;
  uVar5 = 0;
  lVar2 = -(longlong)param_1;
  do {
    cVar1 = *param_1;
    param_1[(longlong)(local_48 + lVar2)] = cVar1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  uVar4 = SimIsBlockInBatchHierarchy(local_48);
  if ((int)uVar4 == 1) {
    iVar3 = HYrslhie(local_48,&DAT_18003fa80,&local_200,local_208);
    if (iVar3 != 0) {
      uVar4 = HYGetFinfoCls(local_200);
      uVar4 = HYPshFinfo(uVar4);
      memset(&local_338,0,0x128);
      local_328 = *(undefined8 *)dataclass_exref;
      local_330 = MDfndkey(*(undefined8 *)iwpfile_exref,local_328,1,"BATCH-OPTS");
      if (*(longlong *)MDerror_exref == 0) {
        DRstovbg(&local_338,local_1f8,0);
        local_348 = 0;
        local_338 = "INTERACTIVE";
        MDfndvar("INTERACTIVE",1,0,&local_338);
        if (local_220 != (undefined4 *)0x0) {
          uVar5 = *local_220;
        }
        DRstovnd(&local_338,local_1f8);
        HYPopFinfo(uVar4);
        goto LAB_18002322f;
      }
      ERclear(0);
    }
    uVar5 = 0;
  }
LAB_18002322f:
  return uVar5;
}

/* RVA 0x23250 */
undefined8 SimIsBlockInBatchHierarchy(char *param_1)

{
  undefined8 uVar1;
  
  uVar1 = SimIsBlockInBatchHierarchy((char *)(*(longlong *)topfinfo_exref + 0x4c2));
  return uVar1;
}

/* RVA 0x23270 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 SBbndopt(undefined4 param_1)

{
  undefined1 auStack_278 [32];
  undefined4 *local_258;
  undefined4 local_248;
  undefined4 local_244 [3];
  undefined1 local_238 [4];
  undefined4 local_234;
  undefined4 local_230;
  undefined4 local_22c;
  undefined1 local_128 [12];
  undefined4 local_11c;
  ulonglong local_18;
  
                    /* 0x23270  187  SBbndopt */
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_278;
  local_244[0] = 1;
  local_248 = 0xffffffff;
  memset(local_238,0,0x110);
  local_258 = &local_248;
  local_230 = 0x31;
  local_234 = 1;
  local_22c = param_1;
  SEND_MESSAGE_WAIT(&DAT_1800521b4,local_244,local_238,local_128);
  return local_11c;
}

/* RVA 0x23310 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_180023310(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  char *pcVar5;
  uint uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  undefined1 auStackY_158 [32];
  char local_128 [8];
  int local_120;
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStackY_158;
  GRsetust();
  if (((byte)Sactions_exref[4] & 1) == 0) {
    FUN_180030240((char *)0x0,local_128,0,0x1f000000,(char *)0x0);
  }
  iVar1 = GRinqist();
  if (iVar1 == 0) {
    FUN_180028200("Problem specifications modified");
  }
  iVar2 = GRinqpri();
  iVar1 = *(int *)(hunks_exref + **(longlong **)iwpfile_exref * 0x108 + 0xf4);
  if ((*(uint *)Sactions_exref & 0x100000) != 0) {
    DAT_180050de4 = 0;
  }
  if (*(int *)sbcanned_exref == 0) {
    iVar3 = MDrenchk();
    if ((0 < iVar3) && (uVar4 = FUN_180023650(), (int)uVar4 < 0)) {
      return -1;
    }
    if ((iVar1 == 0) && (iVar2 != 0)) {
      pcVar5 = (char *)GetSorResStringEx(0x783);
      uVar9 = 0x3038100;
    }
    else {
      pcVar5 = (char *)GetSorResStringEx(0x783);
      uVar9 = 0x3030100;
    }
  }
  else {
    pcVar5 = (char *)GetSorResStringEx(0x783);
    uVar9 = 0x3040000;
  }
  uVar8 = (ulonglong)(uint)(iVar2 == 0);
  iVar1 = FUN_180030240(pcVar5,local_128,(uint)(iVar2 == 0),uVar9,(char *)0x0);
  if ((*(uint *)Sactions_exref & 0x100000) != 0) {
    DAT_180050de4 = 1;
  }
  if (iVar1 == 0) {
    return -1;
  }
  uVar7 = (ulonglong)(local_120 - 1U);
  if (local_120 - 1U != 0) {
    if ((local_120 == 2) || (local_120 == 3)) {
      uVar7 = 0;
      if (((*(uint *)Sactions_exref & 0x100000) != 0) || (iVar1 = GRinqpgc(), iVar1 != 0))
      goto LAB_1800234d2;
    }
    else {
      uVar6 = local_120 - 5;
      uVar7 = (ulonglong)uVar6;
      if (uVar6 == 0) {
        GRsetsmf();
        FUN_18002be40(0,uVar7,uVar8,uVar9);
        return local_120;
      }
      if (uVar6 != 0x11) {
        return -1;
      }
    }
  }
  GRsetsmf();
LAB_1800234d2:
  FUN_18002be40(0,uVar7,uVar8,uVar9);
  if (*(int *)partial_results_exref != 0) {
    GRsetcpt(1);
  }
  return local_120;
}

/* RVA 0x23500 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_180023500(void)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  undefined8 in_R9;
  undefined1 auStack_a8 [32];
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  char local_68 [80];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_a8;
  bVar1 = false;
  if (*(longlong *)(*(longlong *)finfo_exref + 0x1e0) != 0) {
    piVar3 = (int *)MDgetito(*(undefined8 *)iwpfile_exref,0xffffffffffffffff);
    iVar5 = 0;
    piVar4 = piVar3 + 2;
    if (0 < *piVar3) {
      do {
        if ((*(char *)((longlong)piVar4 + 1) == '\x01') && ((char)*piVar4 == '\x01')) {
          if (!bVar1) {
            in_R9 = 0x4a;
            local_88 = *(undefined8 *)(*(longlong *)finfo_exref + 0x698);
            local_80 = *(undefined8 *)(*(longlong *)finfo_exref + 0x690);
            local_78 = 0;
            uStack_70 = 0;
            HYdspnam(&local_88,&local_78,local_68);
            SBsetscp(local_68);
            bVar1 = true;
          }
          iVar2 = FUN_1800237f0((longlong)piVar4 + 2,piVar4 + 4,(longlong)piVar4 + 0x1e,in_R9);
          if (iVar2 < 0) {
            _DAT_1800521b8 = 0xffffffff;
            *(undefined4 *)HYloohie_break_exref = 1;
            return;
          }
        }
        iVar5 = iVar5 + 1;
        piVar4 = piVar4 + 0xb;
      } while (iVar5 < *piVar3);
    }
  }
  return;
}

/* RVA 0x23650 */
undefined8 FUN_180023650(void)

{
  undefined8 uVar1;
  
  uVar1 = HYPshFinfo(1);
  HYloodwn(FUN_180023500);
  HYPopFinfo(uVar1);
  return 0;
}

/* RVA 0x23680 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_180023680(void)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  char *pcVar5;
  ulonglong uVar6;
  undefined1 auStackY_158 [32];
  char local_128 [8];
  undefined4 local_120;
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStackY_158;
  uVar3 = HYPshFinfo(1);
  iVar1 = GRinqsmstrat();
  HYPopFinfo(uVar3);
  if (iVar1 == 0) {
    iVar2 = GRinqlaststrat();
    if ((iVar2 != 0) && (iVar2 = GRinqiap(), iVar2 != 0)) {
      SBmoveto(6,(char *)0x0);
    }
    uVar6 = 0x5020000;
  }
  else if (iVar1 == 1) {
    iVar2 = GRinqiap();
    if ((iVar2 != 0) && (lVar4 = GRinqnxt(), lVar4 == 0)) {
      SBmoveto(6,(char *)0x0);
    }
    uVar6 = 0x5030000;
  }
  else {
    uVar6 = 0x5000000;
    if (iVar1 == 2) {
      uVar6 = 0x5040000;
    }
  }
  GRsetlaststrat(iVar1);
  GRsetust(0);
  GRsetsms(1);
  pcVar5 = (char *)GetSorResStringEx(0x784);
  iVar1 = FUN_180030240(pcVar5,local_128,1,uVar6,(char *)0x0);
  iVar2 = GRinqust();
  if (iVar2 != 0) {
    pfs_refresh_status();
  }
  if (iVar1 == 0) {
switchD_180023792_caseD_5:
    return 0xffffffff;
  }
  switch(local_120) {
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
    goto switchD_180023792_caseD_5;
  default:
    return local_120;
  }
}

/* RVA 0x237f0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_1800237f0(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined1 auStack_288 [32];
  int *local_268;
  int local_258 [4];
  undefined1 local_248 [4];
  undefined4 local_244;
  undefined4 local_240;
  undefined4 local_23c;
  undefined1 local_238 [8];
  undefined1 local_230 [248];
  undefined1 local_138 [8];
  uint local_130;
  ulonglong local_28;
  
  local_28 = DAT_1800516d8 ^ (ulonglong)auStack_288;
  local_258[1] = 1;
  local_258[0] = -1;
  iVar1 = FUN_18002f8e0(param_1);
  if ((iVar1 == -1) && (iVar1 = GRinqcnn(), iVar1 == 2)) {
    memset(local_248,0,0x110);
    local_240 = 0x2c;
    local_244 = 1;
    local_23c = 0xffffffff;
    FUN_180008f80(local_238,&DAT_180041f38,param_2,param_4);
    FUN_180008f80(local_230,&DAT_180041f38,param_3,param_4);
    SyncDataShareOut();
    local_268 = local_258;
    SEND_MESSAGE_WAIT(&DAT_1800521b4,local_258 + 1,local_248,local_138);
    SyncDataShareIn();
    GRsetcnn(((int)local_130 < 0) + '\x02');
    iVar1 = (local_130 ^ (int)local_130 >> 0x1f) - ((int)local_130 >> 0x1f);
    if (local_258[0] == 0) {
      iVar1 = -1;
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

/* RVA 0x23910 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 SBrepall(void)

{
  int iVar1;
  char *pcVar2;
  undefined8 uVar3;
  undefined1 auStackY_158 [32];
  char local_128 [8];
  undefined4 local_120;
  ulonglong local_18;
  
                    /* 0x23910  183  SBrepall */
  local_18 = DAT_1800516d8 ^ (ulonglong)auStackY_158;
  pcVar2 = (char *)GetSorResStringEx(0x782);
  iVar1 = FUN_180030240(pcVar2,local_128,0,0x9030000,(char *)0x0);
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  switch(local_120) {
  case 1:
  case 5:
    iVar1 = GRinqust();
    if (iVar1 != 0) {
      uVar3 = 2;
      goto LAB_180023989;
    }
    break;
  case 2:
  case 3:
    uVar3 = 0;
LAB_180023989:
    GRsetust(uVar3);
    break;
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
    return 0xffffffff;
  default:
    goto switchD_180023979_caseD_9;
  }
  *(uint *)Sactions_exref = *(uint *)Sactions_exref | 0x8000;
  *(uint *)Sactions_exref = *(uint *)Sactions_exref | 0x80000000;
  GRsetrpt(1);
switchD_180023979_caseD_9:
  FUN_1800281c0("Refresh");
  return local_120;
}

/* RVA 0x23a50 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180023a50(void)

{
  int iVar1;
  char *pcVar2;
  undefined1 auStackY_158 [32];
  char local_128 [8];
  undefined4 local_120;
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStackY_158;
  iVar1 = GRinqust();
  if (iVar1 == 2) {
    GRsetust(1);
  }
  DAT_180050de4 = 0;
  pcVar2 = (char *)GetSorResStringEx(0x1d9);
  FUN_180008f30(pcVar2);
  FUN_1800282b0("->Generating report ...");
  iVar1 = FUN_180030240((char *)0x0,local_128,0,0x9020000,(char *)0x0);
  pfs_refresh_status();
  DAT_180050de4 = 1;
  if (iVar1 == 0) {
switchD_180023af2_caseD_4:
    pcVar2 = (char *)GetSorResStringEx(0x1da);
    FUN_180008f30(pcVar2);
    return 0xffffffff;
  }
  switch(local_120) {
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
    goto switchD_180023af2_caseD_4;
  default:
    pcVar2 = (char *)GetSorResStringEx(0x1db);
    FUN_180008f30(pcVar2);
    return 0;
  }
}

/* RVA 0x23b70 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 SBrepsum(void)

{
  int iVar1;
  char *pcVar2;
  undefined8 uVar3;
  undefined1 auStackY_158 [32];
  char local_128 [8];
  undefined4 local_120;
  ulonglong local_18;
  
                    /* 0x23b70  184  SBrepsum */
  local_18 = DAT_1800516d8 ^ (ulonglong)auStackY_158;
  pcVar2 = (char *)GetSorResStringEx(0x782);
  iVar1 = FUN_180030240(pcVar2,local_128,0,0x9010000,(char *)0x0);
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  switch(local_120) {
  case 1:
  case 5:
    iVar1 = GRinqust();
    if (iVar1 != 0) {
      uVar3 = 2;
      goto LAB_180023be5;
    }
    break;
  case 2:
  case 3:
    uVar3 = 0;
LAB_180023be5:
    GRsetust(uVar3);
    break;
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
    return 0xffffffff;
  default:
    goto switchD_180023bd5_caseD_9;
  }
  *(uint *)Sactions_exref = *(uint *)Sactions_exref | 0x8000;
  *(uint *)Sactions_exref = *(uint *)Sactions_exref | 0x80000000;
  GRsetrpt(1);
switchD_180023bd5_caseD_9:
  return local_120;
}

/* RVA 0x23ca0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_180023ca0(void)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  undefined1 auStackY_158 [32];
  char local_128 [272];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStackY_158;
  uVar1 = *(undefined4 *)partial_results_exref;
  *(undefined4 *)partial_results_exref = 0;
  pcVar3 = (char *)GetSorResStringEx(0x782);
  iVar2 = FUN_180030240(pcVar3,local_128,0,0x9010000,(char *)0x0);
  if (0 < iVar2) {
    FUN_18002c620((longlong)APtmpfil_exref);
    GRsetrpt(1);
  }
  *(undefined4 *)partial_results_exref = uVar1;
  iVar2 = FUN_180024de0();
  if (0 < iVar2) {
    *(undefined4 *)sum_header_exref = 1;
    FUN_18002c620((longlong)APtmpfil_exref);
    *(undefined4 *)sum_header_exref = 0;
  }
  return iVar2;
}

/* RVA 0x23d70 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_180023d70(void)

{
  bool bVar1;
  int iVar2;
  undefined7 extraout_var;
  char *pcVar3;
  ulonglong uVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined1 auStackY_158 [32];
  char local_128 [8];
  uint local_120;
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStackY_158;
  GRsetari(*(undefined8 *)topfinfo_exref);
  if (((*(int *)(*(longlong *)topfinfo_exref + 0x158) != 0) && (((byte)*Sactions_exref & 0x40) != 0)
      ) && (iVar2 = GRinqist(), iVar2 == 0)) {
    FUN_180028200("Problem specifications modified");
  }
  FUN_1800194c0(0);
  bVar1 = FUN_180025320();
  if (((int)CONCAT71(extraout_var,bVar1) == 0) &&
     (uVar5 = *(uint *)Sactions_exref >> 6 & 1, uVar5 != 0)) {
    pcVar3 = (char *)GetSorResStringEx(0x783);
  }
  else {
    FUN_180025320();
    uVar5 = *(uint *)Sactions_exref;
    pcVar3 = (char *)GetSorResStringEx(0x783);
    uVar5 = uVar5 >> 6 & 1;
  }
  uVar6 = 0x16010000;
  iVar2 = FUN_180030240(pcVar3,local_128,uVar5,0x16010000,(char *)0x0);
  if (iVar2 != 0) {
    FUN_18002fe10();
    GRsetsbm(1);
    FUN_18002be10();
    uVar4 = (ulonglong)local_120;
    switch(local_120) {
    case 1:
    case 2:
    case 3:
    case 5:
    case 0x11:
    case 0x16:
      if (((byte)*Sactions_exref & 0x40) != 0) {
        FUN_18002be40(0,uVar4,0x180000000,uVar6);
        uVar4 = (ulonglong)local_120;
      }
      return uVar4;
    case 6:
      GRsetsmf(1);
      GRsetsms(0);
    }
  }
  return 0xffffffff;
}

/* RVA 0x23ef0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_180023ef0(void)

{
  char cVar1;
  code cVar2;
  undefined8 uVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  undefined8 uVar7;
  char *pcVar8;
  longlong lVar9;
  undefined7 extraout_var;
  char *pcVar10;
  uint *puVar11;
  undefined7 extraout_var_00;
  code *pcVar12;
  int *piVar13;
  ulonglong uVar14;
  code *pcVar15;
  size_t _MaxCount;
  char *pcVar16;
  undefined1 *puVar17;
  undefined4 *in_R9;
  undefined1 auStack_4f8 [32];
  uint *local_4d8;
  char *local_4d0;
  uint local_4c8;
  int local_4c4 [3];
  undefined4 local_4b8;
  undefined4 local_4b4;
  char local_4a8 [8];
  uint local_4a0;
  int local_49c [2];
  char local_494;
  char local_398 [80];
  char local_348 [80];
  undefined1 local_2f8;
  undefined1 local_2c8 [4];
  undefined4 local_2c4;
  undefined4 local_2c0;
  undefined1 local_1b8 [80];
  char local_168 [80];
  char local_118 [256];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_4f8;
  local_4c4[0] = 0;
  local_4c4[1] = 1;
  iVar5 = GRinqcnn();
  if (1 < iVar5) {
    return 1;
  }
  GRsetust(0);
  pcVar16 = (char *)0x50;
  pcVar10 = local_348;
  FUN_18000f680(local_398,pcVar10,0x50);
  local_2f8 = 0;
  iVar5 = GRinqcnn();
  if (iVar5 == 0) {
    if ((*(int *)(*(longlong *)SBdataptr_exref + 0x146c) == 0) &&
       (uVar7 = FUN_18002a150(), (int)uVar7 == 0)) {
      GRsetsbs(4);
    }
    MVGetProductCode();
    uVar7 = GetSorResStringEx(0x785);
    FUN_180028200(uVar7);
    pcVar8 = (char *)GetSorResStringEx(0x786);
    FUN_180008f30(pcVar8);
    uVar7 = FUN_1800273d0(local_118);
    if ((int)uVar7 == 0) {
      return 0;
    }
    if (((*(int *)(*(longlong *)SBdataptr_exref + 0x1214) == 0) &&
        (*(char *)(*(longlong *)SBdataptr_exref + 0x1674) != '\0')) &&
       (iVar5 = FUN_1800325b0((undefined *)0x0,pcVar10,pcVar16,(undefined *)in_R9), iVar5 != 0)) {
      if ((*(uint *)Sactions_exref & 0x1000) == 0) {
        return 0;
      }
      FUN_180028530("Unable to generate definition file. Aborting command",-1);
      return 0;
    }
    _guard_check_icall();
    thunk_FUN_180008f30("");
    if (*(int *)debug_flag_exref != 0) {
      FUN_180008f80(local_168,"Starting handshaking between engine and GUI",pcVar16,in_R9);
      FUN_1800282b0(local_168);
    }
    in_R9 = &DAT_1800521b4;
    pcVar16 = local_4a8;
    local_4b8 = *(undefined4 *)(xprtdata_exref + 0x938);
    local_4b4 = *(undefined4 *)(xprtdata_exref + 0x90c);
    local_4d0 = local_398;
    local_4d8 = (uint *)(*(longlong *)SBdataptr_exref + 0x146c);
    START_ASPEN_PROCESS(local_118);
    _guard_check_icall();
    pfs_refresh_status();
    if (DAT_1800521b4 < 0) {
      local_4d0 = "cause: Insufficient disk space or memory.\n";
      local_4d8 = (uint *)0x180041dd8;
      FUN_180008f80(dbxbuf_exref,"%c%c%s%s",0x5e,0x58);
      EXyesno(dbxbuf_exref,2);
      DAT_1800521b4 = 0;
      FUN_180028530("",-1);
      GRsetiap(0);
      GRsetgpd(0);
      *(undefined4 *)(*(longlong *)topfinfo_exref + 0x438) = 0xffffffff;
      GRsetexc();
      SBsetnxt((char *)0x0,0);
      GRsetsme(2);
      return 0xffffffff;
    }
    if (DAT_1800521b4 == 0) {
      MMDisplayConnectError(DAT_180052d88);
      GRsetust(0);
      GRsetiap(0);
      GRsetsme(3);
      return 0xffffffffffffffff;
    }
  }
  GRsetsme(0);
  if (*(int *)debug_flag_exref != 0) {
    FUN_180008f80(local_168,"Successful handshaking between engine and GUI",pcVar16,in_R9);
    FUN_1800282b0(local_168);
  }
  iVar5 = GRinqcnn();
  if (iVar5 == 0) {
    GRsetcnn(1);
  }
  FUN_18002fe10();
  if (((byte)Sactions_exref[4] & 2) != 0) {
    return 1;
  }
  if (((byte)*Sactions_exref & 0x40) != 0) {
    DAT_1800521b0 = 1;
  }
  _guard_check_icall();
  _MaxCount = 0xffffffffffffffff;
  local_4c8 = 0xffffffff;
  memset(local_4a8,0,0x110);
  memset(local_2c8,0,0x110);
  local_2c0 = 0x22;
  local_2c4 = 1;
  SyncDataShareOut();
  local_4d8 = &local_4c8;
  pcVar10 = local_4a8;
  puVar17 = local_2c8;
  piVar13 = local_4c4 + 1;
  SEND_MESSAGE_WAIT(&DAT_1800521b4);
  SyncDataShareIn();
  iVar5 = GRinqssu();
  if (iVar5 != 0) {
    FUN_180031430();
  }
  _guard_check_icall();
  if ((int)local_4c8 < 1) {
    GRsetust(0);
    GRsetiap(0);
    GRsetsme();
    FUN_180021b60(0);
    GRsetgpd(0);
    lVar9 = *(longlong *)topfinfo_exref;
    *(undefined4 *)(lVar9 + 0x438) = 0xffffffff;
    FUN_18002a3a0(lVar9,piVar13,puVar17,pcVar10);
    GRnxtact();
    return (ulonglong)local_4c8;
  }
  GRsetcnn(((int)local_4a0 < 0) + '\x02');
  DAT_1800521b0 = 0;
  local_4a0 = (local_4a0 ^ (int)local_4a0 >> 0x1f) - ((int)local_4a0 >> 0x1f);
  FUN_180021b60(1);
  uVar14 = (ulonglong)local_4a0;
  uVar7 = 0x180000000;
  switch(local_4a0) {
  case 1:
    GRsetrpx(0);
    GRsetiap();
    if (((byte)*Sactions_exref & 0x40) != 0) {
      FUN_18002be40(0,uVar14,uVar7,pcVar10);
    }
    iVar5 = (int)local_494;
    local_494 = 0;
    FUN_18002f550(local_1b8,(longlong)local_49c);
    lVar9 = GRinqexc();
    if (lVar9 == 0) {
      pcVar12 = (code *)GetSorResStringEx(0x788);
      pcVar15 = dbxbuf_exref;
      do {
        cVar2 = *pcVar12;
        pcVar12 = pcVar12 + 1;
        *pcVar15 = cVar2;
        pcVar15 = pcVar15 + 1;
      } while (cVar2 != (code)0x0);
      pcVar12 = dbxbuf_exref + -1;
      do {
        pcVar15 = pcVar12 + 1;
        pcVar12 = pcVar12 + 1;
      } while (*pcVar15 != (code)0x0);
      lVar9 = 0;
      do {
        cVar2 = (code)local_1b8[lVar9];
        pcVar12[lVar9] = cVar2;
        lVar9 = lVar9 + 1;
      } while (cVar2 != (code)0x0);
    }
    else {
      pcVar10 = (char *)GRinqnxt();
      if (pcVar10 != (char *)0x0) {
        do {
          _MaxCount = _MaxCount + 1;
        } while (pcVar10[_MaxCount] != '\0');
        iVar6 = strncmp(pcVar10,local_1b8,_MaxCount);
        if (iVar6 == 0) {
          puVar11 = (uint *)GetSorResStringEx(0x78a);
          uVar7 = GetSorResStringEx(0x789);
          local_4d8 = puVar11;
          FUN_180008f80(dbxbuf_exref,"%s %s %s",uVar7,local_1b8);
          goto LAB_1800244d1;
        }
      }
      GRsetexc(0);
      *(uint *)Sactions_exref = *(uint *)Sactions_exref & 0xffefffff;
      pcVar12 = (code *)GetSorResStringEx(0x788);
      pcVar15 = dbxbuf_exref;
      do {
        cVar2 = *pcVar12;
        pcVar12 = pcVar12 + 1;
        *pcVar15 = cVar2;
        pcVar15 = pcVar15 + 1;
      } while (cVar2 != (code)0x0);
      pcVar12 = dbxbuf_exref + -1;
      do {
        pcVar15 = pcVar12 + 1;
        pcVar12 = pcVar12 + 1;
      } while (*pcVar15 != (code)0x0);
      lVar9 = 0;
      do {
        cVar2 = *(code *)((longlong)local_49c + lVar9);
        pcVar12[lVar9] = cVar2;
        lVar9 = lVar9 + 1;
      } while (cVar2 != (code)0x0);
    }
LAB_1800244d1:
    SBsetnxt(local_1b8,iVar5);
    goto LAB_1800244df;
  case 2:
    goto switchD_18002431e_caseD_2;
  case 3:
    if (local_49c[0] == 5) {
      local_49c[0] = 1;
    }
switchD_18002431e_caseD_2:
    GRsetrpx(0);
    GRsetrst(local_49c[0]);
    if (*(int *)(*(longlong *)topfinfo_exref + 0x380) != 1) {
      GRsetgpd(0);
      GRsetiap(2);
      *(undefined4 *)(*(longlong *)topfinfo_exref + 0x438) = 0xffffffff;
      GRsetexc();
      SBsetnxt((char *)0x0,0);
      GRsetsmf();
      GRsetsms();
      break;
    }
    GRsetiap();
    if (((byte)*Sactions_exref & 0x40) != 0) {
      FUN_18002be40(0,uVar14,uVar7,pcVar10);
    }
    lVar9 = GRinqexc();
    if ((lVar9 != 0) && (lVar9 = GRinqnxt(), lVar9 != 0)) {
      GRsetexc();
      *(uint *)Sactions_exref = *(uint *)Sactions_exref & 0xffefffff;
    }
    SBsetnxt((char *)0x0,0);
    lVar9 = GRinqexc();
    if (lVar9 == 0) {
      GRsetsmf(1);
      GRsetmtf(0);
      uVar3 = s_Table_Generation_completed_180041e68._8_8_;
      uVar7 = s_All_blocks_have_been_executed_180041e48._8_8_;
      pcVar12 = dbxbuf_exref;
      if (*(int *)sbcanned_exref == 0) {
        *(undefined8 *)dbxbuf_exref = s_All_blocks_have_been_executed_180041e48._0_8_;
        *(undefined8 *)(pcVar12 + 8) = uVar7;
        *(undefined8 *)(pcVar12 + 0x10) = s_All_blocks_have_been_executed_180041e48._16_8_;
        *(undefined4 *)(pcVar12 + 0x18) = s_All_blocks_have_been_executed_180041e48._24_4_;
        *(undefined2 *)(pcVar12 + 0x1c) = s_All_blocks_have_been_executed_180041e48._28_2_;
      }
      else {
        *(undefined8 *)dbxbuf_exref = s_Table_Generation_completed_180041e68._0_8_;
        *(undefined8 *)(pcVar12 + 8) = uVar3;
        *(undefined8 *)(pcVar12 + 0x10) = s_Table_Generation_completed_180041e68._16_8_;
        *(undefined2 *)(pcVar12 + 0x18) = s_Table_Generation_completed_180041e68._24_2_;
        pcVar12[0x1a] = (code)s_Table_Generation_completed_180041e68[0x1a];
      }
    }
    else {
      pcVar10 = (char *)GRinqexc();
      lVar9 = -(longlong)pcVar10;
      do {
        cVar1 = *pcVar10;
        pcVar10[(longlong)(local_1b8 + lVar9)] = cVar1;
        pcVar10 = pcVar10 + 1;
      } while (cVar1 != '\0');
      pcVar10 = strchr(local_1b8,0x20);
      if (pcVar10 != (char *)0x0) {
        *pcVar10 = '\0';
      }
      local_4d8 = (uint *)0x180041e88;
      FUN_180008f80(dbxbuf_exref,"%s %s %s","Block",local_1b8);
    }
    goto LAB_1800244df;
  case 4:
  case 8:
    GRsetiap(local_4a0 == 4);
    bVar4 = FUN_180025320();
    if ((int)CONCAT71(extraout_var,bVar4) != 0) {
      FUN_180028530("",-1);
    }
    GRseterr(2);
    GRsetgpd(0);
    *(undefined4 *)(*(longlong *)topfinfo_exref + 0x438) = 0xffffffff;
    GRsetedt();
    GRsetexc();
    SBsetnxt((char *)0x0,0);
    return 0xffffffff;
  case 5:
    GRsetrpx(0);
    GRsetiap();
    if (((byte)*Sactions_exref & 0x40) != 0) {
      FUN_18002be40(0,uVar14,uVar7,pcVar10);
    }
    iVar5 = (int)local_494;
    local_494 = 0;
    FUN_18002f550(local_1b8,(longlong)local_49c);
    pcVar10 = strchr(local_1b8,0x20);
    if (pcVar10 != (char *)0x0) {
      *pcVar10 = '\0';
    }
    puVar11 = (uint *)GetSorResStringEx(0x78a);
    uVar7 = GetSorResStringEx(0x789);
    local_4d8 = puVar11;
    FUN_180008f80(dbxbuf_exref,"%s %s %s",uVar7,local_1b8);
    hide_mouse();
    thunk_FUN_180008f30((char *)dbxbuf_exref);
    show_mouse();
    GRsetexc2(local_1b8,iVar5);
    pcVar10 = FUN_180019cb0(local_4c4);
    SBsetnxt(pcVar10,iVar5);
    FUN_180026490();
    if (local_4c4[0] == 0) {
      return 0xffffffff;
    }
    break;
  case 6:
    GRsetrpx(0);
    GRsetiap(0);
    GRsetgpd(0);
    *(undefined4 *)(*(longlong *)topfinfo_exref + 0x438) = 0xffffffff;
    GRsetexc();
    SBsetnxt((char *)0x0,0);
    GRsetsmf(1);
    GRsetsms(0);
    if (*(int *)prop_retrieve_results_exref != 0) {
      FUN_18002c620((longlong)APtmpfil_exref);
      return 0xffffffff;
    }
    OPpurout(*(undefined8 *)iwpfile_exref,0,1);
    FUN_18002c620((longlong)APtmpfil_exref);
    if (local_49c[0] == 0) {
      local_49c[0] = 1;
    }
    GRsetrst(local_49c[0]);
    return 0xffffffff;
  case 7:
    GRsetrpx(0);
    GRsetiap(0);
    if (DAT_180051e50 != 0) {
      hide_mouse();
      _guard_check_icall();
      thunk_FUN_180008f30("");
      show_mouse();
    }
    GRsetsms(0);
    GRsetsmf(0);
    GRsetgpd(0);
    *(undefined4 *)(*(longlong *)topfinfo_exref + 0x438) = 0xffffffff;
    GRsetedt();
    GRsetexc();
    SBsetnxt((char *)0x0,0);
    GRseterr(1);
    return 0xffffffff;
  default:
    GRsetrpx();
    break;
  case 10:
  case 0xb:
    GRsetiap(0);
    GRsetgpd(0);
    *(undefined4 *)(*(longlong *)topfinfo_exref + 0x438) = 0xffffffff;
    GRsetedt();
    GRsetexc();
    SBsetnxt((char *)0x0,0);
    GRsetust(0);
    GRsetist(1);
    return 0xffffffff;
  case 0xd:
    GRsetrpx(0);
    GRseterr(3);
    GRsetiap(0);
    GRsetgpd(0);
    *(undefined4 *)(*(longlong *)topfinfo_exref + 0x438) = 0xffffffff;
    GRsetedt();
    bVar4 = FUN_180025320();
    if ((int)CONCAT71(extraout_var_00,bVar4) != 0) {
      FUN_180028530("",-1);
    }
    GRsetexc();
    SBsetnxt((char *)0x0,0);
    return 0xffffffff;
  case 0xe:
    GRsetrpx(0);
    GRsetiap();
    GRsetexc();
    SBsetnxt((char *)0x0,0);
    if (DAT_180050de4 != 0) {
      GRseterr(6);
      return 0xffffffff;
    }
    break;
  case 0x10:
    GRsetrpx(0);
    GRsetiap(0);
    GRsetgpd(0);
    *(undefined4 *)(*(longlong *)topfinfo_exref + 0x438) = 0xffffffff;
    GRsetedt();
    GRsetexc();
    SBsetnxt((char *)0x0,0);
    if (DAT_180050de4 != 0) {
      GRseterr(4);
      return 0xffffffff;
    }
    if (*(int *)in_canned_exref != 0) {
      GRsetprp();
    }
    break;
  case 0x16:
    GRsetrpx(0);
    GRsetiap();
    if (((byte)*Sactions_exref & 0x40) != 0) {
      FUN_18002be40(0,uVar14,uVar7,pcVar10);
    }
    SBsetnxt((char *)0x0,0);
    pcVar12 = (code *)GetSorResStringEx(0x787);
    pcVar15 = dbxbuf_exref;
    do {
      cVar2 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      *pcVar15 = cVar2;
      pcVar15 = pcVar15 + 1;
    } while (cVar2 != (code)0x0);
LAB_1800244df:
    hide_mouse();
    thunk_FUN_180008f30((char *)dbxbuf_exref);
    show_mouse();
  }
  FUN_18002fe10();
  SimResetExcludedBlockList(0);
  return (ulonglong)local_4a0;
}

/* RVA 0x24b90 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_180024b90(void)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  char *pcVar4;
  longlong lVar5;
  ulonglong uVar6;
  undefined1 auStackY_3a8 [32];
  char local_378 [8];
  int local_370;
  char local_36c [260];
  char local_268 [16];
  char local_258 [64];
  undefined1 local_218 [512];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStackY_3a8;
  uVar3 = HYPshFinfo(1);
  iVar1 = GRinqsmstrat();
  HYPopFinfo(uVar3);
  if (iVar1 == 0) {
    uVar6 = 0xb020000;
    lVar5 = *(longlong *)topfinfo_exref;
    if ((*(char *)(lVar5 + 0x4c2) != ' ') || (*(char *)(lVar5 + 0x478) != ' ')) {
      FUN_180008f80(local_218,"next_block %s next_btype %d",(char *)(lVar5 + 0x4c2),
                    (ulonglong)*(uint *)(lVar5 + 0x50c));
    }
    pcVar4 = (char *)(*(longlong *)topfinfo_exref + 0x4c2);
    if (((*pcVar4 != ' ') &&
        (uVar2 = *(int *)(*(longlong *)topfinfo_exref + 0x50c) + 0x10, uVar2 < 0x21)) &&
       ((0x100028001U >> ((ulonglong)uVar2 & 0x3f) & 1) != 0)) {
      iVar1 = FUN_1800230d0(pcVar4);
      uVar6 = 0xb020000;
      if (iVar1 != 0) {
        uVar6 = 0x30000000;
      }
    }
    if ((*(char *)(*(longlong *)topfinfo_exref + 0x4c2) != ' ') &&
       (pcVar4 = strstr((char *)(*(longlong *)topfinfo_exref + 0x4c2),"$BASVR"),
       pcVar4 != (char *)0x0)) {
      uVar6 = 0x30000000;
    }
  }
  else if (iVar1 == 1) {
    uVar6 = 0xb030000;
    iVar1 = GRinqiap();
    if ((iVar1 != 0) && (lVar5 = GRinqnxt(), lVar5 == 0)) {
      SBmoveto(6,(char *)0x0);
    }
  }
  else {
    uVar6 = 0xb000000;
    if (iVar1 == 2) {
      uVar6 = 0xb040000;
    }
  }
  GRsetust(0);
  GRsetsms(1);
  pcVar4 = (char *)GetSorResStringEx(0x784);
  iVar1 = FUN_180030240(pcVar4,local_378,1,uVar6,(char *)0x0);
  if (local_370 == 1) {
    local_268[0] = '\0';
    local_268[1] = '\0';
    local_268[2] = '\0';
    local_268[3] = '\0';
    local_268[4] = '\0';
    local_268[5] = '\0';
    local_268[6] = '\0';
    local_268[7] = '\0';
    local_268[8] = 0;
    if (local_36c[0] != '\0') {
      strncpy(local_268,local_36c,8);
    }
    FUN_180008f80(local_258,"Ready to execute block %s",local_268,uVar6);
    FUN_1800281c0(local_258);
  }
  else {
    pfs_refresh_status();
  }
  if (iVar1 + 1U < 2) {
LAB_180024d85:
    local_370 = -1;
  }
  else {
    if ((local_370 != 1) && (local_370 != 2)) {
      if (local_370 == 3) {
        return 3;
      }
      if ((local_370 != 5) && (local_370 != 0x11)) goto LAB_180024d85;
    }
    iVar1 = GRinqrdy();
    if ((iVar1 - 2U & 0xfffffffb) == 0) {
      GRsetrdy(1);
    }
  }
  return local_370;
}

/* RVA 0x24de0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_180024de0(void)

{
  int iVar1;
  undefined1 auStackY_158 [32];
  char local_128 [8];
  undefined4 local_120;
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStackY_158;
  iVar1 = FUN_180030240((char *)0x0,local_128,0,0x19000000,(char *)0x0);
  if (iVar1 != 0) {
    switch(local_120) {
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
      *(uint *)Sactions_exref = *(uint *)Sactions_exref & 0xffff7fff;
      break;
    default:
      return local_120;
    }
  }
  return 0xffffffff;
}

/* RVA 0x24ec0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
FUN_180024ec0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  LSTATUS LVar1;
  undefined4 extraout_var;
  undefined1 auStackY_368 [32];
  DWORD local_338 [2];
  HKEY local_330;
  BYTE local_328;
  undefined1 local_327 [271];
  CHAR local_218 [512];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStackY_368;
  FUN_180008f80(local_218,"SOFTWARE\\Policies\\Microsoft\\Windows\\System",param_3,param_4);
  LVar1 = RegOpenKeyExA((HKEY)0xffffffff80000001,local_218,0,0x20019,&local_330);
  if (LVar1 == 0) {
    local_328 = '\0';
    memset(local_327,0,0x103);
    local_338[0] = 0x104;
    LVar1 = RegQueryValueExA(local_330,"DisableCMD",(LPDWORD)0x0,(LPDWORD)0x0,&local_328,local_338);
    if (LVar1 == 0) {
      return CONCAT71((int7)(CONCAT44(extraout_var,LVar1) >> 8),'\0' < (char)local_328);
    }
  }
  return 0;
}

/* RVA 0x24fa0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180024fa0(longlong param_1)

{
  char cVar1;
  longlong lVar2;
  char *pcVar3;
  longlong lVar4;
  ulonglong uVar5;
  int iVar6;
  int iVar7;
  ulonglong uVar8;
  undefined1 auStack_58 [32];
  char local_38 [32];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_58;
  iVar7 = 0;
  iVar6 = 0;
  uVar8 = 0xffffffffffffffff;
  do {
    uVar8 = uVar8 + 1;
  } while (*(char *)(param_1 + uVar8) != '\0');
  if (uVar8 != 0) {
    lVar4 = 0;
    do {
      if (*(char *)(lVar4 + param_1) == '$') {
        if (*(char *)(lVar4 + 1 + param_1) != '$') {
          lVar4 = -1;
          do {
            lVar4 = lVar4 + 1;
          } while (*(char *)(param_1 + lVar4) != '\0');
          if (lVar4 == 0) {
            return 0xffffffff;
          }
          uVar8 = 0;
          lVar4 = 0;
          do {
            if (0x1ff < uVar8) {
                    /* WARNING: Subroutine does not return */
              FUN_18003b6e4();
            }
            if (*(char *)(lVar4 + param_1) == '$') {
              cVar1 = *(char *)(lVar4 + 1 + param_1);
              if (cVar1 == '$') {
                iVar7 = iVar7 + 1;
                lVar4 = lVar4 + 1;
                uVar8 = uVar8 + 1;
              }
              else {
                if (cVar1 != '{') {
                  return 0xffffffff;
                }
                pcVar3 = (char *)((longlong)iVar7 + 2 + param_1);
                lVar2 = -(longlong)pcVar3;
                do {
                  cVar1 = *pcVar3;
                  pcVar3[(longlong)(local_38 + lVar2)] = cVar1;
                  pcVar3 = pcVar3 + 1;
                } while (cVar1 != '\0');
                pcVar3 = strchr(local_38,0x7d);
                *pcVar3 = '\0';
                iVar6 = _stricmp(local_38,"asptop");
                if ((iVar6 == 0) || (iVar6 = _stricmp(local_38,"aprsys"), iVar6 == 0)) {
                  return 0;
                }
              }
            }
            iVar7 = iVar7 + 1;
            uVar5 = 0xffffffffffffffff;
            lVar4 = lVar4 + 1;
            do {
              uVar5 = uVar5 + 1;
            } while (*(char *)(param_1 + uVar5) != '\0');
            if (uVar5 <= (ulonglong)(longlong)iVar7) {
              return 0xffffffff;
            }
          } while( true );
        }
        iVar6 = iVar6 + 1;
        lVar4 = lVar4 + 1;
      }
      iVar6 = iVar6 + 1;
      lVar4 = lVar4 + 1;
    } while ((ulonglong)(longlong)iVar6 < uVar8);
  }
  return 0xffffffff;
}

/* RVA 0x25120 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180025120(char *param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  FILE *_File;
  FILE *_File_00;
  size_t _Count;
  undefined1 auStack_438 [32];
  undefined1 local_418 [1024];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_438;
  pcVar4 = param_1;
  do {
    cVar1 = *pcVar4;
    cVar2 = pcVar4[(longlong)param_2 - (longlong)param_1];
    if (cVar1 != cVar2) break;
    pcVar4 = pcVar4 + 1;
  } while (cVar2 != '\0');
  if (((cVar1 != cVar2) && (iVar3 = _access(param_2,0), iVar3 == 0)) &&
     (_File = fopen(param_2,"rb"), _File != (FILE *)0x0)) {
    _File_00 = fopen(param_1,"ab");
    if (_File_00 != (FILE *)0x0) {
      iVar3 = feof(_File);
      while (iVar3 == 0) {
        _Count = fread(local_418,1,0x400,_File);
        if (_Count != 0) {
          fwrite(local_418,1,_Count,_File_00);
        }
        iVar3 = feof(_File);
      }
      fclose(_File);
      _File = _File_00;
    }
    fclose(_File);
  }
  return;
}

/* RVA 0x25240 */
void FUN_180025240(char *param_1,int param_2)

{
  char cVar1;
  char *pcVar2;
  
  if (param_2 == 0) {
    pcVar2 = (char *)(*(longlong *)SBdataptr_exref + 0x110);
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
    pcVar2 = (char *)(*(longlong *)SBdataptr_exref + 0x110);
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

/* RVA 0x252b0 */
undefined4 FUN_1800252b0(int param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  
  PTR__guard_check_icall_180044160[4] = 0;
  iVar1 = _guard_check_icall();
  if ((iVar1 != 0) && (param_1 == 0)) {
    FUN_180008f80(PTR__guard_check_icall_180044160 + 4,"Command failed, no %s file","RESULTS.MM",
                  param_4);
    *(undefined4 *)(PTR__guard_check_icall_180044160 + 0x408) = 1;
    *(undefined4 *)PTR__guard_check_icall_180044160 = 0xffffffff;
  }
  FUN_180028080();
  return *(undefined4 *)PTR__guard_check_icall_180044160;
}

/* RVA 0x25320 */
bool FUN_180025320(void)

{
  undefined8 uVar1;
  
  uVar1 = EXmsgbox();
  if ((int)uVar1 == 0) {
    return false;
  }
  return (int)uVar1 != 2;
}

/* RVA 0x25350 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_180025350(char *param_1,char *param_2)

{
  char cVar1;
  undefined4 *puVar2;
  undefined2 *puVar3;
  int iVar4;
  undefined8 *puVar5;
  undefined2 *puVar6;
  undefined8 *puVar7;
  undefined4 *puVar8;
  longlong lVar9;
  FILE *_File;
  char *pcVar10;
  char *pcVar11;
  undefined1 *puVar12;
  longlong lVar13;
  longlong lVar14;
  undefined1 *puVar15;
  undefined1 auStack_4e8 [32];
  char *local_4c8;
  undefined1 local_4c0 [7];
  undefined8 uStack_4b9;
  undefined8 uStack_3a9;
  char local_298 [128];
  undefined1 local_218 [208];
  char local_148 [272];
  ulonglong local_38;
  
  local_38 = DAT_1800516d8 ^ (ulonglong)auStack_4e8;
  if (*(int *)(*(longlong *)topfinfo_exref + 0x380) == 1) {
    lVar14 = (longlong)&uStack_3a9 + (1 - (longlong)param_1);
    pcVar10 = param_1;
    do {
      cVar1 = *pcVar10;
      pcVar10[lVar14] = cVar1;
      pcVar10 = pcVar10 + 1;
    } while (cVar1 != '\0');
    iVar4 = MVGetProductCode();
    if (iVar4 == 2) {
      puVar5 = &uStack_3a9;
      do {
        pcVar10 = (char *)((longlong)puVar5 + 1);
        puVar5 = (undefined8 *)((longlong)puVar5 + 1);
      } while (*pcVar10 != '\0');
      *puVar5 = _DAT_180040b78;
    }
    else {
      puVar5 = &uStack_3a9;
      do {
        puVar7 = puVar5;
        puVar5 = (undefined8 *)((longlong)puVar7 + 1);
      } while (*(char *)((longlong)puVar7 + 1) != '\0');
      *(undefined4 *)((longlong)puVar7 + 1) = DAT_180040b80;
      *(undefined2 *)((longlong)puVar7 + 5) = DAT_180040b84;
      *(undefined1 *)((longlong)puVar7 + 7) = DAT_180040b86;
    }
    name_lwr((uchar *)((longlong)&uStack_3a9 + 1));
    puVar15 = local_4c0 + (8 - (longlong)param_2);
    pcVar10 = param_2;
    do {
      cVar1 = *pcVar10;
      pcVar10[(longlong)puVar15] = cVar1;
      pcVar10 = pcVar10 + 1;
    } while (cVar1 != '\0');
    iVar4 = MVGetProductCode();
    if (iVar4 == 2) {
      puVar5 = (undefined8 *)(local_4c0 + 7);
      do {
        pcVar10 = (char *)((longlong)puVar5 + 1);
        puVar5 = (undefined8 *)((longlong)puVar5 + 1);
      } while (*pcVar10 != '\0');
      *puVar5 = _DAT_180040b78;
    }
    else {
      puVar2 = (undefined4 *)(local_4c0 + 7);
      do {
        puVar8 = puVar2;
        puVar2 = (undefined4 *)((longlong)puVar8 + 1);
      } while (*(char *)((longlong)puVar8 + 1) != '\0');
      *(undefined4 *)((longlong)puVar8 + 1) = DAT_180040b80;
      *(undefined2 *)((longlong)puVar8 + 5) = DAT_180040b84;
      *(undefined1 *)((longlong)puVar8 + 7) = DAT_180040b86;
    }
    name_lwr((uchar *)((longlong)&uStack_4b9 + 1));
    iVar4 = FUN_180026510((char *)open_path_exref,(char *)((longlong)&uStack_3a9 + 1));
    if (iVar4 == 0) {
      FUN_180025fb0((char *)0x0,(char *)((longlong)&uStack_4b9 + 1));
      FUN_180025b70((char *)open_path_exref,(char *)((longlong)&uStack_3a9 + 1),(char *)0x0,
                    (char *)((longlong)&uStack_4b9 + 1));
    }
    pcVar10 = param_1;
    do {
      cVar1 = *pcVar10;
      pcVar10[lVar14] = cVar1;
      pcVar10 = pcVar10 + 1;
    } while (cVar1 != '\0');
    pcVar10 = param_2;
    do {
      cVar1 = *pcVar10;
      pcVar10[(longlong)puVar15] = cVar1;
      pcVar10 = pcVar10 + 1;
    } while (cVar1 != '\0');
    if ((*(int *)(*(longlong *)SBdataptr_exref + 0x1218) == 0) ||
       (*(int *)(*(longlong *)SBdataptr_exref + 0x1218) == 1)) {
      puVar5 = &uStack_3a9;
      do {
        puVar7 = puVar5;
        puVar5 = (undefined8 *)((longlong)puVar7 + 1);
      } while (*(char *)((longlong)puVar7 + 1) != '\0');
      *(undefined4 *)((longlong)puVar7 + 1) = DAT_180041f40;
      *(undefined1 *)((longlong)puVar7 + 5) = DAT_180041f44;
      puVar2 = (undefined4 *)(local_4c0 + 7);
      do {
        puVar8 = puVar2;
        puVar2 = (undefined4 *)((longlong)puVar8 + 1);
      } while (*(char *)((longlong)puVar8 + 1) != '\0');
      *(undefined4 *)((longlong)puVar8 + 1) = DAT_180041f40;
      *(undefined1 *)((longlong)puVar8 + 5) = DAT_180041f44;
    }
    else {
      puVar5 = &uStack_3a9;
      do {
        puVar7 = puVar5;
        puVar5 = (undefined8 *)((longlong)puVar7 + 1);
      } while (*(char *)((longlong)puVar7 + 1) != '\0');
      *(undefined2 *)((longlong)puVar7 + 1) = DAT_180042434;
      *(undefined1 *)((longlong)puVar7 + 3) = DAT_180042436;
      puVar3 = (undefined2 *)(local_4c0 + 7);
      do {
        puVar6 = puVar3;
        puVar3 = (undefined2 *)((longlong)puVar6 + 1);
      } while (*(char *)((longlong)puVar6 + 1) != '\0');
      *(undefined2 *)((longlong)puVar6 + 1) = DAT_180042434;
      *(undefined1 *)((longlong)puVar6 + 3) = DAT_180042436;
    }
    name_lwr((uchar *)((longlong)&uStack_3a9 + 1));
    name_lwr((uchar *)((longlong)&uStack_4b9 + 1));
    FUN_180025fb0((char *)0x0,(char *)((longlong)&uStack_4b9 + 1));
    iVar4 = FUN_180026510((char *)open_path_exref,(char *)((longlong)&uStack_3a9 + 1));
    if (iVar4 == 0) {
      FUN_180025b70((char *)open_path_exref,(char *)((longlong)&uStack_3a9 + 1),(char *)0x0,
                    (char *)((longlong)&uStack_4b9 + 1));
    }
    pcVar10 = param_1;
    do {
      cVar1 = *pcVar10;
      pcVar10[lVar14] = cVar1;
      pcVar10 = pcVar10 + 1;
    } while (cVar1 != '\0');
    pcVar10 = param_2;
    do {
      cVar1 = *pcVar10;
      pcVar10[(longlong)puVar15] = cVar1;
      pcVar10 = pcVar10 + 1;
    } while (cVar1 != '\0');
    puVar5 = &uStack_3a9;
    if (*(int *)(*(longlong *)SBdataptr_exref + 0x1218) == 0) {
      do {
        puVar7 = puVar5;
        puVar5 = (undefined8 *)((longlong)puVar7 + 1);
      } while (*(char *)((longlong)puVar7 + 1) != '\0');
      *(undefined4 *)((longlong)puVar7 + 1) = DAT_180042438;
      *(undefined2 *)((longlong)puVar7 + 5) = DAT_18004243c;
      *(undefined1 *)((longlong)puVar7 + 7) = DAT_18004243e;
      puVar2 = (undefined4 *)(local_4c0 + 7);
      do {
        puVar8 = puVar2;
        puVar2 = (undefined4 *)((longlong)puVar8 + 1);
      } while (*(char *)((longlong)puVar8 + 1) != '\0');
      *(undefined4 *)((longlong)puVar8 + 1) = DAT_180042438;
      *(undefined2 *)((longlong)puVar8 + 5) = DAT_18004243c;
      *(undefined1 *)((longlong)puVar8 + 7) = DAT_18004243e;
    }
    else if (*(int *)(*(longlong *)SBdataptr_exref + 0x1218) == 1) {
      do {
        puVar7 = puVar5;
        puVar5 = (undefined8 *)((longlong)puVar7 + 1);
      } while (*(char *)((longlong)puVar7 + 1) != '\0');
      *(undefined4 *)((longlong)puVar7 + 1) = DAT_180041f48;
      *(undefined1 *)((longlong)puVar7 + 5) = DAT_180041f4c;
      puVar2 = (undefined4 *)(local_4c0 + 7);
      do {
        puVar8 = puVar2;
        puVar2 = (undefined4 *)((longlong)puVar8 + 1);
      } while (*(char *)((longlong)puVar8 + 1) != '\0');
      *(undefined4 *)((longlong)puVar8 + 1) = DAT_180041f48;
      *(undefined1 *)((longlong)puVar8 + 5) = DAT_180041f4c;
    }
    else {
      do {
        puVar7 = puVar5;
        puVar5 = (undefined8 *)((longlong)puVar7 + 1);
      } while (*(char *)((longlong)puVar7 + 1) != '\0');
      *(undefined4 *)((longlong)puVar7 + 1) = DAT_180042440;
      *(undefined1 *)((longlong)puVar7 + 5) = DAT_180042444;
      puVar2 = (undefined4 *)(local_4c0 + 7);
      do {
        puVar8 = puVar2;
        puVar2 = (undefined4 *)((longlong)puVar8 + 1);
      } while (*(char *)((longlong)puVar8 + 1) != '\0');
      *(undefined4 *)((longlong)puVar8 + 1) = DAT_180042440;
      *(undefined1 *)((longlong)puVar8 + 5) = DAT_180042444;
    }
    name_lwr((uchar *)((longlong)&uStack_3a9 + 1));
    name_lwr((uchar *)((longlong)&uStack_4b9 + 1));
    FUN_180025fb0((char *)0x0,(char *)((longlong)&uStack_4b9 + 1));
    iVar4 = FUN_180026510((char *)open_path_exref,(char *)((longlong)&uStack_3a9 + 1));
    if (iVar4 == 0) {
      FUN_180025b70((char *)open_path_exref,(char *)((longlong)&uStack_3a9 + 1),(char *)0x0,
                    (char *)((longlong)&uStack_4b9 + 1));
    }
    lVar9 = MDfndfil(1,"copy.ext",local_148);
    if ((lVar9 == 0) || (_File = fopen(local_148,"r"), _File == (FILE *)0x0)) {
      _local_4c0 = "No A+ files will be copied over.";
      local_4c8 = "The file \'copy.ext\' is not exist or cannot be opened. ";
      FUN_180008f80(local_218,"%c%c%s%s",0x5e,0x21);
      EXyesno(local_218,2,1);
    }
    else {
      pcVar10 = fgets(local_298,0x78,_File);
      if (pcVar10 != (char *)0x0) {
LAB_1800257b0:
        lVar9 = -1;
        do {
          lVar13 = lVar9;
          lVar9 = lVar13 + 1;
        } while (pcVar10[lVar9] != '\0');
        if (*pcVar10 != ';') {
          for (pcVar11 = pcVar10 + lVar13; (*pcVar11 == ' ' || (*pcVar11 == '\n'));
              pcVar11 = pcVar11 + -1) {
            *pcVar11 = '\0';
          }
          iVar4 = MVGetProductCode();
          if (iVar4 == 2) {
            pcVar11 = _strlwr(pcVar10);
            lVar9 = 0;
            do {
              lVar13 = lVar9 + 1;
              if ((&DAT_180040b78)[lVar9] != pcVar11[lVar9]) goto LAB_180025840;
              lVar9 = lVar13;
            } while (lVar13 != 8);
          }
          else {
            pcVar11 = _strlwr(pcVar10);
            lVar9 = 0;
            do {
              lVar13 = lVar9 + 1;
              if (*(char *)((longlong)&DAT_180040b80 + lVar9) != pcVar11[lVar9]) goto LAB_180025840;
              lVar9 = lVar13;
            } while (lVar13 != 7);
          }
        }
        goto LAB_180025911;
      }
LAB_18002593a:
      fclose(_File);
    }
  }
  return;
LAB_180025840:
  pcVar11 = param_1;
  do {
    cVar1 = *pcVar11;
    pcVar11[lVar14] = cVar1;
    pcVar11 = pcVar11 + 1;
  } while (cVar1 != '\0');
  puVar5 = &uStack_3a9;
  do {
    pcVar11 = (char *)((longlong)puVar5 + 1);
    puVar5 = (undefined8 *)((longlong)puVar5 + 1);
  } while (*pcVar11 != '\0');
  lVar9 = 0;
  do {
    cVar1 = pcVar10[lVar9];
    *(char *)((longlong)puVar5 + lVar9) = cVar1;
    lVar9 = lVar9 + 1;
  } while (cVar1 != '\0');
  name_lwr((uchar *)((longlong)&uStack_3a9 + 1));
  pcVar11 = param_2;
  do {
    cVar1 = *pcVar11;
    pcVar11[(longlong)puVar15] = cVar1;
    pcVar11 = pcVar11 + 1;
  } while (cVar1 != '\0');
  puVar12 = local_4c0 + 7;
  do {
    pcVar11 = puVar12 + 1;
    puVar12 = puVar12 + 1;
  } while (*pcVar11 != '\0');
  lVar9 = 0;
  do {
    cVar1 = pcVar10[lVar9];
    puVar12[lVar9] = cVar1;
    lVar9 = lVar9 + 1;
  } while (cVar1 != '\0');
  name_lwr((uchar *)((longlong)&uStack_4b9 + 1));
  iVar4 = FUN_180026510((char *)open_path_exref,(char *)((longlong)&uStack_3a9 + 1));
  if (iVar4 == 0) {
    FUN_180025fb0((char *)0x0,(char *)((longlong)&uStack_4b9 + 1));
    FUN_180025b70((char *)open_path_exref,(char *)((longlong)&uStack_3a9 + 1),(char *)0x0,
                  (char *)((longlong)&uStack_4b9 + 1));
  }
LAB_180025911:
  pcVar10 = fgets(local_298,0x78,_File);
  if (pcVar10 == (char *)0x0) goto LAB_18002593a;
  goto LAB_1800257b0;
}

/* RVA 0x259d0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool FUN_1800259d0(char *param_1,char *param_2,char *param_3,char *param_4)

{
  char cVar1;
  uchar uVar2;
  uchar uVar3;
  longlong lVar4;
  bool bVar5;
  int iVar6;
  uchar *puVar7;
  undefined1 auStack_388 [32];
  uchar local_368 [272];
  uchar local_258 [272];
  char local_148 [272];
  ulonglong local_38;
  
  local_38 = DAT_1800516d8 ^ (ulonglong)auStack_388;
  if ((param_1 == (char *)0x0) && (param_2 == (char *)0x0)) {
    return false;
  }
  if ((param_3 == (char *)0x0) && (param_4 == (char *)0x0)) {
    return false;
  }
  _getcwd(local_148,0x104);
  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {
LAB_180025a77:
    FUN_180026740(local_148,param_2,local_368,1);
  }
  else if (param_2 == (char *)0x0) {
    lVar4 = -(longlong)param_1;
    do {
      cVar1 = *param_1;
      param_1[(longlong)(local_368 + lVar4)] = cVar1;
      param_1 = param_1 + 1;
    } while (cVar1 != '\0');
  }
  else {
    FUN_180026740(param_1,param_2,local_368,1);
    iVar6 = _access((char *)local_368,0);
    if (iVar6 != 0) goto LAB_180025a77;
  }
  name_lwr(local_368);
  if ((param_3 == (char *)0x0) || (*param_3 == '\0')) {
    param_3 = local_148;
  }
  else if (param_4 == (char *)0x0) {
    lVar4 = -(longlong)param_3;
    do {
      cVar1 = *param_3;
      param_3[(longlong)(local_258 + lVar4)] = cVar1;
      param_3 = param_3 + 1;
    } while (cVar1 != '\0');
    goto LAB_180025af3;
  }
  FUN_180026740(param_3,param_4,local_258,1);
LAB_180025af3:
  name_lwr(local_258);
  puVar7 = local_368;
  lVar4 = -(longlong)puVar7;
  do {
    uVar2 = *puVar7;
    uVar3 = puVar7[(longlong)(local_258 + lVar4)];
    if (uVar2 != uVar3) break;
    puVar7 = puVar7 + 1;
  } while (uVar3 != '\0');
  if ((uVar2 == uVar3) || (iVar6 = _access((char *)local_368,0), iVar6 != 0)) {
    return false;
  }
  bVar5 = FUN_180006b60((LPCSTR)local_368,(LPCSTR)local_258);
  return bVar5;
}

/* RVA 0x25b70 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool FUN_180025b70(char *param_1,char *param_2,char *param_3,char *param_4)

{
  bool bVar1;
  int iVar2;
  undefined1 auStackY_ec8 [32];
  int local_e98 [4];
  char local_e88 [272];
  char local_d78 [272];
  char local_c68 [1040];
  char local_858 [1040];
  char local_448 [1040];
  ulonglong local_38;
  
  local_38 = DAT_1800516d8 ^ (ulonglong)auStackY_ec8;
  local_e98[0] = -1;
  if ((*(uint *)(xprtdata_exref + 0x930) >> 0x1c & 1) == 0) {
    iVar2 = *(int *)(*(longlong *)SBdataptr_exref + 0x1214);
    if (iVar2 == 0) {
LAB_180025dd2:
      bVar1 = FUN_1800259d0(param_1,param_2,param_3,param_4);
      return bVar1;
    }
    if (((iVar2 == 1) || (iVar2 == 2)) || (iVar2 == 3)) {
      CUsethvr("_SFILE",param_2,lvars_exref,0x400);
      CUsethvr("_DFILE",param_4,lvars_exref,0x400);
      CUsubhvr(lvars_exref,local_c68,*(longlong *)SBdataptr_exref + 0x1114,0);
      CUusthvr("_SFILE",lvars_exref,0x400);
      CUusthvr("_DFILE",lvars_exref,0x400);
      sscanf(local_c68,"%s %s %s",local_448,local_d78,local_e88);
      iVar2 = FUN_180035230(local_448,param_2,param_4,local_858,local_e98);
      if ((iVar2 != 0) || (local_e98[0] == -1)) goto LAB_180025dd2;
    }
  }
  else {
    *(uint *)(xprtdata_exref + 0x930) = *(uint *)(xprtdata_exref + 0x930) & 0xefffffff;
    CUsethvr("_SFILE",param_2,lvars_exref,0x400);
    CUsethvr("_DFILE",param_4,lvars_exref,0x400);
    CUsubhvr(lvars_exref,local_c68,*(longlong *)SBdataptr_exref + 0x1114,0);
    CUusthvr("_SFILE",lvars_exref,0x400);
    CUusthvr("_DFILE",lvars_exref,0x400);
    FUN_180028100(local_c68,0);
    iVar2 = FUN_1800270a0(1);
    if (iVar2 != 0x42) {
      FUN_180008f80(local_858,"Could not copy %s to %s",param_2,param_4);
      FUN_180028530(local_858,-1);
    }
    *(uint *)(xprtdata_exref + 0x930) = *(uint *)(xprtdata_exref + 0x930) | 0x10000000;
  }
  return true;
}

/* RVA 0x25e00 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180025e00(char *param_1,uint param_2,undefined8 param_3,char *param_4)

{
  int iVar1;
  char *pcVar2;
  undefined8 uVar3;
  undefined1 *puVar4;
  char *pcVar5;
  undefined1 auStack_378 [32];
  char *local_358;
  undefined4 local_348 [4];
  undefined1 local_338 [272];
  char local_228 [272];
  undefined1 local_118 [256];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_378;
  local_348[0] = 0xffffffff;
  if (*(int *)g_nogetridof_exref != 0) {
    return;
  }
  iVar1 = *(int *)(*(longlong *)SBdataptr_exref + 0x1214);
  if (iVar1 != 0) {
    if (((iVar1 == 1) || (iVar1 == 2)) || (iVar1 == 3)) {
      FUN_180035520(param_1,local_118,local_348,(ulonglong)param_2);
      return;
    }
    return;
  }
  iVar1 = *(int *)(*(longlong *)SBdataptr_exref + 0x1218);
  pcVar5 = param_1;
  if (iVar1 == 0) {
    pcVar2 = getenv("ASP$TOP");
    if (pcVar2 == (char *)0x0) {
      return;
    }
    pcVar2 = "@asp$com:getridof %s /quiet";
    puVar4 = local_338;
    FUN_180008f80(puVar4,"@asp$com:getridof %s /quiet",param_1,param_4);
  }
  else if (iVar1 == 1) {
    iVar1 = FUN_1800269c0("getridof.exe",local_228);
    if ((iVar1 != 0) && (iVar1 = FUN_1800269c0("getridof.bat",local_228), iVar1 != 0))
    goto LAB_180025f70;
    local_358 = "";
    if (param_2 != 0) {
      local_358 = "/NOWAIT";
    }
    pcVar5 = local_228;
    puVar4 = local_338;
    pcVar2 = "%s %s /quiet %s";
    param_4 = param_1;
    FUN_180008f80(puVar4,"%s %s /quiet %s",pcVar5,param_1);
  }
  else {
    if (iVar1 != 2) {
      return;
    }
    pcVar2 = getenv("ASPDIR");
    if (pcVar2 == (char *)0x0) {
      return;
    }
    pcVar2 = "getridof %s /quiet";
    puVar4 = local_338;
    FUN_180008f80(puVar4,"getridof %s /quiet",param_1,param_4);
  }
  uVar3 = FUN_180024ec0(puVar4,pcVar2,pcVar5,param_4);
  if ((int)uVar3 == 0) {
    FUN_180028100(local_338,0x800);
    return;
  }
LAB_180025f70:
  FUN_1800279c0(param_1);
  return;
}

/* RVA 0x25fb0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180025fb0(char *param_1,char *param_2)

{
  char cVar1;
  longlong lVar2;
  int iVar3;
  undefined8 uVar4;
  undefined1 auStack_788 [32];
  undefined4 local_768 [4];
  char local_758 [272];
  char local_648 [272];
  char local_538 [1040];
  char local_128 [272];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_788;
  local_768[0] = 0xffffffff;
  if ((*(uint *)(xprtdata_exref + 0x940) & 0x10000000) == 0) {
    iVar3 = *(int *)(*(longlong *)SBdataptr_exref + 0x1214);
    if (iVar3 == 0) {
      if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {
        lVar2 = -(longlong)param_2;
        do {
          cVar1 = *param_2;
          param_2[(longlong)(local_538 + lVar2)] = cVar1;
          param_2 = param_2 + 1;
        } while (cVar1 != '\0');
      }
      else {
        FUN_180026740(param_1,param_2,local_538,1);
      }
      remove(local_538);
    }
    else if (((iVar3 == 1) || (iVar3 == 2)) || (iVar3 == 3)) {
      CUsethvr("_HFILE",param_2,lvars_exref,0x400);
      CUsubhvr(lvars_exref,local_538,*(longlong *)SBdataptr_exref + 0x1014,0);
      CUusthvr("_HFILE",lvars_exref,0x400);
      sscanf(local_538,"%s %s",local_648,local_128);
      FUN_180035180(local_648,param_2,local_758,local_768);
    }
  }
  else {
    CUsethvr("_HFILE",param_2,lvars_exref);
    uVar4 = 0;
    CUsubhvr(lvars_exref,local_538,*(longlong *)SBdataptr_exref + 0x1014);
    CUusthvr("_HFILE",lvars_exref,0x400);
    FUN_180028100(local_538,0);
    iVar3 = FUN_1800270a0(1);
    if (iVar3 != 0x42) {
      FUN_180008f80(local_758,"Could not erase %s",param_2,uVar4);
      FUN_180028530(local_758,-1);
    }
  }
  return;
}

/* RVA 0x261d0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1800261d0(char *param_1)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  longlong lVar6;
  undefined1 *puVar7;
  char *pcVar8;
  undefined1 auStack_148 [31];
  undefined4 uStack_129;
  undefined1 local_124 [268];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_148;
  puVar7 = auStack_148 + (0x20 - (longlong)param_1);
  pcVar8 = param_1;
  do {
    cVar2 = *pcVar8;
    pcVar8[(longlong)puVar7] = cVar2;
    pcVar8 = pcVar8 + 1;
  } while (cVar2 != '\0');
  puVar5 = &uStack_129;
  do {
    puVar4 = puVar5;
    puVar5 = (undefined4 *)((longlong)puVar4 + 1);
  } while (*(char *)((longlong)puVar4 + 1) != '\0');
  *(undefined4 *)((longlong)puVar4 + 1) = DAT_180041718;
  *(undefined1 *)((longlong)puVar4 + 5) = DAT_18004171c;
  name_lwr((uchar *)((longlong)&uStack_129 + 1));
  remove((char *)((longlong)&uStack_129 + 1));
  pcVar8 = param_1;
  do {
    cVar2 = *pcVar8;
    pcVar8[(longlong)puVar7] = cVar2;
    pcVar8 = pcVar8 + 1;
  } while (cVar2 != '\0');
  puVar5 = &uStack_129;
  do {
    puVar4 = puVar5;
    puVar5 = (undefined4 *)((longlong)puVar4 + 1);
  } while (*(char *)((longlong)puVar4 + 1) != '\0');
  *(undefined4 *)((longlong)puVar4 + 1) = DAT_180041f50;
  *(undefined1 *)((longlong)puVar4 + 5) = DAT_180041f54;
  name_lwr((uchar *)((longlong)&uStack_129 + 1));
  remove((char *)((longlong)&uStack_129 + 1));
  pcVar8 = param_1;
  do {
    cVar2 = *pcVar8;
    pcVar8[(longlong)puVar7] = cVar2;
    pcVar8 = pcVar8 + 1;
  } while (cVar2 != '\0');
  puVar5 = &uStack_129;
  do {
    puVar4 = puVar5;
    puVar5 = (undefined4 *)((longlong)puVar4 + 1);
  } while (*(char *)((longlong)puVar4 + 1) != '\0');
  *(undefined4 *)((longlong)puVar4 + 1) = DAT_180042618;
  *(undefined1 *)((longlong)puVar4 + 5) = DAT_18004261c;
  name_lwr((uchar *)((longlong)&uStack_129 + 1));
  remove((char *)((longlong)&uStack_129 + 1));
  pcVar8 = param_1;
  do {
    cVar2 = *pcVar8;
    pcVar8[(longlong)puVar7] = cVar2;
    pcVar8 = pcVar8 + 1;
  } while (cVar2 != '\0');
  puVar5 = &uStack_129;
  do {
    puVar4 = puVar5;
    puVar5 = (undefined4 *)((longlong)puVar4 + 1);
  } while (*(char *)((longlong)puVar4 + 1) != '\0');
  *(undefined4 *)((longlong)puVar4 + 1) = DAT_180042620;
  *(undefined1 *)((longlong)puVar4 + 5) = DAT_180042624;
  name_lwr((uchar *)((longlong)&uStack_129 + 1));
  remove((char *)((longlong)&uStack_129 + 1));
  pcVar8 = param_1;
  do {
    cVar2 = *pcVar8;
    pcVar8[(longlong)puVar7] = cVar2;
    pcVar8 = pcVar8 + 1;
  } while (cVar2 != '\0');
  puVar5 = &uStack_129;
  do {
    puVar4 = puVar5;
    puVar5 = (undefined4 *)((longlong)puVar4 + 1);
  } while (*(char *)((longlong)puVar4 + 1) != '\0');
  *(undefined4 *)((longlong)puVar4 + 1) = DAT_180040a80;
  *(undefined1 *)((longlong)puVar4 + 5) = DAT_180040a84;
  name_lwr((uchar *)((longlong)&uStack_129 + 1));
  remove((char *)((longlong)&uStack_129 + 1));
  pcVar8 = param_1;
  do {
    cVar2 = *pcVar8;
    pcVar8[(longlong)puVar7] = cVar2;
    pcVar8 = pcVar8 + 1;
  } while (cVar2 != '\0');
  puVar5 = &uStack_129;
  do {
    puVar4 = puVar5;
    puVar5 = (undefined4 *)((longlong)puVar4 + 1);
  } while (*(char *)((longlong)puVar4 + 1) != '\0');
  *(undefined4 *)((longlong)puVar4 + 1) = DAT_180041f58;
  *(undefined1 *)((longlong)puVar4 + 5) = DAT_180041f5c;
  name_lwr((uchar *)((longlong)&uStack_129 + 1));
  remove((char *)((longlong)&uStack_129 + 1));
  do {
    cVar2 = *param_1;
    param_1[(longlong)puVar7] = cVar2;
    param_1 = param_1 + 1;
  } while (cVar2 != '\0');
  iVar3 = MVGetProductCode();
  pcVar8 = ".aprsum";
  if (iVar3 == 1) {
    pcVar8 = ".sum";
  }
  puVar5 = &uStack_129;
  do {
    pcVar1 = (char *)((longlong)puVar5 + 1);
    puVar5 = (undefined4 *)((longlong)puVar5 + 1);
  } while (*pcVar1 != '\0');
  lVar6 = 0;
  do {
    cVar2 = pcVar8[lVar6];
    *(char *)((longlong)puVar5 + lVar6) = cVar2;
    lVar6 = lVar6 + 1;
  } while (cVar2 != '\0');
  name_lwr((uchar *)((longlong)&uStack_129 + 1));
  remove((char *)((longlong)&uStack_129 + 1));
  iVar3 = MVGetProductCode();
  pcVar8 = "unnamed.aprsum";
  if (iVar3 != 2) {
    pcVar8 = "unnamed.sum";
  }
  remove(pcVar8);
  return;
}

