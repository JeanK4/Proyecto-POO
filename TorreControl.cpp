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

void torreControl::iniciarVuelo(string numIdent){
	vector<vuelo>& vuelos = aeropuerto::getVuelos();
	vuelo fly;
	for(int i = 0; i < vuelos.size(); i++){
		if(vuelos[i].getNumIdent() == numIdent)
			fly = vuelos[i];
	}
	if(fly.getAeronaveAsignada()->getEstado() == 4){
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
	else
		cout << "No es posible iniciar el vuelo sin asignar una puerta con anterioridad" << endl;
}

void torreControl::consultarPuertas(){
	for(int i = 0; i < Puertas.size(); i++){
		cout << "Puerta #" << Puertas[i].getIdentificacion() << ": ";
		if(Puertas[i].getDisponible()){
			cout << "Disponible, ";
			cout << "Ubicacion: " << Puertas[i].getUbicacion() << endl;
		}
		else{
			cout << "No Disponible, ";
			cout << "Ubicacion: " << Puertas[i].getUbicacion() << endl;
			cout << "Numero de vuelo asignado: " << Puertas[i].getVuelo()->getNumIdent() << endl;
		}
	}
}

void torreControl::addPuerta(puertaembarque puerta){
	Puertas.push_back(puerta);
}

void torreControl::solicitarAltitud(string numIdent){
	vector<vuelo>& vuelos = aeropuerto::getVuelos();
	int i = 0;
	bool flag = false;
	while(i < vuelos.size() && !flag){
		if(vuelos[i].getNumIdent() == numIdent)
			flag = true;
		i++;
	}
	if(vuelos[i].getAeronaveAsignada()->getEstado() == 5)
		cout << "Vuelo #" << numIdent << " con altitud: " << vuelos[i].getAltitud() << endl;
	else
		cout << "Vuelo #" << numIdent << " no se encuentra en el aire" << endl;
}

void torreControl::finalizarVuelo(string numIdent){
	vector<vuelo>& vuelos = aeropuerto::getVuelos();
	vuelo fly;
	for(int i = 0; i < vuelos.size(); i++){
		if(vuelos[i].getNumIdent() == numIdent)
			fly = vuelos[i];
	}
	int index = 0;
	bool flag = false;
	while(!flag && index < vuelos.size()){
		if(vuelos[index].getNumIdent() == numIdent){
			vuelos.erase(vuelos.begin() + index);
			fly.getAeronaveAsignada()->setEstado(3);
			flag = true;
		}
	}
}