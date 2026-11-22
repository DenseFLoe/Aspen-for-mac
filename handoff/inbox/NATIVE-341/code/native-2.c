/* ---- FUNC 00018A20 FUN_180018a20 (60 bytes) ---- */

undefined8 * FUN_180018a20(undefined8 *param_1,longlong param_2)

{
  *param_1 = std::exception::vftable;
  param_1[1] = 0;
  param_1[2] = 0;
  __std_exception_copy(param_2 + 8);
  *param_1 = std::bad_cast::vftable;
  return param_1;
}

/* ---- FUNC 00018A60 FUN_180018a60 (33 bytes) ---- */

undefined8 * FUN_180018a60(undefined8 *param_1)

{
  param_1[2] = 0;
  param_1[1] = "bad cast";
  *param_1 = std::bad_cast::vftable;
  return param_1;
}

/* ---- FUNC 00018AF0 FUN_180018af0 (57 bytes) ---- */

void FUN_180018af0(undefined8 *param_1)

{
  longlong *plVar1;
  
  plVar1 = (longlong *)param_1[1];
  if (plVar1 != (longlong *)0x0) {
    FUN_180017cc0(plVar1,*param_1,*(longlong **)(*plVar1 + 8));
    operator_delete((void *)*plVar1);
    return;
  }
  return;
}

/* ---- FUNC 00018B30 FUN_180018b30 (99 bytes) ---- */

void FUN_180018b30(basic_streambuf<char,std::char_traits<char>_> *param_1)

{
  basic_streambuf<char,std::char_traits<char>_> *pbVar1;
  
  *(undefined ***)param_1 = std::basic_filebuf<char,std::char_traits<char>_>::vftable;
  if (*(longlong *)(param_1 + 0x80) != 0) {
    pbVar1 = (basic_streambuf<char,std::char_traits<char>_> *)
             std::basic_streambuf<char,std::char_traits<char>_>::eback(param_1);
    if (pbVar1 == param_1 + 0x70) {
      std::basic_streambuf<char,std::char_traits<char>_>::setg
                (param_1,*(char **)(param_1 + 0x88),*(char **)(param_1 + 0x88),
                 *(char **)(param_1 + 0x90));
    }
  }
  if (param_1[0x7c] != (basic_streambuf<char,std::char_traits<char>_>)0x0) {
    FUN_18001b0d0(param_1);
  }
                    /* WARNING: Could not recover jumptable at 0x000180018b8c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<char,std::char_traits<char>_>::~basic_streambuf<char,std::char_traits<char>_>
            (param_1);
  return;
}

/* ---- FUNC 00018BC0 FUN_180018bc0 (50 bytes) ---- */

void FUN_180018bc0(undefined8 *param_1)

{
  *param_1 = CBufferStream::vftable;
  if ((void *)param_1[0x23] != (void *)0x0) {
    free((void *)param_1[0x23]);
  }
  FUN_180018c20(param_1);
  return;
}

/* ---- FUNC 00018C10 FUN_180018c10 (11 bytes) ---- */

void FUN_180018c10(undefined8 *param_1)

{
  *param_1 = CGenStream::vftable;
  return;
}

/* ---- FUNC 00018C20 FUN_180018c20 (11 bytes) ---- */

void FUN_180018c20(undefined8 *param_1)

{
  *param_1 = CTextBufferStream::vftable;
  return;
}

/* ---- FUNC 00018C30 FUN_180018c30 (43 bytes) ---- */

void FUN_180018c30(longlong *param_1)

{
  basic_streambuf<char,std::char_traits<char>_> *pbVar1;
  
  pbVar1 = std::basic_ios<char,std::char_traits<char>_>::rdbuf
                     ((basic_ios<char,std::char_traits<char>_> *)
                      ((longlong)*(int *)(*(longlong *)*param_1 + 4) + *param_1));
  if (pbVar1 != (basic_streambuf<char,std::char_traits<char>_> *)0x0) {
    (**(code **)(*(longlong *)pbVar1 + 0x10))(pbVar1);
  }
  return;
}

/* ---- FUNC 00018C70 FUN_180018c70 (47 bytes) ---- */

void FUN_180018c70(longlong param_1)

{
  undefined8 *puVar1;
  
  if (*(longlong **)(param_1 + 8) != (longlong *)0x0) {
    puVar1 = (undefined8 *)(**(code **)(**(longlong **)(param_1 + 8) + 0x10))();
    if (puVar1 != (undefined8 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000180018c97. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)*puVar1)(puVar1,1);
      return;
    }
  }
  return;
}

/* ---- FUNC 00018CA0 FUN_180018ca0 (43 bytes) ---- */

void FUN_180018ca0(longlong *param_1)

{
  basic_streambuf<char,std::char_traits<char>_> *pbVar1;
  
  pbVar1 = std::basic_ios<char,std::char_traits<char>_>::rdbuf
                     ((basic_ios<char,std::char_traits<char>_> *)
                      ((longlong)*(int *)(*(longlong *)*param_1 + 4) + *param_1));
  if (pbVar1 != (basic_streambuf<char,std::char_traits<char>_> *)0x0) {
    (**(code **)(*(longlong *)pbVar1 + 0x10))(pbVar1);
  }
  return;
}

/* ---- FUNC 00018CD0 FUN_180018cd0 (112 bytes) ---- */

CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
FUN_180018cd0(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_1,
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

/* ---- FUNC 00018D50 FUN_180018d50 (97 bytes) ---- */

void FUN_180018d50(longlong *param_1)

{
  basic_ios<char,std::char_traits<char>_> *this;
  
  this = (basic_ios<char,std::char_traits<char>_> *)(param_1 + 0x16);
  *(undefined ***)(this + (longlong)*(int *)(*param_1 + 4) + -0xb0) =
       std::basic_ifstream<char,std::char_traits<char>_>::vftable;
  *(int *)(this + (longlong)*(int *)(*param_1 + 4) + -0xb4) = *(int *)(*param_1 + 4) + -0xb0;
  FUN_180018b30((basic_streambuf<char,std::char_traits<char>_> *)(param_1 + 2));
  std::basic_istream<char,std::char_traits<char>_>::~basic_istream<char,std::char_traits<char>_>
            ((basic_istream<char,std::char_traits<char>_> *)(param_1 + 3));
                    /* WARNING: Could not recover jumptable at 0x000180018daa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ios<char,std::char_traits<char>_>::~basic_ios<char,std::char_traits<char>_>(this);
  return;
}

/* ---- FUNC 00018DB4 FUN_180018db4 (12 bytes) ---- */

void FUN_180018db4(longlong param_1,uint param_2)

{
  FUN_180018e00(param_1 - *(int *)(param_1 + -4),param_2);
  return;
}

/* ---- FUNC 00018DC0 FUN_180018dc0 (52 bytes) ---- */

basic_streambuf<char,std::char_traits<char>_> *
FUN_180018dc0(basic_streambuf<char,std::char_traits<char>_> *param_1,uint param_2)

{
  FUN_180018b30(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

/* ---- FUNC 00018E00 FUN_180018e00 (59 bytes) ---- */

longlong * FUN_180018e00(longlong param_1,uint param_2)

{
  longlong *plVar1;
  
  plVar1 = (longlong *)(param_1 + -0xb0);
  FUN_180018d50(plVar1);
  if ((param_2 & 1) != 0) {
    operator_delete(plVar1);
  }
  return plVar1;
}

/* ---- FUNC 00018E40 FUN_180018e40 (24 bytes) ---- */

void FUN_180018e40(long param_1)

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

/* ---- FUNC 00018E60 FUN_180018e60 (29 bytes) ---- */

void FUN_180018e60(void)

{
  DWORD DVar1;
  
  DVar1 = GetLastError();
  if (0 < (int)DVar1) {
    DVar1 = DVar1 & 0xffff | 0x80070000;
  }
                    /* WARNING: Subroutine does not return */
  FUN_180018e40(DVar1);
}

/* ---- FUNC 00018E80 FUN_180018e80 (6 bytes) ---- */

undefined8 FUN_180018e80(void)

{
  return 0x80004001;
}

/* ---- FUNC 00018E90 FUN_180018e90 (579 bytes) ---- */

undefined8 FUN_180018e90(longlong param_1)

{
  int iVar1;
  char *pcVar2;
  size_t sVar3;
  size_t sVar4;
  uint uVar5;
  
  switch(*(undefined4 *)(param_1 + 0x100)) {
  case 0:
    break;
  case 1:
    iVar1 = 3 - (uint)(*(longlong *)(param_1 + 0x108) != 0);
    goto LAB_1800190ab;
  case 2:
    goto switchD_180018ec8_caseD_2;
  case 3:
    goto switchD_180018ec8_caseD_3;
  case 4:
    iVar1 = 6 - (uint)(*(longlong *)(param_1 + 0x108) != 0);
LAB_1800190ab:
    *(int *)(param_1 + 0x100) = iVar1;
    goto switchD_180018ec8_default;
  case 5:
    goto switchD_180018ec8_caseD_5;
  case 6:
    goto switchD_180018ec8_caseD_6;
  default:
    goto switchD_180018ec8_default;
  }
  uVar5 = *(int *)(param_1 + 0x124) - *(uint *)(param_1 + 0x120);
  sVar4 = (size_t)uVar5;
  *(undefined8 *)(param_1 + 0x108) = 0;
  if ((0 < (int)uVar5) &&
     ((sVar3 = strcspn((char *)((ulonglong)*(uint *)(param_1 + 0x120) +
                               *(longlong *)(param_1 + 0x118)),"\n"),
      (ulonglong)(longlong)(int)uVar5 < sVar3 ||
      (sVar4 = strcspn((char *)((ulonglong)*(uint *)(param_1 + 0x120) +
                               *(longlong *)(param_1 + 0x118)),"\n"), 0 < (int)sVar4)))) {
    memcpy((void *)(param_1 + 0xc),
           (void *)((ulonglong)*(uint *)(param_1 + 0x120) + *(longlong *)(param_1 + 0x118)),
           sVar4 & 0xffffffff);
    *(undefined1 *)((sVar4 & 0xffffffff) + 0xc + param_1) = 0;
    pcVar2 = strstr((char *)(param_1 + 0xc),"PFSVData");
    if (pcVar2 != (char *)0x0) {
      *(int *)(param_1 + 0x120) = *(int *)(param_1 + 0x120) + (int)sVar4 + 1;
      goto switchD_180018ec8_default;
    }
  }
switchD_180018ec8_caseD_2:
  iVar1 = (**(code **)(param_1 + 0xf8))(param_1 + 0xc,param_1 + 0x108,1);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x100) = 3;
switchD_180018ec8_caseD_3:
    *(undefined8 *)(param_1 + 0x108) = 0;
switchD_180018ec8_caseD_5:
    iVar1 = (**(code **)(param_1 + 0xf8))(param_1 + 0xc,param_1 + 0x108,2);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x100) = 6;
switchD_180018ec8_caseD_6:
      uVar5 = *(int *)(param_1 + 0x124) - *(uint *)(param_1 + 0x120);
      sVar4 = (size_t)uVar5;
      if ((int)uVar5 < 1) {
LAB_180019057:
        if ((int)uVar5 < 0) {
          return 0x80004005;
        }
      }
      else {
        sVar3 = strcspn((char *)((ulonglong)*(uint *)(param_1 + 0x120) +
                                *(longlong *)(param_1 + 0x118)),"\n");
        if (sVar3 <= (ulonglong)(longlong)(int)uVar5) {
          sVar4 = strcspn((char *)((ulonglong)*(uint *)(param_1 + 0x120) +
                                  *(longlong *)(param_1 + 0x118)),"\n");
          uVar5 = (uint)sVar4;
          goto LAB_180019057;
        }
      }
      memcpy((void *)(param_1 + 0xc),
             (void *)((ulonglong)*(uint *)(param_1 + 0x120) + *(longlong *)(param_1 + 0x118)),
             sVar4 & 0xffffffff);
      *(undefined1 *)((sVar4 & 0xffffffff) + 0xc + param_1) = 0;
      *(int *)(param_1 + 0x120) = *(int *)(param_1 + 0x120) + (int)sVar4 + 1;
    }
    else if (*(int *)(param_1 + 0x100) == 3) {
      pcVar2 = "$REPLACESTREAM";
      *(undefined4 *)(param_1 + 0x100) = 4;
      goto LAB_1800190b5;
    }
  }
  else if (*(int *)(param_1 + 0x100) == 0) {
    pcVar2 = "$REPLACEBLOCK";
    *(undefined4 *)(param_1 + 0x100) = 1;
    goto LAB_1800190b5;
  }
switchD_180018ec8_default:
  pcVar2 = (char *)(param_1 + 0xc);
LAB_1800190b5:
  *(char **)(param_1 + 0xf0) = pcVar2;
  return 0;
}

/* ---- FUNC 000190F0 FUN_1800190f0 (357 bytes) ---- */

undefined8 FUN_1800190f0(longlong param_1)

{
  int iVar1;
  char *pcVar2;
  longlong lVar3;
  undefined8 uVar4;
  
  iVar1 = *(int *)(param_1 + 0x100);
  switch(iVar1) {
  case 0:
    *(undefined8 *)(param_1 + 0x108) = 0;
LAB_18001913f:
    iVar1 = (**(code **)(param_1 + 0xf8))(param_1 + 0xc,param_1 + 0x108,1);
    if (iVar1 == 0) goto LAB_180019175;
    if (*(int *)(param_1 + 0x100) == 0) {
      pcVar2 = "$REPLACEBLOCK";
      *(undefined4 *)(param_1 + 0x100) = 1;
      goto LAB_180019241;
    }
    break;
  case 1:
    iVar1 = 3 - (uint)(*(longlong *)(param_1 + 0x108) != 0);
    goto LAB_180019237;
  case 2:
    if (*(longlong *)(param_1 + 0x108) != 0) goto LAB_18001913f;
LAB_180019175:
    iVar1 = 3;
    *(undefined4 *)(param_1 + 0x100) = 3;
  case 3:
    *(undefined8 *)(param_1 + 0x108) = 0;
switchD_180019121_caseD_5:
    if (((iVar1 != 3) && (*(longlong *)(param_1 + 0x108) == 0)) ||
       (iVar1 = (**(code **)(param_1 + 0xf8))(param_1 + 0xc,(longlong *)(param_1 + 0x108),2),
       iVar1 == 0)) {
      *(undefined4 *)(param_1 + 0x100) = 6;
switchD_180019121_caseD_6:
      if (*(code **)(param_1 + 0xe0) == (code *)0x0) {
        return 0x80004005;
      }
      *(longlong *)(param_1 + 0xf0) = param_1 + 0xc;
      lVar3 = (**(code **)(param_1 + 0xe0))();
      uVar4 = 0x80004005;
      if (lVar3 != 0) {
        uVar4 = 0;
      }
      return uVar4;
    }
    if (*(int *)(param_1 + 0x100) == 3) {
      pcVar2 = "$REPLACESTREAM";
      *(undefined4 *)(param_1 + 0x100) = 4;
      goto LAB_180019241;
    }
    break;
  case 4:
    iVar1 = 6 - (uint)(*(longlong *)(param_1 + 0x108) != 0);
LAB_180019237:
    *(int *)(param_1 + 0x100) = iVar1;
    break;
  case 5:
    goto switchD_180019121_caseD_5;
  case 6:
    goto switchD_180019121_caseD_6;
  }
  pcVar2 = (char *)(param_1 + 0xc);
LAB_180019241:
  *(char **)(param_1 + 0xf0) = pcVar2;
  return 0;
}

/* ---- FUNC 00019280 FUN_180019280 (374 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_180019280(undefined8 *param_1,undefined8 param_2)

{
  uint uVar1;
  ulonglong uVar2;
  undefined1 auStack_458 [32];
  longlong *local_438;
  longlong *local_430;
  longlong *local_428;
  longlong *local_420 [3];
  undefined1 local_408 [1008];
  ulonglong local_18;
  
  local_18 = DAT_1800791f8 ^ (ulonglong)auStack_458;
  if (param_1 == (undefined8 *)0x0) {
    FUN_180007de0(local_408,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\bkputil.cpp",0x40a);
    LogMessage(local_408,2,1);
  }
  local_428 = (longlong *)0x0;
  uVar2 = (**(code **)*param_1)(param_1,&DAT_180057ae8,&local_428);
  if (-1 < (int)uVar2) {
    local_430 = (longlong *)0x0;
    uVar1 = (**(code **)(*local_428 + 0x20))(local_428,&DAT_180057aa8,&local_430);
    if (-1 < (int)uVar1) {
      local_438 = (longlong *)0x0;
      uVar1 = (**(code **)(*local_430 + 0x38))(local_430,&local_438);
      if (-1 < (int)uVar1) {
        uVar1 = (**(code **)(*local_438 + 0x18))(local_438,1,local_420);
        while (-1 < (int)uVar1) {
          uVar1 = (**(code **)*local_420[0])(local_420[0],&DAT_180057aa8,param_2);
          (**(code **)(*local_420[0] + 0x10))();
          if (-1 < (int)uVar1) break;
          uVar1 = (**(code **)(*local_438 + 0x18))(local_438,1,local_420);
        }
        (**(code **)(*local_438 + 0x10))();
      }
      (**(code **)(*local_430 + 0x10))();
    }
    uVar2 = (ulonglong)uVar1;
    (**(code **)(*local_428 + 0x10))();
  }
  return uVar2;
}

/* ---- FUNC 00019400 FUN_180019400 (135 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_180019400(void)

{
  undefined1 auStack_d8 [32];
  _OSVERSIONINFOA local_b8;
  undefined8 local_24;
  ulonglong local_18;
  
  local_18 = DAT_1800791f8 ^ (ulonglong)auStack_d8;
  local_b8.dwMajorVersion = 0;
  local_b8.dwMinorVersion = 0;
  local_b8.dwBuildNumber = 0;
  local_b8.dwPlatformId = 0;
  local_b8.szCSDVersion[0] = '\0';
  local_b8.szCSDVersion[1] = '\0';
  local_b8.szCSDVersion[2] = '\0';
  local_b8.szCSDVersion[3] = '\0';
  local_b8.szCSDVersion[4] = '\0';
  local_b8.szCSDVersion[5] = '\0';
  local_b8.szCSDVersion[6] = '\0';
  local_b8.szCSDVersion[7] = '\0';
  local_b8.szCSDVersion[8] = '\0';
  local_b8.szCSDVersion[9] = '\0';
  local_b8.szCSDVersion[10] = '\0';
  local_b8.szCSDVersion[0xb] = '\0';
  local_b8.szCSDVersion[0xc] = '\0';
  local_b8.szCSDVersion[0xd] = '\0';
  local_b8.szCSDVersion[0xe] = '\0';
  local_b8.szCSDVersion[0xf] = '\0';
  local_b8.szCSDVersion[0x10] = '\0';
  local_b8.szCSDVersion[0x11] = '\0';
  local_b8.szCSDVersion[0x12] = '\0';
  local_b8.szCSDVersion[0x13] = '\0';
  local_b8.szCSDVersion[0x14] = '\0';
  local_b8.szCSDVersion[0x15] = '\0';
  local_b8.szCSDVersion[0x16] = '\0';
  local_b8.szCSDVersion[0x17] = '\0';
  local_b8.szCSDVersion[0x18] = '\0';
  local_b8.szCSDVersion[0x19] = '\0';
  local_b8.szCSDVersion[0x1a] = '\0';
  local_b8.szCSDVersion[0x1b] = '\0';
  local_b8.szCSDVersion[0x1c] = '\0';
  local_b8.szCSDVersion[0x1d] = '\0';
  local_b8.szCSDVersion[0x1e] = '\0';
  local_b8.szCSDVersion[0x1f] = '\0';
  local_b8.szCSDVersion[0x20] = '\0';
  local_b8.szCSDVersion[0x21] = '\0';
  local_b8.szCSDVersion[0x22] = '\0';
  local_b8.szCSDVersion[0x23] = '\0';
  local_b8.szCSDVersion[0x24] = '\0';
  local_b8.szCSDVersion[0x25] = '\0';
  local_b8.szCSDVersion[0x26] = '\0';
  local_b8.szCSDVersion[0x27] = '\0';
  local_b8.szCSDVersion[0x28] = '\0';
  local_b8.szCSDVersion[0x29] = '\0';
  local_b8.szCSDVersion[0x2a] = '\0';
  local_b8.szCSDVersion[0x2b] = '\0';
  local_b8.szCSDVersion[0x2c] = '\0';
  local_b8.szCSDVersion[0x2d] = '\0';
  local_b8.szCSDVersion[0x2e] = '\0';
  local_b8.szCSDVersion[0x2f] = '\0';
  local_b8.szCSDVersion[0x30] = '\0';
  local_b8.szCSDVersion[0x31] = '\0';
  local_b8.szCSDVersion[0x32] = '\0';
  local_b8.szCSDVersion[0x33] = '\0';
  local_b8.szCSDVersion[0x34] = '\0';
  local_b8.szCSDVersion[0x35] = '\0';
  local_b8.szCSDVersion[0x36] = '\0';
  local_b8.szCSDVersion[0x37] = '\0';
  local_b8.szCSDVersion[0x38] = '\0';
  local_b8.szCSDVersion[0x39] = '\0';
  local_b8.szCSDVersion[0x3a] = '\0';
  local_b8.szCSDVersion[0x3b] = '\0';
  local_b8.szCSDVersion[0x3c] = '\0';
  local_b8.szCSDVersion[0x3d] = '\0';
  local_b8.szCSDVersion[0x3e] = '\0';
  local_b8.szCSDVersion[0x3f] = '\0';
  local_b8.szCSDVersion[0x40] = '\0';
  local_b8.szCSDVersion[0x41] = '\0';
  local_b8.szCSDVersion[0x42] = '\0';
  local_b8.szCSDVersion[0x43] = '\0';
  local_b8.szCSDVersion[0x44] = '\0';
  local_b8.szCSDVersion[0x45] = '\0';
  local_b8.szCSDVersion[0x46] = '\0';
  local_b8.szCSDVersion[0x47] = '\0';
  local_b8.szCSDVersion[0x48] = '\0';
  local_b8.szCSDVersion[0x49] = '\0';
  local_b8.szCSDVersion[0x4a] = '\0';
  local_b8.szCSDVersion[0x4b] = '\0';
  local_b8.szCSDVersion[0x4c] = '\0';
  local_b8.szCSDVersion[0x4d] = '\0';
  local_b8.szCSDVersion[0x4e] = '\0';
  local_b8.szCSDVersion[0x4f] = '\0';
  local_24 = 0;
  local_b8.szCSDVersion[0x50] = '\0';
  local_b8.szCSDVersion[0x51] = '\0';
  local_b8.szCSDVersion[0x52] = '\0';
  local_b8.szCSDVersion[0x53] = '\0';
  local_b8.szCSDVersion[0x54] = '\0';
  local_b8.szCSDVersion[0x55] = '\0';
  local_b8.szCSDVersion[0x56] = '\0';
  local_b8.szCSDVersion[0x57] = '\0';
  local_b8.szCSDVersion[0x58] = '\0';
  local_b8.szCSDVersion[0x59] = '\0';
  local_b8.szCSDVersion[0x5a] = '\0';
  local_b8.szCSDVersion[0x5b] = '\0';
  local_b8.szCSDVersion[0x5c] = '\0';
  local_b8.szCSDVersion[0x5d] = '\0';
  local_b8.szCSDVersion[0x5e] = '\0';
  local_b8.szCSDVersion[0x5f] = '\0';
  local_b8.szCSDVersion[0x60] = '\0';
  local_b8.szCSDVersion[0x61] = '\0';
  local_b8.szCSDVersion[0x62] = '\0';
  local_b8.szCSDVersion[99] = '\0';
  local_b8.szCSDVersion[100] = '\0';
  local_b8.szCSDVersion[0x65] = '\0';
  local_b8.szCSDVersion[0x66] = '\0';
  local_b8.szCSDVersion[0x67] = '\0';
  local_b8.szCSDVersion[0x68] = '\0';
  local_b8.szCSDVersion[0x69] = '\0';
  local_b8.szCSDVersion[0x6a] = '\0';
  local_b8.szCSDVersion[0x6b] = '\0';
  local_b8.szCSDVersion[0x6c] = '\0';
  local_b8.szCSDVersion[0x6d] = '\0';
  local_b8.szCSDVersion[0x6e] = '\0';
  local_b8.szCSDVersion[0x6f] = '\0';
  local_b8.szCSDVersion[0x70] = '\0';
  local_b8.szCSDVersion[0x71] = '\0';
  local_b8.szCSDVersion[0x72] = '\0';
  local_b8.szCSDVersion[0x73] = '\0';
  local_b8.szCSDVersion[0x74] = '\0';
  local_b8.szCSDVersion[0x75] = '\0';
  local_b8.szCSDVersion[0x76] = '\0';
  local_b8.szCSDVersion[0x77] = '\0';
  local_b8.szCSDVersion[0x78] = '\0';
  local_b8.szCSDVersion[0x79] = '\0';
  local_b8.szCSDVersion[0x7a] = '\0';
  local_b8.szCSDVersion[0x7b] = '\0';
  local_b8.szCSDVersion[0x7c] = '\0';
  local_b8.szCSDVersion[0x7d] = '\0';
  local_b8.szCSDVersion[0x7e] = '\0';
  local_b8.szCSDVersion[0x7f] = '\0';
  local_b8.dwOSVersionInfoSize = 0x9c;
  GetVersionExA(&local_b8);
  _DAT_18007a268 = local_b8.dwMajorVersion;
  return;
}

/* ---- FUNC 00019490 FUN_180019490 (950 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
FUN_180019490(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_1,LPCSTR param_2)

{
  int *piVar1;
  longlong lVar2;
  code *pcVar3;
  LPCWSTR pWVar4;
  void *pvVar5;
  BSTR psz;
  int iVar6;
  HRESULT HVar7;
  int iVar8;
  LCID LVar9;
  BSTR pOVar10;
  undefined8 *puVar11;
  LPSTR pCVar12;
  uint uVar13;
  LPCOLESTR lpszProgID;
  undefined1 *puVar15;
  undefined1 auStackY_1b8 [32];
  WCHAR local_168 [20];
  undefined8 uStack_140;
  undefined1 local_138 [80];
  undefined4 local_e8 [2];
  BSTR local_e0;
  BSTR local_d8;
  wchar_t *local_d0;
  undefined8 *local_c8;
  undefined2 *local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_a8;
  VARIANTARG local_a0;
  undefined1 local_88 [24];
  undefined2 local_70;
  BSTR local_68;
  CLSID local_58;
  ulonglong local_48;
  LPCOLESTR pOVar14;
  
  local_48 = DAT_1800791f8 ^ (ulonglong)local_e8;
  local_e8[0] = 1;
  uStack_140 = 0x1800194da;
  local_a8 = param_1;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1);
  local_e8[0] = 1;
  pOVar14 = (LPCOLESTR)0x0;
  puVar15 = local_138;
  if (DAT_18007a2b0 == (longlong *)0x0) {
    lpszProgID = pOVar14;
    if (local_168 != (LPWSTR)0x0) {
      local_168[0] = L'\0';
      iVar6 = MultiByteToWideChar(0,0,"AspenTech.AspenPlus.Localization.UnmanagedResourceServer.410"
                                  ,-1,local_168,0x3d);
      lpszProgID = local_168;
      if (iVar6 == 0) {
        lpszProgID = pOVar14;
      }
    }
    HVar7 = CLSIDFromProgID(lpszProgID,&local_58);
    puVar15 = auStackY_1b8;
    if ((HVar7 < 0) ||
       (HVar7 = CoCreateInstance(&local_58,(LPUNKNOWN)0x0,1,(IID *)&DAT_180057ac8,&DAT_18007a2b0),
       puVar15 = auStackY_1b8, HVar7 < 0)) goto LAB_1800197f1;
    local_d0 = L"GetPromptResourceString";
    lVar2 = *DAT_18007a2b0;
    GetUserDefaultLCID();
    iVar6 = (**(code **)(lVar2 + 0x28))(DAT_18007a2b0,&DAT_180057ab8,&local_d0,1);
    puVar15 = auStackY_1b8;
    if (iVar6 < 0) {
      (**(code **)(*DAT_18007a2b0 + 0x10))();
      DAT_18007a2b0 = (longlong *)0x0;
      puVar15 = auStackY_1b8;
      goto LAB_1800197f1;
    }
  }
  local_b8 = 0;
  local_b0 = 2;
  local_c0 = (undefined2 *)local_88;
  do {
    *(undefined8 *)(puVar15 + -8) = 0x180019614;
    VariantInit((VARIANTARG *)(local_88 + (longlong)pOVar14 * 0x18));
    uVar13 = (int)pOVar14 + 1;
    pOVar14 = (LPCOLESTR)(ulonglong)uVar13;
  } while (uVar13 < (uint)local_b0);
  *(undefined8 *)(puVar15 + -8) = 0x180019628;
  local_d8 = SysAllocString(L"");
  if (param_2 == (LPCSTR)0x0) {
    local_e0 = (BSTR)0x0;
  }
  else {
    *(undefined4 *)(puVar15 + 0x28) = 0;
    *(undefined8 *)(puVar15 + 0x20) = 0;
    *(undefined8 *)(puVar15 + -8) = 0x18001964b;
    iVar6 = MultiByteToWideChar(0,0,param_2,-1,*(LPWSTR *)(puVar15 + 0x20),*(int *)(puVar15 + 0x28))
    ;
    *(undefined8 *)(puVar15 + -8) = 0x180019658;
    pOVar10 = SysAllocStringLen((OLECHAR *)0x0,iVar6 - 1);
    if (pOVar10 != (BSTR)0x0) {
      *(int *)(puVar15 + 0x28) = iVar6;
      *(BSTR *)(puVar15 + 0x20) = pOVar10;
      *(undefined8 *)(puVar15 + -8) = 0x180019679;
      iVar8 = MultiByteToWideChar(0,0,param_2,-1,*(LPWSTR *)(puVar15 + 0x20),
                                  *(int *)(puVar15 + 0x28));
      if (iVar8 != iVar6) {
        *(undefined8 *)(puVar15 + -8) = 0x180019831;
        SysFreeString(pOVar10);
        goto LAB_180019831;
      }
    }
    local_e0 = pOVar10;
    if (pOVar10 == (BSTR)0x0) {
LAB_180019831:
                    /* WARNING: Subroutine does not return */
      *(undefined8 *)(puVar15 + -8) = 0x18001983b;
      FUN_180018e40(-0x7ff8fff2);
    }
  }
  pOVar10 = local_e0;
  local_70 = 8;
  local_88._0_2_ = 0x4008;
  local_88._8_8_ = &local_d8;
  *(undefined8 *)(puVar15 + -8) = 0x1800196c7;
  local_68 = local_e0;
  COleVariant::COleVariant((COleVariant *)&local_a0,0,3);
  lVar2 = *DAT_18007a2b0;
  *(undefined8 *)(puVar15 + -8) = 0x1800196d8;
  LVar9 = GetUserDefaultLCID();
  *(undefined8 *)(puVar15 + 0x40) = 0;
  *(undefined8 *)(puVar15 + 0x38) = 0;
  *(VARIANTARG **)(puVar15 + 0x30) = &local_a0;
  *(undefined2 ***)(puVar15 + 0x28) = &local_c0;
  *(undefined2 *)(puVar15 + 0x20) = 1;
  pcVar3 = *(code **)(lVar2 + 0x30);
  *(undefined8 *)(puVar15 + -8) = 0x180019714;
  iVar6 = (*pcVar3)(DAT_18007a2b0,DAT_180072048,&DAT_180057ab8,LVar9);
  psz = local_d8;
  if ((-1 < iVar6) && (local_d8 != (OLECHAR *)0x0)) {
    *(undefined8 *)(puVar15 + -8) = 0x180019733;
    puVar11 = operator_new(0x18);
    if (puVar11 == (undefined8 *)0x0) {
      puVar11 = (undefined8 *)0x0;
    }
    else {
      puVar11[1] = 0;
      *(undefined4 *)(puVar11 + 2) = 1;
      *(undefined8 *)(puVar15 + -8) = 0x180019750;
      local_c8 = puVar11;
      pOVar10 = SysAllocString(psz);
      *puVar11 = pOVar10;
      if ((pOVar10 == (BSTR)0x0) && (psz != (OLECHAR *)0x0)) {
                    /* WARNING: Subroutine does not return */
        *(undefined **)(puVar15 + -8) = &UNK_180019846;
        FUN_180047c60(0x8007000e);
      }
    }
    local_c8 = puVar11;
    if (puVar11 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
      *(undefined8 *)(puVar15 + -8) = 0x180019827;
      FUN_180047c60(0x8007000e);
    }
    pCVar12 = (LPSTR)puVar11[1];
    if (pCVar12 == (LPSTR)0x0) {
      pWVar4 = (LPCWSTR)*puVar11;
      *(undefined8 *)(puVar15 + -8) = 0x180019784;
      pCVar12 = FUN_180047c70(pWVar4);
      puVar11[1] = pCVar12;
    }
    *(undefined8 *)(puVar15 + -8) = 0x18001979b;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format(param_1,"%s",pCVar12)
    ;
    LOCK();
    piVar1 = (int *)(puVar11 + 2);
    iVar6 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    pOVar10 = local_e0;
    if (iVar6 == 1) {
      pOVar10 = (BSTR)*puVar11;
      if (pOVar10 != (BSTR)0x0) {
        *(undefined8 *)(puVar15 + -8) = 0x1800197b6;
        SysFreeString(pOVar10);
        *puVar11 = 0;
      }
      pvVar5 = (void *)puVar11[1];
      if (pvVar5 != (void *)0x0) {
        *(undefined8 *)(puVar15 + -8) = 0x1800197c7;
        operator_delete__(pvVar5);
        puVar11[1] = 0;
      }
      *(undefined8 *)(puVar15 + -8) = 0x1800197d8;
      operator_delete(puVar11);
      pOVar10 = local_e0;
    }
  }
  *(undefined8 *)(puVar15 + -8) = 0x1800197e6;
  VariantClear(&local_a0);
  *(undefined8 *)(puVar15 + -8) = 0x1800197f0;
  SysFreeString(pOVar10);
LAB_1800197f1:
  *(undefined8 *)(puVar15 + -8) = 0x180019803;
  return param_1;
}

/* ---- FUNC 00019850 FUN_180019850 (206 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180019850(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_1)

{
  LSTATUS LVar1;
  undefined8 uVar2;
  undefined1 auStackY_168 [32];
  LONG local_138 [2];
  HKEY local_130;
  CHAR local_128;
  undefined1 local_127 [271];
  ulonglong local_18;
  
  local_18 = DAT_1800791f8 ^ (ulonglong)auStackY_168;
  uVar2 = 0;
  LVar1 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000001,"Software\\AspenTech\\Engineering",0,0x20019,
                        &local_130);
  if (LVar1 == 0) {
    local_128 = '\0';
    memset(local_127,0,0x103);
    local_138[0] = 0x104;
    LVar1 = RegQueryValueA(local_130,"Language",&local_128,local_138);
    if (LVar1 == 0) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                (param_1,&local_128);
      uVar2 = 1;
    }
  }
  RegCloseKey(local_130);
  return uVar2;
}

/* ---- FUNC 00019920 FUN_180019920 (186 bytes) ---- */

void FUN_180019920(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_1,
                  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_2,
                  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_3)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Find(param_1,'\"',0);
  if (iVar1 == -1) {
    iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
                      (param_1,'.');
    if (iVar1 == -1) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                (param_3,"\"%s\\%s.amf\"",*(undefined8 *)param_2,*(undefined8 *)param_1);
      goto LAB_1800199b7;
    }
    pcVar2 = "\"%s\"";
  }
  else {
    iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
                      (param_1,'.');
    if (iVar1 == -1) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                (param_3,"%s\\%s.amf",*(undefined8 *)param_2,*(undefined8 *)param_1);
      goto LAB_1800199b7;
    }
    pcVar2 = "%s";
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
            (param_3,pcVar2,*(undefined8 *)param_1);
LAB_1800199b7:
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1);
                    /* WARNING: Could not recover jumptable at 0x0001800199d3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_2);
  return;
}

/* ---- FUNC 000199E0 FUN_1800199e0 (48 bytes) ---- */

void FUN_1800199e0(undefined8 *param_1,LPCWSTR param_2,UINT param_3)

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
    FUN_180018e40(-0x7ff8ffa9);
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
      if (pCVar6 == (LPSTR)0x0) goto LAB_180019bf8;
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
        FUN_180018e40(-0x7ff8fff2);
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
      FUN_180018e40(-0x7ff8ffa9);
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
          FUN_180018e40(-0x7ff8fff2);
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
LAB_180019bf8:
                    /* WARNING: Subroutine does not return */
          FUN_180018e40(-0x7ff8fff2);
        }
      }
      *param_1 = pCVar6;
    }
    iVar4 = WideCharToMultiByte(param_3,0,param_2,cchWideChar,pCVar6,iVar4,(LPCSTR)0x0,(LPBOOL)0x0);
    bVar8 = iVar4 == 0;
  }
  if (bVar8) {
    FUN_180017630((void *)*param_1,pCVar1);
    FUN_180018e60();
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  return;
}

/* ---- FUNC 00019A10 FUN_180019a10 (543 bytes) ---- */

void FUN_180019a10(undefined8 *param_1,longlong param_2)

{
  LPSTR pCVar1;
  LPSTR pCVar2;
  code *pcVar3;
  int iVar4;
  DWORD DVar5;
  LPSTR pCVar6;
  int cchWideChar;
  longlong lVar7;
  undefined8 *unaff_RDI;
  UINT unaff_R12D;
  LPCWSTR unaff_R14;
  bool bVar8;
  
  lVar7 = -1;
  do {
    lVar7 = lVar7 + 1;
  } while (*(short *)(param_2 + lVar7 * 2) != 0);
  cchWideChar = (int)lVar7 + 1;
  pCVar1 = (LPSTR)(param_1 + 1);
  iVar4 = cchWideChar * 4;
  if (((unaff_RDI == (undefined8 *)0x0) || (iVar4 < 0)) || (pCVar1 == (LPSTR)0x0)) {
                    /* WARNING: Subroutine does not return */
    FUN_180018e40(-0x7ff8ffa9);
  }
  pCVar2 = (LPSTR)*param_1;
  pCVar6 = pCVar1;
  if (pCVar2 == pCVar1) {
    if (iVar4 < 0x81) {
      *unaff_RDI = pCVar1;
    }
    else {
      pCVar6 = calloc((longlong)iVar4,1);
      *unaff_RDI = pCVar6;
      if (pCVar6 == (LPSTR)0x0) goto LAB_180019bf8;
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
        FUN_180018e40(-0x7ff8fff2);
      }
    }
    *unaff_RDI = pCVar6;
  }
  iVar4 = WideCharToMultiByte(unaff_R12D,0,unaff_R14,cchWideChar,pCVar6,iVar4,(LPCSTR)0x0,
                              (LPBOOL)0x0);
  bVar8 = iVar4 == 0;
  if ((iVar4 == 0) && (DVar5 = GetLastError(), DVar5 == 0x7a)) {
    iVar4 = WideCharToMultiByte(unaff_R12D,0,unaff_R14,cchWideChar,(LPSTR)0x0,0,(LPCSTR)0x0,
                                (LPBOOL)0x0);
    if (iVar4 < 0) {
                    /* WARNING: Subroutine does not return */
      FUN_180018e40(-0x7ff8ffa9);
    }
    pCVar2 = (LPSTR)*unaff_RDI;
    pCVar6 = pCVar1;
    if (pCVar2 == pCVar1) {
      if (iVar4 < 0x81) {
        *unaff_RDI = pCVar1;
      }
      else {
        pCVar6 = calloc((longlong)iVar4,1);
        *unaff_RDI = pCVar6;
        if (pCVar6 == (LPSTR)0x0) {
                    /* WARNING: Subroutine does not return */
          FUN_180018e40(-0x7ff8fff2);
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
LAB_180019bf8:
                    /* WARNING: Subroutine does not return */
          FUN_180018e40(-0x7ff8fff2);
        }
      }
      *unaff_RDI = pCVar6;
    }
    iVar4 = WideCharToMultiByte(unaff_R12D,0,unaff_R14,cchWideChar,pCVar6,iVar4,(LPCSTR)0x0,
                                (LPBOOL)0x0);
    bVar8 = iVar4 == 0;
  }
  if (bVar8) {
    FUN_180017630((void *)*unaff_RDI,pCVar1);
    FUN_180018e60();
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  return;
}

/* ---- FUNC 00019BE2 FUN_180019be2 (10 bytes) ---- */

void FUN_180019be2(void)

{
                    /* WARNING: Subroutine does not return */
  FUN_180018e40(-0x7ff8fff2);
}

/* ---- FUNC 00019C30 FUN_180019c30 (92 bytes) ---- */

undefined4 FUN_180019c30(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  longlong local_res8 [4];
  
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_res8);
  uVar2 = FUN_180019850((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_res8)
  ;
  uVar3 = 1;
  if (((int)uVar2 == 1) && (0 < *(int *)(local_res8[0] + -0x10))) {
    iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_res8,
                       "ENG");
    uVar3 = 1;
    if (iVar1 != 0) {
      uVar3 = 0;
    }
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_res8);
  return uVar3;
}

/* ---- FUNC 00019C90 FUN_180019c90 (33 bytes) ---- */

void FUN_180019c90(void)

{
  FUN_180019d10();
  if (DAT_18007a2a0 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000180019ca9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*DAT_18007a2a0)();
    return;
  }
  return;
}

/* ---- FUNC 00019CC0 FUN_180019cc0 (43 bytes) ---- */

void FUN_180019cc0(undefined8 param_1)

{
  FUN_180019d10();
  if (DAT_18007a298 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000180019ce2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*DAT_18007a298)(param_1);
    return;
  }
  return;
}

/* ---- FUNC 00019CF0 FUN_180019cf0 (21 bytes) ---- */

void FUN_180019cf0(longlong *param_1,undefined1 *param_2)

{
  if ((param_1 != (longlong *)0x0) && (param_2 != (undefined1 *)0x0)) {
    *param_2 = 0;
                    /* WARNING: Could not recover jumptable at 0x000180019d00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x18))();
    return;
  }
  return;
}

/* ---- FUNC 00019D10 FUN_180019d10 (83 bytes) ---- */

void FUN_180019d10(void)

{
  if (DAT_18007a298 == (FARPROC)0x0) {
    DAT_18007a298 = GetProcAddress(DAT_18007a270,"GRSetACEString");
  }
  if (DAT_18007a2a0 == (FARPROC)0x0) {
    DAT_18007a2a0 = GetProcAddress(DAT_18007a270,"GRGetACEString");
  }
  return;
}

/* ---- FUNC 00019D70 FUN_180019d70 (79 bytes) ---- */

undefined8 FUN_180019d70(longlong *param_1,longlong *param_2,undefined8 *param_3)

{
  if ((*param_2 == DAT_180057a78) && (param_2[1] == DAT_180057a80)) {
    (**(code **)(*param_1 + 8))();
    *param_3 = param_1;
    return 0;
  }
  return 0x80004001;
}

/* ---- FUNC 00019DC0 FUN_180019dc0 (50 bytes) ---- */

undefined8 FUN_180019dc0(longlong param_1,undefined8 param_2,undefined8 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (*(code **)(param_1 + 0x20) == (code *)0x0) {
    return 0x80004005;
  }
  uVar1 = (**(code **)(param_1 + 0x20))(*(undefined8 *)(param_1 + 0x10));
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = uVar1;
  }
  return 0;
}

/* ---- FUNC 00019E00 FUN_180019e00 (53 bytes) ---- */

undefined8 FUN_180019e00(longlong *param_1,char *param_2,uint param_3,uint *param_4)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  
  if ((int)param_1[0x1b] != 0) {
    return 0x80004005;
  }
  uVar3 = 0;
  if (param_3 != 0) {
    do {
      if (*(int *)((longlong)param_1 + 0xd4) != 0) {
        *(undefined4 *)((longlong)param_1 + 0xd4) = 0;
        iVar1 = (**(code **)(*param_1 + 0x70))(param_1);
        if (iVar1 < 0) {
          *(undefined4 *)(param_1 + 0x1b) = 1;
          return 0x80004005;
        }
      }
      cVar2 = *(char *)param_1[0x1e];
      param_1[0x1e] = (longlong)((char *)param_1[0x1e] + 1);
      if (cVar2 == '\0') {
        cVar2 = '\n';
        *(undefined4 *)((longlong)param_1 + 0xd4) = 1;
      }
      *param_2 = cVar2;
      uVar3 = uVar3 + 1;
      param_2 = param_2 + 1;
    } while (uVar3 < param_3);
  }
  if (param_4 != (uint *)0x0) {
    *param_4 = uVar3;
  }
  return 0;
}

/* ---- FUNC 00019E35 FUN_180019e35 (137 bytes) ---- */

undefined8 FUN_180019e35(void)

{
  int iVar1;
  char cVar2;
  longlong *unaff_RBX;
  uint unaff_EBP;
  char *unaff_RSI;
  uint uVar3;
  uint *unaff_R14;
  
  uVar3 = 0;
  if (unaff_EBP != 0) {
    do {
      if (*(int *)((longlong)unaff_RBX + 0xd4) != 0) {
        *(undefined4 *)((longlong)unaff_RBX + 0xd4) = 0;
        iVar1 = (**(code **)(*unaff_RBX + 0x70))();
        if (iVar1 < 0) {
          *(undefined4 *)(unaff_RBX + 0x1b) = 1;
          return 0x80004005;
        }
      }
      cVar2 = *(char *)unaff_RBX[0x1e];
      unaff_RBX[0x1e] = (longlong)((char *)unaff_RBX[0x1e] + 1);
      if (cVar2 == '\0') {
        cVar2 = '\n';
        *(undefined4 *)((longlong)unaff_RBX + 0xd4) = 1;
      }
      *unaff_RSI = cVar2;
      uVar3 = uVar3 + 1;
      unaff_RSI = unaff_RSI + 1;
    } while (uVar3 < unaff_EBP);
  }
  if (unaff_R14 != (uint *)0x0) {
    *unaff_R14 = uVar3;
  }
  return 0;
}

/* ---- FUNC 00019EBE FUN_180019ebe (17 bytes) ---- */

undefined8 FUN_180019ebe(void)

{
  longlong unaff_RBX;
  
  *(undefined4 *)(unaff_RBX + 0xd8) = 1;
  return 0x80004005;
}

/* ---- FUNC 00019ED0 FUN_180019ed0 (174 bytes) ---- */

ulonglong FUN_180019ed0(longlong *param_1,char *param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  uint uVar4;
  
  if (((int)param_1[0x20] < 6) &&
     (uVar2 = FUN_180019e00(param_1,param_2,param_3,param_4), -1 < (int)uVar2)) {
    return 0;
  }
  if ((code *)param_1[0x24] == (code *)0x0) {
LAB_180019f64:
    uVar3 = 0x80004005;
  }
  else {
    uVar1 = (*(code *)param_1[0x24])(param_2,1,param_3,param_1[0x23]);
    if (param_4 != (uint *)0x0) {
      *param_4 = uVar1;
    }
    uVar4 = 0;
    if (uVar1 != 0) {
      do {
        if (*param_2 == '\0') {
          *param_2 = '.';
        }
        else if (*param_2 == -1) goto LAB_180019f64;
        uVar4 = uVar4 + 1;
        param_2 = param_2 + 1;
      } while (uVar4 < uVar1);
    }
    uVar3 = (ulonglong)(param_3 != uVar1);
  }
  return uVar3;
}

/* ---- FUNC 00019F80 FUN_180019f80 (1479 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_180019f80(longlong *param_1,char *param_2,undefined8 *param_3,uint *param_4,
                       undefined8 *param_5,undefined8 *param_6)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  longlong lVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  ulonglong uVar8;
  char *pcVar9;
  longlong lVar10;
  longlong lVar11;
  ulonglong uVar12;
  size_t _MaxCount;
  undefined1 auStack_d18 [32];
  uint local_cf8;
  longlong *local_cf0;
  longlong *local_ce8;
  uint local_ce0;
  int local_cdc;
  undefined8 *local_cd8;
  undefined8 *local_cd0;
  longlong *local_cc8;
  undefined8 local_cc0;
  undefined2 local_cb8 [4];
  undefined8 local_cb0;
  undefined4 local_ca8;
  undefined4 local_ca4;
  undefined4 local_ca0;
  int local_c88;
  undefined8 local_c48 [35];
  undefined8 local_b30;
  undefined4 local_b28;
  undefined8 local_b24;
  char local_858 [2048];
  ulonglong local_58;
  
  local_58 = DAT_1800791f8 ^ (ulonglong)auStack_d18;
  local_cd8 = param_5;
  local_cd0 = param_6;
  local_858[0] = '\0';
  uVar12 = 0;
  local_ce8 = (longlong *)0x0;
  local_cf0 = (longlong *)0x0;
  uVar8 = FUN_1800240b0();
  if ((int)uVar8 == 2) {
    uVar8 = FUN_18001b180(param_1,(longlong)local_858);
    uVar12 = uVar8 & 0xffffffff;
    if ((int)uVar8 == 0) {
      while( true ) {
        if ((local_858[0] != '\0') && (pcVar9 = strchr(local_858,10), pcVar9 != (char *)0x0)) {
          *pcVar9 = '\0';
        }
        iVar5 = strcmp(local_858,"$_SUMMARY_FILE");
        if (iVar5 == 0) break;
        uVar8 = FUN_18001b180(param_1,(longlong)local_858);
        uVar12 = uVar8 & 0xffffffff;
        if ((int)uVar8 != 0) {
          (**(code **)(*param_1 + 0x10))(param_1);
          return uVar12;
        }
      }
      *param_4 = *param_4 | 2;
    }
    (**(code **)(*param_1 + 0x10))(param_1);
    return uVar12;
  }
  bVar3 = true;
  if (param_3 != (undefined8 *)0x0) {
    iVar5 = (**(code **)*param_3)(param_3,&DAT_1800561f0,&local_ce8);
    if (iVar5 == 0) {
      (**(code **)(*local_ce8 + 0x10))();
    }
    else {
      FUN_180007de0(local_c48,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\bkputil.cpp",0x472);
      LogMessage(local_c48,2,1);
      (**(code **)(*local_ce8 + 0x10))();
      local_ce8 = (longlong *)0x0;
    }
    uVar8 = FUN_180019280(param_3,&local_cf0);
    if ((int)uVar8 < 0) {
      local_cf0 = (longlong *)0x0;
    }
    if ((local_ce8 != (longlong *)0x0) && (local_cf0 != (longlong *)0x0)) {
      _MaxCount = 0xffffffffffffffff;
      do {
        _MaxCount = _MaxCount + 1;
      } while (PTR_DAT_180072040[_MaxCount] != '\0');
      iVar5 = strncmp(param_2,PTR_DAT_180072040,_MaxCount);
      local_cc8 = param_1;
      if (iVar5 == 0) {
        local_cb8[0] = 1;
        local_ca8 = 1;
        local_cb0 = 0;
        local_ca0 = 4;
        local_ca4 = 0xffffffff;
        local_cd0 = (undefined8 *)CONCAT44(local_cd0._4_4_,4);
        local_cc0 = 0;
        iVar5 = (**(code **)(*local_cf0 + 0x38))(local_cf0,local_cb8,&local_cd0,0);
        if (iVar5 != 0) {
          FUN_180007de0(local_c48,"Assert failed in file %s line %d",
                        "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\bkputil.cpp",0x500);
          LogMessage(local_c48,2,1);
        }
        uVar8 = FUN_18001b180(param_1,(longlong)local_858);
        uVar6 = (uint)uVar8;
        if (uVar6 == 0) {
          do {
            uVar12 = uVar8 & 0xffffffff;
            uVar6 = (uint)uVar8;
            if ((local_858[0] != '\0') && (pcVar9 = strchr(local_858,10), pcVar9 != (char *)0x0)) {
              *pcVar9 = '\0';
            }
            iVar5 = strcmp(local_858,"$_SUMMARY_FILE");
            if (iVar5 == 0) {
              *param_4 = 2;
              goto LAB_18001a27a;
            }
            iVar5 = strncmp(local_858,"$_ADS_FILE",10);
            if (iVar5 == 0) {
              *param_4 = *param_4 | 8;
              goto LAB_18001a2a7;
            }
            iVar5 = strcmp(local_858,"#HIERPFSVDATA");
            if (iVar5 == 0) goto LAB_18001a27a;
            uVar8 = FUN_18001b180(param_1,(longlong)local_858);
          } while ((int)uVar8 == 0);
          uVar12 = uVar8 & 0xffffffff;
        }
        else {
LAB_18001a27a:
          uVar12 = (ulonglong)uVar6;
        }
      }
      else {
        local_cd0 = param_3;
        lVar10 = PostMainWndMessage(0x4d4,0xe5,&local_cd0);
        if (lVar10 == 0) {
          uVar12 = 0x80004005;
        }
        else {
          *param_4 = *param_4 | 2;
        }
      }
LAB_18001a2a7:
      (**(code **)(*local_cf0 + 0x10))();
      (**(code **)(*param_1 + 0x10))(param_1);
      return uVar12;
    }
  }
  bVar2 = false;
  uVar8 = 0;
  if (((local_cd8 != (undefined8 *)0x0) &&
      (iVar5 = (**(code **)(*param_1 + 0x60))(param_1), uVar8 = 0, -1 < iVar5)) &&
     (local_cdc = local_c88, local_c88 != 0)) {
    FUN_180018790(local_c48,0,0,0);
    iVar5 = local_c88;
    do {
      while( true ) {
        uVar12 = FUN_18001b180(param_1,(longlong)local_858);
        uVar8 = uVar12 & 0xffffffff;
        local_cf8 = (uint)((int)uVar12 != 0);
        iVar7 = strncmp(local_858,"$_SUMMARY_FILE",0xe);
        bVar1 = bVar2;
        if (iVar7 == 0) {
          *param_4 = *param_4 | 2;
          goto LAB_18001a40e;
        }
        iVar7 = strncmp(local_858,"$_ADS_FILE",10);
        if (iVar7 == 0) {
          *param_4 = *param_4 | 8;
          goto LAB_18001a40e;
        }
        iVar7 = strncmp(local_858,"#HIERPFSVDATA",0xd);
        if (iVar7 == 0) goto LAB_18001a40e;
        lVar10 = -1;
        do {
          lVar11 = lVar10 + 1;
          lVar4 = lVar10 + 1;
          lVar10 = lVar11;
        } while (local_858[lVar4] != '\0');
        bVar1 = bVar3;
        if ((int)uVar12 < 0) goto LAB_18001a40e;
        uVar6 = (uint)lVar11;
        uVar12 = FUN_18001aba0((longlong)local_c48,local_858,uVar6,&local_ce0);
        uVar8 = uVar12 & 0xffffffff;
        if (((int)uVar12 < 0) || (iVar5 = iVar5 - local_ce0, local_cf8 != 0)) goto LAB_18001a40e;
        if (local_cdc != -1) break;
        if (uVar6 == 0) goto LAB_18001a40e;
      }
    } while (iVar5 != 0);
LAB_18001a40e:
    *local_cd8 = local_b30;
    local_b30 = 0;
    if (local_cd0 != (undefined8 *)0x0) {
      *(undefined4 *)local_cd0 = local_b28;
      local_b24 = 0;
    }
    FUN_180018bc0(local_c48);
    if (((int)uVar8 < 0) || (!bVar1)) goto LAB_18001a508;
  }
  uVar12 = FUN_18001b180(param_1,(longlong)local_858);
  if ((int)uVar12 == 0) {
    while( true ) {
      if ((local_858[0] != '\0') && (pcVar9 = strchr(local_858,10), pcVar9 != (char *)0x0)) {
        *pcVar9 = '\0';
      }
      iVar5 = strcmp(local_858,"$_SUMMARY_FILE");
      if (iVar5 == 0) break;
      iVar5 = strncmp(local_858,"$_ADS_FILE",10);
      if (iVar5 == 0) {
        *param_4 = *param_4 | 8;
        goto LAB_18001a508;
      }
      iVar5 = strncmp(local_858,"#HIERPFSVDATA",0xd);
      if ((iVar5 == 0) || (uVar12 = FUN_18001b180(param_1,(longlong)local_858), (int)uVar12 != 0))
      goto LAB_18001a508;
    }
    *param_4 = *param_4 | 2;
  }
LAB_18001a508:
  if (local_cf0 != (longlong *)0x0) {
    (**(code **)(*local_cf0 + 0x10))();
  }
  (**(code **)(*param_1 + 0x10))(param_1);
  return uVar8;
}

/* ---- FUNC 0001A550 FUN_18001a550 (913 bytes) ---- */

undefined *** FUN_18001a550(char *param_1)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  basic_streambuf<char,std::char_traits<char>_> *pbVar4;
  undefined8 *puVar5;
  undefined ***pppuVar6;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar7;
  char *pcVar8;
  undefined ***pppuVar9;
  undefined ***pppuVar10;
  undefined ***pppuVar11;
  undefined4 local_res10 [2];
  char *local_res18;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res20 [8];
  int iStack_15c;
  undefined *local_158 [2];
  undefined **local_148;
  basic_istream<char,std::char_traits<char>_> local_140 [96];
  undefined8 local_e0;
  char local_d8 [4];
  undefined8 local_d4;
  undefined1 local_cc;
  FILE *local_c8;
  char *local_c0;
  char *local_b8;
  basic_ios<char,std::char_traits<char>_> local_a8 [128];
  
  pppuVar10 = (undefined ***)0x0;
  local_res10[0] = 0;
  local_158[0] = &DAT_180054380;
  std::basic_ios<char,std::char_traits<char>_>::basic_ios<char,std::char_traits<char>_>(local_a8);
  local_res10[0] = 1;
  std::basic_istream<char,std::char_traits<char>_>::basic_istream<char,std::char_traits<char>_>
            ((basic_istream<char,std::char_traits<char>_> *)local_158,
             (basic_streambuf<char,std::char_traits<char>_> *)&local_148,false);
  *(undefined ***)((longlong)local_158 + (longlong)*(int *)(local_158[0] + 4)) =
       std::basic_ifstream<char,std::char_traits<char>_>::vftable;
  *(int *)((longlong)&iStack_15c + (longlong)*(int *)(local_158[0] + 4)) =
       *(int *)(local_158[0] + 4) + -0xb0;
  std::basic_streambuf<char,std::char_traits<char>_>::basic_streambuf<char,std::char_traits<char>_>
            ((basic_streambuf<char,std::char_traits<char>_> *)&local_148);
  local_148 = std::basic_filebuf<char,std::char_traits<char>_>::vftable;
  local_cc = 0;
  local_d8[1] = 0;
  std::basic_streambuf<char,std::char_traits<char>_>::_Init
            ((basic_streambuf<char,std::char_traits<char>_> *)&local_148);
  local_c8 = (FILE *)0x0;
  local_d4 = DAT_18007a6c0;
  local_e0 = 0;
  pbVar4 = FUN_18001b290((basic_streambuf<char,std::char_traits<char>_> *)&local_148,param_1,1,0x40)
  ;
  if (pbVar4 == (basic_streambuf<char,std::char_traits<char>_> *)0x0) {
    std::basic_ios<char,std::char_traits<char>_>::setstate
              ((basic_ios<char,std::char_traits<char>_> *)
               ((longlong)local_158 + (longlong)*(int *)(local_158[0] + 4)),2,false);
  }
  else {
    std::basic_ios<char,std::char_traits<char>_>::clear
              ((basic_ios<char,std::char_traits<char>_> *)
               ((longlong)local_158 + (longlong)*(int *)(local_158[0] + 4)),0,false);
  }
  if (local_c8 == (FILE *)0x0) goto LAB_18001a885;
  std::basic_istream<char,std::char_traits<char>_>::seekg
            ((basic_istream<char,std::char_traits<char>_> *)local_158,0,2);
  puVar5 = (undefined8 *)
           std::basic_istream<char,std::char_traits<char>_>::tellg
                     ((basic_istream<char,std::char_traits<char>_> *)local_158);
  iVar3 = (int)puVar5[1] + (int)*puVar5;
  std::basic_istream<char,std::char_traits<char>_>::seekg
            ((basic_istream<char,std::char_traits<char>_> *)local_158,0,0);
  pppuVar6 = operator_new__((longlong)(iVar3 + 1));
  std::basic_istream<char,std::char_traits<char>_>::read
            ((basic_istream<char,std::char_traits<char>_> *)local_158,(char *)pppuVar6,
             (longlong)iVar3);
  *(char *)((longlong)iVar3 + (longlong)pppuVar6) = '\0';
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res20,(char *)pppuVar6);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res18,
             (char *)pppuVar6);
  if (0 < *(int *)(local_res18 + -0x10)) {
    iVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Find
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res18
                       ,"</FileRootSettings>",0);
    if (iVar3 != -1) {
      pCVar7 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Mid
                         ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                          &local_res18,(int)local_res10,0);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res18,
                 pCVar7);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_res10);
    }
    operator_delete__(pppuVar6);
    iVar3 = *(int *)(local_res18 + -0x10);
    pppuVar6 = operator_new__((longlong)(iVar3 + 1));
    pcVar8 = local_res18;
    pppuVar9 = pppuVar6;
    do {
      cVar1 = *pcVar8;
      *(char *)pppuVar9 = cVar1;
      pcVar8 = pcVar8 + 1;
      pppuVar9 = (undefined ***)((longlong)pppuVar9 + 1);
    } while (cVar1 != '\0');
    *(char *)((longlong)iVar3 + (longlong)pppuVar6) = '\0';
  }
  if (local_c8 == (FILE *)0x0) {
    local_cc = 0;
    local_d8[1] = 0;
    std::basic_streambuf<char,std::char_traits<char>_>::_Init
              ((basic_streambuf<char,std::char_traits<char>_> *)&local_148);
LAB_18001a83c:
    local_c8 = (FILE *)0x0;
    local_e0 = 0;
    local_d4 = DAT_18007a6c0;
    std::basic_ios<char,std::char_traits<char>_>::setstate
              ((basic_ios<char,std::char_traits<char>_> *)
               ((longlong)local_158 + (longlong)*(int *)(local_158[0] + 4)),2,false);
  }
  else {
    pcVar8 = std::basic_streambuf<char,std::char_traits<char>_>::eback
                       ((basic_streambuf<char,std::char_traits<char>_> *)&local_148);
    if (pcVar8 == local_d8) {
      std::basic_streambuf<char,std::char_traits<char>_>::setg
                ((basic_streambuf<char,std::char_traits<char>_> *)&local_148,local_c0,local_c0,
                 local_b8);
    }
    bVar2 = FUN_18001aed0((longlong *)&local_148);
    pppuVar9 = &local_148;
    if (!bVar2) {
      pppuVar9 = pppuVar10;
    }
    iVar3 = fclose(local_c8);
    pppuVar11 = pppuVar10;
    if (iVar3 == 0) {
      pppuVar11 = pppuVar9;
    }
    local_cc = 0;
    local_d8[1] = 0;
    std::basic_streambuf<char,std::char_traits<char>_>::_Init
              ((basic_streambuf<char,std::char_traits<char>_> *)&local_148);
    local_c8 = (FILE *)0x0;
    local_d4 = DAT_18007a6c0;
    local_e0 = 0;
    if (pppuVar11 == (undefined ***)0x0) goto LAB_18001a83c;
  }
  if (0 < *(int *)(local_res18 + -0x10)) {
    pppuVar10 = pppuVar6;
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res18);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res20);
LAB_18001a885:
  *(undefined ***)((longlong)local_158 + (longlong)*(int *)(local_158[0] + 4)) =
       std::basic_ifstream<char,std::char_traits<char>_>::vftable;
  *(int *)((longlong)&iStack_15c + (longlong)*(int *)(local_158[0] + 4)) =
       *(int *)(local_158[0] + 4) + -0xb0;
  FUN_180018b30((basic_streambuf<char,std::char_traits<char>_> *)&local_148);
  std::basic_istream<char,std::char_traits<char>_>::~basic_istream<char,std::char_traits<char>_>
            (local_140);
  std::basic_ios<char,std::char_traits<char>_>::~basic_ios<char,std::char_traits<char>_>(local_a8);
  return pppuVar10;
}

/* ---- FUNC 0001A8F0 FUN_18001a8f0 (46 bytes) ---- */

int FUN_18001a8f0(undefined8 *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 1) + -1;
  *(int *)(param_1 + 1) = iVar1;
  if (iVar1 == 0) {
    FUN_180018c10(param_1);
    operator_delete(param_1);
    iVar1 = 0;
  }
  return iVar1;
}

/* ---- FUNC 0001A920 FUN_18001a920 (46 bytes) ---- */

int FUN_18001a920(undefined8 *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 1) + -1;
  *(int *)(param_1 + 1) = iVar1;
  if (iVar1 == 0) {
    FUN_180018c20(param_1);
    operator_delete(param_1);
    iVar1 = 0;
  }
  return iVar1;
}

/* ---- FUNC 0001A950 FUN_18001a950 (24 bytes) ---- */

void FUN_18001a950(longlong param_1)

{
  undefined4 uVar1;
  
  uVar1 = 6;
  if (*(longlong *)(param_1 + 0xf8) != 0) {
    uVar1 = 0;
  }
  *(undefined4 *)(param_1 + 0x100) = uVar1;
  return;
}

/* ---- FUNC 0001A970 RestoreEmbeddedObjects (134 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int RestoreEmbeddedObjects(undefined8 param_1,undefined8 *param_2)

{
  int iVar1;
  ulonglong uVar2;
  undefined1 auStack_468 [32];
  longlong *local_448;
  undefined2 local_440 [4];
  undefined8 local_438;
  undefined4 local_430;
  undefined4 local_42c;
  undefined4 local_428;
  undefined4 local_420 [2];
  undefined8 local_418;
  undefined8 local_410;
  undefined1 local_408 [1008];
  ulonglong local_18;
  
                    /* 0x1a970  171  RestoreEmbeddedObjects */
  local_18 = DAT_1800791f8 ^ (ulonglong)auStack_468;
  local_448 = (longlong *)0x0;
  uVar2 = FUN_180019280(param_2,&local_448);
  if ((int)uVar2 < 0) {
    iVar1 = -0x7fffbffb;
  }
  else {
    local_438 = 0;
    local_428 = 8;
    local_42c = 0xffffffff;
    local_420[0] = 8;
    local_410 = 0;
    local_440[0] = 1;
    local_430 = 1;
    local_418 = param_1;
    iVar1 = (**(code **)(*local_448 + 0x38))(local_448,local_440,local_420,0);
    if (iVar1 != 0) {
      FUN_180007de0(local_408,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\bkputil.cpp",0x5ad);
      LogMessage(local_408,2,1);
    }
    (**(code **)(*local_448 + 0x10))();
  }
  return iVar1;
}

/* ---- FUNC 0001A9F6 FUN_18001a9f6 (102 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_18001a9f6(longlong *param_1)

{
  int iVar1;
  longlong *plStackX_20;
  undefined2 uStack0000000000000028;
  undefined4 uStack0000000000000038;
  
  uStack0000000000000028 = 1;
  uStack0000000000000038 = 1;
  iVar1 = (**(code **)(*param_1 + 0x38))();
  if (iVar1 != 0) {
    FUN_180007de0(&stack0x00000060,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\bkputil.cpp",0x5ad);
    LogMessage(&stack0x00000060,2,1);
  }
  (**(code **)(*plStackX_20 + 0x10))();
  return iVar1;
}

/* ---- FUNC 0001AA5C FUN_18001aa5c (25 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18001aa5c(void)

{
  return;
}

/* ---- FUNC 0001AA80 FUN_18001aa80 (73 bytes) ---- */

undefined8 FUN_18001aa80(longlong param_1,int param_2,int param_3)

{
  if (param_3 == 0) {
    *(int *)(param_1 + 0x120) = param_2;
  }
  else if (param_3 == 1) {
    *(int *)(param_1 + 0x120) = *(int *)(param_1 + 0x120) + param_2;
  }
  else if (param_3 == 2) {
    *(int *)(param_1 + 0x120) = *(int *)(param_1 + 0x124) + param_2;
  }
  if (*(uint *)(param_1 + 0x124) < *(uint *)(param_1 + 0x120)) {
    *(uint *)(param_1 + 0x120) = *(uint *)(param_1 + 0x124);
  }
  return 0;
}

/* ---- FUNC 0001AAD0 FUN_18001aad0 (31 bytes) ---- */

uint FUN_18001aad0(longlong param_1,long param_2,int param_3)

{
  int iVar1;
  
  iVar1 = fseek(*(FILE **)(param_1 + 0x118),param_2,param_3);
  return -(uint)(iVar1 != 0) & 0x80004005;
}

/* ---- FUNC 0001AAF0 FUN_18001aaf0 (85 bytes) ---- */

undefined8 FUN_18001aaf0(longlong param_1,undefined8 *param_2,int param_3)

{
  LPVOID pvVar1;
  
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  param_2[4] = 0;
  param_2[5] = 0;
  param_2[6] = 0;
  param_2[7] = 0;
  param_2[8] = 0;
  param_2[9] = 0;
  if (param_3 == 0) {
    pvVar1 = CoTaskMemAlloc(1);
    *param_2 = pvVar1;
  }
  *(undefined4 *)(param_2 + 2) = *(undefined4 *)(param_1 + 0x128);
  *(undefined4 *)((longlong)param_2 + 0x14) = 0;
  return 0;
}

/* ---- FUNC 0001AB50 FUN_18001ab50 (71 bytes) ---- */

undefined8 FUN_18001ab50(undefined8 param_1,undefined8 *param_2,int param_3)

{
  LPVOID pvVar1;
  
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  param_2[4] = 0;
  param_2[5] = 0;
  param_2[6] = 0;
  param_2[7] = 0;
  param_2[8] = 0;
  param_2[9] = 0;
  if (param_3 == 0) {
    pvVar1 = CoTaskMemAlloc(1);
    *param_2 = pvVar1;
  }
  *(undefined4 *)(param_2 + 2) = 0xffffffff;
  *(undefined4 *)((longlong)param_2 + 0x14) = 0;
  return 0;
}

/* ---- FUNC 0001ABA0 FUN_18001aba0 (275 bytes) ---- */

undefined8 FUN_18001aba0(longlong param_1,void *param_2,uint param_3,uint *param_4)

{
  int iVar1;
  uint uVar2;
  void *_Memory;
  undefined8 uVar3;
  uint uVar4;
  
  _Memory = *(void **)(param_1 + 0x118);
  if (_Memory == (void *)0x0) {
    uVar2 = param_3;
    if (param_3 < 0x1000) {
      uVar2 = 0x1000;
    }
    *(uint *)(param_1 + 0x124) = uVar2;
    _Memory = malloc((ulonglong)uVar2);
    *(void **)(param_1 + 0x118) = _Memory;
  }
  iVar1 = (*(int *)(param_1 + 0x120) - *(int *)(param_1 + 0x124)) + param_3;
  if (0 < iVar1) {
    if (iVar1 < 0x400) {
      iVar1 = 0x400;
    }
    uVar2 = iVar1 + *(int *)(param_1 + 0x124);
    *(uint *)(param_1 + 0x124) = uVar2;
    _Memory = realloc(_Memory,(ulonglong)uVar2);
    *(void **)(param_1 + 0x118) = _Memory;
  }
  uVar2 = *(int *)(param_1 + 0x124) - *(uint *)(param_1 + 0x120);
  if (uVar2 < param_3) {
    param_3 = uVar2;
  }
  uVar2 = 0;
  if (0 < (int)param_3) {
    memcpy((void *)((ulonglong)*(uint *)(param_1 + 0x120) + (longlong)_Memory),param_2,
           (longlong)(int)param_3);
    uVar4 = *(int *)(param_1 + 0x120) + param_3;
    *(uint *)(param_1 + 0x120) = uVar4;
    uVar2 = *(uint *)(param_1 + 0x128);
    if (*(uint *)(param_1 + 0x128) <= uVar4) {
      uVar2 = uVar4;
    }
    *(uint *)(param_1 + 0x128) = uVar2;
    uVar2 = param_3;
  }
  if (param_4 != (uint *)0x0) {
    *param_4 = uVar2;
  }
  uVar3 = 0x80004005;
  if (uVar2 != 0) {
    uVar3 = 0;
  }
  return uVar3;
}

/* ---- FUNC 0001ACC0 FUN_18001acc0 (67 bytes) ---- */

undefined8 FUN_18001acc0(longlong param_1,undefined8 param_2,undefined4 param_3,undefined4 *param_4)

{
  if (*(code **)(param_1 + 0x18) == (code *)0x0) {
    return 0x80004005;
  }
  (**(code **)(param_1 + 0x18))(*(undefined8 *)(param_1 + 0x10));
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = param_3;
  }
  return 0;
}

/* ---- FUNC 0001AD10 FUN_18001ad10 (197 bytes) ---- */

undefined8 FUN_18001ad10(longlong param_1,char *param_2,undefined8 param_3,int *param_4)

{
  int iVar1;
  undefined2 local_res8 [4];
  
  iVar1 = 0;
  local_res8[0] = 0;
  if (*(code **)(param_1 + 0xe8) != (code *)0x0) {
    if (*(int *)(param_1 + 0x110) == 0) {
      iVar1 = (**(code **)(param_1 + 0xe8))(param_2);
      if (param_4 != (int *)0x0) {
        *param_4 = iVar1;
      }
      if (iVar1 == 0) {
        return 0x80004005;
      }
      return 0;
    }
    if (*param_2 != '\0') {
      do {
        if (*(int *)(param_1 + 0x114) != 0) {
          (**(code **)(param_1 + 0xe8))(&DAT_1800541f0);
          *(undefined4 *)(param_1 + 0x114) = 0;
        }
        if (*param_2 == '\n') {
          *(undefined4 *)(param_1 + 0x114) = 1;
        }
        local_res8[0] = CONCAT11(local_res8[0]._1_1_,*param_2);
        (**(code **)(param_1 + 0xe8))(local_res8);
        param_2 = param_2 + 1;
        iVar1 = iVar1 + 1;
      } while (*param_2 != '\0');
      if (iVar1 == 0) {
        return 0x80004005;
      }
      return 0;
    }
  }
  return 0x80004005;
}

/* ---- FUNC 0001ADE0 FUN_18001ade0 (240 bytes) ---- */

undefined8 FUN_18001ade0(longlong param_1,char *param_2,undefined8 param_3,int *param_4)

{
  int iVar1;
  
  iVar1 = 0;
  if (*(code **)(param_1 + 0x128) != (code *)0x0) {
    if (*(int *)(param_1 + 0x130) == 0) {
      iVar1 = (**(code **)(param_1 + 0x128))
                        (*(undefined8 *)(param_1 + 0x118),&DAT_1800536f0,param_2);
      if (param_4 != (int *)0x0) {
        *param_4 = iVar1;
      }
      if (iVar1 == 0) {
        return 0x80004005;
      }
      return 0;
    }
    if (*param_2 != '\0') {
      do {
        if (*(int *)(param_1 + 0x134) != 0) {
          (**(code **)(param_1 + 0x128))(*(undefined8 *)(param_1 + 0x118),&DAT_1800541f0);
          *(undefined4 *)(param_1 + 0x134) = 0;
        }
        if (*param_2 == '\n') {
          *(undefined4 *)(param_1 + 0x134) = 1;
        }
        (**(code **)(param_1 + 0x128))
                  (*(undefined8 *)(param_1 + 0x118),&DAT_1800541f4,(int)*param_2);
        param_2 = param_2 + 1;
        iVar1 = iVar1 + 1;
      } while (*param_2 != '\0');
      if (iVar1 == 0) {
        return 0x80004005;
      }
      return 0;
    }
  }
  return 0x80004005;
}

/* ---- FUNC 0001AED0 FUN_18001aed0 (53 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool FUN_18001aed0(longlong *param_1)

{
  int iVar1;
  size_t sVar2;
  size_t _Count;
  undefined1 auStackY_68 [32];
  char *local_38;
  char local_30 [32];
  ulonglong local_10;
  
  local_10 = DAT_1800791f8 ^ (ulonglong)auStackY_68;
  if ((param_1[0xd] == 0) || (*(char *)((longlong)param_1 + 0x71) == '\0')) {
    return true;
  }
  iVar1 = (**(code **)(*param_1 + 0x18))(param_1,0xffffffff);
  if (iVar1 != -1) {
    iVar1 = std::codecvt<char,char,_Mbstatet>::unshift
                      ((codecvt<char,char,_Mbstatet> *)param_1[0xd],
                       (_Mbstatet *)((longlong)param_1 + 0x74),local_30,(char *)&local_10,&local_38)
    ;
    if (iVar1 == 0) {
      *(undefined1 *)((longlong)param_1 + 0x71) = 0;
    }
    else if (iVar1 != 1) {
      if (iVar1 != 3) {
        return false;
      }
      *(undefined1 *)((longlong)param_1 + 0x71) = 0;
      return true;
    }
    _Count = (longlong)local_38 - (longlong)local_30;
    if ((_Count == 0) || (sVar2 = fwrite(local_30,1,_Count,(FILE *)param_1[0x10]), _Count == sVar2))
    {
      return *(char *)((longlong)param_1 + 0x71) == '\0';
    }
  }
  return false;
}

/* ---- FUNC 0001AF05 FUN_18001af05 (95 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool FUN_18001af05(void)

{
  int iVar1;
  longlong in_RAX;
  size_t sVar2;
  longlong unaff_RBX;
  size_t _Count;
  char *in_stack_00000030;
  
  iVar1 = (**(code **)(in_RAX + 0x18))();
  if (iVar1 != -1) {
    iVar1 = std::codecvt<char,char,_Mbstatet>::unshift
                      (*(codecvt<char,char,_Mbstatet> **)(unaff_RBX + 0x68),
                       (_Mbstatet *)(unaff_RBX + 0x74),&stack0x00000038,&stack0x00000058,
                       &stack0x00000030);
    if (iVar1 == 0) {
      *(undefined1 *)(unaff_RBX + 0x71) = 0;
    }
    else if (iVar1 != 1) {
      if (iVar1 != 3) {
        return false;
      }
      *(undefined1 *)(unaff_RBX + 0x71) = 0;
      return true;
    }
    _Count = (longlong)in_stack_00000030 - (longlong)&stack0x00000038;
    if ((_Count == 0) ||
       (sVar2 = fwrite(&stack0x00000038,1,_Count,*(FILE **)(unaff_RBX + 0x80)), _Count == sVar2)) {
      return *(char *)(unaff_RBX + 0x71) == '\0';
    }
  }
  return false;
}

/* ---- FUNC 0001AF64 FUN_18001af64 (63 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool FUN_18001af64(void)

{
  size_t sVar1;
  longlong unaff_RBX;
  size_t _Count;
  longlong in_stack_00000030;
  
  *(undefined1 *)(unaff_RBX + 0x71) = 0;
  _Count = in_stack_00000030 - (longlong)&stack0x00000038;
  if ((_Count != 0) &&
     (sVar1 = fwrite(&stack0x00000038,1,_Count,*(FILE **)(unaff_RBX + 0x80)), _Count != sVar1)) {
    return false;
  }
  return *(char *)(unaff_RBX + 0x71) == '\0';
}

/* ---- FUNC 0001AFA3 FUN_18001afa3 (21 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 FUN_18001afa3(void)

{
  return 1;
}

/* ---- FUNC 0001AFC0 FUN_18001afc0 (110 bytes) ---- */

void FUN_18001afc0(undefined8 *param_1)

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
      operator_delete(puVar3);
    }
    *param_1 = 0;
  }
  return;
}

/* ---- FUNC 0001B030 FUN_18001b030 (20 bytes) ---- */

void FUN_18001b030(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x80) != 0) {
                    /* WARNING: Could not recover jumptable at 0x00018001b03c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    _lock_file();
    return;
  }
  return;
}

/* ---- FUNC 0001B050 FUN_18001b050 (62 bytes) ---- */

void FUN_18001b050(basic_streambuf<char,std::char_traits<char>_> *param_1)

{
  basic_streambuf<char,std::char_traits<char>_> *pbVar1;
  
  pbVar1 = (basic_streambuf<char,std::char_traits<char>_> *)
           std::basic_streambuf<char,std::char_traits<char>_>::eback(param_1);
  if (pbVar1 == param_1 + 0x70) {
                    /* WARNING: Could not recover jumptable at 0x00018001b081. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_streambuf<char,std::char_traits<char>_>::setg
              (param_1,*(char **)(param_1 + 0x88),*(char **)(param_1 + 0x88),
               *(char **)(param_1 + 0x90));
    return;
  }
  return;
}

/* ---- FUNC 0001B090 FUN_18001b090 (31 bytes) ---- */

void FUN_18001b090(void)

{
  undefined8 local_28 [5];
  
  FUN_180018a60(local_28);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_28,(ThrowInfo *)&DAT_180065380);
}

/* ---- FUNC 0001B0B0 FUN_18001b0b0 (20 bytes) ---- */

void FUN_18001b0b0(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x80) != 0) {
                    /* WARNING: Could not recover jumptable at 0x00018001b0bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    _unlock_file();
    return;
  }
  return;
}

/* ---- FUNC 0001B0D0 FUN_18001b0d0 (23 bytes) ---- */

basic_streambuf<char,std::char_traits<char>_> *
FUN_18001b0d0(basic_streambuf<char,std::char_traits<char>_> *param_1)

{
  bool bVar1;
  int iVar2;
  basic_streambuf<char,std::char_traits<char>_> *pbVar3;
  basic_streambuf<char,std::char_traits<char>_> *pbVar4;
  
  if (*(longlong *)(param_1 + 0x80) == 0) {
    pbVar3 = (basic_streambuf<char,std::char_traits<char>_> *)0x0;
  }
  else {
    pbVar3 = (basic_streambuf<char,std::char_traits<char>_> *)
             std::basic_streambuf<char,std::char_traits<char>_>::eback(param_1);
    if (pbVar3 == param_1 + 0x70) {
      std::basic_streambuf<char,std::char_traits<char>_>::setg
                (param_1,*(char **)(param_1 + 0x88),*(char **)(param_1 + 0x88),
                 *(char **)(param_1 + 0x90));
    }
    bVar1 = FUN_18001aed0((longlong *)param_1);
    pbVar4 = (basic_streambuf<char,std::char_traits<char>_> *)0x0;
    if (bVar1) {
      pbVar4 = param_1;
    }
    iVar2 = fclose(*(FILE **)(param_1 + 0x80));
    pbVar3 = (basic_streambuf<char,std::char_traits<char>_> *)0x0;
    if (iVar2 == 0) {
      pbVar3 = pbVar4;
    }
  }
  param_1[0x7c] = (basic_streambuf<char,std::char_traits<char>_>)0x0;
  param_1[0x71] = (basic_streambuf<char,std::char_traits<char>_>)0x0;
  std::basic_streambuf<char,std::char_traits<char>_>::_Init(param_1);
  *(undefined8 *)(param_1 + 0x80) = 0;
  *(undefined8 *)(param_1 + 0x74) = DAT_18007a6c0;
  *(undefined8 *)(param_1 + 0x68) = 0;
  return pbVar3;
}

/* ---- FUNC 0001B0E7 FUN_18001b0e7 (90 bytes) ---- */

basic_streambuf<char,std::char_traits<char>_> *
FUN_18001b0e7(basic_streambuf<char,std::char_traits<char>_> *param_1)

{
  bool bVar1;
  int iVar2;
  basic_streambuf<char,std::char_traits<char>_> *pbVar3;
  basic_streambuf<char,std::char_traits<char>_> *pbVar4;
  basic_streambuf<char,std::char_traits<char>_> *unaff_RDI;
  
  pbVar3 = (basic_streambuf<char,std::char_traits<char>_> *)
           std::basic_streambuf<char,std::char_traits<char>_>::eback(param_1);
  if (pbVar3 == unaff_RDI + 0x70) {
    std::basic_streambuf<char,std::char_traits<char>_>::setg
              (unaff_RDI,*(char **)(unaff_RDI + 0x88),*(char **)(unaff_RDI + 0x88),
               *(char **)(unaff_RDI + 0x90));
  }
  bVar1 = FUN_18001aed0((longlong *)unaff_RDI);
  pbVar3 = (basic_streambuf<char,std::char_traits<char>_> *)0x0;
  if (bVar1) {
    pbVar3 = unaff_RDI;
  }
  iVar2 = fclose(*(FILE **)(unaff_RDI + 0x80));
  pbVar4 = (basic_streambuf<char,std::char_traits<char>_> *)0x0;
  if (iVar2 == 0) {
    pbVar4 = pbVar3;
  }
  unaff_RDI[0x7c] = (basic_streambuf<char,std::char_traits<char>_>)0x0;
  unaff_RDI[0x71] = (basic_streambuf<char,std::char_traits<char>_>)0x0;
  std::basic_streambuf<char,std::char_traits<char>_>::_Init(unaff_RDI);
  *(undefined8 *)(unaff_RDI + 0x80) = 0;
  *(undefined8 *)(unaff_RDI + 0x74) = DAT_18007a6c0;
  *(undefined8 *)(unaff_RDI + 0x68) = 0;
  return pbVar4;
}

/* ---- FUNC 0001B141 FUN_18001b141 (63 bytes) ---- */

undefined8 FUN_18001b141(void)

{
  basic_streambuf<char,std::char_traits<char>_> *unaff_RDI;
  
  unaff_RDI[0x7c] = (basic_streambuf<char,std::char_traits<char>_>)0x0;
  unaff_RDI[0x71] = (basic_streambuf<char,std::char_traits<char>_>)0x0;
  std::basic_streambuf<char,std::char_traits<char>_>::_Init(unaff_RDI);
  *(undefined8 *)(unaff_RDI + 0x80) = 0;
  *(undefined8 *)(unaff_RDI + 0x74) = DAT_18007a6c0;
  *(undefined8 *)(unaff_RDI + 0x68) = 0;
  return 0;
}

/* ---- FUNC 0001B180 FUN_18001b180 (181 bytes) ---- */

ulonglong FUN_18001b180(longlong *param_1,longlong param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  uint uVar4;
  char local_res18 [8];
  int local_res20 [2];
  
  uVar3 = 0;
  uVar1 = uVar3;
  while( true ) {
    uVar4 = (uint)uVar1;
    uVar1 = (**(code **)(*param_1 + 0x18))(param_1,local_res18,1,local_res20);
    uVar2 = uVar1 & 0xffffffff;
    if ((int)uVar1 != 0) {
      return uVar1;
    }
    if (local_res20[0] != 1) break;
    if (local_res18[0] == -1) {
      if (uVar3 == 0) {
        return 0x800300fd;
      }
LAB_18001b1d5:
      *(char *)(uVar3 + param_2) = local_res18[0];
      if ((local_res18[0] == '\n') || (local_res18[0] == -1)) goto LAB_18001b21d;
    }
    else {
      if (local_res18[0] != '\t') goto LAB_18001b1d5;
      uVar4 = uVar4 - 1;
      uVar3 = uVar3 - 1;
    }
    uVar4 = uVar4 + 1;
    uVar1 = (ulonglong)uVar4;
    uVar3 = uVar3 + 1;
    if (0x7fd < (longlong)uVar3) goto LAB_18001b21d;
  }
  uVar2 = 0x800300fd;
  *(undefined1 *)((int)uVar4 + param_2) = 0;
LAB_18001b21d:
  *(undefined1 *)((longlong)(int)uVar4 + 1 + param_2) = 0;
  return uVar2;
}

/* ---- FUNC 0001B240 FUN_18001b240 (80 bytes) ---- */

void FUN_18001b240(basic_streambuf<char,std::char_traits<char>_> *param_1,locale *param_2)

{
  bool bVar1;
  _Facet_base *this;
  
  this = FUN_180018420(param_2);
  bVar1 = std::codecvt_base::always_noconv((codecvt_base *)this);
  if (bVar1) {
    *(undefined8 *)(param_1 + 0x68) = 0;
    return;
  }
  *(_Facet_base **)(param_1 + 0x68) = this;
                    /* WARNING: Could not recover jumptable at 0x00018001b289. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<char,std::char_traits<char>_>::_Init(param_1);
  return;
}

/* ---- FUNC 0001B290 FUN_18001b290 (319 bytes) ---- */

basic_streambuf<char,std::char_traits<char>_> *
FUN_18001b290(basic_streambuf<char,std::char_traits<char>_> *param_1,char *param_2,int param_3,
             int param_4)

{
  bool bVar1;
  _iobuf *p_Var2;
  locale *plVar3;
  _Facet_base *this;
  undefined8 *puVar4;
  int *local_res8;
  char **local_28;
  char **local_20;
  longlong *local_18;
  
  if (*(longlong *)(param_1 + 0x80) == 0) {
    p_Var2 = std::_Fiopen(param_2,param_3,param_4);
    if (p_Var2 != (_iobuf *)0x0) {
      param_1[0x7c] = (basic_streambuf<char,std::char_traits<char>_>)0x1;
      param_1[0x71] = (basic_streambuf<char,std::char_traits<char>_>)0x0;
      std::basic_streambuf<char,std::char_traits<char>_>::_Init(param_1);
      local_20 = (char **)0x0;
      local_28 = (char **)0x0;
      local_res8 = (int *)0x0;
      _get_stream_buffer_pointers(p_Var2,&local_20,&local_28,&local_res8);
      std::basic_streambuf<char,std::char_traits<char>_>::_Init
                (param_1,local_20,local_28,local_res8,local_20,local_28,local_res8);
      *(_iobuf **)(param_1 + 0x80) = p_Var2;
      *(undefined8 *)(param_1 + 0x74) = DAT_18007a6c0;
      *(undefined8 *)(param_1 + 0x68) = 0;
      plVar3 = (locale *)std::basic_streambuf<char,std::char_traits<char>_>::getloc(param_1);
      this = FUN_180018420(plVar3);
      bVar1 = std::codecvt_base::always_noconv((codecvt_base *)this);
      if (bVar1) {
        *(undefined8 *)(param_1 + 0x68) = 0;
      }
      else {
        *(_Facet_base **)(param_1 + 0x68) = this;
        std::basic_streambuf<char,std::char_traits<char>_>::_Init(param_1);
      }
      if (local_18 != (longlong *)0x0) {
        puVar4 = (undefined8 *)(**(code **)(*local_18 + 0x10))();
        if (puVar4 != (undefined8 *)0x0) {
          (**(code **)*puVar4)(puVar4,1);
        }
      }
      return param_1;
    }
  }
  return (basic_streambuf<char,std::char_traits<char>_> *)0x0;
}

/* ---- FUNC 0001B3D0 FUN_18001b3d0 (45 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_18001b3d0(basic_streambuf<char,std::char_traits<char>_> *param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  basic_streambuf<char,std::char_traits<char>_> *pbVar4;
  size_t sVar5;
  size_t _Count;
  char cVar6;
  undefined1 auStackY_88 [32];
  char local_48;
  char local_47 [7];
  char *local_40;
  char *local_38;
  char local_30 [32];
  ulonglong local_10;
  
  local_10 = DAT_1800791f8 ^ (ulonglong)auStackY_88;
  if (param_2 == -1) {
    iVar1 = 0;
  }
  else {
    pcVar2 = std::basic_streambuf<char,std::char_traits<char>_>::pptr(param_1);
    cVar6 = (char)param_2;
    if (pcVar2 != (char *)0x0) {
      pcVar2 = std::basic_streambuf<char,std::char_traits<char>_>::epptr(param_1);
      pcVar3 = std::basic_streambuf<char,std::char_traits<char>_>::pptr(param_1);
      if (pcVar3 < pcVar2) {
        pcVar2 = std::basic_streambuf<char,std::char_traits<char>_>::_Pninc(param_1);
        *pcVar2 = cVar6;
        return param_2;
      }
    }
    if (*(longlong *)(param_1 + 0x80) != 0) {
      pbVar4 = (basic_streambuf<char,std::char_traits<char>_> *)
               std::basic_streambuf<char,std::char_traits<char>_>::eback(param_1);
      if (pbVar4 == param_1 + 0x70) {
        std::basic_streambuf<char,std::char_traits<char>_>::setg
                  (param_1,*(char **)(param_1 + 0x88),*(char **)(param_1 + 0x88),
                   *(char **)(param_1 + 0x90));
      }
      if (*(codecvt<char,char,_Mbstatet> **)(param_1 + 0x68) == (codecvt<char,char,_Mbstatet> *)0x0)
      {
        iVar1 = fputc((int)cVar6,*(FILE **)(param_1 + 0x80));
        if (iVar1 == -1) {
          return -1;
        }
        return param_2;
      }
      local_48 = cVar6;
      iVar1 = std::codecvt<char,char,_Mbstatet>::out
                        (*(codecvt<char,char,_Mbstatet> **)(param_1 + 0x68),
                         (_Mbstatet *)(param_1 + 0x74),&local_48,local_47,&local_38,local_30,
                         (char *)&local_10,&local_40);
      if ((iVar1 == 0) || (iVar1 == 1)) {
        _Count = (longlong)local_40 - (longlong)local_30;
        if ((_Count == 0) ||
           (sVar5 = fwrite(local_30,1,_Count,*(FILE **)(param_1 + 0x80)), _Count == sVar5)) {
          param_1[0x71] = (basic_streambuf<char,std::char_traits<char>_>)0x1;
          if (local_38 == &local_48) {
            return -1;
          }
          return param_2;
        }
      }
      else if (iVar1 == 3) {
        iVar1 = fputc((int)local_48,*(FILE **)(param_1 + 0x80));
        if (iVar1 == -1) {
          return -1;
        }
        return param_2;
      }
    }
    iVar1 = -1;
  }
  return iVar1;
}

/* ---- FUNC 0001B3FD FUN_18001b3fd (361 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_18001b3fd(basic_streambuf<char,std::char_traits<char>_> *param_1)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  basic_streambuf<char,std::char_traits<char>_> *pbVar4;
  size_t sVar5;
  size_t _Count;
  char cVar6;
  undefined4 unaff_ESI;
  basic_streambuf<char,std::char_traits<char>_> *unaff_RDI;
  char in_stack_00000040;
  char *in_stack_00000048;
  char *in_stack_00000050;
  
  pcVar2 = std::basic_streambuf<char,std::char_traits<char>_>::pptr(param_1);
  cVar6 = (char)unaff_ESI;
  if (pcVar2 != (char *)0x0) {
    pcVar2 = std::basic_streambuf<char,std::char_traits<char>_>::epptr(unaff_RDI);
    pcVar3 = std::basic_streambuf<char,std::char_traits<char>_>::pptr(unaff_RDI);
    if (pcVar3 < pcVar2) {
      pcVar2 = std::basic_streambuf<char,std::char_traits<char>_>::_Pninc(unaff_RDI);
      *pcVar2 = cVar6;
      return unaff_ESI;
    }
  }
  if (*(longlong *)(unaff_RDI + 0x80) != 0) {
    pbVar4 = (basic_streambuf<char,std::char_traits<char>_> *)
             std::basic_streambuf<char,std::char_traits<char>_>::eback(unaff_RDI);
    if (pbVar4 == unaff_RDI + 0x70) {
      std::basic_streambuf<char,std::char_traits<char>_>::setg
                (unaff_RDI,*(char **)(unaff_RDI + 0x88),*(char **)(unaff_RDI + 0x88),
                 *(char **)(unaff_RDI + 0x90));
    }
    if (*(codecvt<char,char,_Mbstatet> **)(unaff_RDI + 0x68) == (codecvt<char,char,_Mbstatet> *)0x0)
    {
      iVar1 = fputc((int)cVar6,*(FILE **)(unaff_RDI + 0x80));
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      return unaff_ESI;
    }
    in_stack_00000040 = cVar6;
    iVar1 = std::codecvt<char,char,_Mbstatet>::out
                      (*(codecvt<char,char,_Mbstatet> **)(unaff_RDI + 0x68),
                       (_Mbstatet *)(unaff_RDI + 0x74),&stack0x00000040,&stack0x00000041,
                       &stack0x00000050,&stack0x00000058,&stack0x00000078,&stack0x00000048);
    if ((iVar1 == 0) || (iVar1 == 1)) {
      _Count = (longlong)in_stack_00000048 - (longlong)&stack0x00000058;
      if ((_Count == 0) ||
         (sVar5 = fwrite(&stack0x00000058,1,_Count,*(FILE **)(unaff_RDI + 0x80)), _Count == sVar5))
      {
        unaff_RDI[0x71] = (basic_streambuf<char,std::char_traits<char>_>)0x1;
        if (in_stack_00000050 == &stack0x00000040) {
          return 0xffffffff;
        }
        return unaff_ESI;
      }
    }
    else if (iVar1 == 3) {
      iVar1 = fputc((int)in_stack_00000040,*(FILE **)(unaff_RDI + 0x80));
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      return unaff_ESI;
    }
  }
  return 0xffffffff;
}

/* ---- FUNC 0001B566 FUN_18001b566 (30 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18001b566(void)

{
  return;
}

/* ---- FUNC 0001B590 FUN_18001b590 (282 bytes) ---- */

uint FUN_18001b590(basic_streambuf<char,std::char_traits<char>_> *param_1,uint param_2)

{
  basic_streambuf<char,std::char_traits<char>_> *pbVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  basic_streambuf<char,std::char_traits<char>_> *pbVar5;
  
  pcVar3 = std::basic_streambuf<char,std::char_traits<char>_>::gptr(param_1);
  if (pcVar3 != (char *)0x0) {
    pcVar3 = std::basic_streambuf<char,std::char_traits<char>_>::eback(param_1);
    pcVar4 = std::basic_streambuf<char,std::char_traits<char>_>::gptr(param_1);
    if ((pcVar3 < pcVar4) &&
       ((param_2 == 0xffffffff ||
        (pcVar3 = std::basic_streambuf<char,std::char_traits<char>_>::gptr(param_1),
        (byte)pcVar3[-1] == param_2)))) {
      std::basic_streambuf<char,std::char_traits<char>_>::_Gndec(param_1);
      if (param_2 != 0xffffffff) {
        return param_2;
      }
      return 0;
    }
  }
  if ((*(FILE **)(param_1 + 0x80) != (FILE *)0x0) && (param_2 != 0xffffffff)) {
    if ((*(longlong *)(param_1 + 0x68) == 0) &&
       (iVar2 = ungetc(param_2 & 0xff,*(FILE **)(param_1 + 0x80)), iVar2 != -1)) {
      return param_2;
    }
    pbVar1 = param_1 + 0x70;
    pbVar5 = (basic_streambuf<char,std::char_traits<char>_> *)
             std::basic_streambuf<char,std::char_traits<char>_>::gptr(param_1);
    if (pbVar5 != pbVar1) {
      *pbVar1 = SUB41(param_2,0);
      pbVar5 = (basic_streambuf<char,std::char_traits<char>_> *)
               std::basic_streambuf<char,std::char_traits<char>_>::eback(param_1);
      if (pbVar5 != pbVar1) {
        pcVar3 = std::basic_streambuf<char,std::char_traits<char>_>::eback(param_1);
        *(char **)(param_1 + 0x88) = pcVar3;
        pcVar3 = std::basic_streambuf<char,std::char_traits<char>_>::egptr(param_1);
        *(char **)(param_1 + 0x90) = pcVar3;
      }
      std::basic_streambuf<char,std::char_traits<char>_>::setg
                (param_1,(char *)pbVar1,(char *)pbVar1,(char *)(param_1 + 0x71));
      return param_2;
    }
  }
  return 0xffffffff;
}

/* ---- FUNC 0001B6B0 FUN_18001b6b0 (73 bytes) ---- */

void FUN_18001b6b0(undefined8 *param_1,undefined1 param_2)

{
  ulonglong uVar1;
  ulonglong _Size;
  ulonglong uVar2;
  void *_Src;
  void *_Dst;
  ulonglong uVar3;
  ulonglong uVar4;
  void *pvVar5;
  
  _Size = param_1[2];
  uVar2 = param_1[3];
  if (_Size < uVar2) {
    param_1[2] = _Size + 1;
    if (0xf < uVar2) {
      param_1 = (undefined8 *)*param_1;
    }
    *(undefined1 *)((longlong)param_1 + _Size) = param_2;
    *(undefined1 *)((longlong)param_1 + _Size + 1) = 0;
    return;
  }
  uVar4 = 0x7fffffffffffffff;
  if (_Size == 0x7fffffffffffffff) {
                    /* WARNING: Subroutine does not return */
    FUN_18000ace0();
  }
  uVar3 = _Size + 1 | 0xf;
  if (uVar3 < 0x8000000000000000) {
    if (0x7fffffffffffffff - (uVar2 >> 1) < uVar2) {
      _Dst = (void *)FUN_180007f10(0x8000000000000000);
    }
    else {
      uVar1 = (uVar2 >> 1) + uVar2;
      uVar4 = uVar3;
      if (uVar3 < uVar1) {
        uVar4 = uVar1;
      }
      uVar3 = uVar4 + 1;
      if (uVar3 < 0x1000) {
        if (uVar3 == 0) {
          _Dst = (void *)0x0;
        }
        else {
          _Dst = operator_new(uVar3);
        }
      }
      else {
        _Dst = (void *)FUN_180007f10(uVar3);
      }
    }
  }
  else {
    _Dst = (void *)FUN_180007f10(0x8000000000000000);
  }
  param_1[2] = _Size + 1;
  param_1[3] = uVar4;
  if (uVar2 < 0x10) {
    memcpy(_Dst,param_1,_Size);
    *(undefined1 *)((longlong)_Dst + _Size) = param_2;
    *(undefined1 *)((longlong)_Dst + _Size + 1) = 0;
  }
  else {
    _Src = (void *)*param_1;
    memcpy(_Dst,_Src,_Size);
    *(undefined1 *)((longlong)_Dst + _Size) = param_2;
    *(undefined1 *)((longlong)_Dst + _Size + 1) = 0;
    pvVar5 = _Src;
    if ((0xfff < uVar2 + 1) &&
       (pvVar5 = *(void **)((longlong)_Src + -8),
       0x1f < (ulonglong)((longlong)_Src + (-8 - (longlong)pvVar5)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar5);
  }
  *param_1 = _Dst;
  return;
}

/* ---- FUNC 0001B6F9 FUN_18001b6f9 (31 bytes) ---- */

void FUN_18001b6f9(void)

{
  ulonglong uVar1;
  void *_Src;
  void *_Dst;
  ulonglong uVar2;
  undefined8 *unaff_RBX;
  ulonglong unaff_RBP;
  size_t unaff_RSI;
  ulonglong uVar3;
  void *pvVar4;
  undefined1 unaff_R15B;
  
  uVar3 = 0x7fffffffffffffff;
  if (unaff_RSI == 0x7fffffffffffffff) {
                    /* WARNING: Subroutine does not return */
    FUN_18000ace0();
  }
  uVar2 = unaff_RSI + 1 | 0xf;
  if (uVar2 < 0x8000000000000000) {
    if (0x7fffffffffffffff - (unaff_RBP >> 1) < unaff_RBP) {
      _Dst = (void *)FUN_180007f10(0x8000000000000000);
    }
    else {
      uVar1 = (unaff_RBP >> 1) + unaff_RBP;
      uVar3 = uVar2;
      if (uVar2 < uVar1) {
        uVar3 = uVar1;
      }
      uVar2 = uVar3 + 1;
      if (uVar2 < 0x1000) {
        if (uVar2 == 0) {
          _Dst = (void *)0x0;
        }
        else {
          _Dst = operator_new(uVar2);
        }
      }
      else {
        _Dst = (void *)FUN_180007f10(uVar2);
      }
    }
  }
  else {
    _Dst = (void *)FUN_180007f10(0x8000000000000000);
  }
  unaff_RBX[2] = unaff_RSI + 1;
  unaff_RBX[3] = uVar3;
  if (unaff_RBP < 0x10) {
    memcpy(_Dst,unaff_RBX,unaff_RSI);
    *(undefined1 *)((longlong)_Dst + unaff_RSI) = unaff_R15B;
    *(undefined1 *)((longlong)_Dst + unaff_RSI + 1) = 0;
  }
  else {
    _Src = (void *)*unaff_RBX;
    memcpy(_Dst,_Src,unaff_RSI);
    *(undefined1 *)((longlong)_Dst + unaff_RSI) = unaff_R15B;
    *(undefined1 *)((longlong)_Dst + unaff_RSI + 1) = 0;
    pvVar4 = _Src;
    if ((0xfff < unaff_RBP + 1) &&
       (pvVar4 = *(void **)((longlong)_Src + -8),
       0x1f < (ulonglong)((longlong)_Src + (-8 - (longlong)pvVar4)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar4);
  }
  *unaff_RBX = _Dst;
  return;
}

/* ---- FUNC 0001B718 FUN_18001b718 (163 bytes) ---- */

void FUN_18001b718(void)

{
  ulonglong uVar1;
  void *_Src;
  void *_Dst;
  ulonglong uVar2;
  undefined8 *unaff_RBX;
  ulonglong unaff_RBP;
  size_t unaff_RSI;
  ulonglong unaff_RDI;
  void *pvVar3;
  undefined1 unaff_R15B;
  
  uVar2 = unaff_RSI + 1 | 0xf;
  if (unaff_RDI < uVar2) {
    _Dst = (void *)FUN_180007f10(0x8000000000000000);
  }
  else if (unaff_RDI - (unaff_RBP >> 1) < unaff_RBP) {
    _Dst = (void *)FUN_180007f10(0x8000000000000000);
  }
  else {
    uVar1 = (unaff_RBP >> 1) + unaff_RBP;
    unaff_RDI = uVar2;
    if (uVar2 < uVar1) {
      unaff_RDI = uVar1;
    }
    uVar2 = unaff_RDI + 1;
    if (uVar2 < 0x1000) {
      if (uVar2 == 0) {
        _Dst = (void *)0x0;
      }
      else {
        _Dst = operator_new(uVar2);
      }
    }
    else {
      _Dst = (void *)FUN_180007f10(uVar2);
    }
  }
  unaff_RBX[2] = unaff_RSI + 1;
  unaff_RBX[3] = unaff_RDI;
  if (unaff_RBP < 0x10) {
    memcpy(_Dst,unaff_RBX,unaff_RSI);
    *(undefined1 *)((longlong)_Dst + unaff_RSI) = unaff_R15B;
    *(undefined1 *)((longlong)_Dst + unaff_RSI + 1) = 0;
  }
  else {
    _Src = (void *)*unaff_RBX;
    memcpy(_Dst,_Src,unaff_RSI);
    *(undefined1 *)((longlong)_Dst + unaff_RSI) = unaff_R15B;
    *(undefined1 *)((longlong)_Dst + unaff_RSI + 1) = 0;
    pvVar3 = _Src;
    if ((0xfff < unaff_RBP + 1) &&
       (pvVar3 = *(void **)((longlong)_Src + -8),
       0x1f < (ulonglong)((longlong)_Src + (-8 - (longlong)pvVar3)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar3);
  }
  *unaff_RBX = _Dst;
  return;
}

/* ---- FUNC 0001B7BB FUN_18001b7bb (120 bytes) ---- */

void FUN_18001b7bb(void *param_1,undefined8 param_2,size_t param_3)

{
  void *_Src;
  longlong *unaff_RBX;
  longlong unaff_RBP;
  longlong unaff_RSI;
  void *pvVar1;
  longlong unaff_R14;
  undefined1 unaff_R15B;
  
  _Src = (void *)*unaff_RBX;
  memcpy(param_1,_Src,param_3);
  *(undefined1 *)(unaff_R14 + unaff_RSI) = unaff_R15B;
  *(undefined1 *)(unaff_R14 + 1 + unaff_RSI) = 0;
  pvVar1 = _Src;
  if ((0xfff < unaff_RBP + 1U) &&
     (pvVar1 = *(void **)((longlong)_Src + -8),
     0x1f < (ulonglong)((longlong)_Src + (-8 - (longlong)pvVar1)))) {
                    /* WARNING: Subroutine does not return */
    _invalid_parameter_noinfo_noreturn();
  }
  operator_delete(pvVar1);
  *unaff_RBX = unaff_R14;
  return;
}

/* ---- FUNC 0001B833 thunk_FUN_18000ace0 (5 bytes) ---- */

void thunk_FUN_18000ace0(void)

{
                    /* WARNING: Subroutine does not return */
  FUN_18000ace0();
}

/* ---- FUNC 0001B840 FUN_18001b840 (269 bytes) ---- */

int FUN_18001b840(longlong *param_1,
                 CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_2)

{
  char cVar1;
  int iVar2;
  IAtlStringMgr *pIVar3;
  int iVar4;
  char local_res8 [16];
  char local_res18 [8];
  int local_res20 [2];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_30 [8];
  
  iVar4 = 0;
  iVar2 = (**(code **)(*param_1 + 0x18))(param_1,local_res8,1,local_res20);
  if (-1 < iVar2) {
    while ((cVar1 = local_res8[0], local_res20[0] == 1 && (local_res8[0] != '\0'))) {
      if (iVar4 == 0) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  (param_2,local_res8[0]);
      }
      else {
        pIVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                           (param_2);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_30,pIVar3);
        local_res18[0] = cVar1;
        ATL::CSimpleStringT<char,1>::Concatenate
                  ((CSimpleStringT<char,1> *)local_30,*(char **)param_2,
                   *(int *)(*(char **)param_2 + -0x10),local_res18,1);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  (param_2,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                            *)local_30);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_30);
      }
      iVar4 = iVar4 + 1;
      if (local_res8[0] == '\n') {
        return iVar4;
      }
      iVar2 = (**(code **)(*param_1 + 0x18))(param_1,local_res8,1,local_res20);
      if (iVar2 < 0) {
        return iVar4;
      }
    }
  }
  return iVar4;
}

/* ---- FUNC 0001B950 FUN_18001b950 (206 bytes) ---- */

fpos_t * FUN_18001b950(basic_streambuf<char,std::char_traits<char>_> *param_1,fpos_t *param_2,
                      longlong param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  basic_streambuf<char,std::char_traits<char>_> *pbVar3;
  fpos_t fVar4;
  fpos_t local_res8;
  
  pbVar3 = (basic_streambuf<char,std::char_traits<char>_> *)
           std::basic_streambuf<char,std::char_traits<char>_>::gptr(param_1);
  if (((pbVar3 == param_1 + 0x70) && (param_4 == 1)) && (*(longlong *)(param_1 + 0x68) == 0)) {
    param_3 = param_3 + -1;
  }
  if (*(longlong *)(param_1 + 0x80) != 0) {
    bVar1 = FUN_18001aed0((longlong *)param_1);
    if (bVar1) {
      if ((param_3 != 0) || (param_4 != 1)) {
        iVar2 = _fseeki64(*(FILE **)(param_1 + 0x80),param_3,param_4);
        if (iVar2 != 0) goto LAB_18001b9f1;
      }
      iVar2 = fgetpos(*(FILE **)(param_1 + 0x80),&local_res8);
      if (iVar2 == 0) {
        FUN_18001b050(param_1);
        fVar4 = *(fpos_t *)(param_1 + 0x74);
        *param_2 = local_res8;
        goto LAB_18001b9fa;
      }
    }
  }
LAB_18001b9f1:
  *param_2 = -1;
  fVar4 = 0;
LAB_18001b9fa:
  param_2[1] = 0;
  param_2[2] = fVar4;
  return param_2;
}

/* ---- FUNC 0001BA20 FUN_18001ba20 (147 bytes) ---- */

longlong *
FUN_18001ba20(basic_streambuf<char,std::char_traits<char>_> *param_1,longlong *param_2,
             longlong *param_3)

{
  bool bVar1;
  int iVar2;
  longlong lVar3;
  longlong local_res8;
  
  local_res8 = param_3[1] + *param_3;
  if (*(longlong *)(param_1 + 0x80) != 0) {
    bVar1 = FUN_18001aed0((longlong *)param_1);
    if (bVar1) {
      iVar2 = fsetpos(*(FILE **)(param_1 + 0x80),&local_res8);
      if (iVar2 == 0) {
        *(longlong *)(param_1 + 0x74) = param_3[2];
        FUN_18001b050(param_1);
        lVar3 = *(longlong *)(param_1 + 0x74);
        *param_2 = local_res8;
        goto LAB_18001ba94;
      }
    }
  }
  *param_2 = -1;
  lVar3 = 0;
LAB_18001ba94:
  param_2[1] = 0;
  param_2[2] = lVar3;
  return param_2;
}

/* ---- FUNC 0001BAC0 FUN_18001bac0 (62 bytes) ---- */

basic_streambuf<char,std::char_traits<char>_> *
FUN_18001bac0(basic_streambuf<char,std::char_traits<char>_> *param_1,char *param_2,size_t param_3)

{
  longlong lVar1;
  int iVar2;
  int *local_res8;
  char **local_res10;
  char **local_res18 [2];
  
  if ((param_2 != (char *)0x0) || (iVar2 = 4, param_3 != 0)) {
    iVar2 = 0;
  }
  if (*(FILE **)(param_1 + 0x80) != (FILE *)0x0) {
    iVar2 = setvbuf(*(FILE **)(param_1 + 0x80),param_2,iVar2,param_3);
    if (iVar2 == 0) {
      lVar1 = *(longlong *)(param_1 + 0x80);
      param_1[0x7c] = (basic_streambuf<char,std::char_traits<char>_>)0x1;
      param_1[0x71] = (basic_streambuf<char,std::char_traits<char>_>)0x0;
      std::basic_streambuf<char,std::char_traits<char>_>::_Init(param_1);
      if (lVar1 != 0) {
        local_res18[0] = (char **)0x0;
        local_res10 = (char **)0x0;
        local_res8 = (int *)0x0;
        _get_stream_buffer_pointers(lVar1,local_res18,&local_res10,&local_res8);
        std::basic_streambuf<char,std::char_traits<char>_>::_Init
                  (param_1,local_res18[0],local_res10,local_res8,local_res18[0],local_res10,
                   local_res8);
      }
      *(longlong *)(param_1 + 0x80) = lVar1;
      *(undefined8 *)(param_1 + 0x74) = DAT_18007a6c0;
      *(undefined8 *)(param_1 + 0x68) = 0;
      return param_1;
    }
  }
  return (basic_streambuf<char,std::char_traits<char>_> *)0x0;
}

/* ---- FUNC 0001BAFE FUN_18001bafe (149 bytes) ---- */

void FUN_18001bafe(void)

{
  longlong lVar1;
  basic_streambuf<char,std::char_traits<char>_> *unaff_RBX;
  char **unaff_RSI;
  char **in_stack_00000060;
  char **in_stack_00000068;
  char **in_stack_00000070;
  
  lVar1 = *(longlong *)(unaff_RBX + 0x80);
  unaff_RBX[0x7c] = (basic_streambuf<char,std::char_traits<char>_>)0x1;
  unaff_RBX[0x71] = SUB81(unaff_RSI,0);
  std::basic_streambuf<char,std::char_traits<char>_>::_Init(unaff_RBX);
  if (lVar1 != 0) {
    in_stack_00000060 = unaff_RSI;
    in_stack_00000068 = unaff_RSI;
    in_stack_00000070 = unaff_RSI;
    _get_stream_buffer_pointers(lVar1,&stack0x00000070,&stack0x00000068,&stack0x00000060);
    std::basic_streambuf<char,std::char_traits<char>_>::_Init
              (unaff_RBX,in_stack_00000070,in_stack_00000068,(int *)in_stack_00000060,
               in_stack_00000070,in_stack_00000068,(int *)in_stack_00000060);
  }
  *(longlong *)(unaff_RBX + 0x80) = lVar1;
  *(undefined8 *)(unaff_RBX + 0x74) = DAT_18007a6c0;
  *(char ***)(unaff_RBX + 0x68) = unaff_RSI;
  return;
}

/* ---- FUNC 0001BB93 FUN_18001bb93 (9 bytes) ---- */

undefined8 FUN_18001bb93(void)

{
  return 0;
}

/* ---- FUNC 0001BBA0 FUN_18001bba0 (72 bytes) ---- */

int FUN_18001bba0(longlong *param_1)

{
  int iVar1;
  
  if (param_1[0x10] != 0) {
    iVar1 = (**(code **)(*param_1 + 0x18))(param_1,0xffffffff);
    if (iVar1 != -1) {
      iVar1 = fflush((FILE *)param_1[0x10]);
      return (-1 < iVar1) - 1;
    }
  }
  return 0;
}

/* ---- FUNC 0001BBF0 FUN_18001bbf0 (972 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint FUN_18001bbf0(basic_streambuf<char,std::char_traits<char>_> *param_1)

{
  ulonglong uVar1;
  ulonglong uVar2;
  char ******ppppppcVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  byte *pbVar8;
  basic_streambuf<char,std::char_traits<char>_> *pbVar9;
  char *******pppppppcVar10;
  ulonglong uVar11;
  FILE *_File;
  uint uVar12;
  ulonglong uVar13;
  char *******pppppppcVar14;
  size_t sVar15;
  char cVar16;
  undefined1 auStackY_a8 [32];
  byte local_68;
  char local_67 [7];
  char *local_60;
  byte *local_58;
  char ******local_50;
  undefined8 uStack_48;
  size_t local_40;
  ulonglong local_38;
  ulonglong local_30;
  
  local_30 = DAT_1800791f8 ^ (ulonglong)auStackY_a8;
  pcVar6 = std::basic_streambuf<char,std::char_traits<char>_>::gptr(param_1);
  if (pcVar6 != (char *)0x0) {
    pcVar6 = std::basic_streambuf<char,std::char_traits<char>_>::egptr(param_1);
    pcVar7 = std::basic_streambuf<char,std::char_traits<char>_>::gptr(param_1);
    if (pcVar7 < pcVar6) {
      pbVar8 = (byte *)std::basic_streambuf<char,std::char_traits<char>_>::_Gninc(param_1);
      return (uint)*pbVar8;
    }
  }
  if (*(longlong *)(param_1 + 0x80) == 0) {
    uVar12 = 0xffffffff;
  }
  else {
    pbVar9 = (basic_streambuf<char,std::char_traits<char>_> *)
             std::basic_streambuf<char,std::char_traits<char>_>::eback(param_1);
    if (pbVar9 == param_1 + 0x70) {
      std::basic_streambuf<char,std::char_traits<char>_>::setg
                (param_1,*(char **)(param_1 + 0x88),*(char **)(param_1 + 0x88),
                 *(char **)(param_1 + 0x90));
    }
    _File = *(FILE **)(param_1 + 0x80);
    if (*(longlong *)(param_1 + 0x68) == 0) {
      uVar4 = fgetc(_File);
      uVar12 = 0xffffffff;
      if (uVar4 != 0xffffffff) {
        uVar12 = uVar4 & 0xff;
      }
    }
    else {
      uStack_48 = 0;
      local_40 = 0;
      local_38 = 0xf;
      local_50 = (char ******)0x0;
LAB_18001bcde:
      iVar5 = fgetc(_File);
      uVar11 = local_38;
      sVar15 = local_40;
      if (iVar5 != -1) {
        cVar16 = (char)iVar5;
        if (local_40 < local_38) {
          pppppppcVar10 = &local_50;
          if (0xf < local_38) {
            pppppppcVar10 = (char *******)local_50;
          }
          pcVar6 = (char *)((longlong)pppppppcVar10 + local_40);
          local_40 = local_40 + 1;
          *pcVar6 = cVar16;
          *(char *)((longlong)pppppppcVar10 + sVar15 + 1) = '\0';
        }
        else {
          if (local_40 == 0x7fffffffffffffff) {
                    /* WARNING: Subroutine does not return */
            FUN_18000ace0();
          }
          uVar1 = local_40 + 1;
          uVar13 = uVar1 | 0xf;
          if (uVar13 < 0x8000000000000000) {
            if (0x7fffffffffffffff - (local_38 >> 1) < local_38) {
              uVar13 = 0x7fffffffffffffff;
              pppppppcVar10 = (char *******)FUN_180007f10(0x8000000000000000);
            }
            else {
              uVar2 = local_38 + (local_38 >> 1);
              if (uVar13 < uVar2) {
                uVar13 = uVar2;
              }
              uVar2 = uVar13 + 1;
              if (uVar2 < 0x1000) {
                if (uVar2 == 0) {
                  pppppppcVar10 = (char *******)0x0;
                }
                else {
                  pppppppcVar10 = operator_new(uVar2);
                }
              }
              else {
                pppppppcVar10 = (char *******)FUN_180007f10(uVar2);
              }
            }
          }
          else {
            uVar13 = 0x7fffffffffffffff;
            pppppppcVar10 = (char *******)FUN_180007f10(0x8000000000000000);
          }
          ppppppcVar3 = local_50;
          local_40 = uVar1;
          local_38 = uVar13;
          if (uVar11 < 0x10) {
            memcpy(pppppppcVar10,&local_50,sVar15);
            *(char *)((longlong)pppppppcVar10 + sVar15) = cVar16;
            *(char *)((longlong)pppppppcVar10 + sVar15 + 1) = '\0';
            local_50 = (char ******)pppppppcVar10;
          }
          else {
            memcpy(pppppppcVar10,local_50,sVar15);
            *(char *)((longlong)pppppppcVar10 + sVar15) = cVar16;
            *(char *)((longlong)pppppppcVar10 + sVar15 + 1) = '\0';
            pppppppcVar14 = (char *******)ppppppcVar3;
            if ((0xfff < uVar11 + 1) &&
               (pppppppcVar14 = (char *******)ppppppcVar3[-1],
               (char *)0x1f < (char *)((longlong)ppppppcVar3 + (-8 - (longlong)pppppppcVar14)))) {
                    /* WARNING: Subroutine does not return */
              _invalid_parameter_noinfo_noreturn();
            }
            operator_delete(pppppppcVar14);
            local_50 = (char ******)pppppppcVar10;
          }
        }
        pppppppcVar10 = &local_50;
        if (0xf < local_38) {
          pppppppcVar10 = (char *******)local_50;
        }
        iVar5 = std::codecvt<char,char,_Mbstatet>::in
                          (*(codecvt<char,char,_Mbstatet> **)(param_1 + 0x68),
                           (_Mbstatet *)(param_1 + 0x74),(char *)pppppppcVar10,
                           (char *)((longlong)pppppppcVar10 + local_40),&local_60,(char *)&local_68,
                           local_67,(char **)&local_58);
        if ((iVar5 == 0) || (iVar5 == 1)) {
          if (local_58 == &local_68) goto code_r0x00018001be98;
          pppppppcVar10 = &local_50;
          if (0xf < local_38) {
            pppppppcVar10 = (char *******)local_50;
          }
          pcVar6 = (char *)((longlong)pppppppcVar10 + (local_40 - (longlong)local_60));
          while (0 < (longlong)pcVar6) {
            pcVar6 = pcVar6 + -1;
            ungetc((int)pcVar6[(longlong)local_60],*(FILE **)(param_1 + 0x80));
          }
          uVar12 = (uint)local_68;
          goto LAB_18001bf4a;
        }
        if (iVar5 == 3) {
          pppppppcVar10 = &local_50;
          if (0xf < local_38) {
            pppppppcVar10 = (char *******)local_50;
          }
          uVar12 = (uint)*(char *)pppppppcVar10;
          goto LAB_18001bf4a;
        }
      }
      uVar12 = 0xffffffff;
LAB_18001bf4a:
      if (0xf < local_38) {
        pppppppcVar10 = (char *******)local_50;
        if ((0xfff < local_38 + 1) &&
           (pppppppcVar10 = (char *******)local_50[-1],
           (char *)0x1f < (char *)((longlong)local_50 + (-8 - (longlong)pppppppcVar10)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        operator_delete(pppppppcVar10);
      }
    }
  }
  return uVar12;
code_r0x00018001be98:
  pppppppcVar10 = &local_50;
  if (0xf < local_38) {
    pppppppcVar10 = (char *******)local_50;
  }
  uVar11 = (longlong)local_60 - (longlong)pppppppcVar10;
  if (local_40 < (ulonglong)((longlong)local_60 - (longlong)pppppppcVar10)) {
    uVar11 = local_40;
  }
  pppppppcVar10 = &local_50;
  if (0xf < local_38) {
    pppppppcVar10 = (char *******)local_50;
  }
  sVar15 = local_40 - uVar11;
  memmove(pppppppcVar10,(char *)((longlong)pppppppcVar10 + uVar11),sVar15 + 1);
  _File = *(FILE **)(param_1 + 0x80);
  local_40 = sVar15;
  goto LAB_18001bcde;
}

/* ---- FUNC 0001BFC0 FUN_18001bfc0 (124 bytes) ---- */

ulonglong FUN_18001bfc0(basic_streambuf<char,std::char_traits<char>_> *param_1)

{
  char *pcVar1;
  char *pcVar2;
  byte *pbVar3;
  ulonglong uVar4;
  
  pcVar1 = std::basic_streambuf<char,std::char_traits<char>_>::gptr(param_1);
  if (pcVar1 != (char *)0x0) {
    pcVar1 = std::basic_streambuf<char,std::char_traits<char>_>::egptr(param_1);
    pcVar2 = std::basic_streambuf<char,std::char_traits<char>_>::gptr(param_1);
    if (pcVar2 < pcVar1) {
      pbVar3 = (byte *)std::basic_streambuf<char,std::char_traits<char>_>::gptr(param_1);
      return (ulonglong)*pbVar3;
    }
  }
  uVar4 = (**(code **)(*(longlong *)param_1 + 0x38))(param_1);
  if ((int)uVar4 == -1) {
    return uVar4;
  }
  (**(code **)(*(longlong *)param_1 + 0x20))(param_1,uVar4 & 0xffffffff);
  return uVar4 & 0xffffffff;
}

/* ---- FUNC 0001C040 FUN_18001c040 (79 bytes) ---- */

longlong FUN_18001c040(basic_streambuf<char,std::char_traits<char>_> *param_1,char *param_2,
                      ulonglong param_3)

{
  __int64 _Var1;
  ulonglong uVar2;
  char *_Src;
  size_t sVar3;
  ulonglong _Count;
  ulonglong _Size;
  
  if ((longlong)param_3 < 1) {
    return 0;
  }
  if (*(longlong *)(param_1 + 0x68) != 0) {
                    /* WARNING: Could not recover jumptable at 0x00018001c088. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    _Var1 = std::basic_streambuf<char,std::char_traits<char>_>::xsgetn(param_1,param_2,param_3);
    return _Var1;
  }
  uVar2 = std::basic_streambuf<char,std::char_traits<char>_>::_Gnavail(param_1);
  _Count = param_3;
  if (uVar2 != 0) {
    _Size = param_3;
    if (uVar2 < param_3) {
      _Size = uVar2;
    }
    _Src = std::basic_streambuf<char,std::char_traits<char>_>::gptr(param_1);
    memcpy(param_2,_Src,_Size);
    param_2 = param_2 + _Size;
    _Count = param_3 - _Size;
    std::basic_streambuf<char,std::char_traits<char>_>::gbump(param_1,(int)_Size);
  }
  if (*(longlong *)(param_1 + 0x80) != 0) {
    FUN_18001b050(param_1);
    do {
      if (_Count < 0x1000) {
        if (_Count != 0) {
          sVar3 = fread(param_2,1,_Count,*(FILE **)(param_1 + 0x80));
          _Count = _Count - sVar3;
        }
        break;
      }
      sVar3 = fread(param_2,1,0xfff,*(FILE **)(param_1 + 0x80));
      _Count = _Count - sVar3;
      param_2 = param_2 + sVar3;
    } while (sVar3 == 0xfff);
  }
  return param_3 - _Count;
}

/* ---- FUNC 0001C08F FUN_18001c08f (227 bytes) ---- */

longlong FUN_18001c08f(basic_streambuf<char,std::char_traits<char>_> *param_1)

{
  ulonglong uVar1;
  char *_Src;
  size_t sVar2;
  ulonglong _Count;
  basic_streambuf<char,std::char_traits<char>_> *unaff_RBP;
  ulonglong unaff_RSI;
  ulonglong _Size;
  void *unaff_R14;
  
  uVar1 = std::basic_streambuf<char,std::char_traits<char>_>::_Gnavail(param_1);
  _Count = unaff_RSI;
  if (uVar1 != 0) {
    _Size = unaff_RSI;
    if (uVar1 < unaff_RSI) {
      _Size = uVar1;
    }
    _Src = std::basic_streambuf<char,std::char_traits<char>_>::gptr(unaff_RBP);
    memcpy(unaff_R14,_Src,_Size);
    unaff_R14 = (void *)((longlong)unaff_R14 + _Size);
    _Count = unaff_RSI - _Size;
    std::basic_streambuf<char,std::char_traits<char>_>::gbump(unaff_RBP,(int)_Size);
  }
  if (*(longlong *)(unaff_RBP + 0x80) != 0) {
    FUN_18001b050(unaff_RBP);
    do {
      if (_Count < 0x1000) {
        if (_Count != 0) {
          sVar2 = fread(unaff_R14,1,_Count,*(FILE **)(unaff_RBP + 0x80));
          _Count = _Count - sVar2;
        }
        break;
      }
      sVar2 = fread(unaff_R14,1,0xfff,*(FILE **)(unaff_RBP + 0x80));
      _Count = _Count - sVar2;
      unaff_R14 = (void *)((longlong)unaff_R14 + sVar2);
    } while (sVar2 == 0xfff);
  }
  return unaff_RSI - _Count;
}

/* ---- FUNC 0001C172 FUN_18001c172 (5 bytes) ---- */

longlong FUN_18001c172(void)

{
  longlong unaff_RBX;
  longlong unaff_RSI;
  
  return unaff_RSI - unaff_RBX;
}

/* ---- FUNC 0001C180 FUN_18001c180 (181 bytes) ---- */

longlong FUN_18001c180(basic_streambuf<char,std::char_traits<char>_> *param_1,char *param_2,
                      size_t param_3)

{
  __int64 _Var1;
  size_t sVar2;
  char *_Dst;
  size_t _Count;
  
  if (*(longlong *)(param_1 + 0x68) != 0) {
                    /* WARNING: Could not recover jumptable at 0x00018001c1a1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    _Var1 = std::basic_streambuf<char,std::char_traits<char>_>::xsputn(param_1,param_2,param_3);
    return _Var1;
  }
  sVar2 = std::basic_streambuf<char,std::char_traits<char>_>::_Pnavail(param_1);
  _Count = param_3;
  if (0 < (longlong)param_3) {
    if (0 < (longlong)sVar2) {
      if ((longlong)param_3 < (longlong)sVar2) {
        sVar2 = param_3;
      }
      _Dst = std::basic_streambuf<char,std::char_traits<char>_>::pptr(param_1);
      memcpy(_Dst,param_2,sVar2);
      param_2 = param_2 + sVar2;
      _Count = param_3 - sVar2;
      std::basic_streambuf<char,std::char_traits<char>_>::pbump(param_1,(int)sVar2);
      if ((longlong)_Count < 1) goto LAB_18001c21c;
    }
    if (*(FILE **)(param_1 + 0x80) != (FILE *)0x0) {
      sVar2 = fwrite(param_2,1,_Count,*(FILE **)(param_1 + 0x80));
      _Count = _Count - sVar2;
    }
  }
LAB_18001c21c:
  return param_3 - _Count;
}

/* ---- FUNC 0001C240 AddLibrary (25 bytes) ---- */

int AddLibrary(char *param_1)

{
  CApwnBlockUsage *pCVar1;
  int iVar2;
  
                    /* 0x1c240  276  AddLibrary */
  pCVar1 = g_pApwnBlockUsage;
  if (g_pApwnBlockUsage == (CApwnBlockUsage *)0x0) {
    return -0x7fffbffb;
  }
  iVar2 = CApwnLibraries::FindApwnLibrary(*(CApwnLibraries **)g_pApwnBlockUsage,param_1);
  if (iVar2 != -1) {
    return 0;
  }
  iVar2 = CApwnLibraries::AddNewLibrary(*(CApwnLibraries **)pCVar1,param_1,1);
  return iVar2;
}

/* ---- FUNC 0001C260 ApwnBlockAddModel (30 bytes) ---- */

void ApwnBlockAddModel(longlong *param_1,longlong *param_2,longlong *param_3)

{
                    /* 0x1c260  280  ApwnBlockAddModel */
  if (g_pApwnBlockUsage != (CApwnBlockUsage *)0x0) {
    FUN_180002640((longlong)g_pApwnBlockUsage,param_1,param_2,param_3);
    return;
  }
  return;
}

/* ---- FUNC 0001C280 ApwnBlockAddModel2 (43 bytes) ---- */

void ApwnBlockAddModel2(longlong *param_1,longlong *param_2,longlong *param_3,char *param_4)

{
                    /* 0x1c280  281  ApwnBlockAddModel2 */
  if (g_pApwnBlockUsage != (CApwnBlockUsage *)0x0) {
    FUN_1800029b0((longlong)g_pApwnBlockUsage,param_1,param_2,param_3,param_4);
  }
  return;
}

/* ---- FUNC 0001C2B0 ApwnBlockAddReference (71 bytes) ---- */

CSimpleStringT<char,1> *
ApwnBlockAddReference
          (char *param_1,char *param_2,char *param_3,char *param_4,
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_5,int param_6)

{
  CSimpleStringT<char,1> *pCVar1;
  
                    /* 0x1c2b0  282  ApwnBlockAddReference */
  if (g_pApwnBlockUsage != (CApwnBlockUsage *)0x0) {
    pCVar1 = FUN_180002190((undefined8 *)g_pApwnBlockUsage,param_1,param_2,param_3,param_4,param_5,
                           param_6);
    return pCVar1;
  }
  return (CSimpleStringT<char,1> *)0x80004005;
}

/* ---- FUNC 0001C300 ApwnBlockAssignModel (27 bytes) ---- */

void ApwnBlockAssignModel(char *param_1,longlong *param_2)

{
                    /* 0x1c300  283  ApwnBlockAssignModel */
  if (g_pApwnBlockUsage != (CApwnBlockUsage *)0x0) {
    FUN_180002db0(g_pApwnBlockUsage,param_1,param_2);
    return;
  }
  return;
}

/* ---- FUNC 0001C320 ApwnBlockChangeModelType (68 bytes) ---- */

void ApwnBlockChangeModelType(char *param_1,longlong *param_2)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar1;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res18 [16];
  
                    /* 0x1c320  284  ApwnBlockChangeModelType */
  if (g_pApwnBlockUsage != (CApwnBlockUsage *)0x0) {
    pCVar1 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res18,param_1);
    FUN_180003bc0((longlong)g_pApwnBlockUsage,pCVar1,param_2);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res18);
  }
  return;
}

/* ---- FUNC 0001C370 ApwnBlockFindModel (83 bytes) ---- */

ulonglong ApwnBlockFindModel(char *param_1,undefined8 *param_2)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar1;
  ulonglong uVar2;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res18 [16];
  
                    /* 0x1c370  285  ApwnBlockFindModel */
  if (g_pApwnBlockUsage != (CApwnBlockUsage *)0x0) {
    pCVar1 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res18,param_1);
    uVar2 = FUN_180003c80((longlong)g_pApwnBlockUsage,pCVar1,param_2);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res18);
    return uVar2 & 0xffffffff;
  }
  return 0x80004005;
}

/* ---- FUNC 0001C3D0 ApwnBlockGetSaveSize (19 bytes) ---- */

int ApwnBlockGetSaveSize(void)

{
  longlong lVar1;
  CApwnBlockUsage *pCVar2;
  int iVar3;
  ulonglong uVar4;
  int iVar5;
  uint uVar6;
  ulonglong uVar7;
  
                    /* 0x1c3d0  286  ApwnBlockGetSaveSize */
  pCVar2 = g_pApwnBlockUsage;
  if (g_pApwnBlockUsage == (CApwnBlockUsage *)0x0) {
    return 0;
  }
  lVar1 = *(longlong *)(g_pApwnBlockUsage + 0x18);
  uVar4 = 0;
  iVar5 = 4;
  uVar7 = uVar4;
  if (0 < lVar1) {
    do {
      if (((longlong)uVar4 < 0) || (lVar1 <= (longlong)uVar4)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      iVar3 = FUN_180004220(*(longlong **)(*(longlong *)(pCVar2 + 0x10) + uVar4 * 8));
      uVar6 = (int)uVar7 + 1;
      iVar5 = iVar5 + iVar3;
      uVar4 = uVar4 + 1;
      uVar7 = (ulonglong)uVar6;
    } while ((int)uVar6 < lVar1);
  }
  return iVar5;
}

/* ---- FUNC 0001C3F0 ApwnBlockMarkBlocks (19 bytes) ---- */

void ApwnBlockMarkBlocks(undefined4 param_1)

{
  int iVar1;
  longlong lVar2;
  CApwnBlockUsage *pCVar3;
  longlong lVar4;
  
                    /* 0x1c3f0  287  ApwnBlockMarkBlocks */
  pCVar3 = g_pApwnBlockUsage;
  if (g_pApwnBlockUsage == (CApwnBlockUsage *)0x0) {
    return;
  }
  iVar1 = *(int *)(g_pApwnBlockUsage + 0x18);
  if (0 < (longlong)iVar1) {
    lVar4 = 0;
    do {
      if ((lVar4 < 0) || (*(longlong *)(pCVar3 + 0x18) <= lVar4)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      lVar2 = *(longlong *)(*(longlong *)(pCVar3 + 0x10) + lVar4 * 8);
      if (lVar2 != 0) {
        *(undefined4 *)(lVar2 + 0x3c) = param_1;
      }
      lVar4 = lVar4 + 1;
    } while (lVar4 < iVar1);
  }
  return;
}

/* ---- FUNC 0001C410 ApwnBlockPartialRename (46 bytes) ---- */

void ApwnBlockPartialRename(char *param_1,char *param_2)

{
                    /* 0x1c410  288  ApwnBlockPartialRename */
  if (g_pApwnBlockUsage != (CApwnBlockUsage *)0x0) {
    FUN_180004780((longlong)g_pApwnBlockUsage,param_1,param_2,0,0);
  }
  return;
}

/* ---- FUNC 0001C440 ApwnBlockRemoveModel (20 bytes) ---- */

void ApwnBlockRemoveModel(longlong *param_1)

{
  CApwnBlockUsage *pCVar1;
  char *pcVar2;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> aCStackX_18 [16];
  
                    /* 0x1c440  289  ApwnBlockRemoveModel */
  pCVar1 = g_pApwnBlockUsage;
  if (g_pApwnBlockUsage == (CApwnBlockUsage *)0x0) {
    return;
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(aCStackX_18);
  pcVar2 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)aCStackX_18,0x40);
  FUN_180003e00(param_1,pcVar2,0x3f);
  ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)aCStackX_18,-1);
  FUN_180004af0((longlong)pCVar1,aCStackX_18);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(aCStackX_18);
  return;
}

/* ---- FUNC 0001C460 ApwnBlockRemoveModelByName (59 bytes) ---- */

void ApwnBlockRemoveModelByName(char *param_1)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar1;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res10 [24];
  
                    /* 0x1c460  290  ApwnBlockRemoveModelByName */
  if (g_pApwnBlockUsage != (CApwnBlockUsage *)0x0) {
    pCVar1 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res10,param_1);
    FUN_180004af0((longlong)g_pApwnBlockUsage,pCVar1);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res10);
  }
  return;
}

/* ---- FUNC 0001C4A0 ApwnBlockRemoveUnmarked (17 bytes) ---- */

void ApwnBlockRemoveUnmarked(void)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar1;
  CApwnBlockUsage *pCVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  
                    /* 0x1c4a0  291  ApwnBlockRemoveUnmarked */
  pCVar2 = g_pApwnBlockUsage;
  if (g_pApwnBlockUsage == (CApwnBlockUsage *)0x0) {
    return;
  }
  lVar3 = *(longlong *)(g_pApwnBlockUsage + 0x18);
  uVar4 = 0;
  uVar5 = uVar4;
  if (0 < lVar3) {
    do {
      if (((longlong)uVar4 < 0) || (lVar3 <= (longlong)uVar4)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      pCVar1 = *(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> **)
                (*(longlong *)(pCVar2 + 0x10) + uVar4 * 8);
      if ((pCVar1 == (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) ||
         (*(int *)(pCVar1 + 0x3c) != 0)) {
        uVar5 = (ulonglong)((int)uVar5 + 1);
        uVar4 = uVar4 + 1;
      }
      else {
        FUN_180001ce0(pCVar1);
        operator_delete(pCVar1);
        CPtrArray::RemoveAt((CPtrArray *)(pCVar2 + 8),(longlong)(int)uVar5,1);
      }
      lVar3 = *(longlong *)(pCVar2 + 0x18);
    } while ((int)uVar5 < lVar3);
  }
  return;
}

/* ---- FUNC 0001C4C0 ApwnBlockRenameModel (20 bytes) ---- */

void ApwnBlockRenameModel(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  CApwnBlockUsage *pCVar3;
  longlong lVar4;
  ulonglong uVar5;
  uint uVar6;
  ulonglong uVar7;
  
                    /* 0x1c4c0  292  ApwnBlockRenameModel */
  pCVar3 = g_pApwnBlockUsage;
  if (g_pApwnBlockUsage == (CApwnBlockUsage *)0x0) {
    return;
  }
  lVar1 = *(longlong *)(g_pApwnBlockUsage + 0x18);
  uVar5 = 0;
  uVar7 = uVar5;
  if (0 < lVar1) {
    do {
      if (((longlong)uVar5 < 0) || (lVar1 <= (longlong)uVar5)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      lVar2 = *(longlong *)(*(longlong *)(pCVar3 + 0x10) + uVar5 * 8);
      lVar4 = FUN_180003f70(lVar2);
      if (param_1 == lVar4) {
        FUN_180004d90(lVar2);
        return;
      }
      uVar6 = (int)uVar7 + 1;
      uVar5 = uVar5 + 1;
      uVar7 = (ulonglong)uVar6;
    } while ((int)uVar6 < lVar1);
  }
  return;
}

/* ---- FUNC 0001C4E0 ApwnBlockRenameNew (37 bytes) ---- */

void ApwnBlockRenameNew(longlong param_1,undefined8 *param_2,int param_3)

{
  char *pcVar1;
  CApwnBlockUsage *pCVar2;
  undefined8 *puVar3;
  int iVar4;
  
                    /* 0x1c4e0  293  ApwnBlockRenameNew */
  if ((g_pApwnBlockUsage != (CApwnBlockUsage *)0x0) && (iVar4 = 0, 0 < param_3)) {
    pCVar2 = g_pApwnBlockUsage;
    puVar3 = param_2;
    do {
      pcVar1 = *(char **)((param_1 - (longlong)param_2) + (longlong)puVar3);
      if (pcVar1 == (char *)0x0) {
        return;
      }
      if ((param_2 != (undefined8 *)0x0) && ((char *)*puVar3 != (char *)0x0)) {
        FUN_180004780((longlong)pCVar2,pcVar1,(char *)*puVar3,1,1);
        pCVar2 = g_pApwnBlockUsage;
      }
      iVar4 = iVar4 + 1;
      puVar3 = puVar3 + 1;
    } while (iVar4 < param_3);
  }
  return;
}

/* ---- FUNC 0001C505 FUN_18001c505 (12 bytes) ---- */

void FUN_18001c505(CApwnBlockUsage *param_1,undefined8 *param_2,int param_3)

{
  char *pcVar1;
  int unaff_EBP;
  longlong unaff_RSI;
  int iVar2;
  longlong unaff_R14;
  longlong lVar3;
  
  iVar2 = 0;
  if (0 < param_3) {
    lVar3 = unaff_R14 - (longlong)param_2;
    do {
      pcVar1 = *(char **)(lVar3 + (longlong)param_2);
      if (pcVar1 == (char *)0x0) {
        return;
      }
      if ((unaff_RSI != 0) && ((char *)*param_2 != (char *)0x0)) {
        FUN_180004780((longlong)param_1,pcVar1,(char *)*param_2,1,1);
        param_1 = g_pApwnBlockUsage;
      }
      iVar2 = iVar2 + 1;
      param_2 = param_2 + 1;
    } while (iVar2 < unaff_EBP);
  }
  return;
}

/* ---- FUNC 0001C511 FUN_18001c511 (78 bytes) ---- */

void FUN_18001c511(CApwnBlockUsage *param_1,undefined8 *param_2)

{
  char *pcVar1;
  int unaff_EBP;
  longlong unaff_RSI;
  int unaff_EDI;
  longlong unaff_R14;
  longlong lVar2;
  
  lVar2 = unaff_R14 - (longlong)param_2;
  do {
    pcVar1 = *(char **)(lVar2 + (longlong)param_2);
    if (pcVar1 == (char *)0x0) {
      return;
    }
    if ((unaff_RSI != 0) && ((char *)*param_2 != (char *)0x0)) {
      FUN_180004780((longlong)param_1,pcVar1,(char *)*param_2,1,1);
      param_1 = g_pApwnBlockUsage;
    }
    unaff_EDI = unaff_EDI + 1;
    param_2 = param_2 + 1;
  } while (unaff_EDI < unaff_EBP);
  return;
}

/* ---- FUNC 0001C55F FUN_18001c55f (5 bytes) ---- */

void FUN_18001c55f(void)

{
  return;
}

/* ---- FUNC 0001C564 FUN_18001c564 (17 bytes) ---- */

void FUN_18001c564(void)

{
  return;
}

/* ---- FUNC 0001C580 ApwnBlockRestore (27 bytes) ---- */

void ApwnBlockRestore(int *param_1,HWND param_2)

{
                    /* 0x1c580  294  ApwnBlockRestore */
  if (g_pApwnBlockUsage != (CApwnBlockUsage *)0x0) {
    FUN_180004e00(g_pApwnBlockUsage,param_1,param_2);
    return;
  }
  return;
}

/* ---- FUNC 0001C5A0 ApwnBlockRestoreFromText (59 bytes) ---- */

undefined8 ApwnBlockRestoreFromText(longlong *param_1,char *param_2)

{
                    /* 0x1c5a0  295  ApwnBlockRestoreFromText */
  if (g_pApwnBlockUsage != (CApwnBlockUsage *)0x0) {
    FUN_180005d90(g_pApwnBlockUsage,param_1,(HWND)0x0,param_2,(CMapStringToString *)0x0);
    return 1;
  }
  return 0;
}

/* ---- FUNC 0001C5E0 ApwnBlockRestoreFromText2 (41 bytes) ---- */

undefined8
ApwnBlockRestoreFromText2
          (longlong *param_1,char *param_2,int param_3,longlong *param_4,longlong param_5)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this;
  char *pcVar1;
  longlong lVar2;
  int iVar3;
  char *local_68;
  CMapStringToString local_60 [56];
  
                    /* 0x1c5e0  296  ApwnBlockRestoreFromText2 */
  if (g_pApwnBlockUsage == (CApwnBlockUsage *)0x0) {
    return 0;
  }
  CMapStringToString::CMapStringToString(local_60,(longlong)param_3);
  iVar3 = 0;
  if (0 < param_3) {
    lVar2 = param_5 - (longlong)param_4;
    do {
      if (*param_4 == 0) break;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_68);
      if ((param_5 == 0) || (pcVar1 = *(char **)(lVar2 + (longlong)param_4), pcVar1 == (char *)0x0))
      {
        pcVar1 = (char *)*param_4;
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_68,pcVar1);
      pcVar1 = local_68;
      this = CMapStringToString::operator[](local_60,(char *)*param_4);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(this,pcVar1);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_68);
      iVar3 = iVar3 + 1;
      param_4 = param_4 + 1;
    } while (iVar3 < param_3);
  }
  FUN_180005d90(g_pApwnBlockUsage,param_1,(HWND)0x0,param_2,(CMapStringToString *)0x0);
  CMapStringToString::~CMapStringToString(local_60);
  return 1;
}

/* ---- FUNC 0001C609 FUN_18001c609 (27 bytes) ---- */

undefined8 FUN_18001c609(undefined8 param_1,__int64 param_2)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this;
  char *pcVar1;
  longlong *unaff_RBX;
  longlong lVar2;
  char *unaff_R12;
  longlong *unaff_R13;
  int iVar3;
  int unaff_R15D;
  char *in_stack_00000030;
  longlong in_stack_000000c0;
  
  CMapStringToString::CMapStringToString((CMapStringToString *)&stack0x00000038,param_2);
  iVar3 = 0;
  if (0 < unaff_R15D) {
    lVar2 = in_stack_000000c0 - (longlong)unaff_RBX;
    do {
      if (*unaff_RBX == 0) break;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&stack0x00000030);
      if ((in_stack_000000c0 == 0) ||
         (pcVar1 = *(char **)(lVar2 + (longlong)unaff_RBX), pcVar1 == (char *)0x0)) {
        pcVar1 = (char *)*unaff_RBX;
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&stack0x00000030,
                 pcVar1);
      pcVar1 = in_stack_00000030;
      this = CMapStringToString::operator[]
                       ((CMapStringToString *)&stack0x00000038,(char *)*unaff_RBX);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(this,pcVar1);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&stack0x00000030);
      iVar3 = iVar3 + 1;
      unaff_RBX = unaff_RBX + 1;
    } while (iVar3 < unaff_R15D);
  }
  FUN_180005d90(g_pApwnBlockUsage,unaff_R13,(HWND)0x0,unaff_R12,(CMapStringToString *)0x0);
  CMapStringToString::~CMapStringToString((CMapStringToString *)&stack0x00000038);
  return 1;
}

/* ---- FUNC 0001C624 FUN_18001c624 (166 bytes) ---- */

undefined8 FUN_18001c624(void)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this;
  char *pcVar1;
  longlong *unaff_RBX;
  longlong lVar2;
  char *unaff_R12;
  longlong *unaff_R13;
  int unaff_R14D;
  int unaff_R15D;
  char *in_stack_00000030;
  longlong in_stack_000000c0;
  
  lVar2 = in_stack_000000c0 - (longlong)unaff_RBX;
  do {
    if (*unaff_RBX == 0) break;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&stack0x00000030);
    if ((in_stack_000000c0 == 0) ||
       (pcVar1 = *(char **)(lVar2 + (longlong)unaff_RBX), pcVar1 == (char *)0x0)) {
      pcVar1 = (char *)*unaff_RBX;
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&stack0x00000030,
               pcVar1);
    pcVar1 = in_stack_00000030;
    this = CMapStringToString::operator[]((CMapStringToString *)&stack0x00000038,(char *)*unaff_RBX)
    ;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(this,pcVar1);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&stack0x00000030);
    unaff_R14D = unaff_R14D + 1;
    unaff_RBX = unaff_RBX + 1;
  } while (unaff_R14D < unaff_R15D);
  FUN_180005d90(g_pApwnBlockUsage,unaff_R13,(HWND)0x0,unaff_R12,(CMapStringToString *)0x0);
  CMapStringToString::~CMapStringToString((CMapStringToString *)&stack0x00000038);
  return 1;
}

/* ---- FUNC 0001C6CA FUN_18001c6ca (62 bytes) ---- */

undefined8 FUN_18001c6ca(void)

{
  char *unaff_R12;
  longlong *unaff_R13;
  
  FUN_180005d90(g_pApwnBlockUsage,unaff_R13,(HWND)0x0,unaff_R12,(CMapStringToString *)0x0);
  CMapStringToString::~CMapStringToString((CMapStringToString *)&stack0x00000038);
  return 1;
}

/* ---- FUNC 0001C708 FUN_18001c708 (14 bytes) ---- */

undefined8 FUN_18001c708(void)

{
  return 0;
}

/* ---- FUNC 0001C720 ApwnBlockSave (20 bytes) ---- */

void ApwnBlockSave(undefined4 *param_1)

{
  longlong *plVar1;
  CApwnBlockUsage *pCVar2;
  int iVar3;
  longlong lVar4;
  ulonglong uVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined4 *puVar8;
  
                    /* 0x1c720  297  ApwnBlockSave */
  pCVar2 = g_pApwnBlockUsage;
  if (g_pApwnBlockUsage == (CApwnBlockUsage *)0x0) {
    return;
  }
  puVar8 = param_1 + 1;
  *param_1 = *(undefined4 *)(g_pApwnBlockUsage + 0x18);
  uVar5 = 0;
  lVar4 = *(longlong *)(pCVar2 + 0x18);
  uVar7 = uVar5;
  if (0 < lVar4) {
    do {
      if (((longlong)uVar5 < 0) || (lVar4 <= (longlong)uVar5)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      plVar1 = *(longlong **)(*(longlong *)(pCVar2 + 0x10) + uVar5 * 8);
      iVar3 = FUN_180004220(plVar1);
      FUN_180007190(plVar1,puVar8);
      lVar4 = *(longlong *)(pCVar2 + 0x18);
      uVar6 = (int)uVar7 + 1;
      puVar8 = (undefined4 *)((longlong)puVar8 + (longlong)iVar3);
      uVar5 = uVar5 + 1;
      uVar7 = (ulonglong)uVar6;
    } while ((int)uVar6 < lVar4);
  }
  return;
}

/* ---- FUNC 0001C740 ApwnBlockSaveToText (41 bytes) ---- */

undefined8 ApwnBlockSaveToText(longlong *param_1)

{
                    /* 0x1c740  298  ApwnBlockSaveToText */
  if (g_pApwnBlockUsage != (CApwnBlockUsage *)0x0) {
    FUN_180007290((longlong)g_pApwnBlockUsage,param_1);
    return 1;
  }
  return 0;
}

/* ---- FUNC 0001C770 ApwnBlockSaveToText2 (43 bytes) ---- */

void ApwnBlockSaveToText2(longlong *param_1,longlong *param_2,longlong param_3,int param_4)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this;
  char *pcVar1;
  longlong lVar2;
  int iVar3;
  char *local_58;
  CMapStringToString local_50 [56];
  
                    /* 0x1c770  299  ApwnBlockSaveToText2 */
  if (g_pApwnBlockUsage != (CApwnBlockUsage *)0x0) {
    CMapStringToString::CMapStringToString(local_50,(longlong)param_4);
    iVar3 = 0;
    if (0 < param_4) {
      lVar2 = param_3 - (longlong)param_2;
      do {
        if (*param_2 == 0) break;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_58);
        if ((param_3 == 0) ||
           (pcVar1 = *(char **)(lVar2 + (longlong)param_2), pcVar1 == (char *)0x0)) {
          pcVar1 = (char *)*param_2;
        }
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_58,pcVar1
                  );
        pcVar1 = local_58;
        this = CMapStringToString::operator[](local_50,(char *)*param_2);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(this,pcVar1);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_58);
        iVar3 = iVar3 + 1;
        param_2 = param_2 + 1;
      } while (iVar3 < param_4);
    }
    FUN_1800073c0((longlong)g_pApwnBlockUsage,param_1,local_50);
    CMapStringToString::~CMapStringToString(local_50);
  }
  return;
}

/* ---- FUNC 0001C79B FUN_18001c79b (30 bytes) ---- */

void FUN_18001c79b(undefined8 param_1,__int64 param_2)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this;
  char *pcVar1;
  longlong *unaff_RBX;
  longlong unaff_RBP;
  longlong lVar2;
  longlong *unaff_R12;
  int iVar3;
  int unaff_R15D;
  char *pcStackX_20;
  
  CMapStringToString::CMapStringToString((CMapStringToString *)&stack0x00000028,param_2);
  iVar3 = 0;
  if (0 < unaff_R15D) {
    lVar2 = unaff_RBP - (longlong)unaff_RBX;
    do {
      if (*unaff_RBX == 0) break;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&pcStackX_20);
      if ((unaff_RBP == 0) ||
         (pcVar1 = *(char **)(lVar2 + (longlong)unaff_RBX), pcVar1 == (char *)0x0)) {
        pcVar1 = (char *)*unaff_RBX;
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&pcStackX_20,
                 pcVar1);
      pcVar1 = pcStackX_20;
      this = CMapStringToString::operator[]
                       ((CMapStringToString *)&stack0x00000028,(char *)*unaff_RBX);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(this,pcVar1);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&pcStackX_20);
      iVar3 = iVar3 + 1;
      unaff_RBX = unaff_RBX + 1;
    } while (iVar3 < unaff_R15D);
  }
  FUN_1800073c0((longlong)g_pApwnBlockUsage,unaff_R12,(CMapStringToString *)&stack0x00000028);
  CMapStringToString::~CMapStringToString((CMapStringToString *)&stack0x00000028);
  return;
}

/* ---- FUNC 0001C7B9 FUN_18001c7b9 (137 bytes) ---- */

void FUN_18001c7b9(void)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this;
  char *pcVar1;
  longlong *unaff_RBX;
  longlong unaff_RBP;
  longlong lVar2;
  longlong *unaff_R12;
  int unaff_R14D;
  int unaff_R15D;
  char *pcStackX_20;
  
  lVar2 = unaff_RBP - (longlong)unaff_RBX;
  do {
    if (*unaff_RBX == 0) break;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&pcStackX_20);
    if ((unaff_RBP == 0) ||
       (pcVar1 = *(char **)(lVar2 + (longlong)unaff_RBX), pcVar1 == (char *)0x0)) {
      pcVar1 = (char *)*unaff_RBX;
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&pcStackX_20,pcVar1)
    ;
    pcVar1 = pcStackX_20;
    this = CMapStringToString::operator[]((CMapStringToString *)&stack0x00000028,(char *)*unaff_RBX)
    ;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(this,pcVar1);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&pcStackX_20);
    unaff_R14D = unaff_R14D + 1;
    unaff_RBX = unaff_RBX + 1;
  } while (unaff_R14D < unaff_R15D);
  FUN_1800073c0((longlong)g_pApwnBlockUsage,unaff_R12,(CMapStringToString *)&stack0x00000028);
  CMapStringToString::~CMapStringToString((CMapStringToString *)&stack0x00000028);
  return;
}

/* ---- FUNC 0001C842 FUN_18001c842 (38 bytes) ---- */

void FUN_18001c842(void)

{
  longlong *unaff_R12;
  
  FUN_1800073c0((longlong)g_pApwnBlockUsage,unaff_R12,(CMapStringToString *)&stack0x00000028);
  CMapStringToString::~CMapStringToString((CMapStringToString *)&stack0x00000028);
  return;
}

/* ---- FUNC 0001C868 FUN_18001c868 (18 bytes) ---- */

void FUN_18001c868(void)

{
  return;
}

/* ---- FUNC 0001C880 CAddRef (13 bytes) ---- */

void CAddRef(longlong *param_1)

{
                    /* 0x1c880  320  CAddRef */
  if (param_1 != (longlong *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00018001c888. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 8))();
    return;
  }
  return;
}

/* ---- FUNC 0001C890 CRelease (13 bytes) ---- */

void CRelease(longlong *param_1)

{
                    /* 0x1c890  321  CRelease */
  if (param_1 != (longlong *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00018001c898. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x10))();
    return;
  }
  return;
}

/* ---- FUNC 0001C8A0 CheckSignalReadGraphics (7 bytes) ---- */

undefined4 CheckSignalReadGraphics(void)

{
                    /* 0x1c8a0  338  CheckSignalReadGraphics */
  return DAT_18007a26c;
}

/* ---- FUNC 0001C8B0 CreateBufferStream (107 bytes) ---- */

longlong * CreateBufferStream(undefined8 param_1,undefined4 param_2,longlong param_3)

{
  undefined8 *puVar1;
  longlong *plVar2;
  
                    /* 0x1c8b0  341  CreateBufferStream */
  puVar1 = operator_new(0x130);
  if (puVar1 != (undefined8 *)0x0) {
    plVar2 = FUN_180018790(puVar1,param_3,param_1,param_2);
    if (plVar2 != (longlong *)0x0) {
      (**(code **)(*plVar2 + 8))(plVar2);
      return plVar2;
    }
  }
  return (longlong *)0x0;
}

/* ---- FUNC 0001C920 GetBlockIdsFromCArestoreMap (30 bytes) ---- */

void GetBlockIdsFromCArestoreMap(longlong *param_1)

{
  char cVar1;
  longlong *plVar2;
  ulonglong uVar3;
  size_t sVar4;
  int iVar5;
  longlong *_Buf1;
  longlong *_Buf2;
  longlong *plVar6;
  longlong *plVar7;
  
                    /* 0x1c920  356  GetBlockIdsFromCArestoreMap */
  plVar6 = (longlong *)*DAT_18007a278;
  if (plVar6 != DAT_18007a278) {
    do {
      plVar2 = (longlong *)param_1[1];
      plVar7 = (longlong *)*param_1;
      if (plVar7 == plVar2) {
LAB_18001c9af:
        if (plVar2 == (longlong *)param_1[2]) {
          FUN_180017980(param_1,plVar2,plVar6 + 4);
        }
        else {
          FUN_180018500(plVar2,plVar6 + 4);
          param_1[1] = param_1[1] + 0x20;
        }
      }
      else {
        uVar3 = plVar6[7];
        sVar4 = plVar6[6];
        do {
          _Buf2 = plVar6 + 4;
          if (0xf < uVar3) {
            _Buf2 = (longlong *)plVar6[4];
          }
          _Buf1 = plVar7;
          if (0xf < (ulonglong)plVar7[3]) {
            _Buf1 = (longlong *)*plVar7;
          }
        } while (((plVar7[2] != sVar4) || (iVar5 = memcmp(_Buf1,_Buf2,plVar7[2]), iVar5 != 0)) &&
                (plVar7 = plVar7 + 4, plVar7 != plVar2));
        if (plVar7 == plVar2) goto LAB_18001c9af;
      }
      plVar2 = (longlong *)plVar6[2];
      if (*(char *)((longlong)plVar2 + 0x19) == '\0') {
        cVar1 = *(char *)(*plVar2 + 0x19);
        plVar6 = plVar2;
        plVar2 = (longlong *)*plVar2;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*plVar2 + 0x19);
          plVar6 = plVar2;
          plVar2 = (longlong *)*plVar2;
        }
      }
      else {
        cVar1 = *(char *)(plVar6[1] + 0x19);
        plVar7 = (longlong *)plVar6[1];
        plVar2 = plVar6;
        while ((plVar6 = plVar7, cVar1 == '\0' && (plVar2 == (longlong *)plVar6[2]))) {
          cVar1 = *(char *)(plVar6[1] + 0x19);
          plVar7 = (longlong *)plVar6[1];
          plVar2 = plVar6;
        }
      }
    } while (plVar6 != DAT_18007a278);
  }
  return;
}

/* ---- FUNC 0001C93E FUN_18001c93e (279 bytes) ---- */

void FUN_18001c93e(void)

{
  char cVar1;
  longlong *plVar2;
  ulonglong uVar3;
  size_t sVar4;
  int iVar5;
  longlong *_Buf1;
  longlong *_Buf2;
  longlong *unaff_RBX;
  longlong *plVar6;
  longlong *unaff_R15;
  
  do {
    plVar2 = (longlong *)unaff_R15[1];
    plVar6 = (longlong *)*unaff_R15;
    if (plVar6 == plVar2) {
LAB_18001c9af:
      if (plVar2 == (longlong *)unaff_R15[2]) {
        FUN_180017980(unaff_R15,plVar2,unaff_RBX + 4);
      }
      else {
        FUN_180018500(plVar2,unaff_RBX + 4);
        unaff_R15[1] = unaff_R15[1] + 0x20;
      }
    }
    else {
      uVar3 = unaff_RBX[7];
      sVar4 = unaff_RBX[6];
      do {
        _Buf2 = unaff_RBX + 4;
        if (0xf < uVar3) {
          _Buf2 = (longlong *)unaff_RBX[4];
        }
        _Buf1 = plVar6;
        if (0xf < (ulonglong)plVar6[3]) {
          _Buf1 = (longlong *)*plVar6;
        }
      } while (((plVar6[2] != sVar4) || (iVar5 = memcmp(_Buf1,_Buf2,plVar6[2]), iVar5 != 0)) &&
              (plVar6 = plVar6 + 4, plVar6 != plVar2));
      if (plVar6 == plVar2) goto LAB_18001c9af;
    }
    plVar2 = (longlong *)unaff_RBX[2];
    if (*(char *)((longlong)plVar2 + 0x19) == '\0') {
      cVar1 = *(char *)(*plVar2 + 0x19);
      unaff_RBX = plVar2;
      plVar2 = (longlong *)*plVar2;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*plVar2 + 0x19);
        unaff_RBX = plVar2;
        plVar2 = (longlong *)*plVar2;
      }
    }
    else {
      cVar1 = *(char *)(unaff_RBX[1] + 0x19);
      plVar6 = (longlong *)unaff_RBX[1];
      plVar2 = unaff_RBX;
      while ((unaff_RBX = plVar6, cVar1 == '\0' && (plVar2 == (longlong *)unaff_RBX[2]))) {
        cVar1 = *(char *)(unaff_RBX[1] + 0x19);
        plVar6 = (longlong *)unaff_RBX[1];
        plVar2 = unaff_RBX;
      }
    }
    if (unaff_RBX == DAT_18007a278) {
      return;
    }
  } while( true );
}

/* ---- FUNC 0001CA55 FUN_18001ca55 (8 bytes) ---- */

void FUN_18001ca55(void)

{
  return;
}

/* ---- FUNC 0001CA60 GetGlobalMemory (69 bytes) ---- */

void GetGlobalMemory(int param_1,undefined8 *param_2,undefined8 *param_3)

{
  HGLOBAL hMem;
  LPVOID pvVar1;
  
                    /* 0x1ca60  361  GetGlobalMemory */
  hMem = GlobalAlloc(0x2002,(longlong)param_1);
  pvVar1 = GlobalLock(hMem);
  *param_3 = pvVar1;
  *param_2 = hMem;
  return;
}

/* ---- FUNC 0001CAB0 FUN_18001cab0 (166 bytes) ---- */

undefined8 FUN_18001cab0(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_1)

{
  longlong lVar1;
  char *pcVar2;
  IAtlStringMgr *pIVar3;
  longlong lVar4;
  char *local_res10;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res18 [16];
  longlong lVar5;
  
  pcVar2 = (char *)GetGlobalPointer("MMCOMMONXEQ");
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res10,pcVar2);
  if (0 < *(int *)(local_res10 + -0x10)) {
    pIVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                       ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                        &local_res10);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res18,pIVar3);
    lVar5 = -1;
    do {
      lVar4 = lVar5 + 1;
      lVar1 = lVar5 + 1;
      lVar5 = lVar4;
    } while ("\\Html5helpMapfiles\\mapranges.txt"[lVar1] != '\0');
    ATL::CSimpleStringT<char,1>::Concatenate
              ((CSimpleStringT<char,1> *)local_res18,local_res10,*(int *)(local_res10 + -0x10),
               "\\Html5helpMapfiles\\mapranges.txt",(int)lVar4);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              (param_1,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                       local_res18);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res18);
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res10);
  return 1;
}

/* ---- FUNC 0001CB60 GetHtml5HelpMapUrl (3161 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void GetHtml5HelpMapUrl(char *param_1,char *param_2,longlong param_3)

{
  char cVar1;
  undefined4 *puVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar6;
  char *pcVar7;
  ulonglong uVar8;
  IAtlStringMgr *pIVar9;
  longlong lVar10;
  undefined8 *puVar11;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar12;
  basic_streambuf<char,std::char_traits<char>_> *pbVar13;
  longlong *plVar14;
  undefined1 (*pauVar15) [32];
  undefined1 (*pauVar16) [32];
  undefined1 (*pauVar17) [32];
  undefined4 *puVar18;
  longlong lVar19;
  undefined1 (*pauVar20) [32];
  undefined ***pppuVar21;
  undefined ***pppuVar22;
  undefined1 auStackY_338 [32];
  char *local_308;
  char *local_300;
  char *local_2f8;
  undefined8 local_2f0;
  char *local_2e8;
  char *local_2e0;
  char *local_2d8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_2d0 [8];
  char *local_2c8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_2c0 [4];
  int iStack_2bc;
  undefined *local_2b8 [2];
  undefined **local_2a8;
  basic_istream<char,std::char_traits<char>_> local_2a0 [96];
  undefined8 local_240;
  char local_238 [4];
  undefined8 local_234;
  undefined1 local_22c;
  FILE *local_228;
  char *local_220;
  char *local_218;
  basic_ios<char,std::char_traits<char>_> local_208 [96];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_1a8 [8];
  undefined1 (*local_1a0) [32];
  undefined8 uStack_198;
  longlong local_190;
  ulonglong local_188;
  undefined1 local_180 [55];
  undefined4 uStack_149;
  ulonglong local_38;
  
                    /* 0x1cb60  363  GetHtml5HelpMapUrl */
  local_38 = DAT_1800791f8 ^ (ulonglong)auStackY_338;
  pppuVar22 = (undefined ***)0x0;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_300);
  MMGetLMProfileString(local_2c0,"mm","IgnoreHtmlHelpRoot","");
  pCVar6 = MMGetLMProfileString
                     ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2e8,
                      "mm","HtmlHelpRoot","");
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_300,
             (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar6);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2e8);
  iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                    (local_2c0,"YES");
  if ((iVar4 == 0) || (*(int *)(local_300 + -0x10) < 1)) {
    pcVar7 = (char *)SEGetSettingValue("HtmlHelpRoot",0);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_300,pcVar7);
  }
  if (*(int *)(local_300 + -0x10) < 1) goto LAB_18001d77d;
  iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::FindOneOf
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_300,
                     "/\\");
  if (((iVar4 == -1) &&
      (iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Find
                         ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                          &local_300,"http",0), iVar4 == -1)) &&
     (iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Find
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_300
                         ,"file:///",0), iVar4 == -1)) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_308);
    iVar4 = SHGetFolderPathA(0,0x23);
    if (-1 < iVar4) {
      uVar8 = FUN_1800240b0();
      pcVar7 = "\\AspenTech\\Aspen Plus ";
      if ((int)uVar8 != 1) {
        pcVar7 = "\\AspenTech\\Aspen Properties ";
      }
      PathAppendA((LPSTR)((longlong)&uStack_149 + 1),pcVar7);
      puVar2 = &uStack_149;
      do {
        puVar18 = puVar2;
        puVar2 = (undefined4 *)((longlong)puVar18 + 1);
      } while (*(char *)((longlong)puVar18 + 1) != '\0');
      *(undefined4 *)((longlong)puVar18 + 1) = DAT_180054638;
      *(undefined2 *)((longlong)puVar18 + 5) = DAT_18005463c;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_308,
                 (char *)((longlong)&uStack_149 + 1));
      pIVar9 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                         ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                          &local_308);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2f8,pIVar9)
      ;
      lVar19 = -1;
      do {
        lVar10 = lVar19 + 1;
        pcVar7 = "HtmlHelp\\" + lVar19;
        lVar19 = lVar10;
      } while (*pcVar7 != '\0');
      ATL::CSimpleStringT<char,1>::Concatenate
                ((CSimpleStringT<char,1> *)&local_2f8,local_308,*(int *)(local_308 + -0x10),
                 "\\HtmlHelp\\",(int)lVar10);
      pIVar9 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                         ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                          &local_2f8);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2f0,pIVar9)
      ;
      ATL::CSimpleStringT<char,1>::Concatenate
                ((CSimpleStringT<char,1> *)&local_2f0,local_2f8,*(int *)(local_2f8 + -0x10),
                 local_300,*(int *)(local_300 + -0x10));
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2f8);
      iVar4 = _stat64i32(local_2f0,local_180);
      if (iVar4 == -1) {
        pcVar7 = (char *)GetGlobalPointer("MMTOP");
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_308,
                   pcVar7);
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2f0);
    }
    if (0 < *(int *)(local_308 + -0x10)) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Replace
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_308,'\\',
                 '/');
      pCVar6 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
               ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
               CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_1a8,"file:///");
      pIVar9 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                         (pCVar6);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2f8,pIVar9)
      ;
      ATL::CSimpleStringT<char,1>::Concatenate
                ((CSimpleStringT<char,1> *)&local_2f8,*(char **)pCVar6,
                 *(int *)(*(char **)pCVar6 + -0x10),local_308,*(int *)(local_308 + -0x10));
      puVar11 = (undefined8 *)
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                          (local_2d0,"/HtmlHelp/");
      pCVar6 = FUN_180018cd0((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &local_2e8,
                             (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &local_2f8,puVar11);
      pIVar9 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                         (pCVar6);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2f0,pIVar9)
      ;
      ATL::CSimpleStringT<char,1>::Concatenate
                ((CSimpleStringT<char,1> *)&local_2f0,*(char **)pCVar6,
                 *(int *)(*(char **)pCVar6 + -0x10),local_300,*(int *)(local_300 + -0x10));
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_300,
                 (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                 &local_2f0);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2f0);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2e8);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2f8);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_1a8);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_2d0);
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_308);
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2e0,param_1);
  iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Find
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2e0,
                     ".chm",0);
  if (iVar4 != -1) {
    pCVar12 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2e0
                         ,(int)local_2d0);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2e0,pCVar12);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_2d0);
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2c8,param_2);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2d8);
  FUN_18001cab0((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2d8);
  if (0 < *(int *)(local_2d8 + -0x10)) {
    local_190 = 0;
    local_188 = 0xf;
    uStack_198 = 0;
    local_1a0 = (undefined1 (*) [32])0x0;
    local_2b8[0] = &DAT_180054380;
    std::basic_ios<char,std::char_traits<char>_>::basic_ios<char,std::char_traits<char>_>(local_208)
    ;
    std::basic_istream<char,std::char_traits<char>_>::basic_istream<char,std::char_traits<char>_>
              ((basic_istream<char,std::char_traits<char>_> *)local_2b8,
               (basic_streambuf<char,std::char_traits<char>_> *)&local_2a8,false);
    *(undefined ***)((longlong)local_2b8 + (longlong)*(int *)(local_2b8[0] + 4)) =
         std::basic_ifstream<char,std::char_traits<char>_>::vftable;
    *(int *)((longlong)&iStack_2bc + (longlong)*(int *)(local_2b8[0] + 4)) =
         *(int *)(local_2b8[0] + 4) + -0xb0;
    std::basic_streambuf<char,std::char_traits<char>_>::
    basic_streambuf<char,std::char_traits<char>_>
              ((basic_streambuf<char,std::char_traits<char>_> *)&local_2a8);
    local_22c = 0;
    local_2a8 = std::basic_filebuf<char,std::char_traits<char>_>::vftable;
    local_238[1] = 0;
    std::basic_streambuf<char,std::char_traits<char>_>::_Init
              ((basic_streambuf<char,std::char_traits<char>_> *)&local_2a8);
    local_228 = (FILE *)0x0;
    local_234 = DAT_18007a6c0;
    local_240 = 0;
    pbVar13 = FUN_18001b290((basic_streambuf<char,std::char_traits<char>_> *)&local_2a8,local_2d8,1,
                            0x40);
    if (pbVar13 == (basic_streambuf<char,std::char_traits<char>_> *)0x0) {
      std::basic_ios<char,std::char_traits<char>_>::setstate
                ((basic_ios<char,std::char_traits<char>_> *)
                 ((longlong)local_2b8 + (longlong)*(int *)(local_2b8[0] + 4)),2,false);
    }
    if (local_228 != (FILE *)0x0) {
      plVar14 = (longlong *)
                FUN_1800183e0((basic_istream<char,std::char_traits<char>_> *)local_2b8,&local_1a0);
      bVar3 = std::ios_base::operator_bool
                        ((ios_base *)((longlong)*(int *)(*plVar14 + 4) + (longlong)plVar14));
      if (bVar3) {
LAB_18001d0b1:
        lVar19 = local_190;
        pauVar17 = (undefined1 (*) [32])&local_1a0;
        if (0xf < local_188) {
          pauVar17 = local_1a0;
        }
        pauVar20 = (undefined1 (*) [32])(*pauVar17 + local_190);
        pauVar16 = (undefined1 (*) [32])&local_1a0;
        if (0xf < local_188) {
          pauVar16 = local_1a0;
        }
        pauVar15 = thunk_FUN_180047b40(pauVar16,pauVar20,'{');
        pauVar16 = pauVar15;
        if (pauVar15 != pauVar20) {
          while (pauVar16 = (undefined1 (*) [32])(*pauVar16 + 1), pauVar16 != pauVar20) {
            if ((*pauVar16)[0] != '{') {
              (*pauVar15)[0] = (*pauVar16)[0];
              pauVar15 = (undefined1 (*) [32])(*pauVar15 + 1);
            }
          }
        }
        pauVar16 = (undefined1 (*) [32])&local_1a0;
        if (0xf < local_188) {
          pauVar16 = local_1a0;
        }
        lVar10 = (longlong)pauVar15 - (longlong)pauVar16;
        uVar8 = (longlong)pauVar17 + (lVar19 - (longlong)pauVar15);
        if ((ulonglong)(local_190 - lVar10) < uVar8) {
          uVar8 = local_190 - lVar10;
        }
        pauVar17 = (undefined1 (*) [32])&local_1a0;
        if (0xf < local_188) {
          pauVar17 = local_1a0;
        }
        lVar19 = local_190 - uVar8;
        memmove((void *)((longlong)pauVar17 + lVar10),(void *)((longlong)pauVar17 + lVar10 + uVar8),
                (lVar19 - lVar10) + 1);
        local_190 = lVar19;
        if (lVar19 == 0) goto LAB_18001d41b;
        pauVar17 = (undefined1 (*) [32])&local_1a0;
        if (0xf < local_188) {
          pauVar17 = local_1a0;
        }
        pauVar20 = (undefined1 (*) [32])(lVar19 + (longlong)pauVar17);
        pauVar16 = (undefined1 (*) [32])&local_1a0;
        if (0xf < local_188) {
          pauVar16 = local_1a0;
        }
        pauVar16 = thunk_FUN_180047b40(pauVar16,pauVar20,'}');
        pauVar15 = pauVar16;
        if (pauVar16 != pauVar20) {
          while (pauVar15 = (undefined1 (*) [32])(*pauVar15 + 1), pauVar15 != pauVar20) {
            if ((*pauVar15)[0] != '}') {
              (*pauVar16)[0] = (*pauVar15)[0];
              pauVar16 = (undefined1 (*) [32])(*pauVar16 + 1);
            }
          }
        }
        pauVar20 = (undefined1 (*) [32])&local_1a0;
        if (0xf < local_188) {
          pauVar20 = local_1a0;
        }
        lVar10 = (longlong)pauVar16 - (longlong)pauVar20;
        uVar8 = (longlong)pauVar17 + (lVar19 - (longlong)pauVar16);
        if ((ulonglong)(local_190 - lVar10) < uVar8) {
          uVar8 = local_190 - lVar10;
        }
        pauVar17 = (undefined1 (*) [32])&local_1a0;
        if (0xf < local_188) {
          pauVar17 = local_1a0;
        }
        lVar19 = local_190 - uVar8;
        memmove((void *)((longlong)pauVar17 + lVar10),(void *)((longlong)pauVar17 + lVar10 + uVar8),
                (lVar19 - lVar10) + 1);
        pauVar17 = (undefined1 (*) [32])&local_1a0;
        if (0xf < local_188) {
          pauVar17 = local_1a0;
        }
        pauVar20 = (undefined1 (*) [32])(lVar19 + (longlong)pauVar17);
        pauVar16 = (undefined1 (*) [32])&local_1a0;
        if (0xf < local_188) {
          pauVar16 = local_1a0;
        }
        local_190 = lVar19;
        pauVar15 = thunk_FUN_180047b40(pauVar16,pauVar20,'\"');
        pauVar16 = pauVar15;
        if (pauVar15 != pauVar20) {
          while (pauVar16 = (undefined1 (*) [32])(*pauVar16 + 1), pauVar16 != pauVar20) {
            if ((*pauVar16)[0] != '\"') {
              (*pauVar15)[0] = (*pauVar16)[0];
              pauVar15 = (undefined1 (*) [32])(*pauVar15 + 1);
            }
          }
        }
        pauVar16 = (undefined1 (*) [32])&local_1a0;
        if (0xf < local_188) {
          pauVar16 = local_1a0;
        }
        lVar10 = (longlong)pauVar15 - (longlong)pauVar16;
        uVar8 = (longlong)pauVar17 + (lVar19 - (longlong)pauVar15);
        if ((ulonglong)(local_190 - lVar10) < uVar8) {
          uVar8 = local_190 - lVar10;
        }
        pauVar17 = (undefined1 (*) [32])&local_1a0;
        if (0xf < local_188) {
          pauVar17 = local_1a0;
        }
        lVar19 = local_190 - uVar8;
        memmove((void *)((longlong)pauVar17 + lVar10),(void *)((longlong)pauVar17 + lVar10 + uVar8),
                (lVar19 - lVar10) + 1);
        local_190 = lVar19;
        if (lVar19 == 0) goto LAB_18001d41b;
        pauVar17 = (undefined1 (*) [32])&local_1a0;
        if (0xf < local_188) {
          pauVar17 = local_1a0;
        }
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_308,
                   (char *)pauVar17);
        iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Find
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_308,',',0);
        if (iVar4 == -1) {
LAB_18001d415:
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_308);
          goto LAB_18001d41b;
        }
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Mid
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_308,
                   (int)&local_2f0,0);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Trim
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2f0);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Mid
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_308,
                   (int)&local_2f8);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Trim
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2f8);
        iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_2f0,local_2e0);
        if (iVar4 != 0) {
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2f8);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2f0);
          goto LAB_18001d415;
        }
        iVar4 = atoi(local_2f8);
        iVar5 = atoi(local_2c8);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2e8);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2e8,
                   "%s#cshid=%i",local_300,(ulonglong)(uint)(iVar4 + iVar5));
        lVar19 = param_3 - (longlong)local_2e8;
        do {
          cVar1 = *local_2e8;
          local_2e8[lVar19] = cVar1;
          local_2e8 = local_2e8 + 1;
        } while (cVar1 != '\0');
        if (local_228 == (FILE *)0x0) {
          local_22c = 0;
          local_238[1] = 0;
          std::basic_streambuf<char,std::char_traits<char>_>::_Init
                    ((basic_streambuf<char,std::char_traits<char>_> *)&local_2a8);
LAB_18001d5d0:
          local_228 = (FILE *)0x0;
          local_240 = 0;
          local_234 = DAT_18007a6c0;
          std::basic_ios<char,std::char_traits<char>_>::setstate
                    ((basic_ios<char,std::char_traits<char>_> *)
                     ((longlong)local_2b8 + (longlong)*(int *)(local_2b8[0] + 4)),2,false);
        }
        else {
          pcVar7 = std::basic_streambuf<char,std::char_traits<char>_>::eback
                             ((basic_streambuf<char,std::char_traits<char>_> *)&local_2a8);
          if (pcVar7 == local_238) {
            std::basic_streambuf<char,std::char_traits<char>_>::setg
                      ((basic_streambuf<char,std::char_traits<char>_> *)&local_2a8,local_220,
                       local_220,local_218);
          }
          bVar3 = FUN_18001aed0((longlong *)&local_2a8);
          pppuVar21 = &local_2a8;
          if (!bVar3) {
            pppuVar21 = pppuVar22;
          }
          iVar4 = fclose(local_228);
          local_22c = 0;
          local_238[1] = 0;
          if (iVar4 == 0) {
            pppuVar22 = pppuVar21;
          }
          std::basic_streambuf<char,std::char_traits<char>_>::_Init
                    ((basic_streambuf<char,std::char_traits<char>_> *)&local_2a8);
          local_234 = DAT_18007a6c0;
          local_228 = (FILE *)0x0;
          local_240 = 0;
          if (pppuVar22 == (undefined ***)0x0) goto LAB_18001d5d0;
        }
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2e8);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2f8);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2f0);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_308);
        *(undefined ***)((longlong)local_2b8 + (longlong)*(int *)(local_2b8[0] + 4)) =
             std::basic_ifstream<char,std::char_traits<char>_>::vftable;
        *(int *)((longlong)&iStack_2bc + (longlong)*(int *)(local_2b8[0] + 4)) =
             *(int *)(local_2b8[0] + 4) + -0xb0;
        FUN_180018b30((basic_streambuf<char,std::char_traits<char>_> *)&local_2a8);
        std::basic_istream<char,std::char_traits<char>_>::
        ~basic_istream<char,std::char_traits<char>_>(local_2a0);
        std::basic_ios<char,std::char_traits<char>_>::~basic_ios<char,std::char_traits<char>_>
                  (local_208);
        if (0xf < local_188) {
          pauVar17 = local_1a0;
          if ((0xfff < local_188 + 1) &&
             (pauVar17 = *(undefined1 (**) [32])(local_1a0[-1] + 0x18),
             0x1f < (ulonglong)((longlong)local_1a0 + (-8 - (longlong)pauVar17)))) {
                    /* WARNING: Subroutine does not return */
            _invalid_parameter_noinfo_noreturn();
          }
          goto LAB_18001d757;
        }
        goto LAB_18001d75c;
      }
LAB_18001d443:
      if (local_228 == (FILE *)0x0) {
        local_22c = 0;
        local_238[1] = 0;
        std::basic_streambuf<char,std::char_traits<char>_>::_Init
                  ((basic_streambuf<char,std::char_traits<char>_> *)&local_2a8);
      }
      else {
        pcVar7 = std::basic_streambuf<char,std::char_traits<char>_>::eback
                           ((basic_streambuf<char,std::char_traits<char>_> *)&local_2a8);
        if (pcVar7 == local_238) {
          std::basic_streambuf<char,std::char_traits<char>_>::setg
                    ((basic_streambuf<char,std::char_traits<char>_> *)&local_2a8,local_220,local_220
                     ,local_218);
        }
        bVar3 = FUN_18001aed0((longlong *)&local_2a8);
        pppuVar21 = &local_2a8;
        if (!bVar3) {
          pppuVar21 = pppuVar22;
        }
        iVar4 = fclose(local_228);
        local_22c = 0;
        local_238[1] = 0;
        if (iVar4 == 0) {
          pppuVar22 = pppuVar21;
        }
        std::basic_streambuf<char,std::char_traits<char>_>::_Init
                  ((basic_streambuf<char,std::char_traits<char>_> *)&local_2a8);
        local_234 = DAT_18007a6c0;
        local_228 = (FILE *)0x0;
        local_240 = 0;
        if (pppuVar22 != (undefined ***)0x0) goto LAB_18001d6dc;
      }
      local_228 = (FILE *)0x0;
      local_240 = 0;
      local_234 = DAT_18007a6c0;
      std::basic_ios<char,std::char_traits<char>_>::setstate
                ((basic_ios<char,std::char_traits<char>_> *)
                 ((longlong)local_2b8 + (longlong)*(int *)(local_2b8[0] + 4)),2,false);
    }
LAB_18001d6dc:
    *(undefined ***)((longlong)local_2b8 + (longlong)*(int *)(local_2b8[0] + 4)) =
         std::basic_ifstream<char,std::char_traits<char>_>::vftable;
    *(int *)((longlong)&iStack_2bc + (longlong)*(int *)(local_2b8[0] + 4)) =
         *(int *)(local_2b8[0] + 4) + -0xb0;
    FUN_180018b30((basic_streambuf<char,std::char_traits<char>_> *)&local_2a8);
    std::basic_istream<char,std::char_traits<char>_>::~basic_istream<char,std::char_traits<char>_>
              (local_2a0);
    std::basic_ios<char,std::char_traits<char>_>::~basic_ios<char,std::char_traits<char>_>
              (local_208);
    if (0xf < local_188) {
      pauVar17 = local_1a0;
      if ((0xfff < local_188 + 1) &&
         (pauVar17 = *(undefined1 (**) [32])(local_1a0[-1] + 0x18),
         0x1f < (ulonglong)
                ((longlong)local_1a0 +
                (-8 - (longlong)*(undefined1 (**) [32])(local_1a0[-1] + 0x18))))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
LAB_18001d757:
      operator_delete(pauVar17);
    }
  }
LAB_18001d75c:
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2d8);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2c8);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_2e0);
LAB_18001d77d:
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_2c0);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_300);
  return;
LAB_18001d41b:
  plVar14 = (longlong *)
            FUN_1800183e0((basic_istream<char,std::char_traits<char>_> *)local_2b8,&local_1a0);
  bVar3 = std::ios_base::operator_bool
                    ((ios_base *)((longlong)*(int *)(*plVar14 + 4) + (longlong)plVar14));
  if (!bVar3) goto LAB_18001d443;
  goto LAB_18001d0b1;
}

/* ---- FUNC 0001D7C0 GetModelDataFromApwnBlockName (53 bytes) ---- */

undefined8 GetModelDataFromApwnBlockName(char *param_1,char *param_2,char *param_3,char *param_4)

{
  undefined8 uVar1;
  
                    /* 0x1d7c0  365  GetModelDataFromApwnBlockName */
  if (g_pApwnBlockUsage != (CApwnBlockUsage *)0x0) {
    uVar1 = FUN_180003f80((longlong)g_pApwnBlockUsage,param_1,param_2,param_3,param_4);
    return uVar1;
  }
  return 0x80004005;
}

/* ---- FUNC 0001D800 GetPastingStatus (7 bytes) ---- */

undefined4 GetPastingStatus(void)

{
                    /* 0x1d800  366  GetPastingStatus */
  return DAT_18007a2a8;
}

/* ---- FUNC 0001D810 MMGetLocalizedNamePackProp (283 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

INT_PTR MMGetLocalizedNamePackProp(undefined8 param_1)

{
  longlong lVar1;
  int iVar2;
  char *pcVar3;
  IAtlStringMgr *pIVar4;
  longlong lVar5;
  HMODULE hModule;
  FARPROC pFVar7;
  INT_PTR IVar8;
  undefined1 auStackY_88 [32];
  char *local_58;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_50 [8];
  undefined1 local_48 [48];
  ulonglong local_18;
  longlong lVar6;
  
                    /* 0x1d810  389  MMGetLocalizedNamePackProp */
  local_18 = DAT_1800791f8 ^ (ulonglong)auStackY_88;
  hModule = (HMODULE)0x0;
  pcVar3 = (char *)GetGlobalPointer("MMCOMMONXEQ");
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_58,pcVar3);
  if (*(int *)(local_58 + -0x10) != 0) {
    pIVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                       ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_58);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_50,pIVar4);
    lVar6 = -1;
    do {
      lVar5 = lVar6 + 1;
      lVar1 = lVar6 + 1;
      lVar6 = lVar5;
    } while ("\\rscpackprop.dll"[lVar1] != '\0');
    ATL::CSimpleStringT<char,1>::Concatenate
              ((CSimpleStringT<char,1> *)local_50,local_58,*(int *)(local_58 + -0x10),
               "\\rscpackprop.dll",(int)lVar5);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_58,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)local_50
              );
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_50);
    iVar2 = _stat64i32(local_58,local_48);
    if (iVar2 != -1) {
      hModule = LoadLibraryA(local_58);
    }
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_58);
  if ((hModule != (HMODULE)0x0) &&
     (pFVar7 = GetProcAddress(hModule,"GetPackPropValue"), pFVar7 != (FARPROC)0x0)) {
    IVar8 = (*pFVar7)(param_1);
    return IVar8;
  }
  return 0;
}

/* ---- FUNC 0001D930 MMGetLocalizedPrompt (178 bytes) ---- */

undefined * MMGetLocalizedPrompt(short param_1,short param_2)

{
  LPCSTR local_res18;
  char *local_res20;
  
                    /* 0x1d930  390  MMGetLocalizedPrompt */
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res18);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res18,
             "FILEPNUM_%d_Prompt_%d",(ulonglong)(uint)(int)param_1,(ulonglong)(uint)(int)param_2);
  FUN_180019490((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20,
                local_res18);
  if (*(int *)(local_res20 + -0x10) == 0) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res18);
    return (undefined *)0x0;
  }
  strncpy(&DAT_18007a2c0,local_res20,0x1ff);
  DAT_18007a4bf = 0;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res18);
  return &DAT_18007a2c0;
}

/* ---- FUNC 0001D9F0 MMGetLocalizedRecPrompt (158 bytes) ---- */

undefined * MMGetLocalizedRecPrompt(short param_1)

{
  LPCSTR local_res10;
  char *local_res18 [2];
  
                    /* 0x1d9f0  391  MMGetLocalizedRecPrompt */
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res10);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res10,
             "FILEPNUM_%d",(ulonglong)(uint)(int)param_1);
  FUN_180019490((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_res18,
                local_res10);
  if (*(int *)(local_res18[0] + -0x10) == 0) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_res18);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res10);
    return (undefined *)0x0;
  }
  strncpy(&DAT_18007a4c0,local_res18[0],0x1ff);
  DAT_18007a6bf = 0;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_res18);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res10);
  return &DAT_18007a4c0;
}

/* ---- FUNC 0001DA90 MMGetLocalizedTFFFullPath (136 bytes) ---- */

undefined4 MMGetLocalizedTFFFullPath(char *param_1,longlong param_2,int param_3)

{
  char cVar1;
  longlong lVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  undefined8 uVar7;
  IAtlStringMgr *pIVar8;
  longlong lVar9;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar10;
  longlong lVar11;
  longlong lVar12;
  char *local_res20;
  char *local_48;
  char *local_40;
  char *local_38;
  char *local_30;
  char *local_28 [2];
  
                    /* 0x1da90  392  MMGetLocalizedTFFFullPath */
  uVar5 = 0;
  iVar4 = FUN_180019c30();
  if (iVar4 == 1) {
    uVar5 = 0;
  }
  else {
    pcVar6 = (char *)GetGlobalPointer("MMXEQ");
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_28,pcVar6);
    if (0 < *(int *)(local_28[0] + -0x10)) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_30);
      uVar7 = FUN_180019850((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            &local_30);
      uVar3 = uVar5;
      if (((int)uVar7 == 1) && (uVar3 = 0, 0 < *(int *)(local_30 + -0x10))) {
        pIVar8 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                           ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            local_28);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_40,pIVar8
                  );
        lVar11 = -1;
        lVar12 = -1;
        do {
          lVar9 = lVar12 + 1;
          lVar2 = lVar12 + 1;
          lVar12 = lVar9;
        } while ("\\tfffiles\\"[lVar2] != '\0');
        ATL::CSimpleStringT<char,1>::Concatenate
                  ((CSimpleStringT<char,1> *)&local_40,local_28[0],*(int *)(local_28[0] + -0x10),
                   "\\tfffiles\\",(int)lVar9);
        pIVar8 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                           ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            &local_40);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_48,pIVar8
                  );
        ATL::CSimpleStringT<char,1>::Concatenate
                  ((CSimpleStringT<char,1> *)&local_48,local_40,*(int *)(local_40 + -0x10),local_30,
                   *(int *)(local_30 + -0x10));
        pIVar8 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                           ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            &local_48);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20,
                   pIVar8);
        lVar12 = -1;
        do {
          lVar9 = lVar12 + 1;
          lVar2 = lVar12 + 1;
          lVar12 = lVar9;
        } while (*(char *)((longlong)&DAT_180053ef4 + lVar2) != '\0');
        ATL::CSimpleStringT<char,1>::Concatenate
                  ((CSimpleStringT<char,1> *)&local_res20,local_48,*(int *)(local_48 + -0x10),"\\",
                   (int)lVar9);
        pIVar8 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                           ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            &local_res20);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_38,pIVar8
                  );
        if (param_1 == (char *)0x0) {
          lVar11 = 0;
        }
        else {
          do {
            lVar11 = lVar11 + 1;
          } while (param_1[lVar11] != '\0');
        }
        ATL::CSimpleStringT<char,1>::Concatenate
                  ((CSimpleStringT<char,1> *)&local_38,local_res20,*(int *)(local_res20 + -0x10),
                   param_1,(int)lVar11);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_48);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_40);
        iVar4 = _access(local_38,0);
        if (iVar4 != -1) {
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20,
                     (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                     &local_38);
          if (param_3 < *(int *)(local_res20 + -0x10)) {
            pCVar10 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                 &local_res20,(int)&local_40);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20
                       ,pCVar10);
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_40);
          }
          lVar12 = param_2 - (longlong)local_res20;
          do {
            cVar1 = *local_res20;
            local_res20[lVar12] = cVar1;
            local_res20 = local_res20 + 1;
          } while (cVar1 != '\0');
          uVar5 = 1;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20);
        }
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_38);
        uVar3 = uVar5;
      }
      uVar5 = uVar3;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_30);
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_28);
  }
  return uVar5;
}

/* ---- FUNC 0001DB18 FUN_18001db18 (321 bytes) ---- */

ulonglong FUN_18001db18(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_1)

{
  longlong lVar1;
  int iVar2;
  IAtlStringMgr *pIVar3;
  longlong lVar4;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar5;
  char *pcVar6;
  ulonglong uVar7;
  longlong unaff_RBP;
  char *unaff_RSI;
  longlong unaff_RDI;
  longlong lVar8;
  char cVar9;
  ulonglong unaff_R14;
  int unaff_R15D;
  
  pIVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager(param_1);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(unaff_RBP + -0x28),
             pIVar3);
  uVar7 = 0xffffffffffffffff;
  lVar8 = -1;
  do {
    lVar4 = lVar8 + 1;
    lVar1 = lVar8 + 1;
    cVar9 = (char)unaff_R14;
    lVar8 = lVar4;
  } while ("\\tfffiles\\"[lVar1] != cVar9);
  ATL::CSimpleStringT<char,1>::Concatenate
            ((CSimpleStringT<char,1> *)(unaff_RBP + -0x28),*(char **)(unaff_RBP + -0x10),
             *(int *)(*(char **)(unaff_RBP + -0x10) + -0x10),"\\tfffiles\\",(int)lVar4);
  pIVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                     ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                      (unaff_RBP + -0x28));
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(unaff_RBP + -0x30),
             pIVar3);
  ATL::CSimpleStringT<char,1>::Concatenate
            ((CSimpleStringT<char,1> *)(unaff_RBP + -0x30),*(char **)(unaff_RBP + -0x28),
             *(int *)(*(char **)(unaff_RBP + -0x28) + -0x10),*(char **)(unaff_RBP + -0x18),
             *(int *)(*(char **)(unaff_RBP + -0x18) + -0x10));
  pIVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                     ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                      (unaff_RBP + -0x30));
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(unaff_RBP + 0x38),
             pIVar3);
  lVar8 = -1;
  do {
    lVar4 = lVar8 + 1;
    lVar1 = lVar8 + 1;
    lVar8 = lVar4;
  } while (*(char *)((longlong)&DAT_180053ef4 + lVar1) != cVar9);
  ATL::CSimpleStringT<char,1>::Concatenate
            ((CSimpleStringT<char,1> *)(unaff_RBP + 0x38),*(char **)(unaff_RBP + -0x30),
             *(int *)(*(char **)(unaff_RBP + -0x30) + -0x10),"\\",(int)lVar4);
  pIVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                     ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                      (unaff_RBP + 0x38));
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(unaff_RBP + -0x20),
             pIVar3);
  if (unaff_RSI == (char *)0x0) {
    uVar7 = unaff_R14 & 0xffffffff;
  }
  else {
    do {
      uVar7 = uVar7 + 1;
    } while (unaff_RSI[uVar7] != cVar9);
  }
  ATL::CSimpleStringT<char,1>::Concatenate
            ((CSimpleStringT<char,1> *)(unaff_RBP + -0x20),*(char **)(unaff_RBP + 0x38),
             *(int *)(*(char **)(unaff_RBP + 0x38) + -0x10),unaff_RSI,(int)uVar7);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(unaff_RBP + 0x38));
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(unaff_RBP + -0x30));
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(unaff_RBP + -0x28));
  iVar2 = _access(*(char **)(unaff_RBP + -0x20),0);
  if (iVar2 != -1) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(unaff_RBP + 0x38),
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               (unaff_RBP + -0x20));
    pcVar6 = *(char **)(unaff_RBP + 0x38);
    if (unaff_R15D < *(int *)(pcVar6 + -0x10)) {
      pCVar5 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                         ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                          (unaff_RBP + 0x38),(int)unaff_RBP + -0x28);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(unaff_RBP + 0x38)
                 ,pCVar5);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                 (unaff_RBP + -0x28));
      pcVar6 = *(char **)(unaff_RBP + 0x38);
    }
    lVar8 = unaff_RDI - (longlong)pcVar6;
    do {
      cVar9 = *pcVar6;
      pcVar6[lVar8] = cVar9;
      pcVar6 = pcVar6 + 1;
    } while (cVar9 != '\0');
    unaff_R14 = 1;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(unaff_RBP + 0x38));
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(unaff_RBP + -0x20));
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(unaff_RBP + -0x18));
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(unaff_RBP + -0x10));
  return unaff_R14 & 0xffffffff;
}

/* ---- FUNC 0001DC59 FUN_18001dc59 (157 bytes) ---- */

undefined8 FUN_18001dc59(void)

{
  char cVar1;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar2;
  char *pcVar3;
  longlong unaff_RBP;
  longlong unaff_RDI;
  longlong lVar4;
  int unaff_R15D;
  
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(unaff_RBP + 0x38),
             (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             (unaff_RBP + -0x20));
  pcVar3 = *(char **)(unaff_RBP + 0x38);
  if (unaff_R15D < *(int *)(pcVar3 + -0x10)) {
    pCVar2 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Left
                       ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                        (unaff_RBP + 0x38),(int)unaff_RBP + -0x28);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(unaff_RBP + 0x38),
               pCVar2);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(unaff_RBP + -0x28))
    ;
    pcVar3 = *(char **)(unaff_RBP + 0x38);
  }
  lVar4 = unaff_RDI - (longlong)pcVar3;
  do {
    cVar1 = *pcVar3;
    pcVar3[lVar4] = cVar1;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(unaff_RBP + 0x38));
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(unaff_RBP + -0x20));
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(unaff_RBP + -0x18));
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(unaff_RBP + -0x10));
  return 1;
}

/* ---- FUNC 0001DD00 PutOnClipboard (64 bytes) ---- */

void PutOnClipboard(HGLOBAL param_1)

{
                    /* 0x1dd00  423  PutOnClipboard */
  OpenClipboard((HWND)0x0);
  EmptyClipboard();
  GlobalUnlock(param_1);
  GetLastError();
  SetClipboardData(1,param_1);
                    /* WARNING: Could not recover jumptable at 0x00018001dd39. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CloseClipboard();
  return;
}

/* ---- FUNC 0001DD40 Read90CArestoreMap (26 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 Read90CArestoreMap(void *param_1,int *param_2,int *param_3,longlong param_4)

{
  char cVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined8 ***pppuVar6;
  ulonglong uVar7;
  longlong *plVar8;
  int iVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  char *pcVar13;
  undefined8 ****ppppuVar14;
  longlong *plVar15;
  undefined8 uVar16;
  size_t sVar17;
  longlong lVar18;
  undefined1 auStack_88 [32];
  int *local_68;
  undefined8 ***local_60;
  undefined8 uStack_58;
  size_t local_50;
  ulonglong local_48;
  ulonglong local_40;
  
                    /* 0x1dd40  424  Read90CArestoreMap */
  local_40 = DAT_1800791f8 ^ (ulonglong)auStack_88;
  uVar16 = 0;
  local_60 = (undefined8 ****)0x0;
  uStack_58 = 0;
  local_50 = 0;
  sVar17 = 0xffffffffffffffff;
  local_48 = 0;
  do {
    sVar17 = sVar17 + 1;
  } while (*(char *)((longlong)param_1 + sVar17) != '\0');
  local_68 = param_2;
  FUN_18000b5f0(&local_60,param_1,sVar17);
  uVar7 = local_48;
  sVar17 = local_50;
  pppuVar6 = local_60;
  plVar5 = DAT_18007a288;
  plVar15 = (longlong *)*DAT_18007a288;
  if (plVar15 != DAT_18007a288) {
    do {
      plVar11 = plVar15 + 4;
      ppppuVar14 = &local_60;
      if (0xf < uVar7) {
        ppppuVar14 = (undefined8 ****)pppuVar6;
      }
      if (0xf < (ulonglong)plVar15[7]) {
        plVar11 = (longlong *)plVar15[4];
      }
      if ((plVar15[6] == sVar17) && (iVar9 = memcmp(plVar11,ppppuVar14,plVar15[6]), iVar9 == 0)) {
        plVar11 = (longlong *)plVar15[8];
        plVar12 = (longlong *)*plVar11;
        if (plVar12 != plVar11) {
          do {
            if ((int)plVar12[4] == *local_68) {
              plVar2 = (longlong *)plVar12[5];
              plVar10 = (longlong *)*plVar2;
              if (plVar10 != plVar2) {
                do {
                  if (*(int *)((longlong)plVar10 + 0x1c) == *param_3) {
                    plVar15 = plVar10 + 4;
                    lVar18 = param_4 - (longlong)plVar15;
                    do {
                      lVar4 = *plVar15;
                      *(char *)(lVar18 + (longlong)plVar15) = (char)lVar4;
                      plVar15 = (longlong *)((longlong)plVar15 + 1);
                    } while ((char)lVar4 != '\0');
                    pcVar13 = (char *)((longlong)plVar10 + 0x2c);
                    lVar18 = param_4 - (longlong)pcVar13;
                    do {
                      cVar1 = *pcVar13;
                      pcVar13[lVar18 + 0xc] = cVar1;
                      pcVar13 = pcVar13 + 1;
                    } while (cVar1 != '\0');
                    uVar16 = 1;
                    goto FUN_18001df5f;
                  }
                  plVar3 = (longlong *)plVar10[2];
                  if (*(char *)((longlong)plVar3 + 0x19) == '\0') {
                    cVar1 = *(char *)(*plVar3 + 0x19);
                    plVar10 = plVar3;
                    plVar3 = (longlong *)*plVar3;
                    while (cVar1 == '\0') {
                      cVar1 = *(char *)(*plVar3 + 0x19);
                      plVar10 = plVar3;
                      plVar3 = (longlong *)*plVar3;
                    }
                  }
                  else {
                    cVar1 = *(char *)(plVar10[1] + 0x19);
                    plVar8 = (longlong *)plVar10[1];
                    plVar3 = plVar10;
                    while ((plVar10 = plVar8, cVar1 == '\0' && (plVar3 == (longlong *)plVar10[2])))
                    {
                      cVar1 = *(char *)(plVar10[1] + 0x19);
                      plVar8 = (longlong *)plVar10[1];
                      plVar3 = plVar10;
                    }
                  }
                } while (plVar10 != plVar2);
              }
            }
            plVar2 = (longlong *)plVar12[2];
            if (*(char *)((longlong)plVar2 + 0x19) == '\0') {
              cVar1 = *(char *)(*plVar2 + 0x19);
              plVar12 = plVar2;
              plVar2 = (longlong *)*plVar2;
              while (cVar1 == '\0') {
                cVar1 = *(char *)(*plVar2 + 0x19);
                plVar12 = plVar2;
                plVar2 = (longlong *)*plVar2;
              }
            }
            else {
              cVar1 = *(char *)(plVar12[1] + 0x19);
              plVar10 = (longlong *)plVar12[1];
              plVar2 = plVar12;
              while ((plVar12 = plVar10, cVar1 == '\0' && (plVar2 == (longlong *)plVar12[2]))) {
                cVar1 = *(char *)(plVar12[1] + 0x19);
                plVar10 = (longlong *)plVar12[1];
                plVar2 = plVar12;
              }
            }
          } while (plVar12 != plVar11);
        }
      }
      plVar11 = (longlong *)plVar15[2];
      if (*(char *)((longlong)plVar11 + 0x19) == '\0') {
        cVar1 = *(char *)(*plVar11 + 0x19);
        plVar15 = plVar11;
        plVar11 = (longlong *)*plVar11;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*plVar11 + 0x19);
          plVar15 = plVar11;
          plVar11 = (longlong *)*plVar11;
        }
      }
      else {
        cVar1 = *(char *)(plVar15[1] + 0x19);
        plVar12 = (longlong *)plVar15[1];
        plVar11 = plVar15;
        while ((plVar15 = plVar12, cVar1 == '\0' && (plVar11 == (longlong *)plVar15[2]))) {
          cVar1 = *(char *)(plVar15[1] + 0x19);
          plVar12 = (longlong *)plVar15[1];
          plVar11 = plVar15;
        }
      }
    } while (plVar15 != plVar5);
    uVar16 = 0;
  }
FUN_18001df5f:
  if (0xf < uVar7) {
    ppppuVar14 = (undefined8 ****)pppuVar6;
    if ((0xfff < uVar7 + 1) &&
       (ppppuVar14 = (undefined8 ****)pppuVar6[-1],
       0x1f < (ulonglong)((longlong)pppuVar6 + (-8 - (longlong)ppppuVar14)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(ppppuVar14);
  }
  return uVar16;
}

/* ---- FUNC 0001DD5A FUN_18001dd5a (105 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
FUN_18001dd5a(void *param_1,int *param_2,int *param_3,longlong param_4,undefined8 param_5,
             undefined8 param_6,size_t param_7,ulonglong param_8)

{
  char cVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined1 *puVar6;
  ulonglong uVar7;
  longlong *plVar8;
  int iVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  char *pcVar13;
  undefined1 *puVar14;
  longlong *plVar15;
  undefined8 unaff_RBX;
  undefined8 unaff_RSI;
  undefined8 uVar16;
  size_t sVar17;
  longlong lVar18;
  longlong in_R11;
  undefined8 unaff_R13;
  undefined8 unaff_R14;
  
  *(undefined8 *)(in_R11 + 0x10) = unaff_RBX;
  uVar16 = 0;
  *(undefined8 *)(in_R11 + -0x20) = unaff_RSI;
  *(undefined8 *)(in_R11 + -0x30) = unaff_R13;
  param_5 = (undefined1 *)0x0;
  param_6 = 0;
  *(undefined8 *)(in_R11 + -0x38) = unaff_R14;
  *(undefined8 *)(in_R11 + -0x50) = 0;
  sVar17 = 0xffffffffffffffff;
  *(undefined8 *)(in_R11 + -0x48) = 0;
  do {
    sVar17 = sVar17 + 1;
  } while (*(char *)((longlong)param_1 + sVar17) != '\0');
  FUN_18000b5f0(&param_5,param_1,sVar17);
  uVar7 = param_8;
  sVar17 = param_7;
  puVar6 = param_5;
  plVar5 = DAT_18007a288;
  plVar15 = (longlong *)*DAT_18007a288;
  if (plVar15 != DAT_18007a288) {
    do {
      plVar11 = plVar15 + 4;
      puVar14 = (undefined1 *)&param_5;
      if (0xf < uVar7) {
        puVar14 = puVar6;
      }
      if (0xf < (ulonglong)plVar15[7]) {
        plVar11 = (longlong *)plVar15[4];
      }
      if ((plVar15[6] == sVar17) && (iVar9 = memcmp(plVar11,puVar14,plVar15[6]), iVar9 == 0)) {
        plVar11 = (longlong *)plVar15[8];
        plVar12 = (longlong *)*plVar11;
        if (plVar12 != plVar11) {
          do {
            if ((int)plVar12[4] == *param_2) {
              plVar2 = (longlong *)plVar12[5];
              plVar10 = (longlong *)*plVar2;
              if (plVar10 != plVar2) {
                do {
                  if (*(int *)((longlong)plVar10 + 0x1c) == *param_3) {
                    plVar15 = plVar10 + 4;
                    lVar18 = param_4 - (longlong)plVar15;
                    do {
                      lVar4 = *plVar15;
                      *(char *)(lVar18 + (longlong)plVar15) = (char)lVar4;
                      plVar15 = (longlong *)((longlong)plVar15 + 1);
                    } while ((char)lVar4 != '\0');
                    pcVar13 = (char *)((longlong)plVar10 + 0x2c);
                    param_4 = param_4 - (longlong)pcVar13;
                    do {
                      cVar1 = *pcVar13;
                      pcVar13[param_4 + 0xc] = cVar1;
                      pcVar13 = pcVar13 + 1;
                    } while (cVar1 != '\0');
                    uVar16 = 1;
                    goto FUN_18001df5f;
                  }
                  plVar3 = (longlong *)plVar10[2];
                  if (*(char *)((longlong)plVar3 + 0x19) == '\0') {
                    cVar1 = *(char *)(*plVar3 + 0x19);
                    plVar10 = plVar3;
                    plVar3 = (longlong *)*plVar3;
                    while (cVar1 == '\0') {
                      cVar1 = *(char *)(*plVar3 + 0x19);
                      plVar10 = plVar3;
                      plVar3 = (longlong *)*plVar3;
                    }
                  }
                  else {
                    cVar1 = *(char *)(plVar10[1] + 0x19);
                    plVar8 = (longlong *)plVar10[1];
                    plVar3 = plVar10;
                    while ((plVar10 = plVar8, cVar1 == '\0' && (plVar3 == (longlong *)plVar10[2])))
                    {
                      cVar1 = *(char *)(plVar10[1] + 0x19);
                      plVar8 = (longlong *)plVar10[1];
                      plVar3 = plVar10;
                    }
                  }
                } while (plVar10 != plVar2);
              }
            }
            plVar2 = (longlong *)plVar12[2];
            if (*(char *)((longlong)plVar2 + 0x19) == '\0') {
              cVar1 = *(char *)(*plVar2 + 0x19);
              plVar12 = plVar2;
              plVar2 = (longlong *)*plVar2;
              while (cVar1 == '\0') {
                cVar1 = *(char *)(*plVar2 + 0x19);
                plVar12 = plVar2;
                plVar2 = (longlong *)*plVar2;
              }
            }
            else {
              cVar1 = *(char *)(plVar12[1] + 0x19);
              plVar10 = (longlong *)plVar12[1];
              plVar2 = plVar12;
              while ((plVar12 = plVar10, cVar1 == '\0' && (plVar2 == (longlong *)plVar12[2]))) {
                cVar1 = *(char *)(plVar12[1] + 0x19);
                plVar10 = (longlong *)plVar12[1];
                plVar2 = plVar12;
              }
            }
          } while (plVar12 != plVar11);
        }
      }
      plVar11 = (longlong *)plVar15[2];
      if (*(char *)((longlong)plVar11 + 0x19) == '\0') {
        cVar1 = *(char *)(*plVar11 + 0x19);
        plVar15 = plVar11;
        plVar11 = (longlong *)*plVar11;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*plVar11 + 0x19);
          plVar15 = plVar11;
          plVar11 = (longlong *)*plVar11;
        }
      }
      else {
        cVar1 = *(char *)(plVar15[1] + 0x19);
        plVar12 = (longlong *)plVar15[1];
        plVar11 = plVar15;
        while ((plVar15 = plVar12, cVar1 == '\0' && (plVar11 == (longlong *)plVar15[2]))) {
          cVar1 = *(char *)(plVar15[1] + 0x19);
          plVar12 = (longlong *)plVar15[1];
          plVar11 = plVar15;
        }
      }
    } while (plVar15 != plVar5);
    uVar16 = 0;
  }
FUN_18001df5f:
  if (0xf < uVar7) {
    puVar14 = puVar6;
    if ((0xfff < uVar7 + 1) &&
       (puVar14 = *(undefined1 **)(puVar6 + -8),
       (undefined1 *)0x1f < puVar6 + (-8 - (longlong)puVar14))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(puVar14);
  }
  return uVar16;
}

/* ---- FUNC 0001DDC3 FUN_18001ddc3 (412 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_18001ddc3(void)

{
  char cVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong lVar4;
  size_t sVar5;
  longlong *plVar6;
  int iVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong *plVar10;
  char *pcVar11;
  undefined1 *puVar12;
  longlong *unaff_RBX;
  undefined1 *unaff_RBP;
  int *unaff_RSI;
  undefined4 uVar13;
  longlong lVar14;
  longlong unaff_R13;
  longlong *unaff_R14;
  ulonglong unaff_R15;
  int *piStackX_20;
  size_t in_stack_00000038;
  
  sVar5 = in_stack_00000038;
  do {
    plVar9 = unaff_RBX + 4;
    puVar12 = &stack0x00000028;
    if (0xf < unaff_R15) {
      puVar12 = unaff_RBP;
    }
    if (0xf < (ulonglong)unaff_RBX[7]) {
      plVar9 = (longlong *)unaff_RBX[4];
    }
    if ((unaff_RBX[6] == sVar5) && (iVar7 = memcmp(plVar9,puVar12,unaff_RBX[6]), iVar7 == 0)) {
      plVar9 = (longlong *)unaff_RBX[8];
      plVar10 = (longlong *)*plVar9;
      if (plVar10 != plVar9) {
        do {
          if ((int)plVar10[4] == *piStackX_20) {
            plVar2 = (longlong *)plVar10[5];
            plVar8 = (longlong *)*plVar2;
            if (plVar8 != plVar2) {
              do {
                if (*(int *)((longlong)plVar8 + 0x1c) == *unaff_RSI) {
                  plVar9 = plVar8 + 4;
                  lVar14 = unaff_R13 - (longlong)plVar9;
                  do {
                    lVar4 = *plVar9;
                    *(char *)(lVar14 + (longlong)plVar9) = (char)lVar4;
                    plVar9 = (longlong *)((longlong)plVar9 + 1);
                  } while ((char)lVar4 != '\0');
                  pcVar11 = (char *)((longlong)plVar8 + 0x2c);
                  lVar14 = unaff_R13 - (longlong)pcVar11;
                  do {
                    cVar1 = *pcVar11;
                    pcVar11[lVar14 + 0xc] = cVar1;
                    pcVar11 = pcVar11 + 1;
                  } while (cVar1 != '\0');
                  uVar13 = 1;
                  goto LAB_18001df5a;
                }
                plVar3 = (longlong *)plVar8[2];
                if (*(char *)((longlong)plVar3 + 0x19) == '\0') {
                  cVar1 = *(char *)(*plVar3 + 0x19);
                  plVar8 = plVar3;
                  plVar3 = (longlong *)*plVar3;
                  while (cVar1 == '\0') {
                    cVar1 = *(char *)(*plVar3 + 0x19);
                    plVar8 = plVar3;
                    plVar3 = (longlong *)*plVar3;
                  }
                }
                else {
                  cVar1 = *(char *)(plVar8[1] + 0x19);
                  plVar6 = (longlong *)plVar8[1];
                  plVar3 = plVar8;
                  while ((plVar8 = plVar6, cVar1 == '\0' && (plVar3 == (longlong *)plVar8[2]))) {
                    cVar1 = *(char *)(plVar8[1] + 0x19);
                    plVar6 = (longlong *)plVar8[1];
                    plVar3 = plVar8;
                  }
                }
              } while (plVar8 != plVar2);
            }
          }
          plVar2 = (longlong *)plVar10[2];
          if (*(char *)((longlong)plVar2 + 0x19) == '\0') {
            cVar1 = *(char *)(*plVar2 + 0x19);
            plVar10 = plVar2;
            plVar2 = (longlong *)*plVar2;
            while (cVar1 == '\0') {
              cVar1 = *(char *)(*plVar2 + 0x19);
              plVar10 = plVar2;
              plVar2 = (longlong *)*plVar2;
            }
          }
          else {
            cVar1 = *(char *)(plVar10[1] + 0x19);
            plVar8 = (longlong *)plVar10[1];
            plVar2 = plVar10;
            while ((plVar10 = plVar8, cVar1 == '\0' && (plVar2 == (longlong *)plVar10[2]))) {
              cVar1 = *(char *)(plVar10[1] + 0x19);
              plVar8 = (longlong *)plVar10[1];
              plVar2 = plVar10;
            }
          }
        } while (plVar10 != plVar9);
      }
    }
    plVar9 = (longlong *)unaff_RBX[2];
    if (*(char *)((longlong)plVar9 + 0x19) == '\0') {
      cVar1 = *(char *)(*plVar9 + 0x19);
      unaff_RBX = plVar9;
      plVar9 = (longlong *)*plVar9;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*plVar9 + 0x19);
        unaff_RBX = plVar9;
        plVar9 = (longlong *)*plVar9;
      }
    }
    else {
      cVar1 = *(char *)(unaff_RBX[1] + 0x19);
      plVar10 = (longlong *)unaff_RBX[1];
      plVar9 = unaff_RBX;
      while ((unaff_RBX = plVar10, cVar1 == '\0' && (plVar9 == (longlong *)unaff_RBX[2]))) {
        cVar1 = *(char *)(unaff_RBX[1] + 0x19);
        plVar10 = (longlong *)unaff_RBX[1];
        plVar9 = unaff_RBX;
      }
    }
  } while (unaff_RBX != unaff_R14);
  uVar13 = 0;
LAB_18001df5a:
  if (0xf < unaff_R15) {
    puVar12 = unaff_RBP;
    if ((0xfff < unaff_R15 + 1) &&
       (puVar12 = *(undefined1 **)(unaff_RBP + -8),
       (undefined1 *)0x1f < unaff_RBP + (-8 - (longlong)puVar12))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(puVar12);
  }
  return uVar13;
}

/* ---- FUNC 0001DF5F FUN_18001df5f (33 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_18001df5f(void)

{
  void *unaff_RBP;
  void *pvVar1;
  undefined4 unaff_EDI;
  ulonglong unaff_R15;
  
  if (0xf < unaff_R15) {
    pvVar1 = unaff_RBP;
    if ((0xfff < unaff_R15 + 1) &&
       (pvVar1 = *(void **)((longlong)unaff_RBP + -8),
       0x1f < (ulonglong)((longlong)unaff_RBP + (-8 - (longlong)pvVar1)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar1);
  }
  return unaff_EDI;
}

/* ---- FUNC 0001DF80 FUN_18001df80 (43 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_18001df80(void)

{
  void *unaff_RBP;
  void *pvVar1;
  undefined4 unaff_EDI;
  longlong unaff_R15;
  
  pvVar1 = unaff_RBP;
  if ((0xfff < unaff_R15 + 1U) &&
     (pvVar1 = *(void **)((longlong)unaff_RBP + -8),
     0x1f < (ulonglong)((longlong)unaff_RBP + (-8 - (longlong)pvVar1)))) {
                    /* WARNING: Subroutine does not return */
    _invalid_parameter_noinfo_noreturn();
  }
  operator_delete(pvVar1);
  return unaff_EDI;
}

/* ---- FUNC 0001DFAC FUN_18001dfac (78 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18001dfac(void)

{
  char cVar1;
  longlong in_RAX;
  char *pcVar2;
  void *unaff_RBP;
  void *pvVar3;
  longlong lVar4;
  longlong unaff_R13;
  ulonglong unaff_R15;
  
  pcVar2 = (char *)(in_RAX + 0x20);
  lVar4 = unaff_R13 - (longlong)pcVar2;
  do {
    cVar1 = *pcVar2;
    pcVar2[lVar4] = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  pcVar2 = (char *)(in_RAX + 0x2c);
  lVar4 = unaff_R13 - (longlong)pcVar2;
  do {
    cVar1 = *pcVar2;
    pcVar2[lVar4 + 0xc] = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  if (0xf < unaff_R15) {
    pvVar3 = unaff_RBP;
    if ((0xfff < unaff_R15 + 1) &&
       (pvVar3 = *(void **)((longlong)unaff_RBP + -8),
       0x1f < (ulonglong)((longlong)unaff_RBP + (-8 - (longlong)pvVar3)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar3);
  }
  return 1;
}

/* ---- FUNC 0001DFFA FUN_18001dffa (32 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_18001dffa(void)

{
  void *unaff_RBP;
  undefined4 unaff_EDI;
  
  operator_delete(unaff_RBP);
  return unaff_EDI;
}

/* ---- FUNC 0001E020 Read90CArestoreMapforOption (24 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void Read90CArestoreMapforOption(void *param_1,longlong param_2)

{
  char cVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined8 ******ppppppuVar6;
  ulonglong uVar7;
  undefined8 *puVar8;
  longlong *plVar9;
  int iVar10;
  longlong *plVar11;
  char *pcVar12;
  undefined8 *******pppppppuVar13;
  longlong lVar14;
  size_t sVar15;
  undefined1 auStack_78 [32];
  undefined8 ******local_58;
  undefined8 uStack_50;
  size_t local_48;
  ulonglong local_40;
  ulonglong local_38;
  
                    /* 0x1e020  425  Read90CArestoreMapforOption */
  local_38 = DAT_1800791f8 ^ (ulonglong)auStack_78;
  local_58 = (undefined8 *******)0x0;
  uStack_50 = 0;
  local_48 = 0;
  local_40 = 0;
  sVar15 = 0xffffffffffffffff;
  do {
    sVar15 = sVar15 + 1;
  } while (*(char *)((longlong)param_1 + sVar15) != '\0');
  FUN_18000b5f0(&local_58,param_1,sVar15);
  uVar7 = local_40;
  sVar15 = local_48;
  ppppppuVar6 = local_58;
  puVar5 = DAT_18007a288;
  plVar2 = (longlong *)*DAT_18007a288;
  do {
    if (plVar2 == puVar5) {
FUN_18001e1b4:
      if (0xf < uVar7) {
        pppppppuVar13 = (undefined8 *******)ppppppuVar6;
        if ((0xfff < uVar7 + 1) &&
           (pppppppuVar13 = (undefined8 *******)ppppppuVar6[-1],
           0x1f < (ulonglong)((longlong)ppppppuVar6 + (-8 - (longlong)pppppppuVar13)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        operator_delete(pppppppuVar13);
      }
      return;
    }
    plVar11 = plVar2 + 4;
    pppppppuVar13 = &local_58;
    if (0xf < uVar7) {
      pppppppuVar13 = (undefined8 *******)ppppppuVar6;
    }
    if (0xf < (ulonglong)plVar2[7]) {
      plVar11 = (longlong *)plVar2[4];
    }
    if ((plVar2[6] == sVar15) && (iVar10 = memcmp(plVar11,pppppppuVar13,plVar2[6]), iVar10 == 0)) {
      puVar3 = *(undefined8 **)plVar2[8];
      while (puVar3 != (undefined8 *)plVar2[8]) {
        plVar11 = *(longlong **)puVar3[5];
        if (plVar11 != (longlong *)puVar3[5]) {
          pcVar12 = (char *)(plVar11 + 4);
          lVar14 = param_2 - (longlong)pcVar12;
          do {
            cVar1 = *pcVar12;
            pcVar12[lVar14] = cVar1;
            pcVar12 = pcVar12 + 1;
          } while (cVar1 != '\0');
          goto FUN_18001e1b4;
        }
        puVar4 = (undefined8 *)puVar3[2];
        if (*(char *)((longlong)puVar4 + 0x19) == '\0') {
          cVar1 = *(char *)((longlong)*puVar4 + 0x19);
          puVar3 = puVar4;
          puVar4 = (undefined8 *)*puVar4;
          while (cVar1 == '\0') {
            cVar1 = *(char *)((longlong)*puVar4 + 0x19);
            puVar3 = puVar4;
            puVar4 = (undefined8 *)*puVar4;
          }
        }
        else {
          cVar1 = *(char *)((longlong)puVar3[1] + 0x19);
          puVar8 = (undefined8 *)puVar3[1];
          puVar4 = puVar3;
          while ((puVar3 = puVar8, cVar1 == '\0' && (puVar4 == (undefined8 *)puVar3[2]))) {
            cVar1 = *(char *)((longlong)puVar3[1] + 0x19);
            puVar8 = (undefined8 *)puVar3[1];
            puVar4 = puVar3;
          }
        }
      }
    }
    plVar11 = (longlong *)plVar2[2];
    if (*(char *)((longlong)plVar11 + 0x19) == '\0') {
      cVar1 = *(char *)(*plVar11 + 0x19);
      plVar2 = plVar11;
      plVar11 = (longlong *)*plVar11;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*plVar11 + 0x19);
        plVar2 = plVar11;
        plVar11 = (longlong *)*plVar11;
      }
    }
    else {
      cVar1 = *(char *)(plVar2[1] + 0x19);
      plVar9 = (longlong *)plVar2[1];
      plVar11 = plVar2;
      while ((plVar2 = plVar9, cVar1 == '\0' && (plVar11 == (longlong *)plVar2[2]))) {
        cVar1 = *(char *)(plVar2[1] + 0x19);
        plVar9 = (longlong *)plVar2[1];
        plVar11 = plVar2;
      }
    }
  } while( true );
}

/* ---- FUNC 0001E038 FUN_18001e038 (91 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18001e038(void *param_1,longlong param_2)

{
  char cVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined8 ******ppppppuVar6;
  undefined8 *puVar7;
  longlong *plVar8;
  int iVar9;
  longlong *plVar10;
  char *pcVar11;
  undefined8 *******pppppppuVar12;
  undefined8 unaff_RBX;
  undefined8 unaff_RSI;
  size_t sVar13;
  longlong in_R11;
  undefined8 unaff_R14;
  undefined8 ******ppppppuStackX_20;
  undefined8 uStack0000000000000028;
  size_t in_stack_00000030;
  ulonglong in_stack_00000038;
  
  *(undefined8 *)(in_R11 + 0x18) = unaff_RBX;
  *(undefined8 *)(in_R11 + -0x18) = unaff_RSI;
  ppppppuStackX_20 = (undefined8 *******)0x0;
  uStack0000000000000028 = 0;
  *(undefined8 *)(in_R11 + -0x48) = 0;
  *(undefined8 *)(in_R11 + -0x40) = 0;
  sVar13 = 0xffffffffffffffff;
  *(undefined8 *)(in_R11 + -0x20) = unaff_R14;
  do {
    sVar13 = sVar13 + 1;
  } while (*(char *)((longlong)param_1 + sVar13) != '\0');
  FUN_18000b5f0(&ppppppuStackX_20,param_1,sVar13);
  ppppppuVar6 = ppppppuStackX_20;
  puVar5 = DAT_18007a288;
  plVar2 = (longlong *)*DAT_18007a288;
  do {
    if (plVar2 == puVar5) {
FUN_18001e1b4:
      if (0xf < in_stack_00000038) {
        pppppppuVar12 = (undefined8 *******)ppppppuVar6;
        if ((0xfff < in_stack_00000038 + 1) &&
           (pppppppuVar12 = (undefined8 *******)ppppppuVar6[-1],
           0x1f < (ulonglong)((longlong)ppppppuVar6 + (-8 - (longlong)pppppppuVar12)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        operator_delete(pppppppuVar12);
      }
      return;
    }
    plVar10 = plVar2 + 4;
    pppppppuVar12 = &ppppppuStackX_20;
    if (0xf < in_stack_00000038) {
      pppppppuVar12 = (undefined8 *******)ppppppuVar6;
    }
    if (0xf < (ulonglong)plVar2[7]) {
      plVar10 = (longlong *)plVar2[4];
    }
    if ((plVar2[6] == in_stack_00000030) &&
       (iVar9 = memcmp(plVar10,pppppppuVar12,plVar2[6]), iVar9 == 0)) {
      puVar3 = *(undefined8 **)plVar2[8];
      while (puVar3 != (undefined8 *)plVar2[8]) {
        plVar10 = *(longlong **)puVar3[5];
        if (plVar10 != (longlong *)puVar3[5]) {
          pcVar11 = (char *)(plVar10 + 4);
          param_2 = param_2 - (longlong)pcVar11;
          do {
            cVar1 = *pcVar11;
            pcVar11[param_2] = cVar1;
            pcVar11 = pcVar11 + 1;
          } while (cVar1 != '\0');
          goto FUN_18001e1b4;
        }
        puVar4 = (undefined8 *)puVar3[2];
        if (*(char *)((longlong)puVar4 + 0x19) == '\0') {
          cVar1 = *(char *)((longlong)*puVar4 + 0x19);
          puVar3 = puVar4;
          puVar4 = (undefined8 *)*puVar4;
          while (cVar1 == '\0') {
            cVar1 = *(char *)((longlong)*puVar4 + 0x19);
            puVar3 = puVar4;
            puVar4 = (undefined8 *)*puVar4;
          }
        }
        else {
          cVar1 = *(char *)((longlong)puVar3[1] + 0x19);
          puVar7 = (undefined8 *)puVar3[1];
          puVar4 = puVar3;
          while ((puVar3 = puVar7, cVar1 == '\0' && (puVar4 == (undefined8 *)puVar3[2]))) {
            cVar1 = *(char *)((longlong)puVar3[1] + 0x19);
            puVar7 = (undefined8 *)puVar3[1];
            puVar4 = puVar3;
          }
        }
      }
    }
    plVar10 = (longlong *)plVar2[2];
    if (*(char *)((longlong)plVar10 + 0x19) == '\0') {
      cVar1 = *(char *)(*plVar10 + 0x19);
      plVar2 = plVar10;
      plVar10 = (longlong *)*plVar10;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*plVar10 + 0x19);
        plVar2 = plVar10;
        plVar10 = (longlong *)*plVar10;
      }
    }
    else {
      cVar1 = *(char *)(plVar2[1] + 0x19);
      plVar8 = (longlong *)plVar2[1];
      plVar10 = plVar2;
      while ((plVar2 = plVar8, cVar1 == '\0' && (plVar10 == (longlong *)plVar2[2]))) {
        cVar1 = *(char *)(plVar2[1] + 0x19);
        plVar8 = (longlong *)plVar2[1];
        plVar10 = plVar2;
      }
    }
  } while( true );
}

/* ---- FUNC 0001E093 FUN_18001e093 (289 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18001e093(void)

{
  char cVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  longlong *plVar5;
  int iVar6;
  longlong *plVar7;
  char *pcVar8;
  undefined1 *puVar9;
  longlong *unaff_RBX;
  ulonglong unaff_RBP;
  longlong unaff_RSI;
  longlong lVar10;
  undefined1 *unaff_RDI;
  longlong *unaff_R14;
  undefined1 auStackX_20 [8];
  size_t in_stack_00000030;
  
  do {
    plVar7 = unaff_RBX + 4;
    puVar9 = auStackX_20;
    if (0xf < unaff_RBP) {
      puVar9 = unaff_RDI;
    }
    if (0xf < (ulonglong)unaff_RBX[7]) {
      plVar7 = (longlong *)unaff_RBX[4];
    }
    if ((unaff_RBX[6] == in_stack_00000030) &&
       (iVar6 = memcmp(plVar7,puVar9,unaff_RBX[6]), iVar6 == 0)) {
      puVar2 = *(undefined8 **)unaff_RBX[8];
      while (puVar2 != (undefined8 *)unaff_RBX[8]) {
        plVar7 = *(longlong **)puVar2[5];
        if (plVar7 != (longlong *)puVar2[5]) {
          pcVar8 = (char *)(plVar7 + 4);
          lVar10 = unaff_RSI - (longlong)pcVar8;
          do {
            cVar1 = *pcVar8;
            pcVar8[lVar10] = cVar1;
            pcVar8 = pcVar8 + 1;
          } while (cVar1 != '\0');
          goto LAB_18001e1af;
        }
        puVar3 = (undefined8 *)puVar2[2];
        if (*(char *)((longlong)puVar3 + 0x19) == '\0') {
          cVar1 = *(char *)((longlong)*puVar3 + 0x19);
          puVar2 = puVar3;
          puVar3 = (undefined8 *)*puVar3;
          while (cVar1 == '\0') {
            cVar1 = *(char *)((longlong)*puVar3 + 0x19);
            puVar2 = puVar3;
            puVar3 = (undefined8 *)*puVar3;
          }
        }
        else {
          cVar1 = *(char *)((longlong)puVar2[1] + 0x19);
          puVar4 = (undefined8 *)puVar2[1];
          puVar3 = puVar2;
          while ((puVar2 = puVar4, cVar1 == '\0' && (puVar3 == (undefined8 *)puVar2[2]))) {
            cVar1 = *(char *)((longlong)puVar2[1] + 0x19);
            puVar4 = (undefined8 *)puVar2[1];
            puVar3 = puVar2;
          }
        }
      }
    }
    plVar7 = (longlong *)unaff_RBX[2];
    if (*(char *)((longlong)plVar7 + 0x19) == '\0') {
      cVar1 = *(char *)(*plVar7 + 0x19);
      unaff_RBX = plVar7;
      plVar7 = (longlong *)*plVar7;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*plVar7 + 0x19);
        unaff_RBX = plVar7;
        plVar7 = (longlong *)*plVar7;
      }
    }
    else {
      cVar1 = *(char *)(unaff_RBX[1] + 0x19);
      plVar5 = (longlong *)unaff_RBX[1];
      plVar7 = unaff_RBX;
      while ((unaff_RBX = plVar5, cVar1 == '\0' && (plVar7 == (longlong *)unaff_RBX[2]))) {
        cVar1 = *(char *)(unaff_RBX[1] + 0x19);
        plVar5 = (longlong *)unaff_RBX[1];
        plVar7 = unaff_RBX;
      }
    }
  } while (unaff_RBX != unaff_R14);
LAB_18001e1af:
  if (0xf < unaff_RBP) {
    puVar9 = unaff_RDI;
    if ((0xfff < unaff_RBP + 1) &&
       (puVar9 = *(undefined1 **)(unaff_RDI + -8),
       (undefined1 *)0x1f < unaff_RDI + (-8 - (longlong)puVar9))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(puVar9);
  }
  return;
}

/* ---- FUNC 0001E1B4 FUN_18001e1b4 (24 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18001e1b4(void)

{
  ulonglong unaff_RBP;
  void *unaff_RDI;
  void *pvVar1;
  
  if (0xf < unaff_RBP) {
    pvVar1 = unaff_RDI;
    if ((0xfff < unaff_RBP + 1) &&
       (pvVar1 = *(void **)((longlong)unaff_RDI + -8),
       0x1f < (ulonglong)((longlong)unaff_RDI + (-8 - (longlong)pvVar1)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar1);
  }
  return;
}

/* ---- FUNC 0001E1CC FUN_18001e1cc (72 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18001e1cc(void)

{
  longlong unaff_RBP;
  void *unaff_RDI;
  void *pvVar1;
  
  pvVar1 = unaff_RDI;
  if ((0xfff < unaff_RBP + 1U) &&
     (pvVar1 = *(void **)((longlong)unaff_RDI + -8),
     0x1f < (ulonglong)((longlong)unaff_RDI + (-8 - (longlong)pvVar1)))) {
                    /* WARNING: Subroutine does not return */
    _invalid_parameter_noinfo_noreturn();
  }
  operator_delete(pvVar1);
  return;
}

/* ---- FUNC 0001E220 ReadACEStringFromBKP (955 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

char * ReadACEStringFromBKP(undefined8 param_1,undefined8 param_2)

{
  ulonglong uVar1;
  void *_Src;
  int iVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  char ****ppppcVar5;
  char *pcVar6;
  char ****ppppcVar7;
  ulonglong _Size;
  ulonglong uVar8;
  ulonglong uVar9;
  undefined1 auStackY_498 [32];
  void *local_468;
  longlong *local_460;
  char ***local_458;
  undefined8 uStack_450;
  ulonglong local_448;
  ulonglong local_440;
  undefined1 local_438 [1008];
  ulonglong local_48;
  
                    /* 0x1e220  426  ReadACEStringFromBKP */
  local_48 = DAT_1800791f8 ^ (ulonglong)auStackY_498;
  puVar4 = (undefined8 *)0x0;
  local_460 = (longlong *)0x0;
  puVar3 = operator_new(0x138);
  if (puVar3 != (undefined8 *)0x0) {
    puVar4 = FUN_180018980(puVar3,param_1,0,param_2,0,0);
  }
  iVar2 = (**(code **)*puVar4)(puVar4,&DAT_180057a78);
  if (iVar2 != 0) {
    FUN_180007de0(local_438,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\bkputil.cpp",0x943);
    LogMessage(local_438);
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_468);
  local_448 = 0;
  uStack_450 = 0;
  local_458 = (char ***)0x0;
  local_440 = 0xf;
  do {
    FUN_18001b840(local_460,
                  (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_468);
    iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_468,
                       "$_END_ACE_STRING\n");
    if (iVar2 == 0) break;
    iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_468,
                       "$_ACE_STRING\n");
    uVar9 = local_440;
    _Src = local_468;
    ppppcVar5 = (char ****)local_458;
    if (iVar2 != 0) {
      if (local_448 == 0) {
        _Size = 0xffffffffffffffff;
        do {
          _Size = _Size + 1;
        } while (*(char *)((longlong)local_468 + _Size) != '\0');
        if (local_440 < _Size) {
          if (0x7fffffffffffffff < _Size) {
                    /* WARNING: Subroutine does not return */
            FUN_18000ace0();
          }
          uVar8 = _Size | 0xf;
          if (uVar8 < 0x8000000000000000) {
            if (0x7fffffffffffffff - (local_440 >> 1) < local_440) {
              uVar8 = 0x7fffffffffffffff;
              ppppcVar5 = (char ****)FUN_180007f10(0x8000000000000000);
            }
            else {
              uVar1 = (local_440 >> 1) + local_440;
              if (uVar8 < uVar1) {
                uVar8 = uVar1;
              }
              uVar1 = uVar8 + 1;
              if (uVar1 < 0x1000) {
                if (uVar1 == 0) {
                  ppppcVar5 = (char ****)0x0;
                }
                else {
                  ppppcVar5 = operator_new(uVar1);
                }
              }
              else {
                ppppcVar5 = (char ****)FUN_180007f10(uVar1);
              }
            }
          }
          else {
            uVar8 = 0x7fffffffffffffff;
            ppppcVar5 = (char ****)FUN_180007f10(0x8000000000000000);
          }
          local_448 = _Size;
          local_440 = uVar8;
          memcpy(ppppcVar5,_Src,_Size);
          *(char *)((longlong)ppppcVar5 + _Size) = '\0';
          if (0xf < uVar9) {
            ppppcVar7 = (char ****)local_458;
            if ((0xfff < uVar9 + 1) &&
               (ppppcVar7 = (char ****)local_458[-1],
               (char *)0x1f < (char *)((longlong)local_458 + (-8 - (longlong)ppppcVar7))))
            goto LAB_18001e580;
            operator_delete(ppppcVar7);
          }
        }
        else {
          ppppcVar5 = &local_458;
          if (0xf < local_440) {
            ppppcVar5 = (char ****)local_458;
          }
          local_448 = _Size;
          memmove(ppppcVar5,local_468,_Size);
          *(char *)((longlong)ppppcVar5 + _Size) = '\0';
          ppppcVar5 = (char ****)local_458;
        }
      }
      else {
        uVar9 = 0xffffffffffffffff;
        do {
          uVar9 = uVar9 + 1;
        } while (*(char *)((longlong)local_468 + uVar9) != '\0');
        if (local_440 - local_448 < uVar9) {
          FUN_180017f00(&local_458,uVar9,0,local_468,uVar9);
          ppppcVar5 = (char ****)local_458;
        }
        else {
          ppppcVar5 = &local_458;
          if (0xf < local_440) {
            ppppcVar5 = (char ****)local_458;
          }
          pcVar6 = (char *)((longlong)ppppcVar5 + local_448);
          local_448 = uVar9 + local_448;
          memmove(pcVar6,local_468,uVar9);
          pcVar6[uVar9] = '\0';
          ppppcVar5 = (char ****)local_458;
        }
      }
    }
    local_458 = (char ***)ppppcVar5;
    iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_468,
                       "$_END_ACE_STRING\n");
  } while (iVar2 != 0);
  (**(code **)(*local_460 + 0x10))();
  ppppcVar5 = &local_458;
  if (0xf < local_440) {
    ppppcVar5 = (char ****)local_458;
  }
  pcVar6 = _strdup((char *)ppppcVar5);
  if (0xf < local_440) {
    ppppcVar5 = (char ****)local_458;
    if ((0xfff < local_440 + 1) &&
       (ppppcVar5 = (char ****)local_458[-1],
       (char *)0x1f < (char *)((longlong)local_458 + (-8 - (longlong)ppppcVar5)))) {
LAB_18001e580:
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(ppppcVar5);
  }
  local_448 = 0;
  local_440 = 0xf;
  local_458 = (char ***)((ulonglong)local_458 & 0xffffffffffffff00);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_468);
  return pcVar6;
}

/* ---- FUNC 0001E5E0 ReadACEStringFromIStream (273 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 ReadACEStringFromIStream(longlong *param_1)

{
  ulonglong uVar1;
  int iVar2;
  char *pcVar3;
  ulonglong uVar4;
  undefined1 auStack_a8 [32];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_88 [8];
  undefined8 local_80;
  undefined1 local_78 [16];
  undefined8 local_68;
  undefined8 uStack_60;
  ulonglong local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
                    /* 0x1e5e0  427  ReadACEStringFromIStream */
  local_18 = DAT_1800791f8 ^ (ulonglong)auStack_a8;
  if (param_1 != (longlong *)0x0) {
    local_68 = 0;
    uStack_60 = 0;
    local_58 = 0;
    uStack_50 = 0;
    local_48 = 0;
    uStack_40 = 0;
    local_38 = 0;
    uStack_30 = 0;
    local_28 = 0;
    uStack_20 = 0;
    (**(code **)(*param_1 + 0x60))(0,&local_68,1);
    uVar1 = local_58;
    iVar2 = (int)local_58;
    uVar4 = local_58 & 0xffffffff;
    pcVar3 = operator_new__((ulonglong)((int)local_58 + 1));
    (**(code **)(*param_1 + 0x18))(param_1,pcVar3,uVar1 & 0xffffffff,local_78);
    if (iVar2 == 0) {
      return 0x80004005;
    }
    pcVar3[uVar4] = '\0';
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_88,pcVar3);
    iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
                      (local_88,'>');
    if (iVar2 != -1) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Mid
                (local_88,(int)&local_80,0);
      FUN_180019cc0(local_80);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_80);
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_88);
  }
  return 0;
}

/* ---- FUNC 0001E700 ReadApwnBlockFromBuffer (237 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ReadApwnBlockFromBuffer(char *param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 *puVar2;
  undefined1 auStackY_448 [32];
  undefined1 local_408 [1008];
  ulonglong local_18;
  
                    /* 0x1e700  428  ReadApwnBlockFromBuffer */
  local_18 = DAT_1800791f8 ^ (ulonglong)auStackY_448;
  puVar2 = operator_new(0x118);
  if (puVar2 == (undefined8 *)0x0) {
    puVar2 = (undefined8 *)0x0;
  }
  else {
    puVar2 = FUN_180018910(puVar2,param_2,0,0);
  }
  iVar1 = (**(code **)*puVar2)(puVar2,&DAT_180057a78);
  if (iVar1 != 0) {
    FUN_180007de0(local_408,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\bkputil.cpp",0x729);
    LogMessage(local_408);
  }
  if (g_pApwnBlockUsage != (CApwnBlockUsage *)0x0) {
    FUN_180005d90(g_pApwnBlockUsage,(longlong *)0x0,(HWND)0x0,param_1,(CMapStringToString *)0x0);
  }
  (**(code **)(_DAT_00000000 + 0x10))();
  return;
}

/* ---- FUNC 0001E7F0 ReadApwnBlockFromFile (312 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ReadApwnBlockFromFile(undefined8 param_1,char *param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  undefined1 auStackY_488 [32];
  CApwnBlockUsage local_450 [56];
  undefined1 local_418 [1008];
  ulonglong local_28;
  
                    /* 0x1e7f0  429  ReadApwnBlockFromFile */
  local_28 = DAT_1800791f8 ^ (ulonglong)auStackY_488;
  puVar3 = (undefined8 *)0x0;
  puVar2 = operator_new(0x138);
  if (puVar2 != (undefined8 *)0x0) {
    puVar3 = FUN_180018980(puVar2,param_1,0,param_3,0,0);
  }
  iVar1 = (**(code **)*puVar3)();
  if (iVar1 != 0) {
    FUN_180007de0(local_418,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\bkputil.cpp",0x751);
    LogMessage(local_418);
  }
  if (g_pApwnBlockUsage == (CApwnBlockUsage *)0x0) {
    uVar4 = FUN_1800240b0();
    if ((int)uVar4 == 2) {
      CApwnBlockUsage::CApwnBlockUsage(local_450,(CApwnLibraries *)0x0,(IAModel *)0x0);
      FUN_180005d90(local_450,(longlong *)0x0,(HWND)0x0,param_2,(CMapStringToString *)0x0);
      CApwnBlockUsage::~CApwnBlockUsage(local_450);
    }
  }
  else {
    FUN_180005d90(g_pApwnBlockUsage,(longlong *)0x0,(HWND)0x0,param_2,(CMapStringToString *)0x0);
  }
  (**(code **)(_DAT_00000000 + 0x10))();
  return;
}

/* ---- FUNC 0001E930 ReadApwnBlockUsagesFromBuffer (224 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ReadApwnBlockUsagesFromBuffer
               (longlong *param_1,longlong param_2,int param_3,char *param_4,undefined8 param_5)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this;
  char *pcVar4;
  undefined8 *puVar5;
  longlong lVar6;
  undefined1 auStackY_4b8 [32];
  char *local_480;
  CMapStringToString local_478 [64];
  undefined1 local_438 [1008];
  ulonglong local_48;
  
                    /* 0x1e930  430  ReadApwnBlockUsagesFromBuffer */
  local_48 = DAT_1800791f8 ^ (ulonglong)auStackY_4b8;
  puVar5 = (undefined8 *)0x0;
  puVar2 = operator_new(0x118);
  puVar3 = puVar5;
  if (puVar2 != (undefined8 *)0x0) {
    puVar3 = FUN_180018910(puVar2,param_5,0,0);
  }
  iVar1 = (**(code **)*puVar3)(puVar3,&DAT_180057a78);
  if (iVar1 != 0) {
    FUN_180007de0(local_438,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\bkputil.cpp",0x737);
    LogMessage(local_438);
  }
  if (g_pApwnBlockUsage != (CApwnBlockUsage *)0x0) {
    if (param_3 == 0) {
      FUN_180005d90(g_pApwnBlockUsage,(longlong *)0x0,(HWND)0x0,param_4,(CMapStringToString *)0x0);
    }
    else {
      CMapStringToString::CMapStringToString(local_478,(longlong)param_3);
      if (0 < param_3) {
        lVar6 = param_2 - (longlong)param_1;
        do {
          if (*param_1 == 0) break;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_480);
          if ((param_2 == 0) ||
             (pcVar4 = *(char **)(lVar6 + (longlong)param_1), pcVar4 == (char *)0x0)) {
            pcVar4 = (char *)*param_1;
          }
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_480,
                     pcVar4);
          pcVar4 = local_480;
          this = CMapStringToString::operator[](local_478,(char *)*param_1);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(this,pcVar4)
          ;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_480);
          puVar5 = (undefined8 *)((longlong)puVar5 + 1);
          param_1 = param_1 + 1;
        } while ((longlong)puVar5 < (longlong)param_3);
      }
      FUN_180005d90(g_pApwnBlockUsage,(longlong *)0x0,(HWND)0x0,param_4,local_478);
      CMapStringToString::~CMapStringToString(local_478);
    }
  }
  (**(code **)(_DAT_00000000 + 0x10))();
  return;
}

/* ---- FUNC 0001EA10 FUN_18001ea10 (183 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18001ea10(void)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this;
  char *pcVar1;
  __int64 unaff_RBX;
  longlong unaff_RBP;
  longlong lVar2;
  longlong *unaff_RDI;
  char *unaff_R12;
  longlong unaff_R14;
  longlong *in_stack_00000030;
  char *in_stack_00000038;
  
  CMapStringToString::CMapStringToString((CMapStringToString *)&stack0x00000040,unaff_RBX);
  if (0 < (int)unaff_RBX) {
    lVar2 = unaff_R14 - (longlong)unaff_RDI;
    do {
      if (*unaff_RDI == 0) break;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&stack0x00000038);
      if ((unaff_R14 == 0) ||
         (pcVar1 = *(char **)(lVar2 + (longlong)unaff_RDI), pcVar1 == (char *)0x0)) {
        pcVar1 = (char *)*unaff_RDI;
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&stack0x00000038,
                 pcVar1);
      pcVar1 = in_stack_00000038;
      this = CMapStringToString::operator[]
                       ((CMapStringToString *)&stack0x00000040,(char *)*unaff_RDI);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(this,pcVar1);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&stack0x00000038);
      unaff_RBP = unaff_RBP + 1;
      unaff_RDI = unaff_RDI + 1;
    } while (unaff_RBP < unaff_RBX);
  }
  FUN_180005d90(g_pApwnBlockUsage,in_stack_00000030,(HWND)0x0,unaff_R12,
                (CMapStringToString *)&stack0x00000040);
  CMapStringToString::~CMapStringToString((CMapStringToString *)&stack0x00000040);
  (**(code **)(*in_stack_00000030 + 0x10))();
  return;
}

/* ---- FUNC 0001EAC7 FUN_18001eac7 (43 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18001eac7(void)

{
  longlong *in_stack_00000030;
  
  (**(code **)(*in_stack_00000030 + 0x10))();
  return;
}

/* ---- FUNC 0001EB00 ReadApwnLibFromBuffer (206 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void ReadApwnLibFromBuffer(undefined8 param_1)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined1 auStack_438 [32];
  IStream *local_418 [2];
  undefined1 local_408 [1008];
  ulonglong local_18;
  
                    /* 0x1eb00  431  ReadApwnLibFromBuffer */
  local_18 = DAT_1800791f8 ^ (ulonglong)auStack_438;
  puVar3 = (undefined8 *)0x0;
  local_418[0] = (IStream *)0x0;
  puVar2 = operator_new(0x118);
  if (puVar2 != (undefined8 *)0x0) {
    puVar3 = FUN_180018910(puVar2,param_1,0,0);
  }
  iVar1 = (**(code **)*puVar3)(puVar3,&DAT_180057a78,local_418);
  if (iVar1 != 0) {
    FUN_180007de0(local_408,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\bkputil.cpp",0x620);
    LogMessage(local_408,2,1);
  }
  ApwnLibRestoreFromText(local_418[0],(HWND__ *)0x0);
  (*local_418[0]->lpVtbl->Release)(local_418[0]);
  return;
}

/* ---- FUNC 0001EBD0 ReadApwnLibFromFile (405 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 ReadApwnLibFromFile(longlong param_1,undefined8 param_2,int param_3,undefined *param_4)

{
  char cVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined4 uVar4;
  undefined1 auStackY_468 [32];
  IStream *local_438;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_430 [8];
  undefined1 local_428 [1008];
  ulonglong local_38;
  
                    /* 0x1ebd0  432  ReadApwnLibFromFile */
  local_38 = DAT_1800791f8 ^ (ulonglong)auStackY_468;
  local_438 = (IStream *)0x0;
  uVar4 = 1;
  if (param_1 != 0) {
    puVar3 = operator_new(0x138);
    if (puVar3 == (undefined8 *)0x0) {
      puVar3 = (undefined8 *)0x0;
    }
    else {
      puVar3 = FUN_180018980(puVar3,param_1,0,param_2,0,0);
    }
    iVar2 = (**(code **)*puVar3)(puVar3,&DAT_180057a78,&local_438);
    if (iVar2 != 0) {
      FUN_180007de0(local_428,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\bkputil.cpp",0x6d2);
      LogMessage(local_428,2,1);
      ApwnLibRestoreFromText(local_438,(HWND__ *)0x0);
      goto LAB_18001ec9e;
    }
  }
  ApwnLibRestoreFromText(local_438,(HWND__ *)0x0);
  if (param_1 == 0) {
    if (local_438 == (IStream *)0x0) {
      return 1;
    }
    (*local_438->lpVtbl->Release)(local_438);
    return 1;
  }
LAB_18001ec9e:
  if (local_438 != (IStream *)0x0) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_430);
    FUN_18001b840((longlong *)local_438,local_430);
    if (local_438 != (IStream *)0x0) {
      (*local_438->lpVtbl->Release)(local_438);
    }
    iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                      (local_430,"$_IDENTIFIERS\n");
    if (iVar2 == 0) {
      ReadBlockGUIDsFromBKP(param_1,param_2,param_3,param_4);
    }
    else {
      cVar1 = ATL::CSimpleStringT<char,1>::GetAt((CSimpleStringT<char,1> *)local_430,0);
      if (cVar1 == ';') {
        uVar4 = 0;
      }
      else {
        uVar4 = 0xffffffff;
      }
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_430);
  }
  return uVar4;
}

/* ---- FUNC 0001ED70 ReadApwnShellSettingFromBKP (551 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void ReadApwnShellSettingFromBKP(char *param_1,undefined8 param_2,undefined8 param_3,char *param_4)

{
  int iVar1;
  int *piVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  IAtlStringMgr *pIVar5;
  FILE *_File;
  undefined8 *puVar6;
  char *pcVar7;
  undefined1 auStackY_488 [32];
  char *local_458;
  char *local_450;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_448 [8];
  longlong *local_440;
  undefined1 local_438 [1008];
  ulonglong local_48;
  
                    /* 0x1ed70  433  ReadApwnShellSettingFromBKP */
  local_48 = DAT_1800791f8 ^ (ulonglong)auStackY_488;
  pcVar7 = param_4;
  piVar2 = (int *)SEGetSettingValue("ignoreapwnshellsettings",0);
  puVar4 = (undefined8 *)0x0;
  puVar6 = puVar4;
  if ((piVar2 != (int *)0x0) && (puVar6 = (undefined8 *)0x0, *piVar2 == 1)) {
    puVar6 = (undefined8 *)0x1;
  }
  local_440 = (longlong *)0x0;
  puVar3 = operator_new(0x138);
  if (puVar3 != (undefined8 *)0x0) {
    puVar4 = FUN_180018980(puVar3,param_2,0,param_4,0,0);
    pcVar7 = param_4;
  }
  iVar1 = (**(code **)*puVar4)(puVar4,&DAT_180057a78,&local_440);
  if (iVar1 != 0) {
    pcVar7 = (char *)0x912;
    FUN_180007de0(local_438,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\bkputil.cpp",0x912);
    LogMessage(local_438,2,1);
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_450);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_458);
  do {
    FUN_18001b840(local_440,
                  (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_450);
    iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_450,
                       "$_END_APWNSHELL_SETTINGS\n");
    if (iVar1 == 0) break;
    if (puVar6 != (undefined8 *)0x1) {
      if (*(int *)(local_458 + -0x10) == 0) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_458,
                   (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                   &local_450);
      }
      else {
        pIVar5 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                           ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            &local_458);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_448,pIVar5);
        pcVar7 = local_450;
        ATL::CSimpleStringT<char,1>::Concatenate
                  ((CSimpleStringT<char,1> *)local_448,local_458,*(int *)(local_458 + -0x10),
                   local_450,*(int *)(local_450 + -0x10));
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_458,
                   (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                   local_448);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_448);
      }
    }
    iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_450,
                       "$_END_APWNSHELL_SETTINGS\n");
  } while (iVar1 != 0);
  if (*(int *)(local_458 + -0x10) != 0) {
    _File = fopen(param_1,"w+");
    if (_File != (FILE *)0x0) {
      FUN_180022760(_File,&DAT_180053c08,local_458,pcVar7);
      fclose(_File);
    }
  }
  (**(code **)(*local_440 + 0x10))();
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_458);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_450);
  return;
}

/* ---- FUNC 0001EFA0 ReadApwnShellSettingsFromStreamToFile (332 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 ReadApwnShellSettingsFromStreamToFile(longlong *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  FILE *_File;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar3;
  ulonglong uVar4;
  undefined1 *puVar5;
  undefined1 auStack_b8 [32];
  undefined8 local_98;
  undefined1 local_90 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_88 [16];
  undefined8 local_78;
  undefined8 uStack_70;
  ulonglong local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
                    /* 0x1efa0  434  ReadApwnShellSettingsFromStreamToFile */
  local_28 = DAT_1800791f8 ^ (ulonglong)auStack_b8;
  if (param_1 != (longlong *)0x0) {
    local_78 = 0;
    uStack_70 = 0;
    local_68 = 0;
    uStack_60 = 0;
    local_58 = 0;
    uStack_50 = 0;
    local_48 = 0;
    uStack_40 = 0;
    local_38 = 0;
    uStack_30 = 0;
    (**(code **)(*param_1 + 0x60))(0,&local_78,1);
    iVar1 = (int)local_68;
    uVar4 = local_68 & 0xffffffff;
    pcVar2 = operator_new__((ulonglong)((int)local_68 + 1));
    puVar5 = local_90;
    (**(code **)(*param_1 + 0x18))(param_1,pcVar2);
    if (iVar1 != 0) {
      pcVar2[uVar4] = '\0';
      _File = fopen(param_2,"w+");
      if (_File != (FILE *)0x0) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_98,pcVar2
                  );
        iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_98,'>');
        if (iVar1 != -1) {
          puVar5 = (undefined1 *)(ulonglong)(iVar1 + 1);
          pCVar3 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                   ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Mid
                             ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                              &local_98,(int)local_88,0);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_98,
                     pCVar3);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_88);
        }
        FUN_180022760(_File,&DAT_180053c08,local_98,puVar5);
        fclose(_File);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_98);
      }
      return 0;
    }
  }
  return 0x80004005;
}

/* ---- FUNC 0001F0F0 ReadApwnShellSettingsInfoFromFile (54 bytes) ---- */

undefined *** ReadApwnShellSettingsInfoFromFile(char *param_1)

{
  int *piVar1;
  undefined ***pppuVar2;
  
                    /* 0x1f0f0  435  ReadApwnShellSettingsInfoFromFile */
  piVar1 = (int *)SEGetSettingValue("ignorereadapwnshellsettings",0);
  if ((piVar1 != (int *)0x0) && (*piVar1 == 1)) {
    return (undefined ***)0x0;
  }
  pppuVar2 = FUN_18001a550(param_1);
  return pppuVar2;
}

/* ---- FUNC 0001F130 ReadBlockGUIDsFromBKP (338 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 *
ReadBlockGUIDsFromBKP(undefined8 param_1,undefined8 param_2,int param_3,undefined *param_4)

{
  longlong lVar1;
  longlong *plVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  IAtlStringMgr *pIVar8;
  BSTR lpWideCharStr;
  BSTR lpWideCharStr_00;
  longlong *plVar9;
  undefined8 *puVar10;
  undefined1 auStackY_818 [32];
  longlong *local_7e8;
  longlong *local_7e0;
  longlong *local_7d8;
  char *local_7d0;
  longlong *local_7c8;
  undefined2 local_7c0 [4];
  longlong *local_7b8;
  longlong *local_7b0;
  longlong *local_7a8;
  char *local_7a0;
  longlong *local_798;
  LPCWSTR local_790;
  longlong *local_788;
  BSTR local_780;
  short local_778 [4];
  LPCWSTR local_770;
  short local_760 [4];
  LPCWSTR local_758;
  char *local_748;
  char local_740 [136];
  char *local_6b8;
  char local_6b0 [136];
  char *local_628;
  char local_620 [136];
  char local_598 [32];
  char local_578 [64];
  char local_538 [256];
  undefined1 local_438 [1008];
  ulonglong local_48;
  
                    /* 0x1f130  436  ReadBlockGUIDsFromBKP */
  local_48 = DAT_1800791f8 ^ (ulonglong)auStackY_818;
  puVar10 = (undefined8 *)0x0;
  local_788 = (longlong *)0x0;
  puVar6 = operator_new(0x138);
  puVar7 = puVar10;
  if (puVar6 != (undefined8 *)0x0) {
    puVar7 = FUN_180018980(puVar6,param_1,0,param_2,0,0);
  }
  puVar7 = (undefined8 *)(**(code **)*puVar7)(puVar7,&DAT_180057a78,&local_788);
  if ((int)puVar7 != 0) {
    return puVar7;
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7a0);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7d0);
  do {
    FUN_18001b840(local_788,
                  (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7a0);
    iVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7a0,
                       "$_END_IDENTIFIERS\n");
    if (iVar3 == 0) break;
    if (*(int *)(local_7d0 + -0x10) == 0) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7d0,
                 (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                 &local_7a0);
    }
    else {
      pIVar8 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                         ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                          &local_7d0);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7c8,pIVar8)
      ;
      ATL::CSimpleStringT<char,1>::Concatenate
                ((CSimpleStringT<char,1> *)&local_7c8,local_7d0,*(int *)(local_7d0 + -0x10),
                 local_7a0,*(int *)(local_7a0 + -0x10));
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7d0,
                 (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                 &local_7c8);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7c8);
    }
    iVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7a0,
                       "$_END_IDENTIFIERS\n");
  } while (iVar3 != 0);
  (**(code **)(*local_788 + 0x10))();
  if ((param_3 != 1) && (*(int *)(local_7d0 + -0x10) != 0)) {
    local_798 = (longlong *)0x0;
    local_7c0[0] = 0;
    uVar4 = CoCreateInstance((IID *)&DAT_1800542a8,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_180054680,
                             &local_798);
    if (uVar4 == 0) {
      FUN_180018810(&local_780,local_7d0);
      uVar4 = (**(code **)(*local_798 + 0x208))(local_798,local_780,local_7c0);
      if (uVar4 == 0) {
        local_7c8 = (longlong *)0x0;
        uVar4 = (**(code **)(*local_798 + 0x168))(local_798,&local_7c8);
        if (uVar4 == 0) {
          local_7d8 = (longlong *)0x0;
          local_7e0 = (longlong *)0x0;
          local_7e8 = (longlong *)0x0;
          local_7a8 = (longlong *)0x0;
          local_7b0 = (longlong *)0x0;
          local_7b8 = (longlong *)0x0;
          uVar4 = (**(code **)(*local_7c8 + 0x68))();
          if (uVar4 == 0) {
            local_790 = (LPCWSTR)0x0;
            iVar3 = MultiByteToWideChar(0,0,"Name",-1,(LPWSTR)0x0,0);
            lpWideCharStr = SysAllocStringLen((OLECHAR *)0x0,iVar3 - 1);
            if ((lpWideCharStr == (BSTR)0x0) ||
               (iVar5 = MultiByteToWideChar(0,0,"Name",-1,lpWideCharStr,iVar3),
               lpWideCharStr_00 = lpWideCharStr, iVar5 == iVar3)) {
              if (lpWideCharStr == (BSTR)0x0) goto LAB_18001f98a;
              iVar3 = MultiByteToWideChar(0,0,"GUID",-1,(LPWSTR)0x0,0);
              lpWideCharStr_00 = SysAllocStringLen((OLECHAR *)0x0,iVar3 - 1);
              if ((lpWideCharStr_00 == (BSTR)0x0) ||
                 (iVar5 = MultiByteToWideChar(0,0,"GUID",-1,lpWideCharStr_00,iVar3), iVar5 == iVar3)
                 ) {
                puVar7 = puVar10;
                if (lpWideCharStr_00 != (BSTR)0x0) {
                  do {
                    if (local_7d8 == (longlong *)0x0) break;
                    uVar4 = (**(code **)(*local_7d8 + 0x38))(local_7d8,&local_790);
                    plVar2 = local_7e8;
                    if (uVar4 != 0) {
LAB_18001f894:
                      SysFreeString(lpWideCharStr_00);
                      SysFreeString(lpWideCharStr);
                      SysFreeString(local_790);
                      goto LAB_18001f8b0;
                    }
                    if (local_7e8 != (longlong *)0x0) {
                      local_7e8 = (longlong *)0x0;
                      (**(code **)(*plVar2 + 0x10))();
                    }
                    uVar4 = (**(code **)(*local_7d8 + 0x68))(local_7d8,&local_7e8);
                    if (uVar4 != 0) goto LAB_18001f894;
                    iVar3 = (int)puVar7;
                    plVar2 = local_7e0;
                    plVar9 = local_7b8;
                    while ((local_7e0 = plVar2, local_7b8 = plVar9, iVar3 == 0 &&
                           (local_7e8 != (longlong *)0x0))) {
                      if (plVar9 != (longlong *)0x0) {
                        local_7b8 = (longlong *)0x0;
                        (**(code **)(*plVar9 + 0x10))();
                      }
                      uVar4 = (**(code **)(*local_7e8 + 0x88))(local_7e8,&local_7b8);
                      plVar2 = local_7b0;
                      if (uVar4 != 0) goto LAB_18001f894;
                      if ((local_7b0 != (longlong *)0x0) &&
                         (local_7b0 = (longlong *)0x0, plVar2 != (longlong *)0x0)) {
                        (**(code **)(*plVar2 + 0x10))();
                      }
                      plVar2 = local_7b0;
                      plVar9 = local_7a8;
                      if (local_7a8 != local_7b0) {
                        if (local_7b0 != (longlong *)0x0) {
                          (**(code **)(*local_7b0 + 8))(local_7b0);
                        }
                        plVar9 = plVar2;
                        if (local_7a8 != (longlong *)0x0) {
                          lVar1 = *local_7a8;
                          local_7a8 = plVar2;
                          (**(code **)(lVar1 + 0x10))();
                          plVar9 = local_7a8;
                        }
                      }
                      local_7a8 = plVar9;
                      uVar4 = (**(code **)(*local_7b8 + 0x38))(local_7b8,lpWideCharStr,&local_7a8);
                      if ((((uVar4 != 0) ||
                           (uVar4 = (**(code **)(*local_7a8 + 0x40))(local_7a8,local_778),
                           uVar4 != 0)) ||
                          (uVar4 = (**(code **)(*local_7b8 + 0x38))(local_7b8,lpWideCharStr_00),
                          uVar4 != 0)) ||
                         (uVar4 = (**(code **)(*local_7b0 + 0x40))(local_7b0,local_760), uVar4 != 0)
                         ) goto LAB_18001f894;
                      if (local_778[0] != 8) {
                        FUN_180007de0(local_438,"Assert failed in file %s line %d",
                                      "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\bkputil.cpp",0x6ad)
                        ;
                        LogMessage(local_438,2);
                      }
                      if (local_760[0] != 8) {
                        FUN_180007de0(local_438,"Assert failed in file %s line %d",
                                      "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\bkputil.cpp",0x6ae)
                        ;
                        LogMessage(local_438);
                      }
                      local_628 = local_620;
                      FUN_1800199e0(&local_628,local_770,0);
                      strcpy_s(local_538,0x100,local_628);
                      local_6b8 = local_6b0;
                      FUN_1800199e0(&local_6b8,local_758,0);
                      strcpy_s(local_578,0x40,local_6b8);
                      local_748 = local_740;
                      FUN_1800199e0(&local_748,local_790,0);
                      strcpy_s(local_598,0x20,local_748);
                      (*(code *)param_4)(local_598,local_538,local_578);
                      plVar2 = local_7e0;
                      if (local_7e0 != (longlong *)0x0) {
                        local_7e0 = (longlong *)0x0;
                        (**(code **)(*plVar2 + 0x10))();
                      }
                      iVar3 = (**(code **)(*local_7e8 + 0x80))(local_7e8,&local_7e0);
                      plVar2 = local_7e0;
                      if (local_7e8 != local_7e0) {
                        if (local_7e0 != (longlong *)0x0) {
                          (**(code **)(*local_7e0 + 8))(local_7e0);
                        }
                        plVar9 = local_7e8;
                        local_7e8 = plVar2;
                        if (plVar9 != (longlong *)0x0) {
                          (**(code **)(*plVar9 + 0x10))();
                        }
                      }
                      if (local_748 != local_740) {
                        free(local_748);
                      }
                      if (local_6b8 != local_6b0) {
                        free(local_6b8);
                      }
                      plVar2 = local_7e0;
                      plVar9 = local_7b8;
                      if (local_628 != local_620) {
                        free(local_628);
                        plVar2 = local_7e0;
                        plVar9 = local_7b8;
                      }
                    }
                    if (plVar2 != (longlong *)0x0) {
                      local_7e0 = (longlong *)0x0;
                      (**(code **)(*plVar2 + 0x10))(plVar2);
                    }
                    uVar4 = (**(code **)(*local_7d8 + 0x80))(local_7d8,&local_7e0);
                    plVar2 = local_7e0;
                    if (local_7d8 != local_7e0) {
                      plVar9 = local_7d8;
                      if (local_7e0 != (longlong *)0x0) {
                        (**(code **)(*local_7e0 + 8))(local_7e0);
                        plVar9 = local_7d8;
                      }
                      local_7d8 = plVar2;
                      if (plVar9 != (longlong *)0x0) {
                        (**(code **)(*plVar9 + 0x10))();
                      }
                    }
                    puVar7 = (undefined8 *)(ulonglong)uVar4;
                  } while (uVar4 == 0);
                  SysFreeString(lpWideCharStr_00);
                  SysFreeString(lpWideCharStr);
                  SysFreeString(local_790);
                  if (local_7b8 != (longlong *)0x0) {
                    (**(code **)(*local_7b8 + 0x10))();
                  }
                  if (local_7b0 != (longlong *)0x0) {
                    (**(code **)(*local_7b0 + 0x10))();
                  }
                  if (local_7a8 != (longlong *)0x0) {
                    (**(code **)(*local_7a8 + 0x10))();
                  }
                  if (local_7e8 != (longlong *)0x0) {
                    (**(code **)(*local_7e8 + 0x10))();
                  }
                  if (local_7e0 != (longlong *)0x0) {
                    (**(code **)(*local_7e0 + 0x10))();
                  }
                  if (local_7d8 != (longlong *)0x0) {
                    (**(code **)(*local_7d8 + 0x10))();
                  }
                  if (local_7c8 != (longlong *)0x0) {
                    (**(code **)(*local_7c8 + 0x10))();
                  }
                  SysFreeString(local_780);
                  if (local_798 != (longlong *)0x0) {
                    (**(code **)(*local_798 + 0x10))();
                    puVar10 = (undefined8 *)0x0;
                  }
                  goto LAB_18001f93a;
                }
                goto LAB_18001f98a;
              }
            }
            SysFreeString(lpWideCharStr_00);
LAB_18001f98a:
                    /* WARNING: Subroutine does not return */
            FUN_180018e40(-0x7ff8fff2);
          }
LAB_18001f8b0:
          if (local_7b8 != (longlong *)0x0) {
            (**(code **)(*local_7b8 + 0x10))();
          }
          if (local_7b0 != (longlong *)0x0) {
            (**(code **)(*local_7b0 + 0x10))();
          }
          if (local_7a8 != (longlong *)0x0) {
            (**(code **)(*local_7a8 + 0x10))();
          }
          if (local_7e8 != (longlong *)0x0) {
            (**(code **)(*local_7e8 + 0x10))();
          }
          if (local_7e0 != (longlong *)0x0) {
            (**(code **)(*local_7e0 + 0x10))();
          }
          if (local_7d8 != (longlong *)0x0) {
            (**(code **)(*local_7d8 + 0x10))();
          }
        }
        if (local_7c8 != (longlong *)0x0) {
          (**(code **)(*local_7c8 + 0x10))();
        }
      }
      SysFreeString(local_780);
    }
    if (local_798 != (longlong *)0x0) {
      (**(code **)(*local_798 + 0x10))();
    }
    puVar10 = (undefined8 *)(ulonglong)uVar4;
  }
LAB_18001f93a:
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7d0);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_7a0);
  return puVar10;
}

/* ---- FUNC 0001F282 FUN_18001f282 (1760 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_18001f282(longlong *param_1)

{
  BSTR bstrString;
  longlong lVar1;
  LPWSTR pWVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  BSTR lpWideCharStr;
  BSTR lpWideCharStr_00;
  LPWSTR pWVar7;
  longlong unaff_RBP;
  LPWSTR unaff_RSI;
  code *unaff_R13;
  int unaff_R14D;
  ulonglong uVar8;
  LPWSTR in_stack_00000030;
  LPWSTR in_stack_00000038;
  LPWSTR in_stack_00000040;
  LPCSTR in_stack_00000048;
  LPWSTR in_stack_00000050;
  undefined2 in_stack_00000058;
  LPWSTR in_stack_00000060;
  LPWSTR in_stack_00000068;
  LPWSTR in_stack_00000070;
  
  (**(code **)(*param_1 + 0x10))();
  if ((unaff_R14D != 1) && (iVar6 = (int)unaff_RSI, *(int *)(in_stack_00000048 + -0x10) != iVar6)) {
    *(LPWSTR *)(unaff_RBP + -0x80) = unaff_RSI;
    in_stack_00000058 = SUB82(unaff_RSI,0);
    uVar3 = CoCreateInstance((IID *)&DAT_1800542a8,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_180054680,
                             (LPVOID *)(unaff_RBP + -0x80));
    if (uVar3 == 0) {
      FUN_180018810((undefined8 *)(unaff_RBP + -0x68),in_stack_00000048);
      bstrString = *(BSTR *)(unaff_RBP + -0x68);
      uVar3 = (**(code **)(**(longlong **)(unaff_RBP + -0x80) + 0x208))
                        (*(longlong **)(unaff_RBP + -0x80),bstrString,&stack0x00000058);
      if (uVar3 == 0) {
        in_stack_00000050 = unaff_RSI;
        uVar3 = (**(code **)(**(longlong **)(unaff_RBP + -0x80) + 0x168))
                          (*(longlong **)(unaff_RBP + -0x80),&stack0x00000050);
        if (uVar3 == 0) {
          in_stack_00000030 = unaff_RSI;
          in_stack_00000038 = unaff_RSI;
          in_stack_00000040 = unaff_RSI;
          in_stack_00000060 = unaff_RSI;
          in_stack_00000068 = unaff_RSI;
          in_stack_00000070 = unaff_RSI;
          uVar3 = (**(code **)(*(longlong *)in_stack_00000050 + 0x68))();
          if (uVar3 == 0) {
            *(LPWSTR *)(unaff_RBP + -0x78) = unaff_RSI;
            iVar4 = MultiByteToWideChar(0,0,"Name",-1,unaff_RSI,iVar6);
            lpWideCharStr = SysAllocStringLen((OLECHAR *)0x0,iVar4 - 1);
            if ((lpWideCharStr == (BSTR)0x0) ||
               (iVar5 = MultiByteToWideChar(0,0,"Name",-1,lpWideCharStr,iVar4),
               lpWideCharStr_00 = lpWideCharStr, iVar5 == iVar4)) {
              if (lpWideCharStr == (BSTR)0x0) goto LAB_18001f98a;
              iVar6 = MultiByteToWideChar(0,0,"GUID",-1,unaff_RSI,iVar6);
              lpWideCharStr_00 = SysAllocStringLen((OLECHAR *)0x0,iVar6 - 1);
              if ((lpWideCharStr_00 == (BSTR)0x0) ||
                 (iVar4 = MultiByteToWideChar(0,0,"GUID",-1,lpWideCharStr_00,iVar6), iVar4 == iVar6)
                 ) {
                if (lpWideCharStr_00 != (BSTR)0x0) {
                  uVar8 = (ulonglong)unaff_RSI & 0xffffffff;
                  do {
                    if (in_stack_00000040 == (LPWSTR)0x0) break;
                    uVar3 = (**(code **)(*(longlong *)in_stack_00000040 + 0x38))
                                      (in_stack_00000040,unaff_RBP + -0x78);
                    if (uVar3 != 0) {
LAB_18001f894:
                      SysFreeString(lpWideCharStr_00);
                      SysFreeString(lpWideCharStr);
                      SysFreeString(*(BSTR *)(unaff_RBP + -0x78));
                      goto LAB_18001f8b0;
                    }
                    if (in_stack_00000030 != (LPWSTR)0x0) {
                      lVar1 = *(longlong *)in_stack_00000030;
                      in_stack_00000030 = unaff_RSI;
                      (**(code **)(lVar1 + 0x10))();
                    }
                    uVar3 = (**(code **)(*(longlong *)in_stack_00000040 + 0x68))
                                      (in_stack_00000040,&stack0x00000030);
                    if (uVar3 != 0) goto LAB_18001f894;
                    iVar6 = (int)uVar8;
                    while ((iVar6 == 0 && (in_stack_00000030 != unaff_RSI))) {
                      if (in_stack_00000060 != (LPWSTR)0x0) {
                        lVar1 = *(longlong *)in_stack_00000060;
                        in_stack_00000060 = unaff_RSI;
                        (**(code **)(lVar1 + 0x10))();
                      }
                      uVar3 = (**(code **)(*(longlong *)in_stack_00000030 + 0x88))
                                        (in_stack_00000030,&stack0x00000060);
                      if (uVar3 != 0) goto LAB_18001f894;
                      pWVar2 = in_stack_00000068;
                      if ((in_stack_00000068 != (LPWSTR)0x0) &&
                         (pWVar2 = unaff_RSI, in_stack_00000068 != (LPWSTR)0x0)) {
                        lVar1 = *(longlong *)in_stack_00000068;
                        in_stack_00000068 = unaff_RSI;
                        (**(code **)(lVar1 + 0x10))();
                        pWVar2 = in_stack_00000068;
                      }
                      in_stack_00000068 = pWVar2;
                      pWVar2 = in_stack_00000068;
                      pWVar7 = in_stack_00000070;
                      if (in_stack_00000070 != in_stack_00000068) {
                        if (in_stack_00000068 != (LPWSTR)0x0) {
                          (**(code **)(*(longlong *)in_stack_00000068 + 8))(in_stack_00000068);
                        }
                        pWVar7 = pWVar2;
                        if (in_stack_00000070 != (LPWSTR)0x0) {
                          lVar1 = *(longlong *)in_stack_00000070;
                          in_stack_00000070 = pWVar2;
                          (**(code **)(lVar1 + 0x10))();
                          pWVar7 = in_stack_00000070;
                        }
                      }
                      in_stack_00000070 = pWVar7;
                      uVar3 = (**(code **)(*(longlong *)in_stack_00000060 + 0x38))
                                        (in_stack_00000060,lpWideCharStr,&stack0x00000070);
                      if ((((uVar3 != 0) ||
                           (uVar3 = (**(code **)(*(longlong *)in_stack_00000070 + 0x40))
                                              (in_stack_00000070,unaff_RBP + -0x60), uVar3 != 0)) ||
                          (uVar3 = (**(code **)(*(longlong *)in_stack_00000060 + 0x38))
                                             (in_stack_00000060,lpWideCharStr_00), uVar3 != 0)) ||
                         (uVar3 = (**(code **)(*(longlong *)in_stack_00000068 + 0x40))
                                            (in_stack_00000068,unaff_RBP + -0x48), uVar3 != 0))
                      goto LAB_18001f894;
                      if (*(short *)(unaff_RBP + -0x60) != 8) {
                        FUN_180007de0(unaff_RBP + 0x2e0,"Assert failed in file %s line %d",
                                      "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\bkputil.cpp",0x6ad)
                        ;
                        LogMessage(unaff_RBP + 0x2e0,2);
                      }
                      if (*(short *)(unaff_RBP + -0x48) != 8) {
                        FUN_180007de0(unaff_RBP + 0x2e0,"Assert failed in file %s line %d",
                                      "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\bkputil.cpp",0x6ae)
                        ;
                        LogMessage(unaff_RBP + 0x2e0);
                      }
                      *(longlong *)(unaff_RBP + 0xf0) = unaff_RBP + 0xf8;
                      FUN_1800199e0((undefined8 *)(unaff_RBP + 0xf0),*(LPCWSTR *)(unaff_RBP + -0x58)
                                    ,0);
                      strcpy_s((char *)(unaff_RBP + 0x1e0),0x100,*(char **)(unaff_RBP + 0xf0));
                      *(longlong *)(unaff_RBP + 0x60) = unaff_RBP + 0x68;
                      FUN_1800199e0((undefined8 *)(unaff_RBP + 0x60),*(LPCWSTR *)(unaff_RBP + -0x40)
                                    ,0);
                      strcpy_s((char *)(unaff_RBP + 0x1a0),0x40,*(char **)(unaff_RBP + 0x60));
                      *(longlong *)(unaff_RBP + -0x30) = unaff_RBP + -0x28;
                      FUN_1800199e0((undefined8 *)(unaff_RBP + -0x30),
                                    *(LPCWSTR *)(unaff_RBP + -0x78),0);
                      strcpy_s((char *)(unaff_RBP + 0x180),0x20,*(char **)(unaff_RBP + -0x30));
                      (*unaff_R13)(unaff_RBP + 0x180,unaff_RBP + 0x1e0,unaff_RBP + 0x1a0);
                      if (in_stack_00000038 != (LPWSTR)0x0) {
                        lVar1 = *(longlong *)in_stack_00000038;
                        in_stack_00000038 = unaff_RSI;
                        (**(code **)(lVar1 + 0x10))();
                      }
                      iVar6 = (**(code **)(*(longlong *)in_stack_00000030 + 0x80))
                                        (in_stack_00000030,&stack0x00000038);
                      pWVar2 = in_stack_00000038;
                      if (in_stack_00000030 != in_stack_00000038) {
                        if (in_stack_00000038 != (LPWSTR)0x0) {
                          (**(code **)(*(longlong *)in_stack_00000038 + 8))(in_stack_00000038);
                        }
                        pWVar7 = in_stack_00000030;
                        in_stack_00000030 = pWVar2;
                        if (pWVar7 != (LPWSTR)0x0) {
                          (**(code **)(*(longlong *)pWVar7 + 0x10))();
                        }
                      }
                      if (*(void **)(unaff_RBP + -0x30) != (void *)(unaff_RBP + -0x28)) {
                        free(*(void **)(unaff_RBP + -0x30));
                      }
                      if (*(void **)(unaff_RBP + 0x60) != (void *)(unaff_RBP + 0x68)) {
                        free(*(void **)(unaff_RBP + 0x60));
                      }
                      if (*(void **)(unaff_RBP + 0xf0) != (void *)(unaff_RBP + 0xf8)) {
                        free(*(void **)(unaff_RBP + 0xf0));
                      }
                    }
                    if (in_stack_00000038 != (LPWSTR)0x0) {
                      pWVar2 = unaff_RSI;
                      (**(code **)(*(longlong *)in_stack_00000038 + 0x10))(in_stack_00000038);
                      in_stack_00000038 = pWVar2;
                    }
                    uVar3 = (**(code **)(*(longlong *)in_stack_00000040 + 0x80))
                                      (in_stack_00000040,&stack0x00000038);
                    pWVar2 = in_stack_00000038;
                    uVar8 = (ulonglong)uVar3;
                    if (in_stack_00000040 != in_stack_00000038) {
                      pWVar7 = in_stack_00000040;
                      if (in_stack_00000038 != (LPWSTR)0x0) {
                        (**(code **)(*(longlong *)in_stack_00000038 + 8))(in_stack_00000038);
                        pWVar7 = in_stack_00000040;
                      }
                      in_stack_00000040 = pWVar2;
                      if (pWVar7 != (LPWSTR)0x0) {
                        (**(code **)(*(longlong *)pWVar7 + 0x10))();
                      }
                    }
                  } while (uVar3 == 0);
                  SysFreeString(lpWideCharStr_00);
                  SysFreeString(lpWideCharStr);
                  SysFreeString(*(BSTR *)(unaff_RBP + -0x78));
                  if (in_stack_00000060 != (LPWSTR)0x0) {
                    (**(code **)(*(longlong *)in_stack_00000060 + 0x10))();
                  }
                  if (in_stack_00000068 != (LPWSTR)0x0) {
                    (**(code **)(*(longlong *)in_stack_00000068 + 0x10))();
                  }
                  if (in_stack_00000070 != (LPWSTR)0x0) {
                    (**(code **)(*(longlong *)in_stack_00000070 + 0x10))();
                  }
                  if (in_stack_00000030 != (LPWSTR)0x0) {
                    (**(code **)(*(longlong *)in_stack_00000030 + 0x10))();
                  }
                  if (in_stack_00000038 != (LPWSTR)0x0) {
                    (**(code **)(*(longlong *)in_stack_00000038 + 0x10))();
                  }
                  if (in_stack_00000040 != (LPWSTR)0x0) {
                    (**(code **)(*(longlong *)in_stack_00000040 + 0x10))();
                  }
                  if (in_stack_00000050 != (LPWSTR)0x0) {
                    (**(code **)(*(longlong *)in_stack_00000050 + 0x10))();
                  }
                  SysFreeString(bstrString);
                  if (*(longlong **)(unaff_RBP + -0x80) != (longlong *)0x0) {
                    (**(code **)(**(longlong **)(unaff_RBP + -0x80) + 0x10))();
                  }
                  goto LAB_18001f93a;
                }
                goto LAB_18001f98a;
              }
            }
            SysFreeString(lpWideCharStr_00);
LAB_18001f98a:
                    /* WARNING: Subroutine does not return */
            FUN_180018e40(-0x7ff8fff2);
          }
LAB_18001f8b0:
          if (in_stack_00000060 != (LPWSTR)0x0) {
            (**(code **)(*(longlong *)in_stack_00000060 + 0x10))();
          }
          if (in_stack_00000068 != (LPWSTR)0x0) {
            (**(code **)(*(longlong *)in_stack_00000068 + 0x10))();
          }
          if (in_stack_00000070 != (LPWSTR)0x0) {
            (**(code **)(*(longlong *)in_stack_00000070 + 0x10))();
          }
          if (in_stack_00000030 != (LPWSTR)0x0) {
            (**(code **)(*(longlong *)in_stack_00000030 + 0x10))();
          }
          if (in_stack_00000038 != (LPWSTR)0x0) {
            (**(code **)(*(longlong *)in_stack_00000038 + 0x10))();
          }
          if (in_stack_00000040 != (LPWSTR)0x0) {
            (**(code **)(*(longlong *)in_stack_00000040 + 0x10))();
          }
        }
        if (in_stack_00000050 != (LPWSTR)0x0) {
          (**(code **)(*(longlong *)in_stack_00000050 + 0x10))();
        }
      }
      SysFreeString(bstrString);
    }
    if (*(longlong **)(unaff_RBP + -0x80) != (longlong *)0x0) {
      (**(code **)(**(longlong **)(unaff_RBP + -0x80) + 0x10))();
    }
    unaff_RSI = (LPWSTR)(ulonglong)uVar3;
  }
LAB_18001f93a:
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&stack0x00000048);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&stack0x00000078);
  return (ulonglong)unaff_RSI & 0xffffffff;
}

/* ---- FUNC 0001F962 FUN_18001f962 (31 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18001f962(void)

{
  return;
}

/* ---- FUNC 0001F981 FUN_18001f981 (19 bytes) ---- */

void FUN_18001f981(void)

{
  BSTR unaff_R12;
  
  SysFreeString(unaff_R12);
                    /* WARNING: Subroutine does not return */
  FUN_180018e40(-0x7ff8fff2);
}

/* ---- FUNC 0001F9A0 ReadCArestoreMap (31 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void ReadCArestoreMap(void *param_1,void *param_2,void *param_3,longlong param_4)

{
  char cVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  longlong lVar4;
  undefined8 *****pppppuVar5;
  longlong *plVar6;
  undefined8 *puVar7;
  int iVar8;
  longlong *plVar9;
  undefined8 *puVar10;
  longlong *plVar11;
  longlong *plVar12;
  undefined8 ******ppppppuVar13;
  undefined8 ******ppppppuVar14;
  longlong lVar15;
  size_t sVar16;
  char *pcVar17;
  size_t sVar18;
  longlong *plVar19;
  undefined1 auStack_d8 [32];
  longlong local_b8;
  undefined8 *****local_b0;
  undefined8 uStack_a8;
  size_t local_a0;
  ulonglong local_98;
  undefined8 *****local_90;
  undefined8 uStack_88;
  size_t local_80;
  ulonglong local_78;
  undefined8 *****local_70;
  undefined8 uStack_68;
  size_t local_60;
  ulonglong local_58;
  ulonglong local_50;
  
                    /* 0x1f9a0  437  ReadCArestoreMap */
  local_50 = DAT_1800791f8 ^ (ulonglong)auStack_d8;
  sVar16 = 0xffffffffffffffff;
  local_60 = 0;
  local_58 = 0;
  sVar18 = 0xffffffffffffffff;
  local_70 = (undefined8 ******)0x0;
  uStack_68 = 0;
  do {
    sVar18 = sVar18 + 1;
  } while (*(char *)((longlong)param_3 + sVar18) != '\0');
  local_b8 = param_4;
  FUN_18000b5f0(&local_70,param_3,sVar18);
  local_80 = 0;
  local_90 = (undefined8 ******)0x0;
  uStack_88 = 0;
  local_78 = 0;
  sVar18 = 0xffffffffffffffff;
  do {
    sVar18 = sVar18 + 1;
  } while (*(char *)((longlong)param_2 + sVar18) != '\0');
  FUN_18000b5f0(&local_90,param_2,sVar18);
  local_a0 = 0;
  local_b0 = (undefined8 ******)0x0;
  uStack_a8 = 0;
  local_98 = 0;
  do {
    sVar16 = sVar16 + 1;
  } while (*(char *)((longlong)param_1 + sVar16) != '\0');
  FUN_18000b5f0(&local_b0,param_1,sVar16);
  sVar16 = local_60;
  pppppuVar5 = local_70;
  plVar12 = (longlong *)*DAT_18007a278;
  ppppppuVar13 = (undefined8 ******)local_90;
  plVar19 = DAT_18007a278;
  if (plVar12 != DAT_18007a278) {
    do {
      ppppppuVar14 = &local_b0;
      if (0xf < local_98) {
        ppppppuVar14 = (undefined8 ******)local_b0;
      }
      plVar9 = plVar12 + 4;
      if (0xf < (ulonglong)plVar12[7]) {
        plVar9 = (longlong *)plVar12[4];
      }
      if ((plVar12[6] == local_a0) &&
         (iVar8 = memcmp(plVar9,ppppppuVar14,plVar12[6]), plVar19 = DAT_18007a278, iVar8 == 0)) {
        puVar2 = (undefined8 *)plVar12[8];
        puVar3 = (undefined8 *)*puVar2;
        while (DAT_18007a278 = plVar19, puVar3 != puVar2) {
          puVar10 = puVar3 + 4;
          ppppppuVar14 = &local_90;
          if (0xf < local_78) {
            ppppppuVar14 = ppppppuVar13;
          }
          if (0xf < (ulonglong)puVar3[7]) {
            puVar10 = (undefined8 *)puVar3[4];
          }
          if ((puVar3[6] == local_80) &&
             (iVar8 = memcmp(puVar10,ppppppuVar14,puVar3[6]), iVar8 == 0)) {
            plVar19 = (longlong *)puVar3[8];
            plVar9 = (longlong *)*plVar19;
            ppppppuVar13 = (undefined8 ******)local_90;
            if (plVar9 != plVar19) {
LAB_18001fb40:
              plVar11 = plVar9 + 4;
              ppppppuVar13 = &local_70;
              if (0xf < local_58) {
                ppppppuVar13 = (undefined8 ******)pppppuVar5;
              }
              if (0xf < (ulonglong)plVar9[7]) {
                plVar11 = (longlong *)plVar9[4];
              }
              if ((plVar9[6] != sVar16) ||
                 (iVar8 = memcmp(plVar11,ppppppuVar13,plVar9[6]), iVar8 != 0)) goto LAB_18001fb72;
              plVar12 = plVar9 + 8;
              lVar15 = local_b8 - (longlong)plVar12;
              do {
                lVar4 = *plVar12;
                *(char *)((longlong)plVar12 + lVar15) = (char)lVar4;
                plVar12 = (longlong *)((longlong)plVar12 + 1);
              } while ((char)lVar4 != '\0');
              pcVar17 = (char *)((longlong)plVar9 + 0x4c);
              lVar15 = local_b8 - (longlong)pcVar17;
              do {
                cVar1 = *pcVar17;
                pcVar17[lVar15 + 0xc] = cVar1;
                pcVar17 = pcVar17 + 1;
              } while (cVar1 != '\0');
              goto FUN_18001fce4;
            }
          }
LAB_18001fbcc:
          puVar10 = (undefined8 *)puVar3[2];
          plVar19 = DAT_18007a278;
          if (*(char *)((longlong)puVar10 + 0x19) == '\0') {
            cVar1 = *(char *)((longlong)*puVar10 + 0x19);
            puVar3 = puVar10;
            puVar10 = (undefined8 *)*puVar10;
            while (cVar1 == '\0') {
              cVar1 = *(char *)((longlong)*puVar10 + 0x19);
              puVar3 = puVar10;
              puVar10 = (undefined8 *)*puVar10;
            }
          }
          else {
            cVar1 = *(char *)((longlong)puVar3[1] + 0x19);
            puVar7 = (undefined8 *)puVar3[1];
            puVar10 = puVar3;
            while ((puVar3 = puVar7, cVar1 == '\0' && (puVar10 == (undefined8 *)puVar3[2]))) {
              cVar1 = *(char *)((longlong)puVar3[1] + 0x19);
              puVar7 = (undefined8 *)puVar3[1];
              puVar10 = puVar3;
            }
          }
        }
      }
      plVar9 = (longlong *)plVar12[2];
      if (*(char *)((longlong)plVar9 + 0x19) == '\0') {
        cVar1 = *(char *)(*plVar9 + 0x19);
        plVar12 = plVar9;
        plVar9 = (longlong *)*plVar9;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*plVar9 + 0x19);
          plVar12 = plVar9;
          plVar9 = (longlong *)*plVar9;
        }
      }
      else {
        cVar1 = *(char *)(plVar12[1] + 0x19);
        plVar11 = (longlong *)plVar12[1];
        plVar9 = plVar12;
        while ((plVar12 = plVar11, cVar1 == '\0' && (plVar9 == (longlong *)plVar12[2]))) {
          cVar1 = *(char *)(plVar12[1] + 0x19);
          plVar11 = (longlong *)plVar12[1];
          plVar9 = plVar12;
        }
      }
    } while (plVar12 != plVar19);
  }
FUN_18001fce4:
  if (0xf < local_98) {
    ppppppuVar13 = (undefined8 ******)local_b0;
    if ((0xfff < local_98 + 1) &&
       (ppppppuVar13 = (undefined8 ******)local_b0[-1],
       0x1f < (ulonglong)((longlong)local_b0 + (-8 - (longlong)ppppppuVar13)))) goto LAB_18001fd9f;
    operator_delete(ppppppuVar13);
  }
  if (0xf < local_78) {
    ppppppuVar13 = (undefined8 ******)local_90;
    if ((0xfff < local_78 + 1) &&
       (ppppppuVar13 = (undefined8 ******)local_90[-1],
       0x1f < (ulonglong)((longlong)local_90 + (-8 - (longlong)ppppppuVar13)))) goto LAB_18001fd9f;
    operator_delete(ppppppuVar13);
  }
  if (0xf < local_58) {
    ppppppuVar13 = (undefined8 ******)pppppuVar5;
    if ((0xfff < local_58 + 1) &&
       (ppppppuVar13 = (undefined8 ******)pppppuVar5[-1],
       0x1f < (ulonglong)((longlong)pppppuVar5 + (-8 - (longlong)ppppppuVar13)))) {
LAB_18001fd9f:
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(ppppppuVar13);
  }
  return;
LAB_18001fb72:
  plVar11 = (longlong *)plVar9[2];
  if (*(char *)((longlong)plVar11 + 0x19) == '\0') {
    cVar1 = *(char *)(*plVar11 + 0x19);
    plVar9 = plVar11;
    plVar11 = (longlong *)*plVar11;
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*plVar11 + 0x19);
      plVar9 = plVar11;
      plVar11 = (longlong *)*plVar11;
    }
  }
  else {
    cVar1 = *(char *)(plVar9[1] + 0x19);
    plVar6 = (longlong *)plVar9[1];
    plVar11 = plVar9;
    while ((plVar9 = plVar6, cVar1 == '\0' && (plVar11 == (longlong *)plVar9[2]))) {
      cVar1 = *(char *)(plVar9[1] + 0x19);
      plVar6 = (longlong *)plVar9[1];
      plVar11 = plVar9;
    }
  }
  ppppppuVar13 = (undefined8 ******)local_90;
  if (plVar9 == plVar19) goto LAB_18001fbcc;
  goto LAB_18001fb40;
}

/* ---- FUNC 0001F9BF FUN_18001f9bf (200 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18001f9bf(void *param_1,void *param_2,void *param_3,undefined8 param_4)

{
  char cVar1;
  void *pvVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  longlong lVar5;
  longlong *plVar6;
  undefined8 *puVar7;
  int iVar8;
  void *pvVar9;
  longlong *plVar10;
  undefined8 *puVar11;
  longlong *plVar12;
  longlong *plVar13;
  void *pvVar14;
  void *_Buf2;
  longlong lVar15;
  undefined8 unaff_RBX;
  size_t sVar16;
  char *pcVar17;
  longlong unaff_RBP;
  undefined8 unaff_RSI;
  undefined8 unaff_RDI;
  size_t sVar18;
  longlong lVar19;
  longlong *plVar20;
  longlong in_R11;
  undefined8 unaff_R14;
  
  *(undefined8 *)(in_R11 + -0x18) = unaff_RBX;
  *(undefined8 *)(in_R11 + -0x20) = unaff_RSI;
  sVar16 = 0xffffffffffffffff;
  *(undefined8 *)(in_R11 + -0x28) = unaff_RDI;
  *(undefined8 *)(in_R11 + -0x38) = unaff_R14;
  *(undefined8 *)(unaff_RBP + -0x59) = param_4;
  *(undefined8 *)(unaff_RBP + -1) = 0;
  *(undefined8 *)(unaff_RBP + 7) = 0;
  sVar18 = 0xffffffffffffffff;
  *(undefined8 *)(unaff_RBP + -0x11) = 0;
  *(undefined8 *)(unaff_RBP + -9) = 0;
  do {
    sVar18 = sVar18 + 1;
  } while (*(char *)((longlong)param_3 + sVar18) != '\0');
  FUN_18000b5f0((undefined8 *)(unaff_RBP + -0x11),param_3,sVar18);
  *(undefined8 *)(unaff_RBP + -0x21) = 0;
  *(undefined8 *)(unaff_RBP + -0x31) = 0;
  *(undefined8 *)(unaff_RBP + -0x29) = 0;
  *(undefined8 *)(unaff_RBP + -0x19) = 0;
  sVar18 = 0xffffffffffffffff;
  do {
    sVar18 = sVar18 + 1;
  } while (*(char *)((longlong)param_2 + sVar18) != '\0');
  FUN_18000b5f0((undefined8 *)(unaff_RBP + -0x31),param_2,sVar18);
  *(undefined8 *)(unaff_RBP + -0x41) = 0;
  *(undefined8 *)(unaff_RBP + -0x51) = 0;
  *(undefined8 *)(unaff_RBP + -0x49) = 0;
  *(undefined8 *)(unaff_RBP + -0x39) = 0;
  do {
    sVar16 = sVar16 + 1;
  } while (*(char *)((longlong)param_1 + sVar16) != '\0');
  FUN_18000b5f0((undefined8 *)(unaff_RBP + -0x51),param_1,sVar16);
  pvVar2 = *(void **)(unaff_RBP + -0x11);
  pvVar14 = *(void **)(unaff_RBP + -0x31);
  pvVar9 = *(void **)(unaff_RBP + -0x51);
  plVar13 = (longlong *)*DAT_18007a278;
  if (plVar13 != DAT_18007a278) {
    sVar16 = *(size_t *)(unaff_RBP + -1);
    plVar20 = DAT_18007a278;
    do {
      _Buf2 = (void *)(unaff_RBP + -0x51);
      if (0xf < *(ulonglong *)(unaff_RBP + -0x39)) {
        _Buf2 = pvVar9;
      }
      plVar10 = plVar13 + 4;
      if (0xf < (ulonglong)plVar13[7]) {
        plVar10 = (longlong *)plVar13[4];
      }
      if ((plVar13[6] == *(size_t *)(unaff_RBP + -0x41)) &&
         (iVar8 = memcmp(plVar10,_Buf2,plVar13[6]), plVar20 = DAT_18007a278, iVar8 == 0)) {
        puVar3 = (undefined8 *)plVar13[8];
        puVar4 = (undefined8 *)*puVar3;
        while (DAT_18007a278 = plVar20, puVar4 != puVar3) {
          puVar11 = puVar4 + 4;
          pvVar9 = (void *)(unaff_RBP + -0x31);
          if (0xf < *(ulonglong *)(unaff_RBP + -0x19)) {
            pvVar9 = pvVar14;
          }
          if (0xf < (ulonglong)puVar4[7]) {
            puVar11 = (undefined8 *)puVar4[4];
          }
          if ((puVar4[6] == *(size_t *)(unaff_RBP + -0x21)) &&
             (iVar8 = memcmp(puVar11,pvVar9,puVar4[6]), iVar8 == 0)) {
            plVar20 = (longlong *)puVar4[8];
            plVar10 = (longlong *)*plVar20;
            if (plVar10 != plVar20) {
LAB_18001fb40:
              plVar12 = plVar10 + 4;
              pvVar9 = (void *)(unaff_RBP + -0x11);
              if (0xf < *(ulonglong *)(unaff_RBP + 7)) {
                pvVar9 = pvVar2;
              }
              if (0xf < (ulonglong)plVar10[7]) {
                plVar12 = (longlong *)plVar10[4];
              }
              if ((plVar10[6] != sVar16) || (iVar8 = memcmp(plVar12,pvVar9,plVar10[6]), iVar8 != 0))
              goto LAB_18001fb72;
              lVar19 = *(longlong *)(unaff_RBP + -0x59);
              plVar13 = plVar10 + 8;
              lVar15 = lVar19 - (longlong)plVar13;
              do {
                lVar5 = *plVar13;
                *(char *)((longlong)plVar13 + lVar15) = (char)lVar5;
                plVar13 = (longlong *)((longlong)plVar13 + 1);
              } while ((char)lVar5 != '\0');
              pcVar17 = (char *)((longlong)plVar10 + 0x4c);
              lVar19 = lVar19 - (longlong)pcVar17;
              do {
                cVar1 = *pcVar17;
                pcVar17[lVar19 + 0xc] = cVar1;
                pcVar17 = pcVar17 + 1;
              } while (cVar1 != '\0');
              pvVar9 = *(void **)(unaff_RBP + -0x51);
              goto FUN_18001fce4;
            }
LAB_18001fbc8:
            pvVar14 = *(void **)(unaff_RBP + -0x31);
          }
          puVar11 = (undefined8 *)puVar4[2];
          plVar20 = DAT_18007a278;
          if (*(char *)((longlong)puVar11 + 0x19) == '\0') {
            cVar1 = *(char *)((longlong)*puVar11 + 0x19);
            puVar4 = puVar11;
            puVar11 = (undefined8 *)*puVar11;
            while (cVar1 == '\0') {
              cVar1 = *(char *)((longlong)*puVar11 + 0x19);
              puVar4 = puVar11;
              puVar11 = (undefined8 *)*puVar11;
            }
          }
          else {
            cVar1 = *(char *)((longlong)puVar4[1] + 0x19);
            puVar7 = (undefined8 *)puVar4[1];
            puVar11 = puVar4;
            while ((puVar4 = puVar7, cVar1 == '\0' && (puVar11 == (undefined8 *)puVar4[2]))) {
              cVar1 = *(char *)((longlong)puVar4[1] + 0x19);
              puVar7 = (undefined8 *)puVar4[1];
              puVar11 = puVar4;
            }
          }
        }
      }
      plVar10 = (longlong *)plVar13[2];
      if (*(char *)((longlong)plVar10 + 0x19) == '\0') {
        cVar1 = *(char *)(*plVar10 + 0x19);
        plVar13 = plVar10;
        plVar10 = (longlong *)*plVar10;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*plVar10 + 0x19);
          plVar13 = plVar10;
          plVar10 = (longlong *)*plVar10;
        }
      }
      else {
        cVar1 = *(char *)(plVar13[1] + 0x19);
        plVar12 = (longlong *)plVar13[1];
        plVar10 = plVar13;
        while ((plVar13 = plVar12, cVar1 == '\0' && (plVar10 == (longlong *)plVar13[2]))) {
          cVar1 = *(char *)(plVar13[1] + 0x19);
          plVar12 = (longlong *)plVar13[1];
          plVar10 = plVar13;
        }
      }
      pvVar9 = *(void **)(unaff_RBP + -0x51);
    } while (plVar13 != plVar20);
  }
FUN_18001fce4:
  if (0xf < *(ulonglong *)(unaff_RBP + -0x39)) {
    pvVar14 = pvVar9;
    if ((0xfff < *(ulonglong *)(unaff_RBP + -0x39) + 1) &&
       (pvVar14 = *(void **)((longlong)pvVar9 + -8),
       0x1f < (ulonglong)((longlong)pvVar9 + (-8 - (longlong)pvVar14)))) goto LAB_18001fd9f;
    operator_delete(pvVar14);
  }
  if (0xf < *(ulonglong *)(unaff_RBP + -0x19)) {
    pvVar9 = *(void **)(unaff_RBP + -0x31);
    pvVar14 = pvVar9;
    if ((0xfff < *(ulonglong *)(unaff_RBP + -0x19) + 1) &&
       (pvVar14 = *(void **)((longlong)pvVar9 + -8),
       0x1f < (ulonglong)((longlong)pvVar9 + (-8 - (longlong)pvVar14)))) goto LAB_18001fd9f;
    operator_delete(pvVar14);
  }
  if (0xf < *(ulonglong *)(unaff_RBP + 7)) {
    pvVar9 = pvVar2;
    if ((0xfff < *(ulonglong *)(unaff_RBP + 7) + 1) &&
       (pvVar9 = *(void **)((longlong)pvVar2 + -8),
       0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)pvVar9)))) {
LAB_18001fd9f:
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar9);
  }
  return;
LAB_18001fb72:
  plVar12 = (longlong *)plVar10[2];
  if (*(char *)((longlong)plVar12 + 0x19) == '\0') {
    cVar1 = *(char *)(*plVar12 + 0x19);
    plVar10 = plVar12;
    plVar12 = (longlong *)*plVar12;
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*plVar12 + 0x19);
      plVar10 = plVar12;
      plVar12 = (longlong *)*plVar12;
    }
  }
  else {
    cVar1 = *(char *)(plVar10[1] + 0x19);
    plVar6 = (longlong *)plVar10[1];
    plVar12 = plVar10;
    while ((plVar10 = plVar6, cVar1 == '\0' && (plVar12 == (longlong *)plVar10[2]))) {
      cVar1 = *(char *)(plVar10[1] + 0x19);
      plVar6 = (longlong *)plVar10[1];
      plVar12 = plVar10;
    }
  }
  if (plVar10 == plVar20) goto LAB_18001fbc8;
  goto LAB_18001fb40;
}

/* ---- FUNC 0001FA87 FUN_18001fa87 (605 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18001fa87(void *param_1,undefined8 param_2,undefined8 param_3,longlong *param_4)

{
  char cVar1;
  size_t sVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  longlong lVar5;
  longlong *plVar6;
  undefined8 *puVar7;
  int iVar8;
  undefined8 *puVar9;
  longlong *plVar10;
  longlong *plVar11;
  void *pvVar12;
  void *pvVar13;
  longlong lVar14;
  void *unaff_RBX;
  longlong *plVar15;
  char *pcVar16;
  longlong unaff_RBP;
  longlong lVar17;
  void *unaff_R13;
  longlong *unaff_R14;
  
  sVar2 = *(size_t *)(unaff_RBP + -1);
  do {
    pvVar12 = (void *)(unaff_RBP + -0x51);
    if (0xf < *(ulonglong *)(unaff_RBP + -0x39)) {
      pvVar12 = param_1;
    }
    plVar11 = unaff_R14 + 4;
    if (0xf < (ulonglong)unaff_R14[7]) {
      plVar11 = (longlong *)unaff_R14[4];
    }
    if ((unaff_R14[6] == *(size_t *)(unaff_RBP + -0x41)) &&
       (iVar8 = memcmp(plVar11,pvVar12,unaff_R14[6]), param_4 = DAT_18007a278, iVar8 == 0)) {
      puVar3 = (undefined8 *)unaff_R14[8];
      puVar4 = (undefined8 *)*puVar3;
      while (DAT_18007a278 = param_4, puVar4 != puVar3) {
        puVar9 = puVar4 + 4;
        pvVar12 = (void *)(unaff_RBP + -0x31);
        if (0xf < *(ulonglong *)(unaff_RBP + -0x19)) {
          pvVar12 = unaff_RBX;
        }
        if (0xf < (ulonglong)puVar4[7]) {
          puVar9 = (undefined8 *)puVar4[4];
        }
        if ((puVar4[6] == *(size_t *)(unaff_RBP + -0x21)) &&
           (iVar8 = memcmp(puVar9,pvVar12,puVar4[6]), iVar8 == 0)) {
          plVar11 = (longlong *)puVar4[8];
          plVar15 = (longlong *)*plVar11;
          if (plVar15 != plVar11) {
LAB_18001fb40:
            plVar10 = plVar15 + 4;
            pvVar12 = (void *)(unaff_RBP + -0x11);
            if (0xf < *(ulonglong *)(unaff_RBP + 7)) {
              pvVar12 = unaff_R13;
            }
            if (0xf < (ulonglong)plVar15[7]) {
              plVar10 = (longlong *)plVar15[4];
            }
            if ((plVar15[6] != sVar2) || (iVar8 = memcmp(plVar10,pvVar12,plVar15[6]), iVar8 != 0))
            goto LAB_18001fb72;
            lVar17 = *(longlong *)(unaff_RBP + -0x59);
            plVar11 = plVar15 + 8;
            lVar14 = lVar17 - (longlong)plVar11;
            do {
              lVar5 = *plVar11;
              *(char *)((longlong)plVar11 + lVar14) = (char)lVar5;
              plVar11 = (longlong *)((longlong)plVar11 + 1);
            } while ((char)lVar5 != '\0');
            pcVar16 = (char *)((longlong)plVar15 + 0x4c);
            lVar17 = lVar17 - (longlong)pcVar16;
            do {
              cVar1 = *pcVar16;
              pcVar16[lVar17 + 0xc] = cVar1;
              pcVar16 = pcVar16 + 1;
            } while (cVar1 != '\0');
            param_1 = *(void **)(unaff_RBP + -0x51);
            goto LAB_18001fcd4;
          }
LAB_18001fbc8:
          unaff_RBX = *(void **)(unaff_RBP + -0x31);
        }
        puVar9 = (undefined8 *)puVar4[2];
        param_4 = DAT_18007a278;
        if (*(char *)((longlong)puVar9 + 0x19) == '\0') {
          cVar1 = *(char *)((longlong)*puVar9 + 0x19);
          puVar4 = puVar9;
          puVar9 = (undefined8 *)*puVar9;
          while (cVar1 == '\0') {
            cVar1 = *(char *)((longlong)*puVar9 + 0x19);
            puVar4 = puVar9;
            puVar9 = (undefined8 *)*puVar9;
          }
        }
        else {
          cVar1 = *(char *)((longlong)puVar4[1] + 0x19);
          puVar7 = (undefined8 *)puVar4[1];
          puVar9 = puVar4;
          while ((puVar4 = puVar7, cVar1 == '\0' && (puVar9 == (undefined8 *)puVar4[2]))) {
            cVar1 = *(char *)((longlong)puVar4[1] + 0x19);
            puVar7 = (undefined8 *)puVar4[1];
            puVar9 = puVar4;
          }
        }
      }
    }
    plVar11 = (longlong *)unaff_R14[2];
    if (*(char *)((longlong)plVar11 + 0x19) == '\0') {
      cVar1 = *(char *)(*plVar11 + 0x19);
      unaff_R14 = plVar11;
      plVar11 = (longlong *)*plVar11;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*plVar11 + 0x19);
        unaff_R14 = plVar11;
        plVar11 = (longlong *)*plVar11;
      }
    }
    else {
      cVar1 = *(char *)(unaff_R14[1] + 0x19);
      plVar15 = (longlong *)unaff_R14[1];
      plVar11 = unaff_R14;
      while ((unaff_R14 = plVar15, cVar1 == '\0' && (plVar11 == (longlong *)unaff_R14[2]))) {
        cVar1 = *(char *)(unaff_R14[1] + 0x19);
        plVar15 = (longlong *)unaff_R14[1];
        plVar11 = unaff_R14;
      }
    }
    param_1 = *(void **)(unaff_RBP + -0x51);
  } while (unaff_R14 != param_4);
LAB_18001fcd4:
  if (0xf < *(ulonglong *)(unaff_RBP + -0x39)) {
    pvVar12 = param_1;
    if ((0xfff < *(ulonglong *)(unaff_RBP + -0x39) + 1) &&
       (pvVar12 = *(void **)((longlong)param_1 + -8),
       0x1f < (ulonglong)((longlong)param_1 + (-8 - (longlong)pvVar12)))) goto LAB_18001fd9f;
    operator_delete(pvVar12);
  }
  if (0xf < *(ulonglong *)(unaff_RBP + -0x19)) {
    pvVar12 = *(void **)(unaff_RBP + -0x31);
    pvVar13 = pvVar12;
    if ((0xfff < *(ulonglong *)(unaff_RBP + -0x19) + 1) &&
       (pvVar13 = *(void **)((longlong)pvVar12 + -8),
       0x1f < (ulonglong)((longlong)pvVar12 + (-8 - (longlong)pvVar13)))) goto LAB_18001fd9f;
    operator_delete(pvVar13);
  }
  if (0xf < *(ulonglong *)(unaff_RBP + 7)) {
    pvVar12 = unaff_R13;
    if ((0xfff < *(ulonglong *)(unaff_RBP + 7) + 1) &&
       (pvVar12 = *(void **)((longlong)unaff_R13 + -8),
       0x1f < (ulonglong)((longlong)unaff_R13 + (-8 - (longlong)pvVar12)))) {
LAB_18001fd9f:
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar12);
  }
  return;
LAB_18001fb72:
  plVar10 = (longlong *)plVar15[2];
  if (*(char *)((longlong)plVar10 + 0x19) == '\0') {
    cVar1 = *(char *)(*plVar10 + 0x19);
    plVar15 = plVar10;
    plVar10 = (longlong *)*plVar10;
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*plVar10 + 0x19);
      plVar15 = plVar10;
      plVar10 = (longlong *)*plVar10;
    }
  }
  else {
    cVar1 = *(char *)(plVar15[1] + 0x19);
    plVar6 = (longlong *)plVar15[1];
    plVar10 = plVar15;
    while ((plVar15 = plVar6, cVar1 == '\0' && (plVar10 == (longlong *)plVar15[2]))) {
      cVar1 = *(char *)(plVar15[1] + 0x19);
      plVar6 = (longlong *)plVar15[1];
      plVar10 = plVar15;
    }
  }
  if (plVar15 == plVar11) goto LAB_18001fbc8;
  goto LAB_18001fb40;
}

/* ---- FUNC 0001FCE4 FUN_18001fce4 (42 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18001fce4(void *param_1)

{
  void *pvVar1;
  void *pvVar2;
  longlong unaff_RBP;
  void *unaff_R13;
  
  if (0xf < *(ulonglong *)(unaff_RBP + -0x39)) {
    pvVar1 = param_1;
    if ((0xfff < *(ulonglong *)(unaff_RBP + -0x39) + 1) &&
       (pvVar1 = *(void **)((longlong)param_1 + -8),
       0x1f < (ulonglong)((longlong)param_1 + (-8 - (longlong)pvVar1)))) goto LAB_18001fd9f;
    operator_delete(pvVar1);
  }
  if (0xf < *(ulonglong *)(unaff_RBP + -0x19)) {
    pvVar1 = *(void **)(unaff_RBP + -0x31);
    pvVar2 = pvVar1;
    if ((0xfff < *(ulonglong *)(unaff_RBP + -0x19) + 1) &&
       (pvVar2 = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar2)))) goto LAB_18001fd9f;
    operator_delete(pvVar2);
  }
  if (0xf < *(ulonglong *)(unaff_RBP + 7)) {
    pvVar1 = unaff_R13;
    if ((0xfff < *(ulonglong *)(unaff_RBP + 7) + 1) &&
       (pvVar1 = *(void **)((longlong)unaff_R13 + -8),
       0x1f < (ulonglong)((longlong)unaff_R13 + (-8 - (longlong)pvVar1)))) {
LAB_18001fd9f:
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar1);
  }
  return;
}

/* ---- FUNC 0001FD0E FUN_18001fd0e (183 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18001fd0e(void *param_1)

{
  longlong in_RAX;
  void *pvVar1;
  void *pvVar2;
  longlong unaff_RBP;
  void *unaff_R13;
  
  pvVar1 = param_1;
  if ((0xfff < in_RAX + 1U) &&
     (pvVar1 = *(void **)((longlong)param_1 + -8),
     0x1f < (ulonglong)((longlong)param_1 + (-8 - (longlong)pvVar1)))) {
LAB_18001fd9f:
                    /* WARNING: Subroutine does not return */
    _invalid_parameter_noinfo_noreturn();
  }
  operator_delete(pvVar1);
  if (0xf < *(ulonglong *)(unaff_RBP + -0x19)) {
    pvVar1 = *(void **)(unaff_RBP + -0x31);
    pvVar2 = pvVar1;
    if ((0xfff < *(ulonglong *)(unaff_RBP + -0x19) + 1) &&
       (pvVar2 = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar2)))) goto LAB_18001fd9f;
    operator_delete(pvVar2);
  }
  if (0xf < *(ulonglong *)(unaff_RBP + 7)) {
    pvVar1 = unaff_R13;
    if ((0xfff < *(ulonglong *)(unaff_RBP + 7) + 1) &&
       (pvVar1 = *(void **)((longlong)unaff_R13 + -8),
       0x1f < (ulonglong)((longlong)unaff_R13 + (-8 - (longlong)pvVar1)))) goto LAB_18001fd9f;
    operator_delete(pvVar1);
  }
  return;
}

/* ---- FUNC 0001FDD0 ReadGraphicsFromBuffer (243 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void ReadGraphicsFromBuffer
               (char *param_1,undefined8 *param_2,undefined8 param_3,longlong param_4,
               undefined8 *param_5,undefined8 *param_6)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined1 auStackY_478 [32];
  longlong *local_448 [2];
  undefined1 local_438 [1008];
  ulonglong local_48;
  
                    /* 0x1fdd0  438  ReadGraphicsFromBuffer */
  local_48 = DAT_1800791f8 ^ (ulonglong)auStackY_478;
  puVar3 = (undefined8 *)0x0;
  local_448[0] = (longlong *)0x0;
  puVar2 = operator_new(0x118);
  if (puVar2 != (undefined8 *)0x0) {
    puVar3 = FUN_180018910(puVar2,param_3,0,param_4);
  }
  iVar1 = (**(code **)*puVar3)(puVar3,&DAT_180057a78,local_448);
  if (iVar1 != 0) {
    FUN_180007de0(local_438,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\bkputil.cpp",0x52d);
    LogMessage(local_438,2,1);
  }
  FUN_180019f80(local_448[0],param_1,param_2,(uint *)0x0,param_5,param_6);
  return;
}

/* ---- FUNC 0001FED0 ReadGraphicsFromBuffer2 (313 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong ReadGraphicsFromBuffer2
                    (char *param_1,undefined8 *param_2,longlong param_3,undefined4 param_4,
                    longlong param_5)

{
  int iVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  ulonglong uVar4;
  undefined1 auStackY_468 [32];
  longlong *local_438 [2];
  undefined1 local_428 [1008];
  ulonglong local_38;
  
                    /* 0x1fed0  439  ReadGraphicsFromBuffer2 */
  local_38 = DAT_1800791f8 ^ (ulonglong)auStackY_468;
  plVar3 = (longlong *)0x0;
  local_438[0] = (longlong *)0x0;
  puVar2 = operator_new(0x130);
  if (puVar2 != (undefined8 *)0x0) {
    plVar3 = FUN_180018790(puVar2,param_5,0,0);
  }
  (**(code **)(*plVar3 + 8))(plVar3);
  plVar3[0x23] = param_3;
  *(undefined4 *)(plVar3 + 0x25) = param_4;
  *(undefined4 *)((longlong)plVar3 + 0x124) = param_4;
  iVar1 = (**(code **)*plVar3)(plVar3,&DAT_180057a78,local_438);
  if (iVar1 != 0) {
    FUN_180007de0(local_428,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\bkputil.cpp",0x54a);
    LogMessage(local_428,2,1);
  }
  uVar4 = FUN_180019f80(local_438[0],param_1,param_2,(uint *)0x0,(undefined8 *)0x0,(undefined8 *)0x0
                       );
  plVar3[0x23] = 0;
  *(undefined8 *)((longlong)plVar3 + 0x124) = 0;
  (**(code **)(*plVar3 + 0x10))(plVar3);
  return uVar4 & 0xffffffff;
}

/* ---- FUNC 00020010 ReadGraphicsFromFile (283 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void ReadGraphicsFromFile
               (undefined8 param_1,char *param_2,undefined8 *param_3,undefined8 param_4,
               uint *param_5,longlong param_6,undefined8 *param_7,undefined8 *param_8)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined1 auStackY_488 [32];
  longlong *local_458;
  undefined8 *local_450;
  undefined1 local_448 [1008];
  ulonglong local_58;
  
                    /* 0x20010  440  ReadGraphicsFromFile */
  local_58 = DAT_1800791f8 ^ (ulonglong)auStackY_488;
  puVar3 = (undefined8 *)0x0;
  local_450 = param_8;
  local_458 = (longlong *)0x0;
  puVar2 = operator_new(0x138);
  if (puVar2 != (undefined8 *)0x0) {
    puVar3 = FUN_180018980(puVar2,param_1,0,param_4,0,param_6);
  }
  iVar1 = (**(code **)*puVar3)(puVar3,&DAT_180057a78,&local_458);
  if (iVar1 != 0) {
    FUN_180007de0(local_448,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\bkputil.cpp",0x53b);
    LogMessage(local_448,2,1);
  }
  FUN_180019f80(local_458,param_2,param_3,param_5,param_7,local_450);
  return;
}

/* ---- FUNC 00020130 ReadGraphicsFromStream (193 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void ReadGraphicsFromStream
               (char *param_1,undefined8 *param_2,undefined8 *param_3,uint *param_4,
               undefined8 *param_5,undefined8 *param_6)

{
  int iVar1;
  undefined1 auStackY_468 [32];
  longlong *local_438 [2];
  undefined1 local_428 [1008];
  ulonglong local_38;
  
                    /* 0x20130  441  ReadGraphicsFromStream */
  local_38 = DAT_1800791f8 ^ (ulonglong)auStackY_468;
  iVar1 = (**(code **)*param_3)(param_3,&DAT_180057a78,local_438);
  if (iVar1 != 0) {
    FUN_180007de0(local_428,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\bkputil.cpp",0x559);
    LogMessage(local_428,2,1);
  }
  FUN_180019f80(local_438[0],param_1,param_2,param_4,param_5,param_6);
  return;
}

/* ---- FUNC 00020200 ReadOLELink (59 bytes) ---- */

ulonglong ReadOLELink(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  uint uVar1;
  ulonglong uVar2;
  longlong *local_res18;
  longlong *local_res20;
  
                    /* 0x20200  442  ReadOLELink */
  if (param_3 == (undefined8 *)0x0) {
    return 0;
  }
  uVar2 = (**(code **)*param_3)(param_3,&DAT_180056180,&local_res18);
  if (-1 < (int)uVar2) {
    uVar1 = (**(code **)(*local_res18 + 0x38))(local_res18,&local_res20);
    (**(code **)(*local_res18 + 0x10))();
    if (-1 < (int)uVar1) {
      uVar1 = (**(code **)(*local_res20 + 0x120))(local_res20,param_1,1);
      (**(code **)(*local_res20 + 0x10))();
    }
    uVar2 = (ulonglong)uVar1;
  }
  return uVar2;
}

/* ---- FUNC 0002023B FUN_18002023b (71 bytes) ---- */

int FUN_18002023b(longlong *param_1)

{
  int iVar1;
  longlong *in_stack_00000040;
  longlong *in_stack_00000048;
  
  iVar1 = (**(code **)(*param_1 + 0x38))();
  (**(code **)(*in_stack_00000040 + 0x10))();
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*in_stack_00000048 + 0x120))();
    (**(code **)(*in_stack_00000048 + 0x10))();
  }
  return iVar1;
}

/* ---- FUNC 00020282 FUN_180020282 (6 bytes) ---- */

void FUN_180020282(void)

{
  return;
}

/* ---- FUNC 00020290 ReadOLELinkFromBuffer (224 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong ReadOLELinkFromBuffer(undefined8 param_1,undefined8 *param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  undefined1 auStack_448 [32];
  longlong *local_428 [2];
  undefined1 local_418 [1008];
  ulonglong local_28;
  
                    /* 0x20290  443  ReadOLELinkFromBuffer */
  local_28 = DAT_1800791f8 ^ (ulonglong)auStack_448;
  puVar3 = (undefined8 *)0x0;
  local_428[0] = (longlong *)0x0;
  puVar2 = operator_new(0x118);
  if (puVar2 != (undefined8 *)0x0) {
    puVar3 = FUN_180018910(puVar2,param_3,0,0);
  }
  iVar1 = (**(code **)*puVar3)(puVar3,&DAT_180057a78,local_428);
  if (iVar1 != 0) {
    FUN_180007de0(local_418,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\bkputil.cpp",0x604);
    LogMessage(local_418,2,1);
  }
  uVar4 = ReadOLELink(local_428[0],param_1,param_2);
  (**(code **)(*local_428[0] + 0x10))();
  return uVar4 & 0xffffffff;
}

/* ---- FUNC 00020370 ReadOLELinkFromFile (231 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong ReadOLELinkFromFile(undefined8 param_1,undefined8 param_2,undefined8 *param_3,
                             undefined8 param_4)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  undefined1 auStackY_468 [32];
  longlong *local_438 [2];
  undefined1 local_428 [1008];
  ulonglong local_38;
  
                    /* 0x20370  444  ReadOLELinkFromFile */
  local_38 = DAT_1800791f8 ^ (ulonglong)auStackY_468;
  puVar3 = (undefined8 *)0x0;
  local_438[0] = (longlong *)0x0;
  puVar2 = operator_new(0x138);
  if (puVar2 != (undefined8 *)0x0) {
    puVar3 = FUN_180018980(puVar2,param_1,0,param_4,0,0);
  }
  iVar1 = (**(code **)*puVar3)(puVar3,&DAT_180057a78,local_438);
  if (iVar1 != 0) {
    FUN_180007de0(local_428,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\bkputil.cpp",0x611);
    LogMessage(local_428,2,1);
  }
  uVar4 = ReadOLELink(local_438[0],param_2,param_3);
  (**(code **)(*local_438[0] + 0x10))();
  return uVar4 & 0xffffffff;
}

/* ---- FUNC 00020460 ReadStreamLine (97 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong ReadStreamLine(longlong *param_1,char *param_2,int param_3)

{
  ulonglong uVar1;
  undefined1 auStack_848 [32];
  char local_828 [2048];
  ulonglong local_28;
  
                    /* 0x20460  445  ReadStreamLine */
  local_28 = DAT_1800791f8 ^ (ulonglong)auStack_848;
  uVar1 = FUN_18001b180(param_1,(longlong)local_828);
  if (-1 < (int)uVar1) {
    strncpy(param_2,local_828,(longlong)param_3);
    uVar1 = uVar1 & 0xffffffff;
  }
  return uVar1;
}

/* ---- FUNC 000204D0 ResetBufferStreamState (13 bytes) ---- */

void ResetBufferStreamState(longlong *param_1)

{
                    /* 0x204d0  447  ResetBufferStreamState */
  if (param_1 != (longlong *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0001800204d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x78))();
    return;
  }
  return;
}

/* ---- FUNC 000204E0 SetPastingStatus (7 bytes) ---- */

void SetPastingStatus(undefined4 param_1)

{
                    /* 0x204e0  527  SetPastingStatus */
  DAT_18007a2a8 = param_1;
  return;
}

/* ---- FUNC 000204F0 SigReadGraphStrmsAndBlksOnly (75 bytes) ---- */

ulonglong SigReadGraphStrmsAndBlksOnly(undefined8 *param_1)

{
  ulonglong uVar1;
  longlong *local_res8 [4];
  
                    /* 0x204f0  528  SigReadGraphStrmsAndBlksOnly */
  if (param_1 == (undefined8 *)0x0) {
    return 1;
  }
  local_res8[0] = (longlong *)0x0;
  uVar1 = FUN_180019280(param_1,local_res8);
  if (-1 < (int)uVar1) {
    (**(code **)(*local_res8[0] + 0x10))();
    PostMainWndMessage(0x4d4,0x1e,0);
    uVar1 = 0;
  }
  return uVar1;
}

/* ---- FUNC 00020540 SignalReadGraphics (125 bytes) ---- */

ulonglong SignalReadGraphics(undefined8 *param_1,int param_2)

{
  ulonglong uVar1;
  longlong *local_res8 [4];
  
                    /* 0x20540  529  SignalReadGraphics */
  if ((param_1 == (undefined8 *)0x0) || (param_2 == DAT_18007a26c)) {
    uVar1 = 1;
  }
  else {
    local_res8[0] = (longlong *)0x0;
    uVar1 = FUN_180019280(param_1,local_res8);
    if (-1 < (int)uVar1) {
      (**(code **)(*local_res8[0] + 0x10))();
      if (param_2 == 1) {
        PostMainWndMessage(0x4d4,0x12,0);
        DAT_18007a26c = param_2;
        return 0;
      }
      DAT_18007a26c = param_2;
      PostMainWndMessage(0x4d4,0x13,0);
      return 0;
    }
  }
  return uVar1;
}

/* ---- FUNC 000205C0 Write90CArestoreMap (2389 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Write90CArestoreMap(void *param_1,char *param_2,char *param_3,int *param_4)

{
  ulonglong uVar1;
  char cVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  char *pcVar6;
  longlong lVar7;
  undefined8 uVar8;
  longlong *plVar9;
  undefined8 *puVar10;
  int iVar11;
  uint uVar12;
  ulonglong uVar13;
  longlong *plVar14;
  void *pvVar15;
  undefined8 ****_Dst;
  longlong *plVar16;
  longlong *plVar17;
  longlong lVar18;
  char *pcVar19;
  undefined8 ***pppuVar20;
  void *pvVar21;
  undefined8 *****pppppuVar22;
  size_t sVar23;
  longlong *plVar24;
  size_t sVar25;
  int iVar26;
  undefined8 *****pppppuVar27;
  undefined1 auStack_158 [32];
  void *local_138;
  longlong local_130;
  void *local_128;
  longlong local_120;
  char *local_118;
  undefined8 uStack_110;
  int *local_f8;
  char *local_f0;
  char *local_e8;
  undefined8 uStack_e0;
  longlong local_d8;
  undefined8 ***local_d0;
  undefined8 ***pppuStack_c8;
  ulonglong local_c0;
  ulonglong uStack_b8;
  longlong *local_b0;
  longlong local_a8;
  undefined8 ****local_a0;
  undefined8 uStack_98;
  size_t local_90;
  ulonglong local_88;
  void *local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  ulonglong uStack_68;
  void *local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  ulonglong uStack_48;
  ulonglong local_40;
  
                    /* 0x205c0  530  Write90CArestoreMap */
  local_40 = DAT_1800791f8 ^ (ulonglong)auStack_158;
  local_130 = 0;
  local_118 = param_2;
  local_f8 = param_4;
  local_f0 = param_3;
  local_138 = operator_new(0x38);
  *(void **)local_138 = local_138;
  *(void **)((longlong)local_138 + 8) = local_138;
  *(void **)((longlong)local_138 + 0x10) = local_138;
  *(undefined2 *)((longlong)local_138 + 0x18) = 0x101;
  local_120 = 0;
  local_128 = operator_new(0x38);
  sVar23 = 0xffffffffffffffff;
  local_60 = (void *)0x0;
  uStack_58 = 0;
  *(void **)local_128 = local_128;
  sVar25 = 0xffffffffffffffff;
  *(void **)((longlong)local_128 + 8) = local_128;
  *(void **)((longlong)local_128 + 0x10) = local_128;
  *(undefined2 *)((longlong)local_128 + 0x18) = 0x101;
  local_50 = 0;
  uStack_48 = 0;
  do {
    sVar25 = sVar25 + 1;
  } while (param_2[sVar25] != '\0');
  FUN_18000b5f0(&local_60,param_2,sVar25);
  local_80 = (void *)0x0;
  uStack_78 = 0;
  sVar25 = 0xffffffffffffffff;
  local_70 = 0;
  uStack_68 = 0;
  do {
    sVar25 = sVar25 + 1;
  } while (param_3[sVar25] != '\0');
  FUN_18000b5f0(&local_80,param_3,sVar25);
  local_90 = 0;
  local_a0 = (undefined8 *****)0x0;
  uStack_98 = 0;
  local_88 = 0;
  do {
    sVar23 = sVar23 + 1;
  } while (*(char *)((longlong)param_1 + sVar23) != '\0');
  FUN_18000b5f0(&local_a0,param_1,sVar23);
  iVar26 = 1;
  plVar14 = (longlong *)*DAT_18007a288;
  plVar16 = DAT_18007a288;
  pppppuVar27 = (undefined8 *****)local_a0;
  if (plVar14 != DAT_18007a288) {
    do {
      plVar17 = plVar14 + 4;
      pppppuVar22 = &local_a0;
      if (0xf < local_88) {
        pppppuVar22 = pppppuVar27;
      }
      if (0xf < (ulonglong)plVar14[7]) {
        plVar17 = (longlong *)plVar14[4];
      }
      if ((plVar14[6] == local_90) &&
         (iVar11 = memcmp(plVar17,pppppuVar22,plVar14[6]), plVar16 = DAT_18007a288, iVar11 == 0)) {
        plVar17 = (longlong *)plVar14[8];
        plVar24 = (longlong *)*plVar17;
        if (plVar24 != plVar17) {
          iVar11 = *local_f8;
          do {
            if ((int)plVar24[4] == iVar11) {
              puVar3 = (undefined8 *)plVar24[5];
              iVar26 = iVar26 + 1;
              puVar4 = (undefined8 *)*puVar3;
              while (puVar4 != puVar3) {
                uVar13 = FUN_1800175e0(puVar4 + 4,&local_60);
                if (((char)uVar13 != '\0') &&
                   (uVar13 = FUN_1800175e0((void *)((longlong)puVar4 + 0x2c),&local_80),
                   pppppuVar27 = (undefined8 *****)local_a0, (char)uVar13 != '\0'))
                goto LAB_180020d7e;
                puVar5 = (undefined8 *)puVar4[2];
                if (*(char *)((longlong)puVar5 + 0x19) == '\0') {
                  cVar2 = *(char *)((longlong)*puVar5 + 0x19);
                  puVar4 = puVar5;
                  puVar5 = (undefined8 *)*puVar5;
                  while (cVar2 == '\0') {
                    cVar2 = *(char *)((longlong)*puVar5 + 0x19);
                    puVar4 = puVar5;
                    puVar5 = (undefined8 *)*puVar5;
                  }
                }
                else {
                  cVar2 = *(char *)((longlong)puVar4[1] + 0x19);
                  puVar10 = (undefined8 *)puVar4[1];
                  puVar5 = puVar4;
                  while ((puVar4 = puVar10, cVar2 == '\0' && (puVar5 == (undefined8 *)puVar4[2]))) {
                    cVar2 = *(char *)((longlong)puVar4[1] + 0x19);
                    puVar10 = (undefined8 *)puVar4[1];
                    puVar5 = puVar4;
                  }
                }
              }
            }
            plVar16 = (longlong *)plVar24[2];
            if (*(char *)((longlong)plVar16 + 0x19) == '\0') {
              cVar2 = *(char *)(*plVar16 + 0x19);
              plVar24 = plVar16;
              plVar16 = (longlong *)*plVar16;
              while (cVar2 == '\0') {
                cVar2 = *(char *)(*plVar16 + 0x19);
                plVar24 = plVar16;
                plVar16 = (longlong *)*plVar16;
              }
            }
            else {
              cVar2 = *(char *)(plVar24[1] + 0x19);
              plVar9 = (longlong *)plVar24[1];
              plVar16 = plVar24;
              while ((plVar24 = plVar9, cVar2 == '\0' && (plVar16 == (longlong *)plVar24[2]))) {
                cVar2 = *(char *)(plVar24[1] + 0x19);
                plVar9 = (longlong *)plVar24[1];
                plVar16 = plVar24;
              }
            }
            plVar16 = DAT_18007a288;
            pppppuVar27 = (undefined8 *****)local_a0;
          } while (plVar24 != plVar17);
        }
      }
      plVar17 = (longlong *)plVar14[2];
      if (*(char *)((longlong)plVar17 + 0x19) == '\0') {
        cVar2 = *(char *)(*plVar17 + 0x19);
        plVar14 = plVar17;
        plVar17 = (longlong *)*plVar17;
        while (cVar2 == '\0') {
          cVar2 = *(char *)(*plVar17 + 0x19);
          plVar14 = plVar17;
          plVar17 = (longlong *)*plVar17;
        }
      }
      else {
        cVar2 = *(char *)(plVar14[1] + 0x19);
        plVar24 = (longlong *)plVar14[1];
        plVar17 = plVar14;
        while ((plVar14 = plVar24, cVar2 == '\0' && (plVar17 == (longlong *)plVar14[2]))) {
          cVar2 = *(char *)(plVar14[1] + 0x19);
          plVar24 = (longlong *)plVar14[1];
          plVar17 = plVar14;
        }
      }
      param_3 = local_f0;
      param_2 = local_118;
    } while (plVar14 != plVar16);
  }
  pvVar21 = local_128;
  lVar18 = (longlong)&local_e8 - (longlong)param_2;
  do {
    cVar2 = *param_2;
    param_2[lVar18] = cVar2;
    param_2 = param_2 + 1;
  } while (cVar2 != '\0');
  lVar18 = 4 - (longlong)param_3;
  do {
    cVar2 = *param_3;
    param_3[(longlong)&uStack_e0 + lVar18] = cVar2;
    param_3 = param_3 + 1;
  } while (cVar2 != '\0');
  plVar14 = operator_new(0x38);
  _Dst = (undefined8 ****)0x0;
  plVar14[4] = (longlong)local_e8;
  plVar14[5] = (longlong)uStack_e0;
  *(int *)((longlong)plVar14 + 0x1c) = iVar26;
  plVar14[6] = local_d8;
  *plVar14 = (longlong)pvVar21;
  plVar14[1] = (longlong)pvVar21;
  plVar14[2] = (longlong)pvVar21;
  *(undefined2 *)(plVar14 + 3) = 0;
  uStack_e0 = (void *)((ulonglong)uStack_e0 & 0xffffffff00000000);
  pcVar19 = *(char **)((longlong)local_128 + 8);
  cVar2 = pcVar19[0x19];
  local_e8 = pcVar19;
  uStack_110 = (ulonglong)uStack_e0;
  while (pcVar6 = pcVar19, cVar2 == '\0') {
    uStack_e0._4_4_ = (uint)(uStack_110 >> 0x20);
    if (iVar26 < *(int *)(pcVar6 + 0x1c)) {
      pcVar19 = *(char **)pcVar6;
      uStack_e0 = (void *)CONCAT44(uStack_e0._4_4_,1);
    }
    else {
      pcVar19 = *(char **)(pcVar6 + 0x10);
      uStack_e0 = (void *)((ulonglong)uStack_e0._4_4_ << 0x20);
    }
    cVar2 = pcVar19[0x19];
    local_e8 = pcVar6;
    uStack_110 = (ulonglong)uStack_e0;
  }
  uStack_e0 = (void *)uStack_110;
  if (local_120 == 0x492492492492492) {
                    /* WARNING: Subroutine does not return */
    FUN_18000ac90();
  }
  local_118 = local_e8;
  FUN_18000a930((longlong *)&local_128,(longlong *)&local_118,plVar14);
  local_e8 = (char *)CONCAT44(local_e8._4_4_,*local_f8);
  FUN_1800185f0(&uStack_e0,(longlong *)&local_128,plVar14,plVar16);
  pvVar21 = local_138;
  plVar14 = operator_new(0x38);
  *(undefined4 *)(plVar14 + 4) = local_e8._0_4_;
  plVar14[5] = 0;
  plVar14[6] = 0;
  pvVar15 = operator_new(0x38);
  uStack_110 = uStack_110 & 0xffffffff00000000;
  *(void **)pvVar15 = pvVar15;
  *(void **)((longlong)pvVar15 + 8) = pvVar15;
  *(void **)((longlong)pvVar15 + 0x10) = pvVar15;
  *(undefined2 *)((longlong)pvVar15 + 0x18) = 0x101;
  plVar14[5] = (longlong)uStack_e0;
  lVar18 = plVar14[6];
  plVar14[6] = local_d8;
  *plVar14 = (longlong)pvVar21;
  plVar14[1] = (longlong)pvVar21;
  plVar14[2] = (longlong)pvVar21;
  *(undefined2 *)(plVar14 + 3) = 0;
  local_118 = *(char **)((longlong)local_138 + 8);
  if (local_118[0x19] == '\0') {
    pcVar19 = local_118;
    do {
      local_118 = pcVar19;
      if ((int)plVar14[4] < *(int *)(local_118 + 0x20)) {
        pcVar19 = *(char **)local_118;
        uStack_110 = CONCAT44(uStack_110._4_4_,1);
      }
      else {
        pcVar19 = *(char **)(local_118 + 0x10);
        uStack_110 = (ulonglong)uStack_110._4_4_ << 0x20;
      }
    } while (pcVar19[0x19] == '\0');
  }
  uStack_e0 = pvVar15;
  local_d8 = lVar18;
  if (local_130 == 0x492492492492492) {
                    /* WARNING: Subroutine does not return */
    FUN_18000ac90();
  }
  FUN_18000a930((longlong *)&local_138,(longlong *)&local_118,plVar14);
  FUN_180017b60(&uStack_e0,&uStack_e0);
  sVar23 = local_90;
  pppppuVar22 = &local_a0;
  if (0xf < local_88) {
    pppppuVar22 = pppppuVar27;
  }
  local_d0 = (undefined8 ***)0x0;
  pppuStack_c8 = (undefined8 ****)0x0;
  if (0x7fffffffffffffff < local_90) {
                    /* WARNING: Subroutine does not return */
    FUN_18000ace0();
  }
  if (local_90 < 0x10) {
    local_c0 = local_90;
    uStack_b8 = 0xf;
    local_d0 = *pppppuVar22;
    pppuStack_c8 = pppppuVar22[1];
  }
  else {
    uVar13 = local_90 | 0xf;
    if (uVar13 < 0x8000000000000000) {
      if (uVar13 < 0x16) {
        uVar13 = 0x16;
      }
      uVar1 = uVar13 + 1;
      if (uVar1 < 0x1000) {
        if (uVar1 != 0) {
          _Dst = operator_new(uVar1);
        }
      }
      else {
        _Dst = (undefined8 ****)FUN_180007f10(uVar1);
      }
    }
    else {
      _Dst = (undefined8 ****)FUN_180007f10(0x8000000000000000);
      uVar13 = 0x7fffffffffffffff;
    }
    local_c0 = sVar23;
    local_d0 = _Dst;
    uStack_b8 = uVar13;
    memcpy(_Dst,pppppuVar22,sVar23 + 1);
  }
  local_a8 = 0;
  local_b0 = operator_new(0x38);
  *local_b0 = (longlong)local_b0;
  local_b0[1] = (longlong)local_b0;
  local_b0[2] = (longlong)local_b0;
  *(undefined2 *)(local_b0 + 3) = 0x101;
  plVar14 = FUN_180017700(&local_b0,*(undefined8 **)((longlong)local_138 + 8),(longlong)local_b0,
                          plVar16);
  local_b0[1] = (longlong)plVar14;
  local_a8 = local_130;
  plVar14 = (longlong *)local_b0[1];
  if (*(char *)((longlong)plVar14 + 0x19) == '\0') {
    cVar2 = *(char *)(*plVar14 + 0x19);
    plVar16 = (longlong *)*plVar14;
    while (cVar2 == '\0') {
      cVar2 = *(char *)(*plVar16 + 0x19);
      plVar14 = plVar16;
      plVar16 = (longlong *)*plVar16;
    }
    *local_b0 = (longlong)plVar14;
    lVar18 = *(longlong *)(local_b0[1] + 0x10);
    cVar2 = *(char *)(lVar18 + 0x19);
    lVar7 = local_b0[1];
    while (cVar2 == '\0') {
      cVar2 = *(char *)(*(longlong *)(lVar18 + 0x10) + 0x19);
      lVar7 = lVar18;
      lVar18 = *(longlong *)(lVar18 + 0x10);
    }
    local_b0[2] = lVar7;
  }
  else {
    *local_b0 = (longlong)local_b0;
    local_b0[2] = (longlong)local_b0;
  }
  plVar14 = DAT_18007a288;
  plVar16 = operator_new(0x50);
  plVar16[6] = 0;
  plVar16[7] = 0;
  plVar16[4] = (longlong)local_d0;
  plVar16[5] = (longlong)pppuStack_c8;
  uVar13 = _UNK_180053828;
  uVar8 = _DAT_180053820;
  plVar16[6] = local_c0;
  plVar16[7] = uStack_b8;
  local_d0 = (undefined8 ***)((ulonglong)local_d0 & 0xffffffffffffff00);
  local_c0 = uVar8;
  uStack_b8 = uVar13;
  plVar16[8] = 0;
  plVar16[9] = 0;
  plVar17 = operator_new(0x38);
  uStack_e0 = (void *)((ulonglong)uStack_e0 & 0xffffffff00000000);
  *plVar17 = (longlong)plVar17;
  plVar17[1] = (longlong)plVar17;
  plVar17[2] = (longlong)plVar17;
  *(undefined2 *)(plVar17 + 3) = 0x101;
  plVar16[8] = (longlong)local_b0;
  lVar18 = plVar16[9];
  plVar16[9] = local_a8;
  *plVar16 = (longlong)plVar14;
  plVar16[1] = (longlong)plVar14;
  plVar16[2] = (longlong)plVar14;
  *(undefined2 *)(plVar16 + 3) = 0;
  pcVar19 = (char *)DAT_18007a288[1];
  cVar2 = pcVar19[0x19];
  local_a8 = lVar18;
  local_e8 = pcVar19;
  local_b0 = plVar17;
  while (cVar2 == '\0') {
    local_e8 = pcVar19;
    uVar12 = FUN_180007ea0(plVar16 + 4,(undefined8 *)(pcVar19 + 0x20));
    if ((char)uVar12 == '\0') {
      pcVar19 = *(char **)(pcVar19 + 0x10);
      uStack_e0 = (void *)((ulonglong)uStack_e0._4_4_ << 0x20);
    }
    else {
      pcVar19 = *(char **)pcVar19;
      uStack_e0 = (void *)CONCAT44(uStack_e0._4_4_,1);
    }
    cVar2 = pcVar19[0x19];
  }
  if (DAT_18007a290 == 0x333333333333333) {
                    /* WARNING: Subroutine does not return */
    FUN_18000ac90();
  }
  local_118 = local_e8;
  uStack_110 = (ulonglong)uStack_e0;
  FUN_18000a930((longlong *)&DAT_18007a288,(longlong *)&local_118,plVar16);
  FUN_180017c40(&local_b0,&local_b0,(longlong *)local_b0[1]);
  operator_delete(local_b0);
  if (0xf < uStack_b8) {
    pppuVar20 = local_d0;
    if ((0xfff < uStack_b8 + 1) &&
       (pppuVar20 = *(undefined8 ****)((longlong)local_d0 + -8),
       0x1f < (ulonglong)((longlong)local_d0 + (-8 - (longlong)pppuVar20)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pppuVar20);
  }
LAB_180020d7e:
  if (0xf < local_88) {
    pppppuVar22 = pppppuVar27;
    if ((0xfff < local_88 + 1) &&
       (pppppuVar22 = (undefined8 *****)pppppuVar27[-1],
       0x1f < (ulonglong)((longlong)pppppuVar27 + (-8 - (longlong)pppppuVar22))))
    goto LAB_180020e1e;
    operator_delete(pppppuVar22);
  }
  if (0xf < uStack_68) {
    pvVar21 = local_80;
    if ((0xfff < uStack_68 + 1) &&
       (pvVar21 = *(void **)((longlong)local_80 + -8),
       0x1f < (ulonglong)((longlong)local_80 + (-8 - (longlong)pvVar21)))) goto LAB_180020e1e;
    operator_delete(pvVar21);
  }
  if (0xf < uStack_48) {
    pvVar21 = local_60;
    if ((0xfff < uStack_48 + 1) &&
       (pvVar21 = *(void **)((longlong)local_60 + -8),
       0x1f < (ulonglong)((longlong)local_60 + (-8 - (longlong)pvVar21)))) {
LAB_180020e1e:
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar21);
  }
  cVar2 = *(char *)((longlong)*(longlong **)((longlong)local_128 + 8) + 0x19);
  plVar14 = *(longlong **)((longlong)local_128 + 8);
  while (cVar2 == '\0') {
    FUN_180017be0(&local_128,&local_128,(longlong *)plVar14[2]);
    plVar16 = (longlong *)*plVar14;
    operator_delete(plVar14);
    plVar14 = plVar16;
    cVar2 = *(char *)((longlong)plVar16 + 0x19);
  }
  operator_delete(local_128);
  cVar2 = *(char *)((longlong)*(longlong **)((longlong)local_138 + 8) + 0x19);
  plVar14 = *(longlong **)((longlong)local_138 + 8);
  while (cVar2 == '\0') {
    FUN_180017c40(&local_138,&local_138,(longlong *)plVar14[2]);
    plVar16 = (longlong *)*plVar14;
    FUN_180017b60(plVar14 + 5,plVar14 + 5);
    operator_delete(plVar14);
    plVar14 = plVar16;
    cVar2 = *(char *)((longlong)plVar16 + 0x19);
  }
  operator_delete(local_138);
  return;
}

/* ---- FUNC 00020F20 WriteACEStringToIStream (117 bytes) ---- */

undefined4 WriteACEStringToIStream(longlong *param_1)

{
  int iVar1;
  longlong lVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined4 local_res8 [2];
  longlong local_res10;
  
                    /* 0x20f20  531  WriteACEStringToIStream */
  uVar3 = 0;
  local_res8[0] = 0;
  pcVar4 = (char *)FUN_180019c90();
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res10,pcVar4);
  iVar1 = *(int *)(local_res10 + -0x10);
  if (iVar1 != 0) {
    lVar2 = *param_1;
    pcVar4 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)&local_res10);
    uVar3 = (**(code **)(lVar2 + 0x20))(param_1,pcVar4,iVar1,local_res8);
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res10);
  return uVar3;
}

/* ---- FUNC 00020FA0 WriteApwnBlock (230 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WriteApwnBlock(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 *puVar2;
  undefined1 auStackY_458 [32];
  longlong *local_428 [2];
  undefined1 local_418 [1008];
  ulonglong local_28;
  
                    /* 0x20fa0  532  WriteApwnBlock */
  local_28 = DAT_1800791f8 ^ (ulonglong)auStackY_458;
  puVar2 = operator_new(0x138);
  if (puVar2 == (undefined8 *)0x0) {
    puVar2 = (undefined8 *)0x0;
  }
  else {
    puVar2 = FUN_180018980(puVar2,param_1,param_2,0,param_3,0);
  }
  local_428[0] = (longlong *)0x0;
  iVar1 = (**(code **)*puVar2)(puVar2,&DAT_180057a78,local_428);
  if (iVar1 != 0) {
    FUN_180007de0(local_418,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\bkputil.cpp",0x784);
    LogMessage(local_418,2,1);
  }
  if (g_pApwnBlockUsage != (CApwnBlockUsage *)0x0) {
    FUN_180007290((longlong)g_pApwnBlockUsage,local_428[0]);
  }
  (**(code **)(*local_428[0] + 0x10))();
  return;
}

/* ---- FUNC 00021090 WriteApwnBlockUsages (401 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WriteApwnBlockUsages
               (undefined8 param_1,longlong *param_2,longlong param_3,int param_4,undefined8 param_5
               )

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this;
  char *pcVar4;
  undefined8 *puVar5;
  longlong lVar6;
  undefined1 auStackY_4b8 [32];
  char *local_488;
  longlong *local_480;
  CMapStringToString local_478 [64];
  undefined1 local_438 [1008];
  ulonglong local_48;
  
                    /* 0x21090  533  WriteApwnBlockUsages */
  local_48 = DAT_1800791f8 ^ (ulonglong)auStackY_4b8;
  puVar2 = operator_new(0x138);
  puVar5 = (undefined8 *)0x0;
  puVar3 = puVar5;
  if (puVar2 != (undefined8 *)0x0) {
    puVar3 = FUN_180018980(puVar2,param_1,0,0,param_5,0);
  }
  local_480 = (longlong *)0x0;
  iVar1 = (**(code **)*puVar3)(puVar3,&DAT_180057a78,&local_480);
  if (iVar1 != 0) {
    FUN_180007de0(local_438,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\bkputil.cpp",0x797);
    LogMessage(local_438,2,1);
  }
  if (g_pApwnBlockUsage != (CApwnBlockUsage *)0x0) {
    CMapStringToString::CMapStringToString(local_478,(longlong)param_4);
    if (0 < param_4) {
      lVar6 = param_3 - (longlong)param_2;
      do {
        if (*param_2 == 0) break;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_488);
        if ((param_3 == 0) ||
           (pcVar4 = *(char **)(lVar6 + (longlong)param_2), pcVar4 == (char *)0x0)) {
          pcVar4 = (char *)*param_2;
        }
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_488,
                   pcVar4);
        pcVar4 = local_488;
        this = CMapStringToString::operator[](local_478,(char *)*param_2);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(this,pcVar4);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_488);
        puVar5 = (undefined8 *)((longlong)puVar5 + 1);
        param_2 = param_2 + 1;
      } while ((longlong)puVar5 < (longlong)param_4);
    }
    FUN_1800073c0((longlong)g_pApwnBlockUsage,local_480,local_478);
    CMapStringToString::~CMapStringToString(local_478);
  }
  (**(code **)(*local_480 + 0x10))();
  return;
}

/* ---- FUNC 00021230 WriteApwnBlockUsagesToBuffer (174 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WriteApwnBlockUsagesToBuffer(longlong *param_1,longlong param_2,int param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this;
  char *pcVar4;
  undefined8 *puVar5;
  longlong lVar6;
  undefined1 auStack_4a8 [32];
  char *local_488;
  longlong *local_480;
  CMapStringToString local_478 [64];
  undefined1 local_438 [1008];
  ulonglong local_48;
  
                    /* 0x21230  534  WriteApwnBlockUsagesToBuffer */
  local_48 = DAT_1800791f8 ^ (ulonglong)auStack_4a8;
  puVar5 = (undefined8 *)0x0;
  local_480 = (longlong *)0x0;
  puVar2 = operator_new(0x118);
  puVar3 = puVar5;
  if (puVar2 != (undefined8 *)0x0) {
    puVar3 = FUN_180018910(puVar2,0,param_4,0);
  }
  iVar1 = (**(code **)*puVar3)(puVar3,&DAT_180057a78,&local_480);
  if (iVar1 != 0) {
    FUN_180007de0(local_438,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\bkputil.cpp",0x7af);
    LogMessage(local_438,2,1);
  }
  if (g_pApwnBlockUsage != (CApwnBlockUsage *)0x0) {
    CMapStringToString::CMapStringToString(local_478,(longlong)param_3);
    if (0 < param_3) {
      lVar6 = param_2 - (longlong)param_1;
      do {
        if (*param_1 == 0) break;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_488);
        if ((param_2 == 0) ||
           (pcVar4 = *(char **)(lVar6 + (longlong)param_1), pcVar4 == (char *)0x0)) {
          pcVar4 = (char *)*param_1;
        }
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_488,
                   pcVar4);
        pcVar4 = local_488;
        this = CMapStringToString::operator[](local_478,(char *)*param_1);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(this,pcVar4);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_488);
        puVar5 = (undefined8 *)((longlong)puVar5 + 1);
        param_1 = param_1 + 1;
      } while ((longlong)puVar5 < (longlong)param_3);
    }
    FUN_1800073c0((longlong)g_pApwnBlockUsage,local_480,local_478);
    CMapStringToString::~CMapStringToString(local_478);
  }
  (**(code **)(*local_480 + 0x10))();
  return;
}

/* ---- FUNC 000212DE FUN_1800212de (172 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1800212de(void)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this;
  char *pcVar1;
  longlong unaff_RBP;
  __int64 unaff_RSI;
  longlong lVar2;
  longlong *unaff_RDI;
  longlong unaff_R14;
  char *pcStackX_20;
  longlong *in_stack_00000028;
  
  CMapStringToString::CMapStringToString((CMapStringToString *)&stack0x00000030,unaff_RSI);
  if (0 < (int)unaff_RSI) {
    lVar2 = unaff_R14 - (longlong)unaff_RDI;
    do {
      if (*unaff_RDI == 0) break;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&pcStackX_20);
      if ((unaff_R14 == 0) ||
         (pcVar1 = *(char **)(lVar2 + (longlong)unaff_RDI), pcVar1 == (char *)0x0)) {
        pcVar1 = (char *)*unaff_RDI;
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&pcStackX_20,
                 pcVar1);
      pcVar1 = pcStackX_20;
      this = CMapStringToString::operator[]
                       ((CMapStringToString *)&stack0x00000030,(char *)*unaff_RDI);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(this,pcVar1);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&pcStackX_20);
      unaff_RBP = unaff_RBP + 1;
      unaff_RDI = unaff_RDI + 1;
    } while (unaff_RBP < unaff_RSI);
  }
  FUN_1800073c0((longlong)g_pApwnBlockUsage,in_stack_00000028,(CMapStringToString *)&stack0x00000030
               );
  CMapStringToString::~CMapStringToString((CMapStringToString *)&stack0x00000030);
  (**(code **)(*in_stack_00000028 + 0x10))();
  return;
}

/* ---- FUNC 0002138A FUN_18002138a (41 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18002138a(void)

{
  longlong *in_stack_00000028;
  
  (**(code **)(*in_stack_00000028 + 0x10))();
  return;
}

/* ---- FUNC 000213C0 WriteApwnLib (218 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WriteApwnLib(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 *puVar2;
  undefined1 auStackY_458 [32];
  IStream *local_428 [2];
  undefined1 local_418 [1008];
  ulonglong local_28;
  
                    /* 0x213c0  535  WriteApwnLib */
  local_28 = DAT_1800791f8 ^ (ulonglong)auStackY_458;
  puVar2 = operator_new(0x138);
  if (puVar2 == (undefined8 *)0x0) {
    puVar2 = (undefined8 *)0x0;
  }
  else {
    puVar2 = FUN_180018980(puVar2,param_1,param_2,0,param_3,0);
  }
  local_428[0] = (IStream *)0x0;
  iVar1 = (**(code **)*puVar2)(puVar2,&DAT_180057a78,local_428);
  if (iVar1 != 0) {
    FUN_180007de0(local_418,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\bkputil.cpp",0x700);
    LogMessage(local_418,2,1);
  }
  ApwnLibSaveToText(local_428[0]);
  (*local_428[0]->lpVtbl->Release)(local_428[0]);
  return;
}

/* ---- FUNC 000214A0 WriteApwnShellSettingsFromFileToStream (69 bytes) ---- */

undefined8 WriteApwnShellSettingsFromFileToStream(longlong *param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined8 uVar4;
  basic_streambuf<char,std::char_traits<char>_> *pbVar5;
  char *pcVar6;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar7;
  longlong lVar8;
  undefined1 local_res18 [8];
  longlong local_res20;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_158 [12];
  int iStack_14c;
  undefined *local_148 [2];
  undefined **local_138;
  basic_istream<char,std::char_traits<char>_> local_130 [96];
  undefined8 local_d0;
  undefined1 local_c7;
  undefined8 local_c4;
  undefined1 local_bc;
  longlong local_b8;
  basic_ios<char,std::char_traits<char>_> local_98 [128];
  
                    /* 0x214a0  536  WriteApwnShellSettingsFromFileToStream */
  piVar3 = (int *)SEGetSettingValue("ignoreapwnshellsettings",0);
  if ((piVar3 == (int *)0x0) || (*piVar3 != 1)) {
    local_148[0] = &DAT_180054380;
    std::basic_ios<char,std::char_traits<char>_>::basic_ios<char,std::char_traits<char>_>(local_98);
    std::basic_istream<char,std::char_traits<char>_>::basic_istream<char,std::char_traits<char>_>
              ((basic_istream<char,std::char_traits<char>_> *)local_148,
               (basic_streambuf<char,std::char_traits<char>_> *)&local_138,false);
    *(undefined ***)((longlong)local_148 + (longlong)*(int *)(local_148[0] + 4)) =
         std::basic_ifstream<char,std::char_traits<char>_>::vftable;
    *(int *)((longlong)&iStack_14c + (longlong)*(int *)(local_148[0] + 4)) =
         *(int *)(local_148[0] + 4) + -0xb0;
    std::basic_streambuf<char,std::char_traits<char>_>::
    basic_streambuf<char,std::char_traits<char>_>
              ((basic_streambuf<char,std::char_traits<char>_> *)&local_138);
    local_bc = 0;
    local_138 = std::basic_filebuf<char,std::char_traits<char>_>::vftable;
    local_c7 = 0;
    std::basic_streambuf<char,std::char_traits<char>_>::_Init
              ((basic_streambuf<char,std::char_traits<char>_> *)&local_138);
    local_b8 = 0;
    local_c4 = DAT_18007a6c0;
    local_d0 = 0;
    pbVar5 = FUN_18001b290((basic_streambuf<char,std::char_traits<char>_> *)&local_138,param_2,1,
                           0x40);
    if (pbVar5 == (basic_streambuf<char,std::char_traits<char>_> *)0x0) {
      std::basic_ios<char,std::char_traits<char>_>::setstate
                ((basic_ios<char,std::char_traits<char>_> *)
                 ((longlong)local_148 + (longlong)*(int *)(local_148[0] + 4)),2,false);
    }
    else {
      std::basic_ios<char,std::char_traits<char>_>::clear
                ((basic_ios<char,std::char_traits<char>_> *)
                 ((longlong)local_148 + (longlong)*(int *)(local_148[0] + 4)),0,false);
    }
    if (local_b8 != 0) {
      std::basic_istream<char,std::char_traits<char>_>::seekg
                ((basic_istream<char,std::char_traits<char>_> *)local_148,0,2);
      piVar3 = (int *)std::basic_istream<char,std::char_traits<char>_>::tellg
                                ((basic_istream<char,std::char_traits<char>_> *)local_148);
      iVar2 = piVar3[2];
      iVar1 = *piVar3;
      std::basic_istream<char,std::char_traits<char>_>::seekg
                ((basic_istream<char,std::char_traits<char>_> *)local_148,0,0);
      lVar8 = (longlong)(iVar1 + iVar2);
      pcVar6 = operator_new__(lVar8 + 1);
      std::basic_istream<char,std::char_traits<char>_>::read
                ((basic_istream<char,std::char_traits<char>_> *)local_148,pcVar6,lVar8);
      pcVar6[lVar8] = '\0';
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20,
                 pcVar6);
      operator_delete__(pcVar6);
      iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                         &local_res20,'>');
      if (iVar2 != -1) {
        pCVar7 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                 ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Mid
                           ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            &local_res20,(int)local_158,0);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20,
                   pCVar7);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_158);
      }
      (**(code **)(*param_1 + 0x20))
                (param_1,local_res20,*(undefined4 *)(local_res20 + -0x10),local_res18);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20);
    }
    *(undefined ***)((longlong)local_148 + (longlong)*(int *)(local_148[0] + 4)) =
         std::basic_ifstream<char,std::char_traits<char>_>::vftable;
    *(int *)((longlong)&iStack_14c + (longlong)*(int *)(local_148[0] + 4)) =
         *(int *)(local_148[0] + 4) + -0xb0;
    FUN_180018b30((basic_streambuf<char,std::char_traits<char>_> *)&local_138);
    std::basic_istream<char,std::char_traits<char>_>::~basic_istream<char,std::char_traits<char>_>
              (local_130);
    std::basic_ios<char,std::char_traits<char>_>::~basic_ios<char,std::char_traits<char>_>(local_98)
    ;
    uVar4 = 0;
  }
  else {
    uVar4 = 0x80004005;
  }
  return uVar4;
}

/* ---- FUNC 000214E5 FUN_1800214e5 (530 bytes) ---- */

undefined8 FUN_1800214e5(void)

{
  int iVar1;
  undefined8 uVar2;
  int iVar3;
  longlong in_RAX;
  basic_streambuf<char,std::char_traits<char>_> *pbVar4;
  int *piVar5;
  char *pcVar6;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar7;
  char *unaff_RBX;
  longlong lVar8;
  longlong unaff_RBP;
  longlong *unaff_RSI;
  longlong unaff_RDI;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> aCStackX_20 [8];
  longlong lStack0000000000000030;
  undefined **in_stack_00000040;
  
  lStack0000000000000030 = in_RAX;
  std::basic_ios<char,std::char_traits<char>_>::basic_ios<char,std::char_traits<char>_>
            ((basic_ios<char,std::char_traits<char>_> *)(unaff_RBP + -0x20));
  std::basic_istream<char,std::char_traits<char>_>::basic_istream<char,std::char_traits<char>_>
            ((basic_istream<char,std::char_traits<char>_> *)&stack0x00000030,
             (basic_streambuf<char,std::char_traits<char>_> *)&stack0x00000040,false);
  *(undefined ***)((longlong)&stack0x00000030 + (longlong)*(int *)(lStack0000000000000030 + 4)) =
       std::basic_ifstream<char,std::char_traits<char>_>::vftable;
  *(int *)(&stack0x0000002c + *(int *)(lStack0000000000000030 + 4)) =
       *(int *)(lStack0000000000000030 + 4) + -0xb0;
  std::basic_streambuf<char,std::char_traits<char>_>::basic_streambuf<char,std::char_traits<char>_>
            ((basic_streambuf<char,std::char_traits<char>_> *)&stack0x00000040);
  *(char *)(unaff_RBP + -0x44) = (char)unaff_RDI;
  in_stack_00000040 = std::basic_filebuf<char,std::char_traits<char>_>::vftable;
  *(char *)(unaff_RBP + -0x4f) = (char)unaff_RDI;
  std::basic_streambuf<char,std::char_traits<char>_>::_Init
            ((basic_streambuf<char,std::char_traits<char>_> *)&stack0x00000040);
  uVar2 = DAT_18007a6c0;
  *(longlong *)(unaff_RBP + -0x40) = unaff_RDI;
  *(undefined8 *)(unaff_RBP + -0x4c) = uVar2;
  *(longlong *)(unaff_RBP + -0x58) = unaff_RDI;
  pbVar4 = FUN_18001b290((basic_streambuf<char,std::char_traits<char>_> *)&stack0x00000040,unaff_RBX
                         ,1,0x40);
  if (pbVar4 == (basic_streambuf<char,std::char_traits<char>_> *)0x0) {
    std::basic_ios<char,std::char_traits<char>_>::setstate
              ((basic_ios<char,std::char_traits<char>_> *)
               ((longlong)&stack0x00000030 + (longlong)*(int *)(lStack0000000000000030 + 4)),2,false
              );
  }
  else {
    std::basic_ios<char,std::char_traits<char>_>::clear
              ((basic_ios<char,std::char_traits<char>_> *)
               ((longlong)&stack0x00000030 + (longlong)*(int *)(lStack0000000000000030 + 4)),0,false
              );
  }
  if (*(longlong *)(unaff_RBP + -0x40) != unaff_RDI) {
    std::basic_istream<char,std::char_traits<char>_>::seekg
              ((basic_istream<char,std::char_traits<char>_> *)&stack0x00000030,0,2);
    piVar5 = (int *)std::basic_istream<char,std::char_traits<char>_>::tellg
                              ((basic_istream<char,std::char_traits<char>_> *)&stack0x00000030);
    iVar3 = piVar5[2];
    iVar1 = *piVar5;
    std::basic_istream<char,std::char_traits<char>_>::seekg
              ((basic_istream<char,std::char_traits<char>_> *)&stack0x00000030,0,0);
    lVar8 = (longlong)(iVar1 + iVar3);
    pcVar6 = operator_new__(lVar8 + 1);
    std::basic_istream<char,std::char_traits<char>_>::read
              ((basic_istream<char,std::char_traits<char>_> *)&stack0x00000030,pcVar6,lVar8);
    pcVar6[lVar8] = '\0';
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(unaff_RBP + 0x98),
               pcVar6);
    operator_delete__(pcVar6);
    iVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                       (unaff_RBP + 0x98),'>');
    if (iVar3 != -1) {
      pCVar7 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Mid
                         ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                          (unaff_RBP + 0x98),(int)aCStackX_20,0);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(unaff_RBP + 0x98)
                 ,pCVar7);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(aCStackX_20);
    }
    (**(code **)(*unaff_RSI + 0x20))();
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(unaff_RBP + 0x98));
  }
  *(undefined ***)((longlong)&stack0x00000030 + (longlong)*(int *)(lStack0000000000000030 + 4)) =
       std::basic_ifstream<char,std::char_traits<char>_>::vftable;
  *(int *)(&stack0x0000002c + *(int *)(lStack0000000000000030 + 4)) =
       *(int *)(lStack0000000000000030 + 4) + -0xb0;
  FUN_180018b30((basic_streambuf<char,std::char_traits<char>_> *)&stack0x00000040);
  std::basic_istream<char,std::char_traits<char>_>::~basic_istream<char,std::char_traits<char>_>
            ((basic_istream<char,std::char_traits<char>_> *)&stack0x00000048);
  std::basic_ios<char,std::char_traits<char>_>::~basic_ios<char,std::char_traits<char>_>
            ((basic_ios<char,std::char_traits<char>_> *)(unaff_RBP + -0x20));
  return 0;
}

/* ---- FUNC 000216F7 FUN_1800216f7 (19 bytes) ---- */

void FUN_1800216f7(void)

{
  return;
}

/* ---- FUNC 00021710 WriteCArestoreMap (363 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WriteCArestoreMap(void *param_1,void *param_2,void *param_3,char *param_4)

{
  char cVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  uint uVar6;
  undefined8 ***pppuVar7;
  longlong *plVar8;
  undefined8 ***pppuVar9;
  longlong *plVar10;
  ulonglong uVar11;
  char *pcVar12;
  void *pvVar13;
  undefined8 ****ppppuVar14;
  size_t sVar15;
  ulonglong uVar16;
  undefined8 *puVar17;
  ulonglong uVar18;
  size_t sVar19;
  char *pcVar20;
  ulonglong uVar21;
  bool bVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  undefined4 uVar25;
  undefined4 uVar26;
  undefined1 auStack_148 [32];
  void *local_128;
  longlong local_120;
  void *local_118;
  longlong local_110;
  undefined8 *local_108;
  undefined8 uStack_100;
  longlong local_f8;
  undefined8 local_e8;
  undefined8 uStack_e0;
  ulonglong local_d8;
  ulonglong uStack_d0;
  longlong *local_c8;
  longlong local_c0;
  undefined8 ***local_b0;
  undefined8 uStack_a8;
  ulonglong local_a0;
  ulonglong local_98;
  undefined8 ***local_90;
  undefined8 uStack_88;
  ulonglong local_80;
  ulonglong local_78;
  undefined8 ***local_70;
  undefined8 uStack_68;
  ulonglong local_60;
  ulonglong local_58;
  ulonglong local_50;
  
                    /* 0x21710  537  WriteCArestoreMap */
  local_50 = DAT_1800791f8 ^ (ulonglong)auStack_148;
  pppuVar9 = (undefined8 ***)0x0;
  local_120 = 0;
  pcVar20 = param_4;
  local_128 = operator_new(0x50);
  *(void **)local_128 = local_128;
  *(void **)((longlong)local_128 + 8) = local_128;
  *(void **)((longlong)local_128 + 0x10) = local_128;
  *(undefined2 *)((longlong)local_128 + 0x18) = 0x101;
  local_110 = 0;
  local_118 = operator_new(0x58);
  local_a0 = 0;
  sVar15 = 0xffffffffffffffff;
  local_98 = 0;
  local_b0 = (undefined8 ****)0x0;
  uStack_a8 = 0;
  *(void **)local_118 = local_118;
  sVar19 = 0xffffffffffffffff;
  *(void **)((longlong)local_118 + 8) = local_118;
  *(void **)((longlong)local_118 + 0x10) = local_118;
  *(undefined2 *)((longlong)local_118 + 0x18) = 0x101;
  do {
    sVar19 = sVar19 + 1;
  } while (*(char *)((longlong)param_3 + sVar19) != '\0');
  FUN_18000b5f0(&local_b0,param_3,sVar19);
  local_80 = 0;
  local_90 = (undefined8 ****)0x0;
  uStack_88 = 0;
  local_78 = 0;
  sVar19 = 0xffffffffffffffff;
  do {
    sVar19 = sVar19 + 1;
  } while (*(char *)((longlong)param_2 + sVar19) != '\0');
  FUN_18000b5f0(&local_90,param_2,sVar19);
  local_60 = 0;
  local_70 = (undefined8 ****)0x0;
  uStack_68 = 0;
  local_58 = 0;
  do {
    sVar15 = sVar15 + 1;
  } while (*(char *)((longlong)param_1 + sVar15) != '\0');
  FUN_18000b5f0(&local_70,param_1,sVar15);
  pcVar12 = param_4;
  do {
    cVar1 = *pcVar12;
    pcVar12[(longlong)&local_108 - (longlong)param_4] = cVar1;
    pcVar12 = pcVar12 + 1;
  } while (cVar1 != '\0');
  pcVar12 = param_4 + 0xc;
  lVar2 = 4 - (longlong)pcVar12;
  do {
    cVar1 = *pcVar12;
    pcVar12[(longlong)&uStack_100 + lVar2] = cVar1;
    uVar5 = local_a0;
    pcVar12 = pcVar12 + 1;
  } while (cVar1 != '\0');
  ppppuVar14 = &local_b0;
  if (0xf < local_98) {
    ppppuVar14 = (undefined8 ****)local_b0;
  }
  local_e8 = (undefined8 ***)0x0;
  uStack_e0 = (undefined8 ***)0x0;
  if (0x7fffffffffffffff < local_a0) {
                    /* WARNING: Subroutine does not return */
    FUN_18000ace0();
  }
  uVar21 = 0x8000000000000000;
  if (local_a0 < 0x10) {
    local_d8 = local_a0;
    uStack_d0 = 0xf;
    uVar23 = *(undefined4 *)ppppuVar14;
    uVar24 = *(undefined4 *)((longlong)ppppuVar14 + 4);
    uVar25 = *(undefined4 *)(ppppuVar14 + 1);
    uVar26 = *(undefined4 *)((longlong)ppppuVar14 + 0xc);
  }
  else {
    uVar16 = local_a0 | 0xf;
    if (uVar16 < 0x8000000000000000) {
      if (uVar16 < 0x16) {
        uVar16 = 0x16;
      }
      uVar18 = uVar16 + 1;
      if (uVar18 < 0x1000) {
        pppuVar7 = pppuVar9;
        if (uVar18 != 0) {
          pppuVar7 = operator_new(uVar18);
        }
      }
      else {
        pppuVar7 = (undefined8 ***)FUN_180007f10(uVar18);
      }
    }
    else {
      uVar16 = 0x7fffffffffffffff;
      pppuVar7 = (undefined8 ***)FUN_180007f10(0x8000000000000000);
    }
    local_d8 = uVar5;
    local_e8 = pppuVar7;
    uStack_d0 = uVar16;
    memcpy(pppuVar7,ppppuVar14,uVar5 + 1);
    uVar23 = (undefined4)local_e8;
    uVar24 = local_e8._4_4_;
    uVar25 = (undefined4)uStack_e0;
    uVar26 = uStack_e0._4_4_;
  }
  pvVar13 = local_118;
  plVar8 = operator_new(0x58);
  uVar5 = uStack_100;
  uStack_100 = uStack_100 & 0xffffffff00000000;
  *(undefined4 *)(plVar8 + 4) = uVar23;
  *(undefined4 *)((longlong)plVar8 + 0x24) = uVar24;
  *(undefined4 *)(plVar8 + 5) = uVar25;
  *(undefined4 *)((longlong)plVar8 + 0x2c) = uVar26;
  plVar8[6] = local_d8;
  plVar8[7] = uStack_d0;
  plVar8[8] = (longlong)local_108;
  plVar8[9] = uVar5;
  plVar8[10] = local_f8;
  *plVar8 = (longlong)pvVar13;
  plVar8[1] = (longlong)pvVar13;
  plVar8[2] = (longlong)pvVar13;
  *(undefined2 *)(plVar8 + 3) = 0;
  puVar17 = *(undefined8 **)((longlong)local_118 + 8);
  cVar1 = *(char *)((longlong)puVar17 + 0x19);
  local_108 = puVar17;
  while (cVar1 == '\0') {
    local_108 = puVar17;
    uVar6 = FUN_180007ea0(plVar8 + 4,puVar17 + 4);
    if ((char)uVar6 == '\0') {
      puVar17 = (undefined8 *)puVar17[2];
      uStack_100 = (ulonglong)uStack_100._4_4_ << 0x20;
    }
    else {
      puVar17 = (undefined8 *)*puVar17;
      uStack_100 = CONCAT44(uStack_100._4_4_,1);
    }
    cVar1 = *(char *)((longlong)puVar17 + 0x19);
  }
  if (local_110 == 0x2e8ba2e8ba2e8ba) {
                    /* WARNING: Subroutine does not return */
    FUN_18000ac90();
  }
  FUN_18000a930((longlong *)&local_118,(longlong *)&local_108,plVar8);
  uVar5 = local_80;
  pppuVar7 = local_90;
  ppppuVar14 = &local_90;
  if (0xf < local_78) {
    ppppuVar14 = (undefined8 ****)local_90;
  }
  local_e8 = (undefined8 ***)0x0;
  uStack_e0 = (undefined8 ***)0x0;
  if (0x7fffffffffffffff < local_80) {
                    /* WARNING: Subroutine does not return */
    FUN_18000ace0();
  }
  if (local_80 < 0x10) {
    local_d8 = local_80;
    uStack_d0 = 0xf;
    local_e8 = *ppppuVar14;
    uStack_e0 = ppppuVar14[1];
  }
  else {
    uVar16 = local_80 | 0xf;
    if (uVar16 < 0x8000000000000000) {
      if (uVar16 < 0x16) {
        uVar16 = 0x16;
      }
      uVar18 = uVar16 + 1;
      if (uVar18 < 0x1000) {
        if (uVar18 != 0) {
          pppuVar9 = operator_new(uVar18);
        }
      }
      else {
        pppuVar9 = (undefined8 ***)FUN_180007f10(uVar18);
      }
    }
    else {
      uVar16 = 0x7fffffffffffffff;
      pppuVar9 = (undefined8 ***)FUN_180007f10(0x8000000000000000);
    }
    plVar8 = (longlong *)(uVar5 + 1);
    local_d8 = uVar5;
    local_e8 = pppuVar9;
    uStack_d0 = uVar16;
    memcpy(pppuVar9,ppppuVar14,(size_t)plVar8);
  }
  FUN_1800186c0((longlong *)&local_c8,(longlong *)&local_118,plVar8,pcVar20);
  pvVar13 = local_128;
  plVar8 = operator_new(0x50);
  plVar8[6] = 0;
  plVar8[7] = 0;
  plVar8[4] = (longlong)local_e8;
  plVar8[5] = (longlong)uStack_e0;
  uVar5 = _UNK_180053828;
  uVar4 = _DAT_180053820;
  plVar8[6] = local_d8;
  plVar8[7] = uStack_d0;
  local_e8 = (undefined8 ***)((ulonglong)local_e8 & 0xffffffffffffff00);
  local_d8 = uVar4;
  uStack_d0 = uVar5;
  plVar8[8] = 0;
  plVar8[9] = 0;
  plVar10 = operator_new(0x58);
  uStack_100 = uStack_100 & 0xffffffff00000000;
  *plVar10 = (longlong)plVar10;
  plVar10[1] = (longlong)plVar10;
  plVar10[2] = (longlong)plVar10;
  *(undefined2 *)(plVar10 + 3) = 0x101;
  plVar8[8] = (longlong)local_c8;
  lVar2 = plVar8[9];
  plVar8[9] = local_c0;
  *plVar8 = (longlong)pvVar13;
  plVar8[1] = (longlong)pvVar13;
  plVar8[2] = (longlong)pvVar13;
  *(undefined2 *)(plVar8 + 3) = 0;
  puVar17 = *(undefined8 **)((longlong)local_128 + 8);
  cVar1 = *(char *)((longlong)puVar17 + 0x19);
  local_c0 = lVar2;
  local_108 = puVar17;
  local_c8 = plVar10;
  while (cVar1 == '\0') {
    local_108 = puVar17;
    uVar6 = FUN_180007ea0(plVar8 + 4,puVar17 + 4);
    if ((char)uVar6 == '\0') {
      puVar17 = (undefined8 *)puVar17[2];
      uStack_100 = (ulonglong)uStack_100._4_4_ << 0x20;
    }
    else {
      puVar17 = (undefined8 *)*puVar17;
      uStack_100 = CONCAT44(uStack_100._4_4_,1);
    }
    cVar1 = *(char *)((longlong)puVar17 + 0x19);
  }
  if (local_120 == 0x333333333333333) {
                    /* WARNING: Subroutine does not return */
    FUN_18000ac90();
  }
  FUN_18000a930((longlong *)&local_128,(longlong *)&local_108,plVar8);
  FUN_180017cc0(&local_c8,&local_c8,(longlong *)local_c8[1]);
  operator_delete(local_c8);
  if (0xf < uStack_d0) {
    pvVar13 = local_e8;
    if ((0xfff < uStack_d0 + 1) &&
       (pvVar13 = *(void **)((longlong)local_e8 + -8),
       0x1f < (ulonglong)((longlong)local_e8 + (-8 - (longlong)pvVar13)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar13);
  }
  uVar16 = local_58;
  uVar5 = local_60;
  pppuVar9 = local_70;
  ppppuVar14 = &local_70;
  if (0xf < local_58) {
    ppppuVar14 = (undefined8 ****)local_70;
  }
  local_e8 = (undefined8 ***)0x0;
  uStack_e0 = (undefined8 ***)0x0;
  if (0x7fffffffffffffff < local_60) {
                    /* WARNING: Subroutine does not return */
    FUN_18000ace0();
  }
  if (local_60 < 0x10) {
    local_d8 = local_60;
    uStack_d0 = 0xf;
    local_e8 = *ppppuVar14;
    uStack_e0 = ppppuVar14[1];
  }
  else {
    uVar11 = local_60 | 0xf;
    uVar18 = 0x7fffffffffffffff;
    if (uVar11 < 0x8000000000000000) {
      if (uVar11 < 0x16) {
        uVar11 = 0x16;
      }
      uVar21 = uVar11 + 1;
      uVar18 = uVar11;
      if (0xfff < uVar21) goto LAB_180021c89;
      if (uVar21 == 0) {
        local_e8 = (undefined8 ***)0x0;
      }
      else {
        local_e8 = operator_new(uVar21);
      }
    }
    else {
LAB_180021c89:
      local_e8 = (undefined8 ***)FUN_180007f10(uVar21);
      uVar11 = uVar18;
    }
    local_d8 = uVar5;
    uStack_d0 = uVar11;
    memcpy(local_e8,ppppuVar14,uVar5 + 1);
  }
  local_c0 = 0;
  local_c8 = operator_new(0x50);
  *local_c8 = (longlong)local_c8;
  local_c8[1] = (longlong)local_c8;
  local_c8[2] = (longlong)local_c8;
  *(undefined2 *)(local_c8 + 3) = 0x101;
  plVar8 = FUN_1800178a0(&local_c8,*(undefined8 **)((longlong)local_128 + 8),(longlong)local_c8,
                         pcVar20);
  local_c8[1] = (longlong)plVar8;
  local_c0 = local_120;
  plVar8 = (longlong *)local_c8[1];
  if (*(char *)((longlong)plVar8 + 0x19) == '\0') {
    cVar1 = *(char *)(*plVar8 + 0x19);
    plVar10 = (longlong *)*plVar8;
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*plVar10 + 0x19);
      plVar8 = plVar10;
      plVar10 = (longlong *)*plVar10;
    }
    *local_c8 = (longlong)plVar8;
    lVar2 = *(longlong *)(local_c8[1] + 0x10);
    cVar1 = *(char *)(lVar2 + 0x19);
    lVar3 = local_c8[1];
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*(longlong *)(lVar2 + 0x10) + 0x19);
      lVar3 = lVar2;
      lVar2 = *(longlong *)(lVar2 + 0x10);
    }
    local_c8[2] = lVar3;
  }
  else {
    *local_c8 = (longlong)local_c8;
    local_c8[2] = (longlong)local_c8;
  }
  lVar3 = DAT_18007a278;
  plVar8 = operator_new(0x50);
  plVar8[6] = 0;
  plVar8[7] = 0;
  plVar8[4] = (longlong)local_e8;
  plVar8[5] = (longlong)uStack_e0;
  uVar5 = _UNK_180053828;
  uVar4 = _DAT_180053820;
  plVar8[6] = local_d8;
  plVar8[7] = uStack_d0;
  local_e8 = (undefined8 ***)((ulonglong)local_e8 & 0xffffffffffffff00);
  local_d8 = uVar4;
  uStack_d0 = uVar5;
  plVar8[8] = 0;
  plVar8[9] = 0;
  plVar10 = operator_new(0x50);
  *plVar10 = (longlong)plVar10;
  plVar10[1] = (longlong)plVar10;
  plVar10[2] = (longlong)plVar10;
  *(undefined2 *)(plVar10 + 3) = 0x101;
  plVar8[8] = (longlong)local_c8;
  lVar2 = plVar8[9];
  plVar8[9] = local_c0;
  *plVar8 = lVar3;
  plVar8[1] = lVar3;
  plVar8[2] = lVar3;
  *(undefined2 *)(plVar8 + 3) = 0;
  puVar17 = *(undefined8 **)(DAT_18007a278 + 8);
  cVar1 = *(char *)((longlong)puVar17 + 0x19);
  uStack_100._0_4_ = 0;
  local_c0 = lVar2;
  local_108 = puVar17;
  local_c8 = plVar10;
  while (cVar1 == '\0') {
    local_108 = puVar17;
    uVar6 = FUN_180007ea0(plVar8 + 4,puVar17 + 4);
    bVar22 = (char)uVar6 == '\0';
    if (bVar22) {
      puVar17 = (undefined8 *)puVar17[2];
    }
    else {
      puVar17 = (undefined8 *)*puVar17;
    }
    uStack_100._0_4_ = (uint)!bVar22;
    cVar1 = *(char *)((longlong)puVar17 + 0x19);
  }
  if (DAT_18007a280 == 0x333333333333333) {
                    /* WARNING: Subroutine does not return */
    FUN_18000ac90();
  }
  FUN_18000a930(&DAT_18007a278,(longlong *)&local_108,plVar8);
  FUN_180017e00(&local_c8,&local_c8,(longlong *)local_c8[1]);
  operator_delete(local_c8);
  if (0xf < uStack_d0) {
    pvVar13 = local_e8;
    if ((0xfff < uStack_d0 + 1) &&
       (pvVar13 = *(void **)((longlong)local_e8 + -8),
       0x1f < (ulonglong)((longlong)local_e8 + (-8 - (longlong)pvVar13)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar13);
  }
  if (0xf < uVar16) {
    ppppuVar14 = (undefined8 ****)pppuVar9;
    if ((0xfff < uVar16 + 1) &&
       (ppppuVar14 = (undefined8 ****)pppuVar9[-1],
       0x1f < (ulonglong)((longlong)pppuVar9 + (-8 - (longlong)ppppuVar14)))) goto LAB_180021f98;
    operator_delete(ppppuVar14);
  }
  if (0xf < local_78) {
    ppppuVar14 = (undefined8 ****)pppuVar7;
    if ((0xfff < local_78 + 1) &&
       (ppppuVar14 = (undefined8 ****)pppuVar7[-1],
       0x1f < (ulonglong)((longlong)pppuVar7 + (-8 - (longlong)ppppuVar14)))) goto LAB_180021f98;
    operator_delete(ppppuVar14);
  }
  if (0xf < local_98) {
    ppppuVar14 = (undefined8 ****)local_b0;
    if ((0xfff < local_98 + 1) &&
       (ppppuVar14 = (undefined8 ****)local_b0[-1],
       0x1f < (ulonglong)((longlong)local_b0 + (-8 - (longlong)ppppuVar14)))) {
LAB_180021f98:
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(ppppuVar14);
  }
  FUN_180017cc0(&local_118,&local_118,*(longlong **)((longlong)local_118 + 8));
  operator_delete(local_118);
  FUN_180017e00(&local_128,&local_128,*(longlong **)((longlong)local_128 + 8));
  operator_delete(local_128);
  return;
}

/* ---- FUNC 0002187B FUN_18002187b (261 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_18002187b(void)

{
  char cVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  longlong *plVar5;
  longlong lVar6;
  longlong *plVar7;
  uint uVar8;
  longlong *plVar9;
  void *pvVar10;
  void *pvVar11;
  undefined8 *puVar12;
  undefined8 *puVar13;
  undefined8 *puVar14;
  longlong unaff_RBP;
  ulonglong unaff_RSI;
  ulonglong unaff_RDI;
  undefined8 in_R9;
  char cVar15;
  undefined4 uVar16;
  void *unaff_R13;
  undefined4 *unaff_R14;
  ulonglong uVar17;
  bool bVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  void *pvStackX_20;
  longlong in_stack_00000028;
  void *in_stack_00000030;
  longlong in_stack_00000038;
  undefined8 *in_stack_00000040;
  uint uStack0000000000000048;
  undefined4 uStack000000000000004c;
  longlong in_stack_00000050;
  undefined4 uStack0000000000000060;
  undefined4 uStack0000000000000064;
  undefined4 uStack0000000000000068;
  undefined4 uStack000000000000006c;
  ulonglong uStack0000000000000078;
  
  uVar17 = 0x8000000000000000;
  if (unaff_RSI < 0x10) {
    uStack0000000000000078 = 0xf;
    uVar19 = *unaff_R14;
    uVar20 = unaff_R14[1];
    uVar21 = unaff_R14[2];
    uVar22 = unaff_R14[3];
  }
  else {
    uStack0000000000000078 = unaff_RSI | 0xf;
    if (unaff_RDI < uStack0000000000000078) {
      pvVar11 = (void *)FUN_180007f10(0x8000000000000000);
      uStack0000000000000078 = unaff_RDI;
    }
    else {
      if (uStack0000000000000078 < 0x16) {
        uStack0000000000000078 = 0x16;
      }
      uVar2 = uStack0000000000000078 + 1;
      if (uVar2 < 0x1000) {
        pvVar11 = unaff_R13;
        if (uVar2 != 0) {
          pvVar11 = operator_new(uVar2);
        }
      }
      else {
        pvVar11 = (void *)FUN_180007f10(uVar2);
      }
    }
    _uStack0000000000000060 = pvVar11;
    memcpy(pvVar11,unaff_R14,unaff_RSI + 1);
    uVar19 = uStack0000000000000060;
    uVar20 = uStack0000000000000064;
    uVar21 = uStack0000000000000068;
    uVar22 = uStack000000000000006c;
  }
  pvVar11 = in_stack_00000030;
  plVar9 = operator_new(0x58);
  uVar16 = SUB84(unaff_R13,0);
  *(undefined4 *)(plVar9 + 4) = uVar19;
  *(undefined4 *)((longlong)plVar9 + 0x24) = uVar20;
  *(undefined4 *)(plVar9 + 5) = uVar21;
  *(undefined4 *)((longlong)plVar9 + 0x2c) = uVar22;
  plVar9[6] = unaff_RSI;
  plVar9[7] = uStack0000000000000078;
  plVar9[8] = (longlong)in_stack_00000040;
  plVar9[9] = _uStack0000000000000048;
  plVar9[10] = in_stack_00000050;
  *plVar9 = (longlong)pvVar11;
  plVar9[1] = (longlong)pvVar11;
  plVar9[2] = (longlong)pvVar11;
  *(short *)(plVar9 + 3) = (short)unaff_R13;
  puVar12 = *(undefined8 **)((longlong)in_stack_00000030 + 8);
  cVar15 = (char)unaff_R13;
  cVar1 = *(char *)((longlong)puVar12 + 0x19);
  uStack0000000000000048 = uVar16;
  in_stack_00000040 = puVar12;
  while (cVar1 == cVar15) {
    in_stack_00000040 = puVar12;
    uVar8 = FUN_180007ea0(plVar9 + 4,puVar12 + 4);
    if ((char)uVar8 == '\0') {
      puVar12 = (undefined8 *)puVar12[2];
      uStack0000000000000048 = uVar16;
    }
    else {
      puVar12 = (undefined8 *)*puVar12;
      uStack0000000000000048 = 1;
    }
    cVar1 = *(char *)((longlong)puVar12 + 0x19);
  }
  if (in_stack_00000038 == 0x2e8ba2e8ba2e8ba) {
                    /* WARNING: Subroutine does not return */
    FUN_18000ac90();
  }
  FUN_18000a930((longlong *)&stack0x00000030,(longlong *)&stack0x00000040,plVar9);
  puVar12 = *(undefined8 **)(unaff_RBP + -0x48);
  uVar2 = *(ulonglong *)(unaff_RBP + -0x38);
  puVar13 = (undefined8 *)(unaff_RBP + -0x48);
  if (0xf < *(ulonglong *)(unaff_RBP + -0x30)) {
    puVar13 = puVar12;
  }
  _uStack0000000000000060 = (void *)0x0;
  _uStack0000000000000068 = 0;
  if (unaff_RDI < uVar2) {
                    /* WARNING: Subroutine does not return */
    FUN_18000ace0();
  }
  if (uVar2 < 0x10) {
    uStack0000000000000078 = 0xf;
    _uStack0000000000000060 = (void *)*puVar13;
    _uStack0000000000000068 = puVar13[1];
  }
  else {
    uStack0000000000000078 = uVar2 | 0xf;
    if (unaff_RDI < uStack0000000000000078) {
      pvVar11 = (void *)FUN_180007f10(0x8000000000000000);
      uStack0000000000000078 = unaff_RDI;
    }
    else {
      if (uStack0000000000000078 < 0x16) {
        uStack0000000000000078 = 0x16;
      }
      uVar4 = uStack0000000000000078 + 1;
      if (uVar4 < 0x1000) {
        pvVar11 = unaff_R13;
        if (uVar4 != 0) {
          pvVar11 = operator_new(uVar4);
        }
      }
      else {
        pvVar11 = (void *)FUN_180007f10(uVar4);
      }
    }
    plVar9 = (longlong *)(uVar2 + 1);
    _uStack0000000000000060 = pvVar11;
    memcpy(pvVar11,puVar13,(size_t)plVar9);
  }
  FUN_1800186c0((longlong *)(unaff_RBP + -0x80),(longlong *)&stack0x00000030,plVar9,in_R9);
  pvVar11 = pvStackX_20;
  plVar9 = operator_new(0x50);
  plVar9[6] = (longlong)unaff_R13;
  plVar9[7] = (longlong)unaff_R13;
  plVar9[4] = (longlong)_uStack0000000000000060;
  plVar9[5] = _uStack0000000000000068;
  uVar4 = _UNK_180053828;
  plVar9[6] = uVar2;
  plVar9[7] = uStack0000000000000078;
  _uStack0000000000000060 = (void *)CONCAT71(stack0x00000061,cVar15);
  plVar9[8] = (longlong)unaff_R13;
  plVar9[9] = (longlong)unaff_R13;
  pvVar10 = operator_new(0x58);
  *(void **)pvVar10 = pvVar10;
  *(void **)((longlong)pvVar10 + 8) = pvVar10;
  *(void **)((longlong)pvVar10 + 0x10) = pvVar10;
  *(undefined2 *)((longlong)pvVar10 + 0x18) = 0x101;
  plVar9[8] = *(longlong *)(unaff_RBP + -0x80);
  *(void **)(unaff_RBP + -0x80) = pvVar10;
  lVar3 = plVar9[9];
  plVar9[9] = *(longlong *)(unaff_RBP + -0x78);
  *(longlong *)(unaff_RBP + -0x78) = lVar3;
  *plVar9 = (longlong)pvVar11;
  plVar9[1] = (longlong)pvVar11;
  plVar9[2] = (longlong)pvVar11;
  *(short *)(plVar9 + 3) = (short)unaff_R13;
  puVar13 = *(undefined8 **)((longlong)pvStackX_20 + 8);
  cVar1 = *(char *)((longlong)puVar13 + 0x19);
  uStack0000000000000048 = uVar16;
  in_stack_00000040 = puVar13;
  while (cVar1 == cVar15) {
    in_stack_00000040 = puVar13;
    uVar8 = FUN_180007ea0(plVar9 + 4,puVar13 + 4);
    if ((char)uVar8 == '\0') {
      puVar13 = (undefined8 *)puVar13[2];
      uStack0000000000000048 = uVar16;
    }
    else {
      puVar13 = (undefined8 *)*puVar13;
      uStack0000000000000048 = 1;
    }
    cVar1 = *(char *)((longlong)puVar13 + 0x19);
  }
  if (in_stack_00000028 == 0x333333333333333) {
                    /* WARNING: Subroutine does not return */
    FUN_18000ac90();
  }
  FUN_18000a930((longlong *)&pvStackX_20,(longlong *)&stack0x00000040,plVar9);
  FUN_180017cc0(unaff_RBP + -0x80,unaff_RBP + -0x80,
                *(longlong **)(*(longlong *)(unaff_RBP + -0x80) + 8));
  operator_delete(*(void **)(unaff_RBP + -0x80));
  if (0xf < uVar4) {
    pvVar11 = _uStack0000000000000060;
    if ((0xfff < uVar4 + 1) &&
       (pvVar11 = *(void **)((longlong)_uStack0000000000000060 + -8),
       0x1f < (ulonglong)((longlong)_uStack0000000000000060 + (-8 - (longlong)pvVar11)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar11);
  }
  uVar2 = *(ulonglong *)(unaff_RBP + -0x10);
  puVar13 = *(undefined8 **)(unaff_RBP + -0x28);
  uVar4 = *(ulonglong *)(unaff_RBP + -0x18);
  puVar14 = (undefined8 *)(unaff_RBP + -0x28);
  if (0xf < uVar2) {
    puVar14 = puVar13;
  }
  _uStack0000000000000060 = (void *)0x0;
  _uStack0000000000000068 = 0;
  if (unaff_RDI < uVar4) {
                    /* WARNING: Subroutine does not return */
    FUN_18000ace0();
  }
  if (uVar4 < 0x10) {
    uStack0000000000000078 = 0xf;
    _uStack0000000000000060 = (void *)*puVar14;
    _uStack0000000000000068 = puVar14[1];
  }
  else {
    uStack0000000000000078 = uVar4 | 0xf;
    if (unaff_RDI < uStack0000000000000078) {
LAB_180021c89:
      _uStack0000000000000060 = (void *)FUN_180007f10(uVar17);
      uStack0000000000000078 = unaff_RDI;
    }
    else {
      if (uStack0000000000000078 < 0x16) {
        uStack0000000000000078 = 0x16;
      }
      uVar17 = uStack0000000000000078 + 1;
      unaff_RDI = uStack0000000000000078;
      if (0xfff < uVar17) goto LAB_180021c89;
      if (uVar17 == 0) {
        _uStack0000000000000060 = (void *)0x0;
      }
      else {
        _uStack0000000000000060 = operator_new(uVar17);
      }
    }
    memcpy(_uStack0000000000000060,puVar14,uVar4 + 1);
  }
  *(undefined8 *)(unaff_RBP + -0x78) = 0;
  pvVar11 = operator_new(0x50);
  *(void **)pvVar11 = pvVar11;
  *(void **)((longlong)pvVar11 + 8) = pvVar11;
  *(void **)((longlong)pvVar11 + 0x10) = pvVar11;
  *(undefined2 *)((longlong)pvVar11 + 0x18) = 0x101;
  *(void **)(unaff_RBP + -0x80) = pvVar11;
  plVar9 = FUN_1800178a0((undefined8 *)(unaff_RBP + -0x80),
                         *(undefined8 **)((longlong)pvStackX_20 + 8),(longlong)pvVar11,in_R9);
  *(longlong **)(*(longlong *)(unaff_RBP + -0x80) + 8) = plVar9;
  plVar9 = *(longlong **)(unaff_RBP + -0x80);
  *(longlong *)(unaff_RBP + -0x78) = in_stack_00000028;
  plVar5 = (longlong *)plVar9[1];
  if (*(char *)((longlong)plVar5 + 0x19) == '\0') {
    cVar1 = *(char *)(*plVar5 + 0x19);
    plVar7 = (longlong *)*plVar5;
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*plVar7 + 0x19);
      plVar5 = plVar7;
      plVar7 = (longlong *)*plVar7;
    }
    *plVar9 = (longlong)plVar5;
    lVar3 = *(longlong *)(*(longlong *)(unaff_RBP + -0x80) + 8);
    lVar6 = *(longlong *)(lVar3 + 0x10);
    cVar1 = *(char *)(lVar6 + 0x19);
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*(longlong *)(lVar6 + 0x10) + 0x19);
      lVar3 = lVar6;
      lVar6 = *(longlong *)(lVar6 + 0x10);
    }
    *(longlong *)(*(longlong *)(unaff_RBP + -0x80) + 0x10) = lVar3;
  }
  else {
    *plVar9 = (longlong)plVar9;
    *(longlong *)(*(longlong *)(unaff_RBP + -0x80) + 0x10) = *(longlong *)(unaff_RBP + -0x80);
  }
  lVar6 = DAT_18007a278;
  plVar9 = operator_new(0x50);
  plVar9[6] = 0;
  plVar9[7] = 0;
  plVar9[4] = (longlong)_uStack0000000000000060;
  plVar9[5] = _uStack0000000000000068;
  uVar17 = _UNK_180053828;
  plVar9[6] = uVar4;
  plVar9[7] = uStack0000000000000078;
  _uStack0000000000000060 = (void *)((ulonglong)_uStack0000000000000060 & 0xffffffffffffff00);
  plVar9[8] = 0;
  plVar9[9] = 0;
  pvVar11 = operator_new(0x50);
  uStack0000000000000048 = 0;
  *(void **)pvVar11 = pvVar11;
  *(void **)((longlong)pvVar11 + 8) = pvVar11;
  *(void **)((longlong)pvVar11 + 0x10) = pvVar11;
  *(undefined2 *)((longlong)pvVar11 + 0x18) = 0x101;
  plVar9[8] = *(longlong *)(unaff_RBP + -0x80);
  *(void **)(unaff_RBP + -0x80) = pvVar11;
  lVar3 = plVar9[9];
  plVar9[9] = *(longlong *)(unaff_RBP + -0x78);
  *(longlong *)(unaff_RBP + -0x78) = lVar3;
  *plVar9 = lVar6;
  plVar9[1] = lVar6;
  plVar9[2] = lVar6;
  *(undefined2 *)(plVar9 + 3) = 0;
  puVar14 = *(undefined8 **)(DAT_18007a278 + 8);
  cVar1 = *(char *)((longlong)puVar14 + 0x19);
  in_stack_00000040 = puVar14;
  while (cVar1 == '\0') {
    in_stack_00000040 = puVar14;
    uVar8 = FUN_180007ea0(plVar9 + 4,puVar14 + 4);
    bVar18 = (char)uVar8 == '\0';
    if (bVar18) {
      puVar14 = (undefined8 *)puVar14[2];
    }
    else {
      puVar14 = (undefined8 *)*puVar14;
    }
    uStack0000000000000048 = (uint)!bVar18;
    cVar1 = *(char *)((longlong)puVar14 + 0x19);
  }
  if (DAT_18007a280 == 0x333333333333333) {
                    /* WARNING: Subroutine does not return */
    FUN_18000ac90();
  }
  FUN_18000a930(&DAT_18007a278,(longlong *)&stack0x00000040,plVar9);
  FUN_180017e00(unaff_RBP + -0x80,unaff_RBP + -0x80,
                *(longlong **)(*(longlong *)(unaff_RBP + -0x80) + 8));
  operator_delete(*(void **)(unaff_RBP + -0x80));
  if (0xf < uVar17) {
    pvVar11 = _uStack0000000000000060;
    if ((0xfff < uVar17 + 1) &&
       (pvVar11 = *(void **)((longlong)_uStack0000000000000060 + -8),
       0x1f < (ulonglong)((longlong)_uStack0000000000000060 + (-8 - (longlong)pvVar11)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar11);
  }
  if (0xf < uVar2) {
    puVar14 = puVar13;
    if ((0xfff < uVar2 + 1) &&
       (puVar14 = (undefined8 *)puVar13[-1],
       0x1f < (ulonglong)((longlong)puVar13 + (-8 - (longlong)puVar14)))) goto LAB_180021f98;
    operator_delete(puVar14);
  }
  if (0xf < *(ulonglong *)(unaff_RBP + -0x30)) {
    puVar13 = puVar12;
    if ((0xfff < *(ulonglong *)(unaff_RBP + -0x30) + 1) &&
       (puVar13 = (undefined8 *)puVar12[-1],
       0x1f < (ulonglong)((longlong)puVar12 + (-8 - (longlong)puVar13)))) goto LAB_180021f98;
    operator_delete(puVar13);
  }
  if (0xf < *(ulonglong *)(unaff_RBP + -0x50)) {
    pvVar11 = *(void **)(unaff_RBP + -0x68);
    pvVar10 = pvVar11;
    if ((0xfff < *(ulonglong *)(unaff_RBP + -0x50) + 1) &&
       (pvVar10 = *(void **)((longlong)pvVar11 + -8),
       0x1f < (ulonglong)((longlong)pvVar11 + (-8 - (longlong)pvVar10)))) {
LAB_180021f98:
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar10);
  }
  FUN_180017cc0(&stack0x00000030,&stack0x00000030,*(longlong **)((longlong)in_stack_00000030 + 8));
  operator_delete(in_stack_00000030);
  FUN_180017e00(&pvStackX_20,&pvStackX_20,*(longlong **)((longlong)pvStackX_20 + 8));
  operator_delete(pvStackX_20);
  return;
}

/* ---- FUNC 00021980 FUN_180021980 (79 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_180021980(void)

{
  char cVar1;
  undefined8 *puVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong lVar6;
  longlong *plVar7;
  undefined8 uVar8;
  uint uVar9;
  longlong *plVar10;
  void *pvVar11;
  ulonglong uVar12;
  void *pvVar13;
  undefined8 *unaff_RBX;
  ulonglong uVar14;
  undefined8 *puVar15;
  undefined8 *puVar16;
  longlong unaff_RBP;
  ulonglong unaff_RDI;
  undefined8 in_R9;
  char cVar17;
  undefined4 uVar18;
  void *unaff_R13;
  longlong *unaff_R14;
  ulonglong unaff_R15;
  bool bVar19;
  void *pvStackX_20;
  longlong in_stack_00000028;
  void *in_stack_00000030;
  longlong in_stack_00000038;
  undefined8 *puStack0000000000000040;
  uint uStack0000000000000048;
  undefined4 uStack000000000000004c;
  void *in_stack_00000060;
  longlong in_stack_00000068;
  ulonglong in_stack_00000070;
  ulonglong in_stack_00000078;
  
  do {
    puStack0000000000000040 = unaff_RBX;
    uVar9 = FUN_180007ea0(unaff_R14 + 4,unaff_RBX + 4);
    uVar18 = SUB84(unaff_R13,0);
    if ((char)uVar9 == '\0') {
      unaff_RBX = (undefined8 *)unaff_RBX[2];
      _uStack0000000000000048 = CONCAT44(uStack000000000000004c,uVar18);
    }
    else {
      unaff_RBX = (undefined8 *)*unaff_RBX;
      _uStack0000000000000048 = CONCAT44(uStack000000000000004c,1);
    }
    cVar17 = (char)unaff_R13;
  } while (*(char *)((longlong)unaff_RBX + 0x19) == cVar17);
  if (in_stack_00000038 == 0x2e8ba2e8ba2e8ba) {
                    /* WARNING: Subroutine does not return */
    FUN_18000ac90();
  }
  FUN_18000a930((longlong *)&stack0x00000030,(longlong *)&stack0x00000040,unaff_R14);
  puVar2 = *(undefined8 **)(unaff_RBP + -0x48);
  uVar3 = *(ulonglong *)(unaff_RBP + -0x38);
  puVar15 = (undefined8 *)(unaff_RBP + -0x48);
  if (0xf < *(ulonglong *)(unaff_RBP + -0x30)) {
    puVar15 = puVar2;
  }
  in_stack_00000060 = (void *)0x0;
  in_stack_00000068 = 0;
  if (unaff_RDI < uVar3) {
                    /* WARNING: Subroutine does not return */
    FUN_18000ace0();
  }
  if (uVar3 < 0x10) {
    in_stack_00000078 = 0xf;
    in_stack_00000060 = (void *)*puVar15;
    in_stack_00000068 = puVar15[1];
    in_stack_00000070 = uVar3;
  }
  else {
    uVar14 = uVar3 | 0xf;
    if (unaff_RDI < uVar14) {
      pvVar13 = (void *)FUN_180007f10(unaff_R15);
      uVar14 = unaff_RDI;
    }
    else {
      if (uVar14 < 0x16) {
        uVar14 = 0x16;
      }
      uVar12 = uVar14 + 1;
      if (uVar12 < 0x1000) {
        pvVar13 = unaff_R13;
        if (uVar12 != 0) {
          pvVar13 = operator_new(uVar12);
        }
      }
      else {
        pvVar13 = (void *)FUN_180007f10(uVar12);
      }
    }
    unaff_R14 = (longlong *)(uVar3 + 1);
    in_stack_00000060 = pvVar13;
    in_stack_00000070 = uVar3;
    in_stack_00000078 = uVar14;
    memcpy(pvVar13,puVar15,(size_t)unaff_R14);
  }
  FUN_1800186c0((longlong *)(unaff_RBP + -0x80),(longlong *)&stack0x00000030,unaff_R14,in_R9);
  pvVar13 = pvStackX_20;
  plVar10 = operator_new(0x50);
  plVar10[6] = (longlong)unaff_R13;
  plVar10[7] = (longlong)unaff_R13;
  plVar10[4] = (longlong)in_stack_00000060;
  plVar10[5] = in_stack_00000068;
  uVar3 = _UNK_180053828;
  uVar8 = _DAT_180053820;
  plVar10[6] = in_stack_00000070;
  plVar10[7] = in_stack_00000078;
  in_stack_00000060 = (void *)CONCAT71(in_stack_00000060._1_7_,cVar17);
  in_stack_00000070 = uVar8;
  in_stack_00000078 = uVar3;
  plVar10[8] = (longlong)unaff_R13;
  plVar10[9] = (longlong)unaff_R13;
  pvVar11 = operator_new(0x58);
  *(void **)pvVar11 = pvVar11;
  *(void **)((longlong)pvVar11 + 8) = pvVar11;
  *(void **)((longlong)pvVar11 + 0x10) = pvVar11;
  *(undefined2 *)((longlong)pvVar11 + 0x18) = 0x101;
  plVar10[8] = *(longlong *)(unaff_RBP + -0x80);
  *(void **)(unaff_RBP + -0x80) = pvVar11;
  lVar4 = plVar10[9];
  plVar10[9] = *(longlong *)(unaff_RBP + -0x78);
  *(longlong *)(unaff_RBP + -0x78) = lVar4;
  *plVar10 = (longlong)pvVar13;
  plVar10[1] = (longlong)pvVar13;
  plVar10[2] = (longlong)pvVar13;
  *(short *)(plVar10 + 3) = (short)unaff_R13;
  puVar15 = *(undefined8 **)((longlong)pvStackX_20 + 8);
  cVar1 = *(char *)((longlong)puVar15 + 0x19);
  puStack0000000000000040 = puVar15;
  uStack0000000000000048 = uVar18;
  while (cVar1 == cVar17) {
    puStack0000000000000040 = puVar15;
    uVar9 = FUN_180007ea0(plVar10 + 4,puVar15 + 4);
    if ((char)uVar9 == '\0') {
      puVar15 = (undefined8 *)puVar15[2];
      uStack0000000000000048 = uVar18;
    }
    else {
      puVar15 = (undefined8 *)*puVar15;
      uStack0000000000000048 = 1;
    }
    cVar1 = *(char *)((longlong)puVar15 + 0x19);
  }
  if (in_stack_00000028 == 0x333333333333333) {
                    /* WARNING: Subroutine does not return */
    FUN_18000ac90();
  }
  FUN_18000a930((longlong *)&pvStackX_20,(longlong *)&stack0x00000040,plVar10);
  FUN_180017cc0(unaff_RBP + -0x80,unaff_RBP + -0x80,
                *(longlong **)(*(longlong *)(unaff_RBP + -0x80) + 8));
  operator_delete(*(void **)(unaff_RBP + -0x80));
  if (0xf < in_stack_00000078) {
    pvVar13 = in_stack_00000060;
    if ((0xfff < in_stack_00000078 + 1) &&
       (pvVar13 = *(void **)((longlong)in_stack_00000060 + -8),
       0x1f < (ulonglong)((longlong)in_stack_00000060 + (-8 - (longlong)pvVar13)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar13);
  }
  uVar3 = *(ulonglong *)(unaff_RBP + -0x10);
  puVar15 = *(undefined8 **)(unaff_RBP + -0x28);
  uVar14 = *(ulonglong *)(unaff_RBP + -0x18);
  puVar16 = (undefined8 *)(unaff_RBP + -0x28);
  if (0xf < uVar3) {
    puVar16 = puVar15;
  }
  in_stack_00000060 = (void *)0x0;
  in_stack_00000068 = 0;
  if (unaff_RDI < uVar14) {
                    /* WARNING: Subroutine does not return */
    FUN_18000ace0();
  }
  if (uVar14 < 0x10) {
    in_stack_00000078 = 0xf;
    in_stack_00000060 = (void *)*puVar16;
    in_stack_00000068 = puVar16[1];
    in_stack_00000070 = uVar14;
  }
  else {
    uVar12 = uVar14 | 0xf;
    if (unaff_RDI < uVar12) {
LAB_180021c89:
      in_stack_00000060 = (void *)FUN_180007f10(unaff_R15);
      uVar12 = unaff_RDI;
    }
    else {
      if (uVar12 < 0x16) {
        uVar12 = 0x16;
      }
      unaff_R15 = uVar12 + 1;
      unaff_RDI = uVar12;
      if (0xfff < unaff_R15) goto LAB_180021c89;
      if (unaff_R15 == 0) {
        in_stack_00000060 = (void *)0x0;
      }
      else {
        in_stack_00000060 = operator_new(unaff_R15);
      }
    }
    in_stack_00000070 = uVar14;
    in_stack_00000078 = uVar12;
    memcpy(in_stack_00000060,puVar16,uVar14 + 1);
  }
  *(undefined8 *)(unaff_RBP + -0x78) = 0;
  pvVar13 = operator_new(0x50);
  *(void **)pvVar13 = pvVar13;
  *(void **)((longlong)pvVar13 + 8) = pvVar13;
  *(void **)((longlong)pvVar13 + 0x10) = pvVar13;
  *(undefined2 *)((longlong)pvVar13 + 0x18) = 0x101;
  *(void **)(unaff_RBP + -0x80) = pvVar13;
  plVar10 = FUN_1800178a0((undefined8 *)(unaff_RBP + -0x80),
                          *(undefined8 **)((longlong)pvStackX_20 + 8),(longlong)pvVar13,in_R9);
  *(longlong **)(*(longlong *)(unaff_RBP + -0x80) + 8) = plVar10;
  plVar10 = *(longlong **)(unaff_RBP + -0x80);
  *(longlong *)(unaff_RBP + -0x78) = in_stack_00000028;
  plVar5 = (longlong *)plVar10[1];
  if (*(char *)((longlong)plVar5 + 0x19) == '\0') {
    cVar17 = *(char *)(*plVar5 + 0x19);
    plVar7 = (longlong *)*plVar5;
    while (cVar17 == '\0') {
      cVar17 = *(char *)(*plVar7 + 0x19);
      plVar5 = plVar7;
      plVar7 = (longlong *)*plVar7;
    }
    *plVar10 = (longlong)plVar5;
    lVar4 = *(longlong *)(*(longlong *)(unaff_RBP + -0x80) + 8);
    lVar6 = *(longlong *)(lVar4 + 0x10);
    cVar17 = *(char *)(lVar6 + 0x19);
    while (cVar17 == '\0') {
      cVar17 = *(char *)(*(longlong *)(lVar6 + 0x10) + 0x19);
      lVar4 = lVar6;
      lVar6 = *(longlong *)(lVar6 + 0x10);
    }
    *(longlong *)(*(longlong *)(unaff_RBP + -0x80) + 0x10) = lVar4;
  }
  else {
    *plVar10 = (longlong)plVar10;
    *(longlong *)(*(longlong *)(unaff_RBP + -0x80) + 0x10) = *(longlong *)(unaff_RBP + -0x80);
  }
  lVar6 = DAT_18007a278;
  plVar10 = operator_new(0x50);
  plVar10[6] = 0;
  plVar10[7] = 0;
  plVar10[4] = (longlong)in_stack_00000060;
  plVar10[5] = in_stack_00000068;
  uVar14 = _UNK_180053828;
  uVar8 = _DAT_180053820;
  plVar10[6] = in_stack_00000070;
  plVar10[7] = in_stack_00000078;
  in_stack_00000060 = (void *)((ulonglong)in_stack_00000060 & 0xffffffffffffff00);
  in_stack_00000070 = uVar8;
  in_stack_00000078 = uVar14;
  plVar10[8] = 0;
  plVar10[9] = 0;
  pvVar13 = operator_new(0x50);
  uStack0000000000000048 = 0;
  *(void **)pvVar13 = pvVar13;
  *(void **)((longlong)pvVar13 + 8) = pvVar13;
  *(void **)((longlong)pvVar13 + 0x10) = pvVar13;
  *(undefined2 *)((longlong)pvVar13 + 0x18) = 0x101;
  plVar10[8] = *(longlong *)(unaff_RBP + -0x80);
  *(void **)(unaff_RBP + -0x80) = pvVar13;
  lVar4 = plVar10[9];
  plVar10[9] = *(longlong *)(unaff_RBP + -0x78);
  *(longlong *)(unaff_RBP + -0x78) = lVar4;
  *plVar10 = lVar6;
  plVar10[1] = lVar6;
  plVar10[2] = lVar6;
  *(undefined2 *)(plVar10 + 3) = 0;
  puVar16 = *(undefined8 **)(DAT_18007a278 + 8);
  cVar17 = *(char *)((longlong)puVar16 + 0x19);
  puStack0000000000000040 = puVar16;
  while (cVar17 == '\0') {
    puStack0000000000000040 = puVar16;
    uVar9 = FUN_180007ea0(plVar10 + 4,puVar16 + 4);
    bVar19 = (char)uVar9 == '\0';
    if (bVar19) {
      puVar16 = (undefined8 *)puVar16[2];
    }
    else {
      puVar16 = (undefined8 *)*puVar16;
    }
    uStack0000000000000048 = (uint)!bVar19;
    cVar17 = *(char *)((longlong)puVar16 + 0x19);
  }
  if (DAT_18007a280 == 0x333333333333333) {
                    /* WARNING: Subroutine does not return */
    FUN_18000ac90();
  }
  FUN_18000a930(&DAT_18007a278,(longlong *)&stack0x00000040,plVar10);
  FUN_180017e00(unaff_RBP + -0x80,unaff_RBP + -0x80,
                *(longlong **)(*(longlong *)(unaff_RBP + -0x80) + 8));
  operator_delete(*(void **)(unaff_RBP + -0x80));
  if (0xf < in_stack_00000078) {
    pvVar13 = in_stack_00000060;
    if ((0xfff < in_stack_00000078 + 1) &&
       (pvVar13 = *(void **)((longlong)in_stack_00000060 + -8),
       0x1f < (ulonglong)((longlong)in_stack_00000060 + (-8 - (longlong)pvVar13)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar13);
  }
  if (0xf < uVar3) {
    puVar16 = puVar15;
    if ((0xfff < uVar3 + 1) &&
       (puVar16 = (undefined8 *)puVar15[-1],
       0x1f < (ulonglong)((longlong)puVar15 + (-8 - (longlong)puVar16)))) goto LAB_180021f98;
    operator_delete(puVar16);
  }
  if (0xf < *(ulonglong *)(unaff_RBP + -0x30)) {
    puVar15 = puVar2;
    if ((0xfff < *(ulonglong *)(unaff_RBP + -0x30) + 1) &&
       (puVar15 = (undefined8 *)puVar2[-1],
       0x1f < (ulonglong)((longlong)puVar2 + (-8 - (longlong)puVar15)))) goto LAB_180021f98;
    operator_delete(puVar15);
  }
  if (0xf < *(ulonglong *)(unaff_RBP + -0x50)) {
    pvVar13 = *(void **)(unaff_RBP + -0x68);
    pvVar11 = pvVar13;
    if ((0xfff < *(ulonglong *)(unaff_RBP + -0x50) + 1) &&
       (pvVar11 = *(void **)((longlong)pvVar13 + -8),
       0x1f < (ulonglong)((longlong)pvVar13 + (-8 - (longlong)pvVar11)))) {
LAB_180021f98:
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar11);
  }
  FUN_180017cc0(&stack0x00000030,&stack0x00000030,*(longlong **)((longlong)in_stack_00000030 + 8));
  operator_delete(in_stack_00000030);
  FUN_180017e00(&pvStackX_20,&pvStackX_20,*(longlong **)((longlong)pvStackX_20 + 8));
  operator_delete(pvStackX_20);
  return;
}

/* ---- FUNC 000219CF FUN_1800219cf (1644 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1800219cf(longlong param_1,undefined8 param_2,longlong *param_3,undefined8 param_4,
                  longlong param_5,void *param_6)

{
  char cVar1;
  undefined8 *puVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong lVar6;
  longlong *plVar7;
  undefined8 uVar8;
  uint uVar9;
  longlong *plVar10;
  void *pvVar11;
  ulonglong uVar12;
  void *pvVar13;
  ulonglong uVar14;
  undefined8 *puVar15;
  undefined8 *puVar16;
  longlong unaff_RBP;
  ulonglong unaff_RDI;
  void *unaff_R13;
  ulonglong unaff_R15;
  bool bVar17;
  undefined8 in_XMM0_Qb;
  void *pvStackX_20;
  undefined8 *puStack0000000000000040;
  uint uStack0000000000000048;
  undefined4 uStack000000000000004c;
  void *in_stack_00000060;
  longlong in_stack_00000068;
  ulonglong in_stack_00000070;
  ulonglong in_stack_00000078;
  
  uStack000000000000004c = (undefined4)((ulonglong)in_XMM0_Qb >> 0x20);
  puStack0000000000000040 = (undefined8 *)param_1;
  FUN_18000a930((longlong *)&param_6,(longlong *)&stack0x00000040,param_3);
  puVar2 = *(undefined8 **)(unaff_RBP + -0x48);
  uVar3 = *(ulonglong *)(unaff_RBP + -0x38);
  puVar15 = (undefined8 *)(unaff_RBP + -0x48);
  if (0xf < *(ulonglong *)(unaff_RBP + -0x30)) {
    puVar15 = puVar2;
  }
  in_stack_00000060 = (void *)0x0;
  in_stack_00000068 = 0;
  if (unaff_RDI < uVar3) {
                    /* WARNING: Subroutine does not return */
    FUN_18000ace0();
  }
  if (uVar3 < 0x10) {
    in_stack_00000078 = 0xf;
    in_stack_00000060 = (void *)*puVar15;
    in_stack_00000068 = puVar15[1];
    in_stack_00000070 = uVar3;
  }
  else {
    uVar14 = uVar3 | 0xf;
    if (unaff_RDI < uVar14) {
      pvVar13 = (void *)FUN_180007f10(unaff_R15);
      uVar14 = unaff_RDI;
    }
    else {
      if (uVar14 < 0x16) {
        uVar14 = 0x16;
      }
      uVar12 = uVar14 + 1;
      if (uVar12 < 0x1000) {
        pvVar13 = unaff_R13;
        if (uVar12 != 0) {
          pvVar13 = operator_new(uVar12);
        }
      }
      else {
        pvVar13 = (void *)FUN_180007f10(uVar12);
      }
    }
    param_3 = (longlong *)(uVar3 + 1);
    in_stack_00000060 = pvVar13;
    in_stack_00000070 = uVar3;
    in_stack_00000078 = uVar14;
    memcpy(pvVar13,puVar15,(size_t)param_3);
  }
  FUN_1800186c0((longlong *)(unaff_RBP + -0x80),(longlong *)&param_6,param_3,param_4);
  pvVar13 = pvStackX_20;
  plVar10 = operator_new(0x50);
  plVar10[6] = (longlong)unaff_R13;
  plVar10[7] = (longlong)unaff_R13;
  plVar10[4] = (longlong)in_stack_00000060;
  plVar10[5] = in_stack_00000068;
  uVar3 = _UNK_180053828;
  uVar8 = _DAT_180053820;
  plVar10[6] = in_stack_00000070;
  plVar10[7] = in_stack_00000078;
  in_stack_00000060 = (void *)CONCAT71(in_stack_00000060._1_7_,(char)unaff_R13);
  in_stack_00000070 = uVar8;
  in_stack_00000078 = uVar3;
  plVar10[8] = (longlong)unaff_R13;
  plVar10[9] = (longlong)unaff_R13;
  pvVar11 = operator_new(0x58);
  *(void **)pvVar11 = pvVar11;
  *(void **)((longlong)pvVar11 + 8) = pvVar11;
  *(void **)((longlong)pvVar11 + 0x10) = pvVar11;
  *(undefined2 *)((longlong)pvVar11 + 0x18) = 0x101;
  plVar10[8] = *(longlong *)(unaff_RBP + -0x80);
  *(void **)(unaff_RBP + -0x80) = pvVar11;
  lVar4 = plVar10[9];
  plVar10[9] = *(longlong *)(unaff_RBP + -0x78);
  *(longlong *)(unaff_RBP + -0x78) = lVar4;
  *plVar10 = (longlong)pvVar13;
  plVar10[1] = (longlong)pvVar13;
  plVar10[2] = (longlong)pvVar13;
  *(short *)(plVar10 + 3) = (short)unaff_R13;
  puVar15 = *(undefined8 **)((longlong)pvStackX_20 + 8);
  cVar1 = *(char *)((longlong)puVar15 + 0x19);
  uStack0000000000000048 = (int)unaff_R13;
  puStack0000000000000040 = puVar15;
  while (cVar1 == (char)unaff_R13) {
    puStack0000000000000040 = puVar15;
    uVar9 = FUN_180007ea0(plVar10 + 4,puVar15 + 4);
    if ((char)uVar9 == '\0') {
      puVar15 = (undefined8 *)puVar15[2];
      uStack0000000000000048 = (int)unaff_R13;
    }
    else {
      puVar15 = (undefined8 *)*puVar15;
      uStack0000000000000048 = 1;
    }
    cVar1 = *(char *)((longlong)puVar15 + 0x19);
  }
  if (param_5 == 0x333333333333333) {
                    /* WARNING: Subroutine does not return */
    FUN_18000ac90();
  }
  FUN_18000a930((longlong *)&pvStackX_20,(longlong *)&stack0x00000040,plVar10);
  FUN_180017cc0(unaff_RBP + -0x80,unaff_RBP + -0x80,
                *(longlong **)(*(longlong *)(unaff_RBP + -0x80) + 8));
  operator_delete(*(void **)(unaff_RBP + -0x80));
  if (0xf < in_stack_00000078) {
    pvVar13 = in_stack_00000060;
    if ((0xfff < in_stack_00000078 + 1) &&
       (pvVar13 = *(void **)((longlong)in_stack_00000060 + -8),
       0x1f < (ulonglong)((longlong)in_stack_00000060 + (-8 - (longlong)pvVar13)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar13);
  }
  uVar3 = *(ulonglong *)(unaff_RBP + -0x10);
  puVar15 = *(undefined8 **)(unaff_RBP + -0x28);
  uVar14 = *(ulonglong *)(unaff_RBP + -0x18);
  puVar16 = (undefined8 *)(unaff_RBP + -0x28);
  if (0xf < uVar3) {
    puVar16 = puVar15;
  }
  in_stack_00000060 = (void *)0x0;
  in_stack_00000068 = 0;
  if (unaff_RDI < uVar14) {
                    /* WARNING: Subroutine does not return */
    FUN_18000ace0();
  }
  if (uVar14 < 0x10) {
    in_stack_00000078 = 0xf;
    in_stack_00000060 = (void *)*puVar16;
    in_stack_00000068 = puVar16[1];
    in_stack_00000070 = uVar14;
  }
  else {
    uVar12 = uVar14 | 0xf;
    if (unaff_RDI < uVar12) {
LAB_180021c89:
      in_stack_00000060 = (void *)FUN_180007f10(unaff_R15);
      uVar12 = unaff_RDI;
    }
    else {
      if (uVar12 < 0x16) {
        uVar12 = 0x16;
      }
      unaff_R15 = uVar12 + 1;
      unaff_RDI = uVar12;
      if (0xfff < unaff_R15) goto LAB_180021c89;
      if (unaff_R15 == 0) {
        in_stack_00000060 = (void *)0x0;
      }
      else {
        in_stack_00000060 = operator_new(unaff_R15);
      }
    }
    in_stack_00000070 = uVar14;
    in_stack_00000078 = uVar12;
    memcpy(in_stack_00000060,puVar16,uVar14 + 1);
  }
  *(undefined8 *)(unaff_RBP + -0x78) = 0;
  pvVar13 = operator_new(0x50);
  *(void **)pvVar13 = pvVar13;
  *(void **)((longlong)pvVar13 + 8) = pvVar13;
  *(void **)((longlong)pvVar13 + 0x10) = pvVar13;
  *(undefined2 *)((longlong)pvVar13 + 0x18) = 0x101;
  *(void **)(unaff_RBP + -0x80) = pvVar13;
  plVar10 = FUN_1800178a0((undefined8 *)(unaff_RBP + -0x80),
                          *(undefined8 **)((longlong)pvStackX_20 + 8),(longlong)pvVar13,param_4);
  *(longlong **)(*(longlong *)(unaff_RBP + -0x80) + 8) = plVar10;
  plVar10 = *(longlong **)(unaff_RBP + -0x80);
  *(longlong *)(unaff_RBP + -0x78) = param_5;
  plVar5 = (longlong *)plVar10[1];
  if (*(char *)((longlong)plVar5 + 0x19) == '\0') {
    cVar1 = *(char *)(*plVar5 + 0x19);
    plVar7 = (longlong *)*plVar5;
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*plVar7 + 0x19);
      plVar5 = plVar7;
      plVar7 = (longlong *)*plVar7;
    }
    *plVar10 = (longlong)plVar5;
    lVar4 = *(longlong *)(*(longlong *)(unaff_RBP + -0x80) + 8);
    lVar6 = *(longlong *)(lVar4 + 0x10);
    cVar1 = *(char *)(lVar6 + 0x19);
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*(longlong *)(lVar6 + 0x10) + 0x19);
      lVar4 = lVar6;
      lVar6 = *(longlong *)(lVar6 + 0x10);
    }
    *(longlong *)(*(longlong *)(unaff_RBP + -0x80) + 0x10) = lVar4;
  }
  else {
    *plVar10 = (longlong)plVar10;
    *(longlong *)(*(longlong *)(unaff_RBP + -0x80) + 0x10) = *(longlong *)(unaff_RBP + -0x80);
  }
  lVar6 = DAT_18007a278;
  plVar10 = operator_new(0x50);
  plVar10[6] = 0;
  plVar10[7] = 0;
  plVar10[4] = (longlong)in_stack_00000060;
  plVar10[5] = in_stack_00000068;
  uVar14 = _UNK_180053828;
  uVar8 = _DAT_180053820;
  plVar10[6] = in_stack_00000070;
  plVar10[7] = in_stack_00000078;
  in_stack_00000060 = (void *)((ulonglong)in_stack_00000060 & 0xffffffffffffff00);
  in_stack_00000070 = uVar8;
  in_stack_00000078 = uVar14;
  plVar10[8] = 0;
  plVar10[9] = 0;
  pvVar13 = operator_new(0x50);
  uStack0000000000000048 = 0;
  *(void **)pvVar13 = pvVar13;
  *(void **)((longlong)pvVar13 + 8) = pvVar13;
  *(void **)((longlong)pvVar13 + 0x10) = pvVar13;
  *(undefined2 *)((longlong)pvVar13 + 0x18) = 0x101;
  plVar10[8] = *(longlong *)(unaff_RBP + -0x80);
  *(void **)(unaff_RBP + -0x80) = pvVar13;
  lVar4 = plVar10[9];
  plVar10[9] = *(longlong *)(unaff_RBP + -0x78);
  *(longlong *)(unaff_RBP + -0x78) = lVar4;
  *plVar10 = lVar6;
  plVar10[1] = lVar6;
  plVar10[2] = lVar6;
  *(undefined2 *)(plVar10 + 3) = 0;
  puVar16 = *(undefined8 **)(DAT_18007a278 + 8);
  cVar1 = *(char *)((longlong)puVar16 + 0x19);
  puStack0000000000000040 = puVar16;
  while (cVar1 == '\0') {
    puStack0000000000000040 = puVar16;
    uVar9 = FUN_180007ea0(plVar10 + 4,puVar16 + 4);
    bVar17 = (char)uVar9 == '\0';
    if (bVar17) {
      puVar16 = (undefined8 *)puVar16[2];
    }
    else {
      puVar16 = (undefined8 *)*puVar16;
    }
    uStack0000000000000048 = (uint)!bVar17;
    cVar1 = *(char *)((longlong)puVar16 + 0x19);
  }
  if (DAT_18007a280 == 0x333333333333333) {
                    /* WARNING: Subroutine does not return */
    FUN_18000ac90();
  }
  FUN_18000a930(&DAT_18007a278,(longlong *)&stack0x00000040,plVar10);
  FUN_180017e00(unaff_RBP + -0x80,unaff_RBP + -0x80,
                *(longlong **)(*(longlong *)(unaff_RBP + -0x80) + 8));
  operator_delete(*(void **)(unaff_RBP + -0x80));
  if (0xf < in_stack_00000078) {
    pvVar13 = in_stack_00000060;
    if ((0xfff < in_stack_00000078 + 1) &&
       (pvVar13 = *(void **)((longlong)in_stack_00000060 + -8),
       0x1f < (ulonglong)((longlong)in_stack_00000060 + (-8 - (longlong)pvVar13)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar13);
  }
  if (0xf < uVar3) {
    puVar16 = puVar15;
    if ((0xfff < uVar3 + 1) &&
       (puVar16 = (undefined8 *)puVar15[-1],
       0x1f < (ulonglong)((longlong)puVar15 + (-8 - (longlong)puVar16)))) goto LAB_180021f98;
    operator_delete(puVar16);
  }
  if (0xf < *(ulonglong *)(unaff_RBP + -0x30)) {
    puVar15 = puVar2;
    if ((0xfff < *(ulonglong *)(unaff_RBP + -0x30) + 1) &&
       (puVar15 = (undefined8 *)puVar2[-1],
       0x1f < (ulonglong)((longlong)puVar2 + (-8 - (longlong)puVar15)))) goto LAB_180021f98;
    operator_delete(puVar15);
  }
  if (0xf < *(ulonglong *)(unaff_RBP + -0x50)) {
    pvVar13 = *(void **)(unaff_RBP + -0x68);
    pvVar11 = pvVar13;
    if ((0xfff < *(ulonglong *)(unaff_RBP + -0x50) + 1) &&
       (pvVar11 = *(void **)((longlong)pvVar13 + -8),
       0x1f < (ulonglong)((longlong)pvVar13 + (-8 - (longlong)pvVar11)))) {
LAB_180021f98:
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar11);
  }
  FUN_180017cc0(&param_6,&param_6,*(longlong **)((longlong)param_6 + 8));
  operator_delete(param_6);
  FUN_180017e00(&pvStackX_20,&pvStackX_20,*(longlong **)((longlong)pvStackX_20 + 8));
  operator_delete(pvStackX_20);
  return;
}

/* ---- FUNC 00022018 thunk_FUN_18000ac90 (5 bytes) ---- */

void thunk_FUN_18000ac90(void)

{
                    /* WARNING: Subroutine does not return */
  FUN_18000ac90();
}

/* ---- FUNC 0002201E thunk_FUN_18000ace0 (5 bytes) ---- */

void thunk_FUN_18000ace0(void)

{
                    /* WARNING: Subroutine does not return */
  FUN_18000ace0();
}

/* ---- FUNC 0002202A thunk_FUN_18000ace0 (5 bytes) ---- */

void thunk_FUN_18000ace0(void)

{
                    /* WARNING: Subroutine does not return */
  FUN_18000ace0();
}

/* ---- FUNC 00022040 WriteGraphicsToFile (272 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int WriteGraphicsToFile(undefined8 *param_1,longlong param_2,undefined4 param_3,undefined8 param_4,
                       undefined4 param_5,undefined8 param_6)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined1 auStackY_478 [32];
  longlong *local_448 [2];
  undefined1 local_438 [1008];
  ulonglong local_48;
  
                    /* 0x22040  538  WriteGraphicsToFile */
  local_48 = DAT_1800791f8 ^ (ulonglong)auStackY_478;
  puVar2 = operator_new(0x138);
  puVar3 = (undefined8 *)0x0;
  if (puVar2 != (undefined8 *)0x0) {
    puVar3 = FUN_180018980(puVar2,param_4,param_5,0,param_6,0);
  }
  local_448[0] = (longlong *)0x0;
  iVar1 = (**(code **)*puVar3)(puVar3,&DAT_180057a78,local_448);
  if (iVar1 != 0) {
    FUN_180007de0(local_438,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\bkputil.cpp",0x3d4);
    LogMessage(local_438,2,1);
  }
  iVar1 = WriteGraphicsWithStream(param_1,param_2,param_3,local_448[0],(undefined8 *)0x0,1);
  (**(code **)(*local_448[0] + 0x10))();
  return iVar1;
}

/* ---- FUNC 00022150 WriteGraphicsWithObject (263 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int WriteGraphicsWithObject
              (undefined8 *param_1,undefined8 *param_2,longlong param_3,undefined4 param_4,
              int param_5,undefined8 param_6,undefined8 param_7)

{
  int iVar1;
  undefined8 *puVar2;
  undefined1 auStackY_478 [32];
  longlong *local_448 [2];
  undefined1 local_438 [1008];
  ulonglong local_48;
  
                    /* 0x22150  539  WriteGraphicsWithObject */
  local_48 = DAT_1800791f8 ^ (ulonglong)auStackY_478;
  puVar2 = operator_new(0x28);
  if (puVar2 == (undefined8 *)0x0) {
    puVar2 = (undefined8 *)0x0;
  }
  else {
    puVar2 = FUN_1800188e0(puVar2,param_6,param_7,0);
  }
  local_448[0] = (longlong *)0x0;
  iVar1 = (**(code **)*puVar2)(puVar2,&DAT_180057a78,local_448);
  if (iVar1 != 0) {
    FUN_180007de0(local_438,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\bkputil.cpp",0x3e3);
    LogMessage(local_438,2,1);
  }
  iVar1 = WriteGraphicsWithStream(param_1,param_3,param_4,local_448[0],param_2,param_5);
  (**(code **)(*local_448[0] + 0x10))();
  return iVar1;
}

/* ---- FUNC 00022260 WriteGraphicsWithStream (830 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int WriteGraphicsWithStream
              (undefined8 *param_1,longlong param_2,undefined4 param_3,longlong *param_4,
              undefined8 *param_5,int param_6)

{
  longlong lVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  longlong *plVar5;
  char *pcVar6;
  ulonglong uVar7;
  longlong lVar8;
  longlong *plVar10;
  undefined1 auStack_4b8 [32];
  char *local_498;
  longlong *local_490;
  longlong *local_488;
  longlong *local_480;
  longlong *local_478;
  undefined2 local_470 [4];
  undefined8 local_468;
  undefined4 local_460;
  undefined4 local_45c;
  undefined4 local_458;
  undefined4 local_450 [2];
  longlong *local_448;
  undefined8 local_440;
  undefined8 local_438;
  undefined2 local_430;
  ulonglong local_48;
  longlong lVar9;
  
                    /* 0x22260  540  WriteGraphicsWithStream */
  local_48 = DAT_1800791f8 ^ (ulonglong)auStack_4b8;
  local_480 = (longlong *)0x0;
  plVar10 = param_4;
  if (param_1 == (undefined8 *)0x0) {
    local_490 = (longlong *)0x0;
    plVar5 = (longlong *)GetGlobalPointer("HappNode");
    if ((plVar5 == (longlong *)0x0) ||
       (iVar3 = (**(code **)(*plVar5 + 0x90))(plVar5,&local_490), iVar3 < 0)) {
      return 0;
    }
    iVar3 = (**(code **)*local_490)(local_490,&DAT_1800561f0,&local_488);
    (**(code **)(*local_490 + 0x10))();
  }
  else {
    iVar3 = (**(code **)*param_1)(param_1,&DAT_1800561f0,&local_488);
  }
  if ((local_488 != (longlong *)0x0) && (iVar3 == 0)) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_498);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_490);
    pcVar6 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)&local_498,0x41);
    FUN_180019cf0(local_488,pcVar6);
    ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)&local_498,-1);
    if (param_5 != (undefined8 *)0x0) {
      (**(code **)*param_5)(param_5,&DAT_1800561f0,&local_480);
    }
    if (local_480 != (longlong *)0x0) {
      pcVar6 = ATL::CSimpleStringT<char,1>::GetBuffer((CSimpleStringT<char,1> *)&local_490,0x41);
      FUN_180019cf0(local_480,pcVar6);
      ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)&local_490,-1);
      (**(code **)(*local_480 + 0x10))();
    }
    iVar3 = (int)local_490[-2];
    if ((iVar3 != 0) && (iVar4 = strncmp(local_498,(char *)local_490,(longlong)iVar3), iVar4 == 0))
    {
      if (iVar3 < *(int *)(local_498 + -0x10)) {
        cVar2 = ATL::CSimpleStringT<char,1>::operator[]((CSimpleStringT<char,1> *)&local_498,iVar3);
        if (cVar2 == '.') {
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_498,
                     local_498 + (longlong)(int)local_490[-2] + 1);
        }
      }
      else {
        ATL::CSimpleStringT<char,1>::Empty((CSimpleStringT<char,1> *)&local_498);
      }
    }
    local_478 = (longlong *)0x0;
    uVar7 = FUN_180019280(local_488,&local_478);
    if (((int)uVar7 == 0) || ((param_2 != 0 && (param_6 == 1)))) {
      if (*(int *)(local_498 + -0x10) == 0) {
        local_438 = DAT_180054238;
        local_430 = DAT_180054240;
      }
      else {
        FUN_180007de0(&local_438,"#HIERPFSVDATA\n%s PFSVData\n",local_498,plVar10);
      }
      lVar9 = -1;
      do {
        lVar8 = lVar9 + 1;
        lVar1 = lVar9 + 1;
        lVar9 = lVar8;
      } while (*(char *)((longlong)&local_438 + lVar1) != '\0');
      (**(code **)(*param_4 + 0x20))(param_4,&local_438,lVar8,0);
    }
    if ((int)uVar7 == 0) {
      local_470[0] = (undefined2)param_6;
      local_460 = 1;
      local_468 = 0;
      local_458 = 4;
      local_45c = 0xffffffff;
      local_450[0] = 4;
      local_440 = 0;
      local_448 = param_4;
      iVar3 = (**(code **)(*local_478 + 0x20))(local_478,local_470,local_450);
      if (iVar3 != 0) {
        FUN_180007de0(&local_438,"Assert failed in file %s line %d",
                      "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\bkputil.cpp",0x3c1);
        LogMessage(&local_438,2,1);
      }
      (**(code **)(*local_478 + 0x10))();
    }
    else if ((param_2 != 0) && (param_6 == 1)) {
      (**(code **)(*param_4 + 0x20))(param_4,param_2,param_3,0);
    }
    (**(code **)(*local_488 + 0x10))();
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_490);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_498);
    iVar3 = 0;
  }
  return iVar3;
}

/* ---- FUNC 000225A0 WriteOLELink (383 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong WriteOLELink(undefined8 param_1,undefined4 param_2,undefined8 *param_3,undefined8 param_4)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  undefined1 auStackY_478 [32];
  longlong *local_448;
  longlong *local_440;
  longlong *local_438 [2];
  undefined1 local_428 [1008];
  ulonglong local_38;
  
                    /* 0x225a0  541  WriteOLELink */
  local_38 = DAT_1800791f8 ^ (ulonglong)auStackY_478;
  local_448 = (longlong *)GetGlobalPointer("HappNode");
  if (param_3 == (undefined8 *)0x0) {
    local_448 = (longlong *)GetGlobalPointer("HappNode");
    if (local_448 == (longlong *)0x0) {
      return 0x80004005;
    }
    (**(code **)(*local_448 + 8))(local_448);
  }
  else {
    uVar3 = (**(code **)*param_3)(param_3,&DAT_180056180,local_438);
    if ((int)uVar3 < 0) {
      return uVar3;
    }
    uVar2 = (**(code **)(*local_438[0] + 0x38))(local_438[0],&local_448);
    (**(code **)(*local_438[0] + 0x10))();
    if ((int)uVar2 < 0) goto LAB_180022701;
  }
  puVar4 = operator_new(0x138);
  if (puVar4 == (undefined8 *)0x0) {
    puVar4 = (undefined8 *)0x0;
  }
  else {
    puVar4 = FUN_180018980(puVar4,param_1,param_2,0,param_4,0);
  }
  local_440 = (longlong *)0x0;
  iVar1 = (**(code **)*puVar4)(puVar4,&DAT_180057a78,&local_440);
  if (iVar1 != 0) {
    FUN_180007de0(local_428,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\bkputil.cpp",0x5d4);
    LogMessage(local_428,2,1);
  }
  uVar2 = (**(code **)(*local_448 + 0x118))(local_448,local_440,1);
  (**(code **)(*local_440 + 0x10))();
  (**(code **)(*local_448 + 0x10))();
LAB_180022701:
  return (ulonglong)uVar2;
}

/* ---- FUNC 00022720 WriteOLELinkToStream (59 bytes) ---- */

void WriteOLELinkToStream(undefined8 param_1)

{
  longlong *plVar1;
  
                    /* 0x22720  542  WriteOLELinkToStream */
  plVar1 = (longlong *)GetGlobalPointer("HappNode");
  if (plVar1 != (longlong *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00018002274e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*plVar1 + 0x118))(plVar1,param_1,1);
    return;
  }
  return;
}

/* ---- FUNC 00022760 FUN_180022760 (69 bytes) ---- */

void FUN_180022760(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res18 = param_3;
  local_res20 = param_4;
  puVar1 = (undefined8 *)FUN_180007dc0();
  __stdio_common_vfprintf(*puVar1,param_1,param_2,0,&local_res18);
  return;
}

/* ---- FUNC 000227B0 STCopyIStreamToBuffer (101 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

HGLOBAL STCopyIStreamToBuffer(LPSTREAM param_1)

{
  LARGE_INTEGER dlibMove;
  HRESULT HVar1;
  HRESULT HVar2;
  uint cb;
  uint uVar3;
  undefined1 auStackY_4d8 [32];
  LPSTREAM local_4a8;
  HGLOBAL local_4a0;
  ULARGE_INTEGER local_498;
  LARGE_INTEGER local_490;
  ULARGE_INTEGER local_488;
  ULARGE_INTEGER local_480;
  STATSTG local_478;
  undefined1 local_428 [1024];
  ulonglong local_28;
  
                    /* 0x227b0  468  STCopyIStreamToBuffer */
  local_28 = DAT_1800791f8 ^ (ulonglong)auStackY_4d8;
  HVar2 = 0;
  local_4a0 = (HGLOBAL)0x0;
  local_4a8 = (IStream *)0x0;
  HVar1 = GetHGlobalFromStream(param_1,&local_4a0);
  if ((HVar1 != 0) && (HVar1 = CreateStreamOnHGlobal((HGLOBAL)0x0,0,&local_4a8), HVar1 == 0)) {
    local_490.QuadPart = 0;
    uVar3 = 0xffffffff;
    local_498.QuadPart = 0xffffffffffffffff;
    HVar1 = (*param_1->lpVtbl->Stat)(param_1,&local_478,1);
    if (HVar1 == 0) {
      (*local_4a8->lpVtbl->SetSize)(local_4a8,local_478.cbSize);
    }
    dlibMove = local_490;
    (*local_4a8->lpVtbl->Seek)(local_4a8,local_490,0,&local_488);
    HVar1 = (*param_1->lpVtbl->CopyTo)(param_1,local_4a8,local_498,&local_488,&local_480);
    if (HVar1 != 0) {
      (*param_1->lpVtbl->Seek)(param_1,dlibMove,0,&local_488);
      (*local_4a8->lpVtbl->Seek)(local_4a8,dlibMove,0,&local_488);
      while (HVar2 == 0) {
        cb = uVar3;
        if (0x400 < uVar3) {
          cb = 0x400;
        }
        HVar1 = (*param_1->lpVtbl->Read)(param_1,local_428,cb,(ULONG *)&local_498.QuadPart);
        if ((HVar1 < 0) || (local_498.s.LowPart == 0)) break;
        HVar2 = (*local_4a8->lpVtbl->Write)
                          (local_4a8,local_428,local_498.s.LowPart,(ULONG *)&local_490.QuadPart);
        uVar3 = uVar3 - cb;
        if (uVar3 == 0) break;
      }
    }
    GetHGlobalFromStream(local_4a8,&local_4a0);
    (*local_4a8->lpVtbl->Release)(local_4a8);
  }
  return local_4a0;
}

/* ---- FUNC 00022815 FUN_180022815 (146 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

HGLOBAL FUN_180022815(void)

{
  int iVar1;
  uint uVar2;
  longlong in_RAX;
  uint uVar3;
  longlong unaff_RBP;
  LARGE_INTEGER unaff_RSI;
  uint uVar4;
  longlong *unaff_R14;
  IStream *in_stack_00000030;
  HGLOBAL in_stack_00000038;
  ULONG UStack0000000000000040;
  ULARGE_INTEGER in_stack_00000070;
  
  uVar4 = 0xffffffff;
  _UStack0000000000000040 = 0xffffffffffffffff;
  iVar1 = (**(code **)(in_RAX + 0x60))();
  if (iVar1 == 0) {
    (*in_stack_00000030->lpVtbl->SetSize)(in_stack_00000030,in_stack_00000070);
  }
  (*in_stack_00000030->lpVtbl->Seek)
            (in_stack_00000030,unaff_RSI,0,(ULARGE_INTEGER *)&stack0x00000050);
  iVar1 = (**(code **)(*unaff_R14 + 0x38))();
  if (iVar1 != 0) {
    (**(code **)(*unaff_R14 + 0x28))();
    (*in_stack_00000030->lpVtbl->Seek)
              (in_stack_00000030,unaff_RSI,0,(ULARGE_INTEGER *)&stack0x00000050);
    while (unaff_RSI.s.LowPart == 0) {
      uVar3 = uVar4;
      if (0x400 < uVar4) {
        uVar3 = 0x400;
      }
      iVar1 = (**(code **)(*unaff_R14 + 0x18))();
      if ((iVar1 < 0) || (UStack0000000000000040 == 0)) break;
      uVar2 = (*in_stack_00000030->lpVtbl->Write)
                        (in_stack_00000030,(void *)(unaff_RBP + -0x50),UStack0000000000000040,
                         (ULONG *)&stack0x00000048);
      unaff_RSI.s.HighPart = 0;
      unaff_RSI.s.LowPart = uVar2;
      uVar4 = uVar4 - uVar3;
      if (uVar4 == 0) break;
    }
  }
  GetHGlobalFromStream(in_stack_00000030,&stack0x00000038);
  (*in_stack_00000030->lpVtbl->Release)(in_stack_00000030);
  return in_stack_00000038;
}

/* ---- FUNC 000228A7 FUN_1800228a7 (127 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

HGLOBAL FUN_1800228a7(void)

{
  int iVar1;
  longlong in_RAX;
  uint uVar2;
  LARGE_INTEGER unaff_RBX;
  longlong unaff_RBP;
  HRESULT unaff_ESI;
  uint unaff_EDI;
  longlong *unaff_R14;
  IStream *in_stack_00000030;
  HGLOBAL in_stack_00000038;
  ULONG in_stack_00000040;
  
  (**(code **)(in_RAX + 0x28))();
  (*in_stack_00000030->lpVtbl->Seek)
            (in_stack_00000030,unaff_RBX,0,(ULARGE_INTEGER *)&stack0x00000050);
  while (unaff_ESI == 0) {
    uVar2 = unaff_EDI;
    if (0x400 < unaff_EDI) {
      uVar2 = 0x400;
    }
    iVar1 = (**(code **)(*unaff_R14 + 0x18))();
    if ((iVar1 < 0) || (in_stack_00000040 == 0)) break;
    unaff_ESI = (*in_stack_00000030->lpVtbl->Write)
                          (in_stack_00000030,(void *)(unaff_RBP + -0x50),in_stack_00000040,
                           (ULONG *)&stack0x00000048);
    unaff_EDI = unaff_EDI - uVar2;
    if (unaff_EDI == 0) break;
  }
  GetHGlobalFromStream(in_stack_00000030,&stack0x00000038);
  (*in_stack_00000030->lpVtbl->Release)(in_stack_00000030);
  return in_stack_00000038;
}

/* ---- FUNC 00022926 FUN_180022926 (43 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

HGLOBAL FUN_180022926(void)

{
  LPSTREAM in_stack_00000030;
  HGLOBAL in_stack_00000038;
  
  GetHGlobalFromStream(in_stack_00000030,&stack0x00000038);
  (*in_stack_00000030->lpVtbl->Release)(in_stack_00000030);
  return in_stack_00000038;
}

/* ---- FUNC 00022951 FUN_180022951 (32 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180022951(void)

{
  undefined8 in_stack_00000038;
  
  return in_stack_00000038;
}

/* ---- FUNC 00022980 STCreateIStream (50 bytes) ---- */

void STCreateIStream(undefined8 *param_1)

{
  LPSTREAM local_res8 [4];
  
                    /* 0x22980  469  STCreateIStream */
  local_res8[0] = (LPSTREAM)0x0;
  CreateStreamOnHGlobal((HGLOBAL)0x0,1,local_res8);
  *param_1 = local_res8[0];
  return;
}

/* ---- FUNC 000229C0 STReadIStream (32 bytes) ---- */

undefined4 STReadIStream(longlong *param_1)

{
                    /* 0x229c0  471  STReadIStream */
  (**(code **)(*param_1 + 0x18))();
  return 0;
}

/* ---- FUNC 000229E0 STReleaseIStream (7 bytes) ---- */

void STReleaseIStream(longlong *param_1)

{
                    /* 0x229e0  472  STReleaseIStream */
                    /* WARNING: Could not recover jumptable at 0x0001800229e3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x10))();
  return;
}

/* ---- FUNC 000229F0 STWriteIStream (10 bytes) ---- */

void STWriteIStream(longlong *param_1)

{
                    /* 0x229f0  473  STWriteIStream */
                    /* WARNING: Could not recover jumptable at 0x0001800229f6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x20))();
  return;
}

/* ---- FUNC 00022A00 FUN_180022a00 (155 bytes) ---- */

CDialog * FUN_180022a00(CDialog *param_1,CWnd *param_2)

{
  CDialog::CDialog(param_1,0x2a01,param_2);
  *(undefined ***)param_1 = CCatDialog::vftable;
  CWnd::CWnd((CWnd *)(param_1 + 0x130));
  *(undefined ***)(param_1 + 0x130) = CCheckListBox::vftable;
  *(undefined8 *)(param_1 + 0x218) = 0;
  param_1[0x178] = (CDialog)0x1;
  FUN_180022aa0((CWnd *)(param_1 + 0x220));
  FUN_180022aa0((CWnd *)(param_1 + 0x348));
  CPtrArray::CPtrArray((CPtrArray *)(param_1 + 0x470));
  *(undefined ***)(param_1 + 0x470) = CNameAndStateArray::vftable;
  return param_1;
}

/* ---- FUNC 00022AA0 FUN_180022aa0 (98 bytes) ---- */

CWnd * FUN_180022aa0(CWnd *param_1)

{
  CWnd::CWnd(param_1);
  *(undefined8 *)(param_1 + 0xf0) = 0;
  *(undefined ***)(param_1 + 0xe8) = CBitmap::vftable;
  *(undefined8 *)(param_1 + 0x100) = 0;
  *(undefined ***)(param_1 + 0xf8) = CBitmap::vftable;
  *(undefined8 *)(param_1 + 0x110) = 0;
  *(undefined ***)(param_1 + 0x108) = CBitmap::vftable;
  *(undefined8 *)(param_1 + 0x120) = 0;
  *(undefined ***)(param_1 + 0x118) = CBitmap::vftable;
  *(undefined ***)param_1 = CMappedBitmapButton::vftable;
  return param_1;
}

/* ---- FUNC 00022B20 FUN_180022b20 (129 bytes) ---- */

CDialog * FUN_180022b20(CDialog *param_1,uint param_2)

{
  CNameAndStateArray::~CNameAndStateArray((CNameAndStateArray *)(param_1 + 0x470));
  FUN_18000d3f0((CButton *)(param_1 + 0x348));
  FUN_18000d3f0((CButton *)(param_1 + 0x220));
  CListBox::~CListBox((CListBox *)(param_1 + 0x130));
  CDialog::~CDialog(param_1);
  if ((param_2 & 1) != 0) {
    if ((param_2 & 4) == 0) {
      operator_delete(param_1);
      return param_1;
    }
    operator_delete(param_1);
  }
  return param_1;
}

/* ---- FUNC 00022BB0 FUN_180022bb0 (78 bytes) ---- */

CListBox * FUN_180022bb0(CListBox *param_1,uint param_2)

{
  CListBox::~CListBox(param_1);
  if ((param_2 & 1) != 0) {
    if ((param_2 & 4) == 0) {
      operator_delete(param_1);
      return param_1;
    }
    operator_delete(param_1);
  }
  return param_1;
}

/* ---- FUNC 00022C00 FUN_180022c00 (78 bytes) ---- */

CButton * FUN_180022c00(CButton *param_1,uint param_2)

{
  FUN_18000d3f0(param_1);
  if ((param_2 & 1) != 0) {
    if ((param_2 & 4) == 0) {
      operator_delete(param_1);
      return param_1;
    }
    operator_delete(param_1);
  }
  return param_1;
}

/* ---- FUNC 00022C50 FUN_180022c50 (13 bytes) ---- */

void FUN_180022c50(longlong param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000180022c56. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EnableWindow(*(undefined8 *)(param_1 + 0x40),0);
  return;
}

/* ---- FUNC 00022C60 FUN_180022c60 (8 bytes) ---- */

void FUN_180022c60(CDialog *param_1,ushort param_2,CWnd *param_3)

{
  CDialog::Create(param_1,(char *)(ulonglong)param_2,param_3);
  return;
}

/* ---- FUNC 00022C70 FUN_180022c70 (66 bytes) ---- */

void FUN_180022c70(longlong param_1,CDataExchange *param_2)

{
  DDX_Control(param_2,0x4002,(CWnd *)(param_1 + 0x220));
  DDX_Control(param_2,0x4003,(CWnd *)(param_1 + 0x348));
  return;
}

/* ---- FUNC 00022CC0 FUN_180022cc0 (16 bytes) ---- */

void FUN_180022cc0(longlong param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000180022cc9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EnableWindow(*(undefined8 *)(param_1 + 0x40),1);
  return;
}

/* ---- FUNC 00022CD0 FUN_180022cd0 (263 bytes) ---- */

void FUN_180022cd0(longlong param_1,CPtrArray *param_2)

{
  undefined4 uVar1;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar2;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this;
  longlong lVar3;
  int iVar4;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res8 [16];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_res18;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_res20;
  
  iVar4 = 0;
  if (0 < *(longlong *)(param_1 + 0x480)) {
    lVar3 = 0;
    do {
      pCVar2 = operator_new(0x10);
      local_res18 = pCVar2;
      if (pCVar2 == (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
        pCVar2 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
      }
      else {
        local_res20 = local_res8;
        if ((lVar3 < 0) || (*(longlong *)(param_1 + 0x480) <= lVar3)) {
                    /* WARNING: Subroutine does not return */
          AfxThrowInvalidArgException();
        }
        this = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
               ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
               CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                         (local_res8,
                          *(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                            **)(*(longlong *)(param_1 + 0x478) + lVar3 * 8));
        if (*(longlong *)(param_1 + 0x480) <= lVar3) {
                    /* WARNING: Subroutine does not return */
          AfxThrowInvalidArgException();
        }
        uVar1 = *(undefined4 *)(*(longlong *)(*(longlong *)(param_1 + 0x478) + lVar3 * 8) + 8);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar2);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  (pCVar2,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                           *)this);
        *(undefined4 *)(pCVar2 + 8) = uVar1;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(this);
      }
      CPtrArray::SetAtGrow(param_2,*(__int64 *)(param_2 + 0x10),pCVar2);
      iVar4 = iVar4 + 1;
      lVar3 = lVar3 + 1;
    } while ((longlong)iVar4 < *(longlong *)(param_1 + 0x480));
  }
  return;
}

/* ---- FUNC 00022DE0 thunk_FUN_180022df0 (5 bytes) ---- */

undefined ** thunk_FUN_180022df0(void)

{
  return &PTR_LAB_180055080;
}

/* ---- FUNC 00022DF0 FUN_180022df0 (8 bytes) ---- */

undefined ** FUN_180022df0(void)

{
  return &PTR_LAB_180055080;
}

/* ---- FUNC 00022E00 FUN_180022e00 (467 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
FUN_180022e00(longlong param_1,ulonglong param_2,ulonglong param_3,ulonglong param_4,uint param_5)

{
  int iVar1;
  HINSTANCE__ *pHVar2;
  HBITMAP pHVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_98 [32];
  _COLORMAP local_68;
  undefined4 local_60;
  DWORD local_5c;
  undefined4 local_58;
  DWORD local_54;
  ulonglong local_50;
  
  local_50 = DAT_1800791f8 ^ (ulonglong)auStackY_98;
  local_68.from = 0x808080;
  local_68.to = GetSysColor(0x10);
  local_60 = 0xc0c0c0;
  local_5c = GetSysColor(0xf);
  local_58 = 0xdfdfdf;
  local_54 = GetSysColor(0x16);
  CGdiObject::DeleteObject((CGdiObject *)(param_1 + 0xe8));
  CGdiObject::DeleteObject((CGdiObject *)(param_1 + 0xf8));
  CGdiObject::DeleteObject((CGdiObject *)(param_1 + 0x108));
  CGdiObject::DeleteObject((CGdiObject *)(param_1 + 0x118));
  pHVar2 = AfxFindResourceHandle((char *)(param_2 & 0xffff),(char *)0x2);
  pHVar3 = CreateMappedBitmap(pHVar2,param_2 & 0xffffffff,0,&local_68,3);
  iVar1 = CGdiObject::Attach((CGdiObject *)(param_1 + 0xe8),pHVar3);
  uVar5 = 0;
  uVar4 = uVar5;
  if (iVar1 != 0) {
    uVar4 = 1;
    if ((int)param_3 != 0) {
      pHVar2 = AfxFindResourceHandle((char *)(param_3 & 0xffff),(char *)0x2);
      pHVar3 = CreateMappedBitmap(pHVar2,param_3 & 0xffffffff,0,&local_68,3);
      iVar1 = CGdiObject::Attach((CGdiObject *)(param_1 + 0xf8),pHVar3);
      uVar4 = 1;
      if (iVar1 == 0) {
        uVar4 = uVar5;
      }
    }
    if ((int)param_4 != 0) {
      pHVar2 = AfxFindResourceHandle((char *)(param_4 & 0xffff),(char *)0x2);
      pHVar3 = CreateMappedBitmap(pHVar2,param_4 & 0xffffffff,0,&local_68,3);
      iVar1 = CGdiObject::Attach((CGdiObject *)(param_1 + 0x108),pHVar3);
      if (iVar1 == 0) {
        uVar4 = uVar5;
      }
    }
    if (param_5 != 0) {
      pHVar2 = AfxFindResourceHandle((char *)(ulonglong)(param_5 & 0xffff),(char *)0x2);
      pHVar3 = CreateMappedBitmap(pHVar2,(ulonglong)param_5,0,&local_68,3);
      iVar1 = CGdiObject::Attach((CGdiObject *)(param_1 + 0x118),pHVar3);
      if (iVar1 == 0) {
        uVar4 = uVar5;
      }
    }
  }
  return uVar4;
}

/* ---- FUNC 00022FE0 FUN_180022fe0 (264 bytes) ---- */

void FUN_180022fe0(longlong param_1)

{
  int iVar1;
  ulonglong uVar2;
  LRESULT LVar3;
  int iVar4;
  LPARAM local_res8;
  
  uVar2 = SendMessageA(*(HWND *)(param_1 + 0x170),0x188,0,0);
  LVar3 = SendMessageA(*(HWND *)(param_1 + 0x170),0x18b,0,0);
  iVar4 = (int)uVar2;
  if (iVar4 < (int)LVar3 + -1) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8);
    CListBox::GetText((CListBox *)(param_1 + 0x130),iVar4,
                      (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8);
    iVar1 = CCheckListBox::GetCheck((CCheckListBox *)(param_1 + 0x130),iVar4);
    SendMessageA(*(HWND *)(param_1 + 0x170),0x182,uVar2 & 0xffffffff,0);
    iVar4 = iVar4 + 1;
    SendMessageA(*(HWND *)(param_1 + 0x170),0x181,(longlong)iVar4,local_res8);
    CCheckListBox::SetCheck((CCheckListBox *)(param_1 + 0x130),iVar4,iVar1);
    SendMessageA(*(HWND *)(param_1 + 0x170),0x186,(longlong)iVar4,0);
    FUN_180023540(param_1);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8);
  }
  return;
}

/* ---- FUNC 000230F0 FUN_1800230f0 (238 bytes) ---- */

void FUN_1800230f0(longlong param_1)

{
  int iVar1;
  ulonglong uVar2;
  int iVar3;
  LPARAM local_res8;
  
  uVar2 = SendMessageA(*(HWND *)(param_1 + 0x170),0x188,0,0);
  iVar3 = (int)uVar2;
  if (0 < iVar3) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8);
    CListBox::GetText((CListBox *)(param_1 + 0x130),iVar3,
                      (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8);
    iVar1 = CCheckListBox::GetCheck((CCheckListBox *)(param_1 + 0x130),iVar3);
    SendMessageA(*(HWND *)(param_1 + 0x170),0x182,uVar2 & 0xffffffff,0);
    iVar3 = iVar3 + -1;
    SendMessageA(*(HWND *)(param_1 + 0x170),0x181,(longlong)iVar3,local_res8);
    CCheckListBox::SetCheck((CCheckListBox *)(param_1 + 0x130),iVar3,iVar1);
    SendMessageA(*(HWND *)(param_1 + 0x170),0x186,(longlong)iVar3,0);
    FUN_180023540(param_1);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8);
  }
  return;
}

/* ---- FUNC 000231E0 OnCancel (5 bytes) ---- */

void __thiscall CDialog::OnCancel(CDialog *this)

{
                    /* WARNING: Could not recover jumptable at 0x0001800465e9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  OnCancel(this);
  return;
}

/* ---- FUNC 000231F0 FUN_1800231f0 (31 bytes) ---- */

undefined8 FUN_1800231f0(void)

{
  MMDisplayHtmlHelp();
  return 1;
}

/* ---- FUNC 00023210 FUN_180023210 (349 bytes) ---- */

undefined8 FUN_180023210(CDialog *param_1)

{
  int iVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  LPARAM local_res8;
  
  CDialog::OnInitDialog(param_1);
  CWnd::SetWindowTextA((CWnd *)param_1,"Palette Categories");
  CWnd::SubclassDlgItem((CWnd *)(param_1 + 0x130),0x4001,(CWnd *)param_1);
  FUN_180022e00((longlong)(param_1 + 0x220),0x4006,0x4009,0x4008,0x4007);
  FUN_180022e00((longlong)(param_1 + 0x348),0x400a,0x400c,0x400b,0x400d);
  uVar2 = 0;
  iVar1 = *(int *)(param_1 + 0x480);
  uVar3 = uVar2;
  if (0 < (longlong)iVar1) {
    do {
      if (((longlong)uVar2 < 0) || (*(longlong *)(param_1 + 0x480) <= (longlong)uVar2)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8,
                 *(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> **)
                  (*(longlong *)(param_1 + 0x478) + uVar2 * 8));
      SendMessageA(*(HWND *)(param_1 + 0x170),0x180,0,local_res8);
      if (*(longlong *)(param_1 + 0x480) <= (longlong)uVar2) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      CCheckListBox::SetCheck
                ((CCheckListBox *)(param_1 + 0x130),(int)uVar3,
                 *(int *)(*(longlong *)(*(longlong *)(param_1 + 0x478) + uVar2 * 8) + 8));
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8);
      uVar2 = uVar2 + 1;
      uVar3 = (ulonglong)((int)uVar3 + 1);
    } while ((longlong)uVar2 < (longlong)iVar1);
  }
  SendMessageA(*(HWND *)(param_1 + 0x170),0x186,0,0);
  FUN_180023540((longlong)param_1);
  return 1;
}

/* ---- FUNC 00023370 FUN_180023370 (397 bytes) ---- */

void FUN_180023370(CDialog *param_1)

{
  int iVar1;
  LRESULT LVar2;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar3;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar4;
  int iVar5;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar6;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res8 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res10 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res18 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_res20;
  
  CNameAndStateArray::RemoveAndDeleteAll((CNameAndStateArray *)(param_1 + 0x470));
  LVar2 = SendMessageA(*(HWND *)(param_1 + 0x170),0x18b,0,0);
  pCVar6 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
  pCVar4 = pCVar6;
  if (0 < (int)LVar2) {
    do {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res8);
      iVar5 = (int)pCVar4;
      CListBox::GetText((CListBox *)(param_1 + 0x130),iVar5,local_res8);
      iVar1 = CCheckListBox::GetCheck((CCheckListBox *)(param_1 + 0x130),iVar5);
      pCVar4 = pCVar6;
      if (iVar1 == 1) {
        pCVar3 = operator_new(0x10);
        local_res20 = pCVar3;
        if (pCVar3 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
          pCVar4 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                   ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                   CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                             (local_res10,
                              (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                               *)local_res8);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar3);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    (pCVar3,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                             *)pCVar4);
          *(undefined4 *)(pCVar3 + 8) = 1;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar4);
          pCVar4 = pCVar3;
        }
      }
      else {
        pCVar3 = operator_new(0x10);
        if (pCVar3 != (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
          pCVar4 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                   ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                   CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                             (local_res18,
                              (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                               *)local_res8);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar3);
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    (pCVar3,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                             *)pCVar4);
          *(undefined4 *)(pCVar3 + 8) = 0;
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar4);
          pCVar4 = pCVar3;
        }
      }
      CPtrArray::SetAtGrow((CPtrArray *)(param_1 + 0x470),*(__int64 *)(param_1 + 0x480),pCVar4);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res8);
      pCVar4 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
               (ulonglong)(iVar5 + 1U);
    } while ((int)(iVar5 + 1U) < (int)LVar2);
  }
  CDialog::OnOK(param_1);
  return;
}

/* ---- FUNC 00023500 FUN_180023500 (56 bytes) ---- */

void FUN_180023500(longlong param_1)

{
  LRESULT LVar1;
  
  LVar1 = SendMessageA(*(HWND *)(param_1 + 0x170),0x188,0,0);
  if (-1 < (int)LVar1) {
    FUN_180023540(param_1);
    return;
  }
  return;
}

/* ---- FUNC 00023540 FUN_180023540 (198 bytes) ---- */

void FUN_180023540(longlong param_1)

{
  LRESULT LVar1;
  LRESULT LVar2;
  int iVar3;
  int iVar4;
  
  LVar1 = SendMessageA(*(HWND *)(param_1 + 0x170),0x18b,0,0);
  if (((int)LVar1 == 0) ||
     (LVar1 = SendMessageA(*(HWND *)(param_1 + 0x170),0x18b,0,0), (int)LVar1 == 1)) {
    iVar4 = 0;
    iVar3 = iVar4;
  }
  else {
    LVar1 = SendMessageA(*(HWND *)(param_1 + 0x170),0x188,0,0);
    LVar2 = SendMessageA(*(HWND *)(param_1 + 0x170),0x18b,0,0);
    if ((int)LVar1 == (int)LVar2 + -1) {
      iVar4 = 0;
      iVar3 = 1;
    }
    else if ((int)LVar1 == 0) {
      iVar4 = 1;
      iVar3 = 0;
    }
    else {
      iVar4 = 1;
      iVar3 = iVar4;
    }
  }
  CWnd::EnableWindow((CWnd *)(param_1 + 0x220),iVar3);
  CWnd::EnableWindow((CWnd *)(param_1 + 0x348),iVar4);
  return;
}

/* ---- FUNC 00023610 FUN_180023610 (240 bytes) ---- */

void FUN_180023610(longlong param_1,longlong param_2)

{
  undefined4 uVar1;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar2;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *this;
  longlong lVar3;
  int iVar4;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res10 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_res18;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_res20;
  
  iVar4 = 0;
  if (0 < *(longlong *)(param_2 + 0x10)) {
    lVar3 = 0;
    do {
      pCVar2 = operator_new(0x10);
      local_res18 = pCVar2;
      if (pCVar2 == (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0) {
        pCVar2 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)0x0;
      }
      else {
        local_res20 = local_res10;
        if ((lVar3 < 0) || (*(longlong *)(param_2 + 0x10) <= lVar3)) {
                    /* WARNING: Subroutine does not return */
          AfxThrowInvalidArgException();
        }
        this = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
               ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
               CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                         (local_res10,
                          *(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                            **)(*(longlong *)(param_2 + 8) + lVar3 * 8));
        if (*(longlong *)(param_2 + 0x10) <= lVar3) {
                    /* WARNING: Subroutine does not return */
          AfxThrowInvalidArgException();
        }
        uVar1 = *(undefined4 *)(*(longlong *)(*(longlong *)(param_2 + 8) + lVar3 * 8) + 8);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(pCVar2);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                  (pCVar2,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                           *)this);
        *(undefined4 *)(pCVar2 + 8) = uVar1;
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(this);
      }
      CPtrArray::SetAtGrow((CPtrArray *)(param_1 + 0x470),*(__int64 *)(param_1 + 0x480),pCVar2);
      iVar4 = iVar4 + 1;
      lVar3 = lVar3 + 1;
    } while ((longlong)iVar4 < *(longlong *)(param_2 + 0x10));
  }
  return;
}

/* ---- FUNC 00023710 InitializeCriticalSectionEx (7 bytes) ---- */

BOOL __stdcall
InitializeCriticalSectionEx(LPCRITICAL_SECTION lpCriticalSection,DWORD dwSpinCount,DWORD Flags)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180023710. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = InitializeCriticalSectionEx(lpCriticalSection,dwSpinCount,Flags);
  return BVar1;
}

/* ---- FUNC 00023720 real2bstr (329 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void real2bstr(double param_1,short param_2,undefined8 param_3,undefined8 param_4)

{
  char *pcVar1;
  code *pcVar2;
  uint uVar3;
  char *pcVar4;
  uint uVar5;
  ulonglong uVar6;
  double _X;
  double dVar7;
  undefined1 auStack_d8 [32];
  undefined1 local_b8 [16];
  char local_a8 [112];
  ulonglong local_38;
  
                    /* 0x23720  549  real2bstr */
  local_38 = DAT_1800791f8 ^ (ulonglong)auStack_d8;
  uVar5 = (int)param_2 - 1;
  if (0.0 <= param_1) {
    uVar5 = (uint)param_2;
  }
  _X = log10((double)CONCAT44((uint)((ulonglong)param_1 >> 0x20) & _UNK_1800550d4,
                              SUB84(param_1,0) & _DAT_1800550d0));
  dVar7 = ceil(_X);
  uVar3 = uVar5 - 1;
  if ((int)dVar7 == uVar5) {
    uVar3 = uVar5;
  }
  uVar6 = (ulonglong)uVar3;
  if (((_X < DAT_1800550c8) || ((double)(int)uVar3 <= _X)) &&
     (uVar6 = (ulonglong)(uVar3 - 4),
     _DAT_1800550c0 <=
     (double)CONCAT44((uint)((ulonglong)_X >> 0x20) & _UNK_1800550d4,SUB84(_X,0) & _DAT_1800550d0)))
  {
    uVar6 = (ulonglong)(uVar3 - 5);
  }
  FUN_180007de0(local_b8,"%%.%dg",uVar6,param_4);
  FUN_180007de0(local_a8,local_b8,param_1,param_4);
  pcVar4 = local_a8;
  while (local_a8[0] != '\0') {
    if (local_a8[0] == 'e') {
      pcVar4 = pcVar4 + 2;
      if (*pcVar4 == '0') {
        do {
          pcVar1 = pcVar4 + 1;
          *pcVar4 = *pcVar1;
          pcVar4 = pcVar4 + 1;
        } while (*pcVar1 != '\0');
      }
    }
    else {
      pcVar4 = pcVar4 + 1;
    }
    local_a8[0] = *pcVar4;
  }
  if ((ulonglong)(longlong)param_2 < 100) {
    local_a8[param_2] = '\0';
    SysAllocStringByteLen(local_a8,(int)param_2);
    return;
  }
  FUN_180046e94();
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}

/* ---- FUNC 00023870 FUN_180023870 (35 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_180023870(void)

{
  HMODULE hModule;
  longlong local_28;
  ulonglong uStack_20;
  undefined8 local_18;
  undefined8 local_10;
  
  if (DAT_18007a798 == 1) {
    return 0;
  }
  local_18 = 10;
  local_28 = DAT_1800550e8;
  local_10 = 0xf;
  uStack_20 = (ulonglong)DAT_1800550f0;
  hModule = FUN_18000da20(&local_28);
  if (hModule == (HMODULE)0x0) {
    AfxMessageBox("Can\'t load libbz2.dll",0,0);
    return 0xffffffff;
  }
  DAT_18007a798 = 1;
  _DAT_18007a7a0 = hModule;
  DAT_18007a748 = GetProcAddress(hModule,"BZ2_bzBuffToBuffCompress");
  DAT_18007a750 = GetProcAddress(hModule,"BZ2_bzBuffToBuffDecompress");
  return 0;
}

/* ---- FUNC 00023893 FUN_180023893 (95 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_180023893(longlong *param_1)

{
  ushort in_AX;
  HMODULE hModule;
  undefined8 in_XMM0_Qb;
  uint3 uStack0000000000000028;
  undefined5 uStack000000000000002b;
  undefined8 uStack0000000000000030;
  undefined8 uStack0000000000000038;
  
  uStack0000000000000030 = 10;
  uStack0000000000000038 = 0xf;
  uStack000000000000002b = (undefined5)((ulonglong)in_XMM0_Qb >> 0x18);
  uStack0000000000000028 = (uint3)in_AX;
  hModule = FUN_18000da20(param_1);
  if (hModule == (HMODULE)0x0) {
    AfxMessageBox("Can\'t load libbz2.dll",0,0);
    return 0xffffffff;
  }
  DAT_18007a798 = 1;
  _DAT_18007a7a0 = hModule;
  DAT_18007a748 = GetProcAddress(hModule,"BZ2_bzBuffToBuffCompress");
  DAT_18007a750 = GetProcAddress(hModule,"BZ2_bzBuffToBuffDecompress");
  return 0;
}

/* ---- FUNC 000238F2 FUN_1800238f2 (75 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_1800238f2(void)

{
  HMODULE unaff_RBX;
  
  DAT_18007a798 = 1;
  _DAT_18007a7a0 = unaff_RBX;
  DAT_18007a748 = GetProcAddress(unaff_RBX,"BZ2_bzBuffToBuffCompress");
  DAT_18007a750 = GetProcAddress(unaff_RBX,"BZ2_bzBuffToBuffDecompress");
  return 0;
}

/* ---- FUNC 00023940 FUN_180023940 (478 bytes) ---- */

void FUN_180023940(CSimpleStringT<char,1> *param_1)

{
  uint uVar1;
  ulonglong uVar2;
  int iVar3;
  void *pvVar4;
  char *_Dest;
  char *_Source;
  undefined1 *puVar5;
  void *pvVar6;
  undefined1 *puVar7;
  ulonglong uVar8;
  uint local_res10 [2];
  char *local_res18;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res20 [8];
  
  if (DAT_18007a798 != 0) {
    uVar1 = *(uint *)(*(longlong *)param_1 + -0x10);
    local_res10[0] = uVar1 + 0x400;
    pvVar4 = operator_new__((ulonglong)local_res10[0]);
    _Dest = operator_new__((ulonglong)uVar1);
    _Source = ATL::CSimpleStringT<char,1>::GetBuffer(param_1,uVar1);
    strncpy(_Dest,_Source,(ulonglong)uVar1);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res20);
    iVar3 = (*DAT_18007a748)(pvVar4,local_res10,_Dest,uVar1,1,0,0);
    if (iVar3 == 0) {
      iVar3 = local_res10[0] / 3 + 1;
      uVar1 = iVar3 * 3;
      uVar8 = (ulonglong)uVar1;
      *(undefined1 *)((ulonglong)(local_res10[0] + 2) + (longlong)pvVar4) = 0;
      *(undefined1 *)((ulonglong)(local_res10[0] + 1) + (longlong)pvVar4) = 0;
      *(undefined1 *)((ulonglong)local_res10[0] + (longlong)pvVar4) = 0;
      puVar5 = operator_new__((ulonglong)uVar1);
      uVar2 = (ulonglong)(uint)(iVar3 * 0xc) / 3;
      pvVar6 = operator_new__(uVar2);
      if (uVar1 != 0) {
        puVar7 = puVar5;
        do {
          *puVar7 = puVar7[(longlong)pvVar4 - (longlong)puVar5];
          puVar7 = puVar7 + 1;
          uVar8 = uVar8 - 1;
        } while (uVar8 != 0);
      }
      FUN_180042210((longlong)puVar5,(longlong)pvVar6,uVar1);
      FUN_180023ee0(param_1,(longlong)pvVar6,(int)uVar2);
      operator_delete__(puVar5);
      operator_delete__(pvVar6);
    }
    else {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res18);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res18,
                 "Error compressing:  %d\n");
      AfxMessageBox(local_res18,0,0);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res18);
    }
    operator_delete__(pvVar4);
    operator_delete__(_Dest);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res20);
  }
  return;
}

/* ---- FUNC 00023B20 FUN_180023b20 (627 bytes) ---- */

void FUN_180023b20(CSimpleStringT<char,1> *param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  void *pvVar4;
  undefined1 *puVar5;
  void *pvVar6;
  char *pcVar7;
  undefined1 *puVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  uint uVar11;
  longlong lVar13;
  uint local_res10 [2];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res18 [8];
  char *local_res20;
  ulonglong uVar12;
  
  if ((DAT_18007a798 != 0) && (*(int *)(*(longlong *)param_1 + -0x10) != 0)) {
    iVar3 = *(int *)(*(longlong *)param_1 + -0x10) * 3;
    uVar2 = (int)(iVar3 + (iVar3 >> 0x1f & 3U)) >> 2;
    local_res10[0] = uVar2 * 10;
    pvVar4 = operator_new__((ulonglong)local_res10[0]);
    uVar10 = (ulonglong)uVar2;
    puVar5 = operator_new__((ulonglong)uVar2);
    pvVar6 = operator_new__((ulonglong)(uVar2 + 1));
    pcVar7 = operator_new__((longlong)*(int *)(*(longlong *)param_1 + -0x10) + 1);
    uVar9 = 0;
    lVar13 = *(longlong *)param_1;
    uVar12 = uVar9;
    local_res20 = pcVar7;
    if (0 < *(int *)(lVar13 + -0x10)) {
      do {
        cVar1 = ATL::CSimpleStringT<char,1>::GetAt(param_1,(int)uVar12);
        *pcVar7 = cVar1;
        uVar11 = (int)uVar12 + 1;
        uVar12 = (ulonglong)uVar11;
        pcVar7 = pcVar7 + 1;
        lVar13 = *(longlong *)param_1;
      } while ((int)uVar11 < *(int *)(lVar13 + -0x10));
    }
    pcVar7 = local_res20;
    FUN_180042320((longlong)local_res20,(longlong)pvVar6,*(int *)(lVar13 + -0x10));
    if (0 < (int)uVar2) {
      puVar8 = puVar5;
      do {
        *puVar8 = puVar8[(longlong)pvVar6 - (longlong)puVar5];
        puVar8 = puVar8 + 1;
        uVar10 = uVar10 - 1;
      } while (uVar10 != 0);
    }
    operator_delete__(pcVar7);
    operator_delete__(pvVar6);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res18);
    iVar3 = (*DAT_18007a750)(pvVar4,local_res10,puVar5,uVar2,0,0);
    while (iVar3 == -8) {
      operator_delete__(pvVar4);
      local_res10[0] = local_res10[0] * 2;
      pvVar4 = operator_new__((ulonglong)local_res10[0]);
      iVar3 = (*DAT_18007a750)(pvVar4,local_res10,puVar5,uVar2,0,0);
    }
    if (iVar3 == 0) {
      pcVar7 = ATL::CSimpleStringT<char,1>::GetBuffer
                         ((CSimpleStringT<char,1> *)local_res18,local_res10[0]);
      if (local_res10[0] != 0) {
        do {
          pcVar7[uVar9] = *(char *)(uVar9 + (longlong)pvVar4);
          uVar2 = (int)uVar9 + 1;
          uVar9 = (ulonglong)uVar2;
        } while (uVar2 < local_res10[0]);
      }
      ATL::CSimpleStringT<char,1>::ReleaseBuffer
                ((CSimpleStringT<char,1> *)local_res18,local_res10[0]);
      FUN_180023e70(param_1,(CSimpleStringT<char,1> *)local_res18);
    }
    else {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20,
                 "Error decompressing:  %d\n");
      AfxMessageBox(local_res20,0,0);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res20);
    }
    operator_delete__(pvVar4);
    operator_delete__(puVar5);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res18);
  }
  return;
}

/* ---- FUNC 00023DA0 FUN_180023da0 (58 bytes) ---- */

bool FUN_180023da0(CSimpleStringT<char,1> *param_1)

{
  longlong lVar1;
  
  lVar1 = FUN_180023e20(param_1);
  if ((char)lVar1 == '\0') {
    FUN_180023870();
    FUN_180023940(param_1);
    lVar1 = FUN_180023e20(param_1);
    return (char)lVar1 != '\0';
  }
  return true;
}

/* ---- FUNC 00023DE0 FUN_180023de0 (58 bytes) ---- */

bool FUN_180023de0(CSimpleStringT<char,1> *param_1)

{
  longlong lVar1;
  
  lVar1 = FUN_180023e20(param_1);
  if ((char)lVar1 != '\0') {
    FUN_180023870();
    FUN_180023b20(param_1);
    lVar1 = FUN_180023e20(param_1);
    return (char)lVar1 == '\0';
  }
  return true;
}

/* ---- FUNC 00023E20 FUN_180023e20 (69 bytes) ---- */

longlong FUN_180023e20(CSimpleStringT<char,1> *param_1)

{
  char *pcVar1;
  uint7 uVar2;
  longlong lVar3;
  
  pcVar1 = ATL::CSimpleStringT<char,1>::GetBuffer(param_1,0xe);
  lVar3 = 0;
  do {
    uVar2 = (uint7)((ulonglong)(pcVar1 + -0x180055150) >> 8);
    if ((&DAT_180055150)[lVar3] != (pcVar1 + -0x180055150)[(longlong)(&DAT_180055150 + lVar3)]) {
      return (ulonglong)uVar2 << 8;
    }
    lVar3 = lVar3 + 1;
  } while (lVar3 < 0xd);
  return CONCAT71(uVar2,1);
}

/* ---- FUNC 00023E70 FUN_180023e70 (111 bytes) ---- */

void FUN_180023e70(CSimpleStringT<char,1> *param_1,CSimpleStringT<char,1> *param_2)

{
  char cVar1;
  char *pcVar2;
  longlong lVar3;
  int iVar4;
  
  pcVar2 = ATL::CSimpleStringT<char,1>::GetBuffer(param_1,*(int *)(*(longlong *)param_2 + -0x10));
  lVar3 = *(longlong *)param_2;
  iVar4 = 0;
  if (0 < *(int *)(lVar3 + -0x10)) {
    do {
      cVar1 = ATL::CSimpleStringT<char,1>::GetAt(param_2,iVar4);
      *pcVar2 = cVar1;
      iVar4 = iVar4 + 1;
      lVar3 = *(longlong *)param_2;
      pcVar2 = pcVar2 + 1;
    } while (iVar4 < *(int *)(lVar3 + -0x10));
  }
                    /* WARNING: Could not recover jumptable at 0x000180023ed8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CSimpleStringT<char,1>::ReleaseBuffer(param_1,*(int *)(lVar3 + -0x10));
  return;
}

/* ---- FUNC 00023EE0 FUN_180023ee0 (91 bytes) ---- */

void FUN_180023ee0(CSimpleStringT<char,1> *param_1,longlong param_2,int param_3)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  
  lVar3 = (longlong)param_3;
  pcVar1 = ATL::CSimpleStringT<char,1>::GetBuffer(param_1,param_3);
  if (0 < param_3) {
    lVar2 = param_2 - (longlong)pcVar1;
    do {
      *pcVar1 = pcVar1[lVar2];
      pcVar1 = pcVar1 + 1;
      lVar3 = lVar3 + -1;
    } while (lVar3 != 0);
  }
                    /* WARNING: Could not recover jumptable at 0x000180023f34. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CSimpleStringT<char,1>::ReleaseBuffer(param_1,param_3);
  return;
}

/* ---- FUNC 00023F40 MMCompressText (85 bytes) ---- */

void MMCompressText(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_1,
                   CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_2)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res18 [16];
  
                    /* 0x23f40  374  MMCompressText */
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            (local_res18,
             (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)param_1);
  FUN_180023da0((CSimpleStringT<char,1> *)local_res18);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            (param_2,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                     local_res18);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res18);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1);
  return;
}

/* ---- FUNC 00023FA0 MMDecompressText (85 bytes) ---- */

void MMDecompressText(CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_1,
                     CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_2)

{
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res18 [16];
  
                    /* 0x23fa0  381  MMDecompressText */
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            (local_res18,
             (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)param_1);
  FUN_180023de0((CSimpleStringT<char,1> *)local_res18);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            (param_2,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                     local_res18);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res18);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1);
  return;
}

/* ---- FUNC 00024000 FUN_180024000 (101 bytes) ---- */

void FUN_180024000(void)

{
  longlong local_28;
  undefined4 local_20;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined2 local_1a;
  undefined8 local_18;
  undefined8 local_10;
  
  if (DAT_18007a7a8 == (HMODULE)0x0) {
    local_1a = 0;
    local_20 = DAT_1800551a0;
    local_1c = DAT_1800551a4;
    local_18 = 0xd;
    local_10 = 0xf;
    local_28 = DAT_180055198;
    local_1b = 0;
    DAT_18007a7a8 = FUN_18000da20(&local_28);
  }
  return;
}

/* ---- FUNC 00024070 FUN_180024070 (52 bytes) ---- */

INT_PTR FUN_180024070(void)

{
  HMODULE hModule;
  FARPROC UNRECOVERED_JUMPTABLE;
  INT_PTR IVar1;
  INT_PTR local_res8;
  
  hModule = (HMODULE)FUN_180024000();
  if (hModule != (HMODULE)0x0) {
    UNRECOVERED_JUMPTABLE = GetProcAddress(hModule,"MVGetI18nProductName");
    if (UNRECOVERED_JUMPTABLE != (FARPROC)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000180024097. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      IVar1 = (*UNRECOVERED_JUMPTABLE)();
      return IVar1;
    }
  }
  return local_res8;
}

/* ---- FUNC 000240B0 FUN_1800240b0 (51 bytes) ---- */

ulonglong FUN_1800240b0(void)

{
  HMODULE hModule;
  FARPROC UNRECOVERED_JUMPTABLE;
  ulonglong uVar1;
  uint local_res8;
  
  hModule = (HMODULE)FUN_180024000();
  if (hModule != (HMODULE)0x0) {
    UNRECOVERED_JUMPTABLE = GetProcAddress(hModule,"MVGetProductCode");
    if (UNRECOVERED_JUMPTABLE != (FARPROC)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0001800240d7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar1 = (*UNRECOVERED_JUMPTABLE)();
      return uVar1;
    }
  }
  return (ulonglong)local_res8;
}

/* ---- FUNC 000240F0 FUN_1800240f0 (52 bytes) ---- */

INT_PTR FUN_1800240f0(void)

{
  HMODULE hModule;
  FARPROC UNRECOVERED_JUMPTABLE;
  INT_PTR IVar1;
  INT_PTR local_res8;
  
  hModule = (HMODULE)FUN_180024000();
  if (hModule != (HMODULE)0x0) {
    UNRECOVERED_JUMPTABLE = GetProcAddress(hModule,"MVGetProductName");
    if (UNRECOVERED_JUMPTABLE != (FARPROC)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000180024117. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      IVar1 = (*UNRECOVERED_JUMPTABLE)();
      return IVar1;
    }
  }
  return local_res8;
}

/* ---- FUNC 00024130 FUN_180024130 (52 bytes) ---- */

INT_PTR FUN_180024130(void)

{
  HMODULE hModule;
  FARPROC UNRECOVERED_JUMPTABLE;
  INT_PTR IVar1;
  INT_PTR local_res8;
  
  hModule = (HMODULE)FUN_180024000();
  if (hModule != (HMODULE)0x0) {
    UNRECOVERED_JUMPTABLE = GetProcAddress(hModule,"MVGetProductRegistryName");
    if (UNRECOVERED_JUMPTABLE != (FARPROC)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000180024157. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      IVar1 = (*UNRECOVERED_JUMPTABLE)();
      return IVar1;
    }
  }
  return local_res8;
}

/* ---- FUNC 00024170 FUN_180024170 (52 bytes) ---- */

INT_PTR FUN_180024170(void)

{
  HMODULE hModule;
  FARPROC UNRECOVERED_JUMPTABLE;
  INT_PTR IVar1;
  INT_PTR local_res8;
  
  hModule = (HMODULE)FUN_180024000();
  if (hModule != (HMODULE)0x0) {
    UNRECOVERED_JUMPTABLE = GetProcAddress(hModule,"MVGetRegistryKey");
    if (UNRECOVERED_JUMPTABLE != (FARPROC)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000180024197. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      IVar1 = (*UNRECOVERED_JUMPTABLE)();
      return IVar1;
    }
  }
  return local_res8;
}

/* ---- FUNC 000241B0 FUN_1800241b0 (52 bytes) ---- */

INT_PTR FUN_1800241b0(void)

{
  HMODULE hModule;
  FARPROC UNRECOVERED_JUMPTABLE;
  INT_PTR IVar1;
  INT_PTR local_res8;
  
  hModule = (HMODULE)FUN_180024000();
  if (hModule != (HMODULE)0x0) {
    UNRECOVERED_JUMPTABLE = GetProcAddress(hModule,"MVGetVersionString");
    if (UNRECOVERED_JUMPTABLE != (FARPROC)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0001800241d7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      IVar1 = (*UNRECOVERED_JUMPTABLE)();
      return IVar1;
    }
  }
  return local_res8;
}

/* ---- FUNC 000241F0 DeleteTempFile (119 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

BOOL DeleteTempFile(LPCSTR param_1)

{
  int iVar1;
  BOOL BVar2;
  undefined1 auStack_68 [32];
  undefined1 local_48 [48];
  ulonglong local_18;
  
                    /* 0x241f0  343  DeleteTempFile */
  local_18 = DAT_1800791f8 ^ (ulonglong)auStack_68;
  if (param_1 == (LPCSTR)0x0) {
    return -1;
  }
  iVar1 = _stat64i32(param_1,local_48);
  if (iVar1 == -1) {
    return 2;
  }
  BVar2 = DeleteFileA(param_1);
  return BVar2;
}

/* ---- FUNC 00024270 GetEditorTempFileName (166 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 GetEditorTempFileName(longlong param_1)

{
  char cVar1;
  DWORD DVar2;
  UINT UVar3;
  char *pcVar4;
  undefined1 auStack_258 [32];
  CHAR local_238 [272];
  CHAR local_128 [272];
  ulonglong local_18;
  
                    /* 0x24270  359  GetEditorTempFileName */
  local_18 = DAT_1800791f8 ^ (ulonglong)auStack_258;
  if (param_1 != 0) {
    DVar2 = GetTempPathA(0x104,local_128);
    if ((DVar2 != 0) && (UVar3 = GetTempFileNameA(local_128,"~AP",0,local_238), UVar3 != 0)) {
      pcVar4 = local_238;
      do {
        cVar1 = *pcVar4;
        pcVar4[param_1 - (longlong)local_238] = cVar1;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      return 1;
    }
    GetLastError();
  }
  return 0;
}

/* ---- FUNC 00024320 GetEditorTempTxtFileName (332 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 GetEditorTempTxtFileName(longlong param_1)

{
  char cVar1;
  longlong lVar2;
  DWORD DVar3;
  UINT UVar4;
  int iVar5;
  char *pcVar6;
  undefined1 auStack_268 [32];
  char *local_248;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_240 [8];
  CHAR local_238 [272];
  CHAR local_128 [272];
  ulonglong local_18;
  
                    /* 0x24320  360  GetEditorTempTxtFileName */
  local_18 = DAT_1800791f8 ^ (ulonglong)auStack_268;
  if (param_1 != 0) {
    DVar3 = GetTempPathA(0x104,local_128);
    if ((DVar3 != 0) && (UVar4 = GetTempFileNameA(local_128,"~AP",0,local_238), UVar4 != 0)) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_248,
                 local_238);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Right
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_248,
                 (int)local_240);
      iVar5 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                        (local_240,".tmp");
      if (iVar5 == 0) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Replace
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_248,
                   ".tmp",".txt");
        iVar5 = rename(local_238,local_248);
        if (iVar5 == 0) {
          lVar2 = -(longlong)local_248;
          do {
            cVar1 = *local_248;
            local_248[(longlong)(local_238 + lVar2)] = cVar1;
            local_248 = local_248 + 1;
          } while (cVar1 != '\0');
        }
      }
      pcVar6 = local_238;
      do {
        cVar1 = *pcVar6;
        pcVar6[param_1 - (longlong)local_238] = cVar1;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_240);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_248);
      return 1;
    }
    GetLastError();
  }
  return 0;
}

/* ---- FUNC 00024470 ERPureCall (44 bytes) ---- */

void ERPureCall(void)

{
                    /* 0x24470  80  ERPureCall */
  DAT_180072050 = 0x13f2;
  ERProcessDump(DAT_18007204c);
  _set_abort_behavior(0,1);
                    /* WARNING: Subroutine does not return */
  abort();
}

/* ---- FUNC 000244A0 FUN_1800244a0 (689 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_1800244a0(void *param_1)

{
  wchar_t wVar1;
  int iVar2;
  DWORD DVar3;
  wchar_t *lpString2;
  LPCSTR pCVar4;
  wchar_t *pwVar5;
  longlong lVar6;
  undefined1 auStackY_468 [32];
  __time64_t local_430;
  wchar_t *local_428;
  undefined1 local_418 [1008];
  ulonglong local_28;
  
  local_28 = DAT_1800791f8 ^ (ulonglong)auStackY_468;
  _time64(&local_430);
  lpString2 = _wctime64(&local_430);
  pwVar5 = lpString2;
  do {
    wVar1 = *pwVar5;
    local_428 = pwVar5;
    if (wVar1 == L'\0') {
LAB_180024526:
      GetModuleFileNameW((HMODULE)0x0,(LPWSTR)&DAT_18007a9e0,0x208);
      _wsplitpath((wchar_t *)&DAT_18007a9e0,(wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)&DAT_18007abf0,
                  (wchar_t *)0x0);
      lstrcpyW((LPWSTR)&DAT_18007a7d0,(LPCWSTR)&DAT_18007abf0);
      lstrcatW((LPWSTR)&DAT_18007a7d0,L"_ExceptionDump_");
      lstrcatW((LPWSTR)&DAT_18007a7d0,lpString2);
      lstrcatW((LPWSTR)&DAT_18007a7d0,L".dmp");
      DVar3 = GetCurrentThreadId();
      iVar2 = FUN_180027150(DAT_18007204c,(LPCWSTR)&DAT_18007a7d0,DVar3,param_1);
      if (iVar2 != 0) {
        FUN_180007de0(local_418,"Assert failed in file %s line %d",
                      "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\ERDbgUtl.cpp",0xb4);
        LogMessage(local_418,2,1);
        if (iVar2 != 0) {
          return 0;
        }
      }
      pCVar4 = (LPCSTR)FUN_1800240f0();
      if (pCVar4 != (LPCSTR)0x0) {
        lVar6 = -1;
        do {
          lVar6 = lVar6 + 1;
        } while (pCVar4[lVar6] != '\0');
        _DAT_18007b410 = 0;
        MultiByteToWideChar(0,0,pCVar4,-1,(LPWSTR)&DAT_18007b410,(int)lVar6 + 1);
        _DAT_18007b450 = 0;
        pCVar4 = (LPCSTR)MMStructGetSorResStringEx();
        if (pCVar4 != (LPCSTR)0x0) {
          lVar6 = -1;
          do {
            lVar6 = lVar6 + 1;
          } while (pCVar4[lVar6] != '\0');
          MultiByteToWideChar(0,0,pCVar4,-1,(LPWSTR)&DAT_18007b450,(int)lVar6 + 1);
          lstrcpyW((LPWSTR)&DAT_18007b010,(LPCWSTR)&DAT_18007b450);
          pwVar5 = _wgetcwd((wchar_t *)&DAT_18007ae00,0x104);
          lstrcatW((LPWSTR)&DAT_18007b010,pwVar5);
          lstrcatW((LPWSTR)&DAT_18007b010,L"\\");
          lstrcatW((LPWSTR)&DAT_18007b010,(LPCWSTR)&DAT_18007a7d0);
          MessageBoxW((HWND)0x0,(LPCWSTR)&DAT_18007b010,(LPCWSTR)&DAT_18007b410,0x10);
        }
      }
      return 0;
    }
    if ((wVar1 == L' ') || (wVar1 == L':')) {
      *pwVar5 = L'_';
    }
    else {
      iVar2 = isalnum((uint)(ushort)wVar1);
      if (iVar2 == 0) {
        *pwVar5 = L'\0';
        goto LAB_180024526;
      }
    }
    pwVar5 = pwVar5 + 1;
  } while( true );
}

/* ---- FUNC 00024760 FUN_180024760 (71 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_180024760(undefined8 param_1,int param_2)

{
  if (param_2 == 0) {
    if (DAT_18007a7b8 != 0) {
      SetUnhandledExceptionFilter(DAT_18007a7c0);
      DAT_18007a7b8 = 0;
    }
  }
  else if (param_2 == 1) {
    _DAT_18007a7b0 = param_1;
    return 1;
  }
  return 1;
}

/* ---- FUNC 000247B0 ERHookUnhandledExceptionFilter (78 bytes) ---- */

undefined8 ERHookUnhandledExceptionFilter(undefined4 param_1)

{
                    /* 0x247b0  345  ERHookUnhandledExceptionFilter */
  if (DAT_18007a7b8 == 0) {
    DAT_18007204c = param_1;
    DAT_18007a7c0 = SetUnhandledExceptionFilter(FUN_180024ae0);
    DAT_18007a7c8 = _set_purecall_handler(ERPureCall);
    DAT_18007a7b8 = 1;
  }
  return 1;
}

/* ---- FUNC 00024800 ERHookUnhandledExceptionFilterDefault (10 bytes) ---- */

void ERHookUnhandledExceptionFilterDefault(void)

{
                    /* 0x24800  346  ERHookUnhandledExceptionFilterDefault */
  ERHookUnhandledExceptionFilter(4);
  return;
}

/* ---- FUNC 00024810 FUN_180024810 (6 bytes) ---- */

undefined8 FUN_180024810(void)

{
  return 1;
}

/* ---- FUNC 00024820 ERProcessDump (600 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool ERProcessDump(undefined4 param_1)

{
  uint _C;
  int iVar1;
  DWORD DVar2;
  wchar_t *lpString2;
  LPCSTR pCVar3;
  longlong lVar4;
  wchar_t *pwVar5;
  __time64_t local_res10;
  
                    /* 0x24820  347  ERProcessDump */
  _DAT_18007a7d0 = 0;
  _time64(&local_res10);
  lpString2 = _wctime64(&local_res10);
  pwVar5 = lpString2;
  do {
    if (*pwVar5 == L'\0') {
LAB_180024896:
      GetModuleFileNameW((HMODULE)0x0,(LPWSTR)&DAT_18007a9e0,0x208);
      _wsplitpath((wchar_t *)&DAT_18007a9e0,(wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)&DAT_18007abf0,
                  (wchar_t *)0x0);
      lstrcpyW((LPWSTR)&DAT_18007a7d0,(LPCWSTR)&DAT_18007abf0);
      lstrcatW((LPWSTR)&DAT_18007a7d0,L"_ProcessDump_");
      lstrcatW((LPWSTR)&DAT_18007a7d0,lpString2);
      lstrcatW((LPWSTR)&DAT_18007a7d0,L".dmp");
      DVar2 = GetCurrentThreadId();
      iVar1 = FUN_180027150(param_1,(LPCWSTR)&DAT_18007a7d0,DVar2,(void *)0x0);
      if ((iVar1 == 0) && (pCVar3 = (LPCSTR)FUN_1800240f0(), pCVar3 != (LPCSTR)0x0)) {
        lVar4 = -1;
        do {
          lVar4 = lVar4 + 1;
        } while (pCVar3[lVar4] != '\0');
        _DAT_18007b410 = 0;
        MultiByteToWideChar(0,0,pCVar3,-1,(LPWSTR)&DAT_18007b410,(int)lVar4 + 1);
        _DAT_18007b450 = 0;
        pCVar3 = (LPCSTR)MMStructGetSorResStringEx();
        if (pCVar3 != (LPCSTR)0x0) {
          lVar4 = -1;
          do {
            lVar4 = lVar4 + 1;
          } while (pCVar3[lVar4] != '\0');
          MultiByteToWideChar(0,0,pCVar3,-1,(LPWSTR)&DAT_18007b450,(int)lVar4 + 1);
          lstrcpyW((LPWSTR)&DAT_18007b010,(LPCWSTR)&DAT_18007b450);
          pwVar5 = _wgetcwd((wchar_t *)&DAT_18007ae00,0x104);
          lstrcatW((LPWSTR)&DAT_18007b010,pwVar5);
          lstrcatW((LPWSTR)&DAT_18007b010,L"\\");
          lstrcatW((LPWSTR)&DAT_18007b010,(LPCWSTR)&DAT_18007a7d0);
          MessageBoxW((HWND)0x0,(LPCWSTR)&DAT_18007b010,(LPCWSTR)&DAT_18007b410,0x10);
        }
      }
      return iVar1 == 0;
    }
    _C = (uint)(ushort)*pwVar5;
    if ((_C == 0x20) || (_C == 0x3a)) {
      *pwVar5 = L'_';
    }
    else {
      iVar1 = isalnum(_C);
      if (iVar1 == 0) {
        *pwVar5 = L'\0';
        goto LAB_180024896;
      }
    }
    pwVar5 = pwVar5 + 1;
  } while( true );
}

/* ---- FUNC 00024A80 ERProcessDumpDefault (7 bytes) ---- */

void ERProcessDumpDefault(void)

{
                    /* 0x24a80  348  ERProcessDumpDefault */
  ERProcessDump(0);
  return;
}

/* ---- FUNC 00024A90 ERSetIgnoreUnhandledExceptionFilter (76 bytes) ---- */

undefined8 ERSetIgnoreUnhandledExceptionFilter(void)

{
                    /* 0x24a90  349  ERSetIgnoreUnhandledExceptionFilter */
  if (DAT_18007a7b8 != 0) {
    SetUnhandledExceptionFilter(DAT_18007a7c0);
    DAT_18007a7b8 = 0;
  }
  DAT_18007a7c0 = SetUnhandledExceptionFilter(FUN_180024810);
  DAT_18007a7b8 = 1;
  return 1;
}

/* ---- FUNC 00024AE0 FUN_180024ae0 (394 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

DWORD FUN_180024ae0(undefined8 *param_1)

{
  undefined1 auStackY_448 [32];
  DWORD local_418 [4];
  undefined1 local_408 [1008];
  ulonglong local_18;
  
  local_18 = DAT_1800791f8 ^ (ulonglong)auStackY_448;
  local_418[0] = 0;
  if (DAT_18007b540 != 0) goto LAB_180024bef;
  DAT_18007b540 = 1;
  if (((param_1 != (undefined8 *)0x0) && ((int *)*param_1 != (int *)0x0)) &&
     (*(int *)*param_1 == -0x3ffdffff)) {
    DAT_18007b540 = 0;
    return 0;
  }
  if ((*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) + 4)
       < DAT_18007b550) && (FUN_180047094(&DAT_18007b550), DAT_18007b550 == -1)) {
    DAT_18007b548 =
         (HANDLE)_beginthreadex((void *)0x0,0,FUN_1800244a0,param_1,0,(uint *)&DAT_18007b544);
    _Init_thread_footer(&DAT_18007b550);
  }
  if (DAT_18007b548 == (HANDLE)0xffffffffffffffff) {
    FUN_180007de0(local_408,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\ERDbgUtl.cpp",0xf0);
    LogMessage(local_408,2,1);
    if (DAT_18007b548 != (HANDLE)0xffffffffffffffff) goto LAB_180024bb6;
  }
  else {
LAB_180024bb6:
    WaitForSingleObject(DAT_18007b548,0xffffffff);
    GetExitCodeThread(DAT_18007b548,local_418);
    CloseHandle(DAT_18007b548);
  }
  DAT_18007b540 = DAT_18007b540 + -1;
  if (local_418[0] == 0xffffffff) {
    return 0xffffffff;
  }
LAB_180024bef:
  ERSetIgnoreUnhandledExceptionFilter();
  return local_418[0];
}

/* ---- FUNC 00024C70 ERUnhookUnhandledExceptionFilter (58 bytes) ---- */

undefined8 ERUnhookUnhandledExceptionFilter(void)

{
                    /* 0x24c70  350  ERUnhookUnhandledExceptionFilter */
  if (DAT_18007a7b8 != 0) {
    SetUnhandledExceptionFilter(DAT_18007a7c0);
    _set_purecall_handler(DAT_18007a7c8);
    DAT_18007a7b8 = 0;
  }
  return 1;
}

/* ---- FUNC 00024CB0 MMSpreadsheetDuplicateItem (126 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong MMSpreadsheetDuplicateItem(undefined4 param_1)

{
  longlong lVar1;
  HRESULT HVar2;
  uint uVar3;
  int iVar4;
  LCID LVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  undefined1 auStackY_e8 [32];
  longlong *local_98;
  undefined8 local_90;
  undefined4 local_88;
  wchar_t *local_80;
  _union_2707 *local_78;
  undefined8 local_70;
  undefined8 local_68;
  _union_2707 local_60;
  tagVARIANT local_48;
  CLSID local_30;
  ulonglong local_20;
  
                    /* 0x24cb0  409  MMSpreadsheetDuplicateItem */
  local_20 = DAT_1800791f8 ^ (ulonglong)auStackY_e8;
  HVar2 = CLSIDFromProgID(L"AspenTech.AspenPlus.SpreadsheetCalculator.410",&local_30);
  if (HVar2 < 0) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_90);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_90,
               "MMSpreadsheetDuplicateItem(): %ls not registered",
               L"AspenTech.AspenPlus.SpreadsheetCalculator.410");
    LogMessage(local_90,1,1);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_90);
  }
  else {
    uVar7 = 0;
    local_98 = (longlong *)0x0;
    uVar3 = CoCreateInstance(&local_30,(LPUNKNOWN)0x0,1,(IID *)&DAT_180057ac8,&local_98);
    if (((int)uVar3 < 0) || (local_98 == (longlong *)0x0)) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_90);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_90,
                 "MMSpreadsheetDuplicateItem(): Failed to create the instance of %ls. HR=%d",
                 L"AspenTech.AspenPlus.SpreadsheetCalculator.410",(ulonglong)uVar3);
      LogMessage(local_90,1,1);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_90);
    }
    else {
      local_80 = L"DuplicateSpreadsheet";
      lVar1 = *local_98;
      GetUserDefaultLCID();
      iVar4 = (**(code **)(lVar1 + 0x28))(local_98,&DAT_180057ab8,&local_80,1);
      if (-1 < iVar4) {
        local_78 = &local_60;
        local_70 = 0;
        local_68 = 1;
        uVar6 = uVar7;
        do {
          VariantInit((VARIANTARG *)&(&local_60)[uVar6].n2);
          uVar3 = (int)uVar6 + 1;
          uVar6 = (ulonglong)uVar3;
        } while (uVar3 < (uint)local_68);
        local_60.n2.vt = 3;
        local_60._8_4_ = param_1;
        AfxVariantInit(&local_48);
        lVar1 = *local_98;
        LVar5 = GetUserDefaultLCID();
        iVar4 = (**(code **)(lVar1 + 0x30))(local_98,local_88,&DAT_180057ab8,LVar5);
        (**(code **)(*local_98 + 0x10))();
        if (-1 < iVar4) {
          uVar7 = (ulonglong)(uint)local_48.n1._8_4_;
        }
        VariantClear(&local_48);
        return uVar7;
      }
      (**(code **)(*local_98 + 0x10))();
    }
  }
  return 0;
}

/* ---- FUNC 00024D2E FUN_180024d2e (429 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_180024d2e(void)

{
  longlong lVar1;
  uint uVar2;
  LCID LVar3;
  int iVar4;
  ulonglong uVar5;
  longlong unaff_RBP;
  ulonglong uVar6;
  undefined4 unaff_R15D;
  
  uVar6 = 0;
  *(undefined8 *)(unaff_RBP + -0x39) = 0;
  uVar2 = CoCreateInstance((IID *)(unaff_RBP + 0x2f),(LPUNKNOWN)0x0,1,(IID *)&DAT_180057ac8,
                           (LPVOID *)(unaff_RBP + -0x39));
  if (((int)uVar2 < 0) || (*(longlong **)(unaff_RBP + -0x39) == (longlong *)0x0)) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(unaff_RBP + -0x31))
    ;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(unaff_RBP + -0x31),
               "MMSpreadsheetDuplicateItem(): Failed to create the instance of %ls. HR=%d",
               L"AspenTech.AspenPlus.SpreadsheetCalculator.410",(ulonglong)uVar2);
    LogMessage(*(undefined8 *)(unaff_RBP + -0x31),1,1);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(unaff_RBP + -0x31))
    ;
  }
  else {
    *(wchar_t **)(unaff_RBP + -0x21) = L"DuplicateSpreadsheet";
    lVar1 = **(longlong **)(unaff_RBP + -0x39);
    LVar3 = GetUserDefaultLCID();
    iVar4 = (**(code **)(lVar1 + 0x28))
                      (*(undefined8 *)(unaff_RBP + -0x39),&DAT_180057ab8,unaff_RBP + -0x21,1,LVar3);
    if (-1 < iVar4) {
      *(undefined8 *)(unaff_RBP + -0x11) = 0;
      *(longlong *)(unaff_RBP + -0x19) = unaff_RBP + -1;
      *(undefined8 *)(unaff_RBP + -9) = 1;
      uVar5 = uVar6;
      do {
        VariantInit((VARIANTARG *)(unaff_RBP + -1 + uVar5 * 0x18));
        uVar2 = (int)uVar5 + 1;
        uVar5 = (ulonglong)uVar2;
      } while (uVar2 < *(uint *)(unaff_RBP + -9));
      *(undefined4 *)(unaff_RBP + 7) = unaff_R15D;
      *(undefined2 *)(unaff_RBP + -1) = 3;
      AfxVariantInit((tagVARIANT *)(unaff_RBP + 0x17));
      lVar1 = **(longlong **)(unaff_RBP + -0x39);
      LVar3 = GetUserDefaultLCID();
      iVar4 = (**(code **)(lVar1 + 0x30))
                        (*(undefined8 *)(unaff_RBP + -0x39),*(undefined4 *)(unaff_RBP + -0x29),
                         &DAT_180057ab8,LVar3,1);
      (**(code **)(**(longlong **)(unaff_RBP + -0x39) + 0x10))();
      if (-1 < iVar4) {
        uVar6 = (ulonglong)*(uint *)(unaff_RBP + 0x1f);
      }
      VariantClear((VARIANTARG *)(unaff_RBP + 0x17));
      return uVar6;
    }
    (**(code **)(**(longlong **)(unaff_RBP + -0x39) + 0x10))();
  }
  return 0;
}

/* ---- FUNC 00024EDB FUN_180024edb (24 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180024edb(void)

{
  return;
}

/* ---- FUNC 00024F00 MMSpreadsheetGetItem (125 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 MMSpreadsheetGetItem(undefined4 *param_1)

{
  longlong lVar1;
  HRESULT HVar2;
  uint uVar3;
  int iVar4;
  LCID LVar5;
  ulonglong uVar6;
  undefined1 auStackY_e8 [32];
  longlong *local_98;
  undefined8 local_90;
  undefined4 local_88;
  undefined4 local_84;
  wchar_t *local_80;
  undefined1 *local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined1 local_60 [24];
  tagVARIANT local_48;
  CLSID local_30;
  ulonglong local_20;
  
                    /* 0x24f00  410  MMSpreadsheetGetItem */
  local_20 = DAT_1800791f8 ^ (ulonglong)auStackY_e8;
  HVar2 = CLSIDFromProgID(L"AspenTech.AspenPlus.SpreadsheetCalculator.410",&local_30);
  if (HVar2 < 0) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_90);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_90,
               "MMSpreadsheetGetItem(): %ls not registered",
               L"AspenTech.AspenPlus.SpreadsheetCalculator.410");
    LogMessage(local_90,1,1);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_90);
  }
  else {
    uVar6 = 0;
    local_98 = (longlong *)0x0;
    uVar3 = CoCreateInstance(&local_30,(LPUNKNOWN)0x0,1,(IID *)&DAT_180057ac8,&local_98);
    if (((int)uVar3 < 0) || (local_98 == (longlong *)0x0)) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_90);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_90,
                 "MMSpreadsheetGetItem(): Failed to create the instance of %ls. HR=%d",
                 L"AspenTech.AspenPlus.SpreadsheetCalculator.410",(ulonglong)uVar3);
      LogMessage(local_90,1,1);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_90);
    }
    else {
      local_80 = L"GetSpreadsheet";
      lVar1 = *local_98;
      GetUserDefaultLCID();
      iVar4 = (**(code **)(lVar1 + 0x28))(local_98,&DAT_180057ab8,&local_80,1);
      if (-1 < iVar4) {
        local_78 = local_60;
        local_70 = 0;
        local_68 = 1;
        do {
          VariantInit((VARIANTARG *)(local_60 + uVar6 * 0x18));
          uVar3 = (int)uVar6 + 1;
          uVar6 = (ulonglong)uVar3;
        } while (uVar3 < (uint)local_68);
        local_88 = *param_1;
        local_60._0_2_ = 0x4003;
        local_60._8_8_ = &local_88;
        AfxVariantInit(&local_48);
        lVar1 = *local_98;
        LVar5 = GetUserDefaultLCID();
        iVar4 = (**(code **)(lVar1 + 0x30))(local_98,local_84,&DAT_180057ab8,LVar5);
        (**(code **)(*local_98 + 0x10))();
        if (iVar4 < 0) {
          *param_1 = 0;
          VariantClear(&local_48);
          return 0;
        }
        *param_1 = local_88;
        VariantClear(&local_48);
        return 1;
      }
      (**(code **)(*local_98 + 0x10))();
    }
  }
  return 0;
}

/* ---- FUNC 00024F7D FUN_180024f7d (463 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180024f7d(void)

{
  longlong lVar1;
  uint uVar2;
  LCID LVar3;
  int iVar4;
  ulonglong uVar5;
  longlong unaff_RBP;
  undefined4 *unaff_RSI;
  
  uVar5 = 0;
  *(undefined8 *)(unaff_RBP + -0x39) = 0;
  uVar2 = CoCreateInstance((IID *)(unaff_RBP + 0x2f),(LPUNKNOWN)0x0,1,(IID *)&DAT_180057ac8,
                           (LPVOID *)(unaff_RBP + -0x39));
  if (((int)uVar2 < 0) || (*(longlong **)(unaff_RBP + -0x39) == (longlong *)0x0)) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(unaff_RBP + -0x31))
    ;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(unaff_RBP + -0x31),
               "MMSpreadsheetGetItem(): Failed to create the instance of %ls. HR=%d",
               L"AspenTech.AspenPlus.SpreadsheetCalculator.410",(ulonglong)uVar2);
    LogMessage(*(undefined8 *)(unaff_RBP + -0x31),1,1);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(unaff_RBP + -0x31))
    ;
  }
  else {
    *(wchar_t **)(unaff_RBP + -0x21) = L"GetSpreadsheet";
    lVar1 = **(longlong **)(unaff_RBP + -0x39);
    LVar3 = GetUserDefaultLCID();
    iVar4 = (**(code **)(lVar1 + 0x28))
                      (*(undefined8 *)(unaff_RBP + -0x39),&DAT_180057ab8,unaff_RBP + -0x21,1,LVar3);
    if (-1 < iVar4) {
      *(undefined8 *)(unaff_RBP + -0x11) = 0;
      *(longlong *)(unaff_RBP + -0x19) = unaff_RBP + -1;
      *(undefined8 *)(unaff_RBP + -9) = 1;
      do {
        VariantInit((VARIANTARG *)(unaff_RBP + -1 + uVar5 * 0x18));
        uVar2 = (int)uVar5 + 1;
        uVar5 = (ulonglong)uVar2;
      } while (uVar2 < *(uint *)(unaff_RBP + -9));
      *(undefined4 *)(unaff_RBP + -0x29) = *unaff_RSI;
      *(undefined2 *)(unaff_RBP + -1) = 0x4003;
      *(longlong *)(unaff_RBP + 7) = unaff_RBP + -0x29;
      AfxVariantInit((tagVARIANT *)(unaff_RBP + 0x17));
      lVar1 = **(longlong **)(unaff_RBP + -0x39);
      LVar3 = GetUserDefaultLCID();
      iVar4 = (**(code **)(lVar1 + 0x30))
                        (*(undefined8 *)(unaff_RBP + -0x39),*(undefined4 *)(unaff_RBP + -0x25),
                         &DAT_180057ab8,LVar3,1);
      (**(code **)(**(longlong **)(unaff_RBP + -0x39) + 0x10))();
      if (-1 < iVar4) {
        *unaff_RSI = *(undefined4 *)(unaff_RBP + -0x29);
        VariantClear((VARIANTARG *)(unaff_RBP + 0x17));
        return 1;
      }
      *unaff_RSI = 0;
      VariantClear((VARIANTARG *)(unaff_RBP + 0x17));
      return 0;
    }
    (**(code **)(**(longlong **)(unaff_RBP + -0x39) + 0x10))();
  }
  return 0;
}

/* ---- FUNC 0002514C FUN_18002514c (23 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18002514c(void)

{
  return;
}

/* ---- FUNC 00025170 MMXLCloseItem (41 bytes) ---- */

void MMXLCloseItem(undefined4 param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* 0x25170  415  MMXLCloseItem */
  UNRECOVERED_JUMPTABLE = (code *)GetGlobalPointer("APXLCloseItem");
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000180025190. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(param_1);
    return;
  }
  return;
}

/* ---- FUNC 000251A0 MMXLCommitItem (41 bytes) ---- */

void MMXLCommitItem(undefined4 param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* 0x251a0  416  MMXLCommitItem */
  UNRECOVERED_JUMPTABLE = (code *)GetGlobalPointer("APXLCommitItem");
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0001800251c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(param_1);
    return;
  }
  return;
}

/* ---- FUNC 000251D0 MMXLEditDefVars (82 bytes) ---- */

void MMXLEditDefVars(undefined4 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  code *pcVar1;
  
                    /* 0x251d0  417  MMXLEditDefVars */
  pcVar1 = (code *)GetGlobalPointer("APXLEditDefVars");
  if (pcVar1 != (code *)0x0) {
    (*pcVar1)(param_1,param_2,param_3,param_4);
  }
  return;
}

/* ---- FUNC 00025230 MMXLGetItem (84 bytes) ---- */

void MMXLGetItem(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* 0x25230  418  MMXLGetItem */
  UNRECOVERED_JUMPTABLE = (code *)GetGlobalPointer("APXLGetItem");
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000180025271. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(param_1,param_2,param_3);
    return;
  }
  return;
}

/* ---- FUNC 00025290 MMXLRemoveItem (61 bytes) ---- */

void MMXLRemoveItem(undefined4 param_1,undefined8 param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* 0x25290  419  MMXLRemoveItem */
  UNRECOVERED_JUMPTABLE = (code *)GetGlobalPointer("APXLRemoveItem");
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0001800252bf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(param_1,param_2);
    return;
  }
  return;
}

/* ---- FUNC 000252D0 MMXLRestoreItem (41 bytes) ---- */

void MMXLRestoreItem(undefined4 param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* 0x252d0  420  MMXLRestoreItem */
  UNRECOVERED_JUMPTABLE = (code *)GetGlobalPointer("APXLRestoreItem");
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0001800252f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(param_1);
    return;
  }
  return;
}

/* ---- FUNC 00025300 XCExcelCalc (174 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void XCExcelCalc(undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined8 param_6,undefined8 param_7,undefined4 *param_8,
                undefined4 param_9)

{
  code *pcVar1;
  
                    /* 0x25300  543  XCExcelCalc */
  pcVar1 = (code *)GetGlobalPointer("APXLDoCalc");
  if (pcVar1 != (code *)0x0) {
    _DAT_18007b56c = param_5;
    _DAT_18007b570 = param_6;
    _DAT_18007b578 = param_7;
    DAT_18007b580 = 1;
    _DAT_18007b584 = param_9;
    _DAT_18007b558 = param_1;
    _DAT_18007b560 = param_2;
    _DAT_18007b564 = param_3;
    _DAT_18007b568 = param_4;
    (*pcVar1)(&DAT_18007b558);
    *param_8 = DAT_18007b580;
  }
  return;
}

/* ---- FUNC 000253B0 FUN_1800253b0 (201 bytes) ---- */

undefined8 *
FUN_1800253b0(undefined8 *param_1,LPCSTR param_2,DWORD param_3,DWORD param_4,
             LPSECURITY_ATTRIBUTES param_5,DWORD param_6,DWORD param_7,HANDLE param_8)

{
  char cVar1;
  char *pcVar2;
  HANDLE pvVar3;
  longlong lVar4;
  char *pcVar6;
  longlong lVar5;
  
  *param_1 = CFileStream::vftable;
  *(undefined4 *)(param_1 + 4) = 0;
  param_1[1] = 0;
  *(undefined4 *)(param_1 + 2) = 0;
  if (param_2 == (LPCSTR)0x0) {
    param_1[3] = 0;
  }
  else {
    lVar4 = -1;
    do {
      lVar5 = lVar4;
      lVar4 = lVar5 + 1;
    } while (param_2[lVar4] != '\0');
    pcVar2 = malloc(lVar5 + 2);
    param_1[3] = pcVar2;
    pcVar6 = param_2;
    if (pcVar2 != (char *)0x0) {
      do {
        cVar1 = *pcVar6;
        *pcVar2 = cVar1;
        pcVar2 = pcVar2 + 1;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      pvVar3 = CreateFileA(param_2,param_3,param_4,param_5,param_6,param_7,param_8);
      param_1[1] = pvVar3;
      *(DWORD *)(param_1 + 4) = param_3;
    }
  }
  return param_1;
}

/* ---- FUNC 00025480 FUN_180025480 (63 bytes) ---- */

void FUN_180025480(undefined8 *param_1)

{
  *param_1 = CFileStream::vftable;
  if ((void *)param_1[3] != (void *)0x0) {
    free((void *)param_1[3]);
  }
  if ((HANDLE)param_1[1] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[1]);
    param_1[1] = 0;
  }
  return;
}

/* ---- FUNC 000254C0 FUN_1800254c0 (52 bytes) ---- */

undefined8 * FUN_1800254c0(undefined8 *param_1,uint param_2)

{
  FUN_180025480(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

/* ---- FUNC 00025500 FUN_180025500 (9 bytes) ---- */

void FUN_180025500(longlong param_1)

{
  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
  return;
}

/* ---- FUNC 00025510 FUN_180025510 (48 bytes) ---- */

undefined4 FUN_180025510(longlong param_1)

{
  BOOL BVar1;
  undefined4 uVar2;
  
  if (*(HANDLE *)(param_1 + 8) == (HANDLE)0x0) {
    return 0x80004005;
  }
  BVar1 = FlushFileBuffers(*(HANDLE *)(param_1 + 8));
  uVar2 = 0x80004005;
  if (BVar1 != 0) {
    uVar2 = 0;
  }
  return uVar2;
}

/* ---- FUNC 00025540 FUN_180025540 (129 bytes) ---- */

int FUN_180025540(longlong *param_1,longlong *param_2,uint param_3,int *param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  void *_Memory;
  uint uVar3;
  int local_res8 [2];
  int local_38 [4];
  
  if (param_1[1] == 0) {
    return -0x7fffbffb;
  }
  if (param_2 == (longlong *)0x0) {
    return -0x7ff8ffa9;
  }
  _Memory = malloc(0xc18);
  iVar2 = 0;
  if (param_4 != (int *)0x0) {
    param_4[0] = 0;
    param_4[1] = 0;
  }
  if (param_5 != (int *)0x0) {
    param_5[0] = 0;
    param_5[1] = 0;
  }
  iVar1 = 0;
  if (param_3 != 0) {
    while (iVar2 = iVar1, iVar2 == 0) {
      uVar3 = param_3;
      if (0xc18 < param_3) {
        uVar3 = 0xc18;
      }
      iVar2 = (**(code **)(*param_1 + 0x18))(param_1,_Memory,uVar3,local_res8);
      if (param_4 != (int *)0x0) {
        *param_4 = *param_4 + local_res8[0];
      }
      if ((iVar2 < 0) || (local_res8[0] == 0)) break;
      iVar2 = (**(code **)(*param_2 + 0x20))(param_2,_Memory,local_res8[0],local_38);
      if (param_5 != (int *)0x0) {
        *param_5 = *param_5 + local_38[0];
      }
      param_3 = param_3 - uVar3;
      iVar1 = iVar2;
      if (param_3 == 0) break;
    }
  }
  free(_Memory);
  return iVar2;
}

/* ---- FUNC 000255C1 FUN_1800255c1 (106 bytes) ---- */

int FUN_1800255c1(void)

{
  uint unaff_EBX;
  uint uVar1;
  int *unaff_RSI;
  int unaff_EDI;
  longlong *unaff_R12;
  longlong *unaff_R13;
  int *unaff_R14;
  void *unaff_R15;
  undefined4 uStackX_20;
  int in_stack_00000060;
  
  while (unaff_EDI == 0) {
    uVar1 = unaff_EBX;
    if (0xc18 < unaff_EBX) {
      uVar1 = 0xc18;
    }
    unaff_EDI = (**(code **)(*unaff_R13 + 0x18))();
    if (unaff_R14 != (int *)0x0) {
      *unaff_R14 = *unaff_R14 + in_stack_00000060;
    }
    if ((unaff_EDI < 0) || (in_stack_00000060 == 0)) break;
    unaff_EDI = (**(code **)(*unaff_R12 + 0x20))();
    if (unaff_RSI != (int *)0x0) {
      *unaff_RSI = *unaff_RSI + uStackX_20;
    }
    unaff_EBX = unaff_EBX - uVar1;
    if (unaff_EBX == 0) break;
  }
  free(unaff_R15);
  return unaff_EDI;
}

/* ---- FUNC 0002562B FUN_18002562b (38 bytes) ---- */

undefined4 FUN_18002562b(void)

{
  undefined4 unaff_EDI;
  void *unaff_R15;
  
  free(unaff_R15);
  return unaff_EDI;
}

/* ---- FUNC 00025660 FUN_180025660 (57 bytes) ---- */

undefined4 FUN_180025660(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  BOOL BVar1;
  undefined4 uVar2;
  
  BVar1 = LockFile(*(HANDLE *)(param_1 + 8),(DWORD)param_2,(DWORD)((ulonglong)param_2 >> 0x20),
                   (DWORD)param_3,(DWORD)((ulonglong)param_3 >> 0x20));
  uVar2 = 0x80004005;
  if (BVar1 != 0) {
    uVar2 = 0;
  }
  return uVar2;
}

/* ---- FUNC 000256A0 FUN_1800256a0 (104 bytes) ---- */

undefined8 FUN_1800256a0(longlong *param_1,longlong *param_2,undefined8 *param_3)

{
  if (((*param_2 != DAT_180057a78) || (param_2[1] != DAT_180057a80)) &&
     ((*param_2 != DAT_180057a58 || (param_2[1] != DAT_180057a60)))) {
    return 0x80004001;
  }
  (**(code **)(*param_1 + 8))();
  *param_3 = param_1;
  return 0;
}

/* ---- FUNC 00025710 FUN_180025710 (102 bytes) ---- */

undefined8 FUN_180025710(longlong param_1,LPVOID param_2,DWORD param_3,DWORD *param_4)

{
  BOOL BVar1;
  DWORD DVar2;
  undefined8 uVar3;
  DWORD local_res8 [8];
  
  if (*(HANDLE *)(param_1 + 8) == (HANDLE)0x0) {
    return 0x80004005;
  }
  BVar1 = ReadFile(*(HANDLE *)(param_1 + 8),param_2,param_3,local_res8,(LPOVERLAPPED)0x0);
  if (param_4 != (DWORD *)0x0) {
    *param_4 = local_res8[0];
  }
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    uVar3 = 1;
    if (DVar2 != 0x26) {
      uVar3 = 0x8003001e;
    }
    return uVar3;
  }
  return 0;
}

/* ---- FUNC 00025780 FUN_180025780 (64 bytes) ---- */

int FUN_180025780(longlong *param_1)

{
  int iVar1;
  
  iVar1 = (int)param_1[2];
  if (iVar1 != 0) {
    iVar1 = iVar1 + -1;
    *(int *)(param_1 + 2) = iVar1;
    if (iVar1 == 0) {
      CloseHandle((HANDLE)param_1[1]);
      param_1[1] = 0;
      (**(code **)(*param_1 + 0x70))(param_1,1);
      iVar1 = 0;
    }
  }
  return iVar1;
}

/* ---- FUNC 000257C0 FUN_1800257c0 (115 bytes) ---- */

ulonglong FUN_1800257c0(longlong param_1,LONG param_2,int param_3,DWORD *param_4)

{
  DWORD DVar1;
  DWORD local_res8;
  
  if (*(HANDLE *)(param_1 + 8) != (HANDLE)0x0) {
    if (param_3 == 0) {
      local_res8 = 0;
    }
    else if (param_3 == 1) {
      local_res8 = 1;
    }
    else if (param_3 == 2) {
      local_res8 = 2;
    }
    DVar1 = SetFilePointer(*(HANDLE *)(param_1 + 8),param_2,(PLONG)0x0,local_res8);
    if (param_4 != (DWORD *)0x0) {
      *param_4 = DVar1;
      param_4[1] = 0;
    }
    return (ulonglong)(DVar1 == 0xffffffff);
  }
  return 0x80004005;
}

/* ---- FUNC 00025840 FUN_180025840 (289 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180025840(longlong param_1,undefined8 *param_2,int param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  int iVar3;
  uint uVar4;
  ulonglong uVar5;
  wchar_t *_DstCh;
  LPVOID pvVar6;
  undefined1 auStack_68 [32];
  undefined1 local_48 [20];
  undefined4 local_34;
  ulonglong local_18;
  
  local_18 = DAT_1800791f8 ^ (ulonglong)auStack_68;
  if (((*(longlong *)(param_1 + 0x18) != 0) &&
      (iVar3 = _stat64i32(*(longlong *)(param_1 + 0x18),local_48), iVar3 == 0)) &&
     (param_2 != (undefined8 *)0x0)) {
    *param_2 = 0;
    param_2[1] = 0;
    param_2[2] = 0;
    param_2[3] = 0;
    param_2[4] = 0;
    param_2[5] = 0;
    param_2[6] = 0;
    param_2[7] = 0;
    param_2[8] = 0;
    param_2[9] = 0;
    if (param_3 == 0) {
      if (*(longlong *)(param_1 + 0x18) == 0) {
        pvVar6 = CoTaskMemAlloc(0);
        *param_2 = pvVar6;
      }
      else {
        uVar5 = 0xffffffffffffffff;
        do {
          uVar5 = uVar5 + 1;
        } while (*(char *)(*(longlong *)(param_1 + 0x18) + uVar5) != '\0');
        uVar4 = (int)uVar5 + 1;
        _DstCh = CoTaskMemAlloc((ulonglong)uVar4);
        *param_2 = _DstCh;
        if ((uVar4 != 0) && (_DstCh != (wchar_t *)0x0)) {
          mbtowc(_DstCh,*(char **)(param_1 + 0x18),uVar5 & 0xffffffff);
        }
      }
    }
    *(undefined4 *)(param_2 + 2) = local_34;
    *(undefined4 *)(param_2 + 1) = 2;
    GetFileTime(*(HANDLE *)(param_1 + 8),(LPFILETIME)(param_2 + 4),(LPFILETIME)(param_2 + 5),
                (LPFILETIME)(param_2 + 3));
    *(undefined4 *)(param_2 + 6) = *(undefined4 *)(param_1 + 0x20);
    *(undefined4 *)((longlong)param_2 + 0x34) = 0;
    uVar2 = DAT_180057ac0;
    uVar1 = DAT_180057ab8;
    param_2[9] = 0;
    param_2[7] = uVar1;
    param_2[8] = uVar2;
    return 0;
  }
  return 0x80004005;
}

/* ---- FUNC 00025970 FUN_180025970 (57 bytes) ---- */

undefined4 FUN_180025970(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  BOOL BVar1;
  undefined4 uVar2;
  
  BVar1 = UnlockFile(*(HANDLE *)(param_1 + 8),(DWORD)param_2,(DWORD)((ulonglong)param_2 >> 0x20),
                     (DWORD)param_3,(DWORD)((ulonglong)param_3 >> 0x20));
  uVar2 = 0x80004005;
  if (BVar1 != 0) {
    uVar2 = 0;
  }
  return uVar2;
}

/* ---- FUNC 000259B0 FUN_1800259b0 (102 bytes) ---- */

undefined8 FUN_1800259b0(longlong param_1,LPCVOID param_2,DWORD param_3,DWORD *param_4)

{
  BOOL BVar1;
  DWORD DVar2;
  undefined8 uVar3;
  DWORD local_res8 [8];
  
  if (*(HANDLE *)(param_1 + 8) == (HANDLE)0x0) {
    return 0x80004005;
  }
  BVar1 = WriteFile(*(HANDLE *)(param_1 + 8),param_2,param_3,local_res8,(LPOVERLAPPED)0x0);
  if (param_4 != (DWORD *)0x0) {
    *param_4 = local_res8[0];
  }
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    uVar3 = 1;
    if (DVar2 != 0x26) {
      uVar3 = 0x8003001d;
    }
    return uVar3;
  }
  return 0;
}

/* ---- FUNC 00025A20 MMCreateStreamOnFile (49 bytes) ---- */

void MMCreateStreamOnFile
               (LPCSTR param_1,DWORD param_2,DWORD param_3,DWORD param_4,undefined8 *param_5)

{
                    /* 0x25a20  379  MMCreateStreamOnFile */
  MMCreateStreamOnFileEx
            (param_1,param_2,param_3,(LPSECURITY_ATTRIBUTES)0x0,param_4,0x80,(HANDLE)0x0,param_5);
  return;
}

/* ---- FUNC 00025A60 MMCreateStreamOnFileEx (182 bytes) ---- */

undefined8
MMCreateStreamOnFileEx
          (LPCSTR param_1,DWORD param_2,DWORD param_3,LPSECURITY_ATTRIBUTES param_4,DWORD param_5,
          DWORD param_6,HANDLE param_7,undefined8 *param_8)

{
  undefined8 *puVar1;
  longlong *plVar2;
  undefined8 uVar3;
  
                    /* 0x25a60  380  MMCreateStreamOnFileEx */
  puVar1 = operator_new(0x28);
  if (puVar1 == (undefined8 *)0x0) {
    plVar2 = (longlong *)0x0;
  }
  else {
    plVar2 = FUN_1800253b0(puVar1,param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    if (plVar2 != (longlong *)0x0) {
      (**(code **)(*plVar2 + 8))(plVar2);
    }
  }
  *param_8 = plVar2;
  uVar3 = 0x80004005;
  if (plVar2 != (longlong *)0x0) {
    uVar3 = 0;
  }
  return uVar3;
}

/* ---- FUNC 00025B20 MMCreateGuid (7 bytes) ---- */

HRESULT __stdcall MMCreateGuid(GUID *pguid)

{
  HRESULT HVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180025b20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x25b20  377  MMCreateGuid */
  HVar1 = CoCreateGuid(pguid);
  return HVar1;
}

/* ---- FUNC 00025B30 MMCreateGuidString (71 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined * MMCreateGuidString(void)

{
  undefined1 auStack_48 [32];
  GUID local_28;
  ulonglong local_18;
  
                    /* 0x25b30  378  MMCreateGuidString */
  local_18 = DAT_1800791f8 ^ (ulonglong)auStack_48;
  MMCreateGuid(&local_28);
  MMGuidToString(&local_28,0x18007b590);
  return &DAT_18007b590;
}

/* ---- FUNC 00025B80 MMGuidFromString (7 bytes) ---- */

RPC_STATUS __stdcall MMGuidFromString(RPC_CSTR StringUuid,UUID *Uuid)

{
  RPC_STATUS RVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180025b80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x25b80  396  MMGuidFromString */
  RVar1 = UuidFromStringA(StringUuid,Uuid);
  return RVar1;
}

/* ---- FUNC 00025B90 MMGuidIsNil (20 bytes) ---- */

void MMGuidIsNil(UUID *param_1)

{
  RPC_STATUS local_res10 [6];
  
                    /* 0x25b90  397  MMGuidIsNil */
  UuidIsNil(param_1,local_res10);
  return;
}

/* ---- FUNC 00025BB0 MMGuidToString (63 bytes) ---- */

void MMGuidToString(UUID *param_1,longlong param_2)

{
  uchar uVar1;
  longlong lVar2;
  RPC_CSTR local_res10 [3];
  
                    /* 0x25bb0  398  MMGuidToString */
  UuidToStringA(param_1,local_res10);
  lVar2 = param_2 - (longlong)local_res10[0];
  do {
    uVar1 = *local_res10[0];
    local_res10[0][lVar2] = uVar1;
    local_res10[0] = local_res10[0] + 1;
  } while (uVar1 != '\0');
  RpcStringFreeA(local_res10);
  return;
}

/* ---- FUNC 00025BF0 FUN_180025bf0 (138 bytes) ---- */

CDialog * FUN_180025bf0(CDialog *param_1,CWnd *param_2)

{
  CDialog::CDialog(param_1,0x2a00,param_2);
  *(undefined ***)param_1 = CLibDialog::vftable;
  CWnd::CWnd((CWnd *)(param_1 + 0x130));
  *(undefined ***)(param_1 + 0x130) = CCheckListBox::vftable;
  *(undefined8 *)(param_1 + 0x218) = 0;
  param_1[0x178] = (CDialog)0x1;
  FUN_180022aa0((CWnd *)(param_1 + 0x220));
  FUN_180022aa0((CWnd *)(param_1 + 0x348));
  CStringArray::CStringArray((CStringArray *)(param_1 + 0x470));
  return param_1;
}

/* ---- FUNC 00025C80 FUN_180025c80 (129 bytes) ---- */

CDialog * FUN_180025c80(CDialog *param_1,uint param_2)

{
  CStringArray::~CStringArray((CStringArray *)(param_1 + 0x470));
  FUN_18000d3f0((CButton *)(param_1 + 0x348));
  FUN_18000d3f0((CButton *)(param_1 + 0x220));
  CListBox::~CListBox((CListBox *)(param_1 + 0x130));
  CDialog::~CDialog(param_1);
  if ((param_2 & 1) != 0) {
    if ((param_2 & 4) == 0) {
      operator_delete(param_1);
      return param_1;
    }
    FUN_180007c90(param_1);
  }
  return param_1;
}

/* ---- FUNC 00025D10 FUN_180025d10 (66 bytes) ---- */

void FUN_180025d10(longlong param_1,CDataExchange *param_2)

{
  DDX_Control(param_2,0x4001,(CWnd *)(param_1 + 0x220));
  DDX_Control(param_2,0x4002,(CWnd *)(param_1 + 0x348));
  return;
}

/* ---- FUNC 00025D60 FUN_180025d60 (108 bytes) ---- */

void FUN_180025d60(longlong param_1,CStringArray *param_2)

{
  ulonglong uVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong lVar4;
  
  lVar4 = *(longlong *)(param_1 + 0x480);
  uVar1 = 0;
  uVar3 = uVar1;
  if (0 < lVar4) {
    do {
      if (((longlong)uVar1 < 0) || (lVar4 <= (longlong)uVar1)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      CStringArray::SetAtGrow
                (param_2,*(__int64 *)(param_2 + 0x10),
                 (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                 (*(longlong *)(param_1 + 0x478) + uVar1 * 8));
      lVar4 = *(longlong *)(param_1 + 0x480);
      uVar2 = (int)uVar3 + 1;
      uVar1 = (ulonglong)(int)uVar2;
      uVar3 = (ulonglong)uVar2;
    } while ((longlong)uVar1 < lVar4);
  }
  return;
}

/* ---- FUNC 00025DD0 thunk_FUN_180025de0 (5 bytes) ---- */

undefined ** thunk_FUN_180025de0(void)

{
  return &PTR_LAB_180055970;
}

/* ---- FUNC 00025DE0 FUN_180025de0 (8 bytes) ---- */

undefined ** FUN_180025de0(void)

{
  return &PTR_LAB_180055970;
}

/* ---- FUNC 00025DF0 FUN_180025df0 (937 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180025df0(CWnd *param_1)

{
  int iVar1;
  int iVar2;
  int extraout_EAX;
  tagOFNA *ptVar3;
  __int64 _Var4;
  undefined8 uVar5;
  INT_PTR IVar6;
  LRESULT LVar7;
  CWnd *this;
  char *pcVar8;
  int iVar9;
  DWORD DVar10;
  undefined4 uVar11;
  undefined1 auStackY_578 [32];
  char *local_528;
  LPCSTR local_520;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_518 [8];
  undefined4 local_510;
  undefined4 local_50c;
  CFileDialog local_508 [912];
  char local_178 [64];
  char local_138 [272];
  ulonglong local_28;
  CListBox *this_00;
  
  local_28 = DAT_1800791f8 ^ (ulonglong)auStackY_578;
  iVar9 = 0;
  CFileDialog::CFileDialog
            (local_508,1,"apm",(char *)0x0,0x20000e,
             "Aspen Plus User Model Library (*.apm)|*.apm|All Files (*.*)|*.*||",(CWnd *)0x0,0,1);
  ptVar3 = CFileDialog::GetOFN(local_508);
  *(char **)(ptVar3 + 0x58) = "New User Model Library";
  _Var4 = CFileDialog::DoModal(local_508);
  if (_Var4 == 1) {
    CFileDialog::GetPathName(local_508);
    uVar5 = GetModLibDocName(local_520,local_178,0x40);
    if ((int)uVar5 < 1) {
      pcVar8 = "The file chosen cannot be opened. It may be locked by another application.";
      if ((int)uVar5 != -1) {
        pcVar8 = 
        "The file chosen is not a valid model library or is a\nlibrary created with a later version of Aspen Plus."
        ;
      }
      AfxMessageBox(pcVar8,0,0);
    }
    else {
      iVar1 = ApwnIsReservedDisplayName(local_178);
      if (iVar1 == 0) {
        LVar7 = SendMessageA(*(HWND *)(param_1 + 0x170),0x18b,0,0);
        this_00 = (CListBox *)(param_1 + 0x130);
        iVar1 = (int)LVar7;
        if (0 < iVar1) {
          do {
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_518);
            CListBox::GetText(this_00,iVar9,local_518);
            iVar2 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                    CompareNoCase(local_518,local_178);
            if (iVar2 == 0) {
              local_50c = 0;
              local_510 = 0;
              DVar10 = APModLibGetValues((longlong)local_178,local_138,0x104,&local_50c,&local_510);
              param_1 = (CWnd *)CONCAT44((int)((ulonglong)param_1 >> 0x20),DVar10);
              if (extraout_EAX != 0) {
                iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Compare
                                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                                   &local_520,local_138);
                if (iVar1 != 0) {
                  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &local_528);
                  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &local_528,
                             "A User Model Library with the name \"%s\"\nis already registered. Do you wish to replace it?\n\nReplacing the library may cause unexpected behavior for\nsimulation problems which referenced the previous version"
                            );
                  iVar1 = AfxMessageBox(local_528,0x104,0);
                  if (iVar1 == 7) {
                    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                               &local_528);
                    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_518);
                    goto LAB_180026157;
                  }
                  uVar11 = APModLibUnregisterLib((longlong)local_178);
                  this_00 = (CListBox *)CONCAT44((int)((ulonglong)this_00 >> 0x20),uVar11);
                  APModLibRegisterLib(local_178,local_520,0,0);
                  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             &local_528);
                }
              }
              CCheckListBox::SetCheck((CCheckListBox *)this_00,iVar9,1);
              SendMessageA(*(HWND *)(param_1 + 0x170),0x186,(longlong)iVar9,0);
              ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
              ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_518);
              goto LAB_180025ffe;
            }
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_518);
            iVar9 = iVar9 + 1;
          } while (iVar9 < iVar1);
        }
        APModLibRegisterLib(local_178,local_520,0,0);
        SendMessageA(*(HWND *)(param_1 + 0x170),0x180,0,(LPARAM)local_178);
        CCheckListBox::SetCheck((CCheckListBox *)this_00,iVar1,1);
        SendMessageA(*(HWND *)(param_1 + 0x170),0x186,(longlong)iVar1,0);
        SendMessageA(*(HWND *)(param_1 + 0x170),0x188,0,0);
LAB_180025ffe:
        this = CWnd::GetDlgItem(param_1,0x4004);
        CWnd::SetWindowTextA(this,local_520);
        FUN_180023540((longlong)param_1);
      }
      else {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_528);
        IVar6 = FUN_1800240f0();
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_528,
                   "%s has reserved the Model Library name \"%s\".\n",IVar6,local_178);
        AfxMessageBox(local_528,0,0);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_528);
      }
    }
LAB_180026157:
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_520);
  }
  CFileDialog::~CFileDialog(local_508);
  return;
}

/* ---- FUNC 000261A0 FUN_1800261a0 (31 bytes) ---- */

undefined8 FUN_1800261a0(void)

{
  MMDisplayHtmlHelp();
  return 1;
}

/* ---- FUNC 000261C0 FUN_1800261c0 (1496 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_1800261c0(CDialog *param_1)

{
  undefined1 auVar1 [16];
  double dVar2;
  DWORD DVar3;
  int iVar4;
  int extraout_EAX;
  int extraout_EAX_00;
  HDC pHVar5;
  CDC *pCVar6;
  __uint64 _Var7;
  void *pvVar8;
  void *pvVar9;
  undefined8 uVar10;
  LRESULT LVar11;
  undefined8 *puVar12;
  CWnd *pCVar13;
  longlong lVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  ulonglong uVar17;
  ulonglong uVar18;
  undefined4 uVar19;
  int iVar20;
  undefined1 auStackY_208 [32];
  int local_1d8;
  int local_1d4;
  undefined4 local_1d0;
  undefined4 uStack_1cc;
  CDC *local_1c8;
  tagSIZE local_1c0;
  tagSIZE local_1b8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_1b0 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_1a8 [16];
  char local_198 [64];
  char local_158 [272];
  ulonglong local_48;
  
  local_48 = DAT_1800791f8 ^ (ulonglong)auStackY_208;
  uVar16 = 0;
  local_1d0 = 0;
  CDialog::OnInitDialog(param_1);
  CWnd::SubclassDlgItem((CWnd *)(param_1 + 0x130),0x4000,(CWnd *)param_1);
  CWnd::SetWindowTextA((CWnd *)param_1,"Library References");
  FUN_180022e00((longlong)(param_1 + 0x220),0x4006,0x4009,0x4008,0x4007);
  FUN_180022e00((longlong)(param_1 + 0x348),0x400a,0x400c,0x400b,0x400d);
  local_1d4 = *(int *)(param_1 + 0x480);
  iVar20 = 200;
  local_1d8 = 200;
  pHVar5 = GetDC(*(HWND *)(param_1 + 0x170));
  pCVar6 = CDC::FromHandle(pHVar5);
  dVar2 = DAT_180055b70;
  uVar18 = uVar16;
  local_1c8 = pCVar6;
  if (0 < local_1d4) {
    do {
      iVar4 = (int)uVar18;
      if ((iVar4 < 0) || (*(longlong *)(param_1 + 0x480) <= (longlong)iVar4)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1d0,
                 (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                 (*(longlong *)(param_1 + 0x478) + (longlong)iVar4 * 8));
      SendMessageA(*(HWND *)(param_1 + 0x170),0x180,0,CONCAT44(uStack_1cc,local_1d0));
      GetTextExtentPoint32A
                (*(HDC *)(pCVar6 + 0x10),(LPCSTR)CONCAT44(uStack_1cc,local_1d0),
                 *(int *)((LPCSTR)CONCAT44(uStack_1cc,local_1d0) + -0x10),&local_1c0);
      if (iVar20 <= (int)((double)local_1c0.cx * dVar2)) {
        GetTextExtentPoint32A
                  (*(HDC *)(pCVar6 + 0x10),(LPCSTR)CONCAT44(uStack_1cc,local_1d0),
                   *(int *)((LPCSTR)CONCAT44(uStack_1cc,local_1d0) + -0x10),&local_1b8);
        iVar20 = (int)((double)local_1b8.cx * dVar2);
        local_1d8 = iVar20;
      }
      CCheckListBox::SetCheck((CCheckListBox *)(param_1 + 0x130),iVar4,1);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1d0);
      uVar18 = (ulonglong)(iVar4 + 1U);
    } while ((int)(iVar4 + 1U) < local_1d4);
  }
  DVar3 = APModLibCount();
  uVar18 = (ulonglong)(int)DVar3;
  auVar1._8_8_ = 0;
  auVar1._0_8_ = uVar18;
  _Var7 = SUB168(ZEXT816(8) * auVar1,0);
  if (SUB168(ZEXT816(8) * auVar1,8) != 0) {
    _Var7 = 0xffffffffffffffff;
  }
  pvVar8 = operator_new__(_Var7);
  uVar15 = uVar16;
  if (0 < (int)DVar3) {
    do {
      pvVar9 = operator_new__(0x40);
      *(void **)((longlong)pvVar8 + uVar15 * 8) = pvVar9;
      uVar15 = uVar15 + 1;
    } while ((longlong)uVar15 < (longlong)uVar18);
  }
  APModLibListLibs((longlong)pvVar8,DVar3,0x40);
  uVar15 = uVar16;
  uVar17 = uVar16;
  iVar20 = local_1d8;
  if (0 < (int)DVar3) {
    do {
      local_1d0 = 0;
      local_1d8 = 0;
      iVar4 = ApwnIsReservedDisplayName(*(char **)((longlong)pvVar8 + uVar15 * 8));
      lVar14 = *(longlong *)((longlong)pvVar8 + uVar15 * 8);
      if (iVar4 == 0) {
        DVar3 = APModLibGetValues(lVar14,local_158,0x104,&local_1d0,&local_1d8);
        pvVar8 = (void *)CONCAT44((int)((ulonglong)pvVar8 >> 0x20),DVar3);
        if ((extraout_EAX < 1) ||
           (uVar10 = GetModLibDocName(local_158,local_198,0x40), (int)uVar10 == 0)) {
          lVar14 = *(longlong *)((longlong)pvVar8 + uVar15 * 8);
          goto LAB_180026547;
        }
        LVar11 = SendMessageA(*(HWND *)(param_1 + 0x170),0x1a2,0xffffffffffffffff,
                              *(LPARAM *)((longlong)pvVar8 + uVar15 * 8));
        if ((int)LVar11 < 0) {
          SendMessageA(*(HWND *)(param_1 + 0x170),0x180,0,*(LPARAM *)((longlong)pvVar8 + uVar15 * 8)
                      );
          puVar12 = (undefined8 *)
                    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                              (local_1a8,*(char **)((longlong)pvVar8 + uVar15 * 8));
          GetTextExtentPoint32A
                    (*(HDC *)(local_1c8 + 0x10),(LPCSTR)*puVar12,*(int *)((LPCSTR)*puVar12 + -0x10),
                     &local_1b8);
          if (iVar20 <= (int)((double)local_1b8.cx * dVar2)) {
            puVar12 = (undefined8 *)
                      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                                (local_1b0,*(char **)((longlong)pvVar8 + uVar15 * 8));
            uVar17 = 1;
            GetTextExtentPoint32A
                      (*(HDC *)(local_1c8 + 0x10),(LPCSTR)*puVar12,
                       *(int *)((LPCSTR)*puVar12 + -0x10),&local_1c0);
            iVar20 = (int)((double)local_1c0.cx * dVar2);
          }
          if (uVar17 != 0) {
            uVar17 = 0;
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_1b0);
          }
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_1a8);
        }
      }
      else {
LAB_180026547:
        uVar19 = APModLibUnregisterLib(lVar14);
        param_1 = (CDialog *)CONCAT44((int)((ulonglong)param_1 >> 0x20),uVar19);
      }
      uVar15 = uVar15 + 1;
    } while ((longlong)uVar15 < (longlong)uVar18);
  }
  ReleaseDC(*(HWND *)(param_1 + 0x170),*(HDC *)(local_1c8 + 8));
  SendMessageA(*(HWND *)(param_1 + 0x170),0x194,(longlong)iVar20,0);
  LVar11 = SendMessageA(*(HWND *)(param_1 + 0x170),399,0xffffffffffffffff,DAT_18007b690);
  if ((int)LVar11 < 0) {
    SendMessageA(*(HWND *)(param_1 + 0x170),0x180,0,DAT_18007b690);
  }
  LVar11 = SendMessageA(*(HWND *)(param_1 + 0x170),399,0xffffffffffffffff,DAT_18007b698);
  if ((int)LVar11 < 0) {
    SendMessageA(*(HWND *)(param_1 + 0x170),0x180,0,DAT_18007b698);
  }
  LVar11 = SendMessageA(*(HWND *)(param_1 + 0x170),399,0xffffffffffffffff,DAT_18007b6a0);
  if ((int)LVar11 < 0) {
    SendMessageA(*(HWND *)(param_1 + 0x170),0x180,0,DAT_18007b6a0);
  }
  LVar11 = SendMessageA(*(HWND *)(param_1 + 0x170),399,0xffffffffffffffff,DAT_18007b6a8);
  if ((int)LVar11 < 0) {
    SendMessageA(*(HWND *)(param_1 + 0x170),0x180,0,DAT_18007b6a8);
  }
  iVar20 = 0;
  if (local_1d4 < 1) {
    SendMessageA(*(HWND *)(param_1 + 0x170),0x186,0,0);
  }
  else {
    LVar11 = SendMessageA(*(HWND *)(param_1 + 0x170),0x186,(longlong)(local_1d4 + -1),0);
    iVar20 = (int)LVar11;
  }
  FUN_180023540((longlong)param_1);
  if (-1 < iVar20) {
    SendMessageA(*(HWND *)(param_1 + 0x170),0x189,(longlong)iVar20,(LPARAM)local_198);
    pCVar13 = CWnd::GetDlgItem((CWnd *)param_1,0x4005);
    CWnd::SetWindowTextA(pCVar13,local_198);
    local_1d4 = 0;
    local_1d0 = 0;
    DVar3 = APModLibGetValues((longlong)local_198,local_158,0x104,&local_1d4,&local_1d0);
    pvVar8 = (void *)CONCAT44((int)((ulonglong)pvVar8 >> 0x20),DVar3);
    if (0 < extraout_EAX_00) {
      pCVar13 = CWnd::GetDlgItem((CWnd *)param_1,0x4004);
      CWnd::SetWindowTextA(pCVar13,local_158);
    }
  }
  if (0 < (longlong)uVar18) {
    do {
      operator_delete__(*(void **)((longlong)pvVar8 + uVar16 * 8));
      uVar16 = uVar16 + 1;
    } while ((longlong)uVar16 < (longlong)uVar18);
  }
  operator_delete__(pvVar8);
  return 1;
}

/* ---- FUNC 000267A0 FUN_1800267a0 (198 bytes) ---- */

void FUN_1800267a0(CDialog *param_1)

{
  int iVar1;
  LRESULT LVar2;
  int iVar3;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res8 [8];
  
  CStringArray::SetSize((CStringArray *)(param_1 + 0x470),0,-1);
  LVar2 = SendMessageA(*(HWND *)(param_1 + 0x170),0x18b,0,0);
  iVar3 = 0;
  if (0 < (int)LVar2) {
    do {
      iVar1 = CCheckListBox::GetCheck((CCheckListBox *)(param_1 + 0x130),iVar3);
      if (iVar1 == 1) {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res8);
        CListBox::GetText((CListBox *)(param_1 + 0x130),iVar3,local_res8);
        CStringArray::SetAtGrow
                  ((CStringArray *)(param_1 + 0x470),*(__int64 *)(param_1 + 0x480),local_res8);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res8);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)LVar2);
  }
  CDialog::OnOK(param_1);
  return;
}

/* ---- FUNC 00026870 FUN_180026870 (273 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180026870(CWnd *param_1)

{
  int extraout_EAX;
  LRESULT LVar1;
  CWnd *this;
  CWnd *this_00;
  char *pcVar2;
  undefined1 auStackY_1a8 [32];
  undefined4 local_178;
  undefined4 local_174 [3];
  char local_168 [64];
  char local_128 [272];
  ulonglong local_18;
  
  local_18 = DAT_1800791f8 ^ (ulonglong)auStackY_1a8;
  LVar1 = SendMessageA(*(HWND *)(param_1 + 0x170),0x188,0,0);
  this = CWnd::GetDlgItem(param_1,0x4005);
  this_00 = CWnd::GetDlgItem(param_1,0x4004);
  if (-1 < (int)LVar1) {
    SendMessageA(*(HWND *)(param_1 + 0x170),0x189,(longlong)(int)LVar1,(LPARAM)local_168);
    CWnd::SetWindowTextA(this,local_168);
    local_174[0] = 0;
    local_178 = 0;
    APModLibGetValues((longlong)local_168,local_128,0x104,local_174,&local_178);
    pcVar2 = local_128;
    if (extraout_EAX < 1) {
      pcVar2 = "";
    }
    CWnd::SetWindowTextA(this_00,pcVar2);
    FUN_180023540((longlong)param_1);
  }
  return;
}

/* ---- FUNC 00026990 FUN_180026990 (103 bytes) ---- */

void FUN_180026990(longlong param_1,longlong param_2)

{
  ulonglong uVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong lVar4;
  
  lVar4 = *(longlong *)(param_2 + 0x10);
  uVar1 = 0;
  uVar3 = uVar1;
  if (0 < lVar4) {
    do {
      if (((longlong)uVar1 < 0) || (lVar4 <= (longlong)uVar1)) {
                    /* WARNING: Subroutine does not return */
        AfxThrowInvalidArgException();
      }
      CStringArray::SetAtGrow
                ((CStringArray *)(param_1 + 0x470),*(__int64 *)(param_1 + 0x480),
                 (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                 (*(longlong *)(param_2 + 8) + uVar1 * 8));
      lVar4 = *(longlong *)(param_2 + 0x10);
      uVar2 = (int)uVar3 + 1;
      uVar1 = (ulonglong)(int)uVar2;
      uVar3 = (ulonglong)uVar2;
    } while ((longlong)uVar1 < lVar4);
  }
  return;
}

/* ---- FUNC 00026A00 FUN_180026a00 (803 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

char * FUN_180026a00(int param_1,char *param_2,char *param_3)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  undefined8 uVar4;
  char *pcVar5;
  char *pcVar6;
  longlong lVar7;
  undefined1 *puVar8;
  undefined1 auStack_188 [32];
  undefined1 local_168 [47];
  undefined1 uStack_139;
  char local_138 [272];
  ulonglong local_28;
  
  local_28 = DAT_1800791f8 ^ (ulonglong)auStack_188;
  local_138[0] = '\0';
  if (param_1 != 3) {
    pcVar6 = param_2;
    do {
      cVar2 = *pcVar6;
      pcVar6[(longlong)param_3 - (longlong)param_2] = cVar2;
      pcVar6 = pcVar6 + 1;
    } while (cVar2 != '\0');
    iVar3 = _stat64i32(param_3,local_168);
    if (iVar3 == 0) {
      return param_3;
    }
    if (param_1 == 0) {
      return (char *)0x0;
    }
  }
  pcVar6 = "MMXEQ";
  if (param_1 == 2) {
    pcVar6 = "MMDAT";
  }
  uVar4 = FUN_180026dd0(param_3,(param_1 != 2) + 1,local_138);
  if ((int)uVar4 != 0) {
    pcVar5 = param_3 + -1;
    do {
      pcVar1 = pcVar5 + 1;
      pcVar5 = pcVar5 + 1;
    } while (*pcVar1 != '\0');
    lVar7 = 0;
    do {
      cVar2 = param_2[lVar7];
      pcVar5[lVar7] = cVar2;
      lVar7 = lVar7 + 1;
    } while (cVar2 != '\0');
    iVar3 = _stat64i32(param_3);
    if (iVar3 == 0) {
      return param_3;
    }
    if (local_138[0] != '\0') {
      puVar8 = &uStack_139;
      do {
        pcVar5 = puVar8 + 1;
        puVar8 = puVar8 + 1;
      } while (*pcVar5 != '\0');
      lVar7 = 0;
      do {
        cVar2 = param_2[lVar7];
        puVar8[lVar7] = cVar2;
        lVar7 = lVar7 + 1;
      } while (cVar2 != '\0');
      iVar3 = _stat64i32(local_138,local_168);
      if (iVar3 == 0) {
        pcVar6 = local_138;
        do {
          cVar2 = *pcVar6;
          pcVar6[(longlong)param_3 - (longlong)local_138] = cVar2;
          pcVar6 = pcVar6 + 1;
        } while (cVar2 != '\0');
        return param_3;
      }
    }
  }
  uVar4 = FUN_180026d30(param_3,pcVar6,(char *)0x0);
  if ((int)uVar4 != 0) {
    pcVar6 = param_3 + -1;
    do {
      pcVar5 = pcVar6 + 1;
      pcVar6 = pcVar6 + 1;
    } while (*pcVar5 != '\0');
    lVar7 = 0;
    do {
      cVar2 = param_2[lVar7];
      pcVar6[lVar7] = cVar2;
      lVar7 = lVar7 + 1;
    } while (cVar2 != '\0');
    iVar3 = _stat64i32(param_3,local_168);
    if (iVar3 == 0) {
      return param_3;
    }
  }
  if (param_1 == 2) {
    uVar4 = FUN_180026d30(param_3,"MMDAT2",(char *)0x0);
    if ((int)uVar4 == 0) goto LAB_180026c27;
    pcVar6 = param_3 + -1;
    do {
      pcVar5 = pcVar6 + 1;
      pcVar6 = pcVar6 + 1;
    } while (*pcVar5 != '\0');
    lVar7 = 0;
    do {
      cVar2 = param_2[lVar7];
      pcVar6[lVar7] = cVar2;
      lVar7 = lVar7 + 1;
    } while (cVar2 != '\0');
  }
  else {
    if ((param_1 != 4) || (uVar4 = FUN_180026d30(param_3,"MMTOP",(char *)0x0), (int)uVar4 == 0))
    goto LAB_180026c27;
    pcVar6 = param_3 + -1;
    do {
      pcVar5 = pcVar6 + 1;
      pcVar6 = pcVar6 + 1;
    } while (*pcVar5 != '\0');
    lVar7 = 0;
    do {
      cVar2 = param_2[lVar7];
      pcVar6[lVar7] = cVar2;
      lVar7 = lVar7 + 1;
    } while (cVar2 != '\0');
  }
  iVar3 = _stat64i32(param_3,local_168);
  if (iVar3 == 0) {
    return param_3;
  }
LAB_180026c27:
  uVar4 = FUN_180026d30(param_3,"MMTOP","\\mm\\");
  if ((int)uVar4 != 0) {
    puVar8 = &DAT_180055bd0;
    if (param_1 == 2) {
      puVar8 = &DAT_180055bc8;
    }
    pcVar6 = param_3 + -1;
    do {
      pcVar5 = pcVar6 + 1;
      pcVar6 = pcVar6 + 1;
    } while (*pcVar5 != '\0');
    lVar7 = 0;
    do {
      cVar2 = puVar8[lVar7];
      pcVar6[lVar7] = cVar2;
      lVar7 = lVar7 + 1;
    } while (cVar2 != '\0');
    pcVar6 = param_3 + -1;
    do {
      pcVar5 = pcVar6 + 1;
      pcVar6 = pcVar6 + 1;
    } while (*pcVar5 != '\0');
    lVar7 = 0;
    do {
      cVar2 = param_2[lVar7];
      pcVar6[lVar7] = cVar2;
      lVar7 = lVar7 + 1;
    } while (cVar2 != '\0');
    iVar3 = _stat64i32(param_3,local_168);
    if (iVar3 == 0) {
      return param_3;
    }
  }
  lVar7 = (longlong)param_3 - (longlong)param_2;
  pcVar6 = param_2;
  if (param_1 == 3) {
    do {
      cVar2 = *pcVar6;
      pcVar6[lVar7] = cVar2;
      pcVar6 = pcVar6 + 1;
    } while (cVar2 != '\0');
    iVar3 = _stat64i32(param_3,local_168);
    if (iVar3 == 0) {
      return param_3;
    }
  }
  do {
    cVar2 = *param_2;
    param_2[lVar7] = cVar2;
    param_2 = param_2 + 1;
  } while (cVar2 != '\0');
  return (char *)0x0;
}

/* ---- FUNC 00026D30 FUN_180026d30 (152 bytes) ---- */

undefined8 FUN_180026d30(char *param_1,char *param_2,char *param_3)

{
  char cVar1;
  char *pcVar2;
  int _Val;
  char *pcVar3;
  char *pcVar4;
  
  pcVar2 = getenv(param_2);
  if (((pcVar2 != (char *)0x0) || (pcVar2 = param_3, param_3 != (char *)0x0)) &&
     (cVar1 = *pcVar2, cVar1 != '\0')) {
    pcVar4 = param_1;
    do {
      pcVar3 = pcVar4;
      *pcVar3 = cVar1;
      pcVar4 = pcVar3 + 1;
      _Val = (int)cVar1;
      cVar1 = pcVar4[(longlong)pcVar2 - (longlong)param_1];
    } while (cVar1 != '\0');
    if (pcVar4 != param_1) {
      pcVar2 = strchr("\\:",_Val);
      if (pcVar2 == (char *)0x0) {
        *pcVar4 = '\\';
        pcVar4 = pcVar3 + 2;
      }
      *pcVar4 = '\0';
      return 1;
    }
  }
  return 0;
}

/* ---- FUNC 00026DD0 FUN_180026dd0 (337 bytes) ---- */

undefined8 FUN_180026dd0(char *param_1,int param_2,char *param_3)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  
  if (param_2 != 0) {
    if (param_2 == 1) {
      pcVar4 = "MMCOMMONDAT";
      pcVar3 = "MMDAT";
    }
    else if (param_2 == 2) {
      pcVar4 = "MMCOMMONXEQ";
      pcVar3 = "MMXEQ";
    }
    else if (param_2 == 3) {
      pcVar4 = "MMCOMMONTOP";
      pcVar3 = "MMTOP";
    }
    else {
      if (param_2 != 4) {
        return 0;
      }
      pcVar4 = "MMCOMMONFAVORITES";
      pcVar3 = "MMFAVORITES";
    }
    pcVar1 = (char *)GetGlobalPointer(pcVar3);
    pcVar3 = (char *)GetGlobalPointer(pcVar4);
    if (pcVar1 != (char *)0x0) {
      cVar2 = *pcVar1;
      pcVar4 = param_1;
      if (cVar2 != '\0') {
        do {
          *pcVar4 = cVar2;
          pcVar4 = pcVar4 + 1;
          cVar2 = pcVar4[(longlong)pcVar1 - (longlong)param_1];
        } while (cVar2 != '\0');
      }
      if (pcVar3 == (char *)0x0) {
        *param_3 = '\0';
        pcVar3 = (char *)0x0;
      }
      else {
        cVar2 = *pcVar3;
        while (cVar2 != '\0') {
          pcVar3 = pcVar3 + 1;
          *param_3 = cVar2;
          param_3 = param_3 + 1;
          cVar2 = *pcVar3;
        }
        pcVar3 = pcVar3 + 1;
      }
      if (pcVar4 != param_1) {
        pcVar1 = strchr("\\:",(int)pcVar4[-1]);
        if (pcVar1 == (char *)0x0) {
          *pcVar4 = '\\';
          pcVar4 = pcVar4 + 1;
        }
        if ((pcVar3 != (char *)0x0) &&
           (pcVar3 = strchr("\\:",(int)param_3[-1]), pcVar3 == (char *)0x0)) {
          *param_3 = '\\';
          param_3 = param_3 + 1;
        }
        *pcVar4 = '\0';
        *param_3 = '\0';
        return 1;
      }
    }
  }
  return 0;
}

/* ---- FUNC 00026F30 FUN_180026f30 (150 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool FUN_180026f30(undefined4 *param_1)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  HANDLE pvVar3;
  undefined4 uVar4;
  undefined1 auStackY_468 [32];
  undefined1 local_418 [1008];
  ulonglong local_28;
  
  local_28 = DAT_1800791f8 ^ (ulonglong)auStackY_468;
  hObject = CreateFileW(*(LPCWSTR *)(param_1 + 2),0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,2,0x80,
                        (HANDLE)0x0);
  uVar4 = 0;
  if (hObject == (HANDLE)0xffffffffffffffff) {
    FUN_180007de0(local_418,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\MiniDump.cpp",0x140);
    LogMessage(local_418,2,1);
    param_1[8] = 4;
  }
  else {
    DVar2 = GetCurrentProcessId();
    pvVar3 = GetCurrentProcess();
    iVar1 = (*DAT_18007b6b0)(pvVar3,DVar2,hObject,*param_1);
    if (iVar1 != 1) {
      FUN_180007de0(local_418,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\MiniDump.cpp",0x156);
      LogMessage(local_418,2,1);
      uVar4 = 5;
    }
    param_1[8] = uVar4;
    CloseHandle(hObject);
  }
  DVar2 = GetLastError();
  param_1[9] = DVar2;
  return param_1[8] == 0;
}

/* ---- FUNC 00026FC6 FUN_180026fc6 (8 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_180026fc6(void)

{
  DWORD DVar1;
  int iVar2;
  HANDLE pvVar3;
  int iVar4;
  undefined8 unaff_RSI;
  longlong unaff_RDI;
  HANDLE unaff_R14;
  
  DVar1 = GetCurrentProcessId();
  pvVar3 = GetCurrentProcess();
  iVar2 = (*DAT_18007b6b0)(pvVar3,DVar1);
  iVar4 = (int)unaff_RSI;
  if (iVar2 != 1) {
    FUN_180007de0(&stack0x00000050,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\MiniDump.cpp",0x156);
    LogMessage(&stack0x00000050,2,1);
    iVar4 = 5;
  }
  *(int *)(unaff_RDI + 0x20) = iVar4;
  CloseHandle(unaff_R14);
  DVar1 = GetLastError();
  *(DWORD *)(unaff_RDI + 0x24) = DVar1;
  return CONCAT71((int7)((ulonglong)unaff_RSI >> 8),*(int *)(unaff_RDI + 0x20) == (int)unaff_RSI) &
         0xffffffff;
}

/* ---- FUNC 00026FCE FUN_180026fce (102 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_180026fce(void)

{
  DWORD DVar1;
  int iVar2;
  HANDLE pvVar3;
  int iVar4;
  undefined8 unaff_RSI;
  longlong unaff_RDI;
  HANDLE unaff_R14;
  
  DVar1 = GetCurrentProcessId();
  pvVar3 = GetCurrentProcess();
  iVar2 = (*DAT_18007b6b0)(pvVar3,DVar1);
  iVar4 = (int)unaff_RSI;
  if (iVar2 != 1) {
    FUN_180007de0(&stack0x00000050,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\MiniDump.cpp",0x156);
    LogMessage(&stack0x00000050,2,1);
    iVar4 = 5;
  }
  *(int *)(unaff_RDI + 0x20) = iVar4;
  CloseHandle(unaff_R14);
  DVar1 = GetLastError();
  *(DWORD *)(unaff_RDI + 0x24) = DVar1;
  return CONCAT71((int7)((ulonglong)unaff_RSI >> 8),*(int *)(unaff_RDI + 0x20) == (int)unaff_RSI) &
         0xffffffff;
}

/* ---- FUNC 00027034 FUN_180027034 (83 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_180027034(void)

{
  DWORD DVar1;
  int iVar2;
  int unaff_EBX;
  undefined8 unaff_RSI;
  longlong unaff_RDI;
  HANDLE unaff_R14;
  
  FUN_180007de0(&stack0x00000050,"Assert failed in file %s line %d",
                "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\MiniDump.cpp",0x156);
  LogMessage(&stack0x00000050,2,1);
  iVar2 = (int)unaff_RSI;
  if (unaff_EBX != 1) {
    iVar2 = 5;
  }
  *(int *)(unaff_RDI + 0x20) = iVar2;
  CloseHandle(unaff_R14);
  DVar1 = GetLastError();
  *(DWORD *)(unaff_RDI + 0x24) = DVar1;
  return CONCAT71((int7)((ulonglong)unaff_RSI >> 8),*(int *)(unaff_RDI + 0x20) == (int)unaff_RSI) &
         0xffffffff;
}

/* ---- FUNC 00027087 FUN_180027087 (46 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_180027087(void)

{
  DWORD DVar1;
  undefined8 unaff_RSI;
  longlong unaff_RDI;
  
  DVar1 = GetLastError();
  *(DWORD *)(unaff_RDI + 0x24) = DVar1;
  return CONCAT71((int7)((ulonglong)unaff_RSI >> 8),*(int *)(unaff_RDI + 0x20) == (int)unaff_RSI) &
         0xffffffff;
}

/* ---- FUNC 000270C0 FUN_1800270c0 (139 bytes) ---- */

undefined8 FUN_1800270c0(HMODULE param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  HRSRC hResInfo;
  HGLOBAL hResData;
  LPVOID pvVar2;
  
  if (param_2 != (undefined8 *)0x0) {
    hResInfo = FindResourceA(param_1,(LPCSTR)0x1,(LPCSTR)0x10);
    if (hResInfo != (HRSRC)0x0) {
      hResData = LoadResource(param_1,hResInfo);
      if (hResData != (HGLOBAL)0x0) {
        pvVar2 = LockResource(hResData);
        if ((pvVar2 != (LPVOID)0x0) && (*(int *)((longlong)pvVar2 + 0x28) == -0x110fb43)) {
          uVar1 = *(undefined8 *)((longlong)pvVar2 + 0x30);
          *param_2 = *(undefined8 *)((longlong)pvVar2 + 0x28);
          param_2[1] = uVar1;
          uVar1 = *(undefined8 *)((longlong)pvVar2 + 0x40);
          param_2[2] = *(undefined8 *)((longlong)pvVar2 + 0x38);
          param_2[3] = uVar1;
          uVar1 = *(undefined8 *)((longlong)pvVar2 + 0x50);
          param_2[4] = *(undefined8 *)((longlong)pvVar2 + 0x48);
          param_2[5] = uVar1;
          *(undefined4 *)(param_2 + 6) = *(undefined4 *)((longlong)pvVar2 + 0x58);
          return 1;
        }
      }
    }
  }
  return 0;
}

/* ---- FUNC 00027150 FUN_180027150 (509 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_180027150(undefined4 param_1,LPCWSTR param_2,undefined4 param_3,void *param_4)

{
  bool bVar1;
  BOOL BVar2;
  DWORD dwErrCode;
  int iVar3;
  undefined7 extraout_var;
  HANDLE hHandle;
  undefined1 auStackY_488 [32];
  undefined4 local_458 [2];
  LPCWSTR local_450;
  undefined4 local_448;
  void *local_440;
  undefined8 local_438;
  uint local_430 [2];
  undefined1 local_428 [1008];
  ulonglong local_38;
  
  local_38 = DAT_1800791f8 ^ (ulonglong)auStackY_488;
  BVar2 = IsBadStringPtrW(param_2,0x104);
  if (BVar2 != 0) {
    FUN_180007de0(local_428,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\MiniDump.cpp",0xdf);
    LogMessage(local_428,2,1);
  }
  BVar2 = IsBadStringPtrW(param_2,0x104);
  if (BVar2 == 1) {
LAB_18002732c:
    iVar3 = 3;
  }
  else {
    if (param_4 != (void *)0x0) {
      BVar2 = IsBadReadPtr(param_4,0x10);
      if (BVar2 != 0) {
        FUN_180007de0(local_428,"Assert failed in file %s line %d",
                      "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\MiniDump.cpp",0xe8);
        LogMessage(local_428,2,1);
      }
      BVar2 = IsBadReadPtr(param_4,0x10);
      if (BVar2 == 1) goto LAB_18002732c;
    }
    if ((DAT_18007b6b0 != 0) ||
       (((iVar3 = DAT_180072148, DAT_180072148 == 7 &&
         (bVar1 = FUN_180027350(), iVar3 = DAT_180072148, (int)CONCAT71(extraout_var,bVar1) != 0))
        && (DAT_18007b6b0 != 0)))) {
      local_438 = 7;
      local_458[0] = param_1;
      local_450 = param_2;
      local_448 = param_3;
      local_440 = param_4;
      hHandle = (HANDLE)_beginthreadex((void *)0x0,0,FUN_180026f30,local_458,0,local_430);
      if (hHandle == (HANDLE)0xffffffffffffffff) {
        FUN_180007de0(local_428,"Assert failed in file %s line %d",
                      "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\MiniDump.cpp",0x111);
        LogMessage(local_428,2,1);
        dwErrCode = GetLastError();
        local_438 = CONCAT44(dwErrCode,6);
        SetLastError(dwErrCode);
        iVar3 = (int)local_438;
      }
      else {
        WaitForSingleObject(hHandle,0xffffffff);
        CloseHandle(hHandle);
        SetLastError(local_438._4_4_);
        iVar3 = (int)local_438;
      }
    }
  }
  return iVar3;
}

/* ---- FUNC 00027350 FUN_180027350 (28 bytes) ---- */

bool FUN_180027350(void)

{
  ushort uVar1;
  HMODULE hModule;
  undefined8 uVar2;
  bool bVar3;
  undefined8 local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ushort uStack_3a;
  
  bVar3 = DAT_18007b6b0 == (FARPROC)0x0;
  if (!bVar3) goto FUN_180027418;
  hModule = GetModuleHandleA(PTR_s_DBGHELP_DLL_180072138);
  if (hModule == (HMODULE)0x0) {
    hModule = LoadLibraryA(PTR_s_DBGHELP_DLL_180072138);
    if (hModule != (HMODULE)0x0) goto LAB_1800273a0;
    DAT_180072148 = 1;
  }
  else {
LAB_1800273a0:
    DAT_18007b6b0 = GetProcAddress(hModule,PTR_s_MiniDumpWriteDump_180072140);
    if (DAT_18007b6b0 == (FARPROC)0x0) {
      DAT_180072148 = 2;
    }
    else {
      DAT_180072148 = 0;
      uVar2 = FUN_1800270c0(hModule,&local_48);
      if ((int)uVar2 != 0) {
        uVar1 = (ushort)((uint)local_40 >> 0x10);
        if ((uVar1 < 3) || (((uVar1 == 3 && ((short)local_40 == 0)) && (uStack_3a < 0x14)))) {
          DAT_180072148 = 8;
        }
      }
    }
  }
  bVar3 = DAT_18007b6b0 == (FARPROC)0x0;
FUN_180027418:
  return !bVar3;
}

/* ---- FUNC 0002736C FUN_18002736c (172 bytes) ---- */

ulonglong FUN_18002736c(LPCSTR param_1)

{
  ushort uVar1;
  HMODULE hModule;
  undefined8 uVar2;
  FARPROC unaff_RDI;
  undefined8 uStackX_20;
  undefined8 in_stack_00000028;
  
  hModule = GetModuleHandleA(param_1);
  if (hModule == (HMODULE)0x0) {
    hModule = LoadLibraryA(PTR_s_DBGHELP_DLL_180072138);
    if (hModule == (HMODULE)0x0) {
      DAT_180072148 = 1;
      goto LAB_18002740c;
    }
  }
  DAT_18007b6b0 = GetProcAddress(hModule,PTR_s_MiniDumpWriteDump_180072140);
  if (DAT_18007b6b0 == (FARPROC)0x0) {
    DAT_180072148 = 2;
  }
  else {
    DAT_180072148 = SUB84(unaff_RDI,0);
    uVar2 = FUN_1800270c0(hModule,&uStackX_20);
    if ((int)uVar2 != 0) {
      uVar1 = (ushort)((ulonglong)in_stack_00000028 >> 0x10);
      if ((uVar1 < 3) ||
         (((uVar1 == 3 && ((short)in_stack_00000028 == 0)) &&
          ((ushort)((ulonglong)in_stack_00000028 >> 0x30) < 0x14)))) {
        DAT_180072148 = 8;
      }
    }
  }
LAB_18002740c:
  return CONCAT71((int7)((ulonglong)unaff_RDI >> 8),DAT_18007b6b0 != unaff_RDI) & 0xffffffff;
}

/* ---- FUNC 00027418 FUN_180027418 (12 bytes) ---- */

ulonglong FUN_180027418(void)

{
  undefined8 unaff_RDI;
  bool in_ZF;
  
  return CONCAT71((int7)((ulonglong)unaff_RDI >> 8),!in_ZF) & 0xffffffff;
}

/* ---- FUNC 00027430 CMMDialog (130 bytes) ---- */

/* public: __cdecl CMMDialog::CMMDialog(unsigned int,class CWnd * __ptr64) __ptr64 */

CMMDialog * __thiscall CMMDialog::CMMDialog(CMMDialog *this,uint param_1,CWnd *param_2)

{
                    /* 0x27430  26  ??0CMMDialog@@QEAA@IPEAVCWnd@@@Z */
  CDialog::CDialog((CDialog *)this,param_1,param_2);
  *(undefined ***)this = vftable;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(this + 0x138));
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(this + 0x140));
  *(undefined4 *)(this + 0x130) = 1;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(this + 0x138),
             "Suppressed Dialog");
  ATL::CSimpleStringT<char,1>::Empty((CSimpleStringT<char,1> *)(this + 0x140));
  return this;
}

/* ---- FUNC 000274C0 FUN_1800274c0 (15 bytes) ---- */

void FUN_1800274c0(void)

{
  AfxTryCleanup();
  return;
}

/* ---- FUNC 000274D0 FUN_1800274d0 (15 bytes) ---- */

void FUN_1800274d0(COleDispatchDriver *param_1)

{
  COleDispatchDriver::ReleaseDispatch(param_1);
  return;
}

/* ---- FUNC 000274E0 FUN_1800274e0 (107 bytes) ---- */

CDialog * FUN_1800274e0(CDialog *param_1,uint param_2)

{
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0x140));
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(param_1 + 0x138));
  CDialog::~CDialog(param_1);
  if ((param_2 & 1) != 0) {
    if ((param_2 & 4) == 0) {
      operator_delete(param_1);
      return param_1;
    }
    FUN_180007c90(param_1);
  }
  return param_1;
}

/* ---- FUNC 00027550 FUN_180027550 (207 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_180027550(uint param_1,uint param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_458 [32];
  LPCSTR local_438;
  AFX_MAINTAIN_STATE2 local_430 [24];
  undefined1 local_418 [1008];
  ulonglong local_28;
  
  local_28 = DAT_1800791f8 ^ (ulonglong)auStack_458;
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_430,DAT_18007b728);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_438);
  iVar1 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::LoadStringA
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_438,
                     param_1);
  if (iVar1 == 0) {
    FUN_180007de0(local_418,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\mm_messagebox.cpp",0xaf);
    LogMessage(local_418,2,1);
  }
  if (param_3 != 0xffffffff) {
    param_1 = param_3;
  }
  uVar2 = FUN_180027620(local_438,param_2,param_1);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_438);
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_430);
  return uVar2;
}

/* ---- FUNC 00027620 FUN_180027620 (71 bytes) ---- */

void FUN_180027620(LPCSTR param_1,uint param_2,uint param_3)

{
  int iVar1;
  LPCSTR pCVar2;
  
  iVar1 = MMMessageBoxDefault(param_2,0xffffffff);
  if (iVar1 == 0) {
    pCVar2 = (LPCSTR)FUN_180024070();
    FUN_180027c60(param_1,param_3,param_2,pCVar2);
  }
  else {
    pCVar2 = (LPCSTR)FUN_180024070();
    FUN_180027970(param_1,pCVar2,param_3,param_2 & 0xf,param_2 & 0xf0,iVar1);
  }
  return;
}

/* ---- FUNC 00027667 FUN_180027667 (52 bytes) ---- */

void FUN_180027667(void)

{
  LPCSTR pCVar1;
  LPCSTR unaff_RBP;
  undefined4 unaff_ESI;
  uint unaff_EDI;
  undefined4 unaff_R14D;
  
  pCVar1 = (LPCSTR)FUN_180024070();
  FUN_180027970(unaff_RBP,pCVar1,unaff_ESI,unaff_EDI & 0xf,unaff_EDI & 0xf0,unaff_R14D);
  return;
}

/* ---- FUNC 0002769B FUN_18002769b (22 bytes) ---- */

void FUN_18002769b(void)

{
  return;
}

/* ---- FUNC 000276C0 DoModal (178 bytes) ---- */

/* public: virtual __int64 __cdecl CMMDialog::DoModal(void) __ptr64 */

__int64 __thiscall CMMDialog::DoModal(CMMDialog *this)

{
  longlong *plVar1;
  uint uVar2;
  CWinThread *pCVar3;
  __int64 _Var4;
  char *pcVar5;
  
                    /* 0x276c0  78  ?DoModal@CMMDialog@@UEAA_JXZ */
  uVar2 = MMGetSuppress();
  if (uVar2 != 0) {
    (**(code **)(*(longlong *)this + 0x328))(this);
    pcVar5 = *(char **)(this + 0x140);
    if (*(int *)(pcVar5 + -0x10) == 0) {
      pcVar5 = FUN_180027f20(*(undefined4 *)(this + 0x130));
    }
    MMBroadcastMB(*(char **)(this + 0x138),pcVar5);
    return (longlong)*(int *)(this + 0x130);
  }
  pCVar3 = AfxGetThread();
  plVar1 = *(longlong **)(pCVar3 + 0x80);
  if (plVar1 != (longlong *)0x0) {
    (**(code **)(*plVar1 + 0xb0))(plVar1);
    _Var4 = CDialog::DoModal((CDialog *)this);
    (**(code **)(*plVar1 + 0xb8))(plVar1);
    return (longlong)(int)_Var4;
  }
  _Var4 = CDialog::DoModal((CDialog *)this);
  return (longlong)(int)_Var4;
}

/* ---- FUNC 00027780 FUN_180027780 (193 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180027780(void)

{
  int iVar1;
  HRESULT HVar2;
  LPCOLESTR lpszProgID;
  WCHAR local_88 [48];
  LPVOID local_28;
  CLSID local_20;
  ulonglong local_10;
  
  local_10 = DAT_1800791f8 ^ (ulonglong)&local_28;
  lpszProgID = (LPCOLESTR)0x0;
  if (local_88 != (LPWSTR)0x0) {
    local_88[0] = L'\0';
    iVar1 = MultiByteToWideChar(0,0,"AspenTech.AspenPlus.WpfMMDialog.MessageBox.410",-1,local_88,
                                0x2f);
    lpszProgID = local_88;
    if (iVar1 == 0) {
      lpszProgID = (LPCOLESTR)0x0;
    }
  }
  HVar2 = CLSIDFromProgID(lpszProgID,&local_20);
  if (-1 < HVar2) {
    local_28 = (LPVOID)0x0;
    HVar2 = CoCreateInstance(&local_20,(LPUNKNOWN)0x0,1,(IID *)&DAT_180057ac8,&local_28);
    if (-1 < HVar2) {
      return local_28;
    }
  }
  return 0;
}

/* ---- FUNC 00027850 MMAfxMessageBox (166 bytes) ---- */

/* int __cdecl MMAfxMessageBox(unsigned int,unsigned int,int,unsigned int) */

int __cdecl MMAfxMessageBox(uint param_1,uint param_2,int param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char *local_18 [2];
  
                    /* 0x27850  130  ?MMAfxMessageBox@@YAHIIHI@Z */
  uVar1 = MMGetSuppress();
  if (uVar1 == 0) {
    iVar2 = FUN_180027550(param_1,param_2,param_4);
  }
  else {
    iVar2 = MMMessageBoxDefault(param_2,param_3);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_18);
    iVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::LoadStringA
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_18,
                       param_1);
    if (iVar3 == 0) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_18,
                 "Unknown prompt identifier");
    }
    pcVar4 = FUN_180027f20(iVar2);
    MMBroadcastMB(local_18[0],pcVar4);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_18);
  }
  return iVar2;
}

/* ---- FUNC 00027900 MMAfxMessageBox (107 bytes) ---- */

/* int __cdecl MMAfxMessageBox(char const * __ptr64,unsigned int,int,unsigned int) */

int __cdecl MMAfxMessageBox(char *param_1,uint param_2,int param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  
                    /* 0x27900  131  ?MMAfxMessageBox@@YAHPEBDIHI@Z */
  uVar1 = MMGetSuppress();
  if (uVar1 == 0) {
    iVar2 = FUN_180027620(param_1,param_2,param_4);
  }
  else {
    iVar2 = MMMessageBoxDefault(param_2,param_3);
    pcVar3 = FUN_180027f20(iVar2);
    MMBroadcastMB(param_1,pcVar3);
  }
  return iVar2;
}

/* ---- FUNC 00027970 FUN_180027970 (742 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_180027970(LPCSTR param_1,LPCSTR param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5,undefined4 param_6)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  LCID LVar4;
  longlong *plVar5;
  uint uVar6;
  ulonglong uVar8;
  undefined1 auStackY_1c8 [32];
  undefined4 local_174;
  BSTR local_170;
  BSTR local_168;
  wchar_t *local_158;
  _union_2707 *local_150;
  undefined8 local_148;
  undefined8 local_140;
  VARIANTARG local_138 [4];
  _union_2707 local_d8;
  undefined2 local_c0;
  undefined4 local_b8;
  undefined2 local_a8;
  undefined4 local_a0;
  undefined2 local_90;
  undefined4 local_88;
  undefined2 local_78;
  BSTR local_70;
  undefined2 local_60;
  BSTR local_58;
  ulonglong local_48;
  ulonglong uVar7;
  
  local_48 = DAT_1800791f8 ^ (ulonglong)auStackY_1c8;
  plVar5 = (longlong *)FUN_180027780();
  if (plVar5 != (longlong *)0x0) {
    local_158 = L"Show_3";
    lVar1 = *plVar5;
    GetUserDefaultLCID();
    iVar2 = (**(code **)(lVar1 + 0x28))(plVar5,&DAT_180057ab8,&local_158,1);
    if (-1 < iVar2) {
      uVar8 = 0;
      local_148 = 0;
      local_140 = 6;
      local_150 = &local_d8;
      uVar7 = uVar8;
      do {
        VariantInit((VARIANTARG *)&(&local_d8)[uVar7].n2);
        uVar6 = (int)uVar7 + 1;
        uVar7 = (ulonglong)uVar6;
      } while (uVar6 < (uint)local_140);
      if (param_1 == (LPCSTR)0x0) {
        local_170 = (BSTR)0x0;
      }
      else {
        iVar2 = MultiByteToWideChar(0,0,param_1,-1,(LPWSTR)0x0,0);
        local_170 = SysAllocStringLen((OLECHAR *)0x0,iVar2 - 1);
        if ((local_170 != (BSTR)0x0) &&
           (iVar3 = MultiByteToWideChar(0,0,param_1,-1,local_170,iVar2), iVar3 != iVar2)) {
          SysFreeString(local_170);
LAB_180027c38:
                    /* WARNING: Subroutine does not return */
          FUN_180018e40(-0x7ff8fff2);
        }
        if (local_170 == (BSTR)0x0) goto LAB_180027c38;
      }
      if (param_2 != (LPCSTR)0x0) {
        iVar2 = MultiByteToWideChar(0,0,param_2,-1,(LPWSTR)0x0,0);
        local_168 = SysAllocStringLen((OLECHAR *)0x0,iVar2 - 1);
        if ((local_168 == (BSTR)0x0) ||
           (iVar3 = MultiByteToWideChar(0,0,param_2,-1,local_168,iVar2), iVar3 == iVar2)) {
          if (local_168 != (BSTR)0x0) goto LAB_180027b31;
        }
        else {
          SysFreeString(local_168);
        }
                    /* WARNING: Subroutine does not return */
        FUN_180018e40(-0x7ff8fff2);
      }
      local_168 = (BSTR)0x0;
LAB_180027b31:
      local_60 = 8;
      local_78 = 8;
      local_90 = 3;
      local_a8 = 3;
      local_c0 = 3;
      local_b8 = param_5;
      local_d8.n2.vt = 3;
      local_d8._8_4_ = param_6;
      local_a0 = param_4;
      local_88 = param_3;
      local_70 = local_168;
      local_58 = local_170;
      COleVariant::COleVariant((COleVariant *)local_138,0,3);
      lVar1 = *plVar5;
      LVar4 = GetUserDefaultLCID();
      iVar2 = (**(code **)(lVar1 + 0x30))(plVar5,local_174,&DAT_180057ab8,LVar4);
      if (-1 < iVar2) {
        uVar8 = (ulonglong)(uint)local_138[0].n1._8_4_;
      }
      (**(code **)(*plVar5 + 0x10))(plVar5);
      VariantClear(local_138);
      SysFreeString(local_168);
      SysFreeString(local_170);
      return uVar8;
    }
    (**(code **)(*plVar5 + 0x10))(plVar5);
  }
  return 0;
}

/* ---- FUNC 00027C60 FUN_180027c60 (690 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_180027c60(LPCSTR param_1,uint param_2,undefined4 param_3,LPCSTR param_4)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  LCID LVar4;
  longlong *plVar5;
  uint uVar6;
  ulonglong uVar8;
  undefined1 auStackY_148 [32];
  undefined4 local_f4;
  BSTR local_f0;
  BSTR local_e8;
  wchar_t *local_e0;
  _union_2707 *local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  VARIANTARG local_c0;
  _union_2707 local_a8;
  undefined2 local_90;
  undefined4 local_88;
  undefined2 local_78;
  BSTR local_70;
  undefined2 local_60;
  BSTR local_58;
  ulonglong local_48;
  ulonglong uVar7;
  
  local_48 = DAT_1800791f8 ^ (ulonglong)auStackY_148;
  plVar5 = (longlong *)FUN_180027780();
  if (plVar5 != (longlong *)0x0) {
    local_e0 = L"Show";
    lVar1 = *plVar5;
    GetUserDefaultLCID();
    iVar2 = (**(code **)(lVar1 + 0x28))(plVar5,&DAT_180057ab8,&local_e0,1);
    if (-1 < iVar2) {
      uVar8 = 0;
      local_d0 = 0;
      local_c8 = 4;
      local_d8 = &local_a8;
      uVar7 = uVar8;
      do {
        VariantInit((VARIANTARG *)&(&local_a8)[uVar7].n2);
        uVar6 = (int)uVar7 + 1;
        uVar7 = (ulonglong)uVar6;
      } while (uVar6 < (uint)local_c8);
      if (param_1 == (LPCSTR)0x0) {
        local_f0 = (BSTR)0x0;
      }
      else {
        iVar2 = MultiByteToWideChar(0,0,param_1,-1,(LPWSTR)0x0,0);
        local_f0 = SysAllocStringLen((OLECHAR *)0x0,iVar2 - 1);
        if ((local_f0 != (BSTR)0x0) &&
           (iVar3 = MultiByteToWideChar(0,0,param_1,-1,local_f0,iVar2), iVar3 != iVar2)) {
          SysFreeString(local_f0);
LAB_180027ef4:
                    /* WARNING: Subroutine does not return */
          FUN_180018e40(-0x7ff8fff2);
        }
        if (local_f0 == (BSTR)0x0) goto LAB_180027ef4;
      }
      if (param_4 != (LPCSTR)0x0) {
        iVar2 = MultiByteToWideChar(0,0,param_4,-1,(LPWSTR)0x0,0);
        local_e8 = SysAllocStringLen((OLECHAR *)0x0,iVar2 - 1);
        if ((local_e8 == (BSTR)0x0) ||
           (iVar3 = MultiByteToWideChar(0,0,param_4,-1,local_e8,iVar2), iVar3 == iVar2)) {
          if (local_e8 != (BSTR)0x0) goto LAB_180027e11;
        }
        else {
          SysFreeString(local_e8);
        }
                    /* WARNING: Subroutine does not return */
        FUN_180018e40(-0x7ff8fff2);
      }
      local_e8 = (BSTR)0x0;
LAB_180027e11:
      local_60 = 8;
      local_78 = 8;
      local_90 = 3;
      local_a8.n2.vt = 3;
      local_a8._8_4_ = param_2 & 0xf;
      local_88 = param_3;
      local_70 = local_e8;
      local_58 = local_f0;
      COleVariant::COleVariant((COleVariant *)&local_c0,0,3);
      lVar1 = *plVar5;
      LVar4 = GetUserDefaultLCID();
      iVar2 = (**(code **)(lVar1 + 0x30))(plVar5,local_f4,&DAT_180057ab8,LVar4);
      if (-1 < iVar2) {
        uVar8 = (ulonglong)(uint)local_c0.n1._8_4_;
      }
      (**(code **)(*plVar5 + 0x10))(plVar5);
      VariantClear(&local_c0);
      SysFreeString(local_e8);
      SysFreeString(local_f0);
      return uVar8;
    }
    (**(code **)(*plVar5 + 0x10))(plVar5);
  }
  return 0;
}

/* ---- FUNC 00027F20 FUN_180027f20 (144 bytes) ---- */

undefined * FUN_180027f20(undefined4 param_1)

{
  longlong lVar1;
  
  lVar1 = 0;
  switch(param_1) {
  case 1:
    return PTR_DAT_180072158;
  case 2:
    return PTR_s_Cancel_180072168;
  case 3:
    return PTR_s_Abort_180072170;
  case 4:
    return PTR_s_Retry_180072178;
  case 5:
    return PTR_s_Ignore_180072180;
  case 6:
    return PTR_DAT_180072188;
  case 7:
    lVar1 = 8;
    break;
  case 9:
    return PTR_DAT_180072160;
  }
  return (&PTR_s_Unknown_180072150)[lVar1];
}

/* ---- FUNC 00027FE0 MMBroadcastMB (161 bytes) ---- */

void MMBroadcastMB(char *param_1,char *param_2)

{
  HWND wParam;
  HWND lParam;
  CWinThread *pCVar1;
  longlong lVar2;
  HWND hWnd;
  AFX_MAINTAIN_STATE2 local_18 [16];
  
                    /* 0x27fe0  370  MMBroadcastMB */
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_18,DAT_18007b728);
  hWnd = (HWND)0x0;
  wParam = hWnd;
  if (param_1 != (char *)0x0) {
    wParam = (HWND)_strdup(param_1);
  }
  lParam = hWnd;
  if (param_2 != (char *)0x0) {
    lParam = (HWND)_strdup(param_2);
  }
  pCVar1 = AfxGetThread();
  if ((pCVar1 != (CWinThread *)0x0) &&
     (lVar2 = (**(code **)(*(longlong *)pCVar1 + 0xf8))(pCVar1), lVar2 != 0)) {
    hWnd = *(HWND *)(lVar2 + 0x40);
  }
  PostMessageA(hWnd,0x4dd,(WPARAM)wParam,(LPARAM)lParam);
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_18);
  return;
}

/* ---- FUNC 00028090 MMGetSuppress (28 bytes) ---- */

uint MMGetSuppress(void)

{
                    /* 0x28090  394  MMGetSuppress */
  if (DAT_180072198 != 0) {
    return (uint)(DAT_18007b6bc == 0);
  }
  return DAT_18007b6b8;
}

/* ---- FUNC 000280B0 MMGetVisibleSuppress (7 bytes) ---- */

undefined4 MMGetVisibleSuppress(void)

{
                    /* 0x280b0  395  MMGetVisibleSuppress */
  return DAT_18007b6bc;
}

/* ---- FUNC 000280C0 MMMessageBox (115 bytes) ---- */

int MMMessageBox(HWND param_1,char *param_2,LPCSTR param_3,UINT param_4,uint param_5)

{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  
                    /* 0x280c0  400  MMMessageBox */
  uVar1 = MMGetSuppress();
  if (uVar1 == 0) {
    iVar2 = MessageBoxA(param_1,param_2,param_3,param_4);
  }
  else {
    iVar2 = MMMessageBoxDefault(param_4,param_5);
    pcVar3 = FUN_180027f20(iVar2);
    MMBroadcastMB(param_2,pcVar3);
  }
  return iVar2;
}

/* ---- FUNC 00028140 MMMessageBoxDefault (38 bytes) ---- */

undefined4 MMMessageBoxDefault(uint param_1,uint param_2)

{
  uint uVar1;
  
                    /* 0x28140  401  MMMessageBoxDefault */
  uVar1 = param_1;
  if (param_2 != 0xffffffff) {
    uVar1 = param_2;
  }
  return *(undefined4 *)
          (&DAT_1800721a0 + ((ulonglong)(uVar1 >> 8 & 3) + (ulonglong)(param_1 & 0xf) * 4) * 4);
}

/* ---- FUNC 00028170 MMSetSuppress (17 bytes) ---- */

void MMSetSuppress(undefined4 param_1)

{
                    /* 0x28170  407  MMSetSuppress */
  DAT_180072198 = 0;
  DAT_18007b6b8 = param_1;
  return;
}

/* ---- FUNC 00028190 MMSetVisibleSuppress (7 bytes) ---- */

void MMSetVisibleSuppress(undefined4 param_1)

{
                    /* 0x28190  408  MMSetVisibleSuppress */
  DAT_18007b6bc = param_1;
  return;
}

/* ---- FUNC 000281A0 MMThreadBroadcastMB (663 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void MMThreadBroadcastMB(void *param_1,void *param_2)

{
  int iVar1;
  undefined8 *puVar2;
  undefined1 auStackY_4e8 [32];
  undefined2 local_4a8;
  undefined1 local_4a6;
  longlong *local_4a0;
  longlong *local_498;
  longlong *local_490;
  longlong *local_488;
  IDispatch *local_480;
  void *local_478;
  void *local_470;
  COleDispatchDriver local_468 [16];
  undefined1 local_458 [8];
  AFX_EXCEPTION_LINK local_450 [16];
  longlong *local_440 [5];
  undefined1 local_418 [1008];
  ulonglong local_28;
  
                    /* 0x281a0  414  MMThreadBroadcastMB */
  local_28 = DAT_1800791f8 ^ (ulonglong)auStackY_4e8;
  local_478 = param_1;
  local_470 = param_2;
  puVar2 = (undefined8 *)GetGlobalPointer("HappNode");
  if (puVar2 != (undefined8 *)0x0) {
    local_4a0 = (longlong *)0x0;
    (**(code **)*puVar2)(puVar2,&DAT_180057ac8,&local_4a0);
    if (local_4a0 == (longlong *)0x0) {
      FUN_180007de0(local_418,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\mm_messagebox.cpp",0xe3);
      LogMessage(local_418,2,1);
    }
    local_488 = (longlong *)0x0;
    local_490 = (longlong *)0x0;
    local_4a8 = DAT_18005608c;
    local_4a6 = DAT_18005608e;
    iVar1 = (**(code **)*local_4a0)(local_4a0,&DAT_180057ae8,&local_488);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(*local_488 + 0x20))(local_488,&DAT_180056190,&local_490);
      if (-1 < iVar1) {
        COleDispatchDriver::COleDispatchDriver(local_468);
        iVar1 = (**(code **)(*local_490 + 0x38))(local_490,&local_498);
        if (-1 < iVar1) {
          (**(code **)(*local_498 + 0x28))();
          while (iVar1 = (**(code **)(*local_498 + 0x18))(local_498,1,local_440,local_458),
                iVar1 == 0) {
            if (local_440[0] != (longlong *)0x0) {
              local_480 = (IDispatch *)0x0;
              iVar1 = (**(code **)*local_440[0])(local_440[0],&DAT_180057ac8);
              if (-1 < iVar1) {
                COleDispatchDriver::AttachDispatch(local_468,local_480,0);
                AFX_EXCEPTION_LINK::AFX_EXCEPTION_LINK(local_450);
                COleDispatchDriver::InvokeHelper(local_468,100,1,0,(void *)0x0,(uchar *)&local_4a8);
                AfxTryCleanup();
                COleDispatchDriver::DetachDispatch(local_468);
              }
              (**(code **)(*local_440[0] + 0x10))();
            }
          }
          (**(code **)(*local_498 + 0x10))();
        }
        (**(code **)(*local_490 + 0x10))();
        COleDispatchDriver::ReleaseDispatch(local_468);
      }
      (**(code **)(*local_488 + 0x10))();
    }
    (**(code **)(*local_4a0 + 0x10))();
    if (param_1 != (void *)0x0) {
      free(param_1);
    }
    if (param_2 != (void *)0x0) {
      free(param_2);
    }
  }
  return;
}

/* ---- FUNC 00028440 FUN_180028440 (164 bytes) ---- */

void FUN_180028440(longlong *param_1,longlong *param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong *plVar6;
  
  plVar6 = FUN_1800284f0(param_1,*(undefined8 **)(*param_2 + 8),*param_1,param_4);
  *(longlong **)(*param_1 + 8) = plVar6;
  plVar6 = (longlong *)*param_1;
  param_1[1] = param_2[1];
  plVar2 = (longlong *)plVar6[1];
  if (*(char *)((longlong)plVar2 + 0x19) != '\0') {
    *plVar6 = (longlong)plVar6;
    *(longlong *)(*param_1 + 0x10) = *param_1;
    return;
  }
  cVar1 = *(char *)(*plVar2 + 0x19);
  plVar5 = (longlong *)*plVar2;
  while (cVar1 == '\0') {
    cVar1 = *(char *)(*plVar5 + 0x19);
    plVar2 = plVar5;
    plVar5 = (longlong *)*plVar5;
  }
  *plVar6 = (longlong)plVar2;
  lVar3 = *(longlong *)(*param_1 + 8);
  lVar4 = *(longlong *)(lVar3 + 0x10);
  cVar1 = *(char *)(lVar4 + 0x19);
  while (cVar1 == '\0') {
    cVar1 = *(char *)(*(longlong *)(lVar4 + 0x10) + 0x19);
    lVar3 = lVar4;
    lVar4 = *(longlong *)(lVar4 + 0x10);
  }
  *(longlong *)(*param_1 + 0x10) = lVar3;
  return;
}

/* ---- FUNC 000284F0 FUN_1800284f0 (308 bytes) ---- */

longlong *
FUN_1800284f0(undefined8 *param_1,undefined8 *param_2,longlong param_3,undefined8 param_4)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong *plVar5;
  
  plVar4 = (longlong *)*param_1;
  if (*(char *)((longlong)param_2 + 0x19) == '\0') {
    plVar1 = operator_new(0x1b0);
    plVar2 = plVar1 + 4;
    *plVar2 = (longlong)&DAT_1800537c8;
    plVar1[5] = 0;
    plVar1[6] = 0;
    plVar1[7] = 0;
    plVar1[8] = 0xf;
    *(undefined1 *)(plVar1 + 5) = 0;
    plVar5 = (longlong *)((longlong)*(int *)(param_2[4] + 4) + (longlong)(param_2 + 4));
    plVar2 = (longlong *)((longlong)*(int *)(*plVar2 + 4) + (longlong)plVar2);
    if (plVar2 != plVar5) {
      plVar3 = plVar5;
      if (0xf < (ulonglong)plVar5[3]) {
        plVar3 = (longlong *)*plVar5;
      }
      FUN_18000ad20(plVar2,plVar3,plVar5[2]);
    }
    CConverter::CConverter((CConverter *)(plVar1 + 9),(CConverter *)(param_2 + 9));
    *plVar1 = (longlong)plVar4;
    plVar1[2] = (longlong)plVar4;
    *(undefined2 *)(plVar1 + 3) = 0;
    plVar1[1] = param_3;
    *(undefined1 *)(plVar1 + 3) = *(undefined1 *)(param_2 + 3);
    if (*(char *)((longlong)plVar4 + 0x19) != '\0') {
      plVar4 = plVar1;
    }
    plVar2 = FUN_1800284f0(param_1,(undefined8 *)*param_2,(longlong)plVar1,param_4);
    *plVar1 = (longlong)plVar2;
    plVar2 = FUN_1800284f0(param_1,(undefined8 *)param_2[2],(longlong)plVar1,param_4);
    plVar1[2] = (longlong)plVar2;
  }
  return plVar4;
}

/* ---- FUNC 00028630 FUN_180028630 (447 bytes) ---- */

undefined8 * FUN_180028630(longlong *param_1,undefined8 *param_2,longlong *param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  int iVar4;
  longlong *plVar5;
  longlong *plVar6;
  longlong *plVar7;
  undefined8 *_Buf1;
  longlong *plVar8;
  undefined8 *_Buf2;
  undefined8 *puVar9;
  longlong *plVar10;
  undefined8 *puVar11;
  ulonglong _Size;
  longlong *local_68;
  longlong *plStack_60;
  longlong *local_58;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  
  lVar1 = *param_1;
  plStack_60 = (longlong *)0x0;
  local_68 = param_1;
  plVar5 = operator_new(0x1b0);
  plVar6 = plVar5 + 4;
  *plVar6 = (longlong)&DAT_1800537c8;
  plVar5[5] = 0;
  plVar5[6] = 0;
  plVar5[7] = 0;
  plVar5[8] = 0xf;
  *(undefined1 *)(plVar5 + 5) = 0;
  plVar10 = (longlong *)((longlong)*(int *)(*param_3 + 4) + (longlong)param_3);
  plVar7 = (longlong *)((longlong)*(int *)(*plVar6 + 4) + (longlong)plVar6);
  plStack_60 = plVar5;
  if (plVar7 != plVar10) {
    plVar8 = plVar10;
    if (0xf < (ulonglong)plVar10[3]) {
      plVar8 = (longlong *)*plVar10;
    }
    FUN_18000ad20(plVar7,plVar8,plVar10[2]);
  }
  CConverter::CConverter((CConverter *)(plVar5 + 9),(CConverter *)(param_3 + 5));
  *plVar5 = lVar1;
  plVar5[1] = lVar1;
  plVar5[2] = lVar1;
  *(undefined2 *)(plVar5 + 3) = 0;
  plVar7 = *(longlong **)(*param_1 + 8);
  uStack_50 = 0;
  local_58 = plVar7;
  if (*(char *)((longlong)plVar7 + 0x19) == '\0') {
    puVar9 = (undefined8 *)((longlong)plVar6 + (longlong)*(int *)(*plVar6 + 4));
    do {
      puVar11 = (undefined8 *)((longlong)*(int *)(plVar7[4] + 4) + (longlong)(plVar7 + 4));
      _Buf2 = puVar11;
      if (0xf < (ulonglong)puVar11[3]) {
        _Buf2 = (undefined8 *)*puVar11;
      }
      _Buf1 = puVar9;
      if (0xf < (ulonglong)puVar9[3]) {
        _Buf1 = (undefined8 *)*puVar9;
      }
      uVar2 = puVar11[2];
      uVar3 = puVar9[2];
      _Size = uVar3;
      if (uVar2 < uVar3) {
        _Size = uVar2;
      }
      local_58 = plVar7;
      iVar4 = memcmp(_Buf1,_Buf2,_Size);
      if (iVar4 == 0) {
        if (uVar3 < uVar2) goto LAB_1800287dd;
LAB_18002877a:
        uStack_50 = 0;
        plVar7 = (longlong *)plVar7[2];
      }
      else {
        if (-1 < iVar4) goto LAB_18002877a;
LAB_1800287dd:
        uStack_50 = 1;
        plVar7 = (longlong *)*plVar7;
      }
    } while (*(char *)((longlong)plVar7 + 0x19) == '\0');
  }
  if (param_1[1] != 0x97b425ed097b42) {
    plStack_60 = (longlong *)CONCAT44(uStack_4c,uStack_50);
    local_68 = local_58;
    plVar6 = FUN_18000a930(param_1,(longlong *)&local_68,plVar5);
    *param_2 = plVar6;
    *(undefined1 *)(param_2 + 1) = 1;
    return param_2;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18000ac90();
}

/* ---- FUNC 000287F0 FUN_1800287f0 (58 bytes) ---- */

longlong * FUN_1800287f0(longlong *param_1,longlong *param_2,longlong *param_3)

{
  ulonglong uVar1;
  int iVar2;
  void *_Buf1;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  ulonglong _Size;
  ulonglong uVar8;
  ulonglong uVar9;
  longlong lVar10;
  undefined8 *puVar11;
  undefined8 *local_res8;
  
  local_res8 = (undefined8 *)*param_1;
  puVar7 = (undefined8 *)local_res8[1];
  puVar11 = local_res8;
  if (*(char *)((longlong)puVar7 + 0x19) == '\0') {
    puVar6 = (undefined8 *)((longlong)*(int *)(*param_3 + 4) + (longlong)param_3);
    puVar5 = puVar7;
    do {
      lVar10 = (longlong)*(int *)(puVar5[4] + 4);
      puVar4 = puVar6;
      if (0xf < (ulonglong)puVar6[3]) {
        puVar4 = (undefined8 *)*puVar6;
      }
      uVar8 = *(ulonglong *)((longlong)puVar5 + lVar10 + 0x38);
      _Buf1 = (void *)((longlong)puVar5 + lVar10 + 0x20);
      if (0xf < uVar8) {
        _Buf1 = *(void **)((longlong)puVar5 + lVar10 + 0x20);
      }
      uVar1 = puVar6[2];
      uVar9 = *(ulonglong *)((longlong)puVar5 + lVar10 + 0x30);
      _Size = uVar9;
      if (uVar1 < uVar9) {
        _Size = uVar1;
      }
      iVar2 = memcmp(_Buf1,puVar4,_Size);
      if (iVar2 == 0) {
        if (uVar1 <= uVar9) goto LAB_180028888;
LAB_1800288c8:
        puVar4 = (undefined8 *)puVar5[2];
      }
      else {
        if (iVar2 < 0) goto LAB_1800288c8;
LAB_180028888:
        if (*(char *)((longlong)puVar11 + 0x19) != '\0') {
          puVar4 = (undefined8 *)(lVar10 + 0x20 + (longlong)puVar5);
          if (0xf < uVar8) {
            puVar4 = (undefined8 *)*puVar4;
          }
          puVar3 = puVar6;
          if (0xf < (ulonglong)puVar6[3]) {
            puVar3 = (undefined8 *)*puVar6;
          }
          uVar8 = uVar1;
          if (uVar9 < uVar1) {
            uVar8 = uVar9;
          }
          iVar2 = memcmp(puVar3,puVar4,uVar8);
          if (iVar2 == 0) {
            if (uVar1 < uVar9) goto LAB_1800288d8;
          }
          else if (iVar2 < 0) {
LAB_1800288d8:
            puVar11 = puVar5;
          }
        }
        puVar4 = (undefined8 *)*puVar5;
        local_res8 = puVar5;
      }
      puVar5 = puVar4;
    } while (*(char *)((longlong)puVar4 + 0x19) == '\0');
  }
  if (*(char *)((longlong)puVar11 + 0x19) == '\0') {
    puVar7 = (undefined8 *)*puVar11;
  }
  if (*(char *)((longlong)puVar7 + 0x19) == '\0') {
    puVar5 = (undefined8 *)((longlong)*(int *)(*param_3 + 4) + (longlong)param_3);
    do {
      puVar4 = (undefined8 *)((longlong)puVar7 + (longlong)*(int *)(puVar7[4] + 4) + 0x20);
      puVar6 = puVar4;
      if (0xf < (ulonglong)puVar4[3]) {
        puVar6 = (undefined8 *)*puVar4;
      }
      puVar3 = puVar5;
      if (0xf < (ulonglong)puVar5[3]) {
        puVar3 = (undefined8 *)*puVar5;
      }
      uVar8 = puVar4[2];
      uVar1 = puVar5[2];
      uVar9 = uVar1;
      if (uVar8 < uVar1) {
        uVar9 = uVar8;
      }
      iVar2 = memcmp(puVar3,puVar6,uVar9);
      if (iVar2 == 0) {
        if (uVar8 <= uVar1) goto LAB_180028966;
LAB_180028990:
        puVar6 = (undefined8 *)*puVar7;
        puVar11 = puVar7;
      }
      else {
        if (iVar2 < 0) goto LAB_180028990;
LAB_180028966:
        puVar6 = (undefined8 *)puVar7[2];
      }
      puVar7 = puVar6;
    } while (*(char *)((longlong)puVar6 + 0x19) == '\0');
  }
  *param_2 = (longlong)local_res8;
  param_2[1] = (longlong)puVar11;
  return param_2;
}

/* ---- FUNC 0002882A FUN_18002882a (213 bytes) ---- */

undefined8 * FUN_18002882a(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  ulonglong uVar1;
  int iVar2;
  longlong in_RAX;
  void *_Buf1;
  undefined8 *_Buf1_00;
  undefined8 *puVar3;
  undefined8 *unaff_RBX;
  undefined8 *puVar4;
  undefined8 *unaff_RDI;
  ulonglong _Size;
  ulonglong uVar5;
  undefined8 *puVar6;
  ulonglong uVar7;
  longlong lVar8;
  undefined8 *unaff_R15;
  undefined8 *in_stack_00000060;
  undefined8 *in_stack_00000068;
  longlong *in_stack_00000070;
  
  puVar4 = (undefined8 *)(*(int *)(in_RAX + 4) + param_3);
  do {
    lVar8 = (longlong)*(int *)(unaff_RBX[4] + 4);
    puVar3 = puVar4;
    if (0xf < (ulonglong)puVar4[3]) {
      puVar3 = (undefined8 *)*puVar4;
    }
    uVar5 = *(ulonglong *)((longlong)unaff_RBX + lVar8 + 0x38);
    _Buf1 = (void *)((longlong)unaff_RBX + lVar8 + 0x20);
    if (0xf < uVar5) {
      _Buf1 = *(void **)((longlong)unaff_RBX + lVar8 + 0x20);
    }
    uVar1 = puVar4[2];
    uVar7 = *(ulonglong *)((longlong)unaff_RBX + lVar8 + 0x30);
    _Size = uVar7;
    if (uVar1 < uVar7) {
      _Size = uVar1;
    }
    iVar2 = memcmp(_Buf1,puVar3,_Size);
    if (iVar2 == 0) {
      if (uVar1 <= uVar7) goto LAB_180028888;
LAB_1800288c8:
      puVar3 = (undefined8 *)unaff_RBX[2];
    }
    else {
      if (iVar2 < 0) goto LAB_1800288c8;
LAB_180028888:
      if (*(char *)((longlong)unaff_R15 + 0x19) != '\0') {
        puVar3 = (undefined8 *)(lVar8 + 0x20 + (longlong)unaff_RBX);
        if (0xf < uVar5) {
          puVar3 = (undefined8 *)*puVar3;
        }
        puVar6 = puVar4;
        if (0xf < (ulonglong)puVar4[3]) {
          puVar6 = (undefined8 *)*puVar4;
        }
        uVar5 = uVar1;
        if (uVar7 < uVar1) {
          uVar5 = uVar7;
        }
        iVar2 = memcmp(puVar6,puVar3,uVar5);
        if (iVar2 == 0) {
          if (uVar1 < uVar7) goto LAB_1800288d8;
        }
        else if (iVar2 < 0) {
LAB_1800288d8:
          unaff_R15 = unaff_RBX;
        }
      }
      puVar3 = (undefined8 *)*unaff_RBX;
      in_stack_00000060 = unaff_RBX;
    }
    unaff_RBX = puVar3;
  } while (*(char *)((longlong)puVar3 + 0x19) == '\0');
  if (*(char *)((longlong)unaff_R15 + 0x19) == '\0') {
    unaff_RDI = (undefined8 *)*unaff_R15;
  }
  if (*(char *)((longlong)unaff_RDI + 0x19) == '\0') {
    puVar4 = (undefined8 *)
             ((longlong)*(int *)(*in_stack_00000070 + 4) + (longlong)in_stack_00000070);
    do {
      puVar6 = (undefined8 *)((longlong)unaff_RDI + (longlong)*(int *)(unaff_RDI[4] + 4) + 0x20);
      puVar3 = puVar6;
      if (0xf < (ulonglong)puVar6[3]) {
        puVar3 = (undefined8 *)*puVar6;
      }
      _Buf1_00 = puVar4;
      if (0xf < (ulonglong)puVar4[3]) {
        _Buf1_00 = (undefined8 *)*puVar4;
      }
      uVar5 = puVar6[2];
      uVar1 = puVar4[2];
      uVar7 = uVar1;
      if (uVar5 < uVar1) {
        uVar7 = uVar5;
      }
      iVar2 = memcmp(_Buf1_00,puVar3,uVar7);
      if (iVar2 == 0) {
        if (uVar5 <= uVar1) goto LAB_180028966;
LAB_180028990:
        puVar3 = (undefined8 *)*unaff_RDI;
        unaff_R15 = unaff_RDI;
      }
      else {
        if (iVar2 < 0) goto LAB_180028990;
LAB_180028966:
        puVar3 = (undefined8 *)unaff_RDI[2];
      }
      unaff_RDI = puVar3;
    } while (*(char *)((longlong)puVar3 + 0x19) == '\0');
  }
  *in_stack_00000068 = in_stack_00000060;
  in_stack_00000068[1] = unaff_R15;
  return in_stack_00000068;
}

/* ---- FUNC 000288FF FUN_1800288ff (153 bytes) ---- */

void FUN_1800288ff(undefined8 param_1,undefined8 param_2,longlong *param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  int iVar3;
  undefined8 *_Buf1;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined8 *unaff_RDI;
  undefined8 *puVar6;
  ulonglong _Size;
  undefined8 *unaff_R12;
  undefined8 unaff_R14;
  undefined8 *unaff_R15;
  
  if (*(char *)((longlong)unaff_R15 + 0x19) == '\0') {
    unaff_RDI = (undefined8 *)*unaff_R15;
  }
  if (*(char *)((longlong)unaff_RDI + 0x19) == '\0') {
    puVar5 = (undefined8 *)((longlong)*(int *)(*param_3 + 4) + (longlong)param_3);
    do {
      puVar6 = (undefined8 *)((longlong)unaff_RDI + (longlong)*(int *)(unaff_RDI[4] + 4) + 0x20);
      puVar4 = puVar6;
      if (0xf < (ulonglong)puVar6[3]) {
        puVar4 = (undefined8 *)*puVar6;
      }
      _Buf1 = puVar5;
      if (0xf < (ulonglong)puVar5[3]) {
        _Buf1 = (undefined8 *)*puVar5;
      }
      uVar1 = puVar6[2];
      uVar2 = puVar5[2];
      _Size = uVar2;
      if (uVar1 < uVar2) {
        _Size = uVar1;
      }
      iVar3 = memcmp(_Buf1,puVar4,_Size);
      if (iVar3 == 0) {
        if (uVar2 < uVar1) goto LAB_180028990;
LAB_180028966:
        puVar4 = (undefined8 *)unaff_RDI[2];
      }
      else {
        if (-1 < iVar3) goto LAB_180028966;
LAB_180028990:
        puVar4 = (undefined8 *)*unaff_RDI;
        unaff_R15 = unaff_RDI;
      }
      unaff_RDI = puVar4;
    } while (*(char *)((longlong)puVar4 + 0x19) == '\0');
  }
  *unaff_R12 = unaff_R14;
  unaff_R12[1] = unaff_R15;
  return;
}

/* ---- FUNC 000289A0 FUN_1800289a0 (32 bytes) ---- */

void FUN_1800289a0(undefined8 param_1,undefined8 param_2,longlong *param_3)

{
  char cVar1;
  longlong *plVar2;
  
  cVar1 = *(char *)((longlong)param_3 + 0x19);
  while (cVar1 == '\0') {
    FUN_1800289a0(param_1,param_2,(longlong *)param_3[2]);
    plVar2 = (longlong *)*param_3;
    CConverter::~CConverter((CConverter *)(param_3 + 9));
    FUN_180009900((longlong)(param_3 + 4));
    operator_delete(param_3);
    param_3 = plVar2;
    cVar1 = *(char *)((longlong)plVar2 + 0x19);
  }
  return;
}

/* ---- FUNC 000289C0 FUN_1800289c0 (84 bytes) ---- */

void FUN_1800289c0(void)

{
  longlong *plVar1;
  longlong *unaff_RBX;
  undefined8 unaff_RBP;
  undefined8 unaff_R14;
  
  do {
    FUN_1800289a0(unaff_R14,unaff_RBP,(longlong *)unaff_RBX[2]);
    plVar1 = (longlong *)*unaff_RBX;
    CConverter::~CConverter((CConverter *)(unaff_RBX + 9));
    FUN_180009900((longlong)(unaff_RBX + 4));
    operator_delete(unaff_RBX);
    unaff_RBX = plVar1;
  } while (*(char *)((longlong)plVar1 + 0x19) == '\0');
  return;
}

/* ---- FUNC 00028A14 FUN_180028a14 (17 bytes) ---- */

void FUN_180028a14(void)

{
  return;
}

/* ---- FUNC 00028A30 CConvertMgr (121 bytes) ---- */

/* public: __cdecl CConvertMgr::CConvertMgr(class CConvertMgr const & __ptr64) __ptr64 */

CConvertMgr * __thiscall CConvertMgr::CConvertMgr(CConvertMgr *this,CConvertMgr *param_1)

{
  CConvertMgr *pCVar1;
  void *pvVar2;
  undefined8 in_R8;
  undefined8 in_R9;
  
                    /* 0x28a30  22  ??0CConvertMgr@@QEAA@AEBV0@@Z */
  *(undefined ***)this = vftable;
  pCVar1 = this + 8;
  *(longlong *)pCVar1 = 0;
  *(undefined8 *)(this + 0x10) = 0;
  pvVar2 = operator_new(0x1b0);
  *(void **)pvVar2 = pvVar2;
  *(void **)((longlong)pvVar2 + 8) = pvVar2;
  *(void **)((longlong)pvVar2 + 0x10) = pvVar2;
  *(undefined2 *)((longlong)pvVar2 + 0x18) = 0x101;
  *(void **)pCVar1 = pvVar2;
  FUN_180028440((longlong *)pCVar1,(longlong *)(param_1 + 8),in_R8,in_R9);
  return this;
}

/* ---- FUNC 00028AB0 CConvertMgr (85 bytes) ---- */

/* public: __cdecl CConvertMgr::CConvertMgr(void) __ptr64 */

CConvertMgr * __thiscall CConvertMgr::CConvertMgr(CConvertMgr *this)

{
  void *pvVar1;
  
                    /* 0x28ab0  23  ??0CConvertMgr@@QEAA@XZ */
  *(undefined ***)this = vftable;
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)(this + 0x10) = 0;
  pvVar1 = operator_new(0x1b0);
  *(void **)pvVar1 = pvVar1;
  *(void **)((longlong)pvVar1 + 8) = pvVar1;
  *(void **)((longlong)pvVar1 + 0x10) = pvVar1;
  *(undefined2 *)((longlong)pvVar1 + 0x18) = 0x101;
  *(void **)(this + 8) = pvVar1;
  return this;
}

/* ---- FUNC 00028B10 CConverter (785 bytes) ---- */

/* public: __cdecl CConverter::CConverter(class CConverter const & __ptr64) __ptr64 */

CConverter * __thiscall CConverter::CConverter(CConverter *this,CConverter *param_1)

{
  CConverter *pCVar1;
  CConverter *pCVar2;
  CConverter *pCVar3;
  CConverter *pCVar4;
  undefined8 uVar5;
  CConverter *pCVar6;
  CConverter *pCVar7;
  CConverter *pCVar8;
  CConverter *pCVar9;
  CConverter *pCVar10;
  
                    /* 0x28b10  24  ??0CConverter@@QEAA@AEBV0@@Z */
  *(undefined ***)this = vftable;
  pCVar9 = this + 0x20;
  *(undefined **)pCVar9 = &DAT_1800537c8;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined8 *)(this + 0x38) = 0;
  *(undefined8 *)(this + 0x40) = 0xf;
  this[0x28] = (CConverter)0x0;
  pCVar10 = this + 0x48;
  *(undefined **)pCVar10 = &DAT_1800537c8;
  *(undefined8 *)(this + 0x50) = 0;
  *(undefined8 *)(this + 0x58) = 0;
  *(undefined8 *)(this + 0x60) = 0;
  *(undefined8 *)(this + 0x68) = 0xf;
  this[0x50] = (CConverter)0x0;
  pCVar7 = this + 0x70;
  *(undefined **)pCVar7 = &DAT_1800537c8;
  *(undefined8 *)(this + 0x78) = 0;
  *(undefined8 *)(this + 0x80) = 0;
  *(undefined8 *)(this + 0x88) = 0;
  *(undefined8 *)(this + 0x90) = 0xf;
  this[0x78] = (CConverter)0x0;
  pCVar1 = this + 0x98;
  *(undefined **)pCVar1 = &DAT_1800537c8;
  *(undefined8 *)(this + 0xa0) = 0;
  *(undefined8 *)(this + 0xa8) = 0;
  *(undefined8 *)(this + 0xb0) = 0;
  *(undefined8 *)(this + 0xb8) = 0xf;
  this[0xa0] = (CConverter)0x0;
  pCVar2 = this + 0xc0;
  *(undefined **)pCVar2 = &DAT_1800537c8;
  *(undefined8 *)(this + 200) = 0;
  *(undefined8 *)(this + 0xd0) = 0;
  *(undefined8 *)(this + 0xd8) = 0;
  *(undefined8 *)(this + 0xe0) = 0xf;
  this[200] = (CConverter)0x0;
  pCVar3 = this + 0xe8;
  *(undefined **)pCVar3 = &DAT_1800537c8;
  *(undefined8 *)(this + 0xf0) = 0;
  *(undefined8 *)(this + 0xf8) = 0;
  *(undefined8 *)(this + 0x100) = 0;
  *(undefined8 *)(this + 0x108) = 0xf;
  this[0xf0] = (CConverter)0x0;
  pCVar4 = this + 0x110;
  *(undefined **)pCVar4 = &DAT_1800537c8;
  *(undefined8 *)(this + 0x118) = 0;
  *(undefined8 *)(this + 0x120) = 0;
  *(undefined8 *)(this + 0x128) = 0;
  *(undefined8 *)(this + 0x130) = 0xf;
  this[0x118] = (CConverter)0x0;
  *(undefined **)(this + 0x138) = &DAT_1800537c8;
  *(undefined8 *)(this + 0x140) = 0;
  *(undefined8 *)(this + 0x148) = 0;
  *(undefined8 *)(this + 0x150) = 0;
  *(undefined8 *)(this + 0x158) = 0xf;
  this[0x140] = (CConverter)0x0;
  uVar5 = *(undefined8 *)(param_1 + 0x14);
  *(undefined8 *)(this + 0xc) = *(undefined8 *)(param_1 + 0xc);
  *(undefined8 *)(this + 0x14) = uVar5;
  pCVar8 = param_1 + 0x20 + *(int *)(*(longlong *)(param_1 + 0x20) + 4);
  if (pCVar9 + *(int *)(*(longlong *)pCVar9 + 4) != pCVar8) {
    pCVar6 = pCVar8;
    if (0xf < *(ulonglong *)(pCVar8 + 0x18)) {
      pCVar6 = *(CConverter **)pCVar8;
    }
    FUN_18000ad20((longlong *)(pCVar9 + *(int *)(*(longlong *)pCVar9 + 4)),pCVar6,
                  *(size_t *)(pCVar8 + 0x10));
  }
  pCVar9 = param_1 + 0x48 + *(int *)(*(longlong *)(param_1 + 0x48) + 4);
  if (pCVar10 + *(int *)(*(longlong *)pCVar10 + 4) != pCVar9) {
    pCVar8 = pCVar9;
    if (0xf < *(ulonglong *)(pCVar9 + 0x18)) {
      pCVar8 = *(CConverter **)pCVar9;
    }
    FUN_18000ad20((longlong *)(pCVar10 + *(int *)(*(longlong *)pCVar10 + 4)),pCVar8,
                  *(size_t *)(pCVar9 + 0x10));
  }
  pCVar9 = param_1 + 0x70 + *(int *)(*(longlong *)(param_1 + 0x70) + 4);
  if (pCVar7 + *(int *)(*(longlong *)pCVar7 + 4) != pCVar9) {
    pCVar10 = pCVar9;
    if (0xf < *(ulonglong *)(pCVar9 + 0x18)) {
      pCVar10 = *(CConverter **)pCVar9;
    }
    FUN_18000ad20((longlong *)(pCVar7 + *(int *)(*(longlong *)pCVar7 + 4)),pCVar10,
                  *(size_t *)(pCVar9 + 0x10));
  }
  pCVar9 = param_1 + 0x98 + *(int *)(*(longlong *)(param_1 + 0x98) + 4);
  if (pCVar1 + *(int *)(*(longlong *)pCVar1 + 4) != pCVar9) {
    pCVar10 = pCVar9;
    if (0xf < *(ulonglong *)(pCVar9 + 0x18)) {
      pCVar10 = *(CConverter **)pCVar9;
    }
    FUN_18000ad20((longlong *)(pCVar1 + *(int *)(*(longlong *)pCVar1 + 4)),pCVar10,
                  *(size_t *)(pCVar9 + 0x10));
  }
  pCVar9 = param_1 + 0xc0 + *(int *)(*(longlong *)(param_1 + 0xc0) + 4);
  if (pCVar2 + *(int *)(*(longlong *)pCVar2 + 4) != pCVar9) {
    pCVar10 = pCVar9;
    if (0xf < *(ulonglong *)(pCVar9 + 0x18)) {
      pCVar10 = *(CConverter **)pCVar9;
    }
    FUN_18000ad20((longlong *)(pCVar2 + *(int *)(*(longlong *)pCVar2 + 4)),pCVar10,
                  *(size_t *)(pCVar9 + 0x10));
  }
  pCVar9 = param_1 + 0xe8 + *(int *)(*(longlong *)(param_1 + 0xe8) + 4);
  if (pCVar3 + *(int *)(*(longlong *)pCVar3 + 4) != pCVar9) {
    pCVar10 = pCVar9;
    if (0xf < *(ulonglong *)(pCVar9 + 0x18)) {
      pCVar10 = *(CConverter **)pCVar9;
    }
    FUN_18000ad20((longlong *)(pCVar3 + *(int *)(*(longlong *)pCVar3 + 4)),pCVar10,
                  *(size_t *)(pCVar9 + 0x10));
  }
  pCVar9 = param_1 + 0x110 + *(int *)(*(longlong *)(param_1 + 0x110) + 4);
  if (pCVar4 + *(int *)(*(longlong *)pCVar4 + 4) != pCVar9) {
    pCVar10 = pCVar9;
    if (0xf < *(ulonglong *)(pCVar9 + 0x18)) {
      pCVar10 = *(CConverter **)pCVar9;
    }
    FUN_18000ad20((longlong *)(pCVar4 + *(int *)(*(longlong *)pCVar4 + 4)),pCVar10,
                  *(size_t *)(pCVar9 + 0x10));
  }
  pCVar10 = param_1 + 0x138 + *(int *)(*(longlong *)(param_1 + 0x138) + 4);
  pCVar9 = this + 0x138;
  if (pCVar9 + *(int *)(*(longlong *)pCVar9 + 4) != pCVar10) {
    pCVar7 = pCVar10;
    if (0xf < *(ulonglong *)(pCVar10 + 0x18)) {
      pCVar7 = *(CConverter **)pCVar10;
    }
    FUN_18000ad20((longlong *)(pCVar9 + *(int *)(*(longlong *)pCVar9 + 4)),pCVar7,
                  *(size_t *)(pCVar10 + 0x10));
  }
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0x160) = *(undefined4 *)(param_1 + 0x160);
  return this;
}

/* ---- FUNC 00028E30 CConverter (294 bytes) ---- */

/* public: __cdecl CConverter::CConverter(void) __ptr64 */

CConverter * __thiscall CConverter::CConverter(CConverter *this)

{
                    /* 0x28e30  25  ??0CConverter@@QEAA@XZ */
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 8) = 0;
  *(undefined **)(this + 0x20) = &DAT_1800537c8;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined8 *)(this + 0x38) = 0;
  *(undefined8 *)(this + 0x40) = 0xf;
  this[0x28] = (CConverter)0x0;
  *(undefined **)(this + 0x48) = &DAT_1800537c8;
  *(undefined8 *)(this + 0x50) = 0;
  *(undefined8 *)(this + 0x58) = 0;
  *(undefined8 *)(this + 0x60) = 0;
  *(undefined8 *)(this + 0x68) = 0xf;
  this[0x50] = (CConverter)0x0;
  *(undefined **)(this + 0x70) = &DAT_1800537c8;
  *(undefined8 *)(this + 0x78) = 0;
  *(undefined8 *)(this + 0x80) = 0;
  *(undefined8 *)(this + 0x88) = 0;
  *(undefined8 *)(this + 0x90) = 0xf;
  this[0x78] = (CConverter)0x0;
  *(undefined **)(this + 0x98) = &DAT_1800537c8;
  *(undefined8 *)(this + 0xa0) = 0;
  *(undefined8 *)(this + 0xa8) = 0;
  *(undefined8 *)(this + 0xb0) = 0;
  *(undefined8 *)(this + 0xb8) = 0xf;
  this[0xa0] = (CConverter)0x0;
  *(undefined **)(this + 0xc0) = &DAT_1800537c8;
  *(undefined8 *)(this + 200) = 0;
  *(undefined8 *)(this + 0xd0) = 0;
  *(undefined8 *)(this + 0xd8) = 0;
  *(undefined8 *)(this + 0xe0) = 0xf;
  this[200] = (CConverter)0x0;
  *(undefined **)(this + 0xe8) = &DAT_1800537c8;
  *(undefined8 *)(this + 0xf0) = 0;
  *(undefined8 *)(this + 0xf8) = 0;
  *(undefined8 *)(this + 0x100) = 0;
  *(undefined8 *)(this + 0x108) = 0xf;
  this[0xf0] = (CConverter)0x0;
  *(undefined **)(this + 0x110) = &DAT_1800537c8;
  *(undefined8 *)(this + 0x118) = 0;
  *(undefined8 *)(this + 0x120) = 0;
  *(undefined8 *)(this + 0x128) = 0;
  *(undefined8 *)(this + 0x130) = 0xf;
  this[0x118] = (CConverter)0x0;
  *(undefined **)(this + 0x138) = &DAT_1800537c8;
  *(undefined8 *)(this + 0x140) = 0;
  *(undefined8 *)(this + 0x148) = 0;
  *(undefined8 *)(this + 0x150) = 0;
  *(undefined8 *)(this + 0x158) = 0xf;
  this[0x140] = (CConverter)0x0;
  return this;
}

/* ---- FUNC 00028F80 FUN_180028f80 (57 bytes) ---- */

void FUN_180028f80(undefined8 *param_1)

{
  longlong *plVar1;
  
  plVar1 = (longlong *)param_1[1];
  if (plVar1 != (longlong *)0x0) {
    FUN_1800289a0(plVar1,*param_1,*(longlong **)(*plVar1 + 8));
    operator_delete((void *)*plVar1);
    return;
  }
  return;
}

/* ---- FUNC 00028FC0 FUN_180028fc0 (70 bytes) ---- */

void FUN_180028fc0(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 8);
  if (lVar1 != 0) {
    CConverter::~CConverter((CConverter *)(lVar1 + 0x48));
    FUN_180009900(lVar1 + 0x20);
  }
  if (*(void **)(param_1 + 8) != (void *)0x0) {
    operator_delete(*(void **)(param_1 + 8));
  }
  return;
}

/* ---- FUNC 00029010 FUN_180029010 (31 bytes) ---- */

void FUN_180029010(longlong param_1)

{
  CConverter::~CConverter((CConverter *)(param_1 + 0x28));
  FUN_180009900(param_1);
  return;
}

/* ---- FUNC 00029030 ~CConvertMgr (56 bytes) ---- */

/* public: virtual __cdecl CConvertMgr::~CConvertMgr(void) __ptr64 */

void __thiscall CConvertMgr::~CConvertMgr(CConvertMgr *this)

{
  CConvertMgr *pCVar1;
  
                    /* 0x29030  34  ??1CConvertMgr@@UEAA@XZ */
  pCVar1 = this + 8;
  *(undefined ***)this = vftable;
  FUN_1800289a0(pCVar1,pCVar1,*(longlong **)(*(longlong *)pCVar1 + 8));
  operator_delete(*(void **)pCVar1);
  return;
}

/* ---- FUNC 00029070 ~CConverter (111 bytes) ---- */

/* public: virtual __cdecl CConverter::~CConverter(void) __ptr64 */

void __thiscall CConverter::~CConverter(CConverter *this)

{
                    /* 0x29070  35  ??1CConverter@@UEAA@XZ */
  *(undefined ***)this = vftable;
  FUN_180009900((longlong)(this + 0x138));
  FUN_180009900((longlong)(this + 0x110));
  FUN_180009900((longlong)(this + 0xe8));
  FUN_180009900((longlong)(this + 0xc0));
  FUN_180009900((longlong)(this + 0x98));
  FUN_180009900((longlong)(this + 0x70));
  FUN_180009900((longlong)(this + 0x48));
  FUN_180009900((longlong)(this + 0x20));
  return;
}

/* ---- FUNC 000290E0 operator= (31 bytes) ---- */

/* public: class CConvertMgr & __ptr64 __cdecl CConvertMgr::operator=(class CConvertMgr const &
   __ptr64) __ptr64 */

CConvertMgr * __thiscall CConvertMgr::operator=(CConvertMgr *this,CConvertMgr *param_1)

{
  CConvertMgr *pCVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 in_R9;
  
                    /* 0x290e0  43  ??4CConvertMgr@@QEAAAEAV0@AEBV0@@Z */
  pCVar1 = this + 8;
  if (pCVar1 != param_1 + 8) {
    lVar2 = *(longlong *)pCVar1;
    plVar3 = *(longlong **)(lVar2 + 8);
    FUN_1800289a0(pCVar1,pCVar1,plVar3);
    *(longlong *)(lVar2 + 8) = lVar2;
    *(longlong *)lVar2 = lVar2;
    *(longlong *)(lVar2 + 0x10) = lVar2;
    *(undefined8 *)(this + 0x10) = 0;
    FUN_180028440((longlong *)pCVar1,(longlong *)(param_1 + 8),plVar3,in_R9);
  }
  return this;
}

/* ---- FUNC 000290FF FUN_1800290ff (58 bytes) ---- */

void FUN_1800290ff(void)

{
  longlong lVar1;
  longlong *unaff_RBP;
  longlong *unaff_RDI;
  longlong *plVar2;
  undefined8 in_R9;
  
  lVar1 = *unaff_RDI;
  plVar2 = *(longlong **)(lVar1 + 8);
  FUN_1800289a0(unaff_RDI,unaff_RDI,plVar2);
  *(longlong *)(lVar1 + 8) = lVar1;
  *(longlong *)lVar1 = lVar1;
  *(longlong *)(lVar1 + 0x10) = lVar1;
  unaff_RDI[1] = 0;
  FUN_180028440(unaff_RDI,unaff_RBP,plVar2,in_R9);
  return;
}

/* ---- FUNC 00029139 FUN_180029139 (19 bytes) ---- */

void FUN_180029139(void)

{
  return;
}

/* ---- FUNC 00029150 operator= (528 bytes) ---- */

/* public: class CConverter & __ptr64 __cdecl CConverter::operator=(class CConverter const &
   __ptr64) __ptr64 */

CConverter * __thiscall CConverter::operator=(CConverter *this,CConverter *param_1)

{
  CConverter *pCVar1;
  undefined8 uVar2;
  CConverter *pCVar3;
  CConverter *pCVar4;
  
                    /* 0x29150  44  ??4CConverter@@QEAAAEAV0@AEBV0@@Z */
  pCVar1 = this + 0x20;
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  uVar2 = *(undefined8 *)(param_1 + 0x14);
  *(undefined8 *)(this + 0xc) = *(undefined8 *)(param_1 + 0xc);
  *(undefined8 *)(this + 0x14) = uVar2;
  pCVar4 = param_1 + 0x20 + *(int *)(*(longlong *)(param_1 + 0x20) + 4);
  if (pCVar1 + *(int *)(*(longlong *)pCVar1 + 4) != pCVar4) {
    pCVar3 = pCVar4;
    if (0xf < *(ulonglong *)(pCVar4 + 0x18)) {
      pCVar3 = *(CConverter **)pCVar4;
    }
    FUN_18000ad20((longlong *)(pCVar1 + *(int *)(*(longlong *)pCVar1 + 4)),pCVar3,
                  *(size_t *)(pCVar4 + 0x10));
  }
  pCVar1 = this + 0x48;
  pCVar4 = param_1 + (longlong)*(int *)(*(longlong *)(param_1 + 0x48) + 4) + 0x48;
  if (pCVar1 + *(int *)(*(longlong *)pCVar1 + 4) != pCVar4) {
    pCVar3 = pCVar4;
    if (0xf < *(ulonglong *)(pCVar4 + 0x18)) {
      pCVar3 = *(CConverter **)pCVar4;
    }
    FUN_18000ad20((longlong *)(pCVar1 + *(int *)(*(longlong *)pCVar1 + 4)),pCVar3,
                  *(size_t *)(pCVar4 + 0x10));
  }
  pCVar1 = this + 0x70;
  pCVar4 = param_1 + (longlong)*(int *)(*(longlong *)(param_1 + 0x70) + 4) + 0x70;
  if (pCVar1 + *(int *)(*(longlong *)pCVar1 + 4) != pCVar4) {
    pCVar3 = pCVar4;
    if (0xf < *(ulonglong *)(pCVar4 + 0x18)) {
      pCVar3 = *(CConverter **)pCVar4;
    }
    FUN_18000ad20((longlong *)(pCVar1 + *(int *)(*(longlong *)pCVar1 + 4)),pCVar3,
                  *(size_t *)(pCVar4 + 0x10));
  }
  pCVar1 = this + 0x98;
  pCVar4 = param_1 + 0x98 + *(int *)(*(longlong *)(param_1 + 0x98) + 4);
  if (pCVar1 + *(int *)(*(longlong *)pCVar1 + 4) != pCVar4) {
    pCVar3 = pCVar4;
    if (0xf < *(ulonglong *)(pCVar4 + 0x18)) {
      pCVar3 = *(CConverter **)pCVar4;
    }
    FUN_18000ad20((longlong *)(pCVar1 + *(int *)(*(longlong *)pCVar1 + 4)),pCVar3,
                  *(size_t *)(pCVar4 + 0x10));
  }
  pCVar1 = this + 0xc0;
  pCVar4 = param_1 + 0xc0 + *(int *)(*(longlong *)(param_1 + 0xc0) + 4);
  if (pCVar1 + *(int *)(*(longlong *)pCVar1 + 4) != pCVar4) {
    pCVar3 = pCVar4;
    if (0xf < *(ulonglong *)(pCVar4 + 0x18)) {
      pCVar3 = *(CConverter **)pCVar4;
    }
    FUN_18000ad20((longlong *)(pCVar1 + *(int *)(*(longlong *)pCVar1 + 4)),pCVar3,
                  *(size_t *)(pCVar4 + 0x10));
  }
  pCVar1 = this + 0xe8;
  pCVar4 = param_1 + 0xe8 + *(int *)(*(longlong *)(param_1 + 0xe8) + 4);
  if (pCVar1 + *(int *)(*(longlong *)pCVar1 + 4) != pCVar4) {
    pCVar3 = pCVar4;
    if (0xf < *(ulonglong *)(pCVar4 + 0x18)) {
      pCVar3 = *(CConverter **)pCVar4;
    }
    FUN_18000ad20((longlong *)(pCVar1 + *(int *)(*(longlong *)pCVar1 + 4)),pCVar3,
                  *(size_t *)(pCVar4 + 0x10));
  }
  pCVar1 = this + 0x110;
  pCVar4 = param_1 + 0x110 + *(int *)(*(longlong *)(param_1 + 0x110) + 4);
  if (pCVar1 + *(int *)(*(longlong *)pCVar1 + 4) != pCVar4) {
    pCVar3 = pCVar4;
    if (0xf < *(ulonglong *)(pCVar4 + 0x18)) {
      pCVar3 = *(CConverter **)pCVar4;
    }
    FUN_18000ad20((longlong *)(pCVar1 + *(int *)(*(longlong *)pCVar1 + 4)),pCVar3,
                  *(size_t *)(pCVar4 + 0x10));
  }
  pCVar1 = this + 0x138;
  pCVar4 = param_1 + 0x138 + *(int *)(*(longlong *)(param_1 + 0x138) + 4);
  if (pCVar1 + *(int *)(*(longlong *)pCVar1 + 4) != pCVar4) {
    pCVar3 = pCVar4;
    if (0xf < *(ulonglong *)(pCVar4 + 0x18)) {
      pCVar3 = *(CConverter **)pCVar4;
    }
    FUN_18000ad20((longlong *)(pCVar1 + *(int *)(*(longlong *)pCVar1 + 4)),pCVar3,
                  *(size_t *)(pCVar4 + 0x10));
  }
  *(undefined4 *)(this + 0x160) = *(undefined4 *)(param_1 + 0x160);
  return this;
}

/* ---- FUNC 00029360 FUN_180029360 (48 bytes) ---- */

longlong * FUN_180029360(longlong *param_1,void *param_2)

{
  longlong lVar1;
  longlong *plVar2;
  ulonglong _Size;
  
  _Size = 0xffffffffffffffff;
  do {
    _Size = _Size + 1;
  } while (*(char *)((longlong)param_2 + _Size) != '\0');
  lVar1 = param_1[2];
  if (_Size <= (ulonglong)(param_1[3] - lVar1)) {
    param_1[2] = lVar1 + _Size;
    plVar2 = param_1;
    if (0xf < (ulonglong)param_1[3]) {
      plVar2 = (longlong *)*param_1;
    }
    memmove((void *)((longlong)plVar2 + lVar1),param_2,_Size);
    *(undefined1 *)((longlong)plVar2 + lVar1 + _Size) = 0;
    return param_1;
  }
  plVar2 = FUN_180017f00(param_1,_Size,0,param_2,_Size);
  return plVar2;
}

/* ---- FUNC 00029390 FUN_180029390 (63 bytes) ---- */

void FUN_180029390(longlong param_1,void *param_2,ulonglong param_3)

{
  undefined8 *unaff_RSI;
  size_t unaff_RDI;
  
  unaff_RSI[2] = param_1 + unaff_RDI;
  if (0xf < param_3) {
    unaff_RSI = (undefined8 *)*unaff_RSI;
  }
  memmove((void *)((longlong)unaff_RSI + param_1),param_2,unaff_RDI);
  *(undefined1 *)((longlong)unaff_RSI + param_1 + unaff_RDI) = 0;
  return;
}

/* ---- FUNC 000293CF FUN_1800293cf (33 bytes) ---- */

void FUN_1800293cf(undefined8 param_1,void *param_2)

{
  undefined8 *unaff_RSI;
  ulonglong unaff_RDI;
  
  FUN_180017f00(unaff_RSI,unaff_RDI,0,param_2,unaff_RDI);
  return;
}

/* ---- FUNC 000293F0 FUN_1800293f0 (139 bytes) ---- */

CConvertMgr * FUN_1800293f0(CConvertMgr *param_1,uint param_2)

{
  if ((param_2 & 2) != 0) {
    _eh_vector_destructor_iterator_
              (param_1,0x18,*(__uint64 *)(param_1 + -8),CConvertMgr::~CConvertMgr);
    if ((param_2 & 1) != 0) {
      operator_delete__(param_1 + -8);
    }
    return param_1 + -8;
  }
  CConvertMgr::~CConvertMgr(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

/* ---- FUNC 00029480 FUN_180029480 (135 bytes) ---- */

CConverter * FUN_180029480(CConverter *param_1,uint param_2)

{
  if ((param_2 & 2) != 0) {
    _eh_vector_destructor_iterator_
              (param_1,0x168,*(__uint64 *)(param_1 + -8),CConverter::~CConverter);
    if ((param_2 & 1) != 0) {
      operator_delete__(param_1 + -8);
    }
    return param_1 + -8;
  }
  CConverter::~CConverter(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

/* ---- FUNC 00029510 FUN_180029510 (21 bytes) ---- */

BSTR FUN_180029510(LPCSTR param_1)

{
  int cchWideChar;
  int iVar1;
  BSTR lpWideCharStr;
  
  if (param_1 == (LPCSTR)0x0) {
    return (BSTR)0x0;
  }
  cchWideChar = MultiByteToWideChar(0,0,param_1,-1,(LPWSTR)0x0,0);
  lpWideCharStr = SysAllocStringLen((OLECHAR *)0x0,cchWideChar - 1);
  if (lpWideCharStr != (BSTR)0x0) {
    iVar1 = MultiByteToWideChar(0,0,param_1,-1,lpWideCharStr,cchWideChar);
    if (iVar1 != cchWideChar) {
      SysFreeString(lpWideCharStr);
      return (BSTR)0x0;
    }
  }
  return lpWideCharStr;
}

/* ---- FUNC 00029525 FUN_180029525 (123 bytes) ---- */

BSTR FUN_180029525(undefined8 param_1,undefined8 param_2,LPCSTR param_3)

{
  int cchWideChar;
  int iVar1;
  BSTR lpWideCharStr;
  LPCSTR unaff_RDI;
  
  cchWideChar = MultiByteToWideChar(0,0,param_3,-1,(LPWSTR)0x0,0);
  lpWideCharStr = SysAllocStringLen((OLECHAR *)0x0,cchWideChar - 1);
  if (lpWideCharStr != (BSTR)0x0) {
    iVar1 = MultiByteToWideChar(0,0,unaff_RDI,-1,lpWideCharStr,cchWideChar);
    if (iVar1 != cchWideChar) {
      SysFreeString(lpWideCharStr);
      return (BSTR)0x0;
    }
  }
  return lpWideCharStr;
}

/* ---- FUNC 000295A0 FUN_1800295a0 (19 bytes) ---- */

void FUN_1800295a0(void)

{
  return;
}

/* ---- FUNC 000295B3 FUN_1800295b3 (8 bytes) ---- */

undefined8 FUN_1800295b3(void)

{
  return 0;
}

/* ---- FUNC 000295C0 BlockCount (337 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: int __cdecl CConvertMgr::BlockCount(char const * __ptr64) __ptr64 */

int __thiscall CConvertMgr::BlockCount(CConvertMgr *this,char *param_1)

{
  char cVar1;
  longlong *plVar2;
  longlong *plVar3;
  void *pvVar4;
  int iVar5;
  size_t sVar6;
  undefined1 auStack_78 [32];
  undefined4 local_58;
  longlong *local_50;
  longlong *local_48;
  void *local_40 [4];
  ulonglong uStack_20;
  ulonglong local_18;
  
                    /* 0x295c0  67  ?BlockCount@CConvertMgr@@QEAAHPEBD@Z */
  local_18 = DAT_1800791f8 ^ (ulonglong)auStack_78;
  iVar5 = 0;
  local_40[0] = &DAT_1800537c8;
  local_40[2] = (void *)0x0;
  local_40[3] = (void *)_DAT_180053820;
  uStack_20 = _UNK_180053828;
  local_40[1] = (void *)0x0;
  local_58 = 1;
  sVar6 = 0xffffffffffffffff;
  do {
    sVar6 = sVar6 + 1;
  } while (param_1[sVar6] != '\0');
  FUN_18000ad20((longlong *)((longlong)local_40 + (longlong)DAT_1800537cc),param_1,sVar6);
  FUN_1800287f0((longlong *)(this + 8),(longlong *)&local_50,(longlong *)local_40);
  while (local_50 != local_48) {
    iVar5 = iVar5 + 1;
    plVar2 = (longlong *)local_50[2];
    if (*(char *)((longlong)plVar2 + 0x19) == '\0') {
      cVar1 = *(char *)(*plVar2 + 0x19);
      local_50 = plVar2;
      plVar2 = (longlong *)*plVar2;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*plVar2 + 0x19);
        local_50 = plVar2;
        plVar2 = (longlong *)*plVar2;
      }
    }
    else {
      cVar1 = *(char *)(local_50[1] + 0x19);
      plVar3 = (longlong *)local_50[1];
      plVar2 = local_50;
      while ((local_50 = plVar3, cVar1 == '\0' && (plVar2 == (longlong *)local_50[2]))) {
        cVar1 = *(char *)(local_50[1] + 0x19);
        plVar3 = (longlong *)local_50[1];
        plVar2 = local_50;
      }
    }
  }
  if (0xf < uStack_20) {
    pvVar4 = local_40[1];
    if ((0xfff < uStack_20 + 1) &&
       (pvVar4 = *(void **)((longlong)local_40[1] + -8),
       0x1f < (ulonglong)((longlong)local_40[1] + (-8 - (longlong)pvVar4)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar4);
  }
  return iVar5;
}

/* ---- FUNC 00029720 FUN_180029720 (909 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Type propagation algorithm not settling */

HKEY FUN_180029720(LPCWSTR param_1,undefined1 *param_2,uint param_3)

{
  HKEY pHVar1;
  undefined *puVar2;
  undefined *puVar3;
  uint uVar4;
  longlong lVar5;
  longlong lVar6;
  ulonglong uVar7;
  int iVar8;
  HKEY pHVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined8 *puVar12;
  HKEY pHVar13;
  undefined8 uStack_1f0;
  undefined1 auStack_1e8 [32];
  longlong lStack_1c8;
  int aiStack_1c0 [2];
  undefined8 local_1b8 [2];
  HKEY__ local_1a8;
  DWORD DStack_1a4;
  undefined *local_1a0;
  HKEY local_198;
  undefined4 local_190;
  undefined8 local_188;
  undefined *local_180;
  HKEY local_178;
  undefined4 local_170;
  undefined8 local_168;
  char acStack_159 [273];
  ulonglong local_48;
  
  local_48 = DAT_1800791f8 ^ (ulonglong)&local_1a8;
  pHVar9 = (HKEY)0x0;
  local_180 = &DAT_180053988;
  local_178 = (HKEY)0x0;
  local_170 = 0;
  local_168 = 0;
  local_1a0 = &DAT_180053988;
  local_198 = (HKEY)0x0;
  local_190 = 0;
  local_188 = 0;
  *param_2 = 0;
  puVar10 = auStack_1e8;
  pHVar13 = pHVar9;
  if (param_1 != (LPCWSTR)0x0) {
    lVar5 = -1;
    do {
      lVar6 = lVar5;
      lVar5 = lVar6 + 1;
    } while (param_1[lVar5] != L'\0');
    iVar8 = (int)lVar6 + 2;
    puVar10 = auStack_1e8;
    if (iVar8 < 0x40000000) {
      lVar5 = (longlong)(int)lVar5 * 2;
      uVar7 = lVar5 + 0x11;
      if (uVar7 <= lVar5 + 2U) {
        uVar7 = 0xffffffffffffff0;
      }
      uStack_1f0 = 0x1800297d7;
      lVar5 = -(uVar7 & 0xfffffffffffffff0);
      pHVar1 = (HKEY)((longlong)&local_1a8 + lVar5);
      puVar10 = auStack_1e8 + lVar5;
      if (pHVar1 != (HKEY)0x0) {
        *(undefined1 *)&pHVar1->unused = 0;
        *(undefined8 *)((longlong)local_1b8 + lVar5 + 8) = 0;
        *(undefined8 *)((longlong)local_1b8 + lVar5) = 0;
        *(int *)((longlong)aiStack_1c0 + lVar5) = iVar8 * 2;
        *(HKEY *)((longlong)&lStack_1c8 + lVar5) = pHVar1;
        *(undefined8 *)(auStack_1e8 + lVar5 + -8) = 0x18002980b;
        iVar8 = WideCharToMultiByte(0,0,param_1,-1,*(LPSTR *)((longlong)&lStack_1c8 + lVar5),
                                    *(int *)((longlong)aiStack_1c0 + lVar5),
                                    *(LPCSTR *)((longlong)local_1b8 + lVar5),
                                    *(LPBOOL *)((longlong)local_1b8 + lVar5 + 8));
        puVar10 = auStack_1e8 + lVar5;
        pHVar13 = pHVar1;
        if (iVar8 == 0) {
          puVar10 = auStack_1e8 + lVar5;
          pHVar13 = pHVar9;
        }
      }
    }
  }
  *(undefined8 *)(puVar10 + -8) = 0x18002982f;
  uVar7 = FUN_18002be60(&local_178,(HKEY)0xffffffff80000000,(LPCSTR)pHVar13,0x20019);
  puVar3 = local_180;
  pHVar13 = (HKEY)(uVar7 & 0xffffffff);
  puVar11 = puVar10;
  if ((int)uVar7 != 0) goto LAB_180029a64;
  pHVar13 = *(HKEY *)((longlong)&local_180 + (longlong)*(int *)(local_180 + 4));
  *(undefined8 *)(puVar10 + -8) = 0x18002985c;
  uVar7 = FUN_18002be60(&local_198,pHVar13,"CurVer",0x20019);
  puVar2 = local_1a0;
  if ((int)uVar7 == 0) {
    iVar8 = *(int *)(local_1a0 + 4);
    local_1a8.unused = 0x104;
    *(HKEY__ **)(puVar10 + 0x28) = &local_1a8;
    *(longlong *)(puVar10 + 0x20) = (longlong)acStack_159 + 1;
    pHVar13 = *(HKEY *)((longlong)&local_1a0 + (longlong)iVar8);
    *(undefined8 *)(puVar10 + -8) = 0x18002989e;
    uVar4 = RegQueryValueExA(pHVar13,"",(LPDWORD)0x0,&DStack_1a4,*(LPBYTE *)(puVar10 + 0x20),
                             *(LPDWORD *)(puVar10 + 0x28));
    pHVar13 = (HKEY)(ulonglong)uVar4;
    if (uVar4 == 0) {
      if (DStack_1a4 - 1 < 2) {
        if (local_1a8.unused == 0) {
          acStack_159[1] = '\0';
        }
        else if (acStack_159[(uint)local_1a8.unused] != '\0') {
          pHVar13 = (HKEY)0xd;
          goto LAB_180029961;
        }
        lVar5 = -1;
        do {
          lVar6 = lVar5;
          lVar5 = lVar6 + 1;
        } while (acStack_159[lVar6 + 2] != '\0');
        iVar8 = (int)lVar6 + 2;
        pHVar13 = pHVar9;
        if (iVar8 < 0x40000000) {
          lVar5 = (longlong)(int)(lVar6 + 1) * 2;
          uVar7 = lVar5 + 0x11;
          if (uVar7 <= lVar5 + 2U) {
            uVar7 = 0xffffffffffffff0;
          }
          *(undefined8 *)(puVar10 + -8) = 0x180029919;
          lVar5 = -(uVar7 & 0xfffffffffffffff0);
          pHVar1 = (HKEY)(puVar10 + lVar5 + 0x40);
          puVar11 = puVar10 + lVar5;
          if (pHVar1 != (HKEY)0x0) {
            *(undefined2 *)&pHVar1->unused = 0;
            *(int *)(puVar10 + lVar5 + 0x28) = iVar8;
            *(HKEY *)(puVar10 + lVar5 + 0x20) = pHVar1;
            *(undefined8 *)(puVar10 + lVar5 + -8) = 0x180029946;
            iVar8 = MultiByteToWideChar(0,0,(LPCSTR)((longlong)acStack_159 + 1),-1,
                                        *(LPWSTR *)(puVar10 + lVar5 + 0x20),
                                        *(int *)(puVar10 + lVar5 + 0x28));
            puVar11 = puVar10 + lVar5;
            pHVar13 = pHVar1;
            if (iVar8 == 0) {
              puVar11 = puVar10 + lVar5;
              pHVar13 = pHVar9;
            }
          }
        }
        *(undefined8 *)(puVar11 + -8) = 0x18002995f;
        pHVar13 = FUN_180029720((LPCWSTR)pHVar13,param_2,param_3);
        pHVar13 = (HKEY)((ulonglong)pHVar13 & 0xffffffff);
      }
      else {
        pHVar13 = (HKEY)0xd;
      }
    }
LAB_180029961:
    iVar8 = *(int *)(puVar2 + 4);
    puVar12 = (undefined8 *)((longlong)&local_1a0 + (longlong)iVar8);
    pHVar1 = (HKEY)*puVar12;
    if (pHVar1 != (HKEY)0x0) {
      *(undefined8 *)(puVar11 + -8) = 0x18002997a;
      RegCloseKey(pHVar1);
      *puVar12 = 0;
    }
    *(undefined4 *)((longlong)&local_198 + (longlong)iVar8) = 0;
    if ((int)pHVar13 != 0) goto LAB_180029988;
  }
  else {
LAB_180029988:
    iVar8 = *(int *)(local_1a0 + 4);
    pHVar13 = *(HKEY *)((longlong)&local_180 + (longlong)*(int *)(puVar3 + 4));
    *(undefined8 *)(puVar11 + -8) = 0x1800299b2;
    uVar7 = FUN_18002be60((undefined8 *)((longlong)&local_1a0 + (longlong)iVar8),pHVar13,"CLSID",
                          0x20019);
    puVar2 = local_1a0;
    pHVar13 = (HKEY)(uVar7 & 0xffffffff);
    if ((int)uVar7 == 0) {
      iVar8 = *(int *)(local_1a0 + 4);
      local_1a8.unused = param_3;
      *(HKEY__ **)(puVar11 + 0x28) = &local_1a8;
      *(undefined1 **)(puVar11 + 0x20) = param_2;
      pHVar13 = *(HKEY *)((longlong)&local_1a0 + (longlong)iVar8);
      *(undefined8 *)(puVar11 + -8) = 0x1800299ef;
      uVar4 = RegQueryValueExA(pHVar13,"",(LPDWORD)0x0,&DStack_1a4,*(LPBYTE *)(puVar11 + 0x20),
                               *(LPDWORD *)(puVar11 + 0x28));
      pHVar13 = (HKEY)(ulonglong)uVar4;
      if (uVar4 == 0) {
        if (DStack_1a4 - 1 < 2) {
          pHVar13 = pHVar9;
          if (local_1a8.unused == 0) {
            *param_2 = 0;
          }
          else if (param_2[(ulonglong)(uint)local_1a8.unused - 1] != '\0') {
            pHVar13 = (HKEY)0xd;
          }
        }
        else {
          pHVar13 = (HKEY)0xd;
        }
      }
      iVar8 = *(int *)(puVar2 + 4);
      puVar12 = (undefined8 *)((longlong)&local_1a0 + (longlong)iVar8);
      pHVar9 = (HKEY)*puVar12;
      if (pHVar9 != (HKEY)0x0) {
        *(undefined8 *)(puVar11 + -8) = 0x180029a3b;
        RegCloseKey(pHVar9);
        *puVar12 = 0;
      }
      *(undefined4 *)((longlong)&local_198 + (longlong)iVar8) = 0;
    }
  }
  lVar5 = (longlong)*(int *)(puVar3 + 4);
  puVar12 = (undefined8 *)((longlong)&local_180 + lVar5);
  pHVar9 = (HKEY)*puVar12;
  if (pHVar9 != (HKEY)0x0) {
    *(undefined8 *)(puVar11 + -8) = 0x180029a5a;
    RegCloseKey(pHVar9);
    *puVar12 = 0;
  }
  *(undefined4 *)((longlong)&local_178 + lVar5) = 0;
  pHVar9 = local_198;
LAB_180029a64:
  if (pHVar9 != (HKEY)0x0) {
    *(undefined8 *)(puVar11 + -8) = 0x180029a72;
    RegCloseKey(pHVar9);
  }
  pHVar9 = local_178;
  if (local_178 != (HKEY)0x0) {
    *(undefined8 *)(puVar11 + -8) = 0x180029a82;
    RegCloseKey(pHVar9);
  }
  *(undefined8 *)(puVar11 + -8) = 0x180029a93;
  return pHVar13;
}

/* ---- FUNC 00029AB0 Convert (1867 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: long __cdecl CConverter::Convert(struct IHNodeCol * __ptr64,wchar_t * __ptr64,long
   (__cdecl*)(struct IHNodeCol * __ptr64,wchar_t * __ptr64,wchar_t * __ptr64,wchar_t *
   __ptr64,wchar_t * __ptr64,wchar_t * __ptr64,int))const __ptr64 */

long __thiscall
CConverter::Convert(CConverter *this,IHNodeCol *param_1,wchar_t *param_2,
                   _func_long_IHNodeCol_ptr_wchar_t_ptr_wchar_t_ptr_wchar_t_ptr_wchar_t_ptr_wchar_t_ptr_int
                   *param_3)

{
  undefined4 uVar1;
  code *pcVar2;
  _union_1719 _Var3;
  longlong *plVar4;
  undefined8 uVar5;
  wchar_t *pwVar6;
  _func_long_IHNodeCol_ptr_wchar_t_ptr_wchar_t_ptr_wchar_t_ptr_wchar_t_ptr_wchar_t_ptr_int *p_Var7;
  int iVar8;
  int iVar9;
  HRESULT HVar10;
  longlong lVar11;
  HINSTANCE hModule;
  FARPROC pFVar13;
  INT_PTR IVar14;
  BSTR pOVar15;
  BSTR pOVar16;
  BSTR pOVar17;
  ulonglong uVar18;
  CConverter *pCVar19;
  undefined1 *puVar20;
  LPOLESTR lpszLibName;
  BSTR bstrString;
  BSTR bstrString_00;
  bool bVar21;
  undefined8 uStack_1c0;
  undefined1 auStack_1b8 [32];
  undefined8 uStack_198;
  int aiStack_190 [6];
  _union_1719 local_178;
  longlong *local_170;
  longlong *local_168;
  int local_160;
  int local_15c;
  _union_2707 local_158;
  _union_2707 local_140;
  _union_2707 local_128;
  BSTR local_110;
  BSTR local_108;
  BSTR local_100;
  BSTR local_f8;
  wchar_t *local_f0;
  _func_long_IHNodeCol_ptr_wchar_t_ptr_wchar_t_ptr_wchar_t_ptr_wchar_t_ptr_wchar_t_ptr_int *local_e8
  ;
  undefined1 local_d8 [16];
  undefined8 local_c8;
  undefined8 local_b8;
  _union_1719 _Stack_b0;
  undefined8 local_a8;
  undefined8 local_98;
  _union_1719 _Stack_90;
  undefined8 local_88;
  undefined8 local_78;
  _union_1719 _Stack_70;
  undefined8 local_68;
  undefined1 local_58 [16];
  undefined8 local_48;
  IHNodeCol *local_38;
  ulonglong local_30;
  longlong lVar12;
  
                    /* 0x29ab0  72  ?Convert@CConverter@@QEBAJPEAUIHNodeCol@@PEA_WP6AJ011111H@Z@Z */
  local_30 = DAT_1800791f8 ^ (ulonglong)&local_178;
  local_e8 = param_3;
  local_f0 = param_2;
  lpszLibName = (LPOLESTR)0x0;
  local_170 = (longlong *)0x0;
  iVar9 = -0x7fffbffb;
  puVar20 = auStack_1b8;
  if (*(longlong *)(this + (longlong)*(int *)(*(longlong *)(this + 0xc0) + 4) + 0xd0) == 0) {
LAB_180029c51:
    *(longlong ***)(puVar20 + 0x20) = &local_170;
    *(undefined8 *)(puVar20 + -8) = 0x180029c71;
    CoCreateInstance((IID *)(this + 0xc),(LPUNKNOWN)0x0,0x17,(IID *)&DAT_180056148,
                     *(LPVOID **)(puVar20 + 0x20));
  }
  else {
    pCVar19 = this + (longlong)*(int *)(*(longlong *)(this + 0xc0) + 4) + 0xc0;
    if (0xf < *(ulonglong *)(pCVar19 + 0x18)) {
      pCVar19 = *(CConverter **)pCVar19;
    }
    uStack_1c0 = 0x180029b4a;
    iVar8 = _access((char *)pCVar19,0);
    puVar20 = auStack_1b8;
    if (iVar8 == -1) goto LAB_180029c51;
    puVar20 = auStack_1b8;
    if (pCVar19 != (CConverter *)0x0) {
      lVar11 = -1;
      do {
        lVar12 = lVar11;
        lVar11 = lVar12 + 1;
      } while (pCVar19[lVar11] != (CConverter)0x0);
      iVar8 = (int)lVar12 + 2;
      puVar20 = auStack_1b8;
      if (iVar8 < 0x40000000) {
        lVar11 = (longlong)(int)lVar11 * 2;
        uVar18 = lVar11 + 0x11;
        if (uVar18 <= lVar11 + 2U) {
          uVar18 = 0xffffffffffffff0;
        }
        uStack_1c0 = 0x180029ba0;
        lVar11 = -(uVar18 & 0xfffffffffffffff0);
        lpszLibName = (LPOLESTR)((longlong)&local_178 + lVar11);
        if (lpszLibName == (LPOLESTR)0x0) {
          lpszLibName = (LPOLESTR)0x0;
          puVar20 = auStack_1b8 + lVar11;
        }
        else {
          *lpszLibName = L'\0';
          *(int *)((longlong)aiStack_190 + lVar11) = iVar8;
          *(LPOLESTR *)((longlong)&uStack_198 + lVar11) = lpszLibName;
          *(undefined8 *)(auStack_1b8 + lVar11 + -8) = 0x180029bcc;
          iVar8 = MultiByteToWideChar(0,0,(LPCSTR)pCVar19,-1,
                                      *(LPWSTR *)((longlong)&uStack_198 + lVar11),
                                      *(int *)((longlong)aiStack_190 + lVar11));
          puVar20 = auStack_1b8 + lVar11;
          if (iVar8 == 0) {
            lpszLibName = (LPOLESTR)0x0;
            puVar20 = auStack_1b8 + lVar11;
          }
        }
      }
    }
    *(undefined8 *)(puVar20 + -8) = 0x180029bea;
    hModule = CoLoadLibrary(lpszLibName,1);
    if (hModule == (HINSTANCE)0x0) goto LAB_180029c51;
    *(undefined8 *)(puVar20 + -8) = 0x180029bff;
    pFVar13 = GetProcAddress(hModule,"DllGetClassObject");
    if (pFVar13 == (FARPROC)0x0) goto LAB_180029c51;
    local_178.Lo64 = 0;
    *(undefined8 *)(puVar20 + -8) = 0x180029c1b;
    IVar14 = (*pFVar13)(this + 0xc,&DAT_180057a68,&local_178);
    _Var3 = local_178;
    iVar9 = -0x7fffbffb;
    if (-1 < (int)IVar14) {
      pcVar2 = *(code **)(*(longlong *)local_178 + 0x18);
      *(undefined8 *)(puVar20 + -8) = 0x180029c36;
      iVar9 = (*pcVar2)(_Var3.Lo64,0,&DAT_180056260,&local_170);
    }
    if ((longlong *)local_178.Lo64 != (longlong *)0x0) {
      pcVar2 = *(code **)(*(longlong *)local_178 + 0x10);
      *(undefined8 *)(puVar20 + -8) = 0x180029c48;
      (*pcVar2)();
    }
    if (iVar9 != 0) goto LAB_180029c51;
  }
  plVar4 = local_170;
  bstrString = (BSTR)0x0;
  if (local_170 == (longlong *)0x0) goto LAB_18002a18d;
  local_15c = 0;
  pcVar2 = *(code **)(*local_170 + 0x28);
  *(undefined8 *)(puVar20 + -8) = 0x180029c8b;
  iVar8 = (*pcVar2)(plVar4,&local_15c);
  if ((iVar8 < 0) || (local_15c < *(int *)(this + 8))) goto LAB_18002a18d;
  local_158._0_8_ = 0;
  local_158.decVal.u2.Lo64 = (_union_1719)0x0;
  local_158._16_8_ = 0;
  *(undefined8 *)(puVar20 + -8) = 0x180029cb7;
  VariantInit((VARIANTARG *)&local_158.n2);
  plVar4 = local_170;
  uVar1 = *(undefined4 *)(this + 8);
  pcVar2 = *(code **)(*local_170 + 0x20);
  *(undefined8 *)(puVar20 + -8) = 0x180029cca;
  iVar9 = (*pcVar2)(plVar4,uVar1);
  if (-1 < iVar9) {
    local_178.Lo64 = 0;
    if ((local_158.n2.vt & 0xfff) == 0xd) {
      *(undefined8 *)(puVar20 + -8) = 0x180029d02;
      VariantChangeType((VARIANTARG *)&local_158.n2,(VARIANTARG *)&local_158.n2,0,0xd);
      bVar21 = local_158.n2.vt == 0xd;
LAB_180029d2f:
      uVar5 = local_158.decVal.u2;
      _Var3 = local_178;
      if ((bVar21) && ((_union_1719)local_178.Lo64 != local_158.decVal.u2.Lo64)) {
        if (local_158.decVal.u2.Lo64 == 0) {
LAB_180029d57:
          local_178.Lo64 = 0;
        }
        else {
          pcVar2 = (code *)**(undefined8 **)local_158.decVal.u2;
          *(undefined8 *)(puVar20 + -8) = 0x180029d53;
          iVar8 = (*pcVar2)(uVar5,&DAT_180056120,&local_178);
          if (iVar8 < 0) goto LAB_180029d57;
        }
        if ((longlong *)_Var3.Lo64 != (longlong *)0x0) {
          pcVar2 = *(code **)(*(longlong *)_Var3 + 0x10);
          *(undefined8 *)(puVar20 + -8) = 0x180029d69;
          (*pcVar2)(_Var3.Lo64);
        }
      }
      if ((longlong *)local_178.Lo64 != (longlong *)0x0) {
        local_168 = (longlong *)0x0;
        local_140._0_4_ = local_140._0_4_ & 0xffff0000;
        *(undefined8 *)(puVar20 + -8) = 0x180029d86;
        HVar10 = VariantClear((VARIANTARG *)&local_140.n2);
        if (HVar10 < 0) {
                    /* WARNING: Subroutine does not return */
          *(undefined8 *)(puVar20 + -8) = 0x18002a1e1;
          FUN_180018e40(HVar10);
        }
        local_140.n2.vt = 8;
        *(undefined8 *)(puVar20 + -8) = 0x180029da0;
        local_140.decVal.u2 = (_union_1719)SysAllocString(param_2);
        if ((local_140.decVal.u2.Lo64 == (_union_1719)0x0) && (param_2 != (wchar_t *)0x0)) {
          local_140.n2.vt = 10;
          local_140.decVal.u2 = (_union_1719)0x8007000e;
                    /* WARNING: Subroutine does not return */
          *(undefined **)(puVar20 + -8) = &UNK_18002a1fb;
          FUN_180018e40(-0x7ff8fff2);
        }
        local_128._0_8_ = 0;
        local_128.decVal.u2.Lo64 = (_union_1719)0x0;
        local_128._16_8_ = 0;
        *(undefined8 *)(puVar20 + -8) = 0x180029dc9;
        VariantInit((VARIANTARG *)&local_128.n2);
        local_38 = param_1;
        if (param_1 != (IHNodeCol *)0x0) {
          pcVar2 = *(code **)(*(longlong *)param_1 + 8);
          *(undefined8 *)(puVar20 + -8) = 0x180029de0;
          (*pcVar2)(param_1);
        }
        local_d8._0_8_ = local_128._0_8_;
        local_d8._8_8_ = local_128.decVal.u2;
        local_c8 = local_128._16_8_;
        local_b8 = local_128._0_8_;
        _Stack_b0.Lo64 = (ULONGLONG)local_128.decVal.u2;
        local_a8 = local_128._16_8_;
        local_98 = local_128._0_8_;
        _Stack_90.Lo64 = (ULONGLONG)local_128.decVal.u2;
        local_88 = local_128._16_8_;
        local_78 = local_128._0_8_;
        _Stack_70.Lo64 = (ULONGLONG)local_128.decVal.u2;
        local_68 = local_128._16_8_;
        local_58._4_4_ = local_140.decVal.Hi32;
        local_58._0_4_ = local_140._0_4_;
        local_58._8_8_ = local_140.decVal.u2;
        local_48 = local_140._16_8_;
        lVar11 = *(longlong *)param_1;
        *(longlong ***)(puVar20 + 0x30) = &local_168;
        *(undefined1 **)(puVar20 + 0x28) = local_d8;
        *(undefined8 **)(puVar20 + 0x20) = &local_b8;
        pcVar2 = *(code **)(lVar11 + 0x68);
        *(undefined8 *)(puVar20 + -8) = 0x180029e7e;
        iVar8 = (*pcVar2)(param_1,local_58,&local_78,&local_98);
        if ((-1 < iVar8) && (local_168 != (longlong *)0x0)) {
          pcVar2 = *(code **)(*local_168 + 8);
          *(undefined8 *)(puVar20 + -8) = 0x180029e99;
          (*pcVar2)();
          plVar4 = local_168;
          _Var3 = local_178;
          local_160 = 0;
          pcVar2 = *(code **)(*(longlong *)local_178 + 0x60);
          *(undefined8 *)(puVar20 + -8) = 0x180029eae;
          iVar9 = (*pcVar2)(_Var3.Lo64,plVar4,&local_160);
          pcVar2 = *(code **)(*local_168 + 0x10);
          *(undefined8 *)(puVar20 + -8) = 0x180029ebb;
          (*pcVar2)();
          plVar4 = local_168;
          if ((iVar9 == 0) && (local_160 == 0)) {
            if ((local_168 != (longlong *)0x0) &&
               (local_168 = (longlong *)0x0, plVar4 != (longlong *)0x0)) {
              pcVar2 = *(code **)(*plVar4 + 0x10);
              *(undefined8 *)(puVar20 + -8) = 0x180029eec;
              (*pcVar2)();
            }
            if (param_3 !=
                (_func_long_IHNodeCol_ptr_wchar_t_ptr_wchar_t_ptr_wchar_t_ptr_wchar_t_ptr_wchar_t_ptr_int
                 *)0x0) {
              local_110 = (BSTR)0x0;
              pCVar19 = this + 0x20 + *(int *)(*(longlong *)(this + 0x20) + 4);
              if (0xf < *(ulonglong *)(pCVar19 + 0x18)) {
                pCVar19 = *(CConverter **)pCVar19;
              }
              *(undefined8 *)(puVar20 + -8) = 0x180029f1d;
              pOVar15 = FUN_180029510((LPCSTR)pCVar19);
              bstrString_00 = bstrString;
              if (pOVar15 != (BSTR)0x0) {
                *(undefined8 *)(puVar20 + -8) = 0x180029f2d;
                SysFreeString((BSTR)0x0);
                bstrString_00 = pOVar15;
                local_110 = pOVar15;
              }
              local_108 = (BSTR)0x0;
              pCVar19 = this + 0xe8 + *(int *)(*(longlong *)(this + 0xe8) + 4);
              if (0xf < *(ulonglong *)(pCVar19 + 0x18)) {
                pCVar19 = *(CConverter **)pCVar19;
              }
              *(undefined8 *)(puVar20 + -8) = 0x180029f5b;
              pOVar16 = FUN_180029510((LPCSTR)pCVar19);
              pOVar15 = bstrString;
              if (pOVar16 != (BSTR)0x0) {
                *(undefined8 *)(puVar20 + -8) = 0x180029f6b;
                SysFreeString((BSTR)0x0);
                pOVar15 = pOVar16;
                local_108 = pOVar16;
              }
              local_100 = (BSTR)0x0;
              pCVar19 = this + 0x110 + *(int *)(*(longlong *)(this + 0x110) + 4);
              if (0xf < *(ulonglong *)(pCVar19 + 0x18)) {
                pCVar19 = *(CConverter **)pCVar19;
              }
              *(undefined8 *)(puVar20 + -8) = 0x180029f96;
              pOVar16 = FUN_180029510((LPCSTR)pCVar19);
              if (pOVar16 != (BSTR)0x0) {
                *(undefined8 *)(puVar20 + -8) = 0x180029fa6;
                SysFreeString((BSTR)0x0);
                bstrString = pOVar16;
                local_100 = pOVar16;
              }
              local_f8 = (BSTR)0x0;
              pCVar19 = this + 0x138 + *(int *)(*(longlong *)(this + 0x138) + 4);
              if (0xf < *(ulonglong *)(pCVar19 + 0x18)) {
                pCVar19 = *(CConverter **)pCVar19;
              }
              *(undefined8 *)(puVar20 + -8) = 0x180029fd8;
              pOVar17 = FUN_180029510((LPCSTR)pCVar19);
              pOVar16 = (BSTR)0x0;
              if (pOVar17 != (BSTR)0x0) {
                *(undefined8 *)(puVar20 + -8) = 0x180029fe8;
                SysFreeString((BSTR)0x0);
                local_f8 = pOVar17;
                pOVar16 = pOVar17;
              }
              *(uint *)(puVar20 + 0x30) = (uint)(*(int *)(this + 0x160) != 1);
              *(BSTR *)(puVar20 + 0x28) = pOVar16;
              *(BSTR *)(puVar20 + 0x20) = bstrString;
              p_Var7 = local_e8;
              pwVar6 = local_f0;
              *(undefined8 *)(puVar20 + -8) = 0x18002a023;
              iVar9 = (*p_Var7)(param_1,pwVar6,bstrString_00,pOVar15,*(wchar_t **)(puVar20 + 0x20),
                                *(wchar_t **)(puVar20 + 0x28),*(int *)(puVar20 + 0x30));
              if (-1 < iVar9) {
                local_58._0_8_ = local_128._0_8_;
                local_58._8_8_ = local_128.decVal.u2;
                local_48 = local_128._16_8_;
                local_78 = local_128._0_8_;
                _Stack_70 = local_128.decVal.u2;
                local_68 = local_128._16_8_;
                local_98 = local_128._0_8_;
                _Stack_90 = local_128.decVal.u2;
                local_88 = local_128._16_8_;
                local_b8 = local_128._0_8_;
                _Stack_b0 = local_128.decVal.u2;
                local_a8 = local_128._16_8_;
                local_d8._4_4_ = local_140.decVal.Hi32;
                local_d8._0_4_ = local_140._0_4_;
                local_d8._8_8_ = local_140.decVal.u2;
                local_c8 = local_140._16_8_;
                lVar11 = *(longlong *)param_1;
                *(longlong ***)(puVar20 + 0x30) = &local_168;
                *(undefined1 **)(puVar20 + 0x28) = local_58;
                *(undefined8 **)(puVar20 + 0x20) = &local_78;
                pcVar2 = *(code **)(lVar11 + 0x68);
                *(undefined8 *)(puVar20 + -8) = 0x18002a0cb;
                iVar9 = (*pcVar2)(param_1,local_d8,&local_b8,&local_98);
              }
              *(undefined8 *)(puVar20 + -8) = 0x18002a0d7;
              SysFreeString(pOVar16);
              *(undefined8 *)(puVar20 + -8) = 0x18002a0e1;
              SysFreeString(bstrString);
              *(undefined8 *)(puVar20 + -8) = 0x18002a0eb;
              SysFreeString(pOVar15);
              *(undefined8 *)(puVar20 + -8) = 0x18002a0f5;
              SysFreeString(bstrString_00);
            }
            if (local_168 != (longlong *)0x0) {
              pcVar2 = *(code **)(*(longlong *)local_178 + 0x58);
              *(undefined8 *)(puVar20 + -8) = 0x18002a10a;
              iVar9 = (*pcVar2)();
              if (iVar9 != 0) {
                *(undefined8 *)(puVar20 + -8) = 0x18002a118;
                FUN_18002bf60(iVar9);
              }
            }
          }
          else {
            *(undefined8 *)(puVar20 + -8) = 0x18002a122;
            FUN_18002bf60(iVar9);
          }
        }
        if (param_1 != (IHNodeCol *)0x0) {
          pcVar2 = *(code **)(*(longlong *)param_1 + 0x10);
          *(undefined8 *)(puVar20 + -8) = 0x18002a132;
          (*pcVar2)(param_1);
        }
        *(undefined8 *)(puVar20 + -8) = 0x18002a13d;
        VariantClear((VARIANTARG *)&local_128.n2);
        *(undefined8 *)(puVar20 + -8) = 0x18002a148;
        VariantClear((VARIANTARG *)&local_140.n2);
        if (local_168 != (longlong *)0x0) {
          pcVar2 = *(code **)(*local_168 + 0x10);
          *(undefined8 *)(puVar20 + -8) = 0x18002a158;
          (*pcVar2)();
        }
      }
    }
    else if ((local_158.n2.vt & 0xfff) == 9) {
      *(undefined8 *)(puVar20 + -8) = 0x180029d2a;
      VariantChangeType((VARIANTARG *)&local_158.n2,(VARIANTARG *)&local_158.n2,0,9);
      bVar21 = local_158.n2.vt == 9;
      goto LAB_180029d2f;
    }
    _Var3 = local_178;
    if ((longlong *)local_178.Lo64 != (longlong *)0x0) {
      pcVar2 = *(code **)(*(longlong *)local_178 + 0x10);
      *(undefined8 *)(puVar20 + -8) = 0x18002a16b;
      (*pcVar2)(_Var3.Lo64);
    }
  }
  plVar4 = local_170;
  if (local_170 != (longlong *)0x0) {
    local_170 = (longlong *)0x0;
    pcVar2 = *(code **)(*plVar4 + 0x10);
    *(undefined8 *)(puVar20 + -8) = 0x18002a17e;
    (*pcVar2)();
  }
  *(undefined8 *)(puVar20 + -8) = 0x18002a189;
  VariantClear((VARIANTARG *)&local_158.n2);
LAB_18002a18d:
  if (local_170 != (longlong *)0x0) {
    pcVar2 = *(code **)(*local_170 + 0x10);
    *(undefined8 *)(puVar20 + -8) = 0x18002a1a2;
    (*pcVar2)();
  }
  *(undefined8 *)(puVar20 + -8) = 0x18002a1b4;
  return iVar9;
}

/* ---- FUNC 0002A200 GetConverter (248 bytes) ---- */

/* public: class CConverter const * __ptr64 __cdecl CConvertMgr::GetConverter(int) __ptr64 */

CConverter * __thiscall CConvertMgr::GetConverter(CConvertMgr *this,int param_1)

{
  char cVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  CConverter *pCVar6;
  ulonglong uVar7;
  
                    /* 0x2a200  97  ?GetConverter@CConvertMgr@@QEAAPEBVCConverter@@H@Z */
  puVar2 = *(undefined8 **)(this + 8);
  puVar5 = (undefined8 *)*puVar2;
  if (param_1 < 0) {
    uVar7 = (ulonglong)(uint)-param_1;
    do {
      if (*(char *)((longlong)puVar5 + 0x19) == '\0') {
        puVar3 = (undefined8 *)*puVar5;
        if (*(char *)((longlong)puVar3 + 0x19) == '\0') {
          cVar1 = *(char *)((longlong)puVar3[2] + 0x19);
          puVar4 = (undefined8 *)puVar3[2];
          while (puVar5 = puVar3, cVar1 == '\0') {
            cVar1 = *(char *)((longlong)puVar4[2] + 0x19);
            puVar3 = puVar4;
            puVar4 = (undefined8 *)puVar4[2];
          }
        }
        else {
          cVar1 = *(char *)((longlong)puVar5[1] + 0x19);
          puVar4 = (undefined8 *)puVar5[1];
          puVar3 = puVar5;
          while ((puVar5 = puVar4, cVar1 == '\0' && (puVar3 == (undefined8 *)*puVar5))) {
            cVar1 = *(char *)((longlong)puVar5[1] + 0x19);
            puVar4 = (undefined8 *)puVar5[1];
            puVar3 = puVar5;
          }
          if (*(char *)((longlong)puVar3 + 0x19) != '\0') {
            puVar5 = puVar3;
          }
        }
      }
      else {
        puVar5 = (undefined8 *)puVar5[2];
      }
      uVar7 = uVar7 - 1;
    } while (uVar7 != 0);
    pCVar6 = (CConverter *)(puVar5 + 9);
    if (puVar5 == puVar2) {
      pCVar6 = (CConverter *)0x0;
    }
    return pCVar6;
  }
  for (; 0 < param_1; param_1 = param_1 + -1) {
    puVar3 = (undefined8 *)puVar5[2];
    if (*(char *)((longlong)puVar3 + 0x19) == '\0') {
      cVar1 = *(char *)((longlong)*puVar3 + 0x19);
      puVar5 = puVar3;
      puVar3 = (undefined8 *)*puVar3;
      while (cVar1 == '\0') {
        cVar1 = *(char *)((longlong)*puVar3 + 0x19);
        puVar5 = puVar3;
        puVar3 = (undefined8 *)*puVar3;
      }
    }
    else {
      cVar1 = *(char *)((longlong)puVar5[1] + 0x19);
      puVar4 = (undefined8 *)puVar5[1];
      puVar3 = puVar5;
      while ((puVar5 = puVar4, cVar1 == '\0' && (puVar3 == (undefined8 *)puVar5[2]))) {
        cVar1 = *(char *)((longlong)puVar5[1] + 0x19);
        puVar4 = (undefined8 *)puVar5[1];
        puVar3 = puVar5;
      }
    }
  }
  pCVar6 = (CConverter *)(puVar5 + 9);
  if (puVar5 == puVar2) {
    pCVar6 = (CConverter *)0x0;
  }
  return pCVar6;
}

/* ---- FUNC 0002A300 GetLowerBound (481 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: int __cdecl CConvertMgr::GetLowerBound(char const * __ptr64) __ptr64 */

int __thiscall CConvertMgr::GetLowerBound(CConvertMgr *this,char *param_1)

{
  char cVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  int iVar5;
  undefined8 *puVar6;
  longlong lVar7;
  undefined8 *_Buf1;
  void *pvVar8;
  undefined8 *puVar9;
  int iVar10;
  size_t sVar11;
  undefined8 *puVar12;
  ulonglong _Size;
  undefined8 *puVar13;
  undefined1 auStack_88 [32];
  undefined4 local_68;
  void *local_60 [2];
  ulonglong auStack_50 [5];
  
                    /* 0x2a300  105  ?GetLowerBound@CConvertMgr@@QEAAHPEBD@Z */
  auStack_50[3] = DAT_1800791f8 ^ (ulonglong)auStack_88;
  iVar10 = 0;
  local_60[0] = &DAT_1800537c8;
  auStack_50[0] = 0;
  auStack_50[1] = _DAT_180053820;
  auStack_50[2] = _UNK_180053828;
  local_60[1] = (void *)0x0;
  local_68 = 1;
  sVar11 = 0xffffffffffffffff;
  do {
    sVar11 = sVar11 + 1;
  } while (param_1[sVar11] != '\0');
  FUN_18000ad20((longlong *)((longlong)local_60 + (longlong)DAT_1800537cc),param_1,sVar11);
  puVar13 = *(undefined8 **)(this + 8);
  if (*(char *)((longlong)puVar13[1] + 0x19) == '\0') {
    lVar7 = (longlong)*(int *)((longlong)local_60[0] + 4);
    uVar2 = *(ulonglong *)((longlong)auStack_50 + lVar7 + 8);
    uVar3 = *(ulonglong *)((longlong)auStack_50 + lVar7);
    puVar9 = (undefined8 *)puVar13[1];
    do {
      puVar12 = (undefined8 *)((longlong)*(int *)(puVar9[4] + 4) + (longlong)(puVar9 + 4));
      puVar6 = (undefined8 *)((longlong)local_60 + lVar7);
      if (0xf < uVar2) {
        puVar6 = *(undefined8 **)((longlong)local_60 + lVar7);
      }
      _Buf1 = puVar12;
      if (0xf < (ulonglong)puVar12[3]) {
        _Buf1 = (undefined8 *)*puVar12;
      }
      uVar4 = puVar12[2];
      _Size = uVar4;
      if (uVar3 < uVar4) {
        _Size = uVar3;
      }
      iVar5 = memcmp(_Buf1,puVar6,_Size);
      if (iVar5 == 0) {
        if (uVar3 <= uVar4) goto LAB_18002a3f0;
LAB_18002a43c:
        puVar6 = (undefined8 *)puVar9[2];
      }
      else {
        if (iVar5 < 0) goto LAB_18002a43c;
LAB_18002a3f0:
        puVar6 = (undefined8 *)*puVar9;
        puVar13 = puVar9;
      }
      puVar9 = puVar6;
    } while (*(char *)((longlong)puVar6 + 0x19) == '\0');
  }
  if (0xf < auStack_50[2]) {
    pvVar8 = local_60[1];
    if ((0xfff < auStack_50[2] + 1) &&
       (pvVar8 = *(void **)((longlong)local_60[1] + -8),
       0x1f < (ulonglong)((longlong)local_60[1] + (-8 - (longlong)pvVar8)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar8);
  }
  puVar9 = (undefined8 *)**(undefined8 **)(this + 8);
  do {
    do {
      while( true ) {
        puVar6 = puVar9;
        if (puVar6 == puVar13) {
          return iVar10;
        }
        iVar10 = iVar10 + 1;
        puVar9 = (undefined8 *)puVar6[2];
        if (*(char *)((longlong)puVar9 + 0x19) != '\0') break;
        cVar1 = *(char *)((longlong)*puVar9 + 0x19);
        puVar6 = (undefined8 *)*puVar9;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((longlong)*puVar6 + 0x19);
          puVar9 = puVar6;
          puVar6 = (undefined8 *)*puVar6;
        }
      }
      puVar9 = (undefined8 *)puVar6[1];
    } while (*(char *)((longlong)puVar9 + 0x19) != '\0');
    do {
      if (puVar6 != (undefined8 *)puVar9[2]) break;
      puVar12 = (undefined8 *)puVar9[1];
      puVar6 = puVar9;
      puVar9 = puVar12;
    } while (*(char *)((longlong)puVar12 + 0x19) == '\0');
  } while( true );
}

/* ---- FUNC 0002A4F0 GetUpperBound (481 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: int __cdecl CConvertMgr::GetUpperBound(char const * __ptr64) __ptr64 */

int __thiscall CConvertMgr::GetUpperBound(CConvertMgr *this,char *param_1)

{
  char cVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  int iVar5;
  longlong lVar6;
  undefined8 *_Buf1;
  void *pvVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  int iVar10;
  undefined8 *puVar11;
  size_t sVar12;
  undefined8 *puVar13;
  ulonglong _Size;
  undefined1 auStack_88 [32];
  undefined4 local_68;
  void *local_60 [2];
  ulonglong auStack_50 [5];
  
                    /* 0x2a4f0  112  ?GetUpperBound@CConvertMgr@@QEAAHPEBD@Z */
  auStack_50[3] = DAT_1800791f8 ^ (ulonglong)auStack_88;
  iVar10 = 0;
  local_60[0] = &DAT_1800537c8;
  auStack_50[0] = 0;
  auStack_50[1] = _DAT_180053820;
  auStack_50[2] = _UNK_180053828;
  local_60[1] = (void *)0x0;
  local_68 = 1;
  sVar12 = 0xffffffffffffffff;
  do {
    sVar12 = sVar12 + 1;
  } while (param_1[sVar12] != '\0');
  FUN_18000ad20((longlong *)((longlong)local_60 + (longlong)DAT_1800537cc),param_1,sVar12);
  puVar11 = DAT_18007b6c8;
  if (*(char *)((longlong)DAT_18007b6c8[1] + 0x19) == '\0') {
    lVar6 = (longlong)*(int *)((longlong)local_60[0] + 4);
    uVar2 = *(ulonglong *)((longlong)auStack_50 + lVar6 + 8);
    uVar3 = *(ulonglong *)((longlong)auStack_50 + lVar6);
    puVar9 = (undefined8 *)DAT_18007b6c8[1];
    do {
      puVar13 = (undefined8 *)((longlong)*(int *)(puVar9[4] + 4) + (longlong)(puVar9 + 4));
      puVar8 = puVar13;
      if (0xf < (ulonglong)puVar13[3]) {
        puVar8 = (undefined8 *)*puVar13;
      }
      _Buf1 = (undefined8 *)((longlong)local_60 + lVar6);
      if (0xf < uVar2) {
        _Buf1 = *(undefined8 **)((longlong)local_60 + lVar6);
      }
      uVar4 = puVar13[2];
      _Size = uVar3;
      if (uVar4 < uVar3) {
        _Size = uVar4;
      }
      iVar5 = memcmp(_Buf1,puVar8,_Size);
      if (iVar5 == 0) {
        if (uVar3 < uVar4) goto LAB_18002a62c;
LAB_18002a5e2:
        puVar8 = (undefined8 *)puVar9[2];
      }
      else {
        if (-1 < iVar5) goto LAB_18002a5e2;
LAB_18002a62c:
        puVar8 = (undefined8 *)*puVar9;
        puVar11 = puVar9;
      }
      puVar9 = puVar8;
    } while (*(char *)((longlong)puVar8 + 0x19) == '\0');
  }
  if (0xf < auStack_50[2]) {
    pvVar7 = local_60[1];
    if ((0xfff < auStack_50[2] + 1) &&
       (pvVar7 = *(void **)((longlong)local_60[1] + -8),
       0x1f < (ulonglong)((longlong)local_60[1] + (-8 - (longlong)pvVar7)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar7);
  }
  puVar9 = (undefined8 *)**(undefined8 **)(this + 8);
  while (puVar9 != puVar11) {
    iVar10 = iVar10 + 1;
    puVar8 = (undefined8 *)puVar9[2];
    if (*(char *)((longlong)puVar8 + 0x19) == '\0') {
      cVar1 = *(char *)((longlong)*puVar8 + 0x19);
      puVar9 = puVar8;
      puVar8 = (undefined8 *)*puVar8;
      while (cVar1 == '\0') {
        cVar1 = *(char *)((longlong)*puVar8 + 0x19);
        puVar9 = puVar8;
        puVar8 = (undefined8 *)*puVar8;
      }
    }
    else {
      cVar1 = *(char *)((longlong)puVar9[1] + 0x19);
      puVar13 = (undefined8 *)puVar9[1];
      puVar8 = puVar9;
      while ((puVar9 = puVar13, cVar1 == '\0' && (puVar8 == (undefined8 *)puVar9[2]))) {
        cVar1 = *(char *)((longlong)puVar9[1] + 0x19);
        puVar13 = (undefined8 *)puVar9[1];
        puVar8 = puVar9;
      }
    }
  }
  return iVar10;
}

/* ---- FUNC 0002A6E0 Initialize (6011 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __cdecl CConvertMgr::Initialize(void) __ptr64 */

void __thiscall CConvertMgr::Initialize(CConvertMgr *this)

{
  char *pcVar1;
  uchar uVar2;
  code *pcVar3;
  BSTR pOVar4;
  LPCWSTR pWVar5;
  undefined8 uVar6;
  LSTATUS LVar7;
  RPC_STATUS RVar8;
  int iVar9;
  UINT UVar10;
  void *pvVar11;
  ulonglong uVar12;
  HKEY pHVar13;
  HINSTANCE hModule;
  FARPROC pFVar14;
  INT_PTR IVar15;
  longlong lVar16;
  longlong lVar17;
  undefined8 *puVar18;
  ulonglong uVar19;
  CConvertMgr *pCVar20;
  int iVar21;
  LPCSTR lpSubKey;
  longlong *plVar22;
  longlong *plVar23;
  HKEY pHVar24;
  undefined1 *puVar25;
  undefined1 *puVar26;
  HKEY pHVar27;
  HKEY pHVar28;
  size_t sVar29;
  size_t sVar30;
  uint uVar31;
  undefined1 auStackY_918 [32];
  uint local_8d8;
  short asStack_8d4 [2];
  uint local_8d0;
  uint local_8cc;
  longlong *local_8c8;
  longlong *local_8c0;
  HKEY local_8b8;
  BSTR local_8b0;
  LPCWSTR local_8a8;
  int local_8a0;
  _union_2707 local_898;
  DWORD local_880 [2];
  longlong *local_878;
  LPCWSTR local_870;
  LPCWSTR local_868;
  LPCWSTR local_860;
  LPCWSTR local_858;
  HKEY local_850;
  CConvertMgr *local_848;
  HKEY local_840;
  HKEY local_838 [2];
  undefined4 local_828;
  undefined8 local_820;
  CConvertMgr *local_818;
  undefined *local_810;
  HKEY local_808;
  undefined4 local_800;
  undefined8 local_7f8;
  undefined **local_7f0;
  undefined8 local_7e8 [2];
  void *local_7d8 [2];
  ulonglong auStack_7c8 [3];
  void *local_7b0 [2];
  size_t sStack_7a0;
  ulonglong local_798 [2];
  UUID local_788;
  CConverter local_778 [8];
  int local_770;
  UUID local_76c;
  longlong local_758 [5];
  longlong local_730 [5];
  longlong local_708 [5];
  longlong local_6e0 [5];
  longlong local_6b8 [5];
  longlong local_690 [5];
  longlong local_668 [5];
  longlong local_640 [5];
  uint local_618;
  undefined *local_608 [5];
  CConverter local_5e0 [359];
  char acStack_479 [273];
  char local_368 [272];
  char local_258 [271];
  uchar auStack_149 [273];
  ulonglong local_38;
  
                    /* 0x2a6e0  120  ?Initialize@CConvertMgr@@QEAAXXZ */
  puVar25 = auStackY_918;
  local_38 = DAT_1800791f8 ^ (ulonglong)&local_8d8;
  pHVar27 = (HKEY)0x0;
  local_7d8[0] = &DAT_1800537c8;
  auStack_7c8[0] = 0;
  auStack_7c8[1] = _DAT_180053820;
  auStack_7c8[2] = _UNK_180053828;
  local_7d8[1] = (void *)0x0;
  uVar31 = 4;
  local_8d8 = 4;
  local_848 = this;
  local_818 = this;
  FUN_18000ad20((longlong *)((longlong)local_7d8 + (longlong)DAT_1800537cc),"Software\\AspenTech\\",
                0x13);
  pvVar11 = (void *)FUN_180024130();
  FUN_180029360((longlong *)((longlong)local_7d8 + (longlong)*(int *)((longlong)local_7d8[0] + 4)),
                pvVar11);
  lVar16 = (longlong)*(int *)((longlong)local_7d8[0] + 4);
  puVar18 = (undefined8 *)((longlong)local_7d8 + lVar16);
  uVar19 = *(ulonglong *)((longlong)auStack_7c8 + lVar16);
  uVar12 = *(ulonglong *)((longlong)auStack_7c8 + lVar16 + 8);
  if (uVar12 == uVar19) {
    FUN_180017f00(puVar18,1,0,&DAT_180053ef4,1);
  }
  else {
    *(ulonglong *)((longlong)auStack_7c8 + lVar16) = uVar19 + 1;
    if (0xf < uVar12) {
      puVar18 = (undefined8 *)*puVar18;
    }
    *(undefined2 *)((longlong)puVar18 + uVar19) = 0x5c;
  }
  pvVar11 = (void *)FUN_180024170();
  FUN_180029360((longlong *)((longlong)local_7d8 + (longlong)*(int *)((longlong)local_7d8[0] + 4)),
                pvVar11);
  lVar16 = (longlong)*(int *)((longlong)local_7d8[0] + 4);
  puVar18 = (undefined8 *)((longlong)local_7d8 + lVar16);
  uVar19 = *(ulonglong *)((longlong)auStack_7c8 + lVar16);
  uVar12 = *(ulonglong *)((longlong)auStack_7c8 + lVar16 + 8);
  if (uVar12 == uVar19) {
    FUN_180017f00(puVar18,1,0,&DAT_180053ef4,1);
  }
  else {
    *(ulonglong *)((longlong)auStack_7c8 + lVar16) = uVar19 + 1;
    if (0xf < uVar12) {
      puVar18 = (undefined8 *)*puVar18;
    }
    *(undefined2 *)((longlong)puVar18 + uVar19) = 0x5c;
  }
  lVar17 = (longlong)*(int *)((longlong)local_7d8[0] + 4);
  puVar18 = (undefined8 *)((longlong)local_7d8 + lVar17);
  lVar16 = *(longlong *)((longlong)auStack_7c8 + lVar17);
  uVar19 = *(ulonglong *)((longlong)auStack_7c8 + lVar17 + 8);
  pHVar28 = pHVar27;
  if (uVar19 - lVar16 < 10) {
    FUN_180017f00(puVar18,10,0,"Converters",10);
  }
  else {
    *(longlong *)((longlong)auStack_7c8 + lVar17) = lVar16 + 10;
    if (0xf < uVar19) {
      puVar18 = (undefined8 *)*puVar18;
    }
    memmove((void *)((longlong)puVar18 + lVar16),"Converters",10);
    *(undefined1 *)((longlong)puVar18 + lVar16 + 10) = 0;
    puVar25 = auStackY_918;
  }
  do {
    iVar21 = (int)pHVar28;
    local_8a0 = iVar21;
    if (1 < iVar21) {
      if (0xf < auStack_7c8[2]) {
        pvVar11 = local_7d8[1];
        if ((0xfff < auStack_7c8[2] + 1) &&
           (pvVar11 = *(void **)((longlong)local_7d8[1] + -8),
           0x1f < (ulonglong)((longlong)local_7d8[1] + (-8 - (longlong)pvVar11)))) {
                    /* WARNING: Subroutine does not return */
          *(undefined **)(puVar25 + -8) = &UNK_18002be19;
          _invalid_parameter_noinfo_noreturn();
        }
        *(undefined8 *)(puVar25 + -8) = 0x18002be1f;
        operator_delete(pvVar11);
      }
      *(undefined8 *)(puVar25 + -8) = 0x18002be2e;
      return;
    }
    pHVar28 = (HKEY)&DAT_180053988;
    local_838[0] = (HKEY)&DAT_180053988;
    local_850 = (HKEY)0x0;
    local_820 = 0;
    uVar31 = uVar31 | 2;
    lpSubKey = (LPCSTR)((longlong)local_7d8 + (longlong)*(int *)((longlong)local_7d8[0] + 4));
    if (0xf < *(ulonglong *)
               ((longlong)auStack_7c8 + (longlong)*(int *)((longlong)local_7d8[0] + 4) + 8)) {
      lpSubKey = *(LPCSTR *)lpSubKey;
    }
    local_8b8 = (HKEY)0x0;
    *(HKEY **)(puVar25 + 0x20) = &local_8b8;
    *(undefined8 *)(puVar25 + -8) = 0x18002a986;
    LVar7 = RegOpenKeyExA((HKEY)(&DAT_ffffffff80000002 + -(ulonglong)(iVar21 != 0)),lpSubKey,0,
                          0x20019,*(PHKEY *)(puVar25 + 0x20));
    if (LVar7 == 0) {
      local_850 = local_8b8;
      local_838[1] = local_8b8;
      local_828 = 0;
      pHVar13 = pHVar27;
      while( true ) {
        local_8cc = (DWORD)pHVar13 + 1;
        pHVar24 = *(HKEY *)((longlong)local_838 + (longlong)pHVar28[1].unused);
        *(undefined8 *)(puVar25 + -8) = 0x18002a9d6;
        LVar7 = RegEnumKeyA(pHVar24,(DWORD)pHVar13,local_368,0x104);
        iVar21 = local_8a0;
        if (LVar7 != 0) break;
        local_810 = &DAT_180053988;
        local_7f8 = 0;
        uVar31 = uVar31 | 1;
        local_8d8 = uVar31;
        iVar21 = pHVar28[1].unused;
        local_8b8 = (HKEY)0x0;
        *(HKEY **)(puVar25 + 0x20) = &local_8b8;
        pHVar13 = *(HKEY *)((longlong)local_838 + (longlong)iVar21);
        *(undefined8 *)(puVar25 + -8) = 0x18002aa2d;
        LVar7 = RegOpenKeyExA(pHVar13,local_368,0,0x20019,*(PHKEY *)(puVar25 + 0x20));
        pHVar24 = pHVar27;
        if (LVar7 == 0) {
          local_840 = local_8b8;
          local_808 = local_8b8;
          local_800 = 0;
          pHVar13 = pHVar27;
          if (local_368[0] == '{') {
            do {
              pcVar1 = local_368 + (longlong)pHVar13;
              local_258[(longlong)pHVar13] = *pcVar1;
              pHVar13 = (HKEY)((longlong)&pHVar13->unused + 1);
            } while (*pcVar1 != '\0');
          }
          else {
            lVar16 = -1;
            do {
              lVar17 = lVar16;
              lVar16 = lVar17 + 1;
            } while (local_368[lVar17 + 1] != '\0');
            iVar21 = (int)lVar17 + 2;
            puVar26 = puVar25;
            if (iVar21 < 0x40000000) {
              lVar16 = (longlong)(int)(lVar17 + 1) * 2;
              uVar19 = lVar16 + 0x11;
              if (uVar19 <= lVar16 + 2U) {
                uVar19 = 0xffffffffffffff0;
              }
              *(undefined8 *)(puVar25 + -8) = 0x18002aa9a;
              lVar16 = -(uVar19 & 0xfffffffffffffff0);
              pHVar24 = (HKEY)(puVar25 + lVar16 + 0x40);
              puVar26 = puVar25 + lVar16;
              if (pHVar24 != (HKEY)0x0) {
                *(WCHAR *)&pHVar24->unused = L'\0';
                *(int *)(puVar25 + lVar16 + 0x28) = iVar21;
                *(HKEY *)(puVar25 + lVar16 + 0x20) = pHVar24;
                *(undefined8 *)(puVar25 + lVar16 + -8) = 0x18002aac7;
                iVar21 = MultiByteToWideChar(0,0,local_368,-1,*(LPWSTR *)(puVar25 + lVar16 + 0x20),
                                             *(int *)(puVar25 + lVar16 + 0x28));
                pHVar13 = pHVar24;
                puVar26 = puVar25 + lVar16;
                if (iVar21 == 0) {
                  pHVar13 = pHVar27;
                  puVar26 = puVar25 + lVar16;
                }
              }
            }
            *(undefined8 *)(puVar26 + -8) = 0x18002aae7;
            FUN_180029720((LPCWSTR)pHVar13,local_258,0x104);
            puVar25 = puVar26;
          }
          pHVar24 = local_840;
          pHVar13 = pHVar27;
          if (local_258[0] == '{') {
            do {
              uVar2 = (local_258 + 1)[(longlong)pHVar13];
              (auStack_149 + 1)[(longlong)pHVar13] = uVar2;
              pHVar13 = (HKEY)((longlong)&pHVar13->unused + 1);
            } while (uVar2 != '\0');
            uVar19 = 0xffffffffffffffff;
            do {
              uVar12 = uVar19;
              uVar19 = uVar12 + 1;
            } while (auStack_149[uVar12 + 2] != '\0');
            if (0x103 < uVar12) {
              *(undefined8 *)(puVar25 + -8) = 0x18002be59;
              FUN_180046e94();
              pcVar3 = (code *)swi(3);
              (*pcVar3)();
              return;
            }
            auStack_149[uVar12 + 1] = '\0';
            *(undefined8 *)(puVar25 + -8) = 0x18002ab85;
            RVar8 = UuidFromStringA(auStack_149 + 1,&local_788);
            if (RVar8 == 0) {
              local_8c0 = (longlong *)0x0;
              iVar21 = -0x7fffbffb;
              local_8d0 = 0x104;
              *(uint **)(puVar25 + 0x28) = &local_8d0;
              *(char **)(puVar25 + 0x20) = acStack_479 + 1;
              *(undefined8 *)(puVar25 + -8) = 0x18002abe2;
              LVar7 = RegQueryValueExA(pHVar24,"",(LPDWORD)0x0,local_880,*(LPBYTE *)(puVar25 + 0x20)
                                       ,*(LPDWORD *)(puVar25 + 0x28));
              if ((LVar7 == 0) && (local_880[0] - 1 < 2)) {
                if (local_8d0 == 0) {
                  acStack_479[1] = 0;
                }
                else if (acStack_479[local_8d0] != '\0') goto LAB_18002ad1e;
                if (local_8d0 == 0) goto LAB_18002ad1e;
                *(undefined8 *)(puVar25 + -8) = 0x18002ac2c;
                iVar9 = _access(acStack_479 + 1,0);
                if (iVar9 == -1) goto LAB_18002ad1e;
                lVar16 = -1;
                do {
                  lVar17 = lVar16;
                  lVar16 = lVar17 + 1;
                } while (acStack_479[lVar17 + 2] != '\0');
                iVar9 = (int)lVar17 + 2;
                pHVar28 = pHVar27;
                puVar26 = puVar25;
                if (iVar9 < 0x40000000) {
                  lVar16 = (longlong)(int)(lVar17 + 1) * 2;
                  uVar19 = lVar16 + 0x11;
                  if (uVar19 <= lVar16 + 2U) {
                    uVar19 = 0xffffffffffffff0;
                  }
                  *(undefined8 *)(puVar25 + -8) = 0x18002ac76;
                  lVar16 = -(uVar19 & 0xfffffffffffffff0);
                  pHVar13 = (HKEY)(puVar25 + lVar16 + 0x40);
                  puVar26 = puVar25 + lVar16;
                  if (pHVar13 != (HKEY)0x0) {
                    *(undefined2 *)&pHVar13->unused = 0;
                    *(int *)(puVar25 + lVar16 + 0x28) = iVar9;
                    *(HKEY *)(puVar25 + lVar16 + 0x20) = pHVar13;
                    *(undefined8 *)(puVar25 + lVar16 + -8) = 0x18002aca3;
                    iVar9 = MultiByteToWideChar(0,0,acStack_479 + 1,-1,
                                                *(LPWSTR *)(puVar25 + lVar16 + 0x20),
                                                *(int *)(puVar25 + lVar16 + 0x28));
                    pHVar28 = pHVar13;
                    puVar26 = puVar25 + lVar16;
                    if (iVar9 == 0) {
                      pHVar28 = pHVar27;
                      puVar26 = puVar25 + lVar16;
                    }
                  }
                }
                puVar25 = puVar26;
                *(undefined8 *)(puVar25 + -8) = 0x18002acbc;
                hModule = CoLoadLibrary((LPOLESTR)pHVar28,1);
                if (hModule == (HINSTANCE)0x0) goto LAB_18002ad1e;
                *(undefined8 *)(puVar25 + -8) = 0x18002acd1;
                pFVar14 = GetProcAddress(hModule,"DllGetClassObject");
                if (pFVar14 == (FARPROC)0x0) goto LAB_18002ad1e;
                local_8b0 = (BSTR)0x0;
                *(undefined8 *)(puVar25 + -8) = 0x18002acee;
                IVar15 = (*pFVar14)(&local_788,&DAT_180057a68,&local_8b0);
                pOVar4 = local_8b0;
                if (-1 < (int)IVar15) {
                  pcVar3 = *(code **)(*(longlong *)local_8b0 + 0x18);
                  *(undefined8 *)(puVar25 + -8) = 0x18002ad09;
                  iVar21 = (*pcVar3)(pOVar4,0,&DAT_180056260,&local_8c0);
                }
                if (local_8b0 != (BSTR)0x0) {
                  pcVar3 = *(code **)(*(longlong *)local_8b0 + 0x10);
                  *(undefined8 *)(puVar25 + -8) = 0x18002ad1a;
                  (*pcVar3)();
                }
                if (iVar21 != 0) goto LAB_18002ad1e;
              }
              else {
LAB_18002ad1e:
                *(longlong ***)(puVar25 + 0x20) = &local_8c0;
                *(undefined8 *)(puVar25 + -8) = 0x18002ad41;
                CoCreateInstance(&local_788,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_180056148,
                                 *(LPVOID **)(puVar25 + 0x20));
              }
              plVar23 = local_8c0;
              if (local_8c0 != (longlong *)0x0) {
                local_8d0 = 0;
                pcVar3 = *(code **)(*local_8c0 + 0x28);
                *(undefined8 *)(puVar25 + -8) = 0x18002ad5b;
                iVar21 = (*pcVar3)(plVar23,&local_8d0);
                if ((-1 < iVar21) && (0 < (int)local_8d0)) {
                  for (iVar21 = 1; iVar21 <= (int)local_8d0; iVar21 = iVar21 + 1) {
                    local_898._0_8_ = 0;
                    local_898.decVal.u2.Lo64 = (_union_1719)0x0;
                    local_898._16_8_ = 0;
                    *(undefined8 *)(puVar25 + -8) = 0x18002ad92;
                    VariantInit((VARIANTARG *)&local_898.n2);
                    plVar23 = local_8c0;
                    pcVar3 = *(code **)(*local_8c0 + 0x20);
                    *(undefined8 *)(puVar25 + -8) = 0x18002ada3;
                    iVar9 = (*pcVar3)(plVar23,iVar21);
                    if (-1 < iVar9) {
                      local_8c8 = (longlong *)0x0;
                      if ((local_898.n2.vt & 0xfff) == 9) {
                        *(undefined8 *)(puVar25 + -8) = 0x18002addb;
                        VariantChangeType((VARIANTARG *)&local_898.n2,(VARIANTARG *)&local_898.n2,0,
                                          9);
                        uVar6 = local_898.decVal.u2;
                        if (local_898.n2.vt == 9) {
                          pcVar3 = (code *)**(undefined8 **)local_898.decVal.u2;
                          *(undefined8 *)(puVar25 + -8) = 0x18002adf6;
                          (*pcVar3)(uVar6,&DAT_180056120,&local_8c8);
                        }
LAB_18002ae34:
                        plVar23 = local_8c8;
                        if (local_8c8 != (longlong *)0x0) {
                          local_8a8 = (LPCWSTR)0x0;
                          local_8b0 = (BSTR)0x0;
                          local_8b8 = (HKEY)0x0;
                          local_858 = (LPCWSTR)0x0;
                          local_860 = (LPCWSTR)0x0;
                          local_868 = (LPCWSTR)0x0;
                          local_870 = (LPCWSTR)0x0;
                          pcVar3 = *(code **)(*local_8c8 + 0x18);
                          *(undefined8 *)(puVar25 + -8) = 0x18002ae6a;
                          (*pcVar3)(plVar23,&local_8a8);
                          plVar23 = local_8c8;
                          pcVar3 = *(code **)(*local_8c8 + 0x20);
                          *(undefined8 *)(puVar25 + -8) = 0x18002ae78;
                          (*pcVar3)(plVar23,&local_8b0);
                          plVar23 = local_8c8;
                          pcVar3 = *(code **)(*local_8c8 + 0x28);
                          *(undefined8 *)(puVar25 + -8) = 0x18002ae89;
                          (*pcVar3)(plVar23,&local_858);
                          plVar23 = local_8c8;
                          pcVar3 = *(code **)(*local_8c8 + 0x30);
                          *(undefined8 *)(puVar25 + -8) = 0x18002ae97;
                          (*pcVar3)(plVar23,&local_8b8);
                          plVar23 = local_8c8;
                          pcVar3 = *(code **)(*local_8c8 + 0x38);
                          *(undefined8 *)(puVar25 + -8) = 0x18002aea5;
                          (*pcVar3)(plVar23,&local_860);
                          plVar23 = local_8c8;
                          pcVar3 = *(code **)(*local_8c8 + 0x40);
                          *(undefined8 *)(puVar25 + -8) = 0x18002aeb3;
                          (*pcVar3)(plVar23,&local_868);
                          plVar23 = local_8c8;
                          pcVar3 = *(code **)(*local_8c8 + 0x48);
                          *(undefined8 *)(puVar25 + -8) = 0x18002aec1;
                          (*pcVar3)(plVar23,&local_870);
                          pWVar5 = local_8a8;
                          asStack_8d4[0] = -1;
                          puVar26 = puVar25;
                          if (local_8a8 != (LPCWSTR)0x0) {
                            lVar16 = -1;
                            do {
                              lVar17 = lVar16;
                              lVar16 = lVar17 + 1;
                            } while (local_8a8[lVar16] != L'\0');
                            iVar9 = (int)lVar17 + 2;
                            if (iVar9 < 0x40000000) {
                              lVar16 = (longlong)(int)lVar16 * 2;
                              uVar19 = lVar16 + 0x11;
                              if (uVar19 <= lVar16 + 2U) {
                                uVar19 = 0xffffffffffffff0;
                              }
                              *(undefined8 *)(puVar25 + -8) = 0x18002af1c;
                              lVar16 = -(uVar19 & 0xfffffffffffffff0);
                              pcVar1 = puVar25 + lVar16 + 0x40;
                              puVar26 = puVar25 + lVar16;
                              if (pcVar1 != (char *)0x0) {
                                *pcVar1 = '\0';
                                *(undefined8 *)(puVar25 + lVar16 + 0x38) = 0;
                                *(undefined8 *)(puVar25 + lVar16 + 0x30) = 0;
                                *(int *)(puVar25 + lVar16 + 0x28) = iVar9 * 2;
                                *(char **)(puVar25 + lVar16 + 0x20) = pcVar1;
                                *(undefined8 *)(puVar25 + lVar16 + -8) = 0x18002af4f;
                                iVar9 = WideCharToMultiByte(0,0,pWVar5,-1,
                                                            *(LPSTR *)(puVar25 + lVar16 + 0x20),
                                                            *(int *)(puVar25 + lVar16 + 0x28),
                                                            *(LPCSTR *)(puVar25 + lVar16 + 0x30),
                                                            *(LPBOOL *)(puVar25 + lVar16 + 0x38));
                                puVar26 = puVar25 + lVar16;
                                if (iVar9 != 0) {
                                  lVar17 = -1;
                                  do {
                                    lVar17 = lVar17 + 1;
                                  } while (pcVar1[lVar17] != '\0');
                                  puVar26 = puVar25 + lVar16;
                                  if (lVar17 != 0) {
                                    *(undefined8 *)(puVar25 + lVar16 + -8) = 0x18002af74;
                                    iVar9 = _stricmp(pcVar1,"RateFrac");
                                    puVar26 = puVar25 + lVar16;
                                    if (iVar9 == 0) {
                                      asStack_8d4[0] = 0;
                                      puVar26 = puVar25 + lVar16;
                                    }
                                  }
                                }
                              }
                            }
                          }
                          plVar23 = local_8c8;
                          local_878 = (longlong *)0x0;
                          pcVar3 = *(code **)*local_8c8;
                          *(undefined8 *)(puVar26 + -8) = 0x18002af94;
                          iVar9 = (*pcVar3)(plVar23,&DAT_180056158,&local_878);
                          if ((-1 < iVar9) && (local_878 == (longlong *)0x0)) {
                            pcVar3 = *(code **)(_DAT_00000000 + 0x18);
                            *(undefined8 *)(puVar26 + -8) = 0x18002afb0;
                            (*pcVar3)(0,asStack_8d4);
                          }
                          pWVar5 = local_8a8;
                          *(undefined8 *)(puVar26 + -8) = 0x18002afba;
                          UVar10 = SysStringLen(pWVar5);
                          pOVar4 = local_8b0;
                          if (UVar10 != 0) {
                            *(undefined8 *)(puVar26 + -8) = 0x18002afcc;
                            UVar10 = SysStringLen(pOVar4);
                            if (UVar10 != 0) {
                              *(undefined8 *)(puVar26 + -8) = 0x18002afe0;
                              CConverter::CConverter(local_778);
                              pOVar4 = local_8b0;
                              local_76c.Data1 = local_788.Data1;
                              local_76c.Data2 = local_788.Data2;
                              local_76c.Data3 = local_788.Data3;
                              local_76c.Data4[0] = local_788.Data4[0];
                              local_76c.Data4[1] = local_788.Data4[1];
                              local_76c.Data4[2] = local_788.Data4[2];
                              local_76c.Data4[3] = local_788.Data4[3];
                              local_76c.Data4[4] = local_788.Data4[4];
                              local_76c.Data4[5] = local_788.Data4[5];
                              local_76c.Data4[6] = local_788.Data4[6];
                              local_76c.Data4[7] = local_788.Data4[7];
                              pHVar28 = pHVar27;
                              puVar25 = puVar26;
                              if (local_8b0 != (LPCWSTR)0x0) {
                                lVar16 = -1;
                                do {
                                  lVar17 = lVar16;
                                  lVar16 = lVar17 + 1;
                                } while (local_8b0[lVar16] != L'\0');
                                iVar9 = (int)lVar17 + 2;
                                if (iVar9 < 0x40000000) {
                                  lVar16 = (longlong)(int)lVar16 * 2;
                                  uVar19 = lVar16 + 0x11;
                                  if (uVar19 <= lVar16 + 2U) {
                                    uVar19 = 0xffffffffffffff0;
                                  }
                                  *(undefined8 *)(puVar26 + -8) = 0x18002b038;
                                  lVar16 = -(uVar19 & 0xfffffffffffffff0);
                                  pHVar13 = (HKEY)(puVar26 + lVar16 + 0x40);
                                  puVar25 = puVar26 + lVar16;
                                  if (pHVar13 != (HKEY)0x0) {
                                    *(undefined1 *)&pHVar13->unused = 0;
                                    *(undefined8 *)(puVar26 + lVar16 + 0x38) = 0;
                                    *(undefined8 *)(puVar26 + lVar16 + 0x30) = 0;
                                    *(int *)(puVar26 + lVar16 + 0x28) = iVar9 * 2;
                                    *(HKEY *)(puVar26 + lVar16 + 0x20) = pHVar13;
                                    *(undefined8 *)(puVar26 + lVar16 + -8) = 0x18002b06b;
                                    iVar9 = WideCharToMultiByte(0,0,pOVar4,-1,
                                                                *(LPSTR *)(puVar26 + lVar16 + 0x20),
                                                                *(int *)(puVar26 + lVar16 + 0x28),
                                                                *(LPCSTR *)(puVar26 + lVar16 + 0x30)
                                                                ,*(LPBOOL *)
                                                                  (puVar26 + lVar16 + 0x38));
                                    pHVar28 = pHVar13;
                                    puVar25 = puVar26 + lVar16;
                                    if (iVar9 == 0) {
                                      pHVar28 = pHVar27;
                                      puVar25 = puVar26 + lVar16;
                                    }
                                  }
                                }
                              }
                              local_7b0[0] = &DAT_1800537c8;
                              sStack_7a0 = 0;
                              local_798[0] = 0;
                              local_798[1] = 0xf;
                              local_7b0[1] = (void *)0x0;
                              local_8d8 = uVar31 | 0x400;
                              sVar29 = 0xffffffffffffffff;
                              do {
                                sVar29 = sVar29 + 1;
                              } while (*(char *)((longlong)&pHVar28->unused + sVar29) != '\0');
                              *(undefined8 *)(puVar25 + -8) = 0x18002b0d2;
                              FUN_18000ad20((longlong *)
                                            ((longlong)local_7b0 + (longlong)DAT_1800537cc),pHVar28,
                                            sVar29);
                              lVar16 = (longlong)*(int *)((longlong)local_7b0[0] + 4);
                              plVar22 = (longlong *)((longlong)local_7b0 + lVar16);
                              plVar23 = (longlong *)
                                        ((longlong)local_758 + (longlong)*(int *)(local_758[0] + 4))
                              ;
                              if (plVar23 != plVar22) {
                                if (0xf < *(ulonglong *)((longlong)local_798 + lVar16)) {
                                  plVar22 = (longlong *)*plVar22;
                                }
                                sVar29 = *(size_t *)((longlong)&sStack_7a0 + lVar16);
                                *(undefined8 *)(puVar25 + -8) = 0x18002b116;
                                FUN_18000ad20(plVar23,plVar22,sVar29);
                              }
                              if (0xf < local_798[1]) {
                                pvVar11 = local_7b0[1];
                                if ((0xfff < local_798[1] + 1) &&
                                   (pvVar11 = *(void **)((longlong)local_7b0[1] + -8),
                                   0x1f < (ulonglong)
                                          ((longlong)local_7b0[1] + (-8 - (longlong)pvVar11))))
                                goto LAB_18002ba8f;
                                *(undefined8 *)(puVar25 + -8) = 0x18002b158;
                                operator_delete(pvVar11);
                              }
                              pWVar5 = local_8a8;
                              pHVar28 = pHVar27;
                              puVar26 = puVar25;
                              if (local_8a8 != (LPCWSTR)0x0) {
                                lVar16 = -1;
                                do {
                                  lVar17 = lVar16;
                                  lVar16 = lVar17 + 1;
                                } while (local_8a8[lVar16] != L'\0');
                                iVar9 = (int)lVar17 + 2;
                                if (iVar9 < 0x40000000) {
                                  lVar16 = (longlong)(int)lVar16 * 2;
                                  uVar19 = lVar16 + 0x11;
                                  if (uVar19 <= lVar16 + 2U) {
                                    uVar19 = 0xffffffffffffff0;
                                  }
                                  *(undefined8 *)(puVar25 + -8) = 0x18002b19c;
                                  lVar16 = -(uVar19 & 0xfffffffffffffff0);
                                  pHVar13 = (HKEY)(puVar25 + lVar16 + 0x40);
                                  puVar26 = puVar25 + lVar16;
                                  if (pHVar13 != (HKEY)0x0) {
                                    *(undefined1 *)&pHVar13->unused = 0;
                                    *(undefined8 *)(puVar25 + lVar16 + 0x38) = 0;
                                    *(undefined8 *)(puVar25 + lVar16 + 0x30) = 0;
                                    *(int *)(puVar25 + lVar16 + 0x28) = iVar9 * 2;
                                    *(HKEY *)(puVar25 + lVar16 + 0x20) = pHVar13;
                                    *(undefined8 *)(puVar25 + lVar16 + -8) = 0x18002b1cf;
                                    iVar9 = WideCharToMultiByte(0,0,pWVar5,-1,
                                                                *(LPSTR *)(puVar25 + lVar16 + 0x20),
                                                                *(int *)(puVar25 + lVar16 + 0x28),
                                                                *(LPCSTR *)(puVar25 + lVar16 + 0x30)
                                                                ,*(LPBOOL *)
                                                                  (puVar25 + lVar16 + 0x38));
                                    pHVar28 = pHVar13;
                                    puVar26 = puVar25 + lVar16;
                                    if (iVar9 == 0) {
                                      pHVar28 = pHVar27;
                                      puVar26 = puVar25 + lVar16;
                                    }
                                  }
                                }
                              }
                              local_7b0[0] = &DAT_1800537c8;
                              sStack_7a0 = 0;
                              local_798[0] = 0;
                              local_798[1] = 0xf;
                              local_7b0[1] = (void *)0x0;
                              local_8d8 = uVar31 | 0xc00;
                              sVar29 = 0xffffffffffffffff;
                              do {
                                sVar29 = sVar29 + 1;
                              } while (*(char *)((longlong)&pHVar28->unused + sVar29) != '\0');
                              *(undefined8 *)(puVar26 + -8) = 0x18002b232;
                              FUN_18000ad20((longlong *)
                                            ((longlong)local_7b0 + (longlong)DAT_1800537cc),pHVar28,
                                            sVar29);
                              lVar16 = (longlong)*(int *)((longlong)local_7b0[0] + 4);
                              plVar22 = (longlong *)((longlong)local_7b0 + lVar16);
                              plVar23 = (longlong *)
                                        ((longlong)local_730 + (longlong)*(int *)(local_730[0] + 4))
                              ;
                              if (plVar23 != plVar22) {
                                if (0xf < *(ulonglong *)((longlong)local_798 + lVar16)) {
                                  plVar22 = (longlong *)*plVar22;
                                }
                                sVar29 = *(size_t *)((longlong)&sStack_7a0 + lVar16);
                                *(undefined8 *)(puVar26 + -8) = 0x18002b276;
                                FUN_18000ad20(plVar23,plVar22,sVar29);
                              }
                              if (0xf < local_798[1]) {
                                pvVar11 = local_7b0[1];
                                if ((0xfff < local_798[1] + 1) &&
                                   (pvVar11 = *(void **)((longlong)local_7b0[1] + -8),
                                   puVar25 = puVar26,
                                   0x1f < (ulonglong)
                                          ((longlong)local_7b0[1] + (-8 - (longlong)pvVar11))))
                                goto LAB_18002ba8f;
                                *(undefined8 *)(puVar26 + -8) = 0x18002b2b8;
                                operator_delete(pvVar11);
                              }
                              pHVar28 = local_8b8;
                              pHVar13 = pHVar27;
                              puVar25 = puVar26;
                              if (local_8b8 != (HKEY)0x0) {
                                lVar16 = -1;
                                do {
                                  lVar17 = lVar16;
                                  lVar16 = lVar17 + 1;
                                } while (*(short *)((longlong)&local_8b8->unused + lVar17 * 2 + 2)
                                         != 0);
                                iVar9 = (int)lVar17 + 2;
                                if (iVar9 < 0x40000000) {
                                  lVar16 = (longlong)(int)(lVar17 + 1) * 2;
                                  uVar19 = lVar16 + 0x11;
                                  if (uVar19 <= lVar16 + 2U) {
                                    uVar19 = 0xffffffffffffff0;
                                  }
                                  *(undefined8 *)(puVar26 + -8) = 0x18002b2fc;
                                  lVar16 = -(uVar19 & 0xfffffffffffffff0);
                                  pHVar24 = (HKEY)(puVar26 + lVar16 + 0x40);
                                  puVar25 = puVar26 + lVar16;
                                  if (pHVar24 != (HKEY)0x0) {
                                    *(undefined1 *)&pHVar24->unused = 0;
                                    *(undefined8 *)(puVar26 + lVar16 + 0x38) = 0;
                                    *(undefined8 *)(puVar26 + lVar16 + 0x30) = 0;
                                    *(int *)(puVar26 + lVar16 + 0x28) = iVar9 * 2;
                                    *(HKEY *)(puVar26 + lVar16 + 0x20) = pHVar24;
                                    *(undefined8 *)(puVar26 + lVar16 + -8) = 0x18002b32f;
                                    iVar9 = WideCharToMultiByte(0,0,(LPCWSTR)pHVar28,-1,
                                                                *(LPSTR *)(puVar26 + lVar16 + 0x20),
                                                                *(int *)(puVar26 + lVar16 + 0x28),
                                                                *(LPCSTR *)(puVar26 + lVar16 + 0x30)
                                                                ,*(LPBOOL *)
                                                                  (puVar26 + lVar16 + 0x38));
                                    pHVar13 = pHVar24;
                                    puVar25 = puVar26 + lVar16;
                                    if (iVar9 == 0) {
                                      pHVar13 = pHVar27;
                                      puVar25 = puVar26 + lVar16;
                                    }
                                  }
                                }
                              }
                              local_7b0[0] = &DAT_1800537c8;
                              sStack_7a0 = 0;
                              local_798[0] = 0;
                              local_798[1] = 0xf;
                              local_7b0[1] = (void *)0x0;
                              local_8d8 = uVar31 | 0x1c00;
                              sVar29 = 0xffffffffffffffff;
                              do {
                                sVar29 = sVar29 + 1;
                              } while (*(char *)((longlong)&pHVar13->unused + sVar29) != '\0');
                              *(undefined8 *)(puVar25 + -8) = 0x18002b392;
                              FUN_18000ad20((longlong *)
                                            ((longlong)local_7b0 + (longlong)DAT_1800537cc),pHVar13,
                                            sVar29);
                              lVar16 = (longlong)*(int *)((longlong)local_7b0[0] + 4);
                              plVar22 = (longlong *)((longlong)local_7b0 + lVar16);
                              plVar23 = (longlong *)
                                        ((longlong)local_708 + (longlong)*(int *)(local_708[0] + 4))
                              ;
                              if (plVar23 != plVar22) {
                                if (0xf < *(ulonglong *)((longlong)local_798 + lVar16)) {
                                  plVar22 = (longlong *)*plVar22;
                                }
                                sVar29 = *(size_t *)((longlong)&sStack_7a0 + lVar16);
                                *(undefined8 *)(puVar25 + -8) = 0x18002b3d6;
                                FUN_18000ad20(plVar23,plVar22,sVar29);
                              }
                              if (0xf < local_798[1]) {
                                pvVar11 = local_7b0[1];
                                if ((0xfff < local_798[1] + 1) &&
                                   (pvVar11 = *(void **)((longlong)local_7b0[1] + -8),
                                   0x1f < (ulonglong)
                                          ((longlong)local_7b0[1] + (-8 - (longlong)pvVar11))))
                                goto LAB_18002ba8f;
                                *(undefined8 *)(puVar25 + -8) = 0x18002b418;
                                operator_delete(pvVar11);
                              }
                              pWVar5 = local_858;
                              pHVar28 = pHVar27;
                              puVar26 = puVar25;
                              if (local_858 != (LPCWSTR)0x0) {
                                lVar16 = -1;
                                do {
                                  lVar17 = lVar16;
                                  lVar16 = lVar17 + 1;
                                } while (local_858[lVar16] != L'\0');
                                iVar9 = (int)lVar17 + 2;
                                if (iVar9 < 0x40000000) {
                                  lVar16 = (longlong)(int)lVar16 * 2;
                                  uVar19 = lVar16 + 0x11;
                                  if (uVar19 <= lVar16 + 2U) {
                                    uVar19 = 0xffffffffffffff0;
                                  }
                                  *(undefined8 *)(puVar25 + -8) = 0x18002b468;
                                  lVar16 = -(uVar19 & 0xfffffffffffffff0);
                                  pHVar13 = (HKEY)(puVar25 + lVar16 + 0x40);
                                  puVar26 = puVar25 + lVar16;
                                  if (pHVar13 != (HKEY)0x0) {
                                    *(undefined1 *)&pHVar13->unused = 0;
                                    *(undefined8 *)(puVar25 + lVar16 + 0x38) = 0;
                                    *(undefined8 *)(puVar25 + lVar16 + 0x30) = 0;
                                    *(int *)(puVar25 + lVar16 + 0x28) = iVar9 * 2;
                                    *(HKEY *)(puVar25 + lVar16 + 0x20) = pHVar13;
                                    *(undefined8 *)(puVar25 + lVar16 + -8) = 0x18002b49b;
                                    iVar9 = WideCharToMultiByte(0,0,pWVar5,-1,
                                                                *(LPSTR *)(puVar25 + lVar16 + 0x20),
                                                                *(int *)(puVar25 + lVar16 + 0x28),
                                                                *(LPCSTR *)(puVar25 + lVar16 + 0x30)
                                                                ,*(LPBOOL *)
                                                                  (puVar25 + lVar16 + 0x38));
                                    pHVar28 = pHVar13;
                                    puVar26 = puVar25 + lVar16;
                                    if (iVar9 == 0) {
                                      pHVar28 = pHVar27;
                                      puVar26 = puVar25 + lVar16;
                                    }
                                  }
                                }
                              }
                              local_7b0[0] = &DAT_1800537c8;
                              sStack_7a0 = 0;
                              local_798[0] = 0;
                              local_798[1] = 0xf;
                              local_7b0[1] = (void *)0x0;
                              local_8d8 = uVar31 | 0x1c08;
                              sVar29 = 0xffffffffffffffff;
                              do {
                                sVar29 = sVar29 + 1;
                              } while (*(char *)((longlong)&pHVar28->unused + sVar29) != '\0');
                              *(undefined8 *)(puVar26 + -8) = 0x18002b502;
                              FUN_18000ad20((longlong *)
                                            ((longlong)local_7b0 + (longlong)DAT_1800537cc),pHVar28,
                                            sVar29);
                              lVar16 = (longlong)*(int *)((longlong)local_7b0[0] + 4);
                              plVar22 = (longlong *)((longlong)local_7b0 + lVar16);
                              plVar23 = (longlong *)
                                        ((longlong)local_6e0 + (longlong)*(int *)(local_6e0[0] + 4))
                              ;
                              if (plVar23 != plVar22) {
                                if (0xf < *(ulonglong *)((longlong)local_798 + lVar16)) {
                                  plVar22 = (longlong *)*plVar22;
                                }
                                sVar29 = *(size_t *)((longlong)&sStack_7a0 + lVar16);
                                *(undefined8 *)(puVar26 + -8) = 0x18002b546;
                                FUN_18000ad20(plVar23,plVar22,sVar29);
                              }
                              puVar25 = puVar26;
                              if (0xf < local_798[1]) {
                                pvVar11 = local_7b0[1];
                                if ((0xfff < local_798[1] + 1) &&
                                   (pvVar11 = *(void **)((longlong)local_7b0[1] + -8),
                                   0x1f < (ulonglong)
                                          ((longlong)local_7b0[1] + (-8 - (longlong)pvVar11))))
                                goto LAB_18002ba8f;
                                *(undefined8 *)(puVar26 + -8) = 0x18002b588;
                                operator_delete(pvVar11);
                              }
                              local_7b0[0] = &DAT_1800537c8;
                              sStack_7a0 = 0;
                              local_798[0] = 0;
                              local_798[1] = 0xf;
                              local_7b0[1] = (void *)0x0;
                              local_8d8 = uVar31 | 0x1c18;
                              sVar29 = 0xffffffffffffffff;
                              do {
                                sVar30 = sVar29 + 1;
                                lVar16 = sVar29 + 2;
                                sVar29 = sVar30;
                              } while (acStack_479[lVar16] != '\0');
                              *(undefined8 *)(puVar26 + -8) = 0x18002b5e9;
                              FUN_18000ad20((longlong *)
                                            ((longlong)local_7b0 + (longlong)DAT_1800537cc),
                                            acStack_479 + 1,sVar30);
                              lVar16 = (longlong)*(int *)((longlong)local_7b0[0] + 4);
                              plVar22 = (longlong *)((longlong)local_7b0 + lVar16);
                              plVar23 = (longlong *)
                                        ((longlong)local_6b8 + (longlong)*(int *)(local_6b8[0] + 4))
                              ;
                              if (plVar23 != plVar22) {
                                if (0xf < *(ulonglong *)((longlong)local_798 + lVar16)) {
                                  plVar22 = (longlong *)*plVar22;
                                }
                                sVar29 = *(size_t *)((longlong)&sStack_7a0 + lVar16);
                                *(undefined8 *)(puVar26 + -8) = 0x18002b62d;
                                FUN_18000ad20(plVar23,plVar22,sVar29);
                              }
                              if (0xf < local_798[1]) {
                                pvVar11 = local_7b0[1];
                                if ((0xfff < local_798[1] + 1) &&
                                   (pvVar11 = *(void **)((longlong)local_7b0[1] + -8),
                                   0x1f < (ulonglong)
                                          ((longlong)local_7b0[1] + (-8 - (longlong)pvVar11))))
                                goto LAB_18002ba8f;
                                *(undefined8 *)(puVar26 + -8) = 0x18002b66f;
                                operator_delete(pvVar11);
                              }
                              pWVar5 = local_860;
                              pHVar28 = pHVar27;
                              if (local_860 != (LPCWSTR)0x0) {
                                lVar16 = -1;
                                do {
                                  lVar17 = lVar16;
                                  lVar16 = lVar17 + 1;
                                } while (local_860[lVar16] != L'\0');
                                iVar9 = (int)lVar17 + 2;
                                if (iVar9 < 0x40000000) {
                                  lVar16 = (longlong)(int)lVar16 * 2;
                                  uVar19 = lVar16 + 0x11;
                                  if (uVar19 <= lVar16 + 2U) {
                                    uVar19 = 0xffffffffffffff0;
                                  }
                                  *(undefined8 *)(puVar26 + -8) = 0x18002b6b8;
                                  lVar16 = -(uVar19 & 0xfffffffffffffff0);
                                  pHVar13 = (HKEY)(puVar26 + lVar16 + 0x40);
                                  puVar25 = puVar26 + lVar16;
                                  if (pHVar13 != (HKEY)0x0) {
                                    *(undefined1 *)&pHVar13->unused = 0;
                                    *(undefined8 *)(puVar26 + lVar16 + 0x38) = 0;
                                    *(undefined8 *)(puVar26 + lVar16 + 0x30) = 0;
                                    *(int *)(puVar26 + lVar16 + 0x28) = iVar9 * 2;
                                    *(HKEY *)(puVar26 + lVar16 + 0x20) = pHVar13;
                                    *(undefined8 *)(puVar26 + lVar16 + -8) = 0x18002b6eb;
                                    iVar9 = WideCharToMultiByte(0,0,pWVar5,-1,
                                                                *(LPSTR *)(puVar26 + lVar16 + 0x20),
                                                                *(int *)(puVar26 + lVar16 + 0x28),
                                                                *(LPCSTR *)(puVar26 + lVar16 + 0x30)
                                                                ,*(LPBOOL *)
                                                                  (puVar26 + lVar16 + 0x38));
                                    pHVar28 = pHVar13;
                                    puVar25 = puVar26 + lVar16;
                                    if (iVar9 == 0) {
                                      pHVar28 = pHVar27;
                                      puVar25 = puVar26 + lVar16;
                                    }
                                  }
                                }
                              }
                              local_7b0[0] = &DAT_1800537c8;
                              sStack_7a0 = 0;
                              local_798[0] = 0;
                              local_798[1] = 0xf;
                              local_7b0[1] = (void *)0x0;
                              local_8d8 = uVar31 | 0x1c38;
                              sVar29 = 0xffffffffffffffff;
                              do {
                                sVar29 = sVar29 + 1;
                              } while (*(char *)((longlong)&pHVar28->unused + sVar29) != '\0');
                              *(undefined8 *)(puVar25 + -8) = 0x18002b752;
                              FUN_18000ad20((longlong *)
                                            ((longlong)local_7b0 + (longlong)DAT_1800537cc),pHVar28,
                                            sVar29);
                              lVar16 = (longlong)*(int *)((longlong)local_7b0[0] + 4);
                              plVar22 = (longlong *)((longlong)local_7b0 + lVar16);
                              plVar23 = (longlong *)
                                        ((longlong)local_690 + (longlong)*(int *)(local_690[0] + 4))
                              ;
                              if (plVar23 != plVar22) {
                                if (0xf < *(ulonglong *)((longlong)local_798 + lVar16)) {
                                  plVar22 = (longlong *)*plVar22;
                                }
                                sVar29 = *(size_t *)((longlong)&sStack_7a0 + lVar16);
                                *(undefined8 *)(puVar25 + -8) = 0x18002b796;
                                FUN_18000ad20(plVar23,plVar22,sVar29);
                              }
                              if (0xf < local_798[1]) {
                                pvVar11 = local_7b0[1];
                                if ((0xfff < local_798[1] + 1) &&
                                   (pvVar11 = *(void **)((longlong)local_7b0[1] + -8),
                                   0x1f < (ulonglong)
                                          ((longlong)local_7b0[1] + (-8 - (longlong)pvVar11))))
                                goto LAB_18002ba8f;
                                *(undefined8 *)(puVar25 + -8) = 0x18002b7d8;
                                operator_delete(pvVar11);
                              }
                              pWVar5 = local_868;
                              pHVar28 = pHVar27;
                              puVar26 = puVar25;
                              if (local_868 != (LPCWSTR)0x0) {
                                lVar16 = -1;
                                do {
                                  lVar17 = lVar16;
                                  lVar16 = lVar17 + 1;
                                } while (local_868[lVar16] != L'\0');
                                iVar9 = (int)lVar17 + 2;
                                if (iVar9 < 0x40000000) {
                                  lVar16 = (longlong)(int)lVar16 * 2;
                                  uVar19 = lVar16 + 0x11;
                                  if (uVar19 <= lVar16 + 2U) {
                                    uVar19 = 0xffffffffffffff0;
                                  }
                                  *(undefined8 *)(puVar25 + -8) = 0x18002b81c;
                                  lVar16 = -(uVar19 & 0xfffffffffffffff0);
                                  pHVar13 = (HKEY)(puVar25 + lVar16 + 0x40);
                                  puVar26 = puVar25 + lVar16;
                                  if (pHVar13 != (HKEY)0x0) {
                                    *(undefined1 *)&pHVar13->unused = 0;
                                    *(undefined8 *)(puVar25 + lVar16 + 0x38) = 0;
                                    *(undefined8 *)(puVar25 + lVar16 + 0x30) = 0;
                                    *(int *)(puVar25 + lVar16 + 0x28) = iVar9 * 2;
                                    *(HKEY *)(puVar25 + lVar16 + 0x20) = pHVar13;
                                    *(undefined8 *)(puVar25 + lVar16 + -8) = 0x18002b84f;
                                    iVar9 = WideCharToMultiByte(0,0,pWVar5,-1,
                                                                *(LPSTR *)(puVar25 + lVar16 + 0x20),
                                                                *(int *)(puVar25 + lVar16 + 0x28),
                                                                *(LPCSTR *)(puVar25 + lVar16 + 0x30)
                                                                ,*(LPBOOL *)
                                                                  (puVar25 + lVar16 + 0x38));
                                    pHVar28 = pHVar13;
                                    puVar26 = puVar25 + lVar16;
                                    if (iVar9 == 0) {
                                      pHVar28 = pHVar27;
                                      puVar26 = puVar25 + lVar16;
                                    }
                                  }
                                }
                              }
                              local_7b0[0] = &DAT_1800537c8;
                              sStack_7a0 = 0;
                              local_798[0] = 0;
                              local_798[1] = 0xf;
                              local_7b0[1] = (void *)0x0;
                              local_8d8 = uVar31 | 0x1c78;
                              sVar29 = 0xffffffffffffffff;
                              do {
                                sVar29 = sVar29 + 1;
                              } while (*(char *)((longlong)&pHVar28->unused + sVar29) != '\0');
                              *(undefined8 *)(puVar26 + -8) = 0x18002b8b2;
                              FUN_18000ad20((longlong *)
                                            ((longlong)local_7b0 + (longlong)DAT_1800537cc),pHVar28,
                                            sVar29);
                              lVar16 = (longlong)*(int *)((longlong)local_7b0[0] + 4);
                              plVar22 = (longlong *)((longlong)local_7b0 + lVar16);
                              plVar23 = (longlong *)
                                        ((longlong)local_668 + (longlong)*(int *)(local_668[0] + 4))
                              ;
                              if (plVar23 != plVar22) {
                                if (0xf < *(ulonglong *)((longlong)local_798 + lVar16)) {
                                  plVar22 = (longlong *)*plVar22;
                                }
                                sVar29 = *(size_t *)((longlong)&sStack_7a0 + lVar16);
                                *(undefined8 *)(puVar26 + -8) = 0x18002b8f6;
                                FUN_18000ad20(plVar23,plVar22,sVar29);
                              }
                              puVar25 = puVar26;
                              if (0xf < local_798[1]) {
                                pvVar11 = local_7b0[1];
                                if ((0xfff < local_798[1] + 1) &&
                                   (pvVar11 = *(void **)((longlong)local_7b0[1] + -8),
                                   0x1f < (ulonglong)
                                          ((longlong)local_7b0[1] + (-8 - (longlong)pvVar11))))
                                goto LAB_18002ba8f;
                                *(undefined8 *)(puVar26 + -8) = 0x18002b938;
                                operator_delete(pvVar11);
                              }
                              pWVar5 = local_870;
                              pHVar28 = pHVar27;
                              if (local_870 != (LPCWSTR)0x0) {
                                lVar16 = -1;
                                do {
                                  lVar17 = lVar16;
                                  lVar16 = lVar17 + 1;
                                } while (local_870[lVar16] != L'\0');
                                iVar9 = (int)lVar17 + 2;
                                if (iVar9 < 0x40000000) {
                                  lVar16 = (longlong)(int)lVar16 * 2;
                                  uVar19 = lVar16 + 0x11;
                                  if (uVar19 <= lVar16 + 2U) {
                                    uVar19 = 0xffffffffffffff0;
                                  }
                                  *(undefined8 *)(puVar26 + -8) = 0x18002b97c;
                                  lVar16 = -(uVar19 & 0xfffffffffffffff0);
                                  pHVar13 = (HKEY)(puVar26 + lVar16 + 0x40);
                                  puVar25 = puVar26 + lVar16;
                                  if (pHVar13 != (HKEY)0x0) {
                                    *(undefined1 *)&pHVar13->unused = 0;
                                    *(undefined8 *)(puVar26 + lVar16 + 0x38) = 0;
                                    *(undefined8 *)(puVar26 + lVar16 + 0x30) = 0;
                                    *(int *)(puVar26 + lVar16 + 0x28) = iVar9 * 2;
                                    *(HKEY *)(puVar26 + lVar16 + 0x20) = pHVar13;
                                    *(undefined8 *)(puVar26 + lVar16 + -8) = 0x18002b9af;
                                    iVar9 = WideCharToMultiByte(0,0,pWVar5,-1,
                                                                *(LPSTR *)(puVar26 + lVar16 + 0x20),
                                                                *(int *)(puVar26 + lVar16 + 0x28),
                                                                *(LPCSTR *)(puVar26 + lVar16 + 0x30)
                                                                ,*(LPBOOL *)
                                                                  (puVar26 + lVar16 + 0x38));
                                    pHVar28 = pHVar13;
                                    puVar25 = puVar26 + lVar16;
                                    if (iVar9 == 0) {
                                      pHVar28 = pHVar27;
                                      puVar25 = puVar26 + lVar16;
                                    }
                                  }
                                }
                              }
                              local_7b0[0] = &DAT_1800537c8;
                              sStack_7a0 = 0;
                              local_798[0] = 0;
                              local_798[1] = 0xf;
                              local_7b0[1] = (void *)0x0;
                              local_8d8 = uVar31 | 0x1cf8;
                              sVar29 = 0xffffffffffffffff;
                              do {
                                sVar29 = sVar29 + 1;
                              } while (*(char *)((longlong)&pHVar28->unused + sVar29) != '\0');
                              *(undefined8 *)(puVar25 + -8) = 0x18002ba12;
                              FUN_18000ad20((longlong *)
                                            ((longlong)local_7b0 + (longlong)DAT_1800537cc),pHVar28,
                                            sVar29);
                              lVar16 = (longlong)*(int *)((longlong)local_7b0[0] + 4);
                              plVar22 = (longlong *)((longlong)local_7b0 + lVar16);
                              plVar23 = (longlong *)
                                        ((longlong)local_640 + (longlong)*(int *)(local_640[0] + 4))
                              ;
                              if (plVar23 != plVar22) {
                                if (0xf < *(ulonglong *)((longlong)local_798 + lVar16)) {
                                  plVar22 = (longlong *)*plVar22;
                                }
                                sVar29 = *(size_t *)((longlong)&sStack_7a0 + lVar16);
                                *(undefined8 *)(puVar25 + -8) = 0x18002ba56;
                                FUN_18000ad20(plVar23,plVar22,sVar29);
                              }
                              if (0xf < local_798[1]) {
                                pvVar11 = local_7b0[1];
                                if ((0xfff < local_798[1] + 1) &&
                                   (pvVar11 = *(void **)((longlong)local_7b0[1] + -8),
                                   0x1f < (ulonglong)
                                          ((longlong)local_7b0[1] + (-8 - (longlong)pvVar11)))) {
LAB_18002ba8f:
                    /* WARNING: Subroutine does not return */
                                  *(undefined **)(puVar25 + -8) = &UNK_18002ba95;
                                  _invalid_parameter_noinfo_noreturn();
                                }
                                *(undefined8 *)(puVar25 + -8) = 0x18002ba9b;
                                operator_delete(pvVar11);
                              }
                              pWVar5 = local_8a8;
                              local_770 = iVar21;
                              local_618 = (uint)(asStack_8d4[0] != 0);
                              pHVar28 = pHVar27;
                              puVar26 = puVar25;
                              if (local_8a8 != (LPCWSTR)0x0) {
                                lVar16 = -1;
                                do {
                                  lVar17 = lVar16;
                                  lVar16 = lVar17 + 1;
                                } while (local_8a8[lVar16] != L'\0');
                                iVar9 = (int)lVar17 + 2;
                                if (iVar9 < 0x40000000) {
                                  lVar16 = (longlong)(int)lVar16 * 2;
                                  uVar19 = lVar16 + 0x11;
                                  if (uVar19 <= lVar16 + 2U) {
                                    uVar19 = 0xffffffffffffff0;
                                  }
                                  *(undefined8 *)(puVar25 + -8) = 0x18002baf6;
                                  lVar16 = -(uVar19 & 0xfffffffffffffff0);
                                  pHVar13 = (HKEY)(puVar25 + lVar16 + 0x40);
                                  puVar26 = puVar25 + lVar16;
                                  if (pHVar13 != (HKEY)0x0) {
                                    *(undefined1 *)&pHVar13->unused = 0;
                                    *(undefined8 *)(puVar25 + lVar16 + 0x38) = 0;
                                    *(undefined8 *)(puVar25 + lVar16 + 0x30) = 0;
                                    *(int *)(puVar25 + lVar16 + 0x28) = iVar9 * 2;
                                    *(HKEY *)(puVar25 + lVar16 + 0x20) = pHVar13;
                                    *(undefined8 *)(puVar25 + lVar16 + -8) = 0x18002bb29;
                                    iVar9 = WideCharToMultiByte(0,0,pWVar5,-1,
                                                                *(LPSTR *)(puVar25 + lVar16 + 0x20),
                                                                *(int *)(puVar25 + lVar16 + 0x28),
                                                                *(LPCSTR *)(puVar25 + lVar16 + 0x30)
                                                                ,*(LPBOOL *)
                                                                  (puVar25 + lVar16 + 0x38));
                                    pHVar28 = pHVar13;
                                    puVar26 = puVar25 + lVar16;
                                    if (iVar9 == 0) {
                                      pHVar28 = pHVar27;
                                      puVar26 = puVar25 + lVar16;
                                    }
                                  }
                                }
                              }
                              local_7b0[0] = &DAT_1800537c8;
                              sStack_7a0 = 0;
                              local_798[0] = 0;
                              local_798[1] = 0xf;
                              local_7b0[1] = (void *)0x0;
                              local_8d8 = uVar31 | 0x1df8;
                              sVar29 = 0xffffffffffffffff;
                              do {
                                sVar29 = sVar29 + 1;
                              } while (*(char *)((longlong)&pHVar28->unused + sVar29) != '\0');
                              *(undefined8 *)(puVar26 + -8) = 0x18002bb92;
                              FUN_18000ad20((longlong *)
                                            ((longlong)local_7b0 + (longlong)DAT_1800537cc),pHVar28,
                                            sVar29);
                              local_7f0 = local_608;
                              local_608[0] = &DAT_1800537c8;
                              local_608[2] = (undefined *)0x0;
                              local_608[3] = (undefined *)0x0;
                              local_608[4] = (undefined *)0xf;
                              local_608[1] = (undefined *)0x0;
                              uVar31 = uVar31 | 0x1ff8;
                              local_8d8 = uVar31;
                              lVar16 = (longlong)*(int *)((longlong)local_7b0[0] + 4);
                              plVar23 = (longlong *)((longlong)local_7b0 + lVar16);
                              if ((longlong *)((longlong)local_608 + (longlong)DAT_1800537cc) !=
                                  plVar23) {
                                if (0xf < *(ulonglong *)((longlong)local_798 + lVar16)) {
                                  plVar23 = (longlong *)*plVar23;
                                }
                                sVar29 = *(size_t *)((longlong)&sStack_7a0 + lVar16);
                                *(undefined8 *)(puVar26 + -8) = 0x18002bc13;
                                FUN_18000ad20((longlong *)
                                              ((longlong)local_608 + (longlong)DAT_1800537cc),
                                              plVar23,sVar29);
                              }
                              *(undefined8 *)(puVar26 + -8) = 0x18002bc27;
                              CConverter::CConverter(local_5e0,local_778);
                              pCVar20 = local_848 + 8;
                              *(undefined8 *)(puVar26 + -8) = 0x18002bc46;
                              FUN_180028630((longlong *)pCVar20,local_7e8,(longlong *)local_608);
                              *(undefined8 *)(puVar26 + -8) = 0x18002bc53;
                              CConverter::~CConverter(local_5e0);
                              *(undefined8 *)(puVar26 + -8) = 0x18002bc5f;
                              FUN_180009900((longlong)local_608);
                              if (0xf < local_798[1]) {
                                pvVar11 = local_7b0[1];
                                if ((0xfff < local_798[1] + 1) &&
                                   (pvVar11 = *(void **)((longlong)local_7b0[1] + -8),
                                   0x1f < (ulonglong)
                                          ((longlong)local_7b0[1] + (-8 - (longlong)pvVar11)))) {
                    /* WARNING: Subroutine does not return */
                                  *(undefined **)(puVar26 + -8) = &UNK_18002bc9e;
                                  _invalid_parameter_noinfo_noreturn();
                                }
                                *(undefined8 *)(puVar26 + -8) = 0x18002bca4;
                                operator_delete(pvVar11);
                              }
                              *(undefined8 *)(puVar26 + -8) = 0x18002bcb1;
                              CConverter::~CConverter(local_778);
                            }
                          }
                          if (local_878 != (longlong *)0x0) {
                            pcVar3 = *(code **)(*local_878 + 0x10);
                            *(undefined8 *)(puVar26 + -8) = 0x18002bcc1;
                            (*pcVar3)();
                          }
                          pWVar5 = local_870;
                          *(undefined8 *)(puVar26 + -8) = 0x18002bccc;
                          SysFreeString(pWVar5);
                          pWVar5 = local_868;
                          *(undefined8 *)(puVar26 + -8) = 0x18002bcd7;
                          SysFreeString(pWVar5);
                          pWVar5 = local_860;
                          *(undefined8 *)(puVar26 + -8) = 0x18002bce2;
                          SysFreeString(pWVar5);
                          pWVar5 = local_858;
                          *(undefined8 *)(puVar26 + -8) = 0x18002bcf0;
                          SysFreeString(pWVar5);
                          pHVar28 = local_8b8;
                          *(undefined8 *)(puVar26 + -8) = 0x18002bcfb;
                          SysFreeString((BSTR)pHVar28);
                          pOVar4 = local_8b0;
                          *(undefined8 *)(puVar26 + -8) = 0x18002bd06;
                          SysFreeString(pOVar4);
                          pWVar5 = local_8a8;
                          *(undefined8 *)(puVar26 + -8) = 0x18002bd11;
                          SysFreeString(pWVar5);
                          puVar25 = puVar26;
                        }
                      }
                      else if ((local_898.n2.vt & 0xfff) == 0xd) {
                        *(undefined8 *)(puVar25 + -8) = 0x18002ae19;
                        VariantChangeType((VARIANTARG *)&local_898.n2,(VARIANTARG *)&local_898.n2,0,
                                          0xd);
                        uVar6 = local_898.decVal.u2;
                        if (local_898.n2.vt == 0xd) {
                          pcVar3 = (code *)**(undefined8 **)local_898.decVal.u2;
                          *(undefined8 *)(puVar25 + -8) = 0x18002ae34;
                          (*pcVar3)(uVar6,&DAT_180056120,&local_8c8);
                        }
                        goto LAB_18002ae34;
                      }
                      if (local_8c8 != (longlong *)0x0) {
                        pcVar3 = *(code **)(*local_8c8 + 0x10);
                        *(undefined8 *)(puVar25 + -8) = 0x18002bd20;
                        (*pcVar3)();
                      }
                    }
                    *(undefined8 *)(puVar25 + -8) = 0x18002bd2b;
                    VariantClear((VARIANTARG *)&local_898.n2);
                  }
                }
                plVar23 = local_8c0;
                if ((local_8c0 != (longlong *)0x0) &&
                   (local_8c0 = (longlong *)0x0, plVar23 != (longlong *)0x0)) {
                  pcVar3 = *(code **)(*plVar23 + 0x10);
                  *(undefined8 *)(puVar25 + -8) = 0x18002bd56;
                  (*pcVar3)(plVar23);
                }
              }
              pHVar24 = local_840;
              pHVar28 = local_838[0];
              if (local_8c0 != (longlong *)0x0) {
                pcVar3 = *(code **)(*local_8c0 + 0x10);
                *(undefined8 *)(puVar25 + -8) = 0x18002bdb0;
                (*pcVar3)();
                pHVar28 = local_838[0];
              }
            }
          }
        }
        pHVar13 = (HKEY)(ulonglong)local_8cc;
        if (pHVar24 != (HKEY)0x0) {
          *(undefined8 *)(puVar25 + -8) = 0x18002ab9e;
          RegCloseKey(pHVar24);
          pHVar13 = (HKEY)(ulonglong)local_8cc;
        }
      }
    }
    pHVar28 = local_850;
    if (local_850 != (HKEY)0x0) {
      *(undefined8 *)(puVar25 + -8) = 0x18002bdd4;
      RegCloseKey(pHVar28);
    }
    pHVar28 = (HKEY)(ulonglong)(iVar21 + 1);
  } while( true );
}

/* ---- FUNC 0002BE60 FUN_18002be60 (248 bytes) ---- */

ulonglong FUN_18002be60(undefined8 *param_1,HKEY param_2,LPCSTR param_3,uint param_4)

{
  longlong *plVar1;
  LSTATUS LVar2;
  uint uVar3;
  HMODULE hModule;
  FARPROC pFVar4;
  ulonglong uVar5;
  undefined4 extraout_var;
  HKEY local_res8;
  
  plVar1 = (longlong *)param_1[2];
  local_res8 = (HKEY)0x0;
  if (plVar1 == (longlong *)0x0) {
LAB_18002beff:
    LVar2 = RegOpenKeyExA(param_2,param_3,0,param_4,&local_res8);
    uVar5 = CONCAT44(extraout_var,LVar2);
  }
  else {
    if (*plVar1 == 0) {
      if ((int)plVar1[1] != 0) goto LAB_18002beff;
    }
    else {
      hModule = GetModuleHandleA("Advapi32.dll");
      if (hModule == (HMODULE)0x0) {
        return 1;
      }
      pFVar4 = GetProcAddress(hModule,"RegOpenKeyTransactedA");
      if (pFVar4 != (FARPROC)0x0) {
        uVar5 = (*pFVar4)(param_2,param_3,0,param_4,&local_res8,*plVar1,0);
        goto LAB_18002bf18;
      }
    }
    uVar5 = 1;
  }
LAB_18002bf18:
  if ((int)uVar5 == 0) {
    uVar5 = 0;
    if ((HKEY)*param_1 != (HKEY)0x0) {
      uVar3 = RegCloseKey((HKEY)*param_1);
      uVar5 = (ulonglong)uVar3;
    }
    *param_1 = local_res8;
    *(uint *)(param_1 + 1) = param_4 & 0x300;
  }
  return uVar5;
}

/* ---- FUNC 0002BF60 FUN_18002bf60 (534 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18002bf60(int param_1)

{
  char *pcVar1;
  LPCSTR pCVar2;
  _func_6744 *p_Var3;
  IErrorInfo *This;
  BSTR pOVar4;
  HRESULT HVar5;
  longlong lVar6;
  longlong lVar7;
  ulonglong uVar8;
  int iVar9;
  LPCSTR pCVar10;
  LPCSTR pCVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  LPCSTR pCVar14;
  undefined8 uStack_70;
  undefined1 auStack_68 [32];
  undefined8 uStack_48;
  int aiStack_40 [2];
  undefined8 local_38 [2];
  IErrorInfo *local_28;
  BSTR local_20;
  BSTR local_18;
  ulonglong local_10;
  
  puVar13 = auStack_68;
  local_10 = DAT_1800791f8 ^ (ulonglong)&local_28;
  puVar12 = auStack_68;
  if (param_1 < 0) {
    pCVar10 = (LPCSTR)0x0;
    local_28 = (IErrorInfo *)0x0;
    uStack_70 = 0x18002bfa6;
    HVar5 = GetErrorInfo(0,&local_28);
    if (-1 < HVar5) {
      local_18 = (LPCWSTR)0x0;
      local_20 = (LPCWSTR)0x0;
      uStack_70 = 0x18002bfc4;
      (*local_28->lpVtbl->GetDescription)(local_28,&local_18);
      uStack_70 = 0x18002bfd2;
      (*local_28->lpVtbl->GetSource)(local_28,&local_20);
      pOVar4 = local_18;
      puVar12 = auStack_68;
      pCVar14 = pCVar10;
      if (local_18 != (LPCWSTR)0x0) {
        lVar6 = -1;
        do {
          lVar7 = lVar6;
          lVar6 = lVar7 + 1;
        } while (local_18[lVar6] != L'\0');
        iVar9 = (int)lVar7 + 2;
        puVar12 = auStack_68;
        if (iVar9 < 0x40000000) {
          lVar6 = (longlong)(int)lVar6 * 2;
          uVar8 = lVar6 + 0x11;
          if (uVar8 <= lVar6 + 2U) {
            uVar8 = 0xffffffffffffff0;
          }
          uStack_70 = 0x18002c028;
          lVar6 = -(uVar8 & 0xfffffffffffffff0);
          pcVar1 = (char *)((longlong)&local_28 + lVar6);
          puVar12 = auStack_68 + lVar6;
          if (pcVar1 != (char *)0x0) {
            *pcVar1 = '\0';
            *(undefined8 *)((longlong)local_38 + lVar6 + 8) = 0;
            *(undefined8 *)((longlong)local_38 + lVar6) = 0;
            *(int *)((longlong)aiStack_40 + lVar6) = iVar9 * 2;
            *(char **)((longlong)&uStack_48 + lVar6) = pcVar1;
            *(undefined8 *)(auStack_68 + lVar6 + -8) = 0x18002c05c;
            iVar9 = WideCharToMultiByte(0,0,pOVar4,-1,*(LPSTR *)((longlong)&uStack_48 + lVar6),
                                        *(int *)((longlong)aiStack_40 + lVar6),
                                        *(LPCSTR *)((longlong)local_38 + lVar6),
                                        *(LPBOOL *)((longlong)local_38 + lVar6 + 8));
            puVar12 = auStack_68 + lVar6;
            pCVar14 = pcVar1;
            if (iVar9 == 0) {
              puVar12 = auStack_68 + lVar6;
              pCVar14 = pCVar10;
            }
          }
        }
      }
      pOVar4 = local_20;
      pCVar11 = pCVar10;
      puVar13 = puVar12;
      if (local_20 != (LPCWSTR)0x0) {
        lVar6 = -1;
        do {
          lVar7 = lVar6;
          lVar6 = lVar7 + 1;
        } while (local_20[lVar6] != L'\0');
        iVar9 = (int)lVar7 + 2;
        if (iVar9 < 0x40000000) {
          lVar6 = (longlong)(int)lVar6 * 2;
          uVar8 = lVar6 + 0x11;
          if (uVar8 <= lVar6 + 2U) {
            uVar8 = 0xffffffffffffff0;
          }
          *(undefined8 *)(puVar12 + -8) = 0x18002c0b8;
          lVar6 = -(uVar8 & 0xfffffffffffffff0);
          pCVar2 = puVar12 + lVar6 + 0x40;
          puVar13 = puVar12 + lVar6;
          if (pCVar2 != (LPCSTR)0x0) {
            *pCVar2 = '\0';
            *(undefined8 *)(puVar12 + lVar6 + 0x38) = 0;
            *(undefined8 *)(puVar12 + lVar6 + 0x30) = 0;
            *(int *)(puVar12 + lVar6 + 0x28) = iVar9 * 2;
            *(LPCSTR *)(puVar12 + lVar6 + 0x20) = pCVar2;
            *(undefined8 *)(puVar12 + lVar6 + -8) = 0x18002c0ec;
            iVar9 = WideCharToMultiByte(0,0,pOVar4,-1,*(LPSTR *)(puVar12 + lVar6 + 0x20),
                                        *(int *)(puVar12 + lVar6 + 0x28),
                                        *(LPCSTR *)(puVar12 + lVar6 + 0x30),
                                        *(LPBOOL *)(puVar12 + lVar6 + 0x38));
            pCVar11 = pCVar2;
            puVar13 = puVar12 + lVar6;
            if (iVar9 == 0) {
              pCVar11 = pCVar10;
              puVar13 = puVar12 + lVar6;
            }
          }
        }
      }
      if (param_1 != -0x7ffbffff) {
        lVar6 = -1;
        do {
          lVar6 = lVar6 + 1;
        } while (pCVar14[lVar6] != '\0');
        if (lVar6 != 0) {
          *(undefined4 *)(puVar13 + 0x20) = 0xffffffff;
          *(undefined8 *)(puVar13 + -8) = 0x18002c12e;
          MMMessageBox((HWND)0x0,pCVar14,pCVar11,0x10,*(uint *)(puVar13 + 0x20));
        }
      }
      pOVar4 = local_20;
      *(undefined8 *)(puVar13 + -8) = 0x18002c139;
      SysFreeString(pOVar4);
      pOVar4 = local_18;
      *(undefined8 *)(puVar13 + -8) = 0x18002c144;
      SysFreeString(pOVar4);
    }
    This = local_28;
    puVar12 = puVar13;
    if (local_28 != (IErrorInfo *)0x0) {
      p_Var3 = local_28->lpVtbl->Release;
      *(undefined8 *)(puVar13 + -8) = 0x18002c154;
      (*p_Var3)(This);
    }
  }
  *(undefined8 *)(puVar12 + -8) = 0x18002c160;
  return;
}

/* ---- FUNC 0002C180 MMConvertBlock (1022 bytes) ---- */

BSTR MMConvertBlock(char *param_1,char *param_2,char *param_3,
                   _func_long_IHNodeCol_ptr_wchar_t_ptr_wchar_t_ptr_wchar_t_ptr_wchar_t_ptr_wchar_t_ptr_int
                   *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  longlong *plVar4;
  BSTR lpWideCharStr;
  CConverter *this;
  BSTR lpWideCharStr_00;
  CConverter *pCVar5;
  BSTR pOVar6;
  BSTR pOVar7;
  longlong *local_b8;
  int local_b0;
  IHNodeCol *local_a8;
  BSTR local_a0;
  longlong *local_98;
  LPCSTR local_90;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_88 [8];
  longlong *local_80;
  _union_2707 local_78;
  undefined4 local_58;
  ULONG UStack_54;
  undefined4 uStack_50;
  ULONG UStack_4c;
  undefined8 local_48;
  
                    /* 0x2c180  375  MMConvertBlock */
  pOVar7 = (BSTR)0x0;
  local_b8 = (longlong *)0x0;
  local_80 = (longlong *)0x0;
  plVar4 = (longlong *)GetGlobalPointer("HappNode");
  if ((plVar4 != (longlong *)0x0) &&
     (iVar1 = (**(code **)(*plVar4 + 0x90))(plVar4,&local_80), -1 < iVar1)) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_90,
               "Data\\Blocks\\");
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_90,param_1);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Replace
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_90,".",
               "\\Data\\Blocks\\");
    lpWideCharStr = pOVar7;
    if (local_90 != (LPCSTR)0x0) {
      iVar1 = MultiByteToWideChar(0,0,local_90,-1,(LPWSTR)0x0,0);
      lpWideCharStr = SysAllocStringLen((OLECHAR *)0x0,iVar1 - 1);
      if ((lpWideCharStr != (BSTR)0x0) &&
         (iVar2 = MultiByteToWideChar(0,0,local_90,-1,lpWideCharStr,iVar1), iVar2 != iVar1)) {
        SysFreeString(lpWideCharStr);
LAB_18002c574:
                    /* WARNING: Subroutine does not return */
        FUN_180018e40(-0x7ff8fff2);
      }
      if (lpWideCharStr == (BSTR)0x0) goto LAB_18002c574;
    }
    iVar1 = (**(code **)(*local_80 + 0x110))(local_80,lpWideCharStr,&local_b8);
    if ((iVar1 != 0) || (local_b8 != (longlong *)0x0)) {
      iVar1 = CConvertMgr::BlockCount(&g_Converter,param_2);
      iVar2 = CConvertMgr::GetLowerBound(&g_Converter,param_2);
      iVar1 = iVar1 + iVar2;
      local_b0 = iVar1;
      if (iVar2 < iVar1) {
        do {
          this = CConvertMgr::GetConverter(&g_Converter,iVar2);
          if (this != (CConverter *)0x0) {
            pCVar5 = this + (longlong)*(int *)(*(longlong *)(this + 0x70) + 4) + 0x70;
            if (0xf < *(ulonglong *)(pCVar5 + 0x18)) {
              pCVar5 = *(CConverter **)pCVar5;
            }
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_88,(char *)pCVar5);
            iVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                    CompareNoCase(local_88,param_3);
            if (iVar3 == 0) {
              local_98 = (longlong *)0x0;
              local_a8 = (IHNodeCol *)0x0;
              local_78._16_8_ = 0;
              local_78._0_8_ = 0;
              local_78.decVal.u2.Lo64 = (_union_1719)0x0;
              local_a0 = (BSTR)0x0;
              VariantInit((VARIANTARG *)&local_78.n2);
              local_58 = local_78._0_4_;
              UStack_54 = local_78.decVal.Hi32;
              uStack_50 = local_78._8_4_;
              UStack_4c = local_78._12_4_;
              local_48 = local_78._16_8_;
              iVar1 = (**(code **)(*local_b8 + 0x48))(local_b8,&local_58,&local_a0);
              VariantClear((VARIANTARG *)&local_78.n2);
              if (-1 < iVar1) {
                iVar1 = MultiByteToWideChar(0,0,"..",-1,(LPWSTR)0x0,0);
                lpWideCharStr_00 = SysAllocStringLen((OLECHAR *)0x0,iVar1 - 1);
                pOVar6 = pOVar7;
                if ((lpWideCharStr_00 == (BSTR)0x0) ||
                   (iVar3 = MultiByteToWideChar(0,0,"..",-1,lpWideCharStr_00,iVar1), iVar3 == iVar1)
                   ) {
                  if (lpWideCharStr_00 != (BSTR)0x0) {
                    SysFreeString((BSTR)0x0);
                    pOVar6 = lpWideCharStr_00;
                  }
                }
                else {
                  SysFreeString(lpWideCharStr_00);
                }
                iVar1 = (**(code **)(*local_b8 + 0x110))(local_b8,pOVar6,&local_98);
                if ((((-1 < iVar1) && (local_98 != (longlong *)0x0)) &&
                    (iVar1 = (**(code **)(*local_98 + 200))(local_98,&local_a8), plVar4 = local_b8,
                    -1 < iVar1)) && (local_a8 != (IHNodeCol *)0x0)) {
                  if (local_b8 != (longlong *)0x0) {
                    local_b8 = (longlong *)0x0;
                    (**(code **)(*plVar4 + 0x10))();
                  }
                  CConverter::Convert(this,local_a8,local_a0,param_4);
                  SysFreeString(pOVar6);
                  SysFreeString(local_a0);
                  if (local_a8 != (IHNodeCol *)0x0) {
                    (**(code **)(*(longlong *)local_a8 + 0x10))();
                  }
                  if (local_98 != (longlong *)0x0) {
                    (**(code **)(*local_98 + 0x10))();
                  }
                  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_88);
                  pOVar7 = (BSTR)0x1;
                  break;
                }
                SysFreeString(pOVar6);
              }
              SysFreeString(local_a0);
              if (local_a8 != (IHNodeCol *)0x0) {
                (**(code **)(*(longlong *)local_a8 + 0x10))();
              }
              iVar1 = local_b0;
              if (local_98 != (longlong *)0x0) {
                (**(code **)(*local_98 + 0x10))();
                iVar1 = local_b0;
              }
            }
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_88);
          }
          iVar2 = iVar2 + 1;
        } while (iVar2 < iVar1);
      }
    }
    SysFreeString(lpWideCharStr);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_90);
  }
  if (local_80 != (longlong *)0x0) {
    (**(code **)(*local_80 + 0x10))();
  }
  if (local_b8 != (longlong *)0x0) {
    (**(code **)(*local_b8 + 0x10))();
  }
  return pOVar7;
}

/* ---- FUNC 0002C2D3 FUN_18002c2d3 (313 bytes) ---- */

ulonglong FUN_18002c2d3(void)

{
  longlong lVar1;
  longlong *plVar2;
  int iVar3;
  int iVar4;
  CConverter *this;
  BSTR lpWideCharStr;
  CConverter *pCVar5;
  IHNodeCol *pIVar6;
  int unaff_EBX;
  BSTR pOVar7;
  longlong unaff_RBP;
  char *unaff_RSI;
  BSTR unaff_RDI;
  LPWSTR unaff_R14;
  int unaff_R15D;
  
  do {
    this = CConvertMgr::GetConverter(&g_Converter,unaff_R15D);
    if (this != (CConverter *)0x0) {
      pCVar5 = this + (longlong)*(int *)(*(longlong *)(this + 0x70) + 4) + 0x70;
      if (0xf < *(ulonglong *)(pCVar5 + 0x18)) {
        pCVar5 = *(CConverter **)pCVar5;
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                 (unaff_RBP + -0x29),(char *)pCVar5);
      iVar3 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                        ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                         (unaff_RBP + -0x29),unaff_RSI);
      if (iVar3 == 0) {
        *(LPWSTR *)(unaff_RBP + -0x39) = unaff_R14;
        *(LPWSTR *)(unaff_RBP + -0x49) = unaff_R14;
        *(undefined8 *)(unaff_RBP + -9) = 0;
        *(undefined8 *)(unaff_RBP + -0x19) = 0;
        *(undefined8 *)(unaff_RBP + -0x11) = 0;
        *(LPWSTR *)(unaff_RBP + -0x41) = unaff_R14;
        VariantInit((VARIANTARG *)(unaff_RBP + -0x19));
        lVar1 = **(longlong **)(unaff_RBP + -0x59);
        *(undefined4 *)(unaff_RBP + 7) = *(undefined4 *)(unaff_RBP + -0x19);
        *(undefined4 *)(unaff_RBP + 0xb) = *(undefined4 *)(unaff_RBP + -0x15);
        *(undefined4 *)(unaff_RBP + 0xf) = *(undefined4 *)(unaff_RBP + -0x11);
        *(undefined4 *)(unaff_RBP + 0x13) = *(undefined4 *)(unaff_RBP + -0xd);
        *(undefined8 *)(unaff_RBP + 0x17) = *(undefined8 *)(unaff_RBP + -9);
        iVar3 = (**(code **)(lVar1 + 0x48))
                          (*(longlong **)(unaff_RBP + -0x59),unaff_RBP + 7,unaff_RBP + -0x41);
        VariantClear((VARIANTARG *)(unaff_RBP + -0x19));
        if (-1 < iVar3) {
          iVar3 = MultiByteToWideChar(0,0,"..",-1,unaff_R14,(int)unaff_R14);
          lpWideCharStr = SysAllocStringLen((OLECHAR *)0x0,iVar3 - 1);
          pOVar7 = unaff_R14;
          if ((lpWideCharStr == (BSTR)0x0) ||
             (iVar4 = MultiByteToWideChar(0,0,"..",-1,lpWideCharStr,iVar3), iVar4 == iVar3)) {
            if (lpWideCharStr != (BSTR)0x0) {
              SysFreeString((BSTR)0x0);
              pOVar7 = lpWideCharStr;
            }
          }
          else {
            SysFreeString(lpWideCharStr);
          }
          iVar3 = (**(code **)(**(longlong **)(unaff_RBP + -0x59) + 0x110))
                            (*(longlong **)(unaff_RBP + -0x59),pOVar7,unaff_RBP + -0x39);
          if ((((-1 < iVar3) &&
               (plVar2 = *(longlong **)(unaff_RBP + -0x39), plVar2 != (longlong *)0x0)) &&
              (iVar3 = (**(code **)(*plVar2 + 200))(plVar2,unaff_RBP + -0x49), -1 < iVar3)) &&
             (pIVar6 = *(IHNodeCol **)(unaff_RBP + -0x49), pIVar6 != (IHNodeCol *)0x0)) {
            plVar2 = *(longlong **)(unaff_RBP + -0x59);
            if (plVar2 != (longlong *)0x0) {
              *(LPWSTR *)(unaff_RBP + -0x59) = unaff_R14;
              (**(code **)(*plVar2 + 0x10))();
              pIVar6 = *(IHNodeCol **)(unaff_RBP + -0x49);
            }
            CConverter::Convert(this,pIVar6,*(wchar_t **)(unaff_RBP + -0x41),
                                *(_func_long_IHNodeCol_ptr_wchar_t_ptr_wchar_t_ptr_wchar_t_ptr_wchar_t_ptr_wchar_t_ptr_int
                                  **)(unaff_RBP + 0x7f));
            SysFreeString(pOVar7);
            SysFreeString(*(BSTR *)(unaff_RBP + -0x41));
            if (*(longlong **)(unaff_RBP + -0x49) != (longlong *)0x0) {
              (**(code **)(**(longlong **)(unaff_RBP + -0x49) + 0x10))();
            }
            if (*(longlong **)(unaff_RBP + -0x39) != (longlong *)0x0) {
              (**(code **)(**(longlong **)(unaff_RBP + -0x39) + 0x10))();
            }
            ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
            ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                      ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                       (unaff_RBP + -0x29));
            unaff_R14 = (LPWSTR)0x1;
            goto LAB_18002c517;
          }
          SysFreeString(pOVar7);
          unaff_RSI = *(char **)(unaff_RBP + 0x77);
        }
        SysFreeString(*(BSTR *)(unaff_RBP + -0x41));
        if (*(longlong **)(unaff_RBP + -0x49) != (longlong *)0x0) {
          (**(code **)(**(longlong **)(unaff_RBP + -0x49) + 0x10))();
        }
        if (*(longlong **)(unaff_RBP + -0x39) != (longlong *)0x0) {
          (**(code **)(**(longlong **)(unaff_RBP + -0x39) + 0x10))();
        }
        unaff_EBX = *(int *)(unaff_RBP + -0x51);
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                 (unaff_RBP + -0x29));
    }
    unaff_R15D = unaff_R15D + 1;
    if (unaff_EBX <= unaff_R15D) {
LAB_18002c517:
      SysFreeString(unaff_RDI);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                 (unaff_RBP + -0x31));
      if (*(longlong **)(unaff_RBP + -0x21) != (longlong *)0x0) {
        (**(code **)(**(longlong **)(unaff_RBP + -0x21) + 0x10))();
      }
      if (*(longlong **)(unaff_RBP + -0x59) != (longlong *)0x0) {
        (**(code **)(**(longlong **)(unaff_RBP + -0x59) + 0x10))();
      }
      return (ulonglong)unaff_R14 & 0xffffffff;
    }
  } while( true );
}

/* ---- FUNC 0002C40C FUN_18002c40c (8 bytes) ---- */

ulonglong FUN_18002c40c(undefined8 param_1,undefined8 param_2)

{
  longlong lVar1;
  longlong *plVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  CConverter *this;
  BSTR lpWideCharStr;
  CConverter *pCVar6;
  IHNodeCol *pIVar7;
  BSTR pOVar8;
  longlong unaff_RBP;
  char *unaff_RSI;
  BSTR unaff_R14;
  BSTR pOVar9;
  char *unaff_R15;
  
  iVar3 = (**(code **)(**(longlong **)(unaff_RBP + -0x21) + 0x110))
                    (*(longlong **)(unaff_RBP + -0x21),param_2,unaff_RBP + -0x59);
  pOVar9 = unaff_R14;
  if ((iVar3 != 0) || (*(BSTR *)(unaff_RBP + -0x59) != unaff_R14)) {
    iVar3 = CConvertMgr::BlockCount(&g_Converter,unaff_R15);
    iVar4 = CConvertMgr::GetLowerBound(&g_Converter,unaff_R15);
    iVar3 = iVar3 + iVar4;
    *(int *)(unaff_RBP + -0x51) = iVar3;
    if (iVar4 < iVar3) {
      do {
        this = CConvertMgr::GetConverter(&g_Converter,iVar4);
        if (this != (CConverter *)0x0) {
          pCVar6 = this + (longlong)*(int *)(*(longlong *)(this + 0x70) + 4) + 0x70;
          if (0xf < *(ulonglong *)(pCVar6 + 0x18)) {
            pCVar6 = *(CConverter **)pCVar6;
          }
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                     (unaff_RBP + -0x29),(char *)pCVar6);
          iVar5 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                             (unaff_RBP + -0x29),unaff_RSI);
          if (iVar5 == 0) {
            *(BSTR *)(unaff_RBP + -0x39) = unaff_R14;
            *(BSTR *)(unaff_RBP + -0x49) = unaff_R14;
            *(undefined8 *)(unaff_RBP + -9) = 0;
            *(undefined8 *)(unaff_RBP + -0x19) = 0;
            *(undefined8 *)(unaff_RBP + -0x11) = 0;
            *(BSTR *)(unaff_RBP + -0x41) = unaff_R14;
            VariantInit((VARIANTARG *)(unaff_RBP + -0x19));
            lVar1 = **(longlong **)(unaff_RBP + -0x59);
            *(undefined4 *)(unaff_RBP + 7) = *(undefined4 *)(unaff_RBP + -0x19);
            *(undefined4 *)(unaff_RBP + 0xb) = *(undefined4 *)(unaff_RBP + -0x15);
            *(undefined4 *)(unaff_RBP + 0xf) = *(undefined4 *)(unaff_RBP + -0x11);
            *(undefined4 *)(unaff_RBP + 0x13) = *(undefined4 *)(unaff_RBP + -0xd);
            *(undefined8 *)(unaff_RBP + 0x17) = *(undefined8 *)(unaff_RBP + -9);
            iVar3 = (**(code **)(lVar1 + 0x48))
                              (*(longlong **)(unaff_RBP + -0x59),unaff_RBP + 7,unaff_RBP + -0x41);
            VariantClear((VARIANTARG *)(unaff_RBP + -0x19));
            if (-1 < iVar3) {
              iVar3 = MultiByteToWideChar(0,0,"..",-1,unaff_R14,(int)unaff_R14);
              lpWideCharStr = SysAllocStringLen((OLECHAR *)0x0,iVar3 - 1);
              pOVar8 = unaff_R14;
              if ((lpWideCharStr == (BSTR)0x0) ||
                 (iVar5 = MultiByteToWideChar(0,0,"..",-1,lpWideCharStr,iVar3), iVar5 == iVar3)) {
                if (lpWideCharStr != (BSTR)0x0) {
                  SysFreeString((BSTR)0x0);
                  pOVar8 = lpWideCharStr;
                }
              }
              else {
                SysFreeString(lpWideCharStr);
              }
              iVar3 = (**(code **)(**(longlong **)(unaff_RBP + -0x59) + 0x110))
                                (*(longlong **)(unaff_RBP + -0x59),pOVar8,unaff_RBP + -0x39);
              if ((((-1 < iVar3) &&
                   (plVar2 = *(longlong **)(unaff_RBP + -0x39), plVar2 != (longlong *)0x0)) &&
                  (iVar3 = (**(code **)(*plVar2 + 200))(plVar2,unaff_RBP + -0x49), -1 < iVar3)) &&
                 (pIVar7 = *(IHNodeCol **)(unaff_RBP + -0x49), pIVar7 != (IHNodeCol *)0x0)) {
                plVar2 = *(longlong **)(unaff_RBP + -0x59);
                if (plVar2 != (longlong *)0x0) {
                  *(BSTR *)(unaff_RBP + -0x59) = unaff_R14;
                  (**(code **)(*plVar2 + 0x10))();
                  pIVar7 = *(IHNodeCol **)(unaff_RBP + -0x49);
                }
                CConverter::Convert(this,pIVar7,*(wchar_t **)(unaff_RBP + -0x41),
                                    *(_func_long_IHNodeCol_ptr_wchar_t_ptr_wchar_t_ptr_wchar_t_ptr_wchar_t_ptr_wchar_t_ptr_int
                                      **)(unaff_RBP + 0x7f));
                SysFreeString(pOVar8);
                SysFreeString(*(BSTR *)(unaff_RBP + -0x41));
                if (*(longlong **)(unaff_RBP + -0x49) != (longlong *)0x0) {
                  (**(code **)(**(longlong **)(unaff_RBP + -0x49) + 0x10))();
                }
                if (*(longlong **)(unaff_RBP + -0x39) != (longlong *)0x0) {
                  (**(code **)(**(longlong **)(unaff_RBP + -0x39) + 0x10))();
                }
                ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           (unaff_RBP + -0x29));
                pOVar9 = (BSTR)0x1;
                break;
              }
              SysFreeString(pOVar8);
              unaff_RSI = *(char **)(unaff_RBP + 0x77);
            }
            SysFreeString(*(BSTR *)(unaff_RBP + -0x41));
            if (*(longlong **)(unaff_RBP + -0x49) != (longlong *)0x0) {
              (**(code **)(**(longlong **)(unaff_RBP + -0x49) + 0x10))();
            }
            if (*(longlong **)(unaff_RBP + -0x39) != (longlong *)0x0) {
              (**(code **)(**(longlong **)(unaff_RBP + -0x39) + 0x10))();
            }
            iVar3 = *(int *)(unaff_RBP + -0x51);
          }
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
          ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                     (unaff_RBP + -0x29));
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar3);
    }
  }
  SysFreeString(unaff_R14);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(unaff_RBP + -0x31));
  if (*(longlong **)(unaff_RBP + -0x21) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(unaff_RBP + -0x21) + 0x10))();
  }
  if (*(longlong **)(unaff_RBP + -0x59) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(unaff_RBP + -0x59) + 0x10))();
  }
  return (ulonglong)pOVar9 & 0xffffffff;
}

/* ---- FUNC 0002C414 FUN_18002c414 (275 bytes) ---- */

ulonglong FUN_18002c414(void)

{
  longlong lVar1;
  longlong *plVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  CConverter *pCVar6;
  IHNodeCol *pIVar7;
  LPWSTR unaff_RBX;
  longlong unaff_RBP;
  BSTR unaff_RSI;
  BSTR unaff_RDI;
  CConverter *unaff_R12;
  LPWSTR unaff_R14;
  int unaff_R15D;
  
code_r0x00018002c414:
  if (unaff_RSI != (BSTR)0x0) {
    SysFreeString((BSTR)0x0);
    unaff_RBX = unaff_RSI;
  }
  do {
    iVar5 = (**(code **)(**(longlong **)(unaff_RBP + -0x59) + 0x110))
                      (*(longlong **)(unaff_RBP + -0x59),unaff_RBX,unaff_RBP + -0x39);
    if ((((-1 < iVar5) && (plVar2 = *(longlong **)(unaff_RBP + -0x39), plVar2 != (longlong *)0x0))
        && (iVar5 = (**(code **)(*plVar2 + 200))(plVar2,unaff_RBP + -0x49), -1 < iVar5)) &&
       (pIVar7 = *(IHNodeCol **)(unaff_RBP + -0x49), pIVar7 != (IHNodeCol *)0x0)) {
      plVar2 = *(longlong **)(unaff_RBP + -0x59);
      if (plVar2 != (longlong *)0x0) {
        *(LPWSTR *)(unaff_RBP + -0x59) = unaff_R14;
        (**(code **)(*plVar2 + 0x10))();
        pIVar7 = *(IHNodeCol **)(unaff_RBP + -0x49);
      }
      CConverter::Convert(unaff_R12,pIVar7,*(wchar_t **)(unaff_RBP + -0x41),
                          *(_func_long_IHNodeCol_ptr_wchar_t_ptr_wchar_t_ptr_wchar_t_ptr_wchar_t_ptr_wchar_t_ptr_int
                            **)(unaff_RBP + 0x7f));
      SysFreeString(unaff_RBX);
      SysFreeString(*(BSTR *)(unaff_RBP + -0x41));
      if (*(longlong **)(unaff_RBP + -0x49) != (longlong *)0x0) {
        (**(code **)(**(longlong **)(unaff_RBP + -0x49) + 0x10))();
      }
      if (*(longlong **)(unaff_RBP + -0x39) != (longlong *)0x0) {
        (**(code **)(**(longlong **)(unaff_RBP + -0x39) + 0x10))();
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                 (unaff_RBP + -0x29));
      unaff_R14 = (LPWSTR)0x1;
LAB_18002c517:
      SysFreeString(unaff_RDI);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                 (unaff_RBP + -0x31));
      if (*(longlong **)(unaff_RBP + -0x21) != (longlong *)0x0) {
        (**(code **)(**(longlong **)(unaff_RBP + -0x21) + 0x10))();
      }
      if (*(longlong **)(unaff_RBP + -0x59) != (longlong *)0x0) {
        (**(code **)(**(longlong **)(unaff_RBP + -0x59) + 0x10))();
      }
      return (ulonglong)unaff_R14 & 0xffffffff;
    }
    SysFreeString(unaff_RBX);
    pcVar3 = *(char **)(unaff_RBP + 0x77);
    do {
      SysFreeString(*(BSTR *)(unaff_RBP + -0x41));
      if (*(longlong **)(unaff_RBP + -0x49) != (longlong *)0x0) {
        (**(code **)(**(longlong **)(unaff_RBP + -0x49) + 0x10))();
      }
      if (*(longlong **)(unaff_RBP + -0x39) != (longlong *)0x0) {
        (**(code **)(**(longlong **)(unaff_RBP + -0x39) + 0x10))();
      }
      iVar5 = *(int *)(unaff_RBP + -0x51);
      do {
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                   (unaff_RBP + -0x29));
        do {
          unaff_R15D = unaff_R15D + 1;
          if (iVar5 <= unaff_R15D) goto LAB_18002c517;
          unaff_R12 = CConvertMgr::GetConverter(&g_Converter,unaff_R15D);
        } while (unaff_R12 == (CConverter *)0x0);
        pCVar6 = unaff_R12 + (longlong)*(int *)(*(longlong *)(unaff_R12 + 0x70) + 4) + 0x70;
        if (0xf < *(ulonglong *)(pCVar6 + 0x18)) {
          pCVar6 = *(CConverter **)pCVar6;
        }
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                   (unaff_RBP + -0x29),(char *)pCVar6);
        iVar4 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::CompareNoCase
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           (unaff_RBP + -0x29),pcVar3);
      } while (iVar4 != 0);
      *(LPWSTR *)(unaff_RBP + -0x39) = unaff_R14;
      *(LPWSTR *)(unaff_RBP + -0x49) = unaff_R14;
      *(undefined8 *)(unaff_RBP + -9) = 0;
      *(undefined8 *)(unaff_RBP + -0x19) = 0;
      *(undefined8 *)(unaff_RBP + -0x11) = 0;
      *(LPWSTR *)(unaff_RBP + -0x41) = unaff_R14;
      VariantInit((VARIANTARG *)(unaff_RBP + -0x19));
      lVar1 = **(longlong **)(unaff_RBP + -0x59);
      *(undefined4 *)(unaff_RBP + 7) = *(undefined4 *)(unaff_RBP + -0x19);
      *(undefined4 *)(unaff_RBP + 0xb) = *(undefined4 *)(unaff_RBP + -0x15);
      *(undefined4 *)(unaff_RBP + 0xf) = *(undefined4 *)(unaff_RBP + -0x11);
      *(undefined4 *)(unaff_RBP + 0x13) = *(undefined4 *)(unaff_RBP + -0xd);
      *(undefined8 *)(unaff_RBP + 0x17) = *(undefined8 *)(unaff_RBP + -9);
      iVar5 = (**(code **)(lVar1 + 0x48))
                        (*(longlong **)(unaff_RBP + -0x59),unaff_RBP + 7,unaff_RBP + -0x41);
      VariantClear((VARIANTARG *)(unaff_RBP + -0x19));
    } while (iVar5 < 0);
    iVar5 = MultiByteToWideChar(0,0,"..",-1,unaff_R14,(int)unaff_R14);
    unaff_RSI = SysAllocStringLen((OLECHAR *)0x0,iVar5 - 1);
    unaff_RBX = unaff_R14;
    if ((unaff_RSI == (BSTR)0x0) ||
       (iVar4 = MultiByteToWideChar(0,0,"..",-1,unaff_RSI,iVar5), iVar4 == iVar5))
    goto code_r0x00018002c414;
    SysFreeString(unaff_RSI);
  } while( true );
}

/* ---- FUNC 0002C527 FUN_18002c527 (68 bytes) ---- */

undefined4 FUN_18002c527(void)

{
  longlong unaff_RBP;
  BSTR unaff_RDI;
  undefined4 unaff_R14D;
  
  SysFreeString(unaff_RDI);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)(unaff_RBP + -0x31));
  if (*(longlong **)(unaff_RBP + -0x21) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(unaff_RBP + -0x21) + 0x10))();
  }
  if (*(longlong **)(unaff_RBP + -0x59) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(unaff_RBP + -0x59) + 0x10))();
  }
  return unaff_R14D;
}

/* ---- FUNC 0002C580 MMInitConverter (35 bytes) ---- */

void MMInitConverter(void)

{
  ulonglong uVar1;
  
                    /* 0x2c580  399  MMInitConverter */
  uVar1 = FUN_1800240b0();
  if ((int)uVar1 == 1) {
    CConvertMgr::Initialize(&g_Converter);
    return;
  }
  return;
}

/* ---- FUNC 0002C5B0 FUN_18002c5b0 (309 bytes) ---- */

void FUN_18002c5b0(longlong param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  void *pvVar4;
  void *pvVar5;
  longlong lVar6;
  
  lVar6 = *(longlong *)(param_1 + 0x20);
  plVar1 = (longlong *)(param_1 + 0x10);
  plVar2 = (longlong *)(param_1 + 8);
  do {
    if (lVar6 == 0) goto LAB_18002c657;
    plVar3 = *(longlong **)
              (*plVar2 + (*(longlong *)(param_1 + 0x18) + -1 + lVar6 & *plVar1 - 1U) * 8);
    pvVar4 = (void *)*plVar3;
    if (pvVar4 != (void *)0x0) {
      pvVar5 = pvVar4;
      if ((0xfff < (ulonglong)(plVar3[2] - (longlong)pvVar4)) &&
         (pvVar5 = *(void **)((longlong)pvVar4 + -8),
         0x1f < (ulonglong)((longlong)pvVar4 + (-8 - (longlong)pvVar5)))) goto LAB_18002c6df;
      operator_delete(pvVar5);
      *plVar3 = 0;
      plVar3[1] = 0;
      plVar3[2] = 0;
    }
    lVar6 = *(longlong *)(param_1 + 0x20) + -1;
    *(longlong *)(param_1 + 0x20) = lVar6;
  } while (lVar6 != 0);
  *(undefined8 *)(param_1 + 0x18) = 0;
LAB_18002c657:
  if (*plVar2 != 0) {
    lVar6 = *plVar1;
    while (lVar6 != 0) {
      lVar6 = lVar6 + -1;
      pvVar4 = *(void **)(*plVar2 + lVar6 * 8);
      if (pvVar4 != (void *)0x0) {
        operator_delete(pvVar4);
      }
    }
    pvVar4 = (void *)*plVar2;
    pvVar5 = pvVar4;
    if ((0xfff < (ulonglong)(*plVar1 << 3)) &&
       (pvVar5 = *(void **)((longlong)pvVar4 + -8),
       0x1f < (ulonglong)((longlong)pvVar4 + (-8 - (longlong)pvVar5)))) {
LAB_18002c6df:
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar5);
  }
  *plVar2 = 0;
  *plVar1 = 0;
  return;
}

/* ---- FUNC 0002C6F0 FUN_18002c6f0 (50 bytes) ---- */

undefined8 FUN_18002c6f0(undefined8 param_1,int param_2)

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

/* ---- FUNC 0002C730 FUN_18002c730 (365 bytes) ---- */

longlong * FUN_18002c730(longlong *param_1,longlong *param_2)

{
  ulonglong uVar1;
  ulonglong _Size;
  ulonglong uVar2;
  void *pvVar3;
  void *_Dst;
  ulonglong uVar4;
  void *pvVar5;
  longlong *_Dst_00;
  ulonglong uVar6;
  longlong *_Src;
  
  if (param_1 != param_2) {
    _Src = param_2;
    if (0xf < (ulonglong)param_2[3]) {
      _Src = (longlong *)*param_2;
    }
    _Size = param_2[2];
    uVar2 = param_1[3];
    if (uVar2 < _Size) {
      uVar6 = 0x7fffffffffffffff;
      if (0x7fffffffffffffff < _Size) {
                    /* WARNING: Subroutine does not return */
        FUN_18000ace0();
      }
      uVar4 = _Size | 0xf;
      if (uVar4 < 0x8000000000000000) {
        if (0x7fffffffffffffff - (uVar2 >> 1) < uVar2) {
          _Dst = (void *)FUN_180007f10(0x8000000000000000);
        }
        else {
          uVar1 = (uVar2 >> 1) + uVar2;
          uVar6 = uVar4;
          if (uVar4 < uVar1) {
            uVar6 = uVar1;
          }
          uVar4 = uVar6 + 1;
          if (uVar4 < 0x1000) {
            if (uVar4 == 0) {
              _Dst = (void *)0x0;
            }
            else {
              _Dst = operator_new(uVar4);
            }
          }
          else {
            _Dst = (void *)FUN_180007f10(uVar4);
          }
        }
      }
      else {
        _Dst = (void *)FUN_180007f10(0x8000000000000000);
      }
      param_1[2] = _Size;
      param_1[3] = uVar6;
      memcpy(_Dst,_Src,_Size);
      *(undefined1 *)((longlong)_Dst + _Size) = 0;
      if (0xf < uVar2) {
        pvVar3 = (void *)*param_1;
        pvVar5 = pvVar3;
        if ((0xfff < uVar2 + 1) &&
           (pvVar5 = *(void **)((longlong)pvVar3 + -8),
           0x1f < (ulonglong)((longlong)pvVar3 + (-8 - (longlong)pvVar5)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        operator_delete(pvVar5);
      }
      *param_1 = (longlong)_Dst;
    }
    else {
      _Dst_00 = param_1;
      if (0xf < uVar2) {
        _Dst_00 = (longlong *)*param_1;
      }
      param_1[2] = _Size;
      memmove(_Dst_00,_Src,_Size);
      *(undefined1 *)((longlong)_Dst_00 + _Size) = 0;
    }
  }
  return param_1;
}

/* ---- FUNC 0002C8A0 FUN_18002c8a0 (167 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_18002c8a0(int param_1)

{
  undefined1 auStack_428 [32];
  undefined1 local_408 [1008];
  ulonglong local_18;
  
  local_18 = DAT_1800791f8 ^ (ulonglong)auStack_428;
  if (param_1 != 0) {
    if (param_1 == 1) {
      return 1;
    }
    if (param_1 == 2) {
      return 2;
    }
    FUN_180007de0(local_408,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\mmstruct.cpp",0xb1);
    LogMessage(local_408,2,1);
  }
  return 0;
}

/* ---- FUNC 0002C950 MMDisplayHelp (261 bytes) ---- */

undefined8 MMDisplayHelp(short *param_1)

{
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar1;
  wchar_t *pwVar2;
  undefined8 uVar3;
  longlong local_res8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res20 [8];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_18 [16];
  
                    /* 0x2c950  135  MMDisplayHelp */
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8);
  if (*param_1 == 8) {
    pwVar2 = *(wchar_t **)(param_1 + 4);
  }
  else {
    if (*param_1 != 0x4008) {
      uVar3 = 0;
      goto LAB_18002ca3d;
    }
    pwVar2 = (wchar_t *)**(undefined8 **)(param_1 + 4);
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8,pwVar2);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::MakeUpper
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Replace
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8,".HLP",
             ".CHM");
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            (local_res20,
             (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             &local_res8);
  if (*(char *)(local_res8 + 1) == ':') {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::ReverseFind
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8,'\\');
    pCVar1 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Mid
                       ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8
                        ,(int)local_18);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              (local_res20,pCVar1);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_18);
  }
  MMDisplayHtmlHelp();
  uVar3 = 1;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res20);
LAB_18002ca3d:
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8);
  return uVar3;
}

/* ---- FUNC 0002CA60 FUN_18002ca60 (83 bytes) ---- */

uint FUN_18002ca60(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  if ((param_1 & 2) == 0) {
    uVar2 = 0;
    if ((param_1 & 1) != 0) {
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 2;
  }
  uVar1 = uVar2 | 0x10;
  if ((param_1 >> 10 & 1) == 0) {
    uVar1 = uVar2;
  }
  uVar2 = uVar1 | 0x1000;
  if ((param_1 >> 8 & 1) == 0) {
    uVar2 = uVar1;
  }
  if ((uVar2 & 0xf0) == 0) {
    uVar1 = 0x20;
    if ((uVar2 & 3) != 0) {
      uVar1 = 0x10;
    }
    return uVar1 | uVar2;
  }
  return uVar2;
}

/* ---- FUNC 0002CAC0 FUN_18002cac0 (71 bytes) ---- */

uint FUN_18002cac0(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  if ((param_1 & 2) == 0) {
    uVar2 = 0;
    if ((param_1 & 1) != 0) {
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 2;
  }
  uVar1 = uVar2 | 0x100;
  if ((param_1 >> 0xc & 1) == 0) {
    uVar1 = uVar2;
  }
  uVar2 = uVar1 | 0x400;
  if ((param_1 & 0x10) == 0) {
    uVar2 = uVar1;
  }
  uVar1 = uVar2 | 0x8000;
  if ((param_1 >> 0x10 & 1) != 0) {
    uVar1 = uVar2;
  }
  return uVar1;
}

/* ---- FUNC 0002CB10 AssistVw (1661 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00018002d125) */

BOOL AssistVw(void)

{
  longlong lVar1;
  HKEY hKey;
  char cVar2;
  int iVar3;
  LSTATUS LVar4;
  BOOL BVar5;
  char *pcVar6;
  undefined8 uVar7;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar8;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar9;
  LPBYTE lpData;
  IAtlStringMgr *pIVar10;
  longlong lVar11;
  HKEY pHVar13;
  undefined1 auStackY_288 [32];
  HKEY local_238;
  longlong local_230;
  char *local_228;
  DWORD local_220;
  undefined4 uStack_21c;
  longlong local_218;
  undefined8 local_210;
  undefined8 local_208;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_200 [8];
  HKEY local_1f8;
  LPSTR local_1f0;
  _PROCESS_INFORMATION local_1e8;
  _STARTUPINFOA local_1c8;
  BYTE local_128;
  undefined1 local_127 [271];
  ulonglong local_18;
  longlong lVar12;
  
                    /* 0x2cb10  319  AssistVw */
  local_18 = DAT_1800791f8 ^ (ulonglong)auStackY_288;
  local_1c8.cb = 0x68;
  local_1c8._4_8_ = 0;
  local_1c8._12_8_ = 0;
  local_1c8.hStdError._4_4_ = 0;
  local_1c8._20_8_ = 0;
  local_1c8._28_8_ = 0;
  local_1c8.dwY = 0;
  local_1c8.dwXSize = 0;
  local_1c8.dwYSize = 0;
  local_1c8.dwXCountChars = 0;
  local_1c8.dwYCountChars = 0;
  local_1c8.dwFillAttribute = 0;
  local_1c8.dwFlags = 0;
  local_1c8.wShowWindow = 0;
  local_1c8.cbReserved2 = 0;
  local_1c8._68_8_ = 0;
  local_1c8._76_8_ = 0;
  local_1c8._84_8_ = 0;
  local_1c8._92_8_ = 0;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_200);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_230);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_218);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_208);
  pcVar6 = (char *)GetGlobalPointer("MMCOMMONXEQ");
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=(local_200,pcVar6);
  pcVar6 = (char *)SEGetSettingValue("proppkgsel",0);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_230,pcVar6);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_228);
  uVar7 = FUN_180019850((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_228)
  ;
  if (((int)uVar7 == 1) && (0 < *(int *)(local_228 + -0x10))) {
    iVar3 = _stricmp(local_228,"ENG");
    if (iVar3 == 0) {
      pcVar6 = "PropertyMethodAssistant";
    }
    else {
      iVar3 = _stricmp(local_228,"FRA");
      if (iVar3 == 0) {
        pcVar6 = "PropertyMethodAssistant_FRA";
      }
      else {
        iVar3 = _stricmp(local_228,"ITA");
        if (iVar3 == 0) {
          pcVar6 = "PropertyMethodAssistant_ITA";
        }
        else {
          iVar3 = _stricmp(local_228,"DEU");
          if (iVar3 == 0) {
            pcVar6 = "PropertyMethodAssistant_DEU";
          }
          else {
            iVar3 = _stricmp(local_228,"SPA");
            if (iVar3 == 0) {
              pcVar6 = "PropertyMethodAssistant_SPA";
            }
            else {
              iVar3 = _stricmp(local_228,"JPN");
              if (iVar3 == 0) {
                pcVar6 = "PropertyMethodAssistant_JPN";
              }
              else {
                iVar3 = _stricmp(local_228,"CHS");
                if (iVar3 == 0) {
                  pcVar6 = "PropertyMethodAssistant_CHS";
                }
                else {
                  iVar3 = _stricmp(local_228,"KOR");
                  if (iVar3 == 0) {
                    pcVar6 = "PropertyMethodAssistant_KOR";
                  }
                  else {
                    iVar3 = _stricmp(local_228,"RUS");
                    if (iVar3 == 0) {
                      pcVar6 = "PropertyMethodAssistant_RUS";
                    }
                    else {
                      iVar3 = _stricmp(local_228,"PTB");
                      if (iVar3 != 0) goto LAB_18002cd3d;
                      pcVar6 = "PropertyMethodAssistant_PTB";
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_230,pcVar6);
  }
LAB_18002cd3d:
  if (*(int *)(local_230 + -0x10) != 0) {
    pCVar8 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                       ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1f8,
                        (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *
                        )local_200);
    pCVar9 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
             ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
             CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                       ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_238,
                        (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *
                        )&local_230);
    FUN_180019920(pCVar9,pCVar8,
                  (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_208);
    iVar3 = _stat64i32(local_208);
    if (iVar3 == -1) {
      pcVar6 = (char *)SEGetSettingValue("proppkgsel",0);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_230,pcVar6)
      ;
      if (*(int *)(local_230 + -0x10) != 0) {
        pCVar8 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                 ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                 CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                           ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            &local_1f8,
                            (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                             *)local_200);
        pCVar9 = (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                 ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
                 CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                           ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                            &local_238,
                            (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                             *)&local_230);
        FUN_180019920(pCVar9,pCVar8,
                      (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_208);
      }
    }
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_210);
  local_238 = (HKEY)0x0;
  LVar4 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000002,"SOFTWARE\\AspenTech\\Setup",0,0x20019,
                        &local_238);
  hKey = local_238;
  pHVar13 = (HKEY)0x0;
  if (LVar4 == 0) {
    local_220 = 0;
    local_238 = (HKEY)((ulonglong)local_238 & 0xffffffff00000000);
    LVar4 = RegQueryValueExA(hKey,"ASPENCOMMONdir",(LPDWORD)0x0,(LPDWORD)&local_238,(LPBYTE)0x0,
                             &local_220);
    pHVar13 = hKey;
    if (((LVar4 == 0) || ((int)local_238 - 1U < 2)) || ((int)local_238 == 7)) {
      lpData = (LPBYTE)ATL::CSimpleStringT<char,1>::GetBufferSetLength
                                 ((CSimpleStringT<char,1> *)&local_210,local_220 + 1);
      LVar4 = RegQueryValueExA(hKey,"ASPENCOMMONdir",(LPDWORD)0x0,(LPDWORD)&local_238,lpData,
                               &local_220);
      ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)&local_210,-1);
      if (LVar4 == 0) goto LAB_18002cff7;
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_220);
    pcVar6 = getenv("CommonProgramFiles");
    if (pcVar6 == (char *)0x0) {
      LVar4 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000002,
                            "Software\\Microsoft\\Windows\\CurrentVersion",0,1,&local_1f8);
      if (LVar4 == 0) {
        local_128 = '\0';
        memset(local_127,0,0x103);
        local_238 = (HKEY)CONCAT44(local_238._4_4_,0x104);
        LVar4 = RegQueryValueExA(local_1f8,"CommonFilesDir",(LPDWORD)0x0,(LPDWORD)0x0,&local_128,
                                 (LPDWORD)&local_238);
        if (LVar4 == 0) {
          ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                    ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_220,
                     (char *)&local_128);
        }
        RegCloseKey(local_1f8);
      }
    }
    else {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_220,pcVar6)
      ;
    }
    if (*(int *)(CONCAT44(uStack_21c,local_220) + -0x10) != 0) {
      pIVar10 = ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::GetManager
                          ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)
                           &local_220);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_238,pIVar10
                );
      lVar12 = -1;
      do {
        lVar11 = lVar12 + 1;
        lVar1 = lVar12 + 1;
        lVar12 = lVar11;
      } while ("\\AspenTech Shared"[lVar1] != '\0');
      ATL::CSimpleStringT<char,1>::Concatenate
                ((CSimpleStringT<char,1> *)&local_238,(char *)CONCAT44(uStack_21c,local_220),
                 *(int *)((char *)CONCAT44(uStack_21c,local_220) + -0x10),"\\AspenTech Shared",
                 (int)lVar11);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_210,
                 (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                 &local_238);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_238);
    }
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_220);
  }
LAB_18002cff7:
  if (pHVar13 != (HKEY)0x0) {
    RegCloseKey(pHVar13);
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_218,
             (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)&local_210
            );
  cVar2 = ATL::CSimpleStringT<char,1>::operator[]
                    ((CSimpleStringT<char,1> *)&local_218,*(int *)(local_218 + -0x10) + -1);
  if (cVar2 != '\\') {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_218,"\\");
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_218,
             "AspenTech.Visualisation.Assistant.Run.exe");
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1f0);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1f0,"\"%s\" %s"
            );
  BVar5 = CreateProcessA((LPCSTR)0x0,local_1f0,(LPSECURITY_ATTRIBUTES)0x0,(LPSECURITY_ATTRIBUTES)0x0
                         ,0,0,(LPVOID)0x0,(LPCSTR)0x0,&local_1c8,&local_1e8);
  if (BVar5 == 0) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_238);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::Format
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_238,
               "Cannot find the exe file in %s.",local_210);
    MMAfxMessageBox((char *)local_238,0,-1,0);
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_238);
  }
  else {
    CloseHandle(local_1e8.hThread);
    CloseHandle(local_1e8.hProcess);
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1f0);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_210);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_228);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_208);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_218);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_230);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_200);
  return BVar5;
}

/* ---- FUNC 0002D190 CompareShortPathName (336 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int CompareShortPathName(char *param_1,char *param_2)

{
  char cVar1;
  DWORD DVar2;
  DWORD DVar3;
  int iVar4;
  longlong lVar5;
  undefined1 auStack_268 [32];
  LPSTR local_248 [2];
  CHAR local_238 [272];
  CHAR local_128 [272];
  ulonglong local_18;
  
                    /* 0x2d190  339  CompareShortPathName */
  local_18 = DAT_1800791f8 ^ (ulonglong)auStack_268;
  DVar2 = GetFullPathNameA(param_1,0x104,local_128,local_248);
  if (DVar2 == 0) {
    lVar5 = (longlong)local_128 - (longlong)param_1;
    do {
      cVar1 = *param_1;
      param_1[lVar5] = cVar1;
      param_1 = param_1 + 1;
    } while (cVar1 != '\0');
  }
  else {
    DVar2 = GetFileAttributesA(local_128);
    if ((((DVar2 & 0x10) == 0) || (DVar2 == 0xffffffff)) && (local_248[0] != (LPSTR)0x0)) {
      *local_248[0] = '\0';
    }
  }
  DVar2 = GetFullPathNameA(param_2,0x104,local_238,local_248);
  if (DVar2 == 0) {
    lVar5 = (longlong)local_238 - (longlong)param_2;
    do {
      cVar1 = *param_2;
      param_2[lVar5] = cVar1;
      param_2 = param_2 + 1;
    } while (cVar1 != '\0');
  }
  else {
    DVar2 = GetFileAttributesA(local_238);
    if ((((DVar2 & 0x10) == 0) || (DVar2 == 0xffffffff)) && (local_248[0] != (LPSTR)0x0)) {
      *local_248[0] = '\0';
    }
  }
  DVar2 = GetShortPathNameA(local_128,local_128,0x104);
  if (((DVar2 != 0) && (DVar3 = GetShortPathNameA(local_238,local_238,0x104), DVar3 != 0)) &&
     ((int)DVar3 <= (int)DVar2)) {
    iVar4 = _strnicmp(local_128,local_238,(longlong)(int)DVar3);
    return -(uint)(iVar4 != 0);
  }
  return -1;
}

/* ---- FUNC 0002D2E0 DllCanUnloadNow (48 bytes) ---- */

HRESULT __stdcall DllCanUnloadNow(void)

{
  long lVar1;
  AFX_MAINTAIN_STATE2 local_18 [16];
  
                    /* 0x2d2e0  344  DllCanUnloadNow */
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_18,DAT_18007b728);
  lVar1 = AfxDllCanUnloadNow();
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_18);
  return lVar1;
}

/* ---- FUNC 0002D310 FUN_18002d310 (82 bytes) ---- */

undefined8 FUN_18002d310(HINSTANCE__ *param_1,int param_2)

{
  if (param_2 == 1) {
    FUN_180019400();
    AfxInitExtensionModule((AFX_EXTENSION_MODULE *)&DAT_18007b700,param_1);
  }
  FUN_180024760(param_1,param_2);
  return 1;
}

/* ---- FUNC 0002D370 GenerateErrorInfo (309 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void GenerateErrorInfo(LPCSTR param_1)

{
  OLECHAR *pOVar1;
  _func_6755 *p_Var2;
  _func_6750 *p_Var3;
  _func_6744 *p_Var4;
  _func_6752 *p_Var5;
  ICreateErrorInfo *pIVar6;
  IErrorInfo *pIVar7;
  HRESULT HVar8;
  longlong lVar9;
  BSTR szDescription;
  ulonglong uVar11;
  int iVar12;
  OLECHAR *psz;
  undefined1 *puVar13;
  OLECHAR *pOVar14;
  undefined8 uStack_60;
  undefined1 auStack_58 [32];
  undefined8 uStack_38;
  int aiStack_30 [2];
  ICreateErrorInfo *local_28;
  IErrorInfo *local_20;
  ulonglong local_18;
  longlong lVar10;
  
                    /* 0x2d370  353  GenerateErrorInfo */
  puVar13 = auStack_58;
  local_18 = DAT_1800791f8 ^ (ulonglong)&local_28;
  pOVar14 = (OLECHAR *)0x0;
  local_28 = (ICreateErrorInfo *)0x0;
  uStack_60 = 0x18002d3a8;
  HVar8 = CreateErrorInfo(&local_28);
  if (-1 < HVar8) {
    psz = pOVar14;
    puVar13 = auStack_58;
    if (param_1 != (LPCSTR)0x0) {
      lVar9 = -1;
      do {
        lVar10 = lVar9;
        lVar9 = lVar10 + 1;
      } while (param_1[lVar9] != '\0');
      iVar12 = (int)lVar10 + 2;
      puVar13 = auStack_58;
      if (iVar12 < 0x40000000) {
        lVar9 = (longlong)(int)lVar9 * 2;
        uVar11 = lVar9 + 0x11;
        if (uVar11 <= lVar9 + 2U) {
          uVar11 = 0xffffffffffffff0;
        }
        uStack_60 = 0x18002d3fd;
        lVar9 = -(uVar11 & 0xfffffffffffffff0);
        pOVar1 = (OLECHAR *)((longlong)&local_28 + lVar9);
        puVar13 = auStack_58 + lVar9;
        if (pOVar1 != (OLECHAR *)0x0) {
          *(int *)((longlong)aiStack_30 + lVar9) = iVar12;
          *pOVar1 = L'\0';
          *(OLECHAR **)((longlong)&uStack_38 + lVar9) = pOVar1;
          *(undefined8 *)(auStack_58 + lVar9 + -8) = 0x18002d429;
          iVar12 = MultiByteToWideChar(0,0,param_1,-1,*(LPWSTR *)((longlong)&uStack_38 + lVar9),
                                       *(int *)((longlong)aiStack_30 + lVar9));
          psz = pOVar1;
          puVar13 = auStack_58 + lVar9;
          if (iVar12 == 0) {
            psz = pOVar14;
            puVar13 = auStack_58 + lVar9;
          }
        }
      }
    }
    *(undefined8 *)(puVar13 + -8) = 0x18002d43d;
    szDescription = SysAllocString(psz);
    pIVar6 = local_28;
    p_Var2 = local_28->lpVtbl->SetDescription;
    *(undefined8 *)(puVar13 + -8) = 0x18002d44b;
    (*p_Var2)(pIVar6,szDescription);
    pIVar6 = local_28;
    local_20 = (IErrorInfo *)0x0;
    p_Var3 = local_28->lpVtbl->QueryInterface;
    *(undefined8 *)(puVar13 + -8) = 0x18002d463;
    HVar8 = (*p_Var3)(pIVar6,(IID *)&DAT_180057ad8,&local_20);
    pIVar7 = local_20;
    if (-1 < HVar8) {
      *(undefined8 *)(puVar13 + -8) = 0x18002d473;
      SetErrorInfo(0,pIVar7);
      pIVar7 = local_20;
      p_Var4 = local_20->lpVtbl->Release;
      *(undefined8 *)(puVar13 + -8) = 0x18002d47d;
      (*p_Var4)(pIVar7);
    }
    pIVar6 = local_28;
    p_Var5 = local_28->lpVtbl->Release;
    *(undefined8 *)(puVar13 + -8) = 0x18002d487;
    (*p_Var5)(pIVar6);
  }
  *(undefined8 *)(puVar13 + -8) = 0x18002d493;
  return;
}

/* ---- FUNC 0002D4B0 GetGlobalPointer (110 bytes) ---- */

undefined8 GetGlobalPointer(char *param_1)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  char *local_res8 [4];
  
                    /* 0x2d4b0  362  GetGlobalPointer */
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_res8);
  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_res8,param_1);
    puVar2 = FUN_18002fe10((CMapStringToPtr *)&DAT_18007b760,local_res8[0]);
    if (puVar2 != (undefined8 *)0x0) {
      uVar1 = *puVar2;
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_res8);
      return uVar1;
    }
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)local_res8);
  return 0;
}

/* ---- FUNC 0002D520 MMBeginWaitCursor (50 bytes) ---- */

void MMBeginWaitCursor(void)

{
  AFX_MODULE_STATE *pAVar1;
  AFX_MAINTAIN_STATE2 local_18 [24];
  
                    /* 0x2d520  369  MMBeginWaitCursor */
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_18,DAT_18007b728);
  pAVar1 = AfxGetModuleState();
  CCmdTarget::BeginWaitCursor(*(CCmdTarget **)(pAVar1 + 8));
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_18);
  return;
}

/* ---- FUNC 0002D560 MMEndWaitCursor (50 bytes) ---- */

void MMEndWaitCursor(void)

{
  AFX_MODULE_STATE *pAVar1;
  AFX_MAINTAIN_STATE2 local_18 [24];
  
                    /* 0x2d560  387  MMEndWaitCursor */
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_18,DAT_18007b728);
  pAVar1 = AfxGetModuleState();
  CCmdTarget::EndWaitCursor(*(CCmdTarget **)(pAVar1 + 8));
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_18);
  return;
}

/* ---- FUNC 0002D5A0 MMGetPromptHelpFile (173 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool MMGetPromptHelpFile(longlong param_1,undefined8 param_2,short param_3)

{
  char cVar1;
  longlong lVar2;
  undefined1 auStack_68 [32];
  char *local_48;
  char local_40 [40];
  ulonglong local_18;
  
                    /* 0x2d5a0  393  MMGetPromptHelpFile */
  local_18 = DAT_1800791f8 ^ (ulonglong)auStack_68;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_48,"pmpt");
  _itoa((int)param_3,local_40,10);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_48,local_40);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator+=
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_48,".chm");
  lVar2 = param_1 - (longlong)local_48;
  do {
    cVar1 = *local_48;
    local_48[lVar2] = cVar1;
    local_48 = local_48 + 1;
  } while (cVar1 != '\0');
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_48);
  return param_1 != 0;
}

/* ---- FUNC 0002D650 MMPasteFormats (20 bytes) ---- */

byte MMPasteFormats(void)

{
  byte bVar1;
  BOOL BVar2;
  UINT format;
  UINT format_00;
  BOOL BVar3;
  byte bVar4;
  
                    /* 0x2d650  402  MMPasteFormats */
  BVar2 = OpenClipboard((HWND)0x0);
  if (BVar2 != 0) {
    format = RegisterClipboardFormatA("Link Source");
    format_00 = RegisterClipboardFormatA("Happ Node");
    BVar2 = IsClipboardFormatAvailable(1);
    BVar3 = IsClipboardFormatAvailable(format);
    bVar4 = BVar2 != 0 | 2;
    if (BVar3 == 0) {
      bVar4 = BVar2 != 0;
    }
    BVar2 = IsClipboardFormatAvailable(format_00);
    CloseClipboard();
    bVar1 = bVar4 | 4;
    if (BVar2 == 0) {
      bVar1 = bVar4;
    }
    return bVar1;
  }
  return 0;
}

/* ---- FUNC 0002D664 FUN_18002d664 (125 bytes) ---- */

ulonglong FUN_18002d664(void)

{
  UINT format;
  UINT format_00;
  BOOL BVar1;
  ulonglong uVar2;
  undefined8 unaff_RBP;
  ulonglong uVar3;
  
  format = RegisterClipboardFormatA("Link Source");
  format_00 = RegisterClipboardFormatA("Happ Node");
  BVar1 = IsClipboardFormatAvailable((int)unaff_RBP + 1);
  uVar2 = CONCAT71((int7)((ulonglong)unaff_RBP >> 8),BVar1 != 0);
  BVar1 = IsClipboardFormatAvailable(format);
  uVar3 = (ulonglong)((uint)uVar2 | 2);
  if (BVar1 == 0) {
    uVar3 = uVar2 & 0xffffffff;
  }
  BVar1 = IsClipboardFormatAvailable(format_00);
  CloseClipboard();
  uVar2 = (ulonglong)((uint)uVar3 | 4);
  if (BVar1 == 0) {
    uVar2 = uVar3;
  }
  return uVar2;
}

/* ---- FUNC 0002D6E1 FUN_18002d6e1 (8 bytes) ---- */

undefined4 FUN_18002d6e1(void)

{
  undefined4 unaff_EBP;
  
  return unaff_EBP;
}

/* ---- FUNC 0002D6F0 MMRestoreWaitCursor (56 bytes) ---- */

void MMRestoreWaitCursor(void)

{
  AFX_MODULE_STATE *pAVar1;
  AFX_MAINTAIN_STATE2 local_18 [24];
  
                    /* 0x2d6f0  404  MMRestoreWaitCursor */
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_18,DAT_18007b728);
  pAVar1 = AfxGetModuleState();
  (**(code **)(**(longlong **)(pAVar1 + 8) + 0x180))(*(longlong **)(pAVar1 + 8),0);
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_18);
  return;
}

/* ---- FUNC 0002D730 MMStructInitExtDLL (54 bytes) ---- */

void MMStructInitExtDLL(void)

{
  CDynLinkLibrary *this;
  
                    /* 0x2d730  413  MMStructInitExtDLL */
  this = operator_new(0x80);
  if (this != (CDynLinkLibrary *)0x0) {
    CDynLinkLibrary::CDynLinkLibrary(this,(AFX_EXTENSION_MODULE *)&DAT_18007b700,0);
  }
  DAT_18007b728 = AfxGetModuleState();
  return;
}

/* ---- FUNC 0002D770 PostMainWndMessage (297 bytes) ---- */

undefined8 PostMainWndMessage(undefined4 param_1,undefined8 param_2,undefined8 param_3)

{
  LPSTREAM pStm;
  DWORD DVar1;
  undefined8 local_res20;
  longlong *local_18 [2];
  
                    /* 0x2d770  421  PostMainWndMessage */
  local_res20 = 0;
  if (DAT_18007b798 == (longlong *)0x0) {
    return 0;
  }
  DVar1 = GetCurrentThreadId();
  pStm = DAT_18007b7a0;
  if ((DVar1 != DAT_180072200) && (DAT_180072200 != 0xffffffff)) {
    if (DAT_18007b7a0 == (LPSTREAM)0x0) {
      local_res20 = 1;
    }
    else {
      local_18[0] = (longlong *)0x0;
      (*DAT_18007b7a0->lpVtbl->Seek)(DAT_18007b7a0,(LARGE_INTEGER)0x0,0,(ULARGE_INTEGER *)0x0);
      CoUnmarshalInterface(pStm,(IID *)&DAT_1800561c0,local_18);
      if (local_18[0] != (longlong *)0x0) {
        (**(code **)(*local_18[0] + 0x28))(local_18[0],param_1,param_2,param_3,&local_res20);
        (**(code **)(*local_18[0] + 0x10))();
      }
    }
    return local_res20;
  }
  (**(code **)(*DAT_18007b798 + 0x28))(DAT_18007b798,param_1,param_2,param_3,&local_res20);
  return local_res20;
}

/* ---- FUNC 0002D7C0 FUN_18002d7c0 (137 bytes) ---- */

undefined8 FUN_18002d7c0(void)

{
  LPSTREAM pStm;
  undefined4 unaff_R14D;
  longlong *plStack0000000000000030;
  undefined8 in_stack_00000068;
  
  pStm = DAT_18007b7a0;
  if (DAT_18007b7a0 == (LPSTREAM)0x0) {
    in_stack_00000068 = 1;
  }
  else {
    plStack0000000000000030 = (longlong *)0x0;
    (*DAT_18007b7a0->lpVtbl->Seek)(DAT_18007b7a0,(LARGE_INTEGER)0x0,0,(ULARGE_INTEGER *)0x0);
    CoUnmarshalInterface(pStm,(IID *)&DAT_1800561c0,&stack0x00000030);
    if (plStack0000000000000030 != (longlong *)0x0) {
      (**(code **)(*plStack0000000000000030 + 0x28))(plStack0000000000000030,unaff_R14D);
      (**(code **)(*plStack0000000000000030 + 0x10))();
    }
  }
  return in_stack_00000068;
}

/* ---- FUNC 0002D849 FUN_18002d849 (7 bytes) ---- */

undefined8 FUN_18002d849(void)

{
  return 1;
}

/* ---- FUNC 0002D850 FUN_18002d850 (54 bytes) ---- */

undefined8 FUN_18002d850(void)

{
  undefined4 unaff_R14D;
  undefined8 in_stack_00000068;
  
  (**(code **)(*DAT_18007b798 + 0x28))(DAT_18007b798,unaff_R14D);
  return in_stack_00000068;
}

/* ---- FUNC 0002D8A0 PostMainWndMessage2 (290 bytes) ---- */

undefined8 PostMainWndMessage2(undefined4 param_1,undefined8 param_2,undefined8 param_3)

{
  LPSTREAM pStm;
  DWORD DVar1;
  undefined8 local_res20;
  longlong *local_18 [2];
  
                    /* 0x2d8a0  422  PostMainWndMessage2 */
  local_res20 = 0;
  if (DAT_18007b798 == (longlong *)0x0) {
    return 0;
  }
  DVar1 = GetCurrentThreadId();
  pStm = DAT_18007b7a0;
  if ((DVar1 != DAT_180072200) && (DAT_180072200 != 0xffffffff)) {
    if (DAT_18007b7a0 != (LPSTREAM)0x0) {
      local_18[0] = (longlong *)0x0;
      (*DAT_18007b7a0->lpVtbl->Seek)(DAT_18007b7a0,(LARGE_INTEGER)0x0,0,(ULARGE_INTEGER *)0x0);
      CoUnmarshalInterface(pStm,(IID *)&DAT_1800561c0,local_18);
      if (local_18[0] != (longlong *)0x0) {
        (**(code **)(*local_18[0] + 0x28))(local_18[0],param_1,param_2,param_3,&local_res20);
        (**(code **)(*local_18[0] + 0x10))();
      }
    }
    return local_res20;
  }
  (**(code **)(*DAT_18007b798 + 0x28))(DAT_18007b798,param_1,param_2,param_3,&local_res20);
  return local_res20;
}

/* ---- FUNC 0002D8F0 FUN_18002d8f0 (137 bytes) ---- */

undefined8 FUN_18002d8f0(void)

{
  LPSTREAM pStm;
  undefined4 unaff_R14D;
  longlong *plStack0000000000000030;
  undefined8 in_stack_00000068;
  
  pStm = DAT_18007b7a0;
  if (DAT_18007b7a0 != (LPSTREAM)0x0) {
    plStack0000000000000030 = (longlong *)0x0;
    (*DAT_18007b7a0->lpVtbl->Seek)(DAT_18007b7a0,(LARGE_INTEGER)0x0,0,(ULARGE_INTEGER *)0x0);
    CoUnmarshalInterface(pStm,(IID *)&DAT_1800561c0,&stack0x00000030);
    if (plStack0000000000000030 != (longlong *)0x0) {
      (**(code **)(*plStack0000000000000030 + 0x28))(plStack0000000000000030,unaff_R14D);
      (**(code **)(*plStack0000000000000030 + 0x10))();
    }
  }
  return in_stack_00000068;
}

/* ---- FUNC 0002D979 FUN_18002d979 (54 bytes) ---- */

undefined8 FUN_18002d979(void)

{
  undefined4 unaff_R14D;
  undefined8 in_stack_00000068;
  
  (**(code **)(*DAT_18007b798 + 0x28))(DAT_18007b798,unaff_R14D);
  return in_stack_00000068;
}

/* ---- FUNC 0002D9D0 STchgsiz (75 bytes) ---- */

int STchgsiz(int param_1,undefined4 param_2)

{
  int iVar1;
  longlong *plVar2;
  
                    /* 0x2d9d0  474  STchgsiz */
  plVar2 = (longlong *)FUN_1800414e0(0x18007b738,param_1);
  if (plVar2 != (longlong *)0x0) {
    iVar1 = (**(code **)(*plVar2 + 0x30))(plVar2,param_2);
    return -(uint)(iVar1 != 0);
  }
  return -1;
}

/* ---- FUNC 0002DA20 STclsenm (22 bytes) ---- */

undefined8 STclsenm(longlong *param_1)

{
                    /* 0x2da20  475  STclsenm */
  if (param_1 != (longlong *)0x0) {
    (**(code **)(*param_1 + 0x10))();
  }
  return 0;
}

/* ---- FUNC 0002DA40 STclsstg (125 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 STclsstg(longlong param_1)

{
  undefined1 auStack_428 [32];
  undefined1 local_408 [1008];
  ulonglong local_18;
  
                    /* 0x2da40  476  STclsstg */
  local_18 = DAT_1800791f8 ^ (ulonglong)auStack_428;
  if (param_1 == 0) {
    FUN_180007de0(local_408,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\mmstruct.cpp",0x1d0);
    LogMessage(local_408,2,1);
  }
  FUN_1800419b0(0x18007b738,param_1);
  return 0;
}

/* ---- FUNC 0002DAC0 STclsstr (33 bytes) ---- */

int STclsstr(int param_1)

{
  undefined8 uVar1;
  
                    /* 0x2dac0  477  STclsstr */
  uVar1 = FUN_180041820(0x18007b738,param_1);
  return -(uint)((int)uVar1 != 0);
}

/* ---- FUNC 0002DAF0 STcmtstg (177 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong STcmtstg(longlong *param_1)

{
  int iVar1;
  ulonglong uVar2;
  undefined1 auStack_428 [32];
  undefined1 local_408 [1008];
  ulonglong local_18;
  
                    /* 0x2daf0  478  STcmtstg */
  local_18 = DAT_1800791f8 ^ (ulonglong)auStack_428;
  if (param_1 == (longlong *)0x0) {
    FUN_180007de0(local_408,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\mmstruct.cpp",0x1d8);
    LogMessage(local_408,2);
  }
  iVar1 = FUN_1800410e0(0x18007b738,(longlong)param_1,(char *)0x0);
  if (iVar1 < 1) {
    if (param_1 == (longlong *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = (**(code **)(*param_1 + 0x48))(param_1,0);
    }
  }
  else {
    uVar2 = FUN_180040e20(0x18007b738,iVar1,0);
    uVar2 = (ulonglong)-(uint)((int)uVar2 != 0);
  }
  return uVar2;
}

/* ---- FUNC 0002DBB0 STcmtstr (30 bytes) ---- */

int STcmtstr(int param_1,int param_2)

{
  ulonglong uVar1;
  
                    /* 0x2dbb0  479  STcmtstr */
  uVar1 = FUN_180040e20(0x18007b738,param_1,param_2);
  return -(uint)((int)uVar1 != 0);
}

/* ---- FUNC 0002DBD0 STcpystg (28 bytes) ---- */

void STcpystg(longlong *param_1,undefined8 param_2)

{
                    /* 0x2dbd0  480  STcpystg */
  (**(code **)(*param_1 + 0x38))(param_1,0,0,0,param_2);
  return;
}

/* ---- FUNC 0002DBF0 STcredoc (439 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 STcredoc(char *param_1,uint param_2,longlong *param_3)

{
  WCHAR *pWVar1;
  _func_5396 *p_Var2;
  IStorage *pIVar3;
  uint grfMode;
  int iVar4;
  HRESULT HVar5;
  undefined8 uVar6;
  longlong lVar7;
  ulonglong uVar9;
  undefined1 *puVar10;
  WCHAR *pwcsName;
  WCHAR *pWVar11;
  undefined8 uStack_480;
  undefined1 auStack_478 [32];
  undefined8 uStack_458;
  int aiStack_450 [6];
  IStorage *local_438 [2];
  undefined1 local_428 [1008];
  ulonglong local_38;
  longlong lVar8;
  
                    /* 0x2dbf0  481  STcredoc */
  puVar10 = auStack_478;
  local_38 = DAT_1800791f8 ^ (ulonglong)local_438;
  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {
    uStack_480 = 0x18002dc4b;
    FUN_180007de0(local_428,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\mmstruct.cpp",0x139);
    uStack_480 = 0x18002dc5e;
    LogMessage(local_428,2,1);
  }
  pWVar11 = (WCHAR *)0x0;
  local_438[0] = (IStorage *)0x0;
  *param_3 = 0;
  uStack_480 = 0x18002dc7b;
  uVar6 = FUN_180041680(0x18007b738,param_1,(longlong *)local_438);
  if ((int)uVar6 == 0) {
    uStack_480 = 0x18002dc8a;
    grfMode = FUN_18002ca60(param_2);
    uStack_480 = 0x18002dc9b;
    iVar4 = strcmp(param_1,"_unnamed.apw");
    if (iVar4 == 0) {
      grfMode = grfMode | 0x4000000;
    }
    puVar10 = auStack_478;
    pwcsName = pWVar11;
    if (param_1 != (char *)0x0) {
      lVar7 = -1;
      do {
        lVar8 = lVar7;
        lVar7 = lVar8 + 1;
      } while (param_1[lVar7] != '\0');
      iVar4 = (int)lVar8 + 2;
      puVar10 = auStack_478;
      if (iVar4 < 0x40000000) {
        lVar7 = (longlong)(int)lVar7 * 2;
        uVar9 = lVar7 + 0x11;
        if (uVar9 <= lVar7 + 2U) {
          uVar9 = 0xffffffffffffff0;
        }
        uStack_480 = 0x18002dced;
        lVar7 = -(uVar9 & 0xfffffffffffffff0);
        pWVar1 = (WCHAR *)((longlong)local_438 + lVar7);
        puVar10 = auStack_478 + lVar7;
        if (pWVar1 != (WCHAR *)0x0) {
          *(int *)((longlong)aiStack_450 + lVar7) = iVar4;
          *pWVar1 = L'\0';
          *(WCHAR **)((longlong)&uStack_458 + lVar7) = pWVar1;
          *(undefined8 *)(auStack_478 + lVar7 + -8) = 0x18002dd1a;
          iVar4 = MultiByteToWideChar(0,0,param_1,-1,*(LPWSTR *)((longlong)&uStack_458 + lVar7),
                                      *(int *)((longlong)aiStack_450 + lVar7));
          puVar10 = auStack_478 + lVar7;
          pwcsName = pWVar1;
          if (iVar4 == 0) {
            puVar10 = auStack_478 + lVar7;
            pwcsName = pWVar11;
          }
        }
      }
    }
    *(undefined8 *)(puVar10 + -8) = 0x18002dd37;
    HVar5 = StgCreateDocfile(pwcsName,grfMode,0,local_438);
    pIVar3 = local_438[0];
    if (HVar5 == 0) {
      *(undefined8 *)(puVar10 + 0x30) = 0;
      *(uint *)(puVar10 + 0x28) = grfMode;
      *(undefined4 *)(puVar10 + 0x20) = 1;
      *(undefined8 *)(puVar10 + -8) = 0x18002dd62;
      uVar6 = FUN_180040a30((CPtrArray *)&DAT_18007b738,(longlong)pIVar3,0,param_1,
                            *(uint *)(puVar10 + 0x20),*(undefined4 *)(puVar10 + 0x28),
                            *(int **)(puVar10 + 0x30));
      pIVar3 = local_438[0];
      p_Var2 = local_438[0]->lpVtbl->Release;
      *(undefined8 *)(puVar10 + -8) = 0x18002dd6e;
      (*p_Var2)(pIVar3);
      if ((int)uVar6 == 0) goto LAB_18002dd76;
    }
    uVar6 = 0;
  }
  else {
LAB_18002dd76:
    uVar6 = 1;
    *param_3 = (longlong)local_438[0];
  }
  *(undefined8 *)(puVar10 + -8) = 0x18002dd91;
  return uVar6;
}

/* ---- FUNC 0002DDB0 STcrestg (22 bytes) ---- */

void STcrestg(longlong *param_1,char *param_2,uint param_3,undefined8 *param_4)

{
                    /* 0x2ddb0  482  STcrestg */
  STcrestg2(param_1,param_2,param_3,0,param_4);
  return;
}

/* ---- FUNC 0002DDD0 STcrestg2 (552 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
STcrestg2(longlong *param_1,char *param_2,uint param_3,undefined4 param_4,undefined8 *param_5)

{
  _func_5439 *p_Var1;
  code *pcVar2;
  _func_5396 *p_Var3;
  LPLOCKBYTES pIVar4;
  IStorage *pIVar5;
  uint uVar6;
  HRESULT HVar7;
  undefined4 uVar8;
  longlong lVar9;
  undefined8 uVar11;
  ulonglong uVar12;
  int iVar13;
  undefined1 *puVar14;
  undefined2 *puVar15;
  undefined8 uStack_490;
  undefined1 auStack_488 [32];
  undefined8 uStack_468;
  int aiStack_460 [6];
  LPLOCKBYTES local_448;
  IStorage *local_440;
  undefined1 local_438 [1008];
  ulonglong local_48;
  longlong lVar10;
  
                    /* 0x2ddd0  483  STcrestg2 */
  local_48 = DAT_1800791f8 ^ (ulonglong)&local_448;
  local_448 = (LPLOCKBYTES)CONCAT44(local_448._4_4_,param_4);
  uVar8 = 2;
  if (param_1 == (longlong *)0x0) {
    uStack_490 = 0x18002de3c;
    FUN_180007de0(local_438,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\mmstruct.cpp",399);
    uStack_490 = 0x18002de4e;
    LogMessage(local_438,2,1);
  }
  if ((param_2 == (char *)0x0) || (*param_2 == '\0')) {
    uStack_490 = 0x18002de75;
    FUN_180007de0(local_438,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\mmstruct.cpp",400);
    uStack_490 = 0x18002de88;
    LogMessage(local_438,2,1);
    puVar14 = auStack_488;
    if (param_2 != (char *)0x0) goto LAB_18002de8d;
LAB_18002df05:
    puVar15 = (undefined2 *)0x0;
  }
  else {
LAB_18002de8d:
    lVar9 = -1;
    do {
      lVar10 = lVar9;
      lVar9 = lVar10 + 1;
    } while (param_2[lVar9] != '\0');
    iVar13 = (int)lVar10 + 2;
    puVar14 = auStack_488;
    if (0x3fffffff < iVar13) goto LAB_18002df05;
    lVar9 = (longlong)(int)lVar9 * 2;
    uVar12 = lVar9 + 0x11;
    if (uVar12 <= lVar9 + 2U) {
      uVar12 = 0xffffffffffffff0;
    }
    uStack_490 = 0x18002ded1;
    lVar9 = -(uVar12 & 0xfffffffffffffff0);
    puVar14 = auStack_488 + lVar9;
    puVar15 = (undefined2 *)((longlong)&local_448 + lVar9);
    if (puVar15 == (undefined2 *)0x0) goto LAB_18002df05;
    *(int *)((longlong)aiStack_460 + lVar9) = iVar13;
    *puVar15 = 0;
    *(undefined2 **)((longlong)&uStack_468 + lVar9) = puVar15;
    *(undefined8 *)(auStack_488 + lVar9 + -8) = 0x18002defd;
    iVar13 = MultiByteToWideChar(0,0,param_2,-1,*(LPWSTR *)((longlong)&uStack_468 + lVar9),
                                 *(int *)((longlong)aiStack_460 + lVar9));
    puVar14 = auStack_488 + lVar9;
    if (iVar13 == 0) {
      puVar14 = auStack_488 + lVar9;
      puVar15 = (undefined2 *)0x0;
    }
  }
  local_440 = (IStorage *)0x0;
  *param_5 = 0;
  *(undefined8 *)(puVar14 + -8) = 0x18002df19;
  uVar6 = FUN_18002ca60(param_3);
  if ((int)local_448 == 0) {
    lVar9 = *param_1;
    *(IStorage ***)(puVar14 + 0x28) = &local_440;
    *(undefined4 *)(puVar14 + 0x20) = 0;
    pcVar2 = *(code **)(lVar9 + 0x28);
    *(undefined8 *)(puVar14 + -8) = 0x18002df87;
    iVar13 = (*pcVar2)(param_1,puVar15,uVar6,0);
    if (iVar13 == 0) goto LAB_18002df8b;
  }
  else {
    local_448 = (ILockBytes *)0x0;
    *(undefined8 *)(puVar14 + -8) = 0x18002df37;
    HVar7 = CreateILockBytesOnHGlobal((HGLOBAL)0x0,1,&local_448);
    pIVar4 = local_448;
    if (HVar7 == 0) {
      *(undefined8 *)(puVar14 + -8) = 0x18002df55;
      StgCreateDocfileOnILockBytes(pIVar4,uVar6 | 0x11000,0,&local_440);
      pIVar4 = local_448;
      p_Var1 = local_448->lpVtbl->Release;
      *(undefined8 *)(puVar14 + -8) = 0x18002df5f;
      (*p_Var1)(pIVar4);
      uVar8 = 10;
    }
LAB_18002df8b:
    pIVar5 = local_440;
    *(undefined8 *)(puVar14 + 0x30) = 0;
    *(uint *)(puVar14 + 0x28) = uVar6;
    *(undefined4 *)(puVar14 + 0x20) = uVar8;
    *(undefined8 *)(puVar14 + -8) = 0x18002dfb0;
    uVar11 = FUN_180040a30((CPtrArray *)&DAT_18007b738,(longlong)pIVar5,(longlong)param_1,param_2,
                           *(uint *)(puVar14 + 0x20),*(undefined4 *)(puVar14 + 0x28),
                           *(int **)(puVar14 + 0x30));
    pIVar5 = local_440;
    p_Var3 = local_440->lpVtbl->Release;
    *(undefined8 *)(puVar14 + -8) = 0x18002dfbc;
    (*p_Var3)(pIVar5);
    if ((int)uVar11 == 0) {
      uVar8 = 1;
      *param_5 = local_440;
      goto LAB_18002dfcf;
    }
  }
  uVar8 = 0;
LAB_18002dfcf:
  *(undefined8 *)(puVar14 + -8) = 0x18002dfde;
  return uVar8;
}

/* ---- FUNC 0002E000 STcrestr (22 bytes) ---- */

void STcrestr(longlong *param_1,LPCSTR param_2,uint param_3,undefined8 param_4)

{
                    /* 0x2e000  484  STcrestr */
  STcrestr2(param_1,param_2,param_3,0,param_4);
  return;
}

/* ---- FUNC 0002E020 STcrestr2 (491 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool STcrestr2(longlong *param_1,LPCSTR param_2,uint param_3,int param_4,undefined8 param_5)

{
  undefined2 *puVar1;
  code *pcVar2;
  _func_5369 *p_Var3;
  LPSTREAM pIVar4;
  uint uVar5;
  HRESULT HVar6;
  longlong lVar7;
  undefined8 uVar9;
  ulonglong uVar10;
  int iVar11;
  undefined2 *puVar12;
  undefined1 *puVar13;
  undefined2 *puVar14;
  undefined4 uVar15;
  bool bVar16;
  undefined8 uStack_490;
  undefined1 auStack_488 [32];
  undefined8 uStack_468;
  int aiStack_460 [6];
  LPSTREAM local_448;
  undefined8 local_440;
  undefined1 local_438 [1008];
  ulonglong local_48;
  longlong lVar8;
  
                    /* 0x2e020  485  STcrestr2 */
  local_48 = DAT_1800791f8 ^ (ulonglong)&local_448;
  local_440 = param_5;
  if (param_1 == (longlong *)0x0) {
    uStack_490 = 0x18002e089;
    FUN_180007de0(local_438,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\mmstruct.cpp",0x212);
    uStack_490 = 0x18002e09b;
    LogMessage(local_438,2,1);
  }
  puVar14 = (undefined2 *)0x0;
  local_448 = (IStream *)0x0;
  uStack_490 = 0x18002e0a8;
  uVar5 = FUN_18002ca60(param_3);
  uVar15 = 4;
  puVar12 = puVar14;
  puVar13 = auStack_488;
  if (param_2 != (LPCSTR)0x0) {
    lVar7 = -1;
    do {
      lVar8 = lVar7;
      lVar7 = lVar8 + 1;
    } while (param_2[lVar7] != '\0');
    iVar11 = (int)lVar8 + 2;
    puVar13 = auStack_488;
    if (iVar11 < 0x40000000) {
      lVar7 = (longlong)(int)lVar7 * 2;
      uVar10 = lVar7 + 0x11;
      if (uVar10 <= lVar7 + 2U) {
        uVar10 = 0xffffffffffffff0;
      }
      uStack_490 = 0x18002e0fd;
      lVar7 = -(uVar10 & 0xfffffffffffffff0);
      puVar1 = (undefined2 *)((longlong)&local_448 + lVar7);
      puVar13 = auStack_488 + lVar7;
      if (puVar1 != (undefined2 *)0x0) {
        *(int *)((longlong)aiStack_460 + lVar7) = iVar11;
        *puVar1 = 0;
        *(undefined2 **)((longlong)&uStack_468 + lVar7) = puVar1;
        *(undefined8 *)(auStack_488 + lVar7 + -8) = 0x18002e129;
        iVar11 = MultiByteToWideChar(0,0,param_2,-1,*(LPWSTR *)((longlong)&uStack_468 + lVar7),
                                     *(int *)((longlong)aiStack_460 + lVar7));
        puVar12 = puVar1;
        puVar13 = auStack_488 + lVar7;
        if (iVar11 == 0) {
          puVar12 = puVar14;
          puVar13 = auStack_488 + lVar7;
        }
      }
    }
  }
  if (param_1 == (longlong *)0x0) {
    if ((uVar5 >> 0xc & 1) == 0) {
      HVar6 = (int)local_448;
    }
    else {
      *(undefined8 *)(puVar13 + -8) = 0x18002e150;
      HVar6 = CreateStreamOnHGlobal((HGLOBAL)0x0,1,&local_448);
    }
  }
  else if ((param_4 == 0) || ((uVar5 & 0x1001) == 0)) {
    lVar7 = *param_1;
    *(LPSTREAM **)(puVar13 + 0x28) = &local_448;
    *(undefined4 *)(puVar13 + 0x20) = 0;
    pcVar2 = *(code **)(lVar7 + 0x18);
    *(undefined8 *)(puVar13 + -8) = 0x18002e19d;
    HVar6 = (*pcVar2)(param_1,puVar12,uVar5,0);
  }
  else {
    *(undefined8 *)(puVar13 + -8) = 0x18002e176;
    HVar6 = CreateStreamOnHGlobal((HGLOBAL)0x0,1,&local_448);
    uVar15 = 0xc;
  }
  pIVar4 = local_448;
  if (HVar6 == 0) {
    *(undefined8 *)(puVar13 + 0x30) = local_440;
    *(uint *)(puVar13 + 0x28) = uVar5;
    *(undefined4 *)(puVar13 + 0x20) = uVar15;
    *(undefined8 *)(puVar13 + -8) = 0x18002e1ca;
    uVar9 = FUN_180040a30((CPtrArray *)&DAT_18007b738,(longlong)pIVar4,(longlong)param_1,param_2,
                          *(uint *)(puVar13 + 0x20),*(undefined4 *)(puVar13 + 0x28),
                          *(int **)(puVar13 + 0x30));
    pIVar4 = local_448;
    p_Var3 = local_448->lpVtbl->Release;
    *(undefined8 *)(puVar13 + -8) = 0x18002e1d6;
    (*p_Var3)(pIVar4);
    bVar16 = (int)uVar9 == 0;
  }
  else {
    bVar16 = false;
  }
  *(undefined8 *)(puVar13 + -8) = 0x18002e1f1;
  return bVar16;
}

/* ---- FUNC 0002E210 STenmstr (313 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

char * STenmstr(longlong *param_1,longlong *param_2,uint param_3,undefined8 param_4)

{
  char *pcVar1;
  LPCWSTR lpWideCharStr;
  bool bVar2;
  int iVar3;
  uint uVar4;
  undefined7 extraout_var;
  longlong lVar5;
  ulonglong uVar7;
  char *pcVar8;
  char *pcVar9;
  undefined1 *puVar10;
  undefined8 uStack_f0;
  undefined1 auStack_e8 [32];
  undefined8 uStack_c8;
  int aiStack_c0 [2];
  undefined8 local_b8 [2];
  int local_a8 [4];
  LPCWSTR local_98 [10];
  ulonglong local_48;
  longlong lVar6;
  
                    /* 0x2e210  486  STenmstr */
  local_48 = DAT_1800791f8 ^ (ulonglong)local_a8;
  pcVar8 = (char *)0x0;
  pcVar9 = pcVar8;
  puVar10 = auStack_e8;
  if (param_2 != (longlong *)0x0) {
    uStack_f0 = 0x18002e260;
    iVar3 = (**(code **)(*param_2 + 0x18))(param_2,1,local_98,local_a8);
    lpWideCharStr = local_98[0];
    puVar10 = auStack_e8;
    if (((iVar3 == 0) && (puVar10 = auStack_e8, local_a8[0] != 0)) &&
       (pcVar9 = (char *)0x0, puVar10 = auStack_e8, local_98[0] != (LPCWSTR)0x0)) {
      uStack_f0 = 0x18002e285;
      uVar4 = FUN_18002ca60(param_3);
      lVar5 = -1;
      do {
        lVar6 = lVar5;
        lVar5 = lVar6 + 1;
      } while (lpWideCharStr[lVar5] != L'\0');
      iVar3 = (int)lVar6 + 2;
      pcVar9 = pcVar8;
      puVar10 = auStack_e8;
      if (iVar3 < 0x40000000) {
        lVar5 = (longlong)(int)lVar5 * 2;
        uVar7 = lVar5 + 0x11;
        if (uVar7 <= lVar5 + 2U) {
          uVar7 = 0xffffffffffffff0;
        }
        uStack_f0 = 0x18002e2ce;
        lVar5 = -(uVar7 & 0xfffffffffffffff0);
        pcVar1 = (char *)((longlong)local_a8 + lVar5);
        puVar10 = auStack_e8 + lVar5;
        if (pcVar1 != (char *)0x0) {
          *(undefined8 *)((longlong)local_b8 + lVar5 + 8) = 0;
          *(undefined8 *)((longlong)local_b8 + lVar5) = 0;
          *(int *)((longlong)aiStack_c0 + lVar5) = iVar3 * 2;
          *(char **)((longlong)&uStack_c8 + lVar5) = pcVar1;
          *pcVar1 = '\0';
          *(undefined8 *)(auStack_e8 + lVar5 + -8) = 0x18002e306;
          iVar3 = WideCharToMultiByte(0,0,lpWideCharStr,-1,*(LPSTR *)((longlong)&uStack_c8 + lVar5),
                                      *(int *)((longlong)aiStack_c0 + lVar5),
                                      *(LPCSTR *)((longlong)local_b8 + lVar5),
                                      *(LPBOOL *)((longlong)local_b8 + lVar5 + 8));
          pcVar9 = pcVar1;
          puVar10 = auStack_e8 + lVar5;
          if (iVar3 == 0) {
            pcVar9 = pcVar8;
            puVar10 = auStack_e8 + lVar5;
          }
        }
      }
      *(undefined8 *)(puVar10 + -8) = 0x18002e320;
      bVar2 = STopnstr(param_1,pcVar9,uVar4,param_4);
      pcVar9 = (char *)(CONCAT71(extraout_var,bVar2) & 0xffffffff);
      *(undefined8 *)(puVar10 + -8) = 0x18002e32c;
      CoTaskMemFree(local_98[0]);
    }
  }
  *(undefined8 *)(puVar10 + -8) = 0x18002e33a;
  return pcVar9;
}

/* ---- FUNC 0002E350 STerrbox (332 bytes) ---- */

void STerrbox(undefined8 *param_1,int param_2)

{
  longlong lVar1;
  LPCSTR lpMultiByteStr;
  char *lpMultiByteStr_00;
  CWinThread *pCVar2;
  int cbMultiByte;
  longlong lVar3;
  HWND pHVar4;
  int cbMultiByte_00;
  longlong lVar5;
  
                    /* 0x2e350  487  STerrbox */
  lVar3 = -1;
  do {
    lVar5 = lVar3 * 2;
    lVar3 = lVar3 + 1;
  } while (*(short *)(param_1[2] + 2 + lVar5) != 0);
  lVar5 = -1;
  do {
    lVar1 = lVar5 * 2;
    lVar5 = lVar5 + 1;
  } while (*(short *)(param_1[3] + 2 + lVar1) != 0);
  cbMultiByte_00 = (int)lVar5 * 2 + 2;
  lpMultiByteStr = malloc((longlong)cbMultiByte_00);
  cbMultiByte = (int)lVar3 * 2 + 2;
  lpMultiByteStr_00 = malloc((longlong)cbMultiByte);
  pHVar4 = (HWND)0x0;
  WideCharToMultiByte(0,0,(LPCWSTR)param_1[2],-1,lpMultiByteStr_00,cbMultiByte,(LPCSTR)0x0,
                      (LPBOOL)0x0);
  WideCharToMultiByte(0,0,(LPCWSTR)param_1[3],-1,lpMultiByteStr,cbMultiByte_00,(LPCSTR)0x0,
                      (LPBOOL)0x0);
  pCVar2 = AfxGetThread();
  if (pCVar2 != (CWinThread *)0x0) {
    lVar3 = (**(code **)(*(longlong *)pCVar2 + 0xf8))(pCVar2);
    if (lVar3 != 0) {
      pHVar4 = *(HWND *)(lVar3 + 0x40);
    }
  }
  MMMessageBox(pHVar4,lpMultiByteStr_00,lpMultiByteStr,0x2010,0xffffffff);
  free(lpMultiByteStr_00);
  free(lpMultiByteStr);
  if ((param_2 != 0) && ((code *)*param_1 != (code *)0x0)) {
    (*(code *)*param_1)(param_1);
  }
  return;
}

/* ---- FUNC 0002E4A0 STfprintf (105 bytes) ---- */

void STfprintf(int param_1,char *param_2,undefined8 param_3,undefined8 param_4)

{
  char *pcVar1;
  longlong lVar2;
  undefined8 local_res18;
  undefined8 local_res20;
  
                    /* 0x2e4a0  488  STfprintf */
  local_res18 = param_3;
  local_res20 = param_4;
  pcVar1 = strchr(param_2,0x25);
  if (pcVar1 == (char *)0x0) {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (param_2[lVar2] != '\0');
    STwrite(param_1,param_2,(int)lVar2);
    return;
  }
  FUN_18002f930(param_1,param_2,&local_res18);
  return;
}

/* ---- FUNC 0002E510 STfread (144 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong STfread(undefined8 param_1,ulonglong param_2,int param_3,int param_4)

{
  int iVar1;
  undefined1 auStack_428 [32];
  undefined1 local_408 [1008];
  ulonglong local_18;
  
                    /* 0x2e510  489  STfread */
  local_18 = DAT_1800791f8 ^ (ulonglong)auStack_428;
  iVar1 = STread(param_4,param_1,(int)param_2 * param_3);
  if ((ulonglong)(longlong)iVar1 % param_2 != 0) {
    FUN_180007de0(local_408,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\mmstruct.cpp",0x350);
    LogMessage(local_408,2,1);
  }
  return (ulonglong)(longlong)iVar1 / param_2;
}

/* ---- FUNC 0002E5A0 STfree (7 bytes) ---- */

void __cdecl STfree(void *_Memory)

{
                    /* WARNING: Could not recover jumptable at 0x00018002e5a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x2e5a0  490  STfree */
  free(_Memory);
  return;
}

/* ---- FUNC 0002E5B0 STgetc (65 bytes) ---- */

int STgetc(int param_1)

{
  int iVar1;
  int iVar2;
  char local_res10 [24];
  
                    /* 0x2e5b0  491  STgetc */
  iVar1 = DAT_18007b734;
  if (DAT_18007b734 != 0) {
    DAT_18007b734 = 0;
    return iVar1;
  }
  iVar1 = STread(param_1,local_res10,1);
  iVar2 = -1;
  if (iVar1 == 1) {
    iVar2 = (int)local_res10[0];
  }
  return iVar2;
}

/* ---- FUNC 0002E600 STgetenm (50 bytes) ---- */

bool STgetenm(longlong *param_1,undefined8 param_2)

{
  int iVar1;
  
                    /* 0x2e600  492  STgetenm */
  iVar1 = -0x7fffbffb;
  if (param_1 != (longlong *)0x0) {
    iVar1 = (**(code **)(*param_1 + 0x58))(param_1,0,0,0,param_2);
  }
  return iVar1 == 0;
}

/* ---- FUNC 0002E640 STgets (25 bytes) ---- */

undefined1 * STgets(undefined1 *param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  undefined1 *puVar3;
  
                    /* 0x2e640  493  STgets */
  if (param_2 == 0) {
    return (undefined1 *)0x0;
  }
  uVar2 = 0;
  if (DAT_18007b734 != 0) {
    *param_1 = (char)DAT_18007b734;
    DAT_18007b734 = 0;
    if (param_2 == 1) {
      return param_1;
    }
    uVar2 = 1;
  }
  iVar1 = STread(param_3,param_1 + uVar2,param_2 - uVar2);
  puVar3 = (undefined1 *)0x0;
  if (0 < iVar1) {
    puVar3 = param_1;
  }
  return puVar3;
}

/* ---- FUNC 0002E659 FUN_18002e659 (67 bytes) ---- */

undefined1 * FUN_18002e659(undefined8 param_1,int param_2,int param_3,int param_4)

{
  int in_EAX;
  int iVar1;
  undefined1 *unaff_RBX;
  uint uVar2;
  undefined1 *puVar3;
  
  uVar2 = 0;
  if (in_EAX != 0) {
    *unaff_RBX = (char)in_EAX;
    DAT_18007b734 = 0;
    if (param_2 == 1) {
      return unaff_RBX;
    }
    uVar2 = 1;
  }
  iVar1 = STread(param_4,unaff_RBX + uVar2,param_3 - uVar2);
  puVar3 = (undefined1 *)0x0;
  if (0 < iVar1) {
    puVar3 = unaff_RBX;
  }
  return puVar3;
}

/* ---- FUNC 0002E69C FUN_18002e69c (14 bytes) ---- */

void FUN_18002e69c(void)

{
  return;
}

/* ---- FUNC 0002E6AA FUN_18002e6aa (8 bytes) ---- */

undefined8 FUN_18002e6aa(void)

{
  return 0;
}

/* ---- FUNC 0002E6C0 STgetsiz (14 bytes) ---- */

void STgetsiz(int param_1)

{
                    /* 0x2e6c0  494  STgetsiz */
  FUN_180041290(0x18007b738,param_1);
  return;
}

/* ---- FUNC 0002E6D0 STgetstg (148 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int STgetstg(int param_1,longlong *param_2)

{
  undefined8 uVar1;
  undefined1 auStack_428 [32];
  undefined1 local_408 [1008];
  ulonglong local_18;
  
                    /* 0x2e6d0  495  STgetstg */
  local_18 = DAT_1800791f8 ^ (ulonglong)auStack_428;
  if (param_2 == (longlong *)0x0) {
    FUN_180007de0(local_408,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\mmstruct.cpp",0x1ba);
    LogMessage(local_408,2);
  }
  uVar1 = FUN_1800413a0(0x18007b738,param_1,(undefined4 *)0x0,param_2);
  return -(uint)((int)uVar1 != 1);
}

/* ---- FUNC 0002E770 STgetstg2 (37 bytes) ---- */

undefined8 STgetstg2(longlong param_1,int *param_2)

{
  int iVar1;
  
                    /* 0x2e770  496  STgetstg2 */
  iVar1 = FUN_1800410e0(0x18007b738,param_1,(char *)0x0);
  *param_2 = iVar1;
  return 0;
}

/* ---- FUNC 0002E7A0 STgetstr (148 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int STgetstr(int param_1,longlong *param_2)

{
  longlong lVar1;
  undefined1 auStack_428 [32];
  undefined1 local_408 [1008];
  ulonglong local_18;
  
                    /* 0x2e7a0  497  STgetstr */
  local_18 = DAT_1800791f8 ^ (ulonglong)auStack_428;
  if (param_2 == (longlong *)0x0) {
    FUN_180007de0(local_408,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\mmstruct.cpp",0x1c8);
    LogMessage(local_408,2,1);
  }
  lVar1 = FUN_1800414e0(0x18007b738,param_1);
  *param_2 = lVar1;
  return (lVar1 != 0) - 1;
}

/* ---- FUNC 0002E840 SThasstr (578 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

LPCSTR SThasstr(longlong *param_1,char *param_2,int *param_3,undefined4 *param_4)

{
  LPCSTR pCVar1;
  char cVar2;
  char cVar3;
  code *pcVar4;
  LPCWSTR pWVar5;
  longlong *plVar6;
  undefined1 *puVar7;
  int iVar8;
  longlong lVar9;
  char *pcVar11;
  ulonglong uVar12;
  LPCSTR lpString2;
  undefined1 *puVar13;
  LPCSTR pCVar14;
  undefined1 auStack_5e8 [32];
  longlong **local_5c8;
  longlong *local_5a8 [2];
  LPCWSTR local_598 [2];
  undefined8 local_588;
  CHAR local_548 [256];
  undefined1 local_448 [1008];
  ulonglong local_58;
  longlong lVar10;
  
                    /* 0x2e840  498  SThasstr */
  puVar13 = auStack_5e8;
  local_58 = DAT_1800791f8 ^ (ulonglong)local_5a8;
  if (param_1 == (longlong *)0x0) {
    FUN_180007de0(local_448,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\mmstruct.cpp",0xe4);
    LogMessage(local_448,2,1);
  }
  pCVar14 = (LPCSTR)0x0;
  local_5a8[0] = (longlong *)0x0;
  local_5c8 = local_5a8;
  iVar8 = (**(code **)(*param_1 + 0x58))(param_1,0,0,0);
  if (iVar8 == 0) {
    iVar8 = (**(code **)(*local_5a8[0] + 0x18))(local_5a8[0],1,local_598);
    pWVar5 = local_598[0];
    puVar13 = auStack_5e8;
    while (iVar8 == 0) {
      local_598[0] = pWVar5;
      if (pWVar5 != (LPCWSTR)0x0) {
        lVar9 = -1;
        do {
          lVar10 = lVar9;
          lVar9 = lVar10 + 1;
        } while (pWVar5[lVar9] != L'\0');
        iVar8 = (int)lVar10 + 2;
        lpString2 = pCVar14;
        puVar7 = puVar13;
        if (iVar8 < 0x40000000) {
          lVar9 = (longlong)(int)lVar9 * 2;
          uVar12 = lVar9 + 0x11;
          if (uVar12 <= lVar9 + 2U) {
            uVar12 = 0xffffffffffffff0;
          }
          *(undefined8 *)(puVar13 + -8) = 0x18002e94d;
          lVar9 = -(uVar12 & 0xfffffffffffffff0);
          pCVar1 = puVar13 + lVar9 + 0x40;
          puVar7 = puVar13 + lVar9;
          if (pCVar1 != (LPCSTR)0x0) {
            *(undefined8 *)(puVar13 + lVar9 + 0x38) = 0;
            *(undefined8 *)(puVar13 + lVar9 + 0x30) = 0;
            *(int *)(puVar13 + lVar9 + 0x28) = iVar8 * 2;
            *pCVar1 = '\0';
            *(LPCSTR *)(puVar13 + lVar9 + 0x20) = pCVar1;
            *(undefined8 *)(puVar13 + lVar9 + -8) = 0x18002e981;
            iVar8 = WideCharToMultiByte(0,0,pWVar5,-1,*(LPSTR *)(puVar13 + lVar9 + 0x20),
                                        *(int *)(puVar13 + lVar9 + 0x28),
                                        *(LPCSTR *)(puVar13 + lVar9 + 0x30),
                                        *(LPBOOL *)(puVar13 + lVar9 + 0x38));
            lpString2 = pCVar1;
            puVar7 = puVar13 + lVar9;
            if (iVar8 == 0) {
              lpString2 = pCVar14;
              puVar7 = puVar13 + lVar9;
            }
          }
        }
        puVar13 = puVar7;
        *(undefined8 *)(puVar13 + -8) = 0x18002e999;
        lstrcpyA(local_548,lpString2);
        pWVar5 = local_598[0];
        *(undefined8 *)(puVar13 + -8) = 0x18002e9a3;
        CoTaskMemFree(pWVar5);
        pcVar11 = local_548;
        lVar9 = (longlong)param_2 - (longlong)pcVar11;
        do {
          cVar2 = *pcVar11;
          cVar3 = pcVar11[lVar9];
          if (cVar2 != cVar3) break;
          pcVar11 = pcVar11 + 1;
        } while (cVar3 != '\0');
        if (cVar2 == cVar3) {
          if ((int)((ulonglong)local_588 >> 0x20) != 0) {
            *(undefined8 *)(puVar13 + -8) = 0x18002ea14;
            FUN_180007de0(local_448,"Assert failed in file %s line %d",
                          "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\mmstruct.cpp",0xf3);
            *(undefined8 *)(puVar13 + -8) = 0x18002ea2a;
            LogMessage(local_448,2,1);
          }
          pCVar14 = (LPCSTR)0x1;
          if (param_4 != (undefined4 *)0x0) {
            *param_4 = (int)local_588;
          }
          break;
        }
      }
      plVar6 = local_5a8[0];
      pcVar4 = *(code **)(*local_5a8[0] + 0x18);
      *(undefined8 *)(puVar13 + -8) = 0x18002e9dc;
      iVar8 = (*pcVar4)(plVar6,1,local_598);
      pWVar5 = local_598[0];
    }
    pcVar4 = *(code **)(*local_5a8[0] + 0x10);
    *(undefined8 *)(puVar13 + -8) = 0x18002ea42;
    (*pcVar4)();
    if (param_3 != (int *)0x0) {
      *(undefined8 *)(puVar13 + -8) = 0x18002ea59;
      iVar8 = FUN_1800410e0(0x18007b738,(longlong)param_1,param_2);
      *param_3 = iVar8;
    }
  }
  else {
    pCVar14 = (LPCSTR)0x0;
  }
  *(undefined8 *)(puVar13 + -8) = 0x18002ea6e;
  return pCVar14;
}

/* ---- FUNC 0002EA90 STisdoc (202 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool STisdoc(LPCSTR param_1)

{
  HRESULT HVar1;
  longlong lVar2;
  ulonglong uVar4;
  int iVar5;
  undefined1 *puVar6;
  WCHAR *pwcsName;
  undefined8 uStack_50;
  undefined1 auStack_48 [32];
  undefined8 uStack_28;
  int aiStack_20 [2];
  ulonglong local_18 [2];
  longlong lVar3;
  
                    /* 0x2ea90  499  STisdoc */
  local_18[0] = DAT_1800791f8 ^ (ulonglong)local_18;
  puVar6 = auStack_48;
  if (param_1 != (LPCSTR)0x0) {
    lVar2 = -1;
    do {
      lVar3 = lVar2;
      lVar2 = lVar3 + 1;
    } while (param_1[lVar2] != '\0');
    iVar5 = (int)lVar3 + 2;
    puVar6 = auStack_48;
    if (iVar5 < 0x40000000) {
      lVar2 = (longlong)(int)lVar2 * 2;
      uVar4 = lVar2 + 0x11;
      if (uVar4 <= lVar2 + 2U) {
        uVar4 = 0xffffffffffffff0;
      }
      uStack_50 = 0x18002eafb;
      lVar2 = -(uVar4 & 0xfffffffffffffff0);
      puVar6 = auStack_48 + lVar2;
      pwcsName = (WCHAR *)((longlong)local_18 + lVar2);
      if (pwcsName != (WCHAR *)0x0) {
        *(int *)((longlong)aiStack_20 + lVar2) = iVar5;
        *pwcsName = L'\0';
        *(WCHAR **)((longlong)&uStack_28 + lVar2) = pwcsName;
        *(undefined8 *)(auStack_48 + lVar2 + -8) = 0x18002eb24;
        iVar5 = MultiByteToWideChar(0,0,param_1,-1,*(LPWSTR *)((longlong)&uStack_28 + lVar2),
                                    *(int *)((longlong)aiStack_20 + lVar2));
        puVar6 = auStack_48 + lVar2;
        if (iVar5 == 0) {
          puVar6 = auStack_48 + lVar2;
          pwcsName = (WCHAR *)0x0;
        }
        goto LAB_18002eb30;
      }
    }
  }
  pwcsName = (WCHAR *)0x0;
LAB_18002eb30:
  *(undefined8 *)(puVar6 + -8) = 0x18002eb39;
  HVar1 = StgIsStorageFile(pwcsName);
  *(undefined8 *)(puVar6 + -8) = 0x18002eb4c;
  return HVar1 == 0;
}

/* ---- FUNC 0002EB60 STlseek (118 bytes) ---- */

undefined4 STlseek(int param_1,undefined4 param_2,int param_3)

{
  longlong lVar1;
  int iVar2;
  longlong *plVar3;
  ulonglong uVar4;
  undefined4 local_18;
  int local_14;
  
                    /* 0x2eb60  500  STlseek */
  plVar3 = (longlong *)FUN_1800414e0(0x18007b738,param_1);
  if (plVar3 != (longlong *)0x0) {
    lVar1 = *plVar3;
    uVar4 = FUN_18002c8a0(param_3);
    iVar2 = (**(code **)(lVar1 + 0x28))(plVar3,param_2,uVar4 & 0xffffffff,&local_18);
    if ((iVar2 == 0) && (local_14 == 0)) {
      return local_18;
    }
  }
  return 0xffffffff;
}

/* ---- FUNC 0002EBE0 STlstdir (236 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

HANDLE STlstdir(LPCSTR param_1,longlong param_2,HANDLE param_3,int param_4)

{
  char cVar1;
  longlong lVar2;
  BOOL BVar3;
  ulonglong uVar4;
  CHAR *pCVar6;
  undefined1 auStack_188 [32];
  _WIN32_FIND_DATAA local_168;
  ulonglong local_28;
  ulonglong uVar5;
  
                    /* 0x2ebe0  501  STlstdir */
  local_28 = DAT_1800791f8 ^ (ulonglong)auStack_188;
  if (param_3 == (HANDLE)0x0) {
    param_3 = FindFirstFileA(param_1,&local_168);
    if (param_3 == (HANDLE)0xffffffffffffffff) {
      return (HANDLE)0x0;
    }
  }
  else {
    BVar3 = FindNextFileA(param_3,&local_168);
    if (BVar3 == 0) {
      FindClose(param_3);
      return (HANDLE)0x0;
    }
  }
  if ((local_168.cAlternateFileName[0] != '\0') && (0 < param_4)) {
    uVar5 = 0xffffffffffffffff;
    do {
      uVar4 = uVar5 + 1;
      lVar2 = uVar5 + 1;
      uVar5 = uVar4;
    } while (local_168.cFileName[lVar2] != '\0');
    if ((ulonglong)(longlong)param_4 < uVar4) {
      pCVar6 = local_168.cAlternateFileName;
      do {
        cVar1 = *pCVar6;
        pCVar6[param_2 - (longlong)local_168.cAlternateFileName] = cVar1;
        pCVar6 = pCVar6 + 1;
      } while (cVar1 != '\0');
      return param_3;
    }
  }
  pCVar6 = local_168.cFileName;
  do {
    cVar1 = *pCVar6;
    pCVar6[param_2 - (longlong)local_168.cFileName] = cVar1;
    pCVar6 = pCVar6 + 1;
  } while (cVar1 != '\0');
  return param_3;
}

/* ---- FUNC 0002ECD0 STmalloc (7 bytes) ---- */

void * __cdecl STmalloc(size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018002ecd0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x2ecd0  502  STmalloc */
  pvVar1 = malloc(_Size);
  return pvVar1;
}

/* ---- FUNC 0002ECE0 STmsgbox (16 bytes) ---- */

void STmsgbox(char *param_1,LPCSTR param_2,uint param_3)

{
                    /* 0x2ece0  503  STmsgbox */
  STmsgbox2((HWND)0x0,param_1,param_2,param_3);
  return;
}

/* ---- FUNC 0002ECF0 STmsgbox2 (143 bytes) ---- */

int STmsgbox2(HWND param_1,char *param_2,LPCSTR param_3,uint param_4)

{
  int iVar1;
  AFX_MAINTAIN_STATE2 local_18 [16];
  
                    /* 0x2ecf0  504  STmsgbox2 */
  if (DAT_18007b728 == (AFX_MODULE_STATE *)0x0) {
    iVar1 = 1;
  }
  else {
    AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_18,DAT_18007b728);
    if (param_1 == (HWND)0x0) {
      iVar1 = MMAfxMessageBox(param_2,param_4,-1,0);
    }
    else {
      iVar1 = MMMessageBox(param_1,param_2,param_3,param_4,0xffffffff);
    }
    AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_18);
  }
  return iVar1;
}

/* ---- FUNC 0002ED80 STmsgbox_Format (202 bytes) ---- */

int STmsgbox_Format(DWORD param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  CWinThread *pCVar2;
  longlong lVar3;
  HWND pHVar4;
  undefined8 local_res10;
  undefined8 local_res18;
  undefined8 local_res20;
  va_list local_28;
  char *local_20;
  AFX_MAINTAIN_STATE2 local_18 [16];
  
                    /* 0x2ed80  505  STmsgbox_Format */
  local_res10 = param_2;
  local_res18 = param_3;
  local_res20 = param_4;
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_18,DAT_18007b728);
  local_28 = (va_list)&local_res10;
  pHVar4 = (HWND)0x0;
  FormatMessageA(0x1100,(LPCVOID)0x0,param_1,0x400,(LPSTR)&local_20,0,&local_28);
  local_28 = (va_list)0x0;
  pCVar2 = AfxGetThread();
  if (pCVar2 != (CWinThread *)0x0) {
    lVar3 = (**(code **)(*(longlong *)pCVar2 + 0xf8))(pCVar2);
    if (lVar3 != 0) {
      pHVar4 = *(HWND *)(lVar3 + 0x40);
    }
  }
  iVar1 = MMMessageBox(pHVar4,local_20,"Error",0x40,0xffffffff);
  LocalFree(local_20);
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_18);
  return iVar1;
}

/* ---- FUNC 0002EE50 STopndoc (474 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 STopndoc(char *param_1,uint param_2,undefined8 *param_3)

{
  code *pcVar1;
  longlong *plVar2;
  uint grfMode;
  HRESULT HVar3;
  longlong lVar4;
  undefined8 uVar6;
  ulonglong uVar7;
  int iVar8;
  undefined1 *puVar9;
  WCHAR *pwcsName;
  undefined8 uStack_480;
  undefined1 auStack_478 [32];
  undefined8 uStack_458;
  int aiStack_450 [6];
  longlong *local_438 [2];
  undefined1 local_428 [1008];
  ulonglong local_38;
  longlong lVar5;
  
                    /* 0x2ee50  506  STopndoc */
  local_38 = DAT_1800791f8 ^ (ulonglong)local_438;
  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {
    uStack_480 = 0x18002eeac;
    FUN_180007de0(local_428,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\mmstruct.cpp",0x10e);
    uStack_480 = 0x18002eebf;
    LogMessage(local_428,2,1);
    puVar9 = auStack_478;
    if (param_1 != (char *)0x0) goto LAB_18002eec4;
LAB_18002ef41:
    pwcsName = (WCHAR *)0x0;
  }
  else {
LAB_18002eec4:
    lVar4 = -1;
    do {
      lVar5 = lVar4;
      lVar4 = lVar5 + 1;
    } while (param_1[lVar4] != '\0');
    iVar8 = (int)lVar5 + 2;
    puVar9 = auStack_478;
    if (0x3fffffff < iVar8) goto LAB_18002ef41;
    lVar4 = (longlong)(int)lVar4 * 2;
    uVar7 = lVar4 + 0x11;
    if (uVar7 <= lVar4 + 2U) {
      uVar7 = 0xffffffffffffff0;
    }
    uStack_480 = 0x18002ef0d;
    lVar4 = -(uVar7 & 0xfffffffffffffff0);
    puVar9 = auStack_478 + lVar4;
    pwcsName = (WCHAR *)((longlong)local_438 + lVar4);
    if (pwcsName == (WCHAR *)0x0) goto LAB_18002ef41;
    *(int *)((longlong)aiStack_450 + lVar4) = iVar8;
    *pwcsName = L'\0';
    *(WCHAR **)((longlong)&uStack_458 + lVar4) = pwcsName;
    *(undefined8 *)(auStack_478 + lVar4 + -8) = 0x18002ef39;
    iVar8 = MultiByteToWideChar(0,0,param_1,-1,*(LPWSTR *)((longlong)&uStack_458 + lVar4),
                                *(int *)((longlong)aiStack_450 + lVar4));
    puVar9 = auStack_478 + lVar4;
    if (iVar8 == 0) {
      puVar9 = auStack_478 + lVar4;
      pwcsName = (WCHAR *)0x0;
    }
  }
  local_438[0] = (longlong *)0x0;
  *param_3 = 0;
  *(undefined8 *)(puVar9 + -8) = 0x18002ef5f;
  uVar6 = FUN_180041680(0x18007b738,param_1,(longlong *)local_438);
  if ((int)uVar6 == 0) {
    *(undefined8 *)(puVar9 + -8) = 0x18002ef6f;
    grfMode = FUN_18002ca60(param_2);
    *(longlong ***)(puVar9 + 0x28) = local_438;
    *(undefined4 *)(puVar9 + 0x20) = 0;
    *(undefined8 *)(puVar9 + -8) = 0x18002ef90;
    HVar3 = StgOpenStorage(pwcsName,(IStorage *)0x0,grfMode,(SNB)0x0,*(DWORD *)(puVar9 + 0x20),
                           *(IStorage ***)(puVar9 + 0x28));
    if (HVar3 == 0) {
LAB_18002efbd:
      plVar2 = local_438[0];
      *(undefined8 *)(puVar9 + 0x30) = 0;
      *(uint *)(puVar9 + 0x28) = grfMode;
      *(undefined4 *)(puVar9 + 0x20) = 1;
      *(undefined8 *)(puVar9 + -8) = 0x18002efe5;
      uVar6 = FUN_180040a30((CPtrArray *)&DAT_18007b738,(longlong)plVar2,0,param_1,
                            *(uint *)(puVar9 + 0x20),*(undefined4 *)(puVar9 + 0x28),
                            *(int **)(puVar9 + 0x30));
      pcVar1 = *(code **)(*local_438[0] + 0x10);
      *(undefined8 *)(puVar9 + -8) = 0x18002eff1;
      (*pcVar1)();
      if ((int)uVar6 == 0) goto LAB_18002eff9;
    }
    else if ((grfMode & 2) != 0) {
      *(longlong ***)(puVar9 + 0x28) = local_438;
      *(undefined4 *)(puVar9 + 0x20) = 0;
      *(undefined8 *)(puVar9 + -8) = 0x18002efb9;
      HVar3 = StgOpenStorage(pwcsName,(IStorage *)0x0,0x20,(SNB)0x0,*(DWORD *)(puVar9 + 0x20),
                             *(IStorage ***)(puVar9 + 0x28));
      if (HVar3 == 0) goto LAB_18002efbd;
    }
    uVar6 = 0;
  }
  else {
LAB_18002eff9:
    uVar6 = 1;
    *param_3 = local_438[0];
  }
  *(undefined8 *)(puVar9 + -8) = 0x18002f014;
  return uVar6;
}

/* ---- FUNC 0002F030 STopnstg (22 bytes) ---- */

void STopnstg(longlong *param_1,char *param_2,uint param_3,undefined8 *param_4)

{
                    /* 0x2f030  507  STopnstg */
  STopnstg2(param_1,param_2,param_3,0,param_4);
  return;
}

/* ---- FUNC 0002F050 STopnstg2 (596 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 STopnstg2(longlong *param_1,char *param_2,uint param_3,int param_4,undefined8 *param_5)

{
  code *pcVar1;
  uint uVar2;
  longlong *plVar3;
  uint uVar4;
  uint uVar5;
  longlong lVar6;
  undefined8 uVar8;
  ulonglong uVar9;
  int iVar10;
  undefined1 *puVar11;
  wchar_t *pwVar12;
  undefined4 uVar13;
  undefined8 uStack_4e0;
  undefined1 auStack_4d8 [32];
  undefined8 uStack_4b8;
  int aiStack_4b0 [6];
  longlong *local_498;
  int local_490;
  undefined8 local_488;
  undefined8 uStack_480;
  undefined8 local_478;
  undefined8 uStack_470;
  undefined8 local_468;
  undefined8 uStack_460;
  undefined8 local_458;
  undefined8 uStack_450;
  undefined8 local_448;
  undefined8 uStack_440;
  undefined1 local_438 [1008];
  ulonglong local_48;
  longlong lVar7;
  
                    /* 0x2f050  508  STopnstg2 */
  local_48 = DAT_1800791f8 ^ (ulonglong)&local_498;
  local_490 = param_4;
  if (param_1 == (longlong *)0x0) {
    uStack_4e0 = 0x18002f0bb;
    FUN_180007de0(local_438,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\mmstruct.cpp",0x15e);
    uStack_4e0 = 0x18002f0cb;
    LogMessage(local_438,2,1);
  }
  if ((param_2 == (char *)0x0) || (*param_2 == '\0')) {
    uStack_4e0 = 0x18002f0f2;
    FUN_180007de0(local_438,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\mmstruct.cpp",0x15f);
    uStack_4e0 = 0x18002f104;
    LogMessage(local_438,2,1);
    puVar11 = auStack_4d8;
    if (param_2 != (char *)0x0) goto LAB_18002f109;
LAB_18002f181:
    pwVar12 = (wchar_t *)0x0;
  }
  else {
LAB_18002f109:
    lVar6 = -1;
    do {
      lVar7 = lVar6;
      lVar6 = lVar7 + 1;
    } while (param_2[lVar6] != '\0');
    iVar10 = (int)lVar7 + 2;
    puVar11 = auStack_4d8;
    if (0x3fffffff < iVar10) goto LAB_18002f181;
    lVar6 = (longlong)(int)lVar6 * 2;
    uVar9 = lVar6 + 0x11;
    if (uVar9 <= lVar6 + 2U) {
      uVar9 = 0xffffffffffffff0;
    }
    uStack_4e0 = 0x18002f14d;
    lVar6 = -(uVar9 & 0xfffffffffffffff0);
    puVar11 = auStack_4d8 + lVar6;
    pwVar12 = (wchar_t *)((longlong)&local_498 + lVar6);
    if (pwVar12 == (wchar_t *)0x0) goto LAB_18002f181;
    *(int *)((longlong)aiStack_4b0 + lVar6) = iVar10;
    *pwVar12 = L'\0';
    *(wchar_t **)((longlong)&uStack_4b8 + lVar6) = pwVar12;
    *(undefined8 *)(auStack_4d8 + lVar6 + -8) = 0x18002f179;
    iVar10 = MultiByteToWideChar(0,0,param_2,-1,*(LPWSTR *)((longlong)&uStack_4b8 + lVar6),
                                 *(int *)((longlong)aiStack_4b0 + lVar6));
    puVar11 = auStack_4d8 + lVar6;
    if (iVar10 == 0) {
      puVar11 = auStack_4d8 + lVar6;
      pwVar12 = (wchar_t *)0x0;
    }
  }
  local_498 = (longlong *)0x0;
  *param_5 = 0;
  *(undefined8 *)(puVar11 + -8) = 0x18002f195;
  uVar4 = FUN_18002ca60(param_3);
  uVar13 = 10;
  if (local_490 == 0) {
    uVar13 = 2;
  }
  *(undefined8 *)(puVar11 + -8) = 0x18002f1bd;
  uVar9 = ZStgOpenStorage(param_1,pwVar12,uVar4,(longlong)&local_498);
  iVar10 = (int)uVar9;
  if (iVar10 == -0x7ffcffff) {
    uVar5 = uVar4 | 1;
    uVar2 = uVar4 & 1;
    uVar4 = uVar4 & 0xfffffffe;
    if (uVar2 == 0) {
      uVar4 = uVar5;
    }
    *(undefined8 *)(puVar11 + -8) = 0x18002f1ea;
    uVar9 = ZStgOpenStorage(param_1,pwVar12,uVar4,(longlong)&local_498);
    iVar10 = (int)uVar9;
  }
  if (iVar10 == 0) {
LAB_18002f235:
    plVar3 = local_498;
    *(undefined8 *)(puVar11 + 0x30) = 0;
    *(uint *)(puVar11 + 0x28) = uVar4;
    *(undefined4 *)(puVar11 + 0x20) = uVar13;
    *(undefined8 *)(puVar11 + -8) = 0x18002f25a;
    uVar8 = FUN_180040a30((CPtrArray *)&DAT_18007b738,(longlong)plVar3,(longlong)param_1,param_2,
                          *(uint *)(puVar11 + 0x20),*(undefined4 *)(puVar11 + 0x28),
                          *(int **)(puVar11 + 0x30));
    pcVar1 = *(code **)(*local_498 + 0x10);
    *(undefined8 *)(puVar11 + -8) = 0x18002f266;
    (*pcVar1)();
    if ((int)uVar8 == 0) {
      uVar8 = 1;
      *param_5 = local_498;
      goto LAB_18002f27b;
    }
  }
  else {
    local_488 = 0;
    uStack_480 = 0;
    local_478 = 0;
    uStack_470 = 0;
    local_468 = 0;
    uStack_460 = 0;
    local_458 = 0;
    uStack_450 = 0;
    local_448 = 0;
    uStack_440 = 0;
    pcVar1 = *(code **)(*param_1 + 0x88);
    *(undefined8 *)(puVar11 + -8) = 0x18002f21b;
    iVar10 = (*pcVar1)(param_1,&local_488,1);
    if (iVar10 == 0) {
      *(undefined8 *)(puVar11 + -8) = 0x18002f231;
      uVar9 = ZStgOpenStorage(param_1,pwVar12,uVar4,(longlong)&local_498);
      if ((int)uVar9 == 0) goto LAB_18002f235;
    }
  }
  uVar8 = 0;
LAB_18002f27b:
  *(undefined8 *)(puVar11 + -8) = 0x18002f28a;
  return uVar8;
}

/* ---- FUNC 0002F2B0 STopnstr (447 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool STopnstr(longlong *param_1,char *param_2,uint param_3,undefined8 param_4)

{
  wchar_t *pwVar1;
  code *pcVar2;
  LARGE_INTEGER LVar3;
  uint uVar4;
  longlong lVar5;
  undefined8 uVar7;
  ulonglong uVar8;
  int iVar9;
  undefined1 *puVar10;
  wchar_t *pwVar11;
  wchar_t *pwVar12;
  bool bVar13;
  undefined8 uStack_4e0;
  undefined1 auStack_4d8 [32];
  undefined8 uStack_4b8;
  int aiStack_4b0 [6];
  LARGE_INTEGER local_498 [2];
  undefined8 local_488;
  undefined8 uStack_480;
  undefined8 local_478;
  undefined8 uStack_470;
  undefined8 local_468;
  undefined8 uStack_460;
  undefined8 local_458;
  undefined8 uStack_450;
  undefined8 local_448;
  undefined8 uStack_440;
  undefined1 local_438 [1008];
  ulonglong local_48;
  longlong lVar6;
  
                    /* 0x2f2b0  509  STopnstr */
  local_48 = DAT_1800791f8 ^ (ulonglong)local_498;
  if (param_1 == (longlong *)0x0) {
    uStack_4e0 = 0x18002f306;
    FUN_180007de0(local_438,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\mmstruct.cpp",0x1f0);
    uStack_4e0 = 0x18002f318;
    LogMessage(local_438,2,1);
  }
  pwVar11 = (wchar_t *)0x0;
  local_498[0].QuadPart = 0;
  uStack_4e0 = 0x18002f325;
  uVar4 = FUN_18002ca60(param_3);
  puVar10 = auStack_4d8;
  pwVar12 = pwVar11;
  if (param_2 != (char *)0x0) {
    lVar5 = -1;
    do {
      lVar6 = lVar5;
      lVar5 = lVar6 + 1;
    } while (param_2[lVar5] != '\0');
    iVar9 = (int)lVar6 + 2;
    puVar10 = auStack_4d8;
    if (iVar9 < 0x40000000) {
      lVar5 = (longlong)(int)lVar5 * 2;
      uVar8 = lVar5 + 0x11;
      if (uVar8 <= lVar5 + 2U) {
        uVar8 = 0xffffffffffffff0;
      }
      uStack_4e0 = 0x18002f370;
      lVar5 = -(uVar8 & 0xfffffffffffffff0);
      pwVar1 = (wchar_t *)((longlong)local_498 + lVar5);
      puVar10 = auStack_4d8 + lVar5;
      if (pwVar1 != (wchar_t *)0x0) {
        *(int *)((longlong)aiStack_4b0 + lVar5) = iVar9;
        *pwVar1 = L'\0';
        *(wchar_t **)((longlong)&uStack_4b8 + lVar5) = pwVar1;
        *(undefined8 *)(auStack_4d8 + lVar5 + -8) = 0x18002f39c;
        iVar9 = MultiByteToWideChar(0,0,param_2,-1,*(LPWSTR *)((longlong)&uStack_4b8 + lVar5),
                                    *(int *)((longlong)aiStack_4b0 + lVar5));
        puVar10 = auStack_4d8 + lVar5;
        pwVar12 = pwVar1;
        if (iVar9 == 0) {
          puVar10 = auStack_4d8 + lVar5;
          pwVar12 = pwVar11;
        }
      }
    }
  }
  if ((uVar4 & 0x10) == 0) {
    uVar4 = uVar4 & 0xffffff9f | 0x10;
  }
  *(undefined8 *)(puVar10 + -8) = 0x18002f3c4;
  uVar8 = ZStgOpenStream(param_1,pwVar12,uVar4,local_498);
  if ((int)uVar8 == 0) {
LAB_18002f413:
    LVar3 = local_498[0];
    *(undefined8 *)(puVar10 + 0x30) = param_4;
    *(uint *)(puVar10 + 0x28) = uVar4;
    *(undefined4 *)(puVar10 + 0x20) = 4;
    *(undefined8 *)(puVar10 + -8) = 0x18002f43a;
    uVar7 = FUN_180040a30((CPtrArray *)&DAT_18007b738,LVar3.QuadPart,(longlong)param_1,param_2,
                          *(uint *)(puVar10 + 0x20),*(undefined4 *)(puVar10 + 0x28),
                          *(int **)(puVar10 + 0x30));
    pcVar2 = *(code **)(*(longlong *)local_498[0] + 0x10);
    *(undefined8 *)(puVar10 + -8) = 0x18002f446;
    (*pcVar2)();
    bVar13 = (int)uVar7 == 0;
  }
  else {
    local_488 = 0;
    uStack_480 = 0;
    local_478 = 0;
    uStack_470 = 0;
    local_468 = 0;
    uStack_460 = 0;
    local_458 = 0;
    uStack_450 = 0;
    local_448 = 0;
    uStack_440 = 0;
    pcVar2 = *(code **)(*param_1 + 0x88);
    *(undefined8 *)(puVar10 + -8) = 0x18002f3f5;
    iVar9 = (*pcVar2)(param_1,&local_488,1);
    if (iVar9 == 0) {
      *(undefined8 *)(puVar10 + -8) = 0x18002f40b;
      uVar8 = ZStgOpenStream(param_1,pwVar12,uVar4,local_498);
      if ((int)uVar8 == 0) goto LAB_18002f413;
    }
    bVar13 = false;
  }
  *(undefined8 *)(puVar10 + -8) = 0x18002f45d;
  return bVar13;
}

/* ---- FUNC 0002F470 STread (80 bytes) ---- */

undefined4 STread(int param_1,undefined8 param_2,undefined4 param_3)

{
  int iVar1;
  longlong *plVar2;
  undefined4 local_res20 [2];
  
                    /* 0x2f470  510  STread */
  plVar2 = (longlong *)FUN_1800414e0(0x18007b738,param_1);
  if ((plVar2 != (longlong *)0x0) &&
     (iVar1 = (**(code **)(*plVar2 + 0x18))(plVar2,param_2,param_3,local_res20), iVar1 == 0)) {
    return local_res20[0];
  }
  return 0xffffffff;
}

/* ---- FUNC 0002F4C0 STrealloc (7 bytes) ---- */

void * __cdecl STrealloc(void *_Memory,size_t _NewSize)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018002f4c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x2f4c0  511  STrealloc */
  pvVar1 = realloc(_Memory,_NewSize);
  return pvVar1;
}

/* ---- FUNC 0002F4D0 STremstr (559 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

ulonglong STremstr(longlong *param_1,char *param_2,int param_3)

{
  undefined2 *puVar1;
  code *pcVar2;
  bool bVar3;
  longlong *plVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *pCVar7;
  longlong lVar8;
  int iVar10;
  undefined2 *puVar11;
  undefined1 *puVar12;
  undefined2 *puVar13;
  undefined2 *puVar14;
  undefined8 uStack_480;
  undefined1 auStack_478 [32];
  undefined8 uStack_458;
  int aiStack_450 [2];
  longlong *local_448;
  LPCSTR local_440;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_438 [16];
  undefined1 local_428 [1008];
  ulonglong local_38;
  longlong lVar9;
  
                    /* 0x2f4d0  512  STremstr */
  puVar12 = auStack_478;
  local_38 = DAT_1800791f8 ^ (ulonglong)&local_448;
  puVar14 = (undefined2 *)0x0;
  bVar3 = false;
  local_448 = param_1;
  if (param_1 == (longlong *)0x0) {
    if (param_3 == 0) {
      uStack_480 = 0x18002f52a;
      FUN_180007de0(local_428,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\mmstruct.cpp",0x267);
      uStack_480 = 0x18002f53b;
      LogMessage(local_428,2);
    }
    uStack_480 = 0x18002f550;
    uVar5 = FUN_1800413a0(0x18007b738,param_3,(undefined4 *)0x0,(longlong *)&local_448);
    if ((int)uVar5 == 0) {
      uVar6 = 0xffffffffffffffff;
      goto LAB_18002f6e2;
    }
    bVar3 = true;
  }
  uStack_480 = 0x18002f56f;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_440);
  if (param_2 == (char *)0x0) {
    if (param_3 == 0) {
      uStack_480 = 0x18002f595;
      FUN_180007de0(local_428,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\mmstruct.cpp",0x26f);
      uStack_480 = 0x18002f5a6;
      LogMessage(local_428,2,1);
    }
    uStack_480 = 0x18002f5b9;
    pCVar7 = FUN_180041590(0x18007b738,local_438,param_3);
    uStack_480 = 0x18002f5c6;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_440,
               (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)pCVar7);
    uStack_480 = 0x18002f5d0;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_438);
  }
  else {
    uStack_480 = 0x18002f5df;
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_440,param_2);
  }
  puVar13 = (undefined2 *)0xffffffffffffffff;
  if (param_3 == 0) {
LAB_18002f61d:
    puVar11 = puVar14;
    puVar12 = auStack_478;
    if (local_440 != (LPCSTR)0x0) {
      lVar8 = -1;
      do {
        lVar9 = lVar8;
        lVar8 = lVar9 + 1;
      } while (local_440[lVar8] != '\0');
      iVar10 = (int)lVar9 + 2;
      puVar12 = auStack_478;
      if (iVar10 < 0x40000000) {
        lVar8 = (longlong)(int)lVar8 * 2;
        uVar6 = lVar8 + 0x11;
        if (uVar6 <= lVar8 + 2U) {
          uVar6 = 0xffffffffffffff0;
        }
        uStack_480 = 0x18002f66d;
        lVar8 = -(uVar6 & 0xfffffffffffffff0);
        puVar1 = (undefined2 *)((longlong)&local_448 + lVar8);
        puVar12 = auStack_478 + lVar8;
        if (puVar1 != (undefined2 *)0x0) {
          *(int *)((longlong)aiStack_450 + lVar8) = iVar10;
          *puVar1 = 0;
          *(undefined2 **)((longlong)&uStack_458 + lVar8) = puVar1;
          *(undefined8 *)(auStack_478 + lVar8 + -8) = 0x18002f694;
          iVar10 = MultiByteToWideChar(0,0,local_440,-1,*(LPWSTR *)((longlong)&uStack_458 + lVar8),
                                       *(int *)((longlong)aiStack_450 + lVar8));
          puVar11 = puVar1;
          puVar12 = auStack_478 + lVar8;
          if (iVar10 == 0) {
            puVar11 = puVar14;
            puVar12 = auStack_478 + lVar8;
          }
        }
      }
    }
    plVar4 = local_448;
    pcVar2 = *(code **)(*local_448 + 0x60);
    *(undefined8 *)(puVar12 + -8) = 0x18002f6ac;
    iVar10 = (*pcVar2)(plVar4,puVar11);
    plVar4 = local_448;
    pcVar2 = *(code **)(*local_448 + 0x48);
    *(undefined8 *)(puVar12 + -8) = 0x18002f6bb;
    (*pcVar2)(plVar4,0);
    plVar4 = local_448;
    if (bVar3) {
      *(undefined8 *)(puVar12 + -8) = 0x18002f6cf;
      FUN_1800419b0(0x18007b738,(longlong)plVar4);
    }
    if (iVar10 == 0) {
      puVar13 = puVar14;
    }
  }
  else {
    uStack_480 = 0x18002f5fc;
    uVar5 = FUN_180041820(0x18007b738,param_3);
    if ((int)uVar5 == 0) goto LAB_18002f61d;
    puVar12 = auStack_478;
    if (bVar3) {
      uStack_480 = 0x18002f618;
      FUN_1800419b0(0x18007b738,(longlong)local_448);
      puVar12 = auStack_478;
    }
  }
  *(undefined8 *)(puVar12 + -8) = 0x18002f6e0;
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_440);
  uVar6 = (ulonglong)puVar13 & 0xffffffff;
LAB_18002f6e2:
  *(undefined8 *)(puVar12 + -8) = 0x18002f6f1;
  return uVar6;
}

/* ---- FUNC 0002F700 STreopen (6 bytes) ---- */

undefined8 STreopen(void)

{
                    /* 0x2f700  513  STreopen */
  return 0xffffffff;
}

/* ---- FUNC 0002F710 STsizstr (105 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 STsizstr(longlong *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_88 [32];
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
                    /* 0x2f710  514  STsizstr */
  local_18 = DAT_1800791f8 ^ (ulonglong)auStack_88;
  uVar2 = 0;
  if (param_1 != (longlong *)0x0) {
    local_68 = 0;
    uStack_60 = 0;
    local_58 = 0;
    uStack_50 = 0;
    local_48 = 0;
    uStack_40 = 0;
    local_38 = 0;
    uStack_30 = 0;
    local_28 = 0;
    uStack_20 = 0;
    iVar1 = (**(code **)(*param_1 + 0x60))(0,&local_68,1);
    uVar2 = 0;
    if (iVar1 == 0) {
      uVar2 = (undefined4)local_58;
    }
  }
  return uVar2;
}

/* ---- FUNC 0002F780 STstgflg (130 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint STstgflg(longlong *param_1)

{
  int iVar1;
  uint uVar2;
  undefined1 auStack_88 [32];
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
                    /* 0x2f780  515  STstgflg */
  local_18 = DAT_1800791f8 ^ (ulonglong)auStack_88;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  iVar1 = (**(code **)(*param_1 + 0x88))(0,&local_68,1);
  if (iVar1 == 0) {
    uVar2 = FUN_18002cac0((uint)local_38);
    return uVar2;
  }
  return 2;
}

/* ---- FUNC 0002F810 STtell (74 bytes) ---- */

undefined4 STtell(int param_1)

{
  int iVar1;
  longlong *plVar2;
  undefined4 local_res18;
  int local_res1c;
  
                    /* 0x2f810  516  STtell */
  plVar2 = (longlong *)FUN_1800414e0(0x18007b738,param_1);
  if (((plVar2 != (longlong *)0x0) &&
      (iVar1 = (**(code **)(*plVar2 + 0x28))(plVar2,0,0,&local_res18), iVar1 == 0)) &&
     (local_res1c == 0)) {
    return local_res18;
  }
  return 0xffffffff;
}

/* ---- FUNC 0002F860 STtrace (40 bytes) ---- */

void STtrace(char *param_1)

{
  CDumpContext local_18 [16];
  
                    /* 0x2f860  517  STtrace */
  CDumpContext::CDumpContext(local_18,(CFile *)0x0);
  CDumpContext::operator<<(local_18,param_1);
  return;
}

/* ---- FUNC 0002F890 STtraceV (136 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void STtraceV(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulonglong *puVar1;
  undefined8 local_res10;
  undefined8 local_res18;
  undefined8 local_res20;
  undefined1 auStack_258 [32];
  undefined8 local_238;
  undefined8 *local_230;
  CHAR local_228 [512];
  ulonglong local_28;
  
                    /* 0x2f890  518  STtraceV */
  local_28 = DAT_1800791f8 ^ (ulonglong)auStack_258;
  local_res10 = param_2;
  local_res18 = param_3;
  local_res20 = param_4;
  puVar1 = (ulonglong *)FUN_180007dc0();
  local_238 = 0;
  local_230 = &local_res10;
  __stdio_common_vsprintf(*puVar1 | 1,local_228,0x200,param_1);
  OutputDebugStringA(local_228);
  return;
}

/* ---- FUNC 0002F920 STungetc (9 bytes) ---- */

undefined4 STungetc(undefined4 param_1)

{
                    /* 0x2f920  520  STungetc */
  DAT_18007b734 = param_1;
  return param_1;
}

/* ---- FUNC 0002F930 FUN_18002f930 (213 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_18002f930(int param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  ulonglong *puVar2;
  undefined1 auStack_1448 [32];
  undefined8 local_1428;
  undefined8 local_1420;
  undefined1 local_1418 [1008];
  undefined1 local_1028 [4096];
  ulonglong local_28;
  undefined8 uStack_20;
  
  uStack_20 = 0x18002f93e;
  local_28 = DAT_1800791f8 ^ (ulonglong)auStack_1448;
  puVar2 = (ulonglong *)FUN_180007dc0();
  local_1428 = 0;
  local_1420 = param_3;
  iVar1 = __stdio_common_vsprintf(*puVar2 | 1,local_1028,0x1000,param_2);
  if (iVar1 < 0) {
    iVar1 = -1;
  }
  if (iVar1 == -1) {
    FUN_180007de0(local_1418,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\mmstruct.cpp",0x336);
    LogMessage(local_1418,2,1);
    iVar1 = 0x1000;
  }
  else if (iVar1 < 1) {
    return;
  }
  STwrite(param_1,local_1028,iVar1);
  return;
}

/* ---- FUNC 0002FA10 STwrite (80 bytes) ---- */

undefined4 STwrite(int param_1,undefined8 param_2,undefined4 param_3)

{
  int iVar1;
  longlong *plVar2;
  undefined4 local_res20 [2];
  
                    /* 0x2fa10  521  STwrite */
  plVar2 = (longlong *)FUN_1800414e0(0x18007b738,param_1);
  if ((plVar2 != (longlong *)0x0) &&
     (iVar1 = (**(code **)(*plVar2 + 0x20))(plVar2,param_2,param_3,local_res20), iVar1 == 0)) {
    return local_res20[0];
  }
  return 0xffffffff;
}

/* ---- FUNC 0002FA60 SendMainWndMessage (70 bytes) ---- */

undefined8 SendMainWndMessage(undefined4 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 local_res20;
  
                    /* 0x2fa60  522  SendMainWndMessage */
  local_res20 = 0;
  if (DAT_18007b798 != (longlong *)0x0) {
    (**(code **)(*DAT_18007b798 + 0x28))(DAT_18007b798,param_1,param_2,param_3,&local_res20);
    return local_res20;
  }
  return 0;
}

/* ---- FUNC 0002FAB0 SetBlockEOStatus (18 bytes) ---- */

void SetBlockEOStatus(char *param_1,int param_2)

{
                    /* 0x2fab0  523  SetBlockEOStatus */
  CApwnEOStatus::SetAt(&g_ApwnEOStatusMap,param_1,param_2);
  return;
}

/* ---- FUNC 0002FAD0 SetGlobalCharPointer (133 bytes) ---- */

undefined8 SetGlobalCharPointer(char *param_1,char *param_2,undefined4 param_3)

{
  undefined8 uVar1;
  char *local_res8;
  
                    /* 0x2fad0  524  SetGlobalCharPointer */
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8);
  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8,param_1)
    ;
    uVar1 = FUN_18002fe40((CMapStringToPtr *)&DAT_18007b760,local_res8,param_2,param_3,1);
    if ((int)uVar1 == 1) {
      uVar1 = 0;
      goto LAB_18002fb38;
    }
  }
  uVar1 = 0xffffffff;
LAB_18002fb38:
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8);
  return uVar1;
}

/* ---- FUNC 0002FB60 SetGlobalPointer (127 bytes) ---- */

undefined4 SetGlobalPointer(char *param_1,char *param_2,undefined4 param_3)

{
  undefined8 uVar1;
  undefined4 uVar2;
  char *local_res8;
  
                    /* 0x2fb60  525  SetGlobalPointer */
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8);
  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {
    ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8,param_1)
    ;
    uVar2 = 0;
    uVar1 = FUN_18002fe40((CMapStringToPtr *)&DAT_18007b760,local_res8,param_2,param_3,0);
    if ((int)uVar1 == 1) goto LAB_18002fbc2;
  }
  uVar2 = 0xffffffff;
LAB_18002fbc2:
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_res8);
  return uVar2;
}

/* ---- FUNC 0002FBE0 SetGlobalWinApp (252 bytes) ---- */

void SetGlobalWinApp(IUnknown *param_1)

{
  IUnknown *pUnk;
  LPSTREAM pStm;
  HRESULT HVar1;
  
                    /* 0x2fbe0  526  SetGlobalWinApp */
  pStm = DAT_18007b7a0;
  if (DAT_18007b798 != (IUnknown *)0x0) {
    if (DAT_18007b7a0 != (LPSTREAM)0x0) {
      (*DAT_18007b7a0->lpVtbl->Seek)(DAT_18007b7a0,(LARGE_INTEGER)0x0,0,(ULARGE_INTEGER *)0x0);
      CoReleaseMarshalData(pStm);
      (*pStm->lpVtbl->Release)(pStm);
    }
    DAT_18007b7a0 = (LPSTREAM)0x0;
    (*DAT_18007b798->lpVtbl->Release)(DAT_18007b798);
    DAT_18007b798 = (IUnknown *)0x0;
  }
  if (param_1 != (IUnknown *)0x0) {
    DAT_18007b798 = param_1;
    (*param_1->lpVtbl->AddRef)(param_1);
    DAT_180072200 = GetCurrentThreadId();
    pUnk = DAT_18007b798;
    HVar1 = CreateStreamOnHGlobal((HGLOBAL)0x0,1,&DAT_18007b7a0);
    if (-1 < HVar1) {
      HVar1 = CoMarshalInterface(DAT_18007b7a0,(IID *)&DAT_1800561c0,pUnk,3,(LPVOID)0x0,1);
      if (HVar1 < 0) {
        (*DAT_18007b7a0->lpVtbl->Release)(DAT_18007b7a0);
        DAT_18007b7a0 = (LPSTREAM)0x0;
      }
    }
  }
  return;
}

/* ---- FUNC 0002FCE0 FUN_18002fce0 (28 bytes) ---- */

CMapStringToPtr * FUN_18002fce0(CMapStringToPtr *param_1)

{
  CMapStringToPtr::CMapStringToPtr(param_1,10);
  return param_1;
}

/* ---- FUNC 0002FD00 FUN_18002fd00 (163 bytes) ---- */

void FUN_18002fd00(CMapStringToPtr *param_1)

{
  undefined8 *_Memory;
  __POSITION *local_res8;
  undefined8 *local_res10;
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> local_res18 [8];
  
  local_res8 = (__POSITION *)-(ulonglong)(*(longlong *)(param_1 + 0x18) != 0);
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res18);
  local_res10 = (undefined8 *)0x0;
  while (local_res8 != (__POSITION *)0x0) {
    CMapStringToPtr::GetNextAssoc(param_1,&local_res8,local_res18,&local_res10);
    _Memory = local_res10;
    if (local_res10 != (undefined8 *)0x0) {
      if ((*(int *)((longlong)local_res10 + 0xc) != 0) && ((void *)*local_res10 != (void *)0x0)) {
        free((void *)*local_res10);
      }
      free(_Memory);
    }
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(local_res18);
  CMapStringToPtr::~CMapStringToPtr(param_1);
  return;
}

/* ---- FUNC 0002FDB0 FUN_18002fdb0 (84 bytes) ---- */

void * FUN_18002fdb0(char *param_1)

{
  char cVar1;
  longlong lVar2;
  void *pvVar3;
  
  if (param_1 == (char *)0x0) {
    return (void *)0x0;
  }
  lVar2 = -1;
  do {
    lVar2 = lVar2 + 1;
  } while (param_1[lVar2] != '\0');
  pvVar3 = malloc((longlong)((int)lVar2 + 1));
  lVar2 = (longlong)pvVar3 - (longlong)param_1;
  do {
    cVar1 = *param_1;
    param_1[lVar2] = cVar1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  return pvVar3;
}

/* ---- FUNC 0002FE10 FUN_18002fe10 (45 bytes) ---- */

void * FUN_18002fe10(CMapStringToPtr *param_1,char *param_2)

{
  int iVar1;
  void *local_res8 [4];
  
  local_res8[0] = (void *)0x0;
  iVar1 = CMapStringToPtr::Lookup(param_1,param_2,local_res8);
  if ((iVar1 != 1) || (local_res8[0] == (void *)0x0)) {
    local_res8[0] = (void *)0x0;
  }
  return local_res8[0];
}

/* ---- FUNC 0002FE40 FUN_18002fe40 (214 bytes) ---- */

undefined8
FUN_18002fe40(CMapStringToPtr *param_1,char *param_2,char *param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  undefined8 *puVar2;
  void **ppvVar3;
  undefined8 uVar4;
  void *pvVar5;
  undefined8 *local_res8;
  
  local_res8 = (undefined8 *)0x0;
  iVar1 = CMapStringToPtr::Lookup(param_1,param_2,&local_res8);
  puVar2 = local_res8;
  if (iVar1 == 0) {
    puVar2 = malloc(0x10);
    *(undefined4 *)(puVar2 + 1) = param_4;
    *(int *)((longlong)puVar2 + 0xc) = param_5;
    if (param_5 != 0) {
      param_3 = FUN_18002fdb0(param_3);
    }
    *puVar2 = param_3;
    ppvVar3 = CMapStringToPtr::operator[](param_1,param_2);
    *ppvVar3 = puVar2;
    uVar4 = 1;
  }
  else if ((*(int *)(local_res8 + 1) == 0) && (*(int *)((longlong)local_res8 + 0xc) == param_5)) {
    if (*(int *)((longlong)local_res8 + 0xc) == 0) {
      *local_res8 = param_3;
    }
    else {
      if ((void *)*local_res8 != (void *)0x0) {
        free((void *)*local_res8);
        *puVar2 = 0;
      }
      if (param_3 != (char *)0x0) {
        pvVar5 = FUN_18002fdb0(param_3);
        *puVar2 = pvVar5;
        return 1;
      }
    }
    uVar4 = 1;
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}

/* ---- FUNC 0002FF20 FUN_18002ff20 (46 bytes) ---- */

undefined8 *
FUN_18002ff20(undefined8 *param_1,ulonglong param_2,undefined8 param_3,size_t param_4,
             longlong param_5,void *param_6,size_t param_7)

{
  size_t _Size;
  ulonglong uVar1;
  longlong lVar2;
  ulonglong uVar3;
  void *_Src;
  void *_Dst;
  ulonglong uVar4;
  ulonglong uVar5;
  void *pvVar6;
  
  lVar2 = param_1[2];
  uVar5 = 0x7fffffffffffffff;
  if (0x7fffffffffffffffU - lVar2 < param_2) {
                    /* WARNING: Subroutine does not return */
    FUN_18000ace0();
  }
  uVar3 = param_1[3];
  uVar4 = lVar2 + param_2 | 0xf;
  if (uVar4 < 0x8000000000000000) {
    if (0x7fffffffffffffff - (uVar3 >> 1) < uVar3) {
      _Dst = (void *)FUN_180007f10(0x8000000000000000);
    }
    else {
      uVar1 = (uVar3 >> 1) + uVar3;
      uVar5 = uVar4;
      if (uVar4 < uVar1) {
        uVar5 = uVar1;
      }
      uVar4 = uVar5 + 1;
      if (uVar4 < 0x1000) {
        if (uVar4 == 0) {
          _Dst = (void *)0x0;
        }
        else {
          _Dst = operator_new(uVar4);
        }
      }
      else {
        _Dst = (void *)FUN_180007f10(uVar4);
      }
    }
  }
  else {
    _Dst = (void *)FUN_180007f10(0x8000000000000000);
  }
  param_1[3] = uVar5;
  param_1[2] = lVar2 + param_2;
  pvVar6 = (void *)((longlong)_Dst + param_4);
  _Size = ((lVar2 - param_4) - param_5) + 1;
  if (uVar3 < 0x10) {
    memcpy(_Dst,param_1,param_4);
    memcpy(pvVar6,param_6,param_7);
    memcpy((void *)((longlong)pvVar6 + param_7),(void *)(param_4 + param_5 + (longlong)param_1),
           _Size);
  }
  else {
    _Src = (void *)*param_1;
    memcpy(_Dst,_Src,param_4);
    memcpy(pvVar6,param_6,param_7);
    memcpy((void *)((longlong)pvVar6 + param_7),(void *)((longlong)_Src + param_5 + param_4),_Size);
    pvVar6 = _Src;
    if ((0xfff < uVar3 + 1) &&
       (pvVar6 = *(void **)((longlong)_Src + -8),
       0x1f < (ulonglong)((longlong)_Src + (-8 - (longlong)pvVar6)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar6);
  }
  *param_1 = _Dst;
  return param_1;
}

/* ---- FUNC 0002FF4E FUN_18002ff4e (385 bytes) ---- */

void FUN_18002ff4e(longlong param_1,longlong param_2)

{
  size_t _Size;
  ulonglong uVar1;
  ulonglong uVar2;
  void *_Src;
  void *_Dst;
  ulonglong uVar3;
  ulonglong unaff_RBX;
  void *pvVar4;
  undefined8 *unaff_RDI;
  longlong unaff_R14;
  size_t unaff_R15;
  longlong in_stack_00000070;
  void *in_stack_00000078;
  size_t in_stack_00000080;
  
  uVar2 = *(ulonglong *)(param_1 + 0x18);
  uVar3 = unaff_R14 + param_2 | 0xf;
  if (unaff_RBX < uVar3) {
    _Dst = (void *)FUN_180007f10(0x8000000000000000);
  }
  else if (unaff_RBX - (uVar2 >> 1) < uVar2) {
    _Dst = (void *)FUN_180007f10(0x8000000000000000);
  }
  else {
    uVar1 = (uVar2 >> 1) + uVar2;
    unaff_RBX = uVar3;
    if (uVar3 < uVar1) {
      unaff_RBX = uVar1;
    }
    uVar3 = unaff_RBX + 1;
    if (uVar3 < 0x1000) {
      if (uVar3 == 0) {
        _Dst = (void *)0x0;
      }
      else {
        _Dst = operator_new(uVar3);
      }
    }
    else {
      _Dst = (void *)FUN_180007f10(uVar3);
    }
  }
  unaff_RDI[3] = unaff_RBX;
  unaff_RDI[2] = unaff_R14 + param_2;
  pvVar4 = (void *)((longlong)_Dst + unaff_R15);
  _Size = ((unaff_R14 - unaff_R15) - in_stack_00000070) + 1;
  if (uVar2 < 0x10) {
    memcpy(_Dst,unaff_RDI,unaff_R15);
    memcpy(pvVar4,in_stack_00000078,in_stack_00000080);
    memcpy((void *)((longlong)pvVar4 + in_stack_00000080),
           (void *)(unaff_R15 + in_stack_00000070 + (longlong)unaff_RDI),_Size);
  }
  else {
    _Src = (void *)*unaff_RDI;
    memcpy(_Dst,_Src,unaff_R15);
    memcpy(pvVar4,in_stack_00000078,in_stack_00000080);
    memcpy((void *)((longlong)pvVar4 + in_stack_00000080),
           (void *)((longlong)_Src + in_stack_00000070 + unaff_R15),_Size);
    pvVar4 = _Src;
    if ((0xfff < uVar2 + 1) &&
       (pvVar4 = *(void **)((longlong)_Src + -8),
       0x1f < (ulonglong)((longlong)_Src + (-8 - (longlong)pvVar4)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(pvVar4);
  }
  *unaff_RDI = _Dst;
  return;
}

/* ---- FUNC 000300CF thunk_FUN_18000ace0 (5 bytes) ---- */

void thunk_FUN_18000ace0(void)

{
                    /* WARNING: Subroutine does not return */
  FUN_18000ace0();
}

/* ---- FUNC 000300E0 GetAppRegistryKey (276 bytes) ---- */

/* struct HKEY__ * __ptr64 __cdecl GetAppRegistryKey(void) */

HKEY__ * __cdecl GetAppRegistryKey(void)

{
  LSTATUS LVar1;
  LPCSTR pCVar2;
  DWORD local_res8 [2];
  HKEY local_res10;
  HKEY local_res18;
  HKEY local_res20;
  
                    /* 0x300e0  91  ?GetAppRegistryKey@@YAPEAUHKEY__@@XZ */
  FUN_180031520();
  local_res20 = (HKEY__ *)0x0;
  local_res10 = (HKEY)0x0;
  local_res18 = (HKEY)0x0;
  LVar1 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000001,"SOFTWARE",0,0x2001f,&local_res10);
  if (LVar1 == 0) {
    pCVar2 = (LPCSTR)&DAT_180072208;
    if (0xf < DAT_180072220) {
      pCVar2 = DAT_180072208;
    }
    LVar1 = RegCreateKeyExA(local_res10,pCVar2,0,(LPSTR)0x0,0,0x2001f,(LPSECURITY_ATTRIBUTES)0x0,
                            &local_res18,local_res8);
    if (LVar1 == 0) {
      pCVar2 = (LPCSTR)&DAT_180072228;
      if (0xf < DAT_180072240) {
        pCVar2 = DAT_180072228;
      }
      RegCreateKeyExA(local_res18,pCVar2,0,(LPSTR)0x0,0,0x2001f,(LPSECURITY_ATTRIBUTES)0x0,
                      &local_res20,local_res8);
    }
  }
  if (local_res10 != (HKEY)0x0) {
    RegCloseKey(local_res10);
  }
  if (local_res18 != (HKEY)0x0) {
    RegCloseKey(local_res18);
  }
  return local_res20;
}

/* ---- FUNC 00030200 GetLMAppRegistryKey (276 bytes) ---- */

/* struct HKEY__ * __ptr64 __cdecl GetLMAppRegistryKey(void) */

HKEY__ * __cdecl GetLMAppRegistryKey(void)

{
  LSTATUS LVar1;
  LPCSTR pCVar2;
  DWORD local_res8 [2];
  HKEY local_res10;
  HKEY local_res18;
  HKEY local_res20;
  
                    /* 0x30200  100  ?GetLMAppRegistryKey@@YAPEAUHKEY__@@XZ */
  FUN_180031520();
  local_res20 = (HKEY__ *)0x0;
  local_res10 = (HKEY)0x0;
  local_res18 = (HKEY)0x0;
  LVar1 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000002,"SOFTWARE",0,0x20019,&local_res10);
  if (LVar1 == 0) {
    pCVar2 = (LPCSTR)&DAT_180072208;
    if (0xf < DAT_180072220) {
      pCVar2 = DAT_180072208;
    }
    LVar1 = RegCreateKeyExA(local_res10,pCVar2,0,(LPSTR)0x0,0,0x20019,(LPSECURITY_ATTRIBUTES)0x0,
                            &local_res18,local_res8);
    if (LVar1 == 0) {
      pCVar2 = (LPCSTR)&DAT_180072228;
      if (0xf < DAT_180072240) {
        pCVar2 = DAT_180072228;
      }
      RegCreateKeyExA(local_res18,pCVar2,0,(LPSTR)0x0,0,0x20019,(LPSECURITY_ATTRIBUTES)0x0,
                      &local_res20,local_res8);
    }
  }
  if (local_res10 != (HKEY)0x0) {
    RegCloseKey(local_res10);
  }
  if (local_res18 != (HKEY)0x0) {
    RegCloseKey(local_res18);
  }
  return local_res20;
}

/* ---- FUNC 00030320 GetLMProfileString (253 bytes) ---- */

/* char const * __ptr64 __cdecl GetLMProfileString(char const * __ptr64,char const * __ptr64,char
   const * __ptr64) */

char * __cdecl GetLMProfileString(char *param_1,char *param_2,char *param_3)

{
  LSTATUS LVar1;
  HKEY__ *hKey;
  char *pcVar2;
  LPBYTE lpData;
  longlong lVar3;
  DWORD local_res20 [2];
  DWORD local_28 [4];
  
                    /* 0x30320  101  ?GetLMProfileString@@YAPEBDPEBD00@Z */
  FUN_180031520();
  lpData = (LPBYTE)0x0;
  if (DAT_180072218 != 0) {
    hKey = GetLMSectionKey(param_1);
    if (hKey == (HKEY__ *)0x0) {
      if (param_3 == (char *)0x0) {
        param_3 = "";
      }
      pcVar2 = _strdup(param_3);
      return pcVar2;
    }
    local_28[0] = 0;
    local_res20[0] = 0;
    LVar1 = RegQueryValueExA(hKey,param_2,(LPDWORD)0x0,local_28,(LPBYTE)0x0,local_res20);
    if (LVar1 == 0) {
      lVar3 = (longlong)(int)local_res20[0];
      lpData = operator_new__((longlong)(int)(local_res20[0] + 1));
      lpData[lVar3] = '\0';
      LVar1 = RegQueryValueExA(hKey,param_2,(LPDWORD)0x0,local_28,lpData,local_res20);
    }
    RegCloseKey(hKey);
    if (LVar1 == 0) {
      return (char *)lpData;
    }
    if (param_3 != (char *)0x0) {
      pcVar2 = _strdup(param_3);
      return pcVar2;
    }
  }
  return (char *)0x0;
}

/* ---- FUNC 00030420 GetLMSectionKey (139 bytes) ---- */

/* struct HKEY__ * __ptr64 __cdecl GetLMSectionKey(char const * __ptr64) */

HKEY__ * __cdecl GetLMSectionKey(char *param_1)

{
  HKEY__ *hKey;
  DWORD local_res10 [2];
  HKEY local_res18 [2];
  
                    /* 0x30420  102  ?GetLMSectionKey@@YAPEAUHKEY__@@PEBD@Z */
  FUN_180031520();
  local_res18[0] = (HKEY__ *)0x0;
  hKey = GetLMAppRegistryKey();
  if (hKey == (HKEY__ *)0x0) {
    return (HKEY__ *)0x0;
  }
  RegCreateKeyExA(hKey,param_1,0,(LPSTR)0x0,0,0x20019,(LPSECURITY_ATTRIBUTES)0x0,local_res18,
                  local_res10);
  RegCloseKey(hKey);
  return local_res18[0];
}

/* ---- FUNC 000304B0 GetLMSystemProfileString (1002 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x000180030605) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xfffffffffffffe68 : 0x000180030635 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* char const * __ptr64 __cdecl GetLMSystemProfileString(char const * __ptr64,char const * __ptr64)
    */

char * __cdecl GetLMSystemProfileString(char *param_1,char *param_2)

{
  char ***pppcVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  LSTATUS LVar5;
  char ****ppppcVar6;
  longlong *plVar7;
  char *pcVar8;
  longlong lVar9;
  undefined8 *puVar10;
  char *****pppppcVar11;
  BYTE *_Src;
  undefined1 auStackY_1f8 [32];
  DWORD local_1c8 [2];
  HKEY local_1c0;
  char ****local_1b8;
  longlong lStack_1b0;
  longlong local_1a8;
  ulonglong uStack_1a0;
  undefined8 *local_198;
  undefined8 uStack_190;
  undefined8 local_188;
  ulonglong uStack_180;
  undefined8 *local_178;
  undefined8 uStack_170;
  undefined8 local_168;
  ulonglong uStack_160;
  BYTE local_158 [272];
  ulonglong local_48;
  
                    /* 0x304b0  103  ?GetLMSystemProfileString@@YAPEBDPEBD0@Z */
  local_48 = DAT_1800791f8 ^ (ulonglong)auStackY_1f8;
  FUN_180031520();
  local_1c0 = (HKEY)0x0;
  local_1c8[0] = 0x104;
  local_158[0] = '\0';
  local_1b8 = (char ****)0x0;
  lStack_1b0 = 0;
  local_1a8 = 0;
  uStack_1a0 = 0xf;
  ppppcVar6 = operator_new(0x20);
  uVar4 = s_SOFTWARE_AspenTech_APrSystem__1800567e8._8_8_;
  local_1a8 = 0x1d;
  uStack_1a0 = 0x1f;
  *ppppcVar6 = (char ***)s_SOFTWARE_AspenTech_APrSystem__1800567e8._0_8_;
  ppppcVar6[1] = (char ***)uVar4;
  ppppcVar6[2] = (char ***)s_SOFTWARE_AspenTech_APrSystem__1800567e8._16_8_;
  *(undefined4 *)(ppppcVar6 + 3) = s_SOFTWARE_AspenTech_APrSystem__1800567e8._24_4_;
  *(char *)((longlong)ppppcVar6 + 0x1c) = s_SOFTWARE_AspenTech_APrSystem__1800567e8[0x1c];
  *(char *)((longlong)ppppcVar6 + 0x1d) = '\0';
  local_198 = (undefined8 *)0x0;
  uStack_190 = 0;
  local_188 = 0;
  uStack_180 = 0;
  local_1b8 = ppppcVar6;
  local_198 = operator_new(0x30);
  uStack_180 = 0x2f;
  pppcVar1 = ppppcVar6[1];
  *local_198 = *ppppcVar6;
  local_198[1] = pppcVar1;
  local_198[2] = ppppcVar6[2];
  *(undefined4 *)(local_198 + 3) = *(undefined4 *)(ppppcVar6 + 3);
  *(char *)((longlong)local_198 + 0x1c) = *(char *)((longlong)ppppcVar6 + 0x1c);
  *(undefined4 *)((longlong)local_198 + 0x1d) = DAT_1800533c0;
  *(undefined1 *)((longlong)local_198 + 0x21) = 0;
  local_188 = 0x22;
  *(undefined2 *)((longlong)local_198 + 0x21) = 0x5c;
  local_178 = (undefined8 *)0x0;
  uStack_170 = 0;
  local_168 = 0;
  uStack_160 = 0;
  local_178 = local_198;
  uStack_170 = uStack_190;
  local_168 = local_188;
  uStack_160 = uStack_180;
  local_188 = 0;
  uStack_180 = 0xf;
                    /* WARNING: Ignoring partial resolution of indirect */
  local_198._0_1_ = 0;
  plVar7 = FUN_180029360((longlong *)&local_178,param_1);
  pppppcVar11 = (char *****)*plVar7;
  lVar9 = plVar7[1];
  lVar2 = plVar7[2];
  uVar3 = plVar7[3];
  plVar7[2] = 0;
  plVar7[3] = 0xf;
  *(undefined1 *)plVar7 = 0;
  if (0xf < uStack_1a0) {
    ppppcVar6 = local_1b8;
    if ((0xfff < uStack_1a0 + 1) &&
       (ppppcVar6 = (char ****)local_1b8[-1],
       (char *)0x1f < (char *)((longlong)local_1b8 + (-8 - (longlong)ppppcVar6)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(ppppcVar6);
  }
  local_1b8 = (char ****)pppppcVar11;
  lStack_1b0 = lVar9;
  local_1a8 = lVar2;
  uStack_1a0 = uVar3;
  if (0xf < uStack_160) {
    puVar10 = local_178;
    if ((0xfff < uStack_160 + 1) &&
       (puVar10 = (undefined8 *)local_178[-1],
       0x1f < (ulonglong)((longlong)local_178 + (-8 - (longlong)puVar10)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(puVar10);
  }
  local_168 = _DAT_180053820;
  uStack_160 = _UNK_180053828;
  local_178 = (undefined8 *)((ulonglong)local_178 & 0xffffffffffffff00);
  if (0xf < uStack_180) {
    puVar10 = local_198;
    if ((0xfff < uStack_180 + 1) &&
       (puVar10 = (undefined8 *)local_198[-1],
       0x1f < (ulonglong)((longlong)local_198 + (-8 - (longlong)puVar10)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    operator_delete(puVar10);
  }
  pppppcVar11 = &local_1b8;
  if (0xf < uStack_1a0) {
    pppppcVar11 = (char *****)local_1b8;
  }
  LVar5 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000002,(LPCSTR)pppppcVar11,0,0x20019,&local_1c0);
  if (LVar5 == 0) {
    LVar5 = RegQueryValueExA(local_1c0,param_2,(LPDWORD)0x0,(LPDWORD)0x0,local_158,local_1c8);
    RegCloseKey(local_1c0);
    _Src = local_158;
    if (LVar5 != 0) {
      _Src = "";
    }
    pcVar8 = _strdup((char *)_Src);
    if (uStack_1a0 < 0x10) {
      return pcVar8;
    }
    pppppcVar11 = (char *****)local_1b8;
    if (uStack_1a0 + 1 < 0x1000) goto LAB_1800307cf;
    pppppcVar11 = (char *****)local_1b8[-1];
    lVar9 = (longlong)local_1b8 - (longlong)pppppcVar11;
  }
  else {
    pcVar8 = _strdup("");
    if (uStack_1a0 < 0x10) {
      return pcVar8;
    }
    pppppcVar11 = (char *****)local_1b8;
    if (uStack_1a0 + 1 < 0x1000) goto LAB_1800307cf;
    pppppcVar11 = (char *****)local_1b8[-1];
    lVar9 = (longlong)local_1b8 - (longlong)pppppcVar11;
  }
  if (0x1f < lVar9 - 8U) {
                    /* WARNING: Subroutine does not return */
    _invalid_parameter_noinfo_noreturn();
  }
LAB_1800307cf:
  operator_delete(pppppcVar11);
  return pcVar8;
}

/* ---- FUNC 000308A0 GetProfileStringA (253 bytes) ---- */

/* char const * __ptr64 __cdecl GetProfileStringA(char const * __ptr64,char const * __ptr64,char
   const * __ptr64) */

char * __cdecl GetProfileStringA(char *param_1,char *param_2,char *param_3)

{
  LSTATUS LVar1;
  HKEY__ *hKey;
  char *pcVar2;
  LPBYTE lpData;
  longlong lVar3;
  DWORD local_res20 [2];
  DWORD local_28 [4];
  
                    /* 0x308a0  108  ?GetProfileStringA@@YAPEBDPEBD00@Z */
  FUN_180031520();
  lpData = (LPBYTE)0x0;
  if (DAT_180072218 != 0) {
    hKey = GetSectionKey(param_1);
    if (hKey == (HKEY__ *)0x0) {
      if (param_3 == (char *)0x0) {
        param_3 = "";
      }
      pcVar2 = _strdup(param_3);
      return pcVar2;
    }
    local_28[0] = 0;
    local_res20[0] = 0;
    LVar1 = RegQueryValueExA(hKey,param_2,(LPDWORD)0x0,local_28,(LPBYTE)0x0,local_res20);
    if (LVar1 == 0) {
      lVar3 = (longlong)(int)local_res20[0];
      lpData = operator_new__((longlong)(int)(local_res20[0] + 1));
      lpData[lVar3] = '\0';
      LVar1 = RegQueryValueExA(hKey,param_2,(LPDWORD)0x0,local_28,lpData,local_res20);
    }
    RegCloseKey(hKey);
    if (LVar1 == 0) {
      return (char *)lpData;
    }
    if (param_3 != (char *)0x0) {
      pcVar2 = _strdup(param_3);
      return pcVar2;
    }
  }
  return (char *)0x0;
}

/* ---- FUNC 000309A0 GetSectionKey (139 bytes) ---- */

/* struct HKEY__ * __ptr64 __cdecl GetSectionKey(char const * __ptr64) */

HKEY__ * __cdecl GetSectionKey(char *param_1)

{
  HKEY__ *hKey;
  DWORD local_res10 [2];
  HKEY local_res18 [2];
  
                    /* 0x309a0  110  ?GetSectionKey@@YAPEAUHKEY__@@PEBD@Z */
  FUN_180031520();
  local_res18[0] = (HKEY__ *)0x0;
  hKey = GetAppRegistryKey();
  if (hKey == (HKEY__ *)0x0) {
    return (HKEY__ *)0x0;
  }
  RegCreateKeyExA(hKey,param_1,0,(LPSTR)0x0,0,0x2001f,(LPSECURITY_ATTRIBUTES)0x0,local_res18,
                  local_res10);
  RegCloseKey(hKey);
  return local_res18[0];
}

/* ---- FUNC 00030A30 MMGetLMAppRegistryKey (384 bytes) ---- */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

HKEY MMGetLMAppRegistryKey(void)

{
  LSTATUS LVar1;
  LPCSTR lpSubKey;
  LPCSTR lpSubKey_00;
  undefined1 auStackY_458 [32];
  HKEY local_428;
  HKEY local_420;
  HKEY local_418 [2];
  undefined1 local_408 [1008];
  ulonglong local_18;
  
                    /* 0x30a30  136  MMGetLMAppRegistryKey */
  local_18 = DAT_1800791f8 ^ (ulonglong)auStackY_458;
  FUN_180031520();
  lpSubKey_00 = (LPCSTR)&DAT_180072208;
  if (0xf < DAT_180072220) {
    lpSubKey_00 = DAT_180072208;
  }
  lpSubKey = (LPCSTR)&DAT_180072228;
  if (0xf < DAT_180072240) {
    lpSubKey = DAT_180072228;
  }
  if (lpSubKey_00 == (LPCSTR)0x0) {
    FUN_180007de0(local_408,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\reghelper.cpp",0x29);
    LogMessage(local_408,2,1);
  }
  if (lpSubKey == (LPCSTR)0x0) {
    FUN_180007de0(local_408,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\reghelper.cpp",0x2a);
    LogMessage(local_408,2,1);
  }
  local_418[0] = (HKEY)0x0;
  local_428 = (HKEY)0x0;
  local_420 = (HKEY)0x0;
  LVar1 = RegOpenKeyExA((HKEY)&DAT_ffffffff80000002,"Software",0,0x20019,&local_428);
  if (LVar1 == 0) {
    LVar1 = RegOpenKeyExA(local_428,lpSubKey_00,0,0x20019,&local_420);
    if (LVar1 == 0) {
      RegOpenKeyExA(local_420,lpSubKey,0,0x20019,local_418);
    }
  }
  if (local_428 != (HKEY)0x0) {
    RegCloseKey(local_428);
  }
  if (local_420 != (HKEY)0x0) {
    RegCloseKey(local_420);
  }
  return local_418[0];
}

/* ---- FUNC 00030BB0 MMGetLMProfileString (869 bytes) ---- */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *
MMGetLMProfileString
          (CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *param_1,LPCSTR param_2,
          LPCSTR param_3,char *param_4)

{
  LSTATUS LVar1;
  DWORD DVar2;
  HKEY hKey;
  LPBYTE lpData;
  LPCSTR *lpFileName;
  LPCSTR lpDefault;
  undefined8 **ppuVar3;
  undefined1 auStackY_1488 [32];
  DWORD local_1458 [2];
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *local_1450;
  DWORD local_1448 [4];
  undefined1 local_1438 [1008];
  CHAR local_1048 [4096];
  ulonglong local_48;
  undefined8 uStack_40;
  
                    /* 0x30bb0  137  MMGetLMProfileString */
  uStack_40 = 0x180030bcd;
  local_48 = DAT_1800791f8 ^ (ulonglong)auStackY_1488;
  local_1450 = param_1;
  FUN_180031520();
  ppuVar3 = &DAT_180072208;
  if (0xf < DAT_180072220) {
    ppuVar3 = (undefined8 **)DAT_180072208;
  }
  lpFileName = &DAT_180072228;
  if (0xf < DAT_180072240) {
    lpFileName = (LPCSTR *)DAT_180072228;
  }
  if (ppuVar3 == (undefined8 **)0x0) {
    FUN_180007de0(local_1438,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\reghelper.cpp",0x5e);
    LogMessage(local_1438,2);
  }
  if (lpFileName == (LPCSTR *)0x0) {
    FUN_180007de0(local_1438,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\reghelper.cpp",0x5f);
    LogMessage(local_1438,2);
  }
  if (param_2 == (LPCSTR)0x0) {
    FUN_180007de0(local_1438,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\reghelper.cpp",0x61);
    LogMessage(local_1438,2);
  }
  if (param_3 == (LPCSTR)0x0) {
    FUN_180007de0(local_1438,"Assert failed in file %s line %d",
                  "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\reghelper.cpp",0x62);
    LogMessage(local_1438,2);
  }
  if (ppuVar3 == (undefined8 **)0x0) {
    if (lpFileName == (LPCSTR *)0x0) {
      FUN_180007de0(local_1438,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\reghelper.cpp",0x7d);
      LogMessage(local_1438,2,1);
    }
    lpDefault = "";
    if (param_4 != (char *)0x0) {
      lpDefault = param_4;
    }
    DVar2 = GetPrivateProfileStringA(param_2,param_3,lpDefault,local_1048,0x1000,(LPCSTR)lpFileName)
    ;
    if (0xffe < DVar2) {
      FUN_180007de0(local_1438,"Assert failed in file %s line %d",
                    "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\reghelper.cpp",0x84);
      LogMessage(local_1438,2,1);
    }
    param_4 = local_1048;
  }
  else {
    hKey = MMGetLMSectionKey(param_2);
    if (hKey != (HKEY)0x0) {
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1450);
      LVar1 = RegQueryValueExA(hKey,param_3,(LPDWORD)0x0,local_1458,(LPBYTE)0x0,local_1448);
      if (LVar1 == 0) {
        if (local_1458[0] != 1) {
          FUN_180007de0(local_1438,"Assert failed in file %s line %d",
                        "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\reghelper.cpp",0x6e);
          LogMessage(local_1438,2);
        }
        lpData = (LPBYTE)ATL::CSimpleStringT<char,1>::GetBuffer
                                   ((CSimpleStringT<char,1> *)&local_1450,local_1448[0]);
        LVar1 = RegQueryValueExA(hKey,param_3,(LPDWORD)0x0,local_1458,lpData,local_1448);
        ATL::CSimpleStringT<char,1>::ReleaseBuffer((CSimpleStringT<char,1> *)&local_1450,-1);
      }
      RegCloseKey(hKey);
      if (LVar1 == 0) {
        if (local_1458[0] != 1) {
          FUN_180007de0(local_1438,"Assert failed in file %s line %d",
                        "G:\\Agent\\work\\2\\s\\src\\mm\\MMStruct\\reghelper.cpp",0x76);
          LogMessage(local_1438,2,1);
        }
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  (param_1,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
                            *)&local_1450);
        ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
        ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                  ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1450);
        return param_1;
      }
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1,param_4);
      ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>
                ((CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_> *)&local_1450);
      return param_1;
    }
  }
  ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>_>_>(param_1,param_4);
  return param_1;
}

