#include <iostream>
#include "Cliente.h"

using namespace std;
int Cliente::autonumerico = 0;
Cliente::Cliente(string nombre, string apellido, string identificacion, string tipoIdentificacion,string nacionalidad,string provCiudad,string email,string domicilio, string patenteVeh,string nroCelular):
	codigo(++autonumerico), nombre(nombre), apellido(apellido), identificacion(identificacion), nacionalidad(nacionalidad), provCiudad(provCiudad), email(email), domicilio(domicilio), tipoIdentificacion(tipoIdentificacion), patenteVeh(patenteVeh), nroCelular(nroCelular){
}

Cliente::Cliente(string nombre, string apellido, string identificacion, string tipoIdentificacion):
	codigo(++autonumerico), nombre(nombre), apellido(apellido), identificacion(identificacion), tipoIdentificacion(tipoIdentificacion){
}


string Cliente::getIdentificacion(){
	return identificacion;
}

void Cliente::listarInfo(){
	cout << "Nombre Completo: " << nombre << " " << apellido << ", Identificacion: " << identificacion << "(" << tipoIdentificacion << ") " << endl;
}

