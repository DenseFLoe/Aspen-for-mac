C   Written 10 August   1997 -- Nylon 6 user rate constant routine
C
C   This routine calculates total acid concentration for Nylon-6
C
C ---------------------------------------------------------------------
C     COPYRIGHT (C) 1997
C     ASPEN TECHNOLOGY, INC.
C     CAMBRIDGE,MA
C ---------------------------------------------------------------------
      SUBROUTINE URCNY6(
     1     SOUT,       NSUBS,      IDXSUB,     ITYPE,      XMW,
     2     IDSCC,      NPO,        NBOPST,     NIDS,       IDS,
     3     NINTB,      INTB,       NREALB,     REALB,
     4     NINTR,      INTR,       NREALR,     REALR,      NIWRK,
     5     IWRK,       NWRK,       WRK,        NCPMX,      IDXM,
     6     X,          X1,         X2,         Y,          DUMXS,
     7     VLQ,        VLQ1,       VLQ2,       VVP,        VOLSLT,
     8     IPOLY,      NSEG,       IDXSEG,     NOLIG,      IDXOLI,
     9     NSGOLG,     NGROUP,     IDGRP,      NSPEC,      IDXSPC,
     *     NFGSPC,     CSS,        CGROUP,     TEMP,       PRES,
     1     NURC,       RCUSER      )
