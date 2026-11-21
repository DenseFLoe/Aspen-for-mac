C   Written 10 August   1997 -- Nylon 6 user property subroutine
C
C   DEBUG UNIT(6), SUBTRACE, INIT
C   END DEBUG
C ---------------------------------------------------------------------
C     COPYRIGHT (C) 1994
C     ASPEN TECHNOLOGY, INC.
C     CAMBRIDGE, MA
C ---------------------------------------------------------------------
C
C     NAME OF MODULE: USR002
C
C     MODULE TITLE: NYLON-6 USER PROPERTY ROUTINE
C
C     PURPOSE: SAMPLE USER PROPERTY ROUTINE: CALCULATE POLY PROPS
C
C     WRITTEN BY: DAVID A TREMBLAY DATE WRITTEN: 10 August 1997
C
C     VARIABLES USED:
C
C       VARIABLES IN ARGUMENT LIST
C
C  VARIABLE  I/O  TYPE  DIMENSION   DESCRIPTION AND RANGE
C
C  T          I   R*8       -       STREAM TEMPERATURE (K)
C  P          I   R*8       -       STREAM PRESSURE    (NSQM)
C  FV         I   R*8       -       MOLAR VAPOR  FRACTION
C  FL         I   R*8       -       MOLAR LIQUID FRACTION
C  BETA       I   R*8       -       MOLAR RATIO L1/(L1 + L2)
C  NCP        I    I        -       NUMBER OF COMPONENTS PRESENT
C  IDX        I    I        -       COMPONENT INDEX VECTOR
C  FLOW       I    I        -       TOTAL MOLE FLOW OF STREAM
C  Y          I   R*8      NCP      PACKED VAPOR  COMPOSITION
C  X          I   R*8      NCP      PACKED LIQUID COMPOSITION
C  X1         I   R*8      NCP      PACKED LIQUID 1 COMPOSITION
C  X2         I   R*8      NCP      PACKED LIQUID 2 COMPOSITION
C  Z          I   R*8      NCP      PACKED MIXED PHASE COMPOSITION
C  NBOPST     I    I        6       PHYSICAL PROP OPTION SET VECTOR
C  KDIAG      I    I        -       SIMULATION DIAGNOSTIC LEVEL
C  KPDIAG     I    I        -       PROPERTIES DIAGNOSTIC LEVEL
C  XPCTLV     I   R*8       -       DISTILLATION CURVE LIQ VOLUME PCT
C  IPHASE     I    I        -       PHASE CODE:  SEE NOTES BELOW
C  NAME       I    H        2       PROPERTY NAME AS 2 INTEGER WORDS
C  VALUES     O   R*8       #       PROPERTY VALUE(S) SEE NOTE 3
C  SF         I   R*8       -       SOLID FRACTION ( 1 - FV - FL )
C  S          I   R*8      NCP      CISOLID:  SOLID MOLE FRACTIONS
C                                   NCSOLID:  SOLID MASS FRACTIONS
C  ISSTYP     I    I        -       SUBSTREAM TYPE (SEE BELOW)
C  CAT        I    I       (1)      COMPONENT ATTRIBUTE VECTOR
C  STREAM     I   R*8      (1)      STREAM VECTOR
C  NSUBS      I    I        -       NUMBER OF SUBSTREAMS
C  IDXSUB     I    I       NSUBS    LOCATION OF SUBSTREAMS IN STREAM
C  ITYPE      I    I       NSUBS    SUBSTREAM TYPE VECTOR (SEE BELOW)
C  XMW        I   R*8      NCC      COMPONENT MOLECULAR WEIGHTS
C  IDSCC      I    H       NCC      COMPONENT IDS AS 2 INTEGER WORDS
C  NSEG       I   INT       -       NUMBER OF SEGMENTS
C  IDXSEG     I   INT      NSUBS    SEGMENT INDEX VECTOR
C
C NOTES
C ------
C PHASE CODES:    |  SUBSTREAM TYPE  | NOTE 3:  # = - OR NCP
C                 |                  |
C 1 = VAPOR       | 1 = MIXED        | VALUES = SCALER VALUE FOR
C 2 = LIQUID      | 2 = CISOLID      |          MIXTURE PROPERTY OR
C 3 = SOLID       | 3 = NC           |          VECTOR OF DIMENSION
C 4 = LIQUID 1    |                  |          NCP FOR PROPERTIES
C 5 = MIXED       |                  |          OF COMPONENTS IN MIXTURE
C 6 = LIQUID 2    |                  |
C                 |                  |
C
C ---------------------------------------------------------------------
      SUBROUTINE USR002 (T     , P     , FV    , FL    , BETA  ,
     2                   NCP   , IDX   , FLOW  , Y     , X     ,
     3                   X1    , X2    , Z     , NBOPST, KDIAG ,
     4                   KPDIAG, XPCTLV, IPHASE, NAME  , VALUES,
     5                   SF    , S     , ISSTYP, CAT   , SOUT  ,
     6                   NSUBS , IDXSUB, ITYPE , XMW   , IDSCC ,
     7                   NSEG  , IDXSEG)
