/* RVA 0x1020 */
void FUN_180001020(void)

{
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&DAT_180051bc8);
  atexit((_func_5014 *)&LAB_18003d6a0);
  return;
}

/* RVA 0x1060 */
void FUN_180001060(void)

{
  DAT_180051bd0 = operator_new(0x60);
  *(void **)DAT_180051bd0 = DAT_180051bd0;
  *(void **)((longlong)DAT_180051bd0 + 8) = DAT_180051bd0;
  *(void **)((longlong)DAT_180051bd0 + 0x10) = DAT_180051bd0;
  *(undefined2 *)((longlong)DAT_180051bd0 + 0x18) = 0x101;
  atexit(FUN_18003d6d0);
  return;
}

/* RVA 0x10e0 */
void FUN_1800010e0(void)

{
  CRuntimeClass *pCVar1;
  
  pCVar1 = CSimSeqObj::GetRuntimeClass();
  AfxClassInit(pCVar1);
  return;
}

/* RVA 0x1100 */
void FUN_180001100(void)

{
  CRuntimeClass *pCVar1;
  
  pCVar1 = (CRuntimeClass *)FUN_180014fb0();
  AfxClassInit(pCVar1);
  return;
}

/* RVA 0x1120 */
void FUN_180001120(void)

{
  DAT_180051f68 = FUN_180015f60();
  return;
}

/* RVA 0x1140 */
void FUN_180001140(void)

{
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&DAT_180051f60);
  atexit((_func_5014 *)&LAB_18003d970);
  return;
}

/* RVA 0x1164 */
void FUN_180001164(void)

{
  ATL::CAtlBaseModule::CAtlBaseModule((CAtlBaseModule *)&DAT_1800537f0);
  atexit((_func_5014 *)&LAB_18003d980);
  return;
}

/* RVA 0x11a0 */
void FUN_1800011a0(undefined8 param_1,char *param_2)

{
  byte bVar1;
  int iVar2;
  byte *_Str1;
  longlong lVar3;
  byte *pbVar4;
  byte *pbVar5;
  
  if ((param_2 == (char *)0x0) || (*param_2 == '\0')) {
    return;
  }
  _Str1 = (byte *)_strdup(param_2);
  if (((byte)(*_Str1 - 0xe) < 2) || (iVar2 = strncmp((char *)_Str1,"RTOPT>",6), iVar2 == 0)) {
LAB_18000124f:
                    /* WARNING: Could not recover jumptable at 0x00018000125b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    free(_Str1);
    return;
  }
  pbVar5 = _Str1;
  while( true ) {
    bVar1 = *pbVar5;
    if ((0xd < bVar1) || ((0x3480U >> ((int)(char)bVar1 & 0x1fU) & 1) == 0)) break;
    pbVar5 = pbVar5 + 1;
    if (pbVar5 == (byte *)0x0) goto LAB_180001248;
  }
  if (bVar1 == 0) goto LAB_180001248;
  lVar3 = -1;
  do {
    lVar3 = lVar3 + 1;
  } while (pbVar5[lVar3] != 0);
  iVar2 = (int)lVar3 + -1;
  if (-1 < iVar2) {
    pbVar4 = pbVar5 + iVar2;
    do {
      if ((0xd < *pbVar4) || ((0x3480U >> ((int)(char)*pbVar4 & 0x1fU) & 1) == 0)) break;
      *pbVar4 = 0;
      pbVar4 = pbVar4 + -1;
    } while (-1 < (longlong)pbVar4 - (longlong)pbVar5);
  }
LAB_180001248:
  SimUpdateMessageView(0,(char *)pbVar5);
  goto LAB_18000124f;
}

/* RVA 0x1270 */
void FUN_180001270(void *param_1,void *param_2)

{
  if (param_1 == param_2) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000180001275. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  free(param_1);
  return;
}

/* RVA 0x1280 */
CCmdTarget * FUN_180001280(CCmdTarget *param_1)

{
  CCmdTarget::CCmdTarget(param_1);
  *(undefined ***)param_1 = CASCSimMessageEventSink::vftable;
  *(undefined ***)(param_1 + 0x50) = CASCSimMessageEventSink::XMessageSink::vftable;
  *(undefined4 *)(param_1 + 0x48) = 0;
  return param_1;
}

/* RVA 0x12c0 */
void FUN_1800012c0(CCmdTarget *param_1)

{
  *(undefined ***)param_1 = CASCSimMessageEventSink::vftable;
  if (*(longlong **)(param_1 + 0x40) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(param_1 + 0x40) + 0x10))();
  }
  CCmdTarget::~CCmdTarget(param_1);
  return;
}

/* RVA 0x1300 */
void FUN_180001300(void *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b368. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  operator_delete(param_1);
  return;
}

/* RVA 0x1310 */
CCmdTarget * FUN_180001310(CCmdTarget *param_1,uint param_2)

{
  FUN_1800012c0(param_1);
  if ((param_2 & 1) != 0) {
    if ((param_2 & 4) == 0) {
      operator_delete(param_1);
      return param_1;
    }
    thunk_FUN_180001300(param_1);
  }
  return param_1;
}

/* RVA 0x1360 */
undefined8 SBsubflowsheet(void)

{
                    /* 0x1360  101  SBsubflowsheet */
  return 1;
}

/* RVA 0x1370 */
void _guard_check_icall(void)

{
                    /* 0x1370  24  SimToggleControlPanel
                       0x1370  28  SimCloseControlPanel
                       0x1370  30  SimBeginWaitCursor
                       0x1370  31  SimEndWaitCursor
                       0x1370  59  SaveBinaryAnalysis
                       0x1370  114  SimPushPipe
                       0x1370  125  SimPostReinit
                       0x1370  126  SimResendScope
                       0x1370  146  BDcurves_gen
                       0x1370  147  CPlglchr
                       0x1370  189  CPshflft
                       0x1370  190  CPshfrt
                       0x1370  192  GRbutdrv
                       0x1370  194  GRchkwin
                       0x1370  195  GRclssdb
                       0x1370  196  GRfixssm
                       0x1370  197  GRinpsta
                       0x1370  198  GRsetcpb
                       0x1370  199  ICcanchm
                       0x1370  200  ICcanco0
                       0x1370  201  ICcanco1
                       0x1370  202  ICcanhc1
                       0x1370  203  ICcanhc2
                       0x1370  204  ICcanhc3
                       0x1370  205  ICcanhc4
                       0x1370  206  ICcanops
                       0x1370  207  ICcanpro
                       0x1370  208  ICcansps
                       0x1370  209  ICcanunt
                       0x1370  210  LSdosnam
                       0x1370  211  NTlstcus
                       0x1370  212  PTenvelope_gen
                       0x1370  213  PVcurves_gen
                       0x1370  215  SBreares
                       0x1370  217  SMhassol
                       0x1370  218  SYclrtfd
                       0x1370  223  TMdislog
                       0x1370  224  TVcurves_gen
                       0x1370  225  _dos_getdiskfree
                       0x1370  226  accountinfo
                       0x1370  227  adj_cs
                       0x1370  228  aspen_run
                       0x1370  229  bdr_0
                       0x1370  230  bdr_dln
                       0x1370  231  bell
                       0x1370  233  cl_wn
                       0x1370  234  close_menu_def
                       0x1370  235  compflow_gen
                       0x1370  236  composition_gen
                       0x1370  237  create_new_ss
                       0x1370  238  csr_hide
                       0x1370  239  csr_type
                       0x1370  240  define_ss
                       0x1370  241  defs_wn
                       0x1370  242  delete_plot_menu_template
                       0x1370  243  distill_gen
                       0x1370  244  edit_cmnd
                       0x1370  245  err_wn
                       0x1370  246  first_finished
                       0x1370  247  flash_gen
                       0x1370  248  focus_control_panel
                       0x1370  249  frmbrkset
                       0x1370  250  get_cur_stream_name
                       0x1370  251  get_current_ss_list
                       0x1370  252  gibb_gen
                       0x1370  253  keywds_call
                       0x1370  254  ki
                       0x1370  256  kx
                       0x1370  257  modify_menu_item2
                       0x1370  258  mouse_interrupt
                       0x1370  259  mouse_rubber_band2
                       0x1370  260  mv_csr
                       0x1370  262  ntnam
                       0x1370  263  open_MM_window
                       0x1370  264  open_list_dialog
                       0x1370  265  open_ss_pad
                       0x1370  266  petroleum_gen
                       0x1370  267  pfs_load_purge
                       0x1370  268  pl_csr
                       0x1370  269  pure_gen
                       0x1370  270  pxy_gen
                       0x1370  271  refresh_cpanel_message
                       0x1370  272  refresh_windows
                       0x1370  273  residue_gen
                       0x1370  274  save_MAX
                       0x1370  275  sbresult
                       0x1370  276  sbrk
                       0x1370  277  select_hcs
                       0x1370  278  select_list_set
                       0x1370  279  set_dialog_current_item
                       0x1370  280  set_wn
                       0x1370  281  setup_run_menu
                       0x1370  282  ss_def_column
                       0x1370  283  ss_set_col_width
                       0x1370  284  toggle_history
                       0x1370  285  txy_gen
                       0x1370  286  unset_wn
                       0x1370  287  v_ch
                       0x1370  288  v_fst
                       0x1370  289  v_natt
                       0x1370  290  v_plst */
  return;
}

/* RVA 0x1380 */
void FUN_180001380(long param_1)

