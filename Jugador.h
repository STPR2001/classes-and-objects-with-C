#ifndef JUGADOR_H_
#define JUGADOR_H_

#include <string>
#include <iostream>

using namespace std;

class Jugador {
private:
	string nickName;
	int edad;
	string contrasenia;
public:
	Jugador(string nickName, int edad, string contrasenia);

	int getEdad();
	string getNickName();
	string getContrasenia();

	void setNickName(string nickName);
	void setEdad(int edad);
	void setContrasenia(string contrasenia);

	virtual ~Jugador();
};

#endif /* JUGADOR_H_ */
