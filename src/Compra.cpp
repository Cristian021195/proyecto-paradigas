#include "Compra.h"
#include "ProductoBar.h"
#include <iostream>

using namespace std;

int Compra::autonumerico = 0;

Compra::Compra(ProductoBar* producto, int cantProd, Fecha *fechaCompra) {
	this->codCompra = ++this->autonumerico;
	this->producto = producto;
	this->cantProd = cantProd;
	this->fechaCompra = new Fecha(fechaCompra->getDia(), fechaCompra->getMes(), fechaCompra->getAnio());
}

void Compra::listarInfo(){
	cout<< "Fecha: "<<this->fechaCompra->toString()<<endl;
	this->producto->listarInfo();
	cout<< "X" << this->cantProd;
	cout<< "-------------- $"<< this->calcularTotal() <<endl;
}

float Compra::calcularTotal(){
	return this->producto->getPrecioBase()*this->cantProd;
}

Compra::~Compra() {
	this->producto = NULL;
	delete fechaCompra;
}
