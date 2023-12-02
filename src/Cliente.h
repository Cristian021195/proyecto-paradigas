#include <iostream>
#include <string>
#ifndef CLIENTE_H_
#define CLIENTE_H_

using namespace std;

class Cliente {
	static int autonumerico;
	int codigo;
	string nombre;
	string apellido;
	string identificacion;
	string tipoIdentificacion;
	string nacionalidad;
	string provCiudad;
	string email;
	string domicilio;
	string patenteVeh;
	string nroCelular;

public:
	Cliente(string nombre, string apellido, string identificacion,
			string tipoIdentificacion, string nacionalidad,string provCiudad,string email,string domicilio,
			string patenteVeh,string nroCelular);
	Cliente(string nombre, string apellido, string identificacion, string tipoIdentificacion);
	string getIdentificacion();
	void listarInfo();
};


#endif /* CLIENTE_H_ */
