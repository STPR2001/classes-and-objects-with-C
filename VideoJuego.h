#ifndef VIDEOJUEGO_H_
#define VIDEOJUEGO_H_

#include <string>
#include <iostream>
#include <vector>

#include "Partida.h"

enum TipoJuego {
	Guerra, Deporte, Arcade, Rol
};

using namespace std;

class VideoJuego {
private:
	string nombre;
	TipoJuego genero;
	vector<Partida*> partidas;
public:
	VideoJuego(string nombre, TipoJuego genero);

	string getNombre();
	TipoJuego getTipoJuego();
	vector<Partida*> getPartidas();

	void setNombre(string nombre);
	void setGenero(TipoJuego genero);

	void setPartidas(vector<Partida*>);

	virtual ~VideoJuego();
};

#endif /* VIDEOJUEGO_H_ */