C ---------------------------------------------------------------------
      IMPLICIT NONE
C
C     DECLARE VARIABLES USED IN DIMENSIONING
C
      INTEGER NCP,   NSUBS
C
C     DECLARE PARAMETERS & VARIABLES USED IN PARAMETERS
C
      INTEGER NPROP
      PARAMETER ( NPROP=31 )
C ---------------------------------------------------------------------
C  COMMON BLOCKS AND DIMENSIONS
C ---------------------------------------------------------------------
#include "ppexec_user.cmn"
      EQUIVALENCE (RMISX, USER_RUMISS)
      EQUIVALENCE (IMISS, USER_IUMISS)
#include "dms_rglob.cmn"
#include "dms_ncomp.cmn"
C ---------------------------------------------------------------------
C     POLYMER COMMONS
C ---------------------------------------------------------------------
C
C     DECLARE ARGUMENTS
C
      INTEGER IDX(NCP),     NBOPST(6),    NAME(2),
     +        IDXSUB(NSUBS),ITYPE(NSUBS), IDSCC(2,1),
     +        IDXSEG(1),    IDZMOM(2),    IDSFLO(2),
     +        IDEVAP(2),    KDIAG, KPDIAG,IPHASE,
     +        ISSTYP,NSEG,  I,     ICL,   IACA
      INTEGER ICD,   IH2O,  INY6,  ITNH2, ITCOOH,
     +        IBACA, IAA,   ICHA,  IN2,   ISEG,
     +        IEVA,  JTNH2, JTCOOH,JBACA
      REAL*8 Y(NCP),X(NCP),X1(NCP),      X2(NCP),
     +       Z(NCP),VALUES(1),    S(NCP),CAT(1),
     +       SOUT(1),      XMW(1),T,     P,     FV,
     +       FL,    BETA,  FLOW,  XPCTLV,SF,
     +       FCL,   FACA,  FCD,   FH2O,  FN2
      REAL*8 EH2O,  ECL,   EACA,  EN2,   ECD
C
C
C     DECLARE SYSTEM FUNCTIONS
C
      INTEGER SHS_LCATT
C
C     DECLARE LOCAL VARIABLES
C
      INTEGER IPROG(2),     ID(2), IDPART(2),
     +        NAME2(5),     NAME3(5),     NAME4(5),
     +        NM(2,11),     NAMEP(14),     IMISS,
     +        NPOLY, IDXPOL,IMOM,  J
      REAL*8 RMISX, STOTAL,FNY6,  FAA,   FCHA,
     +       FTNH2, FTCOOH,FBACA, W_CL,  W_ACA,
     +       W_CD,  W_H2O, W_NY6, W_TNH2,W_TCOOH,
     +       W_BACA,W_N2,  VMASS, FLOMAS,FACID,
     +       FAMIN, FAMID, FCOO,  FNH,   FMONO
      REAL*8 ZEROTH,FTOTAL, MWN
      INTEGER IDMWN(2),IMWN
