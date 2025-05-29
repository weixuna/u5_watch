################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TouchGFX/generated/fonts/src/ApplicationFontProvider.cpp \
../TouchGFX/generated/fonts/src/CachedFont.cpp \
../TouchGFX/generated/fonts/src/CompressedFontCache.cpp \
../TouchGFX/generated/fonts/src/CompressedUnmappedFontCache.cpp \
../TouchGFX/generated/fonts/src/FontCache.cpp \
../TouchGFX/generated/fonts/src/Font_verdana_10_4bpp_0.cpp \
../TouchGFX/generated/fonts/src/Font_verdana_20_4bpp_0.cpp \
../TouchGFX/generated/fonts/src/Font_verdana_40_4bpp_0.cpp \
../TouchGFX/generated/fonts/src/GeneratedFont.cpp \
../TouchGFX/generated/fonts/src/Kerning_verdana_10_4bpp.cpp \
../TouchGFX/generated/fonts/src/Kerning_verdana_20_4bpp.cpp \
../TouchGFX/generated/fonts/src/Kerning_verdana_40_4bpp.cpp \
../TouchGFX/generated/fonts/src/Table_verdana_10_4bpp.cpp \
../TouchGFX/generated/fonts/src/Table_verdana_20_4bpp.cpp \
../TouchGFX/generated/fonts/src/Table_verdana_40_4bpp.cpp \
../TouchGFX/generated/fonts/src/UnmappedDataFont.cpp \
../TouchGFX/generated/fonts/src/VectorFontRendererBuffers.cpp \
../TouchGFX/generated/fonts/src/Vector_Font_STXIHEI_TTF_0.cpp \
../TouchGFX/generated/fonts/src/Vector_Font_STXIHEI_TTF_15.cpp \
../TouchGFX/generated/fonts/src/Vector_Font_STXIHEI_TTF_17.cpp \
../TouchGFX/generated/fonts/src/Vector_Kerning_STXIHEI_TTF.cpp \
../TouchGFX/generated/fonts/src/Vector_Table_STXIHEI_TTF.cpp \
../TouchGFX/generated/fonts/src/Vector_Table_STXIHEI_TTF_25.cpp 

OBJS += \
./TouchGFX/generated/fonts/src/ApplicationFontProvider.o \
./TouchGFX/generated/fonts/src/CachedFont.o \
./TouchGFX/generated/fonts/src/CompressedFontCache.o \
./TouchGFX/generated/fonts/src/CompressedUnmappedFontCache.o \
./TouchGFX/generated/fonts/src/FontCache.o \
./TouchGFX/generated/fonts/src/Font_verdana_10_4bpp_0.o \
./TouchGFX/generated/fonts/src/Font_verdana_20_4bpp_0.o \
./TouchGFX/generated/fonts/src/Font_verdana_40_4bpp_0.o \
./TouchGFX/generated/fonts/src/GeneratedFont.o \
./TouchGFX/generated/fonts/src/Kerning_verdana_10_4bpp.o \
./TouchGFX/generated/fonts/src/Kerning_verdana_20_4bpp.o \
./TouchGFX/generated/fonts/src/Kerning_verdana_40_4bpp.o \
./TouchGFX/generated/fonts/src/Table_verdana_10_4bpp.o \
./TouchGFX/generated/fonts/src/Table_verdana_20_4bpp.o \
./TouchGFX/generated/fonts/src/Table_verdana_40_4bpp.o \
./TouchGFX/generated/fonts/src/UnmappedDataFont.o \
./TouchGFX/generated/fonts/src/VectorFontRendererBuffers.o \
./TouchGFX/generated/fonts/src/Vector_Font_STXIHEI_TTF_0.o \
./TouchGFX/generated/fonts/src/Vector_Font_STXIHEI_TTF_15.o \
./TouchGFX/generated/fonts/src/Vector_Font_STXIHEI_TTF_17.o \
./TouchGFX/generated/fonts/src/Vector_Kerning_STXIHEI_TTF.o \
./TouchGFX/generated/fonts/src/Vector_Table_STXIHEI_TTF.o \
./TouchGFX/generated/fonts/src/Vector_Table_STXIHEI_TTF_25.o 

