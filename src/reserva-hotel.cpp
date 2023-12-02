#include <iostream>
#include <vector>
#include <string>
#include "Sistema.h"
#include "Cliente.h"
#include "Fecha.h"
#include "Hora.h"
using namespace std;

int main() {
	Sistema S;

	S.crearHabitacion(1,"hab1",100,5,4,101);
	S.crearHabitacion(2,"hab2",101,4,5,102);
	S.crearHabitacion(3,"hab3",102,3,6,103);
	S.crearHabitacion(4,"hab4",101,2,5,104);
	S.crearHabitacion(5,"hab5",104,7,7,105);

	S.crearProductoBar("x1", "papitas", "snaks", 10);
	S.crearProductoBar("x2", "alfajor", "gololsina", 20);
	S.crearProductoBar("x3", "cafe", "merienda", 30);

	S.crearAmenity("am1","piscina","recreacion",1100);
	S.crearAmenity("am2","cine","entretenimiento",1200);
	S.crearAmenity("am3","spa","relax",1300);

	//Reserva 1
	//Fecha para reserva 1
	Fecha f1(20,12,2023); Hora h1(14,0,0);
	Fecha f2(22,12,2023); Hora h2(12,0,0);

	cout<< "CARACTERISTICAS PARA LA RESERVA 1\n" <<endl;
	cout<< "Fecha de reserva: " << f1.toString() << " - " << f2.toString()<<endl;
	cout<< "Nro camas: 5"<<endl;
	cout<< "Capacidad: 4"<<endl;
	cout<< "Tamaño: 101 m2"<<endl;

	Cliente T1("Carlo", "Lopez", "39356700", "dni", "arg", "Tucuman", "carlo@gmail.com", "av indep 1800", "0XXCASD", "3865332311");//Titular
	Cliente A1("Carlo Jr", "Lopez", "39356701", "dni"); //Acompanante de T1
	Cliente A2("Sebastian", "Lopez", "39356702", "dni"); //Acompanante de T1
	vector <Cliente *> acompanantesT = {&A1, &A2};


	S.crearReservaHab(&T1, &f1, &f2, 5, 4, 101, 92);
	//Se crea una reserva en la habitacion 2, dado que esta cumple los requisitos y no tiene reservas registradas

	S.checkIn(2, "39356700", &f1, &h1, acompanantesT);
	//Se realiza el checkIn de la habitacion 2

	//Reserva 2
	//Fechas para reserva 2
	Fecha f3(f1);
	Fecha f4(23,12,2023);

	cout<< "\nCARACTERISTICAS PARA LA RESERVA 2\n" <<endl;
	cout<< "Fecha de reserva: " << f3.toString() << " - " << f4.toString()<<endl;
	cout<< "Nro camas: 5"<<endl;
	cout<< "Capacidad: 4"<<endl;
	cout<< "Tamaño: 101 m2"<<endl;

	Cliente T2("Jeremy", "Gonzales", "44157101" ,"dni", "arg", "Tucuman", "jgonzales@gmail.com", "av indep 1600", "0XXCAEE", "3813025220");//Titular
	Cliente A3("Jose", "Dominguez", "39356701", "dni"); //Acompanante de T2
	Cliente A4("Marta", "Soria", "39356702", "dni"); //Acompanante de T2
	vector<Cliente*> acompanantesT2 = {&A3, &A4};

	S.crearReservaHab(&T2, &f3, &f4, 5, 4, 101, 95);

	cout<< "\n=========EL TITULAR Y/O ALGUN ACOMPAÑANTE HACEN RESERVAS DE AMENITIES========="<<endl;
	S.crearReservaAmenity(2,"39356700","piscina",&f1,&h1);
	Fecha fechaReserva(21, 12, 2023);
	S.crearReservaAmenity(2, "39356702", "spa", &fechaReserva, &h2);
	cout<< "---------------------------------------------------------------"<<endl;

	cout<< "\n=========SE REALIZAN COMPRAS DE PRODUCTOS DEL BAR========="<<endl;
	S.crearCompra(2, "x1",2,&f1);
	S.crearCompra(2,"x2", 2, &f1);
	S.checkOut(2, "39356700", &f2, &h2);

	//Reserva 3

	//Fechas para la reserva 3
	Fecha f5(26,12,2023);
	Fecha f6(28,12,2023);
	cout<< "\nCARACTERISTICAS PARA LA RESERVA 3\n" <<endl;
	cout<< "Fecha de reserva: " << f5.toString() << " - " << f6.toString()<<endl;
	cout<< "Nro camas: 5"<<endl;
	cout<< "Capacidad: 4"<<endl;
	cout<< "Tamaño: 101 m2"<<endl;

	//Se utilizaran como titular y acompanantes a T2, A3 y A4
	S.crearReservaHab(&T2, &f5, &f6, 5, 4, 101, 95);
	S.checkIn(2, "44157101", &f5, &h1, acompanantesT2);
	return 0;
}
