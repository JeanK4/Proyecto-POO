#include "aeropuerto.h"
#include <iostream>
#include <string>
#include "TorreControl.h"

using namespace std;

/* Variables y objetos globales */
aeropuerto elDorado;
torreControl* torreControl::instance = nullptr;


int main(){
	torreControl* Tower = torreControl::getInstance();
	puertaembarque Gate1("01","Ala norte");
	Tower->addPuerta(Gate1);
	puertaembarque Gate2("02","Ala este");
	Tower->addPuerta(Gate2);
	puertaembarque Gate3("03","Ala sur");
	Tower->addPuerta(Gate3);
	puertaembarque Gate4("04","Ala oeste");
	Tower->addPuerta(Gate4);
	int opcion;
	cout << "Bienvenido al sistema del aeropuerto, Elija su opcion" << endl;
	cout << "1. Reservar Vuelo\n2. Anadir Vuelo\n3. Consultar Vuelo\n4. Consultar Puertas de Embarque\n5. Salir" << endl;
	cout << "Digite su opcion: ";
	cin  >> opcion;
	while(opcion != 5){
		switch(opcion){
		case 1:
			elDorado.reservarVuelo();
			break;
		case 2:
			elDorado.anadirVuelo();
			break;
		case 3:
			elDorado.consultarVuelo();
			break;
		case 4:
			Tower->consultarPuertas();
			break;
		default:
			cout << "Opcion invalida" << endl;
			break;
		}
		cout << "1. Reservar Vuelo\n2. Anadir Vuelo\n3. Consultar Vuelo\n4. Consultar Puertas de Embarque\n5. Salir" << endl;
		cout << "Digite su opcion: ";
		cin  >> opcion;
	}
return 0;
}