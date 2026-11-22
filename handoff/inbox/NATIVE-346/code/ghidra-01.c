/* RVA 0x1000, PPEXEC_APLOAD */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PPEXEC_APLOAD(void)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  bool bVar4;
  code *pcVar5;
  code *pcVar6;
  code *pcVar7;
  code *pcVar8;
  code *pcVar9;
  code *pcVar10;
  longlong lVar11;
  longlong lVar12;
  longlong lVar13;
  
                    /* 0x1000  6  PPEXEC_APLOAD */
  lVar11 = DMS_LOCATI(&DAT_180015d80);
  pcVar9 = DMS_ERRTWO_exref;
  DAT_18001e8f8 = *(undefined8 *)(DMS_ERRTWO_exref + 0x58);
  DAT_18001e970 = lVar11;
  *(undefined8 *)(DMS_ERRTWO_exref + 0x58) = 2;
  *(undefined8 *)PPBASE_PPFLAG_exref = 0;
  pcVar8 = DMS_PLEX_exref;
  _DAT_18001e968 = *(undefined8 *)(DMS_PLEX_exref + lVar11 * 8 + 0x118);
  lVar11 = DMS_LOCATI(&DAT_18001e968);
  pcVar6 = DMS_NCOMP_exref;
  uVar2 = *(undefined8 *)(pcVar8 + lVar11 * 8 + -8);
  *(undefined8 *)DMS_NCOMP_exref = uVar2;
  uVar3 = *(undefined8 *)(pcVar8 + lVar11 * 8 + 8);
  *(undefined8 *)(pcVar6 + 8) = *(undefined8 *)(pcVar8 + lVar11 * 8);
  *(undefined8 *)(pcVar6 + 0x10) = uVar3;
  uVar3 = *(undefined8 *)(pcVar8 + lVar11 * 8 + 0x10 + 8);
  *(undefined8 *)(pcVar6 + 0x18) = *(undefined8 *)(pcVar8 + lVar11 * 8 + 0x10);
  *(undefined8 *)(pcVar6 + 0x20) = uVar3;
  uVar3 = *(undefined8 *)(pcVar8 + lVar11 * 8 + 0x20 + 8);
  *(undefined8 *)(pcVar6 + 0x28) = *(undefined8 *)(pcVar8 + lVar11 * 8 + 0x20);
  *(undefined8 *)(pcVar6 + 0x30) = uVar3;
  uVar3 = *(undefined8 *)(pcVar8 + lVar11 * 8 + 0x30 + 8);
  *(undefined8 *)(pcVar6 + 0x38) = *(undefined8 *)(pcVar8 + lVar11 * 8 + 0x30);
  *(undefined8 *)(pcVar6 + 0x40) = uVar3;
  uVar3 = *(undefined8 *)(pcVar8 + lVar11 * 8 + 0x40 + 8);
  *(undefined8 *)(pcVar6 + 0x48) = *(undefined8 *)(pcVar8 + lVar11 * 8 + 0x40);
  *(undefined8 *)(pcVar6 + 0x50) = uVar3;
  uVar3 = *(undefined8 *)(pcVar8 + lVar11 * 8 + 0x50 + 8);
  *(undefined8 *)(pcVar6 + 0x58) = *(undefined8 *)(pcVar8 + lVar11 * 8 + 0x50);
  *(undefined8 *)(pcVar6 + 0x60) = uVar3;
  uVar3 = *(undefined8 *)(pcVar8 + lVar11 * 8 + 0x60 + 8);
  *(undefined8 *)(pcVar6 + 0x68) = *(undefined8 *)(pcVar8 + lVar11 * 8 + 0x60);
  *(undefined8 *)(pcVar6 + 0x70) = uVar3;
  *(undefined8 *)(pcVar6 + 0x78) = *(undefined8 *)(pcVar8 + lVar11 * 8 + 0x70);
  uVar3 = *(undefined8 *)(pcVar8 + lVar11 * 8 + 0xa8 + 8);
  *(undefined8 *)(pcVar6 + 0xb0) = *(undefined8 *)(pcVar8 + lVar11 * 8 + 0xa8);
  *(undefined8 *)(pcVar6 + 0xb8) = uVar3;
  pcVar10 = PPBASE_IREFGL_exref;
  *(undefined8 *)(PPBASE_IREFGL_exref + 0x10) = 0;
  *(undefined8 *)(pcVar10 + 0x18) = 0;
  *(undefined8 *)pcVar10 = 0;
  *(undefined8 *)(pcVar10 + 8) = 0;
  *(undefined8 *)(pcVar10 + 0x20) = 0;
  pcVar7 = DMS_RGLOB_exref;
  pcVar5 = DMS_PPRIV_exref;
  uVar3 = *(undefined8 *)(DMS_RGLOB_exref + 8);
  *(undefined8 *)DMS_PPRIV_exref = *(undefined8 *)DMS_RGLOB_exref;
  *(undefined8 *)(pcVar5 + 8) = uVar3;
  *(undefined8 *)(pcVar5 + 0x10) = *(undefined8 *)(pcVar7 + 0x20);
  pcVar6 = DMS_GLOBAL_exref;
  uVar3 = *(undefined8 *)(DMS_GLOBAL_exref + 0x20);
  *(undefined8 *)(pcVar5 + 0x38) = *(undefined8 *)(DMS_GLOBAL_exref + 0x38);
  *(undefined8 *)(pcVar5 + 0x40) = uVar3;
  *(undefined8 *)(pcVar5 + 0x48) = uVar2;
  _DAT_18001e900 = *(undefined8 *)(pcVar8 + DAT_18001e970 * 8 + 0x630);
  lVar11 = DMS_LOCATI(&DAT_18001e900);
  *(undefined8 *)(pcVar5 + 0x4ee8) = *(undefined8 *)(pcVar8 + lVar11 * 8 + 0x2e0);
  FUN_180002b80();
  SHS_FIPOLM(&DAT_18001e908);
  if (0 < DAT_18001e908) {
    *(undefined8 *)(pcVar10 + 0x20) = 1;
  }
  PPEXEC_LDCMPTYP();
  lVar13 = DAT_18001e970;
  pcVar5 = PPMON_PPCKWK_exref;
  lVar11 = *(longlong *)(pcVar8 + DAT_18001e970 * 8 + 0x368);
  lVar12 = *(longlong *)(pcVar8 + DAT_18001e970 * 8 + 0x370);
  *(longlong *)PPMON_PPCKWK_exref = lVar11;
  *(longlong *)(pcVar5 + 8) = lVar12;
  pcVar5 = DMS_IPOFF9_exref;
  *(undefined8 *)(pcVar8 + (lVar11 + *(longlong *)(DMS_IPOFF9_exref + 8)) * 8 + -8) =
       *(undefined8 *)pcVar7;
  *(undefined8 *)(pcVar8 + (lVar12 + *(longlong *)pcVar5) * 8 + -8) = *(undefined8 *)(pcVar6 + 0x38)
  ;
  _DAT_18001e960 = *(undefined8 *)(pcVar8 + lVar13 * 8 + 0x130);
  DMS_ILOAD(DMS_PPCTBL_exref,&DAT_18001e960,&DAT_180015d88,&DAT_180015d90);
  _DAT_18001e958 = *(longlong *)(pcVar8 + DAT_18001e970 * 8 + 0x3c8);
  if (_DAT_18001e958 != 0) {
    lVar11 = DMS_LOCATI(&DAT_18001e958);
    if (*(longlong *)(pcVar8 + lVar11 * 8 + -8) == 1) {
      _DAT_18001e950 = *(undefined8 *)(pcVar8 + lVar11 * 8 + 8);
      PPTB_TPUNPK(&DAT_18001e950);
      PPTBI_HIGTB(&DAT_180015d98);
    }
  }
  _DAT_18001e948 = *(longlong *)(pcVar8 + DAT_18001e970 * 8 + 0x508);
  if (_DAT_18001e948 != 0) {
    lVar11 = DMS_LOCATI(&DAT_18001e948);
    if (*(longlong *)(pcVar8 + lVar11 * 8 + 0x20) == 0x457) {
      PPTH_SLXIN0(&DAT_180015d98);
    }
  }
  FUN_180005bd0();
  *(undefined8 *)(pcVar9 + 0x58) = 0x1d;
  _DAT_18001e940 = *(undefined8 *)(pcVar8 + DAT_18001e970 * 8 + 0xb0);
  lVar12 = DMS_LOCATI(&DAT_18001e940);
  lVar11 = *(longlong *)(pcVar8 + lVar12 * 8 + -8);
  DAT_18001e930 = 1;
  DAT_18001e910 = lVar11;
  DAT_18001e938 = lVar12;
  if (0 < lVar11) {
    lVar13 = lVar11;
    do {
      if (*(longlong *)(pcVar8 + (lVar13 * 3 + lVar12 + DAT_18001e930) * 8 + -8) == 1) {
        lVar12 = DAT_18001e930 * 3 + lVar12;
        _DAT_18001e928 = *(undefined8 *)(pcVar8 + lVar12 * 8 + -8);
        _DAT_18001e920 = *(undefined8 *)(pcVar8 + lVar12 * 8 + -0x18);
        _DAT_18001e918 = *(undefined8 *)(pcVar8 + lVar12 * 8 + -0x10);
        PPEXEC_PHCCIN((longlong *)&DAT_18001e920,(longlong *)&DAT_18001e918,&DAT_18001e928);
        lVar12 = DAT_18001e938;
        lVar13 = DAT_18001e910;
      }
      lVar1 = DAT_18001e930 + 1;
      bVar4 = DAT_18001e930 < lVar11;
      DAT_18001e930 = lVar1;
    } while (bVar4);
  }
  DMS_ICKFPE();
  _DAT_18001e8e0 = 0;
  uRam000000018001e8e8 = 0;
  _DAT_18001e8d0 = 0;
  uRam000000018001e8d8 = 0;
  _PPEXEC_REINIT = 0;
  uRam000000018001e8c8 = 0;
  _DAT_18001e8f0 = 0;
  *(undefined8 *)(pcVar9 + 0x58) = DAT_18001e8f8;
  UMOD_PPCHKU();
  return;
}

/* RVA 0x13d0, PPEXEC_LDSTW */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PPEXEC_LDSTW(void)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  code *pcVar8;
  code *pcVar9;
  longlong lVar10;
  longlong lVar11;
  
                    /* 0x13d0  18  PPEXEC_LDSTW */
  lVar10 = DMS_LOCATI(&DAT_180015da0);
  pcVar8 = DMS_PLEX_exref;
  _DAT_18001e978 = *(longlong *)(DMS_PLEX_exref + lVar10 * 8 + 0x1c0);
  if (_DAT_18001e978 != 0) {
    lVar10 = DMS_LOCATI(&DAT_18001e978);
    pcVar9 = SHS_STWORK_exref;
    FUN_180008d20();
    lVar11 = 0;
    do {
      *(undefined8 *)(pcVar9 + lVar11 * 8 + 0x210) =
           *(undefined8 *)(pcVar8 + lVar11 * 8 + lVar10 * 8 + 0x168);
      lVar11 = lVar11 + 1;
    } while (lVar11 != 8);
    lVar11 = 0;
    do {
      *(undefined8 *)(pcVar9 + lVar11 * 8 + 0x268) =
           *(undefined8 *)(pcVar8 + lVar11 * 8 + lVar10 * 8 + 0x1a8);
      lVar11 = lVar11 + 1;
    } while (lVar11 != 4);
    lVar11 = 0;
    do {
      *(undefined8 *)(pcVar9 + lVar11 * 8 + 0x2a8) =
           *(undefined8 *)(pcVar8 + lVar11 * 8 + lVar10 * 8 + 0x1c8);
      lVar11 = lVar11 + 1;
    } while (lVar11 != 2);
    *(undefined8 *)(pcVar9 + 0x348) = *(undefined8 *)(pcVar8 + lVar10 * 8 + 0x248);
    uVar1 = *(undefined8 *)(pcVar8 + lVar10 * 8 + 0x238 + 8);
    *(undefined8 *)(pcVar9 + 0x338) = *(undefined8 *)(pcVar8 + lVar10 * 8 + 0x238);
    *(undefined8 *)(pcVar9 + 0x340) = uVar1;
    uVar1 = *(undefined8 *)(pcVar8 + lVar10 * 8 + 0x228 + 8);
    *(undefined8 *)(pcVar9 + 0x328) = *(undefined8 *)(pcVar8 + lVar10 * 8 + 0x228);
    *(undefined8 *)(pcVar9 + 0x330) = uVar1;
    uVar1 = *(undefined8 *)(pcVar8 + lVar10 * 8 + 0x218 + 8);
    *(undefined8 *)(pcVar9 + 0x318) = *(undefined8 *)(pcVar8 + lVar10 * 8 + 0x218);
    *(undefined8 *)(pcVar9 + 800) = uVar1;
    uVar1 = *(undefined8 *)(pcVar8 + lVar10 * 8 + 0x1d8);
    uVar2 = *(undefined8 *)(pcVar8 + lVar10 * 8 + 0x1d8 + 8);
    uVar3 = *(undefined8 *)(pcVar8 + lVar10 * 8 + 0x1e8);
    uVar4 = *(undefined8 *)(pcVar8 + lVar10 * 8 + 0x1e8 + 8);
    uVar5 = *(undefined8 *)(pcVar8 + lVar10 * 8 + 0x1f8);
    uVar6 = *(undefined8 *)(pcVar8 + lVar10 * 8 + 0x1f8 + 8);
    uVar7 = *(undefined8 *)(pcVar8 + lVar10 * 8 + 0x208 + 8);
    *(undefined8 *)(pcVar9 + 0x308) = *(undefined8 *)(pcVar8 + lVar10 * 8 + 0x208);
    *(undefined8 *)(pcVar9 + 0x310) = uVar7;
    *(undefined8 *)(pcVar9 + 0x2f8) = uVar5;
    *(undefined8 *)(pcVar9 + 0x300) = uVar6;
    *(undefined8 *)(pcVar9 + 0x2e8) = uVar3;
    *(undefined8 *)(pcVar9 + 0x2f0) = uVar4;
    *(undefined8 *)(pcVar9 + 0x2d8) = uVar1;
    *(undefined8 *)(pcVar9 + 0x2e0) = uVar2;
  }
  *(undefined8 *)(DMS_STWKWK_exref + 0x30) = 1;
  FUN_180002c10();
  return;
}

/* RVA 0x1560, PPEXEC_PHCCIN */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PPEXEC_PHCCIN(longlong *param_1,longlong *param_2,undefined8 param_3)

