#include "ProductoBar.h"
#include <iostream>

using namespace std;

ProductoBar::ProductoBar(string codProducto, string nombre, string descripcion, float precioBase) {
	this->codProducto = codProducto;
	this->nombre = nombre;
	this->descripcion = descripcion;
	this->precioBase = precioBase;
}

ProductoBar::ProductoBar(const ProductoBar &p){
	this->codProducto = p.codProducto;
	this->nombre = p.nombre;
	this->descripcion = p.descripcion;
	this->precioBase = p.precioBase;
}

void ProductoBar::listarInfo(){
	cout<< this->nombre << "  ";
	cout<< this->precioBase;
}

string ProductoBar::getCodProd(){
	return codProducto;
}

float ProductoBar::getPrecioBase()const { return this->precioBase; }