{
  code *pcVar1;
  
  if (param_1 == -0x7ff8fff2) {
    AfxThrowMemoryException();
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  AfxThrowOleException(param_1);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

/* RVA 0x13a0 */
void FUN_1800013a0(void)

{
  DWORD DVar1;
  
  DVar1 = GetLastError();
  if (0 < (int)DVar1) {
    DVar1 = DVar1 & 0xffff | 0x80070000;
  }
                    /* WARNING: Subroutine does not return */
  FUN_180001380(DVar1);
}

/* RVA 0x13c0 */
int FUN_1800013c0(longlong param_1)

{
  int iVar1;
  int iVar2;
  BSTR bstrString;
  longlong *local_res8;
  
  iVar2 = 1;
  if (*(int *)(param_1 + 0x48) == 0) {
    local_res8 = (longlong *)0x0;
    iVar1 = Ordinal_78(&local_res8);
    if (-1 < iVar1) {
      if (local_res8 != (longlong *)0x0) {
        bstrString = SysAllocString(L"ASCSimulationMsgs");
        iVar2 = (**(code **)(*local_res8 + 0x58))(local_res8,bstrString,param_1 + 0x40);
        SysFreeString(bstrString);
        if (iVar2 < 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = AfxConnectionAdvise(*(IUnknown **)(param_1 + 0x40),(_GUID *)&DAT_180040228,
                                      (IUnknown *)(param_1 + 0x50),1,(ulong *)(param_1 + 0x48));
        }
        if (local_res8 != (longlong *)0x0) {
          (**(code **)(*local_res8 + 0x10))();
        }
      }
      return iVar2;
    }
  }
  return 0;
}

/* RVA 0x14a0 */
CCmdTarget * FUN_1800014a0(void)

{
  CCmdTarget *pCVar1;
  
  pCVar1 = operator_new(0x58);
  if (pCVar1 == (CCmdTarget *)0x0) {
    return (CCmdTarget *)0x0;
  }
  pCVar1 = FUN_180001280(pCVar1);
  return pCVar1;
}

/* RVA 0x14d0 */
undefined ** FUN_1800014d0(void)

{
  return &PTR_LAB_18003f808;
}

/* RVA 0x14e0 */
undefined8 FUN_1800014e0(void)

{
  return 0x80004001;
}

/* RVA 0x14f0 */
undefined8 FUN_1800014f0(void)

{
  return 0x18003f860;
}

/* RVA 0x1500 */
undefined ** thunk_FUN_180001520(void)

{
  return &PTR_LAB_18003f970;
}

/* RVA 0x1510 */
undefined ** FUN_180001510(void)

{
  return &PTR_s_CASCSimMessageEventSink_18003f7d8;
}

/* RVA 0x1520 */
undefined ** FUN_180001520(void)

{
  return &PTR_LAB_18003f970;
}

/* RVA 0x1530 */
int FUN_180001530(longlong param_1)

{
  undefined8 *puVar1;
  ulong uVar2;
  int iVar3;
  
  uVar2 = *(ulong *)(param_1 + 0x48);
  if (uVar2 == 0) {
    return 0;
  }
  puVar1 = (undefined8 *)(param_1 + 0x40);
  iVar3 = AfxConnectionUnadvise
                    ((IUnknown *)*puVar1,(_GUID *)&DAT_180040228,(IUnknown *)(param_1 + 0x50),1,
                     uVar2);
  (**(code **)(*(longlong *)*puVar1 + 0x10))();
  CoDisconnectObject((IUnknown *)(param_1 + 0x50),0);
  *puVar1 = 0;
  *(ulong *)(param_1 + 0x48) = 0;
  return iVar3;
}

/* RVA 0x15d0 */
void FUN_1800015d0(undefined8 *param_1,LPCWSTR param_2,UINT param_3)

{
  LPSTR pCVar1;
  LPSTR pCVar2;
  code *pcVar3;
  int iVar4;
  DWORD DVar5;
  LPSTR pCVar6;
  int cchWideChar;
  longlong lVar7;
  bool bVar8;
  
  if (param_2 == (LPCWSTR)0x0) {
    *param_1 = 0;
    return;
  }
  lVar7 = -1;
  do {
    lVar7 = lVar7 + 1;
  } while (param_2[lVar7] != L'\0');
  cchWideChar = (int)lVar7 + 1;
  pCVar1 = (LPSTR)(param_1 + 1);
  iVar4 = cchWideChar * 4;
  if (((param_1 == (undefined8 *)0x0) || (iVar4 < 0)) || (pCVar1 == (LPSTR)0x0)) {
                    /* WARNING: Subroutine does not return */
    FUN_180001380(-0x7ff8ffa9);
  }
  pCVar2 = (LPSTR)*param_1;
  pCVar6 = pCVar1;
  if (pCVar2 == pCVar1) {
    if (iVar4 < 0x81) {
      *param_1 = pCVar1;
    }
    else {
      pCVar6 = calloc((longlong)iVar4,1);
      *param_1 = pCVar6;
      if (pCVar6 == (LPSTR)0x0) goto LAB_1800017e8;
    }
  }
  else {
    if (iVar4 < 0x81) {
      free(pCVar2);
    }
    else {
      pCVar6 = _recalloc(pCVar2,(longlong)iVar4,1);
      if (pCVar6 == (LPSTR)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_180001380(-0x7ff8fff2);
      }
    }
    *param_1 = pCVar6;
  }
  iVar4 = WideCharToMultiByte(param_3,0,param_2,cchWideChar,pCVar6,iVar4,(LPCSTR)0x0,(LPBOOL)0x0);
  bVar8 = iVar4 == 0;
  if ((iVar4 == 0) && (DVar5 = GetLastError(), DVar5 == 0x7a)) {
    iVar4 = WideCharToMultiByte(param_3,0,param_2,cchWideChar,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
    if (iVar4 < 0) {
                    /* WARNING: Subroutine does not return */
      FUN_180001380(-0x7ff8ffa9);
    }
    pCVar2 = (LPSTR)*param_1;
    pCVar6 = pCVar1;
    if (pCVar2 == pCVar1) {
      if (iVar4 < 0x81) {
        *param_1 = pCVar1;
      }
      else {
        pCVar6 = calloc((longlong)iVar4,1);
        *param_1 = pCVar6;
        if (pCVar6 == (LPSTR)0x0) {
                    /* WARNING: Subroutine does not return */
          FUN_180001380(-0x7ff8fff2);
        }
      }
    }
    else {
      if (iVar4 < 0x81) {
        free(pCVar2);
      }
      else {
        pCVar6 = _recalloc(pCVar2,(longlong)iVar4,1);
        if (pCVar6 == (LPSTR)0x0) {
LAB_1800017e8:
                    /* WARNING: Subroutine does not return */
          FUN_180001380(-0x7ff8fff2);
        }
      }
      *param_1 = pCVar6;
    }
    iVar4 = WideCharToMultiByte(param_3,0,param_2,cchWideChar,pCVar6,iVar4,(LPCSTR)0x0,(LPBOOL)0x0);
    bVar8 = iVar4 == 0;
  }
  if (bVar8) {
    FUN_180001270((void *)*param_1,pCVar1);
    FUN_1800013a0();
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  return;
}

/* RVA 0x1820 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180001820(longlong param_1,int param_2)

{
  longlong *plVar1;
  short *psVar2;
  undefined8 *in_stack_00000030;
  VARIANTARG *in_stack_00000038;
  undefined1 auStack_d8 [32];
  undefined8 local_b8;
  char *local_a8;
  char local_a0 [136];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_d8;
  plVar1 = (longlong *)(param_1 + -0x50);
  if (param_2 == 1) {
    if ((*(int *)(in_stack_00000030 + 2) != 0) && (*(short *)*in_stack_00000030 == 8)) {
      local_a8 = local_a0;
      FUN_1800015d0(&local_a8,*(LPCWSTR *)((short *)*in_stack_00000030 + 4),0);
      FUN_1800011a0(plVar1,local_a8);
      if (local_a8 != local_a0) {
        free(local_a8);
      }
    }
  }
  else if (param_2 == 2) {
    if ((((*(int *)(in_stack_00000030 + 2) == 4) &&
         (psVar2 = (short *)*in_stack_00000030, *psVar2 == 0x2008)) && (psVar2[0xc] == 0x200c)) &&
       ((psVar2[0x18] == 0x200c && (psVar2[0x24] == 5)))) {
      local_b8 = *(undefined8 *)(psVar2 + 0x28);
      (**(code **)(*plVar1 + 0xb0))
                (plVar1,*(undefined8 *)(psVar2 + 4),*(undefined8 *)(psVar2 + 0x10),
                 *(undefined8 *)(psVar2 + 0x1c));
    }
  }
  else if (param_2 == 3) {
    (**(code **)(*plVar1 + 0xb8))(plVar1);
  }
  if (in_stack_00000038 != (VARIANTARG *)0x0) {
    VariantClear(in_stack_00000038);
  }
  return 0;
}

/* RVA 0x1950 */
undefined8 FUN_180001950(longlong *param_1,longlong *param_2,undefined8 *param_3)

{
  if (((((*param_2 == DAT_180043ed8) && (param_2[1] == DAT_180043ee0)) ||
       ((*param_2 == DAT_180043ee8 && (param_2[1] == DAT_180043ef0)))) ||
      ((*param_2 == DAT_180040228 && (param_2[1] == DAT_180040230)))) ||
     ((*param_2 == DAT_180040238 && (param_2[1] == DAT_180040240)))) {
    *param_3 = param_1;
    (**(code **)(*param_1 + 8))();
    return 0;
  }
  return 0x80004002;
}

/* RVA 0x19e0 */
undefined8 EXmsgbox(void)

{
                    /* 0x19e0  191  EXmsgbox
                       0x19e0  193  GRchkfpd
                       0x19e0  232  check_cpanel_status
                       0x19e0  255  ki_chk */
  return 0;
}

/* RVA 0x19f0 */
int FUN_1800019f0(void)

{
  int iVar1;
  
  if (DAT_180051a00 == (CCmdTarget *)0x0) {
    DAT_180051a00 = (CCmdTarget *)0x0;
    return 0;
  }
  iVar1 = FUN_180001530((longlong)DAT_180051a00);
  CCmdTarget::ExternalRelease(DAT_180051a00);
  DAT_180051a00 = (CCmdTarget *)0x0;
  return iVar1;
}

/* RVA 0x1a40 */
void FUN_180001a40(void)

{
  CCmdTarget *pCVar1;
  CCmdTarget *pCVar2;
  
  if (DAT_180051a00 != (CCmdTarget *)0x0) {
    CCmdTarget::ExternalRelease(DAT_180051a00);
  }
  pCVar1 = operator_new(0x58);
  pCVar2 = (CCmdTarget *)0x0;
  if (pCVar1 != (CCmdTarget *)0x0) {
    pCVar2 = FUN_180001280(pCVar1);
  }
  DAT_180051a00 = pCVar2;
  FUN_1800013c0((longlong)pCVar2);
  return;
}

/* RVA 0x1aa0 */
CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
FUN_180001aa0(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_1,
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_2,
             undefined8 *param_3)

{
  IAtlStringMgr *pIVar1;
  
  pIVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager(param_2);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1,pIVar1);
  ATL::CSimpleStringT<char,1>::Concatenate
            ((CSimpleStringT<char,1> *)param_1,*(char **)param_2,*(int *)(*(char **)param_2 + -0x10)
             ,(char *)*param_3,*(int *)((char *)*param_3 + -0x10));
  return param_1;
}

/* RVA 0x1b20 */
undefined * FUN_180001b20(void)

{
  return &DAT_180051b18;
}

/* RVA 0x1b30 */
undefined * FUN_180001b30(void)

{
  return &DAT_180051b20;
}

/* RVA 0x1b40 */
undefined8 * FUN_180001b40(undefined8 *param_1,LPCSTR param_2)

{
  int cchWideChar;
  int iVar1;
  BSTR lpWideCharStr;
  
  if (param_2 == (LPCSTR)0x0) {
    *param_1 = 0;
    return param_1;
  }
  cchWideChar = MultiByteToWideChar(0,0,param_2,-1,(LPWSTR)0x0,0);
  lpWideCharStr = SysAllocStringLen((OLECHAR *)0x0,cchWideChar - 1);
  if ((lpWideCharStr == (BSTR)0x0) ||
     (iVar1 = MultiByteToWideChar(0,0,param_2,-1,lpWideCharStr,cchWideChar), iVar1 == cchWideChar))
  {
    *param_1 = lpWideCharStr;
    if (lpWideCharStr != (BSTR)0x0) {
      return param_1;
    }
  }
  else {
    SysFreeString(lpWideCharStr);
    *param_1 = 0;
  }
                    /* WARNING: Subroutine does not return */
  FUN_180001380(-0x7ff8fff2);
}

/* RVA 0x1c10 */
void FUN_180001c10(undefined8 *param_1)

{
  undefined8 *_Memory;
  
  _Memory = (undefined8 *)*param_1;
  while (_Memory != (undefined8 *)0x0) {
    *param_1 = *_Memory;
    free(_Memory);
    _Memory = (undefined8 *)*param_1;
  }
  return;
}

/* RVA 0x1c40 */
void FUN_180001c40(longlong *param_1)

{
  if ((longlong *)*param_1 != (longlong *)0x0) {
    (**(code **)(*(longlong *)*param_1 + 0x10))();
  }
  return;
}

/* RVA 0x1c80 */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

VARIANTARG * FUN_180001c80(VARIANTARG *param_1,LPCSTR param_2)

{
  HRESULT HVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  undefined8 *_Memory;
  BSTR pOVar6;
  undefined8 *puVar7;
  undefined1 *puVar8;
  ulonglong uVar9;
  OLECHAR *pOVar10;
  OLECHAR *psz;
  undefined1 auStack_58 [48];
  undefined8 *local_28;
  ulonglong local_20;
  
  local_20 = DAT_1800516d8 ^ (ulonglong)&local_28;
  psz = (OLECHAR *)0x0;
  puVar7 = (undefined8 *)0x0;
  local_28 = (undefined8 *)0x0;
  HVar1 = VariantClear(param_1);
  if (HVar1 < 0) {
                    /* WARNING: Subroutine does not return */
    FUN_180001380(HVar1);
  }
  (param_1->n1).n2.vt = 8;
  _Memory = puVar7;
  puVar8 = auStack_58;
  if (param_2 != (LPCSTR)0x0) {
    lVar3 = -1;
    do {
      lVar3 = lVar3 + 1;
    } while (param_2[lVar3] != '\0');
    lVar3 = (longlong)((int)lVar3 + 1) * 2;
    puVar8 = auStack_58;
    if (lVar3 + 0x80000000U < 0x100000000) {
      iVar2 = (int)lVar3;
      uVar9 = (ulonglong)iVar2;
      if ((iVar2 < 0x401) && (uVar4 = FUN_1800023f0(uVar9), (char)uVar4 != '\0')) {
        uVar5 = uVar9 + 0xf;
        if (uVar5 <= uVar9) {
          uVar5 = 0xffffffffffffff0;
        }
        pOVar10 = (OLECHAR *)(auStack_58 + -(uVar5 & 0xfffffffffffffff0) + 0x30);
        puVar8 = auStack_58 + -(uVar5 & 0xfffffffffffffff0);
      }
      else {
        if (~uVar9 < 0x10) {
                    /* WARNING: Subroutine does not return */
          FUN_180001380(-0x7ff8fdea);
        }
        _Memory = malloc(uVar9 + 0x10);
        puVar8 = auStack_58;
        if (_Memory == (undefined8 *)0x0) {
          pOVar10 = (OLECHAR *)0x0;
          _Memory = puVar7;
          puVar8 = auStack_58;
        }
        else {
          *_Memory = 0;
          local_28 = _Memory;
          pOVar10 = (OLECHAR *)(_Memory + 2);
        }
      }
      if (pOVar10 != (OLECHAR *)0x0) {
        *pOVar10 = L'\0';
        *(int *)(puVar8 + 0x28) = (int)(uVar9 >> 1);
        *(OLECHAR **)(puVar8 + 0x20) = pOVar10;
        *(undefined8 *)(puVar8 + -8) = 0x180001da0;
        iVar2 = MultiByteToWideChar(0,0,param_2,-1,*(LPWSTR *)(puVar8 + 0x20),
                                    *(int *)(puVar8 + 0x28));
        psz = pOVar10;
        if (iVar2 == 0) {
          psz = (OLECHAR *)0x0;
        }
      }
    }
  }
  *(undefined8 *)(puVar8 + -8) = 0x180001db2;
  pOVar6 = SysAllocString(psz);
  (param_1->n1).decVal.u2.Lo64 = (ULONGLONG)pOVar6;
  if ((pOVar6 == (BSTR)0x0) && (param_2 != (LPCSTR)0x0)) {
    (param_1->n1).n2.vt = 10;
    (param_1->n1).n2.n3.lVal = -0x7ff8fff2;
                    /* WARNING: Subroutine does not return */
    *(undefined **)(puVar8 + -8) = &UNK_180001e35;
    FUN_180001380(-0x7ff8fff2);
  }
  while (_Memory != (undefined8 *)0x0) {
    puVar7 = (undefined8 *)*_Memory;
    *(undefined8 *)(puVar8 + -8) = 0x180001ddc;
    free(_Memory);
    _Memory = puVar7;
  }
  *(undefined8 *)(puVar8 + -8) = 0x180001df0;
  return param_1;
}

/* RVA 0x1e40 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_180001e40(LPVOID *param_1)

{
  int *piVar1;
  OLECHAR *psz;
  HRESULT HVar2;
  int iVar3;
  undefined8 *puVar4;
  BSTR pOVar5;
  undefined4 uVar6;
  undefined1 auStackY_78 [32];
  longlong *local_48;
  OLECHAR *local_40;
  undefined8 *local_38;
  CLSID local_30;
  ulonglong local_20;
  
  local_20 = DAT_1800516d8 ^ (ulonglong)auStackY_78;
  local_48 = (longlong *)0x0;
  uVar6 = 1;
  HVar2 = CoCreateInstance((IID *)&DAT_18003fa00,(LPUNKNOWN)0x0,1,(IID *)&DAT_18003f9f0,&local_48);
  if ((HVar2 < 0) ||
     (iVar3 = (**(code **)(*local_48 + 0x18))(local_48,&local_40), psz = local_40, iVar3 < 0)) {
    uVar6 = 0;
  }
  else {
    puVar4 = operator_new(0x18);
    local_38 = puVar4;
    if (puVar4 == (undefined8 *)0x0) {
      puVar4 = (undefined8 *)0x0;
    }
    else {
      puVar4[1] = 0;
      *(undefined4 *)(puVar4 + 2) = 1;
      pOVar5 = SysAllocString(psz);
      *puVar4 = pOVar5;
      if ((pOVar5 == (BSTR)0x0) && (psz != (OLECHAR *)0x0)) {
                    /* WARNING: Subroutine does not return */
        FUN_18003c7f0(0x8007000e);
      }
    }
    if (puVar4 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_18003c7f0(0x8007000e);
    }
    SysFreeString(local_40);
    HVar2 = CLSIDFromProgID((LPCOLESTR)*puVar4,&local_30);
    if ((HVar2 < 0) ||
       (HVar2 = CoCreateInstance(&local_30,(LPUNKNOWN)0x0,4,(IID *)&DAT_18003f9d0,param_1),
       HVar2 < 0)) {
      uVar6 = 0;
    }
    LOCK();
    piVar1 = (int *)(puVar4 + 2);
    iVar3 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar3 == 1) {
      if ((BSTR)*puVar4 != (BSTR)0x0) {
        SysFreeString((BSTR)*puVar4);
        *puVar4 = 0;
      }
      if ((void *)puVar4[1] != (void *)0x0) {
        operator_delete__((void *)puVar4[1]);
        puVar4[1] = 0;
      }
      FUN_180001300(puVar4);
    }
  }
  if (local_48 != (longlong *)0x0) {
    (**(code **)(*local_48 + 0x10))();
  }
  return uVar6;
}

/* RVA 0x1fd0 */
undefined8 FUN_180001fd0(char *param_1,longlong *param_2)

{
  longlong *plVar1;
  undefined8 psz;
  int iVar2;
  int iVar3;
  longlong *plVar4;
  BSTR pOVar5;
  BSTR pOVar6;
  undefined8 uVar7;
  longlong *local_res18;
  longlong *local_res20;
  LPCSTR local_a8;
  BSTR local_a0;
  _union_2707 local_98;
  _union_2707 local_80;
  longlong *local_68;
  undefined4 local_58;
  ULONG UStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined8 local_48;
  
  uVar7 = 0;
  local_res20 = (longlong *)0x0;
  local_res18 = (longlong *)0x0;
  plVar4 = (longlong *)GetGlobalPointer("HappNode");
  local_68 = plVar4;
  if (plVar4 != (longlong *)0x0) {
    (**(code **)(*plVar4 + 8))(plVar4);
    (**(code **)(*plVar4 + 0x90))(plVar4,&local_res20);
    if (local_res20 != (longlong *)0x0) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_a8,
                 "\\Data\\Model Analysis Tools\\Cost-Est\\Input\\");
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_a8,param_1)
      ;
      plVar1 = local_res20;
      if (local_a8 == (LPCSTR)0x0) {
        local_a0 = (BSTR)0x0;
      }
      else {
        iVar2 = MultiByteToWideChar(0,0,local_a8,-1,(LPWSTR)0x0,0);
        pOVar5 = SysAllocStringLen((OLECHAR *)0x0,iVar2 - 1);
        if ((pOVar5 != (BSTR)0x0) &&
           (iVar3 = MultiByteToWideChar(0,0,local_a8,-1,pOVar5,iVar2), iVar3 != iVar2)) {
          SysFreeString(pOVar5);
LAB_180002252:
                    /* WARNING: Subroutine does not return */
          FUN_180001380(-0x7ff8fff2);
        }
        local_a0 = pOVar5;
        if (pOVar5 == (BSTR)0x0) goto LAB_180002252;
      }
      pOVar5 = local_a0;
      (**(code **)(*plVar1 + 0x110))(plVar1,local_a0,&local_res18);
      SysFreeString(pOVar5);
      if (local_res18 != (longlong *)0x0) {
        local_80._0_8_ = 0;
        local_80.decVal.u2 = (_union_1719)(_struct_1720)0x0;
        local_80._16_8_ = 0;
        VariantInit((VARIANTARG *)&local_80.n2);
        local_98._0_8_ = 0;
        local_98.decVal.u2 = (_union_1719)0;
        local_98._16_8_ = 0;
        VariantInit((VARIANTARG *)&local_98.n2);
        local_58 = local_80._0_4_;
        UStack_54 = local_80.decVal.Hi32;
        uStack_50 = local_80._8_4_;
        uStack_4c = local_80._12_4_;
        local_48 = local_80._16_8_;
        iVar2 = (**(code **)(*local_res18 + 0x68))(local_res18,&local_58,&local_98);
        psz = local_98._8_8_;
        if ((-1 < iVar2) && (local_98.n2.vt == 8)) {
          if ((local_98.decVal.u2 == 0) ||
             (((_struct_1720 *)*param_2 == (_struct_1720 *)0x0 ||
              ((_union_1719)*(_struct_1720 *)*param_2 != local_98.decVal.u2)))) {
            FUN_180002480(param_2);
            pOVar5 = operator_new(0x18);
            local_a0 = pOVar5;
            if (pOVar5 == (BSTR)0x0) {
              pOVar5 = (BSTR)0x0;
            }
            else {
              pOVar5[4] = L'\0';
              pOVar5[5] = L'\0';
              pOVar5[6] = L'\0';
              pOVar5[7] = L'\0';
              pOVar5[8] = L'\x01';
              pOVar5[9] = L'\0';
              pOVar6 = SysAllocString((OLECHAR *)psz);
              *(BSTR *)pOVar5 = pOVar6;
              if ((pOVar6 == (BSTR)0x0) && (psz != 0)) {
                    /* WARNING: Subroutine does not return */
                FUN_18003c7f0(0x8007000e);
              }
            }
            *param_2 = (longlong)pOVar5;
            if (pOVar5 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
              FUN_18003c7f0(0x8007000e);
            }
          }
          uVar7 = 1;
        }
        VariantClear((VARIANTARG *)&local_98.n2);
        VariantClear((VARIANTARG *)&local_80.n2);
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_a8);
    }
  }
  if (plVar4 != (longlong *)0x0) {
    (**(code **)(*plVar4 + 0x10))(plVar4);
  }
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x10))();
  }
  if (local_res20 != (longlong *)0x0) {
    (**(code **)(*local_res20 + 0x10))();
  }
  return uVar7;
}

