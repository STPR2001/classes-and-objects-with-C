#include "Date.h"
#include <string>
#include <iostream>

Date::Date(int dia, int mes, int anio) {
	this->dia = dia;
	this->mes = mes;
	this->anio = anio;
}

int Date::getDia() {
	return this->dia;
}

int Date::getMes() {
	return this->mes;
}

int Date::getAnio() {
	return this->anio;
}

Date::~Date() {
	// TODO Auto-generated destructor stub
}
