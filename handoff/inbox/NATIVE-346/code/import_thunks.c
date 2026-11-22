/* AMD64 Windows import veneers. Compile with Clang in GNU mode.
   Each extern denotes the named eight-byte IAT slot at the indicated original RVA.
   Naked tail jumps preserve the caller's arguments, return address and ABI. */
/* 0x11342 -> atdms0.dll!DMS_RTLAYL. */
__attribute__((naked, used)) void thunk_11342(void)
{
    __asm__("jmpq *iat_15530(%rip)");
}

/* 0x11348 -> atdms0.dll!LM_RETURN_APROP_LICENSE. */
__attribute__((naked, used)) void thunk_11348(void)
{
    __asm__("jmpq *iat_15520(%rip)");
}

/* 0x1134e -> atdms0.dll!DMS_ASPENC. */
__attribute__((naked, used)) void thunk_1134e(void)
{
    __asm__("jmpq *iat_15528(%rip)");
}

/* 0x11354 -> atdms.dll!DMS_LOCATI. */
__attribute__((naked, used)) void thunk_11354(void)
{
    __asm__("jmpq *iat_15508(%rip)");
}

/* 0x1138a -> atdms.dll!DMS_ILOAD. */
__attribute__((naked, used)) void thunk_1138a(void)
{
    __asm__("jmpq *iat_154c0(%rip)");
}

/* 0x11390 -> atdms.dll!DMS_ICKFPE. */
__attribute__((naked, used)) void thunk_11390(void)
{
    __asm__("jmpq *iat_154b8(%rip)");
}

/* 0x113a8 -> atdms.dll!DMS_IRRCHK. */
__attribute__((naked, used)) void thunk_113a8(void)
{
    __asm__("jmpq *iat_15498(%rip)");
}

/* 0x113b4 -> atdms.dll!DMS_ERRPRT. */
__attribute__((naked, used)) void thunk_113b4(void)
{
    __asm__("jmpq *iat_15488(%rip)");
}

/* 0x113ba -> atdms.dll!DMS_DOCALL. */
__attribute__((naked, used)) void thunk_113ba(void)
{
    __asm__("jmpq *iat_15480(%rip)");
}

/* 0x113c0 -> atdms.dll!DMS_APCWRK. */
__attribute__((naked, used)) void thunk_113c0(void)
{
    __asm__("jmpq *iat_15478(%rip)");
}

/* 0x113c6 -> atdms.dll!DMS_PHCWRK. */
__attribute__((naked, used)) void thunk_113c6(void)
{
    __asm__("jmpq *iat_15470(%rip)");
}

/* 0x113d8 -> atdms.dll!DMS_LOCATM. */
__attribute__((naked, used)) void thunk_113d8(void)
{
    __asm__("jmpq *iat_15458(%rip)");
}

/* 0x113e4 -> atdms.dll!DMS_IPHCFC. */
__attribute__((naked, used)) void thunk_113e4(void)
{
    __asm__("jmpq *iat_15448(%rip)");
}

/* 0x113f0 -> atdms.dll!DMS_TREAD. */
__attribute__((naked, used)) void thunk_113f0(void)
{
    __asm__("jmpq *iat_15438(%rip)");
}

/* 0x113fc -> atdms.dll!DMS_ATFREE. */
__attribute__((naked, used)) void thunk_113fc(void)
{
    __asm__("jmpq *iat_15420(%rip)");
}

/* 0x11402 -> atdms.dll!DMS_RALOCI. */
__attribute__((naked, used)) void thunk_11402(void)
{
    __asm__("jmpq *iat_15428(%rip)");
}

/* 0x11408 -> atdms.dll!DMS_LOCATR. */
__attribute__((naked, used)) void thunk_11408(void)
{
    __asm__("jmpq *iat_15418(%rip)");
}

/* 0x1140e -> atdms.dll!DMS_ALLOCI. */
__attribute__((naked, used)) void thunk_1140e(void)
{
    __asm__("jmpq *iat_15410(%rip)");
}

/* 0x1142c -> atdms.dll!DMS_LENTHR. */
__attribute__((naked, used)) void thunk_1142c(void)
{
    __asm__("jmpq *iat_153e8(%rip)");
}

/* 0x11432 -> atdms.dll!DMS_FREEBD. */
__attribute__((naked, used)) void thunk_11432(void)
{
    __asm__("jmpq *iat_153e0(%rip)");
}

/* 0x11438 -> atdms.dll!DMS_ALLOCR. */
__attribute__((naked, used)) void thunk_11438(void)
{
    __asm__("jmpq *iat_153d8(%rip)");
}

/* 0x1143e -> atdms.dll!DMS_RCOPY. */
__attribute__((naked, used)) void thunk_1143e(void)
{
    __asm__("jmpq *iat_153d0(%rip)");
}

/* 0x1144a -> atdms.dll!DMS_STRLEN. */
__attribute__((naked, used)) void thunk_1144a(void)
{
    __asm__("jmpq *iat_153c0(%rip)");
}

/* 0x11450 -> atdms.dll!DMS_IAPOPN. */
__attribute__((naked, used)) void thunk_11450(void)
{
    __asm__("jmpq *iat_15388(%rip)");
}

/* 0x11462 -> atdms.dll!DMS_FPULDL. */
__attribute__((naked, used)) void thunk_11462(void)
{
    __asm__("jmpq *iat_153b8(%rip)");
}

/* 0x11468 -> atdms.dll!DMS_UNLVRT. */
__attribute__((naked, used)) void thunk_11468(void)
{
    __asm__("jmpq *iat_153a8(%rip)");
}

/* 0x1146e -> atdms.dll!DMS_CLRCMN. */
__attribute__((naked, used)) void thunk_1146e(void)
{
    __asm__("jmpq *iat_153a0(%rip)");
}

/* 0x11474 -> atdms.dll!DMS_CLSPDF. */
__attribute__((naked, used)) void thunk_11474(void)
{
    __asm__("jmpq *iat_15398(%rip)");
}

/* 0x1148c -> atdms.dll!DMS_FPLDLB. */
__attribute__((naked, used)) void thunk_1148c(void)
{
    __asm__("jmpq *iat_15378(%rip)");
}

/* 0x11492 -> atdms.dll!DMS_FPFIND. */
__attribute__((naked, used)) void thunk_11492(void)
{
    __asm__("jmpq *iat_151c8(%rip)");
}

/* 0x11498 -> atdms.dll!DMS_DOCALL_30. */
__attribute__((naked, used)) void thunk_11498(void)
{
    __asm__("jmpq *iat_151d0(%rip)");
}

/* 0x114a4 -> atdms.dll!DMS_CLSBDS. */
__attribute__((naked, used)) void thunk_114a4(void)
{
    __asm__("jmpq *iat_151e0(%rip)");
}

/* 0x114aa -> atdms.dll!DMS_SELF_EXIT. */
__attribute__((naked, used)) void thunk_114aa(void)
{
    __asm__("jmpq *iat_151e8(%rip)");
}

/* 0x114b0 -> atdms.dll!DMS_GET_PRODUCTCODE. */
__attribute__((naked, used)) void thunk_114b0(void)
{
    __asm__("jmpq *iat_151f0(%rip)");
}

/* 0x114b6 -> atdms.dll!DMS_BIOCOMPS. */
__attribute__((naked, used)) void thunk_114b6(void)
{
    __asm__("jmpq *iat_151f8(%rip)");
}

/* 0x114c2 -> atdms.dll!DMS_WHRAMI. */
__attribute__((naked, used)) void thunk_114c2(void)
{
    __asm__("jmpq *iat_15208(%rip)");
}

/* 0x114c8 -> atdms.dll!DMS_APOPEN. */
__attribute__((naked, used)) void thunk_114c8(void)
{
    __asm__("jmpq *iat_15210(%rip)");
}

