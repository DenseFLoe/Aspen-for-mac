/* RVA 0x34540 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_180034540(undefined8 param_1)

{
  int iVar1;
  undefined1 auStack_158 [32];
  undefined4 local_138;
  int local_128 [4];
  undefined8 local_118;
  undefined2 local_110;
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_158;
  local_110 = DAT_1800439e0;
  local_128[0] = -1;
  local_118 = DAT_1800439d8;
  local_138 = *(undefined4 *)(*(longlong *)SBdataptr_exref + 0x1220);
  iVar1 = REMOTE_COMMAND(*(undefined4 *)(*(longlong *)SBdataptr_exref + 0x146c),&local_118,param_1,
                         local_128);
  if (iVar1 == 0) {
    return -(uint)(local_128[0] != 0);
  }
  return -1;
}

/* RVA 0x345f0 */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_1800345f0(char *param_1,undefined8 param_2,undefined1 *param_3)

{
  longlong lVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  FILE *_File;
  undefined8 uVar5;
  char *pcVar6;
  int iVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  int iVar10;
  undefined1 auStack_1198 [32];
  undefined8 local_1178;
  undefined *local_1170;
  char *local_1168;
  undefined8 local_1160;
  undefined *local_1158;
  char *local_1150;
  uint local_1148;
  short local_1144 [2];
  undefined4 local_1140 [2];
  char *local_1138;
  char *local_1130;
  char local_1128 [32];
  char local_1108 [8];
  char acStack_1100 [8];
  char local_10f8 [8];
  char acStack_10f0 [8];
  char local_10e8 [8];
  char local_10e0 [472];
  undefined1 local_f08 [512];
  undefined1 local_d08 [272];
  char local_bf8 [3008];
  ulonglong local_38;
  undefined8 uStack_30;
  
  uStack_30 = 0x18003460e;
  local_38 = DAT_1800516d8 ^ (ulonglong)auStack_1198;
  iVar7 = 0;
  local_1148 = 0xffffffff;
  iVar3 = *(int *)(*(longlong *)SBdataptr_exref + 0x1468);
  iVar10 = 1000;
  if (iVar3 != 0) {
    iVar10 = iVar3;
  }
  if (*(int *)(*(longlong *)SBdataptr_exref + 0x1214) == 3) {
    FUN_1800350d0(0);
  }
  lVar1 = *(longlong *)SBdataptr_exref;
  iVar3 = *(int *)(lVar1 + 0x1218);
  if (iVar3 == 0) {
    uVar2 = *(undefined4 *)(lVar1 + 0x1220);
    pcVar6 = "GETFILE %s%s %s %d %d";
LAB_1800346d3:
    local_1168 = (char *)CONCAT44(local_1168._4_4_,uVar2);
    local_1170 = (undefined *)CONCAT44(local_1170._4_4_,iVar10);
    local_1178 = &DAT_180042a60;
    FUN_180008f80(local_f08,pcVar6,param_3,param_2);
  }
  else {
    if (iVar3 == 1) {
      SFfmtnstr(param_3,0x104,local_d08);
      param_3 = local_d08;
      pcVar6 = "GETFILE \"%s\\%s\" %s %d %d";
      uVar2 = *(undefined4 *)(*(longlong *)SBdataptr_exref + 0x1220);
      goto LAB_1800346d3;
    }
    if (iVar3 == 2) {
      uVar2 = *(undefined4 *)(lVar1 + 0x1220);
      pcVar6 = "GETFILE %s/%s %s %d %d";
      goto LAB_1800346d3;
    }
  }
  local_1178._0_4_ = *(undefined4 *)(*(longlong *)SBdataptr_exref + 0x1220);
  iVar3 = XCrcmnd(*(undefined4 *)(*(longlong *)SBdataptr_exref + 0x146c),local_f08,local_1108,
                  &local_1148);
  if ((iVar3 == 0) && (local_1148 == 0)) {
    local_1130 = local_1108;
    SFgettok(&local_1130,local_1128,0x1f);
    uVar4 = atoi(local_1128);
    FUN_180008f80(local_f08,"GETDATA %d %d",(ulonglong)uVar4,
                  (ulonglong)(1 < *(int *)(*(longlong *)SBdataptr_exref + 0x1464)));
    pcVar6 = local_1108;
    uVar5 = 0;
    local_1178._0_4_ = *(undefined4 *)(*(longlong *)SBdataptr_exref + 0x1220);
    iVar3 = XCrcmnd(*(undefined4 *)(*(longlong *)SBdataptr_exref + 0x146c),local_f08);
    if (iVar3 == 0) {
      _File = fopen(param_1,"w");
      if (_File != (FILE *)0x0) {
        do {
          uVar8 = 2;
          lVar1 = *(longlong *)SBdataptr_exref;
          uVar9 = (ulonglong)*(uint *)(lVar1 + 0x1220);
          iVar3 = XCread((uint)(1 < *(int *)(lVar1 + 0x1464)) + *(int *)(lVar1 + 0x146c),local_1144)
          ;
          if (iVar3 < 1) {
            GetLastXCerror(local_1140,&local_1138);
            local_1168 = local_1138;
            local_1170 = &DAT_180043860;
            local_1178._0_4_ = local_1140[0];
            FUN_180008f80(local_1108,"%s%s%d%s%s","Failed to read header info.  ","Error is: ");
            fclose(_File);
            goto LAB_180034b03;
          }
          uVar4 = (uint)local_1144[0];
          if ((int)uVar4 < 1) {
            if (uVar4 != 0) {
LAB_180034a72:
              pcVar6 = "Header information is corrupted.";
LAB_18003499e:
              FUN_180008f80(local_1108,pcVar6,uVar8,uVar9);
              fclose(_File);
              goto LAB_180034b03;
            }
            FUN_180008f80(local_1108,"finished reading - got 0",uVar8,uVar9);
            break;
          }
          if (iVar10 < (int)uVar4) goto LAB_180034a72;
          uVar8 = (ulonglong)uVar4;
          lVar1 = *(longlong *)SBdataptr_exref;
          uVar9 = (ulonglong)*(uint *)(lVar1 + 0x1220);
          local_1148 = XCread((uint)(1 < *(int *)(lVar1 + 0x1464)) + *(int *)(lVar1 + 0x146c),
                              local_bf8);
          while( true ) {
            if ((int)local_1148 < 1) {
              local_1160._4_4_ = (undefined4)((ulonglong)local_1160 >> 0x20);
              GetLastXCerror(local_1140,&local_1138);
              local_1150 = local_1138;
              local_1158 = &DAT_180043860;
              local_1160 = (char *)CONCAT44(local_1160._4_4_,local_1140[0]);
              local_1168 = "- Error is: ";
              local_1170 = (undefined *)CONCAT44(local_1170._4_4_,local_1148);
              local_1178._0_4_ = 0x800438c8;
              local_1178._4_4_ = 1;
              FUN_180008f80(local_1108,"%s%d.  %s%d %s%d%s%s",
                            "Read from host failed trying to read ",(ulonglong)uVar4);
              fclose(_File);
              goto LAB_180034b03;
            }
            if (2999 < (ulonglong)local_1148) {
                    /* WARNING: Subroutine does not return */
              FUN_18003b6e4();
            }
            local_bf8[local_1148] = '\0';
            iVar3 = fputs(local_bf8,_File);
            if (iVar3 == -1) {
              pcVar6 = "could not write info to file";
              goto LAB_18003499e;
            }
            fflush(_File);
            if ((int)uVar4 <= (int)local_1148) break;
            uVar4 = uVar4 - local_1148;
            uVar8 = (ulonglong)uVar4;
            lVar1 = *(longlong *)SBdataptr_exref;
            uVar9 = (ulonglong)*(uint *)(lVar1 + 0x1220);
            local_1148 = XCread((uint)(1 < *(int *)(lVar1 + 0x1464)) + *(int *)(lVar1 + 0x146c),
                                local_bf8);
          }
        } while (uVar4 != 0);
        fclose(_File);
      }
      local_1178._0_4_ = *(undefined4 *)(*(longlong *)SBdataptr_exref + 0x1220);
      iVar3 = XCrcmnd(*(undefined4 *)(*(longlong *)SBdataptr_exref + 0x146c),0,local_1108,
                      &local_1148);
      if ((iVar3 == 0) && (local_1148 == 0)) goto LAB_180034b08;
      GetLastXCerror(local_1140,&local_1138);
      local_1160 = "  File may be corrupted.";
      local_1168 = local_1138;
      local_1170 = &DAT_180043860;
      local_1178._0_4_ = local_1140[0];
      FUN_180008f80(local_1108,"%s%s%d%s%s%s","Receive final handshaking failed.  ","Error is: ");
      fclose(_File);
    }
    else {
      FUN_180008f80(local_1108,"could not GETDATA from xcserver",pcVar6,uVar5);
    }
  }
  else {
    local_10e0[0] = s_Unable_to_initiate_internal_file_180043690[0x28];
    local_10e0[1] = s_Unable_to_initiate_internal_file_180043690[0x29];
    local_1108[0] = s_Unable_to_initiate_internal_file_180043690[0];
    local_1108[1] = s_Unable_to_initiate_internal_file_180043690[1];
    local_1108[2] = s_Unable_to_initiate_internal_file_180043690[2];
    local_1108[3] = s_Unable_to_initiate_internal_file_180043690[3];
    local_1108[4] = s_Unable_to_initiate_internal_file_180043690[4];
    local_1108[5] = s_Unable_to_initiate_internal_file_180043690[5];
    local_1108[6] = s_Unable_to_initiate_internal_file_180043690[6];
    local_1108[7] = s_Unable_to_initiate_internal_file_180043690[7];
    acStack_1100[0] = s_Unable_to_initiate_internal_file_180043690[8];
    acStack_1100[1] = s_Unable_to_initiate_internal_file_180043690[9];
    acStack_1100[2] = s_Unable_to_initiate_internal_file_180043690[10];
    acStack_1100[3] = s_Unable_to_initiate_internal_file_180043690[0xb];
    acStack_1100[4] = s_Unable_to_initiate_internal_file_180043690[0xc];
    acStack_1100[5] = s_Unable_to_initiate_internal_file_180043690[0xd];
    acStack_1100[6] = s_Unable_to_initiate_internal_file_180043690[0xe];
    acStack_1100[7] = s_Unable_to_initiate_internal_file_180043690[0xf];
    local_10e8[0] = s_Unable_to_initiate_internal_file_180043690[0x20];
    local_10e8[1] = s_Unable_to_initiate_internal_file_180043690[0x21];
    local_10e8[2] = s_Unable_to_initiate_internal_file_180043690[0x22];
    local_10e8[3] = s_Unable_to_initiate_internal_file_180043690[0x23];
    local_10e8[4] = s_Unable_to_initiate_internal_file_180043690[0x24];
    local_10e8[5] = s_Unable_to_initiate_internal_file_180043690[0x25];
    local_10e8[6] = s_Unable_to_initiate_internal_file_180043690[0x26];
    local_10e8[7] = s_Unable_to_initiate_internal_file_180043690[0x27];
    local_10f8[0] = s_Unable_to_initiate_internal_file_180043690[0x10];
    local_10f8[1] = s_Unable_to_initiate_internal_file_180043690[0x11];
    local_10f8[2] = s_Unable_to_initiate_internal_file_180043690[0x12];
    local_10f8[3] = s_Unable_to_initiate_internal_file_180043690[0x13];
    local_10f8[4] = s_Unable_to_initiate_internal_file_180043690[0x14];
    local_10f8[5] = s_Unable_to_initiate_internal_file_180043690[0x15];
    local_10f8[6] = s_Unable_to_initiate_internal_file_180043690[0x16];
    local_10f8[7] = s_Unable_to_initiate_internal_file_180043690[0x17];
    acStack_10f0[0] = s_Unable_to_initiate_internal_file_180043690[0x18];
    acStack_10f0[1] = s_Unable_to_initiate_internal_file_180043690[0x19];
    acStack_10f0[2] = s_Unable_to_initiate_internal_file_180043690[0x1a];
    acStack_10f0[3] = s_Unable_to_initiate_internal_file_180043690[0x1b];
    acStack_10f0[4] = s_Unable_to_initiate_internal_file_180043690[0x1c];
    acStack_10f0[5] = s_Unable_to_initiate_internal_file_180043690[0x1d];
    acStack_10f0[6] = s_Unable_to_initiate_internal_file_180043690[0x1e];
    acStack_10f0[7] = s_Unable_to_initiate_internal_file_180043690[0x1f];
  }
LAB_180034b03:
  iVar7 = -1;
LAB_180034b08:
  if (*(int *)(*(longlong *)SBdataptr_exref + 0x1214) == 3) {
    FUN_1800350d0(1);
  }
  if (iVar7 == 0) {
    uVar5 = 0;
  }
  else {
    FUN_180028530(local_1108,-1);
    uVar5 = 0xffffffff;
  }
  return uVar5;
}

/* RVA 0x34b70 */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180034b70(char *param_1,undefined8 param_2,undefined1 *param_3)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  FILE *_File;
  size_t sVar5;
  undefined8 uVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  undefined1 auStack_1298 [32];
  undefined *local_1278;
  undefined8 local_1270;
  undefined4 local_1268;
  undefined2 local_1258 [2];
  undefined4 local_1254;
  int local_1250 [2];
  undefined8 local_1248;
  int local_1240 [2];
  char *local_1238;
  char local_1230 [40];
  char local_1208 [8];
  char acStack_1200 [8];
  char local_11f8 [8];
  char acStack_11f0 [8];
  char local_11e8 [8];
  char local_11e0 [472];
  undefined1 local_1008 [512];
  undefined1 local_e08 [272];
  undefined1 local_cf8 [256];
  undefined2 local_bf8;
  undefined1 local_bf6 [3006];
  ulonglong local_38;
  undefined8 uStack_30;
  
  uStack_30 = 0x180034b8e;
  local_38 = DAT_1800516d8 ^ (ulonglong)auStack_1298;
  iVar9 = 0;
  local_1250[0] = -1;
  iVar3 = *(int *)(*(longlong *)SBdataptr_exref + 0x1468);
  iVar4 = 1000;
  if (iVar3 != 0) {
    iVar4 = iVar3;
  }
  if (*(int *)(*(longlong *)SBdataptr_exref + 0x1214) == 3) {
    FUN_1800350d0(0);
  }
  lVar1 = *(longlong *)SBdataptr_exref;
  iVar3 = *(int *)(lVar1 + 0x1218);
  if (iVar3 == 0) {
    local_1268 = *(undefined4 *)(lVar1 + 0x1220);
    pcVar7 = "PUTFILE %s%s %s %d %d";
LAB_180034c51:
    local_1270 = CONCAT44(local_1270._4_4_,iVar4);
    local_1278 = &DAT_180042a60;
    FUN_180008f80(local_1008,pcVar7,param_3,param_2);
  }
  else {
    if (iVar3 == 1) {
      SFfmtnstr(param_3,0x104,local_e08);
      param_3 = local_e08;
      pcVar7 = "PUTFILE \"%s\\%s\" %s %d %d";
      local_1268 = *(undefined4 *)(*(longlong *)SBdataptr_exref + 0x1220);
      goto LAB_180034c51;
    }
    if (iVar3 == 2) {
      local_1268 = *(undefined4 *)(lVar1 + 0x1220);
      pcVar7 = "PUTFILE %s/%s %s %d %d";
      goto LAB_180034c51;
    }
  }
  local_1278._0_4_ = *(undefined4 *)(*(longlong *)SBdataptr_exref + 0x1220);
  local_1240[0] =
       XCrcmnd(*(undefined4 *)(*(longlong *)SBdataptr_exref + 0x146c),local_1008,local_1208,
               local_1250);
  if ((local_1240[0] == 0) && (local_1250[0] == 0)) {
    local_1238 = local_1208;
    SFgettok(&local_1238,local_1230,0x1f);
    uVar2 = atoi(local_1230);
    SFgettok(&local_1238,local_1230,0x1f);
    iVar3 = atoi(local_1230);
    FUN_180008f80(local_1008,"PUTDATA %d %d",(ulonglong)uVar2,
                  (ulonglong)(1 < *(int *)(*(longlong *)SBdataptr_exref + 0x1464)));
    piVar10 = local_1250;
    pcVar7 = local_1208;
    local_1278._0_4_ = *(undefined4 *)(*(longlong *)SBdataptr_exref + 0x1220);
    iVar4 = XCrcmnd(*(undefined4 *)(*(longlong *)SBdataptr_exref + 0x146c),local_1008);
    if ((iVar4 == 0) || (local_1250[0] == 0)) {
      _File = fopen(param_1,"r");
      if (_File == (FILE *)0x0) goto LAB_180035062;
      iVar4 = feof(_File);
      if (iVar4 == 0) {
        do {
          sVar5 = fread(local_bf6,1,(longlong)(iVar3 + -2),_File);
          if ((int)sVar5 < 1) break;
          iVar8 = (int)sVar5 + 2;
          local_1258[0] = (undefined2)sVar5;
          local_bf8 = local_1258[0];
          iVar4 = XCread((uint)(1 < *(int *)(*(longlong *)SBdataptr_exref + 0x1464)) +
                         *(int *)(*(longlong *)SBdataptr_exref + 0x146c),local_cf8,0x100,0);
          if ((iVar4 < 0) || (local_1240[0] < 0)) {
            GetLastXCerror(&local_1254,&local_1248);
            local_1270 = local_1248;
            local_1278._0_4_ = local_1254;
            FUN_180008f80(local_1208,"%s.  %s%d - %s","Internal send failed-packets were dropped",
                          "Error is: ");
            iVar9 = -1;
            fclose(_File);
            goto LAB_180035062;
          }
          lVar1 = *(longlong *)SBdataptr_exref;
          iVar4 = XCwrite((uint)(1 < *(int *)(lVar1 + 0x1464)) + *(int *)(lVar1 + 0x146c),&local_bf8
                          ,iVar8,*(undefined4 *)(lVar1 + 0x1220));
          if (iVar4 < 1) {
            GetLastXCerror(&local_1254,&local_1248);
            pcVar7 = "Internal send data failed";
LAB_180034f3c:
            local_1270 = local_1248;
            local_1278._0_4_ = local_1254;
            FUN_180008f80(local_1208,"%s.  %s%d - %s",pcVar7,"Error is: ");
            fclose(_File);
            goto LAB_18003505d;
          }
          if (iVar4 < iVar8) {
            GetLastXCerror(&local_1254,&local_1248);
            pcVar7 = "Internal send data timed out";
            goto LAB_180034f3c;
          }
          iVar4 = feof(_File);
        } while (iVar4 == 0);
      }
      fclose(_File);
      local_1258[0] = 0;
      lVar1 = *(longlong *)SBdataptr_exref;
      iVar3 = XCwrite((uint)(1 < *(int *)(lVar1 + 0x1464)) + *(int *)(lVar1 + 0x146c),local_1258,2,
                      *(undefined4 *)(lVar1 + 0x1220));
      if (iVar3 < 1) {
        GetLastXCerror(&local_1254,&local_1248);
        pcVar7 = "Internal send data failed on final write";
      }
      else {
        local_1278._0_4_ = *(undefined4 *)(*(longlong *)SBdataptr_exref + 0x1220);
        iVar3 = XCrcmnd(*(undefined4 *)(*(longlong *)SBdataptr_exref + 0x146c),0,local_1208,
                        local_1240);
        if ((-1 < iVar3) && (-1 < local_1240[0])) goto LAB_180035062;
        GetLastXCerror(&local_1254,&local_1248);
        pcVar7 = "Internal send data failed on final read";
      }
      local_1270 = local_1248;
      local_1278._0_4_ = local_1254;
      FUN_180008f80(local_1208,"%s.  %s%d - %s",pcVar7,"Error is: ");
    }
    else {
      FUN_180008f80(local_1208,"could not initiate PUTDATA to xcserver",pcVar7,piVar10);
    }
  }
  else {
    local_11e0[0] = s_Unable_to_initiate_internal_file_180043690[0x28];
    local_11e0[1] = s_Unable_to_initiate_internal_file_180043690[0x29];
    local_1208[0] = s_Unable_to_initiate_internal_file_180043690[0];
    local_1208[1] = s_Unable_to_initiate_internal_file_180043690[1];
    local_1208[2] = s_Unable_to_initiate_internal_file_180043690[2];
    local_1208[3] = s_Unable_to_initiate_internal_file_180043690[3];
    local_1208[4] = s_Unable_to_initiate_internal_file_180043690[4];
    local_1208[5] = s_Unable_to_initiate_internal_file_180043690[5];
    local_1208[6] = s_Unable_to_initiate_internal_file_180043690[6];
    local_1208[7] = s_Unable_to_initiate_internal_file_180043690[7];
    acStack_1200[0] = s_Unable_to_initiate_internal_file_180043690[8];
    acStack_1200[1] = s_Unable_to_initiate_internal_file_180043690[9];
    acStack_1200[2] = s_Unable_to_initiate_internal_file_180043690[10];
    acStack_1200[3] = s_Unable_to_initiate_internal_file_180043690[0xb];
    acStack_1200[4] = s_Unable_to_initiate_internal_file_180043690[0xc];
    acStack_1200[5] = s_Unable_to_initiate_internal_file_180043690[0xd];
    acStack_1200[6] = s_Unable_to_initiate_internal_file_180043690[0xe];
    acStack_1200[7] = s_Unable_to_initiate_internal_file_180043690[0xf];
    local_11e8[0] = s_Unable_to_initiate_internal_file_180043690[0x20];
    local_11e8[1] = s_Unable_to_initiate_internal_file_180043690[0x21];
    local_11e8[2] = s_Unable_to_initiate_internal_file_180043690[0x22];
    local_11e8[3] = s_Unable_to_initiate_internal_file_180043690[0x23];
    local_11e8[4] = s_Unable_to_initiate_internal_file_180043690[0x24];
    local_11e8[5] = s_Unable_to_initiate_internal_file_180043690[0x25];
    local_11e8[6] = s_Unable_to_initiate_internal_file_180043690[0x26];
    local_11e8[7] = s_Unable_to_initiate_internal_file_180043690[0x27];
    local_11f8[0] = s_Unable_to_initiate_internal_file_180043690[0x10];
    local_11f8[1] = s_Unable_to_initiate_internal_file_180043690[0x11];
    local_11f8[2] = s_Unable_to_initiate_internal_file_180043690[0x12];
    local_11f8[3] = s_Unable_to_initiate_internal_file_180043690[0x13];
    local_11f8[4] = s_Unable_to_initiate_internal_file_180043690[0x14];
    local_11f8[5] = s_Unable_to_initiate_internal_file_180043690[0x15];
    local_11f8[6] = s_Unable_to_initiate_internal_file_180043690[0x16];
    local_11f8[7] = s_Unable_to_initiate_internal_file_180043690[0x17];
    acStack_11f0[0] = s_Unable_to_initiate_internal_file_180043690[0x18];
    acStack_11f0[1] = s_Unable_to_initiate_internal_file_180043690[0x19];
    acStack_11f0[2] = s_Unable_to_initiate_internal_file_180043690[0x1a];
    acStack_11f0[3] = s_Unable_to_initiate_internal_file_180043690[0x1b];
    acStack_11f0[4] = s_Unable_to_initiate_internal_file_180043690[0x1c];
    acStack_11f0[5] = s_Unable_to_initiate_internal_file_180043690[0x1d];
    acStack_11f0[6] = s_Unable_to_initiate_internal_file_180043690[0x1e];
    acStack_11f0[7] = s_Unable_to_initiate_internal_file_180043690[0x1f];
  }
