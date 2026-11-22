/* RVA 0x1b0b0, FUN_18001b0b0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18001b0b0(undefined8 param_1,uint *param_2,double *param_3,double *param_4)

{
  int iVar1;
  size_t sVar2;
  double *pdVar3;
  ulonglong uVar4;
  undefined *puVar5;
  undefined1 auStack_2a8 [32];
  double *local_288;
  int local_280;
  int local_27c;
  int local_278;
  int local_274;
  int local_270;
  longlong *local_268;
  int local_260;
  double *local_258;
  double *local_250;
  double *local_248;
  int local_240;
  int local_23c;
  int local_238;
  int local_234;
  uint local_230;
  undefined1 local_22c [12];
  double *local_220;
  int local_218;
  int local_214;
  int local_210;
  longlong *local_208;
  double local_200;
  double local_1f8;
  double local_1f0;
  int local_1e8;
  undefined *local_1e0;
  undefined *local_1d8;
  longlong local_1d0;
  undefined *local_1c8;
  double local_1c0;
  double local_1b8;
  double local_1b0;
  double local_1a8;
  int *local_1a0;
  longlong local_198;
  double local_190;
  double local_188 [2];
  char local_178 [96];
  double local_118 [32];
  ulonglong local_18;
  
  local_18 = DAT_180032178 ^ (ulonglong)auStack_2a8;
  pdVar3 = param_3;
  local_1a0 = FUN_180021a60(5);
  local_208 = *(longlong **)(local_1a0 + 2);
  do {
    if (local_208 == (longlong *)0x0) {
      return;
    }
    local_268 = (longlong *)*local_208;
    if ((local_268[3] != 0) &&
       ((local_268[3] == 0 || (iVar1 = _stricmp((char *)local_268[3],""), iVar1 != 0)))) {
      local_198 = local_268[1];
      local_1d0 = *local_268;
      local_278 = -1;
      local_274 = -1;
      local_260 = -1;
      if (local_268[6] == 0) {
        local_240 = -1;
      }
      else {
        local_240 = 1;
      }
      local_214 = 0;
      local_218 = 0;
      local_210 = 0;
      local_280 = 1;
      local_258 = (double *)local_268[3];
      local_250 = (double *)local_268[5];
      for (; local_280 <= (short)local_268[2]; local_280 = local_280 + 1) {
        local_27c = 0;
        while (((&PTR_DAT_18002e640)[(longlong)local_27c * 3] != (undefined *)0x0 &&
               (iVar1 = _stricmp((&PTR_DAT_18002e640)[(longlong)local_27c * 3],(char *)local_258),
               iVar1 != 0))) {
          local_27c = local_27c + 1;
        }
        if (((&PTR_DAT_18002e648)[(longlong)local_27c * 3] == (undefined *)0x0) ||
           (*(&PTR_DAT_18002e648)[(longlong)local_27c * 3] != 'T')) {
          if (((&PTR_DAT_18002e648)[(longlong)local_27c * 3] != (undefined *)0x0) &&
             (*(&PTR_DAT_18002e648)[(longlong)local_27c * 3] == 'P')) {
            local_274 = local_280;
            local_218 = local_218 + 1;
            pdVar3 = local_188;
            local_1d8 = FUN_1800082f0((char *)local_250,0x16,pdVar3);
            if (local_1d8 == (undefined *)0x0) {
              pdVar3 = local_250;
              param_4 = local_258;
              FUN_1800220b0(1,"Unit <%s> for property <%s> not supported by Aspen Plus",local_250,
                            local_258);
              local_274 = -1;
            }
            if (local_240 == 1) {
              local_248 = (double *)((longlong)(local_280 + -1) * 0x14 + local_268[6]);
              if (*(char *)local_248 == '%') {
                local_238 = 1;
              }
              else if (*(char *)local_248 == '$') {
                local_238 = -1;
              }
              else {
                iVar1 = strcmp((char *)local_248,(char *)local_250);
                if (iVar1 == 0) {
                  local_238 = 2;
                }
                else {
                  pdVar3 = local_248;
                  param_4 = local_258;
                  FUN_1800220b0(0,"ERR-UNIT <%s> for property <%s> differs from UNIT",local_248,
                                local_258);
                  local_238 = -1;
                }
              }
            }
          }
        }
        else {
          local_278 = local_280;
          local_214 = local_214 + 1;
          pdVar3 = &local_190;
          local_1e0 = FUN_1800082f0((char *)local_250,0x19,pdVar3);
          if (local_1e0 == (undefined *)0x0) {
            pdVar3 = local_250;
            param_4 = local_258;
            FUN_1800220b0(1,"Unit <%s> for property <%s> not supported by Aspen Plus",local_250,
                          local_258);
            local_278 = -1;
          }
          if (local_240 == 1) {
            local_248 = (double *)((longlong)(local_280 + -1) * 0x14 + local_268[6]);
            if (*(char *)local_248 == '%') {
              local_23c = 1;
            }
            else if (*(char *)local_248 == '$') {
              local_23c = -1;
            }
            else {
              iVar1 = strcmp((char *)local_248,(char *)local_250);
              if (iVar1 == 0) {
                local_23c = 2;
              }
              else {
                pdVar3 = local_248;
                param_4 = local_258;
                FUN_1800220b0(0,"ERR-UNIT <%s> for property <%s> differs from UNIT",local_248,
                              local_258);
                local_23c = -1;
              }
            }
          }
        }
        local_258 = (double *)((longlong)local_258 + 0xd);
        local_250 = (double *)((longlong)local_250 + 0x14);
      }
      if ((local_278 == -1) || (local_274 == -1)) {
        if ((local_278 == -1) || (local_274 != -1)) {
          if ((local_278 != -1) || (local_274 == -1)) {
            FUN_1800220b0(0,"Neither T nor P given in TABLE - no DATA GROUP written",pdVar3,param_4)
            ;
            goto LAB_18001b100;
          }
          strcpy(local_22c,"P");
        }
        else {
          strcpy(local_22c,"T");
        }
      }
      else {
        strcpy(local_22c,"TP");
      }
      local_280 = 1;
      local_258 = (double *)local_268[3];
      local_250 = (double *)local_268[5];
      for (; local_280 <= (short)local_268[2]; local_280 = local_280 + 1) {
        if ((local_280 == 1) && (local_214 + local_218 == (int)(short)local_268[2])) {
          local_210 = 1;
        }
        if (local_210 == 1) {
          local_210 = 0;
LAB_18001b886:
          FUN_18001ddb0();
          *param_2 = *param_2 + 1;
          uVar4 = (ulonglong)*param_2;
          FUN_180007f00(param_1,"DATA-GROUP DG-%d\n",uVar4,param_4);
          FUN_180007f00(param_1,"  IN-UNITS SI ",uVar4,param_4);
          if ((local_278 < 1) || (local_274 < 1)) {
            if ((local_278 < 1) || (-1 < local_274)) {
              if ((local_278 < 0) && (0 < local_274)) {
                FUN_180007f00(param_1,"%s &\n",local_1d8,param_4);
              }
            }
            else {
              FUN_180007f00(param_1,"%s &\n",local_1e0,param_4);
            }
          }
          else {
            FUN_180007f00(param_1,"%s &\n",local_1e0,param_4);
            FUN_180007f00(param_1,"              %s &\n",local_1d8,param_4);
          }
          if (0 < local_260) {
            FUN_180007f00(param_1,"              %s\n",local_1c8,param_4);
          }
          if (local_1d0 != 0) {
            FUN_180007f00(param_1,"  DESCRIPTION \"Source-Key: %s\"\n",local_1d0,param_4);
          }
          param_4 = (double *)(local_198 + 0x240);
          pdVar3 = (double *)local_22c;
          FUN_180007f00(param_1,"  SYSTEM-DEF %s %s ",pdVar3,param_4);
          if (0 < local_260) {
            pdVar3 = *(double **)(local_22c._4_8_ + 8);
            FUN_180007f00(param_1,"PROP-LIST=%s",pdVar3,param_4);
          }
          FUN_180007f00(param_1,&DAT_180027258,pdVar3,param_4);
          local_27c = 0;
          local_220 = (double *)local_268[7];
          local_270 = 1;
          local_230 = 1;
          for (; local_27c < (int)(short)local_268[2] * (int)*(short *)((longlong)local_268 + 0x42);
              local_27c = local_27c + 1) {
            if (((local_270 == local_278) || (local_270 == local_274)) || (local_270 == local_260))
            {
              if (local_270 == local_278) {
                local_1c0 = *local_220;
                local_200 = local_220[1];
              }
              if (local_270 == local_274) {
                local_1b8 = *local_220;
                local_1f8 = local_220[1];
              }
              if (local_270 == local_260) {
                local_1b0 = *local_220;
                local_1f0 = local_220[1];
              }
              if (local_270 == (short)local_268[2]) {
                if (local_240 == 1) {
                  local_288 = local_118;
                  if (local_278 != -1) {
                    if ((local_23c == 1) && (local_200 != DAT_180029478)) {
                      FUN_180002d90(local_288," -%-10G",local_200,param_4);
                    }
                    else if ((local_23c == 2) && (local_200 != DAT_180029478)) {
                      FUN_180002d90(local_288," %-11G",local_200,param_4);
                    }
                    else {
                      FUN_180002d90(local_288," %-11s",&DAT_180028740,param_4);
                    }
                    sVar2 = strlen((char *)local_288);
                    local_288 = (double *)((longlong)local_288 + (longlong)(int)sVar2);
                  }
                  if (local_274 != -1) {
                    if ((local_238 == 1) && (local_1f8 != DAT_180029478)) {
                      FUN_180002d90(local_288," -%-10G",local_1f8,param_4);
                    }
                    else if ((local_238 == 2) && (local_1f8 != DAT_180029478)) {
                      FUN_180002d90(local_288," %-11G",local_1f8,param_4);
                    }
                    else {
                      FUN_180002d90(local_288," %-11s",&DAT_180028740,param_4);
                    }
                    sVar2 = strlen((char *)local_288);
                    local_288 = (double *)((longlong)local_288 + (longlong)(int)sVar2);
                  }
                  if (local_260 != -1) {
                    if ((local_234 == 1) && (local_1f0 != DAT_180029478)) {
                      FUN_180002d90(local_288," -%-10G",local_1f0,param_4);
                    }
                    else if ((local_234 == 2) && (local_1f0 != DAT_180029478)) {
                      FUN_180002d90(local_288," %-11G",local_1f0,param_4);
                    }
                    else {
                      FUN_180002d90(local_288," %-11s",&DAT_180028740,param_4);
                    }
                    sVar2 = strlen((char *)local_288);
                    local_288 = (double *)((longlong)local_288 + (longlong)(int)sVar2);
                  }
                  if ((local_230 == 1) || (iVar1 = strcmp(local_178,(char *)local_118), iVar1 != 0))
                  {
                    param_4 = local_118;
                    FUN_180007f00(param_1,"  STD-DEV %2i%s\n",(ulonglong)local_230,param_4);
                    strcpy(local_178,(char *)local_118);
                  }
                }
                local_288 = local_118;
                puVar5 = (undefined *)(ulonglong)local_230;
                FUN_180002d90(local_288,"  DATA    %2i",puVar5,param_4);
                sVar2 = strlen((char *)local_288);
                local_288 = (double *)((longlong)local_288 + (longlong)(int)sVar2);
                if (local_278 != -1) {
                  if (local_1c0 == DAT_180029478) {
                    puVar5 = &DAT_180028740;
                    FUN_180002d90(local_288," %-11s",&DAT_180028740,param_4);
                  }
                  else {
                    puVar5 = (undefined *)(local_1c0 * local_190);
                    FUN_180002d90(local_288," %-11G",puVar5,param_4);
                  }
                  sVar2 = strlen((char *)local_288);
                  local_288 = (double *)((longlong)local_288 + (longlong)(int)sVar2);
                }
                if (local_274 != -1) {
                  if (local_1b8 == DAT_180029478) {
                    puVar5 = &DAT_180028740;
                    FUN_180002d90(local_288," %-11s",&DAT_180028740,param_4);
                  }
                  else {
                    puVar5 = (undefined *)(local_1b8 * local_188[0]);
                    FUN_180002d90(local_288," %-11G",puVar5,param_4);
                  }
                  sVar2 = strlen((char *)local_288);
                  local_288 = (double *)((longlong)local_288 + (longlong)(int)sVar2);
                }
                if (local_260 != -1) {
                  if (local_1b0 == DAT_180029478) {
                    puVar5 = &DAT_180028740;
                    FUN_180002d90(local_288," %-11s",&DAT_180028740,param_4);
                  }
                  else {
                    puVar5 = (undefined *)(local_1b0 * local_1a8);
                    FUN_180002d90(local_288," %-11G",puVar5,param_4);
                  }
                  sVar2 = strlen((char *)local_288);
                  local_288 = (double *)((longlong)local_288 + (longlong)(int)sVar2);
                }
                FUN_180002d90(local_288,&DAT_180027258,puVar5,param_4);
                pdVar3 = local_118;
                FUN_180007f00(param_1,&DAT_180026538,pdVar3,param_4);
                local_270 = 0;
                local_230 = local_230 + 1;
              }
            }
            local_220 = local_220 + 2;
            local_270 = local_270 + 1;
          }
          FUN_180007f00(param_1,&DAT_180027258,pdVar3,param_4);
        }
        else if ((local_280 != local_278) && (local_280 != local_274)) {
          local_22c._4_8_ = param_3;
          while ((*(double *)local_22c._4_8_ != 0.0 &&
                 (iVar1 = _stricmp(*(char **)local_22c._4_8_,(char *)local_258), iVar1 != 0))) {
            local_22c._4_8_ = local_22c._4_8_ + 0x18;
          }
          if (*(double *)(local_22c._4_8_ + 8) != 0.0) {
            if (*(int *)(local_22c._4_8_ + 0x10) == 0) {
              local_1a8 = DAT_180026638;
            }
            else {
              local_1c8 = FUN_1800082f0((char *)local_250,*(int *)(local_22c._4_8_ + 0x10),
                                        &local_1a8);
              if (local_1c8 == (undefined *)0x0) {
                pdVar3 = local_250;
                param_4 = local_258;
                FUN_1800220b0(1,"Unit <%s> for property <%s> not supported by Aspen Plus",local_250,
                              local_258);
                goto LAB_18001b60f;
              }
            }
            local_260 = local_280;
            local_1e8 = local_27c;
            if (local_240 == 1) {
              local_248 = (double *)((longlong)(local_280 + -1) * 0x14 + local_268[6]);
              if (*(char *)local_248 == '%') {
                local_234 = 1;
              }
              else if (*(char *)local_248 == '$') {
                local_234 = -1;
              }
              else {
                iVar1 = strcmp((char *)local_248,(char *)local_250);
                if (iVar1 == 0) {
                  local_234 = 2;
                }
                else {
                  param_4 = local_258;
                  FUN_1800220b0(0,"ERR-UNIT <%s> for property <%s> differs from UNIT",local_248,
                                local_258);
                  local_234 = -1;
                }
              }
            }
            goto LAB_18001b886;
          }
          pdVar3 = local_258;
          FUN_1800220b0(1,"Property <%s> not supported by Aspen Plus",local_258,param_4);
        }
LAB_18001b60f:
        local_258 = (double *)((longlong)local_258 + 0xd);
        local_250 = (double *)((longlong)local_250 + 0x14);
      }
    }
LAB_18001b100:
    local_208 = (longlong *)local_208[1];
  } while( true );
}

/* RVA 0x1c050, FUN_18001c050 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00018001d06e) */
/* WARNING: Removing unreachable block (ram,0x00018001d0a1) */
/* WARNING: Removing unreachable block (ram,0x00018001d192) */
/* WARNING: Removing unreachable block (ram,0x00018001d1c8) */
/* WARNING: Removing unreachable block (ram,0x00018001d85e) */

void FUN_18001c050(undefined8 param_1,uint *param_2,double *param_3,double *param_4)

