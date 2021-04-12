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
void R_SCI_PinSet_SCI0(void);
void R_SCI_PinSet_SCI1(void);
void R_SCI_PinSet_SCI2(void);
void R_SCI_PinSet_SCI3(void);
void R_SCI_PinSet_SCI4(void);
void R_SCI_PinSet_SCI5(void);
void R_SCI_PinSet_SCI6(void);
void R_SCI_PinSet_SCI7(void);
void R_SCI_PinSet_SCI8(void);
void R_SCI_PinSet_SCI9(void);
void R_SCI_PinSet_SCI10(void);
void R_SCI_PinSet_SCI11(void);
void R_SCI_PinSet_SCI12(void);

#if defined(__ICCRX__)

/* Workaround for warning messages caused by file end without newline
 */
#pragma diag_suppress = Pe001

#endif /* defined(__ICCRX__) */

#endif /* FIT_PATCH_H */
