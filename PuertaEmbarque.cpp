#include "PuertaEmbarque.h"

puertaembarque::puertaembarque() {
    // Constructor por defecto
}

bool puertaembarque::getDisponible() {
    return disponible;
}

string puertaembarque::getIdentificacion() {
    return identificacion;
}

string puertaembarque::getUbicacion() {
    return ubicacion;
}

string puertaembarque::getHora() {
    return hora;
}

vector<vuelo> puertaembarque::getHistorial() {
    return historial;
}

void puertaembarque::setDisponible(bool estado) {
    disponible = estado;
}

void puertaembarque::setIdentificacion(string ID) {
    identificacion = ID;
}

void puertaembarque::setUbicacion(string Ubicacion) {
    ubicacion = Ubicacion;
}

void puertaembarque::setHora(string Hora) {
    hora = Hora;
}

void puertaembarque::setHistorial(vector<vuelo> Historial) {
    historial = Historial;
}