/* 0x114e0 -> atdms.dll!DMS_INITVMMF. */
__attribute__((naked, used)) void thunk_114e0(void)
{
    __asm__("jmpq *iat_15230(%rip)");
}

/* 0x114f2 -> atdms.dll!DMS_GETASPTOP. */
__attribute__((naked, used)) void thunk_114f2(void)
{
    __asm__("jmpq *iat_15248(%rip)");
}

/* 0x114f8 -> atdms.dll!DMS_ASGOPN. */
__attribute__((naked, used)) void thunk_114f8(void)
{
    __asm__("jmpq *iat_15250(%rip)");
}

/* 0x1150a -> atdms.dll!DMS_PCS_INITPLEX. */
__attribute__((naked, used)) void thunk_1150a(void)
{
    __asm__("jmpq *iat_15268(%rip)");
}

/* 0x11510 -> atdms.dll!DMS_ICKFPE2. */
__attribute__((naked, used)) void thunk_11510(void)
{
    __asm__("jmpq *iat_15270(%rip)");
}

/* 0x1151c -> atdms.dll!DMS_INT2CS. */
__attribute__((naked, used)) void thunk_1151c(void)
{
    __asm__("jmpq *iat_15280(%rip)");
}

/* 0x11522 -> atdms.dll!DMS_LENTHM. */
__attribute__((naked, used)) void thunk_11522(void)
{
    __asm__("jmpq *iat_15288(%rip)");
}

/* 0x11528 -> atdms.dll!DMS_GETVER. */
__attribute__((naked, used)) void thunk_11528(void)
{
    __asm__("jmpq *iat_15290(%rip)");
}

/* 0x1152e -> atdms.dll!DMS_CHKVER. */
__attribute__((naked, used)) void thunk_1152e(void)
{
    __asm__("jmpq *iat_15510(%rip)");
}

/* 0x11534 -> atdms.dll!DMS_MVBYT. */
__attribute__((naked, used)) void thunk_11534(void)
{
    __asm__("jmpq *iat_153b0(%rip)");
}

/* 0x1153a -> atdms.dll!DMS_TCOPY. */
__attribute__((naked, used)) void thunk_1153a(void)
{
    __asm__("jmpq *iat_152a8(%rip)");
}

/* 0x11540 -> atdms.dll!DMS_ALLOCM. */
__attribute__((naked, used)) void thunk_11540(void)
{
    __asm__("jmpq *iat_152b0(%rip)");
}

/* 0x11546 -> atdms.dll!DMS_COPY. */
__attribute__((naked, used)) void thunk_11546(void)
{
    __asm__("jmpq *iat_152b8(%rip)");
}

/* 0x1154c -> atdms.dll!DMS_IKWTXY. */
__attribute__((naked, used)) void thunk_1154c(void)
{
    __asm__("jmpq *iat_152c0(%rip)");
}

/* 0x1155e -> atdms.dll!DMS_ERRSET. */
__attribute__((naked, used)) void thunk_1155e(void)
{
    __asm__("jmpq *iat_152d8(%rip)");
}

/* 0x1156a -> atdms.dll!DMS_CDATE. */
__attribute__((naked, used)) void thunk_1156a(void)
{
    __asm__("jmpq *iat_152e8(%rip)");
}

/* 0x11570 -> atdms.dll!DMS_LENTHI. */
__attribute__((naked, used)) void thunk_11570(void)
{
    __asm__("jmpq *iat_152f0(%rip)");
}

/* 0x1157c -> atdms.dll!DMS_SETNCC. */
__attribute__((naked, used)) void thunk_1157c(void)
{
    __asm__("jmpq *iat_15300(%rip)");
}

/* 0x11582 -> atdms.dll!DMS_SIMBEAD. */
__attribute__((naked, used)) void thunk_11582(void)
{
    __asm__("jmpq *iat_15308(%rip)");
}

/* 0x11588 -> atdms.dll!DMS_STRETN. */
__attribute__((naked, used)) void thunk_11588(void)
{
    __asm__("jmpq *iat_15310(%rip)");
}

/* 0x11594 -> atdms.dll!DMS_STRUPR. */
__attribute__((naked, used)) void thunk_11594(void)
{
    __asm__("jmpq *iat_15320(%rip)");
}

/* 0x1159a -> atdms.dll!DMS_CSTRLEN. */
__attribute__((naked, used)) void thunk_1159a(void)
{
    __asm__("jmpq *iat_15328(%rip)");
}

/* 0x115a0 -> atdms.dll!DMS_SET_PRODUCTCODE. */
__attribute__((naked, used)) void thunk_115a0(void)
{
    __asm__("jmpq *iat_15330(%rip)");
}

/* 0x115a6 -> atdms.dll!DMS_CREATE_BUFFER_LIST. */
__attribute__((naked, used)) void thunk_115a6(void)
{
    __asm__("jmpq *iat_15338(%rip)");
}

/* 0x115b2 -> atdms.dll!DMS_SET_BUFFER_NAME. */
__attribute__((naked, used)) void thunk_115b2(void)
{
    __asm__("jmpq *iat_15348(%rip)");
}

/* 0x115b8 -> atdms.dll!DMS_SET_CURRENT_BUFFER. */
__attribute__((naked, used)) void thunk_115b8(void)
{
    __asm__("jmpq *iat_15350(%rip)");
}

/* 0x115be -> atdms.dll!DMS_SET_BUFFER_AS_HEADER_BY_INDEX. */
__attribute__((naked, used)) void thunk_115be(void)
{
    __asm__("jmpq *iat_15358(%rip)");
}

/* 0x115c4 -> atdms.dll!DMS_GETFNC. */
__attribute__((naked, used)) void thunk_115c4(void)
{
    __asm__("jmpq *iat_15360(%rip)");
}

/* 0x115ca -> atdms.dll!DMS_DOCALL_10. */
__attribute__((naked, used)) void thunk_115ca(void)
{
    __asm__("jmpq *iat_15368(%rip)");
}

/* 0x115d0 -> zeshs.dll!SHS_FIPOLM. */
__attribute__((naked, used)) void thunk_115d0(void)
{
    __asm__("jmpq *iat_15cc8(%rip)");
}

/* 0x115e2 -> zereport.dll!ZREP_REPBLK. */
__attribute__((naked, used)) void thunk_115e2(void)
{
    __asm__("jmpq *iat_15c90(%rip)");
}

/* 0x115ee -> zereport.dll!ZREP_CENTER. */
__attribute__((naked, used)) void thunk_115ee(void)
{
    __asm__("jmpq *iat_15ca8(%rip)");
}

/* 0x115f4 -> zereport.dll!ZREP_PLOGO. */
__attribute__((naked, used)) void thunk_115f4(void)
{
    __asm__("jmpq *iat_15ca0(%rip)");
}

/* 0x11600 -> pputil.dll!PPUTL_PPFUNC. */
__attribute__((naked, used)) void thunk_11600(void)
{
    __asm__("jmpq *iat_15c20(%rip)");
}

/* 0x11642 -> ppbase.dll!PPBASE_WATS01. */
__attribute__((naked, used)) void thunk_11642(void)
{
    __asm__("jmpq *iat_15600(%rip)");
}

/* 0x11648 -> ppbase.dll!PPBASE_GM11. */
__attribute__((naked, used)) void thunk_11648(void)
{
    __asm__("jmpq *iat_155f8(%rip)");
}

/* 0x1164e -> ppbase.dll!PPBASE_MUVL02. */
__attribute__((naked, used)) void thunk_1164e(void)
{
    __asm__("jmpq *iat_155f0(%rip)");
}

/* 0x11654 -> ppbase.dll!PPBASE_HRFIGI. */
__attribute__((naked, used)) void thunk_11654(void)
{
    __asm__("jmpq *iat_155e8(%rip)");
}

