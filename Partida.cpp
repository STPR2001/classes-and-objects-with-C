#include "Partida.h"

Partida::Partida(int dia, int mes, int anio, float duracion,
		vector<string> nickNames) :
		fecha(dia, mes, anio) {
	this->duracion = duracion;
	this->nickNames = nickNames;
}

DtFecha Partida::getFecha() {
	return this->fecha;
}
float Partida::getDuracion() {
	return this->duracion;
}
vector<string> Partida::getNickNames() {
	return this->nickNames;
}

void Partida::setFecha(DtFecha fecha) {
	this->fecha = fecha;
}
void Partida::setDuracion(float duracion) {
	this->duracion = duracion;
}

float Partida::darTotalHorasParticipantes() {
	return this->duracion;
}

Partida::~Partida() {
}
