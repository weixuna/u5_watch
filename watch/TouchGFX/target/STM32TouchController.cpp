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
#include <stdio.h>
#include "../BSP/CST816D/cst816d.h"

#include <STM32TouchController.hpp>

// 触摸控制器状态结构体
typedef struct
{
    uint16_t touchX;
    uint16_t touchY;
    bool touched;
} TouchControllerState;

// 触摸状态获取函数声明
static bool myTouchController_GetState(TouchControllerState *state);

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
    /**
     * By default sampleTouch returns false,
     * return true if a touch has been detected, otherwise false.
     *
     * Coordinates are passed to the caller by reference by x and y.
     *
     * This function is called by the TouchGFX framework.
     * By default sampleTouch is called every tick, this can be adjusted by HAL::setTouchSampleRate(int8_t);
     *
     */
    TouchControllerState state;
    if (myTouchController_GetState(&state))
    {
        x = state.touchX;
        y = state.touchY;
        return true;
    }
    return false; // 无触摸
}

static bool myTouchController_GetState(TouchControllerState *state)
{
    static int32_t lastX = 0;
    static int32_t lastY = 0;
    static bool wasTouched = false;
    static bool justReleased = false;

    // 检查触摸状态
    if (CST816D_IsTouched())
    {
        CST816D_TouchData touchData;

        if (CST816D_GetTouchData(&touchData) == HAL_OK && touchData.finger_num > 0)
        {
            // 获取坐标
            state->touchX = touchData.x;
            state->touchY = touchData.y;
            lastX = state->touchX;
            lastY = state->touchY;

            wasTouched = true;
            justReleased = false;
            state->touched = true;

            return true;
        }
    }
    else if (wasTouched)
    {
        // 触摸刚刚结束
        if (!justReleased)
        {
            // 发送最后一个触摸位置
            state->touchX = lastX;
            state->touchY = lastY;
            state->touched = true;
            justReleased = true;

            return true;
        }
        else
        {
            // 恢复到未触摸状态
            justReleased = false;
            wasTouched = false;
        }
    }

    state->touched = false;
    return false;
}

/* USER CODE END STM32TouchController */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