LAB_18003505d:
  iVar9 = -1;
LAB_180035062:
  if (*(int *)(*(longlong *)SBdataptr_exref + 0x1214) == 3) {
    FUN_1800350d0(1);
  }
  if (iVar9 == 0) {
    uVar6 = 0;
  }
  else {
    FUN_180028530(local_1208,-1);
    uVar6 = 0xffffffff;
  }
  return uVar6;
}

/* RVA 0x350d0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_1800350d0(uint param_1)

{
  int iVar1;
  undefined1 auStack_258 [32];
  undefined4 local_238;
  int local_228 [4];
  undefined1 local_218 [256];
  undefined1 local_118 [256];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_258;
  FUN_180008f80(local_218,"%s %d","PROXYIO",(ulonglong)param_1);
  local_238 = *(undefined4 *)(*(longlong *)SBdataptr_exref + 0x1220);
  iVar1 = XCrcmnd(*(undefined4 *)(*(longlong *)SBdataptr_exref + 0x146c),local_218,local_118,
                  local_228);
  if (iVar1 == 0) {
    return -(uint)(local_228[0] != 0);
  }
  return -1;
}

/* RVA 0x35180 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180035180(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 auStack_278 [32];
  undefined4 local_258;
  undefined1 local_248 [272];
  undefined1 local_138 [272];
  ulonglong local_28;
  
  local_28 = DAT_1800516d8 ^ (ulonglong)auStack_278;
  SFfmtnstr(param_2,0x104,local_138);
  FUN_180008f80(local_248,"%s \"%s\"",param_1,local_138);
  local_258 = *(undefined4 *)(*(longlong *)SBdataptr_exref + 0x1220);
  REMOTE_COMMAND(*(undefined4 *)(*(longlong *)SBdataptr_exref + 0x146c),local_248,param_3,param_4);
  return;
}

/* RVA 0x35230 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180035230(undefined8 param_1,undefined1 *param_2,undefined1 *param_3,undefined8 param_4,
                  undefined8 param_5)

{
  char *pcVar1;
  undefined1 auStack_398 [32];
  undefined1 *local_378;
  undefined1 local_368 [272];
  undefined1 local_258 [272];
  undefined1 local_148 [272];
  ulonglong local_38;
  
  local_38 = DAT_1800516d8 ^ (ulonglong)auStack_398;
  if (*(int *)(*(longlong *)SBdataptr_exref + 0x1218) == 1) {
    SFfmtnstr(param_2,0x104,local_258);
    SFfmtnstr(param_3,0x104,local_148);
    pcVar1 = "%s \"%s\" \"%s\"";
    param_2 = local_258;
    param_3 = local_148;
  }
  else {
    pcVar1 = "%s \"%s %s\"";
  }
  local_378 = param_3;
  FUN_180008f80(local_368,pcVar1,param_1,param_2);
  local_378 = (undefined1 *)
              CONCAT44(local_378._4_4_,*(undefined4 *)(*(longlong *)SBdataptr_exref + 0x1220));
  REMOTE_COMMAND(*(undefined4 *)(*(longlong *)SBdataptr_exref + 0x146c),local_368,param_4,param_5);
  return;
}

/* RVA 0x35320 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180035320(undefined8 param_1,undefined8 param_2,int *param_3,undefined8 param_4)

{
  undefined8 uVar1;
  int *piVar2;
  undefined1 auStack_268 [32];
  undefined4 local_248;
  char local_238 [8];
  char local_230 [264];
  undefined1 local_128 [272];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_268;
  if (*(int *)(*(longlong *)SBdataptr_exref + 0x1218) == 1) {
    uVar1 = SFfmtnstr(param_1,0x101,local_128);
    FUN_180008f80(local_238,"GETENV U \"%s\"",uVar1,param_4);
    local_248 = *(undefined4 *)(*(longlong *)SBdataptr_exref + 0x1220);
    piVar2 = param_3;
    uVar1 = XCrcmnd(*(undefined4 *)(*(longlong *)SBdataptr_exref + 0x146c),local_238,param_2);
    if (((int)uVar1 != 0) || (*param_3 != 0)) {
      local_238[0] = s_GETENV_M_180043ad0[0];
      local_238[1] = s_GETENV_M_180043ad0[1];
      local_238[2] = s_GETENV_M_180043ad0[2];
      local_238[3] = s_GETENV_M_180043ad0[3];
      local_238[4] = s_GETENV_M_180043ad0[4];
      local_238[5] = s_GETENV_M_180043ad0[5];
      local_238[6] = s_GETENV_M_180043ad0[6];
      local_238[7] = s_GETENV_M_180043ad0[7];
      local_230[0] = s_GETENV_M_180043ad0[8];
      local_230[1] = s_GETENV_M_180043ad0[9];
      FUN_180008f80(local_238,"GETENV M \"%s\"",local_128,piVar2);
      local_248 = *(undefined4 *)(*(longlong *)SBdataptr_exref + 0x1220);
      uVar1 = XCrcmnd(*(undefined4 *)(*(longlong *)SBdataptr_exref + 0x146c),local_238,param_2,
                      param_3);
    }
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* RVA 0x35440 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_180035440(char param_1,undefined8 param_2,undefined8 param_3,int *param_4)

{
  uint uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined1 auStack_278 [32];
  undefined4 local_258;
  undefined1 local_248 [272];
  undefined1 local_138 [272];
  ulonglong local_28;
  
  local_28 = DAT_1800516d8 ^ (ulonglong)auStack_278;
  uVar4 = 0xffffffff;
  if (((*(int *)(*(longlong *)SBdataptr_exref + 0x1218) == 1) &&
      (uVar1 = (int)param_1 - 0x43, (byte)uVar1 < 0x13)) && ((0x40401U >> (uVar1 & 0x1f) & 1) != 0))
  {
    uVar2 = SFfmtnstr(param_2,0x101,local_138);
    FUN_180008f80(local_248,"GETENV %c \"%s\"",(ulonglong)(uint)(int)param_1,uVar2);
    local_258 = *(undefined4 *)(*(longlong *)SBdataptr_exref + 0x1220);
    uVar3 = XCrcmnd(*(undefined4 *)(*(longlong *)SBdataptr_exref + 0x146c),local_248,param_3,param_4
                   );
    uVar4 = uVar3 & 0xffffffff;
    if (((int)uVar3 == 0) && (*param_4 == 0)) {
      return uVar3;
    }
  }
  return uVar4;
}

/* RVA 0x35520 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180035520(char *param_1,undefined8 param_2,undefined4 *param_3,undefined8 param_4)

{
  int iVar1;
  char *pcVar2;
  undefined8 uVar3;
  undefined1 auStack_4b8 [32];
  char *local_498;
  undefined4 local_488 [4];
  undefined1 local_478 [272];
  undefined1 local_368 [272];
  char local_258 [272];
  undefined1 local_148 [272];
  ulonglong local_38;
  
  local_38 = DAT_1800516d8 ^ (ulonglong)auStack_4b8;
  local_488[0] = 0xffffffff;
  if (*(int *)(*(longlong *)SBdataptr_exref + 0x1218) == 1) {
    iVar1 = FUN_1800269c0("getridof.exe",local_368);
    if ((iVar1 != 0) && (iVar1 = FUN_1800269c0("getridof.bat",local_368), iVar1 != 0)) {
      return;
    }
    pcVar2 = strstr((char *)(*(longlong *)SBdataptr_exref + 0x10),"\\\\");
    if (pcVar2 != (char *)0x0) {
      FUN_180026860((char *)(*(longlong *)SBdataptr_exref + 0x10),param_1,local_258,1);
      param_1 = local_258;
    }
    local_498 = "";
    if ((int)param_4 != 0) {
      local_498 = "/NOWAIT";
    }
    FUN_180008f80(local_478,"%s %s /quiet %s",local_368,param_1);
    SFfmtnstr(local_478,0x101,local_368);
    FUN_180008f80(local_478,"%s \"%s\"","SPAWN",local_368);
    param_3 = local_488;
  }
  else {
    uVar3 = SFfmtnstr(param_1,0x104,local_148);
    FUN_180008f80(local_478,"GETRID \"%s\"",uVar3,param_4);
  }
  local_498 = (char *)CONCAT44(local_498._4_4_,
                               *(undefined4 *)(*(longlong *)SBdataptr_exref + 0x1220));
  REMOTE_COMMAND(*(undefined4 *)(*(longlong *)SBdataptr_exref + 0x146c),local_478,param_2,param_3);
  return;
}

/* RVA 0x356d0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_1800356d0(void)

{
  int iVar1;
  ulonglong uVar2;
  undefined1 auStack_468 [32];
  undefined4 local_448;
  undefined8 local_440;
  undefined8 local_438;
  uint local_428 [4];
  undefined1 local_418 [256];
  undefined1 local_318 [256];
  undefined1 local_218 [256];
  undefined1 local_118 [256];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_468;
  CUsubhvr(lvars_exref,local_418,*(longlong *)SBdataptr_exref + 0xc14,0);
  iVar1 = *(int *)(*(longlong *)SBdataptr_exref + 0x1214);
  if ((iVar1 == 1) || (iVar1 == 2)) {
    local_438 = 0;
    local_440 = 0;
    local_448 = 0;
    uVar2 = SPAWN(DAT_180052d78,local_418,*(undefined4 *)(xprtdata_exref + 0x94c),0);
    return uVar2;
  }
  if (iVar1 == 3) {
    CUsubhvr(lvars_exref,local_318,*(longlong *)SBdataptr_exref + 0x1574,0);
    FUN_180008f80(local_218,"%s \"%s\"","REMTALK",local_318);
    local_448 = *(undefined4 *)(*(longlong *)SBdataptr_exref + 0x1220);
    REMOTE_COMMAND(*(undefined4 *)(*(longlong *)SBdataptr_exref + 0x146c),local_218,0,0);
    local_438 = 0;
    local_440 = 0;
    local_448 = 0;
    SPAWN(DAT_180052d78,local_418,*(undefined4 *)(xprtdata_exref + 0x94c),0);
    local_448 = *(undefined4 *)(*(longlong *)SBdataptr_exref + 0x1220);
    uVar2 = REMOTE_COMMAND(*(undefined4 *)(*(longlong *)SBdataptr_exref + 0x146c),0,local_118,
                           local_428);
    return uVar2;
  }
  return (ulonglong)local_428[0];
}

/* RVA 0x35890 */
ulonglong BinaryAnalysis(undefined8 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  ulonglong uVar5;
  undefined4 uVar6;
  undefined4 local_res10 [2];
  
                    /* 0x35890  58  BinaryAnalysis */
  uVar5 = 0;
  uVar1 = GRinqcpt();
  uVar2 = GRinqpgc();
  uVar3 = GRinqnec();
  uVar4 = GRinqgpd();
  GRset_in_canned(1);
  GRcreateAnalysisSumbuf();
  SMSetPropTableID(param_1,0);
  SMgenpropset(local_res10);
  switch(local_res10[0]) {
  case 0:
    uVar6 = 3;
    break;
  case 1:
    uVar6 = 4;
    break;
  case 2:
    uVar6 = 5;
    break;
  case 3:
    uVar6 = 0x10;
    break;
  case 4:
    uVar6 = 0x11;
    break;
  case 5:
    uVar6 = 0x12;
    break;
  default:
    goto switchD_180035907_default;
  }
  uVar5 = FUN_180038a30(0,0,uVar6,"BINARY");
  uVar5 = uVar5 & 0xffffffff;
switchD_180035907_default:
  GRsetpgc(uVar2);
  GRsetnec(uVar3);
  GRsetcpt(uVar1);
  GRsetgpd(uVar4);
  GRmoveAnalysisSumbuf();
  GRdeleteAnalysisSumbuf();
  GRset_in_canned(0);
  return uVar5;
}

/* RVA 0x359c0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 BubbleAnalysis(void)

{
  bool bVar1;
  undefined7 extraout_var;
  undefined8 uVar2;
  undefined1 auStack_178 [32];
  undefined8 local_158;
  code *local_150;
  undefined8 local_148 [38];
  ulonglong local_18;
  
                    /* 0x359c0  90  BubbleAnalysis */
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_178;
  bVar1 = FUN_180035c00(local_148);
  if ((int)CONCAT71(extraout_var,bVar1) == 0) {
    uVar2 = 0;
  }
  else {
    local_150 = _guard_check_icall;
    local_158 = 0;
    uVar2 = FUN_180038a30((longlong)local_148,1,9,"BUBBLE");
  }
  _DAT_180052fd0 = 0;
  return uVar2;
}

/* RVA 0x35a40 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 CompflAnalysis(void)

{
  bool bVar1;
  undefined7 extraout_var;
  undefined8 uVar2;
  undefined1 auStack_178 [32];
  undefined8 local_158;
  code *local_150;
  undefined8 local_148 [38];
  ulonglong local_18;
  
                    /* 0x35a40  86  CompflAnalysis */
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_178;
  bVar1 = FUN_180035c00(local_148);
  if ((int)CONCAT71(extraout_var,bVar1) == 0) {
    uVar2 = 0;
  }
  else {
    local_150 = _guard_check_icall;
    local_158 = 0;
    uVar2 = FUN_180038a30((longlong)local_148,1,0xfffffffe,"COMPFL");
  }
  _DAT_180052fd0 = 0;
  return uVar2;
}

/* RVA 0x35ac0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 CompsiAnalysis(void)

{
  bool bVar1;
  undefined7 extraout_var;
  undefined8 uVar2;
  undefined1 auStack_178 [32];
  undefined8 local_158;
  code *local_150;
  undefined8 local_148 [38];
  ulonglong local_18;
  
                    /* 0x35ac0  87  CompsiAnalysis */
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_178;
  bVar1 = FUN_180035c00(local_148);
  if ((int)CONCAT71(extraout_var,bVar1) == 0) {
    uVar2 = 0;
  }
  else {
    local_150 = _guard_check_icall;
    local_158 = 0;
    uVar2 = FUN_180038a30((longlong)local_148,1,0xfffffffd,"COMPSI");
  }
  _DAT_180052fd0 = 0;
  return uVar2;
}

/* RVA 0x35b40 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DiscurAnalysis(void)

{
  bool bVar1;
  undefined7 extraout_var;
  undefined8 uVar2;
  undefined1 auStack_178 [32];
  undefined8 local_158;
  code *local_150;
  undefined8 local_148 [38];
  ulonglong local_18;
  
                    /* 0x35b40  89  DiscurAnalysis */
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_178;
  bVar1 = FUN_180035c00(local_148);
  if ((int)CONCAT71(extraout_var,bVar1) == 0) {
    uVar2 = 0;
  }
  else {
    local_150 = _guard_check_icall;
    local_158 = 0;
    uVar2 = FUN_180038a30((longlong)local_148,1,0xfffffffb,"DISCUR");
  }
  _DAT_180052fd0 = 0;
  return uVar2;
}

/* RVA 0x35bc0 */
void GeneralAnalysis(void)

{
                    /* 0x35bc0  65  GeneralAnalysis */
  FUN_180038a30(0,0,1,"GENERAL");
  return;
}

