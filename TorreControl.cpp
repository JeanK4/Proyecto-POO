#include "aeropuerto.h"
#include "TorreControl.h"

torreControl* torreControl::getInstance(){
  if(instance == nullptr){
    instance = new torreControl();
  }
  return instance;
}

torreControl::torreControl(){

}

void torreControl::asignarPuerta(){
	vector<vuelo>& vuelos = aeropuerto::getVuelos();
	bool flag = false;
	int index = 0;
	for(int i = 0; i < vuelos.size(); i++){
		if(vuelos[i].getAeronaveAsignada()->getEstado() == 2){
			while(!flag && index < Puertas.size()){
				if(Puertas[index].getDisponible()){
					Puertas[index].setDisponible(false);
					Puertas[index].addHistorial(vuelos[i]);
					vuelo* xd = &vuelos[i];
					Puertas[index].setVuelo(xd);
					Puertas[index].setHora(vuelos[i].getHora());
					vuelos[i].getAeronaveAsignada()->setEstado(4);
					vuelos[i].setIdPuerta(Puertas[index].getIdentificacion());
					flag = true;
				}
				index++;
			}
			if(!flag)
				cout << "No hay puertas disponibles" << endl;
		}
	}
}

void torreControl::iniciarVuelo(vuelo fly){
	string tmp = fly.getIdPuerta();
	bool flag = false;
	int index;
	while(!flag && index < Puertas.size()){
		if(Puertas[index].getIdentificacion() == tmp){
			Puertas[index].setDisponible(true);
			fly.getAeronaveAsignada()->setEstado(5);
			Puertas[index].setVuelo(NULL);
			Puertas[index].setHora("");
		}
		index++;
	}
}

void torreControl::consultarPuertas(){
	for(int i = 0; i < Puertas.size(); i++){
		cout << "Puerta #" << Puertas[i].getIdentificacion() << ": ";
		if(Puertas[i].getDisponible())
			cout << "Disponible, ";
		else
			cout << "No Disponible, ";
		cout << "Ubicacion: " << Puertas[i].getUbicacion() << endl;
	}
}

void torreControl::addPuerta(puertaembarque puerta){
	Puertas.push_back(puerta);
}

void torreControl::solicitarAltitud(vuelo fly){
	cout << "Vuelo #" << fly.getNumIdent() << ", Se solicita altitud" << endl;
}

void torreControl::recibirAltitud(){
	cout << "Mensaje recibido" << endl;
}

void torreControl::finalizarVuelo(vuelo fly){
	vector<vuelo>& vuelos = aeropuerto::getVuelos();
	string id = fly.getNumIdent();
	int index = 0;
	bool flag = false;
	while(!flag){
		if(vuelos[index].getNumIdent() == id){
			vuelos.erase(vuelos.begin() + index);
			fly.getAeronaveAsignada()->setEstado(3);
			flag = true;
		}
	}
}