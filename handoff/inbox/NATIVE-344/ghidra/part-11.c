/* RVA 0x3a630 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_18003a630(int *param_1,longlong param_2,longlong param_3,undefined8 param_4)

{
  int *piVar1;
  longlong lVar2;
  int iVar3;
  char *pcVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  int *_Source;
  int *piVar8;
  int iVar9;
  size_t sVar10;
  size_t _Count;
  double dVar11;
  undefined1 auStack_1e8 [32];
  undefined8 local_1c8;
  char *local_1c0;
  double *local_1b8;
  undefined1 *local_1b0;
  undefined4 local_1a8;
  undefined1 local_198 [16];
  char *local_188;
  undefined8 local_180;
  undefined8 local_178;
  undefined1 local_170 [256];
  undefined4 *local_70;
  undefined8 local_58;
  undefined8 local_50;
  char local_48 [16];
  undefined1 local_38;
  ulonglong local_30;
  
  local_30 = DAT_1800516d8 ^ (ulonglong)auStack_1e8;
  switch(*(undefined4 *)(param_2 + 8)) {
  case 0xffffffdf:
    iVar3 = HYrslhie(&DAT_180053860,&DAT_18003fa80,&local_50,&local_58);
    if (iVar3 != 0) {
      uVar5 = HYGetFinfoCls(local_50,local_58);
      uVar5 = HYPshFinfo(uVar5);
      uVar6 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"CALCULATOR");
      uVar7 = MDfndkey(*(undefined8 *)iwpfile_exref,uVar6,1,&DAT_1800531c0);
      memset(local_170,0,0x110);
      local_188 = "SHEET";
      local_1c8 = 0;
      local_180 = uVar7;
      local_178 = uVar6;
      MDfndvar("SHEET",1,0,&local_188);
      local_1a8 = 2;
LAB_18003ab2a:
      local_1b0 = local_198;
      local_1b8 = DAT_1800531e0;
      local_1c0 = DAT_1800531d0;
      local_1c8 = CONCAT44(local_1c8._4_4_,DAT_1800531b8);
      XCExcelCalc(&DAT_1800531c0,*local_70,DAT_1800531b0,DAT_1800531b4);
      DAT_1800531e8 = DAT_1800531e0;
      *(undefined1 *)(param_3 + 0xc) = local_198[0];
      DAT_1800531f0 = 0;
      *(undefined4 *)(param_3 + 8) = 1;
      HYPopFinfo(uVar5);
    }
    break;
  case 0xffffffe0:
  case 0xffffffe1:
  case 0xffffffe2:
  case 0xffffffe3:
  case 0xffffffe4:
  case 0xffffffe5:
  case 0xffffffe6:
  case 0xffffffe7:
  case 0xffffffe8:
  case 0xffffffe9:
  case 0xffffffea:
  case 0xffffffeb:
  case 0xffffffec:
  case 0xffffffed:
    break;
  case 0xffffffee:
    if (0 < DAT_1800531b0) {
      MDfree(DAT_1800531d0);
    }
    if (0 < DAT_1800531cc) {
      MDfree(DAT_1800531e0);
    }
    break;
  case 0xffffffef:
    pcVar4 = (char *)(param_3 + 0xc);
    *(undefined4 *)(param_3 + 8) = 1;
    memset(pcVar4,0x20,0x104);
    iVar3 = 0;
    do {
      if (DAT_1800531b8 <= DAT_1800531f0) break;
      FUN_180008f80(local_48,"%-16.9G",*DAT_1800531e8,param_4);
      sVar10 = 0xffffffffffffffff;
      do {
        _Count = sVar10 + 1;
        lVar2 = sVar10 + 1;
        sVar10 = _Count;
      } while (local_48[lVar2] != '\0');
      strncpy(pcVar4,local_48,_Count);
      iVar3 = iVar3 + 1;
      DAT_1800531e8 = DAT_1800531e8 + 1;
      DAT_1800531f0 = DAT_1800531f0 + 1;
      pcVar4 = pcVar4 + 0x10;
    } while (iVar3 < 0xc);
    break;
  case 0xfffffff0:
    iVar3 = HYrslhie(&DAT_180053860,&DAT_18003fa80,&local_50,&local_58);
    if (iVar3 != 0) {
      uVar5 = HYGetFinfoCls(local_50,local_58);
      uVar5 = HYPshFinfo(uVar5);
      uVar6 = MDfnddir(*(undefined8 *)iwpfile_exref,*(undefined8 *)dataclass_exref,"CALCULATOR");
      uVar7 = MDfndkey(*(undefined8 *)iwpfile_exref,uVar6,1,&DAT_1800531c0);
      memset(local_170,0,0x110);
      local_188 = "HANDLE";
      local_1c8 = 0;
      local_180 = uVar7;
      local_178 = uVar6;
      MDfndvar("HANDLE",1,0,&local_188);
      local_1a8 = 1;
      goto LAB_18003ab2a;
    }
    break;
  case 0xfffffff1:
    iVar3 = 0;
    if (0 < *param_1) {
      piVar8 = (int *)(param_2 + 0xc);
      do {
        iVar9 = 0;
        if (0 < *piVar8) {
          do {
            strncpy(local_48,(char *)(piVar8 + (longlong)iVar9 * 4 + 1),0x10);
            local_38 = 0;
            dVar11 = atof(local_48);
            iVar9 = iVar9 + 1;
            *DAT_1800531e8 = dVar11;
            DAT_1800531e8 = DAT_1800531e8 + 1;
          } while (iVar9 < *piVar8);
        }
        iVar3 = iVar3 + 1;
        piVar8 = piVar8 + 0x44;
      } while (iVar3 < *param_1);
    }
    break;
  case 0xfffffff2:
    DAT_1800531b4 = *(int *)(param_2 + 0xc);
    DAT_1800531b8 = *(int *)(param_2 + 0x10);
    DAT_1800531cc = DAT_1800531b8;
    if (DAT_1800531b8 < DAT_1800531b4) {
      DAT_1800531cc = DAT_1800531b4;
    }
    if (DAT_1800531cc < 1) {
      DAT_1800531e8 = DAT_1800531e0;
    }
    else {
      DAT_1800531e0 = (double *)MDmalloc((longlong)DAT_1800531cc << 3);
      DAT_1800531e8 = DAT_1800531e0;
    }
    break;
  case 0xfffffff3:
    iVar3 = 0;
    if (0 < *param_1) {
      piVar8 = (int *)(param_2 + 0xc);
      pcVar4 = DAT_1800531d8;
      do {
        _Source = piVar8 + 1;
        iVar9 = 0;
        if (0 < *piVar8) {
          do {
            strncpy(pcVar4,(char *)_Source,8);
            iVar9 = iVar9 + 1;
            DAT_1800531d8[8] = '\0';
            *(int *)(DAT_1800531d8 + 0xc) = _Source[2];
            *(int *)(DAT_1800531d8 + 0x10) = _Source[3];
            *(int *)(DAT_1800531d8 + 0x14) = _Source[4];
            *(int *)(DAT_1800531d8 + 0x18) = _Source[5];
            piVar1 = _Source + 6;
            _Source = _Source + 7;
            *(int *)(DAT_1800531d8 + 0x1c) = *piVar1;
            pcVar4 = DAT_1800531d8 + 0x20;
            DAT_1800531d8 = pcVar4;
          } while (iVar9 < *piVar8);
        }
        iVar3 = iVar3 + 1;
        piVar8 = piVar8 + 0x44;
      } while (iVar3 < *param_1);
    }
    break;
  case 0xfffffff4:
    DAT_1800531b0 = *(int *)(param_2 + 0x14);
    strncpy(&DAT_1800531c0,(char *)(param_2 + 0xc),8);
    DAT_1800531c8 = 0;
    pcVar4 = strchr(&DAT_1800531c0,0x20);
    if (pcVar4 != (char *)0x0) {
      *pcVar4 = '\0';
    }
    DAT_1800531b4 = 0;
    DAT_1800531b8 = 0;
    _DAT_1800531bc = 0;
    if (0 < DAT_1800531b0) {
      iVar3 = DAT_1800531b0 << 5;
      pcVar4 = (char *)MDmalloc((longlong)iVar3);
      DAT_1800531d0 = pcVar4;
      memset(pcVar4,0,(longlong)iVar3);
      DAT_1800531d8 = pcVar4;
    }
    break;
  default:
    goto switchD_18003a690_default;
  }
switchD_18003a690_default:
  return;
}

/* RVA 0x3ac3c */
void GetGlobalPointer(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ac3c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetGlobalPointer();
  return;
}

/* RVA 0x3ac42 */
void GRinqcnn(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ac42. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRinqcnn();
  return;
}

/* RVA 0x3ac48 */
void SEGetSettingValue(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ac48. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SEGetSettingValue();
  return;
}

/* RVA 0x3ac4e */
void COprocom(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ac4e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  COprocom();
  return;
}

/* RVA 0x3ac54 */
void MDnatsrt(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ac54. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MDnatsrt();
  return;
}

/* RVA 0x3ac5a */
void GRsetust(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ac5a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRsetust();
  return;
}

/* RVA 0x3ac60 */
void GRinqust(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ac60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRinqust();
  return;
}

/* RVA 0x3ac66 */
void GRinqscp(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ac66. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRinqscp();
  return;
}

/* RVA 0x3ac6c */
void GRinqeop(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ac6c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRinqeop();
  return;
}

/* RVA 0x3ac72 */
void GRseteorsl(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ac72. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRseteorsl();
  return;
}

/* RVA 0x3ac78 */
void FLeofix(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ac78. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FLeofix();
  return;
}

/* RVA 0x3ac7e */
void GRinqiap(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ac7e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRinqiap();
  return;
}

/* RVA 0x3ac84 */
void GRsetfnm(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ac84. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRsetfnm();
  return;
}

/* RVA 0x3ac8a */
void GRinqfnm(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ac8a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRinqfnm();
  return;
}

/* RVA 0x3ac90 */
void GRinqexc(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ac90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRinqexc();
  return;
}

/* RVA 0x3ac96 */
void GRinqnxt(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ac96. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRinqnxt();
  return;
}

/* RVA 0x3ac9c */
void GRinqpgc(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ac9c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRinqpgc();
  return;
}

