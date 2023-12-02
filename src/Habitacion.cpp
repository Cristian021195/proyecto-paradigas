#include "Habitacion.h"
#include <sstream>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

Habitacion::Habitacion(int nroHabitacion,string nombrePopular,float tamanio,int capacidad,int nroCamas,float precioPorNoche):
	nroHabitacion(nroHabitacion),
	nombrePopular(nombrePopular),
	tamanio(tamanio),
	capacidad(capacidad),
	nroCamas(nroCamas),
	precioPorNoche(precioPorNoche){
}

int Habitacion::getNroHab(){ return nroHabitacion;}
float Habitacion::getPrecioPorNoche(){ return precioPorNoche; }

int Habitacion::getNroCamas(){return nroCamas;}
int Habitacion::getCapacidad(){return capacidad;}
float Habitacion::getTamanio(){return tamanio;}

tipoEstado Habitacion::hayDisponibilidad(Fecha * fechaEntrada, Fecha * fechaSalida){
	int i = 0;
	while(i < (int)reservas.size()){
		Fecha * fechaRegEntrada = reservas[i]->getFechaEntrada();
		Fecha * fechaRegSalida = reservas[i]->getFechaSalida();
		if( (*fechaEntrada >= *fechaRegEntrada && *fechaRegSalida >= *fechaEntrada) || (*fechaSalida >= *fechaRegEntrada && *fechaRegSalida >= *fechaSalida) ||
		(*fechaRegEntrada >= *fechaEntrada && *fechaSalida >= *fechaRegSalida) ){
			if(reservas[i]->getFechaIn() == NULL){
				return Reservada;
			}else{
				if(reservas[i]->getFechaOut() == NULL){
					return Ocupada;
				}
			}
		}
		i++;
	}
	return Libre;
}

float Habitacion::costoTotalReserva(Fecha * entrada, Fecha * salida){
	int cant = *salida - *entrada;
	float costo = cant*precioPorNoche*1.5;
	return costo;
}

void Habitacion::agregarReserva(ReservaHabitacion * reserva){
	reservas.push_back(reserva);
}
Habitacion::~Habitacion(){
	reservas.clear();
}
