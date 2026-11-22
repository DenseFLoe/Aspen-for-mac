/* RVA 0x70c0, FUN_1800070c0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_1800070c0(char *param_1,char *param_2,int param_3,uint *param_4,undefined8 param_5)

{
  int iVar1;
  size_t sVar2;
  longlong lVar3;
  undefined1 *puVar4;
  ulonglong uVar5;
  char *pcVar6;
  undefined1 auStack_288 [32];
  char *local_268;
  char *local_260;
  char *local_258;
  int local_248;
  int local_244;
  int local_240;
  int local_23c;
  int local_238;
  int local_234;
  int local_230;
  int local_22c;
  int local_228;
  int local_224;
  char *local_220;
  int local_218;
  size_t local_210;
  ulonglong local_208;
  ulonglong local_200;
  ulonglong local_1f8;
  ulonglong local_1f0;
  undefined4 local_1e8;
  undefined4 local_1e4;
  undefined4 local_1e0;
  undefined4 local_1dc;
  int local_1d8;
  ulonglong local_1d0;
  undefined8 local_1c8 [10];
  char local_178 [24];
  char local_160 [24];
  char local_148 [32];
  char local_128 [24];
  char local_110;
  undefined1 local_10f [23];
  char local_f8;
  undefined1 local_f7 [23];
  char local_e0 [24];
  char local_c8;
  undefined1 local_c7 [23];
  char local_b0 [56];
  char local_78;
  undefined1 local_77 [23];
  char local_60;
  undefined1 local_5f [23];
  char local_48;
  undefined1 local_47 [23];
  char local_30;
  undefined1 local_2f [23];
  ulonglong local_18;
  
  local_18 = DAT_180032178 ^ (ulonglong)auStack_288;
  local_234 = 0;
  local_b0[0] = DAT_1800264e3;
  pcVar6 = local_b0;
  for (lVar3 = 0x31; pcVar6 = pcVar6 + 1, lVar3 != 0; lVar3 = lVar3 + -1) {
    *pcVar6 = '\0';
  }
  local_224 = 0;
  local_22c = 0;
  local_228 = 0;
  local_1e8 = 0;
  local_1e4 = 0;
  local_1e0 = 0;
  local_1dc = 0;
  local_f8 = DAT_1800264e3;
  puVar4 = local_f7;
  for (lVar3 = 0x13; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  local_128[0] = DAT_1800264e3;
  pcVar6 = local_128;
  for (lVar3 = 0x13; pcVar6 = pcVar6 + 1, lVar3 != 0; lVar3 = lVar3 + -1) {
    *pcVar6 = '\0';
  }
  local_160[0] = DAT_1800264e3;
  pcVar6 = local_160;
  for (lVar3 = 0x13; pcVar6 = pcVar6 + 1, lVar3 != 0; lVar3 = lVar3 + -1) {
    *pcVar6 = '\0';
  }
  local_c8 = DAT_1800264e3;
  puVar4 = local_c7;
  for (lVar3 = 0x13; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  local_78 = DAT_1800264e3;
  puVar4 = local_77;
  for (lVar3 = 0x13; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  local_60 = DAT_1800264e3;
  puVar4 = local_5f;
  for (lVar3 = 0x13; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  local_48 = DAT_1800264e3;
  puVar4 = local_47;
  for (lVar3 = 0x13; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  local_30 = DAT_1800264e3;
  puVar4 = local_2f;
  for (lVar3 = 0x13; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  local_e0[0] = DAT_1800264e3;
  pcVar6 = local_e0;
  for (lVar3 = 0x13; pcVar6 = pcVar6 + 1, lVar3 != 0; lVar3 = lVar3 + -1) {
    *pcVar6 = '\0';
  }
  local_110 = DAT_1800264e3;
  puVar4 = local_10f;
  for (lVar3 = 0x13; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  local_178[0] = DAT_1800264e3;
  pcVar6 = local_178;
  for (lVar3 = 0x13; pcVar6 = pcVar6 + 1, lVar3 != 0; lVar3 = lVar3 + -1) {
    *pcVar6 = '\0';
  }
  local_240 = 0;
  local_248 = 0;
  local_244 = 0;
  *param_4 = *param_4 + 1;
  local_1d0 = strlen(param_2);
  local_220 = param_2;
  while ((ulonglong)(longlong)local_234 < local_1d0) {
    for (; *local_220 != ' '; local_220 = local_220 + 1) {
      local_b0[local_240] = *local_220;
      local_240 = local_240 + 1;
      local_234 = local_234 + 1;
    }
    local_200 = (ulonglong)local_240;
    if (0x31 < local_200) {
      FUN_1800240b8();
    }
    local_b0[local_200] = '\0';
    local_234 = local_234 + 1;
    local_220 = local_220 + 1;
    if (local_b0[0] != '\0') {
      strcpy(&local_110,"");
      strcpy(local_178,"");
      FUN_180008840(local_b0,(longlong)&local_110,local_178);
      strcpy(local_b0,"");
      local_240 = 0;
      iVar1 = strcmp(&local_110,"TEMPERATURE");
      if (iVar1 == 0) {
        local_224 = 1;
        strcpy(&local_f8,local_178);
      }
      else {
        iVar1 = strcmp(&local_110,"PRESSURE");
        if (iVar1 == 0) {
          local_22c = 1;
          local_244 = 0;
          local_248 = 0;
          while (sVar2 = strlen(local_178), local_248 < (int)sVar2) {
            if (local_178[local_248] != '\'') {
              local_128[local_244] = local_178[local_248];
              local_244 = local_244 + 1;
            }
            local_248 = local_248 + 1;
          }
          local_1f8 = (ulonglong)local_244;
          if (0x13 < local_1f8) {
            FUN_1800240b8();
          }
          local_128[local_1f8] = '\0';
        }
        else {
          iVar1 = strcmp(&local_110,"SYSTEM-DEF");
          if (iVar1 == 0) {
            strcpy(local_e0,local_178);
          }
          else {
            iVar1 = strcmp(&local_110,"PROP-LIST");
            if (iVar1 == 0) {
              iVar1 = strcmp(local_178,"EQB");
              if (iVar1 == 0) {
                local_228 = 0;
                strcpy(&local_c8,"");
              }
              else {
                local_228 = 1;
                strcpy(&local_c8,local_178);
              }
            }
            else {
              iVar1 = strcmp(&local_110,"EQB");
              if ((iVar1 == 0) && (iVar1 = strcmp(local_178,"\'EQB\'"), iVar1 == 0)) {
                strcpy(local_160,"");
              }
              else {
                local_244 = 0;
                local_248 = 0;
                while (sVar2 = strlen(local_178), local_248 < (int)sVar2) {
                  if (local_178[local_248] != '\'') {
                    local_160[local_244] = local_178[local_248];
                    local_244 = local_244 + 1;
                  }
                  local_248 = local_248 + 1;
                }
                local_1f0 = (ulonglong)local_244;
                if (0x13 < local_1f0) {
                  FUN_1800240b8();
                }
                local_160[local_1f0] = '\0';
              }
            }
          }
        }
      }
    }
  }
  pcVar6 = (char *)0x2;
  uVar5 = 10;
  local_218 = FUN_180021730(param_1,local_1c8,10,2);
  local_1d8 = local_218 + -4;
  local_210 = strlen(local_e0);
  if (((local_228 != 0) && (local_210 == 1)) && (local_22c != 0)) {
    strcpy(local_160,local_128);
    local_22c = 0;
  }
  local_230 = 3;
  do {
    if (local_218 + -1 <= local_230) {
      return 1;
    }
    strcpy(local_148,(char *)local_1c8[local_230]);
    iVar1 = strcmp(local_148,"*");
    if (iVar1 != 0) {
      local_238 = local_230 + -3;
      local_244 = 0;
      strcpy(local_b0,"");
      if (param_3 == 0) {
        local_23c = 0;
        local_240 = 0;
LAB_180007805:
        sVar2 = strlen(local_148);
        if (local_240 < (int)sVar2) {
          if (local_148[local_240] != '-') break;
          local_23c = 1;
          local_248 = 0;
          while (sVar2 = strlen(local_148), local_248 < (int)sVar2) {
            if (local_148[local_248] != '-') {
              local_b0[local_244] = local_148[local_248];
              local_244 = local_244 + 1;
            }
            local_248 = local_248 + 1;
          }
          local_208 = (ulonglong)local_244;
          if (0x31 < local_208) {
            FUN_1800240b8();
          }
          local_b0[local_208] = '\0';
          strcpy(local_148,local_b0);
        }
        if ((local_e0[local_238] == 'T') && (local_224 != 0)) {
          if (local_23c == 0) {
            local_260 = local_148;
            local_268 = &local_f8;
            pcVar6 = &local_f8;
            uVar5 = (ulonglong)*param_4;
            FUN_180007f00(param_5,
                          "%d PROPLIST = \"TEMPERATURE_%s\" PROPLABEL = \"%s\" VALUE = %s <0> <0>",
                          uVar5,pcVar6);
          }
          if (local_23c == 1) {
            local_260 = local_148;
            local_268 = &local_f8;
            pcVar6 = &local_f8;
            uVar5 = (ulonglong)*param_4;
            FUN_180007f00(param_5,
                          "%d PROPLIST = \"TEMPERATURE_%s\" PROPLABEL = \"%s\" VALUE = \"%s%%\" <0> <0>"
                          ,uVar5,pcVar6);
          }
        }
        if ((local_e0[local_238] == 'P') && (local_22c != 0)) {
          if (local_23c == 0) {
            local_260 = local_148;
            local_268 = local_128;
            pcVar6 = local_128;
            uVar5 = (ulonglong)*param_4;
            FUN_180007f00(param_5,
                          "%d PROPLIST = \"PRESSURE_%s\" PROPLABEL = \"%s\" VALUE = %s <0> <0>",
                          uVar5,pcVar6);
          }
          if (local_23c == 1) {
            local_260 = local_148;
            local_268 = local_128;
            pcVar6 = local_128;
            uVar5 = (ulonglong)*param_4;
            FUN_180007f00(param_5,
                          "%d PROPLIST = \"PRESSURE_%s\" PROPLABEL = \"%s\" VALUE = \"%s%%\" <0> <0>"
                          ,uVar5,pcVar6);
          }
        }
        if (local_228 == 0) {
          FUN_180007f00(param_5,&DAT_180027250,uVar5,pcVar6);
        }
        else {
          if (local_210 < (ulonglong)(longlong)(local_238 + 1)) {
            if (local_23c == 0) {
              local_258 = local_148;
              local_260 = local_160;
              local_268 = local_160;
              pcVar6 = &local_c8;
              uVar5 = (ulonglong)*param_4;
              FUN_180007f00(param_5,"%d PROPLIST = \"%s_%s\" PROPLABEL = \"%s\" VALUE = %s <0> <0>",
                            uVar5,pcVar6);
            }
            if (local_23c == 1) {
              local_258 = local_148;
              local_260 = local_160;
              local_268 = local_160;
              pcVar6 = &local_c8;
              uVar5 = (ulonglong)*param_4;
              FUN_180007f00(param_5,
                            "%d PROPLIST = \"%s_%s\" PROPLABEL = \"%s\" VALUE = \"%s%%\" <0> <0>",
                            uVar5,pcVar6);
            }
          }
          FUN_180007f00(param_5,&DAT_180027250,uVar5,pcVar6);
        }
      }
      if (param_3 == 1) {
        if ((local_e0[local_238] == 'T') && (local_224 != 0)) {
          local_260 = local_148;
          local_268 = &local_f8;
          pcVar6 = &local_f8;
          uVar5 = (ulonglong)*param_4;
          FUN_180007f00(param_5,
                        "%d PROPLIST = \"TEMPERATURE_%s\" PROPLABEL = \"%s\" VALUE = %s <0> <0>",
                        uVar5,pcVar6);
        }
        if ((local_e0[local_238] == 'P') && (local_22c != 0)) {
          local_260 = local_148;
          local_268 = local_128;
          pcVar6 = local_128;
          uVar5 = (ulonglong)*param_4;
          FUN_180007f00(param_5,
                        "%d PROPLIST = \"PRESSURE_%s\" PROPLABEL = \"%s\" VALUE = %s <0> <0>",uVar5,
                        pcVar6);
        }
        if (local_228 == 0) {
          FUN_180007f00(param_5,&DAT_180027250,uVar5,pcVar6);
        }
        else {
          if (local_210 < (ulonglong)(longlong)(local_238 + 1)) {
            local_258 = local_148;
            local_260 = local_160;
            local_268 = local_160;
            pcVar6 = &local_c8;
            uVar5 = (ulonglong)*param_4;
            FUN_180007f00(param_5,"%d PROPLIST = \"%s_%s\" PROPLABEL = \"%s\" VALUE = %s <0> <0>",
                          uVar5,pcVar6);
          }
          FUN_180007f00(param_5,&DAT_180027250,uVar5,pcVar6);
        }
      }
    }
    local_230 = local_230 + 1;
  } while( true );
  local_240 = local_240 + 1;
  goto LAB_180007805;
}

/* RVA 0x7cb0, FUN_180007cb0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_180007cb0(char *param_1)

{
  size_t sVar1;
  longlong lVar2;
  char *pcVar3;
  undefined1 auStack_78 [32];
  uint local_58;
  uint local_54;
  int local_50;
  undefined4 local_4c;
  ulonglong local_48;
  ulonglong local_40;
  ulonglong local_38;
  char local_30 [32];
  ulonglong local_10;
  
  local_10 = DAT_180032178 ^ (ulonglong)auStack_78;
  local_58 = 0;
  local_50 = 0;
  local_4c = 0;
  local_30[0] = DAT_1800264e3;
  pcVar3 = local_30;
  for (lVar2 = 0x1d; pcVar3 = pcVar3 + 1, lVar2 != 0; lVar2 = lVar2 + -1) {
    *pcVar3 = '\0';
  }
  local_54 = 0;
  while( true ) {
    local_40 = (ulonglong)local_54;
    sVar1 = strlen(param_1);
    if (sVar1 <= local_40) {
      return local_4c;
    }
    if (param_1[local_54] == '-') break;
    local_54 = local_54 + 1;
  }
  local_4c = 1;
  local_58 = 0;
  while( true ) {
    local_38 = (ulonglong)local_58;
    sVar1 = strlen(param_1);
    if (sVar1 <= local_38) break;
    if (param_1[local_58] != '-') {
      local_30[local_50] = param_1[local_58];
      local_50 = local_50 + 1;
    }
    local_58 = local_58 + 1;
  }
  local_48 = (ulonglong)local_50;
  if (0x1d < local_48) {
    FUN_1800240b8();
  }
  local_30[local_48] = '\0';
  strcpy(param_1,local_30);
  return local_4c;
}

/* RVA 0x7e30, FUN_180007e30 */
void FUN_180007e30(int param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  if (param_1 == 0) {
    FUN_180007f00(param_2,&DAT_180027250,param_3,param_4);
  }
  else {
    FUN_180007f00(param_2,&DAT_180027248,param_3,param_4);
  }
  return;
}

/* RVA 0x7e70, FUN_180007e70 */
void FUN_180007e70(int param_1,char *param_2,longlong *param_3)

{
  size_t sVar1;
  char *local_10;
  
  local_10 = FUN_180023a80(param_2,"\n");
  if (local_10 == (char *)0x0) {
    local_10 = param_2;
  }
  else {
    local_10 = local_10 + 1;
  }
  sVar1 = strlen(local_10);
  if (0x4e < (int)sVar1 + param_1) {
    sVar1 = strlen((char *)*param_3);
    *param_3 = (longlong)(int)sVar1 + *param_3;
  }
  return;
}

/* RVA 0x7f00, FUN_180007f00 */
undefined4
FUN_180007f00(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined4 uVar1;
  undefined8 *puVar2;
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res18 = param_3;
  local_res20 = param_4;
  puVar2 = (undefined8 *)FUN_180001770();
  uVar1 = __stdio_common_vfprintf(*puVar2,param_1,param_2,0,&local_res18);
  return uVar1;
}