C
C      DATA STATEMENTS
C
C      COMMON /NPOLY1/ NPOLY, IDXPOL(3,1)
C ---------------------------------------------------------------------
C ---------------------------------------------------------------------
C     SPECIFY PROGRAM NAME AND PROPERTY NAMES AND COMPONENT NAMES
C ---------------------------------------------------------------------
      DATA IPROG  /'USR0','02  '/
      DATA IDZMOM /'ZMOM','    '/
      DATA IDSFLO /'SFLO','W   '/
      DATA IDMWN  /'MWN ','    '/
      DATA IDEVAP /'CAUS','RA  '/
C      DATA NM /'CL  ','    ','ACA ','    ','CD  ','    ','H2O ','    ',
C     1         'NYLO','N   ','T-NH','2   ','T-CO','OH  ','B-AC','A   ',
C     2         'AA  ','    ','CHA ','    ','N2  ','    '/
      DATA NM /'CL  ','    ','ACA ','    ','CD  ','    ','H2O ','    ',
     1         'NYLO','N6  ','AMIN','E-E ','ACID','-E  ','ACA-','R   ',
     2         'HAC ','    ','CHA ','    ','N2  ','    '/
      DATA NAMEP  / 'ACID','AMIN','AMID','X-AC','X-NH','C-AC','X-CL',
     1              'C-AA','C-CH','RV  ','C-H2','C-CL','C-CD','WT-X'/
      DATA NAME2 /'V-H2','V-CL','V-AC','V-N2','V-CD'/
      DATA NAME3 /'L-H2','L-CL','L-AC','L-N2','L-CD'/
      DATA NAME4 /'W-H2','W-CL','W-AC','W-N2','W-CD'/
C ---------------------------------------------------------------------
C     CALCULATE THE TOTAL MASS FLOW RATE AND SKIP THE ROUTINE IF ZERO
C ---------------------------------------------------------------------
  111 FORMAT (' USER PROPERTY ROUTINE DIAGNOSTICS:  ',2A4,' = ',G12.5)
C
C     BEGIN EXECUTABLE CODE
C
      STOTAL = SOUT( NCOMP_NCC+1 ) * SOUT( NCOMP_NCC+9 )
      IF ( STOTAL .LE. RGLOB_RMIN ) GO TO 999
C---------------------------------------------------------------------
C     INITIALIZE PROPERTY VALUE
C---------------------------------------------------------------------
      VALUES(1) = 0.D0
C---------------------------------------------------------------------
C     LOCATE POLYMER INDEX AND GET THE ATTRIBUTE OFFSETS
C---------------------------------------------------------------------
C      IF ( IH2O.EQ.0 ) THEN
C---------------------------------------------------------------------
C     LOCATE COMPONENT INDEX VALUES AND LIQUID MOLE FRACTIONS
C---------------------------------------------------------------------
       DO 200 I = 1, NCOMP_NCC
        IF (IDSCC(1,I).EQ.NM(1,1).AND.IDSCC(2,I).EQ.NM(2,1)) ICL   =I
        IF (IDSCC(1,I).EQ.NM(1,2).AND.IDSCC(2,I).EQ.NM(2,2)) IACA  =I
        IF (IDSCC(1,I).EQ.NM(1,3).AND.IDSCC(2,I).EQ.NM(2,3)) ICD   =I
        IF (IDSCC(1,I).EQ.NM(1,4).AND.IDSCC(2,I).EQ.NM(2,4)) IH2O  =I
        IF (IDSCC(1,I).EQ.NM(1,5).AND.IDSCC(2,I).EQ.NM(2,5)) INY6  =I
        IF (IDSCC(1,I).EQ.NM(1,6).AND.IDSCC(2,I).EQ.NM(2,6)) ITNH2 =I
        IF (IDSCC(1,I).EQ.NM(1,7).AND.IDSCC(2,I).EQ.NM(2,7)) ITCOOH=I
        IF (IDSCC(1,I).EQ.NM(1,8).AND.IDSCC(2,I).EQ.NM(2,8)) IBACA =I
        IF (IDSCC(1,I).EQ.NM(1,9).AND.IDSCC(2,I).EQ.NM(2,9)) IAA   =I
        IF (IDSCC(1,I).EQ.NM(1,10).AND.IDSCC(2,I).EQ.NM(2,10)) ICHA=I
        IF (IDSCC(1,I).EQ.NM(1,11).AND.IDSCC(2,I).EQ.NM(2,11)) IN2=I
 200    CONTINUE
       ISEG  = SHS_LCATT( 1, INY6, IDSFLO )
       IMOM  = SHS_LCATT( 1, INY6, IDZMOM )
       IMWN  = SHS_LCATT( 1, INY6, IDMWN )
       IEVA  = SHS_LCATT( 1, INY6, IDEVAP )
       MWN = SOUT( IMWN + 1 )
