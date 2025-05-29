################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TouchGFX/generated/gui_generated/src/menupage_screen/menuPageViewBase.cpp 

OBJS += \
./TouchGFX/generated/gui_generated/src/menupage_screen/menuPageViewBase.o 

CPP_DEPS += \
./TouchGFX/generated/gui_generated/src/menupage_screen/menuPageViewBase.d 


# Each subdirectory must supply rules for building sources it contributes
TouchGFX/generated/gui_generated/src/menupage_screen/%.o TouchGFX/generated/gui_generated/src/menupage_screen/%.su TouchGFX/generated/gui_generated/src/menupage_screen/%.cyclo: ../TouchGFX/generated/gui_generated/src/menupage_screen/%.cpp TouchGFX/generated/gui_generated/src/menupage_screen/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m33 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U575xx -c -I../Core/Inc -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Drivers/STM32U5xx_HAL_Driver/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include/ -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -I../Middlewares/Third_Party/CMSIS/RTOS2/Include/ -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/generated/videos/include -I../TouchGFX/gui/include -I"D:/GitHub/u5_watch/watch/BSP" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-TouchGFX-2f-generated-2f-gui_generated-2f-src-2f-menupage_screen

clean-TouchGFX-2f-generated-2f-gui_generated-2f-src-2f-menupage_screen:
	-$(RM) ./TouchGFX/generated/gui_generated/src/menupage_screen/menuPageViewBase.cyclo ./TouchGFX/generated/gui_generated/src/menupage_screen/menuPageViewBase.d ./TouchGFX/generated/gui_generated/src/menupage_screen/menuPageViewBase.o ./TouchGFX/generated/gui_generated/src/menupage_screen/menuPageViewBase.su

.PHONY: clean-TouchGFX-2f-generated-2f-gui_generated-2f-src-2f-menupage_screen

