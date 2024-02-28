#ifndef DTFECHA_H_
#define DTFECHA_H_

class DtFecha {
private:
	int dia;
	int mes;
	int anio;
public:
	DtFecha(int dia, int mes, int anio);
	int getDia();
	int getMes();
	int getAnio();

	void setDia(int dia);
	void setMes(int mes);
	void setAnio(int anio);
	~DtFecha();
};

#endif /* DTFECHA_H_ */