{
  int iVar1;
  double *pdVar2;
  size_t sVar3;
  ulonglong uVar4;
  undefined *puVar5;
  undefined1 auStackY_478 [32];
  char *local_448;
  int local_440;
  undefined8 *local_438;
  int local_430;
  int local_42c;
  double *local_428;
  int local_420;
  int local_41c;
  int local_418;
  double *local_410;
  char local_408 [8];
  double *local_400;
  double *local_3f8;
  double *local_3f0;
  int local_3e8;
  int local_3e4;
  int local_3e0;
  int local_3dc;
  int local_3d8;
  int local_3d4;
  int local_3d0;
  int local_3cc;
  undefined4 local_3c8;
  int local_3c4;
  int local_3c0;
  undefined *local_3b8;
  longlong *local_3b0;
  char *local_3a8;
  double *local_3a0;
  undefined *local_398;
  double local_390;
  longlong local_388;
  undefined8 local_380;
  undefined8 local_378;
  undefined8 local_370;
  undefined8 local_368;
  double local_360;
  double local_358;
  int *local_350;
  double *local_348;
  double *local_340;
  undefined8 local_338;
  char local_330 [24];
  char local_318 [208];
  char local_248 [256];
  char local_148 [96];
  char local_e8 [208];
  ulonglong local_18;
  
  local_18 = DAT_180032178 ^ (ulonglong)auStackY_478;
  local_3c8 = 0;
  pdVar2 = param_3;
  local_350 = FUN_180021a60(5);
  local_3b0 = *(longlong **)(local_350 + 2);
  do {
    if (local_3b0 == (longlong *)0x0) {
      return;
    }
    local_438 = (undefined8 *)*local_3b0;
    if ((local_438[3] != 0) &&
       ((local_438[3] == 0 || (iVar1 = _stricmp((char *)local_438[3],""), iVar1 != 0)))) {
      local_388 = local_438[1];
      local_338 = *local_438;
      local_41c = -1;
      local_420 = -1;
      local_42c = -1;
      local_3d0 = 0;
      local_3d4 = 0;
      local_398 = (undefined *)0x0;
      local_3b8 = (undefined *)0x0;
      local_3a0 = (double *)0x0;
      local_3e8 = 0;
      local_3cc = 0;
      local_418 = 0;
      local_3c4 = 0;
      local_3c0 = 0;
      strcpy(local_330,"");
      if (local_438[6] == 0) {
        local_3e4 = -1;
      }
      else {
        local_3e4 = 1;
      }
      local_430 = 1;
      local_428 = (double *)local_438[3];
      local_3f8 = (double *)local_438[5];
      while (local_430 <= *(short *)(local_438 + 2)) {
        local_440 = 0;
        while ((((&PTR_DAT_18002e640)[(longlong)local_440 * 3] != (undefined *)0x0 &&
                (local_428 != (double *)0x0)) &&
               (iVar1 = _stricmp((&PTR_DAT_18002e640)[(longlong)local_440 * 3],(char *)local_428),
               iVar1 != 0))) {
          local_440 = local_440 + 1;
        }
        if (((&PTR_DAT_18002e648)[(longlong)local_440 * 3] == (undefined *)0x0) ||
           (*(&PTR_DAT_18002e648)[(longlong)local_440 * 3] != 'T')) {
          if (((&PTR_DAT_18002e648)[(longlong)local_440 * 3] != (undefined *)0x0) &&
             (*(&PTR_DAT_18002e648)[(longlong)local_440 * 3] == 'P')) {
            pdVar2 = &local_358;
            local_3a0 = (double *)FUN_1800082f0((char *)local_3f8,0x16,pdVar2);
            if (local_3a0 == (double *)0x0) {
              pdVar2 = local_3f8;
              param_4 = local_428;
              FUN_1800220b0(1,"Unit <%s> for property <%s> not supported by Aspen Plus",local_3f8,
                            local_428);
            }
            else {
              local_420 = local_430;
              local_3d4 = local_3d4 + 1;
            }
            if (local_3e4 == 1) {
              local_400 = (double *)((longlong)(local_430 + -1) * 0x14 + local_438[6]);
              if (*(char *)local_400 == '%') {
                local_3dc = 1;
              }
              else if (*(char *)local_400 == '$') {
                local_3dc = -1;
              }
              else {
                iVar1 = strcmp((char *)local_400,(char *)local_3f8);
                if (iVar1 == 0) {
                  local_3dc = 2;
                }
                else {
                  pdVar2 = local_400;
                  param_4 = local_428;
                  FUN_1800220b0(0,"ERR-UNIT <%s> for property <%s> differs from UNIT",local_400,
                                local_428);
                  local_3dc = -1;
                }
              }
            }
          }
        }
        else {
          pdVar2 = &local_360;
          local_3b8 = FUN_1800082f0((char *)local_3f8,0x19,pdVar2);
          if (local_3b8 == (undefined *)0x0) {
            pdVar2 = local_3f8;
            param_4 = local_428;
            FUN_1800220b0(1,"Unit <%s> for property <%s> not supported by Aspen Plus",local_3f8,
                          local_428);
          }
          else {
            local_41c = local_430;
            local_3d0 = local_3d0 + 1;
          }
          if (local_3e4 == 1) {
            local_400 = (double *)((longlong)(local_430 + -1) * 0x14 + local_438[6]);
            if (*(char *)local_400 == '%') {
              local_3e0 = 1;
            }
            else if (*(char *)local_400 == '$') {
              local_3e0 = -1;
            }
            else {
              iVar1 = strcmp((char *)local_400,(char *)local_3f8);
              if (iVar1 == 0) {
                local_3e0 = 2;
              }
              else {
                pdVar2 = local_400;
                param_4 = local_428;
                FUN_1800220b0(0,"ERR-UNIT <%s> for property <%s> differs from UNIT",local_400,
                              local_428);
                local_3e0 = -1;
              }
            }
          }
        }
        local_348 = local_428;
        local_430 = local_430 + 1;
        if (local_428 != (double *)0x0) {
          local_428 = (double *)((longlong)local_428 + 0xd);
        }
        local_3f8 = (double *)((longlong)local_3f8 + 0x14);
      }
      if ((local_41c == -1) || (local_420 == -1)) {
        if ((local_41c == -1) || (local_420 != -1)) {
          if ((local_41c != -1) || (local_420 == -1)) {
            FUN_1800220b0(0,"Neither T nor P given in TABLE - no DATA GROUP written",pdVar2,param_4)
            ;
            goto LAB_18001c0b0;
          }
          strcpy(local_408,"P");
        }
        else {
          strcpy(local_408,"T");
        }
      }
      else {
        strcpy(local_408,"TP");
        local_3e8 = 1;
      }
      local_3c4 = local_3d0 + local_3d4;
      local_3c0 = (int)*(short *)(local_438 + 2);
      local_3cc = local_3c0 - local_3c4;
      if ((local_3cc < 1) && (local_3e8 == 0)) {
        FUN_1800220b0(0,"No property given in TABLE - no DATA GROUP written",pdVar2,param_4);
      }
      else {
        if (0 < local_3cc) {
          local_430 = 1;
          local_428 = (double *)local_438[3];
          local_3f8 = (double *)local_438[5];
          local_3a8 = (char *)local_438[4];
          while (local_430 <= *(short *)(local_438 + 2)) {
            if (((local_428 != (double *)0x0) && (iVar1 = strcmp((char *)local_428,"T"), iVar1 != 0)
                ) && (iVar1 = strcmp((char *)local_428,"P"), iVar1 != 0)) {
              local_3f0 = param_3;
              while ((*local_3f0 != 0.0 &&
                     ((iVar1 = strcmp((char *)*local_3f0,(char *)local_428), iVar1 != 0 ||
                      (((*(char *)((longlong)local_3f0 + 0x14) != ' ' &&
                        ((iVar1 = strcmp((char *)*local_3f0,"VOL"), iVar1 != 0 ||
                         (local_3a8 != (char *)0x0)))) &&
                       (*(char *)((longlong)local_3f0 + 0x14) != *local_3a8))))))) {
                local_3f0 = local_3f0 + 3;
              }
              if (local_3f0[1] != 0.0) {
                if (*(int *)(local_3f0 + 2) == 0) {
                  local_390 = DAT_180026638;
                }
                else {
                  pdVar2 = &local_390;
                  local_398 = FUN_1800082f0((char *)local_3f8,*(int *)(local_3f0 + 2),pdVar2);
                  if (local_398 == (undefined *)0x0) {
                    pdVar2 = local_3f8;
                    param_4 = local_428;
                    FUN_1800220b0(1,"Unit <%s> for property <%s> not supported by Aspen Plus",
                                  local_3f8,local_428);
                    goto LAB_18001c715;
                  }
                }
                local_42c = local_430;
                if (local_3e4 == 1) {
                  local_400 = (double *)((longlong)(local_430 + -1) * 0x14 + local_438[6]);
                  if (*(char *)local_400 == '%') {
                    local_3d8 = 1;
                  }
                  else if (*(char *)local_400 == '$') {
                    local_3d8 = -1;
                  }
                  else {
                    iVar1 = strcmp((char *)local_400,(char *)local_3f8);
                    if (iVar1 == 0) {
                      local_3d8 = 2;
                    }
                    else {
                      pdVar2 = local_400;
                      param_4 = local_428;
                      FUN_1800220b0(0,"ERR-UNIT <%s> for property <%s> differs from UNIT",local_400,
                                    local_428);
                      local_3d8 = -1;
                    }
                  }
                }
              }
              if (local_42c < 1) {
                pdVar2 = local_428;
                FUN_1800220b0(1,"Property <%s> not supported by Aspen Plus - no DATA GROUP written."
                              ,local_428,param_4);
              }
              break;
            }
LAB_18001c715:
            local_340 = local_428;
            local_430 = local_430 + 1;
            if (local_428 != (double *)0x0) {
              local_428 = (double *)((longlong)local_428 + 0xd);
            }
            local_3f8 = (double *)((longlong)local_3f8 + 0x14);
            local_3a8 = local_3a8 + 0xd;
          }
          if (local_42c < 0) {
            FUN_1800220b0(0,
                          "Incorrect property name or incorrect unit in TABLE - no DATA GROUP written."
                          ,pdVar2,param_4);
            goto LAB_18001c0b0;
          }
          local_418 = 0;
          strcpy(local_330,(char *)local_3f0[1]);
          iVar1 = strcmp(local_330,"DHVL");
          if ((((((iVar1 == 0) || (iVar1 = strcmp(local_330,"CPV"), iVar1 == 0)) ||
                ((iVar1 = strcmp(local_330,"CPL"), iVar1 == 0 ||
                 ((((iVar1 = strcmp(local_330,"RHOV"), iVar1 == 0 ||
                    (iVar1 = strcmp(local_330,"RHOL"), iVar1 == 0)) ||
                   (iVar1 = strcmp(local_330,"VV"), iVar1 == 0)) ||
                  ((iVar1 = strcmp(local_330,"VL"), iVar1 == 0 ||
                   (iVar1 = strcmp(local_330,"MUV"), iVar1 == 0)))))))) ||
               (iVar1 = strcmp(local_330,"MUL"), iVar1 == 0)) ||
              ((iVar1 = strcmp(local_330,"KV"), iVar1 == 0 ||
               (iVar1 = strcmp(local_330,"KL"), iVar1 == 0)))) ||
             ((iVar1 = strcmp(local_330,"SIGL"), iVar1 == 0 ||
              ((iVar1 = strcmp(local_330,"HV"), iVar1 == 0 ||
               (iVar1 = strcmp(local_330,"HL"), iVar1 == 0)))))) {
            strcpy(local_408,"TP");
            local_418 = 1;
          }
          iVar1 = strcmp(local_330,"DHVS");
          if (((((iVar1 == 0) || (iVar1 = strcmp(local_330,"DHLS"), iVar1 == 0)) ||
               (iVar1 = strcmp(local_330,"CPS"), iVar1 == 0)) ||
              (((iVar1 = strcmp(local_330,"CPIG"), iVar1 == 0 ||
                (iVar1 = strcmp(local_330,"RHOS"), iVar1 == 0)) ||
               ((iVar1 = strcmp(local_330,"VS"), iVar1 == 0 ||
                ((iVar1 = strcmp(local_330,"PL"), iVar1 == 0 ||
                 (iVar1 = strcmp(local_330,"PS"), iVar1 == 0)))))))) ||
             ((iVar1 = strcmp(local_330,"KS"), iVar1 == 0 ||
              ((iVar1 = strcmp(local_330,"HS"), iVar1 == 0 ||
               (iVar1 = strcmp(local_330,"WATSOL"), iVar1 == 0)))))) {
            strcpy(local_408,"T");
            local_418 = 2;
          }
          strcpy(local_330,"");
        }
        strcpy(local_e8,"");
        strcpy(local_318,"");
        if ((local_41c < 1) || (local_420 < 1)) {
          if ((local_41c < 1) || (-1 < local_420)) {
            if ((local_41c < 0) && (0 < local_420)) {
              FUN_180002d90(local_318,&DAT_180028df4,local_3a0,param_4);
              strcat(local_e8,local_318);
            }
          }
          else {
            FUN_180002d90(local_318,&DAT_180028df4,local_3b8,param_4);
            strcat(local_e8,local_318);
          }
        }
        else {
          if (local_418 == 2) {
            FUN_180002d90(local_318,&DAT_180028df4,local_3b8,param_4);
          }
          else {
            param_4 = local_3a0;
            FUN_180002d90(local_318,"%s %s ",local_3b8,local_3a0);
          }
          strcat(local_e8,local_318);
        }
        if (local_42c < 1) {
          if (local_3e8 == 1) {
            FUN_180002d90(local_318,&DAT_180028df4,"EQB=\'EQB\'",param_4);
            strcat(local_e8,local_318);
          }
        }
        else {
          FUN_180002d90(local_318,&DAT_180028df4,local_398,param_4);
          strcat(local_e8,local_318);
        }
        FUN_180002d90(local_318,"SYSTEM-DEF=%s ",local_408,param_4);
        strcat(local_e8,local_318);
        if (local_42c < 1) {
          if (local_3e8 == 1) {
            FUN_180002d90(local_318,&DAT_180028df4,"PROP-LIST=EQB ",param_4);
            strcat(local_e8,local_318);
          }
        }
        else {
          FUN_180002d90(local_318,"PROP-LIST=%s ",local_3f0[1],param_4);
          strcat(local_e8,local_318);
        }
        *param_2 = *param_2 + 1;
        uVar4 = (ulonglong)*param_2;
        FUN_180007f00(param_1,"? PROPERTIES DATA \"PURE-COMP\" \"DG-%d\" ? ",uVar4,param_4);
        FUN_180007f00(param_1," ; \"SI_MOLE\" ; \n",uVar4,param_4);
        if ((local_42c < 1) && (local_3e8 == 1)) {
          FUN_180007f00(param_1,"\\ \"SYSTEM-DEF\" STATESPEC = %s",local_408,param_4);
        }
        else if (0 < local_42c) {
          FUN_180007f00(param_1,"\\ \"SYSTEM-DEF\" STATESPEC = %s",local_3f0[1],param_4);
        }
        _strupr((char *)(local_388 + 0x240));
        pdVar2 = (double *)(local_388 + 0x240);
        FUN_180007f00(param_1," CID = %s \\ \n",pdVar2,param_4);
        FUN_180007f00(param_1," \\ USING ",pdVar2,param_4);
        local_248[0] = '\0';
        local_378 = 0;
        local_380 = 0;
        local_148[0] = '\0';
        for (local_440 = 0; local_440 < *(short *)((longlong)local_438 + 0x42);
            local_440 = local_440 + 1) {
          if (local_440 == 0) {
            FUN_180007f00(param_1," USE = \"STD-DEV\" / \n",pdVar2,param_4);
            strcpy(local_148,local_248);
          }
          local_448 = local_248;
          pdVar2 = (double *)(ulonglong)(local_440 + 1);
          FUN_180002d90(local_448,"  DATA    %2i",pdVar2,param_4);
          if (local_440 == *(short *)((longlong)local_438 + 0x42) + -1) {
            FUN_180007f00(param_1," USE = DATA \\ \n",pdVar2,param_4);
          }
          else {
            FUN_180007f00(param_1," USE = DATA / \n",pdVar2,param_4);
          }
        }
        local_148[0] = '\0';
        local_368 = 0;
        local_370 = 0;
        local_248[0] = '\0';
        local_3c8 = 0;
        FUN_180007f00(param_1,"\\ DATA \n",pdVar2,param_4);
        for (local_440 = 0; local_440 < *(short *)((longlong)local_438 + 0x42);
            local_440 = local_440 + 1) {
          if (local_3e4 == 1) {
            local_448 = local_248;
            if (local_41c == -1) {
              if (local_418 != 0) {
                FUN_180007e70(0xb,local_248,(longlong *)&local_448);
                FUN_180002d90(local_448," %-11s",&DAT_180028740,param_4);
                sVar3 = strlen(local_448);
                local_448 = local_448 + (int)sVar3;
              }
            }
            else {
              local_410 = (double *)
                          (local_438[7] + (longlong)(local_440 * *(short *)(local_438 + 2)) * 0x10 +
                           -0x10 + (longlong)local_41c * 0x10);
              FUN_180007e70(0xb,local_248,(longlong *)&local_448);
              if ((local_3e0 == 1) && (local_410[1] != DAT_180029478)) {
                FUN_180002d90(local_448," -%-10G",local_410[1],param_4);
              }
              else if ((local_3e0 == 2) && (local_410[1] != DAT_180029478)) {
                FUN_180002d90(local_448," %-11G",local_410[1] * local_360,param_4);
              }
              else {
                FUN_180002d90(local_448," %-11s",&DAT_180028740,param_4);
              }
              sVar3 = strlen(local_448);
              local_448 = local_448 + (int)sVar3;
            }
            if ((local_420 == -1) || (local_418 != 1)) {
              if (local_418 == 1) {
                FUN_180007e70(0xb,local_248,(longlong *)&local_448);
                FUN_180002d90(local_448," %-11s",&DAT_180028740,param_4);
                sVar3 = strlen(local_448);
                local_448 = local_448 + (int)sVar3;
              }
            }
            else {
              local_410 = (double *)
                          (local_438[7] + (longlong)(local_440 * *(short *)(local_438 + 2)) * 0x10 +
                           -0x10 + (longlong)local_420 * 0x10);
              FUN_180007e70(0xb,local_248,(longlong *)&local_448);
              if ((local_3dc == 1) && (local_410[1] != DAT_180029478)) {
                FUN_180002d90(local_448," -%-10G",local_410[1],param_4);
              }
              else if ((local_3dc == 2) && (local_410[1] != DAT_180029478)) {
                FUN_180002d90(local_448," %-11G",local_410[1] * local_358,param_4);
              }
              else {
                FUN_180002d90(local_448," %-11s",&DAT_180028740,param_4);
              }
              sVar3 = strlen(local_448);
              local_448 = local_448 + (int)sVar3;
            }
            if (local_42c != -1) {
              FUN_180007e70(0xb,local_248,(longlong *)&local_448);
              local_410 = (double *)
                          (local_438[7] + (longlong)(local_440 * *(short *)(local_438 + 2)) * 0x10 +
                           -0x10 + (longlong)local_42c * 0x10);
              if ((local_3d8 == 1) && (local_410[1] != DAT_180029478)) {
                FUN_180002d90(local_448," -%-10G",local_410[1],param_4);
              }
              else if ((local_3d8 == 2) && (local_410[1] != DAT_180029478)) {
                FUN_180002d90(local_448," %-11G",local_410[1] * local_390,param_4);
              }
              else {
                FUN_180002d90(local_448," %-11s",&DAT_180028740,param_4);
              }
              sVar3 = strlen(local_448);
              local_448 = local_448 + (int)sVar3;
            }
          }
          if ((local_440 == 0) || (iVar1 = strcmp(local_148,local_248), iVar1 != 0)) {
            strcpy(local_148,local_248);
            FUN_180002d90(local_318,"  STD-DEV %2i%s\n",(ulonglong)(local_440 + 1),local_248);
            param_4 = (double *)&local_3c8;
            FUN_1800070c0(local_318,local_e8,0,(uint *)param_4,param_1);
          }
          local_448 = local_248;
          puVar5 = (undefined *)(ulonglong)(local_440 + 1);
          FUN_180002d90(local_448,"  DATA    %2i",puVar5,param_4);
          sVar3 = strlen(local_448);
          local_448 = local_448 + (int)sVar3;
          if (local_41c == -1) {
            if (local_418 != 0) {
              FUN_180007e70(0xb,local_248,(longlong *)&local_448);
              puVar5 = &DAT_180028740;
              FUN_180002d90(local_448," %-11s",&DAT_180028740,param_4);
              sVar3 = strlen(local_448);
              local_448 = local_448 + (int)sVar3;
            }
          }
          else {
            FUN_180007e70(0xb,local_248,(longlong *)&local_448);
            local_410 = (double *)
                        (local_438[7] + (longlong)(local_440 * *(short *)(local_438 + 2)) * 0x10 +
                         -0x10 + (longlong)local_41c * 0x10);
            if (*local_410 == DAT_180029478) {
              puVar5 = &DAT_180028740;
              FUN_180002d90(local_448," %-11s",&DAT_180028740,param_4);
            }
            else {
              puVar5 = (undefined *)(*local_410 * local_360);
              FUN_180002d90(local_448," %-11G",puVar5,param_4);
            }
            sVar3 = strlen(local_448);
            local_448 = local_448 + (int)sVar3;
          }
          if ((local_420 == -1) || (local_418 != 1)) {
            if (local_418 == 1) {
              FUN_180007e70(0xb,local_248,(longlong *)&local_448);
              puVar5 = &DAT_180028740;
              FUN_180002d90(local_448," %-11s",&DAT_180028740,param_4);
              sVar3 = strlen(local_448);
              local_448 = local_448 + (int)sVar3;
            }
          }
          else {
            local_410 = (double *)
                        (local_438[7] + (longlong)(local_440 * *(short *)(local_438 + 2)) * 0x10 +
                         -0x10 + (longlong)local_420 * 0x10);
            if (*local_410 == DAT_180029478) {
              puVar5 = &DAT_180028740;
              FUN_180002d90(local_448," %-11s",&DAT_180028740,param_4);
            }
            else {
              puVar5 = (undefined *)(*local_410 * local_358);
              FUN_180002d90(local_448," %-11G",puVar5,param_4);
            }
            sVar3 = strlen(local_448);
            local_448 = local_448 + (int)sVar3;
          }
          if (local_42c != -1) {
            FUN_180007e70(0xb,local_248,(longlong *)&local_448);
            local_410 = (double *)
                        (local_438[7] + (longlong)(local_440 * *(short *)(local_438 + 2)) * 0x10 +
                         -0x10 + (longlong)local_42c * 0x10);
            if (*local_410 == DAT_180029478) {
              puVar5 = &DAT_180028740;
              FUN_180002d90(local_448," %-11s",&DAT_180028740,param_4);
            }
            else {
              puVar5 = (undefined *)(*local_410 * local_390);
              FUN_180002d90(local_448," %-11G",puVar5,param_4);
            }
            sVar3 = strlen(local_448);
            local_448 = local_448 + (int)sVar3;
          }
          FUN_180002d90(local_448,&DAT_180027258,puVar5,param_4);
          param_4 = (double *)&local_3c8;
          pdVar2 = (double *)0x1;
          FUN_1800070c0(local_248,local_e8,1,(uint *)param_4,param_1);
        }
        FUN_180007f00(param_1,&DAT_180027248,pdVar2,param_4);
      }
    }
LAB_18001c0b0:
    local_3b0 = (longlong *)local_3b0[1];
  } while( true );
}

