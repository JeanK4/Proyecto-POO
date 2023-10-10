#include "tripulante.h"

tripulante::tripulante(std::string Ced, std::string Nom, std::string FechNaci, std::string gender, std::string address, std::string telef, std::string mail,std::string puest, int Xp, int HM) : persona(Ced, Nom, FechNaci, gender, address, telef, mail), puesto(puest), experienciaAnos(Xp), horasMax(HM) {}

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