C ---------------------------------------------------------------------
C
C  MODULE:       STEP-GROWTH REACTION KINETICS MODEL
C  ROUTINE:      USER RATE-CONSTANT SUBROUTINE FOR PET
C  WRITTEN BY:   DAVID TREMBLAY       DATE: AUGUST 1995
C
C  CALL TREE:
C
C  STEPG--|--> USER             > USER MASS-TRASNFER SUBROUTINE
C         |--SGMECH--|--SGXPLD  > COMPONENT BASIS-->SEGMENT BASIS
C                    |--> USER  > USER RATE CONSTANT SUBROUTINE
C                    |--SGPLAW  > RTN RATES LOCAL POWER-LAW RXNS
C                    |--SGRATC  > RTN NET RATE CONSTANTS SG RXNS
C                    |--SGRXRT  > RTN RATES STEP-GROWTH RXNS
C                    |--> USER  > USER KINETICS SUBROUTINE
C                    |--SGMPLD  > SEGMENT BASIS-->COMPONENT BASIS
C
C  DESCRIPTION:  USE THIS OPTIONAL, USER-WRITTEN SUBROUTINE TO SUPPLY
C                USER-CALCULATED RATE CONSTANTS TO THE POLYMERS PLUS
C                STEP-GROWTH REACTION KINETICS MODEL.
C
C                THE STEP-GROWTH MODEL MULTIPLIES THE STANDARD RATE
C                EXPRESSION BY THE USER-SUPPLIED CONSTANT.
C
C                USER RATE CONSTANTS ARE INVOKED BY ENTERING A FLAG
C                IN THE USER-RC BOXES IN THE SG-RATE-CON AND RATE-CON
C                FORMS OF THE STEP-GROWTH REACTIONS MODEL
C
C ---------------------------------------------------------------------
C  ARGUMENT LIST:  REFER TO THE ASPEN PLUS GUIDE TO USER MODELS FOR
C                  MORE DETAILED DESCRIPTIONS OF KEY ARGUMENTS
C
C   VARIABLE  USE  TYPE  DIMENSION     DESCRIPTION
C   --------  ---  ----  -----------   --------------------------------
C   SOUT       I   DBL   (1)           OUTLET STREAM
C   NSUBS      I   INT   -             NUMBER OF SUBSTREAMS
C   IDXSUB     I   INT   NSUBS         LOCATION OF SUBSTREAMS IN SOUT
C   ITYPE      I   INT   NSUBS         SUBSTREAM TYPE VECTOR
C                                        1: MIXED
C                                        2: CISOLID
C                                        3: NCSOLID
C   XMW        I   DBL   -             CONVENTIONAL COMPONENT MW
C   IDSCC      I   I*4   2,(1)         CONVENTIONAL COMPONENT IDS
C   NPO        I   INT   -             # OF PROPERTY OPTION SETS
C   NIDS       I   INT   --            NUMBER OF BLOCK IDS
C   IDS        I   I*4   2,NIDS        BLOCK IDS:
C                                        I,1 REACTOR BLOCK ID
C                                        I,2 REACTOR BLOCK TYPE
C                                        I,3 REACTION PARAGRAPH ID
C                                        I,4 REACTION PARAGRAPH TYPE
C                                        I,5 THIS SUBROUTINE ID
C   NBOPST     I   INT   6,NPO         PROPERTY OPTION SET ARRAY
C   NINTB      I   INT   --            SIZE OF INTK VECTOR FROM BLOCK
C   INTB      I/O  INT   NINTB         INTK VECTOR FROM BLOCK
C   NREALB     I   INT   --            SIZE OF REALK VECTOR FROM BLOCK
C   REALB     I/O  DBL   NREALB        REALK VECTOR FROM BLOCK
C   NINTR      I   INT   --            SIZE OF INTRC VECTOR FROM RXNS
C   INTR      I/O  INT   NINTR         INTRC VECTOR FROM RXNS
C   NREALR     I   INT   --            SIZE OF REALRC VECTOR FROM RXNS
C   REALR     I/O  DBL   NREALR        REALRC VECTOR FROM RXNS
C   NPO        I   INT   --            # OF PROPERTY OPTION SETS
C   NBOPST     I   INT   6,NPO         PROPERTY OPTION SET ARRAY
C   NCPMX      I   INT   --            NUMBER COMPS PRESENT IN MIXED SS
C   IDXM       I   INT   NCPMX         INDEX VECTOR OF MIXED SS COMPS
C   X          I   DBL   NCPMX         LIQUID  PHASE MOLE FRACTIONS*
C   X1         I   DBL   NCPMX         LIQUID1 PHASE MOLE FRACTIONS*
C   X2         I   DBL   NCPMX         LIQUID2 PHASE MOLE FRACTIONS*
C   Y          I   DBL   NCPMX         VAPOR   PHASE MOLE FRACTIONS*
C   DUMXS**    I   DBL   NCPMX         SALT PHASE MOLE FRACTIONS
C   VLQ        I   DBL   --            LIQUID  MOLE VOLUME, M^3/MOL
C   VLQ1       I   DBL   --            LIQUID1 MOLE VOLUME, M^3/MOL
C   VLQ2       I   DBL   --            LIQUID2 MOLE VOLUME, M^3/MOL
C   VVP        I   DBL   --            VAPOR   MOLE VOLUME, M^3/MOL
C   VOLSLT     I   DBL   --            SALT    MOLE VOLUME, M^3/MOL
C   IPOLY      I   INT   -             REACTING POLYMER COMPONENT INDEX
C   NSEG       I   INT   -             NUMBER OF SEGMENTS
C   IDXSEG     I   INT   NSEG          SEGMENT INDEX VECTOR
C   NOLIG      I   INT   -             NUMBER OF OLIGOMERS
C   IDXOLI     I   INT   NOLIG         INDEX VECTOR OF OLIGOMERS
C   NSGOLG     I   INT   NSEG,NOLIG    MATRIX OF SEGS / OLIGOMER
C   NGROUP     I   INT   -             NUMBER OF FUNCTIONAL GROUPS
C   IDGRP      I   I*4   2,NGROUP      FUNCTIONAL GROUP NAMES
C   NSPEC      I   INT   -             NUMBER OF REACTING SPECIES
C   IDXSPC     I   INT   NSPEC         INDEX VECTOR OF SPECIES
C   NFGSPC     I   INT   NSPEC,NGROUP  MATRIX OF GROUPS/SPECIES
C   CSS        I   DBL   NCC           RXN PHASE COMP. CONC., KMOL/M^3
C   CGROUP     I   DBL   NGROUP        GROUP CONCENTRATIONS, KMOL/CUM
C   TEMP       I   DBL   -             TEMPERATURE, DEG K
C   PRES       I   DBL   -             PRESSURE, PASCAL
C   NURC       I   INT   -             NUMBER OF USER RATE CONSTANTS$
C   RCUSER     O   DBL   NURC          VECTOR OF USER RATE CONSTANTS
C
C   NOTES:   * THESE VECTORS ARE PACKED AGAINST NCPM BY FLASH / CPACK
C           ** THESE SALT VECTORS AND SCALERS ARE NOT IMPLEMENTED YET
C            $ SPECIFIED IN THE STEP-GROWTH.SUBROUTINE FORM
C
C ---------------------------------------------------------------------
C  KEY LOCAL ARGUMENTS:
C
C   VARIABLE  USE  TYPE  DIMENSION     DESCRIPTION
C   --------  ---  ----  -----------   --------------------------------
C
C ======================================================================
C     DECLARATIONS
C ======================================================================
      IMPLICIT NONE
