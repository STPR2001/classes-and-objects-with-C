#include "PartidaIndividual.h"

#include "Jugador.h"
#include "VideoJuego.h"

PartidaIndividual::PartidaIndividual(int dia, int mes, int anio, float duracion,
		vector<string> nickNames, bool continuaPartidaAnterior) :
		Partida(dia, mes, anio, duracion, nickNames) {
	this->continuaPartidaAnterior = continuaPartidaAnterior;
}

bool PartidaIndividual::getContinuaPartidaAnterior() {
	return this->continuaPartidaAnterior;
}

void PartidaIndividual::setContinuaPartidaAnterior(
		bool continuaPartidaAnterior) {
	this->continuaPartidaAnterior = continuaPartidaAnterior;
}

float PartidaIndividual::darTotalHorasParticipantes() {
	return this->getDuracion();
}

PartidaIndividual::~PartidaIndividual() {
}