/* RVA 0x1dab0, FUN_18001dab0 */
undefined8 FUN_18001dab0(undefined8 param_1,undefined8 param_2,char *param_3,undefined *param_4)

{
  char *_Str2;
  bool bVar1;
  int iVar2;
  int *piVar3;
  int local_38;
  undefined8 *local_30;
  
  bVar1 = false;
  piVar3 = FUN_180021a60(8);
  for (local_30 = *(undefined8 **)(piVar3 + 2); local_30 != (undefined8 *)0x0;
      local_30 = (undefined8 *)local_30[1]) {
    _Str2 = (char *)*local_30;
    if (!bVar1) {
      param_3 = "PROPERTIES       ";
      FUN_180007f00(param_1,&DAT_1800272c0,"PROPERTIES       ",param_4);
      bVar1 = true;
    }
    local_38 = 0;
    while (((&PTR_s_UNIQUAC_18002e590)[(longlong)local_38 * 7] != (undefined *)0x0 &&
           (iVar2 = _stricmp((&PTR_s_UNIQUAC_18002e590)[(longlong)local_38 * 7],_Str2), iVar2 != 0))
          ) {
      local_38 = local_38 + 1;
    }
    if ((&PTR_DAT_18002e598)[(longlong)local_38 * 7] != (undefined *)0x0) {
      param_4 = (&PTR_s_UNIQUAC_18002e590)[(longlong)local_38 * 7];
      param_3 = "PROPERTIES";
      FUN_180007f00(param_1,"            %s %s\n","PROPERTIES",param_4);
    }
  }
  FUN_180007f00(param_1,&DAT_180027468,param_3,param_4);
  return 1;
}

/* RVA 0x1dbf0, FUN_18001dbf0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00018001dc28) */

undefined8
FUN_18001dbf0(undefined8 param_1,undefined8 param_2,undefined *param_3,undefined8 param_4)

{
  int iVar1;
  undefined1 auStack_78 [32];
  int local_58;
  undefined8 *local_50;
  char *local_48;
  undefined8 local_40;
  undefined4 local_38;
  int *local_30;
  undefined **local_28;
  char local_20 [16];
  ulonglong local_10;
  
  local_10 = DAT_180032178 ^ (ulonglong)auStack_78;
  local_38 = 0;
  local_40 = 0;
  local_20[0] = '\0';
  local_30 = FUN_180021a60(8);
  local_50 = *(undefined8 **)(local_30 + 2);
  do {
    if (local_50 == (undefined8 *)0x0) {
      FUN_180007f00(param_1,&DAT_180027468,param_3,param_4);
      return 1;
    }
    local_48 = (char *)*local_50;
    local_58 = 0;
    while ((&PTR_s_UNIQUAC_18002e590)[(longlong)local_58 * 7] != (undefined *)0x0) {
      local_28 = &PTR_s_UNIQUAC_18002e590;
      iVar1 = _stricmp((&PTR_s_UNIQUAC_18002e590)[(longlong)local_58 * 7],local_48);
      if (iVar1 == 0) break;
      local_58 = local_58 + 1;
    }
    if (((&PTR_DAT_18002e598)[(longlong)local_58 * 7] != (undefined *)0x0) &&
       ((local_20[0] == '\0' || (iVar1 = _stricmp(local_20,local_48), iVar1 != 0)))) {
      FUN_180007f00(param_1,"? PROPERTIES \"OPTION-SETS\" %s ?\n",
                    (&PTR_s_UNIQUAC_18002e590)[(longlong)local_58 * 7],param_4);
      param_3 = (&PTR_s_UNIQUAC_18002e590)[(longlong)local_58 * 7];
      FUN_180007f00(param_1,"\\ PARAM BASE = %s \\ \n",param_3,param_4);
      strcpy(local_20,local_48);
    }
    local_50 = (undefined8 *)local_50[1];
  } while( true );
}

/* RVA 0x1ddb0, FUN_18001ddb0 */
void FUN_18001ddb0(void)

{
  return;
}

/* RVA 0x1ddc0, FUN_18001ddc0 */
undefined8 FUN_18001ddc0(char *param_1,int param_2,ulonglong param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  int *piVar3;
  longlong lVar4;
  uint uVar5;
  char *pcVar6;
  undefined8 local_18;
  char *local_10;
  
  uVar5 = (uint)param_3;
  if (param_2 == 1) {
    uVar2 = 2;
    iVar1 = FUN_180021870((longlong)param_1,(longlong)&local_18,2);
    if (iVar1 != 2) {
      return 0;
    }
    DAT_1800341d0 = calloc(1,0x36d);
    uVar2 = FUN_180022020((longlong)DAT_1800341d0,uVar5,uVar2,param_4);
    if ((int)uVar2 == 0) {
      piVar3 = FUN_180021a60(1);
      FUN_180023c20(piVar3,DAT_1800341d0);
      FUN_180022050((longlong)DAT_1800341d0,local_10,0x11,uVar5);
      return 0;
    }
    return 0xffffffff;
  }
  if (param_2 == 3) {
    if (DAT_1800341d0 != (void *)0x0) {
      iVar1 = FUN_180021f90((longlong)param_1,"AUTHOR");
      if (iVar1 == 0) {
        iVar1 = FUN_180021730(param_1,&local_18,2,1);
        if (iVar1 == 2) {
          FUN_180022050((longlong)DAT_1800341d0 + 0x11,local_10,0x100,uVar5);
          return 0;
        }
        return 0;
      }
      iVar1 = FUN_180021f90((longlong)param_1,"TITLE");
      if (iVar1 == 0) {
        iVar1 = FUN_180021730(param_1,&local_18,2,1);
        if (iVar1 == 2) {
          FUN_180022050((longlong)DAT_1800341d0 + 0x111,local_10,0x100,uVar5);
          return 0;
        }
        return 0;
      }
      iVar1 = FUN_180021f90((longlong)param_1,"JOURNAL");
      if (iVar1 == 0) {
        iVar1 = FUN_180021730(param_1,&local_18,2,1);
        if (iVar1 == 2) {
          FUN_180022050((longlong)DAT_1800341d0 + 0x211,local_10,0x100,uVar5);
          return 0;
        }
        return 0;
      }
      iVar1 = FUN_180021f90((longlong)param_1,"CODEN");
      if (iVar1 == 0) {
        iVar1 = FUN_180021730(param_1,&local_18,2,2);
        if (iVar1 != 2) {
          return 0;
        }
        lVar4 = (longlong)DAT_1800341d0 + 0x311;
LAB_18001e156:
        FUN_180022050(lVar4,local_10,10,uVar5);
        return 0;
      }
      iVar1 = FUN_180021f90((longlong)param_1,"VOLUME");
      if (iVar1 == 0) {
        iVar1 = FUN_180021730(param_1,&local_18,2,2);
        if (iVar1 == 2) {
          FUN_180022050((longlong)DAT_1800341d0 + 0x31b,local_10,0xb,uVar5);
          return 0;
        }
        return 0;
      }
      iVar1 = FUN_180021f90((longlong)param_1,"ISSUE");
      if (iVar1 == 0) {
        iVar1 = FUN_180021730(param_1,&local_18,2,2);
        if (iVar1 == 2) {
          FUN_180022050((longlong)DAT_1800341d0 + 0x326,local_10,0xb,uVar5);
          return 0;
        }
        return 0;
      }
      iVar1 = FUN_180021f90((longlong)param_1,"PAGE");
      if (iVar1 == 0) {
        iVar1 = FUN_180021730(param_1,&local_18,2,2);
        if (iVar1 == 2) {
          FUN_180022050((longlong)DAT_1800341d0 + 0x331,local_10,0x1e,uVar5);
          return 0;
        }
        return 0;
      }
      iVar1 = FUN_180021f90((longlong)param_1,"YEAR");
      if (iVar1 == 0) {
        iVar1 = FUN_180021730(param_1,&local_18,2,2);
        if (iVar1 != 2) {
          return 0;
        }
        lVar4 = (longlong)DAT_1800341d0 + 0x34f;
        goto LAB_18001e156;
      }
      iVar1 = FUN_180021f90((longlong)param_1,"ISBN");
      if (iVar1 == 0) {
        iVar1 = FUN_180021730(param_1,&local_18,2,2);
        if (iVar1 != 2) {
          return 0;
        }
        lVar4 = (longlong)DAT_1800341d0 + 0x359;
        goto LAB_18001e156;
      }
      pcVar6 = "LINE %d - unrecognized keyword in SOURCE \n";
      param_3 = param_3 & 0xffffffff;
      goto LAB_18001e1a6;
    }
  }
  else if (param_2 == 2) {
    DAT_1800341d0 = (void *)0x0;
    return 0;
  }
  pcVar6 = "LINE %d - SOURCE is initialized";
LAB_18001e1a6:
  FUN_1800220b0(0,pcVar6,param_3,param_4);
  return 0;
}