CPP_DEPS += \
./TouchGFX/generated/fonts/src/ApplicationFontProvider.d \
./TouchGFX/generated/fonts/src/CachedFont.d \
./TouchGFX/generated/fonts/src/CompressedFontCache.d \
./TouchGFX/generated/fonts/src/CompressedUnmappedFontCache.d \
./TouchGFX/generated/fonts/src/FontCache.d \
./TouchGFX/generated/fonts/src/Font_verdana_10_4bpp_0.d \
./TouchGFX/generated/fonts/src/Font_verdana_20_4bpp_0.d \
./TouchGFX/generated/fonts/src/Font_verdana_40_4bpp_0.d \
./TouchGFX/generated/fonts/src/GeneratedFont.d \
./TouchGFX/generated/fonts/src/Kerning_verdana_10_4bpp.d \
./TouchGFX/generated/fonts/src/Kerning_verdana_20_4bpp.d \
./TouchGFX/generated/fonts/src/Kerning_verdana_40_4bpp.d \
./TouchGFX/generated/fonts/src/Table_verdana_10_4bpp.d \
./TouchGFX/generated/fonts/src/Table_verdana_20_4bpp.d \
./TouchGFX/generated/fonts/src/Table_verdana_40_4bpp.d \
./TouchGFX/generated/fonts/src/UnmappedDataFont.d \
./TouchGFX/generated/fonts/src/VectorFontRendererBuffers.d \
./TouchGFX/generated/fonts/src/Vector_Font_STXIHEI_TTF_0.d \
./TouchGFX/generated/fonts/src/Vector_Font_STXIHEI_TTF_15.d \
./TouchGFX/generated/fonts/src/Vector_Font_STXIHEI_TTF_17.d \
./TouchGFX/generated/fonts/src/Vector_Kerning_STXIHEI_TTF.d \
./TouchGFX/generated/fonts/src/Vector_Table_STXIHEI_TTF.d \
./TouchGFX/generated/fonts/src/Vector_Table_STXIHEI_TTF_25.d 


# Each subdirectory must supply rules for building sources it contributes
TouchGFX/generated/fonts/src/%.o TouchGFX/generated/fonts/src/%.su TouchGFX/generated/fonts/src/%.cyclo: ../TouchGFX/generated/fonts/src/%.cpp TouchGFX/generated/fonts/src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m33 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U575xx -c -I../Core/Inc -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Drivers/STM32U5xx_HAL_Driver/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include/ -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -I../Middlewares/Third_Party/CMSIS/RTOS2/Include/ -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/generated/videos/include -I../TouchGFX/gui/include -I"D:/GitHub/u5_watch/watch/BSP" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-TouchGFX-2f-generated-2f-fonts-2f-src

