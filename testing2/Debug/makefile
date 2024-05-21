################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include nuclei_sdk/SoC/evalsoc/Common/Source/Stubs/newlib/subdir.mk
-include nuclei_sdk/SoC/evalsoc/Common/Source/GCC/subdir.mk
-include nuclei_sdk/SoC/evalsoc/Common/Source/Drivers/subdir.mk
-include nuclei_sdk/SoC/evalsoc/Common/Source/subdir.mk
-include application/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(CCM_DEPS)),)
-include $(CCM_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CXXM_DEPS)),)
-include $(CXXM_DEPS)
endif
ifneq ($(strip $(C++M_DEPS)),)
-include $(C++M_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := testing2
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
testing2.hex \

SECONDARY_LIST += \
testing2.lst \

SECONDARY_SIZE += \
testing2.siz \


# All Target
all: main-build

# Main-build Target
main-build: testing2.elf secondary-outputs

# Tool invocations
testing2.elf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU RISC-V Cross C++ Linker'
	riscv64-unknown-elf-g++ -march=rv32emac -mabi=ilp32e -mtune=nuclei-200-series -mcmodel=medlow -msave-restore -fno-code-hoisting -fno-tree-vectorize -finline-functions -falign-functions=4 -falign-jumps=4 -falign-loops=4 -finline-limit=200 -fno-if-conversion -fno-if-conversion2 -fipa-pta -fselective-scheduling -fno-tree-loop-distribute-patterns -funroll-loops -funroll-all-loops -fno-delete-null-pointer-checks -fno-rename-registers -mbranch-cost=1 --param fsm-scale-path-stmts=5 --param max-average-unrolled-insns=200 --param max-grow-copy-bb-insns=20 --param max-jump-thread-duplication-stmts=25 --param hot-bb-frequency-fraction=4 --param unroll-jam-min-percent=0 -Ofast -ffunction-sections -fdata-sections -fno-common -g3 -T "D:\codes\opensource\nuclei_testing\testing2\nuclei_sdk\SoC\evalsoc\Board\nuclei_fpga_eval\Source\GCC\gcc_evalsoc_ilm.ld" -nostartfiles -nodefaultlibs -Xlinker --gc-sections -Wl,-Map,"testing2.map" -u _printf_float -Wl,--check-sections -Wl,--no-warn-rwx-segments -u _isatty -u _write -u _sbrk -u _read -u _close -u _fstat -u _lseek -u errno -o "testing2.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

testing2.hex: testing2.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: GNU RISC-V Cross Create Flash Image'
	riscv64-unknown-elf-objcopy -O ihex "testing2.elf"  "testing2.hex"
	@echo 'Finished building: $@'
	@echo ' '

testing2.lst: testing2.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: GNU RISC-V Cross Create Listing'
	riscv64-unknown-elf-objdump --source --all-headers --demangle --line-numbers --wide "testing2.elf" > "testing2.lst"
	@echo 'Finished building: $@'
	@echo ' '

testing2.siz: testing2.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: GNU RISC-V Cross Print Size'
	riscv64-unknown-elf-size --format=berkeley "testing2.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(CCM_DEPS)$(C_UPPER_DEPS)$(SECONDARY_LIST)$(SECONDARY_SIZE)$(CXXM_DEPS)$(C_DEPS)$(CC_DEPS)$(C++_DEPS)$(OBJS)$(CXX_DEPS)$(SECONDARY_FLASH)$(ASM_DEPS)$(S_UPPER_DEPS)$(C++M_DEPS)$(CPP_DEPS) testing2.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents main-build

-include ../makefile.targets