/* RVA 0x2270 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180002270(longlong param_1,longlong param_2)

{
  char cVar1;
  char *pcVar2;
  longlong lVar3;
  longlong lVar4;
  undefined1 auStack_268 [32];
  char *local_248;
  char cStack_239;
  CHAR local_238 [271];
  char cStack_129;
  CHAR local_128;
  char acStack_127 [271];
  ulonglong local_18;
  
  local_18 = DAT_1800516d8 ^ (ulonglong)auStack_268;
  pcVar2 = (char *)GetGlobalPointer("MMXEQ");
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_248,pcVar2);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_248,
             "\\AspenIcarusToAspenPlus.xslt");
  GetCurrentDirectoryA(0x104,&local_128);
  lVar4 = -1;
  do {
    lVar3 = lVar4;
    lVar4 = lVar3 + 1;
  } while (acStack_127[lVar3] != '\0');
  if (acStack_127[lVar3 + -1] != '\\') {
    pcVar2 = &cStack_129;
    do {
      pcVar2 = pcVar2 + 1;
    } while (*pcVar2 != '\0');
    *(undefined2 *)pcVar2 = DAT_18003fa78;
  }
  GetTempFileNameA(&local_128,"_",0,local_238);
  DeleteFileA(local_238);
  pcVar2 = strstr(local_238,".");
  if ((char *)0x103 < pcVar2 + (1 - (longlong)local_238)) {
                    /* WARNING: Subroutine does not return */
    FUN_18003b6e4();
  }
  local_238[(longlong)(pcVar2 + (1 - (longlong)local_238))] = '\0';
  pcVar2 = &cStack_239;
  do {
    pcVar2 = pcVar2 + 1;
  } while (*pcVar2 != '\0');
  *(undefined4 *)pcVar2 = DAT_18003fa84;
  lVar4 = param_1 - (longlong)local_248;
  do {
    cVar1 = *local_248;
    local_248[lVar4] = cVar1;
    local_248 = local_248 + 1;
  } while (cVar1 != '\0');
  pcVar2 = local_238;
  do {
    cVar1 = *pcVar2;
    pcVar2[param_2 - (longlong)local_238] = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_248);
  return;
}

/* RVA 0x23f0 */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_1800023f0(ulonglong param_1)

{
  ulonglong uVar1;
  undefined8 uVar2;
  undefined1 *puVar3;
  undefined1 auStack_38 [48];
  
  puVar3 = auStack_38;
  uVar2 = 1;
  if (~param_1 < 0x4000) {
    uVar2 = 0;
  }
  else {
    uVar1 = param_1 + 0x400f;
    if (uVar1 <= param_1 + 0x4000) {
      uVar1 = 0xffffffffffffff0;
    }
    puVar3 = auStack_38 + -(uVar1 & 0xfffffffffffffff0);
  }
  *(undefined8 *)(puVar3 + -8) = 0x18000246a;
  return uVar2;
}

/* RVA 0x2480 */
void FUN_180002480(undefined8 *param_1)

{
  int *piVar1;
  int iVar2;
  undefined8 *puVar3;
  
  puVar3 = (undefined8 *)*param_1;
  if (puVar3 != (undefined8 *)0x0) {
    LOCK();
    piVar1 = (int *)(puVar3 + 2);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      if ((BSTR)*puVar3 != (BSTR)0x0) {
        SysFreeString((BSTR)*puVar3);
        *puVar3 = 0;
      }
      if ((void *)puVar3[1] != (void *)0x0) {
        operator_delete__((void *)puVar3[1]);
        puVar3[1] = 0;
      }
      FUN_180001300(puVar3);
    }
    *param_1 = 0;
  }
  return;
}

/* RVA 0x24f0 */
undefined8 DeleteXML(longlong param_1)

{
  LPCSTR local_res8 [4];
  
                    /* 0x24f0  134  DeleteXML */
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_res8,
             *(wchar_t **)(param_1 + 8));
  DeleteFileA(local_res8[0]);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_res8);
  return 1;
}

/* RVA 0x2530 */
undefined8 GetIPETemplate(longlong param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 *puVar4;
  BSTR pOVar5;
  undefined8 uVar6;
  short local_res18 [8];
  longlong *local_28 [2];
  
                    /* 0x2530  138  GetIPETemplate */
  local_28[0] = (longlong *)0x0;
  uVar2 = FUN_180001e40(local_28);
  local_res18[0] = (short)uVar2;
  if (local_res18[0] == 0) {
    uVar6 = 0xffffffff;
  }
  else {
    puVar4 = operator_new(0x18);
    if (puVar4 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_18003c7f0(0x8007000e);
    }
    uVar6 = 1;
    puVar4[1] = 0;
    *(undefined4 *)(puVar4 + 2) = 1;
    pOVar5 = FUN_18003c920("IPE");
    *puVar4 = pOVar5;
    (**(code **)(*local_28[0] + 0x48))(local_28[0],pOVar5,local_res18);
    if (local_res18[0] == -1) {
      iVar3 = (**(code **)(*local_28[0] + 0x68))(local_28[0],param_1);
      if (iVar3 < 0) {
        uVar6 = 0xfffffffe;
      }
      else if (*(longlong *)(param_1 + 8) != 0) {
        *param_2 = *(undefined4 *)(*(longlong *)(param_1 + 8) + 0x18);
      }
    }
    LOCK();
    piVar1 = (int *)(puVar4 + 2);
    iVar3 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar3 == 1) {
      if ((BSTR)*puVar4 != (BSTR)0x0) {
        SysFreeString((BSTR)*puVar4);
        *puVar4 = 0;
      }
      if ((void *)puVar4[1] != (void *)0x0) {
        operator_delete__((void *)puVar4[1]);
        puVar4[1] = 0;
      }
      FUN_180001300(puVar4);
    }
  }
  if (local_28[0] != (longlong *)0x0) {
    (**(code **)(*local_28[0] + 0x10))();
  }
  return uVar6;
}

