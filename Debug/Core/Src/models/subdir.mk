################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/models/acquisition_model.c \
../Core/Src/models/pwm_model.c 

OBJS += \
./Core/Src/models/acquisition_model.o \
./Core/Src/models/pwm_model.o 

C_DEPS += \
./Core/Src/models/acquisition_model.d \
./Core/Src/models/pwm_model.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/models/%.o Core/Src/models/%.su Core/Src/models/%.cyclo: ../Core/Src/models/%.c Core/Src/models/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O2 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-models

clean-Core-2f-Src-2f-models:
	-$(RM) ./Core/Src/models/acquisition_model.cyclo ./Core/Src/models/acquisition_model.d ./Core/Src/models/acquisition_model.o ./Core/Src/models/acquisition_model.su ./Core/Src/models/pwm_model.cyclo ./Core/Src/models/pwm_model.d ./Core/Src/models/pwm_model.o ./Core/Src/models/pwm_model.su

.PHONY: clean-Core-2f-Src-2f-models