/* 0x1165a -> ppbase.dll!PPBASE_IDLINT. */
__attribute__((naked, used)) void thunk_1165a(void)
{
    __asm__("jmpq *iat_155e0(%rip)");
}

/* 0x11660 -> ppbase.dll!PPBASE_HCS01I. */
__attribute__((naked, used)) void thunk_11660(void)
{
    __asm__("jmpq *iat_155d8(%rip)");
}

/* 0x11666 -> ppbase.dll!PPBASE_GM05I. */
__attribute__((naked, used)) void thunk_11666(void)
{
    __asm__("jmpq *iat_155d0(%rip)");
}

/* 0x1166c -> ppbase.dll!PPBASE_GM11M. */
__attribute__((naked, used)) void thunk_1166c(void)
{
    __asm__("jmpq *iat_155c8(%rip)");
}

/* 0x11672 -> ppbase.dll!PPBASE_GM25II. */
__attribute__((naked, used)) void thunk_11672(void)
{
    __asm__("jmpq *iat_155c0(%rip)");
}

/* 0x11678 -> ppbase.dll!PPBASE_GM05AI. */
__attribute__((naked, used)) void thunk_11678(void)
{
    __asm__("jmpq *iat_155b8(%rip)");
}

/* 0x11690 -> ppbase.dll!PPBASE_ES15B1. */
__attribute__((naked, used)) void thunk_11690(void)
{
    __asm__("jmpq *iat_15590(%rip)");
}

/* 0x11696 -> ppbase.dll!PPBASE_ES15B2. */
__attribute__((naked, used)) void thunk_11696(void)
{
    __asm__("jmpq *iat_15588(%rip)");
}

/* 0x1169c -> ppbase.dll!PPBASE_ES15B3. */
__attribute__((naked, used)) void thunk_1169c(void)
{
    __asm__("jmpq *iat_15580(%rip)");
}

/* 0x116a2 -> ppbase.dll!PPBASE_ES15B4. */
__attribute__((naked, used)) void thunk_116a2(void)
{
    __asm__("jmpq *iat_155a0(%rip)");
}

/* 0x116a8 -> ppbase.dll!PPBASE_ES15B5. */
__attribute__((naked, used)) void thunk_116a8(void)
{
    __asm__("jmpq *iat_155a8(%rip)");
}

/* 0x116ba -> ppuser.dll!PPUSER_PHCCIU. */
__attribute__((naked, used)) void thunk_116ba(void)
{
    __asm__("jmpq *iat_15c10(%rip)");
}

/* 0x116c0 -> ppuser.dll!PPUSER_PHCLCU. */
__attribute__((naked, used)) void thunk_116c0(void)
{
    __asm__("jmpq *iat_15c08(%rip)");
}

/* 0x116c6 -> ppeosi.dll!PPESI_ES02. */
__attribute__((naked, used)) void thunk_116c6(void)
{
    __asm__("jmpq *iat_15730(%rip)");
}

/* 0x116cc -> ppeosi.dll!PPESI_ES04. */
__attribute__((naked, used)) void thunk_116cc(void)
{
    __asm__("jmpq *iat_15738(%rip)");
}

/* 0x116d2 -> ppeosi.dll!PPESI_ES19A. */
__attribute__((naked, used)) void thunk_116d2(void)
{
    __asm__("jmpq *iat_15740(%rip)");
}

/* 0x116d8 -> ppeosi.dll!PPESI_ES06SA. */
__attribute__((naked, used)) void thunk_116d8(void)
{
    __asm__("jmpq *iat_157a8(%rip)");
}

/* 0x116de -> ppeosi.dll!PPESI_ES13A. */
__attribute__((naked, used)) void thunk_116de(void)
{
    __asm__("jmpq *iat_157b0(%rip)");
}

/* 0x116e4 -> ppeosi.dll!PPESI_ES36I. */
__attribute__((naked, used)) void thunk_116e4(void)
{
    __asm__("jmpq *iat_157b8(%rip)");
}

/* 0x116ea -> ppeosi.dll!PPESI_ES32A. */
__attribute__((naked, used)) void thunk_116ea(void)
{
    __asm__("jmpq *iat_157c0(%rip)");
}

/* 0x116f0 -> ppeosi.dll!PPESI_ES06A. */
__attribute__((naked, used)) void thunk_116f0(void)
{
    __asm__("jmpq *iat_15678(%rip)");
}

/* 0x116f6 -> ppeosi.dll!PPESI_ESR02I. */
__attribute__((naked, used)) void thunk_116f6(void)
{
    __asm__("jmpq *iat_157d8(%rip)");
}

/* 0x116fc -> ppeosi.dll!PPESI_ES19. */
__attribute__((naked, used)) void thunk_116fc(void)
{
    __asm__("jmpq *iat_157d0(%rip)");
}

/* 0x11702 -> ppeosi.dll!PPESI_ES36VI. */
__attribute__((naked, used)) void thunk_11702(void)
{
    __asm__("jmpq *iat_157c8(%rip)");
}

/* 0x11708 -> ppeosi.dll!PPESI_ES24I. */
__attribute__((naked, used)) void thunk_11708(void)
{
    __asm__("jmpq *iat_15768(%rip)");
}

/* 0x1170e -> ppeosi.dll!PPESI_ES17. */
__attribute__((naked, used)) void thunk_1170e(void)
{
    __asm__("jmpq *iat_15760(%rip)");
}

/* 0x11714 -> ppeosi.dll!PPESI_ES30A. */
__attribute__((naked, used)) void thunk_11714(void)
{
    __asm__("jmpq *iat_15758(%rip)");
}

/* 0x1171a -> ppeosi.dll!PPESI_ES21. */
__attribute__((naked, used)) void thunk_1171a(void)
{
    __asm__("jmpq *iat_15750(%rip)");
}

/* 0x11720 -> ppeosi.dll!PPESI_ES32. */
__attribute__((naked, used)) void thunk_11720(void)
{
    __asm__("jmpq *iat_15748(%rip)");
}

/* 0x11726 -> ppeosi.dll!PPESI_ESR05I. */
__attribute__((naked, used)) void thunk_11726(void)
{
    __asm__("jmpq *iat_15720(%rip)");
}

/* 0x1172c -> ppeosi.dll!PPESI_HYSPRI. */
__attribute__((naked, used)) void thunk_1172c(void)
{
    __asm__("jmpq *iat_15718(%rip)");
}

/* 0x11732 -> ppeosi.dll!PPESI_ESR08I. */
__attribute__((naked, used)) void thunk_11732(void)
{
    __asm__("jmpq *iat_15710(%rip)");
}

/* 0x11738 -> ppeosi.dll!PPESI_ES13. */
__attribute__((naked, used)) void thunk_11738(void)
{
    __asm__("jmpq *iat_15708(%rip)");
}

/* 0x1173e -> ppeosi.dll!PPESI_ESR04I. */
__attribute__((naked, used)) void thunk_1173e(void)
{
    __asm__("jmpq *iat_15700(%rip)");
}

/* 0x11744 -> ppeosi.dll!PPESI_ES04A. */
__attribute__((naked, used)) void thunk_11744(void)
{
    __asm__("jmpq *iat_156f8(%rip)");
}

/* 0x1174a -> ppeosi.dll!PPESI_ESR03I. */
__attribute__((naked, used)) void thunk_1174a(void)
{
    __asm__("jmpq *iat_156f0(%rip)");
}

/* 0x11750 -> ppeosi.dll!PPESI_ESPR78AI. */
__attribute__((naked, used)) void thunk_11750(void)
{
    __asm__("jmpq *iat_156e8(%rip)");
}

/* 0x11756 -> ppeosi.dll!PPESI_ES09I. */
__attribute__((naked, used)) void thunk_11756(void)
{
    __asm__("jmpq *iat_15798(%rip)");
}

