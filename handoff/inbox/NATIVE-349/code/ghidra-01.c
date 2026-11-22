/* RVA 0x1000, FUN_180001000 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180001000(char *param_1,char *param_2)

{
  char *pcVar1;
  char cVar2;
  char cVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  int iVar7;
  char *pcVar8;
  longlong lVar9;
  undefined8 uVar10;
  longlong lVar11;
  longlong lVar12;
  undefined *puVar13;
  char *pcVar14;
  double *pdVar15;
  int iVar16;
  double dVar17;
  double dVar18;
  longlong lVar19;
  undefined1 auStackY_6a8 [32];
  int local_678 [2];
  double local_670;
  char local_668 [24];
  double local_650 [77];
  double local_3e8;
  double local_3e0;
  char local_3d8 [24];
  double local_3c0 [77];
  char local_158 [32];
  char local_138 [208];
  ulonglong local_68;
  
  local_68 = DAT_180032178 ^ (ulonglong)auStackY_6a8;
  pcVar8 = param_1;
  do {
    cVar2 = *pcVar8;
    pcVar8[(longlong)(local_138 + -(longlong)param_1)] = cVar2;
    pcVar8 = pcVar8 + 1;
  } while (cVar2 != '\0');
  FUN_1800238a0(local_138," ",&DAT_1800264e3);
  dVar4 = DAT_180026638;
  lVar19 = 0;
  local_670 = DAT_180026638;
  local_3e0 = DAT_180026638;
  local_678[0] = 0;
  dVar17 = 4.94065645841247e-324;
  local_3e8._0_4_ = 0;
  FUN_180001780(local_678,(int *)&local_3e8,local_138,1,DAT_180026638);
  FUN_180002ee0(local_678,(int *)&local_3e8);
  FUN_180002ee0((int *)&local_3e8,local_678);
  FUN_1800032f0(local_678);
  FUN_1800032f0((int *)&local_3e8);
  FUN_1800026c0(local_678);
  FUN_1800026c0((int *)&local_3e8);
  if ((local_678[0] == 1) && (local_3e8._0_4_ == 1)) {
    pcVar8 = local_668;
    lVar11 = -(longlong)pcVar8;
    do {
      cVar2 = *pcVar8;
      cVar3 = pcVar8[(longlong)(local_3d8 + lVar11)];
      if (cVar2 != cVar3) break;
      pcVar8 = pcVar8 + 1;
    } while (cVar3 != '\0');
    if (cVar2 != cVar3) goto LAB_180001137;
  }
  else {
LAB_180001137:
    FUN_180002280(local_678,&local_3e8);
  }
  FUN_180002ae0(local_678);
  FUN_180002ae0((int *)&local_3e8);
  lVar11 = -(longlong)param_1;
  do {
    cVar2 = *param_1;
    param_1[(longlong)(local_158 + lVar11)] = cVar2;
    param_1 = param_1 + 1;
  } while (cVar2 != '\0');
  iVar16 = 0;
  lVar11 = -1;
  do {
    lVar9 = lVar11 + 1;
    lVar12 = lVar11 + 1;
    lVar11 = lVar9;
  } while (local_158[lVar12] != '\0');
  if (0 < (int)lVar9) {
    pcVar8 = local_158;
    do {
      if ((byte)(*pcVar8 + 0x9fU) < 0x1a) {
        *pcVar8 = *pcVar8 + -0x20;
      }
      iVar16 = iVar16 + 1;
      pcVar8 = pcVar8 + 1;
      lVar11 = -1;
      do {
        lVar9 = lVar11 + 1;
        lVar12 = lVar11 + 1;
        lVar11 = lVar9;
      } while (local_158[lVar12] != '\0');
    } while (iVar16 < (int)lVar9);
  }
  lVar11 = 0;
  do {
    lVar12 = lVar11 + 1;
    if (local_158[lVar11] != (&DAT_1800264e8)[lVar11]) {
      iVar16 = strcmp(local_158,"KCAL/KMOL");
      if (iVar16 != 0) {
        lVar11 = 0;
        goto LAB_180001260;
      }
      break;
    }
    lVar11 = lVar12;
  } while (lVar12 != 8);
  uVar10 = 0x4c4f4d2f4c4143;
  goto LAB_18000120e;
  while (lVar11 = lVar12, lVar12 != 6) {
LAB_180001260:
    lVar12 = lVar11 + 1;
    if (local_158[lVar11] != (&DAT_1800265f4)[lVar11]) {
      pcVar8 = "KJ/KMOL";
      lVar11 = 0;
      goto LAB_180001291;
    }
  }
  uVar10 = 0x4c4f4d4b2f4a4b;
  goto LAB_18000120e;
LAB_180001315:
  do {
    if (*(char *)(pdVar15 + -3) != '\0') {
      if (iVar16 != 0) {
        FUN_180002d90(pcVar14,&DAT_18002651c,pcVar8,dVar17);
        pcVar14 = pcVar14 + 1;
      }
      lVar11 = (longlong)iVar16 * 0x20;
      pcVar8 = local_668 + lVar11;
      if (((*pcVar8 == 'M') && (local_668[lVar11 + 1] == '\0')) ||
         ((*pcVar8 == 'F' && ((local_668[lVar11 + 1] == 'T' && (local_668[lVar11 + 2] == '\0'))))))
      {
        dVar18 = *pdVar15;
        if (dVar18 == dVar6) {
          FUN_180002d90(pcVar14,&DAT_180026520,pcVar8,dVar17);
        }
        else {
          if (dVar18 != dVar5) goto joined_r0x0001800013ad;
          FUN_180002d90(pcVar14,&DAT_180026528,pcVar8,dVar17);
        }
      }
      else {
        dVar18 = *pdVar15;
joined_r0x0001800013ad:
        if (dVar18 == dVar4) {
          FUN_180002d90(pcVar14,&DAT_180026538,pcVar8,dVar17);
        }
        else {
          FUN_180002d90(pcVar14,"%s**%G",pcVar8,dVar18);
          dVar17 = dVar18;
        }
      }
      lVar11 = -1;
      do {
        lVar11 = lVar11 + 1;
      } while (pcVar14[lVar11] != '\0');
      pcVar14 = pcVar14 + (int)lVar11;
      iVar7 = local_678[0];
    }
    iVar16 = iVar16 + 1;
    pdVar15 = pdVar15 + 4;
  } while (iVar16 < iVar7);
LAB_1800013f2:
  iVar16 = 0;
  if (0 < local_3e8._0_4_) {
    pdVar15 = local_3c0;
    iVar7 = local_3e8._0_4_;
    do {
      if (*(char *)(pdVar15 + -3) != '\0') {
        puVar13 = &DAT_18002651c;
        pcVar1 = pcVar14 + 1;
        if (iVar16 == 0) {
          puVar13 = &DAT_18002653c;
        }
        FUN_180002d90(pcVar14,puVar13,pcVar8,dVar17);
        lVar11 = (longlong)iVar16 * 0x20;
        pcVar8 = local_3d8 + lVar11;
        if (((*pcVar8 == 'M') && (local_3d8[lVar11 + 1] == '\0')) ||
           ((*pcVar8 == 'F' && ((local_3d8[lVar11 + 1] == 'T' && (local_3d8[lVar11 + 2] == '\0')))))
           ) {
          dVar18 = *pdVar15;
          if (dVar18 == dVar6) {
            FUN_180002d90(pcVar1,&DAT_180026520,pcVar8,dVar17);
          }
          else {
            if (dVar18 != dVar5) goto joined_r0x0001800014e6;
            FUN_180002d90(pcVar1,&DAT_180026528,pcVar8,dVar17);
          }
        }
        else {
          dVar18 = *pdVar15;
joined_r0x0001800014e6:
          if (dVar18 == dVar4) {
            FUN_180002d90(pcVar1,&DAT_180026538,pcVar8,dVar17);
          }
          else {
            FUN_180002d90(pcVar1,"%s**%G",pcVar8,dVar18);
            dVar17 = dVar18;
          }
        }
        lVar11 = -1;
        do {
          lVar11 = lVar11 + 1;
        } while (pcVar1[lVar11] != '\0');
        pcVar14 = pcVar1 + (int)lVar11;
        iVar7 = local_3e8._0_4_;
      }
      iVar16 = iVar16 + 1;
      pdVar15 = pdVar15 + 4;
    } while (iVar16 < iVar7);
  }
  iVar16 = 0;
  lVar11 = -1;
  do {
    lVar11 = lVar11 + 1;
  } while (param_2[lVar11] != '\0');
  if (0 < (int)lVar11) {
    pcVar8 = param_2;
    do {
      if ((byte)(*pcVar8 + 0x9fU) < 0x1a) {
        *pcVar8 = *pcVar8 + -0x20;
      }
      iVar16 = iVar16 + 1;
      lVar11 = -1;
      pcVar8 = pcVar8 + 1;
      do {
        lVar11 = lVar11 + 1;
      } while (param_2[lVar11] != '\0');
    } while (iVar16 < (int)lVar11);
  }
  iVar16 = strcmp("J**0.5/M**1.5",param_2);
  if (iVar16 == 0) {
    *(undefined8 *)param_2 = DAT_180026550;
    *(undefined4 *)(param_2 + 8) = DAT_180026558;
    return;
  }
  iVar16 = strcmp("BTU**0.5/FT**1.5",param_2);
  if (iVar16 == 0) {
    *(undefined8 *)param_2 = DAT_180026578;
    *(undefined4 *)(param_2 + 8) = DAT_180026580;
    *(undefined2 *)(param_2 + 0xc) = DAT_180026584;
    param_2[0xe] = DAT_180026586;
    return;
  }
  iVar16 = strcmp("KMOL/KMOL",param_2);
  if (iVar16 != 0) {
    lVar11 = 0;
    do {
      lVar12 = lVar11 + 1;
      if ((&DAT_180026594)[lVar11] != param_2[lVar11]) {
        lVar11 = 0;
        do {
          lVar12 = lVar11 + 1;
          if ((&DAT_1800265ac)[lVar11] != param_2[lVar11]) {
            iVar16 = strcmp("KCAL/KMOL-K",param_2);
            if (iVar16 == 0) {
              *(undefined8 *)param_2 = DAT_180026608;
              *(undefined2 *)(param_2 + 8) = DAT_180026610;
              return;
            }
            do {
              lVar11 = lVar19 + 1;
              if ((&DAT_180026618)[lVar19] != param_2[lVar19]) {
                return;
              }
              lVar19 = lVar11;
            } while (lVar11 != 8);
            *(undefined8 *)param_2 = DAT_180026620;
            *(undefined2 *)(param_2 + 8) = DAT_180026628;
            return;
          }
          lVar11 = lVar12;
        } while (lVar12 != 4);
        *(undefined8 *)param_2 = s_VOL_FRAC_1800265b0._0_8_;
        param_2[8] = s_VOL_FRAC_1800265b0[8];
        return;
      }
      lVar11 = lVar12;
    } while (lVar12 != 6);
    *(undefined8 *)param_2 = s_MASS_FRAC_1800265a0._0_8_;
    *(undefined2 *)(param_2 + 8) = s_MASS_FRAC_1800265a0._8_2_;
    return;
  }
LAB_180001745:
  *(undefined8 *)param_2 = s_MOLE_FRAC_180026510._0_8_;
  *(undefined2 *)(param_2 + 8) = s_MOLE_FRAC_180026510._8_2_;
  return;
  while (lVar11 = lVar12, lVar12 != 8) {
LAB_180001291:
    lVar12 = lVar11 + 1;
    if (local_158[lVar11] != (&DAT_180026600)[lVar11]) {
      iVar16 = strcmp(local_158,"MOLE/MOLE");
      dVar6 = DAT_180026648;
      dVar5 = DAT_180026640;
      if (iVar16 == 0) goto LAB_180001745;
      iVar16 = 0;
      pcVar14 = param_2;
      if (local_678[0] < 1) goto LAB_1800013f2;
      pdVar15 = local_650;
      iVar7 = local_678[0];
      goto LAB_180001315;
    }
  }
  uVar10 = 0x4c4f4d4b2f4a4b;
LAB_18000120e:
  *(undefined8 *)param_2 = uVar10;
  return;
}

/* RVA 0x1770, FUN_180001770 */
undefined * FUN_180001770(void)

{
  return &DAT_1800372b0;
}

/* RVA 0x1780, FUN_180001780 */
void FUN_180001780(int *param_1,int *param_2,char *param_3,int param_4,double param_5)

{
  char cVar1;
  undefined8 uVar2;
  char *pcVar3;
  int *piVar4;
  longlong lVar5;
  longlong lVar6;
  int iVar7;
  double dVar8;
  double dVar9;
  char *local_48;
  char *local_40 [5];
  
  lVar6 = -1;
  lVar5 = -1;
  do {
    lVar5 = lVar5 + 1;
  } while (param_3[lVar5] != '\0');
  uVar2 = FUN_180002df0((longlong)param_3,(int)lVar5,(longlong *)local_40,(longlong *)&local_48);
  cVar1 = (char)uVar2;
  do {
    if (cVar1 == ' ') {
      if ((*param_3 == '(') && (param_3[lVar5 + -1] == ')')) {
        FUN_180002880(param_1,param_2,(longlong)param_3,param_4,param_5,(int)lVar5);
      }
      else {
        FUN_1800021a0(param_3,local_40,(double *)&local_48);
        if (param_4 == 1) {
          piVar4 = param_1 + (longlong)*param_1 * 8 + 4;
          do {
            cVar1 = *local_40[0];
            local_40[0] = local_40[0] + 1;
            *(char *)piVar4 = cVar1;
            piVar4 = (int *)((longlong)piVar4 + 1);
          } while (cVar1 != '\0');
          *(double *)(param_1 + (longlong)*param_1 * 8 + 10) = (double)local_48 * param_5;
          *param_1 = *param_1 + 1;
        }
        else if (param_4 == -1) {
          piVar4 = param_2 + (longlong)*param_2 * 8 + 4;
          do {
            cVar1 = *local_40[0];
            local_40[0] = local_40[0] + 1;
            *(char *)piVar4 = cVar1;
            piVar4 = (int *)((longlong)piVar4 + 1);
          } while (cVar1 != '\0');
          *(double *)(param_2 + (longlong)*param_2 * 8 + 10) = (double)local_48 * param_5;
          *param_2 = *param_2 + 1;
        }
      }
      return;
    }
    cVar1 = (char)uVar2;
    if (cVar1 == '*') {
      if (param_4 == 1) {
        iVar7 = 1;
      }
      else {
        if (param_4 != -1) {
          return;
        }
        iVar7 = -1;
      }
      FUN_180001780(param_1,param_2,local_40[0],iVar7,param_5);
      param_4 = 1;
    }
    else {
      if (cVar1 != '/') {
        if (cVar1 != '^') {
          return;
        }
        if (*local_48 == '(') {
          lVar5 = -1;
          do {
            lVar5 = lVar5 + 1;
          } while (local_48[lVar5] != '\0');
          if (local_48[(longlong)(int)lVar5 + -1] == ')') {
            local_48 = local_48 + 1;
          }
        }
        pcVar3 = strchr(local_48,0x2f);
        if (pcVar3 == (char *)0x0) {
          dVar8 = atof(local_48);
        }
        else {
          dVar8 = atof(local_48);
          dVar9 = atof(pcVar3 + 1);
          dVar8 = dVar8 / dVar9;
        }
        do {
          lVar6 = lVar6 + 1;
        } while (local_40[0][lVar6] != '\0');
        FUN_180002880(param_1,param_2,(longlong)local_40[0],param_4,dVar8 * param_5,(int)lVar6);
        return;
      }
      if (param_4 == 1) {
        iVar7 = 1;
      }
      else {
        if (param_4 != -1) {
          return;
        }
        iVar7 = -1;
      }
      FUN_180001780(param_1,param_2,local_40[0],iVar7,param_5);
      param_4 = -1;
    }
    param_3 = local_48;
    lVar5 = -1;
    do {
      lVar5 = lVar5 + 1;
    } while (local_48[lVar5] != '\0');
    uVar2 = FUN_180002df0((longlong)local_48,(int)lVar5,(longlong *)local_40,(longlong *)&local_48);
    cVar1 = (char)uVar2;
  } while( true );
}

