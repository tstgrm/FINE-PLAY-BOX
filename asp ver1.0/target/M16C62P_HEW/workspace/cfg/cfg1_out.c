/* cfg1_out.c */
#define TOPPERS_CFG1_OUT  1
#include "kernel/kernel_int.h"
#include "target_timer.h"
#include "target_syssvc.h"
#include "syssvc/serial.h"
#include "Apli/job.h"


#ifdef INT64_MAX
  typedef int64_t signed_t;
  typedef uint64_t unsigned_t;
#else
  typedef int32_t signed_t;
  typedef uint32_t unsigned_t;
#endif

#include <target_cfg1_out.h>

const uint32_t TOPPERS_cfg_magic_number = 0x12345678;
const uint32_t TOPPERS_cfg_sizeof_signed_t = sizeof(signed_t);
const unsigned_t TOPPERS_cfg_CHAR_BIT = CHAR_BIT;
const unsigned_t TOPPERS_cfg_CHAR_MAX = CHAR_MAX;
const unsigned_t TOPPERS_cfg_CHAR_MIN = CHAR_MIN;
const unsigned_t TOPPERS_cfg_SCHAR_MAX = SCHAR_MAX;
const unsigned_t TOPPERS_cfg_SHRT_MAX = SHRT_MAX;
const unsigned_t TOPPERS_cfg_INT_MAX = INT_MAX;
const unsigned_t TOPPERS_cfg_LONG_MAX = LONG_MAX;