/* 0x1175c -> ppeosi.dll!PPESI_HYSSRKI. */
__attribute__((naked, used)) void thunk_1175c(void)
{
    __asm__("jmpq *iat_156d8(%rip)");
}

/* 0x11762 -> ppeosi.dll!PPESI_ES35I. */
__attribute__((naked, used)) void thunk_11762(void)
{
    __asm__("jmpq *iat_156d0(%rip)");
}

/* 0x11768 -> ppeosi.dll!PPESI_ES04WA. */
__attribute__((naked, used)) void thunk_11768(void)
{
    __asm__("jmpq *iat_156c8(%rip)");
}

/* 0x1176e -> ppeosi.dll!PPESI_ESCPAI. */
__attribute__((naked, used)) void thunk_1176e(void)
{
    __asm__("jmpq *iat_156c0(%rip)");
}

/* 0x11774 -> ppeosi.dll!PPESI_ES35VTI. */
__attribute__((naked, used)) void thunk_11774(void)
{
    __asm__("jmpq *iat_156b8(%rip)");
}

/* 0x1177a -> ppeosi.dll!PPESI_ESPR78I. */
__attribute__((naked, used)) void thunk_1177a(void)
{
    __asm__("jmpq *iat_156b0(%rip)");
}

/* 0x11780 -> ppeosi.dll!PPESI_ES11. */
__attribute__((naked, used)) void thunk_11780(void)
{
    __asm__("jmpq *iat_156a8(%rip)");
}

/* 0x11786 -> ppeosi.dll!PPESI_ESR07I. */
__attribute__((naked, used)) void thunk_11786(void)
{
    __asm__("jmpq *iat_156a0(%rip)");
}

/* 0x1178c -> ppeosi.dll!PPESI_ES14. */
__attribute__((naked, used)) void thunk_1178c(void)
{
    __asm__("jmpq *iat_15698(%rip)");
}

/* 0x11792 -> ppeosi.dll!PPESI_ES04SA. */
__attribute__((naked, used)) void thunk_11792(void)
{
    __asm__("jmpq *iat_15690(%rip)");
}

/* 0x11798 -> ppeosi.dll!PPESI_ES06S. */
__attribute__((naked, used)) void thunk_11798(void)
{
    __asm__("jmpq *iat_15688(%rip)");
}

/* 0x1179e -> ppeosi.dll!PPESI_ES30. */
__attribute__((naked, used)) void thunk_1179e(void)
{
    __asm__("jmpq *iat_15680(%rip)");
}

/* 0x117a4 -> ppeosi.dll!PPESI_ES11A. */
__attribute__((naked, used)) void thunk_117a4(void)
{
    __asm__("jmpq *iat_157a0(%rip)");
}

/* 0x117aa -> ppeosi.dll!PPESI_ES21A. */
__attribute__((naked, used)) void thunk_117aa(void)
{
    __asm__("jmpq *iat_15790(%rip)");
}

/* 0x117b0 -> ppeosi.dll!PPESI_ES02A. */
__attribute__((naked, used)) void thunk_117b0(void)
{
    __asm__("jmpq *iat_15788(%rip)");
}

/* 0x117b6 -> ppeosi.dll!PPESI_ES4ML. */
__attribute__((naked, used)) void thunk_117b6(void)
{
    __asm__("jmpq *iat_15780(%rip)");
}

/* 0x117bc -> ppeosi.dll!PPESI_ES04W. */
__attribute__((naked, used)) void thunk_117bc(void)
{
    __asm__("jmpq *iat_15778(%rip)");
}

/* 0x117c2 -> ppeosi.dll!PPESI_ES4MLA. */
__attribute__((naked, used)) void thunk_117c2(void)
{
    __asm__("jmpq *iat_15770(%rip)");
}

/* 0x117c8 -> ppeosi.dll!PPESI_ES06. */
__attribute__((naked, used)) void thunk_117c8(void)
{
    __asm__("jmpq *iat_15728(%rip)");
}

/* 0x117ce -> ppeosi.dll!PPESI_ESR06I. */
__attribute__((naked, used)) void thunk_117ce(void)
{
    __asm__("jmpq *iat_156e0(%rip)");
}

/* 0x117d4 -> ppeosi.dll!PPESI_ES04S. */
__attribute__((naked, used)) void thunk_117d4(void)
{
    __asm__("jmpq *iat_15660(%rip)");
}

/* 0x117da -> ppeosi.dll!PPESI_ESR01I. */
__attribute__((naked, used)) void thunk_117da(void)
{
    __asm__("jmpq *iat_15668(%rip)");
}

/* 0x117e0 -> ppeosi.dll!PPESI_ES35VI. */
__attribute__((naked, used)) void thunk_117e0(void)
{
    __asm__("jmpq *iat_15670(%rip)");
}

/* 0x117e6 -> ppeosi.dll!PPESI_ES141. */
__attribute__((naked, used)) void thunk_117e6(void)
{
    __asm__("jmpq *iat_157e0(%rip)");
}

/* 0x117ec -> ppthermoi.dll!PPTHI_PS003. */
__attribute__((naked, used)) void thunk_117ec(void)
{
    __asm__("jmpq *iat_15b18(%rip)");
}

/* 0x117f2 -> ppthermoi.dll!PPTHI_DHL302. */
__attribute__((naked, used)) void thunk_117f2(void)
{
    __asm__("jmpq *iat_15b10(%rip)");
}

/* 0x117f8 -> ppthermoi.dll!PPTHI_HL003. */
__attribute__((naked, used)) void thunk_117f8(void)
{
    __asm__("jmpq *iat_15b08(%rip)");
}

/* 0x117fe -> ppthermoi.dll!PPTHI_HL002. */
__attribute__((naked, used)) void thunk_117fe(void)
{
    __asm__("jmpq *iat_15b28(%rip)");
}

/* 0x11804 -> ppthermoi.dll!PPTHI_HS002I. */
__attribute__((naked, used)) void thunk_11804(void)
{
    __asm__("jmpq *iat_15b60(%rip)");
}

/* 0x1180a -> ppthermoi.dll!PPTHI_VS001I. */
__attribute__((naked, used)) void thunk_1180a(void)
{
    __asm__("jmpq *iat_15b68(%rip)");
}

/* 0x11810 -> ppthermoi.dll!PPTHI_VL010I. */
__attribute__((naked, used)) void thunk_11810(void)
{
    __asm__("jmpq *iat_15b70(%rip)");
}

/* 0x11816 -> ppthermoi.dll!PPTHI_VLQUAI. */
__attribute__((naked, used)) void thunk_11816(void)
{
    __asm__("jmpq *iat_15b78(%rip)");
}

/* 0x1181c -> ppthermoi.dll!PPTHI_VL004I. */
__attribute__((naked, used)) void thunk_1181c(void)
{
    __asm__("jmpq *iat_15b20(%rip)");
}

/* 0x11822 -> ppthermoi.dll!PPTHI_HRFLQI. */
__attribute__((naked, used)) void thunk_11822(void)
{
    __asm__("jmpq *iat_15b30(%rip)");
}

/* 0x11828 -> ppthermoi.dll!PPTHI_DHV01I. */
__attribute__((naked, used)) void thunk_11828(void)
{
    __asm__("jmpq *iat_15b38(%rip)");
}

/* 0x1182e -> ppthermoi.dll!PPTHI_PL001I. */
__attribute__((naked, used)) void thunk_1182e(void)
{
    __asm__("jmpq *iat_15b40(%rip)");
}

/* 0x11834 -> ppthermoi.dll!PPTHI_VL208I. */
__attribute__((naked, used)) void thunk_11834(void)
{
    __asm__("jmpq *iat_15b48(%rip)");
}

/* 0x1183a -> ppthermoi.dll!PPTHI_PHL004. */
__attribute__((naked, used)) void thunk_1183a(void)
{
    __asm__("jmpq *iat_15b50(%rip)");
}

