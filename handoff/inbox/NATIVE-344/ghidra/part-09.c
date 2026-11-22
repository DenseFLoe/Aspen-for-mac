/* RVA 0x2e060 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_18002e060(void)

{
  undefined1 auStack_f8 [32];
  int *local_d8;
  undefined8 local_d0;
  int local_c8 [4];
  undefined4 local_b8;
  undefined2 local_b4;
  undefined1 local_b2;
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_f8;
  local_b4 = DAT_180041814;
  local_b2 = DAT_180041816;
  local_b8 = 0;
  local_d0 = 0;
  local_c8[1] = 1;
  local_d8 = local_c8;
  SELF_INITIALIZE(&local_b8,local_c8 + 1,FUN_18002e110,*(longlong *)SBdataptr_exref + 0xc10);
  if (-1 < local_c8[0]) {
    Getlocalserver(&DAT_180052d78);
  }
  return local_c8[0];
}

/* RVA 0x2e110 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00018002f18f) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_18002e110(int *param_1,int *param_2,longlong param_3,undefined8 param_4)

{
  char cVar1;
  uchar uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  clock_t cVar6;
  uint uVar7;
  undefined8 uVar8;
  char *pcVar9;
  ulonglong uVar10;
  char *pcVar11;
  undefined2 *puVar12;
  longlong lVar13;
  uchar *puVar14;
  undefined4 *puVar15;
  undefined1 *puVar16;
  uint uVar17;
  uchar *puVar18;
  int iVar19;
  ulonglong uVar20;
  uint *puVar21;
  longlong lVar22;
  longlong lVar23;
  int *piVar24;
  int **ppiVar25;
  int iVar26;
  bool bVar27;
  double dVar28;
  double dVar29;
  undefined1 auStackY_388 [24];
  int local_370 [2];
  int local_348;
  undefined8 local_340;
  undefined8 uStack_338;
  undefined1 local_330 [8];
  undefined8 local_328;
  undefined8 uStack_320;
  undefined8 local_318;
  undefined8 uStack_310;
  undefined8 local_308;
  undefined8 uStack_300;
  undefined8 local_2f8;
  undefined8 uStack_2f0;
  undefined8 local_2e8;
  undefined8 uStack_2e0;
  undefined4 local_2d8;
  undefined4 uStack_2d4;
  undefined4 uStack_2d0;
  undefined4 uStack_2cc;
  double local_2c8 [3];
  int *local_2b0;
  undefined1 local_2a8;
  int local_2a0 [2];
  undefined1 local_298;
  char local_290 [8];
  undefined1 local_288;
  char local_280 [8];
  undefined1 local_278;
  int *local_270;
  undefined1 local_268;
  undefined2 uStack_259;
  undefined1 auStack_209 [9];
  undefined8 uStack_200;
  undefined8 local_1f8;
  undefined8 uStack_1f0;
  undefined8 local_1e8;
  undefined8 uStack_1e0;
  undefined8 local_1d8;
  undefined8 uStack_1d0;
  undefined8 local_1c8;
  undefined8 uStack_1c0;
  char local_1b8 [79];
  undefined1 local_169;
  uchar local_168 [4];
  undefined1 local_164 [268];
  ulonglong local_58;
  
  local_58 = DAT_1800516d8 ^ (ulonglong)auStackY_388;
  iVar26 = 0;
  iVar5 = *param_1;
  *(undefined4 *)not_in_aspmsg_exref = 0;
  *(undefined8 *)(param_3 + 4) = 4;
  local_2b0 = param_1;
  iVar4 = GRinqssu();
  if (((iVar4 != 0) && (iVar4 = SimQueryStopButtonPressed(), iVar4 != 0)) ||
     (((uVar8 = EXmsgbox(), (int)uVar8 != 0 && (iVar4 = GRinqssu(), iVar4 != 0)) &&
      (((iVar4 = _guard_check_icall(), iVar4 == 0x53 || (iVar4 == 0x73)) || (iVar4 == 0xd)))))) {
    GRsetust(1);
    *(undefined4 *)(param_3 + 8) = 1;
  }
  iVar4 = param_2[2];
  bVar27 = DAT_180052e98 != 0;
  if (((iVar4 == 0) || (iVar4 == -0x1e)) || ((DAT_180052e94 != 0 || (bVar27)))) {
    if (DAT_180052e94 == 0) {
      if (!bVar27) {
        hide_mouse();
        if (DAT_1800521b0 == 1) {
          DAT_1800521b0 = 0;
          hide_mouse();
          if (DAT_180050de0 != 0) {
            thunk_FUN_180008f30("");
            pcVar9 = (char *)GetSorResStringEx(0x783);
            FUN_180008f30(pcVar9);
          }
          show_mouse();
          if ((*(int *)sbcanned_exref == 0) && (*(int *)(*(longlong *)topfinfo_exref + 0x380) == 1))
          {
            FUN_180031470();
          }
          else {
            show_mouse();
          }
        }
        if (param_2[2] == -0x1e) {
          if (DAT_180052d88 == (char *)0x0) {
            DAT_180052d88 = (char *)MDmalloc(0x78);
            DAT_180052ea8 = 0x78;
          }
          *DAT_180052d88 = '\0';
        }
        piVar24 = param_2;
        if (iVar5 != 0) {
          do {
            uVar20 = (ulonglong)piVar24[3];
            uVar10 = uVar20;
            if (0x4f < uVar20) {
              uVar10 = 0x50;
            }
            *(undefined1 *)(uVar10 + 0x10 + (longlong)piVar24) = 0;
            strncpy(local_1b8,(char *)(piVar24 + 4),0x4f);
            local_169 = 0;
            if (piVar24[2] == -0x1e) {
              lVar23 = -1;
              do {
                lVar23 = lVar23 + 1;
              } while (DAT_180052d88[lVar23] != '\0');
              uVar10 = uVar20 + 1 + lVar23;
              if (DAT_180052ea8 <= uVar10) {
                DAT_180052d88 = (char *)MDrealloc();
                DAT_180052ea8 = uVar10 + 0x50;
              }
              pcVar9 = DAT_180052d88 + -1;
              do {
                pcVar11 = pcVar9 + 1;
                pcVar9 = pcVar9 + 1;
              } while (*pcVar11 != '\0');
              lVar23 = 0;
              do {
                cVar1 = local_1b8[lVar23];
                pcVar9[lVar23] = cVar1;
                lVar23 = lVar23 + 1;
              } while (cVar1 != '\0');
            }
            SFfiltra();
            hide_mouse();
            if ((piVar24[2] != -0x1e) && (DAT_180050de0 != 0)) {
              SimUpdateMessageView(0,local_1b8);
            }
            show_mouse();
            iVar5 = iVar5 + -1;
            if (0 < iVar5) {
              piVar24 = piVar24 + 0x44;
            }
          } while (iVar5 != 0);
          param_1 = local_2b0;
        }
        if (piVar24[2] == -0x1e) {
          pcVar9 = strchr(DAT_180052d88,0xd);
          while (pcVar9 != (char *)0x0) {
            pcVar11 = pcVar9 + -1;
            cVar1 = pcVar9[-1];
            while (cVar1 == ' ') {
              pcVar11 = pcVar11 + -1;
              cVar1 = *pcVar11;
            }
            pcVar9 = pcVar9 + 2;
            pcVar11[1] = '\r';
            pcVar11[2] = '\n';
            cVar1 = *pcVar9;
            while (cVar1 == ' ') {
              pcVar9 = pcVar9 + 1;
              cVar1 = *pcVar9;
            }
            lVar23 = (longlong)(pcVar11 + 3) - (longlong)pcVar9;
            do {
              cVar1 = *pcVar9;
              pcVar9[lVar23] = cVar1;
              pcVar9 = pcVar9 + 1;
            } while (cVar1 != '\0');
            pcVar9 = strchr(pcVar11 + 3,0xd);
          }
        }
        show_mouse();
      }
      if (!bVar27) goto LAB_18002f4e9;
LAB_18002f069:
      DAT_180052e98 = param_2[3];
      iVar5 = *param_1;
      if (DAT_180052e98 == 0) {
        FUN_180021800(*(longlong *)(*(longlong *)topfinfo_exref + 0x560),0);
      }
      while( true ) {
        if (iVar5 == 0) break;
        iVar26 = 0;
        if (0 < param_2[4]) {
          piVar24 = param_2 + 5;
          do {
            strncpy(local_280,(char *)(param_2 + (longlong)iVar26 * 4 + 6),8);
            uVar10 = 0;
            local_278 = 0;
            do {
              if (local_280[uVar10] == ' ') {
                if (8 < uVar10) goto LAB_18002f538;
                local_280[uVar10] = '\0';
              }
              uVar10 = uVar10 + 1;
            } while ((longlong)uVar10 < 8);
            pcVar9 = FUN_180027200(local_280);
            lVar23 = -0x4f - (longlong)pcVar9;
            do {
              cVar1 = *pcVar9;
              pcVar9[(longlong)(auStack_209 + lVar23)] = cVar1;
              pcVar9 = pcVar9 + 1;
            } while (cVar1 != '\0');
            FUN_180020520(*(longlong *)(*(longlong *)topfinfo_exref + 0x560),0,*piVar24,piVar24[3],
                          (char *)((longlong)&uStack_259 + 1));
            iVar26 = iVar26 + 1;
            piVar24 = piVar24 + 4;
          } while (iVar26 < param_2[4]);
        }
        param_2 = param_2 + 0x44;
        iVar5 = iVar5 + -1;
      }
      goto LAB_18002f4e9;
    }
LAB_18002f4da:
    iVar5 = 0;
LAB_18002f4dd:
    FUN_1800077e0((longlong)param_2,*param_1,iVar5);
    goto LAB_18002f4e9;
  }
  if (iVar4 == 1) {
    if (param_2[3] == 0x29a) {
      piVar24 = param_2 + 7;
      iVar5 = (param_2[5] + -1) / 2;
      VRupdbox(iVar5,piVar24,piVar24 + iVar5,piVar24 + iVar5 + (longlong)iVar5 + 1);
    }
    goto LAB_18002f4e9;
  }
  if (iVar4 == 2) {
    *(undefined1 *)(param_2 + 7) = 0;
    if (0 < param_2[3]) {
      DAT_180052e90 = DAT_180052e90 + 1;
      if (DAT_180052e90 == 100) {
        FUN_18002f5f0(param_3);
      }
      *(undefined1 *)(param_2 + 7) = 0;
      pcVar9 = FUN_18002f550((char *)((longlong)&uStack_259 + 1),(longlong)(param_2 + 5));
      SBsetnxt(pcVar9,param_2[3]);
    }
    goto LAB_18002f4e9;
  }
  if (iVar4 == 3) {
    local_2b0 = (int *)0x2020202020202020;
    strncpy((char *)&local_2b0,(char *)(param_2 + 5),8);
    iVar5 = param_2[7];
    local_2a8 = 0;
    if (iVar5 == -1) {
      param_2[7] = 2;
    }
    else if (iVar5 == 0) {
      param_2[7] = 1;
    }
    else if (iVar5 == 1) {
      param_2[7] = 0;
    }
    else if (iVar5 == 2) {
      param_2[7] = 3;
    }
    FUN_18002f550((char *)((longlong)&uStack_259 + 1),(longlong)&local_2b0);
    uVar17 = param_2[4] >> 0x1f;
    iVar5 = (param_2[4] ^ uVar17) - uVar17;
    param_2[4] = iVar5;
    FUN_18001ebd0(param_2[3],iVar5,(char *)((longlong)&uStack_259 + 1));
    dVar29 = DAT_180041698;
    if (param_2[3] == 1) {
      lVar22 = 0;
      local_2c8[0] = (double)CONCAT44(_UNK_1800416a4,_DAT_1800416a0);
      local_2c8[1] = (double)CONCAT44(_UNK_1800416ac,_UNK_1800416a8);
      lVar23 = 0;
      local_2c8[2] = DAT_180041698;
      *(undefined1 *)((longlong)param_2[8] + 0x24 + (longlong)param_2) = 0;
      do {
        pcVar9 = (char *)((longlong)param_2 + lVar23 + 0x24);
        if (*pcVar9 == ' ') {
          iVar26 = iVar26 + 1;
          lVar23 = lVar23 + 1;
        }
        else {
          if (*pcVar9 == '*') {
            dVar28 = dVar29;
          }
          else {
            dVar28 = atof((char *)((longlong)iVar26 + 0x24 + (longlong)param_2));
          }
          local_2c8[lVar22] = dVar28;
          if (lVar22 == 2) break;
          cVar1 = *pcVar9;
          while (cVar1 != ' ') {
            iVar26 = iVar26 + 1;
            pcVar9 = pcVar9 + 1;
            lVar23 = lVar23 + 1;
            cVar1 = *pcVar9;
          }
          lVar22 = lVar22 + 1;
        }
      } while (lVar22 < 3);
      uVar17 = param_2[4];
      if (uVar17 < 0xae) {
        if (uVar17 == 0x1e) {
          uVar17 = 0x25;
          param_2[4] = 0x25;
        }
        GRset_global_block_data
                  ((&PTR_DAT_180050e90)[(int)uVar17],(longlong)&uStack_259 + 1,local_2c8);
      }
    }
    goto LAB_18002f4e9;
  }
  if (iVar4 == 4) {
    local_328 = CONCAT44(_UNK_1800416a4,_DAT_1800416a0);
    uStack_320 = CONCAT44(_UNK_1800416ac,_UNK_1800416a8);
    local_318 = CONCAT44(_UNK_1800416a4,_DAT_1800416a0);
    uStack_310 = CONCAT44(_UNK_1800416ac,_UNK_1800416a8);
    local_308 = CONCAT44(_UNK_1800416a4,_DAT_1800416a0);
    uStack_300 = CONCAT44(_UNK_1800416ac,_UNK_1800416a8);
    local_2f8 = CONCAT44(_UNK_1800416a4,_DAT_1800416a0);
    uStack_2f0 = CONCAT44(_UNK_1800416ac,_UNK_1800416a8);
    local_2e8 = CONCAT44(_UNK_1800416a4,_DAT_1800416a0);
    uStack_2e0 = CONCAT44(_UNK_1800416ac,_UNK_1800416a8);
    iVar26 = 0;
    local_2d8 = _DAT_1800416a0;
    uStack_2d4 = _UNK_1800416a4;
    uStack_2d0 = _UNK_1800416a8;
    uStack_2cc = _UNK_1800416ac;
    local_340 = _DAT_1800412d0;
    uStack_338 = _UNK_1800412d8;
    local_330 = (undefined1  [8])0xffffffffffffffff;
    local_2b0 = (int *)0x2020202020202020;
    strncpy((char *)&local_2b0,(char *)(param_2 + 4),8);
    iVar5 = param_2[6];
    local_2a8 = 0;
    if (iVar5 == -1) {
      param_2[6] = 2;
    }
    else if (iVar5 == 0) {
      param_2[6] = 1;
    }
    else if (iVar5 == 1) {
      param_2[6] = 0;
    }
    else if (iVar5 == 2) {
      param_2[6] = 3;
    }
    FUN_18002f550((char *)((longlong)&uStack_259 + 1),(longlong)&local_2b0);
    FUN_18001f6d0(param_2[3],0,(longlong)&uStack_259 + 1,param_2[6]);
    GRset_global_stream_data
              ((&PTR_DAT_180051400)[param_2[3]],(longlong)&uStack_259 + 1,&local_328,&local_340);
    lVar22 = 0;
    lVar23 = 0;
    piVar24 = local_370;
    *(undefined1 *)((longlong)param_2[7] + 0x20 + (longlong)param_2) = 0;
    do {
      pcVar9 = (char *)((longlong)param_2 + lVar23 + 0x20);
      if (*pcVar9 == ' ') {
        iVar26 = iVar26 + 1;
        lVar23 = lVar23 + 1;
      }
      else {
        if (*pcVar9 == '*') {
          if (0xb < lVar22) {
            iVar5 = -1;
            goto LAB_18002e564;
          }
          local_2c8[lVar22 + -0xc] = -1e+28;
        }
        else {
          pcVar11 = (char *)((longlong)param_2 + (longlong)iVar26 + 0x20);
          if (lVar22 < 0xc) {
            dVar29 = atof(pcVar11);
            local_2c8[lVar22 + -0xc] = dVar29;
          }
          else {
            iVar5 = atoi(pcVar11);
LAB_18002e564:
            *piVar24 = iVar5;
            if (lVar22 == 0x11) break;
          }
        }
        cVar1 = *pcVar9;
        while (cVar1 != ' ') {
          iVar26 = iVar26 + 1;
          pcVar9 = pcVar9 + 1;
          lVar23 = lVar23 + 1;
          cVar1 = *pcVar9;
        }
        lVar22 = lVar22 + 1;
        piVar24 = piVar24 + 1;
      }
    } while (lVar22 < 0x12);
    GRset_global_stream_data
              ((&PTR_DAT_180051400)[param_2[3]],(longlong)&uStack_259 + 1,&local_328,&local_340);
    goto LAB_18002f4e9;
  }
  if (iVar4 == 5) {
    iVar5 = param_2[4];
    if (iVar5 == -1) {
      param_2[4] = 2;
    }
    else if (iVar5 == 0) {
      param_2[4] = 1;
    }
    else if (iVar5 == 1) {
      param_2[4] = 0;
    }
    else if (iVar5 == 2) {
      param_2[4] = 3;
    }
    FUN_18002f550((char *)((longlong)&uStack_259 + 1),
                  (longlong)(&PTR_DAT_180051430)[-(longlong)param_2[3]]);
    FUN_18001f8c0((ulonglong)(uint)param_2[3],param_2[3],(longlong)&uStack_259 + 1,param_2[4]);
    goto LAB_18002f4e9;
  }
  if (iVar4 == 6) {
    SimProcShwseqMessage((longlong)param_2,*param_1);
    goto LAB_18002f4e9;
  }
  if (iVar4 == -4) goto LAB_18002f4da;
  if (iVar4 == -6) goto LAB_18002f4e9;
  if (iVar4 == -0xb) {
    iVar5 = 1;
    goto LAB_18002f4dd;
  }
  if (iVar4 == -7) {
    GRsetcat(param_2[3]);
    goto LAB_18002f4e9;
  }
  if (iVar4 != -8) {
    if (iVar4 != -9) {
      if (iVar4 == -10) {
        if (DAT_180052d70 == (FILE *)0x0) {
          puVar18 = local_168;
          puVar14 = *(uchar **)topfinfo_exref;
          do {
            uVar2 = *puVar14;
            puVar14 = puVar14 + 1;
            *puVar18 = uVar2;
            puVar18 = puVar18 + 1;
          } while (uVar2 != '\0');
          puVar3 = (undefined4 *)&local_169;
          do {
            puVar15 = puVar3;
            puVar3 = (undefined4 *)((longlong)puVar15 + 1);
          } while (*(char *)((longlong)puVar15 + 1) != '\0');
          *(undefined4 *)((longlong)puVar15 + 1) = DAT_1800410f8;
          *(undefined1 *)((longlong)puVar15 + 5) = DAT_1800410fc;
          _mbslwr(local_168);
          DAT_180052d70 = fopen((char *)local_168,"w");
        }
        local_348 = *param_1;
        if (local_348 == 0) {
          piVar24 = local_2b0;
        }
        else {
          do {
            local_2a0[0] = param_2[4];
            puVar21 = (uint *)(param_2 + 5);
            iVar5 = 0;
            local_328 = 0;
            uStack_320 = 0;
            local_318 = 0;
            uStack_310 = 0;
            local_308 = 0;
            uStack_300 = 0;
            local_2f8 = 0;
            uStack_2f0 = 0;
            local_2e8 = 0;
            uStack_2e0 = 0;
            auStack_209._1_8_ = 0;
            uStack_200 = 0;
            local_1f8 = 0;
            uStack_1f0 = 0;
            local_1e8 = 0;
            uStack_1e0 = 0;
            local_1d8 = 0;
            uStack_1d0 = 0;
            local_1c8 = 0;
            uStack_1c0 = 0;
            if (0 < local_2a0[0]) {
              do {
                uVar17 = *puVar21;
                strncpy(local_290,(char *)(puVar21 + 1),8);
                local_288 = 0;
                pcVar9 = strchr(local_290,0x20);
                if (pcVar9 != (char *)0x0) {
                  *pcVar9 = '\0';
                }
                uVar7 = puVar21[3];
                puVar21 = puVar21 + 4;
                if (uVar7 == 0) {
                  lVar23 = 0;
                  do {
                    cVar1 = local_290[lVar23];
                    local_330[lVar23 + 8] = cVar1;
                    lVar23 = lVar23 + 1;
                  } while (cVar1 != '\0');
                }
                else {
                  if (0x4f < uVar7) {
                    uVar7 = 0x4f;
                  }
                  uVar10 = (ulonglong)(int)uVar7;
                  strncpy((char *)&local_328,(char *)puVar21,uVar10);
                  if (0x4f < uVar10) goto LAB_18002f53e;
                  local_330[uVar10 + 8] = 0;
                  puVar12 = (undefined2 *)(local_330 + 7);
                  do {
                    pcVar9 = (char *)((longlong)puVar12 + 1);
                    puVar12 = (undefined2 *)((longlong)puVar12 + 1);
                  } while (*pcVar9 != '\0');
                  *puVar12 = _DAT_18003fa80;
                  puVar16 = local_330 + 7;
                  do {
                    pcVar9 = puVar16 + 1;
                    puVar16 = puVar16 + 1;
                  } while (*pcVar9 != '\0');
                  lVar23 = 0;
                  do {
                    cVar1 = local_290[lVar23];
                    puVar16[lVar23] = cVar1;
                    lVar23 = lVar23 + 1;
                  } while (cVar1 != '\0');
                  puVar21 = (uint *)((longlong)puVar21 + uVar10);
                }
                strncpy(local_290,(char *)(puVar21 + 1),8);
                local_288 = 0;
                pcVar9 = strchr(local_290,0x20);
                if (pcVar9 != (char *)0x0) {
                  *pcVar9 = '\0';
                }
                uVar7 = puVar21[3];
                puVar21 = puVar21 + 4;
                if (uVar7 == 0) {
                  lVar23 = 0;
                  do {
                    cVar1 = local_290[lVar23];
                    auStack_209[lVar23 + 1] = cVar1;
                    lVar23 = lVar23 + 1;
                  } while (cVar1 != '\0');
                }
                else {
                  if (0x4f < uVar7) {
                    uVar7 = 0x4f;
                  }
                  uVar10 = (ulonglong)(int)uVar7;
                  strncpy(auStack_209 + 1,(char *)puVar21,uVar10);
                  if (0x4f < uVar10) {
LAB_18002f53e:
                    /* WARNING: Subroutine does not return */
                    FUN_18003b6e4();
                  }
                  auStack_209[uVar10 + 1] = 0;
                  puVar12 = (undefined2 *)auStack_209;
                  do {
                    pcVar9 = (char *)((longlong)puVar12 + 1);
                    puVar12 = (undefined2 *)((longlong)puVar12 + 1);
                  } while (*pcVar9 != '\0');
                  *puVar12 = _DAT_18003fa80;
                  puVar16 = auStack_209;
                  do {
                    pcVar9 = puVar16 + 1;
                    puVar16 = puVar16 + 1;
                  } while (*pcVar9 != '\0');
                  lVar23 = 0;
                  do {
                    cVar1 = local_290[lVar23];
                    puVar16[lVar23] = cVar1;
                    lVar23 = lVar23 + 1;
                  } while (cVar1 != '\0');
                  puVar21 = (uint *)((longlong)puVar21 + uVar10);
                }
                FUN_180028920(DAT_180052d70,"%d %s %d %s\n",(ulonglong)uVar17,&local_328);
                iVar5 = iVar5 + 1;
              } while (iVar5 < local_2a0[0]);
            }
            local_348 = local_348 + -1;
            piVar24 = param_2;
            param_2 = param_2 + 0x44;
          } while (local_348 != 0);
        }
        if (piVar24[3] == 0) {
          *(uint *)(Sactions_exref + 4) = *(uint *)(Sactions_exref + 4) | 8;
          fclose(DAT_180052d70);
        }
      }
      else if ((iVar4 + 0x12U < 7) || (iVar4 == -0x21)) {
        FUN_18003a630(param_1,(longlong)param_2,param_3,param_4);
      }
      else if (iVar4 == -0x13) {
        uVar10 = (ulonglong)param_2[3];
        if (0x40 < uVar10) {
          uVar10 = 0x40;
        }
        *(undefined1 *)(uVar10 + (longlong)(param_2 + 4)) = 0;
        strncpy(&DAT_180053860,(char *)(param_2 + 4),0x40);
        DAT_1800538a0 = 0;
        pcVar9 = strchr(&DAT_180053860,0x20);
        if (pcVar9 != (char *)0x0) {
          *pcVar9 = '\0';
        }
      }
      else if (iVar4 == -0x14) {
        iVar5 = param_2[3];
        iVar26 = param_2[4];
        strncpy(local_280,(char *)(param_2 + 5),8);
        local_278 = 0;
        pcVar9 = strchr(local_280,0x20);
        if (pcVar9 != (char *)0x0) {
          *pcVar9 = '\0';
        }
        uVar10 = (ulonglong)param_2[8];
        iVar4 = param_2[7];
        strncpy((char *)((longlong)&uStack_259 + 1),(char *)(param_2 + 9),uVar10);
        if (0x4f < uVar10) goto LAB_18002f538;
        auStack_209[uVar10 - 0x4f] = 0;
        if (uStack_259._1_1_ != '\0') {
          puVar12 = &uStack_259;
          do {
            pcVar9 = (char *)((longlong)puVar12 + 1);
            puVar12 = (undefined2 *)((longlong)puVar12 + 1);
          } while (*pcVar9 != '\0');
          *puVar12 = _DAT_18003fa80;
        }
        puVar12 = &uStack_259;
        do {
          pcVar9 = (char *)((longlong)puVar12 + 1);
          puVar12 = (undefined2 *)((longlong)puVar12 + 1);
        } while (*pcVar9 != '\0');
        lVar23 = 0;
        do {
          cVar1 = local_280[lVar23];
          *(char *)((longlong)puVar12 + lVar23) = cVar1;
          lVar23 = lVar23 + 1;
        } while (cVar1 != '\0');
        FUN_18001ed40(iVar26,0,(char *)((longlong)&uStack_259 + 1),iVar4,
                      (longlong)param_2 + uVar10 + 0x28,*(int *)(uVar10 + 0x24 + (longlong)param_2),
                      DAT_180050df8);
        DAT_180050df8 = (uint)(iVar5 == 0);
      }
      else if (iVar4 == -0x15) {
        uVar10 = (ulonglong)param_2[5];
        iVar5 = param_2[3];
        iVar26 = param_2[4];
        lVar23 = 0;
        iVar4 = 0;
        strncpy((char *)((longlong)&uStack_259 + 1),(char *)(param_2 + 6),uVar10);
        if (0x4f < uVar10) {
                    /* WARNING: Subroutine does not return */
          FUN_18003b6e4();
        }
        auStack_209[uVar10 - 0x4f] = 0;
        strncpy((char *)&local_270,(char *)((longlong)param_2 + uVar10 + 0x18),8);
        local_268 = 0;
        pcVar9 = strchr((char *)&local_270,0x20);
        if (pcVar9 != (char *)0x0) {
          *pcVar9 = '\0';
        }
        strncpy((char *)&local_2b0,(char *)((longlong)param_2 + uVar10 + 0x20),8);
        local_2a8 = 0;
        pcVar9 = strchr((char *)&local_2b0,0x20);
        if (pcVar9 != (char *)0x0) {
          *pcVar9 = '\0';
        }
        if ((iVar26 == -1) && (iVar4 = *(int *)(uVar10 + 0x28 + (longlong)param_2), iVar4 != 0)) {
          lVar23 = (longlong)param_2 + uVar10 + 0x2c;
        }
        if ((char)local_270 != '\0') {
          lVar22 = 0;
          do {
            lVar13 = lVar22 + 1;
            if (*(char *)((longlong)&local_270 + lVar22) != (&DAT_18004049c)[lVar22]) {
              iVar19 = 8;
              goto LAB_18002e949;
            }
            lVar22 = lVar13;
          } while (lVar13 != 4);
        }
        iVar19 = 1;
LAB_18002e949:
        if (DAT_180052ea4 == 0) {
          ppiVar25 = &local_270;
          if (iVar19 != 8) {
            ppiVar25 = &local_2b0;
          }
          FUN_18001a710(iVar19,(char *)((longlong)&uStack_259 + 1),(char *)ppiVar25,0);
        }
        FUN_18001f000(iVar19,(char *)&local_270,(char *)((longlong)&uStack_259 + 1),iVar26,lVar23,
                      iVar4,(char *)&local_2b0,0);
        DAT_180052ea4 = iVar5;
      }
      else if (iVar4 == -0x16) {
        uVar10 = (ulonglong)param_2[5];
        iVar5 = param_2[3];
        iVar26 = param_2[4];
        strncpy((char *)((longlong)&uStack_259 + 1),(char *)(param_2 + 6),uVar10);
        if (0x4f < uVar10) {
                    /* WARNING: Subroutine does not return */
          FUN_18003b6e4();
        }
        auStack_209[uVar10 - 0x4f] = 0;
        strncpy((char *)&local_2b0,(char *)((longlong)param_2 + uVar10 + 0x18),8);
        local_2a8 = 0;
        pcVar9 = strchr((char *)&local_2b0,0x20);
        if (pcVar9 != (char *)0x0) {
          *pcVar9 = '\0';
        }
        if (DAT_180052eb0 == 0) {
          FUN_18001a710(2,(char *)((longlong)&uStack_259 + 1),(char *)&local_2b0,0);
        }
        iVar4 = *(int *)(uVar10 + 0x20 + (longlong)param_2);
        if (iVar4 == 0) {
          lVar23 = 0;
        }
        else {
          lVar23 = (longlong)param_2 + uVar10 + 0x24;
        }
        FUN_18001f000(2,(char *)&local_2b0,(char *)((longlong)&uStack_259 + 1),iVar26,lVar23,iVar4,
                      (char *)0x0,0);
        DAT_180052eb0 = iVar5;
      }
      else if (iVar4 == -0x17) {
        uVar10 = (ulonglong)param_2[6];
        iVar5 = param_2[3];
        iVar26 = param_2[4];
        iVar4 = param_2[5];
        strncpy((char *)((longlong)&uStack_259 + 1),(char *)(param_2 + 7),uVar10);
        if (0x4f < uVar10) {
                    /* WARNING: Subroutine does not return */
          FUN_18003b6e4();
        }
        auStack_209[uVar10 - 0x4f] = 0;
        strncpy((char *)&local_2b0,(char *)((longlong)param_2 + uVar10 + 0x1c),8);
        local_2a8 = 0;
        pcVar9 = strchr((char *)&local_2b0,0x20);
        if (pcVar9 != (char *)0x0) {
          *pcVar9 = '\0';
        }
        if (DAT_180052eb4 == 0) {
          FUN_18001a710(3,(char *)((longlong)&uStack_259 + 1),(char *)&local_2b0,iVar4);
        }
        iVar19 = *(int *)(uVar10 + 0x24 + (longlong)param_2);
        if (iVar19 == 0) {
          lVar23 = 0;
        }
        else {
          lVar23 = (longlong)param_2 + uVar10 + 0x28;
        }
        FUN_18001f000(3,(char *)&local_2b0,(char *)((longlong)&uStack_259 + 1),iVar26,lVar23,iVar19,
                      (char *)0x0,iVar4);
        DAT_180052eb4 = iVar5;
      }
      else if (iVar4 == -0x19) {
        uVar10 = (ulonglong)param_2[5];
        iVar5 = param_2[3];
        iVar26 = param_2[4];
        strncpy((char *)((longlong)&uStack_259 + 1),(char *)(param_2 + 6),uVar10);
        if (0x4f < uVar10) {
                    /* WARNING: Subroutine does not return */
          FUN_18003b6e4();
        }
        auStack_209[uVar10 - 0x4f] = 0;
        strncpy((char *)local_2a0,(char *)((longlong)param_2 + uVar10 + 0x18),8);
        local_298 = 0;
        pcVar9 = strchr((char *)local_2a0,0x20);
        if (pcVar9 != (char *)0x0) {
          *pcVar9 = '\0';
        }
        strncpy((char *)&local_2b0,(char *)((longlong)param_2 + uVar10 + 0x20),8);
        local_2a8 = 0;
        pcVar9 = strchr((char *)&local_2b0,0x20);
        if (pcVar9 != (char *)0x0) {
          *pcVar9 = '\0';
        }
        iVar4 = 7;
        if ((char)local_2b0 != '\0') {
          iVar4 = 5;
        }
        if (DAT_180052eb8 == 0) {
          ppiVar25 = &local_2b0;
          if (iVar4 != 5) {
            ppiVar25 = (int **)local_2a0;
          }
          FUN_18001a710(iVar4,(char *)((longlong)&uStack_259 + 1),(char *)ppiVar25,0);
        }
        iVar19 = *(int *)(uVar10 + 0x28 + (longlong)param_2);
        if (iVar19 == 0) {
          lVar23 = 0;
        }
        else {
          lVar23 = (longlong)param_2 + uVar10 + 0x2c;
        }
        FUN_18001f000(iVar4,(char *)&local_2b0,(char *)((longlong)&uStack_259 + 1),iVar26,lVar23,
                      iVar19,(char *)local_2a0,0);
        DAT_180052eb8 = iVar5;
      }
      else if ((iVar4 + 0x1aU & 0xfffffffd) == 0) {
        uVar10 = (ulonglong)param_2[5];
        iVar5 = param_2[3];
        iVar26 = param_2[4];
        strncpy((char *)((longlong)&uStack_259 + 1),(char *)(param_2 + 6),uVar10);
        if (0x4f < uVar10) {
LAB_18002f538:
                    /* WARNING: Subroutine does not return */
          FUN_18003b6e4();
        }
        auStack_209[uVar10 - 0x4f] = 0;
        if (DAT_180052ebc == 0) {
          FUN_18001a710(-0x14 - iVar4,(char *)((longlong)&uStack_259 + 1),(char *)0x0,0);
        }
        iVar19 = *(int *)(uVar10 + 0x18 + (longlong)param_2);
        lVar23 = (longlong)param_2 + uVar10 + 0x1c;
        if (iVar19 == 0) {
          lVar23 = 0;
        }
        FUN_18001f000(-0x14 - iVar4,(char *)0x0,(char *)((longlong)&uStack_259 + 1),iVar26,lVar23,
                      iVar19,(char *)0x0,0);
        DAT_180052ebc = iVar5;
      }
      else if (iVar4 == -0x1b) {
        iVar5 = param_2[3];
        uVar10 = (ulonglong)iVar5;
        if (iVar5 != 0) {
          strncpy((char *)((longlong)&uStack_259 + 1),(char *)(param_2 + 4),uVar10);
          if (0x4f < uVar10) goto LAB_18002f538;
          auStack_209[uVar10 - 0x4f] = 0;
        }
        pcVar9 = (char *)((longlong)&uStack_259 + 1);
        if (iVar5 == 0) {
          pcVar9 = (char *)0x0;
        }
        FUN_180008650(pcVar9);
      }
      else if (iVar4 == -0x1c) {
        iVar5 = param_2[5];
        pcVar9 = FUN_18002f550((char *)((longlong)&uStack_259 + 1),(longlong)(param_2 + 3));
        SimEnablePFSBlock((LPARAM)pcVar9,iVar5);
      }
      else if ((iVar4 + 0x20U < 2) &&
              (((cVar6 = clock(), _DAT_180050df0 <= (double)((cVar6 - _DAT_180052ea0) / 1000) ||
                (DAT_180050dec == 0)) || (param_2[2] == -0x1f)))) {
        SyncDataShareIn();
        FUN_1800072a0();
        _DAT_180052ea0 = clock();
      }
      goto LAB_18002f4e9;
    }
    goto LAB_18002f069;
  }
  hide_mouse();
  thunk_FUN_180008f30("");
  if ((*(int *)(*(longlong *)topfinfo_exref + 0x380) == 0x1b) || (*(int *)sbcanned_exref != 0)) {
    uVar8 = 0x1ab;
LAB_18002e6c6:
    pcVar9 = (char *)GetSorResStringEx(uVar8);
    FUN_180008f30(pcVar9);
  }
  else if (*(int *)(*(longlong *)topfinfo_exref + 0x380) == 9) {
    uVar8 = 0x1ac;
    goto LAB_18002e6c6;
  }
  show_mouse();
