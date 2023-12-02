/*
 * Hora.cpp
 */

#include <iomanip>
#include <iostream>
#include <ctime>
#include "Hora.h"
using namespace std;


Hora::Hora() {
	setHoraActual();
}
Hora::Hora(const Hora &h) {
	*this = h; //lo puedo hacer porque los datos miembros son tipos primitivos
}

Hora::Hora(const unsigned short hora, const unsigned short minuto, const unsigned short segundo) {
	setHora(hora);
	setMinuto(minuto);
	setSegundo(segundo);
}

void Hora::setHora(const unsigned short int h) {
	hora = h % (HORA_MAX + 1);
}
void Hora::setMinuto(const unsigned short int m) {
	minuto = m % (MINUTO_MAX + 1);
}
void Hora::setSegundo(const unsigned short int s) {
	segundo = s % (SEGUNDO_MAX + 1);
}

void Hora::setHoraActual(void) {
	struct tm *ptr;
	time_t sec;

	time(&sec);
	ptr = localtime(&sec);
	hora = (short) ptr->tm_hour;
	minuto = (short) ptr->tm_min;
	segundo = (short) ptr->tm_sec;
}

string Hora::toString() {
	stringstream flujo;
	flujo << this->hora <<":"<< this->minuto <<":"<< this->segundo;
	return string(flujo.str());
}


void Hora::sumar(const Hora &h) {
	sumarSegundo(h.segundo);
	sumarMinuto(h.minuto);
	sumarHora(h.hora);
}
void Hora::sumarHora(const unsigned short int h) {
	setHora(hora + h);
}
void Hora::sumarMinuto(const unsigned short int m) {
	unsigned short int total = minuto + m;
	sumarHora(total / (MINUTO_MAX + 1));
	setMinuto(total);
}
void Hora::sumarSegundo(const unsigned short int s) {
	unsigned short int total = segundo + s;
	sumarMinuto(total / (SEGUNDO_MAX + 1));
	setSegundo(total);
}

void Hora::incrementarHora() {
	hora++;
	if (hora > HORA_MAX) {
		hora = HORA_MIN;
	}
}
void Hora::incrementarMinuto() {
	minuto++;
	if (minuto > MINUTO_MAX) {
		minuto = MINUTO_MIN;
		incrementarHora();
	}
}
void Hora::incrementarSegundo() {
	segundo++;
	if (segundo > SEGUNDO_MAX) {
		segundo = SEGUNDO_MIN;
		incrementarMinuto();
	}
}

Hora& Hora::operator=(const Hora &h) {
	if (this != &h) {
		hora = h.hora;
		minuto = h.minuto;
		segundo = h.segundo;
	}
	return *this;
}
Hora& Hora::operator+(const Hora &h) const{
	Hora *aux = new Hora(*this);
	aux->sumar(h);
	return *aux;
}


bool operator>(const Hora &h1, const Hora &h2) {
	bool resultado = false;
	if ((h1.hora > h2.hora) || (h1.hora == h2.hora && h1.minuto > h2.minuto) || (h1.hora == h2.hora
			&& h1.minuto == h2.minuto && h1.segundo > h2.segundo)) {
		resultado = true;
	}
	return resultado;
}
bool operator==(const Hora &h1, const Hora &h2) {
	bool resultado = false;
	if (h1.hora == h2.hora && h1.minuto == h2.minuto && h1.segundo == h2.segundo) {
		resultado = true;
	}
	return resultado;
}
bool operator>=(const Hora &h1, const Hora &h2){
	return (h1>h2 || h1==h2);
}
bool operator!=(const Hora &h1, const Hora &h2) {
	return !(h1 == h2);
}

bool operator<(const Hora &h1, const Hora &h2) {
	bool resultado = false;
	if (!(h1 > h2) && (h1 != h2)) {
		resultado = true;
	}
	return resultado;
}

ostream& operator<<(ostream & os, const Hora h) {
	os.fill('0');
	os << setw(2) << h.getHora() << ":" << setw(2) << h.getMinuto() << ":" << setw(2)
			<< h.getSegundo();
	return os;
}

istream & operator>>(istream & is, Hora &h) {
	unsigned short hs, min, seg;
	is >> hs >> min >> seg;
	h.setHora(hs);
	h.setMinuto(min);
	h.setSegundo(seg);
	return is;
}

