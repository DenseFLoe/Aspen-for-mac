C
C  5 April 2018 David Tremblay  RAFT polymerization example
C
      SUBROUTINE USRAFT (SOUT,   NSUBS,  IDXSUB,   ITYPE,  NINTB,
     2                   INTB,   NREALB, REALB,    IDS,    NPO,
     3                   NBOPST, NIWORK, IWORK,    NWORK,  WORK,
     4                   NC,     NR,     STOIC,    RATES,  FLUXM,
     5                   FLUXS,  XCURR,  NTCAT,    RATCAT, NTSSAT,
     6                   RATSSA, KCALL,  KFAIL,    KFLASH, NCOMP,
     7                   IDX,    Y,      X,        X1,     X2,
     8                   NRALL,  RATALL, NUSERV,   USERV,  NINTR,
     9                   INTR,   NREALR, REALR,    NIWR,   IWR,
     *                   NWR,    WR)

C-------------------------------------------------------------------------------
C      Purpose:  User kinetic routine used with the free-radical model to 
C                simulate RAFT polymerization.
C
C       Refs:    Aspen Plus User Models Manual Reference. 
C-------------------------------------------------------------------------------
C
      IMPLICIT NONE
C
C     DECLARE VARIABLES USED IN DIMENSIONING
C
      INTEGER NSUBS, NINTB,  NPO,   NIWORK,NWORK,
     +        NC,    NR,    NTCAT, NTSSAT,NCOMP,
     +        NRALL, NUSERV,NINTR, NREALR,NIWR,
     +        NWR

C- Arrays in Argument List
C     These arrays are adjustable and are dimensioned as shown in Chapter
C     11 of the User's Models Manual.  The stream vector's dimension will
C     be determined by Aspen Plus at run-time.
C------------------------------------------------------------------------
C- Labeled commons are provided to pass data for specific reactor types.

C- RCSTR
#include "rcst_rcstri.cmn"
#include "rxn_rcstrr.cmn"
C- RPLUG
#include "rplg_rplugi.cmn"
#include "rplg_rplugr.cmn"
      EQUIVALENCE (XLEN, RPLUGR_UXLONG)
      EQUIVALENCE (DIAM, RPLUGR_UDIAM)
C- RBATCH
#include "rbtc_rbati.cmn"
#include "rbtc_rbatr.cmn"
C- Pressure Relief
#include "rbtc_presrr.cmn"

C------------------------------------------------------------------------
C- Two general labeled commons are provided for physical property data.

#include "rxn_rprops.cmn"
      EQUIVALENCE (TEMP, RPROPS_UTEMP)
      EQUIVALENCE (PRES, RPROPS_UPRES)
      EQUIVALENCE (VFRAC, RPROPS_UVFRAC)
      EQUIVALENCE (BETA, RPROPS_UBETA)
      EQUIVALENCE (VVAP, RPROPS_UVVAP)
      EQUIVALENCE (VLIQ, RPROPS_UVLIQ)
      EQUIVALENCE (VLIQS, RPROPS_UVLIQS)
#include "pputl_ppglob.cmn"

C------------------------------------------------------------------------
C- A general user common is provided for all user-specified routines.
C  This common is documented in Appendix A of the User Models manual.

#include "ppexec_user.cmn"
      EQUIVALENCE (RMISS, USER_RUMISS)
      EQUIVALENCE (IMISS, USER_IUMISS)
#include "dms_ncomp.cmn"
#include "dms_errout.cmn"
      EQUIVALENCE (IERROUT, ERROUT_IEROUT)
#include "dms_plex.cmn"
      EQUIVALENCE (IB(1), B(1))