/* 0x11840 -> ppthermoi.dll!PPTHI_VPM03. */
__attribute__((naked, used)) void thunk_11840(void)
{
    __asm__("jmpq *iat_15b58(%rip)");
}

/* 0x11846 -> ppthermoi.dll!PPTHI_VL006. */
__attribute__((naked, used)) void thunk_11846(void)
{
    __asm__("jmpq *iat_15b80(%rip)");
}

/* 0x1184c -> ppgammai.dll!PPGMI_GM041. */
__attribute__((naked, used)) void thunk_1184c(void)
{
    __asm__("jmpq *iat_157f0(%rip)");
}

/* 0x11852 -> ppgammai.dll!PPGMI_GM07. */
__attribute__((naked, used)) void thunk_11852(void)
{
    __asm__("jmpq *iat_15848(%rip)");
}

/* 0x11858 -> ppgammai.dll!PPGMI_GM15. */
__attribute__((naked, used)) void thunk_11858(void)
{
    __asm__("jmpq *iat_15840(%rip)");
}

/* 0x1185e -> ppgammai.dll!PPGMI_GM13G. */
__attribute__((naked, used)) void thunk_1185e(void)
{
    __asm__("jmpq *iat_15838(%rip)");
}

/* 0x11864 -> ppgammai.dll!PPGMI_GM02. */
__attribute__((naked, used)) void thunk_11864(void)
{
    __asm__("jmpq *iat_15830(%rip)");
}

/* 0x1186a -> ppgammai.dll!PPGMI_GM03I. */
__attribute__((naked, used)) void thunk_1186a(void)
{
    __asm__("jmpq *iat_15828(%rip)");
}

/* 0x11870 -> ppgammai.dll!PPGMI_GM11VT. */
__attribute__((naked, used)) void thunk_11870(void)
{
    __asm__("jmpq *iat_15820(%rip)");
}

/* 0x11876 -> ppgammai.dll!PPGMI_GM13L. */
__attribute__((naked, used)) void thunk_11876(void)
{
    __asm__("jmpq *iat_15818(%rip)");
}

/* 0x1187c -> ppgammai.dll!PPGMI_CSMOSI. */
__attribute__((naked, used)) void thunk_1187c(void)
{
    __asm__("jmpq *iat_15810(%rip)");
}

/* 0x11882 -> ppgammai.dll!PPGMI_GM23I. */
__attribute__((naked, used)) void thunk_11882(void)
{
    __asm__("jmpq *iat_15808(%rip)");
}

/* 0x11888 -> ppgammai.dll!PPGMI_GM11PS. */
__attribute__((naked, used)) void thunk_11888(void)
{
    __asm__("jmpq *iat_15800(%rip)");
}

/* 0x1188e -> ppgammai.dll!PPGMI_GM20I. */
__attribute__((naked, used)) void thunk_1188e(void)
{
    __asm__("jmpq *iat_157f8(%rip)");
}

/* 0x11894 -> pptabpolyi.dll!PPTBI_HIGTB. */
__attribute__((naked, used)) void thunk_11894(void)
{
    __asm__("jmpq *iat_15a70(%rip)");
}

/* 0x1189a -> pptabpolyi.dll!PPTBI_VSTB. */
__attribute__((naked, used)) void thunk_1189a(void)
{
    __asm__("jmpq *iat_15a78(%rip)");
}

/* 0x118a0 -> pptabpolyi.dll!PPTBI_HLTB. */
__attribute__((naked, used)) void thunk_118a0(void)
{
    __asm__("jmpq *iat_15a80(%rip)");
}

/* 0x118a6 -> pptabpolyi.dll!PPTBI_VLTB. */
__attribute__((naked, used)) void thunk_118a6(void)
{
    __asm__("jmpq *iat_15ac0(%rip)");
}

/* 0x118ac -> pptabpolyi.dll!PPTBI_DSVTB. */
__attribute__((naked, used)) void thunk_118ac(void)
{
    __asm__("jmpq *iat_15ad8(%rip)");
}

/* 0x118b2 -> pptabpolyi.dll!PPTBI_DSLTB. */
__attribute__((naked, used)) void thunk_118b2(void)
{
    __asm__("jmpq *iat_15ad0(%rip)");
}

/* 0x118b8 -> pptabpolyi.dll!PPTBI_PHVTB. */
__attribute__((naked, used)) void thunk_118b8(void)
{
    __asm__("jmpq *iat_15ab8(%rip)");
}

/* 0x118be -> pptabpolyi.dll!PPTBI_PHLTB. */
__attribute__((naked, used)) void thunk_118be(void)
{
    __asm__("jmpq *iat_15ab0(%rip)");
}

/* 0x118c4 -> pptabpolyi.dll!PPTBI_HVTB. */
__attribute__((naked, used)) void thunk_118c4(void)
{
    __asm__("jmpq *iat_15aa8(%rip)");
}

/* 0x118ca -> pptabpolyi.dll!PPTBI_DHVLTB. */
__attribute__((naked, used)) void thunk_118ca(void)
{
    __asm__("jmpq *iat_15aa0(%rip)");
}

/* 0x118d0 -> pptabpolyi.dll!PPTBI_DHLTB. */
__attribute__((naked, used)) void thunk_118d0(void)
{
    __asm__("jmpq *iat_15a98(%rip)");
}

/* 0x118d6 -> pptabpolyi.dll!PPTBI_DHLSTB. */
__attribute__((naked, used)) void thunk_118d6(void)
{
    __asm__("jmpq *iat_15a90(%rip)");
}

/* 0x118dc -> pptabpolyi.dll!PPTBI_DHVSTB. */
__attribute__((naked, used)) void thunk_118dc(void)
{
    __asm__("jmpq *iat_15a88(%rip)");
}

/* 0x118e2 -> pptabpolyi.dll!PPTBI_DGVTB. */
__attribute__((naked, used)) void thunk_118e2(void)
{
    __asm__("jmpq *iat_15a50(%rip)");
}

/* 0x118e8 -> pptabpolyi.dll!PPTBI_DGSTB. */
__attribute__((naked, used)) void thunk_118e8(void)
{
    __asm__("jmpq *iat_15a68(%rip)");
}

/* 0x118ee -> pptabpolyi.dll!PPTBI_SLTB. */
__attribute__((naked, used)) void thunk_118ee(void)
{
    __asm__("jmpq *iat_15ae0(%rip)");
}

/* 0x118f4 -> pptabpolyi.dll!PPTBI_PLTB. */
__attribute__((naked, used)) void thunk_118f4(void)
{
    __asm__("jmpq *iat_15ac8(%rip)");
}

/* 0x118fa -> pptabpolyi.dll!PPTBI_MUVTB. */
__attribute__((naked, used)) void thunk_118fa(void)
{
    __asm__("jmpq *iat_15a60(%rip)");
}

/* 0x11900 -> pptabpolyi.dll!PPTBI_MULTB. */
__attribute__((naked, used)) void thunk_11900(void)
{
    __asm__("jmpq *iat_15a58(%rip)");
}

/* 0x11906 -> pptabpolyi.dll!PPTBI_KVLTB. */
__attribute__((naked, used)) void thunk_11906(void)
{
    __asm__("jmpq *iat_15ae8(%rip)");
}

/* 0x1190c -> pptabpolyi.dll!PPTBI_DHSTB. */
__attribute__((naked, used)) void thunk_1190c(void)
{
    __asm__("jmpq *iat_15a48(%rip)");
}

/* 0x11912 -> pptabpolyi.dll!PPTBI_SVTB. */
__attribute__((naked, used)) void thunk_11912(void)
{
    __asm__("jmpq *iat_15a40(%rip)");
}

/* 0x11918 -> pptabpolyi.dll!PPTBI_PHVMTB. */
__attribute__((naked, used)) void thunk_11918(void)
{
    __asm__("jmpq *iat_15a38(%rip)");
}