/* RVA 0x35c00 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_180035c00(undefined8 *param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  longlong lVar4;
  undefined8 uVar5;
  longlong lVar6;
  char *pcVar7;
  undefined8 uVar8;
  char *pcVar9;
  undefined1 auStack_198 [32];
  char *local_178;
  undefined8 local_170;
  char *local_168;
  longlong local_160;
  longlong local_158;
  undefined8 local_100;
  longlong local_f0;
  longlong local_e0;
  undefined8 local_d8;
  longlong local_c8;
  longlong local_90;
  int *local_50;
  undefined1 local_38 [8];
  undefined8 local_30;
  char local_28 [16];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_198;
  DAT_180052fe0 = '\0';
  memset(&local_168,0,0x128);
  local_158 = *(longlong *)(analysis_ditem_exref + 8);
  local_160 = *(longlong *)analysis_ditem_exref;
  if ((local_158 != -1) && (local_160 != -1)) {
    local_90 = MDfndito(*(undefined8 *)iwpfile_exref);
    MDgetrdf(&local_168);
    lVar4 = MDrslcls(*(undefined8 *)recfile_exref,local_d8);
    pcVar7 = (char *)(lVar4 + local_e0 * 0x108);
    if (pcVar7 == (char *)0x0) {
LAB_180035d52:
      local_168 = "STREAMNAME";
      local_c8 = MDfndrbv(local_100,local_f0);
      if (local_c8 == 0) {
        return false;
      }
      lVar4 = MDgetvar(&local_168);
      if (lVar4 == 0) {
        return false;
      }
      pcVar9 = &DAT_180052fe0;
      pcVar7 = (char *)(*local_50 + local_90);
      do {
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        *pcVar9 = cVar1;
        pcVar9 = pcVar9 + 1;
      } while (cVar1 != '\0');
    }
    else {
      iVar3 = strcmp(pcVar7,"PTENVELOPE");
      if (iVar3 != 0) {
        lVar4 = 0;
        do {
          lVar6 = lVar4 + 1;
          if (pcVar7[lVar4] != "MIXTURE"[lVar4]) goto LAB_180035d52;
          lVar4 = lVar6;
        } while (lVar6 != 8);
      }
      local_168 = "SID";
      local_c8 = MDfndrbv(local_100,local_f0);
      if (local_c8 == 0) {
        return false;
      }
      lVar4 = MDgetvar(&local_168);
      if (lVar4 == 0) {
        return false;
      }
      pcVar7 = (char *)MDcnvhnk((ulonglong)*(uint *)(local_c8 + 0x14) + local_f0,local_50,&local_168
                               );
      lVar4 = (longlong)&DAT_180052fe0 - (longlong)pcVar7;
      do {
        cVar1 = *pcVar7;
        pcVar7[lVar4] = cVar1;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
    }
    if (DAT_180052fe0 != '\0') {
      uVar8 = 1;
      iVar3 = HYparnam(&DAT_180052fe0,&local_170,&local_178);
      if (iVar3 != 0) {
        lVar4 = -(longlong)local_178;
        do {
          cVar1 = *local_178;
          local_178[(longlong)(local_28 + lVar4)] = cVar1;
          local_178 = local_178 + 1;
        } while (cVar1 != '\0');
        local_178 = local_28;
        iVar3 = HYrslhie(local_170,&DAT_18003fa80,&local_30,local_38);
        if (iVar3 == 0) {
          return false;
        }
        uVar8 = HYGetFinfoCls(local_30);
      }
      uVar8 = HYPshFinfo(uVar8);
      memset(param_1,0,0x128);
      uVar5 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"STREAM");
      lVar4 = MDrslcls(*(undefined8 *)iwpfile_exref,uVar5);
      uVar5 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)(lVar4 + 0x148),"MATERIAL");
      param_1[2] = uVar5;
      MDrslcls(*(undefined8 *)iwpfile_exref,uVar5);
      uVar5 = MDfndkey(*(undefined8 *)iwpfile_exref,uVar5,1,local_178);
      param_1[1] = uVar5;
      lVar4 = *(longlong *)MDerror_exref;
      if (lVar4 == 0) {
        _DAT_180052fd0 = 1;
        uVar2 = *(undefined4 *)sbcanned_exref;
        FUN_1800370b0(param_1);
        *(undefined4 *)sbcanned_exref = uVar2;
        HYPopFinfo(uVar8);
      }
      else {
        ERclear(0);
        HYPopFinfo(uVar8);
      }
      return lVar4 == 0;
    }
  }
  return false;
}

/* RVA 0x35f70 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong Mixture(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined7 extraout_var;
  ulonglong uVar4;
  undefined1 auStack_188 [32];
  undefined8 local_168;
  code *local_160;
  undefined8 local_158 [38];
  ulonglong local_28;
  
                    /* 0x35f70  177  Mixture */
  local_28 = DAT_1800516d8 ^ (ulonglong)auStack_188;
  uVar4 = 0;
  GRset_in_canned(1);
  GRcreateAnalysisSumbuf();
  iVar2 = SMSetPropTableID();
  iVar3 = isFlowsheet();
  if ((iVar3 != 0) && (iVar2 != 0)) {
    bVar1 = FUN_180035c00(local_158);
    local_160 = _guard_check_icall;
    local_168 = 0;
    uVar4 = FUN_180038a30((longlong)local_158,(uint)((int)CONCAT71(extraout_var,bVar1) != 0),0xe,
                          "MIXTURE");
    uVar4 = uVar4 & 0xffffffff;
  }
  iVar2 = isFlowsheet();
  if (iVar2 == 0) {
    local_160 = _guard_check_icall;
    local_168 = 0;
    uVar4 = FUN_180038a30(0,0,0xd,"MIXTURE");
    uVar4 = uVar4 & 0xffffffff;
  }
  _DAT_180052fd0 = 0;
  GRmoveAnalysisSumbuf();
  GRdeleteAnalysisSumbuf();
  GRset_in_canned(0);
  return uVar4;
}

/* RVA 0x36070 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong PTEnvelope(undefined8 param_1,undefined8 param_2)

{
  bool bVar1;
  int iVar2;
  undefined7 extraout_var;
  ulonglong uVar3;
  undefined8 *puVar4;
  int iVar5;
  undefined1 auStack_178 [32];
  undefined8 local_158;
  code *local_150;
  undefined8 local_148 [38];
  ulonglong local_18;
  
                    /* 0x36070  64  PTEnvelope */
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_178;
  iVar5 = 1;
  GRset_in_canned(1);
  GRcreateAnalysisSumbuf();
  iVar2 = SMSetPropTableID(param_1,param_2);
  if (iVar2 != 0) {
    bVar1 = FUN_180035c00(local_148);
    if ((int)CONCAT71(extraout_var,bVar1) != 0) {
      puVar4 = local_148;
      goto LAB_1800360d6;
    }
  }
  puVar4 = (undefined8 *)0x0;
  iVar5 = 0;
LAB_1800360d6:
  local_150 = _guard_check_icall;
  local_158 = 0;
  uVar3 = FUN_180038a30((longlong)puVar4,iVar5,7,"PTENVELOPE");
  _DAT_180052fd0 = 0;
  GRmoveAnalysisSumbuf();
  GRdeleteAnalysisSumbuf();
  GRset_in_canned(0);
  return uVar3 & 0xffffffff;
}

/* RVA 0x36140 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 PetrolAnalysis(void)

{
  bool bVar1;
  undefined7 extraout_var;
  undefined8 uVar2;
  undefined1 auStack_178 [32];
  undefined8 local_158;
  code *local_150;
  undefined8 local_148 [38];
  ulonglong local_18;
  
                    /* 0x36140  88  PetrolAnalysis */
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_178;
  bVar1 = FUN_180035c00(local_148);
  if ((int)CONCAT71(extraout_var,bVar1) == 0) {
    uVar2 = 0;
  }
  else {
    local_150 = _guard_check_icall;
    local_158 = 0;
    uVar2 = FUN_180038a30((longlong)local_148,1,0xfffffffc,"PETROL");
  }
  _DAT_180052fd0 = 0;
  return uVar2;
}

/* RVA 0x361c0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 PointAnalysis(void)

{
  bool bVar1;
  undefined7 extraout_var;
  undefined8 uVar2;
  undefined1 auStack_178 [32];
  undefined8 local_158;
  code *local_150;
  undefined8 local_148 [38];
  ulonglong local_18;
  
                    /* 0x361c0  72  PointAnalysis */
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_178;
  bVar1 = FUN_180035c00(local_148);
  if ((int)CONCAT71(extraout_var,bVar1) == 0) {
    uVar2 = 0;
  }
  else {
    local_150 = _guard_check_icall;
    local_158 = 0;
    uVar2 = FUN_180038a30((longlong)local_148,1,0xffffffff,"POINT");
  }
  _DAT_180052fd0 = 0;
  return uVar2;
}

/* RVA 0x36240 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong PureAnalysis(undefined8 param_1)

{
  undefined8 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 *puVar11;
  undefined8 *puVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  int iVar17;
  undefined8 *puVar18;
  ulonglong uVar19;
  longlong lVar20;
  undefined8 *puVar21;
  undefined4 uVar22;
  undefined1 auStack_2b8 [32];
  undefined8 local_298;
  code *local_290;
  undefined8 local_288 [38];
  undefined8 local_158;
  longlong lStack_150;
  longlong local_148;
  undefined8 local_80;
  ulonglong local_28;
  
                    /* 0x36240  62  PureAnalysis */
  local_28 = DAT_1800516d8 ^ (ulonglong)auStack_2b8;
  uVar13 = GRinqcpt();
  uVar14 = GRinqpgc();
  uVar15 = GRinqnec();
  uVar16 = GRinqgpd();
  GRset_in_canned(1);
  GRcreateAnalysisSumbuf();
  SMSetPropTableID(param_1);
  memset(&local_158,0,0x128);
  local_148 = *(longlong *)(analysis_ditem_exref + 8);
  lStack_150 = *(longlong *)analysis_ditem_exref;
  if ((local_148 == -1) || (lStack_150 == -1)) {
    uVar19 = 0;
  }
  else {
    local_80 = MDfndito(*(undefined8 *)iwpfile_exref);
    MDgetrdf(&local_158);
    lVar20 = 2;
    puVar11 = &local_158;
    puVar12 = local_288;
    do {
      puVar21 = puVar12;
      puVar18 = puVar11;
      uVar1 = puVar18[1];
      uVar8 = puVar18[2];
      uVar9 = puVar18[3];
      *puVar21 = *puVar18;
      puVar21[1] = uVar1;
      uVar1 = puVar18[4];
      uVar10 = puVar18[5];
      puVar21[2] = uVar8;
      puVar21[3] = uVar9;
      uVar8 = puVar18[6];
      uVar9 = puVar18[7];
      puVar21[4] = uVar1;
      puVar21[5] = uVar10;
      uVar1 = puVar18[8];
      uVar10 = puVar18[9];
      puVar21[6] = uVar8;
      puVar21[7] = uVar9;
      uVar8 = puVar18[10];
      uVar9 = puVar18[0xb];
      puVar21[8] = uVar1;
      puVar21[9] = uVar10;
      uVar1 = puVar18[0xc];
      uVar10 = puVar18[0xd];
      puVar21[10] = uVar8;
      puVar21[0xb] = uVar9;
      uVar8 = puVar18[0xe];
      uVar9 = puVar18[0xf];
      puVar21[0xc] = uVar1;
      puVar21[0xd] = uVar10;
      puVar21[0xe] = uVar8;
      puVar21[0xf] = uVar9;
      lVar20 = lVar20 + -1;
      puVar11 = puVar18 + 0x10;
      puVar12 = puVar21 + 0x10;
    } while (lVar20 != 0);
    uVar1 = puVar18[0x14];
    uVar22 = *(undefined4 *)((longlong)puVar18 + 0x84);
    uVar2 = *(undefined4 *)(puVar18 + 0x11);
    uVar3 = *(undefined4 *)((longlong)puVar18 + 0x8c);
    uVar4 = *(undefined4 *)(puVar18 + 0x12);
    uVar5 = *(undefined4 *)((longlong)puVar18 + 0x94);
    uVar6 = *(undefined4 *)(puVar18 + 0x13);
    uVar7 = *(undefined4 *)((longlong)puVar18 + 0x9c);
    *(undefined4 *)(puVar21 + 0x10) = *(undefined4 *)(puVar18 + 0x10);
    *(undefined4 *)((longlong)puVar21 + 0x84) = uVar22;
    *(undefined4 *)(puVar21 + 0x11) = uVar2;
    *(undefined4 *)((longlong)puVar21 + 0x8c) = uVar3;
    *(undefined4 *)(puVar21 + 0x12) = uVar4;
    *(undefined4 *)((longlong)puVar21 + 0x94) = uVar5;
    *(undefined4 *)(puVar21 + 0x13) = uVar6;
    *(undefined4 *)((longlong)puVar21 + 0x9c) = uVar7;
    puVar21[0x14] = uVar1;
    iVar17 = SMgetproptype();
    local_290 = (code *)0x0;
    if (iVar17 != 3) {
      local_290 = _guard_check_icall;
    }
    uVar22 = 0x13;
    if (iVar17 != 3) {
      uVar22 = 2;
    }
    local_298 = 0;
    uVar19 = FUN_180038a30(0,0,uVar22,"PURE");
    uVar19 = uVar19 & 0xffffffff;
    GRsetpgc(uVar14);
    GRsetnec(uVar15);
    GRsetcpt(uVar13);
    GRsetgpd(uVar16);
    GRmoveAnalysisSumbuf();
    GRdeleteAnalysisSumbuf();
    GRset_in_canned(0);
  }
  return uVar19;
}

/* RVA 0x36430 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 PvcurAnalysis(void)

{
  bool bVar1;
  undefined7 extraout_var;
  undefined8 uVar2;
  undefined1 auStack_178 [32];
  undefined8 local_158;
  code *local_150;
  undefined8 local_148 [38];
  ulonglong local_18;
  
                    /* 0x36430  91  PvcurAnalysis */
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_178;
  bVar1 = FUN_180035c00(local_148);
  if ((int)CONCAT71(extraout_var,bVar1) == 0) {
    uVar2 = 0;
  }
  else {
    local_150 = _guard_check_icall;
    local_158 = 0;
    uVar2 = FUN_180038a30((longlong)local_148,1,10,"PVCUR");
  }
  _DAT_180052fd0 = 0;
  return uVar2;
}

/* RVA 0x364b0 */
ulonglong ResidueAnalysis(void)

{
  ulonglong uVar1;
  
                    /* 0x364b0  63  ResidueAnalysis */
  GRset_in_canned(1);
  GRcreateAnalysisSumbuf();
  SMSetPropTableID();
  uVar1 = FUN_180038a30(0,0,6,"RESIDUE");
  GRmoveAnalysisSumbuf();
  GRdeleteAnalysisSumbuf();
  GRset_in_canned(0);
  return uVar1 & 0xffffffff;
}

/* RVA 0x36520 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180036520(char *param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  undefined8 uVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  ulonglong _Count;
  undefined4 uVar12;
  undefined1 auStack_128 [32];
  undefined8 local_108;
  undefined8 local_100;
  undefined8 local_f8;
  undefined4 local_f0;
  undefined8 local_e8;
  undefined4 local_d8;
  char local_c8 [4];
  char local_c4 [2];
  char local_c2;
  char local_48 [16];
  ulonglong local_38;
  
  local_38 = DAT_1800516d8 ^ (ulonglong)auStack_128;
  pcVar3 = strchr(param_1,0x2e);
  if (pcVar3 == (char *)0x0) {
    pcVar3 = (char *)0x0;
    pcVar4 = param_1;
    do {
      cVar1 = *pcVar4;
      pcVar4[(longlong)(local_48 + -(longlong)param_1)] = cVar1;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
  }
  else {
    _Count = (longlong)pcVar3 - (longlong)param_1;
    pcVar3 = pcVar3 + 1;
    strncpy(local_48,param_1,_Count);
    if (8 < _Count) {
                    /* WARNING: Subroutine does not return */
      FUN_18003b6e4();
    }
    local_48[_Count] = '\0';
    if (pcVar3 != (char *)0x0) {
      uVar9 = *(undefined8 *)(*(longlong *)finfo_exref + 0x1b8);
      goto LAB_1800365cf;
    }
  }
  uVar9 = *(undefined8 *)(*(longlong *)finfo_exref + 0x1c0);
LAB_1800365cf:
  uVar5 = MDfndkey(*(undefined8 *)iwpfile_exref,uVar9,1,local_48);
  lVar6 = MDgethkp(*(undefined8 *)iwpfile_exref,uVar9,uVar5);
  uVar9 = *(undefined8 *)(lVar6 + 0x28);
  lVar6 = *(longlong *)(lVar6 + 0x30);
  lVar7 = MDgetito(*(undefined8 *)iwpfile_exref,uVar9,lVar6);
  lVar8 = MDrslcls(*(undefined8 *)iwpfile_exref);
  lVar8 = lVar6 * 0x108 + lVar8;
  if (pcVar3 == (char *)0x0) {
    uVar5 = *(undefined8 *)(lVar7 + 0x20);
    uVar11 = *(undefined8 *)(lVar7 + 0x18);
    memset(*(void **)gevaldef_exref,0,0x128);
    uVar10 = MDgetito(*(undefined8 *)recfile_exref,uVar5,uVar11);
    *(undefined8 *)(*(longlong *)gevaldef_exref + 0x68) = uVar10;
    *(undefined8 *)(*(longlong *)gevaldef_exref + 0x90) = uVar5;
    *(undefined8 *)(*(longlong *)gevaldef_exref + 0x88) = uVar11;
    uVar11 = MDgetito(*(undefined8 *)recfile_exref,uVar5,
                      *(undefined8 *)(*(longlong *)(*(longlong *)gevaldef_exref + 0x68) + 0x40));
    *(undefined8 *)(*(longlong *)gevaldef_exref + 0x78) = uVar11;
    uVar11 = MDgetito(*(undefined8 *)iwpfile_exref,uVar9,lVar6);
    *(undefined8 *)(*(longlong *)gevaldef_exref + 0xd8) = uVar11;
    *(undefined8 *)(*(longlong *)gevaldef_exref + 0x10) = uVar9;
    *(longlong *)(*(longlong *)gevaldef_exref + 8) = lVar6;
    if (*(longlong *)(*(longlong *)(*(longlong *)gevaldef_exref + 0x68) + 0x68) == 0) {
      *(undefined8 *)(*(longlong *)gevaldef_exref + 0x70) = 0;
    }
    else {
      uVar5 = MDgetito(*(undefined8 *)recfile_exref,uVar5);
      *(undefined8 *)(*(longlong *)gevaldef_exref + 0x70) = uVar5;
    }
    lVar8 = MDrslcls(*(undefined8 *)recfile_exref,
                     *(undefined8 *)(*(longlong *)gevaldef_exref + 0x90));
    lVar7 = *(longlong *)gevaldef_exref;
    iVar2 = strcmp((char *)(*(longlong *)(lVar7 + 0x88) * 0x108 + lVar8),"MATERIAL");
    uVar12 = local_d8;
    if (iVar2 == 0) {
      uVar12 = 1;
    }
    iVar2 = MDlenito(*(undefined8 *)iwpfile_exref,*(undefined8 *)(lVar7 + 0x10),
                     *(undefined8 *)(lVar7 + 8));
    if (iVar2 != 0x178) {
      lVar7 = *(longlong *)(*(longlong *)gevaldef_exref + 0xd8);
      if (*(longlong *)(lVar7 + 0x90) == 0) {
        local_100 = 0;
      }
      else {
        local_100 = MDgetito(*(undefined8 *)iwpfile_exref,*(undefined8 *)(lVar7 + 0x98));
      }
      if ((*(longlong *)(lVar7 + 0x30) < 1) || (*(longlong *)(lVar7 + 0x28) < 1)) {
        *(undefined8 *)(*(longlong *)gevaldef_exref + 0xb8) = 0;
      }
      else {
        uVar5 = MDgetito(*(undefined8 *)recfile_exref);
        *(undefined8 *)(*(longlong *)gevaldef_exref + 0xb8) = uVar5;
      }
      local_e8 = 0;
      local_f0 = 1;
      *(ulonglong *)geunbead_exref = local_100;
      local_c8[0] = s_STREAM_1800415b4[0];
      local_c8[1] = s_STREAM_1800415b4[1];
      local_c8[2] = s_STREAM_1800415b4[2];
      local_c8[3] = s_STREAM_1800415b4[3];
      local_c4[0] = s_STREAM_1800415b4[4];
      local_c4[1] = s_STREAM_1800415b4[5];
      local_c2 = s_STREAM_1800415b4[6];
      *(undefined4 *)called_from_analysis_exref = 1;
      lVar8 = *(longlong *)gevaldef_exref;
      local_f8 = local_c8;
      local_108 = param_1;
      GEgenpar(*(undefined8 *)(lVar8 + 0xd8),*(undefined8 *)(lVar8 + 0x68),
               *(undefined8 *)(lVar8 + 0x78),uVar12);
      *(undefined4 *)called_from_analysis_exref = 0;
      lVar6 = MDgethkp(*(undefined8 *)iwpfile_exref,uVar9,lVar6);
      local_f8 = (char *)((ulonglong)local_f8 & 0xffffffff00000000);
      local_100 = CONCAT44(local_100._4_4_,9999);
      local_108 = (char *)CONCAT44(local_108._4_4_,9999);
      *(uint *)(lVar6 + 0x18) = *(uint *)(lVar6 + 0x18) | 0x1000;
      MDprpcmp(lVar7 + 0x40,*(undefined4 *)(lVar7 + 0x38),*(undefined8 *)(lVar7 + 0x80),
               *(undefined8 *)(*(longlong *)gevaldef_exref + 8));
    }
  }
  else if ((*(byte *)(lVar7 + 0x120) & 4) != 0) {
    local_f8 = (char *)((ulonglong)local_f8._4_4_ << 0x20);
    local_100 = (ulonglong)local_100._4_4_ << 0x20;
    local_108 = (char *)((ulonglong)local_108._4_4_ << 0x20);
    GEwrtwrd(0,"HIERARCHY",2,1);
    local_f8 = (char *)((ulonglong)local_f8 & 0xffffffff00000000);
    local_100 = local_100 & 0xffffffff00000000;
    local_108 = (char *)((ulonglong)local_108 & 0xffffffff00000000);
    GEwrtwrd(0,lVar8,0,1);
    uVar9 = HYGetFinfoCls(uVar9,lVar6);
    uVar9 = HYPshFinfo(uVar9);
    if (*(int *)editrun_exref != 0) {
      GEgendel();
    }
    FUN_180036520(pcVar3);
    HYPopFinfo(uVar9);
    local_f8 = (char *)((ulonglong)local_f8 & 0xffffffff00000000);
    local_100 = local_100 & 0xffffffff00000000;
    local_108 = (char *)((ulonglong)local_108 & 0xffffffff00000000);
    GEwrtwrd(0,"ENDHIERARCHY",2,1);
    local_f8 = (char *)((ulonglong)local_f8 & 0xffffffff00000000);
    local_100 = local_100 & 0xffffffff00000000;
    local_108 = (char *)((ulonglong)local_108 & 0xffffffff00000000);
    GEwrtwrd(0,lVar8,0,1);
  }
  return 1;
}

