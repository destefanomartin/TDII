################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/OS/monitor.c \
../Core/Src/OS/scheduler.c \
../Core/Src/OS/system.c 

OBJS += \
./Core/Src/OS/monitor.o \
./Core/Src/OS/scheduler.o \
./Core/Src/OS/system.o 

C_DEPS += \
./Core/Src/OS/monitor.d \
./Core/Src/OS/scheduler.d \
./Core/Src/OS/system.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/OS/%.o Core/Src/OS/%.su: ../Core/Src/OS/%.c Core/Src/OS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Core/Src/OS -I"C:/Digitales 2/Nucleo/C-TDS F401RE/App/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-OS

clean-Core-2f-Src-2f-OS:
	-$(RM) ./Core/Src/OS/monitor.d ./Core/Src/OS/monitor.o ./Core/Src/OS/monitor.su ./Core/Src/OS/scheduler.d ./Core/Src/OS/scheduler.o ./Core/Src/OS/scheduler.su ./Core/Src/OS/system.d ./Core/Src/OS/system.o ./Core/Src/OS/system.su

.PHONY: clean-Core-2f-Src-2f-OS