{
  code *pcVar1;
  longlong lVar2;
  ulonglong uVar3;
  code *pcVar4;
  longlong *plVar5;
  undefined4 local_16e;
  undefined4 local_16a;
  undefined4 local_166;
  undefined2 local_162;
  longlong local_160;
  longlong local_158;
  longlong local_150;
  longlong local_148;
  longlong local_140;
  longlong local_138;
  longlong local_130;
  longlong local_128;
  longlong local_120;
  longlong local_118;
  longlong local_110;
  longlong local_108;
  longlong local_100;
  longlong local_f8;
  longlong local_f0;
  longlong local_e8;
  longlong local_e0;
  longlong local_d8;
  longlong local_d0;
  longlong local_c8;
  longlong local_c0;
  longlong local_b8;
  longlong local_b0 [2];
  code *local_a0;
  undefined8 local_98;
  undefined8 local_90;
  code *local_88;
  undefined8 local_80;
  longlong local_78;
  undefined8 local_70 [6];
  
                    /* 0x1560  23  PPEXEC_PHCCIN */
  pcVar4 = DMS_IPOFF1_exref;
  DAT_18001ebc0 = *(longlong *)(DMS_IPOFF4_exref + 8);
  lVar2 = *(longlong *)(DMS_IPOFF1_exref + 0x988);
  local_108 = *(longlong *)(DMS_IPOFF1_exref + 0x10c0);
  local_b8 = *(longlong *)(DMS_IPOFF1_exref + 0x10c8);
  local_c0 = *(longlong *)(DMS_IPOFF1_exref + 0x10d0);
  local_118 = *(longlong *)(DMS_IPOFF1_exref + 0x1b0);
  local_110 = *(longlong *)(DMS_IPOFF1_exref + 0x218);
  local_128 = *(longlong *)(DMS_IPOFF1_exref + 0x10e0);
  local_120 = *(longlong *)(DMS_IPOFF1_exref + 0x10e8);
  local_c8 = *(longlong *)(DMS_IPOFF1_exref + 0x10f0);
  local_d8 = *(longlong *)(DMS_IPOFF1_exref + 0x10f8);
  local_f0 = *(longlong *)(DMS_IPOFF1_exref + 0x1560);
  local_140 = *(longlong *)(DMS_IPOFF1_exref + 0x11e8);
  local_138 = *(longlong *)(DMS_IPOFF1_exref + 0x11f0);
  local_130 = *(longlong *)(DMS_IPOFF1_exref + 0x11f8);
  local_e0 = *(longlong *)(DMS_IPOFF1_exref + 0x1200);
  local_e8 = *(longlong *)(DMS_IPOFF1_exref + 0x1208);
  local_d0 = *(longlong *)(DMS_IPOFF1_exref + 0x1290);
  local_f8 = *(longlong *)(DMS_IPOFF1_exref + 0x1298);
  local_100 = *(longlong *)(DMS_IPOFF1_exref + 0x12a0);
  local_160 = *(longlong *)(DMS_IPOFF1_exref + 0x12a8);
  local_158 = *(longlong *)(DMS_IPOFF1_exref + 0x12b0);
  local_148 = *(longlong *)(DMS_IPOFF1_exref + 0x12b8);
  local_150 = *(longlong *)(DMS_IPOFF1_exref + 0x12c8);
  if ((*param_1 == 0x2020202032305345) && (*param_2 == 0x2020202020202020)) {
switchD_1800017a5_default:
    PPESI_ES02(param_3);
  }
  else {
    plVar5 = &DAT_1800160b8;
    uVar3 = 0;
    do {
      if ((*param_1 == plVar5[-1]) && (*param_2 == *plVar5)) {
        switch(uVar3 & 0xffffffff) {
        case 0:
          PPTHI_PS003(param_3);
          return;
        case 1:
          PPESI_ES19(param_3);
          return;
        case 2:
          PPESI_ES13(param_3);
          return;
        case 3:
          PPESI_ES04(param_3);
          return;
        case 4:
          PPESI_ES06(param_3);
          return;
        case 5:
          PPESI_ES14(param_3);
          return;
        case 6:
          PPESI_ES141(param_3);
          return;
        case 7:
          PPESI_ES11(param_3);
          return;
        case 8:
          PPGMI_GM02(param_3);
          return;
        case 9:
          PPGMI_GM041(param_3);
          return;
        case 10:
          PPGMI_GM15(param_3);
          return;
        case 0xb:
          PPGMI_GM07(param_3);
          return;
        case 0xc:
          PPTHI_DHL302(param_3);
          return;
        case 0xd:
          PPTHI_VL006(param_3);
          return;
        case 0xe:
          PPSTUB_VL203(param_3);
          return;
        case 0xf:
          PPTHI_VPM03(param_3);
          return;
        case 0x10:
          PPTHI_PHL004(param_3);
          return;
        case 0x11:
          PPESI_ES17(param_3);
          return;
        case 0x12:
          PPSTUB_VAQ003(param_3);
          return;
        case 0x13:
          PPTBI_HVTB(param_3);
          return;
        case 0x14:
          PPTBI_DHVTB(param_3);
          return;
        case 0x15:
          PPTBI_HLTB(param_3);
          return;
        case 0x16:
          PPTBI_DHVLTB(param_3);
          return;
        case 0x17:
          PPTBI_DHLTB(param_3);
          return;
        case 0x18:
          PPTBI_HSTB(param_3);
          return;
        case 0x19:
          PPTBI_DHSTB(param_3);
          return;
        case 0x1a:
          PPTBI_DHLSTB(param_3);
          return;
        case 0x1b:
          PPTBI_DHVSTB(param_3);
          return;
        case 0x1c:
          PPTBI_SVTB(param_3);
          return;
        case 0x1d:
          PPTBI_DSVTB(param_3);
          return;
        case 0x1e:
          PPTBI_SLTB(param_3);
          return;
        case 0x1f:
          PPTBI_DSLTB(param_3);
          return;
        case 0x20:
          PPTBI_SSTB(param_3);
          return;
        case 0x21:
          PPTBI_DSSTB(param_3);
          return;
        case 0x22:
          PPTBI_GVTB(param_3);
          return;
        case 0x23:
          PPTBI_DGVTB(param_3);
          return;
        case 0x24:
          PPTBI_GLTB(param_3);
          return;
        case 0x25:
          PPTBI_DGLTB(param_3);
          return;
        case 0x26:
          PPTBI_GSTB(param_3);
          return;
        case 0x27:
          PPTBI_DGSTB(param_3);
          return;
        case 0x28:
          PPTBI_PHVTB(param_3);
          return;
        case 0x29:
          PPTBI_PHLTB(param_3);
          return;
        case 0x2a:
          PPTBI_PHSTB(param_3);
          return;
        case 0x2b:
          PPTBI_PLTB(param_3);
          return;
        case 0x2c:
          PPTBI_PSTB(param_3);
          return;
        case 0x2d:
          PPTBI_VVTB(param_3);
          return;
        case 0x2e:
          PPTBI_VLTB(param_3);
          return;
        case 0x2f:
          PPTBI_VSTB(param_3);
          return;
        case 0x30:
          PPTBI_MUVTB(param_3);
          return;
        case 0x31:
          PPTBI_MULTB(param_3);
          return;
        case 0x32:
          PPTBI_HNRYTB(param_3);
          return;
        case 0x33:
          PPTBI_KVLTB(param_3);
          return;
        case 0x34:
          PPTBI_KLLTB(param_3);
          return;
        case 0x35:
          PPTBI_PHVMTB(param_3);
          return;
        case 0x36:
          PPTBI_PHLMTB(param_3);
          return;
        case 0x37:
          PPBASE_WATS01(param_3);
          return;
        case 0x38:
          PPBASE_GM11(param_3);
          return;
        case 0x39:
          PPESI_ES04A(param_3);
          return;
        case 0x3a:
          PPESI_ES06A(param_3);
          return;
        case 0x3b:
          PPESI_ES11A(param_3);
          return;
        case 0x3c:
          PPESI_ES02A(param_3);
          return;
        case 0x3d:
          PPSTUB_GM18(param_3);
          return;
        case 0x3e:
          PPSTUB_GM18A(param_3);
          return;
        case 0x3f:
          PPESI_ES30(param_3);
          return;
        case 0x40:
          PPESI_ES30A(param_3);
          return;
        case 0x41:
          PPESI_ES21(param_3);
          return;
        case 0x42:
          PPESI_ES21A(param_3);
          return;
        case 0x43:
          PPUTL_PPFUNC(s_KVLU_I_18001e000,&DAT_18001ebd0);
          pcVar4 = DMS_GLOBAL_exref + 0x38;
          DMS_DOCALL(&DAT_18001ebd0,param_3,pcVar4,pcVar4,pcVar4,pcVar4,pcVar4,pcVar4,pcVar4,pcVar4,
                     pcVar4,pcVar4,pcVar4,pcVar4,pcVar4,pcVar4,pcVar4,pcVar4,pcVar4,pcVar4,pcVar4,
                     pcVar4,pcVar4,pcVar4,pcVar4,pcVar4,pcVar4,pcVar4,pcVar4,pcVar4,pcVar4,pcVar4,
                     pcVar4,pcVar4,pcVar4,pcVar4,pcVar4,pcVar4,pcVar4,pcVar4,pcVar4,pcVar4,pcVar4,
                     pcVar4,pcVar4,pcVar4,pcVar4,pcVar4,pcVar4,pcVar4,pcVar4,pcVar4,pcVar4,pcVar4,
                     pcVar4,pcVar4,pcVar4,pcVar4,pcVar4,pcVar4,pcVar4,pcVar4,pcVar4,pcVar4,pcVar4,
                     pcVar4);
          return;
        case 0x44:
          PPESI_ES19A(param_3);
          return;
        case 0x45:
          PPESI_ES13A(param_3);
          return;
        case 0x46:
          PPTHI_HL002(param_3);
          return;
        case 0x47:
          PPESI_ES32(param_3);
          return;
        case 0x48:
          PPESI_ES32A(param_3);
          return;
        case 0x49:
          PPBASE_MUVL02(param_3);
          return;
        case 0x4a:
          PPTXI_MUVLW1(param_3);
          return;
        case 0x4b:
          PPTXI_MUVLW2(param_3);
          return;
        case 0x4c:
          PPTXI_KVLW1(param_3);
          return;
        case 0x4d:
          PPTXI_MUVL05(param_3);
          return;
        case 0x4e:
          PPTXI_MUV006(param_3);
          return;
        case 0x4f:
          PPSTUB_GMSA81(param_3);
          return;
        case 0x50:
          PPSTUB_GM081(param_3);
          return;
        case 0x51:
          PPGMI_GM20I(param_3);
          return;
        case 0x52:
          PPSTUB_BK10IN(param_3);
          return;
        case 0x53:
          PPGMI_GM23I(param_3);
          return;
        case 0x54:
          PPGMI_GM13L(param_3);
          return;
        case 0x55:
          PPGMI_GM13G(param_3);
          return;
        case 0x56:
          PPESI_ES35I(param_3);
          return;
        case 0x57:
          PPESI_ES36I(param_3);
          return;
        case 0x58:
          PPGMI_GM11PS(param_3);
          return;
        case 0x59:
          PPESI_ES35VI(param_3);
          return;
        case 0x5a:
          PPESI_ES36VI(param_3);
          return;
        case 0x5b:
          PPESI_ES04S(param_3);
          return;
        case 0x5c:
          PPESI_ES06S(param_3);
          return;
        case 0x5d:
          PPESI_ES04SA(param_3);
          return;
        case 0x5e:
          PPESI_ES06SA(param_3);
          return;
        case 0x5f:
          PPSTUB_GM081E(param_3);
          return;
        case 0x60:
          return;
        case 0x61:
          PPSTUB_VLP01I(DMS_PLEX_exref + lVar2 * 8,DMS_PLEX_exref + local_160 * 8,
                        DMS_PLEX_exref + local_158 * 8,DMS_PLEX_exref + local_148 * 8,
                        DMS_PLEX_exref + local_140 * 8,DMS_PLEX_exref + local_138 * 8,
                        DMS_PLEX_exref + local_130 * 8,DMS_PLEX_exref + local_108 * 8,
                        DMS_PLEX_exref + DAT_18001ebc0 * 8);
          return;
        case 0x62:
          PPSTUB_HLP01I(DMS_PLEX_exref + lVar2 * 8,DMS_PLEX_exref + local_150 * 8,
                        DMS_PLEX_exref + *(longlong *)(DMS_IPOFF1_exref + 0x12d0) * 8,
                        DMS_PLEX_exref + *(longlong *)(DMS_IPOFF1_exref + 0x12d8) * 8,
                        DMS_PLEX_exref + *(longlong *)(DMS_IPOFF1_exref + 0x15a8) * 8,
                        DMS_PLEX_exref + local_e0 * 8,DMS_PLEX_exref + local_e8 * 8,
                        DMS_PLEX_exref + local_110 * 8,DMS_PLEX_exref + DAT_18001ebc0 * 8);
          return;
        case 99:
          PPSTUB_TM001I(DMS_PLEX_exref + local_d8 * 8,DMS_PLEX_exref + DAT_18001ebc0 * 8);
          return;
        case 100:
          PPSTUB_TG001I(DMS_PLEX_exref + local_c8 * 8,DMS_PLEX_exref + DAT_18001ebc0 * 8);
          return;
        case 0x65:
          PPSTUB_CPP01I(DMS_PLEX_exref + lVar2 * 8,DMS_PLEX_exref + local_f8 * 8,
                        DMS_PLEX_exref + local_100 * 8,DMS_PLEX_exref + local_c0 * 8,
                        DMS_PLEX_exref + local_b8 * 8,DMS_PLEX_exref + DAT_18001ebc0 * 8);
          return;
        case 0x66:
          PPSTUB_VLP02I(DMS_PLEX_exref + lVar2 * 8,DMS_PLEX_exref + local_160 * 8,
                        DMS_PLEX_exref + local_158 * 8,DMS_PLEX_exref + local_148 * 8,
                        DMS_PLEX_exref + local_140 * 8,DMS_PLEX_exref + local_138 * 8,
                        DMS_PLEX_exref + local_130 * 8,DMS_PLEX_exref + local_108 * 8,
                        DMS_PLEX_exref + local_d0 * 8,DMS_PLEX_exref + DAT_18001ebc0 * 8);
          return;
        case 0x67:
          PPSTUB_GLP01I(DMS_PLEX_exref + lVar2 * 8,
                        DMS_PLEX_exref + *(longlong *)(DMS_IPOFF1_exref + 0x12e0) * 8,
                        DMS_PLEX_exref + *(longlong *)(DMS_IPOFF1_exref + 0x12e8) * 8,
                        DMS_PLEX_exref + *(longlong *)(DMS_IPOFF1_exref + 0x12f0) * 8,
                        DMS_PLEX_exref + *(longlong *)(DMS_IPOFF1_exref + 0x15b0) * 8,
                        DMS_PLEX_exref + local_128 * 8,DMS_PLEX_exref + local_120 * 8,
                        DMS_PLEX_exref + local_118 * 8,DMS_PLEX_exref + DAT_18001ebc0 * 8);
          return;
        case 0x68:
          PPTXI_KL204I(param_3);
          return;
        case 0x69:
          PPTHI_VL208I(param_3);
          return;
        case 0x6a:
          PPTXI_MUL207(param_3);
          return;
        case 0x6b:
          PPGMI_GM03I(param_3);
          return;
        case 0x6c:
          PPTHI_HL003(param_3);
          return;
        case 0x6d:
          PPBASE_IDLINT(param_3);
          return;
        case 0x6e:
          PPSTUB_HMU01I(DMS_PLEX_exref + local_f0 * 8,DMS_PLEX_exref + DAT_18001ebc0 * 8);
          PPSTUB_MULMH0(param_3);
          return;
        case 0x6f:
          PPSTUB_ESP01I(DMS_PLEX_exref + lVar2 * 8,
                        DMS_PLEX_exref + *(longlong *)(DMS_IPOFF1_exref + 0x12e0) * 8,
                        DMS_PLEX_exref + *(longlong *)(DMS_IPOFF1_exref + 0x12e8) * 8,
                        DMS_PLEX_exref + *(longlong *)(DMS_IPOFF1_exref + 0x12f0) * 8,
                        DMS_PLEX_exref + *(longlong *)(DMS_IPOFF1_exref + 0x15b0) * 8,
                        DMS_PLEX_exref + *(longlong *)(DMS_IPOFF1_exref + 0x15a8) * 8,
                        DMS_PLEX_exref + local_150 * 8,DMS_PLEX_exref + local_128 * 8,
                        DMS_PLEX_exref + local_120 * 8,DMS_PLEX_exref + local_118 * 8,
                        DMS_PLEX_exref + DAT_18001ebc0 * 8,DMS_PLEX_exref + local_110 * 8);
          return;
        case 0x70:
          PPSTUB_FH01I(param_3);
          return;
        case 0x71:
          PPSTUB_ESSFTI(param_3);
          return;
        case 0x72:
          PPBASE_GM05I(param_3);
          return;
        case 0x73:
          PPTXI_MUL01I(param_3);
          return;
        case 0x74:
          PPTXI_MUV01I(param_3);
          return;
        case 0x75:
          PPTXI_KL002I(param_3);
          return;
        case 0x76:
          PPTXI_KV001I(param_3);
          return;
        case 0x77:
          PPTXI_SIG02I(param_3);
          return;
        case 0x78:
          PPTHI_VS001I(param_3);
          return;
        case 0x79:
          PPTHI_VL004I(param_3);
          return;
        case 0x7a:
          PPTHI_HS002I(param_3);
          return;
        case 0x7b:
          PPTHI_DHV01I(param_3);
          return;
        case 0x7c:
          PPTHI_HRFLQI(param_3);
          return;
        case 0x7d:
          PPBASE_HRFIGI(param_3);
          return;
        case 0x7e:
          PPTHI_PL001I(param_3);
          return;
        case 0x7f:
          PPESI_ESR01I(param_3);
          return;
        case 0x80:
          PPESI_ESR02I(param_3);
          return;
        case 0x81:
          PPESI_ESR03I(param_3);
          return;
        case 0x82:
          PPESI_ESR04I(param_3);
          return;
        case 0x83:
          PPESI_ESR05I(param_3);
          return;
        case 0x84:
          PPESI_ESR06I(param_3);
          return;
        case 0x85:
          PPESI_ESR07I(param_3);
          return;
        case 0x86:
          PPESI_ESR08I(param_3);
          return;
        case 0x87:
          PPESI_ES24I(param_3);
          return;
        case 0x88:
          PPESI_ES04W(param_3);
          return;
        case 0x89:
          PPESI_ES04WA(param_3);
          return;
        case 0x8a:
          PPSTUB_ESPCSI(param_3);
          return;
        case 0x8b:
          PPESI_ES4ML(param_3);
          return;
        case 0x8c:
          PPESI_ES4MLA(param_3);
          return;
        case 0x8d:
          PPTXI_MUASPI(param_3);
          return;
        case 0x8e:
          PPSTUB_ESPSLI(param_3);
          return;
        case 0x8f:
          PPSTUB_MUASP0(param_3);
          return;
        case 0x90:
          lVar2 = DMS_LOCATI(&DAT_180016bf0);
          pcVar1 = DMS_PLEX_exref;
          _DAT_18001ebb8 = *(undefined8 *)(DMS_PLEX_exref + lVar2 * 8 + 0x118);
          lVar2 = DMS_LOCATI(&DAT_18001ebb8);
          _DAT_18001ebb0 = *(undefined8 *)(pcVar1 + lVar2 * 8 + -8);
          PPSTUB_KLVKI(&DAT_18001ebb0,pcVar1 + *(longlong *)(pcVar4 + 0x2a10) * 8,
                       pcVar1 + *(longlong *)(pcVar4 + 0x2a18) * 8,
                       pcVar1 + *(longlong *)(pcVar4 + 0x2a20) * 8,pcVar1 + DAT_18001ebc0 * 8);
          return;
        case 0x91:
          PPBASE_HCS01I(param_3);
          return;
        case 0x92:
          PPGMI_CSMOSI(param_3);
          return;
        case 0x93:
          PPBASE_GM05AI(param_3);
          return;
        case 0x94:
          PPSTUB_GM05SI(param_3);
          return;
        case 0x95:
          PPSTUB_GM5ASI(param_3);
          return;
        case 0x96:
          PPSTUB_GCHEMI(param_3);
          return;
        case 0x97:
          PPSTUB_CM05SI(param_3);
          return;
        case 0x98:
          PPSTUB_HSEN0I(param_3);
          return;
        case 0x99:
          PPSTUB_EYRIN0(param_3);
          return;
        case 0x9a:
          PPESI_ES09I(param_3);
          return;
        case 0x9b:
          PPSTUB_ESPSAI(param_3);
          return;
        case 0x9c:
          PPTHI_VLQUAI(param_3);
          return;
        case 0x9d:
          PPTXI_MULQUI(param_3);
          return;
        case 0x9e:
          PPELCI_GM051E(param_3);
          return;
        case 0x9f:
          PPSTUB_GM05RK(param_3);
          return;
        case 0xa0:
          PPSTUB_GM05SR(param_3);
          return;
        case 0xa1:
          PPHYSP_GLYCOLI(param_3);
          return;
        case 0xa2:
          PPESI_HYSPRI(param_3);
          return;
        case 0xa3:
          PPESI_HYSSRKI(param_3);
          return;
        case 0xa4:
          PPHYSP_HYSPRPI(param_3);
          return;
        case 0xa5:
          PPESI_ESCPAI(param_3);
          return;
        case 0xa6:
          PPSTUB_ESPSAHI(param_3);
        case 0xa7:
          PPGMI_GM11VT(param_3);
          return;
        case 0xa8:
          PPESI_ES35VTI(param_3);
          return;
        case 0xa9:
          PPESI_ESPR78AI(param_3);
          return;
        case 0xaa:
          PPESI_ESPR78I(param_3);
          return;
        case 0xab:
          PPTHI_VL010I(param_3);
          return;
        case 0xac:
          PPEDL_ESEDLI(param_3);
          return;
        case 0xad:
          PPEDL_EDLPROPI(param_3);
          return;
        case 0xae:
          PPEDL_ESESFI(param_3);
          return;
        case 0xaf:
          PPEDL_ESELKI(param_3);
          return;
        case 0xb0:
          PPSTUB_MUPOL0(param_3);
          return;
        case 0xb1:
          PPBASE_GM11M(param_3);
          return;
        case 0xb2:
          PPBASE_GM25II(param_3);
          return;
        }
        goto switchD_1800017a5_default;
      }
      uVar3 = uVar3 + 1;
      plVar5 = plVar5 + 2;
    } while (uVar3 != 0xb3);
    PPUSER_PHCCIU(param_1,param_2,param_3,&DAT_18001ebc8);
    if ((DAT_18001ebc8 != 0) &&
       (lVar2 = DMS_IRRCHK(s_PHCC_IN_6_18001e020,&DAT_180016be8,&DAT_180016be0,
                           DMS_GLOBAL_exref + 0x28,DMS_GLOBAL_exref + 0x38,&DAT_180016be8,
                           &DAT_180016be8,&DAT_180016bf0), local_a0 = DMS_ERROUT_exref, lVar2 != 0))
    {
      local_78 = *param_1;
      local_70[0] = 0;
      local_166 = 0x10b0638;
      local_162 = 2;
      local_90 = 800;
      local_88 = DMS_ERROUT_exref;
      local_80 = 0x50;
      for_write_int_fmt(local_70,0x801208384ff00,&local_166,&local_90,&DAT_18001e05c);
      local_b0[0] = *param_2;
      local_16a = 0x1010b;
      for_write_int_fmt_xmit(local_70,&local_16a,local_b0);
      local_70[0] = 0;
      local_16e = 0x10638;
      local_b0[1] = 0x2d0;
      local_a0 = local_a0 + 0x50;
      local_98 = 0x50;
      for_write_int_fmt(local_70,0x801208384ff00,&local_16e,local_b0 + 1,
                        s_PHCC_IN_6_18001e020 + 0x10);
      DMS_ERRPRT(&DAT_180016bf0);
    }
  }
  return;
}

/* RVA 0x2b80, FUN_180002b80 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_180002b80(void)

{
  _DAT_18001ebe0 = 0x40000;
  DMS_APCWRK(&DAT_180016c00,&DAT_18001ebe0,&DAT_18001ebd8,&DAT_18001ebd8);
  DMS_APCWRK(&DAT_180016bf8,&DAT_18001ebe0,&DAT_18001ebd8,&DAT_18001ebd8);
  DMS_APCWRK(&DAT_180016c00,&DAT_18001ebe0,&DAT_18001ebd8,&DAT_18001ebd8);
  DMS_PHCWRK();
  PPEXEC_PHCLCD();
  PPEXEC_PHCMAT();
  PPEXEC_PHCDRS();
  PPEXEC_PHCBIO();
  PPEXEC_PHCTAB();
  PPEXEC_PHCRES();
  return;
}

/* RVA 0x2c10, FUN_180002c10 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_180002c10(void)

{
  code *pcVar1;
  
  _PPEXEC_SYSFOI = 1;
  _DAT_1800220e8 = 10;
  _DAT_1800220f0 = 10;
  _DAT_1800220f8 = 0x1e;
  _DAT_180022100 = *(undefined8 *)(DMS_GLOBAL_exref + 0x38);
  _DAT_180022108 = 1;
  _DAT_180022110 = 0;
  uRam0000000180022118 = 0;
  _DAT_180022138 = 0;
  PPEXEC_SYSFOR = 0x3f1a36e2eb1c432d;
  pcVar1 = DMS_INITV_exref + 8;
  FUN_180004c60((ulonglong *)&DAT_180016c08,(longlong *)&DAT_180016c08,(longlong)pcVar1,
                (longlong)pcVar1,(longlong *)&DAT_180016c08,(longlong)pcVar1,
                (longlong)DMS_INITV_exref);
  return;
}

/* RVA 0x2cc0, PPEXEC_PHCBIO */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PPEXEC_PHCBIO(void)

{
  code *pcVar1;
  longlong lVar2;
  
                    /* 0x2cc0  22  PPEXEC_PHCBIO */
  lVar2 = DMS_LOCATI(&DAT_180016c10);
  pcVar1 = DMS_PLEX_exref;
  _DAT_18001ebf0 = *(undefined8 *)(DMS_PLEX_exref + lVar2 * 8 + 0x630);
  lVar2 = DMS_LOCATI(&DAT_18001ebf0);
  _DAT_18001ebe8 = *(longlong *)(pcVar1 + lVar2 * 8 + 0x50);
  if (0 < _DAT_18001ebe8) {
    lVar2 = DMS_LOCATI(&DAT_18001ebe8);
    *(longlong *)DMS_IPOFF6_exref = lVar2 + -1;
  }
  return;
}

/* RVA 0x2d30, PPEXEC_PHCDRS */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PPEXEC_PHCDRS(void)

{
  code *pcVar1;
  bool bVar2;
  longlong lVar3;
  undefined4 *puVar4;
  longlong *plVar5;
  code *pcVar6;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined2 local_d8;
  undefined4 local_d6;
  undefined4 local_d2;
  undefined4 local_ce;
  undefined2 local_ca;
  longlong local_c8;
  longlong local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  code *local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  code *local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70 [6];
  
                    /* 0x2d30  24  PPEXEC_PHCDRS */
  DAT_18001ec70 = DMS_LOCATI(&DAT_180016c28);
  pcVar1 = DMS_PLEX_exref;
  _DAT_18001ec68 = *(undefined8 *)(DMS_PLEX_exref + DAT_18001ec70 * 8 + 0x4f0);
  lVar3 = DMS_LOCATI(&DAT_18001ec68);
  DAT_18001ec60 = *(longlong *)(pcVar1 + lVar3 * 8 + -8);
  if ((DAT_18001ec60 == 1) &&
     (_DAT_18001ec58 = *(longlong *)(pcVar1 + DAT_18001ec70 * 8 + 0x238), _DAT_18001ec58 != 0)) {
    lVar3 = DMS_LOCATI(&DAT_18001ec58);
    DAT_18001ec00 = *(longlong *)(pcVar1 + lVar3 * 8 + -8);
    _DAT_18001ec50 = *(undefined8 *)(pcVar1 + DAT_18001ec70 * 8 + 0x4e8);
    DMS_LOCATM(&DAT_18001ec50,&DAT_18001ec48,&DAT_18001ec40,&DAT_18001ec38);
    _DAT_18001ecb8 = *(longlong *)(pcVar1 + DAT_18001ec48 * 8 + 0x28);
    lVar3 = *(longlong *)(pcVar1 + DAT_18001ec48 * 8 + 0x30);
    DAT_18001ec80 = 0xffffffffffffffff;
    _DAT_18001ec88 = _DAT_18001ecb8 * 3 + -1;
    _DAT_18001ec90 = _DAT_18001ecb8 * 3 + (DAT_18001ec00 + 7) * _DAT_18001ecb8 + -1;
    _DAT_18001ec98 = *(longlong *)(pcVar1 + DAT_18001ec48 * 8 + 0x40) * lVar3 + _DAT_18001ec90;
    _DAT_18001eca0 = _DAT_18001ec98 + *(longlong *)(DMS_NCOMP_exref + 0x10) * _DAT_18001ecb8;
    _DAT_18001eca8 = _DAT_18001eca0 + *(longlong *)(pcVar1 + DAT_18001ec48 * 8 + 0x38) * lVar3;
    _DAT_18001ecb0 = _DAT_18001eca8 + lVar3 * 4;
    _DAT_18001ecb8 = _DAT_18001ecb0 + _DAT_18001ecb8;
    _DAT_18001ec30 = _DAT_18001ecb8 + *(longlong *)(pcVar1 + DAT_18001ec48 * 8 + 0x38) * lVar3;
    if (_DAT_18001ec30 == 0) {
      _DAT_18001ec28 = 0;
    }
    else {
      DMS_APCWRK(&DAT_180016c18,&DAT_18001ec30,&DAT_18001ec28,&DAT_18001ec20);
    }
    DAT_18001ec18 = -1;
    DAT_18001ec60 = 1;
    pcVar1 = DMS_GLOBAL_exref + 0x38;
    pcVar6 = DMS_GLOBAL_exref + 0x28;
    do {
      lVar3 = DAT_18001ec18 * 8;
      DAT_18001ec18 = DAT_18001ec18 + 2;
      DAT_18001ec10 =
           DMS_IPHCFC(s_IDDT_IDPO_ST_IDPR_TN_IDXD_G_IDXN_18001e0e0 + lVar3 + 8,&DAT_18001ec08);
      if (DAT_18001ec10 < 9) {
        if (DAT_18001ec10 == 0) {
          lVar3 = DMS_IRRCHK(s_PHCD_RS_18001e0c0,&DAT_180016c30,&DAT_180016c28,pcVar6,pcVar1,
                             &DAT_180016c20,&DAT_180016c20,&DAT_180016c28);
          if (lVar3 != 0) {
            local_98 = *(undefined8 *)(DAT_18001ec18 * 8 + 0x18001e0d8);
            local_70[0] = 0;
            local_dc = 0x10b0638;
            local_d8 = 2;
            local_b0 = 800;
            local_a8 = DMS_ERROUT_exref;
            local_a0 = 0x50;
            for_write_int_fmt(local_70,0x801208384ff00,&local_dc,&local_b0,
                              s_IDDT_IDPO_ST_IDPR_TN_IDXD_G_IDXN_18001e0e0 + 0x80);
            local_c8 = *(longlong *)
                        (s_IDDT_IDPO_ST_IDPR_TN_IDXD_G_IDXN_18001e0e0 + DAT_18001ec18 * 8);
            local_e0 = 0x1010b;
            puVar4 = &local_e0;
            plVar5 = &local_c8;
            goto LAB_180003183;
          }
        }
        else {
          *(longlong *)(DMS_IPOFF5_exref + DAT_18001ec10 * 8 + -8) =
               *(longlong *)(DAT_18001ec60 * 8 + 0x18001ec78) + _DAT_18001ec28;
        }
      }
      else {
        lVar3 = DMS_IRRCHK(s_PHCD_RS_18001e0c0,&DAT_180016c30,&DAT_180016c30,pcVar6,pcVar1,
                           &DAT_180016c20,&DAT_180016c20,&DAT_180016c28);
        if (lVar3 != 0) {
          local_78 = *(undefined8 *)(DAT_18001ec18 * 8 + 0x18001e0d8);
          local_70[0] = 0;
          local_ce = 0x10b0638;
          local_ca = 2;
          local_90 = 800;
          local_88 = DMS_ERROUT_exref;
          local_80 = 0x50;
          for_write_int_fmt(local_70,0x801208384ff00,&local_ce,&local_90,&DAT_18001e1b0);
          local_b8 = *(undefined8 *)
                      (s_IDDT_IDPO_ST_IDPR_TN_IDXD_G_IDXN_18001e0e0 + DAT_18001ec18 * 8);
          local_d2 = 0x2010b;
          for_write_int_fmt_xmit(local_70,&local_d2,&local_b8);
          local_d6 = 0x1010b;
          local_c0 = DAT_18001ec10;
          puVar4 = &local_d6;
          plVar5 = &local_c0;
LAB_180003183:
          for_write_int_fmt_xmit(local_70,puVar4,plVar5);
          DMS_ERRPRT(&DAT_180016c30);
        }
      }
      lVar3 = DAT_18001ec60 + 1;
      bVar2 = DAT_18001ec60 < 8;
      DAT_18001ec60 = lVar3;
    } while (bVar2);
  }
  return;
}

/* RVA 0x31b0, PPEXEC_PHCLCD */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PPEXEC_PHCLCD(void)

