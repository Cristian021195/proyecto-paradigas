#ifndef RESERVAAMENITY_H_
#define RESERVAAMENITY_H_
#include "Fecha.h"
#include "Hora.h"
#include <iostream>
using namespace std;

class Amenity;

class ReservaAmenity {
    static int autonumerico;
    int nroReserva;
    int nroHabitacion;
    string identHuesped;
    Fecha *fecha;
    Hora *hora;
    Amenity *amenity;
public:
    ReservaAmenity(Amenity *amenity, int nroHabitacion, string identHuesped, Fecha *fechaReserva, Hora *horaReserva);
    ReservaAmenity(const ReservaAmenity &co);
    virtual ~ReservaAmenity();
    string getIdentHuesped() const;
    int getNroHab() const;
    void listarInfo();
    Fecha * getFecha();
    Hora * getHora();
    Amenity * getAmenity();

};

#endif //RESERVAAMENITY_H_