/* 0x1191e -> pptabpolyi.dll!PPTBI_GVTB. */
__attribute__((naked, used)) void thunk_1191e(void)
{
    __asm__("jmpq *iat_15a30(%rip)");
}

/* 0x11924 -> pptabpolyi.dll!PPTBI_KLLTB. */
__attribute__((naked, used)) void thunk_11924(void)
{
    __asm__("jmpq *iat_15a28(%rip)");
}

/* 0x1192a -> pptabpolyi.dll!PPTBI_HNRYTB. */
__attribute__((naked, used)) void thunk_1192a(void)
{
    __asm__("jmpq *iat_15a20(%rip)");
}

/* 0x11930 -> pptabpolyi.dll!PPTBI_DSSTB. */
__attribute__((naked, used)) void thunk_11930(void)
{
    __asm__("jmpq *iat_15a18(%rip)");
}

/* 0x11936 -> pptabpolyi.dll!PPTBI_PHSTB. */
__attribute__((naked, used)) void thunk_11936(void)
{
    __asm__("jmpq *iat_15a10(%rip)");
}

/* 0x1193c -> pptabpolyi.dll!PPTBI_PHLMTB. */
__attribute__((naked, used)) void thunk_1193c(void)
{
    __asm__("jmpq *iat_15a08(%rip)");
}

/* 0x11942 -> pptabpolyi.dll!PPTBI_GLTB. */
__attribute__((naked, used)) void thunk_11942(void)
{
    __asm__("jmpq *iat_15a00(%rip)");
}

/* 0x11948 -> pptabpolyi.dll!PPTBI_HSTB. */
__attribute__((naked, used)) void thunk_11948(void)
{
    __asm__("jmpq *iat_159f8(%rip)");
}

/* 0x1194e -> pptabpolyi.dll!PPTBI_PSTB. */
__attribute__((naked, used)) void thunk_1194e(void)
{
    __asm__("jmpq *iat_159f0(%rip)");
}

/* 0x11954 -> pptabpolyi.dll!PPTBI_DGLTB. */
__attribute__((naked, used)) void thunk_11954(void)
{
    __asm__("jmpq *iat_159e8(%rip)");
}

/* 0x1195a -> pptabpolyi.dll!PPTBI_SSTB. */
__attribute__((naked, used)) void thunk_1195a(void)
{
    __asm__("jmpq *iat_159e0(%rip)");
}

/* 0x11960 -> pptabpolyi.dll!PPTBI_VVTB. */
__attribute__((naked, used)) void thunk_11960(void)
{
    __asm__("jmpq *iat_159d8(%rip)");
}

/* 0x11966 -> pptabpolyi.dll!PPTBI_GSTB. */
__attribute__((naked, used)) void thunk_11966(void)
{
    __asm__("jmpq *iat_159d0(%rip)");
}

/* 0x1196c -> pptabpolyi.dll!PPTBI_DHVTB. */
__attribute__((naked, used)) void thunk_1196c(void)
{
    __asm__("jmpq *iat_159c8(%rip)");
}

/* 0x11972 -> pptransporti.dll!PPTXI_KVLW1. */
__attribute__((naked, used)) void thunk_11972(void)
{
    __asm__("jmpq *iat_15ba0(%rip)");
}

/* 0x11978 -> pptransporti.dll!PPTXI_MUASPI. */
__attribute__((naked, used)) void thunk_11978(void)
{
    __asm__("jmpq *iat_15b98(%rip)");
}

/* 0x1197e -> pptransporti.dll!PPTXI_KV001I. */
__attribute__((naked, used)) void thunk_1197e(void)
{
    __asm__("jmpq *iat_15b90(%rip)");
}

/* 0x11984 -> pptransporti.dll!PPTXI_MUL01I. */
__attribute__((naked, used)) void thunk_11984(void)
{
    __asm__("jmpq *iat_15ba8(%rip)");
}

/* 0x1198a -> pptransporti.dll!PPTXI_KL002I. */
__attribute__((naked, used)) void thunk_1198a(void)
{
    __asm__("jmpq *iat_15bb0(%rip)");
}

/* 0x11990 -> pptransporti.dll!PPTXI_MUV01I. */
__attribute__((naked, used)) void thunk_11990(void)
{
    __asm__("jmpq *iat_15bb8(%rip)");
}

/* 0x11996 -> pptransporti.dll!PPTXI_MULQUI. */
__attribute__((naked, used)) void thunk_11996(void)
{
    __asm__("jmpq *iat_15bf8(%rip)");
}

/* 0x1199c -> pptransporti.dll!PPTXI_SIG02I. */
__attribute__((naked, used)) void thunk_1199c(void)
{
    __asm__("jmpq *iat_15bc0(%rip)");
}

/* 0x119a2 -> pptransporti.dll!PPTXI_MUL207. */
__attribute__((naked, used)) void thunk_119a2(void)
{
    __asm__("jmpq *iat_15bc8(%rip)");
}

/* 0x119a8 -> pptransporti.dll!PPTXI_KL204I. */
__attribute__((naked, used)) void thunk_119a8(void)
{
    __asm__("jmpq *iat_15bd0(%rip)");
}

/* 0x119ae -> pptransporti.dll!PPTXI_MUVLW1. */
__attribute__((naked, used)) void thunk_119ae(void)
{
    __asm__("jmpq *iat_15bd8(%rip)");
}

/* 0x119b4 -> pptransporti.dll!PPTXI_MUVLW2. */
__attribute__((naked, used)) void thunk_119b4(void)
{
    __asm__("jmpq *iat_15be0(%rip)");
}

/* 0x119ba -> pptransporti.dll!PPTXI_MUVL05. */
__attribute__((naked, used)) void thunk_119ba(void)
{
    __asm__("jmpq *iat_15be8(%rip)");
}

/* 0x119c0 -> pptransporti.dll!PPTXI_MUV006. */
__attribute__((naked, used)) void thunk_119c0(void)
{
    __asm__("jmpq *iat_15bf0(%rip)");
}

/* 0x119c6 -> ppthermo.dll!PPTH_SLXIN0. */
__attribute__((naked, used)) void thunk_119c6(void)
{
    __asm__("jmpq *iat_15af8(%rip)");
}

/* 0x119cc -> pptabpoly.dll!PPTB_TPUNPK. */
__attribute__((naked, used)) void thunk_119cc(void)
{
    __asm__("jmpq *iat_159b8(%rip)");
}

/* 0x119d2 -> ppstub.dll!PPSTUB_VAQ003. */
__attribute__((naked, used)) void thunk_119d2(void)
{
    __asm__("jmpq *iat_15940(%rip)");
}

/* 0x119d8 -> ppstub.dll!PPSTUB_GM081E. */
__attribute__((naked, used)) void thunk_119d8(void)
{
    __asm__("jmpq *iat_15948(%rip)");
}

/* 0x119de -> ppstub.dll!PPSTUB_TM001I. */
__attribute__((naked, used)) void thunk_119de(void)
{
    __asm__("jmpq *iat_15950(%rip)");
}

/* 0x119e4 -> ppstub.dll!PPSTUB_BK10IN. */
__attribute__((naked, used)) void thunk_119e4(void)
{
    __asm__("jmpq *iat_15958(%rip)");
}

/* 0x119ea -> ppstub.dll!PPSTUB_CPP01I. */
__attribute__((naked, used)) void thunk_119ea(void)
{
    __asm__("jmpq *iat_15960(%rip)");
}

/* 0x119f0 -> ppstub.dll!PPSTUB_FH01I. */
__attribute__((naked, used)) void thunk_119f0(void)
{
    __asm__("jmpq *iat_15968(%rip)");
}

/* 0x119f6 -> ppstub.dll!PPSTUB_HLP01I. */
__attribute__((naked, used)) void thunk_119f6(void)
{
    __asm__("jmpq *iat_15970(%rip)");
}