/* RVA 0x2650 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 LaunchIPE(_union_2707 *param_1)

{
  int *piVar1;
  longlong *plVar2;
  code cVar3;
  _union_1719 _Var4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  HRESULT HVar8;
  undefined8 *puVar9;
  BSTR pOVar10;
  longlong *plVar11;
  undefined8 uVar12;
  undefined8 *puVar13;
  longlong lVar14;
  undefined8 *puVar15;
  undefined8 *puVar16;
  LPCSTR lpFileName;
  undefined8 *puVar17;
  char *pcVar18;
  char *pcVar19;
  undefined8 uVar20;
  undefined8 uVar21;
  undefined8 uVar22;
  longlong lVar23;
  undefined1 auStack_5e8 [32];
  longlong **local_5c8;
  undefined8 *local_5c0;
  longlong **local_5b8;
  undefined8 local_5b0;
  undefined2 local_5a8;
  longlong **local_5a0;
  longlong *local_598;
  longlong *local_590;
  undefined8 *local_588;
  ULONG local_580 [2];
  undefined8 *local_578;
  undefined8 *local_570;
  longlong *local_568;
  _union_2707 *local_560;
  longlong *local_558;
  longlong *local_550;
  longlong *local_548;
  longlong *local_540;
  longlong *local_538;
  longlong *local_530;
  undefined8 *local_528;
  _union_2707 local_520;
  LPCSTR local_508;
  SAFEARRAYBOUND local_500;
  _union_1719 local_4f8;
  _union_2707 local_4f0;
  _union_2707 local_4d8;
  _union_2707 local_4c0;
  void *local_4a8;
  BSTR local_4a0;
  _union_2707 local_498;
  _union_2707 local_480;
  undefined8 local_468;
  _union_1719 _Stack_460;
  undefined8 local_458;
  longlong *local_448;
  _union_1719 _Stack_440;
  undefined8 local_438;
  undefined8 local_428;
  _union_1719 _Stack_420;
  undefined8 local_418;
  undefined8 local_408;
  _union_1719 _Stack_400;
  undefined8 local_3f8;
  undefined4 local_3e8;
  ULONG UStack_3e4;
  undefined4 uStack_3e0;
  undefined4 uStack_3dc;
  undefined8 local_3d8;
  undefined4 local_3c8;
  ULONG UStack_3c4;
  undefined4 uStack_3c0;
  undefined4 uStack_3bc;
  undefined8 local_3b8;
  undefined4 local_3a8;
  ULONG UStack_3a4;
  undefined4 uStack_3a0;
  undefined4 uStack_39c;
  undefined8 local_398;
  undefined4 local_388;
  ULONG UStack_384;
  undefined4 uStack_380;
  undefined4 uStack_37c;
  undefined8 local_378;
  char cStack_369;
  CHAR local_368;
  char acStack_367 [271];
  CHAR local_258 [272];
  CHAR local_148 [272];
  ulonglong local_38;
  
                    /* 0x2650  133  LaunchIPE */
  local_38 = DAT_1800516d8 ^ (ulonglong)auStack_5e8;
  local_548 = (longlong *)0x0;
  local_568 = (longlong *)0x0;
  local_560 = param_1;
  uVar5 = FUN_180001e40(&local_548);
  local_598._0_2_ = (short)uVar5;
  if ((short)local_598 == 0) {
    uVar5 = 0;
    goto LAB_1800033cf;
  }
  puVar9 = operator_new(0x18);
  if (puVar9 == (undefined8 *)0x0) goto LAB_18000342a;
  puVar9[1] = 0;
  *(undefined4 *)(puVar9 + 2) = 1;
  pOVar10 = FUN_18003c920("IPE");
  *puVar9 = pOVar10;
  iVar6 = (**(code **)(*local_548 + 0x48))(local_548,*puVar9,&local_598);
  if (iVar6 < 0) {
    uVar5 = 0;
  }
  else {
    if ((short)local_598 == -1) {
      local_570 = (undefined8 *)0x0;
      local_578 = (undefined8 *)0x0;
      local_588 = (undefined8 *)0x0;
      FUN_180001fd0("ARCHIVE",(longlong *)&local_570);
      FUN_180001fd0("PROJ_NAME",(longlong *)&local_578);
      FUN_180001fd0("SCENARIO",(longlong *)&local_588);
      puVar15 = local_588;
      if (local_588 == (undefined8 *)0x0) {
        uVar12 = 0;
      }
      else {
        uVar12 = *local_588;
      }
      if (local_578 == (undefined8 *)0x0) {
        uVar22 = 0;
      }
      else {
        uVar22 = *local_578;
      }
      if (local_570 == (undefined8 *)0x0) {
        uVar21 = 0;
      }
      else {
        uVar21 = *local_570;
      }
      local_5c8 = &local_568;
      iVar6 = (**(code **)(*local_548 + 0x50))(local_548,uVar21,uVar22,uVar12);
      if (iVar6 < 0) {
        plVar11 = operator_new(0x18);
        if (plVar11 == (longlong *)0x0) {
LAB_18000342a:
                    /* WARNING: Subroutine does not return */
          FUN_18003c7f0(0x8007000e);
        }
        plVar11[1] = 0;
        *(undefined4 *)(plVar11 + 2) = 1;
        pOVar10 = FUN_18003c920("Template");
        *plVar11 = (longlong)pOVar10;
        local_540 = plVar11;
        uVar12 = FUN_180001fd0("TEMPLATE",(longlong *)&local_540);
        puVar13 = operator_new(0x18);
        if (puVar13 == (undefined8 *)0x0) goto LAB_18000342a;
        puVar13[1] = 0;
        *(undefined4 *)(puVar13 + 2) = 1;
        pOVar10 = FUN_18003c920("AspenPlus");
        *puVar13 = pOVar10;
        SimThreadNoMT(1);
        local_5b0 = *puVar13;
        if (local_540 == (longlong *)0x0) {
          local_5b8 = (longlong **)0x0;
        }
        else {
          local_5b8 = (longlong **)*local_540;
        }
        if (puVar15 == (undefined8 *)0x0) {
          uVar22 = 0;
        }
        else {
          uVar22 = *puVar15;
        }
        if (local_578 == (undefined8 *)0x0) {
          uVar21 = 0;
        }
        else {
          uVar21 = *local_578;
        }
        if (local_570 == (undefined8 *)0x0) {
          uVar20 = 0;
        }
        else {
          uVar20 = *local_570;
        }
        local_5a0 = &local_568;
        local_5a8 = 0xffff;
        local_5c0 = (undefined8 *)CONCAT62(local_5c0._2_6_,-(ushort)((int)uVar12 != 0));
        local_5c8 = (longlong **)((ulonglong)local_5c8 & 0xffffffffffff0000);
        iVar7 = (**(code **)(*local_548 + 0x58))(local_548,uVar20,uVar21,uVar22);
        SimThreadNoMT(0);
        LOCK();
        piVar1 = (int *)(puVar13 + 2);
        iVar6 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar6 == 1) {
          if ((BSTR)*puVar13 != (BSTR)0x0) {
            SysFreeString((BSTR)*puVar13);
            *puVar13 = 0;
          }
          if ((void *)puVar13[1] != (void *)0x0) {
            operator_delete__((void *)puVar13[1]);
            puVar13[1] = 0;
          }
          FUN_180001300(puVar13);
        }
        plVar11 = local_540;
        if (local_540 != (longlong *)0x0) {
          LOCK();
          plVar2 = local_540 + 2;
          lVar23 = *plVar2;
          *(int *)plVar2 = (int)*plVar2 + -1;
          UNLOCK();
          if ((int)lVar23 == 1) {
            if ((BSTR)*local_540 != (BSTR)0x0) {
              SysFreeString((BSTR)*local_540);
              *plVar11 = 0;
            }
            if ((void *)plVar11[1] != (void *)0x0) {
              operator_delete__((void *)plVar11[1]);
              plVar11[1] = 0;
            }
            FUN_180001300(plVar11);
          }
        }
        if (-1 < iVar7) {
          puVar15 = local_588;
          goto LAB_18000293b;
        }
LAB_1800030cd:
        puVar15 = local_588;
      }
      else {
LAB_18000293b:
        if (local_568 != (longlong *)0x0) {
          GetCurrentDirectoryA(0x104,&local_368);
          lVar23 = -1;
          do {
            lVar14 = lVar23;
            lVar23 = lVar14 + 1;
          } while (acStack_367[lVar14] != '\0');
          if (acStack_367[lVar14 + -1] != '\\') {
            pcVar18 = &cStack_369;
            do {
              pcVar19 = pcVar18 + 1;
              pcVar18 = pcVar18 + 1;
            } while (*pcVar19 != '\0');
            *(undefined2 *)pcVar18 = DAT_18003fa78;
          }
          pcVar18 = &cStack_369;
          do {
            pcVar19 = pcVar18 + 1;
            pcVar18 = pcVar18 + 1;
          } while (*pcVar19 != '\0');
          lVar23 = 0;
          do {
            cVar3 = APtmpfil_exref[lVar23];
            pcVar18[lVar23] = (char)cVar3;
            lVar23 = lVar23 + 1;
          } while (cVar3 != (code)0x0);
          pcVar18 = &cStack_369;
          do {
            pcVar19 = pcVar18;
            pcVar18 = pcVar19 + 1;
          } while (pcVar19[1] != '\0');
          *(undefined4 *)(pcVar19 + 1) = DAT_18003fae4;
          pcVar19[5] = DAT_18003fae8;
          uVar12 = FUN_180014460(&local_368,(char)lVar23);
          if ((int)uVar12 == 0) {
            puVar15 = operator_new(0x18);
            if (puVar15 == (undefined8 *)0x0) {
LAB_18000341f:
                    /* WARNING: Subroutine does not return */
              FUN_18003c7f0(0x8007000e);
            }
            puVar15[1] = 0;
            *(undefined4 *)(puVar15 + 2) = 1;
            pOVar10 = FUN_18003c920(&local_368);
            *puVar15 = pOVar10;
            local_528 = puVar9;
            puVar13 = operator_new(0x18);
            if (puVar13 == (undefined8 *)0x0) goto LAB_18000341f;
            *(undefined4 *)(puVar13 + 2) = 1;
            puVar13[1] = 0;
            pOVar10 = FUN_18003c920("Carbon Steel");
            *puVar13 = pOVar10;
            local_550 = (longlong *)0x0;
            local_530 = (longlong *)0x0;
            local_558 = (longlong *)0x0;
            plVar11 = (longlong *)GetGlobalPointer("HappNode");
            local_590 = plVar11;
            if (plVar11 != (longlong *)0x0) {
              (**(code **)(*plVar11 + 8))(plVar11);
              (**(code **)(*plVar11 + 0x90))(plVar11,&local_550);
              if (local_550 != (longlong *)0x0) {
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_508,"\\Data\\Model Analysis Tools\\Cost-Est\\Input\\BLOCK_ID");
                plVar2 = local_550;
                puVar16 = FUN_180001b40(&local_4a0,local_508);
                (**(code **)(*plVar2 + 0x110))(plVar2,*puVar16,&local_530);
                SysFreeString(local_4a0);
                if ((local_530 != (longlong *)0x0) &&
                   ((**(code **)(*local_530 + 200))(local_530,&local_558),
                   local_558 != (longlong *)0x0)) {
                  (**(code **)(*local_558 + 0x48))(local_558,local_580);
                  local_4d8._0_8_ = 0;
                  local_4d8.decVal.u2 = (_union_1719)(_struct_1720)0x0;
                  local_4d8._16_8_ = 0;
                  VariantInit((VARIANTARG *)&local_4d8.n2);
                  VariantInit((VARIANTARG *)&local_4d8.n2);
                  local_4d8.n2.vt = 0x2008;
                  local_500.lLbound = 0;
                  local_500.cElements = local_580[0];
                  local_4f8.s2 = (_struct_1720)SafeArrayCreate(8,1,&local_500);
                  SafeArrayAccessData((SAFEARRAY *)local_4f8.s2,&local_4a8);
                  puVar9 = local_528;
                  uVar5 = 0;
                  if (0 < (int)local_580[0]) {
                    lVar23 = 0;
                    do {
                      local_498._0_8_ = 0;
                      local_498.decVal.u2 = (_union_1719)(_struct_1720)0x0;
                      local_498._16_8_ = 0;
                      VariantInit((VARIANTARG *)&local_498.n2);
                      local_4c0._0_8_ = 0;
                      local_4c0.decVal.u2 = (_union_1719)(_struct_1720)0x0;
                      local_4c0._16_8_ = 0;
                      VariantInit((VARIANTARG *)&local_4c0.n2);
                      local_4f0._0_8_ = 0;
                      local_4f0.decVal.u2 = (_union_1719)(_struct_1720)0x0;
                      local_4f0._16_8_ = 0;
                      VariantInit((VARIANTARG *)&local_4f0.n2);
                      local_5b8 = &local_538;
                      local_480.n2.vt = 3;
                      local_5c0 = &local_468;
                      local_5c8 = &local_448;
                      local_538 = (longlong *)0x0;
                      local_458 = local_498._16_8_;
                      local_438 = local_498._16_8_;
                      local_418 = local_498._16_8_;
                      local_3f8 = local_498._16_8_;
                      local_468 = local_498._0_8_;
                      _Stack_460.Lo64 = (ULONGLONG)local_498.decVal.u2;
                      local_448 = (longlong *)local_498._0_8_;
                      _Stack_440.Lo64 = (ULONGLONG)local_498.decVal.u2;
                      local_428 = local_498._0_8_;
                      _Stack_420.Lo64 = (ULONGLONG)local_498.decVal.u2;
                      local_408 = local_498._0_8_;
                      _Stack_400.Lo64 = (ULONGLONG)local_498.decVal.u2;
                      local_3e8 = local_480._0_4_;
                      UStack_3e4 = local_480.decVal.Hi32;
                      uStack_3dc = local_480._12_4_;
                      local_3d8 = local_480._16_8_;
                      local_480._8_4_ = uVar5;
                      uStack_3e0 = uVar5;
                      (**(code **)(*local_558 + 0x68))(local_558,&local_3e8,&local_408,&local_428);
                      VariantClear((VARIANTARG *)&local_480.n2);
                      local_3c8 = local_4c0._0_4_;
                      UStack_3c4 = local_4c0.decVal.Hi32;
                      uStack_3c0 = local_4c0._8_4_;
                      uStack_3bc = local_4c0._12_4_;
                      local_3b8 = local_4c0._16_8_;
                      (**(code **)(*local_538 + 0x68))(local_538,&local_3c8,&local_4f0);
                      local_3a8 = local_4c0._0_4_;
                      UStack_3a4 = local_4c0.decVal.Hi32;
                      uStack_3a0 = local_4c0._8_4_;
                      uStack_39c = local_4c0._12_4_;
                      local_398 = local_4c0._16_8_;
                      iVar6 = (**(code **)(*local_538 + 0x68))(local_538,&local_3a8,&local_4f0);
                      if ((-1 < iVar6) && (local_4f0.n2.vt == 8)) {
                        ((_union_1719 *)((longlong)local_4a8 + lVar23))->s2 =
                             (_struct_1720)local_4f0.decVal.u2;
                        local_4f0._0_8_ = local_4f0._0_8_ & 0xffffffffffff0000;
                      }
                      if (local_538 != (longlong *)0x0) {
                        (**(code **)(*local_538 + 0x10))();
                      }
                      VariantClear((VARIANTARG *)&local_4f0.n2);
                      VariantClear((VARIANTARG *)&local_4c0.n2);
                      VariantClear((VARIANTARG *)&local_498.n2);
                      uVar5 = uVar5 + 1;
                      lVar23 = lVar23 + 8;
                    } while ((int)uVar5 < (int)local_580[0]);
                    plVar11 = local_590;
                  }
                  _Var4.s2 = local_4f8.s2;
                  SafeArrayUnaccessData((SAFEARRAY *)local_4f8.s2);
                  local_4d8.decVal.u2 = (_union_1719)(_union_1719)_Var4.s2;
                  SimThreadNoMT(1);
                  local_5c8 = &local_598;
                  local_388 = local_4d8._0_4_;
                  UStack_384 = local_4d8.decVal.Hi32;
                  uStack_380 = local_4d8._8_4_;
                  uStack_37c = local_4d8._12_4_;
                  local_378 = local_4d8._16_8_;
                  uVar5 = (**(code **)(*local_568 + 0x78))(local_568,*puVar15,&local_388,*puVar13);
                  local_590 = (longlong *)CONCAT44(local_590._4_4_,uVar5);
                  SimThreadNoMT(0);
                  lpFileName = (LPCSTR)puVar15[1];
                  puVar16 = puVar15 + 1;
                  local_528 = puVar16;
                  if (lpFileName == (LPCSTR)0x0) {
                    lpFileName = FUN_18003c800((LPCWSTR)*puVar15);
                    *puVar16 = lpFileName;
                  }
                  DeleteFileA(lpFileName);
                  if ((-1 < (int)local_590) && ((short)local_598 == -1)) {
                    FUN_180002270((longlong)local_148,(longlong)local_258);
                    puVar16 = operator_new(0x18);
                    if (puVar16 == (undefined8 *)0x0) {
LAB_180003435:
                    /* WARNING: Subroutine does not return */
                      FUN_18003c7f0(0x8007000e);
                    }
                    *(undefined4 *)(puVar16 + 2) = 1;
                    puVar16[1] = 0;
                    pOVar10 = FUN_18003c920(local_148);
                    *puVar16 = pOVar10;
                    puVar17 = operator_new(0x18);
                    if (puVar17 == (undefined8 *)0x0) goto LAB_180003435;
                    *(undefined4 *)(puVar17 + 2) = 1;
                    puVar17[1] = 0;
                    pOVar10 = FUN_18003c920(local_258);
                    *puVar17 = pOVar10;
                    SimThreadNoMT(1);
                    (**(code **)(*local_568 + 0x60))(local_568,*puVar16,*puVar17,&local_598);
                    SimThreadNoMT(0);
                    local_520._0_8_ = 0;
                    local_520.decVal.u2 = (_union_1719)(_struct_1720)0x0;
                    local_520._16_8_ = (IRecordInfo *)0x0;
                    VariantInit((VARIANTARG *)&local_520.n2);
                    if (((local_560 == (_union_2707 *)0x0) || (&local_520 == local_560)) ||
                       (HVar8 = VariantClear((VARIANTARG *)&local_520.n2), HVar8 < 0)) {
                      FUN_180001c80((VARIANTARG *)&local_520.n2,local_258);
                      if (local_560 != (_union_2707 *)0x0) goto LAB_180002f28;
                    }
                    else {
                      local_520.n2.vt = (local_560->n2).vt;
                      local_520.n2.wReserved1 = (local_560->n2).wReserved1;
                      local_520.n2.wReserved2 = (local_560->n2).wReserved2;
                      local_520.n2.wReserved3 = (local_560->n2).wReserved3;
                      local_520.decVal.u2 = (_union_1719)*(_union_1719 *)&(local_560->decVal).u2.s2;
                      local_520._16_8_ = (local_560->n2).n3.brecVal.pRecInfo;
                      (local_560->n2).vt = 0;
                      FUN_180001c80((VARIANTARG *)&local_520.n2,local_258);
LAB_180002f28:
                      HVar8 = VariantClear((VARIANTARG *)&local_560->n2);
                      if (-1 < HVar8) {
                        (local_560->n2).vt = local_520._0_2_;
                        (local_560->n2).wReserved1 = local_520.n2.wReserved1;
                        (local_560->n2).wReserved2 = local_520.n2.wReserved2;
                        (local_560->n2).wReserved3 = local_520.n2.wReserved3;
                        (local_560->decVal).u2.s2 = (_struct_1720)local_520.decVal.u2;
                        (local_560->n2).n3.brecVal.pRecInfo = (IRecordInfo *)local_520._16_8_;
                        local_520._0_8_ = local_520._0_8_ & 0xffffffffffff0000;
                      }
                    }
                    VariantClear((VARIANTARG *)&local_520.n2);
                    LOCK();
                    piVar1 = (int *)(puVar17 + 2);
                    iVar6 = *piVar1;
                    *piVar1 = *piVar1 + -1;
                    UNLOCK();
                    if (iVar6 == 1) {
                      if ((BSTR)*puVar17 != (BSTR)0x0) {
                        SysFreeString((BSTR)*puVar17);
                        *puVar17 = 0;
                      }
                      if ((void *)puVar17[1] != (void *)0x0) {
                        operator_delete__((void *)puVar17[1]);
                        puVar17[1] = 0;
                      }
                      FUN_180001300(puVar17);
                    }
                    LOCK();
                    piVar1 = (int *)(puVar16 + 2);
                    iVar6 = *piVar1;
                    *piVar1 = *piVar1 + -1;
                    UNLOCK();
                    if (iVar6 == 1) {
                      if ((BSTR)*puVar16 != (BSTR)0x0) {
                        SysFreeString((BSTR)*puVar16);
                        *puVar16 = 0;
                      }
                      if ((void *)puVar16[1] != (void *)0x0) {
                        operator_delete__((void *)puVar16[1]);
                        puVar16[1] = 0;
                      }
                      FUN_180001300(puVar16);
                    }
                    puVar16 = local_528;
                  }
                  (**(code **)(*local_568 + 0x80))(local_568,&local_598);
                  VariantClear((VARIANTARG *)&local_4d8.n2);
                  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &local_508);
                  (**(code **)(*plVar11 + 0x10))(plVar11);
                  if (local_558 != (longlong *)0x0) {
                    (**(code **)(*local_558 + 0x10))();
                  }
                  if (local_530 != (longlong *)0x0) {
                    (**(code **)(*local_530 + 0x10))();
                  }
                  if (local_550 != (longlong *)0x0) {
                    (**(code **)(*local_550 + 0x10))();
                  }
                  LOCK();
                  piVar1 = (int *)(puVar13 + 2);
                  iVar6 = *piVar1;
                  *piVar1 = *piVar1 + -1;
                  UNLOCK();
                  if (iVar6 == 1) {
                    if ((BSTR)*puVar13 != (BSTR)0x0) {
                      SysFreeString((BSTR)*puVar13);
                      *puVar13 = 0;
                    }
                    if ((void *)puVar13[1] != (void *)0x0) {
                      operator_delete__((void *)puVar13[1]);
                      puVar13[1] = 0;
                    }
                    FUN_180001300(puVar13);
                  }
                  LOCK();
                  piVar1 = (int *)(puVar15 + 2);
                  iVar6 = *piVar1;
                  *piVar1 = *piVar1 + -1;
                  UNLOCK();
                  if (iVar6 == 1) {
                    if ((BSTR)*puVar15 != (BSTR)0x0) {
                      SysFreeString((BSTR)*puVar15);
                      *puVar15 = 0;
                    }
                    if ((void *)*puVar16 != (void *)0x0) {
                      operator_delete__((void *)*puVar16);
                      *puVar16 = 0;
                    }
                    FUN_180001300(puVar15);
                  }
                  goto LAB_1800030cd;
                }
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_508);
              }
              (**(code **)(*plVar11 + 0x10))(plVar11);
            }
            if (local_558 != (longlong *)0x0) {
              (**(code **)(*local_558 + 0x10))();
            }
            if (local_530 != (longlong *)0x0) {
              (**(code **)(*local_530 + 0x10))();
            }
            if (local_550 != (longlong *)0x0) {
              (**(code **)(*local_550 + 0x10))();
            }
            LOCK();
            piVar1 = (int *)(puVar13 + 2);
            iVar6 = *piVar1;
            *piVar1 = *piVar1 + -1;
            UNLOCK();
            if (iVar6 == 1) {
              if ((BSTR)*puVar13 != (BSTR)0x0) {
                SysFreeString((BSTR)*puVar13);
                *puVar13 = 0;
              }
              if ((void *)puVar13[1] != (void *)0x0) {
                operator_delete__((void *)puVar13[1]);
                puVar13[1] = 0;
              }
              FUN_180001300(puVar13);
            }
            LOCK();
            piVar1 = (int *)(puVar15 + 2);
            iVar6 = *piVar1;
            *piVar1 = *piVar1 + -1;
            UNLOCK();
            if (iVar6 == 1) {
              if ((BSTR)*puVar15 != (BSTR)0x0) {
                SysFreeString((BSTR)*puVar15);
                *puVar15 = 0;
              }
              if ((void *)puVar15[1] != (void *)0x0) {
                operator_delete__((void *)puVar15[1]);
                puVar15[1] = 0;
              }
              FUN_180001300(puVar15);
            }
            puVar15 = local_588;
          }
          puVar13 = local_588;
          if (puVar15 != (undefined8 *)0x0) {
            LOCK();
            piVar1 = (int *)(puVar15 + 2);
            iVar6 = *piVar1;
            *piVar1 = *piVar1 + -1;
            UNLOCK();
            if (iVar6 == 1) {
              if ((BSTR)*local_588 != (BSTR)0x0) {
                SysFreeString((BSTR)*local_588);
                *puVar13 = 0;
              }
              if ((void *)puVar13[1] != (void *)0x0) {
                operator_delete__((void *)puVar13[1]);
                puVar13[1] = 0;
              }
              FUN_180001300(puVar13);
            }
          }
          puVar15 = local_578;
          if (local_578 != (undefined8 *)0x0) {
            LOCK();
            piVar1 = (int *)(local_578 + 2);
            iVar6 = *piVar1;
            *piVar1 = *piVar1 + -1;
            UNLOCK();
            if (iVar6 == 1) {
              if ((BSTR)*local_578 != (BSTR)0x0) {
                SysFreeString((BSTR)*local_578);
                *puVar15 = 0;
              }
              if ((void *)puVar15[1] != (void *)0x0) {
                operator_delete__((void *)puVar15[1]);
                puVar15[1] = 0;
              }
              FUN_180001300(puVar15);
            }
          }
          puVar15 = local_570;
          if (local_570 != (undefined8 *)0x0) {
            LOCK();
            piVar1 = (int *)(local_570 + 2);
            iVar6 = *piVar1;
            *piVar1 = *piVar1 + -1;
            UNLOCK();
            if (iVar6 == 1) {
              if ((BSTR)*local_570 != (BSTR)0x0) {
                SysFreeString((BSTR)*local_570);
                *puVar15 = 0;
              }
              if ((void *)puVar15[1] != (void *)0x0) {
                operator_delete__((void *)puVar15[1]);
                puVar15[1] = 0;
              }
              FUN_180001300(puVar15);
            }
          }
          uVar5 = 0;
          goto LAB_180003393;
        }
      }
      puVar13 = local_588;
      if (puVar15 != (undefined8 *)0x0) {
        LOCK();
        piVar1 = (int *)(puVar15 + 2);
        iVar6 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar6 == 1) {
          if ((BSTR)*local_588 != (BSTR)0x0) {
            SysFreeString((BSTR)*local_588);
            *puVar13 = 0;
          }
          if ((void *)puVar13[1] != (void *)0x0) {
            operator_delete__((void *)puVar13[1]);
            puVar13[1] = 0;
          }
          FUN_180001300(puVar13);
        }
      }
      puVar15 = local_578;
      if (local_578 != (undefined8 *)0x0) {
        LOCK();
        piVar1 = (int *)(local_578 + 2);
        iVar6 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar6 == 1) {
          if ((BSTR)*local_578 != (BSTR)0x0) {
            SysFreeString((BSTR)*local_578);
            *puVar15 = 0;
          }
          if ((void *)puVar15[1] != (void *)0x0) {
            operator_delete__((void *)puVar15[1]);
            puVar15[1] = 0;
          }
          FUN_180001300(puVar15);
        }
      }
      puVar15 = local_570;
      if (local_570 != (undefined8 *)0x0) {
        LOCK();
        piVar1 = (int *)(local_570 + 2);
        iVar6 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar6 == 1) {
          if ((BSTR)*local_570 != (BSTR)0x0) {
            SysFreeString((BSTR)*local_570);
            *puVar15 = 0;
          }
          if ((void *)puVar15[1] != (void *)0x0) {
            operator_delete__((void *)puVar15[1]);
            puVar15[1] = 0;
          }
          FUN_180001300(puVar15);
        }
      }
    }
    uVar5 = 1;
  }
