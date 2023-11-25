################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Middlewares/MotorControl/subdir.mk
-include Drivers/STM32F0xx_HAL_Driver/subdir.mk
-include Drivers/CMSIS/subdir.mk
-include Application/User/subdir.mk
-include Application/Startup/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
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

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := Dribbler Motor - HALL sensing with high-speed logging
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Dribbler\ Motor\ -\ HALL\ sensing\ with\ high-speed\ logging.elf \

MAP_FILES += \
Dribbler\ Motor\ -\ HALL\ sensing\ with\ high-speed\ logging.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Dribbler\ Motor\ -\ HALL\ sensing\ with\ high-speed\ logging.list \


# All Target
all: main-build

# Main-build Target
main-build: Dribbler\ Motor\ -\ HALL\ sensing\ with\ high-speed\ logging.elf secondary-outputs

# Tool invocations
Dribbler\ Motor\ -\ HALL\ sensing\ with\ high-speed\ logging.elf Dribbler\ Motor\ -\ HALL\ sensing\ with\ high-speed\ logging.map: $(OBJS) $(USER_OBJS) C:\Users\tarak\Downloads\Dribbler\ Motor\ -\ HALL\ sensing\ with\ high-speed\ logging\STM32CubeIDE\STM32F031C6TX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "Dribbler Motor - HALL sensing with high-speed logging.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m0 -T"C:\Users\tarak\Downloads\Dribbler Motor - HALL sensing with high-speed logging\STM32CubeIDE\STM32F031C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Dribbler Motor - HALL sensing with high-speed logging.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Dribbler\ Motor\ -\ HALL\ sensing\ with\ high-speed\ logging.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Dribbler Motor - HALL sensing with high-speed logging.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) Dribbler\ Motor\ -\ HALL\ sensing\ with\ high-speed\ logging.elf Dribbler\ Motor\ -\ HALL\ sensing\ with\ high-speed\ logging.list Dribbler\ Motor\ -\ HALL\ sensing\ with\ high-speed\ logging.map Dribbler\\ Motor\\ -\\ HALL\\ sensing\\ with\\ high-speed\\ logging.elf default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
