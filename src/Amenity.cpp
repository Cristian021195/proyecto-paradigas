#include <iostream>
#include "Amenity.h"
#include <Vector>
#include "ReservaAmenity.h"
using namespace std;

Amenity::Amenity(string codigo, string nombre, string descripcion, float precioBase) {
	this->codigo = codigo;
	this->nombre = nombre;
	this->descripcion = descripcion;
	this->precioBase = precioBase;

}
Amenity::Amenity(const Amenity &co) {
	this->codigo = co.codigo;
	this->descripcion = co.descripcion;
	this->nombre = co.nombre;
	this->precioBase = co.precioBase;
	this->reservas = co.reservas;
}

Amenity::~Amenity() {
	vector<ReservaAmenity*>::iterator it;
	for (it == reservas.begin(); it != reservas.end(); it++) {
		delete (*it);
	}
	reservas.clear();
}


ReservaAmenity * Amenity::crearReservaAmenity(Amenity* amenity, int nroHabitacion,string identfHuesped,Fecha *fechaReserva,Hora * horaReserva) {
	ReservaAmenity * reserva = new ReservaAmenity(amenity, nroHabitacion, identfHuesped, fechaReserva, horaReserva);
	reservas.insert(reservas.end(), reserva);
	return reserva;
}


bool Amenity::hayDisponibilidad(Fecha *fechaReserva,Hora *horaReserva){
	bool existeReserva = false;
	vector<ReservaAmenity*>::iterator it;
	for (it = reservas.begin(); it != reservas.end(); ++it) {
		Fecha * fechaA = (*it)->getFecha();
		Hora * horaA = (*it)->getHora();

		if(*fechaReserva == *fechaA){
			existeReserva = true;
			Hora aux(1);
			if(!(*horaReserva >= *horaA && (*horaA + aux) >= *horaReserva)){
				return true;
			}else{
				return false;
			}
		}
	}
	return !existeReserva;
}

string Amenity::getNombre() {
	return nombre;
}
float Amenity::getPrecioBase() {
	return precioBase;
}
void Amenity::listarInfo() {
	cout << nombre << "------------" <<precioBase << endl;
}


