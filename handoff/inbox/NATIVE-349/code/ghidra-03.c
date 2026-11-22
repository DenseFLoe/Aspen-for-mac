/* RVA 0x10320, FUN_180010320 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180010320(undefined8 param_1,uint *param_2,double *param_3,double *param_4)

{
  int iVar1;
  double *pdVar2;
  size_t sVar3;
  undefined *puVar4;
  undefined1 auStack_3e8 [32];
  double *local_3c8;
  int local_3c0;
  int local_3bc;
  longlong *local_3b8;
  int local_3b0;
  double *local_3a8;
  int local_3a0;
  int local_39c;
  int local_398;
  int local_394;
  int local_390;
  int local_38c;
  double *local_388;
  double *local_380;
  double *local_378;
  int local_370;
  int local_36c;
  int local_368;
  double *local_360;
  int local_358;
  int local_354;
  int local_350;
  char *local_348;
  int local_340;
  int local_33c;
  double *local_338;
  int local_330;
  int local_32c;
  int local_328;
  longlong *local_320;
  int local_318;
  int local_314;
  int local_310;
  int local_30c;
  longlong local_308;
  int local_300;
  undefined *local_2f8;
  undefined *local_2f0;
  undefined *local_2e8;
  double local_2e0;
  longlong *local_2d8;
  undefined4 local_2d0;
  longlong local_2c8;
  double local_2c0;
  double local_2b8;
  int *local_2b0;
  double local_2a8;
  int aiStack_2a0 [8];
  int aiStack_280 [8];
  int aiStack_260 [8];
  double local_240;
  char local_238 [32];
  double local_218 [32];
  char local_118 [256];
  ulonglong local_18;
  
  local_18 = DAT_180032178 ^ (ulonglong)auStack_3e8;
  pdVar2 = param_3;
  local_2b0 = FUN_180021a60(7);
  local_2d8 = *(longlong **)(local_2b0 + 2);
  do {
    if (local_2d8 == (longlong *)0x0) {
      return;
    }
    local_3b8 = (longlong *)*local_2d8;
    if ((local_3b8[4] != 0) &&
       ((((local_3b8[4] == 0 || (iVar1 = _stricmp((char *)local_3b8[4],""), iVar1 != 0)) &&
         (local_3b8 != (longlong *)0xffffffffffffffc8)) &&
        ((local_3b8 == (longlong *)0xffffffffffffffc8 ||
         (iVar1 = _stricmp((char *)(local_3b8 + 7),""), iVar1 != 0)))))) {
      local_320 = (longlong *)local_3b8[2];
      local_308 = *local_3b8;
      local_310 = 0;
      local_30c = 0;
      local_300 = 0;
      local_33c = 0;
      local_318 = 0;
      local_340 = 0;
      local_330 = 0;
      local_368 = 0;
      strcpy(local_238,"");
      local_3a0 = -1;
      local_39c = -1;
      local_394 = -1;
      for (local_3b0 = 0; local_3b0 < 8; local_3b0 = local_3b0 + 1) {
        aiStack_2a0[local_3b0] = -1;
        aiStack_280[local_3b0] = -1;
        aiStack_260[local_3b0] = -1;
      }
      local_390 = 0;
      local_370 = 0;
      local_358 = 0;
      local_328 = 0;
      local_32c = 0;
      local_338 = (double *)0x0;
      local_3b0 = 1;
      local_380 = (double *)local_3b8[4];
      local_378 = (double *)local_3b8[6];
      for (; local_3b0 <= (short)local_3b8[3]; local_3b0 = local_3b0 + 1) {
        local_3c0 = 0;
        while (((&PTR_DAT_18002e640)[(longlong)local_3c0 * 3] != (undefined *)0x0 &&
               (iVar1 = _stricmp((&PTR_DAT_18002e640)[(longlong)local_3c0 * 3],(char *)local_380),
               iVar1 != 0))) {
          local_3c0 = local_3c0 + 1;
        }
        if (((&PTR_DAT_18002e648)[(longlong)local_3c0 * 3] == (undefined *)0x0) ||
           (*(&PTR_DAT_18002e648)[(longlong)local_3c0 * 3] != 'T')) {
          if (((&PTR_DAT_18002e648)[(longlong)local_3c0 * 3] == (undefined *)0x0) ||
             (*(&PTR_DAT_18002e648)[(longlong)local_3c0 * 3] != 'P')) {
            if (((&PTR_DAT_18002e648)[(longlong)local_3c0 * 3] == (undefined *)0x0) ||
               (*(&PTR_DAT_18002e648)[(longlong)local_3c0 * 3] != 'X')) {
              if (((&PTR_DAT_18002e648)[(longlong)local_3c0 * 3] != (undefined *)0x0) &&
                 (*(&PTR_DAT_18002e648)[(longlong)local_3c0 * 3] == 'Y')) {
                if (local_338 == (double *)0x0) {
                  pdVar2 = &local_2a8;
                  local_338 = (double *)FUN_1800082f0((char *)local_378,0x20,pdVar2);
                  if (local_338 == (double *)0x0) {
                    pdVar2 = local_378;
                    param_4 = local_380;
                    FUN_1800220b0(1,"Unit <%s> for property <%s> not supported by Aspen Plus",
                                  local_378,local_380);
                    goto LAB_18001056a;
                  }
                  if (local_3b8[9] != 0) {
                    local_388 = (double *)((longlong)(local_3b0 + -1) * 0x14 + local_3b8[9]);
                    if (*(char *)local_388 == '%') {
                      local_398 = 1;
                    }
                    else if (*(char *)local_388 == '$') {
                      local_398 = -1;
                    }
                    else {
                      iVar1 = strcmp((char *)local_388,(char *)local_378);
                      if (iVar1 == 0) {
                        local_398 = 2;
                      }
                      else {
                        pdVar2 = local_388;
                        param_4 = local_380;
                        FUN_1800220b0(0,"ERR-UNIT <%s> for property <%s> differs from UNIT",
                                      local_388,local_380);
                        local_398 = -1;
                      }
                    }
                  }
                }
                aiStack_260[local_358] = local_3b0;
                local_358 = local_358 + 1;
              }
            }
            else {
              if (local_338 == (double *)0x0) {
                pdVar2 = &local_2a8;
                local_338 = (double *)FUN_1800082f0((char *)local_378,0x20,pdVar2);
                if (local_338 == (double *)0x0) {
                  pdVar2 = local_378;
                  param_4 = local_380;
                  FUN_1800220b0(1,"Unit <%s> for property <%s> not supported by Aspen Plus",
                                local_378,local_380);
                  goto LAB_18001056a;
                }
                if (local_3b8[9] != 0) {
                  local_388 = (double *)((longlong)(local_3b0 + -1) * 0x14 + local_3b8[9]);
                  if (*(char *)local_388 == '%') {
                    local_398 = 1;
                  }
                  else if (*(char *)local_388 == '$') {
                    local_398 = -1;
                  }
                  else {
                    iVar1 = strcmp((char *)local_388,(char *)local_378);
                    if (iVar1 == 0) {
                      local_398 = 2;
                    }
                    else {
                      pdVar2 = local_388;
                      param_4 = local_380;
                      FUN_1800220b0(0,"ERR-UNIT <%s> for property <%s> differs from UNIT",local_388,
                                    local_380);
                      local_398 = -1;
                    }
                  }
                }
              }
              if (local_3b8[5] == 0) {
                aiStack_2a0[local_390] = local_3b0;
                local_390 = local_390 + 1;
              }
              else {
                local_348 = (char *)((longlong)(local_3b0 + -1) * 0xd + local_3b8[5]);
                iVar1 = strcmp(local_348,"L1");
                if ((iVar1 == 0) || (iVar1 = strcmp(local_348,"L"), iVar1 == 0)) {
                  aiStack_2a0[local_390] = local_3b0;
                  local_390 = local_390 + 1;
                }
                else {
                  iVar1 = strcmp(local_348,"L2");
                  if (iVar1 == 0) {
                    aiStack_280[local_370] = local_3b0;
                    local_370 = local_370 + 1;
                  }
                }
              }
            }
          }
          else {
            pdVar2 = &local_2b8;
            local_2f0 = FUN_1800082f0((char *)local_378,0x16,pdVar2);
            if (local_2f0 == (undefined *)0x0) {
              pdVar2 = local_378;
              param_4 = local_380;
              FUN_1800220b0(1,"Unit <%s> for property <%s> not supported by Aspen Plus",local_378,
                            local_380);
            }
            else {
              local_39c = local_3b0;
              local_32c = local_32c + 1;
            }
            if (local_3b8[9] != 0) {
              local_388 = (double *)((longlong)(local_3b0 + -1) * 0x14 + local_3b8[9]);
              if (*(char *)local_388 == '%') {
                local_350 = 1;
              }
              else if (*(char *)local_388 == '$') {
                local_350 = -1;
              }
              else {
                iVar1 = strcmp((char *)local_388,(char *)local_378);
                if (iVar1 == 0) {
                  local_350 = 2;
                }
                else {
                  pdVar2 = local_388;
                  param_4 = local_380;
                  FUN_1800220b0(0,"ERR-UNIT <%s> for property <%s> differs from UNIT",local_388,
                                local_380);
                  local_350 = -1;
                }
              }
            }
          }
        }
        else {
          pdVar2 = &local_2c0;
          local_2f8 = FUN_1800082f0((char *)local_378,0x19,pdVar2);
          if (local_2f8 == (undefined *)0x0) {
            pdVar2 = local_378;
            param_4 = local_380;
            FUN_1800220b0(1,"Unit <%s> for property <%s> not supported by Aspen Plus",local_378,
                          local_380);
          }
          else {
            local_3a0 = local_3b0;
            local_328 = local_328 + 1;
          }
          if (local_3b8[9] != 0) {
            local_388 = (double *)((longlong)(local_3b0 + -1) * 0x14 + local_3b8[9]);
            if (*(char *)local_388 == '%') {
              local_354 = 1;
            }
            else if (*(char *)local_388 == '$') {
              local_354 = -1;
            }
            else {
              iVar1 = strcmp((char *)local_388,(char *)local_378);
              if (iVar1 == 0) {
                local_354 = 2;
              }
              else {
                pdVar2 = local_388;
                param_4 = local_380;
                FUN_1800220b0(0,"ERR-UNIT <%s> for property <%s> differs from UNIT",local_388,
                              local_380);
                local_354 = -1;
              }
            }
          }
        }
LAB_18001056a:
        local_380 = (double *)((longlong)local_380 + 0xd);
        local_378 = (double *)((longlong)local_378 + 0x14);
      }
      if ((local_3a0 == -1) || (local_39c == -1)) {
        if ((local_3a0 == -1) || (local_39c != -1)) {
          if ((local_3a0 != -1) || (local_39c == -1)) {
            FUN_1800220b0(0,"Neither T nor P given in TABLE - no DATA GROUP written",pdVar2,param_4)
            ;
            goto LAB_180010370;
          }
          strcpy((char *)&local_240,"P");
        }
        else {
          strcpy((char *)&local_240,"T");
        }
      }
      else {
        strcpy((char *)&local_240,"TP");
      }
      if (((local_390 < 1) || (local_370 != 0)) && ((local_390 != 0 || (local_370 < 1)))) {
        if ((0 < local_390) && (0 < local_370)) {
          strcat((char *)&local_240,"XX");
        }
      }
      else if ((local_3b8 == (longlong *)0xffffffffffffffc8) ||
              (iVar1 = strcmp((char *)(local_3b8 + 7),"LLE"), iVar1 != 0)) {
        strcat((char *)&local_240,"X");
      }
      else {
        strcat((char *)&local_240,"XX");
      }
      if (0 < local_358) {
        strcat((char *)&local_240,"Y");
      }
      if (((local_390 < 1) || (local_370 < 1)) || (local_390 == local_370)) {
        local_300 = (int)(short)local_3b8[3];
        local_33c = local_328 + local_32c + local_390 + local_370 + local_358;
        local_318 = local_300 - local_33c;
        if ((0 < local_318) && (local_33c == 4)) {
          for (local_340 = 4; local_340 < local_318 + 4; local_340 = local_340 + 1) {
            local_330 = 0;
            if ((local_3b8[4] + (longlong)local_340 * 0xd != 0) &&
               (local_3b8[5] + (longlong)local_340 * 0xd != 0)) {
              local_330 = 1;
            }
          }
        }
        if (local_330 == 0) {
          local_3b0 = 1;
          local_380 = (double *)local_3b8[4];
          local_378 = (double *)local_3b8[6];
          local_348 = (char *)local_3b8[5];
          for (; local_3b0 <= (short)local_3b8[3]; local_3b0 = local_3b0 + 1) {
            if ((local_3b0 == 1) &&
               (local_328 + local_32c + local_390 + local_370 + local_358 ==
                (int)(short)local_3b8[3])) {
              local_310 = 1;
              if ((local_3b8 == (longlong *)0xffffffffffffffc8) ||
                 ((iVar1 = strcmp((char *)(local_3b8 + 7),"LLE"), iVar1 != 0 &&
                  (iVar1 = strcmp((char *)(local_3b8 + 7),"VLE"), iVar1 != 0)))) goto LAB_180012874;
LAB_180012c54:
              FUN_18001ddb0();
              *param_2 = *param_2 + 1;
              puVar4 = (undefined *)(ulonglong)*param_2;
              FUN_180007f00(param_1,"DATA-GROUP DG-%d\n",puVar4,param_4);
              FUN_180007f00(param_1,"  IN-UNITS SI ",puVar4,param_4);
              if ((local_3a0 < 1) || (local_39c < 1)) {
                if ((local_3a0 < 1) || (-1 < local_39c)) {
                  if ((local_3a0 < 0) && (0 < local_39c)) {
                    puVar4 = local_2f0;
                    FUN_180007f00(param_1,&DAT_180026538,local_2f0,param_4);
                  }
                }
                else {
                  puVar4 = local_2f8;
                  FUN_180007f00(param_1,&DAT_180026538,local_2f8,param_4);
                }
              }
              else {
                FUN_180007f00(param_1,"%s &\n",local_2f8,param_4);
                puVar4 = local_2f0;
                FUN_180007f00(param_1,"              %s",local_2f0,param_4);
              }
              if (local_394 < 1) {
                FUN_180007f00(param_1,&DAT_180027258,puVar4,param_4);
              }
              else {
                FUN_180007f00(param_1," &\n              %s\n",local_2e8,param_4);
              }
              if (local_308 != 0) {
                FUN_180007f00(param_1,"  DESCRIPTION \"Source-Key: %s\"\n",local_308,param_4);
              }
              pdVar2 = &local_240;
              FUN_180007f00(param_1,"  SYSTEM-DEF %s",pdVar2,param_4);
              local_3c0 = 0;
              local_320 = (longlong *)local_3b8[2];
              for (; local_3c0 < (short)local_3b8[1]; local_3c0 = local_3c0 + 1) {
                local_2c8 = *local_320;
                pdVar2 = (double *)(local_2c8 + 0x240);
                FUN_180007f00(param_1," &\n        %s",pdVar2,param_4);
                local_320 = local_320 + 1;
              }
              if (0 < local_394) {
                pdVar2 = (double *)local_360[1];
                FUN_180007f00(param_1," &\n        PROP-LIST=%s",pdVar2,param_4);
              }
              if (local_338 != (double *)0x0) {
                pdVar2 = local_338;
                FUN_180007f00(param_1," &\n        %s",local_338,param_4);
              }
              FUN_180007f00(param_1,&DAT_180027258,pdVar2,param_4);
              for (local_3c0 = 0; local_3c0 < *(short *)((longlong)local_3b8 + 0x5a);
                  local_3c0 = local_3c0 + 1) {
                if (local_3b8[9] != 0) {
                  local_3c8 = local_218;
                  local_2d0 = 0;
                  if (local_3a0 != -1) {
                    local_3a8 = (double *)
                                (local_3b8[10] + (longlong)(local_3c0 * (short)local_3b8[3]) * 0x10
                                 + -0x10 + (longlong)local_3a0 * 0x10);
                    FUN_180007e70(0xb,(char *)local_218,(longlong *)&local_3c8);
                    if ((local_354 == 1) && (local_3a8[1] != DAT_180029478)) {
                      FUN_180002d90(local_3c8," -%-10G",local_3a8[1],param_4);
                    }
                    else if ((local_354 == 2) && (local_3a8[1] != DAT_180029478)) {
                      FUN_180002d90(local_3c8," %-11G",local_3a8[1],param_4);
                    }
                    else {
                      FUN_180002d90(local_3c8," %-11s",&DAT_180028740,param_4);
                    }
                    sVar3 = strlen((char *)local_3c8);
                    local_3c8 = (double *)((longlong)local_3c8 + (longlong)(int)sVar3);
                  }
                  if (local_39c != -1) {
                    local_3a8 = (double *)
                                (local_3b8[10] + (longlong)(local_3c0 * (short)local_3b8[3]) * 0x10
                                 + -0x10 + (longlong)local_39c * 0x10);
                    FUN_180007e70(0xb,(char *)local_218,(longlong *)&local_3c8);
                    if ((local_350 == 1) && (local_3a8[1] != DAT_180029478)) {
                      FUN_180002d90(local_3c8," -%-10G",local_3a8[1],param_4);
                    }
                    else if ((local_350 == 2) && (local_3a8[1] != DAT_180029478)) {
                      FUN_180002d90(local_3c8," %-11G",local_3a8[1],param_4);
                    }
                    else {
                      FUN_180002d90(local_3c8," %-11s",&DAT_180028740,param_4);
                    }
                    sVar3 = strlen((char *)local_3c8);
                    local_3c8 = (double *)((longlong)local_3c8 + (longlong)(int)sVar3);
                  }
                  for (local_3bc = 0; local_3bc < (short)local_3b8[1] + -1;
                      local_3bc = local_3bc + 1) {
                    if (aiStack_2a0[local_3bc] == -1) {
                      if ((local_3b8 != (longlong *)0xffffffffffffffc8) &&
                         (iVar1 = strcmp((char *)(local_3b8 + 7),"LLE"), iVar1 == 0)) {
                        FUN_180007e70(0xb,(char *)local_218,(longlong *)&local_3c8);
                        FUN_180002d90(local_3c8," %-11s",&DAT_180028740,param_4);
                        sVar3 = strlen((char *)local_3c8);
                        local_3c8 = (double *)((longlong)local_3c8 + (longlong)(int)sVar3);
                      }
                    }
                    else {
                      local_3a8 = (double *)
                                  (local_3b8[10] +
                                   (longlong)(local_3c0 * (short)local_3b8[3]) * 0x10 + -0x10 +
                                  (longlong)aiStack_2a0[local_3bc] * 0x10);
                      FUN_180007e70(0xb,(char *)local_218,(longlong *)&local_3c8);
                      if ((local_398 == 1) && (local_3a8[1] != DAT_180029478)) {
                        FUN_180002d90(local_3c8," -%-10G",local_3a8[1],param_4);
                      }
                      else if ((local_398 == 2) && (local_3a8[1] != DAT_180029478)) {
                        FUN_180002d90(local_3c8," %-11G",local_3a8[1],param_4);
                      }
                      else {
                        FUN_180002d90(local_3c8," %-11s",&DAT_180028740,param_4);
                      }
                      sVar3 = strlen((char *)local_3c8);
                      local_3c8 = (double *)((longlong)local_3c8 + (longlong)(int)sVar3);
                    }
                  }
                  for (local_3bc = 0; local_3bc < (short)local_3b8[1] + -1;
                      local_3bc = local_3bc + 1) {
                    if (aiStack_280[local_3bc] == -1) {
                      if ((local_3b8 != (longlong *)0xffffffffffffffc8) &&
                         (iVar1 = strcmp((char *)(local_3b8 + 7),"LLE"), iVar1 == 0)) {
                        FUN_180007e70(0xb,(char *)local_218,(longlong *)&local_3c8);
                        FUN_180002d90(local_3c8," %-11s",&DAT_180028740,param_4);
                        sVar3 = strlen((char *)local_3c8);
                        local_3c8 = (double *)((longlong)local_3c8 + (longlong)(int)sVar3);
                      }
                    }
                    else {
                      FUN_180007e70(0xb,(char *)local_218,(longlong *)&local_3c8);
                      local_3a8 = (double *)
                                  (local_3b8[10] +
                                   (longlong)(local_3c0 * (short)local_3b8[3]) * 0x10 + -0x10 +
                                  (longlong)aiStack_280[local_3bc] * 0x10);
                      if ((local_398 == 1) && (local_3a8[1] != DAT_180029478)) {
                        FUN_180002d90(local_3c8," -%-10G",local_3a8[1],param_4);
                      }
                      else if ((local_398 == 2) && (local_3a8[1] != DAT_180029478)) {
                        FUN_180002d90(local_3c8," %-11G",local_3a8[1],param_4);
                      }
                      else {
                        FUN_180002d90(local_3c8," %-11s",&DAT_180028740,param_4);
                      }
                      sVar3 = strlen((char *)local_3c8);
                      local_3c8 = (double *)((longlong)local_3c8 + (longlong)(int)sVar3);
                    }
                  }
                  for (local_3bc = 0; local_3bc < (short)local_3b8[1] + -1;
                      local_3bc = local_3bc + 1) {
                    if (aiStack_260[local_3bc] != -1) {
                      FUN_180007e70(0xb,(char *)local_218,(longlong *)&local_3c8);
                      local_3a8 = (double *)
                                  (local_3b8[10] +
                                   (longlong)(local_3c0 * (short)local_3b8[3]) * 0x10 + -0x10 +
                                  (longlong)aiStack_260[local_3bc] * 0x10);
                      if ((local_398 == 1) && (local_3a8[1] != DAT_180029478)) {
                        FUN_180002d90(local_3c8," -%-10G",local_3a8[1],param_4);
                      }
                      else if ((local_398 == 2) && (local_3a8[1] != DAT_180029478)) {
                        FUN_180002d90(local_3c8," %-11G",local_3a8[1],param_4);
                      }
                      else {
                        FUN_180002d90(local_3c8," %-11s",&DAT_180028740,param_4);
                      }
                      sVar3 = strlen((char *)local_3c8);
                      local_3c8 = (double *)((longlong)local_3c8 + (longlong)(int)sVar3);
                    }
                  }
                  if (local_394 != -1) {
                    FUN_180007e70(0xb,(char *)local_218,(longlong *)&local_3c8);
                    local_3a8 = (double *)
                                (local_3b8[10] + (longlong)(local_3c0 * (short)local_3b8[3]) * 0x10
                                 + -0x10 + (longlong)local_394 * 0x10);
                    if ((local_36c == 1) && (local_3a8[1] != DAT_180029478)) {
                      FUN_180002d90(local_3c8," -%-10G",local_3a8[1],param_4);
                    }
                    else if ((local_36c == 2) && (local_3a8[1] != DAT_180029478)) {
                      FUN_180002d90(local_3c8," %-11G",local_3a8[1],param_4);
                    }
                    else {
                      FUN_180002d90(local_3c8," %-11s",&DAT_180028740,param_4);
                    }
                    sVar3 = strlen((char *)local_3c8);
                    local_3c8 = (double *)((longlong)local_3c8 + (longlong)(int)sVar3);
                  }
                  if ((local_3c0 == 0) || (iVar1 = strcmp(local_118,(char *)local_218), iVar1 != 0))
                  {
                    param_4 = local_218;
                    FUN_180007f00(param_1,"  STD-DEV %2i%s\n",(ulonglong)(local_3c0 + 1),param_4);
                    strcpy(local_118,(char *)local_218);
                  }
                }
                local_3c8 = local_218;
                puVar4 = (undefined *)(ulonglong)(local_3c0 + 1);
                FUN_180002d90(local_3c8,"  DATA    %2i",puVar4,param_4);
                sVar3 = strlen((char *)local_3c8);
                local_3c8 = (double *)((longlong)local_3c8 + (longlong)(int)sVar3);
                if (local_3a0 != -1) {
                  FUN_180007e70(0xb,(char *)local_218,(longlong *)&local_3c8);
                  local_3a8 = (double *)
                              (local_3b8[10] + (longlong)(local_3c0 * (short)local_3b8[3]) * 0x10 +
                               -0x10 + (longlong)local_3a0 * 0x10);
                  if (*local_3a8 == DAT_180029478) {
                    puVar4 = &DAT_180028740;
                    FUN_180002d90(local_3c8," %-11s",&DAT_180028740,param_4);
                  }
                  else {
                    puVar4 = (undefined *)(*local_3a8 * local_2c0);
                    FUN_180002d90(local_3c8," %-11G",puVar4,param_4);
                  }
                  sVar3 = strlen((char *)local_3c8);
                  local_3c8 = (double *)((longlong)local_3c8 + (longlong)(int)sVar3);
                }
                if (local_39c != -1) {
                  FUN_180007e70(0xb,(char *)local_218,(longlong *)&local_3c8);
                  local_3a8 = (double *)
                              (local_3b8[10] + (longlong)(local_3c0 * (short)local_3b8[3]) * 0x10 +
                               -0x10 + (longlong)local_39c * 0x10);
                  if (*local_3a8 == DAT_180029478) {
                    puVar4 = &DAT_180028740;
                    FUN_180002d90(local_3c8," %-11s",&DAT_180028740,param_4);
                  }
                  else {
                    puVar4 = (undefined *)(*local_3a8 * local_2b8);
                    FUN_180002d90(local_3c8," %-11G",puVar4,param_4);
                  }
                  sVar3 = strlen((char *)local_3c8);
                  local_3c8 = (double *)((longlong)local_3c8 + (longlong)(int)sVar3);
                }
                for (local_3bc = 0; local_3bc < (short)local_3b8[1] + -1; local_3bc = local_3bc + 1)
                {
                  if (aiStack_2a0[local_3bc] == -1) {
                    if ((local_3b8 != (longlong *)0xffffffffffffffc8) &&
                       (iVar1 = strcmp((char *)(local_3b8 + 7),"LLE"), iVar1 == 0)) {
                      FUN_180007e70(0xb,(char *)local_218,(longlong *)&local_3c8);
                      puVar4 = &DAT_180028740;
                      FUN_180002d90(local_3c8," %-11s",&DAT_180028740,param_4);
                      sVar3 = strlen((char *)local_3c8);
                      local_3c8 = (double *)((longlong)local_3c8 + (longlong)(int)sVar3);
                    }
                  }
                  else {
                    FUN_180007e70(0xb,(char *)local_218,(longlong *)&local_3c8);
                    local_3a8 = (double *)
                                (local_3b8[10] + (longlong)(local_3c0 * (short)local_3b8[3]) * 0x10
                                 + -0x10 + (longlong)aiStack_2a0[local_3bc] * 0x10);
                    if (*local_3a8 == DAT_180029478) {
                      puVar4 = &DAT_180028740;
                      FUN_180002d90(local_3c8," %-11s",&DAT_180028740,param_4);
                    }
                    else {
                      puVar4 = (undefined *)*local_3a8;
                      FUN_180002d90(local_3c8," %-11G",puVar4,param_4);
                    }
                    sVar3 = strlen((char *)local_3c8);
                    local_3c8 = (double *)((longlong)local_3c8 + (longlong)(int)sVar3);
                  }
                }
                for (local_3bc = 0; local_3bc < (short)local_3b8[1] + -1; local_3bc = local_3bc + 1)
                {
                  if (aiStack_280[local_3bc] == -1) {
                    if ((local_3b8 != (longlong *)0xffffffffffffffc8) &&
                       (iVar1 = strcmp((char *)(local_3b8 + 7),"LLE"), iVar1 == 0)) {
                      FUN_180007e70(0xb,(char *)local_218,(longlong *)&local_3c8);
                      puVar4 = &DAT_180028740;
                      FUN_180002d90(local_3c8," %-11s",&DAT_180028740,param_4);
                      sVar3 = strlen((char *)local_3c8);
                      local_3c8 = (double *)((longlong)local_3c8 + (longlong)(int)sVar3);
                    }
                  }
                  else {
                    FUN_180007e70(0xb,(char *)local_218,(longlong *)&local_3c8);
                    local_3a8 = (double *)
                                (local_3b8[10] + (longlong)(local_3c0 * (short)local_3b8[3]) * 0x10
                                 + -0x10 + (longlong)aiStack_280[local_3bc] * 0x10);
                    if (*local_3a8 == DAT_180029478) {
                      puVar4 = &DAT_180028740;
                      FUN_180002d90(local_3c8," %-11s",&DAT_180028740,param_4);
                    }
                    else {
                      puVar4 = (undefined *)*local_3a8;
                      FUN_180002d90(local_3c8," %-11G",puVar4,param_4);
                    }
                    sVar3 = strlen((char *)local_3c8);
                    local_3c8 = (double *)((longlong)local_3c8 + (longlong)(int)sVar3);
                  }
                }
                for (local_3bc = 0; local_3bc < (short)local_3b8[1] + -1; local_3bc = local_3bc + 1)
                {
                  if (aiStack_260[local_3bc] != -1) {
                    FUN_180007e70(0xb,(char *)local_218,(longlong *)&local_3c8);
                    local_3a8 = (double *)
                                (local_3b8[10] + (longlong)(local_3c0 * (short)local_3b8[3]) * 0x10
                                 + -0x10 + (longlong)aiStack_260[local_3bc] * 0x10);
                    if (*local_3a8 == DAT_180029478) {
                      puVar4 = &DAT_180028740;
                      FUN_180002d90(local_3c8," %-11s",&DAT_180028740,param_4);
                    }
                    else {
                      puVar4 = (undefined *)*local_3a8;
                      FUN_180002d90(local_3c8," %-11G",puVar4,param_4);
                    }
                    sVar3 = strlen((char *)local_3c8);
                    local_3c8 = (double *)((longlong)local_3c8 + (longlong)(int)sVar3);
                  }
                }
                if (local_394 != -1) {
                  FUN_180007e70(0xb,(char *)local_218,(longlong *)&local_3c8);
                  local_3a8 = (double *)
                              (local_3b8[10] + (longlong)(local_3c0 * (short)local_3b8[3]) * 0x10 +
                               -0x10 + (longlong)local_394 * 0x10);
                  if (*local_3a8 == DAT_180029478) {
                    puVar4 = &DAT_180028740;
                    FUN_180002d90(local_3c8," %-11s",&DAT_180028740,param_4);
                  }
                  else {
                    puVar4 = (undefined *)(*local_3a8 * local_2e0);
                    FUN_180002d90(local_3c8," %-11G",puVar4,param_4);
                  }
                  sVar3 = strlen((char *)local_3c8);
                  local_3c8 = (double *)((longlong)local_3c8 + (longlong)(int)sVar3);
                }
                FUN_180002d90(local_3c8,&DAT_180027258,puVar4,param_4);
                pdVar2 = local_218;
                FUN_180007f00(param_1,&DAT_180026538,pdVar2,param_4);
              }
              FUN_180007f00(param_1,&DAT_180027258,pdVar2,param_4);
            }
            else {
              local_38c = 0;
              for (local_3c0 = 0; (local_38c == 0 && (local_3c0 < local_390));
                  local_3c0 = local_3c0 + 1) {
                if (local_3b0 == aiStack_2a0[local_3c0]) {
                  local_38c = local_3b0;
                }
              }
              for (local_3c0 = 0; (local_38c == 0 && (local_3c0 < local_370));
                  local_3c0 = local_3c0 + 1) {
                if (local_3b0 == aiStack_280[local_3c0]) {
                  local_38c = local_3b0;
                }
              }
              for (local_3c0 = 0; (local_38c == 0 && (local_3c0 < local_358));
                  local_3c0 = local_3c0 + 1) {
                if (local_3b0 == aiStack_260[local_3c0]) {
                  local_38c = local_3b0;
                }
              }
              if (local_310 != 0) {
                local_310 = 0;
                goto LAB_180012c54;
              }
              if (((local_3b0 != local_3a0) && (local_3b0 != local_39c)) && (local_3b0 != local_38c)
                 ) {
                local_360 = param_3;
                while ((*local_360 != 0.0 &&
                       ((iVar1 = strcmp((char *)*local_360,(char *)local_380), iVar1 != 0 ||
                        (*(char *)((longlong)local_360 + 0x14) != *local_348))))) {
                  local_360 = local_360 + 3;
                }
                if (local_360[1] != 0.0) {
                  if (*(int *)(local_360 + 2) == 0) {
                    local_2e0 = DAT_180026638;
                  }
                  else {
                    local_2e8 = FUN_1800082f0((char *)local_378,*(int *)(local_360 + 2),&local_2e0);
                    if (local_2e8 == (undefined *)0x0) {
                      pdVar2 = local_378;
                      param_4 = local_380;
                      FUN_1800220b0(1,"Unit <%s> for property <%s> not supported by Aspen Plus",
                                    local_378,local_380);
                      goto LAB_180012874;
                    }
                  }
                  local_394 = local_3b0;
                  local_314 = local_3c0;
                  if (local_3b8[9] != 0) {
                    local_388 = (double *)((longlong)(local_3b0 + -1) * 0x14 + local_3b8[9]);
                    if (*(char *)local_388 == '%') {
                      local_36c = 1;
                    }
                    else if (*(char *)local_388 == '$') {
                      local_36c = -1;
                    }
                    else {
                      iVar1 = strcmp((char *)local_388,(char *)local_378);
                      if (iVar1 == 0) {
                        local_36c = 2;
                      }
                      else {
                        param_4 = local_380;
                        FUN_1800220b0(0,"ERR-UNIT <%s> for property <%s> differs from UNIT",
                                      local_388,local_380);
                        local_36c = -1;
                      }
                    }
                  }
                  goto LAB_180012c54;
                }
              }
            }
LAB_180012874:
            local_380 = (double *)((longlong)local_380 + 0xd);
            local_378 = (double *)((longlong)local_378 + 0x14);
            local_348 = local_348 + 0xd;
          }
        }
        else {
          local_330 = 0;
          local_3b0 = 1;
          local_380 = (double *)local_3b8[4];
          local_378 = (double *)local_3b8[6];
          local_348 = (char *)local_3b8[5];
          for (; local_3b0 <= (short)local_3b8[3]; local_3b0 = local_3b0 + 1) {
            if (local_3b0 == 1) {
              local_30c = 1;
            }
            local_38c = 0;
            for (local_3c0 = 0; (local_38c == 0 && (local_3c0 < local_390));
                local_3c0 = local_3c0 + 1) {
              if (local_3b0 == aiStack_2a0[local_3c0]) {
                local_38c = local_3b0;
              }
            }
            for (local_3c0 = 0; (local_38c == 0 && (local_3c0 < local_370));
                local_3c0 = local_3c0 + 1) {
              if (local_3b0 == aiStack_280[local_3c0]) {
                local_38c = local_3b0;
              }
            }
            for (local_3c0 = 0; (local_38c == 0 && (local_3c0 < local_358));
                local_3c0 = local_3c0 + 1) {
              if (local_3b0 == aiStack_260[local_3c0]) {
                local_38c = local_3b0;
              }
            }
            if (local_30c == 0) {
              if (((local_3b0 != local_3a0) && (local_3b0 != local_39c)) && (local_3b0 != local_38c)
                 ) {
                local_360 = param_3;
                while ((*local_360 != 0.0 &&
                       ((iVar1 = strcmp((char *)*local_360,(char *)local_380), iVar1 != 0 ||
                        (*(char *)((longlong)local_360 + 0x14) != *local_348))))) {
                  local_360 = local_360 + 3;
                }
                if (local_360[1] != 0.0) {
                  if (*(int *)(local_360 + 2) == 0) {
                    local_2e0 = DAT_180026638;
                  }
                  else {
                    local_2e8 = FUN_1800082f0((char *)local_378,*(int *)(local_360 + 2),&local_2e0);
                    if (local_2e8 == (undefined *)0x0) {
                      pdVar2 = local_378;
                      param_4 = local_380;
                      FUN_1800220b0(1,"Unit <%s> for property <%s> not supported by Aspen Plus",
                                    local_378,local_380);
                      goto LAB_180010f92;
                    }
                  }
                  local_394 = local_3b0;
                  local_314 = local_3c0;
                  if (local_3b8[9] != 0) {
                    local_388 = (double *)((longlong)(local_3b0 + -1) * 0x14 + local_3b8[9]);
                    if (*(char *)local_388 == '%') {
                      local_36c = 1;
                    }
                    else if (*(char *)local_388 == '$') {
                      local_36c = -1;
                    }
                    else {
                      iVar1 = strcmp((char *)local_388,(char *)local_378);
                      if (iVar1 == 0) {
                        local_36c = 2;
                      }
                      else {
                        param_4 = local_380;
                        FUN_1800220b0(0,"ERR-UNIT <%s> for property <%s> differs from UNIT",
                                      local_388,local_380);
                        local_36c = -1;
                      }
                    }
                  }
                  goto LAB_1800112f0;
                }
              }
            }
            else {
              local_30c = 0;
LAB_1800112f0:
              FUN_18001ddb0();
              *param_2 = *param_2 + 1;
              puVar4 = (undefined *)(ulonglong)*param_2;
              FUN_180007f00(param_1,"DATA-GROUP DG-%d\n",puVar4,param_4);
              FUN_180007f00(param_1,"  IN-UNITS SI ",puVar4,param_4);
              if ((local_3a0 < 1) || (local_39c < 1)) {
                if ((local_3a0 < 1) || (-1 < local_39c)) {
                  if ((local_3a0 < 0) && (0 < local_39c)) {
                    puVar4 = local_2f0;
                    FUN_180007f00(param_1,&DAT_180026538,local_2f0,param_4);
                  }
                }
                else {
                  puVar4 = local_2f8;
                  FUN_180007f00(param_1,&DAT_180026538,local_2f8,param_4);
                }
              }
              else {
                FUN_180007f00(param_1,"%s &\n",local_2f8,param_4);
                puVar4 = local_2f0;
                FUN_180007f00(param_1,"              %s",local_2f0,param_4);
              }
              if (local_394 < 1) {
                FUN_180007f00(param_1,&DAT_180027258,puVar4,param_4);
              }
              else {
                FUN_180007f00(param_1," &\n              %s\n",local_2e8,param_4);
              }
              if (local_308 != 0) {
                FUN_180007f00(param_1,"  DESCRIPTION \"Source-Key: %s\"\n",local_308,param_4);
              }
              if (0 < local_394) {
                local_368 = 0;
                strcpy(local_238,(char *)local_360[1]);
                iVar1 = strcmp(local_238,"CPLMX");
                if (((((((iVar1 == 0) || (iVar1 = strcmp(local_238,"GAMMAM"), iVar1 == 0)) ||
                       (iVar1 = strcmp(local_238,"GLXS"), iVar1 == 0)) ||
                      ((iVar1 = strcmp(local_238,"HLMX"), iVar1 == 0 ||
                       (iVar1 = strcmp(local_238,"HLXS"), iVar1 == 0)))) ||
                     (iVar1 = strcmp(local_238,"KLMX"), iVar1 == 0)) ||
                    (((iVar1 = strcmp(local_238,"MULMX"), iVar1 == 0 ||
                      (iVar1 = strcmp(local_238,"OSMOT"), iVar1 == 0)) ||
                     ((iVar1 = strcmp(local_238,"PH"), iVar1 == 0 ||
                      (((iVar1 = strcmp(local_238,"RHOLMX"), iVar1 == 0 ||
                        (iVar1 = strcmp(local_238,"SIGLMX"), iVar1 == 0)) ||
                       (iVar1 = strcmp(local_238,"VLMX"), iVar1 == 0)))))))) ||
                   (((iVar1 = strcmp(local_238,"DLMX"), iVar1 == 0 ||
                     (iVar1 = strcmp(local_238,"GAMMA"), iVar1 == 0)) ||
                    ((iVar1 = strcmp(local_238,"GAMMAS"), iVar1 == 0 ||
                     (iVar1 = strcmp(local_238,"HNRYMX"), iVar1 == 0)))))) {
                  strcpy((char *)&local_240,"TPX");
                  local_368 = 1;
                }
                iVar1 = strcmp(local_238,"CPVMX");
                if ((((iVar1 == 0) || (iVar1 = strcmp(local_238,"HVMX"), iVar1 == 0)) ||
                    ((iVar1 = strcmp(local_238,"KVMX"), iVar1 == 0 ||
                     (((iVar1 = strcmp(local_238,"MUVMX"), iVar1 == 0 ||
                       (iVar1 = strcmp(local_238,"RHOVMX"), iVar1 == 0)) ||
                      (iVar1 = strcmp(local_238,"VVMX"), iVar1 == 0)))))) ||
                   (iVar1 = strcmp(local_238,"DVMX"), iVar1 == 0)) {
                  strcpy((char *)&local_240,"TPY");
                  local_368 = 2;
                }
                strcpy(local_238,"");
              }
              pdVar2 = &local_240;
              FUN_180007f00(param_1,"  SYSTEM-DEF %s",pdVar2,param_4);
              local_3c0 = 0;
              local_320 = (longlong *)local_3b8[2];
              for (; local_3c0 < (short)local_3b8[1]; local_3c0 = local_3c0 + 1) {
                local_2c8 = *local_320;
                pdVar2 = (double *)(local_2c8 + 0x240);
                FUN_180007f00(param_1," &\n        %s",pdVar2,param_4);
                local_320 = local_320 + 1;
              }
              if (0 < local_394) {
                pdVar2 = (double *)local_360[1];
                FUN_180007f00(param_1," &\n        PROP-LIST=%s",pdVar2,param_4);
              }
              if (local_338 != (double *)0x0) {
                pdVar2 = local_338;
                FUN_180007f00(param_1," &\n        %s",local_338,param_4);
              }
              FUN_180007f00(param_1,&DAT_180027258,pdVar2,param_4);
              for (local_3c0 = 0; local_3c0 < *(short *)((longlong)local_3b8 + 0x5a);
                  local_3c0 = local_3c0 + 1) {
                if (local_3b8[9] != 0) {
                  local_3c8 = local_218;
                  local_2d0 = 0;
                  if (local_3a0 != -1) {
                    local_3a8 = (double *)
                                (local_3b8[10] + (longlong)(local_3c0 * (short)local_3b8[3]) * 0x10
                                 + -0x10 + (longlong)local_3a0 * 0x10);
                    FUN_180007e70(0xb,(char *)local_218,(longlong *)&local_3c8);
                    if ((local_354 == 1) && (local_3a8[1] != DAT_180029478)) {
                      FUN_180002d90(local_3c8," -%-10G",local_3a8[1],param_4);
                    }
                    else if ((local_354 == 2) && (local_3a8[1] != DAT_180029478)) {
                      FUN_180002d90(local_3c8," %-11G",local_3a8[1],param_4);
                    }
                    else {
                      FUN_180002d90(local_3c8," %-11s",&DAT_180028740,param_4);
                    }
                    sVar3 = strlen((char *)local_3c8);
                    local_3c8 = (double *)((longlong)local_3c8 + (longlong)(int)sVar3);
                  }
                  if (local_39c != -1) {
                    local_3a8 = (double *)
                                (local_3b8[10] + (longlong)(local_3c0 * (short)local_3b8[3]) * 0x10
                                 + -0x10 + (longlong)local_39c * 0x10);
                    FUN_180007e70(0xb,(char *)local_218,(longlong *)&local_3c8);
                    if ((local_350 == 1) && (local_3a8[1] != DAT_180029478)) {
                      FUN_180002d90(local_3c8," -%-10G",local_3a8[1],param_4);
                    }
                    else if ((local_350 == 2) && (local_3a8[1] != DAT_180029478)) {
                      FUN_180002d90(local_3c8," %-11G",local_3a8[1],param_4);
                    }
                    else {
                      FUN_180002d90(local_3c8," %-11s",&DAT_180028740,param_4);
                    }
                    sVar3 = strlen((char *)local_3c8);
                    local_3c8 = (double *)((longlong)local_3c8 + (longlong)(int)sVar3);
                  }
                  for (local_3bc = 0; local_3bc < (short)local_3b8[1] + -1;
                      local_3bc = local_3bc + 1) {
                    if (aiStack_2a0[local_3bc] == -1) {
                      if ((local_3b8 != (longlong *)0xffffffffffffffc8) &&
                         (iVar1 = strcmp((char *)(local_3b8 + 7),"LLE"), iVar1 == 0)) {
                        FUN_180007e70(0xb,(char *)local_218,(longlong *)&local_3c8);
                        FUN_180002d90(local_3c8," %-11s",&DAT_180028740,param_4);
                        sVar3 = strlen((char *)local_3c8);
                        local_3c8 = (double *)((longlong)local_3c8 + (longlong)(int)sVar3);
                      }
                    }
                    else {
                      if (local_368 == 2) break;
                      local_3a8 = (double *)
                                  (local_3b8[10] +
                                   (longlong)(local_3c0 * (short)local_3b8[3]) * 0x10 + -0x10 +
                                  (longlong)aiStack_2a0[local_3bc] * 0x10);
                      FUN_180007e70(0xb,(char *)local_218,(longlong *)&local_3c8);
                      if ((local_398 == 1) && (local_3a8[1] != DAT_180029478)) {
                        FUN_180002d90(local_3c8," -%-10G",local_3a8[1],param_4);
                      }
                      else if ((local_398 == 2) && (local_3a8[1] != DAT_180029478)) {
                        FUN_180002d90(local_3c8," %-11G",local_3a8[1],param_4);
                      }
                      else {
                        FUN_180002d90(local_3c8," %-11s",&DAT_180028740,param_4);
                      }
                      sVar3 = strlen((char *)local_3c8);
                      local_3c8 = (double *)((longlong)local_3c8 + (longlong)(int)sVar3);
                    }
                  }
                  local_3bc = 0;
                  while ((local_3bc < (short)local_3b8[1] + -1 && (local_368 != 2))) {
                    if (aiStack_280[local_3bc] == -1) {
                      if ((local_3b8 != (longlong *)0xffffffffffffffc8) &&
                         (iVar1 = strcmp((char *)(local_3b8 + 7),"LLE"), iVar1 == 0)) {
                        FUN_180007e70(0xb,(char *)local_218,(longlong *)&local_3c8);
                        FUN_180002d90(local_3c8," %-11s",&DAT_180028740,param_4);
                        sVar3 = strlen((char *)local_3c8);
                        local_3c8 = (double *)((longlong)local_3c8 + (longlong)(int)sVar3);
                      }
                    }
                    else {
                      FUN_180007e70(0xb,(char *)local_218,(longlong *)&local_3c8);
                      local_3a8 = (double *)
                                  (local_3b8[10] +
                                   (longlong)(local_3c0 * (short)local_3b8[3]) * 0x10 + -0x10 +
                                  (longlong)aiStack_280[local_3bc] * 0x10);
                      if ((local_398 == 1) && (local_3a8[1] != DAT_180029478)) {
                        FUN_180002d90(local_3c8," -%-10G",local_3a8[1],param_4);
                      }
                      else if ((local_398 == 2) && (local_3a8[1] != DAT_180029478)) {
                        FUN_180002d90(local_3c8," %-11G",local_3a8[1],param_4);
                      }
                      else {
                        FUN_180002d90(local_3c8," %-11s",&DAT_180028740,param_4);
                      }
                      sVar3 = strlen((char *)local_3c8);
                      local_3c8 = (double *)((longlong)local_3c8 + (longlong)(int)sVar3);
                    }
                    local_3bc = local_3bc + 1;
                  }
                  local_3bc = 0;
                  while ((local_3bc < (short)local_3b8[1] + -1 && (local_368 != 1))) {
                    if (aiStack_260[local_3bc] != -1) {
                      FUN_180007e70(0xb,(char *)local_218,(longlong *)&local_3c8);
                      local_3a8 = (double *)
                                  (local_3b8[10] +
                                   (longlong)(local_3c0 * (short)local_3b8[3]) * 0x10 + -0x10 +
                                  (longlong)aiStack_260[local_3bc] * 0x10);
                      if ((local_398 == 1) && (local_3a8[1] != DAT_180029478)) {
                        FUN_180002d90(local_3c8," -%-10G",local_3a8[1],param_4);
                      }
                      else if ((local_398 == 2) && (local_3a8[1] != DAT_180029478)) {
                        FUN_180002d90(local_3c8," %-11G",local_3a8[1],param_4);
                      }
                      else {
                        FUN_180002d90(local_3c8," %-11s",&DAT_180028740,param_4);
                      }
                      sVar3 = strlen((char *)local_3c8);
                      local_3c8 = (double *)((longlong)local_3c8 + (longlong)(int)sVar3);
                    }
                    local_3bc = local_3bc + 1;
                  }
                  if (local_394 != -1) {
                    FUN_180007e70(0xb,(char *)local_218,(longlong *)&local_3c8);
                    local_3a8 = (double *)
                                (local_3b8[10] + (longlong)(local_3c0 * (short)local_3b8[3]) * 0x10
                                 + -0x10 + (longlong)local_394 * 0x10);
                    if ((local_36c == 1) && (local_3a8[1] != DAT_180029478)) {
                      FUN_180002d90(local_3c8," -%-10G",local_3a8[1],param_4);
                    }
                    else if ((local_36c == 2) && (local_3a8[1] != DAT_180029478)) {
                      FUN_180002d90(local_3c8," %-11G",local_3a8[1],param_4);
                    }
                    else {
                      FUN_180002d90(local_3c8," %-11s",&DAT_180028740,param_4);
                    }
                    sVar3 = strlen((char *)local_3c8);
                    local_3c8 = (double *)((longlong)local_3c8 + (longlong)(int)sVar3);
                  }
                  if ((local_3c0 == 0) || (iVar1 = strcmp(local_118,(char *)local_218), iVar1 != 0))
                  {
                    param_4 = local_218;
                    FUN_180007f00(param_1,"  STD-DEV %2i%s\n",(ulonglong)(local_3c0 + 1),param_4);
                    strcpy(local_118,(char *)local_218);
                  }
                }
                local_3c8 = local_218;
                puVar4 = (undefined *)(ulonglong)(local_3c0 + 1);
                FUN_180002d90(local_3c8,"  DATA    %2i",puVar4,param_4);
                sVar3 = strlen((char *)local_3c8);
                local_3c8 = (double *)((longlong)local_3c8 + (longlong)(int)sVar3);
                if (local_3a0 != -1) {
                  FUN_180007e70(0xb,(char *)local_218,(longlong *)&local_3c8);
                  local_3a8 = (double *)
                              (local_3b8[10] + (longlong)(local_3c0 * (short)local_3b8[3]) * 0x10 +
                               -0x10 + (longlong)local_3a0 * 0x10);
                  if (*local_3a8 == DAT_180029478) {
                    puVar4 = &DAT_180028740;
                    FUN_180002d90(local_3c8," %-11s",&DAT_180028740,param_4);
                  }
                  else {
                    puVar4 = (undefined *)(*local_3a8 * local_2c0);
                    FUN_180002d90(local_3c8," %-11G",puVar4,param_4);
                  }
                  sVar3 = strlen((char *)local_3c8);
                  local_3c8 = (double *)((longlong)local_3c8 + (longlong)(int)sVar3);
                }
                if (local_39c != -1) {
                  FUN_180007e70(0xb,(char *)local_218,(longlong *)&local_3c8);
                  local_3a8 = (double *)
                              (local_3b8[10] + (longlong)(local_3c0 * (short)local_3b8[3]) * 0x10 +
                               -0x10 + (longlong)local_39c * 0x10);
                  if (*local_3a8 == DAT_180029478) {
                    puVar4 = &DAT_180028740;
                    FUN_180002d90(local_3c8," %-11s",&DAT_180028740,param_4);
                  }
                  else {
                    puVar4 = (undefined *)(*local_3a8 * local_2b8);
                    FUN_180002d90(local_3c8," %-11G",puVar4,param_4);
                  }
                  sVar3 = strlen((char *)local_3c8);
                  local_3c8 = (double *)((longlong)local_3c8 + (longlong)(int)sVar3);
                }
                local_3bc = 0;
                while ((local_3bc < (short)local_3b8[1] + -1 && (local_368 != 2))) {
                  if (aiStack_2a0[local_3bc] == -1) {
                    if ((local_3b8 != (longlong *)0xffffffffffffffc8) &&
                       (iVar1 = strcmp((char *)(local_3b8 + 7),"LLE"), iVar1 == 0)) {
                      FUN_180007e70(0xb,(char *)local_218,(longlong *)&local_3c8);
                      puVar4 = &DAT_180028740;
                      FUN_180002d90(local_3c8," %-11s",&DAT_180028740,param_4);
                      sVar3 = strlen((char *)local_3c8);
                      local_3c8 = (double *)((longlong)local_3c8 + (longlong)(int)sVar3);
                    }
                  }
                  else {
                    FUN_180007e70(0xb,(char *)local_218,(longlong *)&local_3c8);
                    local_3a8 = (double *)
                                (local_3b8[10] + (longlong)(local_3c0 * (short)local_3b8[3]) * 0x10
                                 + -0x10 + (longlong)aiStack_2a0[local_3bc] * 0x10);
                    if (*local_3a8 == DAT_180029478) {
                      puVar4 = &DAT_180028740;
                      FUN_180002d90(local_3c8," %-11s",&DAT_180028740,param_4);
                    }
                    else {
                      puVar4 = (undefined *)*local_3a8;
                      FUN_180002d90(local_3c8," %-11G",puVar4,param_4);
                    }
                    sVar3 = strlen((char *)local_3c8);
                    local_3c8 = (double *)((longlong)local_3c8 + (longlong)(int)sVar3);
                  }
                  local_3bc = local_3bc + 1;
                }
                local_3bc = 0;
                while ((local_3bc < (short)local_3b8[1] + -1 && (local_368 != 2))) {
                  if (aiStack_280[local_3bc] == -1) {
                    if ((local_3b8 != (longlong *)0xffffffffffffffc8) &&
                       (iVar1 = strcmp((char *)(local_3b8 + 7),"LLE"), iVar1 == 0)) {
                      FUN_180007e70(0xb,(char *)local_218,(longlong *)&local_3c8);
                      puVar4 = &DAT_180028740;
                      FUN_180002d90(local_3c8," %-11s",&DAT_180028740,param_4);
                      sVar3 = strlen((char *)local_3c8);
                      local_3c8 = (double *)((longlong)local_3c8 + (longlong)(int)sVar3);
                    }
                  }
                  else {
                    FUN_180007e70(0xb,(char *)local_218,(longlong *)&local_3c8);
                    local_3a8 = (double *)
                                (local_3b8[10] + (longlong)(local_3c0 * (short)local_3b8[3]) * 0x10
                                 + -0x10 + (longlong)aiStack_280[local_3bc] * 0x10);
                    if (*local_3a8 == DAT_180029478) {
                      puVar4 = &DAT_180028740;
                      FUN_180002d90(local_3c8," %-11s",&DAT_180028740,param_4);
                    }
                    else {
                      puVar4 = (undefined *)*local_3a8;
                      FUN_180002d90(local_3c8," %-11G",puVar4,param_4);
                    }
                    sVar3 = strlen((char *)local_3c8);
                    local_3c8 = (double *)((longlong)local_3c8 + (longlong)(int)sVar3);
                  }
                  local_3bc = local_3bc + 1;
                }
                local_3bc = 0;
                while ((local_3bc < (short)local_3b8[1] + -1 && (local_368 != 1))) {
                  if (aiStack_260[local_3bc] != -1) {
                    FUN_180007e70(0xb,(char *)local_218,(longlong *)&local_3c8);
                    local_3a8 = (double *)
                                (local_3b8[10] + (longlong)(local_3c0 * (short)local_3b8[3]) * 0x10
                                 + -0x10 + (longlong)aiStack_260[local_3bc] * 0x10);
                    if (*local_3a8 == DAT_180029478) {
                      puVar4 = &DAT_180028740;
                      FUN_180002d90(local_3c8," %-11s",&DAT_180028740,param_4);
                    }
                    else {
                      puVar4 = (undefined *)*local_3a8;
                      FUN_180002d90(local_3c8," %-11G",puVar4,param_4);
                    }
                    sVar3 = strlen((char *)local_3c8);
                    local_3c8 = (double *)((longlong)local_3c8 + (longlong)(int)sVar3);
                  }
                  local_3bc = local_3bc + 1;
                }
                if (local_394 != -1) {
                  FUN_180007e70(0xb,(char *)local_218,(longlong *)&local_3c8);
                  local_3a8 = (double *)
                              (local_3b8[10] + (longlong)(local_3c0 * (short)local_3b8[3]) * 0x10 +
                               -0x10 + (longlong)local_394 * 0x10);
                  if (*local_3a8 == DAT_180029478) {
                    puVar4 = &DAT_180028740;
                    FUN_180002d90(local_3c8," %-11s",&DAT_180028740,param_4);
                  }
                  else {
                    puVar4 = (undefined *)(*local_3a8 * local_2e0);
                    FUN_180002d90(local_3c8," %-11G",puVar4,param_4);
                  }
                  sVar3 = strlen((char *)local_3c8);
                  local_3c8 = (double *)((longlong)local_3c8 + (longlong)(int)sVar3);
                }
                FUN_180002d90(local_3c8,&DAT_180027258,puVar4,param_4);
                pdVar2 = local_218;
                FUN_180007f00(param_1,&DAT_180026538,pdVar2,param_4);
              }
              FUN_180007f00(param_1,&DAT_180027258,pdVar2,param_4);
              local_368 = 0;
            }
LAB_180010f92:
            local_380 = (double *)((longlong)local_380 + 0xd);
            local_378 = (double *)((longlong)local_378 + 0x14);
            local_348 = local_348 + 0xd;
          }
        }
      }
      else {
        FUN_1800220b0(0,"NO of X-Values for phases differ - no DATA GROUP written",pdVar2,param_4);
      }
    }
LAB_180010370:
    local_2d8 = (longlong *)local_2d8[1];
  } while( true );
}

/* RVA 0x13e80, FUN_180013e80 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00018001555b) */
/* WARNING: Removing unreachable block (ram,0x0001800171a6) */
/* WARNING: Removing unreachable block (ram,0x000180015591) */
/* WARNING: Removing unreachable block (ram,0x0001800171dc) */
/* WARNING: Removing unreachable block (ram,0x000180015685) */
/* WARNING: Removing unreachable block (ram,0x0001800172d0) */
/* WARNING: Removing unreachable block (ram,0x0001800156bb) */
/* WARNING: Removing unreachable block (ram,0x000180017306) */

