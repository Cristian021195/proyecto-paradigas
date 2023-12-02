#ifndef HORA_H_
#define HORA_H_
#include <iomanip>
#include <iostream>
#include <ctime>
using namespace std;

class Hora {
private:
	unsigned short hora;
	unsigned short minuto;
	unsigned short segundo;
public:
	static const unsigned short HORA_MAX = 23;
	static const unsigned short MINUTO_MAX = 59;
	static const unsigned short SEGUNDO_MAX = 59;
	static const unsigned short HORA_MIN = 0;
	static const unsigned short MINUTO_MIN = 0;
	static const unsigned short SEGUNDO_MIN = 0;

	Hora(); //constructor por defecto
	Hora(const Hora &h); //constructor copia
	Hora(const unsigned short hora, const unsigned short minuto = 0, const unsigned short segundo =
			0); //contructor

	void incrementarHora();
	void incrementarMinuto();
	void incrementarSegundo();

	void sumar(const Hora &h);
	void sumarHora(const unsigned short h);
	void sumarMinuto(const unsigned short m);
	void sumarSegundo(const unsigned short s);

	void setHora(const unsigned short h);
	void setMinuto(const unsigned short m);
	void setSegundo(const unsigned short s);
	void setHoraActual(void);

	string toString();
	unsigned short getHora() const {
		return hora;
	}
	unsigned short getMinuto() const {
		return minuto;
	}
	unsigned short getSegundo() const {
		return segundo;
	}

	Hora& operator=(const Hora &h);
	Hora& operator+(const Hora &x) const;

	friend bool operator>(const Hora &h1, const Hora &h2);
	friend bool operator==(const Hora &h1, const Hora &h2);
	friend bool operator>=(const Hora &h1, const Hora &h2);

	friend bool operator!=(const Hora &h1, const Hora &h2);
	

};

ostream& operator<<(ostream & os, const Hora h);

istream & operator>>(istream & is, Hora &h);

#endif /* HORA_H_ */

