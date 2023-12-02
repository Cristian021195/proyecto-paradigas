/*
 * Fecha.h
 */

#ifndef FECHA_H_
#define FECHA_H_
#include <iostream>

using namespace std;

class Fecha {
private:
	short dia;
	short mes;
	short anio;
	bool esDiaValido() const;
	bool esMesValido() const;
	bool esAnioValido() const;
	short diasEnMes(const short mes) const;
public:
	//Constructores
	Fecha();
	Fecha(const short d, const short m, const short a);
	Fecha(const Fecha &f);
	//Setters
	void setFechaActual(void);
	void setFecha(const short d, const short m, const short a);
	//Getters
	short getDia() const;
	short getMes() const;
	short getAnio() const;
	//Test anio bisiesto
	bool esAnioBisiesto(void) const;
	//Operacion que transforma una fecha a string
    string toString();

	friend long int operator-(Fecha &fecha1, Fecha &fecha2);//Retorna la diferencia de d�as entre 2 fechas
	long int cantidadDiasDelAnio();
	friend bool operator>=(Fecha fecha1, Fecha fecha2);
	friend bool operator==(Fecha fecha1, Fecha fecha2);
};

//Sobrecarga del operador < como funci�n
//externa de la clase Fecha
bool operator<(Fecha fecha1, Fecha fecha2);


#endif /* FECHA_H_ */
