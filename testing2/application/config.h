#ifndef JINGAN_CONFIG_H_
#define JINGAN_CONFIG_H_

#include <stdint.h>
#include <stddef.h>

#ifdef __GNUC__
# define COMPILER_VERSION "GCC"__VERSION__
#else
#error  ""
#endif
typedef int32_t SAL_RET;
typedef int8_t sal_int8_t;
typedef int16_t sal_int16_t;
typedef int32_t sal_int32_t;
typedef int64_t sal_int64_t;
typedef uint8_t sal_uint8_t;
typedef uint16_t sal_uint16_t;
typedef uint32_t sal_uint32_t;
typedef uint64_t sal_uint64_t;
typedef int32_t sal_fix1616_t;
typedef int32_t sal_fix2408_t;
typedef int32_t sal_fix2012_t;
typedef sal_int16_t sal_bool_t;
// typedef float sal_float_t;

// //#define CALC_USING_FIX1616
// #ifdef CALC_USING_FIX1616
// typedef sal_int32_t sal_real32_t;
// #else
// typedef float sal_real32_t;
// #endif

#ifndef DTOF_FALSE
#define DTOF_FALSE (sal_bool_t)(0)
#endif
#ifndef DTOF_TRUE
#define DTOF_TRUE (sal_bool_t)(1)
#endif

#define SAL_RET_SUCCESS  DTOF_TRUE
#define SAL_RET_ERROR   DTOF_FALSE


// define the sensor default config--reg address--no use
// todo  fred lei
#define DTOF_MAIN_SPAD_START_ADDRESS   0xCC
#define DTOF_REF_SPAD_START_ADDRESS   0xD0
// 这里的定义 是寄存器 对于的个数
#define DTOF_MAIN_SPAD_MAX 4  // MAIN  SPAD
#define DTOF_REF_SPAD_MAX 1  // REF  SPAD
#define DTOF_SPAD_TOTAL (DTOF_MAIN_SPAD_MAX + DTOF_REF_SPAD_MAX)

// bit define
#define BIT_8_FF 0xFF
#define BIT_8_0F 0x0F
#define BIT_8_F0 0xF0
#define BIT_8_CHECK_NUM 2

// 用于pll en后的1ms延时全局宏
#define GLOBAL_PLL_DELAY_TIME 1


// system timer  7     level: 2  高电平触发
#define  SYSTEM_TIMER   0X07
#define  SYSTEM_TIMER_VALUE 0x5FC10100

// MCU  interrupt  19  level: 4  高电平触发
// TODO 子豪 需要 和 数字部门check 对于DSP 中断到内部的出发也需要check
//  这里 需要改成 上升沿出发
#define  SYSTEM_MCU_INTERRUPT   0X13
#define  SYSTEM_MCU_INTERRUPT_VALUE   0x9FC30100

// DSP  interrupt  20  level: 3  高电平触发
#define  SYSTEM_DSP_INTERRUPT   0X14
// TODO 子豪 需要 和 数字部门check 对于DSP 中断到内部的出发也需要check
#define  SYSTEM_DSP_INTERRUPT_VALUE   0x7FC30100

// eyes safe 21        level: 5  上升沿触发
#define  SYSTEM_EYESAFE_INTERRUPT   0X15
#define  SYSTEM_EYESAFE_INTERRUPT_VALUE   0xBFC30100

// watch dog           level: 6  高电平触发
#define  SYSTEM_WATHDOG_INTERRUPT   0X16
// TODO 子豪 记得丁香 测试过一个bug  不可以配置成 高电平
#define  SYSTEM_WATHDOG_INTERRUPT_VALUE   0xDFC30100

// testing flag
// #define  JINGAN_FUNCTION_DEBUG_TESTING

#endif
