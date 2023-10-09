#include "aeronave.h"

aeronave::aeronave() {
    capacidadPasajeros = 0;
    estado = 1;
}

string aeronave::getMarca() {
    return marca;
}

int aeronave::getModelo() {
    return modelo;
}

int aeronave::getCapacidadPasajeros() {
    return capacidadPasajeros;
}

int aeronave::getVelocidadMaxima() {
    return velocidadMaxima;
}

int aeronave::getAutonomia() {
    return autonomia;
}

int aeronave::getAnoFabricacion() {
    return anoFabricacion;
}

int aeronave::getEstado() {
    return estado;
}

int aeronave::getCtVuelos(){
    return ctVuelos;
}

void aeronave::setMarca(string Marca) {
    marca = Marca;
}

void aeronave::setModelo(int model) {
    modelo = model;
}

void aeronave::setCapacidadPasajeros(int capPasajeros) {
    capacidadPasajeros = capPasajeros;
}

void aeronave::setVelocidadMaxima(int velM) {
    velocidadMaxima = velM;
}

void aeronave::setAutonomia(int autonom) {
    autonomia = autonom;
}

void aeronave::setAnoFabricacion(int yF) {
    anoFabricacion = yF;
}

void aeronave::setEstado(int S) {
    estado = S;
}

avion::avion(){

}

void aeronave::setCtVuelos(int ct){
    ctVuelos = ct;
}

avion::avion(string marca, int model, int capacidadP, int velocidadM, int autonomia, int anoF, int est, string altM, int cntM) {
    setMarca(marca);
    setModelo(model);
    setCapacidadPasajeros(capacidadP);
    setVelocidadMaxima(velocidadM);
    setAutonomia(autonomia);
    setAnoFabricacion(anoF);
    setEstado(est);
    altitudMax = altM;
    cantMotores = cntM;

}

string avion::getAltitudMax() {
    return altitudMax;
}

int avion::getCantMotores() {
    return cantMotores;
}


void avion::setAltitudMax(string AltM) {
    altitudMax = AltM;
}

void avion::setCantMotores(int ctM) {
    cantMotores = ctM;
}

helicoptero::helicoptero() {

}

helicoptero::helicoptero(string marca, int model, int capacidadP, int velocidadM, int autonomia, int anoF, int est, int cntR, string capE, int uso) {
    setMarca(marca);
    setModelo(model);
    setCapacidadPasajeros(capacidadP);
    setVelocidadMaxima(velocidadM);
    setAutonomia(autonomia);
    setAnoFabricacion(anoF);
    setEstado(est);
    cntRotores = cntR;
    capacidadElevacion = capE;
    uso = uso;
}

int helicoptero::getCntRotores() {
    return cntRotores;
}

string helicoptero::getCapacidadElevacion() {
    return capacidadElevacion;
}

int helicoptero::getUso() {
    return uso;
}

void helicoptero::setCntRotores(int rotores) {
    cntRotores = rotores;
}

void helicoptero::setCapacidadElevacion(string capElev) {
    capacidadElevacion = capElev;
}

void helicoptero::setUso(int Uso) {
    uso = Uso;
}

jets::jets() {

}

jets::jets(string marca, int model, int capacidadP, int velocidadM, int autonomia, int anoF, int est, string propietario, vector<string> services, vector<string> destinosFrec) {
    setMarca(marca);
    setModelo(model);
    setCapacidadPasajeros(capacidadP);
    setVelocidadMaxima(velocidadM);
    setAutonomia(autonomia);
    setAnoFabricacion(anoF);
    setEstado(est);
    propietario = propietario;
    servicios = services;
    destinosFrec = destinosFrec;
}

string jets::getPropietario() {
    return propietario;
}

vector<string> jets::getServicios() {
    return servicios;
}

vector<string> jets::getDestinosFrec() {
    return destinosFrec;
}

void jets::setPropietario(string p) {
    propietario = p;
}

void jets::setServicios(vector<string> s) {
    servicios = s;
}

void jets::setDestinosFrec(vector<string> d) {
    destinosFrec = d;
}
