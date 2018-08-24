################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include controllers/subdir.mk
-include communication/subdir.mk
-include MCAL/subdir.mk
-include HAL/subdir.mk
-include Application/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
FATAKAT1.lss \

FLASH_IMAGE += \
FATAKAT1.hex \

EEPROM_IMAGE += \
FATAKAT1.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: FATAKAT1.elf secondary-outputs

# Tool invocations
FATAKAT1.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,FATAKAT1.map -mmcu=atmega128 -o "FATAKAT1.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

FATAKAT1.lss: FATAKAT1.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S FATAKAT1.elf  >"FATAKAT1.lss"
	@echo 'Finished building: $@'
	@echo ' '

FATAKAT1.hex: FATAKAT1.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex FATAKAT1.elf  "FATAKAT1.hex"
	@echo 'Finished building: $@'
	@echo ' '

FATAKAT1.eep: FATAKAT1.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex FATAKAT1.elf  "FATAKAT1.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: FATAKAT1.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega128 FATAKAT1.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) FATAKAT1.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
