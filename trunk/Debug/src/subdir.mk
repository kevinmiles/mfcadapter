################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CList.cpp \
../src/CObject.cpp \
../src/CString.cpp \
../src/CTime.cpp \
../src/CTimeSpan.cpp 

OBJS += \
./src/CList.o \
./src/CObject.o \
./src/CString.o \
./src/CTime.o \
./src/CTimeSpan.o 

CPP_DEPS += \
./src/CList.d \
./src/CObject.d \
./src/CString.d \
./src/CTime.d \
./src/CTimeSpan.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