/* RVA 0x1e1c0, FUN_18001e1c0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18001e1c0(char *param_1,int param_2,uint param_3,undefined8 param_4)

{
  short *psVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined8 uVar7;
  int *piVar8;
  void *pvVar9;
  char *pcVar10;
  undefined8 *puVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  longlong lVar14;
  ulonglong uVar15;
  undefined1 auStack_218 [32];
  char *local_1f8;
  char *local_1f0;
  undefined8 local_1e8;
  undefined4 local_1e0;
  undefined4 local_1d8;
  char *local_1c8;
  char *local_1c0;
  char *local_1b8;
  char *local_1b0;
  undefined8 local_1a8 [38];
  char local_78 [16];
  char local_68 [24];
  char local_50 [32];
  ulonglong local_30;
  
  local_30 = DAT_180032178 ^ (ulonglong)auStack_218;
  local_78[0] = '\0';
  local_78[1] = '\0';
  local_78[2] = '\0';
  local_78[3] = '\0';
  local_78[4] = '\0';
  local_78[5] = '\0';
  local_78[6] = '\0';
  local_78[7] = '\0';
  local_78[8] = '\0';
  local_68[0] = '\0';
  local_50[0] = '\0';
  uVar15 = (ulonglong)param_3;
  local_50[0x11] = '\0';
  local_50[0x12] = '\0';
  local_50[0x13] = '\0';
  local_50[0x14] = '\0';
  local_50[0x15] = '\0';
  local_50[0x16] = '\0';
  local_50[0x17] = '\0';
  local_50[0x18] = '\0';
  local_50[0x19] = '\0';
  local_50[0x1a] = '\0';
  local_50[0x1b] = '\0';
  local_50[0x1c] = '\0';
  local_50[0x1d] = '\0';
  local_50[0x1e] = '\0';
  local_50[0x1f] = 0;
  local_68[1] = '\0';
  local_68[2] = '\0';
  local_68[3] = '\0';
  local_68[4] = '\0';
  local_68[5] = '\0';
  local_68[6] = '\0';
  local_68[7] = '\0';
  local_68[8] = '\0';
  local_68[9] = '\0';
  local_68[10] = '\0';
  local_68[0xb] = '\0';
  local_68[0xc] = '\0';
  local_68[0xd] = '\0';
  local_68[0xe] = '\0';
  local_68[0xf] = '\0';
  local_68[0x10] = '\0';
  local_50[1] = '\0';
  local_50[2] = '\0';
  local_50[3] = '\0';
  local_50[4] = '\0';
  local_50[5] = '\0';
  local_50[6] = '\0';
  local_50[7] = '\0';
  local_50[8] = '\0';
  local_50[9] = '\0';
  local_50[10] = '\0';
  local_50[0xb] = '\0';
  local_50[0xc] = '\0';
  local_50[0xd] = '\0';
  local_50[0xe] = '\0';
  local_50[0xf] = '\0';
  local_50[0x10] = '\0';
  if (param_2 == 1) {
    uVar7 = 0x2a;
    iVar4 = FUN_180021870((longlong)param_1,(longlong)&local_1c8,0x2a);
    if (iVar4 != 2) {
      return 0;
    }
    FUN_180021620(local_1c0);
    DAT_1800341d8 = calloc(1,600);
    uVar7 = FUN_180022020((longlong)DAT_1800341d8,param_3,uVar7,param_4);
    if ((int)uVar7 == 0) {
      piVar8 = FUN_180021a60(2);
      uVar7 = 0x14;
      FUN_180022050((longlong)local_50,local_1c0,0x14,param_3);
      FUN_180021440(local_50,piVar8,uVar7,uVar15);
      FUN_180023c20(piVar8,DAT_1800341d8);
      FUN_180022050((longlong)DAT_1800341d8,local_1c0,0x14,param_3);
      FUN_180022050((longlong)DAT_1800341d8 + 0x240,local_50,0x14,param_3);
      return 0;
    }
    return 0xffffffff;
  }
  if (param_2 != 3) {
    if (param_2 == 2) {
      DAT_1800341d8 = (void *)0x0;
      return 0;
    }
    return 0;
  }
  iVar4 = FUN_180021f90((longlong)param_1,"NAME");
  if (iVar4 == 0) {
    iVar4 = FUN_180021730(param_1,&local_1c8,2,1);
    if (iVar4 != 2) {
      return 0;
    }
    pcVar10 = (char *)((longlong)DAT_1800341d8 + 0x14);
LAB_18001e5d9:
    FUN_180022050((longlong)pcVar10,local_1c0,0x100,param_3);
    return 0;
  }
  iVar4 = FUN_180021f90((longlong)param_1,"SYNONYME");
  if ((iVar4 == 0) || (iVar4 = FUN_180021f90((longlong)param_1,"SYNONYM"), iVar4 == 0)) {
    uVar13 = 1;
    uVar7 = 2;
    iVar4 = FUN_180021730(param_1,&local_1c8,2,1);
    if (iVar4 != 2) {
      return 0;
    }
    if (*(short *)((longlong)DAT_1800341d8 + 0x220) == 0) {
      pvVar9 = calloc(1,0x100);
    }
    else {
      pvVar9 = realloc(*(void **)((longlong)DAT_1800341d8 + 0x228),
                       (longlong)(*(short *)((longlong)DAT_1800341d8 + 0x220) + 1) << 8);
    }
    uVar7 = FUN_180022020((longlong)pvVar9,param_3,uVar7,uVar13);
    if ((int)uVar7 == 0) {
      psVar1 = (short *)((longlong)DAT_1800341d8 + 0x220);
      *(void **)((longlong)DAT_1800341d8 + 0x228) = pvVar9;
      FUN_180022050((longlong)((longlong)*psVar1 * 0x100 + (longlong)pvVar9),local_1c0,0x100,param_3
                   );
      *(short *)((longlong)DAT_1800341d8 + 0x220) = *(short *)((longlong)DAT_1800341d8 + 0x220) + 1;
      return 0;
    }
    return 0xffffffff;
  }
  iVar4 = FUN_180021f90((longlong)param_1,"CAS-NR");
  if (iVar4 != 0) {
    iVar4 = FUN_180021f90((longlong)param_1,"FORMULA");
    if (iVar4 != 0) {
      iVar4 = FUN_180021f90((longlong)param_1,"STRUCTURE");
      if (iVar4 != 0) {
        FUN_1800220b0(0,"LINE %d - unrecognized keyword in COMP-DEF \n",uVar15,param_4);
        return 0;
      }
      uVar12 = 2;
      uVar13 = 0x2a;
      iVar4 = FUN_180021730(param_1,&local_1c8,0x2a,2);
      uVar7 = FUN_1800215c0((longlong *)&PTR_s_LYDERSEN_180031bb8,local_1c8);
      if ((int)uVar7 != 0) {
        FUN_1800220b0(0,"LINE %d - unknown STRUCTURE",uVar15,uVar12);
        return 0xffffffff;
      }
      if (iVar4 < 4) {
        return 0;
      }
      if (*(short *)((longlong)DAT_1800341d8 + 0x230) == 0) {
        pvVar9 = calloc(1,0x2e0);
      }
      else {
        pvVar9 = realloc(*(void **)((longlong)DAT_1800341d8 + 0x238),
                         (longlong)(*(short *)((longlong)DAT_1800341d8 + 0x230) + 1) * 0x2e0);
      }
      uVar7 = FUN_180022020((longlong)pvVar9,param_3,uVar13,uVar12);
      lVar14 = (longlong)DAT_1800341d8;
      if ((int)uVar7 != 0) {
        return 0xffffffff;
      }
      *(void **)((longlong)DAT_1800341d8 + 0x238) = pvVar9;
      pvVar9 = (void *)((longlong)pvVar9 + (longlong)*(short *)(lVar14 + 0x230) * 0x2e0);
      FUN_180022050((longlong)pvVar9,local_1c0,0x100,param_3);
      FUN_180022050((longlong)pvVar9 + 0x100,local_1b8,0x14,param_3);
      iVar5 = atoi(local_1b0);
      *(int *)((longlong)pvVar9 + 0x114) = iVar5;
      uVar6 = (iVar4 + -4) / 2;
      if (0 < (int)uVar6) {
        piVar8 = (int *)((longlong)pvVar9 + 300);
        lVar14 = (longlong)pvVar9 + 0x118;
        uVar15 = (ulonglong)uVar6;
        puVar11 = local_1a8 + 1;
        do {
          FUN_180022050(lVar14,(char *)puVar11[-1],0x14,param_3);
          iVar4 = atoi((char *)*puVar11);
          lVar14 = lVar14 + 0x18;
          *piVar8 = iVar4;
          piVar8 = piVar8 + 6;
          puVar11 = puVar11 + 2;
          uVar15 = uVar15 - 1;
        } while (uVar15 != 0);
      }
      *(short *)((longlong)DAT_1800341d8 + 0x230) = *(short *)((longlong)DAT_1800341d8 + 0x230) + 1;
      return 0;
    }
    iVar4 = FUN_180021730(param_1,&local_1c8,2,2);
    if (iVar4 != 2) {
      return 0;
    }
    pcVar10 = (char *)((longlong)DAT_1800341d8 + 0x120);
    if (*pcVar10 != '\0') {
      return 0;
    }
    goto LAB_18001e5d9;
  }
  iVar4 = FUN_180021730(param_1,&local_1c8,2,2);
  if (iVar4 == 2) {
    FUN_180022050((longlong)DAT_1800341d8 + 0x114,local_1c0,0xc,param_3);
  }
  if (*(char *)((longlong)DAT_1800341d8 + 0x114) == '\0') {
    return 0;
  }
  iVar4 = GetnamesfromCasno("PURE40",local_78,local_68);
  if (iVar4 != 1) {
    if (iVar4 != 2) {
      return 0;
    }
    pcVar10 = local_68;
    do {
      cVar2 = *pcVar10;
      pcVar10[(longlong)DAT_1800341d8 + (0x120 - (longlong)local_68)] = cVar2;
      pcVar10 = pcVar10 + 1;
    } while (cVar2 != '\0');
    return 0;
  }
  iVar4 = DAT_180032160;
  if (DAT_180032160 < 3) {
    pcVar10 = (char *)((longlong)DAT_1800341d8 + 0x240);
    lVar14 = -(longlong)pcVar10;
    do {
      cVar2 = *pcVar10;
      cVar3 = pcVar10[(longlong)(local_78 + lVar14)];
      if (cVar2 != cVar3) break;
      pcVar10 = pcVar10 + 1;
    } while (cVar3 != '\0');
    if (cVar2 == cVar3) goto LAB_18001e52e;
    uVar7 = GetSorResStringEx(0x46d);
    local_1f0 = DAT_1800341d8;
    local_1f8 = local_78;
    FUN_180002d90(&local_1c8,uVar7,DAT_1800341d8,local_78);
    uVar7 = GetSorResStringEx(0x46e);
    local_1d8 = 0xffffffff;
    local_1e0 = 1;
    local_1e8 = 0;
    local_1f0 = "No\\ to all";
    local_1f8 = "Yes to a\\ll";
    iVar4 = open_message_box(uVar7,&local_1c8," Y\\es "," N\\o ");
    if (iVar4 < 3) goto LAB_18001e4e9;
    DAT_180032160 = iVar4;
LAB_18001e4ee:
    if (iVar4 != 3) goto LAB_18001e52e;
  }
  else {
LAB_18001e4e9:
    if (iVar4 != 1) goto LAB_18001e4ee;
  }
  pcVar10 = local_78;
  do {
    cVar2 = *pcVar10;
    pcVar10[(longlong)DAT_1800341d8 + (0x240 - (longlong)local_78)] = cVar2;
    pcVar10 = pcVar10 + 1;
  } while (cVar2 != '\0');
LAB_18001e52e:
  pcVar10 = local_68;
  do {
    cVar2 = *pcVar10;
    pcVar10[(longlong)DAT_1800341d8 + (0x120 - (longlong)local_68)] = cVar2;
    pcVar10 = pcVar10 + 1;
  } while (cVar2 != '\0');
  return 0;
}

/* RVA 0x1e870, FUN_18001e870 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18001e870(char *param_1,int param_2,uint param_3)

{
  ulonglong uVar1;
  int iVar2;
  longlong lVar3;
  void *pvVar4;
  undefined8 uVar5;
  int *piVar6;
  char *pcVar7;
  undefined8 uVar8;
  double dVar9;
  undefined1 auStack_98 [32];
  char *local_78;
  char *local_70;
  char *local_68;
  char *local_60;
  char *local_58;
  char *local_50;
  char *local_48;
  char *local_40;
  ulonglong local_28;
  
  local_28 = DAT_180032178 ^ (ulonglong)auStack_98;
  uVar1 = (ulonglong)param_3;
  if (param_2 != 3) {
    return 0;
  }
  uVar5 = 2;
  if (DAT_180031780 < 0x10) {
    uVar8 = 8;
    iVar2 = FUN_180021730(param_1,&local_78,8,2);
    if (iVar2 != 8) goto LAB_18001e9b2;
    lVar3 = FUN_1800216c0(local_70);
    if (lVar3 == 0) goto LAB_18001e9df;
    if (*local_68 == DAT_180031787) goto LAB_18001ea0a;
    pvVar4 = calloc(1,0x70);
    uVar5 = FUN_180022020((longlong)pvVar4,param_3,uVar8,uVar5);
    if ((int)uVar5 != 0) {
      return 0xffffffff;
    }
    piVar6 = FUN_180021a60(3);
    FUN_180023c20(piVar6,pvVar4);
    FUN_180022050((longlong)pvVar4,local_78,0xd,param_3);
    *(longlong *)((longlong)pvVar4 + 0x10) = lVar3;
    dVar9 = atof(local_68);
    *(double *)((longlong)pvVar4 + 0x18) = dVar9;
    pcVar7 = FUN_180023030(local_60);
    FUN_180022050((longlong)pvVar4 + 0x20,pcVar7,0x14,param_3);
    dVar9 = atof(local_58);
    *(double *)((longlong)pvVar4 + 0x38) = dVar9;
    pcVar7 = FUN_180023030(local_50);
    FUN_180022050((longlong)pvVar4 + 0x40,pcVar7,0x14,param_3);
  }
  else {
    uVar8 = 9;
    iVar2 = FUN_180021730(param_1,&local_78,9,2);
    if (iVar2 != 9) {
LAB_18001e9b2:
      FUN_1800220b0(0,"LINE %d - No. of entries wrong",uVar1,uVar5);
      return 0xffffffff;
    }
    lVar3 = FUN_1800216c0(local_68);
    if (lVar3 == 0) {
LAB_18001e9df:
      FUN_1800220b0(0,"LINE %d - unknown CID",uVar1,uVar5);
      return 0xffffffff;
    }
    if (*local_60 == DAT_180031787) {
LAB_18001ea0a:
      FUN_1800220b0(0,"LINE %d - missing VALUE",uVar1,uVar5);
      return 0xffffffff;
    }
    pvVar4 = calloc(1,0x70);
    uVar5 = FUN_180022020((longlong)pvVar4,param_3,uVar8,uVar5);
    if ((int)uVar5 != 0) {
      return 0xffffffff;
    }
    piVar6 = FUN_180021a60(3);
    FUN_180023c20(piVar6,pvVar4);
    FUN_180022050((longlong)pvVar4,local_78,0xd,param_3);
    *(longlong *)((longlong)pvVar4 + 0x10) = lVar3;
    dVar9 = atof(local_60);
    *(double *)((longlong)pvVar4 + 0x18) = dVar9;
    pcVar7 = FUN_180023030(local_58);
    FUN_180022050((longlong)pvVar4 + 0x20,pcVar7,0x14,param_3);
    dVar9 = atof(local_50);
    *(double *)((longlong)pvVar4 + 0x38) = dVar9;
    pcVar7 = FUN_180023030(local_48);
    FUN_180022050((longlong)pvVar4 + 0x40,pcVar7,0x14,param_3);
    local_48 = local_40;
  }
  FUN_180022050((longlong)pvVar4 + 0x54,local_48,0x14,param_3);
  return 0;
}

/* RVA 0x1eb10, FUN_18001eb10 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18001eb10(char *param_1,int param_2,uint param_3)

{
  ulonglong uVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  void *pvVar5;
  undefined8 uVar6;
  int *piVar7;
  char *_String;
  undefined8 uVar8;
  double dVar9;
  undefined1 auStack_88 [32];
  char *local_68;
  char *local_60;
  char *local_58;
  char *local_50;
  char *local_48;
  ulonglong local_28;
  
  local_28 = DAT_180032178 ^ (ulonglong)auStack_88;
  uVar1 = (ulonglong)param_3;
  if (param_2 != 3) {
    return 0;
  }
  uVar6 = 2;
  if (DAT_180031780 < 0x10) {
    uVar8 = 5;
    iVar2 = FUN_180021730(param_1,&local_68,5,2);
    if (iVar2 != 5) {
LAB_18001ec54:
      FUN_1800220b0(0,"LINE %d - No. of entries wrong",uVar1,uVar6);
      return 0xffffffff;
    }
    uVar3 = FUN_1800215c0((longlong *)&PTR_s_UNIQUAC_180031cc0,local_68);
    if ((int)uVar3 != 0) {
LAB_18001ec81:
      FUN_1800220b0(0,"LINE %d - unknown PARAMETER",uVar1,uVar6);
      return 0xffffffff;
    }
    lVar4 = FUN_1800216c0(local_50);
    if (lVar4 == 0) {
LAB_18001ecab:
      FUN_1800220b0(0,"LINE %d - unknown CID",uVar1,uVar6);
      return 0xffffffff;
    }
    _String = local_48;
    if (*local_48 == DAT_180031787) {
LAB_18001ecda:
      FUN_1800220b0(0,"LINE %d - missing VALUE",uVar1,uVar6);
      return 0xffffffff;
    }
  }
  else {
    uVar8 = 8;
    iVar2 = FUN_180021730(param_1,&local_68,8,2);
    if (iVar2 != 8) goto LAB_18001ec54;
    uVar3 = FUN_1800215c0((longlong *)&PTR_s_UNIQUAC_180031cc0,local_68);
    if ((int)uVar3 != 0) goto LAB_18001ec81;
    lVar4 = FUN_1800216c0(local_50);
    if (lVar4 == 0) goto LAB_18001ecab;
    _String = local_48;
    if (*local_48 == DAT_180031787) goto LAB_18001ecda;
  }
  pvVar5 = calloc(1,0x30);
  uVar6 = FUN_180022020((longlong)pvVar5,param_3,uVar8,uVar6);
  if ((int)uVar6 == 0) {
    piVar7 = FUN_180021a60(4);
    FUN_180023c20(piVar7,pvVar5);
    FUN_180022050((longlong)pvVar5,local_68,0x100,param_3);
    FUN_180022050((longlong)pvVar5 + 0xd,local_60,0x100,param_3);
    iVar2 = atoi(local_58);
    *(int *)((longlong)pvVar5 + 0x1c) = iVar2;
    *(longlong *)((longlong)pvVar5 + 0x20) = lVar4;
    dVar9 = atof(_String);
    *(double *)((longlong)pvVar5 + 0x28) = dVar9;
    return 0;
  }
  return 0xffffffff;
}

/* RVA 0x1ed00, FUN_18001ed00 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18001ed00(char *param_1,int param_2,ulonglong param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  char cVar2;
  ulonglong uVar3;
  short sVar4;
  int iVar5;
  undefined8 uVar6;
  int *piVar7;
  longlong lVar8;
  undefined8 uVar9;
  void *pvVar10;
  int iVar11;
  char *pcVar12;
  int iVar13;
  undefined8 *puVar14;
  uint uVar15;
  char **ppcVar16;
  longlong *plVar17;
  undefined8 uVar18;
  undefined4 uVar19;
  double dVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  undefined1 auStack_1b8 [32];
  undefined8 local_198;
  char *local_190 [41];
  ulonglong local_48;
  
  local_48 = DAT_180032178 ^ (ulonglong)auStack_1b8;
  uVar15 = (uint)param_3;
  if (param_2 == 1) {
    uVar18 = 2;
    uVar6 = 2;
    iVar5 = FUN_180021730(param_1,&local_198,2,2);
    if (iVar5 < 3) {
      DAT_1800341e0 = calloc(1,0x48);
      uVar6 = FUN_180022020((longlong)DAT_1800341e0,uVar15,uVar6,uVar18);
      if ((int)uVar6 != 0) {
        return 0xffffffff;
      }
      piVar7 = FUN_180021a60(5);
      FUN_180023c20(piVar7,DAT_1800341e0);
    }
  }
  else if (param_2 == 3) {
    iVar5 = FUN_180021f90((longlong)param_1,"SOURCE-KEY");
    if (iVar5 == 0) {
      uVar6 = 2;
      FUN_180021730(param_1,&local_198,2,2);
      lVar8 = FUN_1800219f0(local_190[0]);
      if (lVar8 == 0) {
        FUN_1800220b0(0,"LINE %d - unknown SOURCE-KEY",param_3 & 0xffffffff,uVar6);
        return 0xffffffff;
      }
      *DAT_1800341e0 = lVar8;
    }
    else {
      iVar5 = FUN_180021f90((longlong)param_1,"COMPONENT");
      if (iVar5 == 0) {
        uVar6 = 2;
        FUN_180021730(param_1,&local_198,2,2);
        lVar8 = FUN_1800216c0(local_190[0]);
        if (lVar8 == 0) {
          FUN_1800220b0(0,"LINE %d - unknown CID",param_3 & 0xffffffff,uVar6);
          return 0xffffffff;
        }
        DAT_1800341e0[1] = lVar8;
      }
      else {
        iVar5 = FUN_180021f90((longlong)param_1,"PROPERTY");
        if (iVar5 == 0) {
          if (DAT_1800341e0[3] != 0) {
            FUN_1800220b0(0,"LINE %d - duplicate PROPERTY entry",param_3 & 0xffffffff,param_4);
          }
          plVar17 = DAT_1800341e0;
          uVar18 = 2;
          uVar6 = 0x2a;
          iVar5 = FUN_180021730(param_1,&local_198,0x2a,2);
          sVar4 = (short)iVar5 + -1;
          iVar5 = 1;
          *(short *)(plVar17 + 2) = sVar4;
          iVar13 = 1;
          if (0 < sVar4) {
            ppcVar16 = local_190;
            do {
              uVar9 = FUN_1800215c0((longlong *)&PTR_DAT_180031d00,*ppcVar16);
              if ((int)uVar9 != 0) {
                FUN_1800220b0(0,"LINE %d - unknown PROPERTY",param_3 & 0xffffffff,uVar18);
                return 0xffffffff;
              }
              iVar13 = iVar13 + 1;
              ppcVar16 = ppcVar16 + 1;
              plVar17 = DAT_1800341e0;
            } while (iVar13 <= (short)DAT_1800341e0[2]);
          }
          pvVar10 = calloc((longlong)(short)plVar17[2],0xd);
          uVar6 = FUN_180022020((longlong)pvVar10,uVar15,uVar6,uVar18);
          plVar17 = DAT_1800341e0;
          if ((int)uVar6 != 0) {
            return 0xffffffff;
          }
          DAT_1800341e0[3] = (longlong)pvVar10;
          if (0 < (short)plVar17[2]) {
            ppcVar16 = local_190;
            do {
              FUN_180022050((longlong)pvVar10,*ppcVar16,0xd,uVar15);
              ppcVar16 = ppcVar16 + 1;
              pvVar10 = (void *)((longlong)pvVar10 + 0xd);
              iVar5 = iVar5 + 1;
            } while (iVar5 <= (short)DAT_1800341e0[2]);
          }
        }
        else {
          if (0 < (short)DAT_1800341e0[2]) {
            iVar5 = FUN_180021f90((longlong)param_1,"PHASE");
            plVar17 = DAT_1800341e0;
            if (iVar5 == 0) {
              if (DAT_1800341e0[4] != 0) {
                FUN_1800220b0(0,"LINE %d - duplicate PHASE entry",param_3 & 0xffffffff,param_4);
                return 0xffffffff;
              }
              uVar18 = 2;
              uVar6 = 0x2a;
              iVar5 = FUN_180021730(param_1,&local_198,0x2a,2);
              if (iVar5 + -1 != (int)(short)plVar17[2]) {
                FUN_1800220b0(0,"LINE %d - no. of PHASES is not equal to no. of PROPERTIES",
                              param_3 & 0xffffffff,uVar18);
                return 0xffffffff;
              }
              iVar5 = 1;
              iVar13 = 1;
              if (0 < (short)plVar17[2]) {
                ppcVar16 = local_190;
                do {
                  pcVar12 = *ppcVar16;
                  if (*pcVar12 != DAT_180031787) {
                    uVar9 = FUN_1800215c0((longlong *)&PTR_DAT_1800320c8,pcVar12);
                    if ((int)uVar9 != 0) {
                      FUN_1800220b0(0,"LINE %d - unknown PHASE: %s",param_3 & 0xffffffff,pcVar12);
                      return 0xffffffff;
                    }
                    plVar17 = DAT_1800341e0;
                  }
                  iVar13 = iVar13 + 1;
                  ppcVar16 = ppcVar16 + 1;
                } while (iVar13 <= (short)plVar17[2]);
              }
              pvVar10 = calloc((longlong)(short)plVar17[2],0xd);
              uVar6 = FUN_180022020((longlong)pvVar10,uVar15,uVar6,uVar18);
              plVar17 = DAT_1800341e0;
              if ((int)uVar6 != 0) {
                return 0xffffffff;
              }
              DAT_1800341e0[4] = (longlong)pvVar10;
              if ((short)plVar17[2] < 1) {
                return 0;
              }
              ppcVar16 = local_190;
              do {
                FUN_180022050((longlong)pvVar10,*ppcVar16,0xd,uVar15);
                ppcVar16 = ppcVar16 + 1;
                pvVar10 = (void *)((longlong)pvVar10 + 0xd);
                iVar5 = iVar5 + 1;
              } while (iVar5 <= (short)DAT_1800341e0[2]);
              return 0;
            }
            if (0 < (short)DAT_1800341e0[2]) {
              iVar5 = FUN_180021f90((longlong)param_1,"UNIT");
              if (iVar5 == 0) {
                pcVar12 = param_1;
                do {
                  cVar2 = *pcVar12;
                  pcVar12[(longlong)&DAT_1800341f0 - (longlong)param_1] = cVar2;
                  plVar17 = DAT_1800341e0;
                  pcVar12 = pcVar12 + 1;
                } while (cVar2 != '\0');
                if (DAT_1800341e0[5] != 0) {
                  FUN_1800220b0(0,"LINE %d - duplicate UNIT entry",param_3 & 0xffffffff,param_4);
                  return 0xffffffff;
                }
                uVar6 = 0x2a;
                iVar5 = FUN_180021870((longlong)param_1,(longlong)&local_198,0x2a);
                if (iVar5 + -1 != (int)(short)plVar17[2]) {
                  FUN_1800220b0(0,"LINE %d - no. of UNITS is not equal to no. of PROPERTIES",
                                param_3 & 0xffffffff,param_4);
                  return 0xffffffff;
                }
                pvVar10 = calloc((longlong)(short)plVar17[2],0x14);
                uVar6 = FUN_180022020((longlong)pvVar10,uVar15,uVar6,param_4);
                plVar17 = DAT_1800341e0;
                if ((int)uVar6 != 0) {
                  return 0xffffffff;
                }
                iVar5 = 1;
                DAT_1800341e0[5] = (longlong)pvVar10;
                if ((short)plVar17[2] < 1) {
                  return 0;
                }
                ppcVar16 = local_190;
                do {
                  FUN_180022050((longlong)pvVar10,*ppcVar16,0x14,uVar15);
                  ppcVar16 = ppcVar16 + 1;
                  pvVar10 = (void *)((longlong)pvVar10 + 0x14);
                  iVar5 = iVar5 + 1;
                } while (iVar5 <= (short)DAT_1800341e0[2]);
                return 0;
              }
              if (0 < (short)DAT_1800341e0[2]) {
                iVar5 = FUN_180021f90((longlong)param_1,"ERR-UNIT");
                plVar17 = DAT_1800341e0;
                if (iVar5 == 0) {
                  if (DAT_1800341e0[6] != 0) {
                    FUN_1800220b0(0,"LINE %d - duplicate ERR-UNIT entry",param_3 & 0xffffffff,
                                  param_4);
                    return 0xffffffff;
                  }
                  uVar6 = 0x2a;
                  iVar5 = FUN_180021870((longlong)param_1,(longlong)&local_198,0x2a);
                  if (iVar5 + -1 == (int)(short)plVar17[2]) {
                    pvVar10 = calloc((longlong)(short)plVar17[2],0x14);
                    uVar6 = FUN_180022020((longlong)pvVar10,uVar15,uVar6,param_4);
                    plVar17 = DAT_1800341e0;
                    if ((int)uVar6 != 0) {
                      return 0xffffffff;
                    }
                    iVar5 = 1;
                    DAT_1800341e0[6] = (longlong)pvVar10;
                    if ((short)plVar17[2] < 1) {
                      return 0;
                    }
                    ppcVar16 = local_190;
                    do {
                      FUN_180022050((longlong)pvVar10,*ppcVar16,0x14,uVar15);
                      ppcVar16 = ppcVar16 + 1;
                      pvVar10 = (void *)((longlong)pvVar10 + 0x14);
                      iVar5 = iVar5 + 1;
                    } while (iVar5 <= (short)DAT_1800341e0[2]);
                    return 0;
                  }
LAB_18001f384:
                  FUN_1800220b0(0,"LINE %d - no. of ERR-UNITS is not equal to no. of PROPERTIES",
                                param_3 & 0xffffffff,param_4);
                  return 0xffffffff;
                }
                if (0 < (short)DAT_1800341e0[2]) {
                  iVar5 = FUN_180021f90((longlong)param_1,"ERROR");
                  plVar17 = DAT_1800341e0;
                  if (iVar5 == 0) {
                    iVar5 = 1;
                    if (DAT_1800341e0[6] == 0) {
                      param_4 = 1;
                      uVar6 = 0x2a;
                      iVar13 = FUN_180021730(&DAT_1800341f0,&local_198,0x2a,1);
                      if (iVar13 + -1 != (int)(short)plVar17[2]) goto LAB_18001f384;
                      pvVar10 = calloc((longlong)(short)plVar17[2],0x14);
                      uVar6 = FUN_180022020((longlong)pvVar10,uVar15,uVar6,param_4);
                      plVar17 = DAT_1800341e0;
                      if (((int)uVar6 == 0) &&
                         (DAT_1800341e0[6] = (longlong)pvVar10, 0 < (short)plVar17[2])) {
                        ppcVar16 = local_190;
                        iVar13 = iVar5;
                        do {
                          FUN_180022050((longlong)pvVar10,*ppcVar16,0x14,uVar15);
                          ppcVar16 = ppcVar16 + 1;
                          pvVar10 = (void *)((longlong)pvVar10 + 0x14);
                          iVar13 = iVar13 + 1;
                          plVar17 = DAT_1800341e0;
                        } while (iVar13 <= (short)DAT_1800341e0[2]);
                      }
                      DAT_1800341f0 = 0;
                    }
                    uVar18 = 2;
                    uVar6 = 0x2a;
                    iVar13 = FUN_180021730(param_1,&local_198,0x2a,2);
                    iVar11 = (int)(short)plVar17[2];
                    if (iVar13 + -1 == iVar11) {
                      sVar4 = (short)plVar17[8];
                      if (*(short *)((longlong)plVar17 + 0x42) == sVar4) {
                        if (sVar4 == 0) {
                          pvVar10 = calloc((longlong)(iVar11 * 10),0x10);
                        }
                        else {
                          pvVar10 = realloc((void *)plVar17[7],
                                            (longlong)((sVar4 + 10) * iVar11) << 4);
                        }
                        uVar6 = FUN_180022020((longlong)pvVar10,uVar15,uVar6,uVar18);
                        plVar17 = DAT_1800341e0;
                        if ((int)uVar6 != 0) {
                          return 0xffffffff;
                        }
                        *(short *)(DAT_1800341e0 + 8) = (short)DAT_1800341e0[8] + 10;
                        plVar17[7] = (longlong)pvVar10;
                      }
                      else {
                        pvVar10 = (void *)plVar17[7];
                      }
                      if (pvVar10 == (void *)0x0) {
                        return 0;
                      }
                      DAT_1800341e8 =
                           (void *)((longlong)pvVar10 +
                                   (longlong)
                                   ((int)*(short *)((longlong)plVar17 + 0x42) *
                                   (int)(short)plVar17[2]) * 0x10);
                      if ((short)plVar17[2] < 1) {
                        return 0;
                      }
                      uVar22 = (undefined4)DAT_180029478;
                      uVar3 = (ulonglong)DAT_180029478 >> 0x20;
                      ppcVar16 = local_190;
                      puVar14 = (undefined8 *)((longlong)DAT_1800341e8 + 8);
                      do {
                        if (**ppcVar16 == DAT_180031787) {
                          uVar19 = uVar22;
                          uVar21 = (int)uVar3;
                        }
                        else {
                          dVar20 = atof(*ppcVar16);
                          plVar17 = DAT_1800341e0;
                          uVar19 = SUB84(dVar20,0);
                          uVar21 = (int)((ulonglong)dVar20 >> 0x20);
                        }
                        *puVar14 = CONCAT44(uVar21,uVar19);
                        iVar5 = iVar5 + 1;
                        puVar14 = puVar14 + 2;
                        ppcVar16 = ppcVar16 + 1;
                      } while (iVar5 <= (short)plVar17[2]);
                      return 0;
                    }
LAB_18001f57c:
                    FUN_1800220b0(0,"LINE %d - no. of DATA is not equal to no. of PROPERTIES",
                                  param_3 & 0xffffffff,uVar18);
                    return 0xffffffff;
                  }
                  if ((0 < (short)DAT_1800341e0[2]) &&
                     (iVar5 = FUN_180021f90((longlong)param_1,"DATA"), iVar5 == 0)) {
                    uVar18 = 2;
                    iVar5 = FUN_180021730(param_1,&local_198,0x2a,2);
                    iVar13 = (int)(short)DAT_1800341e0[2];
                    if (iVar5 + -1 == iVar13) {
                      sVar4 = (short)DAT_1800341e0[8];
                      if (*(short *)((longlong)DAT_1800341e0 + 0x42) == sVar4) {
                        plVar17 = DAT_1800341e0;
                        if (sVar4 == 0) {
                          pvVar10 = calloc((longlong)(iVar13 * 10),0x10);
                        }
                        else {
                          pvVar10 = realloc((void *)DAT_1800341e0[7],
                                            (longlong)((sVar4 + 10) * iVar13) << 4);
                        }
                        uVar6 = FUN_180022020((longlong)pvVar10,uVar15,plVar17,uVar18);
                        plVar17 = DAT_1800341e0;
                        if ((int)uVar6 != 0) {
                          return 0xffffffff;
                        }
                        *(short *)(DAT_1800341e0 + 8) = (short)DAT_1800341e0[8] + 10;
                        plVar17[7] = (longlong)pvVar10;
                      }
                      else {
                        pvVar10 = (void *)DAT_1800341e0[7];
                        plVar17 = DAT_1800341e0;
                      }
                      if (pvVar10 == (void *)0x0) {
                        return 0;
                      }
                      iVar5 = 1;
                      puVar14 = (undefined8 *)
                                ((longlong)pvVar10 +
                                (longlong)
                                ((int)*(short *)((longlong)plVar17 + 0x42) * (int)(short)plVar17[2])
                                * 0x10);
                      if (0 < (short)plVar17[2]) {
                        uVar22 = (undefined4)DAT_180029478;
                        uVar3 = (ulonglong)DAT_180029478 >> 0x20;
                        ppcVar16 = local_190;
                        lVar8 = (longlong)DAT_1800341e8;
                        do {
                          if (**ppcVar16 == DAT_180031787) {
                            uVar19 = uVar22;
                            uVar21 = (int)uVar3;
                          }
                          else {
                            dVar20 = atof(*ppcVar16);
                            plVar17 = DAT_1800341e0;
                            uVar19 = SUB84(dVar20,0);
                            uVar21 = (int)((ulonglong)dVar20 >> 0x20);
                          }
                          *puVar14 = CONCAT44(uVar21,uVar19);
                          if (lVar8 != 0) {
                            puVar1 = (undefined8 *)(lVar8 + 8);
                            lVar8 = lVar8 + 0x10;
                            puVar14[1] = *puVar1;
                          }
                          puVar14 = puVar14 + 2;
                          iVar5 = iVar5 + 1;
                          ppcVar16 = ppcVar16 + 1;
                        } while (iVar5 <= (short)plVar17[2]);
                      }
                      *(short *)((longlong)plVar17 + 0x42) =
                           *(short *)((longlong)plVar17 + 0x42) + 1;
                      return 0;
                    }
                    goto LAB_18001f57c;
                  }
                }
              }
            }
          }
          FUN_1800220b0(0,"LINE %d - unrecognized keyword in TABLE \n",param_3 & 0xffffffff,param_4)
          ;
        }
      }
    }
  }
  else if (param_2 == 2) {
    if (*(short *)((longlong)DAT_1800341e0 + 0x42) < (short)DAT_1800341e0[8]) {
      pvVar10 = realloc((void *)DAT_1800341e0[7],
                        (longlong)
                        ((int)(short)DAT_1800341e0[2] *
                        (int)*(short *)((longlong)DAT_1800341e0 + 0x42)) << 4);
      uVar6 = FUN_180022020((longlong)pvVar10,uVar15,param_3,param_4);
      if ((int)uVar6 == 0) {
        *(undefined2 *)(DAT_1800341e0 + 8) = *(undefined2 *)((longlong)DAT_1800341e0 + 0x42);
        DAT_1800341e0[7] = (longlong)pvVar10;
      }
    }
    DAT_1800341e0 = (longlong *)0x0;
    DAT_1800341e8 = (void *)0x0;
  }
  return 0;
}

/* RVA 0x1f740, FUN_18001f740 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18001f740(char *param_1,int param_2,uint param_3,undefined8 param_4)

{
  char *pcVar1;
  ulonglong uVar2;
  short sVar3;
  int iVar4;
  undefined8 uVar5;
  int *piVar6;
  longlong lVar7;
  undefined8 uVar8;
  void *pvVar9;
  double *pdVar10;
  char **ppcVar11;
  undefined8 uVar12;
  int iVar13;
  longlong *plVar14;
  double dVar15;
  undefined1 auStack_1a8 [32];
  undefined8 local_188;
  char *local_180 [41];
  ulonglong local_38;
  
  local_38 = DAT_180032178 ^ (ulonglong)auStack_1a8;
  uVar2 = (ulonglong)param_3;
  if (param_2 == 1) {
    uVar12 = 2;
    uVar5 = 2;
    iVar4 = FUN_180021730(param_1,&local_188,2,2);
    if (2 < iVar4) {
      return 0;
    }
    DAT_180034290 = calloc(1,0x90);
    uVar5 = FUN_180022020((longlong)DAT_180034290,param_3,uVar5,uVar12);
    if ((int)uVar5 == 0) {
      piVar6 = FUN_180021a60(6);
      FUN_180023c20(piVar6,DAT_180034290);
      return 0;
    }
    return 0xffffffff;
  }
  if (param_2 != 3) {
    if (param_2 == 2) {
      DAT_180034290 = (longlong *)0x0;
      return 0;
    }
    return 0;
  }
  iVar4 = FUN_180021f90((longlong)param_1,"SOURCE-KEY");
  if (iVar4 == 0) {
    uVar5 = 2;
    FUN_180021730(param_1,&local_188,2,2);
    lVar7 = FUN_1800219f0(local_180[0]);
    if (lVar7 == 0) {
      FUN_1800220b0(0,"LINE %d - unknown SOURCE-KEY",uVar2,uVar5);
      return 0xffffffff;
    }
    *DAT_180034290 = lVar7;
    return 0;
  }
  iVar4 = FUN_180021f90((longlong)param_1,"COMPONENT");
  if (iVar4 == 0) {
    uVar5 = 2;
    FUN_180021730(param_1,&local_188,2,2);
    lVar7 = FUN_1800216c0(local_180[0]);
    if (lVar7 == 0) {
      FUN_1800220b0(0,"LINE %d - unknown CID",uVar2,uVar5);
      return 0xffffffff;
    }
    DAT_180034290[1] = lVar7;
    return 0;
  }
  iVar4 = FUN_180021f90((longlong)param_1,"NAME");
  if (iVar4 == 0) {
    uVar5 = 2;
    iVar4 = FUN_180021730(param_1,&local_188,2,2);
    if (iVar4 != 2) {
      return 0;
    }
    uVar12 = FUN_1800215c0((longlong *)&PTR_s_POLYNOM_180031ee0,local_180[0]);
    if ((int)uVar12 == 0) {
      FUN_180022050((longlong)(DAT_180034290 + 2),local_180[0],0xd,param_3);
      return 0;
    }
    FUN_1800220b0(0,"LINE %d - unknown FUNCTION",uVar2,uVar5);
    return 0xffffffff;
  }
  iVar4 = FUN_180021f90((longlong)param_1,"PROPERTY");
  plVar14 = DAT_180034290;
  if (iVar4 == 0) {
    if (DAT_180034290[7] != 0) {
      FUN_1800220b0(0,"LINE %d - duplicate PROPERTY entry",uVar2,param_4);
      return 0xffffffff;
    }
    uVar12 = 2;
    uVar5 = 0x2a;
    iVar4 = FUN_180021730(param_1,&local_188,0x2a,2);
    sVar3 = (short)iVar4 + -1;
    iVar4 = 1;
    *(short *)((longlong)plVar14 + 0x8a) = sVar3;
    iVar13 = 1;
    if (0 < sVar3) {
      ppcVar11 = local_180;
      do {
        uVar8 = FUN_1800215c0((longlong *)&PTR_DAT_180031d00,*ppcVar11);
        if ((int)uVar8 != 0) {
          FUN_1800220b0(0,"LINE %d - unknown PROPERTY",uVar2,uVar12);
          return 0xffffffff;
        }
        iVar13 = iVar13 + 1;
        ppcVar11 = ppcVar11 + 1;
        plVar14 = DAT_180034290;
      } while (iVar13 <= *(short *)((longlong)DAT_180034290 + 0x8a));
    }
    pvVar9 = calloc((longlong)(*(short *)((longlong)plVar14 + 0x8a) + 1),0xd);
    uVar5 = FUN_180022020((longlong)pvVar9,param_3,uVar5,uVar12);
    plVar14 = DAT_180034290;
    if ((int)uVar5 != 0) {
      return 0xffffffff;
    }
    DAT_180034290[7] = (longlong)pvVar9;
    if (*(short *)((longlong)plVar14 + 0x8a) < 1) {
      return 0;
    }
    ppcVar11 = local_180;
    do {
      FUN_180022050((longlong)pvVar9,*ppcVar11,0xd,param_3);
      ppcVar11 = ppcVar11 + 1;
      pvVar9 = (void *)((longlong)pvVar9 + 0xd);
      iVar4 = iVar4 + 1;
    } while (iVar4 <= *(short *)((longlong)DAT_180034290 + 0x8a));
    return 0;
  }
  if (0 < *(short *)((longlong)DAT_180034290 + 0x8a)) {
    iVar4 = FUN_180021f90((longlong)param_1,"PHASE");
    plVar14 = DAT_180034290;
    if (iVar4 == 0) {
      if (DAT_180034290[8] != 0) {
        FUN_1800220b0(0,"LINE %d - duplicate PHASE entry",uVar2,param_4);
        return 0xffffffff;
      }
      uVar12 = 2;
      uVar5 = 0x2a;
      iVar4 = FUN_180021730(param_1,&local_188,0x2a,2);
      if (iVar4 + -1 != (int)*(short *)((longlong)plVar14 + 0x8a)) {
        FUN_1800220b0(0,"LINE %d - no. of PHASES is not equal to no. of PROPERTIES",uVar2,uVar12);
        return 0xffffffff;
      }
      iVar4 = 1;
      iVar13 = 1;
      if (0 < *(short *)((longlong)plVar14 + 0x8a)) {
        ppcVar11 = local_180;
        do {
          pcVar1 = *ppcVar11;
          if (*pcVar1 != DAT_180031787) {
            uVar8 = FUN_1800215c0((longlong *)&PTR_DAT_1800320c8,pcVar1);
            if ((int)uVar8 != 0) {
              FUN_1800220b0(0,"LINE %d - unknown PHASE: %s",uVar2,pcVar1);
              return 0xffffffff;
            }
            plVar14 = DAT_180034290;
          }
          iVar13 = iVar13 + 1;
          ppcVar11 = ppcVar11 + 1;
        } while (iVar13 <= *(short *)((longlong)plVar14 + 0x8a));
      }
      pvVar9 = calloc((longlong)*(short *)((longlong)plVar14 + 0x8a),0xd);
      uVar5 = FUN_180022020((longlong)pvVar9,param_3,uVar5,uVar12);
      plVar14 = DAT_180034290;
      if ((int)uVar5 != 0) {
        return 0xffffffff;
      }
      DAT_180034290[8] = (longlong)pvVar9;
      if (*(short *)((longlong)plVar14 + 0x8a) < 1) {
        return 0;
      }
      ppcVar11 = local_180;
      do {
        FUN_180022050((longlong)pvVar9,*ppcVar11,0xd,param_3);
        ppcVar11 = ppcVar11 + 1;
        pvVar9 = (void *)((longlong)pvVar9 + 0xd);
        iVar4 = iVar4 + 1;
      } while (iVar4 <= *(short *)((longlong)DAT_180034290 + 0x8a));
      return 0;
    }
    if ((0 < *(short *)((longlong)DAT_180034290 + 0x8a)) &&
       (iVar4 = FUN_180021f90((longlong)param_1,"UNIT"), plVar14 = DAT_180034290, iVar4 == 0)) {
      if (DAT_180034290[9] != 0) {
        FUN_1800220b0(0,"LINE %d - duplicate UNIT entry",uVar2,param_4);
        return 0xffffffff;
      }
      uVar5 = 0x2a;
      iVar4 = FUN_180021870((longlong)param_1,(longlong)&local_188,0x2a);
      if (iVar4 + -1 != (int)*(short *)((longlong)plVar14 + 0x8a)) {
        FUN_1800220b0(0,"LINE %d - no. of UNITS is not equal to no. of PROPERTIES",uVar2,param_4);
        return 0xffffffff;
      }
      pvVar9 = calloc((longlong)(*(short *)((longlong)plVar14 + 0x8a) + 1),0x14);
      uVar5 = FUN_180022020((longlong)pvVar9,param_3,uVar5,param_4);
      plVar14 = DAT_180034290;
      if ((int)uVar5 != 0) {
        return 0xffffffff;
      }
      iVar4 = 1;
      DAT_180034290[9] = (longlong)pvVar9;
      if (*(short *)((longlong)plVar14 + 0x8a) < 1) {
        return 0;
      }
      ppcVar11 = local_180;
      do {
        FUN_180022050((longlong)pvVar9,*ppcVar11,0x14,param_3);
        ppcVar11 = ppcVar11 + 1;
        pvVar9 = (void *)((longlong)pvVar9 + 0x14);
        iVar4 = iVar4 + 1;
      } while (iVar4 <= *(short *)((longlong)DAT_180034290 + 0x8a));
      return 0;
    }
  }
  iVar4 = FUN_180021f90((longlong)param_1,"ERR-UNIT");
  if (iVar4 == 0) {
    iVar4 = FUN_180021870((longlong)param_1,(longlong)&local_188,0x2a);
    if (iVar4 == 2) {
      FUN_180022050((longlong)(DAT_180034290 + 10),local_180[0],0x14,param_3);
    }
  }
  else {
    iVar4 = FUN_180021f90((longlong)param_1,"ERROR");
    if (iVar4 == 0) {
      iVar4 = FUN_180021730(param_1,&local_188,2,2);
      if (iVar4 == 2) {
        if (*local_180[0] == DAT_180031787) {
          FUN_180022050((longlong)(DAT_180034290 + 10),"$",0x14,param_3);
        }
        else {
          dVar15 = atof(local_180[0]);
          DAT_180034290[0xd] = (longlong)dVar15;
        }
      }
    }
    else {
      iVar4 = FUN_180021f90((longlong)param_1,"LOWER-BOUND");
      plVar14 = DAT_180034290;
      if (iVar4 == 0) {
        if (DAT_180034290[0xe] != 0) {
          FUN_1800220b0(0,"LINE %d - duplicate LOWER-BOUND entry",uVar2,param_4);
          return 0xffffffff;
        }
        uVar12 = 2;
        uVar5 = 0x2a;
        iVar4 = FUN_180021730(param_1,&local_188,0x2a,2);
        iVar13 = *(short *)((longlong)plVar14 + 0x8a) + -1;
        if (iVar4 + -1 != iVar13) {
          FUN_1800220b0(0,"LINE %d - no. of LOWER-BOUNDS is not equal to no. of X-PROPERTIES",uVar2,
                        uVar12);
          return 0xffffffff;
        }
        pdVar10 = calloc((longlong)iVar13,8);
        uVar5 = FUN_180022020((longlong)pdVar10,param_3,uVar5,uVar12);
        plVar14 = DAT_180034290;
        if ((int)uVar5 != 0) {
          return 0xffffffff;
        }
        iVar4 = 1;
        DAT_180034290[0xe] = (longlong)pdVar10;
        if (0 < *(short *)((longlong)plVar14 + 0x8a) + -1) {
          ppcVar11 = local_180;
          do {
            dVar15 = atof(*ppcVar11);
            plVar14 = DAT_180034290;
            iVar4 = iVar4 + 1;
            *pdVar10 = dVar15;
            pdVar10 = pdVar10 + 1;
            ppcVar11 = ppcVar11 + 1;
          } while (iVar4 <= *(short *)((longlong)plVar14 + 0x8a) + -1);
        }
      }
      else {
        iVar4 = FUN_180021f90((longlong)param_1,"UPPER-BOUND");
        plVar14 = DAT_180034290;
        if (iVar4 == 0) {
          if (DAT_180034290[0xf] != 0) {
            FUN_1800220b0(0,"LINE %d - duplicate UPPER-BOUND entry",uVar2,param_4);
            return 0xffffffff;
          }
          uVar12 = 2;
          uVar5 = 0x2a;
          iVar4 = FUN_180021730(param_1,&local_188,0x2a,2);
          iVar13 = *(short *)((longlong)plVar14 + 0x8a) + -1;
          if (iVar4 + -1 != iVar13) {
            FUN_1800220b0(0,"LINE %d - no. of UPPER-BOUNDS is not equal to no. of X-PROPERTIES",
                          uVar2,uVar12);
            return 0xffffffff;
          }
          pdVar10 = calloc((longlong)iVar13,8);
          uVar5 = FUN_180022020((longlong)pdVar10,param_3,uVar5,uVar12);
          plVar14 = DAT_180034290;
          if ((int)uVar5 != 0) {
            return 0xffffffff;
          }
          iVar4 = 1;
          DAT_180034290[0xf] = (longlong)pdVar10;
          if (0 < *(short *)((longlong)plVar14 + 0x8a) + -1) {
            ppcVar11 = local_180;
            do {
              dVar15 = atof(*ppcVar11);
              plVar14 = DAT_180034290;
              iVar4 = iVar4 + 1;
              *pdVar10 = dVar15;
              pdVar10 = pdVar10 + 1;
              ppcVar11 = ppcVar11 + 1;
            } while (iVar4 <= *(short *)((longlong)plVar14 + 0x8a) + -1);
          }
        }
        else {
          iVar4 = FUN_180021f90((longlong)param_1,"COEFFICIENTS");
          plVar14 = DAT_180034290;
          if (iVar4 == 0) {
            if (DAT_180034290[0x10] != 0) {
              FUN_1800220b0(0,"LINE %d - duplicate COEFFICIENTS entry",uVar2,param_4);
              return 0xffffffff;
            }
            uVar12 = 2;
            uVar5 = 0x2a;
            iVar4 = FUN_180021730(param_1,&local_188,0x2a,2);
            sVar3 = (short)iVar4 + -1;
            *(short *)(plVar14 + 0x11) = sVar3;
            pdVar10 = calloc((longlong)sVar3,8);
            uVar5 = FUN_180022020((longlong)pdVar10,param_3,uVar5,uVar12);
            plVar14 = DAT_180034290;
            if ((int)uVar5 != 0) {
              return 0xffffffff;
            }
            iVar4 = 1;
            DAT_180034290[0x10] = (longlong)pdVar10;
            if (0 < (short)plVar14[0x11]) {
              ppcVar11 = local_180;
              do {
                dVar15 = atof(*ppcVar11);
                plVar14 = DAT_180034290;
                iVar4 = iVar4 + 1;
                *pdVar10 = dVar15;
                pdVar10 = pdVar10 + 1;
                ppcVar11 = ppcVar11 + 1;
              } while (iVar4 <= (short)plVar14[0x11]);
            }
          }
          else {
            FUN_1800220b0(0,"LINE %d - unrecognized keyword in FUNCTION \n",uVar2,param_4);
          }
        }
      }
    }
  }
  return 0;
}

/* RVA 0x20100, FUN_180020100 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180020100(char *param_1,int param_2,ulonglong param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  char cVar2;
  short sVar3;
  int iVar4;
  undefined8 uVar5;
  int *piVar6;
  longlong lVar7;
  longlong *plVar8;
  undefined8 uVar9;
  void *pvVar10;
  int iVar11;
  char *pcVar12;
  longlong *plVar13;
  undefined8 *puVar14;
  uint uVar15;
  ulonglong uVar16;
  char **ppcVar17;
  int iVar18;
  undefined8 uVar19;
  undefined4 uVar20;
  double dVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  undefined1 auStack_1b8 [32];
  undefined8 local_198;
  char *local_190 [41];
  ulonglong local_48;
  
  local_48 = DAT_180032178 ^ (ulonglong)auStack_1b8;
  uVar16 = param_3 & 0xffffffff;
  uVar15 = (uint)param_3;
  if (param_2 == 1) {
    uVar19 = 2;
    uVar5 = 2;
    iVar4 = FUN_180021730(param_1,&local_198,2,2);
    if (iVar4 < 3) {
      DAT_180034298 = calloc(1,0x60);
      uVar5 = FUN_180022020((longlong)DAT_180034298,uVar15,uVar5,uVar19);
      if ((int)uVar5 != 0) {
        return 0xffffffff;
      }
      piVar6 = FUN_180021a60(7);
      FUN_180023c20(piVar6,DAT_180034298);
    }
  }
  else if (param_2 == 3) {
    iVar4 = FUN_180021f90((longlong)param_1,"SOURCE-KEY");
    if (iVar4 == 0) {
      uVar5 = 2;
      FUN_180021730(param_1,&local_198,2,2);
      lVar7 = FUN_1800219f0(local_190[0]);
      if (lVar7 == 0) {
        FUN_1800220b0(0,"LINE %d - unknown SOURCE-KEY",uVar16,uVar5);
        return 0xffffffff;
      }
      *DAT_180034298 = lVar7;
    }
    else {
      iVar4 = FUN_180021f90((longlong)param_1,"COMPONENTS");
      if (iVar4 == 0) {
        uVar5 = 0x2a;
        iVar4 = FUN_180021870((longlong)param_1,(longlong)&local_198,0x2a);
        *(short *)(DAT_180034298 + 1) = (short)iVar4 + -1;
        plVar8 = calloc((longlong)(iVar4 + -1),8);
        uVar5 = FUN_180022020((longlong)plVar8,uVar15,uVar5,param_4);
        plVar13 = DAT_180034298;
        if ((int)uVar5 != 0) {
          return 0xffffffff;
        }
        iVar4 = 1;
        DAT_180034298[2] = (longlong)plVar8;
        if (0 < (short)plVar13[1]) {
          ppcVar17 = local_190;
          do {
            FUN_180021620(*ppcVar17);
            lVar7 = FUN_1800216c0(*ppcVar17);
            if (lVar7 == 0) {
              FUN_1800220b0(0,"LINE %d - unknown CID",uVar16,param_4);
              return 0xffffffff;
            }
            *plVar8 = lVar7;
            iVar4 = iVar4 + 1;
            plVar8 = plVar8 + 1;
            ppcVar17 = ppcVar17 + 1;
          } while (iVar4 <= (short)DAT_180034298[1]);
        }
      }
      else {
        iVar4 = FUN_180021f90((longlong)param_1,"PROPERTY");
        if (iVar4 == 0) {
          if (DAT_180034298[4] != 0) {
            FUN_1800220b0(0,"LINE %d - duplicate PROPERTY entry",uVar16,param_4);
          }
          plVar13 = DAT_180034298;
          uVar19 = 2;
          uVar5 = 0x2a;
          iVar4 = FUN_180021730(param_1,&local_198,0x2a,2);
          sVar3 = (short)iVar4 + -1;
          iVar18 = 1;
          *(short *)(plVar13 + 3) = sVar3;
          iVar4 = 1;
          if (0 < sVar3) {
            ppcVar17 = local_190;
            do {
              uVar9 = FUN_1800215c0((longlong *)&PTR_DAT_180031f70,*ppcVar17);
              if ((int)uVar9 != 0) {
                FUN_1800220b0(0,"LINE %d - unknown PROPERTY",uVar16,uVar19);
                return 0xffffffff;
              }
              iVar4 = iVar4 + 1;
              ppcVar17 = ppcVar17 + 1;
              plVar13 = DAT_180034298;
            } while (iVar4 <= (short)DAT_180034298[3]);
          }
          pvVar10 = calloc((longlong)(short)plVar13[3],0xd);
          uVar5 = FUN_180022020((longlong)pvVar10,uVar15,uVar5,uVar19);
          plVar13 = DAT_180034298;
          if ((int)uVar5 != 0) {
            return 0xffffffff;
          }
          DAT_180034298[4] = (longlong)pvVar10;
          if (0 < (short)plVar13[3]) {
            ppcVar17 = local_190;
            do {
              FUN_180022050((longlong)pvVar10,*ppcVar17,0xd,uVar15);
              ppcVar17 = ppcVar17 + 1;
              pvVar10 = (void *)((longlong)pvVar10 + 0xd);
              iVar18 = iVar18 + 1;
            } while (iVar18 <= (short)DAT_180034298[3]);
          }
        }
        else if (((short)DAT_180034298[3] < 1) ||
                (iVar4 = FUN_180021f90((longlong)param_1,"PHASE"), plVar13 = DAT_180034298,
                iVar4 != 0)) {
          iVar4 = FUN_180021f90((longlong)param_1,"STATE");
          if (iVar4 == 0) {
            uVar5 = 2;
            iVar4 = FUN_180021730(param_1,&local_198,2,2);
            if (iVar4 == 2) {
              uVar19 = FUN_1800215c0((longlong *)&PTR_DAT_180032080,local_190[0]);
              if ((int)uVar19 != 0) {
                FUN_1800220b0(0,"LINE %d - unknown STATE",uVar16,uVar5);
                return 0xffffffff;
              }
              FUN_180022050((longlong)(DAT_180034298 + 7),local_190[0],0xd,uVar15);
            }
          }
          else {
            if (0 < (short)DAT_180034298[3]) {
              iVar4 = FUN_180021f90((longlong)param_1,"UNIT");
              if (iVar4 == 0) {
                pcVar12 = param_1;
                do {
                  cVar2 = *pcVar12;
                  pcVar12[(longlong)&DAT_1800342b0 - (longlong)param_1] = cVar2;
                  plVar13 = DAT_180034298;
                  pcVar12 = pcVar12 + 1;
                } while (cVar2 != '\0');
                if (DAT_180034298[6] != 0) {
                  FUN_1800220b0(0,"LINE %d - duplicate UNIT entry",uVar16,param_4);
                  return 0xffffffff;
                }
                uVar5 = 0x2a;
                iVar4 = FUN_180021870((longlong)param_1,(longlong)&local_198,0x2a);
                if (iVar4 + -1 != (int)(short)plVar13[3]) {
                  FUN_1800220b0(0,"LINE %d - no. of UNITS is not equal to no. of PROPERTIES",uVar16,
                                param_4);
                  return 0xffffffff;
                }
                pvVar10 = calloc((longlong)(short)plVar13[3],0x14);
                uVar5 = FUN_180022020((longlong)pvVar10,uVar15,uVar5,param_4);
                plVar13 = DAT_180034298;
                if ((int)uVar5 != 0) {
                  return 0xffffffff;
                }
                iVar4 = 1;
                DAT_180034298[6] = (longlong)pvVar10;
                if ((short)plVar13[3] < 1) {
                  return 0;
                }
                ppcVar17 = local_190;
                do {
                  FUN_180022050((longlong)pvVar10,*ppcVar17,0x14,uVar15);
                  ppcVar17 = ppcVar17 + 1;
                  pvVar10 = (void *)((longlong)pvVar10 + 0x14);
                  iVar4 = iVar4 + 1;
                } while (iVar4 <= (short)DAT_180034298[3]);
                return 0;
              }
              if (0 < (short)DAT_180034298[3]) {
                iVar4 = FUN_180021f90((longlong)param_1,"ERR-UNIT");
                plVar13 = DAT_180034298;
                if (iVar4 == 0) {
                  if (DAT_180034298[9] != 0) {
                    FUN_1800220b0(0,"LINE %d - duplicate ERR-UNIT entry",uVar16,param_4);
                    return 0xffffffff;
                  }
                  uVar5 = 0x2a;
                  iVar4 = FUN_180021870((longlong)param_1,(longlong)&local_198,0x2a);
                  if (iVar4 + -1 == (int)(short)plVar13[3]) {
                    pvVar10 = calloc((longlong)(short)plVar13[3],0x14);
                    uVar5 = FUN_180022020((longlong)pvVar10,uVar15,uVar5,param_4);
                    plVar13 = DAT_180034298;
                    if ((int)uVar5 != 0) {
                      return 0xffffffff;
                    }
                    iVar4 = 1;
                    DAT_180034298[9] = (longlong)pvVar10;
                    if ((short)plVar13[3] < 1) {
                      return 0;
                    }
                    ppcVar17 = local_190;
                    do {
                      FUN_180022050((longlong)pvVar10,*ppcVar17,0x14,uVar15);
                      ppcVar17 = ppcVar17 + 1;
                      pvVar10 = (void *)((longlong)pvVar10 + 0x14);
                      iVar4 = iVar4 + 1;
                    } while (iVar4 <= (short)DAT_180034298[3]);
                    return 0;
                  }
LAB_180020864:
                  FUN_1800220b0(0,"LINE %d - no. of ERR-UNITS is not equal to no. of PROPERTIES",
                                uVar16,param_4);
                  return 0xffffffff;
                }
                if (0 < (short)DAT_180034298[3]) {
                  iVar4 = FUN_180021f90((longlong)param_1,"ERROR");
                  plVar13 = DAT_180034298;
                  if (iVar4 == 0) {
                    iVar4 = 1;
                    if (DAT_180034298[9] == 0) {
                      param_4 = 1;
                      uVar5 = 0x2a;
                      iVar18 = FUN_180021730(&DAT_1800342b0,&local_198,0x2a,1);
                      if (iVar18 + -1 != (int)(short)plVar13[3]) goto LAB_180020864;
                      pvVar10 = calloc((longlong)(short)plVar13[3],0x14);
                      uVar5 = FUN_180022020((longlong)pvVar10,uVar15,uVar5,param_4);
                      plVar13 = DAT_180034298;
                      if (((int)uVar5 == 0) &&
                         (DAT_180034298[9] = (longlong)pvVar10, 0 < (short)plVar13[3])) {
                        ppcVar17 = local_190;
                        iVar18 = iVar4;
                        do {
                          FUN_180022050((longlong)pvVar10,*ppcVar17,0x14,uVar15);
                          ppcVar17 = ppcVar17 + 1;
                          pvVar10 = (void *)((longlong)pvVar10 + 0x14);
                          iVar18 = iVar18 + 1;
                          plVar13 = DAT_180034298;
                        } while (iVar18 <= (short)DAT_180034298[3]);
                      }
                      DAT_1800342b0 = 0;
                    }
                    uVar19 = 2;
                    uVar5 = 0x2a;
                    iVar18 = FUN_180021730(param_1,&local_198,0x2a,2);
                    iVar11 = (int)(short)plVar13[3];
                    if (iVar18 + -1 == iVar11) {
                      sVar3 = (short)plVar13[0xb];
                      if (*(short *)((longlong)plVar13 + 0x5a) == sVar3) {
                        if (sVar3 == 0) {
                          pvVar10 = calloc((longlong)(iVar11 * 10),0x10);
                        }
                        else {
                          pvVar10 = realloc((void *)plVar13[10],
                                            (longlong)((sVar3 + 10) * iVar11) << 4);
                        }
                        uVar5 = FUN_180022020((longlong)pvVar10,uVar15,uVar5,uVar19);
                        plVar13 = DAT_180034298;
                        if ((int)uVar5 != 0) {
                          return 0xffffffff;
                        }
                        *(short *)(DAT_180034298 + 0xb) = (short)DAT_180034298[0xb] + 10;
                        plVar13[10] = (longlong)pvVar10;
                      }
                      else {
                        pvVar10 = (void *)plVar13[10];
                      }
                      if (pvVar10 == (void *)0x0) {
                        return 0;
                      }
                      DAT_180034174 =
                           (int)*(short *)((longlong)plVar13 + 0x5a) * (int)(short)plVar13[3];
                      DAT_1800342a0 = (void *)((longlong)pvVar10 + (longlong)DAT_180034174 * 0x10);
                      if ((short)plVar13[3] < 1) {
                        return 0;
                      }
                      uVar23 = (undefined4)DAT_180029478;
                      uVar16 = (ulonglong)DAT_180029478 >> 0x20;
                      ppcVar17 = local_190;
                      puVar14 = (undefined8 *)((longlong)DAT_1800342a0 + 8);
                      do {
                        if (**ppcVar17 == DAT_180031787) {
                          uVar20 = uVar23;
                          uVar22 = (int)uVar16;
                        }
                        else {
                          dVar21 = atof(*ppcVar17);
                          plVar13 = DAT_180034298;
                          uVar20 = SUB84(dVar21,0);
                          uVar22 = (int)((ulonglong)dVar21 >> 0x20);
                        }
                        *puVar14 = CONCAT44(uVar22,uVar20);
                        iVar4 = iVar4 + 1;
                        puVar14 = puVar14 + 2;
                        ppcVar17 = ppcVar17 + 1;
                      } while (iVar4 <= (short)plVar13[3]);
                      return 0;
                    }
LAB_180020a5c:
                    FUN_1800220b0(0,"LINE %d - no. of DATA is not equal to no. of PROPERTIES",uVar16
                                  ,uVar19);
                    return 0xffffffff;
                  }
                  if ((0 < (short)DAT_180034298[3]) &&
                     (iVar4 = FUN_180021f90((longlong)param_1,"DATA"), iVar4 == 0)) {
                    uVar19 = 2;
                    iVar4 = FUN_180021730(param_1,&local_198,0x2a,2);
                    iVar18 = (int)(short)DAT_180034298[3];
                    if (iVar4 + -1 == iVar18) {
                      sVar3 = (short)DAT_180034298[0xb];
                      if (*(short *)((longlong)DAT_180034298 + 0x5a) == sVar3) {
                        plVar13 = DAT_180034298;
                        if (sVar3 == 0) {
                          pvVar10 = calloc((longlong)(iVar18 * 10),0x10);
                        }
                        else {
                          pvVar10 = realloc((void *)DAT_180034298[10],
                                            (longlong)((sVar3 + 10) * iVar18) << 4);
                          if (DAT_1800342a0 != (void *)0x0) {
                            DAT_1800342a0 =
                                 (void *)((longlong)DAT_180034174 * 0x10 + (longlong)pvVar10);
                          }
                        }
                        uVar5 = FUN_180022020((longlong)pvVar10,uVar15,plVar13,uVar19);
                        plVar13 = DAT_180034298;
                        if ((int)uVar5 != 0) {
                          return 0xffffffff;
                        }
                        *(short *)(DAT_180034298 + 0xb) = (short)DAT_180034298[0xb] + 10;
                        plVar13[10] = (longlong)pvVar10;
                      }
                      else {
                        pvVar10 = (void *)DAT_180034298[10];
                        plVar13 = DAT_180034298;
                      }
                      if (pvVar10 == (void *)0x0) {
                        return 0;
                      }
                      iVar4 = 1;
                      puVar14 = (undefined8 *)
                                ((longlong)pvVar10 +
                                (longlong)
                                ((int)*(short *)((longlong)plVar13 + 0x5a) * (int)(short)plVar13[3])
                                * 0x10);
                      if (0 < (short)plVar13[3]) {
                        uVar23 = (undefined4)DAT_180029478;
                        uVar16 = (ulonglong)DAT_180029478 >> 0x20;
                        ppcVar17 = local_190;
                        pvVar10 = DAT_1800342a0;
                        do {
                          if (**ppcVar17 == DAT_180031787) {
                            uVar20 = uVar23;
                            uVar22 = (int)uVar16;
                          }
                          else {
                            dVar21 = atof(*ppcVar17);
                            plVar13 = DAT_180034298;
                            uVar20 = SUB84(dVar21,0);
                            uVar22 = (int)((ulonglong)dVar21 >> 0x20);
                          }
                          *puVar14 = CONCAT44(uVar22,uVar20);
                          if (pvVar10 != (void *)0x0) {
                            puVar1 = (undefined8 *)((longlong)pvVar10 + 8);
                            pvVar10 = (void *)((longlong)pvVar10 + 0x10);
                            puVar14[1] = *puVar1;
                          }
                          puVar14 = puVar14 + 2;
                          iVar4 = iVar4 + 1;
                          ppcVar17 = ppcVar17 + 1;
                        } while (iVar4 <= (short)plVar13[3]);
                      }
                      *(short *)((longlong)plVar13 + 0x5a) =
                           *(short *)((longlong)plVar13 + 0x5a) + 1;
                      return 0;
                    }
                    goto LAB_180020a5c;
                  }
                }
              }
            }
            FUN_1800220b0(0,"LINE %d - unrecognized keyword in TABLE \n",uVar16,param_4);
          }
        }
        else {
          if (DAT_180034298[5] != 0) {
            FUN_1800220b0(0,"LINE %d - duplicate PHASE entry",param_3 & 0xffffffff,param_4);
            return 0xffffffff;
          }
          uVar19 = 2;
          uVar5 = 0x2a;
          iVar4 = FUN_180021730(param_1,&local_198,0x2a,2);
          if (iVar4 + -1 != (int)(short)plVar13[3]) {
            FUN_1800220b0(0,"LINE %d - no. of PHASES is not equal to no. of PROPERTIES",
                          param_3 & 0xffffffff,uVar19);
            return 0xffffffff;
          }
          iVar18 = 1;
          iVar4 = 1;
          if (0 < (short)plVar13[3]) {
            ppcVar17 = local_190;
            do {
              pcVar12 = *ppcVar17;
              if (*pcVar12 != DAT_180031787) {
                uVar9 = FUN_1800215c0((longlong *)&PTR_DAT_1800320c8,pcVar12);
                if ((int)uVar9 != 0) {
                  FUN_1800220b0(0,"LINE %d - unknown PHASE: %s",param_3 & 0xffffffff,pcVar12);
                  return 0xffffffff;
                }
                plVar13 = DAT_180034298;
              }
              iVar4 = iVar4 + 1;
              ppcVar17 = ppcVar17 + 1;
            } while (iVar4 <= (short)plVar13[3]);
          }
          pvVar10 = calloc((longlong)(short)plVar13[3],0xd);
          uVar5 = FUN_180022020((longlong)pvVar10,uVar15,uVar5,uVar19);
          plVar13 = DAT_180034298;
          if ((int)uVar5 != 0) {
            return 0xffffffff;
          }
          DAT_180034298[5] = (longlong)pvVar10;
          if (0 < (short)plVar13[3]) {
            ppcVar17 = local_190;
            do {
              FUN_180022050((longlong)pvVar10,*ppcVar17,0xd,uVar15);
              ppcVar17 = ppcVar17 + 1;
              pvVar10 = (void *)((longlong)pvVar10 + 0xd);
              iVar18 = iVar18 + 1;
            } while (iVar18 <= (short)DAT_180034298[3]);
          }
        }
      }
    }
  }
  else if (param_2 == 2) {
    if (*(short *)((longlong)DAT_180034298 + 0x5a) < (short)DAT_180034298[0xb]) {
      pvVar10 = realloc((void *)DAT_180034298[10],
                        (longlong)
                        ((int)(short)DAT_180034298[3] *
                        (int)*(short *)((longlong)DAT_180034298 + 0x5a)) << 4);
      uVar5 = FUN_180022020((longlong)pvVar10,uVar15,param_3,param_4);
      if ((int)uVar5 == 0) {
        *(undefined2 *)(DAT_180034298 + 0xb) = *(undefined2 *)((longlong)DAT_180034298 + 0x5a);
        DAT_180034298[10] = (longlong)pvVar10;
      }
    }
    DAT_180034298 = (longlong *)0x0;
    DAT_1800342a0 = (void *)0x0;
  }
  return 0;
}

/* RVA 0x20c40, FUN_180020c40 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180020c40(char *param_1,int param_2,uint param_3)

{
  ulonglong uVar1;
  longlong lVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  int *piVar6;
  longlong lVar7;
  longlong lVar8;
  void *pvVar9;
  undefined8 uVar10;
  double dVar11;
  undefined1 auStack_68 [32];
  char *local_48;
  char *local_40;
  char *local_38;
  char *local_30;
  char *local_28;
  ulonglong local_20;
  
  local_20 = DAT_180032178 ^ (ulonglong)auStack_68;
  uVar1 = (ulonglong)param_3;
  if (param_2 != 1) {
    if (param_2 != 3) {
      if (param_2 == 2) {
        DAT_180034350 = (void *)0x0;
        return 0;
      }
      return 0;
    }
    if (DAT_180034350 == (void *)0x0) {
      return 0;
    }
    iVar3 = FUN_180021f90((longlong)param_1,"ERROR");
    if (iVar3 == 0) {
      return 0;
    }
    uVar4 = 2;
    uVar10 = 5;
    FUN_180021730(param_1,&local_48,5,2);
    uVar5 = FUN_1800215c0((longlong *)&PTR_s_ALPHA_180032140,local_48);
    if ((int)uVar5 != 0) {
      FUN_1800220b0(0,"LINE %d - unknown MATRIX PARAMETER",uVar1,uVar4);
      return 0xffffffff;
    }
    lVar7 = FUN_1800216c0(local_40);
    if ((lVar7 == 0) || (lVar8 = FUN_1800216c0(local_38), local_40 = local_38, lVar8 == 0)) {
      FUN_1800220b0(0,"LINE %d - unknown CID: %s",uVar1,local_40);
      return 0xffffffff;
    }
    if (*(short *)((longlong)DAT_180034350 + 0x28) == 0) {
      pvVar9 = calloc(1,0x30);
    }
    else {
      pvVar9 = realloc(*(void **)((longlong)DAT_180034350 + 0x20),
                       (longlong)(*(short *)((longlong)DAT_180034350 + 0x28) + 1) * 0x30);
    }
    uVar5 = FUN_180022020((longlong)pvVar9,param_3,uVar10,uVar4);
    lVar2 = (longlong)DAT_180034350;
    if ((int)uVar5 == 0) {
      *(void **)((longlong)DAT_180034350 + 0x20) = pvVar9;
      pvVar9 = (void *)((longlong)pvVar9 + (longlong)*(short *)(lVar2 + 0x28) * 0x30);
      FUN_180022050((longlong)pvVar9,local_48,0xd,param_3);
      *(longlong *)((longlong)pvVar9 + 0x10) = lVar7;
      *(longlong *)((longlong)pvVar9 + 0x18) = lVar8;
      dVar11 = atof(local_30);
      *(double *)((longlong)pvVar9 + 0x20) = dVar11;
      dVar11 = atof(local_28);
      lVar7 = (longlong)DAT_180034350;
      *(double *)((longlong)pvVar9 + 0x28) = dVar11;
      *(short *)(lVar7 + 0x28) = *(short *)(lVar7 + 0x28) + 1;
      return 0;
    }
    return 0xffffffff;
  }
  uVar5 = 2;
  if (DAT_180031780 < 0x10) {
    uVar10 = 3;
    iVar3 = FUN_180021730(param_1,&local_48,3,2);
    if (iVar3 != 3) {
      return 0;
    }
    uVar4 = FUN_1800215c0((longlong *)&PTR_DAT_180032100,local_48);
    if ((int)uVar4 != 0) {
LAB_180020d56:
      FUN_1800220b0(0,"LINE %d - unknown METHOD",uVar1,uVar5);
      return 0xffffffff;
    }
    DAT_180034350 = calloc(1,0x30);
    uVar5 = FUN_180022020((longlong)DAT_180034350,param_3,uVar10,uVar5);
    if ((int)uVar5 != 0) {
      return 0xffffffff;
    }
    piVar6 = FUN_180021a60(8);
    FUN_180023c20(piVar6,DAT_180034350);
    FUN_180022050((longlong)DAT_180034350,local_48,0xd,param_3);
    FUN_180022050((longlong)DAT_180034350 + 0xd,local_40,0xd,param_3);
  }
  else {
    uVar10 = 4;
    iVar3 = FUN_180021730(param_1,&local_48,4,2);
    if (iVar3 != 4) {
      return 0;
    }
    uVar4 = FUN_1800215c0((longlong *)&PTR_DAT_180032100,local_40);
    if ((int)uVar4 != 0) goto LAB_180020d56;
    DAT_180034350 = calloc(1,0x30);
    uVar5 = FUN_180022020((longlong)DAT_180034350,param_3,uVar10,uVar5);
    if ((int)uVar5 != 0) {
      return 0xffffffff;
    }
    piVar6 = FUN_180021a60(8);
    FUN_180023c20(piVar6,DAT_180034350);
    FUN_180022050((longlong)DAT_180034350,local_40,0xd,param_3);
    FUN_180022050((longlong)DAT_180034350 + 0xd,local_38,0xd,param_3);
    local_38 = local_30;
  }
  iVar3 = atoi(local_38);
  *(int *)((longlong)DAT_180034350 + 0x1c) = iVar3;
  return 0;
}

/* RVA 0x20fa0, FUN_180020fa0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180020fa0(char *param_1,int param_2,uint param_3)

{
  int iVar1;
  undefined8 uVar2;
  int *piVar3;
  void *pvVar4;
  void *pvVar5;
  longlong lVar6;
  int iVar7;
  char **ppcVar8;
  short sVar9;
  double *pdVar10;
  undefined8 uVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  double dVar14;
  undefined1 auStack_198 [24];
  char *apcStack_180 [43];
  ulonglong local_28;
  
  local_28 = DAT_180032178 ^ (ulonglong)auStack_198;
  uVar12 = (ulonglong)param_3;
  if (param_2 == 1) {
    uVar11 = 2;
    uVar2 = 0x2a;
    iVar1 = FUN_180021730(param_1,apcStack_180 + 1,0x2a,2);
    if (1 < iVar1) {
      iVar7 = 1;
      DAT_180034358 = calloc(1,0x30);
      uVar2 = FUN_180022020((longlong)DAT_180034358,param_3,uVar2,uVar11);
      if ((int)uVar2 != 0) {
        piVar3 = FUN_180021a60(9);
        FUN_180023c20(piVar3,DAT_180034358);
        uVar2 = 0xd;
        FUN_180022050((longlong)DAT_180034358,apcStack_180[1],0xd,param_3);
        sVar9 = (short)iVar1 + -1;
        *(short *)((longlong)DAT_180034358 + 0x18) = sVar9;
        pvVar4 = calloc((longlong)sVar9,0xd);
        uVar2 = FUN_180022020((longlong)pvVar4,param_3,uVar2,uVar12);
        pvVar5 = DAT_180034358;
        if ((int)uVar2 == 0) {
          *(void **)((longlong)DAT_180034358 + 0x10) = pvVar4;
          if (*(short *)((longlong)pvVar5 + 0x18) < 1) {
            return 0;
          }
          ppcVar8 = apcStack_180 + 2;
          do {
            FUN_180022050((longlong)pvVar4,*ppcVar8,0xd,param_3);
            ppcVar8 = ppcVar8 + 1;
            pvVar4 = (void *)((longlong)pvVar4 + 0xd);
            iVar7 = iVar7 + 1;
          } while (iVar7 <= *(short *)((longlong)DAT_180034358 + 0x18));
          return 0;
        }
      }
      return 0xffffffff;
    }
  }
  else {
    if (param_2 == 3) {
      uVar2 = 0x2a;
      iVar1 = FUN_180021730(param_1,apcStack_180 + 1,0x2a,2);
      uVar13 = (ulonglong)(uint)(int)*(short *)((longlong)DAT_180034358 + 0x18);
      if (iVar1 != (int)*(short *)((longlong)DAT_180034358 + 0x18) + 2U) {
        FUN_1800220b0(0,"LINE %d - no. of G-PARAMETERS does not fit to given no of %i",uVar12,uVar13
                     );
        return 0xffffffff;
      }
      iVar1 = 1;
      if (*(short *)((longlong)DAT_180034358 + 0x28) == 0) {
        pvVar5 = calloc(1,0xb8);
      }
      else {
        pvVar5 = realloc(*(void **)((longlong)DAT_180034358 + 0x20),
                         (longlong)(*(short *)((longlong)DAT_180034358 + 0x28) + 1) * 0xb8);
      }
      uVar2 = FUN_180022020((longlong)pvVar5,param_3,uVar2,uVar13);
      lVar6 = (longlong)DAT_180034358;
      if ((int)uVar2 != 0) {
        return 0xffffffff;
      }
      *(void **)((longlong)DAT_180034358 + 0x20) = pvVar5;
      pvVar5 = (void *)((longlong)pvVar5 + (longlong)*(short *)(lVar6 + 0x28) * 0xb8);
      FUN_180022050((longlong)pvVar5,apcStack_180[1],0xd,param_3);
      iVar7 = atoi(apcStack_180[2]);
      lVar6 = (longlong)DAT_180034358;
      *(int *)((longlong)pvVar5 + 0x10) = iVar7;
      if (0 < *(short *)(lVar6 + 0x18)) {
        pdVar10 = (double *)((longlong)pvVar5 + 0x18);
        do {
          dVar14 = atof(*(char **)((longlong)pdVar10 + ((longlong)apcStack_180 - (longlong)pvVar5)))
          ;
          lVar6 = (longlong)DAT_180034358;
          iVar1 = iVar1 + 1;
          *pdVar10 = dVar14;
          pdVar10 = pdVar10 + 1;
        } while (iVar1 <= *(short *)(lVar6 + 0x18));
      }
      *(short *)(lVar6 + 0x28) = *(short *)(lVar6 + 0x28) + 1;
      return 0;
    }
    if (param_2 == 2) {
      DAT_180034358 = (void *)0x0;
    }
  }
  return 0;
}

/* RVA 0x21210, FUN_180021210 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180021210(char *param_1,int param_2,uint param_3)

{
  void *pvVar1;
  int iVar2;
  undefined8 uVar3;
  int *piVar4;
  void *pvVar5;
  longlong lVar6;
  undefined8 uVar7;
  double dVar8;
  undefined1 auStack_188 [32];
  char *local_168;
  char *local_160;
  char *local_158;
  char *local_150;
  ulonglong local_18;
  
  local_18 = DAT_180032178 ^ (ulonglong)auStack_188;
  if (param_2 == 1) {
    uVar7 = 2;
    uVar3 = 1;
    iVar2 = FUN_180021730(param_1,&local_168,1,2);
    if (iVar2 == 1) {
      DAT_180034360 = calloc(1,0x20);
      uVar3 = FUN_180022020((longlong)DAT_180034360,param_3,uVar3,uVar7);
      if ((int)uVar3 != 0) {
        return 0xffffffff;
      }
      piVar4 = FUN_180021a60(10);
      FUN_180023c20(piVar4,DAT_180034360);
      FUN_180022050((longlong)DAT_180034360,local_168,0xd,param_3);
    }
  }
  else {
    if (param_2 == 3) {
      uVar7 = 2;
      uVar3 = 4;
      iVar2 = FUN_180021730(param_1,&local_168,4,2);
      if (iVar2 == 4) {
        if (*(short *)((longlong)DAT_180034360 + 0x18) == 0) {
          pvVar5 = calloc(1,0x18);
        }
        else {
          pvVar5 = realloc(*(void **)((longlong)DAT_180034360 + 0x10),
                           (longlong)(*(short *)((longlong)DAT_180034360 + 0x18) + 1) * 0x18);
        }
        uVar3 = FUN_180022020((longlong)pvVar5,param_3,uVar3,uVar7);
        pvVar1 = DAT_180034360;
        if ((int)uVar3 == 0) {
          *(void **)((longlong)DAT_180034360 + 0x10) = pvVar5;
          lVar6 = (longlong)*(short *)((longlong)pvVar1 + 0x18);
          iVar2 = atoi(local_168);
          *(int *)((longlong)pvVar5 + lVar6 * 0x18) = iVar2;
          iVar2 = atoi(local_160);
          *(int *)((longlong)pvVar5 + lVar6 * 0x18 + 4) = iVar2;
          dVar8 = atof(local_158);
          *(double *)((longlong)pvVar5 + lVar6 * 0x18 + 8) = dVar8;
          dVar8 = atof(local_150);
          pvVar1 = DAT_180034360;
          *(double *)((longlong)pvVar5 + lVar6 * 0x18 + 0x10) = dVar8;
          *(short *)((longlong)pvVar1 + 0x18) = *(short *)((longlong)pvVar1 + 0x18) + 1;
          return 0;
        }
      }
      else {
        FUN_1800220b0(0,"LINE %d - no. of PARAMETERS is not correct",(ulonglong)param_3,uVar7);
      }
      return 0xffffffff;
    }
    if (param_2 == 2) {
      DAT_180034360 = (void *)0x0;
    }
  }
  return 0;
}

/* RVA 0x213d0, FUN_1800213d0 */
undefined8 FUN_1800213d0(char *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  longlong *plVar3;
  
  plVar3 = *(longlong **)(param_2 + 2);
  iVar2 = 1;
  if (0 < *param_2) {
    do {
      iVar1 = _stricmp(param_1,(char *)(*plVar3 + 0x240));
      if (iVar1 == 0) {
        return 1;
      }
      plVar3 = (longlong *)plVar3[1];
      iVar2 = iVar2 + 1;
    } while (iVar2 <= *param_2);
  }
  return 0;
}

