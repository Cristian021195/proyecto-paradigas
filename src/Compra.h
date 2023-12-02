#ifndef COMPRA_H_
#define COMPRA_H_
#include "ProductoBar.h"
#include <iostream>
#include "Fecha.h"

using namespace std;

class Compra {
	static int autonumerico;
	int codCompra;
	int cantProd;
	ProductoBar* producto;
	Fecha* fechaCompra;
public:
	Compra(ProductoBar* producto, int cantProd, Fecha *fechaCompra);
	void listarInfo();
	float calcularTotal();
	~Compra();
};



#endif /* COMPRA_H_ */
