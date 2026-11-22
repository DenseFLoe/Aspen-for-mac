/* RVA 0x21870, FUN_180021870 */
int FUN_180021870(longlong param_1,longlong param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  char *pcVar5;
  longlong lVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar2 = 0;
  iVar7 = 0;
  if (param_3 < 0) {
LAB_1800219d6:
    return iVar7 + 1;
  }
  lVar6 = 0;
LAB_1800218a0:
  iVar8 = 0;
  iVar9 = 0;
  pcVar5 = (char *)(iVar2 + param_1);
  iVar3 = iVar2 + 1;
  if (*pcVar5 != DAT_180031786) {
    iVar3 = iVar2;
  }
  *(longlong *)(param_2 + lVar6 * 8) = iVar3 + param_1;
  cVar1 = *pcVar5;
  do {
    if (((cVar1 == ' ') || (cVar1 == '\t')) || (cVar1 == '\0')) break;
    if (cVar1 == DAT_180031786) {
      if (iVar8 == 0) {
        if (iVar9 == 0) {
          iVar8 = iVar2;
        }
      }
      else {
        if (iVar9 != 0) break;
        iVar9 = iVar2;
      }
    }
    cVar1 = pcVar5[1];
    pcVar5 = pcVar5 + 1;
    iVar2 = iVar2 + 1;
  } while( true );
  pcVar5 = (char *)(iVar2 + param_1);
  cVar1 = *pcVar5;
  if (cVar1 == '\0') {
    if ((iVar8 != 0) && (iVar9 != 0)) {
      *(undefined1 *)(iVar9 + param_1) = 0;
    }
    goto LAB_1800219d6;
  }
  if (iVar9 == 0) {
    if (iVar8 == 0) {
      iVar2 = iVar2 + 1;
      *pcVar5 = '\0';
      for (pcVar5 = (char *)(iVar2 + param_1); (*pcVar5 == ' ' || (*pcVar5 == '\t'));
          pcVar5 = pcVar5 + 1) {
        iVar2 = iVar2 + 1;
      }
    }
    else {
      while (cVar1 != DAT_180031786) {
        iVar2 = iVar2 + 1;
        pcVar5 = pcVar5 + 1;
        cVar1 = *pcVar5;
      }
      lVar4 = (longlong)iVar2;
      iVar2 = iVar2 + 1;
      *(undefined1 *)(lVar4 + param_1) = 0;
      for (pcVar5 = (char *)(iVar2 + param_1); (*pcVar5 == ' ' || (*pcVar5 == '\t'));
          pcVar5 = pcVar5 + 1) {
        iVar2 = iVar2 + 1;
      }
    }
  }
  else {
    *(undefined1 *)(iVar9 + param_1) = 0;
    iVar2 = iVar9 + 1;
    for (pcVar5 = (char *)(iVar2 + param_1); (*pcVar5 == ' ' || (*pcVar5 == '\t'));
        pcVar5 = pcVar5 + 1) {
      iVar2 = iVar2 + 1;
    }
  }
  if (*(char *)(iVar2 + param_1) == '\0') goto LAB_1800219d6;
  iVar7 = iVar7 + 1;
  lVar6 = lVar6 + 1;
  if (param_3 < lVar6) goto LAB_1800219d6;
  goto LAB_1800218a0;
}

/* RVA 0x219f0, FUN_1800219f0 */
longlong FUN_1800219f0(char *param_1)

{
  char cVar1;
  char cVar2;
  longlong *plVar3;
  int *piVar4;
  char *pcVar5;
  
  piVar4 = FUN_180021a60(1);
  plVar3 = *(longlong **)(piVar4 + 2);
  do {
    if (plVar3 == (longlong *)0x0) {
      return 0;
    }
    pcVar5 = param_1;
    do {
      cVar1 = *pcVar5;
      cVar2 = pcVar5[*plVar3 - (longlong)param_1];
      if (cVar1 != cVar2) break;
      pcVar5 = pcVar5 + 1;
    } while (cVar2 != '\0');
    if (cVar1 == cVar2) {
      return *plVar3;
    }
    plVar3 = (longlong *)plVar3[1];
  } while( true );
}

/* RVA 0x21a60, FUN_180021a60 */
int * FUN_180021a60(undefined4 param_1)

