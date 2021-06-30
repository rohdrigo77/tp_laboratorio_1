################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Controller.c \
../src/LinkedList.c \
../src/bibliogenerica.c \
../src/ePiloto.c \
../src/eVuelo.c \
../src/efecha.c \
../src/informes.c \
../src/main.c \
../src/parser.c 

OBJS += \
./src/Controller.o \
./src/LinkedList.o \
./src/bibliogenerica.o \
./src/ePiloto.o \
./src/eVuelo.o \
./src/efecha.o \
./src/informes.o \
./src/main.o \
./src/parser.o 

C_DEPS += \
./src/Controller.d \
./src/LinkedList.d \
./src/bibliogenerica.d \
./src/ePiloto.d \
./src/eVuelo.d \
./src/efecha.d \
./src/informes.d \
./src/main.d \
./src/parser.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


