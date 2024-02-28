#include <string>
#include <iostream>
#include <vector>

#include "Date.h"
#include "Partida.h"
#include "Jugador.h"
#include "PartidaIndividual.h"
#include "VideoJuego.h"
#include "PartidaMultijugador.h"

using namespace std;

#ifndef SISTEMA_H_
#define SISTEMA_H_

class Sistema {
private:
	vector<Jugador*> jugadores;
	vector<VideoJuego*> videoJuegos;
	vector<Partida*> partida;
public:
	Sistema();

	void agregarJugador(string nickName, int edad, string contrasenia);
	void agregarVideojuego(string nombre, TipoJuego genero);
	void iniciarPartida(string nickName, string videojuego, Partida *datos,
			Sistema *sis);

	vector<Jugador*> obtenerJugadores(int &cantJugadores);
	vector<VideoJuego*> obtenerVideojuegos(int &cantVideojuegos);
	vector<Partida*> obtenerPartidas(string videojuego, int &cantPartidas,
			Sistema *sis);

	void Menu();
	bool CheckDate(int dia, int mes, int anio);

	vector<Jugador*> getJugadores();
	vector<VideoJuego*> getVideoJuegos();

	void setPartidas(vector<Partida*>);
	vector<Partida*> getPartidas();

	virtual ~Sistema();
};
#endif /* SISTEMA_H_ */