const unsigned_t TOPPERS_cfg_TA_NULL = TA_NULL;
const unsigned_t TOPPERS_cfg_TA_ACT = TA_ACT;
const unsigned_t TOPPERS_cfg_TA_TPRI = TA_TPRI;
const unsigned_t TOPPERS_cfg_TA_MPRI = TA_MPRI;
const unsigned_t TOPPERS_cfg_TA_WMUL = TA_WMUL;
const unsigned_t TOPPERS_cfg_TA_CLR = TA_CLR;
const unsigned_t TOPPERS_cfg_TA_STA = TA_STA;
const unsigned_t TOPPERS_cfg_TA_NONKERNEL = TA_NONKERNEL;
const unsigned_t TOPPERS_cfg_TA_ENAINT = TA_ENAINT;
const unsigned_t TOPPERS_cfg_TA_EDGE = TA_EDGE;
const signed_t TOPPERS_cfg_TMIN_TPRI = TMIN_TPRI;
const signed_t TOPPERS_cfg_TMAX_TPRI = TMAX_TPRI;
const signed_t TOPPERS_cfg_TMIN_DPRI = TMIN_DPRI;
const signed_t TOPPERS_cfg_TMAX_DPRI = TMAX_DPRI;
const signed_t TOPPERS_cfg_TMIN_MPRI = TMIN_MPRI;
const signed_t TOPPERS_cfg_TMAX_MPRI = TMAX_MPRI;
const signed_t TOPPERS_cfg_TMIN_ISRPRI = TMIN_ISRPRI;
const signed_t TOPPERS_cfg_TMAX_ISRPRI = TMAX_ISRPRI;
const unsigned_t TOPPERS_cfg_TMAX_MAXSEM = TMAX_MAXSEM;
const unsigned_t TOPPERS_cfg_TMAX_RELTIM = TMAX_RELTIM;
const signed_t TOPPERS_cfg_TMIN_INTPRI = TMIN_INTPRI;
const unsigned_t TOPPERS_cfg_OMIT_INITIALIZE_INTERRUPT = 
#if defined(OMIT_INITIALIZE_INTERRUPT)
1;
#else
0;
#endif
const unsigned_t TOPPERS_cfg_OMIT_INITIALIZE_EXCEPTION = 
#if defined(OMIT_INITIALIZE_EXCEPTION)
1;
#else
0;
#endif
const unsigned_t TOPPERS_cfg_sizeof_ID = sizeof(ID);
const unsigned_t TOPPERS_cfg_sizeof_uint_t = sizeof(uint_t);
const unsigned_t TOPPERS_cfg_sizeof_SIZE = sizeof(SIZE);
const unsigned_t TOPPERS_cfg_sizeof_ATR = sizeof(ATR);
const unsigned_t TOPPERS_cfg_sizeof_PRI = sizeof(PRI);
const unsigned_t TOPPERS_cfg_sizeof_void_ptr = sizeof(void*);
const unsigned_t TOPPERS_cfg_sizeof_VP = sizeof(void*);
const unsigned_t TOPPERS_cfg_sizeof_intptr_t = sizeof(intptr_t);
const unsigned_t TOPPERS_cfg_sizeof_FP = sizeof(FP);
const unsigned_t TOPPERS_cfg_sizeof_TINIB = sizeof(TINIB);
const unsigned_t TOPPERS_cfg_offsetof_TINIB_tskatr = offsetof(TINIB,tskatr);
const unsigned_t TOPPERS_cfg_offsetof_TINIB_exinf = offsetof(TINIB,exinf);
const unsigned_t TOPPERS_cfg_offsetof_TINIB_task = offsetof(TINIB,task);
const unsigned_t TOPPERS_cfg_offsetof_TINIB_ipriority = offsetof(TINIB,ipriority);
const unsigned_t TOPPERS_cfg_offsetof_TINIB_stksz = offsetof(TINIB,stksz);
const unsigned_t TOPPERS_cfg_offsetof_TINIB_stk = offsetof(TINIB,stk);
const unsigned_t TOPPERS_cfg_offsetof_TINIB_texatr = offsetof(TINIB,texatr);
const unsigned_t TOPPERS_cfg_offsetof_TINIB_texrtn = offsetof(TINIB,texrtn);
const unsigned_t TOPPERS_cfg_sizeof_SEMINIB = sizeof(SEMINIB);
const unsigned_t TOPPERS_cfg_offsetof_SEMINIB_sematr = offsetof(SEMINIB,sematr);
const unsigned_t TOPPERS_cfg_offsetof_SEMINIB_isemcnt = offsetof(SEMINIB,isemcnt);
const unsigned_t TOPPERS_cfg_offsetof_SEMINIB_maxsem = offsetof(SEMINIB,maxsem);
const unsigned_t TOPPERS_cfg_sizeof_FLGPTN = sizeof(FLGPTN);
const unsigned_t TOPPERS_cfg_sizeof_FLGINIB = sizeof(FLGINIB);
const unsigned_t TOPPERS_cfg_offsetof_FLGINIB_flgatr = offsetof(FLGINIB,flgatr);
const unsigned_t TOPPERS_cfg_offsetof_FLGINIB_iflgptn = offsetof(FLGINIB,iflgptn);
const unsigned_t TOPPERS_cfg_sizeof_DTQINIB = sizeof(DTQINIB);
const unsigned_t TOPPERS_cfg_offsetof_DTQINIB_dtqatr = offsetof(DTQINIB,dtqatr);
const unsigned_t TOPPERS_cfg_offsetof_DTQINIB_dtqcnt = offsetof(DTQINIB,dtqcnt);
const unsigned_t TOPPERS_cfg_offsetof_DTQINIB_p_dtqmb = offsetof(DTQINIB,p_dtqmb);
const unsigned_t TOPPERS_cfg_sizeof_PDQINIB = sizeof(PDQINIB);
const unsigned_t TOPPERS_cfg_offsetof_PDQINIB_pdqatr = offsetof(PDQINIB,pdqatr);
const unsigned_t TOPPERS_cfg_offsetof_PDQINIB_pdqcnt = offsetof(PDQINIB,pdqcnt);
const unsigned_t TOPPERS_cfg_offsetof_PDQINIB_maxdpri = offsetof(PDQINIB,maxdpri);
const unsigned_t TOPPERS_cfg_offsetof_PDQINIB_p_pdqmb = offsetof(PDQINIB,p_pdqmb);
const unsigned_t TOPPERS_cfg_sizeof_MBXINIB = sizeof(MBXINIB);
const unsigned_t TOPPERS_cfg_offsetof_MBXINIB_mbxatr = offsetof(MBXINIB,mbxatr);
const unsigned_t TOPPERS_cfg_offsetof_MBXINIB_maxmpri = offsetof(MBXINIB,maxmpri);
const unsigned_t TOPPERS_cfg_sizeof_MPFINIB = sizeof(MPFINIB);
const unsigned_t TOPPERS_cfg_offsetof_MPFINIB_mpfatr = offsetof(MPFINIB,mpfatr);
const unsigned_t TOPPERS_cfg_offsetof_MPFINIB_blkcnt = offsetof(MPFINIB,blkcnt);
const unsigned_t TOPPERS_cfg_offsetof_MPFINIB_blksz = offsetof(MPFINIB,blksz);
const unsigned_t TOPPERS_cfg_offsetof_MPFINIB_mpf = offsetof(MPFINIB,mpf);
const unsigned_t TOPPERS_cfg_offsetof_MPFINIB_p_mpfmb = offsetof(MPFINIB,p_mpfmb);
const unsigned_t TOPPERS_cfg_sizeof_CYCINIB = sizeof(CYCINIB);
const unsigned_t TOPPERS_cfg_offsetof_CYCINIB_cycatr = offsetof(CYCINIB,cycatr);
const unsigned_t TOPPERS_cfg_offsetof_CYCINIB_exinf = offsetof(CYCINIB,exinf);
const unsigned_t TOPPERS_cfg_offsetof_CYCINIB_cychdr = offsetof(CYCINIB,cychdr);
const unsigned_t TOPPERS_cfg_offsetof_CYCINIB_cyctim = offsetof(CYCINIB,cyctim);
const unsigned_t TOPPERS_cfg_offsetof_CYCINIB_cycphs = offsetof(CYCINIB,cycphs);
const unsigned_t TOPPERS_cfg_sizeof_ALMINIB = sizeof(ALMINIB);
const unsigned_t TOPPERS_cfg_offsetof_ALMINIB_almatr = offsetof(ALMINIB,almatr);
const unsigned_t TOPPERS_cfg_offsetof_ALMINIB_exinf = offsetof(ALMINIB,exinf);
const unsigned_t TOPPERS_cfg_offsetof_ALMINIB_almhdr = offsetof(ALMINIB,almhdr);
const unsigned_t TOPPERS_cfg_sizeof_INHNO = sizeof(INHNO);
const unsigned_t TOPPERS_cfg_sizeof_INTNO = sizeof(INTNO);
const unsigned_t TOPPERS_cfg_sizeof_EXCNO = sizeof(EXCNO);
const unsigned_t TOPPERS_cfg_TA_POSEDGE = TA_EDGE;
const unsigned_t TOPPERS_cfg_TA_BOTHEDGE = TA_BOTHEDGE;
const unsigned_t TOPPERS_cfg_TA_NEGEDGE = TA_NEGEDGE;