LAB_18002f4e9:
  *(undefined4 *)not_in_aspmsg_exref = 1;
  return;
}

/* RVA 0x2f550 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char * FUN_18002f550(char *param_1,longlong param_2)

{
  char *pcVar1;
  char cVar2;
  longlong lVar3;
  char *pcVar4;
  
  pcVar4 = &DAT_180053860;
  do {
    cVar2 = *pcVar4;
    (param_1 + -0x180053860)[(longlong)pcVar4] = cVar2;
    pcVar4 = pcVar4 + 1;
  } while (cVar2 != '\0');
  if (*param_1 != '\0') {
    pcVar4 = param_1 + -1;
    do {
      pcVar1 = pcVar4 + 1;
      pcVar4 = pcVar4 + 1;
    } while (*pcVar1 != '\0');
    *(undefined2 *)pcVar4 = _DAT_18003fa80;
  }
  pcVar4 = param_1 + -1;
  do {
    pcVar1 = pcVar4 + 1;
    pcVar4 = pcVar4 + 1;
  } while (*pcVar1 != '\0');
  lVar3 = 0;
  do {
    cVar2 = *(char *)(param_2 + lVar3);
    pcVar4[lVar3] = cVar2;
    lVar3 = lVar3 + 1;
  } while (cVar2 != '\0');
  pcVar4 = strchr(param_1,0x20);
  if (pcVar4 != (char *)0x0) {
    *pcVar4 = '\0';
  }
  return param_1;
}

/* RVA 0x2f5f0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool FUN_18002f5f0(longlong param_1)

{
  int iVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  bool bVar5;
  undefined1 auStack_48 [44];
  uint local_1c;
  uint local_18;
  uint local_14;
  ulonglong local_10;
  
  local_10 = DAT_1800516d8 ^ (ulonglong)auStack_48;
  DAT_180052e90 = 0;
  iVar1 = _guard_check_icall();
  if (iVar1 == 0) {
    uVar4 = (ulonglong)local_1c * (ulonglong)local_18 * (ulonglong)local_14;
    if (uVar4 < 0x2625a1) {
      uVar3 = (ulonglong)DAT_180050de8;
      if (uVar4 < uVar3) {
        do {
          if ((int)uVar3 < 0x7a121) {
            uVar3 = 0xffffffff;
          }
          else {
            uVar3 = (ulonglong)((int)uVar3 - 500000);
          }
          DAT_180050de8 = (int)uVar3;
        } while (uVar4 < (ulonglong)(longlong)DAT_180050de8);
        uVar2 = new_dialog();
        iVar1 = define_dialog_box(uVar2,"spacelow");
        if (iVar1 == 0) {
          bVar5 = false;
        }
        else {
          if (param_1 != 0) {
            FUN_180031430();
          }
          hide_mouse();
          push_mouse_mask(0);
          open_dialog_box(uVar2,0,0);
          show_mouse();
          iVar1 = drive_dialog(uVar2);
          if ((iVar1 == 0) || (param_1 == 0)) {
            bVar5 = iVar1 != 0;
            hide_mouse();
            pop_mouse_mask();
            show_mouse();
            if (param_1 != 0) {
              FUN_180031470();
            }
          }
          else {
            *(undefined4 *)(param_1 + 8) = 1;
            hide_mouse();
            pop_mouse_mask();
            show_mouse();
            FUN_180031470();
            bVar5 = true;
          }
        }
        return bVar5;
      }
    }
    else {
      DAT_180050de8 = 2000000;
    }
  }
  return false;
}

/* RVA 0x2f750 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_18002f750(char *param_1)

{
  longlong lVar1;
  int iVar2;
  char *pcVar3;
  longlong lVar5;
  longlong lVar4;
  undefined1 auStackY_1c8 [32];
  undefined8 local_198;
  undefined8 local_190;
  undefined8 local_188;
  undefined8 uStack_180;
  char local_178 [272];
  char local_68 [73];
  undefined1 local_1f;
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStackY_1c8;
  thunk_FUN_180008f30("");
  pcVar3 = (char *)GetSorResStringEx(0x1b5);
  FUN_180008f30(pcVar3);
  if (param_1 == (char *)0x0) {
    local_198 = *(undefined8 *)(*(longlong *)finfo_exref + 0x698);
    local_190 = *(undefined8 *)(*(longlong *)finfo_exref + 0x690);
    local_188 = 0;
    uStack_180 = 0;
    HYdspnam(&local_198,&local_188,local_68,0x41);
    FUN_1800194c0(0);
  }
  else {
    strncpy(local_68,param_1,0x4a);
    local_1f = 0;
  }
  MDclrmsg(*(undefined8 *)(*(longlong *)finfo_exref + 0x168));
  lVar5 = -1;
  do {
    lVar4 = lVar5 + 1;
    lVar1 = lVar5 + 1;
    lVar5 = lVar4;
  } while (local_68[lVar1] != '\0');
  iVar2 = FUN_180030240((char *)0x0,local_178,0,(longlong)(int)((int)lVar4 * 0x10000 | 0x2b00ff00),
                        local_68);
  if (iVar2 == 1) {
    if (param_1 == (char *)0x0) {
      FUN_18002fe10();
    }
    pcVar3 = (char *)GetSorResStringEx(0x791);
    thunk_FUN_180008f30(pcVar3);
    iVar2 = 0;
  }
  else if (iVar2 < 1) {
    iVar2 = -1;
  }
  return iVar2;
}

/* RVA 0x2f8b0 */
void FUN_18002f8b0(void)

