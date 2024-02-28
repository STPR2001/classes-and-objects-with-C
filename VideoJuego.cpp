#include "VideoJuego.h"

#include <string>
#include <iostream>

VideoJuego::VideoJuego(string nombre, TipoJuego genero) {
	this->nombre = nombre;
	this->genero = genero;
}

string VideoJuego::getNombre() {
	return this->nombre;
}

TipoJuego VideoJuego::getTipoJuego() {
	return this->genero;
}

void VideoJuego::setNombre(string nombre) {
	this->nombre = nombre;
}

void VideoJuego::setGenero(TipoJuego genero) {
	this->genero = genero;
}

void VideoJuego::setPartidas(vector<Partida*> p) {
	this->partidas = p;
}

vector<Partida*> VideoJuego::getPartidas() {
	return this->partidas;
}

VideoJuego::~VideoJuego() {}