/* #include "target_timer.h" */

#line 6 "C:/WorkSpace/asp/target/M16C62P_HEW/workspace/../../../target/M16C62P_HEW/target_timer.cfg"
const unsigned_t TOPPERS_cfg_static_api_0 = 0;
const unsigned_t TOPPERS_cfg_valueof_iniatr_0 = ( TA_NULL ); 
#line 7 "C:/WorkSpace/asp/target/M16C62P_HEW/workspace/../../../target/M16C62P_HEW/target_timer.cfg"
const unsigned_t TOPPERS_cfg_static_api_1 = 1;
const unsigned_t TOPPERS_cfg_valueof_teratr_1 = ( TA_NULL ); 
#line 8 "C:/WorkSpace/asp/target/M16C62P_HEW/workspace/../../../target/M16C62P_HEW/target_timer.cfg"
const unsigned_t TOPPERS_cfg_static_api_2 = 2;
const unsigned_t TOPPERS_cfg_valueof_inhno_2 = ( INHNO_TIMER ); const unsigned_t TOPPERS_cfg_valueof_inhatr_2 = ( TA_NULL ); 
#line 9 "C:/WorkSpace/asp/target/M16C62P_HEW/workspace/../../../target/M16C62P_HEW/target_timer.cfg"
const unsigned_t TOPPERS_cfg_static_api_3 = 3;
const unsigned_t TOPPERS_cfg_valueof_intno_3 = ( INTNO_TIMER ); const unsigned_t TOPPERS_cfg_valueof_intatr_3 = ( TA_ENAINT | INTATR_TIMER ); const signed_t TOPPERS_cfg_valueof_intpri_3 = ( INTPRI_TIMER ); /* #include "target_syssvc.h" */
/* #include "syssvc/serial.h" */