/* RVA 0x21440, FUN_180021440 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180021440(char *param_1,int *param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  undefined1 *puVar2;
  undefined8 uVar3;
  char *pcVar4;
  longlong lVar5;
  uint uVar6;
  undefined1 auStack_68 [31];
  undefined1 uStack_49;
  char local_48;
  ulonglong local_47;
  undefined8 uStack_3f;
  undefined8 local_37;
  undefined4 local_2f;
  undefined2 local_2b;
  undefined1 local_29;
  char local_28 [16];
  ulonglong local_18;
  
  local_18 = DAT_180032178 ^ (ulonglong)auStack_68;
  local_48 = '\0';
  local_37 = 0;
  local_2f = 0;
  local_2b = 0;
  local_29 = 0;
  local_47 = 0;
  uStack_3f = 0;
  if (((param_1 != (char *)0x0) && (param_2 != (int *)0x0)) && (*param_1 != '\0')) {
    _strupr(param_1);
    strncpy(&local_48,param_1,0x1e);
    uVar6 = 0;
    local_47 = local_47 & 0xffffffffffffff;
    do {
      if ((int)uVar6 < 1000) {
        if (99 < (int)uVar6) {
          local_47._0_4_ = (uint)(uint3)local_47;
          goto LAB_1800214f3;
        }
        if (9 < (int)uVar6) {
          local_47._0_5_ = (uint5)(uint)local_47;
          goto LAB_1800214f3;
        }
        if (0 < (int)uVar6) {
          local_47._0_6_ = (uint6)(uint5)local_47;
          goto LAB_1800214f3;
        }
      }
      else {
        local_47._0_3_ = (uint3)(ushort)local_47;
LAB_1800214f3:
        FUN_180002d90(local_28,&DAT_180029720,(ulonglong)uVar6,param_4);
        puVar2 = &uStack_49;
        do {
          pcVar4 = puVar2 + 1;
          puVar2 = puVar2 + 1;
        } while (*pcVar4 != '\0');
        lVar5 = 0;
        do {
          cVar1 = local_28[lVar5];
          puVar2[lVar5] = cVar1;
          lVar5 = lVar5 + 1;
        } while (cVar1 != '\0');
      }
      uVar3 = FUN_1800213d0(&local_48,param_2);
      if ((int)uVar3 == 0) {
        pcVar4 = &local_48;
        do {
          cVar1 = *pcVar4;
          pcVar4[(longlong)param_1 - (longlong)&local_48] = cVar1;
          pcVar4 = pcVar4 + 1;
        } while (cVar1 != '\0');
        return;
      }
      uVar6 = uVar6 + 1;
    } while ((int)uVar6 < 10000);
  }
  return;
}

/* RVA 0x215b0, FUN_1800215b0 */
undefined * FUN_1800215b0(void)

