C     Dave Humbird, Jun 2022. Prepared for AspenTech.
C
C     RYIELD Subroutine for converting solid biocomponents to 
C     base components
C
C
      SUBROUTINE BFDYLD (SIN,SOUT, NSUBS,IDXSUB,ITYPE,NINT,INTS_IN,
     1                   NREAL,REALS_IN,IDS,NPO,NBOPST,NIW,IW,NW,W)
C
      IMPLICIT NONE
C
C     DECLARE VARIABLES USED IN DIMENSIONING
C
      INTEGER NSUBS, NINT,  NPO, NIW, NW
C
C ***************** # INCLUDE STATEMENTS *************************
C THESE ARE ASPEN PLUS COMMON BLOCKS
C USED BY VARIOUS UTILITIES WITHIN THE SUBROUTINE
C
#include "ppexec_user.cmn"
#include "dms_ncomp.cmn"
#include "dms_rglob.cmn"
#include "dms_plex.cmn"
#include "dms_maxwrt.cmn"
#include "dms_errout.cmn"
C
C
C *********************************************************
C                  DECLARATIONS & COMMONS
C *********************************************************
C
C ********* REAL VARIABLES/FUNCTIONS************************
C (DESCRIPTIONS OF FUNCTIONS ABOVE)
      REAL*8 PPUTL_AVEMW
      REAL*8 SIN(1),SOUT(1), W(NW), STOTAL
      REAL*8 REALS_IN(NREAL), RMISS, MW(NCOMP_NCC)
      REAL*8 B(1), BNO, SUMBNO
C
C ********** INTEGER VARIABLES/FUNCTIONS*********************
      INTEGER IPROG(2),  IMISS, DMS_IRRCHK
      INTEGER DMS_LOCATI, DMS_KCCIDC, DMS_KNCIDC, DMS_IFCMNC
      INTEGER I, J, LMW, LBIOPOS, LBIOCMP, LBIOID, LBIONO
      INTEGER IDXSUB(NSUBS),ITYPE(NSUBS), INTS_IN(NINT),
     +        IDS(2,13),    NBOPST(6,NPO),
     +        IW(NIW),NREAL
      INTEGER JBID, BID
      INTEGER IBIOPOS(NCOMP_NCC)
C REVBIOP must be dimensioned larger than the number of possible biobase
C components (19 in V14).
      INTEGER REVBIOP(50)
C *****************CHARACTER VALUES *****************************
      CHARACTER*256 BUFFER(14)
C
C ***************** EQUIVALENCE STATEMENTS *************
      EQUIVALENCE (RMISS, USER_RUMISS)
      EQUIVALENCE (IMISS, USER_IUMISS)
      EQUIVALENCE (IB(1), B(1))
      EQUIVALENCE (IERROUT, ERROUT_IEROUT)
      CHARACTER*80 IERROUT(10), IERW1(10), IERW2(9), IERW3(8)
     +             , IERW4(7), IERW5(6), IERW6(5), IERW7(4), IERW8(3)
     +             , IERW9(2), IERW10

      EQUIVALENCE (IERROUT(1), IERW1), (IERROUT(2), IERW2),
     +            (IERROUT(3), IERW3), (IERROUT(4), IERW4),
     +            (IERROUT(5), IERW5), (IERROUT(6), IERW6),
     +            (IERROUT(7), IERW7), (IERROUT(8), IERW8),
     +            (IERROUT(9), IERW9), (IERROUT(10), IERW10)
      DATA IPROG /4HUSRP, 4HYR  /
C
C ************** BEGIN EXECUTABLE CODE ***************
C
C Plex locations for the properties we need
C
      LBIOID = DMS_ifcmnc('BIOID')
      LBIONO = DMS_ifcmnc('BIONO')
      LMW= DMS_IFCMNC('MW')
      LBIOPOS= DMS_IFCMNC('BIOPOS')
      LBIOCMP= DMS_IFCMNC('BIOCOMP')
C
C REVBIOP is a reverse lookup array for BIOPOS. When we later read
C a BIOID from the biomass component, the REVBIOP will tell us
C which component in the main list has that BIOPOS, without needing 
C the component name. The first loop builds the reverse lookup. It 
C also copies the inlet component flows to the outlet.
C
      DO I=1,50
        REVBIOP(I)=0
      END DO
      DO 100 I = 1, NCOMP_NCC
        SOUT(I) = SIN(I) 
        MW(I) = B(LMW+I)
        if (B(LBIOPOS+I).NE.RMISS) then
          IBIOPOS(I) = INT(B(LBIOPOS+I))
          REVBIOP(IBIOPOS(I))=I
        else
          IBIOPOS(I) = IMISS
        endif
 100  CONTINUE
C 
C Next we go through each component in the stream. To find solid 
C biofeedstock components, BIONO is added up. Only feedstock components
C will have a nonzero sum. These components will be destroyed (SOUT=0) 
C and the base component flows will be *incremented* by flow*BIONO. 
C This avoids destroying any base components that may enter the 
C converter by (e.g.) recycle. Any non-biocomponents will retain their 
C SIN flow as copied in the first loop. Note that BIONO is a mass 
C fraction, so a MW conversion is performed. 
C 
C A check is performed to make sure sum(BIONO) is close to 1.
C A warning will be thrown if the deviation is >1%.
C The BIOID vector will be normalized either way.
C
C A 2nd check is performed to make sure that each requested BIOID is 
C present in the componentlist. If a component is not found, calculation
C will abort.
C
      DO 101 I = 1, NCOMP_NCC
        SUMBNO=0
        DO j=1,12
          SUMBNO = SUMBNO + B(LBIONO+(i-1)*12 + j)
        end do
        if (SUMBNO.GT.0) then
          SOUT(I)=0
          if ((SUMBNO.LT.0.99).OR.(SUMBNO.GT.1.01)) then 
            IF (DMS_IRRCHK(IPROG,3,9002,USER_LMSG,IMISS,0,0,2)
     +          .NE. 0) THEN 
              WRITE(IERW1,165), 1./SUMBNO
              CALL DMS_ERRPRT(2)
            END IF
          endif
          DO j=1,12
            BID = int(B(LBIOID+(i-1)*12 + j))
            if (BID.ne.0) then
              if (ANY(IBIOPOS==BID)) then
                JBID = REVBIOP(BID)
                BNO = B(LBIONO+(i-1)*12 + j)/SUMBNO
                BNO = SIN(I)*MW(I)*BNO/MW(JBID)
                SOUT(JBID) = SOUT(JBID) + BNO
              else
                IF (DMS_IRRCHK(IPROG,1,9001,USER_LMSG,IMISS,0,0,2)
     +              .NE. 0) THEN 
                  WRITE(IERW1,160), BID
                  CALL DMS_ERRPRT(2)
                  RETURN
                END IF
              endif
            endif
          end do
        endif
 101  CONTINUE

      STOTAL = 0
      DO 110 I = 1, NCOMP_NCC
        STOTAL = STOTAL+SOUT(I)
 110  CONTINUE
      SOUT(NCOMP_NCC+1) = STOTAL


 160  FORMAT(6X,'BASE COMPONENT WITH BIOID ',I3,' IS MISSING.',/,
     &  6X,'RUN BIOMASS LOOKUP ON THE COMPONENTS SPECIFICATION FORM.')

 165  FORMAT(6X,'SUM OF BIONO FOR BIOFEED COMPONENT NOT EQUAL TO 1.',/,
     &  6X,'BIONO VECTOR SCALED BY A FACTOR OF ',F8.5)


      RETURN
      END
