#include "TorreControl.h"


torreControl* getInstance(){
  if(torreControl::instance == NULL){
    torreControl::instance = new torreControl();
  }
  return torreControl::instance;
}

void torreControl::asignarPuerta(){
	bool flag = false;
	int index = 0;
	for(int i = 0; i < vuelos.size(); i++){
		if(vuelos[i].getAeronaveAsignada->getEstado() == 2){
			while(!flag && index < Puertas.size()){
				if(Puertas[index].getDisponible()){
					Puertas[index].setDisponible(false);
					Puertas[index].addHistorial(vuelos[i]);
					Puertas[index].setVuelo(vuelos[i]);
					Puertas[index].setHora(vuelos[i].getAeronaveAsignada->getHora());
					vuelos[i].getAeronaveAsignada->setEstado(4);
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
	string tmp = fly.getAeronaveAsignada->getIdPuerta();
	bool flag = false;
	int index;
	while(!flag && index < Puertas.size()){
		if(Puertas[index].getIdentificacion == tmp){
			Puertas[index].setDisponible(true);
			fly.getAeronaveAsignada->setEstado(5);
			Puertas[index].setVuelo(NULL);
			Puertas[index].setHora("");
		}
		index++;
	}
}

void torreControl::addPuerta(puertaembarque puerta){
	Puertas.push_back(puerta);
}