void FUN_180013e80(undefined8 param_1,uint *param_2,double *param_3,double *param_4)

{
  int iVar1;
  double *pdVar2;
  size_t sVar3;
  ulonglong uVar4;
  double *pdVar5;
  undefined *puVar6;
  char **ppcVar7;
  undefined1 auStackY_5f8 [32];
  char *local_5c8;
  int local_5c0;
  int local_5bc;
  undefined8 *local_5b8;
  double *local_5b0;
  int local_5a8;
  int local_5a4;
  int local_5a0;
  int local_59c;
  int local_598;
  int local_594;
  int local_590;
  int local_58c;
  int local_588;
  int local_584;
  int local_580;
  double *local_578;
  double *local_570;
  double *local_568;
  undefined4 local_560;
  int local_55c;
  longlong *local_558;
  int local_550;
  int local_54c;
  char *local_548;
  int local_540;
  double *local_538;
  double *local_530;
  longlong local_528;
  undefined *local_520;
  double *local_518;
  int local_510;
  int local_50c;
  uint local_508;
  int local_504;
  longlong *local_500;
  undefined *local_4f8;
  undefined4 local_4f0;
  undefined8 local_4e8;
  undefined8 local_4e0;
  undefined8 local_4d8;
  undefined8 local_4d0;
  double local_4c8 [6];
  double local_498;
  undefined4 local_490;
  undefined4 local_48c;
  int *local_488;
  double *local_480;
  double local_478;
  undefined8 local_470;
  int aiStack_468 [8];
  int aiStack_448 [8];
  int aiStack_428 [8];
  double local_408;
  char local_400 [24];
  char local_3e8 [256];
  char local_2e8 [208];
  double local_218 [6];
  char local_1e8 [208];
  char local_118 [256];
  ulonglong local_18;
  
  local_18 = DAT_180032178 ^ (ulonglong)auStackY_5f8;
  local_560 = 0;
  pdVar2 = param_3;
  pdVar5 = param_4;
  local_488 = FUN_180021a60(7);
  local_500 = *(longlong **)(local_488 + 2);
  do {
    if (local_500 == (longlong *)0x0) {
      return;
    }
    local_5b8 = (undefined8 *)*local_500;
    if ((local_5b8[4] != 0) &&
       ((local_5b8[4] == 0 || (iVar1 = _stricmp((char *)local_5b8[4],""), iVar1 != 0)))) {
      if ((local_5b8 == (undefined8 *)0xffffffffffffffc8) ||
         (iVar1 = _stricmp((char *)(local_5b8 + 7),"GLE"), iVar1 != 0)) {
        if ((local_5b8 == (undefined8 *)0xffffffffffffffc8) ||
           (iVar1 = _stricmp((char *)(local_5b8 + 7),"INFIN"), iVar1 != 0)) {
          local_558 = (longlong *)local_5b8[2];
          local_470 = *local_5b8;
          local_490 = 0;
          local_510 = 0;
          local_504 = 0;
          local_50c = 0;
          local_48c = 0;
          local_598 = 0;
          strcpy(local_400,"");
          local_584 = -1;
          local_580 = -1;
          local_55c = -1;
          for (local_59c = 0; local_59c < 8; local_59c = local_59c + 1) {
            aiStack_468[local_59c] = -1;
            aiStack_448[local_59c] = -1;
            aiStack_428[local_59c] = -1;
          }
          local_5a4 = 0;
          local_5a0 = 0;
          local_588 = 0;
          local_594 = 0;
          local_590 = 0;
          local_548 = (char *)0x0;
          local_520 = (undefined *)0x0;
          local_518 = (double *)0x0;
          local_4f8 = (undefined *)0x0;
          local_59c = 1;
          local_578 = (double *)local_5b8[4];
          local_568 = (double *)local_5b8[6];
          while (local_59c <= *(short *)(local_5b8 + 3)) {
            if (local_578 != (double *)0x0) {
              local_5c0 = 0;
              while (((&PTR_DAT_18002e640)[(longlong)local_5c0 * 3] != (undefined *)0x0 &&
                     (iVar1 = _stricmp((&PTR_DAT_18002e640)[(longlong)local_5c0 * 3],
                                       (char *)local_578), iVar1 != 0))) {
                local_5c0 = local_5c0 + 1;
              }
              if (((&PTR_DAT_18002e648)[(longlong)local_5c0 * 3] == (undefined *)0x0) ||
                 (*(&PTR_DAT_18002e648)[(longlong)local_5c0 * 3] != 'T')) {
                if (((&PTR_DAT_18002e648)[(longlong)local_5c0 * 3] == (undefined *)0x0) ||
                   (*(&PTR_DAT_18002e648)[(longlong)local_5c0 * 3] != 'P')) {
                  if (((&PTR_DAT_18002e648)[(longlong)local_5c0 * 3] == (undefined *)0x0) ||
                     (*(&PTR_DAT_18002e648)[(longlong)local_5c0 * 3] != 'X')) {
                    if (((&PTR_DAT_18002e648)[(longlong)local_5c0 * 3] != (undefined *)0x0) &&
                       (*(&PTR_DAT_18002e648)[(longlong)local_5c0 * 3] == 'Y')) {
                      if (local_548 == (char *)0x0) {
                        pdVar2 = &local_478;
                        local_548 = FUN_1800082f0((char *)local_568,0x20,pdVar2);
                        if (local_548 == (char *)0x0) {
                          pdVar2 = local_568;
                          pdVar5 = local_578;
                          FUN_1800220b0(1,"Unit <%s> for property <%s> not supported by Aspen Plus",
                                        local_568,local_578);
                          goto LAB_180014165;
                        }
                        if (local_5b8[9] != 0) {
                          local_570 = (double *)((longlong)(local_59c + -1) * 0x14 + local_5b8[9]);
                          if (*(char *)local_570 == '%') {
                            local_58c = 1;
                          }
                          else if (*(char *)local_570 == '$') {
                            local_58c = -1;
                          }
                          else {
                            iVar1 = strcmp((char *)local_570,(char *)local_568);
                            if (iVar1 == 0) {
                              local_58c = 2;
                            }
                            else {
                              pdVar2 = local_570;
                              pdVar5 = local_578;
                              FUN_1800220b0(0,"ERR-UNIT <%s> for property <%s> differs from UNIT",
                                            local_570,local_578);
                              local_58c = -1;
                            }
                          }
                        }
                      }
                      aiStack_428[local_588] = local_59c;
                      local_588 = local_588 + 1;
                    }
                  }
                  else {
                    if (local_548 == (char *)0x0) {
                      pdVar2 = &local_478;
                      local_548 = FUN_1800082f0((char *)local_568,0x20,pdVar2);
                      if (local_548 == (char *)0x0) {
                        pdVar2 = local_568;
                        pdVar5 = local_578;
                        FUN_1800220b0(1,"Unit <%s> for property <%s> not supported by Aspen Plus",
                                      local_568,local_578);
                        goto LAB_180014165;
                      }
                      if (local_5b8[9] != 0) {
                        local_570 = (double *)((longlong)(local_59c + -1) * 0x14 + local_5b8[9]);
                        if (*(char *)local_570 == '%') {
                          local_58c = 1;
                        }
                        else if (*(char *)local_570 == '$') {
                          local_58c = -1;
                        }
                        else {
                          iVar1 = strcmp((char *)local_570,(char *)local_568);
                          if (iVar1 == 0) {
                            local_58c = 2;
                          }
                          else {
                            pdVar2 = local_570;
                            pdVar5 = local_578;
                            FUN_1800220b0(0,"ERR-UNIT <%s> for property <%s> differs from UNIT",
                                          local_570,local_578);
                            local_58c = -1;
                          }
                        }
                      }
                    }
                    if (local_5b8[5] == 0) {
                      aiStack_468[local_5a4] = local_59c;
                      local_5a4 = local_5a4 + 1;
                    }
                    else {
                      local_530 = (double *)((longlong)(local_59c + -1) * 0xd + local_5b8[5]);
                      iVar1 = strcmp((char *)local_530,"L1");
                      if ((iVar1 == 0) || (iVar1 = strcmp((char *)local_530,"L"), iVar1 == 0)) {
                        aiStack_468[local_5a4] = local_59c;
                        local_5a4 = local_5a4 + 1;
                      }
                      else {
                        iVar1 = strcmp((char *)local_530,"L2");
                        if (iVar1 == 0) {
                          aiStack_448[local_5a0] = local_59c;
                          local_5a0 = local_5a0 + 1;
                        }
                      }
                    }
                  }
                }
                else {
                  pdVar2 = &local_498;
                  local_518 = (double *)FUN_1800082f0((char *)local_568,0x16,pdVar2);
                  if (local_518 == (double *)0x0) {
                    pdVar2 = local_568;
                    pdVar5 = local_578;
                    FUN_1800220b0(1,"Unit <%s> for property <%s> not supported by Aspen Plus",
                                  local_568,local_578);
                  }
                  else {
                    local_580 = local_59c;
                    local_590 = local_590 + 1;
                  }
                  if (local_5b8[9] != 0) {
                    local_570 = (double *)((longlong)(local_59c + -1) * 0x14 + local_5b8[9]);
                    if (*(char *)local_570 == '%') {
                      local_54c = 1;
                    }
                    else if (*(char *)local_570 == '$') {
                      local_54c = -1;
                    }
                    else {
                      iVar1 = strcmp((char *)local_570,(char *)local_568);
                      if (iVar1 == 0) {
                        local_54c = 2;
                      }
                      else {
                        pdVar2 = local_570;
                        pdVar5 = local_578;
                        FUN_1800220b0(0,"ERR-UNIT <%s> for property <%s> differs from UNIT",
                                      local_570,local_578);
                        local_54c = -1;
                      }
                    }
                  }
                }
              }
              else {
                pdVar2 = local_4c8 + 5;
                local_520 = FUN_1800082f0((char *)local_568,0x19,pdVar2);
                if (local_520 == (undefined *)0x0) {
                  pdVar2 = local_568;
                  pdVar5 = local_578;
                  FUN_1800220b0(1,"Unit <%s> for property <%s> not supported by Aspen Plus",
                                local_568,local_578);
                }
                else {
                  local_584 = local_59c;
                  local_594 = local_594 + 1;
                }
                if (local_5b8[9] != 0) {
                  local_570 = (double *)((longlong)(local_59c + -1) * 0x14 + local_5b8[9]);
                  if (*(char *)local_570 == '%') {
                    local_550 = 1;
                  }
                  else if (*(char *)local_570 == '$') {
                    local_550 = -1;
                  }
                  else {
                    iVar1 = strcmp((char *)local_570,(char *)local_568);
                    if (iVar1 == 0) {
                      local_550 = 2;
                    }
                    else {
                      pdVar2 = local_570;
                      pdVar5 = local_578;
                      FUN_1800220b0(0,"ERR-UNIT <%s> for property <%s> differs from UNIT",local_570,
                                    local_578);
                      local_550 = -1;
                    }
                  }
                }
              }
            }
LAB_180014165:
            local_480 = local_578;
            local_59c = local_59c + 1;
            if (local_578 != (double *)0x0) {
              local_578 = (double *)((longlong)local_578 + 0xd);
            }
            local_568 = (double *)((longlong)local_568 + 0x14);
          }
          if ((local_584 == -1) || (local_580 == -1)) {
            if ((local_584 == -1) || (local_580 != -1)) {
              if ((local_584 != -1) || (local_580 == -1)) {
                FUN_1800220b0(0,"Neither T nor P given in TABLE - no DATA GROUP written",pdVar2,
                              pdVar5);
                goto LAB_180013ee0;
              }
              strcpy((char *)&local_408,"P");
            }
            else {
              strcpy((char *)&local_408,"T");
            }
          }
          else {
            strcpy((char *)&local_408,"TP");
          }
          if (((local_5a4 < 1) || (local_5a0 != 0)) && ((local_5a4 != 0 || (local_5a0 < 1)))) {
            if ((0 < local_5a4) && (0 < local_5a0)) {
              strcat((char *)&local_408,"XX");
            }
          }
          else if ((local_5b8 == (undefined8 *)0xffffffffffffffc8) ||
                  (iVar1 = strcmp((char *)(local_5b8 + 7),"LLE"), iVar1 != 0)) {
            strcat((char *)&local_408,"X");
          }
          else {
            strcat((char *)&local_408,"XX");
          }
          if (0 < local_588) {
            strcat((char *)&local_408,"Y");
          }
          if (((local_5a4 < 1) || (local_5a0 < 1)) || (local_5a4 == local_5a0)) {
            local_510 = (int)*(short *)(local_5b8 + 3);
            local_504 = local_594 + local_590 + local_5a4 + local_5a0 + local_588;
            local_50c = local_510 - local_504;
            if (0 < local_50c) {
              local_560 = 0;
              local_5a8 = 0;
              local_59c = 1;
              local_578 = (double *)local_5b8[4];
              local_568 = (double *)local_5b8[6];
              local_530 = (double *)local_5b8[5];
LAB_180014ba3:
              if (local_59c <= *(short *)(local_5b8 + 3)) {
                if (((local_578 == (double *)0x0) ||
                    (iVar1 = strcmp((char *)local_578,"T"), iVar1 == 0)) ||
                   ((iVar1 = strcmp((char *)local_578,"P"), iVar1 == 0 ||
                    ((iVar1 = strcmp((char *)local_578,"X"), iVar1 == 0 ||
                     (iVar1 = strcmp((char *)local_578,"Y"), iVar1 == 0)))))) break;
                local_538 = param_3;
                while ((*local_538 != 0.0 &&
                       ((iVar1 = strcmp((char *)*local_538,(char *)local_578), iVar1 != 0 ||
                        (*(char *)((longlong)local_538 + 0x14) != *(char *)local_530))))) {
                  local_538 = local_538 + 3;
                }
                if (local_538[1] == 0.0) {
LAB_180014e39:
                  if (local_55c < 1) {
                    pdVar2 = local_578;
                    pdVar5 = local_530;
                    FUN_1800220b0(0,
                                  "Property <%s> for phase <%s> not supported by Aspen Plus - no DATA GROUP written."
                                  ,local_578,local_530);
                  }
                }
                else {
                  if (*(int *)(local_538 + 2) == 0) {
                    local_4c8[0] = DAT_180026638;
LAB_180014d4e:
                    local_55c = local_59c;
                    if (local_5b8[9] != 0) {
                      local_570 = (double *)((longlong)(local_59c + -1) * 0x14 + local_5b8[9]);
                      if (*(char *)local_570 == '%') {
                        local_540 = 1;
                      }
                      else if (*(char *)local_570 == '$') {
                        local_540 = -1;
                      }
                      else {
                        iVar1 = strcmp((char *)local_570,(char *)local_568);
                        if (iVar1 == 0) {
                          local_540 = 2;
                        }
                        else {
                          pdVar2 = local_570;
                          pdVar5 = local_578;
                          FUN_1800220b0(0,"ERR-UNIT <%s> for property <%s> differs from UNIT",
                                        local_570,local_578);
                          local_540 = -1;
                        }
                      }
                    }
                    goto LAB_180014e39;
                  }
                  pdVar2 = local_4c8;
                  local_4f8 = FUN_1800082f0((char *)local_568,*(int *)(local_538 + 2),pdVar2);
                  if (local_4f8 != (undefined *)0x0) goto LAB_180014d4e;
                  pdVar2 = local_568;
                  pdVar5 = local_578;
                  FUN_1800220b0(0,
                                "Unit <%s> for property <%s> not supported by Aspen Plus - no DATA GROUP written."
                                ,local_568,local_578);
                }
              }
              if (local_55c < 0) {
                FUN_1800220b0(0,
                              "Incorrect property name or incorrect unit in TABLE - no DATA GROUP written."
                              ,pdVar2,pdVar5);
              }
              else {
                local_598 = 0;
                strcpy(local_400,(char *)local_538[1]);
                iVar1 = strcmp(local_400,"CPLMX");
                if (((((((iVar1 == 0) || (iVar1 = strcmp(local_400,"GAMMAM"), iVar1 == 0)) ||
                       (iVar1 = strcmp(local_400,"GLXS"), iVar1 == 0)) ||
                      ((iVar1 = strcmp(local_400,"HLMX"), iVar1 == 0 ||
                       (iVar1 = strcmp(local_400,"HLXS"), iVar1 == 0)))) ||
                     ((iVar1 = strcmp(local_400,"KLMX"), iVar1 == 0 ||
                      ((iVar1 = strcmp(local_400,"MULMX"), iVar1 == 0 ||
                       (iVar1 = strcmp(local_400,"OSMOT"), iVar1 == 0)))))) ||
                    (iVar1 = strcmp(local_400,"PH"), iVar1 == 0)) ||
                   (((((iVar1 = strcmp(local_400,"RHOLMX"), iVar1 == 0 ||
                       (iVar1 = strcmp(local_400,"SIGLMX"), iVar1 == 0)) ||
                      (iVar1 = strcmp(local_400,"VLMX"), iVar1 == 0)) ||
                     ((iVar1 = strcmp(local_400,"DLMX"), iVar1 == 0 ||
                      (iVar1 = strcmp(local_400,"GAMMA"), iVar1 == 0)))) ||
                    ((iVar1 = strcmp(local_400,"GAMMAS"), iVar1 == 0 ||
                     (iVar1 = strcmp(local_400,"HNRYMX"), iVar1 == 0)))))) {
                  strcpy((char *)&local_408,"TPX");
                  local_598 = 1;
                }
                iVar1 = strcmp(local_400,"CPVMX");
                if ((((iVar1 == 0) || (iVar1 = strcmp(local_400,"HVMX"), iVar1 == 0)) ||
                    ((iVar1 = strcmp(local_400,"KVMX"), iVar1 == 0 ||
                     (((iVar1 = strcmp(local_400,"MUVMX"), iVar1 == 0 ||
                       (iVar1 = strcmp(local_400,"RHOVMX"), iVar1 == 0)) ||
                      (iVar1 = strcmp(local_400,"VVMX"), iVar1 == 0)))))) ||
                   (iVar1 = strcmp(local_400,"DVMX"), iVar1 == 0)) {
                  strcpy((char *)&local_408,"TPY");
                  local_598 = 2;
                }
                strcpy(local_400,"");
                strcpy(local_1e8,"");
                strcpy(local_2e8,"");
                if ((local_584 < 1) || (local_580 < 1)) {
                  if ((local_584 < 1) || (-1 < local_580)) {
                    if ((local_584 < 0) && (0 < local_580)) {
                      FUN_180002d90(local_2e8,&DAT_180028df4,local_518,pdVar5);
                      strcat(local_1e8,local_2e8);
                    }
                  }
                  else {
                    FUN_180002d90(local_2e8,&DAT_180028df4,local_520,pdVar5);
                    strcat(local_1e8,local_2e8);
                  }
                }
                else {
                  pdVar5 = local_518;
                  FUN_180002d90(local_2e8,"%s %s ",local_520,local_518);
                  strcat(local_1e8,local_2e8);
                }
                FUN_180002d90(local_2e8,&DAT_180028df4,local_4f8,pdVar5);
                strcat(local_1e8,local_2e8);
                FUN_180002d90(local_2e8,"SYSTEM-DEF=%s ",&local_408,pdVar5);
                strcat(local_1e8,local_2e8);
                local_5c0 = 0;
                local_558 = (longlong *)local_5b8[2];
                for (; local_5c0 < *(short *)(local_5b8 + 1); local_5c0 = local_5c0 + 1) {
                  local_528 = *local_558;
                  FUN_180002d90(local_2e8,"COMP=%s ",local_528 + 0x240,pdVar5);
                  strcat(local_1e8,local_2e8);
                  local_558 = local_558 + 1;
                }
                FUN_180002d90(local_2e8,"PROP-LIST=%s ",local_538[1],pdVar5);
                strcat(local_1e8,local_2e8);
                if (local_548 != (char *)0x0) {
                  FUN_180002d90(local_2e8,&DAT_180028df4,local_548,pdVar5);
                  strcat(local_1e8,local_2e8);
                }
                *param_2 = *param_2 + 1;
                uVar4 = (ulonglong)*param_2;
                FUN_180007f00(param_1,"? PROPERTIES DATA MIXTURE \"DG-%d\" ? ",uVar4,pdVar5);
                FUN_180007f00(param_1," ; \"SI_MOLE\" ; \n",uVar4,pdVar5);
                pdVar2 = (double *)local_538[1];
                FUN_180007f00(param_1,"\\ \"SYSTEM-DEF\" STATESPEC = %s",pdVar2,pdVar5);
                FUN_180007f00(param_1," CIDS = (",pdVar2,pdVar5);
                local_5c0 = 0;
                local_558 = (longlong *)local_5b8[2];
                for (; local_5c0 < *(short *)(local_5b8 + 1); local_5c0 = local_5c0 + 1) {
                  local_528 = *local_558;
                  pdVar2 = (double *)(local_528 + 0x240);
                  FUN_180007f00(param_1,&DAT_180028ffc,pdVar2,pdVar5);
                  local_558 = local_558 + 1;
                }
                FUN_180007f00(param_1,&DAT_180029000,pdVar2,pdVar5);
                if (local_548 == (char *)0x0) {
                  FUN_180007f00(param_1," \\\\ USING ",pdVar2,pdVar5);
                }
                else {
                  strcpy((char *)local_218,"");
                  FUN_180004210(local_548,(longlong)local_218);
                  pdVar2 = local_218;
                  FUN_180007f00(param_1," COMPOSITION = \"%s\"  \\ \n",pdVar2,pdVar5);
                  FUN_180007f00(param_1," \\ USING ",pdVar2,pdVar5);
                }
                local_3e8[0] = '\0';
                local_4e0 = 0;
                local_4e8 = 0;
                local_118[0] = '\0';
                for (local_5c0 = 0; local_5c0 < *(short *)((longlong)local_5b8 + 0x5a);
                    local_5c0 = local_5c0 + 1) {
                  if (local_5c0 == 0) {
                    FUN_180007f00(param_1," USE = \"STD-DEV\" / \n",pdVar2,pdVar5);
                    strcpy(local_118,local_3e8);
                  }
                  local_5c8 = local_3e8;
                  pdVar2 = (double *)(ulonglong)(local_5c0 + 1);
                  FUN_180002d90(local_5c8,"  DATA    %2i",pdVar2,pdVar5);
                  if (local_5c0 == *(short *)((longlong)local_5b8 + 0x5a) + -1) {
                    FUN_180007f00(param_1," USE = DATA \\ \n",pdVar2,pdVar5);
                  }
                  else {
                    FUN_180007f00(param_1," USE = DATA / \n",pdVar2,pdVar5);
                  }
                }
                local_118[0] = '\0';
                local_4d0 = 0;
                local_4d8 = 0;
                local_3e8[0] = '\0';
                local_560 = 0;
                FUN_180007f00(param_1,"\\ DATA \n",pdVar2,pdVar5);
                for (local_5c0 = 0; local_5c0 < *(short *)((longlong)local_5b8 + 0x5a);
                    local_5c0 = local_5c0 + 1) {
                  if (local_5b8[9] != 0) {
                    local_5c8 = local_3e8;
                    local_4f0 = 0;
                    if (local_584 == -1) {
                      if (local_598 != 0) {
                        FUN_180007e70(0xb,local_3e8,(longlong *)&local_5c8);
                        FUN_180002d90(local_5c8," %-11s",&DAT_180028740,pdVar5);
                        sVar3 = strlen(local_5c8);
                        local_5c8 = local_5c8 + (int)sVar3;
                      }
                    }
                    else {
                      local_5b0 = (double *)
                                  (local_5b8[10] +
                                   (longlong)(local_5c0 * *(short *)(local_5b8 + 3)) * 0x10 + -0x10
                                  + (longlong)local_584 * 0x10);
                      FUN_180007e70(0xb,local_3e8,(longlong *)&local_5c8);
                      if ((local_550 == 1) && (local_5b0[1] != DAT_180029478)) {
                        FUN_180002d90(local_5c8," -%-10G",local_5b0[1],pdVar5);
                      }
                      else if ((local_550 == 2) && (local_5b0[1] != DAT_180029478)) {
                        FUN_180002d90(local_5c8," %-11G",local_5b0[1],pdVar5);
                      }
                      else {
                        FUN_180002d90(local_5c8," %-11s",&DAT_180028740,pdVar5);
                      }
                      sVar3 = strlen(local_5c8);
                      local_5c8 = local_5c8 + (int)sVar3;
                    }
                    if (local_580 == -1) {
                      if (local_598 != 0) {
                        FUN_180007e70(0xb,local_3e8,(longlong *)&local_5c8);
                        FUN_180002d90(local_5c8," %-11s",&DAT_180028740,pdVar5);
                        sVar3 = strlen(local_5c8);
                        local_5c8 = local_5c8 + (int)sVar3;
                      }
                    }
                    else {
                      local_5b0 = (double *)
                                  (local_5b8[10] +
                                   (longlong)(local_5c0 * *(short *)(local_5b8 + 3)) * 0x10 + -0x10
                                  + (longlong)local_580 * 0x10);
                      FUN_180007e70(0xb,local_3e8,(longlong *)&local_5c8);
                      if ((local_54c == 1) && (local_5b0[1] != DAT_180029478)) {
                        FUN_180002d90(local_5c8," -%-10G",local_5b0[1],pdVar5);
                      }
                      else if ((local_54c == 2) && (local_5b0[1] != DAT_180029478)) {
                        FUN_180002d90(local_5c8," %-11G",local_5b0[1],pdVar5);
                      }
                      else {
                        FUN_180002d90(local_5c8," %-11s",&DAT_180028740,pdVar5);
                      }
                      sVar3 = strlen(local_5c8);
                      local_5c8 = local_5c8 + (int)sVar3;
                    }
                    for (local_5bc = 0; local_5bc < *(short *)(local_5b8 + 1) + -1;
                        local_5bc = local_5bc + 1) {
                      if (aiStack_468[local_5bc] == -1) {
                        if ((local_598 == 1) && (local_5a0 < 0)) {
                          FUN_180007e70(0xb,local_3e8,(longlong *)&local_5c8);
                          FUN_180002d90(local_5c8," %-11s",&DAT_180028740,pdVar5);
                          sVar3 = strlen(local_5c8);
                          local_5c8 = local_5c8 + (int)sVar3;
                        }
                      }
                      else {
                        if (local_598 == 2) break;
                        local_5b0 = (double *)
                                    (local_5b8[10] +
                                     (longlong)(local_5c0 * *(short *)(local_5b8 + 3)) * 0x10 +
                                     -0x10 + (longlong)aiStack_468[local_5bc] * 0x10);
                        FUN_180007e70(0xb,local_3e8,(longlong *)&local_5c8);
                        if ((local_58c == 1) && (local_5b0[1] != DAT_180029478)) {
                          FUN_180002d90(local_5c8," -%-10G",local_5b0[1],pdVar5);
                        }
                        else if ((local_58c == 2) && (local_5b0[1] != DAT_180029478)) {
                          FUN_180002d90(local_5c8," %-11G",local_5b0[1],pdVar5);
                        }
                        else {
                          FUN_180002d90(local_5c8," %-11s",&DAT_180028740,pdVar5);
                        }
                        sVar3 = strlen(local_5c8);
                        local_5c8 = local_5c8 + (int)sVar3;
                      }
                    }
                    local_5bc = 0;
                    while (((local_5bc < *(short *)(local_5b8 + 1) + -1 && (local_598 != 2)) &&
                           ((local_598 != 1 || (local_5a4 < 1))))) {
                      if (aiStack_448[local_5bc] == -1) {
                        if (local_598 == 1) {
                          FUN_180007e70(0xb,local_3e8,(longlong *)&local_5c8);
                          FUN_180002d90(local_5c8," %-11s",&DAT_180028740,pdVar5);
                          sVar3 = strlen(local_5c8);
                          local_5c8 = local_5c8 + (int)sVar3;
                        }
                      }
                      else {
                        FUN_180007e70(0xb,local_3e8,(longlong *)&local_5c8);
                        local_5b0 = (double *)
                                    (local_5b8[10] +
                                     (longlong)(local_5c0 * *(short *)(local_5b8 + 3)) * 0x10 +
                                     -0x10 + (longlong)aiStack_448[local_5bc] * 0x10);
                        if ((local_58c == 1) && (local_5b0[1] != DAT_180029478)) {
                          FUN_180002d90(local_5c8," -%-10G",local_5b0[1],pdVar5);
                        }
                        else if ((local_58c == 2) && (local_5b0[1] != DAT_180029478)) {
                          FUN_180002d90(local_5c8," %-11G",local_5b0[1],pdVar5);
                        }
                        else {
                          FUN_180002d90(local_5c8," %-11s",&DAT_180028740,pdVar5);
                        }
                        sVar3 = strlen(local_5c8);
                        local_5c8 = local_5c8 + (int)sVar3;
                      }
                      local_5bc = local_5bc + 1;
                    }
                    local_5bc = 0;
                    while ((local_5bc < *(short *)(local_5b8 + 1) + -1 && (local_598 != 1))) {
                      if (aiStack_428[local_5bc] == -1) {
                        if (local_598 == 2) {
                          FUN_180007e70(0xb,local_3e8,(longlong *)&local_5c8);
                          FUN_180002d90(local_5c8," %-11s",&DAT_180028740,pdVar5);
                          sVar3 = strlen(local_5c8);
                          local_5c8 = local_5c8 + (int)sVar3;
                        }
                      }
                      else {
                        FUN_180007e70(0xb,local_3e8,(longlong *)&local_5c8);
                        local_5b0 = (double *)
                                    (local_5b8[10] +
                                     (longlong)(local_5c0 * *(short *)(local_5b8 + 3)) * 0x10 +
                                     -0x10 + (longlong)aiStack_428[local_5bc] * 0x10);
                        if ((local_58c == 1) && (local_5b0[1] != DAT_180029478)) {
                          FUN_180002d90(local_5c8," -%-10G",local_5b0[1],pdVar5);
                        }
                        else if ((local_58c == 2) && (local_5b0[1] != DAT_180029478)) {
                          FUN_180002d90(local_5c8," %-11G",local_5b0[1],pdVar5);
                        }
                        else {
                          FUN_180002d90(local_5c8," %-11s",&DAT_180028740,pdVar5);
                        }
                        sVar3 = strlen(local_5c8);
                        local_5c8 = local_5c8 + (int)sVar3;
                      }
                      local_5bc = local_5bc + 1;
                    }
                    if (local_55c != -1) {
                      FUN_180007e70(0xb,local_3e8,(longlong *)&local_5c8);
                      local_5b0 = (double *)
                                  (local_5b8[10] +
                                   (longlong)(local_5c0 * *(short *)(local_5b8 + 3)) * 0x10 + -0x10
                                  + (longlong)local_55c * 0x10);
                      if ((local_540 == 1) && (local_5b0[1] != DAT_180029478)) {
                        FUN_180002d90(local_5c8," -%-10G",local_5b0[1],pdVar5);
                      }
                      else if ((local_540 == 2) && (local_5b0[1] != DAT_180029478)) {
                        FUN_180002d90(local_5c8," %-11G",local_5b0[1],pdVar5);
                      }
                      else {
                        FUN_180002d90(local_5c8," %-11s",&DAT_180028740,pdVar5);
                      }
                      sVar3 = strlen(local_5c8);
                      local_5c8 = local_5c8 + (int)sVar3;
                    }
                  }
                  if ((local_5c0 == 0) || (iVar1 = strcmp(local_118,local_3e8), iVar1 != 0)) {
                    strcpy(local_118,local_3e8);
                    FUN_180002d90(local_2e8,"  STD-DEV %2i%s\n",(ulonglong)(local_5c0 + 1),local_3e8
                                 );
                    pdVar5 = (double *)&local_560;
                    FUN_180004510(local_2e8,local_1e8,0,(uint *)pdVar5,param_1,0);
                  }
                  local_5c8 = local_3e8;
                  puVar6 = (undefined *)(ulonglong)(local_5c0 + 1);
                  FUN_180002d90(local_5c8,"  DATA    %2i",puVar6,pdVar5);
                  sVar3 = strlen(local_5c8);
                  local_5c8 = local_5c8 + (int)sVar3;
                  if (local_584 == -1) {
                    if (local_598 != 0) {
                      FUN_180007e70(0xb,local_3e8,(longlong *)&local_5c8);
                      puVar6 = &DAT_180028740;
                      FUN_180002d90(local_5c8," %-11s",&DAT_180028740,pdVar5);
                      sVar3 = strlen(local_5c8);
                      local_5c8 = local_5c8 + (int)sVar3;
                    }
                  }
                  else {
                    FUN_180007e70(0xb,local_3e8,(longlong *)&local_5c8);
                    local_5b0 = (double *)
                                (local_5b8[10] +
                                 (longlong)(local_5c0 * *(short *)(local_5b8 + 3)) * 0x10 + -0x10 +
                                (longlong)local_584 * 0x10);
                    if (*local_5b0 == DAT_180029478) {
                      puVar6 = &DAT_180028740;
                      FUN_180002d90(local_5c8," %-11s",&DAT_180028740,pdVar5);
                    }
                    else {
                      puVar6 = (undefined *)(*local_5b0 * local_4c8[5]);
                      FUN_180002d90(local_5c8," %-11G",puVar6,pdVar5);
                    }
                    sVar3 = strlen(local_5c8);
                    local_5c8 = local_5c8 + (int)sVar3;
                  }
                  if (local_580 == -1) {
                    if (local_598 != 0) {
                      FUN_180007e70(0xb,local_3e8,(longlong *)&local_5c8);
                      puVar6 = &DAT_180028740;
                      FUN_180002d90(local_5c8," %-11s",&DAT_180028740,pdVar5);
                      sVar3 = strlen(local_5c8);
                      local_5c8 = local_5c8 + (int)sVar3;
                    }
                  }
                  else {
                    FUN_180007e70(0xb,local_3e8,(longlong *)&local_5c8);
                    local_5b0 = (double *)
                                (local_5b8[10] +
                                 (longlong)(local_5c0 * *(short *)(local_5b8 + 3)) * 0x10 + -0x10 +
                                (longlong)local_580 * 0x10);
                    if (*local_5b0 == DAT_180029478) {
                      puVar6 = &DAT_180028740;
                      FUN_180002d90(local_5c8," %-11s",&DAT_180028740,pdVar5);
                    }
                    else {
                      puVar6 = (undefined *)(*local_5b0 * local_498);
                      FUN_180002d90(local_5c8," %-11G",puVar6,pdVar5);
                    }
                    sVar3 = strlen(local_5c8);
                    local_5c8 = local_5c8 + (int)sVar3;
                  }
                  local_5bc = 0;
                  while ((local_5bc < *(short *)(local_5b8 + 1) + -1 && (local_598 != 2))) {
                    if (aiStack_468[local_5bc] == -1) {
                      if ((local_598 == 1) && (local_5a0 < 0)) {
                        FUN_180007e70(0xb,local_3e8,(longlong *)&local_5c8);
                        puVar6 = &DAT_180028740;
                        FUN_180002d90(local_5c8," %-11s",&DAT_180028740,pdVar5);
                        sVar3 = strlen(local_5c8);
                        local_5c8 = local_5c8 + (int)sVar3;
                      }
                    }
                    else {
                      FUN_180007e70(0xb,local_3e8,(longlong *)&local_5c8);
                      local_5b0 = (double *)
                                  (local_5b8[10] +
                                   (longlong)(local_5c0 * *(short *)(local_5b8 + 3)) * 0x10 + -0x10
                                  + (longlong)aiStack_468[local_5bc] * 0x10);
                      if (*local_5b0 == DAT_180029478) {
                        puVar6 = &DAT_180028740;
                        FUN_180002d90(local_5c8," %-11s",&DAT_180028740,pdVar5);
                      }
                      else {
                        puVar6 = (undefined *)*local_5b0;
                        FUN_180002d90(local_5c8," %-11G",puVar6,pdVar5);
                      }
                      sVar3 = strlen(local_5c8);
                      local_5c8 = local_5c8 + (int)sVar3;
                    }
                    local_5bc = local_5bc + 1;
                  }
                  local_5bc = 0;
                  while (((local_5bc < *(short *)(local_5b8 + 1) + -1 && (local_598 != 2)) &&
                         ((local_598 != 1 || (local_5a4 < 1))))) {
                    if (aiStack_448[local_5bc] == -1) {
                      if (local_598 == 1) {
                        FUN_180007e70(0xb,local_3e8,(longlong *)&local_5c8);
                        puVar6 = &DAT_180028740;
                        FUN_180002d90(local_5c8," %-11s",&DAT_180028740,pdVar5);
                        sVar3 = strlen(local_5c8);
                        local_5c8 = local_5c8 + (int)sVar3;
                      }
                    }
                    else {
                      FUN_180007e70(0xb,local_3e8,(longlong *)&local_5c8);
                      local_5b0 = (double *)
                                  (local_5b8[10] +
                                   (longlong)(local_5c0 * *(short *)(local_5b8 + 3)) * 0x10 + -0x10
                                  + (longlong)aiStack_448[local_5bc] * 0x10);
                      if (*local_5b0 == DAT_180029478) {
                        puVar6 = &DAT_180028740;
                        FUN_180002d90(local_5c8," %-11s",&DAT_180028740,pdVar5);
                      }
                      else {
                        puVar6 = (undefined *)*local_5b0;
                        FUN_180002d90(local_5c8," %-11G",puVar6,pdVar5);
                      }
                      sVar3 = strlen(local_5c8);
                      local_5c8 = local_5c8 + (int)sVar3;
                    }
                    local_5bc = local_5bc + 1;
                  }
                  local_5bc = 0;
                  while ((local_5bc < *(short *)(local_5b8 + 1) + -1 && (local_598 != 1))) {
                    if (aiStack_428[local_5bc] == -1) {
                      if (local_598 == 2) {
                        FUN_180007e70(0xb,local_3e8,(longlong *)&local_5c8);
                        puVar6 = &DAT_180028740;
                        FUN_180002d90(local_5c8," %-11s",&DAT_180028740,pdVar5);
                        sVar3 = strlen(local_5c8);
                        local_5c8 = local_5c8 + (int)sVar3;
                      }
                    }
                    else {
                      FUN_180007e70(0xb,local_3e8,(longlong *)&local_5c8);
                      local_5b0 = (double *)
                                  (local_5b8[10] +
                                   (longlong)(local_5c0 * *(short *)(local_5b8 + 3)) * 0x10 + -0x10
                                  + (longlong)aiStack_428[local_5bc] * 0x10);
                      if (*local_5b0 == DAT_180029478) {
                        puVar6 = &DAT_180028740;
                        FUN_180002d90(local_5c8," %-11s",&DAT_180028740,pdVar5);
                      }
                      else {
                        puVar6 = (undefined *)*local_5b0;
                        FUN_180002d90(local_5c8," %-11G",puVar6,pdVar5);
                      }
                      sVar3 = strlen(local_5c8);
                      local_5c8 = local_5c8 + (int)sVar3;
                    }
                    local_5bc = local_5bc + 1;
                  }
                  if (local_55c != -1) {
                    FUN_180007e70(0xb,local_3e8,(longlong *)&local_5c8);
                    local_5b0 = (double *)
                                (local_5b8[10] +
                                 (longlong)(local_5c0 * *(short *)(local_5b8 + 3)) * 0x10 + -0x10 +
                                (longlong)local_55c * 0x10);
                    if (*local_5b0 == DAT_180029478) {
                      puVar6 = &DAT_180028740;
                      FUN_180002d90(local_5c8," %-11s",&DAT_180028740,pdVar5);
                    }
                    else {
                      puVar6 = (undefined *)(*local_5b0 * local_4c8[0]);
                      FUN_180002d90(local_5c8," %-11G",puVar6,pdVar5);
                    }
                    sVar3 = strlen(local_5c8);
                    local_5c8 = local_5c8 + (int)sVar3;
                  }
                  FUN_180002d90(local_5c8,&DAT_180027258,puVar6,pdVar5);
                  local_508 = (uint)(local_5c0 == *(short *)((longlong)local_5b8 + 0x5a) + -1);
                  pdVar5 = (double *)&local_560;
                  pdVar2 = (double *)0x1;
                  FUN_180004510(local_3e8,local_1e8,1,(uint *)pdVar5,param_1,local_508);
                }
                FUN_180007f00(param_1,&DAT_180029034,pdVar2,pdVar5);
                local_598 = 0;
              }
              goto LAB_180013ee0;
            }
            local_560 = 0;
            local_5a8 = 0;
            if ((local_5b8 == (undefined8 *)0xffffffffffffffc8) ||
               (iVar1 = strcmp((char *)(local_5b8 + 7),"LLE"), iVar1 != 0)) {
              if ((local_5b8 == (undefined8 *)0xffffffffffffffc8) ||
                 (iVar1 = strcmp((char *)(local_5b8 + 7),"VLE"), iVar1 != 0)) {
                if ((local_5b8 == (undefined8 *)0xffffffffffffffc8) ||
                   (iVar1 = strcmp((char *)(local_5b8 + 7),"VLLE"), iVar1 != 0)) {
                  if ((local_5b8 == (undefined8 *)0xffffffffffffffc8) ||
                     (iVar1 = strcmp((char *)(local_5b8 + 7),"AZEO"), iVar1 != 0)) {
                    if ((((local_594 < 1) || (local_590 < 1)) || (local_5a4 < 1)) ||
                       ((local_5a0 < 1 || (local_588 < 1)))) {
                      if ((((local_594 < 1) || ((local_590 < 1 || (local_5a4 < 1)))) ||
                          (local_5a0 < 1)) || (local_588 != 0)) {
                        if ((((local_594 < 1) || (local_590 != 0)) || (local_5a4 < 1)) ||
                           ((local_5a0 < 1 || (local_588 != 0)))) {
                          if ((((local_594 < 1) || ((local_590 != 0 || (local_5a4 < 1)))) ||
                              ((local_5a0 != 0 || (local_588 != 0)))) &&
                             ((((local_594 < 1 || (local_590 != 0)) || (local_5a4 != 0)) ||
                              ((local_5a0 < 1 || (local_588 != 0)))))) {
                            if ((((((((0 < local_594) && (0 < local_590)) &&
                                    ((0 < local_5a4 && ((local_5a0 == 0 && (0 < local_588)))))) ||
                                   ((0 < local_594 &&
                                    ((((0 < local_590 && (local_5a4 == 0)) && (0 < local_5a0)) &&
                                     (0 < local_588)))))) ||
                                  (((0 < local_594 && (0 < local_590)) &&
                                   ((local_5a4 == 0 && ((0 < local_5a0 && (local_588 == 0)))))))) ||
                                 ((0 < local_594 &&
                                  ((((0 < local_590 && (0 < local_5a4)) && (local_5a0 == 0)) &&
                                   (local_588 == 0)))))) ||
                                (((((0 < local_594 && (local_590 == 0)) &&
                                   ((local_5a4 == 0 && ((0 < local_5a0 && (0 < local_588)))))) ||
                                  (((0 < local_594 &&
                                    (((local_590 == 0 && (0 < local_5a4)) && (local_5a0 == 0)))) &&
                                   (0 < local_588)))) ||
                                 (((local_594 == 0 && (0 < local_590)) &&
                                  ((local_5a4 == 0 && ((0 < local_5a0 && (0 < local_588)))))))))) ||
                               ((local_594 == 0 &&
                                ((((0 < local_590 && (0 < local_5a4)) && (local_5a0 == 0)) &&
                                 (0 < local_588)))))) {
                              strcpy((char *)&local_408,"TPXY");
                              local_5a8 = 2;
                            }
                          }
                          else {
                            strcpy((char *)&local_408,"TXX");
                            local_5a8 = 5;
                          }
                        }
                        else {
                          strcpy((char *)&local_408,"TXX");
                          local_5a8 = 5;
                        }
                      }
                      else {
                        strcpy((char *)&local_408,"TPXX");
                        local_5a8 = 1;
                      }
                    }
                    else {
                      strcpy((char *)&local_408,"TPXXY");
                      local_5a8 = 3;
                    }
                  }
                  else {
                    strcpy((char *)&local_408,"TPXY");
                    local_5a8 = 4;
                  }
                }
                else {
                  strcpy((char *)&local_408,"TPXXY");
                  local_5a8 = 3;
                }
              }
              else {
                strcpy((char *)&local_408,"TPXY");
                local_5a8 = 2;
              }
            }
            else if ((((local_594 < 1) || (local_590 < 1)) ||
                     ((((local_5a4 < 1 || (local_5a0 < 1)) && ((local_5a4 < 1 || (local_5a0 != 0))))
                      && ((local_5a4 != 0 || (local_5a0 < 1)))))) &&
                    ((((local_594 != 0 || (local_590 < 1)) || (local_5a4 < 1)) || (local_5a0 < 1))))
            {
              if (((0 < local_594) && (local_590 == 0)) &&
                 (((0 < local_5a4 && (0 < local_5a0)) ||
                  (((0 < local_5a4 && (local_5a0 == 0)) || ((local_5a4 == 0 && (0 < local_5a0)))))))
                 ) {
                strcpy((char *)&local_408,"TXX");
                local_5a8 = 5;
              }
            }
            else {
              strcpy((char *)&local_408,"TPXX");
              local_5a8 = 1;
            }
            strcpy(local_1e8,"");
            strcpy(local_2e8,"");
            if ((local_584 < 1) || (local_580 < 1)) {
              if ((local_584 < 1) || (-1 < local_580)) {
                if ((local_584 < 0) && (0 < local_580)) {
                  FUN_180002d90(local_2e8,&DAT_180028df4,local_518,pdVar5);
                  strcat(local_1e8,local_2e8);
                }
              }
              else {
                FUN_180002d90(local_2e8,&DAT_180028df4,local_520,pdVar5);
                strcat(local_1e8,local_2e8);
              }
            }
            else {
              pdVar5 = local_518;
              FUN_180002d90(local_2e8,"%s %s ",local_520,local_518);
              strcat(local_1e8,local_2e8);
            }
            FUN_180002d90(local_2e8,&DAT_180028df4,"EQB=\'EQB\'",pdVar5);
            strcat(local_1e8,local_2e8);
            pdVar2 = &local_408;
            FUN_180002d90(local_2e8,"SYSTEM-DEF=%s ",pdVar2,pdVar5);
            strcat(local_1e8,local_2e8);
            local_5c0 = 0;
            local_558 = (longlong *)local_5b8[2];
            for (; local_5c0 < *(short *)(local_5b8 + 1); local_5c0 = local_5c0 + 1) {
              local_528 = *local_558;
              pdVar2 = (double *)(local_528 + 0x240);
              FUN_180002d90(local_2e8,"COMP=%s ",pdVar2,pdVar5);
              strcat(local_1e8,local_2e8);
              local_558 = local_558 + 1;
            }
            FUN_180002d90(local_2e8,"PROP-LIST=EQB ",pdVar2,pdVar5);
            strcat(local_1e8,local_2e8);
            if (local_548 != (char *)0x0) {
              FUN_180002d90(local_2e8,&DAT_180028df4,local_548,pdVar5);
              strcat(local_1e8,local_2e8);
            }
            *param_2 = *param_2 + 1;
            uVar4 = (ulonglong)*param_2;
            FUN_180007f00(param_1,"? PROPERTIES DATA MIXTURE \"DG-%d\" ? ",uVar4,pdVar5);
            FUN_180007f00(param_1," ; \"SI_MOLE\" ; \n",uVar4,pdVar5);
            pdVar2 = &local_408;
            FUN_180007f00(param_1,"\\ \"SYSTEM-DEF\" STATESPEC = %s",pdVar2,pdVar5);
            FUN_180007f00(param_1," CIDS = (",pdVar2,pdVar5);
            local_5c0 = 0;
            local_558 = (longlong *)local_5b8[2];
            for (; local_5c0 < *(short *)(local_5b8 + 1); local_5c0 = local_5c0 + 1) {
              local_528 = *local_558;
              pdVar2 = (double *)(local_528 + 0x240);
              FUN_180007f00(param_1,&DAT_180028ffc,pdVar2,pdVar5);
              local_558 = local_558 + 1;
            }
            FUN_180007f00(param_1,&DAT_180029000,pdVar2,pdVar5);
            if (local_548 == (char *)0x0) {
              FUN_180007f00(param_1," \\\\ USING ",pdVar2,pdVar5);
            }
            else {
              strcpy((char *)local_218,"");
              FUN_180004210(local_548,(longlong)local_218);
              iVar1 = strcmp(local_548,"COMPOSITION=WEIGHT-PERCENT");
              if (iVar1 == 0) {
                strcpy((char *)local_218,"MASS-PCT");
              }
              pdVar2 = local_218;
              FUN_180007f00(param_1," COMPOSITION = \"%s\"  \\ \n",pdVar2,pdVar5);
              FUN_180007f00(param_1," \\ USING ",pdVar2,pdVar5);
            }
            local_3e8[0] = '\0';
            local_4c8[2] = 0.0;
            local_4c8[1] = 0.0;
            local_118[0] = '\0';
            for (local_5c0 = 0; local_5c0 < *(short *)((longlong)local_5b8 + 0x5a);
                local_5c0 = local_5c0 + 1) {
              if (local_5c0 == 0) {
                FUN_180007f00(param_1," USE = \"STD-DEV\" / \n",pdVar2,pdVar5);
                strcpy(local_118,local_3e8);
              }
              local_5c8 = local_3e8;
              pdVar2 = (double *)(ulonglong)(local_5c0 + 1);
              FUN_180002d90(local_5c8,"  DATA    %2i",pdVar2,pdVar5);
              if (local_5c0 == *(short *)((longlong)local_5b8 + 0x5a) + -1) {
                FUN_180007f00(param_1," USE = DATA \\ \n",pdVar2,pdVar5);
              }
              else {
                FUN_180007f00(param_1," USE = DATA / \n",pdVar2,pdVar5);
              }
            }
            local_118[0] = '\0';
            local_4c8[4] = 0.0;
            local_4c8[3] = 0.0;
            local_3e8[0] = '\0';
            local_560 = 0;
            FUN_180007f00(param_1,"\\ DATA \n",pdVar2,pdVar5);
            for (local_5c0 = 0; local_5c0 < *(short *)((longlong)local_5b8 + 0x5a);
                local_5c0 = local_5c0 + 1) {
              if (local_5b8[9] != 0) {
                local_5c8 = local_3e8;
                local_4f0 = 0;
                if (local_584 == -1) {
                  if (local_5a8 != 0) {
                    FUN_180007e70(0xb,local_3e8,(longlong *)&local_5c8);
                    FUN_180002d90(local_5c8," %-11s",&DAT_180028740,pdVar5);
                    sVar3 = strlen(local_5c8);
                    local_5c8 = local_5c8 + (int)sVar3;
                  }
                }
                else {
                  local_5b0 = (double *)
                              (local_5b8[10] +
                               (longlong)(local_5c0 * *(short *)(local_5b8 + 3)) * 0x10 + -0x10 +
                              (longlong)local_584 * 0x10);
                  FUN_180007e70(0xb,local_3e8,(longlong *)&local_5c8);
                  if ((local_550 == 1) && (local_5b0[1] != DAT_180029478)) {
                    FUN_180002d90(local_5c8," -%-10G",local_5b0[1],pdVar5);
                  }
                  else if ((local_550 == 2) && (local_5b0[1] != DAT_180029478)) {
                    FUN_180002d90(local_5c8," %-11G",local_5b0[1],pdVar5);
                  }
                  else {
                    FUN_180002d90(local_5c8," %-11s",&DAT_180028740,pdVar5);
                  }
                  sVar3 = strlen(local_5c8);
                  local_5c8 = local_5c8 + (int)sVar3;
                }
                if (local_580 == -1) {
                  if ((((local_5a8 == 1) || (local_5a8 == 2)) || (local_5a8 == 3)) ||
                     (local_5a8 == 4)) {
                    FUN_180007e70(0xb,local_3e8,(longlong *)&local_5c8);
                    FUN_180002d90(local_5c8," %-11s",&DAT_180028740,pdVar5);
                    sVar3 = strlen(local_5c8);
                    local_5c8 = local_5c8 + (int)sVar3;
                  }
                }
                else {
                  local_5b0 = (double *)
                              (local_5b8[10] +
                               (longlong)(local_5c0 * *(short *)(local_5b8 + 3)) * 0x10 + -0x10 +
                              (longlong)local_580 * 0x10);
                  FUN_180007e70(0xb,local_3e8,(longlong *)&local_5c8);
                  if ((local_54c == 1) && (local_5b0[1] != DAT_180029478)) {
                    FUN_180002d90(local_5c8," -%-10G",local_5b0[1],pdVar5);
                  }
                  else if ((local_54c == 2) && (local_5b0[1] != DAT_180029478)) {
                    FUN_180002d90(local_5c8," %-11G",local_5b0[1],pdVar5);
                  }
                  else {
                    FUN_180002d90(local_5c8," %-11s",&DAT_180028740,pdVar5);
                  }
                  sVar3 = strlen(local_5c8);
                  local_5c8 = local_5c8 + (int)sVar3;
                }
                for (local_5bc = 0; local_5bc < *(short *)(local_5b8 + 1) + -1;
                    local_5bc = local_5bc + 1) {
                  if (aiStack_468[local_5bc] == -1) {
                    if (((local_5a8 == 1) || (local_5a8 == 3)) ||
                       ((local_5a8 == 5 || ((local_5a8 == 2 && (local_5a0 < 0)))))) {
                      FUN_180007e70(0xb,local_3e8,(longlong *)&local_5c8);
                      FUN_180002d90(local_5c8," %-11s",&DAT_180028740,pdVar5);
                      sVar3 = strlen(local_5c8);
                      local_5c8 = local_5c8 + (int)sVar3;
                    }
                  }
                  else {
                    local_5b0 = (double *)
                                (local_5b8[10] +
                                 (longlong)(local_5c0 * *(short *)(local_5b8 + 3)) * 0x10 + -0x10 +
                                (longlong)aiStack_468[local_5bc] * 0x10);
                    FUN_180007e70(0xb,local_3e8,(longlong *)&local_5c8);
                    if ((local_58c == 1) && (local_5b0[1] != DAT_180029478)) {
                      FUN_180002d90(local_5c8," -%-10G",local_5b0[1],pdVar5);
                    }
                    else if ((local_58c == 2) && (local_5b0[1] != DAT_180029478)) {
                      FUN_180002d90(local_5c8," %-11G",local_5b0[1],pdVar5);
                    }
                    else {
                      FUN_180002d90(local_5c8," %-11s",&DAT_180028740,pdVar5);
                    }
                    sVar3 = strlen(local_5c8);
                    local_5c8 = local_5c8 + (int)sVar3;
                  }
                }
                for (local_5bc = 0; local_5bc < *(short *)(local_5b8 + 1) + -1;
                    local_5bc = local_5bc + 1) {
                  if (aiStack_448[local_5bc] == -1) {
                    if (((local_5a8 == 1) || (local_5a8 == 3)) || (local_5a8 == 5)) {
                      FUN_180007e70(0xb,local_3e8,(longlong *)&local_5c8);
                      FUN_180002d90(local_5c8," %-11s",&DAT_180028740,pdVar5);
                      sVar3 = strlen(local_5c8);
                      local_5c8 = local_5c8 + (int)sVar3;
                    }
                  }
                  else {
                    FUN_180007e70(0xb,local_3e8,(longlong *)&local_5c8);
                    local_5b0 = (double *)
                                (local_5b8[10] +
                                 (longlong)(local_5c0 * *(short *)(local_5b8 + 3)) * 0x10 + -0x10 +
                                (longlong)aiStack_448[local_5bc] * 0x10);
                    if ((local_58c == 1) && (local_5b0[1] != DAT_180029478)) {
                      FUN_180002d90(local_5c8," -%-10G",local_5b0[1],pdVar5);
                    }
                    else if ((local_58c == 2) && (local_5b0[1] != DAT_180029478)) {
                      FUN_180002d90(local_5c8," %-11G",local_5b0[1],pdVar5);
                    }
                    else {
                      FUN_180002d90(local_5c8," %-11s",&DAT_180028740,pdVar5);
                    }
                    sVar3 = strlen(local_5c8);
                    local_5c8 = local_5c8 + (int)sVar3;
                  }
                }
                for (local_5bc = 0; local_5bc < *(short *)(local_5b8 + 1) + -1;
                    local_5bc = local_5bc + 1) {
                  if (aiStack_428[local_5bc] == -1) {
                    if (((local_5a8 == 2) || (local_5a8 == 3)) || (local_5a8 == 4)) {
                      FUN_180007e70(0xb,local_3e8,(longlong *)&local_5c8);
                      FUN_180002d90(local_5c8," %-11s",&DAT_180028740,pdVar5);
                      sVar3 = strlen(local_5c8);
                      local_5c8 = local_5c8 + (int)sVar3;
                    }
                  }
                  else {
                    FUN_180007e70(0xb,local_3e8,(longlong *)&local_5c8);
                    local_5b0 = (double *)
                                (local_5b8[10] +
                                 (longlong)(local_5c0 * *(short *)(local_5b8 + 3)) * 0x10 + -0x10 +
                                (longlong)aiStack_428[local_5bc] * 0x10);
                    if ((local_58c == 1) && (local_5b0[1] != DAT_180029478)) {
                      FUN_180002d90(local_5c8," -%-10G",local_5b0[1],pdVar5);
                    }
                    else if ((local_58c == 2) && (local_5b0[1] != DAT_180029478)) {
                      FUN_180002d90(local_5c8," %-11G",local_5b0[1],pdVar5);
                    }
                    else {
                      FUN_180002d90(local_5c8," %-11s",&DAT_180028740,pdVar5);
                    }
                    sVar3 = strlen(local_5c8);
                    local_5c8 = local_5c8 + (int)sVar3;
                  }
                }
                if ((local_5c0 != 0) && (iVar1 = strcmp(local_118,local_3e8), iVar1 != 0)) {
                  strcpy(local_118,local_3e8);
                  FUN_180002d90(local_2e8,"  STD-DEV %2i%s\n",(ulonglong)(local_5c0 + 1),local_3e8);
                  pdVar5 = (double *)&local_560;
                  FUN_180004510(local_2e8,local_1e8,0,(uint *)pdVar5,param_1,0);
                }
              }
              if (local_5c0 == 0) {
                strcpy(local_118,local_3e8);
                FUN_180002d90(local_2e8,"  STD-DEV %2i%s\n",(ulonglong)(local_5c0 + 1),local_3e8);
                pdVar5 = (double *)&local_560;
                FUN_180004510(local_2e8,local_1e8,0,(uint *)pdVar5,param_1,0);
              }
              local_5c8 = local_3e8;
              ppcVar7 = (char **)(ulonglong)(local_5c0 + 1);
              FUN_180002d90(local_5c8,"  DATA    %2i",ppcVar7,pdVar5);
              sVar3 = strlen(local_5c8);
              local_5c8 = local_5c8 + (int)sVar3;
              if (local_584 == -1) {
                if (local_5a8 != 0) {
                  FUN_180007e70(0xb,local_3e8,(longlong *)&local_5c8);
                  ppcVar7 = (char **)&DAT_180028740;
                  FUN_180002d90(local_5c8," %-11s",&DAT_180028740,pdVar5);
                  sVar3 = strlen(local_5c8);
                  local_5c8 = local_5c8 + (int)sVar3;
                }
              }
              else {
                FUN_180007e70(0xb,local_3e8,(longlong *)&local_5c8);
                local_5b0 = (double *)
                            (local_5b8[10] +
                             (longlong)(local_5c0 * *(short *)(local_5b8 + 3)) * 0x10 + -0x10 +
                            (longlong)local_584 * 0x10);
                if (*local_5b0 == DAT_180029478) {
                  ppcVar7 = (char **)&DAT_180028740;
                  FUN_180002d90(local_5c8," %-11s",&DAT_180028740,pdVar5);
                }
                else {
                  ppcVar7 = (char **)(*local_5b0 * local_4c8[5]);
                  FUN_180002d90(local_5c8," %-11G",ppcVar7,pdVar5);
                }
                sVar3 = strlen(local_5c8);
                local_5c8 = local_5c8 + (int)sVar3;
              }
              if (local_580 == -1) {
                if ((((local_5a8 == 1) || (local_5a8 == 2)) || (local_5a8 == 3)) || (local_5a8 == 4)
                   ) {
                  FUN_180007e70(0xb,local_3e8,(longlong *)&local_5c8);
                  ppcVar7 = (char **)&DAT_180028740;
                  FUN_180002d90(local_5c8," %-11s",&DAT_180028740,pdVar5);
                  sVar3 = strlen(local_5c8);
                  local_5c8 = local_5c8 + (int)sVar3;
                }
              }
              else {
                FUN_180007e70(0xb,local_3e8,(longlong *)&local_5c8);
                local_5b0 = (double *)
                            (local_5b8[10] +
                             (longlong)(local_5c0 * *(short *)(local_5b8 + 3)) * 0x10 + -0x10 +
                            (longlong)local_580 * 0x10);
                if (*local_5b0 == DAT_180029478) {
                  ppcVar7 = (char **)&DAT_180028740;
                  FUN_180002d90(local_5c8," %-11s",&DAT_180028740,pdVar5);
                }
                else {
                  ppcVar7 = (char **)(*local_5b0 * local_498);
                  FUN_180002d90(local_5c8," %-11G",ppcVar7,pdVar5);
                }
                sVar3 = strlen(local_5c8);
                local_5c8 = local_5c8 + (int)sVar3;
              }
              for (local_5bc = 0; local_5bc < *(short *)(local_5b8 + 1) + -1;
                  local_5bc = local_5bc + 1) {
                if (aiStack_468[local_5bc] == -1) {
                  if (((local_5a8 == 1) || (local_5a8 == 3)) ||
                     ((local_5a8 == 5 || ((local_5a8 == 2 && (local_5a0 < 0)))))) {
                    FUN_180007e70(0xb,local_3e8,(longlong *)&local_5c8);
                    ppcVar7 = (char **)&DAT_180028740;
                    FUN_180002d90(local_5c8," %-11s",&DAT_180028740,pdVar5);
                    sVar3 = strlen(local_5c8);
                    local_5c8 = local_5c8 + (int)sVar3;
                  }
                }
                else {
                  FUN_180007e70(0xb,local_3e8,(longlong *)&local_5c8);
                  local_5b0 = (double *)
                              (local_5b8[10] +
                               (longlong)(local_5c0 * *(short *)(local_5b8 + 3)) * 0x10 + -0x10 +
                              (longlong)aiStack_468[local_5bc] * 0x10);
                  if (*local_5b0 == DAT_180029478) {
                    ppcVar7 = (char **)&DAT_180028740;
                    FUN_180002d90(local_5c8," %-11s",&DAT_180028740,pdVar5);
                  }
                  else {
                    ppcVar7 = (char **)*local_5b0;
                    FUN_180002d90(local_5c8," %-11G",ppcVar7,pdVar5);
                  }
                  sVar3 = strlen(local_5c8);
                  local_5c8 = local_5c8 + (int)sVar3;
                }
              }
              for (local_5bc = 0; local_5bc < *(short *)(local_5b8 + 1) + -1;
                  local_5bc = local_5bc + 1) {
                if (aiStack_448[local_5bc] == -1) {
                  if (((local_5a8 == 1) || (local_5a8 == 3)) || (local_5a8 == 5)) {
                    FUN_180007e70(0xb,local_3e8,(longlong *)&local_5c8);
                    ppcVar7 = (char **)&DAT_180028740;
                    FUN_180002d90(local_5c8," %-11s",&DAT_180028740,pdVar5);
                    sVar3 = strlen(local_5c8);
                    local_5c8 = local_5c8 + (int)sVar3;
                  }
                }
                else {
                  FUN_180007e70(0xb,local_3e8,(longlong *)&local_5c8);
                  local_5b0 = (double *)
                              (local_5b8[10] +
                               (longlong)(local_5c0 * *(short *)(local_5b8 + 3)) * 0x10 + -0x10 +
                              (longlong)aiStack_448[local_5bc] * 0x10);
                  if (*local_5b0 == DAT_180029478) {
                    ppcVar7 = (char **)&DAT_180028740;
                    FUN_180002d90(local_5c8," %-11s",&DAT_180028740,pdVar5);
                  }
                  else {
                    ppcVar7 = (char **)*local_5b0;
                    FUN_180002d90(local_5c8," %-11G",ppcVar7,pdVar5);
                  }
                  sVar3 = strlen(local_5c8);
                  local_5c8 = local_5c8 + (int)sVar3;
                }
              }
              for (local_5bc = 0; local_5bc < *(short *)(local_5b8 + 1) + -1;
                  local_5bc = local_5bc + 1) {
                if (aiStack_428[local_5bc] == -1) {
                  if ((local_5a8 == 2) || (local_5a8 == 3)) {
                    FUN_180007e70(0xb,local_3e8,(longlong *)&local_5c8);
                    ppcVar7 = (char **)&DAT_180028740;
                    FUN_180002d90(local_5c8," %-11s",&DAT_180028740,pdVar5);
                    sVar3 = strlen(local_5c8);
                    local_5c8 = local_5c8 + (int)sVar3;
                  }
                  else if (local_5a8 == 4) {
                    ppcVar7 = &local_5c8;
                    FUN_180007e70(0xb,local_3e8,(longlong *)ppcVar7);
                    if (aiStack_468[local_5bc] == -1) {
                      if (aiStack_448[local_5bc] == -1) {
                        ppcVar7 = (char **)&DAT_180028740;
                        FUN_180002d90(local_5c8," %-11s",&DAT_180028740,pdVar5);
                      }
                      else {
                        local_5b0 = (double *)
                                    (local_5b8[10] +
                                     (longlong)(local_5c0 * *(short *)(local_5b8 + 3)) * 0x10 +
                                     -0x10 + (longlong)aiStack_448[local_5bc] * 0x10);
                        if (*local_5b0 != DAT_180029478) {
                          ppcVar7 = (char **)*local_5b0;
                          FUN_180002d90(local_5c8," %-11G",ppcVar7,pdVar5);
                        }
                      }
                    }
                    else {
                      local_5b0 = (double *)
                                  (local_5b8[10] +
                                   (longlong)(local_5c0 * *(short *)(local_5b8 + 3)) * 0x10 + -0x10
                                  + (longlong)aiStack_468[local_5bc] * 0x10);
                      if (*local_5b0 != DAT_180029478) {
                        ppcVar7 = (char **)*local_5b0;
                        FUN_180002d90(local_5c8," %-11G",ppcVar7,pdVar5);
                      }
                    }
                    sVar3 = strlen(local_5c8);
                    local_5c8 = local_5c8 + (int)sVar3;
                  }
                }
                else {
                  FUN_180007e70(0xb,local_3e8,(longlong *)&local_5c8);
                  local_5b0 = (double *)
                              (local_5b8[10] +
                               (longlong)(local_5c0 * *(short *)(local_5b8 + 3)) * 0x10 + -0x10 +
                              (longlong)aiStack_428[local_5bc] * 0x10);
                  if (*local_5b0 == DAT_180029478) {
                    ppcVar7 = (char **)&DAT_180028740;
                    FUN_180002d90(local_5c8," %-11s",&DAT_180028740,pdVar5);
                  }
                  else {
                    ppcVar7 = (char **)*local_5b0;
                    FUN_180002d90(local_5c8," %-11G",ppcVar7,pdVar5);
                  }
                  sVar3 = strlen(local_5c8);
                  local_5c8 = local_5c8 + (int)sVar3;
                }
              }
              FUN_180002d90(local_5c8,&DAT_180027258,ppcVar7,pdVar5);
              pdVar5 = (double *)&local_560;
              pdVar2 = (double *)0x1;
              FUN_180004510(local_3e8,local_1e8,1,(uint *)pdVar5,param_1,0);
            }
            FUN_180007f00(param_1,&DAT_180029084,pdVar2,pdVar5);
          }
          else {
            FUN_1800220b0(0,"NO of X-Values for phases differ - no DATA GROUP written",pdVar2,pdVar5
                         );
          }
        }
        else {
          pdVar2 = param_3;
          pdVar5 = param_4;
          FUN_180019b50(param_1,param_2,(char *)param_3,(uint *)param_4,local_5b8);
        }
      }
      else {
        pdVar2 = param_3;
        pdVar5 = param_4;
        FUN_180018560(param_1,param_2,(char *)param_3,(uint *)param_4,local_5b8);
      }
    }
LAB_180013ee0:
    local_500 = (longlong *)local_500[1];
  } while( true );
  local_59c = local_59c + 1;
  local_578 = (double *)((longlong)local_578 + 0xd);
  local_568 = (double *)((longlong)local_568 + 0x14);
  local_530 = (double *)((longlong)local_530 + 0xd);
  goto LAB_180014ba3;
}

