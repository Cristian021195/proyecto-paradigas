#ifndef SISTEMA_H_
#define SISTEMA_H_
#include "Amenity.h"
#include "ProductoBar.h"
#include "Habitacion.h"
#include "Cliente.h"
#include "Fecha.h"

class Sistema {
	vector<Amenity*> amenities;
	vector<ProductoBar*> productos;
	vector<Habitacion*> habitaciones;
	vector<ReservaHabitacion*> reservasHabitaciones;
	Habitacion* buscarHabDisponible(Fecha * fechaE, Fecha * fechaS, int nroCamas, int capacidad, float tamanio);
public:
	Sistema();
	virtual ~Sistema();
	void crearAmenity(string codigo, string nombre, string descripcion, float precioReserva=0);
	void crearHabitacion(int nroHab, string nombrePopular, float tamanio, int capacidad, int nroCamas, float precioPorNoche);
	void crearProductoBar(string codigo, string nombre, string descripcion, float precioBase);
	void crearReservaAmenity(int nroHab, string identHuesped, string nombreAmenity, Fecha* fechaReserva, Hora* horaReserva);
	void crearReservaHab(Cliente * titular, Fecha * fechaEntrada, Fecha* fechaSalida, int nroCamas, int capacidad, float tamanio, float seniaMin);
	void crearCompra(int nroHab, string  codProd, int cantProd, Fecha * fechaCompra);
	void checkIn(int nroHab, string identTitular, Fecha * fechaLlegada, Hora * horaLlegada, vector<Cliente*> acompanantes);
	void checkOut(int nroHab, string identTitular, Fecha * fechaOut, Hora * horaOut);
};

#endif /* SISTEMA_H_ */