/* RVA 0x36a60 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180036a60(char *param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined1 auStack_168 [32];
  undefined1 local_148 [304];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_168;
  uVar1 = *(undefined8 *)gevaldef_exref;
  *(undefined1 **)gevaldef_exref = local_148;
  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {
    uVar2 = HYPshFinfo(1);
    FUN_180036520(param_1);
    HYPopFinfo(uVar2);
    *(undefined8 *)gevaldef_exref = uVar1;
  }
  return;
}

/* RVA 0x36b00 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_180036b00(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  longlong lVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  char *pcVar7;
  longlong lVar8;
  undefined8 uVar9;
  undefined1 auStackY_198 [32];
  char *local_168;
  char *local_160;
  undefined8 local_158;
  undefined8 local_150;
  char local_148 [8];
  uint local_140;
  int local_138;
  int local_130;
  char local_38 [16];
  char local_28 [16];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStackY_198;
  lVar4 = deref_ptr(*(undefined8 *)(*(longlong *)topfinfo_exref + 0x600));
  DAT_180050de4 = 0;
  if (*(int *)sbcanned_exref < 0) {
    local_160 = (char *)0x0;
    local_38[0] = '\0';
    uVar9 = 1;
    iVar3 = HYparnam(&DAT_180052fe0,&local_160);
    if (iVar3 != 0) {
      lVar8 = -(longlong)local_168;
      do {
        cVar1 = *local_168;
        local_168[(longlong)(local_28 + lVar8)] = cVar1;
        local_168 = local_168 + 1;
      } while (cVar1 != '\0');
      pcVar7 = local_160;
      do {
        cVar1 = *pcVar7;
        pcVar7[(longlong)(local_38 + -(longlong)local_160)] = cVar1;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      local_168 = local_28;
      uVar5 = HYrslhie(local_160,&DAT_18003fa80,&local_150,&local_158);
      if ((int)uVar5 == 0) {
        return uVar5;
      }
      uVar9 = HYGetFinfoCls(local_150,local_158);
    }
    uVar9 = HYPshFinfo(uVar9);
    pcVar7 = local_38;
    if (local_38[0] == '\0') {
      pcVar7 = "";
    }
    SBsetscp(pcVar7);
    *(undefined4 *)partial_results_exref = 1;
    uVar5 = ((longlong)-*(int *)sbcanned_exref | 0x2100U) << 8;
    if (lVar4 != 0) {
      lVar8 = 0;
      uVar2 = 1;
      uVar6 = uVar5 | 1;
      if (*(int *)(lVar4 + 0x14) != 0) {
        uVar6 = uVar5;
      }
      uVar5 = uVar6 | 2;
      if (*(int *)(lVar4 + 0x18) != 0) {
        uVar5 = uVar6;
      }
      for (; lVar8 < 5; lVar8 = lVar8 + 1) {
        if (*(int *)(lVar4 + lVar8 * 4) != 0) {
          uVar5 = uVar5 | (longlong)(int)(uVar2 << 2 | uVar2 >> 0x1e);
        }
        uVar2 = uVar2 << 1 | (uint)((int)uVar2 < 0);
      }
    }
    iVar3 = FUN_180030240((char *)0x0,local_148,0,uVar5 << 8 | 0x40ff,local_168);
    HYPopFinfo(uVar9);
LAB_180036d4a:
    if (iVar3 != 0) {
      if (local_140 == 1) {
        if (local_130 != -1) goto LAB_180036d76;
      }
      else if ((local_140 == 2) || (local_140 == 3)) {
        if (local_138 == -1) {
          uVar2 = 0xffffffff;
          goto LAB_180036d87;
        }
LAB_180036d76:
        *(uint *)Sactions_exref = *(uint *)Sactions_exref | 0x8000;
        uVar2 = local_140;
        goto LAB_180036d87;
      }
    }
    uVar2 = 0xffffffff;
  }
  else {
    SBsetscp("");
    *(undefined4 *)sum_header_exref = 1;
    *(undefined4 *)partial_results_exref = 1;
    uVar2 = FUN_180024de0();
    if (uVar2 != 0xffffffff) {
      FUN_18002c620((longlong)APtmpfil_exref);
      *(undefined4 *)sum_header_exref = 0;
      iVar3 = FUN_180030240((char *)0x0,local_148,0,0x285ff00,
                            *(char **)(canned_distab_exref +
                                      (longlong)*(int *)sbcanned_exref * 8 + -8));
      goto LAB_180036d4a;
    }
LAB_180036d87:
    DAT_180050de4 = 1;
    if (0 < (int)uVar2) {
      DAT_180052fd4 = 1;
      goto LAB_180036db9;
    }
  }
  DAT_180050de4 = 1;
  *(undefined4 *)sbcanned_exref = 0;
LAB_180036db9:
  return (ulonglong)uVar2;
}

/* RVA 0x36df0 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong Solubility(void)

{
  ulonglong uVar1;
  
                    /* 0x36df0  182  Solubility */
  GRset_in_canned(1);
  GRcreateAnalysisSumbuf();
  SMSetPropTableID();
  uVar1 = FUN_180038a30(0,0,0xf,"SOLUBILITY");
  _DAT_180052fd0 = 0;
  GRmoveAnalysisSumbuf();
  GRdeleteAnalysisSumbuf();
  GRset_in_canned(0);
  return uVar1 & 0xffffffff;
}

/* RVA 0x36e60 */
ulonglong TernaryAnalysis(void)

{
  ulonglong uVar1;
  
                    /* 0x36e60  139  TernaryAnalysis */
  GRset_in_canned(1);
  GRcreateAnalysisSumbuf();
  SMSetPropTableID();
  uVar1 = FUN_180038a30(0,0,0xc,"TERDIAGRAM");
  GRmoveAnalysisSumbuf();
  GRdeleteAnalysisSumbuf();
  GRset_in_canned(0);
  return uVar1 & 0xffffffff;
}

/* RVA 0x36ed0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 TvcurAnalysis(void)

{
  bool bVar1;
  undefined7 extraout_var;
  undefined8 uVar2;
  undefined1 auStack_178 [32];
  undefined8 local_158;
  code *local_150;
  undefined8 local_148 [38];
  ulonglong local_18;
  
                    /* 0x36ed0  92  TvcurAnalysis */
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_178;
  bVar1 = FUN_180035c00(local_148);
  if ((int)CONCAT71(extraout_var,bVar1) == 0) {
    uVar2 = 0;
  }
  else {
    local_150 = _guard_check_icall;
    local_158 = 0;
    uVar2 = FUN_180038a30((longlong)local_148,1,0xb,"TVCUR");
  }
  _DAT_180052fd0 = 0;
  return uVar2;
}