/* RVA 0x3aca2 */
void GRinqrsl(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003aca2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRinqrsl();
  return;
}

/* RVA 0x3aca8 */
void GRinqdrs(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003aca8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRinqdrs();
  return;
}

/* RVA 0x3acae */
void GRsetedt(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003acae. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRsetedt();
  return;
}

/* RVA 0x3acb4 */
void GRinqsme(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003acb4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRinqsme();
  return;
}

/* RVA 0x3acba */
void GRinqerr(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003acba. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRinqerr();
  return;
}

/* RVA 0x3acc0 */
void GRinqQRs(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003acc0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRinqQRs();
  return;
}

/* RVA 0x3acc6 */
void GRinqgpd(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003acc6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRinqgpd();
  return;
}

/* RVA 0x3accc */
void GRinqrcl(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003accc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRinqrcl();
  return;
}

/* RVA 0x3acd2 */
void GRsetrun(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003acd2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRsetrun();
  return;
}

/* RVA 0x3acd8 */
void GRdiagno(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003acd8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRdiagno();
  return;
}

/* RVA 0x3acde */
void GRsetpri(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003acde. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRsetpri();
  return;
}

/* RVA 0x3ace4 */
void GRinqlcp(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ace4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRinqlcp();
  return;
}

/* RVA 0x3acea */
void GRinqigb(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003acea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRinqigb();
  return;
}

/* RVA 0x3acf0 */
void GRsetigb(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003acf0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRsetigb();
  return;
}

/* RVA 0x3acf6 */
void GRinqgcp(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003acf6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRinqgcp();
  return;
}

/* RVA 0x3acfc */
void GRinqnco(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003acfc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRinqnco();
  return;
}

/* RVA 0x3ad02 */
void GRinqnec(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ad02. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRinqnec();
  return;
}

/* RVA 0x3ad08 */
void GRinqcmp(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ad08. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRinqcmp();
  return;
}

/* RVA 0x3ad0e */
void GRinqiwp(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ad0e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRinqiwp();
  return;
}

/* RVA 0x3ad14 */
void GRinqsms(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ad14. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRinqsms();
  return;
}

/* RVA 0x3ad1a */
void GRinqsmstrat(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ad1a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRinqsmstrat();
  return;
}

/* RVA 0x3ad20 */
void GRinqsmf(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ad20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRinqsmf();
  return;
}

/* RVA 0x3ad26 */
void GRinqmtf(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ad26. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRinqmtf();
  return;
}

/* RVA 0x3ad2c */
void GRinqinmt(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ad2c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRinqinmt();
  return;
}

/* RVA 0x3ad32 */
void GRsetgfl(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ad32. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRsetgfl();
  return;
}

/* RVA 0x3ad38 */
void GRbkpinp(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ad38. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRbkpinp();
  return;
}

/* RVA 0x3ad3e */
void export_MM_file_MAX(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ad3e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  export_MM_file_MAX();
  return;
}

/* RVA 0x3ad44 */
void GRinqcannedpdf(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ad44. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRinqcannedpdf();
  return;
}

/* RVA 0x3ad4a */
void GRinqeorsl(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ad4a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRinqeorsl();
  return;
}

/* RVA 0x3ad50 */
void SBlocalhost(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ad50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SBlocalhost();
  return;
}

/* RVA 0x3ad56 */
void MDwrtacc(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ad56. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MDwrtacc();
  return;
}

/* RVA 0x3ad5c */
void open_message_box(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ad5c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  open_message_box();
  return;
}

/* RVA 0x3ad62 */
void SESetSettingValue(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ad62. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SESetSettingValue();
  return;
}

/* RVA 0x3ad68 */
void gxDriveDialog2(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ad68. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  gxDriveDialog2();
  return;
}

/* RVA 0x3ad6e */
void GRinqautorun(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ad6e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRinqautorun();
  return;
}

/* RVA 0x3ad74 */
void GRinqAutomationMode(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ad74. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRinqAutomationMode();
  return;
}

/* RVA 0x3ad7a */
void GRemrbkp(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ad7a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRemrbkp();
  return;
}

/* RVA 0x3ad80 */
void GRemrbkpfull(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ad80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRemrbkpfull();
  return;
}

/* RVA 0x3ad86 */
void GRemrbka(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ad86. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRemrbka();
  return;
}

/* RVA 0x3ad8c */
void GRemrprp(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ad8c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRemrprp();
  return;
}

/* RVA 0x3ad92 */
void GetEditorTempFileName(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ad92. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetEditorTempFileName();
  return;
}

/* RVA 0x3ad98 */
void SBgethvr(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ad98. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SBgethvr();
  return;
}

/* RVA 0x3ad9e */
void GRchkitm(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ad9e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRchkitm();
  return;
}

/* RVA 0x3ada4 */
void SBmmgini(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ada4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SBmmgini();
  return;
}

/* RVA 0x3adaa */
void GRsetsms(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003adaa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRsetsms();
  return;
}

/* RVA 0x3adb0 */
void GRinqmt(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003adb0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRinqmt();
  return;
}

/* RVA 0x3adb6 */
void GRsetinmt(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003adb6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRsetinmt();
  return;
}

/* RVA 0x3adbc */
void MDfree(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003adbc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MDfree();
  return;
}

/* RVA 0x3adc2 */
void GRsetpgc(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003adc2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRsetpgc();
  return;
}

/* RVA 0x3adc8 */
void GRsetsmf(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003adc8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRsetsmf();
  return;
}

/* RVA 0x3adce */
void GRsetgpd(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003adce. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRsetgpd();
  return;
}

/* RVA 0x3add4 */
void GRsetsbm(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003add4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRsetsbm();
  return;
}

/* RVA 0x3adda */
void GRsetiap(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003adda. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRsetiap();
  return;
}

/* RVA 0x3ade0 */
void GRsetari(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ade0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRsetari();
  return;
}

/* RVA 0x3ade6 */
void GRsetexc(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ade6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRsetexc();
  return;
}

/* RVA 0x3adec */
void GRsetmtf(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003adec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRsetmtf();
  return;
}

/* RVA 0x3adf2 */
void GRinqcat(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003adf2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRinqcat();
  return;
}

/* RVA 0x3adf8 */
void GRsetsme(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003adf8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRsetsme();
  return;
}

/* RVA 0x3adfe */
void ERclear(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003adfe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ERclear();
  return;
}

/* RVA 0x3ae04 */
void HYparnam(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ae04. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HYparnam();
  return;
}

/* RVA 0x3ae0a */
void HYrslhie(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ae0a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HYrslhie();
  return;
}

/* RVA 0x3ae10 */
void HYGetFinfoCls(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ae10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HYGetFinfoCls();
  return;
}

/* RVA 0x3ae16 */
void HYPshFinfo(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ae16. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HYPshFinfo();
  return;
}

/* RVA 0x3ae1c */
void HYPopFinfo(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ae1c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HYPopFinfo();
  return;
}

/* RVA 0x3ae22 */
void clean_buffer(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ae22. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  clean_buffer();
  return;
}

/* RVA 0x3ae28 */
void HYdspnam(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ae28. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HYdspnam();
  return;
}

/* RVA 0x3ae2e */
void SetGlobalPointer(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ae2e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetGlobalPointer();
  return;
}

/* RVA 0x3ae34 */
void MDfndkey(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ae34. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MDfndkey();
  return;
}

/* RVA 0x3ae3a */
void MDrslcls(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ae3a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MDrslcls();
  return;
}

/* RVA 0x3ae40 */
void HYloohie(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ae40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HYloohie();
  return;
}

/* RVA 0x3ae46 */
void MDfnddir(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ae46. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MDfnddir();
  return;
}

/* RVA 0x3ae4c */
void append_buffer_line(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ae4c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  append_buffer_line();
  return;
}

/* RVA 0x3ae58 */
void hide_mouse(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ae58. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  hide_mouse();
  return;
}

/* RVA 0x3ae5e */
void show_mouse(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ae5e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  show_mouse();
  return;
}

/* RVA 0x3ae64 */
void SBcntcsect(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ae64. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SBcntcsect();
  return;
}

/* RVA 0x3ae6a */
void SBreacsect(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ae6a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SBreacsect();
  return;
}

/* RVA 0x3ae70 */
void MDchkref(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ae70. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MDchkref();
  return;
}

/* RVA 0x3ae76 */
void MDcalloc(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ae76. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MDcalloc();
  return;
}

/* RVA 0x3ae7c */
void MDdelitm(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ae7c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MDdelitm();
  return;
}

/* RVA 0x3ae82 */
void MDdelobj(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ae82. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MDdelobj();
  return;
}

/* RVA 0x3ae88 */
void MDchkkey(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ae88. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MDchkkey();
  return;
}

/* RVA 0x3ae8e */
void MDfndsls(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ae8e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MDfndsls();
  return;
}

/* RVA 0x3ae94 */
void MDfrehnk(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ae94. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MDfrehnk();
  return;
}

/* RVA 0x3ae9a */
void MDfremsg(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003ae9a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MDfremsg();
  return;
}

/* RVA 0x3aea0 */
void MDgethkp(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003aea0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MDgethkp();
  return;
}

/* RVA 0x3aea6 */
void MDgetde(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003aea6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MDgetde();
  return;
}

/* RVA 0x3aeac */
void MDgetito(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003aeac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MDgetito();
  return;
}

/* RVA 0x3aeb2 */
void MDdelsrv(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003aeb2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MDdelsrv();
  return;
}

/* RVA 0x3aeb8 */
void MDdhdvds(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003aeb8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MDdhdvds();
  return;
}

/* RVA 0x3aebe */
void MDprpcmp(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003aebe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MDprpcmp();
  return;
}

/* RVA 0x3aec4 */
void MDprpcmprec(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003aec4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MDprpcmprec();
  return;
}

/* RVA 0x3aeca */
void MDchgflg(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003aeca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MDchgflg();
  return;
}

/* RVA 0x3aed0 */
void MDeoupd(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003aed0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MDeoupd();
  return;
}

/* RVA 0x3aed6 */
void GRsavpgc(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003aed6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRsavpgc();
  return;
}

