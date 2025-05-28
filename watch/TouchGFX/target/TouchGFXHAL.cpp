/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * File Name          : TouchGFXHAL.cpp
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

#include <TouchGFXHAL.hpp>

/* USER CODE BEGIN TouchGFXHAL.cpp */

#include <stdio.h>
#include "../BSP/ICNA3306/icna3306.h"
#include <touchgfx/hal/OSWrappers.hpp>
#include "stm32u5xx_hal.h"
#include <touchgfx/hal/GPIO.hpp>

using namespace touchgfx;

void TouchGFXHAL::initialize()
{
    // Calling parent implementation of initialize().
    //
    // To overwrite the generated implementation, omit the call to the parent function
    // and implement the needed functionality here.
    // Please note, HAL::initialize() must be called to initialize the framework.

    printf("ICNA3306_Init\r\n");

    TouchGFXGeneratedHAL::initialize();
    // setAnimationStorage((void *)animationBuffer); // Add animation storage
    ICNA3306_Init();
}

/**
 * Gets the frame buffer address used by the TFT controller.
 *
 * @return The address of the frame buffer currently being displayed on the TFT.
 */
uint16_t *TouchGFXHAL::getTFTFrameBuffer() const
{
    // Calling parent implementation of getTFTFrameBuffer().
    //
    // To overwrite the generated implementation, omit the call to the parent function
    // and implement the needed functionality here.

    return TouchGFXGeneratedHAL::getTFTFrameBuffer();
}

/**
 * Sets the frame buffer address used by the TFT controller.
 *
 * @param [in] address New frame buffer address.
 */
void TouchGFXHAL::setTFTFrameBuffer(uint16_t *address)
{
    // Calling parent implementation of setTFTFrameBuffer(uint16_t* address).
    //
    // To overwrite the generated implementation, omit the call to the parent function
    // and implement the needed functionality here.

    TouchGFXGeneratedHAL::setTFTFrameBuffer(address);
}

/**
 * This function is called whenever the framework has performed a partial draw.
 *
 * @param rect The area of the screen that has been drawn, expressed in absolute coordinates.
 *
 * @see flushFrameBuffer().
 */
void TouchGFXHAL::flushFrameBuffer(const touchgfx::Rect &rect)
{
    // Calling parent implementation of flushFrameBuffer(const touchgfx::Rect& rect).
    //
    // To overwrite the generated implementation, omit the call to the parent function
    // and implement the needed functionality here.
    // Please note, HAL::flushFrameBuffer(const touchgfx::Rect& rect) must
    // be called to notify the touchgfx framework that flush has been performed.
    // To calculate the start address of rect,
    // use advanceFrameBufferToRect(uint8_t* fbPtr, const touchgfx::Rect& rect)
    // defined in TouchGFXGeneratedHAL.cpp
    // printf("fluashBuffer\r\n");
    uint8_t *fbPtr = (uint8_t *)getClientFrameBuffer();
    for (size_t row = 0; row < rect.height; row++)
    {
        uint8_t *pixel = fbPtr + ((rect.y + row) * 240 + rect.x) * 2;
        for (size_t col = 0; col < rect.width; col++)
        {
            uint8_t temp = pixel[0];
            pixel[0] = pixel[1];
            pixel[1] = temp;
            pixel += 2;
        }
    }
    // printf("fluashBuffer\r\n");
    ICNA3306_DrawBuffer(0, 0, 240, 296, fbPtr, (240 * 296) * 2);

    TouchGFXGeneratedHAL::flushFrameBuffer(rect);
}

bool TouchGFXHAL::blockCopy(void *RESTRICT dest, const void *RESTRICT src, uint32_t numBytes)
{
    return TouchGFXGeneratedHAL::blockCopy(dest, src, numBytes);
}

/**
 * Configures the interrupts relevant for TouchGFX. This primarily entails setting
 * the interrupt priorities for the DMA and LCD interrupts.
 */
void TouchGFXHAL::configureInterrupts()
{
    // Calling parent implementation of configureInterrupts().
    //
    // To overwrite the generated implementation, omit the call to the parent function
    // and implement the needed functionality here.

    TouchGFXGeneratedHAL::configureInterrupts();
}

/**
 * Used for enabling interrupts set in configureInterrupts()
 */
void TouchGFXHAL::enableInterrupts()
{
    // Calling parent implementation of enableInterrupts().
    //
    // To overwrite the generated implementation, omit the call to the parent function
    // and implement the needed functionality here.

    TouchGFXGeneratedHAL::enableInterrupts();
}

/**
 * Used for disabling interrupts set in configureInterrupts()
 */
void TouchGFXHAL::disableInterrupts()
{
    // Calling parent implementation of disableInterrupts().
    //
    // To overwrite the generated implementation, omit the call to the parent function
    // and implement the needed functionality here.

    TouchGFXGeneratedHAL::disableInterrupts();
}

/**
 * Configure the LCD controller to fire interrupts at VSYNC. Called automatically
 * once TouchGFX initialization has completed.
 */
void TouchGFXHAL::enableLCDControllerInterrupt()
{
    // Calling parent implementation of enableLCDControllerInterrupt().
    //
    // To overwrite the generated implementation, omit the call to the parent function
    // and implement the needed functionality here.

    TouchGFXGeneratedHAL::enableLCDControllerInterrupt();
}

bool TouchGFXHAL::beginFrame()
{
    //printf("TouchGFX beginFrame\n");
    return TouchGFXGeneratedHAL::beginFrame();
}

void TouchGFXHAL::endFrame()
{
    //printf("TouchGFX endFrame\n");
    TouchGFXGeneratedHAL::endFrame();
}
extern "C" void touchgfx_tim_vsync(void)
{
    OSWrappers::signalVSync();
    // printf("5555\r\n");
}
/* USER CODE END TouchGFXHAL.cpp */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
