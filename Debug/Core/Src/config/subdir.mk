################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/config/adc_config.c \
../Core/Src/config/clock_config.c \
../Core/Src/config/config.c \
../Core/Src/config/dac_config.c \
../Core/Src/config/dma_config.c \
../Core/Src/config/gpio_config.c \
../Core/Src/config/timer_config.c 

OBJS += \
./Core/Src/config/adc_config.o \
./Core/Src/config/clock_config.o \
./Core/Src/config/config.o \
./Core/Src/config/dac_config.o \
./Core/Src/config/dma_config.o \
./Core/Src/config/gpio_config.o \
./Core/Src/config/timer_config.o 

C_DEPS += \
./Core/Src/config/adc_config.d \
./Core/Src/config/clock_config.d \
./Core/Src/config/config.d \
./Core/Src/config/dac_config.d \
./Core/Src/config/dma_config.d \
./Core/Src/config/gpio_config.d \
./Core/Src/config/timer_config.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/config/%.o Core/Src/config/%.su Core/Src/config/%.cyclo: ../Core/Src/config/%.c Core/Src/config/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O2 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-config

clean-Core-2f-Src-2f-config:
	-$(RM) ./Core/Src/config/adc_config.cyclo ./Core/Src/config/adc_config.d ./Core/Src/config/adc_config.o ./Core/Src/config/adc_config.su ./Core/Src/config/clock_config.cyclo ./Core/Src/config/clock_config.d ./Core/Src/config/clock_config.o ./Core/Src/config/clock_config.su ./Core/Src/config/config.cyclo ./Core/Src/config/config.d ./Core/Src/config/config.o ./Core/Src/config/config.su ./Core/Src/config/dac_config.cyclo ./Core/Src/config/dac_config.d ./Core/Src/config/dac_config.o ./Core/Src/config/dac_config.su ./Core/Src/config/dma_config.cyclo ./Core/Src/config/dma_config.d ./Core/Src/config/dma_config.o ./Core/Src/config/dma_config.su ./Core/Src/config/gpio_config.cyclo ./Core/Src/config/gpio_config.d ./Core/Src/config/gpio_config.o ./Core/Src/config/gpio_config.su ./Core/Src/config/timer_config.cyclo ./Core/Src/config/timer_config.d ./Core/Src/config/timer_config.o ./Core/Src/config/timer_config.su

.PHONY: clean-Core-2f-Src-2f-config