{
  FUN_180019fe0(0xfffffffe,(undefined8 *)0x0,(longlong *)0x0,(uint *)0x0,(uint *)0x0);
  return;
}

/* RVA 0x2f8e0 */
int FUN_18002f8e0(longlong param_1)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  longlong lVar4;
  undefined **ppuVar5;
  int iVar6;
  
  ppuVar5 = &PTR_s_HIERARCHY_180050e00;
  iVar6 = 0;
  do {
    pcVar3 = *ppuVar5;
    if (*pcVar3 != '\0') {
      lVar4 = param_1 - (longlong)pcVar3;
      do {
        cVar1 = *pcVar3;
        cVar2 = pcVar3[lVar4];
        if (cVar1 != cVar2) break;
        pcVar3 = pcVar3 + 1;
      } while (cVar2 != '\0');
      if (cVar1 == cVar2) {
        return iVar6 + -1;
      }
    }
    iVar6 = iVar6 + 1;
    ppuVar5 = ppuVar5 + 1;
    if (0x180050e87 < (longlong)ppuVar5) {
      return 0;
    }
  } while( true );
}

/* RVA 0x2f950 */
ulonglong FUN_18002f950(int param_1,int param_2,ulonglong param_3)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  
  uVar3 = param_3 >> (('\x03' - (char)param_2) * '\b' & 0x3fU);
  uVar4 = uVar3 & 0xff;
  if ((param_1 == 0x13) && (param_2 == 1)) {
    return uVar4;
  }
  uVar2 = (uint)uVar4 & 0x7f;
  uVar1 = -uVar2;
  if ((uVar3 & 0x80) == 0) {
    uVar1 = uVar2;
  }
  return (ulonglong)uVar1;
}

/* RVA 0x2f990 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int SBsetscp(char *param_1)

{
  char cVar1;
  char cVar2;
  longlong lVar3;
  int iVar4;
  longlong lVar5;
  longlong lVar6;
  undefined8 uVar7;
  char *pcVar8;
  ulonglong uVar9;
  undefined1 auStackY_1c8 [32];
  undefined8 local_198;
  undefined8 local_190;
  undefined8 local_188;
  undefined8 uStack_180;
  char local_178 [272];
  char local_68 [64];
  undefined1 local_28;
  ulonglong local_18;
  
                    /* 0x2f990  188  SBsetscp */
  local_18 = DAT_1800516d8 ^ (ulonglong)auStackY_1c8;
  if (param_1 == (char *)0x0) {
    local_198 = *(undefined8 *)(*(longlong *)finfo_exref + 0x698);
    local_190 = *(undefined8 *)(*(longlong *)finfo_exref + 0x690);
    local_188 = 0;
    uStack_180 = 0;
    HYdspnam(&local_198,&local_188,local_68,0x41);
  }
  else {
    strncpy(local_68,param_1,0x41);
    local_28 = 0;
  }
  iVar4 = GRinqiap();
  if ((iVar4 == 1) && (iVar4 = GRinqcnn(), iVar4 == 2)) {
    iVar4 = GRqryscp();
    if (iVar4 == 0) {
      lVar5 = GRinqscp();
      if (lVar5 == 0) {
        if (local_68[0] == '\0') {
          return 1;
        }
      }
      else if (local_68[0] != '\0') {
        pcVar8 = local_68;
        lVar5 = lVar5 - (longlong)pcVar8;
        do {
          cVar1 = *pcVar8;
          cVar2 = pcVar8[lVar5];
          if (cVar1 != cVar2) break;
          pcVar8 = pcVar8 + 1;
        } while (cVar2 != '\0');
        if (cVar1 == cVar2) {
          return 1;
        }
      }
    }
    lVar5 = -1;
    do {
      lVar6 = lVar5 + 1;
      lVar3 = lVar5 + 1;
      lVar5 = lVar6;
    } while (local_68[lVar3] != '\0');
    uVar9 = (ulonglong)(int)((int)lVar6 * 0x10000 | 0x2700ff00);
    iVar4 = FUN_180030240((char *)0x0,local_178,0,uVar9,local_68);
    if (iVar4 != 1) {
      if (iVar4 < 1) {
        uVar7 = GetSorResStringEx(0x1ae);
        FUN_180008f80(&DAT_180052d90,&DAT_18003f9ac,uVar7,uVar9);
        FUN_180028530(&DAT_180052d90,-1);
        return -1;
      }
      return iVar4;
    }
    GRsetscp(local_68);
    GRrstscp(0);
  }
  return 0;
}

