/*
 * Habitacion.h
 *
 *  Created on: 25 nov 2023
 *      Author: crist
 */

#ifndef HABITACION_H_
#define HABITACION_H_

#include <iostream>
#include <string>
#include <vector>
#include "Fecha.h"
#include "ReservaHabitacion.h"

using namespace std;

enum tipoEstado{Reservada, Ocupada, Libre};

class Habitacion {
	int nroHabitacion;
	string nombrePopular;
	float tamanio;
	int capacidad;
	int nroCamas;
	float precioPorNoche;
    vector <ReservaHabitacion*> reservas;
public:
    Habitacion(int nroHabitacion,string nombrePopular,float tamanio,int capacidad,int nroCamas,float precioPorNoche);
	virtual ~Habitacion();
	Habitacion(const Habitacion &other);

	int getNroHab();
	int getNroCamas();
	int getCapacidad();
	float getTamanio();
	float getPrecioPorNoche();
	tipoEstado hayDisponibilidad(Fecha * entrada, Fecha * salida);
	float costoTotalReserva(Fecha * entrada, Fecha * salida);
	void agregarReserva(ReservaHabitacion * reserva);
};

#endif /* HABITACION_H_ */
