#ifndef RESERVAHABITACION_H_
#define RESERVAHABITACION_H_
#include <vector>
#include "Cliente.h"
#include "Fecha.h"
#include "Hora.h"
#include "Consumo.h"
#include "ReservaAmenity.h"
#include "ProductoBar.h"

class Habitacion;

class ReservaHabitacion {
	static int autonumerico;
	int nroReserva;
	Consumo* consumo;
	Habitacion* habitacion;
	Cliente * titular;
	vector<Cliente*> acompanantes;
	float seniaMin;
	Fecha* fechaEntrada;
	Fecha* fechaSalida;
	Fecha* fechaIn;
	Hora* horaIn;
	Fecha* fechaOut;
	Hora* horaOut;
	void mostrarPagoTotal();
	float calcularPenalizacion(Hora * horaOut);
public:
	ReservaHabitacion(Cliente* titular, Habitacion* habitacion, Fecha* fechaEntrada, Fecha* fechaSalida, float seniaMin);

	Fecha* getFechaEntrada();
	Fecha* getFechaSalida();
	Fecha* getFechaIn();
	Hora* getHoraIn();
	Fecha* getFechaOut();
	Hora* getHoraOut();
	Habitacion* getHabitacion();
	Cliente * getTitular();

	bool verificarTitular(string identificacion);
	bool verificarAcompanante(string identificacion);
	void agregarReservaAmenity(ReservaAmenity* reserva);
	void crearCompra(ProductoBar* prod, int cantProd, Fecha* fechaCompra);
	void checkIn(Fecha *fechaIn, Hora *horaIn, vector<Cliente*> acompanantes);
	void checkOut(Fecha *fechaOut, Hora *horaOut);
	virtual ~ReservaHabitacion();
};

#endif /* RESERVAHABITACION_H_ */
