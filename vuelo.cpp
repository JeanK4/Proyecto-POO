#include "vuelo.h"
#include <ctime>
#include <cstdlib>

string vuelo::getNumIdent() {
    return numIdent;
}

vuelo::vuelo(){
    srand(static_cast<unsigned>(time(0)));
    int random = rand() % 2001 + 10000;
    this->altitud = random;
}

int vuelo::getAltitud(){
    return this->altitud;
}

string vuelo::getFecha() {
    return fecha;
}

string vuelo::getCiudadOrigen() {
    return ciudadOrigen;
}

int vuelo::getTipoVuelo(){
    return tipoVuelo;
}

string vuelo::getCiudadDestino() {
    return ciudadDestino;
}

vector<pasajero> vuelo::getPersonasAbordo() {
    return personasAbordo;
}

aeronave* vuelo::getAeronaveAsignada() {
    return aeronaveAsignada;
}

vector<tripulante> vuelo::getTripulantesAbordo() {
    return tripulantesAbordo;
}

void vuelo::setNumIdent(string NumID) {
    numIdent = NumID;
}

void vuelo::setFecha(string Fecha) {
    fecha = Fecha;
}

void vuelo::setCiudadOrigen(string COrigen) {
    ciudadOrigen = COrigen;
}

void vuelo::setCiudadDestino(string CDestino) {
    ciudadDestino = CDestino;
}

void vuelo::addPersonasAbordo(pasajero p) {
    personasAbordo.push_back(p);
}

void vuelo::setAeronaveAsignada(aeronave *n) {
    aeronaveAsignada = n;
}

void vuelo::addTripulantesAbordo(tripulante t) {
    tripulantesAbordo.push_back(t);
}

void vuelo::setTipoVuelo(int x){
    tipoVuelo = x;
}

string vuelo::getIdPuerta(){
    return idPuerta;
}

void vuelo::setIdPuerta(string identificacion){
    idPuerta = identificacion;
}

string vuelo::getHora(){
    return hora;
}

void vuelo::setHora(string hour){
    hora = hour;
}