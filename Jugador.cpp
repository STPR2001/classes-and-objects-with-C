#include "Jugador.h"
#include <string>
#include <iostream>

Jugador::Jugador(string nickName, int edad, string contrasenia) {
	this->nickName = nickName;
	this->edad = edad;
	this->contrasenia = contrasenia;
}

string Jugador::getNickName() {
	return this->nickName;
}

int Jugador::getEdad() {
	return this->edad;
}

string Jugador::getContrasenia() {
	return this->contrasenia;
}

void Jugador::setNickName(string nickName) {
	this->nickName = nickName;
}

void Jugador::setEdad(int edad) {
	this->edad = edad;
}

void Jugador::setContrasenia(string contrasenia) {
	this->contrasenia = contrasenia;
}

Jugador::~Jugador() {}