/* RVA 0x7f80, FUN_180007f80 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined * FUN_180007f80(char *param_1,int param_2)

{
  int iVar1;
  size_t sVar2;
  char *pcVar3;
  undefined *puVar4;
  undefined1 auStack_1f8 [32];
  int local_1d8;
  uint local_1d4;
  int local_1d0;
  ulonglong local_1c8;
  char local_1b8 [208];
  char local_e8 [208];
  ulonglong local_18;
  
  local_18 = DAT_180032178 ^ (ulonglong)auStack_1f8;
  local_1d0 = 0;
  local_1d4 = 0;
  FUN_180001000(param_1,local_1b8);
  local_1d4 = 0;
  while( true ) {
    local_1c8 = (ulonglong)local_1d4;
    sVar2 = strlen(local_1b8);
    if (sVar2 <= local_1c8) break;
    if (('`' < local_1b8[local_1d4]) && (local_1b8[local_1d4] < '{')) {
      local_1b8[local_1d4] = local_1b8[local_1d4] + -0x20;
    }
    local_1d4 = local_1d4 + 1;
  }
  local_1d8 = 0;
  while ((*(int *)(&DAT_180030a10 + (longlong)local_1d8 * 0x158) != -1 &&
         (*(int *)(&DAT_180030a10 + (longlong)local_1d8 * 0x158) != param_2))) {
    local_1d8 = local_1d8 + 1;
  }
  while (((&PTR_s_KMOL_CUM_180030a20)[(longlong)local_1d8 * 0x2b + (longlong)local_1d0] !=
          (undefined *)0x0 &&
         (iVar1 = strcmp((&PTR_s_KMOL_CUM_180030a20)
                         [(longlong)local_1d8 * 0x2b + (longlong)local_1d0],local_1b8), iVar1 != 0))
        ) {
    local_1d0 = local_1d0 + 1;
  }
  if ((&PTR_s_KMOL_CUM_180030a20)[(longlong)local_1d8 * 0x2b + (longlong)local_1d0] ==
      (undefined *)0x0) {
    puVar4 = (undefined *)0x0;
  }
  else {
    pcVar3 = strchr((&PTR_s_KMOL_CUM_180030a20)[(longlong)local_1d8 * 0x2b + (longlong)local_1d0],
                    0x2f);
    if (pcVar3 == (char *)0x0) {
      FUN_180002d90(local_e8,"%s=%s",(&PTR_s_MOLE_DENSITY_180030a18)[(longlong)local_1d8 * 0x2b],
                    (&PTR_s_KMOL_CUM_180030a20)[(longlong)local_1d8 * 0x2b + (longlong)local_1d0]);
    }
    else {
      FUN_180002d90(local_e8,"%s=\'%s\'",(&PTR_s_MOLE_DENSITY_180030a18)[(longlong)local_1d8 * 0x2b]
                    ,(&PTR_s_KMOL_CUM_180030a20)[(longlong)local_1d8 * 0x2b + (longlong)local_1d0]);
    }
    for (local_1d8 = 0; local_1d8 < DAT_180034160; local_1d8 = local_1d8 + 1) {
      iVar1 = strcmp(local_e8,&DAT_1800331c0 + (longlong)local_1d8 * 200);
      if (iVar1 == 0) {
        return &DAT_1800331c0 + (longlong)local_1d8 * 200;
      }
    }
    if (DAT_18003221c == 0x14) {
      DAT_18003221c = 0;
    }
    strcpy(&DAT_1800331c0 + (longlong)DAT_18003221c * 200,local_e8);
    if (DAT_180034160 < 199) {
      DAT_180034160 = DAT_180034160 + 1;
    }
    puVar4 = &DAT_1800331c0 + (longlong)DAT_18003221c * 200;
    DAT_18003221c = DAT_18003221c + 1;
  }
  return puVar4;
}

/* RVA 0x82f0, FUN_1800082f0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined * FUN_1800082f0(char *param_1,int param_2,double *param_3)

{
  int iVar1;
  size_t sVar2;
  char *pcVar3;
  undefined *puVar4;
  undefined1 auStack_1f8 [32];
  int local_1d8;
  uint local_1d4;
  int local_1d0;
  ulonglong local_1c8;
  char local_1b8 [208];
  char local_e8 [208];
  ulonglong local_18;
  
  local_18 = DAT_180032178 ^ (ulonglong)auStack_1f8;
  local_1d0 = 0;
  local_1d4 = 0;
  FUN_180001a20(param_1,local_1b8,param_3);
  local_1d4 = 0;
  while( true ) {
    local_1c8 = (ulonglong)local_1d4;
    sVar2 = strlen(local_1b8);
    if (sVar2 <= local_1c8) break;
    if (('`' < local_1b8[local_1d4]) && (local_1b8[local_1d4] < '{')) {
      local_1b8[local_1d4] = local_1b8[local_1d4] + -0x20;
    }
    local_1d4 = local_1d4 + 1;
  }
  local_1d8 = 0;
  while ((*(int *)(&DAT_18002f1a0 + (longlong)local_1d8 * 0xb8) != -1 &&
         (*(int *)(&DAT_18002f1a0 + (longlong)local_1d8 * 0xb8) != param_2))) {
    local_1d8 = local_1d8 + 1;
  }
  while (((&PTR_DAT_18002f1b0)[(longlong)local_1d8 * 0x17 + (longlong)local_1d0] != (undefined *)0x0
         && (iVar1 = strcmp((&PTR_DAT_18002f1b0)[(longlong)local_1d8 * 0x17 + (longlong)local_1d0],
                            local_1b8), iVar1 != 0))) {
    local_1d0 = local_1d0 + 1;
  }
  if ((&PTR_DAT_18002f1b0)[(longlong)local_1d8 * 0x17 + (longlong)local_1d0] == (undefined *)0x0) {
    puVar4 = (undefined *)0x0;
  }
  else {
    pcVar3 = strchr((&PTR_DAT_18002f1b0)[(longlong)local_1d8 * 0x17 + (longlong)local_1d0],0x2f);
    if (pcVar3 == (char *)0x0) {
      FUN_180002d90(local_e8,"%s=%s",(&PTR_s_ANGLE_18002f1a8)[(longlong)local_1d8 * 0x17],
                    (&PTR_DAT_18002f1b0)[(longlong)local_1d8 * 0x17 + (longlong)local_1d0]);
    }
    else {
      FUN_180002d90(local_e8,"%s=\'%s\'",(&PTR_s_ANGLE_18002f1a8)[(longlong)local_1d8 * 0x17],
                    (&PTR_DAT_18002f1b0)[(longlong)local_1d8 * 0x17 + (longlong)local_1d0]);
    }
    for (local_1d8 = 0; local_1d8 < DAT_180032218; local_1d8 = local_1d8 + 1) {
      iVar1 = strcmp(local_e8,&DAT_180032220 + (longlong)local_1d8 * 200);
      if (iVar1 == 0) {
        return &DAT_180032220 + (longlong)local_1d8 * 200;
      }
    }
    if (DAT_180032214 == 0x14) {
      DAT_180032214 = 0;
    }
    strcpy(&DAT_180032220 + (longlong)DAT_180032214 * 200,local_e8);
    if (DAT_180032218 < 199) {
      DAT_180032218 = DAT_180032218 + 1;
    }
    puVar4 = &DAT_180032220 + (longlong)DAT_180032214 * 200;
    DAT_180032214 = DAT_180032214 + 1;
  }
  return puVar4;
}

/* RVA 0x8670, FUN_180008670 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_180008670(char *param_1,int param_2,double *param_3)

{
  int iVar1;
  undefined4 uVar2;
  size_t sVar3;
  undefined1 auStack_118 [32];
  int local_f8;
  int local_f4;
  int local_f0;
  char local_e8 [208];
  ulonglong local_18;
  
  local_18 = DAT_180032178 ^ (ulonglong)auStack_118;
  local_f0 = 0;
  local_f8 = 0;
  FUN_180001a20(param_1,local_e8,param_3);
  local_f8 = 0;
  while (sVar3 = strlen(local_e8), local_f8 < (int)sVar3) {
    if (('`' < local_e8[local_f8]) && (local_e8[local_f8] < '{')) {
      local_e8[local_f8] = local_e8[local_f8] + -0x20;
    }
    local_f8 = local_f8 + 1;
  }
  local_f4 = 0;
  while ((*(int *)(&DAT_18002f1a0 + (longlong)local_f4 * 0xb8) != -1 &&
         (*(int *)(&DAT_18002f1a0 + (longlong)local_f4 * 0xb8) != param_2))) {
    local_f4 = local_f4 + 1;
  }
  while (((&PTR_DAT_18002f1b0)[(longlong)local_f4 * 0x17 + (longlong)local_f0] != (undefined *)0x0
         && (iVar1 = strcmp((&PTR_DAT_18002f1b0)[(longlong)local_f4 * 0x17 + (longlong)local_f0],
                            local_e8), iVar1 != 0))) {
    local_f0 = local_f0 + 1;
  }
  if ((&PTR_DAT_18002f1b0)[(longlong)local_f4 * 0x17 + (longlong)local_f0] == (undefined *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = *(undefined4 *)(&DAT_18002f250 + (longlong)local_f4 * 0xb8);
  }
  return uVar2;
}

/* RVA 0x8840, FUN_180008840 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180008840(char *param_1,longlong param_2,char *param_3)

{
  char *pcVar1;
  undefined1 auStack_78 [32];
  int local_58;
  int local_54;
  int local_50;
  ulonglong local_48;
  size_t local_40;
  char local_38 [32];
  ulonglong local_18;
  
  local_18 = DAT_180032178 ^ (ulonglong)auStack_78;
  local_54 = 0;
  local_50 = 0;
  local_58 = 0;
  local_40 = strlen(param_1);
  for (local_54 = 0; (ulonglong)(longlong)local_54 < local_40; local_54 = local_54 + 1) {
    if (local_50 == 0) {
      if (param_1[local_54] == '=') {
        *(undefined1 *)(param_2 + local_58) = 0;
        local_50 = 1;
        local_58 = 0;
      }
      else {
        *(char *)(param_2 + local_58) = param_1[local_54];
        local_58 = local_58 + 1;
      }
    }
    else {
      param_3[local_58] = param_1[local_54];
      local_58 = local_58 + 1;
    }
  }
  param_3[local_58] = '\0';
  pcVar1 = strchr(param_3,0x2f);
  if (((pcVar1 != (char *)0x0) && (*param_3 == '\'')) && (param_3[local_58 + -1] == '\'')) {
    strncpy(local_38,param_3 + 1,(longlong)(local_58 + -2));
    local_48 = (ulonglong)(local_58 + -2);
    if (0x1f < local_48) {
      FUN_1800240b8();
    }
    local_38[local_48] = '\0';
    strcpy(param_3,local_38);
  }
  return 1;
}

/* RVA 0x8a30, FUN_180008a30 */
undefined8 FUN_180008a30(char *param_1,int param_2,undefined **param_3,double *param_4)

{
  undefined8 uVar1;
  double *pdVar2;
  uint local_28;
  undefined1 local_24 [12];
  int *local_18;
  int *local_10;
  
  local_28 = 0;
  local_24._0_4_ = 0;
  if ((param_2 == 0) && (local_24._4_8_ = fopen(param_1,"w"), (FILE *)local_24._4_8_ == (FILE *)0x0)
     ) {
    FUN_1800220b0(0,"Unable to open Export File",param_3,param_4);
    return 0xffffffff;
  }
  if ((param_2 == 1) && (local_24._4_8_ = fopen(param_1,"w"), (FILE *)local_24._4_8_ == (FILE *)0x0)
     ) {
    FUN_1800220b0(0,"Unable to open Export File",param_3,param_4);
    return 0xffffffff;
  }
  if (param_2 == 0) {
    local_18 = FUN_180021a60(5);
    local_10 = FUN_180021a60(7);
    if ((*local_18 < 1) && (*local_10 < 1)) {
      uVar1 = 0;
      FUN_18000d730(local_24._4_8_,0,param_3,param_4);
    }
    else {
      uVar1 = 1;
      FUN_18000d730(local_24._4_8_,1,param_3,param_4);
    }
    FUN_180009f90(local_24._4_8_,uVar1,(longlong)param_3,(longlong)param_4);
    FUN_18001dab0(local_24._4_8_,uVar1,(char *)param_3,(undefined *)param_4);
    FUN_18000d9e0(local_24._4_8_,&local_28,(double *)param_3,param_4);
    FUN_18000f580(local_24._4_8_,&local_28,(undefined *)param_3,param_4);
    FUN_180008d00(local_24._4_8_,&local_28,(char *)param_3,(longlong)param_4);
    FUN_18001b0b0(local_24._4_8_,&local_28,(double *)&PTR_DAT_18002e7c0,param_4);
    param_3 = &PTR_DAT_18002ecd0;
    FUN_180010320(local_24._4_8_,&local_28,(double *)&PTR_DAT_18002ecd0,param_4);
    if ((0 < *local_18) || (0 < *local_10)) {
      FUN_18000a2c0();
    }
  }
  if (param_2 == 1) {
    local_18 = FUN_180021a60(5);
    local_10 = FUN_180021a60(7);
    if ((*local_18 < 1) && (*local_10 < 1)) {
      uVar1 = 0;
      FUN_18000d990(local_24._4_8_);
    }
    else {
      uVar1 = 1;
      FUN_18000d990(local_24._4_8_);
    }
    FUN_18000a100(local_24._4_8_,uVar1,(longlong)param_3,(longlong)param_4);
    FUN_18001dbf0(local_24._4_8_,uVar1,(undefined *)param_3,param_4);
    pdVar2 = (double *)local_24;
    FUN_18000e920(local_24._4_8_,&local_28,pdVar2,param_4);
    FUN_18000a2d0(local_24._4_8_,&local_28,pdVar2,(char *)param_4);
    FUN_18000fc10(local_24._4_8_,&local_28,(undefined *)pdVar2,(longlong)param_4);
    FUN_180009420(local_24._4_8_,(int *)&local_28,(ulonglong)pdVar2,(double)param_4);
    FUN_18001c050(local_24._4_8_,&local_28,(double *)&PTR_DAT_18002e7c0,(double *)local_24);
    FUN_180013e80(local_24._4_8_,&local_28,(double *)&PTR_DAT_18002ecd0,(double *)local_24);
  }
  fclose((FILE *)local_24._4_8_);
  return 0;
}