/* RVA 0x18560, FUN_180018560 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x000180018fbf) */
/* WARNING: Removing unreachable block (ram,0x000180018e8f) */
/* WARNING: Removing unreachable block (ram,0x000180018a87) */
/* WARNING: Removing unreachable block (ram,0x000180018ec5) */
/* WARNING: Removing unreachable block (ram,0x000180018ff5) */

void FUN_180018560(undefined8 param_1,uint *param_2,char *param_3,uint *param_4,undefined8 *param_5)

{
  int iVar1;
  char *pcVar2;
  size_t sVar3;
  undefined *puVar4;
  undefined1 auStackY_648 [32];
  int local_618;
  char *local_610;
  int local_608;
  uint local_604;
  double *local_600;
  uint local_5f8;
  uint local_5f4;
  char *local_5f0;
  uint *local_5e8;
  int local_5e0;
  longlong *local_5d8;
  int local_5d0;
  int local_5cc;
  uint local_5c8 [2];
  char *local_5c0;
  int local_5b8;
  int local_5b4;
  int local_5b0;
  int local_5ac;
  int local_5a8;
  int local_5a4;
  uint local_5a0;
  undefined *local_598;
  longlong local_590;
  undefined *local_588;
  undefined8 local_580;
  undefined *local_578;
  undefined8 local_570;
  undefined8 local_568;
  undefined8 local_560;
  undefined8 local_558;
  undefined4 local_550;
  double local_548;
  double local_540;
  undefined8 local_538;
  double local_530;
  double local_528;
  uint auStack_520 [8];
  uint auStack_500 [8];
  char local_4e0 [8];
  char local_4d8 [48];
  char local_4a8 [256];
  char local_3a8 [208];
  char local_2d8 [32];
  char local_2b8 [208];
  char local_1e8 [256];
  char local_e8 [208];
  ulonglong local_18;
  
  local_18 = DAT_180032178 ^ (ulonglong)auStackY_648;
  local_5c8[0] = 0;
  local_5d8 = (longlong *)param_5[2];
  local_538 = *param_5;
  strcpy(local_2d8,"");
  local_5f8 = 0xffffffff;
  local_5f4 = 0xffffffff;
  for (local_604 = 0; (int)local_604 < 8; local_604 = local_604 + 1) {
    auStack_500[(int)local_604] = 0xffffffff;
    auStack_520[(int)local_604] = 0xffffffff;
  }
  local_5e0 = 0;
  local_5d0 = 0;
  local_5b8 = 0;
  local_5b4 = 0;
  local_5c0 = (char *)0x0;
  local_598 = (undefined *)0x0;
  local_604 = 1;
  local_5e8 = (uint *)param_5[4];
  local_5f0 = (char *)param_5[6];
  do {
    if ((int)*(short *)(param_5 + 3) < (int)local_604) {
      local_580 = 0;
      local_4e0[0] = '\0';
      if (local_5f8 != 0xffffffff) {
        strcpy(local_4e0,"T");
      }
      if (local_5f4 != 0xffffffff) {
        strcat(local_4e0,"P");
      }
      if ((local_5f8 == 0) && (local_5f4 == 0)) {
        FUN_1800220b0(0,"Neither T nor P given in TABLE - no DATA GROUP written",param_3,param_4);
      }
      else {
        local_5cc = 1;
        if (local_5e0 < 1) {
          strcat(local_4e0,"X");
          local_5cc = 0;
        }
        else {
          strcat(local_4e0,"X");
        }
        strcpy(local_2b8,"");
        strcpy(local_3a8,"");
        if (0 < (int)local_5f8) {
          FUN_180002d90(local_3a8,&DAT_180028df4,local_578,param_4);
          strcat(local_2b8,local_3a8);
        }
        if (0 < (int)local_5f4) {
          FUN_180002d90(local_3a8,&DAT_180028df4,local_588,param_4);
          strcat(local_2b8,local_3a8);
        }
        pcVar2 = local_4e0;
        FUN_180002d90(local_3a8,"SYSTEM-DEF=%s ",pcVar2,param_4);
        strcat(local_2b8,local_3a8);
        local_618 = 0;
        local_5d8 = (longlong *)param_5[2];
        for (; local_618 < *(short *)(param_5 + 1); local_618 = local_618 + 1) {
          local_590 = *local_5d8;
          pcVar2 = (char *)(local_590 + 0x240);
          FUN_180002d90(local_3a8,"COMP=%s ",pcVar2,param_4);
          strcat(local_2b8,local_3a8);
          local_5d8 = local_5d8 + 1;
        }
        FUN_180002d90(local_3a8,"PROP-LIST=HNRYMX ",pcVar2,param_4);
        strcat(local_2b8,local_3a8);
        if (local_5c0 != (char *)0x0) {
          FUN_180002d90(local_3a8,&DAT_180028df4,local_5c0,param_4);
          strcat(local_2b8,local_3a8);
        }
        *param_2 = *param_2 + 1;
        pcVar2 = (char *)(ulonglong)*param_2;
        FUN_180007f00(param_1,"? PROPERTIES DATA MIXTURE \"DG-%d\" ? ",pcVar2,param_4);
        FUN_180007f00(param_1," ; \"SI_MOLE\" ; \n",pcVar2,param_4);
        FUN_180007f00(param_1,"\\ \"SYSTEM-DEF\" STATESPEC = HENRY",pcVar2,param_4);
        FUN_180007f00(param_1," CIDS = (",pcVar2,param_4);
        local_618 = 0;
        local_5d8 = (longlong *)param_5[2];
        for (; local_618 < *(short *)(param_5 + 1); local_618 = local_618 + 1) {
          local_590 = *local_5d8;
          pcVar2 = (char *)(local_590 + 0x240);
          FUN_180007f00(param_1,&DAT_180028ffc,pcVar2,param_4);
          local_5d8 = local_5d8 + 1;
        }
        FUN_180007f00(param_1,&DAT_180029000,pcVar2,param_4);
        if (local_5c0 == (char *)0x0) {
          FUN_180007f00(param_1," \\\\ USING ",pcVar2,param_4);
        }
        else {
          strcpy(local_4d8,"");
          FUN_180004210(local_5c0,(longlong)local_4d8);
          pcVar2 = local_4d8;
          FUN_180007f00(param_1," COMPOSITION = \"%s\"  \\ \n",pcVar2,param_4);
          FUN_180007f00(param_1," \\ USING ",pcVar2,param_4);
        }
        local_4a8[0] = '\0';
        local_568 = 0;
        local_570 = 0;
        local_1e8[0] = '\0';
        for (local_618 = 0; local_618 < *(short *)((longlong)param_5 + 0x5a);
            local_618 = local_618 + 1) {
          if (local_618 == 0) {
            FUN_180007f00(param_1," USE = \"STD-DEV\" / \n",pcVar2,param_4);
            strcpy(local_1e8,local_4a8);
          }
          local_610 = local_4a8;
          pcVar2 = (char *)(ulonglong)(local_618 + 1);
          FUN_180002d90(local_610,"  DATA    %2i",pcVar2,param_4);
          if (local_618 == *(short *)((longlong)param_5 + 0x5a) + -1) {
            FUN_180007f00(param_1," USE = DATA \\ \n",pcVar2,param_4);
          }
          else {
            FUN_180007f00(param_1," USE = DATA / \n",pcVar2,param_4);
          }
        }
        local_1e8[0] = '\0';
        local_558 = 0;
        local_560 = 0;
        local_4a8[0] = '\0';
        local_5c8[0] = 0;
        FUN_180007f00(param_1,"\\ DATA \n",pcVar2,param_4);
        for (local_618 = 0; local_618 < *(short *)((longlong)param_5 + 0x5a);
            local_618 = local_618 + 1) {
          if (param_5[9] != 0) {
            local_610 = local_4a8;
            local_550 = 0;
            if (local_5f8 != 0xffffffff) {
              local_600 = (double *)
                          (param_5[10] + (longlong)(local_618 * *(short *)(param_5 + 3)) * 0x10 +
                           -0x10 + (longlong)(int)local_5f8 * 0x10);
              FUN_180007e70(0xb,local_4a8,(longlong *)&local_610);
              if ((local_5b0 == 1) && (local_600[1] != DAT_180029478)) {
                FUN_180002d90(local_610," -%-10G",local_600[1],param_4);
              }
              else if ((local_5b0 == 2) && (local_600[1] != DAT_180029478)) {
                FUN_180002d90(local_610," %-11G",local_600[1],param_4);
              }
              else {
                FUN_180002d90(local_610," %-11s",&DAT_180028740,param_4);
              }
              sVar3 = strlen(local_610);
              local_610 = local_610 + (int)sVar3;
            }
            if (local_5f4 != 0xffffffff) {
              local_600 = (double *)
                          (param_5[10] + (longlong)(local_618 * *(short *)(param_5 + 3)) * 0x10 +
                           -0x10 + (longlong)(int)local_5f4 * 0x10);
              FUN_180007e70(0xb,local_4a8,(longlong *)&local_610);
              if ((local_5ac == 1) && (local_600[1] != DAT_180029478)) {
                FUN_180002d90(local_610," -%-10G",local_600[1],param_4);
              }
              else if ((local_5ac == 2) && (local_600[1] != DAT_180029478)) {
                FUN_180002d90(local_610," %-11G",local_600[1],param_4);
              }
              else {
                FUN_180002d90(local_610," %-11s",&DAT_180028740,param_4);
              }
              sVar3 = strlen(local_610);
              local_610 = local_610 + (int)sVar3;
            }
            for (local_608 = 0; local_608 < *(short *)(param_5 + 1) + -1; local_608 = local_608 + 1)
            {
              if (auStack_500[local_608] != 0xffffffff) {
                FUN_180007e70(0xb,local_4a8,(longlong *)&local_610);
                if (local_5cc == 1) {
                  local_600 = (double *)
                              (param_5[10] + (longlong)(local_618 * *(short *)(param_5 + 3)) * 0x10
                               + -0x10 + (longlong)(int)auStack_500[local_608] * 0x10);
                  if ((local_5a8 == 1) && (local_600[1] != DAT_180029478)) {
                    FUN_180002d90(local_610," -%-10G",local_600[1],param_4);
                  }
                  else if ((local_5a8 == 2) && (local_600[1] != DAT_180029478)) {
                    FUN_180002d90(local_610," %-11G",local_600[1],param_4);
                  }
                  else {
                    FUN_180002d90(local_610," %-11s",&DAT_180028740,param_4);
                  }
                }
                else {
                  FUN_180002d90(local_610," %-11s",&DAT_180028740,param_4);
                }
                sVar3 = strlen(local_610);
                local_610 = local_610 + (int)sVar3;
              }
            }
            for (local_608 = 0; local_608 < *(short *)(param_5 + 1); local_608 = local_608 + 1) {
              FUN_180007e70(0xb,local_4a8,(longlong *)&local_610);
              if (auStack_520[local_608] == 0xffffffff) {
                FUN_180002d90(local_610," %-11s",&DAT_180028740,param_4);
              }
              else {
                local_600 = (double *)
                            (param_5[10] + (longlong)(local_618 * *(short *)(param_5 + 3)) * 0x10 +
                             -0x10 + (longlong)(int)auStack_520[local_608] * 0x10);
                if ((local_5a4 == 1) && (local_600[1] != DAT_180029478)) {
                  FUN_180002d90(local_610," -%-10G",local_600[1],param_4);
                }
                else if ((local_5a4 == 2) && (local_600[1] != DAT_180029478)) {
                  FUN_180002d90(local_610," %-11G",local_600[1],param_4);
                }
                else {
                  FUN_180002d90(local_610," %-11s",&DAT_180028740,param_4);
                }
              }
              sVar3 = strlen(local_610);
              local_610 = local_610 + (int)sVar3;
            }
          }
          if ((local_618 == 0) || (iVar1 = strcmp(local_1e8,local_4a8), iVar1 != 0)) {
            strcpy(local_1e8,local_4a8);
            FUN_180002d90(local_e8,"  STD-DEV %2i%s\n",(ulonglong)(local_618 + 1),local_4a8);
            param_4 = local_5c8;
            FUN_180004510(local_e8,local_2b8,0,param_4,param_1,0);
          }
          local_610 = local_4a8;
          puVar4 = (undefined *)(ulonglong)(local_618 + 1);
          FUN_180002d90(local_610,"  DATA    %2i",puVar4,param_4);
          sVar3 = strlen(local_610);
          local_610 = local_610 + (int)sVar3;
          if (local_5f8 != 0xffffffff) {
            FUN_180007e70(0xb,local_4a8,(longlong *)&local_610);
            local_600 = (double *)
                        (param_5[10] + (longlong)(local_618 * *(short *)(param_5 + 3)) * 0x10 +
                         -0x10 + (longlong)(int)local_5f8 * 0x10);
            if (*local_600 == DAT_180029478) {
              puVar4 = &DAT_180028740;
              FUN_180002d90(local_610," %-11s",&DAT_180028740,param_4);
            }
            else {
              puVar4 = (undefined *)(*local_600 * local_548);
              FUN_180002d90(local_610," %-11G",puVar4,param_4);
            }
            sVar3 = strlen(local_610);
            local_610 = local_610 + (int)sVar3;
          }
          if (local_5f4 != 0xffffffff) {
            FUN_180007e70(0xb,local_4a8,(longlong *)&local_610);
            local_600 = (double *)
                        (param_5[10] + (longlong)(local_618 * *(short *)(param_5 + 3)) * 0x10 +
                         -0x10 + (longlong)(int)local_5f4 * 0x10);
            if (*local_600 == DAT_180029478) {
              puVar4 = &DAT_180028740;
              FUN_180002d90(local_610," %-11s",&DAT_180028740,param_4);
            }
            else {
              puVar4 = (undefined *)(*local_600 * local_540);
              FUN_180002d90(local_610," %-11G",puVar4,param_4);
            }
            sVar3 = strlen(local_610);
            local_610 = local_610 + (int)sVar3;
          }
          for (local_608 = 0; local_608 < *(short *)(param_5 + 1) + -1; local_608 = local_608 + 1) {
            FUN_180007e70(0xb,local_4a8,(longlong *)&local_610);
            if (local_5cc == 1) {
              local_600 = (double *)
                          (param_5[10] + (longlong)(local_618 * *(short *)(param_5 + 3)) * 0x10 +
                           -0x10 + (longlong)(int)auStack_500[local_608] * 0x10);
              if (*local_600 == DAT_180029478) {
                puVar4 = &DAT_180028740;
                FUN_180002d90(local_610," %-11s",&DAT_180028740,param_4);
              }
              else {
                puVar4 = (undefined *)*local_600;
                FUN_180002d90(local_610," %-11G",puVar4,param_4);
              }
            }
            else if (local_608 == 0) {
              puVar4 = &DAT_1800290c4;
              FUN_180002d90(local_610," %-11s",&DAT_1800290c4,param_4);
            }
            else {
              puVar4 = &DAT_180028740;
              FUN_180002d90(local_610," %-11s",&DAT_180028740,param_4);
            }
            sVar3 = strlen(local_610);
            local_610 = local_610 + (int)sVar3;
          }
          for (local_608 = 0; local_608 < *(short *)(param_5 + 1); local_608 = local_608 + 1) {
            FUN_180007e70(0xb,local_4a8,(longlong *)&local_610);
            if (auStack_520[local_608] == 0xffffffff) {
              puVar4 = &DAT_180028740;
              FUN_180002d90(local_610," %-11s",&DAT_180028740,param_4);
            }
            else {
              local_600 = (double *)
                          (param_5[10] + (longlong)(local_618 * *(short *)(param_5 + 3)) * 0x10 +
                           -0x10 + (longlong)(int)auStack_520[local_608] * 0x10);
              if (*local_600 == DAT_180029478) {
                puVar4 = &DAT_180028740;
                FUN_180002d90(local_610," %-11s",&DAT_180028740,param_4);
              }
              else {
                puVar4 = (undefined *)*local_600;
                FUN_180002d90(local_610," %-11G",puVar4,param_4);
              }
            }
            sVar3 = strlen(local_610);
            local_610 = local_610 + (int)sVar3;
          }
          FUN_180002d90(local_610,&DAT_180027258,puVar4,param_4);
          local_5a0 = (uint)(local_618 == *(short *)((longlong)param_5 + 0x5a));
          param_4 = local_5c8;
          pcVar2 = (char *)0x1;
          FUN_180004510(local_4a8,local_2b8,1,param_4,param_1,local_5a0);
        }
        FUN_180007f00(param_1,&DAT_180029034,pcVar2,param_4);
        FUN_180007f00(param_1,&DAT_180029084,pcVar2,param_4);
      }
      return;
    }
    local_618 = 0;
    while (((&PTR_DAT_18002e6c0)[(longlong)local_618 * 3] != (undefined *)0x0 &&
           (iVar1 = _stricmp((&PTR_DAT_18002e6c0)[(longlong)local_618 * 3],(char *)local_5e8),
           iVar1 != 0))) {
      local_618 = local_618 + 1;
    }
    if (((&PTR_DAT_18002e6c8)[(longlong)local_618 * 3] == (undefined *)0x0) ||
       (*(&PTR_DAT_18002e6c8)[(longlong)local_618 * 3] != 'T')) {
      if (((&PTR_DAT_18002e6c8)[(longlong)local_618 * 3] == (undefined *)0x0) ||
         (*(&PTR_DAT_18002e6c8)[(longlong)local_618 * 3] != 'P')) {
        if (((&PTR_DAT_18002e6c8)[(longlong)local_618 * 3] == (undefined *)0x0) ||
           (*(&PTR_DAT_18002e6c8)[(longlong)local_618 * 3] != 'X')) {
          if (((&PTR_DAT_18002e6c8)[(longlong)local_618 * 3] != (undefined *)0x0) &&
             (iVar1 = _stricmp((&PTR_DAT_18002e6c8)[(longlong)local_618 * 3],"HNRYMX"), iVar1 == 0))
          {
            if (local_598 == (undefined *)0x0) {
              local_598 = FUN_1800082f0(local_5f0,0x16,&local_528);
              param_3 = local_5f0;
              if (local_598 == (undefined *)0x0) {
                param_4 = local_5e8;
                FUN_1800220b0(1,"Unit <%s> for property <%s> not supported by Aspen Plus",local_5f0,
                              local_5e8);
                goto LAB_180018687;
              }
              param_4 = (uint *)(ulonglong)local_604;
              local_5a4 = FUN_1800042c0((longlong)param_5,local_5e8,local_5f0,local_604);
            }
            auStack_520[local_5d0] = local_604;
            local_5d0 = local_5d0 + 1;
          }
        }
        else {
          if (local_5c0 == (char *)0x0) {
            local_5c0 = FUN_1800082f0(local_5f0,0x20,&local_530);
            param_3 = local_5f0;
            if (local_5c0 == (char *)0x0) {
              param_4 = local_5e8;
              FUN_1800220b0(1,"Unit <%s> for property <%s> not supported by Aspen Plus",local_5f0,
                            local_5e8);
              goto LAB_180018687;
            }
            param_4 = (uint *)(ulonglong)local_604;
            local_5a8 = FUN_1800042c0((longlong)param_5,local_5e8,local_5f0,local_604);
          }
          auStack_500[local_5e0] = local_604;
          local_5e0 = local_5e0 + 1;
        }
      }
      else {
        local_588 = FUN_1800082f0(local_5f0,0x16,&local_540);
        if (local_588 == (undefined *)0x0) {
          FUN_1800220b0(1,"Unit <%s> for property <%s> not supported by Aspen Plus",local_5f0,
                        local_5e8);
        }
        else {
          local_5f4 = local_604;
          local_5b4 = local_5b4 + 1;
        }
        param_4 = (uint *)(ulonglong)local_604;
        param_3 = local_5f0;
        local_5ac = FUN_1800042c0((longlong)param_5,local_5e8,local_5f0,local_604);
      }
    }
    else {
      local_578 = FUN_1800082f0(local_5f0,0x19,&local_548);
      if (local_578 == (undefined *)0x0) {
        FUN_1800220b0(1,"Unit <%s> for property <%s> not supported by Aspen Plus",local_5f0,
                      local_5e8);
      }
      else {
        local_5f8 = local_604;
        local_5b8 = local_5b8 + 1;
      }
      param_4 = (uint *)(ulonglong)local_604;
      param_3 = local_5f0;
      local_5b0 = FUN_1800042c0((longlong)param_5,local_5e8,local_5f0,local_604);
    }
LAB_180018687:
    local_604 = local_604 + 1;
    local_5e8 = (uint *)((longlong)local_5e8 + 0xd);
    local_5f0 = local_5f0 + 0x14;
  } while( true );
}

