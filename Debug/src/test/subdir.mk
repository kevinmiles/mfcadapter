################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/test/CListTest.cpp \
../src/test/CStringTest.cpp \
../src/test/CTimeSpanTest.cpp \
../src/test/CTimeTest.cpp \
../src/test/Main.cpp 

OBJS += \
./src/test/CListTest.o \
./src/test/CStringTest.o \
./src/test/CTimeSpanTest.o \
./src/test/CTimeTest.o \
./src/test/Main.o 

CPP_DEPS += \
./src/test/CListTest.d \
./src/test/CStringTest.d \
./src/test/CTimeSpanTest.d \
./src/test/CTimeTest.d \
./src/test/Main.d 


# Each subdirectory must supply rules for building sources it contributes
src/test/%.o: ../src/test/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