/* RVA 0x8d00, FUN_180008d00 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_180008d00(undefined8 param_1,uint *param_2,char *param_3,longlong param_4)

{
  int iVar1;
  longlong lVar2;
  size_t sVar3;
  char **ppcVar4;
  undefined1 auStack_1f8 [32];
  int local_1d8;
  char *local_1d0;
  int local_1c8;
  char *local_1c0;
  int local_1b8;
  int local_1b4;
  longlong local_1b0;
  char *local_1a8;
  undefined8 *local_1a0;
  longlong local_198;
  longlong local_190;
  int *local_188;
  undefined **local_180;
  longlong local_178;
  double adStack_170 [4];
  double adStack_150 [4];
  char local_130 [24];
  char local_118 [256];
  ulonglong local_18;
  
  local_18 = DAT_180032178 ^ (ulonglong)auStack_1f8;
  strcpy(local_130,"");
  local_188 = FUN_180021a60(8);
  local_1a0 = *(undefined8 **)(local_188 + 2);
  do {
    if (local_1a0 == (undefined8 *)0x0) {
      FUN_180007f00(param_1,&DAT_180027258,param_3,param_4);
      return;
    }
    local_1a8 = (char *)*local_1a0;
    local_1c8 = 0;
    while ((&PTR_s_UNIQUAC_18002e590)[(longlong)local_1c8 * 7] != (undefined *)0x0) {
      local_180 = &PTR_s_UNIQUAC_18002e590;
      iVar1 = _stricmp((&PTR_s_UNIQUAC_18002e590)[(longlong)local_1c8 * 7],local_1a8);
      if (iVar1 == 0) break;
      local_1c8 = local_1c8 + 1;
    }
    local_1b8 = 0;
    local_1b0 = *(longlong *)(local_1a8 + 0x20);
    for (; local_1b8 < *(short *)(local_1a8 + 0x28); local_1b8 = local_1b8 + 1) {
      if ((*(longlong *)(local_1b0 + 0x10) != 0) || (*(longlong *)(local_1b0 + 0x18) != 0)) {
        for (local_1d8 = 0; local_1d8 < 4; local_1d8 = local_1d8 + 1) {
          adStack_150[local_1d8] = 0.0;
          adStack_170[local_1d8] = 0.0;
        }
        local_198 = *(longlong *)(local_1b0 + 0x10);
        local_190 = *(longlong *)(local_1b0 + 0x18);
        local_1d8 = 0;
        while ((local_1d8 < 4 &&
               ((&PTR_DAT_18002e5a0)[(longlong)local_1c8 * 7 + (longlong)local_1d8] !=
                (undefined *)0x0))) {
          local_1c0 = *(char **)(local_1a8 + 0x20);
          for (local_1b4 = 0; local_1b4 < *(short *)(local_1a8 + 0x28); local_1b4 = local_1b4 + 1) {
            if ((*(longlong *)(local_1c0 + 0x10) == local_198) &&
               (*(longlong *)(local_1c0 + 0x18) == local_190)) {
              local_178 = (longlong)local_1d8;
              iVar1 = _stricmp((&PTR_DAT_18002e5a0)[(longlong)local_1c8 * 7 + local_178],local_1c0);
              if (iVar1 == 0) {
                adStack_170[local_1d8] = *(double *)(local_1c0 + 0x20);
                adStack_150[local_1d8] = *(double *)(local_1c0 + 0x28);
                local_1c0[0x10] = '\0';
                local_1c0[0x11] = '\0';
                local_1c0[0x12] = '\0';
                local_1c0[0x13] = '\0';
                local_1c0[0x14] = '\0';
                local_1c0[0x15] = '\0';
                local_1c0[0x16] = '\0';
                local_1c0[0x17] = '\0';
                local_1c0[0x18] = '\0';
                local_1c0[0x19] = '\0';
                local_1c0[0x1a] = '\0';
                local_1c0[0x1b] = '\0';
                local_1c0[0x1c] = '\0';
                local_1c0[0x1d] = '\0';
                local_1c0[0x1e] = '\0';
                local_1c0[0x1f] = '\0';
                break;
              }
            }
            local_1c0 = local_1c0 + 0x30;
          }
          local_1d8 = local_1d8 + 1;
        }
        for (local_1d8 = 0;
            ((local_1d8 < 4 && (adStack_170[local_1d8] == _DAT_180029470)) &&
            (adStack_150[local_1d8] == _DAT_180029470)); local_1d8 = local_1d8 + 1) {
        }
        if (local_1d8 != 4) {
          iVar1 = strcmp(local_130,(&PTR_DAT_18002e598)[(longlong)local_1c8 * 7]);
          if (iVar1 != 0) {
            FUN_180007f00(param_1,&DAT_180027258,param_3,param_4);
            *param_2 = *param_2 + 1;
            FUN_180007f00(param_1,"PROP-DATA BP-%d\n\n",(ulonglong)*param_2,param_4);
            FUN_180007f00(param_1,"   PROP-LIST %s\n\n",
                          (&PTR_DAT_18002e598)[(longlong)local_1c8 * 7],param_4);
            strcpy(local_130,(&PTR_DAT_18002e598)[(longlong)local_1c8 * 7]);
          }
          local_1d0 = local_118;
          lVar2 = local_190 + 0x240;
          FUN_180002d90(local_1d0,"   BPVAL %s %s",local_198 + 0x240,lVar2);
          sVar3 = strlen(local_1d0);
          local_1d0 = local_1d0 + (int)sVar3;
          for (local_1d8 = 0;
              (local_1d8 < 4 && (local_1d8 < *(int *)(&DAT_18002e5c0 + (longlong)local_1c8 * 0x38)))
              ; local_1d8 = local_1d8 + 1) {
            FUN_180007e70(0xb,local_118,(longlong *)&local_1d0);
            FUN_180002d90(local_1d0," %-8G",adStack_170[local_1d8],lVar2);
            sVar3 = strlen(local_1d0);
            local_1d0 = local_1d0 + (int)sVar3;
          }
          for (local_1d8 = 4; local_1d8 < *(int *)(&DAT_18002e5c0 + (longlong)local_1c8 * 0x38);
              local_1d8 = local_1d8 + 1) {
            ppcVar4 = &local_1d0;
            FUN_180007e70(2,local_118,(longlong *)ppcVar4);
            FUN_180002d90(local_1d0,&DAT_1800285a0,ppcVar4,lVar2);
            sVar3 = strlen(local_1d0);
            local_1d0 = local_1d0 + (int)sVar3;
          }
          FUN_180007f00(param_1,&DAT_1800272c0,local_118,lVar2);
          local_1d0 = local_118;
          param_4 = local_198 + 0x240;
          FUN_180002d90(local_1d0,"   BPVAL %s %s",local_190 + 0x240,param_4);
          sVar3 = strlen(local_1d0);
          local_1d0 = local_1d0 + (int)sVar3;
          for (local_1d8 = 0;
              (local_1d8 < 4 && (local_1d8 < *(int *)(&DAT_18002e5c0 + (longlong)local_1c8 * 0x38)))
              ; local_1d8 = local_1d8 + 1) {
            FUN_180007e70(0xb,local_118,(longlong *)&local_1d0);
            FUN_180002d90(local_1d0," %-8G",adStack_150[local_1d8],param_4);
            sVar3 = strlen(local_1d0);
            local_1d0 = local_1d0 + (int)sVar3;
          }
          for (local_1d8 = 4; local_1d8 < *(int *)(&DAT_18002e5c0 + (longlong)local_1c8 * 0x38);
              local_1d8 = local_1d8 + 1) {
            ppcVar4 = &local_1d0;
            FUN_180007e70(2,local_118,(longlong *)ppcVar4);
            FUN_180002d90(local_1d0,&DAT_1800285a0,ppcVar4,param_4);
            sVar3 = strlen(local_1d0);
            local_1d0 = local_1d0 + (int)sVar3;
          }
          param_3 = local_118;
          FUN_180007f00(param_1,&DAT_1800272c0,param_3,param_4);
        }
      }
      local_1b0 = local_1b0 + 0x30;
    }
    local_1a0 = (undefined8 *)local_1a0[1];
  } while( true );
}

/* RVA 0x9420, FUN_180009420 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_180009420(undefined8 param_1,int *param_2,ulonglong param_3,double param_4)

{
  int iVar1;
  longlong lVar2;
  undefined1 *puVar3;
  undefined *puVar4;
  undefined1 auStack_148 [32];
  int local_128;
  uint local_124;
  int local_120;
  int local_11c;
  int local_118;
  float local_114;
  longlong local_110;
  int local_108;
  char *local_100;
  char *local_f8;
  int local_f0;
  uint local_ec;
  uint local_e8;
  longlong *local_e0;
  longlong local_d8;
  longlong local_d0;
  char *local_c8;
  int *local_c0;
  undefined **local_b8;
  longlong local_b0;
  double adStack_a8 [4];
  double adStack_88 [4];
  char local_68;
  undefined1 local_67 [31];
  char local_48;
  undefined1 local_47 [31];
  char local_28 [24];
  ulonglong local_10;
  
  local_10 = DAT_180032178 ^ (ulonglong)auStack_148;
  local_ec = 0;
  local_e8 = 0;
  local_108 = 0;
  local_48 = DAT_1800264e3;
  puVar3 = local_47;
  for (lVar2 = 0x1d; lVar2 != 0; lVar2 = lVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  local_68 = DAT_1800264e3;
  puVar3 = local_67;
  for (lVar2 = 0x1d; lVar2 != 0; lVar2 = lVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  local_118 = 0;
  local_124 = 1;
  local_114 = 0.0;
  strcpy(local_28,"");
  local_c0 = FUN_180021a60(8);
  local_e0 = *(longlong **)(local_c0 + 2);
  do {
    if (local_e0 == (longlong *)0x0) {
      FUN_180007f00(param_1,&DAT_180027258,param_3,param_4);
      return;
    }
    local_f8 = (char *)*local_e0;
    local_c8 = (char *)0x0;
    if ((local_e0 != (longlong *)0x0) && (local_e0[1] != 0)) {
      local_c8 = *(char **)local_e0[1];
    }
    local_108 = 0;
    strcpy(&local_48,"");
    strcpy(&local_68,"");
    local_118 = 0;
    local_11c = 0;
    local_110 = *(longlong *)(local_f8 + 0x20);
    for (; local_11c < *(short *)(local_f8 + 0x28); local_11c = local_11c + 1) {
      if ((*(longlong *)(local_110 + 0x10) != 0) || (*(longlong *)(local_110 + 0x18) != 0)) {
        local_d0 = *(longlong *)(local_110 + 0x10);
        local_d8 = *(longlong *)(local_110 + 0x18);
        param_4 = (double)(local_d8 + 0x240);
        param_3 = local_d0 + 0x240;
        FUN_180002d90(&local_68,"%s %s",param_3,param_4);
        iVar1 = strcmp(&local_68,&local_48);
        if (iVar1 != 0) {
          local_108 = local_108 + 1;
        }
        strcpy(&local_48,&local_68);
      }
      local_110 = local_110 + 0x30;
    }
    local_120 = 0;
    while ((&PTR_s_UNIQUAC_18002e590)[(longlong)local_120 * 7] != (undefined *)0x0) {
      local_b8 = &PTR_s_UNIQUAC_18002e590;
      iVar1 = _stricmp((&PTR_s_UNIQUAC_18002e590)[(longlong)local_120 * 7],local_f8);
      if (iVar1 == 0) break;
      local_120 = local_120 + 1;
    }
    local_11c = 0;
    local_110 = *(longlong *)(local_f8 + 0x20);
    for (; local_11c < *(short *)(local_f8 + 0x28); local_11c = local_11c + 1) {
      if ((*(longlong *)(local_110 + 0x10) != 0) || (*(longlong *)(local_110 + 0x18) != 0)) {
        for (local_128 = 0; local_128 < 4; local_128 = local_128 + 1) {
          adStack_a8[local_128] = 0.0;
          adStack_88[local_128] = 0.0;
        }
        local_d0 = *(longlong *)(local_110 + 0x10);
        local_d8 = *(longlong *)(local_110 + 0x18);
        param_4 = (double)(local_d8 + 0x240);
        param_3 = local_d0 + 0x240;
        FUN_180002d90(&local_48,"%s %s",param_3,param_4);
        local_128 = 0;
        while ((local_128 < 4 &&
               ((&PTR_DAT_18002e5a0)[(longlong)local_120 * 7 + (longlong)local_128] !=
                (undefined *)0x0))) {
          local_100 = *(char **)(local_f8 + 0x20);
          for (local_f0 = 0; local_f0 < *(short *)(local_f8 + 0x28); local_f0 = local_f0 + 1) {
            if ((*(longlong *)(local_100 + 0x10) == local_d0) &&
               (*(longlong *)(local_100 + 0x18) == local_d8)) {
              local_b0 = (longlong)local_128;
              iVar1 = _stricmp((&PTR_DAT_18002e5a0)[(longlong)local_120 * 7 + local_b0],local_100);
              if (iVar1 == 0) {
                adStack_88[local_128] = *(double *)(local_100 + 0x20);
                adStack_a8[local_128] = *(double *)(local_100 + 0x28);
                local_100[0x10] = '\0';
                local_100[0x11] = '\0';
                local_100[0x12] = '\0';
                local_100[0x13] = '\0';
                local_100[0x14] = '\0';
                local_100[0x15] = '\0';
                local_100[0x16] = '\0';
                local_100[0x17] = '\0';
                local_100[0x18] = '\0';
                local_100[0x19] = '\0';
                local_100[0x1a] = '\0';
                local_100[0x1b] = '\0';
                local_100[0x1c] = '\0';
                local_100[0x1d] = '\0';
                local_100[0x1e] = '\0';
                local_100[0x1f] = '\0';
                break;
              }
            }
            local_100 = local_100 + 0x30;
          }
          local_128 = local_128 + 1;
        }
        for (local_128 = 0;
            ((local_128 < 4 && (adStack_88[local_128] == _DAT_180029470)) &&
            (adStack_a8[local_128] == _DAT_180029470)); local_128 = local_128 + 1) {
        }
        if (local_128 != 4) {
          iVar1 = strcmp(local_28,(&PTR_DAT_18002e598)[(longlong)local_120 * 7]);
          if (iVar1 != 0) {
            *param_2 = *param_2 + 1;
            iVar1 = strcmp((&PTR_DAT_18002e598)[(longlong)local_120 * 7],"NRTL");
            if (iVar1 == 0) {
              local_ec = local_ec + 1;
              param_4 = (double)(ulonglong)local_ec;
              puVar4 = (&PTR_DAT_18002e598)[(longlong)local_120 * 7];
              FUN_180007f00(param_1,"? PROPERTIES PARAMETERS BINARY \"T-DEPENDENT\" \"%s-%d\" ?",
                            puVar4,param_4);
              FUN_180007f00(param_1," ; \"SI_MOLE\" ; \n",puVar4,param_4);
              puVar4 = (&PTR_DAT_18002e598)[(longlong)local_120 * 7];
              FUN_180007f00(param_1,"\\ PROP-LIST PARAMNAME = %s SETNO = 1 \\ \n",puVar4,param_4);
              FUN_180007f00(param_1,"\\ BPVAL \n",puVar4,param_4);
            }
            iVar1 = strcmp((&PTR_DAT_18002e598)[(longlong)local_120 * 7],"UNIQ");
            if (iVar1 == 0) {
              local_e8 = local_e8 + 1;
              param_4 = (double)(ulonglong)local_e8;
              puVar4 = (&PTR_DAT_18002e598)[(longlong)local_120 * 7];
              FUN_180007f00(param_1,"? PROPERTIES PARAMETERS BINARY \"T-DEPENDENT\" \"%s-%d\" ?",
                            puVar4,param_4);
              FUN_180007f00(param_1," ; \"SI_MOLE\" ; \n",puVar4,param_4);
              puVar4 = (&PTR_DAT_18002e598)[(longlong)local_120 * 7];
              FUN_180007f00(param_1,"\\ PROP-LIST PARAMNAME = %s SETNO = 1 \\ \n",puVar4,param_4);
              FUN_180007f00(param_1,"\\ BPVAL \n",puVar4,param_4);
            }
            strcpy(local_28,(&PTR_DAT_18002e598)[(longlong)local_120 * 7]);
          }
          FUN_180007f00(param_1,"PARAMNAME2 = %s ",(&PTR_DAT_18002e598)[(longlong)local_120 * 7],
                        param_4);
          param_4 = (double)(local_d8 + 0x240);
          param_3 = local_d0 + 0x240;
          FUN_180007f00(param_1,"CID1 = %s CID2 = %s \n",param_3,param_4);
          local_124 = 1;
          for (local_128 = 0;
              (local_128 < 4 && (local_128 < *(int *)(&DAT_18002e5c0 + (longlong)local_120 * 0x38)))
              ; local_128 = local_128 + 1) {
            if (local_128 == *(int *)(&DAT_18002e5c0 + (longlong)local_120 * 0x38) + -1) {
              FUN_180007f00(param_1," UVAL%d = %-8G <0> <0>",(ulonglong)local_124,
                            adStack_88[local_128]);
              local_124 = local_124 + 1;
              local_118 = local_118 + 1;
              if ((local_118 == local_108) &&
                 ((local_c8 == (char *)0x0 || (iVar1 = _stricmp(local_f8,local_c8), iVar1 != 0)))) {
                param_4 = adStack_a8[local_128];
                param_3 = (ulonglong)local_124;
                FUN_180007f00(param_1," UVAL%d = %-8G <0> <0> \\ \n",param_3,param_4);
              }
              else {
                param_4 = adStack_a8[local_128];
                param_3 = (ulonglong)local_124;
                FUN_180007f00(param_1," UVAL%d = %-8G <0> <0> / \n",param_3,param_4);
              }
            }
            else {
              FUN_180007f00(param_1," UVAL%d = %-8G <0> <0>",(ulonglong)local_124,
                            adStack_88[local_128]);
              local_124 = local_124 + 1;
              iVar1 = strcmp((&PTR_DAT_18002e598)[(longlong)local_120 * 7],"NRTL");
              if (((iVar1 == 0) &&
                  ((&PTR_DAT_18002e5a0)[(longlong)local_120 * 7 + (longlong)local_128] !=
                   (undefined *)0x0)) &&
                 (iVar1 = _stricmp((&PTR_DAT_18002e5a0)
                                   [(longlong)local_120 * 7 + (longlong)local_128],"ALPHA"),
                 iVar1 == 0)) {
                param_4 = (double)local_114;
                param_3 = (ulonglong)local_124;
                FUN_180007f00(param_1," UVAL%d = %-8G <0> <0>\n",param_3,param_4);
              }
              else {
                param_4 = adStack_a8[local_128];
                param_3 = (ulonglong)local_124;
                FUN_180007f00(param_1," UVAL%d = %-8G <0> <0>\n",param_3,param_4);
              }
            }
            local_124 = local_124 + 1;
          }
          for (local_128 = 4; local_128 < *(int *)(&DAT_18002e5c0 + (longlong)local_120 * 0x38);
              local_128 = local_128 + 1) {
            if (local_128 == *(int *)(&DAT_18002e5c0 + (longlong)local_120 * 0x38) + -1) {
              FUN_180007f00(param_1," UVAL%d = %-8G <0> <0>",(ulonglong)local_124,(double)local_114)
              ;
              local_124 = local_124 + 1;
              local_118 = local_118 + 1;
              if ((local_118 == local_108) &&
                 ((local_c8 == (char *)0x0 || (iVar1 = _stricmp(local_f8,local_c8), iVar1 != 0)))) {
                param_4 = (double)local_114;
                param_3 = (ulonglong)local_124;
                FUN_180007f00(param_1," UVAL%d = %-8G <0> <0> \\ \n",param_3,param_4);
              }
              else {
                param_4 = (double)local_114;
                param_3 = (ulonglong)local_124;
                FUN_180007f00(param_1," UVAL%d = %-8G <0> <0> / \n",param_3,param_4);
              }
            }
            else {
              FUN_180007f00(param_1," UVAL%d = %-8G <0> <0>",(ulonglong)local_124,(double)local_114)
              ;
              local_124 = local_124 + 1;
              param_4 = (double)local_114;
              param_3 = (ulonglong)local_124;
              FUN_180007f00(param_1," UVAL%d = %-8G <0> <0>\n",param_3,param_4);
            }
            local_124 = local_124 + 1;
          }
        }
      }
      local_110 = local_110 + 0x30;
    }
    local_e0 = (longlong *)local_e0[1];
  } while( true );
}

/* RVA 0x9f90, FUN_180009f90 */
void FUN_180009f90(undefined8 param_1,undefined8 param_2,longlong param_3,longlong param_4)

{
  longlong lVar1;
  int *piVar2;
  int local_38;
  int local_34;
  longlong *local_28;
  
  local_38 = 0;
  piVar2 = FUN_180021a60(2);
  for (local_28 = *(longlong **)(piVar2 + 2); local_28 != (longlong *)0x0;
      local_28 = (longlong *)local_28[1]) {
    if (*local_28 != -0x240) {
      local_38 = local_38 + 1;
    }
  }
  local_34 = 0;
  piVar2 = FUN_180021a60(2);
  FUN_180007f00(param_1,"COMPONENTS\n",param_3,param_4);
  for (local_28 = *(longlong **)(piVar2 + 2); local_28 != (longlong *)0x0;
      local_28 = (longlong *)local_28[1]) {
    lVar1 = *local_28;
    if (local_34 == local_38 + -1) {
      param_4 = lVar1 + 0x120;
      param_3 = lVar1 + 0x240;
      FUN_180007f00(param_1,"    %s %s \n",param_3,param_4);
    }
    else {
      param_4 = lVar1 + 0x120;
      param_3 = lVar1 + 0x240;
      FUN_180007f00(param_1,"    %s %s /\n",param_3,param_4);
    }
    local_34 = local_34 + 1;
  }
  FUN_180007f00(param_1,&DAT_180027468,param_3,param_4);
  return;
}

/* RVA 0xa100, FUN_18000a100 */
void FUN_18000a100(undefined8 param_1,undefined8 param_2,longlong param_3,longlong param_4)

{
  longlong lVar1;
  int *piVar2;
  int local_38;
  int local_34;
  longlong *local_28;
  
  local_38 = 0;
  piVar2 = FUN_180021a60(2);
  for (local_28 = *(longlong **)(piVar2 + 2); local_28 != (longlong *)0x0;
      local_28 = (longlong *)local_28[1]) {
    if (*local_28 != -0x240) {
      local_38 = local_38 + 1;
    }
  }
  if (0 < local_38) {
    FUN_180007f00(param_1,"? COMPONENTS MAIN ? \n",param_3,param_4);
    FUN_180007f00(param_1,"\\ COMPONENTS ",param_3,param_4);
  }
  local_34 = 0;
  piVar2 = FUN_180021a60(2);
  for (local_28 = *(longlong **)(piVar2 + 2); local_28 != (longlong *)0x0;
      local_28 = (longlong *)local_28[1]) {
    lVar1 = *local_28;
    _strupr((char *)(lVar1 + 0x240));
    if (local_34 == local_38 + -1) {
      param_4 = lVar1 + 0x120;
      param_3 = lVar1 + 0x240;
      FUN_180007f00(param_1,"CID = %s ANAME = %s CID = %s \\\n",param_3,param_4);
    }
    else {
      param_4 = lVar1 + 0x120;
      param_3 = lVar1 + 0x240;
      FUN_180007f00(param_1,"CID = %s ANAME = %s CID = %s /\n",param_3,param_4);
    }
    local_34 = local_34 + 1;
  }
  if (0 < local_38) {
    FUN_180007f00(param_1,"? PROPERTIES MAIN ? \n",param_3,param_4);
  }
  return;
}

/* RVA 0xa2c0, FUN_18000a2c0 */
void FUN_18000a2c0(void)

{
  return;
}