/* RVA 0x1a20, FUN_180001a20 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_180001a20(char *param_1,char *param_2,double *param_3)

{
  char *pcVar1;
  char cVar2;
  char cVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  int iVar7;
  char *pcVar8;
  longlong lVar9;
  longlong lVar10;
  longlong lVar11;
  undefined *puVar12;
  char *pcVar13;
  double *pdVar14;
  int iVar15;
  double dVar16;
  longlong lVar17;
  double dVar18;
  undefined1 auStackY_6c8 [32];
  double local_688;
  double local_680;
  char local_678 [16];
  double local_668 [78];
  double local_3f8;
  double local_3f0;
  char local_3e8 [16];
  double local_3d8 [78];
  char local_168 [32];
  char local_148 [208];
  ulonglong local_78;
  
  local_78 = DAT_180032178 ^ (ulonglong)auStackY_6c8;
  pcVar8 = param_1;
  do {
    cVar2 = *pcVar8;
    pcVar8[(longlong)(local_148 + -(longlong)param_1)] = cVar2;
    pcVar8 = pcVar8 + 1;
  } while (cVar2 != '\0');
  FUN_1800238a0(local_148," ",&DAT_1800264e3);
  dVar4 = DAT_180026638;
  lVar17 = 0;
  local_680 = DAT_180026638;
  local_3f0 = DAT_180026638;
  local_688._0_4_ = 0;
  dVar16 = 4.94065645841247e-324;
  local_3f8._0_4_ = 0;
  FUN_180001780((int *)&local_688,(int *)&local_3f8,local_148,1,DAT_180026638);
  FUN_180002ee0((int *)&local_688,(int *)&local_3f8);
  FUN_180002ee0((int *)&local_3f8,(int *)&local_688);
  FUN_180003040(&local_688);
  FUN_180003040(&local_3f8);
  FUN_1800026c0((int *)&local_688);
  FUN_1800026c0((int *)&local_3f8);
  if ((local_688._0_4_ == 1) && (local_3f8._0_4_ == 1)) {
    pcVar8 = local_678;
    lVar10 = -(longlong)pcVar8;
    do {
      cVar2 = *pcVar8;
      cVar3 = pcVar8[(longlong)(local_3e8 + lVar10)];
      if (cVar2 != cVar3) break;
      pcVar8 = pcVar8 + 1;
    } while (cVar3 != '\0');
    if (cVar2 == cVar3) goto LAB_180001b78;
  }
  FUN_180002280((int *)&local_688,&local_3f8);
LAB_180001b78:
  FUN_180002ae0((int *)&local_688);
  FUN_180002ae0((int *)&local_3f8);
  *param_3 = 1.0;
  lVar10 = -(longlong)param_1;
  do {
    cVar2 = *param_1;
    param_1[(longlong)(local_168 + lVar10)] = cVar2;
    param_1 = param_1 + 1;
  } while (cVar2 != '\0');
  iVar15 = 0;
  lVar10 = -1;
  do {
    lVar9 = lVar10 + 1;
    lVar11 = lVar10 + 1;
    lVar10 = lVar9;
  } while (local_168[lVar11] != '\0');
  if (0 < (int)lVar9) {
    pcVar8 = local_168;
    do {
      if ((byte)(*pcVar8 + 0x9fU) < 0x1a) {
        *pcVar8 = *pcVar8 + -0x20;
      }
      iVar15 = iVar15 + 1;
      pcVar8 = pcVar8 + 1;
      lVar10 = -1;
      do {
        lVar9 = lVar10 + 1;
        lVar11 = lVar10 + 1;
        lVar10 = lVar9;
      } while (local_168[lVar11] != '\0');
    } while (iVar15 < (int)lVar9);
  }
  pcVar8 = "CAL/MOL";
  lVar10 = 0;
  do {
    lVar11 = lVar10 + 1;
    if (local_168[lVar10] != (&DAT_1800264e8)[lVar10]) {
      iVar15 = strcmp(local_168,"KCAL/KMOL");
      if (iVar15 != 0) {
        iVar15 = strcmp(local_168,"MOLE/MOLE");
        dVar6 = DAT_180026648;
        dVar5 = DAT_180026640;
        if (iVar15 == 0) goto LAB_180002176;
        iVar15 = 0;
        pcVar13 = param_2;
        if (local_688._0_4_ < 1) {
          dVar18 = *param_3;
          goto LAB_180001dfd;
        }
        pdVar14 = local_668 + 1;
        iVar7 = local_688._0_4_;
        goto LAB_180001cf0;
      }
      break;
    }
    lVar10 = lVar11;
  } while (lVar11 != 8);
  builtin_strncpy(param_2,"CAL/MOL",8);
  return;
LAB_180001cf0:
  do {
    if (*(char *)(pdVar14 + -3) != '\0') {
      if (iVar15 != 0) {
        FUN_180002d90(pcVar13,&DAT_18002651c,pcVar8,dVar16);
        pcVar13 = pcVar13 + 1;
      }
      lVar10 = (longlong)iVar15 * 0x20;
      pcVar8 = local_678 + lVar10;
      if (((*pcVar8 == 'M') && (local_678[lVar10 + 1] == '\0')) ||
         ((*pcVar8 == 'F' && ((local_678[lVar10 + 1] == 'T' && (local_678[lVar10 + 2] == '\0'))))))
      {
        dVar18 = *pdVar14;
        if (dVar18 == dVar6) {
          FUN_180002d90(pcVar13,&DAT_180026520,pcVar8,dVar16);
        }
        else {
          if (dVar18 != dVar5) goto joined_r0x000180001d88;
          FUN_180002d90(pcVar13,&DAT_180026528,pcVar8,dVar16);
        }
      }
      else {
        dVar18 = *pdVar14;
joined_r0x000180001d88:
        if (dVar18 == dVar4) {
          FUN_180002d90(pcVar13,&DAT_180026538,pcVar8,dVar16);
        }
        else {
          FUN_180002d90(pcVar13,"%s**%G",pcVar8,dVar18);
          dVar16 = dVar18;
        }
      }
      lVar10 = -1;
      do {
        lVar10 = lVar10 + 1;
      } while (pcVar13[lVar10] != '\0');
      pcVar13 = pcVar13 + (int)lVar10;
      iVar7 = local_688._0_4_;
    }
    iVar15 = iVar15 + 1;
    dVar18 = pdVar14[-1] * *param_3;
    pdVar14 = pdVar14 + 4;
    *param_3 = dVar18;
  } while (iVar15 < iVar7);
LAB_180001dfd:
  iVar15 = 0;
  if (0 < local_3f8._0_4_) {
    pdVar14 = local_3d8 + 1;
    iVar7 = local_3f8._0_4_;
    do {
      if (*(char *)(pdVar14 + -3) != '\0') {
        puVar12 = &DAT_18002651c;
        pcVar1 = pcVar13 + 1;
        if (iVar15 == 0) {
          puVar12 = &DAT_18002653c;
        }
        FUN_180002d90(pcVar13,puVar12,pcVar8,dVar16);
        lVar10 = (longlong)iVar15 * 0x20;
        pcVar8 = local_3e8 + lVar10;
        if (((*pcVar8 == 'M') && (local_3e8[lVar10 + 1] == '\0')) ||
           ((*pcVar8 == 'F' && ((local_3e8[lVar10 + 1] == 'T' && (local_3e8[lVar10 + 2] == '\0')))))
           ) {
          dVar18 = *pdVar14;
          if (dVar18 == dVar6) {
            FUN_180002d90(pcVar1,&DAT_180026520,pcVar8,dVar16);
          }
          else {
            if (dVar18 != dVar5) goto joined_r0x000180001ebe;
            FUN_180002d90(pcVar1,&DAT_180026528,pcVar8,dVar16);
          }
        }
        else {
          dVar18 = *pdVar14;
joined_r0x000180001ebe:
          if (dVar18 == dVar4) {
            FUN_180002d90(pcVar1,&DAT_180026538,pcVar8,dVar16);
          }
          else {
            FUN_180002d90(pcVar1,"%s**%G",pcVar8,dVar18);
            dVar16 = dVar18;
          }
        }
        lVar10 = -1;
        do {
          lVar10 = lVar10 + 1;
        } while (pcVar1[lVar10] != '\0');
        pcVar13 = pcVar1 + (int)lVar10;
        iVar7 = local_3f8._0_4_;
      }
      iVar15 = iVar15 + 1;
      dVar18 = *param_3 / pdVar14[-1];
      pdVar14 = pdVar14 + 4;
      *param_3 = dVar18;
    } while (iVar15 < iVar7);
  }
  *param_3 = (dVar18 * local_680) / local_3f0;
  iVar15 = strcmp("J**0.5/M**1.5",param_2);
  if (iVar15 == 0) {
    *(undefined8 *)param_2 = DAT_180026550;
    *(undefined4 *)(param_2 + 8) = DAT_180026558;
    return;
  }
  iVar15 = strcmp("BTU**0.5/FT**1.5",param_2);
  if (iVar15 == 0) {
    *(undefined8 *)param_2 = DAT_180026578;
    *(undefined4 *)(param_2 + 8) = DAT_180026580;
    *(undefined2 *)(param_2 + 0xc) = DAT_180026584;
    param_2[0xe] = DAT_180026586;
    return;
  }
  iVar15 = strcmp("KMOL/KMOL",param_2);
  if (iVar15 != 0) {
    lVar10 = 0;
    do {
      lVar11 = lVar10 + 1;
      if ((&DAT_180026594)[lVar10] != param_2[lVar10]) {
        lVar10 = 0;
        do {
          lVar11 = lVar10 + 1;
          if ((&DAT_1800265ac)[lVar10] != param_2[lVar10]) {
            lVar10 = 0;
            do {
              lVar11 = lVar10 + 1;
              if ((&DAT_1800265bc)[lVar10] != param_2[lVar10]) {
                do {
                  lVar10 = lVar17 + 1;
                  if ((&DAT_1800265c0)[lVar17] != param_2[lVar17]) {
                    iVar15 = strcmp("KCAL/KMOL-K",param_2);
                    if (iVar15 == 0) {
                      *(undefined8 *)param_2 = DAT_1800265e8;
                      *(undefined2 *)(param_2 + 8) = DAT_1800265f0;
                      param_2[10] = DAT_1800265f2;
                      *param_3 = *param_3 / _DAT_180026650;
                      return;
                    }
                    return;
                  }
                  lVar17 = lVar10;
                } while (lVar10 != 8);
                *(undefined8 *)param_2 = DAT_1800265c8;
                *(undefined2 *)(param_2 + 8) = DAT_1800265d0;
                *param_3 = *param_3 * _DAT_180026650;
                return;
              }
              lVar10 = lVar11;
            } while (lVar11 != 4);
            *(undefined4 *)param_2 = DAT_180026420;
            *(undefined2 *)(param_2 + 4) = DAT_180026424;
            *param_3 = *param_3 / _DAT_180026630;
            return;
          }
          lVar10 = lVar11;
        } while (lVar11 != 4);
        *(undefined8 *)param_2 = s_VOL_FRAC_1800265b0._0_8_;
        param_2[8] = s_VOL_FRAC_1800265b0[8];
        return;
      }
      lVar10 = lVar11;
    } while (lVar11 != 6);
    *(undefined8 *)param_2 = s_MASS_FRAC_1800265a0._0_8_;
    *(undefined2 *)(param_2 + 8) = s_MASS_FRAC_1800265a0._8_2_;
    return;
  }
LAB_180002176:
  *(undefined8 *)param_2 = s_MOLE_FRAC_180026510._0_8_;
  *(undefined2 *)(param_2 + 8) = s_MOLE_FRAC_180026510._8_2_;
  return;
}

/* RVA 0x21a0, FUN_1800021a0 */
void FUN_1800021a0(char *param_1,undefined8 *param_2,double *param_3)

{
  char *pcVar1;
  longlong lVar2;
  char *_Str;
  double dVar3;
  double dVar4;
  
  pcVar1 = strchr(param_1,0x5e);
  if (pcVar1 != (char *)0x0) {
    _Str = pcVar1 + 1;
    *pcVar1 = '\0';
    if (*_Str == '(') {
      lVar2 = -1;
      do {
        lVar2 = lVar2 + 1;
      } while (_Str[lVar2] != '\0');
      if (_Str[(longlong)(int)lVar2 + -1] == ')') {
        _Str = pcVar1 + 2;
      }
    }
    pcVar1 = strchr(_Str,0x2f);
    if (pcVar1 == (char *)0x0) {
      dVar3 = atof(_Str);
    }
    else {
      dVar3 = atof(_Str);
      dVar4 = atof(pcVar1 + 1);
      dVar3 = dVar3 / dVar4;
    }
    *param_3 = dVar3;
    if (dVar3 != 0.0) goto LAB_180002266;
  }
  *param_3 = 1.0;
LAB_180002266:
  *param_2 = param_1;
  return;
}

/* RVA 0x2280, FUN_180002280 */
void FUN_180002280(int *param_1,double *param_2)

