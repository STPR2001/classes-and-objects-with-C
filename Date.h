#ifndef DATE_H_
#define DATE_H_

#include <string>
#include <iostream>

using namespace std;

class Date {
private:
	int dia;
	int mes;
	int anio;
public:
	Date(int dia, int mes, int anio);

	int getDia();
	int getMes();
	int getAnio();

	virtual ~Date();
};

#endif /* DATE_H_ */
