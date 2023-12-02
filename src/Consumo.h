#ifndef CONSUMO_H_
#define CONSUMO_H_
#include "ProductoBar.h"
#include "Compra.h"
#include "ReservaAmenity.h"
#include <iostream>
#include <vector>
using namespace std;

class Consumo {
    vector<Compra*> compras;
    vector<ReservaAmenity*> reservasAmenities;
    void imprimirComprasRealizadas();
    void imprimirReservasAmenities();

public:
    Consumo();
    Consumo(const Consumo &c);
    void agregarReservaAmenity(ReservaAmenity *reserva);
    void crearCompra(ProductoBar *producto, int cantProd, Fecha * fechaCompra);
    void imprimirFacturaConsumo();
    float calcularConsumos();
    virtual ~Consumo();
};

#endif /* CONSUMO_H_ */