{
  return &DAT_180034990;
}

/* RVA 0x215c0, FUN_1800215c0 */
undefined8 FUN_1800215c0(longlong *param_1,char *param_2)

{
  longlong lVar1;
  int iVar2;
  
  lVar1 = *param_1;
  while( true ) {
    if (lVar1 == 0) {
      return 0xffffffff;
    }
    iVar2 = FUN_180021f90(lVar1,param_2);
    if (iVar2 == 0) break;
    lVar1 = param_1[1];
    param_1 = param_1 + 1;
  }
  return 0;
}

/* RVA 0x21620, FUN_180021620 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180021620(char *param_1)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  char local_48 [56];
  ulonglong local_10;
  
  pcVar3 = local_48;
  local_10 = DAT_180032178 ^ (ulonglong)local_48;
  pcVar1 = param_1;
  do {
    cVar2 = *pcVar1;
    pcVar1[(longlong)(local_48 + -(longlong)param_1)] = cVar2;
    pcVar1 = pcVar1 + 1;
  } while (cVar2 != '\0');
  if (local_48[0] == '\0') {
    *param_1 = '\0';
    return;
  }
  do {
    pcVar3 = pcVar3 + 1;
    cVar2 = '-';
    if (local_48[0] != ' ') {
      cVar2 = local_48[0];
    }
    pcVar1 = param_1 + 1;
    *param_1 = cVar2;
    local_48[0] = *pcVar3;
    param_1 = pcVar1;
  } while (local_48[0] != '\0');
  *pcVar1 = '\0';
  return;
}

/* RVA 0x216c0, FUN_1800216c0 */
longlong FUN_1800216c0(char *param_1)