{
  double dVar1;
  double dVar2;
  double dVar3;
  char cVar4;
  longlong lVar5;
  int iVar6;
  int *piVar7;
  double *pdVar8;
  int iVar9;
  double *pdVar10;
  double *pdVar11;
  int iVar12;
  int iVar13;
  double *pdVar14;
  double *pdVar15;
  int iVar16;
  int iVar17;
  int local_res8;
  int local_res18;
  int local_res20;
  longlong local_58;
  double *local_50;
  double *local_48;
  double *local_40;
  
  local_res8 = 0;
  if (0 < *param_1) {
    local_58 = 0;
    do {
      iVar16 = 0;
      if (0 < *(int *)param_2) {
        pdVar11 = (double *)(param_1 + local_58 * 8 + 8);
        iVar17 = 0;
        local_50 = (double *)(param_1 + local_58 * 8 + 10);
        local_res18 = local_res8 + 1;
        pdVar14 = param_2 + 5;
        iVar9 = 1;
        pdVar15 = pdVar14;
        pdVar10 = param_2;
        local_res20 = local_res8;
        local_48 = local_50;
        local_40 = pdVar11;
        iVar12 = local_res18;
        iVar13 = local_res8;
        do {
          pdVar8 = pdVar10 + 4;
          piVar7 = param_1 + (longlong)local_res8 * 8 + 4;
          lVar5 = ((longlong)iVar16 * 0x20 + 0x10) - (longlong)piVar7;
          do {
            iVar6 = *piVar7;
            cVar4 = *(char *)((longlong)piVar7 + (longlong)param_2 + lVar5);
            if ((char)iVar6 != cVar4) break;
            piVar7 = (int *)((longlong)piVar7 + 1);
          } while (cVar4 != '\0');
          if ((char)iVar6 == cVar4) {
            dVar1 = *pdVar15;
            dVar2 = *local_48;
            if (dVar1 < dVar2) {
              *local_48 = dVar2 - dVar1;
              *pdVar11 = *pdVar11 / *pdVar8;
              iVar6 = *(int *)param_2;
              if (iVar9 < iVar6) {
                pdVar11 = pdVar14;
                iVar12 = iVar9;
                iVar13 = iVar17;
                do {
                  pdVar8 = param_2 + (longlong)iVar12 * 4 + 2;
                  do {
                    cVar4 = *(char *)pdVar8;
                    *(char *)(((longlong)iVar13 * 0x20 - (longlong)(param_2 + (longlong)iVar12 * 4))
                              + (longlong)param_2 + (longlong)pdVar8) = cVar4;
                    pdVar8 = (double *)((longlong)pdVar8 + 1);
                  } while (cVar4 != '\0');
                  iVar12 = iVar12 + 1;
                  *pdVar11 = pdVar11[4];
                  iVar13 = iVar13 + 1;
                  pdVar11[-1] = pdVar11[3];
                  pdVar11 = pdVar11 + 4;
                  iVar6 = *(int *)param_2;
                } while (iVar12 < iVar6);
                iVar12 = local_res18;
                iVar13 = local_res20;
              }
              iVar16 = iVar16 + -1;
              *(int *)param_2 = iVar6 + -1;
              iVar9 = iVar9 + -1;
              iVar17 = iVar17 + -1;
              pdVar15 = pdVar15 + -4;
              pdVar14 = pdVar14 + -4;
              pdVar8 = pdVar10;
              pdVar11 = local_40;
              goto LAB_180002406;
            }
            if (dVar1 <= dVar2) {
              if (dVar2 != dVar1) goto LAB_180002406;
              *(double *)(param_1 + 2) = *pdVar11 * *(double *)(param_1 + 2);
              iVar6 = *(int *)param_2;
              param_2[1] = param_2[1] * *pdVar8;
              if (iVar9 < iVar6) {
                pdVar11 = pdVar14;
                iVar12 = iVar9;
                iVar13 = iVar17;
                do {
                  pdVar8 = param_2 + (longlong)iVar12 * 4 + 2;
                  do {
                    cVar4 = *(char *)pdVar8;
                    *(char *)((longlong)pdVar8 +
                             ((longlong)iVar13 * 0x20 - (longlong)(param_2 + (longlong)iVar12 * 4))
                             + (longlong)param_2) = cVar4;
                    pdVar8 = (double *)((longlong)pdVar8 + 1);
                  } while (cVar4 != '\0');
                  iVar12 = iVar12 + 1;
                  *pdVar11 = pdVar11[4];
                  iVar13 = iVar13 + 1;
                  pdVar11[-1] = pdVar11[3];
                  pdVar11 = pdVar11 + 4;
                  iVar6 = *(int *)param_2;
                } while (iVar12 < iVar6);
                iVar12 = local_res18;
                iVar13 = local_res20;
              }
              iVar16 = iVar16 + -1;
              *(int *)param_2 = iVar6 + -1;
              iVar9 = iVar9 + -1;
              iVar6 = *param_1;
              iVar17 = iVar17 + -1;
              pdVar15 = pdVar15 + -4;
              pdVar14 = pdVar14 + -4;
              if (iVar6 <= iVar12) goto LAB_1800024f9;
              pdVar11 = local_50;
              do {
                piVar7 = param_1 + (longlong)iVar12 * 8 + 4;
                do {
                  iVar6 = *piVar7;
                  *(char *)((longlong)piVar7 +
                           ((longlong)iVar13 * 0x20 - (longlong)(param_1 + (longlong)iVar12 * 8)) +
                           (longlong)param_1) = (char)iVar6;
                  piVar7 = (int *)((longlong)piVar7 + 1);
                } while ((char)iVar6 != '\0');
                iVar12 = iVar12 + 1;
                *pdVar11 = pdVar11[4];
                iVar13 = iVar13 + 1;
                pdVar11[-1] = pdVar11[3];
                pdVar11 = pdVar11 + 4;
              } while (iVar12 < *param_1);
              local_res18 = local_res18 + -1;
              local_res20 = local_res20 + -1;
              local_res8 = local_res8 + -1;
              local_58 = local_58 + -1;
              local_48 = local_48 + -4;
              pdVar11 = local_40 + -4;
              local_50 = local_50 + -4;
              *param_1 = *param_1 + -1;
              local_40 = pdVar11;
              iVar12 = local_res18;
              iVar13 = local_res20;
            }
            else {
              dVar3 = *pdVar8;
              *pdVar15 = dVar1 - dVar2;
              *pdVar8 = dVar3 / *pdVar11;
              iVar6 = *param_1;
              pdVar10 = pdVar8;
              if (iVar12 < iVar6) {
                pdVar11 = local_50;
                do {
                  piVar7 = param_1 + (longlong)iVar12 * 8 + 4;
                  do {
                    iVar6 = *piVar7;
                    *(char *)((longlong)piVar7 +
                             ((longlong)iVar13 * 0x20 - (longlong)(param_1 + (longlong)iVar12 * 8))
                             + (longlong)param_1) = (char)iVar6;
                    piVar7 = (int *)((longlong)piVar7 + 1);
                  } while ((char)iVar6 != '\0');
                  iVar12 = iVar12 + 1;
                  *pdVar11 = pdVar11[4];
                  iVar13 = iVar13 + 1;
                  pdVar11[-1] = pdVar11[3];
                  pdVar11 = pdVar11 + 4;
                  iVar6 = *param_1;
                } while (iVar12 < iVar6);
                iVar12 = local_res18;
                iVar13 = local_res20;
              }
LAB_1800024f9:
              local_res8 = local_res8 + -1;
              local_58 = local_58 + -1;
              local_48 = local_48 + -4;
              pdVar11 = local_40 + -4;
              local_res18 = iVar12 + -1;
              local_res20 = iVar13 + -1;
              local_50 = local_50 + -4;
              *param_1 = iVar6 + -1;
              local_40 = pdVar11;
              iVar12 = local_res18;
              iVar13 = local_res20;
            }
          }
          else {
LAB_180002406:
            pdVar10 = pdVar8;
          }
          iVar16 = iVar16 + 1;
          iVar9 = iVar9 + 1;
          iVar17 = iVar17 + 1;
          pdVar15 = pdVar15 + 4;
          pdVar14 = pdVar14 + 4;
        } while (iVar16 < *(int *)param_2);
      }
      local_res8 = local_res8 + 1;
      local_58 = local_58 + 1;
    } while (local_res8 < *param_1);
  }
  return;
}

/* RVA 0x26c0, FUN_1800026c0 */
void FUN_1800026c0(int *param_1)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  double *pdVar9;
  int iVar10;
  int iVar11;
  double *pdVar12;
  double *pdVar13;
  double *pdVar14;
  double *pdVar15;
  
  iVar5 = *param_1;
  if (0 < iVar5) {
    pdVar13 = (double *)(param_1 + 0x12);
    iVar7 = 1;
    do {
      if (iVar7 < iVar5) {
        pdVar12 = pdVar13 + -1;
        pdVar14 = pdVar13;
        pdVar15 = pdVar13;
        iVar8 = iVar7;
        iVar6 = iVar7;
        iVar3 = iVar7;
        do {
          iVar10 = iVar3 + 1;
          piVar4 = param_1 + (longlong)(iVar7 + -1) * 8 + 4;
          do {
            iVar11 = *piVar4;
            cVar1 = *(char *)((longlong)piVar4 +
                             (longlong)param_1 +
                             (((longlong)iVar8 * 0x20 + 0x10) -
                             (longlong)(param_1 + (longlong)(iVar7 + -1) * 8 + 4)));
            if ((char)iVar11 != cVar1) break;
            piVar4 = (int *)((longlong)piVar4 + 1);
          } while (cVar1 != '\0');
          if ((char)iVar11 == cVar1) {
            pdVar13[-5] = pdVar13[-5] * *pdVar12;
            pdVar13[-4] = pdVar13[-4] + *pdVar15;
            iVar5 = *param_1;
            if (iVar10 < iVar5) {
              pdVar9 = pdVar14;
              iVar11 = iVar6;
              do {
                piVar4 = param_1 + (longlong)iVar10 * 8 + 4;
                do {
                  iVar5 = *piVar4;
                  *(char *)((longlong)piVar4 +
                           ((longlong)iVar11 * 0x20 - (longlong)(param_1 + (longlong)iVar10 * 8)) +
                           (longlong)param_1) = (char)iVar5;
                  piVar4 = (int *)((longlong)piVar4 + 1);
                } while ((char)iVar5 != '\0');
                iVar10 = iVar10 + 1;
                *pdVar9 = pdVar9[4];
                iVar11 = iVar11 + 1;
                pdVar9[-1] = pdVar9[3];
                pdVar9 = pdVar9 + 4;
                iVar5 = *param_1;
              } while (iVar10 < iVar5);
            }
            iVar5 = iVar5 + -1;
            iVar8 = iVar8 + -1;
            *param_1 = iVar5;
            iVar6 = iVar6 + -1;
            pdVar12 = pdVar12 + -4;
            pdVar15 = pdVar15 + -4;
            pdVar14 = pdVar14 + -4;
            iVar10 = iVar3;
          }
          iVar8 = iVar8 + 1;
          iVar6 = iVar6 + 1;
          pdVar12 = pdVar12 + 4;
          pdVar15 = pdVar15 + 4;
          pdVar14 = pdVar14 + 4;
          iVar3 = iVar10;
        } while (iVar8 < iVar5);
      }
      pdVar13 = pdVar13 + 4;
      bVar2 = iVar7 < iVar5;
      iVar7 = iVar7 + 1;
    } while (bVar2);
  }
  return;
}

/* RVA 0x2880, FUN_180002880 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180002880(int *param_1,int *param_2,longlong param_3,int param_4,double param_5,int param_6
                  )

{
  double dVar1;
  char cVar2;
  char *pcVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  double *pdVar7;
  undefined1 auStackY_578 [32];
  int local_548 [4];
  char local_538 [24];
  double local_520 [77];
  int local_2b8 [4];
  char local_2a8 [24];
  double local_290 [77];
  ulonglong local_28;
  
  dVar1 = DAT_180026638;
  local_28 = DAT_180032178 ^ (ulonglong)auStackY_578;
  iVar5 = 0;
  local_548[0] = 0;
  *(undefined1 *)((longlong)param_6 + -1 + param_3) = 0;
  local_2b8[0] = 0;
  FUN_180001780(local_548,local_2b8,(char *)(param_3 + 1),1,dVar1);
  iVar6 = 0;
  if (param_4 == 1) {
    if (0 < local_548[0]) {
      pdVar7 = local_520;
      do {
        pcVar3 = local_538 + (longlong)iVar6 * 0x20;
        piVar4 = param_1 + (longlong)*param_1 * 8 + 4;
        do {
          cVar2 = *pcVar3;
          pcVar3 = pcVar3 + 1;
          *(char *)piVar4 = cVar2;
          piVar4 = (int *)((longlong)piVar4 + 1);
        } while (cVar2 != '\0');
        dVar1 = *pdVar7;
        iVar6 = iVar6 + 1;
        pdVar7 = pdVar7 + 4;
        *(double *)(param_1 + (longlong)*param_1 * 8 + 10) = param_5 * dVar1;
        *param_1 = *param_1 + 1;
      } while (iVar6 < local_548[0]);
    }
    if (0 < local_2b8[0]) {
      pdVar7 = local_290;
      do {
        pcVar3 = local_2a8 + (longlong)iVar5 * 0x20;
        piVar4 = param_2 + (longlong)*param_2 * 8 + 4;
        do {
          cVar2 = *pcVar3;
          pcVar3 = pcVar3 + 1;
          *(char *)piVar4 = cVar2;
          piVar4 = (int *)((longlong)piVar4 + 1);
        } while (cVar2 != '\0');
        dVar1 = *pdVar7;
        iVar5 = iVar5 + 1;
        pdVar7 = pdVar7 + 4;
        *(double *)(param_2 + (longlong)*param_2 * 8 + 10) = param_5 * dVar1;
        *param_2 = *param_2 + 1;
      } while (iVar5 < local_2b8[0]);
    }
  }
  else {
    if (0 < local_548[0]) {
      pdVar7 = local_520;
      do {
        pcVar3 = local_538 + (longlong)iVar6 * 0x20;
        piVar4 = param_2 + (longlong)*param_2 * 8 + 4;
        do {
          cVar2 = *pcVar3;
          pcVar3 = pcVar3 + 1;
          *(char *)piVar4 = cVar2;
          piVar4 = (int *)((longlong)piVar4 + 1);
        } while (cVar2 != '\0');
        dVar1 = *pdVar7;
        iVar6 = iVar6 + 1;
        pdVar7 = pdVar7 + 4;
        *(double *)(param_2 + (longlong)*param_2 * 8 + 10) = param_5 * dVar1;
        *param_2 = *param_2 + 1;
      } while (iVar6 < local_548[0]);
    }
    if (0 < local_2b8[0]) {
      pdVar7 = local_290;
      do {
        pcVar3 = local_2a8 + (longlong)iVar5 * 0x20;
        piVar4 = param_1 + (longlong)*param_1 * 8 + 4;
        do {
          cVar2 = *pcVar3;
          pcVar3 = pcVar3 + 1;
          *(char *)piVar4 = cVar2;
          piVar4 = (int *)((longlong)piVar4 + 1);
        } while (cVar2 != '\0');
        dVar1 = *pdVar7;
        iVar5 = iVar5 + 1;
        pdVar7 = pdVar7 + 4;
        *(double *)(param_1 + (longlong)*param_1 * 8 + 10) = param_5 * dVar1;
        *param_1 = *param_1 + 1;
      } while (iVar5 < local_2b8[0]);
    }
  }
  return;
}

/* RVA 0x2ae0, FUN_180002ae0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180002ae0(int *param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  char cVar3;
  longlong lVar4;
  int iVar5;
  int *piVar6;
  longlong lVar7;
  int *piVar8;
  char *pcVar9;
  int *piVar10;
  int *_Str2;
  int iVar11;
  int *piVar12;
  int iVar13;
  int iVar14;
  int *_Str1;
  undefined1 auStack_68 [32];
  int local_48;
  char local_40 [16];
  ulonglong local_30;
  
  local_30 = DAT_180032178 ^ (ulonglong)auStack_68;
  iVar5 = *param_1;
  iVar14 = 0;
  iVar13 = 0;
  if (0 < iVar5) {
    piVar8 = param_1;
    do {
      piVar10 = piVar8 + 8;
      iVar11 = iVar13 + 1;
      if (iVar11 < iVar5) {
        piVar12 = piVar8 + 0x12;
        _Str1 = param_1 + (longlong)iVar13 * 8 + 4;
        local_48 = iVar11;
        do {
          _Str2 = param_1 + (longlong)iVar11 * 8 + 4;
          iVar5 = _stricmp((char *)_Str1,(char *)_Str2);
          if (0 < iVar5) {
            piVar6 = _Str1;
            do {
              iVar5 = *piVar6;
              *(char *)((longlong)piVar6 + (longlong)(local_40 + -(longlong)_Str1)) = (char)iVar5;
              piVar6 = (int *)((longlong)piVar6 + 1);
            } while ((char)iVar5 != '\0');
            uVar1 = *(undefined8 *)piVar10;
            uVar2 = *(undefined8 *)(piVar8 + 10);
            lVar7 = (longlong)_Str1 - (longlong)_Str2;
            do {
              iVar5 = *_Str2;
              *(char *)(lVar7 + (longlong)_Str2) = (char)iVar5;
              _Str2 = (int *)((longlong)_Str2 + 1);
            } while ((char)iVar5 != '\0');
            pcVar9 = local_40;
            *(undefined8 *)piVar10 = *(undefined8 *)(piVar12 + -2);
            *(undefined8 *)(piVar8 + 10) = *(undefined8 *)piVar12;
            do {
              cVar3 = *pcVar9;
              pcVar9[(longlong)param_1 + ((longlong)iVar11 * 0x20 - (longlong)local_40) + 0x10] =
                   cVar3;
              pcVar9 = pcVar9 + 1;
            } while (cVar3 != '\0');
            *(undefined8 *)(piVar12 + -2) = uVar1;
            *(undefined8 *)piVar12 = uVar2;
          }
          iVar5 = *param_1;
          iVar11 = iVar11 + 1;
          piVar12 = piVar12 + 8;
        } while (iVar11 < iVar5);
        iVar11 = local_48;
      }
      iVar13 = iVar11;
      piVar8 = piVar10;
    } while (iVar13 < iVar5);
    if (0 < iVar5) {
      do {
        lVar7 = (longlong)iVar14;
        piVar8 = param_1 + lVar7 * 8 + 4;
        if ((((((char)*piVar8 == 'K') && (*(char *)((longlong)piVar8 + 1) == '\0')) ||
             (((char)*piVar8 == 'F' && (*(char *)((longlong)piVar8 + 1) == '\0')))) ||
            (((char)*piVar8 == 'C' && (*(char *)((longlong)piVar8 + 1) == '\0')))) ||
           (((char)*piVar8 == 'R' && (*(char *)((longlong)piVar8 + 1) == '\0')))) {
          lVar4 = -(longlong)piVar8;
          do {
            iVar13 = *piVar8;
            (local_40 + lVar4)[(longlong)piVar8] = (char)iVar13;
            piVar8 = (int *)((longlong)piVar8 + 1);
          } while ((char)iVar13 != '\0');
          uVar1 = *(undefined8 *)(param_1 + lVar7 * 8 + 8);
          iVar13 = iVar14 + 1;
          uVar2 = *(undefined8 *)(param_1 + lVar7 * 8 + 10);
          if (iVar13 < iVar5) {
            piVar8 = param_1 + (longlong)iVar13 * 8 + 10;
            do {
              piVar10 = param_1 + (longlong)iVar13 * 8 + 4;
              do {
                iVar5 = *piVar10;
                *(char *)(((longlong)iVar14 * 0x20 - (longlong)(param_1 + (longlong)iVar13 * 8)) +
                          (longlong)param_1 + (longlong)piVar10) = (char)iVar5;
                piVar10 = (int *)((longlong)piVar10 + 1);
              } while ((char)iVar5 != '\0');
              iVar13 = iVar13 + 1;
              *(undefined8 *)(piVar8 + -10) = *(undefined8 *)(piVar8 + -2);
              iVar14 = iVar14 + 1;
              *(undefined8 *)(piVar8 + -8) = *(undefined8 *)piVar8;
              piVar8 = piVar8 + 8;
              iVar5 = *param_1;
            } while (iVar13 < iVar5);
          }
          pcVar9 = local_40;
          do {
            cVar3 = *pcVar9;
            pcVar9[(longlong)param_1 + ((longlong)iVar5 * 0x20 - (longlong)local_40) + -0x10] =
                 cVar3;
            pcVar9 = pcVar9 + 1;
          } while (cVar3 != '\0');
          *(undefined8 *)(param_1 + (longlong)*param_1 * 8) = uVar1;
          *(undefined8 *)(param_1 + (longlong)*param_1 * 8 + 2) = uVar2;
          return;
        }
        iVar14 = iVar14 + 1;
      } while (iVar14 < iVar5);
    }
  }
  return;
}

/* RVA 0x2d90, FUN_180002d90 */
int FUN_180002d90(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  ulonglong *puVar2;
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res18 = param_3;
  local_res20 = param_4;
  puVar2 = (ulonglong *)FUN_180001770();
  iVar1 = __stdio_common_vsprintf(*puVar2 | 1,param_1,0xffffffffffffffff,param_2,0,&local_res18);
  if (iVar1 < 0) {
    iVar1 = -1;
  }
  return iVar1;
}

