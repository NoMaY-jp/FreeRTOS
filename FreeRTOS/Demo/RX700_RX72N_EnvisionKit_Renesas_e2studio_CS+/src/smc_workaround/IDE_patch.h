#ifndef IDE_PATCH_H
#define IDE_PATCH_H

#if defined(__CDT_PARSER__)

#if defined(__CCRX__)

/* Workaround for missing pre-defined macro in the Renesas Toolchain Builtin
 * Language Settings.
 */
#ifndef __TFU
#define __TFU 1
#endif

/* Workaround for wrong pre-defined macro in the Renesas Toolchain Builtin
 * Language Settings.
 */
#ifdef __DBL4
#undef __DBL4
#endif
#ifndef __DBL8
#define __DBL8 1
#endif

#endif /* defined(__CCRX__) */

#endif /* defined(__CDT_PARSER__) */

#endif /* IDE_PATCH_H */
