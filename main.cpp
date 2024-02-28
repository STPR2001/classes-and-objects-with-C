#include <string>
#include <iostream>
#include <vector>
#include "Sistema.h"

#include <cctype>
#include <stdio.h>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <iostream>

bool checkVideoJuegos(string videoJuego, Sistema *sis);
bool checkNicks(vector<string> nick, Sistema *sis);

using namespace std;

int main(int argc, char *argv[]) {
	Sistema *sis = new Sistema;
	int op = 0;
	while (op != 7) {
		cout << "Ingresa una opcion:" << endl;
		cout << "1. Agregar jugador" << endl;
		cout << "2. Agregar videoJuego" << endl;
		cout << "3. Obtener jugadores" << endl;
		cout << "4. Obtener videoJuegos" << endl;
		cout << "5. Obtener Partidas" << endl;
		cout << "6. Iniciar partida" << endl;
		cout << "7. Salir" << endl;
		cin >> op;

		switch (op) {
		case 1: {
			// AGREGAR JUGADOR
			int edad;
			string nickname, contrasenia;
			cout << "Ingrese nickName" << endl;
			fflush(stdin);
			std::getline(std::cin, nickname);
			do {
				cout << "Ingrese edad" << endl;
				cin >> edad;

				if (edad < 1) {
					cout << "La edad debe ser un numero positivo" << endl;
				}
			} while (edad < 1);

			cout << "Ingrese contrasenia" << endl;
			fflush(stdin);
			std::getline(std::cin, contrasenia);

			sis->agregarJugador(nickname, edad, contrasenia);
			break;
		}
		case 2: {
			// AGREGAR VIDEOJUEGO
			string nombre;
			TipoJuego genero;
			int gen;
			cout << "Ingrese nombre" << endl;
			fflush(stdin);
			std::getline(std::cin, nombre);
			cout << "Genero: ";
			cout << endl << "1. Guerra" << endl << "2. Deportes" << endl
					<< "3. Rol" << endl << "4. Arcade" << endl;
			cin >> gen;
			switch (gen) {
			case 1: {
				genero = Guerra;
				break;
			}
			case 2: {
				genero = Deporte;
				break;
			}
			case 3: {
				genero = Rol;
				break;
			}
			case 4: {
				genero = Arcade;
				break;
			}
			}
			sis->agregarVideojuego(nombre, genero);
			break;
		}
		case 3: {
			// OBTENER JUGADORES
			int cantJugadores;
			int tamanio = sis->getJugadores().size();
			vector<Jugador*> auxJugador;

			do {
				cout << "Ingrese un numero: " << endl;
				cin >> cantJugadores;

				if (cantJugadores > tamanio)
					cout << "Solo hay " << tamanio
							<< " jugadores. Ingrese un número válido." << endl;

			} while (cantJugadores > tamanio);

			auxJugador = sis->obtenerJugadores(cantJugadores);
			for (int k = 0; k < cantJugadores; k++) {
				cout << "------------------------" << endl;
				cout << "Nickname: " << auxJugador[k]->getNickName();
				cout << endl;
				cout << "Edad: " << auxJugador[k]->getEdad();
				cout << endl;
				cout << "Contrasenia: " << auxJugador[k]->getContrasenia();
				cout << endl;
				cout << "------------------------" << endl;
			}
			break;
		}
		case 4: {
			// OBTENER VIDEOJUEGOS
			int cantVideoJuego, sumaHoras, tamanio =
					sis->getVideoJuegos().size();

			do {
				cout << "Ingrese un numero: " << endl;
				cin >> cantVideoJuego;

				if (cantVideoJuego > tamanio)
					cout
							<< "La cantidad de video juegos que ingreso es mayor al existente"
							<< endl;
			} while (cantVideoJuego > tamanio);

			vector<VideoJuego*> juegos = sis->getVideoJuegos();
			for (unsigned long i = 0; i < juegos.size() && i < cantVideoJuego;
					i++) {
				cout << "------------------------" << endl;
				cout << "Nombre: " << juegos[i]->getNombre();
				cout << endl;
				cout << "Genero: ";
				switch (juegos[i]->getTipoJuego()) {
				case 0: {
					cout << "Guerra" << endl;
					break;
				}
				case 1: {
					cout << "Deporte" << endl;
					break;
				}
				case 2: {
					cout << "Rol" << endl;
					break;
				}
				case 3: {
					cout << "Arcade" << endl;
					break;
				}
				}
				cout << "------------------------" << endl;
				sumaHoras = 0;
				for (unsigned long f = 0; f < juegos[i]->getPartidas().size();
						f++) {
					int cant_nicks =
							juegos[i]->getPartidas()[f]->getNickNames().size();
					if (cant_nicks == 1)
						sumaHoras +=
								juegos[i]->getPartidas()[f]->darTotalHorasParticipantes();
					if (cant_nicks > 1)
						sumaHoras +=
								juegos[i]->getPartidas()[f]->darTotalHorasParticipantes();
				}
				cout << "Total de horas: " << sumaHoras << endl;
				cout << "------------------------" << endl;
			}
			break;
		}
		case 5: {
			// OBTENER PARTIDAS
			string videoJuego;
			int cantPartidas;
			VideoJuego *j;
			cout << "Ingrese un video juego " << endl;
			fflush(stdin);
			std::getline(std::cin, videoJuego);

			for (unsigned long k = 0; k < sis->getVideoJuegos().size(); k++)
				if (sis->getVideoJuegos()[k]->getNombre() == videoJuego)
					j = sis->getVideoJuegos()[k];

			int tamanio = j->getPartidas().size();

			do {
				cout << "Ingrese un numero: " << endl;
				cin >> cantPartidas;

				if (cantPartidas > tamanio) {
					cout << "Solo hay " << tamanio
							<< " partidas. Ingrese un número válido." << endl;
				}

			} while (cantPartidas > tamanio);

			if (checkVideoJuegos(videoJuego, sis)) {
				vector<Partida*> partidas;
				partidas = sis->obtenerPartidas(videoJuego, cantPartidas, sis);
				for (unsigned long k = 0; k < partidas.size(); k++) {
					PartidaIndividual *p =
							dynamic_cast<PartidaIndividual*>(partidas[k]);
					if (p) {
						cout << "Partida individual" << endl;
						cout << "Anfitrion: " << p->getNickNames()[0] << endl;
						cout << "Duracion: ";
						cout << p->getDuracion() << endl;
						cout << "Continuacion de partida anterior: ";
						cout << p->getContinuaPartidaAnterior() << endl;
					} else {
						PartidaMultijugador *p =
								dynamic_cast<PartidaMultijugador*>(partidas[k]);
						cout << "Partida multijugador" << endl;
						cout << "Duracion: ";
						cout << p->getDuracion() << endl;
						cout << "Trasmitida en vivo: ";
						cout << p->getTrasmitidaVivo() << endl;
						cout << "Cantidad de jugadores: ";
						cout << p->getNickNames().size() << endl;
						cout << "Jugadores: ";
						vector<string> nicks;
						nicks = p->getNickNames();
						for (unsigned long i = 0; i < nicks.size(); i++) {
							cout << nicks[i] << endl;
						}
						cout << "asasa" << endl;
					}
				}

			} else
				cout << "El video juego no existe en el sistema" << endl;

			break;
		}
		case 6: {
			// AGREGAR PARTIDA
			int opcion, opcion2, cont = 0, dia, mes, anio;
			string nick, videoJuego;
			vector<string> NickNames;
			float duracion;
			bool flag = true;
			cout << "Partida a crear: " << endl;
			cout << "1. Multijuador" << endl;
			cout << "2. Individual" << endl;
			cin >> opcion;
			if (opcion == 1) {
				cout << "Ingrese nombre del VideoJuego " << endl;
				fflush(stdin);
				std::getline(std::cin, videoJuego);
				while (flag) {
					cout << "Ingrese nickName: " << endl;
					fflush(stdin);
					std::getline(std::cin, nick);
					NickNames.push_back(nick);
					cont++;
					cout << "1. Ingresar otro nickName" << endl;
					cout << "2. Siguiente" << endl;
					cin >> opcion2;
					if (opcion2 == 2)
						flag = false;
				}

				string nickName = NickNames[0];

				cout << "Ingrese dia" << endl;
				cin >> dia;
				cout << "Ingrese mes" << endl;
				cin >> mes;
				cout << "Ingrese anio" << endl;
				cin >> anio;
				if (!sis->CheckDate(dia, mes, anio)) {
					cout << "La fecha ingresada es incorrecta" << endl;
					break;
				}
				cout << "Ingrese la duracion de la partida (en horas) " << endl;
				cin >> duracion;
				if (checkVideoJuegos(videoJuego, sis)
						&& checkNicks(NickNames, sis)) {

					Partida *p = new Partida(dia, mes, anio, duracion,
							NickNames);
					sis->iniciarPartida(nickName, videoJuego, p, sis);

				} else {
					cout
							<< "El video juego o uno de los nickNames ingresados no existe en el sistema"
							<< endl;
				}

			}
			if (opcion == 2) {
				cout << "Ingrese nombre del VideoJuego " << endl;
				fflush(stdin);
				std::getline(std::cin, videoJuego);
				cout << "Ingrese nickName: " << endl;
				fflush(stdin);
				std::getline(std::cin, nick);
				NickNames.push_back(nick);

				string nickName = NickNames[0];

				cout << "Ingrese dia" << endl;
				cin >> dia;
				cout << "Ingrese mes" << endl;
				cin >> mes;
				cout << "Ingrese anio" << endl;
				cin >> anio;
				if (!sis->CheckDate(dia, mes, anio)) {
					cout << "La fecha ingresada es incorrecta" << endl;
					break;
				}

				cout << "Ingrese la duracion de la partida (en horas)" << endl;
				cin >> duracion;
				if (checkVideoJuegos(videoJuego, sis)
						&& checkNicks(NickNames, sis)) {

					Partida *p = new Partida(dia, mes, anio, duracion,
							NickNames);
					sis->iniciarPartida(nickName, videoJuego, p, sis);

				} else {
					cout
							<< "El video juego o el nick ingresado no existe en el sistema"
							<< endl;
				}
			}

			break;
		}
		case 7: {
			break;
		}
		}
	}
	return 0;
}

bool checkVideoJuegos(string videoJuego, Sistema *sis) {
	int cont2 = 0;
	for (unsigned long k = 0; k < sis->getVideoJuegos().size(); k++)
		if (sis->getVideoJuegos()[k]->getNombre() == videoJuego)
			cont2++;
	if (cont2 == 0) {
		return false;
	}
	return true;
}

bool checkNicks(vector<string> nick, Sistema *sis) {
	int cont2 = 0;
	int tamanio = nick.size();
	for (unsigned long i = 0; i < nick.size(); i++) {
		for (unsigned long k = 0; k < sis->getJugadores().size(); k++)
			if (sis->getJugadores()[k]->getNickName() == nick[i])
				cont2++;
	}
	if (cont2 < tamanio) {
		return false;
	}
	return true;
}
