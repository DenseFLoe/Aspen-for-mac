/* RVA 0x87d0, PPEXEC_UPDRTN */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PPEXEC_UPDRTN(void)

{
                    /* 0x87d0  37  PPEXEC_UPDRTN */
  DAT_1800207d8 = *(longlong *)DMS_NCOMP_exref;
  DMS_LOCATM(&DAT_180020168,&DAT_1800207f0,&DAT_1800207e8,&DAT_1800207e0);
  _PPEXEC_IWNC = DAT_1800207f0 + -1;
  _PPEXEC_IRETEN = DAT_1800207d8 + -1 + DAT_1800207f0;
  _PPEXEC_WNC1 = DAT_1800207e8 + -1;
  _PPEXEC_WNC2 = DAT_1800207e8 + DAT_1800207d8 + -1;
  _PPEXEC_WNC3 = _PPEXEC_WNC2 + DAT_1800207d8;
  _PPEXEC_WNC4 = _PPEXEC_WNC3 + DAT_1800207d8;
  _PPEXEC_WNC5 = _PPEXEC_WNC4 + DAT_1800207d8;
  _PPEXEC_WNC6 = _PPEXEC_WNC5 + DAT_1800207d8;
  _PPEXEC_WNC7 = _PPEXEC_WNC6 + DAT_1800207d8;
  _PPEXEC_WNC8 = _PPEXEC_WNC7 + DAT_1800207d8;
  _PPEXEC_WNC9 = _PPEXEC_WNC8 + DAT_1800207d8;
  _PPEXEC_WNC10 = _PPEXEC_WNC9 + DAT_1800207d8;
  _PPEXEC_RETEN = _PPEXEC_WNC10 + DAT_1800207d8;
  return;
}

/* RVA 0x88b0, PPEXEC_ALLOCRTN */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PPEXEC_ALLOCRTN(longlong *param_1,longlong *param_2,undefined8 param_3,longlong *param_4,
                    longlong *param_5)

{
  longlong lVar1;
  code *pcVar2;
  
                    /* 0x88b0  2  PPEXEC_ALLOCRTN */
  pcVar2 = DMS_NCOMP_exref;
  _DAT_180020818 = *param_2 + 6 + *(longlong *)DMS_NCOMP_exref;
  _DAT_180020810 = *param_1 + *(longlong *)DMS_NCOMP_exref * 0x10 + 0x1f;
  DMS_ALLOCM(&DAT_180020818,&DAT_180020810,param_3,&DAT_180020808,&DAT_180020800,&DAT_1800207f8);
  _PPEXEC_IWNC = DAT_180020808 + -1;
  lVar1 = *(longlong *)pcVar2;
  *param_5 = lVar1 + -1 + DAT_180020808;
  _PPEXEC_WNC1 = DAT_180020800 + -1;
  _PPEXEC_WNC2 = DAT_180020800 + lVar1 + -1;
  _PPEXEC_WNC3 = _PPEXEC_WNC2 + lVar1;
  _PPEXEC_WNC4 = _PPEXEC_WNC3 + lVar1;
  _PPEXEC_WNC5 = _PPEXEC_WNC4 + lVar1;
  _PPEXEC_WNC6 = _PPEXEC_WNC5 + lVar1;
  _PPEXEC_WNC7 = _PPEXEC_WNC6 + lVar1;
  _PPEXEC_WNC8 = _PPEXEC_WNC7 + lVar1;
  _PPEXEC_WNC9 = _PPEXEC_WNC8 + lVar1;
  _PPEXEC_WNC10 = _PPEXEC_WNC9 + lVar1;
  *param_4 = _PPEXEC_WNC10 + lVar1;
  return;
}

/* RVA 0x89c0, PPEXEC_APINIT */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PPEXEC_APINIT(undefined8 *param_1,undefined8 *param_2,undefined8 param_3,undefined8 *param_4,
                  undefined8 param_5,ulonglong *param_6)

{
  ulonglong uVar1;
  code *pcVar2;
  uint uVar3;
  longlong lVar4;
  undefined8 uVar5;
  longlong lVar6;
  code *pcVar7;
  ulonglong local_40;
  
                    /* 0x89c0  5  PPEXEC_APINIT */
  *(undefined8 *)DMS_ICRD_exref = 1;
  pcVar7 = DMS_PPERR1_exref;
  *(undefined8 *)DMS_PPERR1_exref = 0x1e;
  *(undefined8 *)(pcVar7 + 8) = 1;
  *(undefined8 *)(pcVar7 + 0x710) = 0x32;
  *(undefined8 *)(pcVar7 + 0x718) = 1;
  pcVar7 = DMS_PPERR2_exref;
  *(undefined8 *)DMS_PPERR2_exref = 0x28;
  *(undefined8 *)(pcVar7 + 8) = 1;
  *(undefined8 *)(DMS_GLOBAL_exref + 0x158) = 0;
  pcVar7 = DMS_FNAMES_exref;
  FUN_180008d20();
  pcVar7[0x18ff] = (code)0x20;
  FUN_180008d20();
  DMS_STRUPR(&DAT_180020900,0xff);
  lVar4 = DMS_CSTRLEN(&DAT_180020900,0xff);
  uVar3 = for_cpstr(lVar4 + 0x1800208f9,7,".APRPDF",7,2);
  DAT_180020830 = (ulonglong)(uVar3 & 1) + 1;
  DMS_SET_PRODUCTCODE(&DAT_180020830);
  _DAT_1800208f0 = _DAT_1800176f0;
  uRam00000001800208f4 = _UNK_1800176f4;
  uRam00000001800208f8 = _UNK_1800176f8;
  uRam00000001800208fc = _UNK_1800176fc;
  _DAT_1800208e0 = _DAT_1800176f0;
  uRam00000001800208e4 = _UNK_1800176f4;
  uRam00000001800208e8 = _UNK_1800176f8;
  uRam00000001800208ec = _UNK_1800176fc;
  _DAT_1800208d0 = _DAT_1800176f0;
  uRam00000001800208d4 = _UNK_1800176f4;
  uRam00000001800208d8 = _UNK_1800176f8;
  uRam00000001800208dc = _UNK_1800176fc;
  _DAT_1800208c0 = _DAT_1800176f0;
  uRam00000001800208c4 = _UNK_1800176f4;
  uRam00000001800208c8 = _UNK_1800176f8;
  uRam00000001800208cc = _UNK_1800176fc;
  _DAT_1800208b0 = _DAT_1800176f0;
  uRam00000001800208b4 = _UNK_1800176f4;
  uRam00000001800208b8 = _UNK_1800176f8;
  uRam00000001800208bc = _UNK_1800176fc;
  _DAT_1800208a0 = _DAT_1800176f0;
  uRam00000001800208a4 = _UNK_1800176f4;
  uRam00000001800208a8 = _UNK_1800176f8;
  uRam00000001800208ac = _UNK_1800176fc;
  _DAT_180020890 = _DAT_1800176f0;
  uRam0000000180020894 = _UNK_1800176f4;
  uRam0000000180020898 = _UNK_1800176f8;
  uRam000000018002089c = _UNK_1800176fc;
  _DAT_180020880 = _DAT_1800176f0;
  uRam0000000180020884 = _UNK_1800176f4;
  uRam0000000180020888 = _UNK_1800176f8;
  uRam000000018002088c = _UNK_1800176fc;
  _DAT_180020870 = _DAT_1800176f0;
  uRam0000000180020874 = _UNK_1800176f4;
  uRam0000000180020878 = _UNK_1800176f8;
  uRam000000018002087c = _UNK_1800176fc;
  _DAT_180020860 = _DAT_1800176f0;
  uRam0000000180020864 = _UNK_1800176f4;
  uRam0000000180020868 = _UNK_1800176f8;
  uRam000000018002086c = _UNK_1800176fc;
  uVar1 = *param_6;
  _DAT_180020838 = (ulonglong)((uint)(uVar1 >> 0x3e) & 0xfffffffe);
  local_40 = -uVar1;
  if ((longlong)-uVar1 < 0) {
    local_40 = uVar1;
  }
  DMS_ASPENC(&local_40,&DAT_180020838,&DAT_180020860);
  DAT_180020820 = 0;
  PPEXEC_INTPP(param_1,param_2,param_4,param_5,param_6,&DAT_180020820);
  if (DAT_180020820 == 0) {
    uVar5 = DMS_CREATE_BUFFER_LIST(&DAT_180017c50);
    pcVar2 = DMS_SUMRPB_exref;
    *(undefined8 *)(DMS_SUMRPB_exref + 0x18) = uVar5;
    pcVar7 = pcVar2 + 0x18;
    DMS_SET_BUFFER_NAME(pcVar7,&DAT_180017c40,"DEFAULT.APRPDF",7);
    DMS_SET_BUFFER_NAME(pcVar7,&DAT_180017c48,"HEADERDEFAULT.APRPDF",6);
    uVar5 = DMS_SET_CURRENT_BUFFER(pcVar7,"DEFAULT.APRPDF",7);
    *(undefined8 *)(pcVar2 + 0x20) = uVar5;
    DMS_SET_BUFFER_AS_HEADER_BY_INDEX(pcVar7,&DAT_180017c48,&DAT_180017c48);
    PPEXEC_APLOAD();
    PPEXEC_LDSTW();
    lVar4 = DMS_LOCATI(&DAT_180017c50);
    pcVar7 = DMS_PLEX_exref;
    _DAT_180020840 = *(undefined8 *)(DMS_PLEX_exref + lVar4 * 8 + 0x328);
    lVar4 = DMS_LOCATI();
    pcVar2 = PPUTL_OPSET_exref;
    lVar6 = 0;
    do {
      *(undefined8 *)(pcVar2 + lVar6 * 8) = *(undefined8 *)(pcVar7 + lVar6 * 8 + lVar4 * 8 + -8);
      lVar6 = lVar6 + 1;
    } while (lVar6 != 6);
    if (DAT_180020830 == 1) {
      _DAT_180020828 = 0;
      DMS_GETFNC(&DAT_18001e7a0,s_PML__INIT__PPL_US_18001e760,&DAT_180020828);
      pcVar7 = DMS_INITV_exref + 8;
      DMS_DOCALL_10(&DAT_180020828,pcVar7,pcVar7,pcVar7,pcVar7,pcVar7,pcVar7,pcVar7,pcVar7,pcVar7,
                    pcVar7);
    }
  }
  return;
}

/* RVA 0x8d00, FUN_180008d00 */
undefined * FUN_180008d00(void)

{
  return FUN_180008ea0;
}

/* RVA 0x8d10, FUN_180008d10 */
undefined * FUN_180008d10(void)

{
  return FUN_18000a6c0;
}

/* RVA 0x8d20, FUN_180008d20 */
void FUN_180008d20(void)

{
  ulonglong in_R9;
  undefined4 in_XMM0_Da;
  undefined4 in_XMM1_Da;
  undefined4 in_XMM2_Da;
  
  if (DAT_180020a90 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000180008d30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*DAT_180020a90)();
    return;
  }
  while (DAT_180020ab0 == 0) {
    in_XMM0_Da = FUN_18000d180(in_XMM0_Da,in_XMM1_Da,in_XMM2_Da,in_R9);
  }
  if ((~DAT_180020ab0 & 0x7189d9fee) == 0) {
    DAT_180020a90 = (code *)FUN_180008d10();
  }
  else if ((~(uint)DAT_180020ab0 & 0x9d9fee) == 0) {
    DAT_180020a90 = (code *)FUN_180008d00();
  }
  else {
    DAT_180020a90 = (code *)&LAB_18001479a;
    if ((~(uint)DAT_180020ab0 & 0x6e) == 0) {
      DAT_180020a90 = (code *)&LAB_180012c70;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x000180008dcb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_180020a90)();
  return;
}

/* RVA 0x8d40, FUN_180008d40 */
void FUN_180008d40(undefined4 param_1,undefined4 param_2,undefined4 param_3,ulonglong param_4)