{
  longlong lVar1;
  undefined8 uVar2;
  longlong lVar3;
  longlong lVar4;
  bool bVar5;
  code *pcVar6;
  code *pcVar7;
  longlong lVar8;
  ulonglong uVar9;
  longlong *plVar10;
  longlong lVar11;
  code *pcVar12;
  ulonglong uVar13;
  longlong lVar14;
  longlong lVar15;
  code *pcVar16;
  ulonglong uVar17;
  bool bVar18;
  undefined4 local_f8;
  undefined2 local_f4;
  undefined4 local_f2;
  undefined4 local_ee;
  undefined2 local_ea;
  longlong local_e8;
  code *local_e0;
  code *local_d8;
  code *local_d0;
  longlong local_c8;
  longlong local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  code *local_a8;
  undefined8 local_a0;
  longlong local_98;
  undefined8 local_90;
  code *local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70 [6];
  
                    /* 0x31b0  25  PPEXEC_PHCLCD */
  pcVar16 = DMS_IPOFF1_exref;
  lVar11 = 0;
  FUN_180008df0();
  pcVar7 = DMS_GLOBAL_exref;
  pcVar12 = DMS_IPOFF3_exref;
  uVar2 = *(undefined8 *)(DMS_GLOBAL_exref + 0x38);
  do {
    *(undefined8 *)(pcVar12 + lVar11 * 8) = uVar2;
    pcVar6 = DMS_IPOFF4_exref;
    lVar11 = lVar11 + 1;
  } while (lVar11 != 0x15e);
  lVar11 = 0;
  do {
    *(undefined8 *)(pcVar6 + lVar11 * 8) = 0;
    lVar11 = lVar11 + 1;
  } while (lVar11 != 5);
  DAT_18001f860 = 6;
  DAT_18001f868 = 0;
  if (*(longlong *)(pcVar7 + 0xb0) != 5) {
    DMS_TREAD(&DAT_180017690,&DAT_18001f8a0,&DAT_18001f898,&DAT_18001f890,&DAT_18001f888);
    pcVar12 = DMS_PLEX_exref;
    _DAT_18001f880 = *(longlong *)(DMS_PLEX_exref + DAT_18001f898 * 8 + 0x1c8);
    if (_DAT_18001f880 != 0) {
      DMS_TREAD(&DAT_18001f880,&DAT_18001f878,&DAT_18001f870,&DAT_18001f890,&DAT_18001f888);
      DAT_18001f868 = *(ulonglong *)(pcVar12 + DAT_18001f870 * 8 + -8);
    }
  }
  pcVar12 = DMS_LCLIST_exref;
  if (*(longlong *)DMS_LCLIST_exref != 0) {
    DMS_ATFREE();
    *(undefined8 *)(pcVar12 + 8) = 0;
    lVar11 = *(longlong *)(pcVar12 + 0x15f0);
    DAT_18001f860 = 1;
    if (1 < lVar11) {
      do {
        if (*(longlong *)(pcVar12 + DAT_18001f860 * 0x10 + 8) != 0) {
          DMS_ATFREE(pcVar12 + DAT_18001f860 * 0x10);
          *(undefined8 *)(pcVar12 + DAT_18001f860 * 0x10 + 8) = 0;
        }
        bVar5 = DAT_18001f860 < lVar11 + -1;
        DAT_18001f860 = DAT_18001f860 + 1;
      } while (bVar5);
    }
  }
  *(undefined8 *)(pcVar12 + 0x15f0) = 0;
  *(undefined8 *)pcVar12 = 0;
  *(undefined8 *)(pcVar12 + 8) = 0;
  pcVar7 = pcVar12 + 0x1608;
  lVar11 = 0;
  do {
    *(undefined8 *)(pcVar7 + -0x10) = 0;
    *(undefined8 *)(pcVar7 + -8) = 0;
    *(undefined8 *)pcVar7 = *(undefined8 *)((longlong)&DAT_180016ce0 + lVar11);
    *(undefined8 *)(pcVar12 + lVar11 * 2 + 0x10) = 0;
    *(undefined8 *)(pcVar12 + lVar11 * 2 + 0x10 + 8) = 0;
    lVar11 = lVar11 + 8;
    pcVar7 = pcVar7 + 0x18;
  } while (lVar11 != 0x970);
  DAT_18001f860 = 0x12f;
  lVar11 = DMS_LOCATI(&DAT_180017690);
  pcVar7 = DMS_PLEX_exref;
  _DAT_18001f858 = *(undefined8 *)(DMS_PLEX_exref + lVar11 * 8 + 0x188);
  DAT_18001f850 = DMS_LOCATI(&DAT_18001f858);
  DAT_18001f848 = DAT_18001f850 + -5;
  DAT_18001f840 = 0;
  DAT_18001f838 = 0;
  DAT_18001f830 = 0;
  DAT_18001f828 = -0xf4241;
  DAT_18001f820 = -1;
  lVar11 = *(longlong *)(pcVar7 + DAT_18001f850 * 8 + -8);
  DAT_18001f860 = 1;
  if (lVar11 < 1) {
    DAT_18001f820 = -6;
    DAT_18001f828 = -0xf4246;
    _DAT_18001f7e8 = 6;
    lVar11 = 6;
  }
  else {
    local_d0 = DMS_GLOBAL_exref + 0x38;
    local_d8 = DMS_GLOBAL_exref + 0x28;
    local_e0 = DMS_ERROUT_exref + 0x50;
    local_e8 = 0x2020202053584449;
    do {
      lVar8 = DAT_18001f848 * 8;
      DAT_18001f848 = DAT_18001f848 + 6;
      lVar8 = DMS_IPHCFC(pcVar7 + lVar8 + 0x28,&DAT_18001f810);
      lVar15 = DAT_18001f848;
      DAT_18001f818 = lVar8;
      if (DAT_18001f810 != 2) {
        if (*(longlong *)(&DAT_180017658 + DAT_18001f810 * 8) < lVar8) {
          lVar8 = DMS_IRRCHK(s_PHCL_CD_6_18001e220,&DAT_180017680,&DAT_180017680,local_d8,local_d0,
                             &DAT_180017688,&DAT_180017688,&DAT_180017690);
          if (lVar8 != 0) {
            local_78 = *(undefined8 *)(pcVar7 + DAT_18001f848 * 8 + -8);
            local_70[0] = 0;
            local_ee = 0x10b0638;
            local_ea = 2;
            local_90 = 800;
            local_88 = DMS_ERROUT_exref;
            local_80 = 0x50;
            for_write_int_fmt(local_70,0x801208384ff00,&local_ee,&local_90,&DAT_18001e2a8);
            local_b8 = *(undefined8 *)(pcVar7 + DAT_18001f848 * 8);
            local_f2 = 0x1010b;
            for_write_int_fmt_xmit(local_70,&local_f2,&local_b8);
            local_70[0] = 0;
            local_f8 = 0x10b0638;
            local_f4 = 1;
            local_b0 = 0x2d0;
            local_a8 = local_e0;
            local_a0 = 0x50;
            local_98 = DAT_18001f818;
            for_write_int_fmt(local_70,0x801208384ff00,&local_f8,&local_b0,&DAT_18001e278);
            DMS_ERRPRT(&DAT_180017690);
          }
        }
        else if (lVar8 != 0) {
          lVar1 = *(longlong *)(pcVar7 + DAT_18001f848 * 8 + -8);
          lVar4 = *(longlong *)(pcVar7 + DAT_18001f848 * 8);
          if (DAT_18001f810 == 3) {
            DAT_18001f7f8 = 1;
            plVar10 = &DAT_180016c40;
            uVar13 = 2;
            uVar9 = 0;
            do {
              uVar17 = uVar13;
              lVar14 = *plVar10;
              pcVar12 = DMS_LCLIST_exref;
              if (lVar8 == lVar14) {
                bVar5 = true;
                if (uVar17 == 2) goto LAB_18000372a;
                break;
              }
              plVar10 = plVar10 + 1;
              uVar13 = uVar17 + 1;
              uVar9 = uVar17;
            } while (uVar17 + 1 != 0x13);
            DAT_18001f7f8 = uVar9;
            bVar5 = lVar8 == lVar14;
          }
          else {
            bVar5 = false;
          }
LAB_18000372a:
          _DAT_18001f808 = *(longlong *)(pcVar7 + DAT_18001f848 * 8 + 0x10);
          if (_DAT_18001f808 == 0) {
            if (DAT_18001f810 == 3) {
              if ((DAT_18001f868 == 0) || (DAT_18001f7f8 = 1, (longlong)DAT_18001f868 < 1)) {
                lVar14 = 0;
              }
              else {
                pcVar16 = pcVar7 + DAT_18001f870 * 8;
                uVar13 = 0;
                lVar14 = 0;
                uVar9 = 1;
                do {
                  if ((*(longlong *)pcVar16 == lVar1) && (*(longlong *)(pcVar16 + 8) == lVar4)) {
                    if (uVar9 != 1) {
                      DAT_18001f7f8 = uVar13;
                    }
                    lVar14 = *(longlong *)(pcVar16 + 0x28);
                    goto LAB_180003a65;
                  }
                  uVar13 = lVar14 + 2;
                  lVar14 = lVar14 + 1;
                  uVar17 = uVar9 + 1;
                  pcVar16 = pcVar16 + 0x30;
                  bVar18 = uVar9 != DAT_18001f868;
                  uVar9 = uVar17;
                } while (bVar18);
                lVar14 = 0;
                DAT_18001f7f8 = uVar17;
              }
LAB_180003a65:
              lVar3 = *(longlong *)(pcVar7 + DAT_18001f848 * 8 + 0x18);
              DAT_18001ecc8 = lVar3;
              *(longlong *)(pcVar12 + lVar8 * 0x18 + 0x15e0) = lVar3;
              *(longlong *)(pcVar12 + lVar8 * 0x18 + 0x15e8) = lVar14;
              DAT_18001f800 = 0;
              lVar8 = DAT_18001f818;
              if (lVar3 != 0) {
                if ((lVar4 != 0x202020202020544c || lVar1 != local_e8) &&
                    (lVar4 != 0x2020202020202045 || lVar1 != 0x2020202055525449)) {
                  if (bVar5) {
                    DAT_18001f800 = DAT_18001f828;
                    DAT_18001f828 = DAT_18001f828 - lVar3;
                  }
                }
                else {
                  DAT_18001f800 = DAT_18001f820;
                  DAT_18001f820 = DAT_18001f820 - lVar3;
                }
              }
            }
          }
          else {
            if (DAT_18001f810 != 4 &&
                (DAT_18001f810 != 3 ||
                (lVar4 != 0x202020202020544c || lVar1 != local_e8) &&
                (lVar4 != 0x2020202020202045 || lVar1 != 0x2020202055525449))) {
              if ((DAT_18001f860 != 1) && (DAT_18001f7f8 = DAT_18001f860 - 1, 1 < DAT_18001f860)) {
                pcVar16 = pcVar7 + DAT_18001f850 * 8 + 0x28;
                uVar9 = 0;
                uVar13 = 0;
                do {
                  if ((*(longlong *)(pcVar7 + DAT_18001f848 * 8 + 0x20) == *(longlong *)pcVar16) &&
                     (_DAT_18001f808 == *(longlong *)(pcVar16 + -0x10))) {
                    if (uVar13 != 0) {
                      DAT_18001f7f8 = uVar9;
                    }
                    DAT_18001f800 = DAT_18001f828;
                    DAT_18001f828 = DAT_18001f828 - *(longlong *)(pcVar7 + DAT_18001f848 * 8 + 0x18)
                    ;
                    lVar8 = DAT_18001f838 + 1;
                    bVar5 = DAT_18001f830 <= DAT_18001f838;
                    DAT_18001f838 = lVar8;
                    if (bVar5) {
                      lVar8 = DAT_18001f830 * 2 + 0x14;
                      if (DAT_18001f840 == 0) {
                        DAT_18001f830 = DAT_18001f830 + 10;
                        local_c0 = lVar8;
                        DMS_ALLOCI(&local_c0,&DAT_18001f840,&DAT_18001f7f0);
                      }
                      else {
                        DAT_18001f830 = DAT_18001f830 + 10;
                        local_c8 = lVar8;
                        DMS_RALOCI(&DAT_18001f840,&local_c8,&DAT_18001f7f0);
                      }
                    }
                    lVar8 = DAT_18001f838 * 2 + DAT_18001f7f0;
                    *(longlong *)(pcVar7 + lVar8 * 8 + -0x18) = DAT_18001f818;
                    lVar15 = DAT_18001f848;
                    *(longlong *)(pcVar7 + lVar8 * 8 + -0x10) = DAT_18001f848;
                    lVar8 = DAT_18001f818;
                    goto joined_r0x000180003948;
                  }
                  uVar9 = (DAT_18001f860 - uVar13) - 2;
                  uVar13 = uVar13 + 1;
                  pcVar16 = pcVar16 + 0x30;
                } while (DAT_18001f7f8 != uVar13);
                DAT_18001f7f8 = ~uVar13 + DAT_18001f860;
              }
              lVar8 = DMS_LOCATR(&DAT_18001f808);
              lVar8 = lVar8 + *(longlong *)(pcVar7 + DAT_18001f848 * 8 + 0x20);
            }
            else {
              lVar8 = DMS_LOCATI(&DAT_18001f808);
              lVar8 = lVar8 + *(longlong *)(pcVar7 + DAT_18001f848 * 8 + 0x20);
            }
            DAT_18001f800 = lVar8 + -1;
            lVar8 = DAT_18001f818;
            lVar15 = DAT_18001f848;
          }
joined_r0x000180003948:
          DAT_18001f818 = lVar8;
          if (DAT_18001f810 == 1) {
            if (lVar8 - 900U < 300) {
              PPUSER_PHCLCU(pcVar7 + lVar15 * 8 + -8,&DAT_18001f800);
            }
            *(longlong *)(DMS_IPOFF1_exref + DAT_18001f818 * 8 + -8) = DAT_18001f800;
          }
          else if (DAT_18001f810 == 3) {
            if (DAT_18001f800 != 0) {
              *(longlong *)(DMS_IPOFF3_exref + lVar8 * 8 + -8) = DAT_18001f800;
              *(longlong *)(&DAT_18001ecd8 + lVar8 * 8) = DAT_18001ecc8;
            }
          }
          else if (DAT_18001f810 == 4) {
            *(longlong *)(DMS_IPOFF4_exref + lVar8 * 8 + -8) = DAT_18001f800;
          }
        }
      }
      lVar8 = DAT_18001f860 + 1;
      bVar5 = DAT_18001f860 < lVar11;
      DAT_18001f860 = lVar8;
    } while (bVar5);
    lVar11 = -(DAT_18001f828 + 0xf423b);
    if (-0xf423c < DAT_18001f828) {
      lVar11 = DAT_18001f828 + 0xf423b;
    }
    _DAT_18001f7e8 = -(DAT_18001f820 + -5);
    if (4 < DAT_18001f820) {
      _DAT_18001f7e8 = DAT_18001f820 + -5;
    }
    DAT_18001f828 = DAT_18001f828 + -5;
    pcVar16 = DMS_IPOFF1_exref;
    DAT_18001f820 = DAT_18001f820 + -5;
  }
  pcVar12 = DMS_DMS_exref;
  _DAT_18001f7e8 = lVar11 * *(longlong *)(DMS_DMS_exref + 8) + _DAT_18001f7e8;
  DMS_APCWRK(&DAT_180017698,&DAT_18001f7e8,&DAT_18001f7e0,&DAT_18001f7d8);
  lVar11 = DAT_18001f838;
  lVar8 = -DAT_18001f820;
  if (-DAT_18001f820 < 0) {
    lVar8 = DAT_18001f820;
  }
  uVar9 = (DAT_18001f7e0 + lVar8) - 1;
  uVar13 = *(ulonglong *)(pcVar12 + 8);
  if ((uVar9 | uVar13) >> 0x20 == 0) {
    uVar9 = (uVar9 & 0xffffffff) / (uVar13 & 0xffffffff);
  }
  else {
    uVar9 = (longlong)uVar9 / (longlong)uVar13;
  }
  DAT_18001ecc0 = uVar9 + 1;
  if (0 < DAT_18001f838) {
    DAT_18001f7f8 = DAT_18001f7f0 - 2;
    DAT_18001f860 = 1;
    do {
      lVar8 = DAT_18001f7f8 * 8;
      DAT_18001f848 = *(longlong *)(pcVar7 + DAT_18001f7f8 * 8 + 0x10);
      lVar15 = -*(longlong *)(pcVar16 + *(longlong *)(pcVar7 + lVar8 + 8) * 8 + -8);
      if (lVar15 < 0) {
        lVar15 = *(longlong *)(pcVar16 + *(longlong *)(pcVar7 + lVar8 + 8) * 8 + -8);
      }
      DAT_18001f7d0 = DAT_18001ecc0 + -0xf4241 + lVar15;
      DAT_18001f7f8 = DAT_18001f7f8 + 2;
      *(longlong *)(pcVar16 + *(longlong *)(pcVar7 + lVar8 + 8) * 8 + -8) = DAT_18001f7d0;
      lVar15 = DMS_LOCATR(pcVar7 + DAT_18001f848 * 8 + 0x10);
      lVar8 = *(longlong *)(pcVar7 + DAT_18001f848 * 8 + 0x18);
      if (0 < lVar8) {
        lVar4 = *(longlong *)(pcVar7 + DAT_18001f848 * 8 + 0x20);
        lVar1 = DAT_18001f7d0 * 8;
        lVar14 = 0;
        do {
          *(undefined8 *)(pcVar7 + lVar14 * 8 + lVar1) =
               *(undefined8 *)(pcVar7 + lVar14 * 8 + (lVar15 + lVar4) * 8 + -8);
          lVar14 = lVar14 + 1;
        } while (lVar14 < lVar8);
      }
      lVar8 = DAT_18001f860 + 1;
      bVar5 = DAT_18001f860 < lVar11;
      DAT_18001f860 = lVar8;
    } while (bVar5);
    DMS_ATFREE(&DAT_18001f840);
  }
  pcVar12 = DMS_IPOFF3_exref;
  lVar11 = *(longlong *)(DMS_IPOFF3_exref + 0x140);
  lVar8 = *(longlong *)(DMS_GLOBAL_exref + 0x38);
  if (lVar11 != lVar8) {
    lVar15 = -lVar11;
    if (-lVar11 < 0) {
      lVar15 = lVar11;
    }
    *(longlong *)(DMS_IPOFF3_exref + 0x140) = lVar15 + DAT_18001f7e0 + -1;
  }
  lVar11 = *(longlong *)(pcVar12 + 0x148);
  if (lVar11 != lVar8) {
    lVar8 = -lVar11;
    if (-lVar11 < 0) {
      lVar8 = lVar11;
    }
    *(longlong *)(pcVar12 + 0x148) = DAT_18001f7e0 + lVar8 + -1;
  }
  lVar11 = DAT_18001ecc0 + -0xf4241;
  lVar8 = 0;
  do {
    lVar15 = -*(longlong *)(pcVar12 + *(longlong *)((longlong)&DAT_180016c40 + lVar8) * 8 + -8);
    if (lVar15 < 0) {
      lVar15 = *(longlong *)(pcVar12 + *(longlong *)((longlong)&DAT_180016c40 + lVar8) * 8 + -8);
    }
    *(longlong *)(pcVar12 + *(longlong *)((longlong)&DAT_180016c40 + lVar8) * 8 + -8) =
         lVar15 + lVar11;
    lVar8 = lVar8 + 8;
  } while (lVar8 != 0x88);
  DAT_18001f860 = 0x12;
  return;
}

/* RVA 0x3e70, PPEXEC_PHCMAT */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PPEXEC_PHCMAT(void)

{
  bool bVar1;
  code *pcVar2;
  code *pcVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  undefined4 *puVar7;
  longlong *plVar8;
  code *pcVar9;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined2 local_e0;
  undefined4 local_de;
  undefined4 local_da;
  undefined4 local_d6;
  undefined2 local_d2;
  code *local_d0;
  longlong local_c8;
  longlong local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  code *local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  code *local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70 [6];
  
                    /* 0x3e70  26  PPEXEC_PHCMAT */
  pcVar2 = DMS_IPOFF2_exref;
  FUN_180008df0();
  DAT_18001f8f8 = 0xc0;
  DAT_18001f8f0 = DMS_LOCATI(&DAT_1800176a8);
  pcVar3 = DMS_PLEX_exref;
  _DAT_18001f8e8 = *(undefined8 *)(DMS_PLEX_exref + DAT_18001f8f0 * 8 + 0x118);
  lVar4 = DMS_LOCATI(&DAT_18001f8e8);
  if ((0 < *(longlong *)(pcVar3 + lVar4 * 8 + 0x10)) &&
     (_DAT_18001f8e0 = *(longlong *)(pcVar3 + DAT_18001f8f0 * 8 + 0xd0), 0 < _DAT_18001f8e0)) {
    DAT_18001f8d8 = DMS_LOCATI(&DAT_18001f8e0);
    DAT_18001f8a8 = *(longlong *)(pcVar3 + DAT_18001f8d8 * 8 + -8);
    if (0 < DAT_18001f8a8) {
      _DAT_18001f8d0 = *(undefined8 *)(pcVar3 + DAT_18001f8f0 * 8 + 0x188);
      lVar4 = DMS_LOCATI(&DAT_18001f8d0);
      DAT_18001f8c8 = lVar4 + -5;
      lVar4 = *(longlong *)(pcVar3 + lVar4 * 8 + -8);
      DAT_18001f8f8 = 1;
      if (0 < lVar4) {
        local_d0 = DMS_GLOBAL_exref + 0x38;
        pcVar9 = DMS_GLOBAL_exref + 0x28;
        do {
          lVar6 = DAT_18001f8c8 + 6;
          if ((*(longlong *)(pcVar3 + DAT_18001f8c8 * 8 + 0x48) < 1) &&
             (lVar6 = DAT_18001f8c8 * 8, DAT_18001f8c8 = DAT_18001f8c8 + 6,
             DAT_18001f8c0 = DMS_IPHCFC(pcVar3 + lVar6 + 0x28,&DAT_18001f8b8), lVar6 = DAT_18001f8c8
             , DAT_18001f8b8 == 2)) {
            if (DAT_18001f8c0 < 0xc0) {
              if (DAT_18001f8c0 == 0) {
                lVar5 = DMS_IRRCHK(&DAT_18001e300,&DAT_1800176b0,&DAT_1800176a8,pcVar9,local_d0,
                                   &DAT_1800176a0,&DAT_1800176a0,&DAT_1800176a8);
                lVar6 = DAT_18001f8c8;
                if (lVar5 != 0) {
                  local_98 = *(undefined8 *)(pcVar3 + DAT_18001f8c8 * 8 + -8);
                  local_70[0] = 0;
                  local_e4 = 0x10b0638;
                  local_e0 = 2;
                  local_b0 = 800;
                  local_a8 = DMS_ERROUT_exref;
                  local_a0 = 0x50;
                  for_write_int_fmt(local_70,0x801208384ff00,&local_e4,&local_b0,&DAT_18001e310);
                  local_c8 = *(longlong *)(pcVar3 + DAT_18001f8c8 * 8);
                  local_e8 = 0x1010b;
                  puVar7 = &local_e8;
                  plVar8 = &local_c8;
                  goto LAB_180004289;
                }
              }
              else {
                lVar6 = DAT_18001f8d8 + 1;
                if (0 < DAT_18001f8a8) {
                  lVar5 = 0;
                  do {
                    if ((*(longlong *)(pcVar3 + lVar6 * 8 + 8) ==
                         *(longlong *)(pcVar3 + DAT_18001f8c8 * 8 + -8)) &&
                       (*(longlong *)(pcVar3 + lVar6 * 8 + 0x10) ==
                        *(longlong *)(pcVar3 + DAT_18001f8c8 * 8))) break;
                    lVar6 = lVar6 + 5;
                    lVar5 = lVar5 + 1;
                  } while (lVar5 < DAT_18001f8a8);
                }
                _DAT_18001f8b0 = *(undefined8 *)(pcVar3 + lVar6 * 8 + 0x18);
                lVar6 = DMS_LOCATI(&DAT_18001f8b0);
                *(longlong *)(pcVar2 + DAT_18001f8c0 * 8 + -8) =
                     lVar6 + *(longlong *)(pcVar3 + DAT_18001f8c8 * 8 + 0x20) + -1;
                lVar6 = DAT_18001f8c8;
              }
            }
            else {
              lVar5 = DMS_IRRCHK(&DAT_18001e300,&DAT_1800176b0,&DAT_1800176b0,pcVar9,local_d0,
                                 &DAT_1800176a0,&DAT_1800176a0,&DAT_1800176a8);
              lVar6 = DAT_18001f8c8;
              if (lVar5 != 0) {
                local_78 = *(undefined8 *)(pcVar3 + DAT_18001f8c8 * 8 + -8);
                local_70[0] = 0;
                local_d6 = 0x10b0638;
                local_d2 = 2;
                local_90 = 800;
                local_88 = DMS_ERROUT_exref;
                local_80 = 0x50;
                for_write_int_fmt(local_70,0x801208384ff00,&local_d6,&local_90,&DAT_18001e360);
                local_b8 = *(undefined8 *)(pcVar3 + DAT_18001f8c8 * 8);
                local_da = 0x2010b;
                for_write_int_fmt_xmit(local_70,&local_da,&local_b8);
                local_de = 0x1010b;
                local_c0 = DAT_18001f8c0;
                puVar7 = &local_de;
                plVar8 = &local_c0;
LAB_180004289:
                for_write_int_fmt_xmit(local_70,puVar7,plVar8);
                DMS_ERRPRT(&DAT_1800176b0);
                lVar6 = DAT_18001f8c8;
              }
            }
          }
          DAT_18001f8c8 = lVar6;
          lVar6 = DAT_18001f8f8 + 1;
          bVar1 = DAT_18001f8f8 < lVar4;
          DAT_18001f8f8 = lVar6;
        } while (bVar1);
      }
    }
  }
  return;
}

/* RVA 0x42b0, PPEXEC_PHCRES */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PPEXEC_PHCRES(void)

