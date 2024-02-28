#include "PartidaMultijugador.h"

PartidaMultijugador::PartidaMultijugador(int dia, int mes, int anio,
		float duracion, vector<string> nickNames, bool trasmitidaVivo) :
		Partida(dia, mes, anio, duracion, nickNames) {
	this->trasmitidaVivo = trasmitidaVivo;

}

bool PartidaMultijugador::getTrasmitidaVivo() {
	return this->trasmitidaVivo;
}
void PartidaMultijugador::setTrasmitidaVivo(bool trasmitidaVivo) {
	this->trasmitidaVivo = trasmitidaVivo;
}

float PartidaMultijugador::darTotalHorasParticipantes() {
	return this->getDuracion() * this->getNickNames().size();
}

PartidaMultijugador::~PartidaMultijugador() {
}
