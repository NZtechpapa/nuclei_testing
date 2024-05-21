################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../nuclei_sdk/SoC/evalsoc/Common/Source/Drivers/evalsoc_uart.c 

C_DEPS += \
./nuclei_sdk/SoC/evalsoc/Common/Source/Drivers/evalsoc_uart.d 

OBJS += \
./nuclei_sdk/SoC/evalsoc/Common/Source/Drivers/evalsoc_uart.o 


# Each subdirectory must supply rules for building sources it contributes
nuclei_sdk/SoC/evalsoc/Common/Source/Drivers/%.o: ../nuclei_sdk/SoC/evalsoc/Common/Source/Drivers/%.c nuclei_sdk/SoC/evalsoc/Common/Source/Drivers/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv64-unknown-elf-gcc -march=rv32emac -mabi=ilp32e -mtune=nuclei-200-series -mcmodel=medlow -msave-restore -fno-code-hoisting -fno-tree-vectorize -finline-functions -falign-functions=4 -falign-jumps=4 -falign-loops=4 -finline-limit=200 -fno-if-conversion -fno-if-conversion2 -fipa-pta -fselective-scheduling -fno-tree-loop-distribute-patterns -funroll-loops -funroll-all-loops -fno-delete-null-pointer-checks -fno-rename-registers -mbranch-cost=1 --param fsm-scale-path-stmts=5 --param max-average-unrolled-insns=200 --param max-grow-copy-bb-insns=20 --param max-jump-thread-duplication-stmts=25 --param hot-bb-frequency-fraction=4 --param unroll-jam-min-percent=0 -Ofast -ffunction-sections -fdata-sections -fno-common -g3 -D__IDE_RV_CORE=n203e -DBOOT_HARTID=0 -DRUNMODE_IC_EN=0 -DRUNMODE_DC_EN=0 -DRUNMODE_CCM_EN=0 -DDOWNLOAD_MODE=DOWNLOAD_MODE_ILM -DDOWNLOAD_MODE_STRING=\"ILM\" -DFLAGS_STR=\""See compiler options passed in IDE"\" -DITERATIONS=800 -DPERFORMANCE_RUN=1 -I"D:\codes\opensource\nuclei_testing\testing2\nuclei_sdk\NMSIS\Core\Include" -I"D:\codes\opensource\nuclei_testing\testing2\nuclei_sdk\SoC\evalsoc\Common\Include" -I"D:\codes\opensource\nuclei_testing\testing2\nuclei_sdk\SoC\evalsoc\Board\nuclei_fpga_eval\Include" -I"D:\codes\opensource\nuclei_testing\testing2\application" -isystem/include/newlib-nano -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