/* RVA 0x3aedc */
void GRsetrpt(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003aedc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRsetrpt();
  return;
}

/* RVA 0x3aee2 */
void GRsetssm(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003aee2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRsetssm();
  return;
}

/* RVA 0x3aee8 */
void GRset_global_block_data(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003aee8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRset_global_block_data();
  return;
}

/* RVA 0x3aeee */
void GRset_global_stream_data(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003aeee. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRset_global_stream_data();
  return;
}

/* RVA 0x3aef4 */
void OPcreblk(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003aef4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  OPcreblk();
  return;
}

/* RVA 0x3aefa */
void OPcrestr(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003aefa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  OPcrestr();
  return;
}

/* RVA 0x3af00 */
void OPpurdst(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003af00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  OPpurdst();
  return;
}

/* RVA 0x3af06 */
void OPpurcls(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003af06. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  OPpurcls();
  return;
}

/* RVA 0x3af0c */
void OPpurout(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003af0c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  OPpurout();
  return;
}

/* RVA 0x3af12 */
void EXyesno(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003af12. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EXyesno();
  return;
}

/* RVA 0x3af18 */
void HYnavpth(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003af18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HYnavpth();
  return;
}

/* RVA 0x3af1e */
void deref_ptr(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003af1e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  deref_ptr();
  return;
}

/* RVA 0x3af24 */
void free3(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003af24. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  free3();
  return;
}

/* RVA 0x3af2a */
void GRsetnec(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003af2a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRsetnec();
  return;
}

/* RVA 0x3af30 */
void HYReinitLSBEAD(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003af30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HYReinitLSBEAD();
  return;
}

/* RVA 0x3af36 */
void dump_summary(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003af36. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  dump_summary();
  return;
}

/* RVA 0x3af3c */
void MDcremsg(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003af3c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MDcremsg();
  return;
}

/* RVA 0x3af42 */
void MDcntmsg(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003af42. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MDcntmsg();
  return;
}

/* RVA 0x3af48 */
void AcBlockDeleteOutput(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003af48. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  AcBlockDeleteOutput();
  return;
}

/* RVA 0x3af4e */
void OPpurlnk(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003af4e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  OPpurlnk();
  return;
}

/* RVA 0x3af54 */
void MDaccess(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003af54. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MDaccess();
  return;
}

/* RVA 0x3af5a */
void MDaddcrc(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003af5a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MDaddcrc();
  return;
}

/* RVA 0x3af60 */
void SBsethvr(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003af60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SBsethvr();
  return;
}

/* RVA 0x3af66 */
void SB1sthvr(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003af66. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SB1sthvr();
  return;
}

/* RVA 0x3af6c */
void SBnxthvr(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003af6c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SBnxthvr();
  return;
}

/* RVA 0x3af72 */
void SBinqhvr(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003af72. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SBinqhvr();
  return;
}

/* RVA 0x3af78 */
void SBreaini(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003af78. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SBreaini();
  return;
}

/* RVA 0x3af7e */
void malloc3(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003af7e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  malloc3();
  return;
}

/* RVA 0x3af84 */
void LSbkpsrv(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003af84. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LSbkpsrv();
  return;
}

/* RVA 0x3af8a */
void GRsetfop(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003af8a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRsetfop();
  return;
}

/* RVA 0x3af90 */
void GRsetsbs(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003af90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRsetsbs();
  return;
}

/* RVA 0x3af96 */
void GRsetchanged(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003af96. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRsetchanged();
  return;
}

/* RVA 0x3af9c */
void GRinqsbm(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003af9c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRinqsbm();
  return;
}

/* RVA 0x3afa2 */
void GRchkmmdir(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003afa2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRchkmmdir();
  return;
}

/* RVA 0x3afa8 */
void STsavfil(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003afa8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  STsavfil();
  return;
}

/* RVA 0x3afae */
void GRchkwrt(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003afae. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRchkwrt();
  return;
}

/* RVA 0x3afb4 */
void check_reportoption(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003afb4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  check_reportoption();
  return;
}

/* RVA 0x3afba */
void GRclrstp0(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003afba. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRclrstp0();
  return;
}

/* RVA 0x3afc0 */
void push_mouse_mask(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003afc0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  push_mouse_mask();
  return;
}

/* RVA 0x3afc6 */
void pop_mouse_mask(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003afc6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pop_mouse_mask();
  return;
}

/* RVA 0x3afcc */
void save_graphics(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003afcc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  save_graphics();
  return;
}

/* RVA 0x3afd2 */
void MDfndvar(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003afd2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MDfndvar();
  return;
}

/* RVA 0x3afd8 */
void DRstovbg(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003afd8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DRstovbg();
  return;
}

/* RVA 0x3afde */
void DRstovnd(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003afde. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DRstovnd();
  return;
}

/* RVA 0x3afe4 */
void GRsetcpt(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003afe4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRsetcpt();
  return;
}

/* RVA 0x3afea */
void GRinqssu(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003afea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRinqssu();
  return;
}

/* RVA 0x3aff0 */
void GRsetexc2(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003aff0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRsetexc2();
  return;
}

/* RVA 0x3aff6 */
void GRseterr(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003aff6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRseterr();
  return;
}

/* RVA 0x3affc */
void GRsetcnn(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003affc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRsetcnn();
  return;
}

/* RVA 0x3b002 */
void GRsetrpx(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b002. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRsetrpx();
  return;
}

/* RVA 0x3b008 */
void GRsetrst(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b008. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRsetrst();
  return;
}

/* RVA 0x3b00e */
void GRinqist(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b00e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRinqist();
  return;
}

/* RVA 0x3b014 */
void GRsetrdy(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b014. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRsetrdy();
  return;
}

/* RVA 0x3b01a */
void GRinqrdy(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b01a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRinqrdy();
  return;
}

/* RVA 0x3b020 */
void GRsetist(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b020. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRsetist();
  return;
}

/* RVA 0x3b026 */
void GRsetprp(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b026. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRsetprp();
  return;
}

/* RVA 0x3b02c */
void GRinqlaststrat(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b02c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRinqlaststrat();
  return;
}

/* RVA 0x3b032 */
void GRsetlaststrat(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b032. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRsetlaststrat();
  return;
}

/* RVA 0x3b038 */
void GRnxtact(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b038. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRnxtact();
  return;
}

/* RVA 0x3b03e */
void GRinqpri(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b03e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRinqpri();
  return;
}

/* RVA 0x3b044 */
void MDrenchk(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b044. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MDrenchk();
  return;
}

/* RVA 0x3b04a */
void HYloodwn(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b04a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HYloodwn();
  return;
}

/* RVA 0x3b050 */
void pfs_refresh_status(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b050. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pfs_refresh_status();
  return;
}

/* RVA 0x3b056 */
void MDfndfil(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b056. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MDfndfil();
  return;
}

/* RVA 0x3b05c */
void CUsethvr(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b05c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CUsethvr();
  return;
}

/* RVA 0x3b062 */
void CUusthvr(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b062. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CUusthvr();
  return;
}

/* RVA 0x3b068 */
void CUsubhvr(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b068. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CUsubhvr();
  return;
}

/* RVA 0x3b06e */
void GRInqIsSbSimYesNoDlgRaised(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b06e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRInqIsSbSimYesNoDlgRaised();
  return;
}

/* RVA 0x3b074 */
void GRamask(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b074. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRamask();
  return;
}

/* RVA 0x3b07a */
void show_cpanel(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b07a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  show_cpanel();
  return;
}

/* RVA 0x3b080 */
void OPreabck(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b080. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  OPreabck();
  return;
}

/* RVA 0x3b086 */
void dump_input(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b086. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  dump_input();
  return;
}

/* RVA 0x3b08c */
void msw_modify_run_menu(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b08c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  msw_modify_run_menu();
  return;
}

/* RVA 0x3b092 */
void MDdelito(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b092. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MDdelito();
  return;
}

/* RVA 0x3b098 */
void MDgetcnm(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b098. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MDgetcnm();
  return;
}

/* RVA 0x3b09e */
void MDunlito(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b09e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MDunlito();
  return;
}

/* RVA 0x3b0a4 */
void MDptrfre(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b0a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MDptrfre();
  return;
}

/* RVA 0x3b0aa */
void MDptrcnt(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b0aa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MDptrcnt();
  return;
}

/* RVA 0x3b0b0 */
void MDptridx(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b0b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MDptridx();
  return;
}

/* RVA 0x3b0b6 */
void GRsetQRs(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b0b6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRsetQRs();
  return;
}

/* RVA 0x3b0bc */
void GRsetanm(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b0bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRsetanm();
  return;
}

/* RVA 0x3b0c2 */
void GRstratchanged(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b0c2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRstratchanged();
  return;
}

/* RVA 0x3b0c8 */
void MDgetrdf(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b0c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MDgetrdf();
  return;
}

/* RVA 0x3b0ce */
void MDloocmp(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b0ce. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MDloocmp();
  return;
}

/* RVA 0x3b0d4 */
void RLResetAllACM(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b0d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RLResetAllACM();
  return;
}

/* RVA 0x3b0da */
void MDclrmsg(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b0da. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MDclrmsg();
  return;
}

/* RVA 0x3b0e0 */
void dump_buffer(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b0e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  dump_buffer();
  return;
}

/* RVA 0x3b0e6 */
void pfs_update_tables(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b0e6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pfs_update_tables();
  return;
}

/* RVA 0x3b0ec */
void GRsetpdb(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b0ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRsetpdb();
  return;
}

/* RVA 0x3b0f2 */
void HACxsReflect(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b0f2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HACxsReflect();
  return;
}

/* RVA 0x3b0f8 */
void GRSetIsSbSimYesNoDlgRaised(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b0f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRSetIsSbSimYesNoDlgRaised();
  return;
}

/* RVA 0x3b0fe */
void MDrealloc(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b0fe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MDrealloc();
  return;
}

/* RVA 0x3b104 */
void GRsetssu(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b104. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRsetssu();
  return;
}

/* RVA 0x3b10a */
void GRsetiap2(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b10a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRsetiap2();
  return;
}

/* RVA 0x3b110 */
void GRsetcat(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b110. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRsetcat();
  return;
}