C
C     DECLARE VARIABLES USED IN DIMENSIONING
C
      INTEGER NSUBS, NPO,   NINTB, NREALB,NINTR,
     +        NREALR,NIWRK, NWRK,  NCPMX, NSEG,
     +        NOLIG, NGROUP,NSPEC, NURC
C
C     ASPEN PLUS COMMONS (do not modify)
C
#include "dms_ncomp.cmn"
C
#include "dms_rglob.cmn"
#include "ppexec_user.cmn"
C
C     DECLARE ARGUMENTS
C
      INTEGER IDSCC(2,1),   IDXSUB(NSUBS),
     +        ITYPE(NSUBS), INTB(NINTB),  IDS(2,1),
     +        NBOPST(6,NPO),IWRK(NIWRK),  INTR(NINTR),
     +        IDGRP(2,NGROUP),     IDXSPC(NSPEC),
     +        NFGSPC(NSPEC,NGROUP),IDXOLI(NOLIG)
      INTEGER IDXSEG(NSEG), NSGOLG(NSEG,NOLIG),
     +        IDXM(NCPMX),  NIDS,  IPOLY, I,     IH2O,
     +        IACA,  ITCO,  ITNH,  ICL,   ICD,
     +        IAA,   ICHA,  J
      REAL*8 XMW(1),SOUT(1),      REALB(NREALB),
     +       WRK(NWRK),    CSS(1),CGROUP(1),
     +       RCUSER(NURC), REALR(NREALR),X(1),  X1(1),
     +       X2(1), Y(1),  DUMXS(1),     VLQ,   VLQ1,
     +       VLQ2,  VVP,   VOLSLT,TEMP,  PRES
      REAL*8 CH2O,  TOTCON, DEN1, DEN2
C
C
C     DECLARE LOCAL VARIABLES
C
      INTEGER IPROG(2),     IDACA(2),     IDTCO(2),  IDNY6(2),     
     +        MKPHAS,MTAPP, MKBASS,MTAPPS,NCPM,IDZMOM(2),IDTNH(2)
      INTEGER IDREP(2),IREP,CREP
      INTEGER NCPCS, NCPNC, INY6,  JAC, MKBAS
      REAL*8 B(1),  SSALT, VSALT, FSALT, TCALC,
     +       PCALC, VCALC, QCALC, BETCAL,CACA,
     +       CCL,   CTCO,  CTNH,  CCD,   CAA,
     +       CCHA,  ZMOMCN,CACID0,CACID
      REAL*8 ALPHAW
      REAL*8 DUMMY(2)
      EQUIVALENCE (DUMMY, RGLOB_CONVFL)
#include "dms_global.cmn"
#include "dms_flscom.cmn"
#include "dms_rptglb.cmn"
#include "shs_stwork.cmn"
      EQUIVALENCE (MKBAS, STWORK_NDUM)
      EQUIVALENCE (MKPHAS, STWORK_NBLM)
      EQUIVALENCE (MTAPP, STWORK_NCOVAR)
      EQUIVALENCE (MKBASS, STWORK_NWR)
      EQUIVALENCE (MTAPPS, STWORK_NIWR)
      EQUIVALENCE (SSALT, STWORK_RDUM1)
      EQUIVALENCE (VSALT, STWORK_RDUM2)
      EQUIVALENCE (FSALT, STWORK_FFSALT)