LAB_180003393:
  LOCK();
  piVar1 = (int *)(puVar9 + 2);
  iVar6 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar6 == 1) {
    if ((BSTR)*puVar9 != (BSTR)0x0) {
      SysFreeString((BSTR)*puVar9);
      *puVar9 = 0;
    }
    if ((void *)puVar9[1] != (void *)0x0) {
      operator_delete__((void *)puVar9[1]);
      puVar9[1] = 0;
    }
    FUN_180001300(puVar9);
  }
LAB_1800033cf:
  if (local_568 != (longlong *)0x0) {
    (**(code **)(*local_568 + 0x10))();
  }
  if (local_548 != (longlong *)0x0) {
    (**(code **)(*local_548 + 0x10))();
  }
  return uVar5;
}

/* RVA 0x3440 */
char * SimSBShowBlocksGetItems
                 (int param_1,longlong param_2,int param_3,undefined8 param_4,char *param_5)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  longlong *plVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  longlong lVar9;
  char *local_48;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_40 [8];
  
                    /* 0x3440  159  SimSBShowBlocksGetItems */
  FUN_180019bf0("",1);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_48,"");
  if (param_1 < 1) {
    param_5 = local_48;
  }
  else {
    plVar4 = &DAT_18004f608;
    if (param_1 == 0xc) {
      plVar4 = &DAT_18004f628;
    }
    lVar6 = 0;
    iVar2 = (int)(plVar4[1] - *plVar4 >> 5);
    lVar8 = (longlong)iVar2;
    if (0 < iVar2) {
      lVar5 = 0;
      lVar9 = lVar8;
      do {
        lVar7 = DAT_18004f608;
        if (param_1 == 0xc) {
          lVar7 = DAT_18004f628;
        }
        if (*(int *)(lVar7 + 0x10 + lVar5) == -1) {
          pcVar3 = ATL::CSimpleStringT<char,1>::GetBuffer
                             ((CSimpleStringT<char,1> *)(lVar7 + 8 + lVar5),9);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_40);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                    (local_40,"1^%s",pcVar3);
          ATL::CSimpleStringT<char,1>::ReleaseBuffer
                    ((CSimpleStringT<char,1> *)(lVar7 + 8 + lVar5),-1);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_48,
                     (CSimpleStringT<char,1> *)local_40);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_48,"|")
          ;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_40);
        }
        lVar5 = lVar5 + 0x20;
        lVar9 = lVar9 + -1;
      } while (lVar9 != 0);
    }
    if (param_2 != 0) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_40);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                (local_40,"0^%s",param_2);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_48,
                 (CSimpleStringT<char,1> *)local_40);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_48,"|");
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_40);
    }
    if (0 < lVar8) {
      do {
        lVar9 = DAT_18004f608;
        if (param_1 == 0xc) {
          lVar9 = DAT_18004f628;
        }
        if (*(int *)(lVar9 + 0x10 + lVar6) == param_3) {
          pcVar3 = ATL::CSimpleStringT<char,1>::GetBuffer
                             ((CSimpleStringT<char,1> *)(lVar9 + 8 + lVar6),9);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_40);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                    (local_40,"0^%s",pcVar3);
          ATL::CSimpleStringT<char,1>::ReleaseBuffer
                    ((CSimpleStringT<char,1> *)(lVar9 + 8 + lVar6),-1);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_48,
                     (CSimpleStringT<char,1> *)local_40);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_48,"|")
          ;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_40);
        }
        lVar6 = lVar6 + 0x20;
        lVar8 = lVar8 + -1;
      } while (lVar8 != 0);
    }
    lVar6 = (longlong)param_5 - (longlong)local_48;
    do {
      cVar1 = *local_48;
      local_48[lVar6] = cVar1;
      local_48 = local_48 + 1;
    } while (cVar1 != '\0');
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_48);
  return param_5;
}

/* RVA 0x36e0 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

CArchive *
FUN_1800036e0(CArchive *param_1,
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_2)

{
  uint uVar1;
  uint uVar2;
  __uint64 _Var3;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar4;
  ulonglong uVar5;
  undefined1 auStack_178 [32];
  int local_158 [2];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_150 [8];
  char *local_148;
  char local_140 [136];
  wchar_t *local_b8;
  wchar_t local_b0 [68];
  ulonglong local_28;
  
  local_28 = DAT_1800516d8 ^ (ulonglong)auStack_178;
  _Var3 = AfxReadStringLength(param_1,local_158);
  uVar1 = (uint)_Var3;
  uVar5 = _Var3 & 0xffffffff;
  if (local_158[0] != 1) {
    local_b8 = (wchar_t *)0x0;
    if (uVar1 != 0) {
      if (0xffffffffffffffff / uVar5 < 2) {
                    /* WARNING: Subroutine does not return */
        FUN_180001380(-0x7ff8fdea);
      }
      if (0x80 < uVar5 * 2) {
        FUN_1800038e0(&local_b8,uVar5 * 2);
        goto LAB_1800037e5;
      }
    }
    local_b8 = local_b0;
LAB_1800037e5:
    uVar2 = CArchive::Read(param_1,local_b8,uVar1 * 2);
    if ((ulonglong)uVar2 != uVar5 * 2) {
                    /* WARNING: Subroutine does not return */
      AfxThrowArchiveException(3,(char *)0x0);
    }
    pCVar4 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_150,local_b8,uVar1)
    ;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(param_2,pCVar4);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_150);
    if (local_b8 == local_b0) {
      return param_1;
    }
    FUN_180003910(&local_b8);
    return param_1;
  }
  local_148 = (char *)0x0;
  if (uVar1 != 0) {
    if (0xffffffffffffffff / uVar5 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_180001380(-0x7ff8fdea);
    }
    if (0x80 < uVar5) {
      FUN_1800038e0(&local_148,_Var3 & 0xffffffff);
      goto LAB_180003771;
    }
  }
  local_148 = local_140;
LAB_180003771:
  uVar2 = CArchive::Read(param_1,local_148,uVar1);
  if (uVar2 != uVar1) {
                    /* WARNING: Subroutine does not return */
    AfxThrowArchiveException(3,(char *)0x0);
  }
  pCVar4 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
           ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
           CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_150,local_148,uVar1);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(param_2,pCVar4);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_150);
  if (local_148 != local_140) {
    FUN_180003910(&local_148);
  }
  return param_1;
}

/* RVA 0x38e0 */
void FUN_1800038e0(undefined8 *param_1,size_t param_2)

{
  void *pvVar1;
  
  pvVar1 = malloc(param_2);
  if (pvVar1 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_180001380(-0x7ff8fff2);
  }
  *param_1 = pvVar1;
  return;
}

/* RVA 0x3910 */
void FUN_180003910(undefined8 *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000180003913. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  free((void *)*param_1);
  return;
}

/* RVA 0x3920 */
ulonglong FUN_180003920(undefined8 param_1)

{
  char cVar1;
  char cVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *this;
  undefined7 extraout_var;
  ulonglong uVar8;
  uint local_res10 [2];
  uint local_res18 [2];
  char *local_res20;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_38 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_30 [8];
  undefined8 local_28 [2];
  
  uVar8 = 0;
  pcVar6 = (char *)SEGetSettingValue("servertype",0);
  if (pcVar6 != (char *)0x0) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_30,pcVar6);
    for (uVar4 = FUN_180019fe0(0xffffffff,local_28,(longlong *)&local_res20,local_res18,local_res10)
        ; uVar4 != 0xffffffff;
        uVar4 = FUN_180019fe0(uVar4,local_28,(longlong *)&local_res20,local_res18,local_res10)) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_38,local_res20);
      pcVar7 = pcVar6;
      do {
        cVar1 = *pcVar7;
        cVar2 = pcVar7[(longlong)local_res20 - (longlong)pcVar6];
        if (cVar1 != cVar2) break;
        pcVar7 = pcVar7 + 1;
      } while (cVar2 != '\0');
      if (cVar1 == cVar2) {
LAB_180003a2a:
        if (local_res10[0] != 0) {
          DAT_18004f780 = uVar4 - 1;
          bVar3 = FUN_180003d80(param_1,(char *)0x0);
          uVar8 = CONCAT71(extraout_var,bVar3) & 0xffffffff;
        }
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_38);
        break;
      }
      this = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::MakeLower(local_30)
      ;
      iVar5 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Find
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)this,
                         "no default",0);
      if (iVar5 != -1) goto LAB_180003a2a;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_38);
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_30);
  }
  return uVar8;
}

/* RVA 0x3a70 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool FUN_180003a70(undefined8 param_1,longlong *param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined7 extraout_var;
  int *piVar5;
  char *pcVar6;
  LPWSTR lpWideCharStr;
  undefined1 *puVar7;
  longlong *plVar8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar9;
  int iVar10;
  undefined1 auStackY_148 [24];
  undefined8 uStackY_130;
  WCHAR local_118 [16];
  int local_f8 [2];
  char *local_f0;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_e8 [8];
  IStream *local_e0;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_d8 [8];
  longlong local_d0;
  CArchive local_c8 [24];
  CSimpleStringT<char,1> local_b0 [8];
  uint local_a8;
  int *local_90;
  int *local_88;
  COleStreamFile local_58 [56];
  ulonglong local_20;
  
  local_20 = DAT_1800516d8 ^ (ulonglong)local_f8;
  local_e0 = (IStream *)0x0;
  uStackY_130 = 0x180003abe;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_d8);
  puVar7 = auStackY_148 + 0x20;
  iVar4 = 0;
  iVar10 = 0;
  if (param_2 != (longlong *)0x0) {
    lpWideCharStr = local_118;
    if (lpWideCharStr == (LPWSTR)0x0) {
      lpWideCharStr = (LPWSTR)0x0;
    }
    else {
      local_118[0] = L'\0';
      iVar2 = MultiByteToWideChar(0,0,"ACCTINFO",-1,lpWideCharStr,9);
      if (iVar2 == 0) {
        lpWideCharStr = (LPWSTR)0x0;
      }
    }
    iVar2 = (**(code **)(*param_2 + 0x20))(param_2,lpWideCharStr,0,0x10);
    puVar7 = auStackY_148;
    if (iVar2 == 0) {
      COleStreamFile::COleStreamFile(local_58,local_e0);
      CArchive::CArchive(local_c8,(CFile *)local_58,1,0x1000,(void *)0x0);
      if ((local_a8 & 1) == 0) {
        pcVar6 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64(local_b0);
                    /* WARNING: Subroutine does not return */
        AfxThrowArchiveException(4,pcVar6);
      }
      piVar5 = local_90;
      if (local_88 < local_90 + 1) {
        CArchive::FillBuffer(local_c8,((int)local_90 - (int)local_88) + 4);
        piVar5 = local_90;
      }
      iVar2 = *piVar5;
      local_90 = piVar5 + 1;
      if ((local_a8 & 1) == 0) {
        pcVar6 = ATL::CSimpleStringT<char,1>::operator_char_const____ptr64(local_b0);
                    /* WARNING: Subroutine does not return */
        AfxThrowArchiveException(4,pcVar6);
      }
      if (local_88 < piVar5 + 2) {
        CArchive::FillBuffer(local_c8,((int)local_90 - (int)local_88) + 4);
      }
      local_90 = local_90 + 1;
      FUN_1800036e0(local_c8,local_d8);
      iVar10 = iVar4;
      if (iVar2 == 1) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_f0);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_f8);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_e8);
        FUN_1800036e0(local_c8,(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                               &local_f0);
        FUN_1800036e0(local_c8,(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                               local_f8);
        FUN_1800036e0(local_c8,local_e8);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_e8);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_f8);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_f0);
      }
      else {
        pCVar9 = local_e8;
        plVar8 = &local_d0;
        for (uVar3 = FUN_180019fe0(0xffffffff,&local_f0,plVar8,(uint *)pCVar9,(uint *)local_f8);
            uVar3 != 0xffffffff;
            uVar3 = FUN_180019fe0(uVar3,&local_f0,plVar8,(uint *)pCVar9,(uint *)local_f8)) {
          iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                            (local_d8,local_f0);
          if (iVar4 == 0) {
            if (local_f8[0] != 0) {
              DAT_18004f780 = uVar3 - 1;
              pcVar6 = "Restoring connection to local server ...";
              bVar1 = FUN_180003d80(param_1,"Restoring connection to local server ...");
              iVar10 = (int)CONCAT71(extraout_var,bVar1);
              SimResume(0,pcVar6,(int *)plVar8,(char *)pCVar9);
            }
            break;
          }
          pCVar9 = local_e8;
          plVar8 = &local_d0;
        }
      }
      puVar7 = auStackY_148;
      (*local_e0->lpVtbl->Release)(local_e0);
      CArchive::~CArchive(local_c8);
      COleStreamFile::~COleStreamFile(local_58);
    }
  }
  *(undefined8 *)(puVar7 + -8) = 0x180003d13;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_d8);
  *(undefined8 *)(puVar7 + -8) = 0x180003d24;
  return iVar10 != 0;
}

/* RVA 0x3d80 */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool FUN_180003d80(undefined8 param_1,char *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  BOOL BVar3;
  DWORD DVar4;
  CWinThread *pCVar5;
  undefined8 uVar6;
  uint uVar7;
  int *piVar8;
  char *pcVar9;
  bool bVar10;
  undefined1 auStackY_e8 [32];
  longlong local_b8;
  undefined8 local_b0;
  uint local_a8 [2];
  longlong local_a0;
  uint local_98 [2];
  char *local_90;
  longlong local_88;
  tagMSG local_80;
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 local_48;
  char *local_40;
  undefined4 local_38;
  char local_34;
  undefined8 local_33;
  undefined8 uStack_2b;
  undefined2 local_23;
  undefined1 local_21;
  ulonglong local_20;
  
  local_20 = DAT_1800516d8 ^ (ulonglong)auStackY_e8;
  bVar10 = false;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b8);
  uVar1 = DAT_180051bc0;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b0);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_a0);
  uVar2 = FUN_180019fe0(0xffffffff,&local_90,&local_88,local_98,local_a8);
  do {
    uVar7 = 0;
    if (uVar2 == 0xffffffff) {
LAB_180003e44:
      if (*(int *)(local_a0 + -0x10) == 0) {
        DAT_180051dd0 = 4;
      }
      else {
        ATL::CSimpleStringT<char,1>::Empty((CSimpleStringT<char,1> *)&local_b8);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b8,
                   (CSimpleStringT<char,1> *)&local_a0);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b8,'\0');
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b8,
                   &DAT_18004f784);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b8,'\0');
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b8,
                   &DAT_18004f7d4);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b8,'\0');
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b8,
                   &DAT_18004f824);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b8,'\0');
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b8,
                   &DAT_18004f874);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b8,'\0');
        if (param_2 == (char *)0x0) {
          if (uVar7 == 0) {
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b0,
                       "Connecting to remote server ");
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b0,
                       &DAT_18004f784);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b0,
                       " ...");
          }
          else {
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b0,
                       "Connecting to local server ...");
          }
        }
        else {
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b0,
                     param_2);
        }
        if (DAT_18004f8c4 != 0) {
          DAT_180051bc0 = 1;
        }
        local_48 = 0;
        local_33 = 0;
        uStack_2b = 0;
        local_23 = 0;
        local_21 = 0;
        local_50 = 0xc;
        local_40 = ATL::CSimpleStringT<char,1>::GetBuffer
                             ((CSimpleStringT<char,1> *)&local_b8,*(int *)(local_b8 + -0x10));
        local_4c = 0;
        local_38 = 0;
        local_34 = '\0';
        pCVar5 = AfxBeginThread(FUN_180015d70,&local_50,0,0,0,(_SECURITY_ATTRIBUTES *)0x0);
        *(undefined4 *)(pCVar5 + 0x50) = 0;
        FUN_1800074b0(0x559,local_b0,1);
        do {
          pcVar9 = (char *)0x0;
          BVar3 = PeekMessageA(&local_80,(HWND)0x0,0,0,1);
          if (BVar3 != 0) {
            DispatchMessageA(&local_80);
          }
        } while (local_34 == '\0');
        piVar8 = (int *)0x0;
        FUN_1800074b0(0x559,0,0);
        uVar6 = 1000;
        DVar4 = WaitForSingleObject(*(HANDLE *)(pCVar5 + 0x58),1000);
        if (DVar4 != 0x102) {
          uVar6 = 1;
          (**(code **)(*(longlong *)pCVar5 + 8))();
        }
        bVar10 = local_33._3_4_ == 0;
        if (bVar10) {
          DAT_180051dd0 = 0;
          SimResume(0,uVar6,piVar8,pcVar9);
        }
        else {
          DAT_180051dd0 = 3;
        }
        DAT_180051bc0 = uVar1;
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_a0);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b0);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_b8);
      return bVar10;
    }
    if (uVar2 == DAT_18004f780 + 1U) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_a0,local_90
                );
      uVar7 = local_a8[0];
      goto LAB_180003e44;
    }
    uVar2 = FUN_180019fe0(uVar2,&local_90,&local_88,local_98,local_a8);
  } while( true );
}