/* RVA 0x3b116 */
void GRsetscp(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b116. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRsetscp();
  return;
}

/* RVA 0x3b11c */
void GRqryscp(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b11c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRqryscp();
  return;
}

/* RVA 0x3b122 */
void GRrstscp(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b122. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRrstscp();
  return;
}

/* RVA 0x3b128 */
void VRupdbox(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b128. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  VRupdbox();
  return;
}

/* RVA 0x3b12e */
void MDmalloc(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b12e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MDmalloc();
  return;
}

/* RVA 0x3b134 */
void new_dialog(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b134. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  new_dialog();
  return;
}

/* RVA 0x3b13a */
void drive_dialog(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b13a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  drive_dialog();
  return;
}

/* RVA 0x3b140 */
void define_dialog_box(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b140. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  define_dialog_box();
  return;
}

/* RVA 0x3b146 */
void open_dialog_box(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b146. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  open_dialog_box();
  return;
}

/* RVA 0x3b14c */
void GRinqfop(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b14c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRinqfop();
  return;
}

/* RVA 0x3b152 */
void GRsetcannedpdf(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b152. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRsetcannedpdf();
  return;
}

/* RVA 0x3b158 */
void GRsetdly(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b158. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRsetdly();
  return;
}

/* RVA 0x3b15e */
void GRinqdly(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b15e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRinqdly();
  return;
}

/* RVA 0x3b164 */
void GRsetnxt(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b164. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRsetnxt();
  return;
}

/* RVA 0x3b16a */
void GRqryblk(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b16a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRqryblk();
  return;
}

/* RVA 0x3b170 */
void EXstrbox(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b170. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EXstrbox();
  return;
}

/* RVA 0x3b176 */
void MDcnvhnk(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b176. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MDcnvhnk();
  return;
}

/* RVA 0x3b17c */
void MDfndito(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b17c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MDfndito();
  return;
}

/* RVA 0x3b182 */
void MDlenito(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b182. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MDlenito();
  return;
}

/* RVA 0x3b188 */
void GRinqprp(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b188. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRinqprp();
  return;
}

/* RVA 0x3b18e */
void GRseteditrun(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b18e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRseteditrun();
  return;
}

/* RVA 0x3b194 */
void GRinqcpt(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b194. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRinqcpt();
  return;
}

/* RVA 0x3b19a */
void GRinqaped(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b19a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRinqaped();
  return;
}

/* RVA 0x3b1a0 */
void MDfndrbv(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b1a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MDfndrbv();
  return;
}

/* RVA 0x3b1a6 */
void MDgetvar(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b1a6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MDgetvar();
  return;
}

/* RVA 0x3b1ac */
void MDsetvar(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b1ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MDsetvar();
  return;
}

/* RVA 0x3b1b2 */
void GRset_in_canned(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b1b2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRset_in_canned();
  return;
}

/* RVA 0x3b1b8 */
void GRcreateAnalysisSumbuf(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b1b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRcreateAnalysisSumbuf();
  return;
}

/* RVA 0x3b1be */
void GRmoveAnalysisSumbuf(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b1be. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRmoveAnalysisSumbuf();
  return;
}

/* RVA 0x3b1c4 */
void GRdeleteAnalysisSumbuf(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b1c4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRdeleteAnalysisSumbuf();
  return;
}

/* RVA 0x3b1ca */
void OPdelete_notify(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b1ca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  OPdelete_notify();
  return;
}

/* RVA 0x3b1d0 */
void GRbumpsumcount(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b1d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GRbumpsumcount();
  return;
}

/* RVA 0x3b1d6 */
void open_report_box(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b1d6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  open_report_box();
  return;
}

/* RVA 0x3b1dc */
void MDgetedd(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b1dc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MDgetedd();
  return;
}

/* RVA 0x3b1e2 */
void XCrcmnd(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b1e2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  XCrcmnd();
  return;
}

/* RVA 0x3b1e8 */
void XCread(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b1e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  XCread();
  return;
}

/* RVA 0x3b1ee */
void XCwrite(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b1ee. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  XCwrite();
  return;
}

/* RVA 0x3b1f4 */
void AreDependenciesComplete(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b1f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  AreDependenciesComplete();
  return;
}

/* RVA 0x3b1fa */
void GEmain(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b1fa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GEmain();
  return;
}

/* RVA 0x3b200 */
void GEtim_buf(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b200. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GEtim_buf();
  return;
}

/* RVA 0x3b206 */
void GEpropse(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b206. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GEpropse();
  return;
}

/* RVA 0x3b20c */
void IsFlowSecComplete(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b20c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IsFlowSecComplete();
  return;
}

/* RVA 0x3b212 */
void IsFlowSecBlkStrmComplete(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b212. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IsFlowSecBlkStrmComplete();
  return;
}

/* RVA 0x3b218 */
void GEgendel(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b218. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GEgendel();
  return;
}

/* RVA 0x3b21e */
void GEgenpar(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b21e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GEgenpar();
  return;
}

/* RVA 0x3b224 */
void GEloorec(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b224. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GEloorec();
  return;
}

/* RVA 0x3b22a */
void GEaddbef(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b22a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GEaddbef();
  return;
}

/* RVA 0x3b230 */
void GEwrtwrd(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b230. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GEwrtwrd();
  return;
}

/* RVA 0x3b236 */
void generate_polymers(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b236. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  generate_polymers();
  return;
}

/* RVA 0x3b242 */
void SMSetPropTableID(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b242. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SMSetPropTableID();
  return;
}

/* RVA 0x3b248 */
void SMgenpropset(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b248. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SMgenpropset();
  return;
}

/* RVA 0x3b24e */
void GEopenfile(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b24e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GEopenfile();
  return;
}

/* RVA 0x3b254 */
void GEclosefile(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b254. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GEclosefile();
  return;
}

/* RVA 0x3b25a */
void GEwritefile(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b25a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GEwritefile();
  return;
}

/* RVA 0x3b260 */
void isFlowsheet(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b260. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  isFlowsheet();
  return;
}

/* RVA 0x3b266 */
void SMgetproptype(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b266. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SMgetproptype();
  return;
}

/* RVA 0x3b26c */
void CheckFlowSecGen(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b26c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CheckFlowSecGen();
  return;
}

/* RVA 0x3b272 */
void MMGetSuppress(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b272. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MMGetSuppress();
  return;
}

/* RVA 0x3b278 */
void MMMessageBoxDefault(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b278. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MMMessageBoxDefault();
  return;
}

/* RVA 0x3b27e */
int __cdecl MMAfxMessageBox(char *param_1,uint param_2,int param_3,uint param_4)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003b27e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = MMAfxMessageBox(param_1,param_2,param_3,param_4);
  return iVar1;
}

/* RVA 0x3b284 */
void GetEditorTempTxtFileName(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b284. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetEditorTempTxtFileName();
  return;
}

/* RVA 0x3b28a */
void GenerateErrorInfo(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b28a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GenerateErrorInfo();
  return;
}

/* RVA 0x3b290 */
void PostMainWndMessage(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b290. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  PostMainWndMessage();
  return;
}

/* RVA 0x3b296 */
void MMCreateStreamOnFileEx(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b296. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MMCreateStreamOnFileEx();
  return;
}

/* RVA 0x3b29c */
void MMGetVisibleSuppress(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b29c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MMGetVisibleSuppress();
  return;
}

/* RVA 0x3b2a2 */
void MMMessageBox(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b2a2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MMMessageBox();
  return;
}

/* RVA 0x3b2a8 */
void DeleteTempFile(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b2a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DeleteTempFile();
  return;
}

/* RVA 0x3b2ae */
void CreateApwnLibrariesTest(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b2ae. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CreateApwnLibrariesTest();
  return;
}

/* RVA 0x3b2b4 */
void START_ASPEN_PROCESS(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b2b4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  START_ASPEN_PROCESS();
  return;
}

/* RVA 0x3b2ba */
void MMDisplayConnectError(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b2ba. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MMDisplayConnectError();
  return;
}

/* RVA 0x3b2c0 */
void STerrbox(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b2c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  STerrbox();
  return;
}

/* RVA 0x3b2c6 */
void Ordinal_78(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b2c6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_78();
  return;
}

/* RVA 0x3b2cc */
void Ordinal_21(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b2cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_21();
  return;
}

/* RVA 0x3b2d2 */
void DCGetEngineServer(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b2d2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DCGetEngineServer();
  return;
}

/* RVA 0x3b2d8 */
void Ordinal_79(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b2d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_79();
  return;
}

/* RVA 0x3b2de */
void Ordinal_77(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b2de. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_77();
  return;
}

/* RVA 0x3b2e4 */
void Ordinal_99(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b2e4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_99();
  return;
}

/* RVA 0x3b2ea */
void Ordinal_115(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b2ea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_115();
  return;
}

/* RVA 0x3b2f0 */
void Ordinal_116(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b2f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_116();
  return;
}

/* RVA 0x3b2f6 */
void DCOM_INIT_THREAD(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b2f6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DCOM_INIT_THREAD();
  return;
}

/* RVA 0x3b2fc */
void DCOM_TERMINATE_THREAD(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b2fc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DCOM_TERMINATE_THREAD();
  return;
}

/* RVA 0x3b302 */
void DCHasEngineServer(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b302. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DCHasEngineServer();
  return;
}

/* RVA 0x3b308 */
void DCReleaseServer(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b308. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DCReleaseServer();
  return;
}

/* RVA 0x3b30e */
void Ordinal_80(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b30e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_80();
  return;
}

/* RVA 0x3b314 */
void Ordinal_82(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b314. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_82();
  return;
}

/* RVA 0x3b31a */
void EOClearError(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b31a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EOClearError();
  return;
}

/* RVA 0x3b320 */
void EOInqError(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b320. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EOInqError();
  return;
}

/* RVA 0x3b326 */
void Ordinal_69(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b326. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_69();
  return;
}

/* RVA 0x3b32c */
void EOGetError(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b32c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EOGetError();
  return;
}

/* RVA 0x3b332 */
void Ordinal_83(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b332. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_83();
  return;
}

/* RVA 0x3b338 */
void MVGetRegistryKey(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b338. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MVGetRegistryKey();
  return;
}

