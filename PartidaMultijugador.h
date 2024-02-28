#ifndef PARTIDAMULTIJUGADOR_H_
#define PARTIDAMULTIJUGADOR_H_

#include <iostream>
#include <string>
#include "vector"
#include "partida.h"
#include "Jugador.h"

class PartidaMultijugador: public Partida {
private:
	bool trasmitidaVivo;
public:
	PartidaMultijugador(int, int, int, float, vector<string>, bool);

	bool getTrasmitidaVivo();

	void setTrasmitidaVivo(bool);

	virtual float darTotalHorasParticipantes();
	virtual ~PartidaMultijugador();
};

#endif /* PARTIDAMULTIJUGADOR_H_ */
