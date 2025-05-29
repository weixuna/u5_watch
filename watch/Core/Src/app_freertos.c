/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * File Name          : app_freertos.c
 * Description        : FreeRTOS applicative file
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

/* Includes ------------------------------------------------------------------*/
#include "app_freertos.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include "i2c.h"
#include <string.h>
#include "app_touchgfx.h"
#include "../BSP/BMP280/BMP280.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for defaultTask */

osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
    .name = "defaultTask",
    .priority = (osPriority_t)osPriorityNormal,
    .stack_size = 128 * 4};

// GUI任务
osThreadId_t GUI_TaskHandle;
const osThreadAttr_t GUI_Task_attributes = {
    .name = "GUI_Task",
    .priority = (osPriority_t)osPriorityNormal,
    .stack_size = 10240 * 4};

// BMP280任务
osThreadId_t BMP280_TaskHandle;
const osThreadAttr_t BMP280_Task_attributes = {
    .name = "BMP280_Task",
    .priority = (osPriority_t)osPriorityNormal,
    .stack_size = 2048 * 4};

/*##################   以下是创建互斥锁   ################################*/
osMutexId_t i2cMutexHandle;
const osMutexAttr_t i2cMutex_attributes = {
    .name = "i2cMutex"};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

/**
 * @brief  FreeRTOS initialization
 * @param  None
 * @retval None
 */
void MX_FREERTOS_Init(void)
{
    /* USER CODE BEGIN Init */

    /* USER CODE END Init */

    /* USER CODE BEGIN RTOS_MUTEX */
    /* add mutexes, ... */

    i2cMutexHandle = osMutexNew(&i2cMutex_attributes);
    /* USER CODE END RTOS_MUTEX */

    /* USER CODE BEGIN RTOS_SEMAPHORES */
    /* add semaphores, ... */
    /* USER CODE END RTOS_SEMAPHORES */

    /* USER CODE BEGIN RTOS_TIMERS */
    /* start timers, add new ones, ... */
    /* USER CODE END RTOS_TIMERS */

    /* USER CODE BEGIN RTOS_QUEUES */
    /* add queues, ... */
    /* USER CODE END RTOS_QUEUES */
    /* creation of defaultTask */
    defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

    GUI_TaskHandle = osThreadNew(TouchGFX_GUI, NULL, &GUI_Task_attributes);
    BMP280_TaskHandle = osThreadNew(BMP280_Task, NULL, &BMP280_Task_attributes);
    /* USER CODE BEGIN RTOS_THREADS */
    /* add threads, ... */
    /* USER CODE END RTOS_THREADS */

    /* USER CODE BEGIN RTOS_EVENTS */
    /* add events, ... */
    /* USER CODE END RTOS_EVENTS */
}
/* USER CODE BEGIN Header_StartDefaultTask */
/**
 * @brief Function implementing the defaultTask thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
    /* USER CODE BEGIN defaultTask */

    /* Infinite loop */
    for (;;)
    {
        osDelay(1);
    }
    /* USER CODE END defaultTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

void TouchGFX_GUI(void *argument)
{
    /* USER CODE BEGIN defaultTask */
    MX_TouchGFX_Process();

    /* Infinite loop */
    for (;;)
    {
        osDelay(1);
    }
    /* USER CODE END defaultTask */
}

BMP280_HandleTypedef bmp280;

float pressure, temperature, humidity;
void BMP280_Task(void *argument)
{

    bmp280_init_default_params(&bmp280.params);
    bmp280.addr = BMP280_I2C_ADDRESS_0;
    bmp280.i2c = &hi2c3;

    // 初始化时获取锁
    osMutexAcquire(i2cMutexHandle, osWaitForever);
    while (!bmp280_init(&bmp280, &bmp280.params))
    {
        // printf("BMP280 init error...\r\n");
        osMutexRelease(i2cMutexHandle); // 释放锁
        osDelay(100);
        osMutexAcquire(i2cMutexHandle, osWaitForever); // 重新获取锁
    }
    osMutexRelease(i2cMutexHandle); // 释放锁
    for (;;)
    {
        // 获取锁
        osMutexAcquire(i2cMutexHandle, osWaitForever);
        if (bmp280_read_float(&bmp280, &temperature, &pressure, &humidity))
        {
            // printf("pre: %.2f Pa, temp %.2f C\r\n", pressure, temperature);
        }
        else
        {
            // printf("BMP280 read error...\r\n");
        }
        // 读取后释放锁
        osMutexRelease(i2cMutexHandle);
        osDelay(2000);
    }
}
/* USER CODE END Application */
