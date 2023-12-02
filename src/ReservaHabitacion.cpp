#include <iostream>
#include "ReservaHabitacion.h"
#include "Habitacion.h"
#include "Cliente.h"


using namespace std;

int ReservaHabitacion::autonumerico = 0;

ReservaHabitacion::ReservaHabitacion(Cliente* titular, Habitacion* habitacion, Fecha *fechaEntrada, Fecha *fechaSalida, float seniaMin){
	this->titular = titular;
	this->nroReserva = ++this->autonumerico;
	this->habitacion = habitacion;
	this->fechaEntrada = new Fecha(fechaEntrada->getDia(), fechaEntrada->getMes(), fechaEntrada->getAnio());
	this->fechaSalida = new Fecha(fechaSalida->getDia(), fechaSalida->getMes(), fechaSalida->getAnio());
	this->fechaIn = NULL;
	this->fechaOut = NULL;
	this->horaIn = NULL;
	this->horaOut = NULL;
	this->seniaMin = seniaMin;
	this->consumo = new Consumo();
}


bool ReservaHabitacion::verificarTitular(string identHuesped){
	return (identHuesped == titular->getIdentificacion());
}

bool ReservaHabitacion::verificarAcompanante(string identHuesped){
	vector<Cliente*>::iterator it;
	for (it=acompanantes.begin(); it!=acompanantes.end(); ++it){
		if(identHuesped == (*it)->getIdentificacion()){
			return true;
		}
	}
	return false;
}


Cliente * ReservaHabitacion::getTitular(){
	return titular;
}

void ReservaHabitacion::agregarReservaAmenity(ReservaAmenity* reserva){
	consumo->agregarReservaAmenity(reserva);
}

void ReservaHabitacion::crearCompra(ProductoBar* prod, int cantProd, Fecha *fechaCompra){
	consumo->crearCompra(prod, cantProd, fechaCompra);
}

void ReservaHabitacion::checkIn(Fecha *fechaIn, Hora *horaIn, vector<Cliente*> acompanantes){
	this->fechaIn = new Fecha(fechaIn->getDia(), fechaIn->getMes(), fechaIn->getAnio());
	this->horaIn = new Hora(horaIn->getHora(), horaIn->getMinuto(), horaIn->getSegundo());
	this->acompanantes = acompanantes;
}

void ReservaHabitacion::checkOut(Fecha *fechaOut, Hora *horaOut){
	this->fechaOut = new Fecha(fechaOut->getDia(), fechaOut->getMes(), fechaOut->getAnio());
	this->horaOut = new Hora(horaOut->getHora(), horaOut->getMinuto(), horaOut->getSegundo());
	this->mostrarPagoTotal();
}

void ReservaHabitacion::mostrarPagoTotal(){
	cout<<"\n===========INFORMACION DEL TITULAR============\n"<<endl;
	titular->listarInfo();
	float pagoTotalReserva = habitacion->costoTotalReserva(fechaEntrada, fechaSalida);
	float pagoRestante = pagoTotalReserva - seniaMin;
	float penalizacion = calcularPenalizacion(horaOut);
	consumo->imprimirFacturaConsumo();
	cout<< "Total de la reserva ------------ $"<< pagoTotalReserva <<endl;
	cout<< "Seña minima ------------ $"<< seniaMin <<endl;
	cout<< "Pago restante: "<< pagoRestante <<endl;
	cout<< "Penalizacion por incumplimiento ------------- $"<<penalizacion<<endl;
	cout<< "TOTAL ----------- $"<< pagoRestante + consumo->calcularConsumos() + penalizacion<<endl;
}

float ReservaHabitacion::calcularPenalizacion(Hora * horaOut){
	Hora horaOnce(11,0,0);
	if(horaOnce >= *horaOut){
		return 0;
	}else{
		Hora horaTrece(13,0,0);
		if(*horaOut > horaOnce && horaTrece >= *horaOut){
			return habitacion->getPrecioPorNoche() / 2;
		}else{
			return habitacion->getPrecioPorNoche();
		}
	}
}


Fecha* ReservaHabitacion::getFechaEntrada(){
	return fechaEntrada;
}

Fecha* ReservaHabitacion::getFechaSalida(){
	return fechaSalida;
}

Fecha* ReservaHabitacion::getFechaIn(){
	return fechaIn;
}

Hora* ReservaHabitacion::getHoraIn(){
	return horaIn;
}

Fecha* ReservaHabitacion::getFechaOut(){
	return fechaOut;
}

Hora* ReservaHabitacion::getHoraOut(){
	return horaOut;
}

Habitacion* ReservaHabitacion::getHabitacion(){
	return habitacion;
}


ReservaHabitacion::~ReservaHabitacion() {
	this->titular = NULL;
	this->habitacion = NULL;
	delete fechaEntrada;
	delete fechaSalida;
	delete fechaIn;
	delete horaIn;
	delete fechaOut;
	delete horaOut;
	delete consumo;
	acompanantes.clear();
}
