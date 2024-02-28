#ifndef PARTIDA_H_
#define PARTIDA_H_
#include <iostream>
#include <string>
#include "DtFecha.h"
#include "Jugador.h"
#include "vector"

using namespace std;

class Partida {
private:
	DtFecha fecha;
	float duracion;
	vector<string> nickNames;
public:
	Partida(int, int, int, float, vector<string>);

	DtFecha getFecha();
	float getDuracion();
	vector<string> getNickNames();

	void setFecha(DtFecha fecha);
	void setDuracion(float duracion);

	virtual float darTotalHorasParticipantes();
	virtual ~Partida();
};

#endif /* PARTIDA_H_ */
