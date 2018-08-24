################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../controllers/RouteController.c \
../controllers/lineFollowerController.c \
../controllers/tasksController.c 

OBJS += \
./controllers/RouteController.o \
./controllers/lineFollowerController.o \
./controllers/tasksController.o 

C_DEPS += \
./controllers/RouteController.d \
./controllers/lineFollowerController.d \
./controllers/tasksController.d 


# Each subdirectory must supply rules for building sources it contributes
controllers/%.o: ../controllers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega128 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


