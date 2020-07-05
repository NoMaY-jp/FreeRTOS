#ifndef CCRX_PATCH_H
#define CCRX_PATCH_H

#if defined(__CCRX__)

/* This file has to be included by using CC-RX's -preinclude option. */

/* Workaround for warning messages caused by undefined preprocessing identifier.
 */
#ifndef _FEVAL
#define _FEVAL 0
#endif
#ifndef _FEVVAL
#define _FEVVAL 0
#endif
#ifndef _HAS_C9X_FAST_FMA
#define _HAS_C9X_FAST_FMA 0
#endif

#endif /* defined(__CCRX__) */

#endif /* CCRX_PATCH_H */
