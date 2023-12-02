#include "Consumo.h"
#include "Amenity.h"
#include <iostream>
using namespace std;

Consumo::Consumo() {
}


void Consumo::agregarReservaAmenity(ReservaAmenity *reserva) {
    reservasAmenities.insert(reservasAmenities.end(), reserva);
}

void Consumo::crearCompra(ProductoBar *producto, int cantProd, Fecha * fechaCompra) {
    Compra *nuevaCompra = new Compra(producto, cantProd, fechaCompra);
    compras.insert(compras.end(), nuevaCompra);
}

void Consumo::imprimirComprasRealizadas() {
    if((int)compras.size() > 0){
    	cout<< "\n************** COMPRAS REALIZADAS **************"<<endl;
    	float costoCompras = 0;
    	vector<Compra*>::iterator it;
    	for (it = compras.begin() ; it != compras.end() ; it++) {
    	    (*it)->listarInfo();
    	      costoCompras = costoCompras + (*it)->calcularTotal();
    	      cout<< "------------------------------"<<endl;
    	}
    	cout<< "\nSUBTOTAL COMPRAS -------------- $"<< costoCompras <<endl;
    }
}

void Consumo::imprimirReservasAmenities() {
	if((int)reservasAmenities.size() > 0){
		cout<< "\n************** RESERVAS DE AMENITIES REALIZADAS **************"<<endl;
		float costoReservas = 0;
		vector<ReservaAmenity*>::iterator it;
		for (it = reservasAmenities.begin() ; it != reservasAmenities.end() ; it++) {
			costoReservas += (*it)->getAmenity()->getPrecioBase();
			(*it)->listarInfo();
			cout<< "------------------------------"<<endl;
		}
		cout<< "\nSUBTOTAL RESERVAS AMENITIES --------------- $"<< costoReservas <<endl;
	}
}

void Consumo::imprimirFacturaConsumo() {
	if((int)compras.size() > 0 || (int)reservasAmenities.size() > 0){
		cout<< "\n============== FACTURA DE CONSUMOS REALIZADOS ==============\n"<<endl;
		imprimirComprasRealizadas();
		imprimirReservasAmenities();
		cout<< "TOTAL CONSUMOS EXTRAS ----------- $" << calcularConsumos() <<endl;
	}
}

float Consumo::calcularConsumos() {
    float costoConsumo = 0;
    vector<Compra*>::iterator it;
    for (it = compras.begin() ; it != compras.end() ; it++) {
        costoConsumo = costoConsumo + (*it)->calcularTotal();
    }
    vector<ReservaAmenity*>::iterator itt;
    for (itt = reservasAmenities.begin() ; itt != reservasAmenities.end() ; itt++) {
        costoConsumo = costoConsumo + (*itt)->getAmenity()->getPrecioBase();
    }
    return costoConsumo;
}

Consumo::~Consumo() {
    vector<Compra*>::iterator it;
    for (it = compras.begin() ; it != compras.end() ; it++) {
        delete *it;
    }
    compras.clear();
    reservasAmenities.clear();
}