C
C     DECLARE ARGUMENTS
C
      INTEGER IDXSUB(NSUBS),ITYPE(NSUBS), INTB(NINTB),
     +        IDS(2,4),NBOPST(6,NPO),IWORK(NIWORK),
     +        IDX(NCOMP),   INTR(NINTR),  IWR(NIWR),
     +        NREAL, KCALL, KFAIL, KFLASH,I
      INTEGER IPETOH,IPETAC,IPH2O, KV,    KDIAG,
     +        KER, NREALB
      REAL*8 SOUT(1),      WORK(NWORK),
     +       STOIC(NC,NSUBS,NR),  RATES(NC),
     +       FLUXM(1),     FLUXS(1),     RATCAT(NTCAT),
     +       RATSSA(NTSSAT),      Y(NCOMP),
     +       X(NCOMP),     X1(NCOMP),    X2(NCOMP)
      REAL*8 RATALL(NRALL),USERV(NUSERV),
     +       REALR(NREALR),WR(NWR),      XCURR, TEMP,
     +       PRES,  VMXL,  DVMX,  TK
      REAL*8 B(1)
C
C     DECLARE SYSTEM FUNCTIONS
C
      INTEGER DMS_LOCATI, DMS_KFORMC, DMS_IRRCHK, SHS_LCATT
      INTEGER DMS_IFCMNC, DMS_KCCID, DMS_KCCIDC
C
C     DECLARE LOCAL VARIABLES
C
      INTEGER MODELS(7)
      INTEGER IPROG(2),     IMISS
      REAL*8 REALB(NREALB),  XLEN,  DIAM,  VFRAC, BETA,
     +       VVAP,  VLIQ,  VLIQS, RMISS, CAA,
     +       CETOH, CETAC, CH2O,  RRATE1,RRATE2,
     +       RNET
      CHARACTER*80 IERROUT(10), IERW1(10), IERW2(9), IERW3(8)
     +             , IERW4(7), IERW5(6), IERW6(5), IERW7(4), IERW8(3)
     +             , IERW9(2), IERW10

      EQUIVALENCE (IERROUT(1), IERW1), (IERROUT(2), IERW2),
     +            (IERROUT(3), IERW3), (IERROUT(4), IERW4),
     +            (IERROUT(5), IERW5), (IERROUT(6), IERW6),
     +            (IERROUT(7), IERW7), (IERROUT(8), IERW8),
     +            (IERROUT(9), IERW9), (IERROUT(10), IERW10)
      INTEGER IPOLY, IMCR, L_SFLOW, L_MU0, L_SCB, L_MU1I
      INTEGER L_MU1, L_MU2 
      INTEGER IDSFLOW(2), IDLSFLOW(2), IDSCB(2), IDLEFLOW(2)
	INTEGER IDZMOM(2), IDSMOM(2) , IDDYAD(2), IDUSER(2)
      INTEGER IDLFMOM(2), IDLSMOM(2)
      INTEGER NBPDIR, LBPDIR, NBSEG, LBSEG, NSEG, LIDXSG
	INTEGER L_ZMOM, L_FMOM, L_SMOM, L_DOR
      INTEGER J, IRAFT, IRSEG, JRSEG, IAAR, JAAR, JRAFT
      INTEGER IAA, JAA
      REAL*8  RRAFT, KRAFT, ERAFT, ARAFT, RGAS, TRAFT, CRAFT
	REAL*8  FLOW, AMW, DENS, VFLOW, MDOT, VDOT, RHOP, T1
      REAL*8  MU0, MU1, MU2, GAM0, GAM1, GAM2, VFLOWL
      REAL*8  RM_1, RM_2, KMAIN, REFF, VLFRAC
      REAL*8  R1_0, R1_1, R1_2, R2_1, R2_2, HOLDUP
      INTEGER LMW
C
C      DATA STATEMENTS  
C
      DATA MODELS /'RBAT','RCST','RPLU','PRES','RADF', 'BATC', 'FLUI'/
      DATA IPROG    /'USRA', 'FT  '/   ! Subroutine name
      DATA IDLSFLOW /'LSFL','OW  '/ ! Live segments flow rate (LSFLOW)
      DATA IDSFLOW  /'SFLO','W   '/ ! Total segment flow rate (SFLOW)
      DATA IDSCB    /'SCB ','    '/ ! Short chain branching (SCB)
      DATA IDLEFLOW /'LEFL','OW  '/ ! Live end flow rate (LEFLOW)
      DATA IDDYAD   /'DYAD','FLOW'/ ! Pre flow rates 
	DATA IDZMOM   /'ZMOM','    '/ ! Zeroth moment (ZMOM)
	DATA IDSMOM   /'SMOM','    '/ ! Second moment (SMOM)
      DATA IDLFMOM  /'LFMO','M   '/ ! Live first moment (LFMOM)
      DATA IDLSMOM  /'LSMO','M   '/ ! Live second moment (LSMOM)      
      DATA IDUSER   /'CAUS','RA  '/ ! Track dormant moments (CAUSRA)