{
  code *pcVar1;
  code *pcVar2;
  longlong lVar3;
  undefined4 *puVar4;
  longlong *plVar5;
  code *pcVar6;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined2 local_d8;
  undefined4 local_d6;
  undefined4 local_d2;
  undefined4 local_ce;
  undefined2 local_ca;
  longlong local_c8;
  longlong local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  code *local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  code *local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70 [6];
  
                    /* 0x42b0  27  PPEXEC_PHCRES */
  pcVar2 = DMS_IPOFF8_exref;
  lVar3 = 0;
  do {
    *(undefined8 *)((longlong)&DAT_18001f940 + lVar3) = 0;
    *(undefined8 *)(pcVar2 + lVar3) = 0;
    lVar3 = lVar3 + 8;
  } while (lVar3 != 0x38);
  DAT_18001f928 = 8;
  DAT_18001f920 = DMS_LOCATI(&DAT_1800176c0);
  pcVar6 = DMS_PLEX_exref;
  pcVar1 = DMS_NCOMP_exref;
  if (0 < *(longlong *)DMS_NCOMP_exref) {
    _DAT_18001f918 = *(undefined8 *)(DMS_PLEX_exref + DAT_18001f920 * 8 + 0x160);
    lVar3 = DMS_LOCATI(&DAT_18001f918);
    DAT_18001f940 = lVar3 + -1;
    if (0 < *(longlong *)(pcVar1 + 0x20)) {
      _DAT_18001f918 = *(undefined8 *)(pcVar6 + DAT_18001f920 * 8 + 0x168);
      lVar3 = DMS_LOCATI(&DAT_18001f918);
      DAT_18001f948 = lVar3 + -1;
      _DAT_18001f918 = *(undefined8 *)(pcVar6 + DAT_18001f920 * 8 + 0x140);
      _DAT_18001f950 = DMS_LOCATI(&DAT_18001f918);
      _DAT_18001f950 = _DAT_18001f950 + -1;
    }
    _DAT_18001f918 = *(undefined8 *)(pcVar6 + DAT_18001f920 * 8 + 0x150);
    _DAT_18001f958 = DMS_LOCATI(&DAT_18001f918);
    _DAT_18001f958 = _DAT_18001f958 + -1;
  }
  if (0 < *(longlong *)(pcVar1 + 8)) {
    _DAT_18001f918 = *(undefined8 *)(DMS_PLEX_exref + DAT_18001f920 * 8 + 0x148);
    _DAT_18001f960 = DMS_LOCATI(&DAT_18001f918);
    _DAT_18001f960 = _DAT_18001f960 + -1;
  }
  pcVar6 = DMS_PLEX_exref;
  if (0 < *(longlong *)(pcVar1 + 0x18)) {
    _DAT_18001f918 = *(undefined8 *)(DMS_PLEX_exref + DAT_18001f920 * 8 + 0x158);
    _DAT_18001f968 = DMS_LOCATI(&DAT_18001f918);
    _DAT_18001f968 = _DAT_18001f968 + -1;
    _DAT_18001f918 = *(undefined8 *)(pcVar6 + DAT_18001f920 * 8 + 0x170);
    _DAT_18001f970 = DMS_LOCATI(&DAT_18001f918);
    _DAT_18001f970 = _DAT_18001f970 + -1;
  }
  DAT_18001f910 = -1;
  DAT_18001f928 = 1;
  pcVar1 = DMS_GLOBAL_exref + 0x38;
  pcVar6 = DMS_GLOBAL_exref + 0x28;
  do {
    lVar3 = DAT_18001f910 * 8;
    DAT_18001f910 = DAT_18001f910 + 2;
    DAT_18001f908 =
         DMS_IPHCFC(s_IACC_ICC_IDXA_CC_IDXC_C_IDXN_CC_N_18001e3e0 + lVar3 + 8,&DAT_18001f900);
    if (DAT_18001f908 < 8) {
      if (DAT_18001f908 == 0) {
        lVar3 = DMS_IRRCHK(s_PHCR_ES_18001e3c0,&DAT_1800176c8,&DAT_1800176c0,pcVar6,pcVar1,
                           &DAT_1800176b8,&DAT_1800176b8,&DAT_1800176c0);
        if (lVar3 != 0) {
          local_98 = *(undefined8 *)(&DAT_18001e3d8 + DAT_18001f910 * 8);
          local_70[0] = 0;
          local_dc = 0x10b0638;
          local_d8 = 2;
          local_b0 = 800;
          local_a8 = DMS_ERROUT_exref;
          local_a0 = 0x50;
          for_write_int_fmt(local_70,0x801208384ff00,&local_dc,&local_b0,
                            s_IACC_ICC_IDXA_CC_IDXC_C_IDXN_CC_N_18001e3e0 + 0x70);
          local_c8 = *(longlong *)
                      (s_IACC_ICC_IDXA_CC_IDXC_C_IDXN_CC_N_18001e3e0 + DAT_18001f910 * 8);
          local_e0 = 0x1010b;
          puVar4 = &local_e0;
          plVar5 = &local_c8;
          goto LAB_1800044d0;
        }
        goto LAB_1800044dd;
      }
      *(undefined8 *)(pcVar2 + DAT_18001f908 * 8 + -8) =
           *(undefined8 *)(DAT_18001f928 * 8 + 0x18001f938);
      lVar3 = DAT_18001f928;
    }
    else {
      lVar3 = DMS_IRRCHK(s_PHCR_ES_18001e3c0,&DAT_1800176c8,&DAT_1800176c8,pcVar6,pcVar1,
                         &DAT_1800176b8,&DAT_1800176b8,&DAT_1800176c0);
      if (lVar3 != 0) {
        local_78 = *(undefined8 *)(&DAT_18001e3d8 + DAT_18001f910 * 8);
        local_70[0] = 0;
        local_ce = 0x10b0638;
        local_ca = 2;
        local_90 = 800;
        local_88 = DMS_ERROUT_exref;
        local_80 = 0x50;
        for_write_int_fmt(local_70,0x801208384ff00,&local_ce,&local_90,&DAT_18001e4a0);
        local_b8 = *(undefined8 *)
                    (s_IACC_ICC_IDXA_CC_IDXC_C_IDXN_CC_N_18001e3e0 + DAT_18001f910 * 8);
        local_d2 = 0x2010b;
        for_write_int_fmt_xmit(local_70,&local_d2,&local_b8);
        local_d6 = 0x1010b;
        local_c0 = DAT_18001f908;
        puVar4 = &local_d6;
        plVar5 = &local_c0;
LAB_1800044d0:
        for_write_int_fmt_xmit(local_70,puVar4,plVar5);
        DMS_ERRPRT(&DAT_1800176c8);
      }
LAB_1800044dd:
      lVar3 = DAT_18001f928;
    }
    DAT_18001f928 = lVar3 + 1;
    if (6 < lVar3) {
      return;
    }
  } while( true );
}

/* RVA 0x4760, PPEXEC_PHCTAB */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PPEXEC_PHCTAB(void)

{
  code *pcVar1;
  bool bVar2;
  code *pcVar3;
  longlong lVar4;
  longlong lVar5;
  undefined4 *puVar6;
  longlong *plVar7;
  code *pcVar8;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined2 local_d8;
  undefined4 local_d6;
  undefined4 local_d2;
  undefined4 local_ce;
  undefined2 local_ca;
  longlong local_c8;
  longlong local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  code *local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  code *local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70 [6];
  
                    /* 0x4760  28  PPEXEC_PHCTAB */
  pcVar3 = DMS_IPOFF7_exref;
  lVar4 = 0;
  do {
    *(undefined8 *)((longlong)&DAT_18001fa00 + lVar4) = 0;
    *(undefined8 *)(pcVar3 + lVar4) = 0;
    lVar4 = lVar4 + 8;
  } while (lVar4 != 0x20);
  DAT_18001f9f8 = 5;
  lVar4 = DMS_LOCATI(&DAT_1800176d8);
  pcVar1 = DMS_PLEX_exref;
  _DAT_18001f9f0 = *(longlong *)(DMS_PLEX_exref + lVar4 * 8 + 0x3c8);
  if (_DAT_18001f9f0 != 0) {
    lVar4 = DMS_LOCATI(&DAT_18001f9f0);
    if (*(longlong *)(pcVar1 + lVar4 * 8 + -8) == 1) {
      DAT_18001f988 = *(longlong *)(pcVar1 + lVar4 * 8 + 8);
      _DAT_18001f9e8 = *(undefined8 *)(pcVar1 + lVar4 * 8 + 0x10);
      _DAT_18001f9e0 = *(undefined8 *)(pcVar1 + lVar4 * 8 + 0x18);
      _DAT_18001f9d8 = *(undefined8 *)(pcVar1 + lVar4 * 8 + 0x28);
      DAT_18001f980 = *(longlong *)(pcVar1 + lVar4 * 8 + 0x40);
      DAT_18001f9d0 = *(longlong *)(pcVar1 + lVar4 * 8 + 0x68);
      DAT_18001f9c8 = *(longlong *)(pcVar1 + lVar4 * 8 + 0x70);
      lVar5 = DMS_LOCATI(&DAT_18001f9e0);
      lVar4 = *(longlong *)(DMS_NCOMP_exref + 8);
      if (*(longlong *)(DMS_NCOMP_exref + 8) < *(longlong *)DMS_NCOMP_exref) {
        lVar4 = *(longlong *)DMS_NCOMP_exref;
      }
      if (DAT_18001f988 != 0 && lVar4 * *(longlong *)(pcVar1 + lVar5 * 8 + -8) * 5 != 0) {
        lVar4 = DMS_LOCATI(&DAT_18001f9d8);
        DAT_18001fa00 = lVar4 + -1;
      }
      if (0 < DAT_18001f9d0) {
        lVar4 = DMS_LOCATI(&DAT_18001f9d0);
        DAT_18001fa08 = lVar4 + -1;
      }
      if (0 < DAT_18001f9c8) {
        _DAT_18001fa10 = DMS_LOCATR(&DAT_18001f9c8);
        _DAT_18001fa10 = _DAT_18001fa10 + -1;
      }
      if (DAT_18001f980 != 0) {
        _DAT_18001f9c0 = DMS_LENTHR(&DAT_18001f9e8);
        DAT_18001f9b8 = DMS_LOCATR(&DAT_18001f9e8);
        if (PPEXEC_NBDTAB != 0) {
          DMS_FREEBD(&PPEXEC_NBDTAB);
          PPEXEC_NBDTAB = 0;
        }
        DMS_ALLOCR(&DAT_18001f9c0,&DAT_18001f9b0,&DAT_18001f9a8);
        DMS_RCOPY(pcVar1 + DAT_18001f9b8 * 8 + -8,pcVar1 + DAT_18001f9a8 * 8 + -8,&DAT_18001f9c0);
        _DAT_18001fa18 = DAT_18001f9a8 + -1;
        PPEXEC_NBDTAB = DAT_18001f9b0;
      }
      DAT_18001f9a0 = -1;
      DAT_18001f9f8 = 1;
      pcVar1 = DMS_GLOBAL_exref + 0x38;
      pcVar8 = DMS_GLOBAL_exref + 0x28;
      do {
        lVar4 = DAT_18001f9a0 * 8;
        DAT_18001f9a0 = DAT_18001f9a0 + 2;
        DAT_18001f998 =
             DMS_IPHCFC(s_IDXT_AB_IPRF_DX_PSRF_DT_TABL_AR_6_18001e520 + lVar4 + 8,&DAT_18001f990);
        if (DAT_18001f998 < 5) {
          if (DAT_18001f998 == 0) {
            lVar4 = DMS_IRRCHK(s_PHCT_AB_18001e500,&DAT_1800176e0,&DAT_1800176d8,pcVar8,pcVar1,
                               &DAT_1800176d0,&DAT_1800176d0,&DAT_1800176d8);
            if (lVar4 != 0) {
              local_98 = *(undefined8 *)(&DAT_18001e518 + DAT_18001f9a0 * 8);
              local_70[0] = 0;
              local_dc = 0x10b0638;
              local_d8 = 2;
              local_b0 = 800;
              local_a8 = DMS_ERROUT_exref;
              local_a0 = 0x50;
              for_write_int_fmt(local_70,0x801208384ff00,&local_dc,&local_b0,
                                s_IDXT_AB_IPRF_DX_PSRF_DT_TABL_AR_6_18001e520 + 0x40);
              local_c8 = *(longlong *)
                          (s_IDXT_AB_IPRF_DX_PSRF_DT_TABL_AR_6_18001e520 + DAT_18001f9a0 * 8);
              local_e0 = 0x1010b;
              puVar6 = &local_e0;
              plVar7 = &local_c8;
              goto LAB_1800049e0;
            }
          }
          else {
            *(longlong *)(pcVar3 + DAT_18001f998 * 8 + -8) = (&DAT_18001f9f8)[DAT_18001f9f8];
          }
        }
        else {
          lVar4 = DMS_IRRCHK(s_PHCT_AB_18001e500,&DAT_1800176e0,&DAT_1800176e0,pcVar8,pcVar1,
                             &DAT_1800176d0,&DAT_1800176d0,&DAT_1800176d8);
          if (lVar4 != 0) {
            local_78 = *(undefined8 *)(&DAT_18001e518 + DAT_18001f9a0 * 8);
            local_70[0] = 0;
            local_ce = 0x10b0638;
            local_ca = 2;
            local_90 = 800;
            local_88 = DMS_ERROUT_exref;
            local_80 = 0x50;
            for_write_int_fmt(local_70,0x801208384ff00,&local_ce,&local_90,&DAT_18001e5b0);
            local_b8 = *(undefined8 *)
                        (s_IDXT_AB_IPRF_DX_PSRF_DT_TABL_AR_6_18001e520 + DAT_18001f9a0 * 8);
            local_d2 = 0x2010b;
            for_write_int_fmt_xmit(local_70,&local_d2,&local_b8);
            local_d6 = 0x1010b;
            local_c0 = DAT_18001f998;
            puVar6 = &local_d6;
            plVar7 = &local_c0;
LAB_1800049e0:
            for_write_int_fmt_xmit(local_70,puVar6,plVar7);
            DMS_ERRPRT(&DAT_1800176e0);
          }
        }
        lVar4 = DAT_18001f9f8 + 1;
        bVar2 = DAT_18001f9f8 < 4;
        DAT_18001f9f8 = lVar4;
      } while (bVar2);
    }
  }
  return;
}

/* RVA 0x4c60, FUN_180004c60 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_180004c60(ulonglong *param_1,longlong *param_2,longlong param_3,longlong param_4,
                  longlong *param_5,longlong param_6,longlong param_7)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong lVar3;
  
  uVar1 = *param_1;
  if ((uVar1 & 0xfffffffffffffffd) == 0) {
    _DAT_180022040 = DAT_180022140;
    _DAT_180022030 = _DAT_180022130;
    uRam0000000180022038 = _DAT_180022138;
    _DAT_180022020 = _DAT_180022120;
    uRam0000000180022028 = uRam0000000180022128;
    _DAT_180022010 = _DAT_180022110;
    uRam0000000180022018 = uRam0000000180022118;
    _DAT_180022000 = _DAT_180022100;
    uRam0000000180022008 = _DAT_180022108;
    _DAT_180021ff0 = _DAT_1800220f0;
    uRam0000000180021ff8 = _DAT_1800220f8;
    _PPEXEC_FLOPI = _PPEXEC_SYSFOI;
    uRam0000000180021fe8 = _DAT_1800220e8;
    lVar2 = 0;
    do {
      *(undefined8 *)((longlong)&PPEXEC_FLOPR + lVar2) =
           *(undefined8 *)((longlong)&PPEXEC_SYSFOR + lVar2);
      lVar2 = lVar2 + 8;
    } while (lVar2 != 0x50);
    if (uVar1 == 0) {
      return;
    }
  }
  lVar2 = *param_2;
  if (0 < lVar2) {
    lVar3 = 0;
    do {
      *(undefined8 *)(&DAT_180021ff0 + *(longlong *)(param_3 + lVar3 * 8) * 8) =
           *(undefined8 *)(param_4 + lVar3 * 8);
      lVar3 = lVar3 + 1;
    } while (lVar3 < lVar2);
  }
  lVar2 = *param_5;
  if (0 < lVar2) {
    lVar3 = 0;
    do {
      *(undefined8 *)(&DAT_18001fa18 + *(longlong *)(param_6 + lVar3 * 8) * 8) =
           *(undefined8 *)(param_7 + lVar3 * 8);
      lVar3 = lVar3 + 1;
    } while (lVar3 < lVar2);
  }
  return;
}

/* RVA 0x4d90, PPEXEC_PPSLAVE3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PPEXEC_PPSLAVE3(undefined8 param_1,longlong *param_2,longlong *param_3,undefined8 param_4,
                    undefined8 *param_5,longlong *param_6,ulonglong *param_7,undefined8 *param_8,
                    undefined8 *param_9)

{
  longlong lVar1;
  code *pcVar2;
  longlong lVar3;
  longlong lVar4;
  longlong local_60;
  longlong local_58;
  longlong local_50;
  longlong local_48;
  
                    /* 0x4d90  32  PPEXEC_PPSLAVE3 */
  pcVar2 = DMS_PPSLV_exref;
  _DAT_18001fc70 = 0;
  _DAT_18001fb6f = _DAT_1800176f0;
  uRam000000018001fb73 = _UNK_1800176f4;
  uRam000000018001fb77 = _UNK_1800176f8;
  uRam000000018001fb7b = _UNK_1800176fc;
  _DAT_18001fb7f = _DAT_1800176f0;
  uRam000000018001fb83 = _UNK_1800176f4;
  uRam000000018001fb87 = _UNK_1800176f8;
  uRam000000018001fb8b = _UNK_1800176fc;
  _DAT_18001fb8f = _DAT_1800176f0;
  uRam000000018001fb93 = _UNK_1800176f4;
  uRam000000018001fb97 = _UNK_1800176f8;
  uRam000000018001fb9b = _UNK_1800176fc;
  _DAT_18001fb9f = _DAT_1800176f0;
  uRam000000018001fba3 = _UNK_1800176f4;
  uRam000000018001fba7 = _UNK_1800176f8;
  uRam000000018001fbab = _UNK_1800176fc;
  _DAT_18001fbaf = _DAT_1800176f0;
  uRam000000018001fbb3 = _UNK_1800176f4;
  uRam000000018001fbb7 = _UNK_1800176f8;
  uRam000000018001fbbb = _UNK_1800176fc;
  _DAT_18001fbbf = _DAT_1800176f0;
  uRam000000018001fbc3 = _UNK_1800176f4;
  uRam000000018001fbc7 = _UNK_1800176f8;
  uRam000000018001fbcb = _UNK_1800176fc;
  _DAT_18001fbcf = _DAT_1800176f0;
  uRam000000018001fbd3 = _UNK_1800176f4;
  uRam000000018001fbd7 = _UNK_1800176f8;
  uRam000000018001fbdb = _UNK_1800176fc;
  _DAT_18001fbdf = _DAT_1800176f0;
  uRam000000018001fbe3 = _UNK_1800176f4;
  uRam000000018001fbe7 = _UNK_1800176f8;
  uRam000000018001fbeb = _UNK_1800176fc;
  _DAT_18001fbef = _DAT_1800176f0;
  uRam000000018001fbf3 = _UNK_1800176f4;
  uRam000000018001fbf7 = _UNK_1800176f8;
  uRam000000018001fbfb = _UNK_1800176fc;
  _DAT_18001fbff = _DAT_1800176f0;
  uRam000000018001fc03 = _UNK_1800176f4;
  uRam000000018001fc07 = _UNK_1800176f8;
  uRam000000018001fc0b = _UNK_1800176fc;
  _DAT_18001fc0f = _DAT_1800176f0;
  uRam000000018001fc13 = _UNK_1800176f4;
  uRam000000018001fc17 = _UNK_1800176f8;
  uRam000000018001fc1b = _UNK_1800176fc;
  _DAT_18001fc1f = _DAT_1800176f0;
  uRam000000018001fc23 = _UNK_1800176f4;
  uRam000000018001fc27 = _UNK_1800176f8;
  uRam000000018001fc2b = _UNK_1800176fc;
  _DAT_18001fc2f = _DAT_1800176f0;
  uRam000000018001fc33 = _UNK_1800176f4;
  uRam000000018001fc37 = _UNK_1800176f8;
  uRam000000018001fc3b = _UNK_1800176fc;
  _DAT_18001fc3f = _DAT_1800176f0;
  uRam000000018001fc43 = _UNK_1800176f4;
  uRam000000018001fc47 = _UNK_1800176f8;
  uRam000000018001fc4b = _UNK_1800176fc;
  _DAT_18001fc4f = _DAT_1800176f0;
  uRam000000018001fc53 = _UNK_1800176f4;
  uRam000000018001fc57 = _UNK_1800176f8;
  uRam000000018001fc5b._0_3_ = (undefined3)_UNK_1800176fc;
  DAT_18001fc5e = (undefined1)_DAT_1800176f0;
  uRam000000018001fc5f = (undefined3)((uint)_DAT_1800176f0 >> 8);
  uRam000000018001fc62 = _UNK_1800176f4;
  uRam000000018001fc66 = _UNK_1800176f8;
  uRam000000018001fc6a = _UNK_1800176fc;
  _DAT_18001fa70 = _DAT_1800176f0;
  uRam000000018001fa74 = _UNK_1800176f4;
  uRam000000018001fa78 = _UNK_1800176f8;
  uRam000000018001fa7c = _UNK_1800176fc;
  _DAT_18001fa80 = _DAT_1800176f0;
  uRam000000018001fa84 = _UNK_1800176f4;
  uRam000000018001fa88 = _UNK_1800176f8;
  uRam000000018001fa8c = _UNK_1800176fc;
  _DAT_18001fa90 = _DAT_1800176f0;
  uRam000000018001fa94 = _UNK_1800176f4;
  uRam000000018001fa98 = _UNK_1800176f8;
  uRam000000018001fa9c = _UNK_1800176fc;
  _DAT_18001faa0 = _DAT_1800176f0;
  uRam000000018001faa4 = _UNK_1800176f4;
  uRam000000018001faa8 = _UNK_1800176f8;
  uRam000000018001faac = _UNK_1800176fc;
  _DAT_18001fab0 = _DAT_1800176f0;
  uRam000000018001fab4 = _UNK_1800176f4;
  uRam000000018001fab8 = _UNK_1800176f8;
  uRam000000018001fabc = _UNK_1800176fc;
  _DAT_18001fac0 = _DAT_1800176f0;
  uRam000000018001fac4 = _UNK_1800176f4;
  uRam000000018001fac8 = _UNK_1800176f8;
  uRam000000018001facc = _UNK_1800176fc;
  _DAT_18001fad0 = _DAT_1800176f0;
  uRam000000018001fad4 = _UNK_1800176f4;
  uRam000000018001fad8 = _UNK_1800176f8;
  uRam000000018001fadc = _UNK_1800176fc;
  _DAT_18001fae0 = _DAT_1800176f0;
  uRam000000018001fae4 = _UNK_1800176f4;
  uRam000000018001fae8 = _UNK_1800176f8;
  uRam000000018001faec = _UNK_1800176fc;
  _DAT_18001faf0 = _DAT_1800176f0;
  uRam000000018001faf4 = _UNK_1800176f4;
  uRam000000018001faf8 = _UNK_1800176f8;
  uRam000000018001fafc = _UNK_1800176fc;
  _DAT_18001fb00 = _DAT_1800176f0;
  uRam000000018001fb04 = _UNK_1800176f4;
  uRam000000018001fb08 = _UNK_1800176f8;
  uRam000000018001fb0c = _UNK_1800176fc;
  _DAT_18001fb10 = _DAT_1800176f0;
  uRam000000018001fb14 = _UNK_1800176f4;
  uRam000000018001fb18 = _UNK_1800176f8;
  uRam000000018001fb1c = _UNK_1800176fc;
  _DAT_18001fb20 = _DAT_1800176f0;
  uRam000000018001fb24 = _UNK_1800176f4;
  uRam000000018001fb28 = _UNK_1800176f8;
  uRam000000018001fb2c = _UNK_1800176fc;
  _DAT_18001fb30 = _DAT_1800176f0;
  uRam000000018001fb34 = _UNK_1800176f4;
  uRam000000018001fb38 = _UNK_1800176f8;
  uRam000000018001fb3c = _UNK_1800176fc;
  _DAT_18001fb40 = _DAT_1800176f0;
  uRam000000018001fb44 = _UNK_1800176f4;
  uRam000000018001fb48 = _UNK_1800176f8;
  uRam000000018001fb4c = _UNK_1800176fc;
  _DAT_18001fb50 = _DAT_1800176f0;
  uRam000000018001fb54 = _UNK_1800176f4;
  uRam000000018001fb58 = _UNK_1800176f8;
  uRam000000018001fb5c = CONCAT13(DAT_18001fc5e,(undefined3)uRam000000018001fc5b);
  uRam000000018001fb63 = _UNK_1800176f4;
  uRam000000018001fb67 = _UNK_1800176f8;
  uRam000000018001fb6b = _UNK_1800176fc;
  uRam000000018001fb60 = uRam000000018001fc5f;
  *(undefined8 *)DMS_PPSLV_exref = 1;
  *(undefined8 *)(pcVar2 + 8) = *param_8;
  *(undefined8 *)(pcVar2 + 0x10) = *param_9;
  lVar1 = *param_2;
  if (lVar1 < 0) {
    lVar3 = DMS_STRLEN(param_1,0xff);
    FUN_180008d20();
    *(undefined4 *)(&DAT_18001fb6f + lVar3) = 0x7369682e;
    local_48 = -lVar1;
    DMS_IAPOPN(&DAT_18001fb6f,&local_48,&DAT_180017700,&DAT_18001fc70,&DAT_180017710,&DAT_180017710,
               &DAT_180017708,&DAT_180017710,0xff);
  }
  lVar3 = *param_3;
  if (lVar3 < 0) {
    lVar4 = DMS_STRLEN(param_1,0xff);
    FUN_180008d20();
    *(undefined4 *)(&DAT_18001fa70 + lVar4) = 0x7065722e;
    local_50 = -lVar3;
    DMS_IAPOPN(&DAT_18001fa70,&local_50,&DAT_180017700,&DAT_18001fc70,&DAT_180017710,&DAT_180017710,
               &DAT_180017708,&DAT_180017710,0xff);
  }
  pcVar2 = DMS_MAXWRK_exref;
  lVar4 = *param_6;
  *(longlong *)(DMS_MAXWRK_exref + 0x38) = lVar4;
  *(undefined8 *)(pcVar2 + 0x40) = *param_5;
  *(ulonglong *)pcVar2 = (ulonglong)((uint)(*param_7 >> 0x3e) & 0xfffffffe);
  *(undefined8 *)(pcVar2 + 0x60) = 0;
  _DAT_18001fc78 = (ulonglong)(lVar4 != 0);
  local_58 = -lVar1;
  if (-lVar1 < 0) {
    local_58 = lVar1;
  }
  local_60 = -lVar3;
  if (-lVar3 < 0) {
    local_60 = lVar3;
  }
  PPEXEC_APINIT(&local_58,(undefined8 *)&DAT_180017718,param_4,&local_60,&DAT_18001fc78,param_7);
  return;
}