/* RVA 0x19b50, FUN_180019b50 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00018001a57f) */
/* WARNING: Removing unreachable block (ram,0x00018001a44f) */
/* WARNING: Removing unreachable block (ram,0x00018001a074) */
/* WARNING: Removing unreachable block (ram,0x00018001a485) */
/* WARNING: Removing unreachable block (ram,0x00018001a5b5) */

void FUN_180019b50(undefined8 param_1,uint *param_2,char *param_3,uint *param_4,undefined8 *param_5)

{
  int iVar1;
  char *pcVar2;
  size_t sVar3;
  undefined *puVar4;
  undefined1 auStackY_638 [32];
  int local_608;
  char *local_600;
  int local_5f8;
  uint local_5f4;
  double *local_5f0;
  uint local_5e8;
  uint local_5e4;
  char *local_5e0;
  uint *local_5d8;
  longlong *local_5d0;
  int local_5c8;
  int local_5c4;
  uint local_5c0 [2];
  char *local_5b8;
  int local_5b0;
  int local_5ac;
  int local_5a8;
  int local_5a4;
  int local_5a0;
  int local_59c;
  uint local_598;
  undefined *local_590;
  longlong local_588;
  undefined8 local_580;
  undefined *local_578;
  undefined *local_570;
  undefined8 local_568;
  undefined8 local_560;
  undefined8 local_558;
  undefined8 local_550;
  undefined4 local_548;
  double local_540;
  double local_538;
  undefined8 local_530;
  double local_528;
  double local_520;
  uint auStack_518 [8];
  uint auStack_4f8 [8];
  char local_4d8 [8];
  char local_4d0 [40];
  char local_4a8 [256];
  char local_3a8 [208];
  char local_2d8 [32];
  char local_2b8 [208];
  char local_1e8 [256];
  char local_e8 [208];
  ulonglong local_18;
  
  local_18 = DAT_180032178 ^ (ulonglong)auStackY_638;
  local_5c0[0] = 0;
  local_5d0 = (longlong *)param_5[2];
  local_530 = *param_5;
  strcpy(local_2d8,"");
  local_5e8 = 0xffffffff;
  local_5e4 = 0xffffffff;
  for (local_5f4 = 0; (int)local_5f4 < 8; local_5f4 = local_5f4 + 1) {
    auStack_518[(int)local_5f4] = 0xffffffff;
    auStack_4f8[(int)local_5f4] = 0xffffffff;
  }
  local_5c8 = 0;
  local_5c4 = 0;
  local_5b0 = 0;
  local_5ac = 0;
  local_5b8 = (char *)0x0;
  local_590 = (undefined *)0x0;
  local_5f4 = 1;
  local_5d8 = (uint *)param_5[4];
  local_5e0 = (char *)param_5[6];
  do {
    if ((int)*(short *)(param_5 + 3) < (int)local_5f4) {
      local_580 = 0;
      local_4d8[0] = '\0';
      if (local_5e8 != 0xffffffff) {
        strcpy(local_4d8,"T");
      }
      if (local_5e4 != 0xffffffff) {
        strcat(local_4d8,"P");
      }
      if ((local_5e8 == 0) && (local_5e4 == 0)) {
        FUN_1800220b0(0,"Neither T nor P given in TABLE - no DATA GROUP written",param_3,param_4);
      }
      else {
        strcat(local_4d8,"X");
        strcpy(local_2b8,"");
        strcpy(local_3a8,"");
        if (0 < (int)local_5e8) {
          FUN_180002d90(local_3a8,&DAT_180028df4,local_578,param_4);
          strcat(local_2b8,local_3a8);
        }
        if (0 < (int)local_5e4) {
          FUN_180002d90(local_3a8,&DAT_180028df4,local_570,param_4);
          strcat(local_2b8,local_3a8);
        }
        pcVar2 = local_4d8;
        FUN_180002d90(local_3a8,"SYSTEM-DEF=%s ",pcVar2,param_4);
        strcat(local_2b8,local_3a8);
        local_608 = 0;
        local_5d0 = (longlong *)param_5[2];
        for (; local_608 < *(short *)(param_5 + 1); local_608 = local_608 + 1) {
          local_588 = *local_5d0;
          pcVar2 = (char *)(local_588 + 0x240);
          FUN_180002d90(local_3a8,"COMP=%s ",pcVar2,param_4);
          strcat(local_2b8,local_3a8);
          local_5d0 = local_5d0 + 1;
        }
        FUN_180002d90(local_3a8,"PROP-LIST=GAMMA ",pcVar2,param_4);
        strcat(local_2b8,local_3a8);
        if (local_5b8 != (char *)0x0) {
          FUN_180002d90(local_3a8,&DAT_180028df4,local_5b8,param_4);
          strcat(local_2b8,local_3a8);
        }
        *param_2 = *param_2 + 1;
        pcVar2 = (char *)(ulonglong)*param_2;
        FUN_180007f00(param_1,"? PROPERTIES DATA MIXTURE \"DG-%d\" ? ",pcVar2,param_4);
        FUN_180007f00(param_1," ; \"SI_MOLE\" ; \n",pcVar2,param_4);
        FUN_180007f00(param_1,"\\ \"SYSTEM-DEF\" STATESPEC = GAMMA",pcVar2,param_4);
        FUN_180007f00(param_1," CIDS = (",pcVar2,param_4);
        local_608 = 0;
        local_5d0 = (longlong *)param_5[2];
        for (; local_608 < *(short *)(param_5 + 1); local_608 = local_608 + 1) {
          local_588 = *local_5d0;
          pcVar2 = (char *)(local_588 + 0x240);
          FUN_180007f00(param_1,&DAT_180028ffc,pcVar2,param_4);
          local_5d0 = local_5d0 + 1;
        }
        FUN_180007f00(param_1,&DAT_180029000,pcVar2,param_4);
        if (local_5b8 == (char *)0x0) {
          FUN_180007f00(param_1," \\\\ USING ",pcVar2,param_4);
        }
        else {
          strcpy(local_4d0,"");
          FUN_180004210(local_5b8,(longlong)local_4d0);
          pcVar2 = local_4d0;
          FUN_180007f00(param_1," COMPOSITION = \"%s\"  \\ \n",pcVar2,param_4);
          FUN_180007f00(param_1," \\ USING ",pcVar2,param_4);
        }
        local_4a8[0] = '\0';
        local_560 = 0;
        local_568 = 0;
        local_1e8[0] = '\0';
        for (local_608 = 0; local_608 < *(short *)((longlong)param_5 + 0x5a);
            local_608 = local_608 + 1) {
          if (local_608 == 0) {
            FUN_180007f00(param_1," USE = \"STD-DEV\" / \n",pcVar2,param_4);
            strcpy(local_1e8,local_4a8);
          }
          local_600 = local_4a8;
          pcVar2 = (char *)(ulonglong)(local_608 + 1);
          FUN_180002d90(local_600,"  DATA    %2i",pcVar2,param_4);
          if (local_608 == *(short *)((longlong)param_5 + 0x5a) + -1) {
            FUN_180007f00(param_1," USE = DATA \\ \n",pcVar2,param_4);
          }
          else {
            FUN_180007f00(param_1," USE = DATA / \n",pcVar2,param_4);
          }
        }
        local_1e8[0] = '\0';
        local_550 = 0;
        local_558 = 0;
        local_4a8[0] = '\0';
        local_5c0[0] = 0;
        FUN_180007f00(param_1,"\\ DATA \n",pcVar2,param_4);
        for (local_608 = 0; local_608 < *(short *)((longlong)param_5 + 0x5a);
            local_608 = local_608 + 1) {
          if (param_5[9] != 0) {
            local_600 = local_4a8;
            local_548 = 0;
            if (local_5e8 != 0xffffffff) {
              local_5f0 = (double *)
                          (param_5[10] + (longlong)(local_608 * *(short *)(param_5 + 3)) * 0x10 +
                           -0x10 + (longlong)(int)local_5e8 * 0x10);
              FUN_180007e70(0xb,local_4a8,(longlong *)&local_600);
              if ((local_5a8 == 1) && (local_5f0[1] != DAT_180029478)) {
                FUN_180002d90(local_600," -%-10G",local_5f0[1],param_4);
              }
              else if ((local_5a8 == 2) && (local_5f0[1] != DAT_180029478)) {
                FUN_180002d90(local_600," %-11G",local_5f0[1],param_4);
              }
              else {
                FUN_180002d90(local_600," %-11s",&DAT_180028740,param_4);
              }
              sVar3 = strlen(local_600);
              local_600 = local_600 + (int)sVar3;
            }
            if (local_5e4 != 0xffffffff) {
              local_5f0 = (double *)
                          (param_5[10] + (longlong)(local_608 * *(short *)(param_5 + 3)) * 0x10 +
                           -0x10 + (longlong)(int)local_5e4 * 0x10);
              FUN_180007e70(0xb,local_4a8,(longlong *)&local_600);
              if ((local_5a4 == 1) && (local_5f0[1] != DAT_180029478)) {
                FUN_180002d90(local_600," -%-10G",local_5f0[1],param_4);
              }
              else if ((local_5a4 == 2) && (local_5f0[1] != DAT_180029478)) {
                FUN_180002d90(local_600," %-11G",local_5f0[1],param_4);
              }
              else {
                FUN_180002d90(local_600," %-11s",&DAT_180028740,param_4);
              }
              sVar3 = strlen(local_600);
              local_600 = local_600 + (int)sVar3;
            }
            for (local_5f8 = 0; local_5f8 < *(short *)(param_5 + 1) + -1; local_5f8 = local_5f8 + 1)
            {
              FUN_180007e70(0xb,local_4a8,(longlong *)&local_600);
              if (auStack_518[local_5f8] == 0xffffffff) {
                FUN_180002d90(local_600," %-11s",&DAT_180028740,param_4);
              }
              else {
                local_5f0 = (double *)
                            (param_5[10] + (longlong)(local_608 * *(short *)(param_5 + 3)) * 0x10 +
                             -0x10 + (longlong)(int)auStack_518[local_5f8] * 0x10);
                if ((local_5a0 == 1) && (local_5f0[1] != DAT_180029478)) {
                  FUN_180002d90(local_600," -%-10G",local_5f0[1],param_4);
                }
                else if ((local_5a0 == 2) && (local_5f0[1] != DAT_180029478)) {
                  FUN_180002d90(local_600," %-11G",local_5f0[1],param_4);
                }
              }
              sVar3 = strlen(local_600);
              local_600 = local_600 + (int)sVar3;
            }
            for (local_5f8 = 0; local_5f8 < *(short *)(param_5 + 1); local_5f8 = local_5f8 + 1) {
              if (auStack_4f8[local_5f8] != 0xffffffff) {
                FUN_180007e70(0xb,local_4a8,(longlong *)&local_600);
                local_5f0 = (double *)
                            (param_5[10] + (longlong)(local_608 * *(short *)(param_5 + 3)) * 0x10 +
                             -0x10 + (longlong)(int)auStack_4f8[local_5f8] * 0x10);
                if ((local_59c == 1) && (local_5f0[1] != DAT_180029478)) {
                  FUN_180002d90(local_600," -%-10G",local_5f0[1],param_4);
                }
                else if ((local_59c == 2) && (local_5f0[1] != DAT_180029478)) {
                  FUN_180002d90(local_600," %-11G",local_5f0[1],param_4);
                }
                else {
                  FUN_180002d90(local_600," %-11s",&DAT_180028740,param_4);
                }
                sVar3 = strlen(local_600);
                local_600 = local_600 + (int)sVar3;
              }
            }
          }
          if ((local_608 == 0) || (iVar1 = strcmp(local_1e8,local_4a8), iVar1 != 0)) {
            strcpy(local_1e8,local_4a8);
            FUN_180002d90(local_e8,"  STD-DEV %2i%s\n",(ulonglong)(local_608 + 1),local_4a8);
            param_4 = local_5c0;
            FUN_180004510(local_e8,local_2b8,0,param_4,param_1,0);
          }
          local_600 = local_4a8;
          puVar4 = (undefined *)(ulonglong)(local_608 + 1);
          FUN_180002d90(local_600,"  DATA    %2i",puVar4,param_4);
          sVar3 = strlen(local_600);
          local_600 = local_600 + (int)sVar3;
          if (local_5e8 != 0xffffffff) {
            FUN_180007e70(0xb,local_4a8,(longlong *)&local_600);
            local_5f0 = (double *)
                        (param_5[10] + (longlong)(local_608 * *(short *)(param_5 + 3)) * 0x10 +
                         -0x10 + (longlong)(int)local_5e8 * 0x10);
            if (*local_5f0 == DAT_180029478) {
              puVar4 = &DAT_180028740;
              FUN_180002d90(local_600," %-11s",&DAT_180028740,param_4);
            }
            else {
              puVar4 = (undefined *)(*local_5f0 * local_540);
              FUN_180002d90(local_600," %-11G",puVar4,param_4);
            }
            sVar3 = strlen(local_600);
            local_600 = local_600 + (int)sVar3;
          }
          if (local_5e4 != 0xffffffff) {
            FUN_180007e70(0xb,local_4a8,(longlong *)&local_600);
            local_5f0 = (double *)
                        (param_5[10] + (longlong)(local_608 * *(short *)(param_5 + 3)) * 0x10 +
                         -0x10 + (longlong)(int)local_5e4 * 0x10);
            if (*local_5f0 == DAT_180029478) {
              puVar4 = &DAT_180028740;
              FUN_180002d90(local_600," %-11s",&DAT_180028740,param_4);
            }
            else {
              puVar4 = (undefined *)(*local_5f0 * local_538);
              FUN_180002d90(local_600," %-11G",puVar4,param_4);
            }
            sVar3 = strlen(local_600);
            local_600 = local_600 + (int)sVar3;
          }
          for (local_5f8 = 0; local_5f8 < *(short *)(param_5 + 1) + -1; local_5f8 = local_5f8 + 1) {
            FUN_180007e70(0xb,local_4a8,(longlong *)&local_600);
            if (auStack_518[local_5f8] == 0xffffffff) {
              puVar4 = &DAT_1800290c4;
              FUN_180002d90(local_600," %-11s",&DAT_1800290c4,param_4);
            }
            else {
              local_5f0 = (double *)
                          (param_5[10] + (longlong)(local_608 * *(short *)(param_5 + 3)) * 0x10 +
                           -0x10 + (longlong)(int)auStack_518[local_5f8] * 0x10);
              if (*local_5f0 == DAT_180029478) {
                puVar4 = &DAT_1800290c4;
                FUN_180002d90(local_600," %-11s",&DAT_1800290c4,param_4);
              }
              else {
                puVar4 = (undefined *)*local_5f0;
                FUN_180002d90(local_600," %-11G",puVar4,param_4);
              }
            }
            sVar3 = strlen(local_600);
            local_600 = local_600 + (int)sVar3;
          }
          for (local_5f8 = 0; local_5f8 < *(short *)(param_5 + 1); local_5f8 = local_5f8 + 1) {
            FUN_180007e70(0xb,local_4a8,(longlong *)&local_600);
            if (auStack_4f8[local_5f8] == 0xffffffff) {
              puVar4 = &DAT_180029104;
              FUN_180002d90(local_600," %-11s",&DAT_180029104,param_4);
            }
            else {
              local_5f0 = (double *)
                          (param_5[10] + (longlong)(local_608 * *(short *)(param_5 + 3)) * 0x10 +
                           -0x10 + (longlong)(int)auStack_4f8[local_5f8] * 0x10);
              if (*local_5f0 == DAT_180029478) {
                puVar4 = &DAT_180028740;
                FUN_180002d90(local_600," %-11s",&DAT_180028740,param_4);
              }
              else {
                puVar4 = (undefined *)*local_5f0;
                FUN_180002d90(local_600," %-11G",puVar4,param_4);
              }
            }
            sVar3 = strlen(local_600);
            local_600 = local_600 + (int)sVar3;
          }
          FUN_180002d90(local_600,&DAT_180027258,puVar4,param_4);
          local_598 = (uint)(local_608 == *(short *)((longlong)param_5 + 0x5a));
          param_4 = local_5c0;
          pcVar2 = (char *)0x1;
          FUN_180004510(local_4a8,local_2b8,1,param_4,param_1,local_598);
        }
        FUN_180007f00(param_1,&DAT_180029034,pcVar2,param_4);
        FUN_180007f00(param_1,&DAT_180029084,pcVar2,param_4);
      }
      return;
    }
    local_608 = 0;
    while (((&PTR_DAT_18002e740)[(longlong)local_608 * 3] != (undefined *)0x0 &&
           (iVar1 = _stricmp((&PTR_DAT_18002e740)[(longlong)local_608 * 3],(char *)local_5d8),
           iVar1 != 0))) {
      local_608 = local_608 + 1;
    }
    if (((&PTR_DAT_18002e748)[(longlong)local_608 * 3] == (undefined *)0x0) ||
       (*(&PTR_DAT_18002e748)[(longlong)local_608 * 3] != 'T')) {
      if (((&PTR_DAT_18002e748)[(longlong)local_608 * 3] == (undefined *)0x0) ||
         (*(&PTR_DAT_18002e748)[(longlong)local_608 * 3] != 'P')) {
        if (((&PTR_DAT_18002e748)[(longlong)local_608 * 3] == (undefined *)0x0) ||
           (*(&PTR_DAT_18002e748)[(longlong)local_608 * 3] != 'X')) {
          if (((&PTR_DAT_18002e748)[(longlong)local_608 * 3] != (undefined *)0x0) &&
             (iVar1 = _stricmp((&PTR_DAT_18002e748)[(longlong)local_608 * 3],"GAMMA"), iVar1 == 0))
          {
            if (local_590 == (undefined *)0x0) {
              local_590 = FUN_1800082f0(local_5e0,0x21,&local_520);
              param_3 = local_5e0;
              if (local_590 == (undefined *)0x0) {
                param_4 = local_5d8;
                FUN_1800220b0(1,"Unit <%s> for property <%s> not supported by Aspen Plus",local_5e0,
                              local_5d8);
                goto LAB_180019c74;
              }
              param_4 = (uint *)(ulonglong)local_5f4;
              local_59c = FUN_1800042c0((longlong)param_5,local_5d8,local_5e0,local_5f4);
            }
            auStack_4f8[local_5c4] = local_5f4;
            local_5c4 = local_5c4 + 1;
          }
        }
        else {
          if (local_5b8 == (char *)0x0) {
            local_5b8 = FUN_1800082f0(local_5e0,0x20,&local_528);
            param_3 = local_5e0;
            if (local_5b8 == (char *)0x0) {
              param_4 = local_5d8;
              FUN_1800220b0(1,"Unit <%s> for property <%s> not supported by Aspen Plus",local_5e0,
                            local_5d8);
              goto LAB_180019c74;
            }
            param_4 = (uint *)(ulonglong)local_5f4;
            local_5a0 = FUN_1800042c0((longlong)param_5,local_5d8,local_5e0,local_5f4);
          }
          auStack_518[local_5c8] = local_5f4;
          local_5c8 = local_5c8 + 1;
        }
      }
      else {
        local_570 = FUN_1800082f0(local_5e0,0x16,&local_538);
        if (local_570 == (undefined *)0x0) {
          FUN_1800220b0(1,"Unit <%s> for property <%s> not supported by Aspen Plus",local_5e0,
                        local_5d8);
        }
        else {
          local_5e4 = local_5f4;
          local_5ac = local_5ac + 1;
        }
        param_4 = (uint *)(ulonglong)local_5f4;
        param_3 = local_5e0;
        local_5a4 = FUN_1800042c0((longlong)param_5,local_5d8,local_5e0,local_5f4);
      }
    }
    else {
      local_578 = FUN_1800082f0(local_5e0,0x19,&local_540);
      if (local_578 == (undefined *)0x0) {
        FUN_1800220b0(1,"Unit <%s> for property <%s> not supported by Aspen Plus",local_5e0,
                      local_5d8);
      }
      else {
        local_5e8 = local_5f4;
        local_5b0 = local_5b0 + 1;
      }
      param_4 = (uint *)(ulonglong)local_5f4;
      param_3 = local_5e0;
      local_5a8 = FUN_1800042c0((longlong)param_5,local_5d8,local_5e0,local_5f4);
    }
LAB_180019c74:
    local_5f4 = local_5f4 + 1;
    local_5d8 = (uint *)((longlong)local_5d8 + 0xd);
    local_5e0 = local_5e0 + 0x14;
  } while( true );
}

