################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/Application.c" \
"../Sources/Events.c" \
"../Sources/ProcessorExpert.c" \
"../Sources/Ultrasonico.c" \
"../Sources/mqx_tasks.c" \
"../Sources/sa_mtb.c" \

C_SRCS += \
../Sources/Application.c \
../Sources/Events.c \
../Sources/ProcessorExpert.c \
../Sources/Ultrasonico.c \
../Sources/mqx_tasks.c \
../Sources/sa_mtb.c \

OBJS += \
./Sources/Application_c.obj \
./Sources/Events_c.obj \
./Sources/ProcessorExpert_c.obj \
./Sources/Ultrasonico_c.obj \
./Sources/mqx_tasks_c.obj \
./Sources/sa_mtb_c.obj \

C_DEPS += \
./Sources/Application.d \
./Sources/Events.d \
./Sources/ProcessorExpert.d \
./Sources/Ultrasonico.d \
./Sources/mqx_tasks.d \
./Sources/sa_mtb.d \

OBJS_QUOTED += \
"./Sources/Application_c.obj" \
"./Sources/Events_c.obj" \
"./Sources/ProcessorExpert_c.obj" \
"./Sources/Ultrasonico_c.obj" \
"./Sources/mqx_tasks_c.obj" \
"./Sources/sa_mtb_c.obj" \

C_DEPS_QUOTED += \
"./Sources/Application.d" \
"./Sources/Events.d" \
"./Sources/ProcessorExpert.d" \
"./Sources/Ultrasonico.d" \
"./Sources/mqx_tasks.d" \
"./Sources/sa_mtb.d" \

OBJS_OS_FORMAT += \
./Sources/Application_c.obj \
./Sources/Events_c.obj \
./Sources/ProcessorExpert_c.obj \
./Sources/Ultrasonico_c.obj \
./Sources/mqx_tasks_c.obj \
./Sources/sa_mtb_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Sources/Application_c.obj: ../Sources/Application.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Application.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Sources/Application_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Sources/Events_c.obj: ../Sources/Events.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Events.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Sources/Events_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Sources/ProcessorExpert_c.obj: ../Sources/ProcessorExpert.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/ProcessorExpert.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Sources/ProcessorExpert_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Sources/Ultrasonico_c.obj: ../Sources/Ultrasonico.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Ultrasonico.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Sources/Ultrasonico_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Sources/mqx_tasks_c.obj: ../Sources/mqx_tasks.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/mqx_tasks.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Sources/mqx_tasks_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Sources/sa_mtb_c.obj: ../Sources/sa_mtb.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/sa_mtb.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Sources/sa_mtb_c.obj"
	@echo 'Finished building: $<'
	@echo ' '


