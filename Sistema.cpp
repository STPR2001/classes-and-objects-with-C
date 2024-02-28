#include "Sistema.h"

Sistema::Sistema() {}

void Sistema::agregarJugador(string nickname, int edad, string contrasenia) {
	if (!this->jugadores.empty())
		for (unsigned long k = 0; k < jugadores.size(); k++)
			if (jugadores[k]->getNickName() == nickname) {
				cout << "Ya existe este nickname" << endl;
				return;
			}
	//if (flag)
	//return;
	Jugador *j = new Jugador(nickname, edad, contrasenia);
	jugadores.push_back(j);
}

vector<Jugador*> Sistema::obtenerJugadores(int &cantJugadores) {
	vector<Jugador*> auxJugadores;
	for (int k = 0; k < cantJugadores; k++)
		auxJugadores.push_back(jugadores[k]);
	return auxJugadores;
}

void Sistema::agregarVideojuego(string nombre, TipoJuego genero) {
	bool flag = false;

	if (!this->videoJuegos.empty()) {
		for (unsigned long k = 0; k < videoJuegos.size(); k++) {
			if (videoJuegos[k]->getNombre() == nombre) {
				cout << "Ya existe este video juego" << endl;
				flag = true;
			}

		}
	}
	if (flag)
		return;
	VideoJuego *v = new VideoJuego(nombre, genero);
	videoJuegos.push_back(v);
}

vector<VideoJuego*> Sistema::obtenerVideojuegos(int &cantVideoJuego) {

	vector<VideoJuego*> auxVideoJuego;
	for (int k = 0; k < cantVideoJuego; k++) {
		auxVideoJuego.push_back(videoJuegos[k]);
	}
	return auxVideoJuego;
}

void Sistema::iniciarPartida(string nickName, string videojuego, Partida *datos,
		Sistema *sis) {
	int tamanio;
	DtFecha f = datos->getFecha();
	VideoJuego *v;
	tamanio = datos->getNickNames().size();
	if (tamanio == 1) {
		bool continuacion = false;
		int continua;
		cout << "La partida es continuacion de otra? " << endl;
		cout << "1. Si" << endl;
		cout << "2. No" << endl;
		cin >> continua;
		if (continua == 1)
			continuacion = true;
		if (continua == 2)
			continuacion = false;

		for (unsigned long k = 0; k < this->getVideoJuegos().size(); k++) {
			if (this->getVideoJuegos()[k]->getNombre() == videojuego) {
				v = this->getVideoJuegos()[k];
				break;
			}
		}

		PartidaIndividual *i = new PartidaIndividual(f.getDia(), f.getMes(),
				f.getAnio(), datos->getDuracion(), datos->getNickNames(),
				continuacion);
		vector<Partida*> p;
		p = sis->getPartidas();
		p.push_back(i);
		sis->setPartidas(p);

		p = v->getPartidas();
		p.push_back(i);
		v->setPartidas(p);

		cout << "Partida individual creada con exito" << endl;

		return;
	}
	if (tamanio > 1) {
		bool vivo = false;
		int vivo_int;
		cout << "La partida será trasmitida en vivo? " << endl;
		cout << "1. Si" << endl;
		cout << "2. No" << endl;
		cin >> vivo_int;
		if (vivo_int == 1)
			vivo = true;
		else
			vivo = false;

		for (unsigned long k = 0; k < this->getVideoJuegos().size(); k++) {
			if (this->getVideoJuegos()[k]->getNombre() == videojuego) {
				v = this->getVideoJuegos()[k];
				break;
			}
		}

		PartidaMultijugador *m = new PartidaMultijugador(f.getDia(), f.getMes(),
				f.getAnio(), datos->getDuracion(), datos->getNickNames(), vivo);
		vector<Partida*> p;
		p = sis->getPartidas();
		p.push_back(m);
		sis->setPartidas(p);

		p = v->getPartidas();
		p.push_back(m);
		v->setPartidas(p);

		cout << "Partida multijuador creada con exito" << endl;
		return;
	}
}

vector<Partida*> Sistema::obtenerPartidas(string videojuego, int &cantPartidas,
		Sistema *sis) {
	vector<VideoJuego*> v = sis->getVideoJuegos();
	VideoJuego *j;
	for (unsigned long i = 0; i < v.size(); i++) {
		if (v[i]->getNombre() == videojuego) {
			j = v[i];
		}
	}
	vector<Partida*> partidas = j->getPartidas();
	vector<Partida*> auxPartidas;
	for (int k = 0; k < cantPartidas; k++) {
		auxPartidas.push_back(partidas[k]);
	}
	return auxPartidas;
}

vector<Jugador*> Sistema::getJugadores() {
	return this->jugadores;
}

vector<VideoJuego*> Sistema::getVideoJuegos() {
	return this->videoJuegos;
}

void Sistema::setPartidas(vector<Partida*> p) {
	this->partida = p;
}

vector<Partida*> Sistema::getPartidas() {
	return this->partida;
}

bool Sistema::CheckDate(int dia, int mes, int anio) {
	if (dia < 1 or dia > 31 or mes > 12 or mes < 1 or anio < 1900)
		return false;
	return true;
}

Sistema::~Sistema() {}
