#include "Sistema.h"

Sistema::Sistema() {
	// TODO Auto-generated constructor stub

}

Sistema::~Sistema() {
	// TODO Auto-generated destructor stub

	vector<ReservaHabitacion*>::iterator ith;
	for (ith=reservasHabitaciones.begin(); ith!=reservasHabitaciones.end(); ++ith){
		delete *ith;
	}
	reservasHabitaciones.clear();

	vector<Habitacion*>::iterator it;
	for (it=habitaciones.begin(); it!=habitaciones.end(); ++it){
		delete *it;
	}
	habitaciones.clear();


	vector<Amenity*>::iterator ita;
	for (ita=amenities.begin(); ita!=amenities.end(); ++ita){
		delete *ita;
	}
	amenities.clear();

	vector<ProductoBar*>::iterator itp;
	for (itp=productos.begin(); itp!=productos.end(); ++itp){
		delete *itp;
	}
	productos.clear();
}

void Sistema::crearAmenity(string codigo, string nombre, string descripcion, float precioReserva){
	Amenity* nuevoAmenity = new Amenity(codigo, nombre, descripcion, precioReserva);
	amenities.insert(amenities.end(), nuevoAmenity);
}

void Sistema::crearHabitacion(int nroHab, string nombrePopular, float tamanio, int capacidad, int nroCamas, float precioPorNoche){
	Habitacion* nuevaHabitacion = new Habitacion(nroHab, nombrePopular, tamanio, capacidad, nroCamas, precioPorNoche);
	habitaciones.insert(habitaciones.end(), nuevaHabitacion);
}

void Sistema::crearProductoBar(string codigo, string nombre, string descripcion, float precioBase){
	ProductoBar* nuevoProducto = new ProductoBar(codigo, nombre, descripcion, precioBase);
	productos.insert(productos.end(), nuevoProducto);
}

void Sistema::crearReservaAmenity(int nroHab, string identHuesped, string nombreAmenity, Fecha* fechaReserva, Hora* horaReserva){
   	bool existeAmenityDisponible = false;
   	bool existeReservaHabActiva = false;
   	vector<ReservaHabitacion*>::iterator it;
	for (it=reservasHabitaciones.begin(); it!=reservasHabitaciones.end(); ++it){
		if ((*it)->getHabitacion()->getNroHab() == nroHab && ((*it)->verificarTitular(identHuesped) || (*it)->verificarAcompanante(identHuesped))){
			if ((*it)->getFechaIn() != NULL && (*it)->getFechaOut() == NULL && *fechaReserva >= *((*it)->getFechaIn())){
				existeReservaHabActiva = true;
				vector<Amenity*>::iterator it2;
				for (it2=amenities.begin(); it2!=amenities.end(); ++it2){
					if ((*it2)->getNombre() == nombreAmenity && (*it2)->hayDisponibilidad(fechaReserva, horaReserva)){
						existeAmenityDisponible = true;
						ReservaAmenity* nuevaReservaAme = (*it2)->crearReservaAmenity(*it2, (*it)->getHabitacion()->getNroHab(), identHuesped, fechaReserva, horaReserva);
						(*it)->agregarReservaAmenity(nuevaReservaAme);
						cout<<"Se ha realizado la reserva correctamente"<<endl;
						break;
					}
				}
			}
		}
   	}
   	if(!existeReservaHabActiva || !existeAmenityDisponible){
   		cout<<"No existe reserva activa, o amenity disponible"<<endl;
   	}
}

void Sistema::crearReservaHab(Cliente * titular, Fecha * fechaEntrada, Fecha* fechaSalida, int nroCamas, int capacidad, float tamanio, float seniaMin){
	Habitacion* habDisponible = buscarHabDisponible(fechaEntrada, fechaSalida, nroCamas, capacidad, tamanio);
	if(habDisponible != NULL){
		if(seniaMin >= 0.3*habDisponible->costoTotalReserva(fechaEntrada, fechaSalida)){
			ReservaHabitacion* reserva = new ReservaHabitacion(titular, habDisponible, fechaEntrada, fechaSalida, seniaMin);
			reservasHabitaciones.push_back(reserva);
			habDisponible->agregarReserva(reserva);
			cout << "Se ha realizado la reserva correctamente" << endl;
		}else{
			cout << "No se pudo realizar la reserva porque no se deposito la seña minima esperada" << endl;
		}
	}else{
		cout << "No se pudo realizar la reserva porque no se encuentra una habitacion disponible" << endl;
	}
}