/* RVA 0x2df0, FUN_180002df0 */
undefined8 FUN_180002df0(longlong param_1,int param_2,longlong *param_3,longlong *param_4)

{
  char cVar1;
  uint uVar2;
  ulonglong uVar3;
  uint uVar4;
  longlong lVar5;
  int iVar6;
  
  uVar3 = 0;
  iVar6 = 0;
  if (0 < param_2) {
    lVar5 = 0;
    do {
      cVar1 = *(char *)(lVar5 + param_1);
      uVar4 = (uint)uVar3 + 1;
      if (cVar1 != '(') {
        uVar4 = (uint)uVar3;
      }
      uVar2 = uVar4 - 1;
      if (cVar1 != ')') {
        uVar2 = uVar4;
      }
      uVar3 = (ulonglong)uVar2;
      if ((cVar1 == '/') && (uVar2 == 0)) {
        *(undefined1 *)(iVar6 + param_1) = 0;
        *param_3 = param_1;
        *param_4 = (iVar6 + 1) + param_1;
        return CONCAT71((uint7)(uint3)((uint)(iVar6 + 1) >> 8),0x2f);
      }
      if ((cVar1 == '*') && (uVar2 == 0)) {
        *(undefined1 *)(iVar6 + param_1) = 0;
        *param_3 = param_1;
        *param_4 = (iVar6 + 1) + param_1;
        return CONCAT71((uint7)(uint3)((uint)(iVar6 + 1) >> 8),0x2a);
      }
      if ((((cVar1 == '^') && (uVar2 == 0)) && (2 < lVar5)) &&
         (*(char *)(lVar5 + -1 + param_1) == ')')) {
        *(undefined1 *)(iVar6 + param_1) = 0;
        *param_3 = param_1;
        *param_4 = (iVar6 + 1) + param_1;
        return CONCAT71((uint7)(uint3)((uint)(iVar6 + 1) >> 8),0x5e);
      }
      iVar6 = iVar6 + 1;
      lVar5 = lVar5 + 1;
    } while (lVar5 < param_2);
  }
  return CONCAT71((int7)(uVar3 >> 8),0x20);
}

/* RVA 0x2ee0, FUN_180002ee0 */
void FUN_180002ee0(int *param_1,int *param_2)

{
  double dVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  double *pdVar5;
  int iVar6;
  double *pdVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  double *pdVar12;
  
  dVar1 = DAT_180026658;
  iVar2 = *param_1;
  iVar8 = 0;
  if (0 < iVar2) {
    iVar6 = 1;
    pdVar7 = (double *)(param_1 + 10);
    iVar11 = 0;
    pdVar12 = pdVar7;
    do {
      if (*pdVar7 <= 0.0 && *pdVar7 != 0.0) {
        piVar3 = param_1 + (longlong)iVar8 * 8 + 4;
        piVar4 = param_2 + (longlong)*param_2 * 8 + 4;
        do {
          iVar2 = *piVar3;
          piVar3 = (int *)((longlong)piVar3 + 1);
          *(char *)piVar4 = (char)iVar2;
          piVar4 = (int *)((longlong)piVar4 + 1);
        } while ((char)iVar2 != '\0');
        *(double *)(param_2 + (longlong)*param_2 * 8 + 10) = *pdVar7 * dVar1;
        *param_2 = *param_2 + 1;
        iVar2 = *param_1;
        if (iVar6 < iVar2) {
          pdVar5 = pdVar12;
          iVar10 = iVar11;
          iVar9 = iVar6;
          do {
            piVar3 = param_1 + (longlong)iVar9 * 8 + 4;
            do {
              iVar2 = *piVar3;
              *(char *)(((longlong)iVar10 * 0x20 - (longlong)(param_1 + (longlong)iVar9 * 8)) +
                        (longlong)param_1 + (longlong)piVar3) = (char)iVar2;
              piVar3 = (int *)((longlong)piVar3 + 1);
            } while ((char)iVar2 != '\0');
            iVar9 = iVar9 + 1;
            *pdVar5 = pdVar5[4];
            iVar10 = iVar10 + 1;
            iVar2 = *param_1;
            pdVar5 = pdVar5 + 4;
          } while (iVar9 < iVar2);
        }
        iVar2 = iVar2 + -1;
        iVar8 = iVar8 + -1;
        iVar6 = iVar6 + -1;
        *param_1 = iVar2;
        iVar11 = iVar11 + -1;
        pdVar7 = pdVar7 + -4;
        pdVar12 = pdVar12 + -4;
      }
      iVar8 = iVar8 + 1;
      iVar6 = iVar6 + 1;
      iVar11 = iVar11 + 1;
      pdVar7 = pdVar7 + 4;
      pdVar12 = pdVar12 + 4;
    } while (iVar8 < iVar2);
  }
  return;
}

/* RVA 0x3040, FUN_180003040 */
void FUN_180003040(double *param_1)

{
  char cVar1;
  double *pdVar2;
  ulonglong uVar3;
  double *pdVar4;
  longlong lVar5;
  char *pcVar6;
  double *pdVar7;
  longlong lVar8;
  longlong lVar9;
  double *_Str;
  undefined **ppuVar10;
  double *pdVar11;
  longlong lVar12;
  longlong lVar13;
  double dVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  int local_res8;
  int local_res10;
  
  local_res10 = 0;
  if (0 < *(int *)param_1) {
    local_res8 = (int)param_1;
    lVar12 = (longlong)local_res8;
    uVar17 = (undefined4)DAT_180026638;
    uVar3 = (ulonglong)DAT_180026638 >> 0x20;
    pdVar2 = param_1;
    do {
      pdVar11 = pdVar2 + 4;
      pdVar7 = (double *)0x0;
      lVar13 = 0;
      if (PTR_DAT_18002c008 == (undefined *)0x0) {
LAB_180003258:
        *pdVar11 = 1.0;
        uVar15 = uVar17;
        uVar16 = (int)uVar3;
      }
      else {
        ppuVar10 = &PTR_DAT_18002c008;
        _Str = param_1 + (longlong)local_res10 * 4 + 2;
        pcVar6 = PTR_DAT_18002c008;
        do {
          pdVar4 = (double *)FUN_180023a80((char *)_Str,pcVar6);
          if (pdVar4 != (double *)0x0) {
            lVar9 = -1;
            do {
              lVar9 = lVar9 + 1;
            } while ((*ppuVar10)[lVar9] != '\0');
            lVar5 = -1;
            do {
              lVar5 = lVar5 + 1;
            } while (*(char *)((longlong)pdVar4 + lVar5) != '\0');
            if (lVar5 == lVar9) {
              if (pdVar4 == _Str) goto LAB_180003209;
              lVar12 = 0;
              if (PTR_DAT_18002c4d0 != (undefined *)0x0) {
                ppuVar10 = &PTR_DAT_18002c4d0;
                pcVar6 = PTR_DAT_18002c4d0;
                do {
                  pdVar7 = (double *)strstr((char *)_Str,pcVar6);
                  if (((pdVar7 != (double *)0x0) && (pdVar7 < pdVar4)) && (pdVar7 == _Str)) {
                    lVar9 = -1;
                    do {
                      lVar9 = lVar9 + 1;
                    } while (*(char *)((longlong)pdVar4 + lVar9) != '\0');
                    lVar5 = -1;
                    do {
                      lVar5 = lVar5 + 1;
                    } while ((*ppuVar10)[lVar5] != '\0');
                    lVar8 = -1;
                    do {
                      lVar8 = lVar8 + 1;
                    } while (*(char *)((longlong)_Str + lVar8) != '\0');
                    if (lVar9 + lVar5 == lVar8) break;
                  }
                  lVar12 = lVar12 + 1;
                  ppuVar10 = &PTR_DAT_18002c4d0 + lVar12 * 2;
                  pcVar6 = *ppuVar10;
                } while (pcVar6 != (char *)0x0);
              }
              if ((&PTR_DAT_18002c4d0)[lVar12 * 2] != (undefined *)0x0) goto LAB_180003209;
            }
          }
          lVar13 = lVar13 + 1;
          ppuVar10 = &PTR_DAT_18002c000 + lVar13 * 3 + 1;
          pcVar6 = *ppuVar10;
        } while (pcVar6 != (char *)0x0);
        if (pdVar4 == (double *)0x0) goto LAB_180003258;
LAB_180003209:
        pcVar6 = (&PTR_DAT_18002c000)[lVar13 * 3];
        do {
          cVar1 = *pcVar6;
          pcVar6 = pcVar6 + 1;
          *(char *)_Str = cVar1;
          _Str = (double *)((longlong)_Str + 1);
        } while (cVar1 != '\0');
        dVar14 = pow(*(double *)(lVar13 * 0x18 + 0x18002c010),pdVar2[5]);
        *pdVar11 = dVar14;
        uVar15 = SUB84(dVar14,0);
        uVar16 = (int)((ulonglong)dVar14 >> 0x20);
      }
      if (pdVar7 != (double *)0x0) {
        dVar14 = pow(*(double *)(&DAT_18002c4d8 + lVar12 * 0x10),pdVar2[5]);
        *pdVar11 = dVar14 * (double)CONCAT44(uVar16,uVar15);
      }
      local_res10 = local_res10 + 1;
      pdVar2 = pdVar11;
    } while (local_res10 < *(int *)param_1);
  }
  return;
}

/* RVA 0x32f0, FUN_1800032f0 */
void FUN_1800032f0(int *param_1)

{
  char cVar1;
  int *piVar2;
  longlong lVar3;
  char *pcVar4;
  int *piVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  undefined **ppuVar9;
  int *_Str;
  longlong lVar10;
  int iVar11;
  int *local_res10;
  
  iVar11 = 0;
  if (0 < *param_1) {
    local_res10 = param_1;
    do {
      local_res10 = local_res10 + 8;
      piVar2 = (int *)0x0;
      lVar10 = 0;
      if (PTR_DAT_18002c5e8 != (undefined *)0x0) {
        ppuVar9 = &PTR_DAT_18002c5e8;
        _Str = param_1 + (longlong)iVar11 * 8 + 4;
        pcVar4 = PTR_DAT_18002c5e8;
        do {
          piVar2 = (int *)FUN_180023a80((char *)_Str,pcVar4);
          if (piVar2 != (int *)0x0) {
            lVar8 = -1;
            do {
              lVar8 = lVar8 + 1;
            } while ((*ppuVar9)[lVar8] != '\0');
            lVar3 = -1;
            do {
              lVar3 = lVar3 + 1;
            } while (*(char *)((longlong)piVar2 + lVar3) != '\0');
            if (lVar3 == lVar8) {
              if (piVar2 == _Str) break;
              lVar8 = 0;
              if (PTR_DAT_18002c4d0 != (undefined *)0x0) {
                ppuVar9 = &PTR_DAT_18002c4d0;
                pcVar4 = PTR_DAT_18002c4d0;
                do {
                  piVar5 = (int *)strstr((char *)_Str,pcVar4);
                  if (((piVar5 != (int *)0x0) && (piVar5 < piVar2)) && (piVar5 == _Str)) {
                    lVar3 = -1;
                    do {
                      lVar3 = lVar3 + 1;
                    } while ((*ppuVar9)[lVar3] != '\0');
                    lVar6 = -1;
                    do {
                      lVar6 = lVar6 + 1;
                    } while (*(char *)((longlong)piVar2 + lVar6) != '\0');
                    lVar7 = -1;
                    do {
                      lVar7 = lVar7 + 1;
                    } while (*(char *)((longlong)_Str + lVar7) != '\0');
                    if (lVar3 + lVar6 == lVar7) break;
                  }
                  lVar8 = lVar8 + 1;
                  ppuVar9 = &PTR_DAT_18002c4d0 + lVar8 * 2;
                  pcVar4 = *ppuVar9;
                } while (pcVar4 != (char *)0x0);
              }
              if ((&PTR_DAT_18002c4d0)[lVar8 * 2] != (undefined *)0x0) break;
            }
          }
          lVar10 = lVar10 + 1;
          ppuVar9 = &PTR_DAT_18002c5e8 + lVar10 * 2;
          pcVar4 = *ppuVar9;
        } while (pcVar4 != (char *)0x0);
      }
      local_res10[0] = 0;
      local_res10[1] = 0x3ff00000;
      if (piVar2 != (int *)0x0) {
        piVar2 = param_1 + (longlong)iVar11 * 8 + 4;
        pcVar4 = (&PTR_DAT_18002c5e0)[lVar10 * 2];
        do {
          cVar1 = *pcVar4;
          pcVar4 = pcVar4 + 1;
          *(char *)piVar2 = cVar1;
          piVar2 = (int *)((longlong)piVar2 + 1);
        } while (cVar1 != '\0');
      }
      iVar11 = iVar11 + 1;
    } while (iVar11 < *param_1);
  }
  return;
}

