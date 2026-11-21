C$ #2 BY: RAMANATHAN DATE: 10-APR-1995 MODIFIED ARGUMENT LIST
C$ #1 BY: MOSIAS DATE: 13-FEB-1995 MOVE FREE-RAD FROM POL21
C$_POL20 #1 BY: MOSIAS DATE: 28-OCT-1994 MOVE USRGEL FROM POL13
C$_POL12 #1 BY: RAMANATHAN DATE: 9-APR-1993 USER GEL EFFECT CORRELS
C ---------------------------------------------------------------------
C     COPYRIGHT (C) 1993
C        ASPEN TECHNOLOGY, INC.
C        CAMBRIDGE, MA
C ---------------------------------------------------------------------
      SUBROUTINE USRGEL ( ICORR, MAXGP, GPAR, WTFRP, GF,
     +                    SOUT  ,NSUBS ,IDXSUB,ITYPE ,
     +                    NINTK ,INTK  ,NREALK,REALK ,
     +                    NPO   ,NBOPST,IDS   ,NCK   ,
     +                    NITG  ,ITG   ,NREA  ,REA   )
C
C***********************************************************************
C
C     NAME OF MODULE:  USRGEL
C
C     MODULE TITLE: USER GEL-EFFECT SUBROUTINE FOR LDPE Termination
C                   KINETICS
C
C     PURPOSE: TO CALCULATE THE GEL EFFECT FACTOR FOR THE FREE RADICAL
C              POLYMERIZATION KINETICS.
C
C     TASK, SUBSYSTEM, SYSTEM: GEL EFFECT, SIMULATION PROG., ASPEN
C
C     WRITTEN BY: S. RAMANATHAN         DATE WRITTEN:  8/2/00
C
C     READ BY:                          DATE READ:
C
C     APPROVED BY:                      DATE APPROVED:
C
C     CALLING SEQUENCE:
C
C          CALL USRGEL (
C
C     VARIABLES USED:
C
C      VARIABLE I/O TYPE-SPEC DIMENSION   DESCRIPTION AND RANGE
C
C       ICORR     I    I        --        GEL EFFECT CORRELATION NUMBER
C       MAXGP     I    I        --        MAX. NUMBER OF GEL EFFECT
C                                          PARAMETERS
C       GPAR      I    R       MAXGP      GEL EFFECT PARAMETERS
C       WTFRP     I    R        --        WEIGHT FRACTION OF POLYMER
C       GF        O    R        --        GEL EFFECT FACTOR
C
C       SOUT      I    R        (1)       OUTLET STREAM
C       NSUBS     I    I        --        NUMBER OF SUBSTREAMS
C       IDXSUB    I    I        NSUBS     LOCATION OF SUBSTREAMS
C                                          IN STREAM VECTOR
C       ITYPE     I    I        NSUBS     SUBSTREAM TYPE VECTOR
C                                           1: MIXED
C                                           2: CISOLID
C                                           3: NC
C       NINTK     I    I        --        NUMBER OF INTS. FOR MODEL
C       INTK     I/O   I        NINT      INTEGER ARRAY FOR MODEL
C       NREALK    I    I        --        NUMBER OF REALS FOR MODEL
C       REALK    I/O   R        NREAL     REAL ARRAY FOR MODEL
C       NPO       I    I        --        # OF PROPERTY OPTION SETS
C       NBOPST    I    I        6,NPO     PROPERTY OPTION SET ARRAY
C       IDS       I    I        2,13      BLOCK IDS:
C                                          I,1 BLOCK ID
C                                          I,2 TO I,4 USED BY SYSTM
C                                          I,5 KINETIC SUBR. NAME
C       NCK       I    I        --        TOTAL # OF COMPONENTS
C       NITG      I    I        --        NUMBER OF INTS FOR KINETIC
C       ITG       I    I        NITG      INTEGER ARRAY FOR KINETICS
C       NREA      I    I        --        NUMBER OF REALS FOR KINETIC
C       REA       I    R        NREA      REAL ARRAY FOR KINETICS
C
C***********************************************************************
C23456789012345678901234567890123456789012345678901234567890123456789012
C
C        SPECIFICATIONS, DECLARATIONS, DATA STATEMENTS, ETC.
C
C**      DOUBLE PRECISION
      IMPLICIT REAL*8 (A-H, O-Z) 
C
C     DECLARE VARIABLES USED IN DIMENSIONING
C
      INTEGER MAXGP, NSUBS, NINTK, NREALK,NPO,
     +        NITG,  NREA
C
#include "dms_ncomp.cmn"
#include "dms_rglob.cmn"
#include "dms_global.cmn"
#include "ppexec_user.cmn"
#include "dms_ipoff1.cmn"
#include "dms_errout.cmn"
#include "dms_plex.cmn"
      EQUIVALENCE (IB(1), B(1))
      REAL*8 B(1)
C
C         CHARACTER DECLARATIONS FOR FORTRAN-77
C
C F77-(8 LINES)
C
C     DECLARE ARGUMENTS
C
      INTEGER IDXSUB(NSUBS),ITYPE(NSUBS),
     +        INTK(NINTK),  IDS(2,1),     NBOPST(3,NPO),
     +        ITG(NITG),    ICORR, NCK
      REAL*8 SOUT(1),      REALK(NREALK),REA(NREA),
     +       GPAR(MAXGP),  WTFRP, GF,    TK
C
C
C     DECLARE SYSTEM FUNCTIONS
C
      INTEGER SHS_LCATT
C     DECLARE LOCAL VARIABLES
C
      INTEGER IPROG(2),     KFRRCS,KCIDBS,KPREBS,
     +        KACEBS,KACVBS,KFRRBS,KCI1TD,KCI2TD,
     +        KPRETD,KACETD,KACVTD,KFRRTD,KCI1TC,
     +        KCI2TC,KPRETC,KACETC,KACVTC,KFRRTC,
     +        KCI1IH,KCI2IH,KPREIH,KACEIH,KACVIH
      INTEGER KFRRIH,KCI1SB,KCI2SB,KPRESB,KACESB,
     +        KACVSB,KFRRSB,KCIISE,KCOEFA,KCOEFB,
     +        KCOEFC,KGETYP,KCORRN,KMAXPA,KGEPAR,
     +        KMECH, KQSSA, KQSSAZ,KQSSAF,KQSSAS,
     +        KRADI, KCI1TP,KCI2TP,KPRETP,KACETP
      INTEGER KACVTP,KFRRTP,KCI1IP,KCI2IP,KPREIP,
     +        KACEIP,KACVIP,KFRRIP,KESID, KESTYP,
     +        KRSID, KRSTYP,KMONOM,KBSID, KBSTYP,
     +        KDUM01,KDUM02,KDUM03,KDUM04,KDUM05,
     +        KDUM06,KDUM07,KDUM08,KDUM09,KDUM10
      INTEGER KDUM11,KDUM12,KDUM13,KDUM14,KDUM15,
     +        KDUM16,KDUM17,KDUM18,KDUM19,KDUM20
      REAL*8 A1, A2, AKT, AKP, BR, PRESS, Pp_MPa, VISE2, VISLDPE,
     +       MW_LDPE, MW_ETHYLENE, Fm_LDPE, Fm_ETHYLENE, Fmtot, Vmtot, 
     +       CM, RHOm, RGAS, RGAST, PRGAST
      INTEGER XMW, I_LDPE, I_ETHYLENE, DMS_KCCIDC, DMS_IFCMNC, I
	integer ICATYP(2,35), 
     & Loc_MW,	! Points to MW of a component in the plex
     & MWoffset   ! Offset of MW in the plex
      CHARACTER*80 IERW1(10), IERW2(9)
      CHARACTER*80 IERW3(8), IERW4(7), IERW5(6), IERW6(5)
      CHARACTER*80 IERW7(4), IERW8(3), IERW9(2), IERW10
      EQUIVALENCE (ERROUT_IEROUT(1),IERW1),(ERROUT_IEROUT(2)
     +            ,IERW2), (ERROUT_IEROUT(3),IERW3),(ERROUT_IEROUT(4)
     +            ,IERW4), (ERROUT_IEROUT(5),IERW5),(ERROUT_IEROUT(6)
     +            ,IERW6), (ERROUT_IEROUT(7),IERW7),(ERROUT_IEROUT(8)
     +            ,IERW8), (ERROUT_IEROUT(9),IERW9),(ERROUT_IEROUT(10)
     +            ,IERW10)
C
C         FOLLOWING EQUIVALENCES FOR FORTRAN-66
C
C F66-(3 LINES)
C     EQUIVALENCE (IERW1,NH),(IERW2,NH),(IERW3,NH),(IERW4,NH),
C    1            (IERW5,NH),(IERW6,NH),(IERW7,NH),(IERW8,NH),
C    2            (IERW9,NH),(IERW10,NH)
C
C-----------------------------------------------------------------------
C     DIMENSION STATEMENTS
C
C
C     DATA STATEMENTS
C
      DATA IPROG /'USRG', 'EL  ' /
       PARAMETER
     +    ( IDPN   =  1, IDPW   =  2, IDPZ   =  3, IPDI   =  4,
     +      IMWN   =  5, IMWW   =  6, IMWZ   =  7, IMWSEG =  8,
     +      IZMOM  =  9, IFMOM  = 10, ISMOM  = 11, ITMOM  = 12,
     +      ISFLOW = 13, ISFRAC = 14, IEFRAC = 15, ISEQL  = 16,
     +      ILCB   = 17, IFLCB  = 18, ISCB   = 19, IFSCB  = 20,
     +      ILDPN  = 21, ILDPW  = 22, ILPDI  = 23, ILMWN  = 24,
     +      ILMWW  = 25, ILMWSE = 26, ILZMOM = 27, ILFMOM = 28,
     +      ILSMOM = 29, ILSFLO = 30, ILSFRA = 31, ILEFLO = 32,
     +      ILEFRA = 33, ILSEQL = 34, ILPFRA = 35 )
C     DATA ICATYP CONTAINS ALL ATTRIBUTES TO BE REFERENCED HERE...
C
      DATA ((ICATYP(I,J), I=1,2), J=1,35)
     +   / 'DPN ','    ', 'DPW ','    ', 'DPZ ','    ', 'PDI ','    ',
     +     'MWN ','    ', 'MWW ','    ', 'MWZ ','    ', 'MWSE','G   ',
     +     'ZMOM','    ', 'FMOM','    ', 'SMOM','    ', 'TMOM','    ',
     +     'SFLO','W   ', 'SFRA','C   ', 'EFRA','C   ', 'SEQL','    ',
     +     'LCB ','    ', 'FLCB','    ', 'SCB ','    ', 'FSCB','    ',
     +     'LDPN','    ', 'LDPW','    ', 'LPDI','    ', 'LMWN','    ' ,
     +     'LMWW','    ', 'LMWS','EG  ', 'LZMO','M   ', 'LFMO','M   ',
     +     'LSMO','M   ', 'LSFL','OW  ', 'LSFR','AC  ', 'LEFL','OW  ',
     +     'LEFR','AC  ', 'LSEQ','L   ', 'LPFR','AC  ' /

C
C     FORMAT STATEMENTS
C
C=======================================================================
C
C     EXECUTABLE CODE
C
C.....FIND OUT GLOBAL PHYSICAL PROPERTY DATA
C      XMW(I) = LMW + I
C      LMW = IPOFF1(306)
	Loc_MW(i) = MWoffset + i
	MWoffset = DMS_IFCMNC('MW      ')

C.....Temperature and weight fraction
C
      TK = SOUT(NCK+2) 

C     INITIALIZE GF 
C 
      GF = 1.D0 

C-----------------------------------------------------------------------
C     ****** BEGIN USER SPECIFIED CORRELATION ******
C     ADD YOUR CORRELATION TO CALCULATE GF BELOW
C     NOTE: THE VALUE FOR GF SHOULD TYPICALLY BE BETWEEN 1.0 AND 0.0
C 
C     ****** BEGIN USER SPECIFIED CORRELATION ****** 
C 
C     ADD YOUR CORRELATION TO CALCULATE GF BELOW 
C     NOTE: THE VALUE FOR GF SHOULD TYPICALLY BE BETWEEN 1.0 AND 0.0 
C 
C     FOR EXAMPLE FRIIS AND HAMIELEC GEL EFFECT 
C        ACS SYMP. SER. 24, 82, (1976). 
C 
C     Following correlations from:
C     Villalobos,M.A.,Hamielec,A.E,and Wood, P.E.,
C     "Bulk and Suspension Polymerization of Styrene in the Presence of n-Pentane.  
C      An Evaluation of Monofunctional and Bifunctional Initiation"
C      J.Appl.Polym.Sci,50,327-343 (1993)

C......PROVIDE COMPONENT ID (COMPONENT ORDER IN COMPONENT DEF FORM) 
C
C     Get monomer, polymer and n-pentane component indices
      INC5 = DMS_KCCIDC('NPENTANE') 
	  IMON = DMS_KCCIDC('STY     ')
	  IPOL = DMS_KCCIDC('PS      ')
      IF(ICORR.EQ.3)THEN
C
C       EFFECT OF N-PENTANE ON CHAIN TRANSFER TO MONOMER
C
        WTFRAC = SOUT(INC5) *B(Loc_MW(INC5))/( SOUT(NCOMP_NCC+1) 
     +                                  * SOUT(NCOMP_NCC+9))
          IF(WTFRAC.GT.0.0001)THEN
            DPOL = (1249.25575 - 0.605*TK)/B(Loc_MW(IPOL)) !9.53712792 kmol/m3
	        DMON = (1174.7517 - 0.918*TK)/B(Loc_MW(IMON)) !7.9773185  kmol/m3
	        DNC5 = (953.56225 - 1.115*TK)/B(Loc_MW(INC5)) !7.58583569 kmol/m3
	        VMON = SOUT(IMON)/DMON
	        VPOL = SOUT(IPOL)/DPOL
	        VNC5 = SOUT(INC5)/DNC5
	        VTOT = VMON + VPOL + VNC5
	        VFNC5 = (0.025+0.00079*(TK-123))*VNC5/VTOT
	        ZD = GPAR(1)
            GF = DEXP (-(ZD*VFNC5))
	      ENDIF
      ELSEIF(ICORR.EQ.4)THEN
C
C         DIFFUSION LIMITED TERMINATION (GEL EFFECT)
C

          WTFRAC = SOUT(IPOL) *B(Loc_MW(IPOL))/( SOUT(NCOMP_NCC+1) 
     +                                  * SOUT(NCOMP_NCC+9))
          IF(WTFRAC.GT.0.01)THEN
            DPOL = (1249.25575 - 0.605*TK)/B(Loc_MW(IPOL)) !9.53712792 kmol/m3
	        DMON = (1174.7517 - 0.918*TK)/B(Loc_MW(IMON)) !7.9773185  kmol/m3
	        DNC5 = (953.56225 - 1.115*TK)/B(Loc_MW(INC5)) !7.58583569 kmol/m3
	        VMON = SOUT(IMON)/DMON
	        VPOL = SOUT(IPOL)/DPOL
	        VNC5 = SOUT(INC5)/DNC5
	        VTOT = VMON + VPOL + VNC5
            VFMON = (0.025+0.001*(TK-185))*VMON/VTOT
	        VFPOL = (0.025+0.00048*(TK-370))*VPOL/VTOT
	        VFNC5 = (0.025+0.00079*(TK-123))*VNC5/VTOT
	        VFTOT = VFMON + VFPOL + VFNC5
	        ZKCRIT = 9.44*DEXP(1929/TK)
            LMWW   = SHS_LCATT( 1, IPOL, ICATYP( 1, IMWW   )  )
            ZM = GPAR(1)
	        ZA = GPAR(2)
	        ZN = GPAR(3)
 	        ZK = (SOUT(LMWW+1))**ZM*DEXP(ZA/VFTOT)
            MWCRIT = GPAR(4) 
	        IF (ZK.GE.ZKCRIT) THEN
                IF (MWCRIT .eq. 0.D0) THEN 
                  GPAR(4)=SOUT(LMWW+1)
                  MWCRIT = GPAR(4)
                END IF    
              VFCRIT = ZA/DLOG((ZKCRIT/MWCRIT**ZM))
	          GF = (MWCRIT/(SOUT(LMWW+1)))**ZN
     +                        *DEXP(-ZA*(1/VFTOT-1/VFCRIT))
C				WRITE (USER_NHSTRY,*) 'ZK ',ZK,' ZKC ',ZKCRIT
C                WRITE (USER_NHSTRY, *) 'GF=',GF          
	        ENDIF
C	        IF (ZK.GE.ZKCRIT) THEN
C              IF (ICRIT.NE.123) THEN
C                ICRIT = 123
C	            MWCRIT = SOUT(LMWW+1)
C	            VFCRIT = VFTOT
C	          ENDIF
C	          GF = (MWCRIT/(SOUT(LMWW+1)))**ZN
C     +                        *DEXP(-ZA*(1/VFTOT-1/VFCRIT))
C	        ENDIF
          ENDIF
      ELSEIF(ICORR.EQ.5)THEN
C
C         DIFFUSION LIMITED PROPAGATION(GLASS EFFECT)
C

          WTFRAC = SOUT(IPOL) *B(Loc_MW(IPOL))/( SOUT(NCOMP_NCC+1) 
     +                                  * SOUT(NCOMP_NCC+9))
          IF(WTFRAC.GT.0.01)THEN
            DPOL = (1249.25575 - 0.605*TK)/B(Loc_MW(IPOL)) !9.53712792 kmol/m3
  	        DMON = (1174.7517 - 0.918*TK)/B(Loc_MW(IMON)) !7.9773185  kmol/m3
	        DNC5 = (953.56225 - 1.115*TK)/B(Loc_MW(INC5)) !7.58583569 kmol/m3
	        VMON = SOUT(IMON)/DMON
	        VPOL = SOUT(IPOL)/DPOL
	        VNC5 = SOUT(INC5)/DNC5
	        VTOT = VMON + VPOL + VNC5
            VFMON = (0.025+0.001*(TK-185))*VMON/VTOT
	        VFPOL = (0.025+0.00048*(TK-370))*VPOL/VTOT
	        VFNC5 = (0.025+0.00079*(TK-123))*VNC5/VTOT
	        VFTOT = VFMON + VFPOL + VFNC5
	        ZB = GPAR(1)
	        VFCRIT2 = GPAR(2)
            IF(VFTOT.LE.VFCRIT2) THEN
  	        GF = DEXP(-ZB*(1/VFTOT-1/VFCRIT2))
	      ENDIF
C	      WRITE (USER_NHSTRY, *) 'GF=',GF
          ENDIF
	ENDIF
 
C     ****** END OF USER SPECIFIED CORRELATION ****** 
C 
C     EXIT ROUTINE 
C
C     ****** END OF USER SPECIFIED CORRELATION ******
C-----------------------------------------------------------------------
C
C     EXIT ROUTINE
C
C 999  CONTINUE
      RETURN
#undef P_NPOFF1
      END

