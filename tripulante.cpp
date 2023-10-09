#include "tripulante.h"

string tripulante::getPuesto() {
    return puesto;
}

int tripulante::getExperienciaAños() {
    return experienciaAños;
}

int tripulante::getHorasMax() {
    return horasMax;
}

void tripulante::setPuesto(string puesto) {
    this->puesto = puesto;
}

void tripulante::setExperienciaAños(int Xp) {
    experienciaAños = Xp;
}

void tripulante::setHorasMax(int HM) {
    horasMax = HM;
}
