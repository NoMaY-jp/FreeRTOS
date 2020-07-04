#ifndef CCRX_PATCH_H
#define CCRX_PATCH_H

/* This file has to be included by using CC-RX's -preinclude option. */

/* Workaround for warning messages caused by undefined preprocessing identifier.
 */
#define _FEVAL 0
#define _FEVVAL 0
#define _HAS_C9X_FAST_FMA 0

/* Workaround to turn off FIT module's trigonometric function unit support
because somehow both CS+ and e2 sutudio do not have a GUI element to remove
-tfu compile option of CC-RX.
*/
#ifdef __TFU
#undef __TFU
#endif

#endif /* CCRX_PATCH_H */
