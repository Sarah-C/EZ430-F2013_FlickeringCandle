################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := c:\Program Files\Texas Instruments\CC Essentials 2.0\\utils\Cygwin\rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk
ifneq ($(strip $(DEPS)),)
-include $(DEPS)
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: Candle.out

# Tool invocations
Candle.out: $(OBJS) $(CMD_SRCS)
	@echo 'Building target: $@'
	@echo 'Invoking: MSP430 Linker'
	@echo "c:\Program Files\Texas Instruments\CC Essentials 2.0\tools\compiler\MSP430\bin\cl430"  -z --rom_model --heap_size=0 --search_path="c:\Program Files\Texas Instruments\CC Essentials 2.0\tools\compiler\MSP430\lib" --search_path="c:\Program Files\Texas Instruments\CC Essentials 2.0\tools\compiler\MSP430\include" --library="../lnk_msp430f2013.cmd" --library="rts430.lib" --reread_libs --stack_size=50 --warn_sections -o "Candle.out" $(OBJS_QUOTED)
	@"c:\Program Files\Texas Instruments\CC Essentials 2.0\tools\compiler\MSP430\bin\cl430"  -z --rom_model --heap_size=0 --search_path="c:\Program Files\Texas Instruments\CC Essentials 2.0\tools\compiler\MSP430\lib" --search_path="c:\Program Files\Texas Instruments\CC Essentials 2.0\tools\compiler\MSP430\include" --library="../lnk_msp430f2013.cmd" --library="rts430.lib" --reread_libs --stack_size=50 --warn_sections -o "Candle.out" $(OBJS_QUOTED)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(MSP430_EXECUTABLE_OUTPUTS)$(DEPS) Candle.out
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
