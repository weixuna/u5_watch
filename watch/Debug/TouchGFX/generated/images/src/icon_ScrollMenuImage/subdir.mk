################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Address_Book.cpp \
../TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Blood_oxygen.cpp \
../TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Compass.cpp \
../TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Contact_person.cpp \
../TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Heart_rate.cpp \
../TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Regularly.cpp \
../TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Settings.cpp \
../TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Sport.cpp \
../TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_location.cpp 

OBJS += \
./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Address_Book.o \
./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Blood_oxygen.o \
./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Compass.o \
./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Contact_person.o \
./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Heart_rate.o \
./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Regularly.o \
./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Settings.o \
./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Sport.o \
./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_location.o 

CPP_DEPS += \
./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Address_Book.d \
./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Blood_oxygen.d \
./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Compass.d \
./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Contact_person.d \
./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Heart_rate.d \
./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Regularly.d \
./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Settings.d \
./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Sport.d \
./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_location.d 


# Each subdirectory must supply rules for building sources it contributes
TouchGFX/generated/images/src/icon_ScrollMenuImage/%.o TouchGFX/generated/images/src/icon_ScrollMenuImage/%.su TouchGFX/generated/images/src/icon_ScrollMenuImage/%.cyclo: ../TouchGFX/generated/images/src/icon_ScrollMenuImage/%.cpp TouchGFX/generated/images/src/icon_ScrollMenuImage/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m33 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U575xx -c -I../Core/Inc -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Drivers/STM32U5xx_HAL_Driver/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include/ -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -I../Middlewares/Third_Party/CMSIS/RTOS2/Include/ -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/generated/videos/include -I../TouchGFX/gui/include -I"D:/GitHub/u5_watch/watch/BSP" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-TouchGFX-2f-generated-2f-images-2f-src-2f-icon_ScrollMenuImage

clean-TouchGFX-2f-generated-2f-images-2f-src-2f-icon_ScrollMenuImage:
	-$(RM) ./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Address_Book.cyclo ./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Address_Book.d ./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Address_Book.o ./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Address_Book.su ./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Blood_oxygen.cyclo ./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Blood_oxygen.d ./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Blood_oxygen.o ./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Blood_oxygen.su ./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Compass.cyclo ./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Compass.d ./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Compass.o ./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Compass.su ./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Contact_person.cyclo ./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Contact_person.d ./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Contact_person.o ./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Contact_person.su ./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Heart_rate.cyclo ./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Heart_rate.d ./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Heart_rate.o ./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Heart_rate.su ./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Regularly.cyclo ./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Regularly.d ./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Regularly.o ./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Regularly.su ./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Settings.cyclo ./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Settings.d ./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Settings.o ./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Settings.su ./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Sport.cyclo ./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Sport.d ./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Sport.o ./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_Sport.su ./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_location.cyclo ./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_location.d ./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_location.o ./TouchGFX/generated/images/src/icon_ScrollMenuImage/image_icon_location.su

.PHONY: clean-TouchGFX-2f-generated-2f-images-2f-src-2f-icon_ScrollMenuImage