/* RVA 0x36f50 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180036f50(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 auStack_338 [32];
  undefined8 local_318;
  char *local_308;
  undefined8 local_300;
  undefined8 local_2f8;
  longlong *local_1f0;
  undefined8 local_1d8;
  undefined8 uStack_1d0;
  undefined1 local_1c8 [432];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_338;
  local_1d8 = 0;
  uStack_1d0 = 0;
  memset(&local_308,0,0x128);
  local_2f8 = MDfnddir(*(undefined8 *)iwpfile_exref,
                       *(undefined8 *)(*(longlong *)topfinfo_exref + 0x168),"SETUP");
  uVar2 = 1;
  local_300 = MDfndkey(*(undefined8 *)iwpfile_exref,local_2f8,1,"SIM-OPTIONS");
  if (*(longlong *)MDerror_exref == 0) {
    DRstovbg(&local_308,local_1c8,0);
    local_318 = 0;
    local_308 = "ENERGY-BAL";
    MDfndvar("ENERGY-BAL",1,0,&local_308);
    if ((local_1f0 == (longlong *)0x0) || (*local_1f0 != 0)) {
      iVar1 = EXyesno("ENERGY-BAL has been set to NO in the Setup.Sim-Options form. Analysis is not allowed when ENERGY-BAL=NO. OK will set ENERGY-BAL to YES and proceed with analysis."
                      ,3,1);
      if (iVar1 == 2) {
        uVar2 = 0;
      }
      else {
        MDsetvar(&local_308,&local_1d8);
        GRsetgpd(0);
      }
    }
    DRstovnd(&local_308,local_1c8);
  }
  else {
    ERclear(0);
  }
  return uVar2;
}

/* RVA 0x370b0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_1800370b0(undefined8 *param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  char *pcVar9;
  char *pcVar10;
  char *pcVar11;
  char **ppcVar12;
  int iVar13;
  undefined8 uVar14;
  longlong lVar15;
  int *piVar16;
  longlong *plVar17;
  char **ppcVar18;
  undefined8 *puVar19;
  undefined1 auStack_168 [32];
  char *local_148 [5];
  undefined4 uStack_11c;
  undefined8 local_a8;
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_168;
  uVar14 = FUN_180036f50();
  if ((int)uVar14 != 0) {
    lVar15 = 2;
    ppcVar12 = local_148;
    do {
      puVar19 = param_1;
      ppcVar18 = ppcVar12;
      pcVar1 = (char *)puVar19[1];
      pcVar9 = (char *)puVar19[2];
      pcVar10 = (char *)puVar19[3];
      *ppcVar18 = (char *)*puVar19;
      ppcVar18[1] = pcVar1;
      pcVar1 = (char *)puVar19[4];
      pcVar11 = (char *)puVar19[5];
      ppcVar18[2] = pcVar9;
      ppcVar18[3] = pcVar10;
      pcVar9 = (char *)puVar19[6];
      pcVar10 = (char *)puVar19[7];
      ppcVar18[4] = pcVar1;
      ppcVar18[5] = pcVar11;
      pcVar1 = (char *)puVar19[8];
      pcVar11 = (char *)puVar19[9];
      ppcVar18[6] = pcVar9;
      ppcVar18[7] = pcVar10;
      pcVar9 = (char *)puVar19[10];
      pcVar10 = (char *)puVar19[0xb];
      ppcVar18[8] = pcVar1;
      ppcVar18[9] = pcVar11;
      pcVar1 = (char *)puVar19[0xc];
      pcVar11 = (char *)puVar19[0xd];
      ppcVar18[10] = pcVar9;
      ppcVar18[0xb] = pcVar10;
      pcVar9 = (char *)puVar19[0xe];
      pcVar10 = (char *)puVar19[0xf];
      ppcVar18[0xc] = pcVar1;
      ppcVar18[0xd] = pcVar11;
      ppcVar18[0xe] = pcVar9;
      ppcVar18[0xf] = pcVar10;
      lVar15 = lVar15 + -1;
      ppcVar12 = ppcVar18 + 0x10;
      param_1 = puVar19 + 0x10;
    } while (lVar15 != 0);
    pcVar1 = (char *)puVar19[0x14];
    uVar2 = *(undefined4 *)((longlong)puVar19 + 0x84);
    uVar3 = *(undefined4 *)(puVar19 + 0x11);
    uVar4 = *(undefined4 *)((longlong)puVar19 + 0x8c);
    uVar5 = *(undefined4 *)(puVar19 + 0x12);
    uVar6 = *(undefined4 *)((longlong)puVar19 + 0x94);
    uVar7 = *(undefined4 *)(puVar19 + 0x13);
    uVar8 = *(undefined4 *)((longlong)puVar19 + 0x9c);
    *(undefined4 *)(ppcVar18 + 0x10) = *(undefined4 *)(puVar19 + 0x10);
    *(undefined4 *)((longlong)ppcVar18 + 0x84) = uVar2;
    *(undefined4 *)(ppcVar18 + 0x11) = uVar3;
    *(undefined4 *)((longlong)ppcVar18 + 0x8c) = uVar4;
    *(undefined4 *)(ppcVar18 + 0x12) = uVar5;
    *(undefined4 *)((longlong)ppcVar18 + 0x94) = uVar6;
    *(undefined4 *)(ppcVar18 + 0x13) = uVar7;
    *(undefined4 *)((longlong)ppcVar18 + 0x9c) = uVar8;
    ppcVar18[0x14] = pcVar1;
    local_148[0] = "NPHASE";
    local_a8 = 0;
    uStack_11c = 1;
    piVar16 = (int *)MDgetvar(local_148);
    if (piVar16 == (int *)0x0) {
      *(undefined4 *)canned_phase_freewater_exref = 0;
    }
    else {
      *(int *)canned_phase_freewater_exref = *piVar16 + 1;
    }
    local_a8 = 0;
    local_148[0] = "FREE-WATER";
    plVar17 = (longlong *)MDgetvar(local_148);
    if (plVar17 == (longlong *)0x0) {
      iVar13 = FUN_180038910();
      if (iVar13 != 0) {
        *(int *)canned_phase_freewater_exref = *(int *)canned_phase_freewater_exref + 10;
      }
    }
    else {
      iVar13 = 10;
      if (*plVar17 != 0) {
        iVar13 = 0;
      }
      *(int *)canned_phase_freewater_exref = *(int *)canned_phase_freewater_exref + iVar13;
    }
    *(undefined4 *)sbcanned_exref = 0xffffffff;
  }
  return 0;
}

/* RVA 0x37220 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180037220(void)

{
  uint *puVar1;
  undefined8 uVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  int *piVar6;
  uint uVar7;
  longlong lVar8;
  uint uVar9;
  undefined1 auStack_3c8 [32];
  char *local_3a8;
  undefined8 local_3a0;
  char *local_398;
  undefined4 local_390;
  undefined8 local_388;
  undefined1 local_378 [8];
  longlong local_370;
  undefined8 local_368;
  uint *local_310;
  undefined8 local_300;
  longlong local_2a0;
  undefined1 local_248 [432];
  char local_98 [4];
  char local_94 [11];
  char local_89 [8];
  char local_81 [4];
  char local_7d;
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_3c8;
  uVar2 = *(undefined8 *)gevaldef_exref;
  memset(local_378,0,0x128);
  lVar4 = MDfndkey(*(undefined8 *)iwpfile_exref,*(undefined8 *)(*(longlong *)topfinfo_exref + 0x168)
                   ,1,"SETUP");
  lVar5 = MDrslcls(*(undefined8 *)iwpfile_exref,*(undefined8 *)(*(longlong *)topfinfo_exref + 0x168)
                  );
  local_368 = *(undefined8 *)(lVar5 + 0x28 + lVar4 * 0x108);
  local_370 = MDfndkey(*(undefined8 *)iwpfile_exref,local_368,1);
  if (*(longlong *)MDerror_exref == 0) {
    iVar3 = MDlenito(*(undefined8 *)iwpfile_exref,local_368,local_370);
    if (iVar3 != 0x178) {
      lVar5 = MDrslcls(*(undefined8 *)iwpfile_exref,local_368);
      lVar8 = local_370 * 0x108;
      DRstovbg(local_378,local_248,0);
      lVar4 = local_2a0;
      local_98[0] = s_SETUP_180043b24[0];
      local_98[1] = s_SETUP_180043b24[1];
      local_98[2] = s_SETUP_180043b24[2];
      local_98[3] = s_SETUP_180043b24[3];
      local_94[0] = s_SETUP_180043b24[4];
      local_94[1] = s_SETUP_180043b24[5];
      local_81[0] = s_ACCOUNT_INFO_180043b30[8];
      local_81[1] = s_ACCOUNT_INFO_180043b30[9];
      local_81[2] = s_ACCOUNT_INFO_180043b30[10];
      local_81[3] = s_ACCOUNT_INFO_180043b30[0xb];
      local_7d = s_ACCOUNT_INFO_180043b30[0xc];
      local_89[0] = s_ACCOUNT_INFO_180043b30[0];
      local_89[1] = s_ACCOUNT_INFO_180043b30[1];
      local_89[2] = s_ACCOUNT_INFO_180043b30[2];
      local_89[3] = s_ACCOUNT_INFO_180043b30[3];
      local_89[4] = s_ACCOUNT_INFO_180043b30[4];
      local_89[5] = s_ACCOUNT_INFO_180043b30[5];
      local_89[6] = s_ACCOUNT_INFO_180043b30[6];
      local_89[7] = s_ACCOUNT_INFO_180043b30[7];
      if (*(longlong *)(local_2a0 + 0x90) == 0) {
        local_3a0 = 0;
      }
      else {
        local_3a0 = MDgetito(*(undefined8 *)iwpfile_exref);
      }
      uVar7 = 0;
      *(undefined8 *)geunbead_exref = local_3a0;
      *(undefined1 **)gevaldef_exref = local_378;
      uVar9 = *local_310 >> 7 & 0x1ff;
      if (uVar9 != 0) {
        piVar6 = (int *)((ulonglong)local_310[1] + 4 + (longlong)local_310);
        do {
          if ((*(byte *)(*piVar6 + local_2a0) & 1) != 0) {
            local_398 = local_98;
            local_388 = 0;
            local_390 = 2;
            local_3a8 = "ACCOUNT-INFO";
            GEgenpar(local_2a0,local_310,local_300,0);
            puVar1 = (uint *)(lVar8 + lVar5 + 0x18);
            *puVar1 = *puVar1 | 0x1000;
            local_398 = (char *)((ulonglong)local_398 & 0xffffffff00000000);
            local_3a0 = CONCAT44(local_3a0._4_4_,9999);
            local_3a8 = (char *)CONCAT44(local_3a8._4_4_,9999);
            MDprpcmp(lVar4 + 0x40,*(undefined4 *)(lVar4 + 0x38),*(undefined8 *)(lVar4 + 0x80),
                     *(undefined8 *)(*(longlong *)gevaldef_exref + 8));
            break;
          }
          uVar7 = uVar7 + 1;
          piVar6 = piVar6 + 0xc;
        } while (uVar7 < uVar9);
      }
      *(undefined8 *)gevaldef_exref = uVar2;
    }
  }
  else {
    ERclear(0);
  }
  return;
}

/* RVA 0x37500 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180037500(void)

{
  uint *puVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  undefined1 auStack_408 [32];
  undefined8 *local_3e8;
  undefined8 local_3e0;
  char *local_3d8;
  undefined4 local_3d0;
  undefined8 local_3c8;
  undefined1 local_3b8 [8];
  longlong local_3b0;
  undefined8 local_3a8;
  longlong local_2e0;
  undefined8 local_288 [6];
  undefined1 local_258 [432];
  char local_a8 [8];
  char local_a0 [2];
  char local_9e;
  ulonglong local_28;
  
  local_28 = DAT_1800516d8 ^ (ulonglong)auStack_408;
  uVar2 = *(undefined8 *)gevaldef_exref;
  uVar4 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)(*(longlong *)topfinfo_exref + 0x168)
                   ,"CO-PACKAGE");
  lVar5 = MDrslcls(*(undefined8 *)iwpfile_exref,uVar4);
  local_288[0] = 0;
  local_3e8 = local_288;
  local_3e0 = 0;
  lVar6 = MDfndsls(*(undefined8 *)iwpfile_exref,uVar4,1,0);
  while (lVar6 != -1) {
    lVar7 = lVar6 * 0x108 + lVar5;
    memset(local_3b8,0,0x128);
    local_3b0 = lVar6;
    local_3a8 = uVar4;
    DRstovbg(local_3b8,local_258,0);
    lVar3 = local_2e0;
    local_3c8 = 0;
    local_3d0 = 1;
    *(undefined1 **)gevaldef_exref = local_3b8;
    *(undefined8 *)geunbead_exref = 0;
    local_a0[0] = s_CO_PACKAGE_180043b50[8];
    local_a0[1] = s_CO_PACKAGE_180043b50[9];
    local_9e = s_CO_PACKAGE_180043b50[10];
    local_a8[0] = s_CO_PACKAGE_180043b50[0];
    local_a8[1] = s_CO_PACKAGE_180043b50[1];
    local_a8[2] = s_CO_PACKAGE_180043b50[2];
    local_a8[3] = s_CO_PACKAGE_180043b50[3];
    local_a8[4] = s_CO_PACKAGE_180043b50[4];
    local_a8[5] = s_CO_PACKAGE_180043b50[5];
    local_a8[6] = s_CO_PACKAGE_180043b50[6];
    local_a8[7] = s_CO_PACKAGE_180043b50[7];
    lVar6 = *(longlong *)gevaldef_exref;
    local_3d8 = local_a8;
    local_3e0 = 0;
    local_3e8 = (undefined8 *)lVar7;
    GEgenpar(*(undefined8 *)(lVar6 + 0xd8),*(undefined8 *)(lVar6 + 0x68),
             *(undefined8 *)(lVar6 + 0x78),0);
    puVar1 = (uint *)(lVar7 + 0x18);
    *puVar1 = *puVar1 | 0x1000;
    local_3d8 = (char *)((ulonglong)local_3d8 & 0xffffffff00000000);
    local_3e0 = CONCAT44(local_3e0._4_4_,9999);
    local_3e8 = (undefined8 *)CONCAT44(local_3e8._4_4_,9999);
    MDprpcmp(lVar3 + 0x40,*(undefined4 *)(lVar3 + 0x38),*(undefined8 *)(lVar3 + 0x80));
    DRstovnd(local_3b8,local_258);
    local_3e8 = local_288;
    local_3e0 = 0;
    lVar6 = MDfndsls(*(undefined8 *)iwpfile_exref,uVar4,1);
  }
  *(undefined8 *)gevaldef_exref = uVar2;
  return;
}

/* RVA 0x37760 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180037760(void)

{
  uint *puVar1;
  undefined8 uVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  int *piVar6;
  uint uVar7;
  longlong lVar8;
  uint uVar9;
  undefined1 auStack_3c8 [32];
  char *local_3a8;
  undefined8 local_3a0;
  char *local_398;
  undefined4 local_390;
  undefined8 local_388;
  undefined1 local_378 [8];
  longlong local_370;
  undefined8 local_368;
  uint *local_310;
  undefined8 local_300;
  longlong local_2a0;
  undefined1 local_248 [432];
  char local_98 [4];
  char local_94 [11];
  char local_89 [8];
  char local_81 [2];
  char local_7f;
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_3c8;
  uVar2 = *(undefined8 *)gevaldef_exref;
  memset(local_378,0,0x128);
  lVar4 = MDfndkey(*(undefined8 *)iwpfile_exref,*(undefined8 *)(*(longlong *)topfinfo_exref + 0x168)
                   ,1,"SETUP");
  lVar5 = MDrslcls(*(undefined8 *)iwpfile_exref,*(undefined8 *)(*(longlong *)topfinfo_exref + 0x168)
                  );
  local_368 = *(undefined8 *)(lVar5 + 0x28 + lVar4 * 0x108);
  local_370 = MDfndkey(*(undefined8 *)iwpfile_exref,local_368,1,"CUSTOM-UOM");
  if (*(longlong *)MDerror_exref == 0) {
    iVar3 = MDlenito(*(undefined8 *)iwpfile_exref,local_368,local_370);
    if (iVar3 != 0x178) {
      lVar5 = MDrslcls(*(undefined8 *)iwpfile_exref,local_368);
      lVar8 = local_370 * 0x108;
      DRstovbg(local_378,local_248,0);
      lVar4 = local_2a0;
      uVar7 = 0;
      uVar9 = *local_310 >> 7 & 0x1ff;
      if (uVar9 != 0) {
        piVar6 = (int *)((longlong)local_310 + (ulonglong)local_310[1] + 4);
        do {
          if ((*(byte *)(*piVar6 + local_2a0) & 1) != 0) {
            local_98[0] = s_SETUP_180043b24[0];
            local_98[1] = s_SETUP_180043b24[1];
            local_98[2] = s_SETUP_180043b24[2];
            local_98[3] = s_SETUP_180043b24[3];
            local_94[0] = s_SETUP_180043b24[4];
            local_94[1] = s_SETUP_180043b24[5];
            local_81[0] = s_CUSTOM_UOM_180043e68[8];
            local_81[1] = s_CUSTOM_UOM_180043e68[9];
            local_7f = s_CUSTOM_UOM_180043e68[10];
            local_89[0] = s_CUSTOM_UOM_180043e68[0];
            local_89[1] = s_CUSTOM_UOM_180043e68[1];
            local_89[2] = s_CUSTOM_UOM_180043e68[2];
            local_89[3] = s_CUSTOM_UOM_180043e68[3];
            local_89[4] = s_CUSTOM_UOM_180043e68[4];
            local_89[5] = s_CUSTOM_UOM_180043e68[5];
            local_89[6] = s_CUSTOM_UOM_180043e68[6];
            local_89[7] = s_CUSTOM_UOM_180043e68[7];
            if (*(longlong *)(local_2a0 + 0x90) == 0) {
              local_3a0 = 0;
            }
            else {
              local_3a0 = MDgetito(*(undefined8 *)iwpfile_exref,*(undefined8 *)(local_2a0 + 0x98));
            }
            local_388 = 0;
            local_390 = 2;
            *(undefined8 *)geunbead_exref = local_3a0;
            *(undefined1 **)gevaldef_exref = local_378;
            local_398 = local_98;
            local_3a8 = "CUSTOM-UOM";
            GEgenpar(local_2a0,local_310,local_300,0);
            puVar1 = (uint *)(lVar8 + lVar5 + 0x18);
            *puVar1 = *puVar1 | 0x1000;
            local_398 = (char *)((ulonglong)local_398 & 0xffffffff00000000);
            local_3a0 = CONCAT44(local_3a0._4_4_,9999);
            local_3a8 = (char *)CONCAT44(local_3a8._4_4_,9999);
            MDprpcmp(lVar4 + 0x40,*(undefined4 *)(lVar4 + 0x38),*(undefined8 *)(lVar4 + 0x80),
                     *(undefined8 *)(*(longlong *)gevaldef_exref + 8));
            *(undefined8 *)gevaldef_exref = uVar2;
            break;
          }
          uVar7 = uVar7 + 1;
          piVar6 = piVar6 + 0xc;
        } while (uVar7 < uVar9);
      }
      DRstovnd(local_378,local_248);
    }
  }
  else {
    ERclear(0);
  }
  return;
}

/* RVA 0x37a50 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180037a50(void)

{
  uint *puVar1;
  undefined8 uVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  undefined1 auStack_3c8 [32];
  char *local_3a8;
  undefined8 local_3a0;
  char *local_398;
  undefined4 local_390;
  undefined8 local_388;
  undefined8 local_378;
  longlong local_370;
  undefined8 local_368;
  undefined8 uStack_360;
  undefined8 local_358;
  undefined8 uStack_350;
  undefined8 local_348;
  undefined8 uStack_340;
  undefined8 local_338;
  undefined8 uStack_330;
  undefined8 local_328;
  undefined8 uStack_320;
  undefined8 local_318;
  undefined8 uStack_310;
  undefined8 local_308;
  undefined8 uStack_300;
  undefined8 local_2f8;
  undefined8 local_2f0;
  undefined8 local_2e8;
  undefined8 uStack_2e0;
  undefined8 local_2d8;
  undefined8 uStack_2d0;
  undefined8 local_2c8;
  undefined8 uStack_2c0;
  undefined8 local_2b8;
  undefined8 uStack_2b0;
  undefined8 local_2a8;
  longlong lStack_2a0;
  undefined8 local_298;
  undefined8 uStack_290;
  undefined8 local_288;
  undefined8 uStack_280;
  undefined8 local_278;
  undefined8 uStack_270;
  undefined8 local_268;
  undefined8 uStack_260;
  undefined8 local_258;
  undefined1 local_248 [432];
  char local_98 [8];
  char local_90 [120];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_3c8;
  uVar2 = *(undefined8 *)gevaldef_exref;
  local_378 = 0;
  local_2f8 = 0;
  local_258 = 0;
  uStack_360 = 0;
  local_358 = 0;
  uStack_350 = 0;
  local_348 = 0;
  uStack_340 = 0;
  local_338 = 0;
  uStack_330 = 0;
  local_328 = 0;
  uStack_320 = 0;
  local_318 = 0;
  uStack_310 = 0;
  local_308 = 0;
  uStack_300 = 0;
  local_2e8 = 0;
  uStack_2e0 = 0;
  local_2d8 = 0;
  uStack_2d0 = 0;
  local_2c8 = 0;
  uStack_2c0 = 0;
  local_2b8 = 0;
  uStack_2b0 = 0;
  local_2a8 = 0;
  lStack_2a0 = 0;
  local_298 = 0;
  uStack_290 = 0;
  local_288 = 0;
  uStack_280 = 0;
  local_278 = 0;
  uStack_270 = 0;
  local_268 = 0;
  uStack_260 = 0;
  local_368 = *(undefined8 *)(*(longlong *)topfinfo_exref + 0x168);
  local_370 = MDfndkey(*(undefined8 *)iwpfile_exref,local_368,1,"DATABANKS");
  lVar4 = MDrslcls(*(undefined8 *)iwpfile_exref,local_368);
  lVar5 = local_370 * 0x108;
  local_2e8 = *(undefined8 *)recclass_exref;
  local_2f0 = MDfndkey(*(undefined8 *)recfile_exref,local_2e8,1,"DATABANKS");
  DRstovbg(&local_378,local_248,0);
  lVar3 = lStack_2a0;
  if (*(longlong *)(lStack_2a0 + 0x90) == 0) {
    local_3a0 = 0;
  }
  else {
    local_3a0 = MDgetito(*(undefined8 *)iwpfile_exref,*(undefined8 *)(lStack_2a0 + 0x98));
  }
  local_388 = 0;
  local_390 = 1;
  *(undefined8 *)geunbead_exref = local_3a0;
  local_90[0] = s_DATABANKS_180043b08[8];
  local_90[1] = s_DATABANKS_180043b08[9];
  local_98[0] = s_DATABANKS_180043b08[0];
  local_98[1] = s_DATABANKS_180043b08[1];
  local_98[2] = s_DATABANKS_180043b08[2];
  local_98[3] = s_DATABANKS_180043b08[3];
  local_98[4] = s_DATABANKS_180043b08[4];
  local_98[5] = s_DATABANKS_180043b08[5];
  local_98[6] = s_DATABANKS_180043b08[6];
  local_98[7] = s_DATABANKS_180043b08[7];
  *(undefined8 **)gevaldef_exref = &local_378;
  local_398 = local_98;
  local_3a8 = "DATABANKS";
  GEgenpar(lStack_2a0,uStack_310,uStack_300,0);
  puVar1 = (uint *)(lVar5 + lVar4 + 0x18);
  *puVar1 = *puVar1 | 0x1000;
  local_398 = (char *)((ulonglong)local_398 & 0xffffffff00000000);
  local_3a0 = CONCAT44(local_3a0._4_4_,9999);
  local_3a8 = (char *)CONCAT44(local_3a8._4_4_,9999);
  MDprpcmp(lVar3 + 0x40,*(undefined4 *)(lVar3 + 0x38),*(undefined8 *)(lVar3 + 0x80),
           *(undefined8 *)(*(longlong *)gevaldef_exref + 8));
  *(undefined8 *)gevaldef_exref = uVar2;
  return;
}

/* RVA 0x37ca0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180037ca0(void)

{
  undefined8 uVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  undefined1 auStack_3c8 [32];
  char *local_3a8;
  undefined8 local_3a0;
  char *local_398;
  undefined4 local_390;
  undefined8 local_388;
  undefined1 local_378 [8];
  undefined8 local_370;
  undefined8 local_368;
  undefined8 local_310;
  undefined8 local_300;
  longlong local_2a0;
  undefined1 local_248 [432];
  char local_98 [8];
  char local_90 [4];
  char local_8c;
  char local_89 [8];
  char local_81 [2];
  char local_7f;
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_3c8;
  uVar1 = *(undefined8 *)gevaldef_exref;
  memset(local_378,0,0x128);
  lVar3 = MDfndkey(*(undefined8 *)iwpfile_exref,*(undefined8 *)(*(longlong *)topfinfo_exref + 0x168)
                   ,1,"STREAM-CLASS");
  lVar4 = MDrslcls(*(undefined8 *)iwpfile_exref,*(undefined8 *)(*(longlong *)topfinfo_exref + 0x168)
                  );
  local_368 = *(undefined8 *)(lVar4 + 0x28 + lVar3 * 0x108);
  local_370 = MDfndkey(*(undefined8 *)iwpfile_exref,local_368,1,"SUBSTREAMS");
  if (*(longlong *)MDerror_exref == 0) {
    iVar2 = MDlenito(*(undefined8 *)iwpfile_exref,local_368,local_370);
    if (iVar2 != 0x178) {
      DRstovbg(local_378,local_248,0);
      local_90[0] = s_STREAM_CLASS_180043b60[8];
      local_90[1] = s_STREAM_CLASS_180043b60[9];
      local_90[2] = s_STREAM_CLASS_180043b60[10];
      local_90[3] = s_STREAM_CLASS_180043b60[0xb];
      local_8c = s_STREAM_CLASS_180043b60[0xc];
      local_81[0] = s_SUBSTREAMS_180043b70[8];
      local_81[1] = s_SUBSTREAMS_180043b70[9];
      local_98[0] = s_STREAM_CLASS_180043b60[0];
      local_98[1] = s_STREAM_CLASS_180043b60[1];
      local_98[2] = s_STREAM_CLASS_180043b60[2];
      local_98[3] = s_STREAM_CLASS_180043b60[3];
      local_98[4] = s_STREAM_CLASS_180043b60[4];
      local_98[5] = s_STREAM_CLASS_180043b60[5];
      local_98[6] = s_STREAM_CLASS_180043b60[6];
      local_98[7] = s_STREAM_CLASS_180043b60[7];
      local_7f = s_SUBSTREAMS_180043b70[10];
      local_89[0] = s_SUBSTREAMS_180043b70[0];
      local_89[1] = s_SUBSTREAMS_180043b70[1];
      local_89[2] = s_SUBSTREAMS_180043b70[2];
      local_89[3] = s_SUBSTREAMS_180043b70[3];
      local_89[4] = s_SUBSTREAMS_180043b70[4];
      local_89[5] = s_SUBSTREAMS_180043b70[5];
      local_89[6] = s_SUBSTREAMS_180043b70[6];
      local_89[7] = s_SUBSTREAMS_180043b70[7];
      if (*(longlong *)(local_2a0 + 0x90) == 0) {
        local_3a0 = 0;
      }
      else {
        local_3a0 = MDgetito(*(undefined8 *)iwpfile_exref,*(undefined8 *)(local_2a0 + 0x98));
      }
      local_388 = 0;
      local_390 = 2;
      *(undefined8 *)geunbead_exref = local_3a0;
      *(undefined1 **)gevaldef_exref = local_378;
      local_398 = local_98;
      local_3a8 = "SUBSTREAMS";
      GEgenpar(local_2a0,local_310,local_300,0);
      *(undefined8 *)gevaldef_exref = uVar1;
      DRstovnd(local_378,local_248);
    }
  }
  else {
    ERclear(0);
  }
  return;
}

/* RVA 0x37ee0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180037ee0(void)

{
  undefined8 uVar1;
  undefined8 uVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  undefined1 auStack_408 [32];
  undefined8 *local_3e8;
  undefined8 local_3e0;
  undefined4 *local_3d8;
  undefined4 local_3d0;
  undefined8 local_3c8;
  undefined1 local_3b8 [8];
  longlong local_3b0;
  undefined8 local_3a8;
  longlong local_2e0;
  undefined8 local_288 [6];
  undefined1 local_258 [432];
  undefined4 local_a8 [32];
  ulonglong local_28;
  
  local_28 = DAT_1800516d8 ^ (ulonglong)auStack_408;
  uVar1 = *(undefined8 *)gevaldef_exref;
  uVar2 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)(*(longlong *)topfinfo_exref + 0x168)
                   ,"STREAM-CLASS");
  uVar2 = MDfnddir(*(undefined8 *)iwpfile_exref,uVar2,"SUBS-ATTR");
  lVar3 = MDrslcls(*(undefined8 *)iwpfile_exref,uVar2);
  uVar2 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)(lVar3 + 0x148),&DAT_180043b8c);
  lVar4 = MDrslcls(*(undefined8 *)iwpfile_exref,uVar2);
  local_288[0] = 0;
  local_3e8 = local_288;
  local_3e0 = 0;
  lVar3 = MDfndsls(*(undefined8 *)iwpfile_exref,uVar2,1,0);
  while (lVar3 != -1) {
    lVar5 = lVar3 * 0x108 + lVar4;
    if (((byte)*(undefined4 *)(lVar5 + 0x18) & 0xf) == 1) {
      memset(local_3b8,0,0x128);
      local_3b0 = lVar3;
      local_3a8 = uVar2;
      DRstovbg(local_3b8,local_258,0);
      *(undefined1 **)gevaldef_exref = local_3b8;
      if (*(longlong *)(local_2e0 + 0x90) == 0) {
        local_3e0 = 0;
      }
      else {
        local_3e0 = MDgetito(*(undefined8 *)iwpfile_exref,*(undefined8 *)(local_2e0 + 0x98));
      }
      local_3c8 = 0;
      local_3d0 = 1;
      *(undefined8 *)geunbead_exref = local_3e0;
      local_a8[0] = 0x445350;
      lVar3 = *(longlong *)gevaldef_exref;
      local_3d8 = local_a8;
      local_3e8 = (undefined8 *)lVar5;
      GEgenpar(*(undefined8 *)(lVar3 + 0xd8),*(undefined8 *)(lVar3 + 0x68),
               *(undefined8 *)(lVar3 + 0x78),0);
      DRstovnd(local_3b8,local_258);
    }
    local_3e8 = local_288;
    local_3e0 = 0;
    lVar3 = MDfndsls(*(undefined8 *)iwpfile_exref,uVar2,1);
  }
  *(undefined8 *)gevaldef_exref = uVar1;
  return;
}

/* RVA 0x38160 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180038160(void)

{
  uint *puVar1;
  undefined8 uVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  undefined1 auStack_3c8 [32];
  char *local_3a8;
  undefined8 local_3a0;
  char *local_398;
  undefined4 local_390;
  undefined8 local_388;
  undefined8 local_378;
  longlong local_370;
  undefined8 local_368;
  undefined8 uStack_360;
  undefined8 local_358;
  undefined8 uStack_350;
  undefined8 local_348;
  undefined8 uStack_340;
  undefined8 local_338;
  undefined8 uStack_330;
  undefined8 local_328;
  undefined8 uStack_320;
  undefined8 local_318;
  undefined8 uStack_310;
  undefined8 local_308;
  undefined8 uStack_300;
  undefined8 local_2f8;
  undefined8 local_2f0;
  undefined8 local_2e8;
  undefined8 uStack_2e0;
  undefined8 local_2d8;
  undefined8 uStack_2d0;
  undefined8 local_2c8;
  undefined8 uStack_2c0;
  undefined8 local_2b8;
  undefined8 uStack_2b0;
  undefined8 local_2a8;
  longlong lStack_2a0;
  undefined8 local_298;
  undefined8 uStack_290;
  undefined8 local_288;
  undefined8 uStack_280;
  undefined8 local_278;
  undefined8 uStack_270;
  undefined8 local_268;
  undefined8 uStack_260;
  undefined8 local_258;
  undefined1 local_248 [432];
  char local_98 [8];
  char local_90 [2];
  char local_8e;
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_3c8;
  uVar2 = *(undefined8 *)gevaldef_exref;
  local_378 = 0;
  local_2f8 = 0;
  local_258 = 0;
  uStack_360 = 0;
  local_358 = 0;
  uStack_350 = 0;
  local_348 = 0;
  uStack_340 = 0;
  local_338 = 0;
  uStack_330 = 0;
  local_328 = 0;
  uStack_320 = 0;
  local_318 = 0;
  uStack_310 = 0;
  local_308 = 0;
  uStack_300 = 0;
  local_2e8 = 0;
  uStack_2e0 = 0;
  local_2d8 = 0;
  uStack_2d0 = 0;
  local_2c8 = 0;
  uStack_2c0 = 0;
  local_2b8 = 0;
  uStack_2b0 = 0;
  local_2a8 = 0;
  lStack_2a0 = 0;
  local_298 = 0;
  uStack_290 = 0;
  local_288 = 0;
  uStack_280 = 0;
  local_278 = 0;
  uStack_270 = 0;
  local_268 = 0;
  uStack_260 = 0;
  local_368 = *(undefined8 *)(*(longlong *)topfinfo_exref + 0x168);
  local_370 = MDfndkey(*(undefined8 *)iwpfile_exref,local_368,1,"ODATABANKS");
  if (*(longlong *)MDerror_exref == 0) {
    lVar4 = MDrslcls(*(undefined8 *)iwpfile_exref,local_368);
    lVar5 = local_370 * 0x108;
    local_2e8 = *(undefined8 *)recclass_exref;
    local_2f0 = MDfndkey(*(undefined8 *)recfile_exref,local_2e8,1,"ODATABANKS");
    DRstovbg(&local_378,local_248,0);
    lVar3 = lStack_2a0;
    if (*(longlong *)(lStack_2a0 + 0x90) == 0) {
      local_3a0 = 0;
    }
    else {
      local_3a0 = MDgetito(*(undefined8 *)iwpfile_exref,*(undefined8 *)(lStack_2a0 + 0x98));
    }
    local_388 = 0;
    local_390 = 1;
    *(undefined8 *)geunbead_exref = local_3a0;
    local_90[0] = s_ODATABANKS_180043b18[8];
    local_90[1] = s_ODATABANKS_180043b18[9];
    local_8e = s_ODATABANKS_180043b18[10];
    local_98[0] = s_ODATABANKS_180043b18[0];
    local_98[1] = s_ODATABANKS_180043b18[1];
    local_98[2] = s_ODATABANKS_180043b18[2];
    local_98[3] = s_ODATABANKS_180043b18[3];
    local_98[4] = s_ODATABANKS_180043b18[4];
    local_98[5] = s_ODATABANKS_180043b18[5];
    local_98[6] = s_ODATABANKS_180043b18[6];
    local_98[7] = s_ODATABANKS_180043b18[7];
    *(undefined8 **)gevaldef_exref = &local_378;
    local_398 = local_98;
    local_3a8 = "ODATABANKS";
    GEgenpar(lStack_2a0,uStack_310,uStack_300,0);
    puVar1 = (uint *)(lVar5 + lVar4 + 0x18);
    *puVar1 = *puVar1 | 0x1000;
    local_398 = (char *)((ulonglong)local_398 & 0xffffffff00000000);
    local_3a0 = CONCAT44(local_3a0._4_4_,9999);
    local_3a8 = (char *)CONCAT44(local_3a8._4_4_,9999);
    MDprpcmp(lVar3 + 0x40,*(undefined4 *)(lVar3 + 0x38),*(undefined8 *)(lVar3 + 0x80),
             *(undefined8 *)(*(longlong *)gevaldef_exref + 8));
    *(undefined8 *)gevaldef_exref = uVar2;
  }
  else {
    ERclear(0);
  }
  return;
}

/* RVA 0x383e0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1800383e0(int param_1)

{
  uint *puVar1;
  undefined8 uVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  int *piVar6;
  ulonglong uVar7;
  uint uVar8;
  ulonglong uVar9;
  uint uVar10;
  undefined1 auStack_3c8 [32];
  char *local_3a8;
  ulonglong local_3a0;
  char *local_398;
  undefined4 local_390;
  undefined8 local_388;
  undefined1 local_378 [8];
  longlong local_370;
  undefined8 local_368;
  uint *local_310;
  undefined8 local_300;
  longlong local_2a0;
  undefined1 local_248 [432];
  char local_98 [4];
  char local_94 [11];
  char local_89 [8];
  char local_81 [105];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_3c8;
  uVar2 = *(undefined8 *)gevaldef_exref;
  memset(local_378,0,0x128);
  lVar4 = MDfndkey(*(undefined8 *)iwpfile_exref,*(undefined8 *)(*(longlong *)topfinfo_exref + 0x168)
                   ,1,"SETUP");
  lVar5 = MDrslcls(*(undefined8 *)iwpfile_exref,*(undefined8 *)(*(longlong *)topfinfo_exref + 0x168)
                  );
  local_368 = *(undefined8 *)(lVar5 + 0x28 + lVar4 * 0x108);
  local_370 = MDfndkey(*(undefined8 *)iwpfile_exref,local_368,1,"SIM-OPTIONS");
  if (*(longlong *)MDerror_exref == 0) {
    iVar3 = MDlenito(*(undefined8 *)iwpfile_exref,local_368,local_370);
    if (iVar3 != 0x178) {
      lVar4 = MDrslcls(*(undefined8 *)iwpfile_exref,local_368);
      lVar4 = local_370 * 0x108 + lVar4;
      if ((param_1 == 0) || ((*(uint *)(lVar4 + 0x18) & 0xe00) != 0)) {
        DRstovbg(local_378,local_248,0);
        lVar5 = local_2a0;
        uVar7 = 0;
        uVar10 = *local_310 >> 7 & 0x1ff;
        if (uVar10 != 0) {
          piVar6 = (int *)((longlong)local_310 + (ulonglong)local_310[1] + 4);
          uVar9 = uVar7;
          do {
            if ((*(byte *)(*piVar6 + local_2a0) & 1) != 0) {
              local_98[0] = s_SETUP_180043b24[0];
              local_98[1] = s_SETUP_180043b24[1];
              local_98[2] = s_SETUP_180043b24[2];
              local_98[3] = s_SETUP_180043b24[3];
              local_94[0] = s_SETUP_180043b24[4];
              local_94[1] = s_SETUP_180043b24[5];
              local_81[0] = s_SIM_OPTIONS_180043b40[8];
              local_81[1] = s_SIM_OPTIONS_180043b40[9];
              local_81[2] = s_SIM_OPTIONS_180043b40[10];
              local_81[3] = s_SIM_OPTIONS_180043b40[0xb];
              local_89[0] = s_SIM_OPTIONS_180043b40[0];
              local_89[1] = s_SIM_OPTIONS_180043b40[1];
              local_89[2] = s_SIM_OPTIONS_180043b40[2];
              local_89[3] = s_SIM_OPTIONS_180043b40[3];
              local_89[4] = s_SIM_OPTIONS_180043b40[4];
              local_89[5] = s_SIM_OPTIONS_180043b40[5];
              local_89[6] = s_SIM_OPTIONS_180043b40[6];
              local_89[7] = s_SIM_OPTIONS_180043b40[7];
              if (*(longlong *)(local_2a0 + 0x90) != 0) {
                uVar7 = MDgetito(*(undefined8 *)iwpfile_exref,*(undefined8 *)(local_2a0 + 0x98));
              }
              local_388 = 0;
              local_390 = 2;
              *(ulonglong *)geunbead_exref = uVar7;
              *(undefined1 **)gevaldef_exref = local_378;
              local_398 = local_98;
              local_3a8 = "SIM-OPTIONS";
              local_3a0 = uVar7;
              GEgenpar(local_2a0,local_310,local_300,0);
              puVar1 = (uint *)(lVar4 + 0x18);
              *puVar1 = *puVar1 | 0x1000;
              local_398 = (char *)((ulonglong)local_398 & 0xffffffff00000000);
              local_3a0 = CONCAT44(local_3a0._4_4_,9999);
              local_3a8 = (char *)CONCAT44(local_3a8._4_4_,9999);
              MDprpcmp(lVar5 + 0x40,*(undefined4 *)(lVar5 + 0x38),*(undefined8 *)(lVar5 + 0x80),
                       *(undefined8 *)(*(longlong *)gevaldef_exref + 8));
              *(undefined8 *)gevaldef_exref = uVar2;
              break;
            }
            uVar8 = (int)uVar9 + 1;
            uVar9 = (ulonglong)uVar8;
            piVar6 = piVar6 + 0xc;
          } while (uVar8 < uVar10);
        }
        DRstovnd(local_378,local_248);
      }
    }
  }
  else {
    ERclear(0);
  }
  return;
}

/* RVA 0x386e0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1800386e0(void)

{
  undefined8 uVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  undefined1 auStack_3c8 [32];
  char *local_3a8;
  undefined8 local_3a0;
  char *local_398;
  undefined4 local_390;
  undefined8 local_388;
  undefined1 local_378 [8];
  undefined8 local_370;
  undefined8 local_368;
  undefined8 local_310;
  undefined8 local_300;
  longlong local_2a0;
  undefined1 local_248 [432];
  char local_98 [8];
  char local_90 [4];
  char local_8c;
  char local_89 [8];
  char local_81 [4];
  char local_7d;
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_3c8;
  uVar1 = *(undefined8 *)gevaldef_exref;
  memset(local_378,0,0x128);
  lVar3 = MDfndkey(*(undefined8 *)iwpfile_exref,*(undefined8 *)(*(longlong *)topfinfo_exref + 0x168)
                   ,1,"STREAM-CLASS");
  lVar4 = MDrslcls(*(undefined8 *)iwpfile_exref,*(undefined8 *)(*(longlong *)topfinfo_exref + 0x168)
                  );
  local_368 = *(undefined8 *)(lVar4 + 0x28 + lVar3 * 0x108);
  local_370 = MDfndkey(*(undefined8 *)iwpfile_exref,local_368,1,"STREAM-CLASS");
  if (*(longlong *)MDerror_exref == 0) {
    iVar2 = MDlenito(*(undefined8 *)iwpfile_exref,local_368,local_370);
    if (iVar2 != 0x178) {
      DRstovbg(local_378,local_248,0);
      local_98[0] = s_STREAM_CLASS_180043b60[0];
      local_98[1] = s_STREAM_CLASS_180043b60[1];
      local_98[2] = s_STREAM_CLASS_180043b60[2];
      local_98[3] = s_STREAM_CLASS_180043b60[3];
      local_98[4] = s_STREAM_CLASS_180043b60[4];
      local_98[5] = s_STREAM_CLASS_180043b60[5];
      local_98[6] = s_STREAM_CLASS_180043b60[6];
      local_98[7] = s_STREAM_CLASS_180043b60[7];
      local_90[0] = s_STREAM_CLASS_180043b60[8];
      local_90[1] = s_STREAM_CLASS_180043b60[9];
      local_90[2] = s_STREAM_CLASS_180043b60[10];
      local_90[3] = s_STREAM_CLASS_180043b60[0xb];
      local_8c = s_STREAM_CLASS_180043b60[0xc];
      local_89[0] = s_STREAM_CLASS_180043b60[0];
      local_89[1] = s_STREAM_CLASS_180043b60[1];
      local_89[2] = s_STREAM_CLASS_180043b60[2];
      local_89[3] = s_STREAM_CLASS_180043b60[3];
      local_89[4] = s_STREAM_CLASS_180043b60[4];
      local_89[5] = s_STREAM_CLASS_180043b60[5];
      local_89[6] = s_STREAM_CLASS_180043b60[6];
      local_89[7] = s_STREAM_CLASS_180043b60[7];
      local_81[0] = s_STREAM_CLASS_180043b60[8];
      local_81[1] = s_STREAM_CLASS_180043b60[9];
      local_81[2] = s_STREAM_CLASS_180043b60[10];
      local_81[3] = s_STREAM_CLASS_180043b60[0xb];
      local_7d = s_STREAM_CLASS_180043b60[0xc];
      if (*(longlong *)(local_2a0 + 0x90) == 0) {
        local_3a0 = 0;
      }
      else {
        local_3a0 = MDgetito(*(undefined8 *)iwpfile_exref,*(undefined8 *)(local_2a0 + 0x98));
      }
      local_388 = 0;
      local_390 = 2;
      *(undefined8 *)geunbead_exref = local_3a0;
      *(undefined1 **)gevaldef_exref = local_378;
      local_398 = local_98;
      local_3a8 = "SUBSTREAMS";
      GEgenpar(local_2a0,local_310,local_300,0);
      *(undefined8 *)gevaldef_exref = uVar1;
      DRstovnd(local_378,local_248);
    }
  }
  else {
    ERclear(0);
  }
  return;
}

/* RVA 0x38910 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_180038910(void)

{
  undefined4 uVar1;
  undefined1 auStack_328 [32];
  undefined8 local_308;
  char *local_2f8;
  undefined8 local_2f0;
  undefined8 local_2e8;
  longlong *local_1e0;
  undefined1 local_1c8 [432];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_328;
  uVar1 = 0;
  memset(&local_2f8,0,0x128);
  local_2e8 = MDfnddir(*(undefined8 *)iwpfile_exref,
                       *(undefined8 *)(*(longlong *)topfinfo_exref + 0x168),"SETUP");
  local_2f0 = MDfndkey(*(undefined8 *)iwpfile_exref,local_2e8,1,"SIM-OPTIONS");
  if (*(longlong *)MDerror_exref == 0) {
    DRstovbg(&local_2f8,local_1c8,0);
    local_308 = 0;
    local_2f8 = "FREE-WATER";
    MDfndvar("FREE-WATER",1,0,&local_2f8);
    if ((local_1e0 != (longlong *)0x0) && (uVar1 = 0, *local_1e0 == 0)) {
      uVar1 = 1;
    }
    DRstovnd(&local_2f8,local_1c8);
  }
  else {
    ERclear(0);
    uVar1 = 0;
  }
  return uVar1;
}

/* RVA 0x38a30 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180038a30(longlong param_1,int param_2,undefined4 param_3,char *param_4)

{
  longlong *plVar1;
  code cVar2;
  char cVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  longlong lVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  undefined8 uVar11;
  longlong lVar12;
  longlong lVar13;
  longlong lVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  code *pcVar20;
  undefined4 *puVar21;
  int *piVar22;
  uint uVar23;
  longlong lVar24;
  uint uVar25;
  char *pcVar26;
  undefined4 uVar27;
  undefined1 auStack_688 [32];
  undefined8 local_668;
  undefined8 local_660;
  undefined8 local_658;
  int local_650;
  undefined8 local_648;
  uint local_638;
  int local_634;
  int local_630;
  undefined8 local_628;
  undefined1 local_618 [8];
  longlong local_610;
  longlong local_608;
  uint *local_5b0;
  longlong local_540;
  undefined8 local_4e8;
  undefined8 uStack_4e0;
  undefined8 local_4d8 [6];
  undefined1 local_4a8 [432];
  char local_2f8 [4];
  char acStack_2f4 [4];
  char local_2f0 [2];
  char local_2ee;
  undefined1 local_2ea;
  char local_2e9 [112];
  undefined4 uStack_279;
  undefined1 local_274 [268];
  undefined1 local_168 [304];
  ulonglong local_38;
  
  local_38 = DAT_1800516d8 ^ (ulonglong)auStack_688;
  local_4e8 = 0;
  uStack_4e0 = 0;
  *(undefined4 *)threephase_exref = 0;
  *(undefined4 *)editrun_exref = 0;
  local_630 = param_2;
  GRseteditrun(0);
  iVar10 = *(int *)sbcanned_exref;
  *(undefined4 *)sbcanned_exref = 0;
  memset(local_618,0,0x128);
  local_608 = *(longlong *)(analysis_ditem_exref + 8);
  local_610 = *(longlong *)analysis_ditem_exref;
  if (local_608 == -1) {
    return 0;
  }
  if (local_610 == -1) {
    return 0;
  }
  OPdelete_notify(&local_610);
  clean_buffer(*(undefined8 *)(*(longlong *)topfinfo_exref + 0x520));
  DRstovbg(local_618,local_4a8,0);
  if (param_2 != 0) {
    plVar1 = (longlong *)(param_1 + 8);
    uVar11 = MDgetito(*(undefined8 *)iwpfile_exref,*(undefined8 *)(param_1 + 0x10),*plVar1);
    *(undefined8 *)(param_1 + 0xd8) = uVar11;
    MDgetrdf(param_1);
    lVar12 = MDrslcls(*(undefined8 *)recfile_exref,*(undefined8 *)(param_1 + 0x90));
    iVar9 = strcmp((char *)(*(longlong *)(param_1 + 0x88) * 0x108 + lVar12),"MATERIAL");
    if (iVar9 != 0) {
      return 0;
    }
    lVar12 = MDrslcls(*(undefined8 *)iwpfile_exref,*(undefined8 *)(param_1 + 0x10));
    uVar23 = *(uint *)(*plVar1 * 0x108 + 0x18 + lVar12);
    HYdspnam(plVar1,&local_4e8,&DAT_180052fe0,0x100);
    local_638 = (uint)((uVar23 & 0xe00) != 0);
  }
  iVar9 = 0;
  MDrslcls(*(undefined8 *)iwpfile_exref,*(undefined8 *)(*(longlong *)topfinfo_exref + 0x168));
  lVar12 = MDfndkey(*(undefined8 *)iwpfile_exref,
                    *(undefined8 *)(*(longlong *)topfinfo_exref + 0x168),1,"COMPONENTS");
  lVar13 = MDfndkey(*(undefined8 *)iwpfile_exref,
                    *(undefined8 *)(*(longlong *)topfinfo_exref + 0x168),1,"PROPERTIES");
  lVar14 = MDrslcls(*(undefined8 *)iwpfile_exref,
                    *(undefined8 *)(*(longlong *)topfinfo_exref + 0x168));
  if (((byte)*(undefined4 *)(lVar12 * 0x108 + 0x18 + lVar14) & 0xf) != 1) {
    uVar11 = 0x46f;
LAB_180038c99:
    uVar11 = GetSorResStringEx(uVar11);
    local_648 = CONCAT44(local_648._4_4_,0xffffffff);
    local_650 = 1;
    local_658 = (char *)0x0;
    local_660 = 0;
    local_668 = (char *)0x0;
    open_message_box(0,uVar11,&DAT_1800408b0,0);
    return 0;
  }
  if (((byte)*(undefined4 *)(lVar13 * 0x108 + 0x18 + lVar14) & 0xf) != 1) {
    uVar11 = 0x470;
    goto LAB_180038c99;
  }
  *(undefined4 *)sbcanned_exref = param_3;
  if (iVar10 != 0) {
    *(int *)sbcanned_exref = iVar10;
  }
  pcVar20 = APtmpfil_exref;
  do {
    cVar2 = *pcVar20;
    pcVar20[(longlong)(local_2e9 + (0x71 - (longlong)APtmpfil_exref))] = cVar2;
    pcVar20 = pcVar20 + 1;
  } while (cVar2 != (code)0x0);
  puVar8 = &uStack_279;
  do {
    puVar21 = puVar8;
    puVar8 = (undefined4 *)((longlong)puVar21 + 1);
  } while (*(char *)((longlong)puVar21 + 1) != '\0');
  *(undefined4 *)((longlong)puVar21 + 1) = DAT_180041718;
  *(undefined1 *)((longlong)puVar21 + 5) = DAT_18004171c;
  remove((char *)((longlong)&uStack_279 + 1));
  uVar11 = GEopenfile((longlong)&uStack_279 + 1);
  local_628 = uVar11;
  iVar10 = GRinqgpd();
  if ((((iVar10 != 0) && (*(int *)(*(longlong *)topfinfo_exref + 0x1dc) != 0)) &&
      (*(int *)(*(longlong *)topfinfo_exref + 0x660) == 0)) && (param_2 == 0)) {
    goto LAB_1800393a8;
  }
  local_634 = 1;
  if (*(int *)partial_results_exref == 0) {
LAB_180038e50:
    if (((*(int *)(*(longlong *)topfinfo_exref + 0x380) == 1) ||
        ((*(int *)partial_results_exref != 0 || (iVar10 = GRinqiap(), iVar10 != 1)))) ||
       (*(int *)triggered_by_canned_exref != 0)) {
      lVar12 = *(longlong *)topfinfo_exref;
      if ((((*(int *)(lVar12 + 0x380) != 1) && (*(int *)(lVar12 + 0x14c) != 0)) &&
          (*(int *)(lVar12 + 0x158) != 0)) &&
         ((*(int *)(lVar12 + 0x660) == 0 && (iVar10 = GRinqQRs(), iVar10 == 0)))) {
        FUN_1800282b0("");
        FUN_1800282b0("After running this analysis, you must re-run the problem");
        FUN_1800282b0("before you will be able to export report files.");
      }
    }
    else {
      FUN_1800282b0("");
      FUN_1800282b0("Simulation results are being cleared because you are running an analysis");
      FUN_1800282b0("in the Properties environment.");
      GRsetpgc(1);
    }
  }
  else {
    iVar10 = GRinqiap();
    if ((iVar10 != 1) || (*(int *)triggered_by_canned_exref != 0)) goto LAB_180038e50;
    uVar27 = *(undefined4 *)sbcanned_exref;
    *(undefined4 *)sbcanned_exref = 0;
    iVar10 = _guard_check_icall();
    if (iVar10 == 0) {
      GEclosefile(uVar11);
      *(undefined4 *)sbcanned_exref = 0;
      return 0;
    }
    *(undefined4 *)sbcanned_exref = uVar27;
  }
  local_658 = (char *)((ulonglong)local_658._4_4_ << 0x20);
  local_660 = (ulonglong)local_660._4_4_ << 0x20;
  local_668 = (char *)((ulonglong)local_668._4_4_ << 0x20);
  *(undefined1 **)gevaldef_exref = local_618;
  GEwrtwrd(0,&DAT_180043c70,2);
  GEaddbef();
  iVar10 = GRinqaped();
  if (iVar10 != 0) {
    FUN_180038160();
  }
  FUN_180037a50();
  FUN_180037220();
  FUN_1800383e0(0);
  FUN_180037760();
  uVar11 = MDfnddir(*(undefined8 *)recfile_exref,*(undefined8 *)recclass_exref,"COMPONENTS");
  uVar18 = MDfnddir(*(undefined8 *)iwpfile_exref,
                    *(undefined8 *)(*(longlong *)topfinfo_exref + 0x168),"COMPONENTS");
  uVar19 = MDfnddir(*(undefined8 *)recfile_exref,*(undefined8 *)recclass_exref,"PROPERTIES");
  uVar15 = MDfnddir(*(undefined8 *)iwpfile_exref,
                    *(undefined8 *)(*(longlong *)topfinfo_exref + 0x168),"PROPERTIES");
  uVar16 = MDfnddir(*(undefined8 *)recfile_exref,*(undefined8 *)recclass_exref,"PROP-SET");
  uVar17 = MDfnddir(*(undefined8 *)iwpfile_exref,
                    *(undefined8 *)(*(longlong *)topfinfo_exref + 0x168),"PROP-SET");
  memset(local_618,0,0x128);
  local_2f0[0] = s_COMPONENTS_180041378[8];
  local_2f0[1] = s_COMPONENTS_180041378[9];
  local_2ee = s_COMPONENTS_180041378[10];
  local_2f8[0] = s_COMPONENTS_180041378[0];
  local_2f8[1] = s_COMPONENTS_180041378[1];
  local_2f8[2] = s_COMPONENTS_180041378[2];
  local_2f8[3] = s_COMPONENTS_180041378[3];
  acStack_2f4[0] = s_COMPONENTS_180041378[4];
  acStack_2f4[1] = s_COMPONENTS_180041378[5];
  acStack_2f4[2] = s_COMPONENTS_180041378[6];
  acStack_2f4[3] = s_COMPONENTS_180041378[7];
  local_2ea = 0;
  GEloorec(uVar11,local_2f8,1,uVar18);
  FUN_18002c180(uVar18);
  local_2f0[0] = s_PROPERTIES_180041428[8];
  local_2f0[1] = s_PROPERTIES_180041428[9];
  local_2ee = s_PROPERTIES_180041428[10];
  local_2f8[0] = s_PROPERTIES_180041428[0];
  local_2f8[1] = s_PROPERTIES_180041428[1];
  local_2f8[2] = s_PROPERTIES_180041428[2];
  local_2f8[3] = s_PROPERTIES_180041428[3];
  acStack_2f4[0] = s_PROPERTIES_180041428[4];
  acStack_2f4[1] = s_PROPERTIES_180041428[5];
  acStack_2f4[2] = s_PROPERTIES_180041428[6];
  acStack_2f4[3] = s_PROPERTIES_180041428[7];
  *(undefined4 *)called_from_analysis_exref = 1;
  GEloorec(uVar19,local_2f8,1,uVar15);
  FUN_18002c180(uVar15);
  local_2f8[0] = s_PROP_SET_180043c78[0];
  local_2f8[1] = s_PROP_SET_180043c78[1];
  local_2f8[2] = s_PROP_SET_180043c78[2];
  local_2f8[3] = s_PROP_SET_180043c78[3];
  acStack_2f4[0] = s_PROP_SET_180043c78[4];
  acStack_2f4[1] = s_PROP_SET_180043c78[5];
  acStack_2f4[2] = s_PROP_SET_180043c78[6];
  acStack_2f4[3] = s_PROP_SET_180043c78[7];
  local_2f0[0] = s_PROP_SET_180043c78[8];
  GEloorec(uVar16,local_2f8,1,uVar17);
  FUN_18002c180(uVar17);
  *(undefined4 *)called_from_analysis_exref = 0;
  generate_polymers();
  FUN_180037500();
  lVar13 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"CHEMISTRY");
  lVar14 = MDrslcls(*(undefined8 *)iwpfile_exref,lVar13);
  local_4d8[0] = 0;
  local_668 = (char *)local_4d8;
  local_660 = 0;
  lVar12 = MDfndsls(*(undefined8 *)iwpfile_exref,lVar13,1,0);
  iVar9 = local_634;
  param_2 = local_630;
  uVar11 = local_628;
  while( true ) {
    local_630 = param_2;
    local_628 = uVar11;
    if (lVar12 == -1) break;
    lVar24 = lVar12 * 0x108 + lVar14;
    if (((byte)*(undefined4 *)(lVar24 + 0x18) & 0xf) == (byte)iVar9) {
      memset(local_618,0,0x128);
      local_610 = lVar12;
      local_608 = lVar13;
      DRstovbg(local_618,local_4a8,0);
      lVar12 = local_540;
      *(undefined1 **)gevaldef_exref = local_618;
      if (*(longlong *)(local_540 + 0x90) == 0) {
        local_660 = 0;
      }
      else {
        local_660 = MDgetito(*(undefined8 *)iwpfile_exref,*(undefined8 *)(local_540 + 0x98));
      }
      local_648 = 0;
      local_650 = iVar9;
      *(ulonglong *)geunbead_exref = local_660;
      local_2f0[0] = s_CHEMISTRY_180043c88[8];
      local_2f0[1] = s_CHEMISTRY_180043c88[9];
      local_2f8[0] = s_CHEMISTRY_180043c88[0];
      local_2f8[1] = s_CHEMISTRY_180043c88[1];
      local_2f8[2] = s_CHEMISTRY_180043c88[2];
      local_2f8[3] = s_CHEMISTRY_180043c88[3];
      acStack_2f4[0] = s_CHEMISTRY_180043c88[4];
      acStack_2f4[1] = s_CHEMISTRY_180043c88[5];
      acStack_2f4[2] = s_CHEMISTRY_180043c88[6];
      acStack_2f4[3] = s_CHEMISTRY_180043c88[7];
      lVar7 = *(longlong *)gevaldef_exref;
      local_658 = local_2f8;
      local_668 = (char *)lVar24;
      GEgenpar(*(undefined8 *)(lVar7 + 0xd8),*(undefined8 *)(lVar7 + 0x68),
               *(undefined8 *)(lVar7 + 0x78),0);
    }
    else {
      lVar12 = MDgetito(*(undefined8 *)iwpfile_exref,lVar13,lVar12);
      local_658._0_4_ = iVar9;
      local_660 = local_660 & 0xffffffff00000000;
      local_668 = (char *)((ulonglong)local_668 & 0xffffffff00000000);
      GEwrtwrd(0,"CHEMISTRY",2,iVar9);
      local_658 = (char *)((ulonglong)local_658._4_4_ << 0x20);
      local_660 = local_660 & 0xffffffff00000000;
      local_668 = (char *)CONCAT44(local_668._4_4_,iVar9);
      GEwrtwrd(0,lVar24,0,iVar9);
    }
    *(uint *)(lVar24 + 0x18) = *(uint *)(lVar24 + 0x18) | 0x1000;
    local_658 = (char *)((ulonglong)local_658 & 0xffffffff00000000);
    local_660 = CONCAT44(local_660._4_4_,9999);
    local_668 = (char *)CONCAT44(local_668._4_4_,9999);
    MDprpcmp(lVar12 + 0x40,*(undefined4 *)(lVar12 + 0x38),*(undefined8 *)(lVar12 + 0x80));
    local_668 = (char *)local_4d8;
    local_660 = 0;
    lVar12 = MDfndsls(*(undefined8 *)iwpfile_exref,lVar13,iVar9);
    param_2 = local_630;
    uVar11 = local_628;
  }
LAB_1800393a8:
  uVar18 = 0;
  memset(local_618,0,0x128);
  local_608 = MDfnddir(*(undefined8 *)iwpfile_exref,
                       *(undefined8 *)(*(longlong *)topfinfo_exref + 0x168),"SETUP");
  local_610 = MDfndkey(*(undefined8 *)iwpfile_exref,local_608,1,"GLOBAL");
  if (*(longlong *)MDerror_exref == 0) {
    DRstovbg(local_618,local_4a8,0);
    *(undefined1 **)gevaldef_exref = local_618;
    if (*(longlong *)(local_540 + 0x90) == 0) {
      local_660 = 0;
    }
    else {
      local_660 = MDgetito(*(undefined8 *)iwpfile_exref,*(undefined8 *)(local_540 + 0x98));
    }
    local_648 = 0;
    local_650 = 1;
    *(ulonglong *)geunbead_exref = local_660;
    acStack_2f4[0] = s_SETUP_180043b24[4];
    acStack_2f4[1] = s_SETUP_180043b24[5];
    local_2f8[0] = s_SETUP_180043b24[0];
    local_2f8[1] = s_SETUP_180043b24[1];
    local_2f8[2] = s_SETUP_180043b24[2];
    local_2f8[3] = s_SETUP_180043b24[3];
    lVar12 = *(longlong *)gevaldef_exref;
    local_658 = local_2f8;
    local_668 = "GLOBAL";
    GEgenpar(*(undefined8 *)(lVar12 + 0xd8),*(undefined8 *)(lVar12 + 0x68),
             *(undefined8 *)(lVar12 + 0x78),0);
    DRstovnd(local_618);
  }
  else {
    ERclear(0);
  }
  memset(local_618,0,0x128);
  local_608 = MDfnddir(*(undefined8 *)iwpfile_exref,
                       *(undefined8 *)(*(longlong *)topfinfo_exref + 0x168),"SETUP");
  local_610 = MDfndkey(*(undefined8 *)iwpfile_exref,local_608,1,"DIAGNOSTICS");
  if (*(longlong *)MDerror_exref == 0) {
    DRstovbg(local_618,local_4a8,0);
    uVar23 = 0;
    *(undefined1 **)gevaldef_exref = local_618;
    uVar25 = *local_5b0 >> 7 & 0x1ff;
    if (uVar25 != 0) {
      piVar22 = (int *)((ulonglong)local_5b0[1] + 4 + (longlong)local_5b0);
      do {
        if ((*(byte *)(*piVar22 + local_540) & 1) != 0) {
          if (*(longlong *)(*(longlong *)(*(longlong *)gevaldef_exref + 0xd8) + 0x90) == 0) {
            local_660 = 0;
          }
          else {
            local_660 = MDgetito(*(undefined8 *)iwpfile_exref,
                                 *(undefined8 *)
                                  (*(longlong *)(*(longlong *)gevaldef_exref + 0xd8) + 0x98));
          }
          local_648 = 0;
          local_650 = 1;
          *(ulonglong *)geunbead_exref = local_660;
          acStack_2f4[0] = s_SETUP_180043b24[4];
          acStack_2f4[1] = s_SETUP_180043b24[5];
          local_2f8[0] = s_SETUP_180043b24[0];
          local_2f8[1] = s_SETUP_180043b24[1];
          local_2f8[2] = s_SETUP_180043b24[2];
          local_2f8[3] = s_SETUP_180043b24[3];
          lVar12 = *(longlong *)gevaldef_exref;
          local_658 = local_2f8;
          local_668 = "DIAGNOSTICS";
          GEgenpar(*(undefined8 *)(lVar12 + 0xd8),*(undefined8 *)(lVar12 + 0x68),
                   *(undefined8 *)(lVar12 + 0x78),0);
          break;
        }
        uVar23 = uVar23 + 1;
        piVar22 = piVar22 + 0xc;
      } while (uVar23 < uVar25);
    }
    DRstovnd(local_618,local_4a8);
  }
  else {
    ERclear(0);
  }
  FUN_180037ee0();
  FUN_180037ca0();
  FUN_1800386e0();
  FUN_1800383e0(1);
  *(undefined1 **)gevaldef_exref = local_618;
  if ((param_2 != 0) && ((local_638 != 0 || (iVar9 != 0)))) {
    FUN_180036a60(&DAT_180052fe0);
    GEgendel();
  }
  memset(local_618,0,0x128);
  local_608 = *(undefined8 *)(*(longlong *)topfinfo_exref + 0x168);
  local_610 = MDfndkey(*(undefined8 *)iwpfile_exref,local_608,1);
  if (*(longlong *)MDerror_exref == 0) {
    DRstovbg(local_618,local_4a8,0);
    *(undefined1 **)gevaldef_exref = local_618;
    if (*(longlong *)(local_540 + 0x90) == 0) {
      local_660 = 0;
    }
    else {
      local_660 = MDgetito(*(undefined8 *)iwpfile_exref,*(undefined8 *)(local_540 + 0x98));
    }
    local_648 = 0;
    local_650 = 1;
    *(ulonglong *)geunbead_exref = local_660;
    local_2f0[0] = s_CURRENCY_180043cb0[8];
    local_2f8[0] = s_CURRENCY_180043cb0[0];
    local_2f8[1] = s_CURRENCY_180043cb0[1];
    local_2f8[2] = s_CURRENCY_180043cb0[2];
    local_2f8[3] = s_CURRENCY_180043cb0[3];
    acStack_2f4[0] = s_CURRENCY_180043cb0[4];
    acStack_2f4[1] = s_CURRENCY_180043cb0[5];
    acStack_2f4[2] = s_CURRENCY_180043cb0[6];
    acStack_2f4[3] = s_CURRENCY_180043cb0[7];
    lVar12 = *(longlong *)gevaldef_exref;
    local_658 = local_2f8;
    local_668 = "CURRENCY";
    GEgenpar(*(undefined8 *)(lVar12 + 0xd8),*(undefined8 *)(lVar12 + 0x68),
             *(undefined8 *)(lVar12 + 0x78));
    DRstovnd(local_618);
  }
  else {
    ERclear(0);
  }
  memset(local_618,0,0x128);
  local_608 = *(longlong *)(analysis_ditem_exref + 8);
  local_610 = *(longlong *)analysis_ditem_exref;
  DRstovbg(local_618,local_4a8,0);
  *(undefined1 **)gevaldef_exref = local_618;
  if (*(longlong *)(local_540 + 0x90) != 0) {
    uVar18 = MDgetito(*(undefined8 *)iwpfile_exref,*(undefined8 *)(local_540 + 0x98));
  }
  lVar12 = -(longlong)param_4;
  *(undefined8 *)geunbead_exref = uVar18;
  local_2f0[0] = s_PROP_TABLE_180041240[8];
  local_2f0[1] = s_PROP_TABLE_180041240[9];
  local_2ee = s_PROP_TABLE_180041240[10];
  local_2f8[0] = s_PROP_TABLE_180041240[0];
  local_2f8[1] = s_PROP_TABLE_180041240[1];
  local_2f8[2] = s_PROP_TABLE_180041240[2];
  local_2f8[3] = s_PROP_TABLE_180041240[3];
  acStack_2f4[0] = s_PROP_TABLE_180041240[4];
  acStack_2f4[1] = s_PROP_TABLE_180041240[5];
  acStack_2f4[2] = s_PROP_TABLE_180041240[6];
  acStack_2f4[3] = s_PROP_TABLE_180041240[7];
  do {
    cVar3 = *param_4;
    param_4[(longlong)(local_2e9 + lVar12)] = cVar3;
    param_4 = param_4 + 1;
  } while (cVar3 != '\0');
  *(undefined4 *)called_from_analysis_exref = 1;
  lVar12 = MDrslcls(*(undefined8 *)iwpfile_exref,local_608);
  local_658 = local_2f8;
  uVar27 = 0;
  uVar19 = 0;
  local_668 = (char *)(lVar12 + local_610 * 0x108);
  local_648 = 0;
  pcVar26 = (char *)0x0;
  local_650 = 2;
  piVar22 = *(int **)(*(longlong *)gevaldef_exref + 0x78);
  local_660 = uVar18;
  GEgenpar(*(undefined8 *)(*(longlong *)gevaldef_exref + 0xd8));
  *(undefined4 *)called_from_analysis_exref = 0;
  if (iVar9 != 0) {
    memset(local_618,0,0x128);
    local_608 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"ADD-INPUT");
    piVar22 = (int *)0x1;
    pcVar26 = "ADD-AFTER";
    local_610 = MDfndkey(*(undefined8 *)iwpfile_exref,local_608);
    if (*(longlong *)MDerror_exref == 0) {
      DRstovbg(local_618,local_4a8,0);
      *(undefined1 **)gevaldef_exref = local_618;
      if (*(longlong *)(local_540 + 0x90) != 0) {
        uVar19 = MDgetito(*(undefined8 *)iwpfile_exref,*(undefined8 *)(local_540 + 0x98));
      }
      pcVar26 = (char *)0x0;
      local_648 = 0;
      local_650 = 1;
      *(undefined8 *)geunbead_exref = uVar19;
      local_2f0[0] = s_ADD_INPUT_180043cc0[8];
      local_2f0[1] = s_ADD_INPUT_180043cc0[9];
      local_2f8[0] = s_ADD_INPUT_180043cc0[0];
      local_2f8[1] = s_ADD_INPUT_180043cc0[1];
      local_2f8[2] = s_ADD_INPUT_180043cc0[2];
      local_2f8[3] = s_ADD_INPUT_180043cc0[3];
      acStack_2f4[0] = s_ADD_INPUT_180043cc0[4];
      acStack_2f4[1] = s_ADD_INPUT_180043cc0[5];
      acStack_2f4[2] = s_ADD_INPUT_180043cc0[6];
      acStack_2f4[3] = s_ADD_INPUT_180043cc0[7];
      lVar12 = *(longlong *)gevaldef_exref;
      local_658 = local_2f8;
      local_668 = "ADD-AFTER";
      piVar22 = *(int **)(lVar12 + 0x78);
      local_660 = uVar19;
      GEgenpar(*(undefined8 *)(lVar12 + 0xd8),*(undefined8 *)(lVar12 + 0x68));
    }
    else {
      ERclear(0);
    }
  }
  lVar12 = 6 - (ulonglong)(*(int *)(hunks_exref + **(longlong **)iwpfile_exref * 0x108 + 0xf4) != 0)
  ;
  do {
    GEwritefile(uVar11,&DAT_180043cdc);
    lVar12 = lVar12 + -1;
  } while (lVar12 != 0);
  GEwritefile(uVar11,&DAT_18004100c);
  GEclosefile(uVar11);
  if ((*(int *)(*(longlong *)topfinfo_exref + 0x15c) != 0) || (iVar10 = GRinqgpd(), iVar10 == 0)) {
    uVar27 = 1;
  }
  DAT_180052fd4 = 0;
  lVar12 = *(longlong *)topfinfo_exref;
  uVar4 = *(undefined4 *)(lVar12 + 0x15c);
  uVar5 = *(undefined4 *)(lVar12 + 0x708);
  uVar6 = *(undefined4 *)(lVar12 + 0x150);
  GRbumpsumcount();
  FUN_18000cb50((IMAGE_DOS_HEADER *)0x0,lVar12,piVar22,pcVar26);
  GRsetpgc(uVar27);
  *(undefined4 *)(*(longlong *)topfinfo_exref + 0x15c) = uVar4;
  GRsetnec(uVar5);
  GRsetcpt(uVar6);
  if (DAT_180052fd4 != 0) {
    *(undefined4 *)sbcanned_exref = 0;
    return 1;
  }
  hide_mouse();
  iVar10 = GRinqprp();
  if ((iVar10 == 4) && (iVar10 = GRinqerr(), iVar10 == 4)) {
    uVar11 = GetSorResStringEx();
    uVar18 = 0x7ad;
  }
  else {
    uVar11 = GetSorResStringEx(0x7ae);
    uVar18 = 0x7ac;
  }
  uVar18 = GetSorResStringEx(uVar18);
  FUN_180008f80(local_168,&DAT_18003f9b0,uVar18,uVar11);
  open_report_box(local_168);
  show_mouse();
  *(undefined4 *)sbcanned_exref = 0;
  GRsetprp(0);
  return 0;
}

/* RVA 0x39c00 */
ulonglong submit_proprun(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        )

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  longlong lVar5;
  bool bVar6;
  int iVar7;
  undefined7 extraout_var;
  longlong lVar8;
  undefined8 uVar9;
  
                    /* 0x39c00  93  submit_proprun */
  GRbumpsumcount();
  uVar9 = 1;
  *(undefined4 *)prop_retrieve_results_exref = 1;
  lVar8 = *(longlong *)topfinfo_exref;
  uVar1 = *(undefined4 *)(lVar8 + 0x380);
  if (*(int *)(lVar8 + 0x15c) == 0) {
    iVar7 = GRinqgpd();
    if (iVar7 != 0) {
      uVar9 = 0;
    }
  }
  lVar5 = *(longlong *)topfinfo_exref;
  uVar2 = *(undefined4 *)(lVar5 + 0x15c);
  uVar3 = *(undefined4 *)(lVar5 + 0x708);
  uVar4 = *(undefined4 *)(lVar5 + 0x150);
  *(undefined4 *)(lVar5 + 0x380) = 0x2d9;
  bVar6 = FUN_1800109c0(lVar8,lVar5,param_3,param_4);
  *(undefined4 *)(*(longlong *)topfinfo_exref + 0x380) = uVar1;
  GRsetpgc(uVar9);
  *(undefined4 *)(*(longlong *)topfinfo_exref + 0x15c) = uVar2;
  GRsetnec(uVar3);
  GRsetcpt(uVar4);
  return CONCAT71(extraout_var,bVar6) & 0xffffffff;
}