/* RVA 0x40c0 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1800040c0(void)

{
  int iVar1;
  BOOL BVar2;
  DWORD DVar3;
  CWinThread *pCVar4;
  undefined8 local_res10;
  char *local_res18;
  char *local_res20;
  int *local_48;
  char *local_40;
  tagMSG local_38;
  
  if (*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) + 4) <
      DAT_180051b30) {
    FUN_18003bdf0(&DAT_180051b30);
    if (DAT_180051b30 == -1) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&DAT_180051b28);
      atexit((_func_5014 *)&LAB_18003d650);
      _Init_thread_footer(&DAT_180051b30);
    }
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_40);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_48);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res18);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res10);
  iVar1 = GRinqcnn();
  if (iVar1 != 0) {
    FUN_180020230(3,0);
  }
  ATL::CSimpleStringT<char,1>::Empty((CSimpleStringT<char,1> *)&DAT_180051b28);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&DAT_180051b28,'A');
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&DAT_180051b28,'\0');
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&DAT_180051b28,"");
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&DAT_180051b28,'\0');
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&DAT_180051b28,"");
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&DAT_180051b28,'\0');
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&DAT_180051b28,"");
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&DAT_180051b28,'\0');
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&DAT_180051b28,"");
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&DAT_180051b28,'\0');
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res10,
             "Connecting to local server ...");
  uRam0000000180051b40 = 0;
  _DAT_180051b48 = (char *)0x0;
  _DAT_180051b50 = 0;
  _DAT_180051b58 = 0;
  uRam0000000180051b60 = 0;
  _DAT_180051b38 = 0xc;
  _DAT_180051b48 =
       ATL::CSimpleStringT<char,1>::GetBuffer
                 ((CSimpleStringT<char,1> *)&DAT_180051b28,*(int *)(DAT_180051b28 + -0x10));
  _DAT_180051b38 = _DAT_180051b38 & 0xffffffff;
  _DAT_180051b50 = _DAT_180051b50 & 0xffffff0000000000;
  _DAT_180051b58 = CONCAT44(DAT_180051b58_4,0x7a0);
  pCVar4 = AfxBeginThread(FUN_180015d70,&DAT_180051b38,0,0,0,(_SECURITY_ATTRIBUTES *)0x0);
  *(undefined4 *)(pCVar4 + 0x50) = 0;
  FUN_1800074b0(0x559,local_res10,1);
  do {
    BVar2 = PeekMessageA(&local_38,(HWND)0x0,0,0,1);
    if (BVar2 != 0) {
      DispatchMessageA(&local_38);
    }
  } while (DAT_180051b54 == '\0');
  FUN_1800074b0(0x559,0,0);
  DVar3 = WaitForSingleObject(*(HANDLE *)(pCVar4 + 0x58),1000);
  if (DVar3 != 0x102) {
    (**(code **)(*(longlong *)pCVar4 + 8))(pCVar4,1);
  }
  SimSetConnectInfo(0,local_40,(char *)local_48,local_res20,local_res18,0);
  DAT_180051c2c = 0;
  SimResume(0,local_40,local_48,local_res20);
  COprocom(1);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res10);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res18);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_48);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_40);
  return;
}

/* RVA 0x4400 */
undefined8 FUN_180004400(undefined8 param_1,int param_2)

{
  AFX_MODULE_STATE *pAVar1;
  
  if (param_2 == 1) {
    pAVar1 = AfxGetModuleState();
    *(undefined8 *)(pAVar1 + 0x30) = *(undefined8 *)(pAVar1 + 0x38);
    *(undefined8 *)(pAVar1 + 0x48) = *(undefined8 *)(pAVar1 + 0x50);
    *(undefined8 *)(pAVar1 + 0x38) = 0;
    *(undefined8 *)(pAVar1 + 0x50) = 0;
  }
  return 1;
}

/* RVA 0x4440 */
uint FUN_180004440(undefined8 *param_1,undefined8 *param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  uint uVar3;
  undefined8 *_Buf1;
  ulonglong _Size;
  undefined8 *_Buf2;
  
  _Buf2 = param_2;
  if (0xf < (ulonglong)param_2[3]) {
    _Buf2 = (undefined8 *)*param_2;
  }
  _Buf1 = param_1;
  if (0xf < (ulonglong)param_1[3]) {
    _Buf1 = (undefined8 *)*param_1;
  }
  uVar1 = param_2[2];
  uVar2 = param_1[2];
  _Size = uVar2;
  if (uVar1 < uVar2) {
    _Size = uVar1;
  }
  uVar3 = memcmp(_Buf1,_Buf2,_Size);
  if (uVar3 == 0) {
    if (uVar2 < uVar1) {
      return 1;
    }
    uVar3 = 0;
  }
  return uVar3 >> 0x1f;
}

/* RVA 0x44b0 */
void FUN_1800044b0(ulonglong param_1)

{
  void *pvVar1;
  
  if (param_1 + 0x27 <= param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_180005ed0();
  }
  pvVar1 = operator_new(param_1 + 0x27);
  if (pvVar1 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    _invalid_parameter_noinfo_noreturn();
  }
  *(void **)(((longlong)pvVar1 + 0x27U & 0xffffffffffffffe0) - 8) = pvVar1;
  return;
}

/* RVA 0x44f0 */
void FUN_1800044f0(undefined8 *param_1,void *param_2,size_t param_3)

{
  __uint64 _Var1;
  ulonglong uVar2;
  void *_Dst;
  
  if (0x7fffffffffffffff < param_3) {
                    /* WARNING: Subroutine does not return */
    FUN_180005f10();
  }
  param_1[3] = 0xf;
  if (param_3 < 0x10) {
    param_1[2] = param_3;
    memcpy(param_1,param_2,param_3);
    *(undefined1 *)(param_3 + (longlong)param_1) = 0;
  }
  else {
    uVar2 = param_3 | 0xf;
    if (uVar2 < 0x8000000000000000) {
      if (uVar2 < 0x16) {
        uVar2 = 0x16;
      }
      _Var1 = uVar2 + 1;
      if (_Var1 < 0x1000) {
        if (_Var1 == 0) {
          _Dst = (void *)0x0;
        }
        else {
          _Dst = operator_new(_Var1);
        }
      }
      else {
        _Dst = (void *)FUN_1800044b0(_Var1);
      }
    }
    else {
      _Dst = (void *)FUN_1800044b0(0x8000000000000000);
      uVar2 = 0x7fffffffffffffff;
    }
    *param_1 = _Dst;
    param_1[2] = param_3;
    param_1[3] = uVar2;
    memcpy(_Dst,param_2,param_3);
    *(undefined1 *)((longlong)_Dst + param_3) = 0;
  }
  return;
}

/* RVA 0x45e0 */
void FUN_1800045e0(longlong *param_1,longlong *param_2)

{
  if (param_1 != param_2) {
    do {
      (**(code **)(*param_1 + 8))(param_1,0);
      param_1 = param_1 + 4;
    } while (param_1 != param_2);
  }
  return;
}

/* RVA 0x4620 */
CSimSeqObj * FUN_180004620(longlong *param_1,CSimSeqObj *param_2,CSimSeqObj *param_3)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong lVar3;
  CSimSeqObj *pCVar4;
  ulonglong uVar5;
  __uint64 _Var6;
  ulonglong uVar7;
  CSimSeqObj *this;
  
  lVar2 = *param_1;
  lVar3 = param_1[1] - lVar2 >> 5;
  uVar7 = 0x7ffffffffffffff;
  if (lVar3 == 0x7ffffffffffffff) {
                    /* WARNING: Subroutine does not return */
    FUN_180005f30();
  }
  uVar1 = lVar3 + 1;
  uVar5 = param_1[2] - lVar2 >> 5;
  if (0x7ffffffffffffff - (uVar5 >> 1) < uVar5) {
    pCVar4 = (CSimSeqObj *)FUN_1800044b0(0xffffffffffffffe0);
  }
  else {
    uVar5 = (uVar5 >> 1) + uVar5;
    uVar7 = uVar1;
    if (uVar1 <= uVar5) {
      uVar7 = uVar5;
    }
    if (0x7ffffffffffffff < uVar7) {
                    /* WARNING: Subroutine does not return */
      FUN_180005ed0();
    }
    _Var6 = uVar7 << 5;
    if (_Var6 < 0x1000) {
      if (_Var6 == 0) {
        pCVar4 = (CSimSeqObj *)0x0;
      }
      else {
        pCVar4 = operator_new(_Var6);
      }
    }
    else {
      pCVar4 = (CSimSeqObj *)FUN_1800044b0(_Var6);
    }
  }
  this = pCVar4 + ((longlong)param_2 - lVar2 & 0xffffffffffffffe0);
  CSimSeqObj::CSimSeqObj(this,param_3);
  if (param_2 == (CSimSeqObj *)param_1[1]) {
    FUN_180005600((CSimSeqObj *)*param_1,(CSimSeqObj *)param_1[1],pCVar4);
  }
  else {
    FUN_180005600((CSimSeqObj *)*param_1,param_2,pCVar4);
    FUN_180005600(param_2,(CSimSeqObj *)param_1[1],this + 0x20);
  }
  FUN_180005ad0(param_1,(longlong)pCVar4,uVar1,uVar7);
  return this;
}

/* RVA 0x47a0 */
void FUN_1800047a0(undefined8 param_1,undefined8 param_2,longlong *param_3)

{
  char cVar1;
  longlong *plVar2;
  
  cVar1 = *(char *)((longlong)param_3 + 0x19);
  while (cVar1 == '\0') {
    FUN_1800047a0(param_1,param_2,(longlong *)param_3[2]);
    plVar2 = (longlong *)*param_3;
    FUN_180005800(param_3 + 4);
    FUN_180001300(param_3);
    param_3 = plVar2;
    cVar1 = *(char *)((longlong)plVar2 + 0x19);
  }
  return;
}

/* RVA 0x4820 */
void FUN_180004820(longlong *param_1,CSimSeqObj *param_2,CSimSeqObj *param_3,ulonglong param_4)

{
  CSimSeqObj *pCVar1;
  CSimSeqObj *pCVar2;
  CSimSeqObj *this;
  CSimSeqObj *pCVar3;
  longlong lVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  ulonglong local_88;
  
  pCVar3 = (CSimSeqObj *)*param_1;
  pCVar1 = (CSimSeqObj *)param_1[1];
  if (param_4 != 0) {
    if (param_4 <= (ulonglong)(param_1[2] - (longlong)pCVar1 >> 5)) {
      if (param_4 < (ulonglong)((longlong)pCVar1 - (longlong)param_2 >> 5)) {
        pCVar3 = FUN_180005600(pCVar1 + param_4 * -0x20,pCVar1,pCVar1);
        param_1[1] = (longlong)pCVar3;
        FUN_180004d30((longlong)param_2,(longlong)(pCVar1 + param_4 * -0x20),pCVar1);
        for (pCVar3 = param_2; pCVar3 != param_2 + param_4 * 0x20; pCVar3 = pCVar3 + 0x20) {
          (**(code **)(*(longlong *)pCVar3 + 8))(pCVar3,0);
        }
        for (; param_4 != 0; param_4 = param_4 - 1) {
          CSimSeqObj::CSimSeqObj(param_2,param_3);
          param_2 = param_2 + 0x20;
          param_3 = param_3 + 0x20;
        }
      }
      else {
        pCVar3 = FUN_180005600(param_2,pCVar1,param_2 + param_4 * 0x20);
        param_1[1] = (longlong)pCVar3;
        for (pCVar3 = param_2; pCVar3 != pCVar1; pCVar3 = pCVar3 + 0x20) {
          (**(code **)(*(longlong *)pCVar3 + 8))(pCVar3,0);
        }
        for (; param_4 != 0; param_4 = param_4 - 1) {
          CSimSeqObj::CSimSeqObj(param_2,param_3);
          param_2 = param_2 + 0x20;
          param_3 = param_3 + 0x20;
        }
      }
      return;
    }
    lVar4 = (longlong)pCVar1 - (longlong)pCVar3 >> 5;
    local_88 = 0x7ffffffffffffff;
    if (0x7ffffffffffffffU - lVar4 < param_4) {
                    /* WARNING: Subroutine does not return */
      FUN_180005f30();
    }
    uVar6 = param_4 + lVar4;
    uVar5 = param_1[2] - (longlong)pCVar3 >> 5;
    if ((uVar5 <= 0x7ffffffffffffff - (uVar5 >> 1)) &&
       (local_88 = (uVar5 >> 1) + uVar5, local_88 < uVar6)) {
      local_88 = uVar6;
    }
    pCVar2 = FUN_180005f50(param_1,local_88);
    lVar4 = (longlong)param_2 - (longlong)pCVar3 >> 5;
    this = pCVar2 + lVar4 * 0x20;
    for (uVar5 = param_4; uVar5 != 0; uVar5 = uVar5 - 1) {
      CSimSeqObj::CSimSeqObj(this,param_3);
      this = this + 0x20;
      param_3 = param_3 + 0x20;
    }
    if ((param_4 == 1) && (param_2 == pCVar1)) {
      FUN_180005600(pCVar3,pCVar1,pCVar2);
    }
    else {
      FUN_180005600(pCVar3,param_2,pCVar2);
      FUN_180005600(param_2,pCVar1,pCVar2 + (lVar4 + param_4) * 0x20);
    }
    FUN_180005ad0(param_1,(longlong)pCVar2,uVar6,local_88);
  }
  return;
}

/* RVA 0x4b00 */
void FUN_180004b00(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  ulonglong uVar6;
  CSimSeqObj *pCVar7;
  CSimSeqObj local_68 [8];
  undefined8 local_60;
  CSimSeqObj local_48 [32];
  
  uVar6 = param_2 - param_1 >> 5;
  lVar2 = param_2 - param_1 >> 6;
  if (0 < lVar2) {
    lVar5 = (longlong)(uVar6 - 1) >> 1;
    pCVar7 = (CSimSeqObj *)(lVar2 * 0x20 + param_1);
    do {
      lVar2 = lVar2 + -1;
      pCVar7 = pCVar7 + -0x20;
      CSimSeqObj::CSimSeqObj(local_68,pCVar7);
      for (lVar3 = lVar2; lVar3 < lVar5; lVar3 = lVar3 * 2 + ((longlong)iVar1 >> 0x3f) + 2) {
        iVar1 = MDnatsrt(*(undefined8 *)(lVar3 * 0x40 + 0x48 + param_1),
                         *(undefined8 *)(lVar3 * 0x40 + 0x28 + param_1));
        CSimSeqObj::operator=((CSimSeqObj *)(param_1 + lVar3 * 0x20),local_48);
        CSimSeqObj::~CSimSeqObj(local_48);
      }
      if ((lVar3 == lVar5) && ((uVar6 & 1) == 0)) {
        CSimSeqObj::operator=((CSimSeqObj *)(param_1 + lVar3 * 0x20),local_48);
        CSimSeqObj::~CSimSeqObj(local_48);
        lVar3 = uVar6 - 1;
      }
      while (lVar2 < lVar3) {
        lVar4 = lVar3 + -1 >> 1;
        iVar1 = MDnatsrt(*(undefined8 *)(lVar4 * 0x20 + param_1 + 8),local_60);
        if (-1 < iVar1) break;
        CSimSeqObj::operator=((CSimSeqObj *)(param_1 + lVar3 * 0x20),local_48);
        CSimSeqObj::~CSimSeqObj(local_48);
        lVar3 = lVar4;
      }
      CSimSeqObj::operator=((CSimSeqObj *)(param_1 + lVar3 * 0x20),local_48);
      CSimSeqObj::~CSimSeqObj(local_48);
      CSimSeqObj::~CSimSeqObj(local_68);
    } while (0 < lVar2);
  }
  return;
}

