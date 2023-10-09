#include "PuertaEmbarque.h"

puertaembarque::puertaembarque() {

}
puertaembarque::puertaembarque(string id, string ubi){
    disponible = true;
    identificacion = id;
    ubicacion = ubi;
    hora = hour;
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

void puertaembarque::addHistorial(vuelo fly) {
    historial.push_back(fly);
}

vuelo* puertaembarque::getVuelo(){
    return vueloAsignado;
}

void puertaembarque::setVuelo(vuelo* fly){
    vueloAsignado = fly;
}