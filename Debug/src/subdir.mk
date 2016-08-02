################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Block.c \
../src/Cell.c \
../src/GUI.c \
../src/Game.c \
../src/Grid.c \
../src/High_score.c \
../src/Hold.c \
../src/Input.c \
../src/Score.c \
../src/main.c 

OBJS += \
./src/Block.o \
./src/Cell.o \
./src/GUI.o \
./src/Game.o \
./src/Grid.o \
./src/High_score.o \
./src/Hold.o \
./src/Input.o \
./src/Score.o \
./src/main.o 

C_DEPS += \
./src/Block.d \
./src/Cell.d \
./src/GUI.d \
./src/Game.d \
./src/Grid.d \
./src/High_score.d \
./src/Hold.d \
./src/Input.d \
./src/Score.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -D_SDL_main_h -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


