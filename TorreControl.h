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
		void iniciarVuelo(string numIdent);
		void addPuerta(puertaembarque puerta);
		void finalizarVuelo(string numIdent);
		void solicitarAltitud(string numIdent);
		void consultarPuertas();

};

#endif