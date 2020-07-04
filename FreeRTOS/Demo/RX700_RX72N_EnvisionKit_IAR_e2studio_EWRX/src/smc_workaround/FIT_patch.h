#ifndef FIT_PATCH_H
#define FIT_PATCH_H

/* Workaround for the stand alone RX SmartConfigurator's missing support of FreeRTOS project.
 */
#define BSP_CFG_RTOS_USED (1)

/* Workaround for warning messages caused by undefined preprocessing identifier.
 */
#define SCI_CFG_DATA_MATCH_INCLUDED (0)
#define SCI_CFG_FIFO_INCLUDED (0)

/* Workaround for warning messages caused by missing 'void' argument prototype.
 */
void R_SCI_PinSet_SCI2(void);
void R_SCI_PinSet_SCI9(void);

#if defined(__ICCRX__)

/* Workaround to reduce remark messages.
 */
#pragma diag_suppress = Pe007

#endif /* defined(__ICCRX__) */

#else /* FIT_PATCH_H */

#if defined(R_RX_COMPILER_H)

#if defined(__ICCRX__)

/* Workaround to reduce remark messages.
 */
#pragma diag_default = Pe007

#undef _R_BSP_ASM
#undef R_BSP_ASM
//#undef R_BSP_ASM_LAB_NEXT
//#undef R_BSP_ASM_LAB_PREV
//#undef R_BSP_ASM_LAB
#undef R_BSP_ASM_BEGIN
#undef R_BSP_ASM_END

#define _R_BSP_ASM(...)           #__VA_ARGS__ "\n"
#define R_BSP_ASM(...)            _R_BSP_ASM(__VA_ARGS__)
//#define R_BSP_ASM_LAB_NEXT(n)     _lab##n
//#define R_BSP_ASM_LAB_PREV(n)     _lab##n
//#define R_BSP_ASM_LAB(n_colon)    R_BSP_ASM(_lab##n_colon)
#define R_BSP_ASM_BEGIN           R_BSP_PRAGMA(diag_suppress = Pa174)\
                                  R_BSP_PRAGMA(diag_suppress = Pe010)\
                                  asm(
#define R_BSP_ASM_END             );\
                                  R_BSP_PRAGMA(diag_default = Pe010)
                                  R_BSP_PRAGMA(diag_default = Pa174)

#endif /* defined(__ICCRX__) */

#endif /* defined(R_RX_COMPILER_H) */

#endif /* FIT_PATCH_H */