/* RVA 0x2fb80 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_18002fb80(void)

{
  undefined8 uVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  int iVar9;
  undefined1 auStackY_188 [32];
  char local_128 [272];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStackY_188;
  FUN_180016340(0,1);
  iVar9 = FUN_180030240((char *)0x0,local_128,0,0x1c000000,(char *)0x0);
  if (iVar9 != -1) {
    lVar3 = *(longlong *)topfinfo_exref;
    uVar5 = *(undefined8 *)(lVar3 + 0x5a0);
    uVar6 = *(undefined8 *)(lVar3 + 0x5a8);
    uVar4 = *(undefined8 *)(lVar3 + 0x5d0);
    uVar1 = *(undefined8 *)(lVar3 + 0x5b0);
    uVar7 = *(undefined8 *)(lVar3 + 0x5b8);
    uVar8 = *(undefined8 *)(lVar3 + 0x5c0);
    uVar2 = *(undefined8 *)(lVar3 + 0x5c8);
    hide_mouse();
    HYloohie(&DAT_18003ae52);
    lVar3 = *(longlong *)topfinfo_exref;
    *(undefined8 *)(lVar3 + 0x5a0) = uVar5;
    *(undefined8 *)(lVar3 + 0x5a8) = uVar6;
    *(undefined8 *)(lVar3 + 0x5b0) = uVar1;
    lVar3 = *(longlong *)topfinfo_exref;
    *(undefined8 *)(lVar3 + 0x5b8) = uVar7;
    *(undefined8 *)(lVar3 + 0x5c0) = uVar8;
    *(undefined8 *)(lVar3 + 0x5c8) = uVar2;
    *(undefined8 *)(*(longlong *)topfinfo_exref + 0x5d0) = uVar4;
    show_mouse();
  }
  FUN_180016010(0,1);
  return iVar9;
}

/* RVA 0x2fcc0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_18002fcc0(char *param_1)

{
  longlong lVar1;
  int iVar2;
  char *pcVar3;
  longlong lVar5;
  longlong lVar4;
  undefined1 auStackY_1c8 [32];
  undefined8 local_198;
  undefined8 local_190;
  undefined8 local_188;
  undefined8 uStack_180;
  char local_178 [272];
  char local_68 [64];
  undefined1 local_28;
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStackY_1c8;
  thunk_FUN_180008f30("");
  pcVar3 = (char *)GetSorResStringEx(0x78f);
  FUN_180008f30(pcVar3);
  if (param_1 == (char *)0x0) {
    local_198 = *(undefined8 *)(*(longlong *)finfo_exref + 0x698);
    local_190 = *(undefined8 *)(*(longlong *)finfo_exref + 0x690);
    local_188 = 0;
    uStack_180 = 0;
    HYdspnam(&local_198,&local_188,local_68,0x41);
  }
  else {
    strncpy(local_68,param_1,0x41);
    local_28 = 0;
  }
  MDclrmsg(*(undefined8 *)(*(longlong *)finfo_exref + 0x168));
  lVar5 = -1;
  do {
    lVar4 = lVar5 + 1;
    lVar1 = lVar5 + 1;
    lVar5 = lVar4;
  } while (local_68[lVar1] != '\0');
  iVar2 = FUN_180030240((char *)0x0,local_178,0,(longlong)(int)((int)lVar4 << 0x10 | 0x2900ff00),
                        local_68);
  if (iVar2 == 1) {
    pcVar3 = (char *)GetSorResStringEx(0x790);
    thunk_FUN_180008f30(pcVar3);
    iVar2 = 2;
  }
  else if (iVar2 < 1) {
    iVar2 = -1;
  }
  return iVar2;
}

/* RVA 0x2fe10 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_18002fe10(void)

{
  code cVar1;
  char cVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  longlong lVar7;
  longlong lVar6;
  ulonglong uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  longlong lVar11;
  code *pcVar12;
  undefined4 *puVar13;
  char *pcVar14;
  undefined *puVar15;
  uint uVar16;
  undefined1 *puVar17;
  ulonglong uVar18;
  undefined1 auStack_288 [32];
  int *local_268;
  int local_258 [4];
  undefined1 local_248 [4];
  undefined4 local_244;
  int local_240;
  int local_23c;
  int local_238;
  int local_234 [63];
  char local_138 [8];
  uint local_130;
  int local_128;
  undefined4 uStack_29;
  undefined1 local_24 [20];
  ulonglong local_10;
  
  local_10 = DAT_1800516d8 ^ (ulonglong)auStack_288;
  piVar5 = (int *)SEGetSettingValue("dcomconnect",0);
  if ((((piVar5 == (int *)0x0) || (*piVar5 == 0)) ||
      ((iVar4 = GRinqiap(), iVar4 == 0 &&
       ((iVar4 = GRinqcnn(), iVar4 != 1 && (iVar4 = GRinqcnn(), iVar4 != 2)))))) ||
     (iVar4 = GRinqerr(), iVar4 != 0)) {
    local_258[0] = 1;
  }
  else {
    iVar4 = SBlocalhost();
    uVar16 = 0x280000ff;
    if (iVar4 == 0) {
      uVar16 = 0x280100ff;
    }
    pcVar12 = APtmpfil_exref;
    do {
      cVar1 = *pcVar12;
      pcVar12[(longlong)(local_24 + (-4 - (longlong)APtmpfil_exref))] = cVar1;
      pcVar12 = pcVar12 + 1;
    } while (cVar1 != (code)0x0);
    puVar3 = &uStack_29;
    do {
      puVar13 = puVar3;
      puVar3 = (undefined4 *)((longlong)puVar13 + 1);
    } while (*(char *)((longlong)puVar13 + 1) != '\0');
    *(undefined4 *)((longlong)puVar13 + 1) = DAT_18004211c;
    *(undefined1 *)((longlong)puVar13 + 5) = DAT_180042120;
    lVar7 = -1;
    do {
      lVar6 = lVar7 + 1;
      lVar11 = lVar7 + -3;
      lVar7 = lVar6;
    } while (local_24[lVar11] != '\0');
    memset(local_248,0,0x110);
    uVar18 = (ulonglong)(int)(uVar16 | (int)lVar6 * 0x100);
    local_244 = 1;
    uVar8 = FUN_18002f950(0,0,uVar18);
    iVar4 = (int)uVar8;
    if (iVar4 == -0x7f) {
      pcVar14 = (char *)((longlong)&uStack_29 + 1);
      do {
        cVar2 = *pcVar14;
        pcVar14[-0x218] = cVar2;
        pcVar14 = pcVar14 + 1;
      } while (cVar2 != '\0');
    }
    else {
      local_240 = iVar4;
    }
    uVar8 = FUN_18002f950(iVar4,1,uVar18);
    iVar4 = (int)uVar8;
    if (iVar4 == -0x7f) {
      pcVar14 = (char *)((longlong)&uStack_29 + 1);
      do {
        cVar2 = *pcVar14;
        pcVar14[-0x214] = cVar2;
        pcVar14 = pcVar14 + 1;
      } while (cVar2 != '\0');
    }
    else {
      local_23c = iVar4;
    }
    uVar8 = FUN_18002f950(iVar4,2,uVar18);
    iVar4 = (int)uVar8;
    if (iVar4 == -0x7f) {
      pcVar14 = (char *)((longlong)&uStack_29 + 1);
      do {
        cVar2 = *pcVar14;
        pcVar14[-0x210] = cVar2;
        pcVar14 = pcVar14 + 1;
      } while (cVar2 != '\0');
    }
    else {
      local_238 = iVar4;
    }
    uVar8 = FUN_18002f950(iVar4,3,uVar18);
    if ((int)uVar8 == -0x7f) {
      pcVar14 = (char *)((longlong)&uStack_29 + 1);
      do {
        cVar2 = *pcVar14;
        pcVar14[-0x20c] = cVar2;
        pcVar14 = pcVar14 + 1;
      } while (cVar2 != '\0');
    }
    else {
      local_234[0] = (int)uVar8;
    }
    SyncDataShareOut();
    local_268 = local_258;
    pcVar14 = local_138;
    puVar17 = local_248;
    puVar15 = &DAT_180050dfc;
    SEND_MESSAGE_WAIT(&DAT_1800521b4);
    SyncDataShareIn();
    if (local_258[0] < 1) {
      GRsetust(0);
      GRsetiap(0);
      GRsetsme();
      FUN_180021b60(0);
      GRsetgpd(0);
      DAT_180052e9c = 0;
      lVar7 = *(longlong *)topfinfo_exref;
      *(undefined4 *)(lVar7 + 0x438) = 0xffffffff;
      FUN_18002a3a0(lVar7,puVar15,puVar17,pcVar14);
      GRnxtact();
    }
    else {
      local_130 = (local_130 ^ (int)local_130 >> 0x1f) - ((int)local_130 >> 0x1f);
      if (local_258[0] == 1) {
        if (local_128 == 0) {
          uVar9 = FUN_180013800();
          if ((int)uVar9 == 0) {
            FUN_1800187d0();
            return 0;
          }
          iVar4 = EOInqError();
          if (iVar4 != 0) {
            uVar9 = EOGetError();
            STerrbox(uVar9,1);
            return 1;
          }
          uVar9 = GetSorResStringEx(0x1b0);
          uVar10 = GetSorResStringEx(0x1b1);
          FUN_180008f80(&DAT_180052d90,"%s\n%s",uVar10,uVar9);
        }
        else {
          uVar9 = GetSorResStringEx(0x1b3);
          uVar10 = GetSorResStringEx(0x1b2);
          FUN_180008f80(&DAT_180052d90,"%s\n%s",uVar10,uVar9);
          lVar7 = -1;
          do {
            lVar11 = lVar7;
            lVar7 = lVar11 + 1;
          } while ((&DAT_180052d91)[lVar11] != '\0');
          Ordinal_83(&DAT_180052d91 + lVar11,0x100 - (int)(lVar11 + 1),local_128);
        }
        FUN_180028530(&DAT_180052d90,-1);
        local_258[0] = -1;
      }
      else {
        uVar9 = GetSorResStringEx(0x1b4);
        uVar10 = GetSorResStringEx(0x1b1);
        FUN_180008f80(&DAT_180052d90,"%s\n%s",uVar10,uVar9);
        FUN_180028530(&DAT_180052d90,-1);
        local_258[0] = -1;
      }
    }
  }
  return local_258[0];
}

/* RVA 0x30240 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_180030240(char *param_1,char *param_2,int param_3,ulonglong param_4,char *param_5)

{
  char cVar1;
  code cVar2;
  longlong lVar3;
  int iVar4;
  ulonglong uVar5;
  longlong lVar6;
  longlong lVar7;
  int *piVar8;
  undefined8 uVar9;
  char *pcVar10;
  char *pcVar11;
  code *pcVar12;
  uint uVar13;
  uint *puVar14;
  code *pcVar15;
  size_t _MaxCount;
  int iVar16;
  undefined4 *puVar17;
  undefined8 uVar18;
  undefined1 auStack_8c8 [32];
  int *local_8a8;
  int local_898;
  int local_894;
  uint local_890;
  int local_88c;
  char *local_888;
  undefined4 local_878;
  undefined4 local_874;
  uint local_870 [3];
  char local_864 [252];
  char local_768 [80];
  char local_718 [208];
  char local_648 [8];
  char local_640 [4];
  char local_63c [516];
  undefined1 local_438 [1008];
  ulonglong local_48;
  
  local_48 = DAT_1800516d8 ^ (ulonglong)auStack_8c8;
  local_898 = 0;
  local_890 = 1;
  local_648 = (char  [8])s_SEND_MESSAGE__180042ef8._0_8_;
  DAT_180052e9c = (uint)((param_4 & 0xff000000) == 0x1b000000);
  local_640 = (char  [4])s_SEND_MESSAGE__180042ef8._8_4_;
  local_63c._0_2_ = s_SEND_MESSAGE__180042ef8._12_2_;
  local_88c = param_3;
  local_888 = param_1;
  memset(&local_878,0,0x110);
  uVar13 = 0;
  local_874 = 1;
  iVar16 = 0;
  puVar14 = local_870;
  do {
    uVar5 = FUN_18002f950(uVar13,iVar16,param_4);
    uVar13 = (uint)uVar5;
    if (uVar13 == 0) break;
    if ((param_5 == (char *)0x0) || (uVar13 != 0xffffff81)) {
      *puVar14 = uVar13;
      FUN_180008f80(local_648,"%s %d",local_648,uVar5 & 0xffffffff);
    }
    else {
      pcVar10 = param_5;
      do {
        cVar1 = *pcVar10;
        pcVar10[(longlong)local_870 + ((longlong)iVar16 * 4 - (longlong)param_5)] = cVar1;
        pcVar10 = pcVar10 + 1;
      } while (cVar1 != '\0');
      FUN_180008f80(local_648,"%s %s",local_648,param_5);
    }
    iVar16 = iVar16 + 1;
    puVar14 = puVar14 + 1;
  } while (iVar16 < 4);
  pcVar10 = local_888;
  if (local_888 != (char *)0x0) {
    FUN_1800281c0(local_888);
  }
  _MaxCount = 0xffffffffffffffff;
LAB_1800303ae:
  iVar16 = GRinqcnn();
  if (iVar16 == 1) {
    if ((0x28 < local_870[0]) ||
       ((0x10400006100U >> ((longlong)(int)local_870[0] & 0x3fU) & 1) == 0)) {
      uVar18 = 0x6c6;
LAB_1800303dd:
      FUN_180008f80(local_438,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\sor\\sbsim\\sbxctiap.c",uVar18);
      LogMessage(local_438,2,1);
      return -1;
    }
  }
  else {
    iVar16 = GRinqcnn();
    if ((iVar16 == 3) && ((0x18 < local_870[0] || ((0x1406100U >> (local_870[0] & 0x1f) & 1) == 0)))
       ) {
      uVar18 = 0x6d4;
      goto LAB_1800303dd;
    }
  }
  DAT_180050dec = 1;
  if (((local_870[0] < 0x13) && ((0x48820U >> (local_870[0] & 0x1f) & 1) != 0)) ||
     (local_870[0] - 0x1f < 3)) {
    DAT_180051ff4 = 1;
    DAT_180050dec = (uint)(local_870[0] != 0x12);
    _DAT_180052ea0 = clock();
  }
  iVar16 = local_88c;
  if (((local_88c == 0) || (*(int *)sbcanned_exref != 0)) ||
     (*(int *)(*(longlong *)topfinfo_exref + 0x380) != 1)) {
    _guard_check_icall();
  }
  else {
    FUN_180031470();
  }
  if (*(int *)debug_flag_exref != 0) {
    FUN_1800282b0(local_648);
  }
  if (DAT_180050de4 != 0) {
    hide_mouse();
    thunk_FUN_180008f30("");
    show_mouse();
  }
  SyncDataShareOut();
  local_8a8 = &local_898;
  puVar17 = &local_878;
  puVar14 = &local_890;
  pcVar11 = param_2;
  SEND_MESSAGE_WAIT();
  SyncDataShareIn();
  if (pcVar10 != (char *)0x0) {
    FUN_1800281c0((char *)0x0);
  }
  if (((iVar16 == 0) || (*(int *)sbcanned_exref != 0)) ||
     (*(int *)(*(longlong *)topfinfo_exref + 0x380) != 1)) {
    _guard_check_icall();
  }
  else {
    iVar16 = GRinqssu();
    if (iVar16 != 0) {
      FUN_180031430();
    }
  }
  if (local_898 < 1) {
    GRsetust(0);
    GRsetiap(0);
    GRsetsme();
    FUN_180021b60(0);
    GRsetgpd(0);
    DAT_180052e9c = 0;
    lVar7 = *(longlong *)topfinfo_exref;
    *(undefined4 *)(lVar7 + 0x438) = 0xffffffff;
    FUN_18002a3a0(lVar7,puVar14,puVar17,pcVar11);
    GRnxtact();
    return local_898;
  }
  GRsetcnn((*(int *)(param_2 + 8) >> 0x1f & 1U) + 2);
  uVar13 = (int)*(uint *)(param_2 + 8) >> 0x1f;
  iVar16 = (*(uint *)(param_2 + 8) ^ uVar13) - uVar13;
  *(int *)(param_2 + 8) = iVar16;
  switch(iVar16) {
  case 1:
    if (DAT_180050de4 == 0) {
      DAT_180052e9c = 0;
      return local_898;
    }
    GRsetrpx(0);
    GRsetiap(1);
    cVar1 = param_2[0x14];
    iVar16 = (int)cVar1;
    param_2[0x14] = '\0';
    pcVar10 = FUN_18002f550(local_718,(longlong)(param_2 + 0xc));
    param_2[0x14] = cVar1;
    lVar7 = GRinqexc();
    if (lVar7 == 0) {
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
      lVar7 = 0;
      do {
        cVar2 = (code)pcVar10[lVar7];
        pcVar12[lVar7] = cVar2;
        lVar7 = lVar7 + 1;
      } while (cVar2 != (code)0x0);
      SBsetnxt(pcVar10,iVar16);
      DAT_180052e9c = 0;
      return local_898;
    }
    pcVar11 = (char *)GRinqnxt();
    if (pcVar11 != (char *)0x0) goto LAB_180030690;
    goto LAB_180030736;
  case 3:
    if (DAT_180050de4 == 0) {
      DAT_180052e9c = 0;
      return local_898;
    }
    if (*(int *)(param_2 + 0xc) == 5) {
      param_2[0xc] = '\x01';
      param_2[0xd] = '\0';
      param_2[0xe] = '\0';
      param_2[0xf] = '\0';
    }
  case 2:
    if (DAT_180050de4 != 0) {
      GRsetrpx(0);
      GRsetrst(*(undefined4 *)(param_2 + 0xc));
      if (*(int *)(*(longlong *)topfinfo_exref + 0x380) == 1) {
        GRsetiap2();
        lVar7 = GRinqexc();
        if ((lVar7 != 0) && (lVar7 = GRinqnxt(), lVar7 != 0)) {
          GRsetexc();
          *(uint *)Sactions_exref = *(uint *)Sactions_exref & 0xffefffff;
        }
        SBsetnxt((char *)0x0,0);
        lVar7 = GRinqexc();
        if (lVar7 == 0) {
          if (DAT_180052e9c == 0) {
            iVar16 = GRinqpgc();
            if (iVar16 == 0) {
              GRsetsmf(1);
            }
            iVar16 = GRinqsmstrat();
            GRsetmtf(iVar16 == 1);
          }
          if (*(int *)sbcanned_exref == 0) {
            if (*(int *)bestinput_exref == 0) {
              pcVar12 = (code *)GetSorResStringEx(0x78c);
              pcVar15 = dbxbuf_exref;
              do {
                cVar2 = *pcVar12;
                pcVar12 = pcVar12 + 1;
                *pcVar15 = cVar2;
                pcVar15 = pcVar15 + 1;
              } while (cVar2 != (code)0x0);
            }
            else {
              iVar16 = GRinqcmp();
              if (iVar16 == 1) {
                pcVar12 = (code *)GetSorResStringEx(0x78c);
                pcVar15 = dbxbuf_exref;
                do {
                  cVar2 = *pcVar12;
                  pcVar12 = pcVar12 + 1;
                  *pcVar15 = cVar2;
                  pcVar15 = pcVar15 + 1;
                } while (cVar2 != (code)0x0);
              }
              else {
                pcVar12 = (code *)GetSorResStringEx(0x78b);
                pcVar15 = dbxbuf_exref;
                do {
                  cVar2 = *pcVar12;
                  pcVar12 = pcVar12 + 1;
                  *pcVar15 = cVar2;
                  pcVar15 = pcVar15 + 1;
                } while (cVar2 != (code)0x0);
              }
            }
          }
          else {
            pcVar12 = (code *)GetSorResStringEx(0x78d);
            pcVar15 = dbxbuf_exref;
            do {
              cVar2 = *pcVar12;
              pcVar12 = pcVar12 + 1;
              *pcVar15 = cVar2;
              pcVar15 = pcVar15 + 1;
            } while (cVar2 != (code)0x0);
          }
        }
        else {
          pcVar10 = (char *)GRinqexc();
          lVar7 = -(longlong)pcVar10;
          do {
            cVar1 = *pcVar10;
            pcVar10[(longlong)(local_768 + lVar7)] = cVar1;
            pcVar10 = pcVar10 + 1;
          } while (cVar1 != '\0');
          pcVar10 = strchr(local_768,0x20);
          if (pcVar10 != (char *)0x0) {
            *pcVar10 = '\0';
          }
          piVar8 = (int *)GetSorResStringEx(0x78a);
          uVar18 = GetSorResStringEx(0x789);
          local_8a8 = piVar8;
          FUN_180008f80(dbxbuf_exref,"%s %s %s",uVar18,local_768);
        }
      }
      else {
        if (*(int *)sbcanned_exref == 0) {
          GRsetgpd(0);
        }
        GRsetiap2();
        GRsetexc();
        SBsetnxt((char *)0x0,0);
        GRsetsmf(1);
        GRsetsms(0);
        if ((*(int *)sbcanned_exref == 0) && (*(int *)(*(longlong *)topfinfo_exref + 0x380) != 0x1b)
           ) {
          if (*(int *)bestinput_exref == 0) {
            pcVar12 = (code *)GetSorResStringEx(0x78c);
            pcVar15 = dbxbuf_exref;
            do {
              cVar2 = *pcVar12;
              pcVar12 = pcVar12 + 1;
              *pcVar15 = cVar2;
              pcVar15 = pcVar15 + 1;
            } while (cVar2 != (code)0x0);
          }
          else {
            iVar16 = GRinqcmp();
            if (iVar16 == 1) {
              pcVar12 = (code *)GetSorResStringEx(0x78c);
              pcVar15 = dbxbuf_exref;
              do {
                cVar2 = *pcVar12;
                pcVar12 = pcVar12 + 1;
                *pcVar15 = cVar2;
                pcVar15 = pcVar15 + 1;
              } while (cVar2 != (code)0x0);
            }
            else {
              pcVar12 = (code *)GetSorResStringEx(0x78b);
              pcVar15 = dbxbuf_exref;
              do {
                cVar2 = *pcVar12;
                pcVar12 = pcVar12 + 1;
                *pcVar15 = cVar2;
                pcVar15 = pcVar15 + 1;
              } while (cVar2 != (code)0x0);
            }
          }
        }
        else {
          pcVar12 = (code *)GetSorResStringEx(0x78d);
          pcVar15 = dbxbuf_exref;
          do {
            cVar2 = *pcVar12;
            pcVar12 = pcVar12 + 1;
            *pcVar15 = cVar2;
            pcVar15 = pcVar15 + 1;
          } while (cVar2 != (code)0x0);
        }
      }
LAB_180030b71:
      hide_mouse();
      thunk_FUN_180008f30((char *)dbxbuf_exref);
      show_mouse();
      DAT_180052e9c = 0;
      return local_898;
    }
    break;
  case 4:
    if (DAT_180050de4 == 0) {
      DAT_180052e9c = 0;
      return local_898;
    }
    GRsetrpx(0);
    GRsetiap(1);
    GRseterr();
    goto LAB_180030bbc;
  case 5:
    if (DAT_180050de4 == 0) {
      DAT_180052e9c = 0;
      return local_898;
    }
    DAT_180050de4 = 0;
    GRsetrpx(0);
    GRsetiap(1);
    cVar1 = param_2[0x14];
    param_2[0x14] = '\0';
    pcVar10 = FUN_18002f550(local_718,(longlong)(param_2 + 0xc));
    param_2[0x14] = cVar1;
    GRsetexc2(pcVar10,(int)cVar1);
    pcVar11 = FUN_180019cb0(&local_894);
    SBsetnxt(pcVar11,(int)cVar1);
    FUN_180026490();
    lVar7 = -(longlong)pcVar10;
    do {
      cVar1 = *pcVar10;
      pcVar10[(longlong)(local_768 + lVar7)] = cVar1;
      pcVar10 = pcVar10 + 1;
    } while (cVar1 != '\0');
    pcVar10 = strchr(local_768,0x20);
    if (pcVar10 != (char *)0x0) {
      *pcVar10 = '\0';
    }
    uVar18 = GetSorResStringEx(0x78a);
    uVar9 = GetSorResStringEx(0x789);
    local_8a8 = (int *)uVar18;
    FUN_180008f80(dbxbuf_exref,"%s %s %s",uVar9,local_768);
    hide_mouse();
    thunk_FUN_180008f30((char *)dbxbuf_exref);
    show_mouse();
    DAT_180050de4 = 1;
    DAT_180052e9c = 0;
    return local_898;
  case 6:
    GRsetrpx(0);
    GRsetiap(0);
    GRsetgpd(0);
    *(undefined4 *)(*(longlong *)topfinfo_exref + 0x438) = 0xffffffff;
    GRsetexc();
    SBsetnxt((char *)0x0,0);
    GRsetsmf(1);
    GRsetsms(0);
    if (*(int *)prop_retrieve_results_exref == 0) {
      OPpurout(*(undefined8 *)iwpfile_exref,0,1);
    }
    FUN_18002c620((longlong)APtmpfil_exref);
    iVar16 = *(int *)(param_2 + 0xc);
    if (iVar16 == 0) {
      param_2[0xc] = '\x01';
      param_2[0xd] = '\0';
      param_2[0xe] = '\0';
      param_2[0xf] = '\0';
      iVar16 = 1;
    }
    GRsetrst(iVar16);
    DAT_180052e9c = 0;
    return local_898;
  case 7:
    GRsetrpx(0);
    GRsetiap(0);
    if (DAT_180051e50 != 0) {
      hide_mouse();
      _guard_check_icall();
      thunk_FUN_180008f30("");
      show_mouse();
    }
    if ((DAT_180050de4 == 0) && (*(int *)in_canned_exref != 0)) {
      GRsetprp(4);
    }
    GRsetsms(0);
    GRsetsmf(0);
    GRsetgpd(0);
    *(undefined4 *)(*(longlong *)topfinfo_exref + 0x438) = 0xffffffff;
    GRsetedt();
    GRsetexc();
    SBsetnxt((char *)0x0,0);
    uVar18 = 1;
    goto LAB_180031172;
  case 8:
    GRsetiap(0);
    GRsetgpd(0);
    *(undefined4 *)(*(longlong *)topfinfo_exref + 0x438) = 0xffffffff;
    GRsetedt();
    GRsetexc();
    SBsetnxt((char *)0x0,0);
    if (DAT_180050de4 == 0) {
      DAT_180052e9c = 0;
      return local_898;
    }
    if (*(int *)in_canned_exref != 0) {
      GRsetprp(4);
    }
    GRseterr(2);
    DAT_180052e9c = 0;
    return local_898;
  case 10:
    GRsetpgc(1);
    GRsetiap(0);
    GRsetgpd(0);
    *(undefined4 *)(*(longlong *)topfinfo_exref + 0x438) = 0xffffffff;
    GRsetedt();
    GRsetexc();
    SBsetnxt((char *)0x0,0);
    GRsetust(0);
    GRsetist(1);
    DAT_180052e9c = 0;
    return -1;
  case 0xb:
    GRsetpgc(1);
    GRsetiap(1);
    GRsetust(0);
    GRsetist(1);
    DAT_180052e9c = 0;
    return local_898;
  case 0xd:
    GRsetrpx(0);
    if (((param_4 == 0x3040000) || (param_4 == 0x3030100)) || (param_4 == 0x3038100)) {
      GRsetiap();
    }
    else {
      GRsetiap(0);
      GRsetgpd(0);
      *(undefined4 *)(*(longlong *)topfinfo_exref + 0x438) = 0xffffffff;
      GRsetedt();
    }
    GRsetexc();
    SBsetnxt((char *)0x0,0);
    if (DAT_180050de4 != 0) {
      uVar18 = 3;
      goto LAB_180031172;
    }
    iVar16 = *(int *)in_canned_exref;
joined_r0x00018003115f:
    if (iVar16 != 0) {
      GRsetprp(4);
    }
    goto LAB_180031177;
  case 0xe:
    GRsetrpx(0);
    GRsetiap();
    GRsetexc();
    SBsetnxt((char *)0x0,0);
    if (DAT_180050de4 == 0) {
      DAT_180052e9c = 0;
      return local_898;
    }
    GRseterr(6);
    DAT_180052e9c = 0;
    return local_898;
  case 0xf:
    GRsetrpx(0);
    iVar16 = DAT_180050de4;
    DAT_180050de4 = 0;
    GRsetiap();
    if (param_2[0xc] == '\0') {
      SBsetnxt((char *)0x0,0);
      GRsetexc(0);
    }
    else {
      cVar1 = param_2[0x14];
      param_2[0x14] = '\0';
      pcVar10 = FUN_18002f550(local_718,(longlong)(param_2 + 0xc));
      pcVar11 = FUN_180019cb0(&local_894);
      SBsetnxt(pcVar11,(int)cVar1);
      param_2[0x14] = cVar1;
      FUN_180026490();
      GRsetexc2(pcVar10,(int)cVar1);
      pcVar12 = (code *)GetSorResStringEx(0x78e);
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
      lVar7 = 0;
      do {
        cVar2 = (code)pcVar10[lVar7];
        pcVar12[lVar7] = cVar2;
        lVar7 = lVar7 + 1;
      } while (cVar2 != (code)0x0);
      hide_mouse();
      thunk_FUN_180008f30((char *)dbxbuf_exref);
      show_mouse();
    }
    DAT_180050de4 = iVar16;
    if (iVar16 != 0) {
      GRseterr(5);
      DAT_180052e9c = 0;
      return local_898;
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
    if (DAT_180050de4 == 0) {
      iVar16 = *(int *)in_canned_exref;
      goto joined_r0x00018003115f;
    }
    uVar18 = 4;
LAB_180031172:
    GRseterr(uVar18);
LAB_180031177:
    if (*(int *)partial_results_exref != 0) {
      if (*(int *)(param_2 + 8) != 0x10) {
        local_8a8 = (int *)GetSorResStringEx(0x1ad);
        FUN_180008f80(dbxbuf_exref,"%c%c%s",0x5e,0x21);
        EXyesno(dbxbuf_exref,2,1);
      }
      if (DAT_180052e9c != 0) {
        DAT_180052e9c = 0;
        return -1;
      }
      if (*(int *)in_canned_exref == 0) {
        OPpurout(*(undefined8 *)iwpfile_exref,0,0);
        MDclrmsg(*(undefined8 *)(*(longlong *)topfinfo_exref + 0x168));
        MDloocmp(*(undefined8 *)(*(longlong *)topfinfo_exref + 0x168),0,0xac,
                 local_890 & 0xfe03a3ff | 0x8200);
        Ordinal_69();
        DAT_180052e9c = 0;
        return local_898;
      }
    }
    break;
  case 0x14:
    goto switchD_18003059d_caseD_14;
  case 0x16:
    if (DAT_180050de4 == 0) {
      DAT_180052e9c = 0;
      return local_898;
    }
    GRsetrpx(0);
    GRsetiap();
    GRsetexc();
    SBsetnxt((char *)0x0,0);
    pcVar12 = (code *)GetSorResStringEx(0x787);
    pcVar15 = dbxbuf_exref;
    do {
      cVar2 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      *pcVar15 = cVar2;
      pcVar15 = pcVar15 + 1;
    } while (cVar2 != (code)0x0);
    goto LAB_180030b71;
  case 0x17:
    if (DAT_180050de4 == 0) {
      DAT_180052e9c = 0;
      return local_898;
    }
    GRsetrpx(0);
    GRsetiap();
LAB_180030bbc:
    GRsetexc();
    SBsetnxt((char *)0x0,0);
    DAT_180052e9c = 0;
    return local_898;
  case -0x20:
  case -0x1f:
    SyncDataShareIn();
    FUN_1800072a0();
    DAT_180052e9c = 0;
    return local_898;
  default:
    GRsetrpx(0);
    DAT_180052e9c = 0;
    return local_898;
  case -0x1d:
  case 0x15:
    break;
  case -0x11:
    FUN_18003a630((int *)(param_2 + 8),(longlong)param_2,(longlong)&local_878,pcVar11);
    DAT_180052e9c = 0;
    return local_898;
  }
  DAT_180052e9c = 0;
  return local_898;
switchD_18003059d_caseD_14:
  local_718[0] = '\0';
  iVar16 = FUN_180014850((longlong)local_718,0x4f);
  if (iVar16 == 0) {
    local_718[0] = '\0';
  }
  local_878 = 0;
  local_894 = iVar16;
  memset(local_864,0,0xfc);
  local_874 = 1;
  local_870[0] = 0x23;
  lVar7 = -1;
  do {
    lVar6 = lVar7 + 1;
    lVar3 = lVar7 + 1;
    lVar7 = lVar6;
  } while (local_718[lVar3] != '\0');
  local_870[2] = (uint)lVar6;
  lVar7 = 0;
  do {
    pcVar11 = local_718 + lVar7;
    local_864[lVar7] = *pcVar11;
    lVar7 = lVar7 + 1;
    local_870[1] = iVar16;
  } while (*pcVar11 != '\0');
  goto LAB_1800303ae;
LAB_180030690:
  do {
    _MaxCount = _MaxCount + 1;
  } while (pcVar11[_MaxCount] != '\0');
  iVar4 = strncmp(pcVar11,pcVar10,_MaxCount);
  if (iVar4 == 0) {
    pcVar11 = (char *)GRinqexc();
    lVar7 = -(longlong)pcVar11;
    do {
      cVar1 = *pcVar11;
      pcVar11[(longlong)(local_768 + lVar7)] = cVar1;
      pcVar11 = pcVar11 + 1;
    } while (cVar1 != '\0');
    pcVar11 = strchr(local_768,0x20);
    if (pcVar11 != (char *)0x0) {
      *pcVar11 = '\0';
    }
    uVar18 = GetSorResStringEx(0x78a);
    uVar9 = GetSorResStringEx(0x789);
    local_8a8 = (int *)uVar18;
    FUN_180008f80(dbxbuf_exref,"%s %s %s",uVar9,local_768);
    SBsetnxt(pcVar10,iVar16);
  }
  else {
LAB_180030736:
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
    lVar7 = 0;
    do {
      cVar2 = (code)pcVar10[lVar7];
      pcVar12[lVar7] = cVar2;
      lVar7 = lVar7 + 1;
    } while (cVar2 != (code)0x0);
    SBsetnxt(pcVar10,iVar16);
  }
  DAT_180052e9c = 0;
  return local_898;
}

/* RVA 0x31430 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_180031430(void)

{
  _DAT_1800538b0 = 0;
  _DAT_180052ec0 = 0;
  _guard_check_icall();
  _DAT_180051f0c = 0;
  show_mouse();
  pop_mouse_mask();
  GRsetssu(0);
  return;
}

/* RVA 0x31470 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_180031470(void)

{
  bool bVar1;
  undefined7 extraout_var;
  undefined8 uVar2;
  
  _DAT_180051f0c = 2;
  _DAT_180052ec0 = 1;
  bVar1 = FUN_180025320();
  _guard_check_icall();
  uVar2 = 0;
  if ((int)CONCAT71(extraout_var,bVar1) == 0) {
    uVar2 = 0x16;
  }
  push_mouse_mask(uVar2);
  _DAT_1800538b0 = 0;
  show_mouse();
  GRsetssu(1);
  return;
}

/* RVA 0x314e0 */
void FUN_1800314e0(void)

{
  DAT_180051c10 = 1;
  if (*(int *)partial_results_exref == 0) {
    *(uint *)Sactions_exref = *(uint *)Sactions_exref | 0x1000000;
    return;
  }
  *(uint *)(Sactions_exref + 4) = *(uint *)(Sactions_exref + 4) | 0x10;
  return;
}

/* RVA 0x31510 */
bool FUN_180031510(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 >> 0x1f & 0x1f;
  uVar1 = param_1 + uVar2;
  return (*(uint *)(Sactions_exref + (longlong)((int)uVar1 >> 5) * 4) >>
          ((uVar1 & 0x1f) - uVar2 & 0x1f) & 1) != 0;
}