#include "dms_stwkwk.cmn"
      INTEGER IDUM3(2)
      REAL*8 RDUM(21)
      EQUIVALENCE (NCPM, STWKWK_NCPMOO)
      EQUIVALENCE (NCPCS, STWKWK_NCPCSO)
      EQUIVALENCE (NCPNC, STWKWK_NCPNCO)
      EQUIVALENCE (IDUM3(1), STWKWK_KRSTRT)
      EQUIVALENCE (IDUM3(2), STWKWK_IDUMY)
      EQUIVALENCE (TCALC, STWKWK_TCALC)
      EQUIVALENCE (PCALC, STWKWK_PCALC)
      EQUIVALENCE (VCALC, STWKWK_VCALC)
      EQUIVALENCE (QCALC, STWKWK_QCALC)
      EQUIVALENCE (BETCAL, STWKWK_BETA)
      EQUIVALENCE (RDUM(1), STWKWK_T)
      EQUIVALENCE (RDUM(2), STWKWK_P)
      EQUIVALENCE (RDUM(3), STWKWK_VFRAC)
      EQUIVALENCE (RDUM(4), STWKWK_Q)
      EQUIVALENCE (RDUM(5), STWKWK_TINIT)
      EQUIVALENCE (RDUM(6), STWKWK_PINIT)
      EQUIVALENCE (RDUM(7), STWKWK_DD(1))
      EQUIVALENCE (RDUM(8), STWKWK_DD(2))
      EQUIVALENCE (RDUM(9), STWKWK_DD(3))
      EQUIVALENCE (RDUM(10), STWKWK_DD(4))
      EQUIVALENCE (RDUM(11), STWKWK_DD(5))
      EQUIVALENCE (RDUM(12), STWKWK_DD(6))
      EQUIVALENCE (RDUM(13), STWKWK_DD(7))
      EQUIVALENCE (RDUM(14), STWKWK_DD(8))
      EQUIVALENCE (RDUM(15), STWKWK_DD(9))
      EQUIVALENCE (RDUM(16), STWKWK_DD(10))
      EQUIVALENCE (RDUM(17), STWKWK_DD(11))
      EQUIVALENCE (RDUM(18), STWKWK_DD(12))
      EQUIVALENCE (RDUM(19), STWKWK_DD(13))
      EQUIVALENCE (RDUM(20), STWKWK_DD(14))
      EQUIVALENCE (RDUM(21), STWKWK_DD(15))
#include "dms_ipoff1.cmn"
C
#include "dms_plex.cmn"
      EQUIVALENCE (IB(1), B(1))
#include "dms_errout.cmn"
C
C         CHARACTER DECLARATIONS FOR FORTRAN-77
C
C F77-(8 LINES)
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
C     DIMENSIONS
C
C
C     DATA STATEMENTS - ASPEN STORES STRINGS AS TWO INTEGER WORDS
C
C      DATA IDACA  /'ACA ','    '/
C      DATA IDTCO  /'T-CO','OH  '/
C      DATA IDTNH  /'T-NH','2   '/
C      DATA IDREP  /'B-AC','A   '/
C      DATA IDTCO  /'T-CO','OH  '/
C ... new component names ...
      DATA IDACA  /'ACA ','    '/
      DATA IDTCO  /'ACID','-E  '/
      DATA IDTNH  /'AMIN','E-E '/
      DATA IDREP  /'ACA-','R   '/
C      DATA IDNY6  /'NYLO','N6  '/
C      DATA IDHAC  /'HAC ','    '/
C   - name of group corresponding to acid ends -
C      DATA ID_AC  /'ACID','    '/
C      DATA IDZMOM /'ZMOM','    '/
C ======================================================================
C     EXECUTABLE CODE
C ======================================================================
C
C     locate ethylene glycol and water in the list of components
C
      DO 10 I = 1, NCOMP_NCC
       IF ( IDSCC(1,I).EQ.IDACA(1).AND.IDSCC(2,I).EQ.IDACA(2) ) IACA=I
       IF ( IDSCC(1,I).EQ.IDTCO(1).AND.IDSCC(2,I).EQ.IDTCO(2) ) ITCO=I
       IF ( IDSCC(1,I).EQ.IDTNH(1).AND.IDSCC(2,I).EQ.IDTNH(2) ) ITNH=I
       IF ( IDSCC(1,I).EQ.IDREP(1).AND.IDSCC(2,I).EQ.IDREP(2) ) IREP=I
 10   CONTINUE
C
C     get the concentrations of these species
C
      CACA = 0.0D0
      CTCO = 0.0D0
C
      IF ( IACA .GT.0 ) CACA  = CSS( IACA )
      IF ( ITCO .GT.0 ) CTCO  = CSS( ITCO )
