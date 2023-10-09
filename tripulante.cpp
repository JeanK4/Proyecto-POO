#include "tripulante.h"

string tripulante::getPuesto() {
    return puesto;
}

int tripulante::getExperienciaAnos() {
    return experienciaAnos;
}

int tripulante::getHorasMax() {
    return horasMax;
}

void tripulante::setPuesto(string puesto) {
    this->puesto = puesto;
}

void tripulante::setExperienciaAnos(int Xp) {
    experienciaAnos = Xp;
}

void tripulante::setHorasMax(int HM) {
    horasMax = HM;
}
