#include "pasajero.h"

string pasajero::getNacionalidad() {
    return nacionalidad;
}

int pasajero::getCntMaletas() {
    return cntMaletas;
}

string pasajero::getInfoMedica() {
    return infoMedica;
}

void pasajero::setNacionalidad(string Nacionalidad) {
    nacionalidad = Nacionalidad;
}

void pasajero::setCntMaletas(int ctMaletas) {
    cntMaletas = ctMaletas;
}

void pasajero::setInfoMedica(string InfMed) {
    infoMedica = InfMed;
}