C===============================================================================
      RGAS = 1.986D0 ! 8.3144D0
      FLOW = SOUT( NCOMP_NCC + 1 ) ! mole flow, kmol/s
      AMW  = SOUT( NCOMP_NCC + 9 ) ! average MW, kg/kmol
      DENS = SOUT( NCOMP_NCC + 8 ) ! mass density, kg/m3
      VFLOW = FLOW * AMW / DENS    ! volume flow, M3/s
C ---------------------------------------------------------------------
C     Get liquid volume (batch) or volume flow (continuous)
C ---------------------------------------------------------------------
      KV=1
      CALL PPMON_VOLL ( TEMP  , PRES , X , NCOMP , IDX, NBOPST,
     +                  KDIAG, KV, VMXL, DVMX, KER ) ! get liquid molar volume
      VFLOWL = SOUT(NCOMP_NCC+1)*SOUT(NCOMP_NCC+6)*VMXL ! liquid m3/sec
      VLFRAC = VFLOWL/VFLOW ! Volume fraction occupied by liquid

C ---------------------------------------------------------------------
C     Determine holdup basis based on reactor type
C ---------------------------------------------------------------------      
      IF (IDS(1,4) .EQ. MODELS(1)) HOLDUP = RBATR_VOLRB*VLFRAC ! BATCH
      IF (IDS(1,4) .EQ. MODELS(2)) THEN !CSTR
        HOLDUP = RCSTRR_VOLRC
        IF (RCSTRR_VFRRC.LT.1.D0) HOLDUP = RCSTRR_VOLRC*RCSTRR_VFRRC
      END IF
      IF (IDS(1,4) .EQ. MODELS(3)) HOLDUP = RPLUGI_NTUBE*0.25D0*
     1   (3.1415D0*RPLUGR_UDIAM**2)*VLFRAC ! plug-flow reactor
C      IF (IDS(1,4) .EQ. MODELS(6)) HOLDUP = ! BATCHOP
C ---------------------------------------------------------------------
C     FIND THE POLYMER INDEX BEADS
C ---------------------------------------------------------------------
      CALL SHS_FIPOLM ( NBPDIR )      ! this routine returns the polymer bead
      LBPDIR = DMS_LOCATI( NBPDIR )   ! top of the polymer bead
      NBSEG  = IB( LBPDIR + 1 )       ! the segment bead
C      NBPOLY = IB( LBPDIR + 2 )      ! the polymer bead
C      LBPOLY = LOCATI( NBPOLY )      ! top of the polymer bead
C      NPOLY  = IB( LBPOLY )          ! number of polymers
C      LIDXPO = LBPOLY + 1            ! polymer component list
      LBSEG  = DMS_LOCATI( NBSEG  )   ! top of the segment bead
      NSEG   = IB( LBSEG  )           ! number of segments
      LIDXSG = LBSEG                  ! top of the segment index
      LMW = DMS_IFCMNC('MW')          ! pointer to component mole weights
C===============================================================================
C Locate component indices used in this routine based on formula name.
C    These indices correspond to the order that each component is declared
C    in the Components paragraph of the simulation input file or on the
C    Components Specifications Selection sheet.
C===============================================================================
      IAA    =DMS_KCCIDC ('AA')            ! Monomer
      IRAFT  =DMS_KCCIDC ('RAFT')          ! RAFT agent
      IPOLY  =DMS_KCCIDC ('PAA')           ! polymer
      IRSEG  =DMS_KCCIDC ('E-RAFT')        ! RAFT segment
      IAAR   =DMS_KCCIDC ('AA-R')          ! AA repeat segment
