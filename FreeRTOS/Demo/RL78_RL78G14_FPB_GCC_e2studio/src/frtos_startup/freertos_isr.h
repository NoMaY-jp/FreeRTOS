#ifndef FREERTOS_ISR_H
#define FREERTOS_ISR_H

#if defined(__CCRL__)

#ifndef __CDT_PARSER__
#define R_CG_ASM(...) __VA_ARGS__
#else
#define R_CG_ASM(...)
#endif

extern __near void vPortFreeRTOSInterruptCommonHandler_C(void);
extern __near void vPortInterruptCommonHandler_C(void);

#pragma inline_asm vPortFreeRTOSInterruptCommonHandler_C_Helper1
static void __near vPortFreeRTOSInterruptCommonHandler_C_Helper1(void)
{
    /* Always ucInterruptNesting is zero here, so interrupt stack isn't in use here. */
    R_CG_ASM( oneb !_ucInterruptStackNesting );
    R_CG_ASM( movw de, sp );
    R_CG_ASM( movw sp, #loww(__STACK_ADDR_START) );
    /* Don't enable nested interrupts from the beginning of interrupt until
    the completion of switching the stack from task stacks to interrupt
    stack.  If it is enabled before switching the stack to interrupt
    stack, each task stack need additional space for nested interrupt.
    Moreover ucInterruptStackNesting has to be modified under DI state
    so that the stack isn't switched correctly. */
}

#pragma inline_asm vPortFreeRTOSInterruptCommonHandler_C_Helper2
static void __near vPortFreeRTOSInterruptCommonHandler_C_Helper2(void (__near *func)(void))
{
    /* vPortFreeRTOSInterruptCommonHandler_C() doesn't return here. */
    R_CG_ASM( movw bc, ax );
    R_CG_ASM( br !_vPortFreeRTOSInterruptCommonHandler_C );
}

#define R_CG_FREERTOS_INTERRUPT(function) \
    function(void); \
    static void __near _##function(void); \
    static void __near function(void) \
    { \
        /* vPortFreeRTOSInterruptCommonHandler_C_Helper() doesn't return here. */ \
        vPortFreeRTOSInterruptCommonHandler_C_Helper1(); \
        vPortFreeRTOSInterruptCommonHandler_C_Helper2( (void (__near *)(void))_##function ); \
        /* The following is intended to remove the epilogue code. */ \
        while (1) {} \
    } \
    static void __near _##function

#define R_CG_FREERTOS_INTERRUPT_EI(function) \
    function(void); \
    static void __near _##function(void); \
    static void __near function(void) \
    { \
        /* vPortFreeRTOSInterruptCommonHandler_C_Helper() doesn't return here. */ \
        vPortFreeRTOSInterruptCommonHandler_C_Helper1(); \
        __EI(); \
        vPortFreeRTOSInterruptCommonHandler_C_Helper2( (void (__near *)(void))_##function ); \
        /* The following is intended to remove the epilogue code. */ \
        while (1) {} \
    } \
    static void __near _##function

#pragma inline_asm vPortInterruptCommonHandler_C_Helper1
static void __near vPortInterruptCommonHandler_C_Helper1(void)
{
    R_CG_ASM( .local .skip_switching_sp );
    /* If ucInterruptNesting isn't zero, interrupt stack is in use. */
    R_CG_ASM( cmp0 !_ucInterruptStackNesting );
    R_CG_ASM( bnz $.skip_switching_sp );
    R_CG_ASM( movw de, sp );
    R_CG_ASM( movw sp, #loww(__STACK_ADDR_START) );
    R_CG_ASM( .skip_switching_sp: );
    R_CG_ASM( inc !_ucInterruptStackNesting );
    /* Don't enable nested interrupts from the beginning of interrupt until
    the completion of switching the stack from task stacks to interrupt
    stack.  If it is enabled before switching the stack to interrupt
    stack, each task stack need additional space for nested interrupt.
    Moreover ucInterruptStackNesting has to be modified under DI state
    so that the stack isn't switched correctly. */
}

#pragma inline_asm vPortInterruptCommonHandler_C_Helper2
static void __near vPortInterruptCommonHandler_C_Helper2(void (__near *func)(void))
{
    /* vPortFreeRTOSInterruptCommonHandler_C() doesn't return here. */
    R_CG_ASM( movw bc, ax );
    R_CG_ASM( br !_vPortInterruptCommonHandler_C );
}

#define R_CG_INTERRUPT(function) \
    function(void); \
    static void __near _##function(void); \
    static void __near function(void) \
    { \
        /* vPortInterruptCommonHandler_C_Helper() doesn't return here. */ \
        vPortInterruptCommonHandler_C_Helper1(); \
        vPortInterruptCommonHandler_C_Helper2( (void (__near *)(void))_##function ); \
        /* The following is intended to remove the epilogue code. */ \
        while (1) {} \
    } \
    static void __near _##function

#define R_CG_INTERRUPT_EI(function) \
    function(void); \
    static void __near _##function(void); \
    static void __near function(void) \
    { \
        /* vPorInterruptCommonHandler_C_Helper() doesn't return here. */ \
        vPortInterruptCommonHandler_C_Helper1(); \
        __EI(); \
        vPortInterruptCommonHandler_C_Helper2( (void (__near *)(void))_##function ); \
        /* The following is intended to remove the epilogue code. */ \
        while (1) {} \
    } \
    static void __near _##function

#elif defined(__GNUC__)

extern void vPortFreeRTOSInterruptCommonHandler_C(void) __attribute__((section(".lowtext")));
extern void vPortInterruptCommonHandler_C(void) __attribute__((section(".lowtext")));

/* The function attribute 'naked' is available for our purpos
 * but it causes the following compiler warning.
 *
 * warning: stack usage computation not supported for this target
 *
 * So the following asm code outside function is used instead.
 */

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

#define R_CG_INTERRUPT(function) \
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
        "br !_vPortInterruptCommonHandler_C \n" \
    ); \
    void _##function

#define R_CG_INTERRUPT_EI(function) \
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
        "br !_vPortInterruptCommonHandler_C \n" \
    ); \
    void _##function

#elif defined(__ICCRL78__)

extern __near_func void vPortFreeRTOSInterruptCommonHandler_C(void);
extern __near_func void vPortInterruptCommonHandler_C(void);

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

#if defined(RENESAS_SIMULATOR_DEBUGGING)

#define vPortInterruptCommonHandler_C_Helper(_function) \
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
        "br   _vPortInterruptCommonHandler_C \n" \
    )

#else

#define vPortInterruptCommonHandler_C_Helper(_function) \
    __asm \
    ( \
        /* vPortFreeRTOSInterruptCommonHandler_C() doesn't return here. */ \
        "movw bc, #_" #_function " \n" \
        "br   _vPortInterruptCommonHandler_C \n" \
    )

#endif

#define R_CG_INTERRUPT(function) \
    function(void); \
    __near_func void _##function(void); \
    static __interrupt void function(void) \
    { \
        /* vPortFreeRTOSInterruptCommonHandler_C_Helper() doesn't return here. */ \
        vPortInterruptCommonHandler_C_Helper(_##function); \
        /* The following line is just to prevent the symbol getting optimised away. */ \
        vPortInterruptCommonHandler_C(); \
        /* The following is intended to remove the epilogue code. */ \
        while (1) {} \
    } \
    __near_func void _##function

#define R_CG_INTERRUPT_EI(function) \
    function(void); \
    __near_func void _##function(void); \
    static __interrupt void function(void) \
    { \
        __enable_interrupt(); \
        /* vPortFreeRTOSInterruptCommonHandler_C_Helper() doesn't return here. */ \
        vPortInterruptCommonHandler_C_Helper(_##function); \
        /* The following line is just to prevent the symbol getting optimised away. */ \
        vPortInterruptCommonHandler_C(); \
        /* The following is intended to remove the epilogue code. */ \
        while (1) {} \
    } \
    __near_func void _##function

#endif

#endif