#line 13 "C:/WorkSpace/asp/target/M16C62P_HEW/workspace/../../../syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_static_api_4 = 4;
const unsigned_t TOPPERS_cfg_valueof_iniatr_4 = ( TA_NULL ); 
#line 15 "C:/WorkSpace/asp/target/M16C62P_HEW/workspace/../../../syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_static_api_5 = 5;
#define SERIAL_RCV_SEM1	(<>)

#line 15 "C:/WorkSpace/asp/target/M16C62P_HEW/workspace/../../../syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_5 = ( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_5 = ( 0 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_5 = ( 1 ); 
#line 16 "C:/WorkSpace/asp/target/M16C62P_HEW/workspace/../../../syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_static_api_6 = 6;
#define SERIAL_SND_SEM1	(<>)

#line 16 "C:/WorkSpace/asp/target/M16C62P_HEW/workspace/../../../syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_6 = ( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_6 = ( 1 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_6 = ( 1 ); 
#if TNUM_PORT >= 2

#line 18 "C:/WorkSpace/asp/target/M16C62P_HEW/workspace/../../../syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_static_api_7 = 7;
#define SERIAL_RCV_SEM2	(<>)

#line 18 "C:/WorkSpace/asp/target/M16C62P_HEW/workspace/../../../syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_7 = ( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_7 = ( 0 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_7 = ( 1 ); 
#line 19 "C:/WorkSpace/asp/target/M16C62P_HEW/workspace/../../../syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_static_api_8 = 8;
#define SERIAL_SND_SEM2	(<>)

#line 19 "C:/WorkSpace/asp/target/M16C62P_HEW/workspace/../../../syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_8 = ( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_8 = ( 1 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_8 = ( 1 ); 
#endif 

#if TNUM_PORT >= 3

#line 22 "C:/WorkSpace/asp/target/M16C62P_HEW/workspace/../../../syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_static_api_9 = 9;
#define SERIAL_RCV_SEM3	(<>)

#line 22 "C:/WorkSpace/asp/target/M16C62P_HEW/workspace/../../../syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_9 = ( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_9 = ( 0 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_9 = ( 1 ); 
#line 23 "C:/WorkSpace/asp/target/M16C62P_HEW/workspace/../../../syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_static_api_10 = 10;
#define SERIAL_SND_SEM3	(<>)

#line 23 "C:/WorkSpace/asp/target/M16C62P_HEW/workspace/../../../syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_10 = ( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_10 = ( 1 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_10 = ( 1 ); 
#endif 
/* #include "Apli/job.h" */

#line 14 "C:/WorkSpace/asp/target/M16C62P_HEW/workspace/../../../Apli/job.cfg"
const unsigned_t TOPPERS_cfg_static_api_11 = 11;
#define INIT_TASK	(<>)

