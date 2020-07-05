#ifndef IDE_PATCH_H
#define IDE_PATCH_H

#if defined(__CCRX__)

/* This file has to be included by using CC-RX's -preinclude option. */

/* Workaround to turn off FIT module's trigonometric function unit support
because somehow both CS+ and e2 sutudio do not have a GUI element to remove
-tfu compile option of CC-RX.
*/
#ifdef __TFU
#undef __TFU
#endif

#endif /* defined(__CCRX__) */

#endif /* IDE_PATCH_H */