{
  void *_Memory;
  longlong lVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  switch(param_1) {
  case 1:
    piVar2 = DAT_180034178;
    if (DAT_180034178 == (int *)0x0) {
      DAT_180034178 = (int *)FUN_180023e70();
      return DAT_180034178;
    }
    break;
  case 2:
    piVar2 = DAT_180034180;
    if (DAT_180034180 == (int *)0x0) {
      DAT_180034180 = (int *)FUN_180023e70();
      return DAT_180034180;
    }
    break;
  case 3:
    piVar2 = DAT_180034188;
    if (DAT_180034188 == (int *)0x0) {
      DAT_180034188 = (int *)FUN_180023e70();
      return DAT_180034188;
    }
    break;
  case 4:
    piVar2 = DAT_180034190;
    if (DAT_180034190 == (int *)0x0) {
      DAT_180034190 = (int *)FUN_180023e70();
      return DAT_180034190;
    }
    break;
  case 5:
    piVar2 = DAT_180034198;
    if (DAT_180034198 == (int *)0x0) {
      DAT_180034198 = (int *)FUN_180023e70();
      return DAT_180034198;
    }
    break;
  case 6:
    piVar2 = DAT_1800341a0;
    if (DAT_1800341a0 == (int *)0x0) {
      DAT_1800341a0 = (int *)FUN_180023e70();
      return DAT_1800341a0;
    }
    break;
  case 7:
    piVar2 = DAT_1800341a8;
    if (DAT_1800341a8 == (int *)0x0) {
      DAT_1800341a8 = (int *)FUN_180023e70();
      return DAT_1800341a8;
    }
    break;
  case 8:
    piVar2 = DAT_1800341b0;
    if (DAT_1800341b0 == (int *)0x0) {
      DAT_1800341b0 = (int *)FUN_180023e70();
      return DAT_1800341b0;
    }
    break;
  case 9:
    piVar2 = DAT_1800341b8;
    if (DAT_1800341b8 == (int *)0x0) {
      DAT_1800341b8 = (int *)FUN_180023e70();
      return DAT_1800341b8;
    }
    break;
  case 10:
    piVar2 = DAT_1800341c0;
    if (DAT_1800341c0 == (int *)0x0) {
      DAT_1800341c0 = (int *)FUN_180023e70();
      return DAT_1800341c0;
    }
    break;
  case 0xb:
    piVar2 = DAT_1800341c8;
    if (DAT_1800341c8 == (int *)0x0) {
      DAT_1800341c8 = (int *)FUN_180023e70();
      return DAT_1800341c8;
    }
    break;
  case 0xffffffff:
    if (DAT_180034178 != (int *)0x0) {
      FUN_180023dc0(DAT_180034178);
      DAT_180034178 = (int *)0x0;
    }
    iVar3 = 1;
    if (DAT_180034180 != (int *)0x0) {
      iVar4 = 1;
      if (0 < *DAT_180034180) {
        do {
          _Memory = (void *)FUN_180023c70(DAT_180034180);
          if (0 < *(short *)((longlong)_Memory + 0x220)) {
            free(*(void **)((longlong)_Memory + 0x228));
          }
          if (0 < *(short *)((longlong)_Memory + 0x230)) {
            free(*(void **)((longlong)_Memory + 0x238));
          }
          free(_Memory);
          iVar4 = iVar4 + 1;
        } while (iVar4 <= *DAT_180034180);
      }
      free(DAT_180034180);
      DAT_180034180 = (int *)0x0;
    }
    if (DAT_180034188 != (int *)0x0) {
      FUN_180023dc0(DAT_180034188);
      DAT_180034188 = (int *)0x0;
    }
    if (DAT_180034190 != (int *)0x0) {
      FUN_180023dc0(DAT_180034190);
      DAT_180034190 = (int *)0x0;
    }
    if (DAT_180034198 != (int *)0x0) {
      iVar4 = 1;
      if (0 < *DAT_180034198) {
        do {
          lVar1 = FUN_180023c70(DAT_180034198);
          if (*(void **)(lVar1 + 0x18) != (void *)0x0) {
            free(*(void **)(lVar1 + 0x18));
          }
          if (*(void **)(lVar1 + 0x20) != (void *)0x0) {
            free(*(void **)(lVar1 + 0x20));
          }
          if (*(void **)(lVar1 + 0x28) != (void *)0x0) {
            free(*(void **)(lVar1 + 0x28));
          }
          if (*(void **)(lVar1 + 0x30) != (void *)0x0) {
            free(*(void **)(lVar1 + 0x30));
          }
          if (*(void **)(lVar1 + 0x38) != (void *)0x0) {
            free(*(void **)(lVar1 + 0x38));
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 <= *DAT_180034198);
      }
      free(DAT_180034198);
      DAT_180034198 = (int *)0x0;
    }
    if (DAT_1800341a0 != (int *)0x0) {
      iVar4 = 1;
      if (0 < *DAT_1800341a0) {
        do {
          lVar1 = FUN_180023c70(DAT_1800341a0);
          if (*(void **)(lVar1 + 0x38) != (void *)0x0) {
            free(*(void **)(lVar1 + 0x38));
          }
          if (*(void **)(lVar1 + 0x40) != (void *)0x0) {
            free(*(void **)(lVar1 + 0x40));
          }
          if (*(void **)(lVar1 + 0x48) != (void *)0x0) {
            free(*(void **)(lVar1 + 0x48));
          }
          if (*(void **)(lVar1 + 0x70) != (void *)0x0) {
            free(*(void **)(lVar1 + 0x70));
          }
          if (*(void **)(lVar1 + 0x78) != (void *)0x0) {
            free(*(void **)(lVar1 + 0x78));
          }
          if (*(void **)(lVar1 + 0x80) != (void *)0x0) {
            free(*(void **)(lVar1 + 0x80));
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 <= *DAT_1800341a0);
      }
      free(DAT_1800341a0);
      DAT_1800341a0 = (int *)0x0;
    }
    if (DAT_1800341a8 != (int *)0x0) {
      iVar4 = 1;
      if (0 < *DAT_1800341a8) {
        do {
          lVar1 = FUN_180023c70(DAT_1800341a8);
          if (*(void **)(lVar1 + 0x10) != (void *)0x0) {
            free(*(void **)(lVar1 + 0x10));
          }
          if (*(void **)(lVar1 + 0x20) != (void *)0x0) {
            free(*(void **)(lVar1 + 0x20));
          }
          if (*(void **)(lVar1 + 0x28) != (void *)0x0) {
            free(*(void **)(lVar1 + 0x28));
          }
          if (*(void **)(lVar1 + 0x30) != (void *)0x0) {
            free(*(void **)(lVar1 + 0x30));
          }
          if (*(void **)(lVar1 + 0x48) != (void *)0x0) {
            free(*(void **)(lVar1 + 0x48));
          }
          if (*(void **)(lVar1 + 0x50) != (void *)0x0) {
            free(*(void **)(lVar1 + 0x50));
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 <= *DAT_1800341a8);
      }
      free(DAT_1800341a8);
      DAT_1800341a8 = (int *)0x0;
    }
    if (DAT_1800341b0 != (int *)0x0) {
      iVar4 = 1;
      if (0 < *DAT_1800341b0) {
        do {
          lVar1 = FUN_180023c70(DAT_1800341b0);
          if (*(void **)(lVar1 + 0x20) != (void *)0x0) {
            free(*(void **)(lVar1 + 0x20));
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 <= *DAT_1800341b0);
      }
      free(DAT_1800341b0);
      DAT_1800341b0 = (int *)0x0;
    }
    if (DAT_1800341b8 != (int *)0x0) {
      iVar4 = 1;
      if (0 < *DAT_1800341b8) {
        do {
          lVar1 = FUN_180023c70(DAT_1800341b8);
          if (*(void **)(lVar1 + 0x10) != (void *)0x0) {
            free(*(void **)(lVar1 + 0x10));
          }
          if (*(void **)(lVar1 + 0x20) != (void *)0x0) {
            free(*(void **)(lVar1 + 0x20));
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 <= *DAT_1800341b8);
      }
      free(DAT_1800341b8);
      DAT_1800341b8 = (int *)0x0;
    }
    if (DAT_1800341c0 != (int *)0x0) {
      if (0 < *DAT_1800341c0) {
        do {
          lVar1 = FUN_180023c70(DAT_1800341c0);
          if (*(void **)(lVar1 + 0x10) != (void *)0x0) {
            free(*(void **)(lVar1 + 0x10));
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 <= *DAT_1800341c0);
      }
      free(DAT_1800341c0);
      DAT_1800341c0 = (int *)0x0;
    }
  default:
    piVar2 = (int *)0x0;
  }
  return piVar2;
}

/* RVA 0x21f90, FUN_180021f90 */
int FUN_180021f90(longlong param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  char *pcVar4;
  int iVar5;
  
  iVar5 = 0;
  if (*param_2 != '\0') {
    pcVar4 = param_2;
    do {
      iVar1 = toupper((int)pcVar4[param_1 - (longlong)param_2]);
      iVar2 = toupper((int)*pcVar4);
      if (iVar1 != iVar2) break;
      pcVar4 = pcVar4 + 1;
      iVar5 = iVar5 + 1;
    } while (*pcVar4 != '\0');
  }
  lVar3 = -1;
  do {
    lVar3 = lVar3 + 1;
  } while (param_2[lVar3] != '\0');
  return -(uint)(iVar5 != (int)lVar3);
}

/* RVA 0x22020, FUN_180022020 */
undefined8 FUN_180022020(longlong param_1,uint param_2,undefined8 param_3,undefined8 param_4)

{
  if (param_1 == 0) {
    FUN_1800220b0(0,"LINE %d - unable to allocate memory!",(ulonglong)param_2,param_4);
    return 0xffffffff;
  }
  return 0;
}

/* RVA 0x22050, FUN_180022050 */
void FUN_180022050(longlong param_1,char *param_2,int param_3,uint param_4)

{
  char cVar1;
  longlong lVar2;
  
  lVar2 = -1;
  do {
    lVar2 = lVar2 + 1;
  } while (param_2[lVar2] != '\0');
  if (param_3 <= (int)lVar2) {
    FUN_1800220b0(0,"LINE %d - String <%s> too long, max %i allowed",(ulonglong)param_4,param_2);
    return;
  }
  lVar2 = param_1 - (longlong)param_2;
  do {
    cVar1 = *param_2;
    param_2[lVar2] = cVar1;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  return;
}

/* RVA 0x220b0, FUN_1800220b0 */
void FUN_1800220b0(int param_1,undefined1 *param_2,undefined8 param_3,undefined8 param_4)

{
  FILE *_File;
  undefined8 *puVar1;
  char *pcVar2;
  undefined8 uVar3;
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res18 = param_3;
  local_res20 = param_4;
  if (DAT_180034170 == 0) {
    _File = fopen("IKERROR.LOG","w");
    DAT_180034170 = -1;
  }
  else {
    _File = fopen("IKERROR.LOG","a");
  }
  pcVar2 = "ERROR  : ";
  if (param_1 != 0) {
    pcVar2 = "WARNING: ";
  }
  FUN_180007f00(_File,pcVar2,param_3,param_4);
  puVar1 = (undefined8 *)FUN_180001770();
  uVar3 = 0;
  __stdio_common_vfprintf(*puVar1,_File,param_2,0,&local_res18);
  if (param_1 == 0) {
    param_2 = &DAT_1800349c0;
    FUN_180007f00(_File,"\n--->%s\n",&DAT_1800349c0,uVar3);
  }
  FUN_180007f00(_File,&DAT_180027258,param_2,uVar3);
  fclose(_File);
  return;
}

/* RVA 0x22180, FUN_180022180 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_180022180(char *param_1,uint param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  int iVar2;
  
  if (DAT_180032164 == -1) {
    DAT_180032164 = 0;
  }
  for (; (cVar1 = *param_1, cVar1 == ' ' || (cVar1 == '\t')); param_1 = param_1 + 1) {
  }
  if (cVar1 == '\0') {
    return DAT_180032164;
  }
  if (cVar1 == '\n') {
    return DAT_180032164;
  }
  iVar2 = FUN_180021f90((longlong)param_1,PTR_DAT_180031788);
  if (iVar2 == 0) {
    DAT_1800342ac = 0;
    if (DAT_1800342a8 == -1) {
      DAT_1800342a8 = 0;
      DAT_1800342ac = 0;
      return DAT_180032164;
    }
    iVar2 = FUN_180021f90((longlong)param_1,"COMP_DEF");
    if (((((iVar2 != 0) && (iVar2 = FUN_180021f90((longlong)param_1,"PURE-COMP-DA"), iVar2 != 0)) &&
         (iVar2 = FUN_180021f90((longlong)param_1,"MIXTURE-DATA"), iVar2 != 0)) &&
        ((iVar2 = FUN_180021f90((longlong)param_1,"GROUP-METHOD"), iVar2 != 0 &&
         (iVar2 = FUN_180021f90((longlong)param_1,"THERMODYNAMI"), iVar2 != 0)))) &&
       (iVar2 = FUN_180021f90((longlong)param_1,"SOURCE"), iVar2 != 0)) {
      return DAT_180032164;
    }
    if (DAT_180032168 == 0) {
      FUN_18001ddc0(param_1,2,(ulonglong)param_2,param_4);
    }
    if (DAT_180032168 == 1) {
      FUN_18001e1c0(param_1,2,param_2,param_4);
    }
    if (DAT_180032168 == 2) {
      FUN_18001e870(param_1,2,param_2);
    }
    if (DAT_180032168 == 3) {
      FUN_18001eb10(param_1,2,param_2);
    }
    if (DAT_180032168 == 4) {
      FUN_18001ed00(param_1,2,(ulonglong)param_2,param_4);
    }
    if (DAT_180032168 == 5) {
      FUN_18001f740(param_1,2,param_2,param_4);
    }
    if (DAT_180032168 == 6) {
      FUN_180020100(param_1,2,(ulonglong)param_2,param_4);
    }
    if (DAT_180032168 - 7U < 7) {
      FUN_180020c40(param_1,2,param_2);
    }
    if (DAT_180032168 - 0xeU < 3) {
      FUN_180020fa0(param_1,2,param_2);
    }
    if (DAT_180032168 - 0x11U < 3) {
      FUN_180020fa0(param_1,2,param_2);
      return DAT_180032164;
    }
    return DAT_180032164;
  }
  if (DAT_1800342a8 == -1) {
    return DAT_180032164;
  }
  if (DAT_1800342ac != 0) {
    if (DAT_180032168 == 0) {
      FUN_18001ddc0(param_1,3,(ulonglong)param_2,param_4);
    }
    if (DAT_180032168 == 1) {
      FUN_18001e1c0(param_1,3,param_2,param_4);
    }
    if (DAT_180032168 == 2) {
      FUN_18001e870(param_1,3,param_2);
    }
    if (DAT_180032168 == 3) {
      FUN_18001eb10(param_1,3,param_2);
    }
    if (DAT_180032168 == 4) {
      FUN_18001ed00(param_1,3,(ulonglong)param_2,param_4);
    }
    if (DAT_180032168 == 5) {
      FUN_18001f740(param_1,3,param_2,param_4);
    }
    if (DAT_180032168 == 6) {
      FUN_180020100(param_1,3,(ulonglong)param_2,param_4);
    }
    if (DAT_180032168 - 7U < 7) {
      FUN_180020c40(param_1,3,param_2);
    }
    if (DAT_180032168 - 0xeU < 3) {
      FUN_180020fa0(param_1,3,param_2);
    }
    if (DAT_180032168 - 0x11U < 3) {
      FUN_180020fa0(param_1,3,param_2);
      return DAT_180032164;
    }
    return DAT_180032164;
  }
  iVar2 = FUN_180021f90((longlong)param_1,"VERSION");
  if (iVar2 == 0) {
    FUN_1800231a0(param_1,1,param_2);
    return DAT_180032164;
  }
  iVar2 = FUN_180021f90((longlong)param_1,"SOURCE");
  if (iVar2 == 0) {
    return DAT_180032164;
  }
  iVar2 = FUN_180021f90((longlong)param_1,"KEY");
  if (iVar2 == 0) {
    FUN_18001ddc0(param_1,1,(ulonglong)param_2,param_4);
    DAT_180032168 = 0;
  }
  else {
    iVar2 = FUN_180021f90((longlong)param_1,"COMP-DEF");
    if (iVar2 == 0) {
      return DAT_180032164;
    }
    iVar2 = FUN_180021f90((longlong)param_1,"CID");
    if (iVar2 == 0) {
      FUN_18001e1c0(param_1,1,param_2,param_4);
      DAT_180032168 = 1;
    }
    else {
      iVar2 = FUN_180021f90((longlong)param_1,"PURE-COMP-DA");
      if (iVar2 == 0) {
        _DAT_180034370 = CONCAT14(s_PURE_COMP_DA_180029540[0xc],s_PURE_COMP_DA_180029540._8_4_);
        DAT_180034368 = s_PURE_COMP_DA_180029540[0];
        DAT_180034368_1 = s_PURE_COMP_DA_180029540[1];
        cRam000000018003436a = s_PURE_COMP_DA_180029540[2];
        cRam000000018003436b = s_PURE_COMP_DA_180029540[3];
        cRam000000018003436c = s_PURE_COMP_DA_180029540[4];
        cRam000000018003436d = s_PURE_COMP_DA_180029540[5];
        cRam000000018003436e = s_PURE_COMP_DA_180029540[6];
        cRam000000018003436f = s_PURE_COMP_DA_180029540[7];
        return DAT_180032164;
      }
      iVar2 = FUN_180021f90((longlong)param_1,"PROPERTIES");
      if (iVar2 == 0) {
        FUN_18001e870(param_1,1,param_2);
        DAT_180032168 = 2;
      }
      else {
        iVar2 = FUN_180021f90((longlong)param_1,"PARAMETERS");
        if (iVar2 == 0) {
          FUN_18001eb10(param_1,1,param_2);
          DAT_180032168 = 3;
        }
        else {
          iVar2 = FUN_180021f90((longlong)param_1,"TABLE");
          if ((iVar2 == 0) && (iVar2 = strcmp(&DAT_180034368,"PURE-COMP-DA"), iVar2 == 0)) {
            FUN_18001ed00(param_1,1,(ulonglong)param_2,param_4);
            DAT_180032168 = 4;
          }
          else {
            iVar2 = FUN_180021f90((longlong)param_1,"FUNCTION");
            if (iVar2 == 0) {
              FUN_18001f740(param_1,1,param_2,param_4);
              DAT_180032168 = 5;
            }
            else {
              iVar2 = FUN_180021f90((longlong)param_1,"MIXTURE-DATA");
              if (iVar2 == 0) {
                _DAT_180034370 =
                     CONCAT14(s_MIXTURE_DATA_180029550[0xc],s_MIXTURE_DATA_180029550._8_4_);
                DAT_180034368 = s_MIXTURE_DATA_180029550[0];
                DAT_180034368_1 = s_MIXTURE_DATA_180029550[1];
                cRam000000018003436a = s_MIXTURE_DATA_180029550[2];
                cRam000000018003436b = s_MIXTURE_DATA_180029550[3];
                cRam000000018003436c = s_MIXTURE_DATA_180029550[4];
                cRam000000018003436d = s_MIXTURE_DATA_180029550[5];
                cRam000000018003436e = s_MIXTURE_DATA_180029550[6];
                cRam000000018003436f = s_MIXTURE_DATA_180029550[7];
                return DAT_180032164;
              }
              iVar2 = FUN_180021f90((longlong)param_1,"TABLE");
              if ((iVar2 == 0) && (iVar2 = strcmp(&DAT_180034368,"MIXTURE-DATA"), iVar2 == 0)) {
                FUN_180020100(param_1,1,(ulonglong)param_2,param_4);
                DAT_180032168 = 6;
              }
              else {
                iVar2 = FUN_180021f90((longlong)param_1,"BINARY-PARAMETER");
                if (iVar2 == 0) {
                  DAT_180034368 = s_BINARY_PARAMETER_180029d80[0];
                  DAT_180034368_1 = s_BINARY_PARAMETER_180029d80[1];
                  cRam000000018003436a = s_BINARY_PARAMETER_180029d80[2];
                  cRam000000018003436b = s_BINARY_PARAMETER_180029d80[3];
                  cRam000000018003436c = s_BINARY_PARAMETER_180029d80[4];
                  cRam000000018003436d = s_BINARY_PARAMETER_180029d80[5];
                  cRam000000018003436e = s_BINARY_PARAMETER_180029d80[6];
                  cRam000000018003436f = s_BINARY_PARAMETER_180029d80[7];
                  DAT_180034370 = s_BINARY_PARAMETER_180029d80[8];
                  DAT_180034370_1 = s_BINARY_PARAMETER_180029d80[9];
                  cRam0000000180034372 = s_BINARY_PARAMETER_180029d80[10];
                  cRam0000000180034373 = s_BINARY_PARAMETER_180029d80[0xb];
                  DAT_180034374 = s_BINARY_PARAMETER_180029d80[0xc];
                  DAT_180034374_1._0_1_ = s_BINARY_PARAMETER_180029d80[0xd];
                  DAT_180034374_1._1_1_ = s_BINARY_PARAMETER_180029d80[0xe];
                  DAT_180034374_1._2_1_ = s_BINARY_PARAMETER_180029d80[0xf];
                  DAT_180034378 = s_BINARY_PARAMETER_180029d80[0x10];
                  return DAT_180032164;
                }
                iVar2 = FUN_180021f90((longlong)param_1,"NRTL");
                if ((iVar2 == 0) || (iVar2 = FUN_1800230f0(param_1,"METHOD","NRTL"), iVar2 == 0)) {
                  FUN_180020c40(param_1,1,param_2);
                  DAT_180032168 = 7;
                }
                else {
                  iVar2 = FUN_180021f90((longlong)param_1,"UNIQUAC");
                  if ((iVar2 == 0) ||
                     (iVar2 = FUN_1800230f0(param_1,"METHOD","UNIQUAC"), iVar2 == 0)) {
                    FUN_180020c40(param_1,1,param_2);
                    DAT_180032168 = 8;
                  }
                  else {
                    iVar2 = FUN_180021f90((longlong)param_1,"WILSON");
                    if ((iVar2 == 0) ||
                       (iVar2 = FUN_1800230f0(param_1,"METHOD","WILSON"), iVar2 == 0)) {
                      FUN_180020c40(param_1,1,param_2);
                      DAT_180032168 = 9;
                    }
                    else {
                      iVar2 = FUN_180021f90((longlong)param_1,"FLORY-HUGGIN");
                      if ((iVar2 == 0) ||
                         (iVar2 = FUN_1800230f0(param_1,"METHOD","FLORY-HUGGIN"), iVar2 == 0)) {
                        FUN_180020c40(param_1,1,param_2);
                        DAT_180032168 = 10;
                      }
                      else {
                        iVar2 = FUN_180021f90((longlong)param_1,"UNIFAC");
                        if (((iVar2 == 0) &&
                            (iVar2 = strcmp(&DAT_180034368,"BINARY-PARAMETER"), iVar2 == 0)) ||
                           ((iVar2 = FUN_1800230f0(param_1,"METHOD","UNIFAC"), iVar2 == 0 &&
                            (iVar2 = strcmp(&DAT_180034368,"BINARY-PARAMETER"), iVar2 == 0)))) {
                          FUN_180020c40(param_1,1,param_2);
                          DAT_180032168 = 0xb;
                        }
                        else {
                          iVar2 = FUN_180021f90((longlong)param_1,"D-UNIFAC");
                          if (((iVar2 == 0) &&
                              (iVar2 = strcmp(&DAT_180034368,"BINARY-PARAMETER"), iVar2 == 0)) ||
                             ((iVar2 = FUN_1800230f0(param_1,"METHOD","D-UNIFAC"), iVar2 == 0 &&
                              (iVar2 = strcmp(&DAT_180034368,"BINARY-PARAMETER"), iVar2 == 0)))) {
                            FUN_180020c40(param_1,1,param_2);
                            DAT_180032168 = 0xc;
                          }
                          else {
                            iVar2 = FUN_180021f90((longlong)param_1,"L-UNIFAC");
                            if (((iVar2 == 0) &&
                                (iVar2 = strcmp(&DAT_180034368,"BINARY-PARAMETER"), iVar2 == 0)) ||
                               ((iVar2 = FUN_1800230f0(param_1,"METHOD","L-UNIFAC"), iVar2 == 0 &&
                                (iVar2 = strcmp(&DAT_180034368,"BINARY-PARAMETER"), iVar2 == 0)))) {
                              FUN_180020c40(param_1,1,param_2);
                              DAT_180032168 = 0xd;
                            }
                            else {
                              iVar2 = FUN_180021f90((longlong)param_1,"GROUP-METHOD");
                              if (iVar2 == 0) {
                                return DAT_180032164;
                              }
                              iVar2 = FUN_180021f90((longlong)param_1,"G-PARAMETER");
                              if (iVar2 == 0) {
                                _DAT_180034370 =
                                     CONCAT44(_DAT_180034374,s_G_PARAMETER_180029508._8_4_);
                                DAT_180034368 = s_G_PARAMETER_180029508[0];
                                DAT_180034368_1 = s_G_PARAMETER_180029508[1];
                                cRam000000018003436a = s_G_PARAMETER_180029508[2];
                                cRam000000018003436b = s_G_PARAMETER_180029508[3];
                                cRam000000018003436c = s_G_PARAMETER_180029508[4];
                                cRam000000018003436d = s_G_PARAMETER_180029508[5];
                                cRam000000018003436e = s_G_PARAMETER_180029508[6];
                                cRam000000018003436f = s_G_PARAMETER_180029508[7];
                                return DAT_180032164;
                              }
                              iVar2 = FUN_180021f90((longlong)param_1,"UNIFAC");
                              if (((iVar2 == 0) &&
                                  (iVar2 = strcmp(&DAT_180034368,"G-PARAMETER"), iVar2 == 0)) ||
                                 ((iVar2 = FUN_1800230f0(param_1,"METHOD","UNIFAC"), iVar2 == 0 &&
                                  (iVar2 = strcmp(&DAT_180034368,"G-PARAMETER"), iVar2 == 0)))) {
                                FUN_180020fa0(param_1,1,param_2);
                                DAT_180032168 = 0xe;
                              }
                              else {
                                iVar2 = FUN_180021f90((longlong)param_1,"D-UNIFAC");
                                if (((iVar2 == 0) &&
                                    (iVar2 = strcmp(&DAT_180034368,"G-PARAMETER"), iVar2 == 0)) ||
                                   ((iVar2 = FUN_1800230f0(param_1,"METHOD","D-UNIFAC"), iVar2 == 0
                                    && (iVar2 = strcmp(&DAT_180034368,"G-PARAMETER"), iVar2 == 0))))
                                {
                                  FUN_180020fa0(param_1,1,param_2);
                                  DAT_180032168 = 0xf;
                                }
                                else {
                                  iVar2 = FUN_180021f90((longlong)param_1,"L-UNIFAC");
                                  if (((iVar2 == 0) &&
                                      (iVar2 = strcmp(&DAT_180034368,"G-PARAMETER"), iVar2 == 0)) ||
                                     ((iVar2 = FUN_1800230f0(param_1,"METHOD","L-UNIFAC"),
                                      iVar2 == 0 &&
                                      (iVar2 = strcmp(&DAT_180034368,"G-PARAMETER"), iVar2 == 0))))
                                  {
                                    FUN_180020fa0(param_1,1,param_2);
                                    DAT_180032168 = 0x10;
                                  }
                                  else {
                                    iVar2 = FUN_180021f90((longlong)param_1,"G-INTERACTIO");
                                    if (iVar2 == 0) {
                                      _DAT_180034370 =
                                           CONCAT14(s_G_INTERACTIO_180029518[0xc],
                                                    s_G_INTERACTIO_180029518._8_4_);
                                      DAT_180034368 = s_G_INTERACTIO_180029518[0];
                                      DAT_180034368_1 = s_G_INTERACTIO_180029518[1];
                                      cRam000000018003436a = s_G_INTERACTIO_180029518[2];
                                      cRam000000018003436b = s_G_INTERACTIO_180029518[3];
                                      cRam000000018003436c = s_G_INTERACTIO_180029518[4];
                                      cRam000000018003436d = s_G_INTERACTIO_180029518[5];
                                      cRam000000018003436e = s_G_INTERACTIO_180029518[6];
                                      cRam000000018003436f = s_G_INTERACTIO_180029518[7];
                                      return DAT_180032164;
                                    }
                                    iVar2 = FUN_180021f90((longlong)param_1,"UNIFAC");
                                    if (((iVar2 == 0) &&
                                        (iVar2 = strcmp(&DAT_180034368,"G-INTERACTIO"), iVar2 == 0))
                                       || ((iVar2 = FUN_1800230f0(param_1,"METHOD","UNIFAC"),
                                           iVar2 == 0 &&
                                           (iVar2 = strcmp(&DAT_180034368,"G-INTERACTIO"),
                                           iVar2 == 0)))) {
                                      FUN_180021210(param_1,1,param_2);
                                      DAT_180032168 = 0x11;
                                    }
                                    else {
                                      iVar2 = FUN_180021f90((longlong)param_1,"D-UNIFAC");
                                      if (((iVar2 == 0) &&
                                          (iVar2 = strcmp(&DAT_180034368,"G-INTERACTIO"), iVar2 == 0
                                          )) || ((iVar2 = FUN_1800230f0(param_1,"METHOD","D-UNIFAC")
                                                 , iVar2 == 0 &&
                                                 (iVar2 = strcmp(&DAT_180034368,"G-INTERACTIO"),
                                                 iVar2 == 0)))) {
                                        FUN_180021210(param_1,1,param_2);
                                        DAT_180032168 = 0x12;
                                      }
                                      else {
                                        iVar2 = FUN_180021f90((longlong)param_1,"L-UNIFAC");
                                        if (((iVar2 == 0) &&
                                            (iVar2 = strcmp(&DAT_180034368,"G-INTERACTIO"),
                                            iVar2 == 0)) ||
                                           ((iVar2 = FUN_1800230f0(param_1,"METHOD","L-UNIFAC"),
                                            iVar2 == 0 &&
                                            (iVar2 = strcmp(&DAT_180034368,"G-INTERACTIO"),
                                            iVar2 == 0)))) {
                                          FUN_180021210(param_1,1,param_2);
                                          DAT_180032168 = 0x13;
                                        }
                                        else {
                                          iVar2 = FUN_180021f90((longlong)param_1,"THERMODYNAMI");
                                          if (iVar2 != 0) {
                                            iVar2 = FUN_180021f90((longlong)param_1,"SYSTEM");
                                            if (iVar2 == 0) {
                                              return DAT_180032164;
                                            }
                                            DAT_1800342a8 = 0xffffffff;
                                            return DAT_180032164;
                                          }
                                          DAT_180032168 = 0x14;
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  DAT_1800342ac = 1;
  return DAT_180032164;
}

/* RVA 0x22da0, FUN_180022da0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_180022da0(char *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  char *pcVar1;
  char cVar2;
  longlong lVar3;
  int iVar4;
  int iVar5;
  FILE *_File;
  undefined8 uVar6;
  longlong lVar8;
  longlong lVar7;
  undefined1 *puVar9;
  longlong lVar10;
  uint uVar11;
  undefined7 uVar13;
  char *pcVar12;
  undefined8 uVar14;
  undefined1 auStack_2a8 [32];
  char local_288 [95];
  undefined1 uStack_229;
  char local_228 [512];
  ulonglong local_28;
  
  local_28 = DAT_180032178 ^ (ulonglong)auStack_2a8;
  _DAT_1800349a0 = 0x342e31;
  iVar5 = 0;
  uVar11 = 0;
  _File = fopen(param_1,"r");
  if (_File == (FILE *)0x0) {
    FUN_1800220b0(0,"Could not open file to read",param_3,param_4);
    return 0xffffffff;
  }
  uVar13 = (undefined7)((ulonglong)param_3 >> 8);
  FUN_1800232b0(_File,local_228,'\n',0x52);
  uVar14 = 0x52;
  pcVar12 = (char *)CONCAT71(uVar13,10);
  uVar6 = FUN_1800232b0(_File,local_288,'\n',0x52);
  iVar4 = (int)uVar6;
  if (iVar4 == -1) {
LAB_180022f90:
    fclose(_File);
    DAT_180032160 = 0xffffffff;
    if (iVar4 != -1) {
      if (iVar4 == -2) {
        if (iVar5 != 0) {
          FUN_1800220b0(0,"EOF reached, but not all paragraphs closed",pcVar12,uVar14);
          return 0xffffffff;
        }
      }
      else if ((iVar4 == 0) && (iVar5 < 0)) {
        FUN_1800220b0(0,"STOP proceccsing due to previous errors",pcVar12,uVar14);
        return 0xffffffff;
      }
      DAT_180032160 = 0xffffffff;
      return 0;
    }
  }
  else {
    do {
      iVar4 = (int)uVar6;
      uVar11 = uVar11 + 1;
      if (local_288[0] == DAT_180031784) {
        lVar8 = -1;
        do {
          lVar7 = lVar8 + 1;
          lVar3 = lVar8 + 1;
          lVar8 = lVar7;
        } while (local_288[lVar3] != '\0');
        lVar8 = -1;
        do {
          lVar10 = lVar8 + 1;
          lVar3 = lVar8 + 1;
          lVar8 = lVar10;
        } while (local_228[lVar3] != '\0');
        if (0x1ff < (int)lVar7 + -1 + (int)lVar10) {
          pcVar12 = (char *)(ulonglong)uVar11;
          FUN_1800220b0(0,"ABORT in Line %i - Continuation exceeds max length",pcVar12,uVar14);
          goto LAB_180022f90;
        }
        puVar9 = &uStack_229;
        do {
          pcVar12 = puVar9 + 1;
          puVar9 = puVar9 + 1;
        } while (*pcVar12 != '\0');
        pcVar12 = local_288 + 1;
        lVar8 = 0;
        do {
          cVar2 = pcVar12[lVar8];
          puVar9[lVar8] = cVar2;
          lVar8 = lVar8 + 1;
        } while (cVar2 != '\0');
      }
      else {
        if (local_228[0] != DAT_180031785) {
          DAT_1800349c0 = 0;
          lVar8 = 0;
          do {
            cVar2 = local_228[lVar8];
            (&DAT_1800349c0)[lVar8] = cVar2;
            lVar8 = lVar8 + 1;
          } while (cVar2 != '\0');
          iVar5 = FUN_180022180(local_228,uVar11,pcVar12,uVar14);
        }
        lVar8 = 0;
        do {
          pcVar1 = local_288 + lVar8;
          local_228[lVar8] = *pcVar1;
          lVar8 = lVar8 + 1;
        } while (*pcVar1 != '\0');
      }
      if ((iVar4 == -2) || (iVar5 < 0)) goto LAB_180022f90;
      uVar14 = 0x52;
      pcVar12 = (char *)CONCAT71((int7)((ulonglong)pcVar12 >> 8),10);
      uVar6 = FUN_1800232b0(_File,local_288,'\n',0x52);
    } while ((int)uVar6 != -1);
    fclose(_File);
  }
  DAT_180032160 = 0xffffffff;
  FUN_1800220b0(0,"ABORT in Line %i - to long line",(ulonglong)(uVar11 + 2),uVar14);
  return 0xffffffff;
}

/* RVA 0x23030, FUN_180023030 */
char * FUN_180023030(char *param_1)

{
  longlong lVar1;
  longlong lVar2;
  
  if (((*param_1 != DAT_180031787) || (param_1[1] != '\0')) && (*param_1 == DAT_180031786)) {
    lVar2 = -1;
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_1[lVar1] != '\0');
    if (param_1[(longlong)(int)lVar1 + -1] == DAT_180031786) {
      do {
        lVar2 = lVar2 + 1;
      } while (param_1[lVar2] != '\0');
      param_1[(longlong)(int)lVar2 + -1] = '\0';
      return param_1 + 1;
    }
  }
  return param_1;
}

/* RVA 0x23090, FUN_180023090 */
void FUN_180023090(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulonglong *puVar1;
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res18 = param_3;
  local_res20 = param_4;
  puVar1 = (ulonglong *)FUN_1800215b0();
  __stdio_common_vsscanf(*puVar1 | 1,param_1,0xffffffffffffffff,param_2,0,&local_res18);
  return;
}

/* RVA 0x230f0, FUN_1800230f0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_1800230f0(char *param_1,char *param_2,char *param_3)

{
  int iVar1;
  undefined1 auStack_228 [32];
  char *local_208;
  char *local_200;
  char local_1f8 [480];
  ulonglong local_18;
  
  local_18 = DAT_180032178 ^ (ulonglong)auStack_228;
  strncpy(local_1f8,param_1,0x1e0);
  iVar1 = FUN_180021730(local_1f8,&local_208,2,2);
  if ((iVar1 == 2) && (iVar1 = _stricmp(local_208,param_2), iVar1 == 0)) {
    iVar1 = _stricmp(local_200,param_3);
    return -(uint)(iVar1 != 0);
  }
  return -1;
}

/* RVA 0x231a0, FUN_1800231a0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_1800231a0(char *param_1,int param_2,uint param_3)

{
  int iVar1;
  undefined1 auStack_58 [32];
  uint local_38;
  uint local_34;
  undefined8 local_30 [2];
  char *local_20;
  ulonglong local_18;
  
  local_18 = DAT_180032178 ^ (ulonglong)auStack_58;
  if (param_2 == 1) {
    iVar1 = FUN_180021730(param_1,local_30,3,2);
    if (iVar1 == 3) {
      FUN_180022050(0x1800349a0,local_20,0x20,param_3);
      local_38 = 0;
      local_34 = 0;
      FUN_180023090(&DAT_1800349a0,"%u.%u",&local_38,&local_34);
      if ((1 < local_38) || ((local_38 == 1 && (5 < local_34)))) {
        DAT_180031780 = 0x10;
      }
    }
  }
  return 0;
}

/* RVA 0x232b0, FUN_1800232b0 */
undefined8 FUN_1800232b0(FILE *param_1,char *param_2,char param_3,int param_4)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  
  iVar2 = 0;
  iVar1 = getc(param_1);
  if ((char)iVar1 != param_3) {
    pcVar3 = param_2;
    do {
      if (iVar2 == param_4 + -2) {
        param_2[iVar2] = '\0';
        return 0xffffffff;
      }
      if ((char)iVar1 == -1) {
        param_2[iVar2] = '\0';
        return 0xfffffffe;
      }
      *pcVar3 = (char)iVar1;
      pcVar3 = pcVar3 + 1;
      iVar2 = iVar2 + 1;
      iVar1 = getc(param_1);
    } while ((char)iVar1 != param_3);
  }
  param_2[iVar2] = '\0';
  return 0;
}

/* RVA 0x23350, _stricmp */
int __cdecl _stricmp(char *_Str1,char *_Str2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180023350. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = _stricmp(_Str1,_Str2);
  return iVar1;
}

/* RVA 0x23360, FUN_180023360 */
void FUN_180023360(char *param_1)

{
  char cVar1;
  void *pvVar2;
  undefined1 *puVar3;
  longlong lVar5;
  longlong lVar4;
  
  if (param_1 == (char *)0x0) {
    puVar3 = malloc(1);
    *puVar3 = 0;
    return;
  }
  lVar4 = -1;
  do {
    lVar5 = lVar4;
    lVar4 = lVar5 + 1;
  } while (param_1[lVar4] != '\0');
  pvVar2 = malloc(lVar5 + 2);
  lVar4 = (longlong)pvVar2 - (longlong)param_1;
  do {
    cVar1 = *param_1;
    param_1[lVar4] = cVar1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  return;
}

/* RVA 0x23430, FUN_180023430 */
char * FUN_180023430(char *param_1,undefined1 *param_2)

{
  char cVar1;
  undefined1 auVar2 [16];
  ulonglong uVar3;
  char *pcVar4;
  int iVar5;
  longlong lVar6;
  ulonglong uVar7;
  char *pcVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  
  uVar10 = 0xffffffffffffffff;
  uVar9 = 0xffffffffffffffff;
  do {
    uVar3 = uVar9;
    uVar9 = uVar3 + 1;
  } while (param_1[uVar9] != '\0');
  do {
    uVar10 = uVar10 + 1;
  } while (param_2[uVar10] != '\0');
  auVar2._8_8_ = 0;
  auVar2._0_8_ = uVar9;
  lVar6 = SUB168(ZEXT816(0x47ae147ae147ae15) * auVar2,8);
  uVar7 = uVar3 + 2 + uVar10;
  lVar6 = ((uVar9 - lVar6 >> 1) + lVar6 >> 7) + 1;
  uVar3 = lVar6 * 200;
  if (uVar3 <= uVar7) {
    do {
      lVar6 = lVar6 + 1;
      uVar3 = uVar3 + 200;
    } while (uVar3 <= uVar7);
    pcVar4 = malloc(lVar6 * 200);
    pcVar8 = param_1;
    do {
      cVar1 = *pcVar8;
      pcVar8[(longlong)pcVar4 - (longlong)param_1] = cVar1;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    free(param_1);
    param_1 = pcVar4;
  }
  iVar5 = 0;
  lVar6 = uVar9 - (longlong)param_2;
  do {
    iVar5 = iVar5 + 1;
    param_2[(longlong)(param_1 + lVar6)] = *param_2;
    param_2 = param_2 + 1;
  } while ((ulonglong)(longlong)iVar5 <= uVar10);
  return param_1;
}

/* RVA 0x23550, FUN_180023550 */
int FUN_180023550(char *param_1,char *param_2)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  longlong lVar4;
  int iVar5;
  
  cVar2 = *param_1;
  iVar5 = 0;
  if (cVar2 != '\0') {
    lVar4 = (longlong)param_2 - (longlong)param_1;
    do {
      if (*param_2 == cVar2) {
        pcVar3 = param_1;
        do {
          if (pcVar3[lVar4 + 1] == '\0') {
            iVar5 = iVar5 + 1;
            break;
          }
          pcVar1 = pcVar3 + 1;
          pcVar3 = pcVar3 + 1;
        } while (pcVar3[lVar4] == *pcVar1);
      }
      cVar2 = param_1[1];
      param_1 = param_1 + 1;
      lVar4 = lVar4 + -1;
    } while (cVar2 != '\0');
  }
  return iVar5;
}

/* RVA 0x235a0, FUN_1800235a0 */
char * FUN_1800235a0(char *param_1,int param_2,char *param_3,int param_4)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  longlong lVar4;
  char *pcVar5;
  longlong lVar6;
  int iVar7;
  int iVar8;
  
  iVar7 = param_2 / 200 + 1;
  iVar8 = param_4 + 1 + param_2;
  iVar2 = iVar7 * 200;
  if (iVar2 <= iVar8) {
    do {
      iVar7 = iVar7 + 1;
      iVar2 = iVar2 + 200;
    } while (iVar2 <= iVar8);
    pcVar3 = malloc((longlong)(iVar7 * 200));
    pcVar5 = param_1;
    do {
      cVar1 = *pcVar5;
      pcVar5[(longlong)pcVar3 - (longlong)param_1] = cVar1;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    free(param_1);
    param_1 = pcVar3;
  }
  if (-1 < (longlong)param_4) {
    lVar6 = (longlong)param_2 - (longlong)param_3;
    lVar4 = (longlong)param_4 + 1;
    do {
      (param_1 + lVar6)[(longlong)param_3] = *param_3;
      param_3 = param_3 + 1;
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
  }
  return param_1;
}

/* RVA 0x236a0, FUN_1800236a0 */
char * FUN_1800236a0(char *param_1,char *param_2,int param_3)

{
  longlong lVar1;
  
  strncpy(param_1,param_2,(longlong)param_3 - 1);
  lVar1 = -1;
  do {
    lVar1 = lVar1 + 1;
  } while (param_2[lVar1] != '\0');
  if (param_3 + -1 <= (int)lVar1) {
    builtin_strncpy(param_1 + (longlong)param_3 + -4,"...",4);
  }
  return param_1;
}

/* RVA 0x23710, FUN_180023710 */
void FUN_180023710(void)

{
  undefined1 *puVar1;
  
  puVar1 = malloc(200);
  *puVar1 = 0;
  return;
}

/* RVA 0x23730, FUN_180023730 */
char * FUN_180023730(char *param_1,char *param_2,int param_3)

{
  longlong lVar1;
  
  strncpy(param_1,param_2,(longlong)param_3 - 1);
  lVar1 = -1;
  do {
    lVar1 = lVar1 + 1;
  } while (param_2[lVar1] != '\0');
  if (param_3 + -1 <= (int)lVar1) {
    param_1[(longlong)param_3 + -1] = '\0';
  }
  return param_1;
}

/* RVA 0x23790, FUN_180023790 */
char * FUN_180023790(char *param_1,char *param_2,undefined1 *param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  longlong lVar8;
  int iVar9;
  longlong lVar10;
  
  iVar2 = FUN_180023550(param_1,param_2);
  if (iVar2 == 0) {
    return param_1;
  }
  lVar8 = -1;
  lVar10 = -1;
  do {
    lVar10 = lVar10 + 1;
  } while (param_1[lVar10] != '\0');
  lVar4 = -1;
  do {
    lVar4 = lVar4 + 1;
  } while (param_2[lVar4] != '\0');
  do {
    lVar8 = lVar8 + 1;
  } while (param_3[lVar8] != '\0');
  iVar7 = (int)lVar8 - (int)lVar4;
  if (0 < iVar7) {
    iVar9 = (int)lVar10 / 200 + 1;
    iVar3 = iVar9 * 200;
    iVar2 = iVar7 * iVar2 + 1 + (int)lVar10;
    if (iVar3 <= iVar2) {
      do {
        iVar9 = iVar9 + 1;
        iVar3 = iVar3 + 200;
      } while (iVar3 <= iVar2);
      pcVar5 = malloc((longlong)(iVar9 * 200));
      pcVar6 = param_1;
      do {
        cVar1 = *pcVar6;
        pcVar6[(longlong)pcVar5 - (longlong)param_1] = cVar1;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      free(param_1);
      param_1 = pcVar5;
    }
  }
  pcVar6 = FUN_1800238a0(param_1,param_2,param_3);
  return pcVar6;
}

/* RVA 0x238a0, FUN_1800238a0 */
char * FUN_1800238a0(char *param_1,char *param_2,undefined1 *param_3)

{
  char *pcVar1;
  int iVar2;
  longlong lVar3;
  char *pcVar4;
  undefined1 *puVar5;
  longlong lVar6;
  char *pcVar7;
  longlong lVar8;
  longlong lVar9;
  longlong lVar10;
  longlong lVar11;
  int iVar12;
  ulonglong uVar13;
  longlong lVar14;
  int iVar15;
  int iVar16;
  longlong lVar17;
  
  iVar2 = FUN_180023550(param_1,param_2);
  if (iVar2 == 0) {
    return param_1;
  }
  lVar3 = -1;
  lVar10 = -1;
  do {
    lVar9 = lVar10;
    lVar10 = lVar9 + 1;
  } while (param_1[lVar10] != '\0');
  uVar13 = 0xffffffffffffffff;
  do {
    uVar13 = uVar13 + 1;
  } while (param_2[uVar13] != '\0');
  do {
    lVar3 = lVar3 + 1;
  } while (param_3[lVar3] != '\0');
  iVar2 = (int)lVar3;
  iVar16 = iVar2 - (int)uVar13;
  if (*param_1 != '\0') {
    lVar14 = (longlong)param_1 - (longlong)param_3;
    lVar3 = (longlong)(int)uVar13;
    lVar8 = 0;
    iVar15 = (int)lVar9 + 2;
    lVar17 = (longlong)(int)lVar10 + 1;
    lVar9 = (longlong)iVar16;
    lVar11 = (longlong)param_1 - (longlong)param_2;
    pcVar7 = param_1 + lVar3;
    lVar10 = lVar3;
    do {
      iVar12 = (int)uVar13;
      if (param_1[lVar8] == *param_2) {
        pcVar4 = param_2;
LAB_180023964:
        if (pcVar4[1] != '\0') goto code_r0x00018002396a;
        if (iVar16 < 1) {
          if ((iVar16 < 0) && (lVar10 <= iVar15)) {
            lVar6 = ((iVar15 - lVar3) - lVar8) + 1;
            pcVar4 = pcVar7;
            do {
              pcVar4[lVar9] = *pcVar4;
              pcVar4 = pcVar4 + 1;
              lVar6 = lVar6 + -1;
            } while (lVar6 != 0);
          }
        }
        else if (iVar12 <= lVar17) {
          pcVar4 = param_1 + lVar17;
          lVar6 = (lVar17 - iVar12) + 1;
          do {
            pcVar4[lVar9] = *pcVar4;
            pcVar4 = pcVar4 + -1;
            lVar6 = lVar6 + -1;
          } while (lVar6 != 0);
        }
        if (0 < (longlong)iVar2) {
          puVar5 = param_3;
          lVar6 = (longlong)iVar2;
          do {
            puVar5[lVar14] = *puVar5;
            puVar5 = puVar5 + 1;
            lVar6 = lVar6 + -1;
          } while (lVar6 != 0);
        }
        iVar15 = iVar15 + iVar16;
        lVar17 = lVar17 + lVar9;
        iVar12 = iVar12 + iVar16;
        lVar8 = lVar8 + lVar9;
        lVar11 = lVar11 + lVar9;
        lVar10 = lVar10 + lVar9;
        pcVar7 = pcVar7 + lVar9;
        lVar14 = lVar14 + lVar9;
      }
LAB_180023a29:
      lVar8 = lVar8 + 1;
      uVar13 = (ulonglong)(iVar12 + 1);
      lVar11 = lVar11 + 1;
      lVar10 = lVar10 + 1;
      pcVar7 = pcVar7 + 1;
      lVar14 = lVar14 + 1;
    } while (param_1[lVar8] != '\0');
  }
  return param_1;
code_r0x00018002396a:
  pcVar1 = pcVar4 + 1;
  pcVar4 = pcVar4 + 1;
  if (pcVar4[lVar11] != *pcVar1) goto LAB_180023a29;
  goto LAB_180023964;
}

/* RVA 0x23a80, FUN_180023a80 */
char * FUN_180023a80(char *param_1,char *param_2)

{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  
  pcVar1 = strstr(param_1,param_2);
  pcVar3 = pcVar1;
  if (pcVar1 != (char *)0x0) {
    do {
      pcVar2 = pcVar3;
      if (*pcVar2 == '\0') break;
      pcVar3 = strstr(pcVar2 + 1,param_2);
      pcVar1 = pcVar2;
    } while (pcVar3 != (char *)0x0);
  }
  return pcVar1;
}

/* RVA 0x23b30, FUN_180023b30 */
void FUN_180023b30(longlong param_1,int param_2)

{
  longlong lVar1;
  
  if (0 < param_2) {
    lVar1 = 0;
    do {
      free(*(void **)(param_1 + lVar1 * 8));
      lVar1 = lVar1 + 1;
    } while (lVar1 < param_2);
  }
  return;
}

/* RVA 0x23b80, FUN_180023b80 */
void FUN_180023b80(undefined8 *param_1,uint param_2,int param_3)

{
  undefined1 *puVar1;
  ulonglong uVar2;
  
  if (0 < (int)param_2) {
    uVar2 = (ulonglong)param_2;
    do {
      puVar1 = malloc((longlong)param_3);
      *param_1 = puVar1;
      param_1 = param_1 + 1;
      *puVar1 = 0;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  return;
}

/* RVA 0x23bd0, FUN_180023bd0 */
void FUN_180023bd0(int *param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  uVar1 = FUN_180023ea0(param_2,*(undefined8 *)(param_1 + 2),0);
  if (*param_1 == 0) {
    *param_1 = *param_1 + 1;
    *(undefined8 *)(param_1 + 4) = uVar1;
    *(undefined8 *)(param_1 + 2) = uVar1;
    return;
  }
  *(undefined8 *)(*(longlong *)(param_1 + 2) + 0x10) = uVar1;
  *param_1 = *param_1 + 1;
  *(undefined8 *)(param_1 + 2) = uVar1;
  return;
}

/* RVA 0x23c20, FUN_180023c20 */
void FUN_180023c20(int *param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  uVar1 = FUN_180023ea0(param_2,0,*(undefined8 *)(param_1 + 4));
  if (*param_1 == 0) {
    *param_1 = *param_1 + 1;
    *(undefined8 *)(param_1 + 2) = uVar1;
    *(undefined8 *)(param_1 + 4) = uVar1;
    return;
  }
  *(undefined8 *)(*(longlong *)(param_1 + 4) + 8) = uVar1;
  *param_1 = *param_1 + 1;
  *(undefined8 *)(param_1 + 4) = uVar1;
  return;
}

/* RVA 0x23c70, FUN_180023c70 */
undefined8 FUN_180023c70(int *param_1)

{
  undefined8 *_Memory;
  longlong lVar1;
  undefined8 uVar2;
  int iVar3;
  
  if (*param_1 == 0) {
    return 0;
  }
  _Memory = *(undefined8 **)(param_1 + 2);
  iVar3 = *param_1 + -1;
  lVar1 = _Memory[1];
  uVar2 = *_Memory;
  *(longlong *)(param_1 + 2) = lVar1;
  *param_1 = iVar3;
  if (iVar3 == 0) {
    param_1[4] = 0;
    param_1[5] = 0;
  }
  else {
    *(undefined8 *)(lVar1 + 0x10) = 0;
  }
  free(_Memory);
  return uVar2;
}

/* RVA 0x23cd0, FUN_180023cd0 */
undefined8 FUN_180023cd0(int *param_1)

{
  undefined8 *_Memory;
  longlong lVar1;
  undefined8 uVar2;
  int iVar3;
  
  if (*param_1 == 0) {
    return 0;
  }
  _Memory = *(undefined8 **)(param_1 + 4);
  iVar3 = *param_1 + -1;
  lVar1 = _Memory[2];
  uVar2 = *_Memory;
  *(longlong *)(param_1 + 4) = lVar1;
  *param_1 = iVar3;
  if (iVar3 == 0) {
    param_1[2] = 0;
    param_1[3] = 0;
  }
  else {
    *(undefined8 *)(lVar1 + 8) = 0;
  }
  free(_Memory);
  return uVar2;
}

/* RVA 0x23d30, FUN_180023d30 */
undefined8 FUN_180023d30(int param_1,int *param_2)

{
  int iVar1;
  undefined8 *_Memory;
  undefined8 uVar2;
  ulonglong uVar3;
  longlong lVar4;
  
  iVar1 = *param_2;
  if ((iVar1 == 0) || (iVar1 < param_1)) {
    return 0;
  }
  if (param_1 == 1) {
    uVar2 = FUN_180023c70(param_2);
    return uVar2;
  }
  if (param_1 == iVar1) {
    uVar2 = FUN_180023cd0(param_2);
    return uVar2;
  }
  lVar4 = *(longlong *)(param_2 + 2);
  if (1 < param_1 + -1) {
    uVar3 = (ulonglong)(param_1 - 2);
    do {
      lVar4 = *(longlong *)(lVar4 + 8);
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  _Memory = *(undefined8 **)(lVar4 + 8);
  uVar2 = *_Memory;
  *(undefined8 *)(lVar4 + 8) = _Memory[1];
  *(longlong *)(_Memory[1] + 0x10) = lVar4;
  *param_2 = *param_2 + -1;
  free(_Memory);
  return uVar2;
}

/* RVA 0x23dc0, FUN_180023dc0 */
void FUN_180023dc0(int *param_1)

{
  void *_Memory;
  int iVar1;
  
  iVar1 = 1;
  if (0 < *param_1) {
    do {
      _Memory = (void *)FUN_180023c70(param_1);
      free(_Memory);
      iVar1 = iVar1 + 1;
    } while (iVar1 <= *param_1);
  }
                    /* WARNING: Could not recover jumptable at 0x000180023dfa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  free(param_1);
  return;
}

/* RVA 0x23e70, FUN_180023e70 */
void FUN_180023e70(void)

{
  undefined4 *puVar1;
  
  puVar1 = malloc(0x18);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    *(undefined8 *)(puVar1 + 2) = 0;
    *(undefined8 *)(puVar1 + 4) = 0;
  }
  return;
}

/* RVA 0x23ea0, FUN_180023ea0 */
void FUN_180023ea0(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  
  puVar1 = malloc(0x18);
  if (puVar1 != (undefined8 *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = param_3;
  }
  return;
}

/* RVA 0x23ee9, GetnamesfromCasno */
void GetnamesfromCasno(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180023ee9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetnamesfromCasno();
  return;
}

/* RVA 0x23eef, open_message_box */
void open_message_box(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180023eef. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  open_message_box();
  return;
}

/* RVA 0x23ef5, MVGetVersionString */
void MVGetVersionString(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180023ef5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MVGetVersionString();
  return;
}

/* RVA 0x23efc, __GSHandlerCheck */
/* Library Function - Single Match
    __GSHandlerCheck
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}

/* RVA 0x23f1c, __GSHandlerCheckCommon */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* Library Function - Single Match
    __GSHandlerCheckCommon
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

ulonglong __GSHandlerCheckCommon(undefined8 param_1,longlong param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  uVar2 = (ulonglong)*(uint *)(*(longlong *)(param_2 + 0x10) + 8);
  uVar1 = *(ulonglong *)(param_2 + 8);
  if ((*(byte *)(uVar2 + 3 + uVar1) & 0xf) != 0) {
    uVar1 = (ulonglong)(*(byte *)(uVar2 + 3 + uVar1) & 0xfffffff0);
  }
  return uVar1;
}

/* RVA 0x23f90, __security_check_cookie */
/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie == DAT_180032178) && ((short)(_StackCookie >> 0x30) == 0)) {
    return;
  }
  FUN_180023fe4();
  return;
}

/* RVA 0x23fb0, __raise_securityfailure */
/* Library Function - Single Match
    __raise_securityfailure
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void __raise_securityfailure(_EXCEPTION_POINTERS *param_1)

{
  HANDLE pvVar1;
  
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter(param_1);
  pvVar1 = GetCurrentProcess();
                    /* WARNING: Could not recover jumptable at 0x000180023fdd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  TerminateProcess(pvVar1,0xc0000409);
  return;
}

/* RVA 0x23fe4, FUN_180023fe4 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_180023fe4(void)

{
  code *pcVar1;
  BOOL BVar2;
  undefined1 *puVar3;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [48];
  
  BVar2 = IsProcessorFeaturePresent(0x17);
  puVar3 = auStack_38;
  if (BVar2 != 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(2);
    puVar3 = auStack_30;
  }
  *(undefined8 *)(puVar3 + -8) = 0x18002400f;
  capture_previous_context((PCONTEXT)&DAT_180034430);
  _DAT_1800343a0 = *(undefined8 *)(puVar3 + 0x38);
  _DAT_1800344c8 = puVar3 + 0x40;
  _DAT_1800344b0 = *(undefined8 *)(puVar3 + 0x40);
  _DAT_180034390 = 0xc0000409;
  _DAT_180034394 = 1;
  _DAT_1800343a8 = 1;
  DAT_1800343b0 = 2;
  *(undefined8 *)(puVar3 + 0x20) = DAT_180032178;
  *(undefined8 *)(puVar3 + 0x28) = DAT_180032170;
  *(undefined8 *)(puVar3 + -8) = 0x1800240b1;
  DAT_180034528 = _DAT_1800343a0;
  __raise_securityfailure((_EXCEPTION_POINTERS *)&PTR_DAT_180029e70);
  return;
}

/* RVA 0x240b8, FUN_1800240b8 */
void FUN_1800240b8(void)

{
  FUN_1800240cc(8);
  return;
}

/* RVA 0x240cc, FUN_1800240cc */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1800240cc(undefined4 param_1)

{
  code *pcVar1;
  BOOL BVar2;
  undefined1 *puVar3;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [32];
  
  BVar2 = IsProcessorFeaturePresent(0x17);
  puVar3 = auStack_28;
  if (BVar2 != 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(param_1);
    puVar3 = auStack_20;
  }
  *(undefined8 *)(puVar3 + -8) = 0x1800240f7;
  capture_current_context((PCONTEXT)&DAT_180034430);
  _DAT_1800343a0 = *(undefined8 *)(puVar3 + 0x28);
  _DAT_1800344c8 = puVar3 + 0x30;
  _DAT_180034390 = 0xc0000409;
  _DAT_180034394 = 1;
  _DAT_1800343a8 = 1;
  DAT_1800343b0 = (ulonglong)*(uint *)(puVar3 + 0x30);
  *(undefined8 *)(puVar3 + -8) = 0x180024163;
  DAT_180034528 = _DAT_1800343a0;
  __raise_securityfailure((_EXCEPTION_POINTERS *)&PTR_DAT_180029e70);
  return;
}

/* RVA 0x24168, FUN_180024168 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_180024168(undefined4 param_1)

{
  code *pcVar1;
  BOOL BVar2;
  undefined1 *puVar3;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [48];
  
  BVar2 = IsProcessorFeaturePresent(0x17);
  puVar3 = auStack_38;
  if (BVar2 != 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(param_1);
    puVar3 = auStack_30;
  }
  *(undefined8 *)(puVar3 + -8) = 0x18002419c;
  capture_current_context((PCONTEXT)&DAT_180034430);
  _DAT_1800343a0 = *(undefined8 *)(puVar3 + 0x38);
  _DAT_1800344c8 = puVar3 + 0x40;
  _DAT_180034390 = 0xc0000409;
  _DAT_180034394 = 1;
  if ((*(int *)(puVar3 + 0x48) != 0) && (*(longlong *)(puVar3 + 0x50) == 0)) {
    *(undefined4 *)(puVar3 + 0x48) = 0;
  }
  if (0xe < *(uint *)(puVar3 + 0x48)) {
    *(int *)(puVar3 + 0x48) = *(int *)(puVar3 + 0x48) + -1;
  }
  _DAT_1800343a8 = *(int *)(puVar3 + 0x48) + 1;
  DAT_1800343b0 = (ulonglong)*(uint *)(puVar3 + 0x40);
  *(undefined4 *)(puVar3 + 0x20) = 0;
  DAT_180034528 = _DAT_1800343a0;
  while (*(uint *)(puVar3 + 0x20) < *(uint *)(puVar3 + 0x48)) {
    (&DAT_1800343b0)[*(int *)(puVar3 + 0x20) + 1] =
         *(undefined8 *)(*(longlong *)(puVar3 + 0x50) + (ulonglong)*(uint *)(puVar3 + 0x20) * 8);
    *(int *)(puVar3 + 0x20) = *(int *)(puVar3 + 0x20) + 1;
  }
  *(undefined8 *)(puVar3 + -8) = 0x180024272;
  __raise_securityfailure((_EXCEPTION_POINTERS *)&PTR_DAT_180029e70);
  return;
}

/* RVA 0x24278, capture_current_context */
/* Library Function - Single Match
    capture_current_context
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void capture_current_context(PCONTEXT param_1)

{
  DWORD64 ControlPc;
  PRUNTIME_FUNCTION FunctionEntry;
  DWORD64 local_res8;
  ulonglong local_res10;
  PVOID local_res18;
  
  RtlCaptureContext();
  ControlPc = param_1->Rip;
  FunctionEntry = RtlLookupFunctionEntry(ControlPc,&local_res8,(PUNWIND_HISTORY_TABLE)0x0);
  if (FunctionEntry != (PRUNTIME_FUNCTION)0x0) {
    RtlVirtualUnwind(0,local_res8,ControlPc,FunctionEntry,param_1,&local_res18,&local_res10,
                     (PKNONVOLATILE_CONTEXT_POINTERS)0x0);
  }
  return;
}

/* RVA 0x242e8, capture_previous_context */
/* Library Function - Single Match
    capture_previous_context
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void capture_previous_context(PCONTEXT param_1)

{
  DWORD64 ControlPc;
  PRUNTIME_FUNCTION FunctionEntry;
  int iVar1;
  DWORD64 local_res8;
  ulonglong local_res10;
  PVOID local_res18 [2];
  
  RtlCaptureContext();
  ControlPc = param_1->Rip;
  iVar1 = 0;
  do {
    FunctionEntry = RtlLookupFunctionEntry(ControlPc,&local_res8,(PUNWIND_HISTORY_TABLE)0x0);
    if (FunctionEntry == (PRUNTIME_FUNCTION)0x0) {
      return;
    }
    RtlVirtualUnwind(0,local_res8,ControlPc,FunctionEntry,param_1,local_res18,&local_res10,
                     (PKNONVOLATILE_CONTEXT_POINTERS)0x0);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 2);
  return;
}

/* RVA 0x2435c, FUN_18002435c */
ulonglong FUN_18002435c(undefined8 param_1,int param_2,longlong param_3)

{
  byte bVar1;
  ulonglong uVar2;
  undefined7 extraout_var;
  
  if (param_2 == 0) {
    bVar1 = FUN_1800244c4(CONCAT71((int7)((ulonglong)param_1 >> 8),param_3 != 0));
    return CONCAT71(extraout_var,bVar1);
  }
  if (param_2 == 1) {
    uVar2 = FUN_1800243ac(param_1,param_3);
    return uVar2;
  }
  if (param_2 == 2) {
    bVar1 = FUN_180024980();
  }
  else {
    if (param_2 != 3) {
      return 1;
    }
    bVar1 = FUN_1800249a8();
  }
  return (ulonglong)bVar1;
}

/* RVA 0x243ac, FUN_1800243ac */
undefined8 FUN_1800243ac(undefined8 param_1,undefined8 param_2)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  longlong *plVar7;
  ulonglong uVar8;
  
  lVar4 = __scrt_initialize_crt(0);
  if ((char)lVar4 != '\0') {
    uVar5 = __scrt_acquire_startup_lock();
    bVar1 = true;
    if (DAT_180034930 != 0) {
                    /* WARNING: Subroutine does not return */
      FUN_180024ca8(7);
    }
    DAT_180034930 = 1;
    bVar2 = FUN_180024968();
    if (bVar2) {
      FUN_180024f00();
      FUN_18002481c();
      FUN_180024838();
      iVar3 = _initterm_e(&DAT_1800262a0,&DAT_1800262a8);
      if ((iVar3 == 0) && (uVar6 = __scrt_dllmain_after_initialize_c(), (char)uVar6 != '\0')) {
        _initterm(&DAT_180026290,&DAT_180026298);
        DAT_180034930 = 2;
        bVar1 = false;
      }
    }
    __scrt_release_startup_lock((char)uVar5);
    if (!bVar1) {
      plVar7 = (longlong *)FUN_180024c98();
      if ((*plVar7 != 0) && (uVar8 = FUN_180024b3c((longlong)plVar7), (char)uVar8 != '\0')) {
        (*(code *)PTR__guard_dispatch_icall_180026268)(param_1,2,param_2);
      }
      DAT_180034900 = DAT_180034900 + 1;
      return 1;
    }
  }
  return 0;
}

/* RVA 0x244c4, FUN_1800244c4 */
byte FUN_1800244c4(undefined8 param_1)

{
  undefined1 uVar1;
  char cVar2;
  undefined8 uVar3;
  undefined7 uVar4;
  byte bVar5;
  
  uVar1 = (undefined1)param_1;
  if (DAT_180034900 < 1) {
    bVar5 = 0;
  }
  else {
    DAT_180034900 = DAT_180034900 + -1;
    uVar3 = __scrt_acquire_startup_lock();
    if (DAT_180034930 != 2) {
                    /* WARNING: Subroutine does not return */
      FUN_180024ca8(7);
    }
    __scrt_dllmain_uninitialize_c();
    FUN_18002482c();
    FUN_180024f3c();
    DAT_180034930 = 0;
    uVar4 = (undefined7)((ulonglong)param_1 >> 8);
    __scrt_release_startup_lock((char)uVar3);
    cVar2 = __scrt_uninitialize_crt(CONCAT71(uVar4,uVar1),'\0');
    bVar5 = -(cVar2 != '\0') & 1;
    FUN_180024a50();
  }
  return bVar5;
}

/* RVA 0x24548, dllmain_dispatch */
/* Library Function - Single Match
    int __cdecl dllmain_dispatch(struct HINSTANCE__ * __ptr64 const,unsigned long,void * __ptr64
   const)
   
   Library: Visual Studio 2019 Release */

int __cdecl dllmain_dispatch(HINSTANCE__ *param_1,ulong param_2,void *param_3)

{
  ulonglong uVar1;
  undefined8 uVar2;
  HINSTANCE__ *pHVar3;
  int iVar4;
  
  if ((param_2 == 0) && (DAT_180034900 < 1)) {
    iVar4 = 0;
  }
  else {
    if (param_2 - 1 < 2) {
      if ((DAT_180029e80 != 0) &&
         (iVar4 = (*(code *)PTR__guard_dispatch_icall_180026268)(), iVar4 == 0)) {
        return 0;
      }
      uVar1 = FUN_18002435c(param_1,param_2,(longlong)param_3);
      if ((int)uVar1 == 0) {
        return 0;
      }
    }
    uVar2 = DllMain(param_1,param_2);
    iVar4 = (int)uVar2;
    if ((param_2 == 1) && (iVar4 == 0)) {
      pHVar3 = param_1;
      DllMain(param_1,0);
      FUN_1800244c4(CONCAT71((int7)((ulonglong)pHVar3 >> 8),param_3 != (void *)0x0));
      if (DAT_180029e80 != 0) {
        (*(code *)PTR__guard_dispatch_icall_180026268)(param_1,0,param_3);
      }
    }
    if ((param_2 == 0) || (param_2 == 3)) {
      uVar1 = FUN_18002435c(param_1,param_2,(longlong)param_3);
      iVar4 = 0;
      if ((int)uVar1 != 0) {
        if (DAT_180029e80 == 0) {
          iVar4 = 1;
        }
        else {
          iVar4 = (*(code *)PTR__guard_dispatch_icall_180026268)(param_1,param_2,param_3);
        }
      }
    }
  }
  return iVar4;
}

/* RVA 0x246a0, entry */
void entry(HINSTANCE__ *param_1,ulong param_2,void *param_3)

{
  if (param_2 == 1) {
    __security_init_cookie();
  }
  dllmain_dispatch(param_1,param_2,param_3);
  return;
}

/* RVA 0x246e0, FUN_1800246e0 */
ulonglong FUN_1800246e0(void)

{
  DWORD DVar1;
  _FILETIME local_res8;
  _FILETIME local_res10;
  LARGE_INTEGER local_res18 [2];
  
  local_res10.dwLowDateTime = 0;
  local_res10.dwHighDateTime = 0;
  GetSystemTimeAsFileTime(&local_res10);
  local_res8 = local_res10;
  DVar1 = GetCurrentThreadId();
  local_res8 = (_FILETIME)((ulonglong)local_res8 ^ (ulonglong)DVar1);
  DVar1 = GetCurrentProcessId();
  local_res8 = (_FILETIME)((ulonglong)local_res8 ^ (ulonglong)DVar1);
  QueryPerformanceCounter(local_res18);
  return ((ulonglong)local_res18[0].s.LowPart << 0x20 ^
          CONCAT44(local_res18[0].s.HighPart,local_res18[0].s.LowPart) ^ (ulonglong)local_res8 ^
         (ulonglong)&local_res8) & 0xffffffffffff;
}

/* RVA 0x2474c, __security_init_cookie */
/* Library Function - Single Match
    __security_init_cookie
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl __security_init_cookie(void)

{
  DWORD DVar1;
  _FILETIME local_res8;
  LARGE_INTEGER local_res10;
  _FILETIME local_18 [2];
  
  if (DAT_180032178 == 0x2b992ddfa232) {
    local_res8.dwLowDateTime = 0;
    local_res8.dwHighDateTime = 0;
    GetSystemTimeAsFileTime(&local_res8);
    local_18[0] = local_res8;
    DVar1 = GetCurrentThreadId();
    local_18[0] = (_FILETIME)((ulonglong)local_18[0] ^ (ulonglong)DVar1);
    DVar1 = GetCurrentProcessId();
    local_18[0] = (_FILETIME)((ulonglong)local_18[0] ^ (ulonglong)DVar1);
    QueryPerformanceCounter(&local_res10);
    DAT_180032178 =
         ((ulonglong)local_res10.s.LowPart << 0x20 ^
          CONCAT44(local_res10.s.HighPart,local_res10.s.LowPart) ^ (ulonglong)local_18[0] ^
         (ulonglong)local_18) & 0xffffffffffff;
    if (DAT_180032178 == 0x2b992ddfa232) {
      DAT_180032178 = 0x2b992ddfa233;
    }
  }
  DAT_180032170 = ~DAT_180032178;
  return;
}

/* RVA 0x247f8, DllMain */
/* Library Function - Single Match
    DllMain
   
   Library: Visual Studio 2019 Release */

undefined8 DllMain(HMODULE param_1,int param_2)

{
  if ((param_2 == 1) && (DAT_180029e80 == 0)) {
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}

/* RVA 0x2481c, FUN_18002481c */
void FUN_18002481c(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180024823. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  InitializeSListHead(&DAT_180034910);
  return;
}

/* RVA 0x2482c, FUN_18002482c */
void FUN_18002482c(void)

{
  __std_type_info_destroy_list(&DAT_180034910);
  return;
}

/* RVA 0x24838, FUN_180024838 */
void FUN_180024838(void)

{
  ulonglong *puVar1;
  
  puVar1 = (ulonglong *)FUN_180001770();
  *puVar1 = *puVar1 | 0x24;
  puVar1 = (ulonglong *)FUN_1800215b0();
  *puVar1 = *puVar1 | 2;
  return;
}

/* RVA 0x24854, FUN_180024854 */
void FUN_180024854(void)

{
  ulonglong uVar1;
  
  uVar1 = FUN_1800253a0();
  _configure_narrow_argv(uVar1 & 0xffffffff);
  return;
}

/* RVA 0x248f8, __scrt_acquire_startup_lock */
/* Library Function - Single Match
    __scrt_acquire_startup_lock
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

ulonglong __scrt_acquire_startup_lock(void)

{
  bool bVar1;
  undefined7 extraout_var;
  ulonglong uVar2;
  
  bVar1 = __scrt_is_ucrt_dll_in_use();
  uVar2 = CONCAT71(extraout_var,bVar1);
  if ((int)uVar2 == 0) {
LAB_180024926:
    uVar2 = uVar2 & 0xffffffffffffff00;
  }
  else {
    do {
      uVar2 = 0;
      LOCK();
      bVar1 = DAT_180034938 == 0;
      if (bVar1) {
        DAT_180034938 = *(ulonglong *)((longlong)Self + 8);
      }
      else {
        uVar2 = DAT_180034938;
      }
      UNLOCK();
      if (bVar1) goto LAB_180024926;
    } while (*(ulonglong *)((longlong)Self + 8) != uVar2);
    uVar2 = CONCAT71((int7)(uVar2 >> 8),1);
  }
  return uVar2;
}

/* RVA 0x24934, __scrt_dllmain_after_initialize_c */
/* Library Function - Single Match
    __scrt_dllmain_after_initialize_c
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined8 __scrt_dllmain_after_initialize_c(void)

{
  bool bVar1;
  undefined7 extraout_var;
  undefined8 uVar2;
  ulonglong uVar3;
  
  bVar1 = __scrt_is_ucrt_dll_in_use();
  if ((int)CONCAT71(extraout_var,bVar1) == 0) {
    uVar3 = FUN_1800253a0();
    uVar3 = _configure_narrow_argv(uVar3 & 0xffffffff);
    if ((int)uVar3 != 0) {
      return uVar3 & 0xffffffffffffff00;
    }
    uVar2 = _initialize_narrow_environment();
  }
  else {
    uVar2 = FUN_1800251f4();
  }
  return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
}

/* RVA 0x24968, FUN_180024968 */
bool FUN_180024968(void)

{
  undefined8 uVar1;
  
  uVar1 = FUN_180024ab0(0);
  return (char)uVar1 != '\0';
}

/* RVA 0x24980, FUN_180024980 */
undefined1 FUN_180024980(void)

{
  char cVar1;
  
  cVar1 = FUN_180025528();
  if (cVar1 != '\0') {
    cVar1 = FUN_180025528();
    if (cVar1 != '\0') {
      return 1;
    }
    FUN_18002552c();
  }
  return 0;
}

/* RVA 0x249a8, FUN_1800249a8 */
undefined1 FUN_1800249a8(void)

{
  FUN_18002552c();
  FUN_18002552c();
  return 1;
}

/* RVA 0x249c0, __scrt_dllmain_exception_filter */
/* Library Function - Single Match
    __scrt_dllmain_exception_filter
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __scrt_dllmain_exception_filter
               (undefined8 param_1,int param_2,undefined8 param_3,undefined *param_4,
               undefined4 param_5,undefined8 param_6)

{
  bool bVar1;
  undefined7 extraout_var;
  
  bVar1 = __scrt_is_ucrt_dll_in_use();
  if (((int)CONCAT71(extraout_var,bVar1) == 0) && (param_2 == 1)) {
    (*(code *)PTR__guard_dispatch_icall_180026268)(param_1,0,param_3);
  }
  _seh_filter_dll(param_5,param_6);
  return;
}

/* RVA 0x24a20, __scrt_dllmain_uninitialize_c */
/* Library Function - Single Match
    __scrt_dllmain_uninitialize_c
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void __scrt_dllmain_uninitialize_c(void)

{
  bool bVar1;
  undefined7 extraout_var;
  undefined8 uVar2;
  
  bVar1 = __scrt_is_ucrt_dll_in_use();
  if ((int)CONCAT71(extraout_var,bVar1) != 0) {
    _execute_onexit_table(&DAT_180034948);
    return;
  }
  uVar2 = FUN_180025538();
  if ((int)uVar2 == 0) {
    _cexit();
  }
  return;
}

/* RVA 0x24a50, FUN_180024a50 */
void FUN_180024a50(void)

{
  FUN_180025534();
  FUN_180025534();
  return;
}

/* RVA 0x24a64, __scrt_initialize_crt */
/* Library Function - Single Match
    __scrt_initialize_crt
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

longlong __scrt_initialize_crt(int param_1)

{
  char cVar1;
  uint7 extraout_var;
  uint7 uVar2;
  undefined7 extraout_var_00;
  uint7 extraout_var_01;
  
  if (param_1 == 0) {
    DAT_180034940 = 1;
  }
  FUN_1800251f4();
  cVar1 = FUN_180025524();
  uVar2 = extraout_var;
  if (cVar1 != '\0') {
    cVar1 = FUN_180025524();
    if (cVar1 != '\0') {
      return CONCAT71(extraout_var_00,1);
    }
    FUN_180025530();
    uVar2 = extraout_var_01;
  }
  return (ulonglong)uVar2 << 8;
}

/* RVA 0x24ab0, FUN_180024ab0 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_180024ab0(uint param_1)

{
  bool bVar1;
  ulonglong in_RAX;
  undefined7 extraout_var;
  
  if (DAT_180034941 == '\0') {
    if (1 < param_1) {
                    /* WARNING: Subroutine does not return */
      FUN_180024ca8(5);
    }
    bVar1 = __scrt_is_ucrt_dll_in_use();
    if (((int)CONCAT71(extraout_var,bVar1) == 0) || (param_1 != 0)) {
      in_RAX = 0xffffffffffffffff;
      DAT_180034948 = _DAT_180029e90;
      uRam0000000180034950 = _UNK_180029e98;
      _DAT_180034958 = 0xffffffffffffffff;
      _DAT_180034960 = _DAT_180029e90;
      uRam0000000180034968 = _UNK_180029e98;
      _DAT_180034970 = 0xffffffffffffffff;
    }
    else {
      in_RAX = _initialize_onexit_table(&DAT_180034948);
      if (((int)in_RAX != 0) ||
         (in_RAX = _initialize_onexit_table(&DAT_180034960), (int)in_RAX != 0)) {
        return in_RAX & 0xffffffffffffff00;
      }
    }
    DAT_180034941 = '\x01';
  }
  return CONCAT71((int7)(in_RAX >> 8),1);
}

/* RVA 0x24b3c, FUN_180024b3c */
ulonglong FUN_180024b3c(longlong param_1)

{
  ulonglong uVar1;
  uint7 uVar2;
  longlong lVar3;
  longlong lVar4;
  
  uVar1 = 0x5a4d;
  if (IMAGE_DOS_HEADER_180000000.e_magic == (char  [2])0x5a4d) {
    lVar3 = (longlong)(int)IMAGE_DOS_HEADER_180000000.e_lfanew;
    if ((*(int *)(lVar3 + 0x180000000) == 0x4550) &&
       (uVar1 = 0x20b,
       *(short *)((longlong)IMAGE_DOS_HEADER_180000000.e_res_4_ + lVar3 + -4) == 0x20b)) {
      lVar4 = (ulonglong)*(ushort *)((longlong)IMAGE_DOS_HEADER_180000000.e_res_4_ + lVar3 + -8) +
              0x18 + lVar3 + 0x180000000;
      uVar1 = (ulonglong)*(ushort *)(IMAGE_DOS_HEADER_180000000.e_magic + lVar3 + 6);
      lVar3 = lVar4 + uVar1 * 0x28;
      for (; lVar4 != lVar3; lVar4 = lVar4 + 0x28) {
        if (((ulonglong)*(uint *)(lVar4 + 0xc) <= param_1 - 0x180000000U) &&
           (uVar1 = (ulonglong)(*(int *)(lVar4 + 8) + *(uint *)(lVar4 + 0xc)),
           param_1 - 0x180000000U < uVar1)) goto LAB_180024bb2;
      }
      lVar4 = 0;
LAB_180024bb2:
      if (lVar4 == 0) {
        return uVar1 & 0xffffffffffffff00;
      }
      uVar2 = (uint7)(uVar1 >> 8);
      if (*(int *)(lVar4 + 0x24) < 0) {
        return (ulonglong)uVar2 << 8;
      }
      return CONCAT71(uVar2,1);
    }
  }
  return uVar1 & 0xffffffffffffff00;
}

/* RVA 0x24bd4, __scrt_release_startup_lock */
/* Library Function - Single Match
    __scrt_release_startup_lock
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void __scrt_release_startup_lock(char param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  
  bVar1 = __scrt_is_ucrt_dll_in_use();
  if ((CONCAT31(extraout_var,bVar1) != 0) && (param_1 == '\0')) {
    LOCK();
    DAT_180034938 = 0;
    UNLOCK();
  }
  return;
}

/* RVA 0x24bf8, __scrt_uninitialize_crt */
/* Library Function - Single Match
    __scrt_uninitialize_crt
   
   Library: Visual Studio 2019 Release */

undefined1 __scrt_uninitialize_crt(undefined8 param_1,char param_2)

{
  if ((DAT_180034940 == '\0') || (param_2 == '\0')) {
    FUN_180025530();
    FUN_180025530();
  }
  return 1;
}

/* RVA 0x24c24, _onexit */
/* Library Function - Single Match
    _onexit
   
   Library: Visual Studio 2019 Release */

_onexit_t __cdecl _onexit(_onexit_t _Func)

{
  int iVar1;
  _onexit_t p_Var2;
  
  if (DAT_180034948 == -1) {
    iVar1 = _crt_atexit();
  }
  else {
    iVar1 = _register_onexit_function(&DAT_180034948);
  }
  p_Var2 = (_onexit_t)0x0;
  if (iVar1 == 0) {
    p_Var2 = _Func;
  }
  return p_Var2;
}

/* RVA 0x24c80, atexit */
/* Library Function - Single Match
    atexit
   
   Library: Visual Studio 2019 Release */

int __cdecl atexit(_func_5014 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = _onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}

/* RVA 0x24c98, FUN_180024c98 */
undefined * FUN_180024c98(void)

{
  return &DAT_1800372b8;
}

/* RVA 0x24ca0, FUN_180024ca0 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_180024ca0(void)

{
  _DAT_180034978 = 0;
  return;
}

/* RVA 0x24ca8, FUN_180024ca8 */
void FUN_180024ca8(undefined4 param_1)

{
  code *pcVar1;
  BOOL BVar2;
  LONG LVar3;
  PRUNTIME_FUNCTION FunctionEntry;
  undefined1 *puVar4;
  undefined8 unaff_retaddr;
  undefined8 local_res10;
  undefined1 local_res18 [8];
  undefined1 local_res20 [8];
  undefined1 auStack_5c8 [8];
  undefined1 auStack_5c0 [232];
  undefined1 local_4d8 [152];
  undefined1 *local_440;
  DWORD64 local_3e0;
  
  BVar2 = IsProcessorFeaturePresent(0x17);
  puVar4 = auStack_5c8;
  if (BVar2 != 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(param_1);
    puVar4 = auStack_5c0;
  }
  *(undefined8 *)(puVar4 + -8) = 0x180024cdc;
  FUN_180024ca0();
  *(undefined8 *)(puVar4 + -8) = 0x180024ced;
  memset(local_4d8,0,0x4d0);
  *(undefined8 *)(puVar4 + -8) = 0x180024cf7;
  RtlCaptureContext(local_4d8);
  *(undefined8 *)(puVar4 + -8) = 0x180024d11;
  FunctionEntry = RtlLookupFunctionEntry(local_3e0,&local_res10,(PUNWIND_HISTORY_TABLE)0x0);
  if (FunctionEntry != (PRUNTIME_FUNCTION)0x0) {
    *(undefined8 *)(puVar4 + 0x38) = 0;
    *(undefined1 **)(puVar4 + 0x30) = local_res18;
    *(undefined1 **)(puVar4 + 0x28) = local_res20;
    *(undefined1 **)(puVar4 + 0x20) = local_4d8;
    *(undefined8 *)(puVar4 + -8) = 0x180024d52;
    RtlVirtualUnwind(0,local_res10,local_3e0,FunctionEntry,*(PCONTEXT *)(puVar4 + 0x20),
                     *(PVOID **)(puVar4 + 0x28),*(PDWORD64 *)(puVar4 + 0x30),
                     *(PKNONVOLATILE_CONTEXT_POINTERS *)(puVar4 + 0x38));
  }
  local_440 = local_res18 + -0x10;
  *(undefined8 *)(puVar4 + -8) = 0x180024d84;
  memset(puVar4 + 0x50,0,0x98);
  *(undefined8 *)(puVar4 + 0x60) = unaff_retaddr;
  *(undefined4 *)(puVar4 + 0x50) = 0x40000015;
  *(undefined4 *)(puVar4 + 0x54) = 1;
  *(undefined8 *)(puVar4 + -8) = 0x180024da6;
  BVar2 = IsDebuggerPresent();
  *(undefined1 **)(puVar4 + 0x40) = puVar4 + 0x50;
  *(undefined1 **)(puVar4 + 0x48) = local_4d8;
  *(undefined8 *)(puVar4 + -8) = 0x180024dc7;
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  *(undefined8 *)(puVar4 + -8) = 0x180024dd2;
  LVar3 = UnhandledExceptionFilter((_EXCEPTION_POINTERS *)(puVar4 + 0x40));
  if ((LVar3 == 0) && (BVar2 != 1)) {
    *(undefined8 *)(puVar4 + -8) = 0x180024de2;
    FUN_180024ca0();
  }
  return;
}

/* RVA 0x24df4, __scrt_get_show_window_mode */
/* Library Function - Single Match
    __scrt_get_show_window_mode
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

WORD __scrt_get_show_window_mode(void)

{
  WORD WVar1;
  _STARTUPINFOW local_78;
  
  memset(&local_78,0,0x68);
  GetStartupInfoW(&local_78);
  WVar1 = 10;
  if (((byte)local_78.dwFlags & 1) != 0) {
    WVar1 = local_78.wShowWindow;
  }
  return WVar1;
}

/* RVA 0x24e3c, FUN_180024e3c */
ulonglong FUN_180024e3c(void)

{
  HMODULE pHVar1;
  ulonglong uVar2;
  int *piVar3;
  
  pHVar1 = GetModuleHandleW((LPCWSTR)0x0);
  if ((((pHVar1 == (HMODULE)0x0) || ((short)pHVar1->unused != 0x5a4d)) ||
      (piVar3 = (int *)((longlong)&pHVar1->unused + (longlong)pHVar1[0xf].unused), *piVar3 != 0x4550
      )) || ((pHVar1 = (HMODULE)0x20b, (short)piVar3[6] != 0x20b || ((uint)piVar3[0x21] < 0xf)))) {
    uVar2 = (ulonglong)pHVar1 & 0xffffffffffffff00;
  }
  else {
    uVar2 = CONCAT71(2,piVar3[0x3e] != 0);
  }
  return uVar2;
}

/* RVA 0x24ea4, FUN_180024ea4 */
undefined8 FUN_180024ea4(undefined8 *param_1)

{
  int *piVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  
  piVar1 = (int *)*param_1;
  if ((*piVar1 == -0x1f928c9d) && (piVar1[6] == 4)) {
    if ((piVar1[8] + 0xe66cfae0U < 3) || (piVar1[8] == 0x1994000)) {
      puVar3 = (undefined8 *)__current_exception();
      *puVar3 = piVar1;
      uVar2 = param_1[1];
      puVar3 = (undefined8 *)__current_exception_context();
      *puVar3 = uVar2;
                    /* WARNING: Subroutine does not return */
      terminate();
    }
  }
  return 0;
}

/* RVA 0x24f00, FUN_180024f00 */
void FUN_180024f00(void)

{
  longlong *plVar1;
  
  for (plVar1 = &DAT_18002a600; plVar1 < &DAT_18002a600; plVar1 = plVar1 + 1) {
    if (*plVar1 != 0) {
      (*(code *)PTR__guard_dispatch_icall_180026268)();
    }
  }
  return;
}

/* RVA 0x24f3c, FUN_180024f3c */
void FUN_180024f3c(void)

{
  longlong *plVar1;
  
  for (plVar1 = &DAT_18002a610; plVar1 < &DAT_18002a610; plVar1 = plVar1 + 1) {
    if (*plVar1 != 0) {
      (*(code *)PTR__guard_dispatch_icall_180026268)();
    }
  }
  return;
}

/* RVA 0x24f78, _guard_check_icall */
void _guard_check_icall(void)

{
  return;
}

/* RVA 0x24fc8, FUN_180024fc8 */
void FUN_180024fc8(undefined *param_1)

{
  if ((param_1 == &DAT_18002a100) && (DAT_180026280 != (code *)0x0)) {
    (*DAT_180026280)();
  }
  return;
}

/* RVA 0x25004, FUN_180025004 */
void FUN_180025004(void)

{
  if (DAT_180026280 != (code *)0x0) {
    (*DAT_180026280)();
  }
  return;
}

/* RVA 0x25024, FUN_180025024 */
void FUN_180025024(undefined *param_1)

{
  if ((param_1 == &DAT_18002a100) && (DAT_180034980 != 0)) {
    (*(code *)PTR__guard_dispatch_icall_180026268)();
  }
  return;
}

/* RVA 0x2505c, FUN_18002505c */
void FUN_18002505c(void)

{
  if (DAT_180034980 != 0) {
    (*(code *)PTR__guard_dispatch_icall_180026268)();
  }
  return;
}

/* RVA 0x25118, FUN_180025118 */
void FUN_180025118(undefined *param_1,longlong param_2,undefined *param_3)

{
  if (((param_3 < param_1 + (-0x18002a100 - param_2)) && (param_1 == &DAT_18002a100)) &&
     (DAT_180026280 != (code *)0x0)) {
    (*DAT_180026280)();
  }
  return;
}

/* RVA 0x2516c, FUN_18002516c */
void FUN_18002516c(undefined *param_1,longlong param_2,undefined *param_3)

{
  if (((param_3 < param_1 + (-0x18002a100 - param_2)) && (param_1 == &DAT_18002a100)) &&
     (DAT_180034980 != 0)) {
    (*(code *)PTR__guard_dispatch_icall_180026268)();
  }
  return;
}

/* RVA 0x251f4, FUN_1800251f4 */
/* WARNING: Removing unreachable block (ram,0x0001800252be) */
/* WARNING: Removing unreachable block (ram,0x00018002522e) */
/* WARNING: Removing unreachable block (ram,0x000180025207) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_1800251f4(void)

{
  int *piVar1;
  uint *puVar2;
  longlong lVar3;
  uint uVar4;
  undefined8 uVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  byte in_XCR0;
  
  piVar1 = (int *)cpuid_basic_info(0);
  uVar8 = 0;
  puVar2 = (uint *)cpuid_Version_info(1);
  uVar4 = puVar2[3];
  if ((piVar1[2] == 0x49656e69 && piVar1[3] == 0x6c65746e) && piVar1[1] == 0x756e6547) {
    _DAT_180032198 = 0xffffffffffffffff;
    uVar7 = *puVar2 & 0xfff3ff0;
    _DAT_180032190 = 0x8000;
    if ((((uVar7 == 0x106c0) || (uVar7 == 0x20660)) || (uVar7 == 0x20670)) ||
       ((uVar7 - 0x30650 < 0x21 &&
        ((0x100010001U >> ((ulonglong)(uVar7 - 0x30650) & 0x3f) & 1) != 0)))) {
      DAT_180034988 = DAT_180034988 | 1;
    }
  }
  if (6 < *piVar1) {
    lVar3 = cpuid_Extended_Feature_Enumeration_info(7);
    uVar8 = *(uint *)(lVar3 + 4);
    if ((uVar8 >> 9 & 1) != 0) {
      DAT_180034988 = DAT_180034988 | 2;
    }
  }
  _DAT_180032188 = 1;
  DAT_18003218c = 2;
  if ((uVar4 >> 0x14 & 1) != 0) {
    _DAT_180032188 = 2;
    DAT_18003218c = 6;
    if (((uVar4 >> 0x1b & 1) != 0) && ((uVar4 >> 0x1c & 1) != 0)) {
      uVar5 = xinuse(0);
      bVar6 = in_XCR0 & (byte)uVar5;
      if ((bVar6 & 6) == 6) {
        _DAT_180032188 = 3;
        DAT_18003218c = 0xe;
        if ((uVar8 & 0x20) != 0) {
          _DAT_180032188 = 5;
          DAT_18003218c = 0x2e;
          if (((uVar8 & 0xd0030000) == 0xd0030000) && ((bVar6 & 0xe0) == 0xe0)) {
            DAT_18003218c = 0x6e;
            _DAT_180032188 = 6;
          }
        }
      }
    }
  }
  return 0;
}

/* RVA 0x253a0, FUN_1800253a0 */
undefined8 FUN_1800253a0(void)

{
  return 1;
}

/* RVA 0x253a8, __scrt_is_ucrt_dll_in_use */
/* Library Function - Single Match
    __scrt_is_ucrt_dll_in_use
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

bool __scrt_is_ucrt_dll_in_use(void)

{
  return DAT_1800321a0 != 0;
}

/* RVA 0x253c0, strchr */
char * __cdecl strchr(char *_Str,int _Val)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800253c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = strchr(_Str,_Val);
  return pcVar1;
}

/* RVA 0x253c6, strstr */
char * __cdecl strstr(char *_Str,char *_SubStr)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800253c6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = strstr(_Str,_SubStr);
  return pcVar1;
}

/* RVA 0x253d2, __std_type_info_destroy_list */
void __std_type_info_destroy_list(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800253d2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __std_type_info_destroy_list();
  return;
}

/* RVA 0x253d8, __current_exception */
void __current_exception(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800253d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __current_exception();
  return;
}

/* RVA 0x253de, __current_exception_context */
void __current_exception_context(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800253de. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __current_exception_context();
  return;
}

/* RVA 0x253e4, memset */
void * __cdecl memset(void *_Dst,int _Val,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800253e4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memset(_Dst,_Val,_Size);
  return pvVar1;
}

/* RVA 0x253f6, pow */
double __cdecl pow(double _X,double _Y)

{
  double dVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800253f6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  dVar1 = pow(_X,_Y);
  return dVar1;
}

/* RVA 0x253fc, strcmp */
int __cdecl strcmp(char *_Str1,char *_Str2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800253fc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = strcmp(_Str1,_Str2);
  return iVar1;
}

/* RVA 0x25420, strcat */
char * __cdecl strcat(char *_Dest,char *_Source)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180025420. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = strcat(_Dest,_Source);
  return pcVar1;
}

/* RVA 0x25426, strcpy */
char * __cdecl strcpy(char *_Dest,char *_Source)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180025426. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = strcpy(_Dest,_Source);
  return pcVar1;
}

/* RVA 0x2542c, strlen */
size_t __cdecl strlen(char *_Str)

{
  size_t sVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018002542c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  sVar1 = strlen(_Str);
  return sVar1;
}

/* RVA 0x2546e, _initterm */
void _initterm(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018002546e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _initterm();
  return;
}

/* RVA 0x25474, _initterm_e */
void _initterm_e(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180025474. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _initterm_e();
  return;
}

/* RVA 0x2547a, _seh_filter_dll */
void _seh_filter_dll(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018002547a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _seh_filter_dll();
  return;
}

/* RVA 0x25480, _configure_narrow_argv */
void _configure_narrow_argv(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180025480. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _configure_narrow_argv();
  return;
}

/* RVA 0x25486, _initialize_narrow_environment */
void _initialize_narrow_environment(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180025486. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _initialize_narrow_environment();
  return;
}

/* RVA 0x2548c, _initialize_onexit_table */
void _initialize_onexit_table(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018002548c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _initialize_onexit_table();
  return;
}

/* RVA 0x25492, _register_onexit_function */
void _register_onexit_function(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180025492. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _register_onexit_function();
  return;
}

/* RVA 0x25498, _execute_onexit_table */
void _execute_onexit_table(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180025498. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _execute_onexit_table();
  return;
}

/* RVA 0x2549e, _crt_atexit */
void _crt_atexit(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018002549e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _crt_atexit();
  return;
}

/* RVA 0x254aa, _cexit */
void __cdecl _cexit(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800254aa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _cexit();
  return;
}

/* RVA 0x254b0, terminate */
void terminate(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800254b0. Too many branches */
                    /* WARNING: Subroutine does not return */
                    /* WARNING: Treating indirect jump as call */
  terminate();
  return;
}

/* RVA 0x25524, FUN_180025524 */
undefined1 FUN_180025524(void)

{
  return 1;
}

/* RVA 0x25528, FUN_180025528 */
undefined1 FUN_180025528(void)

{
  return 1;
}

/* RVA 0x2552c, FUN_18002552c */
undefined1 FUN_18002552c(void)

{
  return 1;
}

/* RVA 0x25530, FUN_180025530 */
undefined1 FUN_180025530(void)

{
  return 1;
}

/* RVA 0x25534, FUN_180025534 */
undefined1 FUN_180025534(void)

{
  return 1;
}

/* RVA 0x25538, FUN_180025538 */
undefined8 FUN_180025538(void)

{
  return 0;
}

/* RVA 0x25560, _guard_dispatch_icall */
/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000180025560. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

/* RVA 0x25580, _guard_dispatch_icall */
/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  (*(code *)PTR__guard_dispatch_icall_180026268)();
  return;
}

/* RVA 0x25586, FUN_180025586 */
void FUN_180025586(undefined8 param_1,longlong param_2)

{
  __scrt_release_startup_lock(*(char *)(param_2 + 0x40));
  return;
}

/* RVA 0x2559d, FUN_18002559d */
void FUN_18002559d(undefined8 param_1,longlong param_2)

{
  __scrt_release_startup_lock(*(char *)(param_2 + 0x20));
  return;
}

/* RVA 0x255b6, FUN_1800255b6 */
void FUN_1800255b6(void)

{
  FUN_180024a50();
  return;
}

/* RVA 0x255ca, FUN_1800255ca */
void FUN_1800255ca(undefined8 *param_1,longlong param_2)

{
  __scrt_dllmain_exception_filter
            (*(undefined8 *)(param_2 + 0x60),*(int *)(param_2 + 0x68),
             *(undefined8 *)(param_2 + 0x70),FUN_18002435c,*(undefined4 *)*param_1,param_1);
  return;
}

/* RVA 0x25600, FUN_180025600 */
bool FUN_180025600(undefined8 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}

