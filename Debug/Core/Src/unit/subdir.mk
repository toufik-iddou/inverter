################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/unit/error_handler.c 

OBJS += \
./Core/Src/unit/error_handler.o 

C_DEPS += \
./Core/Src/unit/error_handler.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/unit/%.o Core/Src/unit/%.su Core/Src/unit/%.cyclo: ../Core/Src/unit/%.c Core/Src/unit/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-unit

clean-Core-2f-Src-2f-unit:
	-$(RM) ./Core/Src/unit/error_handler.cyclo ./Core/Src/unit/error_handler.d ./Core/Src/unit/error_handler.o ./Core/Src/unit/error_handler.su

.PHONY: clean-Core-2f-Src-2f-unit

