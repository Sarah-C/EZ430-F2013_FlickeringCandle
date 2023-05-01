################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CMD_SRCS += \
../lnk_msp430f2013.cmd 

C_SRCS += \
../Candle.c 

OBJS += \
./Candle.obj 

DEPS += \
./Candle.d 

OBJS_QUOTED += \
"./Candle.obj" 


# Each subdirectory must supply rules for building sources it contributes
Candle.obj: ../Candle.c
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	@echo "c:\Program Files\Texas Instruments\CC Essentials 2.0\tools\compiler\MSP430\bin\cl430" --obj_directory"./" --include_path="c:\Program Files\Texas Instruments\CC Essentials 2.0\tools\compiler\MSP430\include" --symdebug:dwarf --plain_char=signed --silicon_version=msp --printf_support=minimal "$<"
	@"c:\Program Files\Texas Instruments\CC Essentials 2.0\tools\compiler\MSP430\bin\cl430" --obj_directory"./" --include_path="c:\Program Files\Texas Instruments\CC Essentials 2.0\tools\compiler\MSP430\include" --symdebug:dwarf --plain_char=signed --silicon_version=msp --printf_support=minimal "$<" && \
	"c:\Program Files\Texas Instruments\CC Essentials 2.0\tools\compiler\MSP430\bin\cl430" --preproc_dependency./"/Candle.d" --include_path="c:\Program Files\Texas Instruments\CC Essentials 2.0\tools\compiler\MSP430\include" --symdebug:dwarf --plain_char=signed --silicon_version=msp --printf_support=minimal "$<"

	@echo 'Finished building: $<'
	@echo ' '


