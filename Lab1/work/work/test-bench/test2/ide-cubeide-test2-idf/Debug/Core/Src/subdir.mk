################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/main.c \
../Core/Src/stm32f7xx_hal_msp.c \
../Core/Src/stm32f7xx_it.c \
../Core/Src/system_stm32f7xx.c 

C_DEPS += \
./Core/Src/main.d \
./Core/Src/stm32f7xx_hal_msp.d \
./Core/Src/stm32f7xx_it.d \
./Core/Src/system_stm32f7xx.d 

OBJS += \
./Core/Src/main.o \
./Core/Src/stm32f7xx_hal_msp.o \
./Core/Src/stm32f7xx_it.o \
./Core/Src/system_stm32f7xx.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx -c -I"C:/Users/sebastie.metral/Desktop/PTR/XF/Lab1/work/work/test-bench/test2/ide-cubeide-test2-idf/../src" -I"C:/Users/sebastie.metral/Desktop/PTR/XF/Lab1/work/work/test-bench/test2/ide-cubeide-test2-idf/Core/Inc" -I"C:/Users/sebastie.metral/Desktop/PTR/XF/Lab1/work/work/test-bench/test2/ide-cubeide-test2-idf" -I"C:/Users/sebastie.metral/Desktop/PTR/XF/Lab1/work/work/src/platform/f7-disco-gcc" -I"C:/Users/sebastie.metral/Desktop/PTR/XF/Lab1/work/work/src/platform/f7-disco-gcc/mcu" -I"C:/Users/sebastie.metral/Desktop/PTR/XF/Lab1/work/work/test-bench/test2/ide-cubeide-test2-idf/../../../src" -I"C:/Users/sebastie.metral/Desktop/PTR/XF/Lab1/work/work/src/simplified/xf/include" -I"C:/Users/sebastie.metral/Desktop/PTR/XF/Lab1/work/work/src/simplified/xf/port" -I"C:/Users/sebastie.metral/Desktop/PTR/XF/Lab1/work/work/src/simplified/xf/port/common" -I"C:/Users/sebastie.metral/Desktop/PTR/XF/Lab1/work/work/src/simplified/xf/port/idf-stm32" -I"C:/Users/sebastie.metral/Desktop/PTR/XF/Lab1/work/work/test-bench/test2/ide-cubeide-test2-idf/../../../src/mdw" -I"C:/Users/sebastie.metral/Desktop/PTR/XF/Lab1/work/work/test-bench/test2/ide-cubeide-test2-idf/../../../src/mdw/trace" -I"C:/Users/sebastie.metral/Desktop/PTR/XF/Lab1/work/work/test-bench/test2/ide-cubeide-test2-idf/../../common" -I"C:/Users/sebastie.metral/Desktop/PTR/XF/Lab1/work/work/test-bench/test2/ide-cubeide-test2-idf/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Users/sebastie.metral/Desktop/PTR/XF/Lab1/work/work/test-bench/test2/ide-cubeide-test2-idf/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Users/sebastie.metral/Desktop/PTR/XF/Lab1/work/work/test-bench/test2/ide-cubeide-test2-idf/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/sebastie.metral/Desktop/PTR/XF/Lab1/work/work/test-bench/test2/ide-cubeide-test2-idf/Drivers/CMSIS/Include" -Og -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

