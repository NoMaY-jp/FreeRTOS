#ifndef SMC_INTEGRATION_H
#define SMC_INTEGRATION_H

#ifdef __cplusplus
extern "C" {
#endif

#include "r_cg_macrodriver.h"
#if !defined(__TYPEDEF__)
#if defined(__CCRL__)
#define DI()      __DI()
#define EI()      __EI()
#define HALT()    __halt()
#define NOP()     __nop()
#define STOP      __stop
#define BRK       __brk
#elif defined(__ICCRL78__)
#define EI()       __enable_interrupt()
#define DI()       __disable_interrupt()
#define NOP()      __no_operation()
#define HALT()     __halt()
#define STOP()     __stop()
#endif
typedef unsigned short MD_STATUS;
#define __TYPEDEF__
#endif

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "queue.h"
#include "croutine.h"
#include "timers.h"
#include "event_groups.h"

//#include    <stdint.h>
//#include    <stdbool.h>
//#include    <stdio.h>
//#include    <stddef.h>
#include <string.h>



#if defined(__GNUC__) /* And also in case of LLVM */

/*
 * INT_IT (0x38 or 0x3C)
 */

#define r_itl_interrupt vTickISR
void vTickISR(void) __attribute__ ((interrupt));

/*
 * INT_BRK_I (0x7E)
 */
#define INT_BRK_I vSoftwareInterruptISR

void vSoftwareInterruptISR(void) __attribute__ ((interrupt));

/*
 * INT_WDTI (0x04)
 */
#define INT_WDTI u_wdt_interrupt

void u_wdt_interrupt(void) __attribute__ ((interrupt));

#endif



#define INTERNAL_NOT_USED(p)        ((void)(p))
#define R_CG_PRAGMA(...)            _Pragma(#__VA_ARGS__)

#if defined(__CCRL__)

#define R_CG_ISR_UNUSED(function, dummy_vect) \
    function##_UNUSED(void); \
    void function##__UNUSED(void); \
    void function##__UNUSED(void){function##_UNUSED();} \
    static void __near function##_UNUSED

#define R_CG_API_UNUSED(function) \
    function

#define R_CG_API_DO_NOT_USE(function) \
    function

#elif defined(__GNUC__)

#define R_CG_ISR_UNUSED(function, dummy_vect) \
    function##_UNUSED(void) __attribute__ ((unused)); \
    __attribute__ ((unused)) void function##_UNUSED

#define R_CG_API_UNUSED(function) \
    function

#define R_CG_API_DO_NOT_USE(function) \
    function

#elif defined(__ICCRL78__)

#define R_CG_ISR_UNUSED(function, dummy_vect) \
    function##___UNUSED(void); \
    R_CG_PRAGMA(vector = dummy_vect) \
    __interrupt static void function##__UNUSED(void); \
    __interrupt static void function##__UNUSED(void){} \
    static void function##_UNUSED

#define R_CG_API_UNUSED(function) \
    function

#define R_CG_API_DO_NOT_USE(function) \
    function

#endif

#if defined(__GNUC__)
#define BRK()     __asm volatile ("brk")
#endif

#if defined(__ICCRL78__)
#define BRK       __break
#endif

#define di()      DI()
#define ei()      EI()
#define halt()    HALT()
#define nop()     NOP()
#define stop()    STOP()
#define brk()     BRK()

#define NOP0()    do{ }while (0)
#define NOP1()    do{ NOP(); }while (0)
#define NOP2()    do{ NOP();NOP(); }while (0)
#define NOP3()    do{ NOP();NOP();NOP(); }while (0)
#define NOP4()    do{ NOP();NOP();NOP();NOP(); }while (0)
#define NOP5()    do{ NOP();NOP();NOP();NOP();NOP(); }while (0)
#define NOP6()    do{ NOP5();NOP(); }while (0)
#define NOP7()    do{ NOP5();NOP();NOP(); }while (0)
#define NOP8()    do{ NOP5();NOP();NOP();NOP(); }while (0)
#define NOP9()    do{ NOP5();NOP();NOP();NOP();NOP(); }while (0)

#define NOP10()   do{ NOP5();NOP5(); }while (0)
#define NOP11()   do{ NOP10();NOP(); }while (0)
#define NOP12()   do{ NOP10();NOP();NOP(); }while (0)
#define NOP13()   do{ NOP10();NOP();NOP();NOP(); }while (0)
#define NOP14()   do{ NOP10();NOP();NOP();NOP();NOP(); }while (0)
#define NOP15()   do{ NOP10();NOP();NOP();NOP();NOP();NOP(); }while (0)
#define NOP16()   do{ NOP15();NOP(); }while (0)
#define NOP17()   do{ NOP15();NOP();NOP(); }while (0)
#define NOP18()   do{ NOP15();NOP();NOP();NOP(); }while (0)
#define NOP19()   do{ NOP15();NOP();NOP();NOP();NOP(); }while (0)

#define NOP20()   do{ NOP10();NOP10(); }while (0)
#define NOP21()   do{ NOP20();NOP(); }while (0)
#define NOP22()   do{ NOP20();NOP();NOP(); }while (0)
#define NOP23()   do{ NOP20();NOP();NOP();NOP(); }while (0)
#define NOP24()   do{ NOP20();NOP();NOP();NOP();NOP(); }while (0)
#define NOP25()   do{ NOP20();NOP();NOP();NOP();NOP();NOP(); }while (0)
#define NOP26()   do{ NOP25();NOP(); }while (0)
#define NOP27()   do{ NOP25();NOP();NOP(); }while (0)
#define NOP28()   do{ NOP25();NOP();NOP();NOP(); }while (0)
#define NOP29()   do{ NOP25();NOP();NOP();NOP();NOP(); }while (0)

#define NOP30()   do{ NOP10();NOP10();NOP10(); }while (0)
#define NOP31()   do{ NOP30();NOP(); }while (0)
#define NOP32()   do{ NOP30();NOP();NOP(); }while (0)

#define NOP00()   do{ }while (0)
#define NOP40()   do{ NOP10();NOP10();NOP10();NOP10(); }while (0)
#define NOP50()   do{ NOP10();NOP10();NOP10();NOP10();NOP10(); }while (0)
#define NOP60()   do{ NOP50();NOP10(); }while (0)
#define NOP70()   do{ NOP50();NOP10();NOP10(); }while (0)
#define NOP80()   do{ NOP50();NOP10();NOP10();NOP10(); }while (0)
#define NOP90()   do{ NOP50();NOP10();NOP10();NOP10();NOP10(); }while (0)

#define NOP000()  do{ }while (0)
#define NOP100()  do{ NOP50();NOP50(); }while (0)
#define NOP200()  do{ NOP100();NOP100(); }while (0)
#define NOP300()  do{ NOP100();NOP100();NOP100(); }while (0)
#define NOP400()  do{ NOP100();NOP100();NOP100();NOP100(); }while (0)
#define NOP500()  do{ NOP100();NOP100();NOP100();NOP100();NOP100(); }while (0)
#define NOP600()  do{ NOP500();NOP100(); }while (0)
#define NOP700()  do{ NOP500();NOP100();NOP100(); }while (0)
#define NOP800()  do{ NOP500();NOP100();NOP100();NOP100(); }while (0)
#define NOP900()  do{ NOP500();NOP100();NOP100();NOP100();NOP100(); }while (0)

#define NOP0000() do{ }while (0)
#define NOP1000() do{ NOP500();NOP500(); }while (0)
#define NOP2000() do{ NOP1000();NOP1000(); }while (0)
#define NOP3000() do{ NOP1000();NOP1000();NOP1000(); }while (0)
#define NOP4000() do{ NOP1000();NOP1000();NOP1000();NOP1000(); }while (0)
#define NOP5000() do{ NOP1000();NOP1000();NOP1000();NOP1000();NOP1000(); }while (0)
#define NOP6000() do{ NOP5000();NOP1000(); }while (0)
#define NOP7000() do{ NOP5000();NOP1000();NOP1000(); }while (0)
#define NOP8000() do{ NOP5000();NOP1000();NOP1000();NOP1000(); }while (0)
#define NOP9000() do{ NOP5000();NOP1000();NOP1000();NOP1000();NOP1000(); }while (0)

#define NOP00000() do{ }while (0)
#define NOP10000() do{ NOP5000();NOP5000(); }while (0)
#define NOP20000() do{ NOP10000();NOP10000(); }while (0)
#define NOP30000() do{ NOP10000();NOP10000();NOP10000(); }while (0)
#define NOP40000() do{ NOP10000();NOP10000();NOP10000();NOP10000(); }while (0)
#define NOP50000() do{ NOP10000();NOP10000();NOP10000();NOP10000();NOP10000(); }while (0)
#define NOP60000() do{ NOP50000();NOP10000(); }while (0)
#define NOP70000() do{ NOP50000();NOP10000();NOP10000(); }while (0)
#define NOP80000() do{ NOP50000();NOP10000();NOP10000();NOP10000(); }while (0)
#define NOP90000() do{ NOP50000();NOP10000();NOP10000();NOP10000();NOP10000(); }while (0)

#define nop0()     NOP0()
#define nop1()     NOP1()
#define nop2()     NOP2()
#define nop3()     NOP3()
#define nop4()     NOP4()
#define nop5()     NOP5()
#define nop6()     NOP6()
#define nop7()     NOP7()
#define nop8()     NOP8()
#define nop9()     NOP9()

#define nop10()    NOP10()
#define nop11()    NOP11()
#define nop12()    NOP12()
#define nop13()    NOP13()
#define nop14()    NOP14()
#define nop15()    NOP15()
#define nop16()    NOP16()
#define nop17()    NOP17()
#define nop18()    NOP18()
#define nop19()    NOP19()

#define nop20()    NOP20()
#define nop21()    NOP21()
#define nop22()    NOP22()
#define nop23()    NOP23()
#define nop24()    NOP24()
#define nop25()    NOP25()
#define nop26()    NOP26()
#define nop27()    NOP27()
#define nop28()    NOP28()
#define nop29()    NOP29()

#define nop30()    NOP30()
#define nop31()    NOP31()
#define nop32()    NOP32()

#define nop00()    NOP00()
#define nop40()    NOP40()
#define nop50()    NOP50()
#define nop60()    NOP60()
#define nop70()    NOP70()
#define nop80()    NOP80()
#define nop90()    NOP90()

#define nop000()   NOP000()
#define nop100()   NOP100()
#define nop200()   NOP200()
#define nop300()   NOP300()
#define nop400()   NOP400()
#define nop500()   NOP500()
#define nop600()   NOP600()
#define nop700()   NOP700()
#define nop800()   NOP800()
#define nop900()   NOP900()

#define nop0000()  NOP0000()
#define nop1000()  NOP1000()
#define nop2000()  NOP2000()
#define nop3000()  NOP3000()
#define nop4000()  NOP4000()
#define nop5000()  NOP5000()
#define nop6000()  NOP6000()
#define nop7000()  NOP7000()
#define nop8000()  NOP8000()
#define nop9000()  NOP9000()

#define nop00000() NOP00000()
#define nop10000() NOP10000()
#define nop20000() NOP20000()
#define nop30000() NOP30000()
#define nop40000() NOP40000()
#define nop50000() NOP50000()
#define nop60000() NOP60000()
#define nop70000() NOP70000()
#define nop80000() NOP80000()
#define nop90000() NOP90000()

#include "freertos_start.h"
#include "freertos_helper.h"

#if defined(RENESAS_SIMULATOR_DEBUGGING)
#include "RenesasSimDebug/sim_debug_mode_hook.h"
#endif



#if 0

#include "CC_patch.h"
#include "IDE_patch.h"
#include "CG_patch.h"
#include "FIT_patch.h"

#if defined(__GNUC__)

/* Just for convenience.
 */
#define brk()               R_BSP_BRK()
#define int_exception(x)    R_BSP_INT(x)
#define wait()              R_BSP_WAIT()
#define nop()               R_BSP_NOP()

#endif /* defined(__GNUC__) */

#if defined(__GNUC__) || defined(__ICCRX__)

/* Just for convenience.
 */
#define setpsw_i()  R_BSP_SETPSW_I()
#define clrpsw_i()  R_BSP_CLRPSW_I()

#endif /* defined(__GNUC__) || defined(__ICCRX__) */

/* Just for convenience. For example, memcmp(), memcpy(), memset(), and so on.
 */
#include <string.h>

/* For convenience to port programs from CC-RX to GNURX or ICCRX.
 */
#define VOLATILE volatile R_BSP_EVENACCESS_SFR

/* For convenience to use e2 studio's Visual Expression View.
 */
#include "IDE_helper.h"

/* For Renesas RX Simulator Debugging.
 */
#if defined(RENESAS_SIMULATOR_DEBUGGING)
#include "RenesasSimDebug/sim_debug_mode_hook.h"
#endif

#endif /* #if 0 */



#ifdef __cplusplus
}
#endif

#endif /* SMC_INTEGRATION_H */
