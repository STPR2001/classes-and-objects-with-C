#ifndef PARTIDAINDIVIDUAL_H_
#define PARTIDAINDIVIDUAL_H_

#include <iostream>
#include <string>
#include "Partida.h"
#include "Jugador.h"
#include "VideoJuego.h"

using namespace std;

class PartidaIndividual: public Partida {
private:
	bool continuaPartidaAnterior;
public:
	PartidaIndividual(int, int, int, float, vector<string>, bool);

	bool getContinuaPartidaAnterior();

	void setContinuaPartidaAnterior(bool continuaPartidaAnterior);

	virtual float darTotalHorasParticipantes();
	virtual ~PartidaIndividual();
};

#endif /* PARTIDAINDIVIDUAL_H_ */