/* RVA 0x3b33e */
void MVGetProductRegistryName(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b33e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MVGetProductRegistryName();
  return;
}

/* RVA 0x3b344 */
void MVGetProductCode(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b344. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MVGetProductCode();
  return;
}

/* RVA 0x3b34a */
void MVGetI18nProductName(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b34a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MVGetI18nProductName();
  return;
}

/* RVA 0x3b350 */
void MVGetProductName(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b350. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MVGetProductName();
  return;
}

/* RVA 0x3b356 */
void MVGetMajorI(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b356. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MVGetMajorI();
  return;
}

/* RVA 0x3b35c */
void MVGetPointI(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b35c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MVGetPointI();
  return;
}

/* RVA 0x3b362 */
void * __cdecl operator_new(__uint64 param_1)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003b362. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = operator_new(param_1);
  return pvVar1;
}

/* RVA 0x3b368 */
void __cdecl operator_delete(void *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b368. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  operator_delete(param_1);
  return;
}

/* RVA 0x3b36e */
void __cdecl AfxThrowMemoryException(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b36e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  AfxThrowMemoryException();
  return;
}

/* RVA 0x3b374 */
void __cdecl AfxThrowOleException(long param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b374. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  AfxThrowOleException(param_1);
  return;
}

/* RVA 0x3b380 */
void __thiscall CCmdTarget::CCmdTarget(CCmdTarget *this)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b380. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CCmdTarget(this);
  return;
}

/* RVA 0x3b386 */
int __thiscall
CCmdTarget::OnCmdMsg
          (CCmdTarget *this,uint param_1,int param_2,void *param_3,AFX_CMDHANDLERINFO *param_4)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003b386. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = OnCmdMsg(this,param_1,param_2,param_3,param_4);
  return iVar1;
}

/* RVA 0x3b38c */
void __thiscall CCmdTarget::OnFinalRelease(CCmdTarget *this)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b38c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  OnFinalRelease(this);
  return;
}

/* RVA 0x3b392 */
int __thiscall CCmdTarget::IsInvokeAllowed(CCmdTarget *this,long param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003b392. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = IsInvokeAllowed(this,param_1);
  return iVar1;
}

/* RVA 0x3b398 */
int __thiscall CCmdTarget::GetDispatchIID(CCmdTarget *this,_GUID *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003b398. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = GetDispatchIID(this,param_1);
  return iVar1;
}

/* RVA 0x3b39e */
uint __thiscall CCmdTarget::GetTypeInfoCount(CCmdTarget *this)

{
  uint uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003b39e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = GetTypeInfoCount(this);
  return uVar1;
}

/* RVA 0x3b3a4 */
CTypeLibCache * __thiscall CCmdTarget::GetTypeLibCache(CCmdTarget *this)

{
  CTypeLibCache *pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003b3a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = GetTypeLibCache(this);
  return pCVar1;
}

/* RVA 0x3b3aa */
long __thiscall CCmdTarget::GetTypeLib(CCmdTarget *this,ulong param_1,ITypeLib **param_2)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003b3aa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = GetTypeLib(this,param_1,param_2);
  return lVar1;
}

/* RVA 0x3b3b0 */
void __thiscall CCmdTarget::~CCmdTarget(CCmdTarget *this)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b3b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ~CCmdTarget(this);
  return;
}

/* RVA 0x3b3bc */
AFX_OLECMDMAP * __thiscall CCmdTarget::GetCommandMap(CCmdTarget *this)

{
  AFX_OLECMDMAP *pAVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003b3bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pAVar1 = GetCommandMap(this);
  return pAVar1;
}

/* RVA 0x3b3c2 */
AFX_DISPMAP * __thiscall CCmdTarget::GetDispatchMap(CCmdTarget *this)

{
  AFX_DISPMAP *pAVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003b3c2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pAVar1 = GetDispatchMap(this);
  return pAVar1;
}

/* RVA 0x3b3c8 */
AFX_CONNECTIONMAP * __thiscall CCmdTarget::GetConnectionMap(CCmdTarget *this)

{
  AFX_CONNECTIONMAP *pAVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003b3c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pAVar1 = GetConnectionMap(this);
  return pAVar1;
}

/* RVA 0x3b3ce */
AFX_INTERFACEMAP * __cdecl CCmdTarget::GetThisInterfaceMap(void)

{
  AFX_INTERFACEMAP *pAVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003b3ce. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pAVar1 = GetThisInterfaceMap();
  return pAVar1;
}

/* RVA 0x3b3da */
ulong __thiscall CCmdTarget::ExternalRelease(CCmdTarget *this)

{
  ulong uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003b3da. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = ExternalRelease(this);
  return uVar1;
}

/* RVA 0x3b3e0 */
int __thiscall CCmdTarget::OnCreateAggregates(CCmdTarget *this)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003b3e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = OnCreateAggregates(this);
  return iVar1;
}

/* RVA 0x3b3e6 */
IUnknown * __thiscall CCmdTarget::GetInterfaceHook(CCmdTarget *this,void *param_1)

{
  IUnknown *pIVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003b3e6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pIVar1 = GetInterfaceHook(this,param_1);
  return pIVar1;
}

/* RVA 0x3b3ec */
int __thiscall CCmdTarget::GetExtraConnectionPoints(CCmdTarget *this,CPtrArray *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003b3ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = GetExtraConnectionPoints(this,param_1);
  return iVar1;
}

/* RVA 0x3b3f2 */
IConnectionPoint * __thiscall CCmdTarget::GetConnectionHook(CCmdTarget *this,_GUID *param_1)

{
  IConnectionPoint *pIVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003b3f2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pIVar1 = GetConnectionHook(this,param_1);
  return pIVar1;
}

/* RVA 0x3b3f8 */
int __cdecl
AfxConnectionAdvise(IUnknown *param_1,_GUID *param_2,IUnknown *param_3,int param_4,ulong *param_5)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003b3f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = AfxConnectionAdvise(param_1,param_2,param_3,param_4,param_5);
  return iVar1;
}

/* RVA 0x3b3fe */
int __cdecl
AfxConnectionUnadvise(IUnknown *param_1,_GUID *param_2,IUnknown *param_3,int param_4,ulong param_5)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003b3fe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = AfxConnectionUnadvise(param_1,param_2,param_3,param_4,param_5);
  return iVar1;
}

/* RVA 0x3b40a */
AFX_MODULE_STATE * __cdecl AfxGetModuleState(void)

{
  AFX_MODULE_STATE *pAVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003b40a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pAVar1 = AfxGetModuleState();
  return pAVar1;
}

/* RVA 0x3b410 */
void __cdecl operator_delete__(void *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b410. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  operator_delete__(param_1);
  return;
}

/* RVA 0x3b416 */
void __cdecl AfxThrowArchiveException(int param_1,char *param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b416. Too many branches */
                    /* WARNING: Subroutine does not return */
                    /* WARNING: Treating indirect jump as call */
  AfxThrowArchiveException(param_1,param_2);
  return;
}

/* RVA 0x3b41c */
__uint64 __cdecl AfxReadStringLength(CArchive *param_1,int *param_2)

{
  __uint64 _Var1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003b41c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _Var1 = AfxReadStringLength(param_1,param_2);
  return _Var1;
}

/* RVA 0x3b422 */
void __thiscall
CArchive::CArchive(CArchive *this,CFile *param_1,uint param_2,int param_3,void *param_4)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b422. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CArchive(this,param_1,param_2,param_3,param_4);
  return;
}

/* RVA 0x3b428 */
void __thiscall CArchive::~CArchive(CArchive *this)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b428. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ~CArchive(this);
  return;
}

/* RVA 0x3b42e */
uint __thiscall CArchive::Read(CArchive *this,void *param_1,uint param_2)

{
  uint uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003b42e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = Read(this,param_1,param_2);
  return uVar1;
}

/* RVA 0x3b434 */
void __thiscall CArchive::FillBuffer(CArchive *this,uint param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b434. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FillBuffer(this,param_1);
  return;
}

/* RVA 0x3b43a */
CWinThread * __cdecl
AfxBeginThread(_func_uint_void_ptr *param_1,void *param_2,int param_3,uint param_4,ulong param_5,
              _SECURITY_ATTRIBUTES *param_6)

{
  CWinThread *pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003b43a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = AfxBeginThread(param_1,param_2,param_3,param_4,param_5,param_6);
  return pCVar1;
}

/* RVA 0x3b440 */
void __thiscall COleStreamFile::COleStreamFile(COleStreamFile *this,IStream *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b440. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  COleStreamFile(this,param_1);
  return;
}

/* RVA 0x3b446 */
void __thiscall COleStreamFile::~COleStreamFile(COleStreamFile *this)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b446. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ~COleStreamFile(this);
  return;
}

/* RVA 0x3b44c */
void * __cdecl operator_new__(__uint64 param_1)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003b44c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = operator_new__(param_1);
  return pvVar1;
}

/* RVA 0x3b452 */
void __thiscall
AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(AFX_MAINTAIN_STATE2 *this,AFX_MODULE_STATE *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b452. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  AFX_MAINTAIN_STATE2(this,param_1);
  return;
}

/* RVA 0x3b458 */
void __thiscall AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(AFX_MAINTAIN_STATE2 *this)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b458. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ~AFX_MAINTAIN_STATE2(this);
  return;
}

/* RVA 0x3b45e */
CWinThread * __cdecl AfxGetThread(void)

{
  CWinThread *pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003b45e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = AfxGetThread();
  return pCVar1;
}

/* RVA 0x3b464 */
void __thiscall
CDynLinkLibrary::CDynLinkLibrary(CDynLinkLibrary *this,AFX_EXTENSION_MODULE *param_1,int param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b464. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CDynLinkLibrary(this,param_1,param_2);
  return;
}

/* RVA 0x3b46a */
int __cdecl AfxInitExtensionModule(AFX_EXTENSION_MODULE *param_1,HINSTANCE__ *param_2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003b46a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = AfxInitExtensionModule(param_1,param_2);
  return iVar1;
}

/* RVA 0x3b470 */
long __cdecl AfxDllCanUnloadNow(void)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003b470. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = AfxDllCanUnloadNow();
  return lVar1;
}

/* RVA 0x3b476 */
void __thiscall COleVariant::COleVariant(COleVariant *this,long param_1,ushort param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b476. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  COleVariant(this,param_1,param_2);
  return;
}