/* RVA 0x31540 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
FUN_180031540(undefined *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  code cVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  longlong lVar8;
  code *pcVar9;
  code *_Str1;
  char *pcVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  bool bVar17;
  bool bVar18;
  undefined1 auStack_2e8 [32];
  undefined8 local_2c8;
  uint local_2c0;
  int local_2bc;
  uint local_2b8;
  int local_2b4;
  int local_2b0;
  int local_2ac;
  int local_2a8;
  uint local_2a4;
  uint local_2a0;
  int local_29c;
  uint local_298;
  uint local_294;
  uint local_290;
  uint local_28c;
  int local_288;
  int local_284;
  int local_280;
  int local_27c;
  int local_278;
  int local_274;
  int local_270;
  uint local_26c;
  int local_268;
  code *local_260;
  uchar local_258 [272];
  undefined1 local_148 [272];
  ulonglong local_38;
  
  local_38 = DAT_1800516d8 ^ (ulonglong)auStack_2e8;
  bVar2 = false;
  uVar7 = 0;
  local_2a8 = 0;
  bVar3 = false;
  local_2b4 = 0;
  bVar4 = false;
  local_2a0 = 0;
  local_2ac = 0;
  local_290 = 0;
  local_294 = 0;
  local_28c = 0;
  local_288 = 0;
  local_280 = 0;
  local_2b0 = 0;
  local_278 = 0;
  local_29c = 0;
  local_298 = 0;
  local_2c0 = 0;
  local_2a4 = 0;
  local_27c = 0;
  local_270 = 0;
  if (DAT_180051c00 == 0x20) {
    return 1;
  }
  local_2c8 = 0;
  if (param_1 == (undefined *)0x0) {
    param_1 = Sactions_exref;
  }
  local_260 = (code *)param_1;
  iVar5 = GRinqerr();
  if (iVar5 == 1) {
    GRsetpgc(1);
  }
  if (*(int *)debug_flag_exref != 0) {
    FUN_1800282b0("Setting simulation command actions...");
  }
  iVar5 = GRinqcat();
  if (iVar5 != 0) {
    *(undefined8 *)param_1 = 0;
    return 0;
  }
  bVar17 = (*(int *)(*(longlong *)topfinfo_exref + 0x380) - 1U & 0xfffffffd) == 0;
  if ((DAT_180051c00 != 6) || (!bVar17)) {
    uVar11 = (uint)local_2c8;
  }
  else {
    if (*(int *)debug_flag_exref != 0) {
      FUN_1800282b0("Run IAP REINIT BLOCK");
    }
    local_2c8 = CONCAT44(local_2c8._4_4_,0x800000);
    *(ulonglong *)param_1 = local_2c8;
    uVar11 = 0x800000;
  }
  if (((*(int *)(*(longlong *)topfinfo_exref + 0x380) == 1) && (iVar5 = GRinqQRs(), iVar5 != 0)) &&
     (**(char **)topfinfo_exref != '\0')) {
    iVar5 = MVGetProductCode();
    pcVar10 = "%s.aprpdf";
    if (iVar5 != 2) {
      pcVar10 = "%s.appdf";
    }
    FUN_180008f80(local_258,pcVar10,*(undefined8 *)topfinfo_exref,param_4);
    name_lwr(local_258);
    pcVar9 = open_path_exref;
    do {
      cVar1 = *pcVar9;
      pcVar9[(longlong)(local_148 + -(longlong)open_path_exref)] = cVar1;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != (code)0x0);
    name_lwr(local_148);
    iVar5 = FUN_180026510(local_148,(char *)local_258);
    if (iVar5 != 0) {
      GRsetQRs(0);
    }
    GRsetgpd(iVar5 == 0);
  }
  bVar18 = DAT_180051c00 == 9;
  local_268 = *(int *)simulate_flag_exref;
  local_2b8 = (uint)bVar18;
  iVar5 = GRinqgpd();
  if ((iVar5 != 0) &&
     (((!bVar17 && (bVar18 == 0)) || (*(int *)(*(longlong *)topfinfo_exref + 0x380) == 3)))) {
    local_27c = 1;
    GRsetgpd(0);
  }
  if (DAT_180052ec4 == 0) {
    if (**(char **)topfinfo_exref != '\0') {
      iVar5 = _stricmp(*(char **)topfinfo_exref,(char *)APtmpfil_exref);
      bVar3 = false;
      if (iVar5 != 0) {
        bVar3 = true;
      }
    }
  }
  else {
    iVar5 = GRinqfop();
    if (iVar5 == 0) {
      uVar7 = 1;
      local_2a8 = 1;
      if (**(code **)topfinfo_exref != (code)0x0) {
        _Str1 = *(code **)topfinfo_exref;
        pcVar9 = APtmpfil_exref;
        goto LAB_180031808;
      }
    }
    else {
      pcVar9 = *(code **)topfinfo_exref;
      if (*pcVar9 != (code)0x0) {
        _Str1 = APtmpfil_exref;
LAB_180031808:
        iVar5 = _stricmp((char *)_Str1,(char *)pcVar9);
        if (iVar5 != 0) {
          bVar3 = true;
        }
      }
    }
  }
  iVar5 = GRinqgpd();
  if ((iVar5 == 0) || (iVar5 = 1, *(int *)(*(longlong *)topfinfo_exref + 0x660) != 0)) {
    iVar5 = 0;
  }
  local_2bc = iVar5;
  if (((DAT_180051c00 - 0x21 < 2) || (DAT_180051c00 == 0x27)) &&
     ((iVar6 = GRinqpgc(), iVar6 != 0 ||
      (((iVar6 = GRinqnec(), iVar6 == 0 || (DAT_180051c04 != 0)) || (iVar5 == 0)))))) {
    uVar16 = 1;
  }
  else {
    uVar16 = 0;
  }
  if (((DAT_180051c00 == 0x1f) && (iVar5 == 0)) || (local_26c = 0, DAT_180051c04 != 0)) {
    local_26c = 1;
  }
  local_26c = local_26c | uVar16;
  if (((DAT_180051c00 < 0x28) && ((0x8680000000U >> ((ulonglong)DAT_180051c00 & 0x3f) & 1) != 0)) &&
     (((iVar5 == 0 || (iVar6 = GRinqpgc(), iVar6 != 0)) &&
      ((iVar6 = GRinqnec(), iVar6 == 0 || (DAT_180051c04 != 0)))))) {
    local_274 = 1;
  }
  else {
    local_274 = 0;
  }
  if ((DAT_180051c00 == 1) || (((DAT_180051c00 == 5 && (bVar17)) || (local_274 != 0)))) {
    bVar2 = true;
  }
  if (((DAT_180051c00 != 0x1f) && (DAT_180051c00 != 0x22)) || (local_284 = 1, DAT_180051c10 == 0)) {
    local_284 = 0;
  }
  if ((((iVar5 == 0) || ((iVar5 = GRinqpgc(), iVar5 != 0 && (DAT_180051c00 != 0x1f)))) ||
      ((local_2b8 != 0 ||
       ((*(int *)(*(longlong *)topfinfo_exref + 0x660) != 0 || (iVar5 = GRinqcnn(), iVar5 == 3))))))
     || ((uVar16 = uVar7, bVar2 &&
         ((*(int *)(*(longlong *)topfinfo_exref + 0x450) != 0 && (iVar5 = GRinqnco(), iVar5 != 0))))
        )) {
    uVar13 = 1;
    if ((local_2bc != 0) &&
       (((*(int *)(*(longlong *)topfinfo_exref + 0x660) == 0 || (local_2b8 != 0)) &&
        (iVar5 = GRinqcnn(), iVar5 != 3)))) {
      iVar5 = GRinqpgc();
      uVar16 = 1;
      if ((iVar5 == 0) || (*(int *)(*(longlong *)topfinfo_exref + 0x1dc) != 0)) goto LAB_1800319f7;
    }
    GRsetcannedpdf(local_2b8);
    iVar5 = 0;
    local_2ac = 1;
    local_2bc = 0;
    uVar7 = 1;
    local_2a8 = 1;
    GRsetQRs(0);
    if (**(char **)topfinfo_exref != '\0') {
      _stricmp(*(char **)topfinfo_exref,(char *)APtmpfil_exref);
    }
  }
  else {
LAB_1800319f7:
    uVar13 = uVar16;
    if (((DAT_180052ec4 == 0) || (uVar7 != 0)) && ((bVar3 && ((bVar17 || (local_2b8 != 0)))))) {
      local_288 = 1;
    }
    iVar5 = local_2bc;
  }
  iVar6 = GRinqpgc();
  if ((iVar6 == 0) && (local_2b8 == 0)) {
    if ((bVar2) && (*(int *)(*(longlong *)topfinfo_exref + 0x450) != 0)) {
      iVar6 = GRinqnco();
      if (iVar6 != 0) goto LAB_180031a4d;
    }
  }
  else {
LAB_180031a4d:
    if ((((*(int *)(*(longlong *)topfinfo_exref + 0x1dc) != 0) && (uVar13 != 0)) && (iVar5 != 0)) &&
       (local_2ac == 0)) {
      uVar16 = 0;
      local_2b4 = 1;
      if (*(int *)partial_results_exref != 0) {
        uVar16 = (uint)(DAT_180051ff0 != 0);
        local_2c0 = uVar16;
      }
      iVar5 = GRinqQRs();
      if (iVar5 != 0) {
        if (*(int *)partial_results_exref != 0) {
          uVar16 = 1;
        }
        local_2c0 = uVar16;
      }
    }
  }
  iVar5 = GRinqQRs();
  if (((iVar5 != 0) && (local_2bc != 0)) &&
     ((iVar5 = GRinqpgc(), iVar5 == 0 && (*(int *)(*(longlong *)topfinfo_exref + 0x380) == 1)))) {
    uVar13 = 1;
    local_288 = 1;
    if (*(int *)partial_results_exref != 0) {
      local_2c0 = 1;
    }
  }
  uVar16 = local_2c0;
  if ((DAT_180051c00 == 1) || ((local_26c != 0 && (uVar13 != 0)))) {
    local_2a0 = (uint)bVar17;
    bVar3 = bVar17;
  }
  else {
    bVar3 = false;
  }
  if (DAT_180051c00 == 2) {
    local_290 = (uint)bVar17;
  }
  if (DAT_180051c00 == 5) {
    local_294 = (uint)bVar17;
  }
  if (DAT_180051c00 == 8) {
    local_298 = (uint)bVar17;
  }
  if (((bVar3) || (DAT_180051c00 == 5 && bVar17)) && (lVar8 = GRinqexc(), lVar8 != 0)) {
    local_28c = (uint)bVar17;
  }
  if ((DAT_180052ec4 == 0) || ((uVar7 != 0 && (uVar13 != 0)))) {
    bVar4 = true;
    local_280 = 1;
  }
  if (((local_2b4 != 0) && ((bVar17 || (local_2b8 != 0)))) && (DAT_180051c00 != 7)) {
    local_2b0 = 1;
  }
  if (((uVar13 != 0) && (iVar5 = FUN_1800213f0(), iVar5 != 0)) ||
     ((uVar7 != 0 && (iVar5 = FUN_1800213f0(), iVar5 != 0)))) {
    local_29c = 1;
  }
  if (((local_298 != 0) || (local_29c != 0)) ||
     ((local_2b0 != 0 && (iVar5 = FUN_1800213f0(), iVar5 != 0)))) {
    local_278 = 1;
  }
  if ((((local_2ac != 0) || (uVar7 != 0)) && (bVar4)) &&
     ((local_2b8 == 0 && (iVar5 = GRinqQRs(), iVar5 == 0)))) {
    uVar16 = 1;
    local_2c0 = 1;
    local_2a4 = 1;
  }
  GRsetQRs();
  if (((DAT_180051c00 == 0x1d) && (lVar8 = GRinqigb(), lVar8 != 0)) &&
     ((local_270 = 1, uVar13 == 0 && (local_2b4 == 0)))) {
    local_2ac = 1;
    local_2b4 = 0;
    local_2b0 = 0;
    uVar13 = 1;
    local_2a8 = 1;
    GRsetgpd();
  }
  uVar7 = GRinqdly();
  if ((uVar7 == 0) || ((0x1b < (int)DAT_180051c00 && ((int)DAT_180051c00 < 0x1f)))) {
    uVar16 = local_2c0;
    uVar14 = local_2c0;
LAB_180031dbd:
    iVar5 = local_2a8;
  }
  else {
    if ((!bVar2) || (iVar5 = GRinqgcp(), iVar5 == 1)) {
      uVar14 = local_2c0 | uVar7 & 1;
      uVar16 = (int)uVar7 >> 1 & 1U | uVar16;
      local_2a4 = local_2a4 | (int)uVar7 >> 2 & 1U;
      uVar13 = uVar13 | (int)uVar7 >> 3 & 1U;
      if ((*(int *)(*(longlong *)topfinfo_exref + 0x1dc) == 0) ||
         (((uVar13 == 0 || (local_2bc == 0)) || (local_2ac != 0)))) {
        if (local_2b4 == 0) goto LAB_180031dbd;
      }
      else {
        local_2b4 = 1;
      }
      if (!bVar17) {
        if (local_2b8 == 0) goto LAB_180031dbd;
      }
      if (DAT_180051c00 != 7) {
        local_2b0 = 1;
      }
      goto LAB_180031dbd;
    }
    uVar13 = 1;
    local_2b4 = 0;
    local_2b0 = 0;
    local_2ac = 1;
    uVar16 = local_2c0;
    uVar14 = local_2c0;
    iVar5 = 1;
  }
  if (DAT_180051c00 - 0x1c < 3) {
    GRsetdly();
    uVar16 = 0;
    local_2a4 = 0;
    uVar14 = 0;
    if (DAT_180051c00 == 0x1e) {
      if (local_2bc == 0) {
        return 0;
      }
      local_2b0 = 0;
      uVar13 = 0;
      local_2b4 = 0;
    }
  }
  else {
    GRsetdly();
  }
  if (DAT_180051c00 == 0x26) {
    if (local_2bc == 0) {
      return 0;
    }
    local_2b0 = 0;
    uVar13 = 0;
    local_2b4 = 0;
  }
  if (local_284 != 0) {
    if (*(int *)partial_results_exref == 0) {
      local_2c8 = CONCAT44(local_2c8._4_4_,uVar11) | 0x1000000;
      uVar11 = uVar11 | 0x1000000;
    }
    else if (DAT_180051ff0 == 0) goto LAB_180031e63;
    uVar16 = 1;
    uVar14 = 1;
  }
LAB_180031e63:
  uVar7 = uVar11;
  if ((local_2ac != 0) && (DAT_180051c00 != 7)) {
    if (*(int *)debug_flag_exref != 0) {
      FUN_1800282b0("Run Input Translator");
    }
    uVar7 = uVar11 | 0x40;
    local_2c8 = CONCAT44(local_2c8._4_4_,uVar11) | 0x40;
  }
  iVar6 = local_280;
  uVar11 = uVar7;
  if (local_280 != 0) {
    if (*(int *)debug_flag_exref != 0) {
      FUN_1800282b0("Write .prm file");
    }
    uVar11 = uVar7 | 0x200;
    local_2c8 = CONCAT44(local_2c8._4_4_,uVar7) | 0x200;
  }
  uVar7 = uVar11;
  if (((local_2ac != 0) && (iVar6 != 0)) && (DAT_180051c00 != 7)) {
    if (*(int *)debug_flag_exref != 0) {
      FUN_1800282b0("Erase simulation engine files");
    }
    uVar7 = uVar11 | 0x8000000;
    local_2c8 = CONCAT44(local_2c8._4_4_,uVar11) | 0x8000000;
  }
  uVar11 = uVar7;
  if ((local_2a0 != 0) && (bVar17)) {
    if (*(int *)debug_flag_exref != 0) {
      FUN_1800282b0("Run IAP GO");
    }
    uVar11 = uVar7 | 0x400;
    local_2c8 = CONCAT44(local_2c8._4_4_,uVar7) | 0x400;
  }
  uVar7 = local_2b8;
  uVar12 = uVar11;
  if ((local_2b8 == 0) &&
     ((DAT_180051c00 == 3 || (*(int *)(*(longlong *)topfinfo_exref + 0x380) != 1)))) {
    if ((0x1b < *(uint *)(*(longlong *)topfinfo_exref + 0x380)) ||
       ((0x8000208U >> (*(uint *)(*(longlong *)topfinfo_exref + 0x380) & 0x1f) & 1) == 0)) {
      if (*(int *)debug_flag_exref != 0) {
        FUN_1800282b0("Run IAP REPORT SUMMARY");
      }
      uVar12 = uVar11 | 0x1000000;
      local_2c8 = CONCAT44(local_2c8._4_4_,uVar11) | 0x1000000;
      goto LAB_180031fa3;
    }
    if (*(int *)debug_flag_exref != 0) {
      FUN_1800282b0("Run IAP REPORT ALL");
    }
    uVar11 = local_2c8._4_4_ | 4;
    local_2c8 = local_2c8 | 0x400000000;
  }
  else {
LAB_180031fa3:
    uVar11 = local_2c8._4_4_;
  }
  uVar15 = uVar11;
  if ((*(int *)partial_results_exref != 0) && (uVar7 == 0)) {
    if (*(int *)debug_flag_exref != 0) {
      FUN_1800282b0("Run IAP STATUS");
    }
    if (((DAT_180051c00 != 0x1f) && (DAT_180051c00 != 0x22)) || (DAT_180051c10 != 0)) {
      uVar15 = uVar11 | 0x10;
      local_2c8 = CONCAT44(uVar11,(uint)local_2c8) | 0x1000000000;
    }
  }
  uVar11 = uVar12;
  if ((DAT_180051c00 == 7) && (*(int *)(*(longlong *)topfinfo_exref + 0x380) == 1)) {
    if (*(int *)debug_flag_exref != 0) {
      FUN_1800282b0("Run IAP REPORT REPORT");
    }
    uVar11 = uVar12 | 0x800;
    local_2c8 = CONCAT44(local_2c8._4_4_,uVar12) | 0x800;
  }
  uVar12 = uVar11;
  if (DAT_180052ec4 == 0) {
    if (*(int *)debug_flag_exref != 0) {
      FUN_1800282b0("Trigger start of simulation engine");
    }
    uVar12 = uVar11 | 0x10;
    local_2c8 = CONCAT44(local_2c8._4_4_,uVar11) | 0x10;
  }
  uVar11 = uVar12;
  if ((uVar13 != 0) && (DAT_180051c00 != 7)) {
    if (*(int *)debug_flag_exref != 0) {
      FUN_1800282b0("Generate Input file");
    }
    uVar11 = uVar12 | 1;
    local_2c8 = CONCAT44(local_2c8._4_4_,uVar12) | 1;
  }
  uVar12 = uVar11;
  if (iVar5 != 0) {
    uVar12 = uVar11 | 0x20;
    local_2c8 = CONCAT44(local_2c8._4_4_,uVar11) | 0x20;
  }
  if (DAT_180052ec4 != 0) {
    uVar11 = uVar12;
    if ((iVar5 != 0) && (uVar13 != 0)) {
      if (*(int *)debug_flag_exref != 0) {
        FUN_1800282b0("Run IAP RESTART QUIT");
      }
      uVar11 = uVar12 | 0x2000;
      local_2c8 = CONCAT44(local_2c8._4_4_,uVar12) | 0x2000;
    }
    uVar12 = uVar11;
    if ((DAT_180052ec4 != 0) &&
       ((((iVar5 != 0 || (local_27c != 0)) && (uVar13 != 0)) && (iVar5 = GRinqiap(), iVar5 != 0))))
    {
      if (*(int *)debug_flag_exref != 0) {
        FUN_1800282b0("Close IAP files");
      }
      uVar12 = uVar11 | 0x4000000;
      local_2c8 = CONCAT44(local_2c8._4_4_,uVar11) | 0x4000000;
    }
  }
  uVar11 = uVar12;
  if (local_2b0 != 0) {
    if (*(int *)debug_flag_exref != 0) {
      FUN_1800282b0("Run IAP EDIT");
    }
    uVar11 = uVar12 | 0x4000;
    local_2c8 = CONCAT44(local_2c8._4_4_,uVar12) | 0x4000;
  }
  uVar13 = uVar11;
  if (local_278 != 0) {
    if (*(int *)debug_flag_exref != 0) {
      FUN_1800282b0("Run IAP SHOW STOPS");
    }
    uVar13 = uVar11 | 0x20000000;
    local_2c8 = CONCAT44(local_2c8._4_4_,uVar11) | 0x20000000;
  }
  uVar11 = uVar13;
  if (local_29c != 0) {
    if (*(int *)debug_flag_exref != 0) {
      FUN_1800282b0("Run IAP SHOW STOPS");
    }
    uVar11 = uVar13 | 0x40000000;
    local_2c8 = CONCAT44(local_2c8._4_4_,uVar13) | 0x40000000;
  }
  uVar13 = uVar11;
  if (local_298 != 0) {
    if (*(int *)debug_flag_exref != 0) {
      FUN_1800282b0("Put up Stop Points DB");
    }
    uVar13 = uVar11 | 4;
    local_2c8 = CONCAT44(local_2c8._4_4_,uVar11) | 4;
  }
  uVar11 = uVar13;
  if (local_268 == 0) {
LAB_1800321d0:
    uVar13 = uVar11;
    if ((local_2b4 != 0) && (DAT_180051c00 != 7)) {
      if (local_274 == 0) {
        if (*(int *)debug_flag_exref != 0) {
          FUN_1800282b0("Generate Edit Run Input file");
        }
        uVar13 = uVar11 | 2;
        local_2c8 = CONCAT44(local_2c8._4_4_,uVar11) | 2;
      }
      else {
        if (*(int *)debug_flag_exref != 0) {
          FUN_1800282b0("Generate Equation Oriented Edit Run Input file only");
        }
        local_2c8 = CONCAT44(uVar15,(uint)local_2c8) | 0x80000000000;
        uVar15 = uVar15 | 0x800;
      }
    }
  }
  else {
    if (local_2ac != 0) {
LAB_1800321b0:
      if (*(int *)debug_flag_exref != 0) {
        FUN_1800282b0("Edit Input file after generate");
      }
      uVar11 = uVar13 | 0x100;
      local_2c8 = CONCAT44(local_2c8._4_4_,uVar13) | 0x100;
      goto LAB_1800321d0;
    }
    if (local_2b4 != 0) goto LAB_1800321b0;
  }
  uVar11 = uVar13;
  if (local_290 != 0) {
    if (*(int *)debug_flag_exref != 0) {
      FUN_1800282b0("Run IAP MOVE TO");
    }
    uVar11 = uVar13 | 0x20000;
    local_2c8 = CONCAT44(local_2c8._4_4_,uVar13) | 0x20000;
  }
  uVar13 = local_294;
  uVar12 = uVar11;
  if (local_294 != 0) {
    if (*(int *)debug_flag_exref != 0) {
      FUN_1800282b0("Run IAP STEP");
    }
    uVar12 = uVar11 | 0x40000;
    local_2c8 = CONCAT44(local_2c8._4_4_,uVar11) | 0x40000;
  }
  uVar11 = uVar12;
  if (local_28c != 0) {
    if (*(int *)debug_flag_exref != 0) {
      FUN_1800282b0("Ask the User to Re-execute Block");
    }
    uVar11 = uVar12 | 0x100000;
    local_2c8 = CONCAT44(local_2c8._4_4_,uVar12) | 0x100000;
  }
  uVar12 = uVar11;
  if (local_288 != 0) {
    if (*(int *)debug_flag_exref != 0) {
      iVar5 = MVGetProductCode();
      pcVar10 = "Copy aprpdf and aprhis files to APtmpfil.aprpdf/aprhis";
      if (iVar5 != 2) {
        pcVar10 = "Copy pdf and his files to APtmpfil.appdf/his";
      }
      FUN_1800282b0(pcVar10);
    }
    uVar12 = uVar11 | 0x200000;
    local_2c8 = CONCAT44(local_2c8._4_4_,uVar11) | 0x200000;
  }
  uVar11 = uVar12;
  if (uVar14 != 0) {
    if (*(int *)debug_flag_exref != 0) {
      FUN_1800282b0("Generate Summary header");
    }
    uVar11 = uVar12 | 8;
    local_2c8 = CONCAT44(local_2c8._4_4_,uVar12) | 8;
  }
  uVar14 = uVar11;
  if (local_2a4 != 0) {
    if (*(int *)debug_flag_exref != 0) {
      FUN_1800282b0("Purge results");
    }
    uVar14 = uVar11 | 0x80000000;
    local_2c8 = CONCAT44(local_2c8._4_4_,uVar11) | 0x80000000;
  }
  uVar11 = uVar14;
  if (uVar16 != 0) {
    if (*(int *)debug_flag_exref != 0) {
      FUN_1800282b0("Load summary info");
    }
    uVar11 = uVar14 | 0x8000;
    local_2c8 = CONCAT44(local_2c8._4_4_,uVar14) | 0x8000;
  }
  uVar16 = uVar15;
  if (uVar7 != 0) {
    if (*(int *)debug_flag_exref != 0) {
      FUN_1800282b0("Is canned analysis run");
    }
    uVar16 = uVar15 | 1;
    local_2c8 = CONCAT44(uVar15,(uint)local_2c8) | 0x100000000;
  }
  uVar7 = uVar16;
  if (local_270 != 0) {
    if (*(int *)debug_flag_exref != 0) {
      FUN_1800282b0("Generate instant gratification");
    }
    uVar7 = uVar16 | 0x200;
    local_2c8 = CONCAT44(uVar16,(uint)local_2c8) | 0x20000000000;
  }
  if ((DAT_180051c00 == 0x1f) || (uVar16 = uVar7, DAT_180051c00 == 0x22)) {
    if (*(int *)debug_flag_exref != 0) {
      FUN_1800282b0("Execute EO command");
    }
    uVar16 = uVar7 | 0x1000;
    local_2c8 = CONCAT44(uVar7,(uint)local_2c8) | 0x100000000000;
  }
  if (DAT_180051c00 == 0x21) {
LAB_1800323d6:
    if (*(int *)debug_flag_exref != 0) {
      FUN_1800282b0("Synchronize EO from SM");
    }
    uVar7 = uVar16 | 0x2000;
    local_2c8 = CONCAT44(uVar16,(uint)local_2c8) | 0x200000000000;
LAB_1800323f6:
    if (DAT_180051c00 == 0x22) {
      if (DAT_180051c08 == 0) goto LAB_18003246f;
      if (*(int *)debug_flag_exref != 0) {
        FUN_1800282b0("Synchronize EO from SM");
      }
      local_2c8 = CONCAT44(uVar7,(uint)local_2c8) | 0x200000000000;
      uVar7 = uVar7 | 0x2000;
    }
    if (DAT_180051c00 == 0x27) {
      if (local_2bc == 0) {
        if (*(int *)debug_flag_exref != 0) {
          FUN_1800282b0("Reint EO from new SM");
        }
        uVar7 = uVar7 | 0x2000;
      }
      else {
        if (*(int *)debug_flag_exref != 0) {
          FUN_1800282b0("Rebuild EO from SM");
        }
        uVar7 = uVar7 | 0x4000;
      }
      local_2c8 = CONCAT44(uVar7,(uint)local_2c8);
    }
  }
  else {
    uVar7 = uVar16;
    if (DAT_180051c00 != 0x1f) goto LAB_1800323f6;
    if (local_26c != 0) goto LAB_1800323d6;
  }
LAB_18003246f:
  uVar16 = uVar7;
  if ((((uVar13 != 0) || (local_2a0 != 0)) || (local_284 != 0)) &&
     (*(int *)partial_results_exref != 0)) {
    if (*(int *)debug_flag_exref != 0) {
      FUN_1800282b0("Update results birdcage");
    }
    uVar16 = uVar7 | 0x20000;
    local_2c8 = CONCAT44(uVar7,(uint)local_2c8) | 0x2000000000000;
  }
  if (DAT_180051c00 == 10) {
    uVar16 = uVar16 | 0x20;
  }
  else if (DAT_180051c00 == 0xb) {
    uVar16 = uVar16 | 0x40;
  }
  else {
    if ((*(uint *)(Sactions_exref + 4) & 0x40) != 0) {
      *(uint *)(Sactions_exref + 4) = *(uint *)(Sactions_exref + 4) & 0xffffffbf;
      if ((uVar16 & 1) == 0) {
        local_2c8 = CONCAT44(local_2c8._4_4_,uVar11) | 0x80008008;
        uVar11 = uVar11 | 0x80008008;
      }
      goto LAB_180032506;
    }
    if (DAT_180051c00 != 0x28) goto LAB_180032506;
    uVar16 = uVar16 | 0x8020;
    uVar11 = uVar11 & 0xfffffffe;
    local_2c8 = (ulonglong)uVar11;
  }
  local_2c8 = CONCAT44(uVar16,(uint)local_2c8);
LAB_180032506:
  uVar7 = uVar11;
  if ((((uVar11 & 0x6010) != 0) || ((uVar16 & 0x20) != 0)) &&
     ((2 < DAT_180051c00 - 0x1c && (DAT_180051c00 != 0x26)))) {
    if (*(int *)debug_flag_exref != 0) {
      FUN_1800282b0("Run IAP SHOW SEQUENCE");
    }
    uVar7 = uVar11 | 0x10000;
    local_2c8 = CONCAT44(local_2c8._4_4_,uVar11) | 0x10000;
  }
  if ((uVar16 & 0x40) != 0) {
    if ((uVar7 & 0x10) != 0) {
      uVar7 = uVar7 | 0x10000;
    }
    local_2c8 = CONCAT44(local_2c8._4_4_,uVar7) & 0xffffffff7fffffff;
  }
  *(ulonglong *)local_260 = local_2c8;
  return 1;
}

/* RVA 0x325b0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_1800325b0(undefined *param_1,undefined8 param_2,undefined *param_3,undefined *param_4)

{
  code cVar1;
  char cVar2;
  undefined4 *puVar3;
  bool bVar4;
  int iVar5;
  char *pcVar6;
  FILE *_File;
  undefined8 uVar7;
  longlong lVar8;
  undefined7 extraout_var;
  char *pcVar9;
  longlong lVar10;
  undefined4 *puVar11;
  undefined2 *puVar12;
  code *pcVar13;
  code *pcVar14;
  longlong lVar15;
  char *pcVar16;
  code *pcVar17;
  longlong lVar18;
  ulonglong uVar19;
  ulonglong uVar20;
  undefined1 auStack_3e8 [32];
  FILE *local_3c8;
  undefined1 local_3c0 [56];
  code *local_388 [10];
  undefined1 local_338 [255];
  undefined4 uStack_239;
  undefined1 local_234 [251];
  undefined2 uStack_139;
  ulonglong local_38;
  
  local_38 = DAT_1800516d8 ^ (ulonglong)auStack_3e8;
  pcVar16 = &DAT_180052ed0;
  lVar18 = 0;
  uVar19 = 0;
  pcVar17 = APtmpfil_exref;
  if (param_1 != (undefined *)0x0) {
    pcVar17 = (code *)param_1;
  }
  if (DAT_180052ed0 == '\0') {
    param_3 = (undefined *)GetSorResStringEx(0xd48);
    param_4 = (undefined *)0x7f;
    strncpy_s(&DAT_180052ed0,0x80,param_3,0x7f);
  }
  if (DAT_180052f50 == '\0') {
    param_3 = (undefined *)GetSorResStringEx(0xd49);
    param_4 = (undefined *)0x7f;
    strncpy_s(&DAT_180052f50,0x80,param_3,0x7f);
  }
  pcVar13 = pcVar17;
  do {
    cVar1 = *pcVar13;
    pcVar13[(longlong)(local_338 + (0x100 - (longlong)pcVar17))] = cVar1;
    pcVar13 = pcVar13 + 1;
  } while (cVar1 != (code)0x0);
  puVar3 = &uStack_239;
  do {
    puVar11 = puVar3;
    puVar3 = (undefined4 *)((longlong)puVar11 + 1);
  } while (*(char *)((longlong)puVar11 + 1) != '\0');
  *(undefined4 *)((longlong)puVar11 + 1) = DAT_180040a80;
  *(undefined1 *)((longlong)puVar11 + 5) = DAT_180040a84;
  pcVar6 = strrchr((char *)((longlong)&uStack_239 + 1),0x5c);
  if (pcVar6 == (char *)0x0) {
    GetCurrentDirectoryA(0xff,(LPSTR)((longlong)&uStack_139 + 1));
    puVar12 = &uStack_139;
    do {
      pcVar6 = (char *)((longlong)puVar12 + 1);
      puVar12 = (undefined2 *)((longlong)puVar12 + 1);
    } while (*pcVar6 != '\0');
    *puVar12 = DAT_18003fa78;
    puVar12 = &uStack_139;
    do {
      pcVar6 = (char *)((longlong)puVar12 + 1);
      puVar12 = (undefined2 *)((longlong)puVar12 + 1);
    } while (*pcVar6 != '\0');
    param_3 = (undefined *)((longlong)&uStack_239 + 1);
    lVar10 = 0;
    do {
      cVar1 = (code)param_3[lVar10];
      *(code *)((longlong)puVar12 + lVar10) = cVar1;
      lVar10 = lVar10 + 1;
    } while (cVar1 != (code)0x0);
  }
  else {
    lVar10 = 0;
    do {
      cVar2 = local_338[lVar10 + 0x100];
      local_234[lVar10 + 0xfc] = cVar2;
      lVar10 = lVar10 + 1;
    } while (cVar2 != '\0');
  }
  remove((char *)((longlong)&uStack_139 + 1));
  do {
    iVar5 = _stat64i32((longlong)&uStack_139 + 1,local_3c0);
  } while (iVar5 == 0);
  _File = fopen((char *)((longlong)&uStack_239 + 1),"w");
  local_3c8 = _File;
  if (_File == (FILE *)0x0) {
    uVar7 = GetSorResStringEx(0xd4a);
    FUN_180019f70(uVar7,(longlong)&uStack_239 + 1,param_3,param_4);
    *(uint *)Sactions_exref = *(uint *)Sactions_exref | 0x1000;
    return 0xffffffff;
  }
  if ((param_1 == (undefined *)0x0) ||
     (pcVar6 = strrchr((char *)pcVar17,0x5c), pcVar6 == (char *)0x0)) {
    lVar10 = -1;
    do {
      lVar15 = lVar10 + 1;
      pcVar6 = &DAT_180052f51 + lVar10;
      lVar10 = lVar15;
    } while (*pcVar6 != '\0');
    lVar10 = -1;
    do {
      lVar8 = lVar10 + 1;
      pcVar6 = &DAT_180052ed1 + lVar10;
      lVar10 = lVar8;
    } while (*pcVar6 != '\0');
    lVar15 = lVar15 + lVar8;
    if (param_1 == (undefined *)0x0) {
      FUN_180028920(_File,"SLAVE:\n",param_3,param_4);
    }
  }
  else {
    pcVar17 = (code *)(pcVar6 + 1);
    lVar10 = -1;
    do {
      lVar15 = lVar10 + 1;
      pcVar6 = &DAT_180052f51 + lVar10;
      lVar10 = lVar15;
    } while (*pcVar6 != '\0');
    lVar10 = -1;
    do {
      lVar8 = lVar10 + 1;
      pcVar6 = &DAT_180052ed1 + lVar10;
      lVar10 = lVar8;
    } while (*pcVar6 != '\0');
    lVar15 = lVar15 + lVar8;
  }
  if (((byte)Sactions_exref[4] & 0x20) != 0) {
    FUN_180028920(_File,"MMBACKUP:\n",param_3,param_4);
  }
  if ((*(uint *)Sactions_exref & 0x2000000) == 0) {
    param_3 = pcVar17;
    FUN_180028920(_File,"INPUT: %s.inm\n",pcVar17,param_4);
  }
  FUN_180028920(_File,"MODNAME: apmain\n",param_3,param_4);
  FUN_180028920(_File,"RUNID: %s\n",pcVar17,param_4);
  FUN_180028920(_File,"NEW_RUNID: %s\n",pcVar17,param_4);
  FUN_180028920(_File,"OLD_RUNID: %s\n",pcVar17,param_4);
  iVar5 = MVGetProductCode();
  pcVar6 = "PDF: %s.aprpdf\n";
  if (iVar5 != 2) {
    pcVar6 = "PDF: %s.appdf\n";
  }
  FUN_180028920(_File,pcVar6,pcVar17,param_4);
  if (submitdata_exref[0x210] != (code)0x0) {
    iVar5 = FUN_180026510((char *)0x0,(char *)(submitdata_exref + 0x210));
    if (iVar5 != 0) {
      pcVar13 = submitdata_exref + 0x210;
      lVar10 = -(longlong)pcVar13;
      do {
        cVar1 = *pcVar13;
        pcVar13[(longlong)(local_338 + lVar10)] = cVar1;
        pcVar13 = pcVar13 + 1;
      } while (cVar1 != (code)0x0);
      pcVar6 = strchr(local_338,0x2e);
      if (pcVar6 == (char *)0x0) {
        param_4 = &DAT_1800433c0;
        pcVar17 = submitdata_exref + 0x210;
        FUN_180008f80(local_338,"%s.%s",pcVar17,&DAT_1800433c0);
        pcVar13 = (code *)local_338;
        pcVar14 = submitdata_exref + 0x210;
        do {
          cVar1 = *pcVar13;
          pcVar13 = pcVar13 + 1;
          *pcVar14 = cVar1;
          pcVar14 = pcVar14 + 1;
        } while (cVar1 != (code)0x0);
      }
    }
    iVar5 = FUN_180026510((char *)0x0,(char *)(submitdata_exref + 0x210));
    if ((iVar5 == 0) ||
       (pcVar6 = strstr((char *)(submitdata_exref + 0x210),"${"), pcVar6 != (char *)0x0)) {
      pcVar17 = submitdata_exref + 0x210;
      FUN_180028920(_File,"PP1A: %s\n",pcVar17,param_4);
    }
    else {
      lVar10 = -1;
      local_388[0] = submitdata_exref + 0x210;
      uVar19 = 1;
      do {
        lVar10 = lVar10 + 1;
      } while (local_388[0][lVar10] != (code)0x0);
      lVar15 = lVar15 + lVar10;
    }
  }
  uVar20 = uVar19;
  if (submitdata_exref[0x410] != (code)0x0) {
    iVar5 = FUN_180026510((char *)0x0,(char *)(submitdata_exref + 0x410));
    if (iVar5 != 0) {
      pcVar13 = submitdata_exref + 0x410;
      lVar10 = -(longlong)pcVar13;
      do {
        cVar1 = *pcVar13;
        pcVar13[(longlong)(local_338 + lVar10)] = cVar1;
        pcVar13 = pcVar13 + 1;
      } while (cVar1 != (code)0x0);
      pcVar6 = strchr(local_338,0x2e);
      if (pcVar6 == (char *)0x0) {
        param_4 = &DAT_1800433c0;
        pcVar17 = submitdata_exref + 0x410;
        FUN_180008f80(local_338,"%s.%s",pcVar17,&DAT_1800433c0);
        pcVar13 = (code *)local_338;
        pcVar14 = submitdata_exref + 0x410;
        do {
          cVar1 = *pcVar13;
          pcVar13 = pcVar13 + 1;
          *pcVar14 = cVar1;
          pcVar14 = pcVar14 + 1;
        } while (cVar1 != (code)0x0);
      }
    }
    iVar5 = FUN_180026510((char *)0x0,(char *)(submitdata_exref + 0x410));
    if ((iVar5 == 0) ||
       (pcVar6 = strstr((char *)(submitdata_exref + 0x410),"${"), pcVar6 != (char *)0x0)) {
      pcVar17 = submitdata_exref + 0x410;
      FUN_180028920(_File,"PP2A: %s\n",pcVar17,param_4);
    }
    else {
      uVar20 = (ulonglong)((int)uVar19 + 1);
      local_388[uVar19] = submitdata_exref + 0x410;
      lVar10 = -1;
      do {
        lVar10 = lVar10 + 1;
      } while ((submitdata_exref + 0x410)[lVar10] != (code)0x0);
      lVar15 = lVar15 + lVar10;
    }
  }
  uVar19 = uVar20;
  if (submitdata_exref[0x310] != (code)0x0) {
    iVar5 = FUN_180026510((char *)0x0,(char *)(submitdata_exref + 0x310));
    if (iVar5 != 0) {
      pcVar13 = submitdata_exref + 0x310;
      lVar10 = -(longlong)pcVar13;
      do {
        cVar1 = *pcVar13;
        pcVar13[(longlong)(local_338 + lVar10)] = cVar1;
        pcVar13 = pcVar13 + 1;
      } while (cVar1 != (code)0x0);
      pcVar6 = strchr(local_338,0x2e);
      if (pcVar6 == (char *)0x0) {
        param_4 = &DAT_1800433c0;
        pcVar17 = submitdata_exref + 0x310;
        FUN_180008f80(local_338,"%s.%s",pcVar17,&DAT_1800433c0);
        pcVar13 = (code *)local_338;
        pcVar14 = submitdata_exref + 0x310;
        do {
          cVar1 = *pcVar13;
          pcVar13 = pcVar13 + 1;
          *pcVar14 = cVar1;
          pcVar14 = pcVar14 + 1;
        } while (cVar1 != (code)0x0);
      }
    }
    iVar5 = FUN_180026510((char *)0x0,(char *)(submitdata_exref + 0x310));
    if ((iVar5 == 0) ||
       (pcVar6 = strstr((char *)(submitdata_exref + 0x310),"${"), pcVar6 != (char *)0x0)) {
      pcVar17 = submitdata_exref + 0x310;
      FUN_180028920(_File,"PP1B: %s\n",pcVar17,param_4);
    }
    else {
      uVar19 = (ulonglong)((int)uVar20 + 1);
      local_388[uVar20] = submitdata_exref + 0x310;
      lVar10 = -1;
      do {
        lVar10 = lVar10 + 1;
      } while ((submitdata_exref + 0x310)[lVar10] != (code)0x0);
      lVar15 = lVar15 + lVar10;
    }
  }
  uVar20 = uVar19;
  if (submitdata_exref[0x510] != (code)0x0) {
    iVar5 = FUN_180026510((char *)0x0,(char *)(submitdata_exref + 0x510));
    if (iVar5 != 0) {
      pcVar13 = submitdata_exref + 0x510;
      lVar10 = -(longlong)pcVar13;
      do {
        cVar1 = *pcVar13;
        pcVar13[(longlong)(local_338 + lVar10)] = cVar1;
        pcVar13 = pcVar13 + 1;
      } while (cVar1 != (code)0x0);
      pcVar6 = strchr(local_338,0x2e);
      if (pcVar6 == (char *)0x0) {
        param_4 = &DAT_1800433c0;
        pcVar17 = submitdata_exref + 0x510;
        FUN_180008f80(local_338,"%s.%s",pcVar17,&DAT_1800433c0);
        pcVar13 = (code *)local_338;
        pcVar14 = submitdata_exref + 0x510;
        do {
          cVar1 = *pcVar13;
          pcVar13 = pcVar13 + 1;
          *pcVar14 = cVar1;
          pcVar14 = pcVar14 + 1;
        } while (cVar1 != (code)0x0);
      }
    }
    iVar5 = FUN_180026510((char *)0x0,(char *)(submitdata_exref + 0x510));
    if ((iVar5 == 0) ||
       (pcVar6 = strstr((char *)(submitdata_exref + 0x510),"${"), pcVar6 != (char *)0x0)) {
      pcVar17 = submitdata_exref + 0x510;
      FUN_180028920(_File,"PP2B: %s\n",pcVar17,param_4);
    }
    else {
      uVar20 = (ulonglong)((int)uVar19 + 1);
      local_388[uVar19] = submitdata_exref + 0x510;
      lVar10 = -1;
      do {
        lVar10 = lVar10 + 1;
      } while ((submitdata_exref + 0x510)[lVar10] != (code)0x0);
      lVar15 = lVar15 + lVar10;
    }
  }
  uVar19 = uVar20;
  if (submitdata_exref[0x610] != (code)0x0) {
    iVar5 = FUN_180026510((char *)0x0,(char *)(submitdata_exref + 0x610));
    if (iVar5 != 0) {
      pcVar13 = submitdata_exref + 0x610;
      lVar10 = -(longlong)pcVar13;
      do {
        cVar1 = *pcVar13;
        pcVar13[(longlong)(local_338 + lVar10)] = cVar1;
        pcVar13 = pcVar13 + 1;
      } while (cVar1 != (code)0x0);
      pcVar6 = strchr(local_338,0x2e);
      if (pcVar6 == (char *)0x0) {
        param_4 = &DAT_1800433c0;
        pcVar17 = submitdata_exref + 0x610;
        FUN_180008f80(local_338,"%s.%s",pcVar17,&DAT_1800433c0);
        pcVar13 = (code *)local_338;
        pcVar14 = submitdata_exref + 0x610;
        do {
          cVar1 = *pcVar13;
          pcVar13 = pcVar13 + 1;
          *pcVar14 = cVar1;
          pcVar14 = pcVar14 + 1;
        } while (cVar1 != (code)0x0);
      }
    }
    iVar5 = FUN_180026510((char *)0x0,(char *)(submitdata_exref + 0x610));
    if ((iVar5 == 0) ||
       (pcVar6 = strstr((char *)(submitdata_exref + 0x610),"${"), pcVar6 != (char *)0x0)) {
      pcVar17 = submitdata_exref + 0x610;
      FUN_180028920(_File,"PP2C: %s\n",pcVar17,param_4);
    }
    else {
      uVar19 = (ulonglong)((int)uVar20 + 1);
      local_388[uVar20] = submitdata_exref + 0x610;
      lVar10 = -1;
      do {
        lVar10 = lVar10 + 1;
      } while ((submitdata_exref + 0x610)[lVar10] != (code)0x0);
      lVar15 = lVar15 + lVar10;
    }
  }
  if ((*(int *)(submitdata_exref + 0x1214) == 0) &&
     (pcVar6 = getenv("USERNAME"), pcVar6 != (char *)0x0)) {
    FUN_180028920(_File,"USERNAME: %s\n",pcVar6,param_4);
  }
  else if ((*(int *)(submitdata_exref + 0x1214) == 0) &&
          (bVar4 = FUN_180007180(local_338,0x100), (int)CONCAT71(extraout_var,bVar4) != 0)) {
    FUN_180028920(_File,"USERNAME: %s\n",local_338,param_4);
  }
  else if (*(int *)(submitdata_exref + 0x1214) == 0) {
    FUN_180028920(_File,"USERNAME: DOS_USER\n",pcVar17,param_4);
  }
  if ((*(int *)(submitdata_exref + 0x1214) == 0) && (submitdata_exref[0x1674] != (code)0x0)) {
    FUN_180028920(_File,"XMOD: %s\n",submitdata_exref + 0x1674,param_4);
  }
  pcVar6 = (char *)submitdata_exref;
  if (*(int *)(submitdata_exref + 0x1214) != 0) {
    pcVar6 = (char *)(submitdata_exref + 0x1324);
    FUN_180028920(_File,"USERNAME: %s\n",pcVar6,param_4);
  }
  if (submitdata_exref[0x710] == (code)0x0) {
    iVar5 = FUN_180026510((char *)0x0,"user.ilb");
    if (iVar5 != 0) goto LAB_180033145;
    pcVar6 = "user.ilb";
  }
  else {
    iVar5 = FUN_180026510((char *)0x0,(char *)(submitdata_exref + 0x710));
    if (iVar5 != 0) {
      pcVar17 = submitdata_exref + 0x710;
      lVar10 = -(longlong)pcVar17;
      do {
        cVar1 = *pcVar17;
        pcVar17[(longlong)(local_338 + lVar10)] = cVar1;
        pcVar17 = pcVar17 + 1;
      } while (cVar1 != (code)0x0);
      pcVar9 = strchr(local_338,0x2e);
      if (pcVar9 == (char *)0x0) {
        param_4 = &DAT_18004345c;
        pcVar6 = (char *)(submitdata_exref + 0x710);
        FUN_180008f80(local_338,"%s.%s",pcVar6,&DAT_18004345c);
        pcVar17 = (code *)local_338;
        pcVar13 = submitdata_exref + 0x710;
        do {
          cVar1 = *pcVar17;
          pcVar17 = pcVar17 + 1;
          *pcVar13 = cVar1;
          pcVar13 = pcVar13 + 1;
        } while (cVar1 != (code)0x0);
      }
    }
    iVar5 = FUN_180026510((char *)0x0,(char *)(submitdata_exref + 0x710));
    if ((iVar5 != 0) &&
       (uVar7 = FUN_180024fa0((longlong)(submitdata_exref + 0x710)), (int)uVar7 != 0)) {
      local_388[uVar19] = submitdata_exref + 0x710;
      lVar10 = -1;
      do {
        lVar10 = lVar10 + 1;
      } while ((submitdata_exref + 0x710)[lVar10] != (code)0x0);
      lVar15 = lVar15 + lVar10;
      uVar19 = (ulonglong)((int)uVar19 + 1);
      goto LAB_180033145;
    }
    pcVar6 = (char *)(submitdata_exref + 0x710);
  }
  FUN_180028920(_File,"xulb: %s\n",pcVar6,param_4);
LAB_180033145:
  pcVar17 = (code *)getenv("XSDF");
  if ((pcVar17 != (code *)0x0) && (iVar5 = FUN_180026510((char *)0x0,(char *)pcVar17), iVar5 == 0))
  {
    FUN_180028920(_File,"xsdf: %s\n",pcVar17,param_4);
    pcVar6 = (char *)pcVar17;
  }
  if (submitdata_exref[0x910] != (code)0x0) {
    iVar5 = FUN_180026510((char *)0x0,(char *)(submitdata_exref + 0x910));
    if (iVar5 != 0) {
      pcVar17 = submitdata_exref + 0x910;
      lVar10 = -(longlong)pcVar17;
      do {
        cVar1 = *pcVar17;
        pcVar17[(longlong)(local_338 + lVar10)] = cVar1;
        pcVar17 = pcVar17 + 1;
      } while (cVar1 != (code)0x0);
      pcVar9 = strchr(local_338,0x2e);
      if (pcVar9 == (char *)0x0) {
        param_4 = &DAT_1800433c0;
        pcVar6 = (char *)(submitdata_exref + 0x910);
        FUN_180008f80(local_338,"%s.%s",pcVar6,&DAT_1800433c0);
        pcVar17 = (code *)local_338;
        pcVar13 = submitdata_exref + 0x910;
        do {
          cVar1 = *pcVar17;
          pcVar17 = pcVar17 + 1;
          *pcVar13 = cVar1;
          pcVar13 = pcVar13 + 1;
        } while (cVar1 != (code)0x0);
      }
    }
    iVar5 = FUN_180026510((char *)0x0,(char *)(submitdata_exref + 0x910));
    if ((iVar5 == 0) ||
       (uVar7 = FUN_180024fa0((longlong)(submitdata_exref + 0x910)), (int)uVar7 == 0)) {
      pcVar6 = (char *)(submitdata_exref + 0x910);
      FUN_180028920(_File,"ucos: %s\n",pcVar6,param_4);
    }
    else {
      local_388[uVar19] = submitdata_exref + 0x910;
      lVar10 = -1;
      do {
        lVar10 = lVar10 + 1;
      } while ((submitdata_exref + 0x910)[lVar10] != (code)0x0);
      lVar15 = lVar15 + lVar10;
      uVar19 = (ulonglong)((int)uVar19 + 1);
    }
  }
  if (submitdata_exref[0xa10] != (code)0x0) {
    iVar5 = FUN_180026510((char *)0x0,(char *)(submitdata_exref + 0xa10));
    if (iVar5 != 0) {
      pcVar17 = submitdata_exref + 0xa10;
      lVar10 = -(longlong)pcVar17;
      do {
        cVar1 = *pcVar17;
        pcVar17[(longlong)(local_338 + lVar10)] = cVar1;
        pcVar17 = pcVar17 + 1;
      } while (cVar1 != (code)0x0);
      pcVar9 = strchr(local_338,0x2e);
      if (pcVar9 == (char *)0x0) {
        param_4 = &DAT_1800434a4;
        pcVar6 = (char *)(submitdata_exref + 0xa10);
        FUN_180008f80(local_338,"%s.%s",pcVar6,&DAT_1800434a4);
        pcVar17 = (code *)local_338;
        pcVar13 = submitdata_exref + 0xa10;
        do {
          cVar1 = *pcVar17;
          pcVar17 = pcVar17 + 1;
          *pcVar13 = cVar1;
          pcVar13 = pcVar13 + 1;
        } while (cVar1 != (code)0x0);
      }
    }
    iVar5 = FUN_180026510((char *)0x0,(char *)(submitdata_exref + 0xa10));
    if ((iVar5 == 0) ||
       (uVar7 = FUN_180024fa0((longlong)(submitdata_exref + 0xa10)), (int)uVar7 == 0)) {
      pcVar6 = (char *)(submitdata_exref + 0xa10);
      FUN_180028920(_File,"xdef: %s\n",pcVar6,param_4);
    }
    else {
      local_388[uVar19] = submitdata_exref + 0xa10;
      lVar10 = -1;
      do {
        lVar10 = lVar10 + 1;
      } while ((submitdata_exref + 0xa10)[lVar10] != (code)0x0);
      lVar15 = lVar15 + lVar10;
      uVar19 = (ulonglong)((int)uVar19 + 1);
    }
  }
  uVar20 = uVar19;
  if (submitdata_exref[0x810] != (code)0x0) {
    iVar5 = FUN_180026510((char *)0x0,(char *)(submitdata_exref + 0x810));
    if (iVar5 != 0) {
      pcVar17 = submitdata_exref + 0x810;
      lVar10 = -(longlong)pcVar17;
      do {
        cVar1 = *pcVar17;
        pcVar17[(longlong)(local_338 + lVar10)] = cVar1;
        pcVar17 = pcVar17 + 1;
      } while (cVar1 != (code)0x0);
      pcVar9 = strchr(local_338,0x2e);
      if (pcVar9 == (char *)0x0) {
        param_4 = &DAT_1800434b4;
        pcVar6 = (char *)(submitdata_exref + 0x810);
        FUN_180008f80(local_338,"%s.%s",pcVar6,&DAT_1800434b4);
        pcVar17 = (code *)local_338;
        pcVar13 = submitdata_exref + 0x810;
        do {
          cVar1 = *pcVar17;
          pcVar17 = pcVar17 + 1;
          *pcVar13 = cVar1;
          pcVar13 = pcVar13 + 1;
        } while (cVar1 != (code)0x0);
      }
    }
    iVar5 = FUN_180026510((char *)0x0,(char *)(submitdata_exref + 0x810));
    if (iVar5 == 0) {
      pcVar6 = (char *)(submitdata_exref + 0x810);
      FUN_180028920(_File,"xslb: %s\n",pcVar6,param_4);
    }
    else {
      uVar20 = (ulonglong)((int)uVar19 + 1);
      local_388[uVar19] = submitdata_exref + 0x810;
      lVar10 = -1;
      do {
        lVar10 = lVar10 + 1;
      } while ((submitdata_exref + 0x810)[lVar10] != (code)0x0);
      lVar15 = lVar15 + lVar10;
    }
  }
  if (submitdata_exref[0x1474] != (code)0x0) {
    iVar5 = FUN_180026510((char *)0x0,(char *)(submitdata_exref + 0x1474));
    if (iVar5 != 0) {
      pcVar17 = submitdata_exref + 0x1474;
      pcVar6 = local_338 + -(longlong)pcVar17;
      do {
        cVar1 = *pcVar17;
        pcVar17[(longlong)pcVar6] = cVar1;
        pcVar17 = pcVar17 + 1;
      } while (cVar1 != (code)0x0);
      pcVar9 = strchr(local_338,0x2e);
      if (pcVar9 == (char *)0x0) {
        param_4 = &DAT_1800434c4;
        pcVar6 = (char *)(submitdata_exref + 0x1474);
        FUN_180008f80(local_338,"%s.%s",pcVar6,&DAT_1800434c4);
        pcVar17 = (code *)local_338;
        pcVar13 = submitdata_exref + 0x1474;
        do {
          cVar1 = *pcVar17;
          pcVar17 = pcVar17 + 1;
          *pcVar13 = cVar1;
          pcVar13 = pcVar13 + 1;
        } while (cVar1 != (code)0x0);
      }
    }
    iVar5 = FUN_180026510((char *)0x0,(char *)(submitdata_exref + 0x1474));
    if ((iVar5 == 0) ||
       (uVar7 = FUN_180024fa0((longlong)(submitdata_exref + 0x1474)), (int)uVar7 == 0)) {
      pcVar6 = (char *)(submitdata_exref + 0x1474);
      FUN_180028920(_File,"dlopt: %s\n",pcVar6,param_4);
    }
    else {
      local_388[uVar20] = submitdata_exref + 0x1474;
      lVar10 = -1;
      do {
        lVar10 = lVar10 + 1;
      } while ((submitdata_exref + 0x1474)[lVar10] != (code)0x0);
      lVar15 = lVar15 + lVar10;
      uVar20 = (ulonglong)((int)uVar20 + 1);
    }
  }
  if ((((byte)*Sactions_exref & 0x40) == 0) || (param_1 != (undefined *)0x0)) {
    FUN_180028920(_File,"SPONLY:\n",pcVar6,param_4);
  }
  iVar5 = (int)uVar20;
  if (iVar5 != 0) {
    pcVar6 = malloc((ulonglong)(uint)(iVar5 * 2) + lVar15 + 1);
    do {
      cVar2 = *pcVar16;
      pcVar16[(longlong)(pcVar6 + -0x180052ed0)] = cVar2;
      pcVar16 = pcVar16 + 1;
    } while (cVar2 != '\0');
    if (iVar5 != 0) {
      do {
        pcVar16 = pcVar6 + -1;
        do {
          pcVar9 = pcVar16;
          pcVar16 = pcVar9 + 1;
        } while (pcVar9[1] != '\0');
        *(undefined2 *)(pcVar9 + 1) = DAT_1800434e4;
        pcVar9[3] = DAT_1800434e6;
        pcVar16 = pcVar6 + -1;
        do {
          pcVar9 = pcVar16 + 1;
          pcVar16 = pcVar16 + 1;
        } while (*pcVar9 != '\0');
        pcVar17 = local_388[lVar18];
        lVar10 = 0;
        do {
          cVar1 = pcVar17[lVar10];
          pcVar16[lVar10] = (char)cVar1;
          lVar10 = lVar10 + 1;
        } while (cVar1 != (code)0x0);
        lVar18 = lVar18 + 1;
      } while (lVar18 < (longlong)uVar20);
    }
    pcVar16 = pcVar6 + -1;
    do {
      pcVar9 = pcVar16 + 1;
      pcVar16 = pcVar16 + 1;
    } while (*pcVar9 != '\0');
    lVar18 = 0;
    do {
      cVar2 = (&DAT_180052f50)[lVar18];
      pcVar16[lVar18] = cVar2;
      lVar18 = lVar18 + 1;
    } while (cVar2 != '\0');
    param_4 = (undefined *)0x1;
    uVar7 = FUN_180006fc0('s',pcVar6,"YN",1);
    _File = local_3c8;
    if ((int)uVar7 == 1) {
      free(pcVar6);
      fclose(_File);
      remove((char *)((longlong)&uStack_239 + 1));
      return 0xffffffff;
    }
    free(pcVar6);
  }
  if (*(longlong *)(*(longlong *)topfinfo_exref + 0x748) != 0) {
    uVar7 = AcTopConnectionString();
    FUN_180028920(_File,"DBCONN: %s\n",uVar7,param_4);
  }
  fclose(_File);
  return 0;
}

/* RVA 0x337d0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SBsetnxt(char *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  longlong lVar3;
  char *pcVar4;
  longlong lVar5;
  undefined2 *puVar6;
  int iVar7;
  undefined1 auStack_b8 [32];
  undefined1 *local_98;
  undefined1 local_88 [4];
  undefined1 local_84 [4];
  undefined1 local_80 [8];
  char *local_78;
  undefined1 local_70 [8];
  ushort local_68;
  char local_66 [78];
  ulonglong local_18;
  
                    /* 0x337d0  216  SBsetnxt */
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_b8;
  iVar7 = -1;
  if (param_2 != 0) {
    iVar7 = param_2;
  }
  if ((param_1 == (char *)0x0) || (iVar2 = strcmp(param_1,"Calculation Sequence"), iVar2 != 0)) {
    iVar2 = GRsetnxt(param_1,iVar7);
    if (iVar2 == 0) {
      return;
    }
    lVar3 = GRinqexc();
    if (lVar3 != 0) {
      return;
    }
    if (param_1 == (char *)0x0) {
LAB_1800338f1:
      pcVar4 = (char *)GRinqnxt();
    }
    else {
      FUN_1800272e0(param_1,(undefined8 *)local_70,&local_78);
      local_98 = local_88;
      local_68 = local_68 & 0xff00;
      GRqryblk(param_1,&local_68,local_80,local_84);
      lVar3 = 0;
      do {
        lVar5 = lVar3 + 1;
        if (local_70[lVar3 + 8] != (&DAT_180042bc4)[lVar3]) goto LAB_1800338f1;
        lVar3 = lVar5;
      } while (lVar5 != 7);
      lVar3 = -(longlong)local_78;
      local_68 = 0x242a;
      do {
        cVar1 = *local_78;
        local_78[(longlong)(local_66 + lVar3)] = cVar1;
        local_78 = local_78 + 1;
      } while (cVar1 != '\0');
      puVar6 = (undefined2 *)(local_70 + 7);
      do {
        pcVar4 = (char *)((longlong)puVar6 + 1);
        puVar6 = (undefined2 *)((longlong)puVar6 + 1);
      } while (*pcVar4 != '\0');
      *puVar6 = DAT_180043510;
      pcVar4 = (char *)&local_68;
    }
  }
  else {
    pcVar4 = s_Calculation_Sequence_1800515f0;
  }
  SimAnimateSequenceView(pcVar4,iVar7);
  return;
}