C===============================================================================
C     Locate the components in the mole fraction arrays
C===============================================================================
      JRAFT = 0
      JAA   = 0
      DO J = 1, NCOMP
        IF ( IDX(J).EQ. IRAFT ) JRAFT = J
        IF ( IDX(J).EQ. IAA   ) JAA   = J
      END DO
C===============================================================================
C      Get concentrations of interest (kmol/m3)
C===============================================================================
       CRAFT = 0.D0
       IF (jRAFT .NE. 0) CRAFT = X(JRAFT)/VMXL ! concentration kmol/m3
C===============================================================================
C     Find pointers in the component attribute array
C===============================================================================
      L_SFLOW = SHS_LCATT( 1, IPOLY, IDSFLOW )  ! segment flow rates
      L_MU1I  = SHS_LCATT( 1, IPOLY, IDLSFLOW ) ! live segment flow rates
      L_MU0   = SHS_LCATT( 1, IPOLY, IDLEFLOW ) ! live end flow rates
      L_MU1   = SHS_LCATT( 1, IPOLY, IDLFMOM  ) ! live first moment
      L_MU2   = SHS_LCATT( 1, IPOLY, IDLSMOM  ) ! live second moment
      L_SCB   = SHS_LCATT( 1, IPOLY, IDSCB )    ! short chain branching
      L_ZMOM  = SHS_LCATT( 1, IPOLY, IDZMOM )   ! zeroth moment
	L_SMOM  = SHS_LCATT( 1, IPOLY, IDSMOM )   ! second moment
	L_DOR  = SHS_LCATT( 1, IPOLY, IDUSER)     ! Dormant polymer moments
C ---------------------------------------------------------------------
C     Calculate moments (concentration basis)
C ---------------------------------------------------------------------
      MU0 = SOUT( L_MU0 + 1 )  / VFLOWL ! live zeroth moment, kmol/m3
      MU1 = SOUT( L_MU1 + 1 )  / VFLOWL ! live firstmoment, kmol/m3
      MU2 = SOUT( L_MU2 + 1 )  / VFLOWL ! live second moment, kmol/m3
      GAM0 = SOUT( L_DOR + 1 ) / VFLOWL ! dormant zeroth moment, kmol/m3
      GAM1 = SOUT( L_DOR + 2 ) / VFLOWL ! dormant first moment, kmol/m3
      GAM2 = SOUT( L_DOR + 3 ) / VFLOWL ! dormant second moment, kmol/m3
C===============================================================================
C     Locate the segments in the segment list
C===============================================================================
       DO J = 1, NSEG
           IF ( IB( LIDXSG+J ).EQ. IRSEG ) JRSEG = J
           IF ( IB( LIDXSG+J ).EQ. IAAR ) JAAR = J
	 END DO
C===============================================================================
C     Get rate constants and reaction rates
C     R1 = LEFLOW( Mi ) * [ Fk ] * k_RA( I, k ) chain transfer to RAFT agent
C===============================================================================
      ARAFT = REALR(1) ! Pre-factor for RAFT reactions (mol/L/hr basis)
      ERAFT = REALR(2) ! Activation energy for RAFT reactions (kcal/mol)
      TRAFT = REALR(3) +273.15D0 ! Reference temperature, (DEG K)
      KRAFT = (ARAFT/3600D0)*DEXP(( -ERAFT/RGAS )*((1/TEMP)-(1/TRAFT)))
      KMAIN = KRAFT*REALR(4) ! Rate constant for main equilibrium reaction
c      REFF  = REALR(5) ! RAFT agent efficiency factor
C ---------------------------------------------------------------------
C     Calculate reaction rates  P = live polymer
C (A) Pn + F == Qn + P0    (RAFT pre-equlibrium)   F = RAFT agent
C (B) Pn + Qm == Pm + Qn   (RAFT main equilibrium) Q = dormant polymer
C ---------------------------------------------------------------------
      R1_0 = KRAFT * CRAFT * MU0 * HOLDUP ! rate of gam0 by reaction A
      R1_1 = KRAFT * CRAFT * MU1 * HOLDUP ! rate of gam1 by reaction A
      R1_2 = KRAFT * CRAFT * MU2 * HOLDUP ! rate of gam2 by reaction A
      