/* RVA 0x3b47c */
AFX_INTERFACEMAP * __thiscall CCmdTarget::GetInterfaceMap(CCmdTarget *this)

{
  AFX_INTERFACEMAP *pAVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003b47c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pAVar1 = GetInterfaceMap(this);
  return pAVar1;
}

/* RVA 0x3b482 */
AFX_EVENTSINKMAP * __thiscall CCmdTarget::GetEventSinkMap(CCmdTarget *this)

{
  AFX_EVENTSINKMAP *pAVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003b482. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pAVar1 = GetEventSinkMap(this);
  return pAVar1;
}

/* RVA 0x3b488 */
CRuntimeClass * __cdecl CWinThread::GetThisClass(void)

{
  CRuntimeClass *pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003b488. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = GetThisClass();
  return pCVar1;
}

/* RVA 0x3b48e */
void __thiscall CWinThread::CWinThread(CWinThread *this)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b48e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CWinThread(this);
  return;
}

/* RVA 0x3b494 */
int __thiscall CWinThread::Run(CWinThread *this)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003b494. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = Run(this);
  return iVar1;
}

/* RVA 0x3b49a */
int __thiscall CWinThread::PreTranslateMessage(CWinThread *this,tagMSG *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003b49a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = PreTranslateMessage(this,param_1);
  return iVar1;
}

/* RVA 0x3b4a0 */
int __thiscall CWinThread::PumpMessage(CWinThread *this)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003b4a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = PumpMessage(this);
  return iVar1;
}

/* RVA 0x3b4a6 */
int __thiscall CWinThread::OnIdle(CWinThread *this,long param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003b4a6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = OnIdle(this,param_1);
  return iVar1;
}

/* RVA 0x3b4ac */
int __thiscall CWinThread::IsIdleMessage(CWinThread *this,tagMSG *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003b4ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = IsIdleMessage(this,param_1);
  return iVar1;
}

/* RVA 0x3b4b2 */
int __thiscall CWinThread::ExitInstance(CWinThread *this)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003b4b2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = ExitInstance(this);
  return iVar1;
}

/* RVA 0x3b4b8 */
__int64 __thiscall
CWinThread::ProcessWndProcException(CWinThread *this,CException *param_1,tagMSG *param_2)

{
  __int64 _Var1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003b4b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _Var1 = ProcessWndProcException(this,param_1,param_2);
  return _Var1;
}

/* RVA 0x3b4be */
int __thiscall CWinThread::ProcessMessageFilter(CWinThread *this,int param_1,tagMSG *param_2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003b4be. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = ProcessMessageFilter(this,param_1,param_2);
  return iVar1;
}

/* RVA 0x3b4c4 */
CWnd * __thiscall CWinThread::GetMainWnd(CWinThread *this)

{
  CWnd *pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003b4c4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = GetMainWnd(this);
  return pCVar1;
}

/* RVA 0x3b4ca */
void __thiscall CWinThread::~CWinThread(CWinThread *this)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b4ca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ~CWinThread(this);
  return;
}

/* RVA 0x3b4d0 */
void __thiscall CWinThread::Delete(CWinThread *this)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b4d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Delete(this);
  return;
}

/* RVA 0x3b4d6 */
void __cdecl AfxWriteStringLength(CArchive *param_1,__uint64 param_2,int param_3)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b4d6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  AfxWriteStringLength(param_1,param_2,param_3);
  return;
}

/* RVA 0x3b4dc */
void __thiscall CArchive::Write(CArchive *this,void *param_1,uint param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b4dc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Write(this,param_1,param_2);
  return;
}

/* RVA 0x3b4e2 */
void __thiscall CArchive::Flush(CArchive *this)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b4e2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Flush(this);
  return;
}

/* RVA 0x3b4e8 */
void __thiscall CArchive::Close(CArchive *this)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b4e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Close(this);
  return;
}

/* RVA 0x3b4ee */
CWinThread * __cdecl
AfxBeginThread(CRuntimeClass *param_1,int param_2,uint param_3,ulong param_4,
              _SECURITY_ATTRIBUTES *param_5)

{
  CWinThread *pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003b4ee. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = AfxBeginThread(param_1,param_2,param_3,param_4,param_5);
  return pCVar1;
}

/* RVA 0x3b4f4 */
void __cdecl AfxClassInit(CRuntimeClass *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b4f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  AfxClassInit(param_1);
  return;
}

/* RVA 0x3b4fa */
CRuntimeClass * __cdecl CObject::GetThisClass(void)

{
  CRuntimeClass *pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018003b4fa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = GetThisClass();
  return pCVar1;
}

/* RVA 0x3b500 */
/* Library Function - Single Match
    __GSHandlerCheck
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}

/* RVA 0x3b520 */
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

/* RVA 0x3b590 */
/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie == DAT_1800516d8) && ((short)(_StackCookie >> 0x30) == 0)) {
    return;
  }
  FUN_18003b610();
  return;
}

/* RVA 0x3b5b0 */
undefined8 * FUN_18003b5b0(undefined8 *param_1,ulonglong param_2)

{
  *param_1 = type_info::vftable;
  if ((param_2 & 1) != 0) {
    FUN_180001300(param_1);
  }
  return param_1;
}

/* RVA 0x3b5dc */
/* Library Function - Single Match
    __raise_securityfailure
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void __raise_securityfailure(_EXCEPTION_POINTERS *param_1)

{
  HANDLE pvVar1;
  
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter(param_1);
  pvVar1 = GetCurrentProcess();
                    /* WARNING: Could not recover jumptable at 0x00018003b609. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  TerminateProcess(pvVar1,0xc0000409);
  return;
}

/* RVA 0x3b610 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_18003b610(void)

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
  *(undefined8 *)(puVar3 + -8) = 0x18003b63b;
  capture_previous_context((PCONTEXT)&DAT_1800532a0);
  _DAT_180053210 = *(undefined8 *)(puVar3 + 0x38);
  _DAT_180053338 = puVar3 + 0x40;
  _DAT_180053320 = *(undefined8 *)(puVar3 + 0x40);
  _DAT_180053200 = 0xc0000409;
  _DAT_180053204 = 1;
  _DAT_180053218 = 1;
  DAT_180053220 = 2;
  *(undefined8 *)(puVar3 + 0x20) = DAT_1800516d8;
  *(undefined8 *)(puVar3 + 0x28) = DAT_1800516d0;
  *(undefined8 *)(puVar3 + -8) = 0x18003b6dd;
  DAT_180053398 = _DAT_180053210;
  __raise_securityfailure((_EXCEPTION_POINTERS *)&PTR_DAT_180043ec0);
  return;
}

/* RVA 0x3b6e4 */
void FUN_18003b6e4(void)

{
  FUN_18003b6f8(8);
  return;
}

/* RVA 0x3b6f8 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_18003b6f8(undefined4 param_1)

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
  *(undefined8 *)(puVar3 + -8) = 0x18003b723;
  capture_current_context((PCONTEXT)&DAT_1800532a0);
  _DAT_180053210 = *(undefined8 *)(puVar3 + 0x28);
  _DAT_180053338 = puVar3 + 0x30;
  _DAT_180053200 = 0xc0000409;
  _DAT_180053204 = 1;
  _DAT_180053218 = 1;
  DAT_180053220 = (ulonglong)*(uint *)(puVar3 + 0x30);
  *(undefined8 *)(puVar3 + -8) = 0x18003b78f;
  DAT_180053398 = _DAT_180053210;
  __raise_securityfailure((_EXCEPTION_POINTERS *)&PTR_DAT_180043ec0);
  return;
}

/* RVA 0x3b794 */
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

/* RVA 0x3b804 */
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

/* RVA 0x3b878 */
/* Library Function - Multiple Matches With Different Base Names
    __GSHandlerCheck_EH
    __GSHandlerCheck_EH4
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void FID_conflict___GSHandlerCheck_EH
               (longlong param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_4 + 0x38);
  __GSHandlerCheckCommon(param_2,param_4);
  if ((*(uint *)(lVar1 + 4) & ((*(uint *)(param_1 + 4) & 0x66) != 0) + 1) != 0) {
    __CxxFrameHandler4(param_1,param_2,param_3,param_4);
  }
  return;
}

/* RVA 0x3b910 */
/* WARNING: This is an inlined function */
/* Library Function - Single Match
    __chkstk
   
   Libraries: Visual Studio 2005, Visual Studio 2008, Visual Studio 2010, Visual Studio 2012 */

void __chkstk(void)

{
  undefined1 *in_RAX;
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 local_res8 [32];
  
  puVar1 = local_res8 + -(longlong)in_RAX;
  if (local_res8 < in_RAX) {
    puVar1 = (undefined1 *)0x0;
  }
  if (puVar1 < StackLimit) {
    puVar2 = StackLimit;
    do {
      puVar2 = puVar2 + -0x1000;
      *puVar2 = 0;
    } while ((undefined1 *)((ulonglong)puVar1 & 0xfffffffffffff000) != puVar2);
  }
  return;
}

/* RVA 0x3b960 */
void FUN_18003b960(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b967. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  InitializeSListHead(&DAT_180053770);
  return;
}

/* RVA 0x3b970 */
void FUN_18003b970(void)

{
  __std_type_info_destroy_list(&DAT_180053770);
  return;
}

/* RVA 0x3b97c */
/* Library Function - Single Match
    __GSHandlerCheck_SEH
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __GSHandlerCheck_SEH
               (_EXCEPTION_RECORD *param_1,void *param_2,_CONTEXT *param_3,
               _DISPATCHER_CONTEXT *param_4)

{
  uint uVar1;
  uint *puVar2;
  
  puVar2 = *(uint **)(param_4 + 0x38);
  uVar1 = *puVar2;
  __GSHandlerCheckCommon(param_2,(longlong)param_4);
  if ((puVar2[(ulonglong)uVar1 * 4 + 1] & ((param_1->ExceptionFlags & 0x66) != 0) + 1) != 0) {
    __C_specific_handler(param_1,param_2,param_3,param_4);
  }
  return;
}

/* RVA 0x3ba04 */
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
LAB_18003ba32:
    uVar2 = uVar2 & 0xffffffffffffff00;
  }
  else {
    do {
      uVar2 = 0;
      LOCK();
      bVar1 = DAT_180053788 == 0;
      if (bVar1) {
        DAT_180053788 = *(ulonglong *)((longlong)Self + 8);
      }
      else {
        uVar2 = DAT_180053788;
      }
      UNLOCK();
      if (bVar1) goto LAB_18003ba32;
    } while (*(ulonglong *)((longlong)Self + 8) != uVar2);
    uVar2 = CONCAT71((int7)(uVar2 >> 8),1);
  }
  return uVar2;
}