/* 0x119fc -> ppstub.dll!PPSTUB_GLP01I. */
__attribute__((naked, used)) void thunk_119fc(void)
{
    __asm__("jmpq *iat_15978(%rip)");
}

/* 0x11a02 -> ppstub.dll!PPSTUB_MUASP0. */
__attribute__((naked, used)) void thunk_11a02(void)
{
    __asm__("jmpq *iat_15980(%rip)");
}

/* 0x11a08 -> ppstub.dll!PPSTUB_ESPSLI. */
__attribute__((naked, used)) void thunk_11a08(void)
{
    __asm__("jmpq *iat_15988(%rip)");
}

/* 0x11a0e -> ppstub.dll!PPSTUB_CM05SI. */
__attribute__((naked, used)) void thunk_11a0e(void)
{
    __asm__("jmpq *iat_15990(%rip)");
}

/* 0x11a14 -> ppstub.dll!PPSTUB_KLVKI. */
__attribute__((naked, used)) void thunk_11a14(void)
{
    __asm__("jmpq *iat_15998(%rip)");
}

/* 0x11a1a -> ppstub.dll!PPSTUB_ESP01I. */
__attribute__((naked, used)) void thunk_11a1a(void)
{
    __asm__("jmpq *iat_159a0(%rip)");
}

/* 0x11a20 -> ppstub.dll!PPSTUB_GM18. */
__attribute__((naked, used)) void thunk_11a20(void)
{
    __asm__("jmpq *iat_159a8(%rip)");
}

/* 0x11a26 -> ppstub.dll!PPSTUB_VLP01I. */
__attribute__((naked, used)) void thunk_11a26(void)
{
    __asm__("jmpq *iat_15938(%rip)");
}

/* 0x11a2c -> ppstub.dll!PPSTUB_ESPCSI. */
__attribute__((naked, used)) void thunk_11a2c(void)
{
    __asm__("jmpq *iat_15930(%rip)");
}

/* 0x11a32 -> ppstub.dll!PPSTUB_ESPSAHI. */
__attribute__((naked, used)) void thunk_11a32(void)
{
    __asm__("jmpq *iat_15910(%rip)");
}

/* 0x11a38 -> ppstub.dll!PPSTUB_EYRIN0. */
__attribute__((naked, used)) void thunk_11a38(void)
{
    __asm__("jmpq *iat_15898(%rip)");
}

/* 0x11a3e -> ppstub.dll!PPSTUB_MUPOL0. */
__attribute__((naked, used)) void thunk_11a3e(void)
{
    __asm__("jmpq *iat_15890(%rip)");
}

/* 0x11a44 -> ppstub.dll!PPSTUB_GM081. */
__attribute__((naked, used)) void thunk_11a44(void)
{
    __asm__("jmpq *iat_15928(%rip)");
}

/* 0x11a4a -> ppstub.dll!PPSTUB_VLP02I. */
__attribute__((naked, used)) void thunk_11a4a(void)
{
    __asm__("jmpq *iat_158d8(%rip)");
}

/* 0x11a50 -> ppstub.dll!PPSTUB_ESSFTI. */
__attribute__((naked, used)) void thunk_11a50(void)
{
    __asm__("jmpq *iat_158c8(%rip)");
}

/* 0x11a56 -> ppstub.dll!PPSTUB_GM05SR. */
__attribute__((naked, used)) void thunk_11a56(void)
{
    __asm__("jmpq *iat_158d0(%rip)");
}

/* 0x11a5c -> ppstub.dll!PPSTUB_GM05SI. */
__attribute__((naked, used)) void thunk_11a5c(void)
{
    __asm__("jmpq *iat_15920(%rip)");
}

/* 0x11a62 -> ppstub.dll!PPSTUB_GM05RK. */
__attribute__((naked, used)) void thunk_11a62(void)
{
    __asm__("jmpq *iat_15888(%rip)");
}

/* 0x11a68 -> ppstub.dll!PPSTUB_ESPSAI. */
__attribute__((naked, used)) void thunk_11a68(void)
{
    __asm__("jmpq *iat_158a0(%rip)");
}

/* 0x11a6e -> ppstub.dll!PPSTUB_GCHEMI. */
__attribute__((naked, used)) void thunk_11a6e(void)
{
    __asm__("jmpq *iat_158a8(%rip)");
}

/* 0x11a74 -> ppstub.dll!PPSTUB_GM5ASI. */
__attribute__((naked, used)) void thunk_11a74(void)
{
    __asm__("jmpq *iat_158b0(%rip)");
}

/* 0x11a7a -> ppstub.dll!PPSTUB_GM18A. */
__attribute__((naked, used)) void thunk_11a7a(void)
{
    __asm__("jmpq *iat_158b8(%rip)");
}

/* 0x11a80 -> ppstub.dll!PPSTUB_HSEN0I. */
__attribute__((naked, used)) void thunk_11a80(void)
{
    __asm__("jmpq *iat_158c0(%rip)");
}

/* 0x11a86 -> ppstub.dll!PPSTUB_TG001I. */
__attribute__((naked, used)) void thunk_11a86(void)
{
    __asm__("jmpq *iat_158e0(%rip)");
}

/* 0x11a8c -> ppstub.dll!PPSTUB_HMU01I. */
__attribute__((naked, used)) void thunk_11a8c(void)
{
    __asm__("jmpq *iat_158e8(%rip)");
}

/* 0x11a92 -> ppstub.dll!PPSTUB_MULMH0. */
__attribute__((naked, used)) void thunk_11a92(void)
{
    __asm__("jmpq *iat_158f0(%rip)");
}

/* 0x11a98 -> ppstub.dll!PPSTUB_GMSA81. */
__attribute__((naked, used)) void thunk_11a98(void)
{
    __asm__("jmpq *iat_158f8(%rip)");
}

/* 0x11a9e -> ppstub.dll!PPSTUB_VL203. */
__attribute__((naked, used)) void thunk_11a9e(void)
{
    __asm__("jmpq *iat_15900(%rip)");
}

/* 0x11aa4 -> ppstub.dll!PPSTUB_INIT_IXWRAP. */
__attribute__((naked, used)) void thunk_11aa4(void)
{
    __asm__("jmpq *iat_15908(%rip)");
}

/* 0x11ab0 -> zeusermod.dll!UMOD_PPCHKU. */
__attribute__((naked, used)) void thunk_11ab0(void)
{
    __asm__("jmpq *iat_15cd8(%rip)");
}

/* 0x11ab6 -> zeusermod.dll!UMOD_USRVRN. */
__attribute__((naked, used)) void thunk_11ab6(void)
{
    __asm__("jmpq *iat_15ce0(%rip)");
}

/* 0x11abc -> atdms2.dll!DMS_NEWROY. */
__attribute__((naked, used)) void thunk_11abc(void)
{
    __asm__("jmpq *iat_15548(%rip)");
}

/* 0x11ac2 -> atdms2.dll!DMS_FPRSLV. */
__attribute__((naked, used)) void thunk_11ac2(void)
{
    __asm__("jmpq *iat_15540(%rip)");
}

/* 0x11ac8 -> aphier.dll!APHIERSTK_INIT_F. */
__attribute__((naked, used)) void thunk_11ac8(void)
{
    __asm__("jmpq *iat_15100(%rip)");
}

/* 0x11ace -> aphier.dll!APHIER_GETTOPCNTR_F. */
__attribute__((naked, used)) void thunk_11ace(void)
{
    __asm__("jmpq *iat_150f8(%rip)");
}

/* 0x11ad4 -> aphier.dll!APHIERSTK_PUSH_F. */
__attribute__((naked, used)) void thunk_11ad4(void)
{
    __asm__("jmpq *iat_150f0(%rip)");
}