/* RVA 0x50b0, PPEXEC_PPSLAVE2 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PPEXEC_PPSLAVE2(undefined8 param_1,longlong *param_2,longlong *param_3,undefined8 param_4,
                    undefined8 *param_5,longlong *param_6,ulonglong *param_7,undefined8 *param_8)

{
                    /* 0x50b0  31  PPEXEC_PPSLAVE2 */
  _DAT_18001fc80 = 0;
  PPEXEC_PPSLAVE3(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
                  (undefined8 *)&DAT_18001fc80);
  return;
}

/* RVA 0x50f0, PPEXEC_PPSLAVE */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PPEXEC_PPSLAVE(undefined8 param_1,longlong *param_2,longlong *param_3,undefined8 param_4,
                   undefined8 *param_5,longlong *param_6,ulonglong *param_7)

{
                    /* 0x50f0  30  PPEXEC_PPSLAVE */
  _DAT_18001fc88 = 0;
  _DAT_18001fc80 = 0;
  PPEXEC_PPSLAVE3(param_1,param_2,param_3,param_4,param_5,param_6,param_7,
                  (undefined8 *)&DAT_18001fc88,(undefined8 *)&DAT_18001fc80);
  return;
}

/* RVA 0x5150, PPEXEC_APCLOSE */
void PPEXEC_APCLOSE(longlong *param_1,longlong *param_2)

{
                    /* 0x5150  3  PPEXEC_APCLOSE */
  PPEXEC_APCLOSE2(param_1,param_2,(undefined4 *)&DAT_18001e620);
  return;
}

/* RVA 0x5160, PPEXEC_APCLOSE2 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PPEXEC_APCLOSE2(longlong *param_1,longlong *param_2,undefined4 *param_3)

{
  code *pcVar1;
  HMODULE pHVar2;
  code *pcVar3;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  char *local_98;
  undefined8 local_90;
  char *local_88;
  undefined8 local_80;
  char *local_78;
  undefined8 local_70 [6];
  
                    /* 0x5160  4  PPEXEC_APCLOSE2 */
  _DAT_18001fe60 = 0;
  _DAT_18001fe58 = 0;
  _DAT_18001fe48 = 0;
  if (*(longlong *)(DMS_PPRIV_exref + 0x4f30) == 0) {
    pHVar2 = GetModuleHandleA("SOLVINT");
    if (pHVar2 != (HMODULE)0x0) {
      pcVar3 = DMS_DBGOUT_exref + 0xd0;
      DAT_18001fe50 =
           DMS_FPLDLB(&DAT_18001fca8,s_SOLV_INT_INTP_P_6_18001e680,&DAT_180017730,&DAT_180017740,
                      pcVar3);
      if (DAT_18001fe50 == 0) {
        DMS_FPFIND(&DAT_18001fca0,s_SINT__GET_MDL_18001e640,&DAT_18001fca8,pcVar3,&DAT_18001fe50);
        if (DAT_18001fe50 == 0) {
          DMS_DOCALL_30(&DAT_18001fca0,&DAT_180017738,&DAT_180017740,&DAT_180017740,&DAT_180017740,
                        &DAT_180017740,&DAT_180017740,&DAT_18001fe40,&DAT_18001fe20,&DAT_18001fe00,
                        &DAT_18001fde0,&DAT_18001fdc0,&DAT_18001fd20,&DAT_180017748,&DAT_18001fd60,
                        &DAT_18001fd40,&DAT_18001fd00,&DAT_180017748,&DAT_18001fce0,&DAT_18001fcc0,
                        &DAT_18001fda0,&DAT_180017748,&DAT_18001fd80,&DAT_180017748,&DAT_18001fcb0,
                        &DAT_18001fcb0,&DAT_18001fcb0,&DAT_18001fcb0,&DAT_18001fcb0,&DAT_18001fcb0,
                        &DAT_18001fcb0);
        }
      }
    }
  }
  pcVar3 = DMS_INTRPT_exref;
  if (*(longlong *)(DMS_INTRPT_exref + 0x68) != 0) {
    DMS_APCWRK(&DAT_180017750,&DAT_18001fe48,&DAT_18001fe48,&DAT_18001fe48);
    PPSTUB_INIT_IXWRAP();
    DMS_FPULDL();
    pcVar1 = DMS_DMS_exref;
    if (*(longlong *)(DMS_DMS_exref + 0x2088) == 0) {
      DMS_UNLVRT();
    }
    DMS_CLRCMN();
    local_70[0] = 0;
    local_a8 = 0x1000c0438;
    local_80 = 4;
    local_78 = "SAVESOLVINT";
    for_close(local_70,*param_3,0x801208384ff00,&local_a8,&local_80);
    local_70[0] = 0;
    local_b0 = 0x1000c0438;
    local_90 = 4;
    local_88 = "SAVESOLVINT";
    for_close(local_70,0xc,0x801208384ff00,&local_b0,&local_90);
    local_70[0] = 0;
    local_b8 = 0x1000c0438;
    local_a0 = 4;
    local_98 = "SAVESOLVINT";
    for_close(local_70,5,0x801208384ff00,&local_b8,&local_a0);
    if (*(longlong *)(pcVar1 + 0x2088) == 0) {
      DMS_CLSPDF(&DAT_18001fe60,&DAT_18001fe58);
    }
    *(undefined8 *)(pcVar3 + 0x68) = 0;
    *(undefined8 *)(DMS_VIRTFN_exref + 8) = 0;
    *(undefined8 *)(DMS_IAPGLB_exref + 0x38) = 0;
  }
  pcVar3 = DMS_VMM2_exref;
  if (*(longlong *)(DMS_DMS_exref + 0x2088) == 0) {
    if (*(longlong *)(DMS_VMM2_exref + 0x140) != 0) {
      DAT_18001fe50 = DMS_CLSBDS(DMS_VMM2_exref + 0xa0);
      pcVar3[*(longlong *)(pcVar3 + 0x140) * 0x100 + 0x88] = (code)0x20;
      *(undefined8 *)(pcVar3 + 0x140) = 0;
    }
    if (*(longlong *)(pcVar3 + 0x150) != 0) {
      DAT_18001fe50 = DMS_CLSBDS(pcVar3 + 0xb0);
      pcVar3[*(longlong *)(pcVar3 + 0x150) * 0x100 + 0x88] = (code)0x20;
      *(undefined8 *)(pcVar3 + 0x150) = 0;
    }
    if (*param_1 == 1) {
      DMS_RTLAYL();
      LM_RETURN_APROP_LICENSE();
    }
    if ((*param_2 == 1) && (*(longlong *)DMS_MAXWRK_exref == 2)) {
      DMS_SELF_EXIT();
      return;
    }
  }
  return;
}

/* RVA 0x5610, PPEXEC_LDCMPTYP */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PPEXEC_LDCMPTYP(void)

{
  ulonglong uVar1;
  code *pcVar2;
  code *pcVar3;
  code *pcVar4;
  longlong lVar5;
  ulonglong uVar6;
  longlong lVar7;
  undefined8 uVar8;
  longlong lVar9;
  longlong lVar10;
  
                    /* 0x5610  17  PPEXEC_LDCMPTYP */
  DMS_GET_PRODUCTCODE(&DAT_18001fe88);
  pcVar2 = DMS_PLEX_exref;
  pcVar3 = DMS_NCOMP_exref;
  DAT_18001fea8 = *(longlong *)(DMS_IPOFF1_exref + 0x1bf8);
  uVar1 = *(ulonglong *)DMS_NCOMP_exref;
  if (0 < (longlong)uVar1) {
    lVar9 = DAT_18001fea8 * 8;
    if (uVar1 < 0xd) {
      uVar6 = 0;
      do {
        *(undefined8 *)(pcVar2 + uVar6 * 8 + lVar9) = 0;
        uVar6 = uVar6 + 1;
      } while (uVar1 != uVar6);
    }
    else {
      FUN_180008df0();
    }
  }
  SHS_FIPOLM(&DAT_18001fef8);
  if (DAT_18001fef8 < 1) {
    *(undefined8 *)(pcVar3 + 0x90) = 0;
    *(undefined8 *)(pcVar3 + 0x98) = 0;
    *(undefined8 *)(pcVar3 + 0x80) = 0;
    *(undefined8 *)(pcVar3 + 0x88) = 0;
    *(undefined8 *)(pcVar3 + 0xa0) = 0;
    lVar9 = 0;
  }
  else {
    DAT_18001fef0 = DMS_LOCATI(&DAT_18001fef8);
    pcVar2 = DMS_PLEX_exref;
    _DAT_18001fed8 = *(undefined8 *)(DMS_PLEX_exref + DAT_18001fef0 * 8);
    DAT_18001fee8 = *(longlong *)(DMS_PLEX_exref + DAT_18001fef0 * 8 + 8);
    DAT_18001feb8 = *(longlong *)(DMS_PLEX_exref + DAT_18001fef0 * 8 + 0x20);
    DAT_18001fec8 = *(longlong *)(DMS_PLEX_exref + DAT_18001fef0 * 8 + 0x28);
    DAT_18001fe98 = *(longlong *)(DMS_PLEX_exref + DAT_18001fef0 * 8 + 0x78);
    lVar7 = DMS_LOCATI(&DAT_18001fed8);
    lVar5 = DAT_18001fea8;
    pcVar4 = DMS_PLEX_exref;
    lVar9 = *(longlong *)(pcVar2 + lVar7 * 8 + -8);
    DAT_18001fed0 = lVar9;
    if (0 < lVar9) {
      lVar10 = 0;
      do {
        *(undefined8 *)(pcVar2 + (*(longlong *)(pcVar4 + lVar10 * 8 + lVar7 * 8) + lVar5) * 8 + -8)
             = 0x3ff0000000000000;
        lVar10 = lVar10 + 1;
      } while (lVar10 < lVar9);
    }
    if (0 < DAT_18001fee8) {
      lVar7 = DMS_LOCATI(&DAT_18001fee8);
      lVar5 = DAT_18001fea8;
      pcVar4 = DMS_PLEX_exref;
      lVar9 = *(longlong *)(pcVar2 + lVar7 * 8 + -8);
      DAT_18001fee0 = lVar9;
      if (0 < lVar9) {
        lVar10 = 0;
        do {
          *(undefined8 *)
           (pcVar2 + (*(longlong *)(pcVar4 + lVar10 * 8 + lVar7 * 8) + lVar5) * 8 + -8) =
               0x4000000000000000;
          lVar10 = lVar10 + 1;
        } while (lVar10 < lVar9);
      }
    }
    if (0 < DAT_18001feb8) {
      lVar7 = DMS_LOCATI(&DAT_18001feb8);
      lVar5 = DAT_18001fea8;
      pcVar4 = DMS_PLEX_exref;
      lVar9 = *(longlong *)(pcVar2 + lVar7 * 8 + -8);
      DAT_18001feb0 = lVar9;
      if (0 < lVar9) {
        lVar10 = 0;
        do {
          *(undefined8 *)
           (pcVar2 + (*(longlong *)(pcVar4 + lVar10 * 8 + lVar7 * 8) + lVar5) * 8 + -8) =
               0x4008000000000000;
          lVar10 = lVar10 + 1;
        } while (lVar10 < lVar9);
      }
    }
    if (0 < DAT_18001fec8) {
      lVar7 = DMS_LOCATI(&DAT_18001fec8);
      lVar5 = DAT_18001fea8;
      pcVar4 = DMS_PLEX_exref;
      lVar9 = *(longlong *)(pcVar2 + lVar7 * 8 + -8);
      DAT_18001fec0 = lVar9;
      if (0 < lVar9) {
        lVar10 = 0;
        do {
          *(undefined8 *)
           (pcVar2 + (*(longlong *)(pcVar4 + lVar10 * 8 + lVar7 * 8) + lVar5) * 8 + -8) =
               0x4010000000000000;
          lVar10 = lVar10 + 1;
        } while (lVar10 < lVar9);
      }
    }
    if (0 < DAT_18001fe98) {
      lVar7 = DMS_LOCATI(&DAT_18001fe98);
      lVar5 = DAT_18001fea8;
      pcVar4 = DMS_PLEX_exref;
      lVar9 = *(longlong *)(pcVar2 + lVar7 * 8 + -8);
      DAT_18001fe90 = lVar9;
      if (0 < lVar9) {
        lVar10 = 0;
        do {
          *(undefined8 *)
           (pcVar2 + (*(longlong *)(pcVar4 + lVar10 * 8 + lVar7 * 8) + lVar5) * 8 + -8) =
               0x4014000000000000;
          lVar10 = lVar10 + 1;
        } while (lVar10 < lVar9);
      }
    }
    _DAT_18001fea0 = *(undefined8 *)(pcVar2 + DAT_18001fef0 * 8 + 0x30);
    lVar9 = DMS_LOCATI(&DAT_18001fea0);
    uVar8 = *(undefined8 *)(pcVar2 + lVar9 * 8 + -8);
    *(longlong *)(pcVar3 + 0x80) = DAT_18001fee0;
    *(undefined8 *)(pcVar3 + 0x98) = uVar8;
    *(longlong *)(pcVar3 + 0x90) = DAT_18001feb0;
    *(longlong *)(pcVar3 + 0x88) = DAT_18001fed0;
    *(longlong *)(pcVar3 + 0xa0) = DAT_18001fec0;
    lVar9 = DAT_18001fe90;
  }
  *(longlong *)(pcVar3 + 0xa8) = lVar9;
  pcVar2 = DMS_GLOBAL_exref;
  if ((DAT_18001fe88 != 1) || (*(longlong *)(DMS_GLOBAL_exref + 0xe8) != 1)) {
    DAT_18001fe80 = DMS_LOCATI(&DAT_180017758);
    pcVar4 = DMS_PLEX_exref;
    DAT_18001fe78 = *(longlong *)(DMS_PLEX_exref + DAT_18001fe80 * 8 + 0x10);
    if (DAT_18001fe78 == 0) {
      DMS_ALLOCI(&DAT_180017760,&DAT_18001fe78,&DAT_18001fe70);
      *(longlong *)(pcVar4 + DAT_18001fe80 * 8 + 0x10) = DAT_18001fe78;
    }
    else {
      DAT_18001fe70 = DMS_LOCATI(&DAT_18001fe78);
    }
    if (*(longlong *)(pcVar4 + DAT_18001fe70 * 8 + 0x38) == 0) {
      _DAT_18001fe68 = (*(longlong *)(pcVar3 + 0x38) + *(longlong *)(pcVar3 + 0x28)) * 2;
      if (0 < *(longlong *)(pcVar3 + 0x38) + *(longlong *)(pcVar3 + 0x28)) {
        DMS_ALLOCR(&DAT_18001fe68,pcVar4 + DAT_18001fe70 * 8 + 0x38,pcVar2 + 0x80);
      }
    }
    else {
      uVar8 = DMS_LOCATR(pcVar4 + DAT_18001fe70 * 8 + 0x38);
      *(undefined8 *)(pcVar2 + 0x80) = uVar8;
    }
    if (*(longlong *)(pcVar4 + DAT_18001fe70 * 8 + 0x40) == 0) {
      _DAT_18001fe68 = *(longlong *)(pcVar3 + 0x40) + *(longlong *)(pcVar3 + 0x30);
      if (_DAT_18001fe68 != 0 &&
          SCARRY8(*(longlong *)(pcVar3 + 0x40),*(longlong *)(pcVar3 + 0x30)) == _DAT_18001fe68 < 0)
      {
        DMS_ALLOCR(&DAT_18001fe68,pcVar4 + DAT_18001fe70 * 8 + 0x40,pcVar2 + 0x78);
      }
    }
    else {
      uVar8 = DMS_LOCATR(pcVar4 + DAT_18001fe70 * 8 + 0x40);
      *(undefined8 *)(pcVar2 + 0x78) = uVar8;
    }
  }
  return;
}

/* RVA 0x5a90, PPEXEC_INITROUT */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PPEXEC_INITROUT(void)

{
  bool bVar1;
  code *pcVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  
                    /* 0x5a90  12  PPEXEC_INITROUT */
  lVar3 = DMS_LOCATI(&DAT_1800178e0);
  pcVar2 = DMS_PLEX_exref;
  _DAT_18001ff30 = *(undefined8 *)(DMS_PLEX_exref + lVar3 * 8 + 0xb0);
  lVar4 = DMS_LOCATI(&DAT_18001ff30);
  lVar3 = *(longlong *)(pcVar2 + lVar4 * 8 + -8);
  DAT_18001ff20 = lVar3;
  DAT_18001ff28 = lVar4;
  if (0 < lVar3) {
    DAT_18001ff08 = 1;
    lVar5 = lVar3;
    do {
      if (*(longlong *)(pcVar2 + (lVar5 * 3 + lVar4 + DAT_18001ff08) * 8 + -8) == 1) {
        lVar6 = DAT_18001ff08 * 3 + lVar4;
        _DAT_18001ff18 = *(longlong *)(pcVar2 + lVar6 * 8 + -0x18);
        _DAT_18001ff10 = *(longlong *)(pcVar2 + lVar6 * 8 + -0x10);
        lVar7 = 8;
        do {
          if ((_DAT_18001ff18 == *(longlong *)(&UNK_180017778 + lVar7)) &&
             (_DAT_18001ff10 == *(longlong *)((longlong)&DAT_180017780 + lVar7)))
          goto LAB_180005b4f;
          lVar7 = lVar7 + 0x10;
        } while (lVar7 != 0x168);
        _DAT_18001ff00 = *(undefined8 *)(pcVar2 + lVar6 * 8 + -8);
        PPEXEC_PHCCIN((longlong *)&DAT_18001ff18,(longlong *)&DAT_18001ff10,&DAT_18001ff00);
        lVar4 = DAT_18001ff28;
        lVar5 = DAT_18001ff20;
      }
LAB_180005b4f:
      lVar6 = DAT_18001ff08 + 1;
      bVar1 = DAT_18001ff08 < lVar3;
      DAT_18001ff08 = lVar6;
    } while (bVar1);
  }
  return;
}

/* RVA 0x5bd0, FUN_180005bd0 */
void FUN_180005bd0(void)

{
  DAT_18001ff48 = 0;
  DAT_18001ff40 = 0;
  DAT_18001ff38 = 0;
  DMS_BIOCOMPS(&DAT_18001ff40,&DAT_18001ff38,&DAT_18001ff48);
  if (0 < DAT_18001ff48) {
    FUN_180005c50(&DAT_18001ff48,(longlong)(DMS_PLEX_exref + DAT_18001ff40 * 8 + -8),
                  (longlong)(DMS_PLEX_exref + DAT_18001ff38 * 8 + -8));
  }
  return;
}

/* RVA 0x5c50, FUN_180005c50 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_180005c50(longlong *param_1,longlong param_2,longlong param_3)

{
  double dVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  longlong lVar9;
  longlong lVar10;
  longlong lVar11;
  longlong lVar12;
  longlong lVar13;
  longlong lVar14;
  longlong lVar15;
  longlong lVar16;
  longlong lVar17;
  longlong lVar18;
  longlong lVar19;
  longlong lVar20;
  longlong lVar21;
  longlong lVar22;
  longlong lVar23;
  longlong lVar24;
  longlong lVar25;
  longlong lVar26;
  bool bVar27;
  double dVar28;
  code *pcVar29;
  ulonglong uVar30;
  double dVar31;
  double dVar32;
  double dVar33;
  double dVar34;
  longlong lVar35;
  longlong lVar36;
  longlong lVar37;
  
  dVar34 = DAT_180017918;
  dVar33 = DAT_180017910;
  dVar32 = DAT_180017908;
  dVar31 = DAT_180017900;
  uVar30 = _DAT_1800178f0;
  pcVar29 = DMS_PLEX_exref;
  lVar2 = *param_1;
  if (0 < lVar2) {
    lVar3 = *(longlong *)(DMS_IPOFF1_exref + 0xcf8);
    lVar4 = *(longlong *)(DMS_IPOFF1_exref + 0xa28);
    lVar5 = *(longlong *)(DMS_IPOFF1_exref + 0xdb0);
    lVar6 = *(longlong *)(DMS_IPOFF1_exref + 0xef0);
    lVar7 = *(longlong *)(DMS_IPOFF1_exref + 0xbe0);
    lVar8 = *(longlong *)(DMS_IPOFF1_exref + 0xea0);
    lVar9 = *(longlong *)(DMS_IPOFF1_exref + 0x1b0);
    lVar10 = *(longlong *)(DMS_IPOFF1_exref + 0x218);
    lVar11 = *(longlong *)(DMS_IPOFF1_exref + 0x1e0);
    lVar12 = *(longlong *)(DMS_IPOFF1_exref + 0x278);
    lVar13 = *(longlong *)(DMS_IPOFF1_exref + 0xb18);
    lVar14 = *(longlong *)(DMS_IPOFF1_exref + 0x3120);
    lVar15 = *(longlong *)(DMS_IPOFF1_exref + 0xe8);
    dVar1 = *(double *)DMS_RGLOB_exref;
    lVar16 = *(longlong *)(DMS_IPOFF1_exref + 0x148);
    lVar17 = *(longlong *)(DMS_IPOFF1_exref + 0xed0);
    lVar18 = *(longlong *)(DMS_IPOFF1_exref + 0xee8);
    lVar19 = *(longlong *)(DMS_IPOFF1_exref + 0xe58);
    lVar20 = *(longlong *)(DMS_IPOFF1_exref + 0xda0);
    lVar21 = *(longlong *)(DMS_IPOFF1_exref + 0x2c0);
    lVar22 = *(longlong *)(DMS_IPOFF1_exref + 0x988);
    lVar23 = *(longlong *)(DMS_IPOFF1_exref + 0x33b0);
    lVar24 = *(longlong *)(DMS_IPOFF1_exref + 0x33b8);
    lVar25 = *(longlong *)(DMS_IPOFF1_exref + 0xed8);
    lVar26 = *(longlong *)(DMS_IPOFF1_exref + 0xc90);
    lVar35 = 1;
    do {
      lVar36 = *(longlong *)(param_2 + -8 + lVar35 * 8);
      lVar37 = *(longlong *)(param_3 + -8 + lVar35 * 8);
      if (lVar37 == 2) {
        if ((lVar23 != 0) &&
           ((double)(*(ulonglong *)(pcVar29 + (lVar23 + lVar36 * 4) * 8 + -0x20) & uVar30) == dVar1)
           ) {
          lVar37 = lVar23 + lVar36 * 4;
          dVar28 = *(double *)(pcVar29 + (lVar22 + lVar36) * 8 + -8) * dVar33 + dVar34;
          goto LAB_180005fae;
        }
      }
      else if (((lVar37 == 3) && (lVar24 != 0)) &&
              ((double)(*(ulonglong *)(pcVar29 + (lVar24 + lVar36 * 4) * 8 + -0x20) & uVar30) ==
               dVar1)) {
        lVar37 = lVar24 + lVar36 * 4;
        dVar28 = *(double *)(pcVar29 + (lVar22 + lVar36) * 8 + -8) * dVar31 + dVar32;
LAB_180005fae:
        *(double *)(pcVar29 + (lVar37 + -3) * 8 + -8) = dVar28;
      }
      lVar37 = lVar3 + lVar36;
      if ((lVar3 != 0) && (dVar1 == *(double *)(pcVar29 + lVar37 * 8 + -8))) {
        *(undefined8 *)(pcVar29 + lVar37 * 8 + -8) = 0x40a7700000000000;
      }
      lVar37 = lVar4 + lVar36;
      if ((lVar4 != 0) && (dVar1 == *(double *)(pcVar29 + lVar37 * 8 + -8))) {
        *(undefined8 *)(pcVar29 + lVar37 * 8 + -8) = 0x41186a0000000000;
      }
      lVar37 = lVar5 + lVar36;
      if ((lVar5 != 0) && (dVar1 == *(double *)(pcVar29 + lVar37 * 8 + -8))) {
        *(undefined8 *)(pcVar29 + lVar37 * 8 + -8) = 0x404b8db220000000;
      }
      lVar37 = lVar6 + lVar36;
      if ((lVar6 != 0) &&
         (*(double *)(pcVar29 + lVar37 * 8 + -8) == 0.0 ||
          dVar1 == *(double *)(pcVar29 + lVar37 * 8 + -8))) {
        *(undefined8 *)(pcVar29 + lVar37 * 8 + -8) = 0x4095420000000000;
      }
      lVar37 = lVar7 + lVar36;
      if ((lVar7 != 0) && ((double)(*(ulonglong *)(pcVar29 + lVar37 * 8 + -8) & uVar30) == dVar1)) {
        *(undefined8 *)(pcVar29 + lVar37 * 8 + -8) = 0x3fd1930be0000000;
      }
      lVar37 = lVar8 + lVar36;
      if ((lVar8 != 0) && (dVar1 == *(double *)(pcVar29 + lVar37 * 8 + -8))) {
        *(undefined8 *)(pcVar29 + lVar37 * 8 + -8) = 0x3fd3a92a40000000;
      }
      lVar37 = lVar9 + lVar36;
      if ((lVar9 != 0) &&
         (*(double *)(pcVar29 + lVar37 * 8 + -8) == 0.0 ||
          dVar1 == *(double *)(pcVar29 + lVar37 * 8 + -8))) {
        *(undefined8 *)(pcVar29 + lVar37 * 8 + -8) = 0xc1c97e2f20000000;
      }
      lVar37 = lVar10 + lVar36;
      if ((lVar10 != 0) &&
         (*(double *)(pcVar29 + lVar37 * 8 + -8) == 0.0 ||
          dVar1 == *(double *)(pcVar29 + lVar37 * 8 + -8))) {
        *(undefined8 *)(pcVar29 + lVar37 * 8 + -8) = 0xc1d03a3490000000;
      }
      lVar37 = lVar11 + lVar36;
      if ((lVar11 != 0) &&
         (*(double *)(pcVar29 + lVar37 * 8 + -8) == 0.0 ||
          dVar1 == *(double *)(pcVar29 + lVar37 * 8 + -8))) {
        *(undefined8 *)(pcVar29 + lVar37 * 8 + -8) = 0xc1cb1040d0000000;
      }
      lVar37 = lVar12 + lVar36;
      if ((lVar12 != 0) &&
         (*(double *)(pcVar29 + lVar37 * 8 + -8) == 0.0 ||
          dVar1 == *(double *)(pcVar29 + lVar37 * 8 + -8))) {
        *(undefined8 *)(pcVar29 + lVar37 * 8 + -8) = 0xc1d2f94108000000;
      }
      if ((lVar13 != 0) &&
         ((double)(*(ulonglong *)(pcVar29 + (lVar13 + lVar36 * 9 + -9) * 8) & uVar30) == dVar1)) {
        lVar37 = 0;
        do {
          *(undefined8 *)(pcVar29 + lVar37 + lVar36 * 0x48 + lVar13 * 8 + -0x48) =
               *(undefined8 *)((longlong)&DAT_180017b00 + lVar37);
          lVar37 = lVar37 + 8;
        } while (lVar37 != 0x48);
      }
      if ((lVar14 != 0) && (dVar1 == *(double *)(pcVar29 + (lVar36 * 9 + -9 + lVar14) * 8))) {
        lVar37 = 0;
        do {
          *(undefined8 *)(pcVar29 + lVar37 + lVar36 * 0x48 + lVar14 * 8 + -0x48) =
               *(undefined8 *)((longlong)&DAT_180017b00 + lVar37);
          lVar37 = lVar37 + 8;
        } while (lVar37 != 0x48);
      }
      if ((lVar15 != 0) && (dVar1 == *(double *)(pcVar29 + (lVar36 * 0xb + lVar15) * 8 + -0x58))) {
        lVar37 = 0;
        do {
          *(undefined8 *)(pcVar29 + lVar37 + lVar36 * 0x58 + lVar15 * 8 + -0x58) =
               *(undefined8 *)((longlong)&DAT_180017aa0 + lVar37);
          lVar37 = lVar37 + 8;
        } while (lVar37 != 0x58);
      }
      if ((lVar17 != 0) && (dVar1 == *(double *)(pcVar29 + (lVar17 + lVar36 * 5 + -5) * 8))) {
        lVar37 = 0;
        do {
          *(undefined8 *)(pcVar29 + lVar37 + lVar36 * 0x28 + lVar17 * 8 + -0x28) =
               *(undefined8 *)((longlong)&DAT_180017a60 + lVar37);
          lVar37 = lVar37 + 8;
        } while (lVar37 != 0x28);
      }
      if ((lVar18 != 0) && (dVar1 == *(double *)(pcVar29 + (lVar36 * 5 + -5 + lVar18) * 8))) {
        lVar37 = 0;
        do {
          *(undefined8 *)(pcVar29 + lVar37 + lVar36 * 0x28 + lVar18 * 8 + -0x28) =
               *(undefined8 *)((longlong)&DAT_180017a20 + lVar37);
          lVar37 = lVar37 + 8;
        } while (lVar37 != 0x28);
      }
      if ((lVar16 != 0) && (dVar1 == *(double *)(pcVar29 + (lVar16 + lVar36 * 8) * 8 + -0x40))) {
        lVar37 = 0;
        do {
          *(undefined8 *)(pcVar29 + lVar37 + lVar36 * 0x40 + lVar16 * 8 + -0x40) =
               *(undefined8 *)((longlong)&DAT_1800179e0 + lVar37);
          lVar37 = lVar37 + 8;
        } while (lVar37 != 0x40);
      }
      if ((lVar19 != 0) && (dVar1 == *(double *)(pcVar29 + (lVar36 * 7 + lVar19) * 8 + -0x38))) {
        lVar37 = 0;
        do {
          *(undefined8 *)(pcVar29 + lVar37 + lVar36 * 0x38 + lVar19 * 8 + -0x38) =
               *(undefined8 *)((longlong)&DAT_1800179a0 + lVar37);
          lVar37 = lVar37 + 8;
        } while (lVar37 != 0x38);
      }
      lVar37 = lVar20 + lVar36;
      if ((lVar20 != 0) && (dVar1 == *(double *)(pcVar29 + lVar37 * 8 + -8))) {
        *(undefined8 *)(pcVar29 + lVar37 * 8 + -8) = 0x4028f4bc60000000;
      }
      if ((lVar21 != 0) && (dVar1 == *(double *)(pcVar29 + (lVar36 * 5 + lVar21) * 8 + -0x28))) {
        lVar37 = 0;
        do {
          *(undefined8 *)(pcVar29 + lVar37 + lVar36 * 0x28 + lVar21 * 8 + -0x28) =
               *(undefined8 *)((longlong)&DAT_180017960 + lVar37);
          lVar37 = lVar37 + 8;
        } while (lVar37 != 0x28);
      }
      if ((lVar26 != 0) && (dVar1 == *(double *)(pcVar29 + (lVar36 * 7 + lVar26 + -7) * 8))) {
        lVar37 = 0;
        do {
          *(undefined8 *)(pcVar29 + lVar37 + lVar36 * 0x38 + lVar26 * 8 + -0x38) =
               *(undefined8 *)((longlong)&DAT_180017920 + lVar37);
          lVar37 = lVar37 + 8;
        } while (lVar37 != 0x38);
      }
      lVar36 = lVar36 + lVar25;
      if ((lVar25 != 0) && (dVar1 == *(double *)(pcVar29 + lVar36 * 8 + -8))) {
        *(undefined8 *)(pcVar29 + lVar36 * 8 + -8) = 0xc15d9e65c0000000;
      }
      bVar27 = lVar35 < lVar2;
      lVar35 = lVar35 + 1;
    } while (bVar27);
  }
  return;
}

/* RVA 0x65b0, PPEXEC_INTPP */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PPEXEC_INTPP(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 param_4,
                 ulonglong *param_5,undefined8 *param_6)