/* RVA 0x3ba40 */
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
    uVar3 = SBsubflowsheet();
    uVar3 = _configure_narrow_argv(uVar3 & 0xffffffff);
    if ((int)uVar3 != 0) {
      return uVar3 & 0xffffffffffffff00;
    }
    uVar2 = _initialize_narrow_environment();
  }
  else {
    uVar2 = FUN_18003c2a0();
  }
  return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
}

/* RVA 0x3ba74 */
bool FUN_18003ba74(void)

{
  undefined8 uVar1;
  
  uVar1 = FUN_18003bbbc(0);
  return (char)uVar1 != '\0';
}

/* RVA 0x3ba8c */
undefined1 FUN_18003ba8c(void)

{
  char cVar1;
  
  cVar1 = FUN_18003ccf4();
  if (cVar1 != '\0') {
    cVar1 = FUN_18003ccf4();
    if (cVar1 != '\0') {
      return 1;
    }
    FUN_18003ccf4();
  }
  return 0;
}

/* RVA 0x3bab4 */
undefined1 FUN_18003bab4(void)

{
  FUN_18003ccf4();
  FUN_18003ccf4();
  return 1;
}

/* RVA 0x3bacc */
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
    (*(code *)PTR__guard_dispatch_icall_18003f628)(param_1,0,param_3);
  }
  _seh_filter_dll(param_5,param_6);
  return;
}

/* RVA 0x3bb2c */
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
    _execute_onexit_table(&DAT_180053798);
    return;
  }
  uVar2 = EXmsgbox();
  if ((int)uVar2 == 0) {
    _cexit();
  }
  return;
}

/* RVA 0x3bb5c */
void FUN_18003bb5c(void)

{
  FUN_18003ccf4();
  FUN_18003ccf4();
  return;
}

/* RVA 0x3bb70 */
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
    DAT_180053790 = 1;
  }
  FUN_18003c2a0();
  cVar1 = FUN_18003ccf4();
  uVar2 = extraout_var;
  if (cVar1 != '\0') {
    cVar1 = FUN_18003ccf4();
    if (cVar1 != '\0') {
      return CONCAT71(extraout_var_00,1);
    }
    FUN_18003ccf4();
    uVar2 = extraout_var_01;
  }
  return (ulonglong)uVar2 << 8;
}

/* RVA 0x3bbbc */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_18003bbbc(uint param_1)

{
  bool bVar1;
  ulonglong in_RAX;
  undefined7 extraout_var;
  
  if (DAT_180053791 == '\0') {
    if (1 < param_1) {
                    /* WARNING: Subroutine does not return */
      FUN_18003c460(5);
    }
    bVar1 = __scrt_is_ucrt_dll_in_use();
    if (((int)CONCAT71(extraout_var,bVar1) == 0) || (param_1 != 0)) {
      in_RAX = 0xffffffffffffffff;
      DAT_180053798 = _DAT_1800412d0;
      uRam00000001800537a0 = _UNK_1800412d8;
      _DAT_1800537a8 = 0xffffffffffffffff;
      _DAT_1800537b0 = _DAT_1800412d0;
      uRam00000001800537b8 = _UNK_1800412d8;
      _DAT_1800537c0 = 0xffffffffffffffff;
    }
    else {
      in_RAX = _initialize_onexit_table(&DAT_180053798);
      if (((int)in_RAX != 0) ||
         (in_RAX = _initialize_onexit_table(&DAT_1800537b0), (int)in_RAX != 0)) {
        return in_RAX & 0xffffffffffffff00;
      }
    }
    DAT_180053791 = '\x01';
  }
  return CONCAT71((int7)(in_RAX >> 8),1);
}

/* RVA 0x3bc48 */
ulonglong FUN_18003bc48(longlong param_1)

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
           param_1 - 0x180000000U < uVar1)) goto LAB_18003bcbe;
      }
      lVar4 = 0;
LAB_18003bcbe:
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

/* RVA 0x3bce0 */
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
    DAT_180053788 = 0;
    UNLOCK();
  }
  return;
}

/* RVA 0x3bd04 */
/* Library Function - Single Match
    __scrt_uninitialize_crt
   
   Library: Visual Studio 2019 Release */

undefined1 __scrt_uninitialize_crt(undefined8 param_1,char param_2)

{
  if ((DAT_180053790 == '\0') || (param_2 == '\0')) {
    FUN_18003ccf4();
    FUN_18003ccf4();
  }
  return 1;
}

/* RVA 0x3bd30 */
/* Library Function - Single Match
    _onexit
   
   Library: Visual Studio 2019 Release */

_onexit_t __cdecl _onexit(_onexit_t _Func)

{
  int iVar1;
  _onexit_t p_Var2;
  
  if (DAT_180053798 == -1) {
    iVar1 = _crt_atexit();
  }
  else {
    iVar1 = _register_onexit_function(&DAT_180053798);
  }
  p_Var2 = (_onexit_t)0x0;
  if (iVar1 == 0) {
    p_Var2 = _Func;
  }
  return p_Var2;
}

/* RVA 0x3bd6c */
/* Library Function - Single Match
    atexit
   
   Library: Visual Studio 2019 Release */

int __cdecl atexit(_func_5014 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = _onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}

/* RVA 0x3bd84 */
/* Library Function - Single Match
    _Init_thread_footer
   
   Library: Visual Studio 2019 Release */

void _Init_thread_footer(int *param_1)

{
  ulonglong uVar1;
  
  AcquireSRWLockExclusive((PSRWLOCK)&DAT_1800537d0);
  uVar1 = (ulonglong)_tls_index;
  DAT_1800516f4 = DAT_1800516f4 + 1;
  *param_1 = DAT_1800516f4;
  *(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + uVar1 * 8) + 4) = DAT_1800516f4;
  ReleaseSRWLockExclusive((PSRWLOCK)&DAT_1800537d0);
                    /* WARNING: Could not recover jumptable at 0x00018003bde6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WakeAllConditionVariable(&DAT_1800537c8);
  return;
}

/* RVA 0x3bdf0 */
void FUN_18003bdf0(int *param_1)

{
  AcquireSRWLockExclusive((PSRWLOCK)&DAT_1800537d0);
  do {
    if (*param_1 == 0) {
      *param_1 = -1;
LAB_18003be55:
                    /* WARNING: Could not recover jumptable at 0x00018003be61. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      ReleaseSRWLockExclusive((PSRWLOCK)&DAT_1800537d0);
      return;
    }
    if (*param_1 != -1) {
      *(undefined4 *)
       (*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) + 4) =
           DAT_1800516f4;
      goto LAB_18003be55;
    }
    SleepConditionVariableSRW
              ((PCONDITION_VARIABLE)&DAT_1800537c8,(PSRWLOCK)&DAT_1800537d0,0xffffffff,0);
  } while( true );
}

/* RVA 0x3be68 */
/* Library Function - Single Match
    void __cdecl `eh vector destructor iterator'(void * __ptr64,unsigned __int64,unsigned
   __int64,void (__cdecl*)(void * __ptr64))
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl
_eh_vector_destructor_iterator_
          (void *param_1,__uint64 param_2,__uint64 param_3,_func_void_void_ptr *param_4)

{
  void *pvVar1;
  
  pvVar1 = (void *)(param_2 * param_3 + (longlong)param_1);
  while( true ) {
    if (param_3 == 0) break;
    pvVar1 = (void *)((longlong)pvVar1 - param_2);
    (*(code *)PTR__guard_dispatch_icall_18003f628)(pvVar1);
    param_3 = param_3 - 1;
  }
  return;
}

/* RVA 0x3bed4 */
/* Library Function - Single Match
    void __cdecl __ArrayUnwind(void * __ptr64,unsigned __int64,unsigned __int64,void (__cdecl*)(void
   * __ptr64))
   
   Library: Visual Studio 2019 Release */

void __cdecl
__ArrayUnwind(void *param_1,__uint64 param_2,__uint64 param_3,_func_void_void_ptr *param_4)

{
  __uint64 _Var1;
  
  for (_Var1 = 0; _Var1 != param_3; _Var1 = _Var1 + 1) {
    param_1 = (void *)((longlong)param_1 - param_2);
    (*(code *)PTR__guard_dispatch_icall_18003f628)(param_1);
  }
  return;
}

/* RVA 0x3bf38 */
void __cdecl operator_delete__(void *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b410. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  operator_delete__(param_1);
  return;
}

/* RVA 0x3bf40 */
ulonglong FUN_18003bf40(undefined8 param_1,int param_2,longlong param_3)

{
  byte bVar1;
  ulonglong uVar2;
  undefined7 extraout_var;
  
  if (param_2 == 0) {
    bVar1 = FUN_18003c0a8(CONCAT71((int7)((ulonglong)param_1 >> 8),param_3 != 0));
    return CONCAT71(extraout_var,bVar1);
  }
  if (param_2 == 1) {
    uVar2 = FUN_18003bf90(param_1,param_3);
    return uVar2;
  }
  if (param_2 == 2) {
    bVar1 = FUN_18003ba8c();
  }
  else {
    if (param_2 != 3) {
      return 1;
    }
    bVar1 = FUN_18003bab4();
  }
  return (ulonglong)bVar1;
}

/* RVA 0x3bf90 */
undefined8 FUN_18003bf90(undefined8 param_1,undefined8 param_2)

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
    if (DAT_180053780 != 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18003c460(7);
    }
    DAT_180053780 = 1;
    bVar2 = FUN_18003ba74();
    if (bVar2) {
      FUN_18003c67c();
      FUN_18003b960();
      FUN_18003c658();
      iVar3 = _initterm_e(&DAT_18003f6d8,&DAT_18003f6e0);
      if ((iVar3 == 0) && (uVar6 = __scrt_dllmain_after_initialize_c(), (char)uVar6 != '\0')) {
        _initterm(&DAT_18003f650,&DAT_18003f6d0);
        DAT_180053780 = 2;
        bVar1 = false;
      }
    }
    __scrt_release_startup_lock((char)uVar5);
    if (!bVar1) {
      plVar7 = (longlong *)FUN_18003c674();
      if ((*plVar7 != 0) && (uVar8 = FUN_18003bc48((longlong)plVar7), (char)uVar8 != '\0')) {
        (*(code *)PTR__guard_dispatch_icall_18003f628)(param_1,2,param_2);
      }
      DAT_1800537dc = DAT_1800537dc + 1;
      return 1;
    }
  }
  return 0;
}

/* RVA 0x3c0a8 */
byte FUN_18003c0a8(undefined8 param_1)

{
  undefined1 uVar1;
  char cVar2;
  undefined8 uVar3;
  undefined7 uVar4;
  byte bVar5;
  
  uVar1 = (undefined1)param_1;
  if (DAT_1800537dc < 1) {
    bVar5 = 0;
  }
  else {
    DAT_1800537dc = DAT_1800537dc + -1;
    uVar3 = __scrt_acquire_startup_lock();
    if (DAT_180053780 != 2) {
                    /* WARNING: Subroutine does not return */
      FUN_18003c460(7);
    }
    __scrt_dllmain_uninitialize_c();
    FUN_18003b970();
    FUN_18003c6b8();
    DAT_180053780 = 0;
    uVar4 = (undefined7)((ulonglong)param_1 >> 8);
    __scrt_release_startup_lock((char)uVar3);
    cVar2 = __scrt_uninitialize_crt(CONCAT71(uVar4,uVar1),'\0');
    bVar5 = -(cVar2 != '\0') & 1;
    FUN_18003bb5c();
  }
  return bVar5;
}

/* RVA 0x3c12c */
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
  
  if ((param_2 == 0) && (DAT_1800537dc < 1)) {
    iVar4 = 0;
  }
  else {
    if (param_2 - 1 < 2) {
      if ((PTR_FUN_18003fbf8 != (undefined *)0x0) &&
         (iVar4 = (*(code *)PTR__guard_dispatch_icall_18003f628)(), iVar4 == 0)) {
        return 0;
      }
      uVar1 = FUN_18003bf40(param_1,param_2,(longlong)param_3);
      if ((int)uVar1 == 0) {
        return 0;
      }
    }
    uVar2 = FUN_1800063f0(param_1,param_2);
    iVar4 = (int)uVar2;
    if ((param_2 == 1) && (iVar4 == 0)) {
      pHVar3 = param_1;
      FUN_1800063f0(param_1,0);
      FUN_18003c0a8(CONCAT71((int7)((ulonglong)pHVar3 >> 8),param_3 != (void *)0x0));
      if (PTR_FUN_18003fbf8 != (undefined *)0x0) {
        (*(code *)PTR__guard_dispatch_icall_18003f628)(param_1,0,param_3);
      }
    }
    if ((param_2 == 0) || (param_2 == 3)) {
      uVar1 = FUN_18003bf40(param_1,param_2,(longlong)param_3);
      iVar4 = 0;
      if ((int)uVar1 != 0) {
        if (PTR_FUN_18003fbf8 == (undefined *)0x0) {
          iVar4 = 1;
        }
        else {
          iVar4 = (*(code *)PTR__guard_dispatch_icall_18003f628)(param_1,param_2,param_3);
        }
      }
    }
  }
  return iVar4;
}