/* RVA 0x3510, FUN_180003510 */
undefined * FUN_180003510(longlong param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  byte *pbVar6;
  int iVar7;
  undefined *puVar8;
  
  iVar2 = FUN_180003630(0,(char *)0x0,(char *)0x0);
  if (iVar2 == -1) {
    return (undefined *)0x0;
  }
  pbVar6 = &DAT_1800321e8;
  iVar3 = (iVar2 + 1) / 2;
  iVar7 = 1;
  puVar8 = (undefined *)0x0;
  while (iVar7 < iVar2) {
    FUN_180003630(iVar3,&DAT_1800321e8,&DAT_1800321d0);
    pbVar5 = &DAT_1800321e8;
    do {
      bVar1 = *pbVar5;
      if (bVar1 != pbVar5[param_1 + -0x1800321e8]) {
        uVar4 = -(uint)(bVar1 < pbVar5[param_1 + -0x1800321e8]) | 1;
        goto LAB_18000359e;
      }
      pbVar5 = pbVar5 + 1;
    } while (bVar1 != 0);
    uVar4 = 0;
LAB_18000359e:
    if ((int)uVar4 < 1) {
      if (-1 < (int)uVar4) {
        iVar3 = (iVar7 + iVar2) / 2;
        break;
      }
      iVar7 = iVar3 + 1;
      iVar3 = (iVar2 + iVar7) / 2;
    }
    else {
      iVar2 = iVar3 + -1;
      iVar3 = (iVar7 + iVar2) / 2;
    }
  }
  FUN_180003630(iVar3,&DAT_1800321e8,&DAT_1800321d0);
  do {
    bVar1 = *pbVar6;
    if (bVar1 != pbVar6[param_1 + -0x1800321e8]) {
      uVar4 = -(uint)(bVar1 < pbVar6[param_1 + -0x1800321e8]) | 1;
      goto LAB_1800035ff;
    }
    pbVar6 = pbVar6 + 1;
  } while (bVar1 != 0);
  uVar4 = 0;
LAB_1800035ff:
  if (uVar4 == 0) {
    puVar8 = &DAT_1800321d0;
  }
  return puVar8;
}

/* RVA 0x3630, FUN_180003630 */
int FUN_180003630(int param_1,char *param_2,char *param_3)

{
  long lVar1;
  
  if (DAT_1800321c8 == (FILE *)0x0) {
    DAT_1800321c8 = fopen("c+as.txt","r");
    if (DAT_1800321c8 == (FILE *)0x0) {
      return -1;
    }
  }
  if (DAT_1800321c0 == 0) {
    fseek(DAT_1800321c8,1,2);
    lVar1 = ftell(DAT_1800321c8);
    DAT_1800321c0 = lVar1 / 0x26;
  }
  if (param_1 == 0) {
    return DAT_1800321c0;
  }
  fseek(DAT_1800321c8,param_1 * 0x26 + -0x26,0);
  FUN_1800232b0(DAT_1800321c8,param_2,'\"',0xc);
  FUN_1800232b0(DAT_1800321c8,param_2,'\"',0xc);
  FUN_1800232b0(DAT_1800321c8,param_3,'\"',0x14);
  FUN_1800232b0(DAT_1800321c8,param_3,'\"',0x14);
  return 0;
}

/* RVA 0x3770, FUN_180003770 */
undefined8 FUN_180003770(char *param_1,int param_2)

{
  int iVar1;
  int local_18;
  
  local_18 = 0;
  while( true ) {
    if (param_2 < local_18) {
      return 0;
    }
    iVar1 = strcmp(&DAT_180034ba0 + (longlong)local_18 * 100,param_1);
    if (iVar1 == 0) break;
    local_18 = local_18 + 1;
  }
  return 1;
}

/* RVA 0x37e0, FUN_1800037e0 */
void FUN_1800037e0(void)

{
  int local_28;
  int local_24;
  int local_20;
  undefined **local_18;
  
  local_28 = 0;
  do {
    if (9 < local_28) {
      return;
    }
    if (local_28 == 0) {
      local_18 = &PTR_DAT_18002cd10;
    }
    else if (local_28 == 1) {
      local_18 = &PTR_DAT_18002d710;
    }
    else if (local_28 == 2) {
      local_18 = &PTR_DAT_18002d810;
    }
    else if (local_28 == 3) {
      local_18 = &PTR_DAT_18002d990;
    }
    else if (local_28 == 4) {
      local_18 = &PTR_DAT_18002db10;
    }
    else if (local_28 == 5) {
      local_18 = &PTR_DAT_18002dc90;
    }
    else if (local_28 == 6) {
      local_18 = &PTR_DAT_18002dd90;
    }
    else if (local_28 == 7) {
      local_18 = &PTR_DAT_18002e010;
    }
    else if (local_28 == 8) {
      local_18 = &PTR_DAT_18002e190;
    }
    else {
      if (local_28 != 9) {
        return;
      }
      local_18 = &PTR_DAT_18002e290;
    }
    local_24 = 0;
    while (local_18[(longlong)local_24 * 0x10] != (undefined *)0x0) {
      for (local_20 = 0; local_20 < 10; local_20 = local_20 + 1) {
        if (local_18[(longlong)local_24 * 0x10 + (longlong)local_20 + 5] != (undefined *)0x0) {
          local_18[(longlong)local_24 * 0x10 + (longlong)local_20 + 5] = (undefined *)0x0;
        }
      }
      local_24 = local_24 + 1;
    }
    local_28 = local_28 + 1;
  } while( true );
}

/* RVA 0x3980, FUN_180003980 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180003980(int *param_1)

{
  int iVar1;
  undefined1 auStack_98 [32];
  int local_78;
  int local_74;
  int local_70;
  undefined4 local_6c;
  longlong *local_68;
  char *local_60;
  longlong local_58;
  undefined4 local_50;
  undefined4 local_4c;
  int *local_48;
  undefined **local_40;
  undefined **local_38;
  char local_30 [32];
  ulonglong local_10;
  
  local_10 = DAT_180032178 ^ (ulonglong)auStack_98;
  local_50 = 0;
  local_4c = 4;
  local_6c = 1;
  local_70 = 0;
  strcpy(local_30,"");
  local_48 = FUN_180021a60(4);
  local_74 = 0;
  local_68 = *(longlong **)(local_48 + 2);
  do {
    if (local_68 == (longlong *)0x0) {
LAB_180003b61:
      strcpy(local_30,"");
      return;
    }
    local_60 = (char *)*local_68;
    local_58 = *(longlong *)(local_60 + 0x20);
    local_78 = 0;
    while ((&PTR_s_UNIQUAC_18002e410)[(longlong)local_78 * 3] != (undefined *)0x0) {
      local_40 = &PTR_s_UNIQUAC_18002e410;
      iVar1 = _stricmp((&PTR_s_UNIQUAC_18002e410)[(longlong)local_78 * 3],local_60);
      if (iVar1 == 0) {
        local_38 = &PTR_s_UNIQUAC_18002e410;
        iVar1 = _stricmp((&PTR_DAT_18002e418)[(longlong)local_78 * 3],local_60 + 0xd);
        if (iVar1 == 0) break;
      }
      local_78 = local_78 + 1;
    }
    if ((&PTR_s_GMUQR_18002e420)[(longlong)local_78 * 3] != (undefined *)0x0) {
      iVar1 = strcmp(local_30,(char *)(local_58 + 0x240));
      if (iVar1 != 0) {
        local_74 = 0;
      }
      if (local_74 == 0) {
        if (local_70 != 0) {
          local_70 = 0;
          goto LAB_180003b61;
        }
        local_6c = 1;
        local_74 = 1;
        strcpy(local_30,(char *)(local_58 + 0x240));
        local_70 = 1;
      }
      *param_1 = *param_1 + 1;
    }
    local_68 = (longlong *)local_68[1];
  } while( true );
}

/* RVA 0x3ba0, FUN_180003ba0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180003ba0(int *param_1,int *param_2,undefined8 param_3,char *param_4)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 auStack_1a8 [32];
  int local_188;
  int local_184;
  int local_180;
  char *local_178;
  int local_170;
  int local_16c;
  char *local_168;
  longlong *local_160;
  int local_158;
  undefined4 local_154;
  longlong local_150;
  int *local_148;
  double local_140;
  undefined4 local_138;
  undefined **local_130;
  char *local_128;
  undefined8 local_120;
  undefined **local_118;
  char *local_110;
  char local_108 [32];
  char local_e8 [208];
  ulonglong local_18;
  
  local_18 = DAT_180032178 ^ (ulonglong)auStack_1a8;
  local_168 = (char *)0x0;
  local_180 = 0;
  local_138 = 4;
  local_154 = 1;
  local_16c = 0;
  for (local_184 = 0; local_184 < 100; local_184 = local_184 + 1) {
    strcpy(&DAT_180034ba0 + (longlong)local_184 * 100,"");
  }
  strcpy(local_108,"");
  local_148 = FUN_180021a60(3);
  local_158 = 0;
  local_170 = 0;
  for (local_160 = *(longlong **)(local_148 + 2); local_160 != (longlong *)0x0;
      local_160 = (longlong *)local_160[1]) {
    local_178 = (char *)*local_160;
    local_150 = *(longlong *)(local_178 + 0x10);
    local_120 = *(undefined8 *)(local_178 + 0x68);
    local_188 = 0;
    while ((&PTR_DAT_18002c8a0)[(longlong)local_188 * 3] != (undefined *)0x0) {
      local_130 = &PTR_DAT_18002c8a0;
      iVar1 = _stricmp((&PTR_DAT_18002c8a0)[(longlong)local_188 * 3],local_178);
      if (iVar1 == 0) break;
      local_188 = local_188 + 1;
    }
    if ((&PTR_DAT_18002c8a8)[(longlong)local_188 * 3] == (undefined *)0x0) {
      FUN_1800220b0(1,"Property %s not supported by Aspen Plus",local_178,param_4);
    }
    else {
      local_128 = local_178 + 0x20;
      local_168 = FUN_1800082f0(local_128,*(int *)(&DAT_18002c8b0 + (longlong)local_188 * 0x18),
                                &local_140);
      if (local_168 == (char *)0x0) {
        if (*(int *)(&DAT_18002c8b0 + (longlong)local_188 * 0x18) == 0) {
          FUN_180001a20(local_178 + 0x20,local_e8,&local_140);
        }
        else {
          param_4 = local_178;
          FUN_1800220b0(1,"Unit <%s> for property <%s> not supported by Aspen Plus",local_178 + 0x20
                        ,local_178);
        }
      }
      else {
        if (local_158 == 0) {
          if ((local_168 != (char *)0x0) &&
             (uVar2 = FUN_180003770(local_168,local_180), (int)uVar2 == 0)) {
            *param_1 = *param_1 + 1;
            strcpy(&DAT_180034ba0 + (longlong)local_180 * 100,local_168);
            local_180 = local_180 + 1;
          }
          local_158 = 1;
        }
        if (((local_168 != (char *)0x0) && (local_158 == 1)) &&
           (uVar2 = FUN_180003770(local_168,local_180), (int)uVar2 == 0)) {
          *param_1 = *param_1 + 1;
          strcpy(&DAT_180034ba0 + (longlong)local_180 * 100,local_168);
          local_180 = local_180 + 1;
        }
      }
    }
  }
  local_148 = FUN_180021a60(3);
  local_160 = *(longlong **)(local_148 + 2);
  do {
    if (local_160 == (longlong *)0x0) {
LAB_18000419d:
      strcpy(local_108,"");
      for (local_184 = 0; local_184 < 100; local_184 = local_184 + 1) {
        strcpy(&DAT_180034ba0 + (longlong)local_184 * 100,"");
      }
      return 1;
    }
    local_178 = (char *)*local_160;
    local_150 = *(longlong *)(local_178 + 0x10);
    local_120 = *(undefined8 *)(local_178 + 0x68);
    local_188 = 0;
    while ((&PTR_DAT_18002c8a0)[(longlong)local_188 * 3] != (undefined *)0x0) {
      local_118 = &PTR_DAT_18002c8a0;
      iVar1 = _stricmp((&PTR_DAT_18002c8a0)[(longlong)local_188 * 3],local_178);
      if (iVar1 == 0) break;
      local_188 = local_188 + 1;
    }
    if ((&PTR_DAT_18002c8a8)[(longlong)local_188 * 3] == (undefined *)0x0) {
      FUN_1800220b0(1,"Property %s not supported by Aspen Plus",local_178,param_4);
    }
    else {
      local_110 = local_178 + 0x20;
      local_168 = FUN_1800082f0(local_110,*(int *)(&DAT_18002c8b0 + (longlong)local_188 * 0x18),
                                &local_140);
      if (local_168 == (char *)0x0) {
        if (*(int *)(&DAT_18002c8b0 + (longlong)local_188 * 0x18) == 0) {
          FUN_180001a20(local_178 + 0x20,local_e8,&local_140);
          iVar1 = strcmp(local_108,(char *)(local_150 + 0x240));
          if (iVar1 != 0) {
            local_170 = 0;
          }
          if (local_170 == 0) {
            local_154 = 1;
            if (local_16c != 0) {
              local_16c = 0;
              goto LAB_18000419d;
            }
            local_170 = 1;
            strcpy(local_108,(char *)(local_150 + 0x240));
            local_16c = 1;
          }
          *param_2 = *param_2 + 1;
        }
        else {
          param_4 = local_178;
          FUN_1800220b0(1,"Unit <%s> for property <%s> not supported by Aspen Plus",local_178 + 0x20
                        ,local_178);
        }
      }
      else if (local_168 != (char *)0x0) {
        iVar1 = strcmp(local_108,(char *)(local_150 + 0x240));
        if (iVar1 != 0) {
          local_170 = 0;
        }
        if (local_170 == 0) {
          if (local_16c != 0) {
            local_16c = 0;
            goto LAB_18000419d;
          }
          local_154 = 1;
          local_170 = 1;
          strcpy(local_108,(char *)(local_150 + 0x240));
          local_16c = 1;
        }
        *param_2 = *param_2 + 1;
      }
    }
    local_160 = (longlong *)local_160[1];
  } while( true );
}

/* RVA 0x4210, FUN_180004210 */
undefined8 FUN_180004210(char *param_1,longlong param_2)

{
  bool bVar1;
  size_t sVar2;
  int local_18;
  int local_14;
  
  local_14 = 0;
  bVar1 = false;
  for (local_18 = 0; sVar2 = strlen(param_1), local_18 < (int)sVar2; local_18 = local_18 + 1) {
    if (bVar1) {
      *(char *)(param_2 + local_14) = param_1[local_18];
      local_14 = local_14 + 1;
    }
    else if (param_1[local_18] == '=') {
      bVar1 = true;
    }
  }
  *(undefined1 *)(param_2 + local_14) = 0;
  return 1;
}

/* RVA 0x42c0, FUN_1800042c0 */
undefined4 FUN_1800042c0(longlong param_1,undefined8 param_2,char *param_3,int param_4)

{
  int iVar1;
  char *_Str1;
  undefined4 local_18;
  
  local_18 = 0xffffffff;
  if (*(longlong *)(param_1 + 0x48) != 0) {
    _Str1 = (char *)((longlong)(param_4 + -1) * 0x14 + *(longlong *)(param_1 + 0x48));
    if (*_Str1 == '%') {
      local_18 = 1;
    }
    else if (*_Str1 == '$') {
      local_18 = 0xffffffff;
    }
    else {
      iVar1 = strcmp(_Str1,param_3);
      if (iVar1 == 0) {
        local_18 = 2;
      }
      else {
        FUN_1800220b0(0,"ERR-UNIT <%s> for property <%s> differs from UNIT",_Str1,param_2);
        local_18 = 0xffffffff;
      }
    }
  }
  return local_18;
}

/* RVA 0x43c0, FUN_1800043c0 */
undefined8 FUN_1800043c0(char *param_1,longlong param_2)

{
  bool bVar1;
  size_t sVar2;
  int local_18;
  int local_14;
  
  local_14 = 0;
  bVar1 = false;
  for (local_18 = 0; sVar2 = strlen(param_1), local_18 < (int)sVar2; local_18 = local_18 + 1) {
    if (bVar1) {
      if (param_1[local_18] == '\'') {
        *(undefined1 *)(param_2 + local_14) = 0x22;
      }
      else {
        *(char *)(param_2 + local_14) = param_1[local_18];
      }
      local_14 = local_14 + 1;
    }
    else if (param_1[local_18] == '=') {
      bVar1 = true;
    }
  }
  *(undefined1 *)(param_2 + local_14) = 0;
  return 1;
}

