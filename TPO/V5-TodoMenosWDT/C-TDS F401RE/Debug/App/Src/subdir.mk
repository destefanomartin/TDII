################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App/Src/i2c-display.c \
../App/Src/pin_functions_stm32f401.c \
../App/Src/task-audio-processing.c \
../App/Src/task-display.c \
../App/Src/task-heartbeat.c \
../App/Src/task-mediciones.c \
../App/Src/task-pulsador-falla.c \
../App/Src/task-pulsador-medir.c \
../App/Src/task-watchdog.c 

OBJS += \
./App/Src/i2c-display.o \
./App/Src/pin_functions_stm32f401.o \
./App/Src/task-audio-processing.o \
./App/Src/task-display.o \
./App/Src/task-heartbeat.o \
./App/Src/task-mediciones.o \
./App/Src/task-pulsador-falla.o \
./App/Src/task-pulsador-medir.o \
./App/Src/task-watchdog.o 

C_DEPS += \
./App/Src/i2c-display.d \
./App/Src/pin_functions_stm32f401.d \
./App/Src/task-audio-processing.d \
./App/Src/task-display.d \
./App/Src/task-heartbeat.d \
./App/Src/task-mediciones.d \
./App/Src/task-pulsador-falla.d \
./App/Src/task-pulsador-medir.d \
./App/Src/task-watchdog.d 


# Each subdirectory must supply rules for building sources it contributes
App/Src/%.o App/Src/%.su: ../App/Src/%.c App/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/RepTD/TDII/TPO/V5-TodoMenosWDT/C-TDS F401RE/App/Inc" -I"D:/RepTD/TDII/TPO/V5-TodoMenosWDT/C-TDS F401RE/OS/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-App-2f-Src

clean-App-2f-Src:
	-$(RM) ./App/Src/i2c-display.d ./App/Src/i2c-display.o ./App/Src/i2c-display.su ./App/Src/pin_functions_stm32f401.d ./App/Src/pin_functions_stm32f401.o ./App/Src/pin_functions_stm32f401.su ./App/Src/task-audio-processing.d ./App/Src/task-audio-processing.o ./App/Src/task-audio-processing.su ./App/Src/task-display.d ./App/Src/task-display.o ./App/Src/task-display.su ./App/Src/task-heartbeat.d ./App/Src/task-heartbeat.o ./App/Src/task-heartbeat.su ./App/Src/task-mediciones.d ./App/Src/task-mediciones.o ./App/Src/task-mediciones.su ./App/Src/task-pulsador-falla.d ./App/Src/task-pulsador-falla.o ./App/Src/task-pulsador-falla.su ./App/Src/task-pulsador-medir.d ./App/Src/task-pulsador-medir.o ./App/Src/task-pulsador-medir.su ./App/Src/task-watchdog.d ./App/Src/task-watchdog.o ./App/Src/task-watchdog.su

.PHONY: clean-App-2f-Src

