#ifndef SMC_WORKAROUND_H
#define SMC_WORKAROUND_H

#if defined(__GNUC__)

#define brk()               R_BSP_BRK()
#define int_exception(x)    R_BSP_INT(x)
#define wait()              R_BSP_WAIT()
#define nop()               R_BSP_NOP()

#endif /* defined(__GNUC__) */

#if defined(__GNUC__) || defined(__ICCRX__)

#define setpsw_i()  R_BSP_SETPSW_I()
#define clrpsw_i()  R_BSP_CLRPSW_I()

#endif /* defined(__GNUC__) || defined(__ICCRX__) */

#include "CG_patch.h"
#include "FIT_patch.h"

#endif /* SMC_WORKAROUND_H */