/* RVA 0x39ce0 */
void FUN_180039ce0(void)

{
  char cVar1;
  byte *pbVar2;
  int iVar3;
  char *_Str;
  undefined8 uVar4;
  byte *_Dest;
  char *pcVar5;
  longlong lVar6;
  
  _Str = (char *)GRinqigb();
  uVar4 = HYPshFinfo(1);
  _Dest = (byte *)MDcalloc(1);
  pcVar5 = strchr(_Str,0x2e);
  if (pcVar5 == (char *)0x0) {
    lVar6 = (longlong)_Dest - (longlong)_Str;
    do {
      cVar1 = *_Str;
      _Str[lVar6] = cVar1;
      _Str = _Str + 1;
    } while (cVar1 != '\0');
  }
  else {
    *(char **)(_Dest + 0x10) = pcVar5 + 1;
    strncpy((char *)_Dest,_Str,(longlong)pcVar5 - (longlong)_Str);
    _Dest[(longlong)pcVar5 - (longlong)_Str] = 0;
  }
  FUN_18002c100();
  iVar3 = GRinqgcp();
  FUN_18003a060(*(undefined8 *)dataclass_exref,0,(uint)(iVar3 != 1),_Dest);
  while (_Dest != (byte *)0x0) {
    pbVar2 = *(byte **)(_Dest + 0x18);
    MDfree(_Dest);
    _Dest = pbVar2;
  }
  HYPopFinfo(uVar4);
  return;
}