/* RVA 0x4cb0 */
void FUN_180004cb0(CSimSeqObj *param_1,CSimSeqObj *param_2,CSimSeqObj *param_3)

{
  int iVar1;
  
  iVar1 = MDnatsrt(*(undefined8 *)(param_2 + 8),*(undefined8 *)(param_1 + 8));
  if (iVar1 < 0) {
    FUN_180005660(param_2,param_1);
  }
  iVar1 = MDnatsrt(*(undefined8 *)(param_3 + 8),*(undefined8 *)(param_2 + 8));
  if (iVar1 < 0) {
    FUN_180005660(param_3,param_2);
    iVar1 = MDnatsrt(*(undefined8 *)(param_2 + 8),*(undefined8 *)(param_1 + 8));
    if (iVar1 < 0) {
      FUN_180005660(param_2,param_1);
    }
  }
  return;
}

/* RVA 0x4d30 */
CSimSeqObj * FUN_180004d30(longlong param_1,longlong param_2,CSimSeqObj *param_3)

{
  CSimSeqObj local_28 [32];
  
  for (; param_2 != param_1; param_2 = param_2 + -0x20) {
    param_3 = param_3 + -0x20;
    CSimSeqObj::operator=(param_3,local_28);
    CSimSeqObj::~CSimSeqObj(local_28);
  }
  return param_3;
}

/* RVA 0x4d90 */
CSimSeqObj * FUN_180004d90(longlong param_1,longlong param_2,CSimSeqObj *param_3)

{
  CSimSeqObj local_28 [32];
  
  for (; param_1 != param_2; param_1 = param_1 + 0x20) {
    CSimSeqObj::operator=(param_3,local_28);
    CSimSeqObj::~CSimSeqObj(local_28);
    param_3 = param_3 + 0x20;
  }
  return param_3;
}

/* RVA 0x4df0 */
void FUN_180004df0(undefined8 *param_1,CSimSeqObj *param_2,CSimSeqObj *param_3)

{
  int iVar1;
  CSimSeqObj *pCVar2;
  CSimSeqObj *this;
  CSimSeqObj *pCVar3;
  CSimSeqObj *this_00;
  longlong lVar4;
  CSimSeqObj *this_01;
  CSimSeqObj *pCVar5;
  CSimSeqObj local_78 [32];
  CSimSeqObj local_58 [32];
  
  pCVar3 = param_2 + ((longlong)param_3 - (longlong)param_2 >> 6) * 0x20;
  pCVar2 = param_3 + -0x20;
  lVar4 = (longlong)pCVar2 - (longlong)param_2 >> 5;
  pCVar5 = pCVar3;
  if (lVar4 < 0x29) {
    FUN_180004cb0(param_2,pCVar3,pCVar2);
  }
  else {
    lVar4 = lVar4 + 1 >> 3;
    FUN_180004cb0(param_2,param_2 + lVar4 * 0x20,param_2 + lVar4 * 0x40);
    FUN_180004cb0(pCVar3 + lVar4 * -0x20,pCVar3,pCVar3 + lVar4 * 0x20);
    FUN_180004cb0(param_3 + -0x20 + lVar4 * -0x40,pCVar2 + lVar4 * -0x20,param_3 + -0x20);
    FUN_180004cb0(param_2 + lVar4 * 0x20,pCVar3,pCVar2 + lVar4 * -0x20);
  }
  while (((param_2 < pCVar5 &&
          (iVar1 = MDnatsrt(*(undefined8 *)(pCVar5 + -0x18),*(undefined8 *)(pCVar5 + 8)), -1 < iVar1
          )) && (iVar1 = MDnatsrt(*(undefined8 *)(pCVar5 + 8),*(undefined8 *)(pCVar5 + -0x18)),
                -1 < iVar1))) {
    pCVar5 = pCVar5 + -0x20;
  }
  do {
    pCVar2 = pCVar3 + 0x20;
    this = pCVar2;
    this_00 = pCVar5;
    if ((param_3 <= pCVar2) ||
       (iVar1 = MDnatsrt(*(undefined8 *)(pCVar3 + 0x28),*(undefined8 *)(pCVar5 + 8)), iVar1 < 0))
    break;
    iVar1 = MDnatsrt(*(undefined8 *)(pCVar5 + 8),*(undefined8 *)(pCVar3 + 0x28));
    pCVar3 = pCVar2;
  } while (-1 < iVar1);
joined_r0x000180004f27:
  do {
    pCVar3 = pCVar5;
    if (param_3 <= pCVar2) {
joined_r0x000180004faf:
      for (; param_2 < pCVar5; pCVar5 = pCVar5 + -0x20) {
        this_01 = pCVar3 + -0x20;
        iVar1 = MDnatsrt(*(undefined8 *)(pCVar3 + -0x18),*(undefined8 *)(this_00 + 8));
        if (-1 < iVar1) {
          iVar1 = MDnatsrt(*(undefined8 *)(this_00 + 8),*(undefined8 *)(pCVar3 + -0x18));
          if (iVar1 < 0) break;
          this_00 = this_00 + -0x20;
          if (this_00 != this_01) {
            CSimSeqObj::CSimSeqObj(local_78,this_00);
            CSimSeqObj::operator=(this_00,local_58);
            CSimSeqObj::~CSimSeqObj(local_58);
            CSimSeqObj::operator=(this_01,local_58);
            CSimSeqObj::~CSimSeqObj(local_58);
            CSimSeqObj::~CSimSeqObj(local_78);
          }
        }
        pCVar3 = this_01;
      }
      if (pCVar5 == param_2) {
        if (pCVar2 == param_3) {
          *param_1 = this_00;
          param_1[1] = this;
          return;
        }
        if (this != pCVar2) {
          CSimSeqObj::CSimSeqObj(local_78,this_00);
          CSimSeqObj::operator=(this_00,local_58);
          CSimSeqObj::~CSimSeqObj(local_58);
          CSimSeqObj::operator=(this,local_58);
          CSimSeqObj::~CSimSeqObj(local_58);
          CSimSeqObj::~CSimSeqObj(local_78);
        }
        CSimSeqObj::CSimSeqObj(local_78,this_00);
        CSimSeqObj::operator=(this_00,local_58);
        CSimSeqObj::~CSimSeqObj(local_58);
        CSimSeqObj::operator=(pCVar2,local_58);
        CSimSeqObj::~CSimSeqObj(local_58);
        CSimSeqObj::~CSimSeqObj(local_78);
        pCVar2 = pCVar2 + 0x20;
        this = this + 0x20;
        this_00 = this_00 + 0x20;
      }
      else {
        pCVar5 = pCVar5 + -0x20;
        if (pCVar2 == param_3) {
          this_00 = this_00 + -0x20;
          if (pCVar5 != this_00) {
            CSimSeqObj::CSimSeqObj(local_78,pCVar5);
            CSimSeqObj::operator=(pCVar5,local_58);
            CSimSeqObj::~CSimSeqObj(local_58);
            CSimSeqObj::operator=(this_00,local_58);
            CSimSeqObj::~CSimSeqObj(local_58);
            CSimSeqObj::~CSimSeqObj(local_78);
          }
          CSimSeqObj::CSimSeqObj(local_78,this_00);
          CSimSeqObj::operator=(this_00,local_58);
          CSimSeqObj::~CSimSeqObj(local_58);
          CSimSeqObj::operator=(this + -0x20,local_58);
          CSimSeqObj::~CSimSeqObj(local_58);
          CSimSeqObj::~CSimSeqObj(local_78);
          this = this + -0x20;
        }
        else {
          CSimSeqObj::CSimSeqObj(local_78,pCVar2);
          CSimSeqObj::operator=(pCVar2,local_58);
          CSimSeqObj::~CSimSeqObj(local_58);
          CSimSeqObj::operator=(pCVar5,local_58);
          CSimSeqObj::~CSimSeqObj(local_58);
          CSimSeqObj::~CSimSeqObj(local_78);
          pCVar2 = pCVar2 + 0x20;
        }
      }
      goto joined_r0x000180004f27;
    }
    iVar1 = MDnatsrt(*(undefined8 *)(this_00 + 8),*(undefined8 *)(pCVar2 + 8));
    if (-1 < iVar1) {
      iVar1 = MDnatsrt(*(undefined8 *)(pCVar2 + 8),*(undefined8 *)(this_00 + 8));
      if (iVar1 < 0) goto joined_r0x000180004faf;
      if (this != pCVar2) {
        CSimSeqObj::CSimSeqObj(local_78,this);
        CSimSeqObj::operator=(this,local_58);
        CSimSeqObj::~CSimSeqObj(local_58);
        CSimSeqObj::operator=(pCVar2,local_58);
        CSimSeqObj::~CSimSeqObj(local_58);
        CSimSeqObj::~CSimSeqObj(local_78);
      }
      this = this + 0x20;
    }
    pCVar2 = pCVar2 + 0x20;
  } while( true );
}

/* RVA 0x5220 */
void FUN_180005220(longlong param_1,longlong param_2,ulonglong param_3,longlong param_4)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  CSimSeqObj local_48 [32];
  
  lVar2 = (longlong)(param_3 - 1) >> 1;
  for (lVar3 = param_2; lVar3 < lVar2; lVar3 = lVar3 * 2 + ((longlong)iVar1 >> 0x3f) + 2) {
    iVar1 = MDnatsrt(*(undefined8 *)(lVar3 * 0x40 + 0x48 + param_1),
                     *(undefined8 *)(lVar3 * 0x40 + 0x28 + param_1));
    CSimSeqObj::operator=((CSimSeqObj *)(param_1 + lVar3 * 0x20),local_48);
    CSimSeqObj::~CSimSeqObj(local_48);
  }
  if ((lVar3 == lVar2) && ((param_3 & 1) == 0)) {
    CSimSeqObj::operator=((CSimSeqObj *)(param_1 + lVar3 * 0x20),local_48);
    CSimSeqObj::~CSimSeqObj(local_48);
    lVar3 = param_3 - 1;
  }
  while (param_2 < lVar3) {
    lVar2 = lVar3 + -1 >> 1;
    iVar1 = MDnatsrt(*(undefined8 *)(lVar2 * 0x20 + param_1 + 8),*(undefined8 *)(param_4 + 8));
    if (-1 < iVar1) break;
    CSimSeqObj::operator=((CSimSeqObj *)(param_1 + lVar3 * 0x20),local_48);
    CSimSeqObj::~CSimSeqObj(local_48);
    lVar3 = lVar2;
  }
  CSimSeqObj::operator=((CSimSeqObj *)(param_1 + lVar3 * 0x20),local_48);
  CSimSeqObj::~CSimSeqObj(local_48);
  return;
}

/* RVA 0x5380 */
void FUN_180005380(CSimSeqObj *param_1,CSimSeqObj *param_2,longlong param_3,undefined1 param_4)

{
  CSimSeqObj *pCVar1;
  CSimSeqObj *this;
  int iVar2;
  ulonglong uVar3;
  CSimSeqObj *pCVar4;
  CSimSeqObj *local_58;
  CSimSeqObj *local_50;
  CSimSeqObj local_38 [32];
  
  uVar3 = (longlong)param_2 - (longlong)param_1;
  while( true ) {
    if ((longlong)(uVar3 & 0xffffffffffffffe0) < 0x401) {
      pCVar4 = param_1;
      if (param_1 != param_2) {
        while (pCVar1 = pCVar4 + 0x20, pCVar1 != param_2) {
          CSimSeqObj::CSimSeqObj((CSimSeqObj *)&local_58,pCVar1);
          iVar2 = MDnatsrt(local_50,*(undefined8 *)(param_1 + 8));
          this = pCVar1;
          if (iVar2 < 0) {
            for (; this != param_1; this = this + -0x20) {
              CSimSeqObj::operator=(this,local_38);
              CSimSeqObj::~CSimSeqObj(local_38);
            }
            pCVar4 = param_1;
          }
          else {
            iVar2 = MDnatsrt(local_50,*(undefined8 *)(pCVar4 + 8));
            pCVar4 = pCVar1;
            while (iVar2 < 0) {
              CSimSeqObj::operator=(pCVar4,local_38);
              CSimSeqObj::~CSimSeqObj(local_38);
              iVar2 = MDnatsrt(local_50,*(undefined8 *)(pCVar4 + -0x38));
              pCVar4 = pCVar4 + -0x20;
            }
          }
          CSimSeqObj::operator=(pCVar4,local_38);
          CSimSeqObj::~CSimSeqObj(local_38);
          CSimSeqObj::~CSimSeqObj((CSimSeqObj *)&local_58);
          pCVar4 = pCVar1;
        }
      }
      return;
    }
    if (param_3 < 1) break;
    FUN_180004df0(&local_58,param_1,param_2);
    pCVar1 = local_50;
    pCVar4 = local_58;
    param_3 = (param_3 >> 1) + (param_3 >> 2);
    if ((longlong)((longlong)local_58 - (longlong)param_1 & 0xffffffffffffffe0U) <
        (longlong)((longlong)param_2 - (longlong)local_50 & 0xffffffffffffffe0U)) {
      FUN_180005380(param_1,local_58,param_3,param_4);
      param_1 = pCVar1;
      pCVar4 = param_2;
    }
    else {
      FUN_180005380(local_50,param_2,param_3,param_4);
    }
    uVar3 = (longlong)pCVar4 - (longlong)param_1;
    param_2 = pCVar4;
  }
  FUN_180004b00((longlong)param_1,(longlong)param_2);
  if ((longlong)((longlong)param_2 - (longlong)param_1 & 0xffffffffffffffe0U) < 0x40) {
    return;
  }
  pCVar4 = param_2 + -0x20;
  do {
    CSimSeqObj::CSimSeqObj((CSimSeqObj *)&local_58,pCVar4);
    CSimSeqObj::operator=(pCVar4,local_38);
    CSimSeqObj::~CSimSeqObj(local_38);
    FUN_180005220((longlong)param_1,0,(longlong)pCVar4 - (longlong)param_1 >> 5,(longlong)&local_58)
    ;
    CSimSeqObj::~CSimSeqObj((CSimSeqObj *)&local_58);
    pCVar4 = pCVar4 + -0x20;
  } while (0x3f < (longlong)((ulonglong)(pCVar4 + (0x20 - (longlong)param_1)) & 0xffffffffffffffe0))
  ;
  return;
}

/* RVA 0x5600 */
CSimSeqObj * FUN_180005600(CSimSeqObj *param_1,CSimSeqObj *param_2,CSimSeqObj *param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 0x20) {
    CSimSeqObj::CSimSeqObj(param_3,param_1);
    param_3 = param_3 + 0x20;
  }
  return param_3;
}

/* RVA 0x5660 */
void FUN_180005660(CSimSeqObj *param_1,CSimSeqObj *param_2)

{
  CSimSeqObj local_48 [32];
  CSimSeqObj local_28 [32];
  
  CSimSeqObj::CSimSeqObj(local_48,param_1);
  CSimSeqObj::operator=(param_1,local_28);
  CSimSeqObj::~CSimSeqObj(local_28);
  CSimSeqObj::operator=(param_2,local_28);
  CSimSeqObj::~CSimSeqObj(local_28);
  CSimSeqObj::~CSimSeqObj(local_48);
  return;
}

/* RVA 0x56d0 */
undefined8 * FUN_1800056d0(undefined8 *param_1,longlong param_2)

{
  *param_1 = std::exception::vftable;
  param_1[1] = 0;
  param_1[2] = 0;
  __std_exception_copy(param_2 + 8);
  *param_1 = std::bad_alloc::vftable;
  return param_1;
}

/* RVA 0x5710 */
undefined8 * FUN_180005710(undefined8 *param_1,longlong param_2)

{
  *param_1 = std::exception::vftable;
  param_1[1] = 0;
  param_1[2] = 0;
  __std_exception_copy(param_2 + 8);
  *param_1 = std::bad_array_new_length::vftable;
  return param_1;
}

/* RVA 0x5750 */
undefined8 * FUN_180005750(undefined8 *param_1)

{
  param_1[2] = 0;
  param_1[1] = "bad array new length";
  *param_1 = std::bad_array_new_length::vftable;
  return param_1;
}

/* RVA 0x5780 */
/* Library Function - Single Match
    public: __cdecl std::exception::exception(class std::exception const & __ptr64) __ptr64
   
   Library: Visual Studio 2019 Release */

exception * __thiscall std::exception::exception(exception *this,exception *param_1)

{
  *(undefined ***)this = vftable;
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)(this + 0x10) = 0;
  __std_exception_copy(param_1 + 8);
  return this;
}