{
  while (DAT_180020ab0 == 0) {
    param_1 = FUN_18000d180(param_1,param_2,param_3,param_4);
  }
  if ((~DAT_180020ab0 & 0x7189d9fee) == 0) {
    DAT_180020a90 = (code *)FUN_180008d10();
  }
  else if ((~(uint)DAT_180020ab0 & 0x9d9fee) == 0) {
    DAT_180020a90 = (code *)FUN_180008d00();
  }
  else {
    DAT_180020a90 = (code *)&LAB_18001479a;
    if ((~(uint)DAT_180020ab0 & 0x6e) == 0) {
      DAT_180020a90 = (code *)&LAB_180012c70;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x000180008dcb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_180020a90)();
  return;
}

/* RVA 0x8dd0, FUN_180008dd0 */
undefined * FUN_180008dd0(void)

{
  return FUN_18000e040;
}

/* RVA 0x8de0, FUN_180008de0 */
undefined1 * FUN_180008de0(void)

{
  return &LAB_18000f100;
}

/* RVA 0x8df0, FUN_180008df0 */
void FUN_180008df0(void)

{
  ulonglong in_R9;
  undefined4 in_XMM0_Da;
  undefined4 in_XMM1_Da;
  undefined4 in_XMM2_Da;
  
  if (DAT_180020a98 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000180008e00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*DAT_180020a98)();
    return;
  }
  while (DAT_180020ab0 == 0) {
    in_XMM0_Da = FUN_18000d180(in_XMM0_Da,in_XMM1_Da,in_XMM2_Da,in_R9);
  }
  if ((~DAT_180020ab0 & 0x7189d9fee) == 0) {
    DAT_180020a98 = (code *)FUN_180008de0();
  }
  else if ((~(uint)DAT_180020ab0 & 0x9d9fee) == 0) {
    DAT_180020a98 = (code *)FUN_180008dd0();
  }
  else {
    DAT_180020a98 = memset;
    if ((~(uint)DAT_180020ab0 & 0x6e) == 0) {
      DAT_180020a98 = (code *)&LAB_180013d20;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x000180008e98. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_180020a98)();
  return;
}

/* RVA 0x8e10, FUN_180008e10 */
void FUN_180008e10(undefined4 param_1,undefined4 param_2,undefined4 param_3,ulonglong param_4)

{
  while (DAT_180020ab0 == 0) {
    param_1 = FUN_18000d180(param_1,param_2,param_3,param_4);
  }
  if ((~DAT_180020ab0 & 0x7189d9fee) == 0) {
    DAT_180020a98 = (code *)FUN_180008de0();
  }
  else if ((~(uint)DAT_180020ab0 & 0x9d9fee) == 0) {
    DAT_180020a98 = (code *)FUN_180008dd0();
  }
  else {
    DAT_180020a98 = memset;
    if ((~(uint)DAT_180020ab0 & 0x6e) == 0) {
      DAT_180020a98 = (code *)&LAB_180013d20;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x000180008e98. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_180020a98)();
  return;
}

/* RVA 0x8ea0, FUN_180008ea0 */
undefined1 (*) [32]
FUN_180008ea0(undefined1 (*param_1) [32],undefined1 (*param_2) [32],ulonglong param_3)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined1 auVar3 [32];
  undefined1 auVar4 [32];
  undefined1 auVar5 [32];
  undefined1 auVar6 [32];
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  undefined8 uVar21;
  undefined1 (*pauVar22) [32];
  ulonglong uVar23;
  longlong lVar24;
  longlong lVar25;
  
  switch(param_3) {
  case 0:
    break;
  case 1:
    (*param_1)[0] = (*param_2)[0];
    break;
  case 2:
    *(undefined2 *)*param_1 = *(undefined2 *)*param_2;
    break;
  case 3:
    *(undefined2 *)*param_1 = *(undefined2 *)*param_2;
    (*param_1)[2] = (*param_2)[2];
    break;
  case 4:
    *(undefined4 *)*param_1 = *(undefined4 *)*param_2;
    break;
  case 5:
  case 6:
  case 7:
    *(undefined4 *)*param_1 = *(undefined4 *)*param_2;
    *(undefined4 *)(param_1[-1] + param_3 + 0x1c) = *(undefined4 *)(param_2[-1] + param_3 + 0x1c);
    break;
  case 8:
    *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
    break;
  case 9:
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
    *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
    *(undefined8 *)(param_1[-1] + param_3 + 0x18) = *(undefined8 *)(param_2[-1] + param_3 + 0x18);
    break;
  case 0x10:
    uVar7 = *(undefined8 *)(*param_2 + 8);
    *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
    *(undefined8 *)(*param_1 + 8) = uVar7;
    break;
  case 0x11:
  case 0x12:
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
  case 0x1e:
  case 0x1f:
    uVar7 = *(undefined8 *)(*param_2 + 8);
    *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
    *(undefined8 *)(*param_1 + 8) = uVar7;
    uVar7 = *(undefined8 *)((longlong)(param_2[-1] + param_3 + 0x10) + 8);
    *(undefined8 *)(param_1[-1] + param_3 + 0x10) = *(undefined8 *)(param_2[-1] + param_3 + 0x10);
    *(undefined8 *)((longlong)(param_1[-1] + param_3 + 0x10) + 8) = uVar7;
    break;
  case 0x21:
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x2c:
  case 0x2d:
  case 0x2e:
  case 0x2f:
  case 0x30:
  case 0x31:
  case 0x32:
  case 0x33:
  case 0x34:
  case 0x35:
  case 0x36:
  case 0x37:
  case 0x38:
  case 0x39:
  case 0x3a:
  case 0x3b:
  case 0x3c:
  case 0x3d:
  case 0x3e:
  case 0x3f:
    uVar7 = *(undefined8 *)(*param_2 + 8);
    uVar8 = *(undefined8 *)(*param_2 + 0x10);
    uVar9 = *(undefined8 *)(*param_2 + 0x18);
    *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
    *(undefined8 *)(*param_1 + 8) = uVar7;
    *(undefined8 *)(*param_1 + 0x10) = uVar8;
    *(undefined8 *)(*param_1 + 0x18) = uVar9;
    puVar1 = (undefined8 *)(param_2[-1] + param_3);
    uVar7 = puVar1[1];
    uVar8 = puVar1[2];
    uVar9 = puVar1[3];
    puVar2 = (undefined8 *)(param_1[-1] + param_3);
    *puVar2 = *puVar1;
    puVar2[1] = uVar7;
    puVar2[2] = uVar8;
    puVar2[3] = uVar9;
    break;
  case 0x41:
  case 0x42:
  case 0x43:
  case 0x44:
  case 0x45:
  case 0x46:
  case 0x47:
  case 0x48:
  case 0x49:
  case 0x4a:
  case 0x4b:
  case 0x4c:
  case 0x4d:
  case 0x4e:
  case 0x4f:
  case 0x50:
  case 0x51:
  case 0x52:
  case 0x53:
  case 0x54:
  case 0x55:
  case 0x56:
  case 0x57:
  case 0x58:
  case 0x59:
  case 0x5a:
  case 0x5b:
  case 0x5c:
  case 0x5d:
  case 0x5e:
  case 0x5f:
    uVar7 = *(undefined8 *)(*param_2 + 8);
    uVar8 = *(undefined8 *)(*param_2 + 0x10);
    uVar9 = *(undefined8 *)(*param_2 + 0x18);
    *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
    *(undefined8 *)(*param_1 + 8) = uVar7;
    *(undefined8 *)(*param_1 + 0x10) = uVar8;
    *(undefined8 *)(*param_1 + 0x18) = uVar9;
    uVar7 = *(undefined8 *)(param_2[1] + 8);
    uVar8 = *(undefined8 *)(param_2[1] + 0x10);
    uVar9 = *(undefined8 *)(param_2[1] + 0x18);
    *(undefined8 *)param_1[1] = *(undefined8 *)param_2[1];
    *(undefined8 *)(param_1[1] + 8) = uVar7;
    *(undefined8 *)(param_1[1] + 0x10) = uVar8;
    *(undefined8 *)(param_1[1] + 0x18) = uVar9;
    puVar1 = (undefined8 *)(param_2[-1] + param_3);
    uVar7 = puVar1[1];
    uVar8 = puVar1[2];
    uVar9 = puVar1[3];
    puVar2 = (undefined8 *)(param_1[-1] + param_3);
    *puVar2 = *puVar1;
    puVar2[1] = uVar7;
    puVar2[2] = uVar8;
    puVar2[3] = uVar9;
    break;
  case 0x61:
  case 0x62:
  case 99:
  case 100:
  case 0x65:
  case 0x66:
  case 0x67:
  case 0x68:
  case 0x69:
  case 0x6a:
  case 0x6b:
  case 0x6c:
  case 0x6d:
  case 0x6e:
  case 0x6f:
  case 0x70:
  case 0x71:
  case 0x72:
  case 0x73:
  case 0x74:
  case 0x75:
  case 0x76:
  case 0x77:
  case 0x78:
  case 0x79:
  case 0x7a:
  case 0x7b:
  case 0x7c:
  case 0x7d:
  case 0x7e:
  case 0x7f:
    uVar7 = *(undefined8 *)(*param_2 + 8);
    uVar8 = *(undefined8 *)(*param_2 + 0x10);
    uVar9 = *(undefined8 *)(*param_2 + 0x18);
    *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
    *(undefined8 *)(*param_1 + 8) = uVar7;
    *(undefined8 *)(*param_1 + 0x10) = uVar8;
    *(undefined8 *)(*param_1 + 0x18) = uVar9;
    uVar7 = *(undefined8 *)(param_2[1] + 8);
    uVar8 = *(undefined8 *)(param_2[1] + 0x10);
    uVar9 = *(undefined8 *)(param_2[1] + 0x18);
    *(undefined8 *)param_1[1] = *(undefined8 *)param_2[1];
    *(undefined8 *)(param_1[1] + 8) = uVar7;
    *(undefined8 *)(param_1[1] + 0x10) = uVar8;
    *(undefined8 *)(param_1[1] + 0x18) = uVar9;
    uVar7 = *(undefined8 *)(param_2[2] + 8);
    uVar8 = *(undefined8 *)(param_2[2] + 0x10);
    uVar9 = *(undefined8 *)(param_2[2] + 0x18);
    *(undefined8 *)param_1[2] = *(undefined8 *)param_2[2];
    *(undefined8 *)(param_1[2] + 8) = uVar7;
    *(undefined8 *)(param_1[2] + 0x10) = uVar8;
    *(undefined8 *)(param_1[2] + 0x18) = uVar9;
    puVar1 = (undefined8 *)(param_2[-1] + param_3);
    uVar7 = puVar1[1];
    uVar8 = puVar1[2];
    uVar9 = puVar1[3];
    puVar2 = (undefined8 *)(param_1[-1] + param_3);
    *puVar2 = *puVar1;
    puVar2[1] = uVar7;
    puVar2[2] = uVar8;
    puVar2[3] = uVar9;
    break;
  case 0x81:
  case 0x82:
  case 0x83:
  case 0x84:
  case 0x85:
  case 0x86:
  case 0x87:
  case 0x88:
  case 0x89:
  case 0x8a:
  case 0x8b:
  case 0x8c:
  case 0x8d:
  case 0x8e:
  case 0x8f:
  case 0x90:
  case 0x91:
  case 0x92:
  case 0x93:
  case 0x94:
  case 0x95:
  case 0x96:
  case 0x97:
  case 0x98:
  case 0x99:
  case 0x9a:
  case 0x9b:
  case 0x9c:
  case 0x9d:
  case 0x9e:
  case 0x9f:
    uVar7 = *(undefined8 *)(*param_2 + 8);
    uVar8 = *(undefined8 *)(*param_2 + 0x10);
    uVar9 = *(undefined8 *)(*param_2 + 0x18);
    *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
    *(undefined8 *)(*param_1 + 8) = uVar7;
    *(undefined8 *)(*param_1 + 0x10) = uVar8;
    *(undefined8 *)(*param_1 + 0x18) = uVar9;
    uVar7 = *(undefined8 *)(param_2[1] + 8);
    uVar8 = *(undefined8 *)(param_2[1] + 0x10);
    uVar9 = *(undefined8 *)(param_2[1] + 0x18);
    *(undefined8 *)param_1[1] = *(undefined8 *)param_2[1];
    *(undefined8 *)(param_1[1] + 8) = uVar7;
    *(undefined8 *)(param_1[1] + 0x10) = uVar8;
    *(undefined8 *)(param_1[1] + 0x18) = uVar9;
    uVar7 = *(undefined8 *)(param_2[2] + 8);
    uVar8 = *(undefined8 *)(param_2[2] + 0x10);
    uVar9 = *(undefined8 *)(param_2[2] + 0x18);
    *(undefined8 *)param_1[2] = *(undefined8 *)param_2[2];
    *(undefined8 *)(param_1[2] + 8) = uVar7;
    *(undefined8 *)(param_1[2] + 0x10) = uVar8;
    *(undefined8 *)(param_1[2] + 0x18) = uVar9;
    uVar7 = *(undefined8 *)(param_2[3] + 8);
    uVar8 = *(undefined8 *)(param_2[3] + 0x10);
    uVar9 = *(undefined8 *)(param_2[3] + 0x18);
    *(undefined8 *)param_1[3] = *(undefined8 *)param_2[3];
    *(undefined8 *)(param_1[3] + 8) = uVar7;
    *(undefined8 *)(param_1[3] + 0x10) = uVar8;
    *(undefined8 *)(param_1[3] + 0x18) = uVar9;
    puVar1 = (undefined8 *)(param_2[-1] + param_3);
    uVar7 = puVar1[1];
    uVar8 = puVar1[2];
    uVar9 = puVar1[3];
    puVar2 = (undefined8 *)(param_1[-1] + param_3);
    *puVar2 = *puVar1;
    puVar2[1] = uVar7;
    puVar2[2] = uVar8;
    puVar2[3] = uVar9;
    break;
  case 0xa1:
  case 0xa2:
  case 0xa3:
  case 0xa4:
  case 0xa5:
  case 0xa6:
  case 0xa7:
  case 0xa8:
  case 0xa9:
  case 0xaa:
  case 0xab:
  case 0xac:
  case 0xad:
  case 0xae:
  case 0xaf:
  case 0xb0:
  case 0xb1:
  case 0xb2:
  case 0xb3:
  case 0xb4:
  case 0xb5:
  case 0xb6:
  case 0xb7:
  case 0xb8:
  case 0xb9:
  case 0xba:
  case 0xbb:
  case 0xbc:
  case 0xbd:
  case 0xbe:
  case 0xbf:
    uVar7 = *(undefined8 *)(*param_2 + 8);
    uVar8 = *(undefined8 *)(*param_2 + 0x10);
    uVar9 = *(undefined8 *)(*param_2 + 0x18);
    *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
    *(undefined8 *)(*param_1 + 8) = uVar7;
    *(undefined8 *)(*param_1 + 0x10) = uVar8;
    *(undefined8 *)(*param_1 + 0x18) = uVar9;
    uVar7 = *(undefined8 *)(param_2[1] + 8);
    uVar8 = *(undefined8 *)(param_2[1] + 0x10);
    uVar9 = *(undefined8 *)(param_2[1] + 0x18);
    *(undefined8 *)param_1[1] = *(undefined8 *)param_2[1];
    *(undefined8 *)(param_1[1] + 8) = uVar7;
    *(undefined8 *)(param_1[1] + 0x10) = uVar8;
    *(undefined8 *)(param_1[1] + 0x18) = uVar9;
    uVar7 = *(undefined8 *)(param_2[2] + 8);
    uVar8 = *(undefined8 *)(param_2[2] + 0x10);
    uVar9 = *(undefined8 *)(param_2[2] + 0x18);
    *(undefined8 *)param_1[2] = *(undefined8 *)param_2[2];
    *(undefined8 *)(param_1[2] + 8) = uVar7;
    *(undefined8 *)(param_1[2] + 0x10) = uVar8;
    *(undefined8 *)(param_1[2] + 0x18) = uVar9;
    uVar7 = *(undefined8 *)(param_2[3] + 8);
    uVar8 = *(undefined8 *)(param_2[3] + 0x10);
    uVar9 = *(undefined8 *)(param_2[3] + 0x18);
    *(undefined8 *)param_1[3] = *(undefined8 *)param_2[3];
    *(undefined8 *)(param_1[3] + 8) = uVar7;
    *(undefined8 *)(param_1[3] + 0x10) = uVar8;
    *(undefined8 *)(param_1[3] + 0x18) = uVar9;
    uVar7 = *(undefined8 *)(param_2[4] + 8);
    uVar8 = *(undefined8 *)(param_2[4] + 0x10);
    uVar9 = *(undefined8 *)(param_2[4] + 0x18);
    *(undefined8 *)param_1[4] = *(undefined8 *)param_2[4];
    *(undefined8 *)(param_1[4] + 8) = uVar7;
    *(undefined8 *)(param_1[4] + 0x10) = uVar8;
    *(undefined8 *)(param_1[4] + 0x18) = uVar9;
    puVar1 = (undefined8 *)(param_2[-1] + param_3);
    uVar7 = puVar1[1];
    uVar8 = puVar1[2];
    uVar9 = puVar1[3];
    puVar2 = (undefined8 *)(param_1[-1] + param_3);
    *puVar2 = *puVar1;
    puVar2[1] = uVar7;
    puVar2[2] = uVar8;
    puVar2[3] = uVar9;
    break;
  case 0xc1:
  case 0xc2:
  case 0xc3:
  case 0xc4:
  case 0xc5:
  case 0xc6:
  case 199:
  case 200:
  case 0xc9:
  case 0xca:
  case 0xcb:
  case 0xcc:
  case 0xcd:
  case 0xce:
  case 0xcf:
  case 0xd0:
  case 0xd1:
  case 0xd2:
  case 0xd3:
  case 0xd4:
  case 0xd5:
  case 0xd6:
  case 0xd7:
  case 0xd8:
  case 0xd9:
  case 0xda:
  case 0xdb:
  case 0xdc:
  case 0xdd:
  case 0xde:
  case 0xdf:
    uVar7 = *(undefined8 *)(*param_2 + 8);
    uVar8 = *(undefined8 *)(*param_2 + 0x10);
    uVar9 = *(undefined8 *)(*param_2 + 0x18);
    *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
    *(undefined8 *)(*param_1 + 8) = uVar7;
    *(undefined8 *)(*param_1 + 0x10) = uVar8;
    *(undefined8 *)(*param_1 + 0x18) = uVar9;
    uVar7 = *(undefined8 *)(param_2[1] + 8);
    uVar8 = *(undefined8 *)(param_2[1] + 0x10);
    uVar9 = *(undefined8 *)(param_2[1] + 0x18);
    *(undefined8 *)param_1[1] = *(undefined8 *)param_2[1];
    *(undefined8 *)(param_1[1] + 8) = uVar7;
    *(undefined8 *)(param_1[1] + 0x10) = uVar8;
    *(undefined8 *)(param_1[1] + 0x18) = uVar9;
    uVar7 = *(undefined8 *)(param_2[2] + 8);
    uVar8 = *(undefined8 *)(param_2[2] + 0x10);
    uVar9 = *(undefined8 *)(param_2[2] + 0x18);
    *(undefined8 *)param_1[2] = *(undefined8 *)param_2[2];
    *(undefined8 *)(param_1[2] + 8) = uVar7;
    *(undefined8 *)(param_1[2] + 0x10) = uVar8;
    *(undefined8 *)(param_1[2] + 0x18) = uVar9;
    uVar7 = *(undefined8 *)(param_2[3] + 8);
    uVar8 = *(undefined8 *)(param_2[3] + 0x10);
    uVar9 = *(undefined8 *)(param_2[3] + 0x18);
    *(undefined8 *)param_1[3] = *(undefined8 *)param_2[3];
    *(undefined8 *)(param_1[3] + 8) = uVar7;
    *(undefined8 *)(param_1[3] + 0x10) = uVar8;
    *(undefined8 *)(param_1[3] + 0x18) = uVar9;
    uVar7 = *(undefined8 *)(param_2[4] + 8);
    uVar8 = *(undefined8 *)(param_2[4] + 0x10);
    uVar9 = *(undefined8 *)(param_2[4] + 0x18);
    *(undefined8 *)param_1[4] = *(undefined8 *)param_2[4];
    *(undefined8 *)(param_1[4] + 8) = uVar7;
    *(undefined8 *)(param_1[4] + 0x10) = uVar8;
    *(undefined8 *)(param_1[4] + 0x18) = uVar9;
    uVar7 = *(undefined8 *)(param_2[5] + 8);
    uVar8 = *(undefined8 *)(param_2[5] + 0x10);
    uVar9 = *(undefined8 *)(param_2[5] + 0x18);
    *(undefined8 *)param_1[5] = *(undefined8 *)param_2[5];
    *(undefined8 *)(param_1[5] + 8) = uVar7;
    *(undefined8 *)(param_1[5] + 0x10) = uVar8;
    *(undefined8 *)(param_1[5] + 0x18) = uVar9;
    puVar1 = (undefined8 *)(param_2[-1] + param_3);
    uVar7 = puVar1[1];
    uVar8 = puVar1[2];
    uVar9 = puVar1[3];
    puVar2 = (undefined8 *)(param_1[-1] + param_3);
    *puVar2 = *puVar1;
    puVar2[1] = uVar7;
    puVar2[2] = uVar8;
    puVar2[3] = uVar9;
    break;
  case 0xe1:
  case 0xe2:
  case 0xe3:
  case 0xe4:
  case 0xe5:
  case 0xe6:
  case 0xe7:
  case 0xe8:
  case 0xe9:
  case 0xea:
  case 0xeb:
  case 0xec:
  case 0xed:
  case 0xee:
  case 0xef:
  case 0xf0:
  case 0xf1:
  case 0xf2:
  case 0xf3:
  case 0xf4:
  case 0xf5:
  case 0xf6:
  case 0xf7:
  case 0xf8:
  case 0xf9:
  case 0xfa:
  case 0xfb:
  case 0xfc:
  case 0xfd:
  case 0xfe:
  case 0xff:
    uVar7 = *(undefined8 *)(*param_2 + 8);
    uVar8 = *(undefined8 *)(*param_2 + 0x10);
    uVar9 = *(undefined8 *)(*param_2 + 0x18);
    *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
    *(undefined8 *)(*param_1 + 8) = uVar7;
    *(undefined8 *)(*param_1 + 0x10) = uVar8;
    *(undefined8 *)(*param_1 + 0x18) = uVar9;
    uVar7 = *(undefined8 *)(param_2[1] + 8);
    uVar8 = *(undefined8 *)(param_2[1] + 0x10);
    uVar9 = *(undefined8 *)(param_2[1] + 0x18);
    *(undefined8 *)param_1[1] = *(undefined8 *)param_2[1];
    *(undefined8 *)(param_1[1] + 8) = uVar7;
    *(undefined8 *)(param_1[1] + 0x10) = uVar8;
    *(undefined8 *)(param_1[1] + 0x18) = uVar9;
    uVar7 = *(undefined8 *)(param_2[2] + 8);
    uVar8 = *(undefined8 *)(param_2[2] + 0x10);
    uVar9 = *(undefined8 *)(param_2[2] + 0x18);
    *(undefined8 *)param_1[2] = *(undefined8 *)param_2[2];
    *(undefined8 *)(param_1[2] + 8) = uVar7;
    *(undefined8 *)(param_1[2] + 0x10) = uVar8;
    *(undefined8 *)(param_1[2] + 0x18) = uVar9;
    uVar7 = *(undefined8 *)(param_2[3] + 8);
    uVar8 = *(undefined8 *)(param_2[3] + 0x10);
    uVar9 = *(undefined8 *)(param_2[3] + 0x18);
    *(undefined8 *)param_1[3] = *(undefined8 *)param_2[3];
    *(undefined8 *)(param_1[3] + 8) = uVar7;
    *(undefined8 *)(param_1[3] + 0x10) = uVar8;
    *(undefined8 *)(param_1[3] + 0x18) = uVar9;
    uVar7 = *(undefined8 *)(param_2[4] + 8);
    uVar8 = *(undefined8 *)(param_2[4] + 0x10);
    uVar9 = *(undefined8 *)(param_2[4] + 0x18);
    *(undefined8 *)param_1[4] = *(undefined8 *)param_2[4];
    *(undefined8 *)(param_1[4] + 8) = uVar7;
    *(undefined8 *)(param_1[4] + 0x10) = uVar8;
    *(undefined8 *)(param_1[4] + 0x18) = uVar9;
    uVar7 = *(undefined8 *)(param_2[5] + 8);
    uVar8 = *(undefined8 *)(param_2[5] + 0x10);
    uVar9 = *(undefined8 *)(param_2[5] + 0x18);
    *(undefined8 *)param_1[5] = *(undefined8 *)param_2[5];
    *(undefined8 *)(param_1[5] + 8) = uVar7;
    *(undefined8 *)(param_1[5] + 0x10) = uVar8;
    *(undefined8 *)(param_1[5] + 0x18) = uVar9;
    uVar7 = *(undefined8 *)(param_2[6] + 8);
    uVar8 = *(undefined8 *)(param_2[6] + 0x10);
    uVar9 = *(undefined8 *)(param_2[6] + 0x18);
    *(undefined8 *)param_1[6] = *(undefined8 *)param_2[6];
    *(undefined8 *)(param_1[6] + 8) = uVar7;
    *(undefined8 *)(param_1[6] + 0x10) = uVar8;
    *(undefined8 *)(param_1[6] + 0x18) = uVar9;
    puVar1 = (undefined8 *)(param_2[-1] + param_3);
    uVar7 = puVar1[1];
    uVar8 = puVar1[2];
    uVar9 = puVar1[3];
    puVar2 = (undefined8 *)(param_1[-1] + param_3);
    *puVar2 = *puVar1;
    puVar2[1] = uVar7;
    puVar2[2] = uVar8;
    puVar2[3] = uVar9;
    break;
  case 0x100:
    puVar1 = (undefined8 *)(param_2[-8] + param_3);
    uVar7 = puVar1[1];
    uVar8 = puVar1[2];
    uVar9 = puVar1[3];
    puVar2 = (undefined8 *)(param_1[-8] + param_3);
    *puVar2 = *puVar1;
    puVar2[1] = uVar7;
    puVar2[2] = uVar8;
    puVar2[3] = uVar9;
  case 0xe0:
    puVar1 = (undefined8 *)(param_2[-7] + param_3);
    uVar7 = puVar1[1];
    uVar8 = puVar1[2];
    uVar9 = puVar1[3];
    puVar2 = (undefined8 *)(param_1[-7] + param_3);
    *puVar2 = *puVar1;
    puVar2[1] = uVar7;
    puVar2[2] = uVar8;
    puVar2[3] = uVar9;
  case 0xc0:
    puVar1 = (undefined8 *)(param_2[-6] + param_3);
    uVar7 = puVar1[1];
    uVar8 = puVar1[2];
    uVar9 = puVar1[3];
    puVar2 = (undefined8 *)(param_1[-6] + param_3);
    *puVar2 = *puVar1;
    puVar2[1] = uVar7;
    puVar2[2] = uVar8;
    puVar2[3] = uVar9;
  case 0xa0:
    puVar1 = (undefined8 *)(param_2[-5] + param_3);
    uVar7 = puVar1[1];
    uVar8 = puVar1[2];
    uVar9 = puVar1[3];
    puVar2 = (undefined8 *)(param_1[-5] + param_3);
    *puVar2 = *puVar1;
    puVar2[1] = uVar7;
    puVar2[2] = uVar8;
    puVar2[3] = uVar9;
  case 0x80:
    puVar1 = (undefined8 *)(param_2[-4] + param_3);
    uVar7 = puVar1[1];
    uVar8 = puVar1[2];
    uVar9 = puVar1[3];
    puVar2 = (undefined8 *)(param_1[-4] + param_3);
    *puVar2 = *puVar1;
    puVar2[1] = uVar7;
    puVar2[2] = uVar8;
    puVar2[3] = uVar9;
  case 0x60:
    puVar1 = (undefined8 *)(param_2[-3] + param_3);
    uVar7 = puVar1[1];
    uVar8 = puVar1[2];
    uVar9 = puVar1[3];
    puVar2 = (undefined8 *)(param_1[-3] + param_3);
    *puVar2 = *puVar1;
    puVar2[1] = uVar7;
    puVar2[2] = uVar8;
    puVar2[3] = uVar9;
  case 0x40:
    puVar1 = (undefined8 *)(param_2[-2] + param_3);
    uVar7 = puVar1[1];
    uVar8 = puVar1[2];
    uVar9 = puVar1[3];
    puVar2 = (undefined8 *)(param_1[-2] + param_3);
    *puVar2 = *puVar1;
    puVar2[1] = uVar7;
    puVar2[2] = uVar8;
    puVar2[3] = uVar9;
  case 0x20:
    puVar1 = (undefined8 *)(param_2[-1] + param_3);
    uVar7 = puVar1[1];
    uVar8 = puVar1[2];
    uVar9 = puVar1[3];
    puVar2 = (undefined8 *)(param_1[-1] + param_3);
    *puVar2 = *puVar1;
    puVar2[1] = uVar7;
    puVar2[2] = uVar8;
    puVar2[3] = uVar9;
    break;
  default:
    uVar23 = (ulonglong)param_1 & 0x1f;
    pauVar22 = param_1;
    if (uVar23 != 0) {
      lVar24 = -uVar23;
      lVar25 = lVar24 + 0x20;
      param_3 = param_3 - lVar25;
      switch(uVar23) {
      default:
        uVar7 = *(undefined8 *)(*param_2 + 8);
        *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
        *(undefined8 *)(*param_1 + 8) = uVar7;
        uVar7 = *(undefined8 *)((longlong)param_2 + lVar24 + 0x18);
        *(undefined8 *)((longlong)param_1 + lVar24 + 0x10) =
             *(undefined8 *)((longlong)param_2 + lVar24 + 0x10);
        *(undefined8 *)((longlong)param_1 + lVar24 + 0x18) = uVar7;
        break;
      case 0x10:
        uVar7 = *(undefined8 *)(*param_2 + 8);
        *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
        *(undefined8 *)(*param_1 + 8) = uVar7;
        break;
      case 0x11:
      case 0x12:
      case 0x13:
      case 0x14:
      case 0x15:
      case 0x16:
      case 0x17:
        *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
        *(undefined8 *)((longlong)param_1 + lVar24 + 0x18) =
             *(undefined8 *)((longlong)param_2 + lVar24 + 0x18);
        break;
      case 0x18:
        *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
        break;
      case 0x19:
      case 0x1a:
      case 0x1b:
        *(undefined4 *)*param_1 = *(undefined4 *)*param_2;
        *(undefined4 *)((longlong)param_1 + lVar24 + 0x1c) =
             *(undefined4 *)((longlong)param_2 + lVar24 + 0x1c);
        break;
      case 0x1c:
        *(undefined4 *)*param_1 = *(undefined4 *)*param_2;
        break;
      case 0x1d:
        *(undefined2 *)*param_1 = *(undefined2 *)*param_2;
        (*param_1)[2] = (*param_2)[2];
        break;
      case 0x1e:
        *(undefined2 *)*param_1 = *(undefined2 *)*param_2;
        break;
      case 0x1f:
        (*param_1)[0] = (*param_2)[0];
      }
      pauVar22 = (undefined1 (*) [32])((longlong)param_1 + lVar25);
      param_2 = (undefined1 (*) [32])((longlong)param_2 + lVar25);
    }
    if (0xff < (longlong)param_3) {
      if (DAT_18001e888 - (DAT_18001e888 >> 2) <= param_3) {
        if (param_3 < DAT_18001e878) {
          for (; param_3 != 0; param_3 = param_3 - 1) {
            (*pauVar22)[0] = (*param_2)[0];
            param_2 = (undefined1 (*) [32])(*param_2 + 1);
            pauVar22 = (undefined1 (*) [32])(*pauVar22 + 1);
          }
          return param_1;
        }
        do {
          auVar3 = param_2[1];
          auVar4 = param_2[2];
          auVar5 = param_2[3];
          auVar6 = vmovntdq_avx(*param_2);
          *pauVar22 = auVar6;
          auVar3 = vmovntdq_avx(auVar3);
          pauVar22[1] = auVar3;
          auVar3 = vmovntdq_avx(auVar4);
          pauVar22[2] = auVar3;
          auVar3 = vmovntdq_avx(auVar5);
          pauVar22[3] = auVar3;
          param_3 = param_3 - 0x100;
          auVar3 = param_2[5];
          auVar4 = param_2[6];
          auVar5 = param_2[7];
          auVar6 = vmovntdq_avx(param_2[4]);
          pauVar22[4] = auVar6;
          auVar3 = vmovntdq_avx(auVar3);
          pauVar22[5] = auVar3;
          auVar3 = vmovntdq_avx(auVar4);
          pauVar22[6] = auVar3;
          auVar3 = vmovntdq_avx(auVar5);
          pauVar22[7] = auVar3;
          pauVar22 = pauVar22 + 8;
          param_2 = param_2 + 8;
        } while (0x2ff < (longlong)param_3);
      }
      do {
        uVar7 = *(undefined8 *)(*param_2 + 8);
        uVar8 = *(undefined8 *)(*param_2 + 0x10);
        uVar9 = *(undefined8 *)(*param_2 + 0x18);
        uVar10 = *(undefined8 *)param_2[1];
        uVar11 = *(undefined8 *)(param_2[1] + 8);
        uVar12 = *(undefined8 *)(param_2[1] + 0x10);
        uVar13 = *(undefined8 *)(param_2[1] + 0x18);
        uVar14 = *(undefined8 *)param_2[2];
        uVar15 = *(undefined8 *)(param_2[2] + 8);
        uVar16 = *(undefined8 *)(param_2[2] + 0x10);
        uVar17 = *(undefined8 *)(param_2[2] + 0x18);
        uVar18 = *(undefined8 *)param_2[3];
        uVar19 = *(undefined8 *)(param_2[3] + 8);
        uVar20 = *(undefined8 *)(param_2[3] + 0x10);
        uVar21 = *(undefined8 *)(param_2[3] + 0x18);
        *(undefined8 *)*pauVar22 = *(undefined8 *)*param_2;
        *(undefined8 *)(*pauVar22 + 8) = uVar7;
        *(undefined8 *)(*pauVar22 + 0x10) = uVar8;
        *(undefined8 *)(*pauVar22 + 0x18) = uVar9;
        *(undefined8 *)pauVar22[1] = uVar10;
        *(undefined8 *)(pauVar22[1] + 8) = uVar11;
        *(undefined8 *)(pauVar22[1] + 0x10) = uVar12;
        *(undefined8 *)(pauVar22[1] + 0x18) = uVar13;
        *(undefined8 *)pauVar22[2] = uVar14;
        *(undefined8 *)(pauVar22[2] + 8) = uVar15;
        *(undefined8 *)(pauVar22[2] + 0x10) = uVar16;
        *(undefined8 *)(pauVar22[2] + 0x18) = uVar17;
        *(undefined8 *)pauVar22[3] = uVar18;
        *(undefined8 *)(pauVar22[3] + 8) = uVar19;
        *(undefined8 *)(pauVar22[3] + 0x10) = uVar20;
        *(undefined8 *)(pauVar22[3] + 0x18) = uVar21;
        uVar7 = *(undefined8 *)(param_2[4] + 8);
        uVar8 = *(undefined8 *)(param_2[4] + 0x10);
        uVar9 = *(undefined8 *)(param_2[4] + 0x18);
        uVar10 = *(undefined8 *)param_2[5];
        uVar11 = *(undefined8 *)(param_2[5] + 8);
        uVar12 = *(undefined8 *)(param_2[5] + 0x10);
        uVar13 = *(undefined8 *)(param_2[5] + 0x18);
        uVar14 = *(undefined8 *)param_2[6];
        uVar15 = *(undefined8 *)(param_2[6] + 8);
        uVar16 = *(undefined8 *)(param_2[6] + 0x10);
        uVar17 = *(undefined8 *)(param_2[6] + 0x18);
        uVar18 = *(undefined8 *)param_2[7];
        uVar19 = *(undefined8 *)(param_2[7] + 8);
        uVar20 = *(undefined8 *)(param_2[7] + 0x10);
        uVar21 = *(undefined8 *)(param_2[7] + 0x18);
        *(undefined8 *)pauVar22[4] = *(undefined8 *)param_2[4];
        *(undefined8 *)(pauVar22[4] + 8) = uVar7;
        *(undefined8 *)(pauVar22[4] + 0x10) = uVar8;
        *(undefined8 *)(pauVar22[4] + 0x18) = uVar9;
        *(undefined8 *)pauVar22[5] = uVar10;
        *(undefined8 *)(pauVar22[5] + 8) = uVar11;
        *(undefined8 *)(pauVar22[5] + 0x10) = uVar12;
        *(undefined8 *)(pauVar22[5] + 0x18) = uVar13;
        *(undefined8 *)pauVar22[6] = uVar14;
        *(undefined8 *)(pauVar22[6] + 8) = uVar15;
        *(undefined8 *)(pauVar22[6] + 0x10) = uVar16;
        *(undefined8 *)(pauVar22[6] + 0x18) = uVar17;
        *(undefined8 *)pauVar22[7] = uVar18;
        *(undefined8 *)(pauVar22[7] + 8) = uVar19;
        *(undefined8 *)(pauVar22[7] + 0x10) = uVar20;
        *(undefined8 *)(pauVar22[7] + 0x18) = uVar21;
        pauVar22 = pauVar22 + 8;
        param_2 = param_2 + 8;
        param_3 = param_3 - 0x100;
      } while (0xff < param_3);
    }
                    /* WARNING: Could not recover jumptable at 0x0001800091a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pauVar22 = (undefined1 (*) [32])
               (*(code *)(&DAT_180009690 + -*(longlong *)(&DAT_180009690 + param_3 * 8)))
                         (param_1,(longlong)param_2 +
                                  (param_3 -
                                  ((longlong)(*pauVar22 + param_3) -
                                  ((ulonglong)(*pauVar22 + param_3) & 0xffffffffffffffe0))),param_3,
                          &DAT_180009690 + -*(longlong *)(&DAT_180009690 + param_3 * 8));
    return pauVar22;
  }
  return param_1;
}

/* RVA 0xa6c0, FUN_18000a6c0 */
undefined1 (*) [64]
FUN_18000a6c0(undefined1 (*param_1) [64],undefined1 (*param_2) [64],ulonglong param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined1 (*pauVar8) [64];
  undefined1 (*pauVar9) [64];
  ulonglong uVar10;
  undefined1 auVar11 [64];
  
  switch(param_3) {
  case 0:
    break;
  case 1:
    (*param_1)[0] = (*param_2)[0];
    break;
  case 2:
    *(undefined2 *)*param_1 = *(undefined2 *)*param_2;
    break;
  case 3:
    *(undefined2 *)*param_1 = *(undefined2 *)*param_2;
    (*param_1)[2] = (*param_2)[2];
    break;
  case 4:
    *(undefined4 *)*param_1 = *(undefined4 *)*param_2;
    break;
  case 5:
  case 6:
  case 7:
    *(undefined4 *)*param_1 = *(undefined4 *)*param_2;
    *(undefined4 *)(param_1[-1] + param_3 + 0x3c) = *(undefined4 *)(param_2[-1] + param_3 + 0x3c);
    break;
  case 8:
    *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
    break;
  case 9:
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
    *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
    *(undefined8 *)(param_1[-1] + param_3 + 0x38) = *(undefined8 *)(param_2[-1] + param_3 + 0x38);
    break;
  case 0x10:
    uVar1 = *(undefined8 *)(*param_2 + 8);
    *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
    *(undefined8 *)(*param_1 + 8) = uVar1;
    break;
  case 0x11:
  case 0x12:
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
  case 0x1e:
  case 0x1f:
    uVar1 = *(undefined8 *)(*param_2 + 8);
    *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
    *(undefined8 *)(*param_1 + 8) = uVar1;
    uVar1 = *(undefined8 *)(param_2[-1] + param_3 + 0x38);
    *(undefined8 *)(param_1[-1] + param_3 + 0x30) = *(undefined8 *)(param_2[-1] + param_3 + 0x30);
    *(undefined8 *)(param_1[-1] + param_3 + 0x38) = uVar1;
    break;
  case 0x20:
    uVar1 = *(undefined8 *)(*param_2 + 8);
    uVar2 = *(undefined8 *)(*param_2 + 0x10);
    uVar3 = *(undefined8 *)(*param_2 + 0x18);
    *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
    *(undefined8 *)(*param_1 + 8) = uVar1;
    *(undefined8 *)(*param_1 + 0x10) = uVar2;
    *(undefined8 *)(*param_1 + 0x18) = uVar3;
    break;
  case 0x21:
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x2c:
  case 0x2d:
  case 0x2e:
  case 0x2f:
  case 0x30:
  case 0x31:
  case 0x32:
  case 0x33:
  case 0x34:
  case 0x35:
  case 0x36:
  case 0x37:
  case 0x38:
  case 0x39:
  case 0x3a:
  case 0x3b:
  case 0x3c:
  case 0x3d:
  case 0x3e:
  case 0x3f:
    uVar1 = *(undefined8 *)(*param_2 + 8);
    uVar2 = *(undefined8 *)(*param_2 + 0x10);
    uVar3 = *(undefined8 *)(*param_2 + 0x18);
    *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
    *(undefined8 *)(*param_1 + 8) = uVar1;
    *(undefined8 *)(*param_1 + 0x10) = uVar2;
    *(undefined8 *)(*param_1 + 0x18) = uVar3;
    uVar1 = *(undefined8 *)(param_2[-1] + param_3 + 0x28);
    uVar2 = *(undefined8 *)(param_2[-1] + param_3 + 0x30);
    uVar3 = *(undefined8 *)(param_2[-1] + param_3 + 0x38);
    *(undefined8 *)(param_1[-1] + param_3 + 0x20) = *(undefined8 *)(param_2[-1] + param_3 + 0x20);
    *(undefined8 *)(param_1[-1] + param_3 + 0x28) = uVar1;
    *(undefined8 *)(param_1[-1] + param_3 + 0x30) = uVar2;
    *(undefined8 *)(param_1[-1] + param_3 + 0x38) = uVar3;
    break;
  case 0x40:
    uVar1 = *(undefined8 *)(*param_2 + 8);
    uVar2 = *(undefined8 *)(*param_2 + 0x10);
    uVar3 = *(undefined8 *)(*param_2 + 0x18);
    uVar4 = *(undefined8 *)(*param_2 + 0x20);
    uVar5 = *(undefined8 *)(*param_2 + 0x28);
    uVar6 = *(undefined8 *)(*param_2 + 0x30);
    uVar7 = *(undefined8 *)(*param_2 + 0x38);
    *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
    *(undefined8 *)(*param_1 + 8) = uVar1;
    *(undefined8 *)(*param_1 + 0x10) = uVar2;
    *(undefined8 *)(*param_1 + 0x18) = uVar3;
    *(undefined8 *)(*param_1 + 0x20) = uVar4;
    *(undefined8 *)(*param_1 + 0x28) = uVar5;
    *(undefined8 *)(*param_1 + 0x30) = uVar6;
    *(undefined8 *)(*param_1 + 0x38) = uVar7;
    break;
  case 0x41:
  case 0x42:
  case 0x43:
  case 0x44:
  case 0x45:
  case 0x46:
  case 0x47:
  case 0x48:
  case 0x49:
  case 0x4a:
  case 0x4b:
  case 0x4c:
  case 0x4d:
  case 0x4e:
  case 0x4f:
  case 0x50:
  case 0x51:
  case 0x52:
  case 0x53:
  case 0x54:
  case 0x55:
  case 0x56:
  case 0x57:
  case 0x58:
  case 0x59:
  case 0x5a:
  case 0x5b:
  case 0x5c:
  case 0x5d:
  case 0x5e:
  case 0x5f:
  case 0x60:
  case 0x61:
  case 0x62:
  case 99:
  case 100:
  case 0x65:
  case 0x66:
  case 0x67:
  case 0x68:
  case 0x69:
  case 0x6a:
  case 0x6b:
  case 0x6c:
  case 0x6d:
  case 0x6e:
  case 0x6f:
  case 0x70:
  case 0x71:
  case 0x72:
  case 0x73:
  case 0x74:
  case 0x75:
  case 0x76:
  case 0x77:
  case 0x78:
  case 0x79:
  case 0x7a:
  case 0x7b:
  case 0x7c:
  case 0x7d:
  case 0x7e:
  case 0x7f:
    uVar1 = *(undefined8 *)(*param_2 + 8);
    uVar2 = *(undefined8 *)(*param_2 + 0x10);
    uVar3 = *(undefined8 *)(*param_2 + 0x18);
    uVar4 = *(undefined8 *)(*param_2 + 0x20);
    uVar5 = *(undefined8 *)(*param_2 + 0x28);
    uVar6 = *(undefined8 *)(*param_2 + 0x30);
    uVar7 = *(undefined8 *)(*param_2 + 0x38);
    *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
    *(undefined8 *)(*param_1 + 8) = uVar1;
    *(undefined8 *)(*param_1 + 0x10) = uVar2;
    *(undefined8 *)(*param_1 + 0x18) = uVar3;
    *(undefined8 *)(*param_1 + 0x20) = uVar4;
    *(undefined8 *)(*param_1 + 0x28) = uVar5;
    *(undefined8 *)(*param_1 + 0x30) = uVar6;
    *(undefined8 *)(*param_1 + 0x38) = uVar7;
    uVar1 = *(undefined8 *)(param_2[-1] + param_3 + 8);
    uVar2 = *(undefined8 *)(param_2[-1] + param_3 + 0x10);
    uVar3 = *(undefined8 *)(param_2[-1] + param_3 + 0x18);
    uVar4 = *(undefined8 *)(param_2[-1] + param_3 + 0x20);
    uVar5 = *(undefined8 *)(param_2[-1] + param_3 + 0x28);
    uVar6 = *(undefined8 *)(param_2[-1] + param_3 + 0x30);
    uVar7 = *(undefined8 *)(param_2[-1] + param_3 + 0x38);
    *(undefined8 *)(param_1[-1] + param_3) = *(undefined8 *)(param_2[-1] + param_3);
    *(undefined8 *)(param_1[-1] + param_3 + 8) = uVar1;
    *(undefined8 *)(param_1[-1] + param_3 + 0x10) = uVar2;
    *(undefined8 *)(param_1[-1] + param_3 + 0x18) = uVar3;
    *(undefined8 *)(param_1[-1] + param_3 + 0x20) = uVar4;
    *(undefined8 *)(param_1[-1] + param_3 + 0x28) = uVar5;
    *(undefined8 *)(param_1[-1] + param_3 + 0x30) = uVar6;
    *(undefined8 *)(param_1[-1] + param_3 + 0x38) = uVar7;
    break;
  default:
    uVar10 = 0x40U - (longlong)param_1 & 0x3f;
    if (uVar10 != 0) {
      param_3 = param_3 - uVar10;
      switch(uVar10) {
      case 1:
        (*param_1)[0] = (*param_2)[0];
        break;
      case 2:
        *(undefined2 *)*param_1 = *(undefined2 *)*param_2;
        break;
      case 3:
        *(undefined2 *)*param_1 = *(undefined2 *)*param_2;
        (*param_1)[2] = (*param_2)[2];
        break;
      case 4:
        *(undefined4 *)*param_1 = *(undefined4 *)*param_2;
        break;
      case 5:
      case 6:
      case 7:
        *(undefined4 *)*param_1 = *(undefined4 *)*param_2;
        *(undefined4 *)(param_1[-1] + uVar10 + 0x3c) = *(undefined4 *)(param_2[-1] + uVar10 + 0x3c);
        break;
      case 8:
        *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
        break;
      case 9:
      case 10:
      case 0xb:
      case 0xc:
      case 0xd:
      case 0xe:
      case 0xf:
        *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
        *(undefined8 *)(param_1[-1] + uVar10 + 0x38) = *(undefined8 *)(param_2[-1] + uVar10 + 0x38);
        break;
      case 0x10:
        uVar1 = *(undefined8 *)(*param_2 + 8);
        *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
        *(undefined8 *)(*param_1 + 8) = uVar1;
        break;
      case 0x11:
      case 0x12:
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
      case 0x1e:
      case 0x1f:
        uVar1 = *(undefined8 *)(*param_2 + 8);
        *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
        *(undefined8 *)(*param_1 + 8) = uVar1;
        uVar1 = *(undefined8 *)(param_2[-1] + uVar10 + 0x38);
        *(undefined8 *)(param_1[-1] + uVar10 + 0x30) = *(undefined8 *)(param_2[-1] + uVar10 + 0x30);
        *(undefined8 *)(param_1[-1] + uVar10 + 0x38) = uVar1;
        break;
      case 0x20:
        uVar1 = *(undefined8 *)(*param_2 + 8);
        uVar2 = *(undefined8 *)(*param_2 + 0x10);
        uVar3 = *(undefined8 *)(*param_2 + 0x18);
        *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
        *(undefined8 *)(*param_1 + 8) = uVar1;
        *(undefined8 *)(*param_1 + 0x10) = uVar2;
        *(undefined8 *)(*param_1 + 0x18) = uVar3;
        break;
      default:
        uVar1 = *(undefined8 *)(*param_2 + 8);
        uVar2 = *(undefined8 *)(*param_2 + 0x10);
        uVar3 = *(undefined8 *)(*param_2 + 0x18);
        *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
        *(undefined8 *)(*param_1 + 8) = uVar1;
        *(undefined8 *)(*param_1 + 0x10) = uVar2;
        *(undefined8 *)(*param_1 + 0x18) = uVar3;
        uVar1 = *(undefined8 *)(param_2[-1] + uVar10 + 0x28);
        uVar2 = *(undefined8 *)(param_2[-1] + uVar10 + 0x30);
        uVar3 = *(undefined8 *)(param_2[-1] + uVar10 + 0x38);
        *(undefined8 *)(param_1[-1] + uVar10 + 0x20) = *(undefined8 *)(param_2[-1] + uVar10 + 0x20);
        *(undefined8 *)(param_1[-1] + uVar10 + 0x28) = uVar1;
        *(undefined8 *)(param_1[-1] + uVar10 + 0x30) = uVar2;
        *(undefined8 *)(param_1[-1] + uVar10 + 0x38) = uVar3;
      }
      param_1 = (undefined1 (*) [64])(*param_1 + uVar10);
      param_2 = (undefined1 (*) [64])(*param_2 + uVar10);
    }
    pauVar8 = param_1;
    pauVar9 = param_2;
    if (0x1ff < (longlong)param_3) {
      if (param_3 < DAT_18001e878) {
        do {
          auVar11 = vmovdqu64_avx512f(*param_2);
          *param_1 = auVar11;
          auVar11 = vmovdqu64_avx512f(param_2[1]);
          param_1[1] = auVar11;
          auVar11 = vmovdqu64_avx512f(param_2[2]);
          param_1[2] = auVar11;
          auVar11 = vmovdqu64_avx512f(param_2[3]);
          param_1[3] = auVar11;
          pauVar8 = param_1 + 8;
          pauVar9 = param_2 + 8;
          param_3 = param_3 - 0x200;
          auVar11 = vmovdqu64_avx512f(param_2[4]);
          param_1[4] = auVar11;
          auVar11 = vmovdqu64_avx512f(param_2[5]);
          param_1[5] = auVar11;
          auVar11 = vmovdqu64_avx512f(param_2[6]);
          param_1[6] = auVar11;
          auVar11 = vmovdqu64_avx512f(param_2[7]);
          param_1[7] = auVar11;
          param_1 = pauVar8;
          param_2 = pauVar9;
        } while (0x1ff < (longlong)param_3);
      }
      else {
        do {
          auVar11 = vmovdqu64_avx512f(*param_2);
          auVar11 = vmovntdq_avx512f(auVar11);
          *param_1 = auVar11;
          auVar11 = vmovdqu64_avx512f(param_2[1]);
          auVar11 = vmovntdq_avx512f(auVar11);
          param_1[1] = auVar11;
          auVar11 = vmovdqu64_avx512f(param_2[2]);
          auVar11 = vmovntdq_avx512f(auVar11);
          param_1[2] = auVar11;
          auVar11 = vmovdqu64_avx512f(param_2[3]);
          auVar11 = vmovntdq_avx512f(auVar11);
          param_1[3] = auVar11;
          pauVar8 = param_1 + 8;
          pauVar9 = param_2 + 8;
          param_3 = param_3 - 0x200;
          auVar11 = vmovdqu64_avx512f(param_2[4]);
          auVar11 = vmovntdq_avx512f(auVar11);
          param_1[4] = auVar11;
          auVar11 = vmovdqu64_avx512f(param_2[5]);
          auVar11 = vmovntdq_avx512f(auVar11);
          param_1[5] = auVar11;
          auVar11 = vmovdqu64_avx512f(param_2[6]);
          auVar11 = vmovntdq_avx512f(auVar11);
          param_1[6] = auVar11;
          auVar11 = vmovdqu64_avx512f(param_2[7]);
          auVar11 = vmovntdq_avx512f(auVar11);
          param_1[7] = auVar11;
          param_1 = pauVar8;
          param_2 = pauVar9;
        } while (0x1ff < (longlong)param_3);
      }
    }
    uVar10 = (ulonglong)(*pauVar8 + param_3) & 0xffffffffffffffc0;
                    /* WARNING: Could not recover jumptable at 0x00018000aa51. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pauVar8 = (undefined1 (*) [64])
              (*(code *)(&DAT_18000adc0 + -*(longlong *)(&DAT_18000adc0 + param_3 * 8)))
                        (uVar10,(longlong)pauVar9 + (uVar10 - (longlong)pauVar8),param_3,
                         &DAT_18000adc0 + -*(longlong *)(&DAT_18000adc0 + param_3 * 8));
    return pauVar8;
  }
  return param_1;
}

/* RVA 0xc1d0, FUN_18000c1d0 */
void FUN_18000c1d0(undefined4 param_1,undefined4 param_2,undefined4 param_3,ulonglong param_4)

{
  FUN_18000c1f0(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0xc1f0, FUN_18000c1f0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00018000cb28) */
/* WARNING: Removing unreachable block (ram,0x00018000c616) */
/* WARNING: Removing unreachable block (ram,0x00018000cabe) */
/* WARNING: Removing unreachable block (ram,0x00018000c5e1) */
/* WARNING: Removing unreachable block (ram,0x00018000c479) */
/* WARNING: Removing unreachable block (ram,0x00018000c453) */
/* WARNING: Removing unreachable block (ram,0x00018000c35b) */
/* WARNING: Removing unreachable block (ram,0x00018000ca64) */
/* WARNING: Removing unreachable block (ram,0x00018000c2c0) */
/* WARNING: Removing unreachable block (ram,0x00018000c26f) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_18000c1f0(undefined4 param_1,undefined4 param_2,undefined4 param_3,ulonglong param_4)

{
  longlong lVar1;
  int *piVar2;
  uint *puVar3;
  undefined8 uVar4;
  char cVar5;
  int in_EAX;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  char *pcVar10;
  char *pcVar11;
  longlong lVar12;
  ulonglong uVar13;
  longlong lVar14;
  uint unaff_EBP;
  uint unaff_EDI;
  int iVar15;
  longlong lVar16;
  undefined *puVar17;
  char *pcVar18;
  ulonglong uVar19;
  char *pcVar20;
  ulonglong uVar21;
  char *pcVar22;
  char *pcVar23;
  uint in_XCR0;
  undefined1 auStack_138 [32];
  int local_118;
  int local_114;
  int local_110;
  int local_10c;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  ulonglong local_e0;
  undefined4 uStack_d8;
  undefined4 uStack_c8;
  undefined4 local_b8;
  
  local_e0 = DAT_18001e800 ^ (ulonglong)auStack_138;
  local_f8 = 0;
  uStack_f0 = 0;
  local_108 = 0;
  uStack_100 = 0;
  uStack_d8 = param_1;
  uStack_c8 = param_2;
  local_b8 = param_3;
  uVar6 = FUN_18000dfe0(1);
  if (uVar6 != 0) {
    return uVar6;
  }
  piVar2 = (int *)cpuid_basic_info(0);
  local_10c = *piVar2;
  local_110 = piVar2[1];
  local_118 = piVar2[2];
  local_114 = piVar2[3];
  if ((local_10c == 0) ||
     ((in_EAX == 1 &&
      (((local_110 != 0x756e6547 || (local_118 != 0x49656e69)) || (local_114 != 0x6c65746e)))))) {
    _DAT_180020aa0 = local_f8;
    _DAT_180020aa8 = uStack_f0;
  }
  else {
    lVar16 = cpuid_Version_info(1);
    uVar6 = *(uint *)(lVar16 + 8);
    uVar21 = (ulonglong)*(uint *)(lVar16 + 0xc);
    if (((uVar6 & 1) != 0) && (uVar7 = FUN_18000dfe0(2), uVar7 != 0)) {
      return uVar7;
    }
    if (((short)uVar6 < 0) && (uVar7 = FUN_18000dfe0(3), uVar7 != 0)) {
      return uVar7;
    }
    if (((uVar6 >> 0x17 & 1) != 0) && (uVar7 = FUN_18000dfe0(4), uVar7 != 0)) {
      return uVar7;
    }
    uVar7 = (uint)uVar21;
    if ((uVar6 >> 0x18 & 1) != 0) {
      uVar7 = FUN_18000dfe0(5);
      if (uVar7 != 0) {
        return uVar7;
      }
      if (((uVar6 >> 0x19 & 1) != 0) && (uVar7 = FUN_18000dfe0(6), uVar7 != 0)) {
        return uVar7;
      }
      if (((uVar6 >> 0x1a & 1) != 0) && (uVar7 = FUN_18000dfe0(7), uVar7 != 0)) {
        return uVar7;
      }
      if (((uVar21 & 1) != 0) && (uVar7 = FUN_18000dfe0(8), uVar7 != 0)) {
        return uVar7;
      }
      if ((((uint)uVar21 >> 9 & 1) != 0) && (uVar7 = FUN_18000dfe0(9), uVar7 != 0)) {
        return uVar7;
      }
      if ((((uint)uVar21 >> 0x16 & 1) != 0) && (uVar7 = FUN_18000dfe0(0xc), uVar7 != 0)) {
        return uVar7;
      }
      if ((((uint)uVar21 >> 0x13 & 1) != 0) && (uVar7 = FUN_18000dfe0(10), uVar7 != 0)) {
        return uVar7;
      }
      if ((((uint)uVar21 >> 0x14 & 1) != 0) && (uVar7 = FUN_18000dfe0(0xb), uVar7 != 0)) {
        return uVar7;
      }
      if ((((uint)uVar21 >> 0x17 & 1) != 0) && (uVar7 = FUN_18000dfe0(0xd), uVar7 != 0)) {
        return uVar7;
      }
      uVar7 = (uint)uVar21;
      if (((uVar21 & 2) != 0) && (uVar8 = FUN_18000dfe0(0xe), uVar8 != 0)) {
        return uVar8;
      }
      if (((uVar7 >> 0x19 & 1) != 0) && (uVar8 = FUN_18000dfe0(0xf), uVar8 != 0)) {
        return uVar8;
      }
      lVar16 = cpuid_Extended_Feature_Enumeration_info(7);
      unaff_EDI = *(uint *)(lVar16 + 8);
      unaff_EBP = *(uint *)(lVar16 + 0xc);
      param_4 = (ulonglong)*(uint *)(lVar16 + 4);
      if (((*(uint *)(lVar16 + 4) >> 0x1d & 1) != 0) && (uVar8 = FUN_18000dfe0(0x24), uVar8 != 0)) {
        return uVar8;
      }
    }
    if (((uVar7 >> 0x1e & 1) != 0) && (uVar8 = FUN_18000dfe0(0x12), uVar8 != 0)) {
      return uVar8;
    }
    if ((uVar6 >> 0x18 & 1) == 0) {
      lVar16 = cpuid_Extended_Feature_Enumeration_info(7);
      unaff_EDI = *(uint *)(lVar16 + 8);
      unaff_EBP = *(uint *)(lVar16 + 0xc);
      param_4 = (ulonglong)*(uint *)(lVar16 + 4);
    }
    if (((~(uint)param_4 & 0x108) == 0) && (uVar6 = FUN_18000dfe0(0x14), uVar6 != 0)) {
      return uVar6;
    }
    if (((param_4 & 4) != 0) && (uVar6 = FUN_18000dfe0(0x36), uVar6 != 0)) {
      return uVar6;
    }
    if (((param_4 & 0x10) != 0) && (uVar6 = FUN_18000dfe0(0x16), uVar6 != 0)) {
      return uVar6;
    }
    if ((((uint)param_4 >> 0xb & 1) != 0) && (uVar6 = FUN_18000dfe0(0x17), uVar6 != 0)) {
      return uVar6;
    }
    if ((((uint)param_4 >> 0x13 & 1) != 0) && (uVar6 = FUN_18000dfe0(0x1d), uVar6 != 0)) {
      return uVar6;
    }
    if ((((uint)param_4 >> 0x12 & 1) != 0) && (uVar6 = FUN_18000dfe0(0x1e), uVar6 != 0)) {
      return uVar6;
    }
    if ((((uint)param_4 >> 0x18 & 1) != 0) && (uVar6 = FUN_18000dfe0(0x32), uVar6 != 0)) {
      return uVar6;
    }
    lVar16 = cpuid(0x80000001);
    if (((*(uint *)(lVar16 + 0xc) & 0x20) != 0) && (uVar6 = FUN_18000dfe0(0x15), uVar6 != 0)) {
      return uVar6;
    }
    lVar16 = cpuid(0x80000008);
    if (((*(uint *)(lVar16 + 4) >> 9 & 1) != 0) && (uVar6 = FUN_18000dfe0(0x37), uVar6 != 0)) {
      return uVar6;
    }
    if (((unaff_EBP & 0x20) != 0) && (uVar6 = FUN_18000dfe0(0x3e), uVar6 != 0)) {
      return uVar6;
    }
    if (((char)unaff_EBP < '\0') && (uVar6 = FUN_18000dfe0(0x35), uVar6 != 0)) {
      return uVar6;
    }
    if (((unaff_EBP >> 8 & 1) != 0) && (uVar6 = FUN_18000dfe0(0x2e), uVar6 != 0)) {
      return uVar6;
    }
    if (((unaff_EBP >> 0x16 & 1) != 0) && (uVar6 = FUN_18000dfe0(0x33), uVar6 != 0)) {
      return uVar6;
    }
    if (((unaff_EBP >> 0x19 & 1) != 0) && (uVar6 = FUN_18000dfe0(0x3b), uVar6 != 0)) {
      return uVar6;
    }
    if (((unaff_EBP >> 0x1b & 1) != 0) && (uVar6 = FUN_18000dfe0(0x3c), uVar6 != 0)) {
      return uVar6;
    }
    if (((unaff_EBP >> 0x1c & 1) != 0) && (uVar6 = FUN_18000dfe0(0x3d), uVar6 != 0)) {
      return uVar6;
    }
    if (((unaff_EBP >> 0x1d & 1) != 0) && (uVar6 = FUN_18000dfe0(0x40), uVar6 != 0)) {
      return uVar6;
    }
    if (((unaff_EDI >> 0x14 & 1) != 0) && (uVar6 = FUN_18000dfe0(0x34), uVar6 != 0)) {
      return uVar6;
    }
    if (((unaff_EDI >> 0x12 & 1) != 0) && (uVar6 = FUN_18000dfe0(0x38), uVar6 != 0)) {
      return uVar6;
    }
    lVar16 = cpuid(0x14);
    if (((*(uint *)(lVar16 + 4) & 0x10) != 0) && (uVar6 = FUN_18000dfe0(0x1b), uVar6 != 0)) {
      return uVar6;
    }
    if ((unaff_EBP >> 0x17 & 1) != 0) {
      uVar6 = FUN_18000dfe0(1);
      if (uVar6 != 0) {
        return uVar6;
      }
      lVar16 = cpuid(0x19);
      uVar6 = *(uint *)(lVar16 + 4);
      if (((uVar6 & 1) != 0) && (uVar8 = FUN_18000dfe0(0x45), uVar8 != 0)) {
        return uVar8;
      }
      if (((uVar6 & 4) != 0) && (uVar6 = FUN_18000dfe0(0x46), uVar6 != 0)) {
        return uVar6;
      }
    }
    puVar3 = (uint *)cpuid_Extended_Feature_Enumeration_info(7);
    uVar6 = puVar3[1];
    uVar19 = (ulonglong)puVar3[2];
    uVar21 = (ulonglong)*puVar3;
    if (((*puVar3 >> 0x16 & 1) != 0) && (uVar8 = FUN_18000dfe0(0x47), uVar8 != 0)) {
      return uVar8;
    }
    if (((unaff_EDI & 0x20) != 0) && (uVar8 = FUN_18000dfe0(0x48), uVar8 != 0)) {
      return uVar8;
    }
    if ((((uint)uVar19 >> 0xe & 1) != 0) && (uVar8 = FUN_18000dfe0(0x49), uVar8 != 0)) {
      return uVar8;
    }
    if (((char)uVar21 < '\0') && (uVar8 = FUN_18000dfe0(0x4b), uVar8 != 0)) {
      return uVar8;
    }
    if (((uVar21 & 8) != 0) && (uVar8 = FUN_18000dfe0(0x4e), uVar8 != 0)) {
      return uVar8;
    }
    if (((short)uVar19 < 0) && (uVar8 = FUN_18000dfe0(0x55), uVar8 != 0)) {
      return uVar8;
    }
    if ((((uint)uVar19 >> 0x15 & 1) != 0) && (uVar8 = FUN_18000dfe0(0x58), uVar8 != 0)) {
      return uVar8;
    }
    if ((((uint)uVar21 >> 0x1b & 1) != 0) && (uVar8 = FUN_18000dfe0(0x59), uVar8 != 0)) {
      return uVar8;
    }
    if ((((uint)uVar21 >> 0x13 & 1) != 0) && (uVar8 = FUN_18000dfe0(0x5a), uVar8 != 0)) {
      return uVar8;
    }
    if (((uVar6 & 2) != 0) && (uVar6 = FUN_18000dfe0(0x5b), uVar6 != 0)) {
      return uVar6;
    }
    if (((uint)uVar19 >> 0x13 & 1) != 0) {
      uVar6 = FUN_18000dfe0(1);
      if (uVar6 != 0) {
        return uVar6;
      }
      lVar16 = cpuid(0x24);
      uVar6 = *(uint *)(lVar16 + 4);
      if (((uVar6 >> 0x11 & 1) != 0) && (uVar8 = FUN_18000dfe0(0x56), uVar8 != 0)) {
        return uVar8;
      }
      if (((uVar6 >> 0x12 & 1) != 0) && (uVar6 = FUN_18000dfe0(0x57), uVar6 != 0)) {
        return uVar6;
      }
    }
    if ((uVar7 >> 0x1b & 1) != 0) {
      uVar6 = FUN_18000dfe0(1);
      if (uVar6 != 0) {
        return uVar6;
      }
      uVar4 = xinuse(0);
      uVar6 = ~(in_XCR0 & (uint)uVar4);
      uVar13 = (ulonglong)uVar6;
      if ((uVar6 & 0x60000) == 0) {
        uVar6 = FUN_18000dfe0(1);
        if (uVar6 != 0) {
          return uVar6;
        }
        if ((unaff_EDI >> 0x18 & 1) != 0) {
          uVar6 = FUN_18000dfe0(0x42);
          if (uVar6 != 0) {
            return uVar6;
          }
          if ((((uint)uVar21 >> 0x15 & 1) != 0) && (uVar6 = FUN_18000dfe0(0x4f), uVar6 != 0)) {
            return uVar6;
          }
          if ((((uint)uVar19 >> 8 & 1) != 0) && (uVar6 = FUN_18000dfe0(0x50), uVar6 != 0)) {
            return uVar6;
          }
          if (((unaff_EDI >> 0x19 & 1) != 0) && (uVar6 = FUN_18000dfe0(0x43), uVar6 != 0)) {
            return uVar6;
          }
          if (((unaff_EDI >> 0x16 & 1) != 0) && (uVar6 = FUN_18000dfe0(0x44), uVar6 != 0)) {
            return uVar6;
          }
        }
      }
      if ((uVar13 & 6) == 0) {
        uVar6 = FUN_18000dfe0(1);
        if (uVar6 != 0) {
          return uVar6;
        }
        if ((uVar7 >> 0x1c & 1) != 0) {
          uVar6 = FUN_18000dfe0(0x10);
          if (uVar6 != 0) {
            return uVar6;
          }
          if (((unaff_EBP >> 9 & 1) != 0) && (uVar6 = FUN_18000dfe0(0x2f), uVar6 != 0)) {
            return uVar6;
          }
          if (((unaff_EBP >> 10 & 1) != 0) && (uVar6 = FUN_18000dfe0(0x30), uVar6 != 0)) {
            return uVar6;
          }
          if (((uVar21 & 2) != 0) && (uVar6 = FUN_18000dfe0(0x52), uVar6 != 0)) {
            return uVar6;
          }
        }
        if (((uVar7 >> 0x1d & 1) != 0) && (uVar6 = FUN_18000dfe0(0x11), uVar6 != 0)) {
          return uVar6;
        }
        uVar6 = (uint)param_4;
        if ((param_4 & 0x20) != 0) {
          uVar8 = FUN_18000dfe0(0x18);
          if (uVar8 != 0) {
            return uVar8;
          }
          if (((uVar19 & 0x10) != 0) && (uVar8 = FUN_18000dfe0(0x4a), uVar8 != 0)) {
            return uVar8;
          }
          if ((((uint)uVar21 >> 0x17 & 1) != 0) && (uVar8 = FUN_18000dfe0(0x4c), uVar8 != 0)) {
            return uVar8;
          }
          uVar8 = (uint)uVar19;
          if (((uVar19 & 0x20) != 0) && (uVar9 = FUN_18000dfe0(0x4d), uVar9 != 0)) {
            return uVar9;
          }
          if (((uVar21 & 1) != 0) && (uVar9 = FUN_18000dfe0(0x51), uVar9 != 0)) {
            return uVar9;
          }
          if (((uVar21 & 4) != 0) && (uVar9 = FUN_18000dfe0(0x53), uVar9 != 0)) {
            return uVar9;
          }
          if (((uVar8 >> 10 & 1) != 0) && (uVar8 = FUN_18000dfe0(0x54), uVar8 != 0)) {
            return uVar8;
          }
        }
        if (((uVar7 >> 0xc & 1) != 0) && (uVar7 = FUN_18000dfe0(0x13), uVar7 != 0)) {
          return uVar7;
        }
        if ((uVar13 & 0x18) == 0) {
          uVar7 = FUN_18000dfe0(1);
          if (uVar7 != 0) {
            return uVar7;
          }
          if (((uVar6 >> 0xe & 1) != 0) && (uVar7 = FUN_18000dfe0(0x25), uVar7 != 0)) {
            return uVar7;
          }
        }
        if (((uVar21 & 0x10) != 0) && (uVar7 = FUN_18000dfe0(0x41), uVar7 != 0)) {
          return uVar7;
        }
        if ((uVar13 & 0xe0) == 0) {
          uVar7 = FUN_18000dfe0(1);
          if (uVar7 != 0) {
            return uVar7;
          }
          if (((uVar6 >> 0x10 & 1) != 0) && (uVar7 = FUN_18000dfe0(0x19), uVar7 != 0)) {
            return uVar7;
          }
          if (((uVar6 >> 0x1c & 1) != 0) && (uVar7 = FUN_18000dfe0(0x23), uVar7 != 0)) {
            return uVar7;
          }
          if (((uVar6 >> 0x1b & 1) != 0) && (uVar7 = FUN_18000dfe0(0x21), uVar7 != 0)) {
            return uVar7;
          }
          if (((uVar6 >> 0x1a & 1) != 0) && (uVar7 = FUN_18000dfe0(0x22), uVar7 != 0)) {
            return uVar7;
          }
          if (((uVar6 >> 0x11 & 1) != 0) && (uVar7 = FUN_18000dfe0(0x1a), uVar7 != 0)) {
            return uVar7;
          }
          if (((uVar6 >> 0x1e & 1) != 0) && (uVar7 = FUN_18000dfe0(0x26), uVar7 != 0)) {
            return uVar7;
          }
          if (((int)uVar6 < 0) && (uVar7 = FUN_18000dfe0(0x27), uVar7 != 0)) {
            return uVar7;
          }
          if (((uVar6 >> 0x15 & 1) != 0) && (uVar6 = FUN_18000dfe0(0x1f), uVar6 != 0)) {
            return uVar6;
          }
          if (((unaff_EBP & 2) != 0) && (uVar6 = FUN_18000dfe0(0x28), uVar6 != 0)) {
            return uVar6;
          }
          if (((unaff_EBP >> 0xe & 1) != 0) && (uVar6 = FUN_18000dfe0(0x2b), uVar6 != 0)) {
            return uVar6;
          }
          if (((unaff_EDI & 4) != 0) && (uVar6 = FUN_18000dfe0(0x2a), uVar6 != 0)) {
            return uVar6;
          }
          if (((unaff_EDI & 8) != 0) && (uVar6 = FUN_18000dfe0(0x29), uVar6 != 0)) {
            return uVar6;
          }
          if (((unaff_EBP >> 0xc & 1) != 0) && (uVar6 = FUN_18000dfe0(0x2c), uVar6 != 0)) {
            return uVar6;
          }
          if (((unaff_EBP & 0x40) != 0) && (uVar6 = FUN_18000dfe0(0x2d), uVar6 != 0)) {
            return uVar6;
          }
          if (((unaff_EBP >> 0xb & 1) != 0) && (uVar6 = FUN_18000dfe0(0x31), uVar6 != 0)) {
            return uVar6;
          }
          if (((uVar21 & 0x20) != 0) && (uVar6 = FUN_18000dfe0(0x3f), uVar6 != 0)) {
            return uVar6;
          }
          if (((unaff_EDI >> 0x17 & 1) != 0) && (uVar6 = FUN_18000dfe0(0x3a), uVar6 != 0)) {
            return uVar6;
          }
          if (((unaff_EDI >> 8 & 1) != 0) && (uVar6 = FUN_18000dfe0(0x39), uVar6 != 0)) {
            return uVar6;
          }
        }
      }
    }
    pcVar10 = getenv("INTEL_ISA_DISABLE");
    if ((pcVar10 != (char *)0x0) && (cVar5 = *pcVar10, cVar5 != '\0')) {
      lVar16 = 0;
      puVar17 = &DAT_180020ad0;
      pcVar18 = (char *)0x0;
      do {
        iVar15 = (int)lVar16;
        lVar14 = 1 - (longlong)pcVar10;
        pcVar22 = pcVar10;
        pcVar20 = pcVar10;
        while (pcVar20 = pcVar20 + 1, cVar5 == ',') {
          pcVar10 = pcVar22 + 1;
          pcVar22 = pcVar22 + 1;
          lVar14 = lVar14 + -1;
          cVar5 = *pcVar10;
        }
        if (cVar5 == '\0') break;
        pcVar23 = pcVar20;
        while( true ) {
          pcVar10 = pcVar23;
          if ((*pcVar10 == ',') || (*pcVar10 == '\0')) break;
          pcVar23 = pcVar10 + 1;
          pcVar18 = pcVar10;
        }
        pcVar23 = pcVar18 + (1 - (longlong)pcVar22);
        if (pcVar23 != (char *)0x0) {
          if (DAT_180020ac0 == '\0') {
            FUN_18000d1c0();
          }
          pcVar11 = (char *)((ulonglong)pcVar23 & 0xfffffffffffffffe);
          lVar12 = 1;
          do {
            lVar1 = *(longlong *)(puVar17 + lVar12 * 0x18 + 0x10);
            if (lVar1 != 0) {
              if (pcVar22 != pcVar18) {
                uVar21 = 0;
                do {
                  if ((pcVar20[uVar21 * 2 + -1] != *(char *)(lVar1 + uVar21 * 2)) ||
                     (pcVar20[uVar21 * 2] != *(char *)(lVar1 + 1 + uVar21 * 2))) goto LAB_18000c866;
                  uVar21 = uVar21 + 1;
                } while ((ulonglong)(pcVar18 + lVar14) >> 1 != uVar21);
              }
              if (((pcVar23 == pcVar11) || (pcVar22[(longlong)pcVar11] == pcVar11[lVar1])) &&
                 (pcVar23[lVar1] == '\0')) {
                if (1 < (uint)lVar12) {
                  uVar6 = FUN_18000dfe0((uint)lVar12);
                  lVar16 = lVar16 + (ulonglong)(uVar6 == 0);
                }
                break;
              }
            }
LAB_18000c866:
            lVar12 = lVar12 + 1;
          } while (lVar12 != 0x5c);
        }
        iVar15 = (int)lVar16;
        cVar5 = *pcVar10;
      } while (cVar5 != '\0');
      if (0 < iVar15) {
        local_f8 = CONCAT44(~local_108._4_4_ & local_f8._4_4_,~(uint)local_108 & (uint)local_f8);
        uStack_f0 = CONCAT44(~uStack_100._4_4_ & uStack_f0._4_4_,~(uint)uStack_100 & (uint)uStack_f0
                            );
      }
    }
    if (in_EAX == 1) {
      _DAT_180020aa8 = uStack_f0;
      _DAT_180020aa0 = local_f8;
      _DAT_180020ab8 = uStack_f0;
      DAT_180020ab0 = local_f8;
    }
    else {
      _DAT_180020ab8 = uStack_f0;
      DAT_180020ab0 = local_f8;
    }
  }
  return 0;
}

/* RVA 0xd180, FUN_18000d180 */
void FUN_18000d180(undefined4 param_1,undefined4 param_2,undefined4 param_3,ulonglong param_4)

{
  FUN_18000c1f0(param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0xd190, FUN_18000d190 */
undefined8 FUN_18000d190(int param_1)

{
  if (DAT_180020ac0 == '\0') {
    FUN_18000d1c0();
  }
  return *(undefined8 *)(&DAT_180020ad0 + (longlong)param_1 * 0x18);
}

/* RVA 0xd1c0, FUN_18000d1c0 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_18000d1c0(void)

{
  longlong lVar1;
  
  if (DAT_180020ac0 == '\0') {
    lVar1 = 200;
    do {
      *(undefined4 *)(&DAT_180020a28 + lVar1) = 0xffffffff;
      *(undefined4 *)(&DAT_180020a40 + lVar1) = 0xffffffff;
      *(undefined4 *)(&DAT_180020a58 + lVar1) = 0xffffffff;
      *(undefined4 *)(&DAT_180020a70 + lVar1) = 0xffffffff;
      *(undefined4 *)(&DAT_180020a88 + lVar1) = 0xffffffff;
      *(undefined4 *)(&DAT_180020aa0 + lVar1) = 0xffffffff;
      *(undefined4 *)(&DAT_180020ab8 + lVar1) = 0xffffffff;
      *(undefined4 *)(&DAT_180020ad0 + lVar1) = 0xffffffff;
      lVar1 = lVar1 + 0xc0;
    } while (lVar1 != 0x908);
    _DAT_180020ae8 = "GENERIC_IA32";
    DAT_180020af0 = 0;
    _DAT_180020b00 = &DAT_180017c8f;
    DAT_180020b08 = 1;
    _DAT_180020b18 = &DAT_180017c93;
    DAT_180020b20 = 2;
    DAT_180020b38 = 3;
    _DAT_180020b40 = &DAT_180017c98;
    _DAT_180020b30 = &DAT_180017c9c;
    _DAT_180020b48 = "FXSAVE";
    DAT_180020b50 = 4;
    DAT_180020b68 = 5;
    _DAT_180020b70 = &DAT_180017ca7;
    _DAT_180020b60 = &DAT_180017cab;
    DAT_180020b80 = 6;
    _DAT_180020b88 = &DAT_180017caf;
    _DAT_180020b78 = &DAT_180017cb4;
    DAT_180020b98 = 7;
    _DAT_180020ba0 = &DAT_180017cb9;
    _DAT_180020b90 = &DAT_180017cbe;
    DAT_180020bb0 = 8;
    _DAT_180020bb8 = "ssse3";
    _DAT_180020ba8 = "SSSE3";
    DAT_180020bc8 = 9;
    _DAT_180020bd0 = "sse4.1";
    _DAT_180020bc0 = "SSE4_1";
    DAT_180020be0 = 10;
    _DAT_180020be8 = &DAT_180017cdd;
    _DAT_180020bd8 = "SSE4_2";
    DAT_180020bf8 = 0xb;
    _DAT_180020c00 = "movbe";
    _DAT_180020bf0 = "MOVBE";
    DAT_180020c10 = 0xc;
    _DAT_180020c18 = "popcnt";
    _DAT_180020c08 = "POPCNT";
    DAT_180020c28 = 0xd;
    _DAT_180020c30 = "pclmul";
    _DAT_180020c20 = "PCLMULQDQ";
    DAT_180020c40 = 0xe;
    _DAT_180020c48 = &DAT_180017d14;
    _DAT_180020c38 = &DAT_180017d18;
    DAT_180020c58 = 0x10;
    _DAT_180020c60 = &DAT_180017d1c;
    _DAT_180020c50 = &DAT_180017d20;
    _DAT_180020c70 = 0xf;
    _DAT_180020c78 = &DAT_180017d24;
    _DAT_180020c68 = &DAT_180017d29;
    _DAT_180020c88 = 0x11;
    _DAT_180020c90 = "rdrnd";
    _DAT_180020c80 = "RDRND";
    _DAT_180020ca0 = 0x12;
    _DAT_180020ca8 = &DAT_180017d3a;
    _DAT_180020c98 = &DAT_180017d3e;
    _DAT_180020cb8 = 0x13;
    _DAT_180020cc0 = &DAT_180017d42;
    _DAT_180020cb0 = &DAT_180017d46;
    _DAT_180020cd0 = 0x14;
    _DAT_180020cd8 = "lzcnt";
    _DAT_180020cc8 = "LZCNT";
    _DAT_180020ce8 = 0x15;
    _DAT_180020cf0 = &DAT_180017d56;
    _DAT_180020ce0 = &DAT_180017d5a;
    _DAT_180020d00 = 0x16;
    _DAT_180020d08 = &DAT_180017d5e;
    _DAT_180020cf8 = &DAT_180017d62;
    _DAT_180020d18 = 0x17;
    _DAT_180020d20 = &DAT_180017d66;
    _DAT_180020d10 = &DAT_180017d6b;
    _DAT_180020d30 = 0x1b;
    _DAT_180020d38 = "avx512f";
    _DAT_180020d28 = "AVX512F";
    _DAT_180020d48 = 0x18;
    _DAT_180020d50 = "avx512dq";
    _DAT_180020d40 = "AVX512DQ";
    _DAT_180020d60 = 0x19;
    _DAT_180020d68 = "ptwrite";
    _DAT_180020d58 = "PTWRITE";
    _DAT_180020d70 = "KNCNI";
    _DAT_180020d78 = 0x1a;
    _DAT_180020d90 = 0x1c;
    _DAT_180020d98 = &DAT_180017da8;
    _DAT_180020d88 = &DAT_180017dac;
    _DAT_180020da8 = 0x1d;
    _DAT_180020db0 = "rdseed";
    _DAT_180020da0 = "RDSEED";
    _DAT_180020dc0 = 0x1e;
    _DAT_180020dc8 = "avx512ifma";
    _DAT_180020db8 = "AVX512IFMA52";
    _DAT_180020dd8 = 0xffffffff;
    _DAT_180020df0 = 0x20;
    _DAT_180020df8 = "avx512er";
    _DAT_180020de8 = "AVX512ER";
    _DAT_180020e08 = 0x21;
    _DAT_180020e10 = "avx512pf";
    _DAT_180020e00 = "AVX512PF";
    _DAT_180020e20 = 0x22;
    _DAT_180020e28 = "avx512cd";
    _DAT_180020e18 = "AVX512CD";
    _DAT_180020e38 = 0x23;
    _DAT_180020e40 = &DAT_180017e0c;
    _DAT_180020e30 = &DAT_180017e10;
    _DAT_180020e50 = 0x24;
    _DAT_180020e58 = &DAT_180017e14;
    _DAT_180020e48 = &DAT_180017e18;
    _DAT_180020e68 = 0x25;
    _DAT_180020e70 = "avx512bw";
    _DAT_180020e60 = "AVX512BW";
    _DAT_180020e80 = 0x26;
    _DAT_180020e88 = "avx512vl";
    _DAT_180020e78 = "AVX512VL";
    _DAT_180020e98 = 0x27;
    _DAT_180020ea0 = "avx512vbmi";
    _DAT_180020e90 = "AVX512VBMI";
    _DAT_180020eb0 = 0x28;
    _DAT_180020eb8 = "avx5124fmaps";
    _DAT_180020ea8 = "AVX512_4FMAPS";
    _DAT_180020ec8 = 0x29;
    _DAT_180020ed0 = "avx5124vnniw";
    _DAT_180020ec0 = "AVX512_4VNNIW";
    _DAT_180020ee0 = 0x2a;
    _DAT_180020ee8 = "avx512vpopcntdq";
    _DAT_180020ed8 = "AVX512_VPOPCNTDQ";
    _DAT_180020ef8 = 0x2b;
    _DAT_180020f00 = "avx512bitalg";
    _DAT_180020ef0 = "AVX512_BITALG";
    _DAT_180020f10 = 0x2c;
    _DAT_180020f18 = "avx512vbmi2";
    _DAT_180020f08 = "AVX512_VBMI2";
    _DAT_180020f28 = 0x2d;
    _DAT_180020f30 = &DAT_180017ee1;
    _DAT_180020f20 = &DAT_180017ee6;
    _DAT_180020f40 = 0x2e;
    _DAT_180020f48 = &DAT_180017eeb;
    _DAT_180020f38 = &DAT_180017ef0;
    _DAT_180020f58 = 0x2f;
    _DAT_180020f60 = "vpclmulqdq";
    _DAT_180020f50 = "VPCLMULQDQ";
    _DAT_180020f70 = 0x30;
    _DAT_180020f78 = "avx512vnni";
    _DAT_180020f68 = "AVX512_VNNI";
    _DAT_180020f88 = 0x31;
    _DAT_180020f90 = &DAT_180017f22;
    _DAT_180020f80 = &DAT_180017f27;
    _DAT_180020fa0 = 0x32;
    _DAT_180020fa8 = "rdpid";
    _DAT_180020f98 = "RDPID";
    _DAT_180020fb8 = 0x33;
    _DAT_180020fc0 = &DAT_180017f38;
    _DAT_180020fb0 = &DAT_180017f3c;
    _DAT_180020fd0 = 0x34;
    _DAT_180020fd8 = "shstk";
    _DAT_180020fc8 = "SHSTK";
    _DAT_180020fe8 = 0x35;
    _DAT_180020ff0 = &DAT_180017f4c;
    _DAT_180020fe0 = &DAT_180017f50;
    _DAT_180021000 = 0x36;
    _DAT_180021008 = "wbnoinvd";
    _DAT_180020ff8 = "WBNOINVD";
    _DAT_180021018 = 0x37;
    _DAT_180021020 = "pconfig";
    _DAT_180021010 = "PCONFIG";
    _DAT_180021030 = 0x38;
    _DAT_180021038 = "avx512vp2intersect";
    _DAT_180021028 = "AVX512_VP2INTERSECT";
    _DAT_180021048 = 0x3c;
    _DAT_180021050 = "avx512fp16";
    _DAT_180021040 = "AVX512_FP16";
    _DAT_180021060 = 0x40;
    _DAT_180021068 = "cldemote";
    _DAT_180021058 = "CLDEMOTE";
    _DAT_180021078 = 0x41;
    _DAT_180021080 = "movdiri";
    _DAT_180021070 = "MOVDIRI";
    _DAT_180021090 = 0x42;
    _DAT_180021098 = "movdir64b";
    _DAT_180021088 = "MOVDIR64B";
    _DAT_1800210a8 = 0x43;
    _DAT_1800210b0 = "waitpkg";
    _DAT_1800210a0 = "WAITPKG";
    _DAT_1800210c0 = 0x44;
    _DAT_1800210c8 = "avx512bf16";
    _DAT_1800210b8 = "AVX512_BF16";
    _DAT_1800210d8 = 0x45;
    _DAT_1800210e0 = "enqcmd";
    _DAT_1800210d0 = "ENQCMD";
    _DAT_1800210f0 = 0x46;
    _DAT_1800210f8 = "avxvnni";
    _DAT_1800210e8 = "AVX_VNNI";
    _DAT_180021108 = 0x47;
    _DAT_180021110 = "amx-tile";
    _DAT_180021100 = "AMX-TILE";
    _DAT_180021120 = 0x48;
    _DAT_180021128 = "amx-int8";
    _DAT_180021118 = "AMX-INT8";
    _DAT_180021138 = 0x49;
    _DAT_180021140 = "amx-bf16";
    _DAT_180021130 = "AMX-BF16";
    _DAT_180021150 = 0x4a;
    _DAT_180021158 = &DAT_180018066;
    _DAT_180021148 = &DAT_180018069;
    _DAT_180021168 = 0x4b;
    _DAT_180021170 = "wide-kl";
    _DAT_180021160 = "WIDE-KL";
    _DAT_180021180 = 0x4c;
    _DAT_180021188 = "hreset";
    _DAT_180021178 = "HRESET";
    _DAT_180021198 = 0x4d;
    _DAT_1800211a0 = "uintr";
    _DAT_180021190 = "UINTR";
    _DAT_1800211b0 = 0x4e;
    _DAT_1800211b8 = "prefetchi";
    _DAT_1800211a8 = "PREFETCHI";
    _DAT_1800211c8 = 0x4f;
    _DAT_1800211d0 = "avxvnniint8";
    _DAT_1800211c0 = "AVX_VNNI_INT8";
    _DAT_1800211e0 = 0x50;
    _DAT_1800211e8 = "cmpccxadd";
    _DAT_1800211d8 = "CMPCCXADD";
    _DAT_1800211f8 = 0x51;
    _DAT_180021200 = "avxifma";
    _DAT_1800211f0 = "AVX_IFMA";
    _DAT_180021210 = 0x52;
    _DAT_180021218 = "avxneconvert";
    _DAT_180021208 = "AVX_NE_CONVERT";
    _DAT_180021228 = 0x53;
    _DAT_180021230 = "raoint";
    _DAT_180021220 = "RAO_INT";
    _DAT_180021240 = 0x54;
    _DAT_180021248 = "amx-fp16";
    _DAT_180021238 = "AMX-FP16";
    _DAT_180021258 = 0x55;
    _DAT_180021260 = "amx-complex";
    _DAT_180021250 = "AMX-COMPLEX";
    _DAT_180021270 = 0x56;
    _DAT_180021278 = "sha512";
    _DAT_180021268 = "SHA512";
    _DAT_180021288 = 0x57;
    _DAT_180021290 = &DAT_18001814c;
    _DAT_180021280 = &DAT_180018150;
    _DAT_1800212a0 = 0x58;
    _DAT_1800212a8 = &DAT_180018154;
    _DAT_180021298 = &DAT_180018158;
    _DAT_1800212b8 = 0x59;
    _DAT_1800212c0 = "avxvnniint16";
    _DAT_1800212b0 = "AVX_VNNI_INT16";
    _DAT_1800212d0 = 0x5a;
    _DAT_1800212d8 = "usermsr";
    _DAT_1800212c8 = "USER_MSR";
    _DAT_1800212e8 = 0x5b;
    _DAT_1800212f0 = "avx10.1-256";
    _DAT_1800212e0 = "AVX_10_1";
    _DAT_180021300 = 0x5c;
    _DAT_180021308 = "avx10.1-512";
    _DAT_1800212f8 = "AVX_10_1_512";
    _DAT_180021318 = 0x5d;
    _DAT_180021320 = &DAT_1800181b7;
    _DAT_180021310 = &DAT_1800181bc;
    _DAT_180021330 = 0x5e;
    _DAT_180021338 = "msrlist";
    _DAT_180021328 = "MSRLIST";
    _DAT_180021348 = 0x5f;
    _DAT_180021350 = "wrmsrns";
    _DAT_180021340 = "WRMSRNS";
    _DAT_180021360 = 0x60;
    _DAT_180021368 = "pbndkb";
    _DAT_180021358 = "PBNDKB";
    DAT_180020ac0 = '\x01';
  }
  return;
}

/* RVA 0xdf50, FUN_18000df50 */
int FUN_18000df50(void)

{
  int in_EAX;
  int iVar1;
  
  if (DAT_180020ac0 == '\0') {
    FUN_18000d1c0();
  }
  iVar1 = -3;
  if (0xffffff7e < *(int *)(&DAT_180020ad8 + (longlong)in_EAX * 0x18) - 0x80U) {
    iVar1 = *(int *)(&DAT_180020ad8 + (longlong)in_EAX * 0x18);
  }
  return iVar1;
}

/* RVA 0xdf90, FUN_18000df90 */
ulonglong FUN_18000df90(longlong param_1,int param_2)

{
  ulonglong uVar1;
  
  if (DAT_180020ac0 == '\0') {
    FUN_18000d1c0();
  }
  uVar1 = 0xfffffffd;
  if (0xffffff7e < *(uint *)(&DAT_180020ad8 + (longlong)param_2 * 0x18) - 0x80) {
    uVar1 = (ulonglong)*(uint *)(&DAT_180020ad8 + (longlong)param_2 * 0x18);
  }
  if (-1 < (int)(uint)uVar1) {
    uVar1 = (ulonglong)
            ((*(ulonglong *)(param_1 + (ulonglong)((uint)uVar1 >> 6) * 8) >> (uVar1 & 0x3f) & 1) !=
            0);
  }
  return uVar1;
}

/* RVA 0xdfe0, FUN_18000dfe0 */
uint FUN_18000dfe0(int param_1)

{
  ulonglong *puVar1;
  uint uVar2;
  longlong in_RAX;
  
  if (DAT_180020ac0 == '\0') {
    FUN_18000d1c0();
  }
  uVar2 = 0xfffffffd;
  if (0xffffff7e < *(uint *)(&DAT_180020ad8 + (longlong)param_1 * 0x18) - 0x80) {
    uVar2 = *(uint *)(&DAT_180020ad8 + (longlong)param_1 * 0x18);
  }
  if (-1 < (int)uVar2) {
    puVar1 = (ulonglong *)(in_RAX + (ulonglong)(uVar2 >> 6) * 8);
    *puVar1 = *puVar1 | 1L << ((byte)uVar2 & 0x3f);
    uVar2 = 0;
  }
  return uVar2;
}

/* RVA 0xe040, FUN_18000e040 */
longlong * FUN_18000e040(longlong *param_1,ulonglong param_2,ulonglong param_3)

{
  longlong *plVar1;
  ulonglong uVar2;
  longlong lVar3;
  undefined1 uVar4;
  undefined2 uVar5;
  longlong lVar6;
  undefined4 uVar7;
  
  lVar6 = (param_2 & 0xff) * 0x101010101010101;
  uVar7 = (undefined4)lVar6;
  uVar5 = (undefined2)lVar6;
  uVar4 = (undefined1)lVar6;
  switch(param_3) {
  case 0:
    break;
  case 1:
    *(undefined1 *)param_1 = uVar4;
    break;
  case 2:
    *(undefined2 *)param_1 = uVar5;
    break;
  case 3:
    *(undefined2 *)param_1 = uVar5;
    *(undefined1 *)((longlong)param_1 + 2) = uVar4;
    break;
  case 4:
    *(undefined4 *)param_1 = uVar7;
    break;
  case 5:
  case 6:
  case 7:
    *(undefined4 *)param_1 = uVar7;
    *(undefined4 *)((longlong)param_1 + (param_3 - 4)) = uVar7;
    break;
  case 8:
    *param_1 = lVar6;
    break;
  case 9:
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
    *param_1 = lVar6;
    *(longlong *)((longlong)param_1 + (param_3 - 8)) = lVar6;
    break;
  case 0x10:
    *param_1 = lVar6;
    param_1[1] = lVar6;
    break;
  case 0x11:
  case 0x12:
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
  case 0x1e:
  case 0x1f:
    *param_1 = lVar6;
    param_1[1] = lVar6;
    *(longlong *)((longlong)param_1 + (param_3 - 0x10)) = lVar6;
    *(longlong *)((longlong)param_1 + (param_3 - 8)) = lVar6;
    break;
  case 0x20:
    *(undefined4 *)param_1 = uVar7;
    *(undefined4 *)((longlong)param_1 + 4) = uVar7;
    *(undefined4 *)(param_1 + 1) = uVar7;
    *(undefined4 *)((longlong)param_1 + 0xc) = uVar7;
    *(undefined4 *)(param_1 + 2) = uVar7;
    *(undefined4 *)((longlong)param_1 + 0x14) = uVar7;
    *(undefined4 *)(param_1 + 3) = uVar7;
    *(undefined4 *)((longlong)param_1 + 0x1c) = uVar7;
    break;
  case 0x21:
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x2c:
  case 0x2d:
  case 0x2e:
  case 0x2f:
  case 0x30:
  case 0x31:
  case 0x32:
  case 0x33:
  case 0x34:
  case 0x35:
  case 0x36:
  case 0x37:
  case 0x38:
  case 0x39:
  case 0x3a:
  case 0x3b:
  case 0x3c:
  case 0x3d:
  case 0x3e:
  case 0x3f:
    *(undefined4 *)param_1 = uVar7;
    *(undefined4 *)((longlong)param_1 + 4) = uVar7;
    *(undefined4 *)(param_1 + 1) = uVar7;
    *(undefined4 *)((longlong)param_1 + 0xc) = uVar7;
    *(undefined4 *)(param_1 + 2) = uVar7;
    *(undefined4 *)((longlong)param_1 + 0x14) = uVar7;
    *(undefined4 *)(param_1 + 3) = uVar7;
    *(undefined4 *)((longlong)param_1 + 0x1c) = uVar7;
    *(undefined4 *)((longlong)param_1 + (param_3 - 0x20)) = uVar7;
    *(undefined4 *)((longlong)param_1 + (param_3 - 0x1c)) = uVar7;
    *(undefined4 *)((longlong)param_1 + (param_3 - 0x18)) = uVar7;
    *(undefined4 *)((longlong)param_1 + (param_3 - 0x14)) = uVar7;
    *(undefined4 *)((longlong)param_1 + (param_3 - 0x10)) = uVar7;
    *(undefined4 *)((longlong)param_1 + (param_3 - 0xc)) = uVar7;
    *(undefined4 *)((longlong)param_1 + (param_3 - 8)) = uVar7;
    *(undefined4 *)((longlong)param_1 + (param_3 - 4)) = uVar7;
    break;
  case 0x40:
    *(undefined4 *)param_1 = uVar7;
    *(undefined4 *)((longlong)param_1 + 4) = uVar7;
    *(undefined4 *)(param_1 + 1) = uVar7;
    *(undefined4 *)((longlong)param_1 + 0xc) = uVar7;
    *(undefined4 *)(param_1 + 2) = uVar7;
    *(undefined4 *)((longlong)param_1 + 0x14) = uVar7;
    *(undefined4 *)(param_1 + 3) = uVar7;
    *(undefined4 *)((longlong)param_1 + 0x1c) = uVar7;
    *(undefined4 *)(param_1 + 4) = uVar7;
    *(undefined4 *)((longlong)param_1 + 0x24) = uVar7;
    *(undefined4 *)(param_1 + 5) = uVar7;
    *(undefined4 *)((longlong)param_1 + 0x2c) = uVar7;
    *(undefined4 *)(param_1 + 6) = uVar7;
    *(undefined4 *)((longlong)param_1 + 0x34) = uVar7;
    *(undefined4 *)(param_1 + 7) = uVar7;
    *(undefined4 *)((longlong)param_1 + 0x3c) = uVar7;
    break;
  case 0x41:
  case 0x42:
  case 0x43:
  case 0x44:
  case 0x45:
  case 0x46:
  case 0x47:
  case 0x48:
  case 0x49:
  case 0x4a:
  case 0x4b:
  case 0x4c:
  case 0x4d:
  case 0x4e:
  case 0x4f:
  case 0x50:
  case 0x51:
  case 0x52:
  case 0x53:
  case 0x54:
  case 0x55:
  case 0x56:
  case 0x57:
  case 0x58:
  case 0x59:
  case 0x5a:
  case 0x5b:
  case 0x5c:
  case 0x5d:
  case 0x5e:
  case 0x5f:
  case 0x60:
  case 0x61:
  case 0x62:
  case 99:
  case 100:
  case 0x65:
  case 0x66:
  case 0x67:
  case 0x68:
  case 0x69:
  case 0x6a:
  case 0x6b:
  case 0x6c:
  case 0x6d:
  case 0x6e:
  case 0x6f:
  case 0x70:
  case 0x71:
  case 0x72:
  case 0x73:
  case 0x74:
  case 0x75:
  case 0x76:
  case 0x77:
  case 0x78:
  case 0x79:
  case 0x7a:
  case 0x7b:
  case 0x7c:
  case 0x7d:
  case 0x7e:
  case 0x7f:
    *(undefined4 *)param_1 = uVar7;
    *(undefined4 *)((longlong)param_1 + 4) = uVar7;
    *(undefined4 *)(param_1 + 1) = uVar7;
    *(undefined4 *)((longlong)param_1 + 0xc) = uVar7;
    *(undefined4 *)(param_1 + 2) = uVar7;
    *(undefined4 *)((longlong)param_1 + 0x14) = uVar7;
    *(undefined4 *)(param_1 + 3) = uVar7;
    *(undefined4 *)((longlong)param_1 + 0x1c) = uVar7;
    *(undefined4 *)(param_1 + 4) = uVar7;
    *(undefined4 *)((longlong)param_1 + 0x24) = uVar7;
    *(undefined4 *)(param_1 + 5) = uVar7;
    *(undefined4 *)((longlong)param_1 + 0x2c) = uVar7;
    *(undefined4 *)(param_1 + 6) = uVar7;
    *(undefined4 *)((longlong)param_1 + 0x34) = uVar7;
    *(undefined4 *)(param_1 + 7) = uVar7;
    *(undefined4 *)((longlong)param_1 + 0x3c) = uVar7;
    *(undefined4 *)((longlong)param_1 + (param_3 - 0x20)) = uVar7;
    *(undefined4 *)((longlong)param_1 + (param_3 - 0x1c)) = uVar7;
    *(undefined4 *)((longlong)param_1 + (param_3 - 0x18)) = uVar7;
    *(undefined4 *)((longlong)param_1 + (param_3 - 0x14)) = uVar7;
    *(undefined4 *)((longlong)param_1 + (param_3 - 0x10)) = uVar7;
    *(undefined4 *)((longlong)param_1 + (param_3 - 0xc)) = uVar7;
    *(undefined4 *)((longlong)param_1 + (param_3 - 8)) = uVar7;
    *(undefined4 *)((longlong)param_1 + (param_3 - 4)) = uVar7;
    *(undefined4 *)((longlong)param_1 + (param_3 - 0x40)) = uVar7;
    *(undefined4 *)((longlong)param_1 + (param_3 - 0x3c)) = uVar7;
    *(undefined4 *)((longlong)param_1 + (param_3 - 0x38)) = uVar7;
    *(undefined4 *)((longlong)param_1 + (param_3 - 0x34)) = uVar7;
    *(undefined4 *)((longlong)param_1 + (param_3 - 0x30)) = uVar7;
    *(undefined4 *)((longlong)param_1 + (param_3 - 0x2c)) = uVar7;
    *(undefined4 *)((longlong)param_1 + (param_3 - 0x28)) = uVar7;
    *(undefined4 *)((longlong)param_1 + (param_3 - 0x24)) = uVar7;
    break;
  case 0x80:
    *(undefined4 *)param_1 = uVar7;
    *(undefined4 *)((longlong)param_1 + 4) = uVar7;
    *(undefined4 *)(param_1 + 1) = uVar7;
    *(undefined4 *)((longlong)param_1 + 0xc) = uVar7;
    *(undefined4 *)(param_1 + 2) = uVar7;
    *(undefined4 *)((longlong)param_1 + 0x14) = uVar7;
    *(undefined4 *)(param_1 + 3) = uVar7;
    *(undefined4 *)((longlong)param_1 + 0x1c) = uVar7;
    *(undefined4 *)(param_1 + 4) = uVar7;
    *(undefined4 *)((longlong)param_1 + 0x24) = uVar7;
    *(undefined4 *)(param_1 + 5) = uVar7;
    *(undefined4 *)((longlong)param_1 + 0x2c) = uVar7;
    *(undefined4 *)(param_1 + 6) = uVar7;
    *(undefined4 *)((longlong)param_1 + 0x34) = uVar7;
    *(undefined4 *)(param_1 + 7) = uVar7;
    *(undefined4 *)((longlong)param_1 + 0x3c) = uVar7;
    *(undefined4 *)(param_1 + 8) = uVar7;
    *(undefined4 *)((longlong)param_1 + 0x44) = uVar7;
    *(undefined4 *)(param_1 + 9) = uVar7;
    *(undefined4 *)((longlong)param_1 + 0x4c) = uVar7;
    *(undefined4 *)(param_1 + 10) = uVar7;
    *(undefined4 *)((longlong)param_1 + 0x54) = uVar7;
    *(undefined4 *)(param_1 + 0xb) = uVar7;
    *(undefined4 *)((longlong)param_1 + 0x5c) = uVar7;
    *(undefined4 *)(param_1 + 0xc) = uVar7;
    *(undefined4 *)((longlong)param_1 + 100) = uVar7;
    *(undefined4 *)(param_1 + 0xd) = uVar7;
    *(undefined4 *)((longlong)param_1 + 0x6c) = uVar7;
    *(undefined4 *)(param_1 + 0xe) = uVar7;
    *(undefined4 *)((longlong)param_1 + 0x74) = uVar7;
    *(undefined4 *)(param_1 + 0xf) = uVar7;
    *(undefined4 *)((longlong)param_1 + 0x7c) = uVar7;
    break;
  default:
    uVar2 = (ulonglong)param_1 & 0x1f;
    plVar1 = param_1;
    if (uVar2 != 0) {
      lVar3 = -uVar2;
      param_3 = param_3 - (lVar3 + 0x20);
      switch(uVar2) {
      default:
        *param_1 = lVar6;
        param_1[1] = lVar6;
        *(longlong *)((longlong)param_1 + lVar3 + 0x10) = lVar6;
        *(longlong *)((longlong)param_1 + lVar3 + 0x18) = lVar6;
        break;
      case 0x10:
        *param_1 = lVar6;
        param_1[1] = lVar6;
        break;
      case 0x11:
      case 0x12:
      case 0x13:
      case 0x14:
      case 0x15:
      case 0x16:
      case 0x17:
        *param_1 = lVar6;
        *(longlong *)((longlong)param_1 + lVar3 + 0x18) = lVar6;
        break;
      case 0x18:
        *param_1 = lVar6;
        break;
      case 0x19:
      case 0x1a:
      case 0x1b:
        *(undefined4 *)param_1 = uVar7;
        *(undefined4 *)((longlong)param_1 + lVar3 + 0x1c) = uVar7;
        break;
      case 0x1c:
        *(undefined4 *)param_1 = uVar7;
        break;
      case 0x1d:
        *(undefined2 *)param_1 = uVar5;
        *(undefined1 *)((longlong)param_1 + 2) = uVar4;
        break;
      case 0x1e:
        *(undefined2 *)param_1 = uVar5;
        break;
      case 0x1f:
        *(undefined1 *)param_1 = uVar4;
      }
      plVar1 = (longlong *)((longlong)param_1 + lVar3 + 0x20);
    }
    if (0xff < (longlong)param_3) {
      if (DAT_18001e880 - (DAT_18001e880 >> 4) <= param_3) {
        for (; param_3 != 0; param_3 = param_3 - 1) {
          *(undefined1 *)plVar1 = uVar4;
          plVar1 = (longlong *)((longlong)plVar1 + 1);
        }
        return param_1;
      }
      do {
        *(undefined4 *)plVar1 = uVar7;
        *(undefined4 *)((longlong)plVar1 + 4) = uVar7;
        *(undefined4 *)(plVar1 + 1) = uVar7;
        *(undefined4 *)((longlong)plVar1 + 0xc) = uVar7;
        *(undefined4 *)(plVar1 + 2) = uVar7;
        *(undefined4 *)((longlong)plVar1 + 0x14) = uVar7;
        *(undefined4 *)(plVar1 + 3) = uVar7;
        *(undefined4 *)((longlong)plVar1 + 0x1c) = uVar7;
        *(undefined4 *)(plVar1 + 4) = uVar7;
        *(undefined4 *)((longlong)plVar1 + 0x24) = uVar7;
        *(undefined4 *)(plVar1 + 5) = uVar7;
        *(undefined4 *)((longlong)plVar1 + 0x2c) = uVar7;
        *(undefined4 *)(plVar1 + 6) = uVar7;
        *(undefined4 *)((longlong)plVar1 + 0x34) = uVar7;
        *(undefined4 *)(plVar1 + 7) = uVar7;
        *(undefined4 *)((longlong)plVar1 + 0x3c) = uVar7;
        *(undefined4 *)(plVar1 + 8) = uVar7;
        *(undefined4 *)((longlong)plVar1 + 0x44) = uVar7;
        *(undefined4 *)(plVar1 + 9) = uVar7;
        *(undefined4 *)((longlong)plVar1 + 0x4c) = uVar7;
        *(undefined4 *)(plVar1 + 10) = uVar7;
        *(undefined4 *)((longlong)plVar1 + 0x54) = uVar7;
        *(undefined4 *)(plVar1 + 0xb) = uVar7;
        *(undefined4 *)((longlong)plVar1 + 0x5c) = uVar7;
        *(undefined4 *)(plVar1 + 0xc) = uVar7;
        *(undefined4 *)((longlong)plVar1 + 100) = uVar7;
        *(undefined4 *)(plVar1 + 0xd) = uVar7;
        *(undefined4 *)((longlong)plVar1 + 0x6c) = uVar7;
        *(undefined4 *)(plVar1 + 0xe) = uVar7;
        *(undefined4 *)((longlong)plVar1 + 0x74) = uVar7;
        *(undefined4 *)(plVar1 + 0xf) = uVar7;
        *(undefined4 *)((longlong)plVar1 + 0x7c) = uVar7;
        param_3 = param_3 - 0x100;
        *(undefined4 *)(plVar1 + 0x10) = uVar7;
        *(undefined4 *)((longlong)plVar1 + 0x84) = uVar7;
        *(undefined4 *)(plVar1 + 0x11) = uVar7;
        *(undefined4 *)((longlong)plVar1 + 0x8c) = uVar7;
        *(undefined4 *)(plVar1 + 0x12) = uVar7;
        *(undefined4 *)((longlong)plVar1 + 0x94) = uVar7;
        *(undefined4 *)(plVar1 + 0x13) = uVar7;
        *(undefined4 *)((longlong)plVar1 + 0x9c) = uVar7;
        *(undefined4 *)(plVar1 + 0x14) = uVar7;
        *(undefined4 *)((longlong)plVar1 + 0xa4) = uVar7;
        *(undefined4 *)(plVar1 + 0x15) = uVar7;
        *(undefined4 *)((longlong)plVar1 + 0xac) = uVar7;
        *(undefined4 *)(plVar1 + 0x16) = uVar7;
        *(undefined4 *)((longlong)plVar1 + 0xb4) = uVar7;
        *(undefined4 *)(plVar1 + 0x17) = uVar7;
        *(undefined4 *)((longlong)plVar1 + 0xbc) = uVar7;
        *(undefined4 *)(plVar1 + 0x18) = uVar7;
        *(undefined4 *)((longlong)plVar1 + 0xc4) = uVar7;
        *(undefined4 *)(plVar1 + 0x19) = uVar7;
        *(undefined4 *)((longlong)plVar1 + 0xcc) = uVar7;
        *(undefined4 *)(plVar1 + 0x1a) = uVar7;
        *(undefined4 *)((longlong)plVar1 + 0xd4) = uVar7;
        *(undefined4 *)(plVar1 + 0x1b) = uVar7;
        *(undefined4 *)((longlong)plVar1 + 0xdc) = uVar7;
        *(undefined4 *)(plVar1 + 0x1c) = uVar7;
        *(undefined4 *)((longlong)plVar1 + 0xe4) = uVar7;
        *(undefined4 *)(plVar1 + 0x1d) = uVar7;
        *(undefined4 *)((longlong)plVar1 + 0xec) = uVar7;
        *(undefined4 *)(plVar1 + 0x1e) = uVar7;
        *(undefined4 *)((longlong)plVar1 + 0xf4) = uVar7;
        *(undefined4 *)(plVar1 + 0x1f) = uVar7;
        *(undefined4 *)((longlong)plVar1 + 0xfc) = uVar7;
        plVar1 = plVar1 + 0x20;
      } while (0xff < (longlong)param_3);
    }
                    /* WARNING: Could not recover jumptable at 0x00018000e215. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    plVar1 = (longlong *)
             (*(code *)(&DAT_18000e4e0 + -*(longlong *)(&DAT_18000e4e0 + param_3 * 8)))
                       (CONCAT44(uVar7,uVar7),
                        &DAT_18000e4e0 + -*(longlong *)(&DAT_18000e4e0 + param_3 * 8));
    return plVar1;
  }
  return param_1;
}

/* RVA 0x109d0, FUN_1800109d0 */
undefined4 FUN_1800109d0(int param_1,undefined8 param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (0xfffffffc < param_1 - 4U) {
    if (DAT_18002137c == 0) {
      FUN_180010a10((ulonglong)(param_1 - 4U),param_2);
    }
    uVar1 = (&DAT_180021370)[(uint)(param_1 << 2)];
  }
  return uVar1;
}

/* RVA 0x10a10, FUN_180010a10 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x000180010c2b) */
/* WARNING: Removing unreachable block (ram,0x000180010c14) */
/* WARNING: Removing unreachable block (ram,0x000180010bfd) */
/* WARNING: Removing unreachable block (ram,0x000180010bdb) */
/* WARNING: Removing unreachable block (ram,0x000180010aed) */
/* WARNING: Removing unreachable block (ram,0x000180010a8c) */
/* WARNING: Removing unreachable block (ram,0x000180010ccb) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_180010a10(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  uint *puVar2;
  longlong lVar3;
  uint uVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  ulonglong uVar8;
  longlong lVar9;
  ulonglong uVar10;
  undefined4 *puVar11;
  ulonglong uVar12;
  undefined8 unaff_RBX;
  undefined8 uVar13;
  ulonglong *puVar14;
  int iVar15;
  int iVar16;
  undefined8 unaff_RDI;
  int iVar17;
  int iVar18;
  ulonglong uVar19;
  ulonglong uVar20;
  byte in_AF;
  byte in_TF;
  byte in_IF;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  ulonglong uStack_120;
  undefined8 uStack_118;
  ulonglong uStack_110;
  uint local_e8 [2];
  undefined4 local_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined1 local_88 [48];
  uint *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  ulonglong local_48;
  
  local_48 = DAT_18001e800 ^ (ulonglong)local_88;
  uVar12 = local_d8 >> 0x20;
  local_d8 = local_d8 & 0xffffffff00000000;
  uStack_110 = local_48;
  puVar14 = &uStack_118;
  uStack_118 = param_1;
  uVar7 = (uint)(in_NT & 1) * 0x4000 | (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 |
          (uint)((longlong)local_48 < 0) * 0x80 | (uint)(local_48 == 0) * 0x40 |
          (uint)(in_AF & 1) * 0x10 | (uint)((POPCOUNT(local_48 & 0xff) & 1U) == 0) * 4 |
          (uint)(in_ID & 1) * 0x200000 | (uint)(in_VIP & 1) * 0x100000 |
          (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000;
  uVar6 = uVar7 ^ 0x200000;
  uStack_120 = (ulonglong)((uVar6 & 0x4000) != 0) * 0x4000 |
               (ulonglong)((uVar6 & 0x200) != 0) * 0x200 | (ulonglong)((uVar6 & 0x100) != 0) * 0x100
               | (ulonglong)((uVar6 & 0x80) != 0) * 0x80 | (ulonglong)((uVar6 & 0x40) != 0) * 0x40 |
               (ulonglong)((uVar6 & 0x10) != 0) * 0x10 | (ulonglong)((uVar6 & 4) != 0) * 4 |
               (ulonglong)((uVar6 & 0x200000) != 0) * 0x200000 |
               (ulonglong)((uVar6 & 0x40000) != 0) * 0x40000;
  if ((uint)uStack_120 != uVar7) {
    local_d8 = CONCAT44((int)uVar12,1);
    puVar14 = &uStack_120;
    uStack_120 = (ulonglong)uVar7;
  }
  uVar13 = puVar14[1];
  if ((uint)local_d8 != 0) {
    local_58 = local_e8;
    local_d8 = s_GenuineIntel_1800181f0._0_8_;
    uStack_d0 = ram0x0001800181f8;
    local_e0 = 0;
    local_e8[0] = 0;
    puVar14[2] = 0;
    puVar14[1] = unaff_RBX;
    *puVar14 = uVar13;
    puVar14[-1] = param_2;
    puVar2 = (uint *)cpuid_basic_info(0);
    local_d8._0_4_ = s_GenuineIntel_1800181f0._0_4_;
    if ((uint)local_d8 == puVar2[1]) {
      local_d8._4_4_ = s_GenuineIntel_1800181f0._4_4_;
      if (local_d8._4_4_ == puVar2[2]) {
        uStack_d0._0_4_ = (uint)ram0x0001800181f8;
        if ((uint)uStack_d0 == puVar2[3]) {
          local_e0 = 1;
          local_e8[0] = *puVar2;
        }
      }
    }
    puVar11 = (undefined4 *)puVar14[-1];
    lVar9 = *puVar14;
    uVar13 = puVar14[1];
    DAT_180021370 = local_e0;
    DAT_180021374 = local_e8[0];
    if (3 < (int)local_e8[0]) {
      local_58 = (uint *)&local_d8;
      puVar14[2] = (ulonglong)&local_d8;
      puVar14[1] = uVar13;
      *puVar14 = lVar9;
      puVar14[-1] = (ulonglong)puVar11;
      puVar14[-2] = unaff_RDI;
      iVar16 = 0;
      while( true ) {
        puVar2 = (uint *)cpuid_Deterministic_Cache_Parameters_info(4);
        uVar6 = puVar2[1];
        uVar7 = puVar2[2];
        uVar4 = puVar2[3];
        if ((*puVar2 & 0x1f) == 0) break;
        *local_58 = *puVar2;
        local_58[1] = uVar6;
        local_58[2] = uVar4;
        local_58[3] = uVar7;
        iVar16 = iVar16 + 1;
        if (7 < iVar16) break;
        local_58 = local_58 + 4;
      }
      puVar11 = (undefined4 *)puVar14[-1];
      lVar9 = *puVar14;
      uVar13 = puVar14[1];
      if (0 < (longlong)iVar16) {
        lVar9 = 0;
        puVar11 = &DAT_180021370;
        do {
          if ((*(uint *)(local_88 + lVar9 + -0x50) & 0x1f | 2) == 3) {
            uVar6 = *(uint *)(local_88 + lVar9 + -0x4c);
            iVar1 = *(int *)(local_88 + lVar9 + -0x48);
            iVar18 = (uVar6 & 0xfff) + 1;
            uVar12 = (ulonglong)(*(uint *)(local_88 + lVar9 + -0x50) >> 1 & 0x70);
            *(int *)((longlong)&DAT_180021374 + uVar12) = iVar18;
            iVar15 = (uVar6 >> 0xc & 0x3ff) + 1;
            *(int *)(&DAT_180021378 + uVar12) = iVar15;
            iVar17 = (uVar6 >> 0x16) + 1;
            *(int *)((longlong)&DAT_18002137c + uVar12) = iVar17;
            *(uint *)((longlong)&DAT_180021370 + uVar12) =
                 (uint)((iVar1 + 1) * iVar15 * iVar17 * iVar18) >> 10;
          }
          lVar9 = lVar9 + 0x10;
        } while ((longlong)iVar16 * 0x10 != lVar9);
      }
    }
    if ((DAT_180021380 == 0) && (1 < (int)local_e8[0])) {
      local_58 = (uint *)&local_d8;
      puVar14[2] = (ulonglong)local_e8[0];
      puVar14[1] = uVar13;
      *puVar14 = lVar9;
      puVar14[-1] = (ulonglong)puVar11;
      puVar11 = (undefined4 *)cpuid_cache_tlb_info(2);
      local_d8._0_1_ = (byte)*puVar11;
      if ('\x01' < (char)(byte)local_d8) {
        if ('\x02' < (char)(byte)local_d8) {
          if ('\x03' < (char)(byte)local_d8) {
            puVar11 = (undefined4 *)cpuid_cache_tlb_info(2);
            local_a8 = *puVar11;
            local_a4 = puVar11[1];
            local_a0 = puVar11[3];
            local_9c = puVar11[2];
          }
          puVar11 = (undefined4 *)cpuid_cache_tlb_info(2);
          local_b8 = *puVar11;
          local_b4 = puVar11[1];
          local_b0 = puVar11[3];
          local_ac = puVar11[2];
        }
        puVar11 = (undefined4 *)cpuid_cache_tlb_info(2);
        local_c8 = *puVar11;
        local_c4 = puVar11[1];
        local_c0 = puVar11[3];
        local_bc = puVar11[2];
      }
      uVar12 = puVar14[-1];
      uVar13 = puVar14[1];
      uVar10 = (ulonglong)(byte)((byte)local_d8 * '\x04');
      bVar5 = 0x10;
      if ((byte)local_d8 < 5) {
        bVar5 = (byte)local_d8 * '\x04';
      }
      if (bVar5 != 0) {
        uVar19 = 0;
        do {
          if (-1 < (char)local_88[uVar19 * 4 + -0x4d]) {
            lVar9 = 0;
            do {
              uVar20 = (ulonglong)*(byte *)((longlong)local_58 + lVar9);
              if (uVar20 == 0xff) {
                _DAT_180021380 = 0;
                _DAT_180021388 = 0;
                _DAT_180021390 = 0;
                _DAT_180021398 = 0;
                _DAT_1800213a0 = 0;
                _DAT_1800213a8 = 0;
                goto LAB_180010d80;
              }
              uVar6 = *(uint *)(&DAT_180018200 + uVar20 * 8);
              uVar7 = uVar6 & 7;
              if (uVar7 != 0) {
                if ((uVar7 == 2) && (*(byte *)((longlong)local_58 + lVar9) == 0x49)) {
                  puVar14[2] = 2;
                  puVar14[1] = uVar13;
                  *puVar14 = uVar10;
                  puVar14[-1] = uVar12;
                  lVar3 = cpuid_Version_info(1);
                  uVar4 = *(uint *)(lVar3 + 4);
                  local_50 = *(undefined4 *)(lVar3 + 0xc);
                  local_4c = *(undefined4 *)(lVar3 + 8);
                  uVar13 = puVar14[1];
                  uVar12 = (ulonglong)(uVar4 & 0xf000f00);
                  uVar7 = 2;
                  if ((uVar4 & 0xf000f00) == 0xf00) {
                    uVar7 = (uVar4 >> 4 & 0xf | uVar4 >> 0xc & 0xf0) == 6 | 2;
                  }
                }
                uVar8 = (ulonglong)(uVar7 << 4);
                *(uint *)((longlong)&DAT_180021374 + uVar8) = uVar6 >> 3 & 0xfff;
                *(uint *)(&DAT_180021378 + uVar8) = uVar6 >> 0xf & 0x7f;
                *(uint *)((longlong)&DAT_18002137c + uVar8) = uVar6 >> 0x16;
                uVar10 = (ulonglong)*(uint *)(&DAT_180018204 + uVar20 * 8);
                *(uint *)((longlong)&DAT_180021370 + uVar8) = *(uint *)(&DAT_180018204 + uVar20 * 8)
                ;
              }
              lVar9 = lVar9 + 1;
            } while (lVar9 != 4);
          }
          uVar19 = uVar19 + 1;
          local_58 = (uint *)((longlong)local_58 + 4);
        } while (uVar19 != bVar5);
      }
    }
  }
LAB_180010d80:
  DAT_18002137c = 1;
  puVar14[2] = 0x180010d96;
  return;
}

/* RVA 0x10db0, FUN_180010db0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x000180010df4) */
/* WARNING: Removing unreachable block (ram,0x000180010ef7) */
/* WARNING: Removing unreachable block (ram,0x000180010ebf) */
/* WARNING: Removing unreachable block (ram,0x000180010e8b) */
/* WARNING: Removing unreachable block (ram,0x000180010e36) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_180010db0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined *param_4)

{
  longlong lVar1;
  uint *puVar2;
  uint uVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  ushort uStack_2e;
  
  if (DAT_18002137c == 0) {
    FUN_180010a10(param_1,param_2);
  }
  if (DAT_180021370 == 0) {
    lVar1 = cpuid_basic_info(0);
    uVar6 = 0;
    if (((*(int *)(lVar1 + 4) == 0x68747541) && (*(int *)(lVar1 + 8) == 0x69746e65)) &&
       (*(int *)(lVar1 + 0xc) == 0x444d4163)) {
      lVar1 = cpuid_Version_info(1);
      uVar6 = *(uint *)(lVar1 + 8) >> 0x17 & 1;
      puVar2 = (uint *)cpuid(0x80000000);
      if (0x80000005 < *puVar2) {
        lVar1 = cpuid(0x80000006);
        uStack_2e = (ushort)((uint)*(undefined4 *)(lVar1 + 0xc) >> 0x10);
        DAT_18001e870 = (ulonglong)uStack_2e << 10;
        DAT_18001e878 = (ulonglong)uStack_2e << 9;
        DAT_18001e890 = DAT_18001e880 >> 2;
      }
    }
  }
  else {
    if (DAT_180021374 == 0) {
      uVar6 = 0;
    }
    else {
      lVar1 = cpuid_Version_info(1);
      uVar6 = 2;
      if ((*(uint *)(lVar1 + 8) >> 0x1a & 1) == 0) {
        uVar6 = *(uint *)(lVar1 + 8) >> 0x17 & 1;
      }
    }
    if (DAT_180021380 == 0) {
      pcVar4 = getenv("__INTEL_LIBIRC_DEBUG");
      if ((pcVar4 != (char *)0x0) && (*pcVar4 != '\0')) {
        FUN_180011280(1,0,0,param_4);
        FUN_180011280(1,0x3d,0,param_4);
        FUN_180011280(1,0,0,param_4);
                    /* WARNING: Subroutine does not return */
        exit(1);
      }
    }
    else {
      uVar5 = DAT_180021390;
      if (DAT_180021390 < DAT_180021380) {
        uVar5 = DAT_180021380;
      }
      uVar7 = DAT_180021388 * DAT_180021384;
      if (DAT_180021380 < DAT_180021390) {
        uVar7 = DAT_180021398 * DAT_180021394;
      }
      uVar3 = DAT_1800213a8 * DAT_1800213a4;
      if (DAT_1800213a0 <= uVar5) {
        uVar3 = uVar7;
      }
      _DAT_1800213b8 = (ulonglong)uVar3;
      if (uVar5 <= DAT_1800213a0) {
        uVar5 = DAT_1800213a0;
      }
      DAT_18001e870 = (ulonglong)uVar5 << 10;
      DAT_18001e878 = (ulonglong)uVar5 << 9;
      DAT_18001e880 = (ulonglong)(DAT_180021380 << 10);
      DAT_18001e888 = (ulonglong)((DAT_180021380 & 0x3fffff) << 9);
      DAT_18001e890 = (ulonglong)((DAT_180021380 & 0x3fffff) << 8);
      _DAT_18001e898 = 0x2000;
      _DAT_18001e8a0 = DAT_18001e880 * 6;
      _DAT_18001e8a8 = 0x800;
    }
  }
  DAT_1800213b0 = uVar6;
  _DAT_1800213c0 = uVar6;
  return;
}

/* RVA 0x11070, FUN_180011070 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined * FUN_180011070(int param_1,int param_2,undefined8 param_3,undefined8 param_4)

{
  undefined *puVar1;
  ulonglong *puVar2;
  undefined8 local_res18;
  undefined8 local_res20;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  undefined8 *local_30;
  undefined8 *local_20;
  ulonglong local_18;
  
  local_18 = DAT_18001e800 ^ (ulonglong)auStack_58;
  local_res18 = param_3;
  local_res20 = param_4;
  puVar1 = FUN_180011100(param_1);
  if (0 < param_2) {
    local_20 = &local_res18;
    puVar2 = (ulonglong *)FUN_180011ff0();
    local_38 = 0;
    local_30 = &local_res18;
    __stdio_common_vsprintf(*puVar2 | 2,&DAT_1800213d0,0x200,puVar1);
    puVar1 = &DAT_1800213d0;
  }
  return puVar1;
}

/* RVA 0x11100, FUN_180011100 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined * FUN_180011100(int param_1)

{
  char *_Source;
  LCID LVar1;
  DWORD DVar2;
  size_t sVar3;
  undefined1 *puVar4;
  undefined *puVar5;
  undefined1 auStackY_d8 [32];
  char *local_98 [16];
  ulonglong local_18;
  
  local_18 = DAT_18001e800 ^ (ulonglong)auStackY_d8;
  if (param_1 == 0) {
    puVar5 = &DAT_180018a1b;
  }
  else {
    if (DAT_1800217d8 == '\0') {
      DAT_1800217d8 = '\x01';
      LVar1 = GetThreadLocale();
      FUN_180014c70(local_98,"%lu/%s",(ulonglong)LVar1,"irc_msg.dll");
      DAT_1800217e0 = LoadLibraryExA((LPCSTR)local_98,(HANDLE)0x0,0);
      if (DAT_1800217e0 != (HMODULE)0x0) {
        DAT_1800217dc = '\x01';
      }
    }
    puVar5 = (&PTR_DAT_180018a28)[(longlong)param_1 * 2];
    if (DAT_1800217dc == '\x01') {
      DVar2 = FormatMessageA(0x900,DAT_1800217e0,param_1 + 0x80000000,0x409,(LPSTR)local_98,0x200,
                             (va_list *)0x0);
      _Source = local_98[0];
      if (DVar2 != 0) {
        sVar3 = strlen(local_98[0]);
        if (((sVar3 < 2) || (_Source[sVar3 - 2] != '\r')) || (_Source[sVar3 - 1] != '\n')) {
          strncpy(&DAT_1800217f0,_Source,0x200);
          puVar4 = &DAT_1800219ef;
        }
        else {
          strncpy(&DAT_1800217f0,_Source,sVar3 - 2);
          puVar4 = &DAT_1800217ee + sVar3;
        }
        *puVar4 = 0;
        LocalFree(local_98[0]);
        puVar5 = &DAT_1800217f0;
      }
    }
  }
  return puVar5;
}

/* RVA 0x11280, FUN_180011280 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180011280(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined *param_4)

{
  undefined *puVar1;
  ulonglong *puVar2;
  undefined8 uVar3;
  undefined *local_res20;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  undefined **local_30;
  undefined **local_20;
  ulonglong local_18;
  
  local_18 = DAT_18001e800 ^ (ulonglong)auStack_58;
  local_res20 = param_4;
  if ((int)param_2 == 0) {
    FUN_180014cd0(&DAT_180018a15,param_2,param_3,param_4);
  }
  else {
    uVar3 = param_3;
    puVar1 = FUN_180011100((int)param_2);
    if (0 < (int)param_3) {
      local_20 = &local_res20;
      puVar2 = (ulonglong *)FUN_180011ff0();
      local_38 = 0;
      uVar3 = 0x200;
      param_4 = puVar1;
      local_30 = &local_res20;
      __stdio_common_vsprintf(*puVar2 | 2,&DAT_1800215d0);
      puVar1 = &DAT_1800215d0;
    }
    FUN_180014cd0(&DAT_180018a17,puVar1,uVar3,param_4);
  }
  return;
}

/* RVA 0x11320, PPEXEC_APCLOSE_C */
void PPEXEC_APCLOSE_C(longlong param_1,longlong param_2)

{
  longlong local_res8;
  longlong local_res10 [3];
  
                    /* 0x11320  1  PPEXEC_APCLOSE_C */
  local_res8 = param_2;
  local_res10[0] = param_1;
  PPEXEC_APCLOSE(local_res10,&local_res8);
  return;
}

/* RVA 0x11342, DMS_RTLAYL */
void DMS_RTLAYL(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180011342. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DMS_RTLAYL();
  return;
}

/* RVA 0x11348, LM_RETURN_APROP_LICENSE */
void LM_RETURN_APROP_LICENSE(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180011348. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LM_RETURN_APROP_LICENSE();
  return;
}

/* RVA 0x1134e, DMS_ASPENC */
void DMS_ASPENC(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018001134e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DMS_ASPENC();
  return;
}

/* RVA 0x11354, DMS_LOCATI */
void DMS_LOCATI(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180011354. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DMS_LOCATI();
  return;
}

/* RVA 0x1138a, DMS_ILOAD */
void DMS_ILOAD(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018001138a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DMS_ILOAD();
  return;
}

/* RVA 0x11390, DMS_ICKFPE */
void DMS_ICKFPE(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180011390. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DMS_ICKFPE();
  return;
}

/* RVA 0x113a8, DMS_IRRCHK */
void DMS_IRRCHK(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800113a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DMS_IRRCHK();
  return;
}

/* RVA 0x113b4, DMS_ERRPRT */
void DMS_ERRPRT(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800113b4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DMS_ERRPRT();
  return;
}

/* RVA 0x113ba, DMS_DOCALL */
void DMS_DOCALL(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800113ba. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DMS_DOCALL();
  return;
}

/* RVA 0x113c0, DMS_APCWRK */
void DMS_APCWRK(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800113c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DMS_APCWRK();
  return;
}

/* RVA 0x113c6, DMS_PHCWRK */
void DMS_PHCWRK(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800113c6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DMS_PHCWRK();
  return;
}

/* RVA 0x113d8, DMS_LOCATM */
void DMS_LOCATM(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800113d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DMS_LOCATM();
  return;
}