/* RVA 0x39dd0 */
undefined8 FUN_180039dd0(longlong param_1,byte *param_2)

{
  int iVar1;
  char *pcVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  
  if ((*param_2 & 0x1d) != 0) {
    iVar1 = *(int *)(param_2 + 0x2c);
    if (iVar1 == 0xd7) {
      return 2;
    }
    if (iVar1 == 0xf) {
      return 3;
    }
    if (iVar1 == 0x1e) {
      return 5;
    }
    if (*(int *)(param_1 + 0x38) == 2) {
      pcVar2 = (char *)MDgetcnm(*(undefined8 *)iwpfile_exref,*(undefined8 *)(param_1 + 0x48));
      iVar1 = strncmp(pcVar2,"BLOCK",5);
      if (iVar1 == 0) {
        return 4;
      }
    }
    if (*(int *)(param_1 + 0x38) != 2) {
      return 0;
    }
    lVar3 = MDgetcnm(*(undefined8 *)iwpfile_exref,*(undefined8 *)(param_1 + 0x48));
    lVar5 = 0;
    do {
      lVar4 = lVar5 + 1;
      if (*(char *)(lVar3 + lVar5) != "SETUP"[lVar5]) goto LAB_180039f19;
      lVar5 = lVar4;
    } while (lVar4 != 6);
    lVar3 = MDgethkp(*(undefined8 *)iwpfile_exref,*(undefined8 *)(param_1 + 0x10),
                     *(undefined8 *)(param_1 + 8));
    lVar5 = 0;
    do {
      lVar4 = lVar5 + 1;
      if (*(char *)(lVar3 + lVar5) != "GLOBAL"[lVar5]) {
LAB_180039f19:
        if (*(int *)(param_1 + 0x38) == 2) {
          lVar3 = MDgetcnm(*(undefined8 *)iwpfile_exref,*(undefined8 *)(param_1 + 0x48));
          lVar5 = 0;
          do {
            lVar4 = lVar5 + 1;
            if (*(char *)(lVar3 + lVar5) != "SETUP"[lVar5]) {
              return 0;
            }
            lVar5 = lVar4;
          } while (lVar4 != 6);
          pcVar2 = (char *)MDgetcnm(*(undefined8 *)iwpfile_exref,*(undefined8 *)(param_1 + 0x50));
          iVar1 = strcmp(pcVar2,"UNITS-SET");
          if (iVar1 == 0) {
            return 1;
          }
        }
        return 0;
      }
      lVar5 = lVar4;
    } while (lVar4 != 7);
  }
  return 1;
}

