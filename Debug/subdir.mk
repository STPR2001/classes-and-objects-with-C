################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Date.cpp \
../DtFecha.cpp \
../Jugador.cpp \
../Sistema.cpp \
../VideoJuego.cpp \
../main.cpp \
../partida.cpp \
../partidaIndividual.cpp \
../partidaMultijugador.cpp 

CPP_DEPS += \
./Date.d \
./DtFecha.d \
./Jugador.d \
./Sistema.d \
./VideoJuego.d \
./main.d \
./partida.d \
./partidaIndividual.d \
./partidaMultijugador.d 

OBJS += \
./Date.o \
./DtFecha.o \
./Jugador.o \
./Sistema.o \
./VideoJuego.o \
./main.o \
./partida.o \
./partidaIndividual.o \
./partidaMultijugador.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean--2e-

clean--2e-:
	-$(RM) ./Date.d ./Date.o ./DtFecha.d ./DtFecha.o ./Jugador.d ./Jugador.o ./Sistema.d ./Sistema.o ./VideoJuego.d ./VideoJuego.o ./main.d ./main.o ./partida.d ./partida.o ./partidaIndividual.d ./partidaIndividual.o ./partidaMultijugador.d ./partidaMultijugador.o

.PHONY: clean--2e-