{
  longlong lVar1;
  code *pcVar2;
  double dVar3;
  double dVar4;
  undefined8 uVar5;
  bool bVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
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
  code *pcVar21;
  code *pcVar22;
  ulonglong uVar23;
  longlong lVar24;
  longlong lVar25;
  undefined8 uVar26;
  longlong lVar27;
  code *pcVar28;
  ulonglong uVar29;
  ulonglong uVar30;
  code *pcVar31;
  longlong lVar32;
  undefined8 *puVar33;
  longlong lVar34;
  code *pcVar35;
  code *pcVar36;
  code *pcVar37;
  undefined4 local_ce;
  undefined2 local_ca;
  longlong local_c8;
  longlong local_c0;
  longlong local_b8 [2];
  code *local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  char *local_90;
  undefined8 local_88 [9];
  
                    /* 0x65b0  13  PPEXEC_INTPP */
  DMS_GET_PRODUCTCODE(&DAT_1800201e8);
  *param_6 = 0;
  pcVar21 = DMS_ERRTWO_exref;
  *(undefined8 *)(DMS_ERRTWO_exref + 0x1b8) = 0xffffffffffffffff;
  *(undefined8 *)DMS_IAPQIT_exref = 0;
  pcVar37 = DMS_GLOBAL_exref;
  *(undefined8 *)(DMS_GLOBAL_exref + 0x158) = 0;
  *(undefined8 *)(ZREP_RPT_exref + 0x160) = 0;
  DMS_WHRAMI();
  ZREP_REPBLK();
  *(undefined8 *)(pcVar37 + 0xb0) = 9;
  pcVar37 = DMS_MAXWRK_exref;
  DAT_180020510 = *(undefined8 *)DMS_MAXWRK_exref;
  DMS_APOPEN(&DAT_180017ba8);
  DMS_APOPEN(&DAT_180017c18);
  *(undefined8 *)pcVar37 = DAT_180020510;
  pcVar37 = DMS_IPERTB_exref;
  *(undefined8 *)DMS_IPERTB_exref = 0;
  pcVar36 = ZMTH_PPSCLR_exref;
  *(undefined8 *)(ZMTH_PPSCLR_exref + 0x1d8) = 0;
  *(undefined8 *)(pcVar21 + 0x158) = 0;
  *(undefined8 *)(pcVar21 + 0x160) = 0;
  *(undefined8 *)(pcVar21 + 0xb0) = 0;
  *(undefined8 *)(pcVar21 + 0xa0) = 0;
  *(undefined8 *)(pcVar21 + 0x98) = 1;
  *(undefined8 *)(pcVar21 + 0x58) = 1;
  *(undefined8 *)(pcVar21 + 0x50) = 0;
  *(undefined8 *)(pcVar21 + 0x1c0) = 0;
  lVar27 = 1;
  pcVar28 = DMS_ERRKNT_exref;
  do {
    lVar32 = -0x60;
    do {
      *(undefined8 *)(pcVar28 + lVar32 + 0x60) = 0;
      lVar32 = lVar32 + 0x20;
    } while (lVar32 != 0);
    lVar27 = lVar27 + 1;
    pcVar28 = pcVar28 + 8;
  } while (lVar27 != 5);
  DAT_180020730 = 5;
  *(undefined8 *)(DMS_ERRKNT_exref + 0x60) = 0;
  *(undefined8 *)(pcVar21 + 0x78) = 0xfe;
  *(undefined8 *)(pcVar21 + 0x1d0) = 0;
  *(undefined8 *)(pcVar36 + 0x20) = 0;
  pcVar28 = DMS_PLEX_exref;
  _PPEXEC_ASPROP = 0;
  RTO_MALLOC_INIT(DMS_PLEX_exref,DMS_PLEX_exref,DMS_PLEX_exref);
  pcVar21 = PPBASE_XFLSHZ_exref;
  _PPEXEC_KBASE = 1;
  *(undefined8 *)PPBASE_XFLSHZ_exref = 0x4054b926e978d4fe;
  *(undefined8 *)(pcVar21 + 8) = 0x476812f9cf7920e3;
  *(undefined8 *)(pcVar21 + 0x10) = 0x38754484932d2e72;
  *(undefined8 *)(pcVar21 + 0x18) = 0x40c3880000000000;
  *(undefined8 *)(pcVar21 + 0x20) = 0x4024000000000000;
  *(undefined8 *)(pcVar21 + 0x28) = 0x426d1a94a2000000;
  *(undefined8 *)(pcVar21 + 0x30) = 0x4054b926e978d4fe;
  *(undefined8 *)(pcVar21 + 0x38) = 0x38aa95a5b7f87a0f;
  *(undefined8 *)(pcVar21 + 0x40) = 0xbf8495182a9930be;
  *(undefined8 *)(pcVar21 + 0x48) = 0x38aa95a5b7f87a0f;
  pcVar21 = PPUTL_EOSTOL_exref;
  *(undefined8 *)PPUTL_EOSTOL_exref = 0x3e45798ee2308c3a;
  pcVar36 = PPUTL_ESEXTR_exref;
  *(undefined8 *)PPUTL_ESEXTR_exref = 0;
  *(undefined8 *)(pcVar36 + 8) = 0;
  *(undefined8 *)(pcVar21 + 8) = 0x3fb999999999999a;
  pcVar36 = DMS_PPRIV_exref;
  _PPEXEC_MWCALC = 1;
  *(undefined8 *)(DMS_PPRIV_exref + 0x50) = 0;
  *(undefined8 *)(pcVar36 + 0x60) = 1;
  *(undefined8 *)(pcVar36 + 0x68) = 2;
  *(undefined8 *)(pcVar36 + 0x70) = 1;
  *(undefined8 *)(pcVar36 + 0x18) = 0x3fef5c28f5c28f5c;
  *(undefined8 *)(pcVar36 + 0x80) = 1;
  *(undefined8 *)(pcVar36 + 0x90) = 1;
  *(undefined8 *)(pcVar36 + 0x4ed0) = 1;
  *(undefined8 *)(pcVar36 + 0x28) = 0x4072a26666666666;
  *(undefined8 *)(pcVar36 + 0x30) = 0x40f8bcd000000000;
  *(undefined8 *)(pcVar36 + 0x4f38) = 1;
  *(undefined8 *)PPSTUB_SRFAPC_exref = 0;
  pcVar21 = DMS_GLOBAL_exref;
  *(undefined8 *)(DMS_GLOBAL_exref + 600) = 0;
  pcVar31 = PPBASE_PING_exref;
  PPEXEC_NBDTAB = 0;
  *(undefined8 *)(PPBASE_PING_exref + 0x30) = 0;
  *(undefined8 *)(pcVar31 + 0x38) = 0;
  *(undefined8 *)(PPBASE_EOSLOG_exref + 0xc0) = 0;
  pcVar31 = PPUTL_ESROOT_exref;
  *(undefined8 *)(PPUTL_ESROOT_exref + 0x40) = 0;
  uVar7 = *(undefined4 *)(pcVar21 + 0x44);
  uVar8 = *(undefined4 *)(pcVar21 + 0x48);
  uVar9 = *(undefined4 *)(pcVar21 + 0x4c);
  *(undefined4 *)(pcVar31 + 0x58) = *(undefined4 *)(pcVar21 + 0x40);
  *(undefined4 *)(pcVar31 + 0x5c) = uVar7;
  *(undefined4 *)(pcVar31 + 0x60) = uVar8;
  *(undefined4 *)(pcVar31 + 100) = uVar9;
  if (*(longlong *)(pcVar36 + 0x4f00) != 0x1f83) {
    *(undefined8 *)(pcVar36 + 0x4f00) = 0;
  }
  *(undefined8 *)(pcVar36 + 0x4f30) = 0;
  pcVar21 = PPMON_IGSAVE_exref;
  _DAT_18001ffd0 = 0;
  uRam000000018001ffd8 = 0;
  _DAT_18001ffe0 = 0;
  *(undefined8 *)PPMON_IGSAVE_exref = *(undefined8 *)DMS_RGLOB_exref;
  *(undefined8 *)(pcVar21 + 8) = 0;
  pcVar21 = DMS_FLES_exref;
  uVar26 = *(undefined8 *)(DMS_FLES_exref + 0x18);
  uVar5 = *(undefined8 *)(DMS_FLES_exref + 0x38);
  lVar27 = 1;
  do {
    *(longlong *)(pcVar21 + lVar27 * 8 + -8) = lVar27;
    lVar27 = lVar27 + 1;
  } while (lVar27 != 0x25);
  DAT_180020730 = 0x25;
  *(undefined8 *)pcVar21 = 5;
  *(undefined8 *)(pcVar21 + 0x40) = 0;
  *(undefined8 *)(pcVar21 + 0x18) = uVar26;
  *(undefined8 *)(pcVar21 + 0x38) = uVar5;
  *(undefined8 *)(pcVar21 + 0x30) = 0x15;
  *(undefined8 *)(pcVar21 + 0x50) = 0x1e;
  *(undefined8 *)(pcVar21 + 0x60) = *param_1;
  *(undefined8 *)(pcVar21 + 0x68) = *param_3;
  *(undefined8 *)(pcVar21 + 0x90) = 0x21;
  *(undefined8 *)(pcVar21 + 0x98) = 0x22;
  *(undefined8 *)(pcVar21 + 0xe0) = 0x20;
  *(undefined8 *)(pcVar21 + 0xf8) = 0x30;
  *(undefined8 *)(pcVar21 + 0x100) = 0x13;
  *(undefined8 *)(pcVar21 + 0x108) = 0x14;
  *(undefined8 *)(pcVar21 + 0x110) = 0x12;
  *(undefined8 *)(pcVar21 + 0x118) = *param_2;
  *(undefined8 *)pcVar37 = 0;
  *(undefined8 *)(pcVar37 + 8) = 0;
  *(undefined8 *)(pcVar37 + 0x10) = 0;
  pcVar37 = DMS_INITV_exref;
  *(undefined8 *)(DMS_INITV_exref + 0x10) = 0xffffffffdddddddd;
  *(undefined8 *)pcVar37 = 0;
  *(undefined8 *)(pcVar37 + 8) = 0;
  *(undefined8 *)(pcVar37 + 0x18) = 0x4733426172c74d82;
  pcVar37 = PPUTL_TGSSIG_exref;
  *(undefined8 *)PPUTL_TGSSIG_exref = 0;
  *(undefined8 *)(pcVar37 + 8) = 0;
  *(undefined8 *)(pcVar37 + 0x10) = 0;
  DMS_INITVMMF();
  pcVar37 = DMS_DMS_exref;
  *(undefined8 *)(DMS_DMS_exref + 0x80) = 100000000;
  *(undefined8 *)(pcVar37 + 0x30) = 99999999;
  *(undefined8 *)(DMS_TINTRN_exref + 0x20) = 99999999;
  *(undefined8 *)DMS_ICRD_exref = 1;
  *(undefined8 *)(pcVar37 + 0x60) = 10000;
  *(undefined8 *)(pcVar37 + 0x68) = 100000;
  pcVar37 = DMS_GLOBAL_exref;
  *(undefined8 *)(DMS_GLOBAL_exref + 0x30) = 4;
  *(undefined8 *)(pcVar37 + 0x20) = *(undefined8 *)(pcVar21 + 0x60);
  DMS_GETASPTOP(&DAT_180020248,0xff);
  lVar27 = DMS_STRLEN(&DAT_180020248,0xff);
  uVar9 = s__xeq_sdffil_aprsdf_180017b90._12_4_;
  uVar8 = s__xeq_sdffil_aprsdf_180017b90._8_4_;
  uVar7 = s__xeq_sdffil_aprsdf_180017b90._4_4_;
  if (DAT_1800201e8 == 2) {
    *(undefined4 *)(&DAT_180020248 + lVar27) = s__xeq_sdffil_aprsdf_180017b90._0_4_;
    *(undefined4 *)(lVar27 + 0x18002024c) = uVar7;
    *(undefined4 *)(lVar27 + 0x180020250) = uVar8;
    *(undefined4 *)(lVar27 + 0x180020254) = uVar9;
    *(undefined2 *)(&DAT_180020258 + lVar27) = 0x6664;
  }
  else {
    *(undefined8 *)(&DAT_18002024f + lVar27) = 0x6664732e6c696666;
    builtin_strncpy(&DAT_180020248 + lVar27,"/xeq/sdf",8);
  }
  if (*(longlong *)(DMS_VMM2_exref + 0x140) == 0) {
    DMS_ASGOPN(&DAT_180020248,&DAT_180017c20,&DAT_180017bf0,&DAT_180017c18,&DAT_180017bf0,
               &DAT_1800204c0,0xff);
  }
  _DAT_180020500 = 1;
  _DAT_180020508 = 3;
  uVar29 = *param_5;
  _DAT_1800204e0 = (ulonglong)((longlong)uVar29 < -0x191 || *(longlong *)(DMS_PPSLV_exref + 8) == 1)
  ;
  pcVar35 = DMS_FNAMES_exref + 0x1800;
  _DAT_1800204e8 = _DAT_1800204e0;
  DMS_ASGOPN(pcVar35,&DAT_180017c20,&DAT_180020500,&DAT_1800204e0,&DAT_180017bf0,&DAT_1800204c0,
             0x100);
  lVar27 = DMS_LOCATI(&DAT_180017bf0);
  pcVar31 = DMS_PRDIR_exref;
  DAT_180020728 = lVar27;
  *(undefined8 *)(DMS_PRDIR_exref + 0xf0) = *(undefined8 *)(pcVar28 + lVar27 * 8 + 0x348);
  uVar26 = *(undefined8 *)(pcVar28 + lVar27 * 8 + 0x350 + 8);
  *(undefined8 *)(pcVar31 + 0xf8) = *(undefined8 *)(pcVar28 + lVar27 * 8 + 0x350);
  *(undefined8 *)(pcVar31 + 0x100) = uVar26;
  uVar26 = *(undefined8 *)(pcVar28 + lVar27 * 8 + 0x70);
  *(undefined8 *)(pcVar31 + 0x60) = *(undefined8 *)(pcVar28 + lVar27 * 8 + 0x18);
  uVar5 = *(undefined8 *)(pcVar28 + lVar27 * 8 + 0x618 + 8);
  *(undefined8 *)(pcVar31 + 0x118) = *(undefined8 *)(pcVar28 + lVar27 * 8 + 0x618);
  *(undefined8 *)(pcVar31 + 0x120) = uVar5;
  pcVar37 = pcVar28 + lVar27 * 8 + 0x268;
  uVar7 = *(undefined4 *)(pcVar37 + 4);
  uVar8 = *(undefined4 *)(pcVar37 + 8);
  uVar9 = *(undefined4 *)(pcVar37 + 0xc);
  *(undefined4 *)(pcVar31 + 0x20) = *(undefined4 *)pcVar37;
  *(undefined4 *)(pcVar31 + 0x24) = uVar7;
  *(undefined4 *)(pcVar31 + 0x28) = uVar8;
  *(undefined4 *)(pcVar31 + 0x2c) = uVar9;
  *(undefined8 *)(pcVar31 + 0xa0) = uVar26;
  pcVar37 = DMS_DMS_exref;
  if (*(longlong *)(DMS_DMS_exref + 0x2088) == 0) {
    DMS_ASGOPN(pcVar35,&DAT_180017c20,&DAT_180017bb0,&DAT_180017bf0,&DAT_180017c18,&DAT_1800204c0,
               0x100);
    lVar27 = *(longlong *)(pcVar37 + 0x2088);
    pcVar31 = DMS_VMM2_exref;
    pcVar35 = DMS_GLOBAL_exref;
  }
  else {
    lVar27 = DMS_PCS_INITPLEX();
    pcVar35 = DMS_GLOBAL_exref;
    if ((lVar27 == 0) &&
       (lVar27 = DMS_IRRCHK(s_SOLV_INT_INTP_P_6_18001e680 + 0x20,&DAT_180017c18,&DAT_180017c20,
                            DMS_GLOBAL_exref + 0x28,DMS_GLOBAL_exref + 0x38,&DAT_180017c18,
                            &DAT_180017c18,&DAT_180017bf0), lVar27 != 0)) {
      local_88[0] = 0;
      local_ce = 0x4380638;
      local_ca = 1;
      local_b8[1] = 800;
      local_a8 = DMS_ERROUT_exref;
      local_a0 = 0x50;
      local_98 = 0x28;
      local_90 = "FAILED TO GET PCS UNMNAGED BRIDGE HANDLE/xeq/sdffil.sdf";
      for_write_int_fmt(local_88,0x801208384ff00,&local_ce,local_b8 + 1,&DAT_18001e740);
      DMS_ERRPRT(&DAT_180017c20);
    }
    DMS_ICKFPE2();
    pcVar31 = DMS_VMM2_exref;
    *(undefined8 *)(DMS_VMM2_exref + 0x138) = 1;
    lVar27 = DMS_LOCATI(&DAT_180017c20);
    pcVar37 = DMS_DMS_exref;
    uVar26 = *(undefined8 *)(pcVar28 + lVar27 * 8);
    *(undefined8 *)(DMS_DMS_exref + 0x50) = *(undefined8 *)(pcVar28 + lVar27 * 8 + -8);
    *(undefined8 *)(pcVar37 + 0x28) = uVar26;
    *(undefined8 *)(pcVar37 + 0x40) = *(undefined8 *)(pcVar28 + lVar27 * 8 + 8);
    *(undefined8 *)(pcVar37 + 0x38) = *(undefined8 *)(pcVar28 + lVar27 * 8 + 0x10);
    *(undefined8 *)(pcVar37 + 0x30) = *(undefined8 *)(pcVar28 + lVar27 * 8 + 0x18);
    *(undefined8 *)(pcVar37 + 0x48) = *(undefined8 *)(pcVar28 + lVar27 * 8 + 0x20);
    uVar26 = *(undefined8 *)(pcVar28 + lVar27 * 8 + 0x28 + 8);
    *(undefined8 *)pcVar37 = *(undefined8 *)(pcVar28 + lVar27 * 8 + 0x28);
    *(undefined8 *)(pcVar37 + 8) = uVar26;
    *(undefined8 *)(pcVar37 + 0x20) = *(undefined8 *)(pcVar28 + lVar27 * 8 + 0x40);
    *(undefined8 *)(pcVar37 + 0x70) = *(undefined8 *)(pcVar28 + lVar27 * 8 + 0x48);
    pcVar22 = DMS_TINFO_exref;
    pcVar2 = pcVar28 + lVar27 * 8 + 0x98;
    uVar7 = *(undefined4 *)(pcVar2 + 4);
    uVar8 = *(undefined4 *)(pcVar2 + 8);
    uVar9 = *(undefined4 *)(pcVar2 + 0xc);
    uVar26 = *(undefined8 *)(pcVar28 + lVar27 * 8 + 0xa8);
    uVar5 = *(undefined8 *)(pcVar28 + lVar27 * 8 + 0xa8 + 8);
    uVar10 = *(undefined8 *)(pcVar28 + lVar27 * 8 + 0xb8);
    uVar11 = *(undefined8 *)(pcVar28 + lVar27 * 8 + 0xb8 + 8);
    uVar12 = *(undefined8 *)(pcVar28 + lVar27 * 8 + 200);
    uVar13 = *(undefined8 *)(pcVar28 + lVar27 * 8 + 200 + 8);
    *(undefined4 *)(DMS_TINFO_exref + 0x98) = *(undefined4 *)pcVar2;
    *(undefined4 *)(pcVar22 + 0x9c) = uVar7;
    *(undefined4 *)(pcVar22 + 0xa0) = uVar8;
    *(undefined4 *)(pcVar22 + 0xa4) = uVar9;
    *(undefined8 *)(pcVar22 + 0xa8) = uVar26;
    *(undefined8 *)(pcVar22 + 0xb0) = uVar5;
    *(undefined8 *)(pcVar22 + 0xb8) = uVar10;
    *(undefined8 *)(pcVar22 + 0xc0) = uVar11;
    *(undefined8 *)(pcVar22 + 200) = uVar12;
    *(undefined8 *)(pcVar22 + 0xd0) = uVar13;
    lVar27 = *(longlong *)(pcVar37 + 0x2088);
    if (lVar27 == 2) {
      return;
    }
  }
  pcVar2 = DMS_RGLOB_exref;
  uVar30 = -uVar29;
  if ((longlong)-uVar29 < 0) {
    uVar30 = uVar29;
  }
  lVar32 = (ulonglong)(uVar30 < 0x192) * 3 + 1;
  if (*(longlong *)(DMS_PPSLV_exref + 8) == 1) {
    lVar32 = 1;
  }
  lVar24 = 1;
  if (lVar27 == 0) {
    lVar24 = lVar32;
  }
  *(longlong *)(pcVar31 + 0x30) = lVar24;
  DAT_180020728 = DMS_LOCATI(&DAT_180017bf0);
  _DAT_180020720 = *(ulonglong *)(pcVar28 + DAT_180020728 * 8 + 0x630);
  uVar29 = *(ulonglong *)(pcVar37 + 0x80);
  if ((_DAT_180020720 | uVar29) >> 0x20 == 0) {
    uVar29 = (_DAT_180020720 & 0xffffffff) % (uVar29 & 0xffffffff);
  }
  else {
    uVar29 = (longlong)_DAT_180020720 % (longlong)uVar29;
  }
  if (uVar29 != 3) {
    *param_6 = 1;
    return;
  }
  DAT_180020718 = DMS_LOCATI(&DAT_180020720);
  APHIERSTK_INIT_F();
  _DAT_1800201f0 = APHIER_GETTOPCNTR_F();
  APHIERSTK_PUSH_F(&DAT_1800201f0);
  _DAT_180020450 = *(longlong *)(pcVar28 + DAT_180020718 * 8 + 0x170);
  if (0 < _DAT_180020450) {
    lVar27 = DMS_LOCATI(&DAT_180020450);
    pcVar31 = DMS_PLEX_exref;
    _DAT_180020448 = *(longlong *)(DMS_PLEX_exref + lVar27 * 8 + 8);
    if (0 < _DAT_180020448) {
      lVar27 = DMS_LOCATI(&DAT_180020448);
      DMS_INT2CS(&DAT_180017bb8,pcVar31 + (lVar27 + *(longlong *)(pcVar31 + lVar27 * 8 + -8)) * 8,
                 &DAT_180020240,&DAT_180020347,0xff);
      pcVar31 = DMS_FNAMES_exref;
      FUN_180008d20();
      pcVar31[0x49ff] = (code)0x20;
      FUN_180008d20();
      pcVar31[0x55ff] = (code)0x20;
    }
  }
  lVar27 = DAT_180020718;
  *(undefined8 *)(pcVar28 + DAT_180020718 * 8 + 200) = 0;
  uVar29 = *(ulonglong *)(pcVar28 + lVar27 * 8 + 0xa8);
  uVar30 = *(ulonglong *)(pcVar37 + 0x80);
  if ((uVar29 | uVar30) >> 0x20 == 0) {
    uVar23 = (uVar29 & 0xffffffff) / (uVar30 & 0xffffffff);
    uVar29 = (uVar29 & 0xffffffff) % (uVar30 & 0xffffffff);
  }
  else {
    uVar23 = (longlong)uVar29 / (longlong)uVar30;
    uVar29 = (longlong)uVar29 % (longlong)uVar30;
  }
  if (uVar23 == 4) {
    *(undefined8 *)(DMS_PLEX_exref + lVar27 * 8 + 0xa8) = 0;
  }
  DAT_180020728 = DMS_LOCATI(&DAT_180017bf0,uVar29);
  _DAT_180020710 = *(undefined8 *)(pcVar28 + DAT_180020728 * 8 + 0x4f0);
  lVar27 = DMS_LOCATI(&DAT_180020710);
  if (*(longlong *)(pcVar28 + lVar27 * 8 + 0x10) != 0) {
    PPBASE_ES15B1();
    PPBASE_ES15B2();
    PPBASE_ES15B3();
    PPBASE_ES15B4();
    PPBASE_ES15B5();
  }
  _DAT_180020708 = *(undefined8 *)(pcVar28 + DAT_180020728 * 8 + 0x48);
  DMS_LOCATM(&DAT_180020708,&DAT_180020700,&DAT_1800206f8,&DAT_1800206f0);
  DMS_LENTHM(&DAT_180020708,&DAT_1800206e8,&DAT_1800206e0);
  uVar29 = DAT_1800206e8;
  pcVar37 = DMS_DMS_exref;
  if (0 < (longlong)DAT_1800206e8) {
    if (DAT_1800206e8 < 0xd) {
      lVar27 = DAT_180020700 * 8;
      uVar30 = 0;
      do {
        *(undefined8 *)(pcVar35 + uVar30 * 8) = *(undefined8 *)(pcVar28 + uVar30 * 8 + lVar27 + -8);
        uVar30 = uVar30 + 1;
      } while (uVar29 != uVar30);
    }
    else {
      FUN_180008d20();
    }
  }
  uVar29 = DAT_1800206e0;
  DAT_180020730 = 1;
  if (0 < (longlong)DAT_1800206e0) {
    if (DAT_1800206e0 < 0xd) {
      lVar27 = DAT_1800206f8 * 8;
      uVar30 = 0;
      do {
        *(undefined8 *)(pcVar2 + uVar30 * 8) = *(undefined8 *)(pcVar28 + uVar30 * 8 + lVar27 + -8);
        uVar30 = uVar30 + 1;
      } while (uVar29 != uVar30);
    }
    else {
      FUN_180008d20();
    }
    DAT_180020730 = uVar29 + 1;
  }
  lVar27 = PPEXEC_PCS;
  if (PPEXEC_PCS < *(longlong *)(pcVar35 + 0x68)) {
    lVar27 = *(longlong *)(pcVar35 + 0x68);
  }
  *(longlong *)(pcVar35 + 0x68) = lVar27;
  _PPEXEC_ESSAVE = *(undefined8 *)pcVar2;
  _DAT_18001ffa8 = _PPEXEC_ESSAVE;
  _DAT_18001ffb0 = _PPEXEC_ESSAVE;
  _DAT_18001ffb8 = _PPEXEC_ESSAVE;
  _DAT_18001ffc0 = _PPEXEC_ESSAVE;
  _DAT_18001ffc8 = _PPEXEC_ESSAVE;
  *(undefined8 *)(pcVar35 + 0x20) = *(undefined8 *)(pcVar21 + 0x60);
  *(undefined8 *)(pcVar35 + 0x1a8) = 9;
  *(undefined8 *)(pcVar35 + 0xb0) = 9;
  UMOD_USRVRN();
  pcVar31 = DMS_TINFO_exref;
  DMS_GETVER(&DAT_180017bf0,&DAT_180017bc0,DMS_TINFO_exref + 2000);
  DMS_GETVER(&DAT_180017bc8,&DAT_180017be8,pcVar31 + 0x7f8);
  if (*(longlong *)(pcVar37 + 0x2088) == 0) {
    DMS_CHKVER();
  }
  _DAT_180020720 = *(ulonglong *)(pcVar28 + DAT_180020728 * 8 + 0x630);
  DAT_180020718 = DMS_LOCATI(&DAT_180020720);
  pcVar37 = DMS_DBGOUT_exref;
  _DAT_1800201e0 = *(longlong *)(pcVar28 + DAT_180020718 * 8 + 0x1b8);
  if (_DAT_1800201e0 == 0) {
    FUN_180008df0();
    *(undefined8 *)(pcVar37 + 0x228) = 1;
    uVar5 = *(undefined8 *)(pcVar35 + 0x38);
    uVar26 = *(undefined8 *)pcVar2;
    lVar27 = -10;
    do {
      *(undefined8 *)(pcVar37 + lVar27 * 8 + 0xa0) = uVar5;
      *(undefined8 *)(pcVar37 + lVar27 * 8 + 0x50) = uVar26;
      lVar27 = lVar27 + 1;
    } while (lVar27 != 0);
  }
  else {
    DMS_LOCATM(&DAT_1800201e0,&DAT_1800201d8,&DAT_1800201d0,&DAT_1800206f0);
    lVar32 = DAT_1800201d8;
    pcVar22 = DMS_DBGOUT_exref;
    FUN_180008d20();
    lVar27 = DAT_1800201d0;
    uVar26 = *(undefined8 *)(pcVar28 + lVar32 * 8 + 0x318 + 8);
    uVar5 = *(undefined8 *)(pcVar28 + lVar32 * 8 + 0x328);
    uVar10 = *(undefined8 *)(pcVar28 + lVar32 * 8 + 0x328 + 8);
    uVar11 = *(undefined8 *)(pcVar28 + lVar32 * 8 + 0x338);
    uVar12 = *(undefined8 *)(pcVar28 + lVar32 * 8 + 0x338 + 8);
    uVar13 = *(undefined8 *)(pcVar28 + lVar32 * 8 + 0x348);
    uVar14 = *(undefined8 *)(pcVar28 + lVar32 * 8 + 0x348 + 8);
    *(undefined8 *)(pcVar22 + 0x50) = *(undefined8 *)(pcVar28 + lVar32 * 8 + 0x318);
    *(undefined8 *)(pcVar22 + 0x58) = uVar26;
    uVar26 = *(undefined8 *)(pcVar28 + lVar27 * 8 + -8 + 8);
    uVar15 = *(undefined8 *)(pcVar28 + lVar27 * 8 + 8);
    uVar16 = *(undefined8 *)(pcVar28 + lVar27 * 8 + 8 + 8);
    uVar17 = *(undefined8 *)(pcVar28 + lVar27 * 8 + 0x18);
    uVar18 = *(undefined8 *)(pcVar28 + lVar27 * 8 + 0x18 + 8);
    uVar19 = *(undefined8 *)(pcVar28 + lVar27 * 8 + 0x28);
    uVar20 = *(undefined8 *)(pcVar28 + lVar27 * 8 + 0x28 + 8);
    *(undefined8 *)pcVar22 = *(undefined8 *)(pcVar28 + lVar27 * 8 + -8);
    *(undefined8 *)(pcVar22 + 8) = uVar26;
    *(undefined8 *)(pcVar22 + 0x60) = uVar5;
    *(undefined8 *)(pcVar22 + 0x68) = uVar10;
    *(undefined8 *)(pcVar22 + 0x10) = uVar15;
    *(undefined8 *)(pcVar22 + 0x18) = uVar16;
    *(undefined8 *)(pcVar22 + 0x70) = uVar11;
    *(undefined8 *)(pcVar22 + 0x78) = uVar12;
    *(undefined8 *)(pcVar22 + 0x20) = uVar17;
    *(undefined8 *)(pcVar22 + 0x28) = uVar18;
    *(undefined8 *)(pcVar22 + 0x80) = uVar13;
    *(undefined8 *)(pcVar22 + 0x88) = uVar14;
    *(undefined8 *)(pcVar22 + 0x30) = uVar19;
    *(undefined8 *)(pcVar22 + 0x38) = uVar20;
    uVar26 = *(undefined8 *)(pcVar28 + lVar32 * 8 + 0x358 + 8);
    *(undefined8 *)(pcVar22 + 0x90) = *(undefined8 *)(pcVar28 + lVar32 * 8 + 0x358);
    *(undefined8 *)(pcVar22 + 0x98) = uVar26;
    pcVar37 = pcVar28 + lVar27 * 8 + 0x38;
    uVar7 = *(undefined4 *)(pcVar37 + 4);
    uVar8 = *(undefined4 *)(pcVar37 + 8);
    uVar9 = *(undefined4 *)(pcVar37 + 0xc);
    *(undefined4 *)(pcVar22 + 0x40) = *(undefined4 *)pcVar37;
    *(undefined4 *)(pcVar22 + 0x44) = uVar7;
    *(undefined4 *)(pcVar22 + 0x48) = uVar8;
    *(undefined4 *)(pcVar22 + 0x4c) = uVar9;
  }
  DAT_180020730 = 0xb;
  _DAT_180020720 = *(ulonglong *)(pcVar28 + DAT_180020728 * 8 + 0x630);
  lVar32 = DMS_LOCATI(&DAT_180020720);
  lVar27 = DAT_180020728;
  DAT_180020718 = lVar32;
  *(undefined8 *)(pcVar28 + DAT_180020728 * 8 + 0x470) = 0;
  *(undefined8 *)(pcVar28 + lVar27 * 8 + 0x478) = 0;
  _DAT_1800206d8 = *(longlong *)(pcVar28 + lVar32 * 8 + 0xd0);
  if (_DAT_1800206d8 != 0) {
    DMS_LOCATM(&DAT_1800206d8,&DAT_1800206d0,&DAT_1800206c8,&DAT_1800206f0);
    lVar25 = DAT_1800206d0;
    lVar24 = DAT_1800206c8;
    pcVar37 = PPUTL_FLASHD_exref;
    lVar27 = DAT_1800206d0 * 8;
    lVar32 = DAT_1800206c8 * 8;
    uVar29 = 0;
    do {
      uVar30 = uVar29 + 1;
      *(undefined8 *)(pcVar37 + uVar29 * 8) = *(undefined8 *)(pcVar28 + uVar29 * 8 + lVar32 + -8);
      pcVar22 = PPUTL_EOSTOL_exref;
      if ((longlong)uVar30 < 8) {
        *(undefined8 *)(pcVar37 + uVar29 * 8 + 0x68) =
             *(undefined8 *)(pcVar28 + uVar29 * 8 + lVar27 + -8);
      }
      else if (0xc < uVar30) goto code_r0x0001800074fb;
      uVar29 = uVar30;
    } while( true );
  }
LAB_1800075eb:
  DAT_180020730 = 1;
  pcVar36 = DMS_GLOBAL_exref + 0x120;
  pcVar37 = DMS_ERRTWO_exref + 0x78;
  do {
    DMS_MVBYT(pcVar37,pcVar36,pcVar37,&DAT_180020730);
    pcVar2 = DMS_PLEX_exref;
    lVar27 = DAT_180020730 + 1;
    bVar6 = DAT_180020730 < 4;
    DAT_180020730 = lVar27;
  } while (bVar6);
  if (*(longlong *)(DMS_DMS_exref + 0x2088) == 0) {
    DAT_1800206b8 = *(longlong *)(DMS_PLEX_exref + DAT_180020728 * 8 + 0x1b0);
    DAT_1800206c0 = *(longlong *)(DMS_PLEX_exref + DAT_180020728 * 8 + 0x1b8);
    DMS_TREAD(&DAT_180017bf0,&DAT_180020228,&DAT_180020220,&DAT_1800206b0,&DAT_1800206f0);
    if (DAT_1800206c0 == 0) {
      _DAT_180020238 = *(undefined8 *)(pcVar2 + DAT_180020220 * 8 + 0x160);
      DMS_TCOPY(&DAT_180020238,&DAT_1800206c0,ZREP_HEAD_exref + 0xb8,&DAT_1800206b0,&DAT_1800206f0);
      *(longlong *)(pcVar2 + DAT_180020728 * 8 + 0x1b8) = DAT_1800206c0;
      _DAT_180020230 = *(undefined8 *)(pcVar2 + DAT_180020220 * 8 + 0x168);
      DMS_TCOPY(&DAT_180020230,&DAT_180020218,&DAT_180020210,&DAT_1800206b0,&DAT_1800206f0);
      *(undefined8 *)(pcVar2 + DAT_180020728 * 8 + 0x1d8) = DAT_180020218;
      DMS_LENTHM(&DAT_180020218,&DAT_180020648,&DAT_180020640);
      DMS_ALLOCM(&DAT_180020648,&DAT_180020640,&DAT_180020208,&DAT_180020670,&DAT_1800206b0,
                 &DAT_1800206f0);
      *(undefined8 *)(pcVar2 + DAT_180020728 * 8 + 0x1e0) = DAT_180020208;
      pcVar37 = ZREP_HEAD_exref;
      DAT_180020638 = DAT_180020670;
      DMS_ALLOCM(&DAT_180020648,&DAT_180020640,&DAT_1800206b8,ZREP_HEAD_exref + 0xc0,&DAT_1800206b0,
                 &DAT_1800206f0);
      uVar29 = *(ulonglong *)(DMS_DMS_exref + 8);
      uVar30 = DAT_180020640 * uVar29 + _DAT_180020648;
      *(longlong *)(pcVar2 + DAT_180020728 * 8 + 0x1b0) = DAT_1800206b8;
      if ((uVar30 | uVar29) >> 0x20 == 0) {
        uVar23 = (uVar30 & 0xffffffff) % (uVar29 & 0xffffffff);
      }
      else {
        uVar23 = (longlong)uVar30 % (longlong)uVar29;
      }
      _DAT_180020200 = uVar29 - uVar23;
      if (uVar23 == 0) {
        _DAT_180020200 = 0;
      }
      _DAT_180020200 = uVar30 + _DAT_180020200;
      DMS_COPY(pcVar2 + DAT_180020210 * 8 + -8,pcVar2 + *(longlong *)(pcVar37 + 0xc0) * 8 + -8,
               &DAT_180020200);
      DMS_COPY(pcVar2 + DAT_180020210 * 8 + -8,pcVar2 + DAT_180020638 * 8 + -8,&DAT_180020200);
      lVar27 = *(longlong *)(pcVar2 + *(longlong *)(pcVar37 + 0xc0) * 8 + 8);
      DAT_180020730 = 1;
      if (0 < lVar27) {
        do {
          lVar32 = DMS_IKWTXY(&DAT_180020638,&DAT_180020730,&DAT_180017c20);
          *(undefined8 *)(pcVar2 + lVar32 * 8 + -8) = 0x3ff0000000000000;
          lVar32 = DMS_IKWTXY(&DAT_180020638,&DAT_180020730,&DAT_180017bf0);
          *(undefined8 *)(pcVar2 + lVar32 * 8 + -8) = 0;
          lVar32 = DAT_180020730 + 1;
          bVar6 = DAT_180020730 < lVar27;
          DAT_180020730 = lVar32;
        } while (bVar6);
      }
    }
    else {
      DMS_LOCATM(&DAT_1800206c0,ZREP_HEAD_exref + 0xb8,&DAT_1800206b0,&DAT_1800206f0);
    }
    pcVar35 = DMS_GLOBAL_exref;
    if (DAT_1800206b8 != 0) {
      DMS_LOCATM(&DAT_1800206b8,ZREP_HEAD_exref + 0xc0,&DAT_1800206b0,&DAT_1800206f0);
    }
  }
  pcVar2 = DMS_ERRTWO_exref;
  pcVar36 = DMS_RGLOB_exref;
  pcVar37 = DMS_PGMNFO_exref;
  if (*(longlong *)(pcVar35 + 0x1a8) != 1) {
    uVar29 = *(ulonglong *)(pcVar31 + 0x848);
    DAT_180020730 = 1;
    if (0 < (longlong)uVar29) {
      if (uVar29 < 0xd) {
        uVar30 = 0;
        do {
          *(undefined8 *)(pcVar37 + uVar30 * 8 + 0x18) = 0x2020202020202020;
          uVar30 = uVar30 + 1;
        } while (uVar29 != uVar30);
      }
      else {
        FUN_180008df0();
      }
      DAT_180020730 = uVar29 + 1;
    }
  }
  uVar26 = *(undefined8 *)(pcVar35 + 0x38);
  *(undefined8 *)(pcVar2 + 0x1c8) = uVar26;
  pcVar37 = PPEXEC_USER_exref;
  *(undefined8 *)PPEXEC_USER_exref = *(undefined8 *)pcVar36;
  *(undefined8 *)(pcVar37 + 8) = uVar26;
  *(undefined8 *)(pcVar37 + 0x10) = *(undefined8 *)(pcVar35 + 0x58);
  *(undefined8 *)(pcVar37 + 0x18) = *(undefined8 *)(pcVar35 + 0x100);
  *(undefined8 *)(pcVar37 + 0x20) = *(undefined8 *)(pcVar35 + 0xb8);
  *(undefined8 *)(pcVar37 + 0x28) = 0;
  *(undefined8 *)(pcVar37 + 0x30) = *(undefined8 *)(pcVar35 + 0x28);
  *(undefined8 *)(pcVar37 + 0x38) = *(undefined8 *)(pcVar35 + 0x50);
  uVar26 = *(undefined8 *)(pcVar35 + 0x20);
  *(undefined8 *)(pcVar37 + 0x40) = *(undefined8 *)(pcVar35 + 0x10);
  *(undefined8 *)(pcVar37 + 0x48) = uVar26;
  uVar26 = *(undefined8 *)(pcVar21 + 0x118);
  *(undefined8 *)(pcVar37 + 0x50) = *(undefined8 *)(pcVar21 + 0x68);
  *(undefined8 *)(pcVar37 + 0x58) = uVar26;
  *(undefined8 *)(pcVar37 + 0x60) = *(undefined8 *)(pcVar35 + 0x108);
  DMS_CLRCMN();
  if ((*(longlong *)(pcVar35 + 0x110) == 3) && (*(longlong *)(pcVar35 + 0x198) == 1)) {
    DMS_ERRSET(&DAT_180017bd0,&DAT_180017bd8,&DAT_180017c18,&DAT_180017c18,&DAT_180017c18,
               &DAT_180017be0);
  }
  pcVar37 = PPUTL_PPGLOB_exref;
  *(undefined8 *)PPUTL_PPGLOB_exref = 0x40f8bcd000000000;
  *(undefined8 *)(pcVar37 + 8) = 0x4072a26666666666;
  *(undefined8 *)(pcVar37 + 0x10) = 0x40c03d2a3d70a3d7;
  *(undefined8 *)(pcVar37 + 0x18) = 0x3b30b060f018b39b;
  *(undefined8 *)(DMS_RPTGLB_exref + 0x60) = 0x3ff0000000000000;
  lVar27 = 0;
  do {
    *(undefined8 *)((longlong)&PPEXEC_PPROY + lVar27) = 0x3ff0000000000000;
    lVar27 = lVar27 + 8;
  } while (lVar27 != 0x48);
  DAT_180020730 = 10;
  _DAT_1800206a8 = *(longlong *)(pcVar28 + DAT_180020728 * 8 + 0xe0);
  if (0 < _DAT_1800206a8) {
    _DAT_1800206a0 = DMS_LOCATI(&DAT_1800206a8);
    lVar27 = *(longlong *)(pcVar28 + _DAT_1800206a0 * 8 + -8);
    if (0 < lVar27) {
      DAT_180020730 = 1;
      do {
        _DAT_180020698 = *(undefined8 *)(pcVar28 + (DAT_180020730 * 3 + _DAT_1800206a0) * 8 + -8);
        lVar32 = DMS_LOCATI(&DAT_180020698);
        DAT_180020690 = lVar32;
        *(undefined8 *)(pcVar28 + lVar32 * 8 + 8) = 0;
        DAT_1800201c0 = *(longlong *)(pcVar28 + lVar32 * 8 + 0x30);
        if (DAT_1800201c0 == 0) {
          DMS_ALLOCI(&DAT_180017be8,&DAT_1800201c0,&DAT_1800201b8);
          *(longlong *)(pcVar28 + DAT_180020690 * 8 + 0x30) = DAT_1800201c0;
          lVar24 = DAT_1800201b8;
          lVar32 = DAT_1800201b8 * 8;
          *(undefined8 *)(pcVar28 + lVar32 + -8) = 0;
          *(undefined8 *)(pcVar28 + lVar32 + -8 + 8) = 0;
          lVar24 = lVar24 + 2;
        }
        else {
          lVar24 = DMS_LOCATI(&DAT_1800201c0);
          DAT_1800201b8 = lVar24;
          *(undefined8 *)(pcVar28 + lVar24 * 8 + -8) = 0;
        }
        *(undefined8 *)(pcVar28 + lVar24 * 8) = 0;
        lVar32 = DAT_180020730 + 1;
        bVar6 = DAT_180020730 < lVar27;
        DAT_180020730 = lVar32;
      } while (bVar6);
    }
  }
  DMS_CDATE(&DAT_180020620,&DAT_1800207c0,&DAT_180020780,&DAT_180020600,&DAT_180020740,
            &DAT_180020530,&DAT_180020528,&DAT_180020520);
  *(undefined8 *)(pcVar31 + 0xe0) = DAT_180020530;
  *(undefined8 *)(pcVar31 + 0xd8) = DAT_180020528;
  *(undefined8 *)(pcVar31 + 0xe8) = DAT_180020520;
  uVar26 = DAT_180020620;
  *(undefined8 *)pcVar31 = DAT_180020620;
  uVar9 = uRam0000000180020634;
  uVar8 = uRam0000000180020630;
  uVar7 = uRam000000018002062c;
  *(undefined4 *)(pcVar31 + 8) = _DAT_180020628;
  *(undefined4 *)(pcVar31 + 0xc) = uVar7;
  *(undefined4 *)(pcVar31 + 0x10) = uVar8;
  *(undefined4 *)(pcVar31 + 0x14) = uVar9;
  lVar27 = 0;
  do {
    *(undefined8 *)(pcVar31 + lVar27 + 0x58) = *(undefined8 *)((longlong)&DAT_180020600 + lVar27);
    *(undefined8 *)(pcVar31 + lVar27 + 0x18) = *(undefined8 *)((longlong)&DAT_1800207c0 + lVar27);
    lVar27 = lVar27 + 8;
  } while (lVar27 != 0x18);
  lVar27 = 0;
  do {
    *(undefined8 *)(pcVar31 + lVar27 + 0x30) = *(undefined8 *)((longlong)&DAT_180020780 + lVar27);
    *(undefined8 *)(pcVar31 + lVar27 + 0x70) = *(undefined8 *)((longlong)&DAT_180020740 + lVar27);
    pcVar36 = DMS_GLOBAL_exref;
    pcVar37 = DMS_DMS_exref;
    lVar27 = lVar27 + 8;
  } while (lVar27 != 0x28);
  DAT_180020730 = 6;
  if (*(longlong *)(DMS_DMS_exref + 0x2088) == 0) {
    lVar27 = DMS_LOCATI(&DAT_180017bf0);
    pcVar35 = DMS_PLEX_exref;
    _DAT_180020688 = *(undefined8 *)(DMS_PLEX_exref + lVar27 * 8 + 0x308);
    lVar25 = DMS_LOCATI(&DAT_180020688);
    lVar27 = *(longlong *)(pcVar35 + lVar25 * 8 + 0x60);
    lVar32 = *(longlong *)(pcVar35 + lVar25 * 8 + 0x20);
    lVar24 = *(longlong *)(pcVar35 + lVar25 * 8 + 0x38);
    uVar26 = *(undefined8 *)(pcVar35 + lVar25 * 8 + 0x50 + 8);
    *(undefined8 *)(pcVar31 + 0x740) = *(undefined8 *)(pcVar35 + lVar25 * 8 + 0x50);
    *(undefined8 *)(pcVar31 + 0x748) = uVar26;
    pcVar37 = pcVar35 + lVar25 * 8 + -8;
    uVar7 = *(undefined4 *)(pcVar37 + 4);
    uVar8 = *(undefined4 *)(pcVar37 + 8);
    uVar9 = *(undefined4 *)(pcVar37 + 0xc);
    uVar26 = *(undefined8 *)(pcVar35 + lVar25 * 8 + 8);
    uVar5 = *(undefined8 *)(pcVar35 + lVar25 * 8 + 8 + 8);
    *(undefined4 *)(pcVar31 + 0x7a8) = *(undefined4 *)pcVar37;
    *(undefined4 *)(pcVar31 + 0x7ac) = uVar7;
    *(undefined4 *)(pcVar31 + 0x7b0) = uVar8;
    *(undefined4 *)(pcVar31 + 0x7b4) = uVar9;
    *(undefined8 *)(pcVar31 + 0x7b8) = uVar26;
    *(undefined8 *)(pcVar31 + 0x7c0) = uVar5;
    uVar29 = *(ulonglong *)(pcVar31 + 0x848);
    if (0 < (longlong)uVar29) {
      if (uVar29 < 0xd) {
        uVar30 = uVar29 & 0xe;
        if (uVar30 == 0) {
          uVar30 = 0;
        }
        else {
          uVar23 = 0;
          do {
            uVar26 = *(undefined8 *)(pcVar35 + uVar23 * 8 + (lVar25 + lVar32) * 8 + -8 + 8);
            *(undefined8 *)(pcVar31 + uVar23 * 8 + 0x2f0) =
                 *(undefined8 *)(pcVar35 + uVar23 * 8 + (lVar25 + lVar32) * 8 + -8);
            *(undefined8 *)(pcVar31 + uVar23 * 8 + 0x2f0 + 8) = uVar26;
            uVar26 = *(undefined8 *)(pcVar35 + uVar23 * 8 + (lVar25 + lVar24) * 8 + -8 + 8);
            *(undefined8 *)(pcVar31 + uVar23 * 8 + 0x4f8) =
                 *(undefined8 *)(pcVar35 + uVar23 * 8 + (lVar25 + lVar24) * 8 + -8);
            *(undefined8 *)(pcVar31 + uVar23 * 8 + 0x4f8 + 8) = uVar26;
            pcVar37 = pcVar35 + uVar23 * 8 + (lVar25 + lVar27) * 8 + -8;
            uVar7 = *(undefined4 *)(pcVar37 + 4);
            uVar8 = *(undefined4 *)(pcVar37 + 8);
            uVar9 = *(undefined4 *)(pcVar37 + 0xc);
            pcVar36 = pcVar31 + uVar23 * 8 + 0xf0;
            *(undefined4 *)pcVar36 = *(undefined4 *)pcVar37;
            *(undefined4 *)(pcVar36 + 4) = uVar7;
            *(undefined4 *)(pcVar36 + 8) = uVar8;
            *(undefined4 *)(pcVar36 + 0xc) = uVar9;
            uVar23 = uVar23 + 2;
          } while (uVar23 < uVar30);
          if (uVar29 == uVar30) goto LAB_180007f68;
        }
        lVar1 = lVar25 + uVar30;
        lVar34 = 0;
        do {
          *(undefined8 *)(pcVar31 + lVar34 * 8 + uVar30 * 8 + 0x2f0) =
               *(undefined8 *)(pcVar35 + lVar34 * 8 + (lVar32 + lVar1) * 8 + -8);
          *(undefined8 *)(pcVar31 + lVar34 * 8 + uVar30 * 8 + 0x4f8) =
               *(undefined8 *)(pcVar35 + lVar34 * 8 + (lVar24 + lVar1) * 8 + -8);
          *(undefined8 *)(pcVar31 + lVar34 * 8 + uVar30 * 8 + 0xf0) =
               *(undefined8 *)(pcVar35 + lVar34 * 8 + (lVar27 + lVar1) * 8 + -8);
          lVar34 = lVar34 + 1;
        } while (uVar29 - uVar30 != lVar34);
      }
      else {
        FUN_180008d20();
        FUN_180008d20();
        FUN_180008d20();
      }
    }
LAB_180007f68:
    uVar26 = *(undefined8 *)(pcVar35 + lVar25 * 8 + 0x30);
    *(undefined8 *)(pcVar31 + 0x7c8) = *(undefined8 *)(pcVar35 + lVar25 * 8 + 0x18);
    *(undefined8 *)(pcVar31 + 0x4f0) = uVar26;
    *(undefined8 *)(pcVar31 + 0x6f8) = *(undefined8 *)(pcVar35 + lVar25 * 8 + 0x48);
    lVar27 = *(longlong *)(pcVar35 + lVar25 * 8 + 0x70);
    lVar32 = 0;
    do {
      *(undefined8 *)(pcVar31 + lVar32 * 8 + 0x710) =
           *(undefined8 *)(pcVar35 + lVar32 * 8 + (lVar27 + lVar25) * 8 + -8);
      pcVar37 = DMS_PGMNFO_exref;
      lVar32 = lVar32 + 1;
    } while (lVar32 != 6);
    uVar29 = *(ulonglong *)(pcVar35 + lVar25 * 8 + 0x88);
    lVar27 = *(longlong *)(pcVar35 + lVar25 * 8 + 0x90);
    *(ulonglong *)(DMS_PGMNFO_exref + 0x10) = uVar29;
    pcVar36 = DMS_GLOBAL_exref;
    DAT_180020730 = 1;
    if (0 < (longlong)uVar29) {
      if (uVar29 < 0xd) {
        uVar30 = 0;
        do {
          *(undefined8 *)(pcVar37 + uVar30 * 8 + 0x448) =
               *(undefined8 *)(pcVar35 + uVar30 * 8 + (lVar25 + lVar27) * 8 + -8);
          uVar30 = uVar30 + 1;
        } while (uVar29 != uVar30);
      }
      else {
        FUN_180008d20();
      }
      DAT_180020730 = uVar29 + 1;
    }
    pcVar37 = DMS_DMS_exref;
    *(undefined8 *)(DMS_DMS_exref + 0x58) = *(undefined8 *)pcVar31;
    pcVar31 = ZREP_RPT_exref;
    if (*(longlong *)(pcVar37 + 0x2088) == 0) {
      _DAT_180020680 = *(undefined8 *)(pcVar35 + DAT_180020728 * 8 + 0x490);
      lVar32 = DMS_LOCATI(&DAT_180020680);
      lVar27 = *(longlong *)(pcVar35 + lVar32 * 8 + -8);
      if (0 < lVar27) {
        lVar24 = *(longlong *)(pcVar35 + lVar32 * 8);
        puVar33 = &DAT_1800205e0;
        lVar25 = 0;
        do {
          *puVar33 = *(undefined8 *)(pcVar35 + lVar25 * 8 + (lVar24 + lVar32) * 8 + -8);
          puVar33 = puVar33 + 1;
          lVar25 = lVar25 + 1;
        } while (lVar25 < lVar27);
      }
      lVar27 = *(longlong *)(pcVar35 + lVar32 * 8 + 8);
      if (0 < lVar27) {
        lVar24 = *(longlong *)(pcVar35 + lVar32 * 8 + 0x10);
        puVar33 = &DAT_1800205c0;
        lVar25 = 0;
        do {
          *puVar33 = *(undefined8 *)(pcVar35 + lVar25 * 8 + (lVar24 + lVar32) * 8 + -8);
          puVar33 = puVar33 + 1;
          lVar25 = lVar25 + 1;
        } while (lVar25 < lVar27);
      }
      lVar27 = *(longlong *)(pcVar35 + lVar32 * 8 + 0x18);
      if (0 < lVar27) {
        lVar24 = *(longlong *)(pcVar35 + lVar32 * 8 + 0x20);
        puVar33 = &DAT_180020580;
        lVar25 = 0;
        do {
          *puVar33 = *(undefined8 *)(pcVar35 + lVar25 * 8 + (lVar24 + lVar32) * 8 + -8);
          puVar33 = puVar33 + 1;
          lVar25 = lVar25 + 1;
        } while (lVar25 < lVar27);
      }
      lVar27 = *(longlong *)(pcVar35 + lVar32 * 8 + 0x28);
      lVar24 = *(longlong *)(pcVar35 + lVar32 * 8 + 0x30);
      DAT_180020730 = 1;
      if (0 < lVar27) {
        puVar33 = &DAT_180020540;
        lVar25 = 0;
        do {
          *puVar33 = *(undefined8 *)(pcVar35 + lVar25 * 8 + (lVar32 + lVar24) * 8 + -8);
          puVar33 = puVar33 + 1;
          lVar25 = lVar25 + 1;
        } while (lVar25 < lVar27);
        DAT_180020730 = lVar27 + 1;
      }
    }
  }
  else {
    *(undefined8 *)(DMS_DMS_exref + 0x58) = uVar26;
    pcVar31 = ZREP_RPT_exref;
  }
  _DAT_180020678 = *(longlong *)(pcVar28 + DAT_180020728 * 8 + 0x88);
  DAT_180020670 = 1;
  if (_DAT_180020678 == 0) {
    _DAT_180020668 = 0;
    pcVar35 = pcVar28;
  }
  else {
    DAT_180020670 = DMS_LOCATI(&DAT_180020678);
    _DAT_180020668 = DMS_LENTHI(&DAT_180020678);
    pcVar35 = DMS_PLEX_exref + DAT_180020670 * 8 + -8;
  }
  _DAT_180020668 = _DAT_180020668 * *(longlong *)(pcVar36 + 0x30);
  ZREP_CENTER(pcVar35,&DAT_180020668,pcVar31 + 0x30,&DAT_180017bf8);
  _DAT_180020660 = *(longlong *)(pcVar28 + DAT_180020728 * 8 + 0x3b8);
  if (_DAT_180020660 != 0) {
    lVar27 = DMS_LOCATI(&DAT_180020660);
    pcVar28 = DMS_PLEX_exref;
    uVar26 = *(undefined8 *)(DMS_PLEX_exref + lVar27 * 8 + -8 + 8);
    uVar5 = *(undefined8 *)(DMS_PLEX_exref + lVar27 * 8 + 8);
    uVar10 = *(undefined8 *)(DMS_PLEX_exref + lVar27 * 8 + 8 + 8);
    *(undefined8 *)pcVar31 = *(undefined8 *)(DMS_PLEX_exref + lVar27 * 8 + -8);
    *(undefined8 *)(pcVar31 + 8) = uVar26;
    *(undefined8 *)(pcVar31 + 0x10) = uVar5;
    *(undefined8 *)(pcVar31 + 0x18) = uVar10;
    *(undefined8 *)(ZREP_HEAD_exref + 0xa8) = *(undefined8 *)(pcVar28 + lVar27 * 8 + 0x18);
    *(undefined8 *)(pcVar31 + 0x28) = *(undefined8 *)(pcVar28 + lVar27 * 8 + 0x20);
    pcVar28 = pcVar28 + lVar27 * 8 + 0x28;
    uVar7 = *(undefined4 *)(pcVar28 + 4);
    uVar8 = *(undefined4 *)(pcVar28 + 8);
    uVar9 = *(undefined4 *)(pcVar28 + 0xc);
    *(undefined4 *)(pcVar31 + 0xf0) = *(undefined4 *)pcVar28;
    *(undefined4 *)(pcVar31 + 0xf4) = uVar7;
    *(undefined4 *)(pcVar31 + 0xf8) = uVar8;
    *(undefined4 *)(pcVar31 + 0xfc) = uVar9;
  }
  lVar27 = DAT_180020728;
  pcVar28 = DMS_RPTGLB_exref;
  *(undefined8 *)(DMS_RPTGLB_exref + 0x58) = 0;
  *(undefined8 *)(pcVar28 + 0x60) = 0x3ff0000000000000;
  pcVar31 = DMS_PLEX_exref;
  DMS_ALLOCI(&DAT_180017c00,DMS_PLEX_exref + lVar27 * 8 + 0x540,&DAT_180020670);
  DMS_ALLOCI(&DAT_180017c08,pcVar31 + DAT_180020728 * 8 + 0x538,&DAT_180020670);
  pcVar28 = DMS_PPERR1_exref;
  *(undefined8 *)(DMS_PPERR1_exref + 8) = 1;
  *(undefined8 *)(pcVar28 + 0x6e0) = 0x10;
  *(undefined8 *)(pcVar28 + 0x6e8) = 0xf;
  *(undefined8 *)(pcVar28 + 0x6f0) = 0xf;
  lVar27 = DAT_180020728;
  uVar26 = *(undefined8 *)(pcVar31 + DAT_180020728 * 8 + 0x538);
  *(undefined8 *)(pcVar28 + 0x6a0) = *(undefined8 *)(pcVar31 + DAT_180020728 * 8 + 0x540);
  *(undefined8 *)(pcVar28 + 0x6a8) = 1;
  *(undefined8 *)(pcVar28 + 0x6c0) = uVar26;
  *(undefined8 *)(pcVar28 + 0x6c8) = 1;
  *(undefined8 *)(pcVar28 + 0x6b0) = 0;
  if (*(longlong *)(pcVar37 + 0x2088) == 0) {
    DMS_NEWROY();
    lVar27 = DAT_180020728;
  }
  _DAT_180020720 = *(ulonglong *)(pcVar31 + lVar27 * 8 + 0x630);
  DAT_180020718 = DMS_LOCATI(&DAT_180020720);
  *(undefined8 *)(pcVar31 + DAT_180020718 * 8 + 0xb8) = 0;
  _DAT_180020658 = *(undefined8 *)(pcVar31 + DAT_180020728 * 8 + 0x118);
  DAT_180020650 = DMS_LOCATI(&DAT_180020658);
  pcVar28 = DMS_NCOMP_exref;
  DAT_180020518 = *(longlong *)(pcVar31 + DAT_180020650 * 8 + -8);
  *(longlong *)DMS_NCOMP_exref = DAT_180020518;
  if (*(longlong *)(pcVar37 + 0x2088) != 0) {
    DMS_SETNCC(DMS_NCOMP_exref);
  }
  DAT_180020718 = DMS_LOCATI(&DAT_180017c10);
  if (*(longlong *)(pcVar31 + DAT_180020718 * 8 + 0x3d0) == 0) {
    DMS_SIMBEAD(&DAT_180017c20);
    lVar27 = *(longlong *)pcVar28;
    local_b8[0] = lVar27 * 3 + 3;
    local_c0 = lVar27 * 3 + 0xc;
    DMS_ALLOCM(local_b8,&local_c0,pcVar31 + DAT_180020718 * 8 + 0x3d0,&DAT_180020670,&DAT_1800206b0,
               &DAT_1800206f0);
    DMS_SIMBEAD(&DAT_180017c18);
  }
  else {
    DMS_LOCATM(pcVar31 + DAT_180020718 * 8 + 0x3d0,&DAT_180020670,&DAT_1800206b0,&DAT_1800206f0);
  }
  pcVar35 = PPUTL_EOSRET_exref;
  *(undefined8 *)PPUTL_EOSRET_exref = 0xffffffffffffffff;
  lVar27 = *(longlong *)pcVar28;
  *(longlong *)(pcVar35 + 0x40) = lVar27;
  *(undefined8 *)(pcVar35 + 0x48) = 0;
  *(undefined8 *)(pcVar35 + 8) = 1;
  lVar32 = DAT_180020670;
  *(longlong *)(pcVar35 + 0x10) = DAT_180020670;
  *(longlong *)(pcVar35 + 0x18) = lVar27 + 1 + lVar32;
  *(longlong *)(pcVar35 + 0x20) = lVar32 + 2 + lVar27 * 2;
  lVar32 = DAT_1800206b0;
  *(longlong *)(pcVar35 + 0x28) = DAT_1800206b0;
  *(longlong *)(pcVar35 + 0x30) = lVar27 + 4 + lVar32;
  *(longlong *)(pcVar35 + 0x38) = lVar32 + 8 + lVar27 * 2;
  DMS_STRETN(&DAT_180020470,&DAT_180020478,&DAT_180020468,&DAT_180020460,&DAT_180020458);
  _DAT_180020648 = DAT_180020478 + DAT_180020518 + 6;
  DAT_180020640 = DAT_180020470 + DAT_180020518 * 0x10 + 0x1f;
  DMS_ALLOCM(&DAT_180020648,&DAT_180020640,&DAT_180020168,&DAT_180020670,&DAT_1800206b0,
             &DAT_1800206f0);
  _PPEXEC_IWNC = DAT_180020670 + -1;
  _PPEXEC_IRETEN = DAT_180020518 + -1 + DAT_180020670;
  _PPEXEC_WNC1 = DAT_1800206b0 + -1;
  _PPEXEC_WNC2 = DAT_1800206b0 + DAT_180020518 + -1;
  _PPEXEC_WNC3 = _PPEXEC_WNC2 + DAT_180020518;
  _PPEXEC_WNC4 = _PPEXEC_WNC3 + DAT_180020518;
  _PPEXEC_WNC5 = _PPEXEC_WNC4 + DAT_180020518;
  _PPEXEC_WNC6 = _PPEXEC_WNC5 + DAT_180020518;
  _PPEXEC_WNC7 = _PPEXEC_WNC6 + DAT_180020518;
  _PPEXEC_WNC8 = _PPEXEC_WNC7 + DAT_180020518;
  _PPEXEC_WNC9 = _PPEXEC_WNC8 + DAT_180020518;
  _PPEXEC_WNC10 = _PPEXEC_WNC9 + DAT_180020518;
  _PPEXEC_RETEN = _PPEXEC_WNC10 + DAT_180020518;
  DAT_1800204a0 = 0;
  DAT_180020498 = 0;
  _DAT_1800201c8 = *(longlong *)(pcVar31 + DAT_180020728 * 8 + 0x10);
  if (_DAT_1800201c8 == 0) {
LAB_1800086b3:
    DAT_180020490 = *(longlong *)(pcVar31 + DAT_180020650 * 8 + 0x28);
    _DAT_180020488 = *(longlong *)(pcVar31 + DAT_180020650 * 8 + 0x38);
    _DAT_180020480 =
         (*(longlong *)(pcVar31 + DAT_180020650 * 8 + 0x30) +
         *(longlong *)(pcVar31 + DAT_180020650 * 8 + 0x20)) * 2;
    if (0 < *(longlong *)(pcVar31 + DAT_180020650 * 8 + 0x20)) {
      DMS_ALLOCR(&DAT_180020480,&DAT_1800204a0,pcVar36 + 0x80);
    }
    if (0 < DAT_180020490) {
      local_c8 = DAT_180020490 + _DAT_180020488;
      DMS_ALLOCR(&local_c8,&DAT_180020498,pcVar36 + 0x78);
    }
    if (DAT_1800204a0 == 0) goto LAB_180008755;
  }
  else {
    lVar27 = DMS_LOCATI(&DAT_1800201c8);
    DAT_1800204a0 = *(longlong *)(pcVar31 + lVar27 * 8 + 0x38);
    DAT_180020498 = *(longlong *)(pcVar31 + lVar27 * 8 + 0x40);
    if ((DAT_1800204a0 == 0) || (DAT_180020498 == 0)) goto LAB_1800086b3;
  }
  uVar26 = DMS_LOCATR(&DAT_1800204a0);
  *(undefined8 *)(pcVar36 + 0x80) = uVar26;
LAB_180008755:
  if (DAT_180020498 != 0) {
    uVar26 = DMS_LOCATR(&DAT_180020498);
    *(undefined8 *)(pcVar36 + 0x78) = uVar26;
  }
  if (DAT_1800201f8 == '\0') {
    *(undefined8 *)(pcVar21 + 0x40) = 99;
    ZREP_PLOGO(&DAT_180017c20);
    *(undefined8 *)(pcVar21 + 0x40) = 0;
    DAT_1800201f8 = '\x01';
  }
  DMS_FPULDL();
  if (*(longlong *)(pcVar37 + 0x2088) == 0) {
    DMS_FPRSLV();
  }
  return;
code_r0x0001800074fb:
  dVar3 = *(double *)(pcVar28 + lVar24 * 8 + 0x60);
  *(double *)(PPUTL_EOSTOL_exref + 8) = dVar3;
  dVar4 = *(double *)pcVar2;
  if (dVar4 <= dVar3) {
    *(undefined8 *)(pcVar22 + 8) = 0x3fb999999999999a;
  }
  _PPEXEC_MWCALC = *(undefined8 *)(pcVar28 + lVar25 * 8 + 0x10);
  *(undefined8 *)(PPUTL_ESEXTR_exref + 8) = *(undefined8 *)(pcVar28 + lVar25 * 8 + 0x40);
  *(undefined8 *)(pcVar36 + 0x50) = *(undefined8 *)(pcVar28 + lVar25 * 8 + 0x50);
  *(undefined8 *)(pcVar36 + 0x60) = *(undefined8 *)(pcVar28 + lVar25 * 8 + 0x60);
  uVar26 = *(undefined8 *)(pcVar28 + lVar25 * 8 + 0x68 + 8);
  *(undefined8 *)(pcVar36 + 0x68) = *(undefined8 *)(pcVar28 + lVar25 * 8 + 0x68);
  *(undefined8 *)(pcVar36 + 0x70) = uVar26;
  dVar3 = *(double *)(pcVar28 + lVar24 * 8 + 0x68);
  *(double *)(pcVar36 + 0x18) = dVar3;
  if (dVar4 <= dVar3) {
    *(undefined8 *)(pcVar36 + 0x18) = 0x3fef5c28f5c28f5c;
  }
  lVar27 = *(longlong *)(pcVar28 + lVar25 * 8 + 0x90);
  *(undefined8 *)(pcVar36 + 0x80) = *(undefined8 *)(pcVar28 + lVar25 * 8 + 0x88);
  *(ulonglong *)(pcVar36 + 0x90) = (ulonglong)(lVar27 != 1);
  *(undefined8 *)(pcVar36 + 0x4ed0) = *(undefined8 *)(pcVar28 + lVar25 * 8 + 0xb0);
  pcVar37 = pcVar28 + lVar24 * 8 + 0x90;
  uVar7 = *(undefined4 *)(pcVar37 + 4);
  uVar8 = *(undefined4 *)(pcVar37 + 8);
  uVar9 = *(undefined4 *)(pcVar37 + 0xc);
  *(undefined4 *)(pcVar36 + 0x28) = *(undefined4 *)pcVar37;
  *(undefined4 *)(pcVar36 + 0x2c) = uVar7;
  *(undefined4 *)(pcVar36 + 0x30) = uVar8;
  *(undefined4 *)(pcVar36 + 0x34) = uVar9;
  *(ulonglong *)(pcVar36 + 0x4f38) = (ulonglong)(*(longlong *)(pcVar28 + lVar25 * 8 + 0xf8) != 1);
  goto LAB_1800075eb;
}