/* RVA 0x33930 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180033930(char *param_1,int param_2,uchar *param_3,int param_4)

{
  char cVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  size_t sVar9;
  char *pcVar10;
  size_t sVar11;
  longlong lVar12;
  int iVar13;
  int iVar14;
  char *pcVar15;
  undefined1 auStack_f8 [32];
  undefined8 local_d8;
  int local_d0;
  int local_cc;
  char local_c8 [56];
  char local_90 [56];
  ulonglong local_58;
  
  local_58 = DAT_1800516d8 ^ (ulonglong)auStack_f8;
  iVar14 = 0;
  local_d8._0_4_ = 0;
  iVar13 = *(int *)(*(longlong *)SBdataptr_exref + 0x1218);
  if (iVar13 == 0) {
    local_d8._4_4_ = 1;
  }
  else if (iVar13 == 1) {
    local_d8._4_4_ = 0;
  }
  else if (iVar13 == 2) {
    local_d8._4_4_ = 4;
  }
  iVar13 = *(int *)(auStack_f8 + (longlong)param_2 * 4 + 0x20);
  local_d0 = iVar13;
  local_cc = *(int *)(auStack_f8 + (longlong)param_4 * 4 + 0x20);
  if (iVar13 == local_cc) {
    lVar12 = (longlong)param_3 - (longlong)param_1;
    do {
      cVar1 = *param_1;
      param_1[lVar12] = cVar1;
      param_1 = param_1 + 1;
    } while (cVar1 != '\0');
    return;
  }
  lVar12 = -1;
  do {
    lVar2 = lVar12 + 1;
    lVar12 = lVar12 + 1;
  } while (param_1[lVar2] != '\0');
  pcVar6 = param_1 + lVar12;
  pcVar7 = "";
  local_90[0x30] = '\0';
  local_90[0x31] = '\0';
  pcVar15 = "";
  local_90[0x32] = 0;
  local_c8[0x30] = '\0';
  local_c8[0x31] = '\0';
  local_c8[0x32] = 0;
  local_90[0] = '\0';
  local_90[1] = '\0';
  local_90[2] = '\0';
  local_90[3] = '\0';
  local_90[4] = '\0';
  local_90[5] = '\0';
  local_90[6] = '\0';
  local_90[7] = '\0';
  local_90[8] = '\0';
  local_90[9] = '\0';
  local_90[10] = '\0';
  local_90[0xb] = '\0';
  local_90[0xc] = '\0';
  local_90[0xd] = '\0';
  local_90[0xe] = '\0';
  local_90[0xf] = '\0';
  local_90[0x10] = '\0';
  local_90[0x11] = '\0';
  local_90[0x12] = '\0';
  local_90[0x13] = '\0';
  local_90[0x14] = '\0';
  local_90[0x15] = '\0';
  local_90[0x16] = '\0';
  local_90[0x17] = '\0';
  local_90[0x18] = '\0';
  local_90[0x19] = '\0';
  local_90[0x1a] = '\0';
  local_90[0x1b] = '\0';
  local_90[0x1c] = '\0';
  local_90[0x1d] = '\0';
  local_90[0x1e] = '\0';
  local_90[0x1f] = '\0';
  local_90[0x20] = '\0';
  local_90[0x21] = '\0';
  local_90[0x22] = '\0';
  local_90[0x23] = '\0';
  local_90[0x24] = '\0';
  local_90[0x25] = '\0';
  local_90[0x26] = '\0';
  local_90[0x27] = '\0';
  local_90[0x28] = '\0';
  local_90[0x29] = '\0';
  local_90[0x2a] = '\0';
  local_90[0x2b] = '\0';
  local_90[0x2c] = '\0';
  local_90[0x2d] = '\0';
  local_90[0x2e] = '\0';
  local_90[0x2f] = '\0';
  local_c8[0] = '\0';
  local_c8[1] = '\0';
  local_c8[2] = '\0';
  local_c8[3] = '\0';
  local_c8[4] = '\0';
  local_c8[5] = '\0';
  local_c8[6] = '\0';
  local_c8[7] = '\0';
  local_c8[8] = '\0';
  local_c8[9] = '\0';
  local_c8[10] = '\0';
  local_c8[0xb] = '\0';
  local_c8[0xc] = '\0';
  local_c8[0xd] = '\0';
  local_c8[0xe] = '\0';
  local_c8[0xf] = '\0';
  local_c8[0x10] = '\0';
  local_c8[0x11] = '\0';
  local_c8[0x12] = '\0';
  local_c8[0x13] = '\0';
  local_c8[0x14] = '\0';
  local_c8[0x15] = '\0';
  local_c8[0x16] = '\0';
  local_c8[0x17] = '\0';
  local_c8[0x18] = '\0';
  local_c8[0x19] = '\0';
  local_c8[0x1a] = '\0';
  local_c8[0x1b] = '\0';
  local_c8[0x1c] = '\0';
  local_c8[0x1d] = '\0';
  local_c8[0x1e] = '\0';
  local_c8[0x1f] = '\0';
  local_c8[0x20] = '\0';
  local_c8[0x21] = '\0';
  local_c8[0x22] = '\0';
  local_c8[0x23] = '\0';
  local_c8[0x24] = '\0';
  local_c8[0x25] = '\0';
  local_c8[0x26] = '\0';
  local_c8[0x27] = '\0';
  local_c8[0x28] = '\0';
  local_c8[0x29] = '\0';
  local_c8[0x2a] = '\0';
  local_c8[0x2b] = '\0';
  local_c8[0x2c] = '\0';
  local_c8[0x2d] = '\0';
  local_c8[0x2e] = '\0';
  local_c8[0x2f] = '\0';
  pcVar8 = pcVar6;
  if (iVar13 == 0) {
    pcVar10 = "\\:";
LAB_180033bab:
    uVar5 = FUN_180033d90((ulonglong)param_1,(ulonglong)pcVar6,pcVar10,&local_d8);
    if ((int)uVar5 != 0) {
      param_1 = (char *)(CONCAT44(local_d8._4_4_,(undefined4)local_d8) + 1);
    }
    uVar5 = FUN_180033e10(param_1,pcVar6,".",&local_d8);
    if ((int)uVar5 != 0) {
      pcVar15 = (char *)CONCAT44(local_d8._4_4_,(undefined4)local_d8) + 1;
      pcVar7 = pcVar6;
      pcVar8 = (char *)CONCAT44(local_d8._4_4_,(undefined4)local_d8);
    }
  }
  else if (iVar13 == 1) {
    uVar5 = FUN_180033d90((ulonglong)param_1,(ulonglong)pcVar6,":]",&local_d8);
    if ((int)uVar5 != 0) {
      param_1 = (char *)(CONCAT44(local_d8._4_4_,(undefined4)local_d8) + 1);
    }
    uVar5 = FUN_180033e10(param_1,pcVar6,".;",&local_d8);
    if ((int)uVar5 != 0) {
      pcVar8 = (char *)CONCAT44(local_d8._4_4_,(undefined4)local_d8);
      pcVar15 = pcVar8 + 1;
      uVar5 = FUN_180033e10(pcVar15,pcVar6,".;",&local_d8);
      pcVar7 = pcVar6;
      if ((int)uVar5 != 0) {
        pcVar7 = (char *)CONCAT44(local_d8._4_4_,(undefined4)local_d8);
      }
    }
  }
  else if (iVar13 == 2) {
    pcVar8 = param_1 + 1;
    if (*param_1 != '\'') {
      pcVar8 = param_1;
    }
    param_1 = pcVar8;
    pcVar10 = pcVar6 + -1;
    if (pcVar6[-1] != '\'') {
      pcVar10 = pcVar6;
    }
    uVar5 = FUN_180033d90((ulonglong)param_1,(ulonglong)pcVar10,"(",&local_d8);
    if ((int)uVar5 != 0) {
      pcVar10 = (char *)CONCAT44(local_d8._4_4_,(undefined4)local_d8);
    }
    uVar5 = FUN_180033d90((ulonglong)param_1,(ulonglong)pcVar10,".",&local_d8);
    pcVar8 = pcVar10;
    if ((int)uVar5 != 0) {
      pcVar8 = (char *)CONCAT44(local_d8._4_4_,(undefined4)local_d8);
      pcVar15 = pcVar8 + 1;
      uVar5 = FUN_180033d90((ulonglong)param_1,(ulonglong)pcVar8,".",&local_d8);
      pcVar7 = pcVar10;
      if ((int)uVar5 != 0) {
        param_1 = (char *)(CONCAT44(local_d8._4_4_,(undefined4)local_d8) + 1);
      }
    }
  }
  else {
    if (iVar13 == 3) {
      sscanf(param_1,"%8s%8s",local_90,local_c8);
      goto LAB_180033c2d;
    }
    if (iVar13 == 4) {
      pcVar10 = "/";
      goto LAB_180033bab;
    }
    if ((((iVar13 != 0) && (iVar13 != 1)) && (iVar13 != 2)) && (iVar13 != 4)) goto LAB_180033c2d;
  }
  sVar9 = (longlong)pcVar8 - (longlong)param_1;
  if (sVar9 != 0) {
    sVar11 = 0x32;
    if ((longlong)sVar9 < 0x32) {
      sVar11 = sVar9;
    }
    memmove(local_90,param_1,sVar11);
  }
  sVar9 = (longlong)pcVar7 - (longlong)pcVar15;
  if (sVar9 != 0) {
    sVar11 = 0x32;
    if ((longlong)sVar9 < 0x32) {
      sVar11 = sVar9;
    }
    memmove(local_c8,pcVar15,sVar11);
  }
  iVar13 = local_d0;
LAB_180033c2d:
  lVar12 = 0;
  while (iVar4 = _stricmp(local_c8,*(char **)((&PTR_PTR_180051628)[iVar13] + lVar12)),
        iVar3 = local_cc, iVar4 != 0) {
    iVar14 = iVar14 + 1;
    lVar12 = lVar12 + 8;
    if (0xf < lVar12) goto LAB_180033cb1;
  }
  pcVar6 = *(char **)((&PTR_PTR_180051628)[local_cc] + (longlong)iVar14 * 8);
  pcVar15 = local_c8;
  do {
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    *pcVar15 = cVar1;
    pcVar15 = pcVar15 + 1;
  } while (cVar1 != '\0');
LAB_180033cb1:
  lVar12 = (longlong)local_cc;
  if (local_90[0] == '\0') {
    pcVar15 = (&PTR_s_BLANK_180051680)[lVar12];
    lVar2 = -(longlong)pcVar15;
    do {
      cVar1 = *pcVar15;
      pcVar15[(longlong)(local_90 + lVar2)] = cVar1;
      pcVar15 = pcVar15 + 1;
    } while (cVar1 != '\0');
  }
  if (local_c8[0] == '\0') {
    pcVar15 = (&PTR_DAT_1800516a8)[lVar12];
    lVar2 = -(longlong)pcVar15;
    do {
      cVar1 = *pcVar15;
      pcVar15[(longlong)(local_c8 + lVar2)] = cVar1;
      pcVar15 = pcVar15 + 1;
    } while (cVar1 != '\0');
  }
  if ((ulonglong)(longlong)*(int *)(&DAT_180051650 + lVar12 * 4) < 0x33) {
    local_90[*(int *)(&DAT_180051650 + lVar12 * 4)] = '\0';
    if ((ulonglong)(longlong)*(int *)(&DAT_180051668 + lVar12 * 4) < 0x33) {
      local_c8[*(int *)(&DAT_180051668 + lVar12 * 4)] = '\0';
      pcVar15 = "%s.%s";
      if (local_cc == 3) {
        pcVar15 = "%s %s";
      }
      FUN_180008f80(param_3,pcVar15,local_90,local_c8);
      if (iVar3 == 4) {
        name_lwr(param_3);
        return;
      }
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18003b6e4();
}

/* RVA 0x33d90 */
undefined8 FUN_180033d90(ulonglong param_1,ulonglong param_2,char *param_3,ulonglong *param_4)