/* RVA 0x57c0 */
void FUN_1800057c0(undefined8 *param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  
  plVar1 = (longlong *)param_1[1];
  for (plVar2 = (longlong *)*param_1; plVar2 != plVar1; plVar2 = plVar2 + 4) {
    (**(code **)(*plVar2 + 8))(plVar2,0);
  }
  return;
}

/* RVA 0x5800 */
void FUN_180005800(longlong *param_1)

{
  void *pvVar1;
  void *pvVar2;
  
  if (0xf < (ulonglong)param_1[7]) {
    pvVar1 = (void *)param_1[4];
    pvVar2 = pvVar1;
    if ((0xfff < param_1[7] + 1U) &&
       (pvVar2 = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar2)))) goto LAB_1800058a3;
    FUN_180001300(pvVar2);
  }
  param_1[6] = 0;
  param_1[7] = 0xf;
  *(undefined1 *)(param_1 + 4) = 0;
  if (0xf < (ulonglong)param_1[3]) {
    pvVar1 = (void *)*param_1;
    pvVar2 = pvVar1;
    if ((0xfff < param_1[3] + 1U) &&
       (pvVar2 = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar2)))) {
LAB_1800058a3:
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180001300(pvVar2);
  }
  param_1[2] = 0;
  param_1[3] = 0xf;
  *(undefined1 *)param_1 = 0;
  return;
}

/* RVA 0x58b0 */
void FUN_1800058b0(longlong *param_1)

{
  longlong *plVar1;
  void *pvVar2;
  void *pvVar3;
  longlong *plVar4;
  
  plVar4 = (longlong *)*param_1;
  if (plVar4 != (longlong *)0x0) {
    plVar1 = (longlong *)param_1[1];
    for (; plVar4 != plVar1; plVar4 = plVar4 + 4) {
      (**(code **)(*plVar4 + 8))(plVar4,0);
    }
    pvVar2 = (void *)*param_1;
    pvVar3 = pvVar2;
    if ((0xfff < (param_1[2] - (longlong)pvVar2 & 0xffffffffffffffe0U)) &&
       (pvVar3 = *(void **)((longlong)pvVar2 + -8),
       0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)pvVar3)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180001300(pvVar3);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
  }
  return;
}

/* RVA 0x5960 */
/* public: bool __cdecl CSimSeqObj::operator<(class CSimSeqObj const & __ptr64) __ptr64 */

bool __thiscall CSimSeqObj::operator<(CSimSeqObj *this,CSimSeqObj *param_1)

{
  byte extraout_var;
  
                    /* 0x5960  17  ??MCSimSeqObj@@QEAA_NAEBV0@@Z */
  MDnatsrt(*(undefined8 *)(this + 8),*(undefined8 *)(param_1 + 8));
  return (bool)(extraout_var >> 7);
}

/* RVA 0x5980 */
undefined8 * FUN_180005980(undefined8 *param_1,uint param_2)

{
  *param_1 = CSimSeqTree::vftable;
  FUN_1800058b0(param_1 + 1);
  if ((param_2 & 1) != 0) {
    if ((param_2 & 4) == 0) {
      operator_delete(param_1);
      return param_1;
    }
    thunk_FUN_180001300(param_1);
  }
  return param_1;
}

/* RVA 0x59e0 */
undefined8 * FUN_1800059e0(undefined8 *param_1,ulonglong param_2)

{
  *param_1 = std::exception::vftable;
  __std_exception_destroy(param_1 + 1);
  if ((param_2 & 1) != 0) {
    FUN_180001300(param_1);
  }
  return param_1;
}

/* RVA 0x5a30 */
undefined1 FUN_180005a30(longlong param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  longlong lVar5;
  longlong lVar6;
  
  uVar3 = 0;
  uVar4 = 0;
  iVar2 = (int)(*(longlong *)(param_1 + 0x10) - *(longlong *)(param_1 + 8) >> 5);
  lVar5 = (longlong)iVar2;
  if (0 < iVar2) {
    lVar6 = 0;
    do {
      lVar1 = *(longlong *)(param_1 + 8);
      iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                         (lVar1 + 8 + lVar6),*(char **)(param_2 + 8));
      if (iVar2 == 0) {
        uVar4 = uVar3;
        if (*(int *)(lVar1 + 0x10 + lVar6) == *(int *)(param_2 + 0x10)) {
          uVar4 = 1;
          uVar3 = 1;
        }
      }
      lVar6 = lVar6 + 0x20;
      lVar5 = lVar5 + -1;
    } while (lVar5 != 0);
  }
  return uVar4;
}

/* RVA 0x5ad0 */
void FUN_180005ad0(longlong *param_1,longlong param_2,longlong param_3,longlong param_4)

{
  longlong *plVar1;
  void *pvVar2;
  void *pvVar3;
  longlong *plVar4;
  
  plVar4 = (longlong *)*param_1;
  if (plVar4 != (longlong *)0x0) {
    plVar1 = (longlong *)param_1[1];
    for (; plVar4 != plVar1; plVar4 = plVar4 + 4) {
      (**(code **)(*plVar4 + 8))(plVar4,0);
    }
    pvVar2 = (void *)*param_1;
    pvVar3 = pvVar2;
    if ((0xfff < (param_1[2] - (longlong)pvVar2 & 0xffffffffffffffe0U)) &&
       (pvVar3 = *(void **)((longlong)pvVar2 + -8),
       0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)pvVar3)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    FUN_180001300(pvVar3);
  }
  *param_1 = param_2;
  param_1[1] = param_3 * 0x20 + param_2;
  param_1[2] = param_4 * 0x20 + param_2;
  return;
}

/* RVA 0x5b90 */
longlong * FUN_180005b90(longlong *param_1,longlong *param_2,longlong *param_3)

{
  char cVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  longlong *plVar6;
  longlong *plVar7;
  longlong *plVar8;
  
  param_1[1] = param_1[1] + 1;
  plVar2 = (longlong *)*param_1;
  plVar6 = (longlong *)*param_2;
  param_3[1] = (longlong)plVar6;
  if (plVar6 == plVar2) {
    *plVar2 = (longlong)param_3;
    plVar2[1] = (longlong)param_3;
    plVar2[2] = (longlong)param_3;
    *(undefined1 *)(param_3 + 3) = 1;
    return param_3;
  }
  if ((int)param_2[1] == 0) {
    plVar6[2] = (longlong)param_3;
    if (plVar6 == (longlong *)plVar2[2]) {
      plVar2[2] = (longlong)param_3;
    }
  }
  else {
    *plVar6 = (longlong)param_3;
    if (plVar6 == (longlong *)*plVar2) {
      *plVar2 = (longlong)param_3;
    }
  }
  cVar1 = *(char *)(param_3[1] + 0x18);
  plVar6 = param_3;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(plVar2[1] + 0x18) = 1;
      return param_3;
    }
    plVar7 = (longlong *)plVar6[1];
    lVar3 = *(longlong *)plVar7[1];
    if (plVar7 == (longlong *)lVar3) {
      lVar3 = ((longlong *)plVar7[1])[2];
      if (*(char *)(lVar3 + 0x18) == '\0') {
        *(undefined1 *)(plVar7 + 3) = 1;
        *(undefined1 *)(lVar3 + 0x18) = 1;
        *(undefined1 *)(*(longlong *)(plVar6[1] + 8) + 0x18) = 0;
        plVar6 = *(longlong **)(plVar6[1] + 8);
      }
      else {
        plVar8 = (longlong *)plVar7[2];
        if (plVar6 == plVar8) {
          plVar7[2] = *plVar8;
          if (*(char *)(*plVar8 + 0x19) == '\0') {
            *(longlong **)(*plVar8 + 8) = plVar7;
          }
          plVar8[1] = plVar7[1];
          if (plVar7 == (longlong *)*(longlong *)(*param_1 + 8)) {
            *(longlong **)(*param_1 + 8) = plVar8;
          }
          else {
            plVar6 = (longlong *)plVar7[1];
            if (plVar7 == (longlong *)*plVar6) {
              *plVar6 = (longlong)plVar8;
            }
            else {
              plVar6[2] = (longlong)plVar8;
            }
          }
          *plVar8 = (longlong)plVar7;
          plVar7[1] = (longlong)plVar8;
          plVar6 = plVar7;
        }
        *(undefined1 *)(plVar6[1] + 0x18) = 1;
        *(undefined1 *)(*(longlong *)(plVar6[1] + 8) + 0x18) = 0;
        plVar7 = *(longlong **)(plVar6[1] + 8);
        plVar8 = (longlong *)*plVar7;
        *plVar7 = plVar8[2];
        if (*(char *)(plVar8[2] + 0x19) == '\0') {
          *(longlong **)(plVar8[2] + 8) = plVar7;
        }
        plVar8[1] = plVar7[1];
        if (plVar7 == *(longlong **)(*param_1 + 8)) {
          *(longlong **)(*param_1 + 8) = plVar8;
          plVar8[2] = (longlong)plVar7;
        }
        else {
          plVar4 = (longlong *)plVar7[1];
          if (plVar7 == (longlong *)plVar4[2]) {
            plVar4[2] = (longlong)plVar8;
            plVar8[2] = (longlong)plVar7;
          }
          else {
            *plVar4 = (longlong)plVar8;
            plVar8[2] = (longlong)plVar7;
          }
        }
LAB_180005dcd:
        plVar7[1] = (longlong)plVar8;
      }
    }
    else {
      if (*(char *)(lVar3 + 0x18) != '\0') {
        plVar8 = (longlong *)*plVar7;
        if (plVar6 == plVar8) {
          *plVar7 = plVar8[2];
          if (*(char *)(plVar8[2] + 0x19) == '\0') {
            *(longlong **)(plVar8[2] + 8) = plVar7;
          }
          plVar8[1] = plVar7[1];
          if (plVar7 == *(longlong **)(*param_1 + 8)) {
            *(longlong **)(*param_1 + 8) = plVar8;
          }
          else {
            puVar5 = (undefined8 *)plVar7[1];
            if (plVar7 == (longlong *)puVar5[2]) {
              puVar5[2] = plVar8;
            }
            else {
              *puVar5 = plVar8;
            }
          }
          plVar8[2] = (longlong)plVar7;
          plVar7[1] = (longlong)plVar8;
          plVar6 = plVar7;
        }
        *(undefined1 *)(plVar6[1] + 0x18) = 1;
        *(undefined1 *)(*(longlong *)(plVar6[1] + 8) + 0x18) = 0;
        plVar7 = *(longlong **)(plVar6[1] + 8);
        plVar8 = (longlong *)plVar7[2];
        plVar7[2] = *plVar8;
        if (*(char *)(*plVar8 + 0x19) == '\0') {
          *(longlong **)(*plVar8 + 8) = plVar7;
        }
        plVar8[1] = plVar7[1];
        if (plVar7 == *(longlong **)(*param_1 + 8)) {
          *(longlong **)(*param_1 + 8) = plVar8;
        }
        else {
          puVar5 = (undefined8 *)plVar7[1];
          if (plVar7 == (longlong *)*puVar5) {
            *puVar5 = plVar8;
          }
          else {
            puVar5[2] = plVar8;
          }
        }
        *plVar8 = (longlong)plVar7;
        goto LAB_180005dcd;
      }
      *(undefined1 *)(plVar7 + 3) = 1;
      *(undefined1 *)(lVar3 + 0x18) = 1;
      *(undefined1 *)(*(longlong *)(plVar6[1] + 8) + 0x18) = 0;
      plVar6 = *(longlong **)(plVar6[1] + 8);
    }
    cVar1 = *(char *)(plVar6[1] + 0x18);
  } while( true );
}

/* RVA 0x5df0 */
void FUN_180005df0(longlong *param_1,ulonglong param_2)

{
  longlong lVar1;
  longlong lVar2;
  CSimSeqObj *pCVar3;
  CSimSeqObj *pCVar4;
  __uint64 _Var5;
  CSimSeqObj *this;
  CSimSeqObj *pCVar6;
  
  lVar1 = param_1[1];
  lVar2 = *param_1;
  if (0x7ffffffffffffff < param_2) {
                    /* WARNING: Subroutine does not return */
    FUN_180005ed0();
  }
  _Var5 = param_2 << 5;
  if (_Var5 < 0x1000) {
    if (_Var5 == 0) {
      pCVar4 = (CSimSeqObj *)0x0;
    }
    else {
      pCVar4 = operator_new(_Var5);
    }
  }
  else {
    pCVar4 = (CSimSeqObj *)FUN_1800044b0(_Var5);
  }
  pCVar3 = (CSimSeqObj *)param_1[1];
  this = pCVar4;
  for (pCVar6 = (CSimSeqObj *)*param_1; pCVar6 != pCVar3; pCVar6 = pCVar6 + 0x20) {
    CSimSeqObj::CSimSeqObj(this,pCVar6);
    this = this + 0x20;
  }
  FUN_180005ad0(param_1,(longlong)pCVar4,lVar1 - lVar2 >> 5,param_2);
  return;
}

/* RVA 0x5ed0 */
void FUN_180005ed0(void)

{
  undefined8 local_28 [5];
  
  FUN_180005750(local_28);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_28,(ThrowInfo *)&DAT_1800486c8);
}

/* RVA 0x5ef0 */
void FUN_180005ef0(void)

{
                    /* WARNING: Subroutine does not return */
  std::_Xlength_error("map/set too long");
}

/* RVA 0x5f10 */
void FUN_180005f10(void)

{
                    /* WARNING: Subroutine does not return */
  std::_Xlength_error("string too long");
}

/* RVA 0x5f30 */
void FUN_180005f30(void)

{
                    /* WARNING: Subroutine does not return */
  std::_Xlength_error("vector too long");
}

/* RVA 0x5f50 */
void * FUN_180005f50(undefined8 param_1,ulonglong param_2)

{
  void *pvVar1;
  ulonglong uVar2;
  
  if (0x7ffffffffffffff < param_2) {
                    /* WARNING: Subroutine does not return */
    FUN_180005ed0();
  }
  uVar2 = param_2 << 5;
  if (0xfff < uVar2) {
    pvVar1 = (void *)FUN_1800044b0(uVar2);
    return pvVar1;
  }
  if (uVar2 == 0) {
    return (void *)0x0;
  }
  pvVar1 = operator_new(uVar2);
  return pvVar1;
}

/* RVA 0x5fa0 */
longlong * FUN_180005fa0(longlong *param_1,void *param_2,size_t param_3)

{
  __uint64 _Var1;
  ulonglong uVar2;
  ulonglong uVar3;
  void *pvVar4;
  void *_Dst;
  ulonglong uVar5;
  void *pvVar6;
  longlong *_Dst_00;
  ulonglong uVar7;
  
  uVar3 = param_1[3];
  if (uVar3 < param_3) {
    uVar7 = 0x7fffffffffffffff;
    if (0x7fffffffffffffff < param_3) {
                    /* WARNING: Subroutine does not return */
      FUN_180005f10();
    }
    uVar5 = param_3 | 0xf;
    if (uVar5 < 0x8000000000000000) {
      if (0x7fffffffffffffff - (uVar3 >> 1) < uVar3) {
        _Dst = (void *)FUN_1800044b0(0x8000000000000000);
      }
      else {
        uVar2 = (uVar3 >> 1) + uVar3;
        uVar7 = uVar5;
        if (uVar5 < uVar2) {
          uVar7 = uVar2;
        }
        _Var1 = uVar7 + 1;
        if (_Var1 < 0x1000) {
          if (_Var1 == 0) {
            _Dst = (void *)0x0;
          }
          else {
            _Dst = operator_new(_Var1);
          }
        }
        else {
          _Dst = (void *)FUN_1800044b0(_Var1);
        }
      }
    }
    else {
      _Dst = (void *)FUN_1800044b0(0x8000000000000000);
    }
    param_1[2] = param_3;
    param_1[3] = uVar7;
    memcpy(_Dst,param_2,param_3);
    *(undefined1 *)((longlong)_Dst + param_3) = 0;
    if (0xf < uVar3) {
      pvVar4 = (void *)*param_1;
      pvVar6 = pvVar4;
      if ((0xfff < uVar3 + 1) &&
         (pvVar6 = *(void **)((longlong)pvVar4 + -8),
         0x1f < (ulonglong)((longlong)pvVar4 + (-8 - (longlong)pvVar6)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      FUN_180001300(pvVar6);
    }
    *param_1 = (longlong)_Dst;
  }
  else {
    _Dst_00 = param_1;
    if (0xf < uVar3) {
      _Dst_00 = (longlong *)*param_1;
    }
    param_1[2] = param_3;
    memmove(_Dst_00,param_2,param_3);
    *(undefined1 *)((longlong)_Dst_00 + param_3) = 0;
  }
  return param_1;
}

