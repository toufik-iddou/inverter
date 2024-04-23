################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/controllers/pid_controller.c 

OBJS += \
./Core/Src/controllers/pid_controller.o 

C_DEPS += \
./Core/Src/controllers/pid_controller.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/controllers/%.o Core/Src/controllers/%.su Core/Src/controllers/%.cyclo: ../Core/Src/controllers/%.c Core/Src/controllers/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-controllers

clean-Core-2f-Src-2f-controllers:
	-$(RM) ./Core/Src/controllers/pid_controller.cyclo ./Core/Src/controllers/pid_controller.d ./Core/Src/controllers/pid_controller.o ./Core/Src/controllers/pid_controller.su

.PHONY: clean-Core-2f-Src-2f-controllers