C---------------------------------------------------------------------
C     LOCATE SEGMENTS
C---------------------------------------------------------------------
       DO 300 J = 1, NSEG
         IF ( IDXSEG(J) .EQ. ITNH2  ) JTNH2  = J
         IF ( IDXSEG(J) .EQ. ITCOOH ) JTCOOH = J
         IF ( IDXSEG(J) .EQ. IBACA  ) JBACA  = J
 300    CONTINUE
C      END IF
C --------------------------------------------------------------------
C     Get total (all phases) mole flow rates of each component
C --------------------------------------------------------------------
C.....get component mole flow rates...
      IF ( ICL   .GT. 0 ) FCL   = SOUT( ICL   )
      IF ( IACA  .GT. 0 ) FACA  = SOUT( IACA  )
      IF ( ICD   .GT. 0 ) FCD   = SOUT( ICD   )
      IF ( IH2O  .GT. 0 ) FH2O  = SOUT( IH2O  )
      IF ( INY6  .GT. 0 ) FNY6  = SOUT( INY6  )
      IF ( IAA   .GT. 0 ) FAA   = SOUT( IAA   )
      IF ( ICHA  .GT. 0 ) FCHA  = SOUT( ICHA  )
      IF ( IN2   .GT. 0 ) FN2   = SOUT( IN2   )
C.....get segment mole flo rates...
      IF ( ISEG .GT. 0 ) THEN
        IF ( JTNH2  .GT. 0 ) FTNH2  = SOUT( ISEG + JTNH2  )
        IF ( JTCOOH .GT. 0 ) FTCOOH = SOUT( ISEG + JTCOOH )
        IF ( JBACA  .GT. 0 ) FBACA  = SOUT( ISEG + JBACA  )
C.......set missing values to zero...
        IF( FTNH2  .GE. RGLOB_RMISS ) FTNH2  = 0.D0
        IF( FTCOOH .GE. RGLOB_RMISS ) FTCOOH = 0.D0
        IF( FBACA  .GE. RGLOB_RMISS ) FBACA  = 0.D0
      END IF
C.....Get component molecular weights...
      IF ( ICL   .GT. 0 ) W_CL   = XMW( ICL   )
      IF ( IACA  .GT. 0 ) W_ACA  = XMW( IACA  )
      IF ( ICD   .GT. 0 ) W_CD   = XMW( ICD   )
      IF ( IH2O  .GT. 0 ) W_H2O  = XMW( IH2O  )
      IF ( INY6  .GT. 0 ) W_NY6  = XMW( INY6  )
      IF ( ITNH2 .GT. 0 ) W_TNH2 = XMW( ITNH2 )
      IF ( ITCOOH.GT. 0 ) W_TCOOH= XMW( ITCOOH)
      IF ( IBACA .GT. 0 ) W_BACA = XMW( IBACA )
      IF ( IN2   .GT. 0 ) W_N2   = XMW( IN2   )
C.....GET COMPONENT EVAPORATION RATES...
      IF ( IEVA .GT. 0 ) THEN
        EH2O  = SOUT( IEVA +1 )
        ECL   = SOUT( IEVA +2 )
        EACA  = SOUT( IEVA +3 )
        EN2   = SOUT( IEVA +4 )
        ECD   = SOUT( IEVA +5 )
C.......SET MISSING VALUES TO ZERO...
        IF( EH2O  .GE. RGLOB_RMISS ) EH2O  = 0.D0
        IF( ECL   .GE. RGLOB_RMISS ) ECL   = 0.D0
        IF( EACA  .GE. RGLOB_RMISS ) EACA  = 0.D0
        IF( EN2   .GE. RGLOB_RMISS ) EN2   = 0.D0
        IF( ECD   .GE. RGLOB_RMISS ) ECD   = 0.D0