/* RVA 0xa2d0, FUN_18000a2d0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18000a2d0(undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  undefined1 auStack_248 [32];
  undefined *local_228;
  uint local_218;
  uint local_214;
  int local_210;
  int local_20c;
  char *local_208;
  char *local_200;
  char *local_1f8;
  undefined8 *local_1f0;
  int local_1e8;
  longlong local_1e0;
  uint local_1d8;
  int local_1d4;
  uint local_1d0;
  undefined *local_1c8;
  int local_1c0;
  int local_1bc;
  int local_1b8;
  longlong *local_1b0;
  undefined *local_1a8;
  char *local_1a0;
  int *local_198;
  undefined **local_190;
  char *local_188;
  longlong local_180;
  longlong local_178;
  longlong local_170;
  longlong local_168;
  longlong local_160;
  longlong local_158;
  longlong local_150;
  longlong local_148;
  longlong local_140;
  longlong local_138;
  char *local_130;
  undefined8 local_128;
  longlong alStack_118 [20];
  char local_78 [24];
  char local_60 [24];
  char local_48 [24];
  char local_30 [24];
  ulonglong local_18;
  
  local_18 = DAT_180032178 ^ (ulonglong)auStack_248;
  local_198 = FUN_180021a60(6);
  local_1b0 = *(longlong **)(local_198 + 2);
  do {
    if (local_1b0 == (longlong *)0x0) {
      FUN_1800037e0();
      return;
    }
    local_1f0 = (undefined8 *)*local_1b0;
    local_1e0 = local_1f0[1];
    local_128 = *local_1f0;
    local_1b8 = -1;
    local_1e8 = -1;
    local_1c8 = (undefined *)0x0;
    local_1a8 = (undefined *)0x0;
    local_1bc = 0;
    local_210 = 0;
    strcpy(local_60,"");
    strcpy(local_78,"");
    strcpy(local_48,"");
    strcpy(local_30,"");
    local_1d4 = 0;
    while ((&PTR_s_POLYNOM_18002cb70)[(longlong)local_1d4 * 3] != (undefined *)0x0) {
      local_190 = &PTR_s_POLYNOM_18002cb70;
      iVar1 = _stricmp((&PTR_s_POLYNOM_18002cb70)[(longlong)local_1d4 * 3],(char *)(local_1f0 + 2));
      if (iVar1 == 0) break;
      local_1d4 = local_1d4 + 1;
    }
    if ((&PTR_s_POLYNOM_18002cb78)[(longlong)local_1d4 * 3] == (undefined *)0x0) {
      FUN_1800220b0(0,"Sorry! Function <%s> is not supported by Aspen Plus yet!",
                    (&PTR_s_POLYNOM_18002cb70)[(longlong)local_1d4 * 3],param_4);
    }
    else {
      local_20c = 1;
      local_208 = (char *)local_1f0[7];
      local_200 = (char *)local_1f0[9];
      while (local_20c <= *(short *)((longlong)local_1f0 + 0x8a)) {
        local_218 = 0;
        while ((((&PTR_DAT_18002e640)[(longlong)(int)local_218 * 3] != (undefined *)0x0 &&
                (local_208 != (char *)0x0)) &&
               (iVar1 = _stricmp((&PTR_DAT_18002e640)[(longlong)(int)local_218 * 3],local_208),
               iVar1 != 0))) {
          local_218 = local_218 + 1;
        }
        if (((&PTR_DAT_18002e648)[(longlong)(int)local_218 * 3] != (undefined *)0x0) &&
           (*(&PTR_DAT_18002e648)[(longlong)(int)local_218 * 3] == 'T')) {
          local_1bc = local_1bc + 1;
          local_1a8 = FUN_180007f80(local_200,0x19);
          if (local_1a8 == (undefined *)0x0) {
            local_228 = (&PTR_s_POLYNOM_18002cb70)[(longlong)local_1d4 * 3];
            param_4 = local_208;
            FUN_1800220b0(0,
                          "Unit <%s> for property <%s> in FUNCTION %s is not supported by Aspen Plus - no Data written."
                          ,local_200,local_208);
            break;
          }
          local_1b8 = local_20c;
          strcpy(local_30,local_200);
        }
        local_188 = local_208;
        local_20c = local_20c + 1;
        if (local_208 != (char *)0x0) {
          local_208 = local_208 + 0xd;
        }
        local_200 = local_200 + 0x14;
      }
      if ((local_1bc < 1) || (-1 < local_1b8)) {
        local_1c0 = *(int *)(&DAT_18002cb80 + (longlong)local_1d4 * 0x18) + -1;
        switch(local_1c0) {
        case 0:
          local_20c = 1;
          local_208 = (char *)local_1f0[7];
          local_200 = (char *)local_1f0[9];
          local_1f8 = (char *)local_1f0[8];
          for (; local_20c <= *(short *)((longlong)local_1f0 + 0x8a); local_20c = local_20c + 1) {
            if ((local_208 != (char *)0x0) && (iVar1 = strcmp(local_208,"T"), iVar1 != 0)) {
              local_218 = 0;
              while ((&PTR_DAT_18002cd10)[(longlong)(int)local_218 * 0x10] != (undefined *)0x0) {
                iVar1 = _stricmp((&PTR_DAT_18002cd10)[(longlong)(int)local_218 * 0x10],local_208);
                if (iVar1 == 0) {
                  if ((&DAT_18002cd34)[(longlong)(int)local_218 * 0x80] == ' ') {
                    local_210 = local_210 + 1;
                    break;
                  }
                  iVar1 = strcmp((&PTR_DAT_18002cd10)[(longlong)(int)local_218 * 0x10],"VOL");
                  if ((iVar1 == 0) && (local_1f8 == (char *)0x0)) {
                    local_210 = local_210 + 1;
                    break;
                  }
                  if (((local_1f8 != (char *)0x0) && (local_1f8 != (char *)0x0)) &&
                     ((&DAT_18002cd34)[(longlong)(int)local_218 * 0x80] == *local_1f8)) {
                    local_210 = local_210 + 1;
                    break;
                  }
                }
                local_218 = local_218 + 1;
              }
              if (local_210 < 1) {
                FUN_1800220b0(0,
                              "Property <%s> in FUNCTION POLYNOM is not supported by Aspen Plus - no Data written."
                              ,local_208,param_4);
                break;
              }
              local_1c8 = FUN_180007f80(local_200,
                                        *(int *)(&DAT_18002cd20 + (longlong)(int)local_218 * 0x80));
              if (local_1c8 == (undefined *)0x0) {
                param_4 = local_208;
                FUN_1800220b0(0,
                              "Unit <%s> for property <%s> in FUNCTION POLYNOM is not supported by Aspen Plus - no Data written."
                              ,local_200,local_208);
                break;
              }
              if (*(int *)(&DAT_18002cd88 + (longlong)(int)local_218 * 0x80) == 0) {
                *(longlong *)(&DAT_18002cd38 + (longlong)(int)local_218 * 0x80) = local_1e0 + 0x240;
                *(undefined4 *)(&DAT_18002cd88 + (longlong)(int)local_218 * 0x80) = 1;
              }
              else {
                for (local_214 = 0; (int)local_214 < 10; local_214 = local_214 + 1) {
                  if (*(longlong *)
                       (&DAT_18002cd38 +
                       (longlong)(int)local_214 * 8 + (longlong)(int)local_218 * 0x80) == 0) {
                    *(longlong *)
                     (&DAT_18002cd38 +
                     (longlong)(int)local_214 * 8 + (longlong)(int)local_218 * 0x80) =
                         local_1e0 + 0x240;
                    *(uint *)(&DAT_18002cd88 + (longlong)(int)local_218 * 0x80) = local_214 + 1;
                    break;
                  }
                  local_180 = (longlong)(int)local_214;
                  iVar1 = strcmp(*(char **)(&DAT_18002cd38 +
                                           local_180 * 8 + (longlong)(int)local_218 * 0x80),
                                 (char *)(local_1e0 + 0x240));
                  if (iVar1 == 0) {
                    param_4 = (char *)(local_1e0 + 0x240);
                    FUN_1800220b0(0,
                                  "Parameters <%s> for Component <%s> were duplicate in FUNCTION POLYNOM - no Data written for the second Data."
                                  ,(&PTR_DAT_18002cd18)[(longlong)(int)local_218 * 0x10],param_4);
                    local_210 = 0;
                    break;
                  }
                }
              }
              if (local_210 == 0) break;
              local_1e8 = local_20c;
              strcpy(local_78,(&PTR_DAT_18002cd18)[(longlong)(int)local_218 * 0x10]);
              strcpy(local_60,(&PTR_s_N_sqm_18002cd28)[(longlong)(int)local_218 * 0x10]);
              local_1d8 = *(uint *)(&DAT_18002cd30 + (longlong)(int)local_218 * 0x80);
              local_1d0 = *(uint *)(&DAT_18002f250 +
                                   (longlong)
                                   (*(int *)(&DAT_18002cd20 + (longlong)(int)local_218 * 0x80) + -1)
                                   * 0xb8);
              FUN_180001000(local_200,local_48);
              if (0 < local_1e8) break;
            }
            local_208 = local_208 + 0xd;
            local_200 = local_200 + 0x14;
            local_1f8 = local_1f8 + 0xd;
          }
          break;
        case 1:
          local_20c = 1;
          local_208 = (char *)local_1f0[7];
          local_200 = (char *)local_1f0[9];
          local_1f8 = (char *)local_1f0[8];
          for (; local_20c <= *(short *)((longlong)local_1f0 + 0x8a); local_20c = local_20c + 1) {
            if ((local_208 != (char *)0x0) && (iVar1 = strcmp(local_208,"T"), iVar1 != 0)) {
              local_218 = 0;
              while ((&PTR_DAT_18002d710)[(longlong)(int)local_218 * 0x10] != (undefined *)0x0) {
                iVar1 = _stricmp((&PTR_DAT_18002d710)[(longlong)(int)local_218 * 0x10],local_208);
                if (iVar1 == 0) {
                  if ((&DAT_18002d734)[(longlong)(int)local_218 * 0x80] == ' ') {
                    local_210 = local_210 + 1;
                    break;
                  }
                  if (((local_1f8 != (char *)0x0) && (local_1f8 != (char *)0x0)) &&
                     ((&DAT_18002d734)[(longlong)(int)local_218 * 0x80] == *local_1f8)) {
                    local_210 = local_210 + 1;
                    break;
                  }
                }
                local_218 = local_218 + 1;
              }
              if (local_210 < 1) {
                FUN_1800220b0(0,
                              "Property <%s> in FUNCTION EXANTOINE is not supported by Aspen Plus - no Data written."
                              ,local_208,param_4);
                break;
              }
              local_1c8 = FUN_180007f80(local_200,
                                        *(int *)(&DAT_18002d720 + (longlong)(int)local_218 * 0x80));
              if (local_1c8 == (undefined *)0x0) {
                param_4 = local_208;
                FUN_1800220b0(0,
                              "Unit <%s> for property <%s> in FUNCTION EXANTOINE is not supported by Aspen Plus - no Data written."
                              ,local_200,local_208);
                break;
              }
              if (*(int *)(&DAT_18002d788 + (longlong)(int)local_218 * 0x80) == 0) {
                *(longlong *)(&DAT_18002d738 + (longlong)(int)local_218 * 0x80) = local_1e0 + 0x240;
                *(undefined4 *)(&DAT_18002d788 + (longlong)(int)local_218 * 0x80) = 1;
              }
              else {
                for (local_214 = 0; (int)local_214 < 10; local_214 = local_214 + 1) {
                  if (*(longlong *)
                       (&DAT_18002d738 +
                       (longlong)(int)local_214 * 8 + (longlong)(int)local_218 * 0x80) == 0) {
                    *(longlong *)
                     (&DAT_18002d738 +
                     (longlong)(int)local_214 * 8 + (longlong)(int)local_218 * 0x80) =
                         local_1e0 + 0x240;
                    *(uint *)(&DAT_18002d788 + (longlong)(int)local_218 * 0x80) = local_214 + 1;
                    break;
                  }
                  local_178 = (longlong)(int)local_214;
                  iVar1 = strcmp(*(char **)(&DAT_18002d738 +
                                           local_178 * 8 + (longlong)(int)local_218 * 0x80),
                                 (char *)(local_1e0 + 0x240));
                  if (iVar1 == 0) {
                    param_4 = (char *)(local_1e0 + 0x240);
                    FUN_1800220b0(0,
                                  "Parameters <%s> for Component <%s> were duplicate in FUNCTION EXANTOINE - no Data written for the second Data."
                                  ,(&PTR_s_PLXANT_18002d718)[(longlong)(int)local_218 * 0x10],
                                  param_4);
                    local_210 = 0;
                    break;
                  }
                }
              }
              if (local_210 == 0) break;
              local_1e8 = local_20c;
              strcpy(local_78,(&PTR_s_PLXANT_18002d718)[(longlong)(int)local_218 * 0x10]);
              strcpy(local_60,(&PTR_s_N_sqm_18002d728)[(longlong)(int)local_218 * 0x10]);
              local_1d8 = *(uint *)(&DAT_18002d730 + (longlong)(int)local_218 * 0x80);
              local_1d0 = *(uint *)(&DAT_18002f250 +
                                   (longlong)
                                   (*(int *)(&DAT_18002d720 + (longlong)(int)local_218 * 0x80) + -1)
                                   * 0xb8);
              FUN_180001000(local_200,local_48);
              if (0 < local_1e8) break;
            }
            local_208 = local_208 + 0xd;
            local_200 = local_200 + 0x14;
            local_1f8 = local_1f8 + 0xd;
          }
          break;
        case 2:
          local_20c = 1;
          local_208 = (char *)local_1f0[7];
          local_200 = (char *)local_1f0[9];
          local_1f8 = (char *)local_1f0[8];
          for (; local_20c <= *(short *)((longlong)local_1f0 + 0x8a); local_20c = local_20c + 1) {
            if ((local_208 != (char *)0x0) && (iVar1 = strcmp(local_208,"T"), iVar1 != 0)) {
              local_218 = 0;
              while ((&PTR_DAT_18002dc90)[(longlong)(int)local_218 * 0x10] != (undefined *)0x0) {
                iVar1 = _stricmp((&PTR_DAT_18002dc90)[(longlong)(int)local_218 * 0x10],local_208);
                if (iVar1 == 0) {
                  if ((&DAT_18002dcb4)[(longlong)(int)local_218 * 0x80] == ' ') {
                    local_210 = local_210 + 1;
                    break;
                  }
                  if (((local_1f8 != (char *)0x0) && (local_1f8 != (char *)0x0)) &&
                     ((&DAT_18002dcb4)[(longlong)(int)local_218 * 0x80] == *local_1f8)) {
                    local_210 = local_210 + 1;
                    break;
                  }
                }
                local_218 = local_218 + 1;
              }
              if (local_210 < 1) {
                FUN_1800220b0(0,
                              "Property <%s> in FUNCTION WAGNER is not supported by Aspen Plus - no Data written."
                              ,local_208,param_4);
                break;
              }
              local_1c8 = FUN_180007f80(local_200,
                                        *(int *)(&DAT_18002dca0 + (longlong)(int)local_218 * 0x80));
              if (local_1c8 == (undefined *)0x0) {
                param_4 = local_208;
                FUN_1800220b0(0,
                              "Unit <%s> for property <%s> in FUNCTION WAGNER is not supported by Aspen Plus - no Data written."
                              ,local_200,local_208);
                break;
              }
              if (*(int *)(&DAT_18002dd08 + (longlong)(int)local_218 * 0x80) == 0) {
                *(longlong *)(&DAT_18002dcb8 + (longlong)(int)local_218 * 0x80) = local_1e0 + 0x240;
                *(undefined4 *)(&DAT_18002dd08 + (longlong)(int)local_218 * 0x80) = 1;
              }
              else {
                for (local_214 = 0; (int)local_214 < 10; local_214 = local_214 + 1) {
                  if (*(longlong *)
                       (&DAT_18002dcb8 +
                       (longlong)(int)local_214 * 8 + (longlong)(int)local_218 * 0x80) == 0) {
                    *(longlong *)
                     (&DAT_18002dcb8 +
                     (longlong)(int)local_214 * 8 + (longlong)(int)local_218 * 0x80) =
                         local_1e0 + 0x240;
                    *(uint *)(&DAT_18002dd08 + (longlong)(int)local_218 * 0x80) = local_214 + 1;
                    break;
                  }
                  local_170 = (longlong)(int)local_214;
                  iVar1 = strcmp(*(char **)(&DAT_18002dcb8 +
                                           local_170 * 8 + (longlong)(int)local_218 * 0x80),
                                 (char *)(local_1e0 + 0x240));
                  if (iVar1 == 0) {
                    param_4 = (char *)(local_1e0 + 0x240);
                    FUN_1800220b0(0,
                                  "Parameters <%s> for Component <%s> were duplicate in FUNCTION WAGNER - no Data written for the second Data."
                                  ,(&PTR_s_WAGNER_18002dc98)[(longlong)(int)local_218 * 0x10],
                                  param_4);
                    local_210 = 0;
                    break;
                  }
                }
              }
              if (local_210 == 0) break;
              local_1e8 = local_20c;
              strcpy(local_78,(&PTR_s_WAGNER_18002dc98)[(longlong)(int)local_218 * 0x10]);
              strcpy(local_60,(&PTR_s_N_sqm_18002dca8)[(longlong)(int)local_218 * 0x10]);
              local_1d8 = *(uint *)(&DAT_18002dcb0 + (longlong)(int)local_218 * 0x80);
              local_1d0 = *(uint *)(&DAT_18002f250 +
                                   (longlong)
                                   (*(int *)(&DAT_18002dca0 + (longlong)(int)local_218 * 0x80) + -1)
                                   * 0xb8);
              FUN_180001000(local_200,local_48);
              if (0 < local_1e8) break;
            }
            local_208 = local_208 + 0xd;
            local_200 = local_200 + 0x14;
            local_1f8 = local_1f8 + 0xd;
          }
          break;
        case 3:
          local_20c = 1;
          local_208 = (char *)local_1f0[7];
          local_200 = (char *)local_1f0[9];
          local_1f8 = (char *)local_1f0[8];
          for (; local_20c <= *(short *)((longlong)local_1f0 + 0x8a); local_20c = local_20c + 1) {
            if ((local_208 != (char *)0x0) && (iVar1 = strcmp(local_208,"T"), iVar1 != 0)) {
              local_218 = 0;
              while ((&PTR_DAT_18002d810)[(longlong)(int)local_218 * 0x10] != (undefined *)0x0) {
                iVar1 = _stricmp((&PTR_DAT_18002d810)[(longlong)(int)local_218 * 0x10],local_208);
                if (iVar1 == 0) {
                  if ((&DAT_18002d834)[(longlong)(int)local_218 * 0x80] == ' ') {
                    local_210 = local_210 + 1;
                    break;
                  }
                  if (((local_1f8 != (char *)0x0) && (local_1f8 != (char *)0x0)) &&
                     ((&DAT_18002d834)[(longlong)(int)local_218 * 0x80] == *local_1f8)) {
                    local_210 = local_210 + 1;
                    break;
                  }
                }
                local_218 = local_218 + 1;
              }
              if (local_210 < 1) {
                FUN_1800220b0(0,
                              "Property <%s> in FUNCTION SUTHERLAND is not supported by Aspen Plus - no Data written."
                              ,local_208,param_4);
                break;
              }
              local_1c8 = FUN_180007f80(local_200,
                                        *(int *)(&DAT_18002d820 + (longlong)(int)local_218 * 0x80));
              if (local_1c8 == (undefined *)0x0) {
                param_4 = local_208;
                FUN_1800220b0(0,
                              "Unit <%s> for property <%s> in FUNCTION SUTHERLAND is not supported by Aspen Plus - no Data written."
                              ,local_200,local_208);
                break;
              }
              if (*(int *)(&DAT_18002d888 + (longlong)(int)local_218 * 0x80) == 0) {
                *(longlong *)(&DAT_18002d838 + (longlong)(int)local_218 * 0x80) = local_1e0 + 0x240;
                *(undefined4 *)(&DAT_18002d888 + (longlong)(int)local_218 * 0x80) = 1;
              }
              else {
                for (local_214 = 0; (int)local_214 < 10; local_214 = local_214 + 1) {
                  if (*(longlong *)
                       (&DAT_18002d838 +
                       (longlong)(int)local_214 * 8 + (longlong)(int)local_218 * 0x80) == 0) {
                    *(longlong *)
                     (&DAT_18002d838 +
                     (longlong)(int)local_214 * 8 + (longlong)(int)local_218 * 0x80) =
                         local_1e0 + 0x240;
                    *(uint *)(&DAT_18002d888 + (longlong)(int)local_218 * 0x80) = local_214 + 1;
                    break;
                  }
                  local_168 = (longlong)(int)local_214;
                  iVar1 = strcmp(*(char **)(&DAT_18002d838 +
                                           local_168 * 8 + (longlong)(int)local_218 * 0x80),
                                 (char *)(local_1e0 + 0x240));
                  if (iVar1 == 0) {
                    param_4 = (char *)(local_1e0 + 0x240);
                    FUN_1800220b0(0,
                                  "Parameters <%s> for Component <%s> were duplicate in FUNCTION SUTHERLAND - no Data written for the second Data."
                                  ,(&PTR_s_MUVSUT_18002d818)[(longlong)(int)local_218 * 0x10],
                                  param_4);
                    local_210 = 0;
                    break;
                  }
                }
              }
              if (local_210 == 0) break;
              local_1e8 = local_20c;
              strcpy(local_78,(&PTR_s_MUVSUT_18002d818)[(longlong)(int)local_218 * 0x10]);
              strcpy(local_60,(&PTR_s_N_sec_sqm_18002d828)[(longlong)(int)local_218 * 0x10]);
              local_1d8 = *(uint *)(&DAT_18002d830 + (longlong)(int)local_218 * 0x80);
              local_1d0 = *(uint *)(&DAT_18002f250 +
                                   (longlong)
                                   (*(int *)(&DAT_18002d820 + (longlong)(int)local_218 * 0x80) + -1)
                                   * 0xb8);
              FUN_180001000(local_200,local_48);
              if (0 < local_1e8) break;
            }
            local_208 = local_208 + 0xd;
            local_200 = local_200 + 0x14;
            local_1f8 = local_1f8 + 0xd;
          }
          break;
        case 4:
          local_20c = 1;
          local_208 = (char *)local_1f0[7];
          local_200 = (char *)local_1f0[9];
          local_1f8 = (char *)local_1f0[8];
          for (; local_20c <= *(short *)((longlong)local_1f0 + 0x8a); local_20c = local_20c + 1) {
            if ((local_208 != (char *)0x0) && (iVar1 = strcmp(local_208,"T"), iVar1 != 0)) {
              local_218 = 0;
              while ((&PTR_DAT_18002e290)[(longlong)(int)local_218 * 0x10] != (undefined *)0x0) {
                iVar1 = _stricmp((&PTR_DAT_18002e290)[(longlong)(int)local_218 * 0x10],local_208);
                if (iVar1 == 0) {
                  if ((&DAT_18002e2b4)[(longlong)(int)local_218 * 0x80] == ' ') {
                    local_210 = local_210 + 1;
                    break;
                  }
                  if (((local_1f8 != (char *)0x0) && (local_1f8 != (char *)0x0)) &&
                     ((&DAT_18002e2b4)[(longlong)(int)local_218 * 0x80] == *local_1f8)) {
                    local_210 = local_210 + 1;
                    break;
                  }
                }
                local_218 = local_218 + 1;
              }
              if (local_210 < 1) {
                FUN_1800220b0(0,
                              "Property <%s> in FUNCTION RACKETT is not supported by Aspen Plus - no Data written."
                              ,local_208,param_4);
                break;
              }
              local_1c8 = FUN_180007f80(local_200,
                                        *(int *)(&DAT_18002e2a0 + (longlong)(int)local_218 * 0x80));
              if (local_1c8 == (undefined *)0x0) {
                param_4 = local_208;
                FUN_1800220b0(0,
                              "Unit <%s> for property <%s> in FUNCTION RACKETT is not supported by Aspen Plus - no Data written."
                              ,local_200,local_208);
                break;
              }
              if (*(int *)(&DAT_18002e308 + (longlong)(int)local_218 * 0x80) == 0) {
                *(longlong *)(&DAT_18002e2b8 + (longlong)(int)local_218 * 0x80) = local_1e0 + 0x240;
                *(undefined4 *)(&DAT_18002e308 + (longlong)(int)local_218 * 0x80) = 1;
              }
              else {
                for (local_214 = 0; (int)local_214 < 10; local_214 = local_214 + 1) {
                  if (*(longlong *)
                       (&DAT_18002e2b8 +
                       (longlong)(int)local_214 * 8 + (longlong)(int)local_218 * 0x80) == 0) {
                    *(longlong *)
                     (&DAT_18002e2b8 +
                     (longlong)(int)local_214 * 8 + (longlong)(int)local_218 * 0x80) =
                         local_1e0 + 0x240;
                    *(uint *)(&DAT_18002e308 + (longlong)(int)local_218 * 0x80) = local_214 + 1;
                    break;
                  }
                  local_160 = (longlong)(int)local_214;
                  iVar1 = strcmp(*(char **)(&DAT_18002e2b8 +
                                           local_160 * 8 + (longlong)(int)local_218 * 0x80),
                                 (char *)(local_1e0 + 0x240));
                  if (iVar1 == 0) {
                    param_4 = (char *)(local_1e0 + 0x240);
                    FUN_1800220b0(0,
                                  "Parameters <%s> for Component <%s> were duplicate in FUNCTION RACKETT - no Data written for the second Data."
                                  ,(&PTR_s_DNLDIP_18002e298)[(longlong)(int)local_218 * 0x10],
                                  param_4);
                    local_210 = 0;
                    break;
                  }
                }
              }
              if (local_210 == 0) break;
              local_1e8 = local_20c;
              strcpy(local_78,(&PTR_s_DNLDIP_18002e298)[(longlong)(int)local_218 * 0x10]);
              strcpy(local_60,(&PTR_s_kmol_cum_18002e2a8)[(longlong)(int)local_218 * 0x10]);
              local_1d8 = *(uint *)(&DAT_18002e2b0 + (longlong)(int)local_218 * 0x80);
              local_1d0 = *(uint *)(&DAT_18002f250 +
                                   (longlong)
                                   (*(int *)(&DAT_18002e2a0 + (longlong)(int)local_218 * 0x80) + -1)
                                   * 0xb8);
              FUN_180001000(local_200,local_48);
              if (0 < local_1e8) break;
            }
            local_208 = local_208 + 0xd;
            local_200 = local_200 + 0x14;
            local_1f8 = local_1f8 + 0xd;
          }
          break;
        case 5:
          local_20c = 1;
          local_208 = (char *)local_1f0[7];
          local_200 = (char *)local_1f0[9];
          local_1f8 = (char *)local_1f0[8];
          for (; local_20c <= *(short *)((longlong)local_1f0 + 0x8a); local_20c = local_20c + 1) {
            if ((local_208 != (char *)0x0) && (iVar1 = strcmp(local_208,"T"), iVar1 != 0)) {
              local_218 = 0;
              while ((&PTR_DAT_18002d990)[(longlong)(int)local_218 * 0x10] != (undefined *)0x0) {
                iVar1 = _stricmp((&PTR_DAT_18002d990)[(longlong)(int)local_218 * 0x10],local_208);
                if (iVar1 == 0) {
                  if ((&DAT_18002d9b4)[(longlong)(int)local_218 * 0x80] == ' ') {
                    local_210 = local_210 + 1;
                    break;
                  }
                  if (((local_1f8 != (char *)0x0) && (local_1f8 != (char *)0x0)) &&
                     ((&DAT_18002d9b4)[(longlong)(int)local_218 * 0x80] == *local_1f8)) {
                    local_210 = local_210 + 1;
                    break;
                  }
                }
                local_218 = local_218 + 1;
              }
              if (local_210 < 1) {
                FUN_1800220b0(0,
                              "Property <%s> in FUNCTION CPL1 is not supported by Aspen Plus - no Data written."
                              ,local_208,param_4);
                break;
              }
              local_1c8 = FUN_180007f80(local_200,
                                        *(int *)(&DAT_18002d9a0 + (longlong)(int)local_218 * 0x80));
              if (local_1c8 == (undefined *)0x0) {
                param_4 = local_208;
                FUN_1800220b0(0,
                              "Unit <%s> for property <%s> in FUNCTION CPL1 is not supported by Aspen Plus - no Data written."
                              ,local_200,local_208);
                break;
              }
              if (*(int *)(&DAT_18002da08 + (longlong)(int)local_218 * 0x80) == 0) {
                *(longlong *)(&DAT_18002d9b8 + (longlong)(int)local_218 * 0x80) = local_1e0 + 0x240;
                *(undefined4 *)(&DAT_18002da08 + (longlong)(int)local_218 * 0x80) = 1;
              }
              else {
                for (local_214 = 0; (int)local_214 < 10; local_214 = local_214 + 1) {
                  if (*(longlong *)
                       (&DAT_18002d9b8 +
                       (longlong)(int)local_214 * 8 + (longlong)(int)local_218 * 0x80) == 0) {
                    *(longlong *)
                     (&DAT_18002d9b8 +
                     (longlong)(int)local_214 * 8 + (longlong)(int)local_218 * 0x80) =
                         local_1e0 + 0x240;
                    *(uint *)(&DAT_18002da08 + (longlong)(int)local_218 * 0x80) = local_214 + 1;
                    break;
                  }
                  local_158 = (longlong)(int)local_214;
                  iVar1 = strcmp(*(char **)(&DAT_18002d9b8 +
                                           local_158 * 8 + (longlong)(int)local_218 * 0x80),
                                 (char *)(local_1e0 + 0x240));
                  if (iVar1 == 0) {
                    param_4 = (char *)(local_1e0 + 0x240);
                    FUN_1800220b0(0,
                                  "Parameters <%s> for Component <%s> were duplicate in FUNCTION CPL1 - no Data written for the second Data."
                                  ,(&PTR_s_CPLIKC_18002d998)[(longlong)(int)local_218 * 0x10],
                                  param_4);
                    local_210 = 0;
                    break;
                  }
                }
              }
              if (local_210 == 0) break;
              local_1e8 = local_20c;
              strcpy(local_78,(&PTR_s_CPLIKC_18002d998)[(longlong)(int)local_218 * 0x10]);
              strcpy(local_60,(&PTR_s_J_kmol_K_18002d9a8)[(longlong)(int)local_218 * 0x10]);
              local_1d8 = *(uint *)(&DAT_18002d9b0 + (longlong)(int)local_218 * 0x80);
              local_1d0 = *(uint *)(&DAT_18002f250 +
                                   (longlong)
                                   (*(int *)(&DAT_18002d9a0 + (longlong)(int)local_218 * 0x80) + -1)
                                   * 0xb8);
              FUN_180001000(local_200,local_48);
              if (0 < local_1e8) break;
            }
            local_208 = local_208 + 0xd;
            local_200 = local_200 + 0x14;
            local_1f8 = local_1f8 + 0xd;
          }
          break;
        case 6:
          local_20c = 1;
          local_208 = (char *)local_1f0[7];
          local_200 = (char *)local_1f0[9];
          local_1f8 = (char *)local_1f0[8];
          for (; local_20c <= *(short *)((longlong)local_1f0 + 0x8a); local_20c = local_20c + 1) {
            if ((local_208 != (char *)0x0) && (iVar1 = strcmp(local_208,"T"), iVar1 != 0)) {
              local_218 = 0;
              while ((&PTR_DAT_18002db10)[(longlong)(int)local_218 * 0x10] != (undefined *)0x0) {
                iVar1 = _stricmp((&PTR_DAT_18002db10)[(longlong)(int)local_218 * 0x10],local_208);
                if (iVar1 == 0) {
                  if ((&DAT_18002db34)[(longlong)(int)local_218 * 0x80] == ' ') {
                    local_210 = local_210 + 1;
                    break;
                  }
                  if (((local_1f8 != (char *)0x0) && (local_1f8 != (char *)0x0)) &&
                     ((&DAT_18002db34)[(longlong)(int)local_218 * 0x80] == *local_1f8)) {
                    local_210 = local_210 + 1;
                    break;
                  }
                }
                local_218 = local_218 + 1;
              }
              if (local_210 < 1) {
                FUN_1800220b0(0,
                              "Property <%s> in FUNCTION VIS1 is not supported by Aspen Plus - no Data written."
                              ,local_208,param_4);
                break;
              }
              local_1c8 = FUN_180007f80(local_200,
                                        *(int *)(&DAT_18002db20 + (longlong)(int)local_218 * 0x80));
              if (local_1c8 == (undefined *)0x0) {
                param_4 = local_208;
                FUN_1800220b0(0,
                              "Unit <%s> for property <%s> in FUNCTION VIS1 is not supported by Aspen Plus - no Data written."
                              ,local_200,local_208);
                break;
              }
              if (*(int *)(&DAT_18002db88 + (longlong)(int)local_218 * 0x80) == 0) {
                *(longlong *)(&DAT_18002db38 + (longlong)(int)local_218 * 0x80) = local_1e0 + 0x240;
                *(undefined4 *)(&DAT_18002db88 + (longlong)(int)local_218 * 0x80) = 1;
              }
              else {
                for (local_214 = 0; (int)local_214 < 10; local_214 = local_214 + 1) {
                  if (*(longlong *)
                       (&DAT_18002db38 +
                       (longlong)(int)local_214 * 8 + (longlong)(int)local_218 * 0x80) == 0) {
                    *(longlong *)
                     (&DAT_18002db38 +
                     (longlong)(int)local_214 * 8 + (longlong)(int)local_218 * 0x80) =
                         local_1e0 + 0x240;
                    *(uint *)(&DAT_18002db88 + (longlong)(int)local_218 * 0x80) = local_214 + 1;
                    break;
                  }
                  local_150 = (longlong)(int)local_214;
                  iVar1 = strcmp(*(char **)(&DAT_18002db38 +
                                           local_150 * 8 + (longlong)(int)local_218 * 0x80),
                                 (char *)(local_1e0 + 0x240));
                  if (iVar1 == 0) {
                    param_4 = (char *)(local_1e0 + 0x240);
                    FUN_1800220b0(0,
                                  "Parameters <%s> for Component <%s> were duplicate in FUNCTION VIS1 - no Data written for the second Data."
                                  ,(&PTR_s_MULIKC_18002db18)[(longlong)(int)local_218 * 0x10],
                                  param_4);
                    local_210 = 0;
                    break;
                  }
                }
              }
              if (local_210 == 0) break;
              local_1e8 = local_20c;
              strcpy(local_78,(&PTR_s_MULIKC_18002db18)[(longlong)(int)local_218 * 0x10]);
              strcpy(local_60,(&PTR_s_N_sec_sqm_18002db28)[(longlong)(int)local_218 * 0x10]);
              local_1d8 = *(uint *)(&DAT_18002db30 + (longlong)(int)local_218 * 0x80);
              local_1d0 = *(uint *)(&DAT_18002f250 +
                                   (longlong)
                                   (*(int *)(&DAT_18002db20 + (longlong)(int)local_218 * 0x80) + -1)
                                   * 0xb8);
              FUN_180001000(local_200,local_48);
              if (0 < local_1e8) break;
            }
            local_208 = local_208 + 0xd;
            local_200 = local_200 + 0x14;
            local_1f8 = local_1f8 + 0xd;
          }
          break;
        case 7:
          local_20c = 1;
          local_208 = (char *)local_1f0[7];
          local_200 = (char *)local_1f0[9];
          local_1f8 = (char *)local_1f0[8];
          for (; local_20c <= *(short *)((longlong)local_1f0 + 0x8a); local_20c = local_20c + 1) {
            if ((local_208 != (char *)0x0) && (iVar1 = strcmp(local_208,"T"), iVar1 != 0)) {
              local_218 = 0;
              while ((&PTR_DAT_18002e190)[(longlong)(int)local_218 * 0x10] != (undefined *)0x0) {
                iVar1 = _stricmp((&PTR_DAT_18002e190)[(longlong)(int)local_218 * 0x10],local_208);
                if (iVar1 == 0) {
                  if ((&DAT_18002e1b4)[(longlong)(int)local_218 * 0x80] == ' ') {
                    local_210 = local_210 + 1;
                    break;
                  }
                  if (((local_1f8 != (char *)0x0) && (local_1f8 != (char *)0x0)) &&
                     ((&DAT_18002e1b4)[(longlong)(int)local_218 * 0x80] == *local_1f8)) {
                    local_210 = local_210 + 1;
                    break;
                  }
                }
                local_218 = local_218 + 1;
              }
              if (local_210 < 1) {
                FUN_1800220b0(0,
                              "Property <%s> in FUNCTION ALYLEE is not supported by Aspen Plus - no Data written."
                              ,local_208,param_4);
                break;
              }
              local_1c8 = FUN_180007f80(local_200,
                                        *(int *)(&DAT_18002e1a0 + (longlong)(int)local_218 * 0x80));
              if (local_1c8 == (undefined *)0x0) {
                param_4 = local_208;
                FUN_1800220b0(0,
                              "Unit <%s> for property <%s> in FUNCTION ALYLEE is not supported by Aspen Plus - no Data written."
                              ,local_200,local_208);
                break;
              }
              if (*(int *)(&DAT_18002e208 + (longlong)(int)local_218 * 0x80) == 0) {
                *(longlong *)(&DAT_18002e1b8 + (longlong)(int)local_218 * 0x80) = local_1e0 + 0x240;
                *(undefined4 *)(&DAT_18002e208 + (longlong)(int)local_218 * 0x80) = 1;
              }
              else {
                for (local_214 = 0; (int)local_214 < 10; local_214 = local_214 + 1) {
                  if (*(longlong *)
                       (&DAT_18002e1b8 +
                       (longlong)(int)local_214 * 8 + (longlong)(int)local_218 * 0x80) == 0) {
                    *(longlong *)
                     (&DAT_18002e1b8 +
                     (longlong)(int)local_214 * 8 + (longlong)(int)local_218 * 0x80) =
                         local_1e0 + 0x240;
                    *(uint *)(&DAT_18002e208 + (longlong)(int)local_218 * 0x80) = local_214 + 1;
                    break;
                  }
                  local_148 = (longlong)(int)local_214;
                  iVar1 = strcmp(*(char **)(&DAT_18002e1b8 +
                                           local_148 * 8 + (longlong)(int)local_218 * 0x80),
                                 (char *)(local_1e0 + 0x240));
                  if (iVar1 == 0) {
                    param_4 = (char *)(local_1e0 + 0x240);
                    FUN_1800220b0(0,
                                  "Parameters <%s> for Component <%s> were duplicate in FUNCTION ALYLEE - no Data written for the second Data."
                                  ,(&PTR_s_CPIGDP_18002e198)[(longlong)(int)local_218 * 0x10],
                                  param_4);
                    local_210 = 0;
                    break;
                  }
                }
              }
              if (local_210 == 0) break;
              local_1e8 = local_20c;
              strcpy(local_78,(&PTR_s_CPIGDP_18002e198)[(longlong)(int)local_218 * 0x10]);
              strcpy(local_60,(&PTR_s_J_kmol_K_18002e1a8)[(longlong)(int)local_218 * 0x10]);
              local_1d8 = *(uint *)(&DAT_18002e1b0 + (longlong)(int)local_218 * 0x80);
              local_1d0 = *(uint *)(&DAT_18002f250 +
                                   (longlong)
                                   (*(int *)(&DAT_18002e1a0 + (longlong)(int)local_218 * 0x80) + -1)
                                   * 0xb8);
              FUN_180001000(local_200,local_48);
              if (0 < local_1e8) break;
            }
            local_208 = local_208 + 0xd;
            local_200 = local_200 + 0x14;
            local_1f8 = local_1f8 + 0xd;
          }
          break;
        case 8:
          local_20c = 1;
          local_208 = (char *)local_1f0[7];
          local_200 = (char *)local_1f0[9];
          local_1f8 = (char *)local_1f0[8];
          for (; local_20c <= *(short *)((longlong)local_1f0 + 0x8a); local_20c = local_20c + 1) {
            if ((local_208 != (char *)0x0) && (iVar1 = strcmp(local_208,"T"), iVar1 != 0)) {
              local_218 = 0;
              while ((&PTR_DAT_18002e010)[(longlong)(int)local_218 * 0x10] != (undefined *)0x0) {
                iVar1 = _stricmp((&PTR_DAT_18002e010)[(longlong)(int)local_218 * 0x10],local_208);
                if (iVar1 == 0) {
                  if ((&DAT_18002e034)[(longlong)(int)local_218 * 0x80] == ' ') {
                    local_210 = local_210 + 1;
                    break;
                  }
                  if (((local_1f8 != (char *)0x0) && (local_1f8 != (char *)0x0)) &&
                     ((&DAT_18002e034)[(longlong)(int)local_218 * 0x80] == *local_1f8)) {
                    local_210 = local_210 + 1;
                    break;
                  }
                }
                local_218 = local_218 + 1;
              }
              if (local_210 < 1) {
                FUN_1800220b0(0,
                              "Property <%s> in FUNCTION DIP4 is not supported by Aspen Plus - no Data written."
                              ,local_208,param_4);
                break;
              }
              local_1c8 = FUN_180007f80(local_200,
                                        *(int *)(&DAT_18002e020 + (longlong)(int)local_218 * 0x80));
              if (local_1c8 == (undefined *)0x0) {
                param_4 = local_208;
                FUN_1800220b0(0,
                              "Unit <%s> for property <%s> in FUNCTION DIP4 is not supported by Aspen Plus - no Data written."
                              ,local_200,local_208);
                break;
              }
              if (*(int *)(&DAT_18002e088 + (longlong)(int)local_218 * 0x80) == 0) {
                *(longlong *)(&DAT_18002e038 + (longlong)(int)local_218 * 0x80) = local_1e0 + 0x240;
                *(undefined4 *)(&DAT_18002e088 + (longlong)(int)local_218 * 0x80) = 1;
              }
              else {
                for (local_214 = 0; (int)local_214 < 10; local_214 = local_214 + 1) {
                  if (*(longlong *)
                       (&DAT_18002e038 +
                       (longlong)(int)local_214 * 8 + (longlong)(int)local_218 * 0x80) == 0) {
                    *(longlong *)
                     (&DAT_18002e038 +
                     (longlong)(int)local_214 * 8 + (longlong)(int)local_218 * 0x80) =
                         local_1e0 + 0x240;
                    *(uint *)(&DAT_18002e088 + (longlong)(int)local_218 * 0x80) = local_214 + 1;
                    break;
                  }
                  local_140 = (longlong)(int)local_214;
                  iVar1 = strcmp(*(char **)(&DAT_18002e038 +
                                           local_140 * 8 + (longlong)(int)local_218 * 0x80),
                                 (char *)(local_1e0 + 0x240));
                  if (iVar1 == 0) {
                    param_4 = (char *)(local_1e0 + 0x240);
                    FUN_1800220b0(0,
                                  "Parameters <%s> for Component <%s> were duplicate in FUNCTION DIP4 - no Data written for the second Data."
                                  ,(&PTR_s_DHVLDP_18002e018)[(longlong)(int)local_218 * 0x10],
                                  param_4);
                    local_210 = 0;
                    break;
                  }
                }
              }
              if (local_210 == 0) break;
              local_1e8 = local_20c;
              strcpy(local_78,(&PTR_s_DHVLDP_18002e018)[(longlong)(int)local_218 * 0x10]);
              strcpy(local_60,(&PTR_s_J_kmol_18002e028)[(longlong)(int)local_218 * 0x10]);
              local_1d8 = *(uint *)(&DAT_18002e030 + (longlong)(int)local_218 * 0x80);
              local_1d0 = *(uint *)(&DAT_18002f250 +
                                   (longlong)
                                   (*(int *)(&DAT_18002e020 + (longlong)(int)local_218 * 0x80) + -1)
                                   * 0xb8);
              FUN_180001000(local_200,local_48);
              if (0 < local_1e8) break;
            }
            local_208 = local_208 + 0xd;
            local_200 = local_200 + 0x14;
            local_1f8 = local_1f8 + 0xd;
          }
          break;
        case 9:
          local_20c = 1;
          local_208 = (char *)local_1f0[7];
          local_200 = (char *)local_1f0[9];
          local_1f8 = (char *)local_1f0[8];
          for (; local_20c <= *(short *)((longlong)local_1f0 + 0x8a); local_20c = local_20c + 1) {
            if ((local_208 != (char *)0x0) && (iVar1 = strcmp(local_208,"T"), iVar1 != 0)) {
              local_218 = 0;
              while ((&PTR_DAT_18002dd90)[(longlong)(int)local_218 * 0x10] != (undefined *)0x0) {
                iVar1 = _stricmp((&PTR_DAT_18002dd90)[(longlong)(int)local_218 * 0x10],local_208);
                if (iVar1 == 0) {
                  if ((&DAT_18002ddb4)[(longlong)(int)local_218 * 0x80] == ' ') {
                    local_210 = local_210 + 1;
                    break;
                  }
                  if (((local_1f8 != (char *)0x0) && (local_1f8 != (char *)0x0)) &&
                     ((&DAT_18002ddb4)[(longlong)(int)local_218 * 0x80] == *local_1f8)) {
                    local_210 = local_210 + 1;
                    break;
                  }
                }
                local_218 = local_218 + 1;
              }
              if (local_210 < 1) {
                FUN_1800220b0(0,
                              "Property <%s> in FUNCTION DIP5 is not supported by Aspen Plus - no Data written."
                              ,local_208,param_4);
                break;
              }
              local_1c8 = FUN_180007f80(local_200,
                                        *(int *)(&DAT_18002dda0 + (longlong)(int)local_218 * 0x80));
              if (local_1c8 == (undefined *)0x0) {
                param_4 = local_208;
                FUN_1800220b0(0,
                              "Unit <%s> for property <%s> in FUNCTION DIP5 is not supported by Aspen Plus - no Data written."
                              ,local_200,local_208);
                break;
              }
              if (*(int *)(&DAT_18002de08 + (longlong)(int)local_218 * 0x80) == 0) {
                *(longlong *)(&DAT_18002ddb8 + (longlong)(int)local_218 * 0x80) = local_1e0 + 0x240;
                *(undefined4 *)(&DAT_18002de08 + (longlong)(int)local_218 * 0x80) = 1;
              }
              else {
                for (local_214 = 0; (int)local_214 < 10; local_214 = local_214 + 1) {
                  if (*(longlong *)
                       (&DAT_18002ddb8 +
                       (longlong)(int)local_214 * 8 + (longlong)(int)local_218 * 0x80) == 0) {
                    *(longlong *)
                     (&DAT_18002ddb8 +
                     (longlong)(int)local_214 * 8 + (longlong)(int)local_218 * 0x80) =
                         local_1e0 + 0x240;
                    *(uint *)(&DAT_18002de08 + (longlong)(int)local_218 * 0x80) = local_214 + 1;
                    break;
                  }
                  local_138 = (longlong)(int)local_214;
                  iVar1 = strcmp(*(char **)(&DAT_18002ddb8 +
                                           local_138 * 8 + (longlong)(int)local_218 * 0x80),
                                 (char *)(local_1e0 + 0x240));
                  if (iVar1 == 0) {
                    param_4 = (char *)(local_1e0 + 0x240);
                    FUN_1800220b0(0,
                                  "Parameters <%s> for Component <%s> were duplicate in FUNCTION DIP5 - no Data written for the second Data."
                                  ,(&PTR_s_MUVDIP_18002dd98)[(longlong)(int)local_218 * 0x10],
                                  param_4);
                    local_210 = 0;
                    break;
                  }
                }
              }
              if (local_210 == 0) break;
              local_1e8 = local_20c;
              strcpy(local_78,(&PTR_s_MUVDIP_18002dd98)[(longlong)(int)local_218 * 0x10]);
              strcpy(local_60,(&PTR_s_N_sec_sqm_18002dda8)[(longlong)(int)local_218 * 0x10]);
              local_1d8 = *(uint *)(&DAT_18002ddb0 + (longlong)(int)local_218 * 0x80);
              local_1d0 = *(uint *)(&DAT_18002f250 +
                                   (longlong)
                                   (*(int *)(&DAT_18002dda0 + (longlong)(int)local_218 * 0x80) + -1)
                                   * 0xb8);
              FUN_180001000(local_200,local_48);
              if (0 < local_1e8) break;
            }
            local_208 = local_208 + 0xd;
            local_200 = local_200 + 0x14;
            local_1f8 = local_1f8 + 0xd;
          }
          break;
        case 10:
        case 0xb:
        case 0xc:
        case 0xd:
        case 0xe:
        case 0xf:
          FUN_1800220b0(0,"Sorry! Function <%s> is not supported by Aspen Plus yet!",
                        (&PTR_s_POLYNOM_18002cb70)[(longlong)local_1d4 * 3],param_4);
        }
        if (-1 < local_1e8) {
          if (local_1f0[0x10] == 0) {
            FUN_1800220b0(0,"No coefficients entry for Function <%s> - no Data written.",
                          (&PTR_s_POLYNOM_18002cb70)[(longlong)local_1d4 * 3],param_4);
          }
          if ((int)(local_1d8 - 2) < (int)*(short *)(local_1f0 + 0x11)) {
            param_4 = local_78;
            FUN_1800220b0(0,
                          "Number of coefficients of PPDX Function <%s> is more than APLUS function <%s> - no Data written."
                          ,(&PTR_s_POLYNOM_18002cb70)[(longlong)local_1d4 * 3],param_4);
          }
          else {
            pcVar3 = local_78;
            FUN_180007f00(param_1,"? PROPERTIES PARAMETERS UNARY \"T-DEPENDENT\" \"%s-1\" ? ",pcVar3
                          ,param_4);
            FUN_180007f00(param_1," ; \"SI_MOLE\" ; \n",pcVar3,param_4);
            FUN_180007f00(param_1,"\\ PROP-LIST PARAMNAME = %s",local_78,param_4);
            FUN_180007f00(param_1," SETNO = 1 UNITROW = %2i \n",(ulonglong)local_1d0,param_4);
            FUN_180007f00(param_1," UNITLABEL = \"%s\"",local_60,param_4);
            FUN_180007f00(param_1," TUNITROW = 22 TUNITLABEL = K NEL = %2i \\ \n",
                          (ulonglong)local_1d8,param_4);
            FUN_180007f00(param_1,"\\ PVAL PARAMNAME2 = %s",local_78,param_4);
            _strupr((char *)(local_1e0 + 0x240));
            FUN_180007f00(param_1," CID = %s",local_1e0 + 0x240,param_4);
            FUN_180007f00(param_1," UNITROW2 = %2i \n",(ulonglong)local_1d0,param_4);
            FUN_180007f00(param_1," UNITLABEL2 = \"%s\"",local_48,param_4);
            param_4 = (char *)(ulonglong)local_1d8;
            FUN_180007f00(param_1," TUNITROW2 = 22 TUNITLABEL2 = %s NEL2 = %2i \n",local_30,param_4)
            ;
            for (local_20c = 0; local_20c < *(short *)(local_1f0 + 0x11); local_20c = local_20c + 1)
            {
              alStack_118[local_20c] = *(longlong *)(local_1f0[0x10] + (longlong)local_20c * 8);
            }
            local_214 = 1;
            for (local_218 = 1; uVar2 = (int)local_214 >> 0x1f,
                (int)local_218 <= (int)(local_1d8 - 2); local_218 = local_218 + 1) {
              if ((int)*(short *)(local_1f0 + 0x11) < (int)local_218) {
                if ((local_214 & 1 ^ uVar2) == uVar2) {
                  FUN_180007f00(param_1," UVAL%d = 0 <0> <0> \n",(ulonglong)local_218,param_4);
                  local_214 = local_214 + 1;
                }
                else {
                  FUN_180007f00(param_1," UVAL%d = 0 <0> <0>",(ulonglong)local_218,param_4);
                  local_214 = local_214 + 1;
                }
              }
              else {
                if ((local_214 & 1 ^ uVar2) == uVar2) {
                  param_4 = (char *)alStack_118[(int)(local_218 - 1)];
                  FUN_180007f00(param_1," UVAL%d = %-11G <0> <0> \n",(ulonglong)local_218,param_4);
                }
                else {
                  param_4 = (char *)alStack_118[(int)(local_218 - 1)];
                  FUN_180007f00(param_1," UVAL%d = %-11G <0> <0>",(ulonglong)local_218,param_4);
                }
                local_214 = local_214 + 1;
              }
            }
            if (local_1f0[0xe] == 0) {
              if ((local_214 & 1 ^ uVar2) == uVar2) {
                FUN_180007f00(param_1," UVAL%d = 0 <0> <0> \n",(ulonglong)(local_1d8 - 1),param_4);
                local_214 = local_214 + 1;
              }
              else {
                FUN_180007f00(param_1," UVAL%d = 0 <0> <0>",(ulonglong)(local_1d8 - 1),param_4);
                local_214 = local_214 + 1;
              }
            }
            else {
              param_4 = *(char **)local_1f0[0xe];
              local_1a0 = param_4;
              if ((local_214 & 1 ^ uVar2) == uVar2) {
                FUN_180007f00(param_1," UVAL%d = %-11G <0> <0> \n",(ulonglong)(local_1d8 - 1),
                              param_4);
              }
              else {
                FUN_180007f00(param_1," UVAL%d = %-11G <0> <0>",(ulonglong)(local_1d8 - 1),param_4);
              }
              local_214 = local_214 + 1;
            }
            if (local_1f0[0xf] == 0) {
              FUN_180007f00(param_1," UVAL%d = 0 <0> <0> \\ \n",(ulonglong)local_1d8,param_4);
            }
            else {
              param_4 = *(char **)local_1f0[0xf];
              local_130 = param_4;
              FUN_180007f00(param_1," UVAL%d = %-11G <0> <0> \\ \n",(ulonglong)local_1d8,param_4);
            }
          }
        }
      }
    }
    local_1b0 = (longlong *)local_1b0[1];
  } while( true );
}

/* RVA 0xd730, FUN_18000d730 */
void FUN_18000d730(undefined8 param_1,int param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  
  FUN_180007f00(param_1,&DAT_1800272c0,
                "; *****************************************************************************",
                param_4);
  FUN_180007f00(param_1,&DAT_1800272c0,&DAT_1800272c4,param_4);
  FUN_180007f00(param_1,&DAT_1800272c0,"; Partial Input File for: ASPEN-PLUS, Rel. 9.x",param_4);
  FUN_180007f00(param_1,&DAT_1800272c0,&DAT_1800272c4,param_4);
  uVar1 = 1;
  FUN_180007f00(param_1,"%s %d.%d\n","; File generated from   : PPDX-ASPENPLUS-CONVERTER, Rel.",1);
  FUN_180007f00(param_1,&DAT_1800272c0,&DAT_1800272c4,uVar1);
  FUN_180007f00(param_1,&DAT_1800273a0,
                "; ********************** COPYRIGHT BY DECHEMA e.V. ****************************",
                uVar1);
  if (param_2 == 1) {
    FUN_180007f00(param_1,&DAT_1800272c0,&DAT_1800272c4,uVar1);
    FUN_180007f00(param_1,&DAT_1800272c0,"; Run class identifier: DRS",uVar1);
    FUN_180007f00(param_1,&DAT_1800272c0,&DAT_1800272c4,uVar1);
    FUN_180007f00(param_1,&DAT_1800273a0,&DAT_1800273c4,uVar1);
  }
  else {
    FUN_180007f00(param_1,&DAT_1800272c0,&DAT_1800272c4,uVar1);
    FUN_180007f00(param_1,&DAT_1800272c0,"; Run class identifier: FLOWSHEET",uVar1);
    FUN_180007f00(param_1,&DAT_1800272c0,&DAT_1800272c4,uVar1);
    FUN_180007f00(param_1,&DAT_1800273a0,"FLOWSHEET",uVar1);
  }
  FUN_180007f00(param_1,&DAT_1800272c0,&DAT_1800272c4,uVar1);
  FUN_180007f00(param_1,&DAT_1800272c0,"; titel of run",uVar1);
  FUN_180007f00(param_1,&DAT_1800272c0,&DAT_1800272c4,uVar1);
  FUN_180007f00(param_1,&DAT_1800273a0,";TITLE \'xxx\'",uVar1);
  FUN_180007f00(param_1,&DAT_1800272c0,&DAT_1800272c4,uVar1);
  FUN_180007f00(param_1,&DAT_1800272c0,"; Units",uVar1);
  FUN_180007f00(param_1,&DAT_1800272c0,&DAT_1800272c4,uVar1);
  FUN_180007f00(param_1,&DAT_1800273a0,"IN-UNITS SI",uVar1);
  return;
}