/* RVA 0x39f80 */
byte * FUN_180039f80(byte *param_1,char *param_2,int param_3)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  byte *pbVar4;
  byte *pbVar5;
  int iVar6;
  size_t _MaxCount;
  
joined_r0x000180039fa0:
  do {
    pbVar4 = param_1;
    if (pbVar4 == (byte *)0x0) {
      return (byte *)0x0;
    }
    param_1 = *(byte **)(pbVar4 + 0x18);
    if (param_3 == 0) {
      pbVar5 = pbVar4;
      do {
        pbVar1 = pbVar5 + ((longlong)param_2 - (longlong)pbVar4);
        iVar6 = (uint)*pbVar5 - (uint)*pbVar1;
        if (iVar6 != 0) break;
        pbVar5 = pbVar5 + 1;
      } while (*pbVar1 != 0);
    }
    else {
      if (param_3 != 1) goto joined_r0x000180039fa0;
      pbVar5 = pbVar4;
      do {
        bVar2 = *pbVar5;
        bVar3 = pbVar5[(longlong)param_2 - (longlong)pbVar4];
        if (bVar2 != bVar3) break;
        pbVar5 = pbVar5 + 1;
      } while (bVar3 != 0);
      if (bVar2 == bVar3) {
        return pbVar4;
      }
      if (*(char **)(pbVar4 + 0x10) == (char *)0x0) goto joined_r0x000180039fa0;
      _MaxCount = 0xffffffffffffffff;
      do {
        _MaxCount = _MaxCount + 1;
      } while (param_2[_MaxCount] != '\0');
      iVar6 = strncmp(*(char **)(pbVar4 + 0x10),param_2,_MaxCount);
    }
    if (iVar6 == 0) {
      return pbVar4;
    }
  } while( true );
}

/* RVA 0x3a060 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18003a060(undefined8 param_1,longlong param_2,int param_3,byte *param_4)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  longlong lVar8;
  longlong lVar9;
  byte *pbVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  char *_Dest;
  char *pcVar13;
  char *pcVar14;
  undefined1 auStack_368 [32];
  longlong *local_348;
  ulonglong local_340;
  uint local_338;
  longlong local_328;
  int local_320;
  int local_31c;
  int local_318;
  undefined8 local_310;
  longlong local_308;
  undefined1 local_2f8 [8];
  undefined4 local_2f0;
  undefined4 uStack_2ec;
  undefined4 uStack_2e8;
  undefined4 uStack_2e4;
  longlong local_220;
  longlong local_1c8;
  longlong local_1c0;
  longlong local_1b8 [6];
  undefined1 local_188 [8];
  undefined4 local_180;
  undefined4 uStack_17c;
  undefined4 uStack_178;
  undefined4 uStack_174;
  ulonglong local_58;
  
  local_58 = DAT_1800516d8 ^ (ulonglong)auStack_368;
  local_320 = 0;
  local_328 = param_2;
  local_318 = param_3;
  local_310 = param_1;
  iVar4 = strcmp((char *)param_4,"########");
  local_1b8[0] = 0;
  local_31c = iVar4;
  lVar8 = MDrslcls(*(undefined8 *)iwpfile_exref,param_1);
  iVar6 = 0;
joined_r0x00018003a0e8:
  do {
    while( true ) {
      do {
        iVar3 = iVar6;
        iVar7 = param_3;
        uVar11 = param_1;
        if (local_1b8[0] == -1) {
          return 1;
        }
        local_308 = lVar8;
        if (param_2 == 0) {
          local_348 = local_1b8;
          local_340 = 0;
          lVar9 = MDfndsls(*(undefined8 *)iwpfile_exref,uVar11,1);
          if (local_1b8[0] == -1) {
            return 1;
          }
        }
        else {
          local_1b8[0] = -1;
          lVar9 = param_2;
        }
        pcVar14 = (char *)(lVar8 + lVar9 * 0x108);
        param_1 = local_310;
        param_3 = local_318;
        lVar8 = local_308;
        iVar6 = local_320;
      } while ((*(uint *)(pcVar14 + 0x18) & 0xe00) == 0);
      if (pcVar14[0x107] == '\x03') break;
      param_1 = local_310;
      param_3 = local_318;
      if (pcVar14[0x107] == '\x06') {
        lVar8 = *(longlong *)(pcVar14 + 0x28);
        lVar9 = MDrslcls(*(undefined8 *)iwpfile_exref,lVar8);
        if (*(longlong *)(lVar9 + 0x148) != 0) {
          lVar8 = *(longlong *)(lVar9 + 0x148);
        }
        FUN_18003a060(lVar8,0,iVar7,param_4);
        param_1 = local_310;
        param_2 = local_328;
        param_3 = local_318;
        lVar8 = local_308;
        iVar6 = local_320;
      }
    }
    lVar9 = MDgetito(*(undefined8 *)iwpfile_exref,uVar11,lVar9);
    param_1 = local_310;
    param_2 = local_328;
    param_3 = local_318;
    lVar8 = local_308;
    iVar6 = local_320;
  } while ((*(longlong *)(lVar9 + 0x10) == 0) ||
          (param_1 = local_310, param_3 = local_318, *(longlong *)(lVar9 + 0x20) == 0));
  pbVar10 = (byte *)MDgetito(*(undefined8 *)recfile_exref);
  uVar11 = FUN_180039dd0(lVar9,pbVar10);
  iVar5 = (int)uVar11;
  param_2 = local_328;
  lVar8 = local_308;
  iVar6 = local_320;
  if (iVar5 == 1) goto LAB_18003a593;
  if (iVar5 != 2) {
    if (iVar5 != 3) {
      if (iVar5 == 4) {
        pbVar10 = FUN_180039f80(param_4,pcVar14,0);
        param_1 = local_310;
        param_2 = local_328;
        param_3 = local_318;
        lVar8 = local_308;
        iVar6 = local_320;
        if (pbVar10 != (byte *)0x0) {
          local_338 = ~(*(uint *)(pcVar14 + 0x18) >> 0xc) & 1;
          local_340 = CONCAT44(local_340._4_4_,9999);
          local_348 = (longlong *)CONCAT44(local_348._4_4_,9999);
          MDprpcmp(lVar9 + 0x40,*(undefined4 *)(lVar9 + 0x38),*(undefined8 *)(lVar9 + 0x80));
          param_1 = local_310;
          param_2 = local_328;
          param_3 = local_318;
          lVar8 = local_308;
          iVar6 = local_320;
        }
      }
      else {
        param_1 = local_310;
        param_3 = local_318;
        if ((iVar5 == 5) && (param_1 = local_310, param_3 = local_318, iVar7 == 0)) {
          local_180 = *(undefined4 *)(lVar9 + 8);
          uStack_17c = *(undefined4 *)(lVar9 + 0xc);
          uStack_178 = *(undefined4 *)(lVar9 + 0x10);
          uStack_174 = *(undefined4 *)(lVar9 + 0x14);
          *(undefined1 **)gevaldef_exref = local_188;
          iVar6 = GEpropse(2,0);
          if ((iVar6 != 2) ||
             ((iVar6 = GRinqgpd(), iVar6 != 0 &&
              (*(int *)(*(longlong *)topfinfo_exref + 0x1dc) != 0)))) goto LAB_18003a597;
          local_338 = 1;
          local_340 = CONCAT44(local_340._4_4_,9999);
          local_348 = (longlong *)CONCAT44(local_348._4_4_,9999);
          MDprpcmp(lVar9 + 0x40,*(undefined4 *)(lVar9 + 0x38),*(undefined8 *)(lVar9 + 0x80));
          *(uint *)(pcVar14 + 0x18) = *(uint *)(pcVar14 + 0x18) & 0xffffefff;
          param_1 = local_310;
          param_2 = local_328;
          param_3 = local_318;
          lVar8 = local_308;
          iVar6 = local_320;
        }
      }
      goto joined_r0x00018003a0e8;
    }
    uVar2 = *(uint *)(pcVar14 + 0x18);
    if (((uVar2 >> 0xc & 1) != 0 && (uVar2 & 0xf) != 0) &&
       (param_1 = local_310, param_3 = local_318, (uVar2 & 0xe00) == 0))
    goto joined_r0x00018003a0e8;
    if (iVar4 != 0) {
      if (iVar3 == 0) {
        uVar11 = *(undefined8 *)(*(longlong *)finfo_exref + 0x1b8);
        uVar12 = MDfndkey(*(undefined8 *)iwpfile_exref,uVar11,1,param_4);
        lVar8 = MDgethkp(*(undefined8 *)iwpfile_exref,uVar11,uVar12);
        uVar11 = *(undefined8 *)(lVar8 + 0x28);
        uVar12 = *(undefined8 *)(lVar8 + 0x30);
        local_1c0 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"FLOWSHEET"
                            );
        local_340 = local_340 & 0xffffffff00000000;
        local_348 = (longlong *)CONCAT44(local_348._4_4_,8);
        MDgetedd(*(undefined8 *)iwpfile_exref,uVar11,uVar12);
        local_320 = 1;
      }
      param_1 = local_310;
      param_2 = local_328;
      param_3 = local_318;
      lVar8 = local_308;
      iVar6 = local_320;
      if ((*(longlong *)(lVar9 + 8) != local_1c8) ||
         (param_1 = local_310, param_3 = local_318, *(longlong *)(lVar9 + 0x10) != local_1c0))
      goto joined_r0x00018003a0e8;
    }
    memset(local_2f8,0,0x128);
    local_2f0 = *(undefined4 *)(lVar9 + 8);
    uStack_2ec = *(undefined4 *)(lVar9 + 0xc);
    uStack_2e8 = *(undefined4 *)(lVar9 + 0x10);
    uStack_2e4 = *(undefined4 *)(lVar9 + 0x14);
    local_220 = lVar9;
    MDgetrdf(local_2f8);
    iVar7 = CheckFlowSecGen(local_2f8);
    param_1 = local_310;
    param_2 = local_328;
    param_3 = local_318;
    lVar8 = local_308;
    iVar6 = local_320;
    if (iVar7 == 0) {
      *(uint *)(pcVar14 + 0x18) = *(uint *)(pcVar14 + 0x18) & 0xffffefff;
      local_338 = 1;
      local_340 = CONCAT44(local_340._4_4_,9999);
      local_348 = (longlong *)CONCAT44(local_348._4_4_,9999);
      MDprpcmp(lVar9 + 0x40,*(undefined4 *)(lVar9 + 0x38),*(undefined8 *)(lVar9 + 0x80));
      param_1 = local_310;
      param_2 = local_328;
      param_3 = local_318;
      lVar8 = local_308;
      iVar6 = local_320;
    }
    goto joined_r0x00018003a0e8;
  }
  uVar11 = *(undefined8 *)(lVar9 + 0x10);
  uVar12 = *(undefined8 *)(lVar9 + 8);
  if (iVar4 == 0) {
    pbVar10 = param_4;
  }
  else {
    pbVar10 = FUN_180039f80(param_4,pcVar14,1);
    param_1 = local_310;
    param_2 = local_328;
    param_3 = local_318;
    lVar8 = local_308;
    iVar6 = local_320;
    if (pbVar10 == (byte *)0x0) goto joined_r0x00018003a0e8;
    pbVar10 = *(byte **)(pbVar10 + 0x10);
  }
  uVar11 = HYGetFinfoCls(uVar11,uVar12);
  uVar11 = HYPshFinfo(uVar11);
  _Dest = (char *)MDcalloc(1);
  pcVar13 = strchr((char *)pbVar10,0x2e);
  if (pcVar13 == (char *)0x0) {
    lVar8 = (longlong)_Dest - (longlong)pbVar10;
    do {
      bVar1 = *pbVar10;
      pbVar10[lVar8] = bVar1;
      pbVar10 = pbVar10 + 1;
    } while (bVar1 != 0);
  }
  else {
    *(char **)(_Dest + 0x10) = pcVar13 + 1;
    strncpy(_Dest,(char *)pbVar10,(longlong)pcVar13 - (longlong)pbVar10);
    _Dest[(longlong)pcVar13 - (longlong)pbVar10] = '\0';
  }
  local_338 = ~(*(uint *)(pcVar14 + 0x18) >> 0xc) & 1;
  local_340 = CONCAT44(local_340._4_4_,9999);
  local_348 = (longlong *)CONCAT44(local_348._4_4_,9999);
  MDprpcmp(lVar9 + 0x40,*(undefined4 *)(lVar9 + 0x38),*(undefined8 *)(lVar9 + 0x80));
  while (_Dest != (char *)0x0) {
    pcVar14 = *(char **)(_Dest + 0x18);
    MDfree(_Dest);
    _Dest = pcVar14;
  }
  HYPopFinfo(uVar11);
  param_1 = local_310;
  param_2 = local_328;
  param_3 = local_318;
  iVar4 = local_31c;
  lVar8 = local_308;
  iVar6 = local_320;
  goto joined_r0x00018003a0e8;
LAB_18003a593:
  param_1 = local_310;
  param_3 = local_318;
  if (iVar7 == 0) {
LAB_18003a597:
    local_338 = 0;
    local_340 = CONCAT44(local_340._4_4_,9999);
    local_348 = (longlong *)CONCAT44(local_348._4_4_,9999);
    MDprpcmp(lVar9 + 0x40,*(undefined4 *)(lVar9 + 0x38),*(undefined8 *)(lVar9 + 0x80));
    *(uint *)(pcVar14 + 0x18) = *(uint *)(pcVar14 + 0x18) | 0x1000;
    param_1 = local_310;
    param_2 = local_328;
    param_3 = local_318;
    lVar8 = local_308;
    iVar6 = local_320;
  }
  goto joined_r0x00018003a0e8;
}