C.......LIQUID FLOW RATES = TOTAL FLOW RATES - VAPOR FLOW...
        FH2O  = DMAX1( FH2O  - EH2O, 0.D0 )
        FCL   = DMAX1( FCL   - ECL,  0.D0 )
        FACA  = DMAX1( FACA  - EACA, 0.D0 )
        FN2   = DMAX1( FN2   - EN2,  0.D0 )
        FCD   = DMAX1( FCD   - ECD,  0.D0 )
        VMASS = ECL*W_CL + EH2O*W_H2O + EN2*W_N2 + EACA*W_ACA +
     1          ECD*W_CD
      END IF
C.....Mass flow rate of liquid portion of stream...
      FLOMAS = STOTAL - VMASS
C ---------------------------------------------------------------------
C     The following set of user properties, V-XXX, returns the mass
C     flow rate of each volatile component in the vapor stream (CAUSRA)
C     The L-XXX property returns the mass flow rate in the liquid
C ---------------------------------------------------------------------
      IF ( NAME(1).EQ.NAME2(1) ) VALUES(1) = EH2O * W_H2O
      IF ( NAME(1).EQ.NAME2(2) ) VALUES(1) = ECL  * W_CL
      IF ( NAME(1).EQ.NAME2(3) ) VALUES(1) = EACA * W_ACA
      IF ( NAME(1).EQ.NAME2(4) ) VALUES(1) = EN2  * W_N2
      IF ( NAME(1).EQ.NAME2(5) ) VALUES(1) = ECD  * W_CD
C
      IF ( NAME(1).EQ.NAME3(1) ) VALUES(1) = FH2O * W_H2O
      IF ( NAME(1).EQ.NAME3(2) ) VALUES(1) = FCL  * W_CL
      IF ( NAME(1).EQ.NAME3(3) ) VALUES(1) = FACA * W_ACA
      IF ( NAME(1).EQ.NAME3(4) ) VALUES(1) = FN2  * W_N2
      IF ( NAME(1).EQ.NAME3(5) ) VALUES(1) = FCD  * W_CD
C
      IF ( NAME(1).EQ.NAME4(1) ) VALUES(1) = FH2O * W_H2O * 1.D2/FLOMAS
      IF ( NAME(1).EQ.NAME4(2) ) VALUES(1) = FCL  * W_CL  * 1.D2/FLOMAS
      IF ( NAME(1).EQ.NAME4(3) ) VALUES(1) = FACA * W_ACA * 1.D2/FLOMAS
      IF ( NAME(1).EQ.NAME4(4) ) VALUES(1) = FN2  * W_N2  * 1.D2/FLOMAS
      IF ( NAME(1).EQ.NAME4(5) ) VALUES(1) = FCD  * W_CD  * 1.D2/FLOMAS
C ---------------------------------------------------------------------
C     PRELIMINARY CALCULATIONS
C ---------------------------------------------------------------------
C.....total mole flow rate of unreacted acid...
      FACID = FACA + FTCOOH + FAA
C.....total mole flow rate of unreacted amine...
      FAMIN = FACA + FTNH2  + FCHA
C.....total flow rate of amide groups...
      FAMID = FTCOOH + FBACA + FCL + 2.D0*FCD
C.....total mole flow rate of reacted and unreacted acid...
      FCOO  = FACA + FBACA + FTCOOH + FCL + 2.D0*FCD
C.....total mole flow rate of reacted and unreacted amine...
      FNH   = FACA + FBACA + FTNH2   + FCL + 2.D0*FCD
C.....total flow rate of reacted and unreacted CL monomer units...
      FMONO = FACA + FTNH2 + FBACA + FTCOOH + FCL + 2.D0*FCD
C.....zeroth flow rate of polymer...
C      ZEROTH = 0.5D0*( FTNH2 + FTCOOH )
      ZEROTH = SOUT( IMOM+1 )
C.....TRUE MOLECULE FLOW RATE OF STREAM (KMOL/SEC)...
      FTOTAL = ZEROTH + SOUT(NCOMP_NCC+1) - FNY6
