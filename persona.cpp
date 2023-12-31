#include "persona.h"

persona::persona(){

}

persona::persona(string Ced, string Nom, string FechNaci, string gender, string address, string telef, string mail) : cedula(Ced), nombre(Nom), fechaNacimiento(FechNaci), genero(gender), direccion(address), telefono(telef), correo(mail) {}

string persona::getCedula() {
    return cedula;
}

string persona::getNombre() {
    return nombre;
}

string persona::getFechaNacimiento() {
    return fechaNacimiento;
}

string persona::getGenero() {
    return genero;
}

string persona::getDireccion() {
    return direccion;
}

string persona::getTelefono() {
    return telefono;
}

string persona::getCorreo() {
    return correo;
}

void persona::setCedula(string Ced) {
    cedula = Ced;
}

void persona::setNombre(string Nom) {
    nombre = Nom;
}

void persona::setFechaNacimiento(string FechNaci) {
    fechaNacimiento = FechNaci;
}

void persona::setGenero(string gender) {
    genero = gender;
}

void persona::setDireccion(string address) {
    direccion = address;
}

void persona::setTelefono(string telef) {
    telefono = telef;
}

void persona::setCorreo(string mail) {
    correo = mail;
}
