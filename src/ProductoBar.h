#ifndef PRODUCTOBAR_H_
#define PRODUCTOBAR_H_
#include <iostream>
using namespace std;

class ProductoBar {
	string codProducto;
	string nombre;
	string descripcion;
	float precioBase;
public:
	ProductoBar(string codProducto, string nombre, string descripcion, float precioBase);
	ProductoBar(const ProductoBar &p);
	void listarInfo();
	float getPrecioBase()const;
	string getCodProd();
};

#endif /* PRODUCTOBAR_H_ */