/* RVA 0xd990, FUN_18000d990 */
void FUN_18000d990(undefined8 param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar2 = MVGetVersionString();
  uVar1 = MVGetVersionString();
  FUN_180007f00(param_1,
                "MM \"%s\" FLAVOR \"NO\" VERSION \"%s\" DATETIME \"Fri Sep 19 14:00:00 1997\" MACHINE \"WIN-NT/VC\" \n"
                ,uVar1,uVar2);
  FUN_180007f00(param_1,"? SETUP MAIN ? \n",uVar1,uVar2);
  return;
}

/* RVA 0xd9e0, FUN_18000d9e0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18000d9e0(undefined8 param_1,uint *param_2,double *param_3,double *param_4)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 auStack_1c8 [32];
  int local_1a8;
  int local_1a4;
  int local_1a0;
  double *local_198;
  int local_190;
  double *local_188;
  int local_180;
  int local_17c;
  int local_178;
  int local_174;
  undefined8 *local_170;
  int local_168;
  double local_160;
  double local_158;
  int local_150;
  int local_14c;
  int *local_148;
  double local_140;
  undefined **local_138;
  double *local_130;
  undefined **local_128;
  double *local_120;
  undefined **local_118;
  double *local_110;
  char local_108 [32];
  char local_e8 [208];
  ulonglong local_18;
  
  local_18 = DAT_180032178 ^ (ulonglong)auStack_1c8;
  local_188 = (double *)0x0;
  local_178 = 0;
  local_174 = 4;
  local_1a4 = 1;
  local_168 = 0;
  local_14c = 0;
  local_180 = 0;
  local_1a8 = 0;
  FUN_180003ba0(&local_14c,&local_180,param_3,(char *)param_4);
  for (local_17c = 0; local_17c < 100; local_17c = local_17c + 1) {
    strcpy(&DAT_180034ba0 + (longlong)local_17c * 100,"");
  }
  strcpy(local_108,"");
  local_148 = FUN_180021a60(3);
  if (*(longlong *)(local_148 + 2) != 0) {
    *param_2 = *param_2 + 1;
    param_3 = (double *)(ulonglong)*param_2;
    FUN_180007f00(param_1,"PROP-DATA PD-%d\n",param_3,param_4);
  }
  local_150 = 0;
  local_190 = 0;
  for (local_170 = *(undefined8 **)(local_148 + 2); local_170 != (undefined8 *)0x0;
      local_170 = (undefined8 *)local_170[1]) {
    local_198 = (double *)*local_170;
    local_158 = local_198[2];
    local_140 = local_198[0xd];
    local_1a0 = 0;
    while ((&PTR_DAT_18002c8a0)[(longlong)local_1a0 * 3] != (undefined *)0x0) {
      local_138 = &PTR_DAT_18002c8a0;
      iVar1 = _stricmp((&PTR_DAT_18002c8a0)[(longlong)local_1a0 * 3],(char *)local_198);
      if (iVar1 == 0) break;
      local_1a0 = local_1a0 + 1;
    }
    if ((&PTR_DAT_18002c8a8)[(longlong)local_1a0 * 3] == (undefined *)0x0) {
      param_3 = local_198;
      FUN_1800220b0(1,"Property %s not supported by Aspen Plus",local_198,param_4);
    }
    else {
      local_130 = local_198 + 4;
      param_3 = &local_160;
      local_188 = (double *)
                  FUN_1800082f0((char *)local_130,
                                *(int *)(&DAT_18002c8b0 + (longlong)local_1a0 * 0x18),param_3);
      if (local_188 == (double *)0x0) {
        if (*(int *)(&DAT_18002c8b0 + (longlong)local_1a0 * 0x18) == 0) {
          param_3 = &local_160;
          FUN_180001a20((char *)(local_198 + 4),local_e8,param_3);
        }
        else {
          param_3 = local_198 + 4;
          param_4 = local_198;
          FUN_1800220b0(1,"Unit <%s> for property <%s> not supported by Aspen Plus",param_3,
                        local_198);
        }
      }
      else {
        iVar1 = strcmp((char *)local_188,"DIPOLEMOMENT=\'(J/CUM)**.5\'");
        if (iVar1 == 0) {
          strcpy((char *)local_188,"DIPOLEMOMENT=\'(J*CUM)**.5\'");
        }
        if (local_150 == 0) {
          FUN_180007f00(param_1,"  IN-UNITS SI ",param_3,param_4);
          if ((local_188 != (double *)0x0) &&
             (uVar2 = FUN_180003770((char *)local_188,local_178), (int)uVar2 == 0)) {
            param_3 = local_188;
            if (local_1a8 == local_14c + -1) {
              FUN_180007f00(param_1,"              %s \n",local_188,param_4);
            }
            else {
              FUN_180007f00(param_1,"%s &\n",local_188,param_4);
            }
            strcpy(&DAT_180034ba0 + (longlong)local_178 * 100,(char *)local_188);
            local_178 = local_178 + 1;
            local_1a8 = local_1a8 + 1;
          }
          local_150 = 1;
        }
        if (((local_188 != (double *)0x0) && (local_150 == 1)) &&
           (uVar2 = FUN_180003770((char *)local_188,local_178), (int)uVar2 == 0)) {
          param_3 = local_188;
          if (local_1a8 == local_14c + -1) {
            FUN_180007f00(param_1,"              %s \n",local_188,param_4);
          }
          else {
            FUN_180007f00(param_1,"              %s &\n",local_188,param_4);
          }
          strcpy(&DAT_180034ba0 + (longlong)local_178 * 100,(char *)local_188);
          local_178 = local_178 + 1;
          local_1a8 = local_1a8 + 1;
        }
      }
    }
  }
  local_1a8 = 0;
  local_148 = FUN_180021a60(3);
  local_170 = *(undefined8 **)(local_148 + 2);
  do {
    if (local_170 == (undefined8 *)0x0) {
LAB_18000e348:
      local_1a8 = 0;
      FUN_180007f00(param_1,&DAT_180027258,param_3,param_4);
      local_1a4 = 1;
      strcpy(local_108,"");
      local_148 = FUN_180021a60(3);
      local_170 = *(undefined8 **)(local_148 + 2);
      do {
        if (local_170 == (undefined8 *)0x0) {
          FUN_180007f00(param_1,&DAT_180027468,param_3,param_4);
          strcpy(local_108,"");
          for (local_17c = 0; local_17c < 100; local_17c = local_17c + 1) {
            strcpy(&DAT_180034ba0 + (longlong)local_17c * 100,"");
          }
          return;
        }
        local_198 = (double *)*local_170;
        local_158 = local_198[2];
        local_140 = local_198[0xd];
        local_1a0 = 0;
        while ((&PTR_DAT_18002c8a0)[(longlong)local_1a0 * 3] != (undefined *)0x0) {
          local_118 = &PTR_DAT_18002c8a0;
          iVar1 = _stricmp((&PTR_DAT_18002c8a0)[(longlong)local_1a0 * 3],(char *)local_198);
          if (iVar1 == 0) break;
          local_1a0 = local_1a0 + 1;
        }
        if ((&PTR_DAT_18002c8a8)[(longlong)local_1a0 * 3] == (undefined *)0x0) {
          param_3 = local_198;
          FUN_1800220b0(1,"Property %s not supported by Aspen Plus",local_198,param_4);
        }
        else {
          local_110 = local_198 + 4;
          param_3 = &local_160;
          local_188 = (double *)
                      FUN_1800082f0((char *)local_110,
                                    *(int *)(&DAT_18002c8b0 + (longlong)local_1a0 * 0x18),param_3);
          if (local_188 == (double *)0x0) {
            if (*(int *)(&DAT_18002c8b0 + (longlong)local_1a0 * 0x18) == 0) {
              param_3 = &local_160;
              FUN_180001a20((char *)(local_198 + 4),local_e8,param_3);
              iVar1 = strcmp(local_108,(char *)((longlong)local_158 + 0x240));
              if (iVar1 != 0) {
                local_190 = 0;
              }
              if (local_190 == 0) {
                local_1a4 = 1;
                local_1a8 = 0;
                param_3 = (double *)((longlong)local_158 + 0x240);
                FUN_180007f00(param_1,"\n  PVAL % 5s",param_3,param_4);
                local_190 = 1;
                strcpy(local_108,(char *)((longlong)local_158 + 0x240));
              }
              if (local_1a4 == 1) {
                if (local_1a8 == local_180 + -1) {
                  param_3 = (double *)(local_198[3] * local_160);
                  FUN_180007f00(param_1,&DAT_1800275b0,param_3,param_4);
                }
                else {
                  param_3 = (double *)(local_198[3] * local_160);
                  FUN_180007f00(param_1," %G /",param_3,param_4);
                }
                local_1a8 = local_1a8 + 1;
              }
              if ((1 < local_1a4) && (local_1a4 <= local_174)) {
                if (local_1a8 == local_180 + -1) {
                  param_3 = (double *)(local_198[3] * local_160);
                  FUN_180007f00(param_1,&DAT_1800275b0,param_3,param_4);
                }
                else {
                  param_3 = (double *)(local_198[3] * local_160);
                  FUN_180007f00(param_1,"  %G /",param_3,param_4);
                }
                local_1a8 = local_1a8 + 1;
              }
              local_1a4 = local_1a4 + 1;
              if (local_174 < local_1a4) {
                FUN_180007f00(param_1,"  \n            ",param_3,param_4);
                local_1a4 = 1;
              }
            }
            else {
              param_3 = local_198 + 4;
              param_4 = local_198;
              FUN_1800220b0(1,"Unit <%s> for property <%s> not supported by Aspen Plus",param_3,
                            local_198);
            }
          }
          else if (local_188 != (double *)0x0) {
            iVar1 = strcmp(local_108,(char *)((longlong)local_158 + 0x240));
            if (iVar1 != 0) {
              local_190 = 0;
            }
            if (local_190 == 0) {
              local_1a4 = 1;
              local_1a8 = 0;
              param_3 = (double *)((longlong)local_158 + 0x240);
              FUN_180007f00(param_1,"\n  PVAL % 5s",param_3,param_4);
              local_190 = 1;
              strcpy(local_108,(char *)((longlong)local_158 + 0x240));
            }
            if (local_1a4 == 1) {
              if (local_1a8 == local_180 + -1) {
                param_3 = (double *)(local_160 * local_198[3]);
                FUN_180007f00(param_1,&DAT_1800275b0,param_3,param_4);
              }
              else {
                param_3 = (double *)(local_160 * local_198[3]);
                FUN_180007f00(param_1," %G /",param_3,param_4);
              }
              local_1a8 = local_1a8 + 1;
            }
            if ((1 < local_1a4) && (local_1a4 <= local_174)) {
              if (local_1a8 == local_180 + -1) {
                param_3 = (double *)(local_160 * local_198[3]);
                FUN_180007f00(param_1,&DAT_1800275b0,param_3,param_4);
              }
              else {
                param_3 = (double *)(local_160 * local_198[3]);
                FUN_180007f00(param_1,"  %G /",param_3,param_4);
              }
              local_1a8 = local_1a8 + 1;
            }
            local_1a4 = local_1a4 + 1;
            if (local_174 < local_1a4) {
              FUN_180007f00(param_1,"  \n            ",param_3,param_4);
              local_1a4 = 1;
            }
          }
        }
        local_170 = (undefined8 *)local_170[1];
      } while( true );
    }
    local_198 = (double *)*local_170;
    local_158 = local_198[2];
    local_140 = local_198[0xd];
    local_1a0 = 0;
    while ((&PTR_DAT_18002c8a0)[(longlong)local_1a0 * 3] != (undefined *)0x0) {
      local_128 = &PTR_DAT_18002c8a0;
      iVar1 = _stricmp((&PTR_DAT_18002c8a0)[(longlong)local_1a0 * 3],(char *)local_198);
      if (iVar1 == 0) break;
      local_1a0 = local_1a0 + 1;
    }
    if ((&PTR_DAT_18002c8a8)[(longlong)local_1a0 * 3] == (undefined *)0x0) {
      param_3 = local_198;
      FUN_1800220b0(1,"Property %s not supported by Aspen Plus",local_198,param_4);
    }
    else {
      local_120 = local_198 + 4;
      param_3 = &local_160;
      local_188 = (double *)
                  FUN_1800082f0((char *)local_120,
                                *(int *)(&DAT_18002c8b0 + (longlong)local_1a0 * 0x18),param_3);
      if (local_188 == (double *)0x0) {
        if (*(int *)(&DAT_18002c8b0 + (longlong)local_1a0 * 0x18) == 0) {
          param_3 = &local_160;
          FUN_180001a20((char *)(local_198 + 4),local_e8,param_3);
          iVar1 = strcmp(local_108,(char *)((longlong)local_158 + 0x240));
          if (iVar1 != 0) {
            local_190 = 0;
          }
          if (local_190 == 0) {
            local_1a4 = 1;
            if (local_168 != 0) {
              local_168 = 0;
              goto LAB_18000e348;
            }
            FUN_180007f00(param_1,"\n  PROP-LIST ",param_3,param_4);
            local_190 = 1;
            strcpy(local_108,(char *)((longlong)local_158 + 0x240));
            local_168 = 1;
          }
          if (local_1a4 == 1) {
            if (local_1a8 == local_180 + -1) {
              param_3 = (double *)(&PTR_DAT_18002c8a8)[(longlong)local_1a0 * 3];
              FUN_180007f00(param_1,"  %s ",param_3,param_4);
            }
            else {
              param_3 = (double *)(&PTR_DAT_18002c8a8)[(longlong)local_1a0 * 3];
              FUN_180007f00(param_1,"  %s /",param_3,param_4);
            }
            local_1a8 = local_1a8 + 1;
          }
          if ((1 < local_1a4) && (local_1a4 <= local_174)) {
            if (local_1a8 == local_180 + -1) {
              param_3 = (double *)(&PTR_DAT_18002c8a8)[(longlong)local_1a0 * 3];
              FUN_180007f00(param_1,"  %s ",param_3,param_4);
            }
            else {
              param_3 = (double *)(&PTR_DAT_18002c8a8)[(longlong)local_1a0 * 3];
              FUN_180007f00(param_1,"  %s /",param_3,param_4);
            }
            local_1a8 = local_1a8 + 1;
          }
          local_1a4 = local_1a4 + 1;
          if (local_174 < local_1a4) {
            FUN_180007f00(param_1,"  \n            ",param_3,param_4);
            local_1a4 = 1;
          }
        }
        else {
          param_3 = local_198 + 4;
          param_4 = local_198;
          FUN_1800220b0(1,"Unit <%s> for property <%s> not supported by Aspen Plus",param_3,
                        local_198);
        }
      }
      else if (local_188 != (double *)0x0) {
        iVar1 = strcmp(local_108,(char *)((longlong)local_158 + 0x240));
        if (iVar1 != 0) {
          local_190 = 0;
        }
        if (local_190 == 0) {
          if (local_168 != 0) {
            local_168 = 0;
            goto LAB_18000e348;
          }
          local_1a4 = 1;
          FUN_180007f00(param_1,"\n  PROP-LIST ",param_3,param_4);
          local_190 = 1;
          strcpy(local_108,(char *)((longlong)local_158 + 0x240));
          local_168 = 1;
        }
        if (local_1a4 == 1) {
          if (local_1a8 == local_180 + -1) {
            param_3 = (double *)(&PTR_DAT_18002c8a8)[(longlong)local_1a0 * 3];
            FUN_180007f00(param_1,"  %s ",param_3,param_4);
          }
          else {
            param_3 = (double *)(&PTR_DAT_18002c8a8)[(longlong)local_1a0 * 3];
            FUN_180007f00(param_1,"  %s /",param_3,param_4);
          }
          local_1a8 = local_1a8 + 1;
        }
        if ((1 < local_1a4) && (local_1a4 <= local_174)) {
          if (local_1a8 == local_180 + -1) {
            param_3 = (double *)(&PTR_DAT_18002c8a8)[(longlong)local_1a0 * 3];
            FUN_180007f00(param_1,"  %s ",param_3,param_4);
          }
          else {
            param_3 = (double *)(&PTR_DAT_18002c8a8)[(longlong)local_1a0 * 3];
            FUN_180007f00(param_1,"  %s /",param_3,param_4);
          }
          local_1a8 = local_1a8 + 1;
        }
        local_1a4 = local_1a4 + 1;
        if (local_174 < local_1a4) {
          FUN_180007f00(param_1,"  \n            ",param_3,param_4);
          local_1a4 = 1;
        }
      }
    }
    local_170 = (undefined8 *)local_170[1];
  } while( true );
}

/* RVA 0xe920, FUN_18000e920 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18000e920(undefined8 param_1,uint *param_2,double *param_3,double *param_4)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 auStack_218 [32];
  char *local_1f8;
  int local_1e8;
  int local_1e4;
  double *local_1e0;
  int local_1d8;
  int local_1d4;
  char *local_1d0;
  int local_1c8;
  undefined8 *local_1c0;
  double local_1b8;
  int local_1b0;
  undefined4 local_1ac;
  int local_1a8;
  int local_1a4;
  int local_1a0 [2];
  double local_198;
  int *local_190;
  uint local_188;
  double local_180;
  undefined4 local_178;
  undefined **local_170;
  double *local_168;
  undefined **local_160;
  double *local_158;
  double *local_150;
  undefined **local_148;
  double *local_140;
  double local_138;
  char local_130 [32];
  char local_110 [40];
  char local_e8 [208];
  ulonglong local_18;
  
  local_18 = DAT_180032178 ^ (ulonglong)auStack_218;
  local_1d0 = (char *)0x0;
  local_1c8 = 0;
  local_178 = 4;
  local_1ac = 1;
  local_1b0 = 0;
  local_1a4 = 0;
  local_1a0[0] = 0;
  local_1e4 = 0;
  FUN_180003ba0(&local_1a4,local_1a0,param_3,(char *)param_4);
  for (local_1d4 = 0; local_1d4 < 100; local_1d4 = local_1d4 + 1) {
    strcpy(&DAT_180034ba0 + (longlong)local_1d4 * 100,"");
  }
  strcpy(local_130,"");
  local_190 = FUN_180021a60(3);
  if (*(longlong *)(local_190 + 2) != 0) {
    *param_2 = *param_2 + 1;
    param_3 = (double *)(ulonglong)*param_2;
    FUN_180007f00(param_1,"? PROPERTIES PARAMETERS UNARY SCALAR \"PD-%d\" ?",param_3,param_4);
    FUN_180007f00(param_1," ; \"SI_MOLE\" ; ",param_3,param_4);
  }
  local_1a8 = 0;
  local_1d8 = 0;
  for (local_1c0 = *(undefined8 **)(local_190 + 2); local_1c0 != (undefined8 *)0x0;
      local_1c0 = (undefined8 *)local_1c0[1]) {
    local_1e0 = (double *)*local_1c0;
    local_1b8 = local_1e0[2];
    local_180 = local_1e0[0xd];
    local_1e8 = 0;
    while ((&PTR_DAT_18002c8a0)[(longlong)local_1e8 * 3] != (undefined *)0x0) {
      local_170 = &PTR_DAT_18002c8a0;
      iVar1 = _stricmp((&PTR_DAT_18002c8a0)[(longlong)local_1e8 * 3],(char *)local_1e0);
      if (iVar1 == 0) break;
      local_1e8 = local_1e8 + 1;
    }
    if ((&PTR_DAT_18002c8a8)[(longlong)local_1e8 * 3] == (undefined *)0x0) {
      param_3 = local_1e0;
      FUN_1800220b0(1,"Property %s not supported by Aspen Plus",local_1e0,param_4);
    }
    else {
      local_168 = local_1e0 + 4;
      param_3 = &local_198;
      local_1d0 = FUN_1800082f0((char *)local_168,
                                *(int *)(&DAT_18002c8b0 + (longlong)local_1e8 * 0x18),param_3);
      if (local_1d0 == (char *)0x0) {
        if (*(int *)(&DAT_18002c8b0 + (longlong)local_1e8 * 0x18) == 0) {
          param_3 = &local_198;
          FUN_180001a20((char *)(local_1e0 + 4),local_e8,param_3);
        }
        else {
          param_3 = local_1e0 + 4;
          param_4 = local_1e0;
          FUN_1800220b0(1,"Unit <%s> for property <%s> not supported by Aspen Plus",param_3,
                        local_1e0);
        }
      }
      else {
        iVar1 = strcmp(local_1d0,"DIPOLEMOMENT=\'(J/CUM)**.5\'");
        if (iVar1 == 0) {
          strcpy(local_1d0,"DIPOLEMOMENT=\'(J*CUM)**.5\'");
        }
        if (local_1a8 == 0) {
          if ((local_1d0 != (char *)0x0) &&
             (uVar2 = FUN_180003770(local_1d0,local_1c8), (int)uVar2 == 0)) {
            strcpy(&DAT_180034ba0 + (longlong)local_1c8 * 100,local_1d0);
            local_1c8 = local_1c8 + 1;
            local_1e4 = local_1e4 + 1;
          }
          local_1a8 = 1;
        }
        if (((local_1d0 != (char *)0x0) && (local_1a8 == 1)) &&
           (uVar2 = FUN_180003770(local_1d0,local_1c8), (int)uVar2 == 0)) {
          strcpy(&DAT_180034ba0 + (longlong)local_1c8 * 100,local_1d0);
          local_1c8 = local_1c8 + 1;
          local_1e4 = local_1e4 + 1;
        }
      }
    }
  }
  local_1e4 = 0;
  local_190 = FUN_180021a60(3);
  local_1c0 = *(undefined8 **)(local_190 + 2);
  do {
    if (local_1c0 == (undefined8 *)0x0) {
LAB_18000f16e:
      local_1e4 = 0;
      FUN_180007f00(param_1,&DAT_180027258,param_3,param_4);
      local_1ac = 1;
      strcpy(local_130,"");
      local_190 = FUN_180021a60(3);
      local_1c0 = *(undefined8 **)(local_190 + 2);
      do {
        if (local_1c0 == (undefined8 *)0x0) {
          FUN_180007f00(param_1,&DAT_180027468,param_3,param_4);
          strcpy(local_130,"");
          for (local_1d4 = 0; local_1d4 < 100; local_1d4 = local_1d4 + 1) {
            strcpy(&DAT_180034ba0 + (longlong)local_1d4 * 100,"");
          }
          return;
        }
        local_1e0 = (double *)*local_1c0;
        local_1b8 = local_1e0[2];
        local_180 = local_1e0[0xd];
        local_1e8 = 0;
        while ((&PTR_DAT_18002c8a0)[(longlong)local_1e8 * 3] != (undefined *)0x0) {
          local_148 = &PTR_DAT_18002c8a0;
          iVar1 = _stricmp((&PTR_DAT_18002c8a0)[(longlong)local_1e8 * 3],(char *)local_1e0);
          if (iVar1 == 0) break;
          local_1e8 = local_1e8 + 1;
        }
        if ((&PTR_DAT_18002c8a8)[(longlong)local_1e8 * 3] == (undefined *)0x0) {
          param_3 = local_1e0;
          FUN_1800220b0(1,"Property %s not supported by Aspen Plus",local_1e0,param_4);
        }
        else {
          local_140 = local_1e0 + 4;
          param_3 = &local_198;
          local_1d0 = FUN_1800082f0((char *)local_140,
                                    *(int *)(&DAT_18002c8b0 + (longlong)local_1e8 * 0x18),param_3);
          if (local_1d0 == (char *)0x0) {
            if (*(int *)(&DAT_18002c8b0 + (longlong)local_1e8 * 0x18) == 0) {
              FUN_180001a20((char *)(local_1e0 + 4),local_e8,&local_198);
              iVar1 = strcmp(local_130,(char *)((longlong)local_1b8 + 0x240));
              if (iVar1 != 0) {
                local_1d8 = 0;
              }
              if (local_1d8 == 0) {
                local_1ac = 1;
                local_1e4 = 0;
                local_1d8 = 1;
                strcpy(local_130,(char *)((longlong)local_1b8 + 0x240));
              }
              _strupr((char *)((longlong)local_1b8 + 0x240));
              local_1f8 = (char *)(local_1e0[3] * local_198);
              param_4 = (double *)((longlong)local_1b8 + 0x240);
              param_3 = (double *)(&PTR_DAT_18002c8a8)[(longlong)local_1e8 * 3];
              FUN_180007f00(param_1,"\\ PVAL  PARAMNAME2 = %s CID = %s UVALUE = %G <0> <0> \\ \n",
                            param_3,param_4);
            }
            else {
              param_3 = local_1e0 + 4;
              param_4 = local_1e0;
              FUN_1800220b0(1,"Unit <%s> for property <%s> not supported by Aspen Plus",param_3,
                            local_1e0);
            }
          }
          else if (local_1d0 != (char *)0x0) {
            iVar1 = strcmp(local_130,(char *)((longlong)local_1b8 + 0x240));
            if (iVar1 != 0) {
              local_1d8 = 0;
            }
            if (local_1d8 == 0) {
              local_1ac = 1;
              local_1e4 = 0;
              local_1d8 = 1;
              strcpy(local_130,(char *)((longlong)local_1b8 + 0x240));
            }
            _strupr((char *)((longlong)local_1b8 + 0x240));
            local_1f8 = (char *)(local_1e0[3] * local_198);
            param_4 = (double *)((longlong)local_1b8 + 0x240);
            param_3 = (double *)(&PTR_DAT_18002c8a8)[(longlong)local_1e8 * 3];
            FUN_180007f00(param_1,"\\ PVAL  PARAMNAME2 = %s CID = %s UVALUE = %G <0> <0> \\ \n",
                          param_3,param_4);
          }
        }
        local_1c0 = (undefined8 *)local_1c0[1];
      } while( true );
    }
    local_1e0 = (double *)*local_1c0;
    local_1b8 = local_1e0[2];
    local_180 = local_1e0[0xd];
    local_1e8 = 0;
    while ((&PTR_DAT_18002c8a0)[(longlong)local_1e8 * 3] != (undefined *)0x0) {
      local_160 = &PTR_DAT_18002c8a0;
      iVar1 = _stricmp((&PTR_DAT_18002c8a0)[(longlong)local_1e8 * 3],(char *)local_1e0);
      if (iVar1 == 0) break;
      local_1e8 = local_1e8 + 1;
    }
    if ((&PTR_DAT_18002c8a8)[(longlong)local_1e8 * 3] == (undefined *)0x0) {
      param_3 = local_1e0;
      FUN_1800220b0(1,"Property %s not supported by Aspen Plus",local_1e0,param_4);
    }
    else {
      local_158 = local_1e0 + 4;
      param_3 = &local_198;
      local_1d0 = FUN_1800082f0((char *)local_158,
                                *(int *)(&DAT_18002c8b0 + (longlong)local_1e8 * 0x18),param_3);
      if (local_1d0 == (char *)0x0) {
        if (*(int *)(&DAT_18002c8b0 + (longlong)local_1e8 * 0x18) == 0) {
          param_3 = &local_198;
          FUN_180001a20((char *)(local_1e0 + 4),local_e8,param_3);
          iVar1 = strcmp(local_130,(char *)((longlong)local_1b8 + 0x240));
          if (iVar1 != 0) {
            local_1d8 = 0;
          }
          if (local_1d8 == 0) {
            local_1ac = 1;
            if (local_1b0 != 0) {
              local_1b0 = 0;
              goto LAB_18000f16e;
            }
            FUN_180007f00(param_1," \\ PROP-LIST \n",param_3,param_4);
            local_1d8 = 1;
            strcpy(local_130,(char *)((longlong)local_1b8 + 0x240));
            local_1b0 = 1;
          }
          if (local_1e4 == local_1a0[0] + -1) {
            param_3 = (double *)(&PTR_DAT_18002c8a8)[(longlong)local_1e8 * 3];
            FUN_180007f00(param_1," PARAMNAME = %s SETNO = 1 UNITROW = 0 \\ \n",param_3,param_4);
          }
          else {
            param_3 = (double *)(&PTR_DAT_18002c8a8)[(longlong)local_1e8 * 3];
            FUN_180007f00(param_1," PARAMNAME = %s SETNO = 1 UNITROW = 0 / \n",param_3,param_4);
          }
          local_1e4 = local_1e4 + 1;
        }
        else {
          param_3 = local_1e0 + 4;
          param_4 = local_1e0;
          FUN_1800220b0(1,"Unit <%s> for property <%s> not supported by Aspen Plus",param_3,
                        local_1e0);
        }
      }
      else if (local_1d0 != (char *)0x0) {
        iVar1 = strcmp(local_1d0,"DIPOLEMOMENT=\'(J/CUM)**.5\'");
        if (iVar1 == 0) {
          strcpy(local_1d0,"DIPOLEMOMENT=\'(J*CUM)**.5\'");
        }
        iVar1 = strcmp(local_130,(char *)((longlong)local_1b8 + 0x240));
        if (iVar1 != 0) {
          local_1d8 = 0;
        }
        if (local_1d8 == 0) {
          if (local_1b0 != 0) {
            local_1b0 = 0;
            goto LAB_18000f16e;
          }
          local_1ac = 1;
          FUN_180007f00(param_1," \\ PROP-LIST \n",param_3,param_4);
          local_1d8 = 1;
          strcpy(local_130,(char *)((longlong)local_1b8 + 0x240));
          local_1b0 = 1;
        }
        strcpy(local_110,"");
        FUN_1800043c0(local_1d0,(longlong)local_110);
        local_150 = local_1e0 + 4;
        local_188 = FUN_180008670((char *)local_150,
                                  *(int *)(&DAT_18002c8b0 + (longlong)local_1e8 * 0x18),&local_138);
        if (local_1e4 == local_1a0[0] + -1) {
          local_1f8 = local_110;
          param_4 = (double *)(ulonglong)local_188;
          param_3 = (double *)(&PTR_DAT_18002c8a8)[(longlong)local_1e8 * 3];
          FUN_180007f00(param_1," PARAMNAME = %s SETNO = 1 UNITROW = %d UNITLABEL = %s \\ \n",
                        param_3,param_4);
        }
        else {
          local_1f8 = local_110;
          param_4 = (double *)(ulonglong)local_188;
          param_3 = (double *)(&PTR_DAT_18002c8a8)[(longlong)local_1e8 * 3];
          FUN_180007f00(param_1," PARAMNAME = %s SETNO = 1 UNITROW = %d UNITLABEL = %s / \n",param_3
                        ,param_4);
        }
        local_1e4 = local_1e4 + 1;
      }
    }
    local_1c0 = (undefined8 *)local_1c0[1];
  } while( true );
}

/* RVA 0xf580, FUN_18000f580 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18000f580(undefined8 param_1,uint *param_2,undefined *param_3,undefined8 param_4)

{
  int iVar1;
  undefined1 auStack_c8 [32];
  int local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  int local_98 [2];
  char *local_90;
  int local_88;
  longlong *local_80;
  int local_78;
  longlong local_70;
  int *local_68;
  undefined4 local_60;
  undefined **local_58;
  undefined **local_50;
  undefined **local_48;
  undefined **local_40;
  char local_38 [32];
  ulonglong local_18;
  
  local_18 = DAT_180032178 ^ (ulonglong)auStack_c8;
  local_60 = 0;
  local_88 = 4;
  local_a4 = 1;
  local_78 = 0;
  local_98[0] = 0;
  local_a0 = 0;
  FUN_180003980(local_98);
  strcpy(local_38,"");
  local_68 = FUN_180021a60(4);
  if (*(longlong *)(local_68 + 2) != 0) {
    *param_2 = *param_2 + 1;
    param_3 = (undefined *)(ulonglong)*param_2;
    FUN_180007f00(param_1,"PROP-DATA P-%d\n",param_3,param_4);
  }
  local_9c = 0;
  local_80 = *(longlong **)(local_68 + 2);
  do {
    if (local_80 == (longlong *)0x0) {
LAB_18000f8ef:
      FUN_180007f00(param_1,&DAT_180027258,param_3,param_4);
      strcpy(local_38,"");
      local_68 = FUN_180021a60(4);
      local_9c = 0;
      local_a4 = 1;
      local_a0 = 0;
      local_80 = *(longlong **)(local_68 + 2);
      do {
        if (local_80 == (longlong *)0x0) {
          FUN_180007f00(param_1,&DAT_180027468,param_3,param_4);
          return;
        }
        local_90 = (char *)*local_80;
        local_70 = *(longlong *)(local_90 + 0x20);
        local_a8 = 0;
        while ((&PTR_s_UNIQUAC_18002e410)[(longlong)local_a8 * 3] != (undefined *)0x0) {
          local_48 = &PTR_s_UNIQUAC_18002e410;
          iVar1 = _stricmp((&PTR_s_UNIQUAC_18002e410)[(longlong)local_a8 * 3],local_90);
          if (iVar1 == 0) {
            local_40 = &PTR_s_UNIQUAC_18002e410;
            iVar1 = _stricmp((&PTR_DAT_18002e418)[(longlong)local_a8 * 3],local_90 + 0xd);
            if (iVar1 == 0) break;
          }
          local_a8 = local_a8 + 1;
        }
        if ((&PTR_s_GMUQR_18002e420)[(longlong)local_a8 * 3] != (undefined *)0x0) {
          iVar1 = strcmp(local_38,(char *)(local_70 + 0x240));
          if (iVar1 != 0) {
            local_9c = 0;
          }
          if (local_9c == 0) {
            local_a4 = 1;
            param_3 = (undefined *)(local_70 + 0x240);
            FUN_180007f00(param_1,"\n  PVAL % 5s",param_3,param_4);
            local_9c = 1;
            strcpy(local_38,(char *)(local_70 + 0x240));
            local_a0 = 0;
          }
          if (local_a4 == 1) {
            if (local_a0 == local_98[0] + -1) {
              param_3 = *(undefined **)(local_90 + 0x28);
              FUN_180007f00(param_1,"  %G ",param_3,param_4);
            }
            else {
              param_3 = *(undefined **)(local_90 + 0x28);
              FUN_180007f00(param_1,"  %G /",param_3,param_4);
            }
            local_a0 = local_a0 + 1;
          }
          if ((1 < local_a4) && (local_a4 <= local_88)) {
            if (local_a0 == local_98[0] + -1) {
              param_3 = *(undefined **)(local_90 + 0x28);
              FUN_180007f00(param_1,"  %G ",param_3,param_4);
            }
            else {
              param_3 = *(undefined **)(local_90 + 0x28);
              FUN_180007f00(param_1,"  %G /",param_3,param_4);
            }
            local_a0 = local_a0 + 1;
          }
          local_a4 = local_a4 + 1;
          if (local_88 < local_a4) {
            param_3 = (undefined *)(local_70 + 0x240);
            FUN_180007f00(param_1,"\n  PVAL % 5s",param_3,param_4);
            local_a4 = 1;
          }
        }
        local_80 = (longlong *)local_80[1];
      } while( true );
    }
    local_90 = (char *)*local_80;
    local_70 = *(longlong *)(local_90 + 0x20);
    local_a8 = 0;
    while ((&PTR_s_UNIQUAC_18002e410)[(longlong)local_a8 * 3] != (undefined *)0x0) {
      local_58 = &PTR_s_UNIQUAC_18002e410;
      iVar1 = _stricmp((&PTR_s_UNIQUAC_18002e410)[(longlong)local_a8 * 3],local_90);
      if (iVar1 == 0) {
        local_50 = &PTR_s_UNIQUAC_18002e410;
        iVar1 = _stricmp((&PTR_DAT_18002e418)[(longlong)local_a8 * 3],local_90 + 0xd);
        if (iVar1 == 0) break;
      }
      local_a8 = local_a8 + 1;
    }
    if ((&PTR_s_GMUQR_18002e420)[(longlong)local_a8 * 3] != (undefined *)0x0) {
      iVar1 = strcmp(local_38,(char *)(local_70 + 0x240));
      if (iVar1 != 0) {
        local_9c = 0;
      }
      if (local_9c == 0) {
        if (local_78 != 0) {
          local_78 = 0;
          goto LAB_18000f8ef;
        }
        local_a0 = 0;
        local_a4 = 1;
        FUN_180007f00(param_1,"\n  PROP-LIST ",param_3,param_4);
        local_9c = 1;
        strcpy(local_38,(char *)(local_70 + 0x240));
        local_78 = 1;
      }
      if (local_a4 == 1) {
        if (local_a0 == local_98[0] + -1) {
          param_3 = (&PTR_s_GMUQR_18002e420)[(longlong)local_a8 * 3];
          FUN_180007f00(param_1,"  %s ",param_3,param_4);
        }
        else {
          param_3 = (&PTR_s_GMUQR_18002e420)[(longlong)local_a8 * 3];
          FUN_180007f00(param_1,"  %s /",param_3,param_4);
        }
        local_a0 = local_a0 + 1;
      }
      if ((1 < local_a4) && (local_a4 <= local_88)) {
        if (local_a0 == local_98[0] + -1) {
          param_3 = (&PTR_s_GMUQR_18002e420)[(longlong)local_a8 * 3];
          FUN_180007f00(param_1,"  %s ",param_3,param_4);
        }
        else {
          param_3 = (&PTR_s_GMUQR_18002e420)[(longlong)local_a8 * 3];
          FUN_180007f00(param_1,"  %s /",param_3,param_4);
        }
        local_a0 = local_a0 + 1;
      }
      local_a4 = local_a4 + 1;
      if (local_88 < local_a4) {
        FUN_180007f00(param_1," & \n            ",param_3,param_4);
        local_a4 = 1;
      }
    }
    local_80 = (longlong *)local_80[1];
  } while( true );
}

/* RVA 0xfc10, FUN_18000fc10 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18000fc10(undefined8 param_1,uint *param_2,undefined *param_3,longlong param_4)

{
  int iVar1;
  undefined1 auStack_d8 [32];
  undefined8 local_b8;
  int local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  int local_98 [2];
  longlong local_90;
  char *local_88;
  int local_80;
  longlong *local_78;
  int local_70;
  int *local_68;
  undefined4 local_60;
  undefined **local_58;
  undefined **local_50;
  undefined **local_48;
  undefined **local_40;
  char local_38 [32];
  ulonglong local_18;
  
  local_18 = DAT_180032178 ^ (ulonglong)auStack_d8;
  local_60 = 0;
  local_80 = 4;
  local_a4 = 1;
  local_70 = 0;
  local_98[0] = 0;
  local_a0 = 0;
  FUN_180003980(local_98);
  strcpy(local_38,"");
  local_68 = FUN_180021a60(4);
  if (*(longlong *)(local_68 + 2) != 0) {
    *param_2 = *param_2 + 1;
    param_3 = (undefined *)(ulonglong)*param_2;
    FUN_180007f00(param_1,"? PROPERTIES PARAMETERS UNARY SCALAR \"P-%d\" ? ",param_3,param_4);
    FUN_180007f00(param_1," ; \"SI_MOLE\" ; \n",param_3,param_4);
  }
  local_9c = 0;
  local_78 = *(longlong **)(local_68 + 2);
  do {
    if (local_78 == (longlong *)0x0) {
LAB_18000ff8f:
      strcpy(local_38,"");
      local_68 = FUN_180021a60(4);
      local_9c = 0;
      local_a4 = 1;
      local_a0 = 0;
      local_78 = *(longlong **)(local_68 + 2);
      do {
        if (local_78 == (longlong *)0x0) {
          FUN_180007f00(param_1,&DAT_180027468,param_3,param_4);
          return;
        }
        local_88 = (char *)*local_78;
        local_90 = *(longlong *)(local_88 + 0x20);
        local_a8 = 0;
        while ((&PTR_s_UNIQUAC_18002e410)[(longlong)local_a8 * 3] != (undefined *)0x0) {
          local_48 = &PTR_s_UNIQUAC_18002e410;
          iVar1 = _stricmp((&PTR_s_UNIQUAC_18002e410)[(longlong)local_a8 * 3],local_88);
          if (iVar1 == 0) {
            local_40 = &PTR_s_UNIQUAC_18002e410;
            iVar1 = _stricmp((&PTR_DAT_18002e418)[(longlong)local_a8 * 3],local_88 + 0xd);
            if (iVar1 == 0) break;
          }
          local_a8 = local_a8 + 1;
        }
        if ((&PTR_s_GMUQR_18002e420)[(longlong)local_a8 * 3] != (undefined *)0x0) {
          iVar1 = strcmp(local_38,(char *)(local_90 + 0x240));
          if (iVar1 != 0) {
            local_9c = 0;
          }
          if (local_9c == 0) {
            local_a4 = 1;
            local_9c = 1;
            strcpy(local_38,(char *)(local_90 + 0x240));
            local_a0 = 0;
          }
          if (local_a4 == 1) {
            _strupr((char *)(local_90 + 0x240));
            if (local_a0 == local_98[0] + -1) {
              param_4 = local_90 + 0x240;
              local_b8 = *(undefined8 *)(local_88 + 0x28);
              param_3 = (&PTR_s_GMUQR_18002e420)[(longlong)local_a8 * 3];
              FUN_180007f00(param_1,"\\ PVAL PARAMNAME2 = %s CID = %s UVALUE = %G <0> <0> \\ \n",
                            param_3,param_4);
            }
            else {
              param_4 = local_90 + 0x240;
              local_b8 = *(undefined8 *)(local_88 + 0x28);
              param_3 = (&PTR_s_GMUQR_18002e420)[(longlong)local_a8 * 3];
              FUN_180007f00(param_1,"\\ PVAL PARAMNAME2 = %s CID = %s UVALUE = %G <0> <0> \\ \n",
                            param_3,param_4);
            }
            local_a0 = local_a0 + 1;
          }
          if ((1 < local_a4) && (local_a4 <= local_80)) {
            _strupr((char *)(local_90 + 0x240));
            if (local_a0 == local_98[0] + -1) {
              param_4 = local_90 + 0x240;
              local_b8 = *(undefined8 *)(local_88 + 0x28);
              param_3 = (&PTR_s_GMUQR_18002e420)[(longlong)local_a8 * 3];
              FUN_180007f00(param_1,"\\ PVAL PARAMNAME2 = %s CID = %s UVALUE = %G <0> <0> \\ \n",
                            param_3,param_4);
            }
            else {
              param_4 = local_90 + 0x240;
              local_b8 = *(undefined8 *)(local_88 + 0x28);
              param_3 = (&PTR_s_GMUQR_18002e420)[(longlong)local_a8 * 3];
              FUN_180007f00(param_1,"\\ PVAL PARAMNAME2 = %s CID = %s UVALUE = %G <0> <0> \\ \n",
                            param_3,param_4);
            }
            local_a0 = local_a0 + 1;
          }
          local_a4 = local_a4 + 1;
          if (local_80 < local_a4) {
            local_a4 = 1;
          }
        }
        local_78 = (longlong *)local_78[1];
      } while( true );
    }
    local_88 = (char *)*local_78;
    local_90 = *(longlong *)(local_88 + 0x20);
    local_a8 = 0;
    while ((&PTR_s_UNIQUAC_18002e410)[(longlong)local_a8 * 3] != (undefined *)0x0) {
      local_58 = &PTR_s_UNIQUAC_18002e410;
      iVar1 = _stricmp((&PTR_s_UNIQUAC_18002e410)[(longlong)local_a8 * 3],local_88);
      if (iVar1 == 0) {
        local_50 = &PTR_s_UNIQUAC_18002e410;
        iVar1 = _stricmp((&PTR_DAT_18002e418)[(longlong)local_a8 * 3],local_88 + 0xd);
        if (iVar1 == 0) break;
      }
      local_a8 = local_a8 + 1;
    }
    if ((&PTR_s_GMUQR_18002e420)[(longlong)local_a8 * 3] != (undefined *)0x0) {
      iVar1 = strcmp(local_38,(char *)(local_90 + 0x240));
      if (iVar1 != 0) {
        local_9c = 0;
      }
      if (local_9c == 0) {
        if (local_70 != 0) {
          local_70 = 0;
          goto LAB_18000ff8f;
        }
        local_a0 = 0;
        local_a4 = 1;
        FUN_180007f00(param_1,"\\ PROP-LIST ",param_3,param_4);
        local_9c = 1;
        strcpy(local_38,(char *)(local_90 + 0x240));
        local_70 = 1;
      }
      if (local_a4 == 1) {
        if (local_a0 == local_98[0] + -1) {
          param_3 = (&PTR_s_GMUQR_18002e420)[(longlong)local_a8 * 3];
          FUN_180007f00(param_1,"PARAMNAME = %s SETNO = 1 \\ \n",param_3,param_4);
        }
        else {
          param_3 = (&PTR_s_GMUQR_18002e420)[(longlong)local_a8 * 3];
          FUN_180007f00(param_1,"PARAMNAME = %s SETNO = 1 /\n",param_3,param_4);
        }
        local_a0 = local_a0 + 1;
      }
      if ((1 < local_a4) && (local_a4 <= local_80)) {
        if (local_a0 == local_98[0] + -1) {
          param_3 = (&PTR_s_GMUQR_18002e420)[(longlong)local_a8 * 3];
          FUN_180007f00(param_1,"PARAMNAME = %s SETNO = 1 \\ \n",param_3,param_4);
        }
        else {
          param_3 = (&PTR_s_GMUQR_18002e420)[(longlong)local_a8 * 3];
          FUN_180007f00(param_1,"PARAMNAME = %s SETNO = 1 /\n",param_3,param_4);
        }
        local_a0 = local_a0 + 1;
      }
      local_a4 = local_a4 + 1;
      if (local_80 < local_a4) {
        local_a4 = 1;
      }
    }
    local_78 = (longlong *)local_78[1];
  } while( true );
}

