#ifndef __BMP280_H__
#define __BMP280_H__

#include "stm32u5xx_hal.h"
#include <stdint.h>
#include <stdbool.h>

/**
 * 当 SDO 引脚为高电平时，BMP280 或 BME280 的地址为 0x77；
 * 当 SDO 引脚为低电平时，地址为 0x76。
 */

#define BMP280_I2C_ADDRESS_0 0x76
#define BMP280_I2C_ADDRESS_1 0x77

#define BMP280_CHIP_ID 0x58 /* BMP280 的芯片 ID 为 0x58 */
#define BME280_CHIP_ID 0x60 /* BME280 的芯片 ID 为 0x60 */

/**
 * BMP280 模块的工作模式
 * 强制模式 - 由用户触发测量
 * 正常模式 - 连续测量
 */
typedef enum
{
    BMP280_MODE_SLEEP = 0,
    BMP280_MODE_FORCED = 1,
    BMP280_MODE_NORMAL = 3
} BMP280_Mode;

typedef enum
{
    BMP280_FILTER_OFF = 0,
    BMP280_FILTER_2 = 1,
    BMP280_FILTER_4 = 2,
    BMP280_FILTER_8 = 3,
    BMP280_FILTER_16 = 4
} BMP280_Filter;

/**
 * 压力过采样设置
 */
typedef enum
{
    BMP280_SKIPPED = 0,         /* 不测量 */
    BMP280_ULTRA_LOW_POWER = 1, /* 1倍过采样 */
    BMP280_LOW_POWER = 2,       /* 2倍过采样 */
    BMP280_STANDARD = 3,        /* 4倍过采样 */
    BMP280_HIGH_RES = 4,        /* 8倍过采样 */
    BMP280_ULTRA_HIGH_RES = 5   /* 16倍过采样 */
} BMP280_Oversampling;

/**
 * 正常模式下测量之间的待机时间
 */
typedef enum
{
    BMP280_STANDBY_05 = 0,   /* 待机时间 0.5ms */
    BMP280_STANDBY_62 = 1,   /* 待机时间 62.5ms */
    BMP280_STANDBY_125 = 2,  /* 待机时间 125ms */
    BMP280_STANDBY_250 = 3,  /* 待机时间 250ms */
    BMP280_STANDBY_500 = 4,  /* 待机时间 500ms */
    BMP280_STANDBY_1000 = 5, /* 待机时间 1秒 */
    BMP280_STANDBY_2000 = 6, /* 待机时间：BMP280为2秒，BME280为10ms */
    BMP280_STANDBY_4000 = 7, /* 待机时间：BMP280为4秒，BME280为20ms */
} BMP280_StandbyTime;

/**
 * BMP280模块的配置参数
 * 使用 bmp280_init_default_params 函数来使用默认配置
 */
typedef struct
{
    BMP280_Mode mode;
    BMP280_Filter filter;
    BMP280_Oversampling oversampling_pressure;
    BMP280_Oversampling oversampling_temperature;
    BMP280_Oversampling oversampling_humidity;
    BMP280_StandbyTime standby;
} bmp280_params_t;

typedef struct
{
    uint16_t dig_T1;
    int16_t dig_T2;
    int16_t dig_T3;
    uint16_t dig_P1;
    int16_t dig_P2;
    int16_t dig_P3;
    int16_t dig_P4;
    int16_t dig_P5;
    int16_t dig_P6;
    int16_t dig_P7;
    int16_t dig_P8;
    int16_t dig_P9;

    /* BME280的湿度补偿参数 */
    uint8_t dig_H1;
    int16_t dig_H2;
    uint8_t dig_H3;
    int16_t dig_H4;
    int16_t dig_H5;
    int8_t dig_H6;

    uint16_t addr;

    I2C_HandleTypeDef *i2c;

    bmp280_params_t params;

    uint8_t id; /* 芯片ID */

} BMP280_HandleTypedef;

/**
 * 初始化默认参数
 * 默认配置：
 *      模式：正常模式
 *      滤波器：关闭
 *      过采样：4倍
 *      待机时间：250ms
 */
void bmp280_init_default_params(bmp280_params_t *params);

/**
 * 初始化BMP280模块，检测设备，执行软复位，
 * 读取校准常数，并使用提供的参数配置设备。
 * 成功返回true，失败返回false。
 *
 * 假设在dev中已经初始化了I2C地址，
 * 可以是BMP280_I2C_ADDRESS_0或BMP280_I2C_ADDRESS_1。
 * 如果不知道I2C地址，可以依次尝试每个地址。
 *
 * 该函数可以重复调用以进行软复位和重新初始化设备。
 */
bool bmp280_init(BMP280_HandleTypedef *dev, bmp280_params_t *params);

/**
 * 在强制模式下开始测量。
 * 调用此函数后，模块将保持在强制模式。
 * 在正常模式下请勿调用此方法。
 */
bool bmp280_force_measurement(BMP280_HandleTypedef *dev);

/**
 * 检查BMP280是否正在测量温度/压力。
 * 如果BMP280正忙，返回true。
 */
bool bmp280_is_measuring(BMP280_HandleTypedef *dev);

/**
 * 读取经过补偿的温度和压力数据：
 *
 *  温度单位为摄氏度乘以100。
 *
 *  压力单位为帕斯卡，使用24位整数8位小数的定点格式。
 *
 *  湿度是可选的，仅适用于BME280，以相对湿度百分比表示，
 *  使用22位整数10位小数的定点格式。
 */
bool bmp280_read_fixed(BMP280_HandleTypedef *dev, int32_t *temperature,
                       uint32_t *pressure, uint32_t *humidity);

/**
 * 读取经过补偿的温度和压力数据：
 *  温度单位为摄氏度。
 *  压力单位为帕斯卡。
 *  湿度是可选的，仅适用于BME280，以相对湿度百分比表示。
 */
bool bmp280_read_float(BMP280_HandleTypedef *dev, float *temperature,
                       float *pressure, float *humidity);

#endif // __BMP280_H__
