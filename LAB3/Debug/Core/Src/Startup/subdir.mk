################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Core/Src/Startup/startup_stm32f103c6ux.s 

OBJS += \
./Core/Src/Startup/startup_stm32f103c6ux.o 

S_DEPS += \
./Core/Src/Startup/startup_stm32f103c6ux.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Startup/%.o: ../Core/Src/Startup/%.s Core/Src/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m3 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

