#include <iostream>
#include "Amenity.h"
using namespace std;
#include "ReservaAmenity.h"

int ReservaAmenity::autonumerico = 0;

ReservaAmenity::ReservaAmenity(Amenity *amenity, int nroHabitacion, string identHuesped, Fecha *fecha, Hora *hora) {
    this->nroReserva = ++autonumerico;
    this->nroHabitacion = nroHabitacion;
    this->identHuesped = identHuesped;
    this->amenity = amenity;
    this->fecha = new Fecha(*fecha);
    this->hora = new Hora(*hora);
}

ReservaAmenity::ReservaAmenity(const ReservaAmenity &co) {
    this->nroReserva = nroReserva;
    this->nroHabitacion = nroHabitacion;
    this->identHuesped = identHuesped;
    this->amenity = amenity;
    this->fecha = fecha;
    this->hora = hora;
}

ReservaAmenity::~ReservaAmenity(){
	delete fecha;
	delete hora;
}

Amenity * ReservaAmenity::getAmenity(){
	return amenity;
}

string ReservaAmenity::getIdentHuesped() const {
    return this->identHuesped;
}

int ReservaAmenity::getNroHab() const {
    return this->nroHabitacion;
}

void ReservaAmenity::listarInfo() {
    cout<<"Fecha: "<< this->fecha->toString() << " " << this->hora->toString()<<endl;
    amenity->listarInfo();
}

Fecha * ReservaAmenity::getFecha(){
	return this->fecha;
}
Hora * ReservaAmenity::getHora(){
	return this->hora;
}
