################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Tasks/task-heartbeat.c \
../Core/Src/Tasks/task-watchdog.c 

OBJS += \
./Core/Src/Tasks/task-heartbeat.o \
./Core/Src/Tasks/task-watchdog.o 

C_DEPS += \
./Core/Src/Tasks/task-heartbeat.d \
./Core/Src/Tasks/task-watchdog.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Tasks/%.o Core/Src/Tasks/%.su: ../Core/Src/Tasks/%.c Core/Src/Tasks/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Core/Src/OS -I"C:/Digitales 2/Nucleo/C-TDS F401RE/Core/Src/OS" -I"C:/Digitales 2/Nucleo/C-TDS F401RE/Core/Src/Tasks" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Tasks

clean-Core-2f-Src-2f-Tasks:
	-$(RM) ./Core/Src/Tasks/task-heartbeat.d ./Core/Src/Tasks/task-heartbeat.o ./Core/Src/Tasks/task-heartbeat.su ./Core/Src/Tasks/task-watchdog.d ./Core/Src/Tasks/task-watchdog.o ./Core/Src/Tasks/task-watchdog.su

.PHONY: clean-Core-2f-Src-2f-Tasks

