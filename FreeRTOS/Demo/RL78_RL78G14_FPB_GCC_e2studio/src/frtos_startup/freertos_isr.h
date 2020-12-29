#ifndef FREERTOS_ISR_H
#define FREERTOS_ISR_H

#if defined(__CCRL__)

extern void vPortFreeRTOSInterruptCommonHandler_C(void);

#pragma inline_asm vPortFreeRTOSInterruptCommonHandler_C_Helper

static void __near vPortFreeRTOSInterruptCommonHandler_C_Helper(void)
{
    /* vPortFreeRTOSInterruptCommonHandler_C() doesn't return here. */ \
    pop bc
#if defined(__RL78_SMALL__)
    br !_vPortFreeRTOSInterruptCommonHandler_C
#elif defined(__RL78_MEDIUM__)
    br !!_vPortFreeRTOSInterruptCommonHandler_C
#else
    #error Unknown memory model.
#endif
}

#define R_CG_FREERTOS_INTERRUPT(function) \
    function(void); \
    static __near void _##function(void); \
    static __near void function(void) \
    { \
        /* vPortFreeRTOSInterruptCommonHandler_C_Helper() doesn't return here. */ \
        void (__near * volatile p)() = _##function; \
        vPortFreeRTOSInterruptCommonHandler_C_Helper(); \
        /* The following is intended to remove the epilogue code. */ \
        while (1) {} \
    } \
    static void __near _##function

#elif defined(__GNUC__)

extern void vPortFreeRTOSInterruptCommonHandler_C(void);

#define R_CG_FREERTOS_INTERRUPT(function) \
    function(void) \
    { \
        void _##function(void); \
        /* vPortFreeRTOSInterruptCommonHandler_C() doesn't return here. */ \
        __asm volatile \
        ( \
            "movw bc, #__" #function " \n" \
            "br !!_vPortFreeRTOSInterruptCommonHandler_C \n" \
        ); \
        /* The following is intended to remove the epilogue code. */ \
        while (1) {} \
    } \
    void _##function(void); \
    void _##function

#elif defined(__ICCRL78__)

extern void vPortFreeRTOSInterruptCommonHandler_C(void);

#if defined(RENESAS_SIMULATOR_DEBUGGING)

#define vPortFreeRTOSInterruptCommonHandler_C_Helper(function) \
    __asm \
    ( \
        /* The following ICCRL78 interrupt code doesn't work with Renesas RL78 simulator. \
         * "movw ax, 0xffffc          \n" \
         * "push ax                   \n" \
         * So the following code is added. */ \
        "mov  a, cs                \n" \
        "mov  x, a                 \n" \
        "mov  a, es                \n" \
        "movw [sp], ax             \n" \
        /* vPortFreeRTOSInterruptCommonHandler_C() doesn't return here. */ \
        "movw bc, #__" #function " \n" \
        "br   _vPortFreeRTOSInterruptCommonHandler_C \n" \
    )

#else

#define vPortFreeRTOSInterruptCommonHandler_C_Helper(function) \
    __asm \
    ( \
        /* vPortFreeRTOSInterruptCommonHandler_C() doesn't return here. */ \
        "movw bc, #__" #function " \n" \
        "br   _vPortFreeRTOSInterruptCommonHandler_C \n" \
    )

#endif

#define R_CG_FREERTOS_INTERRUPT(function) \
    function(void); \
    __near_func void _##function(void); \
    static __interrupt void function(void) \
    { \
        /* vPortFreeRTOSInterruptCommonHandler_C_Helper() doesn't return here. */ \
        vPortFreeRTOSInterruptCommonHandler_C_Helper(function); \
        /* The following line is just to prevent the symbol getting optimised away. */ \
        vPortFreeRTOSInterruptCommonHandler_C(); \
        /* The following is intended to remove the epilogue code. */ \
        while (1) {} \
    } \
    __near_func void _##function

#endif

#endif
