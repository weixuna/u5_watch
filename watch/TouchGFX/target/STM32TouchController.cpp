/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * File Name          : STM32TouchController.cpp
 ******************************************************************************
 * This file was created by TouchGFX Generator 4.25.0. This file is only
 * generated once! Delete this file from your project and re-generate code
 * using STM32CubeMX or change this file manually to update it.
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2025 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* USER CODE BEGIN STM32TouchController */
#include "../BSP/CST816D/cst816d.h"
#include <stdio.h>

#include <STM32TouchController.hpp>

void STM32TouchController::init()
{
    /**
     * Initialize touch controller and driver
     *
     */
    CST816D_Init();
    uint8_t irq_setting = EnTouch | EnChange | EnMotion;
    CST816D_SetIrqCtl(irq_setting);
    CST816D_SetMotionMask(0x07);
    printf("cst816d init\n");
}

bool STM32TouchController::sampleTouch(int32_t &x, int32_t &y)
{
    static int32_t lastX = 0;
    static int32_t lastY = 0;
    static bool wasTouched = false;
    static uint32_t touchStartTime = 0;
    static uint8_t lastGesture = 0;

    const int32_t MIN_X = 0;
    const int32_t MAX_X = 239;
    const int32_t MIN_Y = 0;
    const int32_t MAX_Y = 295;
    const int32_t MIN_DELTA = 1;

    if (CST816D_IsTouched())
    {
        uint8_t raw_data[7] = {0};
        extern HAL_StatusTypeDef CST816D_ReadReg(uint8_t reg_addr, uint8_t *data, uint16_t len);

        if (CST816D_ReadReg(0x01, raw_data, 7) == HAL_OK)
        {
            uint8_t gesture = raw_data[0];
            uint8_t finger_num = raw_data[1] & 0x0F;
            int32_t newX = ((uint16_t)(raw_data[2] & 0x0F) << 8) | raw_data[3];
            int32_t newY = ((uint16_t)(raw_data[4] & 0x0F) << 8) | raw_data[5];

            // printf("Raw: [%02X %02X %02X %02X %02X %02X %02X] -> fingers=%d, X=%ld, Y=%ld\n",
            //        raw_data[0], raw_data[1], raw_data[2], raw_data[3],
            //        raw_data[4], raw_data[5], raw_data[6],
            //        finger_num, newX, newY);

            if (finger_num > 0)
            {
                // 如果是新的触摸事件
                if (!wasTouched)
                {
                    touchStartTime = HAL_GetTick();
                    lastGesture = gesture;
                }

                // 确保坐标在有效范围内
                newX = (newX < MIN_X) ? MIN_X : (newX > MAX_X) ? MAX_X
                                                               : newX;
                newY = (newY < MIN_Y) ? MIN_Y : (newY > MAX_Y) ? MAX_Y
                                                               : newY;

                bool significantChange = !wasTouched ||
                                         abs(newX - lastX) > MIN_DELTA ||
                                         abs(newY - lastY) > MIN_DELTA;

                if (significantChange)
                {
                    x = newX;
                    y = newY;
                    lastX = x;
                    lastY = y;
                    // printf("Touch Event - X: %ld, Y: %ld, isDrag: %s, Gesture: 0x%02X\n",
                    //        x, y, wasTouched ? "true" : "false", gesture);
                }
                else
                {
                    x = lastX;
                    y = lastY;
                }

                wasTouched = true;
                return true;
            }
        }
    }
    else if (wasTouched)
    {
        // // 只在真正释放时发送一次释放事件
        // printf("Touch Released - Final X: %ld, Y: %ld, Duration: %ldms\n",
        //        lastX, lastY, HAL_GetTick() - touchStartTime);
        x = lastX;
        y = lastY;
        wasTouched = false;
        return true;
    }

    return false;
}

/* USER CODE END STM32TouchController */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