{
  char cVar1;
  char cVar2;
  longlong *plVar3;
  int *piVar4;
  char *pcVar5;
  
  piVar4 = FUN_180021a60(2);
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

/* RVA 0x21730, FUN_180021730 */
int FUN_180021730(char *param_1,undefined8 *param_2,int param_3,int param_4)

{
  char cVar1;
  longlong lVar2;
  char *pcVar3;
  longlong lVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar5 = 0;
  *param_2 = param_1;
  cVar1 = *param_1;
  iVar7 = 1;
  if (cVar1 != ' ') {
    pcVar3 = param_1;
    do {
      if ((cVar1 == '\t') || (cVar1 == '\0')) break;
      cVar1 = pcVar3[1];
      pcVar3 = pcVar3 + 1;
      iVar5 = iVar5 + 1;
    } while (cVar1 != ' ');
  }
  if (param_1[iVar5] != '\0') {
    iVar6 = iVar5 + 1;
    lVar4 = (longlong)param_3;
    param_1[iVar5] = '\0';
    iVar5 = -1;
    if (0 < lVar4) {
      lVar2 = 1;
      pcVar3 = param_1 + iVar6;
      do {
        cVar1 = *pcVar3;
        if (cVar1 == '\0') {
          return iVar7;
        }
        if (iVar5 == 0) {
          if (param_4 == 2) {
            if ((cVar1 == ' ') || (cVar1 == '\t')) {
              *pcVar3 = '\0';
              iVar5 = -1;
            }
            else {
LAB_1800217ee:
              if (cVar1 == '\n') {
                iVar7 = iVar7 + 1;
                *pcVar3 = '\0';
                lVar2 = lVar2 + 1;
                iVar5 = -1;
              }
            }
          }
          else {
            if ((param_4 != 1) || (cVar1 != DAT_180031786)) goto LAB_1800217ee;
            *pcVar3 = '\0';
            iVar5 = -1;
          }
        }
        else {
          if (((param_4 != 2) || (cVar1 == ' ')) || (cVar1 == '\t')) {
            if ((param_4 != 1) || (cVar1 != DAT_180031786)) goto LAB_180021835;
            iVar6 = iVar6 + 1;
            pcVar3 = pcVar3 + 1;
          }
          iVar7 = iVar7 + 1;
          param_2[lVar2] = param_1 + iVar6;
          lVar2 = lVar2 + 1;
          iVar5 = 0;
        }
LAB_180021835:
        if ((lVar2 == lVar4) && (iVar5 == -1)) {
          return iVar7;
        }
        iVar6 = iVar6 + 1;
        pcVar3 = pcVar3 + 1;
      } while (lVar2 <= lVar4);
    }
  }
  return iVar7;
}