{
  ulonglong uVar1;
  char *pcVar2;
  
  uVar1 = param_2;
  do {
    if (uVar1 <= param_1) {
      *param_4 = param_2;
      return 0;
    }
    pcVar2 = (char *)(uVar1 - 1);
    uVar1 = uVar1 - 1;
    pcVar2 = strchr(param_3,(int)*pcVar2);
  } while (pcVar2 == (char *)0x0);
  *param_4 = uVar1;
  return 1;
}

/* RVA 0x33e10 */
undefined8 FUN_180033e10(char *param_1,char *param_2,char *param_3,undefined8 *param_4)

{
  char *pcVar1;
  char *pcVar2;
  
  pcVar2 = param_1;
  while( true ) {
    if (param_2 <= pcVar2) {
      *param_4 = param_1;
      return 0;
    }
    pcVar1 = strchr(param_3,(int)*pcVar2);
    if (pcVar1 != (char *)0x0) break;
    pcVar2 = pcVar2 + 1;
  }
  *param_4 = pcVar2;
  return 1;
}

/* RVA 0x33e90 */
undefined8 FUN_180033e90(undefined8 param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 local_48 [8];
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  char *local_30;
  char *local_28;
  undefined8 local_20;
  undefined8 local_10;
  
  local_28 = "Enter directory on remote host";
  local_30 = "Enter directory on remote host";
  local_10 = 0;
  local_40 = 0x4f;
  local_3c = 0x2a;
  local_38 = 9;
  local_20 = param_1;
  iVar1 = EXstrbox(local_48,"Enter directory on remote host:");
  uVar2 = 0;
  if (iVar1 == 1) {
    uVar2 = param_1;
  }
  return uVar2;
}

