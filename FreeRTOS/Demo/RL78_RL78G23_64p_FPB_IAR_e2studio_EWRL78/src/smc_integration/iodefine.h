/* Workaround for including device specific header files in case of RL78 Smart Configurator + e2 studio.
 */
#if defined(RL78_G23_FPB)
    #if defined(__CCRL__)
        #include "../smc_gen/r_bsp/mcu/rl78_g23/register_access/ccrl/iodefine.h"
    #elif defined(__llvm__) || defined(__GNUC__)
        #include "../smc_gen/r_bsp/mcu/rl78_g23/register_access/llvm/iodefine.h"
    #endif
#else
    #error "Currently the specified MCU (or board) is not supported. Please modify the code here."
#endif
