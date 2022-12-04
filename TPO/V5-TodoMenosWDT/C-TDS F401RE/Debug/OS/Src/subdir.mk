################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../OS/Src/monitor.c \
../OS/Src/scheduler.c \
../OS/Src/system.c 

OBJS += \
./OS/Src/monitor.o \
./OS/Src/scheduler.o \
./OS/Src/system.o 

C_DEPS += \
./OS/Src/monitor.d \
./OS/Src/scheduler.d \
./OS/Src/system.d 


# Each subdirectory must supply rules for building sources it contributes
OS/Src/%.o OS/Src/%.su: ../OS/Src/%.c OS/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/RepTD/TDII/TPO/V5-TodoMenosWDT/C-TDS F401RE/App/Inc" -I"D:/RepTD/TDII/TPO/V5-TodoMenosWDT/C-TDS F401RE/OS/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-OS-2f-Src

clean-OS-2f-Src:
	-$(RM) ./OS/Src/monitor.d ./OS/Src/monitor.o ./OS/Src/monitor.su ./OS/Src/scheduler.d ./OS/Src/scheduler.o ./OS/Src/scheduler.su ./OS/Src/system.d ./OS/Src/system.o ./OS/Src/system.su

.PHONY: clean-OS-2f-Src