C      RM_0 = KRAFT * CRAFT * (MU0 - MU0) * HOLDUP ! mu0 by reaction A
      RM_1 = KRAFT * CRAFT * (MU0 - MU1) * HOLDUP ! mu1 by reaction A
      RM_2 = KRAFT * CRAFT * (MU0 - MU2) * HOLDUP ! mu2 by reaction A

      R2_1 = KMAIN * ( GAM1*MU0 - GAM0*MU1 ) * HOLDUP ! mu1 by reaction B
      R2_2 = KMAIN * ( GAM2*MU0 - GAM0*MU2 ) * HOLDUP ! mu2 by reaction B
      MDOT = R1_0*B( LMW+IRAFT) ! mass rate of change polymer
C===============================================================================
C     Send back rates of change
C===============================================================================
      RATES( IPOLY ) = MDOT / B( LMW+IPOLY ) ! polymer formed reaction 1
      RATES( IRAFT ) = -R1_0 ! RAFT agent consumed by reaction 1
      RATCAT( L_ZMOM + 1 - NCOMP_NVCP ) = R1_0 ! Zeroth moment 
      RATCAT( L_SFLOW + JRSEG - NCOMP_NVCP ) = R1_0 ! SFLOW( E-RAFT )
      RATCAT( L_SMOM + 1 - NCOMP_NVCP ) = R1_0 ! Second moment
C      RATCAT( L_MU0  + JAAR - NCOMP_NVCP ) = RM_0 + R2_0
      RATCAT( L_MU1I + JAAR - NCOMP_NVCP ) = RM_1 + R2_1 ! LEFLOW( AA )
      RATCAT( L_MU2 + 1 -     NCOMP_NVCP ) = RM_2 + R2_2 ! LSMOM
C   - rates of change dormant polymer moments - 
      RATCAT( L_DOR  + 2 - NCOMP_NVCP ) = R1_1 - R2_1 ! dormant gam1
      RATCAT( L_DOR  + 3 - NCOMP_NVCP ) = R1_2 - R2_2 ! dormant gam2
      RATCAT( L_DOR  + 1 - NCOMP_NVCP ) = R1_0 ! dormant gam0
C===============================================================================
C Diagnostic Section
C===============================================================================
C
C      WRITE (USER_NHSTRY,*) 'RAFT ',IRAFT,' IRSEG ',IRSEG
C      WRITE (USER_NHSTRY,*) 'IPOLY ',IPOLY,' IAAR', IAAR
C      WRITE (USER_NHSTRY,*) 'JAAR ',JAAR,' JRSEG ',JRSEG
C       WRITE (USER_NHSTRY,*) 'TEMP ',TEMP,' VFLOW ',VFLOW,' DENS', DENS
C       WRITE (USER_NHSTRY,*) 'ARAFT ', ARAFT, '  ERAFT',ERAFT
C       WRITE (USER_NHSTRY,*) 'TRAFT ', TRAFT, ' NREALR ', NREALR
C       WRITE (USER_NHSTRY,*) 'T1 ',T1
C       WRITE (USER_NHSTRY,*) 'KRAFT ', KRAFT, '  CRAFT',CRAFT
C      WRITE (USER_NHSTRY,*) 'holdup ',HOLDUP
C       WRITE (USER_NHSTRY,'(6X,A4,3(G12.4))') 'R0> ',R0_0, R0_1, R0_2
C       WRITE (USER_NHSTRY,'(6X,A4,3(G12.4))') 'R1> ',R1_0, R1_1, R1_2
C       WRITE (USER_NHSTRY,'(6X,A4,3(G12.4))') 'R2> ',R2_0, R2_1, R2_2       
C      WRITE (USER_NHSTRY,*) 'R1 ',R1, 'MU0',SOUT(L_MU0+1)
C      WRITE (USER_NHSTRY,*) 'RBB ',RBB

      RETURN
      END