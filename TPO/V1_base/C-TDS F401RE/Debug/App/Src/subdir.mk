################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App/Src/task-heartbeat.c \
../App/Src/task-watchdog.c 

OBJS += \
./App/Src/task-heartbeat.o \
./App/Src/task-watchdog.o 

C_DEPS += \
./App/Src/task-heartbeat.d \
./App/Src/task-watchdog.d 


# Each subdirectory must supply rules for building sources it contributes
App/Src/%.o App/Src/%.su: ../App/Src/%.c App/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/RepTD/TDII/TPO/V1_base/C-TDS F401RE/App/Inc" -I"D:/RepTD/TDII/TPO/V1_base/C-TDS F401RE/OS/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-App-2f-Src

clean-App-2f-Src:
	-$(RM) ./App/Src/task-heartbeat.d ./App/Src/task-heartbeat.o ./App/Src/task-heartbeat.su ./App/Src/task-watchdog.d ./App/Src/task-watchdog.o ./App/Src/task-watchdog.su

.PHONY: clean-App-2f-Src

