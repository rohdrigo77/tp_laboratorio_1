################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Controller.c \
../src/Employee.c \
../src/LinkedList.c \
../src/bibliogenerica.c \
../src/main.c 

OBJS += \
./src/Controller.o \
./src/Employee.o \
./src/LinkedList.o \
./src/bibliogenerica.o \
./src/main.o 

C_DEPS += \
./src/Controller.d \
./src/Employee.d \
./src/LinkedList.d \
./src/bibliogenerica.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


