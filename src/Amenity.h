#ifndef AMENITY_H_
#define AMENITY_H_
#include <iostream>
#include <Vector>
#include "Hora.h"
#include "Fecha.h"
#include "ReservaAmenity.h"
using namespace std;


class Amenity {
	string codigo;
	string nombre;
	string descripcion;
	float precioBase;
	vector <ReservaAmenity*> reservas;
public:

	Amenity(string codigo,string nombre,string descripcion,float precioReserva=0);
	Amenity(const Amenity &co);
	virtual ~Amenity();

	ReservaAmenity * crearReservaAmenity(Amenity* amenity, int nroHabitacion,string identfHuesped,Fecha *fechaReserva,Hora * horaReserva);
	string getNombre();
	float getPrecioBase();
	void listarInfo();
	bool hayDisponibilidad(Fecha *fechaReserva,Hora *horaReserva);

};

#endif /* AMENITY_H_ */