void Sistema::crearCompra(int nroHab, string  codProd, int cantProd, Fecha * fechaCompra){
	bool existeReservaHab = false; bool existeProd = false;

	vector<ReservaHabitacion*>::iterator it;
	for (it=reservasHabitaciones.begin(); it!=reservasHabitaciones.end(); ++it){
		if((*it)->getHabitacion()->getNroHab() == nroHab){
			if((*it)->getFechaIn() != NULL && (*it)->getFechaOut() == NULL){
				existeReservaHab = true;
				vector<ProductoBar*>::iterator itp;
				for (itp=productos.begin(); itp!=productos.end(); ++itp){
					if((*itp)->getCodProd() == codProd){
						(*it)->crearCompra(*itp, cantProd, fechaCompra);
						existeProd = true;
						break;
					}
				}
			}
		}
	}
	if(!existeReservaHab || !existeProd){
		cout << "Sin reserva, o sin producto" << endl;
	}else{
		cout << "Reserva OK!, producto adquirido!" << endl;
	}
}

void Sistema::checkIn(int nroHab, string identTitular, Fecha * fechaLlegada, Hora * horaLlegada, vector<Cliente *> acompanantes){
	Hora h(13,0,0);
	bool existeReservaActiva = false;
	if(*horaLlegada >= h){
		vector<ReservaHabitacion*>::iterator it;
		for (it=reservasHabitaciones.begin(); it!=reservasHabitaciones.end(); ++it){//asd
			if((*it)->getHabitacion()->getNroHab() == nroHab && (*it)->getTitular()->getIdentificacion() == identTitular){
				if(*((*it)->getFechaEntrada()) >= *fechaLlegada && *((*it)->getFechaSalida()) >= *fechaLlegada && (*it)->getFechaIn() == NULL){
					existeReservaActiva = true;
					(*it)->checkIn(fechaLlegada, horaLlegada, acompanantes);
					break;
				}
			}
		}
	}

	if(!existeReservaActiva){
		cout << "No se puede hacer el checkIn porque no hay una reserva reciente asociada a la habitacion o al titular" << endl;
	}else{
		cout << "Check in exitoso" << endl;
	}
}

void Sistema::checkOut(int nroHab, string identTitular, Fecha * fechaOut, Hora * horaOut){
	bool existeReservaActiva = false;
	vector<ReservaHabitacion*>::iterator it;
	for (it=reservasHabitaciones.begin(); it!=reservasHabitaciones.end(); ++it){
		if((*it)->getHabitacion()->getNroHab() == nroHab && (*it)->getTitular()->getIdentificacion() == identTitular){
			if((*it)->getFechaIn() != NULL && (*it)->getFechaOut() == NULL){
				existeReservaActiva = true;
				(*it)->checkOut(fechaOut, horaOut);
				break;
			}
		}
	}

	if(!existeReservaActiva){
		cout << "No se puede hacer el checkout de una habitacion sin reserva" << endl;
	}else{
		cout << "Check Out exitoso" << endl;
	}
}

Habitacion* Sistema::buscarHabDisponible(Fecha * fechaE, Fecha * fechaS, int nroCamas, int capacidad, float tamanio){
	if(nroCamas > 0 && capacidad > 0 && tamanio > 0){
		vector<Habitacion*>::iterator it;
		for (it=habitaciones.begin(); it!=habitaciones.end(); ++it){
			if(nroCamas == (*it)->getNroCamas() && capacidad == (*it)->getCapacidad() && tamanio == (*it)->getTamanio()){
				if((*it)->hayDisponibilidad(fechaE, fechaS) == Libre){
					return (*it);
				}
			}
		}
	}

	return 0;

}