/* RVA 0x44a0, Ikc2Bkp */
ulonglong Ikc2Bkp(char *param_1,char *param_2,undefined **param_3,double *param_4)

{
  ulonglong uVar1;
  char *pcVar2;
  int iVar3;
  
                    /* 0x44a0  1  Ikc2Bkp */
  iVar3 = (int)param_3;
  pcVar2 = param_2;
  FUN_180021a60(0xffffffff);
  uVar1 = FUN_180022da0(param_1,pcVar2,param_3,param_4);
  if ((int)uVar1 < 0) {
    uVar1 = uVar1 & 0xffffffff;
  }
  else {
    uVar1 = FUN_180008a30(param_2,iVar3,param_3,param_4);
    if ((int)uVar1 < 0) {
      uVar1 = uVar1 & 0xffffffff;
    }
    else {
      FUN_180021a60(0xffffffff);
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* RVA 0x4510, FUN_180004510 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
FUN_180004510(char *param_1,char *param_2,int param_3,uint *param_4,undefined8 param_5,int param_6)

{
  int iVar1;
  size_t sVar2;
  longlong lVar3;
  undefined1 *puVar4;
  ulonglong uVar5;
  char *pcVar6;
  undefined1 uStack0000000000000000;
  undefined1 auStack_448 [32];
  char *local_428;
  char *local_420;
  char *local_418;
  int local_408;
  int local_404;
  int local_400;
  int local_3fc;
  int local_3f8;
  int local_3f4;
  int local_3f0;
  int local_3ec;
  int local_3e8;
  int local_3e4;
  int local_3e0;
  char local_3dc;
  undefined1 local_3db [3];
  int local_3d8;
  char local_3d4;
  undefined1 local_3d3 [3];
  int local_3d0;
  int local_3cc;
  int local_3c8;
  int local_3c4;
  int local_3c0;
  int local_3bc;
  char *local_3b8;
  int local_3b0;
  int local_3ac;
  int local_3a8;
  int local_3a4;
  int local_3a0;
  int local_39c;
  int local_398;
  int local_394;
  undefined4 local_390;
  ulonglong local_388;
  ulonglong local_380;
  size_t local_378;
  undefined4 local_370;
  undefined4 local_36c;
  int local_368;
  ulonglong local_360;
  undefined8 local_358 [42];
  char local_208;
  undefined1 local_207 [31];
  char local_1e8 [24];
  char local_1d0;
  undefined1 local_1cf [23];
  char local_1b8 [24];
  char local_1a0;
  undefined1 local_19f [23];
  char local_188 [24];
  char local_170;
  undefined1 local_16f [23];
  char local_158;
  undefined1 local_157 [31];
  char local_138 [20];
  char local_124;
  undefined1 local_123 [19];
  char local_110;
  undefined1 local_10f [19];
  char local_fc;
  undefined1 local_fb [19];
  char local_e8;
  undefined1 local_e7 [19];
  char local_d4;
  undefined1 local_d3 [19];
  char local_c0;
  undefined1 local_bf [19];
  char local_ac;
  undefined1 local_ab [19];
  char local_98;
  undefined1 local_97 [19];
  char local_84;
  undefined1 local_83 [27];
  char local_68;
  undefined1 local_67 [23];
  char local_50 [56];
  ulonglong local_18;
  
  local_18 = DAT_180032178 ^ (ulonglong)auStack_448;
  local_3d8 = 0;
  local_3d0 = 0;
  local_50[0] = DAT_1800264e3;
  pcVar6 = local_50;
  for (lVar3 = 0x31; pcVar6 = pcVar6 + 1, lVar3 != 0; lVar3 = lVar3 + -1) {
    *pcVar6 = '\0';
  }
  local_3c0 = 0;
  local_3bc = 0;
  local_3c4 = 0;
  local_390 = 0;
  local_158 = DAT_1800264e3;
  puVar4 = local_157;
  for (lVar3 = 0x13; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  local_170 = DAT_1800264e3;
  puVar4 = local_16f;
  for (lVar3 = 0x13; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  local_188[0] = DAT_1800264e3;
  pcVar6 = local_188;
  for (lVar3 = 0x13; pcVar6 = pcVar6 + 1, lVar3 != 0; lVar3 = lVar3 + -1) {
    *pcVar6 = '\0';
  }
  local_1d0 = DAT_1800264e3;
  puVar4 = local_1cf;
  for (lVar3 = 0x13; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  local_68 = DAT_1800264e3;
  puVar4 = local_67;
  for (lVar3 = 0x13; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  local_138[0] = DAT_1800264e3;
  pcVar6 = local_138;
  for (lVar3 = 0x13; pcVar6 = pcVar6 + 1, lVar3 != 0; lVar3 = lVar3 + -1) {
    *pcVar6 = '\0';
  }
  local_124 = DAT_1800264e3;
  puVar4 = local_123;
  for (lVar3 = 0x13; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  local_110 = DAT_1800264e3;
  puVar4 = local_10f;
  for (lVar3 = 0x13; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  local_fc = DAT_1800264e3;
  puVar4 = local_fb;
  for (lVar3 = 0x13; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  local_e8 = DAT_1800264e3;
  puVar4 = local_e7;
  for (lVar3 = 0x13; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  local_d4 = DAT_1800264e3;
  puVar4 = local_d3;
  for (lVar3 = 0x13; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  local_c0 = DAT_1800264e3;
  puVar4 = local_bf;
  for (lVar3 = 0x13; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  local_ac = DAT_1800264e3;
  puVar4 = local_ab;
  for (lVar3 = 0x13; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  local_98 = DAT_1800264e3;
  puVar4 = local_97;
  for (lVar3 = 0x13; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  local_84 = DAT_1800264e3;
  puVar4 = local_83;
  for (lVar3 = 0x13; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  local_400 = 0;
  local_1e8[0] = DAT_1800264e3;
  pcVar6 = local_1e8;
  for (lVar3 = 0x13; pcVar6 = pcVar6 + 1, lVar3 != 0; lVar3 = lVar3 + -1) {
    *pcVar6 = '\0';
  }
  local_1a0 = DAT_1800264e3;
  puVar4 = local_19f;
  for (lVar3 = 0x13; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  local_1b8[0] = DAT_1800264e3;
  pcVar6 = local_1b8;
  for (lVar3 = 0x13; pcVar6 = pcVar6 + 1, lVar3 != 0; lVar3 = lVar3 + -1) {
    *pcVar6 = '\0';
  }
  local_3fc = 0;
  local_3e0 = 0;
  local_3c8 = 0;
  local_404 = 0;
  local_208 = DAT_1800264e3;
  puVar4 = local_207;
  for (lVar3 = 0x1d; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  local_370 = 0;
  local_36c = 0;
  if (*param_4 == 0) {
    DAT_18002cd08 = 1;
  }
  *param_4 = *param_4 + 1;
  local_360 = strlen(param_2);
  local_3b8 = param_2;
  while ((ulonglong)(longlong)local_3d8 < local_360) {
    for (; *local_3b8 != ' '; local_3b8 = local_3b8 + 1) {
      local_50[local_3fc] = *local_3b8;
      local_3fc = local_3fc + 1;
      local_3d8 = local_3d8 + 1;
    }
    local_388 = (ulonglong)local_3fc;
    if (0x31 < local_388) {
      FUN_1800240b8();
    }
    local_50[local_388] = '\0';
    local_3d8 = local_3d8 + 1;
    local_3b8 = local_3b8 + 1;
    if (local_50[0] != '\0') {
      strcpy(&local_1a0,"");
      strcpy(local_1b8,"");
      FUN_180008840(local_50,(longlong)&local_1a0,local_1b8);
      strcpy(local_50,"");
      local_3fc = 0;
      iVar1 = strcmp(&local_1a0,"TEMPERATURE");
      if (iVar1 == 0) {
        local_3c0 = 1;
        strcpy(&local_158,local_1b8);
      }
      else {
        iVar1 = strcmp(&local_1a0,"PRESSURE");
        if (iVar1 == 0) {
          local_3bc = 1;
          strcpy(&local_170,local_1b8);
        }
        else {
          iVar1 = strcmp(&local_1a0,"SYSTEM-DEF");
          if (iVar1 == 0) {
            strcpy(local_1e8,local_1b8);
          }
          else {
            iVar1 = strcmp(&local_1a0,"PROP-LIST");
            if (iVar1 == 0) {
              iVar1 = strcmp(local_1b8,"EQB");
              if (iVar1 == 0) {
                local_3c4 = 0;
                strcpy(&local_1d0,"");
              }
              else {
                local_3c4 = 1;
                strcpy(&local_1d0,local_1b8);
              }
            }
            else {
              iVar1 = strcmp(&local_1a0,"COMPOSITION");
              if (iVar1 == 0) {
                local_390 = 1;
                strcpy(&local_68,local_1b8);
              }
              else {
                iVar1 = strcmp(&local_1a0,"COMP");
                if (iVar1 == 0) {
                  if (local_400 < 10) {
                    strcpy(local_138 + (longlong)local_400 * 0x14,local_1b8);
                    local_400 = local_400 + 1;
                  }
                }
                else {
                  iVar1 = strcmp(&local_1a0,"EQB");
                  if ((iVar1 == 0) && (iVar1 = strcmp(local_1b8,"\'EQB\'"), iVar1 == 0)) {
                    strcpy(local_188,"");
                  }
                  else {
                    local_3e0 = 0;
                    while (sVar2 = strlen(local_1b8), local_3e0 < (int)sVar2) {
                      if (local_1b8[local_3e0] != '\'') {
                        local_188[local_3d0] = local_1b8[local_3e0];
                        local_3d0 = local_3d0 + 1;
                      }
                      local_3e0 = local_3e0 + 1;
                    }
                    local_380 = (ulonglong)local_3d0;
                    if (0x13 < local_380) {
                      FUN_1800240b8();
                    }
                    local_188[local_380] = '\0';
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  pcVar6 = (char *)0x2;
  uVar5 = 0x2a;
  local_3f4 = FUN_180021730(param_1,local_358,0x2a,2);
  local_368 = local_3f4 + -4;
  local_378 = strlen(local_1e8);
  if (local_3f4 < 5) {
    local_3cc = local_3f4 + -1;
  }
  else if (param_6 == 0) {
    local_3cc = local_3f4 + -1;
  }
  else {
    local_3cc = local_3f4;
  }
  local_408 = 3;
  do {
    if (local_3cc <= local_408) {
      return 1;
    }
    if ((param_6 == 0) || (local_408 < local_3cc + -1)) {
      local_3c8 = 0;
    }
    else {
      local_3c8 = 1;
    }
    if (DAT_18002cd08 == 0) {
      FUN_180007e30(local_3c8,param_5,uVar5,pcVar6);
      if (local_3c8 == 1) {
        return 1;
      }
    }
    else {
      DAT_18002cd08 = 0;
    }
    strcpy(&local_208,(char *)local_358[local_408]);
    if (param_3 == 0) {
      local_3f8 = FUN_180007cb0(&local_208);
      if (local_1e8[local_404] == 'T') {
        if ((local_3c0 != 0) && (iVar1 = strcmp(&local_208,"*"), iVar1 != 0)) {
          if (local_3f8 == 0) {
            local_420 = &local_208;
            local_428 = &local_158;
            pcVar6 = &local_158;
            uVar5 = (ulonglong)*param_4;
            FUN_180007f00(param_5,
                          "%d PROPLIST = \"TEMPERATURE_%s\" PROPLABEL = \"%s\" VALUE = %s <0> <0>",
                          uVar5,pcVar6);
          }
          if (local_3f8 == 1) {
            local_420 = &local_208;
            local_428 = &local_158;
            pcVar6 = &local_158;
            uVar5 = (ulonglong)*param_4;
            FUN_180007f00(param_5,
                          "%d PROPLIST = \"TEMPERATURE_%s\" PROPLABEL = \"%s\" VALUE = \"%s%%\" <0> <0>"
                          ,uVar5,pcVar6);
          }
        }
        local_404 = local_404 + 1;
      }
      else if (local_1e8[local_404] == 'P') {
        if ((local_3bc != 0) && (iVar1 = strcmp(&local_208,"*"), iVar1 != 0)) {
          if (local_3f8 == 0) {
            local_420 = &local_208;
            local_428 = &local_170;
            pcVar6 = &local_170;
            uVar5 = (ulonglong)*param_4;
            FUN_180007f00(param_5,
                          "%d PROPLIST = \"PRESSURE_%s\" PROPLABEL = \"%s\" VALUE = %s <0> <0>",
                          uVar5,pcVar6);
          }
          if (local_3f8 == 1) {
            local_420 = &local_208;
            local_428 = &local_170;
            pcVar6 = &local_170;
            uVar5 = (ulonglong)*param_4;
            FUN_180007f00(param_5,
                          "%d PROPLIST = \"PRESSURE_%s\" PROPLABEL = \"%s\" VALUE = \"%s%%\" <0> <0>"
                          ,uVar5,pcVar6);
          }
        }
        local_404 = local_404 + 1;
      }
      else if ((local_1e8[local_404] == 'X') && (0 < local_400)) {
        local_3f0 = 0;
        local_3dc = DAT_1800264e3;
        puVar4 = local_3db;
        for (lVar3 = 3; lVar3 != 0; lVar3 = lVar3 + -1) {
          *puVar4 = 0;
          puVar4 = puVar4 + 1;
        }
        if ((local_404 == 1) || (local_1e8[local_404 + -1] != 'X')) {
          local_398 = local_404 + 1;
          sVar2 = strlen(local_1e8);
          if ((local_398 < (int)sVar2) && (local_1e8[local_404 + 1] == 'X')) {
            strcpy(&local_3dc,"X1_");
          }
          else {
            strcpy(&local_3dc,"X_");
          }
        }
        else {
          strcpy(&local_3dc,"X2_");
        }
        for (local_3f0 = 0; local_3f0 < local_400 + -1; local_3f0 = local_3f0 + 1) {
          iVar1 = strcmp(&local_208,"*");
          if (iVar1 == 0) {
            if (local_3f0 < local_400 + -2) {
              local_408 = local_408 + 1;
              strcpy(&local_208,(char *)local_358[local_408]);
              local_3f8 = FUN_180007cb0(&local_208);
            }
          }
          else {
            if (local_3f8 == 0) {
              local_420 = local_138 + (longlong)local_3f0 * 0x14;
              local_428 = local_138 + (longlong)local_3f0 * 0x14;
              local_418 = &local_208;
              pcVar6 = &local_3dc;
              uVar5 = (ulonglong)*param_4;
              FUN_180007f00(param_5,"%d PROPLIST = \"%s%s\" PROPLABEL = \"%s\" VALUE = %s <0> <0>",
                            uVar5,pcVar6);
            }
            if (local_3f8 == 1) {
              local_420 = local_138 + (longlong)local_3f0 * 0x14;
              local_428 = local_138 + (longlong)local_3f0 * 0x14;
              local_418 = &local_208;
              pcVar6 = &local_3dc;
              uVar5 = (ulonglong)*param_4;
              FUN_180007f00(param_5,
                            "%d PROPLIST = \"%s%s\" PROPLABEL = \"%s\" VALUE = \"%s%%\" <0> <0>",
                            uVar5,pcVar6);
            }
            if (local_3f0 != local_400 + -2) {
              if ((param_6 == 0) || (local_408 < local_3f4 + -2)) {
                local_39c = 0;
              }
              else {
                local_39c = 1;
              }
              FUN_180007e30(local_39c,param_5,uVar5,pcVar6);
              local_408 = local_408 + 1;
              strcpy(&local_208,(char *)local_358[local_408]);
              local_3f8 = FUN_180007cb0(&local_208);
            }
          }
        }
        local_404 = local_404 + 1;
      }
      else if ((local_1e8[local_404] == 'Y') && (0 < local_400)) {
        for (local_3ec = 0; local_3ec < local_400 + -1; local_3ec = local_3ec + 1) {
          iVar1 = strcmp(&local_208,"*");
          if (iVar1 == 0) {
            if (local_3ec < local_400 + -2) {
              local_408 = local_408 + 1;
              strcpy(&local_208,(char *)local_358[local_408]);
              local_3f8 = FUN_180007cb0(&local_208);
            }
          }
          else {
            if (local_3f8 == 0) {
              local_428 = local_138 + (longlong)local_3ec * 0x14;
              pcVar6 = local_138 + (longlong)local_3ec * 0x14;
              local_420 = &local_208;
              uVar5 = (ulonglong)*param_4;
              FUN_180007f00(param_5,"%d PROPLIST = \"Y_%s\" PROPLABEL = \"%s\" VALUE = %s <0> <0>",
                            uVar5,pcVar6);
            }
            if (local_3f8 == 1) {
              local_428 = local_138 + (longlong)local_3ec * 0x14;
              pcVar6 = local_138 + (longlong)local_3ec * 0x14;
              local_420 = &local_208;
              uVar5 = (ulonglong)*param_4;
              FUN_180007f00(param_5,
                            "%d PROPLIST = \"Y_%s\" PROPLABEL = \"%s\" VALUE = \"%s%%\" <0> <0>",
                            uVar5,pcVar6);
            }
            if (local_3ec != local_400 + -2) {
              if ((param_6 == 0) || (local_408 < local_3f4 + -2)) {
                local_3b0 = 0;
              }
              else {
                local_3b0 = 1;
              }
              FUN_180007e30(local_3b0,param_5,uVar5,pcVar6);
              local_408 = local_408 + 1;
              strcpy(&local_208,(char *)local_358[local_408]);
              local_3f8 = FUN_180007cb0(&local_208);
            }
          }
        }
        local_404 = local_404 + 1;
      }
      else if ((local_3c4 != 0) && (local_378 < (ulonglong)(longlong)(local_404 + 1))) {
        if ((&uStack0000000000000000 == (undefined1 *)0x1d0) ||
           ((iVar1 = strcmp(&local_1d0,"HNRYMX"), iVar1 != 0 &&
            (iVar1 = strcmp(&local_1d0,"GAMMA"), iVar1 != 0)))) {
          if (local_3f8 == 0) {
            local_418 = &local_208;
            local_420 = local_188;
            local_428 = local_188;
            pcVar6 = &local_1d0;
            uVar5 = (ulonglong)*param_4;
            FUN_180007f00(param_5,"%d PROPLIST = \"%s_%s\" PROPLABEL = \"%s\" VALUE = %s <0> <0>",
                          uVar5,pcVar6);
          }
          if (local_3f8 == 1) {
            local_418 = &local_208;
            local_420 = local_188;
            local_428 = local_188;
            pcVar6 = &local_1d0;
            uVar5 = (ulonglong)*param_4;
            FUN_180007f00(param_5,
                          "%d PROPLIST = \"%s_%s\" PROPLABEL = \"%s\" VALUE = \"%s%%\" <0> <0>",
                          uVar5,pcVar6);
          }
        }
        else {
          for (local_3e8 = 0; local_3e8 < local_400; local_3e8 = local_3e8 + 1) {
            iVar1 = strcmp(&local_208,"*");
            if (iVar1 == 0) {
              if (local_3e8 < local_400 + -1) {
                local_408 = local_408 + 1;
                strcpy(&local_208,(char *)local_358[local_408]);
                local_3f8 = FUN_180007cb0(&local_208);
              }
            }
            else {
              if (local_3f8 == 0) {
                local_420 = local_138 + (longlong)local_3e8 * 0x14;
                local_428 = local_138 + (longlong)local_3e8 * 0x14;
                local_418 = &local_208;
                pcVar6 = &local_1d0;
                uVar5 = (ulonglong)*param_4;
                FUN_180007f00(param_5,
                              "%d PROPLIST = \"%s_%s\" PROPLABEL = \"%s\" VALUE = %s <0> <0>",uVar5,
                              pcVar6);
              }
              if (local_3f8 == 1) {
                local_420 = local_138 + (longlong)local_3e8 * 0x14;
                local_428 = local_138 + (longlong)local_3e8 * 0x14;
                local_418 = &local_208;
                pcVar6 = &local_1d0;
                uVar5 = (ulonglong)*param_4;
                FUN_180007f00(param_5,
                              "%d PROPLIST = \"%s_%s\" PROPLABEL = \"%s\" VALUE = \"%s%%\" <0> <0>",
                              uVar5,pcVar6);
              }
              if (local_3e8 != local_400 + -1) {
                if ((param_6 == 0) || (local_408 < local_3f4 + -2)) {
                  local_3ac = 0;
                }
                else {
                  local_3ac = 1;
                }
                FUN_180007e30(local_3ac,param_5,uVar5,pcVar6);
                local_408 = local_408 + 1;
                strcpy(&local_208,(char *)local_358[local_408]);
                local_3f8 = FUN_180007cb0(&local_208);
              }
            }
          }
        }
      }
    }
    else if (param_3 == 1) {
      if (local_1e8[local_404] == 'T') {
        if ((local_3c0 != 0) && (iVar1 = strcmp(&local_208,"*"), iVar1 != 0)) {
          local_420 = &local_208;
          local_428 = &local_158;
          pcVar6 = &local_158;
          uVar5 = (ulonglong)*param_4;
          FUN_180007f00(param_5,
                        "%d PROPLIST = \"TEMPERATURE_%s\" PROPLABEL = \"%s\" VALUE = %s <0> <0>",
                        uVar5,pcVar6);
        }
        local_404 = local_404 + 1;
      }
      else if (local_1e8[local_404] == 'P') {
        if ((local_3bc != 0) && (iVar1 = strcmp(&local_208,"*"), iVar1 != 0)) {
          local_420 = &local_208;
          local_428 = &local_170;
          pcVar6 = &local_170;
          uVar5 = (ulonglong)*param_4;
          FUN_180007f00(param_5,
                        "%d PROPLIST = \"PRESSURE_%s\" PROPLABEL = \"%s\" VALUE = %s <0> <0>",uVar5,
                        pcVar6);
        }
        local_404 = local_404 + 1;
      }
      else if ((local_1e8[local_404] == 'X') && (0 < local_400)) {
        local_3e4 = 0;
        local_3d4 = DAT_1800264e3;
        puVar4 = local_3d3;
        for (lVar3 = 3; lVar3 != 0; lVar3 = lVar3 + -1) {
          *puVar4 = 0;
          puVar4 = puVar4 + 1;
        }
        if ((local_404 == 1) || (local_1e8[local_404 + -1] != 'X')) {
          local_394 = local_404 + 1;
          sVar2 = strlen(local_1e8);
          if ((local_394 < (int)sVar2) && (local_1e8[local_404 + 1] == 'X')) {
            strcpy(&local_3d4,"X1_");
          }
          else {
            strcpy(&local_3d4,"X_");
          }
        }
        else {
          strcpy(&local_3d4,"X2_");
        }
        for (local_3e4 = 0; local_3e4 < local_400 + -1; local_3e4 = local_3e4 + 1) {
          iVar1 = strcmp(&local_208,"*");
          if (iVar1 == 0) {
            if (local_3e4 < local_400 + -2) {
              local_408 = local_408 + 1;
              strcpy(&local_208,(char *)local_358[local_408]);
            }
          }
          else {
            local_420 = local_138 + (longlong)local_3e4 * 0x14;
            local_428 = local_138 + (longlong)local_3e4 * 0x14;
            local_418 = &local_208;
            pcVar6 = &local_3d4;
            uVar5 = (ulonglong)*param_4;
            FUN_180007f00(param_5,"%d PROPLIST = \"%s%s\" PROPLABEL = \"%s\" VALUE = %s <0> <0>",
                          uVar5,pcVar6);
            if (local_3e4 != local_400 + -2) {
              if ((param_6 == 0) || (local_408 < local_3f4 + -2)) {
                local_3a8 = 0;
              }
              else {
                local_3a8 = 1;
              }
              FUN_180007e30(local_3a8,param_5,uVar5,pcVar6);
              local_408 = local_408 + 1;
              strcpy(&local_208,(char *)local_358[local_408]);
            }
          }
        }
        local_404 = local_404 + 1;
      }
      else if ((local_1e8[local_404] == 'Y') && (0 < local_400)) {
        for (local_3fc = 0; local_3fc < local_400 + -1; local_3fc = local_3fc + 1) {
          iVar1 = strcmp(&local_208,"*");
          if (iVar1 == 0) {
            if (local_3fc < local_400 + -2) {
              local_408 = local_408 + 1;
              strcpy(&local_208,(char *)local_358[local_408]);
            }
          }
          else {
            local_428 = local_138 + (longlong)local_3fc * 0x14;
            pcVar6 = local_138 + (longlong)local_3fc * 0x14;
            local_420 = &local_208;
            uVar5 = (ulonglong)*param_4;
            FUN_180007f00(param_5,"%d PROPLIST = \"Y_%s\" PROPLABEL = \"%s\" VALUE = %s <0> <0>",
                          uVar5,pcVar6);
            if (local_3fc != local_400 + -2) {
              if ((param_6 == 0) || (local_408 < local_3f4 + -2)) {
                local_3a4 = 0;
              }
              else {
                local_3a4 = 1;
              }
              FUN_180007e30(local_3a4,param_5,uVar5,pcVar6);
              local_408 = local_408 + 1;
              strcpy(&local_208,(char *)local_358[local_408]);
            }
          }
        }
        local_404 = local_404 + 1;
      }
      else if ((local_3c4 != 0) && (local_378 < (ulonglong)(longlong)(local_404 + 1))) {
        if ((&uStack0000000000000000 == (undefined1 *)0x1d0) ||
           ((iVar1 = strcmp(&local_1d0,"HNRYMX"), iVar1 != 0 &&
            (iVar1 = strcmp(&local_1d0,"GAMMA"), iVar1 != 0)))) {
          local_418 = &local_208;
          local_420 = local_188;
          local_428 = local_188;
          pcVar6 = &local_1d0;
          uVar5 = (ulonglong)*param_4;
          FUN_180007f00(param_5,"%d PROPLIST = \"%s_%s\" PROPLABEL = \"%s\" VALUE = %s <0> <0>",
                        uVar5,pcVar6);
        }
        else {
          for (local_3fc = 0; local_3fc < local_400; local_3fc = local_3fc + 1) {
            iVar1 = strcmp(&local_208,"*");
            if (iVar1 == 0) {
              if (local_3fc < local_400 + -1) {
                local_408 = local_408 + 1;
                strcpy(&local_208,(char *)local_358[local_408]);
              }
            }
            else {
              local_420 = local_138 + (longlong)local_3fc * 0x14;
              local_428 = local_138 + (longlong)local_3fc * 0x14;
              local_418 = &local_208;
              pcVar6 = &local_1d0;
              uVar5 = (ulonglong)*param_4;
              FUN_180007f00(param_5,"%d PROPLIST = \"%s_%s\" PROPLABEL = \"%s\" VALUE = %s <0> <0>",
                            uVar5,pcVar6);
              if (local_3fc != local_400 + -1) {
                if ((param_6 == 0) || (local_408 < local_3f4 + -2)) {
                  local_3a0 = 0;
                }
                else {
                  local_3a0 = 1;
                }
                FUN_180007e30(local_3a0,param_5,uVar5,pcVar6);
                local_408 = local_408 + 1;
                strcpy(&local_208,(char *)local_358[local_408]);
              }
            }
          }
        }
      }
    }
    local_408 = local_408 + 1;
  } while( true );
}

/* RVA 0x5e10, FUN_180005e10 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
FUN_180005e10(char *param_1,char *param_2,int param_3,uint *param_4,undefined8 param_5,int param_6)

{
  int iVar1;
  size_t sVar2;
  longlong lVar3;
  undefined1 *puVar4;
  ulonglong uVar5;
  char *pcVar6;
  undefined1 auStack_268 [32];
  char *local_248;
  char *local_240;
  char *local_238;
  int local_228;
  int local_224;
  int local_220;
  int local_21c;
  int local_218;
  int local_214;
  int local_210;
  int local_20c;
  int local_208;
  int local_204;
  int local_200;
  int local_1fc;
  int local_1f8;
  int local_1f4;
  char *local_1f0;
  int local_1e8;
  int local_1e4;
  size_t local_1e0;
  undefined4 local_1d8;
  undefined4 local_1d4;
  ulonglong local_1d0;
  ulonglong local_1c8;
  ulonglong local_1c0;
  ulonglong local_1b8;
  undefined8 local_1a8 [10];
  char local_158;
  undefined1 local_157 [23];
  char local_140 [32];
  char local_120 [24];
  char local_108 [24];
  char local_f0 [24];
  char local_d8;
  undefined1 local_d7 [23];
  char local_c0;
  undefined1 local_bf [23];
  char local_a8;
  undefined1 local_a7 [23];
  char local_90;
  undefined1 local_8f [23];
  char local_78 [32];
  char local_58;
  undefined1 local_57 [23];
  char local_40;
  undefined1 local_3f [23];
  char local_28;
  undefined1 local_27 [23];
  ulonglong local_10;
  
  local_10 = DAT_180032178 ^ (ulonglong)auStack_268;
  local_208 = 0;
  local_78[0] = DAT_1800264e3;
  pcVar6 = local_78;
  for (lVar3 = 0x1d; pcVar6 = pcVar6 + 1, lVar3 != 0; lVar3 = lVar3 + -1) {
    *pcVar6 = '\0';
  }
  local_1f8 = 0;
  local_1f4 = 0;
  local_200 = 0;
  local_1d8 = 0;
  local_210 = 0;
  local_204 = 0;
  local_1d4 = 0;
  local_a8 = DAT_1800264e3;
  puVar4 = local_a7;
  for (lVar3 = 0x13; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  local_90 = DAT_1800264e3;
  puVar4 = local_8f;
  for (lVar3 = 0x13; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  local_f0[0] = DAT_1800264e3;
  pcVar6 = local_f0;
  for (lVar3 = 0x13; pcVar6 = pcVar6 + 1, lVar3 != 0; lVar3 = lVar3 + -1) {
    *pcVar6 = '\0';
  }
  local_58 = DAT_1800264e3;
  puVar4 = local_57;
  for (lVar3 = 0x13; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  local_28 = DAT_1800264e3;
  puVar4 = local_27;
  for (lVar3 = 0x13; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  local_158 = DAT_1800264e3;
  puVar4 = local_157;
  for (lVar3 = 0x13; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  local_c0 = DAT_1800264e3;
  puVar4 = local_bf;
  for (lVar3 = 0x13; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  local_40 = DAT_1800264e3;
  puVar4 = local_3f;
  for (lVar3 = 0x13; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  local_108[0] = DAT_1800264e3;
  pcVar6 = local_108;
  for (lVar3 = 0x13; pcVar6 = pcVar6 + 1, lVar3 != 0; lVar3 = lVar3 + -1) {
    *pcVar6 = '\0';
  }
  local_d8 = DAT_1800264e3;
  puVar4 = local_d7;
  for (lVar3 = 0x13; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  local_120[0] = DAT_1800264e3;
  pcVar6 = local_120;
  for (lVar3 = 0x13; pcVar6 = pcVar6 + 1, lVar3 != 0; lVar3 = lVar3 + -1) {
    *pcVar6 = '\0';
  }
  local_218 = 0;
  local_224 = 0;
  local_214 = 0;
  local_1fc = 0;
  local_1e4 = 0;
  *param_4 = *param_4 + 1;
  local_1b8 = strlen(param_2);
  local_1f0 = param_2;
LAB_18000607f:
  do {
    if (local_1b8 <= (ulonglong)(longlong)local_208) break;
    for (; *local_1f0 != ' '; local_1f0 = local_1f0 + 1) {
      local_78[local_218] = *local_1f0;
      local_218 = local_218 + 1;
      local_208 = local_208 + 1;
    }
    local_1d0 = (ulonglong)local_218;
    if (0x1d < local_1d0) {
      FUN_1800240b8();
    }
    local_78[local_1d0] = '\0';
    local_208 = local_208 + 1;
    local_1f0 = local_1f0 + 1;
    if (local_78[0] != '\0') {
      strcpy(&local_d8,"");
      strcpy(local_120,"");
      FUN_180008840(local_78,(longlong)&local_d8,local_120);
      strcpy(local_78,"");
      local_218 = 0;
      iVar1 = strcmp(&local_d8,"TEMPERATURE");
      if (iVar1 == 0) {
        local_1f8 = 1;
        strcpy(&local_a8,local_120);
        goto LAB_18000607f;
      }
      iVar1 = strcmp(&local_d8,"PRESSURE");
      if (iVar1 == 0) {
        local_1f4 = 1;
        strcpy(&local_90,local_120);
        goto LAB_18000607f;
      }
      iVar1 = strcmp(&local_d8,"SYSTEM-DEF");
      if (iVar1 == 0) {
        strcpy(local_108,local_120);
        goto LAB_18000607f;
      }
      iVar1 = strcmp(&local_d8,"PROP-LIST");
      if (iVar1 == 0) {
        iVar1 = strcmp(local_120,"EQB");
        if (iVar1 == 0) {
          local_200 = 0;
          strcpy(&local_58,"");
        }
        else {
          local_200 = 1;
          strcpy(&local_58,local_120);
        }
        goto LAB_18000607f;
      }
      iVar1 = strcmp(&local_d8,"COMPOSITION");
      if (iVar1 == 0) {
        local_1d8 = 1;
        strcpy(&local_28,local_120);
        goto LAB_18000607f;
      }
      iVar1 = strcmp(&local_d8,"COMP");
      if (iVar1 == 0) {
        if (local_158 == '\0') {
          local_210 = 1;
          strcpy(&local_158,local_120);
          goto LAB_18000607f;
        }
        if (local_c0 == '\0') {
          local_204 = 1;
          strcpy(&local_c0,local_120);
          goto LAB_18000607f;
        }
        if (local_40 == '\0') {
          local_1d4 = 1;
          strcpy(&local_40,local_120);
          goto LAB_18000607f;
        }
      }
      else {
        iVar1 = strcmp(&local_d8,"EQB");
        if ((iVar1 == 0) && (iVar1 = strcmp(local_120,"\'EQB\'"), iVar1 == 0)) {
          strcpy(local_f0,"");
          goto LAB_18000607f;
        }
      }
      local_224 = 0;
      while (sVar2 = strlen(local_120), local_224 < (int)sVar2) {
        if (local_120[local_224] != '\'') {
          local_f0[local_214] = local_120[local_224];
          local_214 = local_214 + 1;
        }
        local_224 = local_224 + 1;
      }
      local_1c8 = (ulonglong)local_214;
      if (0x13 < local_1c8) {
        FUN_1800240b8();
      }
      local_f0[local_1c8] = '\0';
    }
  } while( true );
  pcVar6 = (char *)0x2;
  uVar5 = 10;
  local_20c = FUN_180021730(param_1,local_1a8,10,2);
  local_1e8 = local_20c + -4;
  local_1e0 = strlen(local_108);
  local_21c = 3;
  do {
    if (local_20c + -1 <= local_21c) {
      return 1;
    }
    strcpy(local_140,(char *)local_1a8[local_21c]);
    iVar1 = strcmp(local_140,"*");
    if (iVar1 != 0) {
      local_220 = local_21c + -3;
      local_214 = 0;
      strcpy(local_78,"");
      if (param_3 == 0) {
        local_228 = 0;
        local_218 = 0;
LAB_1800065b1:
        sVar2 = strlen(local_140);
        if (local_218 < (int)sVar2) {
          if (local_140[local_218] != '-') break;
          local_228 = 1;
          local_224 = 0;
          while (sVar2 = strlen(local_140), local_224 < (int)sVar2) {
            if (local_140[local_224] != '-') {
              local_78[local_214] = local_140[local_224];
              local_214 = local_214 + 1;
            }
            local_224 = local_224 + 1;
          }
          local_1c0 = (ulonglong)local_214;
          if (0x1d < local_1c0) {
            FUN_1800240b8();
          }
          local_78[local_1c0] = '\0';
          strcpy(local_140,local_78);
        }
        if ((local_108[local_220] == 'T') && (local_1f8 != 0)) {
          if (local_228 == 0) {
            local_240 = local_140;
            local_248 = &local_a8;
            pcVar6 = &local_a8;
            uVar5 = (ulonglong)*param_4;
            FUN_180007f00(param_5,
                          "%d PROPLIST = \"TEMPERATURE_%s\" PROPLABEL = \"%s\" VALUE = %s <0> <0>",
                          uVar5,pcVar6);
          }
          if (local_228 == 1) {
            local_240 = local_140;
            local_248 = &local_a8;
            pcVar6 = &local_a8;
            uVar5 = (ulonglong)*param_4;
            FUN_180007f00(param_5,
                          "%d PROPLIST = \"TEMPERATURE_%s\" PROPLABEL = \"%s\" VALUE = \"%s%%\" <0> <0>"
                          ,uVar5,pcVar6);
          }
        }
        if ((local_108[local_220] == 'P') && (local_1f4 != 0)) {
          if (local_228 == 0) {
            local_240 = local_140;
            local_248 = &local_90;
            pcVar6 = &local_90;
            uVar5 = (ulonglong)*param_4;
            FUN_180007f00(param_5,
                          "%d PROPLIST = \"PRESSURE_%s\" PROPLABEL = \"%s\" VALUE = %s <0> <0>",
                          uVar5,pcVar6);
          }
          if (local_228 == 1) {
            local_240 = local_140;
            local_248 = &local_90;
            pcVar6 = &local_90;
            uVar5 = (ulonglong)*param_4;
            FUN_180007f00(param_5,
                          "%d PROPLIST = \"PRESSURE_%s\" PROPLABEL = \"%s\" VALUE = \"%s%%\" <0> <0>"
                          ,uVar5,pcVar6);
          }
        }
        if ((local_108[local_220] == 'X') && (local_210 != 0)) {
          if (local_228 == 0) {
            local_240 = local_140;
            local_248 = &local_158;
            pcVar6 = &local_158;
            uVar5 = (ulonglong)*param_4;
            FUN_180007f00(param_5,"%d PROPLIST = \"X_%s\" PROPLABEL = \"%s\" VALUE = %s <0> <0>",
                          uVar5,pcVar6);
          }
          if (local_228 == 1) {
            local_240 = local_140;
            local_248 = &local_158;
            pcVar6 = &local_158;
            uVar5 = (ulonglong)*param_4;
            FUN_180007f00(param_5,
                          "%d PROPLIST = \"X_%s\" PROPLABEL = \"%s\" VALUE = \"%s%%\" <0> <0>",uVar5
                          ,pcVar6);
          }
        }
        if (((ulonglong)(longlong)local_1e8 <= local_1e0) || (local_f0[0] != '\0')) {
LAB_180006aa9:
          if ((local_108[local_220] == 'Y') && (local_210 != 0)) {
            if (local_228 == 0) {
              local_240 = local_140;
              local_248 = &local_158;
              pcVar6 = &local_158;
              uVar5 = (ulonglong)*param_4;
              FUN_180007f00(param_5,"%d PROPLIST = \"Y_%s\" PROPLABEL = \"%s\" VALUE = %s <0> <0>",
                            uVar5,pcVar6);
            }
            if (local_228 == 1) {
              local_240 = local_140;
              local_248 = &local_158;
              pcVar6 = &local_158;
              uVar5 = (ulonglong)*param_4;
              FUN_180007f00(param_5,
                            "%d PROPLIST = \"Y_%s\" PROPLABEL = \"%s\" VALUE = \"%s%%\" <0> <0>",
                            uVar5,pcVar6);
            }
          }
          if (local_200 == 0) {
            if ((param_6 == 0) || (local_21c < local_20c + -2)) {
              FUN_180007f00(param_5,&DAT_180027250,uVar5,pcVar6);
            }
            else {
              FUN_180007f00(param_5,&DAT_180027248,uVar5,pcVar6);
            }
          }
          else {
            if (local_1e0 < (ulonglong)(longlong)(local_220 + 1)) {
              if (local_228 == 0) {
                local_238 = local_140;
                local_240 = local_f0;
                local_248 = local_f0;
                pcVar6 = &local_58;
                uVar5 = (ulonglong)*param_4;
                FUN_180007f00(param_5,
                              "%d PROPLIST = \"%s_%s\" PROPLABEL = \"%s\" VALUE = %s <0> <0>",uVar5,
                              pcVar6);
              }
              if (local_228 == 1) {
                local_238 = local_140;
                local_240 = local_f0;
                local_248 = local_f0;
                pcVar6 = &local_58;
                uVar5 = (ulonglong)*param_4;
                FUN_180007f00(param_5,
                              "%d PROPLIST = \"%s_%s\" PROPLABEL = \"%s\" VALUE = \"%s%%\" <0> <0>",
                              uVar5,pcVar6);
              }
            }
            if ((param_6 == 0) || (local_21c < local_20c + -2)) {
              FUN_180007f00(param_5,&DAT_180027250,uVar5,pcVar6);
            }
            else {
              FUN_180007f00(param_5,&DAT_180027248,uVar5,pcVar6);
            }
          }
          goto LAB_180006ca9;
        }
        if (local_1fc == 0) {
LAB_1800069b0:
          if (local_108[local_220 + -1] != 'X') goto LAB_180006aa9;
          if ((local_228 == 0) && (local_210 != 0)) {
            local_240 = local_140;
            local_248 = &local_158;
            pcVar6 = &local_158;
            uVar5 = (ulonglong)*param_4;
            FUN_180007f00(param_5,"%d PROPLIST = \"X_%s\" PROPLABEL = \"%s\" VALUE = %s <0> <0>",
                          uVar5,pcVar6);
            FUN_180007f00(param_5,&DAT_180027250,uVar5,pcVar6);
            local_1fc = 1;
          }
          else {
            if ((local_228 != 1) || (local_210 == 0)) goto LAB_180006aa9;
            local_240 = local_140;
            local_248 = &local_158;
            pcVar6 = &local_158;
            uVar5 = (ulonglong)*param_4;
            FUN_180007f00(param_5,
                          "%d PROPLIST = \"X_%s\" PROPLABEL = \"%s\" VALUE = \"%s%%\" <0> <0>",uVar5
                          ,pcVar6);
            FUN_180007f00(param_5,&DAT_180027250,uVar5,pcVar6);
            local_1fc = 1;
          }
        }
        else if ((local_228 == 0) && (local_204 != 0)) {
          local_240 = local_140;
          local_248 = &local_c0;
          pcVar6 = &local_c0;
          uVar5 = (ulonglong)*param_4;
          FUN_180007f00(param_5,"%d PROPLIST = \"Y_%s\" PROPLABEL = \"%s\" VALUE = %s <0> <0>",uVar5
                        ,pcVar6);
          FUN_180007f00(param_5,&DAT_180027250,uVar5,pcVar6);
        }
        else {
          if ((local_228 != 1) || (local_204 == 0)) goto LAB_1800069b0;
          local_240 = local_140;
          local_248 = &local_c0;
          pcVar6 = &local_c0;
          uVar5 = (ulonglong)*param_4;
          FUN_180007f00(param_5,"%d PROPLIST = \"Y_%s\" PROPLABEL = \"%s\" VALUE = \"%s%%\" <0> <0>"
                        ,uVar5,pcVar6);
          FUN_180007f00(param_5,&DAT_180027250,uVar5,pcVar6);
        }
        goto LAB_180006512;
      }
LAB_180006ca9:
      if (param_3 == 1) {
        if ((local_108[local_220] == 'T') && (local_1f8 != 0)) {
          local_240 = local_140;
          local_248 = &local_a8;
          pcVar6 = &local_a8;
          uVar5 = (ulonglong)*param_4;
          FUN_180007f00(param_5,
                        "%d PROPLIST = \"TEMPERATURE_%s\" PROPLABEL = \"%s\" VALUE = %s <0> <0>",
                        uVar5,pcVar6);
        }
        if ((local_108[local_220] == 'P') && (local_1f4 != 0)) {
          local_240 = local_140;
          local_248 = &local_90;
          pcVar6 = &local_90;
          uVar5 = (ulonglong)*param_4;
          FUN_180007f00(param_5,
                        "%d PROPLIST = \"PRESSURE_%s\" PROPLABEL = \"%s\" VALUE = %s <0> <0>",uVar5,
                        pcVar6);
        }
        if ((local_108[local_220] == 'X') && (local_210 != 0)) {
          local_240 = local_140;
          local_248 = &local_158;
          pcVar6 = &local_158;
          uVar5 = (ulonglong)*param_4;
          FUN_180007f00(param_5,"%d PROPLIST = \"X_%s\" PROPLABEL = \"%s\" VALUE = %s <0> <0>",uVar5
                        ,pcVar6);
        }
        if ((local_1e0 < (ulonglong)(longlong)local_1e8) && (local_f0[0] == '\0')) {
          if ((local_1e4 == 0) || (local_204 == 0)) {
            if ((local_108[local_220 + -1] != 'X') || (local_210 == 0)) goto LAB_180006f4a;
            local_240 = local_140;
            local_248 = &local_158;
            pcVar6 = &local_158;
            uVar5 = (ulonglong)*param_4;
            FUN_180007f00(param_5,"%d PROPLIST = \"X_%s\" PROPLABEL = \"%s\" VALUE = %s <0> <0>",
                          uVar5,pcVar6);
            if ((param_6 == 0) || (local_21c < local_20c + -2)) {
              FUN_180007f00(param_5,&DAT_180027250,uVar5,pcVar6);
            }
            else {
              FUN_180007f00(param_5,&DAT_180027248,uVar5,pcVar6);
            }
            local_1e4 = 1;
          }
          else {
            local_240 = local_140;
            local_248 = &local_c0;
            pcVar6 = &local_c0;
            uVar5 = (ulonglong)*param_4;
            FUN_180007f00(param_5,"%d PROPLIST = \"Y_%s\" PROPLABEL = \"%s\" VALUE = %s <0> <0>",
                          uVar5,pcVar6);
            if ((param_6 == 0) || (local_21c < local_20c + -2)) {
              FUN_180007f00(param_5,&DAT_180027250,uVar5,pcVar6);
            }
            else {
              FUN_180007f00(param_5,&DAT_180027248,uVar5,pcVar6);
            }
          }
        }
        else {
LAB_180006f4a:
          if ((local_108[local_220] == 'Y') && (local_210 != 0)) {
            local_240 = local_140;
            local_248 = &local_158;
            pcVar6 = &local_158;
            uVar5 = (ulonglong)*param_4;
            FUN_180007f00(param_5,"%d PROPLIST = \"Y_%s\" PROPLABEL = \"%s\" VALUE = %s <0> <0>",
                          uVar5,pcVar6);
          }
          if (local_200 == 0) {
            if ((param_6 == 0) || (local_21c < local_20c + -2)) {
              FUN_180007f00(param_5,&DAT_180027250,uVar5,pcVar6);
            }
            else {
              FUN_180007f00(param_5,&DAT_180027248,uVar5,pcVar6);
            }
          }
          else {
            if (local_1e0 < (ulonglong)(longlong)(local_220 + 1)) {
              local_238 = local_140;
              local_240 = local_f0;
              local_248 = local_f0;
              pcVar6 = &local_58;
              uVar5 = (ulonglong)*param_4;
              FUN_180007f00(param_5,"%d PROPLIST = \"%s_%s\" PROPLABEL = \"%s\" VALUE = %s <0> <0>",
                            uVar5,pcVar6);
            }
            if ((param_6 == 0) || (local_21c < local_20c + -2)) {
              FUN_180007f00(param_5,&DAT_180027250,uVar5,pcVar6);
            }
            else {
              FUN_180007f00(param_5,&DAT_180027248,uVar5,pcVar6);
            }
          }
        }
      }
    }
LAB_180006512:
    local_21c = local_21c + 1;
  } while( true );
  local_218 = local_218 + 1;
  goto LAB_1800065b1;
}

