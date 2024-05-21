################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
../nuclei_sdk/SoC/evalsoc/Common/Source/GCC/intexc_evalsoc.S \
../nuclei_sdk/SoC/evalsoc/Common/Source/GCC/intexc_evalsoc_s.S \
../nuclei_sdk/SoC/evalsoc/Common/Source/GCC/startup_evalsoc.S 

OBJS += \
./nuclei_sdk/SoC/evalsoc/Common/Source/GCC/intexc_evalsoc.o \
./nuclei_sdk/SoC/evalsoc/Common/Source/GCC/intexc_evalsoc_s.o \
./nuclei_sdk/SoC/evalsoc/Common/Source/GCC/startup_evalsoc.o 

S_UPPER_DEPS += \
./nuclei_sdk/SoC/evalsoc/Common/Source/GCC/intexc_evalsoc.d \
./nuclei_sdk/SoC/evalsoc/Common/Source/GCC/intexc_evalsoc_s.d \
./nuclei_sdk/SoC/evalsoc/Common/Source/GCC/startup_evalsoc.d 


# Each subdirectory must supply rules for building sources it contributes
nuclei_sdk/SoC/evalsoc/Common/Source/GCC/%.o: ../nuclei_sdk/SoC/evalsoc/Common/Source/GCC/%.S nuclei_sdk/SoC/evalsoc/Common/Source/GCC/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross Assembler'
	riscv64-unknown-elf-gcc -march=rv32emac -mabi=ilp32e -mtune=nuclei-200-series -mcmodel=medlow -msave-restore -fno-code-hoisting -fno-tree-vectorize -finline-functions -falign-functions=4 -falign-jumps=4 -falign-loops=4 -finline-limit=200 -fno-if-conversion -fno-if-conversion2 -fipa-pta -fselective-scheduling -fno-tree-loop-distribute-patterns -funroll-loops -funroll-all-loops -fno-delete-null-pointer-checks -fno-rename-registers -mbranch-cost=1 --param fsm-scale-path-stmts=5 --param max-average-unrolled-insns=200 --param max-grow-copy-bb-insns=20 --param max-jump-thread-duplication-stmts=25 --param hot-bb-frequency-fraction=4 --param unroll-jam-min-percent=0 -Ofast -ffunction-sections -fdata-sections -fno-common -g3 -x assembler-with-cpp -D__IDE_RV_CORE=n203e -DBOOT_HARTID=0 -DRUNMODE_IC_EN=0 -DRUNMODE_DC_EN=0 -DRUNMODE_CCM_EN=0 -DDOWNLOAD_MODE=DOWNLOAD_MODE_ILM -DDOWNLOAD_MODE_STRING=\"ILM\" -I"D:\codes\jianash\gn001\testing2\nuclei_sdk\NMSIS\Core\Include" -I"D:\codes\jianash\gn001\testing2\nuclei_sdk\SoC\evalsoc\Common\Include" -I"D:\codes\jianash\gn001\testing2\nuclei_sdk\SoC\evalsoc\Board\nuclei_fpga_eval\Include" -I"D:\codes\jianash\gn001\testing2\application" -isystem/include/newlib-nano -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