C ---------------------------------------------------------------------
C     CALCULATE USER PROP-SET PROPERTIES
C ---------------------------------------------------------------------
C.....ACID Acid end group concentration, mmol/kg...
      IF ( NAME(1).EQ.NAMEP(1) ) THEN
        VALUES(1) = FACID * 1E6 / STOTAL
        GO TO 900
      END IF
C.....AMINE Amine end group concentration, mmol/kg...
      IF ( NAME(1).EQ.NAMEP(2) ) THEN
        VALUES(1) = FAMIN * 1E6 / STOTAL
        GO TO 900
      END IF
C.....AMIDE Amide group concentration, mmol/kg...
      IF ( NAME(1).EQ.NAMEP(3) ) THEN
        VALUES(1) = FAMID * 1E6 / STOTAL
        GO TO 900
      END IF
C.....X-COOH Acid group conversion (%)...
      IF ( NAME(1).EQ.NAMEP(4) ) THEN
        IF (FCOO.GT.RGLOB_RMIN) VALUES(1)=1.D2*( 1.D0 - FACID/FCOO )
        GO TO 900
      END IF
C.....X-NH2 Amine end group conversion (%)...
      IF ( NAME(1).EQ.NAMEP(5) ) THEN
        IF ( FNH.GT.RGLOB_RMIN ) VALUES(1)=1.D2*( 1.D0 - FAMIN/FNH )
        GO TO 900
      END IF
C.....X-CL Caprolactum monomer conversion (%)..
      IF ( NAME(1).EQ.NAMEP(7) ) THEN
        IF ( FMONO .GT. RGLOB_RMIN ) VALUES(1) = 1.D2*( 1.D0 -
     +      FCL / FMONO )
        GO TO 900
      END IF
C.....C-ACA  concentration of free ACA, mmol/kg
      IF ( NAME(1).EQ.NAMEP(6) ) THEN
        VALUES(1) = 1.D6 * FACA / STOTAL
        GO TO 900
      END IF
C.....C-AA  concentration of free AA, mmol/kg
      IF ( NAME(1).EQ.NAMEP(8) ) THEN
        VALUES(1) = 1.D6 * FAA / STOTAL
        GO TO 900
      END IF
C.....C-CHA  concentration of free CHA, mmol/kg
      IF ( NAME(1).EQ.NAMEP(9) ) THEN
        VALUES(1) = 1.D6 * FCHA / STOTAL
        GO TO 900
      END IF
C.....C-H2O  concetration of free water, mmol/kg
      IF ( NAME(1).EQ.NAMEP(11) ) THEN
        VALUES(1) = 1.D6 * FH2O / STOTAL
        GO TO 900
      END IF
C.....C-CL  concentration of free caprolactam, mmol/kg
      IF ( NAME(1).EQ.NAMEP(12) ) THEN
        VALUES(1) = 1.D6 * FCL / STOTAL
        GO TO 900
      END IF
C.....C-CD  concentration of cyclic dimer, mmol/kg
      IF ( NAME(1).EQ.NAMEP(13) ) THEN
        VALUES(1) = 1.D6 * FCD / STOTAL
        GO TO 900
      END IF
C.....WT-X weight percent exctractables, kg/100 kg
      IF ( NAME(1).EQ.NAMEP(14) ) THEN
        VALUES(1) = 1.D2*(FCL*W_CL+FACA*W_ACA+FCD*W_CD) / STOTAL
        GO TO 900
      END IF
C.....RV relative viscosity in 95% sulfuric acid
      IF ( NAME(1).EQ.NAMEP(10) ) THEN
        VALUES(1) = MWN / 10500.D0 + 1.D0
      END IF
C      IF ( NAME(1).EQ.NAMEP(10) ) THEN
C        VALUES(1) = 1.D2*(FCL*W_CL+FACA*W_ACA+FCD*W_CD) / STOTAL
C        GO TO 900
C      END IF
C --------------------------------------------------------------------
C     REPORT DIAGNOSTICS
C --------------------------------------------------------------------
  900 CONTINUE
      IF (KDIAG .GT. 7) WRITE (USER_NHSTRY,111) NAME(1),NAME(2)
     +   ,VALUES(1)
C
  999 RETURN
      END
