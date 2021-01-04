#ifndef FREERTOS_ISR_H
#define FREERTOS_ISR_H

#if defined(__CCRL__)

#define R_CG_PRAGMA(...) _Pragma(#__VA_ARGS__)

extern __near void vPortFreeRTOSInterruptCommonHandler_C(void);

#pragma inline_asm vPortFreeRTOSInterruptCommonHandler_C_Helper

static void __near vPortFreeRTOSInterruptCommonHandler_C_Helper(void (__near *func)(void))
{
    /* vPortFreeRTOSInterruptCommonHandler_C() doesn't return here. */ \
    movw bc, ax
    br !_vPortFreeRTOSInterruptCommonHandler_C
}

#define R_CG_FREERTOS_INTERRUPT(function, vector) \
    function(void); \
    static void __near _##function(void); \
    R_CG_PRAGMA(interrupt function(vect=vector)) \
    static void  __near function(void) \
    { \
        /* vPortFreeRTOSInterruptCommonHandler_C_Helper() doesn't return here. */ \
        vPortFreeRTOSInterruptCommonHandler_C_Helper( (void (__near *)(void))_##function ); \
        /* The following is intended to remove the epilogue code. */ \
        while (1) {} \
    } \
    static void __near _##function

#define R_CG_FREERTOS_INTERRUPT_EI(function, vector) \
    function(void); \
    static void __near _##function(void); \
    R_CG_PRAGMA(interrupt function(vect=vector, enable=true)) \
    static void  __near function(void) \
    { \
        /* vPortFreeRTOSInterruptCommonHandler_C_Helper() doesn't return here. */ \
        vPortFreeRTOSInterruptCommonHandler_C_Helper( (void (__near *)(void))_##function ); \
        /* The following is intended to remove the epilogue code. */ \
        while (1) {} \
    } \
    static void __near _##function

#elif defined(__GNUC__)

extern void vPortFreeRTOSInterruptCommonHandler_C(void) __attribute__((section(".lowtext")));

#define R_CG_FREERTOS_INTERRUPT(function) \
    _##function(void) __attribute__((section(".lowtext." "_" #function))); \
    __asm \
    ( \
        ".section .lowtext." #function ",\"ax\",@progbits \n" \
        ".global _" #function " \n" \
        "_" #function ": \n" \
        "sel rb0 \n" \
        "push ax \n" \
        "push bc \n" \
        "movw bc, #__" #function " \n" \
        "br !_vPortFreeRTOSInterruptCommonHandler_C \n" \
    ); \
    void _##function

#define R_CG_FREERTOS_INTERRUPT_EI(function) \
    _##function(void) __attribute__((section(".lowtext." "_" #function))); \
    __asm \
    ( \
        ".section .lowtext." #function ",\"ax\",@progbits \n" \
        ".global _" #function " \n" \
        "_" #function ": \n" \
        "ei \n" \
        "sel rb0 \n" \
        "push ax \n" \
        "push bc \n" \
        "movw bc, #__" #function " \n" \
        "br !_vPortFreeRTOSInterruptCommonHandler_C \n" \
    ); \
    void _##function

#elif defined(__ICCRL78__)

extern __near_func void vPortFreeRTOSInterruptCommonHandler_C(void);

#if defined(RENESAS_SIMULATOR_DEBUGGING)

#define vPortFreeRTOSInterruptCommonHandler_C_Helper(_function) \
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
        "movw bc, #_" #_function " \n" \
        "br   _vPortFreeRTOSInterruptCommonHandler_C \n" \
    )

#else

#define vPortFreeRTOSInterruptCommonHandler_C_Helper(_function) \
    __asm \
    ( \
        /* vPortFreeRTOSInterruptCommonHandler_C() doesn't return here. */ \
        "movw bc, #_" #_function " \n" \
        "br   _vPortFreeRTOSInterruptCommonHandler_C \n" \
    )

#endif

#define R_CG_FREERTOS_INTERRUPT(function) \
    function(void); \
    __near_func void _##function(void); \
    static __interrupt void function(void) \
    { \
        /* vPortFreeRTOSInterruptCommonHandler_C_Helper() doesn't return here. */ \
        vPortFreeRTOSInterruptCommonHandler_C_Helper(_##function); \
        /* The following line is just to prevent the symbol getting optimised away. */ \
        vPortFreeRTOSInterruptCommonHandler_C(); \
        /* The following is intended to remove the epilogue code. */ \
        while (1) {} \
    } \
    __near_func void _##function

#define R_CG_FREERTOS_INTERRUPT_EI(function) \
    function(void); \
    __near_func void _##function(void); \
    static __interrupt void function(void) \
    { \
        __enable_interrupt(); \
        /* vPortFreeRTOSInterruptCommonHandler_C_Helper() doesn't return here. */ \
        vPortFreeRTOSInterruptCommonHandler_C_Helper(_##function); \
        /* The following line is just to prevent the symbol getting optimised away. */ \
        vPortFreeRTOSInterruptCommonHandler_C(); \
        /* The following is intended to remove the epilogue code. */ \
        while (1) {} \
    } \
    __near_func void _##function

#endif

#endif