clean-TouchGFX-2f-generated-2f-fonts-2f-src:
	-$(RM) ./TouchGFX/generated/fonts/src/ApplicationFontProvider.cyclo ./TouchGFX/generated/fonts/src/ApplicationFontProvider.d ./TouchGFX/generated/fonts/src/ApplicationFontProvider.o ./TouchGFX/generated/fonts/src/ApplicationFontProvider.su ./TouchGFX/generated/fonts/src/CachedFont.cyclo ./TouchGFX/generated/fonts/src/CachedFont.d ./TouchGFX/generated/fonts/src/CachedFont.o ./TouchGFX/generated/fonts/src/CachedFont.su ./TouchGFX/generated/fonts/src/CompressedFontCache.cyclo ./TouchGFX/generated/fonts/src/CompressedFontCache.d ./TouchGFX/generated/fonts/src/CompressedFontCache.o ./TouchGFX/generated/fonts/src/CompressedFontCache.su ./TouchGFX/generated/fonts/src/CompressedUnmappedFontCache.cyclo ./TouchGFX/generated/fonts/src/CompressedUnmappedFontCache.d ./TouchGFX/generated/fonts/src/CompressedUnmappedFontCache.o ./TouchGFX/generated/fonts/src/CompressedUnmappedFontCache.su ./TouchGFX/generated/fonts/src/FontCache.cyclo ./TouchGFX/generated/fonts/src/FontCache.d ./TouchGFX/generated/fonts/src/FontCache.o ./TouchGFX/generated/fonts/src/FontCache.su ./TouchGFX/generated/fonts/src/Font_verdana_10_4bpp_0.cyclo ./TouchGFX/generated/fonts/src/Font_verdana_10_4bpp_0.d ./TouchGFX/generated/fonts/src/Font_verdana_10_4bpp_0.o ./TouchGFX/generated/fonts/src/Font_verdana_10_4bpp_0.su ./TouchGFX/generated/fonts/src/Font_verdana_20_4bpp_0.cyclo ./TouchGFX/generated/fonts/src/Font_verdana_20_4bpp_0.d ./TouchGFX/generated/fonts/src/Font_verdana_20_4bpp_0.o ./TouchGFX/generated/fonts/src/Font_verdana_20_4bpp_0.su ./TouchGFX/generated/fonts/src/Font_verdana_40_4bpp_0.cyclo ./TouchGFX/generated/fonts/src/Font_verdana_40_4bpp_0.d ./TouchGFX/generated/fonts/src/Font_verdana_40_4bpp_0.o ./TouchGFX/generated/fonts/src/Font_verdana_40_4bpp_0.su ./TouchGFX/generated/fonts/src/GeneratedFont.cyclo ./TouchGFX/generated/fonts/src/GeneratedFont.d ./TouchGFX/generated/fonts/src/GeneratedFont.o ./TouchGFX/generated/fonts/src/GeneratedFont.su ./TouchGFX/generated/fonts/src/Kerning_verdana_10_4bpp.cyclo ./TouchGFX/generated/fonts/src/Kerning_verdana_10_4bpp.d ./TouchGFX/generated/fonts/src/Kerning_verdana_10_4bpp.o ./TouchGFX/generated/fonts/src/Kerning_verdana_10_4bpp.su ./TouchGFX/generated/fonts/src/Kerning_verdana_20_4bpp.cyclo ./TouchGFX/generated/fonts/src/Kerning_verdana_20_4bpp.d ./TouchGFX/generated/fonts/src/Kerning_verdana_20_4bpp.o ./TouchGFX/generated/fonts/src/Kerning_verdana_20_4bpp.su ./TouchGFX/generated/fonts/src/Kerning_verdana_40_4bpp.cyclo ./TouchGFX/generated/fonts/src/Kerning_verdana_40_4bpp.d ./TouchGFX/generated/fonts/src/Kerning_verdana_40_4bpp.o ./TouchGFX/generated/fonts/src/Kerning_verdana_40_4bpp.su ./TouchGFX/generated/fonts/src/Table_verdana_10_4bpp.cyclo ./TouchGFX/generated/fonts/src/Table_verdana_10_4bpp.d ./TouchGFX/generated/fonts/src/Table_verdana_10_4bpp.o ./TouchGFX/generated/fonts/src/Table_verdana_10_4bpp.su ./TouchGFX/generated/fonts/src/Table_verdana_20_4bpp.cyclo ./TouchGFX/generated/fonts/src/Table_verdana_20_4bpp.d ./TouchGFX/generated/fonts/src/Table_verdana_20_4bpp.o ./TouchGFX/generated/fonts/src/Table_verdana_20_4bpp.su ./TouchGFX/generated/fonts/src/Table_verdana_40_4bpp.cyclo ./TouchGFX/generated/fonts/src/Table_verdana_40_4bpp.d ./TouchGFX/generated/fonts/src/Table_verdana_40_4bpp.o ./TouchGFX/generated/fonts/src/Table_verdana_40_4bpp.su ./TouchGFX/generated/fonts/src/UnmappedDataFont.cyclo ./TouchGFX/generated/fonts/src/UnmappedDataFont.d ./TouchGFX/generated/fonts/src/UnmappedDataFont.o ./TouchGFX/generated/fonts/src/UnmappedDataFont.su ./TouchGFX/generated/fonts/src/VectorFontRendererBuffers.cyclo ./TouchGFX/generated/fonts/src/VectorFontRendererBuffers.d ./TouchGFX/generated/fonts/src/VectorFontRendererBuffers.o ./TouchGFX/generated/fonts/src/VectorFontRendererBuffers.su ./TouchGFX/generated/fonts/src/Vector_Font_STXIHEI_TTF_0.cyclo ./TouchGFX/generated/fonts/src/Vector_Font_STXIHEI_TTF_0.d ./TouchGFX/generated/fonts/src/Vector_Font_STXIHEI_TTF_0.o ./TouchGFX/generated/fonts/src/Vector_Font_STXIHEI_TTF_0.su ./TouchGFX/generated/fonts/src/Vector_Font_STXIHEI_TTF_15.cyclo ./TouchGFX/generated/fonts/src/Vector_Font_STXIHEI_TTF_15.d ./TouchGFX/generated/fonts/src/Vector_Font_STXIHEI_TTF_15.o ./TouchGFX/generated/fonts/src/Vector_Font_STXIHEI_TTF_15.su ./TouchGFX/generated/fonts/src/Vector_Font_STXIHEI_TTF_17.cyclo ./TouchGFX/generated/fonts/src/Vector_Font_STXIHEI_TTF_17.d ./TouchGFX/generated/fonts/src/Vector_Font_STXIHEI_TTF_17.o ./TouchGFX/generated/fonts/src/Vector_Font_STXIHEI_TTF_17.su ./TouchGFX/generated/fonts/src/Vector_Kerning_STXIHEI_TTF.cyclo ./TouchGFX/generated/fonts/src/Vector_Kerning_STXIHEI_TTF.d ./TouchGFX/generated/fonts/src/Vector_Kerning_STXIHEI_TTF.o ./TouchGFX/generated/fonts/src/Vector_Kerning_STXIHEI_TTF.su ./TouchGFX/generated/fonts/src/Vector_Table_STXIHEI_TTF.cyclo ./TouchGFX/generated/fonts/src/Vector_Table_STXIHEI_TTF.d ./TouchGFX/generated/fonts/src/Vector_Table_STXIHEI_TTF.o ./TouchGFX/generated/fonts/src/Vector_Table_STXIHEI_TTF.su ./TouchGFX/generated/fonts/src/Vector_Table_STXIHEI_TTF_25.cyclo ./TouchGFX/generated/fonts/src/Vector_Table_STXIHEI_TTF_25.d ./TouchGFX/generated/fonts/src/Vector_Table_STXIHEI_TTF_25.o ./TouchGFX/generated/fonts/src/Vector_Table_STXIHEI_TTF_25.su

.PHONY: clean-TouchGFX-2f-generated-2f-fonts-2f-src