/* RVA 0x3c260 */
void entry(HINSTANCE__ *param_1,ulong param_2,void *param_3)

{
  if (param_2 == 1) {
    __security_init_cookie();
  }
  dllmain_dispatch(param_1,param_2,param_3);
  return;
}

/* RVA 0x3c2a0 */
/* WARNING: Removing unreachable block (ram,0x00018003c36a) */
/* WARNING: Removing unreachable block (ram,0x00018003c2da) */
/* WARNING: Removing unreachable block (ram,0x00018003c2b3) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_18003c2a0(void)

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
    _DAT_180051708 = 0xffffffffffffffff;
    uVar7 = *puVar2 & 0xfff3ff0;
    _DAT_180051700 = 0x8000;
    if ((((uVar7 == 0x106c0) || (uVar7 == 0x20660)) || (uVar7 == 0x20670)) ||
       ((uVar7 - 0x30650 < 0x21 &&
        ((0x100010001U >> ((ulonglong)(uVar7 - 0x30650) & 0x3f) & 1) != 0)))) {
      DAT_1800537e0 = DAT_1800537e0 | 1;
    }
  }
  if (6 < *piVar1) {
    lVar3 = cpuid_Extended_Feature_Enumeration_info(7);
    uVar8 = *(uint *)(lVar3 + 4);
    if ((uVar8 >> 9 & 1) != 0) {
      DAT_1800537e0 = DAT_1800537e0 | 2;
    }
  }
  _DAT_1800516f8 = 1;
  DAT_1800516fc = 2;
  if ((uVar4 >> 0x14 & 1) != 0) {
    _DAT_1800516f8 = 2;
    DAT_1800516fc = 6;
    if (((uVar4 >> 0x1b & 1) != 0) && ((uVar4 >> 0x1c & 1) != 0)) {
      uVar5 = xinuse(0);
      bVar6 = in_XCR0 & (byte)uVar5;
      if ((bVar6 & 6) == 6) {
        _DAT_1800516f8 = 3;
        DAT_1800516fc = 0xe;
        if ((uVar8 & 0x20) != 0) {
          _DAT_1800516f8 = 5;
          DAT_1800516fc = 0x2e;
          if (((uVar8 & 0xd0030000) == 0xd0030000) && ((bVar6 & 0xe0) == 0xe0)) {
            DAT_1800516fc = 0x6e;
            _DAT_1800516f8 = 6;
          }
        }
      }
    }
  }
  return 0;
}

/* RVA 0x3c44c */
/* Library Function - Single Match
    __scrt_is_ucrt_dll_in_use
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

bool __scrt_is_ucrt_dll_in_use(void)

{
  return DAT_180051730 != 0;
}

/* RVA 0x3c458 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_18003c458(void)

{
  _DAT_1800537e4 = 0;
  return;
}

/* RVA 0x3c460 */
void FUN_18003c460(undefined4 param_1)

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
  *(undefined8 *)(puVar4 + -8) = 0x18003c494;
  FUN_18003c458();
  *(undefined8 *)(puVar4 + -8) = 0x18003c4a5;
  memset(local_4d8,0,0x4d0);
  *(undefined8 *)(puVar4 + -8) = 0x18003c4af;
  RtlCaptureContext(local_4d8);
  *(undefined8 *)(puVar4 + -8) = 0x18003c4c9;
  FunctionEntry = RtlLookupFunctionEntry(local_3e0,&local_res10,(PUNWIND_HISTORY_TABLE)0x0);
  if (FunctionEntry != (PRUNTIME_FUNCTION)0x0) {
    *(undefined8 *)(puVar4 + 0x38) = 0;
    *(undefined1 **)(puVar4 + 0x30) = local_res18;
    *(undefined1 **)(puVar4 + 0x28) = local_res20;
    *(undefined1 **)(puVar4 + 0x20) = local_4d8;
    *(undefined8 *)(puVar4 + -8) = 0x18003c50a;
    RtlVirtualUnwind(0,local_res10,local_3e0,FunctionEntry,*(PCONTEXT *)(puVar4 + 0x20),
                     *(PVOID **)(puVar4 + 0x28),*(PDWORD64 *)(puVar4 + 0x30),
                     *(PKNONVOLATILE_CONTEXT_POINTERS *)(puVar4 + 0x38));
  }
  local_440 = local_res18 + -0x10;
  *(undefined8 *)(puVar4 + -8) = 0x18003c53c;
  memset(puVar4 + 0x50,0,0x98);
  *(undefined8 *)(puVar4 + 0x60) = unaff_retaddr;
  *(undefined4 *)(puVar4 + 0x50) = 0x40000015;
  *(undefined4 *)(puVar4 + 0x54) = 1;
  *(undefined8 *)(puVar4 + -8) = 0x18003c55e;
  BVar2 = IsDebuggerPresent();
  *(undefined1 **)(puVar4 + 0x40) = puVar4 + 0x50;
  *(undefined1 **)(puVar4 + 0x48) = local_4d8;
  *(undefined8 *)(puVar4 + -8) = 0x18003c57f;
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  *(undefined8 *)(puVar4 + -8) = 0x18003c58a;
  LVar3 = UnhandledExceptionFilter((_EXCEPTION_POINTERS *)(puVar4 + 0x40));
  if ((LVar3 == 0) && (BVar2 != 1)) {
    *(undefined8 *)(puVar4 + -8) = 0x18003c59a;
    FUN_18003c458();
  }
  return;
}

/* RVA 0x3c5ac */
/* Library Function - Single Match
    __security_init_cookie
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl __security_init_cookie(void)

{
  DWORD DVar1;
  _FILETIME local_res8;
  LARGE_INTEGER local_res10;
  _FILETIME local_18 [2];
  
  if (DAT_1800516d8 == 0x2b992ddfa232) {
    local_res8.dwLowDateTime = 0;
    local_res8.dwHighDateTime = 0;
    GetSystemTimeAsFileTime(&local_res8);
    local_18[0] = local_res8;
    DVar1 = GetCurrentThreadId();
    local_18[0] = (_FILETIME)((ulonglong)local_18[0] ^ (ulonglong)DVar1);
    DVar1 = GetCurrentProcessId();
    local_18[0] = (_FILETIME)((ulonglong)local_18[0] ^ (ulonglong)DVar1);
    QueryPerformanceCounter(&local_res10);
    DAT_1800516d8 =
         ((ulonglong)local_res10.s.LowPart << 0x20 ^
          CONCAT44(local_res10.s.HighPart,local_res10.s.LowPart) ^ (ulonglong)local_18[0] ^
         (ulonglong)local_18) & 0xffffffffffff;
    if (DAT_1800516d8 == 0x2b992ddfa232) {
      DAT_1800516d8 = 0x2b992ddfa233;
    }
  }
  DAT_1800516d0 = ~DAT_1800516d8;
  return;
}

