#include "PuertaEmbarque.h"

#ifndef TORRECONTROL
#define TORRECONTROL

using namespace std;

class torreControl{
	private:
		static torreControl* instance;
		torreControl();
		vector<puertaembarque> Puertas;
	public:
		static torreControl* getInstance();
		void asignarPuerta();
		void iniciarVuelo(vuelo fly);
		void addPuerta(puertaembarque puerta);
		void finalizarVuelo(vuelo fly);
		void solicitarAltitud(vuelo fly);
		void recibirAltitud();
		void consultarPuertas();	
		
};

#endif