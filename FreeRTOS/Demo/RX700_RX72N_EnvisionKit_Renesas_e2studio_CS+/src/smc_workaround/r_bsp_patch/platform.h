#ifndef PLATFORM_PATCH_H
#define PLATFORM_PATCH_H

#include "../smc_gen/r_bsp/platform.h"

#if defined(__GNUC__) || defined(__ICCRX__)

#include "smc_workaround2.h"

#endif /* defined(__GNUC__) || defined(__ICCRX__) */

#endif /* PLATFORM_PATCH_H */