C
C     locate acid group in the list of groups
C
C      DO 20 J = 1, NGROUP
C       IF ( IDGRP(1,J).EQ.ID_AC(1).AND.IDGRP(2,J).EQ.ID_AC(2) ) JAC =J
C 20   CONTINUE
C
C
C     get concentrations of COOH (exclude groups in H2O)
C
C       CACID = CGROUP( JAC ) - CSS( IH2O )
C
C     concentration of acid = concentration of ACA + ACID-E
C
       CACID  = CACA + CTCO
C ----------------------------------------------------------------------
C  FLAG=1  acid catalyzed reaction, U(1) = [acid] 
C ----------------------------------------------------------------------
      RCUSER(1) = CACID
C ----------------------------------------------------------------------
C  FLAG=2  probabilty that chain with amine end is dimer
C
C          U(2) = [ACID-E]/( [ACID-E] + [ACA-R] )
C ----------------------------------------------------------------------
      IF ( NURC.LT.2 ) GO TO 999
      DEN1 = CSS( ITCO ) + CSS( IREP )
      DEN2 = CSS( ITNH ) + CSS( IREP )
      IF ( DEN1.GT.RGLOB_RMIN) THEN
        RCUSER(2) = CSS( ITCO ) / DEN1
      ELSE
        RCUSER(2) = 0.D0
      END IF
C ----------------------------------------------------------------------
C  FLAG=3 Same as Flag 2 but including acid catalysis term
C
C          U(3) = [ACID ] * [ACID-E]/( [ACID-E] + [ACA-R] )
C ----------------------------------------------------------------------
      IF ( NURC.LT.3 ) GO TO 999
      RCUSER(3) = CACID * RCUSER(2)
C ----------------------------------------------------------------------
C  FLAG=4  probabilty that chain with amine end larger than dimer
C
C          U(4) = [ACA-R] /( [ACID-E] + [ACA-R] )
C ----------------------------------------------------------------------
      IF ( NURC.LT.4 ) GO TO 999
      IF ( DEN1.GT.RGLOB_RMIN) THEN
        RCUSER(4) = CSS( IREP ) / DEN1
      ELSE
        RCUSER(4) = 0.D0
      END IF
C ----------------------------------------------------------------------
C  FLAG=5 Same as Flag 5 but including acid catalysis term
C
C          U(5) = [ACID ] * [ACA-R]/( [ACID-E] + [ACA-R] )
C ----------------------------------------------------------------------
      IF ( NURC.LT.5 ) GO TO 999
      RCUSER(5) = CACID * RCUSER(4)
C ----------------------------------------------------------------------
C  FLAG=6  probabilty that chain with amine end is linear trimer
C
C   U(6) = ([ACA-R]/([ACID-E]+[ACA-R]))*([ACID-E]/([ACID-E]+[ACA-R])
C ----------------------------------------------------------------------
      IF ( NURC.LT.6 ) GO TO 999
      IF ( DEN1.GT.RGLOB_RMIN) THEN
        RCUSER(6) = ( CSS( IREP ) / DEN1 ) * ( CSS( ITCO ) / DEN1 )
      ELSE
        RCUSER(6) = 0.D0
      END IF
C ----------------------------------------------------------------------
C  FLAG=7 Same as Flag 6 but including acid catalysis term
C ----------------------------------------------------------------------
      IF ( NURC.LT.7 ) GO TO 999
      RCUSER(7) = CACID * RCUSER(6)
C ----------------------------------------------------------------------
C  FLAG=8  probabilty that chain with amine end larger than trimer
C
C   U(8) = ([ACA-R]/([ACID-E]+[ACA-R]))^2
C ----------------------------------------------------------------------
      IF ( NURC.LT.7 ) GO TO 999
      IF ( DEN1.GT.RGLOB_RMIN) THEN
        RCUSER(8) = ( CSS( IREP ) / DEN1 )**2.D0
      ELSE
        RCUSER(8) = 0.D0
      END IF
C ----------------------------------------------------------------------
C  FLAG=9 Same as Flag 8 but including acid catalysis term
C ----------------------------------------------------------------------
      IF ( NURC.LT.9 )  GO TO 999
      RCUSER(9) = CACID * RCUSER(8)
C ----------------------------------------------------------------------
C      WRITE (USER_NHSTRY,*) 'RCUSER> ',RCUSER(1)
 999  CONTINUE
      RETURN
#undef P_NPOFF1
      END