/* RVA 0x33f00 */
undefined8 FUN_180033f00(undefined8 param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  undefined8 uVar2;
  char *pcVar3;
  undefined1 local_48 [8];
  undefined4 local_40;
  undefined4 local_38;
  char *local_30;
  char *local_28;
  undefined8 local_20;
  undefined8 local_10;
  
  local_40 = 0x4f;
  local_10 = 0;
  pcVar3 = "Enter filename:";
  if (((param_3 == 1) || (param_3 == 4)) || (param_3 == 5)) {
    local_38 = 10;
    local_30 = "Enter host filename";
  }
  else {
    local_38 = 8;
    local_30 = "Enter local filename";
  }
  if (param_3 == 2) {
    pcVar3 = "Local filename to send:";
  }
  else if (param_3 == 3) {
    pcVar3 = "Filename on local host:";
  }
  else if (param_3 == 4) {
    pcVar3 = "Remote filename to receive:";
  }
  else if (param_3 == 5) {
    pcVar3 = "Filename on remote host:";
  }
  local_28 = local_30;
  local_20 = param_1;
  iVar1 = EXstrbox(local_48,pcVar3);
  uVar2 = 0;
  if (iVar1 == 1) {
    uVar2 = param_1;
  }
  return uVar2;
}

/* RVA 0x33fc0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180033fc0(char *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined8 uVar4;
  undefined1 auStack_368 [32];
  char *local_348;
  char *local_340;
  int local_338 [4];
  char local_328 [256];
  char local_228 [256];
  undefined1 local_128 [272];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_368;
  local_338[0] = -1;
  iVar2 = *(int *)(*(longlong *)SBdataptr_exref + 0x1214);
  if (iVar2 == 0) {
    FUN_180028530("Should never have gotten here",-1);
  }
  else {
    if (((iVar2 == 1) || (iVar2 == 2)) || (iVar2 == 3)) {
      pcVar3 = param_1;
      do {
        cVar1 = *pcVar3;
        pcVar3[(longlong)(local_228 + -(longlong)param_1)] = cVar1;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      uVar4 = SFfmtnstr(param_1,0x101,local_128);
      FUN_180008f80(local_328,"CHDIR \"%s\"",uVar4,param_4);
      local_348 = (char *)CONCAT44(local_348._4_4_,
                                   *(undefined4 *)(*(longlong *)SBdataptr_exref + 0x1220));
      uVar4 = REMOTE_COMMAND(*(undefined4 *)(*(longlong *)SBdataptr_exref + 0x146c),local_328,
                             param_1,local_338);
      if (((int)uVar4 == 0) && (local_338[0] == 0)) {
        return uVar4;
      }
      local_348 = "Using default working directory";
      local_340 = param_1;
      FUN_180008f80(local_328,"%s %s.  %s %s.",
                    "Problem encountered during change directory process to",local_228);
    }
    FUN_180006fc0('i',local_328,"OKONLY",0);
  }
  return 0xffffffff;
}

/* RVA 0x34120 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_180034120(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined1 auStack_178 [32];
  undefined4 local_158;
  undefined8 local_150;
  undefined8 local_148;
  undefined4 local_138;
  char local_128 [256];
  ulonglong local_28;
  
  local_28 = DAT_1800516d8 ^ (ulonglong)auStack_178;
  *(uint *)(xprtdata_exref + 0x948) = *(uint *)(xprtdata_exref + 0x948) & 0xefffffff;
  pcVar2 = _getcwd(local_128,0x100);
  CUsethvr("_LDIR",pcVar2,lvars_exref,0x400);
  CUsethvr("_HDIR",param_3,lvars_exref,0x400);
  CUsethvr("_LFILE",param_1,lvars_exref,0x400);
  CUsethvr("_HFILE",param_2,lvars_exref,0x400);
  CUsubhvr(lvars_exref,local_128,*(longlong *)SBdataptr_exref + 0xe14,0);
  CUusthvr("_LDIR",lvars_exref,0x400);
  CUusthvr("_HDIR",lvars_exref,0x400);
  CUusthvr("_LFILE",lvars_exref,0x400);
  CUusthvr("_HFILE",lvars_exref,0x400);
  if (*(int *)in_graphics_exref == 0) {
    uVar3 = local_138;
  }
  else {
    uVar3 = *(undefined4 *)mask_pushed_exref;
    *(undefined4 *)mask_pushed_exref = 0;
    show_mouse();
    show_mouse();
    show_mouse();
    hide_mouse();
    push_mouse_mask(0xd);
    show_mouse();
  }
  local_148 = 0;
  local_150 = 0;
  local_158 = 0;
  uVar1 = SPAWN(*(undefined4 *)(*(longlong *)SBdataptr_exref + 0x146c),local_128,
                *(undefined4 *)(xprtdata_exref + 0x948),0);
  if (*(int *)in_graphics_exref != 0) {
    pop_mouse_mask();
    *(undefined4 *)mask_pushed_exref = uVar3;
    show_mouse();
  }
  *(uint *)(xprtdata_exref + 0x948) = *(uint *)(xprtdata_exref + 0x948) | 0x10000000;
  return uVar1;
}

/* RVA 0x34330 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_180034330(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined1 auStack_178 [32];
  undefined4 local_158;
  undefined8 local_150;
  undefined8 local_148;
  undefined4 local_138;
  char local_128 [256];
  ulonglong local_28;
  
  local_28 = DAT_1800516d8 ^ (ulonglong)auStack_178;
  *(uint *)(xprtdata_exref + 0x944) = *(uint *)(xprtdata_exref + 0x944) & 0xefffffff;
  pcVar2 = _getcwd(local_128,0x100);
  CUsethvr("_LDIR",pcVar2,lvars_exref,0x400);
  CUsethvr("_HDIR",param_3,lvars_exref,0x400);
  CUsethvr("_LFILE",param_1,lvars_exref,0x400);
  CUsethvr("_HFILE",param_2,lvars_exref,0x400);
  CUsubhvr(lvars_exref,local_128,*(longlong *)SBdataptr_exref + 0xd14,0);
  CUusthvr("_HDIR",lvars_exref,0x400);
  CUusthvr("_LFILE",lvars_exref,0x400);
  CUusthvr("_HFILE",lvars_exref,0x400);
  CUusthvr("_LDIR",lvars_exref,0x400);
  if (*(int *)in_graphics_exref == 0) {
    uVar3 = local_138;
  }
  else {
    uVar3 = *(undefined4 *)mask_pushed_exref;
    *(undefined4 *)mask_pushed_exref = 0;
    show_mouse();
    show_mouse();
    show_mouse();
    hide_mouse();
    push_mouse_mask(0xd);
    show_mouse();
  }
  local_148 = 0;
  local_150 = 0;
  local_158 = 0;
  uVar1 = SPAWN(*(undefined4 *)(*(longlong *)SBdataptr_exref + 0x146c),local_128,
                *(undefined4 *)(xprtdata_exref + 0x944),0);
  if (*(int *)in_graphics_exref != 0) {
    pop_mouse_mask();
    *(undefined4 *)mask_pushed_exref = uVar3;
    show_mouse();
  }
  *(uint *)(xprtdata_exref + 0x944) = *(uint *)(xprtdata_exref + 0x944) | 0x10000000;
  return uVar1;
}