/* 0x11ada -> rtmalloc.dll!RTO_MALLOC_INIT. */
__attribute__((naked, used)) void thunk_11ada(void)
{
    __asm__("jmpq *iat_15c70(%rip)");
}

/* 0x11ae0 -> ppeleci.dll!PPELCI_GM051E. */
__attribute__((naked, used)) void thunk_11ae0(void)
{
    __asm__("jmpq *iat_15650(%rip)");
}

/* 0x11ae6 -> pphysysprop.dll!PPHYSP_HYSPRPI. */
__attribute__((naked, used)) void thunk_11ae6(void)
{
    __asm__("jmpq *iat_15858(%rip)");
}

/* 0x11aec -> pphysysprop.dll!PPHYSP_GLYCOLI. */
__attribute__((naked, used)) void thunk_11aec(void)
{
    __asm__("jmpq *iat_15860(%rip)");
}

/* 0x11af2 -> ppedl.dll!PPEDL_ESESFI. */
__attribute__((naked, used)) void thunk_11af2(void)
{
    __asm__("jmpq *iat_15640(%rip)");
}

/* 0x11af8 -> ppedl.dll!PPEDL_ESELKI. */
__attribute__((naked, used)) void thunk_11af8(void)
{
    __asm__("jmpq *iat_15628(%rip)");
}

/* 0x11afe -> ppedl.dll!PPEDL_EDLPROPI. */
__attribute__((naked, used)) void thunk_11afe(void)
{
    __asm__("jmpq *iat_15630(%rip)");
}

/* 0x11b04 -> ppedl.dll!PPEDL_ESEDLI. */
__attribute__((naked, used)) void thunk_11b04(void)
{
    __asm__("jmpq *iat_15638(%rip)");
}

/* 0x11b0a -> libifcoremd.dll!for_write_int_fmt. */
__attribute__((naked, used)) void thunk_11b0a(void)
{
    __asm__("jmpq *iat_15570(%rip)");
}

/* 0x11b10 -> libifcoremd.dll!for_write_int_fmt_xmit. */
__attribute__((naked, used)) void thunk_11b10(void)
{
    __asm__("jmpq *iat_15558(%rip)");
}

/* 0x11b16 -> libifcoremd.dll!for_close. */
__attribute__((naked, used)) void thunk_11b16(void)
{
    __asm__("jmpq *iat_15560(%rip)");
}

/* 0x11b1c -> libifcoremd.dll!for_cpstr. */
__attribute__((naked, used)) void thunk_11b1c(void)
{
    __asm__("jmpq *iat_15568(%rip)");
}

/* 0x14704 -> KERNEL32.dll!GetModuleHandleA. */
__attribute__((naked, used)) void thunk_14704(void)
{
    __asm__("jmpq *iat_15020(%rip)");
}

/* 0x14782 -> VCRUNTIME140.dll!__std_type_info_destroy_list. */
__attribute__((naked, used)) void thunk_14782(void)
{
    __asm__("jmpq *iat_150c8(%rip)");
}

/* 0x14788 -> VCRUNTIME140.dll!__current_exception. */
__attribute__((naked, used)) void thunk_14788(void)
{
    __asm__("jmpq *iat_150e0(%rip)");
}

/* 0x1478e -> VCRUNTIME140.dll!__current_exception_context. */
__attribute__((naked, used)) void thunk_1478e(void)
{
    __asm__("jmpq *iat_150d8(%rip)");
}

/* 0x14794 -> VCRUNTIME140.dll!memset. */
__attribute__((naked, used)) void thunk_14794(void)
{
    __asm__("jmpq *iat_150d0(%rip)");
}

/* 0x147a0 -> api-ms-win-crt-runtime-l1-1-0.dll!_initterm. */
__attribute__((naked, used)) void thunk_147a0(void)
{
    __asm__("jmpq *iat_15178(%rip)");
}

/* 0x147a6 -> api-ms-win-crt-runtime-l1-1-0.dll!_initterm_e. */
__attribute__((naked, used)) void thunk_147a6(void)
{
    __asm__("jmpq *iat_15180(%rip)");
}

/* 0x147ac -> api-ms-win-crt-runtime-l1-1-0.dll!_seh_filter_dll. */
__attribute__((naked, used)) void thunk_147ac(void)
{
    __asm__("jmpq *iat_15160(%rip)");
}

/* 0x147b2 -> api-ms-win-crt-runtime-l1-1-0.dll!_configure_narrow_argv. */
__attribute__((naked, used)) void thunk_147b2(void)
{
    __asm__("jmpq *iat_15140(%rip)");
}

/* 0x147b8 -> api-ms-win-crt-runtime-l1-1-0.dll!_initialize_narrow_environment. */
__attribute__((naked, used)) void thunk_147b8(void)
{
    __asm__("jmpq *iat_15120(%rip)");
}

/* 0x147be -> api-ms-win-crt-runtime-l1-1-0.dll!_initialize_onexit_table. */
__attribute__((naked, used)) void thunk_147be(void)
{
    __asm__("jmpq *iat_15128(%rip)");
}

/* 0x147c4 -> api-ms-win-crt-runtime-l1-1-0.dll!_register_onexit_function. */
__attribute__((naked, used)) void thunk_147c4(void)
{
    __asm__("jmpq *iat_15130(%rip)");
}

/* 0x147ca -> api-ms-win-crt-runtime-l1-1-0.dll!_execute_onexit_table. */
__attribute__((naked, used)) void thunk_147ca(void)
{
    __asm__("jmpq *iat_15138(%rip)");
}

/* 0x147d0 -> api-ms-win-crt-runtime-l1-1-0.dll!_crt_atexit. */
__attribute__((naked, used)) void thunk_147d0(void)
{
    __asm__("jmpq *iat_15170(%rip)");
}

/* 0x147dc -> api-ms-win-crt-runtime-l1-1-0.dll!_cexit. */
__attribute__((naked, used)) void thunk_147dc(void)
{
    __asm__("jmpq *iat_15150(%rip)");
}

/* 0x147e2 -> api-ms-win-crt-runtime-l1-1-0.dll!terminate. */
__attribute__((naked, used)) void thunk_147e2(void)
{
    __asm__("jmpq *iat_15158(%rip)");
}

/* 0x147e8 -> api-ms-win-crt-environment-l1-1-0.dll!getenv. */
__attribute__((naked, used)) void thunk_147e8(void)
{
    __asm__("jmpq *iat_15110(%rip)");
}

/* 0x147ee -> api-ms-win-crt-runtime-l1-1-0.dll!exit. */
__attribute__((naked, used)) void thunk_147ee(void)
{
    __asm__("jmpq *iat_15168(%rip)");
}

/* 0x147f4 -> api-ms-win-crt-stdio-l1-1-0.dll!__stdio_common_vsprintf. */
__attribute__((naked, used)) void thunk_147f4(void)
{
    __asm__("jmpq *iat_151a0(%rip)");
}

/* 0x147fa -> api-ms-win-crt-string-l1-1-0.dll!strlen. */
__attribute__((naked, used)) void thunk_147fa(void)
{
    __asm__("jmpq *iat_151b8(%rip)");
}

/* 0x14800 -> api-ms-win-crt-string-l1-1-0.dll!strncpy. */
__attribute__((naked, used)) void thunk_14800(void)
{
    __asm__("jmpq *iat_151b0(%rip)");
}

/* 0x14806 -> api-ms-win-crt-stdio-l1-1-0.dll!__acrt_iob_func. */
__attribute__((naked, used)) void thunk_14806(void)
{
    __asm__("jmpq *iat_15190(%rip)");
}

/* 0x1480c -> api-ms-win-crt-stdio-l1-1-0.dll!__stdio_common_vfprintf. */
__attribute__((naked, used)) void thunk_1480c(void)
{
    __asm__("jmpq *iat_15198(%rip)");
}