#line 14 "C:/WorkSpace/asp/target/M16C62P_HEW/workspace/../../../Apli/job.cfg"
const unsigned_t TOPPERS_cfg_valueof_tskatr_11 = ( TA_ACT ); const signed_t TOPPERS_cfg_valueof_itskpri_11 = ( IDLE_PRIORITY ); const unsigned_t TOPPERS_cfg_valueof_stksz_11 = ( STACK_SIZE ); 
#line 15 "C:/WorkSpace/asp/target/M16C62P_HEW/workspace/../../../Apli/job.cfg"
const unsigned_t TOPPERS_cfg_static_api_12 = 12;
#define FUNC1_TASK	(<>)

#line 15 "C:/WorkSpace/asp/target/M16C62P_HEW/workspace/../../../Apli/job.cfg"
const unsigned_t TOPPERS_cfg_valueof_tskatr_12 = ( TA_NULL ); const signed_t TOPPERS_cfg_valueof_itskpri_12 = ( MID_PRIORITY ); const unsigned_t TOPPERS_cfg_valueof_stksz_12 = ( STACK_SIZE ); 
#line 20 "C:/WorkSpace/asp/target/M16C62P_HEW/workspace/../../../Apli/job.cfg"
const unsigned_t TOPPERS_cfg_static_api_13 = 13;
const unsigned_t TOPPERS_cfg_valueof_intno_13 = ( TINTNO_S0RACK ); const unsigned_t TOPPERS_cfg_valueof_intatr_13 = ( TA_EDGE ); const signed_t TOPPERS_cfg_valueof_intpri_13 = ( INTPRI_UART_recieve ); 
#line 21 "C:/WorkSpace/asp/target/M16C62P_HEW/workspace/../../../Apli/job.cfg"
const unsigned_t TOPPERS_cfg_static_api_14 = 14;
const unsigned_t TOPPERS_cfg_valueof_inhno_14 = ( TINHNO_S0RACK ); const unsigned_t TOPPERS_cfg_valueof_inhatr_14 = ( TA_NULL ); 
#line 24 "C:/WorkSpace/asp/target/M16C62P_HEW/workspace/../../../Apli/job.cfg"
const unsigned_t TOPPERS_cfg_static_api_15 = 15;
const unsigned_t TOPPERS_cfg_valueof_intno_15 = ( TINTNO_S0TNACK ); const unsigned_t TOPPERS_cfg_valueof_intatr_15 = ( TA_EDGE ); const signed_t TOPPERS_cfg_valueof_intpri_15 = ( INTPRI_UART_send ); 
#line 25 "C:/WorkSpace/asp/target/M16C62P_HEW/workspace/../../../Apli/job.cfg"
const unsigned_t TOPPERS_cfg_static_api_16 = 16;
const unsigned_t TOPPERS_cfg_valueof_inhno_16 = ( TINHNO_S0TNACK ); const unsigned_t TOPPERS_cfg_valueof_inhatr_16 = ( TA_NULL ); 
#line 28 "C:/WorkSpace/asp/target/M16C62P_HEW/workspace/../../../Apli/job.cfg"
const unsigned_t TOPPERS_cfg_static_api_17 = 17;
#define UART_DTQ	(<>)

#line 28 "C:/WorkSpace/asp/target/M16C62P_HEW/workspace/../../../Apli/job.cfg"
const unsigned_t TOPPERS_cfg_valueof_dtqatr_17 = ( TA_NULL ); const unsigned_t TOPPERS_cfg_valueof_dtqcnt_17 = ( 20 ); 
#line 32 "C:/WorkSpace/asp/target/M16C62P_HEW/workspace/../../../Apli/job.cfg"
const unsigned_t TOPPERS_cfg_static_api_18 = 18;
#define UART_FLG	(<>)

#line 32 "C:/WorkSpace/asp/target/M16C62P_HEW/workspace/../../../Apli/job.cfg"
const unsigned_t TOPPERS_cfg_valueof_flgatr_18 = ( TA_CLR ); const unsigned_t TOPPERS_cfg_valueof_iflgptn_18 = ( 0x0000 ); 
